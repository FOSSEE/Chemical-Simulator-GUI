import os
import sys
import unittest
import tempfile
import shutil
from unittest.mock import patch, MagicMock

# Ensure src/main and src/main/python are in sys.path
PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from python.OMChem.Flowsheet import (
    Flowsheet,
    _normalize_compound_name,
)


class TestNormalizeCompoundName(unittest.TestCase):
    """Test suite for compound name normalization into Modelica identifiers."""

    def test_standard_compound(self):
        self.assertEqual(_normalize_compound_name("Water"), "Water")
        self.assertEqual(_normalize_compound_name("Ethanol"), "Ethanol")
        self.assertEqual(_normalize_compound_name("Methane"), "Methane")

    def test_compound_with_cas_number(self):
        self.assertEqual(_normalize_compound_name("Acetone (67-64-1)"), "Acetone")
        self.assertEqual(_normalize_compound_name("Water (7732-18-5)"), "Water")
        self.assertEqual(_normalize_compound_name("Ethanol (64-17-5)"), "Ethanol")

    def test_numeric_prefix_mapping(self):
        # 1-5 digits must be converted to One-Five words matching ChemSep database
        self.assertEqual(_normalize_compound_name("1-Butanol"), "Onebutanol")
        self.assertEqual(_normalize_compound_name("1,2-Dichloroethane"), "OneTwodichloroethane")
        self.assertEqual(_normalize_compound_name("2-Butanol"), "Twobutanol")
        self.assertEqual(_normalize_compound_name("1-Hexene"), "Onehexene")

    def test_spaces_and_special_characters(self):
        self.assertEqual(_normalize_compound_name("Hydrogen cyanide"), "Hydrogencyanide")
        self.assertEqual(_normalize_compound_name("Carbon dioxide"), "Carbondioxide")
        self.assertEqual(_normalize_compound_name("Nitric oxide"), "Nitricoxide")

    def test_whitespace_handling(self):
        self.assertEqual(_normalize_compound_name("  Water  "), "Water")
        self.assertEqual(_normalize_compound_name("  1-Propanol  "), "Onepropanol")

    def test_fallback_for_non_alpha_start(self):
        # If result does not start with alpha letter, prefix with 'C'
        self.assertTrue(_normalize_compound_name("999xyz")[0].isalpha())


class TestFlowsheetHelperMethods(unittest.TestCase):
    """Test suite for helper methods on Flowsheet class."""

    def setUp(self):
        self.flowsheet = Flowsheet()

    def test_decode_process_output_none_and_empty(self):
        self.assertEqual(self.flowsheet._decode_process_output(None), "")
        self.assertEqual(self.flowsheet._decode_process_output(b""), "")
        self.assertEqual(self.flowsheet._decode_process_output(""), "")

    def test_decode_process_output_valid_bytes(self):
        raw = b"Simulation completed successfully."
        self.assertEqual(self.flowsheet._decode_process_output(raw), "Simulation completed successfully.")

    def test_decode_process_output_invalid_bytes(self):
        # Invalid UTF-8 bytes should not raise UnicodeDecodeError
        invalid_bytes = b"\xff\xfe\xfa not valid utf8"
        decoded = self.flowsheet._decode_process_output(invalid_bytes)
        self.assertIsInstance(decoded, str)

    def test_extract_omc_error_empty(self):
        self.assertEqual(self.flowsheet._extract_omc_error("", ""), "")
        self.assertEqual(self.flowsheet._extract_omc_error("Success", ""), "")

    def test_extract_omc_error_ignores_empty_geterrorstring(self):
        stdout = 'record SimulationResult\n    resultFile = "res.csv",\n    messages = ""\nend SimulationResult;\n'
        self.assertEqual(self.flowsheet._extract_omc_error(stdout, ""), "")

    def test_extract_omc_error_finds_errors(self):
        stderr = "Error: Class Foo not found\nSomething else\n"
        error = self.flowsheet._extract_omc_error("", stderr)
        self.assertIn("Error: Class Foo not found", error)

    def test_extract_omc_error_caps_lines(self):
        many_errors = "\n".join([f"Error line {i}" for i in range(20)])
        extracted = self.flowsheet._extract_omc_error("", many_errors)
        self.assertLessEqual(len(extracted.splitlines()), 6)

    def test_get_omc_path_found(self):
        # On a system with omc installed or mocked
        with patch("shutil.which", return_value="/usr/bin/omc"):
            with patch("os.path.exists", return_value=True):
                path = self.flowsheet.get_omc_path()
                self.assertTrue(path.endswith("omc") or path.endswith("omc.exe"))

    def test_get_omc_path_missing(self):
        with patch("os.path.exists", return_value=False):
            with patch("glob.glob", return_value=[]):
                with self.assertRaises(FileNotFoundError):
                    self.flowsheet.get_omc_path()


class TestFlowsheetSimulationLifecycle(unittest.TestCase):
    """Test suite for Flowsheet unit operations management, code generation, and result extraction."""

    def setUp(self):
        self.temp_dir = tempfile.mkdtemp()
        self.flowsheet = Flowsheet()
        # Direct generated files to temp directory
        self.flowsheet.sim_dir_path = self.temp_dir
        self.flowsheet.Flomo_path = os.path.join(self.temp_dir, 'Flowsheet.mo')
        self.flowsheet.eqn_mos_path = os.path.join(self.temp_dir, 'simulateEQN.mos')

    def tearDown(self):
        shutil.rmtree(self.temp_dir, ignore_errors=True)

    def test_add_and_remove_unit_operations(self):
        mock_unit = MagicMock()
        mock_unit.name = "Mixer1"

        self.flowsheet.add_unit_operations(mock_unit)
        self.assertIn(mock_unit, self.flowsheet.unit_operations)

        self.flowsheet.remove_unit_operations(mock_unit)
        self.assertNotIn(mock_unit, self.flowsheet.unit_operations)

    def test_add_compound_list(self):
        compounds = ["Water", "Ethanol", "1-Butanol"]
        self.flowsheet.add_compound_list(compounds)
        self.assertEqual(self.flowsheet.compounds, compounds)

    def test_simulate_eqn_code_generation(self):
        """Verify that simulate_EQN generates valid Modelica and script files."""
        # Create mock stream and unit operation
        in_stream = MagicMock()
        in_stream.type = "MaterialStream"
        in_stream.name = "MaterialStream1"
        in_stream.OM_Flowsheet_Equation.return_value = "    MaterialStream1.T = 300;\n"

        out_stream = MagicMock()
        out_stream.type = "MaterialStream"
        out_stream.name = "MaterialStream2"
        out_stream.OM_Flowsheet_Equation.return_value = "    MaterialStream2.T = 350;\n"

        mixer = MagicMock()
        mixer.type = "Mixer"
        mixer.name = "Mixer1"
        mixer.output_stms = {"out1": out_stream}
        mixer.OM_Flowsheet_Initialize.return_value = "Simulator.UnitOperations.Mixer Mixer1(Nc = 2);"
        mixer.OM_Flowsheet_Equation.return_value = "    connect(MaterialStream1.Out, Mixer1.In[1]);\n"

        self.flowsheet.add_compound_list(["Water", "Ethanol"])
        self.flowsheet.add_unit_operations(in_stream)
        self.flowsheet.add_unit_operations(mixer)
        self.flowsheet.add_unit_operations(out_stream)

        msg = []
        self.flowsheet.simulate_EQN(msg)

        # Check generated Flowsheet.mo
        self.assertTrue(os.path.exists(self.flowsheet.Flomo_path))
        with open(self.flowsheet.Flomo_path, 'r') as f:
            mo_content = f.read()

        # Validations on generated Modelica code
        self.assertIn("within Simulator;", mo_content)
        self.assertIn("package Flowsheet", mo_content)
        self.assertIn("model FlowsheetSimulation", mo_content)
        self.assertIn("parameter data.Water Water;", mo_content)
        self.assertIn("parameter data.Ethanol Ethanol;", mo_content)
        self.assertIn("parameter Integer Nc = 2;", mo_content)
        self.assertIn("parameter data.GeneralProperties C[Nc] = {Water, Ethanol};", mo_content)
        self.assertIn("ms MaterialStream1(Nc = 2, C = {Water, Ethanol});", mo_content)
        self.assertIn("ms MaterialStream2(Nc = 2, C = {Water, Ethanol});", mo_content)
        self.assertIn("Simulator.UnitOperations.Mixer Mixer1(Nc = 2);", mo_content)
        # Verify property equations for output stream are skipped to prevent overdetermination
        self.assertIn("// Output Stream MaterialStream2 property equations are skipped", mo_content)
        self.assertIn("end FlowsheetSimulation;", mo_content)

        # Check generated simulateEQN.mos
        self.assertTrue(os.path.exists(self.flowsheet.eqn_mos_path))
        with open(self.flowsheet.eqn_mos_path, 'r') as f:
            mos_content = f.read()
        self.assertIn("loadModel(Modelica);", mos_content)
        self.assertIn('loadFile("package.mo");', mos_content)
        self.assertIn('loadFile("Flowsheet.mo");', mos_content)
        self.assertIn("simulate(Simulator.Flowsheet.FlowsheetSimulation", mos_content)

    def test_ext_data_mapping(self):
        """Verify that simulation results from CSV header and last row are correctly parsed into streams."""
        stream = MagicMock()
        stream.type = "MaterialStream"
        stream.name = "MaterialStream1"
        stream.variables = {
            "T": {"name": "Temperature", "value": "0"},
            "P": {"name": "Pressure", "value": "0"},
            "TotalMolarFlow": {"name": "Molar Flow", "value": "0"},
        }

        self.flowsheet.add_unit_operations(stream)

        # Mock result_data as [headers, initial_row, final_row]
        self.flowsheet.result_data = [
            ["time", "MaterialStream1.T", "MaterialStream1.P", "MaterialStream1.TotalMolarFlow"],
            ["0.0", "298.15", "101325", "100"],
            ["1.0", "350.50", "200000", "150"],
        ]

        self.flowsheet.ext_data()

        # The variables should be updated with the values from the final row
        self.assertEqual(stream.variables["T"]["value"], "350.50")
        self.assertEqual(stream.variables["P"]["value"], "200000")
        self.assertEqual(stream.variables["TotalMolarFlow"]["value"], "150")

    def test_ext_data_empty_or_single_row(self):
        """ext_data should safely return when result_data has fewer than 2 rows."""
        self.flowsheet.result_data = []
        self.flowsheet.ext_data()  # Must not raise

        self.flowsheet.result_data = [["time", "T"]]
        self.flowsheet.ext_data()  # Must not raise


if __name__ == "__main__":
    unittest.main()
