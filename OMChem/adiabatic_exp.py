from OMChem.EngStm import EngStm
class AdiaExp():
    def __init__(self,name=('AdiaExp',1), eff = None):
        self.eff = eff
        self.name = name[0]
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = None
        self.OutputStms = None
        self.EngStms = EngStm(name='EngStm'+self.name)
        self.count = name[1]
        self.type = 'AdiaExp'
        self.thermoPackage ="Raoults_Law"
        self.mode = None
        self.modeVal = None

    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms

    def modesList(self):
        return ["pressDrop","outP","genPow"]

    def paramgetter(self,mode="pressDrop"):
        self.mode = mode
        dict = {"eff":None,self.mode:None,"thermoPackage":None}
        return dict
        
    def paramsetter(self,dict):
        self.eff = dict['eff']
        self.modeVal = dict[self.mode]

    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStms.name+';\n'
        self.OM_data_init = self.OM_data_init + ("model adiaComp"+str(self.count)+"\n")
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Unit_Operations.Adiabatic_Expander;\n" )
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Files.Thermodynamic_Packages."+self.thermoPackage+";\n")
        self.OM_data_init = self.OM_data_init + ("end adiaComp"+str(self.count)+";\n")
        comp_count = len(addedcomp)
        self.OM_data_init = self.OM_data_init + (
        "adiaComp"+str(self.count)+" "+ self.name + "(NOC = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (",comp = {")
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("},")+("eff="+self.eff+");\n")
        return self.OM_data_init

    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        # self.OM_data_eqn = self.name + '.pressDrop = ' + str(self.PressDrop) + ';\n'
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.InputStms[0].name + '.outlet,' +  self.name + '.inlet' + ');\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.outlet,' + self.OutputStms[0].name + '.inlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.EngStms.name + '.outlet,' + self.name + '.energy);\n')
  
        self.OM_data_eqn = self.OM_data_eqn + (self.name+'.'+self.mode+'='+ self.modeVal + ';\n')

        return self.OM_data_eqn
        
