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

from python.DockWidgets.DockWidget import BaseDockWidget

ui_dialog,_ = loadUiType(parentPath+'/ui/DockWidgets/DockWidgetMaterialStream.ui')

class DockWidgetMaterialStream(BaseDockWidget, ui_dialog):

    def __init__(self, name, comptype, obj, container, parent=None):
        BaseDockWidget.__init__(self, parent)
        self.setupUi(self)
        self.setWindowTitle(obj.name)

        self.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.tabWidget.setParent(None)
        self.tabWidget.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        _content = QWidget()
        _contentLayout = QVBoxLayout(_content)
        _contentLayout.setContentsMargins(0, 0, 0, 0)
        _contentLayout.addWidget(self.tabWidget)
        self.setWidget(_content)

        self.name = name
        self.obj = obj
        self.type = comptype
        self.input_dict = {}
        self.x_pclist = []

        self.setMinimumWidth(240)
        self._has_autosized = False

        self.comboBox.currentIndexChanged.connect(self.mode_selection)
        self.pushButton_2.clicked.connect(self.param)

        self.btn_normalize = QPushButton("Normalize")
        self.btn_equalize = QPushButton("Equalize")
        self.btn_normalize.clicked.connect(self.normalize)
        self.btn_equalize.clicked.connect(self.equalize)

        self.dict = {}  # a dictionary

        self.name_type = None
        self.container = container

        #  dropdown 
        self._composition_basis_options = [
            'Mole Fraction', 'Mass Fraction', 'Mole Flow', 'Mass Flow'
        ]
        for opt in self._composition_basis_options:
            self.cbCompositionBasis.addItem(opt)
        self.cbCompositionBasis.setCurrentIndex(0)
        self.cbCompositionBasis.currentIndexChanged.connect(
            self._on_composition_basis_changed
        )

        # Storage for amounts results: { basis_name: { phase_no: [(compound, value)] } }
        # phase_no: 1=Mixture, 2=Liquid, 3=Vapour
        self._amounts_data = {}
        for basis in self._composition_basis_options:
            self._amounts_data[basis] = {1: [], 2: [], 3: []}

        # --- Corrected Thermo Package file reading ---
        if getattr(sys, 'frozen', False):
            # Running as PyInstaller executable
            base_path = sys._MEIPASS
        else:
            # Running as normal Python script
            base_path = parentPath

        thermo_file = os.path.join(base_path, 'python', 'utils', 'thermopackage.txt')
        lines = []
        try:
            with open(thermo_file, 'r') as f:
                lines = [line.rstrip('\n') for line in f]
        except Exception as e:
            print("Error reading thermopackage.txt:", e)

        for j in lines:
            self.cbTP.addItem(str(j))

        # --- Place all Input Data controls directly in the tab ---
        # No inner QScrollArea: the controls live straight in the tab's layout
        # so they always fill the whole panel instead of a small sub-region.
        widgets_to_move = []
        if hasattr(self, 'groupBox'): widgets_to_move.append(self.groupBox)
        if hasattr(self, 'groupBox_2'): widgets_to_move.append(self.groupBox_2)
        if hasattr(self, 'groupBox_3'): widgets_to_move.append(self.groupBox_3)
        if hasattr(self, 'pushButton_2'): widgets_to_move.append(self.pushButton_2)
        widgets_to_move.append(self.btn_normalize)
        widgets_to_move.append(self.btn_equalize)

        # Clear whatever the .ui left in the Input Data tab layout.
        while self.verticalLayout_5.count():
            item = self.verticalLayout_5.takeAt(0)
            if item.widget():
                item.widget().setParent(None)

        # The .ui pins this layout to QLayout::SetFixedSize, which clamps the
        # content to a tiny fixed region. Let it follow the panel size instead.
        self.verticalLayout_5.setSizeConstraint(QLayout.SetDefaultConstraint)
        self.verticalLayout_5.setContentsMargins(8, 8, 8, 8)
        self.verticalLayout_5.setSpacing(8)
        for w in widgets_to_move:
            w.setParent(None)
            self.verticalLayout_5.addWidget(w)
        # Stretch keeps controls anchored at the top when the panel is tall.
        self.verticalLayout_5.addStretch()

        QWIDGETSIZE_MAX = 16777215
        for _lay in self.findChildren(QLayout):
            if _lay.sizeConstraint() == QLayout.SetFixedSize:
                _lay.setSizeConstraint(QLayout.SetDefaultConstraint)
        self.tab.setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX)
        for _gb in (getattr(self, 'groupBox', None),
                    getattr(self, 'groupBox_2', None),
                    getattr(self, 'groupBox_3', None)):
            if _gb is not None:
                _gb.setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX)
                _gb.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Maximum)

        self.modes()

    def showEvent(self, event):
        super().showEvent(event)
        if not self._has_autosized:
            QTimer.singleShot(0, self._autosize)

    def _autosize(self):
        if self._has_autosized:
            return
        try:
            self.tabWidget.adjustSize()
            content_w = self.verticalLayout_5.sizeHint().width()
            content_h = self.verticalLayout_5.sizeHint().height()

            screen = QApplication.primaryScreen().availableGeometry()
            # comfortable bounds so nothing is clipped, capped to the screen.
            desired_w = min(max(300, content_w + 30), int(screen.width() * 0.4))
            desired_h = min(max(440, content_h + 90), int(screen.height() * 0.85))

            mw = self.parent()
            if isinstance(mw, QMainWindow) and not self.isFloating():
                mw.resizeDocks([self], [desired_w], Qt.Horizontal)
                mw.resizeDocks([self], [desired_h], Qt.Vertical)
            else:
                self.resize(desired_w, desired_h)
            self._has_autosized = True
        except Exception as e:
            print(e)

    # ------------------- input data tab -------------------
    def modes(self):
        modes_list = self.obj.modes_list
        if modes_list:
            for j in modes_list:
                self.comboBox.addItem(str(j))
            self.comboBox.setCurrentText(self.obj.mode)
            self.mode_selection()
        else:
            self.input_dict = self.obj.param_getter()
            self.input_params_list()

    def mode_selection(self):
        self.input_dict = {}
        try:
            for i in reversed(range(self.formLayout.count())):
                self.formLayout.removeRow(i)
        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)
        self.input_dict = self.obj.param_getter(self.comboBox.currentText())
        self.obj.mode = self.comboBox.currentText()
        self.input_params_list()

    def input_params_list(self):
        try:
            for c, i in enumerate(self.input_dict):
                if i == "x_pc":
                    noc = len(compound_selected)
                    self.x_pclist.clear()

                    self.comp_gb = QGroupBox("Mole Fractions")
                    lay = QGridLayout()
                    for j in range(noc):
                        try:
                            l = QLineEdit(str(self.obj.variables['x_pc']['value'][j]))
                        except:
                            l = QLineEdit()
                        l.setFixedWidth(100)
                        self.input_dict[i] = "x_pc"
                        lay.addWidget(QLabel(str(compound_selected[j]) + ":"), j, 0, alignment=Qt.AlignLeft)
                        lay.addWidget(l, j, 1, alignment=Qt.AlignCenter)
                        self.x_pclist.append(l)
                    self.comp_gb.setLayout(lay)
                    self.formLayout.addRow(self.comp_gb)
                elif i == "Thermo Package":
                    self.cbTP.setCurrentText(self.input_dict[i])
                else:
                    l = QLineEdit()
                    if self.input_dict[i] is not None:
                        l.setText(str(self.input_dict[i]))
                    l.setFixedWidth(80)
                    lay = QGridLayout()
                    if i != 'MolFlow':
                        lay.addWidget(QLabel(self.obj.variables[i]['name'] + ":"), 0, 0, alignment=Qt.AlignLeft)
                    else:
                        lay.addWidget(QLabel(i + ":"), 0, 0, alignment=Qt.AlignLeft)
                    lay.addWidget(l, 0, 1, alignment=Qt.AlignCenter)
                    if i != 'MolFlow':
                        lay.addWidget(QLabel(self.obj.variables[i]['unit']), 0, 2, alignment=Qt.AlignLeft)
                    else:
                        lay.addWidget(QLabel("mol/s"), 0, 2, alignment=Qt.AlignLeft)
                    self.formLayout.addRow(lay)
                    self.input_dict[i] = l
        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)

    # ------------------- Remaining methods unchanged -------------------
    def update_compounds(self):
        try:
            noc = len(compound_selected)
            self.x_pclist.clear()

            lay = QGridLayout()
            for j in range(noc):
                l = QLineEdit()
                lay.addWidget(QLabel(str(compound_selected[j]) + ":"), j, 0, alignment=Qt.AlignLeft)
                lay.addWidget(l, j, 1, alignment=Qt.AlignCenter)
                self.x_pclist.append(l)
            self.comp_gb.setLayout(lay)
            indexx = self.comboBox.currentIndex()
            self.comboBox.setCurrentIndex(1)
            self.comboBox.setCurrentIndex(indexx)
            if hasattr(self.obj, 'update_compounds'):
                self.obj.update_compounds()
            self.obj.init_variables()
        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)

    def param(self):
        try:
            self.dict = {}
            for i in self.input_dict:
                if i == "x_pc":
                    l = []
                    mf = []
                    total_moles = 0
                    for mol_frac in self.x_pclist:
                        if mol_frac.text():
                            l.append(mol_frac.text())
                            total_moles += float(l[-1])
                        else:
                            self.show_error()
                            break
                    for c in range(len(compound_selected)):
                        mf.append(str(float(l[c]) / total_moles))
                        self.obj.variables[compound_selected[c]]['value'] = str(float(l[c]) / total_moles)
                        self.x_pclist[c].setText(mf[-1])
                    self.dict[i] = ",".join(mf)
                elif i == "Thermo Package":
                    self.dict[i] = self.cbTP.currentText()
                else:
                    if self.input_dict[i].text():
                        self.dict[i] = self.input_dict[i].text()
                    else:
                        self.show_error()
                        break

            self.obj.param_setter(self.dict)

            print(f"[UI] Submit successful for {self.name}")
            for i in self.container.graphics.graphicsView.items():
                try:
                    if i.name == self.name:
                        i.update_tooltip()
                except:
                    pass
            if self.isVisible():
                #added try block to safely handle the errors
                try:
                    currentVal = self.container.graphics.graphicsView.horizontalScrollBar().value()
                    self.container.graphics.graphicsView.horizontalScrollBar().setValue(currentVal - 189)
                except Exception:
                    pass
            self.hide()

        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)

    def update_input_values(self):
        self.init()

    @staticmethod
    def show_result(ms_lst):
        for i in ms_lst:
            i.results_category(i.name)

    def clear_results(self):
        # Clear amounts tables
        self.amountsMixtureTable.setRowCount(0)
        self.amountsLiquidTable.setRowCount(0)
        self.amountsVapourTable.setRowCount(0)
        # Clear phase properties tables
        self.mTableWidget.setRowCount(0)
        self.lTableWidget.setRowCount(0)
        self.vTableWidget.setRowCount(0)
        # Reset stored amounts data
        for basis in self._composition_basis_options:
            self._amounts_data[basis] = {1: [], 2: [], 3: []}

    # result data tab
    def results_category(self,name):
        try:
            #print("Under result category name ", name)
            result=self.container.result
            obj = self.container.fetch_object(name)

            def _safe_result(val):
                if val.replace('.','',1).replace('-','',1).replace('e','',1).replace('+','',1).isdigit():
                    return str(round(float(val), 4))
                return val


            d = {"Mole Fraction":"x_pc", "Mass Fraction":"xm_pc", "Mole Flow":"F_pc", "Mass Flow":"Fm_pc"}
            ms_lst = list(d.keys())
            klst = list(d.values())

            p = {"Pressure":"P", "Temperature":"T","Vapour Phase Mole Fraction":"xvap",
            "Molar Specific Heat":"Cp_p", "Phase Molar Enthalpy":"H_p", 
            "Phase Molar Entropy":"S_p", "Molar Flow Rate":"F_p","Mass Flow Rate":"Fm_p",
            "Average Molecular Weight":"MW_p"}

            # Amounts Tab — populate _amounts_data dict
            if obj.type == 'MaterialStream':
                # Reset stored data
                for basis in self._composition_basis_options:
                    self._amounts_data[basis] = {1: [], 2: [], 3: []}

                ll = []  # list for basis names
                for basis in d:
                    propertyname = name + '.' + d[basis]
                    for i in result[0]:
                        if (propertyname in i):
                            ll.append(i)
                j = 0
                namee = 'none'

                for i, k in enumerate(ll):
                    ind = result[0].index(k)
                    resultval = str(result[-1][ind])
                    obj.variables[k.split('.')[1]]['value'] = resultval

                    if namee not in k:
                        namee = klst[j]

                    phase_no = int(k[k.index(',') - 1])  # phase no from modelica list
                    compound_no = int(k[k.index(',') + 1]) - 1  # compound from python list

                    self._amounts_data[ms_lst[j]][phase_no].append(
                        (compound_selected[compound_no], _safe_result(resultval))
                    )

                    if phase_no == 3 and (compound_no + 1) == len(compound_selected):
                        j += 1

                # Refresh the visible amounts tables for the currently selected basis
                self._on_composition_basis_changed()

                # Phase Properties Tab
                phaseResLst = []
                for phase in p:
                    propertyname = name + '.' + p[phase]
                    #print("phase ", phase, propertyname)
                    for i in result[0]:
                        if '[' in i:
                            if (propertyname == i[0:i.find('[')]):
                                phaseResLst.append(i)
                        elif propertyname == i:
                            phaseResLst.append(i)
                #print(phaseResLst)
                
                self.mTableWidget.setRowCount(0)
                self.lTableWidget.setRowCount(0)
                self.vTableWidget.setRowCount(0)

                for i,val in enumerate(phaseResLst):
                    ind = result[0].index(val)
                    resultval = str(result[-1][ind])
                    #print(resultval, i, val)
                    obj.variables[val.split('.')[1]]['value'] = resultval
                    if '[' in val:
                        #print(val)
                        temp = val[val.find('.')+1:val.find('[')]
                        #print(temp)
                        if '1' in val.split('.')[1]:
                            #print(obj.variables[val.split('.')[1]]['name'])
                            mrowPosition = self.mTableWidget.rowCount()
                            self.mTableWidget.insertRow(mrowPosition)
                            self.mTableWidget.setItem(mrowPosition , 0, QTableWidgetItem(obj.variables[val.split('.')[1]]['name']))
                            self.mTableWidget.setItem(mrowPosition , 1, QTableWidgetItem(_safe_result(resultval)))
                            self.mTableWidget.setItem(mrowPosition , 2, QTableWidgetItem(obj.variables[val.split('.')[1]]['unit']))
                            self.mTableWidget.resizeColumnsToContents() 
                                                 
                        if '2' in val.split('.')[1]:       
                            lrowPosition = self.lTableWidget.rowCount()
                            self.lTableWidget.insertRow(lrowPosition)
                            self.lTableWidget.setItem(lrowPosition , 0, QTableWidgetItem(obj.variables[val.split('.')[1]]['name']))
                            self.lTableWidget.setItem(lrowPosition , 1, QTableWidgetItem(_safe_result(resultval)))
                            self.lTableWidget.setItem(lrowPosition , 2, QTableWidgetItem(obj.variables[val.split('.')[1]]['unit']))
                            self.lTableWidget.resizeColumnsToContents()                         
                        if '3' in val.split('.')[1]:   
                            vrowPosition = self.vTableWidget.rowCount()
                            self.vTableWidget.insertRow(vrowPosition)
                            self.vTableWidget.setItem(vrowPosition , 0, QTableWidgetItem(obj.variables[val.split('.')[1]]['name']))
                            self.vTableWidget.setItem(vrowPosition , 1, QTableWidgetItem(_safe_result(resultval)))
                            self.vTableWidget.setItem(vrowPosition , 2, QTableWidgetItem(obj.variables[val.split('.')[1]]['unit']))
                            self.vTableWidget.resizeColumnsToContents()                                
                    if not '[' in val:
                        #print(obj.variables[val.split('.')[1]]['name'])
                        mrowPosition = self.mTableWidget.rowCount()
                        self.mTableWidget.insertRow(mrowPosition)
                        self.mTableWidget.setItem(mrowPosition , 0, QTableWidgetItem(obj.variables[val.split('.')[1]]['name']))
                        self.mTableWidget.setItem(mrowPosition , 1, QTableWidgetItem(str(round(float(resultval),4)) if resultval.replace('.','',1).replace('-','',1).replace('e','',1).replace('+','',1).isdigit() else resultval))
                        self.mTableWidget.setItem(mrowPosition , 2, QTableWidgetItem(obj.variables[val.split('.')[1]]['unit']))
                        self.mTableWidget.resizeColumnsToContents() 


            # updating the input data from fetched results from simulation
            #print(self.comboBox.currentText())
       
            self.input_dict = {}
            self.input_dict = self.obj.param_getter(self.comboBox.currentText())
            # print("before", self.input_dict)
            for i in range(len(compound_selected)):
                #print(i)
                self.input_dict['x_pc[1,' + str(i+1) + ']'] = self.obj.variables['x_pc[1,' + str(i+1) +']']['value']
            # self.input_dict['thermo_package'] = temp
            # print("after", self.input_dict)
            
            # changing index for updating the input data
            indexx = self.comboBox.currentIndex()
            self.comboBox.setCurrentIndex(1)
            self.comboBox.setCurrentIndex(indexx)

            try:

                for i in self.parent().container.graphics.graphicsView.items():
                    try:
                        if i.obj == self.obj:
                            i.update_tooltip()
                    except Exception as e:
                        pass
            except Exception as e:
                print(e)


        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)
        
    def equalize(self):
        try:
            noc = len(self.x_pclist)
            if noc > 0:
                val = 1.0 / noc
                sum_val = 0
                for i in range(noc - 1):
                    v = round(val, 4)
                    self.x_pclist[i].setText(str(v))
                    sum_val += v
                self.x_pclist[-1].setText(str(round(1.0 - sum_val, 4)))
        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)

    def normalize(self):
        try:
            values = []
            for l in self.x_pclist:
                try:
                    t = l.text().strip()
                    if not t:
                        v = 0.0
                    else:
                        v = float(t)
                except ValueError:
                    v = 0.0
                values.append(v)

            total = sum(values)
            if total > 0:
                sum_norm = 0
                for i in range(len(self.x_pclist) - 1):
                    normalized_val = round(values[i] / total, 4)
                    self.x_pclist[i].setText(str(normalized_val))
                    sum_norm += normalized_val
                self.x_pclist[-1].setText(str(round(1.0 - sum_norm, 4)))
            else:
                self.show_error()
        except Exception as e:
            print(f"[UI] Submit failed for {self.name}: {e}")
            print(e)

    # ------------------- Amounts: Composition Basis switching -------------------
    def _on_composition_basis_changed(self, index=None):
        """Refresh the three Amounts phase tables for the currently selected basis."""
        basis = self.cbCompositionBasis.currentText()
        data = self._amounts_data.get(basis, {1: [], 2: [], 3: []})
        self._populate_amounts_table(self.amountsMixtureTable, data.get(1, []))
        self._populate_amounts_table(self.amountsLiquidTable, data.get(2, []))
        self._populate_amounts_table(self.amountsVapourTable, data.get(3, []))

    @staticmethod
    def _populate_amounts_table(table, rows):
        """Fill a QTableWidget with (compound, value) rows."""
        table.setRowCount(0)
        for compound, value in rows:
            row_pos = table.rowCount()
            table.insertRow(row_pos)
            table.setItem(row_pos, 0, QTableWidgetItem(compound))
            table.setItem(row_pos, 1, QTableWidgetItem(str(value)))
        table.resizeColumnsToContents()
