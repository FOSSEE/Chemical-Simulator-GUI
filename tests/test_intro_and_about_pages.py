import os
import sys
import unittest
from unittest.mock import MagicMock, patch

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QPushButton, QMessageBox

app = QApplication.instance() or QApplication([])

from Intro_page import IntroPage
from About_page import AboutPage


class TestIntroAndAboutPages(unittest.TestCase):
    """Unit tests for IntroPage and AboutPage UI interaction and navigation."""

    def test_intro_page_initialization_and_callbacks(self):
        """Verify IntroPage elements, next_callback and cancel_callback."""
        mock_next = MagicMock()
        mock_cancel = MagicMock()

        intro = IntroPage(mock_next, mock_cancel)
        self.assertEqual(intro.windowTitle(), "Simulation Configuration Wizard")

        # Find buttons
        btn_next = intro.findChild(QPushButton, "next")
        btn_cancel = intro.findChild(QPushButton, "cancel")
        self.assertIsNotNone(btn_next)
        self.assertIsNotNone(btn_cancel)

        # Trigger Next
        btn_next.click()
        mock_next.assert_called_once()

        # Trigger Cancel
        btn_cancel.click()
        mock_cancel.assert_called_once()

    @patch('Intro_page.QMessageBox.information')
    def test_intro_page_close_wizard_button(self, mock_info):
        """Verify the close wizard informational button."""
        intro = IntroPage(lambda: None, lambda: None)
        btn_close = intro.findChild(QPushButton, "closeWizard")
        self.assertIsNotNone(btn_close)

        btn_close.click()
        mock_info.assert_called_once()

    def test_about_page_initialization_and_close_callback(self):
        """Verify AboutPage builds UI and triggers close callback."""
        mock_close = MagicMock()
        about = AboutPage(on_close=mock_close)

        # Find the close button (top bar '✕')
        buttons = about.findChildren(QPushButton)
        close_btn = next((b for b in buttons if b.text() == "✕"), None)
        self.assertIsNotNone(close_btn)

        close_btn.click()
        mock_close.assert_called_once()

    @patch('webbrowser.open')
    def test_about_page_external_links(self, mock_web_open):
        """Verify external repository and organization link buttons."""
        about = AboutPage()
        buttons = about.findChildren(QPushButton)

        # GitHub and FOSSEE buttons
        github_btn = next((b for b in buttons if "GitHub" in b.text()), None)
        fossee_btn = next((b for b in buttons if "FOSSEE" in b.text()), None)

        self.assertIsNotNone(github_btn)
        self.assertIsNotNone(fossee_btn)

        github_btn.click()
        mock_web_open.assert_called_with("https://github.com/FOSSEE/Chemical-Simulator-GUI")

        fossee_btn.click()
        mock_web_open.assert_called_with("https://fossee.in/")


if __name__ == "__main__":
    unittest.main()
