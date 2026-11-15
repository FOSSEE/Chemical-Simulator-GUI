import csv
import os
import sys
import unittest
from unittest.mock import MagicMock, patch

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication
from PyQt5.QtCore import QPointF, Qt
app = QApplication.instance() or QApplication([])

from python.utils.Bin_Phase_env import BinPhaseEnv


class MockCompoundContainer:
    def __init__(self, compounds=None):
        self._compounds = compounds if compounds is not None else ["Water", "Ethanol"]

    def get_compounds(self):
        return list(self._compounds)


class TestBinPhaseEnv(unittest.TestCase):
    """Unit tests for Binary Phase Envelope generator UI and plotting mechanics."""

    def setUp(self):
        self.comp = MockCompoundContainer(["Water", "Ethanol", "Acetone"])
        self.widget = BinPhaseEnv(self.comp)

    def tearDown(self):
        self.widget.close()
        self.widget.deleteLater()
        app.processEvents()

    def test_initialization(self):
        """Verify compound comboboxes and thermodynamic package options populate properly."""
        self.assertEqual(self.widget.comboBox.count(), 3)
        self.assertEqual(self.widget.comboBox.itemText(0), "Water")
        self.assertEqual(self.widget.comboBox.itemText(1), "Ethanol")

        # comboBox_2 should have alternative compound options
        self.assertGreaterEqual(self.widget.comboBox_2.count(), 2)

        # Thermo package options (RaoultsLaw, NRTL)
        thermo_items = [self.widget.comboBox_3.itemText(i) for i in range(self.widget.comboBox_3.count())]
        self.assertIn("RaoultsLaw", thermo_items)
        self.assertIn("NRTL", thermo_items)

        # Initial radio buttons should be unchecked
        self.assertFalse(self.widget.radioButton.isChecked())
        self.assertFalse(self.widget.radioButton_2.isChecked())

    def test_t_xy_mode_selection(self):
        """Verify selecting T-xy mode configures pressure input and data points."""
        self.widget.radioButton.click()
        app.processEvents()

        self.assertTrue(self.widget.radioButton.isChecked())
        self.assertFalse(self.widget.radioButton_2.isChecked())
        self.assertEqual(self.widget.type, "P")
        self.assertEqual(self.widget.other, "T")
        self.assertEqual(self.widget.first.text(), "101325")
        self.assertEqual(self.widget.points.text(), "40")

    def test_p_xy_mode_selection(self):
        """Verify selecting P-xy mode configures temperature input and data points."""
        self.widget.radioButton_2.click()
        app.processEvents()

        self.assertTrue(self.widget.radioButton_2.isChecked())
        self.assertFalse(self.widget.radioButton.isChecked())
        self.assertEqual(self.widget.type, "T")
        self.assertEqual(self.widget.other, "P")
        self.assertEqual(self.widget.first.text(), "350")
        self.assertEqual(self.widget.points.text(), "40")

    @patch('python.utils.Bin_Phase_env.QMessageBox.warning')
    def test_plot_requires_mode_selection(self, mock_warning):
        """Verify plot warns if neither T-xy nor P-xy is selected."""
        self.widget.type = None
        self.widget.plot()
        mock_warning.assert_called_once()
        self.assertIn("Selection Required", mock_warning.call_args[0][1])

    @patch('python.utils.Bin_Phase_env.QMessageBox.warning')
    def test_plot_requires_positive_numeric_input(self, mock_warning):
        """Verify plot warns on non-numeric or negative input values."""
        self.widget.T_xy()
        self.widget.first.setText("-100")
        self.widget.plot()
        mock_warning.assert_called_once()
        self.assertIn("Invalid Input", mock_warning.call_args[0][1])

    @patch('python.utils.Bin_Phase_env.QMessageBox.warning')
    def test_plot_requires_at_least_two_data_points(self, mock_warning):
        """Verify plot warns when data points count is less than 2."""
        self.widget.T_xy()
        self.widget.points.setText("1")
        self.widget.plot()
        mock_warning.assert_called_once()
        self.assertIn("Number of data points must be at least 2", mock_warning.call_args[0][2])

    @patch('python.utils.Bin_Phase_env.QMessageBox.warning')
    def test_plot_requires_different_compounds(self, mock_warning):
        """Verify plot rejects when both selected compounds are identical."""
        self.widget.T_xy()
        self.widget.comboBox.setCurrentText("Water")
        self.widget.comboBox_2.setCurrentText("Water")
        self.widget.plot()
        mock_warning.assert_called_once()
        self.assertIn("select two different compounds", mock_warning.call_args[0][2])


    @patch('platform.system')
    @patch('python.utils.Bin_Phase_env.os.path.exists')
    @patch('python.utils.Bin_Phase_env.shutil.which')
    @patch('python.utils.Bin_Phase_env.os.environ.get')
    def test_get_omc_path_resolution(self, mock_env, mock_which, mock_exists, mock_system):
        """Verify OMC path resolution without requiring OpenModelica installation."""
        mock_system.return_value = 'Linux'
        """Verify OMC path resolution without requiring OpenModelica installation."""
        mock_env.return_value = None
        mock_exists.side_effect = lambda path: path == '/usr/bin/omc'
        mock_which.return_value = None

        self.assertEqual(self.widget.get_omc_path(), '/usr/bin/omc')

        mock_which.return_value = '/custom/bin/omc'
        self.assertEqual(self.widget.get_omc_path(), '/custom/bin/omc')

        mock_which.return_value = None
        mock_exists.side_effect = None
        mock_exists.return_value = False

        with self.assertRaises(FileNotFoundError):
            self.widget.get_omc_path()

    @patch('python.utils.Bin_Phase_env.QMessageBox.critical')
    @patch('python.utils.Bin_Phase_env.Popen')
    @patch('python.utils.Bin_Phase_env.BinPhaseEnv.get_omc_path',
           return_value='/mock/omc')
    def test_plot_handles_omc_failure(self, mock_get_omc, mock_popen, mock_critical):
        """Verify error message is displayed when simulation produces no CSV."""
        self.widget.T_xy()
        self.widget.comboBox.setCurrentText("Water")
        self.widget.comboBox_2.setCurrentText("Ethanol")
        self.widget.comboBox_3.setCurrentText("RaoultsLaw")

        mock_proc = MagicMock()
        mock_proc.communicate.return_value = ("Simulation output", "Error: failed")
        mock_popen.return_value = mock_proc

        self.widget.plot()

        mock_get_omc.assert_called_once()
        mock_popen.assert_called_once()
        mock_critical.assert_called_once()
        self.assertIn("Simulation Error", mock_critical.call_args[0][1])

    @patch('python.utils.Bin_Phase_env.BinPhaseEnv.get_omc_path',
           return_value='/mock/omc')
    @patch('python.utils.Bin_Phase_env.Popen')
    def test_successful_simulation_creates_plot_tab(self, mock_popen, mock_get_omc):
        """Verify successful CSV output parses dew/bubble points and adds plot tab."""
        self.widget.T_xy()
        self.widget.comboBox.setCurrentText("Water")
        self.widget.comboBox_2.setCurrentText("Ethanol")
        self.widget.comboBox_3.setCurrentText("RaoultsLaw")
        self.widget.points.setText("2")

        headers = ["time", '"x[1,1]"', '"y[1,1]"', '"T[1]"',
                   '"x[2,1]"', '"y[2,1]"', '"T[2]"']
        row1 = ["0.0", "0.1", "0.2", "370.0", "0.5", "0.6", "365.0"]
        row2 = ["1.0", "0.15", "0.25", "371.0", "0.55", "0.65", "366.0"]

        def fake_popen(*args, **kwargs):
            import csv
            with open("Simulator.Graph_res.csv", "w", newline="") as f:
                writer = csv.writer(f)
                writer.writerow(headers)
                writer.writerow(row1)
                writer.writerow(row2)

            m = MagicMock()
            m.communicate.return_value = ("Success", "")
            return m

        mock_popen.side_effect = fake_popen

        initial_tabs = self.widget.tabWidget.count()
        self.widget.plot()

        mock_get_omc.assert_called_once()
        mock_popen.assert_called_once()
        self.assertEqual(self.widget.tabWidget.count(), initial_tabs + 1)
        self.assertEqual(len(self.widget.datay), 2)
        self.assertEqual(len(self.widget.datax1), 2)
        self.assertEqual(len(self.widget.datax2), 2)


class TestBinPhaseEnvEdgeCases(unittest.TestCase):
    """Error paths, OMC lookup and plot interaction handlers of BinPhaseEnv."""

    HEADERS = ["time", '"x[1,1]"', '"y[1,1]"', '"T[1]"', '"x[2,1]"', '"y[2,1]"', '"T[2]"']
    GOOD_ROW = ["1.0", "0.15", "0.25", "371.0", "0.55", "0.65", "366.0"]

    def setUp(self):
        self.widget = BinPhaseEnv(MockCompoundContainer(["Water", "Ethanol", "Acetone"]))

    def tearDown(self):
        self.widget.close()
        self.widget.deleteLater()
        app.processEvents()
        while QApplication.overrideCursor() is not None:
            QApplication.restoreOverrideCursor()

    def ready_to_plot(self, points="2"):
        self.widget.T_xy()
        self.widget.comboBox.setCurrentText("Water")
        self.widget.comboBox_2.setCurrentText("Ethanol")
        self.widget.comboBox_3.setCurrentText("RaoultsLaw")
        self.widget.points.setText(points)

    def popen_writing_csv(self, rows, headers=None):
        """A fake Popen that writes the results CSV the way omc would."""
        headers = headers or self.HEADERS

        def fake_popen(*args, **kwargs):
            path = os.path.join(self.widget.sim_dir_path, "Simulator.Graph_res.csv")
            with open(path, "w", newline="") as f:
                writer = csv.writer(f)
                writer.writerow(headers)
                writer.writerows(rows)
            proc = MagicMock()
            proc.communicate.return_value = ("", "")
            return proc
        return fake_popen

    def plot_successfully(self):
        self.ready_to_plot()
        with patch.object(BinPhaseEnv, "get_omc_path", return_value="/mock/omc"), \
                patch("python.utils.Bin_Phase_env.Popen", side_effect=self.popen_writing_csv([self.GOOD_ROW])):
            self.widget.plot()
        return self.widget.new_tab

    # ----------------- construction / mode switching -----------------

    def test_thermo_packages_fall_back_when_file_missing(self):
        with patch("builtins.open", side_effect=FileNotFoundError):
            widget = BinPhaseEnv(MockCompoundContainer())
        try:
            items = [widget.comboBox_3.itemText(i) for i in range(widget.comboBox_3.count())]
            self.assertEqual(items, ["RaoultsLaw", "NRTL"])
        finally:
            widget.deleteLater()

    def test_no_compounds_leaves_comboboxes_empty(self):
        widget = BinPhaseEnv(MockCompoundContainer([]))
        try:
            self.assertEqual(widget.comboBox.count(), 0)
            self.assertEqual(widget.comboBox_2.count(), 0)
        finally:
            widget.deleteLater()

    def test_second_compound_list_starts_with_the_next_compound(self):
        items = [self.widget.comboBox_2.itemText(i) for i in range(self.widget.comboBox_2.count())]
        self.assertEqual(items, ["Ethanol", "Acetone", "Water"])

    def test_switching_modes_replaces_input_rows(self):
        self.widget.T_xy()
        old_input = self.widget.first
        self.widget.P_xy()
        app.processEvents()
        self.assertEqual(self.widget.first.text(), "350")
        self.assertEqual(self.widget.type, "T")
        # The T-xy input was detached from the form
        self.assertIsNone(old_input.parent())

        old_input = self.widget.first
        self.widget.T_xy()
        app.processEvents()
        self.assertEqual(self.widget.first.text(), "101325")
        self.assertEqual(self.widget.type, "P")
        self.assertIsNone(old_input.parent())

    def test_radio_buttons_are_mutually_exclusive(self):
        self.widget.T_xy()
        self.widget.P_xy()
        self.assertTrue(self.widget.radioButton_2.isChecked())
        self.assertFalse(self.widget.radioButton.isChecked())

    # ----------------- get_omc_path -----------------

    def test_omc_from_openmodelicahome(self):
        home = os.path.join("om", "home")
        omc = os.path.join(home, "bin", "omc")
        with patch.dict(os.environ, {"OPENMODELICAHOME": home}), \
                patch("python.utils.Bin_Phase_env.os.path.exists", side_effect=lambda p: p == omc):
            self.assertEqual(self.widget.get_omc_path(), omc)

    def test_omc_exe_from_openmodelicahome(self):
        home = os.path.join("om", "home")
        omc_exe = os.path.join(home, "bin", "omc.exe")
        with patch.dict(os.environ, {"OPENMODELICAHOME": home}), \
                patch("python.utils.Bin_Phase_env.os.path.exists", side_effect=lambda p: p == omc_exe):
            self.assertEqual(self.widget.get_omc_path(), omc_exe)

    def test_omc_found_by_glob_on_windows(self):
        found = [r"C:\Program Files\OpenModelica1.24.0-64bit\bin\omc.exe",
                 r"C:\Program Files\OpenModelica1.26.3-64bit\bin\omc.exe"]
        with patch.dict(os.environ, {}, clear=True), \
                patch("python.utils.Bin_Phase_env.shutil.which", return_value=None), \
                patch("platform.system", return_value="Windows"), \
                patch("glob.glob", return_value=found):
            # Newest version wins
            self.assertEqual(self.widget.get_omc_path(), found[1])

    def test_omc_default_windows_path(self):
        default = r"C:\Program Files\OpenModelica1.26.3-64bit\bin\omc.exe"
        with patch.dict(os.environ, {}, clear=True), \
                patch("python.utils.Bin_Phase_env.shutil.which", return_value=None), \
                patch("platform.system", return_value="Windows"), \
                patch("glob.glob", return_value=[]), \
                patch("python.utils.Bin_Phase_env.os.path.exists", side_effect=lambda p: p == default):
            self.assertEqual(self.widget.get_omc_path(), default)

    def test_omc_not_found_on_windows_raises(self):
        with patch.dict(os.environ, {}, clear=True), \
                patch("python.utils.Bin_Phase_env.shutil.which", return_value=None), \
                patch("platform.system", return_value="Windows"), \
                patch("glob.glob", return_value=[]), \
                patch("python.utils.Bin_Phase_env.os.path.exists", return_value=False):
            with self.assertRaises(FileNotFoundError):
                self.widget.get_omc_path()

    def test_omc_in_opt_local_on_linux(self):
        with patch.dict(os.environ, {}, clear=True), \
                patch("python.utils.Bin_Phase_env.shutil.which", return_value=None), \
                patch("platform.system", return_value="Linux"), \
                patch("python.utils.Bin_Phase_env.os.path.exists", side_effect=lambda p: p == "/opt/local/bin/omc"):
            self.assertEqual(self.widget.get_omc_path(), "/opt/local/bin/omc")

    # ----------------- _cleanup_simulation_files -----------------

    def test_cleanup_ignores_files_that_cannot_be_removed(self):
        self.widget.sim_dir_path = "sim"
        with patch("glob.glob", return_value=["sim/Graph.mo"]), \
                patch("python.utils.Bin_Phase_env.os.remove", side_effect=OSError("locked")) as mock_remove:
            self.widget._cleanup_simulation_files()
        self.assertEqual(mock_remove.call_count, 3)  # one file per pattern

    def test_cleanup_swallows_unexpected_errors(self):
        # sim_dir_path not set yet -> AttributeError inside the try
        self.assertFalse(hasattr(self.widget, "sim_dir_path"))
        self.widget._cleanup_simulation_files()

    # ----------------- plot(): input validation -----------------

    @patch("python.utils.Bin_Phase_env.QMessageBox.warning")
    def test_plot_without_selecting_mode(self, mock_warning):
        self.widget.plot()
        self.assertEqual(mock_warning.call_args[0][1], "Selection Required")

    @patch("python.utils.Bin_Phase_env.QMessageBox.warning")
    def test_plot_rejects_non_numeric_value(self, mock_warning):
        self.widget.T_xy()
        self.widget.first.setText("abc")
        self.widget.plot()
        self.assertEqual(mock_warning.call_args[0][1], "Invalid Input")
        self.assertIn("valid numeric value for P", mock_warning.call_args[0][2])

    @patch("python.utils.Bin_Phase_env.QMessageBox.warning")
    def test_plot_rejects_zero(self, mock_warning):
        self.widget.P_xy()
        self.widget.first.setText("0")
        self.widget.plot()
        self.assertIn("T must be greater than zero", mock_warning.call_args[0][2])

    @patch("python.utils.Bin_Phase_env.QMessageBox.warning")
    def test_invalid_point_count_defaults_to_40(self, mock_warning):
        self.widget.T_xy()
        self.widget.points.setText("lots")
        # Stop right after the point count is parsed, at the compound check
        self.widget.comboBox.setCurrentText("Water")
        self.widget.comboBox_2.setCurrentText("Water")
        self.widget.plot()
        self.assertNotIn("at least 2", mock_warning.call_args[0][2])
        self.assertIn("two different compounds", mock_warning.call_args[0][2])

    @patch("python.utils.Bin_Phase_env.QMessageBox.warning")
    def test_plot_requires_two_compounds(self, mock_warning):
        widget = BinPhaseEnv(MockCompoundContainer([]))
        try:
            widget.T_xy()
            widget.plot()
            self.assertEqual(mock_warning.call_args[0][2], "Please select two compounds.")
        finally:
            widget.deleteLater()

    @patch("python.utils.Bin_Phase_env.QMessageBox.warning")
    def test_plot_rejects_names_that_normalize_to_same_compound(self, mock_warning):
        self.widget.T_xy()
        self.widget.comboBox_2.addItem("water")
        self.widget.comboBox.setCurrentText("Water")
        self.widget.comboBox_2.setCurrentText("water")
        with patch("python.utils.Bin_Phase_env._normalize_compound_name", return_value="Water"):
            self.widget.plot()
        self.assertIn("two different compounds", mock_warning.call_args[0][2])

    @patch("python.utils.Bin_Phase_env.QMessageBox.warning")
    def test_plot_requires_thermo_package(self, mock_warning):
        self.ready_to_plot()
        self.widget.comboBox_3.clear()
        self.widget.plot()
        self.assertEqual(mock_warning.call_args[0][2], "Please select a thermodynamic package.")

    # ----------------- plot(): running OpenModelica -----------------

    @patch("python.utils.Bin_Phase_env.QMessageBox.critical")
    def test_plot_writes_model_and_script(self, mock_critical):
        self.ready_to_plot(points="5")
        written = {}

        def capture(*args, **kwargs):
            for name in ("Graph.mo", "PlotGraph.mos"):
                with open(os.path.join(self.widget.sim_dir_path, name)) as f:
                    written[name] = f.read()
            proc = MagicMock()
            proc.communicate.return_value = ("", "")
            return proc

        with patch.object(BinPhaseEnv, "get_omc_path", return_value="/mock/omc"), \
                patch("python.utils.Bin_Phase_env.Popen", side_effect=capture) as mock_popen:
            self.widget.plot()

        self.assertIn("parameter data.Water comp1;", written["Graph.mo"])
        self.assertIn("parameter data.Ethanol comp2;", written["Graph.mo"])
        self.assertIn("BinaryEnvelopes.RaoultsLaw(Nc = 2, data_points = 5", written["Graph.mo"])
        self.assertIn("P = fill(101325.0, 5)", written["Graph.mo"])
        self.assertIn('simulate(Simulator.Graph, outputFormat="csv"', written["PlotGraph.mos"])
        self.assertEqual(mock_popen.call_args[0][0], ["/mock/omc", "-s", "PlotGraph.mos"])
        # Temporary files are removed afterwards
        self.assertFalse(os.path.exists(self.widget.Graphmo_path))
        self.assertFalse(os.path.exists(self.widget.plot_mos_path))

    @patch("python.utils.Bin_Phase_env.QMessageBox.critical")
    def test_plot_reports_missing_omc(self, mock_critical):
        self.ready_to_plot()
        with patch.object(BinPhaseEnv, "get_omc_path", side_effect=FileNotFoundError("omc missing")), \
                patch("python.utils.Bin_Phase_env.Popen") as mock_popen:
            self.widget.plot()

        mock_popen.assert_not_called()
        self.assertEqual(mock_critical.call_args[0][1:], ("OMC Not Found", "omc missing"))
        self.assertFalse(os.path.exists(self.widget.Graphmo_path))

    @patch("python.utils.Bin_Phase_env.QMessageBox.critical")
    def test_plot_reports_omc_launch_failure_and_restores_cwd(self, mock_critical):
        self.ready_to_plot()
        cwd = os.getcwd()
        with patch.object(BinPhaseEnv, "get_omc_path", return_value="/mock/omc"), \
                patch("python.utils.Bin_Phase_env.Popen", side_effect=OSError("cannot run")):
            self.widget.plot()

        self.assertEqual(os.getcwd(), cwd)
        self.assertEqual(mock_critical.call_args[0][1], "Execution Error")
        self.assertIn("cannot run", mock_critical.call_args[0][2])

    @patch("python.utils.Bin_Phase_env.QMessageBox.critical")
    def test_simulation_error_summary_lists_error_lines(self, mock_critical):
        self.ready_to_plot()
        proc = MagicMock()
        proc.communicate.return_value = ("ok line\nError: model failed", "Translation failed")
        with patch.object(BinPhaseEnv, "get_omc_path", return_value="/mock/omc"), \
                patch("python.utils.Bin_Phase_env.Popen", return_value=proc):
            self.widget.plot()

        details = mock_critical.call_args[0][2]
        self.assertIn("Error: model failed", details)
        self.assertIn("Translation failed", details)
        self.assertNotIn("ok line", details)

    @patch("python.utils.Bin_Phase_env.QMessageBox.warning")
    def test_empty_results_file_warns(self, mock_warning):
        self.ready_to_plot()
        with patch.object(BinPhaseEnv, "get_omc_path", return_value="/mock/omc"), \
                patch("python.utils.Bin_Phase_env.Popen", side_effect=self.popen_writing_csv([])):
            self.widget.plot()

        self.assertEqual(mock_warning.call_args[0][1], "Simulation Warning")
        self.assertEqual(self.widget.tabWidget.count(), 0)
        self.assertFalse(os.path.exists(os.path.join(self.widget.sim_dir_path, "Simulator.Graph_res.csv")))

    @patch("python.utils.Bin_Phase_env.QMessageBox.warning")
    def test_results_without_expected_columns_warn(self, mock_warning):
        self.ready_to_plot()
        with patch.object(BinPhaseEnv, "get_omc_path", return_value="/mock/omc"), \
                patch("python.utils.Bin_Phase_env.Popen",
                      side_effect=self.popen_writing_csv([["1.0", "2.0"]], headers=["time", "other"])):
            self.widget.plot()

        self.assertEqual(mock_warning.call_args[0][1], "Plot Error")
        self.assertEqual(self.widget.tabWidget.count(), 0)

    def test_unparseable_values_are_skipped(self):
        self.ready_to_plot()
        row = ["1.0", "0.15", "0.25", "371.0", "bad", "0.65", "366.0"]
        with patch.object(BinPhaseEnv, "get_omc_path", return_value="/mock/omc"), \
                patch("python.utils.Bin_Phase_env.Popen", side_effect=self.popen_writing_csv([row])):
            self.widget.plot()

        self.assertEqual(self.widget.datax1, [0.15])
        self.assertEqual(self.widget.datay, [371.0])

    def test_successful_plots_get_numbered_tabs(self):
        self.plot_successfully()
        self.plot_successfully()

        self.assertEqual(self.widget.tabWidget.count(), 2)
        self.assertEqual(self.widget.tabWidget.tabText(0), "Plot 1")
        self.assertEqual(self.widget.tabWidget.tabText(1), "Plot 2")
        self.assertEqual(self.widget.counter, 3)

    def test_plot_axis_labels(self):
        plot = self.plot_successfully()
        self.assertEqual(plot.plotItem.getAxis("left").labelText, "T(K)")
        self.assertEqual(plot.plotItem.getAxis("bottom").labelText, "Water(mol. frac.)")

    # ----------------- plot mouse handlers -----------------

    def screen_with_pixel(self, rgb):
        image = MagicMock()
        image.pixel.return_value = rgb
        screen = MagicMock()
        screen.grabWindow.return_value.toImage.return_value = image
        return screen

    def test_mouse_over_curve_shows_coordinates(self):
        plot = self.plot_successfully()
        gui = MagicMock()
        gui.primaryScreen.return_value = self.screen_with_pixel(0xFFFF0000)  # red curve pixel
        with patch("python.utils.Bin_Phase_env.QGuiApplication", gui):
            plot.scene().sigMouseMoved.emit(QPointF(50, 50))

        self.assertNotEqual(self.widget.lineEdit_x.text(), "")
        self.assertNotEqual(self.widget.lineEdit_y.text(), "")
        self.assertEqual(self.widget.tool_tip,
                         f"{self.widget.lineEdit_x.text()}, {self.widget.lineEdit_y.text()}")
        self.assertEqual(QApplication.overrideCursor().shape(), Qt.CrossCursor)

    def test_mouse_off_curve_clears_coordinates(self):
        plot = self.plot_successfully()
        self.widget.lineEdit_x.setText("1")
        self.widget.lineEdit_y.setText("2")
        gui = MagicMock()
        gui.primaryScreen.return_value = self.screen_with_pixel(0xFF00FF00)  # green background
        with patch("python.utils.Bin_Phase_env.QGuiApplication", gui):
            plot.scene().sigMouseMoved.emit(QPointF(50, 50))

        self.assertEqual(self.widget.lineEdit_x.text(), "")
        self.assertEqual(self.widget.lineEdit_y.text(), "")
        self.assertEqual(self.widget.tool_tip, "")
        self.assertEqual(QApplication.overrideCursor().shape(), Qt.ArrowCursor)

    def test_hovering_items_sets_tooltip_and_legend_clears(self):
        plot = self.plot_successfully()
        self.widget.tool_tip = "0.5, 370.0"
        self.widget.lineEdit_x.setText("0.5")

        LegendItem = type("LegendItem", (), {})
        curve = MagicMock()
        plot.scene().sigMouseHover.emit([curve, LegendItem()])

        curve.setToolTip.assert_called_once_with("0.5, 370.0")
        self.assertEqual(self.widget.lineEdit_x.text(), "")
        self.assertEqual(QApplication.overrideCursor().shape(), Qt.ArrowCursor)


if __name__ == '__main__':
    unittest.main()
