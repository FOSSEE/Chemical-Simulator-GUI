from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
from PyQt5.QtWidgets import QLineEdit

from DockWidgets.DockWidget import *
from DockWidgets.DockWidgetMaterialStream import *
from DockWidgets.DockWidgetDistillationColumn import *
from DockWidgets.DockWidgetShortcutColumn import *
from DockWidgets.DockWidgetMixer import *
from DockWidgets.DockWidgetSplitter import *
from DockWidgets.DockWidgetFlash import *
from DockWidgets.DockWidgetCompoundSeparator import *
from DockWidgets.DockWidgetCompressorExpander import *
from Container import *
from Streams import *
from UnitOperations import *
from ComponentSelector import *

class Graphics(QDialog, QtWidgets.QGraphicsItem):

    def __init__(self, unit_operations, graphicsView):
        QDialog.__init__(self)
        QtWidgets.QGraphicsItem.__init__(self)
        self.scene = QGraphicsScene()
        self.scene.setItemIndexMethod(QGraphicsScene.BspTreeIndex)
        self.graphicsView = graphicsView
        self.pos = None
        self.unit_operations = unit_operations

    def get_scene(self):
        return self.scene

    def create_node_item(self,unit_operation, container):
        return NodeItem(unit_operation, container, self.graphicsView)
    
    def load_canvas(self, obj, container):
        stm = ['MaterialStream','EngStm']
        for i in obj:
            if i in self.unit_operations:
                pass
            else:
                self.unit_operations.append(i)
                type(i).counter += 1
            print(self.unit_operations)
            new_box = self.create_node_item(i, container)
            new_box.setPos(i.pos.toPoint().x(), i.pos.toPoint().y())
            self.scene.addItem(new_box)

        for i in obj:
            if i.type == "MaterialStream":
                print(eval(i.type))
            elif i.type not in stm:
                ip = i.input_stms
                op = i.output_stms
                for k, v in ip.items():
                    pointA = NodeItem.get_instances(v.name)
                    pointB = NodeItem.get_instances(i.name)
                    rect = pointA.output[0].boundingRect()
                    pointAA = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
                    pointAA = pointA.output[0].mapToScene(pointAA)
                    socketB = next((s for s in pointB.input if k == s.id))
                    rectB = socketB.boundingRect()
                    pointBB = QtCore.QPointF(rectB.x() + rectB.width()/2, rectB.y() + rectB.height()/2)
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
                    pointAA = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
                    pointAA = socketA.mapToScene(pointAA)
                    rectB = pointB.input[0].boundingRect()
                    pointBB = QtCore.QPointF(rectB.x() + rectB.width()/2, rectB.y() + rectB.height()/2)
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
        self.brush = QtGui.QBrush()
        self.brush.setStyle(QtCore.Qt.SolidPattern)
        self.brush.setColor(QtGui.QColor(220,220,220,220)) 
        # Pen
        self.pen = QtGui.QPen()
        self.pen.setStyle(QtCore.Qt.SolidLine)
        self.pen.setWidth(1)
        self.pen.setColor(QtGui.QColor(0,70,70,255))  
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
        painter.setBrush(self.brush)
        painter.setPen(self.pen)
        painter.drawEllipse(self.rect)

    def mousePressEvent(self, event):
        cursor = QCursor( Qt.PointingHandCursor )
        QApplication.instance().setOverrideCursor(cursor)

        if self.type == 'op':
            rect = self.boundingRect()
            pointA = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
            pointA = self.mapToScene(pointA)
            pointB = self.mapToScene(event.pos())
            self.new_line = NodeLine(pointA, pointB ,'op')
            self.out_lines.append(self.new_line)
            self.scene().addItem(self.new_line)    
        elif self.type == 'in':
            rect = self.boundingRect()
            pointA = self.mapToScene(event.pos())
            pointB = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
            pointB = self.mapToScene(pointB)
            self.new_line = NodeLine(pointA, pointB, 'in')
            self.in_lines.append(self.new_line)
            self.scene().addItem(self.new_line)
        else:
            super(NodeSocket, self).mousePressEvent(event)

    def mouseMoveEvent(self, event):

        if self.type == 'op':
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
        if (self.type == 'op') and (item.type == 'in'):
            self.new_line.source = self
            self.new_line.target = item
            item.in_lines.append(self.new_line)
            self.new_line.pointB = item.get_center()
            print(type(self.new_line.source))
            if self.new_line.source.parent.obj.type not in stm:
                self.new_line.source.parent.obj.add_connection(0, self.new_line.source.id, self.new_line.target.parent.obj)
            if self.new_line.target.parent.obj.type not in stm:
                self.new_line.target.parent.obj.add_connection(1, self.new_line.target.id, self.new_line.source.parent.obj) # Input stream if flag is 1

        elif (self.type =='in') and (item.type == 'op'):
            self.new_line.source = item
            self.new_line.target = self
            item.out_lines.append(self.new_line)
            self.new_line.pointA = item.get_center()
            print(type(self.new_line.source))
            if self.new_line.source.parent.obj.type not in stm:
                self.new_line.source.parent.obj.add_connection(0, self.new_line.source.id, self.new_line.target.parent.obj)
            if self.new_line.target.parent.obj.type not in stm:
                self.new_line.target.parent.obj.add_connection(1, self.new_line.target.id, self.new_line.source.parent.obj)


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
        center = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
        center = self.mapToScene(center)
        return center

    def hoverEnterEvent(self, event):
        cursor = QCursor( Qt.CrossCursor )
        QApplication.instance().setOverrideCursor(cursor)
    
    def hoverLeaveEvent(self, event):
        cursor = QCursor( Qt.ArrowCursor )
        QApplication.instance().setOverrideCursor(cursor)
    
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

        self.name = self.obj.name
        self.type = self.obj.type

        if (self.obj.modes_list):
            default_tooltip = f"{self.name}\n\n"
            default_tooltip_dict = self.obj.param_getter(self.obj.mode)
            for i, j in default_tooltip_dict.items():
                if j is not None:
                    default_tooltip = default_tooltip + f"   {i} : {j}\n"
            self.setToolTip(default_tooltip)


        if self.obj.type == 'Mixer' and not self.obj.saved:
            text, ok = QInputDialog.getText(self.container.graphicsView, 'Mixer', 'Enter number of input:',
                                            echo=QLineEdit.Normal, text=str(self.obj.no_of_inputs))
            if ok and text:
                self.nin = int(text)
                self.obj.no_of_inputs = self.nin
                self.obj.variables['NI']['value'] = self.nin
        # elif self.obj.type == 'Splitter' and not self.obj.saved:
        #     text, ok = QInputDialog.getText(self.container.graphicsView, 'Splitter', 'Enter number of output:')
        #     if ok and text:
        #         self.nop = int(text)
        #         self.obj.no_of_outputs = self.nop
        #         self.obj.variables['No']['value'] = self.nop
        elif self.obj.type == 'DistillationColumn'and not self.obj.saved:
            text, ok = QInputDialog.getText(self.container.graphicsView, 'DistillationColumn', 'Enter number of input:',
                                            echo=QLineEdit.Normal, text=str(self.obj.no_of_inputs))
            if ok and text:
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
            print(self.dock_widget.obj.type)
            try:
                self.dock_widget.obj.param_setter(self.dock_widget.obj.param_getter(self.dock_widget.obj.mode))
            except Exception as e:
                print(e)
        # self.dock_widget.param()

        self.dock_widget.hide()
        
        self.pic=QtGui.QPixmap("Icons/"+self.type+".png")
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
            input = [NodeSocket(QtCore.QRect(5,(self.rect.height()*x/(self.nin+1)-2),4,4), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-9,(self.rect.height()*x*1/(self.nop+1)),4,4), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="AdiabaticCompressor" or self.type=="AdiabaticExpander"  or self.type =="Mixer" or self.type =="Splitter" or self.type =="Valve" ):
            input = [NodeSocket(QtCore.QRect(-2.5, (self.rect.height()*x/(self.nin+1))-2,4,4), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-2.5,(self.rect.height()*x/(self.nop+1))-2,4,4), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="Cooler" or self.type=="Heater"):
            input = [NodeSocket(QtCore.QRect(3.5, (self.rect.height()*x/(self.nin+1))-2,4,4), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-8.0,(self.rect.height()*x/(self.nop+1))-2,4,4), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="Pump"):
            input = [NodeSocket(QtCore.QRect(-2.5,(self.rect.height()*x/(self.nin+1))-7, 4,4), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-2.5,-1.5,4,4), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="DistillationColumn" or self.type=="ShortcutColumn"):
            input = [NodeSocket(QtCore.QRect(-2.5,(self.rect.height()*x/(self.nin+1)),5,5), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-5.5,(self.rect.height()*1.44*x/(self.nop+1))-55,5,5), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output
        elif(self.type=="MaterialStream"):
            input = [NodeSocket(QtCore.QRect(-2.5,(self.rect.height()*x/(self.nin+1)-2),4,4), self, 'in', x) for x in range(1,self.nin+1) ]
            output = [NodeSocket(QtCore.QRect(self.rect.width()-2.5,(self.rect.height()*x/(self.nin+1)-2),4,4), self, 'op', x) for x in range(1,self.nop+1)]
            return input,output

    def mouseMoveEvent(self, event):
        super(NodeItem, self).mouseMoveEvent(event)
        for op in self.output:
            for line in op.out_lines:
                line.pointA = line.source.get_center()
                line.pointB = line.target.get_center()
        for ip in self.input:
            for line in ip.in_lines:
                line.pointA = line.source.get_center()
                line.pointB = line.target.get_center()
        self.pos = event.scenePos()
        self.obj.set_pos(self.pos)
                
    def mouseDoubleClickEvent(self, event):

        self.graphicsView.setInteractive(False)
        if len(stack):
            stack[-1].hide()
        self.dock_widget.show()
        stack.append(self.dock_widget)
        self.graphicsView.setInteractive(True)

    def update_tooltip(self):
        default_tooltip = f"{self.name}\n\n"
        default_tooltip_dict = self.obj.param_getter(self.obj.modes_list[0])
        for i, j in default_tooltip_dict.items():
            if j is not None:
                default_tooltip = default_tooltip + f"   {i} : {j}\n"
        self.setToolTip(default_tooltip)

        
def findMainWindow(self):
    '''
        Global function to find the (open) QMainWindow in application
    ''' 
    app = QApplication.instance()
    for widget in app.topLevelWidgets():
        if isinstance(widget, QMainWindow):
            return widget
    return None
