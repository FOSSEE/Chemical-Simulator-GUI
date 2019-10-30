class Flash():
    def __init__(self,name=("flash",1)):
        self.name = name[0]
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = None
        self.OutputStms = None
        self.type = 'flash'
        self.count = name[1]
        self.thermoPackage =None
    def connect(self,InputStms = None,OutputStms = None):
        self.InputStms = InputStms
        self.OutputStms = OutputStms

    def modesList(self):
        return []   

    def paramgetter(self,mode=None):
        dict = {"thermoPackage":None}
        return dict
    def paramsetter(self,dict):
        self.thermoPackage = dict['thermoPackage']

    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + ("model fls"+str(self.count)+"\n")
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Unit_Operations.Flash;\n" )
        self.OM_data_init = self.OM_data_init + ("extends Simulator.Files.Thermodynamic_Packages."+self.thermoPackage+";\n")
        self.OM_data_init = self.OM_data_init + ("end fls"+str(self.count)+";\n")
        comp_count = len(addedcomp)
        self.OM_data_init = self.OM_data_init + (
        "fls"+str(self.count)+" "+ self.name + "(NOC = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (",comp = {")
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("});\n")
        return self.OM_data_init

    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        comp_count = len(addedcomp)
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.InputStms[0].name + '.outlet,' + self.name + '.feed' + ');\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.vapor,' + self.OutputStms[0].name + '.inlet);\n')
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.name + '.liquid,' + self.OutputStms[1].name + '.inlet);\n')
        return self.OM_data_eqn