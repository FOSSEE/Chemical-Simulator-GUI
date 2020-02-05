from OMChem.Flowsheet import Flowsheet
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
from container import *

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
        self.pos = QPointF(self.x, self.y)
        #self.Prop = {}
        self.variables = {}
        self.modeslist = []
        self.parameters = []
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
<<<<<<< HEAD
        # print("Hello hello ", self.mode)
        #params = self.parameters.copy()
        for i in self.parameters:
            params[i] = self.variables[i]['value']
=======
        params = self.parameters.copy()
>>>>>>> 190966e010e321e4df56d40104ec80467a870e53
        params[self.mode] = None
        return params
        
    def paramsetter(self,params):
        print("paramsetter ", params)
        for k,v in params.items():
            print(k,v)
            if k != self.mode:
                self.k = v
                self.variables[k]['value'] = v
            else:
                self.modeVal = params[self.mode]

    def add_connection(self,flag,UnitOpr):
        if flag==1:
            # Input stream if flag is 1
            print("INPUT CONNECTION")
            self.InputStms.append(UnitOpr)
        else :
            print("OUTPUT CONNECTION")
            self.OutputStms.append(UnitOpr)

    def setPos(self,pos):
        self.pos = pos

    def OM_Flowsheet_Initialize(self):
        self.OM_data_init = ''

        if(self.ThermoPackReq):
            if len(self.extra)>1:
                for i in range(len(self.extra)):
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

            for k in self.parameters:
                self.OM_data_init += ', '
                self.OM_data_init += k + ' = ' + str(self.variables[k]['value'])

            self.OM_data_init += ');\n'
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

    def __init__(self, name='Heater'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'Heater'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.modesList = ['Q','Tout','xvapout','Tdel']
        self.parameters = ['Pdel', 'Eff'] 
        self.extra = None
        self.ForNaming = None
        type(self).counter += 1

        self.variables = {
            'Pdel'  : {'name':'Pressure Drop',          'value':0,       'unit':'Pa'},
            'Eff'   : {'name':'Efficiency',             'value':1,       'unit':''},
            'Tout'  : {'name':'Outlet Temperature',     'value':298.15,  'unit':'K'},
            'Tdel'  : {'name':'Temperature Increase',   'value':0,       'unit':'K'},
            'Q'     : {'name':'Heat Added',             'value':0,       'unit':'W'},
        }

class Cooler(UnitOperation):

    def __init__(self, name='Cooler'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'Cooler'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.modesList = ["Q","Tout","xvapout","Tdel"]
        self.extra = None
        self.ForNaming = None
        self.parameters = ['Pdel', 'Eff']
        type(self).counter += 1

        self.variables = {
            'Pdel'  : {'name':'Pressure Drop',          'value':0,       'unit':'Pa'},
            'Eff'   : {'name':'Efficiency',             'value':1,       'unit':''},
            'Tout'  : {'name':'Outlet Temperature',     'value':298.15,       'unit':'K'},
            'Tdel'  : {'name':'Temperature Increase',   'value':0,       'unit':'K'},
            'Q'     : {'name':'Heat Added',             'value':0,       'unit':'W'},
        }

class AdiabaticCompressor(UnitOperation):

    def __init__(self, name='AdiabaticCompressor'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'AdiabaticCompressor'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.modesList = ["Pdel","Pout","Q"]
        self.extra = ['AdiabaticCompressor']
        self.ForNaming = ['AdiabaticCompressor']
        self.ThermoPackReq = True
        self.thermoPackage ="RaoultsLaw" 
        self.parameters = ['Eff']
        type(self).counter += 1
        self.variables = {
            'Pdel'  : {'name':'Pressure Drop',          'value':0,       'unit':'Pa'},
            'Tdel'  : {'name':'Temperature Increase',   'value':0,       'unit':'K'},
            'Pout'  : {'name':'Outlet Pressure',        'value':101325,       'unit':'Pa'},
            'Tout'  : {'name':'Outlet Temperature',     'value':298.15,       'unit':'K'},
            'Q'     : {'name':'Heat Added',             'value':0,       'unit':'W'},
        }

class AdiabaticExpander(UnitOperation):

    def __init__(self, name='AdiabaticExpander'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'AdiabaticExpander'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.modesList = ["Pdel","Pout","Q"]
        self.extra = ['AdiabaticExpander']
        self.ForNaming = ['AdiabaticExpander']
        self.ThermoPackReq = True
        self.thermoPackage ="RaoultsLaw"
        self.parameters = ['Eff']
        type(self).counter += 1
        self.variables = {
            'Pdel'  : {'name':'Pressure Drop',          'value':0,       'unit':'Pa'},
            'Tdel'  : {'name':'Temperature Increase',   'value':0,       'unit':'K'},
            'Pout'  : {'name':'Outlet Pressure',        'value':101325,  'unit':'Pa'},
            'Tout'  : {'name':'Outlet Temperature',     'value':298.15,  'unit':'K'},
            'Q'     : {'name':'Heat Added',             'value':0,       'unit':'W'},
        }

        