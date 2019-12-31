#  This file can be deleted

# from OMChem.EngStm import EngStm

# class UnitOpr():
  
#   def __init__(self,name,counter,Type,parameters={},mode=None,modeVal=None,ThermoPackReq = False,thermoPack = None,extra=[], multidict=[],inputs=1,outputs=1):
#       self.OM_data_eqn = ''
#       self.OM_data_init = ''
#       self.InputStms = []
#       self.OutputStms = []
#       self.EngStms = EngStm(name='EngStm'+name)
#       self.name = name
#       self.mode = mode
#       self.modeVal = modeVal
#       self.thermoPack = thermoPack
#       self.extra = extra
#       self.multidict = multidict
#       self.type = Type
#       self.ForNaming = extra
#       self.no_of_inputs = inputs
#       self.no_of_outputs = outputs
#       self.counter=counter
#       self.parameters = parameters
#       self.ThermoPackReq = ThermoPackReq
      





#   # def connect(self,InputStms = [],OutputStms = []):
#   #     self.InputStms = InputStms
#   #     self.OutputStms = OutputStms
#   #     print('INPUT')
#   #     print(InputStms)
#   #     print('OUTPUT')
#   #     print(OutputStms)

      


#   def OM_Flowsheet_Initialize(self,addedcomp):
#     self.OM_data_init = ''

#     if(self.ThermoPackReq):
#       if len(self.extra)>1:
#         for i in range(self.extra):
#           latest = ''
#           for j in range(self.extra[i]):
#             if self.extra[i][j]!='.':
#               latest += self.extra[i][j]
#             self.ForNaming[i] = latest   



#     if(self.ThermoPackReq):
#       if len(self.extra)==1:
#         for i in self.extra:
#           self.OM_data_init += ('model '+i+str(self.counter)+'\n')
#           self.OM_data_init += ('extends Simulator.Unit_Operations.'+i+';\n')
#           self.OM_data_init += ('extends Simulator.Files.Thermodynamic_Packages.'+self.thermoPack+';\n')
#           self.OM_data_init += ('end '+i+str(self.counter)+';\n')

#           self.OM_data_init += i+str(self.counter) + ' ' + self.name + '(NOC = ' + str(len(addedcomp)) 

#       else:
#         for i in range(len(self.extra)):
#           if i!=(len(self.extra)-1):
#             self.OM_data_init += ('model '+self.ForNaming[i]+str(self.counter)+'\n')
#             self.OM_data_init += ('extends Simulator.Unit_Operations.'+self.extra[i]+';\n')
#             self.OM_data_init += ('extends Simulator.Files.Thermodynamic_Packages.'+self.thermoPack+';\n')
#             self.OM_data_init += ('end '+self.ForNaming[i]+str(self.counter)+';\n')
#           else:
#             self.OM_data_init += ('model '+self.ForNaming[i]+str(self.counter)+'\n')
#             self.OM_data_init += ('extends Simulator.Unit_Operations.'+self.extra[i]+';\n')
#             for j in range(len(self.extra)-1):
#               self.OM_data_init += (self.ForNaming[j] + str(self.counter) +' ' + self.ForNaming[j] + '#' + self.multidict[j] + ';\n')

#               self.OM_data_init += ('end '+self.ForNaming[i]+str(self.counter)+';\n')

#           self.OM_data_init += self.ForNaming[i] + str(self.counter) + ' ' + self.ForNaming + '(NOC = ' + str(len(addedcomp))
         
#       comp = str(addedcomp).strip('[').strip(']')
#       comp = comp.replace("'", "")  
#       self.OM_data_init += ',comp = {' + comp + '}'

          
            
#       for k,v in self.parameters.items():
#         self.OM_data_init += ', '
#         self.OM_data_init += k + ' = ' + str(v)
#         self.OM_data_init += ');\n' 

#     else: 
#       self.OM_data_init += 'Simulator.Unit_Operations.' + self.type + ' ' + self.name + '(NOC = ' + str(len(addedcomp))
#       comp = str(addedcomp).strip('[').strip(']')
#       comp = comp.replace("'", "")  
#       self.OM_data_init += ',comp = {' + comp + '}'

#       for k,v in self.parameters.items():
#         self.OM_data_init += ', '
#         self.OM_data_init += k + ' = ' + str(v)

#       self.OM_data_init += ');\n'

#         #print("HERE WE GO")
#         #print(self.OM_data_init)

#     return self.OM_data_init  




#   def OM_Flowsheet_Equation(self,addedcomp):
#     self.OM_data_eqn = ''

#     if len(self.InputStms)>1:
#       strcount = 1
#       for strm in self.InputStms:
#         self.OM_data_eqn += ('connect(' + strm.name + '.outlet,' + self.name + '.inlet[' + str(strcount) + ']);\n')
#         strcount += 1
#     else:
#       self.OM_data_eqn += ('connect(' + self.name + '.inlet,' + self.InputStms[0].name + '.outlet);\n')

#     if len(self.OutputStms)>1:
#       strcount = 1
#       for strm in self.OutputStms:
#         self.OM_data_eqn += ('connect(' + strm.name + '.inlet,' + self.name + '.outlet[' + str(strcount) + ']);\n')
#         strcount += 1
#     else:
#       self.OM_data_eqn += ('connect(' + self.name + '.outlet,' + self.OutputStms[0].name + '.inlet);\n')    
    
#     if self.mode:
#       self.OM_data_eqn += (self.name + '.' + self.mode + '=' + self.modeVal + ';\n')    

#     return self.OM_data_eqn








            
              


              
              


        


