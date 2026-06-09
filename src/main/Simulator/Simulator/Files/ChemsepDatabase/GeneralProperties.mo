within Simulator.Files.ChemsepDatabase;
//OMC 4.x treatas '-' as minus symbol and unit is dimensionless so using '1' is needed.
record GeneralProperties "Model to declare the variables for thermophysical properties of the compounds in the database"
    extends Modelica.Icons.Record;
  parameter Integer SN "Serial Number";
  parameter String name "Compound Name";
  parameter String CAS "CAS Number";
  parameter Real Tc (unit="K") "Critical Temperature";
  parameter Real Pc (unit="Pa") "Critical Pressure";
  parameter Real Vc (unit="m3/kmol") "Critical Volume";
  parameter Real Cc (unit="1") "Critical Compressibility Factor";
  parameter Real Tb (unit="K") "Boiling Point Temperature";
  parameter Real Tm (unit="K") "Melting Point Temperature";
  parameter Real TT (unit="K") "Triple Point Temperature";
  parameter Real TP (unit="Pa") "Triple Point Pressure";
  parameter Real MW (unit="1") "Molecular Weight";
  parameter Real LVB (unit="m3/kmol") "Liquid Molar Volume at Normal Boiling Point";
  parameter Real AF (unit="1") "Acentric Factor";
  parameter Real SP (unit="J0.5/m1.5") "Solubility Parameter";
  parameter Real DM (unit="Coulomb.m") "Dipole Moment";
  parameter Real SH (unit="J/kmol") "Absolute Enthalpy";
  parameter Real IGHF (unit="J/kmol") "Standard Heat of Formation";
  parameter Real GEF (unit="J/kmol") "Gibbs Energy of Formation";
  parameter Real AS (unit="J/kmol/K") "Absolute Entropy";
  parameter Real HFMP (unit="J/kmol") "Heat of Fusion at Melting Point";
  parameter Real HOC (unit="J/kmol") "Heat of Combustion";
  parameter Real UniquacR (unit="1") "UNIQUAC r";
  parameter Real UniquacQ (unit="1") "UNIQUAC q";
  
  // Added 'each' to all array modifications below
  parameter Real LiqDen[6] (each unit="kmol/m3") "Liquid Density Coefficients";
  parameter Real VP[6] (each unit="Pa") "Vapor Pressure Coefficients";
  parameter Real LiqCp[6] (each unit="J/kmol/K") "Liquid Heat Capacity Coefficients";
  parameter Real HOV[6] (each unit="J/kmol") "Heat of Vaporization Coefficients";
  parameter Real VapCp[6] (each unit="J/kmol/K") "Ideal Gas Heat Capacity Coefficients";
  parameter Real LiqVis[6] (each unit="Pa.s") "Liquid Viscosity Coefficients";
  parameter Real VapVis[6] (each unit="Pa.s") "Vapor Viscosity Coefficients";
  parameter Real LiqK[6] (each unit="W/m/K") "Liquid Thermal Conductivity Coefficients";
  parameter Real VapK[6] (each unit="W/m/K") "Vapor Thermal Conductivity Coefficients";
  parameter Real Racketparam (unit="1") "Racket Parameter";
  parameter Real ChaoSeadAF (unit="1") "Chao-Seader Accentric Factor";
  parameter Real ChaoSeadSP (unit="J0.5/m1.5") "Shao-Seader Solubility Parameter";
  parameter Real ChaoSeadLV (unit="m3/kmol") "Chao-Seader Liquid Volume";
end GeneralProperties;
