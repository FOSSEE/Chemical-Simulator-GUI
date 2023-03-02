#if defined(__cplusplus)
  extern "C" {
#endif
  int Flowsheet_mayer(DATA* data, modelica_real** res, short*);
  int Flowsheet_lagrange(DATA* data, modelica_real** res, short *, short *);
  int Flowsheet_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int Flowsheet_setInputData(DATA *data, const modelica_boolean file);
  int Flowsheet_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif