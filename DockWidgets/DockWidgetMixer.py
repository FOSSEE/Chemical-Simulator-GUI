from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
from ComponentSelector import *
from Graphics import *

ui_dialog,_ = loadUiType('DockWidgets/DockWidgetMixer.ui')

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
        self.input_params_list()
        self.btn.clicked.connect(self.param)
        self.dict = {}

    # input data tab
    def input_params_list(self):
        try:        
            self.l1.setText(self.obj.variables['NI']['name']+":")
            self.le1.setText(str(self.obj.variables['NI']['value']))
            self.u1.setText(self.obj.variables['NI']['unit'])
            for i in self.obj.Pout_modes:
                self.cb2.addItem(str(i))
            self.cb2.setCurrentText(self.obj.variables['outPress']['value'])

            self.l2.setText(self.obj.variables['outPress']['name']+":")
            self.input_dict = [self.le1, self.cb2]
 
        except Exception as e:
            print(e)
    
    def show_error(self):
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def param(self):
        try:
            self.dict={}
            self.dict = [int(self.input_dict[0].text()), self.input_dict[1].currentText()]
            self.obj.param_setter(self.dict)
            self.hide()
            
        except Exception as e:
            print(e)
    def closeEvent(self,event):
        scrollHVal = self.parent().container.graphics.graphicsView.horizontalScrollBarVal
        currentVal = self.parent().container.graphics.graphicsView.horizontalScrollBar().value()
        self.parent().container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)