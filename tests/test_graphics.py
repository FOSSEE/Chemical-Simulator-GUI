import os
import sys
import unittest
from unittest.mock import MagicMock, patch

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication, QTextBrowser, QGraphicsView, QMenu
from PyQt5.QtCore import QPointF, QPoint, Qt

app = QApplication.instance() or QApplication([])

from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.utils.UnitOperations import (
    Mixer, Splitter, Heater, Cooler, Valve, Flash,
    CentrifugalPump, DistillationColumn, ShortcutColumn,
    CompoundSeparator, AdiabaticCompressor, AdiabaticExpander
)
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
from python.utils import Graphics as G
from python.utils.Graphics import (
    Graphics, NodeItem, NodeSocket, NodeLine, ResizeHandle,
    lst, dock_widget_lst, stack, get_svg_renderer, findMainWindow
)
from python.utils.Container import Container


class MockEvent:
    def __init__(self, pos=None, scenePos=None, screenPos=None, button=Qt.LeftButton, modifiers=Qt.NoModifier, key=None):
        self._pos = pos or QPointF(0, 0)
        self._scenePos = scenePos or QPointF(0, 0)
        self._screenPos = screenPos or QPoint(0, 0)
        self._button = button
        self._modifiers = modifiers
        self._key = key
        self.accepted = False
        self.ignored = False

    def pos(self):
        return self._pos

    def scenePos(self):
        return self._scenePos

    def screenPos(self):
        return self._screenPos

    def button(self):
        return self._button

    def buttons(self):
        return self._button

    def modifiers(self):
        return self._modifiers

    def key(self):
        return self._key

    def accept(self):
        self.accepted = True

    def ignore(self):
        self.ignored = True


class TestGraphicsAndNodes(unittest.TestCase):
    """Unit tests for Graphics canvas, NodeItem rendering, sockets, lines, and resizing."""

    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        lst.clear()
        dock_widget_lst.clear()
        stack.clear()
        Mixer.counter = 1
        Splitter.counter = 1
        Heater.counter = 1
        Cooler.counter = 1
        Valve.counter = 1
        Flash.counter = 1
        CentrifugalPump.counter = 1
        DistillationColumn.counter = 1
        ShortcutColumn.counter = 1
        CompoundSeparator.counter = 1
        AdiabaticCompressor.counter = 1
        AdiabaticExpander.counter = 1
        MaterialStream.counter = 1

        self.browser = QTextBrowser()
        self.view = QGraphicsView()
        self.view.setSceneRect(0, 0, 2000, 2000)
        self.container = Container(self.browser, self.view)
        self.graphics = self.container.graphics
        self.scene = self.graphics.scene
        self.view.setScene(self.scene)

        undo_manager.clean_file("Undo")
        undo_manager.clean_file("Redo")

    def tearDown(self):
        self.scene.clear()
        lst.clear()
        dock_widget_lst.clear()
        stack.clear()
        undo_manager.clean_file("Undo")
        undo_manager.clean_file("Redo")
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

    def _spawn(self, op, name, x=100, y=100):
        op.name = name
        self.container.unit_operations.append(op)
        node = self.graphics.create_node_item(op, self.container)
        self.assertIsNotNone(node)
        self.scene.addItem(node)
        node.setPos(x, y)
        op.set_pos(node.scenePos())
        return node

    def _connect(self, src_sock, tgt_sock):
        line = NodeLine(src_sock.get_center(), tgt_sock.get_center(), 'op')
        line.source = src_sock
        line.target = tgt_sock
        src_sock.out_lines.append(line)
        tgt_sock.in_lines.append(line)
        self.scene.addItem(line)
        line.pointA = src_sock.get_center()
        line.pointB = tgt_sock.get_center()

        stm = ['MaterialStream', 'EngStm']
        if getattr(src_sock.parent.obj, 'type', None) not in stm:
            src_sock.parent.obj.add_connection(0, src_sock.id, tgt_sock.parent.obj)
        if getattr(tgt_sock.parent.obj, 'type', None) not in stm:
            tgt_sock.parent.obj.add_connection(1, tgt_sock.id, src_sock.parent.obj)
        return line

    # ------------------------------------------------------------------
    # Baseline tests
    # ------------------------------------------------------------------

    def test_graphics_initialization(self):
        self.assertIs(self.graphics.container, self.container)
        self.assertIs(self.graphics.graphicsView, self.view)
        self.assertIs(self.graphics.get_scene(), self.scene)

    def test_node_item_creation_and_sockets(self):
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
        mixer = Mixer()
        mixer.name = "Mixer_Test"
        node = NodeItem(mixer, self.container, self.view)

        socket = node.input[0]
        self.assertEqual(socket.type, 'in')
        self.assertEqual(socket.id, 1)
        self.assertFalse(socket.boundingRect().isEmpty())
        self.assertFalse(socket.shape().isEmpty())

        socket.show()
        self.assertFalse(socket.brush.color() == Qt.transparent)
        socket.hide()
        self.assertEqual(socket.brush.color(), Qt.transparent)

    def test_node_line_connection_and_path_update(self):
        pA = QPointF(10, 20)
        pB = QPointF(150, 80)
        line = NodeLine(pA, pB, socket=None)
        self.scene.addItem(line)

        self.assertEqual(line.pointA, pA)
        self.assertEqual(line.pointB, pB)

        line.updatePath()
        self.assertFalse(line.path().isEmpty())

        new_pB = QPointF(200, 150)
        line.pointB = new_pB
        line.updatePath()
        self.assertEqual(line.pointB, new_pB)

    def test_node_item_resize_handle(self):
        heater = Heater()
        heater.name = "Heater_1"
        node = NodeItem(heater, self.container, self.view)
        self.scene.addItem(node)

        orig_w = node.rect.width()
        orig_h = node.rect.height()

        handle = node._resize_handle
        self.assertIsNotNone(handle)
        self.assertFalse(handle.boundingRect().isEmpty())

        node.resize_node(orig_w + 30, orig_h + 20)
        self.assertEqual(node.rect.width(), orig_w + 30)
        self.assertEqual(node.rect.height(), orig_h + 20)
        self.assertEqual(handle.pos().x(), node.rect.width() - 12)
        self.assertEqual(handle.pos().y(), node.rect.height() - 12)

    def test_update_input_ports_on_mixer(self):
        mixer = Mixer()
        mixer.name = "Mixer_Ports"
        node = NodeItem(mixer, self.container, self.view)
        self.scene.addItem(node)

        self.assertEqual(len(node.input), 2)
        node.update_input_ports(4)
        self.assertEqual(len(node.input), 4)
        self.assertEqual(mixer.no_of_inputs, 4)

    def test_update_output_ports_on_splitter(self):
        splitter = Splitter()
        splitter.name = "Splitter_Ports"
        node = NodeItem(splitter, self.container, self.view)
        self.scene.addItem(node)

        self.assertEqual(len(node.output), 2)
        node.update_output_ports(3)
        self.assertEqual(len(node.output), 3)
        self.assertEqual(splitter.no_of_outputs, 3)

    def test_canvas_save_and_restore(self):
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

        self.graphics.push_snapshot()
        self.assertGreater(len(undo_manager.get_last_list("Undo")), 0)

    def test_svg_renderer_cache(self):
        renderer = get_svg_renderer("Mixer")
        cached = get_svg_renderer("Mixer")
        self.assertIs(renderer, cached)

    def test_mouse_double_click_opens_dock_widget(self):
        heater = Heater()
        heater.name = "Heater_Click"
        node = NodeItem(heater, self.container, self.view)
        self.scene.addItem(node)

        self.assertFalse(node.dock_widget.isVisible())
        event = MockEvent()
        node.mouseDoubleClickEvent(event)
        self.assertTrue(node.dock_widget.isVisible())

    # ------------------------------------------------------------------
    # Extended coverage tests
    # ------------------------------------------------------------------

    def test_all_component_types_and_static_helpers(self):
        ops = [
            (MaterialStream(), "MS_all1"),
            (Cooler(), "Cool_all1"),
            (Heater(), "Heat_all1"),
            (Valve(), "Valve_all1"),
            (Flash(), "Flash_all1"),
            (CompoundSeparator(), "CompSep_all1"),
            (CentrifugalPump(), "Pump_all1"),
            (Mixer(), "Mix_all1"),
            (Splitter(), "Split_all1"),
            (DistillationColumn(), "Dist_all1"),
            (ShortcutColumn(), "Short_all1"),
            (AdiabaticCompressor(), "Comp_all1"),
            (AdiabaticExpander(), "Exp_all1"),
        ]
        for idx, (op, name) in enumerate(ops):
            node = self._spawn(op, name, x=80 + idx * 70, y=120)
            self.assertFalse(node.shape().isEmpty())

        self.graphics.update_compounds()
        self.assertIsNotNone(NodeItem.get_instances("MS_all1"))
        self.assertIsNone(NodeItem.get_instances("NonExistentNode"))
        self.assertEqual(len(NodeItem.get_dock_widget()), len(ops))

    def test_save_and_load_canvas_from_snapshot_with_partial_lines(self):
        n_ms1 = self._spawn(MaterialStream(), "MS_s1", 100, 100)
        n_cool = self._spawn(Cooler(), "Cool_s1", 300, 100)
        n_ms2 = self._spawn(MaterialStream(), "MS_s2", 520, 100)

        n_cool.resize_node(95, 95)
        self._connect(n_ms1.output[0], n_cool.input[0])

        p_out = NodeLine(n_cool.output[0].get_center(), QPointF(420, 115), 'op')
        p_out.source = n_cool.output[0]
        n_cool.output[0].out_lines.append(p_out)
        self.scene.addItem(p_out)

        p_in = NodeLine(QPointF(460, 175), n_ms2.input[0].get_center(), 'in')
        p_in.target = n_ms2.input[0]
        n_ms2.input[0].in_lines.append(p_in)
        self.scene.addItem(p_in)

        snap = self.graphics.save_canvas()
        self.assertEqual(len(snap["items"]), 3)
        self.assertEqual(len(snap["connections"]), 1)
        self.assertEqual(len(snap["partial_connections"]), 2)

        self.graphics.load_canvas_from_snapshot(None, self.container)
        self.graphics.load_canvas_from_snapshot(snap, self.container)
        restored_lines = [i for i in self.scene.items() if isinstance(i, NodeLine)]
        self.assertEqual(len(restored_lines), 3)

    def test_load_canvas_from_saved_objects_and_invalid_item(self):
        ms1 = MaterialStream()
        ms1.name = "MS_lc1"
        ms1.pos = QPointF(100, 200)

        heater = Heater()
        heater.name = "Heat_lc1"
        heater.pos = QPointF(300, 200)

        ms2 = MaterialStream()
        ms2.name = "MS_lc2"
        ms2.pos = QPointF(500, 200)

        ms1.output_stms = {1: heater}
        heater.input_stms = {1: ms1}
        heater.output_stms = {1: ms2}
        ms2.input_stms = {1: heater}

        self.graphics.load_canvas([ms1, heater, ms2], self.container)
        lines = [i for i in self.scene.items() if isinstance(i, NodeLine)]
        self.assertEqual(len(lines), 2)

        with patch.object(NodeItem, "__init__", lambda s, *a, **kw: setattr(s, "ok", False)):
            self.assertIsNone(self.graphics.create_node_item(Heater(), self.container))

    def test_push_snapshot_updates_main_window_actions(self):
        self._spawn(MaterialStream(), "MS_mw1", 100, 100)
        mock_mw = MagicMock()
        with patch.object(G, "findMainWindow", return_value=mock_mw):
            self.graphics.push_snapshot()
        mock_mw._update_undo_redo_actions.assert_called_once()

    def test_nodeline_partial_endpoint_drag_and_reconnect_validation(self):
        n_ms1 = self._spawn(MaterialStream(), "MS_pr1", 100, 100)
        n_cool = self._spawn(Cooler(), "Cool_pr1", 320, 100)
        n_ms2 = self._spawn(MaterialStream(), "MS_pr2", 540, 100)

        free_b = QPointF(210, 120)
        line1 = NodeLine(n_ms1.output[0].get_center(), free_b, 'op')
        line1.source = n_ms1.output[0]
        n_ms1.output[0].out_lines.append(line1)
        self.scene.addItem(line1)
        line1.updatePath()
        self.assertFalse(line1.shape().isEmpty())

        self.assertFalse(line1._try_reconnect(QPointF(0, 0)))
        self.assertFalse(line1._try_reconnect(n_ms1.input[0].get_center()))

        miss_ev = MockEvent(scenePos=QPointF(0, 0))
        line1.mousePressEvent(miss_ev)
        self.assertTrue(miss_ev.ignored)
        self.assertFalse(line1._dragging_free_endpoint)

        line1.mousePressEvent(MockEvent(scenePos=free_b))
        self.assertTrue(line1._dragging_free_endpoint)

        tgt_center = n_cool.input[0].get_center()
        line1.mouseMoveEvent(MockEvent(scenePos=tgt_center))
        self.assertEqual(line1.pointB, tgt_center)

        line1.mouseReleaseEvent(MockEvent(scenePos=tgt_center))
        self.assertFalse(line1._dragging_free_endpoint)
        self.assertIs(line1.target, n_cool.input[0])
        self.assertIn(line1, n_cool.input[0].in_lines)

        self.assertFalse(line1._try_reconnect(tgt_center))

        free_a = QPointF(440, 120)
        line2 = NodeLine(free_a, n_ms2.input[0].get_center(), 'in')
        line2.target = n_ms2.input[0]
        n_ms2.input[0].in_lines.append(line2)
        self.scene.addItem(line2)
        line2.updatePath()

        self.assertFalse(line2._try_reconnect(n_ms2.output[0].get_center()))
        line2.mousePressEvent(MockEvent(scenePos=free_a))
        src_center = n_cool.output[0].get_center()
        line2.mouseMoveEvent(MockEvent(scenePos=src_center))
        line2.mouseReleaseEvent(MockEvent(scenePos=src_center))
        self.assertIs(line2.source, n_cool.output[0])
        self.assertIn(line2, n_cool.output[0].out_lines)

    def test_nodeline_routing_hops_paint_context_menu_and_keys(self):
        # Backward routes (bx - ax < 30, both <= 150 and > 150)
        b1 = NodeLine(QPointF(300, 100), QPointF(250, 200), 'op')
        self.scene.addItem(b1)
        b1.updatePath()
        self.assertEqual(len(b1._compute_route()), 6)

        b2 = NodeLine(QPointF(420, 100), QPointF(100, 220), 'op')
        self.scene.addItem(b2)
        b2.updatePath()
        self.assertEqual(len(b2._compute_route()), 6)

        # Vertical line with bx - ax >= 30 so middle vertical segment sits at x=200 (y: 100 -> 200)
        vert = NodeLine(QPointF(150, 100), QPointF(250, 200), 'op')
        self.scene.addItem(vert)
        vert.pointA = QPointF(150, 100)
        vert.pointB = QPointF(250, 200)

        horiz = NodeLine(QPointF(100, 150), QPointF(300, 150), 'op')
        self.scene.addItem(horiz)
        horiz.pointA = QPointF(100, 150)
        horiz.pointB = QPointF(300, 150)

        # Reverse horizontal direction line (right -> left)
        horiz_rev = NodeLine(QPointF(300, 160), QPointF(100, 160), 'op')
        self.scene.addItem(horiz_rev)
        horiz_rev.pointA = QPointF(300, 160)
        horiz_rev.pointB = QPointF(100, 160)

        # Paint in normal, hovered, and selected states
        img = QtGui.QImage(400, 300, QtGui.QImage.Format_ARGB32)
        painter = QtGui.QPainter(img)
        horiz.paint(painter, None, None)
        horiz._hovered = True
        horiz.paint(painter, None, None)
        horiz.setSelected(True)
        horiz.paint(painter, None, None)
        painter.end()

        # Mouse selection (plain & Ctrl), hover enter/leave, keyPressEvent, and contextMenuEvent
        horiz.mousePressEvent(MockEvent(scenePos=QPointF(150, 150)))
        self.assertTrue(horiz.isSelected())
        horiz.mousePressEvent(MockEvent(scenePos=QPointF(150, 150), modifiers=Qt.ControlModifier))
        horiz.hoverEnterEvent(None)
        self.assertTrue(horiz._hovered)
        horiz.hoverLeaveEvent(None)
        self.assertFalse(horiz._hovered)

        horiz.keyPressEvent(QtGui.QKeyEvent(QtCore.QEvent.KeyPress, Qt.Key_A, Qt.NoModifier))
        self.assertIsNotNone(horiz.scene())
        horiz.keyPressEvent(QtGui.QKeyEvent(QtCore.QEvent.KeyPress, Qt.Key_Delete, Qt.NoModifier))
        self.assertIsNone(horiz.scene())

        orig_add = QMenu.addAction
        captured = {}

        def _capture_add(self_menu, text):
            act = orig_add(self_menu, text)
            captured[text] = act
            return act

        with patch.object(QMenu, "addAction", _capture_add), \
             patch.object(QMenu, "exec_", side_effect=lambda pos: captured["Delete Connection"]):
            horiz_rev.contextMenuEvent(MockEvent(screenPos=QPoint(200, 160)))
        self.assertIsNone(horiz_rev.scene())

    def test_nodesocket_drag_connect_move_and_cancel(self):
        n_ms1 = self._spawn(MaterialStream(), "MS_sk1", 100, 100)
        n_cool = self._spawn(Cooler(), "Cool_sk1", 320, 100)
        n_ms2 = self._spawn(MaterialStream(), "MS_sk2", 540, 100)

        op_sock = n_ms1.output[0]
        in_sock = n_cool.input[0]

        op_sock.show()
        img = QtGui.QImage(64, 64, QtGui.QImage.Format_ARGB32)
        painter = QtGui.QPainter(img)
        op_sock.paint(painter, None, None)
        painter.end()
        op_sock.hoverEnterEvent(MagicMock())
        op_sock.hoverLeaveEvent(MagicMock())
        op_sock.hide()

        # Case 1: op -> in
        op_sock.mousePressEvent(MockEvent(pos=QPointF(6, 6), scenePos=op_sock.get_center()))
        self.assertIsNotNone(op_sock.new_line)
        op_sock.mouseMoveEvent(MockEvent(pos=QPointF(20, 20), scenePos=QPointF(180, 180)))
        op_sock.mouseMoveEvent(MockEvent(pos=QPointF(50, 6), scenePos=in_sock.get_center()))
        op_sock.mouseReleaseEvent(MockEvent(pos=QPointF(50, 6), scenePos=in_sock.get_center()))
        self.assertEqual(len(in_sock.in_lines), 1)

        # Case 2: in -> op
        op2 = n_cool.output[0]
        in2 = n_ms2.input[0]
        in2.mousePressEvent(MockEvent(pos=QPointF(6, 6), scenePos=in2.get_center()))
        in2.mouseMoveEvent(MockEvent(pos=QPointF(-50, 6), scenePos=op2.get_center()))
        in2.mouseReleaseEvent(MockEvent(pos=QPointF(-50, 6), scenePos=op2.get_center()))
        self.assertEqual(len(op2.out_lines), 1)

        # Case 3: drag into empty space -> cancels line cleanly
        n_ms3 = self._spawn(MaterialStream(), "MS_sk3", 100, 300)
        free_op = n_ms3.output[0]
        free_op.mousePressEvent(MockEvent(pos=QPointF(6, 6), scenePos=free_op.get_center()))
        free_op.mouseReleaseEvent(MockEvent(pos=QPointF(900, 900), scenePos=QPointF(900, 900)))
        self.assertEqual(len(free_op.out_lines), 0)

    def test_resize_handle_drag_paint_and_reconnect(self):
        n_ms1 = self._spawn(MaterialStream(), "MS_rh1", 100, 100)
        n_cool = self._spawn(Cooler(), "Cool_rh1", 320, 100)
        n_ms2 = self._spawn(MaterialStream(), "MS_rh2", 540, 100)

        handle = n_cool._resize_handle
        img = QtGui.QImage(32, 32, QtGui.QImage.Format_ARGB32)
        painter = QtGui.QPainter(img)
        handle.paint(painter, None, None)
        painter.end()

        handle.mousePressEvent(MockEvent(scenePos=QPointF(150, 150)))
        self.assertTrue(handle._dragging)
        handle.mouseMoveEvent(MockEvent(scenePos=QPointF(210, 220)))
        self.assertGreater(n_cool.rect.width(), 60)

        handle.source = n_ms1.output[0]
        handle.target = None
        handle.pointB = QPointF(0, 0)
        self.assertTrue(handle._try_reconnect(n_cool.input[0].get_center()))

        handle.source = None
        handle.target = n_ms2.input[0]
        handle.pointA = QPointF(0, 0)
        self.assertTrue(handle._try_reconnect(n_cool.output[0].get_center()))

        handle._dragging_free_endpoint = True
        handle.mouseReleaseEvent(MockEvent(scenePos=QPointF(0, 0)))
        self.assertFalse(handle._dragging_free_endpoint)

    def test_dynamic_ports_with_connected_streams(self):
        n_ms1 = self._spawn(MaterialStream(), "MS_dp1", 50, 100)
        n_ms2 = self._spawn(MaterialStream(), "MS_dp2", 50, 200)
        n_ms3 = self._spawn(MaterialStream(), "MS_dp3", 50, 300)
        n_mix = self._spawn(Mixer(), "Mix_dp1", 250, 200)
        n_spl = self._spawn(Splitter(), "Split_dp1", 450, 200)
        n_o1 = self._spawn(MaterialStream(), "MS_dpo1", 650, 150)
        n_o2 = self._spawn(MaterialStream(), "MS_dpo2", 650, 250)

        n_mix.update_input_ports(4)
        self._connect(n_ms1.output[0], n_mix.input[0])
        self._connect(n_ms2.output[0], n_mix.input[2])
        self._connect(n_ms3.output[0], n_mix.input[3])

        n_mix.update_input_ports(3)
        self.assertEqual(len(n_mix.input), 3)
        self.assertTrue(all(len(s.in_lines) == 1 for s in n_mix.input))

        n_spl.update_output_ports(4)
        self._connect(n_spl.output[0], n_o1.input[0])
        self._connect(n_spl.output[1], n_o2.input[0])

        n_spl.update_output_ports(2)
        self.assertEqual(len(n_spl.output), 2)
        self.assertEqual(len(n_spl.output[0].out_lines), 1)
        self.assertEqual(len(n_spl.output[1].out_lines), 1)

    def test_reroute_material_stream_and_context_menu_delete(self):
        n_h1 = self._spawn(Heater(), "Heat_rr1", 100, 150)
        n_ms = self._spawn(MaterialStream(), "MS_rr1", 300, 150)
        n_h2 = self._spawn(Heater(), "Heat_rr2", 500, 150)

        line_in = self._connect(n_h1.output[0], n_ms.input[0])
        line_out = self._connect(n_ms.output[0], n_h2.input[0])

        n_h1._reroute_material_stream("destination")

        n_ms._reroute_material_stream("destination")
        self.assertIsNone(line_out.target)
        self.assertIs(line_out.source, n_ms.output[0])

        n_ms._reroute_material_stream("source")
        self.assertIsNone(line_in.source)
        self.assertIs(line_in.target, n_ms.input[0])

        orig_add = QMenu.addAction
        captured = {}

        def _capture_add(self_menu, text):
            act = orig_add(self_menu, text)
            captured[text] = act
            return act

        with patch.object(QMenu, "addAction", _capture_add), \
             patch.object(QMenu, "exec_", side_effect=lambda pos: captured["Delete"]):
            n_ms.contextMenuEvent(MockEvent(screenPos=QPoint(300, 150)))

        self.assertNotIn(n_ms, self.scene.items())

    def test_nodeitem_paint_tooltips_hover_and_drag_clamping(self):
        node = self._spawn(Heater(), "Heat_pt1", 100, 100)
        ms_node = self._spawn(MaterialStream(), "MS_pt1", 250, 100)

        img = QtGui.QImage(100, 100, QtGui.QImage.Format_ARGB32)
        painter = QtGui.QPainter(img)
        node.paint(painter, None, None)
        node.setSelected(True)
        node.paint(painter, None, None)
        node.svg_renderer = None
        node.paint(painter, None, None)
        painter.end()

        node.update_tooltip()
        ms_node.update_tooltip_selectedVar()
        node.hoverEnterEvent(None)
        node.hoverLeaveEvent(None)

        node._press_scene_pos = node.scenePos()
        node.setPos(-500, -500)
        self.assertGreaterEqual(node.pos().x(), 0)
        self.assertGreaterEqual(node.pos().y(), 0)
        with patch.object(QtWidgets.QGraphicsItem, "mouseMoveEvent"): node.mouseMoveEvent(MockEvent(pos=QPointF(20, 20), scenePos=QPointF(150, 150)))
        with patch.object(QtWidgets.QGraphicsItem, "mouseReleaseEvent"): node.mouseReleaseEvent(MockEvent(pos=QPointF(20, 20), scenePos=QPointF(150, 150)))

    def test_remaining_graphics_edge_branches(self):
        # NodeSocket mouseMoveEvent on 'in' socket and with other_line set
        n_ms1 = self._spawn(MaterialStream(), "MS_eb1", 100, 300)
        n_cool = self._spawn(Cooler(), "Cool_eb1", 300, 300)
        op_s = n_ms1.output[0]
        in_s = n_cool.input[0]

        dummy_line = NodeLine(QPointF(100, 300), QPointF(200, 300), 'op')
        self.scene.addItem(dummy_line)
        op_s.other_line = dummy_line
        op_s.mouseMoveEvent(MockEvent(pos=QPointF(10, 10), scenePos=QPointF(220, 310)))
        op_s.other_line = None

        in_s.other_line = dummy_line
        in_s.mouseMoveEvent(MockEvent(pos=QPointF(-10, 10), scenePos=QPointF(180, 310)))
        in_s.other_line = None

        # NodeItem update_input_ports early return & update_output_ports clamping + Splitter hook
        n_mix = self._spawn(Mixer(), "Mix_eb1", 500, 300)
        n_mix.update_input_ports(len(n_mix.input))

        n_spl = self._spawn(Splitter(), "Split_eb1", 700, 300)
        n_spl.update_output_ports(1)
        n_spl.update_output_ports(8)

        n_ms_spl = self._spawn(MaterialStream(), "MS_eb_spl", 550, 420)
        s_op = n_ms_spl.output[0]
        s_in = n_spl.input[0]
        s_op.mousePressEvent(MockEvent(pos=QPointF(6, 6), scenePos=s_op.get_center()))
        s_op.mouseReleaseEvent(MockEvent(pos=QPointF(50, 6), scenePos=s_in.get_center()))

        # findMainWindow fallback
        self.assertIsNone(findMainWindow(object()))


if __name__ == '__main__':
    unittest.main()

