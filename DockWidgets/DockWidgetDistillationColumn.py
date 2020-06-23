from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgets/DockWidgetDistillationColumn.ui')

class DockWidgetDistillationColumn(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = []
        print("constructor ", self.input_dict)
        self.pushButton_2.clicked.connect(self.param)
        self.dict = []
        self.input_params_list()
        self.name_type = None
        self.container = container

    # input data tab
            
    def input_params_list(self):
        try:
            print("input_params_list ", self.input_dict)
        
            # tab 1
            self.l1.setText(self.obj.variables['Nt']['name']+":")
            self.le1.setText(str(self.obj.variables['Nt']['value']))
            self.l2.setText(self.obj.variables['In_s']['name']+":")
            self.l3.setText(self.obj.variables['InT_s']['name']+":")

            # tab 2
            self.l4.setText(self.obj.variables['Ctype']['name']+":")
            self.u1.setText(self.obj.variables['Ctype']['unit'])
            self.l5.setText(self.obj.variables['Pcond']['name']+":")
            self.le5.setText(str(self.obj.variables['Pcond']['value']))
            self.u2.setText(self.obj.variables['Pcond']['unit'])
            self.l6.setText(self.obj.variables['C_Spec']['name']+":")
            self.l7.setText("Compounds :")

            self.cb5.addItem("Total")
            self.cb5.addItem("Partial")
            for j in self.obj.Cspec_list:
                self.cb1.addItem(str(j))
            for j in self.obj.compounds:
                self.cb2.addItem(str(j))
            self.cb2.setDisabled(True)  
            self.cb1.currentIndexChanged.connect(self.fun2)      
            

            # tab3
            self.l8.setText(self.obj.variables['Preb']['name']+":")
            self.le7.setText(str(self.obj.variables['Preb']['value']))
            self.u3.setText(self.obj.variables['Preb']['unit'])
            self.l9.setText(self.obj.variables['R_Spec']['name']+":")
            self.l10.setText('Compounds')
        
            for j in self.obj.Rspec_list:
                self.cb3.addItem(str(j))
            for j in self.obj.compounds:
                self.cb4.addItem(str(j))
            self.cb4.setDisabled(True)
            self.cb3.currentIndexChanged.connect(self.fun3)

            self.input_dict = [self.le1, self.le2, self.le3, self.cb5, self.le5, self.cb1, self.cb2, self.le6, self.le7, self.cb3, self.cb4, self.le8]
             
        except Exception as e:
            print(e)

    def fun2(self):
        if self.cb1.currentText() == 'Compound Molar Fraction' or self.cb1.currentText() == 'Compound Molar Flow    (mol/s)':
            self.cb2.setDisabled(False)
        else:
            self.cb2.setDisabled(True)
    
    def fun3(self):
        if self.cb3.currentText() == 'Compound Molar Fraction' or self.cb3.currentText() == 'Compound Molar Flow    (mol/s)':
            self.cb4.setDisabled(False)
        else:
            self.cb4.setDisabled(True)
    
    def Show_Error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict= []
            print("param.input_dict ", self.input_dict)
            self.dict = [self.input_dict[0].text(),self.input_dict[1].text(),         self.input_dict[2].text(),           self.input_dict[3].currentText(),
                        self.input_dict[4].text(), self.input_dict[5].currentText(),  self.input_dict[6].currentText(),    self.input_dict[7].text(),
                        self.input_dict[8].text(), self.input_dict[9].currentText(),  self.input_dict[10].currentText(),   self.input_dict[11].text()]
            
            print("param ", self.dict)
            self.obj.param_setter(self.dict)
            self.hide()
            
        except Exception as e:
            print(e)


    @staticmethod
    def showResult(lst):
        #DockWidget1.flag = True
        for i in lst:
            i.resultsCategory(i.name)
            #i.show()
        
    # result data tab
    def resultsCategory(self,name):
        pass