import os, sys

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)
sys.path.append(parentPath)

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from collections import defaultdict

from python.utils.ComponentSelector import *
from python.DockWidgets.DistillationColumnStagewiseResults import DistillationColumnStagewiseResults
from python.utils.Graphics import *

ui_dialog,_ = loadUiType(parentPath+'/ui/DockWidgets/DockWidgetDistillationColumn.ui')


class DockWidgetDistillationColumn(QDockWidget, ui_dialog):

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
        self.stage_res_table = DistillationColumnStagewiseResults()
        self.stageResultsButton.clicked.connect(self.showStagewiseResults)

    # input data tab
            
    def input_params_list(self):
        try:
            print("input_params_list ", self.input_dict)
        
            # tab 1
            
            l1 = QLineEdit()
            l1.setText(str(self.obj.variables['Nt']['value']))
            self.lay1.addWidget(QLabel(self.obj.variables['Nt']['name'] + " :"), 0 ,0, alignment=Qt.AlignLeft)
            self.lay1.addWidget(l1,0,1, alignment=Qt.AlignLeft)
            self.input_dict.append(l1)     

            for i in range(self.obj.variables['Ni']['value']):
                print(i)
                l = QLineEdit()
                if len(self.obj.variables['InT_s']['value']) is not 0:
                    l.setText(str(self.obj.variables['InT_s']['value'][i]))
                self.lay1.addWidget(QLabel(self.obj.variables['InT_s']['name'] +" " + str(i+1) + " location :"),2*(i+1),0, alignment=Qt.AlignLeft)
                self.lay1.addWidget(l,2*(i+1),1, alignment=Qt.AlignLeft)
                self.input_dict.append(l)

            # tab 2
            self.l4.setText(self.obj.variables['Ctype']['name']+":")

            self.u1.setText(self.obj.variables['Ctype']['unit'])
            self.l5.setText(self.obj.variables['Pcond']['name']+":")
            self.le5.setText(str(self.obj.variables['Pcond']['value']))
            self.u2.setText(self.obj.variables['Pcond']['unit'])
            self.l6.setText(self.obj.variables['C_Spec']['name']+":")
            self.le6.setText(str(self.obj.variables['C_Spec']['value']))
            self.l7.setText("Compounds :")

            self.cb5.addItem("Total")
            self.cb5.addItem("Partial")
            self.cb5.setCurrentText(self.obj.variables['Ctype']['value'])
            for j in self.obj.Cspec_list:
                self.cb1.addItem(str(j))
            self.cb1.setCurrentText(self.obj.variables['C_Spec']['type'])
            for j in self.obj.compounds:
                self.cb2.addItem(str(j))
            self.cb2.setCurrentText(self.obj.variables['C_Spec']['comp'])

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
            self.le8.setText(str(self.obj.variables['R_Spec']['value']))
            self.l10.setText('Compounds')
        
            for j in self.obj.Rspec_list:
                self.cb3.addItem(str(j))
            self.cb3.setCurrentText(self.obj.variables['R_Spec']['type'])
            for j in self.obj.compounds:
                self.cb4.addItem(str(j))
            self.cb4.setCurrentText(self.obj.variables['R_Spec']['comp'])
            self.cb4.setDisabled(True)
            self.cb3.currentIndexChanged.connect(self.fun3)

            self.input_dict.append(self.le7)
            self.input_dict.append(self.cb3)
            self.input_dict.append(self.cb4) 
            self.input_dict.append(self.le8)

            self.lines = [line.rstrip('\n') for line in open('thermopackage.txt')]
            for j in self.lines:
                self.cbTP.addItem(str(j))
            self.cbTP.setCurrentText(self.obj.variables['thermo_package']['value'])

            self.input_dict.append(self.cbTP)

            # self.input_dict = [self.le1, self.le2, self.le3, self.cb5, self.le5, self.cb1, self.cb2, self.le6, self.le7, self.cb3, self.cb4, self.le8]
             
        except Exception as e:
            print(e)

    def update_compounds(self):
        self.cb2.clear()
        self.cb4.clear()
        for j in self.obj.compounds:
            self.cb2.addItem(str(j))
        self.cb2.setCurrentText(self.obj.variables['C_Spec']['comp'])
        for j in self.obj.compounds:
            self.cb4.addItem(str(j))
        self.cb4.setCurrentText(self.obj.variables['R_Spec']['comp'])

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
            self.dict.append(self.input_dict[temp+10].currentText())
            print(temp + 10)

            print("param ", self.dict)
            self.obj.param_setter(self.dict)
            if(self.isVisible()):
                currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
                self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)
            self.hide()
            
        except Exception as e:
            print(e)

    def showStagewiseResults(self):
        self.stage_res_table.show()

    @staticmethod
    def showResult(lst):
        # DockWidget1.flag = True
        for i in lst:
            try:
                i.results_category(i.name)
            except AttributeError:
                pass

    def clear_results(self):
        self.tableWidget.setRowCount(0)
        self.stage_res_table.T_table.setRowCount(0)
        self.stage_res_table.T_table.setColumnCount(0)
        self.stage_res_table.x_pc_table.setRowCount(0)
        self.stage_res_table.x_pc_table.setColumnCount(0)
        
    # result data tab
    def results_category(self,name):
        flag = True
        try:
            print("Under result category name ", name)
            result = self.container.result
            obj = self.container.fetch_object(name)
            self.tableWidget.setRowCount(0)
            variKeys = obj.result_parameters
            print(variKeys)
            for i, val in enumerate(variKeys):
                propertyname = name + '.' + val
                print(i, val, propertyname)
                if propertyname in result[0]:
                    ind = result[0].index(propertyname)
                    resultval = str(result[-1][ind])
                    obj.variables[val]['value'] = result[-1][ind]
                    print("######Resultsfetch####", val, resultval)
                    rowPosition = self.tableWidget.rowCount()
                    self.tableWidget.insertRow(rowPosition)
                    self.tableWidget.setItem(rowPosition, 0, QTableWidgetItem(obj.variables[val]['name']))
                    self.tableWidget.setItem(rowPosition, 1, QTableWidgetItem(resultval))
                    self.tableWidget.setItem(rowPosition, 2, QTableWidgetItem(obj.variables[val]['unit']))
                    self.tableWidget.resizeColumnsToContents()

            # Stagewise Results
            Nt = self.obj.variables['Nt']['value']
            Nc = len(self.obj.compounds)
            # initializing temporary arrays
            Stages_T = [None for i in range(Nt)]
        # Can be uncommented when F_p and F_pc implemented in modelica table
            # Stages_F_p = [[None for i in range(3)] for j in range(Nt)]
            # Stages_F_pc = [[[None for i in range(3)] for j in range(Nc)] for k in range(Nt)]
            Stages_x_pc = [[[None for i in range(3)] for j in range(Nc)] for k in range(Nt)]

            Stages_res_varikeys = ['T']
            for i in range(Nc):
                for j in range(3):
                    Stages_res_varikeys.append('x_pc[' + str(j + 1) + ',' + str(i + 1) + ']')

            for v in Stages_res_varikeys:
                propertyname = name + '.condenser.' + v
                if propertyname in result[0]:
                    ind = result[0].index(propertyname)
                    if v == 'T':
                        Stages_T[0] = result[-1][ind]
                # Can be uncommented when F_p is implemented in modelica model
                    # elif v == 'F_p':
                    #     if result[0][ind][result[0][ind].index('[') + 1] == '1':
                    #         Stages_F_p[0][0] = result[-1][ind]
                    #     elif result[0][ind][result[0][ind].index('[') + 1] == '2':
                    #         Stages_F_p[0][1] = result[-1][ind]
                    #     else:
                    #         Stages_F_p[0][2] = result[-1][ind]
                    else:
                        print(ind)
                        phase_no = int(result[0][ind][result[0][ind].index('[') + 1])
                        comp_no = int(result[0][ind][result[0][ind].index(']') - 1])
                        Stages_x_pc[0][comp_no - 1][phase_no - 1] = result[-1][ind]
                    # Can be uncommented and improved when F_pc implemented in modelica model
                        # if v == 'F_pc':
                        #     Stages_F_pc[0][comp_no - 1][phase_no - 1] = result[-1][ind]
                        # else:
                        #     Stages_x_pc[0][comp_no - 1][phase_no - 1] = result[-1][ind]

                for i in range(1, Nt - 1):
                    propertyname = name + '.tray[' + str(i) + '].' + v
                    if propertyname in result[0]:
                        ind = result[0].index(propertyname)
                        if v == 'T':
                            Stages_T[i] = result[-1][ind]
                    # Can be uncommented when F_p implemented in modelica model
                        # elif v == 'F_p':
                        #     if result[0][ind][result[0][ind].index('[') + 1] == '1':
                        #         Stages_F_p[i][0] = result[-1][ind]
                        #     elif result[0][ind][result[0][ind].index('[') + 1] == '2':
                        #         Stages_F_p[i][1] = result[-1][ind]
                        #     else:
                        #         Stages_F_p[i][2] = result[-1][ind]
                        else:
                            print(ind)
                            print(result[0][ind])
                            phase_no = int(result[0][ind].split('.')[-1][result[0][ind].split('.')[-1].index('[') + 1])
                            comp_no = int(result[0][ind].split('.')[-1][result[0][ind].split('.')[-1].index(']') - 1])
                            Stages_x_pc[i][comp_no - 1][phase_no - 1] = result[-1][ind]
                        # Can be uncommented when F_pc implemented in modelica model
                            # if v == 'F_pc':
                            #     Stages_F_pc[i][comp_no - 1][phase_no - 1] = result[-1][ind]
                            # else:
                            #     Stages_x_pc[i][comp_no - 1][phase_no - 1] = result[-1][ind]

                propertyname = name + '.reboiler.' + v
                if propertyname in result[0]:
                    ind = result[0].index(propertyname)
                    if v == 'T':
                        Stages_T[-1] = result[-1][ind]
                # Can be uncommented when F_p implemented in modelica model
                    # elif v == 'F_p':
                    #     if result[0][ind][result[0][ind].index('[') + 1] == '1':
                    #         Stages_F_p[-1][0] = result[-1][ind]
                    #     elif result[0][ind][result[0][ind].index('[') + 1] == '2':
                    #         Stages_F_p[-1][1] = result[-1][ind]
                    #     else:
                    #         Stages_F_p[-1][2] = result[-1][ind]
                    else:
                        print(ind)
                        phase_no = int(result[0][ind][result[0][ind].index('[') + 1])
                        comp_no = int(result[0][ind][result[0][ind].index(']') - 1])
                        Stages_x_pc[-1][comp_no - 1][phase_no - 1] = result[-1][ind]
                    # Can be uncommented when F_pc implemented in modelica model
                        # if v == 'F_pc':
                        #     Stages_F_pc[-1][comp_no - 1][phase_no - 1] = result[-1][ind]
                        # else:
                        #     Stages_x_pc[-1][comp_no - 1][phase_no - 1] = result[-1][ind]

            # Assigning temp variables to obj variabes
            self.obj.variables['Stages.T']['value'] = Stages_T
        # Can be uncommented when F_p and F_pc implemented in modelica model
            # self.obj.variables['Stages.F_p']['value'] = Stages_F_p
            # self.obj.variables['Stages.F_pc']['value'] = Stages_F_pc
            self.obj.variables['Stages.x_pc']['value'] = Stages_x_pc

            # filling stagewise result table
            tables = [self.stage_res_table.T_table, self.stage_res_table.x_pc_table]
        # Can be uncommented when F_p and F_pc implemented in modelica model
            # tables = [self.stage_res_table.T_table, self.stage_res_table.F_p_table, self.stage_res_table.F_pc_table, self.stage_res_table.x_pc_table]

            for t in tables:
                t.setRowCount(Nt)
                t.setVerticalHeaderItem(0, QTableWidgetItem('Condenser'))
                t.setVerticalHeaderItem(Nt -1, QTableWidgetItem('Reboiler'))
                for i in range(1, Nt - 1):
                    t.setVerticalHeaderItem(i, QTableWidgetItem('Stage ' + str(i)))

            T_table = self.stage_res_table.T_table
            T_table.setColumnCount(1)
            for i in range(Nt):
                T_table.setItem(i, 0, QTableWidgetItem(Stages_T[i]))

            x_pc_table = self.stage_res_table.x_pc_table
            x_pc_table.setColumnCount(2*Nc)
            for i in range(Nc):
                x_pc_table.setHorizontalHeaderItem(2*i, QTableWidgetItem(self.obj.compounds[i] + '(Vapor)'))
                x_pc_table.setHorizontalHeaderItem(2*i + 1, QTableWidgetItem(self.obj.compounds[i] + '(Liquid)'))

            for i in range(Nt):
                for j in range(Nc):
                    x_pc_table.setItem(i, 2*j, QTableWidgetItem(Stages_x_pc[i][j][1]))
                    x_pc_table.setItem(i, 2 * j + 1, QTableWidgetItem(Stages_x_pc[i][j][2]))

            for t in tables:
                t.resizeColumnsToContents()
        except Exception as e:
            print(e)

    def closeEvent(self,event):
        scrollHVal = self.parent().container.graphics.graphicsView.horizontalScrollBarVal
        currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
        self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)