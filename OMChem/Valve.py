class Valve():
    def __init__(self,name='valve'):
        #self.PressDrop = PressureDrop
        self.mode = None
        self.modeVal = None
        self.name = name
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = None
        self.OutputStms = None
        self.type = 'Valve'

        self.Prop = {
                'pressDrop':None,
                'outP':None
            }

    def modesList(self):
        return ["pressDrop","outP"]

    def paramgetter(self,mode="pressDrop"):
        self.mode = mode
        dict = {self.mode:None}
        return dict

    def paramsetter(self,dict):

        self.modeVal = dict[self.mode]      

    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms

    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        comp_count = len(addedcomp)
        self.OM_data_init = self.OM_data_init + (
        "Simulator.Unit_Operations.Valve " + self.name + "(NOC = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (",comp = {")
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("});\n")
        return self.OM_data_init

    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.InputStms[0].name + '.outlet,' +  self.name + '.inlet' + ');\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.outlet,' + self.OutputStms[0].name + '.inlet);\n')
        print("asdfvfdasdsqdfdedfdfv12345678987654321234567898765")
        self.OM_data_eqn = self.OM_data_eqn + (self.name+'.'+self.mode+'='+ self.modeVal + ';\n')
        return self.OM_data_eqn