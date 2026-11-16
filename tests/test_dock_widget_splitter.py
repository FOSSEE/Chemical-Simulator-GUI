import os
import sys
import unittest
from unittest.mock import MagicMock, patch

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QTextBrowser, QGraphicsView, QMessageBox
app = QApplication.instance() or QApplication([])

from python.utils.Container import Container
from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.utils.UnitOperations import Splitter
from python.DockWidgets.DockWidgetSplitter import DockWidgetSplitter


class TestDockWidgetSplitter(unittest.TestCase):
    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        Splitter.counter = 1
        MaterialStream.counter = 1

        self.browser = QTextBrowser()
        self.view = QGraphicsView()
        self.container = Container(self.browser, self.view)
        self.view.setScene(self.container.graphics.scene)

        self.splitter = Splitter()
        self.splitter.name = "Splitter1"
        self.container.unit_operations.append(self.splitter)
        self.widget = DockWidgetSplitter(
            self.splitter.name, "Splitter", self.splitter, self.container
        )

    def _build_connected_node(self):
        """Attach an inlet MaterialStream and 2 outlet MaterialStreams on the graphics scene."""
        in_ms = MaterialStream()
        in_ms.name = "InMS"
        in_ms.variables['F_p[1]'] = {'value': 100.0}
        in_ms.variables['Fm_p[1]'] = {'value': 1800.0}

        out1 = MaterialStream()
        out1.name = "OutMS1"
        out2 = MaterialStream()
        out2.name = "OutMS2"

        node_splitter = self.container.graphics.create_node_item(self.splitter, self.container)
        self.container.graphics.scene.addItem(node_splitter)

        # Mock connected input line
        in_line = MagicMock()
        in_line.source.parent.obj = in_ms
        node_splitter.input[0].in_lines = [in_line]

        # Mock connected output lines
        out_line1 = MagicMock()
        out_line1.target.parent.obj = out1
        node_splitter.output[0].out_lines = [out_line1]

        out_line2 = MagicMock()
        out_line2.target.parent.obj = out2
        node_splitter.output[1].out_lines = [out_line2]

        return node_splitter

    def test_init_and_rebuild_stream_fields(self):
        self.assertEqual(self.widget.windowTitle(), "Splitter1")
        self.assertEqual(len(self.widget.stream_edits), 2)
        self.assertEqual(self.widget.get_stream_unit(), "")

        # Change output count to 3 -> rebuilds fields and defaults to 1/3 each
        self.widget.no_combo.setCurrentText("3")
        self.assertEqual(len(self.widget.stream_edits), 3)
        self.assertAlmostEqual(
            sum(float(e.text()) for e in self.widget.stream_edits), 1.0, places=5
        )

    def test_calc_type_switching_and_units(self):
        self.widget.cb2.setCurrentText("Molar_Flow")
        self.assertEqual(self.widget.get_stream_unit(), "mol/s")
        self.assertTrue(all(u.text() == "mol/s" for u in self.widget.stream_units))

        self.widget.cb2.setCurrentText("Mass_Flow")
        self.assertEqual(self.widget.get_stream_unit(), "g/s")
        self.assertTrue(all(u.text() == "g/s" for u in self.widget.stream_units))

        self.widget.cb2.setCurrentText("Split_Ratio")
        self.assertEqual(self.widget.get_stream_unit(), "")

    def test_equalize_and_normalize_split_ratio_and_flows(self):
        # Split_Ratio equalize & normalize
        self.widget.equalize_streams()
        self.assertAlmostEqual(float(self.widget.stream_edits[0].text()), 0.5, places=5)

        self.widget.stream_edits[0].setText("3.0")
        self.widget.stream_edits[1].setText("1.0")
        self.widget.normalize_streams()
        self.assertAlmostEqual(float(self.widget.stream_edits[0].text()), 0.75, places=5)
        self.assertAlmostEqual(float(self.widget.stream_edits[1].text()), 0.25, places=5)

        # Zero values warning in normalize_streams
        with patch.object(QMessageBox, "warning") as mock_warn:
            self.widget.stream_edits[0].setText("0")
            self.widget.stream_edits[1].setText("0")
            self.widget.normalize_streams()
            mock_warn.assert_called_once()

        # Molar_Flow with missing inlet -> warning
        self.widget.cb2.setCurrentText("Molar_Flow")
        with patch.object(QMessageBox, "warning") as mock_warn:
            self.widget.equalize_streams()
            mock_warn.assert_called_once()

        with patch.object(QMessageBox, "warning") as mock_warn:
            self.widget.stream_edits[0].setText("20")
            self.widget.stream_edits[1].setText("30")
            self.widget.normalize_streams()
            mock_warn.assert_called_once()

        # Connect inlet stream -> Molar_Flow & Mass_Flow equalize, normalize, auto_distribute
        self._build_connected_node()
        self.assertEqual(self.widget.get_input_flow("Molar_Flow"), 100.0)
        self.assertEqual(self.widget.get_input_flow("Mass_Flow"), 1800.0)

        self.widget.equalize_streams()
        self.assertAlmostEqual(float(self.widget.stream_edits[0].text()), 50.0, places=4)

        self.widget.stream_edits[0].setText("10")
        self.widget.stream_edits[1].setText("30")
        self.widget.normalize_streams()
        self.assertAlmostEqual(float(self.widget.stream_edits[0].text()), 25.0, places=4)
        self.assertAlmostEqual(float(self.widget.stream_edits[1].text()), 75.0, places=4)

        self.widget.auto_distribute_from_input()
        self.assertAlmostEqual(float(self.widget.stream_edits[0].text()), 50.0, places=4)

    def test_param_submit_validation_and_connected_names(self):
        node_splitter = self._build_connected_node()
        self.widget.update_connected_component_names()
        self.assertEqual(self.widget.stream_names[0].text(), "OutMS1")
        self.assertEqual(self.widget.stream_names[1].text(), "OutMS2")

        # Autosize check
        self.widget._has_autosized = False
        self.widget._autosize()
        self.assertTrue(self.widget._has_autosized)

        with patch.object(QMessageBox, "warning") as mock_warn:
            # Empty input
            self.widget.stream_edits[0].setText("")
            self.widget.param()
            # Negative input
            self.widget.stream_edits[0].setText("-0.2")
            self.widget.param()
            # Split ratios not summing to 1.0
            self.widget.stream_edits[0].setText("0.3")
            self.widget.stream_edits[1].setText("0.3")
            self.widget.param()
            # Invalid non-numeric input -> ValueError
            self.widget.stream_edits[0].setText("abc")
            self.widget.param()
            self.assertEqual(mock_warn.call_count, 4)

        # Valid Split_Ratio submission
        self.widget.stream_edits[0].setText("0.6")
        self.widget.stream_edits[1].setText("0.4")
        self.widget.show()
        self.widget.param()
        self.assertFalse(self.widget.isVisible())
        self.assertEqual(len(node_splitter.output), 2)

        # Valid Molar_Flow submission (including auto-split when both 0, and mismatch warning)
        self.widget.cb2.setCurrentText("Molar_Flow")
        with patch.object(QMessageBox, "warning") as mock_warn:
            self.widget.stream_edits[0].setText("10")
            self.widget.stream_edits[1].setText("10")
            self.widget.param()
            mock_warn.assert_called_once()

        self.widget.stream_edits[0].setText("0")
        self.widget.stream_edits[1].setText("0")
        self.widget.param()


if __name__ == '__main__':
    unittest.main()