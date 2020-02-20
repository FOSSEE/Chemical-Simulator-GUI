from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgetMixer.ui')

class DockWidgetMixer(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.inputdict = []
        self.x_pclist = []
        print("constructor ", self.inputdict)
        self.inputparamslist()
        self.btn.clicked.connect(self.param)
        self.dict = {}

    # input data tab
    def inputparamslist(self):
        try:
            print("inputparamslist ", self.inputdict)
        
            self.l1.setText(self.obj.variables['NOI']['name']+":")
            self.le1.setText(str(self.obj.variables['NOI']['value']))
            self.u1.setText(self.obj.variables['NOI']['unit'])
            for i in self.obj.Pout_modes:
                self.cb2.addItem(str(i))

            self.l2.setText(self.obj.variables['Pout']['name']+":")
           

            self.inputdict = [self.le1, self.cb2]
 
        except Exception as e:
            print(e)
    
    def Show_Error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}
            print("param.inputdict ", self.inputdict)
            self.dict = [int(self.inputdict[0].text()),self.inputdict[1].currentText()]
            print("param ", self.dict)
            self.obj.paramsetter(self.dict)
            self.hide()
            
        except Exception as e:
            print(e)