import os
import sys
import unittest
from unittest.mock import MagicMock

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main'))
sys.path.insert(0, os.path.join(PROJECT_ROOT, 'src', 'main', 'python'))

from python.OMChem.Mixer import Mixer
from python.OMChem.Splitter import Splitter
from python.OMChem.Flash import Flash
from python.OMChem.Pump import Pump
from python.OMChem.Valve import Valve
from python.OMChem.Heater import Heater
from python.OMChem.Cooler import Cooler
from python.OMChem.EngStm import EngStm
from python.OMChem.CompSep import CompSep
from python.OMChem.ConvReactor import ConvReactor
from python.OMChem.DistCol import DistCol
from python.OMChem.ShortcutColumn import ShortcutColumn
from python.OMChem.adiabatic_comp import AdiabaticCompressor
from python.OMChem.adiabatic_exp import AdiabaticExpander


class TestOMChemModels(unittest.TestCase):
    """Test suite for OMChem unit operation classes and code generation."""

    def test_mixer(self):
        m = Mixer()
        self.assertEqual(m.type, 'Mixer')
        self.assertTrue(m.name.startswith('Mixer'))
        self.assertEqual(m.no_of_input, 2)
        self.assertEqual(m.no_of_output, 1)

        # Param setter
        m.paramsetter({"NOI": 3})
        self.assertEqual(m.NOI, 3)

        # Connect
        in1 = MagicMock(name="Inlet1")
        in1.name = "Inlet1"
        in2 = MagicMock(name="Inlet2")
        in2.name = "Inlet2"
        out1 = MagicMock(name="Outlet1")
        out1.name = "Outlet1"

        m.connect([in1, in2], [out1])
        self.assertEqual(m.NOI, 2)
        self.assertEqual(m.InputStms, [in1, in2])
        self.assertEqual(m.OutputStms, [out1])

        # Init & Eqn generation
        init_code = m.OM_Flowsheet_Init(["Water", "Ethanol"])
        self.assertIn("Simulator.UnitOperations.Mixer", init_code)
        self.assertIn("Nc = 2", init_code)
        self.assertIn("C = {Water, Ethanol}", init_code)

        eqn_code = m.OM_Flowsheet_Eqn(["Water", "Ethanol"])
        self.assertIn("connect(Inlet1.Out", eqn_code)
        self.assertIn("connect(Inlet2.Out", eqn_code)

    def test_splitter(self):
        s = Splitter()
        self.assertEqual(s.type, 'Splitter')
        self.assertTrue(s.name.startswith('Splitter'))
        self.assertEqual(s.no_of_input, 1)
        self.assertEqual(s.no_of_output, 4)

        s.paramsetter({"NOO": 2})
        self.assertEqual(s.NOI, 2)

        in1 = MagicMock()
        in1.name = "Inlet"
        out1 = MagicMock()
        out1.name = "Out1"
        out2 = MagicMock()
        out2.name = "Out2"

        s.connect([in1], [out1, out2])
        init_code = s.OM_Flowsheet_Init(["Water"])
        self.assertIn("Simulator.Unit_Operations.Splitter", init_code)

        eqn_code = s.OM_Flowsheet_Eqn(["Water"])
        self.assertIn("Inlet.Out", eqn_code)
        self.assertIn(out1.name, eqn_code)
        self.assertIn(out2.name, eqn_code)

    def test_flash(self):
        f = Flash()
        self.assertEqual(f.type, 'flash')
        self.assertTrue(f.name.startswith('Flash'))
        self.assertEqual(f.no_of_input, 1)
        self.assertEqual(f.no_of_output, 2)

        f.paramsetter({"thermoPackage": "RaoultsLaw"})
        self.assertEqual(f.thermoPackage, "RaoultsLaw")

        in1 = MagicMock()
        in1.name = "FlashFeed"
        out1 = MagicMock()
        out1.name = "FlashVapor"
        out2 = MagicMock()
        out2.name = "FlashLiquid"

        f.connect([in1], [out1, out2])
        init_code = f.OM_Flowsheet_Init(["Water", "Acetone"])
        self.assertIn("Simulator.Unit_Operations.Flash", init_code)
        self.assertIn("RaoultsLaw", init_code)

        eqn_code = f.OM_Flowsheet_Eqn(["Water", "Acetone"])
        self.assertIn("connect(FlashFeed.Out", eqn_code)
        self.assertIn("FlashVapor.In", eqn_code)
        self.assertIn("FlashLiquid.In", eqn_code)

    def test_pump(self):
        p = Pump()
        self.assertEqual(p.type, 'Pump')
        self.assertTrue(p.name.startswith('Pump'))
        self.assertIn("pressInc", p.modesList())

        params = p.paramgetter("pressInc")
        params["eff"] = 0.85
        params["pressInc"] = "200000"
        p.paramsetter(params)
        self.assertEqual(p.modeVal, "200000")

        in1 = MagicMock()
        in1.name = "PumpIn"
        out1 = MagicMock()
        out1.name = "PumpOut"

        p.connect([in1], [out1])
        init_code = p.OM_Flowsheet_Init(["Water"])
        self.assertIn("Simulator.Unit_Operations.Centrifugal_Pump", init_code)

        eqn_code = p.OM_Flowsheet_Eqn(["Water"])
        self.assertIn("connect(PumpIn.Out", eqn_code)
        self.assertIn("PumpOut.In", eqn_code)

    def test_valve(self):
        v = Valve()
        self.assertEqual(v.type, 'Valve')
        self.assertTrue(v.name.startswith('Valve'))
        self.assertIn("pressDrop", v.modesList())

        params = v.paramgetter("pressDrop")
        params["pressDrop"] = "101325"
        v.paramsetter(params)
        self.assertEqual(v.modeVal, "101325")

        in1 = MagicMock()
        in1.name = "ValveIn"
        out1 = MagicMock()
        out1.name = "ValveOut"

        v.connect([in1], [out1])
        init_code = v.OM_Flowsheet_Init(["Water"])
        self.assertIn("Simulator.Unit_Operations.Valve", init_code)

        eqn_code = v.OM_Flowsheet_Eqn(["Water"])
        self.assertIn("connect(ValveIn.Out", eqn_code)
        self.assertIn("ValveOut.In", eqn_code)

    def test_heater_and_cooler(self):
        h = Heater()
        self.assertEqual(h.type, 'Heater')
        self.assertTrue(h.name.startswith('Heater'))

        c = Cooler()
        self.assertEqual(c.type, 'Cooler')
        self.assertTrue(c.name.startswith('Cooler'))

        h_params = h.paramgetter("outT")
        h_params["PressureDrop"] = 0
        h_params["eff"] = 1.0
        h_params["outT"] = 350
        h.paramsetter(h_params)
        self.assertEqual(h.modeVal, 350)

        c_params = c.paramgetter("outT")
        c_params["PressureDrop"] = 0
        c_params["eff"] = 1.0
        c_params["outT"] = 280
        c.paramsetter(c_params)
        self.assertEqual(c.modeVal, 280)

        in1 = MagicMock()
        in1.name = "HeatIn"
        out1 = MagicMock()
        out1.name = "HeatOut"
        eng = MagicMock()
        eng.name = "EngStm1"
        h.EngStms = eng
        c.EngStms = eng

        h.connect([in1], [out1])
        init_code = h.OM_Flowsheet_Init(["Water"])
        self.assertIn("Simulator.Unit_Operations.Heater", init_code)

        c.connect([in1], [out1])
        init_code_c = c.OM_Flowsheet_Init(["Water"])
        self.assertIn("Simulator.Unit_Operations.Cooler", init_code_c)

    def test_energy_stream(self):
        e = EngStm()
        self.assertEqual(e.type, 'EngStm')
        self.assertEqual(e.name, 'Engstm')

        init_code = e.OM_Flowsheet_Init(["Water"])
        self.assertIn("Simulator.Streams.Energy_Stream", init_code)

    def test_compressor_and_expander(self):
        comp = AdiabaticCompressor()
        self.assertEqual(comp.type, 'AdiabaticCompressor')
        self.assertTrue(comp.name.startswith('AdiabaticCompressor'))
        self.assertIn("pressInc", comp.modesList())

        comp_params = comp.paramgetter("pressInc")
        comp_params["eff"] = 0.8
        comp_params["pressInc"] = 300000
        comp.paramsetter(comp_params)
        self.assertEqual(comp.modeVal, 300000)

        exp = AdiabaticExpander()
        self.assertEqual(exp.type, 'AdiabaticExpander')
        self.assertTrue(exp.name.startswith('AdiabaticExpander'))
        self.assertIn("outP", exp.modesList())

        exp_params = exp.paramgetter("outP")
        exp_params["eff"] = 0.85
        exp_params["outP"] = 100000
        exp.paramsetter(exp_params)
        self.assertEqual(exp.modeVal, 100000)

    def test_compound_separator(self):
        cs = CompSep()
        self.assertEqual(cs.type, 'CompSep')
        self.assertTrue(cs.name.startswith('CompSep'))
        self.assertEqual(cs.no_of_input, 1)
        self.assertEqual(cs.no_of_output, 2)

        in1 = MagicMock()
        in1.name = "SepFeed"
        out1 = MagicMock()
        out1.name = "SepOut1"
        out2 = MagicMock()
        out2.name = "SepOut2"

        cs.connect([in1], [out1, out2])
        eqn_code = cs.OM_Flowsheet_Eqn(["Water", "Ethanol"])
        self.assertIn("connect(SepFeed.Out", eqn_code)

    def test_distillation_columns(self):
        dc = DistCol()
        self.assertEqual(dc.type, 'DistCol')
        self.assertTrue(dc.name.startswith('DistCol'))
        self.assertEqual(dc.no_of_input, 2)
        self.assertEqual(dc.no_of_output, 2)

        sc = ShortcutColumn()
        self.assertEqual(sc.type, 'ShortCol')
        self.assertTrue(sc.name.startswith('ShortCol'))

        dc_params = dc.paramgetter("refluxRatio")
        dc_params["numStage"] = "10"
        dc_params["numFeeds"] = "1"
        dc_params["feedStages"] = "5"
        dc_params["refluxRatio"] = "1.5"
        dc_params["condensor.P"] = "101325"
        dc_params["reboiler.P"] = "101325"
        dc_params["condType"] = "Total"
        dc.thermoPackage = "NRTL"
        dc.paramsetter(dc_params)
        self.assertEqual(dc.numStage, "10")


if __name__ == "__main__":
    unittest.main()
