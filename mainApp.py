from functools import partial
from collections import defaultdict
import sys
import numpy as np
from OMChem.Flowsheet import Flowsheet
from OMChem.MatStm import MatStm
from OMChem.Mixer import Mixer
from OMChem.Heater import Heater
from OMChem.Splitter import Splitter
import pandas as pd
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QTextDocument ,QTextCursor ,QTextCharFormat ,QFont ,QPixmap
from PyQt5.uic import loadUiType
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGraphicsProxyWidget, QGraphicsObject, QGraphicsEllipseItem ,QGraphicsPixmapItem,QApplication, QGraphicsView, QGraphicsScene, QHBoxLayout, QWidget, QLabel, QUndoStack
from PyQt5.QtGui import QBrush ,QTransform ,QMouseEvent
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
from component_selector import *
from dockWidget import dockWidget
from resDockWidget import resdockWidget
from UnitOperations import *
import datetime
from container import Container
from Graphics import Graphics
import pickle
import threading
import os
import ctypes
import sys

ui,_ = loadUiType('main.ui')

# comp_dict is a dictionary in which keys are the type of component and value is a list [counter_of_that_particular_type ,Number of ip,Number of op]
#comp_dict ={'MatStm':[1,1,1],'EngStm':[1,1,1],'Mixer':[1,4,1],'Splitter':[1,1,4],'Flash':[1,1,2],'Heater':[1,1,1],'Valve':[1,1,1],'Cooler':[1,1,1],'CompSep':[1,1,2],'Pump':[1,1,1],'AdiaComp':[1,1,1],'AdiaExp':[1,1,1],'DistCol':[1,2,2],'ShortCol':[1,1,2]}

'''
    MainApp class is responsible for all the main App Ui operations
'''
class MainApp(QMainWindow,ui):
    '''
        Initializing the application
    '''
    def __init__(self):
        QMainWindow.__init__(self)
        
        # Loading and setting up style sheet
        self.setupUi(self)
        style = open('light.css','r')
        style = style.read()
        self.setStyleSheet(style)
        
        # Initializing attributes
        self.zoomcount = 0
        self.thrd = None

        # Creating instances of classes for the main app
        self.Container = Container(self.textBrowser)        
        self.comp = componentSelector(self)
        '''self.Container = self.graphics.getContainer(self.textBrowser)
        self.comp = self.graphics.getComponentSelector()'''
        

        # Setting up interactive canvas        
        '''self.scene = QGraphicsScene()
        self.scene.setItemIndexMethod(QGraphicsScene.BspTreeIndex)
        self.graphicsView.setScene(self.scene)
        self.graphicsView.setMouseTracking(True)
        self.graphicsView.keyPressEvent=self.deleteCall'''
        self.graphics = Graphics()
        self.scene = self.graphics.getScene()
        self.graphicsView.setScene(self.scene)
        self.graphicsView.setMouseTracking(True)
        self.graphicsView.keyPressEvent=self.deleteCall
        
        self.setDockNestingEnabled(True)
        self.setCorner(Qt.BottomRightCorner, Qt.RightDockWidgetArea)
        self.setCorner(Qt.BottomLeftCorner, Qt.LeftDockWidgetArea)
        self.addDockWidget(Qt.BottomDockWidgetArea,self.dockWidget_2)
        
        # Setting up undo stack
        # self.undoStack = QUndoStack(self)
        
        # Calling initialisation functions
        self.buttonHandler()
        self.menuBar()
        self.comp.show()
        

    '''
        MenuBar function handels all the all the operations of 
        menu bar like new,zoom,comounds selector, simulation options.
    '''    
    def menuBar(self):
        self.actionSelect_compounds.triggered.connect(self.selectCompounds)
        self.actionSelect_compounds.setShortcut('Ctrl+C')
        self.actionZoomIn.triggered.connect(self.zoomin)
        self.actionZoomIn.setShortcut('Ctrl++')
        self.actionNew_Flowsheet.triggered.connect(self.new)
        self.actionNew_Flowsheet.setShortcut('Ctrl+N')
        self.actionZoomOut.triggered.connect(self.zoomout)
        self.actionZoomOut.setShortcut('Ctrl+-')
        self.actionResetZoom.triggered.connect(self.zoomReset)
        self.actionResetZoom.setShortcut('Ctrl+R')
        self.actionHelp.triggered.connect(self.help)
        self.actionHelp.setShortcut('Ctrl+H')
        self.actionSequential_mode.triggered.connect(partial(self.simulate,'SM'))
        self.actionSequential_mode.setShortcut('Ctrl+M')
        self.actionEquation_oriented.triggered.connect(partial(self.simulate,'EQN'))
        self.actionEquation_oriented.setShortcut('Ctrl+E')
        # self.actionUndo_2.triggered.connect(self.undoStack.undo)
        # self.actionRedo.triggered.connect(self.undoStack.redo)
        self.actionSave_2.triggered.connect(self.save)
        self.actionSave_2.setShortcut('Ctrl+S')
        self.actionOpen.triggered.connect(self.open)
        self.actionOpen.setShortcut('Ctrl+O')
        self.actionTerminate.triggered.connect(self.terminate)
        self.actionTerminate.setShortcut('Ctrl+T')


    '''
        Handles all the buttons of different components.
    '''
    def buttonHandler(self):
        self.pushButton.clicked.connect(partial(self.component,'MatStm'))
        self.pushButton_7.clicked.connect(partial(self.component,'Mixer'))
        self.pushButton_14.clicked.connect(partial(self.component,'Pump'))
        self.pushButton_26.clicked.connect(partial(self.component,'DistCol'))
        self.pushButton_18.clicked.connect(partial(self.component,'ShortCol'))
        self.pushButton_11.clicked.connect(partial(self.component,'Heater'))
        self.pushButton_10.clicked.connect(partial(self.component,'Splitter'))
        self.pushButton_9.clicked.connect(partial(self.component,'Flash'))
        self.pushButton_25.clicked.connect(partial(self.component,'Valve'))
        self.pushButton_12.clicked.connect(partial(self.component,'Cooler'))
        self.pushButton_13.clicked.connect(partial(self.component,'CompSep'))
        self.pushButton_15.clicked.connect(partial(self.component,'AdiaComp'))
        self.pushButton_16.clicked.connect(partial(self.component,'AdiaExp'))
    
    '''
        Displays help box
    '''
    def help(self):
        msgBox = QMessageBox() 
        msgBox.setIcon(QMessageBox.Question)
        msgBox.setTextFormat(Qt.RichText);   
        msgBox.setText("For any Help or Suggestion you can contact us at\n contact-om@fossee.in or at <a href='https://www.fossee.in'>Visit fossee.in!</a>")
        msgBox.setStandardButtons(QMessageBox.Ok)
        msgBox.exec_()

    '''
        Shows Compounds Selector Dialog
    '''
    def selectCompounds(self):
        self.comp.show()

    '''
        Returns currenttime in a required particular format
    '''
    def currentTime(self):
        now = datetime.datetime.now()
        time = str(now.hour) + ":" + str(now.minute) + ":" +str(now.second)
        return time

    '''
        Simulate function is responsible for the simulation
        of the designed flowsheet in a particular mode
        selected by the user.
    '''
    def simulate(self,mode):
        self.thrd = threading.Thread(target=self.Container.simulate, args=(mode,))
        self.thrd.start()
        # self.Container.simulate(mode)
        self.dockWidget_2.show()
        self.res = resdockWidget(self.Container)
        self.addDockWidget(Qt.LeftDockWidgetArea, self.res)
        self.res.show()
    
    def terminate(self):
        os.chdir(self.Container.flowsheet.root_dir)
        if self.thrd:
            thread_id = self.thrd.ident
            print('____________________Going to terminate simulation thread with Thread ID:',thread_id,'____________________')
            print('____________________Going to terminate the new process created for omc____________________')
            self.Container.flowsheet.process.terminate()
            print('____________________New process created for omc is terminated.____________________')
            res = ctypes.pythonapi.PyThreadState_SetAsyncExc(thread_id, ctypes.py_object(SystemExit)) 
            self.textBrowser.append("<span style=\"color:red\">["+str(self.currentTime())+"]<b> Terminating the simulation </b></span>")
            print('____________________Simulation thread terminated____________________')
            if res > 1: 
                ctypes.pythonapi.PyThreadState_SetAsyncExc(thread_id, 0) 
                print('Exception raise (Thread termination) failure')


    '''
        Resets the zoom level to default scaling
    '''
    def zoomReset(self):
        if(self.zoomcount>0):
            for i in range(self.zoomcount):
                self.zoomout()
        elif(self.zoomcount<0): 
            for i in range(abs(self.zoomcount)):
                self.zoomin()

    '''
        ZoomOut the canvas
    '''
    def zoomout(self):
        self.graphicsView.scale(1.0/1.15,1.0/1.15)
        self.zoomcount -=1
    
    '''
        ZoomIn the canvas
    '''
    def zoomin(self):
        self.graphicsView.scale(1.15,1.15)
        self.zoomcount +=1
  
    '''
        Instantiate a NodeItem object for selected type of
        component and added that on canvas/flowsheeting area.
    '''    
    def component(self,unitOpType):
        if(self.comp.isCompSelected()):
            self.type = unitOpType
            if(self.type=="MatStm"):
                self.obj = MatStm(CompNames=compound_selected)  
            else:
                self.obj = eval(self.type+"Class")()
            self.Container.addUnitOp(self.obj,self.scene,self.graphics)
        else:
            QMessageBox.about(self, 'Important', "Please Select Compounds first")
            self.comp.show()


    '''
        New is used to delete all the existing work.
    '''        
    def new(self):
        l=self.scene.items()
        compound_selected.clear()
        self.comp.tableWidget.setRowCount(0)
        self.delete(l)
        self.textBrowser.append("<span>["+str(self.currentTime())+"] <b>New</b> flowsheet is created ... </span>")
        self.comp.show()

    '''
        Handels all the operations which will happen when delete button is pressed.
    '''
    def deleteCall(self,event):
        try:
            if event.key() == QtCore.Qt.Key_Delete:
                l=self.scene.selectedItems()
                self.delete(l)
        except Exception as e:
            print(e)

    '''
        Deletes the selected item from the canvas and also the objects 
        created for that type.
    '''
    def delete(self,l):
        # if isinstance(l,NodeItem):
            # l = [l]
        for item in l:
            self.scene.removeItem(item)
            if hasattr(item,'Input'):
                for x in item.Input:

                    if x.newLine:
                        
                        self.scene.removeItem(x.newLine)
                        del x.newLine
                        
                    if x.otherLine:
                        
                        self.scene.removeItem(x.otherLine)
                        del x.otherLine
            if hasattr(item,'Output'):
                for x in item.Output:
                    if x.newLine:
                                           
                        self.scene.removeItem(x.newLine)
                        del x.newLine
                        
                    if x.otherLine:
                    
                        self.scene.removeItem(x.otherLine)
                        del x.otherLine
            if hasattr(item,'obj'):
                self.Container.unitOp.remove(item.obj)
                for k in list(self.Container.conn):
                    if item.obj==k:
                        del self.Container.conn[k]

                    elif item.obj in self.Container.conn[k]:
                        self.Container.conn[k].remove(item.obj)
                self.textBrowser.append("<span style=\"color:blue\">["+str(self.currentTime())+"]<b> "+item.obj.name+" </b>is deleted .""</span>")
                del item.obj
            del item
    
    '''
        Function for saving the current canvas items and compound_selected
    '''
    def save(self):
        def jdefault(o):
            return o.__dict__

        data = []
        for i in self.Container.unitOp:
            data.append(i)
        
        data.append(self.comp.getComp())

        fileFormat = 'sim'
        initialPath = QDir.currentPath() + 'untitled.' + fileFormat
        fileName, _ = QFileDialog.getSaveFileName(self, "Save As",
                                                  initialPath, "%s Files (*.%s);; All Files (*)" %
                                                  (fileFormat.upper(), fileFormat))
        with open(fileName, 'wb') as f: #'saved_file.sim'
            pickle.dump(data, f, pickle.HIGHEST_PROTOCOL)

    '''
        Function for loading previous saved canvas and simulation 
        ***Not finished yet***
    '''
    def open(self):
        fileFormat = 'sim'
        initialPath = QDir.currentPath() + 'untitled.' + fileFormat
        fileName, _ = QFileDialog.getOpenFileName(self, "Open As",
                                                  initialPath, "%s Files (*.%s);; All Files (*)" %
                                                  (fileFormat.upper(), fileFormat))
        with open(fileName, 'rb') as f:
            obj = pickle.load(f)
        
        for i in obj:
            print(i)

def main():
    app = QApplication(sys.argv)
    window = MainApp()
    window.showMaximized()
    app.exec()

if __name__ == '__main__':
    main()
