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
from python.utils.Graphics import NodeItem, ResizeHandle
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
    node._resize_handle = ResizeHandle(node)
    node._capture_socket_geometry()
    return node


def _center_y(socket):
    return socket.rect.y() + socket.rect.height() / 2


def _min_handle_socket_gap(node):
    hpos = node._resize_handle.pos()
    hsize = getattr(node._resize_handle, "_size", 12)
    hrect = QtCore.QRectF(hpos.x(), hpos.y(), hsize, hsize)
    min_gap = float("inf")
    for s in list(node.input) + list(node.output):
        srect = QtCore.QRectF(s.rect)
        if hrect.intersects(srect):
            return 0.0
        dx = max(0.0, max(srect.left() - hrect.right(), hrect.left() - srect.right()))
        dy = max(0.0, max(srect.top() - hrect.bottom(), hrect.top() - srect.bottom()))
        gap = (dx ** 2 + dy ** 2) ** 0.5
        min_gap = min(min_gap, gap)
    return min_gap


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

    def test_resize_handle_clearance_across_all_components(self):
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
            self.assertGreaterEqual(
                _min_handle_socket_gap(node), NodeItem.PORT_HANDLE_CLEARANCE,
                f"{op.type} resize handle is too close to a port at default size"
            )
            for socket in node.input + node.output:
                self.assertGreater(socket.zValue(), node._resize_handle.zValue())

            # Verify clearance is maintained after resizing
            node.resize_node(node.rect.width() + 30, node.rect.height() + 20)
            self.assertGreaterEqual(
                _min_handle_socket_gap(node), NodeItem.PORT_HANDLE_CLEARANCE,
                f"{op.type} resize handle is too close to a port after enlarging"
            )

        # Verify dynamic multi-port changes on Splitter (up to 6 outputs) and Mixer (up to 6 inputs)
        splitter_node = container.graphics.create_node_item(Splitter(), container)
        for out_count in range(2, 7):
            splitter_node.update_output_ports(out_count)
            self.assertGreaterEqual(
                _min_handle_socket_gap(splitter_node), NodeItem.PORT_HANDLE_CLEARANCE,
                f"Splitter with {out_count} outputs has resize handle too close to port"
            )


if __name__ == "__main__":
    unittest.main()
