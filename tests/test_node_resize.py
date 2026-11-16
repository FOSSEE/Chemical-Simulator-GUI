import os
import sys
import unittest
from unittest.mock import MagicMock

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5 import QtCore, QtWidgets

import python.utils.Container  # noqa: F401 (imports Graphics without the circular import error)
from python.utils.Container import Container
from python.utils.ComponentSelector import compound_selected
from python.utils.Graphics import NodeItem
from python.utils.Streams import MaterialStream
from python.utils.UnitOperations import (
    Mixer, Splitter, Flash, CompoundSeparator, AdiabaticCompressor,
    AdiabaticExpander, Valve, Cooler, Heater, CentrifugalPump,
    DistillationColumn, ShortcutColumn
)


class _MixerObj:
    type = "Mixer"
    name = "M1"
    no_of_inputs = 2
    no_of_outputs = 1
    variables = {"NI": {"value": 2}}


def _make_mixer_node(size=80):
    # Bypass NodeItem.__init__, which needs a main window and dock widgets.
    node = NodeItem.__new__(NodeItem)
    QtWidgets.QGraphicsItem.__init__(node)
    node.obj = _MixerObj()
    node.type = "Mixer"
    node.nin = 2
    node.nop = 1
    node.rect = QtCore.QRect(0, 0, size, size)
    node.input, node.output = node.initialize_sockets(node.type)
    node._orig_pic = MagicMock()
    node.text = QtWidgets.QGraphicsTextItem(node)
    node._resize_handle = QtWidgets.QGraphicsRectItem(node)
    node._capture_socket_geometry()
    return node


def _center_y(socket):
    return socket.rect.y() + socket.rect.height() / 2


class TestNodeResizePorts(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.app = QtWidgets.QApplication.instance() or QtWidgets.QApplication([])

    def test_resize_keeps_ports_on_component_edges(self):
        node = _make_mixer_node(80)
        before = [_center_y(s) / 80 for s in node.input + node.output]

        node.resize_node(160, 120)

        after = [_center_y(s) / 120 for s in node.input + node.output]
        for b, a in zip(before, after):
            self.assertAlmostEqual(b, a, places=2)
        self.assertEqual(node.input[0].rect.x(), -6)
        self.assertEqual(node.output[0].rect.x(), 160 - 7)

    def test_resize_after_port_count_change_keeps_ports_inside(self):
        node = _make_mixer_node(80)
        node.resize_node(160, 160)
        node.update_input_ports(3)
        node.update_output_ports(2)

        node.resize_node(80, 80)

        self.assertEqual([_center_y(s) for s in node.input], [20, 40, 60])
        for socket in node.output:
            self.assertEqual(socket.rect.x(), 80 - 7)
            self.assertTrue(0 < _center_y(socket) < 80)

    def test_resize_and_dynamic_ports_across_components(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        browser = QtWidgets.QTextBrowser()
        view = QtWidgets.QGraphicsView()
        container = Container(browser, view)

        components = [
            MaterialStream(), Mixer(), Splitter(), Flash(), CompoundSeparator(),
            AdiabaticCompressor(), AdiabaticExpander(), Valve(), Cooler(),
            Heater(), CentrifugalPump(), DistillationColumn(), ShortcutColumn()
        ]

        for op in components:
            node = container.graphics.create_node_item(op, container)
            orig_w, orig_h = node.rect.width(), node.rect.height()
            node.resize_node(orig_w + 30, orig_h + 20)
            self.assertEqual(node.rect.width(), orig_w + 30)
            self.assertEqual(node.rect.height(), orig_h + 20)
            self.assertEqual(node._resize_handle.pos(), QtCore.QPointF(orig_w + 30 - 12, orig_h + 20 - 12))

        splitter_node = container.graphics.create_node_item(Splitter(), container)
        for out_count in range(2, 7):
            splitter_node.update_output_ports(out_count)
            self.assertEqual(len(splitter_node.output), out_count)


if __name__ == "__main__":
    unittest.main()
