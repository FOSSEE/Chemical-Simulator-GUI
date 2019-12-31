from OMChem.Flowsheet import Flowsheet
from OMChem.MatStm import MatStm
from OMChem.UnitOprns import UnitOpr
from OMChem.EngStm import EngStm
from Graphics import Graphics
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QTextDocument ,QTextCursor ,QTextCharFormat ,QFont ,QPixmap
from PyQt5.uic import loadUiType
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGraphicsProxyWidget, QGraphicsObject, QGraphicsEllipseItem ,QGraphicsPixmapItem,QApplication, QGraphicsView, QGraphicsScene, QHBoxLayout, QWidget, QLabel
from PyQt5.QtGui import QBrush ,QTransform ,QMouseEvent
from PyQt5.QtGui import *
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
from component_selector import *

class UnitOperation():
    counter = 1
    
    def __init__(self):
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = []
        self.OutputStms = []
        self.name = ''
        self.mode = None
        self.modeVal = None
        self.type = ''
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30
        self.y = 2500-30
        self.Prop = {}
        self.modeslist = []
        self.parameters = {}
        # self.input_parameters = {}
        self.extra = None
        self.ForNaming = None
        self.multidict = None
        self.ThermoPackReq = False
        self.thermoPackage = None

    def paramgetter(self,mode=None):
        params = {}
        if mode == None:
            self.mode = self.modeslist[0]
        else:
            self.mode = mode
        params = self.parameters.copy()
        params[self.mode] = None
        return params
        
    def paramsetter(self,params):
        print(params)
        for k,v in params.items():
            print(k,v)
            if k != self.mode:
                self.k = v
                self.parameters[k] = v
            else:
                self.modeVal = params[self.mode]

    # def connect(self,InputStms,OutputStms):
    #     self.InputStms = InputStms
    #     self.OutputStms = OutputStms

    def add_connection(self,flag,UnitOpr):
        if flag==1:
            # Input stream if flag is 1
            self.InputStms.append(UnitOpr)
            print("INPUT CONNECTION")
        else :
            print("OUTPUT CONNECTION")
            self.OutputStms.append(UnitOpr)

    # def send_to_flowsheet(self):
    #     Inst = UnitOpr(name=self.name,counter=type(self).counter,Type='Heater',parameters=self.parameters,mode=self.mode,modeVal=self.modeVal,ThermoPackReq=self.ThermoPackReq,thermoPack=self.thermoPackage,extra=self.extra,multidict=self.multidict,inputs=self.no_of_inputs,outputs=self.no_of_outputs)
    #     # Inst.connect(self.InputStms,self.OutputStms)
    #     Inst.InputStms = self.InputStms
    #     Inst.OutputStms = self.OutputStms
    #     return Inst

class HeaterClass(UnitOperation):

    def __init__(self, name='Heater', pressDrop=None, eff='None'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'Heater'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.Prop = {
            'pressDrop':None,
            'eff':None,
            'outT':None,
            'tempInc':None,
            'heatAdd':None,
        }
        self.modesList = ["heatAdd","outT","outVapPhasMolFrac","tempInc","enFlo"] 
        self.extra = None
        self.ForNaming = None
        self.pressDrop = pressDrop
        self.eff = eff
        self.parameters = {'pressDrop':self.pressDrop, 'eff':self.eff}
        # self.input_parameters = {'pressDrop':self.pressDrop, 'eff':self.eff}
        type(self).counter += 1

class CoolerClass(UnitOperation):

    def __init__(self, name='Cooler', pressDrop=None, eff='None'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'Cooler'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.Prop = {
            'pressDrop':None,
            'eff':None,
            'outT':None,
            'tempDrop':None,
            'heatRem':None,
        }
        self.modesList = ["heatRem","outT","outVapPhasMolFrac","tempDrop","enFlo"]
        self.extra = None
        self.ForNaming = None
        self.pressDrop = pressDrop
        self.eff = eff
        self.parameters = {'pressDrop':self.pressDrop, 'eff':self.eff}
        # self.input_parameters = {'pressDrop':self.pressDrop, 'eff':self.eff}
        type(self).counter += 1

class AdiaCompClass(UnitOperation):

    def __init__(self, name='AdiaComp', eff='None'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'AdiaComp'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.modesList = ["pressInc","outP","reqPow"]
        self.extra = ['Adiabatic_Compressor']
        self.ForNaming = ['Adiabatic_Compressor']
        self.ThermoPackReq = True
        self.thermoPackage ="Raoults_Law"
        self.eff = eff
        self.parameters = {'eff':self.eff}
        # self.input_parameters = {"eff":self.eff,"thermoPackage":self.thermoPackage}
        type(self).counter += 1

class AdiaExpClass(UnitOperation):

    def __init__(self, name='AdiaExp', eff='None'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'AdiaExp'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.modesList = ["pressDrop","outP","genPow"]
        self.extra = ['Adiabatic_Expander']
        self.ForNaming = ['Adiabatic_Expander']
        self.ThermoPackReq = True
        self.thermoPackage ="Raoults_Law"
        self.eff = eff
        self.parameters = {'eff':self.eff}
        # self.input_parameters = {"eff":self.eff,"thermoPackage":self.thermoPackage}
        type(self).counter += 1


def helperFunc(type):
    if(type=="MatStm"):
        return MatStm(CompNames=compound_selected)  
    else:
        return eval(type+"Class")()
    
        

