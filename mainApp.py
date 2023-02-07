import pickle
import threading
import os
import ctypes
import sys
import datetime
from functools import partial

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets

from OMChem.Flowsheet import Flowsheet
from ComponentSelector import *
from Bin_Phase_env import *
from UnitOperations import *
from Streams import *
from Container import *
from Graphics import *

ui,_ = loadUiType('main.ui')

'''
    MainApp class is responsible for all the main App Ui operations
'''
class MainApp(QMainWindow,ui):
    '''
        Initializing the application
    '''
    def __init__(self):
        QMainWindow.__init__(self)
        
        # Loading and setting up style sheet
        self.setupUi(self)
        
        # Initializing attributes
        self.zoom_count = 0
        self.thrd = None

        # Creating instances of classes for the main app
        self.container = Container(self.textBrowser, self.graphicsView)        
        self.comp = ComponentSelector(self)
        self.comp.accepted.connect(self.update_compounds)

        # Setting up interactive canvas        
        self.scene = self.container.graphics.get_scene()
        self.graphicsView.setScene(self.scene)
        self.graphicsView.setMouseTracking(True)
        self.graphicsView.keyPressEvent=self.delete_call
        
        self.setDockNestingEnabled(True)
        self.setCorner(Qt.BottomRightCorner, Qt.RightDockWidgetArea)
        self.setCorner(Qt.BottomLeftCorner, Qt.LeftDockWidgetArea)
        self.addDockWidget(Qt.BottomDockWidgetArea,self.dockWidget_2)
        
        # Calling initialisation 
        self.menu_bar()
        self.button_handler()
        self.comp.show()

    '''
        MenuBar function handels all the all the operations of 
        menu bar like new,zoom,comounds selector, simulation options.
    '''    
    def menu_bar(self):
        self.actionSelectCompounds.triggered.connect(self.select_compounds)
        self.actionSelectCompounds.setShortcut('Ctrl+C')
        self.actionZoomIn.triggered.connect(self.zoom_in)
        self.actionZoomIn.setShortcut('Ctrl++')
        self.actionNew.triggered.connect(self.new)
        self.actionNew.setShortcut('Ctrl+N')
        self.actionZoomOut.triggered.connect(self.zoom_out)
        self.actionZoomOut.setShortcut('Ctrl+-')
        self.actionResetZoom.triggered.connect(self.zoom_reset)
        self.actionResetZoom.setShortcut('Ctrl+R')
        self.actionHelp.triggered.connect(self.help)
        self.actionHelp.setShortcut('Ctrl+H')
        self.actionSequentialMode.triggered.connect(partial(self.simulate,'SM'))
        self.actionSequentialMode.setShortcut('Ctrl+M') 
        self.actionEquationOriented.triggered.connect(partial(self.simulate,'EQN'))
        self.actionEquationOriented.setShortcut('Ctrl+E')
        self.actionUndo.triggered.connect(self.undo)
        self.actionUndo.setShortcut('Ctrl+Z')
        self.actionRedo.triggered.connect(self.redo)
        self.actionRedo.setShortcut('Ctrl+Y')
        self.actionSave.triggered.connect(self.save)
        self.actionSave.setShortcut('Ctrl+S')
        self.actionOpen.triggered.connect(self.open)
        self.actionOpen.setShortcut('Ctrl+O')
        self.actionTerminate.triggered.connect(self.terminate)
        self.actionTerminate.setShortcut('Ctrl+T')
        self.actionBinaryPhaseEnvelope.triggered.connect(self.bin_phase_env)
        self.actionViewMessageBrowser.triggered.connect(self.toggle_message_browser_view)
        self.actionViewComponentSelector.triggered.connect(self.toggle_component_selector_view)
        
    '''
        Handles all the buttons of different components.
    '''
    def button_handler(self):
        self.pushButton.clicked.connect(partial(self.component,'MaterialStream'))
        self.pushButton_7.clicked.connect(partial(self.component,'Mixer'))
        self.pushButton_14.clicked.connect(partial(self.component,'CentrifugalPump'))
        self.pushButton_26.clicked.connect(partial(self.component,'DistillationColumn'))
        self.pushButton_18.clicked.connect(partial(self.component,'ShortcutColumn'))
        self.pushButton_11.clicked.connect(partial(self.component,'Heater'))
        self.pushButton_10.clicked.connect(partial(self.component,'Splitter'))
        self.pushButton_9.clicked.connect(partial(self.component,'Flash'))
        self.pushButton_25.clicked.connect(partial(self.component,'Valve'))
        self.pushButton_12.clicked.connect(partial(self.component,'Cooler'))
        self.pushButton_13.clicked.connect(partial(self.component,'CompoundSeparator'))
        self.pushButton_15.clicked.connect(partial(self.component,'AdiabaticCompressor'))
        self.pushButton_16.clicked.connect(partial(self.component,'AdiabaticExpander'))
    
    '''
        Displays help box
    '''
    def help(self):
        msgBox = QMessageBox() 
        msgBox.setIcon(QMessageBox.Question)
        msgBox.setTextFormat(Qt.RichText);   
        msgBox.setText("For any Help or Suggestion you can contact us at\n contact-om@fossee.in or at <a href='https://www.fossee.in'>Visit fossee.in!</a>")
        msgBox.setStandardButtons(QMessageBox.Ok)
        msgBox.exec_()

    '''
        Creates Binary Phase envelope
    '''
    def bin_phase_env(self):
        if len(self.comp.get_compounds())<2:
            QMessageBox.about(self, 'Important', "Please select at least 2 Compounds first")
            self.comp.show()
        else: 
            self.bin_phase = BinPhaseEnv(self.comp)
            self.bin_phase.show() 

    '''
        Shows Compounds Selector Dialog
    '''
    def select_compounds(self):
        self.comp.show()

    '''
        Updates compounds after compound selected modified during simulation creation
    '''
    def update_compounds(self):
        self.container.update_compounds()


    '''
        Returns current time in a required particular format
    '''
    def current_time(self):
        now = datetime.datetime.now()
        time = str(now.hour) + ":" + str(now.minute) + ":" +str(now.second)
        return time

    '''
        Simulate function is responsible for the simulation
        of the designed flowsheet in a particular mode
        selected by the user.
    '''
    def simulate(self,mode):
        self.thrd = threading.Thread(target=self.container.simulate, args=(mode,))
        self.thrd.start()
    
    '''
        Terminate the current running simulation
    '''
    def terminate(self):
        os.chdir(self.container.flowsheet.root_dir)
        if self.thrd:
            thread_id = self.thrd.ident
            print('____________________Going to terminate simulation thread with Thread ID:',thread_id,'____________________')
            print('____________________Going to terminate the new process created for omc____________________')
            self.container.flowsheet.process.terminate()
            print('____________________New process created for omc is terminated.____________________')
            res = ctypes.pythonapi.PyThreadState_SetAsyncExc(thread_id, ctypes.py_object(SystemExit)) 
            self.textBrowser.append("<span style=\"color:red\">["+str(self.current_time())+"]<b> Terminating the simulation </b></span>")
            print('____________________Simulation thread terminated____________________')
            if res > 1: 
                ctypes.pythonapi.PyThreadState_SetAsyncExc(thread_id, 0) 
                print('Exception raise (Thread termination) failure')

    '''
        Resets the zoom level to default scaling
    '''
    def zoom_reset(self):
        if(self.zoom_count>0):
            for i in range(self.zoom_count):
                self.zoomout()
        elif(self.zoom_count<0): 
            for i in range(abs(self.zoom_count)):
                self.zoomin()

    '''
        ZoomOut the canvas
    '''
    def zoom_out(self):
        self.graphicsView.scale(1.0/1.15,1.0/1.15)
        self.zoom_count -=1
    
    '''
        ZoomIn the canvas
    '''
    def zoom_in(self):
        self.graphicsView.scale(1.15,1.15)
        self.zoom_count +=1
  
    '''
        Instantiate a NodeItem object for selected type of
        component and added that on canvas/flowsheeting area.
    '''    
    def component(self,unit_operation_type):
        if(self.comp.is_compound_selected()):
            self.type = unit_operation_type
            if(self.type=="MaterialStream"):
                self.obj = MaterialStream(compound_names = compound_selected)
            else:
                self.obj = eval(self.type)()
            self.container.add_unit_operation(self.obj)

        else:
            QMessageBox.about(self, 'Important', "Please Select Compounds first")
            self.comp.show()

    '''
        New is used to delete all the existing work.
    '''        
    def new(self):
        self.undo_redo_helper()
        self.comp = ComponentSelector(self)
        self.textBrowser.append("<span>[" + str(self.current_time()) + "] <b>New</b> flowsheet is created ... </span>")
        dock_widget_lst.clear()

    '''
        Handels all the operations which will happen when delete button is pressed.
    '''
    def delete_call(self,event):
        try:
            if event.key() == QtCore.Qt.Key_Delete:
                l=self.scene.selectedItems()
                self.container.delete(l)
        except Exception as e:
            print(e)

    '''
        It helps by clearing screen and loading the objects by undo redo methods
    '''
    def undo_redo_helper(self):
        for i in self.container.unit_operations:
            type(i).counter = 1
        self.container = None
        for i in dock_widget_lst:
            i.hide()
            del i
        lst.clear()
        self.container = Container(self.textBrowser, self.graphicsView)

        compound_selected.clear()
        self.scene = self.container.graphics.get_scene()
        self.graphicsView.setScene(self.scene)
        self.graphicsView.setMouseTracking(True)
        self.graphicsView.keyPressEvent=self.delete_call

    '''
        Function for undo 
    '''
    def undo(self):
        redo_data = pop('Undo')
        if redo_data is not None:
            push('Redo', redo_data)
            undo_data = get_last_list('Undo')
            messages = self.textBrowser.toPlainText()
            try:
                self.undo_redo_helper()
                self.container.graphics.load_canvas(undo_data, self.container)
                self.textBrowser.setText(messages)
            except Exception as e:
                print(e)
                self.textBrowser.append(messages)
        else:
            messages = self.textBrowser.toPlainText()
            self.textBrowser.setText(messages)
            self.textBrowser.append("<span>[" + str(self.current_time()) + "] <b>No more undo can be done!</b>... </span>")

    '''
        Function for redo 
    '''
    def redo(self):
        redo_data = pop('Redo')
        if redo_data is not None:
            push('Undo', redo_data)
            messages = self.textBrowser.toPlainText()
            self.undo_redo_helper()
            self.container.graphics.load_canvas(redo_data, self.container)
            self.textBrowser.setText(messages)
        else:
            messages = self.textBrowser.toPlainText()
            self.textBrowser.setText(messages)
            self.textBrowser.append("<span>[" + str(self.current_time()) + "] <b>No more redo can be done!</b>... </span>")

    '''
        Function for saving the current canvas items and compound_selected
    '''
    def save(self):
        data = []
        for i in self.container.unit_operations:
            data.append(i)
            i.saved = True
        data.append(compound_selected)
        data.append(self.container.result)

        file_format = 'sim'
        initial_path = QDir.currentPath() + 'untitled.' + file_format
        file_name, _ = QFileDialog.getSaveFileName(self, "Save As",
                                                  initial_path, "%s Files (*.%s);; All Files (*)" %
                                                  (file_format.upper(), file_format))
        try:
            with open(file_name, 'wb') as f: 
                pickle.dump(data, f, pickle.HIGHEST_PROTOCOL)
        except Exception as e:
            pass

    '''
        Function for loading previous saved canvas and simulation 
    '''
    def open(self):
        try:
            file_format = 'sim'
            initial_path = QDir.currentPath() + 'untitled.' + file_format

            file_name, _ = QFileDialog.getOpenFileName(self, "Open As",
                                                      initial_path, "%s Files (*.%s);; All Files (*)" %
                                                      (file_format.upper(), file_format))
            if file_name:
                self.undo_redo_helper()

                with open(file_name, 'rb') as f:
                    obj = pickle.load(f)
                temp_result = obj[-1]
                obj.pop()
                compound_selected = obj[-1]
                obj.pop()
                self.comp.set_compounds(compound_selected)
                for i in compound_selected:
                    self.comp.compound_selection(self.comp, i)
                self.comp.hide()
                self.container.graphics.load_canvas(obj, self.container)
                self.container.result = temp_result
                DockWidget.show_result(dock_widget_lst)

                for i in dock_widget_lst:
                    #Submitting values 
                    i.param()

                #Disbaling input data tab for output stream
                for i in self.container.graphics.scene.items():
                    if (isinstance(i, NodeItem) and i.type == 'MaterialStream'):
                        i.update_tooltip_selectedVar()
                        no_input_lines = len(i.input[0].in_lines)
                        no_output_lines = len(i.output[0].out_lines)
                        if(no_input_lines>0): #Checks if material stream is input or output stream if it is output stream it continues
                            i.obj.disableInputDataTab(i.dock_widget)

        except Exception as e:
            print(e)

    '''
        Function for toggling the display of Component Selector 
    '''
    def toggle_component_selector_view(self):
        if(self.actionViewComponentSelector.isChecked()):
            self.dockWidget.show()
        else:
            self.dockWidget.hide()

    '''
        Function for toggling the display of Message Browser 
    '''
    def toggle_message_browser_view(self):
        if(self.actionViewMessageBrowser.isChecked()):
            self.dockWidget_2.show()
        else:
            self.dockWidget_2.hide()
    
    
def main():

    clean_file('Undo')
    clean_file('Redo')

    app = QApplication(sys.argv)
    window = MainApp()
    window.showMaximized()
    app.exec()
    

if __name__ == '__main__':
    main()
