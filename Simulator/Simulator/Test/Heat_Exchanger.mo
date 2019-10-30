within Simulator.Test;

package Heat_Exchanger
  //Model of a General Purpouse Heat Exchanger operating with multiple modes
  //================================================================================================================

  model MS
    extends Simulator.Streams.Material_Stream;
    //material stream extended
    extends Simulator.Files.Thermodynamic_Packages.Raoults_Law;
    //thermodynamic package Raoults law is extended
  end MS;

  model HX_Test
    import data = Simulator.Files.Chemsep_Database;
    //instantiation of ethanol
    parameter data.Styrene sty;
    //instantiation of acetic acid
    parameter data.Toluene tol;
    parameter Integer NOC = 2;
    parameter data.General_Properties comp[NOC] = {sty, tol};
    Simulator.Unit_Operations.Rigorous_HX HX(NOC = NOC, comp = comp, deltap_hot = 0, deltap_cold = 0, Heat_Loss = 0, Calculation_Method = "Outlet_Temparatures") annotation(
      Placement(visible = true, transformation(origin = {-34, 8}, extent = {{-16, -16}, {16, 16}}, rotation = 0)));
    Simulator.Test.Heat_Exchanger.MS Hot_In(NOC = NOC, comp = comp) annotation(
      Placement(visible = true, transformation(origin = {-80, 6}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
    Simulator.Test.Heat_Exchanger.MS Hot_Out(NOC = NOC, comp = comp) annotation(
      Placement(visible = true, transformation(origin = {48, 70}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
    Simulator.Test.Heat_Exchanger.MS Cold_In(NOC = NOC, comp = comp) annotation(
      Placement(visible = true, transformation(origin = {-78, 68}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
    Simulator.Test.Heat_Exchanger.MS Cold_Out(NOC = NOC, comp = comp) annotation(
      Placement(visible = true, transformation(origin = {54, -58}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  equation
  connect(Cold_In.outlet, HX.Cold_In) annotation(
      Line(points = {{-68, 68}, {-34, 68}, {-34, 24}}));
  connect(Hot_In.outlet, HX.Hot_In) annotation(
      Line(points = {{-70, 6}, {-56, 6}, {-56, 8}, {-50, 8}}));
  connect(HX.Cold_Out, Cold_Out.inlet) annotation(
      Line(points = {{-33, -8}, {-33, -58}, {44, -58}}));
  connect(HX.Hot_Out, Hot_Out.inlet) annotation(
      Line(points = {{-18, 8}, {-18, 45}, {38, 45}, {38, 70}}));
    Hot_In.compMolFrac[1, :] = {1, 0};
    Cold_In.compMolFrac[1, :] = {0, 1};
    Hot_In.totMolFlo[1] = 181.46776;
    Cold_In.totMolFlo[1] = 170.93083;
    Hot_In.T = 422.03889;
    Cold_In.T = 310.92778;
    Hot_In.P = 344737.24128;
    Cold_In.P = 620527.03429;
    HX.U = 300;
    HX.Qactual = 2700E03;
  end HX_Test;
end Heat_Exchanger;
