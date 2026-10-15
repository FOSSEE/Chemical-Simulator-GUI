import os
import sys
import unittest
from unittest.mock import patch, MagicMock

# Ensure headless Qt
os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QMessageBox, QGraphicsScene, QGraphicsView
from PyQt5.QtCore import QPointF

# Initialize QApplication once
app = QApplication.instance()
if app is None:
    app = QApplication(sys.argv)

from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.utils.UnitOperations import (
    Mixer, Splitter, Heater, Cooler, Flash, CompoundSeparator,
    ShortcutColumn, DistillationColumn, AdiabaticCompressor
)
from python.DockWidgets.DockWidget import DockWidget, BaseDockWidget
from python.DockWidgets.DockWidgetMaterialStream import DockWidgetMaterialStream
from python.DockWidgets.DockWidgetMixer import DockWidgetMixer
from python.DockWidgets.DockWidgetSplitter import DockWidgetSplitter
from python.DockWidgets.DockWidgetFlash import DockWidgetFlash
from python.DockWidgets.DockWidgetCompoundSeparator import DockWidgetCompoundSeparator
from python.DockWidgets.DockWidgetShortcutColumn import DockWidgetShortcutColumn
from python.DockWidgets.DockWidgetDistillationColumn import DockWidgetDistillationColumn
from python.DockWidgets.DockWidgetCompressorExpander import DockWidgetCompressorExpander
from python.utils.Graphics import NodeItem, lst, dock_widget_lst
from python.utils.Container import Container


class MockMainWindow:
    """Mock for main window with textBrowser and update actions."""
    def __init__(self):
        self.textBrowser = MagicMock()

    def _update_undo_redo_actions(self):
        pass


class TestComponentNameEditing(unittest.TestCase):
    """Comprehensive unit tests for the Editable Component Name feature."""

    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        lst.clear()
        dock_widget_lst.clear()
        Mixer.counter = 1
        Splitter.counter = 1
        Heater.counter = 1
        Cooler.counter = 1
        Flash.counter = 1
        CompoundSeparator.counter = 1
        ShortcutColumn.counter = 1
        DistillationColumn.counter = 1
        AdiabaticCompressor.counter = 1
        MaterialStream.counter = 1

        self.mock_view = QGraphicsView()
        self.mock_tb = MagicMock()
        self.container = Container(self.mock_tb, self.mock_view)

    def tearDown(self):
        lst.clear()
        dock_widget_lst.clear()

    # -------------------------------------------------------------------------
    # 1. Name Field Presence and Default Display across Component Types
    # -------------------------------------------------------------------------

    def test_default_name_displayed_for_various_components(self):
        """Verify the Name field displays the current default component name across various types."""
        components = [
            (MaterialStream(["Water(chemsep)"]), DockWidgetMaterialStream, "MaterialStream1"),
            (Mixer(), DockWidgetMixer, "Mixer1"),
            (Splitter(), DockWidgetSplitter, "Splitter1"),
            (Heater(), DockWidget, "Heater1"),
            (AdiabaticCompressor(), DockWidgetCompressorExpander, "AdiabaticCompressor1"),
            (Flash(), DockWidgetFlash, "Flash1"),
            (CompoundSeparator(), DockWidgetCompoundSeparator, "CompoundSeparator1"),
            (ShortcutColumn(), DockWidgetShortcutColumn, "ShortcutColumn1"),
            (DistillationColumn(), DockWidgetDistillationColumn, "DistillationColumn1"),
        ]

        for obj, dock_cls, expected_name in components:
            self.container.unit_operations.append(obj)
            dock = dock_cls(obj.name, obj.type, obj, self.container)

            # Check that name widget components exist
            self.assertTrue(hasattr(dock, 'le_name'), f"{dock_cls.__name__} missing le_name")
            self.assertTrue(hasattr(dock, 'btn_name'), f"{dock_cls.__name__} missing btn_name")
            self.assertTrue(hasattr(dock, 'lbl_name'), f"{dock_cls.__name__} missing lbl_name")

            # Check displayed text matches component's initial name
            self.assertEqual(dock.le_name.text(), expected_name)
            self.assertEqual(dock.name, expected_name)
            self.assertEqual(dock.windowTitle(), expected_name)
            self.assertEqual(dock.btn_name.text(), "OK")
            self.assertEqual(dock.lbl_name.text(), "Name: ")

    # -------------------------------------------------------------------------
    # 2. Successful Renaming Updates Everywhere
    # -------------------------------------------------------------------------

    def test_rename_updates_dock_model_and_canvas(self):
        """Clicking OK on a valid new name updates dock, model object, and canvas NodeItem."""
        mixer_obj = Mixer()
        self.container.unit_operations.append(mixer_obj)

        node_item = self.container.graphics.create_node_item(mixer_obj, self.container)
        dock = node_item.dock_widget

        self.assertEqual(dock.name, "Mixer1")
        self.assertEqual(node_item.text.toPlainText(), "Mixer1")

        # Edit name in QLineEdit
        dock.le_name.setText("PrimaryMixer")

        # Click OK button
        dock.btn_name.click()

        # Verify updates everywhere
        self.assertEqual(dock.name, "PrimaryMixer")
        self.assertEqual(mixer_obj.name, "PrimaryMixer")
        self.assertEqual(dock.windowTitle(), "PrimaryMixer")
        self.assertEqual(node_item.name, "PrimaryMixer")
        self.assertEqual(node_item.text.toPlainText(), "PrimaryMixer")
        self.assertTrue(node_item.toolTip().startswith("PrimaryMixer"))

    def test_rename_material_stream(self):
        """Renaming a MaterialStream updates canvas label, tooltip, and dock."""
        strm_obj = MaterialStream(["Water(chemsep)", "Ethanol(chemsep)"])
        self.container.unit_operations.append(strm_obj)

        node_item = self.container.graphics.create_node_item(strm_obj, self.container)
        dock = node_item.dock_widget

        self.assertEqual(dock.name, "MaterialStream1")
        dock.le_name.setText("FeedInlet")
        dock.btn_name.click()

        self.assertEqual(dock.name, "FeedInlet")
        self.assertEqual(strm_obj.name, "FeedInlet")
        self.assertEqual(node_item.name, "FeedInlet")
        self.assertEqual(node_item.text.toPlainText(), "FeedInlet")

    def test_rename_trims_whitespace(self):
        """Leading and trailing whitespace in new names is automatically trimmed."""
        mixer_obj = Mixer()
        self.container.unit_operations.append(mixer_obj)
        dock = DockWidgetMixer(mixer_obj.name, mixer_obj.type, mixer_obj, self.container)

        dock.le_name.setText("   TrimmedMixer   ")
        dock.rename_component()

        self.assertEqual(dock.name, "TrimmedMixer")
        self.assertEqual(mixer_obj.name, "TrimmedMixer")
        self.assertEqual(dock.le_name.text(), "TrimmedMixer")

    # -------------------------------------------------------------------------
    # 3. Validation: Reject Empty and Invalid Identifiers
    # -------------------------------------------------------------------------

    @patch.object(QMessageBox, 'warning')
    def test_empty_name_rejected_and_reverted(self, mock_warning):
        """Empty or whitespace-only name is rejected with a warning and reverted."""
        heater_obj = Heater()
        self.container.unit_operations.append(heater_obj)
        dock = DockWidget(heater_obj.name, heater_obj.type, heater_obj, self.container)

        # Attempt empty name
        dock.le_name.setText("")
        result = dock.rename_component()

        self.assertFalse(result)
        mock_warning.assert_called_once()
        self.assertEqual(dock.name, "Heater1")
        self.assertEqual(heater_obj.name, "Heater1")
        self.assertEqual(dock.le_name.text(), "Heater1")

    @patch.object(QMessageBox, 'warning')
    def test_invalid_identifiers_rejected(self, mock_warning):
        """Names with spaces, symbols, or starting with digits are rejected."""
        invalid_names = [
            "123Heater",     # Starts with digit
            "Heater-Cooler", # Hyphen
            "Heater One",    # Space
            "Heater@1",      # Special symbol
            "Heater.Out",    # Dot
            "!Mixer",        # Special character
        ]

        mixer_obj = Mixer()
        self.container.unit_operations.append(mixer_obj)
        dock = DockWidgetMixer(mixer_obj.name, mixer_obj.type, mixer_obj, self.container)

        for invalid in invalid_names:
            dock.le_name.setText(invalid)
            result = dock.rename_component()

            self.assertFalse(result)
            self.assertEqual(dock.name, "Mixer1")
            self.assertEqual(mixer_obj.name, "Mixer1")
            self.assertEqual(dock.le_name.text(), "Mixer1")

    # -------------------------------------------------------------------------
    # 4. Uniqueness Validation: Reject Duplicates
    # -------------------------------------------------------------------------

    @patch.object(QMessageBox, 'warning')
    def test_duplicate_name_rejected(self, mock_warning):
        """Renaming a component to an existing component's name is rejected."""
        m1 = Mixer()
        m2 = Mixer()
        self.container.unit_operations.extend([m1, m2])

        dock1 = DockWidgetMixer(m1.name, m1.type, m1, self.container)
        dock2 = DockWidgetMixer(m2.name, m2.type, m2, self.container)

        self.assertEqual(dock1.name, "Mixer1")
        self.assertEqual(dock2.name, "Mixer2")

        # Try to rename Mixer2 to Mixer1
        dock2.le_name.setText("Mixer1")
        result = dock2.rename_component()

        self.assertFalse(result)
        mock_warning.assert_called_once()
        self.assertEqual(dock2.name, "Mixer2")
        self.assertEqual(m2.name, "Mixer2")
        self.assertEqual(dock2.le_name.text(), "Mixer2")

    def test_same_name_is_noop(self):
        """Renaming a component to its own name is a clean no-op."""
        m1 = Mixer()
        self.container.unit_operations.append(m1)
        dock = DockWidgetMixer(m1.name, m1.type, m1, self.container)

        dock.le_name.setText("Mixer1")
        result = dock.rename_component()

        self.assertTrue(result)
        self.assertEqual(dock.name, "Mixer1")

    # -------------------------------------------------------------------------
    # 5. Simulation Code Generation Uses Renamed Components & Connections Persist
    # -------------------------------------------------------------------------

    def test_simulation_code_generation_uses_renamed_components(self):
        """Renaming components updates OpenModelica initialization and connection equations."""
        stream = MaterialStream(["Water(chemsep)", "Ethanol(chemsep)"])
        mixer = Mixer()
        self.container.unit_operations.extend([stream, mixer])

        # Establish connection: stream -> mixer (flag 1 for input port 0)
        mixer.add_connection(1, 0, stream)

        dock_stream = DockWidgetMaterialStream(stream.name, stream.type, stream, self.container)
        dock_mixer = DockWidgetMixer(mixer.name, mixer.type, mixer, self.container)

        # Rename both components
        dock_stream.le_name.setText("FreshFeed")
        dock_stream.btn_name.click()

        dock_mixer.le_name.setText("BlendingUnit")
        dock_mixer.btn_name.click()

        self.assertEqual(stream.name, "FreshFeed")
        self.assertEqual(mixer.name, "BlendingUnit")

        # Test Modelica initialization code
        strm_init = stream.OM_Flowsheet_Initialize(["Water", "Ethanol"])
        mixer_init = mixer.OM_Flowsheet_Initialize()

        self.assertIn("FreshFeed", strm_init)
        self.assertNotIn("MaterialStream1", strm_init)
        self.assertIn("BlendingUnit", mixer_init)
        self.assertNotIn("Mixer1", mixer_init)

        # Test Modelica connection equation
        mixer_eqns = mixer.OM_Flowsheet_Equation()
        self.assertIn("connect(FreshFeed.Out, BlendingUnit.In[1]);", mixer_eqns)
        self.assertNotIn("MaterialStream1", mixer_eqns)
        self.assertNotIn("Mixer1", mixer_eqns)

    # -------------------------------------------------------------------------
    # 6. Energy Streams Synchronization
    # -------------------------------------------------------------------------

    def test_internal_energy_streams_renamed_for_heater_and_compressor(self):
        """Renaming units with internal energy streams updates the energy stream name."""
        col = ShortcutColumn()
        self.container.unit_operations.append(col)
        dock_col = DockWidgetShortcutColumn(col.name, col.type, col, self.container)

        self.assertEqual(col.EngStm1.name, "EngStm1ShortcutColumn1")
        self.assertEqual(col.EngStm2.name, "EngStm2ShortcutColumn1")

        dock_col.le_name.setText("Fractionator")
        dock_col.btn_name.click()

        self.assertEqual(col.name, "Fractionator")
        self.assertEqual(col.EngStm1.name, "EngStm1Fractionator")
        self.assertEqual(col.EngStm2.name, "EngStm2Fractionator")

    # -------------------------------------------------------------------------
    # 7. Post-Simulation Results Updating
    # -------------------------------------------------------------------------

    def test_simulation_results_header_updated_on_rename(self):
        """If simulation was already run, renaming updates result column headers and tables."""
        mixer = Mixer()
        self.container.unit_operations.append(mixer)
        dock = DockWidgetMixer(mixer.name, mixer.type, mixer, self.container)

        # Simulate existing results in container
        self.container.result = [
            ["time", "Mixer1.P", "Mixer1.T"],
            [0.0, 101325, 298.15]
        ]

        dock.le_name.setText("MainMixer")
        dock.btn_name.click()

        # Results header must be updated to new name
        self.assertIn("MainMixer.P", self.container.result[0])
        self.assertIn("MainMixer.T", self.container.result[0])
        self.assertNotIn("Mixer1.P", self.container.result[0])
        self.assertNotIn("Mixer1.T", self.container.result[0])

    # -------------------------------------------------------------------------
    # 8. Read-Only Mode Disables Name Editing
    # -------------------------------------------------------------------------

    def test_read_only_mode_disables_name_editing(self):
        """During simulation lock (read-only), name field and OK button are disabled."""
        mixer = Mixer()
        self.container.unit_operations.append(mixer)
        dock = DockWidgetMixer(mixer.name, mixer.type, mixer, self.container)

        dock.set_read_only(True)
        self.assertFalse(dock.le_name.isEnabled())
        self.assertFalse(dock.btn_name.isEnabled())

        dock.set_read_only(False)
        self.assertTrue(dock.le_name.isEnabled())
        self.assertTrue(dock.btn_name.isEnabled())

    # -------------------------------------------------------------------------
    # 9. Auto-rename on Param Submission
    # -------------------------------------------------------------------------

    def test_param_submission_auto_renames_if_name_edited(self):
        """If user edits the name and hits param Submit without hitting OK first, rename occurs."""
        splitter = Splitter()
        self.container.unit_operations.append(splitter)
        dock = DockWidgetSplitter(splitter.name, splitter.type, splitter, self.container)

        dock.le_name.setText("BranchSplitter")
        # Submit parameters without clicking OK
        dock.param()

        self.assertEqual(dock.name, "BranchSplitter")
        self.assertEqual(splitter.name, "BranchSplitter")


if __name__ == '__main__':
    unittest.main()
