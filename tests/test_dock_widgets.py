import os
import sys
import unittest
from unittest.mock import MagicMock
from PyQt5.QtCore import QSize
from PyQt5.QtWidgets import QWidget, QMainWindow
from unittest.mock import patch

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication

app = QApplication.instance() or QApplication([])

from python.utils.ComponentSelector import compound_selected
from python.utils.UnitOperations import (
    Mixer, Splitter, Flash, CompoundSeparator,
    AdiabaticCompressor, ShortcutColumn, DistillationColumn, Heater
)
from python.DockWidgets.DockWidget import BaseDockWidget, DockWidget
from python.DockWidgets.DockWidgetMixer import DockWidgetMixer
from python.DockWidgets.DockWidgetSplitter import DockWidgetSplitter
from python.DockWidgets.DockWidgetFlash import DockWidgetFlash
from python.DockWidgets.DockWidgetCompoundSeparator import DockWidgetCompoundSeparator
from python.DockWidgets.DockWidgetCompressorExpander import DockWidgetCompressorExpander
from python.DockWidgets.DockWidgetShortcutColumn import DockWidgetShortcutColumn
from python.DockWidgets.DockWidgetDistillationColumn import DockWidgetDistillationColumn


class MockContainer:
    """Mock container providing unit operations and mock graphics view."""
    def __init__(self):
        self.unit_operations = []
        self.graphics = MagicMock()


class TestDockWidgetsUnitOperations(unittest.TestCase):
    """Test suite for Unit Operation DockWidgets (property inspector panels)."""

    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        self.container = MockContainer()

    def tearDown(self):
        compound_selected.clear()
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

    # ----------------- DockWidgetMixer ----------------- #

    def test_dock_widget_mixer_initialization_and_param_update(self):
        mixer = Mixer()
        mixer.name = "Mixer1"
        self.container.unit_operations.append(mixer)

        dock = DockWidgetMixer("Mixer1", "Mixer", mixer, self.container)
        self.assertEqual(dock.windowTitle(), "Mixer1")
        self.assertEqual(dock.ni_combo.currentText(), "2")
        self.assertEqual(dock.cb2.currentText(), "Inlet_Average")

        # Simulate user changing NI to 4 and pressure to Inlet_Minimum
        dock.ni_combo.setCurrentText("4")
        dock.cb2.setCurrentText("Inlet_Minimum")
        dock.param()

        self.assertEqual(mixer.no_of_inputs, 4)
        self.assertEqual(mixer.variables['NI']['value'], 4)
        self.assertEqual(mixer.variables['outPress']['value'], "Inlet_Minimum")

    # ----------------- DockWidgetSplitter ----------------- #

    def test_dock_widget_splitter_initialization_and_equalize(self):
        splitter = Splitter()
        splitter.name = "Splitter1"
        self.container.unit_operations.append(splitter)

        dock = DockWidgetSplitter("Splitter1", "Splitter", splitter, self.container)
        self.assertEqual(dock.windowTitle(), "Splitter1")
        self.assertEqual(dock.no_combo.currentText(), "2")

        # Test equalizing streams
        dock.equalize_streams()
        v1 = float(dock.stream_edits[0].text())
        v2 = float(dock.stream_edits[1].text())
        self.assertAlmostEqual(v1, 0.5, places=2)
        self.assertAlmostEqual(v2, 0.5, places=2)

        # Apply parameters
        dock.param()
        self.assertEqual(splitter.no_of_outputs, 2)
        self.assertEqual(splitter.variables['CalcType']['value'], "Split_Ratio")

    # ----------------- DockWidgetFlash ----------------- #

    def test_dock_widget_flash_initialization_and_toggles(self):
        flash = Flash()
        flash.name = "Flash1"
        self.container.unit_operations.append(flash)

        dock = DockWidgetFlash("Flash1", "Flash", flash, self.container)
        self.assertEqual(dock.windowTitle(), "Flash1")
        self.assertIsNotNone(dock.cb1.currentText())

        # Check toggle reaction
        dock.check1.setChecked(True)
        self.assertTrue(dock.le2.isEnabled())
        dock.check1.setChecked(False)
        self.assertFalse(dock.le2.isEnabled())

        # Update temperature and pressure values and submit
        dock.check1.setChecked(True)
        dock.le2.setText("320.0")
        dock.check2.setChecked(True)
        dock.le3.setText("105000")
        dock.param()

        self.assertEqual(flash.variables['Tdef']['value'], 320.0)
        self.assertEqual(flash.variables['Pdef']['value'], 105000)

    # ----------------- DockWidgetCompoundSeparator ----------------- #

    def test_dock_widget_compound_separator_initialization(self):
        cs = CompoundSeparator()
        cs.name = "CS1"
        self.container.unit_operations.append(cs)

        dock = DockWidgetCompoundSeparator("CS1", "CompoundSeparator", cs, self.container)
        self.assertEqual(dock.windowTitle(), "CS1")
        self.assertIsNotNone(dock.calculationLayout)
        self.assertGreater(len(dock.lst), 0)

    # ----------------- DockWidgetCompressorExpander ----------------- #

    def test_dock_widget_compressor_expander_initialization(self):
        comp = AdiabaticCompressor()
        comp.name = "Compressor1"
        self.container.unit_operations.append(comp)

        dock = DockWidgetCompressorExpander("Compressor1", "Compressor", comp, self.container)
        self.assertEqual(dock.windowTitle(), "Compressor1")
        self.assertIsNotNone(dock.comboBox.currentText())

    # ----------------- DockWidgetShortcutColumn ----------------- #

    def test_dock_widget_shortcut_column_initialization(self):
        sc = ShortcutColumn()
        sc.name = "ShortCol1"
        self.container.unit_operations.append(sc)

        dock = DockWidgetShortcutColumn("ShortCol1", "ShortcutColumn", sc, self.container)
        self.assertEqual(dock.windowTitle(), "ShortCol1")
        self.assertIsNotNone(dock.cb1.currentText())
        self.assertIsNotNone(dock.cb2.currentText())

    # ----------------- DockWidgetDistillationColumn ----------------- #

    def test_dock_widget_distillation_column_initialization(self):
        dc = DistillationColumn()
        dc.name = "DistCol1"
        self.container.unit_operations.append(dc)

        dock = DockWidgetDistillationColumn("DistCol1", "DistillationColumn", dc, self.container)
        self.assertEqual(dock.windowTitle(), "DistCol1")
        self.assertIsNotNone(dock.cb1.currentText())

    # ----------------- DockWidget1 (Heater / Generic Unit Ops) ----------------- #

    def test_dock_widget1_initialization_modes_and_param(self):
        heater = Heater()
        heater.name = "Heater1"
        heater.param_setter = MagicMock()
        self.container.unit_operations.append(heater)

        mock_item = MagicMock()
        mock_item.name = "Heater1"
        mock_item.obj = heater
        mock_item.update_tooltip = MagicMock()
        self.container.graphics.graphicsView = MagicMock()
        self.container.graphics.graphicsView.items.return_value = [mock_item]
        self.container.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100

        dock = DockWidget("Heater1", "Heater", heater, self.container)
        self.assertEqual(dock.windowTitle(), "Heater1")
        self.assertGreater(dock.comboBox.count(), 0)

        # Switch modes
        dock.comboBox.setCurrentIndex(1)
        self.assertGreater(len(dock.input_dict), 0)

        # Param submit
        dock.input_dict[None] = None
        for k, edit in dock.input_dict.items():
            if hasattr(edit, "setText"):
                edit.setText("350")
        dock.show()
        dock.param()
        heater.param_setter.assert_called_once()
        mock_item.update_tooltip.assert_called_once()

    def test_dock_widget1_param_empty_shows_error(self):
        heater = Heater()
        heater.name = "Heater2"
        dock = DockWidget("Heater2", "Heater", heater, self.container)
        dock.show_error = MagicMock()

        for k, edit in dock.input_dict.items():
            if hasattr(edit, "setText"):
                edit.setText("")
                break
        dock.param()
        dock.show_error.assert_called_once()

    def test_dock_widget1_results_category(self):
        heater = Heater()
        heater.name = "Heater1"
        self.container.result = [["Heater1.Tout", "Heater1.Q"], [360.0, 12000.0]]
        self.container.fetch_object = MagicMock(return_value=heater)

        dock = DockWidget("Heater1", "Heater", heater, self.container)
        dock.results_category("Heater1")
        self.assertGreater(dock.tableWidget.rowCount(), 0)

    # ----------------- BaseDockWidget Rename and Utilities ----------------- #


    def test_base_dock_widget_autosize(self):
        class TestContent(QWidget):
            def sizeHint(self):
                return QSize(500, 600)

        dock = BaseDockWidget()
        content = TestContent()
        dock.setWidget(content)

        mock_screen = MagicMock()
        mock_screen.availableGeometry.return_value.width.return_value = 1920
        mock_screen.availableGeometry.return_value.height.return_value = 1080

        with patch(
            "python.DockWidgets.DockWidget.QApplication.primaryScreen",
            return_value=mock_screen
        ):
            dock._autosize()

        self.assertEqual(dock.width(), 530)
        self.assertEqual(dock.height(), 650)

    def test_base_dock_widget_rename_validation(self):
        heater = Heater()
        heater.name = "Heater1"
        self.container.flowsheet = MagicMock()
        self.container.flowsheet.unit_operations = {"Heater1": heater}
        self.container.flowsheet.streams = {}
        self.container.undo_manager = MagicMock()
        self.container.result = [["Heater1.Tout"], [350.0]]

        dock = DockWidget("Heater1", "Heater", heater, self.container)
        dock.le_name.setText("Heater1")
        # Same name -> True
        self.assertTrue(dock.rename_component())

        # Empty name -> Warning
        dock.le_name.setText("   ")
        from unittest.mock import patch
        with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
            self.assertFalse(dock.rename_component())
            mock_warn.assert_called_once()

        # Invalid characters (hyphen / space) -> Warning
        dock.le_name.setText("Invalid-Name")
        with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
            self.assertFalse(dock.rename_component())
            mock_warn.assert_called_once()

        # Valid rename with energy stream cascades and flowsheet result_data
        heater.EngStms = MagicMock()
        heater.EngStm1 = MagicMock()
        heater.EngStm2 = MagicMock()
        self.container.flowsheet.result_data = [["Heater1.Q"], [1000.0]]
        self.container.fetch_object = MagicMock(return_value=heater)
        mock_node = MagicMock()
        mock_node.text = MagicMock()
        dock.node_item = mock_node
        dock.le_name.setText("HeaterNew")
        self.assertTrue(dock.rename_component())
        self.assertEqual(dock.name, "HeaterNew")
        self.assertEqual(heater.name, "HeaterNew")
        self.assertEqual(heater.EngStms.name, "EngStmHeaterNew")
        self.assertEqual(heater.EngStm1.name, "EngStm1HeaterNew")
        self.assertEqual(heater.EngStm2.name, "EngStm2HeaterNew")
        self.assertEqual(self.container.flowsheet.result_data[0][0], "HeaterNew.Q")
        self.assertEqual(mock_node.name, "HeaterNew")
        mock_node.text.setPlainText.assert_called_once_with("HeaterNew")

    def test_base_dock_widget_set_read_only(self):
        heater = Heater()
        heater.name = "HeaterReadOnly"
        dock = DockWidget("HeaterReadOnly", "Heater", heater, self.container)
        dock.x_pclist = [MagicMock()]
        dock.calculationGroupBox = MagicMock()
        btn = MagicMock()
        grid = MagicMock()
        grid.count.return_value = 1
        item = MagicMock()
        from PyQt5.QtWidgets import QPushButton
        mock_btn = QPushButton("Submit")
        item.widget.return_value = mock_btn
        grid.itemAt.return_value = item
        dock.gridLayout = grid

        dock.set_read_only(True)
        self.assertFalse(dock.comboBox.isEnabled())
        self.assertFalse(mock_btn.isEnabled())
        dock.set_read_only(False)
        self.assertTrue(dock.comboBox.isEnabled())
        self.assertTrue(mock_btn.isEnabled())

    def test_base_dock_widget_get_node_item_and_clear_results(self):
        heater = Heater()
        heater.name = "HeaterGetItem"
        dock = DockWidget("HeaterGetItem", "Heater", heater, self.container)
        dock.node_item = None

        mock_item = MagicMock()
        mock_item.dock_widget = dock
        from python.utils import Graphics as g_mod
        g_mod.lst.append(mock_item)

        try:
            item = dock.get_node_item()
            self.assertEqual(item, mock_item)
        finally:
            if mock_item in g_mod.lst:
                g_mod.lst.remove(mock_item)

        # Scene items fallback
        dock.node_item = None
        mock_scene_item = MagicMock()
        mock_scene_item.obj = heater
        self.container.graphics.scene = MagicMock()
        self.container.graphics.scene.items.return_value = [mock_scene_item]
        self.assertEqual(dock.get_node_item(), mock_scene_item)

        dock.clear_results()
        self.assertEqual(dock.tableWidget.rowCount(), 0)

        # BaseDockWidget.show_result
        mock_dw = MagicMock()
        mock_dw.name = "MockDW"
        BaseDockWidget.show_result([mock_dw])
        mock_dw.results_category.assert_called_once_with("MockDW")

    def test_base_dock_widget_rename_duplicates_and_check(self):
        heater = Heater()
        heater.name = "HeaterOrig"
        mock_existing = MagicMock()
        mock_existing.name = "ExistingUnit"
        self.container.unit_operations = [mock_existing]

        dock = DockWidget("HeaterOrig", "Heater", heater, self.container)

        # Duplicate unit operation
        dock.le_name.setText("ExistingUnit")
        from unittest.mock import patch
        with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
            self.assertFalse(dock.rename_component())
            mock_warn.assert_called()

        # Invalid starts with number
        dock.le_name.setText("123Bad")
        with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
            self.assertFalse(dock.rename_component())
            mock_warn.assert_called()

        # check_and_rename_if_needed
        dock.le_name.setText("HeaterOrig")
        self.assertTrue(dock.check_and_rename_if_needed())

    def test_dock_widget_empty_modes_fallback(self):
        heater = Heater()
        heater.name = "HeaterNoModes"
        heater.modes_list = []
        heater.param_getter = MagicMock(return_value={"Tout": 350})

        dock = DockWidget("HeaterNoModes", "Heater", heater, self.container)
        self.assertFalse(dock.comboBox.isEnabled())
        self.assertIn("Tout", dock.input_dict)


if __name__ == "__main__":
    unittest.main()
