from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from component_selector import *
from collections import defaultdict
ui_dialog,_ = loadUiType('dockWidget.ui')


class dockWidget(QDockWidget,ui_dialog):
    
    def __init__(self,name,comptype,obj,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.inputdict = {}
        self.compmolfraclist = []
        self.modes()
        self.pushButton_2.clicked.connect(self.modeSelection)
        #self.inputparamslist()
        print(self.inputdict)
        self.pushButton.clicked.connect(self.param)
        self.dict = {}

    def modes(self):
        modesList = self.obj.modesList()
        if(modesList):
            for j in modesList:
                    self.comboBox.addItem(str(j))
            self.modeSelection()
        else:
            self.inputdict= {}
            self.inputdict = self.obj.paramgetter()
            self.inputparamslist()

    def modeSelection(self):
        self.inputdict= {}
        for i in reversed(range(self.formLayout.count())):
            self.formLayout.itemAt(i).widget().setParent(None)  
        self.inputdict = self.obj.paramgetter(self.comboBox.currentText())
        self.inputparamslist()

    def inputparamslist(self):
        try:
            print(self.inputdict)
            for c,i in enumerate(self.inputdict):
                if(i=="thermoPackage"):
                    print("thermo1")
                    combo = QComboBox()
                    self.lines = [line.rstrip('\n') for line in open('thermopackage.txt')]
                    print("thermo2")
                    for j in self.lines:
                        combo.addItem(str(j))
                    self.formLayout.addRow(QLabel(i+":"),combo )                    
                    self.inputdict[i] = combo
                    print("thermo")
                elif(i=="condType"):
                    combo = QComboBox()
                    self.lines = ["Total","Partial"]
                    for j in self.lines:
                        combo.addItem(str(j))
                    self.formLayout.addRow(QLabel("Condensor Type :"+":"),combo )
                    self.inputdict[i] = combo
                elif(i=="CompMolFrac"):
                    print("cmfnjkmnjkmnjkm")
                    noc = len(compound_selected)
                    print(noc)
                    self.compmolfraclist.clear()
                    for j in range(noc):
                        l = QLineEdit()    
                        self.inputdict[i] = "compmolfrac"                                                  
                        self.formLayout.addRow(QLabel(str(compound_selected[j])+" Fraction"+":"),l )
                        
                        self.compmolfraclist.append(l)
                else:
                    print("elseloopo")
                    l = QLineEdit()                                                      
                    self.formLayout.addRow(QLabel(i+":"),l )
                    self.inputdict[i] = l
            
        except Exception as e:
            print(e)
    def Show_Error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")
    def param(self):
        try:
            self.dict={}
            for i in self.inputdict:
                if(i=="thermoPackage"):
                    if (self.inputdict[i].currentText()):
                        self.dict[i] = self.inputdict[i].currentText()
                    else:
                        self.Show_Error()
                        break
                elif(i=="condType"):
                    if (self.inputdict[i].currentText()):
                        self.dict[i] = self.inputdict[i].currentText()
                    else:
                        self.Show_Error()
                        break
                elif(i =="CompMolFrac"):
                    l=[]
                    for mol_frac in self.compmolfraclist:
                        if (mol_frac.text()):
                            l.append(mol_frac.text())
                        else:
                            self.Show_Error()
                            break
                    self.dict[i] = ",".join(l)
                else:
                    if (self.inputdict[i].text()):
                        self.dict[i] = self.inputdict[i].text()
                    else:
                        print(self.inputdict[i].text())
                        self.Show_Error()
                        break
            self.obj.paramsetter(self.dict)
            print(self.dict)
            self.hide()
        except Exception as e:
            print(e)

        
  
    
        