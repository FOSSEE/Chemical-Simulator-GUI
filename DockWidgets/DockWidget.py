from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgets/DockWidget.ui')

class DockWidget(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container, parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = {}
        self.x_pclist = []
        self.modes()
        self.comboBox.currentIndexChanged.connect(self.mode_selection)
       
        print("constructor ", self.input_dict)
        self.pushButton_2.clicked.connect(self.param)
        self.dict = {}

        self.name_type = None
        self.container = container
        
    # input data tab
    def modes(self):
        modes_list = self.obj.modes_list
        if(modes_list):
            for j in modes_list:
                self.comboBox.addItem(str(self.obj.variables[j]['name']))
            self.mode_selection()
        else:
            self.comboBox.setDisabled(True)
            self.input_dict= {}
            self.input_dict = self.obj.param_getter()
            self.input_params_list()

    def mode_selection(self):
        self.input_dict= {}
        for i in reversed(range(self.formLayout.count())):
            self.formLayout.removeRow(i) 
        print(self.comboBox.currentText())
        for i in self.obj.variables:
            if self.obj.variables[i]['name'] == self.comboBox.currentText():
                currentText = i
                break
        self.input_dict = self.obj.param_getter(currentText)
        print('mode selection ', self.input_dict)
        self.input_params_list()
            
    def input_params_list(self):
        try:
            print("input_params_list ", self.input_dict)
            for c,i in enumerate(self.input_dict):
                if i == None:
                    continue
                if(i=="thermo_package"):
                    print("thermo1")
                    combo = QComboBox()
                    self.lines = [line.rstrip('\n') for line in open('thermopackage.txt')]
                    print("thermo2")
                    for j in self.lines:
                        combo.addItem(str(j))
                    combo.setMinimumContentsLength(15)
                    lay = QGridLayout()
                    lay.addWidget(QLabel(i+":"), 0,0, alignment=Qt.AlignLeft)
                    lay.addWidget(combo, 0, 1, alignment=Qt.AlignCenter)
                    lay.addWidget(QLabel(''), 0, 2, alignment = Qt.AlignCenter)
                    self.formLayout.addRow(lay)
                    self.input_dict[i] = combo   
                    print("thermo")
                elif(i=="Ctype"):
                    combo = QComboBox()
                    self.lines = ["Total","Partial"]
                    for j in self.lines:
                        combo.addItem(str(j))
                    combo.setMinimumContentsLength(15)
                    lay = QGridLayout()
                    lay.addWidget(QLabel("Condensor Type :"), 0, 0, alignment=Qt.AlignLeft)
                    lay.addWidget(combo, 0, 1, alignment=Qt.AlignCenter)
                    lay.addWidget(QLabel(''), 0, 2, alignment = Qt.AlignCenter)
                    self.formLayout.addRow(lay)
                    self.input_dict[i] = combo
                elif(i=="x_pc"):
                    noc = len(compound_selected)
                    print(noc)
                    self.x_pclist.clear()
                    gp = QGroupBox("Compounds")
                    lay = QGridLayout()
                    for j in range(noc):
                        l = QLineEdit()    
                        self.input_dict[i] = "x_pc"
                        lay.addWidget(QLabel(str(compound_selected[j])+":"),j,0, alignment=Qt.AlignLeft)
                        lay.addWidget(l,j,1, alignment=Qt.AlignCenter)
                        lay.addWidget(QLabel(self.obj.variables[i]['unit']),j,2, alignment=Qt.AlignCenter)                                      
                        self.x_pclist.append(l)
                    gp.setLayout(lay)
                    self.formLayout.addRow(gp)       
                else:
                    print("elseloop")
                    print(i)
                    if i == None:
                        continue
                    l = QLineEdit()
                    if self.input_dict[i] != None:
                        l.setText(str(self.input_dict[i]))
                    print('before lay')
                    lay = QGridLayout()
                    lay.addWidget(QLabel(self.obj.variables[i]['name']+":"),0,0, alignment=Qt.AlignLeft) #self.obj.variables[i]['name']
                    lay.addWidget(l,0,1, alignment=Qt.AlignCenter)
                    print('after lay')
                    if(i != 'MolFlow'):
                        lay.addWidget(QLabel(self.obj.variables[i]['unit']),0,2, alignment=Qt.AlignCenter)
                    else:
                        lay.addWidget(QLabel('mol/s'),0,2, alignment=Qt.AlignCenter)
                    print('after all')
                    self.formLayout.addRow(lay)
                    self.input_dict[i] = l
                    
            
        except Exception as e:
            print(e)

    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}
            print("param.input_dict ", self.input_dict)
            for i in self.input_dict:
                if (self.input_dict[i] == None):
                    continue                  
                if(i=="thermo_package"):
                    if (self.input_dict[i].currentText()):
                        self.dict[i] = self.input_dict[i].currentText()
                    else:
                        self.show_error()
                        break
                elif(i=="Ctype"):
                    if (self.input_dict[i].currentText()):
                        self.dict[i] = self.input_dict[i].currentText()
                    else:
                        self.show_error()
                        break
                elif(i =="x_pc"):
                    l=[]
                    mf = []
                    total_moles = 0
                    for mol_frac in self.x_pclist:
                        if (mol_frac.text()):
                            l.append(mol_frac.text())
                            total_moles += float(l[-1])
                        else:
                            self.show_error()
                            break
                    for c in range(len(compound_selected)):
                        mf.append(str(float(l[c])/total_moles))
                        self.x_pclist[c].setText(mf[-1])
                    self.dict[i] = ",".join(mf)
                elif(i == 'Pout' and self.obj.type == 'Mixer' or i == '' or i == 'HKey' or i == 'LKey'):
                    self.dict[i] = self.input_dict[i].currentText()
                else:
                    print(self.input_dict[i], i, self.obj.type)
                    if (self.input_dict[i].text()):
                        self.dict[i] = self.input_dict[i].text()
                    else:
                        print(self.input_dict[i].text())
                        self.show_error()
                        break
            
            print("param ", self.dict)
            self.obj.param_setter(self.dict)
            self.hide()
            
        except Exception as e:
            print(e)

    @staticmethod
    def show_result(lst):
        #DockWidget1.flag = True
        for i in lst:
            i.results_category(i.name)
            #i.show()
        
    # result data tab
    def results_category(self,name):
        flag = True
        try:
            print("Under result category name ", name)
            result=self.container.result
            obj = self.container.fetch_object(name)
            self.tableWidget.setRowCount(0)
            variKeys = list(obj.variables.keys())
            print(variKeys)
            for i, val in enumerate(variKeys):
                propertyname = name + '.' + val
                print(i,val, propertyname)
                if propertyname in result[0]:
                    ind = result[0].index(propertyname)
                    resultval = str(result[-1][ind])
                    print("######Resultsfetch####",val,resultval)
                    rowPosition = self.tableWidget.rowCount()
                    self.tableWidget.insertRow(rowPosition)
                    self.tableWidget.setItem(rowPosition , 0, QTableWidgetItem(obj.variables[val]['name']))
                    self.tableWidget.setItem(rowPosition , 1, QTableWidgetItem(resultval))
                    self.tableWidget.setItem(rowPosition , 2, QTableWidgetItem(obj.variables[val]['unit']))
                    self.tableWidget.resizeColumnsToContents()

        except Exception as e:
            print(e)