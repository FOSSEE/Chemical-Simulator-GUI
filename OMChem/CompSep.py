from OMChem.EngStm import EngStm
import json
class CompSep():
    def __init__(self,CompNames = [],name='compoundseparator',SepFact=['Molar_Flow','Mass_Flow'],SepStrm=1,SepFactValue=[]):
        self.SepFact = json.dumps(SepFact).replace('[','{').replace(']','}')
        self.SepStrm = str(SepStrm)
        self.SepFactValue = json.dumps(SepFactValue).replace('[','{').replace(']','}')
        self.name = name
        self.OM_data_eqn = ''
        self.OM_data_init = ''
        self.InputStms = []
        self.OutputStms = []
        self.type = 'CompSep'
        self.EngStms = EngStm(name='EngStm')

    def modesList(self):
        return []   
    def paramgetter(self,mode=None):
        dict = {"SepStrm":None,"SepFactValue":None,"SepFact":None}
        return dict

    def paramsetter(self,dict):
        self.SepStrm = dict['SepStrm']
        self.SepFactValue = dict['SepFactValue']
        self.SepFact = dict['SepFact']

    def OM_Flowsheet_Init(self, addedcomp):
        self.OM_data_init = ''
        comp_count = len(addedcomp)
        self.OM_data_init = self.OM_data_init + 'Simulator.Streams.Energy_Stream '+self.EngStms.name+';\n'
        self.OM_data_init = self.OM_data_init + (
        "Simulator.Unit_Operations.Compound_Separator " + self.name + "(NOC = " + str(comp_count))
        self.OM_data_init = self.OM_data_init + (",comp = {")
        comp = str(addedcomp).strip('[').strip(']')
        comp = comp.replace("'", "")
        self.OM_data_init = self.OM_data_init + comp + ("},")
        self.OM_data_init = self.OM_data_init + ("sepFact = "+self.SepFact+",sepStrm = " + self.SepStrm + ", sepFactVal = " + self.SepFactValue + ");\n")

        return self.OM_data_init

    def connect(self,InputStms = None,OutputStms = []):
        self.InputStms = InputStms
        self.OutputStms = OutputStms


    def OM_Flowsheet_Eqn(self, addedcomp):
        self.OM_data_eqn = ''
        comp_count = len(addedcomp)
        strcount = 1
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.InputStms[0].name + '.outlet,' + self.name + '.inlet' + ');\n')
            
        for strm in self.OutputStms:
            self.OM_data_eqn = self.OM_data_eqn + ('connect(' + strm.name + '.inlet,' + self.name + '.outlet'+str(strcount)+');\n')
            strcount += 1
        
        self.OM_data_eqn = self.OM_data_eqn + ('connect(' + self.EngStms.name + '.outlet,' + self.name + '.energy);\n')
        sepFac = str(self.SepFactValue).strip('[').strip(']')

        self.OM_data_eqn = self.OM_data_eqn + (self.name+'.sepFactVal= {'+ sepFac + '};\n')
        

        return self.OM_data_eqn

