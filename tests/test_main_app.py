import os
import sys
import unittest
from unittest.mock import MagicMock, patch

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication

app = QApplication.instance() or QApplication([])

from mainApp import MainApp
from python.utils.ComponentSelector import compound_selected
from python.utils.Graphics import lst, dock_widget_lst
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


if __name__ == "__main__":
    unittest.main()
