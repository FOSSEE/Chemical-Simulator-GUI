within Simulator.Generated;

package data
  
  record GeneralProperties "Record to declare the variables for thermophysical properties of the compounds in the database"
      extends Modelica.Icons.Record;
    parameter Integer SN "Serial Number";
    parameter String name "Compound Name";
    parameter String CAS "CAS Number";
    parameter Real Tc (unit="K") "Critical Temperature";
    parameter Real Pc (unit="Pa") "Critical Pressure";
    parameter Real Vc (unit="m3/kmol") "Critical Volume";
    parameter Real Cc (unit="-") "Critical Compressibility Factor";
    parameter Real Tb (unit="K") "Boiling Point Temperature";
    parameter Real Tm (unit="K") "Melting Point Temperature";
    parameter Real TT (unit="K") "Triple Point Temperature";
    parameter Real TP (unit="Pa") "Triple Point Pressure";
    parameter Real MW (unit="-") "Molecular Weight";
    parameter Real LVB (unit="m3/kmol") "Liquid Molar Volume at Normal Boiling Point";
    parameter Real AF (unit="-") "Acentric Factor";
    parameter Real SP (unit="J0.5/m1.5") "Solubility Parameter";
    parameter Real DM (unit="Coulomb.m") "Dipole Moment";
    parameter Real SH (unit="J/kmol") "Absolute Enthalpy";
    parameter Real IGHF (unit="J/kmol") "Standard Heat of Formation";
    parameter Real GEF (unit="J/kmol") "Gibbs Energy of Formation";
    parameter Real AS (unit="J/kmol/K") "Absolute Entropy";
    parameter Real HFMP (unit="J/kmol") "Heat of Fusion at Melting Point";
    parameter Real HOC (unit="J/kmol") "Heat of Combustion";
    parameter Real UniquacR (unit="-") "UNIQUAC r";
    parameter Real UniquacQ (unit="-") "UNIQUAC q";
    parameter Real LiqDen[6] (each unit="kmol/m3") "Liquid Density Coefficients";
    parameter Real VP[6] (each unit="Pa") "Vapor Pressure Coefficients";
    parameter Real LiqCp[6] (each unit="J/kmol/K") "Liquid Heat Capacity Coefficients";
    parameter Real HOV[6] (each unit="J/kmol") "Heat of Vaporization Coefficients";
    parameter Real VapCp[6] (each unit="J/kmol/K") "Ideal Gas Heat Capacity Coefficients";
    parameter Real LiqVis[6] (each unit="Pa s") "Liquid Viscosity Coefficients";
    parameter Real VapVis[6] (each unit="Pa s") "Vapor Viscosity Coefficients";
    parameter Real LiqK[6] (each unit="W/m/K") "Liquid Thermal Conductivity Coefficients";
    parameter Real VapK[6] (each unit="W/m/K") "Vapor Thermal Conductivity Coefficients";
    parameter Real Racketparam (unit="-") "Racket Parameter";
    parameter Real ChaoSeadAF (unit="-") "Chao-Seader Accentric Factor";
    parameter Real ChaoSeadSP (unit="J0.5/m1.5") "Shao-Seader Solubility Parameter";
    parameter Real ChaoSeadLV (unit="m3/kmol") "Chao-Seader Liquid Volume";
  end GeneralProperties;

  
  record Air
      extends Modelica.Icons.Record;
    extends GeneralProperties(SN = 1, name = "Air", CAS = "132259-10-0", Tc = 132.45, Pc = 3774000, Vc = 0.09147, Cc = 0.313, Tb = 78.67, Tm = 59.15, TT = 59.15, TP = 5642.15, MW = 28.96, LVB = 0.0329147, AF = 0, SP = 12750, DM = 0, SH = 0.0, IGHF = 0, GEF = 0, AS = 199000, HFMP = 0, HOC = 0, LiqDen = {105, 2.6731, 0.25637, 132.51, 0.26788, 0}, VP = {101, 14.794, -599.85, 1.0009, -3.9938E-07, 2}, LiqCp = {16, 53628, 4511.1, -143.29, 1.582, -0.0051332}, HOV = {106, 7385651, 0.276676, 0.211253, -0.836764, 0.722737}, VapCp = {100, 29562.29, -7.164949, 0.0216294, -0.0000139748, 2.89195E-09}, LiqVis = {101, -72.336, 813.48, 12.687, -0.00033062, 2}, VapVis = {102, 0.000001592, 0.48975, 123.45, -829.58, 0}, LiqK = {16, -0.21199, -16.311, -0.23057, -0.0076197, 0.0000025018}, VapK = {102, 0.0003511, 0.76492, 16.071, 1084.4, 0}, Racketparam = 0.29056, UniquacR = 0, UniquacQ = 0, ChaoSeadAF = -0.00787976, ChaoSeadSP = 12749.8, ChaoSeadLV = 0.0329147);
  end Air;

  
  record Argon
      extends Modelica.Icons.Record;
    extends GeneralProperties(SN = 2, name = "Argon", CAS = "7440-37-1", Tc = 150.86, Pc = 4898000, Vc = 0.07457, Cc = 0.291, Tb = 87.27, Tm = 83.8039, TT = 83.8, TP = 68906.1, MW = 39.948, LVB = 0.0291, AF = -0.002, SP = 14138.3, DM = 0, SH = 0.0, IGHF = 0, GEF = 0, AS = 154732, HFMP = 1184900, HOC = 0, LiqDen = {105, 3.803, 0.286, 150.86, 0.2984, 0}, VP = {101, 44.369, -1126.1, -4.5688, 0.000062339, 2}, LiqCp = {16, 46085, -1304.5, 21.195, -0.015382, 0.000033063}, HOV = {106, 7981000, 0.099752, 0.32009, -0.11898, 0.031141}, VapCp = {16, 20786, 0, 0, 0, 0}, LiqVis = {101, -99.903, 1347.5, 17.615, -0.00032893, 2}, VapVis = {102, 0.0000010023, 0.5922, 85.563, 238.26, 0}, LiqK = {16, -0.30397, -0.82999, -0.71462, -0.00039294, -0.000012209}, VapK = {102, 0.00013095, 0.81923, -122.33, 13993, 0}, Racketparam = 0, UniquacR = 1.1074, UniquacQ = 1.068, ChaoSeadAF = -0.002, ChaoSeadSP = 14138.3, ChaoSeadLV = 0.0285865);
  end Argon;

  
  record Bromine
      extends Modelica.Icons.Record;
    extends GeneralProperties(SN = 3, name = "Bromine", CAS = "7726-95-6", Tc = 584.15, Pc = 1.03E+07, Vc = 0.135, Cc = 0.286, Tb = 331.9, Tm = 265.9, TT = 265.85, TP = 5853.37, MW = 159.808, LVB = 0.0514795, AF = 0.128997, SP = 23590, DM = 0, SH = 0.0, IGHF = 3.091E+07, GEF = 3140000, AS = 245350, HFMP = 1.057E+07, HOC = 0, LiqDen = {105, 2.0603, 0.28982, 584.15, 0.28948, 0}, VP = {101, 63.657, -5321.6, -6.3199, 0.0000054412, 2}, LiqCp = {16, 75351, -4.87E+07, 54033, 102.73, 0.43775}, HOV = {106, 3.8419E+07, -0.26282, 2.1808, -2.7529, 1.1823}, VapCp = {16, 35000, -410, 8.5, -0.00016, -0.00000001}, LiqVis = {101, -5.9813, 410.55, -0.30036, -0.000006936, 2}, VapVis = {102, 1.1438E-07, 0.88111, 59.595, -6723.3, 0}, LiqK = {16, -0.69183, 27.775, -0.38966, 0.00057103, -8.8462E-07}, VapK = {102, 0.0000065648, 1.4785, 4505.6, -870500, 0}, Racketparam = 0.279241, UniquacR = 1.8985, UniquacQ = 1.672, ChaoSeadAF = 0.108, ChaoSeadSP = 23591.8, ChaoSeadLV = 0.0514795);
  end Bromine;

end data;
