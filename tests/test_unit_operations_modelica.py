import os
import sys
import unittest
from types import SimpleNamespace

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from python.utils.ComponentSelector import compound_selected
from python.utils.UnitOperations import (
    UnitOperation, Mixer, Splitter, Heater, Cooler, Flash, Valve,
    AdiabaticCompressor, AdiabaticExpander, CompoundSeparator,
    ShortcutColumn, DistillationColumn, ConvertionReactor,
)


def stream(name):
    return SimpleNamespace(name=name)


class _CompoundsMixin:
    """Run each test with a known compound list and restore the shared one after."""

    def setUp(self):
        self._saved_compounds = list(compound_selected)
        compound_selected[:] = ["Water(chemsep)", "Ethanol(chemsep)"]

    def tearDown(self):
        compound_selected[:] = self._saved_compounds


class TestUnitOperationBase(_CompoundsMixin, unittest.TestCase):

    def test_compounds_strip_database_suffix(self):
        self.assertEqual(UnitOperation().compounds, ["Water", "Ethanol"])

    def test_update_compounds_reads_current_selection(self):
        units = [UnitOperation(), Mixer(), Splitter(), Flash(), ShortcutColumn(),
                 DistillationColumn(), CompoundSeparator(),
                 AdiabaticCompressor(), AdiabaticExpander()]
        compound_selected[:] = ["Methanol(chemsep)"]
        for unit in units:
            unit.update_compounds()
            self.assertEqual(unit.compounds, ["Methanol"], unit.type)

    def test_param_getter_defaults_to_first_mode(self):
        heater = Heater()
        self.assertEqual(heater.param_getter(), {'Pdel': 0, 'Eff': 1})
        self.assertEqual(heater.mode, 'Q')

    def test_param_getter_with_mode(self):
        heater = Heater()
        self.assertEqual(heater.param_getter('Tout'), {'Tout': None, 'Pdel': 0, 'Eff': 1})
        self.assertEqual(heater.mode, 'Tout')

    def test_param_getter_tooltip_uses_display_names_and_units(self):
        heater = Heater()
        self.assertEqual(
            heater.param_getter_tooltip('Tout'),
            {'Tout': None, 'Pressure Drop': '0 Pa', 'Efficiency': '1 '},
        )
        heater.param_getter_tooltip()
        self.assertEqual(heater.mode, 'Q')

    def test_param_setter_sets_mode_values_and_thermo_package(self):
        heater = Heater()
        heater.param_setter({'Tout': 350, 'Pdel': 10, 'Thermo Package': 'PengRobinson'})
        self.assertEqual(heater.mode, 'Tout')
        self.assertEqual(heater.mode_val, 350)
        self.assertEqual(heater.variables['Tout']['value'], 350)
        self.assertEqual(heater.variables['Pdel']['value'], 10)
        self.assertEqual(heater.thermo_package, 'PengRobinson')

    def test_param_setter_empty_params_keeps_mode(self):
        heater = Heater()
        heater.mode = 'Q'
        heater.param_setter({})
        self.assertEqual(heater.mode, 'Q')

    def test_add_and_remove_connections(self):
        unit = UnitOperation()
        feed, product = stream('S1'), stream('S2')
        unit.add_connection(1, 1, feed)
        unit.add_connection(0, 1, product)
        self.assertEqual(unit.input_stms, {1: feed})
        self.assertEqual(unit.output_stms, {1: product})

        unit.remove_connection(1, 1)
        unit.remove_connection(0, 1)
        unit.remove_connection(0, 99)  # missing id is ignored
        self.assertEqual(unit.input_stms, {})
        self.assertEqual(unit.output_stms, {})

    def test_set_pos(self):
        unit = UnitOperation()
        unit.set_pos((10, 20))
        self.assertEqual(unit.pos, (10, 20))

    def test_conversion_reactor_formats_arguments(self):
        reactor = ConvertionReactor(name='R1', Nr=1, a=[1, 2], Tdef=300)
        self.assertEqual(reactor.Nr, '1')
        self.assertEqual(reactor.a, '{1, 2}')
        self.assertEqual(reactor.Tdef, '300')


class TestFlowsheetInitialize(_CompoundsMixin, unittest.TestCase):

    def test_unit_without_thermo_package(self):
        heater = Heater()
        self.assertEqual(
            heater.OM_Flowsheet_Initialize(),
            f'Simulator.UnitOperations.Heater {heater.name}'
            '(Nc = 2,C = {Water, Ethanol}, Pdel = 0, Eff = 1);\n',
        )

    def test_unit_with_thermo_package(self):
        flash = Flash()
        model = f'Flash{Flash.counter}'
        self.assertEqual(
            flash.OM_Flowsheet_Initialize(),
            f'model {model}\n'
            'extends Simulator.UnitOperations.Flash;\n'
            'extends Simulator.Files.ThermodynamicPackages.RaoultsLaw;\n'
            f'end {model};\n'
            f'{model} {flash.name}(Nc = 2,C = {{Water, Ethanol}}, '
            'BTdef = false, Tdef = 298.15, BPdef = false, Pdef = 101325);\n',
        )

    def test_shortcut_column_skips_key_mole_fractions(self):
        column = ShortcutColumn()
        text = column.OM_Flowsheet_Initialize()
        self.assertIn(
            f'{column.name}(Nc = 2,C = {{Water, Ethanol}}, HKey = 0, LKey = 0, '
            'Ctype = "Total", Pcond = 101325, Preb = 101325, RR = 1.5);\n',
            text,
        )
        self.assertNotIn('x_pc', text)

    def test_distillation_column(self):
        column = DistillationColumn()
        column.variables['InT_s']['value'] = [6]
        text = column.OM_Flowsheet_Initialize()
        for model in ('Condenser', 'Tray', 'Reboiler', f'distCol{column.count}'):
            self.assertIn(f'model {model}\n', text)
            self.assertIn(f'end {model};\n', text)
        self.assertTrue(text.endswith(
            f'distCol{column.count} {column.name}(Nc = 2, C= C,'
            'Nt=12,Ni=1,InT_s={6},Ctype ="Total");\n'
        ))

    def test_compound_separator(self):
        sep = CompoundSeparator()
        sep.param_setter([True, False, 'Molar_Flow   (mol/s)', '10',
                          'Inlet_Molar_Flow_Percent', '50'])
        self.assertEqual(
            sep.OM_Flowsheet_Initialize(),
            f'Simulator.UnitOperations.CompoundSeparator {sep.name}(Nc = 2, '
            'C = {Water, Ethanol},'
            'SepFact_c = {"Molar_Flow", "Inlet_Molar_Flow_Percent"},SepStrm = 1);\n',
        )


class TestFlowsheetEquation(_CompoundsMixin, unittest.TestCase):

    def test_no_streams_adds_warnings(self):
        heater = Heater()
        self.assertEqual(
            heater.OM_Flowsheet_Equation(),
            f'// Warning: {heater.name} has no input streams\n'
            f'// Warning: {heater.name} has no output streams\n',
        )

    def test_single_input_and_output_with_mode(self):
        heater = Heater()
        heater.input_stms = {1: stream('S1')}
        heater.output_stms = {1: stream('S2')}
        heater.mode, heater.mode_val = 'Q', 1000
        n = heater.name
        self.assertEqual(
            heater.OM_Flowsheet_Equation(),
            f'connect({n}.In, S1.Out);\nconnect({n}.Out, S2.In);\n{n}.Q = 1000;\n',
        )

    def test_mixer_uses_indexed_inputs(self):
        mixer = Mixer()
        mixer.input_stms = {1: stream('S1'), 2: stream('S2')}
        mixer.output_stms = {1: stream('S3')}
        n = mixer.name
        self.assertEqual(
            mixer.OM_Flowsheet_Equation(),
            f'connect(S1.Out, {n}.In[1]);\nconnect(S2.Out, {n}.In[2]);\n'
            f'connect({n}.Out, S3.In);\n',
        )

    def test_multiple_outputs_are_indexed_and_unnamed_streams_skipped(self):
        valve = Valve()
        valve.input_stms = {1: object()}
        valve.output_stms = {1: stream('S2'), 2: stream('S3')}
        n = valve.name
        self.assertEqual(
            valve.OM_Flowsheet_Equation(),
            f'connect(S2.In, {n}.Out[1]);\nconnect(S3.In, {n}.Out[2]);\n',
        )

    def test_shortcut_column(self):
        column = ShortcutColumn()
        column.input_stms = {1: stream('F')}
        column.output_stms = {1: stream('D'), 2: stream('B')}
        n = column.name
        self.assertEqual(
            column.OM_Flowsheet_Equation(),
            f'connect({n}.In[1], F.Out);\n'
            f'connect(D.In, {n}.Out);\nconnect(B.In, {n}.Out2);\n'
            f'{n}.x_pc[2, {n}.HKey] = 0.01;\n{n}.x_pc[3, {n}.LKey] = 0.01;\n',
        )

    def test_flash_output_ports(self):
        flash = Flash()
        flash.input_stms = {1: stream('F')}
        flash.output_stms = {1: stream('V'), 2: stream('L')}
        n = flash.name
        self.assertEqual(
            flash.OM_Flowsheet_Equation(),
            f'connect({n}.In[1], F.Out);\n'
            f'connect(V.In, {n}.Out1);\nconnect(L.In, {n}.Out2);\n',
        )
        flash.output_stms = {1: stream('V')}
        self.assertIn(f'connect(V.In, {n}.Out);\n', flash.OM_Flowsheet_Equation())

    def test_compound_separator_vector_and_scalar_values(self):
        sep = CompoundSeparator()
        sep.input_stms = {1: stream('F')}
        sep.output_stms = {1: stream('A'), 2: stream('B')}
        sep.variables['SepVal_c']['value'] = [10.0, 50.0]
        n = sep.name
        self.assertEqual(
            sep.OM_Flowsheet_Equation(),
            f'connect({n}.In[1], F.Out);\n'
            f'connect(A.In, {n}.Out1);\nconnect(B.In, {n}.Out2);\n'
            f'{n}.SepVal_c = {{10.0,50.0}};\n',
        )
        sep.variables['SepVal_c']['value'] = 5
        self.assertTrue(sep.OM_Flowsheet_Equation().endswith(f'{n}.SepVal_c = 5;\n'))

    def test_splitter_flow_specifications(self):
        splitter = Splitter()
        splitter.input_stms = {1: stream('F')}
        splitter.output_stms = {1: stream('A'), 2: stream('B')}
        n = splitter.name
        for calc_type, var in (('Molar_Flow', 'F_p'), ('Mass_Flow', 'Fm_p')):
            with self.subTest(calc_type=calc_type):
                splitter.param_setter([2, calc_type, 1.0, 2.0])
                self.assertEqual(
                    splitter.OM_Flowsheet_Equation(),
                    f'connect(F.Out, {n}.In);\n'
                    f'connect({n}.Out[1], A.In);\nA.{var}[1] = 1.0;\n'
                    f'connect({n}.Out[2], B.In);\nB.{var}[1] = 2.0;\n',
                )

    def test_splitter_split_ratio_has_no_flow_specification(self):
        splitter = Splitter()
        splitter.output_stms = {1: stream('A'), 2: stream('B')}
        n = splitter.name
        self.assertEqual(
            splitter.OM_Flowsheet_Equation(),
            f'connect({n}.Out[1], A.In);\nconnect({n}.Out[2], B.In);\n',
        )


class TestDistillationColumn(_CompoundsMixin, unittest.TestCase):

    def _column(self, c_type='Reflux Ratio', c_value=2.5,
                r_type='Temperature  (K)', r_value=380):
        column = DistillationColumn()
        column.param_setter([10, 5, 'Partial', 120000, c_type, 'Ethanol', c_value,
                             130000, r_type, 'Water', r_value, 'PengRobinson'])
        column.input_stms = {1: stream('F')}
        column.output_stms = {1: stream('D'), 2: stream('B')}
        return column

    def test_param_setter(self):
        column = self._column(c_type='Compound Molar Fraction', c_value=0.9,
                              r_type='Compound Molar Flow    (mol/s)', r_value=3)
        v = column.variables
        self.assertEqual(v['Nt']['value'], 10)
        self.assertEqual(v['InT_s']['value'], [5])
        self.assertEqual(v['Ctype']['value'], 'Partial')
        self.assertEqual(v['Pcond']['value'], 120000)
        self.assertEqual(v['Preb']['value'], 130000)
        self.assertEqual(v['C_Spec'], {**v['C_Spec'], 'type': 'Compound Molar Fraction',
                                        'comp': 'Ethanol', 'value': 0.9})
        self.assertEqual(v['R_Spec'], {**v['R_Spec'], 'type': 'Compound Molar Flow    (mol/s)',
                                        'comp': 'Water', 'value': 3})
        self.assertEqual(v['thermo_package']['value'], 'PengRobinson')

    def test_reflux_ratio_spec_updates_rr(self):
        column = self._column()
        self.assertEqual(column.variables['RR']['value'], 2.5)
        n = column.name
        self.assertEqual(
            column.OM_Flowsheet_Equation(),
            f'connect({n}.Dist, D.In);\nconnect({n}.Bot, B.In);\n'
            f'connect(F.Out, {n}.In_s[1]);\n'
            f'{n}.RR=2.5;\nB.T = 380;\n'
            f'{n}.reboiler.P=130000;\n{n}.condenser.P=120000;\n',
        )

    def test_condenser_specs(self):
        cases = {
            'Product Molar Flow   (mol/s)': 'D.F_p[1] = 10;\n',
            'Temperature  (K)': 'D.T = 10;\n',
            'Compound Molar Fraction': 'D.x_pc[1,:2] = 10;\n',
            'Compound Molar Flow    (mol/s)': 'D.F_pc[1,:2] = 10;\n',
        }
        for spec, expected in cases.items():
            with self.subTest(spec=spec):
                self.assertIn(expected, self._column(c_type=spec, c_value=10).OM_Flowsheet_Equation())

    def test_reboiler_specs(self):
        cases = {
            'Product Molar Flow   (mol/s)': 'B.F_p[1] = 4;\n',
            'Compound Molar Fraction': 'B.x_pc[1,:1] = 4;\n',
            'Compound Molar Flow    (mol/s)': 'B.F_pc[1,:1] = 4;\n',
        }
        for spec, expected in cases.items():
            with self.subTest(spec=spec):
                self.assertIn(expected, self._column(r_type=spec, r_value=4).OM_Flowsheet_Equation())


class TestShortcutColumnAndSeparatorSetters(_CompoundsMixin, unittest.TestCase):

    def test_shortcut_column_param_setter_maps_keys_to_indices(self):
        column = ShortcutColumn()
        column.param_setter(['Ethanol', 'Water', 0.02, 0.03, 'Partial',
                             200000, 210000, 2.0, 'PengRobinson'])
        v = column.variables
        self.assertEqual(v['HKey']['value'], 2)
        self.assertEqual(v['LKey']['value'], 1)
        self.assertEqual(v['HKey_x_pc']['value'], 0.02)
        self.assertEqual(v['LKey_x_pc']['value'], 0.03)
        self.assertEqual(v['Ctype']['value'], 'Partial')
        self.assertEqual(v['Pcond']['value'], 200000)
        self.assertEqual(v['Preb']['value'], 210000)
        self.assertEqual(v['RR']['value'], 2.0)
        self.assertEqual(v['thermo_package']['value'], 'PengRobinson')

    def test_shortcut_column_param_setter_rejects_unknown_compound(self):
        with self.assertRaises(ValueError):
            ShortcutColumn().param_setter(['Benzene', 'Water', 0, 0, 'Total', 1, 1, 1, 'X'])

    def test_compound_separator_param_setter(self):
        sep = CompoundSeparator()
        sep.param_setter([False, True, 'Mass_Flow   (g/s)', '1.5', 'Molar_Flow   (mol/s)', '2'])
        self.assertEqual(sep.variables['SepStrm']['value'], 2)
        self.assertEqual(sep.variables['SepVal_c']['value'], [1.5, 2.0])
        self.assertEqual(sep.variables['SepFact_c']['value'],
                         ['Mass_Flow   (g/s)', 'Molar_Flow   (mol/s)'])

    def test_compound_separator_init_variables_resets(self):
        sep = CompoundSeparator()
        sep.variables['SepStrm']['value'] = 2
        sep.update_compounds()
        sep.init_variables()
        self.assertEqual(sep.variables['SepStrm']['value'], 1)
        self.assertEqual(sep.variables['SepVal_c']['value'], ['', ''])


class TestSplitterParamSetter(_CompoundsMixin, unittest.TestCase):

    def test_missing_values_are_kept_or_filled(self):
        splitter = Splitter()
        splitter.param_setter([3, 'Molar_Flow', 1])
        self.assertEqual(splitter.variables['SpecVal_s']['value'], [1.0, 0.5, 0.0])

    def test_missing_split_ratios_are_split_evenly(self):
        splitter = Splitter()
        splitter.param_setter([2, 'Split_Ratio', 0.25, 0.75])
        splitter.variables['SpecVal_s']['value'] = [0.25, 0.25]
        splitter.param_setter([4, 'Split_Ratio'])
        self.assertEqual(splitter.variables['SpecVal_s']['value'], [0.25, 0.25, 0.25, 0.25])
        self.assertEqual(splitter.specval, '{0.25, 0.25, 0.25, 0.25}')

    def test_output_count_is_clamped(self):
        splitter = Splitter()
        splitter.param_setter([10, 'Molar_Flow', 1, 2, 3, 4, 5, 6, 7])
        self.assertEqual(splitter.no_of_outputs, 6)
        self.assertEqual(splitter.variables['SpecVal_s']['value'], [1.0, 2.0, 3.0, 4.0, 5.0, 6.0])
        splitter.param_setter([1, 'Molar_Flow', 1, 2])
        self.assertEqual(splitter.no_of_outputs, 2)

    def test_split_ratios_must_sum_to_one(self):
        splitter = Splitter()
        with self.assertRaisesRegex(ValueError, 'sum to 1.0'):
            splitter.param_setter([2, 'Split_Ratio', 0.6, 0.6])
        self.assertEqual(splitter.variables['SpecVal_s']['value'], [0.5, 0.5])


if __name__ == '__main__':
    unittest.main()
