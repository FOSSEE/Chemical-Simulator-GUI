within Simulator.Files.ThermodynamicFunctions;

function EOSConstantII
  extends Modelica.Icons.Function;
  parameter Real R_gas = 8.314;
  input Integer Nc;
  input Real Tc[Nc], Pc[Nc];
  input Real T;
  output Real b[Nc];
algorithm
  for i in 1:Nc loop
    b[i] := 0.08664 * R_gas * (Tc[i] / Pc[i]);
  end for;
end EOSConstantII;
