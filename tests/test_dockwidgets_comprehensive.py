import os
import sys
import unittest
from unittest.mock import MagicMock, patch

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
for p in [os.path.join(PROJECT_ROOT, 'src', 'main'), os.path.join(PROJECT_ROOT, 'src', 'main', 'python')]:
    if p not in sys.path:
        sys.path.insert(0, p)

from PyQt5 import QtCore, QtWidgets

import python.utils.Container  # noqa: F401
import utils.ComponentSelector as cs_short
from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream
from python.utils.UnitOperations import (
    AdiabaticCompressor,
    CompoundSeparator,
    DistillationColumn,
    Flash,
    Heater,
    Mixer,
    ShortcutColumn,
    Splitter,
)
from python.DockWidgets.DockWidget import BaseDockWidget, DockWidget
from python.DockWidgets.DockWidgetCompoundSeparator import DockWidgetCompoundSeparator
from python.DockWidgets.DockWidgetCompressorExpander import DockWidgetCompressorExpander
from python.DockWidgets.DockWidgetDistillationColumn import DockWidgetDistillationColumn
from python.DockWidgets.DockWidgetFlash import DockWidgetFlash
from python.DockWidgets.DockWidgetMaterialStream import DockWidgetMaterialStream
from python.DockWidgets.DockWidgetMixer import DockWidgetMixer
from python.DockWidgets.DockWidgetShortcutColumn import DockWidgetShortcutColumn
from python.DockWidgets.DockWidgetSplitter import DockWidgetSplitter


def _set_compounds(names):
    import python.utils.Streams as st_long
    import utils.Streams as st_short
    targets = [compound_selected, cs_short.compound_selected]
    for m in (st_long, st_short):
        if hasattr(m, "compound_selected"):
            targets.append(m.compound_selected)
    for lst_ref in targets:
        lst_ref.clear()
        lst_ref.extend(names)


def _make_mock_container():
    container = MagicMock()
    container.unit_operations = []
    container.result = []
    container.graphics = MagicMock()
    container.graphics.graphicsView = MagicMock()
    sb = MagicMock()
    sb.value.return_value = 300
    container.graphics.graphicsView.horizontalScrollBar.return_value = sb
    container.graphics.graphicsView.items.return_value = []
    container.graphics.scene = MagicMock()
    container.graphics.scene.items.return_value = []
    container.flowsheet = MagicMock()
    container.flowsheet.result_data = None
    return container


class TestBaseAndGenericDockWidget(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.app = QtWidgets.QApplication.instance() or QtWidgets.QApplication([])

    def setUp(self):
        _set_compounds(["Water(chemsep)", "Ethanol(chemsep)"])

    def _create_heater_dock(self):
        container = _make_mock_container()
        heater = Heater()
        heater.name = "Heater1"
        heater.EngStms = MagicMock()
        container.unit_operations.append(heater)
        container.fetch_object.return_value = heater
        dock = DockWidget(heater.name, heater.type, heater, container)
        return dock, heater, container

    def test_rename_validation_and_propagation(self):
        dock, heater, container = self._create_heater_dock()
        other = Heater()
        other.name = "Heater2"
        container.unit_operations.append(other)

        fake_node = MagicMock()
        fake_node.name = "Heater1"
        fake_node.obj = heater
        fake_node.dock_widget = dock
        dock.node_item = fake_node

        container.result = [["Heater1.Tout", "Other.T"], [350.0, 300.0]]
        container.flowsheet.result_data = [["Heater1.Tout"], [350.0]]

        with patch.object(QtWidgets.QMessageBox, "warning") as mock_warn:
            dock.le_name.setText("   ")
            self.assertFalse(dock.rename_component())
            self.assertEqual(dock.le_name.text(), "Heater1")

            dock.le_name.setText("123-bad!")
            self.assertFalse(dock.rename_component())
            self.assertEqual(dock.le_name.text(), "Heater1")

            dock.le_name.setText("Heater2")
            self.assertFalse(dock.rename_component())
            self.assertEqual(dock.le_name.text(), "Heater1")
            self.assertEqual(mock_warn.call_count, 3)

        dock.le_name.setText("PreHeater_A")
        self.assertTrue(dock.rename_component())
        self.assertEqual(heater.name, "PreHeater_A")
        self.assertEqual(heater.EngStms.name, "EngStmPreHeater_A")
        self.assertEqual(dock.windowTitle(), "PreHeater_A")
        self.assertEqual(fake_node.name, "PreHeater_A")
        self.assertEqual(container.result[0][0], "PreHeater_A.Tout")
        self.assertEqual(container.flowsheet.result_data[0][0], "PreHeater_A.Tout")
        container.graphics.push_snapshot.assert_called()

        self.assertTrue(dock.rename_component())

    def test_connections_tab_and_disconnect(self):
        dock, heater, container = self._create_heater_dock()
        peer_node = MagicMock()
        peer_node.name = "MS_In"
        peer_socket = MagicMock()
        peer_socket.parent = peer_node

        fake_line = MagicMock()
        fake_line.source = peer_socket
        fake_line.scene.return_value = MagicMock()

        in_sock = MagicMock()
        in_sock.in_lines = [fake_line]
        out_sock = MagicMock()
        out_sock.out_lines = []

        fake_node = MagicMock()
        fake_node.input = [in_sock]
        fake_node.output = [out_sock]

        dock.setup_connections_tab(fake_node)
        self.assertEqual(dock.connections_layout.rowCount(), 2)

        dock.disconnect_line(fake_line)
        container.delete.assert_called_once_with([fake_line])

    def test_param_submit_error_readonly_and_results(self):
        dock, heater, container = self._create_heater_dock()
        dock.show()

        first_key = next(k for k, v in dock.input_dict.items() if v is not None)
        orig_val = dock.input_dict[first_key].text()
        dock.input_dict[first_key].setText("")
        dock.show_error = MagicMock()
        dock.param()
        dock.show_error.assert_called()

        dock.input_dict[first_key].setText(orig_val or "350")
        dock.param()
        self.assertFalse(dock.isVisible())

        dock.set_read_only(True)
        self.assertFalse(dock.pushButton_2.isEnabled())
        dock.set_read_only(False)
        self.assertTrue(dock.pushButton_2.isEnabled())

        var_key = next(iter(heater.variables.keys()))
        container.result = [[f"{heater.name}.{var_key}"], [375.5]]
        BaseDockWidget.show_result([dock])
        self.assertGreater(dock.tableWidget.rowCount(), 0)
        dock.clear_results()
        self.assertEqual(dock.tableWidget.rowCount(), 0)


class TestDockWidgetDistillationColumn(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.app = QtWidgets.QApplication.instance() or QtWidgets.QApplication([])

    def setUp(self):
        _set_compounds(["Water(chemsep)", "Ethanol(chemsep)"])

    def _create_dist_dock(self):
        container = _make_mock_container()
        col = DistillationColumn()
        col.name = "DistCol1"
        col.variables["Ni"]["value"] = 1
        col.variables["InT_s"]["value"] = [5]
        container.fetch_object.return_value = col
        dock = DockWidgetDistillationColumn(col.name, col.type, col, container)
        return dock, col, container

    def test_specs_compounds_and_param_submission(self):
        dock, col, container = self._create_dist_dock()
        self.assertEqual(dock.windowTitle(), "DistCol1")

        dock.cb1.setCurrentText("Compound Molar Fraction")
        self.assertTrue(dock.cb2.isEnabled())
        dock.cb1.setCurrentText("Reflux Ratio")
        self.assertFalse(dock.cb2.isEnabled())

        dock.cb3.setCurrentText("Compound Molar Flow    (mol/s)")
        self.assertTrue(dock.cb4.isEnabled())
        non_comp_rspec = next(x for x in col.Rspec_list if "Compound" not in x)
        dock.cb3.setCurrentText(non_comp_rspec)
        self.assertFalse(dock.cb4.isEnabled())

        col.compounds = ["Water(chemsep)", "Ethanol(chemsep)", "Methanol(chemsep)"]
        dock.update_compounds()
        self.assertEqual(dock.cb2.count(), 3)
        self.assertEqual(dock.cb4.count(), 3)

        dock.input_dict[0].setText("10")
        dock.input_dict[1].setText("5")
        dock.le5.setText("101325")
        dock.le6.setText("2")
        dock.le7.setText("101325")
        dock.le8.setText("2")
        dock.show()
        with patch.object(col, "param_setter") as mock_setter:
            dock.param()
            mock_setter.assert_called_once()
        self.assertFalse(dock.isVisible())

        dock.input_dict[0].setText("not_an_int")
        dock.param()

    def test_stagewise_and_summary_results(self):
        dock, col, container = self._create_dist_dock()
        Nt = col.variables["Nt"]["value"]
        Nc = len(col.compounds)

        headers = []
        values = []
        for k in col.result_parameters:
            headers.append(f"DistCol1.{k}")
            values.append(101.325)

        headers.append("DistCol1.condenser.T")
        values.append(351.2)
        for c in range(1, Nc + 1):
            for p in range(1, 4):
                headers.append(f"DistCol1.condenser.x_pc[{p},{c}]")
                values.append(0.5)

        for tray in range(1, Nt - 1):
            headers.append(f"DistCol1.tray[{tray}].T")
            values.append(355.0 + tray)
            for c in range(1, Nc + 1):
                for p in range(1, 4):
                    headers.append(f"DistCol1.tray[{tray}].x_pc[{p},{c}]")
                    values.append(0.5)

        headers.append("DistCol1.reboiler.T")
        values.append(373.1)
        for c in range(1, Nc + 1):
            for p in range(1, 4):
                headers.append(f"DistCol1.reboiler.x_pc[{p},{c}]")
                values.append(0.5)

        container.result = [headers, values]
        DockWidgetDistillationColumn.showResult([dock])

        self.assertEqual(dock.tableWidget.rowCount(), len(col.result_parameters))
        self.assertEqual(dock.stage_res_table.T_table.rowCount(), Nt)
        self.assertEqual(dock.stage_res_table.x_pc_table.columnCount(), 2 * Nc)

        dock.showStagewiseResults()
        self.assertTrue(dock.stage_res_table.isVisible())
        dock.stage_res_table.close()

        dock.clear_results()
        self.assertEqual(dock.tableWidget.rowCount(), 0)
        self.assertEqual(dock.stage_res_table.T_table.rowCount(), 0)


class TestDockWidgetMaterialStream(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.app = QtWidgets.QApplication.instance() or QtWidgets.QApplication([])

    def setUp(self):
        _set_compounds(["Water(chemsep)", "Ethanol(chemsep)"])

    def _create_ms_dock(self):
        container = _make_mock_container()
        ms = MaterialStream()
        ms.name = "MS1"
        for idx, cname in enumerate(compound_selected, start=1):
            ms.variables.setdefault(cname, {"name": cname, "value": 0.5, "unit": ""})
            ms.variables.setdefault(f"Pvap_c[{idx}]", {"name": f"Pvap {cname}", "value": 0.0, "unit": "Pa"})
            for phase in range(1, 4):
                for key in ("x_pc", "xm_pc", "F_pc", "Fm_pc"):
                    ms.variables.setdefault(f"{key}[{phase},{idx}]", {"name": key, "value": 0.5, "unit": "mol/s"})
        container.fetch_object.return_value = ms
        dock = DockWidgetMaterialStream(ms.name, ms.type, ms, container)
        return dock, ms, container

    def test_equalize_normalize_and_param_submit(self):
        dock, ms, container = self._create_ms_dock()
        self.assertEqual(len(dock.x_pclist), 2)

        dock.equalize()
        self.assertAlmostEqual(float(dock.x_pclist[0].text()), 0.5, places=3)
        self.assertAlmostEqual(float(dock.x_pclist[1].text()), 0.5, places=3)

        dock.x_pclist[0].setText("3.0")
        dock.x_pclist[1].setText("1.0")
        dock.normalize()
        self.assertAlmostEqual(float(dock.x_pclist[0].text()), 0.75, places=3)
        self.assertAlmostEqual(float(dock.x_pclist[1].text()), 0.25, places=3)

        dock.x_pclist[0].setText("0")
        dock.x_pclist[1].setText("bad")
        dock.show_error = MagicMock()
        dock.normalize()
        dock.show_error.assert_called()

        dock.x_pclist[0].setText("2.0")
        dock.x_pclist[1].setText("2.0")
        dock.show()
        dock.param()
        self.assertFalse(dock.isVisible())
        self.assertAlmostEqual(float(dock.x_pclist[0].text()), 0.5, places=3)

    def test_results_and_composition_basis_switching(self):
        dock, ms, container = self._create_ms_dock()

        headers = []
        values = []
        for basis_key in ["x_pc", "xm_pc", "F_pc", "Fm_pc"]:
            for phase in range(1, 4):
                for comp in range(1, 3):
                    headers.append(f"MS1.{basis_key}[{phase},{comp}]")
                    values.append(0.25 * comp)

        headers.extend([
            "MS1.P", "MS1.T", "MS1.xvap",
            "MS1.Cp_p[1]", "MS1.H_p[2]", "MS1.S_p[3]",
            "MS1.Pvap_c[1]", "MS1.Pvap_c[2]",
        ])
        values.extend([101325.0, 298.15, 0.0, 75.3, -285800.0, 160.7, 3169.0, 7870.0])

        container.result = [headers, values]
        DockWidgetMaterialStream.show_result([dock])

        self.assertEqual(dock.amountsMixtureTable.columnCount(), 2)
        self.assertEqual(dock.amountsMixtureTable.rowCount(), 2)
        self.assertGreater(dock.mTableWidget.rowCount(), 0)
        self.assertGreater(dock.lTableWidget.rowCount(), 0)
        self.assertGreater(dock.vTableWidget.rowCount(), 0)

        dock.cbCompositionBasis.setCurrentText("Mole Flow")
        self.assertEqual(dock.amountsMixtureTable.columnCount(), 3)
        self.assertEqual(dock.amountsLiquidTable.rowCount(), 2)
        self.assertEqual(dock.amountsVapourTable.rowCount(), 2)

        dock.clear_results()
        self.assertEqual(dock.amountsMixtureTable.rowCount(), 0)
        self.assertEqual(dock.mTableWidget.rowCount(), 0)


class TestDockWidgetSplitter(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.app = QtWidgets.QApplication.instance() or QtWidgets.QApplication([])

    def setUp(self):
        _set_compounds(["Water(chemsep)", "Ethanol(chemsep)"])

    def _create_splitter_with_inlet(self):
        container = _make_mock_container()
        splitter = Splitter()
        splitter.name = "Splitter1"
        dock = DockWidgetSplitter(splitter.name, splitter.type, splitter, container)

        ms_in = MaterialStream()
        ms_in.name = "FeedStream"
        ms_in.variables["F_p[1]"]["value"] = 100.0
        ms_in.variables["Fm_p[1]"]["value"] = 2500.0

        src_node = MagicMock()
        src_node.obj = ms_in
        line_in = MagicMock()
        line_in.source = MagicMock()
        line_in.source.parent = src_node

        in_socket = MagicMock()
        in_socket.in_lines = [line_in]

        out_obj1 = MaterialStream()
        out_obj1.name = "OutStream1"
        out_node1 = MagicMock()
        out_node1.obj = out_obj1
        line_out1 = MagicMock()
        line_out1.target = MagicMock()
        line_out1.target.parent = out_node1

        out_sock1 = MagicMock()
        out_sock1.id = 1
        out_sock1.out_lines = [line_out1]
        out_sock2 = MagicMock()
        out_sock2.id = 2
        out_sock2.out_lines = []

        splitter_node = MagicMock()
        splitter_node.obj = splitter
        splitter_node.input = [in_socket]
        splitter_node.output = [out_sock1, out_sock2]

        container.graphics.graphicsView.items.return_value = [splitter_node]
        return dock, splitter, splitter_node, container

    def test_output_count_change_and_split_ratio_validation(self):
        dock, splitter, splitter_node, container = self._create_splitter_with_inlet()

        dock.no_combo.setCurrentText("4")
        self.assertEqual(len(dock.stream_edits), 4)
        self.assertAlmostEqual(sum(float(e.text()) for e in dock.stream_edits), 1.0, places=5)

        dock.stream_edits[0].setText("0.9")
        with patch.object(QtWidgets.QMessageBox, "warning") as mock_warn:
            dock.param()
            mock_warn.assert_called()

        dock.stream_edits[0].setText("-0.1")
        with patch.object(QtWidgets.QMessageBox, "warning") as mock_warn:
            dock.param()
            mock_warn.assert_called()

        dock.equalize_streams()
        dock.show()
        dock.param()
        self.assertFalse(dock.isVisible())
        splitter_node.update_output_ports.assert_called_with(4)

    def test_molar_and_mass_flow_modes_and_connected_names(self):
        dock, splitter, splitter_node, container = self._create_splitter_with_inlet()

        dock.cb2.setCurrentText("Molar_Flow")
        self.assertEqual(dock.get_stream_unit(), "mol/s")
        dock.auto_distribute_from_input()
        self.assertAlmostEqual(float(dock.stream_edits[0].text()), 50.0, places=4)
        self.assertAlmostEqual(float(dock.stream_edits[1].text()), 50.0, places=4)

        dock.stream_edits[0].setText("30.0")
        dock.stream_edits[1].setText("10.0")
        dock.normalize_streams()
        self.assertAlmostEqual(float(dock.stream_edits[0].text()), 75.0, places=4)
        self.assertAlmostEqual(float(dock.stream_edits[1].text()), 25.0, places=4)

        dock.stream_edits[0].setText("60.0")
        dock.stream_edits[1].setText("60.0")
        with patch.object(QtWidgets.QMessageBox, "warning") as mock_warn:
            dock.param()
            mock_warn.assert_called()

        dock.stream_edits[0].setText("0")
        dock.stream_edits[1].setText("0")
        dock.param()

        dock.cb2.setCurrentText("Mass_Flow")
        self.assertEqual(dock.get_stream_unit(), "g/s")
        dock.equalize_streams()
        self.assertAlmostEqual(float(dock.stream_edits[0].text()), 1250.0, places=4)

        dock.update_connected_component_names()
        self.assertEqual(dock.stream_names[0].text(), "OutStream1")
        self.assertEqual(dock.stream_names[1].text(), "Not Connected")

        container.graphics.graphicsView.items.return_value = []
        with patch.object(QtWidgets.QMessageBox, "warning") as mock_warn:
            dock.equalize_streams()
            mock_warn.assert_called()


class TestDockWidgetCompoundSeparatorMixerFlashCompressorShortcut(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.app = QtWidgets.QApplication.instance() or QtWidgets.QApplication([])

    def setUp(self):
        _set_compounds(["Water(chemsep)", "Ethanol(chemsep)"])

    def test_compound_separator_update_and_param(self):
        container = _make_mock_container()
        cs = CompoundSeparator()
        cs.name = "CS1"
        dock = DockWidgetCompoundSeparator(cs.name, cs.type, cs, container)

        _set_compounds(["Water(chemsep)", "Ethanol(chemsep)", "Methanol(chemsep)"])
        dock.update_compounds()
        self.assertEqual(len(dock.input_dict), 2 + 2 * 3)

        dock.show_error = MagicMock()
        dock.input_dict[3].setText("")
        with patch.object(cs, "param_setter"):
            dock.param()
            dock.show_error.assert_called()

        for idx in (3, 5, 7):
            dock.input_dict[idx].setText("0.5")
        dock.show()
        with patch.object(cs, "param_setter") as mock_setter:
            dock.param()
            mock_setter.assert_called_once()
        self.assertFalse(dock.isVisible())

    def test_mixer_and_flash_params_and_toggles(self):
        container = _make_mock_container()
        mixer = Mixer()
        mixer.name = "Mix1"
        m_dock = DockWidgetMixer(mixer.name, mixer.type, mixer, container)
        m_dock.ni_combo.setCurrentText("4")
        m_dock.show()
        m_dock.param()
        self.assertFalse(m_dock.isVisible())
        self.assertEqual(mixer.variables["NI"]["value"], 4)

        flash = Flash()
        flash.name = "Flash1"
        f_dock = DockWidgetFlash(flash.name, flash.type, flash, container)
        f_dock.check1.setChecked(True)
        self.assertTrue(f_dock.le2.isEnabled())
        f_dock.check1.setChecked(False)
        self.assertFalse(f_dock.le2.isEnabled())
        f_dock.check2.setChecked(True)
        self.assertTrue(f_dock.le3.isEnabled())
        f_dock.check2.setChecked(False)
        self.assertFalse(f_dock.le3.isEnabled())

        f_dock.show()
        f_dock.param()
        self.assertFalse(f_dock.isVisible())

    def test_compressor_and_shortcut_column(self):
        container = _make_mock_container()
        comp = AdiabaticCompressor()
        comp.name = "Comp1"
        container.fetch_object.return_value = comp
        dock = DockWidgetCompressorExpander(comp.name, comp.type, comp, container)

        if dock.comboBox.count() > 1:
            dock.comboBox.setCurrentIndex(1)

        first_le = next(v for k, v in dock.input_dict.items() if isinstance(v, QtWidgets.QLineEdit))
        orig = first_le.text()
        first_le.setText("")
        dock.show_error = MagicMock()
        dock.param()
        dock.show_error.assert_called()

        first_le.setText(orig or "200000")
        dock.show()
        dock.param()
        self.assertFalse(dock.isVisible())

        var_key = next(iter(comp.variables.keys()))
        container.result = [[f"Comp1.{var_key}"], [5400.0]]
        DockWidgetCompressorExpander.show_result([dock])
        self.assertGreater(dock.tableWidget.rowCount(), 0)
        dock.clear_results()
        self.assertEqual(dock.tableWidget.rowCount(), 0)

        sc = ShortcutColumn()
        sc.name = "SC1"
        container.fetch_object.return_value = sc
        sc_dock = DockWidgetShortcutColumn(sc.name, sc.type, sc, container)
        sc.compounds = ["Water(chemsep)", "Ethanol(chemsep)", "Methanol(chemsep)"]
        sc_dock.update_compounds()
        sc_dock.show()
        sc_dock.param()
        self.assertFalse(sc_dock.isVisible())

        headers = [f"SC1.{k}" for k in sc.result_parameters]
        values = [12.0 for _ in sc.result_parameters]
        container.result = [headers, values]
        sc_dock.results_category("SC1")
        self.assertEqual(sc_dock.tableWidget.rowCount(), len(sc.result_parameters))




class TestDockWidgetsEdgeCasesFor90Plus(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        cls.app = QtWidgets.QApplication.instance() or QtWidgets.QApplication([])

    def setUp(self):
        _set_compounds(["Water(chemsep)", "Ethanol(chemsep)"])

    def test_base_and_generic_dock_edge_cases(self):
        container = _make_mock_container()
        heater = Heater()
        heater.name = "HeaterA"
        heater.EngStm1 = MagicMock()
        heater.EngStm2 = MagicMock()
        container.fetch_object.return_value = heater

        dock = DockWidget(heater.name, heater.type, heater, container)

        # showEvent & closeEvent
        dock.show()
        self.app.processEvents()
        dock.close()

        # get_node_item via scene.items()
        scene_node = MagicMock()
        scene_node.obj = heater
        scene_node.dock_widget = None
        container.graphics.scene.items.return_value = [scene_node]
        self.assertIs(dock.get_node_item(), scene_node)

        # check_and_rename_if_needed & EngStm1/EngStm2 propagation
        dock.le_name.setText("HeaterB")
        self.assertTrue(dock.check_and_rename_if_needed())
        self.assertEqual(heater.EngStm1.name, "EngStm1HeaterB")
        self.assertEqual(heater.EngStm2.name, "EngStm2HeaterB")

        # Direct show_error with mocked QMessageBox.about
        with patch("python.DockWidgets.DockWidget.QMessageBox.about") as mock_about:
            BaseDockWidget.show_error(dock)
            mock_about.assert_called_once()

        # Generic DockWidget with no modes_list
        no_mode_obj = MagicMock()
        no_mode_obj.name = "Valve1"
        no_mode_obj.type = "Valve"
        no_mode_obj.modes_list = []
        no_mode_obj.variables = {"Pdrop": {"name": "Pressure Drop", "value": 1000, "unit": "Pa"}}
        no_mode_obj.param_getter.return_value = {"Pdrop": 1000}
        v_dock = DockWidget("Valve1", "Valve", no_mode_obj, container)
        self.assertFalse(v_dock.comboBox.isEnabled())

    def test_material_stream_autosize_update_compounds_and_errors(self):
        container = _make_mock_container()
        ms = MaterialStream()
        ms.name = "MS_Edge"
        for idx, cname in enumerate(compound_selected, start=1):
            ms.variables.setdefault(cname, {"name": cname, "value": 0.5, "unit": ""})
        container.fetch_object.return_value = ms

        mw = QtWidgets.QMainWindow()
        dock = DockWidgetMaterialStream(ms.name, ms.type, ms, container, parent=mw)
        mw.addDockWidget(QtCore.Qt.RightDockWidgetArea, dock)
        dock.show()
        dock._autosize()

        # Empty mole fraction triggers show_error
        dock.x_pclist[0].setText("")
        dock.show_error = MagicMock()
        with patch.object(ms, "param_setter"):
            dock.param()
            dock.show_error.assert_called()

        # update_compounds rebuilds mole fraction fields
        _set_compounds(["Water(chemsep)", "Ethanol(chemsep)", "Methanol(chemsep)"])
        dock.update_compounds()
        self.assertEqual(len(dock.x_pclist), 3)

        # update_input_values & clear_results
        dock.clear_results()
        self.assertEqual(dock.lTableWidget.rowCount(), 0)
        self.assertEqual(dock.vTableWidget.rowCount(), 0)
        mw.close()

    def test_splitter_autosize_and_edge_warnings(self):
        container = _make_mock_container()
        splitter = Splitter()
        splitter.name = "SplitEdge"
        mw = QtWidgets.QMainWindow()
        dock = DockWidgetSplitter(splitter.name, splitter.type, splitter, container, parent=mw)
        mw.addDockWidget(QtCore.Qt.RightDockWidgetArea, dock)
        dock.show()
        dock._autosize()

        # Switch to Molar_Flow, change output count, then back to Split_Ratio
        dock.cb2.setCurrentText("Molar_Flow")
        dock.no_combo.setCurrentText("3")
        dock.cb2.setCurrentText("Split_Ratio")
        self.assertEqual(len(dock.stream_edits), 3)

        # Normalize with zero values warns
        for e in dock.stream_edits:
            e.setText("0")
        with patch.object(QtWidgets.QMessageBox, "warning") as mock_warn:
            dock.normalize_streams()
            mock_warn.assert_called()

        # Normalize in Molar_Flow with missing inlet warns
        dock.cb2.setCurrentText("Molar_Flow")
        dock.stream_edits[0].setText("10")
        with patch.object(QtWidgets.QMessageBox, "warning") as mock_warn:
            dock.normalize_streams()
            mock_warn.assert_called()

        # Empty stream field in param() warns
        dock.stream_edits[0].setText("")
        with patch.object(QtWidgets.QMessageBox, "warning") as mock_warn:
            dock.param()
            mock_warn.assert_called()

        # target_node.parent.obj resolution in update_connected_component_names
        inner_parent = MagicMock()
        inner_parent.obj.name = "NestedStream"
        wrapper_node = MagicMock(spec=["parent"])
        wrapper_node.parent = inner_parent
        line_out = MagicMock()
        line_out.target = MagicMock()
        line_out.target.parent = wrapper_node
        sock = MagicMock()
        sock.id = 1
        sock.out_lines = [line_out]
        sp_node = MagicMock()
        sp_node.obj = splitter
        sp_node.output = [sock]
        container.graphics.graphicsView.items.return_value = [sp_node]
        dock.update_connected_component_names()
        self.assertEqual(dock.stream_names[0].text(), "NestedStream")
        mw.close()

    def test_compressor_no_modes_and_mixer_port_refresh(self):
        container = _make_mock_container()
        no_mode_comp = MagicMock()
        no_mode_comp.name = "CompNoMode"
        no_mode_comp.type = "AdiabaticCompressor"
        no_mode_comp.modes_list = []
        no_mode_comp.variables = {"eff": {"name": "Efficiency", "value": 0.75, "unit": ""}}
        no_mode_comp.param_getter.return_value = {"eff": 0.75}
        c_dock = DockWidgetCompressorExpander("CompNoMode", "AdiabaticCompressor", no_mode_comp, container)
        self.assertFalse(c_dock.comboBox.isEnabled())

        # Mixer updates graphics lst node ports on param()
        import python.utils.Graphics as g_long
        import utils.Graphics as g_short
        mixer = Mixer()
        mixer.name = "MixEdge"
        fake_node = MagicMock()
        fake_node.obj = mixer
        for g_mod in (g_long, g_short):
            if hasattr(g_mod, "lst"):
                g_mod.lst.append(fake_node)
        try:
            m_dock = DockWidgetMixer(mixer.name, mixer.type, mixer, container)
            m_dock.ni_combo.setCurrentText("3")
            m_dock.param()
            fake_node.update_input_ports.assert_called_with(3)
        finally:
            for g_mod in (g_long, g_short):
                if hasattr(g_mod, "lst") and fake_node in g_mod.lst:
                    g_mod.lst.remove(fake_node)



    def test_final_90plus_coverage_branches(self):
        import python.utils.Graphics as g_long
        import utils.Graphics as g_short

        container = _make_mock_container()
        heater = Heater()
        heater.name = "HeaterFinal"
        container.fetch_object.return_value = heater
        dock = DockWidget(heater.name, heater.type, heater, container)

        # 1. get_node_item via Graphics.lst + update_tooltip on rename
        lst_node = MagicMock()
        lst_node.dock_widget = dock
        lst_node.obj = heater
        for g_mod in (g_long, g_short):
            if hasattr(g_mod, "lst"):
                g_mod.lst.append(lst_node)
        try:
            dock.node_item = None
            self.assertIs(dock.get_node_item(), lst_node)
            dock.le_name.setText("HeaterRenamed")
            self.assertTrue(dock.rename_component())
            lst_node.update_tooltip.assert_called()
        finally:
            for g_mod in (g_long, g_short):
                if hasattr(g_mod, "lst") and lst_node in g_mod.lst:
                    g_mod.lst.remove(lst_node)

        # 2. set_read_only covering x_pclist and calculationGroupBox buttons
        cs = CompoundSeparator()
        cs.name = "CSReadOnly"
        cs_dock = DockWidgetCompoundSeparator(cs.name, cs.type, cs, container)
        extra_le = QtWidgets.QLineEdit("0.5")
        cs_dock.x_pclist = [extra_le]
        cs_dock.set_read_only(True)
        self.assertFalse(extra_le.isEnabled())
        cs_dock.set_read_only(False)
        self.assertTrue(extra_le.isEnabled())

        # 3. MaterialStream modes() with empty modes_list
        ms_no_modes = MagicMock()
        ms_no_modes.name = "MSNoModes"
        ms_no_modes.type = "MaterialStream"
        ms_no_modes.modes_list = []
        ms_no_modes.param_getter.return_value = {}
        ms_dock = DockWidgetMaterialStream("MSNoModes", "MaterialStream", ms_no_modes, container)
        self.assertEqual(ms_dock.comboBox.count(), 0)

        # 4. Splitter floating _autosize, empty in_lines, and non-numeric normalize/equalize
        splitter = Splitter()
        splitter.name = "SplitFloat"
        sp_dock = DockWidgetSplitter(splitter.name, splitter.type, splitter, container)
        sp_dock.setFloating(True)
        sp_dock._autosize()

        sp_dock.stream_edits[0].setText("invalid_num")
        sp_dock.normalize_streams()

        # Disconnected input socket in get_input_flow
        in_sock = MagicMock()
        in_sock.in_lines = []
        sp_node = MagicMock()
        sp_node.obj = splitter
        sp_node.input = [in_sock]
        container.graphics.graphicsView.items.return_value = [sp_node]
        self.assertIsNone(sp_dock.get_input_flow("Molar_Flow"))

        # 5. CompressorExpander tooltip update during param()
        comp = AdiabaticCompressor()
        comp.name = "CompTip"
        c_dock = DockWidgetCompressorExpander(comp.name, comp.type, comp, container)
        for v in c_dock.input_dict.values():
            if isinstance(v, QtWidgets.QLineEdit):
                v.setText("100000")
        tip_item = MagicMock()
        tip_item.name = "CompTip"
        container.graphics.graphicsView.items.return_value = [tip_item]
        c_dock.param()
        tip_item.update_tooltip.assert_called()


if __name__ == "__main__":
    unittest.main()
