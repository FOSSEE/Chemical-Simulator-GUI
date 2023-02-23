within Simulator.BinaryPhaseEnvelope;

package BinaryPhaseEnvelopeNRTL
  extends Modelica.Icons.ExamplesPackage;
  model NRTLmodel
    import Simulator.Files.ThermodynamicFunctions.*;
    gammaNRTLmodel Gamma(Nc = Nc, comp = comp, molFrac = x[:], T = T);
    Real density[Nc], BIPS[Nc, Nc, 2];
  equation
    gamma = Gamma.gamma;
    BIPS = Gamma.BIPS;
    for i in 1:Nc loop
      density[i] = Dens(comp[i].LiqDen, comp[i].Tc, T, P);
    end for;
    for i in 1:Nc loop
      K[i] = gamma[i] * Psat(comp[i].VP, T) / P;
    end for;
  end NRTLmodel;

  model gammaNRTLmodel
    parameter Integer Nc;
    parameter Simulator.Files.ChemsepDatabase.GeneralProperties comp[Nc];
    Real molFrac[Nc], T;
    Real gamma[Nc];
    Real tau[Nc, Nc], G[Nc, Nc], alpha[Nc, Nc], A[Nc, Nc], BIPS[Nc, Nc, 2];
    Real sum1[Nc], sum2[Nc];
    constant Real R = 1.98721;
  equation
    A = BIPS[:, :, 1];
    alpha = BIPS[:, :, 2];
    tau = A ./ (R * T);
    for i in 1:Nc loop
      for j in 1:Nc loop
        G[i, j] = exp(-alpha[i, j] * tau[i, j]);
      end for;
    end for;
    for i in 1:Nc loop
      sum1[i] = sum(molFrac[:] .* G[:, i]);
      sum2[i] = sum(molFrac[:] .* tau[:, i] .* G[:, i]);
    end for;
    for i in 1:Nc loop
      log(gamma[i]) = sum(molFrac[:] .* tau[:, i] .* G[:, i]) / sum(molFrac[:] .* G[:, i]) + sum(molFrac[:] .* G[i, :] ./ sum1[:] .* (tau[i, :] .- sum2[:] ./ sum1[:]));
    end for;
  end gammaNRTLmodel;

  model base
    import data = Simulator.Files.ChemsepDatabase;
    parameter Integer Nc;
    parameter Real BIP[Nc, Nc, 2];
    parameter data.GeneralProperties comp[Nc];
    extends NRTLmodel(BIPS = BIP);
    Real P, T(start = 300), gamma[Nc], K[Nc], x[Nc](each start = 0.5), y[Nc];
  equation
    y[:] = K[:] .* x[:];
    sum(x[:]) = 1;
    sum(y[:]) = 1;
  end base;

  model OnehexeneAcetoneTxy
    extends Modelica.Icons.Example;
    import data = Simulator.Files.ChemsepDatabase;
    parameter data.Onehexene ohex;
    parameter data.Acetone acet;
    parameter Integer Nc = 2;
    parameter Real BIP[Nc, Nc, 2] = Simulator.Files.ThermodynamicFunctions.BIPNRTL(Nc, comp.CAS);
    parameter data.GeneralProperties comp[Nc] = {ohex, acet};
    base points[41](each P = 1013250, each Nc = Nc, each comp = comp, each BIP = BIP);
    Real x[41, Nc], y[41, Nc], T[41];
  equation
    points[:].x = x;
    points[:].y = y;
    points[:].T = T;
    for i in 1:41 loop
      x[i, 1] = 0 + (i - 1) * 0.025;
    end for;
  end OnehexeneAcetoneTxy;

  model OnehexeneAcetonePxy
    extends Modelica.Icons.Example;
    import data = Simulator.Files.ChemsepDatabase;
    parameter data.Onehexene ohex;
    parameter data.Acetone acet;
    parameter Integer Nc = 2;
    parameter Real BIP[Nc, Nc, 2] = Simulator.Files.ThermodynamicFunctions.BIPNRTL(Nc, comp.CAS);
    parameter data.GeneralProperties comp[Nc] = {ohex, acet};
    base points[41](each T = 424, each Nc = Nc, each comp = comp, each BIP = BIP);
    Real x[41, Nc], y[41, Nc], P[41];
  equation
    points[:].x = x;
    points[:].y = y;
    points[:].P = P;
    for i in 1:41 loop
      x[i, 1] = 0 + (i - 1) * 0.025;
    end for;
  end OnehexeneAcetonePxy;
end BinaryPhaseEnvelopeNRTL;
