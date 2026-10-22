import os
import re
import sys
import unittest
from unittest.mock import patch, MagicMock

# Ensure headless Qt
os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication, QGraphicsView, QWidget, QTableWidget, QTableWidgetItem, QVBoxLayout
from PyQt5.QtCore import QPointF, Qt

# Initialize QApplication once
app = QApplication.instance()
if app is None:
    app = QApplication(sys.argv)

from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.utils.UnitOperations import Mixer, Heater
from python.utils.Graphics import NodeItem, NodeLine, lst, dock_widget_lst
from python.utils.Container import Container, flat_list

# Keep a handle on the real module: other test files replace
# sys.modules['python.utils.Container'] with a mock, so patching by dotted
# path would patch the mock instead of the code under test.
container_module = sys.modules[Container.__module__]


class ContainerTestBase(unittest.TestCase):
    """Shared setup: a real Container on an offscreen QGraphicsView."""

    def setUp(self):
        compound_selected.clear()
        compound_selected.extend(["Water(chemsep)", "Ethanol(chemsep)"])
        lst.clear()
        dock_widget_lst.clear()
        Mixer.counter = 1
        Heater.counter = 1
        MaterialStream.counter = 1

        self.view = QGraphicsView()
        self.msg = MagicMock()
        self.container = Container(self.msg, self.view)

        # Never write real Undo/Redo files from tests
        self.snapshot_patch = patch.object(self.container.graphics, "push_snapshot")
        self.mock_push_snapshot = self.snapshot_patch.start()

    def tearDown(self):
        self.snapshot_patch.stop()
        lst.clear()
        dock_widget_lst.clear()
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

    # ----------------- helpers -----------------

    def messages(self):
        """All HTML strings sent to the message browser."""
        return [c.args[0] for c in self.msg.append.call_args_list]

    def any_message_contains(self, text):
        return any(text in m for m in self.messages())

    def add_node(self, obj):
        node = self.container.add_unit_operation(obj)
        self.assertIsInstance(node, NodeItem)
        return node

    def connect(self, src_node, src_idx, tgt_node, tgt_idx):
        """Draw a stream line the same way Graphics.load_canvas does."""
        src_socket = src_node.output[src_idx]
        tgt_socket = tgt_node.input[tgt_idx]
        line = NodeLine(QPointF(0, 0), QPointF(100, 0), 'op')
        line.source = src_socket
        line.target = tgt_socket
        src_socket.out_lines.append(line)
        tgt_socket.in_lines.append(line)
        self.container.scene.addItem(line)
        return line


# =============================================================================
# 1. Construction and simple helpers
# =============================================================================

class TestContainerBasics(ContainerTestBase):

    def test_initial_state(self):
        c = self.container
        self.assertEqual(c.unit_operations, [])
        self.assertIsNone(c.thermo_package)
        self.assertIsNone(c.compounds)
        self.assertIsNone(c.flowsheet)
        self.assertEqual(c.result, [])
        self.assertIs(c.graphicsView, self.view)
        self.assertIs(c.scene, c.graphics.get_scene())

    def test_init_clears_message_browser(self):
        self.msg.setText.assert_called_with("")

    def test_msg_signal_is_forwarded_to_message_browser(self):
        self.container.signals.msg_signal.emit("hello")
        self.msg.append.assert_called_with("hello")

    def test_current_time_format(self):
        self.assertRegex(self.container.current_time(), r"^\d{1,2}:\d{1,2}:\d{1,2}$")

    def test_add_compounds_and_thermo_package(self):
        self.container.add_compounds(["Water", "Ethanol"])
        self.container.add_thermo_package("RaoultsLaw")
        self.assertEqual(self.container.compounds, ["Water", "Ethanol"])
        self.assertEqual(self.container.thermo_package, "RaoultsLaw")

    def test_update_compounds_delegates_to_graphics(self):
        with patch.object(self.container.graphics, "update_compounds") as mock_update:
            self.container.update_compounds()
        mock_update.assert_called_once_with()

    def test_flat_list(self):
        self.assertEqual(flat_list([[1, 2], [3], []]), [1, 2, 3])
        self.assertEqual(flat_list([]), [])


# =============================================================================
# 2. add_unit_operation / fetch_object
# =============================================================================

class TestAddUnitOperation(ContainerTestBase):

    def test_add_unit_operation_adds_node_to_scene_and_model(self):
        mixer = Mixer()
        node = self.add_node(mixer)

        self.assertIs(node.obj, mixer)
        self.assertIn(mixer, self.container.unit_operations)
        self.assertIn(node, self.container.scene.items())
        self.assertTrue(self.any_message_contains(f"<b>{mixer.name}</b> is instantiated"))

    def test_add_multiple_component_types(self):
        objs = [MaterialStream(), Mixer(), Heater()]
        for obj in objs:
            self.add_node(obj)
        self.assertEqual(self.container.unit_operations, objs)

    def test_adding_same_object_twice_does_not_duplicate_model_entry(self):
        mixer = Mixer()
        self.container.add_unit_operation(mixer)
        self.msg.append.reset_mock()
        self.container.add_unit_operation(mixer)

        self.assertEqual(self.container.unit_operations.count(mixer), 1)
        self.assertFalse(self.any_message_contains("is instantiated"))

    def test_add_unit_operation_returns_none_when_node_not_created(self):
        mixer = Mixer()
        with patch.object(self.container.graphics, "create_node_item", return_value=None):
            result = self.container.add_unit_operation(mixer)

        self.assertIsNone(result)
        self.assertNotIn(mixer, self.container.unit_operations)

    def test_add_unit_operation_returns_none_on_exception(self):
        mixer = Mixer()
        with patch.object(self.container.graphics, "create_node_item", side_effect=RuntimeError("boom")):
            result = self.container.add_unit_operation(mixer)

        self.assertIsNone(result)
        self.assertNotIn(mixer, self.container.unit_operations)

    def test_fetch_object_by_name(self):
        mixer, heater = Mixer(), Heater()
        self.container.unit_operations.extend([mixer, heater])

        self.assertIs(self.container.fetch_object(heater.name), heater)
        self.assertIs(self.container.fetch_object(mixer.name), mixer)

    def test_fetch_object_missing_name_returns_none(self):
        self.container.unit_operations.append(Mixer())
        self.assertIsNone(self.container.fetch_object("NoSuchUnit"))


# =============================================================================
# 3. delete
# =============================================================================

class TestDelete(ContainerTestBase):

    def test_delete_node_removes_it_everywhere(self):
        mixer = Mixer()
        node = self.add_node(mixer)
        dock = node.dock_widget

        self.container.delete([node])

        self.assertNotIn(mixer, self.container.unit_operations)
        self.assertNotIn(node, lst)
        self.assertNotIn(dock, dock_widget_lst)
        self.assertIsNone(node.scene())
        self.assertFalse(dock.isVisible())
        self.mock_push_snapshot.assert_called_once_with()

    def test_delete_node_also_removes_connected_lines(self):
        feed = self.add_node(MaterialStream())
        mixer = self.add_node(Mixer())
        line = self.connect(feed, 0, mixer, 0)

        self.container.delete([mixer])

        self.assertIsNone(line.scene())
        self.assertNotIn(line, feed.output[0].out_lines)
        # The stream that was connected stays on the canvas
        self.assertIn(feed.obj, self.container.unit_operations)
        self.assertIsNotNone(feed.scene())

    def test_delete_line_only_keeps_nodes(self):
        feed = self.add_node(MaterialStream())
        mixer = self.add_node(Mixer())
        line = self.connect(feed, 0, mixer, 1)

        with patch.object(mixer.obj, "remove_connection") as mock_remove:
            self.container.delete([line])

        mock_remove.assert_called_once_with(1, mixer.input[1].id)
        self.assertEqual(feed.output[0].out_lines, [])
        self.assertEqual(mixer.input[1].in_lines, [])
        self.assertIsNone(line.scene())
        self.assertEqual(len(self.container.unit_operations), 2)
        self.mock_push_snapshot.assert_called_once_with()

    def test_delete_empty_list_does_not_push_snapshot(self):
        self.container.delete([])
        self.mock_push_snapshot.assert_not_called()

    def test_delete_continues_after_item_error(self):
        bad = self.add_node(Mixer())
        good = self.add_node(Heater())

        with patch.object(bad, "scene", side_effect=RuntimeError("boom")):
            self.container.delete([bad, good])

        self.assertNotIn(good.obj, self.container.unit_operations)
        self.assertIsNone(good.scene())
        self.mock_push_snapshot.assert_called_once_with()


# =============================================================================
# 4. msg_browser
# =============================================================================

class TestMsgBrowser(ContainerTestBase):

    def test_no_flowsheet_emits_nothing(self):
        self.msg.append.reset_mock()
        self.container.msg_browser()
        self.msg.append.assert_not_called()

    def test_stdout_and_stderr_are_shown_with_line_breaks(self):
        self.container.flowsheet = MagicMock(stdout=b"line1\nline2", stderr=b"err1\nerr2")
        self.container.msg_browser()

        msgs = self.messages()
        self.assertIn('<span style="color:green">line1<br/>line2</span>', msgs)
        self.assertIn('<span style="color:red">err1<br/>err2</span>', msgs)

    def test_empty_output_is_skipped(self):
        self.container.flowsheet = MagicMock(stdout=b"", stderr=None)
        self.msg.append.reset_mock()
        self.container.msg_browser()
        self.msg.append.assert_not_called()


# =============================================================================
# 5. simulate
# =============================================================================

class TestSimulate(ContainerTestBase):

    def setUp(self):
        super().setUp()
        self.container.disableInterfaceforSimulation = MagicMock()
        self.flowsheet_patch = patch.object(container_module, "Flowsheet")
        self.mock_flowsheet_cls = self.flowsheet_patch.start()
        self.fs = self.mock_flowsheet_cls.return_value
        self.fs.result_data = [["header"], ["values"]]
        self.fs.last_error = ""

        self.results_ready = MagicMock()
        self.container.signals.results_ready.connect(self.results_ready)

    def tearDown(self):
        self.flowsheet_patch.stop()
        super().tearDown()

    def build_mixer_flowsheet(self):
        """2 Material Streams -> Mixer -> 1 Material Stream (the team's standard test case)."""
        s1 = self.add_node(MaterialStream())
        s2 = self.add_node(MaterialStream())
        mixer = self.add_node(Mixer())
        s3 = self.add_node(MaterialStream())
        self.connect(s1, 0, mixer, 0)
        self.connect(s2, 0, mixer, 1)
        self.connect(mixer, 0, s3, 0)
        return s1, s2, mixer, s3

    def test_sm_mode_success(self):
        self.build_mixer_flowsheet()
        self.container.simulate("SM")

        self.fs.simulate_SM.assert_called_once_with(self.container.ip, self.container.op)
        self.fs.simulate_EQN.assert_not_called()
        self.assertTrue(self.any_message_contains("<b>Sequential</b> mode"))
        self.assertTrue(self.any_message_contains("Simulation <b>Successful.</b>"))
        self.assertEqual(self.container.result, self.fs.result_data)
        self.results_ready.assert_called_once_with()

    def test_eqn_mode_passes_message_browser(self):
        self.build_mixer_flowsheet()
        self.container.simulate("EQN")

        self.fs.simulate_EQN.assert_called_once_with(self.msg)
        self.fs.simulate_SM.assert_not_called()
        self.assertTrue(self.any_message_contains("<b>Equation</b> mode"))

    def test_interface_is_locked_then_unlocked(self):
        self.container.simulate("EQN")
        calls = self.container.disableInterfaceforSimulation.call_args_list
        self.assertEqual(calls[0].args, (True,))
        self.assertEqual(calls[-1].args, (False,))

    def test_unit_operations_are_added_to_flowsheet(self):
        s1, s2, mixer, s3 = self.build_mixer_flowsheet()
        self.container.simulate("SM")

        added = [c.args[0] for c in self.fs.add_unit_operations.call_args_list]
        self.assertEqual(added, [s1.obj, s2.obj, mixer.obj, s3.obj])

    def test_one_failing_unit_operation_does_not_stop_others(self):
        s1, s2, mixer, s3 = self.build_mixer_flowsheet()
        self.fs.add_unit_operations.side_effect = [None, RuntimeError("bad"), None, None]
        self.container.simulate("SM")

        self.assertEqual(self.fs.add_unit_operations.call_count, 4)
        self.fs.simulate_SM.assert_called_once()

    def test_compound_names_are_stripped_of_database_suffix(self):
        self.container.add_compounds(["Water(chemsep)", "1-Butanol (chemsep)", "Methanol"])
        self.container.simulate("EQN")
        self.fs.add_compound_list.assert_called_once_with(["Water", "1-Butanol", "Methanol"])

    def test_no_compounds_skips_add_compound_list(self):
        self.container.add_compounds([])
        with patch.dict(container_module.__dict__, {"compound_selected": []}):
            self.container.simulate("EQN")
        self.fs.add_compound_list.assert_not_called()

    def test_ip_op_maps_follow_canvas_connections(self):
        s1, s2, mixer, s3 = self.build_mixer_flowsheet()
        self.container.simulate("SM")

        ip, op = self.container.ip, self.container.op
        self.assertEqual(set(ip), {mixer.name, s3.name})
        self.assertEqual(set(op), {s1.name, s2.name, mixer.name})
        # Socket indices are recorded in port order
        self.assertEqual(sorted(idx for idx, _ in ip[mixer.name]), [0, 1])
        self.assertEqual([idx for idx, _ in op[mixer.name]], [0])

    def test_unconnected_units_produce_warnings(self):
        mixer = self.add_node(Mixer())
        stream = self.add_node(MaterialStream())
        self.container.simulate("EQN")

        self.assertTrue(self.any_message_contains(f"Warning: {mixer.name} - Missing Socket Connection(s)."))
        self.assertTrue(self.any_message_contains(f"Warning: {stream.name} - Missing Socket Connection(s)."))

    def test_fully_connected_flowsheet_has_no_warnings(self):
        self.build_mixer_flowsheet()
        self.container.simulate("EQN")
        self.assertFalse(self.any_message_contains("Missing Socket Connection"))

    def test_stream_connected_on_one_side_is_not_a_warning(self):
        s1, s2, mixer, s3 = self.build_mixer_flowsheet()
        self.container.simulate("EQN")
        # s1 only has an output connection, s3 only an input connection
        self.assertFalse(self.any_message_contains(f"Warning: {s1.name}"))
        self.assertFalse(self.any_message_contains(f"Warning: {s3.name}"))

    def test_partially_connected_mixer_warns(self):
        s1 = self.add_node(MaterialStream())
        mixer = self.add_node(Mixer())
        self.connect(s1, 0, mixer, 0)
        self.container.simulate("EQN")
        self.assertTrue(self.any_message_contains(f"Warning: {mixer.name} - Missing Socket Connection(s)."))

    def test_success_sets_dock_widgets_read_only(self):
        dw = MagicMock()
        dock_widget_lst.append(dw)
        self.container.simulate("EQN")
        dw.set_read_only.assert_called_with(True)

    def test_failure_when_result_is_too_short(self):
        dw = MagicMock()
        dock_widget_lst.append(dw)
        self.fs.result_data = [["only header"]]
        self.container.simulate("EQN")

        self.assertTrue(self.any_message_contains("Simulation <b>Failed.</b>"))
        self.assertFalse(self.any_message_contains("Successful"))
        dw.set_read_only.assert_called_with(False)
        self.results_ready.assert_not_called()

    def test_failure_shows_escaped_openmodelica_error(self):
        self.fs.result_data = []
        self.fs.last_error = "Error: <x> is undefined\nline 2"
        self.container.simulate("EQN")

        self.assertTrue(self.any_message_contains(
            "<b>OpenModelica Error:</b><br/>Error: &lt;x&gt; is undefined<br/>line 2"
        ))

    def test_failure_without_error_detail_shows_only_failed(self):
        self.fs.result_data = []
        self.fs.last_error = ""
        self.container.simulate("EQN")

        self.assertTrue(self.any_message_contains("Simulation <b>Failed.</b>"))
        self.assertFalse(self.any_message_contains("OpenModelica Error"))

    def test_sm_exception_is_reported_and_treated_as_failure(self):
        self.fs.simulate_SM.side_effect = RuntimeError("solver diverged")
        self.container.simulate("SM")

        self.assertTrue(self.any_message_contains("Sequential Mode failed: solver diverged"))
        self.assertTrue(self.any_message_contains("Simulation <b>Failed.</b>"))
        self.assertIsNone(self.container.result)
        self.container.disableInterfaceforSimulation.assert_called_with(False)

    def test_eqn_exception_is_caught_and_interface_unlocked(self):
        self.fs.simulate_EQN.side_effect = RuntimeError("omc not found")
        self.container.simulate("EQN")

        self.assertTrue(self.any_message_contains("Simulation error: omc not found"))
        self.container.disableInterfaceforSimulation.assert_called_with(False)

    def test_flowsheet_creation_failure_aborts(self):
        self.mock_flowsheet_cls.side_effect = RuntimeError("cannot create")
        self.container.simulate("SM")

        self.assertTrue(self.any_message_contains("Failed to prepare Flowsheet: cannot create"))
        self.assertFalse(self.any_message_contains("Successful"))
        self.assertFalse(self.any_message_contains("Failed."))
        self.container.disableInterfaceforSimulation.assert_called_with(False)

    def test_success_updates_material_stream_tooltips(self):
        s1, s2, mixer, s3 = self.build_mixer_flowsheet()
        with patch.object(NodeItem, "update_tooltip_selectedVar") as mock_tooltip:
            self.container.simulate("SM")
        # One call per MaterialStream on the canvas
        self.assertEqual(mock_tooltip.call_count, 3)


# =============================================================================
# 6. _populate_results
# =============================================================================

class TestPopulateResults(ContainerTestBase):

    def make_dock_with_table(self):
        dock = QWidget()
        table = QTableWidget(2, 2, dock)
        QVBoxLayout(dock).addWidget(table)
        for r in range(2):
            for c in range(2):
                table.setItem(r, c, QTableWidgetItem(f"{r},{c}"))
        dock.set_read_only = MagicMock()
        return dock, table

    def test_results_are_shown_and_tables_made_read_only(self):
        dock, table = self.make_dock_with_table()
        dock_widget_lst.append(dock)

        with patch.object(container_module.DockWidget, "show_result") as mock_show:
            self.container._populate_results()

        mock_show.assert_called_once_with(dock_widget_lst)
        dock.set_read_only.assert_called_once_with(True)
        for r in range(2):
            for c in range(2):
                flags = table.item(r, c).flags()
                self.assertFalse(flags & Qt.ItemIsEditable)
                self.assertTrue(flags & Qt.ItemIsSelectable)
                self.assertTrue(flags & Qt.ItemIsEnabled)

    def test_empty_table_cells_are_skipped(self):
        dock, table = self.make_dock_with_table()
        table.takeItem(0, 0)
        dock_widget_lst.append(dock)

        with patch.object(container_module.DockWidget, "show_result"):
            self.container._populate_results()

        self.assertIsNone(table.item(0, 0))
        self.assertFalse(table.item(1, 1).flags() & Qt.ItemIsEditable)

    def test_show_result_error_is_swallowed(self):
        with patch.object(container_module.DockWidget, "show_result", side_effect=RuntimeError("bad")):
            self.container._populate_results()

    def test_results_ready_signal_triggers_population(self):
        # The slot is connected in __init__, so a fresh container is needed to see the patch
        view = QGraphicsView()
        with patch.object(Container, "_populate_results") as mock_populate:
            c = Container(MagicMock(), view)
            c.signals.results_ready.emit()
        mock_populate.assert_called_once_with()


# =============================================================================
# 7. Toolbar / interface locking
# =============================================================================

class TestInterfaceLocking(ContainerTestBase):

    def setUp(self):
        super().setUp()
        self.view_mock = MagicMock()
        self.main_window = self.view_mock.parent.return_value.parent.return_value
        self.container.graphicsView = self.view_mock

    def enabled(self, action):
        return getattr(self.main_window, action).setProperty.call_args.args

    def test_enable_toolbar_true(self):
        self.container.enableToolbar(True)
        for action in ["actionNew", "actionZoomIn", "actionZoomOut", "actionResetZoom",
                       "actionEquationOriented", "actionSelectCompounds"]:
            self.assertEqual(self.enabled(action), ("enabled", True), action)
        # Terminate is only available while a simulation is running
        self.assertEqual(self.enabled("actionTerminate"), ("enabled", False))

    def test_enable_toolbar_false(self):
        self.container.enableToolbar(False)
        self.assertEqual(self.enabled("actionNew"), ("enabled", False))
        self.assertEqual(self.enabled("actionTerminate"), ("enabled", True))

    def test_lock_interface_for_simulation(self):
        self.container.disableInterfaceforSimulation(True)

        self.assertEqual(self.enabled("menubar"), ("enabled", False))
        self.assertEqual(self.enabled("dockWidget"), ("enabled", False))
        self.assertEqual(self.enabled("actionNew"), ("enabled", False))
        self.view_mock.setInteractive.assert_called_once_with(False)
        self.assertEqual(QApplication.overrideCursor().shape(), Qt.WaitCursor)

    def test_unlock_interface_after_simulation(self):
        self.container.disableInterfaceforSimulation(True)
        self.container.disableInterfaceforSimulation(False)

        self.assertEqual(self.enabled("menubar"), ("enabled", True))
        self.assertEqual(self.enabled("dockWidget"), ("enabled", True))
        self.assertEqual(self.enabled("actionNew"), ("enabled", True))
        self.view_mock.setInteractive.assert_called_with(True)
        self.assertEqual(QApplication.overrideCursor().shape(), Qt.ArrowCursor)


if __name__ == "__main__":
    unittest.main()
