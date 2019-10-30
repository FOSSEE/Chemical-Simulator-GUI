from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
ui_dialog,_ = loadUiType('comp_selector.ui')


df = pd.read_csv("compoundsDatabase.csv")
compound_selected = []
class componentSelector(QDialog,ui_dialog):
    def __init__(self,parent=None):
        #super(componentSelector,self).__init__(parent)
        QDialog.__init__(self,parent)
        self.setupUi(self)
        
        self.lines = [line.rstrip('\n') for line in open('compounds.txt')]
        model = QStringListModel()
        model.setStringList(self.lines)

        completer = QCompleter()
        completer.setCaseSensitivity(Qt.CaseInsensitive)
        completer.setModel(model)
    
        self.lineEdit.setCompleter(completer)
        
        self.compoundSelectButton.clicked.connect(self.compoundSelection)
        self.compoundSelectButton.setAutoDefault(False)
        self.pushButton.clicked.connect(self.accept)
        self.pushButton_2.clicked.connect(self.cancel)
        self.pushButton_3.clicked.connect(self.removeItems)

    def isCompSelected(self):
        if not compound_selected:
            return False
        else:
            return True
            
    def compoundSelection(self):
        comp = self.lineEdit.text()
        if comp in self.lines:

            compound_selected.append(comp)
            self.lineEdit.clear()
            print(compound_selected)
            #self.addCompToList(comp)
            a = df.loc[df['Name'] == comp]
            print(a)
            self.addToTable(a)
            #print(compound_selected)
            '''
            except Exception as e:
                exc_type, exc_obj, exc_tb = sys.exc_info()
                fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
                print(exc_type, fname, exc_tb.tb_lineno)
            '''
        else:
            self.Show_Error()

    def addToTable(self,a):
        try:
            rowPosition = self.tableWidget.rowCount()
            self.tableWidget.insertRow(rowPosition)
            self.tableWidget.setItem(rowPosition , 0, QTableWidgetItem(str(a.iloc[0][0])))
            self.tableWidget.setItem(rowPosition , 1, QTableWidgetItem(str(a.iloc[0][1])))
            self.tableWidget.setItem(rowPosition , 2, QTableWidgetItem(str(a.iloc[0][2])))
            self.tableWidget.setItem(rowPosition , 3, QTableWidgetItem(str(a.iloc[0][3])))
        except Exception as e:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
            print(exc_type, fname, exc_tb.tb_lineno)

    def addCompToList(self,comp):
        self.item = QListWidgetItem()
        self.item.setText(comp)
        self.listWidget.addItem(self.item)

    def removeItems(self):
        item = self.tableWidget.item(self.tableWidget.currentRow(),1).text()
        self.tableWidget.removeRow(self.tableWidget.currentRow())
        
        compound_selected.remove(item)	
    def Show_Error(self):
        QMessageBox.about(self, 'Important', "Selected Compound is not Available")
    def cancel(self):
        compound_selected.clear()
        self.tableWidget.setRowCount(0)
        self.reject()




