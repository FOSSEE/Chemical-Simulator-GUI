import os
import sys
import unittest
from types import SimpleNamespace
from unittest.mock import MagicMock, patch

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5 import sip
from PyQt5.QtCore import QPoint, QPointF, Qt
from PyQt5.QtGui import QCursor
from PyQt5.QtWidgets import QApplication, QGraphicsView, QMenu, QWidget

app = QApplication.instance() or QApplication(sys.argv)

from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.utils.UnitOperations import Heater, Mixer, Splitter
from python.utils import Graphics as G
from python.utils.Graphics import NodeLine, findMainWindow, lst, dock_widget_lst, stack
from python.utils.Container import Container


def event(button=Qt.LeftButton, modifiers=Qt.NoModifier):
    return MagicMock(**{"button.return_value": button,
                        "modifiers.return_value": modifiers,
                        "screenPos.return_value": QPoint(0, 0)})


class _CanvasTest(unittest.TestCase):
    """Shared canvas setup; holds no tests itself."""

    def setUp(self):
        compound_selected[:] = ["Water(chemsep)", "Ethanol(chemsep)"]
        lst.clear()
        dock_widget_lst.clear()
        stack.clear()
        Mixer.counter = Splitter.counter = Heater.counter = MaterialStream.counter = 1
        self.view = QGraphicsView()
        self.container = Container(MagicMock(), self.view)
        self.scene = self.container.scene
        self.snapshot = patch.object(self.container.graphics, "push_snapshot").start()

    def tearDown(self):
        patch.stopall()
        lst.clear()
        dock_widget_lst.clear()
        stack.clear()
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

    def add(self, obj):
        return self.container.add_unit_operation(obj)

    def connect(self, src, src_idx, tgt, tgt_idx):
        """Wire two nodes like a user drag does: visual line plus model connections."""
        s, t = src.output[src_idx], tgt.input[tgt_idx]
        line = NodeLine(s.get_center(), t.get_center(), 'op')
        line.source, line.target = s, t
        s.out_lines.append(line)
        t.in_lines.append(line)
        self.scene.addItem(line)
        if src.type != "MaterialStream":
            src.obj.add_connection(0, s.id, tgt.obj)
        if tgt.type != "MaterialStream":
            tgt.obj.add_connection(1, t.id, src.obj)
        return line

    def run_context_menu(self, node, choice):
        """Open the node's context menu and pick the action with the given text."""
        def pick(menu, *args):
            return next(a for a in menu.actions() if a.text() == choice)
        with patch.object(QMenu, "exec_", pick):
            node.contextMenuEvent(event())


class GraphicsInteractionTest(_CanvasTest):

    # ---------------- NodeLine ----------------

    def test_clicking_a_line_selects_only_that_line(self):
        h1, h2, h3 = self.add(Heater()), self.add(Heater()), self.add(Heater())
        line1, line2 = self.connect(h1, 0, h2, 0), self.connect(h2, 0, h3, 0)
        line2.setSelected(True)

        e = event()
        line1.mousePressEvent(e)

        self.assertTrue(line1.isSelected())
        self.assertFalse(line2.isSelected())
        e.accept.assert_called_once()

    def test_ctrl_click_adds_line_to_selection(self):
        h1, h2, h3 = self.add(Heater()), self.add(Heater()), self.add(Heater())
        line1, line2 = self.connect(h1, 0, h2, 0), self.connect(h2, 0, h3, 0)
        line2.setSelected(True)

        line1.mousePressEvent(event(modifiers=Qt.ControlModifier))

        self.assertTrue(line1.isSelected())
        self.assertTrue(line2.isSelected())

    def test_middle_click_on_line_is_ignored(self):
        line = self.connect(self.add(Heater()), 0, self.add(Heater()), 0)
        e = event(button=Qt.MiddleButton)
        line.mousePressEvent(e)
        self.assertFalse(line.isSelected())
        e.ignore.assert_called_once()

    def test_deleting_hovered_line_restores_cursor(self):
        line = self.connect(self.add(Heater()), 0, self.add(Heater()), 0)
        line._hovered = True
        QApplication.setOverrideCursor(QCursor(Qt.PointingHandCursor))

        line.delete_connection()

        self.assertIsNone(QApplication.overrideCursor())
        self.assertIsNone(line.scene())

    # ---------------- port count changes with unit-operation neighbours ----------------

    def test_mixer_input_change_keeps_unit_operation_sources(self):
        h1, h2, mixer = self.add(Heater()), self.add(Heater()), self.add(Mixer())
        self.connect(h1, 0, mixer, 0)
        self.connect(h2, 0, mixer, 1)

        mixer.update_input_ports(3)

        self.assertEqual(len(mixer.input), 3)
        self.assertIs(mixer.input[0].in_lines[0].source, h1.output[0])
        self.assertIs(mixer.input[1].in_lines[0].source, h2.output[0])
        self.assertEqual(mixer.input[2].in_lines, [])
        self.assertIs(h1.obj.output_stms[1], mixer.obj)
        self.assertEqual(set(mixer.obj.input_stms.values()), {h1.obj, h2.obj})

    def test_splitter_output_change_keeps_unit_operation_targets(self):
        splitter, h1, h2 = self.add(Splitter()), self.add(Heater()), self.add(Heater())
        self.connect(splitter, 0, h1, 0)
        self.connect(splitter, 1, h2, 0)

        splitter.update_output_ports(3)

        self.assertEqual(len(splitter.output), 3)
        self.assertIs(splitter.output[0].out_lines[0].target, h1.input[0])
        self.assertIs(splitter.output[1].out_lines[0].target, h2.input[0])
        self.assertIs(h1.obj.input_stms[1], splitter.obj)
        self.assertIs(h2.obj.input_stms[1], splitter.obj)

    # ---------------- NodeItem double click ----------------

    def test_double_click_replaces_open_dock_and_sizes_it(self):
        first, second = self.add(Heater()), self.add(Heater())
        dead = QWidget()
        first.dock_widget.show()
        stack.extend([first.dock_widget, dead])
        sip.delete(dead)
        second.main_window = MagicMock()

        second.mouseDoubleClickEvent(event())

        self.assertFalse(first.dock_widget.isVisible())
        self.assertTrue(second.dock_widget.isVisible())
        self.assertNotIn(dead, stack)
        second.main_window.resizeDocks.assert_any_call([second.dock_widget], [400], Qt.Horizontal)
        second.main_window.resizeDocks.assert_any_call([second.dock_widget], [600], Qt.Vertical)

    # ---------------- Material Stream context menu ----------------

    def test_context_menu_reroute_destination_frees_line_end(self):
        ms, heater = self.add(MaterialStream(compound_selected)), self.add(Heater())
        line = self.connect(ms, 0, heater, 0)

        self.run_context_menu(ms, "Reroute Destination")

        self.assertIsNone(line.target)
        self.assertIs(line.source, ms.output[0])
        self.assertEqual(heater.input[0].in_lines, [])
        self.assertEqual(heater.obj.input_stms, {})
        self.snapshot.assert_called()

    def test_context_menu_reroute_source_frees_line_start(self):
        heater, ms = self.add(Heater()), self.add(MaterialStream(compound_selected))
        line = self.connect(heater, 0, ms, 0)

        self.run_context_menu(ms, "Reroute Source")

        self.assertIsNone(line.source)
        self.assertIs(line.target, ms.input[0])
        self.assertEqual(heater.output[0].out_lines, [])
        self.assertEqual(heater.obj.output_stms, {})

    def test_reroute_without_connection_does_nothing(self):
        ms = self.add(MaterialStream(compound_selected))
        ms._reroute_material_stream("destination")
        ms._reroute_material_stream("source")
        self.snapshot.assert_not_called()

    def test_reroute_ignored_for_other_components(self):
        heater, ms = self.add(Heater()), self.add(MaterialStream(compound_selected))
        line = self.connect(heater, 0, ms, 0)
        heater._reroute_material_stream("destination")
        self.assertIs(line.target, ms.input[0])

    def test_context_menu_delete_without_container_uses_main_window(self):
        heater = self.add(Heater())
        heater.container = None
        main_window = SimpleNamespace(container=MagicMock())

        with patch.object(G, "findMainWindow", return_value=main_window):
            self.run_context_menu(heater, "Delete")

        main_window.container.delete.assert_called_once_with([heater])

    # ---------------- findMainWindow ----------------

    def test_find_main_window_through_container(self):
        holder = SimpleNamespace(container=SimpleNamespace(graphicsView=self.view))
        self.assertIs(findMainWindow(holder), self.view.window())

    def test_find_main_window_without_view_returns_none(self):
        self.assertIsNone(findMainWindow(SimpleNamespace()))


class CanvasPersistenceTest(_CanvasTest):
    """Saving, loading and undo snapshots must survive bad or partial data."""

    def lines(self):
        return [i for i in self.scene.items() if isinstance(i, NodeLine)]

    def node(self, name):
        return next(n for n in lst if n.obj.name == name)

    # ---------------- load_canvas_from_snapshot (Undo/Redo) ----------------

    def test_snapshot_with_broken_entries_still_restores_valid_parts(self):
        h1, h2 = self.add(Heater()), self.add(Heater())
        ms = self.add(MaterialStream(compound_selected))
        h3 = self.add(Heater())
        self.connect(h1, 0, h2, 0)
        self.connect(h2, 0, ms, 0)
        self.connect(ms, 0, h3, 0)
        snap = self.container.graphics.save_canvas()
        names = [h1.obj.name, h2.obj.name, ms.obj.name, h3.obj.name]

        snap["items"].append({"obj": None})  # cannot be rebuilt
        snap["connections"] += [
            {"source_name": "Ghost", "source_id": 1, "target_name": names[1], "target_id": 1},
            {"source_name": names[0], "source_id": 99, "target_name": names[1], "target_id": 1},
            {},  # missing keys
        ]
        snap["partial_connections"] = [
            {"attached_name": "Ghost", "attached_side": "source", "attached_id": 1, "free_point": (0, 0)},
            {"attached_name": names[0], "attached_side": "source", "attached_id": 99, "free_point": (0, 0)},
            {"attached_name": names[1], "attached_side": "target", "attached_id": 99, "free_point": (0, 0)},
            {"attached_name": names[0], "attached_side": "source", "attached_id": 1, "free_point": (0, 0)},
            {"attached_name": names[1], "attached_side": "target", "attached_id": 1, "free_point": (0, 0)},
            {"attached_name": names[0], "attached_side": "middle", "attached_id": 1, "free_point": (0, 0)},
            {},
        ]

        self.container.graphics.load_canvas_from_snapshot(snap, self.container)

        self.assertEqual(sorted(n.obj.name for n in lst), sorted(names))
        self.assertEqual(len(self.lines()), 3)  # no partial line added to occupied ports
        r1, r2, r3 = (self.node(n) for n in names[:3])
        self.assertIs(r1.obj.output_stms[1], r2.obj)
        self.assertIs(r2.obj.input_stms[1], r1.obj)
        self.assertIs(r3.input[0].in_lines[0].source, r2.output[0])

    def test_snapshot_skips_items_that_cannot_be_drawn(self):
        snap = {"items": [{"obj": Heater()}], "connections": []}
        with patch.object(self.container.graphics, "create_node_item", return_value=None):
            self.container.graphics.load_canvas_from_snapshot(snap, self.container)
        self.assertEqual(self.container.unit_operations, [])

    def test_malformed_snapshot_is_ignored(self):
        self.container.graphics.load_canvas_from_snapshot(["not", "a", "dict"], self.container)
        self.assertEqual(self.container.unit_operations, [])

    # ---------------- load_canvas (.sim files) ----------------

    def test_load_canvas_skips_objects_that_fail_to_rebuild(self):
        good, missing, broken = Heater(), Heater(), Heater()
        real = self.container.graphics.create_node_item

        def create(obj, container):
            if obj is missing:
                return None
            if obj is broken:
                raise RuntimeError("bad file entry")
            return real(obj, container)

        with patch.object(self.container.graphics, "create_node_item", side_effect=create):
            self.container.graphics.load_canvas([good, missing, broken], self.container)

        self.assertEqual(self.container.unit_operations, [good])

    def test_load_canvas_ignores_connections_to_missing_ports(self):
        h1, h2 = Heater(), Heater()
        h1.output_stms = {7: h2}  # a Heater has only outlet 1
        self.container.graphics.load_canvas([h1, h2], self.container)
        self.assertEqual(self.lines(), [])

    def test_load_canvas_with_invalid_list_does_not_raise(self):
        self.container.graphics.load_canvas(None, self.container)
        self.assertEqual(self.container.unit_operations, [])

    # ---------------- save_canvas / push_snapshot ----------------

    def test_save_canvas_skips_lines_with_detached_sockets(self):
        heater = self.add(Heater())
        orphan = SimpleNamespace(parent=None, id=1)
        for source, target in ((orphan, heater.input[0]), (orphan, None), (None, orphan)):
            line = NodeLine(QPointF(0, 0), QPointF(10, 0), 'op')
            line.source, line.target = source, target
            self.scene.addItem(line)

        snap = self.container.graphics.save_canvas()

        self.assertEqual(snap["connections"], [])
        self.assertEqual(snap["partial_connections"], [])

    def test_save_canvas_returns_none_on_error(self):
        with patch.object(self.scene, "items", side_effect=RuntimeError("scene gone")):
            self.assertIsNone(self.container.graphics.save_canvas())

    def test_push_snapshot_skips_failed_saves(self):
        graphics = self.container.graphics
        with patch("python.utils.undo_manager.push") as push:
            with patch.object(graphics, "save_canvas", return_value=None):
                G.Graphics.push_snapshot(graphics)
            with patch.object(graphics, "save_canvas", side_effect=RuntimeError("disk")):
                G.Graphics.push_snapshot(graphics)  # must not raise
        push.assert_not_called()


if __name__ == "__main__":
    unittest.main()
