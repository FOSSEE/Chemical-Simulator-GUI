import os
import sys
import unittest
from unittest.mock import patch

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication

from python.utils import ComponentSelector as component_selector_module
from python.utils.ComponentSelector import ComponentSelector, CompoundLoader, compound_selected


SAMPLE_COMPOUNDS = [
    {"Name": "Water", "CAS": "7732-18-5", "Formula": "H2O", "MW": "18.015"},
    {"Name": "Ethanol", "CAS": "64-17-5", "Formula": "C2H6O", "MW": "46.069"},
    {"Name": "Acetone", "CAS": "67-64-1", "Formula": "C3H6O", "MW": "58.08"},
]


class _SignalStub:
    def connect(self, callback):
        self.callback = callback


class _LoaderStub:
    def __init__(self, instance_list):
        self.instance_list = instance_list
        self.data_loaded = _SignalStub()

    def start(self):
        pass


class _ChemsepDatabaseStub:
    pass


class _FakeChemsepDatabase:
    name = "chemsep"

    def get_comp_name_list(self):
        return ["Water(chemsep)", "Ethanol(chemsep)"]

    def get_value(self, compound_name, field):
        values = {
            ("Water", "CAS"): "7732-18-5",
            ("Water", "StructureFormula"): "H2O",
            ("Water", "MolecularWeight"): "18.015",
            ("Ethanol", "CAS"): "64-17-5",
            ("Ethanol", "StructureFormula"): "C2H6O",
            ("Ethanol", "MolecularWeight"): "46.069",
        }
        return values[(compound_name, field)]


class TestComponentSelector(unittest.TestCase):
    """Unit tests for compound selection, filtering, and global selection storage."""

    @classmethod
    def setUpClass(cls):
        cls.app = QApplication.instance() or QApplication([])

    def setUp(self):
        compound_selected.clear()
        self.loader_patch = patch.object(component_selector_module, "CompoundLoader", _LoaderStub)
        self.database_patch = patch.object(component_selector_module, "ChemsepDatabase", _ChemsepDatabaseStub)
        self.loader_patch.start()
        self.database_patch.start()
        self.selector = ComponentSelector()
        self.selector.on_data_loaded(list(SAMPLE_COMPOUNDS))

    def tearDown(self):
        self.selector.close()
        self.selector.deleteLater()
        QApplication.processEvents()
        self.loader_patch.stop()
        self.database_patch.stop()
        compound_selected.clear()

    def test_data_loaded_populates_table_and_compound_map(self):
        self.assertEqual(self.selector.tableWidget.rowCount(), 3)
        self.assertEqual(self.selector.tableWidget.columnCount(), 5)
        self.assertEqual(self.selector.tableWidget.item(0, 1).text(), "Water")
        self.assertEqual(self.selector.compound_map["Ethanol"]["CAS"], "64-17-5")
        self.assertEqual(self.selector.filtered_data, SAMPLE_COMPOUNDS)

    def test_filter_table_matches_name_cas_and_formula(self):
        self.selector.lineEdit.setText("eth")
        self.selector.filter_table()
        self.assertEqual([c["Name"] for c in self.selector.filtered_data], ["Ethanol"])
        self.assertEqual(self.selector.tableWidget.rowCount(), 1)

        self.selector.lineEdit.setText("67-64")
        self.selector.filter_table()
        self.assertEqual([c["Name"] for c in self.selector.filtered_data], ["Acetone"])

        self.selector.lineEdit.setText("h2o")
        self.selector.filter_table()
        self.assertEqual([c["Name"] for c in self.selector.filtered_data], ["Water"])

    def test_checkbox_state_adds_and_removes_unique_selected_names(self):
        emissions = []
        self.selector.compounds_changed.connect(lambda: emissions.append("changed"))

        self.selector.on_checkbox_state_changed("Water", Qt.Checked)
        self.selector.on_checkbox_state_changed("Water", Qt.Checked)
        self.assertEqual(self.selector.selected_names_list, ["Water"])
        self.assertEqual(self.selector.selected_names_set, {"Water"})
        self.assertEqual(self.selector.added_lineedit.text(), "Water")

        self.selector.on_checkbox_state_changed("Water", Qt.Unchecked)
        self.assertEqual(self.selector.selected_names_list, [])
        self.assertEqual(self.selector.selected_names_set, set())
        self.assertEqual(self.selector.added_lineedit.text(), "")
        self.assertEqual(len(emissions), 3)

    def test_set_compounds_syncs_known_names_and_ignores_unknown_names(self):
        self.selector.set_compounds(["Water", "Missing", "Acetone"])

        self.assertEqual(self.selector.selected_names_list, ["Water", "Acetone"])
        self.assertEqual(self.selector.selected_names_set, {"Water", "Acetone"})
        self.assertEqual(self.selector.added_lineedit.text(), "Water, Acetone")

    def test_sync_state_reads_global_compound_selection_without_database_suffix(self):
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)", "Unknown(chemsep)"])

        self.selector.sync_state()

        self.assertEqual(self.selector.selected_names_list, ["Water", "Ethanol"])
        self.assertEqual(self.selector.selected_names_set, {"Water", "Ethanol"})

    def test_get_selected_compounds_returns_metadata_for_selected_names(self):
        self.selector.selected_names_list = ["Ethanol", "Missing", "Water"]

        selected = self.selector.get_selected_compounds()

        self.assertEqual(selected, [
            {"Name": "Ethanol", "CAS": "64-17-5", "Formula": "C2H6O", "MW": "46.069"},
            {"Name": "Water", "CAS": "7732-18-5", "Formula": "H2O", "MW": "18.015"},
        ])

    def test_accept_writes_selected_names_to_global_storage_with_database_suffix(self):
        self.selector.selected_names_list = ["Water", "Acetone"]

        self.selector.accept()

        self.assertEqual(compound_selected, ["Water(chemsep)", "Acetone(chemsep)"])
        self.assertEqual(self.selector.get_compounds(), compound_selected)
        self.assertTrue(self.selector.is_compound_selected())


class TestCompoundLoader(unittest.TestCase):
    """Unit tests for converting database records into selector table rows."""

    @classmethod
    def setUpClass(cls):
        cls.app = QApplication.instance() or QApplication([])

    def test_loader_emits_clean_compound_metadata(self):
        received = []
        loader = CompoundLoader([_FakeChemsepDatabase()])
        loader.data_loaded.connect(received.append)

        loader.run()

        self.assertEqual(received, [[
            {"Name": "Water", "CAS": "7732-18-5", "Formula": "H2O", "MW": "18.015"},
            {"Name": "Ethanol", "CAS": "64-17-5", "Formula": "C2H6O", "MW": "46.069"},
        ]])


if __name__ == "__main__":
    unittest.main()
