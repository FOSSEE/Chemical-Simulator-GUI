from OMChem.Flowsheet import Flowsheet
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
        self.compounds = compound_selected
        self.name = ''
        self.mode = None
        self.modeVal = None
        self.type = ''
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.Prop = {}
        self.x = 2500-30
        self.y = 2500-30
        self.Prop = {}
        self.modeslist = []
        self.parameters = {}
        # self.input_parameters = {}
        self.extra = []
        self.ForNaming = []
        self.multidict = []
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

    def add_connection(self,flag,UnitOpr):
        if flag==1:
            # Input stream if flag is 1
            self.InputStms.append(UnitOpr)
            print("INPUT CONNECTION")
        else :
            print("OUTPUT CONNECTION")
            self.OutputStms.append(UnitOpr)

    def OM_Flowsheet_Initialize(self):
        self.OM_data_init = ''

        if(self.ThermoPackReq):
            if len(self.extra)>1:
                for i in range(self.extra):
                    latest = ''
                    for j in range(self.extra[i]):
                        if self.extra[i][j]!='.':
                            latest += self.extra[i][j]
                        self.ForNaming[i] = latest   



        if(self.ThermoPackReq):
            if len(self.extra)==1:
                for i in self.extra:
                    self.OM_data_init += ('model '+i+str(self.counter)+'\n')
                    self.OM_data_init += ('extends Simulator.UnitOperations.'+i+';\n')
                    self.OM_data_init += ('extends Simulator.Files.ThermodynamicPackages.'+self.thermoPackage+';\n')
                    self.OM_data_init += ('end '+i+str(self.counter)+';\n')

                    self.OM_data_init += i+str(self.counter) + ' ' + self.name + '(Nc = ' + str(len(self.compounds)) 

            else:
                for i in range(len(self.extra)):
                    if i!=(len(self.extra)-1):
                        self.OM_data_init += ('model '+self.ForNaming[i]+str(self.counter)+'\n')
                        self.OM_data_init += ('extends Simulator.UnitOperations.'+self.extra[i]+';\n')
                        self.OM_data_init += ('extends Simulator.Files.ThermodynamicPackages.'+self.thermoPackage+';\n')
                        self.OM_data_init += ('end '+self.ForNaming[i]+str(self.counter)+';\n')
                    else:
                        self.OM_data_init += ('model '+self.ForNaming[i]+str(self.counter)+'\n')
                        self.OM_data_init += ('extends Simulator.UnitOperations.'+self.extra[i]+';\n')
                        for j in range(len(self.extra)-1):
                            self.OM_data_init += (self.ForNaming[j] + str(self.counter) +' ' + self.ForNaming[j] + '#' + self.multidict[j] + ';\n')

                            self.OM_data_init += ('end '+self.ForNaming[i]+str(self.counter)+';\n')

                    self.OM_data_init += self.ForNaming[i] + str(self.counter) + ' ' + self.ForNaming + '(Nc = ' + str(len(self.compounds))
                 
            C = str(self.compounds).strip('[').strip(']')
            C = C.replace("'", "")  
            self.OM_data_init += ',C = {' + C + '}'

                    
                        
            for k,v in self.parameters.items():
                self.OM_data_init += ', '
                self.OM_data_init += k + ' = ' + str(v)
                self.OM_data_init += ');\n' 

        else: 
            self.OM_data_init += 'Simulator.UnitOperations.' + self.type + ' ' + self.name + '(Nc = ' + str(len(self.compounds))
            C = str(self.compounds).strip('[').strip(']')
            C = C.replace("'", "")  
            self.OM_data_init += ',C = {' + C + '}'

            for k,v in self.parameters.items():
                self.OM_data_init += ', '
                self.OM_data_init += k + ' = ' + str(v)

            self.OM_data_init += ');\n'

                #print("HERE WE GO")
                #print(self.OM_data_init)

        return self.OM_data_init  




    def OM_Flowsheet_Equation(self):
        self.OM_data_eqn = ''

        if len(self.InputStms)>1:
            strcount = 1
            for strm in self.InputStms:
                self.OM_data_eqn += ('connect(' + strm.name + '.Out,' + self.name + '.In[' + str(strcount) + ']);\n')
                strcount += 1
        else:
            self.OM_data_eqn += ('connect(' + self.name + '.In,' + self.InputStms[0].name + '.Out);\n')

        if len(self.OutputStms)>1:
            strcount = 1
            for strm in self.OutputStms:
                self.OM_data_eqn += ('connect(' + strm.name + '.In,' + self.name + '.Out[' + str(strcount) + ']);\n')
                strcount += 1
        else:
            self.OM_data_eqn += ('connect(' + self.name + '.Out,' + self.OutputStms[0].name + '.In);\n')    
        
        if self.mode:
            self.OM_data_eqn += (self.name + '.' + self.mode + '=' + self.modeVal + ';\n')    

        return self.OM_data_eqn

class Heater(UnitOperation):

    def __init__(self, name='Heater', Pdel=None, Eff='None'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'Heater'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.Prop = {
            'Pdel':None,
            'Eff':None,
            'Tout':None,
            'Tdel':None,
            'Q':None,
        }
        self.modesList = ["Q","Tout","xvapout","Tdel"] 
        self.extra = None
        self.ForNaming = None
        self.Pdel = Pdel
        self.Eff = Eff
        self.parameters = {'Pdel':self.Pdel, 'Eff':self.Eff}
        # self.input_parameters = {'Pdel':self.Pdel, 'Eff':self.Eff}
        type(self).counter += 1

class Cooler(UnitOperation):

    def __init__(self, name='Cooler', Pdel=None, Eff='None'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'Cooler'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.Prop = {
            'Pdel':None,
            'Eff':None,
            'Tout':None,
            'Tdel':None,
            'Q':None,
        }
        self.modesList = ["Q","Tout","xvapout","Tdel","enFlo"]
        self.extra = None
        self.ForNaming = None
        self.Pdel = Pdel
        self.Eff = Eff
        self.parameters = {'Pdel':self.Pdel, 'Eff':self.Eff}
        # self.input_parameters = {'Pdel':self.Pdel, 'Eff':self.Eff}
        type(self).counter += 1

class AdiabaticCompressor(UnitOperation):

    def __init__(self, name='AdiabaticCompressor', Eff='None'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'AdiabaticCompressor'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.Prop = {
            'Pdel':None,
            'Tdel':None,
            'Pout':None,
            'Tout':None,
            'Q':None
        }
        self.modesList = ["Pdel","Pout","Q"]
        self.extra = ['AdiabaticCompressor']
        self.ForNaming = ['AdiabaticCompressor']
        self.ThermoPackReq = True
        self.thermoPackage ="RaoultsLaw"
        self.Eff = Eff
        self.parameters = {'Eff':self.Eff}
        # self.input_parameters = {"Eff":self.Eff,"thermoPackage":self.thermoPackage}
        type(self).counter += 1

class AdiabaticExpander(UnitOperation):

    def __init__(self, name='AdiabaticExpander', Eff='None'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'AdiabaticExpander'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.Prop = {
            'Pdel':None,
            'Tdel':None,
            'Pout':None,
            'Tout':None,
            'Q':None
        }
        self.modesList = ["Pdel","Pout","Q"]
        self.extra = ['AdiabaticExpander']
        self.ForNaming = ['AdiabaticExpander']
        self.ThermoPackReq = True
        self.thermoPackage ="RaoultsLaw"
        self.Eff = Eff
        self.parameters = {'Eff':self.Eff}
        # self.input_parameters = {"Eff":self.Eff,"thermoPackage":self.thermoPackage}
        type(self).counter += 1
        

