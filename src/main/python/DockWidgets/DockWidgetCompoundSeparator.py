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
from python.utils.ComponentSelector import *
from collections import defaultdict
from python.utils.Graphics import *

ui_dialog,_ = loadUiType(parentPath+'/ui/DockWidgets/DockWidgetCompoundSeparator.ui')

class DockWidgetCompoundSeparator(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = []
        self.lst = []
        self.input_params_list()
        self.dict = []
            
    def input_params_list(self):
        try:
            if self.type == 'CompoundSeparator':
                self.lst.clear()
                self.calculationGroupBox = QGroupBox('Calculation Parameters')
                self.calculationLayout = QGridLayout()

                r1 = QRadioButton('Stream 1')
                r1.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
                r2 = QRadioButton('Stream 2')
                r2.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
                if self.obj.variables['SepStrm']['value'] == 1:
                    r1.setChecked(True)
                    r2.setChecked(False)
                else:
                    r1.setChecked(False)
                    r2.setChecked(True)


                self.lst = [r1, r2]
                self.calculationLayout.addWidget(r1, 0, 1)
                self.calculationLayout.addWidget(r2, 0, 2)

                for k,val in enumerate(self.obj.compounds):
                    combo = QComboBox()
                    #print("CompoundSeparator combo")
                    for j in self.obj.SepFact_modes:
                        combo.addItem(str(j))
                    #print(self.obj.variables['SepFact_c']['value'][k])
                    combo.setCurrentText(self.obj.variables['SepFact_c']['value'][k])
                    combo.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
                    l = QLineEdit(str(self.obj.variables['SepVal_c']['value'][k]))
                    l.setFixedWidth(80)
                    l.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
                    self.calculationLayout.addWidget(QLabel(val+" :"), k+1,0, alignment=Qt.AlignLeft)
                    self.calculationLayout.addWidget(combo, k+1, 1, alignment=Qt.AlignCenter)
                    self.calculationLayout.addWidget(l,k+1,2, alignment=Qt.AlignCenter)
                    self.lst.append(combo)
                    self.lst.append(l)

                self.calculationLayout.setColumnStretch(3, len(self.obj.compounds)+1)
                self.calculationGroupBox.setLayout(self.calculationLayout)
                
                btn = QPushButton('Submit')
                btn.clicked.connect(self.param)
                
                self.gridLayout.setVerticalSpacing(5)
                self.gridLayout.addWidget(self.calculationGroupBox,0,0)
                self.gridLayout.addWidget(btn,1,0)

                self.input_dict = self.lst            
                        
        except Exception as e:
            print(e)

    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def update_compounds(self):
        try:
            self.obj.init_variables()
            t_item = self.calculationGroupBox.layout().itemAt(0)
            self.calculationGroupBox.layout().removeItem(t_item)
            while(t_item):
                t_widget = t_item.widget()
                if(t_widget):
                    t_widget.setHidden(True)
                    self.calculationGroupBox.layout().removeWidget(t_widget)
                t_item = self.calculationGroupBox.layout().itemAt(0)
            self.input_params_list()
        except Exception as e:
            print(e)
            

    def param(self):
        try:
            self.dict=[]
           
            self.dict = [self.input_dict[0].isChecked(), self.input_dict[1].isChecked()]
            j = 2
            for i in range(len(self.obj.compounds)):
                self.dict.append(self.input_dict[j+i].currentText())
                if(self.input_dict[j+i+1].text()):
                    self.dict.append(self.input_dict[j+i+1].text())
                    j += 1
                else:
                    self.show_error()
                
            
            self.obj.param_setter(self.dict)
            if(self.isVisible()):
                currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
                self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)
            self.hide()
            
        except Exception as e:
            print(e)
    def closeEvent(self,event):
        scrollHVal = self.parent().container.graphics.graphicsView.horizontalScrollBarVal
        currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
        self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)