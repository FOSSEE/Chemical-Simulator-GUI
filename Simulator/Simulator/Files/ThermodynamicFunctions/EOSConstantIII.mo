within Simulator.Files.ThermodynamicFunctions;

function EOSConstantIII
  extends Modelica.Icons.Function;
  input Integer Nc;
  input Real a[Nc];
  output Real a_ij[Nc, Nc];
algorithm
  for i in 1:Nc loop
    a_ij[i, :] := (a[i] .* a[:]) .^ 0.5;
  end for;
end EOSConstantIII;
