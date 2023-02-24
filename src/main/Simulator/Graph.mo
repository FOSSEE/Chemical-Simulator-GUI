model Graph
import data = Simulator.Files.ChemsepDatabase;
parameter data.Benzene comp1;
parameter data.Toluene comp2;
extends BinaryEnvelopes.RaoultsLaw(Nc = 2, data_points = 40, comp = { comp1, comp2 }, P = fill( 25000, 40));
end Graph;