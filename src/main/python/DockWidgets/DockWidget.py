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

    def showEvent(self, event):
        super().showEvent(event)
        curr_name = getattr(self, 'name', None) or getattr(getattr(self, 'obj', None), 'name', None)
        if hasattr(self, 'le_name') and curr_name:
            self.le_name.setText(curr_name)

    def setup_name_editor(self):
        """
        Creates and returns a QWidget containing the Name editor layout:
            Name: [ Component Name ] [OK]
        Sets up self.name_widget, self.le_name, and self.btn_name.
        """
        if hasattr(self, 'name_widget') and self.name_widget is not None:
            return self.name_widget

        self.name_widget = QWidget(self)
        layout = QHBoxLayout(self.name_widget)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.setSpacing(6)

        self.lbl_name = QLabel("Name: ", self.name_widget)
        self.lbl_name.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Preferred)
        initial_name = getattr(self, 'name', None) or getattr(getattr(self, 'obj', None), 'name', '')
        self.le_name = QLineEdit(str(initial_name), self.name_widget)
        self.le_name.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        self.btn_name = QPushButton("OK", self.name_widget)
        self.btn_name.setFixedWidth(50)

        layout.addWidget(self.lbl_name)
        layout.addWidget(self.le_name)
        layout.addWidget(self.btn_name)

        self.btn_name.clicked.connect(self.rename_component)
        self.le_name.returnPressed.connect(self.rename_component)

        return self.name_widget

    def get_node_item(self):
        """Find the corresponding NodeItem on the canvas."""
        if hasattr(self, 'node_item') and self.node_item:
            return self.node_item

        try:
            from python.utils.Graphics import lst
            for item in lst:
                if getattr(item, 'dock_widget', None) is self or (hasattr(self, 'obj') and getattr(item, 'obj', None) is self.obj):
                    self.node_item = item
                    return item
        except Exception:
            pass

        if hasattr(self, 'container') and self.container and hasattr(self.container, 'graphics') and hasattr(self.container.graphics, 'scene'):
            try:
                for item in self.container.graphics.scene.items():
                    if getattr(item, 'dock_widget', None) is self or (hasattr(self, 'obj') and getattr(item, 'obj', None) is self.obj):
                        self.node_item = item
                        return item
            except Exception:
                pass

        return None

    def rename_component(self):
        """
        Renames the component to the text in self.le_name.
        Validates the new name, updates model object, dock widget,
        canvas NodeItem, results, and pushes an undo snapshot.
        """
        old_name = getattr(self, 'name', None) or (self.obj.name if hasattr(self, 'obj') and self.obj else "")
        if not hasattr(self, 'le_name'):
            return True

        new_name = self.le_name.text().strip()

        # If name hasn't changed, nothing to do
        if new_name == old_name:
            return True

        # Validation 1: cannot be empty
        if not new_name:
            QMessageBox.warning(self, "Invalid Name", "Component name cannot be empty.")
            self.le_name.setText(old_name)
            return False

        # Validation 2: valid OpenModelica / Python identifier
        import re
        if not re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', new_name):
            QMessageBox.warning(
                self,
                "Invalid Name",
                "Component name must start with a letter or underscore and contain only alphanumeric characters or underscores."
            )
            self.le_name.setText(old_name)
            return False

        # Validation 3: uniqueness check
        existing_names = set()
        if hasattr(self, 'container') and self.container:
            for op in getattr(self.container, 'unit_operations', []):
                if op is not getattr(self, 'obj', None):
                    existing_names.add(getattr(op, 'name', ''))

        try:
            from python.utils.Graphics import lst
            for item in lst:
                if hasattr(item, 'obj') and item.obj is not getattr(self, 'obj', None):
                    existing_names.add(getattr(item, 'name', ''))
        except Exception:
            pass

        if new_name in existing_names:
            QMessageBox.warning(
                self,
                "Duplicate Name",
                f"A component named '{new_name}' already exists. Please choose a different name."
            )
            self.le_name.setText(old_name)
            return False

        # 1. Update Model object
        if hasattr(self, 'obj') and self.obj:
            self.obj.name = new_name
            if hasattr(self.obj, 'EngStms') and hasattr(self.obj.EngStms, 'name'):
                self.obj.EngStms.name = 'EngStm' + new_name
            if hasattr(self.obj, 'EngStm1') and hasattr(self.obj.EngStm1, 'name'):
                self.obj.EngStm1.name = 'EngStm1' + new_name
            if hasattr(self.obj, 'EngStm2') and hasattr(self.obj.EngStm2, 'name'):
                self.obj.EngStm2.name = 'EngStm2' + new_name

        # 2. Update DockWidget attributes and title
        self.name = new_name
        self.setWindowTitle(new_name)
        self.le_name.setText(new_name)

        # 3. Update Canvas NodeItem
        node_item = self.get_node_item()
        if node_item is not None:
            node_item.name = new_name
            if hasattr(node_item, 'text') and node_item.text:
                node_item.text.setPlainText(new_name)
            if hasattr(node_item, 'update_tooltip'):
                node_item.update_tooltip()

        # 4. Update simulation results headers if results already exist
        if hasattr(self, 'container') and self.container and getattr(self.container, 'result', None):
            res = self.container.result
            if isinstance(res, (list, tuple)) and len(res) > 0 and isinstance(res[0], list):
                old_prefix = f"{old_name}."
                new_prefix = f"{new_name}."
                res[0] = [
                    (new_prefix + col[len(old_prefix):]) if col.startswith(old_prefix) else col
                    for col in res[0]
                ]
            if hasattr(self, 'results_category'):
                try:
                    self.results_category(new_name)
                except Exception:
                    pass

        # Also update result_data on flowsheet if present
        if hasattr(self, 'container') and self.container and hasattr(self.container, 'flowsheet'):
            fs_res = getattr(self.container.flowsheet, 'result_data', None)
            if isinstance(fs_res, (list, tuple)) and len(fs_res) > 0 and isinstance(fs_res[0], list):
                old_prefix = f"{old_name}."
                new_prefix = f"{new_name}."
                fs_res[0] = [
                    (new_prefix + col[len(old_prefix):]) if col.startswith(old_prefix) else col
                    for col in fs_res[0]
                ]

        # 5. Push Undo snapshot
        if hasattr(self, 'container') and self.container and hasattr(self.container, 'graphics'):
            try:
                self.container.graphics.push_snapshot()
            except Exception as e:
                print(f"[DEBUG] rename push_snapshot failed: {e}")

        return True

    def check_and_rename_if_needed(self):
        """Helper to sync name from line edit if modified before submit."""
        if hasattr(self, 'le_name') and hasattr(self, 'name'):
            current_text = self.le_name.text().strip()
            if current_text and current_text != self.name:
                return self.rename_component()
        return True

    def set_read_only(self, readonly):
        """Toggle read-only state on all input controls of a dock widget."""
        # --- 1. input_dict (dict or list) ---
        input_dict = getattr(self, 'input_dict', getattr(self, 'input_dict', {}))
        widgets = input_dict.values() if isinstance(input_dict, dict) else input_dict

        for widget in widgets:
            if isinstance(widget, QLineEdit):
                widget.setDisabled(readonly)
            elif isinstance(widget, (QComboBox, QCheckBox, QRadioButton)):
                widget.setDisabled(readonly)

        # --- 2. Extra QLineEdit lists (e.g. x_pclist in MaterialStream) ---
        for le in getattr(self, 'x_pclist', []):
            if isinstance(le, QLineEdit):
                le.setDisabled(readonly)

        # --- 3. Common buttons, line edits, and combo boxes ---
        for attr in ('btn', 'pushButton_2', 'btn_normalize', 'btn_equalize',
                     'comboBox', 'cbTP', 'le_name', 'btn_name'):
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
        self.name=name
        self.obj=obj
        self.type = comptype
        self.container = container
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
            tab_layout.addWidget(self.setup_name_editor())
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
        elif hasattr(self, 'tab') and self.tab.layout() is not None:
            self.tab.layout().insertWidget(0, self.setup_name_editor())

        # Allow free resizing when docked or floating
        self.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.setMinimumSize(250, 200)

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
            if self.obj.mode in self.obj.variables:
                self.comboBox.setCurrentText(self.obj.variables[self.obj.mode]['name'])
            else:
                self.comboBox.setCurrentIndex(0)
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
            if hasattr(self, 'check_and_rename_if_needed'):
                if not self.check_and_rename_if_needed():
                    return
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