package Simulator
  /* This aims to be steady state chemical engineering process simulator. Currently this contains Chemsep Database(contains more than 400 compounds), thermodynamic packages, Various themodynamic functions , Material stream(generic flash unit) and some generic unit operations and some Tests of these models*/
  /* Chemsep Database is created by "Rahul Jain" and modified by "Pravin Dalve"*/
  extends Modelica.Icons.Package;
  
  // Updated paths for Modelica 4.x
  import SI = Modelica.Units.SI;
  import Cv = Modelica.Units.Conversions;

  annotation(
    uses(Modelica)); 
end Simulator;

