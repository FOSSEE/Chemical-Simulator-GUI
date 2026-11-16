import os
import sys
from unittest.mock import MagicMock, patch
import pytest
from PyQt5.QtWidgets import QApplication, QMainWindow, QTableWidget, QWidget
from PyQt5.QtCore import Qt

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
for p in [os.path.join(PROJECT_ROOT, 'src', 'main'), os.path.join(PROJECT_ROOT, 'src', 'main', 'python')]:
    if p not in sys.path:
        sys.path.insert(0, p)

import python.utils.Container
from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.DockWidgets.DockWidgetMaterialStream import DockWidgetMaterialStream


class MockParentWidget(QWidget):
    def __init__(self, container):
        super().__init__()
        self.container = container


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
def stream_fixture():
    obj = MaterialStream("MS1")
    obj.param_setter = MagicMock()
    for c in compound_selected:
        obj.variables[c] = {'name': c, 'value': 0.5, 'unit': ''}

    container = MockContainerInstance()
    container._objects[obj.name] = obj

    mock_node = MagicMock()
    mock_node.name = obj.name
    mock_node.obj = obj
    mock_node.update_tooltip = MagicMock()
    container.graphics.graphicsView.items.return_value = [mock_node]

    widget = DockWidgetMaterialStream(obj.name, "MaterialStream", obj, container)
    return widget, obj, container, mock_node


# ----------------- Amount Table Tests ----------------- #

def test_populate_amounts_table_mole_fraction_two_columns():
    table = QTableWidget()
    rows = [("Water(chemsep)", 0.5), ("Ethanol(chemsep)", 0.5)]
    DockWidgetMaterialStream._populate_amounts_table(table, rows, "Mole Fraction")

    assert table.columnCount() == 2
    assert table.rowCount() == 2
    assert table.horizontalHeaderItem(0).text() == "Compound"
    assert table.horizontalHeaderItem(1).text() == "Value"
    assert table.item(0, 0).text() == "Water(chemsep)"
    assert table.item(0, 1).text() == "0.50"


def test_populate_amounts_table_mole_flow_three_columns_with_unit():
    table = QTableWidget()
    rows = [("Water(chemsep)", 50.0, "mol/s"), ("Ethanol(chemsep)", 50.0, "mol/s")]
    DockWidgetMaterialStream._populate_amounts_table(table, rows, "Mole Flow")

    assert table.columnCount() == 3
    assert table.rowCount() == 2
    assert table.horizontalHeaderItem(0).text() == "Compound"
    assert table.horizontalHeaderItem(1).text() == "Value"
    assert table.horizontalHeaderItem(2).text() == "Unit"
    assert table.item(0, 2).text() == "mol/s"


# ----------------- Stream Initialization and Modes ----------------- #

def test_stream_initialization(stream_fixture):
    widget, obj, _, _ = stream_fixture
    assert widget.name == obj.name
    assert widget.type == "MaterialStream"
    assert widget.obj is obj
    assert widget.windowTitle() == obj.name
    assert widget.comboBox.count() == 5  # PT, PH, PVF, TVF, PS


def test_stream_modes_switch(stream_fixture):
    widget, obj, _, _ = stream_fixture
    for mode in ["PT", "PH", "PVF", "TVF", "PS"]:
        widget.comboBox.setCurrentText(mode)
        assert widget.obj.mode == mode
        assert "x_pc" in widget.input_dict
        assert len(widget.x_pclist) == 2


def test_stream_modes_empty_fallback():
    obj = MaterialStream("MSEmpty")
    obj.modes_list = []
    obj.param_getter = MagicMock(return_value={"T": 300, "P": 101325})
    container = MockContainerInstance()

    widget = DockWidgetMaterialStream(obj.name, "MaterialStream", obj, container)
    assert "T" in widget.input_dict
    assert "P" in widget.input_dict


def test_stream_equalize(stream_fixture):
    widget, _, _, _ = stream_fixture
    widget.equalize()
    assert float(widget.x_pclist[0].text()) == pytest.approx(0.5, 0.001)
    assert float(widget.x_pclist[1].text()) == pytest.approx(0.5, 0.001)


def test_stream_normalize_valid(stream_fixture):
    widget, _, _, _ = stream_fixture
    widget.x_pclist[0].setText("2.0")
    widget.x_pclist[1].setText("6.0")
    widget.normalize()
    assert float(widget.x_pclist[0].text()) == pytest.approx(0.25, 0.001)
    assert float(widget.x_pclist[1].text()) == pytest.approx(0.75, 0.001)


def test_stream_normalize_zero_shows_error(stream_fixture):
    widget, _, _, _ = stream_fixture
    widget.show_error = MagicMock()
    widget.x_pclist[0].setText("0.0")
    widget.x_pclist[1].setText("")
    widget.normalize()
    widget.show_error.assert_called_once()


def test_stream_update_compounds(stream_fixture):
    widget, obj, _, _ = stream_fixture
    obj.update_compounds = MagicMock()
    obj.init_variables = MagicMock()

    compound_selected.append("Methanol(chemsep)")
    widget.update_compounds()

    assert len(widget.x_pclist) == 3
    obj.update_compounds.assert_called_once()
    obj.init_variables.assert_called_once()


def test_stream_param_submission_success(stream_fixture):
    widget, obj, _, mock_node = stream_fixture
    widget.comboBox.setCurrentText("PT")

    widget.x_pclist[0].setText("0.4")
    widget.x_pclist[1].setText("0.6")

    for k, v in widget.input_dict.items():
        if k != "x_pc" and hasattr(v, "setText"):
            v.setText("300")

    widget.show()
    widget.param()

    obj.param_setter.assert_called_once()
    mock_node.update_tooltip.assert_called_once()
    assert not widget.isVisible()


def test_stream_param_empty_x_pc_shows_error(stream_fixture):
    widget, obj, _, _ = stream_fixture
    widget.show_error = MagicMock()
    widget.x_pclist[0].setText("")
    widget.param()
    widget.show_error.assert_called_once()


def test_stream_param_empty_field_shows_error(stream_fixture):
    widget, obj, _, _ = stream_fixture
    widget.show_error = MagicMock()
    widget.x_pclist[0].setText("0.5")
    widget.x_pclist[1].setText("0.5")

    for k, v in widget.input_dict.items():
        if k != "x_pc" and hasattr(v, "setText"):
            v.setText("")
            break

    widget.param()
    widget.show_error.assert_called_once()


def test_stream_show_result_and_clear_results(stream_fixture):
    widget, _, _, _ = stream_fixture
    mock_s = MagicMock()
    mock_s.name = "StreamTest"
    mock_s.results_category = MagicMock()

    DockWidgetMaterialStream.show_result([mock_s])
    mock_s.results_category.assert_called_once_with("StreamTest")

    widget.amountsMixtureTable.setRowCount(3)
    widget.mTableWidget.setRowCount(3)
    widget.clear_results()
    assert widget.amountsMixtureTable.rowCount() == 0
    assert widget.mTableWidget.rowCount() == 0


def test_stream_results_category_full(stream_fixture):
    widget, obj, container, mock_node = stream_fixture
    name = obj.name

    # Build results matching amounts (x_pc, xm_pc, F_pc, Fm_pc)
    # phase 1, 2, 3 and compounds 1, 2
    headers = []
    values = []

    for prefix in ["x_pc", "xm_pc", "F_pc", "Fm_pc"]:
        for phase in [1, 2, 3]:
            for comp in [1, 2]:
                headers.append(f"{name}.{prefix}[{phase},{comp}]")
                values.append(0.5)

    # Phase properties (scalar and indexed by phase [1], [2], [3])
    phase_props = ["P", "T", "xvap", "Cp_p", "H_p", "S_p", "F_p", "Fm_p", "MW_p"]
    for p in phase_props:
        if p in ["P", "T", "xvap"]:
            headers.append(f"{name}.{p}")
            values.append(101325.0)
        else:
            for phase in [1, 2, 3]:
                headers.append(f"{name}.{p}[{phase}]")
                values.append(500.0)

    # Vapor pressure
    headers.append(f"{name}.Pvap_c[1]")
    values.append(2300.0)
    headers.append(f"{name}.Pvap_c[2]")
    values.append(5900.0)

    container.result = [headers, values]

    # Set parent widget with container for tooltip update
    parent_widget = MockParentWidget(container)
    widget.setParent(parent_widget)

    widget.results_category(name)

    assert widget.mTableWidget.rowCount() > 0
    assert widget.lTableWidget.rowCount() > 0
    assert widget.vTableWidget.rowCount() > 0
    assert widget.amountsMixtureTable.rowCount() == 2

    # Verify switching composition basis options
    for basis in ['Mass Fraction', 'Mole Flow', 'Mass Flow', 'Mole Fraction']:
        widget.cbCompositionBasis.setCurrentText(basis)
        assert widget.amountsMixtureTable.rowCount() == 2


def test_stream_autosize_and_show_event(stream_fixture):
    widget, _, _, _ = stream_fixture
    main_window = QMainWindow()
    main_window.addDockWidget(Qt.LeftDockWidgetArea, widget)
    widget._has_autosized = False
    widget._autosize()
    assert widget._has_autosized is True

    # Floating dock branch
    widget.setFloating(True)
    widget._has_autosized = False
    widget._autosize()
    assert widget._has_autosized is True
