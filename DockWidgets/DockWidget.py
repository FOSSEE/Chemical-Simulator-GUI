from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
from ComponentSelector import *
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
        self.modes()
        self.comboBox.currentIndexChanged.connect(self.mode_selection)
       
        print("constructor ", self.input_dict)
        self.pushButton_2.clicked.connect(self.param)

        self.dict = {}          # a dictionary
        self.container = container
        
    # input data tab
    def modes(self):
        modes_list = self.obj.modes_list
        if(modes_list):
            for j in modes_list:
                self.comboBox.addItem(str(self.obj.variables[j]['name']))
            self.comboBox.setCurrentText(self.obj.variables[self.obj.mode]['name'])
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
                print(i)
                if i == None:
                    continue
                l = QLineEdit(str(self.obj.variables[i]['value']))
                lay = QGridLayout()
                lay.addWidget(QLabel(self.obj.variables[i]['name']+":"),0,0, alignment=Qt.AlignLeft)
                lay.addWidget(l,0,1, alignment=Qt.AlignCenter)
                lay.addWidget(QLabel(self.obj.variables[i]['unit']),0,2, alignment=Qt.AlignCenter)
                self.formLayout.addRow(lay)
                self.input_dict[i] = l
        except Exception as e:
            print(e)


    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict = {}
            print("param.input_dict ", self.input_dict)
            for i in self.input_dict:
                if (self.input_dict[i] == None):
                    continue                  
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
        for i in lst:
            try:
                i.results_category(i.name)
            except AttributeError:
                pass
        
    def clear_results(self):
        self.tableWidget.setRowCount(0)

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

                    # Updating result in class
                    obj.variables[val]['value'] = resultval
                    # try:
                    #     if obj.type == "Heater":
                    #         print(obj.variables[val]['name'] + str(obj.variables[val]['value']))
                    # except Exception as e:
                    #     print(e)



        except Exception as e:
            print(e)

    def closeEvent(self,event):
        scrollHVal = self.parent().container.graphics.graphicsView.horizontalScrollBarVal
        currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
        self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue((scrollHVal+currentVal)/2)