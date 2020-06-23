from OMChem.Flowsheet import Flowsheet
from ComponentSelector import *
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
    def __init__(self,msgbrowser, graphicsView):
        self.unit_operations = []
        self.thermo_package = None
        self.compounds = None
        self.flowsheet = None
        self.conn = defaultdict(list)
        self.op=defaultdict(list)
        self.ip=defaultdict(list)
        self.msg = msgbrowser
        self.graphicsView = graphicsView
        self.msg.setText("")
        self.opl=[]
        self.result=[]
        self.graphics = Graphics(self.unit_operations, self.graphicsView)
        self.scene = self.graphics.get_scene()

    def current_time(self):
        now = datetime.datetime.now()
        time = str(now.hour) + ":" + str(now.minute) + ":" +str(now.second)
        return time
    
    # def updateConn(self,key,value):
    #     self.conn[key].append(value)
    #     self.msg.append("<span style=\"color:blue\">["+str(self.current_time())+"]<b> "+key.name+" </b> output is connected to input of<b> "+value.name +" </b></span>")
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
    #         self.opl=flat_list(flat_list(self.opl))
    #     except Exception as e:
    #         print(e)

    # @staticmethod
    # def addUnitOpObj(obj):
    #     self.unit_operations.append(obj)

    def add_unit_operation(self, obj):
        box = None
        self.obj = obj
        self.scene = self.graphics.get_scene()
        #self.graphicsView = graphicsView
        box  = self.graphics.create_node_item(self.obj, self)
        self.scene.addItem(box)
        box.setPos(2500-30, 2500-30)

        if(obj in self.unit_operations):
            pass
        else:
            self.unit_operations.append(obj)
            data = self.unit_operations[:]
            data.append(compound_selected)
            push('Undo', data)
            self.msg.append("<span style=\"color:blue\">["+str(self.current_time())+"]<b> "+obj.name+" </b>is instantiated .""</span>")

    '''
        Deletes the selected item from the canvas and also the objects created for that type.
    '''
    def delete(self,l):
        for item in l:
            print('deleted objects ', item)
            self.scene.removeItem(item)
            for i in dock_widget_lst:
                if i.name == item.name:
                    i.hide()
                    del i
                    break
            for i in dock_widget_lst:
                print(i.name)
            print("delete ", dock_widget_lst)
            if hasattr(item,'input'):
                print("In input ")
                print(item.input)
                for x in item.input:
                    if x.new_line:
                        self.scene.removeItem(x.new_line)
                        del x.new_line
                    if x.other_line:
                        self.scene.removeItem(x.other_line)
                        del x.other_line
            if hasattr(item,'output'):
                print("in output ")
                print(item.output)
                for x in item.output:
                    if x.new_line:
                        self.scene.removeItem(x.new_line)
                        del x.new_line
                    if x.other_line:
                        self.scene.removeItem(x.other_line)
                        del x.other_line
            if hasattr(item,'obj'):
                self.unit_operations.remove(item.obj)
                for k in list(self.conn):
                    if item.obj==k:
                        del self.conn[k]
                    elif item.obj in self.conn[k]:
                        self.conn[k].remove(item.obj)
                self.msg.append("<span style=\"color:blue\">["+str(self.current_time())+"]<b> "+item.obj.name+" </b>is deleted .""</span>")
                del item.obj
            del item

            clean_file('Redo')
            data = self.unit_operations[:]
            data.append(compound_selected)
            push('Undo', data)

    def fetch_object(self,name):
        for i in self.unit_operations:
            if(i.name==name):
                return i
                
    def add_aompounds(self,comp):
        self.compounds = comp

    def add_thermo_package(self,thermo):
        self.thermo_package = thermo

    def msg_browser(self):
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
        self.flowsheet.add_compound_list(self.compounds)
        print("######## connection master#########\n",self.conn)
        for i in self.unit_operations :
                print("here",i)
                self.flowsheet.add_unit_operations(i)
            
        if mode=='SM':
            self.msg.append("<span>["+str(self.current_time())+"] Simulating in <b>Sequential</b> mode ... </span>")
            self.flowsheet.simulate_SM(self.ip,self.op)
            self.msg_browser()
            self.result=self.flowsheet.result_data
            print("under SEQ mode simulation")
        elif mode=='EQN':
            self.msg.append("<span>["+str(self.current_time())+"] Simulating in <b>equation</b> mode ... </span>")
            self.flowsheet.simulate_EQN()
            self.msg_browser()
            self.result=self.flowsheet.result_data
            print("under Eqn mode simulation")

        try:
            DockWidget.show_result(NodeItem.get_dock_widget())
        except AttributeError:
            print(NodeItem.name + ' does not have dockwidget')
            pass

def flat_list(lst):
    flat_lst=[]
    for sublist in lst:
        for item in sublist:
            flat_lst.append(item)
    return flat_lst

def push(file_name, data):
    with open(f"{file_name}.dat", "ab") as obj:
        pickle.dump(data, obj)

def clean_file(file_name):
    with open(f"{file_name}.dat", "wb") as clean:
        pass

def pop(file_name):
    last_command = None
    if os.stat(f"{file_name}.dat").st_size != 0:
        commands = []
        with open(f"{file_name}.dat", "rb") as objs:
            while True:
                try:
                    command = pickle.load(objs)
                    commands.append(command)
                except EOFError:
                    break

        last_command = commands[-1]
        commands.remove(commands[-1])
        if len(commands) != 0:
            with open(f"{file_name}.dat", "wb") as updated_data:
                for i in range(len(commands)):
                    pickle.dump(commands[i], updated_data)
        else:
            clean_file(file_name)

    return last_command

def get_last_list(file_name):
    commands = []
    if os.stat(f"{file_name}.dat").st_size != 0:
        with open(f"{file_name}.dat", "rb") as objs:
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
