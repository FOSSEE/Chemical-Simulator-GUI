import os
import sys
from unittest.mock import MagicMock, patch
import pytest
from PyQt5.QtWidgets import QApplication

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
for p in [os.path.join(PROJECT_ROOT, 'src', 'main'), os.path.join(PROJECT_ROOT, 'src', 'main', 'python')]:
    if p not in sys.path:
        sys.path.insert(0, p)

import python.utils.Container
from python.utils.ComponentSelector import compound_selected
from python.utils.UnitOperations import CompoundSeparator
from python.DockWidgets.DockWidgetCompoundSeparator import DockWidgetCompoundSeparator


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100


@pytest.fixture(autouse=True)
def setup_compounds():
    app = QApplication.instance() or QApplication(sys.argv)
    compound_selected.clear()
    compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
    yield app
    compound_selected.clear()
    while QApplication.overrideCursor() is not None:
        QApplication.restoreOverrideCursor()


@pytest.fixture
def comp_sep_fixture():
    obj = CompoundSeparator("CompSep1")
    obj.param_setter = MagicMock()
    container = MockContainerInstance()
    widget = DockWidgetCompoundSeparator(obj.name, "CompoundSeparator", obj, container)
    return widget, obj, container


def test_dock_widget_compound_separator_init(comp_sep_fixture):
    widget, obj, _ = comp_sep_fixture
    assert widget.name == obj.name
    assert widget.type == "CompoundSeparator"
    assert widget.obj is obj
    assert widget.windowTitle() == obj.name
    assert len(widget.input_dict) >= 4


def test_dock_widget_compound_separator_param_success(comp_sep_fixture):
    widget, obj, _ = comp_sep_fixture
    # input_dict: [radio1, radio2, combo1, lineEdit1, combo2, lineEdit2]
    widget.input_dict[0].setChecked(True)
    widget.input_dict[1].setChecked(False)

    # Set valid values for compound lines
    widget.input_dict[3].setText("0.8")
    widget.input_dict[5].setText("0.2")

    widget.show()
    widget.param()

    obj.param_setter.assert_called_once()
    assert not widget.isVisible()


def test_dock_widget_compound_separator_param_empty_shows_error(comp_sep_fixture):
    widget, _, _ = comp_sep_fixture
    widget.show_error = MagicMock()

    widget.input_dict[3].setText("")
    widget.param()
    widget.show_error.assert_called_once()


def test_dock_widget_compound_separator_update_compounds(comp_sep_fixture):
    widget, obj, _ = comp_sep_fixture
    compound_selected.append("Methanol(chemsep)")
    widget.update_compounds()
    # Now there are 3 compounds, so input_dict has 2 radios + 3*(combo+line) = 8 items
    assert len(widget.input_dict) == 8
