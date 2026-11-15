import os
import pickle
import shutil
import sys
import tempfile
import unittest
from unittest.mock import MagicMock, patch

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QDialog
from PyQt5.QtCore import QEvent, QPoint, QPointF, Qt

app = QApplication.instance() or QApplication([])

import mainApp
from mainApp import MainApp, DragButtonFilter, DropFilter
from python.utils.ComponentSelector import compound_selected
from python.utils.Graphics import lst, dock_widget_lst, NodeItem
from python.utils.UnitOperations import Mixer, Heater
from python.utils.Streams import MaterialStream
from python.utils import undo_manager


class TestMainApp(unittest.TestCase):
    """Unit tests for MainApp window, menu triggers, and canvas orchestration."""

    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        lst.clear()
        dock_widget_lst.clear()
        undo_manager.clean_file("Undo")
        undo_manager.clean_file("Redo")

        self.main_app = MainApp()

    def tearDown(self):
        lst.clear()
        dock_widget_lst.clear()
        undo_manager.clean_file("Undo")
        undo_manager.clean_file("Redo")
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

    def test_main_app_initialization(self):
        """Verify window title, central container, scene, and action states."""
        self.assertIn("Chemical Simulator GUI", self.main_app.windowTitle())
        self.assertIsNotNone(self.main_app.container)
        self.assertIsNotNone(self.main_app.scene)
        self.assertEqual(self.main_app.zoom_count, 0)

    def test_zoom_in_out_reset(self):
        """Verify zoom actions increment, decrement, and reset zoom factor."""
        initial_zoom = self.main_app.zoom_count
        self.main_app.zoom_in()
        self.assertEqual(self.main_app.zoom_count, initial_zoom + 1)

        self.main_app.zoom_out()
        self.assertEqual(self.main_app.zoom_count, initial_zoom)

        self.main_app.zoom_in()
        self.main_app.zoom_in()
        self.main_app.zoom_reset()
        self.assertEqual(self.main_app.zoom_count, 0)

    def test_toggle_dock_views(self):
        """Verify dock toggle methods update widget visibility based on action check states."""
        self.main_app.show()

        # Test component selector dock view toggle
        self.main_app.actionViewComponentSelector.setChecked(False)
        self.main_app.toggle_component_selector_view()
        self.assertFalse(self.main_app.dockWidget.isVisible())

        self.main_app.actionViewComponentSelector.setChecked(True)
        self.main_app.toggle_component_selector_view()
        self.assertTrue(self.main_app.dockWidget.isVisible())

        # Test message browser dock view toggle
        self.main_app.actionViewMessageBrowser.setChecked(False)
        self.main_app.toggle_message_browser_view()
        self.assertFalse(self.main_app.dockWidget_2.isVisible())

        self.main_app.actionViewMessageBrowser.setChecked(True)
        self.main_app.toggle_message_browser_view()
        self.assertTrue(self.main_app.dockWidget_2.isVisible())

    def test_refresh_and_clear_selected_compounds(self):
        """Verify selected compounds list panel synchronization."""
        self.main_app.comp.selected_names_list = ["Water", "Ethanol"]
        self.main_app._refresh_selected_compounds()
        self.assertEqual(self.main_app.selectedElementsList.count(), 2)

        self.main_app._clear_selected_compounds_panel()
        self.assertEqual(self.main_app.selectedElementsList.count(), 0)

    def test_simulation_methods(self):
        """Verify simulate method initiates container simulation."""
        self.main_app.container.simulate = MagicMock()
        self.main_app.simulate("EQN")
        self.main_app.container.simulate.assert_called_with("EQN")

        self.main_app.simulate("SM")
        self.main_app.container.simulate.assert_called_with("SM")

    def test_component_palette_instantiation(self):
        """Verify adding a unit operation to container from palette."""
        initial_count = len(self.main_app.container.unit_operations)
        self.main_app.component("Mixer")
        self.assertEqual(len(self.main_app.container.unit_operations), initial_count + 1)
        self.assertEqual(self.main_app.container.unit_operations[-1].type, "Mixer")

    @patch('mainApp.QMessageBox.exec_')
    def test_help_dialog(self, mock_msg_exec):
        """Verify help dialog execution."""
        self.main_app.help()
        mock_msg_exec.assert_called_once()


def fake_event(event_type, **attrs):
    """A stand-in for a Qt event: only the methods the filters call."""
    event = MagicMock()
    event.type.return_value = event_type
    for name, value in attrs.items():
        getattr(event, name).return_value = value
    return event


class TestDragAndDropFilters(unittest.TestCase):
    """DragButtonFilter (component palette) and DropFilter (canvas)."""

    def setUp(self):
        self.drag_filter = DragButtonFilter(None, "Mixer")
        self.button = MagicMock()

    def test_press_records_start_position(self):
        self.drag_filter.eventFilter(self.button, fake_event(
            QEvent.MouseButtonPress, button=Qt.LeftButton, pos=QPoint(5, 5)))
        self.assertEqual(self.drag_filter.startPos, QPoint(5, 5))

    def test_right_click_is_ignored(self):
        self.drag_filter.eventFilter(self.button, fake_event(
            QEvent.MouseButtonPress, button=Qt.RightButton, pos=QPoint(5, 5)))
        self.assertIsNone(self.drag_filter.startPos)

    def test_small_move_does_not_start_drag(self):
        self.drag_filter.startPos = QPoint(5, 5)
        with patch("mainApp.QDrag") as mock_drag:
            handled = self.drag_filter.eventFilter(self.button, fake_event(
                QEvent.MouseMove, buttons=Qt.LeftButton, pos=QPoint(6, 5)))
        self.assertFalse(handled)
        mock_drag.assert_not_called()

    def test_long_move_starts_drag_with_component_type(self):
        self.drag_filter.startPos = QPoint(5, 5)
        with patch("mainApp.QDrag") as mock_drag:
            handled = self.drag_filter.eventFilter(self.button, fake_event(
                QEvent.MouseMove, buttons=Qt.LeftButton, pos=QPoint(105, 5)))

        self.assertTrue(handled)
        drag = mock_drag.return_value
        mime = drag.setMimeData.call_args.args[0]
        self.assertEqual(mime.text(), "Mixer")
        drag.exec_.assert_called_once_with(Qt.CopyAction)
        self.assertIsNone(self.drag_filter.startPos)

    def test_move_without_press_does_not_drag(self):
        with patch("mainApp.QDrag") as mock_drag:
            self.drag_filter.eventFilter(self.button, fake_event(
                QEvent.MouseMove, buttons=Qt.LeftButton, pos=QPoint(100, 0)))
        mock_drag.assert_not_called()

    def test_drop_filter_accepts_text_drags(self):
        drop_filter = DropFilter(None, MagicMock())
        for event_type in (QEvent.DragEnter, QEvent.DragMove):
            event = fake_event(event_type)
            event.mimeData.return_value.hasText.return_value = True
            self.assertTrue(drop_filter.eventFilter(None, event))
            event.acceptProposedAction.assert_called_once()

    def test_drop_filter_ignores_non_text_drags(self):
        drop_filter = DropFilter(None, MagicMock())
        event = fake_event(QEvent.DragEnter)
        event.mimeData.return_value.hasText.return_value = False
        self.assertFalse(drop_filter.eventFilter(None, event))
        event.acceptProposedAction.assert_not_called()

    def test_drop_creates_component_at_scene_position(self):
        main_app = MagicMock()
        main_app.graphicsView.mapToScene.return_value = QPointF(120, 80)
        drop_filter = DropFilter(None, main_app)
        event = fake_event(QEvent.Drop, pos=QPoint(10, 20))
        event.mimeData.return_value.text.return_value = "Heater"

        self.assertTrue(drop_filter.eventFilter(None, event))
        main_app.graphicsView.mapToScene.assert_called_once_with(QPoint(10, 20))
        main_app.component.assert_called_once_with("Heater", pos=QPointF(120, 80))

    def test_other_events_pass_through(self):
        drop_filter = DropFilter(None, MagicMock())
        self.assertFalse(drop_filter.eventFilter(None, fake_event(QEvent.KeyPress)))
        self.assertFalse(self.drag_filter.eventFilter(None, fake_event(QEvent.KeyPress)))


class MainAppTestBase(unittest.TestCase):
    """A real MainApp with undo/redo files redirected to a temporary folder."""

    def setUp(self):
        self.tmp_dir = tempfile.mkdtemp()
        undo_patch = patch.object(undo_manager, "UNDO_PATH", os.path.join(self.tmp_dir, "undo_redo"))
        undo_patch.start()
        self.addCleanup(undo_patch.stop)

        # A modal message box would block (or crash) a headless run; tests that
        # expect one patch it themselves, which takes precedence over this.
        about_patch = patch("mainApp.QMessageBox.about")
        about_patch.start()
        self.addCleanup(about_patch.stop)

        lst.clear()
        dock_widget_lst.clear()
        for cls in (Mixer, Heater, MaterialStream):
            cls.counter = 1

        self.main_app = MainApp()
        self.select_compounds()

    def select_compounds(self):
        """Select two compounds (new() clears the selection)."""
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        self.main_app.comp.selected_names_list = ["Water(chemsep)", "Ethanol(chemsep)"]

    def tearDown(self):
        lst.clear()
        dock_widget_lst.clear()
        compound_selected.clear()
        # Destroy the window: each MainApp left alive slows down every later
        # test (app-wide stylesheet and event processing touch all widgets)
        self.main_app.comp.deleteLater()
        self.main_app.deleteLater()
        QApplication.sendPostedEvents(None, QEvent.DeferredDelete)
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()
        shutil.rmtree(self.tmp_dir, ignore_errors=True)

    def messages(self):
        return self.main_app.textBrowser.toPlainText()

    def unit_names(self):
        return sorted(op.name for op in self.main_app.container.unit_operations)


# =============================================================================
# Component panel, dialogs and small actions
# =============================================================================

class TestMainAppActions(MainAppTestBase):

    def test_component_panel_collapses_and_expands(self):
        btn, text = self.main_app._comp_btn_data[0]

        self.main_app._toggle_component_panel()
        self.assertTrue(self.main_app._panel_collapsed)
        self.assertEqual(btn.text(), "")
        self.assertEqual(self.main_app.dockWidget.width(), 48)
        self.assertTrue(all(h.isHidden() for h in self.main_app._comp_headers))

        self.main_app._toggle_component_panel()
        self.assertFalse(self.main_app._panel_collapsed)
        self.assertEqual(btn.text(), f"     {text}")
        self.assertEqual(self.main_app.dockWidget.minimumWidth(), 240)
        self.assertFalse(any(h.isHidden() for h in self.main_app._comp_headers))

    @patch("mainApp.QMessageBox.about")
    def test_bin_phase_env_needs_two_compounds(self, mock_about):
        with patch.object(self.main_app.comp, "get_compounds", return_value=["Water"]), \
                patch.object(self.main_app.comp, "show") as mock_show:
            self.main_app.bin_phase_env()
        self.assertIn("at least 2 Compounds", mock_about.call_args.args[2])
        mock_show.assert_called_once()

    def test_bin_phase_env_opens_window(self):
        with patch.object(self.main_app.comp, "get_compounds", return_value=["Water", "Ethanol"]), \
                patch("mainApp.BinPhaseEnv") as mock_window:
            self.main_app.bin_phase_env()
        mock_window.assert_called_once_with(self.main_app.comp)
        mock_window.return_value.show.assert_called_once()

    def test_select_compounds_shows_selector(self):
        with patch.object(self.main_app.comp, "show") as mock_show:
            self.main_app.select_compounds()
        mock_show.assert_called_once()

    def test_update_compounds_delegates_to_container(self):
        with patch.object(self.main_app.container, "update_compounds") as mock_update:
            self.main_app.update_compounds()
        mock_update.assert_called_once()

    def test_current_time_format(self):
        self.assertRegex(self.main_app.current_time(), r"^\d{1,2}:\d{1,2}:\d{1,2}$")

    def test_zoom_reset_after_zooming_out(self):
        self.main_app.zoom_out()
        self.main_app.zoom_out()
        self.main_app.zoom_reset()
        self.assertEqual(self.main_app.zoom_count, 0)
        self.assertAlmostEqual(self.main_app.graphicsView.transform().m11(), 1.0)

    def test_toggle_selected_elements_view(self):
        self.main_app.show()
        self.main_app.actionViewSelectedElements.setChecked(False)
        self.main_app.toggle_selected_elements_view()
        self.assertFalse(self.main_app.selectedElementsDock.isVisible())

        self.main_app.actionViewSelectedElements.setChecked(True)
        self.main_app.toggle_selected_elements_view()
        self.assertTrue(self.main_app.selectedElementsDock.isVisible())

    def test_refresh_with_no_compounds(self):
        self.main_app.comp.selected_names_list = []
        self.main_app._refresh_selected_compounds()
        self.assertEqual(self.main_app.selectedElementsList.count(), 0)
        self.assertEqual(self.main_app._sel_status_label.text(), "No compounds selected")

    def test_refresh_shows_count(self):
        self.main_app._refresh_selected_compounds()
        self.assertEqual(self.main_app._sel_status_label.text(), "2 compound(s) selected")

    def test_delete_key_deletes_selection(self):
        with patch.object(self.main_app.container, "delete") as mock_delete:
            for key in (Qt.Key_Delete, Qt.Key_Backspace):
                self.main_app.delete_call(fake_event(None, key=key))
        self.assertEqual(mock_delete.call_count, 2)

    def test_other_keys_do_not_delete(self):
        with patch.object(self.main_app.container, "delete") as mock_delete:
            self.main_app.delete_call(fake_event(None, key=Qt.Key_A))
        mock_delete.assert_not_called()

    def test_delete_errors_are_swallowed(self):
        with patch.object(self.main_app.container, "delete", side_effect=RuntimeError("boom")):
            self.main_app.delete_call(fake_event(None, key=Qt.Key_Delete))

    def test_update_undo_redo_actions_handles_errors(self):
        with patch.object(undo_manager, "stack_size", side_effect=RuntimeError("disk")):
            self.main_app._update_undo_redo_actions()  # must not raise

    def test_module_level_select_compounds_opens_dialog(self):
        with patch("mainApp.ComponentSelectorWindow") as mock_dialog:
            mock_dialog.return_value.exec_.return_value = QDialog.Accepted
            mainApp.select_compounds(self.main_app)
        mock_dialog.assert_called_once_with(self.main_app)


# =============================================================================
# simulate / terminate / close
# =============================================================================

class TestMainAppSimulation(MainAppTestBase):

    def setUp(self):
        super().setUp()
        thread_patch = patch("mainApp.threading.Thread")
        self.mock_thread_cls = thread_patch.start()
        self.addCleanup(thread_patch.stop)
        self.main_app.container.disableInterfaceforSimulation = MagicMock()

    def test_simulate_starts_thread_with_mode(self):
        self.main_app.simulate("SM")
        self.mock_thread_cls.assert_called_once_with(
            target=self.main_app.container.simulate, args=("SM",))
        self.mock_thread_cls.return_value.start.assert_called_once()
        self.main_app.container.disableInterfaceforSimulation.assert_called_once_with(True)

    def test_simulate_uses_saved_mo_file(self):
        sim_path = os.path.join(self.tmp_dir, "plant.sim")
        open(sim_path.replace(".sim", ".mo"), "w").close()
        self.main_app.last_saved_project = sim_path

        self.main_app.simulate("EQN")
        self.assertIn("Using project .mo file", self.messages())

    def test_simulate_warns_when_saved_mo_missing(self):
        self.main_app.last_saved_project = os.path.join(self.tmp_dir, "missing.sim")
        self.main_app.simulate("EQN")
        self.assertIn(".mo file not found, using default Flowsheet.mo", self.messages())
        self.mock_thread_cls.return_value.start.assert_called_once()

    def test_simulate_continues_if_compound_list_fails(self):
        self.main_app.container.flowsheet = MagicMock()
        self.main_app.container.flowsheet.add_compound_list.side_effect = ValueError("bad compound")
        self.main_app.simulate("EQN")
        self.mock_thread_cls.return_value.start.assert_called_once()

    def test_simulate_start_failure_unlocks_interface(self):
        self.mock_thread_cls.side_effect = RuntimeError("can't start new thread")
        self.main_app.simulate("SM")

        self.assertIn("Simulation failed: can't start new thread", self.messages())
        self.main_app.container.disableInterfaceforSimulation.assert_called_with(False)

    def running_thread(self):
        thread = MagicMock()
        thread.is_alive.return_value = True
        thread.ident = 1234
        self.main_app.thrd = thread
        self.main_app.container.flowsheet = MagicMock()
        self.main_app.container.flowsheet.root_dir = os.getcwd()
        return thread

    def test_terminate_stops_omc_and_thread(self):
        self.running_thread()
        process = self.main_app.container.flowsheet.process
        with patch("mainApp.ctypes") as mock_ctypes:
            mock_ctypes.pythonapi.PyThreadState_SetAsyncExc.return_value = 1
            self.main_app.terminate()

        process.terminate.assert_called_once()
        self.assertEqual(mock_ctypes.pythonapi.PyThreadState_SetAsyncExc.call_count, 1)
        self.assertIn("Simulation Terminated.", self.messages())
        self.main_app.container.disableInterfaceforSimulation.assert_called_with(False)
        self.assertIsNone(self.main_app.thrd)

    def test_terminate_reverts_when_several_threads_affected(self):
        self.running_thread()
        self.main_app.container.flowsheet.process.terminate.side_effect = OSError("already gone")
        with patch("mainApp.ctypes") as mock_ctypes:
            mock_ctypes.pythonapi.PyThreadState_SetAsyncExc.return_value = 2
            self.main_app.terminate()
        # Second call undoes the async exception
        self.assertEqual(mock_ctypes.pythonapi.PyThreadState_SetAsyncExc.call_count, 2)

    def test_terminate_without_running_thread(self):
        self.main_app.thrd = None
        self.main_app.container.flowsheet = None  # chdir fails and is ignored
        self.main_app.terminate()
        self.assertNotIn("Terminated", self.messages())

    def test_close_terminates_running_simulation(self):
        self.running_thread()
        closed = MagicMock()
        self.main_app.closed.connect(closed)
        QApplication.setOverrideCursor(Qt.WaitCursor)
        event = MagicMock()

        with patch.object(self.main_app, "terminate") as mock_terminate:
            self.main_app.closeEvent(event)

        mock_terminate.assert_called_once()
        event.accept.assert_called_once()
        closed.assert_called_once()
        self.assertIsNone(QApplication.overrideCursor())

    def test_close_ignores_terminate_errors(self):
        self.running_thread()
        event = MagicMock()
        with patch.object(self.main_app, "terminate", side_effect=RuntimeError("boom")):
            self.main_app.closeEvent(event)
        event.accept.assert_called_once()


# =============================================================================
# component(): placing unit operations on the canvas
# =============================================================================

class TestMainAppComponent(MainAppTestBase):

    def setUp(self):
        super().setUp()
        snapshot_patch = patch.object(self.main_app.container.graphics, "push_snapshot")
        self.mock_snapshot = snapshot_patch.start()
        self.addCleanup(snapshot_patch.stop)

    @patch("mainApp.QMessageBox.about")
    def test_component_requires_compounds(self, mock_about):
        with patch.object(self.main_app.comp, "is_compound_selected", return_value=False), \
                patch.object(self.main_app.comp, "show") as mock_show:
            self.main_app.component("Mixer")

        self.assertEqual(mock_about.call_args.args[2], "Please Select Compounds first")
        mock_show.assert_called_once()
        self.assertEqual(self.main_app.container.unit_operations, [])

    def test_material_stream_uses_selected_compounds(self):
        with patch.object(self.main_app.comp, "get_compounds", return_value=["Water", "Ethanol"]):
            self.main_app.component("MaterialStream")
        stream = self.main_app.container.unit_operations[-1]
        self.assertEqual(stream.type, "MaterialStream")
        self.assertEqual(stream.compound_names, ["Water", "Ethanol"])

    def test_unknown_component_type_is_ignored(self):
        self.main_app.component("NotAUnitOperation")
        self.assertEqual(self.main_app.container.unit_operations, [])
        self.mock_snapshot.assert_not_called()

    def test_dropped_component_goes_to_drop_position(self):
        self.main_app.component("Heater", pos=QPointF(300, 200))
        node = next(i for i in self.main_app.scene.items() if isinstance(i, NodeItem))
        self.assertEqual(node.pos(), QPointF(300, 200))
        self.mock_snapshot.assert_called_once()

    def test_clicked_components_fill_a_grid(self):
        positions = []
        for _ in range(6):
            self.main_app.component("Mixer", pos=False)  # clicked() passes a bool
            positions.append(self.main_app.component_offset)

        # Five per row, 180px apart, then wrap 150px down to the first column
        for a, b in zip(positions[:4], positions[1:5]):
            self.assertEqual(b.x() - a.x(), 180)
            self.assertEqual(b.y(), a.y())
        self.assertEqual(positions[5].x(), positions[1].x() - 180)
        self.assertEqual(positions[5].y(), positions[0].y() + 150)

    def test_grid_counter_recovers_if_missing(self):
        self.main_app.component("Mixer")
        del self.main_app._grid_count
        self.main_app.component("Mixer")
        self.assertEqual(self.main_app._grid_count, 1)

    def test_fallback_positions_item_found_in_scene(self):
        mock_timer = MagicMock()
        added = []

        def add_without_returning(obj):
            item = MagicMock()
            added.append(item)
            self.main_app.scene.addItem(QGraphicsRectItemFactory())
            return None

        with patch.object(self.main_app.container, "add_unit_operation", side_effect=add_without_returning), \
                patch("mainApp.QTimer", mock_timer):
            self.main_app.component("Mixer", pos=QPointF(40, 60))

        delay, find_and_position_new = mock_timer.singleShot.call_args.args
        self.assertEqual(delay, 50)
        find_and_position_new()

        rect_item = next(i for i in self.main_app.scene.items() if not isinstance(i, NodeItem))
        self.assertEqual(rect_item.pos(), QPointF(40, 60))
        self.mock_snapshot.assert_called_once()

    def test_fallback_centers_clicked_component(self):
        mock_timer = MagicMock()
        with patch.object(self.main_app.container, "add_unit_operation",
                          side_effect=lambda obj: self.main_app.scene.addItem(QGraphicsRectItemFactory())), \
                patch("mainApp.QTimer", mock_timer), \
                patch.object(self.main_app.graphicsView, "centerOn") as mock_center:
            self.main_app.component("Mixer")
            mock_timer.singleShot.call_args.args[1]()
        mock_center.assert_called_once()

    def test_fallback_without_new_items_does_not_snapshot(self):
        mock_timer = MagicMock()
        with patch.object(self.main_app.container, "add_unit_operation", return_value=None), \
                patch("mainApp.QTimer", mock_timer):
            self.main_app.component("Mixer")
            mock_timer.singleShot.call_args.args[1]()
        self.mock_snapshot.assert_not_called()

    def test_fallback_survives_item_errors(self):
        mock_timer = MagicMock()
        bad_item = QGraphicsRectItemFactory()
        with patch.object(self.main_app.container, "add_unit_operation",
                          side_effect=lambda obj: self.main_app.scene.addItem(bad_item)), \
                patch("mainApp.QTimer", mock_timer):
            self.main_app.component("Mixer", pos=QPointF(1, 1))
            with patch.object(type(bad_item), "setPos", side_effect=RuntimeError("deleted")):
                mock_timer.singleShot.call_args.args[1]()
        self.mock_snapshot.assert_not_called()


def QGraphicsRectItemFactory():
    from PyQt5.QtWidgets import QGraphicsRectItem
    return QGraphicsRectItem(0, 0, 10, 10)


# =============================================================================
# new / new_file / new_project
# =============================================================================

class TestMainAppNew(MainAppTestBase):

    def test_new_resets_project(self):
        self.main_app.component("Mixer")
        self.main_app.component("Mixer")
        old_container = self.main_app.container
        dock_widget_lst.append(MagicMock())

        self.main_app.new()

        self.assertIsNot(self.main_app.container, old_container)
        self.assertEqual(self.main_app.container.unit_operations, [])
        self.assertIs(self.main_app.graphicsView.scene(), self.main_app.scene)
        self.assertEqual(Mixer.counter, 1)
        self.assertEqual(dock_widget_lst, [])
        self.assertEqual(compound_selected, [])
        self.assertIsNone(self.main_app.component_offset)
        self.assertEqual(self.main_app.windowTitle(), "Untitled - Chemical Simulator GUI")
        self.assertIn("New flowsheet is created", self.messages())
        # One snapshot of the empty canvas, so there is nothing to undo yet
        self.assertEqual(undo_manager.stack_size("Undo"), 1)
        self.assertFalse(self.main_app.actionUndo.isEnabled())

    def test_new_skips_already_deleted_dock_widgets(self):
        deleted = MagicMock()
        deleted.hide.side_effect = RuntimeError("wrapped C/C++ object has been deleted")
        dock_widget_lst.append(deleted)
        self.main_app.new()
        self.assertEqual(dock_widget_lst, [])

    def test_new_survives_snapshot_failure(self):
        with patch("mainApp.Container") as mock_container:
            mock_container.return_value.graphics.save_canvas.side_effect = RuntimeError("no scene")
            mock_container.return_value.graphics.get_scene.return_value = self.main_app.scene
            self.main_app.new()
        self.assertIn("New flowsheet is created", self.messages())

    def test_new_reports_errors(self):
        with patch("mainApp.Container", side_effect=RuntimeError("out of memory")):
            self.main_app.new()
        self.assertIn("Failed to create new flowsheet: out of memory", self.messages())

    def test_new_project_resets_and_shows_compound_selector(self):
        with patch.object(self.main_app, "new") as mock_new, \
                patch.object(self.main_app.comp, "show") as mock_show:
            self.main_app.new_project()
        mock_new.assert_called_once()
        mock_show.assert_called_once()

    def run_new_file(self, choice, save_result=True):
        """Run new_file() with the Save / Don't Save / Cancel box answered by `choice`."""
        with patch("mainApp.QMessageBox") as mock_box_cls, \
                patch.object(self.main_app, "new") as mock_new, \
                patch.object(self.main_app, "save", return_value=save_result) as mock_save:
            box = mock_box_cls.return_value
            buttons = {}
            box.addButton.side_effect = lambda text, role: buttons.setdefault(text, MagicMock())
            box.clickedButton.side_effect = lambda: buttons[choice]
            self.main_app.new_file()
        return mock_new, mock_save

    def test_new_file_cancel_keeps_project(self):
        mock_new, mock_save = self.run_new_file("Cancel")
        mock_new.assert_not_called()
        mock_save.assert_not_called()

    def test_new_file_dont_save_starts_new_project(self):
        mock_new, mock_save = self.run_new_file("Don't Save")
        mock_save.assert_not_called()
        mock_new.assert_called_once()

    def test_new_file_save_then_new(self):
        mock_new, mock_save = self.run_new_file("Save")
        mock_save.assert_called_once()
        mock_new.assert_called_once()

    def test_new_file_save_cancelled_keeps_project(self):
        mock_new, mock_save = self.run_new_file("Save", save_result=False)
        mock_save.assert_called_once()
        mock_new.assert_not_called()


# =============================================================================
# undo / redo
# =============================================================================

class TestMainAppUndoRedo(MainAppTestBase):

    def setUp(self):
        super().setUp()
        self.main_app.new()  # pushes the empty-canvas snapshot
        self.select_compounds()

    def add_mixer(self):
        self.main_app.component("Mixer")  # pushes a snapshot with the mixer

    def test_undo_restores_previous_canvas(self):
        self.add_mixer()
        self.assertEqual(self.unit_names(), ["Mixer1"])

        self.main_app.undo()

        self.assertEqual(self.unit_names(), [])
        self.assertEqual(undo_manager.stack_size("Redo"), 1)
        self.assertTrue(self.main_app.actionRedo.isEnabled())

    def test_redo_reapplies_undone_change(self):
        self.add_mixer()
        self.main_app.undo()
        self.main_app.redo()

        self.assertEqual(self.unit_names(), ["Mixer1"])
        self.assertEqual(undo_manager.stack_size("Redo"), 0)
        self.assertFalse(self.main_app.actionRedo.isEnabled())

    def test_undo_at_initial_state_keeps_snapshot(self):
        self.main_app.undo()
        self.assertEqual(undo_manager.stack_size("Undo"), 1)
        self.assertEqual(undo_manager.stack_size("Redo"), 0)

    def test_undo_with_empty_history(self):
        undo_manager.reset_all()
        self.main_app.undo()
        self.assertEqual(undo_manager.stack_size("Undo"), 0)

    def test_redo_with_nothing_to_redo(self):
        self.add_mixer()
        self.main_app.redo()
        self.assertEqual(self.unit_names(), ["Mixer1"])

    def test_undo_and_redo_errors_are_handled(self):
        self.add_mixer()
        with patch.object(self.main_app, "undo_redo_helper", side_effect=RuntimeError("boom")):
            self.main_app.undo()
            self.main_app.redo()  # must not raise

    def test_undo_redo_helper_resets_canvas(self):
        self.add_mixer()
        old_container = self.main_app.container
        self.main_app.undo_redo_helper()

        self.assertIsNot(self.main_app.container, old_container)
        self.assertEqual(dock_widget_lst, [])
        self.assertEqual(self.main_app._grid_count, 0)
        self.assertIs(self.main_app.graphicsView.scene(), self.main_app.scene)
        self.assertEqual(Mixer.counter, 1)


# =============================================================================
# save / open
# =============================================================================

class TestMainAppSaveOpen(MainAppTestBase):

    def save_to(self, path):
        with patch("mainApp.QFileDialog.getSaveFileName", return_value=(path, "")):
            return self.main_app.save()

    def test_save_and_open_round_trip(self):
        self.main_app.new()
        self.select_compounds()
        self.main_app.component("Mixer")
        self.main_app.component("Heater")
        path = os.path.join(self.tmp_dir, "plant.sim").replace("\\", "/")

        self.assertTrue(self.save_to(path))
        self.assertEqual(self.main_app.windowTitle(), "plant - Chemical Simulator GUI")
        self.assertEqual(self.main_app.last_saved_project, path)
        self.assertTrue(all(op.saved for op in self.main_app.container.unit_operations))

        self.main_app.new()
        self.assertEqual(self.unit_names(), [])

        self.main_app.open(path)

        self.assertEqual(self.unit_names(), ["Heater1", "Mixer1"])
        self.assertEqual(self.main_app.windowTitle(), "plant - Chemical Simulator GUI")
        self.assertIn("Project plant loaded successfully.", self.messages())
        # History restarts at the opened state
        self.assertEqual(undo_manager.stack_size("Undo"), 1)
        self.assertEqual(undo_manager.stack_size("Redo"), 0)

    def test_save_cancelled(self):
        self.assertFalse(self.save_to(""))
        self.assertFalse(hasattr(self.main_app, "last_saved_project"))

    def test_save_when_canvas_cannot_be_captured(self):
        with patch.object(self.main_app.container.graphics, "save_canvas", return_value=None):
            self.assertFalse(self.main_app.save())
        self.assertIn("Failed to capture the canvas for saving.", self.messages())

    def test_save_to_unwritable_path(self):
        path = os.path.join(self.tmp_dir, "no_such_dir", "plant.sim")
        self.assertFalse(self.save_to(path))

    def test_open_uses_file_dialog_when_no_path_given(self):
        path = os.path.join(self.tmp_dir, "dialog.sim").replace("\\", "/")
        self.save_to(path)
        with patch("mainApp.QFileDialog.getOpenFileName", return_value=(path, "")) as mock_dialog:
            self.main_app.open()
        mock_dialog.assert_called_once()
        self.assertIn("Project dialog loaded successfully.", self.messages())

    def test_open_cancelled_does_nothing(self):
        title = self.main_app.windowTitle()
        with patch("mainApp.QFileDialog.getOpenFileName", return_value=("", "")):
            self.main_app.open()
        self.assertEqual(self.main_app.windowTitle(), title)

    def test_open_rejects_unknown_format(self):
        path = os.path.join(self.tmp_dir, "weird.sim")
        with open(path, "wb") as f:
            pickle.dump("not a project", f)

        self.main_app.open(path)
        self.assertIn("unsupported or outdated file format", self.messages())

    @patch("mainApp.QMessageBox.critical")
    def test_open_corrupt_file_shows_error(self, mock_critical):
        path = os.path.join(self.tmp_dir, "corrupt.sim")
        with open(path, "wb") as f:
            f.write(b"definitely not pickle")

        self.main_app.open(path)
        self.assertEqual(mock_critical.call_args.args[1], "Error")
        self.assertIn("Failed to load project", mock_critical.call_args.args[2])

    def test_open_with_results_shows_them(self):
        path = os.path.join(self.tmp_dir, "solved.sim").replace("\\", "/")
        self.main_app.component("Mixer")
        self.main_app.container.result = [["header"], ["values"]]
        self.save_to(path)

        with patch("mainApp.DockWidget.show_result") as mock_show_result, \
                patch.object(mainApp.DockWidget, "param", create=True):
            for dw in dock_widget_lst:
                dw.param = MagicMock()
            self.main_app.open(path)

        mock_show_result.assert_called_once_with(dock_widget_lst)
        self.assertEqual(self.main_app.container.result, [["header"], ["values"]])

    def test_open_converts_legacy_list_format(self):
        path = os.path.join(self.tmp_dir, "legacy.sim").replace("\\", "/")
        mixer = Mixer()
        with open(path, "wb") as f:
            pickle.dump([mixer, ["Water(chemsep)"], None], f)

        self.main_app.open(path)
        self.assertEqual(self.unit_names(), ["Mixer1"])


class TestLegacySimConversion(MainAppTestBase):
    """_legacy_sim_to_snapshot converts the old flat-list .sim format."""

    def make_op(self, name, type_, pos=None, input_stms=None, output_stms=None):
        op = MagicMock(spec=["name", "type", "pos", "input_stms", "output_stms"])
        op.name, op.type, op.pos = name, type_, pos
        op.input_stms, op.output_stms = input_stms, output_stms
        return op

    def test_empty_data(self):
        self.assertEqual(self.main_app._legacy_sim_to_snapshot([]),
                         {"items": [], "connections": [], "compounds": [], "result": None})

    def test_items_compounds_and_result(self):
        mixer = self.make_op("Mixer1", "Mixer", pos=QPointF(10, 20))
        snap = self.main_app._legacy_sim_to_snapshot([mixer, ["Water"], "RESULT"])

        self.assertEqual(snap["items"], [{"obj": mixer, "pos": (10, 20)}])
        self.assertEqual(snap["compounds"], ["Water"])
        self.assertEqual(snap["result"], "RESULT")

    def test_missing_or_bad_position_defaults_to_origin(self):
        no_pos = self.make_op("A", "Mixer", pos=None)
        bad_pos = self.make_op("B", "Mixer", pos="not a point")
        snap = self.main_app._legacy_sim_to_snapshot([no_pos, bad_pos, [], None])
        self.assertEqual([i["pos"] for i in snap["items"]], [(0, 0), (0, 0)])

    def test_connections_rebuilt_from_stream_dicts(self):
        feed = self.make_op("S1", "MaterialStream")
        product = self.make_op("S2", "MaterialStream")
        mixer = self.make_op("Mixer1", "Mixer", input_stms={2: feed}, output_stms={1: product})

        snap = self.main_app._legacy_sim_to_snapshot([feed, product, mixer, [], None])

        self.assertEqual(snap["connections"], [
            {"source_name": "S1", "source_id": 1, "target_name": "Mixer1", "target_id": 2},
            {"source_name": "Mixer1", "source_id": 1, "target_name": "S2", "target_id": 1},
        ])


if __name__ == "__main__":
    unittest.main()
