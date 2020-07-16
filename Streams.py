# from OMPython import OMCSession
from PyQt5.QtCore import *
import json
import sys
from collections import defaultdict

class MaterialStream():
    counter = 1
    def __init__(self, compound_names = []):

        self.name = 'MaterialStream' + str(MaterialStream.counter)
        self.type = 'MaterialStream'

        self.compound_names = compound_names
        self.count = MaterialStream.counter
        self.thermo_package ="RaoultsLaw"
        self.mode1 = "P"
        self.mode2 = "T"

        self.mode1_val = ""
        self.mode2_val = ""
        self.OM_data_init = ''
        self.OM_data_eqn = ''
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30
        self.y = 2500-30
        self.pos = QPointF(self.x, self.y)
        MaterialStream.counter+=1
        self.start_dict = {}
        self.eqn_dict = {}
        self.modes_list = ["PT","PH","PVF","TVF","PS"]
        
        self.variables = {
            'P'     : {'name':'Pressure',         'value':101325,    'unit':'Pa'},          # {'Pa':1, 'mmHg':0, 'N/m^2':0}},
            'T'     : {'name':'Temperature',      'value':300,       'unit':'K'},

            'xvap'   : {'name':'Vapour Phase Mole Fraction',          'value':None,       'unit':'g/s'},
            'H_p[1]'  : {'name':'Mixture Phase Molar Entalpy',        'value':None,       'unit':'g/s'},
            'S_p[1]'  : {'name':'Mixture Phase Molar Entropy',        'value':None,       'unit':'g/s'},
            'F_p[1]'  : {'name':'Mixture Molar Flow Rate',            'value':100,       'unit':'g/s'},

            'H_p[2]'  : {'name':'Liquid Phase Molar Entalpy',        'value':None,       'unit':'g/s'},
            'S_p[2]'  : {'name':'Liquid Phase Molar Entropy',        'value':None,       'unit':'g/s'},
            'F_p[2]'  : {'name':'Liquid Molar Flow Rate',            'value':None,       'unit':'g/s'},

            'H_p[3]'  : {'name':'Vapour Phase Molar Entalpy',        'value':None,       'unit':'g/s'},
            'S_p[3]'  : {'name':'Vapour Phase Molar Entropy',        'value':None,       'unit':'g/s'},
            'F_p[3]'  : {'name':'Vapour Molar Flow Rate',            'value':None,       'unit':'g/s'},

            'x_pc'  : {'name':'Mole Fraction',    'value':[],      'unit':'mol/s'},
            'xm_pc' : {'name':'Mass Fraction',    'value':None,     'unit':'g/s'},
            
            'F_pc'  : {'name':'Mole Flow',        'value':100,      'unit':'mol/s'},
            'Fm_pc' : {'name':'Mass Flow',        'value':None,     'unit':'g/s'},
        }
        self.init_variables()

    def init_variables(self):
        Nc = len(self.compound_names)
        for i, val in enumerate(self.compound_names):
            self.variables['x_pc[1,'+ str(i+1)+']'] = {'name':val + ' Mixture Mole Fraction', 'value':round(1/Nc,4), 'unit':'mol/s'}
            self.variables['xm_pc[1,'+ str(i+1)+']'] = {'name':val + ' Mixture Mass Fraction', 'value':None, 'unit':'g/s'}
            self.variables['F_pc[1,'+ str(i+1)+']'] = {'name':val + ' Mixture Mole Flow', 'value':None, 'unit':'mol/s'}
            self.variables['Fm_pc[1,'+ str(i+1)+']'] = {'name':val + ' Mixture Mass Flow', 'value':None, 'unit':'g/s'}

            self.variables['x_pc[2,'+ str(i+1)+']'] = {'name':[val + ' Liquid Mole Fraction'], 'value':None, 'unit':'mol/s'}
            self.variables['xm_pc[2,'+ str(i+1)+']'] = {'name':[val + ' Liquid Mass Fraction'], 'value':None, 'unit':'g/s'}
            self.variables['F_pc[2,'+ str(i+1)+']'] = {'name':[val + ' Liquid Mole Flow'], 'value':None, 'unit':'mol/s'}
            self.variables['Fm_pc[2,'+ str(i+1)+']'] = {'name':[val + ' Liquid Mass Flow'], 'value':None, 'unit':'g/s'}

            self.variables['x_pc[3,'+ str(i+1)+']'] = {'name':[val + ' Vapour Mole Fraction'], 'value':None, 'unit':'mol/s'}
            self.variables['xm_pc[3,'+ str(i+1)+']'] = {'name':[val + ' Vapour Mass Fraction'], 'value':None, 'unit':'g/s'}
            self.variables['F_pc[3,'+ str(i+1)+']'] = {'name':[val + ' Vapour Mole Flow'], 'value':None, 'unit':'mol/s'}
            self.variables['Fm_pc[3,'+ str(i+1)+']'] = {'name':[val + ' Vapour Mass Flow'], 'value':None, 'unit':'g/s'}

        for i in self.compound_names:
            self.variables[i] = {'value':''}

    def param_getter(self,mode):
        dict = {}

        temp = []
        for i, val in enumerate(self.compound_names):
            temp.append(self.variables['x_pc[1,' + str(i+1) + ']']['value'])
        self.variables['x_pc']['value'] = temp

        if(mode=="PT"):
            self.mode1 = 'P'
            self.mode2 = 'T'
            
            dict = {self.mode1:self.variables['P']['value'], self.mode2:self.variables['T']['value'],
                    "MolFlow":self.variables['F_p[1]']['value'],"x_pc":self.variables['x_pc']['value'], "thermo_package":self.thermo_package}

        elif(mode=="PH"):
            self.mode1 = 'P'
            self.mode2 = 'H_p[1]'
            dict = {self.mode1:self.variables['P']['value'], self.mode2:self.variables['H_p[1]']['value'],
                    "MolFlow":self.variables['F_p[1]']['value'], "x_pc":self.variables['x_pc']['value'], "thermo_package":self.thermo_package}
        elif(mode=="PVF"):
            self.mode1 = 'P'
            self.mode2 = 'xvap'
            dict = {self.mode1:self.variables['P']['value'], self.mode2:self.variables['xvap']['value'],
                    "MolFlow":self.variables['F_p[1]']['value'], "x_pc":self.variables['x_pc']['value'],  "thermo_package":self.thermo_package}
        elif(mode=="TVF"):
            self.mode1 = 'T'
            self.mode2 = 'xvap'
            dict = {self.mode1:self.variables['T']['value'], self.mode2:self.variables['xvap']['value'],
                    "MolFlow":self.variables['F_p[1]']['value'], "x_pc":self.variables['x_pc']['value'],  "thermo_package":self.thermo_package}
        elif(mode=="PS"):
            self.mode1 = 'P'
            self.mode2 = 'S_p[1]'
            dict = {self.mode1:self.variables['P']['value'], self.mode2: self.variables['S_p[1]']['value'],
                    "MolFlow":self.variables['F_p[1]']['value'], "x_pc":self.variables['x_pc']['value'], "thermo_package":self.thermo_package}
        
        return dict

    def param_setter(self,dict):
     
        print("inside paramsetter ", dict)

        self.variables['x_pc']['value'] = dict['x_pc'].split(",")
        self.thermo_package = dict['thermo_package']
        self.variables['F_p[1]']['value'] = dict['MolFlow']
        print("inside")
        # self.Prop[self.mode2] = dict[self.mode2]
        # self.Prop[self.mode1] = dict[self.mode1]
        self.variables[self.mode1]['value'] = dict[self.mode1]
        self.variables[self.mode2]['value'] = dict[self.mode2]

        print(self.variables)
        print(self.variables['x_pc']['value'])
        for i in range(len(self.compound_names)):
            print('####### x_pc #########\n',self.variables['x_pc']['value'][i])
            print('x_pc')
            if self.variables['x_pc']['value'][i]:
                self.variables['x_pc[1,'+str(i+1)+']']['value'] = self.variables['x_pc']['value'][i]
            else:
                self.variables['x_pc[1,'+str(i+1)+']']['value'] = None
            print('xm_pc')
            # if self.variables['xm_pc']['value'][i]:
            #     self.variables['xm_pc[1,'+str(i+1)+']']['value'] = self.variables['xm_pc']['value'][i]
            # else:
            self.variables['xm_pc[1,'+str(i+1)+']']['value'] = self.variables['xm_pc']['value']

            print('f_pc')
            self.variables['F_pc[1,'+str(i+1)+']']['value'] = None
            print('fm_pc')
            self.variables['Fm_pc[1,'+str(i+1)+']']['value'] = None
            print('first for')
        print('secnod for')
        for i in range(0,len(self.compound_names)):
            self.variables['x_pc[2,'+str(i+1)+']']['value'] = None
            self.variables['xm_pc[2,'+str(i+1)+']']['value'] = None
            self.variables['F_pc[2,'+str(i+1)+']']['value'] = None
            self.variables['Fm_pc[2,'+str(i+1)+']']['value'] = None

            self.variables['x_pc[3,'+str(i+1)+']']['value'] = None
            self.variables['xm_pc[3,'+str(i+1)+']']['value'] = None
            self.variables['F_pc[3,'+str(i+1)+']']['value'] = None
            self.variables['Fm_pc[3,'+str(i+1)+']']['value'] = None 
    
    def set_pos(self,pos):
        self.pos = pos

    def get_min_eqn_values(self):
        x_pclist = []
        for i in range(0,len(self.compound_names)):
            #print(self.Prop['x_pc[1,'+str(i+1)+']'])
            #x_pclist.append(self.Prop['x_pc[1,'+str(i+1)+']'])
            x_pclist.append(self.variables['x_pc[1,'+str(i+1)+']']['value'])
        print(x_pclist)
        #x_pclist = list(self.Prop(x_pc[1,1)])
        x_pc = json.dumps(x_pclist)
        print(x_pc)
        x_pc = x_pc.replace('[','{')
        x_pc = x_pc.replace(']','}')
        x_pc = x_pc.replace('"','')
        '''
        x_pcstr = json.dumps(self.x_pc)
        x_pcstr = x_pcstr.replace('[','{')
        x_pcstr = x_pcstr.replace(']','}')
        x_pcstr = x_pcstr.replace('"','')
        '''
        if self.variables[self.mode1]['value']:
            self.eqn_dict[self.mode1] = self.variables[self.mode1]['value']
        if self.variables[self.mode2]['value']:
            self.eqn_dict[self.mode2] = self.variables[self.mode2]['value']
        if self.variables['x_pc']['value']:
            self.eqn_dict['x_pc[1,:]'] = x_pc
        if self.variables['F_pc']['value']:
            self.eqn_dict['F_p[1]'] = self.variables['F_pc']['value']  

        print("##############$GetMinVEqnValuesStart$##################")
        print("P:",self.variables[self.mode1]['value'])
        print("T:",self.variables[self.mode2]['value'])
        print("x_pc",self.variables['x_pc']['value'])
        print("F_p",self.variables['F_p[1]']['value'])
        print("##############$GetMinVEqnValuesEnd$##################")

    def get_start_values(self):
        try:
            if self.variables[self.mode1]['value']:
                self.start_dict[self.mode1] = self.variables[self.mode1]['value']
            
            if self.variables[self.mode2]['value']:
                self.start_dict[self.mode2] = self.variables[self.mode2]['value']
            

            if self.variables['x_pc[2,1]']['value'] != None:
                x_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.compound_names)+1):
                        cmf.append(str(self.variables['x_pc['+str(i)+','+str(j)+']']['value']))
                    x_pcarr.append(cmf)
                x_pcstr = json.dumps(x_pcarr)
                x_pcstr = x_pcstr.replace('[','{')
                x_pcstr = x_pcstr.replace(']','}')
                x_pcstr = x_pcstr.replace('"','')
                self.start_dict['x_pc'] = x_pcstr

            if self.variables['xm_pc[2,1]']['value'] != None:
                xm_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.compound_names)+1):
                        cmf.append(str(self.variables['xm_pc['+str(i)+','+str(j)+']']['value']))
                    xm_pcarr.append(cmf)
                xm_pcstr = json.dumps(x_pcarr)
                xm_pcstr = xm_pcstr.replace('[','{')
                xm_pcstr = xm_pcstr.replace(']','}')
                xm_pcstr = xm_pcstr.replace('"','')
                self.start_dict['xm_pc'] = xm_pcstr

            if self.variables['Fm_pc[2,1]']['value'] != None:
                Fm_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.compound_names)+1):
                        cmf.append(str(self.variables['Fm_pc['+str(i)+','+str(j)+']']['value']))
                    Fm_pcarr.append(cmf)
                Fm_pcstr = json.dumps(x_pcarr)
                Fm_pcstr = Fm_pcstr.replace('[','{')
                Fm_pcstr = Fm_pcstr.replace(']','}')
                Fm_pcstr = Fm_pcstr.replace('"','')
                self.start_dict['Fm_pc'] = Fm_pcstr

            if self.variables['F_pc[2,1]']['value'] != None:
                F_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.compound_names)+1):
                        cmf.append(str(self.variables['F_pc['+str(i)+','+str(j)+']']['value']))
                    F_pcarr.append(cmf)
                F_pcstr = json.dumps(F_pcarr)
                F_pcstr = F_pcstr.replace('[','{')
                F_pcstr = F_pcstr.replace(']','}')
                F_pcstr = F_pcstr.replace('"','')
                self.start_dict['F_pc'] = F_pcstr

            if self.variables['MW_p[2]']['value'] != None:
                MW_pArr = []
                for i in range(1,4):
                    MW_pArr.append(self.variables['MW_p['+str(i)+']']['value'])
                MW_pStr = json.dumps(MW_pArr)
                MW_pStr = MW_pStr.replace('[','{')
                MW_pStr = MW_pStr.replace(']','}')
                MW_pStr = MW_pStr.replace('"','')
                self.start_dict['MW_p'] = MW_pStr

            if self.variables['F_p[2]']['value'] != None:
                F_pArr = []
                for i in range(1,4):
                    F_pArr.append(self.variables['F_p['+str(i)+']']['value'])
                F_pStr = json.dumps(F_pArr)
                F_pStr = F_pStr.replace('[','{')
                F_pStr = F_pStr.replace(']','}')
                F_pStr = F_pStr.replace('"','')
                self.start_dict['F_p'] = F_pStr

            if self.variables['Cp_p[2]']['value'] != None:
                Cp_pArr = []
                for i in range(1,4):
                    Cp_pArr.append(self.variables['Cp_p['+str(i)+']']['value'])
                Cp_pStr = json.dumps(Cp_pArr)
                Cp_pStr = Cp_pStr.replace('[','{')
                Cp_pStr = Cp_pStr.replace(']','}')
                Cp_pStr = Cp_pStr.replace('"','')
                self.start_dict['Cp_p'] = Cp_pStr

            if self.variables['H_p[2]']['value'] != None:
                H_pArr = []
                for i in range(1,4):
                    H_pArr.append(self.variables['H_p['+str(i)+']']['value'])
                H_pStr = json.dumps(H_pArr)
                H_pStr = H_pStr.replace('[','{')
                H_pStr = H_pStr.replace(']','}')
                H_pStr = H_pStr.replace('"','')
                self.start_dict['H_p'] = H_pStr


            if self.variables['S_p[2]']['value'] != None:
                S_pArr = []
                for i in range(1,4):
                    S_pArr.append(self.variables['S_p['+str(i)+']']['value'])
                S_pStr = json.dumps(S_pArr)
                S_pStr = S_pStr.replace('[','{')
                S_pStr = S_pStr.replace(']','}')
                S_pStr = S_pStr.replace('"','')
                self.start_dict['S_p'] = S_pStr

            if self.variables['Fm_p[2]']['value'] != None:
                Fm_pArr = []
                for i in range(1,4):
                    Fm_pArr.append(self.variables['Fm_p['+str(i)+']']['value'])
                Fm_pStr = json.dumps(Fm_pArr)
                Fm_pStr = Fm_pStr.replace('[','{')
                Fm_pStr = Fm_pStr.replace(']','}')
                Fm_pStr = Fm_pStr.replace('"','')
                self.start_dict['Fm_p'] = Fm_pStr

        except Exception as e:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            print(exc_type,exc_tb.tb_lineno)
            print(e)
            print('error')

    def OM_Flowsheet_Initialize(self,addedcomp):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + ("model ms"+str(self.count)+"\n")
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Streams.MaterialStream;\n" )
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Files.ThermodynamicPackages."+self.thermo_package+";\n")
        self.OM_data_init = self.OM_data_init + ("end ms"+str(self.count)+";\n")
        comp_count = len(addedcomp)
        # self.get_start_values()

        #self.OM_data_init = "Simulator.Streams.Mat_Stm_RL " + self.name +"(Nc = " + str(comp_count)
        self.OM_data_init = self.OM_data_init + "ms"+str(self.count) +" " + self.name +"(Nc = " + str(comp_count)
        self.OM_data_init = self.OM_data_init + ",C = {"
        C = str(addedcomp).strip('[').strip(']')
        C = C.replace("'","")
        self.OM_data_init = self.OM_data_init + C + "},"
        #for key, value in self.start_dict.items():
        #    self.OM_data_init = self.OM_data_init + key + '(start = ' + str(value) + '),'
        self.OM_data_init = self.OM_data_init[:-1]
        self.OM_data_init = self.OM_data_init + ');\n'        
        return self.OM_data_init


    def OM_Flowsheet_Equation(self,addedcomp,method):
        self.OM_data_eqn = ''
        self.comp_count = len(addedcomp)
        if method == 'Eqn':
            self.eqn_dict = {}
            self.get_min_eqn_values()
        if method == 'SM':
            self.eqn_dict = {}
            self.get_min_eqn_values()
            #self.GetEquationValues()
        #self.GetEquationValues()

        for key,value in self.eqn_dict.items():
            self.OM_data_eqn = self.OM_data_eqn + self.name + '.'+ key + ' = ' + str(value) + ';\n'
        return self.OM_data_eqn
