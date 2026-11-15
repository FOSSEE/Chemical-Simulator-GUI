import os
import sys
import unittest
from unittest.mock import MagicMock, patch

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QPushButton, QMessageBox, QGraphicsView, QWidget
from PyQt5.QtCore import Qt, QRectF

app = QApplication.instance() or QApplication([])

import Landing_page
from Landing_page import LandingPage


class TestLandingPage(unittest.TestCase):
    """Unit tests for LandingPage actions, project launching, and modal triggers."""

    def setUp(self):
        self.landing = LandingPage()

    def tearDown(self):
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

    def test_landing_page_initialization(self):
        """Verify window title, dimensions, and core action buttons."""
        self.assertEqual(self.landing.windowTitle(), "Chemical Simulator GUI")
        self.assertGreaterEqual(self.landing.width(), 800)

        buttons = self.landing.findChildren(QPushButton)
        btn_texts = [b.text_label.text() for b in buttons if hasattr(b, 'text_label')]
        # Verify Start New Simulation, Open Existing Project, About, and Exit exist
        self.assertIn("Start New Simulation", btn_texts)
        self.assertIn("Open Existing Project", btn_texts)
        self.assertIn("About", btn_texts)
        self.assertIn("Exit", btn_texts)

    @patch('Landing_page.MainApp')
    def test_launch_main_window(self, mock_main_app_cls):
        """Verify launching a new simulation initializes MainApp and hides LandingPage."""
        mock_instance = MagicMock()
        mock_main_app_cls.return_value = mock_instance

        self.landing.launch_main_window()

        mock_main_app_cls.assert_called_once()
        mock_instance.new_project.assert_called_once()
        mock_instance.showMaximized.assert_called_once()
        self.assertFalse(self.landing.isVisible())

    @patch('Landing_page.QFileDialog.getOpenFileName')
    @patch('Landing_page.MainApp')
    def test_open_existing_project(self, mock_main_app_cls, mock_open_file):
        """Verify opening an existing project loads the selected file."""
        mock_open_file.return_value = ("/fake/path/to/project.sim", "Project Files (*.sim)")
        mock_instance = MagicMock()
        mock_main_app_cls.return_value = mock_instance

        self.landing.open_existing_project()

        mock_instance.open.assert_called_once_with("/fake/path/to/project.sim")
        mock_instance.showMaximized.assert_called_once()
        self.assertFalse(self.landing.isVisible())

    @patch('Landing_page.QFileDialog.getOpenFileName')
    def test_open_existing_project_cancelled(self, mock_open_file):
        """Verify cancelling the file dialog does nothing."""
        mock_open_file.return_value = ("", "")
        orig_main_window = self.landing.main_window

        self.landing.open_existing_project()
        self.assertEqual(self.landing.main_window, orig_main_window)

    def test_restore_landing_page(self):
        """Verify restore_landing_page displays landing page and resets cursors."""
        self.landing.hide()
        self.assertFalse(self.landing.isVisible())

        self.landing.restore_landing_page()
        self.assertTrue(self.landing.isVisible())


class TestLandingPageFlows(unittest.TestCase):
    """Window lifecycle, error paths and secondary actions of LandingPage."""

    def setUp(self):
        self.landing = LandingPage()
        Landing_page._stashed_windows.clear()

    def tearDown(self):
        Landing_page._stashed_windows.clear()
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

    def capture_timers(self):
        """Patch QTimer so singleShot callbacks are collected instead of scheduled."""
        timer_patch = patch("Landing_page.QTimer")
        mock_timer = timer_patch.start()
        self.addCleanup(timer_patch.stop)
        return mock_timer

    def run_timer_callbacks(self, mock_timer):
        for call in mock_timer.singleShot.call_args_list:
            call.args[1]()

    # ----------------- preload / start -----------------

    @patch("Landing_page.MainApp")
    def test_preload_hides_main_window_and_compound_selector(self, mock_main_app_cls):
        self.landing.preload_main_window()

        window = mock_main_app_cls.return_value
        self.assertIs(self.landing.main_window, window)
        window.hide.assert_called_once()
        window.comp.hide.assert_called_once()
        self.assertIsNone(QApplication.overrideCursor())

    @patch("Landing_page.MainApp", side_effect=RuntimeError("no display"))
    def test_preload_failure_is_handled_and_cursor_restored(self, mock_main_app_cls):
        self.landing.preload_main_window()
        self.assertIsNone(self.landing.main_window)
        self.assertIsNone(QApplication.overrideCursor())

    def test_start_simulation_launches_after_short_delay(self):
        mock_timer = self.capture_timers()
        with patch.object(self.landing, "launch_main_window") as mock_launch:
            self.landing.start_simulation()
            self.assertEqual(QApplication.overrideCursor().shape(), Qt.WaitCursor)
            mock_launch.assert_not_called()

            self.assertEqual(mock_timer.singleShot.call_args.args[0], 100)
            self.run_timer_callbacks(mock_timer)

        mock_launch.assert_called_once_with()
        self.assertIsNone(QApplication.overrideCursor())

    @patch("Landing_page.MainApp")
    def test_launch_shows_compound_selector_and_restores_on_close(self, mock_main_app_cls):
        mock_timer = self.capture_timers()
        self.landing.launch_main_window()
        window = mock_main_app_cls.return_value

        # Second singleShot: show the compound selector
        mock_timer.singleShot.call_args_list[0].args[1]()
        window.comp.show.assert_called_once()

        # Closing the main window schedules restore_landing_page
        on_closed = window.closed.connect.call_args.args[0]
        with patch.object(self.landing, "restore_landing_page") as mock_restore:
            on_closed()
            mock_timer.singleShot.call_args.args[1]()
        mock_restore.assert_called_once_with()

    # ----------------- _cleanup_main_window -----------------

    def test_cleanup_without_main_window_does_nothing(self):
        self.landing.main_window = None
        self.landing._cleanup_main_window()
        self.assertEqual(Landing_page._stashed_windows, [])

    def test_cleanup_stashes_old_window_and_clears_graphics_lists(self):
        old = MagicMock()
        self.landing.main_window = old
        Landing_page._node_lst.append("node")
        Landing_page._dock_widget_lst.append("dock")

        self.landing._cleanup_main_window()

        old.hide.assert_called_once()
        self.assertIsNone(self.landing.main_window)
        self.assertEqual(Landing_page._stashed_windows, [old])
        self.assertEqual(Landing_page._node_lst, [])
        self.assertEqual(Landing_page._dock_widget_lst, [])

    def test_cleanup_survives_errors_from_old_window(self):
        old = MagicMock()
        old.hide.side_effect = RuntimeError("wrapped C/C++ object has been deleted")
        self.landing.main_window = old
        with patch("Landing_page._node_lst", MagicMock(clear=MagicMock(side_effect=RuntimeError))):
            self.landing._cleanup_main_window()

        self.assertEqual(Landing_page._stashed_windows, [old])
        self.assertIsNone(self.landing.main_window)

    def test_cleanup_handles_missing_graphics_lists(self):
        self.landing.main_window = MagicMock()
        with patch("Landing_page._dock_widget_lst", None), patch("Landing_page._node_lst", None):
            self.landing._cleanup_main_window()
        self.assertEqual(len(Landing_page._stashed_windows), 1)

    # ----------------- open_existing_project -----------------

    @patch("Landing_page.QFileDialog.getOpenFileName", return_value=("/p/project.sim", ""))
    @patch("Landing_page.MainApp")
    def test_open_fits_canvas_after_loading(self, mock_main_app_cls, mock_dialog):
        mock_timer = self.capture_timers()
        window = mock_main_app_cls.return_value
        rect = QRectF(0, 0, 400, 300)
        window.container.graphics.scene.itemsBoundingRect.return_value = rect

        self.landing.open_existing_project()
        window.comp.hide.assert_called_once()

        fit_delay, delayed_fit = mock_timer.singleShot.call_args.args
        self.assertEqual(fit_delay, 600)
        delayed_fit()

        gv = window.graphicsView
        gv.setDragMode.assert_called_once_with(QGraphicsView.ScrollHandDrag)
        gv.fitInView.assert_called_once_with(rect, Qt.KeepAspectRatio)
        gv.centerOn.assert_called_once_with(rect.center())

    @patch("Landing_page.QFileDialog.getOpenFileName", return_value=("/p/empty.sim", ""))
    @patch("Landing_page.MainApp")
    def test_open_empty_project_skips_fit(self, mock_main_app_cls, mock_dialog):
        mock_timer = self.capture_timers()
        window = mock_main_app_cls.return_value
        window.container.graphics.scene.itemsBoundingRect.return_value = QRectF()

        self.landing.open_existing_project()
        mock_timer.singleShot.call_args.args[1]()

        window.graphicsView.fitInView.assert_not_called()

    @patch("Landing_page.QFileDialog.getOpenFileName", return_value=("/p/project.sim", ""))
    @patch("Landing_page.MainApp")
    def test_open_fit_errors_are_ignored(self, mock_main_app_cls, mock_dialog):
        mock_timer = self.capture_timers()
        window = mock_main_app_cls.return_value
        window.container.graphics.scene.itemsBoundingRect.side_effect = RuntimeError("deleted")

        self.landing.open_existing_project()
        mock_timer.singleShot.call_args.args[1]()  # must not raise

    @patch("Landing_page.QMessageBox.critical")
    @patch("Landing_page.QFileDialog.getOpenFileName", return_value=("/p/broken.sim", ""))
    @patch("Landing_page.MainApp")
    def test_open_failure_shows_error_and_keeps_landing_page(self, mock_main_app_cls, mock_dialog, mock_critical):
        mock_main_app_cls.return_value.open.side_effect = ValueError("corrupt file")
        self.landing.show()

        self.landing.open_existing_project()

        self.assertEqual(mock_critical.call_args.args[1], "Error")
        self.assertIn("corrupt file", mock_critical.call_args.args[2])
        self.assertTrue(self.landing.isVisible())
        self.assertIsNone(QApplication.overrideCursor())

    @patch("Landing_page.QFileDialog.getOpenFileName", return_value=("/p/project.sim", ""))
    @patch("Landing_page.MainApp")
    def test_open_stashes_preloaded_window(self, mock_main_app_cls, mock_dialog):
        self.capture_timers()
        preloaded = MagicMock()
        self.landing.main_window = preloaded

        self.landing.open_existing_project()

        self.assertIn(preloaded, Landing_page._stashed_windows)
        self.assertIs(self.landing.main_window, mock_main_app_cls.return_value)

    # ----------------- IntroPage / compound selector handlers -----------------

    def test_show_compound_selector_without_main_window(self):
        self.landing.main_window = None
        self.landing.show_compound_selector()  # must not raise

    def test_launch_compound_selector_closes_intro_and_shows_selector(self):
        self.landing.intro_page = MagicMock()
        self.landing.main_window = MagicMock()

        self.landing.launch_compound_selector()

        self.landing.intro_page.close.assert_called_once()
        self.landing.main_window.comp.show.assert_called_once()
        self.landing.main_window.comp.activateWindow.assert_called_once()

    def test_launch_compound_selector_without_intro_or_window(self):
        self.landing.main_window = None
        self.landing.launch_compound_selector()  # must not raise

    def test_cancel_intro_closes_main_window(self):
        self.landing.intro_page = MagicMock()
        self.landing.main_window = MagicMock()

        self.landing.cancel_intro()

        self.landing.intro_page.close.assert_called_once()
        self.landing.main_window.close.assert_called_once()

    def test_cancel_intro_without_main_window_restores_landing(self):
        self.landing.main_window = None
        with patch.object(self.landing, "restore_landing_page") as mock_restore:
            self.landing.cancel_intro()
        mock_restore.assert_called_once_with()

    def test_handle_main_close_accepts_event(self):
        event = MagicMock()
        self.landing.handle_main_close(event)
        event.accept.assert_called_once()

    # ----------------- fit_canvas / restore / close -----------------

    def test_fit_canvas_without_main_window(self):
        self.landing.main_window = None
        self.landing.fit_canvas()  # must not raise

    def test_fit_canvas_fits_scene(self):
        window = MagicMock()
        rect = QRectF(10, 10, 200, 100)
        window.scene.itemsBoundingRect.return_value = rect
        self.landing.main_window = window
        QApplication.setOverrideCursor(Qt.WaitCursor)

        self.landing.fit_canvas()

        window.graphicsView.fitInView.assert_called_once_with(rect, Qt.KeepAspectRatio)
        window.graphicsView.centerOn.assert_called_once_with(rect.center())
        self.assertIsNone(QApplication.overrideCursor())

    def test_restore_drains_all_override_cursors(self):
        for _ in range(3):
            QApplication.setOverrideCursor(Qt.WaitCursor)
        old = MagicMock()
        self.landing.main_window = old

        self.landing.restore_landing_page()

        self.assertIsNone(QApplication.overrideCursor())
        self.assertIn(old, Landing_page._stashed_windows)
        self.assertTrue(self.landing.isVisible())

    @patch("Landing_page.QApplication.quit")
    def test_close_event_quits_application(self, mock_quit):
        event = MagicMock()
        self.landing.closeEvent(event)
        mock_quit.assert_called_once()
        event.accept.assert_called_once()

    def test_reset_cursor_clears_stacked_cursors(self):
        QApplication.setOverrideCursor(Qt.WaitCursor)
        QApplication.setOverrideCursor(Qt.WaitCursor)
        self.landing.reset_cursor()
        self.assertIsNone(QApplication.overrideCursor())

    def test_resize_keeps_working(self):
        self.landing.resize(900, 600)
        self.assertEqual(self.landing.size().width(), 900)

    # ----------------- About / run -----------------

    def test_show_about_opens_window_with_fade_in(self):
        self.landing.show_about()
        try:
            about = self.landing.about_window
            self.assertEqual(about.windowTitle(), "About Chemical Simulator GUI")
            self.assertEqual(about.layout().count(), 1)
            self.assertIsInstance(about.layout().itemAt(0).widget(), Landing_page.AboutPage)
            self.assertEqual(self.landing._about_anim.endValue(), 1)
        finally:
            self.landing.about_window.close()

    def test_about_close_button_closes_window(self):
        with patch("Landing_page.AboutPage") as mock_about:
            mock_about.return_value = QWidget()
            self.landing.show_about()
        on_close = mock_about.call_args.kwargs["on_close"]
        self.assertTrue(self.landing.about_window.isVisible())
        on_close()
        self.assertFalse(self.landing.about_window.isVisible())

    def test_run_shows_landing_page_and_exits_with_app_code(self):
        with patch("Landing_page.QApplication") as mock_app_cls, \
                patch("Landing_page.LandingPage") as mock_landing_cls, \
                patch("Landing_page.sys.exit") as mock_exit:
            mock_app_cls.return_value.exec_.return_value = 0
            Landing_page.run()

        mock_app_cls.return_value.setQuitOnLastWindowClosed.assert_called_once_with(False)
        mock_landing_cls.return_value.show.assert_called_once()
        mock_exit.assert_called_once_with(0)


if __name__ == "__main__":
    unittest.main()
