from OMChem.EngStm import EngStm
class DistCol():
    counter = 1
    def __init__(self,name='DistCol', numStage = None,numFeeds = None,feedStages = None):
        self.numStage = numStage
        self.numFeeds=numFeeds
        self.feedStages=feedStages
        #self.name = name[0]
        self.name = name + str(DistCol.counter) 
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = None
        self.OutputStms = None
        self.EngStm1 = EngStm(name='EngStm1'+self.name)
        self.EngStm2 = EngStm(name='EngStm2'+self.name)
        #self.count = name[1]
        self.count = DistCol.counter
        self.thermoPackage='Raoults_Law'
        self.type = 'DistCol'
        self.mode = None
        self.condType=''
        self.modeVal = None
        self.condP=None
        self.rebP=None

        # new 
        self.no_of_input = 2 
        self.no_of_output = 2  
        DistCol.counter += 1  

    def getname(self):
        return self.name

    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms

    def modesList(self):
        return ["refluxRatio","sideDrawMolFlo","T"]

    def paramgetter(self,mode="refluxRatio"):
        self.mode=mode
        dict = { "numStage" : None,"numFeeds" :None,"feedStages" :None,"thermoPackage":None,"condType":None,self.mode:None,"condensor.P":None,"reboiler.P":None}
        return dict
        
    def paramsetter(self,dict):
        self.numStage = dict["numStage"]
        self.numFeeds = dict["numFeeds"]
        self.feedStages = dict["feedStages"].split(",")
        self.modeVal=dict[self.mode]
        self.condP=dict["condensor.P"]
        self.rebP=dict["reboiler.P"]
        self.condType=dict["condType"]
  
    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + 'model Condensor\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.Unit_Operations.Distillation_Column.Cond;\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.Files.Thermodynamic_Packages.'+self.thermoPackage+';\n'
        self.OM_data_init = self.OM_data_init + 'end Condensor;\n'
        self.OM_data_init = self.OM_data_init + 'model Tray\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.Unit_Operations.Distillation_Column.DistTray;\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.Files.Thermodynamic_Packages.'+self.thermoPackage+';\n'
        self.OM_data_init = self.OM_data_init + 'end Tray;\n'
        self.OM_data_init = self.OM_data_init + 'model Reboiler\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.Unit_Operations.Distillation_Column.Reb;\n'
        self.OM_data_init = self.OM_data_init + 'extends Simulator.Files.Thermodynamic_Packages.'+self.thermoPackage+';\n'
        self.OM_data_init = self.OM_data_init + 'end Reboiler;\n'
        self.OM_data_init = self.OM_data_init + ("model distCol"+str(self.count)+"\n")
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Unit_Operations.Distillation_Column.DistCol;\n" )
        self.OM_data_init = self.OM_data_init + ("Condensor condensor(Nc = Nc, comp = comp, condType =condType, boolFeed = boolFeed[1], T(start = 300));\n" )
        self.OM_data_init = self.OM_data_init + ("Reboiler reboiler(Nc = Nc, comp = comp, boolFeed = boolFeed[noOfStages]);\n" )
        self.OM_data_init = self.OM_data_init + ("Tray tray[noOfStages - 2](each Nc = Nc, each comp = comp, boolFeed = boolFeed[2:noOfStages -1]);\n" )
        self.OM_data_init = self.OM_data_init + ("end distCol"+str(self.count)+";\n")
        comp_count = len(addedcomp)
        self.OM_data_init = self.OM_data_init + (
        "distCol"+str(self.count)+" "+ self.name + "(Nc = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (",comp = {")
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.feedStages=str(self.feedStages).strip('[').strip(']')
        self.feedStages = self.feedStages.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("},")+("noOfStages="+self.numStage+","+"noOfFeeds="+self.numFeeds+",feedStages="+"{"+self.feedStages+"}"+",condensor.condType="+"\""+self.condType+"\""+");\n")
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStm1.name+';\n'
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStm2.name+';\n'
        return self.OM_data_init

    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        # self.OM_data_eqn = self.name + '.pressDrop = ' + str(self.PressDrop) + ';\n'
        self.OM_data_eqn = self.OM_data_eqn + ('connect('+self.name+'.'+'condensor_duty'+','+ self.EngStm1.name+'.inlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect('+self.name+'.reboiler_duty'+', '+self.EngStm2.name+'.inlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect('+self.name+'.distillate'+", "+self.OutputStms[0].name+'.inlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect('+self.name+'.bottoms'+", "+self.OutputStms[1].name+'.inlet);\n')
        for i in range(len(self.InputStms)):
            self.OM_data_eqn = self.OM_data_eqn + ('connect('+self.InputStms[i].name+'.outlet'+", "+self.name+'.feed['+str(i+1)+']);\n')
        self.OM_data_eqn = self.OM_data_eqn + (self.OutputStms[1].name+'.'+'totMolFlow[1] = '+str(self.OutputStms[1].Prop['totMolFlo[1]'])+';\n')
        if self.mode=="refluxRatio":
            self.OM_data_eqn = self.OM_data_eqn + (self.name+'.'+str(self.mode)+'='+ str(self.modeVal) + ';\n')
        else:
            self.OM_data_eqn = self.OM_data_eqn + (self.name+'.condensor.'+self.mode+'='+ str(self.modeVal) + ';\n')
        
        self.OM_data_eqn = self.OM_data_eqn + self.name +'.reboiler.P='+self.rebP+';\n'
        self.OM_data_eqn = self.OM_data_eqn + self.name +'.condensor.P='+self.condP+';\n'
        return self.OM_data_eqn
        
