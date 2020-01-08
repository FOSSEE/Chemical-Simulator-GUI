from OMChem.Flowsheet import Flowsheet
from component_selector import *
from collections import defaultdict
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGraphicsProxyWidget, QGraphicsObject, QGraphicsEllipseItem ,QGraphicsPixmapItem,QApplication, QGraphicsView, QGraphicsScene, QHBoxLayout, QWidget, QLabel
from PyQt5.QtGui import QBrush ,QTransform ,QMouseEvent
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
import datetime
import itertools
import json
import pickle 
import os
import sys
from Graphics import *

class Container():
    
    def __init__(self,msgbrowser):
        self.unitOp = []
        self.thermoPackage = None
        self.compounds = None
        self.flowsheet = None
        self.conn = defaultdict(list)
        self.op=defaultdict(list)
        self.ip=defaultdict(list)
        self.msg = msgbrowser
        self.msg.setText("")
        self.opl=[]
        self.result=[]
        self.graphics = Graphics(self.unitOp)

    def currentTime(self):
        now = datetime.datetime.now()
        time = str(now.hour) + ":" + str(now.minute) + ":" +str(now.second)
        return time
    
    def updateConn(self,key,value):
        self.conn[key].append(value)
        self.msg.append("<span style=\"color:blue\">["+str(self.currentTime())+"]<b> "+key.name+" </b> output is connected to input of<b> "+value.name +" </b></span>")
   
    def connection(self):
        try:
            self.op.clear()
            self.ip.clear()
            self.opl.clear()
            stm = ['MaterialStream','EngStm']
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

    @staticmethod
    def addUnitOpObj(obj):
        self.unitOp.append(obj)

    def addUnitOp(self,obj):
        box = None
        self.obj = obj
        self.scene = self.graphics.getScene()
        box  = self.graphics.createNodeItem(self.obj)
        self.scene.addItem(box)
        box.setPos(2500-30, 2500-30)

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

    def msgBrowser(self):
        std = self.flowsheet.stdout.decode("utf-8")
        if(std):
            stdout = str(std)
            stdout = stdout.replace("\n","<br/>")
            self.msg.append("<span style=\"color:green\">"+stdout+"</span>")
        
        stde = self.flowsheet.stderr.decode("utf-8")
        if(stde):
            stdout = str(stde)
            stdout = stdout.replace("\n","<br/>")
            self.msg.append("<span style=\"color:red\">"+stdout+"</span>")
    
    def simulate(self,mode):
        print("SIMULATE")
        print(mode)
        self.compounds = compound_selected
        self.flowsheet = Flowsheet()
        self.flowsheet.add_comp_list(self.compounds)
        print("######## connection master#########\n",self.conn)
        for i in self.unitOp :
                print("here",i)
                self.flowsheet.add_UnitOpn(i)
            
        if mode=='SM':
            self.msg.append("<span>["+str(self.currentTime())+"] Simulating in <b>Sequential</b> mode ... </span>")
            self.flowsheet.simulateSM(self.ip,self.op)
            self.msgBrowser()
            self.result=self.flowsheet.resdata
            print("under SEQ mode simulation")
        elif mode=='EQN':
            self.msg.append("<span>["+str(self.currentTime())+"] Simulating in <b>equation</b> mode ... </span>")
            self.flowsheet.simulateEQN()
            self.msgBrowser()
            self.result=self.flowsheet.resdata
            print("under Eqn mode simulation")

def flatlist(lst):
    flat_list=[]
    for sublist in lst:
        for item in sublist:
            flat_list.append(item)
    return flat_list
