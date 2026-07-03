# file: python/utils/ComponentSelectorWindow.py
import sys, os
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "../../ui/utils")))

from ComponentSelector import Ui_Dialog

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QDialog

class ComponentSelectorWindow(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowFlags(self.windowFlags() & ~Qt.WindowContextHelpButtonHint)
        self.ui = Ui_Dialog()
        self.ui.setupUi(self)

        # yaha signals connect kar sakte ho
        self.ui.pushButton.clicked.connect(self.Add)   # Add button
        self.ui.pushButton_2.clicked.connect(self.reject) # Cancel button

    def Add(self):
        # yaha pe logic dalna hai jaise selected compounds return karna
        print("Compounds Added!")
        self.accept()
