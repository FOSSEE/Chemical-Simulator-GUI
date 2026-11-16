import os
import sys
from unittest.mock import MagicMock, patch
import pytest
from PyQt5.QtWidgets import QApplication

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
for p in [os.path.join(PROJECT_ROOT, 'src', 'main'), os.path.join(PROJECT_ROOT, 'src', 'main', 'python')]:
    if p not in sys.path:
        sys.path.insert(0, p)

from python.utils.ComponentSelector import compound_selected
from python.utils.UnitOperations import AdiabaticCompressor, AdiabaticExpander
from python.DockWidgets.DockWidgetCompressorExpander import DockWidgetCompressorExpander


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100
        self.graphics.graphicsView.items.return_value = []
        self.result = [[], []]
        self._objects = {}

    def fetch_object(self, name):
        return self._objects.get(name)


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
def compressor_fixture():
    obj = AdiabaticCompressor("Compressor1")
    obj.param_setter = MagicMock()
    container = MockContainerInstance()
    container._objects[obj.name] = obj

    mock_item = MagicMock()
    mock_item.name = obj.name
    mock_item.update_tooltip = MagicMock()
    container.graphics.graphicsView.items.return_value = [mock_item]

    widget = DockWidgetCompressorExpander(obj.name, "Compressor", obj, container)
    return widget, obj, container, mock_item


@pytest.fixture
def expander_fixture():
    obj = AdiabaticExpander("Expander1")
    obj.param_setter = MagicMock()
    container = MockContainerInstance()
    container._objects[obj.name] = obj

    widget = DockWidgetCompressorExpander(obj.name, "Expander", obj, container)
    return widget, obj, container


def test_compressor_initialization(compressor_fixture):
    widget, obj, _, _ = compressor_fixture
    assert widget.name == obj.name
    assert widget.type == "Compressor"
    assert widget.obj is obj
    assert widget.windowTitle() == obj.name
    assert widget.comboBox.count() == 3


def test_expander_initialization(expander_fixture):
    widget, obj, _ = expander_fixture
    assert widget.name == obj.name
    assert widget.type == "Expander"
    assert widget.obj is obj
    assert widget.windowTitle() == obj.name
    assert widget.comboBox.count() == 3


def test_compressor_modes_selection_all_modes(compressor_fixture):
    widget, obj, _, _ = compressor_fixture

    # Test all 3 modes: Pdel, Pout, Q
    for mode_idx in range(widget.comboBox.count()):
        widget.comboBox.setCurrentIndex(mode_idx)
        assert len(widget.input_dict) > 0
        assert "Thermo Package" in widget.input_dict


def test_compressor_empty_modes_fallback():
    obj = AdiabaticCompressor("CompressorEmpty")
    obj.modes_list = []
    obj.param_getter = MagicMock(return_value={"Eff": 1})
    container = MockContainerInstance()

    widget = DockWidgetCompressorExpander(obj.name, "Compressor", obj, container)
    assert not widget.comboBox.isEnabled()
    assert "Eff" in widget.input_dict


def test_compressor_param_submission_success(compressor_fixture):
    widget, obj, container, mock_item = compressor_fixture

    # Add an item that raises an exception on update_tooltip
    failing_item = MagicMock()
    failing_item.name = obj.name
    failing_item.update_tooltip.side_effect = RuntimeError("tooltip failed")
    container.graphics.graphicsView.items.return_value = [failing_item, mock_item]

    # Mode 0 is Pdel
    widget.comboBox.setCurrentIndex(0)
    # Fill in values for line edits
    for k, v in widget.input_dict.items():
        if hasattr(v, "setText"):
            v.setText("100000")

    widget.show()
    widget.param()

    obj.param_setter.assert_called_once()
    assert widget.dict["Pdel"] == "100000"
    mock_item.update_tooltip.assert_called_once()
    assert not widget.isVisible()


def test_compressor_param_scrollbar_exception(compressor_fixture):
    widget, obj, container, _ = compressor_fixture
    container.graphics.graphicsView.horizontalScrollBar.side_effect = RuntimeError("scroll error")

    widget.comboBox.setCurrentIndex(0)
    for k, v in widget.input_dict.items():
        if hasattr(v, "setText"):
            v.setText("100000")

    widget.show()
    widget.param()
    assert not widget.isVisible()


def test_compressor_param_empty_field_shows_error(compressor_fixture):
    widget, obj, _, _ = compressor_fixture
    widget.show_error = MagicMock()

    # Clear one of the line edits
    for k, v in widget.input_dict.items():
        if hasattr(v, "setText"):
            v.setText("")
            break

    widget.param()
    widget.show_error.assert_called_once()


def test_show_result_static(compressor_fixture):
    widget, _, _, _ = compressor_fixture
    mock_item = MagicMock()
    mock_item.name = "CompA"
    mock_item.results_category = MagicMock()

    invalid_item = object()
    DockWidgetCompressorExpander.show_result([mock_item, invalid_item])
    mock_item.results_category.assert_called_once_with("CompA")


def test_clear_results(compressor_fixture):
    widget, _, _, _ = compressor_fixture
    widget.tableWidget.setRowCount(5)
    widget.clear_results()
    assert widget.tableWidget.rowCount() == 0


def test_results_category_success(compressor_fixture):
    widget, obj, container, _ = compressor_fixture
    name = obj.name

    headers = [f"{name}.Pout", f"{name}.Eff", f"{name}.Q"]
    values = [200000.0, 0.85, 4500.0]
    container.result = [headers, values]

    widget.results_category(name)
    assert widget.tableWidget.rowCount() == 3
    assert widget.tableWidget.item(0, 0).text() != ""
