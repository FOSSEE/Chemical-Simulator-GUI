import os
import sys
import unittest
from unittest.mock import MagicMock, patch

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QTableWidget, QTextBrowser, QGraphicsView
app = QApplication.instance() or QApplication([])

from python.utils.Container import Container
from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.DockWidgets.DockWidgetMaterialStream import DockWidgetMaterialStream


class TestDockWidgetMaterialStreamAmountsTable(unittest.TestCase):
    """Unit tests for dynamic column and unit display in Material Stream Amounts tables."""

    def setUp(self):
        self.table = QTableWidget()

    def tearDown(self):
        self.table.clear()

    def test_populate_amounts_table_mole_fraction_two_columns(self):
        rows = [("Water(chemsep)", 0.5), ("Ethanol(chemsep)", 0.5)]
        DockWidgetMaterialStream._populate_amounts_table(self.table, rows, "Mole Fraction")

        self.assertEqual(self.table.columnCount(), 2)
        self.assertEqual(self.table.rowCount(), 2)
        self.assertEqual(self.table.horizontalHeaderItem(0).text(), "Compound")
        self.assertEqual(self.table.horizontalHeaderItem(1).text(), "Value")
        self.assertEqual(self.table.item(0, 0).text(), "Water(chemsep)")
        self.assertEqual(self.table.item(0, 1).text(), "0.50")
        self.assertIsNone(self.table.item(0, 2))

    def test_populate_amounts_table_mass_fraction_two_columns(self):
        rows = [("Water(chemsep)", 0.2811), ("Ethanol(chemsep)", 0.7189)]
        DockWidgetMaterialStream._populate_amounts_table(self.table, rows, "Mass Fraction")

        self.assertEqual(self.table.columnCount(), 2)
        self.assertEqual(self.table.rowCount(), 2)
        self.assertEqual(self.table.horizontalHeaderItem(0).text(), "Compound")
        self.assertEqual(self.table.horizontalHeaderItem(1).text(), "Value")

    def test_populate_amounts_table_mole_flow_three_columns_with_unit(self):
        rows = [("Water(chemsep)", 50.0, "mol/s"), ("Ethanol(chemsep)", 50.0, "mol/s")]
        DockWidgetMaterialStream._populate_amounts_table(self.table, rows, "Mole Flow")

        self.assertEqual(self.table.columnCount(), 3)
        self.assertEqual(self.table.rowCount(), 2)
        self.assertEqual(self.table.horizontalHeaderItem(0).text(), "Compound")
        self.assertEqual(self.table.horizontalHeaderItem(1).text(), "Value")
        self.assertEqual(self.table.horizontalHeaderItem(2).text(), "Unit")
        self.assertEqual(self.table.item(0, 0).text(), "Water(chemsep)")
        self.assertEqual(self.table.item(0, 1).text(), "50.00")
        self.assertEqual(self.table.item(0, 2).text(), "mol/s")

    def test_populate_amounts_table_mass_flow_three_columns_with_unit(self):
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
        flow_rows = [("Water(chemsep)", 50.0, "mol/s")]
        DockWidgetMaterialStream._populate_amounts_table(self.table, flow_rows, "Mole Flow")
        self.assertEqual(self.table.columnCount(), 3)

        fraction_rows = [("Water(chemsep)", 1.0)]
        DockWidgetMaterialStream._populate_amounts_table(self.table, fraction_rows, "Mole Fraction")
        self.assertEqual(self.table.columnCount(), 2)
        self.assertEqual(self.table.horizontalHeaderItem(1).text(), "Value")


class TestDockWidgetMaterialStreamWidget(unittest.TestCase):
    """Comprehensive tests for DockWidgetMaterialStream UI lifecycle, inputs, and results."""

    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        MaterialStream.counter = 1

        self.browser = QTextBrowser()
        self.view = QGraphicsView()
        self.container = Container(self.browser, self.view)

        self.ms = MaterialStream()
        self.ms.name = "MS_1"
        self.ms.init_variables()
        for comp in compound_selected:
            self.ms.variables.setdefault(comp, {'value': 0.5})
        self.container.unit_operations.append(self.ms)
        self.widget = DockWidgetMaterialStream(self.ms.name, "MaterialStream", self.ms, self.container)

    def test_init_modes_and_autosize(self):
        self.assertEqual(self.widget.windowTitle(), "MS_1")
        self.assertGreater(self.widget.comboBox.count(), 0)
        self.assertEqual(len(self.widget.x_pclist), 2)

        if self.widget.comboBox.count() > 1:
            self.widget.comboBox.setCurrentIndex(1)
            self.widget.comboBox.setCurrentIndex(0)

        self.widget._has_autosized = False
        self.widget._autosize()
        self.assertTrue(self.widget._has_autosized)
        self.widget._autosize()

    def test_equalize_normalize_and_update_compounds(self):
        self.widget.equalize()
        self.assertEqual(self.widget.x_pclist[0].text(), "0.5")
        self.assertEqual(self.widget.x_pclist[1].text(), "0.5")

        self.widget.x_pclist[0].setText("3")
        self.widget.x_pclist[1].setText("1")
        self.widget.normalize()
        self.assertEqual(self.widget.x_pclist[0].text(), "0.75")
        self.assertEqual(self.widget.x_pclist[1].text(), "0.25")

        self.widget.show_error = MagicMock()
        self.widget.x_pclist[0].setText("0")
        self.widget.x_pclist[1].setText("bad")
        self.widget.normalize()
        self.widget.show_error.assert_called_once()

        compound_selected.append("Methanol(chemsep)")
        self.widget.update_compounds()
        self.assertEqual(len(self.widget.x_pclist), 3)

    def test_param_submit_valid_and_empty_error(self):
        self.widget.x_pclist[0].setText("0.4")
        self.widget.x_pclist[1].setText("0.6")
        for key, widget_item in self.widget.input_dict.items():
            if key not in ("x_pc", "Thermo Package") and hasattr(widget_item, "setText"):
                if not widget_item.text():
                    widget_item.setText("300")

        mock_node = MagicMock()
        mock_node.name = "MS_1"
        with patch.object(self.view, "items", return_value=[mock_node]):
            self.widget.show()
            self.widget.param()
            mock_node.update_tooltip.assert_called_once()
            self.assertFalse(self.widget.isVisible())

        self.widget.show_error = MagicMock()
        self.widget.x_pclist[0].setText("")
        self.widget.param()
        self.widget.show_error.assert_called()

    def test_results_category_show_and_clear(self):
        names = []
        vals = []

        for base_var in ("x_pc", "xm_pc", "F_pc", "Fm_pc"):
            for phase in (1, 2, 3):
                for comp in (1, 2):
                    vkey = f"{base_var}[{phase},{comp}]"
                    self.ms.variables.setdefault(vkey, {'value': 0.0, 'unit': ''})
                    names.append(f"MS_1.{vkey}")
                    vals.append(0.5 if "pc" in base_var and "F" not in base_var else 25.0)

        extra_vars = [
            ("P", 101325.0), ("T", 350.0), ("xvap", 0.4),
            ("Cp_p[1]", 75.0), ("Cp_p[2]", 76.0), ("Cp_p[3]", 35.0),
            ("Pvap_c[1]", 42000.0), ("Pvap_c[2]", 98000.0),
        ]
        for vkey, val in extra_vars:
            self.ms.variables.setdefault(vkey, {'name': vkey, 'value': 0.0, 'unit': ''})
            names.append(f"MS_1.{vkey}")
            vals.append(val)

        self.container.result = [names, vals]

        DockWidgetMaterialStream.show_result([self.widget])
        self.assertEqual(self.widget.amountsMixtureTable.rowCount(), 2)
        self.assertGreater(self.widget.mTableWidget.rowCount(), 0)
        self.assertGreater(self.widget.lTableWidget.rowCount(), 0)
        self.assertGreater(self.widget.vTableWidget.rowCount(), 0)

        self.widget.cbCompositionBasis.setCurrentText("Mole Flow")
        self.assertEqual(self.widget.amountsMixtureTable.columnCount(), 3)

        self.widget.clear_results()
        self.assertEqual(self.widget.amountsMixtureTable.rowCount(), 0)
        self.assertEqual(self.widget.mTableWidget.rowCount(), 0)


if __name__ == "__main__":
    unittest.main()