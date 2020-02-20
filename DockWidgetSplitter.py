from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgetSplitter.ui')

class DockWidgetSplitter(QDockWidget,ui_dialog):

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
        self.dict = {}

    # input data tab
    def inputparamslist(self):
        try:
            print("inputparamslist ", self.inputdict)
        
            self.l1.setText(self.obj.variables['NOO']['name']+":")
            self.le1.setText(str(self.obj.variables['NOO']['value']))
            self.u1.setText(self.obj.variables['NOO']['unit'])
            
            for i in self.obj.CalcType_modes:
                self.cb2.addItem(str(i))

            self.l2.setText(self.obj.variables['CalcType']['name']+":")

            self.l3.setText("Stream 1 :")
            self.u3.setText('')
            self.l4.setText("Stream 2 :")
            self.u4.setText('')
            self.cb2.currentIndexChanged.connect(self.fun)
           

            self.inputdict = [self.le1, self.cb2, self.le3, self.le4]
 
        except Exception as e:
            print(e)

    def fun(self):
        if self.cb2.currentText() == 'Mole Flow Specs':
            self.u3.setText('mol/s')
            self.u4.setText('mol/s')
        elif self.cb2.currentText() == 'Mass Flow Specs':
            self.u3.setText('kg/s')
            self.u4.setText('kg/s')
        else:
            self.u3.setText('')
            self.u4.setText('')
    
    def Show_Error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}
            print("param.inputdict ", self.inputdict)
            self.dict = [int(self.inputdict[0].text()),self.inputdict[1].currentText(), float(self.inputdict[2].text()), float(self.inputdict[3].text())]
            print("param ", self.dict)
            self.obj.paramsetter(self.dict)
            self.hide()
            
        except Exception as e:
            print(e)
