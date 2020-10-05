import sys
import pandas as pd
import numpy as np
import os
import csv
from subprocess import Popen, PIPE

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import PyQt5.QtGui as QtGui
import PyQt5.QtCore as QtCore
import PyQt5.QtWidgets as QtWidgets
from PyQt5.uic import loadUiType


import pyqtgraph as pg
import pyqtgraph.exporters

ui_dialog,_ = loadUiType('Binary_Phase_Env.ui')

class BinPhaseEnv(QWidget,ui_dialog):
    def __init__(self,comp):
        QWidget.__init__(self)
        self.setupUi(self)

        self.comp = comp
        self.compunds = self.comp.get_compounds()
            
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

        self.data.append("model Graph\n")
        self.data.append("import data = Simulator.Files.Chemsep_Database;\n")
        self.data.append("parameter data."+self.comp1+" comp1;\n")
        self.data.append("parameter data."+self.comp2+" comp2;\n")
        self.data.append("extends BinaryEnvelopes."+self.thermoPack+"(Nc = 2, data_points = "+str(data_points)+ ", comp = { comp1, comp2 }, "+self.type+" = fill( "+str(val)+", "+str(data_points)+"));\n")
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
            csvreader = csv.reader(resultFile,delimiter=',')
            for row in csvreader:
                self.resdata.append(row)
                self.rows.append(row)

        if self.type=='T':
            for k in range(len(self.rows[0])):
                if self.rows[0][k][0]=='P':
                    self.datay.append(float(self.rows[1][k]))
                length = len(self.rows[0][k])
                if self.rows[0][k][0]=='x' and self.rows[0][k][length-2]=='1':
                    self.datax1.append(float(self.rows[1][k]))
                if self.rows[0][k][0]=='y' and self.rows[0][k][length-2]=='1':
                    self.datax2.append(float(self.rows[1][k]))
        else: 
            for k in range(len(self.rows[0])):
                if self.rows[0][k][0]=='T':
                    self.datay.append(float(self.rows[1][k]))
                length = len(self.rows[0][k])   
                if self.rows[0][k][0]=='x' and self.rows[0][k][length-2]=='1':
                    self.datax1.append(float(self.rows[1][k]))

                if self.rows[0][k][0]=='y' and self.rows[0][k][length-2]=='1':
                    self.datax2.append(float(self.rows[1][k]))

        plt = pg.PlotWidget()
        plt.showGrid(x=True,y=True)
        plt.addLegend()   
        plt.setXRange(0,1) 

        c1 = plt.plot(self.datax1, self.datay,pen=pg.mkPen('b',width = 1), name='dew points')
        c2 = plt.plot(self.datax2, self.datay,pen=pg.mkPen('r',width = 1), name='bubble points') 
        view_box = plt.plotItem.vb
        self.tool_tip = ""

        def press_event(evt):
            a = 10
            pos = evt
            mousepoint = view_box.mapSceneToView(pos)
            roi = pg.ROI(pos)
            find_color = plt.mapToGlobal(pos.toPoint())

            screen = QGuiApplication.primaryScreen()
            image = screen.grabWindow(QApplication.desktop().winId()).toImage()
            colour = QtGui.QColor(image.pixel(find_color.x(),find_color.y()))

            if colour.red()==255 or colour.blue()==255:
                self.lineEdit_x.setText(str(round(mousepoint.x(),3)))
                self.lineEdit_y.setText(str(round(mousepoint.y(),3)))
                self.tool_tip = str(round(mousepoint.x(),3)) + ", " + str(round(mousepoint.y(),3))
                QApplication.setOverrideCursor(QCursor(QtCore.Qt.CrossCursor))
            else:
                self.lineEdit_x.setText("")
                self.lineEdit_y.setText("")
                self.tool_tip = ""
                QApplication.setOverrideCursor(QCursor(QtCore.Qt.ArrowCursor))
                     
        def entered(items):
            for i in items:
                if i.__class__.__name__ =="LegendItem":
                    self.lineEdit_x.setText("")
                    self.lineEdit_y.setText("")
                    QApplication.setOverrideCursor(QCursor(QtCore.Qt.ArrowCursor))
                else:
                    i.setToolTip(self.tool_tip)    
                 
        plt.scene().sigMouseMoved.connect(press_event)
        plt.scene().sigMouseHover.connect(entered)

        plt.setLabel('left',self.other+self.otherunit,units = '')   
        plt.setLabel('bottom',self.comp1+'(mol. frac.)',units = '')

        self.new_tab = plt
        self.new_tab.setObjectName("Plot "+str(self.counter))
        
        self.tabWidget.addTab(self.new_tab,"Plot "+str(self.counter))
        self.counter+=1
