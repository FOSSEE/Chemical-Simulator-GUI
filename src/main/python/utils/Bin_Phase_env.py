import sys
import pandas as pd
import numpy as np
import os
import csv
import shutil
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

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)
sys.path.append(parentPath)

from python.OMChem.Flowsheet import _normalize_compound_name

ui_dialog,_ = loadUiType(parentPath+'/ui/utils/Binary_Phase_Env.ui')
pg.CONFIG_OPTIONS['crashWarning'] = False

class BinPhaseEnv(QWidget,ui_dialog):
    def __init__(self,comp):
        QWidget.__init__(self)
        self.setupUi(self)

        self.comp = comp
        self.compunds = self.comp.get_compounds()
            
        for i in self.compunds:
            self.comboBox.addItem(str(i))

        for i in range(len(self.compunds)):
            if i != 0:
                self.comboBox_2.addItem(str(self.compunds[i]))

        if self.compunds:
            self.comboBox_2.addItem(str(self.compunds[0]))  

        # Supported thermodynamic packages in BinaryEnvelopes.mo
        supported_thermo = ['RaoultsLaw', 'NRTL']
        try:
            with open(os.path.join(parentPath, 'python', 'utils', 'thermopackage.txt')) as f:
                self.lines = [line.strip() for line in f if line.strip()]
            for j in self.lines:
                if j in supported_thermo:
                    self.comboBox_3.addItem(str(j))
        except Exception:
            for j in supported_thermo:
                self.comboBox_3.addItem(str(j))

        self.radioButton.setChecked(False)
        self.radioButton_2.setChecked(False)

        self.button_handler()
        self.counter = 1

    def button_handler(self):
        self.radioButton.clicked.connect(lambda: self.T_xy())
        self.radioButton_2.clicked.connect(lambda: self.P_xy())
        self.pushButton_2.clicked.connect(lambda: self.plot())

    def T_xy(self):
        self.radioButton.setChecked(True)
        self.radioButton_2.setChecked(False)
        for i in reversed(range(self.formLayout.count())):
            item = self.formLayout.itemAt(i)
            if item and item.widget():
                item.widget().setParent(None)

        self.first = QLineEdit()
        self.type = "P"
        self.other = "T"
        self.otherunit = "(K)"
        self.first.setText("101325")
        self.formLayout.addRow(QLabel("P(Pa)"), self.first)
        self.points = QLineEdit()
        self.points.setText("40")
        self.formLayout.addRow(QLabel("Number of data points"), self.points)    

    def P_xy(self):
        self.radioButton_2.setChecked(True)
        self.radioButton.setChecked(False)  
        for i in reversed(range(self.formLayout.count())):
            item = self.formLayout.itemAt(i)
            if item and item.widget():
                item.widget().setParent(None)

        self.first = QLineEdit()
        self.type = "T"
        self.other = "P"
        self.otherunit = "(Pa)"
        self.first.setText("350")
        self.points = QLineEdit()
        self.points.setText("40")    
        self.formLayout.addRow(QLabel("T(K)"), self.first)
        self.formLayout.addRow(QLabel("Number of data points"), self.points)

    def get_omc_path(self):
        omhome = os.environ.get('OPENMODELICAHOME')
        if omhome and os.path.exists(os.path.join(omhome, 'bin', 'omc')):
            return os.path.join(omhome, 'bin', 'omc')
        elif omhome and os.path.exists(os.path.join(omhome, 'bin', 'omc.exe')):
            return os.path.join(omhome, 'bin', 'omc.exe')

        which_omc = shutil.which('omc')
        if which_omc:
            return which_omc

        import platform
        if platform.system() == "Windows":
            import glob
            pattern = r"C:\Program Files\OpenModelica*-64bit\bin\omc.exe"
            candidates = sorted(glob.glob(pattern), reverse=True)
            if candidates:
                return candidates[0]
            if os.path.exists(r"C:\Program Files\OpenModelica1.26.3-64bit\bin\omc.exe"):
                return r"C:\Program Files\OpenModelica1.26.3-64bit\bin\omc.exe"
        else:
            if os.path.exists('/usr/bin/omc'):
                return '/usr/bin/omc'
            elif os.path.exists('/opt/local/bin/omc'):
                return '/opt/local/bin/omc'
        raise FileNotFoundError("OpenModelica compiler (omc) not found on system path.")

    def _cleanup_simulation_files(self):
        try:
            import glob
            patterns = [
                os.path.join(self.sim_dir_path, 'Simulator.Graph*'),
                os.path.join(self.sim_dir_path, 'Graph.mo'),
                os.path.join(self.sim_dir_path, 'PlotGraph.mos'),
            ]
            for p in patterns:
                for f in glob.glob(p):
                    try:
                        os.remove(f)
                    except OSError:
                        pass
        except Exception:
            pass

    def plot(self):        
        if not hasattr(self, 'type') or not self.type:
            QMessageBox.warning(self, "Selection Required", "Please select either T-xy or P-xy.")
            return

        try:
            val = float(self.first.text().strip())
        except (ValueError, AttributeError):
            QMessageBox.warning(self, "Invalid Input", f"Please enter a valid numeric value for {self.type}.")
            return

        if val <= 0:
            QMessageBox.warning(self, "Invalid Input", f"{self.type} must be greater than zero.")
            return

        try:
            data_points = int(self.points.text().strip())
        except (ValueError, AttributeError):
            data_points = 40

        if data_points < 2:
            QMessageBox.warning(self, "Invalid Input", "Number of data points must be at least 2.")
            return

        self.comp1 = self.comboBox.currentText().strip()
        self.comp2 = self.comboBox_2.currentText().strip()

        if not self.comp1 or not self.comp2:
            QMessageBox.warning(self, "Selection Required", "Please select two compounds.")
            return

        self.comp_1 = _normalize_compound_name(self.comp1)
        self.comp_2 = _normalize_compound_name(self.comp2)

        if self.comp1 == self.comp2 or self.comp_1 == self.comp_2:
            QMessageBox.warning(self, "Invalid Selection", "Please select two different compounds.")
            return

        self.thermoPack = self.comboBox_3.currentText().strip()
        if not self.thermoPack:
            QMessageBox.warning(self, "Selection Required", "Please select a thermodynamic package.")
            return

        self.sim_dir_path = os.path.abspath(os.path.join(parentPath, 'Simulator', 'Simulator'))
        self.Graphmo_path = os.path.join(self.sim_dir_path, 'Graph.mo')
        self.plot_mos_path = os.path.join(self.sim_dir_path, 'PlotGraph.mos')
        binary_envelopes_path = os.path.abspath(os.path.join(parentPath, 'Simulator', 'BinaryEnvelopes.mo'))

        self._cleanup_simulation_files()

        model_code = (
            "within Simulator;\n\n"
            "model Graph\n"
            "  import data = Simulator.Files.ChemsepDatabase;\n"
            f"  parameter data.{self.comp_1} comp1;\n"
            f"  parameter data.{self.comp_2} comp2;\n"
            f"  extends BinaryEnvelopes.{self.thermoPack}(Nc = 2, data_points = {data_points}, comp = {{ comp1, comp2 }}, {self.type} = fill({val}, {data_points}));\n"
            "end Graph;\n"
        )

        with open(self.Graphmo_path, 'w') as txtfile:
            txtfile.write(model_code)

        mos_bin_path = binary_envelopes_path.replace('\\', '/')
        mos_code = (
            "loadModel(Modelica);\n"
            "loadFile(\"package.mo\");\n"
            f"loadFile(\"{mos_bin_path}\");\n"
            "loadFile(\"Graph.mo\");\n"
            "simulate(Simulator.Graph, outputFormat=\"csv\", stopTime=1.0, numberOfIntervals=1);\n"
            "getErrorString();\n"
        )

        with open(self.plot_mos_path, 'w') as mosFile:
            mosFile.write(mos_code)

        try:
            self.omc_path = self.get_omc_path()
        except FileNotFoundError as e:
            self._cleanup_simulation_files()
            QMessageBox.critical(self, "OMC Not Found", str(e))
            return

        self.curr_path = os.getcwd()
        os.chdir(self.sim_dir_path)

        try:
            process = Popen([self.omc_path, '-s', 'PlotGraph.mos'], stdout=PIPE, stderr=PIPE, text=True)
            self.stdout, self.stderr = process.communicate()
        except Exception as e:
            os.chdir(self.curr_path)
            self._cleanup_simulation_files()
            QMessageBox.critical(self, "Execution Error", f"Failed to execute OpenModelica:\n{e}")
            return

        os.chdir(self.curr_path)

        csvpath = os.path.join(self.sim_dir_path, 'Simulator.Graph_res.csv')
        if not os.path.exists(csvpath):
            error_output = (self.stdout or "") + "\n" + (self.stderr or "")
            err_lines = [line.strip() for line in error_output.splitlines() if 'error' in line.lower() or 'failed' in line.lower()]
            summary = "\n".join(err_lines[:5]) if err_lines else error_output[:300]
            self._cleanup_simulation_files()
            QMessageBox.critical(self, "Simulation Error", f"Simulation failed to produce results.\n\nDetails:\n{summary}")
            return

        self.datay = []
        self.datax1 = []
        self.datax2 = []

        try:
            with open(csvpath, 'r') as resultFile:
                csvreader = csv.reader(resultFile, delimiter=',')
                headers = next(csvreader)
                rows = list(csvreader)

            if not rows:
                QMessageBox.warning(self, "Simulation Warning", "Simulation completed but produced empty results.")
                return

            last_row = rows[-1]
            col_map = {col.strip('"'): idx for idx, col in enumerate(headers)}

            for i in range(1, data_points + 1):
                x_col = col_map.get(f"x[{i},1]")
                y_col = col_map.get(f"y[{i},1]")
                y_val_col = col_map.get(f"{self.other}[{i}]")

                if x_col is not None and y_col is not None and y_val_col is not None:
                    try:
                        self.datax1.append(float(last_row[x_col]))
                        self.datax2.append(float(last_row[y_col]))
                        self.datay.append(float(last_row[y_val_col]))
                    except (ValueError, IndexError):
                        pass
        finally:
            self._cleanup_simulation_files()

        if not self.datay or not self.datax1 or not self.datax2:
            QMessageBox.warning(self, "Plot Error", "Could not extract phase envelope data from simulation results.")
            return

        plt = pg.PlotWidget()
        plt.showGrid(x=True, y=True)
        plt.addLegend()   
        plt.setXRange(0, 1) 

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
