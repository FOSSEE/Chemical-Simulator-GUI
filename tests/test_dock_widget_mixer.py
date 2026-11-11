import os
import sys
from unittest.mock import MagicMock
import pytest
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
for p in [os.path.join(PROJECT_ROOT, 'src', 'main'), os.path.join(PROJECT_ROOT, 'src', 'main', 'python')]:
    if p not in sys.path:
        sys.path.insert(0, p)

# Save original modules
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

from DockWidgets.DockWidgetMixer import DockWidgetMixer

# Restore real modules immediately after import so other tests are not broken
for k, v in _saved_modules.items():
    if v is None:
        sys.modules.pop(k, None)
    else:
        sys.modules[k] = v


class MockMixerObj:
    def __init__(self, name="Mixer1"):
        self.name = name
        self.Pout_modes = ["Minimum", "Inlet 1", "Average"]
        self.variables = {
            "NI": {"name": "Number of Inlets", "value": 2, "unit": ""},
            "outPress": {"name": "Outlet Pressure Mode", "value": "Minimum", "unit": ""}
        }
        self.param_setter = MagicMock()


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100


@pytest.fixture
def mixer_widget():
    obj = MockMixerObj()
    container = MockContainerInstance()
    widget = DockWidgetMixer("Mixer1", "Mixer", obj, container)
    return widget, obj, container


def test_dock_widget_mixer_initialization(mixer_widget):
    widget, obj, _ = mixer_widget
    assert widget.name == "Mixer1"
    assert widget.type == "Mixer"
    assert widget.obj == obj
    assert widget.windowTitle() == "Mixer1"
    assert widget.ni_combo is not None
    assert widget.ni_combo.count() == 5
    assert widget.ni_combo.currentText() == "2"


def test_dock_widget_mixer_input_params_list(mixer_widget):
    widget, obj, _ = mixer_widget
    assert len(widget.input_dict) == 2
    assert widget.input_dict[0] == widget.ni_combo
    assert widget.input_dict[1] == widget.cb2
    assert widget.cb2.count() == 3
    assert widget.cb2.currentText() == "Minimum"


def test_dock_widget_mixer_param_submission(mixer_widget, monkeypatch):
    widget, obj, _ = mixer_widget
    mock_node = MagicMock()
    mock_node.obj = obj
    
    # Patch Graphics.lst safely in-scope
    monkeypatch.setattr("python.utils.Graphics.lst", [mock_node])

    widget.ni_combo.setCurrentText("4")
    widget.cb2.setCurrentText("Average")

    widget.param()

    obj.param_setter.assert_called_once_with([4, "Average"])
    assert widget.dict == [4, "Average"]
    mock_node.update_input_ports.assert_called_once_with(4)


def test_dock_widget_mixer_btn_click(mixer_widget):
    widget, obj, _ = mixer_widget
    sys.modules['python.utils.Graphics'].lst = []

    widget.ni_combo.setCurrentText("3")
    widget.btn.click()

    obj.param_setter.assert_called_once_with([3, "Minimum"])