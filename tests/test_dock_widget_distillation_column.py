import os
import sys
import unittest
from unittest.mock import MagicMock

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QTextBrowser, QGraphicsView
app = QApplication.instance() or QApplication([])

from python.utils.Container import Container
from python.utils.ComponentSelector import compound_selected
from python.utils.UnitOperations import DistillationColumn
from python.DockWidgets.DockWidgetDistillationColumn import DockWidgetDistillationColumn


class TestDockWidgetDistillationColumn(unittest.TestCase):
    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        DistillationColumn.counter = 1

        self.browser = QTextBrowser()
        self.view = QGraphicsView()
        self.container = Container(self.browser, self.view)

        self.dc = DistillationColumn()
        self.dc.name = "DistCol1"
        self.dc.variables['Ni']['value'] = 1
        self.dc.variables['InT_s']['value'] = [5]
        self.container.unit_operations.append(self.dc)

        self.widget = DockWidgetDistillationColumn(
            self.dc.name, "DistillationColumn", self.dc, self.container
        )

    def test_init_and_input_params_list(self):
        self.assertEqual(self.widget.windowTitle(), "DistCol1")
        self.assertEqual(self.widget.type, "DistillationColumn")
        # 1 (Nt) + 1 (feed tray) + 5 (condenser) + 4 (reboiler) + 1 (thermo) = 12 widgets
        self.assertEqual(len(self.widget.input_dict), 12)
        self.assertFalse(self.widget.cb2.isEnabled())
        self.assertFalse(self.widget.cb4.isEnabled())

    def test_fun2_fun3_and_update_compounds(self):
        # Enable cb2 when condenser spec requires a compound
        self.widget.cb1.setCurrentText("Compound Molar Fraction")
        self.assertTrue(self.widget.cb2.isEnabled())
        self.widget.cb1.setCurrentText("Reflux Ratio")
        self.assertFalse(self.widget.cb2.isEnabled())

        # Enable cb4 when reboiler spec requires a compound
        self.widget.cb3.setCurrentText("Compound Molar Fraction")
        self.assertTrue(self.widget.cb4.isEnabled())
        self.widget.cb3.setCurrentIndex(0)
        self.assertFalse(self.widget.cb4.isEnabled())

        # Update compounds list
        compound_selected.append("Methanol(chemsep)")
        self.dc.compounds = list(compound_selected)
        self.widget.update_compounds()
        self.assertEqual(self.widget.cb2.count(), 3)
        self.assertEqual(self.widget.cb4.count(), 3)

    def test_param_submit_valid_and_invalid(self):
        self.widget.input_dict[0].setText("10")   # Nt
        self.widget.input_dict[1].setText("5")    # Feed tray location
        self.widget.le5.setText("101325")         # Pcond
        self.widget.le6.setText("2")              # C_Spec value
        self.widget.le7.setText("101325")         # Preb
        self.widget.le8.setText("2")              # R_Spec value

        self.widget.show()
        self.widget.param()
        self.assertEqual(self.dc.variables['Nt']['value'], 10)
        self.assertFalse(self.widget.isVisible())

        # Invalid int triggers exception handler cleanly
        self.widget.input_dict[0].setText("bad_int")
        self.widget.param()

    def test_stagewise_results_show_and_clear(self):
        Nt = 4
        self.dc.variables['Nt']['value'] = Nt
        self.dc.compounds = ["Water(chemsep)", "Ethanol(chemsep)"]

        res_param = self.dc.result_parameters[0]
        names = [f"DistCol1.{res_param}"]
        vals = [1500.0]

        # Populate condenser, tray[1], tray[2], and reboiler T and x_pc[phase, comp]
        sections = ["condenser", "tray[1]", "tray[2]", "reboiler"]
        for idx, sec in enumerate(sections):
            names.append(f"DistCol1.{sec}.T")
            vals.append(350.0 + idx * 5.0)
            for comp in (1, 2):
                for phase in (1, 2, 3):
                    names.append(f"DistCol1.{sec}.x_pc[{phase},{comp}]")
                    vals.append(0.25 * comp)

        self.container.result = [names, vals]

        DockWidgetDistillationColumn.showResult([self.widget, object()])
        self.assertEqual(self.widget.tableWidget.rowCount(), 1)
        self.assertEqual(self.widget.stage_res_table.T_table.rowCount(), Nt)
        self.assertEqual(self.widget.stage_res_table.x_pc_table.rowCount(), Nt)
        self.assertEqual(self.widget.stage_res_table.x_pc_table.columnCount(), 4)

        self.widget.showStagewiseResults()
        self.assertTrue(self.widget.stage_res_table.isVisible())
        self.widget.stage_res_table.hide()

        self.widget.clear_results()
        self.assertEqual(self.widget.tableWidget.rowCount(), 0)
        self.assertEqual(self.widget.stage_res_table.T_table.rowCount(), 0)
        self.assertEqual(self.widget.stage_res_table.x_pc_table.rowCount(), 0)


if __name__ == '__main__':
    unittest.main()
