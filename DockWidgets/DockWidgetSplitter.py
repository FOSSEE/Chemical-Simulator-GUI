import os, sys

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
from ComponentSelector import *
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgets/DockWidgetSplitter.ui')

class DockWidgetSplitter(QDockWidget,ui_dialog):

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
        self.dict = {}

    # input data tab
    def input_params_list(self):
        try:        
            self.l1.setText(self.obj.variables['No']['name']+":")
            self.le1.setText(str(self.obj.variables['No']['value']))
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

            self.input_dict = [self.le1, self.cb2, self.le3, self.le4]
 
        except Exception as e:
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
    
    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}
            self.dict = [int(self.input_dict[0].text()),self.input_dict[1].currentText(), float(self.input_dict[2].text()), float(self.input_dict[3].text())]
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