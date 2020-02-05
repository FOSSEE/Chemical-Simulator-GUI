from OMPython import OMCSession
from PyQt5.QtCore import *
import json
import sys
from collections import defaultdict

class MaterialStream():
    counter = 1
    def __init__(self, CompNames = []):

        self.name = 'MaterialStream' + str(MaterialStream.counter)
        self.type = 'MaterialStream'

        self.CompNames = CompNames
        self.count = MaterialStream.counter
        self.thermoPackage ="RaoultsLaw"
        self.mode1 = "P"
        self.mode2 = "T"

        self.mode1val = ""
        self.mode2val = ""
        self.OM_data_init = ''
        self.OM_data_eqn = ''
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30
        self.y = 2500-30
        self.pos = QPointF(self.x, self.y)
        MaterialStream.counter+=1
        self.startDict = {}
        self.eqnDict = {}
        self.modesList = ["PT","PH","PVF","TVF","PS"]
        
        self.variables = {
            'P'     : {'name':'Pressure',         'value':101325,    'unit':'Pa'},          # {'Pa':1, 'mmHg':0, 'N/m^2':0}},
            'T'     : {'name':'Temperature',      'value':300,       'unit':'K'},

            'xvap'   : {'name':'Vapour Phase Mole Fraction',          'value':None,       'unit':'g/s'},
            'H_p[1]'  : {'name':'Mixture Phase Molar Entalpy',        'value':None,       'unit':'g/s'},
            'S_p[1]'  : {'name':'Mixture Phase Molar Entropy',        'value':None,       'unit':'g/s'},
            'F_p[1]'  : {'name':'Mixture Molar Flow Rate',            'value':None,       'unit':'g/s'},

            'H_p[2]'  : {'name':'Liquid Phase Molar Entalpy',        'value':None,       'unit':'g/s'},
            'S_p[2]'  : {'name':'Liquid Phase Molar Entropy',        'value':None,       'unit':'g/s'},
            'F_p[2]'  : {'name':'Liquid Molar Flow Rate',            'value':None,       'unit':'g/s'},

            'H_p[3]'  : {'name':'Vapour Phase Molar Entalpy',        'value':None,       'unit':'g/s'},
            'S_p[3]'  : {'name':'Vapour Phase Molar Entropy',        'value':None,       'unit':'g/s'},
            'F_p[3]'  : {'name':'Vapour Molar Flow Rate',            'value':None,       'unit':'g/s'},

            'x_pc'  : {'name':'Mole Fraction',    'value':1.0,      'unit':'mol/s'},
            'xm_pc' : {'name':'Mass Fraction',    'value':None,     'unit':'g/s'},
            
            'F_pc'  : {'name':'Mole Flow',        'value':100,      'unit':'mol/s'},
            'Fm_pc' : {'name':'Mass Flow',        'value':None,     'unit':'g/s'},
        }
        self.initVariables()

    def initVariables(self):
        for i, val in enumerate(self.CompNames):
            self.variables['x_pc[1,'+ str(i+1)+']'] = {'name':val + ' Mixture Mole Fraction', 'value':None, 'unit':'mol/s'}
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

        for i in self.CompNames:
            self.variables[i] = {'value':''}

    def paramgetter(self,mode):
        dict = {}

        if(mode=="PT"):
            self.mode1 = 'P'
            self.mode2 = 'T'
            dict = {self.mode1:self.variables['P']['value'], self.mode2:self.variables['T']['value'],
                    "MolFlow":self.variables['F_pc']['value'],"x_pc":self.variables['x_pc']['value'], "thermoPackage":self.thermoPackage}
        elif(mode=="PH"):
            self.mode1 = 'P'
            self.mode2 = 'H_p[1]'
            dict = {self.mode1:self.variables['P']['value'], self.mode2:self.variables['H_p[1]']['value'],
                    "MolFlow":self.variables['F_pc']['value'], "x_pc":self.variables['x_pc']['value'], "thermoPackage":self.thermoPackage}
        elif(mode=="PVF"):
            self.mode1 = 'P'
            self.mode2 = 'xvap'
            dict = {self.mode1:self.variables['P']['value'], self.mode2:self.variables['xvap']['value'],
                    "MolFlow":self.variables['F_pc']['value'], "x_pc":self.variables['x_pc']['value'],  "thermoPackage":self.thermoPackage}
        elif(mode=="TVF"):
            self.mode1 = 'T'
            self.mode2 = 'xvap'
            dict = {self.mode1:self.variables['T']['value'], self.mode2:self.variables['xvap']['value'],
                    "MolFlow":self.variables['F_pc']['value'], "x_pc":self.variables['x_pc']['value'],  "thermoPackage":self.thermoPackage}
        elif(mode=="PS"):
            self.mode1 = 'P'
            self.mode2 = 'S_p[1]'
            dict = {self.mode1:self.variables['P']['value'], self.mode2: self.variables['S_p[1]']['value'],
                    "MolFlow":self.variables['F_pc']['value'], "x_pc":self.variables['x_pc']['value'], "thermoPackage":self.thermoPackage}
        
        return dict

    def paramsetter(self,dict):
     
        print("inside paramsetter ", dict)

        self.variables['x_pc']['value'] = dict['x_pc'].split(",")
        self.thermoPackage = dict['thermoPackage']
        self.variables['F_p[1]']['value'] = dict['MolFlow']
        print("inside")
        # self.Prop[self.mode2] = dict[self.mode2]
        # self.Prop[self.mode1] = dict[self.mode1]
        self.variables[self.mode1]['value'] = dict[self.mode1]
        self.variables[self.mode2]['value'] = dict[self.mode2]

        print(self.variables)
        print(self.variables['x_pc']['value'])
        for i in range(len(self.CompNames)):
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
        for i in range(0,len(self.CompNames)):
            self.variables['x_pc[2,'+str(i+1)+']']['value'] = None
            self.variables['xm_pc[2,'+str(i+1)+']']['value'] = None
            self.variables['F_pc[2,'+str(i+1)+']']['value'] = None
            self.variables['Fm_pc[2,'+str(i+1)+']']['value'] = None

            self.variables['x_pc[3,'+str(i+1)+']']['value'] = None
            self.variables['xm_pc[3,'+str(i+1)+']']['value'] = None
            self.variables['F_pc[3,'+str(i+1)+']']['value'] = None
            self.variables['Fm_pc[3,'+str(i+1)+']']['value'] = None 
    
    def setPos(self,pos):
        self.pos = pos

    def GetMinEqnValues(self):
        x_pclist = []
        for i in range(0,len(self.CompNames)):
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
            self.eqnDict[self.mode1] = self.variables[self.mode1]['value']
        if self.variables[self.mode2]['value']:
            self.eqnDict[self.mode2] = self.variables[self.mode2]['value']
        if self.variables['x_pc']['value']:
            self.eqnDict['x_pc[1,:]'] = x_pc
        if self.variables['F_pc']['value']:
            self.eqnDict['F_p[1]'] = self.variables['F_pc']['value']  

        print("##############$GetMinVEqnValuesStart$##################")
        print("P:",self.variables[self.mode1]['value'])
        print("T:",self.variables[self.mode2]['value'])
        print("x_pc",self.variables['x_pc']['value'])
        print("F_p",self.variables['F_p[1]']['value'])
        print("##############$GetMinVEqnValuesEnd$##################")

    def GetStartValues(self):
        try:
            if self.variables[self.mode1]['value']:
                self.startDict[self.mode1] = self.variables[self.mode1]['value']
            
            if self.variables[self.mode2]['value']:
                self.startDict[self.mode2] = self.variables[self.mode2]['value']
            

            if self.variables['x_pc[2,1]']['value'] != None:
                x_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.variables['x_pc['+str(i)+','+str(j)+']']['value']))
                    x_pcarr.append(cmf)
                x_pcstr = json.dumps(x_pcarr)
                x_pcstr = x_pcstr.replace('[','{')
                x_pcstr = x_pcstr.replace(']','}')
                x_pcstr = x_pcstr.replace('"','')
                self.startDict['x_pc'] = x_pcstr

            if self.variables['xm_pc[2,1]']['value'] != None:
                xm_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.variables['xm_pc['+str(i)+','+str(j)+']']['value']))
                    xm_pcarr.append(cmf)
                xm_pcstr = json.dumps(x_pcarr)
                xm_pcstr = xm_pcstr.replace('[','{')
                xm_pcstr = xm_pcstr.replace(']','}')
                xm_pcstr = xm_pcstr.replace('"','')
                self.startDict['xm_pc'] = xm_pcstr

            if self.variables['Fm_pc[2,1]']['value'] != None:
                Fm_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.variables['Fm_pc['+str(i)+','+str(j)+']']['value']))
                    Fm_pcarr.append(cmf)
                Fm_pcstr = json.dumps(x_pcarr)
                Fm_pcstr = Fm_pcstr.replace('[','{')
                Fm_pcstr = Fm_pcstr.replace(']','}')
                Fm_pcstr = Fm_pcstr.replace('"','')
                self.startDict['Fm_pc'] = Fm_pcstr

            if self.variables['F_pc[2,1]']['value'] != None:
                F_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.variables['F_pc['+str(i)+','+str(j)+']']['value']))
                    F_pcarr.append(cmf)
                F_pcstr = json.dumps(F_pcarr)
                F_pcstr = F_pcstr.replace('[','{')
                F_pcstr = F_pcstr.replace(']','}')
                F_pcstr = F_pcstr.replace('"','')
                self.startDict['F_pc'] = F_pcstr

            if self.variables['MW_p[2]']['value'] != None:
                MW_pArr = []
                for i in range(1,4):
                    MW_pArr.append(self.variables['MW_p['+str(i)+']']['value'])
                MW_pStr = json.dumps(MW_pArr)
                MW_pStr = MW_pStr.replace('[','{')
                MW_pStr = MW_pStr.replace(']','}')
                MW_pStr = MW_pStr.replace('"','')
                self.startDict['MW_p'] = MW_pStr

            if self.variables['F_p[2]']['value'] != None:
                F_pArr = []
                for i in range(1,4):
                    F_pArr.append(self.variables['F_p['+str(i)+']']['value'])
                F_pStr = json.dumps(F_pArr)
                F_pStr = F_pStr.replace('[','{')
                F_pStr = F_pStr.replace(']','}')
                F_pStr = F_pStr.replace('"','')
                self.startDict['F_p'] = F_pStr

            if self.variables['Cp_p[2]']['value'] != None:
                Cp_pArr = []
                for i in range(1,4):
                    Cp_pArr.append(self.variables['Cp_p['+str(i)+']']['value'])
                Cp_pStr = json.dumps(Cp_pArr)
                Cp_pStr = Cp_pStr.replace('[','{')
                Cp_pStr = Cp_pStr.replace(']','}')
                Cp_pStr = Cp_pStr.replace('"','')
                self.startDict['Cp_p'] = Cp_pStr

            if self.variables['H_p[2]']['value'] != None:
                H_pArr = []
                for i in range(1,4):
                    H_pArr.append(self.variables['H_p['+str(i)+']']['value'])
                H_pStr = json.dumps(H_pArr)
                H_pStr = H_pStr.replace('[','{')
                H_pStr = H_pStr.replace(']','}')
                H_pStr = H_pStr.replace('"','')
                self.startDict['H_p'] = H_pStr


            if self.variables['S_p[2]']['value'] != None:
                S_pArr = []
                for i in range(1,4):
                    S_pArr.append(self.variables['S_p['+str(i)+']']['value'])
                S_pStr = json.dumps(S_pArr)
                S_pStr = S_pStr.replace('[','{')
                S_pStr = S_pStr.replace(']','}')
                S_pStr = S_pStr.replace('"','')
                self.startDict['S_p'] = S_pStr

            if self.variables['Fm_p[2]']['value'] != None:
                Fm_pArr = []
                for i in range(1,4):
                    Fm_pArr.append(self.variables['Fm_p['+str(i)+']']['value'])
                Fm_pStr = json.dumps(Fm_pArr)
                Fm_pStr = Fm_pStr.replace('[','{')
                Fm_pStr = Fm_pStr.replace(']','}')
                Fm_pStr = Fm_pStr.replace('"','')
                self.startDict['Fm_p'] = Fm_pStr

        except Exception as e:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            print(exc_type,exc_tb.tb_lineno)
            print(e)
            print('error')

    def OM_Flowsheet_Initialize(self,addedcomp):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + ("model ms"+str(self.count)+"\n")
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Streams.MaterialStream;\n" )
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Files.ThermodynamicPackages."+self.thermoPackage+";\n")
        self.OM_data_init = self.OM_data_init + ("end ms"+str(self.count)+";\n")
        comp_count = len(addedcomp)
        # self.GetStartValues()

        #self.OM_data_init = "Simulator.Streams.Mat_Stm_RL " + self.name +"(Nc = " + str(comp_count)
        self.OM_data_init = self.OM_data_init + "ms"+str(self.count) +" " + self.name +"(Nc = " + str(comp_count)
        self.OM_data_init = self.OM_data_init + ",C = {"
        C = str(addedcomp).strip('[').strip(']')
        C = C.replace("'","")
        self.OM_data_init = self.OM_data_init + C + "},"
        #for key, value in self.startDict.items():
        #    self.OM_data_init = self.OM_data_init + key + '(start = ' + str(value) + '),'
        self.OM_data_init = self.OM_data_init[:-1]
        self.OM_data_init = self.OM_data_init + ');\n'        
        return self.OM_data_init


    def OM_Flowsheet_Equation(self,addedcomp,method):
        self.OM_data_eqn = ''
        self.comp_count = len(addedcomp)
        if method == 'Eqn':
            self.eqnDict = {}
            self.GetMinEqnValues()
        if method == 'SM':
            self.eqnDict = {}
            self.GetMinEqnValues()
            #self.GetEquationValues()
        #self.GetEquationValues()

        for key,value in self.eqnDict.items():
            self.OM_data_eqn = self.OM_data_eqn + self.name + '.'+ key + ' = ' + str(value) + ';\n'
        return self.OM_data_eqn

      
'''
from OMPython import OMCSession
from PyQt5.QtCore import *
import json
import sys
from collections import defaultdict

class MaterialStream():
    counter = 1
    def __init__(self,CompNames = [],Temperature=300,Pressure=101325,xvap=None,xmvap=None,xliq=None,xmliq=None,x_pc = [1.0], xm_pc = [], MolFlow=100, MasFlow=None,**kwargs):
        self.name = 'MaterialStream' + str(MaterialStream.counter)
        self.type = 'MaterialStream'
        self.T = Temperature
        self.P = Pressure
        self.xvap = xvap
        self.xmvap =  xmvap
        self.xliq = xliq
        self.xmliq = xmliq
        self.CompNames = CompNames
        self.x_pc = x_pc
        self.xm_pc = xm_pc
        self.MolFlow = MolFlow
        self.MasFlow = MasFlow
        self.OM_data_init = ''
        self.OM_data_eqn = ''
        self.count = MaterialStream.counter
        self.thermoPackage ="RaoultsLaw"
        self.mode1 = "P"
        self.mode1val = ""
        self.mode2 = "T"
        self.mode2val = ""
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30
        self.y = 2500-30
        self.pos = QPointF(self.x, self.y)
        MaterialStream.counter+=1
        self.startDict = {}
        self.eqnDict = {}
        self.modesList = ["PT","PH","PVF","TVF","PS"]

        self.Prop = {

            self.mode1:self.mode1val,
            self.mode2:self.mode2val,
            'xliq':xliq,
            'xmliq':xmliq,
            'xvap':xvap,
            'xmvap':xmvap,
            'F_p[1]':MolFlow,
            'Fm_p[1]':MasFlow,
            'MW_p[1]':None,
            'MW_p[2]':None,
            'MW_p[3]':None,
            'Cp_p[1]':None,
            'H_p[1]':None,
            'S_p[1]':None,
            'Cp_p[2]':None,
            'H_p[2]':None,
            'S_p[2]':None,
            'Cp_p[3]':None,
            'H_p[3]':None,
            'S_p[3]':None,
            'F_p[2]':None,
            'Fm_p[2]':None,
            'F_p[3]':None,
            'Fm_p[3]':None

        }

        self.Prop1 = {
            self.mode1:self.mode1val,
            self.mode2:self.mode2val,
            'xliq':xliq,
            'xmliq':xmliq,
            'xvap':xvap,
            'xmvap':xmvap,
            'F_p[1]':MolFlow,
            'Fm_p[1]':MasFlow,
            'MW_p[1]':None,
            'MW_p[2]':None,
            'MW_p[3]':None,
            'Cp_p[1]':None,
            'H_p[1]':None,
            'S_p[1]':None,
            'Cp_p[2]':None,
            'H_p[2]':None,
            'S_p[2]':None,
            'Cp_p[3]':None,
            'H_p[3]':None,
            'S_p[3]':None,
            'F_p[2]':None,
            'Fm_p[2]':None,
            'F_p[3]':None,
            'Fm_p[3]':None

        }
   
    def paramgetter(self,mode):
        dict = {}
        # print("Hello hello ", mode)
        # if(mode == None):
        #     mode = self.modesList[0]
        if(mode=="PT"):
            self.mode1 = 'P'
            self.mode2 = 'T'
            dict = {self.mode2:self.T,self.mode1:self.P,"x_pc":self.x_pc,"MolFlow":self.MolFlow,"thermoPackage":self.thermoPackage}
        elif(mode=="PH"):
            self.mode1 = 'P'
            self.mode2 = 'H_p[1]'
            dict = {self.mode1:self.P,self.mode2:self.Prop['H_p[1]'],"x_pc":self.x_pc,"MolFlow":self.MolFlow,"thermoPackage":self.thermoPackage}
        elif(mode=="PVF"):
            self.mode1 = 'P'
            self.mode2 = 'xvap'
            dict = {self.mode1:self.P,self.mode2:self.xvap,"x_pc":self.x_pc,"MolFlow":self.MolFlow,"thermoPackage":self.thermoPackage}
        elif(mode=="TVF"):
            self.mode1 = 'T'
            self.mode2 = 'xvap'
            dict = {self.mode1:self.T,self.mode2:self.xvap,"x_pc":self.x_pc,"MolFlow":self.MolFlow,"thermoPackage":self.thermoPackage}
        elif(mode=="PS"):
            self.mode1 = 'P'
            self.mode2 = 'S_p[1]'
            dict = {self.mode1:self.P,self.mode2:self.Prop['S_p[1]'],"x_pc":self.x_pc,"MolFlow":self.MolFlow,"thermoPackage":self.thermoPackage}
        
        return dict

    def paramsetter(self,dict):
        self.mode1val = dict[self.mode1]
        self.mode2val = dict[self.mode2]
        self.MolFlow = dict['MolFlow']
        self.x_pc = dict['x_pc'].split(",")
        self.thermoPackage = dict['thermoPackage']
        self.Prop['F_p[1]'] = self.MolFlow
        self.Prop[self.mode2] = dict[self.mode2]
        self.Prop[self.mode1] = dict[self.mode1]
        for i in range(len(self.CompNames)):
            print('####### x_pc #########\n',self.x_pc[i])
            if self.x_pc:
                self.Prop['x_pc[1,'+str(i+1)+']'] = self.x_pc[i]
            else:
                self.Prop['x_pc[1,'+str(i+1)+']'] = None

            if self.xm_pc:
                self.Prop['xm_pc[1,'+str(i+1)+']'] = self.xm_pc[i]
            else:
                self.Prop['xm_pc[1,'+str(i+1)+']'] = None

            self.Prop['F_pc[1,'+str(i+1)+']'] = None
            self.Prop['Fm_pc[1,'+str(i+1)+']'] = None
        for i in range(0,len(self.CompNames)):
            self.Prop['x_pc[2,'+str(i+1)+']'] = None
            self.Prop['xm_pc[2,'+str(i+1)+']'] = None
            self.Prop['F_pc[2,'+str(i+1)+']'] = None
            self.Prop['Fm_pc[2,'+str(i+1)+']'] = None
            self.Prop['x_pc[3,'+str(i+1)+']'] = None
            self.Prop['xm_pc[3,'+str(i+1)+']'] = None
            self.Prop['F_pc[3,'+str(i+1)+']'] = None
            self.Prop['Fm_pc[3,'+str(i+1)+']'] = None
    
    def setPos(self,pos):
        self.pos = pos

    def GetMinEqnValues(self):
        x_pclist = []
        for i in range(0,len(self.CompNames)):
            print(self.Prop['x_pc[1,'+str(i+1)+']'])
            x_pclist.append(self.Prop['x_pc[1,'+str(i+1)+']'])
        print(x_pclist)
        #x_pclist = list(self.Prop(x_pc[1,1)])
        x_pc = json.dumps(x_pclist)
        print(x_pc)
        x_pc = x_pc.replace('[','{')
        x_pc = x_pc.replace(']','}')
        x_pc = x_pc.replace('"','')
        
        # x_pcstr = json.dumps(self.x_pc)
        # x_pcstr = x_pcstr.replace('[','{')
        # x_pcstr = x_pcstr.replace(']','}')
        # x_pcstr = x_pcstr.replace('"','')
        
        if self.Prop[self.mode1]:
            self.eqnDict[self.mode1] = self.Prop[self.mode1]
        if self.Prop[self.mode2]:
            self.eqnDict[self.mode2] = self.Prop[self.mode2]
        if self.x_pc:
            self.eqnDict['x_pc[1,:]'] = x_pc
        if self.MolFlow:
            self.eqnDict['F_p[1]'] = self.Prop['F_p[1]']#self.MolFlow

        print("##############$GetMinVEqnValuesStart$##################")
        print("P:",self.Prop[self.mode1])
        print("T:",self.Prop[self.mode2])
        print("x_pc",x_pc)
        print("F_p",self.Prop['F_p[1]'])
        print("##############$GetMinVEqnValuesEnd$##################")

    # def GetEquationValues(self):    # Not being called anywhere
    #     if self.Prop[self.mode1]:
    #         self.eqnDict[self.mode1] = self.Prop[self.mode1]
        
    #     if self.Prop[self.mode2]:
    #         self.eqnDict[self.mode2] = self.Prop[self.mode2]
        
    #     if self.Prop['x_pc[1,1]']:
    #         cfa = []
    #         for i in range(1,len(self.CompNames)+1):
    #             cfa.append(self.Prop['x_pc[1,'+str(i)+']'])
    #         cmpMolFracstr = json.dumps(cfa)
    #         cmpMolFracstr = cmpMolFracstr.replace('[','{')
    #         cmpMolFracstr = cmpMolFracstr.replace(']','}')
    #         cmpMolFracstr = cmpMolFracstr.replace('"','')
    #         self.eqnDict['x_pc[1,:]'] = cmpMolFracstr
        
    #     if self.Prop['F_p[1]']:
    #         self.eqnDict['F_p[1]'] = self.Prop['F_p[1]']


    def GetStartValues(self):
        try:
            if self.Prop[self.mode1]:
                self.startDict[self.mode1] = self.Prop[self.mode1]
            
            if self.Prop[self.mode2]:
                self.startDict[self.mode2] = self.Prop[self.mode2]
            

            if self.Prop['x_pc[2,1]'] != None:
                x_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.Prop['x_pc['+str(i)+','+str(j)+']']))
                    x_pcarr.append(cmf)
                x_pcstr = json.dumps(x_pcarr)
                x_pcstr = x_pcstr.replace('[','{')
                x_pcstr = x_pcstr.replace(']','}')
                x_pcstr = x_pcstr.replace('"','')
                self.startDict['x_pc'] = x_pcstr

            if self.Prop['xm_pc[2,1]'] != None:
                xm_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.Prop['xm_pc['+str(i)+','+str(j)+']']))
                    xm_pcarr.append(cmf)
                xm_pcstr = json.dumps(x_pcarr)
                xm_pcstr = xm_pcstr.replace('[','{')
                xm_pcstr = xm_pcstr.replace(']','}')
                xm_pcstr = xm_pcstr.replace('"','')
                self.startDict['xm_pc'] = xm_pcstr

            if self.Prop['Fm_pc[2,1]'] != None:
                Fm_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.Prop['Fm_pc['+str(i)+','+str(j)+']']))
                    Fm_pcarr.append(cmf)
                Fm_pcstr = json.dumps(x_pcarr)
                Fm_pcstr = Fm_pcstr.replace('[','{')
                Fm_pcstr = Fm_pcstr.replace(']','}')
                Fm_pcstr = Fm_pcstr.replace('"','')
                self.startDict['Fm_pc'] = Fm_pcstr

            if self.Prop['F_pc[2,1]'] != None:
                F_pcarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.Prop['F_pc['+str(i)+','+str(j)+']']))
                    F_pcarr.append(cmf)
                F_pcstr = json.dumps(F_pcarr)
                F_pcstr = F_pcstr.replace('[','{')
                F_pcstr = F_pcstr.replace(']','}')
                F_pcstr = F_pcstr.replace('"','')
                self.startDict['F_pc'] = F_pcstr

            if self.Prop['MW_p[2]'] != None:
                MW_pArr = []
                for i in range(1,4):
                    MW_pArr.append(self.Prop['MW_p['+str(i)+']'])
                MW_pStr = json.dumps(MW_pArr)
                MW_pStr = MW_pStr.replace('[','{')
                MW_pStr = MW_pStr.replace(']','}')
                MW_pStr = MW_pStr.replace('"','')
                self.startDict['MW_p'] = MW_pStr

            if self.Prop['F_p[2]'] != None:
                F_pArr = []
                for i in range(1,4):
                    F_pArr.append(self.Prop['F_p['+str(i)+']'])
                F_pStr = json.dumps(F_pArr)
                F_pStr = F_pStr.replace('[','{')
                F_pStr = F_pStr.replace(']','}')
                F_pStr = F_pStr.replace('"','')
                self.startDict['F_p'] = F_pStr

            if self.Prop['Cp_p[2]'] != None:
                Cp_pArr = []
                for i in range(1,4):
                    Cp_pArr.append(self.Prop['Cp_p['+str(i)+']'])
                Cp_pStr = json.dumps(Cp_pArr)
                Cp_pStr = Cp_pStr.replace('[','{')
                Cp_pStr = Cp_pStr.replace(']','}')
                Cp_pStr = Cp_pStr.replace('"','')
                self.startDict['Cp_p'] = Cp_pStr

            if self.Prop['H_p[2]'] != None:
                H_pArr = []
                for i in range(1,4):
                    H_pArr.append(self.Prop['H_p['+str(i)+']'])
                H_pStr = json.dumps(H_pArr)
                H_pStr = H_pStr.replace('[','{')
                H_pStr = H_pStr.replace(']','}')
                H_pStr = H_pStr.replace('"','')
                self.startDict['H_p'] = H_pStr


            if self.Prop['S_p[2]'] != None:
                S_pArr = []
                for i in range(1,4):
                    S_pArr.append(self.Prop['S_p['+str(i)+']'])
                S_pStr = json.dumps(S_pArr)
                S_pStr = S_pStr.replace('[','{')
                S_pStr = S_pStr.replace(']','}')
                S_pStr = S_pStr.replace('"','')
                self.startDict['S_p'] = S_pStr

            if self.Prop['Fm_p[2]'] != None:
                Fm_pArr = []
                for i in range(1,4):
                    Fm_pArr.append(self.Prop['Fm_p['+str(i)+']'])
                Fm_pStr = json.dumps(Fm_pArr)
                Fm_pStr = Fm_pStr.replace('[','{')
                Fm_pStr = Fm_pStr.replace(']','}')
                Fm_pStr = Fm_pStr.replace('"','')
                self.startDict['Fm_p'] = Fm_pStr

        except Exception as e:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            print(exc_type,exc_tb.tb_lineno)
            print(e)
            print('error')

       
    def OM_Flowsheet_Initialize(self,addedcomp):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + ("model ms"+str(self.count)+"\n")
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Streams.MaterialStream;\n" )
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Files.ThermodynamicPackages."+self.thermoPackage+";\n")
        self.OM_data_init = self.OM_data_init + ("end ms"+str(self.count)+";\n")
        comp_count = len(addedcomp)
        # self.GetStartValues()

        #self.OM_data_init = "Simulator.Streams.Mat_Stm_RL " + self.name +"(Nc = " + str(comp_count)
        self.OM_data_init = self.OM_data_init + "ms"+str(self.count) +" " + self.name +"(Nc = " + str(comp_count)
        self.OM_data_init = self.OM_data_init + ",C = {"
        C = str(addedcomp).strip('[').strip(']')
        C = C.replace("'","")
        self.OM_data_init = self.OM_data_init + C + "},"
        #for key, value in self.startDict.items():
        #    self.OM_data_init = self.OM_data_init + key + '(start = ' + str(value) + '),'
        self.OM_data_init = self.OM_data_init[:-1]
        self.OM_data_init = self.OM_data_init + ');\n'        
        return self.OM_data_init


    def OM_Flowsheet_Equation(self,addedcomp,method):
        self.OM_data_eqn = ''
        self.comp_count = len(addedcomp)
        if method == 'Eqn':
            self.eqnDict = {}
            self.GetMinEqnValues()
        if method == 'SM':
            self.eqnDict = {}
            self.GetMinEqnValues()
            #self.GetEquationValues()
        #self.GetEquationValues()

        for key,value in self.eqnDict.items():
            self.OM_data_eqn = self.OM_data_eqn + self.name + '.'+ key + ' = ' + str(value) + ';\n'
        return self.OM_data_eqn

      
'''