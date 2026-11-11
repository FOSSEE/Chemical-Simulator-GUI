import os
import sys
from unittest.mock import MagicMock
import pytest
from PyQt5.QtWidgets import QApplication

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
for p in [os.path.join(PROJECT_ROOT, 'src', 'main'), os.path.join(PROJECT_ROOT, 'src', 'main', 'python')]:
    if p not in sys.path:
        sys.path.insert(0, p)

_saved_modules = {k: sys.modules.get(k) for k in [
    'utils.Graphics', 'python.utils.Graphics', 'utils.Container', 'python.utils.Container'
]}

mock_graphics = MagicMock()
mock_container = MagicMock()
mock_graphics.lst = []

sys.modules['utils.Graphics'] = mock_graphics
sys.modules['python.utils.Graphics'] = mock_graphics
sys.modules['utils.Container'] = mock_container
sys.modules['python.utils.Container'] = mock_container

app = QApplication.instance()
if app is None:
    app = QApplication(sys.argv)

from DockWidgets.DockWidgetFlash import DockWidgetFlash

for k, v in _saved_modules.items():
    if v is None:
        sys.modules.pop(k, None)
    else:
        sys.modules[k] = v


class MockFlashObj:
    def __init__(self, name="Flash1"):
        self.name = name
        self.variables = {
            "thermo_package": {"name": "Thermo Package", "value": "Raoults Law"},
            "Tdef": {"name": "Flash Temperature", "value": "300", "unit": "K"},
            "BTdef": {"value": True},
            "Pdef": {"name": "Flash Pressure", "value": "101325", "unit": "Pa"},
            "BPdef": {"value": True}
        }
        self.param_setter = MagicMock()


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100


@pytest.fixture
def flash_widget(qtbot):
    obj = MockFlashObj()
    container = MockContainerInstance()
    widget = DockWidgetFlash("Flash1", "Flash", obj, container)
    qtbot.addWidget(widget)
    return widget, obj, container


def test_dock_widget_flash_initialization(flash_widget):
    widget, obj, _ = flash_widget
    assert widget.name == "Flash1"
    assert widget.type == "Flash"
    assert widget.obj == obj
    assert widget.windowTitle() == "Flash1"
    assert len(widget.input_dict) == 5
    assert widget.check1.isChecked() is True
    assert widget.check2.isChecked() is True


def test_dock_widget_flash_toggle_checkboxes(flash_widget):
    widget, _, _ = flash_widget
    widget.check1.setChecked(False)
    assert widget.le2.isEnabled() is False

    widget.check1.setChecked(True)
    assert widget.le2.isEnabled() is True

    widget.check2.setChecked(False)
    assert widget.le3.isEnabled() is False


def test_dock_widget_flash_param_submission(flash_widget):
    widget, obj, _ = flash_widget
    widget.check1.setChecked(True)
    widget.le2.setText("350.5")
    widget.check2.setChecked(True)
    widget.le3.setText("200000")

    widget.param()

    obj.param_setter.assert_called_once()
    assert widget.dict[1] is True
    assert widget.dict[2] == 350.5
    assert widget.dict[3] is True
    assert widget.dict[4] == 200000.0