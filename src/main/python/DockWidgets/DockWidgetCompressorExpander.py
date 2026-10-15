import os, sys

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)
sys.path.append(parentPath)

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
from python.utils.ComponentSelector import *
from python.utils.Graphics import *

from python.DockWidgets.DockWidget import BaseDockWidget

ui_dialog,_ = loadUiType(parentPath+'/ui/DockWidgets/DockWidgetCompressorExpander.ui')

class DockWidgetCompressorExpander(BaseDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container, parent=None):
        BaseDockWidget.__init__(self,parent)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.container = container
        self.setupUi(self)
        self.setWindowTitle(obj.name)

        # Make dock content resizable
        content = self.widget()
        if content is not None and content.layout() is None:
            layout = QVBoxLayout(content)
            layout.setContentsMargins(4, 4, 4, 4)
            if hasattr(self, 'tabWidget'):
                self.tabWidget.setParent(None)
                layout.addWidget(self.tabWidget)
            content.setLayout(layout)

        if hasattr(self, 'tab') and self.tab.layout() is None:
            tab_layout = QVBoxLayout(self.tab)
            tab_layout.setContentsMargins(6, 6, 6, 6)
            tab_layout.setSpacing(8)
            tab_layout.addWidget(self.setup_name_editor())
            if hasattr(self, 'groupBox'):
                self.groupBox.setParent(None)
                tab_layout.addWidget(self.groupBox)
            if hasattr(self, 'groupBox_2'):
                self.groupBox_2.setParent(None)
                tab_layout.addWidget(self.groupBox_2, 1)
            if hasattr(self, 'pushButton_2'):
                self.pushButton_2.setParent(None)
                tab_layout.addWidget(self.pushButton_2)
            self.tab.setLayout(tab_layout)
        elif hasattr(self, 'tab') and self.tab.layout() is not None:
            self.tab.layout().insertWidget(0, self.setup_name_editor())

        self.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.setMinimumSize(250, 200)

        self.input_dict = {}
        self.x_pclist = []
        self.modes()
        self.comboBox.currentIndexChanged.connect(self.mode_selection)
       
        self.pushButton_2.clicked.connect(self.param)
        self.dict = {}

        self.name_type = None
        
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
        #print(self.comboBox.currentText())
        for i in self.obj.variables:
            if self.obj.variables[i]['name'] == self.comboBox.currentText():
                currentText = i
                break
        self.input_dict = self.obj.param_getter(currentText)
        #print('mode selection ', self.input_dict)
        self.input_params_list()
            
    def input_params_list(self):
        try:
            #print("input_params_list ", self.input_dict)
            for c,i in enumerate(self.input_dict):
                if i == None:
                    continue
                
                l = QLineEdit()
                if self.input_dict[i] != None:
                    l.setText(str(self.input_dict[i]))
                l.setFixedWidth(80)
                lay = QGridLayout()
                lay.addWidget(QLabel(self.obj.variables[i]['name']+":"),0,0, alignment=Qt.AlignLeft) 
                lay.addWidget(l,0,1, alignment=Qt.AlignCenter)
                lay.addWidget(QLabel(self.obj.variables[i]['unit']),0,2, alignment=Qt.AlignLeft)
              
                self.formLayout.addRow(lay)
                self.input_dict[i] = l
            
            self.lines = [line.rstrip('\n') for line in open(parentPath+'/python/utils/thermopackage.txt')]
            for j in self.lines:
                self.cbTP.addItem(str(j))
            self.input_dict['Thermo Package'] = self.cbTP
            
        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)

    def param(self):
        try:
            if hasattr(self, 'check_and_rename_if_needed'):
                if not self.check_and_rename_if_needed():
                    return
            self.dict={}
            for i in self.input_dict:
                if (self.input_dict[i] == None):
                    continue                  
                elif (i == "Thermo Package"):
                    self.dict[i] = self.input_dict[i].currentText()
                else:
                    #print(self.input_dict[i], i, self.obj.type)
                    if (self.input_dict[i].text()):
                        self.dict[i] = self.input_dict[i].text()
                    else:
                        #print(self.input_dict[i].text())
                        self.show_error()
                        break
            
            self.obj.param_setter(self.dict)
            
            print(f"[UI] Submit successful for {self.name}")

            for i in self.container.graphics.graphicsView.items():
                try: 
                    if(i.name == self.name):
                        i.update_tooltip()
                except:
                    pass
            if(self.isVisible()):
                 #added try block to safely handle the errors
                try:
                    currentVal = self.container.graphics.graphicsView.horizontalScrollBar().value()
                    self.container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)
                except Exception:
                    pass
            self.hide()
            
        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
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
            #print("Under result category name ", name)
            result=self.container.result
            obj = self.container.fetch_object(name)
            self.tableWidget.setRowCount(0)
            variKeys = list(obj.variables.keys())
            #print(variKeys)
            for i, val in enumerate(variKeys):
                propertyname = name + '.' + val
                #print(i,val, propertyname)
                if propertyname in result[0]:
                    ind = result[0].index(propertyname)
                    resultval = str(result[-1][ind])
                    #print("######Resultsfetch####",val,resultval)
                    rowPosition = self.tableWidget.rowCount()
                    self.tableWidget.insertRow(rowPosition)
                    self.tableWidget.setItem(rowPosition , 0, QTableWidgetItem(obj.variables[val]['name']))
                    self.tableWidget.setItem(rowPosition , 1, QTableWidgetItem(resultval))
                    self.tableWidget.setItem(rowPosition , 2, QTableWidgetItem(obj.variables[val]['unit']))
                    self.tableWidget.resizeColumnsToContents()

        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)