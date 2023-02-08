from collections import defaultdict
import datetime
import pickle 
import os

from OMChem.Flowsheet import Flowsheet
from ComponentSelector import *
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
    
    def add_unit_operation(self, obj):
        box = None
        self.obj = obj
        self.scene = self.graphics.get_scene()
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
            self.scene.removeItem(item)
            for i in dock_widget_lst:
                if i.name == item.name:
                    i.hide()
                    del i
                    break

            if hasattr(item,'input'):
                for x in item.input:
                    if x.new_line:
                        self.scene.removeItem(x.new_line)
                        del x.new_line
                    if x.other_line:
                        self.scene.removeItem(x.other_line)
                        del x.other_line
            if hasattr(item,'output'):
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
                
    def add_compounds(self,comp):
        self.compounds = comp

    def update_compounds(self):
        self.graphics.update_compounds()

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

        for i in self.graphics.scene.items():
            if (isinstance(i, NodeItem)):
                try:
                    i.dock_widget.clear_results()
                except AttributeError:
                    pass

        #print("SIMULATE")
        #print(mode)
        self.compounds = compound_selected
        self.flowsheet = Flowsheet()
        self.flowsheet.add_compound_list([c[:c.index('(')] for c in self.compounds])
        #print("######## connection master#########\n",self.conn)
        for i in self.unit_operations :
            self.flowsheet.add_unit_operations(i)
            
            
        if mode=='SM':
            self.msg.append("<span>["+str(self.current_time())+"] Simulating in <b>Sequential</b> mode ... </span>")
            self.flowsheet.simulate_SM(self.ip,self.op)
            self.msg_browser()
            self.result=self.flowsheet.result_data
            
        elif mode=='EQN':
            self.graphicsView.setInteractive(False)
            QApplication.instance().setOverrideCursor(QCursor(Qt.WaitCursor))

            self.msg.append("<span>["+str(self.current_time())+"] Simulating in <b>equation</b> mode ... </span>")
            self.flowsheet.simulate_EQN()
            self.result=self.flowsheet.result_data

            self.graphicsView.setInteractive(True)
            QApplication.instance().restoreOverrideCursor()
            QApplication.instance().setOverrideCursor(QCursor(Qt.ArrowCursor))

            if(len(self.result)== 4):
                #self.msg_browser()
                self.msg.append("<span style=\"color:green\">["+str(self.current_time())+"] Simulation <b>Successful.</b></span>")
            else:
                self.msg.append("<span style=\"color:red\">["+str(self.current_time())+"] Simulation <b>Failed.</b></span>")
            #print("under Eqn mode simulation")
        
        if(len(self.result)== 4):
            DockWidget.show_result(NodeItem.get_dock_widget())

        for i in self.graphics.scene.items():
            if (isinstance(i, NodeItem) and i.type == 'MaterialStream'):
                i.update_tooltip_selectedVar()
                no_input_lines = len(i.input[0].in_lines)
                no_output_lines = len(i.output[0].out_lines)
                if(no_input_lines>0): #Checks if material stream is input or output stream if it is output stream it continues
                    i.obj.disableInputDataTab(i.dock_widget)

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
