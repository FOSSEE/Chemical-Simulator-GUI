# -*- coding: utf-8 -*-
"""
Created on Wed Dec 25 17:41:56 2019

@author: Eshika Mahajan
"""

'''

after one simulation all the instances get recreated and the program runs afresh. 
Thus new database.mo wil not have the gen prop of the previous iteration's compounds'
same goes with lists and all ot

'''
'''
FUNCTION(COMPOUNDSELECTION)
any compound selected , compound selection function will first check whether the text
written in lineEdit is a part of database or not by checking the text entered with 
LINES that contain the list of all the compiundsin the database.
if it is a part of database then it will proceed further else it will show error

'''
'''
FINCTION(CREATIN_MO_FILE)
the below codes fetch the general properties of the compiund selected from
Database.py in the form of lists.
first creates the combined list 'comp_prop_list' of gen prop of all the compounds
then appended with one starting line 'package database' and end with 'end database'
and the extension will be changed to .mo file.
    
'''

from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.uic import loadUiType
import pandas as pd
from Simulator.Databases.Databases import ChemsepDatabase
ui_dialog,_ = loadUiType('comp_selector.ui')


#df = pd.read_csv("compoundsDatabase.csv")

compound_selected = [] #list storing components that are selected inintialised as empty

class componentSelector(QDialog,ui_dialog):
    def __init__(self,parent=None):
        #super(componentSelector,self).__init__(parent)
       
        QDialog.__init__(self,parent)

        self.setupUi(self)
    
        self.Dict1=dict()#empty dictionary which will store the obj and its compound
        #self.DB1=#instance of Database class in Database.py module 
        self.instance=[ChemsepDatabase()]  #list of all the instances
        self.lines=[]
        
        for i in self.instance:
            x=i.get_comp_name_list()
            self.Dict1[i]=x
            self.lines+=x
        print(self.lines)
            
            
        #self.DB1_list=self.DB1.get_comp_name_list()
		#storingchemsep
        #database compound list in DB1_list
        #self.Dict1[self.DB1]=self.DB1_list #storing the list as a value and the db as key in dictionary
        #self.lines=self.DB1_list #combined list of all the edited compounds        
       
        self.model = QStringListModel()
        self.model.setStringList(self.lines)
        
        self.completer = QCompleter()
        self.completer.setCaseSensitivity(Qt.CaseInsensitive)
        self.completer.setModel(self.model)
        #QCompleter completes the text written in lineedit    
        self.lineEdit.setCompleter(self.completer)  
		
        self.compoundSelectButton.clicked.connect(self.compoundSelection)
        self.compoundSelectButton.setAutoDefault(False)
        self.pushButton.clicked.connect(self.accept)
        self.pushButton_2.clicked.connect(self.cancel)
        self.pushButton_3.clicked.connect(self.removeItems)
        
        
    def final_list(self,*list_name):
        self.list_final=[]
        #add multiple lists
        for i in list_name:
            self.list_final+=i
        return (self.list_final)

    def isCompSelected(self):
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
        for ele in self.Dict1:
            values=self.Dict1[ele]
            for ind in values:
                if ind ==component:
                    return(ele)
                
                
#the below finction removes the before added extra string from the cmpounds 
    def get_original_name(self,component,removing_attrib):
        self.temp_comp= component.replace(removing_attrib,'')
        return(self.temp_comp)
    
    
    
    def compoundSelection(self):
        
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
            self.Name=self.comp
            self.MolecularFormula=self.obj.get_value(self.comp,'Smiles')
            self.MolecularWeight=self.obj.get_value(self.comp,'MolecularWeight')
            
            Dict={'CAS':self.CAS,'Name':self.Name,'Molecular Formula':self.MolecularFormula,'Molecular Weight':self.MolecularWeight}
            #converted everything to a dictionary which will be passes to addtable 
            #function as a parameter.
            print(Dict)
            self.addToTable(Dict)
        else:
            self.Show_Error()

    @staticmethod
    def setCompounds(compounds):
        #compound_selected = compounds
        for i in compounds:
            compound_selected.append(i)

    def addToTable(self,a):
        try:
            rowPosition = self.tableWidget.rowCount()
            self.tableWidget.insertRow(rowPosition)
            self.tableWidget.setItem(rowPosition , 0, QTableWidgetItem(str(a['CAS'])))
            self.tableWidget.setItem(rowPosition , 1, QTableWidgetItem(str(a['Name'])))
            self.tableWidget.setItem(rowPosition , 2, QTableWidgetItem(str(a['Molecular Formula'])))
            self.tableWidget.setItem(rowPosition , 3, QTableWidgetItem(str(a['Molecular Weight'])))
        except Exception as e:
            exc_type, exc_obj, exc_tb = sys.exc_info()
            fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
            print(exc_type, fname, exc_tb.tb_lineno)

    def addCompToList(self,comp):       # which list?
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
    
    def getComp(self):
        return compound_selected
     
    def final_mo(self):
        self.f_mo=open('Simulator/database.mo','w+')
        self.f_mo.write('package database\n')
        for line in self.prop_list:
            self.f_mo.write(line)
        self.f_mo.write('\n')   
        self.f_mo.write('\nend database;')
        self.f_mo.close()
        
 


    
    


