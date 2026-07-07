# About_page.py
# -*- coding: utf-8 -*-

import os
import webbrowser

from PyQt5.QtWidgets import (
    QWidget, QVBoxLayout, QHBoxLayout, QLabel, QPushButton,
    QScrollArea, QFrame, QGraphicsDropShadowEffect
)
from PyQt5.QtGui import (
    QFont, QFontMetrics, QPixmap, QColor, QPainter, QPen, QLinearGradient, QBrush
)
from PyQt5.QtCore import Qt

# --- Design tokens (kept in sync with the Landing page) --------------------
BG_TOP = "#0f172a"          # Slate 900
BG_BOTTOM = "#1e293b"       # Slate 800
ACCENT = "#60a5fa"          # Blue 400
TEXT_PRIMARY = "#e2e8f0"    # Slate 200
TEXT_SECONDARY = "#94a3b8"  # Slate 400
TEXT_MUTED = "#64748b"      # Slate 500

CARD_WIDTH = 800
HPAD = 64
CONTENT_WIDTH = CARD_WIDTH - 2 * HPAD

GITHUB_URL = "https://github.com/FOSSEE/Chemical-Simulator-GUI"
FOSSEE_URL = "https://fossee.in/"

# Resolve resources relative to this file so the logo works on any machine.
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
ICONS_DIR = os.path.normpath(os.path.join(BASE_DIR, "..", "resources", "base", "icons"))


class AboutPage(QWidget):
    def __init__(self, on_close=None):
        super().__init__()
        self._on_close = on_close

        # Root layout fills the whole page; the page paints its own background.
        root = QVBoxLayout(self)
        root.setContentsMargins(0, 0, 0, 0)
        root.setSpacing(0)

        # --- Top bar with a compact close button ---------------------------
        top_bar = QHBoxLayout()
        top_bar.setContentsMargins(0, 18, 24, 0)
        top_bar.addStretch()
        close_btn = QPushButton("✕")
        close_btn.setFixedSize(40, 40)
        close_btn.setCursor(Qt.PointingHandCursor)
        close_btn.setStyleSheet("""
            QPushButton {
                color: #cbd5e1;
                background-color: rgba(255, 255, 255, 0.06);
                border: 1px solid rgba(255, 255, 255, 0.12);
                border-radius: 20px;
                font-size: 16px;
            }
            QPushButton:hover {
                color: #ffffff;
                background-color: rgba(239, 68, 68, 0.85);
                border: 1px solid rgba(239, 68, 68, 0.9);
            }
        """)
        if on_close is not None:
            close_btn.clicked.connect(on_close)
        top_bar.addWidget(close_btn)
        root.addLayout(top_bar)

        # --- Scrollable, centered content ----------------------------------
        scroll = QScrollArea()
        scroll.setWidgetResizable(True)
        scroll.setFrameShape(QFrame.NoFrame)
        scroll.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        scroll.setStyleSheet("""
            QScrollArea { background: transparent; border: none; }
            QScrollBar:vertical {
                background: transparent; width: 8px; margin: 4px 2px 4px 0;
            }
            QScrollBar::handle:vertical {
                background: rgba(255, 255, 255, 0.18);
                border-radius: 4px; min-height: 40px;
            }
            QScrollBar::handle:vertical:hover { background: rgba(255, 255, 255, 0.30); }
            QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0; }
            QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: transparent; }
        """)
        scroll.viewport().setAutoFillBackground(False)
        root.addWidget(scroll, 1)

        wrapper = QWidget()
        wrapper.setStyleSheet("background: transparent;")
        wrap_layout = QVBoxLayout(wrapper)
        wrap_layout.setContentsMargins(40, 8, 40, 40)
        wrap_layout.addStretch()

        # --- Glass content card --------------------------------------------
        card = QWidget()
        card.setObjectName("aboutCard")
        card.setFixedWidth(CARD_WIDTH)
        card.setStyleSheet("""
            QWidget#aboutCard {
                background-color: rgba(255, 255, 255, 0.04);
                border: 1px solid rgba(255, 255, 255, 0.10);
                border-radius: 24px;
            }
        """)
        shadow = QGraphicsDropShadowEffect()
        shadow.setBlurRadius(50)
        shadow.setColor(QColor(0, 0, 0, 160))
        shadow.setOffset(0, 12)
        card.setGraphicsEffect(shadow)

        card_layout = QVBoxLayout(card)
        card_layout.setContentsMargins(HPAD, 46, HPAD, 40)
        card_layout.setSpacing(14)
        card_layout.setAlignment(Qt.AlignTop)

        # -- Hero (centered) ------------------------------------------------
        logo = self._load_logo()
        if logo is not None:
            logo_label = QLabel()
            logo_label.setPixmap(logo)
            logo_label.setAlignment(Qt.AlignCenter)
            logo_label.setStyleSheet("background: transparent;")
            card_layout.addWidget(logo_label)

        title = QLabel("Chemical Simulator GUI")
        title.setFont(self._fit_title_font(title.text(), CONTENT_WIDTH))
        title.setAlignment(Qt.AlignCenter)
        title.setStyleSheet("color: #ffffff; background: transparent;")
        card_layout.addWidget(title)

        subtitle = QLabel("Cross-platform chemical process simulation")
        subtitle.setFont(QFont("Segoe UI Light", 15))
        subtitle.setAlignment(Qt.AlignCenter)
        subtitle.setStyleSheet("color: %s; background: transparent;" % TEXT_SECONDARY)
        card_layout.addWidget(subtitle)

        card_layout.addSpacing(10)
        card_layout.addWidget(self._separator())
        card_layout.addSpacing(6)

        # -- About ----------------------------------------------------------
        card_layout.addWidget(self._section_header("About"))
        desc = QLabel(
            "A graphical environment for creating and simulating chemical process "
            "flowsheets using unit operations and thermodynamic models."
        )
        desc.setFont(QFont("Segoe UI", 13))
        desc.setWordWrap(True)
        desc.setStyleSheet("color: %s; background: transparent;" % TEXT_PRIMARY)
        card_layout.addWidget(desc)

        card_layout.addSpacing(10)

        # -- Key Features ---------------------------------------------------
        card_layout.addWidget(self._section_header("Key Features"))
        features = [
            "Flowsheet creation and editing",
            "Material stream handling and unit operations",
            "OpenModelica integration",
            "Equation-based and sequential modular simulation",
            "Undo, redo, and CSV result generation",
            "Cross-platform support (Windows and Linux)",
        ]
        for feature in features:
            card_layout.addWidget(self._feature_row(feature))

        card_layout.addSpacing(10)

        # -- Built with -----------------------------------------------------
        card_layout.addWidget(self._section_header("Built With"))
        tech_row = QHBoxLayout()
        tech_row.setSpacing(10)
        tech_row.setContentsMargins(0, 2, 0, 0)
        for tech in ("Python", "PyQt5", "OpenModelica"):
            tech_row.addWidget(self._pill(tech))
        tech_row.addStretch()
        card_layout.addLayout(tech_row)

        card_layout.addSpacing(12)
        card_layout.addWidget(self._separator())
        card_layout.addSpacing(10)

        # -- Attribution & actions (centered) -------------------------------
        dev = QLabel(
            'Developed by '
            '<a href="%s" style="color:%s; text-decoration:none; font-weight:600;">'
            'FOSSEE, IIT Bombay</a>' % (FOSSEE_URL, ACCENT)
        )
        dev.setFont(QFont("Segoe UI", 13))
        dev.setAlignment(Qt.AlignCenter)
        dev.setTextFormat(Qt.RichText)
        dev.setTextInteractionFlags(Qt.TextBrowserInteraction)
        dev.setOpenExternalLinks(True)
        dev.setStyleSheet("color: %s; background: transparent;" % TEXT_SECONDARY)
        card_layout.addWidget(dev)

        card_layout.addSpacing(4)

        button_row = QHBoxLayout()
        button_row.setSpacing(14)
        button_row.setAlignment(Qt.AlignCenter)
        button_row.addWidget(self._action_button("Visit FOSSEE", FOSSEE_URL, primary=True))
        button_row.addWidget(self._action_button("View on GitHub", GITHUB_URL, primary=False))
        card_layout.addLayout(button_row)

        card_layout.addSpacing(12)
        card_layout.addWidget(self._separator())
        card_layout.addSpacing(6)

        footer = QLabel("© 2025 FOSSEE, IIT Bombay  •  Under active development")
        footer.setFont(QFont("Segoe UI", 11))
        footer.setAlignment(Qt.AlignCenter)
        footer.setStyleSheet("color: %s; background: transparent;" % TEXT_MUTED)
        card_layout.addWidget(footer)

        wrap_layout.addWidget(card, 0, Qt.AlignHCenter)
        wrap_layout.addStretch()
        scroll.setWidget(wrapper)

    # -- Helpers ------------------------------------------------------------
    def _load_logo(self):
        for name in ("logoo.png", "logo.png"):
            path = os.path.join(ICONS_DIR, name)
            if os.path.exists(path):
                pixmap = QPixmap(path)
                if not pixmap.isNull():
                    return pixmap.scaled(
                        118, 118, Qt.KeepAspectRatio, Qt.SmoothTransformation
                    )
        return None

    def _fit_title_font(self, text, max_width):
        """Pick the largest title size that fits on one line (avoids clipping)."""
        for size in range(34, 17, -1):
            font = QFont("Segoe UI", size, QFont.Bold)
            if QFontMetrics(font).horizontalAdvance(text) <= max_width:
                return font
        return QFont("Segoe UI", 18, QFont.Bold)

    def _section_header(self, text):
        label = QLabel(text.upper())
        font = QFont("Segoe UI Semibold", 10)
        font.setLetterSpacing(QFont.AbsoluteSpacing, 1.5)
        label.setFont(font)
        label.setStyleSheet("color: %s; background: transparent;" % ACCENT)
        return label

    def _separator(self):
        line = QWidget()
        line.setFixedHeight(1)
        line.setStyleSheet("background-color: rgba(255, 255, 255, 0.08);")
        return line

    def _feature_row(self, text):
        row = QWidget()
        row.setStyleSheet("background: transparent;")
        layout = QHBoxLayout(row)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.setSpacing(14)

        dot = QLabel("●")
        dot.setFont(QFont("Segoe UI", 8))
        dot.setStyleSheet("color: %s; background: transparent;" % ACCENT)
        dot.setContentsMargins(0, 4, 0, 0)
        layout.addWidget(dot, 0, Qt.AlignTop)

        label = QLabel(text)
        label.setFont(QFont("Segoe UI", 13))
        label.setWordWrap(True)
        label.setStyleSheet("color: %s; background: transparent;" % TEXT_PRIMARY)
        layout.addWidget(label, 1)
        return row

    def _pill(self, text):
        pill = QLabel(text)
        pill.setFont(QFont("Segoe UI Semibold", 11))
        pill.setAlignment(Qt.AlignCenter)
        pill.setStyleSheet("""
            color: #bfdbfe;
            background-color: rgba(96, 165, 250, 0.12);
            border: 1px solid rgba(96, 165, 250, 0.35);
            border-radius: 13px;
            padding: 6px 16px;
        """)
        return pill

    def _action_button(self, text, url, primary):
        btn = QPushButton(text)
        btn.setCursor(Qt.PointingHandCursor)
        btn.setFont(QFont("Segoe UI Semibold", 12))
        btn.setFixedHeight(44)
        btn.setMinimumWidth(190)
        if primary:
            btn.setStyleSheet("""
                QPushButton {
                    color: #0b1220;
                    background-color: #60a5fa;
                    border: 1px solid #60a5fa;
                    border-radius: 12px;
                    padding: 8px 26px;
                }
                QPushButton:hover { background-color: #7cb5fb; border: 1px solid #7cb5fb; }
                QPushButton:pressed { background-color: #4f93e6; }
            """)
        else:
            btn.setStyleSheet("""
                QPushButton {
                    color: #e2e8f0;
                    background-color: rgba(255, 255, 255, 0.05);
                    border: 1px solid rgba(255, 255, 255, 0.18);
                    border-radius: 12px;
                    padding: 8px 26px;
                }
                QPushButton:hover {
                    color: #ffffff;
                    background-color: rgba(255, 255, 255, 0.10);
                    border: 1px solid rgba(255, 255, 255, 0.35);
                }
            """)
        btn.clicked.connect(lambda: webbrowser.open(url))
        return btn

    # -- Background painting (mirrors the Landing page) ---------------------
    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing, True)

        gradient = QLinearGradient(0, 0, self.width(), self.height())
        gradient.setColorAt(0.0, QColor(BG_TOP))
        gradient.setColorAt(1.0, QColor(BG_BOTTOM))
        painter.fillRect(self.rect(), QBrush(gradient))

        grid_pen = QPen(QColor(255, 255, 255, 10), 1, Qt.DashLine)
        painter.setPen(grid_pen)
        grid_size = 100
        for x in range(0, self.width(), grid_size):
            painter.drawLine(x, 0, x, self.height())
        for y in range(0, self.height(), grid_size):
            painter.drawLine(0, y, self.width(), y)
        painter.end()
