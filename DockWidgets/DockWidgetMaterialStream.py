from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgets/DockWidgetMaterialStream.ui')

class DockWidgetMaterialStream(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
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

        header = QTreeWidgetItem(['Compound','Value','Unit'])
        self.mTreeWidget.setHeaderItem(header)
        self.lTreeWidget.setHeaderItem(header)
        self.vTreeWidget.setHeaderItem(header)       

        self.mTreeWidget.itemClicked.connect(lambda : self.printer(self.mTreeWidget.currentItem()))
        self.lTreeWidget.itemClicked.connect(lambda : self.printer(self.lTreeWidget.currentItem()))
        self.vTreeWidget.itemClicked.connect(lambda : self.printer(self.vTreeWidget.currentItem()))

    # input data tab
    def modes(self):
        modes_list = self.obj.modes_list
        if(modes_list):
            for j in modes_list:
                self.comboBox.addItem(str(j))
            self.mode_selection()
        else:
            self.input_dict= {}
            self.input_dict = self.obj.param_getter()
            self.input_params_list()

    def mode_selection(self):
        self.input_dict= {}
        for i in reversed(range(self.formLayout.count())):
            self.formLayout.removeRow(i) 
        self.input_dict = self.obj.param_getter(self.comboBox.currentText())
        self.input_params_list()

    def input_params_list(self):
        try:
            print("input_params_list ", self.input_dict)
            
            for c,i in enumerate(self.input_dict):
                if(i=="x_pc"):
                    noc = len(compound_selected)
                    print(noc)
                    self.x_pclist.clear()
                        
                    gp = QGroupBox("Mole Fractions")
                    lay = QGridLayout()
                    for j in range(noc):
                        l = QLineEdit()  
                        if self.input_dict[i] != '':
                            l.setText(str(self.obj.variables['x_pc']['value'][j]))
                            print('l = ', str(self.obj.variables['x_pc']['value'][j]))
                                
                        self.input_dict[i] = "x_pc"
                        lay.addWidget(QLabel(str(compound_selected[j])+":"),j,0, alignment=Qt.AlignLeft)
                        lay.addWidget(l,j,1, alignment=Qt.AlignCenter)
                        self.x_pclist.append(l)                    
                    gp.setLayout(lay)
                    self.formLayout.addRow(gp) 
                else:
                    print("elseloop")
                    l = QLineEdit()
                    if self.input_dict[i] != None:
                        l.setText(str(self.input_dict[i]))
                        
                    lay = QGridLayout()
                    lay.addWidget(QLabel(i+":"),0,0, alignment=Qt.AlignLeft)
                    lay.addWidget(l,0,1, alignment=Qt.AlignCenter)
                    if(i != 'MolFlow'):
                        lay.addWidget(QLabel(self.obj.variables[i]['unit']),0,2, alignment=Qt.AlignCenter)
                    else:
                        lay.addWidget(QLabel("mol/s"),0,2, alignment=Qt.AlignCenter)
                    self.formLayout.addRow(lay)
                    self.input_dict[i] = l            

            self.lines = [line.rstrip('\n') for line in open('thermopackage.txt')]
            for j in self.lines:
                self.cbTP.addItem(str(j))
            self.input_dict['Thermo Package'] = self.cbTP
        
        except Exception as e:
            print(e)

    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}

            print("param.input_dict ", self.input_dict)
            for i in self.input_dict:
                print(i)
                if(i =="x_pc"):
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
                        self.obj.variables[compound_selected[c]]['value'] = str(float(l[c])/total_moles)
                        self.x_pclist[c].setText(mf[-1])
                    self.dict[i] = ",".join(mf)
                elif (i == "Thermo Package"):
                    self.dict[i] = self.input_dict[i].currentText()
                else:
                    if (self.input_dict[i].text()):
                        self.dict[i] = self.input_dict[i].text()
                    else:
                        print(self.input_dict[i])
                        self.show_error()
                        break
            # print(self.input_dict[-1].currentText())                        
            # self.dict['Thermo Package'] = self.input_dict['Thermo Package'].currentText()

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
        
    
    def clear_results(self):
        self.mTreeWidget.clear()
        self.mTableWidget.setRowCount(0)
        self.lTreeWidget.clear()
        self.lTableWidget.setRowCount(0)
        self.vTreeWidget.clear()
        self.vTableWidget.setRowCount(0)

    # result data tab
    def results_category(self,name):
        flag = True
        try:
            print("Under result category name ", name)
            result=self.container.result
            obj = self.container.fetch_object(name)


            d = {"Mole Fraction":"x_pc", "Mass Fraction":"xm_pc", "Mole Flow":"F_pc", "Mass Flow":"Fm_pc"}
            lst = list(d.keys())
            klst = list(d.values())

            p = {"Pressure":"P", "Temperature":"T","Vapour Phase Mole Fraction":"xvap", "Phase Molar Enthalpy":"H_p", 
            "Phase Molar Entropy":"S_p", "Molar Flow Rate":"F_p"}

            # Amounts Tab
            if obj.type == 'MaterialStream':
                ll = []  # list for basis names
                for basis in d:
                    propertyname = name + '.' + d[basis]
                    print("basis ", basis, propertyname)
                    for i in result[0]:
                        if (propertyname in i):
                            ll.append(i)
                print(ll)
              
                j = 0
                t = 0
                namee = klst[j]
                print("namee ", namee)

                for i,k in enumerate(ll):
                    ind = result[0].index(k)
                    print("index ", ind)
                    print("str ", k)
                    resultval = str(result[-1][ind])
                    print("######Resultsfetch####",resultval)
                    print(k[k.find(".")+1:k.find("[")])
                    obj.variables[k.split('.')[1]]['value'] = resultval
                    if namee in k:
                        if i%3 == 0: 
                            if(flag):                                  
                                mroot = QTreeWidgetItem(self.mTreeWidget, [lst[j]])
                            child = QTreeWidgetItem(mroot, [compound_selected[t], str(resultval),obj.variables[k.split('.')[1]]['unit']])
                        elif i%3 == 1:                                
                            if(flag):
                                lroot = QTreeWidgetItem(self.lTreeWidget, [lst[j]])
                            child = QTreeWidgetItem(lroot, [compound_selected[t], str(resultval),obj.variables[k.split('.')[1]]['unit']])
                        elif i%3 == 2:                                
                            if (flag):
                                vroot = QTreeWidgetItem(self.vTreeWidget, [lst[j]])
                            child = QTreeWidgetItem(vroot, [compound_selected[t], str(resultval),obj.variables[k.split('.')[1]]['unit']])
                            t += 1
                            flag = False
                    else:
                        j += 1
                        t = 0
                        namee = klst[j]
                        flag = True
                        if i%3 == 0:
                            if (flag):                                   
                                mroot = QTreeWidgetItem(self.mTreeWidget, [lst[j]])
                            child = QTreeWidgetItem(mroot, [compound_selected[t], str(resultval),obj.variables[k.split('.')[1]]['unit']])
                        elif i%3 == 1:                                
                            if (flag):
                                lroot = QTreeWidgetItem(self.lTreeWidget, [lst[j]])
                            child = QTreeWidgetItem(lroot, [compound_selected[t], str(resultval),obj.variables[k.split('.')[1]]['unit']])
                        elif i%3 == 2:                                
                            if (flag):
                                vroot = QTreeWidgetItem(self.vTreeWidget, [lst[j]])
                            child = QTreeWidgetItem(vroot, [compound_selected[t], str(resultval),obj.variables[k.split('.')[1]]['unit']])
                            t += 1
                            flag = False
                #print(obj.variables)
                
                # Phase Properties Tab
                phaseResLst = []
                for phase in p:
                    propertyname = name + '.' + p[phase]
                    print("phase ", phase, propertyname)
                    for i in result[0]:
                        if i.find('['):
                            if (propertyname == i[0:i.find('[')]):
                                phaseResLst.append(i)
                        if propertyname == i:
                            phaseResLst.append(i)
                print(phaseResLst)
                
                self.mTableWidget.setRowCount(0)
                self.lTableWidget.setRowCount(0)
                self.vTableWidget.setRowCount(0)

                for i,val in enumerate(phaseResLst):
                    ind = result[0].index(val)
                    resultval = str(result[-1][ind])
                    print(resultval, i, val)
                    obj.variables[val.split('.')[1]]['value'] = resultval
                    if '[' in val:
                        print(val)
                        temp = val[val.find('.')+1:val.find('[')]
                        print(temp)
                        if '1' in val.split('.')[1]:
                            print(obj.variables[val.split('.')[1]]['name'])
                            mrowPosition = self.mTableWidget.rowCount()
                            self.mTableWidget.insertRow(mrowPosition)
                            self.mTableWidget.setItem(mrowPosition , 0, QTableWidgetItem(obj.variables[val.split('.')[1]]['name']))
                            self.mTableWidget.setItem(mrowPosition , 1, QTableWidgetItem(resultval))
                            self.mTableWidget.setItem(mrowPosition , 2, QTableWidgetItem(obj.variables[val.split('.')[1]]['unit']))
                            self.mTableWidget.resizeColumnsToContents() 
                                                 
                        if '2' in val.split('.')[1]:       
                            lrowPosition = self.lTableWidget.rowCount()
                            self.lTableWidget.insertRow(lrowPosition)
                            self.lTableWidget.setItem(lrowPosition , 0, QTableWidgetItem(obj.variables[val.split('.')[1]]['name']))
                            self.lTableWidget.setItem(lrowPosition , 1, QTableWidgetItem(resultval))
                            self.lTableWidget.setItem(lrowPosition , 2, QTableWidgetItem(obj.variables[val.split('.')[1]]['unit']))
                            self.lTableWidget.resizeColumnsToContents()                         
                        if '3' in val.split('.')[1]:   
                            vrowPosition = self.vTableWidget.rowCount()
                            self.vTableWidget.insertRow(vrowPosition)
                            self.vTableWidget.setItem(vrowPosition , 0, QTableWidgetItem(obj.variables[val.split('.')[1]]['name']))
                            self.vTableWidget.setItem(vrowPosition , 1, QTableWidgetItem(resultval))
                            self.vTableWidget.setItem(vrowPosition , 2, QTableWidgetItem(obj.variables[val.split('.')[1]]['unit']))
                            self.vTableWidget.resizeColumnsToContents()                                
                    if not '[' in val:
                        #print(p[val.split('.')[1]])
                        print(obj.variables[val.split('.')[1]]['name'])
                        mrowPosition = self.mTableWidget.rowCount()
                        self.mTableWidget.insertRow(mrowPosition)
                        self.mTableWidget.setItem(mrowPosition , 0, QTableWidgetItem(obj.variables[val.split('.')[1]]['name']))
                        self.mTableWidget.setItem(mrowPosition , 1, QTableWidgetItem(resultval))
                        self.mTableWidget.setItem(mrowPosition , 2, QTableWidgetItem(obj.variables[val.split('.')[1]]['unit']))
                        self.mTableWidget.resizeColumnsToContents() 


            # updating the input data from fetched results from simulation
            print(self.comboBox.currentText())
       
            self.input_dict = {}
            self.input_dict = self.obj.param_getter(self.comboBox.currentText())
            print("before", self.input_dict)
            self.input_dict.pop("x_pc")
            temp = self.input_dict.pop('thermo_package')
            for i in range(len(compound_selected)):
                print(i)
                self.input_dict['x_pc[1,' + str(i+1) + ']'] = self.obj.variables['x_pc[1,' + str(i+1) +']']['value']
            self.input_dict['thermo_package'] = temp
            print("after", self.input_dict)
            
            # chaning index for updating the input data
            indexx = self.comboBox.currentIndex()
            self.comboBox.setCurrentIndex(1)
            self.comboBox.setCurrentIndex(indexx)



        except Exception as e:
            print(e)