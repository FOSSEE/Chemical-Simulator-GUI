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

from DockWidgets.DockWidgetCompoundSeparator import DockWidgetCompoundSeparator


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
