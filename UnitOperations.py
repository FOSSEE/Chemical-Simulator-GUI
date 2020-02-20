from OMChem.Flowsheet import Flowsheet
from OMChem.EngStm import EngStm
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
from ComponentSelector import *
from Container import *

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
        self.x = 2500-30 
        self.y = 2500-30
        self.pos = QPointF(self.x, self.y)
        self.count = UnitOperation.counter
        self.variables = {}
        self.modesList = []
        self.parameters = []
        self.extra = []
        self.ForNaming = []
        self.multidict = []
        self.ThermoPackReq = False
        self.thermoPackage = None

    def paramgetter(self,mode=None):
        params = {}
        if mode == None and self.modesList:
            self.mode = self.modesList[0]
        else:
            self.mode = mode
            params[self.mode] = None
        for i in self.parameters:
            params[i] = self.variables[i]['value']
        
        return params
        
    def paramsetter(self,params):
        print("paramsetter ", params)
        for k,v in params.items():
            print(k,v)
            if k != self.mode:
                self.k = v
                self.variables[k]['value'] = v
            else:
                self.variables[k]['value'] = v
                self.modeVal = params[self.mode]
        print(self.variables)

    def add_connection(self,flag,UnitOpr):
        if flag==1:                 # Input stream if flag is 1
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

class ShortcutColumn(UnitOperation):
    def __init__(self, CompNames = [], name='ShortcutColumn'):
        UnitOperation.__init__(self)
        self.name = name + str(ShortcutColumn.counter) 
        self.type = 'ShortcutColumn'
        self.no_of_inputs = 1 
        self.no_of_outputs = 2  
        self.InputStms = None
        self.OutputStms = None
        self.EngStm1 = EngStm(name='EngStm1'+self.name)
        self.EngStm2 = EngStm(name='EngStm2'+self.name)
        self.count = ShortcutColumn.counter

        self.parameters = ['HKey', 'LKey', 'HKey_x_pc', 'LKey_x_pc', 'Ctype', 'Pcond', 'Preb', 'RR']
        type(self).counter += 1

        self.variables = {
            'HKey'  :           {'name':'Heavy Key',                    'value':None,           'unit':''},
            'LKey'  :           {'name':'Light Key',                    'value':None,           'unit':''},
            'HKey_x_pc' :       {'name':'Heavy Key Mole Fraction',      'value':0.01,           'unit':'mol/s'},
            'LKey_x_pc' :       {'name':'Light Key Mole Fraction',      'value':0.01,           'unit':'mol/s'},
            'Ctype' :           {'name':'Condensor Type',               'value':None,           'unit':''},
            'thermoPackage' :   {'name':'Thermo Package',               'value':'Raoults_Law',  'unit':''},
            'Pcond' :           {'name':'Condensor Pressure',           'value':101325,         'unit':'Pa'},
            'Preb'  :           {'name':'Reboiler Pressure',            'value':101325,         'unit':'Pa'},
            'RR'    :           {'name':'Reflux Ratio',                 'value':1.5,            'unit':''},
        } 
      
    def paramsetter(self,params):
        print("paramsetter ", params)
        self.variables['HKey']['value'] = params[0]
        self.variables['LKey']['value'] = params[1]
        self.variables['HKey_x_pc']['value'] = params[2]
        self.variables['LKey_x_pc']['value'] = params[3]
        self.variables['Ctype']['value'] = params[4]
        self.variables['Pcond']['value'] = params[5]
        self.variables['Preb']['value'] = params[6]
        self.variables['RR']['value'] = params[7]

        print(self.variables)


class DistillationColumn(UnitOperation):
    def __init__(self,name='DistillationColumn'):
        self.name = name + str(DistillationColumn.counter) 
        self.type = 'DistillationColumn'
        self.no_of_inputs = 2 
        self.no_of_outputs = 2

        self.compounds = compound_selected

        self.EngStm1 = EngStm(name='EngStm1'+self.name)
        self.EngStm2 = EngStm(name='EngStm2'+self.name)
        self.count = DistillationColumn.counter

        self.InputStms = None
        self.OutputStms = None 
        # self.modesList = ['RR', 'Nout', 'T']
        self.modesList = []
        self.parameters = ['']
        #self.parameters = ['Nt', 'InT_s', 'In_s', 'thermoPackage', 'Ctype', 'Pcond', 'Preb']
        self.Cspec_list = ['Reflux Ratio','Product Molar Flow   (mol/s)', 'Temperature  (K)', 'Compound Molar Fraction',    'Compound Molar Flow    (mol/s)']
        self.Rspec_list = ['Product Molar Flow   (mol/s)', 'Temperature  (K)', 'Compound Molar Fraction',    'Compound Molar Flow    (mol/s)']

        type(self).counter += 1  
        self.variables = {
            'RR'    :           {'name':'Reflux Ratio',             'value':None,           'unit':''},
            'T'     :           {'name':'Temperature',              'value':300,            'unit':'K'},
            'Nout'  :           {'name':'No of Sidedraws',          'value':None,           'unit':''},
            'Nt'    :           {'name':'No of Stages',             'value':12,             'unit':''},
            'InT_s' :           {'name':'No of Feed Stages',        'value':None,           'unit':''},
            'In_s'  :           {'name':'No of Feeds',              'value':None,           'unit':''},
            'thermoPackage' :   {'name':'Thermo Package',           'value':'Raoults_Law',  'unit':''},
            'Ctype' :           {'name':'Condensor Type',           'value':'',             'unit':''},
            'Pcond' :           {'name':'Condensor Pressure',       'value':101325,         'unit':'Pa'},
            'Preb'  :           {'name':'Reboiler Pressure',        'value':101325,         'unit':'Pa'},
            'C_Spec':           {'name':'Condensor Specification',  'type':'Reflux Ratio',  'value':'',         'comp':'',      'unit':''},
            'R_Spec':           {'name':'Reboiler Specification',   'type':'',              'value':'',         'comp':'',      'unit':''},
        }
    def paramsetter(self,params):
        print("paramsetter ", params)
        self.variables['Nt']['value'] = params[0]
        self.variables['In_s']['value'] = params[1]
        self.variables['InT_s']['value'] = params[2]
        self.variables['Ctype']['value'] = params[3]
        self.variables['Pcond']['value'] = params[4]
        self.variables['C_Spec']['type'] = params[5]
        if 'Compound' in self.variables['C_Spec']['type']:
            self.variables['C_Spec']['comp'] = params[6]
        self.variables['C_Spec']['value'] = params[7]
        self.variables['Preb']['value'] = params[8]
        self.variables['R_Spec']['type'] = params[9]
        if 'Compound' in self.variables['R_Spec']['type']:
            self.variables['R_Spec']['comp'] = params[10]
        self.variables['R_Spec']['value'] = params[11]   
        print(self.variables)
        
class ConvertionReactor(UnitOperation):
    def __init__(self,name='',Nr=None,b=None,X=None,Z=None,a=[],operation=None,Tdef=None):
        UnitOperation.__init__(self)
        self.name = name
        self.type = 'ConvertionReactor'

        self.Nr = str(Nr)
        self.b = str(b)
        self.X = str(X)
        self.Z = str(Z)
        self.a = json.dumps(a).replace('[','{').replace(']','}')
        self.operation = str(operation)   
        self.Tdef = str(Tdef)
           
class CompoundSeparator(UnitOperation):
    def __init__(self, name='CompoundSeparator'): 
        UnitOperation.__init__(self)
        self.name = name + str(CompoundSeparator.counter) 
        self.type = 'CompoundSeparator'
        self.no_of_inputs = 1 
        self.no_of_outputs = 2 

        self.SepFact_modes = ['Molar_Flow   (mol/s)', 'Mass_Flow    (kg/s)', 'Inlet_Molar_Flow_Percent', 'Outlet_Molar_Flow_Percent']

        type(self).counter += 1  
        self.variables = {
            'SepStrm'   : {'name':'Separation Stream',      'value':1,              'unit':''}, 
            #'SepVal'    : {'name':'Separation Value',       'value':[],             'unit':''},
            #'SepFact'   : {'name':'Separaction Factor',     'value':'',             'unit':''},
        }
        
        for i in self.compounds:
            self.variables[i] = {'name':'SepVal_'+i,      'value':'',       'type':'', 'unit':''}

        # self.SepFact = json.dumps(self.variables['SepFact']['value']).replace('[','{').replace(']','}')
        # self.SepStrm = str(self.variables['SepStrm']['value'])
        # self.SepVal = json.dumps(self.variables['SepVal']['value']).replace('[','{').replace(']','}')
    def paramsetter(self,params):
        print("paramsetter ", params)
        if params[0]:
            self.variables['SepStrm']['value'] = 1
        elif params[1]:
            self.variables['SepStrm']['value'] = 2
        
        j = 2
        for i in self.compounds:
            self.variables[i]['type'] = params[j]
            self.variables[i]['value'] = float(params[j+1])
            j += 2
        print(self.variables)

class Flash(UnitOperation):
    def __init__(self,name='Flash'):
        UnitOperation.__init__(self)
        self.name = name + str(Flash.counter) 
        self.type = 'Flash'
        self.no_of_inputs = 1 
        self.no_of_outputs = 2  
        self.InputStms = None
        self.OutputStms = None
        self.count = Flash.counter

        type(self).counter += 1 
        self.variables = {
            'thermoPackage' :   {'name':'Thermo Package',                   'value':None,       'unit':''},
            'BTdef' :           {'name':'Separation Temperature Boolean',   'value':False,      'unit':''},
            'BPdef' :           {'name':'Separation Pressure Boolean',      'value':False,      'unit':''},
            'Tdef'  :           {'name':'Separation Temperature',           'value':298.15,     'unit':'K'},
            'Pdef'  :           {'name':'Separation Pressure',              'value':101325,     'unit':'Pa'}
        }
    def paramsetter(self,params):
        print("paramsetter ", params)
        self.variables['thermoPackage']['value'] = params[0]
        self.variables['BTdef']['value'] = params[1]
        self.variables['Tdef']['value'] = params[2]
        self.variables['BPdef']['value'] = params[3]
        self.variables['Pdef']['value'] = params[4]        
        print(self.variables)

class Pump(UnitOperation):
    def __init__(self,name='Pump'):
        UnitOperation.__init__(self)
        self.name = name + str(Pump.counter) 
        self.type = 'Pump'
        self.InputStms = None
        self.OutputStms = None
        self.modesList = ['Pdel', 'Pout', 'Q']     #"enFlo"
        self.parameters = ['Eff']

        type(self).counter += 1 
        self.variables = {
            'Eff'   : {'name':'Efficiency',         'value':1,      'unit':''},
            'Pdel'  : {'name':'Pressure Increase',  'value':None,   'unit':'Pa'},
            'Pout'  : {'name':'Outlet Pressure',    'value':None,   'unit':'Pa'},
            'Q'     : {'name':'Power Required',     'value':None,   'unit':'W'},
        }

class Valve(UnitOperation):
    def __init__(self,name='Valve'):
        UnitOperation.__init__(self)
        self.name = name + str(Valve.counter)
        self.type = 'Valve'
        self.InputStms = None
        self.OutputStms = None
        self.modesList = ['Pdel', 'Pout']

        type(self).counter += 1 
        self.variables = {
            'Pdel'  : {'name':'Pressure Drop',      'value':None,   'unit':'Pa'},
            'Pout'  : {'name':'Outlet Pressure',    'value':None,   'unit':'Pa'}
        }

class Splitter(UnitOperation):
    def __init__(self,name='Splitter'):
        UnitOperation.__init__(self)
        self.name = name + str(Splitter.counter) 
        self.type = 'Splitter'
        self.no_of_outputs = 3 
        
        # self.InputStms = None
        self.CalcType_modes = ['Split Ratios', 'Mole Flow Specs', 'Mass Flow Specs']

        self.parameters = ['NOO', 'CalcType']#, 'SpecVal_s'
        type(self).counter += 1 

        self.variables = {
            'NOO'       : {'name':'No. of Output',          'value':3,                          'unit':''},
            'CalcType'  : {'name':'Calculation Type',       'value':self.CalcType_modes[0],     'unit':''},
            'SpecVal_s' : {'name':'Specification Value',    'value':[50,50],                    'unit':''}
        }
        
        specval = self.variables['SpecVal_s']['value'] # [50,50]
        self.specval = json.dumps(specval).replace('[','{').replace(']','}')

    def paramsetter(self,params):
        print("paramsetter ", params)
        self.variables['NOO']['value'] = int(params[0])
        self.variables['CalcType']['value'] = params[1]
        self.variables['SpecVal_s']['value'] = [float(params[2]), float(params[3])]
        if self.variables['CalcType']['value'] == 'Mole Flow Specs':
            self.variables['SpecVal_s']['unit'] = 'mol/s'
        elif self.variables['CalcType']['value'] == 'Mass Flow Specs':
            self.variables['SpecVal_s']['unit'] = 'kg/s'
        print(self.variables)

class Mixer(UnitOperation):

    def __init__(self,name='Mixer'):
        UnitOperation.__init__(self)
        self.name = name + str(Mixer.counter) 
        self.type = 'Mixer'
        self.no_of_inputs = 6

        self.Pout_modes = ['Inlet Minimum', 'Inlet Average', 'Inlet Maximum']
        self.parameters = ['NOI', 'Pout']
        # self.OutputStms = None
        type(self).counter += 1 

        self.variables = {
            'NOI'   : {'name':'Number of Input', 'value':6,                 'unit':''},
            'Pout'  : {'name':'Outlet Pressure', 'value':'Inlet_Average',   'unit':''},
        }
    def paramsetter(self, params):
        print(self.InputStms, self.OutputStms)
        self.OutputStms = []
        print(self.InputStms, self.OutputStms)
        print("paramsetter ", params)
        self.variables['NOI']['value'] = int(params[0])
        self.variables['Pout']['value'] = params[1]
        print(self.variables)
        

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
            'xvapout':  {'name':'Outlet Vapour',        'value':None,    'unit':''}
        }

class Cooler(UnitOperation):

    def __init__(self, name='Cooler'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'Cooler'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.modesList = ['Q','Tout','Tdel','xvap']
        self.extra = None
        self.ForNaming = None
        self.parameters = ['Pdel', 'Eff']
        type(self).counter += 1

        self.variables = {
            'Pdel'  : {'name':'Pressure Drop',              'value':0,          'unit':'Pa'},
            'Eff'   : {'name':'Efficiency',                 'value':1,          'unit':''},
            'Tout'  : {'name':'Outlet Temperature',         'value':298.15,     'unit':'K'},
            'Tdel'  : {'name':'Temperature Increase',       'value':0,          'unit':'K'},
            'Q'     : {'name':'Heat Added',                 'value':0,          'unit':'W'},
            'xvap'  : {'name':'Vapour Phase Mole Fraction', 'value':None,       'unit':'g/s'},
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
            'Pout'  : {'name':'Outlet Pressure',        'value':101325,  'unit':'Pa'},
            'Tout'  : {'name':'Outlet Temperature',     'value':298.15,  'unit':'K'},
            'Q'     : {'name':'Heat Added',             'value':0,       'unit':'W'},
            'Eff'   : {'name':'Efficiency',             'value':1,       'unit':''}
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
            'Eff'   : {'name':'Efficiency',             'value':1,       'unit':''}
        }

        