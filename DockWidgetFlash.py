from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgetFlash.ui')

class DockWidgetFlash(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.inputdict = []
        print("constructor ", self.inputdict)
        self.inputparamslist()
        self.btn.clicked.connect(self.param)
        self.dict = []

    def inputparamslist(self):
        try:
            print("inputparamslist ", self.inputdict)
        
            self.l1.setText(self.obj.variables['thermoPackage']['name']+":")
            self.lines = [line.rstrip('\n') for line in open('thermopackage.txt')]
            for j in self.lines:
                self.cb1.addItem(str(j))
            
            self.check1.setText(self.obj.variables['Tdef']['name']+":")
            self.le2.setText(str(self.obj.variables['Tdef']['value']))
            self.u2.setText(self.obj.variables['Tdef']['unit'])
            self.check1.toggled.connect(self.fun)
            self.check2.setText(self.obj.variables['Pdef']['name']+":")
            self.le3.setText(str(self.obj.variables['Pdef']['value']))
            self.u3.setText(self.obj.variables['Pdef']['unit'])
            self.check2.toggled.connect(self.fun)

            self.inputdict = [self.cb1, self.check1, self.le2, self.check2, self.le3]
 
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
    
    def Show_Error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}
            print("param.inputdict ", self.inputdict)
            self.dict = [self.inputdict[0].currentText(),self.inputdict[1].isChecked(), float(self.inputdict[2].text()), self.inputdict[3].isChecked(), float(self.inputdict[4].text())]
            print("param ", self.dict)
            self.obj.paramsetter(self.dict)
            self.hide()
            
        except Exception as e:
            print(e)