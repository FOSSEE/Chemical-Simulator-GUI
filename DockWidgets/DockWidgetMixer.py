from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgets/DockWidgetMixer.ui')

class DockWidgetMixer(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = []
        self.x_pclist = []
        print("constructor ", self.input_dict)
        self.input_params_list()
        self.btn.clicked.connect(self.param)
        self.dict = {}

    # input data tab
    def input_params_list(self):
        try:
            print("input_params_list ", self.input_dict)
        
            self.l1.setText(self.obj.variables['NI']['name']+":")
            self.le1.setText(str(self.obj.variables['NI']['value']))
            self.u1.setText(self.obj.variables['NI']['unit'])
            for i in self.obj.Pout_modes:
                self.cb2.addItem(str(i))

            self.l2.setText(self.obj.variables['outPress']['name']+":")
           

            self.input_dict = [self.le1, self.cb2]
 
        except Exception as e:
            print(e)
    
    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}
            print("param.input_dict ", self.input_dict)
            self.dict = [int(self.input_dict[0].text()), '"' + self.input_dict[1].currentText() + '"']
            print("param ", self.dict)
            self.obj.param_setter(self.dict)
            self.hide()
            
        except Exception as e:
            print(e)