from PyQt5.QtCore import QThread, pyqtSignal, Qt, QStringListModel
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import os, sys
import pandas as pd

current = os.path.dirname(os.path.realpath(__file__))
parent = os.path.dirname(current)
parentPath = os.path.dirname(parent)
sys.path.append(parent)

from Simulator.Databases.Databases import ChemsepDatabase
ui_dialog, _ = loadUiType(parentPath + '/ui/utils/ComponentSelector.ui')

compound_selected = []  # list storing selected components


# ----------------------------
# Background Loader Thread
# ----------------------------
class CompoundLoader(QThread):
    data_loaded = pyqtSignal(list)

    def __init__(self, instance_list):
        super().__init__()
        self.instance_list = instance_list

    def run(self):
        compounds_data = []
        dict1 = {}
        lines = []

        for i in self.instance_list:
            x = i.get_comp_name_list()
            dict1[i] = x
            lines += x

        for comp in lines:
            obj = None
            for ele in dict1:
                if comp in dict1[ele]:
                    obj = ele
                    break
            if obj is None:
                continue

            try:
                comp_clean = comp.replace('(' + obj.name + ')', '')
                compounds_data.append({
                    "Name": comp_clean,
                    "CAS": obj.get_value(comp_clean, "CAS"),
                    "Formula": obj.get_value(comp_clean, "StructureFormula"),
                    "MW": obj.get_value(comp_clean, "MolecularWeight")
                })
            except Exception:
                pass

        self.data_loaded.emit(compounds_data)


# ----------------------------
# Main Dialog
# ----------------------------
class ComponentSelector(QDialog, ui_dialog):
    # will change the compound dynamically to the selected compounds box
    compounds_changed = pyqtSignal()
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setupUi(self)
        self.resize(1100, 700)

        # --- Initialize core data structures ---
        self.compound_map = {}          # ✅ fix for missing attribute
        self.compounds_data = []        
        self.filtered_data = []
        self.selected_names_set = set()
        self.selected_names_list = []

        # --- Show temporary loading message ---
        self.tableWidget.setRowCount(1)
        self.tableWidget.setColumnCount(1)
        self.tableWidget.setHorizontalHeaderLabels(["Loading..."])
        self.tableWidget.setItem(0, 0, QTableWidgetItem("Loading compounds... please wait"))

        # --- Start background loader ---
        self.loader = CompoundLoader([ChemsepDatabase()])
        self.loader.data_loaded.connect(self.on_data_loaded)
        self.loader.start()

        # --- Find "Added Compounds" QLineEdit safely ---
        self.added_lineedit = getattr(self, 'lineEdit_2', None)
        if self.added_lineedit is None:
            for child in self.findChildren(QLineEdit):
                n = child.objectName().lower()
                if 'add' in n or 'compound' in n or 'selected' in n:
                    self.added_lineedit = child
                    break

        # --- Connect UI signals ---
        self.pushButton.clicked.connect(self.accept)
        self.pushButton_2.clicked.connect(self.cancel)
        self.lineEdit.textChanged.connect(self.filter_table)


    # ----------------------------
    # Data Loaded (async callback)
    # ----------------------------
    def on_data_loaded(self, compounds_data):
        self.compounds_data = compounds_data
        self.compound_map = {c['Name']: c for c in compounds_data}

        # setup completer
        self.model = QStringListModel([c["Name"] for c in compounds_data])
        self.completer = QCompleter(self.model)
        self.completer.setCaseSensitivity(Qt.CaseInsensitive)
        self.lineEdit.setCompleter(self.completer)
        self.completer.activated[str].connect(self.on_completer_selected)

        # setup table
        self.tableWidget.setColumnCount(5)
        self.tableWidget.setHorizontalHeaderLabels(
            ["Select", "Name", "CAS", "Molecular Formula", "Molecular Weight"]
        )
        self.tableWidget.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)

        # populate table
        self.filtered_data = compounds_data[:]
        self.load_table()

    # ----------------------------
    # Table Management
    # ----------------------------
    def load_table(self):
        self.tableWidget.setRowCount(0)
        for comp in self.filtered_data:
            row_dict = {
                "Name": comp["Name"],
                "CAS": comp["CAS"],
                "Molecular Formula": comp["Formula"],
                "Molecular Weight": comp["MW"]
            }
            self.add_to_table(row_dict)

    def add_to_table(self, a):
        try:
            name = str(a.get('Name', ''))
            row_position = self.tableWidget.rowCount()
            self.tableWidget.insertRow(row_position)

            checkbox = QCheckBox()
            checkbox.setChecked(name in self.selected_names_set)
            checkbox.stateChanged.connect(lambda state, nm=name: self.on_checkbox_state_changed(nm, state))

            container = QWidget()
            lay = QHBoxLayout(container)
            lay.setContentsMargins(0, 0, 0, 0)
            lay.setAlignment(Qt.AlignCenter)
            lay.addWidget(checkbox)
            self.tableWidget.setCellWidget(row_position, 0, container)

            self.tableWidget.setItem(row_position, 1, QTableWidgetItem(name))
            self.tableWidget.setItem(row_position, 2, QTableWidgetItem(str(a.get('CAS', ''))))
            self.tableWidget.setItem(row_position, 3, QTableWidgetItem(str(a.get('Molecular Formula', ''))))
            self.tableWidget.setItem(row_position, 4, QTableWidgetItem(str(a.get('Molecular Weight', ''))))
        except Exception as e:
            print("add_to_table error:", e)

    # ----------------------------
    # Search & Filtering
    # ----------------------------
    def filter_table(self):
        text = self.lineEdit.text().lower()
        self.filtered_data = [
            c for c in self.compounds_data
            if text in c["Name"].lower()
            or text in c["CAS"].lower()
            or text in c["Formula"].lower()
        ]
        self.load_table()

    def on_completer_selected(self, text):
        self.lineEdit.setText(text)
        self.filter_table()

    # ----------------------------
    # Checkbox Management
    # ----------------------------
    def on_checkbox_state_changed(self, name, state):
        if state == Qt.Checked:
            if name not in self.selected_names_set:
                self.selected_names_set.add(name)
                self.selected_names_list.append(name)
        else:
            if name in self.selected_names_set:
                self.selected_names_set.remove(name)
                try:
                    self.selected_names_list.remove(name)
                except ValueError:
                    pass
        self.update_added_compounds()
        self.compounds_changed.emit()

    def update_added_compounds(self):
        text = ", ".join(self.selected_names_list)
        if self.added_lineedit:
            self.added_lineedit.setText(text)

    # ----------------------------
    # Get / Set Selection
    # ----------------------------
    def get_selected_compounds(self):
        selected = []
        for name in self.selected_names_list:
            data = self.compound_map.get(name)
            if data:
                selected.append({
                    "Name": data["Name"],
                    "CAS": data.get("CAS", ""),
                    "Formula": data.get("Formula", ""),
                    "MW": data.get("MW", "")
                })
        return selected

    def set_compounds(self, compounds):
        self.selected_names_set.clear()
        self.selected_names_list.clear()
        for name in compounds:
            if name in self.compound_map:
                self.selected_names_set.add(name)
                self.selected_names_list.append(name)
        self.update_added_compounds()
        self.load_table()

    # ----------------------------
    # OK / Cancel Handling
    # ----------------------------

    def get_compounds(self):
        """
        Returns the list of selected compounds.
        This is used by the simulator when generating .mo file.
        """
        try:
            if hasattr(self, "selected_compounds"):
                return self.selected_compounds
            elif hasattr(self, "compounds"):
                return self.compounds
            else:
                return []
        except Exception as e:
            print(f"[DEBUG] get_compounds() error: {e}")
            return []

    def accept(self):
        for name in self.selected_names_list:
            stored_name = name + '(chemsep)'
            if stored_name not in compound_selected:
                compound_selected.append(stored_name)
        super().accept()

    def cancel(self):
        compound_selected.clear()
        self.tableWidget.setRowCount(0)
        self.reject()

    def is_compound_selected(self):
        return bool(compound_selected)
