import os
import sys
from unittest.mock import MagicMock
import pytest
from PyQt5 import QtCore, QtGui, QtWidgets

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
for p in [os.path.join(PROJECT_ROOT, 'src', 'main'), os.path.join(PROJECT_ROOT, 'src', 'main', 'python')]:
    if p not in sys.path:
        sys.path.insert(0, p)

app = QtWidgets.QApplication.instance()
if app is None:
    app = QtWidgets.QApplication(sys.argv)

from python.utils.Graphics import NodeLine, NodeSocket
from python.utils.Container import Container


class DummyNodeItem(QtWidgets.QGraphicsRectItem):
    def __init__(self, container=None):
        super().__init__(0, 0, 40, 40)
        self.obj = MagicMock()
        self.container = container


def _make_connected_line(scene, container=None):
    src_node = DummyNodeItem(container=container)
    tgt_node = DummyNodeItem(container=container)

    src_socket = NodeSocket(QtCore.QRectF(0, 0, 10, 10), src_node, 'op', 0)
    tgt_socket = NodeSocket(QtCore.QRectF(100, 0, 10, 10), tgt_node, 'in', 0)

    line = NodeLine(QtCore.QPointF(5, 5), QtCore.QPointF(105, 5), src_socket)
    line.source = src_socket
    line.target = tgt_socket
    src_socket.out_lines.append(line)
    tgt_socket.in_lines.append(line)
    line.updatePath()
    scene.addItem(line)
    return line, src_socket, tgt_socket, src_node, tgt_node


def test_nodeline_is_selectable_and_has_wide_hitbox():
    scene = QtWidgets.QGraphicsScene()
    line, *_ = _make_connected_line(scene)

    assert line.flags() & QtWidgets.QGraphicsItem.ItemIsSelectable
    assert line.flags() & QtWidgets.QGraphicsItem.ItemIsFocusable
    assert line.shape().contains(QtCore.QPointF(50, 7))


def test_nodeline_hover_and_selection_paint():
    scene = QtWidgets.QGraphicsScene()
    line, *_ = _make_connected_line(scene)

    line.hoverEnterEvent(None)
    assert line._hovered is True
    line.hoverLeaveEvent(None)
    assert line._hovered is False

    line.setSelected(True)
    img = QtGui.QImage(150, 50, QtGui.QImage.Format_ARGB32)
    painter = QtGui.QPainter(img)
    line.paint(painter, QtWidgets.QStyleOptionGraphicsItem(), None)
    painter.end()

def test_nodeline_delete_via_container_updates_editability():
    scene = QtWidgets.QGraphicsScene()
    view = MagicMock()
    view.scene.return_value = scene
    container = Container(MagicMock(), view)
    container.update_components_editability = MagicMock()
    container.graphics.push_snapshot = MagicMock()

    line, src_socket, tgt_socket, src_node, tgt_node = _make_connected_line(scene, container)
    assert line in scene.items()

    line.delete_connection()

    assert line not in scene.items()
    assert line not in src_socket.out_lines
    assert line not in tgt_socket.in_lines
    src_node.obj.remove_connection.assert_called_once_with(0, src_socket.id)
    tgt_node.obj.remove_connection.assert_called_once_with(1, tgt_socket.id)
    container.update_components_editability.assert_called_once()
    container.graphics.push_snapshot.assert_called_once()


def test_nodeline_keyboard_delete_key():
    scene = QtWidgets.QGraphicsScene()
    line, src_socket, tgt_socket, *_ = _make_connected_line(scene)
    line.setSelected(True)

    key_event = QtGui.QKeyEvent(QtCore.QEvent.KeyPress, QtCore.Qt.Key_Delete, QtCore.Qt.NoModifier)
    line.keyPressEvent(key_event)

    assert key_event.isAccepted()
    assert line not in scene.items()
    assert src_socket.out_lines == []
    assert tgt_socket.in_lines == []


def test_nodeline_context_menu_delete(monkeypatch):
    scene = QtWidgets.QGraphicsScene()
    line, src_socket, tgt_socket, *_ = _make_connected_line(scene)

    fake_action = MagicMock()
    fake_menu = MagicMock()
    fake_menu.addAction.return_value = fake_action
    fake_menu.exec_.return_value = fake_action
    monkeypatch.setattr(QtWidgets, "QMenu", lambda: fake_menu)

    event = MagicMock()
    event.screenPos.return_value = QtCore.QPoint(10, 10)
    line.contextMenuEvent(event)

    assert line not in scene.items()
    assert src_socket.out_lines == []
    assert tgt_socket.in_lines == []


def test_deleting_one_line_preserves_other_connections():
    scene = QtWidgets.QGraphicsScene()
    line1, src1, tgt1, *_ = _make_connected_line(scene)
    line2, src2, tgt2, *_ = _make_connected_line(scene)

    line1.delete_connection()

    assert line1 not in scene.items()
    assert line2 in scene.items()
    assert line2 in src2.out_lines
    assert line2 in tgt2.in_lines