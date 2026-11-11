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

from DockWidgets.DockWidgetCompressorExpander import DockWidgetCompressorExpander

for k, v in _saved_modules.items():
    if v is None:
        sys.modules.pop(k, None)
    else:
        sys.modules[k] = v


class MockCompressorObj:
    def __init__(self, name="Compressor1"):
        self.name = name
        self.type = "Compressor"
        self.modes_list = ["Outlet Pressure", "Pressure Ratio"]
        self.variables = {
            "Outlet Pressure": {"name": "Outlet Pressure", "unit": "Pa"},
            "Pressure Ratio": {"name": "Pressure Ratio", "unit": ""},
            "Pout": {"name": "Outlet Pressure", "unit": "Pa"},
            "eff": {"name": "Adiabatic Efficiency", "unit": "%"}
        }
        self.param_setter = MagicMock()

    def param_getter(self, mode="Outlet Pressure"):
        return {"Pout": "200000", "eff": "75"}


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100


@pytest.fixture
def comp_widget():
    obj = MockCompressorObj()
    container = MockContainerInstance()
    widget = DockWidgetCompressorExpander("Compressor1", "Compressor", obj, container)
    return widget, obj, container


def test_dock_widget_compressor_initialization(comp_widget):
    widget, obj, _ = comp_widget
    assert widget.name == "Compressor1"
    assert widget.type == "Compressor"
    assert widget.obj == obj
    assert widget.windowTitle() == "Compressor1"
    assert widget.comboBox.count() >= 2


def test_dock_widget_compressor_mode_selection(comp_widget):
    widget, _, _ = comp_widget
    widget.comboBox.setCurrentIndex(1)
    assert len(widget.input_dict) > 0


def test_dock_widget_compressor_param_submission(comp_widget):
    widget, obj, _ = comp_widget
    if "Pout" in widget.input_dict and hasattr(widget.input_dict["Pout"], "setText"):
        widget.input_dict["Pout"].setText("300000")
    if "eff" in widget.input_dict and hasattr(widget.input_dict["eff"], "setText"):
        widget.input_dict["eff"].setText("80")

    widget.param()
    obj.param_setter.assert_called_once()
    assert widget.dict.get("Pout") == "300000"
    assert widget.dict.get("eff") == "80"