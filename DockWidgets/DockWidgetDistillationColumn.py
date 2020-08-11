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
            
            l1 = QLineEdit()
            self.lay1.addWidget(QLabel(self.obj.variables['Nt']['name'] + " :"), 0 ,0, alignment=Qt.AlignLeft) 
            self.lay1.addWidget(l1,0,1, alignment=Qt.AlignCenter)
            self.input_dict.append(l1)     

            for i in range(self.obj.variables['Ni']['value']):
                print(i)
                l = QLineEdit()   
                self.lay1.addWidget(QLabel(self.obj.variables['InT_s']['name'] +" " + str(i+1) + " location :"),i+1,0, alignment=Qt.AlignLeft) 
                self.lay1.addWidget(l,i+1,1, alignment=Qt.AlignCenter)
                self.input_dict.append(l)

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

            self.input_dict.append(self.cb5)
            self.input_dict.append(self.le5)
            self.input_dict.append(self.cb1) 
            self.input_dict.append(self.cb2)
            self.input_dict.append(self.le6)                      

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

            self.input_dict.append(self.le7)
            self.input_dict.append(self.cb3)
            self.input_dict.append(self.cb4) 
            self.input_dict.append(self.le8)

            # self.input_dict = [self.le1, self.le2, self.le3, self.cb5, self.le5, self.cb1, self.cb2, self.le6, self.le7, self.cb3, self.cb4, self.le8]
             
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
            temp = 0
            print("param.input_dict ", self.input_dict)
            self.dict.append(int(self.input_dict[0].text()))
            
            for i in range(self.obj.variables['Ni']['value']):
                self.dict.append(int(self.input_dict[i+1].text()))
                temp = i + 1
                print(temp)

            print(temp)
            print(self.input_dict[temp+1])
            self.dict.append(self.input_dict[temp+1].currentText())
            print(temp+1)
            self.dict.append(int(self.input_dict[temp+2].text()))
            print(temp+2)
            self.dict.append(self.input_dict[temp+3].currentText())
            print(temp+3)
            self.dict.append(self.input_dict[temp+4].currentText())
            print(temp+4)
            self.dict.append(int(self.input_dict[temp+5].text()))
            print(temp+5)
            self.dict.append(int(self.input_dict[temp+6].text()))
            print(temp+6)
            self.dict.append(self.input_dict[temp+7].currentText())
            print(temp+7)
            self.dict.append(self.input_dict[temp+8].currentText())
            print(temp+8)
            self.dict.append(int(self.input_dict[temp+9].text()))
            print(temp+9)
            
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