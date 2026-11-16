import os
import sys
from unittest.mock import MagicMock, patch
import pytest
from PyQt5.QtWidgets import QApplication, QMainWindow
from PyQt5.QtCore import Qt

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
for p in [os.path.join(PROJECT_ROOT, 'src', 'main'), os.path.join(PROJECT_ROOT, 'src', 'main', 'python')]:
    if p not in sys.path:
        sys.path.insert(0, p)

from python.utils.ComponentSelector import compound_selected
from python.utils.UnitOperations import Splitter
from python.DockWidgets.DockWidgetSplitter import DockWidgetSplitter


class MockSocket:
    def __init__(self, socket_id=1, parent=None):
        self.id = socket_id
        self.parent = parent
        self.in_lines = []
        self.out_lines = []


class MockLine:
    def __init__(self, source_socket, target_socket):
        self.source = source_socket
        self.target = target_socket


class MockNodeItem:
    def __init__(self, obj, num_inputs=1, num_outputs=2):
        self.obj = obj
        self.input = [MockSocket(socket_id=i, parent=self) for i in range(num_inputs)]
        self.output = [MockSocket(socket_id=i, parent=self) for i in range(num_outputs)]
        self.update_output_ports = MagicMock()


class MockGraphicsView:
    def __init__(self, items=None):
        self._items = items or []
        self._scroll_bar = MagicMock()
        self._scroll_bar.value.return_value = 100

    def items(self):
        return list(self._items)

    def horizontalScrollBar(self):
        return self._scroll_bar


class MockContainerInstance:
    def __init__(self):
        self.graphics = MagicMock()
        self.graphics.graphicsView = MockGraphicsView()


@pytest.fixture(autouse=True)
def setup_app_and_compounds():
    app = QApplication.instance() or QApplication(sys.argv)
    compound_selected.clear()
    compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
    yield app
    compound_selected.clear()
    while QApplication.overrideCursor() is not None:
        QApplication.restoreOverrideCursor()


@pytest.fixture
def splitter_fixture():
    obj = Splitter("Splitter1")
    container = MockContainerInstance()
    node_item = MockNodeItem(obj, num_inputs=1, num_outputs=2)
    container.graphics.graphicsView._items.append(node_item)
    widget = DockWidgetSplitter("Splitter1", "Splitter", obj, container)
    return widget, obj, container, node_item


def test_splitter_initialization(splitter_fixture):
    widget, obj, _, _ = splitter_fixture
    assert widget.name == "Splitter1"
    assert widget.type == "Splitter"
    assert widget.obj is obj
    assert widget.windowTitle() == obj.name
    assert widget.no_combo.currentText() == "2"
    assert widget.cb2.currentText() == "Split_Ratio"
    assert len(widget.stream_edits) == 2


def test_equalize_streams_split_ratio(splitter_fixture):
    widget, _, _, _ = splitter_fixture
    widget.cb2.setCurrentText("Split_Ratio")
    widget.equalize_streams()
    assert float(widget.stream_edits[0].text()) == pytest.approx(0.5, 0.001)
    assert float(widget.stream_edits[1].text()) == pytest.approx(0.5, 0.001)


def test_equalize_streams_flow_missing_input(splitter_fixture):
    widget, _, container, _ = splitter_fixture
    container.graphics.graphicsView._items.clear()
    widget.cb2.setCurrentText("Molar_Flow")
    with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
        widget.equalize_streams()
        mock_warn.assert_called_once()
        assert "Input Missing" in mock_warn.call_args[0][1]


def test_equalize_streams_molar_flow_success(splitter_fixture):
    widget, _, _, node_item = splitter_fixture
    widget.cb2.setCurrentText("Molar_Flow")

    source_obj = MagicMock()
    source_obj.variables = {'F_p[1]': {'value': 100.0}}
    source_node = MagicMock()
    source_node.obj = source_obj
    source_socket = MockSocket(1, parent=source_node)
    line = MockLine(source_socket, node_item.input[0])
    node_item.input[0].in_lines.append(line)

    widget.equalize_streams()
    assert float(widget.stream_edits[0].text()) == pytest.approx(50.0, 0.001)
    assert float(widget.stream_edits[1].text()) == pytest.approx(50.0, 0.001)


def test_normalize_streams_zero_sum(splitter_fixture):
    widget, _, _, _ = splitter_fixture
    for edit in widget.stream_edits:
        edit.setText("0.0")
    with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
        widget.normalize_streams()
        mock_warn.assert_called_once()
        assert "Cannot normalize zero values" in mock_warn.call_args[0][2]


def test_normalize_streams_split_ratio(splitter_fixture):
    widget, _, _, _ = splitter_fixture
    widget.cb2.setCurrentText("Split_Ratio")
    widget.stream_edits[0].setText("2.0")
    widget.stream_edits[1].setText("6.0")
    widget.normalize_streams()
    assert float(widget.stream_edits[0].text()) == pytest.approx(0.25, 0.001)
    assert float(widget.stream_edits[1].text()) == pytest.approx(0.75, 0.001)


def test_normalize_streams_flow_missing_input(splitter_fixture):
    widget, _, container, _ = splitter_fixture
    container.graphics.graphicsView._items.clear()
    widget.cb2.setCurrentText("Mass_Flow")
    widget.stream_edits[0].setText("2.0")
    widget.stream_edits[1].setText("6.0")
    with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
        widget.normalize_streams()
        mock_warn.assert_called_once()
        assert "Input Missing" in mock_warn.call_args[0][1]


def test_normalize_streams_flow_success(splitter_fixture):
    widget, _, _, node_item = splitter_fixture
    widget.cb2.setCurrentText("Mass_Flow")

    source_obj = MagicMock()
    source_obj.variables = {'Fm_p[1]': {'value': 200.0}}
    source_node = MagicMock()
    source_node.obj = source_obj
    source_socket = MockSocket(1, parent=source_node)
    line = MockLine(source_socket, node_item.input[0])
    node_item.input[0].in_lines.append(line)

    widget.stream_edits[0].setText("10.0")
    widget.stream_edits[1].setText("30.0")
    widget.normalize_streams()
    assert float(widget.stream_edits[0].text()) == pytest.approx(50.0, 0.001)
    assert float(widget.stream_edits[1].text()) == pytest.approx(150.0, 0.001)


def test_get_input_flow_various_conditions(splitter_fixture):
    widget, _, container, node_item = splitter_fixture

    # 1. No node item
    container.graphics.graphicsView._items.clear()
    assert widget.get_input_flow("Molar_Flow") is None

    # 2. Node item with no input socket
    container.graphics.graphicsView._items.append(node_item)
    node_item.input.clear()
    assert widget.get_input_flow("Molar_Flow") is None

    # 3. Input socket with no in_lines
    node_item.input.append(MockSocket(1, parent=node_item))
    assert widget.get_input_flow("Molar_Flow") is None

    # 4. Valid lines for Molar_Flow and Mass_Flow
    source_obj = MagicMock()
    source_obj.name = "InStream"
    source_obj.variables = {
        'F_p[1]': {'value': 123.45},
        'Fm_p[1]': {'value': 678.90}
    }
    source_node = MagicMock()
    source_node.obj = source_obj
    source_socket = MockSocket(1, parent=source_node)
    line = MockLine(source_socket, node_item.input[0])
    node_item.input[0].in_lines.append(line)

    assert widget.get_input_flow("Molar_Flow") == pytest.approx(123.45)
    assert widget.get_input_flow("Mass_Flow") == pytest.approx(678.90)


def test_auto_distribute_from_input(splitter_fixture):
    widget, _, _, node_item = splitter_fixture
    widget.cb2.setCurrentText("Split_Ratio")
    # Returns early for Split_Ratio
    widget.auto_distribute_from_input()

    widget.cb2.setCurrentText("Molar_Flow")
    # If no inlet flow, zeroes out
    widget.auto_distribute_from_input()
    for edit in widget.stream_edits:
        assert edit.text() == "0.000000"

    # With negative inlet flow
    source_obj = MagicMock()
    source_obj.variables = {'F_p[1]': {'value': -50.0}}
    source_node = MagicMock()
    source_node.obj = source_obj
    source_socket = MockSocket(1, parent=source_node)
    node_item.input[0].in_lines = [MockLine(source_socket, node_item.input[0])]
    widget.auto_distribute_from_input()

    # With positive inlet flow (e.g. 10.0 split over 2 outlets)
    source_obj.variables['F_p[1]']['value'] = 10.0
    widget.auto_distribute_from_input()
    assert float(widget.stream_edits[0].text()) == pytest.approx(5.0, 0.0001)
    assert float(widget.stream_edits[1].text()) == pytest.approx(5.0, 0.0001)


def test_on_output_count_changed(splitter_fixture):
    widget, _, _, _ = splitter_fixture
    widget.no_combo.setCurrentText("3")
    assert len(widget.stream_edits) == 3
    assert float(widget.stream_edits[0].text()) == pytest.approx(1.0 / 3.0, 0.0001)

    # Change to Molar Flow and then change count
    widget.cb2.setCurrentText("Molar_Flow")
    widget.no_combo.setCurrentText("4")
    assert len(widget.stream_edits) == 4


def test_fun_calculation_type_toggle(splitter_fixture):
    widget, _, _, _ = splitter_fixture
    widget.cb2.setCurrentText("Molar_Flow")
    for u in widget.stream_units:
        assert u.text() == "mol/s"

    widget.cb2.setCurrentText("Mass_Flow")
    for u in widget.stream_units:
        assert u.text() == "g/s"

    widget.cb2.setCurrentText("Split_Ratio")
    for u in widget.stream_units:
        assert u.text() == ""


def test_param_validation_and_submission(splitter_fixture):
    widget, obj, _, node_item = splitter_fixture
    obj.param_setter = MagicMock()

    # 1. Empty field
    widget.stream_edits[0].setText("")
    with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
        widget.param()
        mock_warn.assert_called_once()
        assert "Invalid Input" in mock_warn.call_args[0][1]

    # 2. Negative field
    widget.stream_edits[0].setText("-0.5")
    with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
        widget.param()
        mock_warn.assert_called_once()
        assert "cannot be negative" in mock_warn.call_args[0][2]

    # 3. Non-numeric field
    widget.stream_edits[0].setText("abc")
    with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
        widget.param()
        mock_warn.assert_called_once()
        assert "valid numeric values" in mock_warn.call_args[0][2]

    # 4. Split Ratio sum != 1.0
    widget.cb2.setCurrentText("Split_Ratio")
    widget.stream_edits[0].setText("0.3")
    widget.stream_edits[1].setText("0.3")
    with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
        widget.param()
        mock_warn.assert_called_once()
        assert "Invalid Split Ratio" in mock_warn.call_args[0][1]

    # 5. Split Ratio valid submission
    widget.stream_edits[0].setText("0.6")
    widget.stream_edits[1].setText("0.4")
    widget.param()
    obj.param_setter.assert_called_once_with([2, "Split_Ratio", 0.6, 0.4])
    node_item.update_output_ports.assert_called_once_with(2)

    # 6. Molar Flow without input stream
    widget.cb2.setCurrentText("Molar_Flow")
    widget.stream_edits[0].setText("50.0")
    widget.stream_edits[1].setText("50.0")
    with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
        widget.param()
        mock_warn.assert_called_once()
        assert "Input Missing" in mock_warn.call_args[0][1]

    # 7. Molar Flow with input stream but wrong total
    source_obj = MagicMock()
    source_obj.variables = {'F_p[1]': {'value': 100.0}}
    source_node = MagicMock()
    source_node.obj = source_obj
    source_socket = MockSocket(1, parent=source_node)
    node_item.input[0].in_lines = [MockLine(source_socket, node_item.input[0])]

    widget.stream_edits[0].setText("30.0")
    widget.stream_edits[1].setText("30.0")
    with patch("PyQt5.QtWidgets.QMessageBox.warning") as mock_warn:
        widget.param()
        mock_warn.assert_called_once()
        assert "Invalid Flow" in mock_warn.call_args[0][1]

    # 8. Molar Flow with total == 0 (auto distribute)
    widget.stream_edits[0].setText("0.0")
    widget.stream_edits[1].setText("0.0")
    obj.param_setter.reset_mock()
    widget.param()
    obj.param_setter.assert_called_once_with([2, "Molar_Flow", 50.0, 50.0])

    # 9. Molar Flow with exact matching sum
    widget.stream_edits[0].setText("70.0")
    widget.stream_edits[1].setText("30.0")
    obj.param_setter.reset_mock()
    widget.param()
    obj.param_setter.assert_called_once_with([2, "Molar_Flow", 70.0, 30.0])


def test_update_connected_component_names(splitter_fixture):
    widget, _, container, node_item = splitter_fixture

    # Case A: Splitter node not found
    container.graphics.graphicsView._items.clear()
    widget.update_connected_component_names()

    # Case B: Outputs not connected
    container.graphics.graphicsView._items.append(node_item)
    widget.update_connected_component_names()
    assert widget.stream_names[0].text() == "Not Connected"

    # Case C: Connected to target node with target.parent.obj.name
    target_obj1 = MagicMock()
    target_obj1.name = "Comp1"
    target_node1 = MagicMock()
    target_node1.obj = target_obj1
    target_sock1 = MockSocket(1, parent=target_node1)
    node_item.output[0].out_lines = [MockLine(node_item.output[0], target_sock1)]

    # Case D: Connected to target node with target.parent.parent.obj.name
    target_obj2 = MagicMock()
    target_obj2.name = "Comp2"
    target_parent2 = MagicMock()
    target_parent2.obj = target_obj2
    target_node2 = MagicMock()
    del target_node2.obj
    target_node2.parent = target_parent2
    target_sock2 = MockSocket(2, parent=target_node2)
    node_item.output[1].out_lines = [MockLine(node_item.output[1], target_sock2)]

    widget.update_connected_component_names()
    assert widget.stream_names[0].text() == "Comp1"
    assert widget.stream_names[1].text() == "Comp2"


def test_splitter_show_event_and_autosize(splitter_fixture):
    widget, _, _, _ = splitter_fixture
    main_window = QMainWindow()
    main_window.addDockWidget(Qt.LeftDockWidgetArea, widget)
    widget._has_autosized = False
    widget._autosize()
    assert widget._has_autosized is True

    # Floating widget autosize branch
    widget.setFloating(True)
    widget._has_autosized = False
    widget._autosize()
    assert widget._has_autosized is True
