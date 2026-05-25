import platform
if platform.system() == "Windows": import pyuac

import sys
import pyuac
import math

from mainApp import MainApp
from About_page import AboutPage
from Intro_page import IntroPage


from PyQt5.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QPushButton,
    QFileDialog, QMessageBox, QGraphicsDropShadowEffect
)
from PyQt5.QtGui import QPainter, QPen, QPainterPath
from PyQt5.QtWidgets import QGraphicsView
from PyQt5.QtGui import QFont, QPalette, QColor, QLinearGradient, QBrush
from PyQt5.QtCore import Qt, QTimer, QPropertyAnimation, QEasingCurve, QPointF, QRectF
import sys, os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', '..')))
from src.main.ui.utils.LandingPageUI import IconPanel, GlassButton

class LandingPage(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Chemical Simulator GUI")
        
        # Window type instead of full screen (comment down if u want full screen)
        self.resize(1280, 800)
        qr = self.frameGeometry()
        cp = QApplication.desktop().availableGeometry().center()
        qr.moveCenter(cp)
        self.move(qr.topLeft())

        # Save original window flags & geometry to restore later
        self._orig_window_flags = self.windowFlags()
        self._orig_geometry = self.geometry()

        self.main_window = None
        self.init_ui()

        # 🔥 Start background preload once the window is ready
        QTimer.singleShot(500, self.preload_main_window)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing, True)

        # bg colour 
        gradient = QLinearGradient(0, 0, self.width(), self.height())
        gradient.setColorAt(0.0, QColor("#0f172a"))  # Slate 900
        gradient.setColorAt(1.0, QColor("#1e293b"))  # Slate 800
        painter.fillRect(self.rect(), QBrush(gradient))

        # grid design
        grid_pen = QPen(QColor(255, 255, 255, 10), 1, Qt.DashLine)
        painter.setPen(grid_pen)
        grid_size = 100
        for x in range(0, self.width(), grid_size):
            painter.drawLine(x, 0, x, self.height())
        for y in range(0, self.height(), grid_size):
            painter.drawLine(0, y, self.width(), y)

    def init_ui(self):
        #         # 🌈 Gradient Background
        # palette = QPalette()
        # gradient = QLinearGradient(0, 0, 0, self.height())
        # gradient.setColorAt(0.0, QColor("#1e3c72"))   # Deep blue
        # gradient.setColorAt(1.0, QColor("#2a5298"))   # Light blue
        # palette.setBrush(QPalette.Window, QBrush(gradient))
        # self.setAutoFillBackground(True)
        # self.setPalette(palette)


        # 🌟 Main Layout
        main_layout = QVBoxLayout()
        main_layout.setAlignment(Qt.AlignCenter)
        # added margins and spacing
        main_layout.setContentsMargins(50, 80, 50, 80)
        main_layout.setSpacing(20)
        self.setLayout(main_layout)

        # ✨ Title
        title = QLabel("Chemical Simulator GUI")
        title.setFont(QFont("Segoe UI", 54, QFont.Bold))
        title.setAlignment(Qt.AlignCenter)
        title.setStyleSheet("color: white; letter-spacing: 2px; background: transparent;")
        title_shadow = QGraphicsDropShadowEffect()
        title_shadow.setBlurRadius(15)
        title_shadow.setOffset(0, 4)
        title_shadow.setColor(QColor(0, 0, 0, 180))
        title.setGraphicsEffect(title_shadow)
        main_layout.addWidget(title)

        # 🌤 Subtitle
        subtitle = QLabel("Empowering learning and research in chemical processes")
        subtitle.setFont(QFont("Segoe UI Light", 22))
        subtitle.setAlignment(Qt.AlignCenter)
        subtitle.setStyleSheet("color: #cbd5e1; background: transparent; margin-bottom: 30px;")
        main_layout.addWidget(subtitle)

        # 🚀 Glassmorphic Buttons
        button_names = [
            ("Start New Simulation", "flask", self.start_simulation),
            ("Open Existing Project", "folder", self.open_existing_project),
            ("About", "info", self.show_about),
            ("Exit", "exit", self.close)
        ]

        for text, icon_type, action in button_names:
            btn = GlassButton(text, icon_type, self)
            main_layout.addWidget(btn, alignment=Qt.AlignHCenter)
            btn.clicked.connect(action)

        # 🌿 Footer
        footer = QLabel("Open-source process simulator for education & research")
        footer.setFont(QFont("Segoe UI", 12))
        footer.setAlignment(Qt.AlignCenter)
        footer.setStyleSheet("color: #64748b; background: transparent; margin-top: 40px;")
        main_layout.addWidget(footer)

        # 🌸 Fade-in Animation
        self.fade_in_animation()

    def fade_in_animation(self):
        self.setWindowOpacity(0)
        self.anim = QPropertyAnimation(self, b"windowOpacity")
        self.anim.setDuration(1500)
        self.anim.setStartValue(0)
        self.anim.setEndValue(1)
        self.anim.setEasingCurve(QEasingCurve.InOutQuad)
        self.anim.start()

    def preload_main_window(self):
        QApplication.setOverrideCursor(Qt.WaitCursor)
        try:
            self.main_window = MainApp()
            self.main_window.hide()

            # 💡 Preload compound selector (but don’t show it yet)
            if hasattr(self.main_window, 'comp'):
                self.main_window.comp.hide()
                print("[INFO] Compound window preloaded in background.")

            print("[INFO] MainApp preloaded in background.")
        except Exception as e:
            print("[ERROR] Failed to preload MainApp or Compound window:", e)
        finally:
            QApplication.restoreOverrideCursor()


    def start_simulation(self):
        QApplication.setOverrideCursor(Qt.WaitCursor)
        QTimer.singleShot(100, lambda: (self.launch_main_window(), self.reset_cursor()))


    def _cleanup_main_window(self):
        """Safely schedule the old main window for deletion."""
        if self.main_window is not None:
            try:
                self.main_window.hide()
                self.main_window.deleteLater()
            except Exception:
                pass
            self.main_window = None

    def open_existing_project(self):
        file_path, _ = QFileDialog.getOpenFileName(
            self,
            "Open Existing Project",
            "",
            "Project Files (*.sim);;All Files (*)"
        )

        if not file_path:
            print("[DEBUG] No file selected.")
            return

        QApplication.setOverrideCursor(Qt.WaitCursor)
        try:
            print(f"[DEBUG] Opening existing project from Landing Page: {file_path}")
            self._cleanup_main_window()
            self.main_window = MainApp()

            # Preserve original closeEvent
            orig_close = getattr(self.main_window, "closeEvent", None)
            def _wrapped_close(event):
                try:
                    if orig_close is not None:
                        orig_close(event)
                except Exception:
                    pass
                if event.isAccepted():
                    # Defer restoration so closeEvent finishes before we touch self.main_window
                    QTimer.singleShot(0, self.restore_landing_page)
            self.main_window.closeEvent = _wrapped_close

            # Open project file
            self.main_window.open(file_path)

            # --- Canvas Fit / Zoom (same logic as mainApp.open) ---
            def delayed_fit():
                try:
                    rect = self.main_window.container.graphics.scene.itemsBoundingRect()
                    if not rect.isNull():
                        gv = self.main_window.graphicsView
                        gv.setRenderHints(QPainter.Antialiasing | QPainter.SmoothPixmapTransform)
                        gv.setDragMode(QGraphicsView.ScrollHandDrag)
                        gv.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
                        gv.fitInView(rect, Qt.KeepAspectRatio)
                        gv.centerOn(rect.center())
                        print("[DEBUG] Canvas fitted properly from Landing Page.")
                except Exception as e:
                    print(f"[DEBUG] delayed_fit error: {e}")

            QTimer.singleShot(600, delayed_fit)  # Wait for layout stabilization

            # Ensure main window is maximized and active
            self.main_window.showMaximized()
            self.main_window.activateWindow()
            self.main_window.raise_()

            # Hide landing page
            self.hide()

            print("[DEBUG] Existing project opened successfully.")

        except Exception as e:
            print(f"[DEBUG] Error in open_existing_project: {e}")
            QMessageBox.critical(self, "Error", f"Failed to open project:\n{str(e)}")

        finally:
            self.reset_cursor()

    def launch_main_window(self):
        QApplication.setOverrideCursor(Qt.WaitCursor)
        try:
            self._cleanup_main_window()
            self.main_window = MainApp()
            self.main_window.new_project()  # reset all components for new project

            # Wrap closeEvent to restore landing page
            orig_close = getattr(self.main_window, "closeEvent", None)
            def _wrapped_close(event):
                if orig_close:
                    try:
                        orig_close(event)
                    except Exception:
                        pass
                if event.isAccepted():
                    # Defer restoration so closeEvent finishes before we touch self.main_window
                    QTimer.singleShot(0, self.restore_landing_page)
            self.main_window.closeEvent = _wrapped_close

            # Show main window maximized
            self.main_window.showMaximized()
            self.main_window.activateWindow()
            self.main_window.raise_()

            # Hide landing page
            self.hide()

            # Ensure compound selector is visible
            QTimer.singleShot(100, lambda: self.show_compound_selector())

        finally:
            self.reset_cursor()


    def show_compound_selector(self):
        if not (self.main_window and hasattr(self.main_window, 'comp')):
            return

        comp_window = self.main_window.comp
        comp_window.show()
        comp_window.raise_()
        comp_window.activateWindow()

        # === Show Intro Page overlay (same size and position) ===
        self.intro_page = IntroPage(self.launch_compound_selector, self.cancel_intro)
        self.intro_page.resize(comp_window.size())
        self.intro_page.move(comp_window.pos())
        self.intro_page.setWindowFlag(Qt.WindowStaysOnTopHint)
        self.intro_page.setWindowModality(Qt.ApplicationModal)
        self.intro_page.show()
        self.intro_page.raise_()

    def launch_compound_selector(self):
        """When user clicks Next on IntroPage"""
        if hasattr(self, 'intro_page'):
            self.intro_page.close()

        if self.main_window and hasattr(self.main_window, 'comp'):
            comp_window = self.main_window.comp
            comp_window.show()
            comp_window.raise_()
            comp_window.activateWindow()

    def cancel_intro(self):
        """When user clicks Cancel on IntroPage"""
        if hasattr(self, 'intro_page'):
            self.intro_page.close()
        if self.main_window:
            self.main_window.close()
        else:
            self.restore_landing_page()


    def handle_main_close(self, event):
        """Triggered when MainApp window is closed."""
        event.accept()  # Close main window normally
        # Deferred — restore_landing_page will be called by the QTimer in closeEvent wrapper

    def fit_canvas(self):
        """Properly fit the canvas after MainApp is ready."""
        if self.main_window is None:
            return
        gv = self.main_window.graphicsView
        gv.setDragMode(QGraphicsView.ScrollHandDrag)
        gv.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        gv.fitInView(self.main_window.scene.itemsBoundingRect(), Qt.KeepAspectRatio)
        gv.centerOn(self.main_window.scene.itemsBoundingRect().center())
        self.reset_cursor()

    def restore_landing_page(self):
        # Safely clean up old main window using Qt event loop
        self._cleanup_main_window()

        # Show landing page in full screen
        # self.showFullScreen()  

        # Show landing page (windowed)
        self.show()

        # Make sure it is active
        self.activateWindow()
        self.raise_()
        # QApplication.processEvents()

    def resizeEvent(self, event):
        # """Make sure gradient background fills screen on resize."""
        # palette = QPalette()
        # gradient = QLinearGradient(0, 0, 0, self.height())
        # gradient.setColorAt(0.0, QColor("#1e3c72"))
        # gradient.setColorAt(1.0, QColor("#2a5298"))
        # palette.setBrush(QPalette.Window, QBrush(gradient))
        # self.setPalette(palette)
        super().resizeEvent(event)

    def show_about(self):
        self.about_window = QWidget()
        self.about_window.setWindowTitle("About Chemical Simulator GUI")
        self.about_window.setStyleSheet("background-color: #ffffff;")
        self.about_window.showMaximized()

        layout = QVBoxLayout()
        layout.setAlignment(Qt.AlignCenter)
        self.about_window.setLayout(layout)

        about_widget = AboutPage()
        layout.addWidget(about_widget)

        close_btn = QPushButton("Close")
        close_btn.setFixedHeight(50)
        close_btn.setFont(QFont("Segoe UI", 16))
        close_btn.setStyleSheet("""
            QPushButton {
                color: white;
                background-color: #1e3c72;
                border-radius: 10px;
                padding: 10px 20px;
            }
            QPushButton:hover {
                background-color: #2a5298;
            }
        """)
        close_btn.clicked.connect(self.about_window.close)
        layout.addWidget(close_btn, alignment=Qt.AlignCenter)

        self.about_window.show()

    def reset_cursor(self):
        print("[DEBUG] reset_cursor called, overrideCursor:", QApplication.overrideCursor())
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()
        print("[DEBUG] cursor restored, overrideCursor now:", QApplication.overrideCursor())



def run():
    app = QApplication(sys.argv)
    window = LandingPage()
    window.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    if platform.system() == "Windows":
        if not pyuac.isUserAdmin():
            pyuac.runAsAdmin()
        else:
            run()
    else:
        run()