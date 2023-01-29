from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
from ComponentSelector import *
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgets/DockWidgetShortcutColumn.ui')

class DockWidgetShortcutColumn(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = []
        self.input_params_list()
        self.btn.clicked.connect(self.param)
        self.dict = []

        self.name_type = None
        self.container = container

    # input data tab
    def input_params_list(self):
        try:        
            self.l1.setText(self.obj.variables['HKey']['name']+":")
            self.l2.setText(self.obj.variables['LKey']['name']+":")

            print(self.obj.compounds)
            for i in self.obj.compounds:
                self.cb1.addItem(str(i))
                self.cb2.addItem(str(i))
            self.cb1.setCurrentText(self.obj.compounds[int(self.obj.variables['HKey']['value'])-1])
            self.cb2.setCurrentText(self.obj.compounds[int(self.obj.variables['LKey']['value'])-1])

            self.l3.setText(self.obj.variables['HKey_x_pc']['name']+":")
            self.le3.setText(str(self.obj.variables['HKey_x_pc']['value']))
            self.u3.setText(self.obj.variables['HKey_x_pc']['unit'])
            self.l4.setText(self.obj.variables['LKey_x_pc']['name']+":")
            self.u4.setText(self.obj.variables['LKey_x_pc']['unit'])
            self.le4.setText(str(self.obj.variables['LKey_x_pc']['value']))

            self.l5.setText(self.obj.variables['Ctype']['name']+":")
            self.cb5.addItem('Total')
            self.cb5.addItem('Partial')
            self.cb5.setCurrentText(self.obj.variables['Ctype']['value'])

            self.l6.setText(self.obj.variables['Pcond']['name']+":")
            self.le6.setText(str(self.obj.variables['Pcond']['value']))
            self.u6.setText(self.obj.variables['Pcond']['unit'])
            self.l7.setText(self.obj.variables['Preb']['name']+":")
            self.u7.setText(self.obj.variables['Preb']['unit'])
            self.le7.setText(str(self.obj.variables['Preb']['value']))
            
            self.l8.setText(self.obj.variables['RR']['name']+":") 
            self.le8.setText(str(self.obj.variables['RR']['value']))

            self.l9.setText("Thermo Package :")

            self.lines = [line.rstrip('\n') for line in open('thermopackage.txt')]
            for j in self.lines:
                self.cb6.addItem(str(j))
            self.cb6.setCurrentText(self.obj.variables['thermo_package']['value'])
            
            self.input_dict = [self.cb1, self.cb2, self.le3, self.le4, self.cb5, self.le6, self.le7, self.le8, self.cb6]

        except Exception as e:
            print(e)

    def update_compounds(self):
        self.cb1.clear()
        self.cb2.clear()
        for i in self.obj.compounds:
            self.cb1.addItem(str(i))
            self.cb2.addItem(str(i))
        self.cb1.setCurrentText(self.obj.compounds[int(self.obj.variables['HKey']['value']) - 1])
        self.cb2.setCurrentText(self.obj.compounds[int(self.obj.variables['LKey']['value']) - 1])
    
    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict=[]
            self.dict = [self.input_dict[0].currentText(),self.input_dict[1].currentText(),float(self.input_dict[2].text()), float(self.input_dict[3].text()),
                        self.input_dict[4].currentText(), float(self.input_dict[5].text()), float(self.input_dict[6].text()), float(self.input_dict[7].text()),
                        self.input_dict[8].currentText()]            
            self.obj.param_setter(self.dict)
            if(self.isVisible()):
                currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
                self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)
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
            variKeys = obj.result_parameters
            print(variKeys)
            for i, val in enumerate(variKeys):
                propertyname = name + '.' + val
                print(i,val, propertyname)
                if propertyname in result[0]:
                    ind = result[0].index(propertyname)
                    resultval = str(result[-1][ind])
                    obj.variables[val]['value']= result[-1][ind]
                    print("######Resultsfetch####",val,resultval)
                    rowPosition = self.tableWidget.rowCount()
                    self.tableWidget.insertRow(rowPosition)
                    self.tableWidget.setItem(rowPosition , 0, QTableWidgetItem(obj.variables[val]['name']))
                    self.tableWidget.setItem(rowPosition , 1, QTableWidgetItem(resultval))
                    self.tableWidget.setItem(rowPosition , 2, QTableWidgetItem(obj.variables[val]['unit']))
                    self.tableWidget.resizeColumnsToContents()
        except Exception as e:
            print(e)
    def closeEvent(self,event):
        scrollHVal = self.parent().container.graphics.graphicsView.horizontalScrollBarVal
        currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
        self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)