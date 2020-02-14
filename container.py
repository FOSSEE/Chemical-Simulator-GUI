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
        self.scene = self.graphics.getScene()

    def currentTime(self):
        now = datetime.datetime.now()
        time = str(now.hour) + ":" + str(now.minute) + ":" +str(now.second)
        return time
    
    # def updateConn(self,key,value):
    #     self.conn[key].append(value)
    #     self.msg.append("<span style=\"color:blue\">["+str(self.currentTime())+"]<b> "+key.name+" </b> output is connected to input of<b> "+value.name +" </b></span>")
    #
    # def connection(self):
    #     try:
    #         self.op.clear()
    #         self.ip.clear()
    #         self.opl.clear()
    #         stm = ['MaterialStream','EngStm']
    #         for i in self.conn:
    #             if i.type not in stm:
    #                 self.op[i]=self.conn[i]
    #
    #             for j in range(len(self.conn[i])):
    #                 if self.conn[i][j].type not in stm:
    #                     self.ip[self.conn[i][j]].append(i)
    #
    #         for i in self.op:
    #             i.connect(InputStms=self.ip[i],OutputStms=self.op[i])
    #
    #         self.opl.append([self.op[i] for i in self.op])
    #         self.opl=flatlist(flatlist(self.opl))
    #     except Exception as e:
    #         print(e)

    # @staticmethod
    # def addUnitOpObj(obj):
    #     self.unitOp.append(obj)

    def addUnitOp(self,obj):
        box = None
        self.obj = obj
        self.scene = self.graphics.getScene()
        box  = self.graphics.createNodeItem(self.obj, self)
        self.scene.addItem(box)
        box.setPos(2500-30, 2500-30)

        if(obj in self.unitOp):
            pass
        else:
            self.unitOp.append(obj)
            data = self.unitOp[:]
            data.append(compound_selected)
            PUSH('Undo', data)
            self.msg.append("<span style=\"color:blue\">["+str(self.currentTime())+"]<b> "+obj.name+" </b>is instantiated .""</span>")

    '''
        Deletes the selected item from the canvas and also the objects created for that type.
    '''
    def delete(self,l):
        for item in l:
            self.scene.removeItem(item)
            if hasattr(item,'Input'):
                for x in item.Input:
                    if x.newLine:
                        self.scene.removeItem(x.newLine)
                        del x.newLine
                    if x.otherLine:
                        self.scene.removeItem(x.otherLine)
                        del x.otherLine
            if hasattr(item,'Output'):
                for x in item.Output:
                    if x.newLine:
                        self.scene.removeItem(x.newLine)
                        del x.newLine
                    if x.otherLine:
                        self.scene.removeItem(x.otherLine)
                        del x.otherLine
            if hasattr(item,'obj'):
                self.unitOp.remove(item.obj)
                for k in list(self.conn):
                    if item.obj==k:
                        del self.conn[k]
                    elif item.obj in self.conn[k]:
                        self.conn[k].remove(item.obj)
                self.msg.append("<span style=\"color:blue\">["+str(self.currentTime())+"]<b> "+item.obj.name+" </b>is deleted .""</span>")
                del item.obj
            del item

            CLEAN_FILE('Redo')
            data = self.unitOp[:]
            data.append(compound_selected)
            PUSH('Undo', data)

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

        DockWidget.showResult(NodeItem.getDockWidget())

def flatlist(lst):
    flat_list=[]
    for sublist in lst:
        for item in sublist:
            flat_list.append(item)
    return flat_list

def PUSH(fileName, data):
    with open(f"{fileName}.dat", "ab") as obj:
        pickle.dump(data, obj)

def CLEAN_FILE(fileName):
    with open(f"{fileName}.dat", "wb") as clean:
        pass

def POP(fileName):
    last_command = None
    if os.stat(f"{fileName}.dat").st_size != 0:
        commands = []
        with open(f"{fileName}.dat", "rb") as objs:
            while True:
                try:
                    command = pickle.load(objs)
                    commands.append(command)
                except EOFError:
                    break

        last_command = commands[-1]
        commands.remove(commands[-1])
        if len(commands) != 0:
            with open(f"{fileName}.dat", "wb") as updated_data:
                for i in range(len(commands)):
                    pickle.dump(commands[i], updated_data)
        else:
            CLEAN_FILE(fileName)

    return last_command

def get_last_list(fileName):
    commands = []
    if os.stat(f"{fileName}.dat").st_size != 0:
        with open(f"{fileName}.dat", "rb") as objs:
            while True:
                try:
                    command = pickle.load(objs)
                    commands.append(command)
                except EOFError:
                    break
    if len(commands) is not 0:
        return commands[-1]
    else:
        return None