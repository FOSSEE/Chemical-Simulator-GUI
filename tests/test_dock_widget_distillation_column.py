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
from python.utils.UnitOperations import DistillationColumn
from python.DockWidgets.DockWidgetDistillationColumn import DockWidgetDistillationColumn


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar = MagicMock()
        self.graphics.graphicsView.horizontalScrollBar.return_value.value.return_value = 100
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
def dist_col_fixture():
    obj = DistillationColumn("DistCol1")
    obj.variables['Ni']['value'] = 1
    obj.variables['InT_s']['value'] = [5]
    obj.variables['Nt']['value'] = 10
    obj.param_setter = MagicMock()

    container = MockContainerInstance()
    container._objects[obj.name] = obj

    widget = DockWidgetDistillationColumn(obj.name, "DistillationColumn", obj, container)
    return widget, obj, container


def test_distillation_column_initialization(dist_col_fixture):
    widget, obj, _ = dist_col_fixture
    assert widget.name == obj.name
    assert widget.type == "DistillationColumn"
    assert widget.obj is obj
    assert widget.windowTitle() == obj.name


def test_update_compounds(dist_col_fixture):
    widget, obj, _ = dist_col_fixture
    obj.compounds = ["Water", "Ethanol"]
    obj.variables['C_Spec']['comp'] = "Ethanol"
    obj.variables['R_Spec']['comp'] = "Water"
    widget.update_compounds()

    assert widget.cb2.count() == 2
    assert widget.cb2.currentText() == "Ethanol"
    assert widget.cb4.count() == 2
    assert widget.cb4.currentText() == "Water"


def test_fun2_and_fun3_dropdown_toggles(dist_col_fixture):
    widget, _, _ = dist_col_fixture

    # Test fun2 (Condenser spec)
    widget.cb1.setCurrentText("Compound Molar Fraction")
    widget.fun2()
    assert widget.cb2.isEnabled() is True

    widget.cb1.setCurrentText("Compound Molar Flow    (mol/s)")
    widget.fun2()
    assert widget.cb2.isEnabled() is True

    widget.cb1.setCurrentText("Reflux Ratio")
    widget.fun2()
    assert widget.cb2.isEnabled() is False

    # Test fun3 (Reboiler spec)
    widget.cb3.setCurrentText("Compound Molar Fraction")
    widget.fun3()
    assert widget.cb4.isEnabled() is True

    widget.cb3.setCurrentText("Compound Molar Flow    (mol/s)")
    widget.fun3()
    assert widget.cb4.isEnabled() is True

    widget.cb3.setCurrentText("Product Molar Flow   (mol/s)")
    widget.fun3()
    assert widget.cb4.isEnabled() is False


def test_param_submission_and_scrollbar_adjustment(dist_col_fixture):
    widget, obj, container = dist_col_fixture

    # Setup valid inputs in input_dict
    # input_dict layout:
    # 0: Nt (lineEdit)
    # 1: InT_s[0] (lineEdit)
    # 2: cb5 (Ctype)
    # 3: le5 (Pcond)
    # 4: cb1 (C_Spec type)
    # 5: cb2 (C_Spec comp)
    # 6: le6 (C_Spec value)
    # 7: le7 (Preb)
    # 8: cb3 (R_Spec type)
    # 9: cb4 (R_Spec comp)
    # 10: le8 (R_Spec value)
    # 11: cbTP (thermo package)

    widget.input_dict[0].setText("12")
    widget.input_dict[1].setText("6")
    widget.input_dict[2].setCurrentText("Total")
    widget.input_dict[3].setText("101325")
    widget.input_dict[4].setCurrentText("Reflux Ratio")
    widget.input_dict[5].setCurrentText("Water")
    widget.input_dict[6].setText("2")
    widget.input_dict[7].setText("101325")
    widget.input_dict[8].setCurrentText("Product Molar Flow   (mol/s)")
    widget.input_dict[9].setCurrentText("Water")
    widget.input_dict[10].setText("50")

    widget.show()
    widget.param()

    obj.param_setter.assert_called_once()
    submitted = obj.param_setter.call_args[0][0]
    assert submitted[0] == 12  # Nt
    assert submitted[1] == 6   # InT_s location
    assert submitted[2] == "Total"
    assert submitted[3] == 101325
    assert submitted[4] == "Reflux Ratio"
    assert submitted[6] == 2
    assert submitted[7] == 101325
    assert submitted[10] == 50
    assert not widget.isVisible()


def test_show_stagewise_results(dist_col_fixture):
    widget, _, _ = dist_col_fixture
    widget.stage_res_table.show = MagicMock()
    widget.showStagewiseResults()
    widget.stage_res_table.show.assert_called_once()


def test_show_result_static_method(dist_col_fixture):
    widget, obj, _ = dist_col_fixture
    mock_item = MagicMock()
    mock_item.name = "DistColTest"
    mock_item.results_category = MagicMock()

    item_without_attr = object()
    DockWidgetDistillationColumn.showResult([mock_item, item_without_attr])
    mock_item.results_category.assert_called_once_with("DistColTest")


def test_clear_results(dist_col_fixture):
    widget, _, _ = dist_col_fixture
    widget.tableWidget.setRowCount(5)
    widget.stage_res_table.T_table.setRowCount(5)
    widget.stage_res_table.x_pc_table.setRowCount(5)

    widget.clear_results()
    assert widget.tableWidget.rowCount() == 0
    assert widget.stage_res_table.T_table.rowCount() == 0
    assert widget.stage_res_table.x_pc_table.rowCount() == 0


def test_results_category_success(dist_col_fixture):
    widget, obj, container = dist_col_fixture
    name = obj.name
    Nt = 4
    obj.variables['Nt']['value'] = Nt
    obj.compounds = ["Water", "Ethanol"]
    Nc = len(obj.compounds)

    # Build simulated result table headers and values
    headers = [
        f"{name}.Cduty.Q",
        f"{name}.Rduty.Q",
        f"{name}.condenser.T",
        f"{name}.condenser.x_pc[1,1]",
        f"{name}.condenser.x_pc[2,1]",
        f"{name}.condenser.x_pc[3,1]",
        f"{name}.tray[1].T",
        f"{name}.tray[1].x_pc[1,1]",
        f"{name}.tray[1].x_pc[2,1]",
        f"{name}.tray[1].x_pc[3,1]",
        f"{name}.tray[2].T",
        f"{name}.tray[2].x_pc[1,1]",
        f"{name}.tray[2].x_pc[2,1]",
        f"{name}.tray[2].x_pc[3,1]",
        f"{name}.reboiler.T",
        f"{name}.reboiler.x_pc[1,1]",
        f"{name}.reboiler.x_pc[2,1]",
        f"{name}.reboiler.x_pc[3,1]",
    ]
    values = [
        15000.0,
        25000.0,
        350.0,
        0.1, 0.4, 0.5,
        360.0,
        0.1, 0.4, 0.5,
        370.0,
        0.1, 0.4, 0.5,
        380.0,
        0.1, 0.4, 0.5,
    ]

    container.result = [headers, values]
    widget.results_category(name)

    assert widget.tableWidget.rowCount() == 2
    assert obj.variables['Stages.T']['value'][0] == 350.0
    assert obj.variables['Stages.T']['value'][-1] == 380.0
    assert widget.stage_res_table.T_table.rowCount() == Nt
    assert widget.stage_res_table.x_pc_table.rowCount() == Nt
