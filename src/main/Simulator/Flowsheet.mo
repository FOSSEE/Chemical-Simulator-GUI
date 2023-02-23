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
Simulator.UnitOperations.Mixer Mixer1(Nc = 2,C = {Benzene, Toluene}, NI = 2, outPress = "Inlet_Maximum");
model ms3
extends Simulator.Streams.MaterialStream;
extends Simulator.Files.ThermodynamicPackages.RaoultsLaw;
end ms3;
ms3 MaterialStream3(Nc = 2,C = {Benzene, Toluene});
equation
MaterialStream1.P = 101325;
MaterialStream1.T = 250;
MaterialStream1.x_pc[1,:] = {0.7, 0.3};
MaterialStream1.F_p[1] = 100;
MaterialStream2.P = 101325;
MaterialStream2.T = 300;
MaterialStream2.x_pc[1,:] = {0.5, 0.5};
MaterialStream2.F_p[1] = 100;
connect(MaterialStream1.Out,Mixer1.In[1]);
connect(MaterialStream2.Out,Mixer1.In[2]);
connect(Mixer1.Out,MaterialStream3.In);
end Flowsheet;
