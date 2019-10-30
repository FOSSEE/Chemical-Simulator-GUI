import json
from OMChem.EngStm import EngStm
class ConvReactor():
    def __init__(self,name='',Nr=None,b=None,X=None,Z=None,a=[],operation=None,Tdef=None):
        self.Nr = str(Nr)
        self.b = str(b)
        self.X = str(X)
        self.Z = str(Z)
        self.a = json.dumps(a).replace('[','{').replace(']','}')
        self.operation = str(operation)
        self.Tdef = str(Tdef)
        self.name = name
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = []
        self.OutputStms = []
        self.type = 'ConvReactor'
        self.EngStms = EngStms(name="EngStm")

    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        comp_count = len(addedcomp)
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStms.name+';\n'
        self.OM_data_init = self.OM_data_init + ( "Simulator.Unit_Operations.ConversionReactor " + self.name + "(Nr = " + self.Nr + ',b = ' + self.b + ',X = ' + self.X + ',Z = ' + self.Z + ',a = ' + self.a + ',operation = ' + self.operation + ',Tdef = ' + self.Tdef + ');\n')
        return self.OM_data_init

    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms


    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        comp_count = len(addedcomp)
        strcount = 1
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.InputStms[0].name + '.outlet,' + self.name + '.inlet' + ');\n')
            
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.OutputStms[0].name + '.inlet,' + self.name + '.outlet);\n')
            

        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.EngStms.name + '.inlet,' + self.name + '.EnergyStream);\n')

        return self.OM_data_eqn





































