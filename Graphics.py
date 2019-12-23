from functools import partial
from collections import defaultdict
import sys
import numpy as np
from OMChem.Flowsheet import Flowsheet
from OMChem.MatStm import MatStm
from OMChem.Mixer import Mixer
from OMChem.Heater import Heater
from OMChem.Splitter import Splitter
from OMChem.ShortcutColumn import ShortcutColumn

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
from resDockWidget import resdockWidget
from helper import helperFunc
import datetime
from container import Container

class Graphics(QDialog):

    def __init__(self):
        QDialog.__init__(self)
        self.scene = QGraphicsScene()
        self.scene.setItemIndexMethod(QGraphicsScene.BspTreeIndex) 
    
    def getScene(self):
        return self.scene

    '''def getContainer(self, textBrowser):
        return Container(textBrowser)

    def getComponentSelector(self):
        return componentSelector(self)'''

    def createNodeItem(self, conntype, container):
        return NodeItem(conntype, container)

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
        self.setPath(path)

    def paint(self, painter, option, widget):
        painter.setPen(self.pen)
        painter.drawPath(self.path())
 
    @property
    def pointA(self):
        #print('a')
        return self._pointA
 
    @pointA.setter
    def pointA(self, point):
        #print('seta')
        self._pointA = point
        self.updatePath()
 
    @property
    def pointB(self):
        #print('b')
        return self._pointB
 
    @pointB.setter
    def pointB(self, point):
        #print('set b')
        self._pointB = point
        self.updatePath()
 
    @property
    def source(self):
        #print('source')
        return self._source
 
    @source.setter
    def source(self, widget):
        #print('set source')
        self._source = widget
 
    @property
    def target(self):
        #print('target')
        return self._target
 
    @target.setter
    def target(self, widget):
        #print('set target')
        self._target = widget

    def __delete__(self,instance):
        del self._source
        del self._target
        del self._pointA
        del self._pointB
 
class NodeSocket(QtWidgets.QGraphicsItem):
    def __init__(self, rect, parent, socketType,container):
        super(NodeSocket, self).__init__(parent)
        self.rect = rect
        self.type = socketType
        self.parent=parent
        self.container=container
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
        item.otherLine=self.newLine
        if (self.type == 'op') and (item.type == 'in'):
            self.newLine.source = self
            self.newLine.target = item
            item.inLines.append(self.newLine)
            self.newLine.pointB = item.getCenter()
            self.container.updateConn(self.newLine.source.parent.obj,self.newLine.target.parent.obj)
        elif (self.type =='in') and (item.type == 'op'):
            self.newLine.source = item
            self.newLine.target = self
            item.outLines.append(self.newLine)
            self.newLine.pointA = item.getCenter()
            self.container.updateConn(self.newLine.source.parent.obj,self.newLine.target.parent.obj)                
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
 
class NodeItem(QtWidgets.QGraphicsItem):
    def __init__(self,comptype,container):
        l = ['Mixer','Splitter']
        super(NodeItem, self).__init__()
        self.type = comptype
        
        # for creating unit operation objects without helper function
        if (self.type == 'MatStm'):
            self.obj = MatStm(CompNames=compound_selected)
        elif (self.type == 'ShortCol'):     # the only class that class name and type does not match
            self.obj = ShortcutColumn()
        else:
            self.obj = eval(self.type)()


        #self.obj = myhelperFunc(self.type) 
        self.name = self.obj.getname()
        self.pos = None
        self.setToolTip(self.name)
        self.nin = self.obj.no_of_input
        self.nop = self.obj.no_of_output
    
        self.container=container
        self.container.addUnitOp(self.obj)
        if(self.type not in l):
            self.mainwindow= findMainWindow(self)
            self.dockWidget=dockWidget(self.name,self.type,self.obj)
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
            Input = [NodeSocket(QtCore.QRect(-2.5+5.5,(self.rect.height()*x/(self.nin+1))-8,4,4), self, 'in',self.container) for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-7.5,(self.rect.height()*x*0.90/(self.nop+1))-4,4,4), self, 'op',self.container) for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="AdiaComp" or self.type=="AdiaExp"  or self.type =="Mixer" or self.type =="Splitter" or self.type =="Valve" ):
            Input = [NodeSocket(QtCore.QRect(-3.5,(self.rect.height()*x/(self.nin+1))-6,4,4), self, 'in',self.container) for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-2.5,(self.rect.height()*x/(self.nop+1))-6,4,4), self, 'op',self.container) for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="Cooler" or self.type=="Heater"):
            Input = [NodeSocket(QtCore.QRect(3.5,(self.rect.height()*x/(self.nin+1))-4,4,4), self, 'in',self.container) for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-8.0,(self.rect.height()*x/(self.nop+1))-4,4,4), self, 'op',self.container) for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="Pump"):
            Input = [NodeSocket(QtCore.QRect(-2.5,(self.rect.height()*x/(self.nin+1))-10,4,4), self, 'in',self.container) for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-2.5,-2.5,4,4), self, 'op',self.container) for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="DistCol" or self.type=="ShortCol"):
            Input = [NodeSocket(QtCore.QRect(-2.5,(self.rect.height()*x/(self.nin+1))-12,5,5), self, 'in',self.container) for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-5.5,(self.rect.height()*1.44*x/(self.nop+1))-67,5,5), self, 'op',self.container) for x in range(1,self.nop+1)]
            return Input,Output
        elif(self.type=="MatStm"):
            Input = [NodeSocket(QtCore.QRect(-2.5,(self.rect.height()*x/(self.nin+1))-1,4,4), self, 'in',self.container) for x in range(1,self.nin+1) ]
            Output = [NodeSocket(QtCore.QRect(self.rect.width()-2.5,(self.rect.height()*x/(self.nin+1))-1,4,4), self, 'op',self.container) for x in range(1,self.nop+1)]
            return Input,Output

    def mouseMoveEvent(self, event):
        #print(event.scenePos())
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
