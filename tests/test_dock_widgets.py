import os
import sys
import unittest
from unittest.mock import MagicMock

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication

app = QApplication.instance() or QApplication([])

from python.utils.ComponentSelector import compound_selected
from python.utils.UnitOperations import (
    Mixer, Splitter, Flash, CompoundSeparator,
    AdiabaticCompressor, ShortcutColumn, DistillationColumn
)
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


if __name__ == "__main__":
    unittest.main()
