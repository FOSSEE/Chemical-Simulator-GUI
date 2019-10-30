class Mixer():
    def __init__(self,name='mixer',NOI=5,Pcal = 'Inlet_Average'):
        self.NOI = NOI
        self.Pcal = Pcal
        self.name = name
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = []
        self.OutputStms = None
        self.type = 'Mixer'

    def modesList(self):
        return []   

    def paramgetter(self,mode=None):
        dict = {}
        return dict
    def paramsetter(self,dict):
        self.NOI = dict["NOI"]
    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        comp_count = len(addedcomp)
        
        self.OM_data_init = self.OM_data_init + (
        "Simulator.Unit_Operations.Mixer " + self.name + "(NOC = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (",comp = {")
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("},")
        self.OM_data_init = self.OM_data_init + ("outPress = \""+self.Pcal+"\",NI=" + str(self.NOI) + ");\n")
        return self.OM_data_init

    def connect(self,InputStms = [],OutputStms = None):
        self.NOI=len(InputStms)
        self.InputStms = InputStms
        self.OutputStms = OutputStms


    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        comp_count = len(addedcomp)
        strcount = 1
        for strm in self.InputStms:
            self.OM_data_eqn = self.OM_data_eqn + (
            'connect(' + strm.name + '.outlet,' + self.name + '.inlet[' + str(strcount) + ']);\n')
            strcount += 1
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.outlet,' + self.OutputStms[0].name + '.inlet);\n')
        return self.OM_data_eqn

