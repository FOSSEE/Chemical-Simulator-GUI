import sys
import pandas as pd
import numpy as np
import os
import csv
from subprocess import Popen, PIPE
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QTextDocument ,QTextCursor ,QTextCharFormat ,QFont ,QPixmap
from PyQt5.uic import loadUiType
from PyQt5.QtCore import Qt
#import PyQt5.QtGuiApplication 
from PyQt5.QtGui import *
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
import pyqtgraph as pg
import pyqtgraph.exporters



ui_dialog,_ = loadUiType('Binary_Phase_Env.ui')

class Bin_Phase_env(QWidget,ui_dialog):
    def __init__(self,comp):
        QWidget.__init__(self)
        self.setupUi(self)

        self.comp = comp
        self.compunds = self.comp.getComp()
            
        for i in self.compunds:
            self.comboBox.addItem(str(i))

        for i in range(len(self.compunds)):
            if i!=0:
                self.comboBox_2.addItem(str(self.compunds[i]))

        self.comboBox_2.addItem(str(self.compunds[0]))  

        self.lines = [line.rstrip('\n') for line in open('thermopackage.txt')]
        for j in self.lines:
            self.comboBox_3.addItem(str(j))

        self.radioButton.setChecked(False)
        self.radioButton_2.setChecked(False)

        self.button_handler()

        self.counter = 1



        

    def button_handler(self):
        self.radioButton.clicked.connect(lambda:self.T_xy())
        self.radioButton_2.clicked.connect(lambda:self.P_xy())
        self.pushButton_2.clicked.connect(lambda:self.plot())
        

    def T_xy(self):
        self.radioButton.setChecked(True)
        self.radioButton_2.setChecked(False)
        for i in reversed(range(self.formLayout.count())):
            self.formLayout.itemAt(i).widget().setParent(None)

        self.first = QLineEdit()
        self.type = "P"
        self.other = "T"
        self.otherunit = "(K)"
        self.formLayout.addRow(QLabel("P(Pa)"),self.first)
        self.points = QLineEdit()
        self.points.setText("40")
        self.formLayout.addRow(QLabel("Number of data points"),self.points)    
        #print("T-XY")

    def P_xy(self):
        self.radioButton_2.setChecked(True)
        self.radioButton.setChecked(False)  
        for i in reversed(range(self.formLayout.count())):
            self.formLayout.itemAt(i).widget().setParent(None)

        self.first = QLineEdit()
        self.type = "T"
        self.other = "P"
        self.otherunit = "(Pa)"
        self.points = QLineEdit()
        self.points.setText("40")    
        self.formLayout.addRow(QLabel("T(K)"),self.first)
        self.formLayout.addRow(QLabel("Number of data points"),self.points)
        #print("") 
    def get_omc_path(self):
        try:
            self.omhome = os.environ.get('OPENMODELICAHOME')
            if self.omhome is None:
                self.omhome = os.path.split(os.path.split(os.path.realpath(spawn.find_executable("omc")))[0])[0]
            elif os.path.exists('/opt/local/bin/omc'):
                self.omhome = '/opt/local'
            elif os.path.exists('/usr/bin/omc'):
                self.omhome = '/usr'    
            return os.path.join(self.omhome, 'bin', 'omc')
        except BaseException:
            print("The OpenModelica compiler is missing in the System path please install it" )
            raise

    

    def plot(self):
        #print(self.type)
        
        try:
            val = int(self.first.text(),10)
        except:
            val = 0
        try:        
            data_points = int(self.points.text(),10)
        except:
            data_points = 0    

        self.curr_path = os.getcwd()
        self.sim_dir_path = os.path.join(self.curr_path,'Simulator')
        self.Graphmo_path = os.path.join(self.sim_dir_path,'Graph.mo')
        self.plot_mos_path = os.path.join(self.sim_dir_path,'PlotGraph.mos')

        self.data = []

        self.comp1 = self.comboBox.currentText()
        self.comp2 = self.comboBox_2.currentText()
        self.thermoPack = self.comboBox_3.currentText()

        # print(val)
        # print(data_points)
        # print(self.comp1)
        # print(self.comp2)
        # print(self.thermoPack)

        self.data.append("model Graph\n")
        self.data.append("import data = Simulator.Files.Chemsep_Database;\n")
        self.data.append("parameter data."+self.comp1+" comp1;\n")
        self.data.append("parameter data."+self.comp2+" comp2;\n")
        self.data.append("extends BinaryEnvelopes."+self.thermoPack+"(NOC = 2, data_points = "+str(data_points)+ ", comp = { comp1, comp2 }, "+self.type+" = fill( "+str(val)+", "+str(data_points)+"));\n")
        self.data.append("end Graph;")

        with open(self.Graphmo_path, 'w') as txtfile:
            for d in self.data:
                txtfile.write(str(d))

        with open(self.plot_mos_path, 'w') as mosFile:
            mosFile.write("loadModel(Modelica);\n")
            mosFile.write("loadFile(\"Simulator/package.mo\");\n")
            mosFile.write("loadFile(\"BinaryEnvelopes.mo\");\n")
            mosFile.write("loadFile(\"Graph.mo\");\n")
            mosFile.write("simulate(Graph, outputFormat=\"csv\", stopTime=1.0, numberOfIntervals=1);\n")


        print(self.data)


        self.resdata = []
        self.omc_path = self.get_omc_path()
        simpath = self.plot_mos_path
        os.chdir(self.sim_dir_path)

        process = Popen([self.omc_path, '-s',simpath], stdout=PIPE, stderr=PIPE)
        self.stdout, self.stderr = process.communicate()

        os.chdir(self.curr_path)

        csvpath = os.path.join(self.sim_dir_path,'Graph_res.csv')

        self.datay = []
        self.datax1 = []
        self.datax2 = []
        self.rows = []

        with open (csvpath,'r') as resultFile:
                self.resdata = []
                print("opened")
                csvreader = csv.reader(resultFile,delimiter=',')
                for row in csvreader:
                    print("124125")
                    self.resdata.append(row)
                    self.rows.append(row)

        print("SIMULATION DONE")            





        if self.type=='T':
            for k in range(len(self.rows[0])):
                if self.rows[0][k][0]=='P':
                    self.datay.append(float(self.rows[1][k]))
                    #print(col)
                length = len(self.rows[0][k])

                if self.rows[0][k][0]=='x' and self.rows[0][k][length-2]=='1':
                    self.datax1.append(float(self.rows[1][k]))
                   # k+=1   

                if self.rows[0][k][0]=='y' and self.rows[0][k][length-2]=='1':
                    self.datax2.append(float(self.rows[1][k]))
                    #k+=1        

                #k+=1   

        else:
            
            for k in range(len(self.rows[0])):
                if self.rows[0][k][0]=='T':
                    self.datay.append(float(self.rows[1][k]))
                    #print(col)

                #print(self.rows[0][k]) 
                length = len(self.rows[0][k])   
                if self.rows[0][k][0]=='x' and self.rows[0][k][length-2]=='1':

                    self.datax1.append(float(self.rows[1][k]))
                   # k+=1   

                if self.rows[0][k][0]=='y' and self.rows[0][k][length-2]=='1':
                    self.datax2.append(float(self.rows[1][k]))
                    #k+=1      

        plt = pg.PlotWidget()
        plt.showGrid(x=True,y=True)
        plt.addLegend()   
        plt.setXRange(0,1) 


        # print("SIZE UP AHEAD")
        # print(len(self.datay))
        # print(len(self.datax1))
        # print(len(self.datax2))
        # print("SIZES DONE")

        c1 = plt.plot(self.datax1, self.datay,pen=pg.mkPen('b',width = 1), name='dew points')
        c2 = plt.plot(self.datax2, self.datay,pen=pg.mkPen('r',width = 1), name='bubble points') 

        
        view_box = plt.plotItem.vb



        def pressEvent(evt):
            #print("HELLO")
            a = 10
            pos = evt
            

            mousepoint = view_box.mapSceneToView(pos)
            roi = pg.ROI(pos)
            find_color = plt.mapToGlobal(pos.toPoint())

            screen = QGuiApplication.primaryScreen()
            image = screen.grabWindow(QApplication.desktop().winId()).toImage()
            colour = QtGui.QColor(image.pixel(find_color.x(),find_color.y()))
            #print("red:{}, green:{}, blue:{}".format(colour.red(),colour.green(),colour.blue()))

            if colour.red()==255 or colour.blue()==255:
                self.lineEdit_x.setText(str(round(mousepoint.x(),3)))
                self.lineEdit_y.setText(str(round(mousepoint.y(),3)))
                QApplication.setOverrideCursor(QCursor(QtCore.Qt.CrossCursor))
            else:
                self.lineEdit_x.setText("")
                self.lineEdit_y.setText("")
                QApplication.setOverrideCursor(QCursor(QtCore.Qt.ArrowCursor))
                    

        
        #self.prev = None     
        def entered(items):
            for i in items:
                #print(i.__class__.__name__)
                if i.__class__.__name__ =="LegendItem":
                    self.lineEdit_x.setText("")
                    self.lineEdit_y.setText("")
                    QApplication.setOverrideCursor(QCursor(QtCore.Qt.ArrowCursor))


           # print(items)    
        
        #proxy = pg.SignalProxy(plt.scene().sigMouseMoved, rateLimit = 60, slot = pressEvent)        
        plt.scene().sigMouseMoved.connect(pressEvent)
        plt.scene().sigMouseHover.connect(entered)
        #c1.setAcceptHoverEvents(True)
        #c2.setAcceptHoverEvents(True)

        



        # def hoverEnterEvent(c1,event):
        #     print("Object ZONE")

        # def hoverEnterEvent(c2,event):
        #     print("Object ZONE")    

        #c1.hoverMoveEvent.connect(item)
        #c2.hoverMoveEvent.connect(item)


        plt.setLabel('left',self.other+self.otherunit,units = '')   
        plt.setLabel('bottom',self.comp1+'(mol. frac.)',units = '')

        self.new_tab = plt
        self.new_tab.setObjectName("Plot "+str(self.counter))
        
        self.tabWidget.addTab(self.new_tab,"Plot "+str(self.counter))
        self.counter+=1


    






        
        


            

            
