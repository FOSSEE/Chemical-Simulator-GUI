from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
from PyQt5.QtWidgets import QLineEdit
from PyQt5 import QtSvg
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

class Graphics(QDialog, QtWidgets.QGraphicsItem):

    def __init__(self, container, graphicsView=None):
        QDialog.__init__(self)
        QtWidgets.QGraphicsItem.__init__(self)

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
    
    def load_canvas(self, snapshot, container):
        """
        Rebuilds scene from snapshot created by save_canvas().
        """
        try:
            # Clear current scene
            self.scene.clear()
            self.unit_operations = []

            items = snapshot.get("items", [])

            for data in items:
                try:
                    comp_type = data.get("type")
                    name = data.get("name")
                    pos = data.get("pos", (0, 0))

                    # Create a new object based on its type
                    # (Assumes global class available: python.utils.Streams, UnitOperations, etc.)
                    module_path = f"python.utils.Streams.{comp_type}" if comp_type == "MaterialStream" else f"python.utils.UnitOperations.{comp_type}"

                    cls = None
                    try:
                        module = __import__(module_path, fromlist=[comp_type])
                        cls = getattr(module, comp_type)
                    except Exception:
                        print(f"[DEBUG] load_canvas: could not import {comp_type}")

                    if cls:
                        obj = cls()
                        obj.name = name
                        self.unit_operations.append(obj)

                        # Create its graphical node
                        box = self.create_node_item(obj, container)
                        box.setPos(*pos)
                        self.scene.addItem(box)
                except Exception as e:
                    print(f"[DEBUG] load_canvas: failed to rebuild {data.get('name', '?')} → {e}")

            # Restore optional data
            container.compounds = snapshot.get("compounds", [])
            container.result = snapshot.get("result", None)

            print(f"[DEBUG] load_canvas: reloaded {len(items)} items successfully")

        except Exception as e:
            print("[DEBUG] load_canvas failed:", e)


    def save_canvas(self):
        try:
            from python.utils.ComponentSelector import compound_selected

            data = {"items": [], "connections": [], "compounds": list(compound_selected)}

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
                if isinstance(item, NodeLine):
                    src = getattr(item, "source", None)
                    tgt = getattr(item, "target", None)
                    if src is not None and tgt is not None and src.parent is not None and tgt.parent is not None:
                        data["connections"].append({
                            "source_name": src.parent.obj.name,
                            "source_id": src.id,
                            "target_name": tgt.parent.obj.name,
                            "target_id": tgt.id,
                        })

            print(f"[DEBUG] save_canvas: {len(data['items'])} items, {len(data['connections'])} connections")
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

            self._restore_counters(container.unit_operations)

        except Exception as e:
            print("[DEBUG] Graphics.load_canvas_from_snapshot error:", e)


           
                            
class NodeLine(QtWidgets.QGraphicsPathItem):
    def __init__(self, pointA, pointB , socket):
        super(NodeLine, self).__init__()
        self._pointA = pointA
        self._pointB = pointB
        self.socket = socket
        self._source = None
        self._target = None
        self.setZValue(-1)
        self.setBrush(QtGui.QColor(0,70,70,120))
        self.pen = QtGui.QPen()
        self.pen.setStyle(QtCore.Qt.SolidLine)
        self.pen.setWidth(2)
        self.pen.setColor(QtGui.QColor(0,70,70,220))
        self.setPen(self.pen)

    def updatePath(self):

        if (self._pointB.x() - self._pointA.x()) < 30:
            path = QtGui.QPainterPath()
            midptx = (self.pointA.x() + 13)
    
            ctrl1_1 = QtCore.QPointF(self.pointA.x(), self.pointA.y())
            ctrl2_1 = QtCore.QPointF(self.pointA.x(), self.pointA.y())
            pt1 = QtCore.QPointF(midptx , self.pointA.y())
            path.moveTo(pt1)
            path.cubicTo(ctrl1_1, ctrl2_1, pt1) 

            if abs(self.pointB.x()-midptx) > 150:                
                ctrl1_2 = QtCore.QPointF(midptx, self.pointA.y())
                ctrl2_2 = QtCore.QPointF(midptx, self.pointA.y())
                pt2 = QtCore.QPointF(midptx , self.pointA.y()+100)
                path.cubicTo(ctrl1_2, ctrl2_2, pt2)
                path.moveTo(pt2)

                ctrl1_3 = QtCore.QPointF(midptx, self.pointA.y()+100)
                ctrl2_3 = QtCore.QPointF(midptx, self.pointA.y()+100)
                pt3 = QtCore.QPointF(self.pointB.x()-13, self.pointA.y()+100)
                path.cubicTo(ctrl1_3, ctrl2_3, pt3)
                path.moveTo(pt3)

                ctrl1_4 = QtCore.QPointF(self.pointB.x()-13, self.pointA.y()+100)
                ctrl2_4 = QtCore.QPointF(self.pointB.x()-13, self.pointA.y()+100)
                pt4 = QtCore.QPointF(self.pointB.x()-13, self.pointB.y())
                path.cubicTo(ctrl1_4, ctrl2_4, pt4)
                path.moveTo(pt4)

                ctrl1_5 = QtCore.QPointF(self.pointB.x()-13, self.pointB.y())
                ctrl2_5 = QtCore.QPointF(self.pointB.x()-13, self.pointB.y())
                pt5 = QtCore.QPointF(self.pointB.x(), self.pointB.y())
                path.cubicTo(ctrl1_5, ctrl2_5, pt5)
                path.moveTo(pt5)

                self.setPath(path)
                return
            else:
                ctrl1_2 = QtCore.QPointF(midptx, self.pointA.y())
                ctrl2_2 = QtCore.QPointF(midptx, self.pointA.y())
                pt2 = QtCore.QPointF(midptx , max(self.pointB.y(), self.pointA.y())-(abs(self.pointA.y()-self.pointB.y())/2))
                path.cubicTo(ctrl1_2, ctrl2_2, pt2)
                path.moveTo(pt2)

                ctrl1_3 = QtCore.QPointF(midptx, max(self.pointB.y(), self.pointA.y())-(abs(self.pointA.y()-self.pointB.y())/2))
                ctrl2_3 = QtCore.QPointF(midptx, max(self.pointB.y(), self.pointA.y())-(abs(self.pointA.y()-self.pointB.y())/2))
                pt3 = QtCore.QPointF(self.pointB.x()-13,  max(self.pointB.y(), self.pointA.y())-(abs(self.pointA.y()-self.pointB.y())/2))
                path.cubicTo(ctrl1_3, ctrl2_3, pt3)
                path.moveTo(pt3)

                ctrl1_4 = QtCore.QPointF(self.pointB.x()-13, max(self.pointB.y(), self.pointA.y())-(abs(self.pointA.y()-self.pointB.y())/2))
                ctrl2_4 = QtCore.QPointF(self.pointB.x()-13, max(self.pointB.y(), self.pointA.y())-(abs(self.pointA.y()-self.pointB.y())/2))
                pt4 = QtCore.QPointF(self.pointB.x()-13, self.pointB.y())
                path.cubicTo(ctrl1_4, ctrl2_4, pt4)
                path.moveTo(pt4)

                ctrl1_5 = QtCore.QPointF(self.pointB.x()-13, self.pointB.y())
                ctrl2_5 = QtCore.QPointF(self.pointB.x()-13, self.pointB.y())
                pt5 = QtCore.QPointF(self.pointB.x(), self.pointB.y())
                path.cubicTo(ctrl1_5, ctrl2_5, pt5)
                path.moveTo(pt5)

                self.setPath(path)
                return
        
        path = QtGui.QPainterPath()
        path.moveTo(self.pointA)
        midptx = 0.5*(self.pointA.x() + self.pointB.x())
 
        ctrl1_1 = QtCore.QPointF(self.pointA.x(), self.pointA.y())
        ctrl2_1 = QtCore.QPointF(self.pointA.x(), self.pointA.y())
        pt1 = QtCore.QPointF(midptx , self.pointA.y())
        path.cubicTo(ctrl1_1, ctrl2_1, pt1) 
        path.moveTo(pt1)

        ctrl1_2 = QtCore.QPointF(midptx, self.pointA.y())
        ctrl2_2 = QtCore.QPointF(midptx, self.pointA.y())
        pt2 = QtCore.QPointF(midptx , self.pointB.y())
        path.cubicTo(ctrl1_2, ctrl2_2, pt2)
        path.moveTo(pt2)

        ctrl1_3 = QtCore.QPointF(midptx, self.pointB.y())
        ctrl2_3 = QtCore.QPointF(midptx, self.pointB.y())
        path.cubicTo(ctrl1_3, ctrl2_3, self.pointB)
        path.moveTo(self.pointB)
        self.setPath(path)

    def paint(self, painter, option, widget):
        painter.setPen(self.pen)
        painter.drawPath(self.path())

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
        elif self.type == 'in' and len(self.in_lines) == 0:
            rect = self.boundingRect()
            pointA = self.mapToScene(event.pos())
            pointB = QtCore.QPointF(rect.x() + rect.width()/(2), rect.y() + rect.height()/(2))
            pointB = self.mapToScene(pointB)
            self.new_line = NodeLine(pointA, pointB, 'in')
            self.in_lines.append(self.new_line)
            self.scene().addItem(self.new_line)
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

        item = self.scene().itemAt(event.scenePos().toPoint(), QtGui.QTransform())
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

                sc = self.new_line.source.parent
                tg = self.new_line.target.parent
                if getattr(sc.obj, 'type', None) == 'MaterialStream':
                    if len(getattr(sc.input[0], 'in_lines', [])) > 0:
                        sc.obj.disableInputDataTab(sc.dock_widget)
                if getattr(tg.obj, 'type', None) == 'MaterialStream':
                    if len(getattr(tg.input[0], 'in_lines', [])) > 0:
                        tg.obj.disableInputDataTab(tg.dock_widget)

                try:
                    self.parent.container.graphics.push_snapshot()
                    print("[DEBUG] Snapshot pushed after socket connection (Case 1)")
                except Exception as e:
                    print("[DEBUG] socket connection push error (Case 1):", e)

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

                sc = self.new_line.source.parent
                tg = self.new_line.target.parent
                if getattr(sc.obj, 'type', None) == 'MaterialStream':
                    if len(getattr(sc.input[0], 'in_lines', [])) > 0:
                        sc.obj.disableInputDataTab(sc.dock_widget)
                if getattr(tg.obj, 'type', None) == 'MaterialStream':
                    if len(getattr(tg.input[0], 'in_lines', [])) > 0:
                        tg.obj.disableInputDataTab(tg.dock_widget)

                try:
                    self.parent.container.graphics.push_snapshot()
                    print("[DEBUG] Snapshot pushed after socket connection (Case 2)")
                except Exception as e:
                    print("[DEBUG] socket connection push error (Case 2):", e)

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

    def mouseReleaseEvent(self, event):
        if self._dragging:
            self._dragging = False
            event.accept()
        else:
            super().mouseReleaseEvent(event)


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
        self.main_window = findMainWindow(self)
        # self.dock_widget.setFixedWidth(360)
        # self.dock_widget.setFixedHeight(640)
        self.dock_widget.setMinimumSize(220, 250)
        self.dock_widget.setSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        self.dock_widget.setFeatures(QDockWidget.AllDockWidgetFeatures)
        if self.main_window is not None:
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
        self._orig_width = self.rect.width()
        self._orig_height = self.rect.height()
        self._orig_pic = self.pic.copy()
        self._orig_input_rects = [QtCore.QRectF(s.rect) for s in self.input]
        self._orig_output_rects = [QtCore.QRectF(s.rect) for s in self.output]

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

        # --- Update this node's own input socket lines ---
        for inp in self.input:
            for line in inp.in_lines:
                line.pointB = inp.get_center()
            if inp.other_line:
                inp.other_line.pointB = inp.get_center()

        # --- Update this node's own output socket lines ---
        for op in self.output:
            for line in op.out_lines:
                line.pointA = op.get_center()
            if op.other_line:
                op.other_line.pointA = op.get_center()

        # --- Update all other NodeItem lines in the scene (safety) ---
        items = self.graphicsView.items()
        for i in items:
            if isinstance(i, NodeItem):
                # Update output lines of other nodes
                for op in i.output:
                    for line in op.out_lines:
                        if line.source is not None:
                            line.pointA = line.source.get_center()
                        if line.target is not None:
                            line.pointB = line.target.get_center()

                # Update input lines of other nodes
                for ip in i.input:
                    for line in ip.in_lines:
                        if line.source is not None:
                            line.pointA = line.source.get_center()
                        if line.target is not None:
                            line.pointB = line.target.get_center()

        # --- Update node position in model object (if linked) ---
        self.current_pos = event.scenePos()
        if hasattr(self, "obj") and self.obj is not None:
            self.obj.set_pos(self.current_pos)


    def update_input_ports(self, new_count):
        """Dynamically adjust the number of input sockets for this node (e.g. Mixer)."""
        old_count = len(self.input)
        if new_count == old_count:
            return

        self.prepareGeometryChange()

        # Remove excess sockets from the end
        while len(self.input) > new_count:
            socket = self.input.pop()
            # Remove any connected lines from the scene
            for line in list(socket.in_lines):
                # Clean up the source side
                if hasattr(line, 'source') and line.source is not None:
                    if line in line.source.out_lines:
                        line.source.out_lines.remove(line)
                    # Remove logical connection on the source object
                    try:
                        line.source.parent.obj.remove_connection(0, line.source.id)
                    except Exception as e:
                        print(f"[DEBUG] update_input_ports: source cleanup error: {e}")
                # Remove logical connection on this object
                try:
                    self.obj.remove_connection(1, socket.id)
                except Exception as e:
                    print(f"[DEBUG] update_input_ports: target cleanup error: {e}")
                if self.scene() is not None:
                    self.scene().removeItem(line)
            socket.in_lines.clear()
            if self.scene() is not None:
                self.scene().removeItem(socket)

        # Add new sockets if needed
        while len(self.input) < new_count:
            idx = len(self.input) + 1
            socket = NodeSocket(
                QtCore.QRect(
                    int(-6.5),
                    int(self.rect.height() * idx / (new_count + 1) - 6),
                    12, 12
                ),
                self, 'in', idx
            )
            self.input.append(socket)

        # Reposition all input sockets evenly
        for i, socket in enumerate(self.input):
            idx = i + 1
            socket.prepareGeometryChange()
            socket.rect = QtCore.QRectF(
                -6.5,
                self.rect.height() * idx / (new_count + 1) - 6,
                12, 12
            )
            socket.id = idx
            socket.update()

        self.nin = new_count
        self._orig_input_rects = [QtCore.QRectF(s.rect) for s in self.input]
        self._update_connected_lines()
        self.update()
        print(f"[DEBUG] update_input_ports: {old_count} → {new_count} ports")

    def update_output_ports(self, new_count):
        """Dynamically adjust the number of output sockets for this node (e.g. Splitter)."""
        old_count = len(self.output)
        if new_count == old_count:
            return

        self.prepareGeometryChange()

        # Remove excess sockets from the end
        while len(self.output) > new_count:
            socket = self.output.pop()
            # Remove any connected lines from the scene
            for line in list(socket.out_lines):
                # Clean up the target side
                if hasattr(line, 'target') and line.target is not None:
                    if line in line.target.in_lines:
                        line.target.in_lines.remove(line)
                    # Remove logical connection on the target object
                    try:
                        line.target.parent.obj.remove_connection(1, line.target.id)
                    except Exception as e:
                        print(f"[DEBUG] update_output_ports: target cleanup error: {e}")
                # Remove logical connection on this object
                try:
                    self.obj.remove_connection(0, socket.id)
                except Exception as e:
                    print(f"[DEBUG] update_output_ports: source cleanup error: {e}")
                if self.scene() is not None:
                    self.scene().removeItem(line)
            socket.out_lines.clear()
            if self.scene() is not None:
                self.scene().removeItem(socket)

        # Add new sockets if needed
        while len(self.output) < new_count:
            idx = len(self.output) + 1
            socket = NodeSocket(
                QtCore.QRect(
                    int(self.rect.width() - 6.5),
                    int(self.rect.height() * idx / (new_count + 1) - 6),
                    12, 12
                ),
                self, 'op', idx
            )
            self.output.append(socket)

        # Reposition all output sockets evenly
        for i, socket in enumerate(self.output):
            idx = i + 1
            socket.prepareGeometryChange()
            socket.rect = QtCore.QRectF(
                self.rect.width() - 6.5,
                self.rect.height() * idx / (new_count + 1) - 6,
                12, 12
            )
            socket.id = idx
            socket.update()

        self.nop = new_count
        self._orig_output_rects = [QtCore.QRectF(s.rect) for s in self.output]
        self._update_connected_lines()
        self.update()
        print(f"[DEBUG] update_output_ports: {old_count} → {new_count} ports")

                
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
        newPos = value
        if change == self.ItemPositionChange and self.scene():
            rect = self.container.graphicsView.sceneRect()
            width = self.boundingRect().width()
            height = self.boundingRect().height()
            eWH1 = QPointF(newPos.x()+width,newPos.y()+height)
            eWH2 = QPointF(newPos.x()-width,newPos.y()-height)
            if not rect.__contains__(eWH1) or not rect.__contains__(eWH2) :
                newPos.setX(min(rect.right()-width-40, max(newPos.x(), rect.left())))
                newPos.setY(min(rect.bottom()-height-35, max(newPos.y(), rect.top())))
                self.obj.set_pos(newPos)
        return super(NodeItem,self).itemChange(change, newPos)

    def contextMenuEvent(self, event):
        menu = QMenu()
        delete_action = menu.addAction("Delete")
        action = menu.exec_(event.screenPos())
        if action == delete_action:
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
