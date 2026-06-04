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

ui_dialog,_ = loadUiType(parentPath+'/ui/DockWidgets/DockWidgetMixer.ui')

class DockWidgetMixer(QDockWidget,ui_dialog):

    def __init__(self,name,comptype,obj,container,parent=None):
        QDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)
        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = []
        self.x_pclist = []
        self.container = container
        self.input_params_list()
        self.btn.clicked.connect(self.param)
        self.dict = {}

    # input data tab
    def input_params_list(self):
        try:        
            self.l1.setText(self.obj.variables['NI']['name']+":")

            # Replace the line-edit (le1) with a combo box for NI (2–6)
            self.ni_combo = QComboBox()
            for v in range(2, 7):
                self.ni_combo.addItem(str(v))
            current_ni = self.obj.variables['NI']['value']
            self.ni_combo.setCurrentText(str(current_ni))

            # Swap le1 out of the gridLayout and put ni_combo in its place
            # The grid layout is named 'gridLayout' in the .ui file
            grid = self.gridLayout
            # Find le1's position in the grid (row=0, col=2 per the .ui)
            idx = grid.indexOf(self.le1)
            if idx >= 0:
                row, col, rowspan, colspan = grid.getItemPosition(idx)
                grid.removeWidget(self.le1)
                self.le1.hide()
                self.le1.setParent(None)
                grid.addWidget(self.ni_combo, row, col)
            else:
                # Fallback: just hide le1 and add combo at known position
                self.le1.hide()
                self.le1.setParent(None)
                grid.addWidget(self.ni_combo, 0, 2)

            self.u1.setText(self.obj.variables['NI']['unit'])
            for i in self.obj.Pout_modes:
                self.cb2.addItem(str(i))
            self.cb2.setCurrentText(self.obj.variables['outPress']['value'])

            self.l2.setText(self.obj.variables['outPress']['name']+":")
            self.input_dict = [self.ni_combo, self.cb2]
 
        except Exception as e:
            print(f"[UI] input_params_list failed for {self.name}: {e}")
            print(e)
    
    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}
            new_ni = int(self.input_dict[0].currentText())
            self.dict = [new_ni, self.input_dict[1].currentText()]
            self.obj.param_setter(self.dict)
            print(f"[UI] Submit successful for {self.name}")

            # Refresh input ports 
            from python.utils.Graphics import lst
            for node in lst:
                if node.obj is self.obj:
                    node.update_input_ports(new_ni)
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
    def closeEvent(self,event):
        #added try block to safely handle the errors
        try:
            currentVal = self.container.graphics.graphicsView.horizontalScrollBar().value()
            self.container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)
        except Exception:
            pass