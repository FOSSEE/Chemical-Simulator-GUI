within Simulator.UnitOperations;

model Mixer "Model of a mixer to mix multiple material streams"
  extends Simulator.Files.Icons.Mixer;
  import Simulator.Files.*;
  parameter ChemsepDatabase.GeneralProperties C[Nc];
  parameter Integer Nc "Number of components";
  parameter Integer NI = 6 "Number of inlet streams";
  
  Real Pin[NI](unit = "Pa", min = 0, start = Pg) "Inlet stream pressure";
  Real xin_sc[NI, Nc](each unit = "-", each min = 0, each max = 1) "Inlet stream component mol fraction";
  Real Fin_s[NI](each unit = "mol/s", each min = 0, each start = Fg) "Inlet stream Molar Flow";
  Real Hin_s[NI](each unit = "kJ/kmol") "Inlet stream molar enthalpy";
  Real Tin_s[NI](each unit = "K", each min = 0, each start = Tg) "Inlet stream temperature";
  Real Sin_s[NI](each unit = "kJ/[kmol.K]") "Inlet stream molar entropy";
  Real xvapin_s[NI](each unit = "-", each min = 0, each max = 1, each start = xvapg) "Inlet stream vapor phase mol fraction";
  
  parameter String outPress "Calculation mode for outet pressure: Inlet_Minimum, Inlet_Average, Inlet_Maximum";
  
  Real Fout(unit = "mol/s", each min = 0, each start = Fg) "Outlet stream molar flow";
  Real Pout(unit = "Pa", min = 0, start = Pg) "Outlet stream pressure";
  Real Hout(unit = "kJ/kmol") "Outlet stream molar enthalpy";
  Real Tout(unit = "K", each min = 0, each start = Tg) "Outlet stream temperature";
  Real Sout(unit = "kJ/[kmol.K]") "Outlet stream molar entropy";
  Real xvapout(unit = "-", min = 0, max = 1, start = xvapg) "Outlet stream vapor phase mol fraction";
  Real xout_c[Nc](each unit = "-", each min = 0, each max = 1, start = xguess) "Outlet stream component mol fraction";
 //================================================================================
  //  Files.Interfaces.matConn inlet[NI](each Nc = Nc);
  Simulator.Files.Interfaces.matConn outlet(Nc = Nc) annotation(
    Placement(visible = true, transformation(origin = {100, -2}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {100, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Simulator.Files.Interfaces.matConn inlet[NI](each Nc = Nc) annotation(
    Placement(visible = true, transformation(origin = {-100, -2}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-100, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  
  extends GuessModels.InitialGuess;
  
equation
//Connector equation
  for i in 1:NI loop
    inlet[i].P = Pin[i];
    inlet[i].T = Tin_s[i];
    inlet[i].F = Fin_s[i];
    inlet[i].H = Hin_s[i];
    inlet[i].S = Sin_s[i];
    inlet[i].x_pc[1, :] = xin_sc[i, :];
    inlet[i].xvap = xvapin_s[i];
  end for;
  outlet.P = Pout;
  outlet.T = Tout;
  outlet.F = Fout;
  outlet.H = Hout;
  outlet.S = Sout;
  outlet.x_pc[1, :] = xout_c[:];
  outlet.xvap = xvapout;
//===================================================================================
//Output Pressure
  if outPress == "Inlet_Minimum" then
    Pout = min(Pin);
  elseif outPress == "Inlet_Average" then
    Pout = sum(Pin) / NI;
  elseif outPress == "Inlet_Maximum" then
    Pout = max(Pin);
  end if;
//Molar Balance
  Fout = sum(Fin_s[:]);
  for i in 1:Nc loop
    xout_c[i] * Fout = sum(xin_sc[:, i] .* Fin_s[:]);
  end for;
//Energy balance
  Hout = sum(Hin_s[:] .* Fin_s[:] / Fout);

annotation(
    Documentation(info = "<html><head></head><body><!--StartFragment--><span style=\"font-family: Arial, Helvetica, sans-serif; font-size: 13.3333px; orphans: 2; widows: 2;\">The Mixer is used to mix up to any number of material streams into one, while executing all the mass and energy balances.</span><div style=\"orphans: 2; widows: 2;\"><font face=\"Arial, Helvetica, sans-serif\"><span style=\"font-size: 13px;\"><br></span></font></div><div style=\"orphans: 2; widows: 2;\"><font face=\"Arial, Helvetica, sans-serif\"><span style=\"font-size: 13px;\">The only calculation parameter for mixer is the outlet pressure calculation (<b>Pout</b>). It can be calculated in three different modes:</span></font></div><div style=\"orphans: 2; widows: 2;\"><ol><li><font face=\"Arial, Helvetica, sans-serif\"><span style=\"font-size: 13px;\"><b>Inlet_Minimum</b>: Outlet pressure is taken as minimum of all inlet streams pressure</span></font></li><li><font face=\"Arial, Helvetica, sans-serif\"><span style=\"font-size: 13px;\"><b>Inlet_Average</b></span></font><span style=\"font-family: Arial, Helvetica, sans-serif; font-size: 13px;\">: Outlet pressure is calculated as average of all inlet streams pressure</span></li><li><font face=\"Arial, Helvetica, sans-serif\"><span style=\"font-size: 13px;\"><b>Inlet_Maximum</b></span></font><span style=\"font-family: Arial, Helvetica, sans-serif; font-size: 13px;\">: Outlet pressure is taken as maximum of all inlet streams pressure</span></li></ol><div><font face=\"Arial, Helvetica, sans-serif\"><span style=\"font-size: 13px;\"><br></span></font></div><div><span style=\"font-size: 12px; orphans: auto; widows: auto;\">For examples on simulating mixer, go to&nbsp;</span><b style=\"font-size: 12px; orphans: auto; widows: auto;\"><i>Examples</i></b><span style=\"font-size: 12px; orphans: auto; widows: auto;\">&nbsp;&gt;&gt;&nbsp;</span><i style=\"font-size: 12px; orphans: auto; widows: auto;\"><b>Mixer</b></i></div><p style=\"font-family: Arial, Helvetica, sans-serif; font-size: 13.3333px; orphans: 2; widows: 2;\"></p><br class=\"Apple-interchange-newline\"><!--EndFragment--></div></body></html>"));
    end Mixer;
