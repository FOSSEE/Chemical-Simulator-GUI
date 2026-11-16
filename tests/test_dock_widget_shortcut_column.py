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
from python.utils.UnitOperations import ShortcutColumn
from python.DockWidgets.DockWidgetShortcutColumn import DockWidgetShortcutColumn


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
def shortcut_fixture():
    obj = ShortcutColumn("Shortcut1")
    obj.param_setter = MagicMock()
    container = MockContainerInstance()
    container._objects[obj.name] = obj
    widget = DockWidgetShortcutColumn(obj.name, "ShortcutColumn", obj, container)
    return widget, obj, container


def test_dock_widget_shortcut_column_init(shortcut_fixture):
    widget, obj, _ = shortcut_fixture
    assert widget.name == obj.name
    assert widget.type == "ShortcutColumn"
    assert widget.obj is obj
    assert widget.windowTitle() == obj.name
    assert len(widget.input_dict) == 9


def test_dock_widget_shortcut_column_update_compounds(shortcut_fixture):
    widget, obj, _ = shortcut_fixture
    obj.variables['HKey']['value'] = 1
    obj.variables['LKey']['value'] = 2
    widget.update_compounds()
    assert widget.cb1.currentText() == "Water"
    assert widget.cb2.currentText() == "Ethanol"


def test_dock_widget_shortcut_column_param_submission(shortcut_fixture):
    widget, obj, _ = shortcut_fixture
    # input_dict layout:
    # 0: cb1 (HKey)
    # 1: cb2 (LKey)
    # 2: le1 (HKey_x_pc)
    # 3: le2 (LKey_x_pc)
    # 4: cb3 (Ctype)
    # 5: le3 (Pcond)
    # 6: le4 (Preb)
    # 7: le5 (RR)
    # 8: cbTP (thermo)
    widget.input_dict[2].setText("0.01")
    widget.input_dict[3].setText("0.01")
    widget.input_dict[5].setText("101325")
    widget.input_dict[6].setText("101325")
    widget.input_dict[7].setText("1.5")

    widget.show()
    widget.param()

    obj.param_setter.assert_called_once()
    assert not widget.isVisible()


def test_dock_widget_shortcut_column_results_category(shortcut_fixture):
    widget, obj, container = shortcut_fixture
    name = obj.name
    headers = [f"{name}.Ntmin", f"{name}.RRmin", f"{name}.Nt", f"{name}.Qc", f"{name}.Qr"]
    values = [8.5, 1.2, 16.0, 50000.0, 60000.0]
    container.result = [headers, values]

    widget.results_category(name)
    assert widget.tableWidget.rowCount() == 5
