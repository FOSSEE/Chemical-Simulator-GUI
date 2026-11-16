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
from python.utils.UnitOperations import AdiabaticCompressor, AdiabaticExpander
from python.utils.Container import Container
from python.DockWidgets.DockWidgetCompressorExpander import DockWidgetCompressorExpander


class TestDockWidgetCompressorExpander(unittest.TestCase):
    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        AdiabaticCompressor.counter = 1
        AdiabaticExpander.counter = 1

        self.browser = QTextBrowser()
        self.view = QGraphicsView()
        self.container = Container(self.browser, self.view)

        self.comp = AdiabaticCompressor()
        self.comp.name = "Comp_1"
        self.container.unit_operations.append(self.comp)
        self.widget = DockWidgetCompressorExpander(
            self.comp.name, "AdiabaticCompressor", self.comp, self.container
        )

    def test_modes_and_mode_selection(self):
        self.assertGreater(self.widget.comboBox.count(), 0)
        if self.widget.comboBox.count() > 1:
            self.widget.comboBox.setCurrentIndex(1)
            self.assertGreater(self.widget.formLayout.count(), 0)

        # Expander instantiation + empty modes_list branch
        exp = AdiabaticExpander()
        exp.name = "Exp_1"
        exp.modes_list = []
        exp_widget = DockWidgetCompressorExpander("Exp_1", "AdiabaticExpander", exp, self.container)
        self.assertFalse(exp_widget.comboBox.isEnabled())

    def test_param_submit_tooltip_update_and_empty_error(self):
        mock_node = MagicMock()
        mock_node.name = "Comp_1"
        with unittest.mock.patch.object(self.view, "items", return_value=[mock_node]):
            for key, field in self.widget.input_dict.items():
                if key != "Thermo Package" and field is not None:
                    field.setText("101325")
            self.widget.show()
            self.widget.param()
            mock_node.update_tooltip.assert_called_once()
            self.assertFalse(self.widget.isVisible())

        # Empty input triggers show_error() branch
        self.widget.show_error = MagicMock()
        for key, field in self.widget.input_dict.items():
            if key != "Thermo Package" and field is not None:
                field.setText("")
                break
        self.widget.param()
        self.widget.show_error.assert_called_once()

    def test_results_category_show_and_clear(self):
        var_key = next(iter(self.comp.variables.keys()))
        self.container.result = [
            [f"Comp_1.{var_key}"],
            [45.678],
        ]
        DockWidgetCompressorExpander.show_result([self.widget, object()])
        self.assertEqual(self.widget.tableWidget.rowCount(), 1)

        self.widget.clear_results()
        self.assertEqual(self.widget.tableWidget.rowCount(), 0)


if __name__ == '__main__':
    unittest.main()

