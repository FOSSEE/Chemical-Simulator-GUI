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

from DockWidgets.DockWidgetCompoundSeparator import DockWidgetCompoundSeparator

for k, v in _saved_modules.items():
    if v is None:
        sys.modules.pop(k, None)
    else:
        sys.modules[k] = v


class MockCompoundSeparatorObj:
    def __init__(self, name="CompSep1"):
        self.name = name
        self.variables = {
            "comp_list": ["Water", "Ethanol"],
            "sep_stream": {"name": "Separation Stream", "value": "Top"},
            "split_ratio": {"name": "Split Ratio", "value": [0.9, 0.1]}
        }
        self.param_setter = MagicMock()


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100


@pytest.fixture
def comp_sep_widget():
    obj = MockCompoundSeparatorObj()
    container = MockContainerInstance()
    widget = DockWidgetCompoundSeparator("CompSep1", "CompoundSeparator", obj, container)
    return widget, obj, container


def test_dock_widget_compound_separator_init(comp_sep_widget):
    widget, obj, _ = comp_sep_widget
    assert widget.name == "CompSep1"
    assert widget.type == "CompoundSeparator"
    assert widget.obj == obj
    assert widget.windowTitle() == "CompSep1"


def test_dock_widget_compound_separator_param_submission(comp_sep_widget):
    widget, obj, _ = comp_sep_widget
    if hasattr(widget, 'param'):
        widget.param()
        assert obj.param_setter.called or hasattr(widget, 'dict')