import os, sys

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)
sys.path.append(parentPath)

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
from python.utils.ComponentSelector import *
from python.utils.Graphics import *

ui_dialog,_ = loadUiType(parentPath+'/ui/DockWidgets/DockWidgetFlash.ui')

class DockWidgetFlash(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = []
        self.input_params_list()
        self.btn.clicked.connect(self.param)
        self.dict = []  # a list

    def input_params_list(self):
        try:        
            self.l1.setText(self.obj.variables['thermo_package']['name']+":")
            self.lines = [line.rstrip('\n') for line in open(parentPath+'/python/utils/thermopackage.txt')]
            for j in self.lines:
                self.cb1.addItem(str(j))
            self.cb1.setCurrentText(self.obj.variables['thermo_package']['value'])
            
            self.check1.setText(self.obj.variables['Tdef']['name']+":")
            self.le2.setText(str(self.obj.variables['Tdef']['value']))
            self.u2.setText(self.obj.variables['Tdef']['unit'])
            self.check1.toggled.connect(self.fun)
            self.check1.setChecked(self.obj.variables['BTdef']['value'])
            self.check2.setText(self.obj.variables['Pdef']['name']+":")
            self.le3.setText(str(self.obj.variables['Pdef']['value']))
            self.u3.setText(self.obj.variables['Pdef']['unit'])
            self.check2.toggled.connect(self.fun)
            self.check2.setChecked(self.obj.variables['BPdef']['value'])

            self.le2.setFixedWidth(80)
            self.le3.setFixedWidth(80)
            self.cb1.setFixedWidth(80)

            self.input_dict = [self.cb1, self.check1, self.le2, self.check2, self.le3]
 
        except Exception as e:
            print(e)

    def fun(self):
        if self.check1.isChecked():
            self.le2.setDisabled(False)
        else:
            self.le2.setDisabled(True)
        if self.check2.isChecked():
            self.le3.setDisabled(False)
        else:
            self.le3.setDisabled(True)
    
    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict = []
            #print("param.input_dict ", self.input_dict)
            self.dict = [self.input_dict[0].currentText(),self.input_dict[1].isChecked(), float(self.input_dict[2].text()), self.input_dict[3].isChecked(), float(self.input_dict[4].text())]
            #print("param ", self.dict)
            self.obj.param_setter(self.dict)
            if(self.isVisible()):
                currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
                self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)
            self.hide()
            
        except Exception as e:
            print(e)
            
    def closeEvent(self,event):
        scrollHVal = self.parent().container.graphics.graphicsView.horizontalScrollBarVal
        currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
        self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)