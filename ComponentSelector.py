from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from Simulator.Databases.Databases import ChemsepDatabase
ui_dialog,_ = loadUiType('ComponentSelector.ui')


#df = pd.read_csv("compoundsDatabase.csv")

compound_selected = [] #list storing components that are selected inintialised as empty

class ComponentSelector(QDialog,ui_dialog):
    def __init__(self,parent=None):       
        QDialog.__init__(self,parent)

        self.setupUi(self)
    
        self.dict1=dict()#empty dictionary which will store the obj and its compound
        #self.DB1=#instance of Database class in Database.py module 
        self.instance=[ChemsepDatabase()]  #list of all the instances
        self.lines=[]
        
        for i in self.instance:
            x=i.get_comp_name_list()
            self.dict1[i]=x
            self.lines+=x
        print(self.lines)
            
            
        #self.DB1_list=self.DB1.get_comp_name_list()
		#storingchemsep
        #database compound list in DB1_list
        #self.dict1[self.DB1]=self.DB1_list #storing the list as a value and the db as key in dictionary
        #self.lines=self.DB1_list #combined list of all the edited compounds        
       
        self.model = QStringListModel()
        self.model.setStringList(self.lines)
        
        self.completer = QCompleter()
        self.completer.setCaseSensitivity(Qt.CaseInsensitive)
        self.completer.setModel(self.model)

        #QCompleter completes the text written in lineedit    
        self.lineEdit.setCompleter(self.completer)  
		
        self.compoundSelectButton.clicked.connect(self.compound_selection)
        self.compoundSelectButton.setAutoDefault(False)
        self.pushButton.clicked.connect(self.accept)
        self.pushButton_2.clicked.connect(self.cancel)
        self.pushButton_3.clicked.connect(self.remove_items)
        
    def final_list(self,*list_name):
        self.list_final=[]
        #add multiple lists
        for i in list_name:
            self.list_final+=i
        return (self.list_final)

    def is_compound_selected(self):
        if not compound_selected:
            return False
        else:
            return True        
  
  #attrib:
    #CAS fro CAS Number
    #CompoundID for Name
    #Smiles for Molecular Formula
    #MolecularWeight for Molecular Weight

#the below function will match the entered compound and get the database obj 
        #of the corresponding database
        
    def get_object(self,component):
        for ele in self.dict1:
            values=self.dict1[ele]
            for ind in values:
                if ind ==component:
                    return(ele)
                
                
#the below finction removes the before added extra string from the cmpounds 
    def get_original_name(self,component,removing_attrib):
        self.temp_comp= component.replace(removing_attrib,'')
        return(self.temp_comp)
    
    def compound_selection(self):
        self.comp = self.lineEdit.text()      #gets entered text
        if self.comp in self.lines: #matches with the db
            self.obj=self.get_object(self.comp)   #obj will store the key of the dictionary
            #and thus store the instance of the class to which  the component belongs
            self.removing_attrib='(' + self.obj.name + ')' #getting the attribute that is to be removed
            self.comp=self.get_original_name(self.comp,self.removing_attrib)
            #getting only air, water etc from air chemsep etc
            compound_selected.append(self.comp)    #appending that in the list
            
            self.prop_list=self.obj.get_comp_prop(self.comp) #getting prop of the comp
            #obj is the required class  object
           # self.creating_mo_file()
            self.final_mo()
            
            self.lineEdit.clear()
            print(compound_selected)
            
            self.CAS=self.obj.get_value(self.comp,'CAS')
            self.name=self.comp
            self.molecular_formula=self.obj.get_value(self.comp,'Smiles')
            self.molecular_weight=self.obj.get_value(self.comp,'MolecularWeight')
            
            dict={'CAS':self.CAS,'Name':self.name,'Molecular Formula':self.molecular_formula,'Molecular Weight':self.molecular_weight}
            #converted everything to a dictionary which will be passes to addtable 
            #function as a parameter.
            print(dict)
            self.add_to_table(dict)
        else:
            self.show_error()

    @staticmethod
    def set_compounds(compounds):
        #compound_selected = compounds
        for i in compounds:
            compound_selected.append(i)

    def add_to_table(self,a):
        try:
            row_position = self.tableWidget.rowCount()
            self.tableWidget.insertRow(row_position)
            self.tableWidget.setItem(row_position , 0, QTableWidgetItem(str(a['CAS'])))
            self.tableWidget.setItem(row_position , 1, QTableWidgetItem(str(a['Name'])))
            self.tableWidget.setItem(row_position , 2, QTableWidgetItem(str(a['Molecular Formula'])))
            self.tableWidget.setItem(row_position , 3, QTableWidgetItem(str(a['Molecular Weight'])))
        except Exception as e:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
            print(exc_type, fname, exc_tb.tb_lineno)

    def add_compounds_to_list(self,comp):       # which list?
        self.item = QListWidgetItem()
        self.item.setText(comp)
        self.listWidget.addItem(self.item)

    def remove_items(self):
        try:
            item = self.tableWidget.item(self.tableWidget.currentRow(),1).text()
            self.tableWidget.removeRow(self.tableWidget.currentRow())
            
            compound_selected.remove(item)    
        except Exception as e:
            print(e)

    def show_error(self):
        QMessageBox.about(self, 'Important', "Selected Compound is not Available")
    
    def cancel(self):
        compound_selected.clear()
        self.tableWidget.setRowCount(0)
        self.reject()
    
    def get_compounds(self):
        return compound_selected
     
    def final_mo(self):
        self.f_mo=open('Simulator/database.mo','w+')
        self.f_mo.write('package database\n')
        for line in self.prop_list:
            self.f_mo.write(line)
        self.f_mo.write('\n')   
        self.f_mo.write('\nend database;')
        self.f_mo.close()
        