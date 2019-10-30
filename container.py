from OMChem.Flowsheet import Flowsheet
from OMChem.MatStm import MatStm
from OMChem.Mixer import Mixer
from OMChem.Heater import Heater
from component_selector import *
from collections import defaultdict
from PyQt5.QtCore import *
from PyQt5.QtGui import *
import datetime
import itertools
class Container():
    def __init__(self,msgbrowser):
        self.unitOp = []
        self.thermoPackage = None
        self.compounds = None
        self.conn = defaultdict(list)
        self.op=defaultdict(list)
        self.ip=defaultdict(list)
        self.msg = msgbrowser
        self.msg.setText("")
        self.opl=[]
        self.result=[]


    def currentTime(self):
        now = datetime.datetime.now()
        time = str(now.hour) + ":" + str(now.minute) + ":" +str(now.second)
        return time
    
    def updateConn(self,key,value):
        self.conn[key].append(value)
        self.msg.append("<span style=\"color:blue\">["+str(self.currentTime())+"]<b> "+key.name+" </b> output is connected to input of<b> "+value.name +" </b></span>")
    def addUnitOp(self,obj):
        if(obj in self.unitOp):
            pass
        else:
            self.unitOp.append(obj)
            self.msg.append("<span style=\"color:blue\">["+str(self.currentTime())+"]<b> "+obj.name+" </b>is instantiated .""</span>")

    def fetchObject(self,name):
        for i in self.unitOp:
            if(i.name==name):
                return i
    def addCompounds(self,comp):
        self.compounds = comp

    def add_thermoPackage(self,thermo):
        self.thermoPackage = thermo
        
    def connection(self):
        try:
            self.op.clear()
            self.ip.clear()
            self.opl.clear()
            stm = ['MatStm','EngStm']
            for i in self.conn:
                if i.type not in stm:
                    self.op[i]=self.conn[i]

                for j in range(len(self.conn[i])):
                    if self.conn[i][j].type not in stm:
                        self.ip[self.conn[i][j]].append(i)
                    
            for i in self.op:
                i.connect(InputStms=self.ip[i],OutputStms=self.op[i])
            
            self.opl.append([self.op[i] for i in self.op])
            self.opl=flatlist(flatlist(self.opl))
        except Exception as e:
            print(e)

    def msgBrowser(self,f):
        std = f.stdout.decode("utf-8")
        if(std):
            stdout = str(std)
            stdout = stdout.replace("\n","<br/>")
            self.msg.append("<span style=\"color:green\">"+stdout+"</span>")
        
        stde = f.stderr.decode("utf-8")
        if(stde):
            stdout = str(stde)
            stdout = stdout.replace("\n","<br/>")
            self.msg.append("<span style=\"color:red\">"+stdout+"</span>")
    
    def simulate(self,mode):
        print(mode)
        self.compounds = compound_selected
        self.connection()
        f = Flowsheet()
        f.add_comp_list(self.compounds)
        print("######## connection master#########\n",self.conn)
        for i in self.unitOp :
            if i in self.opl:
                print("here",i)
                f.add_UnitOpn(i,1)
            else:
                f.add_UnitOpn(i,0)
        if mode=='SM':
            self.msg.append("<span>["+str(self.currentTime())+"] Simulating in <b>Sequential</b> mode ... </span>")
            f.simulateSM(self.ip,self.op)
            self.msgBrowser(f)
            self.result=f.resdata
            print("under SEQ mode simulation")
        elif mode=='EQN':
            self.msg.append("<span>["+str(self.currentTime())+"] Simulating in <b>equation</b> mode ... </span>")
            f.simulateEQN()
            self.msgBrowser(f)
            self.result=f.resdata
            print("under Eqn mode simulation")

def flatlist(lst):
    flat_list=[]
    for sublist in lst:
        for item in sublist:
            flat_list.append(item)
    return flat_list
