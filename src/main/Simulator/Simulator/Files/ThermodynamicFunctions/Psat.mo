within Simulator.Files.ThermodynamicFunctions;

  function Psat
    extends Modelica.Icons.Function;
    /*Returns vapor pressure at given temperature*/
    input Real VP[6] "from chemsep database";
    input Real T(unit = "K") "Temperature";
    output Real Pvap(unit = "Pa") "Vapor pressure";
  protected
    Real T_safe;
  algorithm
    T_safe := max(T, 1);
    Pvap := exp(VP[2] + VP[3] / T_safe + VP[4] * log(T_safe) + VP[5] .* T_safe .^ VP[6]);
  end Psat;
