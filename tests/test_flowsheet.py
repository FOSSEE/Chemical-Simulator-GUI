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

    def test_extract_omc_error_detail_line_with_empty_geterrorstring(self):
        combined = "Error: Some compilation error\ngetErrorString() \"\"\nNext line error"
        error = self.flowsheet._extract_omc_error("", combined)
        self.assertIn("Error: Some compilation error", error)
        self.assertNotIn('getErrorString() ""', error)

    def test_decode_process_output_exception(self):
        # When .decode() raises an exception, _decode_process_output should fallback to str(output)
        bad_obj = MagicMock()
        bad_obj.decode.side_effect = RuntimeError("decode exploded")
        bad_obj.__str__.return_value = "fallback_string"
        decoded = self.flowsheet._decode_process_output(bad_obj)
        self.assertEqual(decoded, "fallback_string")

    def test_init_creates_sim_dir_path_if_missing(self):
        with patch("os.path.exists", return_value=False):
            with patch("os.makedirs") as mock_makedirs:
                fs = Flowsheet()
                mock_makedirs.assert_called_once()

    def test_get_omc_path_windows_candidates(self):
        with patch("platform.system", return_value="Windows"):
            with patch("glob.glob", return_value=[r"C:\Program Files\OpenModelica1.26.3-64bit\bin\omc.exe"]):
                with patch("os.path.exists", return_value=True):
                    path = self.flowsheet.get_omc_path()
                    self.assertIn("OpenModelica", path)

    def test_get_omc_path_windows_fallback(self):
        with patch("platform.system", return_value="Windows"):
            with patch("glob.glob", return_value=[]):
                with patch("os.path.exists", return_value=True):
                    path = self.flowsheet.get_omc_path()
                    self.assertIn("OpenModelica1.26.3-64bit", path)

    def test_get_omc_path_missing_with_msg(self):
        with patch("os.path.exists", return_value=False):
            with patch("glob.glob", return_value=[]):
                msg = ["Simulation started"]
                with self.assertRaises(FileNotFoundError):
                    self.flowsheet.get_omc_path(msg=msg)
                self.assertTrue(len(msg) > 1)
                self.assertIn("OMC not found", msg[1])


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
        self.flowsheet.send_for_simulation_Eqn = MagicMock()

        self.flowsheet.simulate_EQN(msg)

        self.flowsheet.send_for_simulation_Eqn.assert_called_once_with(msg)

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

    def test_ext_data_index_or_key_error(self):
        """ext_data should catch IndexError or KeyError without raising."""
        stream = MagicMock()
        stream.type = "MaterialStream"
        stream.name = "Stream1"
        stream.variables = {"T": {"value": "0"}}
        self.flowsheet.add_unit_operations(stream)

        # Header has Stream1.T at index 1, but data row has length 1 (IndexError)
        self.flowsheet.result_data = [
            ["time", "Stream1.T"],
            ["0.0"]
        ]
        self.flowsheet.ext_data()
        self.assertEqual(stream.variables["T"]["value"], "0")

    def test_simulate_eqn_package_order_and_stray_cleanup(self):
        """Verify simulate_EQN updates package.order and removes stray .mo files."""
        # Create package.order missing Flowsheet
        order_path = os.path.join(self.temp_dir, 'package.order')
        with open(order_path, 'w') as f:
            f.write("SomeExistingModel\n")

        # Create stray .mo file
        stray_path = os.path.join(self.temp_dir, 'stray_model.mo')
        with open(stray_path, 'w') as f:
            f.write("model stray_model end stray_model;")

        self.assertTrue(os.path.exists(stray_path))

        with patch.object(self.flowsheet, "send_for_simulation_Eqn"):
            self.flowsheet.simulate_EQN(msg=[])

        # Verify Flowsheet was appended to package.order
        with open(order_path, 'r') as f:
            order_content = f.read()
        self.assertIn("Flowsheet", order_content)
        self.assertIn("SomeExistingModel", order_content)

        # Verify stray .mo file was removed
        self.assertFalse(os.path.exists(stray_path))

    def test_send_for_simulation_eqn_success(self):
        """Verify send_for_simulation_Eqn runs process and loads CSV results."""
        self.flowsheet.sim_method = 'Eqn'
        csv_path = os.path.join(self.temp_dir, 'Simulator.Flowsheet.FlowsheetSimulation_res.csv')
        # Pre-create csv_path to exercise cleanup at start of send_for_simulation_Eqn
        with open(csv_path, 'w') as f:
            f.write("old data\n")

        mock_proc = MagicMock()
        mock_proc.communicate.return_value = (b"record SimulationResult\n timeSimulation = 1.0\nend SimulationResult;", b"")

        # Mock Popen writing the CSV
        def fake_communicate():
            with open(csv_path, 'w') as f:
                f.write("time,MaterialStream1.T\n0.0,300\n1.0,350\n")
            return (b"record SimulationResult\n timeSimulation = 1.0\nend SimulationResult;", b"")

        mock_proc.communicate.side_effect = fake_communicate

        with patch.object(self.flowsheet, "get_omc_path", return_value="/mock/omc"):
            with patch("python.OMChem.Flowsheet.Popen", return_value=mock_proc):
                stream = MagicMock()
                stream.type = "MaterialStream"
                stream.name = "MaterialStream1"
                stream.variables = {"T": {"value": "0"}}
                self.flowsheet.add_unit_operations(stream)

                self.flowsheet.send_for_simulation_Eqn([])

        self.assertEqual(len(self.flowsheet.result_data), 3)
        self.assertEqual(stream.variables["T"]["value"], "350")
        self.assertEqual(self.flowsheet.last_error, "")

    def test_send_for_simulation_eqn_windows_startupinfo(self):
        """Verify Windows branch in send_for_simulation_Eqn configures STARTUPINFO."""
        self.flowsheet.sim_method = 'Eqn'
        mock_proc = MagicMock()
        mock_proc.communicate.return_value = (b"Simulation done", b"")

        mock_startupinfo_cls = MagicMock()
        with patch("platform.system", return_value="Windows"):
            with patch("subprocess.STARTUPINFO", mock_startupinfo_cls, create=True):
                with patch("subprocess.STARTF_USESHOWWINDOW", 1, create=True):
                    with patch.object(self.flowsheet, "get_omc_path", return_value="C:\\omc.exe"):
                        with patch("python.OMChem.Flowsheet.Popen", return_value=mock_proc) as mock_popen:
                            self.flowsheet.send_for_simulation_Eqn([])
                            mock_popen.assert_called_once()
                            _, kwargs = mock_popen.call_args
                            self.assertIn("startupinfo", kwargs)

    def test_send_for_simulation_eqn_failure(self):
        """Verify send_for_simulation_Eqn sets last_error on simulation error or missing CSV."""
        self.flowsheet.sim_method = 'Eqn'
        mock_proc = MagicMock()
        mock_proc.communicate.return_value = (b"timeSimulation = 0.0,\nError: Model is overdetermined", b"")

        with patch.object(self.flowsheet, "get_omc_path", return_value="/mock/omc"):
            with patch("python.OMChem.Flowsheet.Popen", return_value=mock_proc):
                self.flowsheet.send_for_simulation_Eqn([])

        self.assertEqual(self.flowsheet.result_data, [])
        self.assertIn("Error: Model is overdetermined", self.flowsheet.last_error)

    def test_send_for_simulation_sm_success(self):
        """Verify send_for_simulation_SM executes unit and reads its CSV."""
        mock_unit = MagicMock()
        mock_unit.name = "Mixer1"

        csv_path = os.path.join(self.temp_dir, 'Mixer1_res.csv')
        mock_proc = MagicMock()
        def fake_communicate():
            with open(csv_path, 'w') as f:
                f.write("time,Stream1.T\n0.0,300\n1.0,320\n")
            return (b"Mixer simulation success", b"")

        mock_proc.communicate.side_effect = fake_communicate

        with patch.object(self.flowsheet, "get_omc_path", return_value="/mock/omc"):
            with patch("python.OMChem.Flowsheet.Popen", return_value=mock_proc):
                self.flowsheet.send_for_simulation_SM(mock_unit)

        self.assertEqual(len(self.flowsheet.result_data), 3)

    def test_send_for_simulation_sm_missing_csv(self):
        """Verify send_for_simulation_SM extracts error when CSV is missing."""
        mock_unit = MagicMock()
        mock_unit.name = "Mixer1"
        mock_proc = MagicMock()
        mock_proc.communicate.return_value = (b"Error: Failed to simulate Mixer1", b"")

        with patch.object(self.flowsheet, "get_omc_path", return_value="/mock/omc"):
            with patch("python.OMChem.Flowsheet.Popen", return_value=mock_proc):
                self.flowsheet.send_for_simulation_SM(mock_unit)

        self.assertIn("Error: Failed to simulate Mixer1", self.flowsheet.last_error)

    def test_simulate_sm_complete_lifecycle(self):
        """Verify simulate_SM correctly sorts units, writes files, transfers stream properties, and combines CSVs."""
        self.flowsheet.add_compound_list(["Water", "Ethanol"])

        # Streams
        s1 = MagicMock()
        s1.type = "MaterialStream"
        s1.name = "Stream1"
        s1.Prop = {"T": "300"}
        s1.OM_Flowsheet_Initialize.return_value = "ms Stream1(Nc = 2);"
        s1.OM_Flowsheet_Equation.return_value = "Stream1.T = 300;"

        s2 = MagicMock()
        s2.type = "MaterialStream"
        s2.name = "Stream2"
        s2.Prop = {"T": "310"}
        s2.OM_Flowsheet_Initialize.return_value = "ms Stream2(Nc = 2);"
        s2.OM_Flowsheet_Equation.return_value = "Stream2.T = 310;"

        s3 = MagicMock()
        s3.type = "MaterialStream"
        s3.name = "Stream3"
        s3.Prop = {"T": "0"}
        s3.OM_Flowsheet_Initialize.return_value = "ms Stream3(Nc = 2);"
        s3.OM_Flowsheet_Equation.return_value = "Stream3.T = 0;"

        s4 = MagicMock()
        s4.type = "MaterialStream"
        s4.name = "Stream4"
        s4.Prop = {"T": "0"}
        s4.OM_Flowsheet_Initialize.return_value = "ms Stream4(Nc = 2);"
        s4.OM_Flowsheet_Equation.return_value = "Stream4.T = 0;"

        e1 = MagicMock()
        e1.type = "EngStm"
        e1.name = "EngStm1"
        e1.OM_Flowsheet_Initialize.return_value = "Simulator.Streams.Energy_Stream EngStm1;"

        # Unit 1: Mixer (input dict, output list, eng None)
        mixer = MagicMock()
        mixer.type = "Mixer"
        mixer.name = "Mixer1"
        mixer.input_stms = {"in1": s1, "in2": s2}
        mixer.output_stms = [s3]
        mixer.EngStms = None
        mixer.OM_Flowsheet_Initialize.return_value = "Simulator.UnitOperations.Mixer Mixer1(Nc = 2);"
        mixer.OM_Flowsheet_Equation.return_value = "connect(Stream1.Out, Mixer1.In[1]);"

        # Unit 2: Heater (single input not list/dict, output list, eng stm)
        heater = MagicMock()
        heater.type = "Heater"
        heater.name = "Heater1"
        heater.input_stms = s3
        heater.output_stms = [s4]
        heater.EngStms = e1
        heater.OM_Flowsheet_Initialize.return_value = "Simulator.Unit_Operations.Heater Heater1(Nc = 2);"
        heater.OM_Flowsheet_Equation.return_value = "connect(Stream3.Out, Heater1.In);"

        # Add all to flowsheet, including streams to test unit filtering
        self.flowsheet.add_unit_operations(mixer)
        self.flowsheet.add_unit_operations(heater)
        self.flowsheet.add_unit_operations(s1)
        self.flowsheet.add_unit_operations(e1)

        # ip / op structured to exercise all 4 topological sorting branches:
        # Branch 1: neither in self.unit -> appends k then i (Mixer1, Heater1)
        # Branch 2: i in self.unit -> inserts k before i (Mixer0 inserted before Mixer1)
        # Branch 3: k in self.unit -> appends i (Cooler1 appended after Heater1)
        # Branch 4: both i and k in self.unit -> pass
        ip = {
            "Heater1": ["Stream3"],
            "Mixer1": ["Stream0"],
            "Cooler1": ["Stream4"],
            "PassUnit": ["Stream3"],
        }
        op = {
            "Mixer1": ["Stream3"],
            "Mixer0": ["Stream0"],
            "Heater1": ["Stream4"],
            "Heater0": ["Stream3"],
        }

        # Extra stream without Prop to exercise line 514
        s_no_prop = MagicMock()
        s_no_prop.type = "MaterialStream"
        s_no_prop.name = "StreamNoProp"
        s_no_prop.Prop = None
        s_no_prop.OM_Flowsheet_Initialize.return_value = "ms StreamNoProp(Nc = 2);"
        s_no_prop.OM_Flowsheet_Equation.return_value = "StreamNoProp.T = 300;"

        # Extra unit without type / MaterialStream to exercise line 421
        unit_stm = MagicMock()
        unit_stm.type = "MaterialStream"
        unit_stm.name = "Mixer0"

        # Unit 0 (Mixer0)
        mixer0 = MagicMock()
        mixer0.type = "MaterialStream"  # Intentionally MaterialStream to trigger line 421 continue
        mixer0.name = "Mixer0"

        # PassUnit
        pass_unit = MagicMock()
        pass_unit.type = "EngStm"  # Intentionally EngStm to trigger line 421 continue
        pass_unit.name = "PassUnit"

        cooler = MagicMock()
        cooler.type = "Cooler"
        cooler.name = "Cooler1"
        cooler.input_stms = [s4, s_no_prop]
        cooler.output_stms = []
        cooler.EngStms = None
        cooler.OM_Flowsheet_Initialize.return_value = "Simulator.Unit_Operations.Cooler Cooler1(Nc = 2);"
        cooler.OM_Flowsheet_Equation.return_value = "connect(Stream4.Out, Cooler1.In);"

        self.flowsheet.add_unit_operations(mixer0)
        self.flowsheet.add_unit_operations(pass_unit)
        self.flowsheet.add_unit_operations(cooler)

        # Mock Popen to write CSV files for each simulated unit
        def fake_communicate():
            # Write results for whatever unit is being simulated
            for name in ["mixer1", "heater1", "cooler1"]:
                p = os.path.join(self.temp_dir, f"Simulator.{name}_res.csv")
                if not os.path.exists(p):
                    with open(p, 'w') as f:
                        f.write(f"time,Stream3.T,Stream4.T\n0.0,305,350\n1.0,305,350\n")
                    break
            return (b"Sequential simulation success", b"")

        mock_proc = MagicMock()
        mock_proc.communicate.side_effect = fake_communicate

        with patch.object(self.flowsheet, "get_omc_path", return_value="/mock/omc"):
            with patch("python.OMChem.Flowsheet.Popen", return_value=mock_proc):
                self.flowsheet.simulate_SM(ip, op)

        # Check that FlowsheetSEQ.csv was produced and loaded
        seq_csv = os.path.join(self.temp_dir, "FlowsheetSEQ.csv")
        self.assertTrue(os.path.exists(seq_csv))
        self.assertTrue(len(self.flowsheet.result_data) >= 2)
        # Check property transfer
        self.assertEqual(s3.Prop["T"], "305")
        self.assertEqual(s4.Prop["T"], "350")

    def test_simulate_sm_failure_when_no_csv(self):
        """Verify simulate_SM terminates early and records last_error when a unit simulation produces no CSV."""
        self.flowsheet.add_compound_list(["Water"])

        mixer = MagicMock()
        mixer.type = "Mixer"
        mixer.name = "Mixer1"
        mixer.input_stms = []
        mixer.output_stms = []
        mixer.EngStms = None
        mixer.OM_Flowsheet_Initialize.return_value = "Mixer1_init;"
        mixer.OM_Flowsheet_Equation.return_value = "Mixer1_eqn;"

        self.flowsheet.add_unit_operations(mixer)

        # Ensure unit order resolves Mixer1 into self.unit
        ip = {"Mixer1": ["s1"]}
        op = {"Mixer1": ["s1"]}

        mock_proc = MagicMock()
        mock_proc.communicate.return_value = (b"Error: compilation failed for Mixer1", b"")

        with patch.object(self.flowsheet, "get_omc_path", return_value="/mock/omc"):
            with patch("python.OMChem.Flowsheet.Popen", return_value=mock_proc):
                self.flowsheet.simulate_SM(ip, op)

        self.assertIn("Error: compilation failed for Mixer1", self.flowsheet.last_error)


if __name__ == "__main__":
    unittest.main()
