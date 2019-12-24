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



class HeaterClass():
    counter = 1;
    
    def __init__(self,name='Heater',pressDrop = None, eff = None):
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = []
        self.OutputStms = []
        self.name = name + str(HeaterClass.counter)
        self.mode = None
        self.modeVal = None
        self.type = 'Heater'
        self.pressDrop = pressDrop
        self.eff = eff
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30
        self.y = 2500-30
        self.addedcomp = None
        self.extra = None
        HeaterClass.counter+=1

    def modesList(self):
        return ["heatAdd","outT","outVapPhasMolFrac","tempInc","enFlo"] 

    def paramgetter(self,mode="heatAdd"):
        self.mode = mode
        dict = {"pressDrop":None,"eff":None,self.mode:None}
        return dict

    def add_compounds(self,addedcomp):
        self.addedcomp = addedcomp
        
        
        
    def paramsetter(self,dict):
        
        self.pressDrop = dict['pressDrop']
        self.eff = dict['eff']
        self.modeVal = dict[self.mode]

    def connect(self,InputStms,OutputStms):
        self.InputStms = InputStms
        self.OutputStms = OutputStms

    def add_connection(self,flag,UnitOpr):
        if flag==1:
            # Input stream if flag is 1
            self.InputStms.append(UnitOpr)
            print("INPUT CONNECTION")
        else :
            print("OUTPUT CONNECTION")
            self.OutputStms.append(UnitOpr)
            


    def send_to_flowsheet(self,addedcomp):
        self.addedcomp = addedcomp
        parameters = [['pressDrop',self.pressDrop],['eff',self.eff]]
        Inst = UnitOpr(self.name,HeaterClass.counter,'Heater',parameters,self.mode,self.modeVal,False,None,self.extra,None,self.no_of_inputs,self.no_of_outputs)
        Inst.connect(self.InputStms,self.OutputStms)
        return Inst


class CoolerClass():
    counter = 1;
    
    def __init__(self,name='Cooler',pressDrop = None, eff = None):
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = []
        self.OutputStms = []
        self.name = name + str(CoolerClass.counter)
        self.mode = None
        self.modeVal = None
        self.type = 'Cooler'
        self.pressDrop = pressDrop
        self.eff = eff
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30
        self.y = 2500-30
        self.addedcomp = None
        self.extra = None
        HeaterClass.counter+=1

    def modesList(self):
        return ["heatRem","outT","outVapPhasMolFrac","tempDrop","enFlo"] 

    def paramgetter(self,mode="heatRem"):
        self.mode = mode
        dict = {"pressDrop":None,"eff":None,self.mode:None}
        return dict

    def add_compounds(self,addedcomp):
        self.addedcomp = addedcomp
        
        
        
    def paramsetter(self,dict):
        
        self.pressDrop = dict['pressDrop']
        self.eff = dict['eff']
        self.modeVal = dict[self.mode]

    def connect(self,InputStms,OutputStms):
        self.InputStms = InputStms
        self.OutputStms = OutputStms

    def add_connection(self,flag,UnitOpr):
        if flag==1:
            # Input stream if flag is 1
            self.InputStms.append(UnitOpr)
            print("INPUT CONNECTION")
        else :
            print("OUTPUT CONNECTION")
            self.OutputStms.append(UnitOpr)
            


    def send_to_flowsheet(self,addedcomp):
        self.addedcomp = addedcomp
        parameters = [['pressDrop',self.pressDrop],['eff',self.eff]]
        Inst = UnitOpr(self.name,CoolerClass.counter,'Cooler',parameters,self.mode,self.modeVal,False,None,self.extra,None,self.no_of_inputs,self.no_of_outputs)
        Inst.connect(self.InputStms,self.OutputStms)
        return Inst        




class AdiaCompClass():
    counter = 1;
    
    def __init__(self,name='AdiaComp', eff = None):
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = []
        self.OutputStms = []
        self.name = name + str(AdiaCompClass.counter)
        self.mode = None
        self.modeVal = None
        self.type = 'AdiaComp'
        self.thermoPackage ="Raoults_Law"
        #self.pressDrop = pressDrop
        self.eff = eff
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30
        self.y = 2500-30
        self.addedcomp = None
        self.extra = ['Adiabatic_Compressor']
        AdiaCompClass.counter+=1

    def modesList(self):
        return ["pressInc","outP","reqPow"] 

    def add_compounds(self,addedcomp):
        self.addedcomp = addedcomp

    def paramgetter(self,mode="pressInc"):
        self.mode = mode
        dict = {"eff":None,self.mode:None,"thermoPackage":None}
        return dict
        
    def paramsetter(self,dict):

        self.eff = dict['eff']
        self.modeVal = dict[self.mode]

    def add_connection(self,flag,UnitOpr):
        if flag==1:
            # Input stream if flag is 1
            self.InputStms.append(UnitOpr)
            print("INPUT CONNECTION")
        else :
            print("OUTPUT CONNECTION")
            self.OutputStms.append(UnitOpr)    

    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms  

    def send_to_flowsheet(self,addedcomp):
        self.addedcomp = addedcomp
        parameters = [['eff',self.eff]]
        Inst = UnitOpr(self.name,AdiaCompClass.counter,'AdiaComp',parameters,self.mode,self.modeVal,True,self.thermoPackage,self.extra,None,self.no_of_inputs,self.no_of_outputs)
        Inst.connect(self.InputStms,self.OutputStms)
        return Inst

class AdiaExpClass():
    counter = 1;
    
    def __init__(self,name='AdiaExp', eff = None):
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = []
        self.OutputStms = []
        self.name = name + str(AdiaExpClass.counter)
        self.mode = None
        self.modeVal = None
        self.type = 'AdiaExp'
        self.thermoPackage ="Raoults_Law"
        #self.pressDrop = pressDrop
        self.eff = eff
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30
        self.y = 2500-30
        self.addedcomp = None
        self.extra = ['Adiabatic_Expander']
        AdiaExpClass.counter+=1

    def modesList(self):
        return ["pressDrop","outP","genPow"] 

    def add_compounds(self,addedcomp):
        self.addedcomp = addedcomp

    def paramgetter(self,mode="pressDrop"):
        self.mode = mode
        dict = {"eff":None,self.mode:None,"thermoPackage":None}
        return dict
        
    def paramsetter(self,dict):

        self.eff = dict['eff']
        self.modeVal = dict[self.mode]

    def add_connection(self,flag,UnitOpr):
        if flag==1:
            # Input stream if flag is 1
            self.InputStms.append(UnitOpr)
            print("INPUT CONNECTION")
        else :
            print("OUTPUT CONNECTION")
            self.OutputStms.append(UnitOpr)    

    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms  

    def send_to_flowsheet(self,addedcomp):
        self.addedcomp = addedcomp
        parameters = [['eff',self.eff]]
        Inst = UnitOpr(self.name,AdiaExpClass.counter,'AdiaExp',parameters,self.mode,self.modeVal,True,self.thermoPackage,self.extra,None,self.no_of_inputs,self.no_of_outputs)
        Inst.connect(self.InputStms,self.OutputStms)
        return Inst                



    

        



def helperFunc(type):
    if(type=="MatStm"):
        return MatStm(CompNames=compound_selected)
    else:
        return eval(type+"Class")()
    
        

