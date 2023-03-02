import os, sys

from PyQt5.uic import loadUiType
from PyQt5.QtWidgets import QWidget

ui_dialog,_ = loadUiType('DockWidgets/DistillationColumnStagewiseResults.ui')


class DistillationColumnStagewiseResults(QWidget,ui_dialog):

    def __init__(self, parent=None):
        QWidget.__init__(self, parent)
        self.setupUi(self)
        # self.setWindowTitle(self.parent.obj.name)
