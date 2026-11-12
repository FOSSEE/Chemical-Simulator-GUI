import sys
import os
import unittest
from types import SimpleNamespace

# Ensure Python can find modules under src/main/python
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'src', 'main', 'python')))

from utils.UnitOperations import (
    UnitOperation, Mixer, Splitter, Heater, Cooler, Flash, CentrifugalPump, Valve,
    AdiabaticCompressor, AdiabaticExpander, CompoundSeparator,
    ShortcutColumn, DistillationColumn, ConvertionReactor
)
from python.utils.ComponentSelector import compound_selected


class TestUnitOperations(unittest.TestCase):
    """Unit tests for UnitOperations classes, defaults, and parameter setters."""

    # --------------------- MIXER TESTS --------------------- #

    def test_mixer_default_initialization(self):
        """Verify Mixer instantiates with correct default attributes."""
        mixer = Mixer()
        self.assertEqual(mixer.type, 'Mixer')
        self.assertEqual(mixer.no_of_inputs, 2)
        self.assertEqual(mixer.variables['NI']['value'], 2)
        self.assertEqual(mixer.variables['outPress']['value'], 'Inlet_Average')
        self.assertIn('Inlet_Minimum', mixer.Pout_modes)
        self.assertIn('Inlet_Maximum', mixer.Pout_modes)

    def test_mixer_param_setter(self):
        """Verify param_setter correctly updates input count and outlet pressure mode."""
        mixer = Mixer()
        mixer.param_setter([3, 'Inlet_Minimum'])
        self.assertEqual(mixer.no_of_inputs, 3)
        self.assertEqual(mixer.variables['NI']['value'], 3)
        self.assertEqual(mixer.variables['outPress']['value'], 'Inlet_Minimum')

    def test_mixer_param_setter_edge_case(self):
        """Verify param_setter parses string input count into integer."""
        mixer = Mixer()
        mixer.param_setter(['4', 'Inlet_Maximum'])
        self.assertEqual(mixer.no_of_inputs, 4)
        self.assertEqual(mixer.variables['NI']['value'], 4)
        self.assertEqual(mixer.variables['outPress']['value'], 'Inlet_Maximum')

    # --------------------- SPLITTER TESTS --------------------- #

    def test_splitter_default_initialization(self):
        """Verify Splitter instantiates with standard defaults."""
        splitter = Splitter()
        self.assertEqual(splitter.type, 'Splitter')
        self.assertEqual(splitter.no_of_outputs, 2)
        self.assertEqual(splitter.variables['No']['value'], 2)
        self.assertEqual(splitter.variables['CalcType']['value'], 'Split_Ratio')
        self.assertEqual(splitter.variables['SpecVal_s']['value'], [0.5, 0.5])

    def test_splitter_param_setter_split_ratio(self):
        """Verify param_setter assigns split ratios correctly."""
        splitter = Splitter()
        splitter.param_setter([2, 'Split_Ratio', 0.7, 0.3])
        self.assertEqual(splitter.no_of_outputs, 2)
        self.assertEqual(splitter.variables['CalcType']['value'], 'Split_Ratio')
        self.assertEqual(splitter.variables['SpecVal_s']['value'], [0.7, 0.3])
        self.assertEqual(splitter.variables['SpecVal_s']['unit'], '')

    def test_splitter_param_setter_molar_flow(self):
        """Verify param_setter updates units to mol/s for Molar_Flow mode."""
        splitter = Splitter()
        splitter.param_setter([2, 'Molar_Flow', 50.0, 50.0])
        self.assertEqual(splitter.variables['CalcType']['value'], 'Molar_Flow')
        self.assertEqual(splitter.variables['SpecVal_s']['value'], [50.0, 50.0])
        self.assertEqual(splitter.variables['SpecVal_s']['unit'], 'mol/s')

    def test_splitter_param_setter_mass_flow(self):
        """Verify param_setter updates units to g/s for Mass_Flow mode."""
        splitter = Splitter()
        splitter.param_setter([2, 'Mass_Flow', 10.5, 20.5])
        self.assertEqual(splitter.variables['CalcType']['value'], 'Mass_Flow')
        self.assertEqual(splitter.variables['SpecVal_s']['value'], [10.5, 20.5])
        self.assertEqual(splitter.variables['SpecVal_s']['unit'], 'g/s')

    # --------------------- HEATER & COOLER TESTS --------------------- #

    def test_heater_default_initialization(self):
        """Verify Heater default state and variables."""
        heater = Heater()
        self.assertEqual(heater.type, 'Heater')
        self.assertEqual(heater.no_of_inputs, 1)
        self.assertEqual(heater.no_of_outputs, 1)
        self.assertEqual(heater.variables['Pdel']['value'], 0)
        self.assertEqual(heater.variables['Eff']['value'], 1)
        self.assertEqual(heater.variables['Tout']['value'], 298.15)

    def test_cooler_default_initialization(self):
        """Verify Cooler default state and variables."""
        cooler = Cooler()
        self.assertEqual(cooler.type, 'Cooler')
        self.assertEqual(cooler.no_of_inputs, 1)
        self.assertEqual(cooler.no_of_outputs, 1)
        self.assertEqual(cooler.variables['Pdel']['value'], 0)
        self.assertEqual(cooler.variables['Eff']['value'], 1)

    # --------------------- FLASH DRUM TESTS --------------------- #

    def test_flash_default_initialization(self):
        """Verify Flash drum default specifications."""
        flash = Flash()
        self.assertEqual(flash.type, 'Flash')
        self.assertEqual(flash.no_of_inputs, 1)
        self.assertEqual(flash.no_of_outputs, 2)
        self.assertTrue(flash.thermo_pack_req)
        self.assertEqual(flash.variables['Tdef']['value'], 298.15)
        self.assertEqual(flash.variables['Pdef']['value'], 101325)

    def test_flash_param_setter(self):
        """Verify setting thermodynamic package and conditions for Flash."""
        flash = Flash()
        flash.param_setter(['Peng-Robinson', True, 350.0, True, 200000])
        self.assertEqual(flash.variables['thermo_package']['value'], 'Peng-Robinson')
        self.assertTrue(flash.variables['BTdef']['value'])
        self.assertEqual(flash.variables['Tdef']['value'], 350.0)
        self.assertTrue(flash.variables['BPdef']['value'])
        self.assertEqual(flash.variables['Pdef']['value'], 200000)

    # --------------------- PUMP & VALVE TESTS --------------------- #

    def test_pump_default_initialization(self):
        """Verify Centrifugal Pump default parameters."""
        pump = CentrifugalPump()
        self.assertEqual(pump.type, 'CentrifugalPump')
        self.assertEqual(pump.variables['Eff']['value'], 1)
        self.assertIn('Pdel', pump.modes_list)
        self.assertIn('Pout', pump.modes_list)

    def test_valve_default_initialization(self):
        """Verify Valve default parameters."""
        valve = Valve()
        self.assertEqual(valve.type, 'Valve')
        self.assertIn('Pdel', valve.modes_list)
        self.assertIn('Pout', valve.modes_list)

    # --------------------- COMPRESSOR & EXPANDER TESTS --------------------- #

    def test_compressor_and_expander_initialization(self):
        """Verify AdiabaticCompressor and AdiabaticExpander variants."""
        ad_comp = AdiabaticCompressor()
        self.assertEqual(ad_comp.type, 'AdiabaticCompressor')
        self.assertEqual(ad_comp.no_of_inputs, 1)
        self.assertEqual(ad_comp.no_of_outputs, 1)

        ad_exp = AdiabaticExpander()
        self.assertEqual(ad_exp.type, 'AdiabaticExpander')
        self.assertEqual(ad_exp.no_of_inputs, 1)
        self.assertEqual(ad_exp.no_of_outputs, 1)

    # --------------------- COMPOUND SEPARATOR TESTS --------------------- #

    def test_compound_separator_initialization(self):
        """Verify CompoundSeparator attributes and stream counts."""
        sep = CompoundSeparator()
        self.assertEqual(sep.type, 'CompoundSeparator')
        self.assertEqual(sep.no_of_inputs, 1)
        self.assertEqual(sep.no_of_outputs, 2)

    # --------------------- CONVERSION REACTOR TESTS --------------------- #

    def test_conversion_reactor_initialization(self):
        """Verify ConvertionReactor attributes."""
        reactor = ConvertionReactor()
        self.assertEqual(reactor.type, 'ConvertionReactor')
        self.assertEqual(reactor.no_of_inputs, 1)
        self.assertEqual(reactor.no_of_outputs, 1)


class TestUnitOperationCodeGeneration(unittest.TestCase):
    """Regression tests for Modelica code paths that used to crash."""

    def setUp(self):
        self._saved_compounds = list(compound_selected)
        compound_selected[:] = ["Water(chemsep)", "Ethanol(chemsep)"]

    def tearDown(self):
        compound_selected[:] = self._saved_compounds

    def test_initialize_with_multiple_thermo_models(self):
        unit = UnitOperation()
        unit.name = 'U1'
        unit.thermo_pack_req = True
        unit.extra = ['DistillationColumn.Cond', 'DistillationColumn.DistCol']
        unit.multidict = ['x']
        unit.parameters = ['Nt']
        unit.variables = {'Nt': {'value': 12}}
        c = UnitOperation.counter

        self.assertEqual(
            unit.OM_Flowsheet_Initialize(),
            f'model DistillationColumnCond{c}\n'
            'extends Simulator.UnitOperations.DistillationColumn.Cond;\n'
            'extends Simulator.Files.ThermodynamicPackages.RaoultsLaw;\n'
            f'end DistillationColumnCond{c};\n'
            f'model DistillationColumnDistCol{c}\n'
            'extends Simulator.UnitOperations.DistillationColumn.DistCol;\n'
            f'DistillationColumnCond{c} DistillationColumnCond#x;\n'
            f'end DistillationColumnDistCol{c};\n'
            f'DistillationColumnDistCol{c} U1(Nc = 2,C = {{Water, Ethanol}}, Nt = 12);\n',
        )

    def _column_with_condenser_spec(self, spec):
        column = DistillationColumn()
        column.variables['C_Spec']['type'] = spec
        column.input_stms = {1: SimpleNamespace(name='F')}
        column.output_stms = {1: SimpleNamespace(name='D'), 2: SimpleNamespace(name='B')}
        return column

    def test_condenser_fallback_uses_selected_mode(self):
        column = self._column_with_condenser_spec('Custom')
        column.mode, column.mode_val = 'T', 350
        self.assertIn(f'{column.name}.condenser.T=350;\n', column.OM_Flowsheet_Equation())

    def test_unknown_condenser_spec_without_mode_raises(self):
        column = self._column_with_condenser_spec('Custom')
        with self.assertRaisesRegex(ValueError, 'Unsupported condenser specification: Custom'):
            column.OM_Flowsheet_Equation()


if __name__ == '__main__':
    unittest.main()
