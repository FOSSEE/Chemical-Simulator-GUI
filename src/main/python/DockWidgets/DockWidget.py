import os, sys

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)
sys.path.append(parentPath)

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
from python.utils.ComponentSelector import *
from python.utils.Graphics import *

class BaseDockWidget(QDockWidget):
    """
    Base class for all DockWidgets in the application.
    Centralizes common methods (error popups, close events, locking UI) 
    and standardizes variable names across all simulation parameter docks.
    """
    def __init__(self, parent=None):
        super().__init__(parent)
        
        # Standardized list/dict to hold all input Qt Widgets
        self.input_dict = []
        
        # Standardized list/dict to hold final parameter values for simulation
        self.dict = []
        
    def show_error(self):
        """Standard error popup for missing or invalid data."""
        QMessageBox.about(self, 'Important', "Please fill all fields with data")

    def closeEvent(self, event):
        """Standard close event that resets horizontal scrollbar on closing."""
        try:
            if hasattr(self, 'container') and self.container:
                currentVal = self.container.graphics.graphicsView.horizontalScrollBar().value()
                self.container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal - 189)
        except Exception:
            pass

    def set_read_only(self, readonly):
        """Toggle read-only state on all input controls of a dock widget."""
        # --- 1. input_dict (dict or list) ---
        input_dict = getattr(self, 'input_dict', getattr(self, 'input_dict', {}))
        widgets = input_dict.values() if isinstance(input_dict, dict) else input_dict

        for widget in widgets:
            if isinstance(widget, QLineEdit):
                widget.setReadOnly(readonly)
            elif isinstance(widget, (QComboBox, QCheckBox, QRadioButton)):
                widget.setDisabled(readonly)

        # --- 2. Extra QLineEdit lists (e.g. x_pclist in MaterialStream) ---
        for le in getattr(self, 'x_pclist', []):
            if isinstance(le, QLineEdit):
                le.setReadOnly(readonly)

        # --- 3. Common buttons and combo boxes ---
        for attr in ('btn', 'pushButton_2', 'btn_normalize', 'btn_equalize',
                     'comboBox', 'cbTP'):
            w = getattr(self, attr, None)
            if w is not None:
                w.setDisabled(readonly)

        # --- 4. Dynamically-added Submit button (CompoundSeparator) ---
        if hasattr(self, 'calculationGroupBox'):
            grid = getattr(self, 'gridLayout', None)
            if grid:
                for i in range(grid.count()):
                    item = grid.itemAt(i)
                    if item and isinstance(item.widget(), QPushButton):
                        item.widget().setDisabled(readonly)

    def clear_results(self):
        """Clear the default table widget."""
        if hasattr(self, 'tableWidget'):
            self.tableWidget.setRowCount(0)

    @staticmethod
    def show_result(lst):
        """Iterate over all dock widgets and request them to populate results."""
        for dock_widget in lst:
            try:
                # Most subclasses implement results_category(name)
                dock_widget.results_category(dock_widget.name)
            except AttributeError:
                pass

ui_dialog,_ = loadUiType(parentPath+'/ui/DockWidgets/DockWidget.ui')

class DockWidget(BaseDockWidget,ui_dialog):
    
    def __init__(self,name,comptype,obj,container, parent=None):
        BaseDockWidget.__init__(self,parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)

        # --- Make dock content resizable ---
        # The .ui file uses absolute positioning; wrap content in a layout
        # so child widgets stretch when the dock is resized or floated.
        content = self.widget()
        if content is not None and content.layout() is None:
            layout = QVBoxLayout(content)
            layout.setContentsMargins(4, 4, 4, 4)
            # Re-parent the tabWidget into the layout
            if hasattr(self, 'tabWidget'):
                self.tabWidget.setParent(None)  # detach from absolute position
                layout.addWidget(self.tabWidget)
            content.setLayout(layout)

        # Fix Input Data tab: re-layout groupBox, groupBox_2, pushButton_2
        # which also use absolute positioning in the .ui file
        if hasattr(self, 'tab') and self.tab.layout() is None:
            tab_layout = QVBoxLayout(self.tab)
            tab_layout.setContentsMargins(6, 6, 6, 6)
            tab_layout.setSpacing(8)
            if hasattr(self, 'groupBox'):
                self.groupBox.setParent(None)
                tab_layout.addWidget(self.groupBox)
            if hasattr(self, 'groupBox_2'):
                self.groupBox_2.setParent(None)
                tab_layout.addWidget(self.groupBox_2, 1)  # stretch factor
            if hasattr(self, 'pushButton_2'):
                self.pushButton_2.setParent(None)
                tab_layout.addWidget(self.pushButton_2)
            self.tab.setLayout(tab_layout)

        # Allow free resizing when docked or floating
        self.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.setMinimumSize(250, 200)

        self.name=name
        self.obj=obj
        self.type = comptype
        self.input_dict = {}
        self.modes()
        self.comboBox.currentIndexChanged.connect(self.mode_selection)
       
        #print("constructor ", self.input_dict)
        self.pushButton_2.clicked.connect(self.param)

        self.dict = {}          # a dictionary
        self.container = container
        
    # input data tab
    def modes(self):
        modes_list = self.obj.modes_list
        if(modes_list):
            for j in modes_list:
                self.comboBox.addItem(str(self.obj.variables[j]['name']))
            self.comboBox.setCurrentText(self.obj.variables[self.obj.mode]['name'])
            self.mode_selection()
        else:
            self.comboBox.setDisabled(True)
            self.input_dict= {}
            self.input_dict = self.obj.param_getter()
            self.input_params_list()

    def mode_selection(self):
        self.input_dict= {}
        for i in reversed(range(self.formLayout.count())):
            self.formLayout.removeRow(i) 
        #print(self.comboBox.currentText())
        for i in self.obj.variables:
            if self.obj.variables[i]['name'] == self.comboBox.currentText():
                currentText = i
                break
        self.input_dict = self.obj.param_getter(currentText)
        #print('mode selection ', self.input_dict)
        self.input_params_list()
            
    def input_params_list(self):
        try:
            #print("input_params_list ", self.input_dict)
            for c,i in enumerate(self.input_dict):
                #print(i)
                if i == None:
                    continue
                l = QLineEdit(str(self.obj.variables[i]['value']))
                l.setFixedWidth(80)
                lay = QGridLayout()
                lay.addWidget(QLabel(self.obj.variables[i]['name']+":"),0,0, alignment=Qt.AlignLeft)
                lay.addWidget(l,0,1, alignment=Qt.AlignCenter)
                lay.addWidget(QLabel(self.obj.variables[i]['unit']),0,2, alignment=Qt.AlignLeft)
                self.formLayout.addRow(lay)
                self.input_dict[i] = l
        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)
        # moved the function to BaseDockWidget class ( )

    def param(self):
        try:
            self.dict = {}
            #print("param.input_dict ", self.input_dict)
            for i in self.input_dict:
                if (self.input_dict[i] == None):
                    continue                  
                else:
                    #print(self.input_dict[i], i, self.obj.type)
                    if (self.input_dict[i].text()):
                        self.dict[i] = self.input_dict[i].text()
                    else:
                        #print(self.input_dict[i].text())
                        self.show_error()
                        break
            
            #print("param ", self.dict)
            self.obj.param_setter(self.dict)
            print(f"[UI] Submit successful for {self.name}")

            for i in self.container.graphics.graphicsView.items():
                try: 
                    if(i.name == self.name):
                        i.update_tooltip()
                except:
                    pass
            if(self.isVisible()):
                #added try block to safely handle the errors
                try:
                    currentVal = self.container.graphics.graphicsView.horizontalScrollBar().value()
                    self.container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal-189)
                except Exception:
                    pass
            self.hide()
            
        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)

    # moved the function to BaseDockWidget class
    # result data tab
    def results_category(self,name):
        flag = True
        try:
            #print("Under result category name ", name)
            result=self.container.result
            obj = self.container.fetch_object(name)
            self.tableWidget.setRowCount(0)
            variKeys = list(obj.variables.keys())
            #print(variKeys)
            for i, val in enumerate(variKeys):
                propertyname = name + '.' + val
                #print(i,val, propertyname)
                if propertyname in result[0]:
                    ind = result[0].index(propertyname)
                    resultval = str(result[-1][ind])
                    #print("######Resultsfetch####",val,resultval)
                    rowPosition = self.tableWidget.rowCount()
                    self.tableWidget.insertRow(rowPosition)
                    self.tableWidget.setItem(rowPosition , 0, QTableWidgetItem(obj.variables[val]['name']))
                    self.tableWidget.setItem(rowPosition , 1, QTableWidgetItem(resultval))
                    self.tableWidget.setItem(rowPosition , 2, QTableWidgetItem(obj.variables[val]['unit']))
                    self.tableWidget.resizeColumnsToContents()

                    # Updating result in class
                    obj.variables[val]['value'] = resultval
                    # try:
                    #     if obj.type == "Heater":
                    #         print(obj.variables[val]['name'] + str(obj.variables[val]['value']))
                    # except Exception as e:
                    #     print(e)



        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)
            # moved the function to BaseDockWidget class