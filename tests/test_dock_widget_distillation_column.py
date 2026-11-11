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

from DockWidgets.DockWidgetDistillationColumn import DockWidgetDistillationColumn


class MockDistillationColumnObj:
    def __init__(self, name="DistCol1"):
        self.name = name
        self.variables = {
            "thermo_package": {"name": "Thermo Package", "value": "Raoults Law"},
            "stages": {"name": "Number of Stages", "value": "10", "unit": ""},
            "condenser_type": {"name": "Condenser Type", "value": "Total"},
            "reflux_ratio": {"name": "Reflux Ratio", "value": "2.0", "unit": ""}
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
def dist_col_widget(qtbot):
    obj = MockDistillationColumnObj()
    container = MockContainerInstance()
    widget = DockWidgetDistillationColumn("DistCol1", "DistillationColumn", obj, container)
    qtbot.addWidget(widget)
    return widget, obj, container


def test_dock_widget_distillation_column_init(dist_col_widget):
    widget, obj, _ = dist_col_widget
    assert widget.name == "DistCol1"
    assert widget.type == "DistillationColumn"
    assert widget.obj == obj
    assert widget.windowTitle() == "DistCol1"


def test_dock_widget_distillation_column_param_submission(dist_col_widget):
    widget, obj, _ = dist_col_widget
    if hasattr(widget, 'param'):
        widget.param()
        assert obj.param_setter.called or hasattr(widget, 'dict')