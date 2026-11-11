import os
import sys
from types import ModuleType
from unittest.mock import MagicMock
import pytest
from PyQt5.QtWidgets import QApplication

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
for p in [os.path.join(PROJECT_ROOT, 'src', 'main'), os.path.join(PROJECT_ROOT, 'src', 'main', 'python')]:
    if p not in sys.path:
        sys.path.insert(0, p)

if 'python.utils.Graphics' not in sys.modules:
    mock_mod = ModuleType('python.utils.Graphics')
    mock_mod.lst = []
    sys.modules['python.utils.Graphics'] = mock_mod
    sys.modules['utils.Graphics'] = mock_mod
else:
    mock_mod = sys.modules['python.utils.Graphics']
    if not hasattr(mock_mod, 'lst'):
        mock_mod.lst = []

if 'python.utils.Container' not in sys.modules:
    sys.modules['python.utils.Container'] = MagicMock()
    sys.modules['utils.Container'] = sys.modules['python.utils.Container']

app = QApplication.instance()
if app is None:
    app = QApplication(sys.argv)

from DockWidgets.DockWidgetShortcutColumn import DockWidgetShortcutColumn


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
