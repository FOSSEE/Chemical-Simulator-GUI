from PyQt5.QtWidgets import QWidget, QPushButton, QHBoxLayout, QLabel
from PyQt5.QtGui import QPainter, QPen, QPainterPath, QColor, QFont
from PyQt5.QtCore import Qt, QPointF, QRectF


# added a windows type border in the code, remove the code to revert back to the old border
# include app name, minimize button, and close button in the title bar
class IconPanel(QWidget):
    def __init__(self, icon_type, parent=None):
        super().__init__(parent)
        self.icon_type = icon_type
        self.setAttribute(Qt.WA_TransparentForMouseEvents, True)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing, True)

        cx, cy = self.width() / 2, self.height() / 2

        # Determine opacity and thickness based on parent hover/press state
        parent_btn = self.parent()
        if parent_btn and hasattr(parent_btn, "underMouse") and parent_btn.underMouse():
            color = QColor(255, 255, 255, 255)
            thickness = 2.8
            liq_color = QColor(255, 255, 255, 160)
            cross_color = QColor(255, 255, 255, 255)
        elif parent_btn and hasattr(parent_btn, "isDown") and parent_btn.isDown():
            color = QColor(255, 255, 255, 180)
            thickness = 2.5
            liq_color = QColor(255, 255, 255, 100)
            cross_color = QColor(255, 255, 255, 180)
        else:
            color = QColor(255, 255, 255, 210)
            thickness = 2.5
            liq_color = QColor(255, 255, 255, 120)
            cross_color = QColor(255, 255, 255, 210)

        # Draw the icon
        pen = QPen(color, thickness)
        pen.setCapStyle(Qt.RoundCap)
        pen.setJoinStyle(Qt.RoundJoin)
        painter.setPen(pen)
        painter.setBrush(Qt.NoBrush)

        if self.icon_type == "flask":
            # Erlenmeyer flask (left)
            path = QPainterPath()
            path.moveTo(cx - 16, cy - 12)
            path.lineTo(cx - 8, cy - 12)
            path.moveTo(cx - 12, cy - 12)
            path.lineTo(cx - 12, cy - 4)
            path.lineTo(cx - 20, cy + 10)
            path.lineTo(cx - 4, cy + 10)
            path.lineTo(cx - 12, cy - 4)
            path.lineTo(cx - 12, cy - 12)
            painter.drawPath(path)

            # Draw liquid lines
            liq_pen = QPen(liq_color, 1.5)
            painter.setPen(liq_pen)
            painter.drawLine(int(cx - 18), int(cy + 4), int(cx - 6), int(cy + 4))
            painter.drawLine(int(cx - 19), int(cy + 7), int(cx - 5), int(cy + 7))

            # Slanted Test tube (right)
            painter.setPen(pen)
            painter.save()
            painter.translate(cx + 8, cy - 2)
            painter.rotate(15)
            tube = QPainterPath()
            tube.moveTo(-4, -10)
            tube.lineTo(4, -10)
            tube.moveTo(-3, -10)
            tube.lineTo(-3, 8)
            tube.arcTo(-3, 5, 6, 6, 180, 180)
            tube.lineTo(3, -10)
            painter.drawPath(tube)
            
            # Liquid inside test tube
            painter.setPen(liq_pen)
            painter.drawLine(-2, 2, 2, 2)
            painter.restore()

        elif self.icon_type == "folder":
            # File folder outline
            path = QPainterPath()
            path.moveTo(cx - 16, cy + 10)
            path.lineTo(cx + 16, cy + 10)
            path.lineTo(cx + 16, cy - 5)
            path.lineTo(cx + 2, cy - 5)
            path.lineTo(cx - 1, cy - 10)
            path.lineTo(cx - 16, cy - 10)
            path.closeSubpath()
            painter.drawPath(path)

            # Inner paper sheet details
            sheet_pen = QPen(liq_color, 1.5)
            painter.setPen(sheet_pen)
            painter.drawLine(int(cx - 10), int(cy - 3), int(cx + 10), int(cy - 3))
            painter.drawLine(int(cx - 10), int(cy + 2), int(cx + 5), int(cy + 2))

        elif self.icon_type == "info":
            # Outer circle
            painter.drawEllipse(QPointF(cx, cy), 14, 14)
            # Dot of the 'i'
            painter.setBrush(color)
            painter.drawEllipse(QPointF(cx, cy - 6.5), 1.5, 1.5)
            # Stem of 'i'
            painter.setBrush(Qt.NoBrush)
            painter.drawLine(QPointF(cx, cy - 3), QPointF(cx, cy + 6))
            painter.drawLine(QPointF(cx - 2.5, cy + 6), QPointF(cx + 2.5, cy + 6))

        elif self.icon_type == "exit":
            # Power icon
            px, py = cx - 2, cy - 2
            rect = QRectF(px - 11, py - 11, 22, 22)
            painter.drawArc(rect, 125 * 16, 290 * 16)
            painter.drawLine(QPointF(px, py - 11), QPointF(px, py))
            
            # Cross icon at the bottom right
            cx_x, cx_y = cx + 8, cy + 8
            cross_pen = QPen(cross_color, 2.0)
            painter.setPen(cross_pen)
            painter.drawLine(int(cx_x - 4), int(cx_y - 4), int(cx_x + 4), int(cx_y + 4))
            painter.drawLine(int(cx_x + 4), int(cx_y - 4), int(cx_x - 4), int(cx_y + 4))
        painter.end()

# btn styling 
class GlassButton(QPushButton):
    def __init__(self, text, icon_type, parent=None):
        super().__init__(parent)
        self.setFixedHeight(75)
        self.setFixedWidth(500)
        self.setCursor(Qt.PointingHandCursor)

        self.setStyleSheet("""
            QPushButton {
                background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, 
                    stop:0 rgba(255, 255, 255, 0.12), 
                    stop:1 rgba(255, 255, 255, 0.04));
                border: 2px solid rgba(255, 255, 255, 0.15);
                border-radius: 16px;
            }
            QPushButton:hover {
                background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, 
                    stop:0 rgba(255, 255, 255, 0.20), 
                    stop:1 rgba(255, 255, 255, 0.08));
                border: 2px solid rgba(255, 255, 255, 0.35);
            }
            QPushButton:pressed {
                background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, 
                    stop:0 rgba(255, 255, 255, 0.08), 
                    stop:1 rgba(255, 255, 255, 0.02));
                border: 2px solid rgba(255, 255, 255, 0.25);
            }
            QPushButton QLabel {
                color: rgba(255, 255, 255, 0.85);
            }
            QPushButton:hover QLabel {
                color: rgba(255, 255, 255, 1.0);
            }
            QPushButton:pressed QLabel {
                color: rgba(255, 255, 255, 0.70);
            }
            QPushButton QWidget#btnSeparator {
                background-color: rgba(255, 255, 255, 0.15);
            }
            QPushButton:hover QWidget#btnSeparator {
                background-color: rgba(255, 255, 255, 0.35);
            }
            QPushButton:pressed QWidget#btnSeparator {
                background-color: rgba(255, 255, 255, 0.20);
            }
        """)

        layout = QHBoxLayout(self)
        layout.setContentsMargins(4, 0, 4, 0)
        layout.setSpacing(0)

        # Icon Panel
        self.icon_panel = IconPanel(icon_type, self)
        self.icon_panel.setFixedWidth(56)
        self.icon_panel.setFixedHeight(75)
        layout.addWidget(self.icon_panel)

        # Separator Line
        separator = QWidget(self)
        separator.setObjectName("btnSeparator")
        separator.setFixedWidth(1)
        separator.setFixedHeight(40)
        layout.addWidget(separator, alignment=Qt.AlignVCenter)

        # Breathing room after separator
        layout.addSpacing(12)

        # Text Label
        self.text_label = QLabel(text, self)
        self.text_label.setFont(QFont("Segoe UI Semibold", 15))
        self.text_label.setStyleSheet("background: transparent;")
        self.text_label.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.text_label, 1)

        # Right padding to balance the icon area
        layout.addSpacing(12)

        self.setLayout(layout)

        # Make child widgets transparent for mouse clicks
        self.icon_panel.setAttribute(Qt.WA_TransparentForMouseEvents, True)
        separator.setAttribute(Qt.WA_TransparentForMouseEvents, True)
        self.text_label.setAttribute(Qt.WA_TransparentForMouseEvents, True)

    def enterEvent(self, event):
        super().enterEvent(event)
        self.icon_panel.update()

    def leaveEvent(self, event):
        super().leaveEvent(event)
        self.icon_panel.update()

    def mousePressEvent(self, event):
        super().mousePressEvent(event)
        self.icon_panel.update()

    def mouseReleaseEvent(self, event):
        super().mouseReleaseEvent(event)
        self.icon_panel.update()
