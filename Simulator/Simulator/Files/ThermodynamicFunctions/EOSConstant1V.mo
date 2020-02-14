within Simulator.Files.ThermodynamicFunctions;

function EOSConstant1V
  extends Modelica.Icons.Function;
  input Integer Nc;
  input Real compMolFrac[Nc];
  input Real a_ij[Nc, Nc];
  output Real amv;
protected
  Real amvv[Nc];
algorithm
  for i in 1:Nc loop
    amvv[i] := sum(compMolFrac[i] .* compMolFrac[:] .* a_ij[i, :]);
  end for;
  amv := sum(amvv[:]);
end EOSConstant1V;
