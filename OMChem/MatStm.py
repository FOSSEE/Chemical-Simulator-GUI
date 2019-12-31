from OMPython import OMCSession
import json
import sys
from collections import defaultdict

class MatStm():
    counter = 1;
    def __init__(self,CompNames = [],Temperature=300,Pressure=101325,VapPhasMolFrac=None,VapPhasMasFrac=None,LiqPhasMolFrac=None,LiqPhasMasFrac=None,CompMolFrac = [1.0], CompMasFrac = [], MolFlow=100, MasFlow=None,**kwargs):
        self.name = 'MatStm' + str(MatStm.counter)
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
        self.count = MatStm.counter
        self.thermoPackage ="Raoults_Law"
        self.mode1 = "P"
        self.mode1val = ""
        self.mode2 = "T"
        self.mode2val = ""
        self.no_of_inputs = 1
        self.no_of_outputs = 1
        self.x = 2500-30
        self.y = 2500-30
        MatStm.counter+=1
        self.startDict = {}
        self.eqnDict = {}
        self.modesList = ["PT","PH","PVF","TVF","PS"]
        

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

      