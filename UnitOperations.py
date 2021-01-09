from OMChem.Flowsheet import Flowsheet
from OMChem.EngStm import EngStm
from ComponentSelector import *
from Container import *
from PyQt5.QtCore import *

class UnitOperation():
    counter = 1
    def __init__(self):
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.input_stms = {}
        self.output_stms = {}
        self.compounds = [c[:c.index('(')] for c in compound_selected]
        self.name = ''
        self.mode = None
        self.mode_val = None
        self.type = ''
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30 
        self.y = 2500-30
        self.pos = QPointF(self.x, self.y)
        self.count = UnitOperation.counter
        self.variables = {}
        self.modes_list = []
        self.parameters = []
        self.extra = []
        self.for_naming = []
        self.multidict = []
        self.thermo_pack_req = False
        self.thermo_package = 'RaoultsLaw'
        self.saved = False

    def param_getter(self,mode=None):
        params = {}
        if mode == None and self.modes_list:
            self.mode = self.modes_list[0]
        else:
            self.mode = mode
            params[self.mode] = None
        for i in self.parameters:
            params[i] = self.variables[i]['value']
        
        return params
        
    def param_setter(self,params):
        print("param_setter ", params)
        try:
            self.mode = list(params.keys())[0]
        except Exception as e:
            print(e)
        for k,v in params.items():
            if k == 'Thermo Package':
                self.thermo_package = v
            elif k != self.mode:
                self.k = v
                self.variables[k]['value'] = v
            else:
                self.variables[k]['value'] = v
                self.mode_val = params[self.mode]


    def add_connection(self,flag,sourceId, UnitOpr):
        if flag==1:                 # Input stream if flag is 1
            self.input_stms[sourceId] = UnitOpr
        else :
            self.output_stms[sourceId] = UnitOpr

    def set_pos(self,pos):
        self.pos = pos

    def OM_Flowsheet_Initialize(self):
        self.OM_data_init = ''

        if(self.thermo_pack_req):
            if len(self.extra)>1:
                for i in range(len(self.extra)):
                    latest = ''
                    for j in range(self.extra[i]):
                        if self.extra[i][j]!='.':
                            latest += self.extra[i][j]
                        self.for_naming[i] = latest   

        if(self.thermo_pack_req):
            if len(self.extra)==1:
                for i in self.extra:
                    self.OM_data_init += ('model '+i+str(self.counter)+'\n')
                    self.OM_data_init += ('extends Simulator.UnitOperations.'+i+';\n')
                    self.OM_data_init += ('extends Simulator.Files.ThermodynamicPackages.'+self.thermo_package+';\n')
                    self.OM_data_init += ('end '+i+str(self.counter)+';\n')

                    self.OM_data_init += i+str(self.counter) + ' ' + self.name + '(Nc = ' + str(len(self.compounds)) 
            else:
                for i in range(len(self.extra)):
                    if i!=(len(self.extra)-1):
                        self.OM_data_init += ('model '+self.for_naming[i]+str(self.counter)+'\n')
                        self.OM_data_init += ('extends Simulator.UnitOperations.'+self.extra[i]+';\n')
                        self.OM_data_init += ('extends Simulator.Files.ThermodynamicPackages.'+self.thermo_package+';\n')
                        self.OM_data_init += ('end '+self.for_naming[i]+str(self.counter)+';\n')
                    else:
                        self.OM_data_init += ('model '+self.for_naming[i]+str(self.counter)+'\n')
                        self.OM_data_init += ('extends Simulator.UnitOperations.'+self.extra[i]+';\n')
                        for j in range(len(self.extra)-1):
                            self.OM_data_init += (self.for_naming[j] + str(self.counter) +' ' + self.for_naming[j] + '#' + self.multidict[j] + ';\n')

                            self.OM_data_init += ('end '+self.for_naming[i]+str(self.counter)+';\n')

                    self.OM_data_init += self.for_naming[i] + str(self.counter) + ' ' + self.for_naming + '(Nc = ' + str(len(self.compounds))
                 
            C = str(self.compounds).strip('[').strip(']')
            C = C.replace("'", "")  
            self.OM_data_init += ',C = {' + C + '}'  

            for k in self.parameters:
                if(k == 'HKey_x_pc' or k == 'LKey_x_pc'):
                    continue
                self.OM_data_init += ', '
                self.OM_data_init += k + ' = ' + (json.dumps(self.variables[k]['value']) if json.dumps(self.variables[k]['value']).replace('"', '').replace('_', '').isalpha()
                                                   else json.dumps(self.variables[k]['value']).replace('[', '{').replace(']', '}').replace('"', ''))

            self.OM_data_init += ');\n'

        else: 
            self.OM_data_init += 'Simulator.UnitOperations.' + self.type + ' ' + self.name + '(Nc = ' + str(len(self.compounds))
            C = str(self.compounds).strip('[').strip(']')
            C = C.replace("'", "")  
            self.OM_data_init += ',C = {' + C + '}'

            for k in self.parameters:
                self.OM_data_init += ', '
                self.OM_data_init += k + ' = ' + (json.dumps(self.variables[k]['value']) if json.dumps(self.variables[k]['value']).replace('"', '').replace('_', '').isalpha()
                                                   else json.dumps(self.variables[k]['value']).replace('[', '{').replace(']', '}').replace('"', ''))

            self.OM_data_init += ');\n'
        return self.OM_data_init  

    
    def OM_Flowsheet_Equation(self):
        self.OM_data_eqn = ''

        if len(self.input_stms)>1 or self.type == 'Mixer':
            strcount = 1
            for strm in self.input_stms:
                self.OM_data_eqn += ('connect(' + strm.name + '.Out,' + self.name + '.In[' + str(strcount) + ']);\n')
                strcount += 1
        else:
            self.OM_data_eqn += ('connect(' + self.name + '.In,' + self.input_stms[0].name + '.Out);\n')

        if len(self.output_stms)>1:
            strcount = 1
            for strm in self.output_stms:
                self.OM_data_eqn += ('connect(' + strm.name + '.In,' + self.name + '.Out[' + str(strcount) + ']);\n')
                strcount += 1
        else:
            print("self.output_stms ", self.output_stms)
            self.OM_data_eqn += ('connect(' + self.name + '.Out,' + self.output_stms[0].name + '.In);\n')    
        
        if self.mode:
            self.OM_data_eqn += (self.name + '.' + self.mode + '=' + str(self.mode_val) + ';\n')

        return self.OM_data_eqn

class ShortcutColumn(UnitOperation):
    def __init__(self, CompNames = [], name='ShortcutColumn'):
        UnitOperation.__init__(self)
        self.name = name + str(ShortcutColumn.counter) 
        self.type = 'ShortcutColumn'
        self.no_of_inputs = 1 
        self.no_of_outputs = 2  
        self.EngStm1 = EngStm(name='EngStm1'+self.name)
        self.EngStm2 = EngStm(name='EngStm2'+self.name)
        self.count = ShortcutColumn.counter

        self.extra = ['ShortcutColumn']
        self.for_naming = ['ShortcutColumn']
        self.thermo_pack_req = True

        self.parameters = ['HKey', 'LKey', 'HKey_x_pc', 'LKey_x_pc', 'Ctype', 'Pcond', 'Preb', 'RR']
        self.result_parameters = ['RRmin', 'Ntmin', 'Nt', 'Intray', 'Fliqstrip', 'Fliqrec', 'Fvapstrip', 'Fvaprec', 'Qc', 'Qr']
        type(self).counter += 1

        self.variables = {
            'HKey'  :           {'name':'Heavy Key',                    'value':None,           'unit':''},
            'LKey'  :           {'name':'Light Key',                    'value':None,           'unit':''},
            'HKey_x_pc' :       {'name':'Heavy Key Mole Fraction',      'value':0.01,           'unit':''},
            'LKey_x_pc' :       {'name':'Light Key Mole Fraction',      'value':0.01,           'unit':''},
            'Ctype' :           {'name':'Condenser Type',               'value':None,           'unit':''},
            'thermo_package' :  {'name':'Thermo Package',               'value':'Raoults_Law',  'unit':''},
            'Pcond' :           {'name':'Condenser Pressure',           'value':101325,         'unit':'Pa'},
            'Preb'  :           {'name':'Reboiler Pressure',            'value':101325,         'unit':'Pa'},
            'RR'    :           {'name':'Reflux Ratio',                 'value':1.5,            'unit':''},
            
            'RRmin' :           {'name':'Minimum Reflux Ratio',         'value': None ,     'unit':''},
            'Ntmin' :           {'name':'Minimum Number of Stages',     'value': None,      'unit':''},
            'Nt'    :           {'name':'Actual Number of Stages',      'value': None,      'unit':''},
            'Intray'   :        {'name':'Optimal Feed Stage',           'value': None,      'unit':''},
            'Fliqstrip' :       {'name':'Stripping Liquid',             'value': None,      'unit':'mol/s'},
            'Fliqrec'   :       {'name':'Rectification Liquid',         'value': None,      'unit':'mol/s'},
            'Fvapstrip' :       {'name':'Stripping Vapor',              'value': None,      'unit':'mol/s'},
            'Fvaprec'   :       {'name':'Recification Vapour',          'value': None,      'unit':'mol/s'},
            'Qc'    :           {'name':'Conderser Duty',               'value': None,      'unit':'W'},
            'Qr'    :           {'name':'Reboiler Duty',                'value': None,      'unit':'W'},

        } 
      
    def param_setter(self,params):
        print("param_setter ", params)
        self.variables['HKey']['value'] = self.compounds.index(params[0]) + 1
        self.variables['LKey']['value'] = self.compounds.index(params[1]) + 1
        self.variables['HKey_x_pc']['value'] = params[2]
        self.variables['LKey_x_pc']['value'] = params[3]
        self.variables['Ctype']['value'] = params[4]
        self.variables['Pcond']['value'] = params[5]
        self.variables['Preb']['value'] = params[6]
        self.variables['RR']['value'] = params[7]
        self.thermo_package = params[8]

    def OM_Flowsheet_Equation(self):
        self.OM_data_eqn = ''
       
        self.OM_data_eqn += ('connect(' + self.name + '.In,' + self.input_stms[0].name + '.Out);\n')

        strcount = 1
        for strm in self.output_stms:
            self.OM_data_eqn += ('connect(' + strm.name + '.In,' + self.name + '.Out' + str(strcount) + ');\n')
            strcount += 1

        self.OM_data_eqn += (self.name + '.x_pc[2, ' + self.name + '.HKey] = ' + str(self.variables['HKey_x_pc']['value'])  + ';\n')
        self.OM_data_eqn += (self.name + '.x_pc[3, ' + self.name + '.LKey] = ' + str(self.variables['LKey_x_pc']['value'])  + ';\n')
        
        return self.OM_data_eqn

class DistillationColumn(UnitOperation):
    def __init__(self,name='DistillationColumn'):
        UnitOperation.__init__(self)
        self.name = name + str(DistillationColumn.counter) 
        self.type = 'DistillationColumn'
        self.no_of_inputs = 1 
        self.no_of_outputs = 2
        self.EngStm1 = EngStm(name='EngStm1'+self.name)
        self.EngStm2 = EngStm(name='EngStm2'+self.name)
        self.count = DistillationColumn.counter
        self.thermo_pack_req = True
        # self.modes_list = ['RR', 'Nout', 'T']
        self.modes_list = []
        self.parameters = ['Nt', 'Ni', 'Ctype', 'Pcond', 'condmode', 'C_comp', 'C_Spec', 'Preb', 'rebmode', 'rebcomp', 'R_Spec']
        #self.parameters = ['Nt', 'InT_s', 'In_s', 'thermo_package', 'Ctype', 'Pcond', 'Preb']
        self.Cspec_list = ['Reflux Ratio','Product Molar Flow   (mol/s)', 'Temperature  (K)', 'Compound Molar Fraction',    'Compound Molar Flow    (mol/s)']
        self.Rspec_list = ['Product Molar Flow   (mol/s)', 'Temperature  (K)', 'Compound Molar Fraction',    'Compound Molar Flow    (mol/s)']

        type(self).counter += 1  
        self.variables = {
            'Ni'   :            {'name':'Number of Input',          'value':1,              'unit':''},
            'RR'    :           {'name':'Reflux Ratio',             'value':None,           'unit':''},
            'T'     :           {'name':'Temperature',              'value':300,            'unit':'K'},
            'Nout'  :           {'name':'No of Sidedraws',          'value':None,           'unit':''},
            'Nt'    :           {'name':'No of Stages',             'value':12,             'unit':''},
            'InT_s' :           {'name':'Feed Stage',              'value':[],           'unit':''},
            'thermo_package' :   {'name':'Thermo Package',           'value':'Raoults_Law',  'unit':''},
            'Ctype' :           {'name':'Condenser Type',           'value':'Total',             'unit':''},
            'Pcond' :           {'name':'Condenser Pressure',       'value':101325,         'unit':'Pa'},
            'Preb'  :           {'name':'Reboiler Pressure',        'value':101325,         'unit':'Pa'},
            'C_Spec':           {'name':'Condenser Specification',  'type':self.Cspec_list[0],  'value':'',         'comp':compound_selected[0],      'unit':''},
            'R_Spec':           {'name':'Reboiler Specification',   'type':self.Rspec_list[0],       'value':'',         'comp':compound_selected[0],      'unit':''},
        }
       
    def param_setter(self,params):
        print("param_setter ", params)
        temp = 0
        self.variables['Nt']['value'] = params[0]
        for i in range(self.variables['Ni']['value']):
            self.variables['InT_s']['value'].append(params[i+1])
            temp = i + 1
        
        self.variables['Ctype']['value'] = params[temp+1]
        self.variables['Pcond']['value'] = params[temp+2]
        self.variables['C_Spec']['type'] = params[temp+3]
        if 'Compound' in self.variables['C_Spec']['type']:
            self.variables['C_Spec']['comp'] = params[temp+4]
        # C_Spec variable value won't be updated to class here. It will be updated in result
        self.variables['C_Spec']['value'] = params[temp+5]
        for var in self.variables:
            if self.variables[var]['name'] == self.variables['C_Spec']['type']:
                self.variables[var]['value'] = params[temp+5]

        self.variables['Preb']['value'] = params[temp+6]
        # R_Spec variable value won't be updated to class here. It will be updated in result
        self.variables['R_Spec']['type'] = params[temp+7]
        if 'Compound' in self.variables['R_Spec']['type']:
            self.variables['R_Spec']['comp'] = params[temp+8]
        self.variables['R_Spec']['value'] = params[temp+9]   
        print(self.variables)

    def OM_Flowsheet_Initialize(self):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + 'model Condenser\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.UnitOperations.DistillationColumn.Cond;\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.Files.ThermodynamicPackages.' + self.thermo_package + ';\n'
        self.OM_data_init = self.OM_data_init + 'end Condenser;\n'
        self.OM_data_init = self.OM_data_init + 'model Tray\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.UnitOperations.DistillationColumn.DistTray;\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.Files.ThermodynamicPackages.' + self.thermo_package + ';\n'
        self.OM_data_init = self.OM_data_init + 'end Tray;\n'
        self.OM_data_init = self.OM_data_init + 'model Reboiler\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.UnitOperations.DistillationColumn.Reb;\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.Files.ThermodynamicPackages.' + self.thermo_package + ';\n'
        self.OM_data_init = self.OM_data_init + 'end Reboiler;\n'
        self.OM_data_init = self.OM_data_init + ("model distCol" + str(self.count) + "\n")
        self.OM_data_init = self.OM_data_init + ("extends Simulator.UnitOperations.DistillationColumn.DistCol;\n")
        self.OM_data_init = self.OM_data_init + (
             "Condenser condenser(Nc = Nc, C = C, Ctype =Ctype, Bin = Bin_t[1], T(start = 300));\n")
        self.OM_data_init = self.OM_data_init + (
            "Reboiler reboiler(Nc = Nc, C = C, Bin = Bin_t[Nt]);\n")
        self.OM_data_init = self.OM_data_init + (
             "Tray tray[Nt - 2](each Nc = Nc, each C = C, Bin = Bin_t[2:Nt - 1]);\n")
        self.OM_data_init = self.OM_data_init + ("end distCol" + str(self.count) + ";\n")
        comp_count = len(self.compounds)
        self.OM_data_init = self.OM_data_init + (
                "distCol" + str(self.count) + " " + self.name + "(Nc = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (", C= C")

        self.OM_data_init = self.OM_data_init + "," + (
                    "Nt=" + str(self.variables['Nt']['value']) + "," + "Ni="
                    + str(self.variables['Ni']['value']) + ",InT_s=" + "{" +
                    str(self.variables['InT_s']['value']).strip('[').strip(']') + "}" + ',Ctype ="' +
                    self.variables['Ctype']['value'] + '");\n')
        # self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStm1.name+';\n'
        # self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStm2.name+';\n'
        return self.OM_data_init

    def OM_Flowsheet_Equation(self):
        self.OM_data_eqn = ''
        # self.OM_data_eqn = self.name + '.pressDrop = ' + str(self.PressDrop) + ';\n'
        # self.OM_data_eqn = self.OM_data_eqn + (
        #             'connect(' + self.name + '.' + 'condensor_duty' + ',' + self.EngStm1.name + '.inlet);\n')
           # self.OM_data_eqn = self.OM_data_eqn + (
           #             'connect(' + self.name + '.reboiler_duty' + ', ' + self.EngStm2.name + '.inlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + (
                'connect(' + self.name + '.Dist' + ", " + self.output_stms[0].name + '.In);\n')
        self.OM_data_eqn = self.OM_data_eqn + (
                'connect(' + self.name + '.Bot' + ", " + self.output_stms[1].name + '.In);\n')
        for i in range(len(self.input_stms)):
            self.OM_data_eqn = self.OM_data_eqn + (
                    'connect(' + self.input_stms[i].name + '.Out' + ", " + self.name + '.In_s[' + str(
                i + 1) + ']);\n')
        # ['Product Molar Flow   (mol/s)', 'Temperature  (K)', 'Compound Molar Fraction',
        #  'Compound Molar Flow    (mol/s)']
        if self.variables['C_Spec']['type'] == "Reflux Ratio":
            self.OM_data_eqn = self.OM_data_eqn + (
                        self.name + '.' + 'RR' + '=' + str(self.variables['RR']['value']) + ';\n')
        elif self.variables['C_Spec']['type'] == "Product Molar Flow   (mol/s)":
            self.OM_data_eqn = self.OM_data_eqn + (self.output_stms[0].name + '.' + 'F_p[1] = ' + str(
                self.variables['C_Spec']['value']) + ';\n')
        elif self.variables['C_Spec']['type'] == "Temperature  (K)":
            self.OM_data_eqn = self.OM_data_eqn + (self.output_stms[0].name + '.' + 'T = ' + str(
                self.variables['C_Spec']['value']) + ';\n')
        elif self.variables['C_Spec']['type'] == "Compound Molar Fraction":
            self.OM_data_eqn = self.OM_data_eqn + (self.output_stms[0].name + '.x_pc[1,:' +
                               str(self.compounds.index(self.variables['C_Spec']['comp']) + 1) + '] = ' + str(
                               self.variables['C_Spec']['value']) + ';\n')
        elif self.variables['C_Spec']['type'] == "Compound Molar Flow    (mol/s)":
            self.OM_data_eqn = self.OM_data_eqn + (self.output_stms[0].name + '.F_pc[1,:' +
                               str(self.compounds.index(self.variables['C_Spec']['comp']) + 1) + '] = ' + str(
                               self.variables['C_Spec']['value']) + ';\n')
        else:
            self.OM_data_eqn = self.OM_data_eqn + (
                    self.name + '.Condenser.' + self.mode + '=' + str(self.modeVal) + ';\n')

        if self.variables['R_Spec']['type'] == "Product Molar Flow   (mol/s)":
            self.OM_data_eqn = self.OM_data_eqn + (self.output_stms[1].name + '.' + 'F_p[1] = ' + str(
                               self.variables['R_Spec']['value']) + ';\n')
        elif self.variables['R_Spec']['type'] == "Temperature  (K)":
            self.OM_data_eqn = self.OM_data_eqn + (self.output_stms[1].name + '.' + 'T = ' + str(
                               self.variables['R_Spec']['value']) + ';\n')
        elif self.variables['R_Spec']['type'] == "Compound Molar Fraction":
            self.OM_data_eqn = self.OM_data_eqn + (self.output_stms[1].name + '.x_pc[1,:' +
                               str(self.compounds.index(self.variables['R_Spec']['comp']) + 1) + '] = ' + str(
                               self.variables['R_Spec']['value']) + ';\n')
        elif self.variables['R_Spec']['type'] == "Compound Molar Flow    (mol/s)":
            self.OM_data_eqn = self.OM_data_eqn + (self.output_stms[1].name + '.F_pc[1,:' +
                               str(self.compounds.index(self.variables['R_Spec']['comp']) + 1) + '] = ' + str(
                               self.variables['R_Spec']['value']) + ';\n')


        self.OM_data_eqn = self.OM_data_eqn + self.name + '.reboiler.P=' + str(
            self.variables['Preb']['value']) + ';\n'
        self.OM_data_eqn = self.OM_data_eqn + self.name + '.condenser.P=' + str(
            self.variables['Pcond']['value']) + ';\n'
        return self.OM_data_eqn
        
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

        self.SepFact_modes = ['Molar_Flow   (mol/s)', 'Mass_Flow    (g/s)', 'Inlet_Molar_Flow_Percent', 'Outlet_Molar_Flow_Percent']

        type(self).counter += 1  
        self.variables = {
            'SepStrm'   : {'name':'Separation Stream',      'value':1,              'unit':''}, 
            'SepVal_c'    : {'name':'Separation Value',       'value':[],             'unit':''},
            'SepFact_c'   : {'name':'Separaction Factor',     'value':[],             'unit':''},
        }

    def param_setter(self,params):
        print("param_setter CompSep ", params)
      
        if (params[0]):
            self.variables['SepStrm']['value'] = 1
        else:
            self.variables['SepStrm']['value'] = 2
        for index, i in enumerate(range(2, len(params))):
            if (i %2 != 0):
                self.variables['SepVal_c']['value'].append(float(params[i]))   
            else:
                self.variables['SepFact_c']['value'].append(params[i].split(' ')[0])    
        
        self.variables['SepFact_c']['value'] = json.dumps(self.variables['SepFact_c']['value']).replace('[','{').replace(']','}')
        self.variables['SepStrm']['value'] = str(self.variables['SepStrm']['value'])
        self.variables['SepVal_c']['value'] = json.dumps(self.variables['SepVal_c']['value']).replace('[','{').replace(']','}')


    def OM_Flowsheet_Initialize(self):
        self.OM_data_init = ''
        comp_count = len(self.compounds)
        self.OM_data_init = self.OM_data_init + (
        "Simulator.UnitOperations.CompoundSeparator " + self.name + "(Nc = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (", C = {")
        comp = str(self.compounds).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("},")
        self.OM_data_init = self.OM_data_init + ("SepFact_c = "+self.variables['SepFact_c']['value']+",SepStrm = " + self.variables['SepStrm']['value']  + ");\n") #+ ", sepFactVal = " + self.variables['SepVal_c']['value']

        return self.OM_data_init


    def OM_Flowsheet_Equation(self):
        self.OM_data_eqn = ''
       
        self.OM_data_eqn += ('connect(' + self.name + '.In,' + self.input_stms[0].name + '.Out);\n')

        strcount = 1
        for strm in self.output_stms:
            self.OM_data_eqn += ('connect(' + strm.name + '.In,' + self.name + '.Out' + str(strcount) + ');\n')
            strcount += 1
        
        self.OM_data_eqn += (self.name + '.SepVal_c ' + '=' + self.variables['SepVal_c']['value'] + ';\n')    

        return self.OM_data_eqn

class Flash(UnitOperation):
    def __init__(self,name='Flash'):
        UnitOperation.__init__(self)
        self.name = name + str(Flash.counter) 
        self.type = 'Flash'
        self.extra = ['Flash']
        self.for_naming = ['Flash']
        self.no_of_inputs = 1 
        self.no_of_outputs = 2  
        self.input_stms = []
        self.output_stms = []
        self.count = Flash.counter
        self.thermo_pack_req = True
        self.parameters = ['BTdef', 'Tdef', 'BPdef', 'Pdef']

        type(self).counter += 1 
        self.variables = {
            'thermo_package' :   {'name':'Thermo Package',                   'value':None,       'unit':''},
            'BTdef' :           {'name':'Separation Temperature Boolean',   'value':False,      'unit':''},
            'BPdef' :           {'name':'Separation Pressure Boolean',      'value':False,      'unit':''},
            'Tdef'  :           {'name':'Separation Temperature',           'value':298.15,     'unit':'K'},
            'Pdef'  :           {'name':'Separation Pressure',              'value':101325,     'unit':'Pa'}
        }

    def param_setter(self,params):
        print("param_setter ", params)
        self.variables['thermo_package']['value'] = params[0]
        self.variables['BTdef']['value'] = params[1]
        self.variables['Tdef']['value'] = params[2]
        self.variables['BPdef']['value'] = params[3]
        self.variables['Pdef']['value'] = params[4]        

    def OM_Flowsheet_Equation(self):
        self.OM_data_eqn = ''

        self.OM_data_eqn += ('connect(' + self.name + '.In,' + self.input_stms[0].name + '.Out);\n')

        strcount = 1
        for strm in self.output_stms:
            self.OM_data_eqn += ('connect(' + strm.name + '.In,' + self.name + '.Out' + str(strcount) + ');\n')
            strcount += 1

        return self.OM_data_eqn

class Pump(UnitOperation):
    def __init__(self,name='Pump'):
        UnitOperation.__init__(self)
        self.name = name + str(Pump.counter) 
        self.type = 'Pump'
        self.input_stms = None
        self.output_stms = None
        self.modes_list = ['Pdel', 'Pout', 'Q']     #"enFlo"
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
        self.modes_list = ['Pdel', 'Pout']

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
        self.no_of_outputs = 2
        
        self.CalcType_modes = ['Split_Ratio', 'Molar_Flow', 'Mass_Flow']

        self.parameters = ['No', 'CalcType', 'SpecVal_s']
        type(self).counter += 1 

        self.variables = {
            'No'       : {'name':'No. of Output',          'value':3,                          'unit':''},
            'CalcType'  : {'name':'Calculation Type',       'value':self.CalcType_modes[0],     'unit':''},
            'SpecVal_s' : {'name':'Specification Value',    'value':[0.5,0.5],                    'unit':''}
        }
        
        specval = self.variables['SpecVal_s']['value'] 
        self.specval = json.dumps(specval).replace('[','{').replace(']','}')

    def param_setter(self,params):
        print("param_setter ", params)
        self.variables['No']['value'] = int(params[0])
        self.variables['CalcType']['value'] = params[1]
        self.variables['SpecVal_s']['value'] = [float(params[2]), float(params[3])]
        if self.variables['CalcType']['value'] == 'Molar_Flow':
            self.variables['SpecVal_s']['unit'] = 'mol/s'
        elif self.variables['CalcType']['value'] == 'Mass_Flow':
            self.variables['SpecVal_s']['unit'] = 'g/s'
        else:
            self.variables['SpecVal_s']['unit'] = ''

class Mixer(UnitOperation):

    def __init__(self,name='Mixer'):
        UnitOperation.__init__(self)
        self.name = name + str(Mixer.counter) 
        self.type = 'Mixer'
        self.no_of_inputs = 6

        self.Pout_modes = ['Inlet_Minimum', 'Inlet_Average', 'Inlet_Maximum']
        self.parameters = ['NI', 'outPress']
        type(self).counter += 1 

        self.variables = {
            'NI'        : {'name':'Number of Input', 'value':6,                 'unit':''},
            'outPress'  : {'name':'Outlet Pressure', 'value':'Inlet_Average',   'unit':''},
        }
        
    def param_setter(self, params):
        self.variables['NI']['value'] = int(params[0])
        self.variables['outPress']['value'] = params[1]
        
class Heater(UnitOperation):

    def __init__(self, name='Heater'):
        UnitOperation.__init__(self)
        self.name = name + str(type(self).counter)
        self.type = 'Heater'
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.modes_list = ['Q','Tout','xvapout','Tdel']
        self.parameters = ['Pdel', 'Eff'] 
        self.extra = None
        self.for_naming = None
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
        self.modes_list = ['Q','Tout','Tdel','xvap']
        self.extra = None
        self.for_naming = None
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
        self.modes_list = ["Pdel","Pout","Q"]
        self.extra = ['AdiabaticCompressor']
        self.for_naming = ['AdiabaticCompressor']
        self.thermo_pack_req = True
        self.thermo_package ="RaoultsLaw" 
        self.parameters = ['Eff']
        type(self).counter += 1
        self.variables = {
            'Pdel'  : {'name':'Pressure Increase',          'value':0,       'unit':'Pa'},
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
        self.modes_list = ["Pdel","Pout","Q"]
        self.extra = ['AdiabaticExpander']
        self.for_naming = ['AdiabaticExpander']
        self.thermo_pack_req = True
        self.thermo_package ="RaoultsLaw"
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

        