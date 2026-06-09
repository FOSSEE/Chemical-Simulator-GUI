class Mixer():
    counter = 1

    def __init__(self, name='Mixer', NOI=2, Pcal='Inlet_Average'):
        self.NOI = NOI
        self.Pcal = Pcal
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = []
        self.OutputStms = []
        self.type = 'Mixer'

        # Auto-increment name
        self.name = f"{name}{Mixer.counter}"
        self.no_of_input = 2
        self.no_of_output = 1
        Mixer.counter += 1

    def getname(self):
        return self.name

    def modesList(self):
        return []

    def paramgetter(self, mode=None):
        return {}

    def paramsetter(self, params):
        if "NOI" in params:
            self.NOI = params["NOI"]

    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        comp_count = len(addedcomp)
        comp_str = ', '.join(addedcomp)
        self.OM_data_init += (
            f"Simulator.UnitOperations.Mixer {self.name}(Nc = {comp_count}, C = {{{comp_str}}}, "
            f"outPress = \"{self.Pcal}\", NI = {self.NOI});\n"
        )
        return self.OM_data_init

    def connect(self, InputStms=None, OutputStms=None):
        if InputStms is None:
            InputStms = []
        if OutputStms is None:
            OutputStms = []
        self.NOI = len(InputStms)
        self.InputStms = InputStms
        self.OutputStms = OutputStms

    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        strcount = 1

        # Connect input streams safely
        for strm in self.InputStms:
            if strm and hasattr(strm, 'name'):
                self.OM_data_eqn += f'connect({strm.name}.Out, {self.name}.In[{strcount}]);\n'
                strcount += 1

        # Connect output stream safely
        if self.OutputStms and len(self.OutputStms) > 0:
            out_stream = self.OutputStms[0]
            if out_stream and hasattr(out_stream, 'name'):
                self.OM_data_eqn += f'connect({self.name}.Out, {out_stream.name}.In);\n'

        return self.OM_data_eqn
