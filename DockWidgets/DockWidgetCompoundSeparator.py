from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from functools import partial
from ComponentSelector import *
from collections import defaultdict
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgets/DockWidgetCompoundSeparator.ui')

class DockWidgetCompoundSeparator(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = []
        
        self.input_params_list()
        self.dict = []
            
    def input_params_list(self):
        try:
            if self.type == 'CompoundSeparator':
                calculationGroupBox = QGroupBox('Calculation Parameters')
                calculationLayout = QGridLayout()

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


                lst = [r1, r2]
                calculationLayout.addWidget(r1, 0, 1)
                calculationLayout.addWidget(r2, 0, 2)

                for k,val in enumerate(self.obj.compounds):
                    combo = QComboBox()
                    print("CompoundSeparator combo")
                    for j in self.obj.SepFact_modes:
                        combo.addItem(str(j))
                    print(self.obj.variables['SepFact_c']['value'][k])
                    combo.setCurrentText(self.obj.variables['SepFact_c']['value'][k])
                    combo.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
                    l = QLineEdit(str(self.obj.variables['SepVal_c']['value'][k]))
                    l.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
                    calculationLayout.addWidget(QLabel(val+" :"), k+1,0, alignment=Qt.AlignLeft)
                    calculationLayout.addWidget(combo, k+1, 1, alignment=Qt.AlignCenter)
                    calculationLayout.addWidget(l,k+1,2, alignment=Qt.AlignCenter)
                    lst.append(combo)
                    lst.append(l)

                calculationLayout.setColumnStretch(3, len(self.obj.compounds)+1)
                calculationGroupBox.setLayout(calculationLayout)
                
                btn = QPushButton('Submit')
                btn.clicked.connect(self.param)
                
                self.gridLayout.setVerticalSpacing(5)
                self.gridLayout.addWidget(calculationGroupBox,0,0)
                self.gridLayout.addWidget(btn,1,0)

                self.input_dict = lst            
                        
        except Exception as e:
            print(e)

    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict=[]
           
            self.dict = [self.input_dict[0].isChecked(), self.input_dict[1].isChecked()]
            j = 2
            for i in range(len(self.obj.compounds)):
                print(j+i)
                self.dict.append(self.input_dict[j+i].currentText())
                self.dict.append(self.input_dict[j+i+1].text())
                j += 1
            
            self.obj.param_setter(self.dict)
            self.hide()
            
        except Exception as e:
            print(e)
    def closeEvent(self,event):
        scrollHVal = self.parent().container.graphics.graphicsView.horizontalScrollBarVal
        currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
        self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue((scrollHVal+currentVal)/2)