# from OMPython import OMCSession
import os
import csv
from subprocess import Popen, PIPE
#import subprocess
import pandas as pd

class Flowsheet():
	def __init__(self):
		self.sim_name = 'Simulator'
		self.sim_method = ''
		self.UnitOpn = []
		self.data = []
		self.compounds = []
		self.interface = ''
		self.omc_path = None
		self.curr_path = os.getcwd()
		self.sim_dir_path = os.path.join(self.curr_path, self.sim_name)
		self.Flomo_path = os.path.join(self.sim_dir_path,'Flowsheet.mo')
		self.eqn_mos_path = os.path.join(self.sim_dir_path,'simulateEQN.mos')
		self.sm_mos_path = os.path.join(self.sim_dir_path,'simulateSM.mos')
		self.resdata = []
		self.stdout=None
		self.stderr=None
	
	
	def get_omc_path(self):
		try:
		    self.omhome = os.environ.get('OPENMODELICAHOME')
		    if self.omhome is None:
		        self.omhome = os.path.split(os.path.split(os.path.realpath(spawn.find_executable("omc")))[0])[0]
		    elif os.path.exists('/opt/local/bin/omc'):
		        self.omhome = '/opt/local'
		    return os.path.join(self.omhome, 'bin', 'omc')
		except BaseException:
		    print("The OpenModelica compiler is missing in the System path please install it" )
		    raise

	def add_UnitOpn(self,unitop,flag):
                f=(unitop,flag)
                self.UnitOpn.append(f)
	def remove_UnitOpn(self,unitop):
		self.UnitOpn.remove(unitop)

	def add_comp_list(self,comp):
		self.compounds = comp
	

	def send_for_simulationEqn(self):
		self.resdata = []
		self.omc_path = self.get_omc_path()
		print(self.omc_path)

		if self.sim_method == 'Eqn':
			simpath = self.eqn_mos_path
			os.chdir(self.sim_dir_path)
			
			process = Popen([self.omc_path, '-s',simpath], stdout=PIPE, stderr=PIPE)
			self.stdout, self.stderr = process.communicate()
			#s = subprocess.check_output([self.omc_path, '-s',simpath])
			#print(s)
			#print("############### StdOut ################")
			print(self.stdout)
			os.chdir(self.curr_path)
			#os.system(self.omc_path + ' -s ' + simpath)
			print("Hello")
		if self.sim_method == 'Eqn':
			print("hhhh")
			csvpath = os.path.join(self.sim_dir_path,'Flowsheet_res.csv')
			print("csvPath",csvpath)
			with open (csvpath,'r') as resultFile:
				self.resdata = []
				print("opened")
				csvreader = csv.reader(resultFile,delimiter=',')
				for row in csvreader:
					print("124125")
					self.resdata.append(row)
			#self.ExtData()
	

	def send_for_simulationSM(self,unitop):

		self.resdata = []
		self.omc_path = self.get_omc_path()
		os.chdir(self.sim_dir_path)
		#os.system(self.omc_path + ' -s ' + unitop.name+'.mos')
		process = Popen([self.omc_path, '-s',unitop.name,'.mos'], stdout=PIPE, stderr=PIPE)
		stdout, stderr = process.communicate()
		#s = subprocess.check_output([self.omc_path, '-s',simpath])
		#print(s)
		print("############### StdOut ################")
		print(stdout)
		self.resdata = []
		print('Simulating '+unitop.name+'...')
		csvpath = os.path.join(self.sim_dir_path,unitop.name+'_res.csv')
		with open(csvpath,'r') as resultFile:
			csvreader = csv.reader(resultFile,delimiter=',')
			for row in csvreader:
				self.resdata.append(row)
		self.ExtData()

		

		

		# if self.sim_method == 'SM':
		# 	for unitop in self.UnitOpn:
		# 		self.resdata = []
		# 		if unitop.type != 'MatStm':
		# 			print 'Simulating '+unitop.name+'...'
		# 			csvpath = os.path.join(self.sim_dir_path,unitop.name+'_res.csv')
		# 			with open(csvpath,'r') as resultFile:
		# 				csvreader = csv.reader(resultFile,delimiter=',')
		# 				for row in csvreader:
		# 					self.resdata.append(row)
		# 			self.ExtData()


		
			

		# if self.interface == 'OMPython':
		# 	omc = OMCSession()
		# 	omc.sendExpression("loadModel(Modelica)")
		# 	omc.sendExpression("loadFile(\"Simulator.mo\")")
		# 	omc.sendExpression("loadFile(\"Flowsheet.mo\")")
		# 	execsim = omc.sendExpression("simulate(Flowsheet, outputFormat=\"csv\", stopTime=1.0, numberOfIntervals=1)")
		
		# else:
		# 	os.system(self.omc_path + ' -s  ')

	def ExtData(self):
		for unit in self.UnitOpn:
			if unit[0].type == 'MatStm':
#
				for key, value in unit[0].Prop.items():

				
					propertyname = unit[0].name + '.' + key
					if propertyname in self.resdata[0]:
						ind = self.resdata[0].index(propertyname)
						resultval = str(self.resdata[-1][ind])
		 				#resultval = str(omc.sendExpression("val("+unit.name+ "." + value + ", 0.5)"))
						print(resultval)
						unit[0].Prop[key] = resultval
				#print(unit[0].Prop)
			# 		else:
			# 			for v in value:
			# 				propertyname = unit.name + '.' + v
			# 				if propertyname in self.resdata[0]:
			# 					ind = self.resdata[0].index(propertyname)
			# 					resultval = str(self.resdata[-1][ind])
			# # 					resultval = str(omc.sendExpression("val("+unit.name+ "." + v + ", 0.5)"))
			# 					unit.Prop[key][i] = resultval
			# 					i = i + 1

			# 	for key, value in unit.OMVapProp.iteritems():
			# 		i = 0

			# 		if type(value) is str:
			# 			propertyname = unit.name + '.' + value
			# 			if propertyname in self.resdata[0]:
			# 				ind = self.resdata[0].index(propertyname)
			# 				resultval = str(self.resdata[-1][ind])
			# # 				resultval = str(omc.sendExpression("val("+unit.name+ "." + value + ", 0.5)"))
			# 				unit.VapProp[key] = resultval
			# 		else:
			# 			for v in value:
			# 				propertyname = unit.name + '.' + v
			# 				if propertyname in self.resdata[0]:
			# 					ind = self.resdata[0].index(propertyname)
			# 					resultval = str(self.resdata[-1][ind])
			# # 					resultval = str(omc.sendExpression("val("+unit.name+ "." + v + ", 0.5)"))
			# 					unit.VapProp[key][i] = resultval
			# 					i = i + 1


			# 	for key, value in unit.OMLiqProp.iteritems():
			# 		i = 0

			# 		if type(value) is str:
			# 			propertyname = unit.name + '.' + value
			# 			if propertyname in self.resdata[0]:
			# 				ind = self.resdata[0].index(propertyname)
			# 				resultval = str(self.resdata[-1][ind])
			# # 				resultval = str(omc.sendExpression("val("+unit.name+ "." + value + ", 0.5)"))
			# 				unit.LiqProp[key] = resultval
			# 		else:
			# 			for v in value:
			# 				propertyname = unit.name + '.' + v
			# 				if propertyname in self.resdata[0]:
			# 					ind = self.resdata[0].index(propertyname)
			# 					resultval = str(self.resdata[-1][ind])
			# # 					resultval = str(omc.sendExpression("val("+unit.name+ "." + v + ", 0.5)"))
			# 					unit.LiqProp[key][i] = resultval
			# 					i = i + 1
		# 		for key, value in unit.OMVapProp.iteritems():
		# 			i = 0

		# 			if type(value) is str:
		# 				resultval = str(omc.sendExpression("val("+unit.name+ "." + value + ", 0.5)"))
		# 				unit.VapProp[key] = resultval
		# 			else:
		# 				for v in value:
		# 					resultval = str(omc.sendExpression("val("+unit.name+ "." + v + ", 0.5)"))
		# 					unit.VapProp[key][i] = resultval
		# 					i = i + 1


		# 		for key, value in unit.OMLiqProp.iteritems():
		# 			i = 0

		# 			if type(value) is str:
		# 				resultval = str(omc.sendExpression("val("+unit.name+ "." + value + ", 0.5)"))
		# 				unit.LiqProp[key] = resultval
		# 			else:
		# 				for v in value:
		# 					resultval = str(omc.sendExpression("val("+unit.name+ "." + v + ", 0.5)"))
		# 					unit.LiqProp[key][i] = resultval
		# 					i = i + 1       	



	def simulateEQN(self):
		self.data = []
		print("##################################################")
		print("##################################################")
		self.sim_method = 'Eqn'
		self.data.append("model Flowsheet\n")
  		
		for c in self.compounds:
			ucase = c.title()
			lcase = c.lower()
			self.data.append("parameter Simulator.Files.Chemsep_Database." + ucase +' '+ ucase + "; \n")

		for unitop in self.UnitOpn:
			self.data.append(unitop[0].OM_Flowsheet_Init(self.compounds))
		
		self.data.append("equation\n")
        
		for unitop in self.UnitOpn:
			if unitop[1]==0:
					
				if unitop[0].type == 'MatStm':
					self.data.append(unitop[0].OM_Flowsheet_Eqn(self.compounds,'Eqn'))
				else:
					self.data.append(unitop[0].OM_Flowsheet_Eqn(self.compounds))
			else:
				pass
		with open(self.Flomo_path, 'w') as txtfile:
			for d in self.data:
				txtfile.write(d)
			txtfile.write('end Flowsheet;\n')

		with open(self.eqn_mos_path, 'w') as mosFile:
			mosFile.write('loadModel(Modelica);\n')
			mosFile.write("loadFile(\"Simulator\package.mo\");\n")
			mosFile.write("loadFile(\"Flowsheet.mo\");\n")
			mosFile.write("simulate(Flowsheet, outputFormat=\"csv\", stopTime=1.0, numberOfIntervals=1);\n")

		print('Initiating Simulation in Equation Oriented Mode')

		self.send_for_simulationEqn()

	


	def simulateSM(self,ip,op):
		self.sim_method = 'SM'
		self.data = []
		self.resdata = []
		self.unit = []
		self.csvlist = []
		print("op list",op)
		print("ip list",ip)
		for i in ip:
			common = ip[i]
			print("common #############3",common)
			print("*********** i *********",i)
			for k,v in op.items():
				print("Print K",k)
				if(set(v) & set(common)):
					print("*****************common matstm***************")
					if((i in self.unit) and (k in self.unit)):
						print("both exist")
						pass
					elif(i in self.unit):
						print("output exist")
						self.unit.insert(self.unit.index(i),k)
					elif(k in self.unit):
						print("input exists")
						self.unit.append(i)
					else:
						print("nothing exists")
						self.unit.append(k)
						self.unit.append(i)
			print("##############################33")
			print(self.unit)
			print("################################11")	
				
		for unitop in self.unit:
			os.chdir(self.curr_path)
			self.data = []
			if unitop.type not in ['MatStm','EngStm']:
				inpstms = unitop.InputStms
				outstms = unitop.OutputStms
				
				try:
					engstms = unitop.EngStms
				except:
					engstms = None

				self.data.append("model "+unitop.name.lower()+'\n')
				
				for c in self.compounds:
					ucase = c.title()
					lcase = c.lower()
					self.data.append("parameter Simulator.Files.Chemsep_Database." + ucase +' '+ ucase + "; \n")
				
				print("##############compounds added")
				self.data.append(unitop.OM_Flowsheet_Init(self.compounds))
				
				if type(outstms) is list:
					for stm in outstms:
						self.data.append(stm.OM_Flowsheet_Init(self.compounds))
				else:
					self.data.append(outstms.OM_Flowsheet_Init(self.compounds))
				
				
				if engstms:
					self.data.append(engstms.OM_Flowsheet_Init(self.compounds))

				if type(inpstms) is list:
					for stm in inpstms:
						self.data.append(stm.OM_Flowsheet_Init(self.compounds))
				else:
					self.data.append(inpstms.OM_Flowsheet_Init(self.compounds))
				
				self.data.append('equation\n')
				print("##################equation")
				self.data.append(unitop.OM_Flowsheet_Eqn(self.compounds))
				'''
				if type(outstms) is list:
					for stm in outstms:
						#stm.GetEquationValues()
						self.data.append(stm.OM_Flowsheet_Eqn(self.compounds,'SM'))
				else:
					#outstms.GetEquationValues()
					self.data.append(outstms.OM_Flowsheet_Eqn(self.compounds,'SM'))
'''
				if type(inpstms) is list:
					for stm in inpstms:
						#stm.GetEquationValues()
						self.data.append(stm.OM_Flowsheet_Eqn(self.compounds,'SM'))
				else:
					#inpstms.GetEquationValues()
					self.data.append(inpstms.OM_Flowsheet_Eqn(self.compounds,'SM'))

				# os.chdir(self.sim_dir_path)
				unitmofile = os.path.join(self.sim_dir_path,unitop.name.lower()+'.mo')

				with open(unitmofile,'w') as unitFile:
					for d in self.data:
						unitFile.write(d)
					unitFile.write('end '+unitop.name.lower()+';\n')
				
				unitmosfile = os.path.join(self.sim_dir_path,unitop.name.lower()+'.mos')
				with open(unitmosfile, 'w') as mosFile:
					mosFile.write('loadModel(Modelica);\n')
					mosFile.write("loadFile(\"Simulator\package.mo\");\n")
				
					mosFile.write("loadFile(\""+unitop.name.lower()+".mo\");\n")
					mosFile.write("simulate("+unitop.name.lower()+", outputFormat=\"csv\", stopTime=1.0, numberOfIntervals=1);\n")

				print("Initiating simulation in Sequential Modular Mode")
				#self.resdata = []
				self.omc_path = self.get_omc_path()
				os.chdir(self.sim_dir_path)
				#os.system(self.omc_path + ' -s ' + unitop[0].name.lower()+"SEQ"+'.mos')
				print("SIM directory Path 1 ###",self.sim_dir_path)
				sim = os.path.join(self.sim_dir_path,unitop.name.lower()+'.mos')
				process = Popen([self.omc_path, '-s',sim], stdout=PIPE, stderr=PIPE)
				self.stdout, self.stderr = process.communicate()
				os.chdir(self.curr_path)
				#s = subprocess.check_output([self.omc_path, '-s',simpath])
				#print(s)
				print("############### StdOut ################")
				print(self.stdout)
				print("############### StdErr ################")
				print(self.stderr)
				print('Simulating '+unitop.name.lower()+'...')
				csvpath = os.path.join(self.sim_dir_path,unitop.name.lower()+'_res.csv')
				
				self.csvlist.append(csvpath)
				
				with open(csvpath,'r') as resultFile:
					csvreader = csv.reader(resultFile,delimiter=',')
					for row in csvreader:
						self.resdata.append(row)
				
				os.chdir(self.curr_path)
				if type(inpstms) is list:
					for stm in inpstms:
						for key, value in stm.Prop.items():
							propertyname = stm.name + '.' + key
							if propertyname in self.resdata[0]:
								ind = self.resdata[0].index(propertyname)
								resultval = str(self.resdata[-1][ind])
								stm.Prop[key] = resultval

								#print("input",stm.Prop[key])
						

				else:
					for key, value in inpstms.Prop.items():
							propertyname = inpstms.name + '.' + key
							if propertyname in self.resdata[0]:
								ind = self.resdata[0].index(propertyname)
								resultval = str(self.resdata[-1][ind])
								inpstms.Prop[key] = resultval
								#print("input",inpstms.Prop[key])

				if type(outstms) is list:
					for stm in outstms:
						for key, value in stm.Prop.items():
							propertyname = stm.name + '.' + key
							if propertyname in self.resdata[0]:
								ind = self.resdata[0].index(propertyname)
								resultval = str(self.resdata[-1][ind])
								stm.Prop[key] = resultval
								print("output key:",key,"value:",stm.Prop[key])
				else:
					for key, value in outstms.Prop.items():
							propertyname = outstms.name + '.' + key
							if propertyname in self.resdata[0]:
								ind = self.resdata[0].index(propertyname)
								resultval = str(self.resdata[-1][ind])
								outstms.Prop[key] = resultval
								print("output key:",key,"value:",outstms.Prop[key])

		
		self.dataframes = [pd.read_csv(i) for i in self.csvlist]
		os.chdir(self.sim_dir_path)
		dffinal = pd.concat(self.dataframes,axis=1)
		dffinal.to_csv('FlowsheetSEQ.csv',index=False)
		self.resdata.clear()
		with open(os.path.join(self.sim_dir_path+'/FlowsheetSEQ.csv'),'r') as resultFile:
					csvreader = csv.reader(resultFile,delimiter=',')
					for row in csvreader:
						self.resdata.append(row)
		
		


				

					
				









