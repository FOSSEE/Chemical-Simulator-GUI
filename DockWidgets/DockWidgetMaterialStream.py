from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
from ComponentSelector import *
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

        self.comboBox.currentIndexChanged.connect(self.mode_selection)

        self.pushButton_2.clicked.connect(self.param)
        self.dict = {}          # a dictionary

        self.name_type = None
        self.container = container

        header = QTreeWidgetItem(['Compound','Value','Unit'])
        self.mTreeWidget.setHeaderItem(header)
        self.lTreeWidget.setHeaderItem(header)
        self.vTreeWidget.setHeaderItem(header)
        lines = [line.rstrip('\n') for line in open('thermopackage.txt')]
        for j in lines:
            self.cbTP.addItem(str(j))
        self.modes()

    # input data tab
    def modes(self):
        modes_list = self.obj.modes_list
        if(modes_list):
            for j in modes_list:
                self.comboBox.addItem(str(j))
            self.comboBox.setCurrentText(self.obj.mode)
            self.mode_selection()
        else:
            self.input_dict= {}
            self.input_dict = self.obj.param_getter()
            self.input_params_list()

    def mode_selection(self):
        self.input_dict= {}
        try: # removing existing rows while changing modes
            for i in reversed(range(self.formLayout.count())):
                self.formLayout.removeRow(i)
        except Exception as e:
            print(e)
        self.input_dict = self.obj.param_getter(self.comboBox.currentText())
        self.obj.mode = self.comboBox.currentText()
        self.input_params_list()

    def input_params_list(self):
        try:
            for c,i in enumerate(self.input_dict):
                if(i=="x_pc"):
                    noc = len(compound_selected)
                    #print(noc)
                    self.x_pclist.clear()

                    self.comp_gb = QGroupBox("Mole Fractions")
                    lay = QGridLayout()
                    for j in range(noc):
                        try:
                            l = QLineEdit(str(self.obj.variables['x_pc']['value'][j]))
                        except:
                            l = QLineEdit()
                        # if self.input_dict[i] != '':
                        #     l.setText(str(self.obj.variables['x_pc']['value'][j]))
                        #     print('l = ', str(self.obj.variables['x_pc']['value'][j]))

                        self.input_dict[i] = "x_pc"
                        lay.addWidget(QLabel(str(compound_selected[j])+":"),j,0, alignment= Qt.AlignLeft)
                        lay.addWidget(l,j,1, alignment=Qt.AlignCenter)
                        self.x_pclist.append(l)
                        lay.setSizeConstraint(QLayout.SetFixedSize)
                    self.comp_gb.setLayout(lay)
                    self.formLayout.addRow(self.comp_gb)
                elif i == "Thermo Package":
                    self.cbTP.setCurrentText(self.input_dict[i])
                else:
                    #print("elseloop")
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


        except Exception as e:
            print(e)

    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def update_compounds(self):
        try:
            noc = len(compound_selected)
            #print(noc)
            self.x_pclist.clear()

            lay = QGridLayout()
            for j in range(noc):
                l = QLineEdit()
                lay.addWidget(QLabel(str(compound_selected[j]) + ":"), j, 0, alignment=Qt.AlignLeft)
                lay.addWidget(l, j, 1, alignment=Qt.AlignCenter)
                self.x_pclist.append(l)
                lay.setSizeConstraint(QLayout.SetFixedSize)
            self.comp_gb.setLayout(lay)
            indexx = self.comboBox.currentIndex()
            self.comboBox.setCurrentIndex(1)
            self.comboBox.setCurrentIndex(indexx)
            self.obj.init_variables()
        except Exception as e:
            print(e)

    def param(self):
        try:
            self.dict={}
            #print("param.input_dict ", self.input_dict)
            for i in self.input_dict:
                #print(i)
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
                    self.dict[i] = self.cbTP.currentText()
                else:
                    if (self.input_dict[i].text()):
                        self.dict[i] = self.input_dict[i].text()
                    else:
                        #print(self.input_dict[i])
                        self.show_error()
                        break

            #print("param ", self.dict)

            self.obj.param_setter(self.dict)

            for i in self.container.graphics.graphicsView.items():
                try: 
                    if(i.name == self.name):
                        i.update_tooltip()
                except:
                    pass
                
            self.hide()
            
        except Exception as e:
            print(e)

    def update_input_values(self):
        self.init()

    @staticmethod
    def show_result(ms_lst):
        for i in ms_lst:
            i.results_category(i.name)
    
    def clear_results(self):
        self.mTreeWidget.clear()
        self.mTableWidget.setRowCount(0)
        self.lTreeWidget.clear()
        self.lTableWidget.setRowCount(0)
        self.vTreeWidget.clear()
        self.vTableWidget.setRowCount(0)

    # result data tab
    def results_category(self,name):
        try:
            #print("Under result category name ", name)
            result=self.container.result
            obj = self.container.fetch_object(name)


            d = {"Mole Fraction":"x_pc", "Mass Fraction":"xm_pc", "Mole Flow":"F_pc", "Mass Flow":"Fm_pc"}
            ms_lst = list(d.keys())
            klst = list(d.values())

            p = {"Pressure":"P", "Temperature":"T","Vapour Phase Mole Fraction":"xvap", "Phase Molar Enthalpy":"H_p", 
            "Phase Molar Entropy":"S_p", "Molar Flow Rate":"F_p"}

            # Amounts Tab
            if obj.type == 'MaterialStream':
                ll = []  # list for basis names
                for basis in d:
                    propertyname = name + '.' + d[basis]
                    #print("basis ", basis, propertyname)
                    for i in result[0]:
                        if (propertyname in i):
                            ll.append(i)
                #print(ll)
              
                j = 0
                namee = 'none'
                #print("namee ", namee)
                #initialization for treewidgets
                lroot = 1
                mroot = 1
                vroot = 1


                for i,k in enumerate(ll):
                    ind = result[0].index(k)
                    #print("index ", ind)
                    #print("str ", k)
                    resultval = str(result[-1][ind])
                    #print("######Resultsfetch####",resultval)
                    #print(k[k.find(".")+1:k.find("[")])
                    obj.variables[k.split('.')[1]]['value'] = resultval

                    if namee not in k:
                        mroot = QTreeWidgetItem(self.mTreeWidget, [ms_lst[j]])
                        lroot = QTreeWidgetItem(self.lTreeWidget, [ms_lst[j]])
                        vroot = QTreeWidgetItem(self.vTreeWidget, [ms_lst[j]])
                        namee = klst[j]

                    phase_no = int(k[k.index(',') - 1])  # phase no is from modelica list
                    compound_no = int(k[k.index(',') + 1]) - 1  # compound is from python list

                    if phase_no == 1:
                        child = QTreeWidgetItem(mroot, [compound_selected[compound_no], str(resultval),
                                                        obj.variables[k.split('.')[1]]['unit']])
                    elif phase_no == 2:
                        child = QTreeWidgetItem(lroot, [compound_selected[compound_no], str(resultval),
                                                        obj.variables[k.split('.')[1]]['unit']])
                    elif phase_no == 3:
                        child = QTreeWidgetItem(vroot, [compound_selected[compound_no], str(resultval),
                                                        obj.variables[k.split('.')[1]]['unit']])
                        if (compound_no + 1) == len(compound_selected):
                            j += 1


                
                # Phase Properties Tab
                phaseResLst = []
                for phase in p:
                    propertyname = name + '.' + p[phase]
                    #print("phase ", phase, propertyname)
                    for i in result[0]:
                        if i.find('['):
                            if (propertyname == i[0:i.find('[')]):
                                phaseResLst.append(i)
                        if propertyname == i:
                            phaseResLst.append(i)
                #print(phaseResLst)
                
                self.mTableWidget.setRowCount(0)
                self.lTableWidget.setRowCount(0)
                self.vTableWidget.setRowCount(0)

                for i,val in enumerate(phaseResLst):
                    ind = result[0].index(val)
                    resultval = str(result[-1][ind])
                    #print(resultval, i, val)
                    obj.variables[val.split('.')[1]]['value'] = resultval
                    if '[' in val:
                        #print(val)
                        temp = val[val.find('.')+1:val.find('[')]
                        #print(temp)
                        if '1' in val.split('.')[1]:
                            #print(obj.variables[val.split('.')[1]]['name'])
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
                        #print(obj.variables[val.split('.')[1]]['name'])
                        mrowPosition = self.mTableWidget.rowCount()
                        self.mTableWidget.insertRow(mrowPosition)
                        self.mTableWidget.setItem(mrowPosition , 0, QTableWidgetItem(obj.variables[val.split('.')[1]]['name']))
                        self.mTableWidget.setItem(mrowPosition , 1, QTableWidgetItem(resultval))
                        self.mTableWidget.setItem(mrowPosition , 2, QTableWidgetItem(obj.variables[val.split('.')[1]]['unit']))
                        self.mTableWidget.resizeColumnsToContents() 


            # updating the input data from fetched results from simulation
            #print(self.comboBox.currentText())
       
            self.input_dict = {}
            self.input_dict = self.obj.param_getter(self.comboBox.currentText())
            # print("before", self.input_dict)
            #self.input_dict.pop("x_pc")
            # temp = self.input_dict.pop('thermo_package')
            for i in range(len(compound_selected)):
                #print(i)
                self.input_dict['x_pc[1,' + str(i+1) + ']'] = self.obj.variables['x_pc[1,' + str(i+1) +']']['value']
            # self.input_dict['thermo_package'] = temp
            # print("after", self.input_dict)
            
            # changing index for updating the input data
            indexx = self.comboBox.currentIndex()
            self.comboBox.setCurrentIndex(1)
            self.comboBox.setCurrentIndex(indexx)

            try:

                for i in self.parent().container.graphics.graphicsView.items():
                    try:
                        if i.obj == self.obj:
                            i.update_tooltip()
                    except Exception as e:
                        pass
            except Exception as e:
                print(e)


        except Exception as e:
            print(e)
    def closeEvent(self,event):
        scrollHVal = self.parent().container.graphics.graphicsView.horizontalScrollBarVal
        currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
        self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)