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
        self.assertEqual(m.getname(), m.name)
        self.assertEqual(m.modesList(), [])
        self.assertEqual(m.paramgetter(), {})
        self.assertEqual(m.no_of_input, 2)
        self.assertEqual(m.no_of_output, 1)

        # Param setter
        m.paramsetter({"NOI": 3})
        self.assertEqual(m.NOI, 3)

        # Connect with None
        m.connect(None, None)
        self.assertEqual(m.InputStms, [])
        self.assertEqual(m.OutputStms, [])

        # Connect with streams
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
        self.assertEqual(s.getname(), s.name)
        self.assertEqual(s.modesList(), [])
        self.assertEqual(s.paramgetter(), {"NOO": None})
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
        self.assertEqual(f.getname(), f.name)
        self.assertEqual(f.modesList(), [])
        self.assertEqual(f.paramgetter(), {"thermoPackage": None})
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
        self.assertEqual(p.getname(), p.name)
        self.assertIn("pressInc", p.modesList())
        self.assertIn("enFlo", p.modesList())

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
        self.assertIn(f"{p.name}.pressInc=200000", eqn_code)

        # Test enFlo mode
        p.mode = "enFlo"
        p.modeVal = "1500"
        eqn_code_en = p.OM_Flowsheet_Eqn(["Water"])
        self.assertIn(f"{p.EngStms.name}.enFlo=1500;", eqn_code_en)

    def test_valve(self):
        v = Valve()
        self.assertEqual(v.type, 'Valve')
        self.assertTrue(v.name.startswith('Valve'))
        self.assertEqual(v.getname(), v.name)
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
        self.assertEqual(h.getname(), h.name)
        self.assertIn("heatAdd", h.modesList())
        self.assertIn("enFlo", h.modesList())

        c = Cooler()
        self.assertEqual(c.type, 'Cooler')
        self.assertTrue(c.name.startswith('Cooler'))
        self.assertEqual(c.getname(), c.name)
        self.assertIn("heatRem", c.modesList())
        self.assertIn("enFlo", c.modesList())

        h_params = h.paramgetter("outT")
        h_params["PressureDrop"] = 0
        h_params["eff"] = 1.0
        h_params["outT"] = "350"
        h.paramsetter(h_params)
        self.assertEqual(h.modeVal, "350")

        c_params = c.paramgetter("outT")
        c_params["PressureDrop"] = 0
        c_params["eff"] = 1.0
        c_params["outT"] = "280"
        c.paramsetter(c_params)
        self.assertEqual(c.modeVal, "280")

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
        eqn_code_h = h.OM_Flowsheet_Eqn(["Water"])
        self.assertIn("connect(HeatIn.Out", eqn_code_h)
        self.assertIn(f"{h.name}.outT=350;", eqn_code_h)

        # Heater enFlo mode
        h.mode = "enFlo"
        h.modeVal = "5000"
        eqn_code_h_en = h.OM_Flowsheet_Eqn(["Water"])
        self.assertIn(f"{eng.name}.enFlo=5000;", eqn_code_h_en)

        c.connect([in1], [out1])
        init_code_c = c.OM_Flowsheet_Init(["Water"])
        self.assertIn("Simulator.Unit_Operations.Cooler", init_code_c)
        eqn_code_c = c.OM_Flowsheet_Eqn(["Water"])
        self.assertIn("connect(HeatIn.Out", eqn_code_c)
        self.assertIn(f"{c.name}.outT=280;", eqn_code_c)

        # Cooler enFlo mode
        c.mode = "enFlo"
        c.modeVal = "4000"
        eqn_code_c_en = c.OM_Flowsheet_Eqn(["Water"])
        self.assertIn(f"{eng.name}.enFlo=4000;", eqn_code_c_en)

    def test_energy_stream(self):
        e = EngStm()
        self.assertEqual(e.type, 'EngStm')
        self.assertEqual(e.name, 'Engstm')

        init_code = e.OM_Flowsheet_Init(["Water"])
        self.assertIn("Simulator.Streams.Energy_Stream", init_code)

        eqn_code = e.OM_Flowsheet_Eqn(["Water"])
        self.assertEqual(eqn_code, '')

    def test_compressor_and_expander(self):
        comp = AdiabaticCompressor()
        self.assertEqual(comp.type, 'AdiabaticCompressor')
        self.assertTrue(comp.name.startswith('AdiabaticCompressor'))
        self.assertEqual(comp.getname(), comp.name)
        self.assertEqual(comp.modesList(), ["pressInc", "outP", "reqPow"])

        comp_params = comp.paramgetter("pressInc")
        comp_params["eff"] = "0.8"
        comp_params["pressInc"] = "300000"
        comp.paramsetter(comp_params)
        self.assertEqual(comp.eff, "0.8")
        self.assertEqual(comp.modeVal, "300000")

        in_c = MagicMock()
        in_c.name = "CompFeed"
        out_c = MagicMock()
        out_c.name = "CompProd"
        comp.connect([in_c], [out_c])

        init_c = comp.OM_Flowsheet_Init(["Air"])
        self.assertIn("Simulator.Unit_Operations.Adiabatic_Compressor", init_c)
        self.assertIn("eff=0.8", init_c)

        eqn_c = comp.OM_Flowsheet_Eqn(["Air"])
        self.assertIn(f"connect(CompFeed.Out,{comp.name}.In);", eqn_c)
        self.assertIn(f"connect({comp.name}.Out,CompProd.In);", eqn_c)
        self.assertIn(f"{comp.name}.pressInc=300000;", eqn_c)

        # Expander
        exp = AdiabaticExpander()
        self.assertEqual(exp.type, 'AdiabaticExpander')
        self.assertTrue(exp.name.startswith('AdiabaticExpander'))
        self.assertEqual(exp.getname(), exp.name)
        self.assertEqual(exp.modesList(), ["pressDrop", "outP", "genPow"])

        exp_params = exp.paramgetter("outP")
        exp_params["eff"] = "0.85"
        exp_params["outP"] = "100000"
        exp.paramsetter(exp_params)
        self.assertEqual(exp.eff, "0.85")
        self.assertEqual(exp.modeVal, "100000")

        in_e = MagicMock()
        in_e.name = "ExpFeed"
        out_e = MagicMock()
        out_e.name = "ExpProd"
        exp.connect([in_e], [out_e])

        init_e = exp.OM_Flowsheet_Init(["Steam"])
        self.assertIn("Simulator.Unit_Operations.Adiabatic_Expander", init_e)
        self.assertIn("eff=0.85", init_e)

        eqn_e = exp.OM_Flowsheet_Eqn(["Steam"])
        self.assertIn(f"connect(ExpFeed.Out,{exp.name}.In);", eqn_e)
        self.assertIn(f"connect({exp.name}.Out,ExpProd.In);", eqn_e)
        self.assertIn(f"{exp.name}.outP=100000;", eqn_e)

    def test_compound_separator(self):
        cs = CompSep()
        self.assertEqual(cs.type, 'CompSep')
        self.assertTrue(cs.name.startswith('CompSep'))
        self.assertEqual(cs.getname(), cs.name)
        self.assertEqual(cs.modesList(), [])
        self.assertEqual(cs.paramgetter(), {"SepStrm": None, "SepFactValue": None, "SepFact": None})
        self.assertEqual(cs.no_of_input, 1)
        self.assertEqual(cs.no_of_output, 2)

        cs.paramsetter({
            "SepStrm": "1",
            "SepFactValue": "{0.9, 0.1}",
            "SepFact": "{\"Molar_Flow\", \"Mass_Flow\"}"
        })
        self.assertEqual(cs.SepStrm, "1")
        self.assertEqual(cs.SepFactValue, "{0.9, 0.1}")

        in1 = MagicMock()
        in1.name = "SepFeed"
        out1 = MagicMock()
        out1.name = "SepOut1"
        out2 = MagicMock()
        out2.name = "SepOut2"

        cs.connect([in1], [out1, out2])
        init_code = cs.OM_Flowsheet_Init(["Water", "Ethanol"])
        self.assertIn("Simulator.Unit_Operations.Compound_Separator", init_code)
        self.assertIn("sepStrm = 1", init_code)

        eqn_code = cs.OM_Flowsheet_Eqn(["Water", "Ethanol"])
        self.assertIn("connect(SepFeed.Out", eqn_code)
        self.assertIn(f"connect(SepOut1.In,{cs.name}.Out1);", eqn_code)
        self.assertIn(f"connect(SepOut2.In,{cs.name}.Out2);", eqn_code)
        self.assertIn(f"{cs.name}.sepFactVal= {{{{0.9, 0.1}}}};", eqn_code)

    def test_distillation_columns(self):
        dc = DistCol()
        self.assertEqual(dc.type, 'DistCol')
        self.assertTrue(dc.name.startswith('DistCol'))
        self.assertEqual(dc.getname(), dc.name)
        self.assertEqual(dc.modesList(), ["refluxRatio", "sideDrawMolFlo", "T"])
        self.assertEqual(dc.no_of_input, 2)
        self.assertEqual(dc.no_of_output, 2)

        # DistCol refluxRatio mode
        dc_params = dc.paramgetter("refluxRatio")
        dc_params["numStage"] = "10"
        dc_params["numFeeds"] = "1"
        dc_params["feedStages"] = "5"
        dc_params["refluxRatio"] = "1.5"
        dc_params["condensor.P"] = "101325"
        dc_params["reboiler.P"] = "101325"
        dc_params["condType"] = "Total"
        dc.thermoPackage = "Raoults_Law"
        dc.paramsetter(dc_params)
        self.assertEqual(dc.numStage, "10")
        self.assertEqual(dc.modeVal, "1.5")

        feed1 = MagicMock()
        feed1.name = "ColFeed1"
        distillate = MagicMock()
        distillate.name = "Distillate"
        bottoms = MagicMock()
        bottoms.name = "Bottoms"
        bottoms.Prop = {"totMolFlo[1]": 25.0}

        dc.connect([feed1], [distillate, bottoms])

        init_code = dc.OM_Flowsheet_Init(["Benzene", "Toluene"])
        self.assertIn("model Condensor", init_code)
        self.assertIn("model Tray", init_code)
        self.assertIn("model Reboiler", init_code)
        self.assertIn(f"noOfStages=10,noOfFeeds=1,feedStages={{5}},condensor.condType=\"Total\"", init_code)
        self.assertIn(f"Simulator.Streams.Energy_Stream {dc.EngStm1.name};", init_code)
        self.assertIn(f"Simulator.Streams.Energy_Stream {dc.EngStm2.name};", init_code)

        eqn_code = dc.OM_Flowsheet_Eqn(["Benzene", "Toluene"])
        self.assertIn(f"connect({dc.name}.condensor_duty,{dc.EngStm1.name}.In);", eqn_code)
        self.assertIn(f"connect({dc.name}.En2, {dc.EngStm2.name}.In);", eqn_code)
        self.assertIn(f"connect({dc.name}.Out1, Distillate.In);", eqn_code)
        self.assertIn(f"connect({dc.name}.Out2, Bottoms.In);", eqn_code)
        self.assertIn(f"connect(ColFeed1.Out, {dc.name}.In[1]);", eqn_code)
        self.assertIn(f"{dc.name}.refluxRatio=1.5;", eqn_code)
        self.assertIn(f"{dc.name}.reboiler.P=101325;", eqn_code)
        self.assertIn(f"{dc.name}.condensor.P=101325;", eqn_code)

        # DistCol alternative mode (e.g. temperature T)
        dc2 = DistCol()
        dc2_params = dc2.paramgetter("T")
        dc2_params["numStage"] = "8"
        dc2_params["numFeeds"] = "1"
        dc2_params["feedStages"] = "4"
        dc2_params["T"] = "360.0"
        dc2_params["condensor.P"] = "101325"
        dc2_params["reboiler.P"] = "101325"
        dc2_params["condType"] = "Partial"
        dc2.thermoPackage = "Raoults_Law"
        dc2.paramsetter(dc2_params)
        dc2.connect([feed1], [distillate, bottoms])
        dc2.OM_Flowsheet_Init(["Benzene", "Toluene"])
        eqn_code2 = dc2.OM_Flowsheet_Eqn(["Benzene", "Toluene"])
        self.assertIn(f"{dc2.name}.condensor.T=360.0;", eqn_code2)

        # Shortcut Column
        sc = ShortcutColumn()
        self.assertEqual(sc.type, 'ShortCol')
        self.assertTrue(sc.name.startswith('ShortCol'))
        self.assertEqual(sc.getname(), sc.name)
        self.assertEqual(sc.modesList(), [])
        self.assertIn("HKey", sc.paramgetter())

        sc_params = sc.paramgetter()
        sc_params["HKey"] = "2"
        sc_params["LKey"] = "1"
        sc_params["HKeyMolFrac"] = "0.01"
        sc_params["LKeyMolFrac"] = "0.99"
        sc_params["condP"] = "101325"
        sc_params["rebP"] = "105000"
        sc_params["actR"] = "1.5"
        sc_params["condType"] = "Total"
        sc_params["thermoPackage"] = "Raoults_Law"
        sc.paramsetter(sc_params)

        sc.connect([feed1], [distillate, bottoms])

        sc_init = sc.OM_Flowsheet_Init(["Benzene", "Toluene"])
        self.assertIn("extends Simulator.Unit_Operations.Shortcut_Column;", sc_init)
        self.assertIn("condType = \"Total\",HKey = 2,LKey = 1);", sc_init)
        self.assertIn(f"Simulator.Streams.Energy_Stream {sc.EngStm1.name};", sc_init)
        self.assertIn(f"Simulator.Streams.Energy_Stream {sc.EngStm2.name};", sc_init)

        sc_eqn = sc.OM_Flowsheet_Eqn(["Benzene", "Toluene"])
        self.assertIn(f"connect({sc.name}.En2,{sc.EngStm1.name}.Out);", sc_eqn)
        self.assertIn(f"connect({sc.EngStm2.name}.In,{sc.name}.En1);", sc_eqn)
        self.assertIn(f"connect({sc.name}.Out1,Distillate.In);", sc_eqn)
        self.assertIn(f"connect({sc.name}.Out2,Bottoms.In);", sc_eqn)
        self.assertIn(f"connect(ColFeed1.Out,{sc.name}.In);", sc_eqn)
        self.assertIn(f"{sc.name}.rebP = 105000;", sc_eqn)
        self.assertIn(f"{sc.name}.condP = 101325;", sc_eqn)
        self.assertIn(f"{sc.name}.mixMolFrac[2,{sc.name}.LKey]=0.99;", sc_eqn)
        self.assertIn(f"{sc.name}.mixMolFrac[3,{sc.name}.HKey]=0.01;", sc_eqn)
        self.assertIn(f"{sc.name}.actR=1.5;", sc_eqn)

    def test_conversion_reactor(self):
        cr = ConvReactor(
            name="R1",
            Nr=1,
            b=1,
            X=0.85,
            Z=1,
            a=[[-1, 1]],
            operation="Isothermal",
            Tdef=350.15
        )
        self.assertEqual(cr.type, 'ConvReactor')
        self.assertEqual(cr.name, 'R1')
        self.assertEqual(cr.Nr, '1')
        self.assertEqual(cr.b, '1')
        self.assertEqual(cr.X, '0.85')
        self.assertEqual(cr.Z, '1')
        self.assertEqual(cr.a, '{{-1, 1}}')
        self.assertEqual(cr.operation, 'Isothermal')
        self.assertEqual(cr.Tdef, '350.15')

        # Connect streams
        in_stm = MagicMock()
        in_stm.name = "ReactorFeed"
        out_stm = MagicMock()
        out_stm.name = "ReactorProd"
        cr.connect([in_stm], [out_stm])

        self.assertEqual(cr.InputStms, [in_stm])
        self.assertEqual(cr.OutputStms, [out_stm])

        # Test OM_Flowsheet_Init
        init_code = cr.OM_Flowsheet_Init(["A", "B"])
        self.assertIn("Simulator.Streams.Energy_Stream EngStm;", init_code)
        self.assertIn("Simulator.Unit_Operations.ConversionReactor R1", init_code)
        self.assertIn("Nr = 1", init_code)
        self.assertIn("X = 0.85", init_code)
        self.assertIn("a = {{-1, 1}}", init_code)
        self.assertIn("operation = Isothermal", init_code)
        self.assertIn("Tdef = 350.15", init_code)

        # Test OM_Flowsheet_Eqn
        eqn_code = cr.OM_Flowsheet_Eqn(["A", "B"])
        self.assertIn("connect(ReactorFeed.Out,R1.In);", eqn_code)
        self.assertIn("connect(ReactorProd.In,R1.Out);", eqn_code)
        self.assertIn("connect(EngStm.In,R1.energy);", eqn_code)


if __name__ == "__main__":
    unittest.main()
