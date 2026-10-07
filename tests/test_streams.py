import os
import sys
import unittest

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from python.utils.ComponentSelector import compound_selected
from python.utils.Streams import MaterialStream


class TestMaterialStreamInitialization(unittest.TestCase):
    """Unit tests for MaterialStream construction and compound-specific variables."""

    def setUp(self):
        MaterialStream.counter = 1
        compound_selected.clear()

    def test_default_stream_metadata(self):
        stream = MaterialStream(["Water(chemsep)", "Ethanol(chemsep)"])

        self.assertEqual(stream.name, "MaterialStream1")
        self.assertEqual(stream.type, "MaterialStream")
        self.assertEqual(stream.no_of_inputs, 1)
        self.assertEqual(stream.no_of_outputs, 1)
        self.assertEqual(stream.thermo_package, "RaoultsLaw")
        self.assertEqual(stream.mode, "PT")
        self.assertEqual(stream.mode1, "P")
        self.assertEqual(stream.mode2, "T")

    def test_counter_increments_for_multiple_streams(self):
        first = MaterialStream(["Water(chemsep)"])
        second = MaterialStream(["Water(chemsep)"])

        self.assertEqual(first.name, "MaterialStream1")
        self.assertEqual(second.name, "MaterialStream2")
        self.assertEqual(MaterialStream.counter, 3)

    def test_init_variables_creates_phase_properties_for_each_compound(self):
        stream = MaterialStream(["Water(chemsep)", "Ethanol(chemsep)"])

        self.assertEqual(stream.variables["x_pc[1,1]"]["value"], 0.5)
        self.assertEqual(stream.variables["x_pc[1,2]"]["value"], 0.5)
        self.assertIn("xm_pc[2,1]", stream.variables)
        self.assertIn("F_pc[3,2]", stream.variables)
        self.assertEqual(stream.variables["Pvap_c[1]"]["name"], "Vapor Pressure(Water)")
        self.assertEqual(stream.variables["Pvap_c[2]"]["name"], "Vapor Pressure(Ethanol)")

    def test_update_compounds_uses_global_component_selection(self):
        stream = MaterialStream(["Water(chemsep)"])
        compound_selected.extend(["Acetone(chemsep)", "Methanol(chemsep)"])

        stream.update_compounds()

        self.assertEqual(stream.compound_names, ["Acetone(chemsep)", "Methanol(chemsep)"])


class TestMaterialStreamParameters(unittest.TestCase):
    """Unit tests for parameter getter/setter behavior."""

    def setUp(self):
        MaterialStream.counter = 1
        compound_selected.clear()
        self.stream = MaterialStream(["Water(chemsep)", "Ethanol(chemsep)"])

    def test_param_getter_pt_returns_default_stream_inputs(self):
        params = self.stream.param_getter("PT")

        self.assertEqual(params["P"], 101325.0)
        self.assertEqual(params["T"], 300.0)
        self.assertEqual(params["MolFlow"], 100.0)
        self.assertEqual(params["x_pc"], [0.5, 0.5])
        self.assertEqual(params["Thermo Package"], "RaoultsLaw")
        self.assertEqual(self.stream.mode1, "P")
        self.assertEqual(self.stream.mode2, "T")

    def test_param_getter_supports_all_flash_specification_modes(self):
        mode_expectations = {
            "PH": ("P", "H_p[1]"),
            "PVF": ("P", "xvap"),
            "TVF": ("T", "xvap"),
            "PS": ("P", "S_p[1]"),
        }

        for mode, expected_modes in mode_expectations.items():
            with self.subTest(mode=mode):
                params = self.stream.param_getter(mode)
                self.assertIn(expected_modes[0], params)
                self.assertIn(expected_modes[1], params)
                self.assertEqual((self.stream.mode1, self.stream.mode2), expected_modes)

    def test_param_getter_keeps_non_numeric_values_without_crashing(self):
        self.stream.variables["P"]["value"] = "not-a-number"
        self.stream.variables["T"]["value"] = "300.12346"

        params = self.stream.param_getter("PT")

        self.assertEqual(params["P"], "not-a-number")
        self.assertEqual(params["T"], 300.1235)

    def test_param_setter_updates_main_inputs_and_composition(self):
        self.stream.param_getter("PT")

        self.stream.param_setter({
            "P": 202650,
            "T": 325,
            "MolFlow": 250,
            "x_pc": "0.25,0.75",
            "Thermo Package": "NRTL",
        })

        self.assertEqual(self.stream.variables["P"]["value"], 202650)
        self.assertEqual(self.stream.variables["T"]["value"], 325)
        self.assertEqual(self.stream.variables["F_p[1]"]["value"], 250)
        self.assertEqual(self.stream.variables["x_pc[1,1]"]["value"], "0.25")
        self.assertEqual(self.stream.variables["x_pc[1,2]"]["value"], "0.75")
        self.assertEqual(self.stream.thermo_package, "NRTL")

    def test_param_setter_converts_empty_composition_to_none(self):
        self.stream.param_getter("PT")

        self.stream.param_setter({
            "P": 101325,
            "T": 300,
            "MolFlow": 100,
            "x_pc": "1.0,",
            "Thermo Package": "RaoultsLaw",
        })

        self.assertEqual(self.stream.variables["x_pc[1,1]"]["value"], "1.0")
        self.assertIsNone(self.stream.variables["x_pc[1,2]"]["value"])

    def test_selected_variable_tooltip_rounds_numeric_values(self):
        self.stream.variables["P"]["value"] = "101325.67891"
        self.stream.variables["T"]["value"] = "299.99999"
        self.stream.variables["H_p[1]"]["value"] = "1234.56789"

        tooltip = self.stream.param_getter_tooltip_selectedVar()

        self.assertEqual(tooltip["Pressure"], "101325.6789 Pa")
        self.assertEqual(tooltip["Temperature"], "300.0 K")
        self.assertEqual(tooltip["Mixture Molar Enthalpy"], "1234.5679 J/mol")


class TestMaterialStreamModelicaGeneration(unittest.TestCase):
    """Unit tests for MaterialStream Modelica code generation helpers."""

    def setUp(self):
        MaterialStream.counter = 1
        compound_selected.clear()
        self.stream = MaterialStream(["Water(chemsep)", "Ethanol(chemsep)"])

    def test_flowsheet_initialize_generates_model_definition(self):
        init_code = self.stream.OM_Flowsheet_Initialize(["Water", "Ethanol"])

        self.assertIn("model ms1", init_code)
        self.assertIn("extends Simulator.Streams.MaterialStream;", init_code)
        self.assertIn("extends Simulator.Files.ThermodynamicPackages.RaoultsLaw;", init_code)
        self.assertIn("ms1 MaterialStream1(Nc = 2,C = {Water, Ethanol});", init_code)

    def test_flowsheet_equation_generates_feed_specifications(self):
        eqn_code = self.stream.OM_Flowsheet_Equation(["Water", "Ethanol"], "Eqn")

        self.assertIn("MaterialStream1.P = 101325;", eqn_code)
        self.assertIn("MaterialStream1.T = 300;", eqn_code)
        self.assertIn("MaterialStream1.F_p[1] = 100;", eqn_code)
        self.assertIn("MaterialStream1.x_pc[1, :] = {0.5, 0.5};", eqn_code)

    def test_flowsheet_equation_skips_none_values(self):
        self.stream.variables["T"]["value"] = None
        self.stream.variables["x_pc[1,2]"]["value"] = None

        eqn_code = self.stream.OM_Flowsheet_Equation(["Water", "Ethanol"], "Eqn")

        self.assertIn("MaterialStream1.P = 101325;", eqn_code)
        self.assertNotIn("MaterialStream1.T =", eqn_code)
        self.assertIn("MaterialStream1.x_pc[1, :] = {0.5};", eqn_code)

    def test_get_min_eqn_values_populates_equation_dictionary(self):
        self.stream.param_getter("PT")
        self.stream.get_min_eqn_values()

        self.assertEqual(self.stream.eqn_dict["P"], 101325)
        self.assertEqual(self.stream.eqn_dict["T"], 300)
        self.assertEqual(self.stream.eqn_dict["x_pc[1,:]"], "{0.5, 0.5}")
        self.assertEqual(self.stream.eqn_dict["F_p[1]"], 100)

    def test_get_start_values_serializes_phase_arrays(self):
        for phase in range(1, 4):
            for compound_index in range(1, 3):
                self.stream.variables[f"x_pc[{phase},{compound_index}]"]["value"] = round(0.1 * phase, 2)
                self.stream.variables[f"F_pc[{phase},{compound_index}]"]["value"] = phase * compound_index
                self.stream.variables[f"Fm_pc[{phase},{compound_index}]"]["value"] = phase + compound_index

        self.stream.variables["MW_p[2]"]["value"] = 18
        self.stream.variables["MW_p[1]"]["value"] = 20
        self.stream.variables["MW_p[3]"]["value"] = 22
        self.stream.variables["Pvap_c[1]"]["value"] = 5000
        self.stream.variables["Pvap_c[2]"]["value"] = 6000

        self.stream.get_start_values()

        self.assertEqual(self.stream.start_dict["x_pc"], "{{0.1, 0.1}, {0.2, 0.2}, {0.3, 0.3}}")
        self.assertEqual(self.stream.start_dict["F_pc"], "{{1, 2}, {2, 4}, {3, 6}}")
        self.assertEqual(self.stream.start_dict["Fm_pc"], "{{2, 3}, {3, 4}, {4, 5}}")
        self.assertEqual(self.stream.start_dict["MW_p"], "{20, 18, 22}")
        self.assertEqual(self.stream.start_dict["Pvap_c"], "{5000, 6000}")


if __name__ == "__main__":
    unittest.main()
