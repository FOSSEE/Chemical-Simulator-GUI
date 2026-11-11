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

from DockWidgets.DockWidgetSplitter import DockWidgetSplitter

for k, v in _saved_modules.items():
    if v is None:
        sys.modules.pop(k, None)
    else:
        sys.modules[k] = v


class MockSplitterObj:
    def __init__(self, name="Splitter1"):
        self.name = name
        self.NO = 2
        self.split_ratios = [0.5, 0.5]
        self.stream_names = ["Stream_1", "Stream_2"]
        self.variables = {
            "NO": {"name": "Number of Outlets", "value": 2, "unit": ""},
            "split_ratios": {"name": "Split Ratios", "value": [0.5, 0.5], "unit": ""}
        }
        self.param_setter = MagicMock()


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100


@pytest.fixture
def splitter_widget():
    obj = MockSplitterObj()
    container = MockContainerInstance()
    widget = DockWidgetSplitter("Splitter1", "Splitter", obj, container)
    return widget, obj, container


def test_dock_widget_splitter_initialization(splitter_widget):
    widget, obj, _ = splitter_widget
    assert widget.name == "Splitter1"
    assert widget.type == "Splitter"
    assert widget.obj == obj
    assert widget.windowTitle() == "Splitter1"


def test_dock_widget_splitter_equalize(splitter_widget):
    widget, _, _ = splitter_widget
    if hasattr(widget, 'equalize_streams') and hasattr(widget, 'stream_edits') and len(widget.stream_edits) == 2:
        widget.equalize_streams()
        assert float(widget.stream_edits[0].text()) == pytest.approx(0.5, 0.01)
        assert float(widget.stream_edits[1].text()) == pytest.approx(0.5, 0.01)


def test_dock_widget_splitter_normalize(splitter_widget):
    widget, _, _ = splitter_widget
    if hasattr(widget, 'normalize_streams') and hasattr(widget, 'stream_edits') and len(widget.stream_edits) == 2:
        widget.stream_edits[0].setText("2.0")
        widget.stream_edits[1].setText("2.0")
        widget.normalize_streams()
        assert float(widget.stream_edits[0].text()) == pytest.approx(0.5, 0.01)
        assert float(widget.stream_edits[1].text()) == pytest.approx(0.5, 0.01)


def test_dock_widget_splitter_param_submit(splitter_widget, monkeypatch):
    widget, obj, _ = splitter_widget
    mock_node = MagicMock()
    mock_node.obj = obj
    monkeypatch.setattr("python.utils.Graphics.lst", [mock_node])

    if hasattr(widget, 'stream_edits') and len(widget.stream_edits) == 2:
        widget.stream_edits[0].setText("0.6")
        widget.stream_edits[1].setText("0.4")
        widget.param()
        obj.param_setter.assert_called()
