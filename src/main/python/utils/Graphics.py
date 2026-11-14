from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
from PyQt5.QtWidgets import QLineEdit
from PyQt5 import QtSvg
from PyQt5.QtCore import QTimer
import os, sys
import copy

_svg_renderer_cache = {}


def get_svg_renderer(component_type):
    """Return a shared QSvgRenderer for the component type, or None if no SVG."""
    if component_type in _svg_renderer_cache:
        return _svg_renderer_cache[component_type]

    svg_path = os.path.join(parentPath, "resources", "base", "icons", "svg",
                            f"{component_type}.svg")
    renderer = None
    if os.path.exists(svg_path):
        candidate = QtSvg.QSvgRenderer(svg_path)
        if candidate.isValid():
            renderer = candidate

    _svg_renderer_cache[component_type] = renderer
    return renderer


current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)
sys.path.append(parentPath)

from python.DockWidgets.DockWidget import *
from python.utils.undo_manager import *
from python.DockWidgets.DockWidgetMaterialStream import *
from python.DockWidgets.DockWidgetDistillationColumn import *
from python.DockWidgets.DockWidgetShortcutColumn import *
from python.DockWidgets.DockWidgetMixer import *
from python.DockWidgets.DockWidgetSplitter import *
from python.DockWidgets.DockWidgetFlash import *
from python.DockWidgets.DockWidgetCompoundSeparator import *
from python.DockWidgets.DockWidgetCompressorExpander import *
from python.utils.Container import *
from python.utils.Streams import *
from python.utils.UnitOperations import *
from python.utils.ComponentSelector import *

class Graphics(object):

    def __init__(self, container, graphicsView=None):

        # 🔹 Store reference to parent container
        self.container = container

        # 🔹 Link to container's unit operations (single source of truth)
        self.unit_operations = container.unit_operations

        # 🔹 Scene setup
        self.scene = QGraphicsScene()
        self.scene.setItemIndexMethod(QGraphicsScene.BspTreeIndex)

        # 🔹 GraphicsView handling
        if graphicsView is not None:
            self.graphicsView = graphicsView
        else:
            self.graphicsView = getattr(container, "graphicsView", None)

        self.current_pos = None

        if self.graphicsView is not None:
            try:
                self.graphicsView.horizontalScrollBarVal = self.graphicsView.horizontalScrollBar().value()
            except Exception:
                pass

    def get_scene(self):
        return self.scene

    def create_node_item(self,unit_operation, container):
        tempItem = NodeItem(unit_operation, container, self.graphicsView)
        if tempItem.ok:
            return tempItem
        else:
            return None

    def update_compounds(self):
        for i in self.graphicsView.items():
            if isinstance(i, NodeItem):
                i.update_compounds()
    
    def load_canvas(self, obj_list, container):
        """
        Rebuilds scene from a list of saved unit-operation objects
        (the format produced by mainApp.save() for .sim files).
        Each object carries its own position (obj.pos) and connection
        data (obj.input_stms / obj.output_stms).
        """
        try:
            name_to_item = {}   # obj.name → NodeItem

            # --- Phase 1: recreate every node --------------------------------
            for obj in obj_list:
                try:
                    obj.saved = True
                    box = self.create_node_item(obj, container)
                    if box is None:
                        print(f"[DEBUG] load_canvas: create_node_item returned None for {obj.name}")
                        continue
                    self.scene.addItem(box)

                    # Restore position from the saved object
                    if hasattr(obj, 'pos') and obj.pos is not None:
                        box.setPos(obj.pos)

                    container.unit_operations.append(obj)
                    name_to_item[obj.name] = box
                except Exception as e:
                    print(f"[DEBUG] load_canvas: failed to rebuild {getattr(obj, 'name', '?')} → {e}")

            # Let Qt finalize the scene layout before computing socket positions
            from PyQt5.QtWidgets import QApplication
            QApplication.processEvents()

            # --- Phase 2: rebuild visual connections --------------------------
            def _socket_scene_center(socket):
                """Compute socket center in scene coords without relying on mapToScene."""
                r = socket.boundingRect()
                local_center = QtCore.QPointF(r.x() + r.width() / 2, r.y() + r.height() / 2)
                if socket.parentItem() is not None:
                    return socket.parentItem().scenePos() + socket.pos() + local_center
                return local_center

            connected_pairs = set()  # avoid duplicate lines (src_name, src_id, tgt_name, tgt_id)

            def _draw_connection(src_name, src_socket_id, tgt_name, tgt_socket_id):
                pair_key = (src_name, src_socket_id, tgt_name, tgt_socket_id)
                if pair_key in connected_pairs:
                    return
                
                src_item = name_to_item.get(src_name)
                tgt_item = name_to_item.get(tgt_name)
                if not src_item or not tgt_item:
                    return

                src_socket = next((s for s in src_item.output if s.id == src_socket_id), None)
                tgt_socket = next((s for s in tgt_item.input if s.id == tgt_socket_id), None)
                if not src_socket or not tgt_socket:
                    print(f"[DEBUG] load_canvas: socket not found {src_name}[out:{src_socket_id}] -> {tgt_name}[in:{tgt_socket_id}]")
                    return

                connected_pairs.add(pair_key)
                pt_a = _socket_scene_center(src_socket)
                pt_b = _socket_scene_center(tgt_socket)
                line = NodeLine(pt_a, pt_b, 'op')
                line.source = src_socket
                line.target = tgt_socket
                src_socket.out_lines.append(line)
                tgt_socket.in_lines.append(line)
                self.scene.addItem(line)
                line.pointA = pt_a
                line.pointB = pt_b

            for obj in obj_list:
                # 1. Forward connections (obj -> target)
                out_stms = getattr(obj, 'output_stms', {})
                if isinstance(out_stms, dict):
                    for src_socket_id, target_obj in out_stms.items():
                        tgt_name = getattr(target_obj, 'name', None)
                        if not tgt_name: continue
                        
                        tgt_socket_id = 1
                        tgt_in_stms = getattr(target_obj, 'input_stms', {})
                        if isinstance(tgt_in_stms, dict):
                            for tid, connected_obj in tgt_in_stms.items():
                                if getattr(connected_obj, 'name', None) == obj.name:
                                    tgt_socket_id = tid
                                    break
                        
                        _draw_connection(obj.name, src_socket_id, tgt_name, tgt_socket_id)

                # 2. Backward connections (source -> obj)
                in_stms = getattr(obj, 'input_stms', {})
                if isinstance(in_stms, dict):
                    for tgt_socket_id, source_obj in in_stms.items():
                        src_name = getattr(source_obj, 'name', None)
                        if not src_name: continue
                        
                        src_socket_id = 1
                        src_out_stms = getattr(source_obj, 'output_stms', {})
                        if isinstance(src_out_stms, dict):
                            for sid, connected_obj in src_out_stms.items():
                                if getattr(connected_obj, 'name', None) == obj.name:
                                    src_socket_id = sid
                                    break
                        
                        _draw_connection(src_name, src_socket_id, obj.name, tgt_socket_id)

            self._restore_counters(container.unit_operations)
            print(f"[DEBUG] load_canvas: reloaded {len(obj_list)} items, {len(connected_pairs)} connections")

        except Exception as e:
            print("[DEBUG] load_canvas failed:", e)
            import traceback; traceback.print_exc()



    def save_canvas(self):
        try:
            from python.utils.ComponentSelector import compound_selected

            data = {
                "items": [],
                "connections": [],
                "partial_connections": [],
                "compounds": list(compound_selected)
            }

            for item in self.scene.items():
                if isinstance(item, NodeItem):
                    obj = item.obj
                    has_stms = hasattr(obj, "input_stms") and hasattr(obj, "output_stms")

                    if has_stms:
                        saved_in, saved_out = obj.input_stms, obj.output_stms
                        obj.input_stms, obj.output_stms = {}, {}

                    try:
                        obj_copy = copy.deepcopy(obj)
                    finally:
                        if has_stms:
                            obj.input_stms, obj.output_stms = saved_in, saved_out

                    data["items"].append({
                        "obj": obj_copy,
                        "pos": (item.scenePos().x(), item.scenePos().y()),
                        "width": item.rect.width(),
                        "height": item.rect.height(),
                    })

            for item in self.scene.items():
                if not isinstance(item, NodeLine):
                    continue

                src = item.source
                tgt = item.target

                # Complete connection
                if src is not None and tgt is not None:
                    if src.parent is None or tgt.parent is None:
                        continue

                    data["connections"].append({
                        "source_name": src.parent.obj.name,
                        "source_id": src.id,
                        "target_name": tgt.parent.obj.name,
                        "target_id": tgt.id,
                    })

                # Partial connection with attached source
                elif src is not None and tgt is None:
                    if src.parent is None:
                        continue

                    data["partial_connections"].append({
                        "attached_side": "source",
                        "attached_name": src.parent.obj.name,
                        "attached_id": src.id,
                        "free_point": (item.pointB.x(), item.pointB.y()),
                    })

                # Partial connection with attached target
                elif src is None and tgt is not None:
                    if tgt.parent is None:
                        continue

                    data["partial_connections"].append({
                        "attached_side": "target",
                        "attached_name": tgt.parent.obj.name,
                        "attached_id": tgt.id,
                        "free_point": (item.pointA.x(), item.pointA.y()),
                    })

            print(
                f"[DEBUG] save_canvas: {len(data['items'])} items, "
                f"{len(data['connections'])} connections, "
                f"{len(data['partial_connections'])} partial connections"
            )

            return data

        except Exception as e:
            print("[DEBUG] save_canvas failed:", e)
            return None


    def push_snapshot(self):
        from python.utils.undo_manager import push, clean_file
        try:
            snap = self.save_canvas()
            if snap is None:
                return
            clean_file("Redo")
            push("Undo", snap)
            mw = findMainWindow(self)
            if mw is not None and hasattr(mw, "_update_undo_redo_actions"):
                mw._update_undo_redo_actions()
        except Exception as e:
            print("[DEBUG] push_snapshot failed:", e)

    def _restore_counters(self, ops):
        import re
        from python.utils.UnitOperations import (
            Mixer, Heater, Cooler, Valve, Flash, Splitter,
            DistillationColumn, ShortcutColumn, AdiabaticCompressor,
            AdiabaticExpander, CentrifugalPump, CompoundSeparator)
        from python.utils.Streams import MaterialStream

        classes = {c.__name__: c for c in [
            Mixer, Heater, Cooler, Valve, Flash, Splitter,
            DistillationColumn, ShortcutColumn, AdiabaticCompressor,
            AdiabaticExpander, CentrifugalPump, CompoundSeparator, MaterialStream]}

        max_num = {}
        for op in ops:
            match = re.search(r"(\d+)$", getattr(op, "name", "") or "")
            num = int(match.group(1)) if match else 0
            max_num[op.type] = max(max_num.get(op.type, 0), num)

        for type_name, num in max_num.items():
            if type_name in classes:
                classes[type_name].counter = num + 1

    def load_canvas_from_snapshot(self, snapshot, container):
        try:
            if not snapshot:
                return

            self.scene.clear()
            lst.clear()
            dock_widget_lst.clear()
            container.unit_operations.clear()
            self.unit_operations = container.unit_operations

            from python.utils.ComponentSelector import compound_selected
            compounds = snapshot.get("compounds", None)
            if compounds is not None:
                compound_selected.clear()
                compound_selected.extend(compounds)

            stm = ['MaterialStream', 'EngStm']
            name_to_item = {}

            for entry in snapshot.get("items", []):
                try:
                    obj = copy.deepcopy(entry["obj"])
                    obj.saved = True
                    if hasattr(obj, "input_stms"):
                        obj.input_stms = {}
                    if hasattr(obj, "output_stms"):
                        obj.output_stms = {}

                    box = self.create_node_item(obj, container)
                    if box is None:
                        continue
                    self.scene.addItem(box)

                    pos = entry.get("pos", None)
                    if pos is not None:
                        box.setPos(QtCore.QPointF(pos[0], pos[1]))
                        obj.set_pos(box.scenePos())

                    width = entry.get("width", None)
                    height = entry.get("height", None)
                    if width and height and (width != box.rect.width() or height != box.rect.height()):
                        box.resize_node(width, height)

                    container.unit_operations.append(obj)
                    name_to_item[obj.name] = box
                except Exception as e:
                    print("[DEBUG] load_canvas_from_snapshot: rebuild item failed:", e)

            for conn in snapshot.get("connections", []):
                try:
                    src_item = name_to_item.get(conn["source_name"])
                    tgt_item = name_to_item.get(conn["target_name"])
                    if src_item is None or tgt_item is None:
                        continue
                    src_socket = next((s for s in src_item.output if s.id == conn["source_id"]), None)
                    tgt_socket = next((s for s in tgt_item.input if s.id == conn["target_id"]), None)
                    if src_socket is None or tgt_socket is None:
                        continue

                    line = NodeLine(src_socket.get_center(), tgt_socket.get_center(), 'op')
                    line.source = src_socket
                    line.target = tgt_socket
                    src_socket.out_lines.append(line)
                    tgt_socket.in_lines.append(line)
                    self.scene.addItem(line)
                    line.pointA = src_socket.get_center()
                    line.pointB = tgt_socket.get_center()

                    if getattr(src_socket.parent.obj, 'type', None) not in stm:
                        src_socket.parent.obj.add_connection(0, src_socket.id, tgt_socket.parent.obj)
                    if getattr(tgt_socket.parent.obj, 'type', None) not in stm:
                        tgt_socket.parent.obj.add_connection(1, tgt_socket.id, src_socket.parent.obj)

                    sc = src_socket.parent
                    tg = tgt_socket.parent
                    if getattr(sc.obj, 'type', None) == 'MaterialStream' and len(sc.input[0].in_lines) > 0:
                        sc.obj.disableInputDataTab(sc.dock_widget)
                    if getattr(tg.obj, 'type', None) == 'MaterialStream' and len(tg.input[0].in_lines) > 0:
                        tg.obj.disableInputDataTab(tg.dock_widget)
                except Exception as e:
                    print("[DEBUG] load_canvas_from_snapshot: rebuild connection failed:", e)

            # Restore partial connections
            for conn in snapshot.get("partial_connections", []):
                try:
                    attached_item = name_to_item.get(conn["attached_name"])

                    if attached_item is None:
                        continue

                    free_point_data = conn["free_point"]
                    free_point = QtCore.QPointF(
                        free_point_data[0],
                        free_point_data[1]
                    )

                    attached_side = conn["attached_side"]

                    if attached_side == "source":
                        socket = next(
                            (
                                s for s in attached_item.output
                                if s.id == conn["attached_id"]
                            ),
                            None
                        )

                        if socket is None:
                            continue

                        if socket.out_lines:
                            print("[DEBUG] Partial source socket already occupied.")
                            continue

                        line = NodeLine(
                            socket.get_center(),
                            free_point,
                            'op'
                        )

                        line.source = socket
                        socket.out_lines.append(line)

                    elif attached_side == "target":
                        socket = next(
                            (
                                s for s in attached_item.input
                                if s.id == conn["attached_id"]
                            ),
                            None
                        )

                        if socket is None:
                            continue

                        if socket.in_lines:
                            print("[DEBUG] Partial target socket already occupied.")
                            continue

                        line = NodeLine(
                            free_point,
                            socket.get_center(),
                            'in'
                        )

                        line.target = socket
                        socket.in_lines.append(line)

                    else:
                        continue

                    self.scene.addItem(line)

                    # Rebuild route and draggable endpoint marker.
                    line.pointA = line.pointA
                    line.pointB = line.pointB

                    print(
                        f"[DEBUG] Restored partial connection: {attached_side}"
                    )

                except Exception as e:
                    print(
                        "[DEBUG] load_canvas_from_snapshot: "
                        "restore partial connection failed:",
                        e
                    )

            if hasattr(container, "update_components_editability"):
                container.update_components_editability()

            self._restore_counters(container.unit_operations)

        except Exception as e:
            print("[DEBUG] Graphics.load_canvas_from_snapshot error:", e)


           
                            
class NodeLine(QtWidgets.QGraphicsPathItem):
    HOP_RADIUS = 6  # size of the bend drawn where two lines cross

    def __init__(self, pointA, pointB , socket):
        super(NodeLine, self).__init__()
        self._route = []
        self._previous_scene = None
        self._pointA = pointA
        self._pointB = pointB
        self.socket = socket
        self._source = None
        self._target = None
        self._dragging_free_endpoint = False
        self._free_endpoint_radius = 12
        self.setZValue(-1)
        self.setAcceptedMouseButtons(QtCore.Qt.LeftButton)
        self.setBrush(QtGui.QColor(0,70,70,120))
        self.pen = QtGui.QPen()
        self.pen.setStyle(QtCore.Qt.SolidLine)
        self.pen.setWidth(2)
        self.pen.setColor(QtGui.QColor(0,70,70,220))
        self.setPen(self.pen)

    def _compute_route(self):
        """Corner points of the orthogonal route from pointA to pointB."""
        ax, ay = self._pointA.x(), self._pointA.y()
        bx, by = self._pointB.x(), self._pointB.y()

        if (bx - ax) < 30:
            # Target is behind the source: step out, go around, step back in
            midptx = ax + 13
            if abs(bx - midptx) > 150:
                midy = ay + 100
            else:
                midy = max(ay, by) - abs(ay - by) / 2
            return [(ax, ay), (midptx, ay), (midptx, midy),
                    (bx - 13, midy), (bx - 13, by), (bx, by)]

        midptx = 0.5 * (ax + bx)
        return [(ax, ay), (midptx, ay), (midptx, by), (bx, by)]

    def _route_rect(self):
        """Bounding rect of the route, padded so hops are included."""
        if not self._route:
            return QtCore.QRectF()
        xs = [x for x, _ in self._route]
        ys = [y for _, y in self._route]
        r = self.HOP_RADIUS
        return QtCore.QRectF(min(xs) - r, min(ys) - r,
                             max(xs) - min(xs) + 2 * r, max(ys) - min(ys) + 2 * r)

    def _vertical_segments(self):
        """(x, y_min, y_max) for every vertical segment of the route."""
        segs = []
        for (x1, y1), (x2, y2) in zip(self._route, self._route[1:]):
            if x1 == x2 and y1 != y2:
                segs.append((x1, min(y1, y2), max(y1, y2)))
        return segs

    def _other_lines(self, rect, scene=None):
        scene = scene if scene is not None else self.scene()
        if scene is None or rect.isNull():
            return []
        return [item for item in scene.items(rect, QtCore.Qt.IntersectsItemBoundingRect)
                if isinstance(item, NodeLine) and item is not self]

    def _find_hops(self):
        """
        Map route segment index -> x positions where this line must hop.
        Only horizontal segments hop, and only over vertical segments of other
        lines, so every crossing gets exactly one hop whichever line is drawn
        first.
        """
        r = self.HOP_RADIUS
        horizontals = []
        for i, ((x1, y1), (x2, y2)) in enumerate(zip(self._route, self._route[1:])):
            if y1 == y2 and x1 != x2:
                horizontals.append((i, min(x1, x2), max(x1, x2), y1))
        if not horizontals:
            return {}

        hops = {}
        for other in self._other_lines(self._route_rect()):
            for vx, vy_min, vy_max in other._vertical_segments():
                for i, x_min, x_max, y in horizontals:
                    # Strict crossing only: skip touches at segment ends and
                    # crossings too close to a corner to fit a hop
                    if x_min + r < vx < x_max - r and vy_min + 0.5 < y < vy_max - 0.5:
                        hops.setdefault(i, []).append(vx)
        return hops


    def _rebuild_path(self):
        """Draw the route, adding a semicircular hop at every crossing."""
        path = QtGui.QPainterPath()
        if not self._route:
            self.setPath(path)
            return

        r = self.HOP_RADIUS
        hops = self._find_hops()
        path.moveTo(*self._route[0])

        for i, ((x1, y1), (x2, y2)) in enumerate(zip(self._route, self._route[1:])):
            if i in hops:
                direction = 1 if x2 > x1 else -1
                last_x = x1

                for hx in sorted(set(hops[i]), key=lambda x: (x - x1) * direction):
                    start_x = hx - direction * r
                    if (start_x - last_x) * direction < 0:
                        continue

                    path.lineTo(start_x, y1)

                    if direction > 0:
                        path.arcTo(QtCore.QRectF(hx - r, y1 - r, 2 * r, 2 * r), 180, -180)
                    else:
                        path.arcTo(QtCore.QRectF(hx - r, y1 - r, 2 * r, 2 * r), 0, 180)

                    last_x = hx + direction * r

            path.lineTo(x2, y2)

        # Show a draggable marker at the free endpoint of a partial line.
        if (self.source is None) != (self.target is None):
            free_point = self._pointA if self.source is None else self._pointB
            radius = self._free_endpoint_radius

            path.addEllipse(
                QtCore.QRectF(
                    free_point.x() - radius,
                    free_point.y() - radius,
                    radius * 2,
                    radius * 2
                )
            )
            self.setZValue(1)
        else:
            self.setZValue(-1)

        self.setPath(path)

    def shape(self):
        path = QtGui.QPainterPath()

        # For partial connections, only the free endpoint
        # should receive mouse events.
        if (self.source is None) != (self.target is None):
            free_point = self._pointA if self.source is None else self._pointB
            radius = self._free_endpoint_radius

            path.addEllipse(QtCore.QRectF(
                free_point.x() - radius,
                free_point.y() - radius,
                radius * 2,
                radius * 2
            ))
            return path

        return super(NodeLine, self).shape()


    def _refresh_crossing_lines(self, rect, scene=None):
        """Redraw other lines in `rect`, since their hops over this line may have changed."""
        for other in self._other_lines(rect, scene):
            other._rebuild_path()

    def updatePath(self):
        old_rect = self._route_rect()
        self._route = self._compute_route()
        self._rebuild_path()
        self._refresh_crossing_lines(old_rect.united(self._route_rect()))

    def itemChange(self, change, value):
        # Keep hops correct when a line is added to or removed from a scene
        if change == QtWidgets.QGraphicsItem.ItemSceneChange:
            self._previous_scene = self.scene()
        elif change == QtWidgets.QGraphicsItem.ItemSceneHasChanged:
            previous_scene, self._previous_scene = self._previous_scene, None
            rect = self._route_rect()
            if previous_scene is not None and previous_scene is not self.scene():
                self._refresh_crossing_lines(rect, previous_scene)
            if self.scene() is not None:
                self._rebuild_path()
                self._refresh_crossing_lines(rect)
        return super(NodeLine, self).itemChange(change, value)

    def paint(self, painter, option, widget):
        painter.setPen(self.pen)
        painter.drawPath(self.path())

    def mousePressEvent(self, event):
        if self.source is None or self.target is None:
            free_point = self._pointA if self.source is None else self._pointB

            if QtCore.QLineF(
                event.scenePos(), free_point
            ).length() <= self._free_endpoint_radius:

                self._dragging_free_endpoint = True

                # Show all component ports while dragging.
                self._set_all_sockets_visible(True)

                event.accept()
                return

        event.ignore()

    def mouseMoveEvent(self, event):
        if self._dragging_free_endpoint:
            new_point = event.scenePos()

            if self.source is None:
                self.pointA = new_point
            else:
                self.pointB = new_point

            event.accept()
            return

        event.ignore()

    def mouseReleaseEvent(self, event):
        if self._dragging_free_endpoint:
            self._dragging_free_endpoint = False

            self._try_reconnect(event.scenePos())

            # Hide ports after completing the drag.
            self._set_all_sockets_visible(False)

            event.accept()
            return

        event.ignore()


    def _set_all_sockets_visible(self, visible):
        if self.scene() is None:
            return

        for item in self.scene().items():
            if isinstance(item, NodeItem):
                for socket in item.input:
                    if visible:
                        socket.show()
                    else:
                        socket.hide()

                for socket in item.output:
                    if visible:
                        socket.show()
                    else:
                        socket.hide()


    def _try_reconnect(self, scene_pos):
        """Reconnect a partial line to a compatible free socket."""

        if self.source is not None and self.target is not None:
            return False

        if self.scene() is None:
            return False

        candidate = None

        for item in self.scene().items(scene_pos):
            if isinstance(item, NodeSocket):
                candidate = item
                break

        if candidate is None:
            return False

        stm = ['MaterialStream', 'EngStm']

        # Reconnect free destination to an input socket.
        if self.source is not None and self.target is None:

            if candidate.type != 'in' or candidate.in_lines:
                return False

            if candidate.parent is self.source.parent:
                return False

            self.target = candidate
            candidate.in_lines.append(self)
            self.pointB = candidate.get_center()

        # Reconnect free source to an output socket.
        elif self.source is None and self.target is not None:

            if candidate.type != 'op' or candidate.out_lines:
                return False

            if candidate.parent is self.target.parent:
                return False

            self.source = candidate
            candidate.out_lines.append(self)
            self.pointA = candidate.get_center()

        else:
            return False

        # Restore logical component connections.
        if self.source.parent.obj.type not in stm:
            self.source.parent.obj.add_connection(
                0, self.source.id, self.target.parent.obj
            )

        if self.target.parent.obj.type not in stm:
            self.target.parent.obj.add_connection(
                1, self.target.id, self.source.parent.obj
            )

        # Update component editability.
        container = getattr(self.source.parent, 'container', None)

        if container and hasattr(container, 'update_components_editability'):
            container.update_components_editability()

        # Save state for Undo/Redo.
        if container and hasattr(container, 'graphics'):
            container.graphics.push_snapshot()

        print("[DEBUG] Partial line successfully reconnected.")
        return True

    @property
    def pointA(self):
        return self._pointA
 
    @pointA.setter
    def pointA(self, point):
        self._pointA = point
        self.updatePath()
 
    @property
    def pointB(self):
        return self._pointB
 
    @pointB.setter
    def pointB(self, point):
        self._pointB = point
        self.updatePath()
 
    @property
    def source(self):
        return self._source
 
    @source.setter
    def source(self, widget):
        self._source = widget
 
    @property
    def target(self):
        return self._target
 
    @target.setter
    def target(self, widget):
        self._target = widget

    def __delete__(self,instance):
        del self._source
        del self._target
        del self._pointA
        del self._pointB

class NodeSocket(QtWidgets.QGraphicsItem):
    def __init__(self, rect, parent, socketType, id):
        super(NodeSocket, self).__init__(parent)
        self.rect = rect
        self.type = socketType
        self.parent=parent
        self.id = id
        self.setAcceptHoverEvents(True)
        self.new_line=None
        self.other_line=None
    
        # Brush
        self.brush = QtGui.QBrush(Qt.transparent)
        # Pen
        self.pen = QtGui.QPen(Qt.NoPen)

        # Lines
        self.out_lines = []
        self.in_lines = []
        
    def shape(self):
        path = QtGui.QPainterPath()
        path.addEllipse(self.boundingRect())
        return path
 
    def boundingRect(self):
        return QtCore.QRectF(self.rect)

    def paint(self, painter, option, widget):
        painter.setPen(self.pen)
    
        # Outer ellipse
        painter.drawEllipse(
            int(self.rect.x()),
            int(self.rect.y()),
            int(self.rect.height()),
            int(self.rect.width())
        )

        painter.setBrush(self.brush)

        # Inner ellipse
        painter.drawEllipse(
            int(self.rect.x() + 2),
            int(self.rect.y() + 2),
            int((self.rect.height() / 3) * 2),
            int((self.rect.width() / 3) * 2)
        )
        
    def mousePressEvent(self, event):
        cursor = QCursor( Qt.ArrowCursor )
        QApplication.instance().setOverrideCursor(cursor)

        if self.type == 'op'and len(self.out_lines) == 0:
            rect = self.boundingRect()
            pointA = QtCore.QPointF(rect.x() + rect.width()/(2), rect.y() + rect.height()/(2))
            pointA = self.mapToScene(pointA)
            pointB = self.mapToScene(event.pos())
            self.new_line = NodeLine(pointA, pointB ,'op')
            self.out_lines.append(self.new_line)
            self.scene().addItem(self.new_line)    
            event.accept()
        elif self.type == 'in' and len(self.in_lines) == 0:
            rect = self.boundingRect()
            pointA = self.mapToScene(event.pos())
            pointB = QtCore.QPointF(rect.x() + rect.width()/(2), rect.y() + rect.height()/(2))
            pointB = self.mapToScene(pointB)
            self.new_line = NodeLine(pointA, pointB, 'in')
            self.in_lines.append(self.new_line)
            self.scene().addItem(self.new_line)
            event.accept()
        else:
            super(NodeSocket, self).mousePressEvent(event)

    def mouseMoveEvent(self, event):
        try:
            if self.type == 'op':
                # Get the item under cursor
                item = self.scene().itemAt(event.scenePos().toPoint(), QtGui.QTransform())

                # Cursor feedback when hovering over a socket
                if isinstance(item, NodeSocket):
                    QApplication.instance().setOverrideCursor(QCursor(Qt.PointingHandCursor))
                else:
                    QApplication.instance().restoreOverrideCursor()
                    QApplication.instance().setOverrideCursor(QCursor(Qt.ArrowCursor))

                # Update connection line endpoint safely
                if hasattr(self, "new_line") and self.new_line:
                    pointB = self.mapToScene(event.pos())
                    self.new_line.pointB = pointB
                if hasattr(self, "other_line") and self.other_line:
                    pointB = self.mapToScene(event.pos())
                    self.other_line.pointB = pointB

            elif self.type == 'in':
                # Update input socket side connection line
                if hasattr(self, "new_line") and self.new_line:
                    pointA = self.mapToScene(event.pos())
                    self.new_line.pointA = pointA
                if hasattr(self, "other_line") and self.other_line:
                    pointA = self.mapToScene(event.pos())
                    self.other_line.pointA = pointA

            else:
                super(NodeSocket, self).mouseMoveEvent(event)

        except Exception as e:
            print(f"[DEBUG] mouseMoveEvent error: {e}")


    def mouseReleaseEvent(self, event):
        cursor = QCursor(Qt.ArrowCursor)
        QApplication.instance().setOverrideCursor(cursor)

        item = None

        # Find the actual socket under the mouse, ignoring NodeLine markers.
        for scene_item in self.scene().items(event.scenePos()):
            if isinstance(scene_item, NodeSocket) and scene_item is not self:
                item = scene_item
                break
        stm = ['MaterialStream', 'EngStm']

        item_type = getattr(item, 'type', None)
        item_in_lines = getattr(item, 'in_lines', [])
        item_out_lines = getattr(item, 'out_lines', [])

        try:
            # Case 1: self.type == 'op' and item is input socket
            if item is not None and self.type == 'op' and item_type == 'in' and len(item_in_lines) == 0:
                self.new_line.source = self
                self.new_line.target = item
                item_in_lines.append(self.new_line)
                self.new_line.pointB = item.get_center()

                # Connect the two components logically
                if getattr(self.new_line.source.parent.obj, 'type', None) not in stm:
                    self.new_line.source.parent.obj.add_connection(0, self.new_line.source.id, self.new_line.target.parent.obj)
                if getattr(self.new_line.target.parent.obj, 'type', None) not in stm:
                    self.new_line.target.parent.obj.add_connection(1, self.new_line.target.id, self.new_line.source.parent.obj)

                if hasattr(self, "parent") and hasattr(self.parent, "container") and self.parent.container:
                    if hasattr(self.parent.container, "update_components_editability"):
                        self.parent.container.update_components_editability()

                try:
                    self.parent.container.graphics.push_snapshot()
                    print("[DEBUG] Snapshot pushed after socket connection (Case 1)")
                except Exception as e:
                    print("[DEBUG] socket connection push error (Case 1):", e)

                try:
                    target_node = self.new_line.target.parent

                    if (
                        getattr(target_node.obj, "type", None) == "Splitter"
                        and hasattr(target_node.dock_widget, "auto_distribute_from_input")
                    ):
                        target_node.dock_widget.auto_distribute_from_input()

                except Exception as e:
                    print("[DEBUG] Splitter flow auto-update failed:", e)

                # Update Splitter output names immediately after connection
                try:
                    source_node = self.new_line.source.parent

                    if (
                        getattr(source_node.obj, "type", None) == "Splitter"
                        and hasattr(source_node.dock_widget, "update_connected_component_names")
                    ):
                        QTimer.singleShot(
                            0,
                            source_node.dock_widget.update_connected_component_names
                        )

                except Exception as e:
                    print("[DEBUG] Splitter output name update failed:", e)


            # Case 2: self.type == 'in' and item is operation socket
            elif item is not None and self.type == 'in' and item_type == 'op' and len(item_out_lines) == 0:
                self.new_line.source = item
                self.new_line.target = self
                item_out_lines.append(self.new_line)
                self.new_line.pointA = item.get_center()

                if getattr(self.new_line.source.parent.obj, 'type', None) not in stm:
                    self.new_line.source.parent.obj.add_connection(0, self.new_line.source.id, self.new_line.target.parent.obj)
                if getattr(self.new_line.target.parent.obj, 'type', None) not in stm:
                    self.new_line.target.parent.obj.add_connection(1, self.new_line.target.id, self.new_line.source.parent.obj)

                if hasattr(self, "parent") and hasattr(self.parent, "container") and self.parent.container:
                    if hasattr(self.parent.container, "update_components_editability"):
                        self.parent.container.update_components_editability()

                try:
                    self.parent.container.graphics.push_snapshot()
                    print("[DEBUG] Snapshot pushed after socket connection (Case 2)")
                except Exception as e:
                    print("[DEBUG] socket connection push error (Case 2):", e)

                try:
                    target_node = self.new_line.target.parent

                    if (
                        getattr(target_node.obj, "type", None) == "Splitter"
                        and hasattr(target_node.dock_widget, "auto_distribute_from_input")
                    ):
                        target_node.dock_widget.auto_distribute_from_input()

                except Exception as e:
                    print("[DEBUG] Splitter flow auto-update failed:", e)

                # Update Splitter output names immediately after connection
                try:
                    source_node = self.new_line.source.parent

                    if (
                        getattr(source_node.obj, "type", None) == "Splitter"
                        and hasattr(source_node.dock_widget, "update_connected_component_names")
                    ):
                        QTimer.singleShot(
                            0,
                            source_node.dock_widget.update_connected_component_names
                        )

                except Exception as e:
                    print("[DEBUG] Splitter output name update failed:", e)


            # Case 3: clicked empty space or invalid target
            else:
                self.scene().removeItem(self.new_line)
                if hasattr(self, 'in_lines') and self.new_line in self.in_lines:
                    self.in_lines.remove(self.new_line)
                if hasattr(self, 'out_lines') and self.new_line in self.out_lines:
                    self.out_lines.remove(self.new_line)
                del self.new_line
                super(NodeSocket, self).mouseReleaseEvent(event)

        except Exception as e:
            print("[DEBUG] mouseReleaseEvent error:", e)
            
    def get_center(self):
        rect = self.boundingRect()
        center = QtCore.QPointF(rect.x() + rect.width()/(2), rect.y() + rect.height()/(2))
        center = self.mapToScene(center)
        return center

    def hoverEnterEvent(self, event):
        cursor = QCursor( Qt.PointingHandCursor)
        QApplication.instance().setOverrideCursor(cursor)     
    
    def hoverLeaveEvent(self, event):
        cursor = QCursor( Qt.ArrowCursor )
        QApplication.instance().setOverrideCursor(cursor)

    def show(self):
        # set pen to show
        self.pen = QPen(QtGui.QColor(0,70,70,220), 1, Qt.SolidLine)
        self.brush = QBrush(QtGui.QColor(140,199,198,255))

    def hide(self):
        # set pen to transparent
        self.pen = QPen(Qt.NoPen)
        self.brush = QBrush(Qt.transparent)

# all created node items will be put inside this list 
# it is used for recreating the node lines by returning the node item object based on unit operation object's name 
lst = []
dock_widget_lst = []
stack = []


class ResizeHandle(QtWidgets.QGraphicsItem):
    """Drag handle at the bottom-right corner of a NodeItem for resizing."""

    def __init__(self, parent_node):
        super().__init__(parent_node)
        self.parent_node = parent_node
        self.setAcceptHoverEvents(True)
        self.setCursor(Qt.SizeFDiagCursor)
        self._size = 12
        self._dragging = False
        self._start_pos = None
        self._start_width = 0
        self._start_height = 0

    def boundingRect(self):
        return QtCore.QRectF(0, 0, self._size, self._size)

    def paint(self, painter, option, widget):
        pen = QtGui.QPen(QtGui.QColor(100, 100, 100, 180), 1.5)
        painter.setPen(pen)
        s = self._size
        for i in range(3):
            offset = 3 + i * 3
            painter.drawLine(int(s - offset), int(s), int(s), int(s - offset))

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self._dragging = True
            self._start_pos = event.scenePos()
            self._start_width = self.parent_node.rect.width()
            self._start_height = self.parent_node.rect.height()
            event.accept()
        else:
            super().mousePressEvent(event)

    def mouseMoveEvent(self, event):
        if self._dragging:
            delta = event.scenePos() - self._start_pos
            new_w = max(40, self._start_width + delta.x())
            new_h = max(40, self._start_height + delta.y())
            self.parent_node.resize_node(new_w, new_h)
            event.accept()
        else:
            super().mouseMoveEvent(event)


    def _try_reconnect(self, scene_pos):
        """Reconnect a partial line to a compatible free socket."""

        if self.source is not None and self.target is not None:
            return False

        candidate = None

        # Check all items at the drop position, topmost first.
        for item in self.scene().items(scene_pos):
            if isinstance(item, NodeSocket):
                candidate = item
                break

        if candidate is None:
            return False

        stm = ['MaterialStream', 'EngStm']

        # Free destination: attached source -> compatible input socket.
        if self.source is not None and self.target is None:
            if candidate.type != 'in' or candidate.in_lines:
                return False

            if candidate.parent is self.source.parent:
                return False

            self.target = candidate
            candidate.in_lines.append(self)
            self.pointB = candidate.get_center()

        # Free source: compatible output socket -> attached target.
        elif self.source is None and self.target is not None:
            if candidate.type != 'op' or candidate.out_lines:
                return False

            if candidate.parent is self.target.parent:
                return False

            self.source = candidate
            candidate.out_lines.append(self)
            self.pointA = candidate.get_center()

        else:
            return False

        # Restore logical component connections.
        if self.source.parent.obj.type not in stm:
            self.source.parent.obj.add_connection(
                0, self.source.id, self.target.parent.obj
            )

        if self.target.parent.obj.type not in stm:
            self.target.parent.obj.add_connection(
                1, self.target.id, self.source.parent.obj
            )

        # Update component editability.
        attached_node = self.source.parent
        container = getattr(attached_node, 'container', None)

        if container and hasattr(container, 'update_components_editability'):
            container.update_components_editability()

        # Save the new state for Undo/Redo.
        if container and hasattr(container, 'graphics'):
            container.graphics.push_snapshot()

        print("[DEBUG] Partial line successfully reconnected.")
        return True


    def mouseReleaseEvent(self, event):
        if self._dragging_free_endpoint:
            self._dragging_free_endpoint = False

            scene_pos = event.scenePos()
            self._try_reconnect(scene_pos)

            event.accept()
            return

        event.ignore()


class NodeItem(QtWidgets.QGraphicsItem):

    @staticmethod
    def get_instances(namee):
        for i in lst:
            if i.name == namee:
                return i

    @staticmethod
    def get_dock_widget():
        return dock_widget_lst

    def __init__(self, unit_operation, container, graphicsView):
        super(NodeItem, self).__init__()

        # ✅ Always define these lists at the top (warnings fixed)
        unit_ops = ['Splitter', 'Mixer', 'DistillationColumn', 'Flash', 'CompoundSeparator', 'ShortcutColumn']
        streams = ['MaterialStream', 'EnergyStream']

        # ✅ Basic references
        self.obj = unit_operation
        self.container = container
        self.graphicsView = graphicsView
        self.setAcceptHoverEvents(True)
        self.name = self.obj.name
        self.type = self.obj.type
        self.ok = True

        # ✅ Tooltip setup
        if self.obj.modes_list:
            default_tooltip = f"{self.name}\n\n"
            default_tooltip_dict = self.obj.param_getter_tooltip(self.obj.mode)
            for k, v in default_tooltip_dict.items():
                if v is not None:
                    default_tooltip += f"   {k} : {v}\n"
            self.setToolTip(default_tooltip)

        # ✅ Mixer: use default 2 inputs for new components (no prompt)
        if self.obj.type == 'Mixer' and not getattr(self.obj, "saved", False):
            self.nin = 2
            self.obj.no_of_inputs = self.nin
            self.obj.variables['NI']['value'] = self.nin

        # ✅ Distillation Column: use default 1 input for new components (no prompt)
        elif self.obj.type == 'DistillationColumn' and not getattr(self.obj, "saved", False):
            self.nin = 1
            self.obj.no_of_inputs = self.nin
            self.obj.variables['Ni']['value'] = self.nin

        # ✅ Default input/output counts
        self.nin = getattr(self.obj, "no_of_inputs", 0)
        self.nop = getattr(self.obj, "no_of_outputs", 0)

        # ✅ Dock widget creation
        self.dock_widget = None
        lst.append(self)

        if self.obj.type in unit_ops:
            self.dock_widget = eval(f"DockWidget{self.obj.type}")(self.obj.name, self.obj.type, self.obj, self.container)
        elif self.obj.type in streams:
            self.dock_widget = eval(f"DockWidget{self.obj.type}")(self.obj.name, self.obj.type, self.obj, self.container)
        elif self.obj.type in ["AdiabaticCompressor", "AdiabaticExpander"]:
            self.dock_widget = DockWidgetCompressorExpander(self.obj.name, self.obj.type, self.obj, self.container)
        else:
            self.dock_widget = DockWidget(self.obj.name, self.obj.type, self.obj, self.container)

        dock_widget_lst.append(self.dock_widget)
        self.dock_widget.node_item = self
        self.main_window = findMainWindow(self)
        # self.dock_widget.setFixedWidth(360)
        # self.dock_widget.setFixedHeight(640)
        self.dock_widget.setMinimumSize(220, 250)
        self.dock_widget.setSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        self.dock_widget.setFeatures(QDockWidget.AllDockWidgetFeatures)
        if self.main_window is not None and hasattr(self.main_window, 'addDockWidget'):
            self.main_window.addDockWidget(Qt.LeftDockWidgetArea, self.dock_widget)

        # ✅ Update parameters safely (skip MaterialStream)
        if self.dock_widget.obj.type != 'MaterialStream':
            try:
                params = self.dock_widget.obj.param_getter(self.dock_widget.obj.mode)
                self.dock_widget.obj.param_setter(params)
            except Exception as e:
                print("[DEBUG] Parameter update failed:", e)

        self.dock_widget.hide()

        # ✅ Graphics setup
        self.pic = QtGui.QPixmap(parentPath + f"/resources/base/icons/{self.type}.png")
        self.svg_renderer = get_svg_renderer(self.type)
        self.rect = QtCore.QRect(0, 0, self.pic.width(), self.pic.height())

        self.text = QGraphicsTextItem(self)
        font = QFont()
        font.setPointSize(8)
        self.text.setFont(font)
        self.text.setDefaultTextColor(QtGui.QColor(0, 70, 70, 220))
        self.text.setParentItem(self)
        self.text.setPos(self.rect.width() * 0.1, self.rect.height())
        self.text.setPlainText(self.name)

        # ✅ Interaction flags
        self.setFlag(QtWidgets.QGraphicsPixmapItem.ItemIsMovable)
        self.setFlag(QtWidgets.QGraphicsPixmapItem.ItemIsSelectable)
        self.setFlag(QGraphicsItem.ItemSendsGeometryChanges)

        # ✅ Brushes and pens
        self.brush = QtGui.QBrush(QtCore.Qt.SolidPattern)
        self.brush.setColor(QtGui.QColor(80, 0, 90, 255))

        self.pen = QtGui.QPen(QtCore.Qt.SolidLine)
        self.pen.setWidth(1)
        self.pen.setColor(QtGui.QColor(20, 20, 20, 255))

        self.sel_pen = QtGui.QPen(QtCore.Qt.SolidLine)
        self.sel_pen.setWidth(1)
        self.sel_pen.setColor(QtGui.QColor(220, 220, 220, 255))

        # ✅ Initialize sockets (ports)
        self.input, self.output = self.initialize_sockets(self.type)

        # Store original dimensions for resize support
        self._orig_pic = self.pic.copy()
        self._capture_socket_geometry()

        # Add resize handle at bottom-right corner
        self._resize_handle = ResizeHandle(self)
        self._resize_handle.setPos(self.rect.width() - 12, self.rect.height() - 12)
        self._resize_handle.setZValue(1)


    def shape(self):
        path = QtGui.QPainterPath()
        path.addRect(self.boundingRect())
        return path
 
    def boundingRect(self):
        return QtCore.QRectF(self.rect)
 
    def paint(self, painter, option, widget):
        painter.setRenderHint(QtGui.QPainter.SmoothPixmapTransform, True)
        painter.setRenderHint(QtGui.QPainter.Antialiasing, True)
        if self.isSelected():
            painter.setPen(self.sel_pen)
            painter.drawRect(QtCore.QRectF(self.rect))
        else:
            painter.setPen(self.pen)
        if self.svg_renderer is not None:
            # Vector art is re-rasterized at the current size every paint -> crisp.
            self.svg_renderer.render(painter, QtCore.QRectF(self.rect))
        else:
            painter.drawPixmap(self.rect, self.pic)

    def initialize_sockets(self, type):
        if self.type in ["Flash", "CompoundSeparator"]:
            input = [
                NodeSocket(
                    QtCore.QRect(
                        1,
                        int(self.rect.height() * x / (self.nin + 1) - 6),
                        12, 12
                    ),
                    self, 'in', x
                )
                for x in range(1, self.nin + 1)
            ]
            output = [
                NodeSocket(
                    QtCore.QRect(
                        int(self.rect.width() - 13),
                        int(self.rect.height() * x / (self.nop + 1) - 4),
                        12, 12
                    ),
                    self, 'op', x
                )
                for x in range(1, self.nop + 1)
            ]
            return input, output

        elif self.type in ["AdiabaticCompressor", "AdiabaticExpander", "Mixer", "Splitter", "Valve"]:
            input = [
                NodeSocket(
                    QtCore.QRect(
                        int(-6.5),
                        int(self.rect.height() * x / (self.nin + 1) - 6),
                        12, 12
                    ),
                    self, 'in', x
                )
                for x in range(1, self.nin + 1)
            ]
            output = [
                NodeSocket(
                    QtCore.QRect(
                        int(self.rect.width() - 6.5),
                        int(self.rect.height() * x / (self.nop + 1) - 6),
                        12, 12
                    ),
                    self, 'op', x
                )
                for x in range(1, self.nop + 1)
            ]
            return input, output

        elif self.type in ["Cooler", "Heater"]:
            input = [
                NodeSocket(
                    QtCore.QRect(
                        int(-0.5),
                        int(self.rect.height() * x / (self.nin + 1) - 6),
                        12, 12
                    ),
                    self, 'in', x
                )
                for x in range(1, self.nin + 1)
            ]
            output = [
                NodeSocket(
                    QtCore.QRect(
                        int(self.rect.width() - 12.0),
                        int(self.rect.height() * x / (self.nop + 1) - 6),
                        12, 12
                    ),
                    self, 'op', x
                )
                for x in range(1, self.nop + 1)
            ]
            return input, output

        elif self.type == "CentrifugalPump":
            input = [
                NodeSocket(
                    QtCore.QRect(
                        int(-6.5),
                        int(self.rect.height() * x / (self.nin + 1) - 11),
                        12, 12
                    ),
                    self, 'in', x
                )
                for x in range(1, self.nin + 1)
            ]
            output = [
                NodeSocket(
                    QtCore.QRect(
                        int(self.rect.width() - 6.5),
                        int(-5.5),
                        12, 12
                    ),
                    self, 'op', x
                )
                for x in range(1, self.nop + 1)
            ]
            return input, output

        elif self.type in ["DistillationColumn", "ShortcutColumn"]:
            input = [
                NodeSocket(
                    QtCore.QRect(
                        int(-6.5),
                        int(self.rect.height() * x / (self.nin + 1) - 4),
                        12, 12
                    ),
                    self, 'in', x
                )
                for x in range(1, self.nin + 1)
            ]
            output = [
                NodeSocket(
                    QtCore.QRect(
                        int(self.rect.width() - 9.5),
                        int(self.rect.height() * 1.44 * x / (self.nop + 1) - 59),
                        12, 12
                    ),
                    self, 'op', x
                )
                for x in range(1, self.nop + 1)
            ]
            return input, output

        elif self.type == "MaterialStream":
            input = [
                NodeSocket(
                    QtCore.QRect(
                        int(-6.5),
                        int(self.rect.height() * x / (self.nin + 1) - 6),
                        12, 12
                    ),
                    self, 'in', x
                )
                for x in range(1, self.nin + 1)
            ]
            output = [
                NodeSocket(
                    QtCore.QRect(
                        int(self.rect.width() - 6.5),
                        int(self.rect.height() * x / (self.nin + 1) - 6),
                        12, 12
                    ),
                    self, 'op', x
                )
                for x in range(1, self.nop + 1)
            ]
            return input, output

    def resize_node(self, new_width, new_height):
        """Resize the node to the given width and height."""
        self.prepareGeometryChange()

        # Update rect
        self.rect = QtCore.QRect(0, 0, int(new_width), int(new_height))

        # Scale pixmap from the original for best quality
        self.pic = self._orig_pic.scaled(
            int(new_width), int(new_height),
            Qt.IgnoreAspectRatio, Qt.SmoothTransformation
        )

        # Reposition label below the node
        self.text.setPos(self.rect.width() * 0.1, self.rect.height())

        # Reposition sockets proportionally
        self._reposition_sockets()

        # Move resize handle to new bottom-right
        self._resize_handle.setPos(self.rect.width() - 12, self.rect.height() - 12)

        # Update all connected lines
        self._update_connected_lines()

        self.update()

        if hasattr(self, "container") and self.container is not None and hasattr(self.container, "update_components_editability"):
            self.container.update_components_editability()

    def _reposition_sockets(self):
        """Reposition sockets after a resize while keeping their relative
        positions on the component.

        Each socket's *centre* is kept at the same fraction of the component
        height it had originally, and the socket keeps its fixed size. Scaling
        the centre (rather than the top-left corner) avoids amplifying the
        small centring offsets baked into the original rects, which otherwise
        made the ports drift further off as the component grew.
        """
        new_height = self.rect.height()
        new_width = self.rect.width()
        orig_height = self._orig_height if self._orig_height else 1

        for i, socket in enumerate(self.input):
            if i < len(self._orig_input_rects):
                orig = self._orig_input_rects[i]
                frac_y = (orig.y() + orig.height() / 2) / orig_height
                new_cy = frac_y * new_height
                # x stays anchored to the left edge
                socket.prepareGeometryChange()
                socket.rect = QtCore.QRectF(
                    orig.x(),
                    new_cy - orig.height() / 2,
                    orig.width(), orig.height()
                )
                socket.update()

        for i, socket in enumerate(self.output):
            if i < len(self._orig_output_rects):
                orig = self._orig_output_rects[i]
                frac_y = (orig.y() + orig.height() / 2) / orig_height
                new_cy = frac_y * new_height
                # x stays anchored to the right edge
                right_offset = self._orig_width - orig.x()
                socket.prepareGeometryChange()
                socket.rect = QtCore.QRectF(
                    new_width - right_offset,
                    new_cy - orig.height() / 2,
                    orig.width(), orig.height()
                )
                socket.update()

    def _capture_socket_geometry(self):
        """Use the current size and socket rects as the reference for
        _reposition_sockets. Must be called whenever sockets are rebuilt,
        since rebuilt sockets are laid out at the current (possibly resized)
        size, not the original one."""
        self._orig_width = self.rect.width()
        self._orig_height = self.rect.height()
        self._orig_input_rects = [QtCore.QRectF(s.rect) for s in self.input]
        self._orig_output_rects = [QtCore.QRectF(s.rect) for s in self.output]

    def _update_connected_lines(self):
        """Update endpoints of all lines connected to this node."""
        for inp in self.input:
            for line in inp.in_lines:
                line.pointB = inp.get_center()
        for op in self.output:
            for line in op.out_lines:
                line.pointA = op.get_center()

    def mousePressEvent(self, event):
        self._press_scene_pos = self.scenePos()
        super(NodeItem, self).mousePressEvent(event)

    def mouseReleaseEvent(self, event):
        super(NodeItem, self).mouseReleaseEvent(event)
        try:
            start = getattr(self, "_press_scene_pos", None)
            if start is not None and self.scenePos() != start:
                self.obj.set_pos(self.scenePos())
                if self.container is not None and hasattr(self.container, "graphics"):
                    self.container.graphics.push_snapshot()
        except Exception as e:
            print("[DEBUG] NodeItem.mouseReleaseEvent push failed:", e)
        finally:
            self._press_scene_pos = None

    def mouseMoveEvent(self, event):
        super(NodeItem, self).mouseMoveEvent(event)

        # Update node position in model object (if linked)
        self.current_pos = event.scenePos()
        if hasattr(self, "obj") and self.obj is not None:
            self.obj.set_pos(self.current_pos)


    def update_input_ports(self, new_count):
        """Dynamically change the number of input sockets while preserving
        existing connections.

        When the input count is reduced, connected streams are compacted
        from left to right instead of simply deleting connections attached
        to removed sockets.
        """

        old_count = len(self.input)

        if new_count == old_count:
            return

        # ------------------------------------------------------------
        # 1. Save existing connections in their current socket order
        # ------------------------------------------------------------
        saved_connections = []

        for socket in self.input:
            if socket.in_lines:
                line = socket.in_lines[0]

                source_socket = getattr(line, "source", None)

                if source_socket is not None:
                    saved_connections.append({
                        "source_socket": source_socket,
                        "source_obj": source_socket.parent.obj,
                    })

        print(
            f"[DEBUG] update_input_ports: "
            f"{old_count} -> {new_count}, "
            f"connected inputs={len(saved_connections)}"
        )

        # ------------------------------------------------------------
        # 2. Remove all existing input connections cleanly
        # ------------------------------------------------------------
        for socket in self.input:
            for line in list(socket.in_lines):

                source_socket = getattr(line, "source", None)

                # Remove line from source socket
                if source_socket is not None:
                    if line in source_socket.out_lines:
                        source_socket.out_lines.remove(line)

                    # Remove logical connection from source object
                    try:
                        if getattr(source_socket.parent.obj, "type", None) not in [
                            "MaterialStream",
                            "EngStm"
                        ]:
                            source_socket.parent.obj.remove_connection(
                                0,
                                source_socket.id
                            )
                    except Exception as e:
                        print(
                            "[DEBUG] update_input_ports: "
                            f"source connection cleanup failed: {e}"
                        )

                # Remove logical connection from this input socket
                try:
                    if getattr(self.obj, "type", None) not in [
                        "MaterialStream",
                        "EngStm"
                    ]:
                        self.obj.remove_connection(
                            1,
                            socket.id
                        )
                except Exception as e:
                    print(
                        "[DEBUG] update_input_ports: "
                        f"target connection cleanup failed: {e}"
                    )

                # Remove line from scene
                if self.scene() is not None:
                    self.scene().removeItem(line)

            socket.in_lines.clear()

        # ------------------------------------------------------------
        # 3. Remove old input sockets
        # ------------------------------------------------------------
        for socket in self.input:
            if self.scene() is not None:
                self.scene().removeItem(socket)

        self.input.clear()

        # ------------------------------------------------------------
        # 4. Create the new input sockets
        # ------------------------------------------------------------
        for idx in range(1, new_count + 1):

            socket = NodeSocket(
                QtCore.QRect(
                    int(-6.5),
                    int(
                        self.rect.height() * idx /
                        (new_count + 1) - 6
                    ),
                    12,
                    12
                ),
                self,
                "in",
                idx
            )

            self.input.append(socket)

        # ------------------------------------------------------------
        # 5. Update input count
        # ------------------------------------------------------------
        self.nin = new_count
        self.obj.no_of_inputs = new_count

        if hasattr(self.obj, "variables") and "NI" in self.obj.variables:
            self.obj.variables["NI"]["value"] = new_count

        # ------------------------------------------------------------
        # 6. Restore connections sequentially
        #
        # Example:
        #
        # Old:
        #   input1 <- MS1
        #   input3 <- MS2
        #   input5 <- MS3
        #
        # New count = 3
        #
        # New:
        #   input1 <- MS1
        #   input2 <- MS2
        #   input3 <- MS3
        # ------------------------------------------------------------
        for new_idx, connection in enumerate(
            saved_connections[:new_count],
            start=1
        ):

            if new_idx > len(self.input):
                break

            target_socket = self.input[new_idx - 1]
            source_socket = connection["source_socket"]

            # Create new visual connection
            line = NodeLine(
                source_socket.get_center(),
                target_socket.get_center(),
                "op"
            )

            line.source = source_socket
            line.target = target_socket

            # Register line on both sockets
            source_socket.out_lines.append(line)
            target_socket.in_lines.append(line)

            # Add line to scene
            if self.scene() is not None:
                self.scene().addItem(line)

            line.pointA = source_socket.get_center()
            line.pointB = target_socket.get_center()

            # Restore logical connection
            try:
                if getattr(source_socket.parent.obj, "type", None) not in [
                    "MaterialStream",
                    "EngStm"
                ]:
                    source_socket.parent.obj.add_connection(
                        0,
                        source_socket.id,
                        self.obj
                    )

                if getattr(self.obj, "type", None) not in [
                    "MaterialStream",
                    "EngStm"
                ]:
                    self.obj.add_connection(
                        1,
                        target_socket.id,
                        source_socket.parent.obj
                    )

            except Exception as e:
                print(
                    "[DEBUG] update_input_ports: "
                    f"connection restore failed: {e}"
                )

            print(
                f"[DEBUG] Restored connection: "
                f"{source_socket.parent.obj.name}"
                f"[out:{source_socket.id}] -> "
                f"{self.obj.name}"
                f"[in:{target_socket.id}]"
            )

        # ------------------------------------------------------------
        # 7. Update original socket geometry
        # ------------------------------------------------------------
        self._capture_socket_geometry()

        # ------------------------------------------------------------
        # 8. Update connected lines
        # ------------------------------------------------------------
        self._update_connected_lines()

        self.update()

        if hasattr(self, "container") and self.container is not None and hasattr(self.container, "update_components_editability"):
            self.container.update_components_editability()

        print(
            f"[DEBUG] update_input_ports complete: "
            f"{old_count} -> {new_count}"
        )


    def update_output_ports(self, new_count):


        """
        Dynamically change the number of output sockets.

        Existing connections are preserved whenever possible.
        If output count is reduced, connections attached to
        removed outputs are removed cleanly.
        """

        print("OUTPUT DEBUG")

        for i, socket in enumerate(self.output):

            print(
                "socket",
                i+1,
                "id=",
                socket.id,
                "out_lines=",
                len(socket.out_lines)
            )

        old_count = len(self.output)

        if new_count < 2:
            new_count = 2

        if new_count > 6:
            new_count = 6

        if new_count == old_count:
            self.nop = new_count
            self.obj.no_of_outputs = new_count
            return

        # ---------------------------------------------------------
        # 1. Save existing output connections
        # ---------------------------------------------------------

        saved_connections = []

        for socket in self.output:

            for line in list(socket.out_lines):

                target_socket = getattr(
                    line,
                    "target",
                    None
                )

                if target_socket is not None:

                    saved_connections.append({
                        "source_id": socket.id,
                        "target_socket": target_socket,
                        "target_obj": target_socket.parent.obj
                    })

                    break

        print(
            f"[DEBUG] update_output_ports: "
            f"{old_count} -> {new_count}, "
            f"connected outputs={len(saved_connections)}"
        )

        # ---------------------------------------------------------
        # 2. Remove existing output connections
        # ---------------------------------------------------------

        for socket in self.output:

            for line in list(socket.out_lines):

                target_socket = getattr(
                    line,
                    "target",
                    None
                )

                # Remove from target socket
                if target_socket is not None:

                    if line in target_socket.in_lines:
                        target_socket.in_lines.remove(line)

                    # Remove logical connection
                    try:

                        if getattr(
                            target_socket.parent.obj,
                            "type",
                            None
                        ) not in [
                            "MaterialStream",
                            "EngStm"
                        ]:

                            target_socket.parent.obj.remove_connection(
                                1,
                                target_socket.id
                            )

                    except Exception as e:

                        print(
                            "[DEBUG] "
                            "update_output_ports target cleanup failed:",
                            e
                        )

                # Remove logical connection from source
                try:

                    if getattr(
                        self.obj,
                        "type",
                        None
                    ) not in [
                        "MaterialStream",
                        "EngStm"
                    ]:

                        self.obj.remove_connection(
                            0,
                            socket.id
                        )

                except Exception as e:

                    print(
                        "[DEBUG] "
                        "update_output_ports source cleanup failed:",
                        e
                    )

                # Remove line from scene
                if self.scene() is not None:

                    self.scene().removeItem(
                        line
                    )

            socket.out_lines.clear()

        # ---------------------------------------------------------
        # 3. Remove old output sockets
        # ---------------------------------------------------------

        for socket in self.output:

            if self.scene() is not None:

                self.scene().removeItem(
                    socket
                )

        self.output.clear()

        # ---------------------------------------------------------
        # 4. Create new output sockets
        # ---------------------------------------------------------

        for idx in range(1, new_count + 1):

            socket = NodeSocket(
                QtCore.QRect(
                    int(self.rect.width() - 6.5),
                    int(
                        self.rect.height()
                        * idx
                        / (new_count + 1)
                        - 6
                    ),
                    12,
                    12
                ),
                self,
                "op",
                idx
            )

            self.output.append(
                socket
            )

        # ---------------------------------------------------------
        # 5. Update output count
        # ---------------------------------------------------------

        self.nop = new_count

        self.obj.no_of_outputs = new_count

        if hasattr(self.obj, "variables"):

            if "No" in self.obj.variables:

                self.obj.variables["No"]["value"] = new_count

        # ---------------------------------------------------------
        # 6. Restore old connections
        # ---------------------------------------------------------

        for connection in saved_connections:

            source_socket = self.output[
                connection["source_id"] - 1
            ] if connection["source_id"] <= new_count else None

            target_socket = connection[
                "target_socket"
            ]

            if source_socket is None:

                continue

            # Create new line
            line = NodeLine(
                source_socket.get_center(),
                target_socket.get_center(),
                "op"
            )

            line.source = source_socket
            line.target = target_socket

            source_socket.out_lines.append(
                line
            )

            target_socket.in_lines.append(
                line
            )

            if self.scene() is not None:

                self.scene().addItem(
                    line
                )

            line.pointA = source_socket.get_center()
            line.pointB = target_socket.get_center()

            # Restore logical connection
            try:

                if getattr(
                    source_socket.parent.obj,
                    "type",
                    None
                ) not in [
                    "MaterialStream",
                    "EngStm"
                ]:

                    source_socket.parent.obj.add_connection(
                        0,
                        source_socket.id,
                        target_socket.parent.obj
                    )

                if getattr(
                    target_socket.parent.obj,
                    "type",
                    None
                ) not in [
                    "MaterialStream",
                    "EngStm"
                ]:

                    target_socket.parent.obj.add_connection(
                        1,
                        target_socket.id,
                        source_socket.parent.obj
                    )

            except Exception as e:

                print(
                    "[DEBUG] "
                    "update_output_ports connection restore failed:",
                    e
                )

        # ---------------------------------------------------------
        # 7. Update original socket geometry
        # ---------------------------------------------------------

        self._capture_socket_geometry()

        # ---------------------------------------------------------
        # 8. Update connected lines
        # ---------------------------------------------------------

        self._update_connected_lines()

        self.update()

        if hasattr(self, "container") and self.container is not None and hasattr(self.container, "update_components_editability"):
            self.container.update_components_editability()

        print(
            f"[DEBUG] update_output_ports complete: "
            f"{old_count} -> {new_count}"
        )



    def mouseDoubleClickEvent(self, event):

        self.graphicsView.horizontalScrollBarVal = self.graphicsView.horizontalScrollBar().value()
        self.graphicsView.setInteractive(False)
        # Purge any destroyed widgets from the stack before accessing
        import sip
        while stack and sip.isdeleted(stack[-1]):
            stack.pop()
        if len(stack):
            stack[-1].hide()
        self.dock_widget.show()
        stack.append(self.dock_widget)
        self.graphicsView.setInteractive(True)

    def update_tooltip(self):
        default_tooltip = f"{self.name}\n\n"
        default_tooltip_dict = self.obj.param_getter_tooltip(self.obj.mode)
        for i, j in default_tooltip_dict.items():
            if j is not None:
                default_tooltip = default_tooltip + f"   {i} : {j}\n"
        self.setToolTip(default_tooltip)

    def update_tooltip_selectedVar(self):
        default_tooltip = f"{self.name}\n\n"
        default_tooltip_dict = self.obj.param_getter_tooltip_selectedVar()
        for i, j in default_tooltip_dict.items():
            if j is not None:
                default_tooltip = default_tooltip + f"   {i} : {j}\n"
        self.setToolTip(default_tooltip)

    def update_compounds(self):
        try:
            self.obj.update_compounds()
            self.dock_widget.update_compounds()
        except AttributeError:
            pass

    def hoverEnterEvent(self, event):
        super(NodeItem,self).hoverEnterEvent(event)
        for i in self.graphicsView.items():
            if(isinstance(i,NodeItem)):
                for ip in i.input:
                    ip.show()
                for op in i.output:
                    op.show()

    def hoverLeaveEvent(self, event):
        super(NodeItem,self).hoverLeaveEvent(event)
        for i in self.graphicsView.items():
            if(isinstance(i,NodeItem)):
                for ip in i.input:
                    ip.hide()
                for op in i.output:
                    op.hide()

    def itemChange(self, change, value):
        if change == self.ItemPositionChange and self.scene():
            newPos = value
            rect = self.container.graphicsView.sceneRect()
            width = self.boundingRect().width()
            height = self.boundingRect().height()
            eWH1 = QPointF(newPos.x() + width, newPos.y() + height)
            eWH2 = QPointF(newPos.x() - width, newPos.y() - height)
            if not rect.__contains__(eWH1) or not rect.__contains__(eWH2):
                newPos.setX(min(rect.right() - width - 40, max(newPos.x(), rect.left())))
                newPos.setY(min(rect.bottom() - height - 35, max(newPos.y(), rect.top())))
                self.obj.set_pos(newPos)
            return super(NodeItem, self).itemChange(change, newPos)

        if change == self.ItemPositionHasChanged and self.scene():
            self._update_connected_lines()

        return super(NodeItem, self).itemChange(change, value)

    
    def _reroute_material_stream(self, direction):
        """Disconnect one side of a Material Stream connection without deleting its line."""

        if self.type != "MaterialStream":
            return

        if direction == "destination":
            if not self.output or not self.output[0].out_lines:
                return

            line = self.output[0].out_lines[0]
            old_target = line.target
            old_source = line.source

            if old_target is None or old_source is None:
                return

            # Keep the free endpoint at the old destination position.
            free_point = old_target.get_center() + QtCore.QPointF(-30, 0)

            if line in old_target.in_lines:
                old_target.in_lines.remove(line)

            # Remove the old logical connection.
            stm = ["MaterialStream", "EngStm"]

            if old_source.parent.obj.type not in stm:
                old_source.parent.obj.remove_connection(0, old_source.id)

            if old_target.parent.obj.type not in stm:
                old_target.parent.obj.remove_connection(1, old_target.id)

            line.target = None
            line.pointB = free_point

        elif direction == "source":
            if not self.input or not self.input[0].in_lines:
                return

            line = self.input[0].in_lines[0]
            old_source = line.source
            old_target = line.target

            if old_source is None or old_target is None:
                return

            # Keep the free endpoint at the old source position.
            free_point = old_source.get_center() + QtCore.QPointF(30, 0)

            if line in old_source.out_lines:
                old_source.out_lines.remove(line)

            # Remove the old logical connection.
            stm = ["MaterialStream", "EngStm"]

            if old_source.parent.obj.type not in stm:
                old_source.parent.obj.remove_connection(0, old_source.id)

            if old_target.parent.obj.type not in stm:
                old_target.parent.obj.remove_connection(1, old_target.id)

            line.source = None
            line.pointA = free_point

        if self.container and hasattr(self.container, "update_components_editability"):
            self.container.update_components_editability()

       # Save the rerouted state for Undo/Redo.
        if self.container and hasattr(self.container, "graphics"):
            self.container.graphics.push_snapshot()

        print(f"[DEBUG] Material Stream {direction} disconnected.")


    def contextMenuEvent(self, event):
        menu = QMenu()

        reroute_destination_action = None
        reroute_source_action = None

        if self.type == "MaterialStream":
            reroute_destination_action = menu.addAction("Reroute Destination")
            reroute_source_action = menu.addAction("Reroute Source")

            # Show an action as disabled when that side is not connected.
            reroute_destination_action.setEnabled(
                bool(self.output and self.output[0].out_lines)
            )
            reroute_source_action.setEnabled(
                bool(self.input and self.input[0].in_lines)
            )

            menu.addSeparator()

        delete_action = menu.addAction("Delete")
        action = menu.exec_(event.screenPos())

        if action == reroute_destination_action:
            self._reroute_material_stream("destination")

        elif action == reroute_source_action:
            self._reroute_material_stream("source")

        elif action == delete_action:
            if hasattr(self, "container") and self.container:
                self.container.delete([self])
            else:
                main_window = findMainWindow(self)
                if main_window and hasattr(main_window, "container"):
                    main_window.container.delete([self])

        
def findMainWindow(self):
    '''
        Safely find the QMainWindow by navigating up the widget hierarchy from the graphicsView.
    ''' 
    if hasattr(self, 'graphicsView') and self.graphicsView is not None:
        return self.graphicsView.window()
    elif hasattr(self, 'container') and hasattr(self.container, 'graphicsView') and self.container.graphicsView is not None:
        return self.container.graphicsView.window()
    return None
