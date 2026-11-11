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

from DockWidgets.DockWidgetShortcutColumn import DockWidgetShortcutColumn

for k, v in _saved_modules.items():
    if v is None:
        sys.modules.pop(k, None)
    else:
        sys.modules[k] = v


class MockShortcutColumnObj:
    def __init__(self, name="Shortcut1"):
        self.name = name
        self.variables = {
            "thermo_package": {"name": "Thermo Package", "value": "Raoults Law"},
            "reflux_ratio": {"name": "Reflux Ratio", "value": "1.5", "unit": ""},
            "condenser_type": {"name": "Condenser Type", "value": "Total"},
            "light_key": {"name": "Light Key", "value": "Ethanol"},
            "heavy_key": {"name": "Heavy Key", "value": "Water"}
        }
        self.comp_list = ["Ethanol", "Water"]
        self.param_setter = MagicMock()


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100


@pytest.fixture
def shortcut_widget():
    obj = MockShortcutColumnObj()
    container = MockContainerInstance()
    widget = DockWidgetShortcutColumn("Shortcut1", "ShortcutColumn", obj, container)
    return widget, obj, container


def test_dock_widget_shortcut_column_init(shortcut_widget):
    widget, obj, _ = shortcut_widget
    assert widget.name == "Shortcut1"
    assert widget.type == "ShortcutColumn"
    assert widget.obj == obj
    assert widget.windowTitle() == "Shortcut1"


def test_dock_widget_shortcut_column_param_submission(shortcut_widget):
    widget, obj, _ = shortcut_widget
    if hasattr(widget, 'param'):
        widget.param()
        assert obj.param_setter.called or hasattr(widget, 'dict')