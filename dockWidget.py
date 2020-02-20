from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidget.ui')

class DockWidget(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container, parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.inputdict = {}
        self.x_pclist = []
        self.modes()
        self.comboBox.currentIndexChanged.connect(self.modeSelection)
       
        print("constructor ", self.inputdict)
        self.pushButton_2.clicked.connect(self.param)
        self.dict = {}

        self.nameType = None
        self.container = container
        
    # input data tab
    def modes(self):
        modesList = self.obj.modesList
        if(modesList):
            for j in modesList:
                self.comboBox.addItem(str(self.obj.variables[j]['name']))
            self.modeSelection()
        else:
            self.comboBox.setDisabled(True)
            self.inputdict= {}
            self.inputdict = self.obj.paramgetter()
            self.inputparamslist()

    def modeSelection(self):
        self.inputdict= {}
        for i in reversed(range(self.formLayout.count())):
            self.formLayout.removeRow(i) 
        print(self.comboBox.currentText())
        for i in self.obj.variables:
            if self.obj.variables[i]['name'] == self.comboBox.currentText():
                currentText = i
                break
        self.inputdict = self.obj.paramgetter(currentText)
        print('mode selection ', self.inputdict)
        self.inputparamslist()
            
    def inputparamslist(self):
        try:
            print("inputparamslist ", self.inputdict)
            for c,i in enumerate(self.inputdict):
                if i == None:
                    continue
                if(i=="thermoPackage"):
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
                    self.inputdict[i] = combo   
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
                    self.inputdict[i] = combo
                elif(i=="x_pc"):
                    noc = len(compound_selected)
                    print(noc)
                    self.x_pclist.clear()
                    gp = QGroupBox("Compounds")
                    lay = QGridLayout()
                    for j in range(noc):
                        l = QLineEdit()    
                        self.inputdict[i] = "x_pc"
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
                    if self.inputdict[i] != None:
                        l.setText(str(self.inputdict[i]))
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
                    self.inputdict[i] = l
                    
            
        except Exception as e:
            print(e)

    def Show_Error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}
            print("param.inputdict ", self.inputdict)
            for i in self.inputdict:
                if (self.inputdict[i] == None):
                    continue                  
                if(i=="thermoPackage"):
                    if (self.inputdict[i].currentText()):
                        self.dict[i] = self.inputdict[i].currentText()
                    else:
                        self.Show_Error()
                        break
                elif(i=="Ctype"):
                    if (self.inputdict[i].currentText()):
                        self.dict[i] = self.inputdict[i].currentText()
                    else:
                        self.Show_Error()
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
                            self.Show_Error()
                            break
                    for c in range(len(compound_selected)):
                        mf.append(str(float(l[c])/total_moles))
                        self.x_pclist[c].setText(mf[-1])
                    self.dict[i] = ",".join(mf)
                elif(i == 'Pout' and self.obj.type == 'Mixer' or i == '' or i == 'HKey' or i == 'LKey'):
                    self.dict[i] = self.inputdict[i].currentText()
                else:
                    print(self.inputdict[i], i, self.obj.type)
                    if (self.inputdict[i].text()):
                        self.dict[i] = self.inputdict[i].text()
                    else:
                        print(self.inputdict[i].text())
                        self.Show_Error()
                        break
            
            print("param ", self.dict)
            self.obj.paramsetter(self.dict)
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
        flag = True
        try:
            print("Under result category name ", name)
            result=self.container.result
            obj = self.container.fetchObject(name)
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