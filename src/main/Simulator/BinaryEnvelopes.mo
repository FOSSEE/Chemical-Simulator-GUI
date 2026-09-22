package BinaryEnvelopes

  model RaoultsLawBase
    import data = Simulator.Files.ChemsepDatabase;
    parameter Integer Nc = 2;
    parameter data.GeneralProperties comp[Nc];
    Real P(start = 101325, min = 100), T(start = 350, min = 100, max = 2000), K[Nc], x[Nc](each start = 0.5, each min = 0, each max = 1), y[Nc](each min = 0, each max = 1);
  equation
    for i in 1:Nc loop
      K[i] = Simulator.Files.ThermodynamicFunctions.Psat(comp[i].VP, T) / P;
    end for;
    y[:] = K[:] .* x[:];
    sum(x[:]) = 1;
    sum(y[:]) = 1;
  end RaoultsLawBase;

  model RaoultsLaw
    parameter Integer Nc = 2;  
    parameter Integer data_points;
    parameter Simulator.Files.ChemsepDatabase.GeneralProperties comp[Nc];
    RaoultsLawBase points[data_points](each comp = comp);
    Real x[data_points, Nc], y[data_points, Nc], P[data_points], T[data_points];
  equation
    points[:].x = x;
    points[:].y = y;
    points[:].P = P;
    points[:].T = T;
    for i in 1:data_points loop
      x[i, 1] = 0.0 + (i - 1) * 1.0 / (data_points - 1);
    end for; 
  end RaoultsLaw;

  model NRTL
    parameter Integer Nc = 2;  
    parameter Integer data_points;
    parameter Real BIP[Nc, Nc, 2] = Simulator.Files.ThermodynamicFunctions.BIPNRTL(Nc, comp.CAS);
    parameter Simulator.Files.ChemsepDatabase.GeneralProperties comp[Nc];
    Simulator.BinaryPhaseEnvelope.BinaryPhaseEnvelopeNRTL.base points[data_points](each Nc = Nc, each comp = comp, each BIP = BIP);
    Real x[data_points, Nc], y[data_points, Nc], P[data_points], T[data_points];
  equation
    points[:].x = x;
    points[:].y = y;
    points[:].P = P;
    points[:].T = T;
    for i in 1:data_points loop
      x[i, 1] = 0.0 + (i - 1) * 1.0 / (data_points - 1);
    end for; 
  end NRTL;

end BinaryEnvelopes;
