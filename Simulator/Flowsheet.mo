model Flowsheet
parameter database.Benzene Benzene; 
parameter database.Toluene Toluene; 
parameter Integer Nc = 2;
parameter Simulator.Files.ChemsepDatabase.GeneralProperties C[Nc] = {Benzene, Toluene};
model ms1
extends Simulator.Streams.MaterialStream;
extends Simulator.Files.ThermodynamicPackages.RaoultsLaw;
end ms1;
ms1 MaterialStream1(Nc = 2,C = {Benzene, Toluene});
model ms2
extends Simulator.Streams.MaterialStream;
extends Simulator.Files.ThermodynamicPackages.RaoultsLaw;
end ms2;
ms2 MaterialStream2(Nc = 2,C = {Benzene, Toluene});
Simulator.UnitOperations.Heater Heater1(Nc = 2,C = {Benzene, Toluene}, Pdel = 0, Eff = 1);
equation
MaterialStream1.P = 101325.0;
MaterialStream1.T = 350;
MaterialStream1.x_pc[1,:] = {0.5, 0.5};
MaterialStream1.F_p[1] = 100.0;
connect(Heater1.In,MaterialStream1.Out);
connect(Heater1.Out,MaterialStream2.In);
Heater1.Tout=380;
end Flowsheet;
