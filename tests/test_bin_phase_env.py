import os
import sys
import unittest
from unittest.mock import MagicMock, patch

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from PyQt5.QtWidgets import QApplication
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



if __name__ == '__main__':
    unittest.main()
