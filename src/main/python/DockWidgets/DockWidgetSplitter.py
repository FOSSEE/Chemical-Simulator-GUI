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

ui_dialog,_ = loadUiType(parentPath+'/ui/DockWidgets/DockWidgetSplitter.ui')

class DockWidgetSplitter(BaseDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        BaseDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = []
        self.container = container
        self.input_params_list()
        self.btn.clicked.connect(self.param)
        self.dict = {}

    # input data tab
    def input_params_list(self):
        try:        
            self.l1.setText(self.obj.variables['No']['name']+":")

            # Replace le1 with a combo box for No. of Output (2–6)
            self.no_combo = QComboBox()
            for v in range(2, 7):
                self.no_combo.addItem(str(v))
            current_no = self.obj.variables['No']['value']
            self.no_combo.setCurrentText(str(current_no))

            # Swap le1 out of gridLayout and put no_combo in its place
            grid = self.gridLayout
            idx = grid.indexOf(self.le1)
            if idx >= 0:
                row, col, rowspan, colspan = grid.getItemPosition(idx)
                grid.removeWidget(self.le1)
                self.le1.hide()
                self.le1.setParent(None)
                grid.addWidget(self.no_combo, row, col)
            else:
                self.le1.hide()
                self.le1.setParent(None)
                grid.addWidget(self.no_combo, 0, 2)

            self.u1.setText(self.obj.variables['No']['unit'])

            self.l2.setText(self.obj.variables['CalcType']['name'] + ":")
            for i in self.obj.CalcType_modes:
                self.cb2.addItem(str(i))
            self.cb2.setCurrentText(self.obj.variables['CalcType']['value'])

            self.l3.setText("Stream 1 :")
            self.le3.setText(str(self.obj.variables['SpecVal_s']['value'][0]))
            self.u3.setText(self.obj.variables['SpecVal_s']['unit'])
            self.l4.setText("Stream 2 :")
            self.le4.setText(str(self.obj.variables['SpecVal_s']['value'][1]))
            self.u4.setText(str(self.obj.variables['SpecVal_s']['unit']))
            self.cb2.currentIndexChanged.connect(self.fun)

            self.input_dict = [self.no_combo, self.cb2, self.le3, self.le4]
 
        except Exception as e:
            print(f"[UI] input_params_list failed for {self.name}: {e}")
            print(e)

    def fun(self):
        if self.cb2.currentText() == 'Molar_Flow':
            self.u3.setText('mol/s')
            self.u4.setText('mol/s')
        elif self.cb2.currentText() == 'Mass_Flow':
            self.u3.setText('g/s')
            self.u4.setText('g/s')
        else:
            self.u3.setText('')
            self.u4.setText('')
    
    def param(self):
        try:
            self.dict={}
            new_no = int(self.input_dict[0].currentText())
            self.dict = [new_no, self.input_dict[1].currentText(), float(self.input_dict[2].text()), float(self.input_dict[3].text())]
            self.obj.param_setter(self.dict)
            print(f"[UI] Submit successful for {self.name}")

            # Refresh output ports 
            from python.utils.Graphics import lst
            for node in lst:
                if node.obj is self.obj:
                    node.update_output_ports(new_no)
                    break

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