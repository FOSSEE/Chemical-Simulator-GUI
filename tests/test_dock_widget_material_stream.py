import os
import sys
import unittest
from unittest.mock import MagicMock

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

# Break circular import between Graphics and Container
mock_graphics = MagicMock()
mock_container = MagicMock()
sys.modules['utils.Graphics'] = mock_graphics
sys.modules['python.utils.Graphics'] = mock_graphics
sys.modules['utils.Container'] = mock_container
sys.modules['python.utils.Container'] = mock_container

from PyQt5.QtWidgets import QApplication, QTableWidget
from DockWidgets.DockWidgetMaterialStream import DockWidgetMaterialStream

app = QApplication.instance()
if app is None:
    app = QApplication([])


class TestDockWidgetMaterialStreamAmountsTable(unittest.TestCase):
    """Unit tests for dynamic column and unit display in Material Stream Amounts tables."""

    def setUp(self):
        self.table = QTableWidget()

    def tearDown(self):
        self.table.clear()

    def test_populate_amounts_table_mole_fraction_two_columns(self):
        """Verify that Mole Fraction produces 2 columns without Unit."""
        rows = [("Water(chemsep)", 0.5), ("Ethanol(chemsep)", 0.5)]
        DockWidgetMaterialStream._populate_amounts_table(self.table, rows, "Mole Fraction")

        self.assertEqual(self.table.columnCount(), 2)
        self.assertEqual(self.table.rowCount(), 2)
        self.assertEqual(self.table.horizontalHeaderItem(0).text(), "Compound")
        self.assertEqual(self.table.horizontalHeaderItem(1).text(), "Value")

        self.assertEqual(self.table.item(0, 0).text(), "Water(chemsep)")
        self.assertEqual(self.table.item(0, 1).text(), "0.5")
        self.assertIsNone(self.table.item(0, 2))

    def test_populate_amounts_table_mass_fraction_two_columns(self):
        """Verify that Mass Fraction produces 2 columns without Unit."""
        rows = [("Water(chemsep)", 0.2811), ("Ethanol(chemsep)", 0.7189)]
        DockWidgetMaterialStream._populate_amounts_table(self.table, rows, "Mass Fraction")

        self.assertEqual(self.table.columnCount(), 2)
        self.assertEqual(self.table.rowCount(), 2)
        self.assertEqual(self.table.horizontalHeaderItem(0).text(), "Compound")
        self.assertEqual(self.table.horizontalHeaderItem(1).text(), "Value")

    def test_populate_amounts_table_mole_flow_three_columns_with_unit(self):
        """Verify that Mole Flow produces 3 columns including the Unit column."""
        rows = [("Water(chemsep)", 50.0, "mol/s"), ("Ethanol(chemsep)", 50.0, "mol/s")]
        DockWidgetMaterialStream._populate_amounts_table(self.table, rows, "Mole Flow")

        self.assertEqual(self.table.columnCount(), 3)
        self.assertEqual(self.table.rowCount(), 2)
        self.assertEqual(self.table.horizontalHeaderItem(0).text(), "Compound")
        self.assertEqual(self.table.horizontalHeaderItem(1).text(), "Value")
        self.assertEqual(self.table.horizontalHeaderItem(2).text(), "Unit")

        self.assertEqual(self.table.item(0, 0).text(), "Water(chemsep)")
        self.assertEqual(self.table.item(0, 1).text(), "50.0")
        self.assertEqual(self.table.item(0, 2).text(), "mol/s")

    def test_populate_amounts_table_mass_flow_three_columns_with_unit(self):
        """Verify that Mass Flow produces 3 columns including the Unit column."""
        rows = [("Water(chemsep)", 900.75, "g/s"), ("Ethanol(chemsep)", 2303.45, "g/s")]
        DockWidgetMaterialStream._populate_amounts_table(self.table, rows, "Mass Flow")

        self.assertEqual(self.table.columnCount(), 3)
        self.assertEqual(self.table.rowCount(), 2)
        self.assertEqual(self.table.horizontalHeaderItem(0).text(), "Compound")
        self.assertEqual(self.table.horizontalHeaderItem(1).text(), "Value")
        self.assertEqual(self.table.horizontalHeaderItem(2).text(), "Unit")

        self.assertEqual(self.table.item(0, 2).text(), "g/s")
        self.assertEqual(self.table.item(1, 2).text(), "g/s")

    def test_dynamic_switching_resets_columns(self):
        """Verify switching from 3 columns (Mole Flow) to 2 columns (Mole Fraction) resets columns."""
        flow_rows = [("Water(chemsep)", 50.0, "mol/s")]
        DockWidgetMaterialStream._populate_amounts_table(self.table, flow_rows, "Mole Flow")
        self.assertEqual(self.table.columnCount(), 3)

        fraction_rows = [("Water(chemsep)", 1.0)]
        DockWidgetMaterialStream._populate_amounts_table(self.table, fraction_rows, "Mole Fraction")
        self.assertEqual(self.table.columnCount(), 2)
        self.assertEqual(self.table.horizontalHeaderItem(1).text(), "Value")


if __name__ == "__main__":
    unittest.main()