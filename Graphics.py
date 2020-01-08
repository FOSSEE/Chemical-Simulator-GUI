from functools import partial
from collections import defaultdict
import sys
import numpy as np
from OMChem.Flowsheet import Flowsheet
import pandas as pd
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QTextDocument ,QTextCursor ,QTextCharFormat ,QFont ,QPixmap
from PyQt5.uic import loadUiType
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGraphicsProxyWidget, QGraphicsObject, QGraphicsEllipseItem ,QGraphicsPixmapItem,QApplication, QGraphicsView, QGraphicsScene, QHBoxLayout, QWidget, QLabel
from PyQt5.QtGui import QBrush ,QTransform ,QMouseEvent
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
from component_selector import *
from dockWidget import dockWidget
import datetime
from container import *
from Streams import *
from UnitOperations import *

class Graphics(QDialog, QtWidgets.QGraphicsItem):

    def __init__(self, unitOp):
        QDialog.__init__(self)
        QtWidgets.QGraphicsItem.__init__(self)
        self.scene = QGraphicsScene()
        self.scene.setItemIndexMethod(QGraphicsScene.BspTreeIndex)
        self.pos = None
        self.unitOp = unitOp
    
    def getScene(self):
        return self.scene

    def getComponentSelector(self):
        return componentSelector(self)

    def createNodeItem(self,unitOpr):
        return NodeItem(unitOpr)

    def boundingRect(self):
        return QtCore.QRectF(self.rect)
    
    def loadCanvas(self, obj):
        stm = ['MaterialStream','EngStm']
        
        compounds = obj[-1]
        obj.pop()
        componentSelector.setCompounds(compounds)

        for i in obj:
            if(i in self.unitOp):
               pass
            else:
                self.unitOp.append(i)
            new_box = self.createNodeItem(i)
            new_box.setPos(i.pos.toPoint().x(), i.pos.toPoint().y())
            self.scene.addItem(new_box)

        for i in obj:
            if i.type == "MaterialStream":
                eval(i.type).counter += 1
            elif i.type not in stm:
                eval(i.type).counter += 1
                ip = i.InputStms
                op = i.OutputStms
                for j in ip:
                    pointA = NodeItem.getInstances(j.name)
                    pointB = NodeItem.getInstances(i.name)
                    rect = pointA.Output[0].boundingRect()
                    pointAA = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
                    pointAA = pointA.Output[0].mapToScene(pointAA)
                    rectB = pointB.Input[0].boundingRect()
                    pointBB = QtCore.QPointF(rectB.x() + rectB.width()/2, rectB.y() + rectB.height()/2)
                    pointBB = pointB.Input[0].mapToScene(pointBB)
                    self.new_line = NodeLine(pointAA, pointBB, 'in')
                    self.new_line.source = pointA.Output[0]
                    self.new_line.target = pointB.Input[0]
                    pointA.Output[0].outLines.append(self.new_line)
                    pointB.Input[0].inLines.append(self.new_line)
                    pointA.Output[0].otherLine = self.new_line
                    pointB.Input[0].otherLine = self.new_line
                    self.scene.addItem(self.new_line)
                    self.new_line.updatePath()      
                for k in op:
                    pointA = NodeItem.getInstances(i.name)
                    pointB = NodeItem.getInstances(k.name)
                    rect = pointA.Output[0].boundingRect()
                    pointAA = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
                    pointAA = pointA.Output[0].mapToScene(pointAA)
                    rectB = pointB.Input[0].boundingRect()
                    pointBB = QtCore.QPointF(rectB.x() + rectB.width()/2, rectB.y() + rectB.height()/2)
                    pointBB = pointB.Input[0].mapToScene(pointBB)
                    self.new_line = NodeLine(pointAA, pointBB, 'out')
                    self.new_line.source = pointA.Output[0]
                    self.new_line.target = pointB.Input[0]
                    pointA.Output[0].outLines.append(self.new_line)
                    pointB.Input[0].inLines.append(self.new_line)
                    pointA.Output[0].otherLine = self.new_line
                    pointB.Input[0].otherLine = self.new_line
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
        self.setBrush(QtGui.QColor(0,0,255,255))
        self.pen = QtGui.QPen()
        self.pen.setStyle(QtCore.Qt.SolidLine)
        self.pen.setWidth(1)
        self.pen.setColor(QtGui.QColor(0,0,255,255))
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
                ctrl1_2 = QtCore.QPointF(midptx, self.pointB.y())
                ctrl2_2 = QtCore.QPointF(midptx, self.pointB.y())
                pt2 = QtCore.QPointF(midptx , self.pointA.y()+100)
                path.cubicTo(ctrl1_2, ctrl2_2, pt2)
                path.moveTo(pt2)

                ctrl1_3 = QtCore.QPointF(midptx, self.pointA.y()+100)
                ctrl2_3 = QtCore.QPointF(midptx, self.pointA.y()+100)
                pt3 = QtCore.QPointF(self.pointB.x()-13, self.pointA.y()+100)
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
            else:
                ctrl1_2 = QtCore.QPointF(midptx, self.pointB.y())
                ctrl2_2 = QtCore.QPointF(midptx, self.pointB.y())
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

        ctrl1_2 = QtCore.QPointF(midptx, self.pointB.y())
        ctrl2_2 = QtCore.QPointF(midptx, self.pointB.y())
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
    def __init__(self, rect, parent, socketType):
        super(NodeSocket, self).__init__(parent)
        self.rect = rect
        self.type = socketType
        self.parent=parent
        self.newLine=None
        self.otherLine=None
    
        # Brush.
        self.brush = QtGui.QBrush()
        self.brush.setStyle(QtCore.Qt.SolidPattern)
        self.brush.setColor(QtGui.QColor(180,20,90,255))
        # Pen.
        self.pen = QtGui.QPen()
        self.pen.setStyle(QtCore.Qt.SolidLine)
        self.pen.setWidth(1)
        self.pen.setColor(QtGui.QColor(20,20,20,255))
 
        # Lines.
        self.outLines = []
        self.inLines = []
        
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
        if self.type == 'op':
            rect = self.boundingRect()
            pointA = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
            pointA = self.mapToScene(pointA)
            pointB = self.mapToScene(event.pos())
            self.newLine = NodeLine(pointA, pointB ,'op')
            self.outLines.append(self.newLine)
            self.scene().addItem(self.newLine)    
        elif self.type == 'in':
            rect = self.boundingRect()
            pointA = self.mapToScene(event.pos())
            pointB = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
            pointB = self.mapToScene(pointB)
            self.newLine = NodeLine(pointA, pointB, 'in')
            self.inLines.append(self.newLine)
            self.scene().addItem(self.newLine)
        else:
            super(NodeSocket, self).mousePressEvent(event)

    def mouseMoveEvent(self, event):
        if self.type == 'op':
            pointB = self.mapToScene(event.pos())
            self.newLine.pointB = pointB
            if self.otherLine:
                self.otherLine.pointB=pointB       
        elif self.type == 'in':
            pointA = self.mapToScene(event.pos())
            self.newLine.pointA = pointA
            if self.otherLine:
                self.otherLine.pointA=pointA
        else:
            super(NodeSocket, self).mouseMoveEvent(event)

    def mouseReleaseEvent(self, event):
        item = self.scene().itemAt(event.scenePos().toPoint(),QtGui.QTransform())
        stm = ['MaterialStream','EngStm']
        item.otherLine=self.newLine
        if (self.type == 'op') and (item.type == 'in'):
            self.newLine.source = self
            self.newLine.target = item
            item.inLines.append(self.newLine)
            self.newLine.pointB = item.getCenter()
            if self.newLine.source.parent.obj.type not in stm:
                self.newLine.source.parent.obj.add_connection(0,self.newLine.target.parent.obj)
            if self.newLine.target.parent.obj.type not in stm:
                self.newLine.target.parent.obj.add_connection(1,self.newLine.source.parent.obj)
        elif (self.type =='in') and (item.type == 'op'):
            self.newLine.source = item
            self.newLine.target = self
            item.outLines.append(self.newLine)
            self.newLine.pointA = item.getCenter()
            if self.newLine.source.parent.obj.type not in stm:
                self.newLine.source.parent.obj.add_connection(0,self.newLine.target.parent.obj)
            if self.newLine.target.parent.obj.type not in stm:
                self.newLine.target.parent.obj.add_connection(1,self.newLine.source.parent.obj)
        else:
            self.scene().removeItem(self.newLine)
            if(self.newLine in self.inLines):
                self.inLines.remove(self.newLine)
            if(self.newLine in self.outLines):
                self.outLines.remove(self.newLine)
            del self.newLine
            super(NodeSocket, self).mouseReleaseEvent(event) 

    def getCenter(self):
        rect = self.boundingRect()
        center = QtCore.QPointF(rect.x() + rect.width()/2, rect.y() + rect.height()/2)
        center = self.mapToScene(center)
        return center
    
# all created node items will be put inside this list 
# it is used for recreating the node lines by returning the node item object based on unit operation object's name 
lst = []

class NodeItem(QtWidgets.QGraphicsItem):

    @staticmethod
    def getInstances(namee):
        for i in lst:
            if i.name == namee:
                return i

    def __init__(self,unitOpr):
        l = ['Mixer','Splitter']
        super(NodeItem, self).__init__()

        self.obj = unitOpr

        self.name = self.obj.name
        self.type = self.obj.type

        default_tooltip = f"{self.name}\n\n"
        default_tooltip_dict = self.obj.paramgetter(self.obj.modesList[0])
        for i, j in default_tooltip_dict.items():
            if j is not None:
                default_tooltip = default_tooltip + f"   {i} : {j}\n"
        self.setToolTip(default_tooltip)

        self.nin = self.obj.no_of_inputs
        self.nop = self.obj.no_of_outputs

        self.dockWidget = None
        lst.append(self)

        if(self.obj.type not in l):
            self.dockWidget = dockWidget(self.obj.name,self.obj.type,self.obj)
            self.mainwindow= findMainWindow(self)
            self.mainwindow.addDockWidget(Qt.LeftDockWidgetArea, self.dockWidget)
            self.dockWidget.hide()

        self.pic=QtGui.QPixmap("icons/"+self.type+".png")
        self.rect = QtCore.QRect(0,0,self.pic.width(),self.pic.height())
        self.text = QGraphicsTextItem(self)
        f = QFont()
        f.setPointSize(8)
        self.text.setFont(f)
        self.text.setDefaultTextColor(QtGui.QColor(73,36,73,255))
        self.text.setParentItem(self)
        self.text.setPos(-2.5, self.rect.height()-15)
        self.text.setPlainText(self.name) 
        
        self.setFlag(QtWidgets.QGraphicsPixmapItem.ItemIsMovable)
        self.setFlag(QtWidgets.QGraphicsPixmapItem.ItemIsSelectable)
        self.initUi()
    
        # Brush
        self.brush = QtGui.QBrush()
        self.brush.setStyle(QtCore.Qt.SolidPattern)
        self.brush.setColor(QtGui.QColor(80,0,90,255))
        # Pen.
        self.pen = QtGui.QPen()
        self.pen.setStyle(QtCore.Qt.SolidLine)
        self.pen.setWidth(1)
        self.pen.setColor(QtGui.QColor(20,20,20,255))
    
        self.selPen = QtGui.QPen()
        self.selPen.setStyle(QtCore.Qt.SolidLine)
        self.selPen.setWidth(2)
        self.selPen.setColor(QtGui.QColor(222,192,222))
 
    def initUi(self):
        self.Input , self.Output = self.initializeSockets(self.type)
    
    def shape(self):
        path = QtGui.QPainterPath()
        path.addRect(self.boundingRect())
        return path
 
    def boundingRect(self):
        return QtCore.QRectF(self.rect)
 
    def paint(self, painter, option, widget):
        if self.isSelected():
            painter.setPen(self.selPen)
            painter.drawRect(QtCore.QRectF(self.rect))
        else:
            painter.setPen(self.pen)
        painter.drawPixmap(self.rect,self.pic)
    
    def initializeSockets(self,type):
        if(self.type=="Flash" or self.type=="CompSep"):
            Input = [NodeSocket(QtCore.QRect(-2.5+5.5,(self.rect.height()*x/(self.nin+1))-8,4,4), self, 'in') for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-7.5,(self.rect.height()*x*0.90/(self.nop+1))-4,4,4), self, 'op') for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="AdiabaticCompressor" or self.type=="AdiabaticExpander"  or self.type =="Mixer" or self.type =="Splitter" or self.type =="Valve" ):
            Input = [NodeSocket(QtCore.QRect(-3.5,(self.rect.height()*x/(self.nin+1))-6,4,4), self, 'in') for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-2.5,(self.rect.height()*x/(self.nop+1))-6,4,4), self, 'op') for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="Cooler" or self.type=="Heater"):
            Input = [NodeSocket(QtCore.QRect(3.5,(self.rect.height()*x/(self.nin+1))-4,4,4), self, 'in') for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-8.0,(self.rect.height()*x/(self.nop+1))-4,4,4), self, 'op') for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="Pump"):
            Input = [NodeSocket(QtCore.QRect(-2.5,(self.rect.height()*x/(self.nin+1))-10,4,4), self, 'in') for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-2.5,-2.5,4,4), self, 'op') for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="DistCol" or self.type=="ShortCol"):
            Input = [NodeSocket(QtCore.QRect(-2.5,(self.rect.height()*x/(self.nin+1))-12,5,5), self, 'in') for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-5.5,(self.rect.height()*1.44*x/(self.nop+1))-67,5,5), self, 'op') for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="MaterialStream"):
            Input = [NodeSocket(QtCore.QRect(-2.5,(self.rect.height()*x/(self.nin+1))-1,4,4), self, 'in') for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-2.5,(self.rect.height()*x/(self.nin+1))-1,4,4), self, 'op') for x in range(1,self.nop+1)]
            return Input,Output

    def mouseMoveEvent(self, event):
        super(NodeItem, self).mouseMoveEvent(event)
        for output in self.Output:
            for line in output.outLines:
                line.pointA = line.source.getCenter()
                line.pointB = line.target.getCenter()
        for input in self.Input:
            for line in input.inLines:
                line.pointA = line.source.getCenter()
                line.pointB = line.target.getCenter()
        self.pos = event.scenePos()
        self.obj.setPos(self.pos)
                
    def mouseDoubleClickEvent(self, event):
        self.setPos(event.scenePos().x()-250,event.scenePos().y())
        self.dockWidget.show()
        
def findMainWindow(self):
    '''
        Global function to find the (open) QMainWindow in application
    ''' 
    app = QApplication.instance()
    for widget in app.topLevelWidgets():
        if isinstance(widget, QMainWindow):
            return widget
    return None
