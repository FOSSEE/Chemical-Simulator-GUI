from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
from PyQt5.QtWidgets import QLineEdit
import os, sys

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)
sys.path.append(parentPath)

from python.DockWidgets.DockWidget import *
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

    def __init__(self, unit_operations, graphicsView):
        QDialog.__init__(self)
        QtWidgets.QGraphicsItem.__init__(self)
        self.scene = QGraphicsScene()
        self.scene.setItemIndexMethod(QGraphicsScene.BspTreeIndex)
        self.graphicsView = graphicsView
        self.pos = None
        self.unit_operations = unit_operations
        self.graphicsView.horizontalScrollBarVal = self.graphicsView.horizontalScrollBar().value()

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
    
    def load_canvas(self, obj, container):
        stm = ['MaterialStream','EngStm']
        for i in obj:
            if i in self.unit_operations:
                pass
            else:
                self.unit_operations.append(i)
                type(i).counter += 1
            #print(self.unit_operations)
            new_box = self.create_node_item(i, container)
            new_box.setPos(i.pos.toPoint().x(), i.pos.toPoint().y())
            self.scene.addItem(new_box)

        for i in obj:
            if i.type == "MaterialStream":
                pass
                #print(eval(i.type))
            elif i.type not in stm:
                ip = i.input_stms
                op = i.output_stms
                for k, v in ip.items():
                    pointA = NodeItem.get_instances(v.name)
                    pointB = NodeItem.get_instances(i.name)
                    rect = pointA.output[0].boundingRect()
                    pointAA = QtCore.QPointF(rect.x() + rect.width()/(2), rect.y() + rect.height()/(2))
                    pointAA = pointA.output[0].mapToScene(pointAA)
                    socketB = next((s for s in pointB.input if k == s.id))
                    rectB = socketB.boundingRect()
                    pointBB = QtCore.QPointF(rectB.x() + rectB.width()/(2), rectB.y() + rectB.height()/(2))
                    pointBB = socketB.mapToScene(pointBB)
                    self.new_line = NodeLine(pointAA, pointBB, 'in')
                    self.new_line.source = pointA.output[0]
                    self.new_line.target = socketB
                    pointA.output[0].out_lines.append(self.new_line)
                    socketB.in_lines.append(self.new_line)
                    pointA.output[0].other_line = self.new_line
                    socketB.other_line = self.new_line
                    self.scene.addItem(self.new_line)
                    self.new_line.updatePath()      
                for k, v in op.items():
                    pointA = NodeItem.get_instances(i.name)
                    pointB = NodeItem.get_instances(v.name)
                    socketA = next(s for s in pointA.output if k == s.id)
                    rect = socketA.boundingRect()
                    pointAA = QtCore.QPointF(rect.x() + rect.width()/(2), rect.y() + rect.height()/(2))
                    pointAA = socketA.mapToScene(pointAA)
                    rectB = pointB.input[0].boundingRect()
                    pointBB = QtCore.QPointF(rectB.x() + rectB.width()/(2), rectB.y() + rectB.height()/(2))
                    pointBB = pointB.input[0].mapToScene(pointBB)
                    self.new_line = NodeLine(pointAA, pointBB, 'out')
                    self.new_line.source = socketA
                    self.new_line.target = pointB.input[0]
                    socketA.out_lines.append(self.new_line)
                    pointB.input[0].in_lines.append(self.new_line)
                    socketA.other_line = self.new_line
                    pointB.input[0].other_line = self.new_line
                    self.scene.addItem(self.new_line)
                    self.new_line.updatePath()
           
                            
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
        painter.drawEllipse(self.rect.x(),self.rect.y(),self.rect.height(),self.rect.width())
        painter.setBrush(self.brush)
        painter.drawEllipse(self.rect.x()+2,self.rect.y()+2,(self.rect.height()/3)*2,(self.rect.width()/3)*2)
        
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

        if self.type == 'op':
            item = self.scene().itemAt(event.scenePos().toPoint(),QtGui.QTransform())
            if(isinstance(item,NodeSocket)):
                QApplication.instance().setOverrideCursor(QCursor( Qt.PointingHandCursor))
            else:
                QApplication.instance().restoreOverrideCursor()
                QApplication.instance().setOverrideCursor(QCursor( Qt.ArrowCursor))
            pointB = self.mapToScene(event.pos())
            self.new_line.pointB = pointB
            if self.other_line:
                self.other_line.pointB=pointB       
        elif self.type == 'in':
            pointA = self.mapToScene(event.pos())
            self.new_line.pointA = pointA
            if self.other_line:
                self.other_line.pointA=pointA
        else:
            super(NodeSocket, self).mouseMoveEvent(event)

    def mouseReleaseEvent(self, event):
        cursor = QCursor( Qt.ArrowCursor )
        QApplication.instance().setOverrideCursor(cursor)

        item = self.scene().itemAt(event.scenePos().toPoint(),QtGui.QTransform())
        stm = ['MaterialStream','EngStm']
        item.other_line=self.new_line
        if self.type == 'op' and item.type == 'in' and len(item.in_lines) == 0:
            self.new_line.source = self
            self.new_line.target = item
            item.in_lines.append(self.new_line)
            self.new_line.pointB = item.get_center()
            #print(type(self.new_line.source))
            if self.new_line.source.parent.obj.type not in stm:
                self.new_line.source.parent.obj.add_connection(0, self.new_line.source.id, self.new_line.target.parent.obj)
            if self.new_line.target.parent.obj.type not in stm:
                self.new_line.target.parent.obj.add_connection(1, self.new_line.target.id, self.new_line.source.parent.obj) # Input stream if flag is 1
            
            sc = self.new_line.source.parent
            tg = self.new_line.target.parent
            if(sc.obj.type == 'MaterialStream'):
                sc_no_input_lines = len(sc.input[0].in_lines)
                if(sc_no_input_lines > 0):
                    sc.obj.disableInputDataTab(sc.dock_widget)
            if(tg.obj.type == 'MaterialStream'):
                tg_no_input_lines = len(tg.input[0].in_lines)
                if(tg_no_input_lines > 0):
                    tg.obj.disableInputDataTab(tg.dock_widget)

        elif self.type =='in' and item.type == 'op' and len(item.out_lines) == 0:
            self.new_line.source = item
            self.new_line.target = self
            item.out_lines.append(self.new_line)
            self.new_line.pointA = item.get_center()
            #print(type(self.new_line.source))
            if self.new_line.source.parent.obj.type not in stm:
                self.new_line.source.parent.obj.add_connection(0, self.new_line.source.id, self.new_line.target.parent.obj)
            if self.new_line.target.parent.obj.type not in stm:
                self.new_line.target.parent.obj.add_connection(1, self.new_line.target.id, self.new_line.source.parent.obj)
            
            sc = self.new_line.source.parent
            tg = self.new_line.target.parent
            if(sc.obj.type == 'MaterialStream'):
                sc_no_input_lines = len(sc.input[0].in_lines)
                if(sc_no_input_lines > 0):
                    sc.obj.disableInputDataTab(sc.dock_widget)
            if(tg.obj.type == 'MaterialStream'):
                tg_no_input_lines = len(tg.input[0].in_lines)
                if(tg_no_input_lines > 0):
                    tg.obj.disableInputDataTab(tg.dock_widget)

        else:
            self.scene().removeItem(self.new_line)
            if(self.new_line in self.in_lines):
                self.in_lines.remove(self.new_line)
            if(self.new_line in self.out_lines):
                self.out_lines.remove(self.new_line)
            del self.new_line
            super(NodeSocket, self).mouseReleaseEvent(event)

        try:
            data = get_last_list('Undo')
            comp_selected = data[-1]
            data.remove(comp_selected)
            for i in range(len(data)):
                if data[i].name == self.new_line.source.parent.obj.name:
                    data[i] = self.new_line.source.parent.obj
                elif data[i].name == self.new_line.target.parent.obj.name:
                    data[i] = self.new_line.target.parent.obj
            data.append(comp_selected)
            push('Undo', data)
        except Exception as e:
            print(e)
            
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

class NodeItem(QtWidgets.QGraphicsItem):

    @staticmethod
    def get_instances(namee):
        for i in lst:
            if i.name == namee:
                return i

    @staticmethod
    def get_dock_widget():
        return dock_widget_lst

    def __init__(self,unit_operation, container, graphicsView):
        l = ['Splitter','Mixer', 'DistillationColumn', 'Flash', 'CompoundSeparator', 'ShortcutColumn'] 
        stm = ['MaterialStream', 'EnergyStream']
        super(NodeItem, self).__init__()
        self.obj = unit_operation
        self.container = container
        self.graphicsView = graphicsView
        self.setAcceptHoverEvents(True)
        self.name = self.obj.name
        self.type = self.obj.type
        self.ok = True
        if (self.obj.modes_list):
            default_tooltip = f"{self.name}\n\n"
            default_tooltip_dict = self.obj.param_getter_tooltip(self.obj.mode)
            for i, j in default_tooltip_dict.items():
                if j is not None:
                    default_tooltip = default_tooltip + f"   {i} : {j}\n"
            self.setToolTip(default_tooltip)

        dlg = QMessageBox()
        dlg.setWindowTitle("Error")
        dlg.setIcon(QMessageBox.Critical)
        dlg.setText('Enter valid input value!')

        if self.obj.type == 'Mixer' and not self.obj.saved:
            text, self.ok = QInputDialog.getText(self.container.graphicsView, 'Mixer', 'Enter number of input(2-4):',
                                            echo=QLineEdit.Normal, text=str(self.obj.no_of_inputs))
            while self.ok and (int(text)< 2 or int(text) > 4):
                dlg.exec_()
                text, self.ok = QInputDialog.getText(self.container.graphicsView, 'Mixer', 'Enter number of input(2-4):',
                                            echo=QLineEdit.Normal, text=str(self.obj.no_of_inputs))
            if self.ok:
                self.nin = int(text)
                self.obj.no_of_inputs = self.nin
                self.obj.variables['NI']['value'] = self.nin
        elif self.obj.type == 'DistillationColumn'and not self.obj.saved:
            text, self.ok = QInputDialog.getText(self.container.graphicsView, 'DistillationColumn', 'Enter number of input(1-8):',
                                            echo=QLineEdit.Normal, text=str(self.obj.no_of_inputs))
            while self.ok and (int(text)< 1 or int(text) > 8):
                dlg.exec_()
                text, self.ok = QInputDialog.getText(self.container.graphicsView, 'DistillationColumn', 'Enter number of input(1-8):',
                                        echo=QLineEdit.Normal, text=str(self.obj.no_of_inputs))
            if self.ok:
                self.nin = int(text)
                self.obj.no_of_inputs = self.nin
                self.obj.variables['Ni']['value'] = self.nin

        self.nin = self.obj.no_of_inputs
        self.nop = self.obj.no_of_outputs

        self.dock_widget = None
        lst.append(self)
        if self.obj.type in l:
            self.dock_widget = eval("DockWidget"+self.obj.type)(self.obj.name,self.obj.type,self.obj,self.container)
        elif self.obj.type in stm:
            self.dock_widget = eval("DockWidget"+self.obj.type)(self.obj.name,self.obj.type,self.obj,self.container)
        elif self.obj.type == "AdiabaticCompressor" or self.obj.type == "AdiabaticExpander":
            self.dock_widget = eval("DockWidgetCompressorExpander")(self.obj.name,self.obj.type,self.obj,self.container)
        else:
            self.dock_widget = DockWidget(self.obj.name,self.obj.type,self.obj,self.container)
        dock_widget_lst.append(self.dock_widget)
        self.main_window= findMainWindow(self)
        self.dock_widget.setFixedWidth(360)
        self.dock_widget.setFixedHeight(640)
        self.dock_widget.DockWidgetFeature(QDockWidget.AllDockWidgetFeatures)
        self.main_window.addDockWidget(Qt.LeftDockWidgetArea, self.dock_widget)

        # updating input values
        if self.dock_widget.obj.type != 'MaterialStream':
            pass
            try:
                self.dock_widget.obj.param_setter(self.dock_widget.obj.param_getter(self.dock_widget.obj.mode))
            except Exception as e:
                print(e)
        # self.dock_widget.param()

        self.dock_widget.hide()
        
        self.pic=QtGui.QPixmap(parentPath+"/resources/base/Icons/"+self.type+".png")
        self.rect = QtCore.QRect(0,0,self.pic.width(),self.pic.height())
        self.text = QGraphicsTextItem(self)
        f = QFont()
        f.setPointSize(8)
        self.text.setFont(f)
        self.text.setDefaultTextColor(QtGui.QColor(0,70,70,220))
        self.text.setParentItem(self)
        self.text.setPos(self.rect.width()-(self.rect.width()*0.9), self.rect.height())
        self.text.setPlainText(self.name) 
        
        self.setFlag(QtWidgets.QGraphicsPixmapItem.ItemIsMovable)
        self.setFlag(QtWidgets.QGraphicsPixmapItem.ItemIsSelectable)
        self.setFlag(QGraphicsItem.ItemSendsGeometryChanges)
    
        # Brush
        self.brush = QtGui.QBrush()
        self.brush.setStyle(QtCore.Qt.SolidPattern)
        self.brush.setColor(QtGui.QColor(80,0,90,255))
        # Pen
        self.pen = QtGui.QPen()
        self.pen.setStyle(QtCore.Qt.SolidLine)
        self.pen.setWidth(1)
        self.pen.setColor(QtGui.QColor(20,20,20,255))
    
        self.sel_pen = QtGui.QPen()
        self.sel_pen.setStyle(QtCore.Qt.SolidLine)
        self.sel_pen.setWidth(1)
        self.sel_pen.setColor(QtGui.QColor(220,220,220,255))
 
        # initializing the node sockets
        self.input , self.output = self.initialize_sockets(self.type)

    def shape(self):
        path = QtGui.QPainterPath()
        path.addRect(self.boundingRect())
        return path
 
    def boundingRect(self):
        return QtCore.QRectF(self.rect)
 
    def paint(self, painter, option, widget):
        if self.isSelected():
            painter.setPen(self.sel_pen)
            painter.drawRect(QtCore.QRectF(self.rect))
        else:
            painter.setPen(self.pen)
        painter.drawPixmap(self.rect,self.pic)

    def initialize_sockets(self,type):
        if(self.type=="Flash" or self.type=="CompoundSeparator"):
            input = [NodeSocket(QtCore.QRect(1,(self.rect.height()*x/(self.nin+1)-6),4*3,4*3), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-13,(self.rect.height()*x*1/(self.nop+1))-4,4*3,4*3), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="AdiabaticCompressor" or self.type=="AdiabaticExpander"  or self.type =="Mixer" or self.type =="Splitter" or self.type =="Valve" ):
            input = [NodeSocket(QtCore.QRect(-6.5, (self.rect.height()*x/(self.nin+1))-6,4*3,4*3), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-6.5,(self.rect.height()*x/(self.nop+1))-6,4*3,4*3), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="Cooler" or self.type=="Heater"):
            input = [NodeSocket(QtCore.QRect(-0.5, (self.rect.height()*x/(self.nin+1))-6,4*3,4*3), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-12.0,(self.rect.height()*x/(self.nop+1))-6,4*3,4*3), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="CentrifugalPump"):
            input = [NodeSocket(QtCore.QRect(-6.5,(self.rect.height()*x/(self.nin+1))-11, 4*3,4*3), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-6.5,-5.5,4*3,4*3), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="DistillationColumn" or self.type=="ShortcutColumn"):
            input = [NodeSocket(QtCore.QRect(-6.5,(self.rect.height()*x/(self.nin+1)-4),4*3,4*3), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-9.5,(self.rect.height()*1.44*x/(self.nop+1))-59,4*3,4*3), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="MaterialStream"):
            input = [NodeSocket(QtCore.QRect(-6.5,(self.rect.height()*x/(self.nin+1)-6),4*3,4*3), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-6.5,(self.rect.height()*x/(self.nin+1)-6),4*3,4*3), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output

    def mouseMoveEvent(self, event):
        super(NodeItem, self).mouseMoveEvent(event)
        items = self.graphicsView.items()
        for i in items:
            if(type(i) == NodeItem):
                for op in i.output:
                    for line in op.out_lines:
                        line.pointA = line.source.get_center()
                        line.pointB = line.target.get_center()
                for ip in i.input:
                    for line in ip.in_lines:
                        line.pointA = line.source.get_center()
                        line.pointB = line.target.get_center()
        self.pos = event.scenePos()
        self.obj.set_pos(self.pos)
                
    def mouseDoubleClickEvent(self, event):

        self.graphicsView.horizontalScrollBarVal = self.graphicsView.horizontalScrollBar().value()
        self.graphicsView.setInteractive(False)
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
        
def findMainWindow(self):
    '''
        Global function to find the (open) QMainWindow in application
    ''' 
    app = QApplication.instance()
    for widget in app.topLevelWidgets():
        if isinstance(widget, QMainWindow):
            return widget
    return None
