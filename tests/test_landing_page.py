import os
import sys
import unittest
from unittest.mock import MagicMock, patch

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QPushButton, QMessageBox

app = QApplication.instance() or QApplication([])

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


if __name__ == "__main__":
    unittest.main()
