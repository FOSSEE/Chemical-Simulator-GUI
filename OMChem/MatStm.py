from OMPython import OMCSession
import json
import sys
from collections import defaultdict

class MatStm():
    def __init__(self,name =None,CompNames = [],Temperature=300,Pressure=101325,VapPhasMolFrac=None,VapPhasMasFrac=None,LiqPhasMolFrac=None,LiqPhasMasFrac=None,CompMolFrac = [1.0], CompMasFrac = [], MolFlow=100, MasFlow=None,**kwargs):
        self.name = name[0]
        self.type = 'MatStm'
        self.T = Temperature
        self.P = Pressure
        self.VapPhasMolFrac = VapPhasMolFrac
        self.VapPhasMasFrac =  VapPhasMasFrac
        self.LiqPhasMolFrac = LiqPhasMolFrac
        self.LiqPhasMasFrac = LiqPhasMasFrac
        self.CompNames = CompNames
        self.CompMolFrac = CompMolFrac
        self.CompMasFrac = CompMasFrac
        self.MolFlow = MolFlow
        self.MasFlow = MasFlow
        self.OM_data_init = ''
        self.OM_data_eqn = ''
        self.count = name[1]
        self.thermoPackage ="Raoults_Law"
        self.mode1 = "P"
        self.mode1val = ""
        self.mode2 = "T"
        self.mode2val = ""

        # self.ValEntList =  {"T":T," P":P," VapPhasMolFrac":vapPhasMolFrac," CompNames":CompNames," CompMolFrac[1]":CompMolFrac," CompMasFrac":CompMasFrac," MolFlow[1]":MolFlow," MasFlow[1]":MasFlow}


        # self.OMProp = {
        #     'Pressure': self.mode1,
        #     'Temperature': self.mode2,
        #     'Liquid Phase Mole Fraction': 'liqPhasMolFrac',
        #     'Liquid Phase Mas Fraction': 'liqPhasMasFrac',
        #     'Vapour Phase Mole Fraction': 'vapPhasMolFrac',
        #     'Vapour Phase Mas Fraction': 'vapPhasMasFrac',
        #     'Total Molar Flow': 'totMolFlo[1]',
        #     'Total Mas Flow': 'totMasFlo[1]',
        #     'Av. Molecular Weight': 'MW[1]',
        #     'Comp Mole Fraction': ['compMolFrac[1,1]','compMolFrac[1,2]','compMolFrac[1,3]'],
        #     'Comp Mas Fraction': ['compMasFrac[1,1]','compMasFrac[1,2]','compMasFrac[1,3]'],
        #     'Comp Molar Flow': ['compMolFlo[1,1]','compMolFlo[1,2]','compMolFlo[1,3]'],
        #     'Comp Mas Flow': ['compMasFlo[1,1]','compMasFlo[1,2]','compMasFlo[1,3]'],
        #     'Molar Specific Heat': 'phasMolSpHeat[1]',
        #     'Molar Enthalpy': 'phasMolEnth[1]',
        #     'Molar Entropy': 'phasMolEntr[1]'
        # }
        self.startDict = {}
        self.eqnDict = {}
        

        self.Prop = {

            self.mode1:self.mode1val,
            self.mode2:self.mode2val,
            'liqPhasMolFrac':LiqPhasMolFrac,
            'liqPhasMasFrac':LiqPhasMasFrac,
            'vapPhasMolFrac':VapPhasMolFrac,
            'vapPhasMasFrac':VapPhasMasFrac,
            'totMolFlo[1]':MolFlow,
            'totMasFlo[1]':MasFlow,
            'MW[1]':None,
            'MW[2]':None,
            'MW[3]':None,
            'phasMolSpHeat[1]':None,
            'phasMolEnth[1]':None,
            '[1]':None,
            'phasMolSpHeat[2]':None,
            'phasMolEnth[2]':None,
            'phasMolEntr[2]':None,
            'phasMolSpHeat[3]':None,
            'phasMolEnth[3]':None,
            'phasMolEntr[3]':None,
            'totMolFlo[2]':None,
            'totMasFlo[2]':None,
            'totMolFlo[3]':None,
            'totMasFlo[3]':None

        }

        self.Prop1 = {
            self.mode1:self.mode1val,
            self.mode2:self.mode2val,
            'liqPhasMolFrac':LiqPhasMolFrac,
            'liqPhasMasFrac':LiqPhasMasFrac,
            'vapPhasMolFrac':VapPhasMolFrac,
            'vapPhasMasFrac':VapPhasMasFrac,
            'totMolFlo[1]':MolFlow,
            'totMasFlo[1]':MasFlow,
            'MW[1]':None,
            'MW[2]':None,
            'MW[3]':None,
            'phasMolSpHeat[1]':None,
            'phasMolEnth[1]':None,
            'phasMolEntr[1]':None,
            'phasMolSpHeat[2]':None,
            'phasMolEnth[2]':None,
            'phasMolEntr[2]':None,
            'phasMolSpHeat[3]':None,
            'phasMolEnth[3]':None,
            'phasMolEntr[3]':None,
            'totMolFlo[2]':None,
            'totMasFlo[2]':None,
            'totMolFlo[3]':None,
            'totMasFlo[3]':None

        }

    def modesList(self):
        return ["PT","PH","PVF","TVF","PS"]   
    def paramgetter(self,mode):
        dict = {}
        if(mode=="PT"):
            self.mode1 = 'P'
            self.mode2 = 'T'
            dict = {self.mode2:None,self.mode1:None,"CompMolFrac":None,"MolFlow":None,"thermoPackage":None}
        elif(mode=="PH"):
            self.mode1 = 'P'
            self.mode2 = 'phasMolEnth[1]'
            dict = {self.mode1:None,self.mode2:None,"CompMolFrac":None,"MolFlow":None,"thermoPackage":None}
        elif(mode=="PVF"):
            self.mode1 = 'P'
            self.mode2 = 'vapPhasMolFrac'
            dict = {self.mode1:None,self.mode2:None,"CompMolFrac":None,"MolFlow":None,"thermoPackage":None}
        elif(mode=="TVF"):
            self.mode1 = 'T'
            self.mode2 = 'vapPhasMolFrac'
            dict = {self.mode1:None,self.mode2:None,"CompMolFrac":None,"MolFlow":None,"thermoPackage":None}
        elif(mode=="PS"):
            self.mode1 = 'P'
            self.mode2 = 'phasMolEntr[1]'
            dict = {self.mode1:None,self.mode2:None,"CompMolFrac":None,"MolFlow":None,"thermoPackage":None}
        
        return dict
    def paramsetter(self,dict):
        self.mode1val = dict[self.mode1]
        self.mode2val = dict[self.mode2]
        self.MolFlow = dict['MolFlow']
        self.CompMolFrac = dict['CompMolFrac'].split(",")
        self.thermoPackage = dict['thermoPackage']
        self.Prop['totMolFlo[1]'] = self.MolFlow
        self.Prop[self.mode2] = dict[self.mode2]
        self.Prop[self.mode1] = dict[self.mode1]
        for i in range(len(self.CompNames)):
            print('####### compmolfrac #########\n',self.CompMolFrac[i])
            if self.CompMolFrac:
                self.Prop['compMolFrac[1,'+str(i+1)+']'] = self.CompMolFrac[i]
            else:
                self.Prop['compMolFrac[1,'+str(i+1)+']'] = None

            if self.CompMasFrac:
                self.Prop['compMasFrac[1,'+str(i+1)+']'] = self.CompMasFrac[i]
            else:
                self.Prop['compMasFrac[1,'+str(i+1)+']'] = None
            self.Prop['compMolFlo[1,'+str(i+1)+']'] = None
            self.Prop['compMasFlo[1,'+str(i+1)+']'] = None
        for i in range(0,len(self.CompNames)):
            self.Prop['compMolFrac[2,'+str(i+1)+']'] = None
            self.Prop['compMasFrac[2,'+str(i+1)+']'] = None
            self.Prop['compMolFlo[2,'+str(i+1)+']'] = None
            self.Prop['compMasFlo[2,'+str(i+1)+']'] = None
            self.Prop['compMolFrac[3,'+str(i+1)+']'] = None
            self.Prop['compMasFrac[3,'+str(i+1)+']'] = None
            self.Prop['compMolFlo[3,'+str(i+1)+']'] = None
            self.Prop['compMasFlo[3,'+str(i+1)+']'] = None
            
    def GetMinEqnValues(self):
        compmolfraclist = []
        for i in range(0,len(self.CompNames)):
            print(self.Prop['compMolFrac[1,'+str(i+1)+']'])
            compmolfraclist.append(self.Prop['compMolFrac[1,'+str(i+1)+']'])
        print(compmolfraclist)
        #compmolfraclist = list(self.Prop(compMolFrac[1,1)])
        compmolfrac = json.dumps(compmolfraclist)
        print(compmolfrac)
        compmolfrac = compmolfrac.replace('[','{')
        compmolfrac = compmolfrac.replace(']','}')
        compmolfrac = compmolfrac.replace('"','')
        '''
        compmolfracstr = json.dumps(self.CompMolFrac)
        compmolfracstr = compmolfracstr.replace('[','{')
        compmolfracstr = compmolfracstr.replace(']','}')
        compmolfracstr = compmolfracstr.replace('"','')
        '''
        if self.Prop[self.mode1]:
            self.eqnDict[self.mode1] = self.Prop[self.mode1]
        if self.Prop[self.mode2]:
            self.eqnDict[self.mode2] = self.Prop[self.mode2]
        if self.CompMolFrac:
            self.eqnDict['compMolFrac[1,:]'] = compmolfrac
        if self.MolFlow:
            self.eqnDict['totMolFlo[1]'] = self.Prop['totMolFlo[1]']#self.MolFlow

        print("##############$GetMinVEqnValuesStart$##################")
        print("P:",self.Prop[self.mode1])
        print("T:",self.Prop[self.mode2])
        print("CompMolFrac",compmolfrac)
        print("totMolFlo",self.Prop['totMolFlo[1]'])
        print("##############$GetMinVEqnValuesEnd$##################")

    def GetEquationValues(self):
        if self.Prop[self.mode1]:
            self.eqnDict[self.mode1] = self.Prop[self.mode1]
        
        if self.Prop[self.mode2]:
            self.eqnDict[self.mode2] = self.Prop[self.mode2]
        
        if self.Prop['compMolFrac[1,1]']:
            cfa = []
            for i in range(1,len(self.CompNames)+1):
                cfa.append(self.Prop['compMolFrac[1,'+str(i)+']'])
            cmpMolFracstr = json.dumps(cfa)
            cmpMolFracstr = cmpMolFracstr.replace('[','{')
            cmpMolFracstr = cmpMolFracstr.replace(']','}')
            cmpMolFracstr = cmpMolFracstr.replace('"','')
            self.eqnDict['compMolFrac[1,:]'] = cmpMolFracstr
        
        if self.Prop['totMolFlo[1]']:
            self.eqnDict['totMolFlo[1]'] = self.Prop['totMolFlo[1]']


    def GetStartValues(self):
        try:
            if self.Prop[self.mode1]:
                self.startDict[self.mode1] = self.Prop[self.mode1]
            
            if self.Prop[self.mode2]:
                self.startDict[self.mode2] = self.Prop[self.mode2]
            

            if self.Prop['compMolFrac[2,1]'] != None:
                compMolFracarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.Prop['compMolFrac['+str(i)+','+str(j)+']']))
                    compMolFracarr.append(cmf)
                compMolFracstr = json.dumps(compMolFracarr)
                compMolFracstr = compMolFracstr.replace('[','{')
                compMolFracstr = compMolFracstr.replace(']','}')
                compMolFracstr = compMolFracstr.replace('"','')
                self.startDict['compMolFrac'] = compMolFracstr

            if self.Prop['compMasFrac[2,1]'] != None:
                compMasFracarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.Prop['compMasFrac['+str(i)+','+str(j)+']']))
                    compMasFracarr.append(cmf)
                compMasFracstr = json.dumps(compMolFracarr)
                compMasFracstr = compMasFracstr.replace('[','{')
                compMasFracstr = compMasFracstr.replace(']','}')
                compMasFracstr = compMasFracstr.replace('"','')
                self.startDict['compMasFrac'] = compMasFracstr

            if self.Prop['compMasFlo[2,1]'] != None:
                compMasFloarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.Prop['compMasFlo['+str(i)+','+str(j)+']']))
                    compMasFloarr.append(cmf)
                compMasFlostr = json.dumps(compMolFracarr)
                compMasFlostr = compMasFlostr.replace('[','{')
                compMasFlostr = compMasFlostr.replace(']','}')
                compMasFlostr = compMasFlostr.replace('"','')
                self.startDict['compMasFlo'] = compMasFlostr

            if self.Prop['compMolFlo[2,1]'] != None:
                compMolFloarr = []
                for i in range(1,4):
                    cmf = []
                    for j in range(1,len(self.CompNames)+1):
                        cmf.append(str(self.Prop['compMolFlo['+str(i)+','+str(j)+']']))
                    compMolFloarr.append(cmf)
                compMolFlostr = json.dumps(compMolFloarr)
                compMolFlostr = compMolFlostr.replace('[','{')
                compMolFlostr = compMolFlostr.replace(']','}')
                compMolFlostr = compMolFlostr.replace('"','')
                self.startDict['compMolFlo'] = compMolFlostr

            if self.Prop['MW[2]'] != None:
                MWArr = []
                for i in range(1,4):
                    MWArr.append(self.Prop['MW['+str(i)+']'])
                MWStr = json.dumps(MWArr)
                MWStr = MWStr.replace('[','{')
                MWStr = MWStr.replace(']','}')
                MWStr = MWStr.replace('"','')
                self.startDict['MW'] = MWStr

            if self.Prop['totMolFlo[2]'] != None:
                totMolFloArr = []
                for i in range(1,4):
                    totMolFloArr.append(self.Prop['totMolFlo['+str(i)+']'])
                totMolFloStr = json.dumps(totMolFloArr)
                totMolFloStr = totMolFloStr.replace('[','{')
                totMolFloStr = totMolFloStr.replace(']','}')
                totMolFloStr = totMolFloStr.replace('"','')
                self.startDict['totMolFlo'] = totMolFloStr

            if self.Prop['phasMolSpHeat[2]'] != None:
                phasMolSpHeatArr = []
                for i in range(1,4):
                    phasMolSpHeatArr.append(self.Prop['phasMolSpHeat['+str(i)+']'])
                phasMolSpHeatStr = json.dumps(phasMolSpHeatArr)
                phasMolSpHeatStr = phasMolSpHeatStr.replace('[','{')
                phasMolSpHeatStr = phasMolSpHeatStr.replace(']','}')
                phasMolSpHeatStr = phasMolSpHeatStr.replace('"','')
                self.startDict['phasMolSpHeat'] = phasMolSpHeatStr

            if self.Prop['phasMolEnth[2]'] != None:
                phasMolEnthArr = []
                for i in range(1,4):
                    phasMolEnthArr.append(self.Prop['phasMolEnth['+str(i)+']'])
                phasMolEnthStr = json.dumps(phasMolEnthArr)
                phasMolEnthStr = phasMolEnthStr.replace('[','{')
                phasMolEnthStr = phasMolEnthStr.replace(']','}')
                phasMolEnthStr = phasMolEnthStr.replace('"','')
                self.startDict['phasMolEnth'] = phasMolEnthStr


            if self.Prop['phasMolEntr[2]'] != None:
                phasMolEntrArr = []
                for i in range(1,4):
                    phasMolEntrArr.append(self.Prop['phasMolEntr['+str(i)+']'])
                phasMolEntrStr = json.dumps(phasMolEntrArr)
                phasMolEntrStr = phasMolEntrStr.replace('[','{')
                phasMolEntrStr = phasMolEntrStr.replace(']','}')
                phasMolEntrStr = phasMolEntrStr.replace('"','')
                self.startDict['phasMolEntr'] = phasMolEntrStr

            if self.Prop['totMasFlo[2]'] != None:
                totMasFloArr = []
                for i in range(1,4):
                    totMasFloArr.append(self.Prop['totMasFlo['+str(i)+']'])
                totMasFloStr = json.dumps(totMasFloArr)
                totMasFloStr = totMasFloStr.replace('[','{')
                totMasFloStr = totMasFloStr.replace(']','}')
                totMasFloStr = totMasFloStr.replace('"','')
                self.startDict['totMasFlo'] = totMasFloStr

        except Exception as e:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            print(exc_type,exc_tb.tb_lineno)
            print(e)
            print('error')

        # self.OMVapProp = {
        #     'Pressure': self.mode1,
        #     'Temperature': self.mode2,
        #     'Total Molar Flow': 'totMolFlo[3]',
        #     'Total Mas Flow': 'totMasFlo[3]',
        #     'Comp Mole Fraction': ['compMolFrac[3,1]','compMolFrac[3,2]','compMolFrac[3,3]'],
        #     'Comp Mas Fraction': ['compMasFrac[3,1]','compMasFrac[3,2]','compMasFrac[3,3]'],
        #     'Comp Molar Flow': ['compMolFlo[3,1]','compMolFlo[3,2]','compMolFlo[3,3]'],
        #     'Comp Mas Flow': ['compMasFlo[3,1]','compMasFlo[3,2]','compMasFlo[3,3]'],
        #     'Av. Molecular Weight': 'phasMolEnth[3]',
        #     'Molar Specific Heat': 'phasMolSpHeat[3]',
        #     'Molar Enthalpy': 'phasMolEnth[3]',
        #     'Molar Entropy': 'phasMolEntr[3]'}



        # self.VapProp = {
        #     self.mode1:None,
        #     self.mode2:None,
        #     'liqPhasMolFrac':None,
        #     'liqPhasMasFrac':None,
        #     'vapPhasMolFrac':None,
        #     'vapPhasMasFrac':None,
        #     'totMolFlo[3]':None,
        #     'totMasFlo[3]':None,
        #     'MW[1]':None,
        #     'compMolFrac[3,1]':None,
        #     'compMolFrac[3,2]':None,
        #     'compMolFrac[3,3]':None,
        #     'compMasFrac[3,1]':None,
        #     'compMasFrac[3,2]':None,
        #     'compMasFrac[3,3]'None,
        #     'compMolFlo[3,1]':None,
        #     'compMolFlo[3,2]':None,
        #     'compMolFlo[3,3]':None,
        #     'compMasFlo[3,1]':None,
        #     'compMasFlo[3,2]':None,
        #     'compMasFlo[3,3]':None,
        #     'phasMolSpHeat[3]':None,
        #     'phasMolEnth[3]':None,
        #     'phasMolEntr[3]':None
        #     }


        # self.OMLiqProp = {
        #     'Pressure': self.mode1,
        #     'Temperature': self.mode2,
        #     'Total Molar Flow': 'totMolFlo[2]',
        #     'Total Mas Flow': 'totMasFlo[2]',
        #     'Comp Mole Fraction': ['compMolFrac[2,1]','compMolFrac[2,2]','compMolFrac[2,3]'],
        #     'Comp Mas Fraction': ['compMasFrac[2,1]','compMasFrac[2,2]','compMasFrac[2,3]'],
        #     'Comp Molar Flow': ['compMolFlo[2,1]','compMolFlo[2,2]','compMolFlo[2,3]'],
        #     'Comp Mas Flow': ['compMasFlo[2,1]','compMasFlo[2,2]','compMasFlo[2,3]'],
        #     'Av. Molecular Weight': 'MW[2]',
        #     'Molar Specific Heat': 'phasMolSpHeat[2]',
        #     'Molar Enthalpy': 'phasMolEnth[2]',
        #     'Molar Entropy': 'phasMolEntr[2]'}


        # self.LiqProp = {
        #     self.mode1:P,
        #     self.mode2:None,
        #     'liqPhasMolFrac':None,
        #     'liqPhasMasFrac':None,
        #     'vapPhasMolFrac':None,
        #     'vapPhasMasFrac':None,
        #     'totMolFlo[2]':None,
        #     'totMasFlo[2]':None,
        #     'MW[1]':None,
        #     'compMolFrac[2,1]':None,
        #     'compMolFrac[2,2]':None,
        #     'compMolFrac[2,3]':None,
        #     'compMasFrac[2,1]':None,
        #     'compMasFrac[2,2]':None,
        #     'compMasFrac[2,3]'None,
        #     'compMolFlo[2,1]':None,
        #     'compMolFlo[2,2]':None,
        #     'compMolFlo[2,3]':None,
        #     'compMasFlo[2,1]':None,
        #     'compMasFlo[2,2]':None,
        #     'compMasFlo[2,3]':None,
        #     'phasMolSpHeat[2]':None,
        #     'phasMolEnth[2]':None,
        #     'phasMolEntr[2]':None
        #     }

    def OM_Flowsheet_Init(self,addedcomp):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + ("model ms"+str(self.count)+"\n")
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Streams.Material_Stream;\n" )
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Files.Thermodynamic_Packages."+self.thermoPackage+";\n")
        self.OM_data_init = self.OM_data_init + ("end ms"+str(self.count)+";\n")
        comp_count = len(addedcomp)
        self.GetStartValues()

        #self.OM_data_init = "Simulator.Streams.Mat_Stm_RL " + self.name +"(NOC = " + str(comp_count)
        self.OM_data_init = self.OM_data_init + "ms"+str(self.count) +" " + self.name +"(NOC = " + str(comp_count)
        self.OM_data_init = self.OM_data_init + ",comp = {"
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'","")
        self.OM_data_init = self.OM_data_init + comp + "},"
        #for key, value in self.startDict.items():
        #    self.OM_data_init = self.OM_data_init + key + '(start = ' + str(value) + '),'
        self.OM_data_init = self.OM_data_init[:-1]
        self.OM_data_init = self.OM_data_init + ');\n'        
        return self.OM_data_init


    def OM_Flowsheet_Eqn(self,addedcomp,method):
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

      
        # if self.P:
        #     self.OM_data_eqn = self.OM_data_eqn + (self.name + '.P=' + str(self.P) + ';\n')
        # if self.T:
        #     self.OM_data_eqn = self.OM_data_eqn + (self.name + '.T=' + str(self.T) + ';\n')
        # if self.VapPhasMolFrac:
        #     self.OM_data_eqn = self.OM_data_eqn + (self.name + '.vapPhasMolFrac=' + str(self.VapPhasMolFrac) + ';\n')
        

        # if self.CompMolFrac != []:
        #     self.OM_data_eqn = self.OM_data_eqn + (self.name + ".compMolFrac[1,:] = {")
        #     mf = str(self.CompMolFrac).strip('[').strip(']')
        #     self.OM_data_eqn = self.OM_data_eqn + mf + ('};\n')
        # if self.CompMasFrac != []:
        #     self.OM_data_eqn = self.OM_data_eqn + (self.name + ".compMasFrac[1,:] = {")
        #     Mf = str(self.CompMasFrac).strip('[').strip(']')
        #     self.OM_data_eqn = self.OM_data_eqn + Mf + ('};\n')
        
        # if self.MolFlow:
        #     self.OM_data_eqn = self.OM_data_eqn + (self.name + ".totMolFlo[1] = " + str(self.MolFlow) + ";\n")
        # if self.MasFlow:
        #     self.OM_data_eqn = self.OM_data_eqn + (self.name + ".totMasFlo[1] = " + str(self.MasFlow) + ";\n")

        # return self.OM_data_eqn