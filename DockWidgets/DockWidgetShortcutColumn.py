from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgets/DockWidgetShortcutColumn.ui')

class DockWidgetShortcutColumn(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = []
        print("constructor ", self.input_dict)
        self.input_params_list()
        self.btn.clicked.connect(self.param)
        self.dict = []

        self.name_type = None
        self.container = container

    # input data tab
    def input_params_list(self):
        try:
            print("input_params_list ", self.input_dict)
        
            self.l1.setText(self.obj.variables['HKey']['name']+":")
            print(self.obj.compounds)
            for i in self.obj.compounds:
                self.cb1.addItem(str(i))
                self.cb2.addItem(str(i))

            self.l2.setText(self.obj.variables['LKey']['name']+":")

            self.l3.setText(self.obj.variables['HKey_x_pc']['name']+":")
            self.le3.setText(str(self.obj.variables['HKey_x_pc']['value']))
            self.u3.setText(self.obj.variables['HKey_x_pc']['unit'])
            self.l4.setText(self.obj.variables['LKey_x_pc']['name']+":")
            self.u4.setText(self.obj.variables['LKey_x_pc']['unit'])
            self.le4.setText(str(self.obj.variables['LKey_x_pc']['value']))

            self.l5.setText(self.obj.variables['Ctype']['name']+":")
            self.cb5.addItem('Total')
            self.cb5.addItem('Partial')

            self.l6.setText(self.obj.variables['Pcond']['name']+":")
            self.le6.setText(str(self.obj.variables['Pcond']['value']))
            self.u6.setText(self.obj.variables['Pcond']['unit'])
            self.l7.setText(self.obj.variables['Preb']['name']+":")
            self.u7.setText(self.obj.variables['Preb']['unit'])
            self.le7.setText(str(self.obj.variables['Preb']['value']))
            
            self.l8.setText(self.obj.variables['RR']['name']+":") 
            self.le8.setText(str(self.obj.variables['RR']['value']))

            self.input_dict = [self.cb1, self.cb2, self.le3, self.le4, self.cb5, self.le6, self.le7, self.le8]
 
        except Exception as e:
            print(e)
    
    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict=[]
            print("param.input_dict ", self.input_dict)
            self.dict = [self.input_dict[0].currentText(),self.input_dict[1].currentText(),float(self.input_dict[2].text()), float(self.input_dict[3].text()),
                        self.input_dict[4].currentText(), float(self.input_dict[5].text()), float(self.input_dict[6].text()), float(self.input_dict[7].text())]
            
            print("param ", self.dict)
            self.obj.param_setter(self.dict)
            self.hide()
            
        except Exception as e:
            print(e)


    @staticmethod
    def show_result(lst):
        #DockWidget1.flag = True
        for i in lst:
            i.resultsCategory(i.name)
            #i.show()
        
    # result data tab
    def results_category(self,name):
        pass