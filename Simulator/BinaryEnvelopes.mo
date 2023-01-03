package BinaryEnvelopes
  model NRTL
    parameter Integer NOC;  
    parameter Integer data_points;
    parameter Real BIP[NOC, NOC, 2] = Simulator.Files.Thermodynamic_Functions.BIPNRTL(NOC, comp.CAS);
    parameter Simulator.Files.Chemsep_Database.General_Properties comp[NOC];
    Simulator.Binary_Phase_Envelope.Binary_Phase_Envelope_NRTL.base points[data_points](each NOC = NOC, each comp = comp, each BIP = BIP);
    Real x[data_points, NOC], y[data_points, NOC], P[data_points], T[data_points];
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
