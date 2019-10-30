
class EngStm():
    
    def __init__(self,name = 'Engstm'):
        self.name = name
        self.type = 'EngStm'
        self.OM_data_init = ''
        self.OM_data_eqn = ''


    def OM_Flowsheet_Init(self,addedcomp):
        self.OM_data_init = ''
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.name+';\n'
        return self.OM_data_init

    def OM_Flowsheet_Eqn(self,addedcomp):
    	self.OM_data_eqn = ''
    	return self.OM_data_eqn
