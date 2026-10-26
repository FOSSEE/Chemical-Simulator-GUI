import os
import sys
import unittest
from unittest.mock import MagicMock

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QTextBrowser, QGraphicsView
from PyQt5.QtCore import QPointF, Qt

app = QApplication.instance() or QApplication([])

from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.utils.UnitOperations import Mixer, Splitter, Heater
from python.DockWidgets.DockWidget import DockWidget, BaseDockWidget
from python.DockWidgets.DockWidgetMaterialStream import DockWidgetMaterialStream
from python.DockWidgets.DockWidgetMixer import DockWidgetMixer
from python.DockWidgets.DockWidgetSplitter import DockWidgetSplitter
from python.DockWidgets.DockWidgetFlash import DockWidgetFlash
from python.DockWidgets.DockWidgetCompoundSeparator import DockWidgetCompoundSeparator
from python.DockWidgets.DockWidgetShortcutColumn import DockWidgetShortcutColumn
from python.DockWidgets.DockWidgetDistillationColumn import DockWidgetDistillationColumn
from python.DockWidgets.DockWidgetCompressorExpander import DockWidgetCompressorExpander
from python.utils import undo_manager
from python.utils.Graphics import (
    Graphics, NodeItem, NodeSocket, NodeLine, ResizeHandle,
    lst, dock_widget_lst, get_svg_renderer
)
from python.utils.Container import Container


class MockEvent:
    def __init__(self, pos=None, scenePos=None, button=Qt.LeftButton):
        self._pos = pos or QPointF(0, 0)
        self._scenePos = scenePos or QPointF(0, 0)
        self._button = button

    def pos(self):
        return self._pos

    def scenePos(self):
        return self._scenePos

    def button(self):
        return self._button

    def buttons(self):
        return self._button

    def accept(self):
        pass

    def ignore(self):
        pass


class TestGraphicsAndNodes(unittest.TestCase):
    """Unit tests for Graphics canvas, NodeItem rendering, sockets, lines, and resizing."""

    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        lst.clear()
        dock_widget_lst.clear()
        Mixer.counter = 1
        Splitter.counter = 1
        Heater.counter = 1
        MaterialStream.counter = 1

        self.browser = QTextBrowser()
        self.view = QGraphicsView()
        self.container = Container(self.browser, self.view)
        self.graphics = self.container.graphics
        self.scene = self.graphics.scene

        undo_manager.clean_file("Undo")
        undo_manager.clean_file("Redo")

    def tearDown(self):
        lst.clear()
        dock_widget_lst.clear()
        undo_manager.clean_file("Undo")
        undo_manager.clean_file("Redo")
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

    def test_graphics_initialization(self):
        """Verify Graphics canvas setup with Container and Scene."""
        self.assertIs(self.graphics.container, self.container)
        self.assertIs(self.graphics.graphicsView, self.view)
        self.assertIs(self.graphics.get_scene(), self.scene)

    def test_node_item_creation_and_sockets(self):
        """Verify NodeItem initializes input/output sockets, text label, and dock widget."""
        mixer = Mixer()
        mixer.name = "Mixer_1"
        node = NodeItem(mixer, self.container, self.view)
        self.scene.addItem(node)

        self.assertEqual(node.name, "Mixer_1")
        self.assertEqual(node.type, "Mixer")
        self.assertEqual(len(node.input), 2)
        self.assertEqual(len(node.output), 1)
        self.assertEqual(node.text.toPlainText(), "Mixer_1")
        self.assertIsNotNone(node.dock_widget)
        self.assertIn(node, lst)

    def test_node_socket_properties_and_shape(self):
        """Verify NodeSocket bounding rect, type, and shape."""
        mixer = Mixer()
        mixer.name = "Mixer_Test"
        node = NodeItem(mixer, self.container, self.view)

        socket = node.input[0]
        self.assertEqual(socket.type, 'in')
        self.assertEqual(socket.id, 1)
        self.assertFalse(socket.boundingRect().isEmpty())
        self.assertFalse(socket.shape().isEmpty())

        # Test hover events and visibility toggle
        socket.show()
        self.assertFalse(socket.brush.color() == Qt.transparent)
        socket.hide()
        self.assertEqual(socket.brush.color(), Qt.transparent)

    def test_node_line_connection_and_path_update(self):
        """Verify NodeLine initializes correctly, links sockets, and computes bezier path."""
        pA = QPointF(10, 20)
        pB = QPointF(150, 80)
        line = NodeLine(pA, pB, socket=None)
        self.scene.addItem(line)

        self.assertEqual(line.pointA, pA)
        self.assertEqual(line.pointB, pB)

        line.updatePath()
        self.assertFalse(line.path().isEmpty())

        # Move endpoint and update path
        new_pB = QPointF(200, 150)
        line.pointB = new_pB
        line.updatePath()
        self.assertEqual(line.pointB, new_pB)

    def test_node_item_resize_handle(self):
        """Verify ResizeHandle geometry, bounding rect, and node resizing."""
        heater = Heater()
        heater.name = "Heater_1"
        node = NodeItem(heater, self.container, self.view)
        self.scene.addItem(node)

        orig_w = node.rect.width()
        orig_h = node.rect.height()

        handle = node._resize_handle
        self.assertIsNotNone(handle)
        self.assertFalse(handle.boundingRect().isEmpty())

        # Test resize_node
        node.resize_node(orig_w + 30, orig_h + 20)
        self.assertEqual(node.rect.width(), orig_w + 30)
        self.assertEqual(node.rect.height(), orig_h + 20)
        self.assertEqual(handle.pos().x(), node.rect.width() - 12)
        self.assertEqual(handle.pos().y(), node.rect.height() - 12)

    def test_update_input_ports_on_mixer(self):
        """Verify dynamically changing input count updates socket list and coordinates."""
        mixer = Mixer()
        mixer.name = "Mixer_Ports"
        node = NodeItem(mixer, self.container, self.view)
        self.scene.addItem(node)

        self.assertEqual(len(node.input), 2)
        node.update_input_ports(4)
        self.assertEqual(len(node.input), 4)
        self.assertEqual(mixer.no_of_inputs, 4)

    def test_update_output_ports_on_splitter(self):
        """Verify dynamically changing output count updates output socket list."""
        splitter = Splitter()
        splitter.name = "Splitter_Ports"
        node = NodeItem(splitter, self.container, self.view)
        self.scene.addItem(node)

        self.assertEqual(len(node.output), 2)
        node.update_output_ports(3)
        self.assertEqual(len(node.output), 3)
        self.assertEqual(splitter.no_of_outputs, 3)

    def test_canvas_save_and_restore(self):
        """Verify saving canvas layout and pushing undo snapshot."""
        mixer = Mixer()
        mixer.name = "Mixer_Save"
        self.container.unit_operations.append(mixer)
        node = NodeItem(mixer, self.container, self.view)
        node.setPos(50, 75)
        self.scene.addItem(node)

        saved = self.graphics.save_canvas()
        self.assertIn("items", saved)
        self.assertIn("connections", saved)
        self.assertTrue(any(it["obj"].name == "Mixer_Save" for it in saved["items"]))

        # Push snapshot to undo stack
        self.graphics.push_snapshot()
        self.assertGreater(len(undo_manager.get_last_list("Undo")), 0)

    def test_svg_renderer_cache(self):
        """Verify SVG renderer retrieval for vector-rendered icons."""
        renderer = get_svg_renderer("Mixer")
        cached = get_svg_renderer("Mixer")
        self.assertIs(renderer, cached)

    def test_mouse_double_click_opens_dock_widget(self):
        """Verify double clicking a node opens its dock widget."""
        heater = Heater()
        heater.name = "Heater_Click"
        node = NodeItem(heater, self.container, self.view)
        self.scene.addItem(node)

        self.assertFalse(node.dock_widget.isVisible())
        event = MockEvent()
        node.mouseDoubleClickEvent(event)
        self.assertTrue(node.dock_widget.isVisible())


if __name__ == '__main__':
    unittest.main()
