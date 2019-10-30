from OMChem.EngStm import EngStm
class Pump():
    def __init__(self,name='Pump',eff = None):
        self.eff = eff
        self.name = name
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = None
        #self.heatAdd=heatAdd
        #self.outT = outT
        self.OutputStms = None
        self.EngStms = EngStm(name='EngStm'+name)
        self.type = 'Pump'
        self.mode = None
        self.modeVal = None

    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms

    def modesList(self):
        return ["pressInc","outP","reqPow","enFlo"]

    def paramgetter(self,mode="pressInc"):
        self.mode = mode
        dict = {"eff":None,self.mode:None}
        return dict
        
    def paramsetter(self,dict):
        
        self.eff = dict['eff']
        self.modeVal = dict[self.mode]

    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        comp_count = len(addedcomp)
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStms.name+';\n'
        self.OM_data_init = self.OM_data_init + (
        "Simulator.Unit_Operations.Centrifugal_Pump " + self.name + "(NOC = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (",comp = {")
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("},")
        self.OM_data_init = self.OM_data_init + 'eff = ' + str(self.eff) + ');\n'
        return self.OM_data_init

    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        # self.OM_data_eqn = self.name + '.pressDrop = ' + str(self.PressDrop) + ';\n'
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.InputStms[0].name + '.outlet,' +  self.name + '.inlet' + ');\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.outlet,' + self.OutputStms[0].name + '.inlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.EngStms.name + '.outlet,' + self.name + '.energy);\n')

        if(self.mode =="enFlo"):
            self.OM_data_eqn = self.OM_data_eqn + (self.EngStms.name+'.'+self.mode+'='+ self.modeVal + ';\n')
        else:    
            self.OM_data_eqn = self.OM_data_eqn + (self.name+'.'+self.mode+'='+ self.modeVal + ';\n')
        return self.OM_data_eqn
