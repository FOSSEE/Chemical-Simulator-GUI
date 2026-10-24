import os
import sys
import unittest
from unittest.mock import MagicMock

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QDialog
app = QApplication.instance() or QApplication([])

from python.utils.ComponentSelectorWindow import ComponentSelectorWindow


class TestComponentSelectorWindow(unittest.TestCase):
    """Unit tests for ComponentSelectorWindow dialog setup, button connections, and actions."""

    def setUp(self):
        self.dialog = ComponentSelectorWindow()

    def tearDown(self):
        self.dialog.close()
        self.dialog.deleteLater()
        app.processEvents()

    def test_initialization(self):
        """Verify window flags and UI elements initialization."""
        self.assertIsNotNone(self.dialog.ui)
        self.assertTrue(hasattr(self.dialog.ui, 'pushButton'))
        self.assertTrue(hasattr(self.dialog.ui, 'pushButton_2'))

    def test_add_button_triggers_add_and_accept(self):
        """Verify clicking Add button executes Add() and accepts the dialog."""
        accepted = []
        self.dialog.accepted.connect(lambda: accepted.append(True))

        self.dialog.ui.pushButton.click()
        app.processEvents()

        self.assertEqual(self.dialog.result(), QDialog.Accepted)
        self.assertTrue(accepted)

    def test_cancel_button_rejects_dialog(self):
        """Verify clicking Cancel button rejects the dialog."""
        rejected = []
        self.dialog.rejected.connect(lambda: rejected.append(True))

        self.dialog.ui.pushButton_2.click()
        app.processEvents()

        self.assertEqual(self.dialog.result(), QDialog.Rejected)
        self.assertTrue(rejected)


if __name__ == '__main__':
    unittest.main()
