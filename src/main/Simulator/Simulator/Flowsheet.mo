package Mixer1

  model ms
    extends Simulator.Streams.MaterialStream;
    extends Simulator.Files.ThermodynamicPackages.RaoultsLaw;
  end ms;

  model Mixer1Simulation 
    import data = Simulator.Files.ChemsepDatabase;
    parameter Integer Nc = 0;
    parameter data.GeneralProperties C[Nc] = {};
    Simulator.UnitOperations.Mixer Mixer1(Nc = 2,C = {Water, Ethanol}, NI = 2, outPress = "Inlet_Average");

    ms MaterialStream1(Nc = 0, C = {});
    ms MaterialStream2(Nc = 0, C = {});
    ms MaterialStream3(Nc = 0, C = {});
    Simulator.UnitOperations.Heater Heater1(Nc = 2,C = {Water, Ethanol}, Pdel = 0, Eff = 1);


  equation
connect(MaterialStream1.Out, Mixer1.In[1]);
connect(MaterialStream2.Out, Mixer1.In[2]);
connect(Mixer1.Out, MaterialStream3.In);
MaterialStream1.P = 101325;
MaterialStream1.T = 300;
MaterialStream1.F_p[1] = 100;
MaterialStream2.P = 101325;
MaterialStream2.T = 300;
MaterialStream2.F_p[1] = 100;
MaterialStream3.P = 101325;
MaterialStream3.T = 300;
MaterialStream3.F_p[1] = 100;
// Warning: Heater1 has no input streams
// Warning: Heater1 has no output streams
Heater1.Q = None;
  end Mixer1Simulation;
end Mixer1;
