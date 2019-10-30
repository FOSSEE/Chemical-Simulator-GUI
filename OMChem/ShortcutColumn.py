from OMChem.EngStm import EngStm
class ShortcutColumn():
    def __init__(self,name=("ShortcutCol",1),condP = None, rebP = None, LKey = None, HKey = None):
        self.condP = condP
        self.rebP = rebP
        self.LKey = LKey
        self.HKey = HKey
        self.LKeyMolFrac = None
        self.HKeyMolFrac = None
        self.name = name[0]
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = None
        self.OutputStms = None
        self.EngStm1 = EngStm(name='EngStm1'+self.name)
        self.EngStm2 = EngStm(name='EngStm2'+self.name)
        self.count = name[1]
        self.condType=''
        self.actR = None
        self.thermoPackage='Raoults_Law'
        self.type = 'ShortCol'

    def modesList(self):
        return []

    def paramgetter(self,mode=None):
        dict = { "HKey" : None,"LKey" :None,"HKeyMolFrac":None,"LKeyMolFrac":None,"condType":None,"thermoPackage":None,"condP":None,"rebP":None,"actR":None}
        return dict
        
    def paramsetter(self,dict):
        self.HKey = dict["HKey"]
        self.LKey = dict["LKey"]
        self.HKeyMolFrac = dict["HKeyMolFrac"]
        self.LKeyMolFrac=dict["LKeyMolFrac"]
        self.condP=dict["condP"]
        self.rebP=dict["rebP"]
        self.actR=dict["actR"]
        self.condType=dict["condType"]
        self.thermoPackage=dict["thermoPackage"]
    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms
    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + ("model sc"+str(self.count)+"\n")
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Unit_Operations.Shortcut_Column;\n" )
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Files.Thermodynamic_Packages."+self.thermoPackage+";\n")
        self.OM_data_init = self.OM_data_init + ("end sc"+str(self.count)+";\n")
        comp_count = len(addedcomp)
        self.OM_data_init = self.OM_data_init + "sc"+str(self.count)+ " " + self.name + "(NOC = " + str(comp_count)
        self.OM_data_init = self.OM_data_init + (",comp = {")
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("},")
        self.OM_data_init = self.OM_data_init + 'condType = ' + "\""+self.condType+"\""+','
        self.OM_data_init = self.OM_data_init + 'HKey = ' + str(self.HKey) +','
        self.OM_data_init = self.OM_data_init + 'LKey = ' + str(self.LKey)  + ');\n'
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStm1.name+';\n'
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStm2.name+';\n'
        return self.OM_data_init

    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
       
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.reboiler_duty,' +self.EngStm1.name +'.outlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.EngStm2.name+'.inlet,' + self.name + '.condenser_duty);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.distillate,' + self.OutputStms[0].name + '.inlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.bottoms,' + self.OutputStms[1].name + '.inlet);\n')
        
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.InputStms[0].name + '.outlet,' + self.name + '.feed);\n')
        self.OM_data_eqn = self.OM_data_eqn + self.name +'.rebP = ' + self.rebP + ';\n'
        self.OM_data_eqn = self.OM_data_eqn + self.name +'.condP = ' + self.condP + ';\n'
        self.OM_data_eqn = self.OM_data_eqn + self.name +'.mixMolFrac[2,'+self.name+'.LKey]='+self.LKeyMolFrac+ ';\n'
        self.OM_data_eqn = self.OM_data_eqn + self.name +'.mixMolFrac[3,'+self.name+'.HKey]='+self.HKeyMolFrac+ ';\n'
        self.OM_data_eqn = self.OM_data_eqn + self.name +'.actR=' + self.actR + ';\n'
        return self.OM_data_eqn