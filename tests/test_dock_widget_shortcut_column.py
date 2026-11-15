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
from python.utils.UnitOperations import ShortcutColumn
from python.utils.Container import Container
from python.DockWidgets.DockWidgetShortcutColumn import DockWidgetShortcutColumn


class TestDockWidgetShortcutColumn(unittest.TestCase):
    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)", "Methanol(chemsep)"])
        ShortcutColumn.counter = 1

        self.browser = QTextBrowser()
        self.view = QGraphicsView()
        self.container = Container(self.browser, self.view)

        self.sc = ShortcutColumn()
        self.sc.name = "SC_1"
        self.container.unit_operations.append(self.sc)
        self.widget = DockWidgetShortcutColumn(self.sc.name, "ShortcutColumn", self.sc, self.container)

    def test_init_and_input_params_list(self):
        self.assertEqual(self.widget.windowTitle(), "SC_1")
        self.assertEqual(len(self.widget.input_dict), 9)
        self.assertEqual(self.widget.cb1.count(), 3)
        self.assertEqual(self.widget.cb5.count(), 2)
        self.assertGreater(self.widget.cb6.count(), 0)

    def test_update_compounds(self):
        compound_selected.append("Acetone(chemsep)")
        self.sc.compounds = list(compound_selected)
        self.widget.update_compounds()
        self.assertEqual(self.widget.cb1.count(), 4)
        self.assertEqual(self.widget.cb2.count(), 4)

    def test_param_submit_valid_and_invalid(self):
        self.widget.le3.setText("0.02")
        self.widget.le4.setText("0.98")
        self.widget.le6.setText("101325")
        self.widget.le7.setText("101325")
        self.widget.le8.setText("1.5")

        self.widget.show()
        self.widget.param()
        self.assertEqual(self.sc.variables['RR']['value'], 1.5)
        self.assertFalse(self.widget.isVisible())

        # Invalid float triggers exception handler cleanly
        self.widget.le8.setText("not_a_number")
        self.widget.param()

    def test_results_category_populates_table(self):
        param_key = self.sc.result_parameters[0]
        self.container.result = [
            [f"SC_1.{param_key}"],
            [12.3456],
        ]
        self.widget.results_category("SC_1")
        self.assertEqual(self.widget.tableWidget.rowCount(), 1)
        self.assertEqual(self.sc.variables[param_key]['value'], 12.3456)

        # Exception branch when result is None
        self.container.result = None
        self.widget.results_category("SC_1")


if __name__ == '__main__':
    unittest.main()
