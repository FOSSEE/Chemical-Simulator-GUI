from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from component_selector import *
from collections import defaultdict
ui_dialog,_ = loadUiType('resDock.ui')

class resdockWidget(QDockWidget,ui_dialog):
    
    def __init__(self,containerobj,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle("Results")
        self.nameType = None
        self.Container = containerobj
        self.results()
        
        self.pushButton_3.clicked.connect(self.resultTree)

    def abriveation(self,key):
        d ={"P":"Pressure","T":"Temperature",
        "liqPhasMolFrac":"Liquid Phase Mol Fraction","liqPhasMasFrac":"Liquid Pase Mass Fraction",
        "vapPhasMolFrac":"Vapour Phase Mol Fracrion","vapPhasMasFrac":"Vapour Phase Mass Fracrion",
        "totMolFlo[1]":"Molar Flow","totMasFlo[1]":"Mass Flow","MW[1]":"Mixer Phase Molecular Weight",
        "MW[2]":"Liquid Phase Molecular Weight","MW[3]":"Vapour Phase Molecular Weight",
        "phasMolSpHeat[1]":"Mixer Phase molar Heat Capacity","phasMolSpHeat[2]":"Liquid Phase molar Heat Capacity",
        "phasMolSpHeat[3]":"Vapour Phase molar Heat Capacity","phasMolEnth[1]":"Mixer Phase Molar Enthalpy",
        "phasMolEnth[2]":"Liquid Phase Molar Enthalpy","phasMolEnth[3]":"Vapour Phase Molar Enthalpy",
        "phasMolEntr[1]":"Mixer Phase Molar Entropy","phasMolEntr[2]":"Liquid Phase Molar Entropy",
        "phasMolEntr[3]":"Vapour Phase Molar Entropy","totMolFlo[2]":"Liquid Phase Molar Flow Rate",
        "totMolFlo[3]":"Vapour Phase Molar Flow Rate","totMasFlo[2]":"Liquid Phase Mass Flow Rate",
        "totMolFlo[3]":"Liquid Phase Mass Flow Rate"
        } 

        for i in range(len(compound_selected)):
            d["compMolFrac[1,"+str(i+1)+"]"] = str(compound_selected[i]) +" Mixer mole fraction"
            d["compMolFrac[2,"+str(i+1)+"]"] = str(compound_selected[i]) +" Liquid mole fraction"
            d["compMolFrac[3,"+str(i+1)+"]"] = str(compound_selected[i]) +" Vapour mole fraction"

            d["compMasFrac[1,"+str(i+1)+"]"] = str(compound_selected[i]) +" Mixer mass fraction"
            d["compMasFrac[2,"+str(i+1)+"]"] = str(compound_selected[i]) +" Liquid mass fraction"
            d["compMasFrac[3,"+str(i+1)+"]"] = str(compound_selected[i]) +" Vapour mass fraction"

            d["compMasFlo[1,"+str(i+1)+"]"] = str(compound_selected[i]) +" Mixer mass flo"
            d["compMasFlo[2,"+str(i+1)+"]"] = str(compound_selected[i]) +" Liquid mass flo"
            d["compMasFlo[3,"+str(i+1)+"]"] = str(compound_selected[i]) +" Vapour mass flo"

            d["compMolFlo[1,"+str(i+1)+"]"] = str(compound_selected[i]) +" Mixer mole flo"
            d["compMolFlo[2,"+str(i+1)+"]"] = str(compound_selected[i]) +" Liquid mole flo"
            d["compMolFlo[3,"+str(i+1)+"]"] = str(compound_selected[i]) +" Vapour mole flo"
        if key in d.keys():
            return d[key]
        else:
            return key

    def resultsCategory(self,name):
        try:
            print("Under result category")
            result=self.Container.result
            obj = self.Container.fetchObject(name)
            self.tableWidget.setRowCount(0);
            for key, value in obj.Prop.items():
                propertyname = name + '.' + key
                print(key,value)
                if propertyname in result[0]:
                    ind = result[0].index(propertyname)
                    resultval = str(result[-1][ind])
                    #stm.Prop[key] = resultval
                    print("######Resultsfetch####",key,resultval)
                    rowPosition = self.tableWidget.rowCount()
                    self.tableWidget.insertRow(rowPosition)
                    self.tableWidget.setItem(rowPosition , 0, QTableWidgetItem(str(self.abriveation(key))))
                    self.tableWidget.setItem(rowPosition , 1, QTableWidgetItem(str(resultval)))
                    self.tableWidget.resizeColumnsToContents()
        except Exception as e:
            print(e)


    def resultTree(self):
        self.resultsCategory(self.comboBox.currentText())
    def results(self):
        self.nameType={}
        for i in self.Container.unitOp:
            #nameslist.append(i.name)
            self.nameType[i.name] = i.type
            self.comboBox.addItem(str(i.name))