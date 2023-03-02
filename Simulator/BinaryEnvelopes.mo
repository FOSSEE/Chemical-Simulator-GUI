package BinaryEnvelopes
  model NRTL
    parameter Integer Nc;  
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
      x[i, 1] = 0 + (i - 1) * 1/(data_points-1);
    end for; 
  end NRTL;





end BinaryEnvelopes;
