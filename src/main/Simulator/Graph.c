/* Main Simulation File */
#include "Graph_model.h"

#define prefixedName_performSimulation Graph_performSimulation
#define prefixedName_updateContinuousSystem Graph_updateContinuousSystem
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation Graph_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int Graph_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Graph_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Graph_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Graph_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Graph_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
 equation index: 995
 type: SIMPLE_ASSIGN
 y[40,1] = 1.0
 */
void Graph_eqFunction_995(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,995};
  data->localData[0]->realVars[1112] /* y[40,1] variable */ = 1.0;
  TRACE_POP
}
void Graph_eqFunction_996(DATA*,threadData_t*);
void Graph_eqFunction_997(DATA*,threadData_t*);
void Graph_eqFunction_998(DATA*,threadData_t*);
void Graph_eqFunction_999(DATA*,threadData_t*);
void Graph_eqFunction_1000(DATA*,threadData_t*);
void Graph_eqFunction_1001(DATA*,threadData_t*);
void Graph_eqFunction_1002(DATA*,threadData_t*);
/*
 equation index: 1003
 indexNonlinear: 40
 type: NONLINEAR
 
 vars: {T[1]}
 eqns: {996, 997, 998, 999, 1000, 1001, 1002}
 */
void Graph_eqFunction_1003(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1003};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1003 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[40].nlsxOld[0] = data->localData[0]->realVars[200] /* T[1] variable */;
  retValue = solve_nonlinear_system(data, threadData, 40);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1003};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1003 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[200] /* T[1] variable */ = data->simulationInfo->nonlinearSystemData[40].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1004
 type: SIMPLE_ASSIGN
 $cse3 = Simulator.Files.ThermodynamicFunctions.Psat({points[1].comp[1].VP[1], points[1].comp[1].VP[2], points[1].comp[1].VP[3], points[1].comp[1].VP[4], points[1].comp[1].VP[5], points[1].comp[1].VP[6]}, T[1])
 */
void Graph_eqFunction_1004(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1004};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[11284], (modelica_real)data->simulationInfo->realParameter[11285], (modelica_real)data->simulationInfo->realParameter[11286], (modelica_real)data->simulationInfo->realParameter[11287], (modelica_real)data->simulationInfo->realParameter[11288], (modelica_real)data->simulationInfo->realParameter[11289]);
  data->localData[0]->realVars[83] /* $cse3 variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->localData[0]->realVars[200] /* T[1] variable */);
  TRACE_POP
}
/*
 equation index: 1005
 type: SIMPLE_ASSIGN
 points[1]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[1].comp[2].LiqDen[1], points[1].comp[2].LiqDen[2], points[1].comp[2].LiqDen[3], points[1].comp[2].LiqDen[4], points[1].comp[2].LiqDen[5], points[1].comp[2].LiqDen[6]}, points[1].comp[2].Tc, T[1], 10000.0)
 */
void Graph_eqFunction_1005(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1005};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8890], (modelica_real)data->simulationInfo->realParameter[8891], (modelica_real)data->simulationInfo->realParameter[8892], (modelica_real)data->simulationInfo->realParameter[8893], (modelica_real)data->simulationInfo->realParameter[8894], (modelica_real)data->simulationInfo->realParameter[8895]);
  data->localData[0]->realVars[795] /* points[1]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10965], data->localData[0]->realVars[200] /* T[1] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1006
 type: SIMPLE_ASSIGN
 points[1]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[1].comp[1].LiqDen[1], points[1].comp[1].LiqDen[2], points[1].comp[1].LiqDen[3], points[1].comp[1].LiqDen[4], points[1].comp[1].LiqDen[5], points[1].comp[1].LiqDen[6]}, points[1].comp[1].Tc, T[1], 10000.0)
 */
void Graph_eqFunction_1006(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1006};
  real_array tmp2;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[8884], (modelica_real)data->simulationInfo->realParameter[8885], (modelica_real)data->simulationInfo->realParameter[8886], (modelica_real)data->simulationInfo->realParameter[8887], (modelica_real)data->simulationInfo->realParameter[8888], (modelica_real)data->simulationInfo->realParameter[8889]);
  data->localData[0]->realVars[794] /* points[1]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp2, data->simulationInfo->realParameter[10964], data->localData[0]->realVars[200] /* T[1] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1007
 type: SIMPLE_ASSIGN
 points[1]._Gamma._tau[2,1] = 0.5032180796191645 * DIVISION(points[1].BIP[2,1,1], T[1])
 */
void Graph_eqFunction_1007(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1007};
  data->localData[0]->realVars[558] /* points[1]._Gamma._tau[2,1] variable */ = (0.5032180796191645) * (DIVISION_SIM(data->simulationInfo->realParameter[328],data->localData[0]->realVars[200] /* T[1] variable */,"T[1]",equationIndexes));
  TRACE_POP
}
/*
 equation index: 1008
 type: SIMPLE_ASSIGN
 points[1]._Gamma._sum1[1] = exp((-points[1].BIP[2,1,2]) * points[1].Gamma.tau[2,1])
 */
void Graph_eqFunction_1008(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1008};
  data->localData[0]->realVars[396] /* points[1]._Gamma._sum1[1] variable */ = exp(((-data->simulationInfo->realParameter[329])) * (data->localData[0]->realVars[558] /* points[1]._Gamma._tau[2,1] variable */));
  TRACE_POP
}
/*
 equation index: 1009
 type: SIMPLE_ASSIGN
 points[1]._Gamma._sum2[1] = points[1].Gamma.tau[2,1] * points[1].Gamma.sum1[1]
 */
void Graph_eqFunction_1009(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1009};
  data->localData[0]->realVars[476] /* points[1]._Gamma._sum2[1] variable */ = (data->localData[0]->realVars[558] /* points[1]._Gamma._tau[2,1] variable */) * (data->localData[0]->realVars[396] /* points[1]._Gamma._sum1[1] variable */);
  TRACE_POP
}
/*
 equation index: 1010
 type: SIMPLE_ASSIGN
 points[1]._Gamma._tau[1,2] = 0.5032180796191645 * DIVISION(points[1].BIP[1,2,1], T[1])
 */
void Graph_eqFunction_1010(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1010};
  data->localData[0]->realVars[557] /* points[1]._Gamma._tau[1,2] variable */ = (0.5032180796191645) * (DIVISION_SIM(data->simulationInfo->realParameter[326],data->localData[0]->realVars[200] /* T[1] variable */,"T[1]",equationIndexes));
  TRACE_POP
}
/*
 equation index: 1011
 type: SIMPLE_ASSIGN
 points[1]._Gamma._G[1,2] = exp((-points[1].BIP[1,2,2]) * points[1].Gamma.tau[1,2])
 */
void Graph_eqFunction_1011(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1011};
  data->localData[0]->realVars[241] /* points[1]._Gamma._G[1,2] variable */ = exp(((-data->simulationInfo->realParameter[327])) * (data->localData[0]->realVars[557] /* points[1]._Gamma._tau[1,2] variable */));
  TRACE_POP
}
/*
 equation index: 1012
 type: SIMPLE_ASSIGN
 $cse1 = DIVISION(points[1].Gamma.sum2[1], points[1].Gamma.sum1[1]) + points[1].Gamma.G[1,2] * DIVISION(points[1].Gamma.tau[1,2] - DIVISION(points[1].Gamma.sum2[2], points[1].Gamma.sum1[2]), points[1].Gamma.sum1[2])
 */
void Graph_eqFunction_1012(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1012};
  data->localData[0]->realVars[0] /* $cse1 variable */ = DIVISION_SIM(data->localData[0]->realVars[476] /* points[1]._Gamma._sum2[1] variable */,data->localData[0]->realVars[396] /* points[1]._Gamma._sum1[1] variable */,"points[1].Gamma.sum1[1]",equationIndexes) + (data->localData[0]->realVars[241] /* points[1]._Gamma._G[1,2] variable */) * (DIVISION_SIM(data->localData[0]->realVars[557] /* points[1]._Gamma._tau[1,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[477] /* points[1]._Gamma._sum2[2] variable */,data->localData[0]->realVars[397] /* points[1]._Gamma._sum1[2] variable */,"points[1].Gamma.sum1[2]",equationIndexes),data->localData[0]->realVars[397] /* points[1]._Gamma._sum1[2] variable */,"points[1].Gamma.sum1[2]",equationIndexes));
  TRACE_POP
}
/*
 equation index: 1013
 type: SIMPLE_ASSIGN
 points[1]._gamma[1] = exp($cse1)
 */
void Graph_eqFunction_1013(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1013};
  data->localData[0]->realVars[874] /* points[1]._gamma[1] variable */ = exp(data->localData[0]->realVars[0] /* $cse1 variable */);
  TRACE_POP
}
/*
 equation index: 1014
 type: SIMPLE_ASSIGN
 points[1]._K[1] = 0.0001 * points[1].gamma[1] * $cse3
 */
void Graph_eqFunction_1014(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1014};
  data->localData[0]->realVars[716] /* points[1]._K[1] variable */ = (0.0001) * ((data->localData[0]->realVars[874] /* points[1]._gamma[1] variable */) * (data->localData[0]->realVars[83] /* $cse3 variable */));
  TRACE_POP
}
/*
 equation index: 1015
 type: SIMPLE_ASSIGN
 points[1]._Gamma._tau[1,1] = 0.5032180796191645 * DIVISION(points[1].BIP[1,1,1], T[1])
 */
void Graph_eqFunction_1015(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1015};
  data->localData[0]->realVars[556] /* points[1]._Gamma._tau[1,1] variable */ = (0.5032180796191645) * (DIVISION_SIM(data->simulationInfo->realParameter[324],data->localData[0]->realVars[200] /* T[1] variable */,"T[1]",equationIndexes));
  TRACE_POP
}
/*
 equation index: 1016
 type: SIMPLE_ASSIGN
 points[1]._Gamma._G[1,1] = exp((-points[1].BIP[1,1,2]) * points[1].Gamma.tau[1,1])
 */
void Graph_eqFunction_1016(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1016};
  data->localData[0]->realVars[240] /* points[1]._Gamma._G[1,1] variable */ = exp(((-data->simulationInfo->realParameter[325])) * (data->localData[0]->realVars[556] /* points[1]._Gamma._tau[1,1] variable */));
  TRACE_POP
}
void Graph_eqFunction_1017(DATA*,threadData_t*);
void Graph_eqFunction_1018(DATA*,threadData_t*);
void Graph_eqFunction_1019(DATA*,threadData_t*);
void Graph_eqFunction_1020(DATA*,threadData_t*);
void Graph_eqFunction_1021(DATA*,threadData_t*);
void Graph_eqFunction_1022(DATA*,threadData_t*);
void Graph_eqFunction_1023(DATA*,threadData_t*);
void Graph_eqFunction_1024(DATA*,threadData_t*);
void Graph_eqFunction_1025(DATA*,threadData_t*);
void Graph_eqFunction_1026(DATA*,threadData_t*);
void Graph_eqFunction_1027(DATA*,threadData_t*);
void Graph_eqFunction_1028(DATA*,threadData_t*);
void Graph_eqFunction_1029(DATA*,threadData_t*);
void Graph_eqFunction_1030(DATA*,threadData_t*);
void Graph_eqFunction_1031(DATA*,threadData_t*);
void Graph_eqFunction_1032(DATA*,threadData_t*);
void Graph_eqFunction_1033(DATA*,threadData_t*);
void Graph_eqFunction_1034(DATA*,threadData_t*);
void Graph_eqFunction_1035(DATA*,threadData_t*);
void Graph_eqFunction_1036(DATA*,threadData_t*);
void Graph_eqFunction_1037(DATA*,threadData_t*);
/*
 equation index: 1038
 indexNonlinear: 41
 type: NONLINEAR
 
 vars: {T[2]}
 eqns: {1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028, 1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037}
 */
void Graph_eqFunction_1038(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1038};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1038 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[41].nlsxOld[0] = data->localData[0]->realVars[201] /* T[2] variable */;
  retValue = solve_nonlinear_system(data, threadData, 41);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1038};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1038 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[201] /* T[2] variable */ = data->simulationInfo->nonlinearSystemData[41].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1039
 type: SIMPLE_ASSIGN
 points[2]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[2].comp[2].LiqDen[1], points[2].comp[2].LiqDen[2], points[2].comp[2].LiqDen[3], points[2].comp[2].LiqDen[4], points[2].comp[2].LiqDen[5], points[2].comp[2].LiqDen[6]}, points[2].comp[2].Tc, T[2], 10000.0)
 */
void Graph_eqFunction_1039(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1039};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[8902], (modelica_real)data->simulationInfo->realParameter[8903], (modelica_real)data->simulationInfo->realParameter[8904], (modelica_real)data->simulationInfo->realParameter[8905], (modelica_real)data->simulationInfo->realParameter[8906], (modelica_real)data->simulationInfo->realParameter[8907]);
  data->localData[0]->realVars[797] /* points[2]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10967], data->localData[0]->realVars[201] /* T[2] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1040
 type: SIMPLE_ASSIGN
 points[2]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[2].comp[1].LiqDen[1], points[2].comp[1].LiqDen[2], points[2].comp[1].LiqDen[3], points[2].comp[1].LiqDen[4], points[2].comp[1].LiqDen[5], points[2].comp[1].LiqDen[6]}, points[2].comp[1].Tc, T[2], 10000.0)
 */
void Graph_eqFunction_1040(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1040};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8896], (modelica_real)data->simulationInfo->realParameter[8897], (modelica_real)data->simulationInfo->realParameter[8898], (modelica_real)data->simulationInfo->realParameter[8899], (modelica_real)data->simulationInfo->realParameter[8900], (modelica_real)data->simulationInfo->realParameter[8901]);
  data->localData[0]->realVars[796] /* points[2]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10966], data->localData[0]->realVars[201] /* T[2] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1041
 type: SIMPLE_ASSIGN
 y[2,2] = 0.9743589743589743 * points[2].K[2]
 */
void Graph_eqFunction_1041(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1041};
  data->localData[0]->realVars[1037] /* y[2,2] variable */ = (0.9743589743589743) * (data->localData[0]->realVars[718] /* points[2]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1042
 type: SIMPLE_ASSIGN
 y[2,1] = 1.0 - 0.9743589743589743 * points[2].K[2]
 */
void Graph_eqFunction_1042(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1042};
  data->localData[0]->realVars[1036] /* y[2,1] variable */ = 1.0 - ((0.9743589743589743) * (data->localData[0]->realVars[718] /* points[2]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1043(DATA*,threadData_t*);
void Graph_eqFunction_1044(DATA*,threadData_t*);
void Graph_eqFunction_1045(DATA*,threadData_t*);
void Graph_eqFunction_1046(DATA*,threadData_t*);
void Graph_eqFunction_1047(DATA*,threadData_t*);
void Graph_eqFunction_1048(DATA*,threadData_t*);
void Graph_eqFunction_1049(DATA*,threadData_t*);
void Graph_eqFunction_1050(DATA*,threadData_t*);
void Graph_eqFunction_1051(DATA*,threadData_t*);
void Graph_eqFunction_1052(DATA*,threadData_t*);
void Graph_eqFunction_1053(DATA*,threadData_t*);
void Graph_eqFunction_1054(DATA*,threadData_t*);
void Graph_eqFunction_1055(DATA*,threadData_t*);
void Graph_eqFunction_1056(DATA*,threadData_t*);
void Graph_eqFunction_1057(DATA*,threadData_t*);
void Graph_eqFunction_1058(DATA*,threadData_t*);
void Graph_eqFunction_1059(DATA*,threadData_t*);
void Graph_eqFunction_1060(DATA*,threadData_t*);
void Graph_eqFunction_1061(DATA*,threadData_t*);
void Graph_eqFunction_1062(DATA*,threadData_t*);
void Graph_eqFunction_1063(DATA*,threadData_t*);
/*
 equation index: 1064
 indexNonlinear: 42
 type: NONLINEAR
 
 vars: {T[3]}
 eqns: {1043, 1044, 1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 1053, 1054, 1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063}
 */
void Graph_eqFunction_1064(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1064};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1064 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[42].nlsxOld[0] = data->localData[0]->realVars[202] /* T[3] variable */;
  retValue = solve_nonlinear_system(data, threadData, 42);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1064};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1064 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[202] /* T[3] variable */ = data->simulationInfo->nonlinearSystemData[42].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1065
 type: SIMPLE_ASSIGN
 points[3]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[3].comp[2].LiqDen[1], points[3].comp[2].LiqDen[2], points[3].comp[2].LiqDen[3], points[3].comp[2].LiqDen[4], points[3].comp[2].LiqDen[5], points[3].comp[2].LiqDen[6]}, points[3].comp[2].Tc, T[3], 10000.0)
 */
void Graph_eqFunction_1065(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1065};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[8914], (modelica_real)data->simulationInfo->realParameter[8915], (modelica_real)data->simulationInfo->realParameter[8916], (modelica_real)data->simulationInfo->realParameter[8917], (modelica_real)data->simulationInfo->realParameter[8918], (modelica_real)data->simulationInfo->realParameter[8919]);
  data->localData[0]->realVars[799] /* points[3]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10969], data->localData[0]->realVars[202] /* T[3] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1066
 type: SIMPLE_ASSIGN
 points[3]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[3].comp[1].LiqDen[1], points[3].comp[1].LiqDen[2], points[3].comp[1].LiqDen[3], points[3].comp[1].LiqDen[4], points[3].comp[1].LiqDen[5], points[3].comp[1].LiqDen[6]}, points[3].comp[1].Tc, T[3], 10000.0)
 */
void Graph_eqFunction_1066(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1066};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8908], (modelica_real)data->simulationInfo->realParameter[8909], (modelica_real)data->simulationInfo->realParameter[8910], (modelica_real)data->simulationInfo->realParameter[8911], (modelica_real)data->simulationInfo->realParameter[8912], (modelica_real)data->simulationInfo->realParameter[8913]);
  data->localData[0]->realVars[798] /* points[3]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10968], data->localData[0]->realVars[202] /* T[3] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1067
 type: SIMPLE_ASSIGN
 y[3,2] = 0.9487179487179487 * points[3].K[2]
 */
void Graph_eqFunction_1067(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1067};
  data->localData[0]->realVars[1039] /* y[3,2] variable */ = (0.9487179487179487) * (data->localData[0]->realVars[720] /* points[3]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1068
 type: SIMPLE_ASSIGN
 y[3,1] = 1.0 - 0.9487179487179487 * points[3].K[2]
 */
void Graph_eqFunction_1068(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1068};
  data->localData[0]->realVars[1038] /* y[3,1] variable */ = 1.0 - ((0.9487179487179487) * (data->localData[0]->realVars[720] /* points[3]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1069(DATA*,threadData_t*);
void Graph_eqFunction_1070(DATA*,threadData_t*);
void Graph_eqFunction_1071(DATA*,threadData_t*);
void Graph_eqFunction_1072(DATA*,threadData_t*);
void Graph_eqFunction_1073(DATA*,threadData_t*);
void Graph_eqFunction_1074(DATA*,threadData_t*);
void Graph_eqFunction_1075(DATA*,threadData_t*);
void Graph_eqFunction_1076(DATA*,threadData_t*);
void Graph_eqFunction_1077(DATA*,threadData_t*);
void Graph_eqFunction_1078(DATA*,threadData_t*);
void Graph_eqFunction_1079(DATA*,threadData_t*);
void Graph_eqFunction_1080(DATA*,threadData_t*);
void Graph_eqFunction_1081(DATA*,threadData_t*);
void Graph_eqFunction_1082(DATA*,threadData_t*);
void Graph_eqFunction_1083(DATA*,threadData_t*);
void Graph_eqFunction_1084(DATA*,threadData_t*);
void Graph_eqFunction_1085(DATA*,threadData_t*);
void Graph_eqFunction_1086(DATA*,threadData_t*);
void Graph_eqFunction_1087(DATA*,threadData_t*);
void Graph_eqFunction_1088(DATA*,threadData_t*);
void Graph_eqFunction_1089(DATA*,threadData_t*);
/*
 equation index: 1090
 indexNonlinear: 43
 type: NONLINEAR
 
 vars: {T[4]}
 eqns: {1069, 1070, 1071, 1072, 1073, 1074, 1075, 1076, 1077, 1078, 1079, 1080, 1081, 1082, 1083, 1084, 1085, 1086, 1087, 1088, 1089}
 */
void Graph_eqFunction_1090(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1090};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1090 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[43].nlsxOld[0] = data->localData[0]->realVars[203] /* T[4] variable */;
  retValue = solve_nonlinear_system(data, threadData, 43);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1090};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1090 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[203] /* T[4] variable */ = data->simulationInfo->nonlinearSystemData[43].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1091
 type: SIMPLE_ASSIGN
 points[4]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[4].comp[2].LiqDen[1], points[4].comp[2].LiqDen[2], points[4].comp[2].LiqDen[3], points[4].comp[2].LiqDen[4], points[4].comp[2].LiqDen[5], points[4].comp[2].LiqDen[6]}, points[4].comp[2].Tc, T[4], 10000.0)
 */
void Graph_eqFunction_1091(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1091};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[8926], (modelica_real)data->simulationInfo->realParameter[8927], (modelica_real)data->simulationInfo->realParameter[8928], (modelica_real)data->simulationInfo->realParameter[8929], (modelica_real)data->simulationInfo->realParameter[8930], (modelica_real)data->simulationInfo->realParameter[8931]);
  data->localData[0]->realVars[801] /* points[4]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10971], data->localData[0]->realVars[203] /* T[4] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1092
 type: SIMPLE_ASSIGN
 points[4]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[4].comp[1].LiqDen[1], points[4].comp[1].LiqDen[2], points[4].comp[1].LiqDen[3], points[4].comp[1].LiqDen[4], points[4].comp[1].LiqDen[5], points[4].comp[1].LiqDen[6]}, points[4].comp[1].Tc, T[4], 10000.0)
 */
void Graph_eqFunction_1092(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1092};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8920], (modelica_real)data->simulationInfo->realParameter[8921], (modelica_real)data->simulationInfo->realParameter[8922], (modelica_real)data->simulationInfo->realParameter[8923], (modelica_real)data->simulationInfo->realParameter[8924], (modelica_real)data->simulationInfo->realParameter[8925]);
  data->localData[0]->realVars[800] /* points[4]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10970], data->localData[0]->realVars[203] /* T[4] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1093
 type: SIMPLE_ASSIGN
 y[4,2] = 0.9230769230769231 * points[4].K[2]
 */
void Graph_eqFunction_1093(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1093};
  data->localData[0]->realVars[1041] /* y[4,2] variable */ = (0.9230769230769231) * (data->localData[0]->realVars[722] /* points[4]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1094
 type: SIMPLE_ASSIGN
 y[4,1] = 1.0 - 0.9230769230769231 * points[4].K[2]
 */
void Graph_eqFunction_1094(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1094};
  data->localData[0]->realVars[1040] /* y[4,1] variable */ = 1.0 - ((0.9230769230769231) * (data->localData[0]->realVars[722] /* points[4]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1095(DATA*,threadData_t*);
void Graph_eqFunction_1096(DATA*,threadData_t*);
void Graph_eqFunction_1097(DATA*,threadData_t*);
void Graph_eqFunction_1098(DATA*,threadData_t*);
void Graph_eqFunction_1099(DATA*,threadData_t*);
void Graph_eqFunction_1100(DATA*,threadData_t*);
void Graph_eqFunction_1101(DATA*,threadData_t*);
void Graph_eqFunction_1102(DATA*,threadData_t*);
void Graph_eqFunction_1103(DATA*,threadData_t*);
void Graph_eqFunction_1104(DATA*,threadData_t*);
void Graph_eqFunction_1105(DATA*,threadData_t*);
void Graph_eqFunction_1106(DATA*,threadData_t*);
void Graph_eqFunction_1107(DATA*,threadData_t*);
void Graph_eqFunction_1108(DATA*,threadData_t*);
void Graph_eqFunction_1109(DATA*,threadData_t*);
void Graph_eqFunction_1110(DATA*,threadData_t*);
void Graph_eqFunction_1111(DATA*,threadData_t*);
void Graph_eqFunction_1112(DATA*,threadData_t*);
void Graph_eqFunction_1113(DATA*,threadData_t*);
void Graph_eqFunction_1114(DATA*,threadData_t*);
void Graph_eqFunction_1115(DATA*,threadData_t*);
/*
 equation index: 1116
 indexNonlinear: 44
 type: NONLINEAR
 
 vars: {T[5]}
 eqns: {1095, 1096, 1097, 1098, 1099, 1100, 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110, 1111, 1112, 1113, 1114, 1115}
 */
void Graph_eqFunction_1116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1116};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1116 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[44].nlsxOld[0] = data->localData[0]->realVars[204] /* T[5] variable */;
  retValue = solve_nonlinear_system(data, threadData, 44);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1116};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1116 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[204] /* T[5] variable */ = data->simulationInfo->nonlinearSystemData[44].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1117
 type: SIMPLE_ASSIGN
 y[5,2] = 0.8974358974358975 * points[5].K[2]
 */
void Graph_eqFunction_1117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1117};
  data->localData[0]->realVars[1043] /* y[5,2] variable */ = (0.8974358974358975) * (data->localData[0]->realVars[724] /* points[5]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1118
 type: SIMPLE_ASSIGN
 y[5,1] = 1.0 - 0.8974358974358975 * points[5].K[2]
 */
void Graph_eqFunction_1118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1118};
  data->localData[0]->realVars[1042] /* y[5,1] variable */ = 1.0 - ((0.8974358974358975) * (data->localData[0]->realVars[724] /* points[5]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1119
 type: SIMPLE_ASSIGN
 points[5]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[5].comp[2].LiqDen[1], points[5].comp[2].LiqDen[2], points[5].comp[2].LiqDen[3], points[5].comp[2].LiqDen[4], points[5].comp[2].LiqDen[5], points[5].comp[2].LiqDen[6]}, points[5].comp[2].Tc, T[5], 10000.0)
 */
void Graph_eqFunction_1119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1119};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[8938], (modelica_real)data->simulationInfo->realParameter[8939], (modelica_real)data->simulationInfo->realParameter[8940], (modelica_real)data->simulationInfo->realParameter[8941], (modelica_real)data->simulationInfo->realParameter[8942], (modelica_real)data->simulationInfo->realParameter[8943]);
  data->localData[0]->realVars[803] /* points[5]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10973], data->localData[0]->realVars[204] /* T[5] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1120
 type: SIMPLE_ASSIGN
 points[5]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[5].comp[1].LiqDen[1], points[5].comp[1].LiqDen[2], points[5].comp[1].LiqDen[3], points[5].comp[1].LiqDen[4], points[5].comp[1].LiqDen[5], points[5].comp[1].LiqDen[6]}, points[5].comp[1].Tc, T[5], 10000.0)
 */
void Graph_eqFunction_1120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1120};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8932], (modelica_real)data->simulationInfo->realParameter[8933], (modelica_real)data->simulationInfo->realParameter[8934], (modelica_real)data->simulationInfo->realParameter[8935], (modelica_real)data->simulationInfo->realParameter[8936], (modelica_real)data->simulationInfo->realParameter[8937]);
  data->localData[0]->realVars[802] /* points[5]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10972], data->localData[0]->realVars[204] /* T[5] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1121(DATA*,threadData_t*);
void Graph_eqFunction_1122(DATA*,threadData_t*);
void Graph_eqFunction_1123(DATA*,threadData_t*);
void Graph_eqFunction_1124(DATA*,threadData_t*);
void Graph_eqFunction_1125(DATA*,threadData_t*);
void Graph_eqFunction_1126(DATA*,threadData_t*);
void Graph_eqFunction_1127(DATA*,threadData_t*);
void Graph_eqFunction_1128(DATA*,threadData_t*);
void Graph_eqFunction_1129(DATA*,threadData_t*);
void Graph_eqFunction_1130(DATA*,threadData_t*);
void Graph_eqFunction_1131(DATA*,threadData_t*);
void Graph_eqFunction_1132(DATA*,threadData_t*);
void Graph_eqFunction_1133(DATA*,threadData_t*);
void Graph_eqFunction_1134(DATA*,threadData_t*);
void Graph_eqFunction_1135(DATA*,threadData_t*);
void Graph_eqFunction_1136(DATA*,threadData_t*);
void Graph_eqFunction_1137(DATA*,threadData_t*);
void Graph_eqFunction_1138(DATA*,threadData_t*);
void Graph_eqFunction_1139(DATA*,threadData_t*);
void Graph_eqFunction_1140(DATA*,threadData_t*);
void Graph_eqFunction_1141(DATA*,threadData_t*);
/*
 equation index: 1142
 indexNonlinear: 45
 type: NONLINEAR
 
 vars: {T[6]}
 eqns: {1121, 1122, 1123, 1124, 1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133, 1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141}
 */
void Graph_eqFunction_1142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1142};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1142 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[45].nlsxOld[0] = data->localData[0]->realVars[205] /* T[6] variable */;
  retValue = solve_nonlinear_system(data, threadData, 45);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1142};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1142 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[205] /* T[6] variable */ = data->simulationInfo->nonlinearSystemData[45].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1143
 type: SIMPLE_ASSIGN
 points[6]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[6].comp[2].LiqDen[1], points[6].comp[2].LiqDen[2], points[6].comp[2].LiqDen[3], points[6].comp[2].LiqDen[4], points[6].comp[2].LiqDen[5], points[6].comp[2].LiqDen[6]}, points[6].comp[2].Tc, T[6], 10000.0)
 */
void Graph_eqFunction_1143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1143};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[8950], (modelica_real)data->simulationInfo->realParameter[8951], (modelica_real)data->simulationInfo->realParameter[8952], (modelica_real)data->simulationInfo->realParameter[8953], (modelica_real)data->simulationInfo->realParameter[8954], (modelica_real)data->simulationInfo->realParameter[8955]);
  data->localData[0]->realVars[805] /* points[6]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10975], data->localData[0]->realVars[205] /* T[6] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1144
 type: SIMPLE_ASSIGN
 points[6]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[6].comp[1].LiqDen[1], points[6].comp[1].LiqDen[2], points[6].comp[1].LiqDen[3], points[6].comp[1].LiqDen[4], points[6].comp[1].LiqDen[5], points[6].comp[1].LiqDen[6]}, points[6].comp[1].Tc, T[6], 10000.0)
 */
void Graph_eqFunction_1144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1144};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8944], (modelica_real)data->simulationInfo->realParameter[8945], (modelica_real)data->simulationInfo->realParameter[8946], (modelica_real)data->simulationInfo->realParameter[8947], (modelica_real)data->simulationInfo->realParameter[8948], (modelica_real)data->simulationInfo->realParameter[8949]);
  data->localData[0]->realVars[804] /* points[6]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10974], data->localData[0]->realVars[205] /* T[6] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1145
 type: SIMPLE_ASSIGN
 y[6,2] = 0.8717948717948718 * points[6].K[2]
 */
void Graph_eqFunction_1145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1145};
  data->localData[0]->realVars[1045] /* y[6,2] variable */ = (0.8717948717948718) * (data->localData[0]->realVars[726] /* points[6]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1146
 type: SIMPLE_ASSIGN
 y[6,1] = 1.0 - 0.8717948717948718 * points[6].K[2]
 */
void Graph_eqFunction_1146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1146};
  data->localData[0]->realVars[1044] /* y[6,1] variable */ = 1.0 - ((0.8717948717948718) * (data->localData[0]->realVars[726] /* points[6]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1147(DATA*,threadData_t*);
void Graph_eqFunction_1148(DATA*,threadData_t*);
void Graph_eqFunction_1149(DATA*,threadData_t*);
void Graph_eqFunction_1150(DATA*,threadData_t*);
void Graph_eqFunction_1151(DATA*,threadData_t*);
void Graph_eqFunction_1152(DATA*,threadData_t*);
void Graph_eqFunction_1153(DATA*,threadData_t*);
void Graph_eqFunction_1154(DATA*,threadData_t*);
void Graph_eqFunction_1155(DATA*,threadData_t*);
void Graph_eqFunction_1156(DATA*,threadData_t*);
void Graph_eqFunction_1157(DATA*,threadData_t*);
void Graph_eqFunction_1158(DATA*,threadData_t*);
void Graph_eqFunction_1159(DATA*,threadData_t*);
void Graph_eqFunction_1160(DATA*,threadData_t*);
void Graph_eqFunction_1161(DATA*,threadData_t*);
void Graph_eqFunction_1162(DATA*,threadData_t*);
void Graph_eqFunction_1163(DATA*,threadData_t*);
void Graph_eqFunction_1164(DATA*,threadData_t*);
void Graph_eqFunction_1165(DATA*,threadData_t*);
void Graph_eqFunction_1166(DATA*,threadData_t*);
void Graph_eqFunction_1167(DATA*,threadData_t*);
/*
 equation index: 1168
 indexNonlinear: 46
 type: NONLINEAR
 
 vars: {T[7]}
 eqns: {1147, 1148, 1149, 1150, 1151, 1152, 1153, 1154, 1155, 1156, 1157, 1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165, 1166, 1167}
 */
void Graph_eqFunction_1168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1168};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1168 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[46].nlsxOld[0] = data->localData[0]->realVars[206] /* T[7] variable */;
  retValue = solve_nonlinear_system(data, threadData, 46);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1168};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1168 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[206] /* T[7] variable */ = data->simulationInfo->nonlinearSystemData[46].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1169
 type: SIMPLE_ASSIGN
 y[7,2] = 0.8461538461538462 * points[7].K[2]
 */
void Graph_eqFunction_1169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1169};
  data->localData[0]->realVars[1047] /* y[7,2] variable */ = (0.8461538461538462) * (data->localData[0]->realVars[728] /* points[7]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1170
 type: SIMPLE_ASSIGN
 y[7,1] = 1.0 - 0.8461538461538462 * points[7].K[2]
 */
void Graph_eqFunction_1170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1170};
  data->localData[0]->realVars[1046] /* y[7,1] variable */ = 1.0 - ((0.8461538461538462) * (data->localData[0]->realVars[728] /* points[7]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1171
 type: SIMPLE_ASSIGN
 points[7]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[7].comp[2].LiqDen[1], points[7].comp[2].LiqDen[2], points[7].comp[2].LiqDen[3], points[7].comp[2].LiqDen[4], points[7].comp[2].LiqDen[5], points[7].comp[2].LiqDen[6]}, points[7].comp[2].Tc, T[7], 10000.0)
 */
void Graph_eqFunction_1171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1171};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[8962], (modelica_real)data->simulationInfo->realParameter[8963], (modelica_real)data->simulationInfo->realParameter[8964], (modelica_real)data->simulationInfo->realParameter[8965], (modelica_real)data->simulationInfo->realParameter[8966], (modelica_real)data->simulationInfo->realParameter[8967]);
  data->localData[0]->realVars[807] /* points[7]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10977], data->localData[0]->realVars[206] /* T[7] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1172
 type: SIMPLE_ASSIGN
 points[7]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[7].comp[1].LiqDen[1], points[7].comp[1].LiqDen[2], points[7].comp[1].LiqDen[3], points[7].comp[1].LiqDen[4], points[7].comp[1].LiqDen[5], points[7].comp[1].LiqDen[6]}, points[7].comp[1].Tc, T[7], 10000.0)
 */
void Graph_eqFunction_1172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1172};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8956], (modelica_real)data->simulationInfo->realParameter[8957], (modelica_real)data->simulationInfo->realParameter[8958], (modelica_real)data->simulationInfo->realParameter[8959], (modelica_real)data->simulationInfo->realParameter[8960], (modelica_real)data->simulationInfo->realParameter[8961]);
  data->localData[0]->realVars[806] /* points[7]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10976], data->localData[0]->realVars[206] /* T[7] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1173(DATA*,threadData_t*);
void Graph_eqFunction_1174(DATA*,threadData_t*);
void Graph_eqFunction_1175(DATA*,threadData_t*);
void Graph_eqFunction_1176(DATA*,threadData_t*);
void Graph_eqFunction_1177(DATA*,threadData_t*);
void Graph_eqFunction_1178(DATA*,threadData_t*);
void Graph_eqFunction_1179(DATA*,threadData_t*);
void Graph_eqFunction_1180(DATA*,threadData_t*);
void Graph_eqFunction_1181(DATA*,threadData_t*);
void Graph_eqFunction_1182(DATA*,threadData_t*);
void Graph_eqFunction_1183(DATA*,threadData_t*);
void Graph_eqFunction_1184(DATA*,threadData_t*);
void Graph_eqFunction_1185(DATA*,threadData_t*);
void Graph_eqFunction_1186(DATA*,threadData_t*);
void Graph_eqFunction_1187(DATA*,threadData_t*);
void Graph_eqFunction_1188(DATA*,threadData_t*);
void Graph_eqFunction_1189(DATA*,threadData_t*);
void Graph_eqFunction_1190(DATA*,threadData_t*);
void Graph_eqFunction_1191(DATA*,threadData_t*);
void Graph_eqFunction_1192(DATA*,threadData_t*);
void Graph_eqFunction_1193(DATA*,threadData_t*);
/*
 equation index: 1194
 indexNonlinear: 47
 type: NONLINEAR
 
 vars: {T[8]}
 eqns: {1173, 1174, 1175, 1176, 1177, 1178, 1179, 1180, 1181, 1182, 1183, 1184, 1185, 1186, 1187, 1188, 1189, 1190, 1191, 1192, 1193}
 */
void Graph_eqFunction_1194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1194};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1194 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[47].nlsxOld[0] = data->localData[0]->realVars[207] /* T[8] variable */;
  retValue = solve_nonlinear_system(data, threadData, 47);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1194};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1194 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[207] /* T[8] variable */ = data->simulationInfo->nonlinearSystemData[47].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1195
 type: SIMPLE_ASSIGN
 points[8]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[8].comp[2].LiqDen[1], points[8].comp[2].LiqDen[2], points[8].comp[2].LiqDen[3], points[8].comp[2].LiqDen[4], points[8].comp[2].LiqDen[5], points[8].comp[2].LiqDen[6]}, points[8].comp[2].Tc, T[8], 10000.0)
 */
void Graph_eqFunction_1195(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1195};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[8974], (modelica_real)data->simulationInfo->realParameter[8975], (modelica_real)data->simulationInfo->realParameter[8976], (modelica_real)data->simulationInfo->realParameter[8977], (modelica_real)data->simulationInfo->realParameter[8978], (modelica_real)data->simulationInfo->realParameter[8979]);
  data->localData[0]->realVars[809] /* points[8]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10979], data->localData[0]->realVars[207] /* T[8] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1196
 type: SIMPLE_ASSIGN
 points[8]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[8].comp[1].LiqDen[1], points[8].comp[1].LiqDen[2], points[8].comp[1].LiqDen[3], points[8].comp[1].LiqDen[4], points[8].comp[1].LiqDen[5], points[8].comp[1].LiqDen[6]}, points[8].comp[1].Tc, T[8], 10000.0)
 */
void Graph_eqFunction_1196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1196};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8968], (modelica_real)data->simulationInfo->realParameter[8969], (modelica_real)data->simulationInfo->realParameter[8970], (modelica_real)data->simulationInfo->realParameter[8971], (modelica_real)data->simulationInfo->realParameter[8972], (modelica_real)data->simulationInfo->realParameter[8973]);
  data->localData[0]->realVars[808] /* points[8]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10978], data->localData[0]->realVars[207] /* T[8] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1197
 type: SIMPLE_ASSIGN
 y[8,2] = 0.8205128205128205 * points[8].K[2]
 */
void Graph_eqFunction_1197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1197};
  data->localData[0]->realVars[1049] /* y[8,2] variable */ = (0.8205128205128205) * (data->localData[0]->realVars[730] /* points[8]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1198
 type: SIMPLE_ASSIGN
 y[8,1] = 1.0 - 0.8205128205128205 * points[8].K[2]
 */
void Graph_eqFunction_1198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1198};
  data->localData[0]->realVars[1048] /* y[8,1] variable */ = 1.0 - ((0.8205128205128205) * (data->localData[0]->realVars[730] /* points[8]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1199(DATA*,threadData_t*);
void Graph_eqFunction_1200(DATA*,threadData_t*);
void Graph_eqFunction_1201(DATA*,threadData_t*);
void Graph_eqFunction_1202(DATA*,threadData_t*);
void Graph_eqFunction_1203(DATA*,threadData_t*);
void Graph_eqFunction_1204(DATA*,threadData_t*);
void Graph_eqFunction_1205(DATA*,threadData_t*);
void Graph_eqFunction_1206(DATA*,threadData_t*);
void Graph_eqFunction_1207(DATA*,threadData_t*);
void Graph_eqFunction_1208(DATA*,threadData_t*);
void Graph_eqFunction_1209(DATA*,threadData_t*);
void Graph_eqFunction_1210(DATA*,threadData_t*);
void Graph_eqFunction_1211(DATA*,threadData_t*);
void Graph_eqFunction_1212(DATA*,threadData_t*);
void Graph_eqFunction_1213(DATA*,threadData_t*);
void Graph_eqFunction_1214(DATA*,threadData_t*);
void Graph_eqFunction_1215(DATA*,threadData_t*);
void Graph_eqFunction_1216(DATA*,threadData_t*);
void Graph_eqFunction_1217(DATA*,threadData_t*);
void Graph_eqFunction_1218(DATA*,threadData_t*);
void Graph_eqFunction_1219(DATA*,threadData_t*);
/*
 equation index: 1220
 indexNonlinear: 48
 type: NONLINEAR
 
 vars: {T[9]}
 eqns: {1199, 1200, 1201, 1202, 1203, 1204, 1205, 1206, 1207, 1208, 1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1218, 1219}
 */
void Graph_eqFunction_1220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1220};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1220 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[48].nlsxOld[0] = data->localData[0]->realVars[208] /* T[9] variable */;
  retValue = solve_nonlinear_system(data, threadData, 48);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1220};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1220 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[208] /* T[9] variable */ = data->simulationInfo->nonlinearSystemData[48].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1221
 type: SIMPLE_ASSIGN
 y[9,2] = 0.7948717948717949 * points[9].K[2]
 */
void Graph_eqFunction_1221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1221};
  data->localData[0]->realVars[1051] /* y[9,2] variable */ = (0.7948717948717949) * (data->localData[0]->realVars[732] /* points[9]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1222
 type: SIMPLE_ASSIGN
 y[9,1] = 1.0 - 0.7948717948717949 * points[9].K[2]
 */
void Graph_eqFunction_1222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1222};
  data->localData[0]->realVars[1050] /* y[9,1] variable */ = 1.0 - ((0.7948717948717949) * (data->localData[0]->realVars[732] /* points[9]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1223
 type: SIMPLE_ASSIGN
 points[9]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[9].comp[2].LiqDen[1], points[9].comp[2].LiqDen[2], points[9].comp[2].LiqDen[3], points[9].comp[2].LiqDen[4], points[9].comp[2].LiqDen[5], points[9].comp[2].LiqDen[6]}, points[9].comp[2].Tc, T[9], 10000.0)
 */
void Graph_eqFunction_1223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1223};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[8986], (modelica_real)data->simulationInfo->realParameter[8987], (modelica_real)data->simulationInfo->realParameter[8988], (modelica_real)data->simulationInfo->realParameter[8989], (modelica_real)data->simulationInfo->realParameter[8990], (modelica_real)data->simulationInfo->realParameter[8991]);
  data->localData[0]->realVars[811] /* points[9]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10981], data->localData[0]->realVars[208] /* T[9] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1224
 type: SIMPLE_ASSIGN
 points[9]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[9].comp[1].LiqDen[1], points[9].comp[1].LiqDen[2], points[9].comp[1].LiqDen[3], points[9].comp[1].LiqDen[4], points[9].comp[1].LiqDen[5], points[9].comp[1].LiqDen[6]}, points[9].comp[1].Tc, T[9], 10000.0)
 */
void Graph_eqFunction_1224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1224};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8980], (modelica_real)data->simulationInfo->realParameter[8981], (modelica_real)data->simulationInfo->realParameter[8982], (modelica_real)data->simulationInfo->realParameter[8983], (modelica_real)data->simulationInfo->realParameter[8984], (modelica_real)data->simulationInfo->realParameter[8985]);
  data->localData[0]->realVars[810] /* points[9]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10980], data->localData[0]->realVars[208] /* T[9] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1225(DATA*,threadData_t*);
void Graph_eqFunction_1226(DATA*,threadData_t*);
void Graph_eqFunction_1227(DATA*,threadData_t*);
void Graph_eqFunction_1228(DATA*,threadData_t*);
void Graph_eqFunction_1229(DATA*,threadData_t*);
void Graph_eqFunction_1230(DATA*,threadData_t*);
void Graph_eqFunction_1231(DATA*,threadData_t*);
void Graph_eqFunction_1232(DATA*,threadData_t*);
void Graph_eqFunction_1233(DATA*,threadData_t*);
void Graph_eqFunction_1234(DATA*,threadData_t*);
void Graph_eqFunction_1235(DATA*,threadData_t*);
void Graph_eqFunction_1236(DATA*,threadData_t*);
void Graph_eqFunction_1237(DATA*,threadData_t*);
void Graph_eqFunction_1238(DATA*,threadData_t*);
void Graph_eqFunction_1239(DATA*,threadData_t*);
void Graph_eqFunction_1240(DATA*,threadData_t*);
void Graph_eqFunction_1241(DATA*,threadData_t*);
void Graph_eqFunction_1242(DATA*,threadData_t*);
void Graph_eqFunction_1243(DATA*,threadData_t*);
void Graph_eqFunction_1244(DATA*,threadData_t*);
void Graph_eqFunction_1245(DATA*,threadData_t*);
/*
 equation index: 1246
 indexNonlinear: 49
 type: NONLINEAR
 
 vars: {T[10]}
 eqns: {1225, 1226, 1227, 1228, 1229, 1230, 1231, 1232, 1233, 1234, 1235, 1236, 1237, 1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245}
 */
void Graph_eqFunction_1246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1246};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1246 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[49].nlsxOld[0] = data->localData[0]->realVars[209] /* T[10] variable */;
  retValue = solve_nonlinear_system(data, threadData, 49);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1246};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1246 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[209] /* T[10] variable */ = data->simulationInfo->nonlinearSystemData[49].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1247
 type: SIMPLE_ASSIGN
 points[10]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[10].comp[2].LiqDen[1], points[10].comp[2].LiqDen[2], points[10].comp[2].LiqDen[3], points[10].comp[2].LiqDen[4], points[10].comp[2].LiqDen[5], points[10].comp[2].LiqDen[6]}, points[10].comp[2].Tc, T[10], 10000.0)
 */
void Graph_eqFunction_1247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1247};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[8998], (modelica_real)data->simulationInfo->realParameter[8999], (modelica_real)data->simulationInfo->realParameter[9000], (modelica_real)data->simulationInfo->realParameter[9001], (modelica_real)data->simulationInfo->realParameter[9002], (modelica_real)data->simulationInfo->realParameter[9003]);
  data->localData[0]->realVars[813] /* points[10]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10983], data->localData[0]->realVars[209] /* T[10] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1248
 type: SIMPLE_ASSIGN
 points[10]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[10].comp[1].LiqDen[1], points[10].comp[1].LiqDen[2], points[10].comp[1].LiqDen[3], points[10].comp[1].LiqDen[4], points[10].comp[1].LiqDen[5], points[10].comp[1].LiqDen[6]}, points[10].comp[1].Tc, T[10], 10000.0)
 */
void Graph_eqFunction_1248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1248};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[8992], (modelica_real)data->simulationInfo->realParameter[8993], (modelica_real)data->simulationInfo->realParameter[8994], (modelica_real)data->simulationInfo->realParameter[8995], (modelica_real)data->simulationInfo->realParameter[8996], (modelica_real)data->simulationInfo->realParameter[8997]);
  data->localData[0]->realVars[812] /* points[10]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10982], data->localData[0]->realVars[209] /* T[10] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1249
 type: SIMPLE_ASSIGN
 y[10,2] = 0.7692307692307692 * points[10].K[2]
 */
void Graph_eqFunction_1249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1249};
  data->localData[0]->realVars[1053] /* y[10,2] variable */ = (0.7692307692307692) * (data->localData[0]->realVars[734] /* points[10]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1250
 type: SIMPLE_ASSIGN
 y[10,1] = 1.0 - 0.7692307692307692 * points[10].K[2]
 */
void Graph_eqFunction_1250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1250};
  data->localData[0]->realVars[1052] /* y[10,1] variable */ = 1.0 - ((0.7692307692307692) * (data->localData[0]->realVars[734] /* points[10]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1251(DATA*,threadData_t*);
void Graph_eqFunction_1252(DATA*,threadData_t*);
void Graph_eqFunction_1253(DATA*,threadData_t*);
void Graph_eqFunction_1254(DATA*,threadData_t*);
void Graph_eqFunction_1255(DATA*,threadData_t*);
void Graph_eqFunction_1256(DATA*,threadData_t*);
void Graph_eqFunction_1257(DATA*,threadData_t*);
void Graph_eqFunction_1258(DATA*,threadData_t*);
void Graph_eqFunction_1259(DATA*,threadData_t*);
void Graph_eqFunction_1260(DATA*,threadData_t*);
void Graph_eqFunction_1261(DATA*,threadData_t*);
void Graph_eqFunction_1262(DATA*,threadData_t*);
void Graph_eqFunction_1263(DATA*,threadData_t*);
void Graph_eqFunction_1264(DATA*,threadData_t*);
void Graph_eqFunction_1265(DATA*,threadData_t*);
void Graph_eqFunction_1266(DATA*,threadData_t*);
void Graph_eqFunction_1267(DATA*,threadData_t*);
void Graph_eqFunction_1268(DATA*,threadData_t*);
void Graph_eqFunction_1269(DATA*,threadData_t*);
void Graph_eqFunction_1270(DATA*,threadData_t*);
void Graph_eqFunction_1271(DATA*,threadData_t*);
/*
 equation index: 1272
 indexNonlinear: 50
 type: NONLINEAR
 
 vars: {T[11]}
 eqns: {1251, 1252, 1253, 1254, 1255, 1256, 1257, 1258, 1259, 1260, 1261, 1262, 1263, 1264, 1265, 1266, 1267, 1268, 1269, 1270, 1271}
 */
void Graph_eqFunction_1272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1272};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1272 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[50].nlsxOld[0] = data->localData[0]->realVars[210] /* T[11] variable */;
  retValue = solve_nonlinear_system(data, threadData, 50);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1272};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1272 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[210] /* T[11] variable */ = data->simulationInfo->nonlinearSystemData[50].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1273
 type: SIMPLE_ASSIGN
 y[11,2] = 0.7435897435897436 * points[11].K[2]
 */
void Graph_eqFunction_1273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1273};
  data->localData[0]->realVars[1055] /* y[11,2] variable */ = (0.7435897435897436) * (data->localData[0]->realVars[736] /* points[11]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1274
 type: SIMPLE_ASSIGN
 y[11,1] = 1.0 - 0.7435897435897436 * points[11].K[2]
 */
void Graph_eqFunction_1274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1274};
  data->localData[0]->realVars[1054] /* y[11,1] variable */ = 1.0 - ((0.7435897435897436) * (data->localData[0]->realVars[736] /* points[11]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1275
 type: SIMPLE_ASSIGN
 points[11]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[11].comp[2].LiqDen[1], points[11].comp[2].LiqDen[2], points[11].comp[2].LiqDen[3], points[11].comp[2].LiqDen[4], points[11].comp[2].LiqDen[5], points[11].comp[2].LiqDen[6]}, points[11].comp[2].Tc, T[11], 10000.0)
 */
void Graph_eqFunction_1275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1275};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9010], (modelica_real)data->simulationInfo->realParameter[9011], (modelica_real)data->simulationInfo->realParameter[9012], (modelica_real)data->simulationInfo->realParameter[9013], (modelica_real)data->simulationInfo->realParameter[9014], (modelica_real)data->simulationInfo->realParameter[9015]);
  data->localData[0]->realVars[815] /* points[11]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10985], data->localData[0]->realVars[210] /* T[11] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1276
 type: SIMPLE_ASSIGN
 points[11]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[11].comp[1].LiqDen[1], points[11].comp[1].LiqDen[2], points[11].comp[1].LiqDen[3], points[11].comp[1].LiqDen[4], points[11].comp[1].LiqDen[5], points[11].comp[1].LiqDen[6]}, points[11].comp[1].Tc, T[11], 10000.0)
 */
void Graph_eqFunction_1276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1276};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9004], (modelica_real)data->simulationInfo->realParameter[9005], (modelica_real)data->simulationInfo->realParameter[9006], (modelica_real)data->simulationInfo->realParameter[9007], (modelica_real)data->simulationInfo->realParameter[9008], (modelica_real)data->simulationInfo->realParameter[9009]);
  data->localData[0]->realVars[814] /* points[11]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10984], data->localData[0]->realVars[210] /* T[11] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1277(DATA*,threadData_t*);
void Graph_eqFunction_1278(DATA*,threadData_t*);
void Graph_eqFunction_1279(DATA*,threadData_t*);
void Graph_eqFunction_1280(DATA*,threadData_t*);
void Graph_eqFunction_1281(DATA*,threadData_t*);
void Graph_eqFunction_1282(DATA*,threadData_t*);
void Graph_eqFunction_1283(DATA*,threadData_t*);
void Graph_eqFunction_1284(DATA*,threadData_t*);
void Graph_eqFunction_1285(DATA*,threadData_t*);
void Graph_eqFunction_1286(DATA*,threadData_t*);
void Graph_eqFunction_1287(DATA*,threadData_t*);
void Graph_eqFunction_1288(DATA*,threadData_t*);
void Graph_eqFunction_1289(DATA*,threadData_t*);
void Graph_eqFunction_1290(DATA*,threadData_t*);
void Graph_eqFunction_1291(DATA*,threadData_t*);
void Graph_eqFunction_1292(DATA*,threadData_t*);
void Graph_eqFunction_1293(DATA*,threadData_t*);
void Graph_eqFunction_1294(DATA*,threadData_t*);
void Graph_eqFunction_1295(DATA*,threadData_t*);
void Graph_eqFunction_1296(DATA*,threadData_t*);
void Graph_eqFunction_1297(DATA*,threadData_t*);
/*
 equation index: 1298
 indexNonlinear: 51
 type: NONLINEAR
 
 vars: {T[12]}
 eqns: {1277, 1278, 1279, 1280, 1281, 1282, 1283, 1284, 1285, 1286, 1287, 1288, 1289, 1290, 1291, 1292, 1293, 1294, 1295, 1296, 1297}
 */
void Graph_eqFunction_1298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1298};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1298 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[51].nlsxOld[0] = data->localData[0]->realVars[211] /* T[12] variable */;
  retValue = solve_nonlinear_system(data, threadData, 51);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1298};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1298 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[211] /* T[12] variable */ = data->simulationInfo->nonlinearSystemData[51].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1299
 type: SIMPLE_ASSIGN
 points[12]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[12].comp[2].LiqDen[1], points[12].comp[2].LiqDen[2], points[12].comp[2].LiqDen[3], points[12].comp[2].LiqDen[4], points[12].comp[2].LiqDen[5], points[12].comp[2].LiqDen[6]}, points[12].comp[2].Tc, T[12], 10000.0)
 */
void Graph_eqFunction_1299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1299};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9022], (modelica_real)data->simulationInfo->realParameter[9023], (modelica_real)data->simulationInfo->realParameter[9024], (modelica_real)data->simulationInfo->realParameter[9025], (modelica_real)data->simulationInfo->realParameter[9026], (modelica_real)data->simulationInfo->realParameter[9027]);
  data->localData[0]->realVars[817] /* points[12]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10987], data->localData[0]->realVars[211] /* T[12] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1300
 type: SIMPLE_ASSIGN
 points[12]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[12].comp[1].LiqDen[1], points[12].comp[1].LiqDen[2], points[12].comp[1].LiqDen[3], points[12].comp[1].LiqDen[4], points[12].comp[1].LiqDen[5], points[12].comp[1].LiqDen[6]}, points[12].comp[1].Tc, T[12], 10000.0)
 */
void Graph_eqFunction_1300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1300};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9016], (modelica_real)data->simulationInfo->realParameter[9017], (modelica_real)data->simulationInfo->realParameter[9018], (modelica_real)data->simulationInfo->realParameter[9019], (modelica_real)data->simulationInfo->realParameter[9020], (modelica_real)data->simulationInfo->realParameter[9021]);
  data->localData[0]->realVars[816] /* points[12]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10986], data->localData[0]->realVars[211] /* T[12] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1301
 type: SIMPLE_ASSIGN
 y[12,2] = 0.717948717948718 * points[12].K[2]
 */
void Graph_eqFunction_1301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1301};
  data->localData[0]->realVars[1057] /* y[12,2] variable */ = (0.717948717948718) * (data->localData[0]->realVars[738] /* points[12]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1302
 type: SIMPLE_ASSIGN
 y[12,1] = 1.0 - 0.717948717948718 * points[12].K[2]
 */
void Graph_eqFunction_1302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1302};
  data->localData[0]->realVars[1056] /* y[12,1] variable */ = 1.0 - ((0.717948717948718) * (data->localData[0]->realVars[738] /* points[12]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1303(DATA*,threadData_t*);
void Graph_eqFunction_1304(DATA*,threadData_t*);
void Graph_eqFunction_1305(DATA*,threadData_t*);
void Graph_eqFunction_1306(DATA*,threadData_t*);
void Graph_eqFunction_1307(DATA*,threadData_t*);
void Graph_eqFunction_1308(DATA*,threadData_t*);
void Graph_eqFunction_1309(DATA*,threadData_t*);
void Graph_eqFunction_1310(DATA*,threadData_t*);
void Graph_eqFunction_1311(DATA*,threadData_t*);
void Graph_eqFunction_1312(DATA*,threadData_t*);
void Graph_eqFunction_1313(DATA*,threadData_t*);
void Graph_eqFunction_1314(DATA*,threadData_t*);
void Graph_eqFunction_1315(DATA*,threadData_t*);
void Graph_eqFunction_1316(DATA*,threadData_t*);
void Graph_eqFunction_1317(DATA*,threadData_t*);
void Graph_eqFunction_1318(DATA*,threadData_t*);
void Graph_eqFunction_1319(DATA*,threadData_t*);
void Graph_eqFunction_1320(DATA*,threadData_t*);
void Graph_eqFunction_1321(DATA*,threadData_t*);
void Graph_eqFunction_1322(DATA*,threadData_t*);
void Graph_eqFunction_1323(DATA*,threadData_t*);
/*
 equation index: 1324
 indexNonlinear: 52
 type: NONLINEAR
 
 vars: {T[13]}
 eqns: {1303, 1304, 1305, 1306, 1307, 1308, 1309, 1310, 1311, 1312, 1313, 1314, 1315, 1316, 1317, 1318, 1319, 1320, 1321, 1322, 1323}
 */
void Graph_eqFunction_1324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1324};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1324 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[52].nlsxOld[0] = data->localData[0]->realVars[212] /* T[13] variable */;
  retValue = solve_nonlinear_system(data, threadData, 52);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1324};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1324 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[212] /* T[13] variable */ = data->simulationInfo->nonlinearSystemData[52].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1325
 type: SIMPLE_ASSIGN
 y[13,2] = 0.6923076923076923 * points[13].K[2]
 */
void Graph_eqFunction_1325(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1325};
  data->localData[0]->realVars[1059] /* y[13,2] variable */ = (0.6923076923076923) * (data->localData[0]->realVars[740] /* points[13]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1326
 type: SIMPLE_ASSIGN
 y[13,1] = 1.0 - 0.6923076923076923 * points[13].K[2]
 */
void Graph_eqFunction_1326(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1326};
  data->localData[0]->realVars[1058] /* y[13,1] variable */ = 1.0 - ((0.6923076923076923) * (data->localData[0]->realVars[740] /* points[13]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1327
 type: SIMPLE_ASSIGN
 points[13]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[13].comp[2].LiqDen[1], points[13].comp[2].LiqDen[2], points[13].comp[2].LiqDen[3], points[13].comp[2].LiqDen[4], points[13].comp[2].LiqDen[5], points[13].comp[2].LiqDen[6]}, points[13].comp[2].Tc, T[13], 10000.0)
 */
void Graph_eqFunction_1327(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1327};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9034], (modelica_real)data->simulationInfo->realParameter[9035], (modelica_real)data->simulationInfo->realParameter[9036], (modelica_real)data->simulationInfo->realParameter[9037], (modelica_real)data->simulationInfo->realParameter[9038], (modelica_real)data->simulationInfo->realParameter[9039]);
  data->localData[0]->realVars[819] /* points[13]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10989], data->localData[0]->realVars[212] /* T[13] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1328
 type: SIMPLE_ASSIGN
 points[13]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[13].comp[1].LiqDen[1], points[13].comp[1].LiqDen[2], points[13].comp[1].LiqDen[3], points[13].comp[1].LiqDen[4], points[13].comp[1].LiqDen[5], points[13].comp[1].LiqDen[6]}, points[13].comp[1].Tc, T[13], 10000.0)
 */
void Graph_eqFunction_1328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1328};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9028], (modelica_real)data->simulationInfo->realParameter[9029], (modelica_real)data->simulationInfo->realParameter[9030], (modelica_real)data->simulationInfo->realParameter[9031], (modelica_real)data->simulationInfo->realParameter[9032], (modelica_real)data->simulationInfo->realParameter[9033]);
  data->localData[0]->realVars[818] /* points[13]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10988], data->localData[0]->realVars[212] /* T[13] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1329(DATA*,threadData_t*);
void Graph_eqFunction_1330(DATA*,threadData_t*);
void Graph_eqFunction_1331(DATA*,threadData_t*);
void Graph_eqFunction_1332(DATA*,threadData_t*);
void Graph_eqFunction_1333(DATA*,threadData_t*);
void Graph_eqFunction_1334(DATA*,threadData_t*);
void Graph_eqFunction_1335(DATA*,threadData_t*);
void Graph_eqFunction_1336(DATA*,threadData_t*);
void Graph_eqFunction_1337(DATA*,threadData_t*);
void Graph_eqFunction_1338(DATA*,threadData_t*);
void Graph_eqFunction_1339(DATA*,threadData_t*);
void Graph_eqFunction_1340(DATA*,threadData_t*);
void Graph_eqFunction_1341(DATA*,threadData_t*);
void Graph_eqFunction_1342(DATA*,threadData_t*);
void Graph_eqFunction_1343(DATA*,threadData_t*);
void Graph_eqFunction_1344(DATA*,threadData_t*);
void Graph_eqFunction_1345(DATA*,threadData_t*);
void Graph_eqFunction_1346(DATA*,threadData_t*);
void Graph_eqFunction_1347(DATA*,threadData_t*);
void Graph_eqFunction_1348(DATA*,threadData_t*);
void Graph_eqFunction_1349(DATA*,threadData_t*);
/*
 equation index: 1350
 indexNonlinear: 53
 type: NONLINEAR
 
 vars: {T[14]}
 eqns: {1329, 1330, 1331, 1332, 1333, 1334, 1335, 1336, 1337, 1338, 1339, 1340, 1341, 1342, 1343, 1344, 1345, 1346, 1347, 1348, 1349}
 */
void Graph_eqFunction_1350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1350};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1350 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[53].nlsxOld[0] = data->localData[0]->realVars[213] /* T[14] variable */;
  retValue = solve_nonlinear_system(data, threadData, 53);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1350};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1350 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[213] /* T[14] variable */ = data->simulationInfo->nonlinearSystemData[53].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1351
 type: SIMPLE_ASSIGN
 y[14,2] = 0.6666666666666667 * points[14].K[2]
 */
void Graph_eqFunction_1351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1351};
  data->localData[0]->realVars[1061] /* y[14,2] variable */ = (0.6666666666666667) * (data->localData[0]->realVars[742] /* points[14]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1352
 type: SIMPLE_ASSIGN
 y[14,1] = 1.0 - 0.6666666666666667 * points[14].K[2]
 */
void Graph_eqFunction_1352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1352};
  data->localData[0]->realVars[1060] /* y[14,1] variable */ = 1.0 - ((0.6666666666666667) * (data->localData[0]->realVars[742] /* points[14]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1353
 type: SIMPLE_ASSIGN
 points[14]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[14].comp[2].LiqDen[1], points[14].comp[2].LiqDen[2], points[14].comp[2].LiqDen[3], points[14].comp[2].LiqDen[4], points[14].comp[2].LiqDen[5], points[14].comp[2].LiqDen[6]}, points[14].comp[2].Tc, T[14], 10000.0)
 */
void Graph_eqFunction_1353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1353};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9046], (modelica_real)data->simulationInfo->realParameter[9047], (modelica_real)data->simulationInfo->realParameter[9048], (modelica_real)data->simulationInfo->realParameter[9049], (modelica_real)data->simulationInfo->realParameter[9050], (modelica_real)data->simulationInfo->realParameter[9051]);
  data->localData[0]->realVars[821] /* points[14]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10991], data->localData[0]->realVars[213] /* T[14] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1354
 type: SIMPLE_ASSIGN
 points[14]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[14].comp[1].LiqDen[1], points[14].comp[1].LiqDen[2], points[14].comp[1].LiqDen[3], points[14].comp[1].LiqDen[4], points[14].comp[1].LiqDen[5], points[14].comp[1].LiqDen[6]}, points[14].comp[1].Tc, T[14], 10000.0)
 */
void Graph_eqFunction_1354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1354};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9040], (modelica_real)data->simulationInfo->realParameter[9041], (modelica_real)data->simulationInfo->realParameter[9042], (modelica_real)data->simulationInfo->realParameter[9043], (modelica_real)data->simulationInfo->realParameter[9044], (modelica_real)data->simulationInfo->realParameter[9045]);
  data->localData[0]->realVars[820] /* points[14]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10990], data->localData[0]->realVars[213] /* T[14] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1355(DATA*,threadData_t*);
void Graph_eqFunction_1356(DATA*,threadData_t*);
void Graph_eqFunction_1357(DATA*,threadData_t*);
void Graph_eqFunction_1358(DATA*,threadData_t*);
void Graph_eqFunction_1359(DATA*,threadData_t*);
void Graph_eqFunction_1360(DATA*,threadData_t*);
void Graph_eqFunction_1361(DATA*,threadData_t*);
void Graph_eqFunction_1362(DATA*,threadData_t*);
void Graph_eqFunction_1363(DATA*,threadData_t*);
void Graph_eqFunction_1364(DATA*,threadData_t*);
void Graph_eqFunction_1365(DATA*,threadData_t*);
void Graph_eqFunction_1366(DATA*,threadData_t*);
void Graph_eqFunction_1367(DATA*,threadData_t*);
void Graph_eqFunction_1368(DATA*,threadData_t*);
void Graph_eqFunction_1369(DATA*,threadData_t*);
void Graph_eqFunction_1370(DATA*,threadData_t*);
void Graph_eqFunction_1371(DATA*,threadData_t*);
void Graph_eqFunction_1372(DATA*,threadData_t*);
void Graph_eqFunction_1373(DATA*,threadData_t*);
void Graph_eqFunction_1374(DATA*,threadData_t*);
void Graph_eqFunction_1375(DATA*,threadData_t*);
/*
 equation index: 1376
 indexNonlinear: 54
 type: NONLINEAR
 
 vars: {T[15]}
 eqns: {1355, 1356, 1357, 1358, 1359, 1360, 1361, 1362, 1363, 1364, 1365, 1366, 1367, 1368, 1369, 1370, 1371, 1372, 1373, 1374, 1375}
 */
void Graph_eqFunction_1376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1376};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1376 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[54].nlsxOld[0] = data->localData[0]->realVars[214] /* T[15] variable */;
  retValue = solve_nonlinear_system(data, threadData, 54);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1376};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1376 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[214] /* T[15] variable */ = data->simulationInfo->nonlinearSystemData[54].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1377
 type: SIMPLE_ASSIGN
 y[15,2] = 0.641025641025641 * points[15].K[2]
 */
void Graph_eqFunction_1377(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1377};
  data->localData[0]->realVars[1063] /* y[15,2] variable */ = (0.641025641025641) * (data->localData[0]->realVars[744] /* points[15]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1378
 type: SIMPLE_ASSIGN
 y[15,1] = 1.0 - 0.641025641025641 * points[15].K[2]
 */
void Graph_eqFunction_1378(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1378};
  data->localData[0]->realVars[1062] /* y[15,1] variable */ = 1.0 - ((0.641025641025641) * (data->localData[0]->realVars[744] /* points[15]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1379
 type: SIMPLE_ASSIGN
 points[15]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[15].comp[2].LiqDen[1], points[15].comp[2].LiqDen[2], points[15].comp[2].LiqDen[3], points[15].comp[2].LiqDen[4], points[15].comp[2].LiqDen[5], points[15].comp[2].LiqDen[6]}, points[15].comp[2].Tc, T[15], 10000.0)
 */
void Graph_eqFunction_1379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1379};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9058], (modelica_real)data->simulationInfo->realParameter[9059], (modelica_real)data->simulationInfo->realParameter[9060], (modelica_real)data->simulationInfo->realParameter[9061], (modelica_real)data->simulationInfo->realParameter[9062], (modelica_real)data->simulationInfo->realParameter[9063]);
  data->localData[0]->realVars[823] /* points[15]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10993], data->localData[0]->realVars[214] /* T[15] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1380
 type: SIMPLE_ASSIGN
 points[15]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[15].comp[1].LiqDen[1], points[15].comp[1].LiqDen[2], points[15].comp[1].LiqDen[3], points[15].comp[1].LiqDen[4], points[15].comp[1].LiqDen[5], points[15].comp[1].LiqDen[6]}, points[15].comp[1].Tc, T[15], 10000.0)
 */
void Graph_eqFunction_1380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1380};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9052], (modelica_real)data->simulationInfo->realParameter[9053], (modelica_real)data->simulationInfo->realParameter[9054], (modelica_real)data->simulationInfo->realParameter[9055], (modelica_real)data->simulationInfo->realParameter[9056], (modelica_real)data->simulationInfo->realParameter[9057]);
  data->localData[0]->realVars[822] /* points[15]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10992], data->localData[0]->realVars[214] /* T[15] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1381(DATA*,threadData_t*);
void Graph_eqFunction_1382(DATA*,threadData_t*);
void Graph_eqFunction_1383(DATA*,threadData_t*);
void Graph_eqFunction_1384(DATA*,threadData_t*);
void Graph_eqFunction_1385(DATA*,threadData_t*);
void Graph_eqFunction_1386(DATA*,threadData_t*);
void Graph_eqFunction_1387(DATA*,threadData_t*);
void Graph_eqFunction_1388(DATA*,threadData_t*);
void Graph_eqFunction_1389(DATA*,threadData_t*);
void Graph_eqFunction_1390(DATA*,threadData_t*);
void Graph_eqFunction_1391(DATA*,threadData_t*);
void Graph_eqFunction_1392(DATA*,threadData_t*);
void Graph_eqFunction_1393(DATA*,threadData_t*);
void Graph_eqFunction_1394(DATA*,threadData_t*);
void Graph_eqFunction_1395(DATA*,threadData_t*);
void Graph_eqFunction_1396(DATA*,threadData_t*);
void Graph_eqFunction_1397(DATA*,threadData_t*);
void Graph_eqFunction_1398(DATA*,threadData_t*);
void Graph_eqFunction_1399(DATA*,threadData_t*);
void Graph_eqFunction_1400(DATA*,threadData_t*);
void Graph_eqFunction_1401(DATA*,threadData_t*);
/*
 equation index: 1402
 indexNonlinear: 55
 type: NONLINEAR
 
 vars: {T[16]}
 eqns: {1381, 1382, 1383, 1384, 1385, 1386, 1387, 1388, 1389, 1390, 1391, 1392, 1393, 1394, 1395, 1396, 1397, 1398, 1399, 1400, 1401}
 */
void Graph_eqFunction_1402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1402};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1402 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[55].nlsxOld[0] = data->localData[0]->realVars[215] /* T[16] variable */;
  retValue = solve_nonlinear_system(data, threadData, 55);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1402};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1402 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[215] /* T[16] variable */ = data->simulationInfo->nonlinearSystemData[55].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1403
 type: SIMPLE_ASSIGN
 y[16,2] = 0.6153846153846154 * points[16].K[2]
 */
void Graph_eqFunction_1403(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1403};
  data->localData[0]->realVars[1065] /* y[16,2] variable */ = (0.6153846153846154) * (data->localData[0]->realVars[746] /* points[16]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1404
 type: SIMPLE_ASSIGN
 y[16,1] = 1.0 - 0.6153846153846154 * points[16].K[2]
 */
void Graph_eqFunction_1404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1404};
  data->localData[0]->realVars[1064] /* y[16,1] variable */ = 1.0 - ((0.6153846153846154) * (data->localData[0]->realVars[746] /* points[16]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1405
 type: SIMPLE_ASSIGN
 points[16]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[16].comp[2].LiqDen[1], points[16].comp[2].LiqDen[2], points[16].comp[2].LiqDen[3], points[16].comp[2].LiqDen[4], points[16].comp[2].LiqDen[5], points[16].comp[2].LiqDen[6]}, points[16].comp[2].Tc, T[16], 10000.0)
 */
void Graph_eqFunction_1405(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1405};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9070], (modelica_real)data->simulationInfo->realParameter[9071], (modelica_real)data->simulationInfo->realParameter[9072], (modelica_real)data->simulationInfo->realParameter[9073], (modelica_real)data->simulationInfo->realParameter[9074], (modelica_real)data->simulationInfo->realParameter[9075]);
  data->localData[0]->realVars[825] /* points[16]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10995], data->localData[0]->realVars[215] /* T[16] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1406
 type: SIMPLE_ASSIGN
 points[16]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[16].comp[1].LiqDen[1], points[16].comp[1].LiqDen[2], points[16].comp[1].LiqDen[3], points[16].comp[1].LiqDen[4], points[16].comp[1].LiqDen[5], points[16].comp[1].LiqDen[6]}, points[16].comp[1].Tc, T[16], 10000.0)
 */
void Graph_eqFunction_1406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1406};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9064], (modelica_real)data->simulationInfo->realParameter[9065], (modelica_real)data->simulationInfo->realParameter[9066], (modelica_real)data->simulationInfo->realParameter[9067], (modelica_real)data->simulationInfo->realParameter[9068], (modelica_real)data->simulationInfo->realParameter[9069]);
  data->localData[0]->realVars[824] /* points[16]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10994], data->localData[0]->realVars[215] /* T[16] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1407(DATA*,threadData_t*);
void Graph_eqFunction_1408(DATA*,threadData_t*);
void Graph_eqFunction_1409(DATA*,threadData_t*);
void Graph_eqFunction_1410(DATA*,threadData_t*);
void Graph_eqFunction_1411(DATA*,threadData_t*);
void Graph_eqFunction_1412(DATA*,threadData_t*);
void Graph_eqFunction_1413(DATA*,threadData_t*);
void Graph_eqFunction_1414(DATA*,threadData_t*);
void Graph_eqFunction_1415(DATA*,threadData_t*);
void Graph_eqFunction_1416(DATA*,threadData_t*);
void Graph_eqFunction_1417(DATA*,threadData_t*);
void Graph_eqFunction_1418(DATA*,threadData_t*);
void Graph_eqFunction_1419(DATA*,threadData_t*);
void Graph_eqFunction_1420(DATA*,threadData_t*);
void Graph_eqFunction_1421(DATA*,threadData_t*);
void Graph_eqFunction_1422(DATA*,threadData_t*);
void Graph_eqFunction_1423(DATA*,threadData_t*);
void Graph_eqFunction_1424(DATA*,threadData_t*);
void Graph_eqFunction_1425(DATA*,threadData_t*);
void Graph_eqFunction_1426(DATA*,threadData_t*);
void Graph_eqFunction_1427(DATA*,threadData_t*);
/*
 equation index: 1428
 indexNonlinear: 56
 type: NONLINEAR
 
 vars: {T[17]}
 eqns: {1407, 1408, 1409, 1410, 1411, 1412, 1413, 1414, 1415, 1416, 1417, 1418, 1419, 1420, 1421, 1422, 1423, 1424, 1425, 1426, 1427}
 */
void Graph_eqFunction_1428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1428};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1428 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[56].nlsxOld[0] = data->localData[0]->realVars[216] /* T[17] variable */;
  retValue = solve_nonlinear_system(data, threadData, 56);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1428};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1428 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[216] /* T[17] variable */ = data->simulationInfo->nonlinearSystemData[56].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1429
 type: SIMPLE_ASSIGN
 y[17,2] = 0.5897435897435898 * points[17].K[2]
 */
void Graph_eqFunction_1429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1429};
  data->localData[0]->realVars[1067] /* y[17,2] variable */ = (0.5897435897435898) * (data->localData[0]->realVars[748] /* points[17]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1430
 type: SIMPLE_ASSIGN
 y[17,1] = 1.0 - 0.5897435897435898 * points[17].K[2]
 */
void Graph_eqFunction_1430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1430};
  data->localData[0]->realVars[1066] /* y[17,1] variable */ = 1.0 - ((0.5897435897435898) * (data->localData[0]->realVars[748] /* points[17]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1431
 type: SIMPLE_ASSIGN
 points[17]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[17].comp[2].LiqDen[1], points[17].comp[2].LiqDen[2], points[17].comp[2].LiqDen[3], points[17].comp[2].LiqDen[4], points[17].comp[2].LiqDen[5], points[17].comp[2].LiqDen[6]}, points[17].comp[2].Tc, T[17], 10000.0)
 */
void Graph_eqFunction_1431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1431};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9082], (modelica_real)data->simulationInfo->realParameter[9083], (modelica_real)data->simulationInfo->realParameter[9084], (modelica_real)data->simulationInfo->realParameter[9085], (modelica_real)data->simulationInfo->realParameter[9086], (modelica_real)data->simulationInfo->realParameter[9087]);
  data->localData[0]->realVars[827] /* points[17]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10997], data->localData[0]->realVars[216] /* T[17] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1432
 type: SIMPLE_ASSIGN
 points[17]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[17].comp[1].LiqDen[1], points[17].comp[1].LiqDen[2], points[17].comp[1].LiqDen[3], points[17].comp[1].LiqDen[4], points[17].comp[1].LiqDen[5], points[17].comp[1].LiqDen[6]}, points[17].comp[1].Tc, T[17], 10000.0)
 */
void Graph_eqFunction_1432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1432};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9076], (modelica_real)data->simulationInfo->realParameter[9077], (modelica_real)data->simulationInfo->realParameter[9078], (modelica_real)data->simulationInfo->realParameter[9079], (modelica_real)data->simulationInfo->realParameter[9080], (modelica_real)data->simulationInfo->realParameter[9081]);
  data->localData[0]->realVars[826] /* points[17]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10996], data->localData[0]->realVars[216] /* T[17] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1433(DATA*,threadData_t*);
void Graph_eqFunction_1434(DATA*,threadData_t*);
void Graph_eqFunction_1435(DATA*,threadData_t*);
void Graph_eqFunction_1436(DATA*,threadData_t*);
void Graph_eqFunction_1437(DATA*,threadData_t*);
void Graph_eqFunction_1438(DATA*,threadData_t*);
void Graph_eqFunction_1439(DATA*,threadData_t*);
void Graph_eqFunction_1440(DATA*,threadData_t*);
void Graph_eqFunction_1441(DATA*,threadData_t*);
void Graph_eqFunction_1442(DATA*,threadData_t*);
void Graph_eqFunction_1443(DATA*,threadData_t*);
void Graph_eqFunction_1444(DATA*,threadData_t*);
void Graph_eqFunction_1445(DATA*,threadData_t*);
void Graph_eqFunction_1446(DATA*,threadData_t*);
void Graph_eqFunction_1447(DATA*,threadData_t*);
void Graph_eqFunction_1448(DATA*,threadData_t*);
void Graph_eqFunction_1449(DATA*,threadData_t*);
void Graph_eqFunction_1450(DATA*,threadData_t*);
void Graph_eqFunction_1451(DATA*,threadData_t*);
void Graph_eqFunction_1452(DATA*,threadData_t*);
void Graph_eqFunction_1453(DATA*,threadData_t*);
/*
 equation index: 1454
 indexNonlinear: 57
 type: NONLINEAR
 
 vars: {T[18]}
 eqns: {1433, 1434, 1435, 1436, 1437, 1438, 1439, 1440, 1441, 1442, 1443, 1444, 1445, 1446, 1447, 1448, 1449, 1450, 1451, 1452, 1453}
 */
void Graph_eqFunction_1454(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1454};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1454 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[57].nlsxOld[0] = data->localData[0]->realVars[217] /* T[18] variable */;
  retValue = solve_nonlinear_system(data, threadData, 57);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1454};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1454 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[217] /* T[18] variable */ = data->simulationInfo->nonlinearSystemData[57].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1455
 type: SIMPLE_ASSIGN
 points[18]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[18].comp[2].LiqDen[1], points[18].comp[2].LiqDen[2], points[18].comp[2].LiqDen[3], points[18].comp[2].LiqDen[4], points[18].comp[2].LiqDen[5], points[18].comp[2].LiqDen[6]}, points[18].comp[2].Tc, T[18], 10000.0)
 */
void Graph_eqFunction_1455(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1455};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9094], (modelica_real)data->simulationInfo->realParameter[9095], (modelica_real)data->simulationInfo->realParameter[9096], (modelica_real)data->simulationInfo->realParameter[9097], (modelica_real)data->simulationInfo->realParameter[9098], (modelica_real)data->simulationInfo->realParameter[9099]);
  data->localData[0]->realVars[829] /* points[18]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[10999], data->localData[0]->realVars[217] /* T[18] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1456
 type: SIMPLE_ASSIGN
 points[18]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[18].comp[1].LiqDen[1], points[18].comp[1].LiqDen[2], points[18].comp[1].LiqDen[3], points[18].comp[1].LiqDen[4], points[18].comp[1].LiqDen[5], points[18].comp[1].LiqDen[6]}, points[18].comp[1].Tc, T[18], 10000.0)
 */
void Graph_eqFunction_1456(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1456};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9088], (modelica_real)data->simulationInfo->realParameter[9089], (modelica_real)data->simulationInfo->realParameter[9090], (modelica_real)data->simulationInfo->realParameter[9091], (modelica_real)data->simulationInfo->realParameter[9092], (modelica_real)data->simulationInfo->realParameter[9093]);
  data->localData[0]->realVars[828] /* points[18]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[10998], data->localData[0]->realVars[217] /* T[18] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1457
 type: SIMPLE_ASSIGN
 y[18,2] = 0.5641025641025641 * points[18].K[2]
 */
void Graph_eqFunction_1457(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1457};
  data->localData[0]->realVars[1069] /* y[18,2] variable */ = (0.5641025641025641) * (data->localData[0]->realVars[750] /* points[18]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1458
 type: SIMPLE_ASSIGN
 y[18,1] = 1.0 - 0.5641025641025641 * points[18].K[2]
 */
void Graph_eqFunction_1458(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1458};
  data->localData[0]->realVars[1068] /* y[18,1] variable */ = 1.0 - ((0.5641025641025641) * (data->localData[0]->realVars[750] /* points[18]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1459(DATA*,threadData_t*);
void Graph_eqFunction_1460(DATA*,threadData_t*);
void Graph_eqFunction_1461(DATA*,threadData_t*);
void Graph_eqFunction_1462(DATA*,threadData_t*);
void Graph_eqFunction_1463(DATA*,threadData_t*);
void Graph_eqFunction_1464(DATA*,threadData_t*);
void Graph_eqFunction_1465(DATA*,threadData_t*);
void Graph_eqFunction_1466(DATA*,threadData_t*);
void Graph_eqFunction_1467(DATA*,threadData_t*);
void Graph_eqFunction_1468(DATA*,threadData_t*);
void Graph_eqFunction_1469(DATA*,threadData_t*);
void Graph_eqFunction_1470(DATA*,threadData_t*);
void Graph_eqFunction_1471(DATA*,threadData_t*);
void Graph_eqFunction_1472(DATA*,threadData_t*);
void Graph_eqFunction_1473(DATA*,threadData_t*);
void Graph_eqFunction_1474(DATA*,threadData_t*);
void Graph_eqFunction_1475(DATA*,threadData_t*);
void Graph_eqFunction_1476(DATA*,threadData_t*);
void Graph_eqFunction_1477(DATA*,threadData_t*);
void Graph_eqFunction_1478(DATA*,threadData_t*);
void Graph_eqFunction_1479(DATA*,threadData_t*);
/*
 equation index: 1480
 indexNonlinear: 58
 type: NONLINEAR
 
 vars: {T[19]}
 eqns: {1459, 1460, 1461, 1462, 1463, 1464, 1465, 1466, 1467, 1468, 1469, 1470, 1471, 1472, 1473, 1474, 1475, 1476, 1477, 1478, 1479}
 */
void Graph_eqFunction_1480(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1480};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1480 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[58].nlsxOld[0] = data->localData[0]->realVars[218] /* T[19] variable */;
  retValue = solve_nonlinear_system(data, threadData, 58);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1480};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1480 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[218] /* T[19] variable */ = data->simulationInfo->nonlinearSystemData[58].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1481
 type: SIMPLE_ASSIGN
 y[19,2] = 0.5384615384615384 * points[19].K[2]
 */
void Graph_eqFunction_1481(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1481};
  data->localData[0]->realVars[1071] /* y[19,2] variable */ = (0.5384615384615384) * (data->localData[0]->realVars[752] /* points[19]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1482
 type: SIMPLE_ASSIGN
 y[19,1] = 1.0 - 0.5384615384615384 * points[19].K[2]
 */
void Graph_eqFunction_1482(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1482};
  data->localData[0]->realVars[1070] /* y[19,1] variable */ = 1.0 - ((0.5384615384615384) * (data->localData[0]->realVars[752] /* points[19]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1483
 type: SIMPLE_ASSIGN
 points[19]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[19].comp[2].LiqDen[1], points[19].comp[2].LiqDen[2], points[19].comp[2].LiqDen[3], points[19].comp[2].LiqDen[4], points[19].comp[2].LiqDen[5], points[19].comp[2].LiqDen[6]}, points[19].comp[2].Tc, T[19], 10000.0)
 */
void Graph_eqFunction_1483(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1483};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9106], (modelica_real)data->simulationInfo->realParameter[9107], (modelica_real)data->simulationInfo->realParameter[9108], (modelica_real)data->simulationInfo->realParameter[9109], (modelica_real)data->simulationInfo->realParameter[9110], (modelica_real)data->simulationInfo->realParameter[9111]);
  data->localData[0]->realVars[831] /* points[19]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11001], data->localData[0]->realVars[218] /* T[19] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1484
 type: SIMPLE_ASSIGN
 points[19]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[19].comp[1].LiqDen[1], points[19].comp[1].LiqDen[2], points[19].comp[1].LiqDen[3], points[19].comp[1].LiqDen[4], points[19].comp[1].LiqDen[5], points[19].comp[1].LiqDen[6]}, points[19].comp[1].Tc, T[19], 10000.0)
 */
void Graph_eqFunction_1484(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1484};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9100], (modelica_real)data->simulationInfo->realParameter[9101], (modelica_real)data->simulationInfo->realParameter[9102], (modelica_real)data->simulationInfo->realParameter[9103], (modelica_real)data->simulationInfo->realParameter[9104], (modelica_real)data->simulationInfo->realParameter[9105]);
  data->localData[0]->realVars[830] /* points[19]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11000], data->localData[0]->realVars[218] /* T[19] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1485(DATA*,threadData_t*);
void Graph_eqFunction_1486(DATA*,threadData_t*);
void Graph_eqFunction_1487(DATA*,threadData_t*);
void Graph_eqFunction_1488(DATA*,threadData_t*);
void Graph_eqFunction_1489(DATA*,threadData_t*);
void Graph_eqFunction_1490(DATA*,threadData_t*);
void Graph_eqFunction_1491(DATA*,threadData_t*);
void Graph_eqFunction_1492(DATA*,threadData_t*);
void Graph_eqFunction_1493(DATA*,threadData_t*);
void Graph_eqFunction_1494(DATA*,threadData_t*);
void Graph_eqFunction_1495(DATA*,threadData_t*);
void Graph_eqFunction_1496(DATA*,threadData_t*);
void Graph_eqFunction_1497(DATA*,threadData_t*);
void Graph_eqFunction_1498(DATA*,threadData_t*);
void Graph_eqFunction_1499(DATA*,threadData_t*);
void Graph_eqFunction_1500(DATA*,threadData_t*);
void Graph_eqFunction_1501(DATA*,threadData_t*);
void Graph_eqFunction_1502(DATA*,threadData_t*);
void Graph_eqFunction_1503(DATA*,threadData_t*);
void Graph_eqFunction_1504(DATA*,threadData_t*);
void Graph_eqFunction_1505(DATA*,threadData_t*);
/*
 equation index: 1506
 indexNonlinear: 59
 type: NONLINEAR
 
 vars: {T[20]}
 eqns: {1485, 1486, 1487, 1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, 1496, 1497, 1498, 1499, 1500, 1501, 1502, 1503, 1504, 1505}
 */
void Graph_eqFunction_1506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1506};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1506 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[59].nlsxOld[0] = data->localData[0]->realVars[219] /* T[20] variable */;
  retValue = solve_nonlinear_system(data, threadData, 59);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1506};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1506 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[219] /* T[20] variable */ = data->simulationInfo->nonlinearSystemData[59].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1507
 type: SIMPLE_ASSIGN
 points[20]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[20].comp[2].LiqDen[1], points[20].comp[2].LiqDen[2], points[20].comp[2].LiqDen[3], points[20].comp[2].LiqDen[4], points[20].comp[2].LiqDen[5], points[20].comp[2].LiqDen[6]}, points[20].comp[2].Tc, T[20], 10000.0)
 */
void Graph_eqFunction_1507(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1507};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9118], (modelica_real)data->simulationInfo->realParameter[9119], (modelica_real)data->simulationInfo->realParameter[9120], (modelica_real)data->simulationInfo->realParameter[9121], (modelica_real)data->simulationInfo->realParameter[9122], (modelica_real)data->simulationInfo->realParameter[9123]);
  data->localData[0]->realVars[833] /* points[20]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11003], data->localData[0]->realVars[219] /* T[20] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1508
 type: SIMPLE_ASSIGN
 points[20]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[20].comp[1].LiqDen[1], points[20].comp[1].LiqDen[2], points[20].comp[1].LiqDen[3], points[20].comp[1].LiqDen[4], points[20].comp[1].LiqDen[5], points[20].comp[1].LiqDen[6]}, points[20].comp[1].Tc, T[20], 10000.0)
 */
void Graph_eqFunction_1508(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1508};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9112], (modelica_real)data->simulationInfo->realParameter[9113], (modelica_real)data->simulationInfo->realParameter[9114], (modelica_real)data->simulationInfo->realParameter[9115], (modelica_real)data->simulationInfo->realParameter[9116], (modelica_real)data->simulationInfo->realParameter[9117]);
  data->localData[0]->realVars[832] /* points[20]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11002], data->localData[0]->realVars[219] /* T[20] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1509
 type: SIMPLE_ASSIGN
 y[20,2] = 0.5128205128205128 * points[20].K[2]
 */
void Graph_eqFunction_1509(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1509};
  data->localData[0]->realVars[1073] /* y[20,2] variable */ = (0.5128205128205128) * (data->localData[0]->realVars[754] /* points[20]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1510
 type: SIMPLE_ASSIGN
 y[20,1] = 1.0 - 0.5128205128205128 * points[20].K[2]
 */
void Graph_eqFunction_1510(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1510};
  data->localData[0]->realVars[1072] /* y[20,1] variable */ = 1.0 - ((0.5128205128205128) * (data->localData[0]->realVars[754] /* points[20]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1511(DATA*,threadData_t*);
void Graph_eqFunction_1512(DATA*,threadData_t*);
void Graph_eqFunction_1513(DATA*,threadData_t*);
void Graph_eqFunction_1514(DATA*,threadData_t*);
void Graph_eqFunction_1515(DATA*,threadData_t*);
void Graph_eqFunction_1516(DATA*,threadData_t*);
void Graph_eqFunction_1517(DATA*,threadData_t*);
void Graph_eqFunction_1518(DATA*,threadData_t*);
void Graph_eqFunction_1519(DATA*,threadData_t*);
void Graph_eqFunction_1520(DATA*,threadData_t*);
void Graph_eqFunction_1521(DATA*,threadData_t*);
void Graph_eqFunction_1522(DATA*,threadData_t*);
void Graph_eqFunction_1523(DATA*,threadData_t*);
void Graph_eqFunction_1524(DATA*,threadData_t*);
void Graph_eqFunction_1525(DATA*,threadData_t*);
void Graph_eqFunction_1526(DATA*,threadData_t*);
void Graph_eqFunction_1527(DATA*,threadData_t*);
void Graph_eqFunction_1528(DATA*,threadData_t*);
void Graph_eqFunction_1529(DATA*,threadData_t*);
void Graph_eqFunction_1530(DATA*,threadData_t*);
void Graph_eqFunction_1531(DATA*,threadData_t*);
/*
 equation index: 1532
 indexNonlinear: 60
 type: NONLINEAR
 
 vars: {T[21]}
 eqns: {1511, 1512, 1513, 1514, 1515, 1516, 1517, 1518, 1519, 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527, 1528, 1529, 1530, 1531}
 */
void Graph_eqFunction_1532(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1532};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1532 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[60].nlsxOld[0] = data->localData[0]->realVars[220] /* T[21] variable */;
  retValue = solve_nonlinear_system(data, threadData, 60);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1532};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1532 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[220] /* T[21] variable */ = data->simulationInfo->nonlinearSystemData[60].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1533
 type: SIMPLE_ASSIGN
 points[21]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[21].comp[2].LiqDen[1], points[21].comp[2].LiqDen[2], points[21].comp[2].LiqDen[3], points[21].comp[2].LiqDen[4], points[21].comp[2].LiqDen[5], points[21].comp[2].LiqDen[6]}, points[21].comp[2].Tc, T[21], 10000.0)
 */
void Graph_eqFunction_1533(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1533};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9130], (modelica_real)data->simulationInfo->realParameter[9131], (modelica_real)data->simulationInfo->realParameter[9132], (modelica_real)data->simulationInfo->realParameter[9133], (modelica_real)data->simulationInfo->realParameter[9134], (modelica_real)data->simulationInfo->realParameter[9135]);
  data->localData[0]->realVars[835] /* points[21]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11005], data->localData[0]->realVars[220] /* T[21] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1534
 type: SIMPLE_ASSIGN
 points[21]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[21].comp[1].LiqDen[1], points[21].comp[1].LiqDen[2], points[21].comp[1].LiqDen[3], points[21].comp[1].LiqDen[4], points[21].comp[1].LiqDen[5], points[21].comp[1].LiqDen[6]}, points[21].comp[1].Tc, T[21], 10000.0)
 */
void Graph_eqFunction_1534(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1534};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9124], (modelica_real)data->simulationInfo->realParameter[9125], (modelica_real)data->simulationInfo->realParameter[9126], (modelica_real)data->simulationInfo->realParameter[9127], (modelica_real)data->simulationInfo->realParameter[9128], (modelica_real)data->simulationInfo->realParameter[9129]);
  data->localData[0]->realVars[834] /* points[21]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11004], data->localData[0]->realVars[220] /* T[21] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1535
 type: SIMPLE_ASSIGN
 y[21,2] = 0.4871794871794872 * points[21].K[2]
 */
void Graph_eqFunction_1535(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1535};
  data->localData[0]->realVars[1075] /* y[21,2] variable */ = (0.4871794871794872) * (data->localData[0]->realVars[756] /* points[21]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1536
 type: SIMPLE_ASSIGN
 y[21,1] = 1.0 - 0.4871794871794872 * points[21].K[2]
 */
void Graph_eqFunction_1536(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1536};
  data->localData[0]->realVars[1074] /* y[21,1] variable */ = 1.0 - ((0.4871794871794872) * (data->localData[0]->realVars[756] /* points[21]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1537(DATA*,threadData_t*);
void Graph_eqFunction_1538(DATA*,threadData_t*);
void Graph_eqFunction_1539(DATA*,threadData_t*);
void Graph_eqFunction_1540(DATA*,threadData_t*);
void Graph_eqFunction_1541(DATA*,threadData_t*);
void Graph_eqFunction_1542(DATA*,threadData_t*);
void Graph_eqFunction_1543(DATA*,threadData_t*);
void Graph_eqFunction_1544(DATA*,threadData_t*);
void Graph_eqFunction_1545(DATA*,threadData_t*);
void Graph_eqFunction_1546(DATA*,threadData_t*);
void Graph_eqFunction_1547(DATA*,threadData_t*);
void Graph_eqFunction_1548(DATA*,threadData_t*);
void Graph_eqFunction_1549(DATA*,threadData_t*);
void Graph_eqFunction_1550(DATA*,threadData_t*);
void Graph_eqFunction_1551(DATA*,threadData_t*);
void Graph_eqFunction_1552(DATA*,threadData_t*);
void Graph_eqFunction_1553(DATA*,threadData_t*);
void Graph_eqFunction_1554(DATA*,threadData_t*);
void Graph_eqFunction_1555(DATA*,threadData_t*);
void Graph_eqFunction_1556(DATA*,threadData_t*);
void Graph_eqFunction_1557(DATA*,threadData_t*);
/*
 equation index: 1558
 indexNonlinear: 61
 type: NONLINEAR
 
 vars: {T[22]}
 eqns: {1537, 1538, 1539, 1540, 1541, 1542, 1543, 1544, 1545, 1546, 1547, 1548, 1549, 1550, 1551, 1552, 1553, 1554, 1555, 1556, 1557}
 */
void Graph_eqFunction_1558(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1558};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1558 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[61].nlsxOld[0] = data->localData[0]->realVars[221] /* T[22] variable */;
  retValue = solve_nonlinear_system(data, threadData, 61);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1558};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1558 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[221] /* T[22] variable */ = data->simulationInfo->nonlinearSystemData[61].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1559
 type: SIMPLE_ASSIGN
 points[22]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[22].comp[2].LiqDen[1], points[22].comp[2].LiqDen[2], points[22].comp[2].LiqDen[3], points[22].comp[2].LiqDen[4], points[22].comp[2].LiqDen[5], points[22].comp[2].LiqDen[6]}, points[22].comp[2].Tc, T[22], 10000.0)
 */
void Graph_eqFunction_1559(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1559};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9142], (modelica_real)data->simulationInfo->realParameter[9143], (modelica_real)data->simulationInfo->realParameter[9144], (modelica_real)data->simulationInfo->realParameter[9145], (modelica_real)data->simulationInfo->realParameter[9146], (modelica_real)data->simulationInfo->realParameter[9147]);
  data->localData[0]->realVars[837] /* points[22]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11007], data->localData[0]->realVars[221] /* T[22] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1560
 type: SIMPLE_ASSIGN
 points[22]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[22].comp[1].LiqDen[1], points[22].comp[1].LiqDen[2], points[22].comp[1].LiqDen[3], points[22].comp[1].LiqDen[4], points[22].comp[1].LiqDen[5], points[22].comp[1].LiqDen[6]}, points[22].comp[1].Tc, T[22], 10000.0)
 */
void Graph_eqFunction_1560(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1560};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9136], (modelica_real)data->simulationInfo->realParameter[9137], (modelica_real)data->simulationInfo->realParameter[9138], (modelica_real)data->simulationInfo->realParameter[9139], (modelica_real)data->simulationInfo->realParameter[9140], (modelica_real)data->simulationInfo->realParameter[9141]);
  data->localData[0]->realVars[836] /* points[22]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11006], data->localData[0]->realVars[221] /* T[22] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1561
 type: SIMPLE_ASSIGN
 y[22,2] = 0.4615384615384616 * points[22].K[2]
 */
void Graph_eqFunction_1561(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1561};
  data->localData[0]->realVars[1077] /* y[22,2] variable */ = (0.4615384615384616) * (data->localData[0]->realVars[758] /* points[22]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1562
 type: SIMPLE_ASSIGN
 y[22,1] = 1.0 - 0.4615384615384616 * points[22].K[2]
 */
void Graph_eqFunction_1562(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1562};
  data->localData[0]->realVars[1076] /* y[22,1] variable */ = 1.0 - ((0.4615384615384616) * (data->localData[0]->realVars[758] /* points[22]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1563(DATA*,threadData_t*);
void Graph_eqFunction_1564(DATA*,threadData_t*);
void Graph_eqFunction_1565(DATA*,threadData_t*);
void Graph_eqFunction_1566(DATA*,threadData_t*);
void Graph_eqFunction_1567(DATA*,threadData_t*);
void Graph_eqFunction_1568(DATA*,threadData_t*);
void Graph_eqFunction_1569(DATA*,threadData_t*);
void Graph_eqFunction_1570(DATA*,threadData_t*);
void Graph_eqFunction_1571(DATA*,threadData_t*);
void Graph_eqFunction_1572(DATA*,threadData_t*);
void Graph_eqFunction_1573(DATA*,threadData_t*);
void Graph_eqFunction_1574(DATA*,threadData_t*);
void Graph_eqFunction_1575(DATA*,threadData_t*);
void Graph_eqFunction_1576(DATA*,threadData_t*);
void Graph_eqFunction_1577(DATA*,threadData_t*);
void Graph_eqFunction_1578(DATA*,threadData_t*);
void Graph_eqFunction_1579(DATA*,threadData_t*);
void Graph_eqFunction_1580(DATA*,threadData_t*);
void Graph_eqFunction_1581(DATA*,threadData_t*);
void Graph_eqFunction_1582(DATA*,threadData_t*);
void Graph_eqFunction_1583(DATA*,threadData_t*);
/*
 equation index: 1584
 indexNonlinear: 62
 type: NONLINEAR
 
 vars: {T[23]}
 eqns: {1563, 1564, 1565, 1566, 1567, 1568, 1569, 1570, 1571, 1572, 1573, 1574, 1575, 1576, 1577, 1578, 1579, 1580, 1581, 1582, 1583}
 */
void Graph_eqFunction_1584(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1584};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1584 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[62].nlsxOld[0] = data->localData[0]->realVars[222] /* T[23] variable */;
  retValue = solve_nonlinear_system(data, threadData, 62);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1584};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1584 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[222] /* T[23] variable */ = data->simulationInfo->nonlinearSystemData[62].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1585
 type: SIMPLE_ASSIGN
 y[23,2] = 0.4358974358974359 * points[23].K[2]
 */
void Graph_eqFunction_1585(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1585};
  data->localData[0]->realVars[1079] /* y[23,2] variable */ = (0.4358974358974359) * (data->localData[0]->realVars[760] /* points[23]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1586
 type: SIMPLE_ASSIGN
 y[23,1] = 1.0 - 0.4358974358974359 * points[23].K[2]
 */
void Graph_eqFunction_1586(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1586};
  data->localData[0]->realVars[1078] /* y[23,1] variable */ = 1.0 - ((0.4358974358974359) * (data->localData[0]->realVars[760] /* points[23]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1587
 type: SIMPLE_ASSIGN
 points[23]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[23].comp[2].LiqDen[1], points[23].comp[2].LiqDen[2], points[23].comp[2].LiqDen[3], points[23].comp[2].LiqDen[4], points[23].comp[2].LiqDen[5], points[23].comp[2].LiqDen[6]}, points[23].comp[2].Tc, T[23], 10000.0)
 */
void Graph_eqFunction_1587(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1587};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9154], (modelica_real)data->simulationInfo->realParameter[9155], (modelica_real)data->simulationInfo->realParameter[9156], (modelica_real)data->simulationInfo->realParameter[9157], (modelica_real)data->simulationInfo->realParameter[9158], (modelica_real)data->simulationInfo->realParameter[9159]);
  data->localData[0]->realVars[839] /* points[23]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11009], data->localData[0]->realVars[222] /* T[23] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1588
 type: SIMPLE_ASSIGN
 points[23]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[23].comp[1].LiqDen[1], points[23].comp[1].LiqDen[2], points[23].comp[1].LiqDen[3], points[23].comp[1].LiqDen[4], points[23].comp[1].LiqDen[5], points[23].comp[1].LiqDen[6]}, points[23].comp[1].Tc, T[23], 10000.0)
 */
void Graph_eqFunction_1588(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1588};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9148], (modelica_real)data->simulationInfo->realParameter[9149], (modelica_real)data->simulationInfo->realParameter[9150], (modelica_real)data->simulationInfo->realParameter[9151], (modelica_real)data->simulationInfo->realParameter[9152], (modelica_real)data->simulationInfo->realParameter[9153]);
  data->localData[0]->realVars[838] /* points[23]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11008], data->localData[0]->realVars[222] /* T[23] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1589(DATA*,threadData_t*);
void Graph_eqFunction_1590(DATA*,threadData_t*);
void Graph_eqFunction_1591(DATA*,threadData_t*);
void Graph_eqFunction_1592(DATA*,threadData_t*);
void Graph_eqFunction_1593(DATA*,threadData_t*);
void Graph_eqFunction_1594(DATA*,threadData_t*);
void Graph_eqFunction_1595(DATA*,threadData_t*);
void Graph_eqFunction_1596(DATA*,threadData_t*);
void Graph_eqFunction_1597(DATA*,threadData_t*);
void Graph_eqFunction_1598(DATA*,threadData_t*);
void Graph_eqFunction_1599(DATA*,threadData_t*);
void Graph_eqFunction_1600(DATA*,threadData_t*);
void Graph_eqFunction_1601(DATA*,threadData_t*);
void Graph_eqFunction_1602(DATA*,threadData_t*);
void Graph_eqFunction_1603(DATA*,threadData_t*);
void Graph_eqFunction_1604(DATA*,threadData_t*);
void Graph_eqFunction_1605(DATA*,threadData_t*);
void Graph_eqFunction_1606(DATA*,threadData_t*);
void Graph_eqFunction_1607(DATA*,threadData_t*);
void Graph_eqFunction_1608(DATA*,threadData_t*);
void Graph_eqFunction_1609(DATA*,threadData_t*);
/*
 equation index: 1610
 indexNonlinear: 63
 type: NONLINEAR
 
 vars: {T[24]}
 eqns: {1589, 1590, 1591, 1592, 1593, 1594, 1595, 1596, 1597, 1598, 1599, 1600, 1601, 1602, 1603, 1604, 1605, 1606, 1607, 1608, 1609}
 */
void Graph_eqFunction_1610(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1610};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1610 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[63].nlsxOld[0] = data->localData[0]->realVars[223] /* T[24] variable */;
  retValue = solve_nonlinear_system(data, threadData, 63);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1610};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1610 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[223] /* T[24] variable */ = data->simulationInfo->nonlinearSystemData[63].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1611
 type: SIMPLE_ASSIGN
 y[24,2] = 0.4102564102564102 * points[24].K[2]
 */
void Graph_eqFunction_1611(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1611};
  data->localData[0]->realVars[1081] /* y[24,2] variable */ = (0.4102564102564102) * (data->localData[0]->realVars[762] /* points[24]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1612
 type: SIMPLE_ASSIGN
 y[24,1] = 1.0 - 0.4102564102564102 * points[24].K[2]
 */
void Graph_eqFunction_1612(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1612};
  data->localData[0]->realVars[1080] /* y[24,1] variable */ = 1.0 - ((0.4102564102564102) * (data->localData[0]->realVars[762] /* points[24]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1613
 type: SIMPLE_ASSIGN
 points[24]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[24].comp[2].LiqDen[1], points[24].comp[2].LiqDen[2], points[24].comp[2].LiqDen[3], points[24].comp[2].LiqDen[4], points[24].comp[2].LiqDen[5], points[24].comp[2].LiqDen[6]}, points[24].comp[2].Tc, T[24], 10000.0)
 */
void Graph_eqFunction_1613(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1613};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9166], (modelica_real)data->simulationInfo->realParameter[9167], (modelica_real)data->simulationInfo->realParameter[9168], (modelica_real)data->simulationInfo->realParameter[9169], (modelica_real)data->simulationInfo->realParameter[9170], (modelica_real)data->simulationInfo->realParameter[9171]);
  data->localData[0]->realVars[841] /* points[24]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11011], data->localData[0]->realVars[223] /* T[24] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1614
 type: SIMPLE_ASSIGN
 points[24]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[24].comp[1].LiqDen[1], points[24].comp[1].LiqDen[2], points[24].comp[1].LiqDen[3], points[24].comp[1].LiqDen[4], points[24].comp[1].LiqDen[5], points[24].comp[1].LiqDen[6]}, points[24].comp[1].Tc, T[24], 10000.0)
 */
void Graph_eqFunction_1614(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1614};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9160], (modelica_real)data->simulationInfo->realParameter[9161], (modelica_real)data->simulationInfo->realParameter[9162], (modelica_real)data->simulationInfo->realParameter[9163], (modelica_real)data->simulationInfo->realParameter[9164], (modelica_real)data->simulationInfo->realParameter[9165]);
  data->localData[0]->realVars[840] /* points[24]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11010], data->localData[0]->realVars[223] /* T[24] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1615(DATA*,threadData_t*);
void Graph_eqFunction_1616(DATA*,threadData_t*);
void Graph_eqFunction_1617(DATA*,threadData_t*);
void Graph_eqFunction_1618(DATA*,threadData_t*);
void Graph_eqFunction_1619(DATA*,threadData_t*);
void Graph_eqFunction_1620(DATA*,threadData_t*);
void Graph_eqFunction_1621(DATA*,threadData_t*);
void Graph_eqFunction_1622(DATA*,threadData_t*);
void Graph_eqFunction_1623(DATA*,threadData_t*);
void Graph_eqFunction_1624(DATA*,threadData_t*);
void Graph_eqFunction_1625(DATA*,threadData_t*);
void Graph_eqFunction_1626(DATA*,threadData_t*);
void Graph_eqFunction_1627(DATA*,threadData_t*);
void Graph_eqFunction_1628(DATA*,threadData_t*);
void Graph_eqFunction_1629(DATA*,threadData_t*);
void Graph_eqFunction_1630(DATA*,threadData_t*);
void Graph_eqFunction_1631(DATA*,threadData_t*);
void Graph_eqFunction_1632(DATA*,threadData_t*);
void Graph_eqFunction_1633(DATA*,threadData_t*);
void Graph_eqFunction_1634(DATA*,threadData_t*);
void Graph_eqFunction_1635(DATA*,threadData_t*);
/*
 equation index: 1636
 indexNonlinear: 64
 type: NONLINEAR
 
 vars: {T[25]}
 eqns: {1615, 1616, 1617, 1618, 1619, 1620, 1621, 1622, 1623, 1624, 1625, 1626, 1627, 1628, 1629, 1630, 1631, 1632, 1633, 1634, 1635}
 */
void Graph_eqFunction_1636(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1636};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1636 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[64].nlsxOld[0] = data->localData[0]->realVars[224] /* T[25] variable */;
  retValue = solve_nonlinear_system(data, threadData, 64);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1636};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1636 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[224] /* T[25] variable */ = data->simulationInfo->nonlinearSystemData[64].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1637
 type: SIMPLE_ASSIGN
 points[25]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[25].comp[2].LiqDen[1], points[25].comp[2].LiqDen[2], points[25].comp[2].LiqDen[3], points[25].comp[2].LiqDen[4], points[25].comp[2].LiqDen[5], points[25].comp[2].LiqDen[6]}, points[25].comp[2].Tc, T[25], 10000.0)
 */
void Graph_eqFunction_1637(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1637};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9178], (modelica_real)data->simulationInfo->realParameter[9179], (modelica_real)data->simulationInfo->realParameter[9180], (modelica_real)data->simulationInfo->realParameter[9181], (modelica_real)data->simulationInfo->realParameter[9182], (modelica_real)data->simulationInfo->realParameter[9183]);
  data->localData[0]->realVars[843] /* points[25]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11013], data->localData[0]->realVars[224] /* T[25] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1638
 type: SIMPLE_ASSIGN
 points[25]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[25].comp[1].LiqDen[1], points[25].comp[1].LiqDen[2], points[25].comp[1].LiqDen[3], points[25].comp[1].LiqDen[4], points[25].comp[1].LiqDen[5], points[25].comp[1].LiqDen[6]}, points[25].comp[1].Tc, T[25], 10000.0)
 */
void Graph_eqFunction_1638(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1638};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9172], (modelica_real)data->simulationInfo->realParameter[9173], (modelica_real)data->simulationInfo->realParameter[9174], (modelica_real)data->simulationInfo->realParameter[9175], (modelica_real)data->simulationInfo->realParameter[9176], (modelica_real)data->simulationInfo->realParameter[9177]);
  data->localData[0]->realVars[842] /* points[25]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11012], data->localData[0]->realVars[224] /* T[25] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1639
 type: SIMPLE_ASSIGN
 y[25,2] = 0.3846153846153846 * points[25].K[2]
 */
void Graph_eqFunction_1639(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1639};
  data->localData[0]->realVars[1083] /* y[25,2] variable */ = (0.3846153846153846) * (data->localData[0]->realVars[764] /* points[25]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1640
 type: SIMPLE_ASSIGN
 y[25,1] = 1.0 - 0.3846153846153846 * points[25].K[2]
 */
void Graph_eqFunction_1640(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1640};
  data->localData[0]->realVars[1082] /* y[25,1] variable */ = 1.0 - ((0.3846153846153846) * (data->localData[0]->realVars[764] /* points[25]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1641(DATA*,threadData_t*);
void Graph_eqFunction_1642(DATA*,threadData_t*);
void Graph_eqFunction_1643(DATA*,threadData_t*);
void Graph_eqFunction_1644(DATA*,threadData_t*);
void Graph_eqFunction_1645(DATA*,threadData_t*);
void Graph_eqFunction_1646(DATA*,threadData_t*);
void Graph_eqFunction_1647(DATA*,threadData_t*);
void Graph_eqFunction_1648(DATA*,threadData_t*);
void Graph_eqFunction_1649(DATA*,threadData_t*);
void Graph_eqFunction_1650(DATA*,threadData_t*);
void Graph_eqFunction_1651(DATA*,threadData_t*);
void Graph_eqFunction_1652(DATA*,threadData_t*);
void Graph_eqFunction_1653(DATA*,threadData_t*);
void Graph_eqFunction_1654(DATA*,threadData_t*);
void Graph_eqFunction_1655(DATA*,threadData_t*);
void Graph_eqFunction_1656(DATA*,threadData_t*);
void Graph_eqFunction_1657(DATA*,threadData_t*);
void Graph_eqFunction_1658(DATA*,threadData_t*);
void Graph_eqFunction_1659(DATA*,threadData_t*);
void Graph_eqFunction_1660(DATA*,threadData_t*);
void Graph_eqFunction_1661(DATA*,threadData_t*);
/*
 equation index: 1662
 indexNonlinear: 65
 type: NONLINEAR
 
 vars: {T[26]}
 eqns: {1641, 1642, 1643, 1644, 1645, 1646, 1647, 1648, 1649, 1650, 1651, 1652, 1653, 1654, 1655, 1656, 1657, 1658, 1659, 1660, 1661}
 */
void Graph_eqFunction_1662(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1662};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1662 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[65].nlsxOld[0] = data->localData[0]->realVars[225] /* T[26] variable */;
  retValue = solve_nonlinear_system(data, threadData, 65);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1662};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1662 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[225] /* T[26] variable */ = data->simulationInfo->nonlinearSystemData[65].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1663
 type: SIMPLE_ASSIGN
 y[26,2] = 0.3589743589743589 * points[26].K[2]
 */
void Graph_eqFunction_1663(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1663};
  data->localData[0]->realVars[1085] /* y[26,2] variable */ = (0.3589743589743589) * (data->localData[0]->realVars[766] /* points[26]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1664
 type: SIMPLE_ASSIGN
 y[26,1] = 1.0 - 0.3589743589743589 * points[26].K[2]
 */
void Graph_eqFunction_1664(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1664};
  data->localData[0]->realVars[1084] /* y[26,1] variable */ = 1.0 - ((0.3589743589743589) * (data->localData[0]->realVars[766] /* points[26]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1665
 type: SIMPLE_ASSIGN
 points[26]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[26].comp[2].LiqDen[1], points[26].comp[2].LiqDen[2], points[26].comp[2].LiqDen[3], points[26].comp[2].LiqDen[4], points[26].comp[2].LiqDen[5], points[26].comp[2].LiqDen[6]}, points[26].comp[2].Tc, T[26], 10000.0)
 */
void Graph_eqFunction_1665(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1665};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9190], (modelica_real)data->simulationInfo->realParameter[9191], (modelica_real)data->simulationInfo->realParameter[9192], (modelica_real)data->simulationInfo->realParameter[9193], (modelica_real)data->simulationInfo->realParameter[9194], (modelica_real)data->simulationInfo->realParameter[9195]);
  data->localData[0]->realVars[845] /* points[26]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11015], data->localData[0]->realVars[225] /* T[26] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1666
 type: SIMPLE_ASSIGN
 points[26]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[26].comp[1].LiqDen[1], points[26].comp[1].LiqDen[2], points[26].comp[1].LiqDen[3], points[26].comp[1].LiqDen[4], points[26].comp[1].LiqDen[5], points[26].comp[1].LiqDen[6]}, points[26].comp[1].Tc, T[26], 10000.0)
 */
void Graph_eqFunction_1666(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1666};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9184], (modelica_real)data->simulationInfo->realParameter[9185], (modelica_real)data->simulationInfo->realParameter[9186], (modelica_real)data->simulationInfo->realParameter[9187], (modelica_real)data->simulationInfo->realParameter[9188], (modelica_real)data->simulationInfo->realParameter[9189]);
  data->localData[0]->realVars[844] /* points[26]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11014], data->localData[0]->realVars[225] /* T[26] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1667(DATA*,threadData_t*);
void Graph_eqFunction_1668(DATA*,threadData_t*);
void Graph_eqFunction_1669(DATA*,threadData_t*);
void Graph_eqFunction_1670(DATA*,threadData_t*);
void Graph_eqFunction_1671(DATA*,threadData_t*);
void Graph_eqFunction_1672(DATA*,threadData_t*);
void Graph_eqFunction_1673(DATA*,threadData_t*);
void Graph_eqFunction_1674(DATA*,threadData_t*);
void Graph_eqFunction_1675(DATA*,threadData_t*);
void Graph_eqFunction_1676(DATA*,threadData_t*);
void Graph_eqFunction_1677(DATA*,threadData_t*);
void Graph_eqFunction_1678(DATA*,threadData_t*);
void Graph_eqFunction_1679(DATA*,threadData_t*);
void Graph_eqFunction_1680(DATA*,threadData_t*);
void Graph_eqFunction_1681(DATA*,threadData_t*);
void Graph_eqFunction_1682(DATA*,threadData_t*);
void Graph_eqFunction_1683(DATA*,threadData_t*);
void Graph_eqFunction_1684(DATA*,threadData_t*);
void Graph_eqFunction_1685(DATA*,threadData_t*);
void Graph_eqFunction_1686(DATA*,threadData_t*);
void Graph_eqFunction_1687(DATA*,threadData_t*);
/*
 equation index: 1688
 indexNonlinear: 66
 type: NONLINEAR
 
 vars: {T[27]}
 eqns: {1667, 1668, 1669, 1670, 1671, 1672, 1673, 1674, 1675, 1676, 1677, 1678, 1679, 1680, 1681, 1682, 1683, 1684, 1685, 1686, 1687}
 */
void Graph_eqFunction_1688(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1688};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1688 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[66].nlsxOld[0] = data->localData[0]->realVars[226] /* T[27] variable */;
  retValue = solve_nonlinear_system(data, threadData, 66);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1688};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1688 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[226] /* T[27] variable */ = data->simulationInfo->nonlinearSystemData[66].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1689
 type: SIMPLE_ASSIGN
 y[27,2] = 0.3333333333333334 * points[27].K[2]
 */
void Graph_eqFunction_1689(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1689};
  data->localData[0]->realVars[1087] /* y[27,2] variable */ = (0.3333333333333334) * (data->localData[0]->realVars[768] /* points[27]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1690
 type: SIMPLE_ASSIGN
 y[27,1] = 1.0 - 0.3333333333333334 * points[27].K[2]
 */
void Graph_eqFunction_1690(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1690};
  data->localData[0]->realVars[1086] /* y[27,1] variable */ = 1.0 - ((0.3333333333333334) * (data->localData[0]->realVars[768] /* points[27]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1691
 type: SIMPLE_ASSIGN
 points[27]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[27].comp[2].LiqDen[1], points[27].comp[2].LiqDen[2], points[27].comp[2].LiqDen[3], points[27].comp[2].LiqDen[4], points[27].comp[2].LiqDen[5], points[27].comp[2].LiqDen[6]}, points[27].comp[2].Tc, T[27], 10000.0)
 */
void Graph_eqFunction_1691(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1691};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9202], (modelica_real)data->simulationInfo->realParameter[9203], (modelica_real)data->simulationInfo->realParameter[9204], (modelica_real)data->simulationInfo->realParameter[9205], (modelica_real)data->simulationInfo->realParameter[9206], (modelica_real)data->simulationInfo->realParameter[9207]);
  data->localData[0]->realVars[847] /* points[27]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11017], data->localData[0]->realVars[226] /* T[27] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1692
 type: SIMPLE_ASSIGN
 points[27]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[27].comp[1].LiqDen[1], points[27].comp[1].LiqDen[2], points[27].comp[1].LiqDen[3], points[27].comp[1].LiqDen[4], points[27].comp[1].LiqDen[5], points[27].comp[1].LiqDen[6]}, points[27].comp[1].Tc, T[27], 10000.0)
 */
void Graph_eqFunction_1692(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1692};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9196], (modelica_real)data->simulationInfo->realParameter[9197], (modelica_real)data->simulationInfo->realParameter[9198], (modelica_real)data->simulationInfo->realParameter[9199], (modelica_real)data->simulationInfo->realParameter[9200], (modelica_real)data->simulationInfo->realParameter[9201]);
  data->localData[0]->realVars[846] /* points[27]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11016], data->localData[0]->realVars[226] /* T[27] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1693(DATA*,threadData_t*);
void Graph_eqFunction_1694(DATA*,threadData_t*);
void Graph_eqFunction_1695(DATA*,threadData_t*);
void Graph_eqFunction_1696(DATA*,threadData_t*);
void Graph_eqFunction_1697(DATA*,threadData_t*);
void Graph_eqFunction_1698(DATA*,threadData_t*);
void Graph_eqFunction_1699(DATA*,threadData_t*);
void Graph_eqFunction_1700(DATA*,threadData_t*);
void Graph_eqFunction_1701(DATA*,threadData_t*);
void Graph_eqFunction_1702(DATA*,threadData_t*);
void Graph_eqFunction_1703(DATA*,threadData_t*);
void Graph_eqFunction_1704(DATA*,threadData_t*);
void Graph_eqFunction_1705(DATA*,threadData_t*);
void Graph_eqFunction_1706(DATA*,threadData_t*);
void Graph_eqFunction_1707(DATA*,threadData_t*);
void Graph_eqFunction_1708(DATA*,threadData_t*);
void Graph_eqFunction_1709(DATA*,threadData_t*);
void Graph_eqFunction_1710(DATA*,threadData_t*);
void Graph_eqFunction_1711(DATA*,threadData_t*);
void Graph_eqFunction_1712(DATA*,threadData_t*);
void Graph_eqFunction_1713(DATA*,threadData_t*);
/*
 equation index: 1714
 indexNonlinear: 67
 type: NONLINEAR
 
 vars: {T[28]}
 eqns: {1693, 1694, 1695, 1696, 1697, 1698, 1699, 1700, 1701, 1702, 1703, 1704, 1705, 1706, 1707, 1708, 1709, 1710, 1711, 1712, 1713}
 */
void Graph_eqFunction_1714(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1714};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1714 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[67].nlsxOld[0] = data->localData[0]->realVars[227] /* T[28] variable */;
  retValue = solve_nonlinear_system(data, threadData, 67);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1714};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1714 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[227] /* T[28] variable */ = data->simulationInfo->nonlinearSystemData[67].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1715
 type: SIMPLE_ASSIGN
 points[28]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[28].comp[2].LiqDen[1], points[28].comp[2].LiqDen[2], points[28].comp[2].LiqDen[3], points[28].comp[2].LiqDen[4], points[28].comp[2].LiqDen[5], points[28].comp[2].LiqDen[6]}, points[28].comp[2].Tc, T[28], 10000.0)
 */
void Graph_eqFunction_1715(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1715};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9214], (modelica_real)data->simulationInfo->realParameter[9215], (modelica_real)data->simulationInfo->realParameter[9216], (modelica_real)data->simulationInfo->realParameter[9217], (modelica_real)data->simulationInfo->realParameter[9218], (modelica_real)data->simulationInfo->realParameter[9219]);
  data->localData[0]->realVars[849] /* points[28]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11019], data->localData[0]->realVars[227] /* T[28] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1716
 type: SIMPLE_ASSIGN
 points[28]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[28].comp[1].LiqDen[1], points[28].comp[1].LiqDen[2], points[28].comp[1].LiqDen[3], points[28].comp[1].LiqDen[4], points[28].comp[1].LiqDen[5], points[28].comp[1].LiqDen[6]}, points[28].comp[1].Tc, T[28], 10000.0)
 */
void Graph_eqFunction_1716(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1716};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9208], (modelica_real)data->simulationInfo->realParameter[9209], (modelica_real)data->simulationInfo->realParameter[9210], (modelica_real)data->simulationInfo->realParameter[9211], (modelica_real)data->simulationInfo->realParameter[9212], (modelica_real)data->simulationInfo->realParameter[9213]);
  data->localData[0]->realVars[848] /* points[28]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11018], data->localData[0]->realVars[227] /* T[28] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1717
 type: SIMPLE_ASSIGN
 y[28,2] = 0.3076923076923077 * points[28].K[2]
 */
void Graph_eqFunction_1717(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1717};
  data->localData[0]->realVars[1089] /* y[28,2] variable */ = (0.3076923076923077) * (data->localData[0]->realVars[770] /* points[28]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1718
 type: SIMPLE_ASSIGN
 y[28,1] = 1.0 - 0.3076923076923077 * points[28].K[2]
 */
void Graph_eqFunction_1718(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1718};
  data->localData[0]->realVars[1088] /* y[28,1] variable */ = 1.0 - ((0.3076923076923077) * (data->localData[0]->realVars[770] /* points[28]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1719(DATA*,threadData_t*);
void Graph_eqFunction_1720(DATA*,threadData_t*);
void Graph_eqFunction_1721(DATA*,threadData_t*);
void Graph_eqFunction_1722(DATA*,threadData_t*);
void Graph_eqFunction_1723(DATA*,threadData_t*);
void Graph_eqFunction_1724(DATA*,threadData_t*);
void Graph_eqFunction_1725(DATA*,threadData_t*);
void Graph_eqFunction_1726(DATA*,threadData_t*);
void Graph_eqFunction_1727(DATA*,threadData_t*);
void Graph_eqFunction_1728(DATA*,threadData_t*);
void Graph_eqFunction_1729(DATA*,threadData_t*);
void Graph_eqFunction_1730(DATA*,threadData_t*);
void Graph_eqFunction_1731(DATA*,threadData_t*);
void Graph_eqFunction_1732(DATA*,threadData_t*);
void Graph_eqFunction_1733(DATA*,threadData_t*);
void Graph_eqFunction_1734(DATA*,threadData_t*);
void Graph_eqFunction_1735(DATA*,threadData_t*);
void Graph_eqFunction_1736(DATA*,threadData_t*);
void Graph_eqFunction_1737(DATA*,threadData_t*);
void Graph_eqFunction_1738(DATA*,threadData_t*);
void Graph_eqFunction_1739(DATA*,threadData_t*);
/*
 equation index: 1740
 indexNonlinear: 68
 type: NONLINEAR
 
 vars: {T[29]}
 eqns: {1719, 1720, 1721, 1722, 1723, 1724, 1725, 1726, 1727, 1728, 1729, 1730, 1731, 1732, 1733, 1734, 1735, 1736, 1737, 1738, 1739}
 */
void Graph_eqFunction_1740(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1740};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1740 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[68].nlsxOld[0] = data->localData[0]->realVars[228] /* T[29] variable */;
  retValue = solve_nonlinear_system(data, threadData, 68);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1740};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1740 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[228] /* T[29] variable */ = data->simulationInfo->nonlinearSystemData[68].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1741
 type: SIMPLE_ASSIGN
 points[29]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[29].comp[2].LiqDen[1], points[29].comp[2].LiqDen[2], points[29].comp[2].LiqDen[3], points[29].comp[2].LiqDen[4], points[29].comp[2].LiqDen[5], points[29].comp[2].LiqDen[6]}, points[29].comp[2].Tc, T[29], 10000.0)
 */
void Graph_eqFunction_1741(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1741};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9226], (modelica_real)data->simulationInfo->realParameter[9227], (modelica_real)data->simulationInfo->realParameter[9228], (modelica_real)data->simulationInfo->realParameter[9229], (modelica_real)data->simulationInfo->realParameter[9230], (modelica_real)data->simulationInfo->realParameter[9231]);
  data->localData[0]->realVars[851] /* points[29]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11021], data->localData[0]->realVars[228] /* T[29] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1742
 type: SIMPLE_ASSIGN
 points[29]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[29].comp[1].LiqDen[1], points[29].comp[1].LiqDen[2], points[29].comp[1].LiqDen[3], points[29].comp[1].LiqDen[4], points[29].comp[1].LiqDen[5], points[29].comp[1].LiqDen[6]}, points[29].comp[1].Tc, T[29], 10000.0)
 */
void Graph_eqFunction_1742(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1742};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9220], (modelica_real)data->simulationInfo->realParameter[9221], (modelica_real)data->simulationInfo->realParameter[9222], (modelica_real)data->simulationInfo->realParameter[9223], (modelica_real)data->simulationInfo->realParameter[9224], (modelica_real)data->simulationInfo->realParameter[9225]);
  data->localData[0]->realVars[850] /* points[29]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11020], data->localData[0]->realVars[228] /* T[29] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1743
 type: SIMPLE_ASSIGN
 y[29,2] = 0.2820512820512821 * points[29].K[2]
 */
void Graph_eqFunction_1743(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1743};
  data->localData[0]->realVars[1091] /* y[29,2] variable */ = (0.2820512820512821) * (data->localData[0]->realVars[772] /* points[29]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1744
 type: SIMPLE_ASSIGN
 y[29,1] = 1.0 - 0.2820512820512821 * points[29].K[2]
 */
void Graph_eqFunction_1744(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1744};
  data->localData[0]->realVars[1090] /* y[29,1] variable */ = 1.0 - ((0.2820512820512821) * (data->localData[0]->realVars[772] /* points[29]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1745(DATA*,threadData_t*);
void Graph_eqFunction_1746(DATA*,threadData_t*);
void Graph_eqFunction_1747(DATA*,threadData_t*);
void Graph_eqFunction_1748(DATA*,threadData_t*);
void Graph_eqFunction_1749(DATA*,threadData_t*);
void Graph_eqFunction_1750(DATA*,threadData_t*);
void Graph_eqFunction_1751(DATA*,threadData_t*);
void Graph_eqFunction_1752(DATA*,threadData_t*);
void Graph_eqFunction_1753(DATA*,threadData_t*);
void Graph_eqFunction_1754(DATA*,threadData_t*);
void Graph_eqFunction_1755(DATA*,threadData_t*);
void Graph_eqFunction_1756(DATA*,threadData_t*);
void Graph_eqFunction_1757(DATA*,threadData_t*);
void Graph_eqFunction_1758(DATA*,threadData_t*);
void Graph_eqFunction_1759(DATA*,threadData_t*);
void Graph_eqFunction_1760(DATA*,threadData_t*);
void Graph_eqFunction_1761(DATA*,threadData_t*);
void Graph_eqFunction_1762(DATA*,threadData_t*);
void Graph_eqFunction_1763(DATA*,threadData_t*);
void Graph_eqFunction_1764(DATA*,threadData_t*);
void Graph_eqFunction_1765(DATA*,threadData_t*);
/*
 equation index: 1766
 indexNonlinear: 69
 type: NONLINEAR
 
 vars: {T[30]}
 eqns: {1745, 1746, 1747, 1748, 1749, 1750, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758, 1759, 1760, 1761, 1762, 1763, 1764, 1765}
 */
void Graph_eqFunction_1766(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1766};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1766 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[69].nlsxOld[0] = data->localData[0]->realVars[229] /* T[30] variable */;
  retValue = solve_nonlinear_system(data, threadData, 69);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1766};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1766 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[229] /* T[30] variable */ = data->simulationInfo->nonlinearSystemData[69].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1767
 type: SIMPLE_ASSIGN
 points[30]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[30].comp[2].LiqDen[1], points[30].comp[2].LiqDen[2], points[30].comp[2].LiqDen[3], points[30].comp[2].LiqDen[4], points[30].comp[2].LiqDen[5], points[30].comp[2].LiqDen[6]}, points[30].comp[2].Tc, T[30], 10000.0)
 */
void Graph_eqFunction_1767(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1767};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9238], (modelica_real)data->simulationInfo->realParameter[9239], (modelica_real)data->simulationInfo->realParameter[9240], (modelica_real)data->simulationInfo->realParameter[9241], (modelica_real)data->simulationInfo->realParameter[9242], (modelica_real)data->simulationInfo->realParameter[9243]);
  data->localData[0]->realVars[853] /* points[30]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11023], data->localData[0]->realVars[229] /* T[30] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1768
 type: SIMPLE_ASSIGN
 points[30]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[30].comp[1].LiqDen[1], points[30].comp[1].LiqDen[2], points[30].comp[1].LiqDen[3], points[30].comp[1].LiqDen[4], points[30].comp[1].LiqDen[5], points[30].comp[1].LiqDen[6]}, points[30].comp[1].Tc, T[30], 10000.0)
 */
void Graph_eqFunction_1768(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1768};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9232], (modelica_real)data->simulationInfo->realParameter[9233], (modelica_real)data->simulationInfo->realParameter[9234], (modelica_real)data->simulationInfo->realParameter[9235], (modelica_real)data->simulationInfo->realParameter[9236], (modelica_real)data->simulationInfo->realParameter[9237]);
  data->localData[0]->realVars[852] /* points[30]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11022], data->localData[0]->realVars[229] /* T[30] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1769
 type: SIMPLE_ASSIGN
 y[30,2] = 0.2564102564102564 * points[30].K[2]
 */
void Graph_eqFunction_1769(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1769};
  data->localData[0]->realVars[1093] /* y[30,2] variable */ = (0.2564102564102564) * (data->localData[0]->realVars[774] /* points[30]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1770
 type: SIMPLE_ASSIGN
 y[30,1] = 1.0 - 0.2564102564102564 * points[30].K[2]
 */
void Graph_eqFunction_1770(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1770};
  data->localData[0]->realVars[1092] /* y[30,1] variable */ = 1.0 - ((0.2564102564102564) * (data->localData[0]->realVars[774] /* points[30]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1771(DATA*,threadData_t*);
void Graph_eqFunction_1772(DATA*,threadData_t*);
void Graph_eqFunction_1773(DATA*,threadData_t*);
void Graph_eqFunction_1774(DATA*,threadData_t*);
void Graph_eqFunction_1775(DATA*,threadData_t*);
void Graph_eqFunction_1776(DATA*,threadData_t*);
void Graph_eqFunction_1777(DATA*,threadData_t*);
void Graph_eqFunction_1778(DATA*,threadData_t*);
void Graph_eqFunction_1779(DATA*,threadData_t*);
void Graph_eqFunction_1780(DATA*,threadData_t*);
void Graph_eqFunction_1781(DATA*,threadData_t*);
void Graph_eqFunction_1782(DATA*,threadData_t*);
void Graph_eqFunction_1783(DATA*,threadData_t*);
void Graph_eqFunction_1784(DATA*,threadData_t*);
void Graph_eqFunction_1785(DATA*,threadData_t*);
void Graph_eqFunction_1786(DATA*,threadData_t*);
void Graph_eqFunction_1787(DATA*,threadData_t*);
void Graph_eqFunction_1788(DATA*,threadData_t*);
void Graph_eqFunction_1789(DATA*,threadData_t*);
void Graph_eqFunction_1790(DATA*,threadData_t*);
void Graph_eqFunction_1791(DATA*,threadData_t*);
/*
 equation index: 1792
 indexNonlinear: 70
 type: NONLINEAR
 
 vars: {T[31]}
 eqns: {1771, 1772, 1773, 1774, 1775, 1776, 1777, 1778, 1779, 1780, 1781, 1782, 1783, 1784, 1785, 1786, 1787, 1788, 1789, 1790, 1791}
 */
void Graph_eqFunction_1792(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1792};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1792 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[70].nlsxOld[0] = data->localData[0]->realVars[230] /* T[31] variable */;
  retValue = solve_nonlinear_system(data, threadData, 70);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1792};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1792 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[230] /* T[31] variable */ = data->simulationInfo->nonlinearSystemData[70].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1793
 type: SIMPLE_ASSIGN
 points[31]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[31].comp[2].LiqDen[1], points[31].comp[2].LiqDen[2], points[31].comp[2].LiqDen[3], points[31].comp[2].LiqDen[4], points[31].comp[2].LiqDen[5], points[31].comp[2].LiqDen[6]}, points[31].comp[2].Tc, T[31], 10000.0)
 */
void Graph_eqFunction_1793(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1793};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9250], (modelica_real)data->simulationInfo->realParameter[9251], (modelica_real)data->simulationInfo->realParameter[9252], (modelica_real)data->simulationInfo->realParameter[9253], (modelica_real)data->simulationInfo->realParameter[9254], (modelica_real)data->simulationInfo->realParameter[9255]);
  data->localData[0]->realVars[855] /* points[31]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11025], data->localData[0]->realVars[230] /* T[31] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1794
 type: SIMPLE_ASSIGN
 points[31]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[31].comp[1].LiqDen[1], points[31].comp[1].LiqDen[2], points[31].comp[1].LiqDen[3], points[31].comp[1].LiqDen[4], points[31].comp[1].LiqDen[5], points[31].comp[1].LiqDen[6]}, points[31].comp[1].Tc, T[31], 10000.0)
 */
void Graph_eqFunction_1794(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1794};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9244], (modelica_real)data->simulationInfo->realParameter[9245], (modelica_real)data->simulationInfo->realParameter[9246], (modelica_real)data->simulationInfo->realParameter[9247], (modelica_real)data->simulationInfo->realParameter[9248], (modelica_real)data->simulationInfo->realParameter[9249]);
  data->localData[0]->realVars[854] /* points[31]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11024], data->localData[0]->realVars[230] /* T[31] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1795
 type: SIMPLE_ASSIGN
 y[31,2] = 0.2307692307692307 * points[31].K[2]
 */
void Graph_eqFunction_1795(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1795};
  data->localData[0]->realVars[1095] /* y[31,2] variable */ = (0.2307692307692307) * (data->localData[0]->realVars[776] /* points[31]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1796
 type: SIMPLE_ASSIGN
 y[31,1] = 1.0 - 0.2307692307692307 * points[31].K[2]
 */
void Graph_eqFunction_1796(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1796};
  data->localData[0]->realVars[1094] /* y[31,1] variable */ = 1.0 - ((0.2307692307692307) * (data->localData[0]->realVars[776] /* points[31]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1797(DATA*,threadData_t*);
void Graph_eqFunction_1798(DATA*,threadData_t*);
void Graph_eqFunction_1799(DATA*,threadData_t*);
void Graph_eqFunction_1800(DATA*,threadData_t*);
void Graph_eqFunction_1801(DATA*,threadData_t*);
void Graph_eqFunction_1802(DATA*,threadData_t*);
void Graph_eqFunction_1803(DATA*,threadData_t*);
void Graph_eqFunction_1804(DATA*,threadData_t*);
void Graph_eqFunction_1805(DATA*,threadData_t*);
void Graph_eqFunction_1806(DATA*,threadData_t*);
void Graph_eqFunction_1807(DATA*,threadData_t*);
void Graph_eqFunction_1808(DATA*,threadData_t*);
void Graph_eqFunction_1809(DATA*,threadData_t*);
void Graph_eqFunction_1810(DATA*,threadData_t*);
void Graph_eqFunction_1811(DATA*,threadData_t*);
void Graph_eqFunction_1812(DATA*,threadData_t*);
void Graph_eqFunction_1813(DATA*,threadData_t*);
void Graph_eqFunction_1814(DATA*,threadData_t*);
void Graph_eqFunction_1815(DATA*,threadData_t*);
void Graph_eqFunction_1816(DATA*,threadData_t*);
void Graph_eqFunction_1817(DATA*,threadData_t*);
/*
 equation index: 1818
 indexNonlinear: 71
 type: NONLINEAR
 
 vars: {T[32]}
 eqns: {1797, 1798, 1799, 1800, 1801, 1802, 1803, 1804, 1805, 1806, 1807, 1808, 1809, 1810, 1811, 1812, 1813, 1814, 1815, 1816, 1817}
 */
void Graph_eqFunction_1818(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1818};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1818 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[71].nlsxOld[0] = data->localData[0]->realVars[231] /* T[32] variable */;
  retValue = solve_nonlinear_system(data, threadData, 71);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1818};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1818 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[231] /* T[32] variable */ = data->simulationInfo->nonlinearSystemData[71].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1819
 type: SIMPLE_ASSIGN
 y[32,2] = 0.2051282051282052 * points[32].K[2]
 */
void Graph_eqFunction_1819(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1819};
  data->localData[0]->realVars[1097] /* y[32,2] variable */ = (0.2051282051282052) * (data->localData[0]->realVars[778] /* points[32]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1820
 type: SIMPLE_ASSIGN
 y[32,1] = 1.0 - 0.2051282051282052 * points[32].K[2]
 */
void Graph_eqFunction_1820(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1820};
  data->localData[0]->realVars[1096] /* y[32,1] variable */ = 1.0 - ((0.2051282051282052) * (data->localData[0]->realVars[778] /* points[32]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1821
 type: SIMPLE_ASSIGN
 points[32]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[32].comp[2].LiqDen[1], points[32].comp[2].LiqDen[2], points[32].comp[2].LiqDen[3], points[32].comp[2].LiqDen[4], points[32].comp[2].LiqDen[5], points[32].comp[2].LiqDen[6]}, points[32].comp[2].Tc, T[32], 10000.0)
 */
void Graph_eqFunction_1821(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1821};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9262], (modelica_real)data->simulationInfo->realParameter[9263], (modelica_real)data->simulationInfo->realParameter[9264], (modelica_real)data->simulationInfo->realParameter[9265], (modelica_real)data->simulationInfo->realParameter[9266], (modelica_real)data->simulationInfo->realParameter[9267]);
  data->localData[0]->realVars[857] /* points[32]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11027], data->localData[0]->realVars[231] /* T[32] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1822
 type: SIMPLE_ASSIGN
 points[32]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[32].comp[1].LiqDen[1], points[32].comp[1].LiqDen[2], points[32].comp[1].LiqDen[3], points[32].comp[1].LiqDen[4], points[32].comp[1].LiqDen[5], points[32].comp[1].LiqDen[6]}, points[32].comp[1].Tc, T[32], 10000.0)
 */
void Graph_eqFunction_1822(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1822};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9256], (modelica_real)data->simulationInfo->realParameter[9257], (modelica_real)data->simulationInfo->realParameter[9258], (modelica_real)data->simulationInfo->realParameter[9259], (modelica_real)data->simulationInfo->realParameter[9260], (modelica_real)data->simulationInfo->realParameter[9261]);
  data->localData[0]->realVars[856] /* points[32]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11026], data->localData[0]->realVars[231] /* T[32] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1823(DATA*,threadData_t*);
void Graph_eqFunction_1824(DATA*,threadData_t*);
void Graph_eqFunction_1825(DATA*,threadData_t*);
void Graph_eqFunction_1826(DATA*,threadData_t*);
void Graph_eqFunction_1827(DATA*,threadData_t*);
void Graph_eqFunction_1828(DATA*,threadData_t*);
void Graph_eqFunction_1829(DATA*,threadData_t*);
void Graph_eqFunction_1830(DATA*,threadData_t*);
void Graph_eqFunction_1831(DATA*,threadData_t*);
void Graph_eqFunction_1832(DATA*,threadData_t*);
void Graph_eqFunction_1833(DATA*,threadData_t*);
void Graph_eqFunction_1834(DATA*,threadData_t*);
void Graph_eqFunction_1835(DATA*,threadData_t*);
void Graph_eqFunction_1836(DATA*,threadData_t*);
void Graph_eqFunction_1837(DATA*,threadData_t*);
void Graph_eqFunction_1838(DATA*,threadData_t*);
void Graph_eqFunction_1839(DATA*,threadData_t*);
void Graph_eqFunction_1840(DATA*,threadData_t*);
void Graph_eqFunction_1841(DATA*,threadData_t*);
void Graph_eqFunction_1842(DATA*,threadData_t*);
void Graph_eqFunction_1843(DATA*,threadData_t*);
/*
 equation index: 1844
 indexNonlinear: 72
 type: NONLINEAR
 
 vars: {T[33]}
 eqns: {1823, 1824, 1825, 1826, 1827, 1828, 1829, 1830, 1831, 1832, 1833, 1834, 1835, 1836, 1837, 1838, 1839, 1840, 1841, 1842, 1843}
 */
void Graph_eqFunction_1844(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1844};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1844 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[72].nlsxOld[0] = data->localData[0]->realVars[232] /* T[33] variable */;
  retValue = solve_nonlinear_system(data, threadData, 72);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1844};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1844 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[232] /* T[33] variable */ = data->simulationInfo->nonlinearSystemData[72].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1845
 type: SIMPLE_ASSIGN
 points[33]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[33].comp[2].LiqDen[1], points[33].comp[2].LiqDen[2], points[33].comp[2].LiqDen[3], points[33].comp[2].LiqDen[4], points[33].comp[2].LiqDen[5], points[33].comp[2].LiqDen[6]}, points[33].comp[2].Tc, T[33], 10000.0)
 */
void Graph_eqFunction_1845(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1845};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9274], (modelica_real)data->simulationInfo->realParameter[9275], (modelica_real)data->simulationInfo->realParameter[9276], (modelica_real)data->simulationInfo->realParameter[9277], (modelica_real)data->simulationInfo->realParameter[9278], (modelica_real)data->simulationInfo->realParameter[9279]);
  data->localData[0]->realVars[859] /* points[33]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11029], data->localData[0]->realVars[232] /* T[33] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1846
 type: SIMPLE_ASSIGN
 points[33]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[33].comp[1].LiqDen[1], points[33].comp[1].LiqDen[2], points[33].comp[1].LiqDen[3], points[33].comp[1].LiqDen[4], points[33].comp[1].LiqDen[5], points[33].comp[1].LiqDen[6]}, points[33].comp[1].Tc, T[33], 10000.0)
 */
void Graph_eqFunction_1846(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1846};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9268], (modelica_real)data->simulationInfo->realParameter[9269], (modelica_real)data->simulationInfo->realParameter[9270], (modelica_real)data->simulationInfo->realParameter[9271], (modelica_real)data->simulationInfo->realParameter[9272], (modelica_real)data->simulationInfo->realParameter[9273]);
  data->localData[0]->realVars[858] /* points[33]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11028], data->localData[0]->realVars[232] /* T[33] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1847
 type: SIMPLE_ASSIGN
 y[33,2] = 0.1794871794871795 * points[33].K[2]
 */
void Graph_eqFunction_1847(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1847};
  data->localData[0]->realVars[1099] /* y[33,2] variable */ = (0.1794871794871795) * (data->localData[0]->realVars[780] /* points[33]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1848
 type: SIMPLE_ASSIGN
 y[33,1] = 1.0 - 0.1794871794871795 * points[33].K[2]
 */
void Graph_eqFunction_1848(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1848};
  data->localData[0]->realVars[1098] /* y[33,1] variable */ = 1.0 - ((0.1794871794871795) * (data->localData[0]->realVars[780] /* points[33]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1849(DATA*,threadData_t*);
void Graph_eqFunction_1850(DATA*,threadData_t*);
void Graph_eqFunction_1851(DATA*,threadData_t*);
void Graph_eqFunction_1852(DATA*,threadData_t*);
void Graph_eqFunction_1853(DATA*,threadData_t*);
void Graph_eqFunction_1854(DATA*,threadData_t*);
void Graph_eqFunction_1855(DATA*,threadData_t*);
void Graph_eqFunction_1856(DATA*,threadData_t*);
void Graph_eqFunction_1857(DATA*,threadData_t*);
void Graph_eqFunction_1858(DATA*,threadData_t*);
void Graph_eqFunction_1859(DATA*,threadData_t*);
void Graph_eqFunction_1860(DATA*,threadData_t*);
void Graph_eqFunction_1861(DATA*,threadData_t*);
void Graph_eqFunction_1862(DATA*,threadData_t*);
void Graph_eqFunction_1863(DATA*,threadData_t*);
void Graph_eqFunction_1864(DATA*,threadData_t*);
void Graph_eqFunction_1865(DATA*,threadData_t*);
void Graph_eqFunction_1866(DATA*,threadData_t*);
void Graph_eqFunction_1867(DATA*,threadData_t*);
void Graph_eqFunction_1868(DATA*,threadData_t*);
void Graph_eqFunction_1869(DATA*,threadData_t*);
/*
 equation index: 1870
 indexNonlinear: 73
 type: NONLINEAR
 
 vars: {T[34]}
 eqns: {1849, 1850, 1851, 1852, 1853, 1854, 1855, 1856, 1857, 1858, 1859, 1860, 1861, 1862, 1863, 1864, 1865, 1866, 1867, 1868, 1869}
 */
void Graph_eqFunction_1870(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1870};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1870 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[73].nlsxOld[0] = data->localData[0]->realVars[233] /* T[34] variable */;
  retValue = solve_nonlinear_system(data, threadData, 73);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1870};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1870 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[233] /* T[34] variable */ = data->simulationInfo->nonlinearSystemData[73].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1871
 type: SIMPLE_ASSIGN
 points[34]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[34].comp[2].LiqDen[1], points[34].comp[2].LiqDen[2], points[34].comp[2].LiqDen[3], points[34].comp[2].LiqDen[4], points[34].comp[2].LiqDen[5], points[34].comp[2].LiqDen[6]}, points[34].comp[2].Tc, T[34], 10000.0)
 */
void Graph_eqFunction_1871(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1871};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9286], (modelica_real)data->simulationInfo->realParameter[9287], (modelica_real)data->simulationInfo->realParameter[9288], (modelica_real)data->simulationInfo->realParameter[9289], (modelica_real)data->simulationInfo->realParameter[9290], (modelica_real)data->simulationInfo->realParameter[9291]);
  data->localData[0]->realVars[861] /* points[34]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11031], data->localData[0]->realVars[233] /* T[34] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1872
 type: SIMPLE_ASSIGN
 points[34]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[34].comp[1].LiqDen[1], points[34].comp[1].LiqDen[2], points[34].comp[1].LiqDen[3], points[34].comp[1].LiqDen[4], points[34].comp[1].LiqDen[5], points[34].comp[1].LiqDen[6]}, points[34].comp[1].Tc, T[34], 10000.0)
 */
void Graph_eqFunction_1872(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1872};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9280], (modelica_real)data->simulationInfo->realParameter[9281], (modelica_real)data->simulationInfo->realParameter[9282], (modelica_real)data->simulationInfo->realParameter[9283], (modelica_real)data->simulationInfo->realParameter[9284], (modelica_real)data->simulationInfo->realParameter[9285]);
  data->localData[0]->realVars[860] /* points[34]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11030], data->localData[0]->realVars[233] /* T[34] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1873
 type: SIMPLE_ASSIGN
 y[34,2] = 0.1538461538461539 * points[34].K[2]
 */
void Graph_eqFunction_1873(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1873};
  data->localData[0]->realVars[1101] /* y[34,2] variable */ = (0.1538461538461539) * (data->localData[0]->realVars[782] /* points[34]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1874
 type: SIMPLE_ASSIGN
 y[34,1] = 1.0 - 0.1538461538461539 * points[34].K[2]
 */
void Graph_eqFunction_1874(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1874};
  data->localData[0]->realVars[1100] /* y[34,1] variable */ = 1.0 - ((0.1538461538461539) * (data->localData[0]->realVars[782] /* points[34]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1875(DATA*,threadData_t*);
void Graph_eqFunction_1876(DATA*,threadData_t*);
void Graph_eqFunction_1877(DATA*,threadData_t*);
void Graph_eqFunction_1878(DATA*,threadData_t*);
void Graph_eqFunction_1879(DATA*,threadData_t*);
void Graph_eqFunction_1880(DATA*,threadData_t*);
void Graph_eqFunction_1881(DATA*,threadData_t*);
void Graph_eqFunction_1882(DATA*,threadData_t*);
void Graph_eqFunction_1883(DATA*,threadData_t*);
void Graph_eqFunction_1884(DATA*,threadData_t*);
void Graph_eqFunction_1885(DATA*,threadData_t*);
void Graph_eqFunction_1886(DATA*,threadData_t*);
void Graph_eqFunction_1887(DATA*,threadData_t*);
void Graph_eqFunction_1888(DATA*,threadData_t*);
void Graph_eqFunction_1889(DATA*,threadData_t*);
void Graph_eqFunction_1890(DATA*,threadData_t*);
void Graph_eqFunction_1891(DATA*,threadData_t*);
void Graph_eqFunction_1892(DATA*,threadData_t*);
void Graph_eqFunction_1893(DATA*,threadData_t*);
void Graph_eqFunction_1894(DATA*,threadData_t*);
void Graph_eqFunction_1895(DATA*,threadData_t*);
/*
 equation index: 1896
 indexNonlinear: 74
 type: NONLINEAR
 
 vars: {T[35]}
 eqns: {1875, 1876, 1877, 1878, 1879, 1880, 1881, 1882, 1883, 1884, 1885, 1886, 1887, 1888, 1889, 1890, 1891, 1892, 1893, 1894, 1895}
 */
void Graph_eqFunction_1896(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1896};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1896 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[74].nlsxOld[0] = data->localData[0]->realVars[234] /* T[35] variable */;
  retValue = solve_nonlinear_system(data, threadData, 74);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1896};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1896 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[234] /* T[35] variable */ = data->simulationInfo->nonlinearSystemData[74].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1897
 type: SIMPLE_ASSIGN
 points[35]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[35].comp[2].LiqDen[1], points[35].comp[2].LiqDen[2], points[35].comp[2].LiqDen[3], points[35].comp[2].LiqDen[4], points[35].comp[2].LiqDen[5], points[35].comp[2].LiqDen[6]}, points[35].comp[2].Tc, T[35], 10000.0)
 */
void Graph_eqFunction_1897(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1897};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9298], (modelica_real)data->simulationInfo->realParameter[9299], (modelica_real)data->simulationInfo->realParameter[9300], (modelica_real)data->simulationInfo->realParameter[9301], (modelica_real)data->simulationInfo->realParameter[9302], (modelica_real)data->simulationInfo->realParameter[9303]);
  data->localData[0]->realVars[863] /* points[35]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11033], data->localData[0]->realVars[234] /* T[35] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1898
 type: SIMPLE_ASSIGN
 points[35]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[35].comp[1].LiqDen[1], points[35].comp[1].LiqDen[2], points[35].comp[1].LiqDen[3], points[35].comp[1].LiqDen[4], points[35].comp[1].LiqDen[5], points[35].comp[1].LiqDen[6]}, points[35].comp[1].Tc, T[35], 10000.0)
 */
void Graph_eqFunction_1898(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1898};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9292], (modelica_real)data->simulationInfo->realParameter[9293], (modelica_real)data->simulationInfo->realParameter[9294], (modelica_real)data->simulationInfo->realParameter[9295], (modelica_real)data->simulationInfo->realParameter[9296], (modelica_real)data->simulationInfo->realParameter[9297]);
  data->localData[0]->realVars[862] /* points[35]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11032], data->localData[0]->realVars[234] /* T[35] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1899
 type: SIMPLE_ASSIGN
 y[35,2] = 0.1282051282051282 * points[35].K[2]
 */
void Graph_eqFunction_1899(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1899};
  data->localData[0]->realVars[1103] /* y[35,2] variable */ = (0.1282051282051282) * (data->localData[0]->realVars[784] /* points[35]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1900
 type: SIMPLE_ASSIGN
 y[35,1] = 1.0 - 0.1282051282051282 * points[35].K[2]
 */
void Graph_eqFunction_1900(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1900};
  data->localData[0]->realVars[1102] /* y[35,1] variable */ = 1.0 - ((0.1282051282051282) * (data->localData[0]->realVars[784] /* points[35]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1901(DATA*,threadData_t*);
void Graph_eqFunction_1902(DATA*,threadData_t*);
void Graph_eqFunction_1903(DATA*,threadData_t*);
void Graph_eqFunction_1904(DATA*,threadData_t*);
void Graph_eqFunction_1905(DATA*,threadData_t*);
void Graph_eqFunction_1906(DATA*,threadData_t*);
void Graph_eqFunction_1907(DATA*,threadData_t*);
void Graph_eqFunction_1908(DATA*,threadData_t*);
void Graph_eqFunction_1909(DATA*,threadData_t*);
void Graph_eqFunction_1910(DATA*,threadData_t*);
void Graph_eqFunction_1911(DATA*,threadData_t*);
void Graph_eqFunction_1912(DATA*,threadData_t*);
void Graph_eqFunction_1913(DATA*,threadData_t*);
void Graph_eqFunction_1914(DATA*,threadData_t*);
void Graph_eqFunction_1915(DATA*,threadData_t*);
void Graph_eqFunction_1916(DATA*,threadData_t*);
void Graph_eqFunction_1917(DATA*,threadData_t*);
void Graph_eqFunction_1918(DATA*,threadData_t*);
void Graph_eqFunction_1919(DATA*,threadData_t*);
void Graph_eqFunction_1920(DATA*,threadData_t*);
void Graph_eqFunction_1921(DATA*,threadData_t*);
/*
 equation index: 1922
 indexNonlinear: 75
 type: NONLINEAR
 
 vars: {T[36]}
 eqns: {1901, 1902, 1903, 1904, 1905, 1906, 1907, 1908, 1909, 1910, 1911, 1912, 1913, 1914, 1915, 1916, 1917, 1918, 1919, 1920, 1921}
 */
void Graph_eqFunction_1922(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1922};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1922 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[75].nlsxOld[0] = data->localData[0]->realVars[235] /* T[36] variable */;
  retValue = solve_nonlinear_system(data, threadData, 75);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1922};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1922 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[235] /* T[36] variable */ = data->simulationInfo->nonlinearSystemData[75].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1923
 type: SIMPLE_ASSIGN
 points[36]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[36].comp[2].LiqDen[1], points[36].comp[2].LiqDen[2], points[36].comp[2].LiqDen[3], points[36].comp[2].LiqDen[4], points[36].comp[2].LiqDen[5], points[36].comp[2].LiqDen[6]}, points[36].comp[2].Tc, T[36], 10000.0)
 */
void Graph_eqFunction_1923(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1923};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9310], (modelica_real)data->simulationInfo->realParameter[9311], (modelica_real)data->simulationInfo->realParameter[9312], (modelica_real)data->simulationInfo->realParameter[9313], (modelica_real)data->simulationInfo->realParameter[9314], (modelica_real)data->simulationInfo->realParameter[9315]);
  data->localData[0]->realVars[865] /* points[36]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11035], data->localData[0]->realVars[235] /* T[36] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1924
 type: SIMPLE_ASSIGN
 points[36]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[36].comp[1].LiqDen[1], points[36].comp[1].LiqDen[2], points[36].comp[1].LiqDen[3], points[36].comp[1].LiqDen[4], points[36].comp[1].LiqDen[5], points[36].comp[1].LiqDen[6]}, points[36].comp[1].Tc, T[36], 10000.0)
 */
void Graph_eqFunction_1924(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1924};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9304], (modelica_real)data->simulationInfo->realParameter[9305], (modelica_real)data->simulationInfo->realParameter[9306], (modelica_real)data->simulationInfo->realParameter[9307], (modelica_real)data->simulationInfo->realParameter[9308], (modelica_real)data->simulationInfo->realParameter[9309]);
  data->localData[0]->realVars[864] /* points[36]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11034], data->localData[0]->realVars[235] /* T[36] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1925
 type: SIMPLE_ASSIGN
 y[36,2] = 0.1025641025641025 * points[36].K[2]
 */
void Graph_eqFunction_1925(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1925};
  data->localData[0]->realVars[1105] /* y[36,2] variable */ = (0.1025641025641025) * (data->localData[0]->realVars[786] /* points[36]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1926
 type: SIMPLE_ASSIGN
 y[36,1] = 1.0 - 0.1025641025641025 * points[36].K[2]
 */
void Graph_eqFunction_1926(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1926};
  data->localData[0]->realVars[1104] /* y[36,1] variable */ = 1.0 - ((0.1025641025641025) * (data->localData[0]->realVars[786] /* points[36]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1927(DATA*,threadData_t*);
void Graph_eqFunction_1928(DATA*,threadData_t*);
void Graph_eqFunction_1929(DATA*,threadData_t*);
void Graph_eqFunction_1930(DATA*,threadData_t*);
void Graph_eqFunction_1931(DATA*,threadData_t*);
void Graph_eqFunction_1932(DATA*,threadData_t*);
void Graph_eqFunction_1933(DATA*,threadData_t*);
void Graph_eqFunction_1934(DATA*,threadData_t*);
void Graph_eqFunction_1935(DATA*,threadData_t*);
void Graph_eqFunction_1936(DATA*,threadData_t*);
void Graph_eqFunction_1937(DATA*,threadData_t*);
void Graph_eqFunction_1938(DATA*,threadData_t*);
void Graph_eqFunction_1939(DATA*,threadData_t*);
void Graph_eqFunction_1940(DATA*,threadData_t*);
void Graph_eqFunction_1941(DATA*,threadData_t*);
void Graph_eqFunction_1942(DATA*,threadData_t*);
void Graph_eqFunction_1943(DATA*,threadData_t*);
void Graph_eqFunction_1944(DATA*,threadData_t*);
void Graph_eqFunction_1945(DATA*,threadData_t*);
void Graph_eqFunction_1946(DATA*,threadData_t*);
void Graph_eqFunction_1947(DATA*,threadData_t*);
/*
 equation index: 1948
 indexNonlinear: 76
 type: NONLINEAR
 
 vars: {T[37]}
 eqns: {1927, 1928, 1929, 1930, 1931, 1932, 1933, 1934, 1935, 1936, 1937, 1938, 1939, 1940, 1941, 1942, 1943, 1944, 1945, 1946, 1947}
 */
void Graph_eqFunction_1948(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1948};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1948 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[76].nlsxOld[0] = data->localData[0]->realVars[236] /* T[37] variable */;
  retValue = solve_nonlinear_system(data, threadData, 76);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1948};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1948 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[236] /* T[37] variable */ = data->simulationInfo->nonlinearSystemData[76].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1949
 type: SIMPLE_ASSIGN
 points[37]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[37].comp[2].LiqDen[1], points[37].comp[2].LiqDen[2], points[37].comp[2].LiqDen[3], points[37].comp[2].LiqDen[4], points[37].comp[2].LiqDen[5], points[37].comp[2].LiqDen[6]}, points[37].comp[2].Tc, T[37], 10000.0)
 */
void Graph_eqFunction_1949(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1949};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9322], (modelica_real)data->simulationInfo->realParameter[9323], (modelica_real)data->simulationInfo->realParameter[9324], (modelica_real)data->simulationInfo->realParameter[9325], (modelica_real)data->simulationInfo->realParameter[9326], (modelica_real)data->simulationInfo->realParameter[9327]);
  data->localData[0]->realVars[867] /* points[37]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11037], data->localData[0]->realVars[236] /* T[37] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1950
 type: SIMPLE_ASSIGN
 points[37]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[37].comp[1].LiqDen[1], points[37].comp[1].LiqDen[2], points[37].comp[1].LiqDen[3], points[37].comp[1].LiqDen[4], points[37].comp[1].LiqDen[5], points[37].comp[1].LiqDen[6]}, points[37].comp[1].Tc, T[37], 10000.0)
 */
void Graph_eqFunction_1950(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1950};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9316], (modelica_real)data->simulationInfo->realParameter[9317], (modelica_real)data->simulationInfo->realParameter[9318], (modelica_real)data->simulationInfo->realParameter[9319], (modelica_real)data->simulationInfo->realParameter[9320], (modelica_real)data->simulationInfo->realParameter[9321]);
  data->localData[0]->realVars[866] /* points[37]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11036], data->localData[0]->realVars[236] /* T[37] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1951
 type: SIMPLE_ASSIGN
 y[37,2] = 0.07692307692307687 * points[37].K[2]
 */
void Graph_eqFunction_1951(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1951};
  data->localData[0]->realVars[1107] /* y[37,2] variable */ = (0.07692307692307687) * (data->localData[0]->realVars[788] /* points[37]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1952
 type: SIMPLE_ASSIGN
 y[37,1] = 1.0 - 0.07692307692307687 * points[37].K[2]
 */
void Graph_eqFunction_1952(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1952};
  data->localData[0]->realVars[1106] /* y[37,1] variable */ = 1.0 - ((0.07692307692307687) * (data->localData[0]->realVars[788] /* points[37]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_1953(DATA*,threadData_t*);
void Graph_eqFunction_1954(DATA*,threadData_t*);
void Graph_eqFunction_1955(DATA*,threadData_t*);
void Graph_eqFunction_1956(DATA*,threadData_t*);
void Graph_eqFunction_1957(DATA*,threadData_t*);
void Graph_eqFunction_1958(DATA*,threadData_t*);
void Graph_eqFunction_1959(DATA*,threadData_t*);
void Graph_eqFunction_1960(DATA*,threadData_t*);
void Graph_eqFunction_1961(DATA*,threadData_t*);
void Graph_eqFunction_1962(DATA*,threadData_t*);
void Graph_eqFunction_1963(DATA*,threadData_t*);
void Graph_eqFunction_1964(DATA*,threadData_t*);
void Graph_eqFunction_1965(DATA*,threadData_t*);
void Graph_eqFunction_1966(DATA*,threadData_t*);
void Graph_eqFunction_1967(DATA*,threadData_t*);
void Graph_eqFunction_1968(DATA*,threadData_t*);
void Graph_eqFunction_1969(DATA*,threadData_t*);
void Graph_eqFunction_1970(DATA*,threadData_t*);
void Graph_eqFunction_1971(DATA*,threadData_t*);
void Graph_eqFunction_1972(DATA*,threadData_t*);
void Graph_eqFunction_1973(DATA*,threadData_t*);
/*
 equation index: 1974
 indexNonlinear: 77
 type: NONLINEAR
 
 vars: {T[38]}
 eqns: {1953, 1954, 1955, 1956, 1957, 1958, 1959, 1960, 1961, 1962, 1963, 1964, 1965, 1966, 1967, 1968, 1969, 1970, 1971, 1972, 1973}
 */
void Graph_eqFunction_1974(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1974};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 1974 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[77].nlsxOld[0] = data->localData[0]->realVars[237] /* T[38] variable */;
  retValue = solve_nonlinear_system(data, threadData, 77);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,1974};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 1974 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[237] /* T[38] variable */ = data->simulationInfo->nonlinearSystemData[77].nlsx[0];
  TRACE_POP
}
/*
 equation index: 1975
 type: SIMPLE_ASSIGN
 y[38,2] = 0.05128205128205132 * points[38].K[2]
 */
void Graph_eqFunction_1975(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1975};
  data->localData[0]->realVars[1109] /* y[38,2] variable */ = (0.05128205128205132) * (data->localData[0]->realVars[790] /* points[38]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 1976
 type: SIMPLE_ASSIGN
 y[38,1] = 1.0 - 0.05128205128205132 * points[38].K[2]
 */
void Graph_eqFunction_1976(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1976};
  data->localData[0]->realVars[1108] /* y[38,1] variable */ = 1.0 - ((0.05128205128205132) * (data->localData[0]->realVars[790] /* points[38]._K[2] variable */));
  TRACE_POP
}
/*
 equation index: 1977
 type: SIMPLE_ASSIGN
 points[38]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[38].comp[2].LiqDen[1], points[38].comp[2].LiqDen[2], points[38].comp[2].LiqDen[3], points[38].comp[2].LiqDen[4], points[38].comp[2].LiqDen[5], points[38].comp[2].LiqDen[6]}, points[38].comp[2].Tc, T[38], 10000.0)
 */
void Graph_eqFunction_1977(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1977};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9334], (modelica_real)data->simulationInfo->realParameter[9335], (modelica_real)data->simulationInfo->realParameter[9336], (modelica_real)data->simulationInfo->realParameter[9337], (modelica_real)data->simulationInfo->realParameter[9338], (modelica_real)data->simulationInfo->realParameter[9339]);
  data->localData[0]->realVars[869] /* points[38]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11039], data->localData[0]->realVars[237] /* T[38] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 1978
 type: SIMPLE_ASSIGN
 points[38]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[38].comp[1].LiqDen[1], points[38].comp[1].LiqDen[2], points[38].comp[1].LiqDen[3], points[38].comp[1].LiqDen[4], points[38].comp[1].LiqDen[5], points[38].comp[1].LiqDen[6]}, points[38].comp[1].Tc, T[38], 10000.0)
 */
void Graph_eqFunction_1978(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1978};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9328], (modelica_real)data->simulationInfo->realParameter[9329], (modelica_real)data->simulationInfo->realParameter[9330], (modelica_real)data->simulationInfo->realParameter[9331], (modelica_real)data->simulationInfo->realParameter[9332], (modelica_real)data->simulationInfo->realParameter[9333]);
  data->localData[0]->realVars[868] /* points[38]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11038], data->localData[0]->realVars[237] /* T[38] variable */, 10000.0);
  TRACE_POP
}
void Graph_eqFunction_1979(DATA*,threadData_t*);
void Graph_eqFunction_1980(DATA*,threadData_t*);
void Graph_eqFunction_1981(DATA*,threadData_t*);
void Graph_eqFunction_1982(DATA*,threadData_t*);
void Graph_eqFunction_1983(DATA*,threadData_t*);
void Graph_eqFunction_1984(DATA*,threadData_t*);
void Graph_eqFunction_1985(DATA*,threadData_t*);
void Graph_eqFunction_1986(DATA*,threadData_t*);
void Graph_eqFunction_1987(DATA*,threadData_t*);
void Graph_eqFunction_1988(DATA*,threadData_t*);
void Graph_eqFunction_1989(DATA*,threadData_t*);
void Graph_eqFunction_1990(DATA*,threadData_t*);
void Graph_eqFunction_1991(DATA*,threadData_t*);
void Graph_eqFunction_1992(DATA*,threadData_t*);
void Graph_eqFunction_1993(DATA*,threadData_t*);
void Graph_eqFunction_1994(DATA*,threadData_t*);
void Graph_eqFunction_1995(DATA*,threadData_t*);
void Graph_eqFunction_1996(DATA*,threadData_t*);
void Graph_eqFunction_1997(DATA*,threadData_t*);
void Graph_eqFunction_1998(DATA*,threadData_t*);
void Graph_eqFunction_1999(DATA*,threadData_t*);
/*
 equation index: 2000
 indexNonlinear: 78
 type: NONLINEAR
 
 vars: {T[39]}
 eqns: {1979, 1980, 1981, 1982, 1983, 1984, 1985, 1986, 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999}
 */
void Graph_eqFunction_2000(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2000};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 2000 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[78].nlsxOld[0] = data->localData[0]->realVars[238] /* T[39] variable */;
  retValue = solve_nonlinear_system(data, threadData, 78);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,2000};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 2000 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[238] /* T[39] variable */ = data->simulationInfo->nonlinearSystemData[78].nlsx[0];
  TRACE_POP
}
/*
 equation index: 2001
 type: SIMPLE_ASSIGN
 points[39]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[39].comp[2].LiqDen[1], points[39].comp[2].LiqDen[2], points[39].comp[2].LiqDen[3], points[39].comp[2].LiqDen[4], points[39].comp[2].LiqDen[5], points[39].comp[2].LiqDen[6]}, points[39].comp[2].Tc, T[39], 10000.0)
 */
void Graph_eqFunction_2001(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2001};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[9346], (modelica_real)data->simulationInfo->realParameter[9347], (modelica_real)data->simulationInfo->realParameter[9348], (modelica_real)data->simulationInfo->realParameter[9349], (modelica_real)data->simulationInfo->realParameter[9350], (modelica_real)data->simulationInfo->realParameter[9351]);
  data->localData[0]->realVars[871] /* points[39]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp0, data->simulationInfo->realParameter[11041], data->localData[0]->realVars[238] /* T[39] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 2002
 type: SIMPLE_ASSIGN
 points[39]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[39].comp[1].LiqDen[1], points[39].comp[1].LiqDen[2], points[39].comp[1].LiqDen[3], points[39].comp[1].LiqDen[4], points[39].comp[1].LiqDen[5], points[39].comp[1].LiqDen[6]}, points[39].comp[1].Tc, T[39], 10000.0)
 */
void Graph_eqFunction_2002(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2002};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9340], (modelica_real)data->simulationInfo->realParameter[9341], (modelica_real)data->simulationInfo->realParameter[9342], (modelica_real)data->simulationInfo->realParameter[9343], (modelica_real)data->simulationInfo->realParameter[9344], (modelica_real)data->simulationInfo->realParameter[9345]);
  data->localData[0]->realVars[870] /* points[39]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11040], data->localData[0]->realVars[238] /* T[39] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 2003
 type: SIMPLE_ASSIGN
 y[39,2] = 0.02564102564102566 * points[39].K[2]
 */
void Graph_eqFunction_2003(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2003};
  data->localData[0]->realVars[1111] /* y[39,2] variable */ = (0.02564102564102566) * (data->localData[0]->realVars[792] /* points[39]._K[2] variable */);
  TRACE_POP
}
/*
 equation index: 2004
 type: SIMPLE_ASSIGN
 y[39,1] = 1.0 - 0.02564102564102566 * points[39].K[2]
 */
void Graph_eqFunction_2004(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2004};
  data->localData[0]->realVars[1110] /* y[39,1] variable */ = 1.0 - ((0.02564102564102566) * (data->localData[0]->realVars[792] /* points[39]._K[2] variable */));
  TRACE_POP
}
void Graph_eqFunction_2005(DATA*,threadData_t*);
void Graph_eqFunction_2006(DATA*,threadData_t*);
void Graph_eqFunction_2007(DATA*,threadData_t*);
void Graph_eqFunction_2008(DATA*,threadData_t*);
void Graph_eqFunction_2009(DATA*,threadData_t*);
void Graph_eqFunction_2010(DATA*,threadData_t*);
void Graph_eqFunction_2011(DATA*,threadData_t*);
/*
 equation index: 2012
 indexNonlinear: 79
 type: NONLINEAR
 
 vars: {T[40]}
 eqns: {2005, 2006, 2007, 2008, 2009, 2010, 2011}
 */
void Graph_eqFunction_2012(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2012};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 2012 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[79].nlsxOld[0] = data->localData[0]->realVars[239] /* T[40] variable */;
  retValue = solve_nonlinear_system(data, threadData, 79);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,2012};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 2012 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[239] /* T[40] variable */ = data->simulationInfo->nonlinearSystemData[79].nlsx[0];
  TRACE_POP
}
/*
 equation index: 2013
 type: SIMPLE_ASSIGN
 points[40]._Gamma._tau[1,2] = 0.5032180796191645 * DIVISION(points[40].BIP[1,2,1], T[40])
 */
void Graph_eqFunction_2013(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2013};
  data->localData[0]->realVars[713] /* points[40]._Gamma._tau[1,2] variable */ = (0.5032180796191645) * (DIVISION_SIM(data->simulationInfo->realParameter[638],data->localData[0]->realVars[239] /* T[40] variable */,"T[40]",equationIndexes));
  TRACE_POP
}
/*
 equation index: 2014
 type: SIMPLE_ASSIGN
 points[40]._Gamma._sum1[2] = exp((-points[40].BIP[1,2,2]) * points[40].Gamma.tau[1,2])
 */
void Graph_eqFunction_2014(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2014};
  data->localData[0]->realVars[475] /* points[40]._Gamma._sum1[2] variable */ = exp(((-data->simulationInfo->realParameter[639])) * (data->localData[0]->realVars[713] /* points[40]._Gamma._tau[1,2] variable */));
  TRACE_POP
}
/*
 equation index: 2015
 type: SIMPLE_ASSIGN
 points[40]._Gamma._sum2[2] = points[40].Gamma.tau[1,2] * points[40].Gamma.sum1[2]
 */
void Graph_eqFunction_2015(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2015};
  data->localData[0]->realVars[555] /* points[40]._Gamma._sum2[2] variable */ = (data->localData[0]->realVars[713] /* points[40]._Gamma._tau[1,2] variable */) * (data->localData[0]->realVars[475] /* points[40]._Gamma._sum1[2] variable */);
  TRACE_POP
}
/*
 equation index: 2016
 type: SIMPLE_ASSIGN
 points[40]._Gamma._tau[2,1] = 0.5032180796191645 * DIVISION(points[40].BIP[2,1,1], T[40])
 */
void Graph_eqFunction_2016(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2016};
  data->localData[0]->realVars[714] /* points[40]._Gamma._tau[2,1] variable */ = (0.5032180796191645) * (DIVISION_SIM(data->simulationInfo->realParameter[640],data->localData[0]->realVars[239] /* T[40] variable */,"T[40]",equationIndexes));
  TRACE_POP
}
/*
 equation index: 2017
 type: SIMPLE_ASSIGN
 points[40]._Gamma._G[2,1] = exp((-points[40].BIP[2,1,2]) * points[40].Gamma.tau[2,1])
 */
void Graph_eqFunction_2017(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2017};
  data->localData[0]->realVars[394] /* points[40]._Gamma._G[2,1] variable */ = exp(((-data->simulationInfo->realParameter[641])) * (data->localData[0]->realVars[714] /* points[40]._Gamma._tau[2,1] variable */));
  TRACE_POP
}
/*
 equation index: 2018
 type: SIMPLE_ASSIGN
 $cse158 = DIVISION(points[40].Gamma.sum2[2], points[40].Gamma.sum1[2]) + points[40].Gamma.G[2,1] * DIVISION(points[40].Gamma.tau[2,1] - DIVISION(points[40].Gamma.sum2[1], points[40].Gamma.sum1[1]), points[40].Gamma.sum1[1])
 */
void Graph_eqFunction_2018(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2018};
  data->localData[0]->realVars[65] /* $cse158 variable */ = DIVISION_SIM(data->localData[0]->realVars[555] /* points[40]._Gamma._sum2[2] variable */,data->localData[0]->realVars[475] /* points[40]._Gamma._sum1[2] variable */,"points[40].Gamma.sum1[2]",equationIndexes) + (data->localData[0]->realVars[394] /* points[40]._Gamma._G[2,1] variable */) * (DIVISION_SIM(data->localData[0]->realVars[714] /* points[40]._Gamma._tau[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[554] /* points[40]._Gamma._sum2[1] variable */,data->localData[0]->realVars[474] /* points[40]._Gamma._sum1[1] variable */,"points[40].Gamma.sum1[1]",equationIndexes),data->localData[0]->realVars[474] /* points[40]._Gamma._sum1[1] variable */,"points[40].Gamma.sum1[1]",equationIndexes));
  TRACE_POP
}
/*
 equation index: 2019
 type: SIMPLE_ASSIGN
 points[40]._gamma[2] = exp($cse158)
 */
void Graph_eqFunction_2019(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2019};
  data->localData[0]->realVars[953] /* points[40]._gamma[2] variable */ = exp(data->localData[0]->realVars[65] /* $cse158 variable */);
  TRACE_POP
}
/*
 equation index: 2020
 type: SIMPLE_ASSIGN
 points[40]._Gamma._tau[2,2] = 0.5032180796191645 * DIVISION(points[40].BIP[2,2,1], T[40])
 */
void Graph_eqFunction_2020(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2020};
  data->localData[0]->realVars[715] /* points[40]._Gamma._tau[2,2] variable */ = (0.5032180796191645) * (DIVISION_SIM(data->simulationInfo->realParameter[642],data->localData[0]->realVars[239] /* T[40] variable */,"T[40]",equationIndexes));
  TRACE_POP
}
/*
 equation index: 2021
 type: SIMPLE_ASSIGN
 points[40]._Gamma._G[2,2] = exp((-points[40].BIP[2,2,2]) * points[40].Gamma.tau[2,2])
 */
void Graph_eqFunction_2021(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2021};
  data->localData[0]->realVars[395] /* points[40]._Gamma._G[2,2] variable */ = exp(((-data->simulationInfo->realParameter[643])) * (data->localData[0]->realVars[715] /* points[40]._Gamma._tau[2,2] variable */));
  TRACE_POP
}
/*
 equation index: 2022
 type: SIMPLE_ASSIGN
 $cse160 = Simulator.Files.ThermodynamicFunctions.Psat({points[40].comp[2].VP[1], points[40].comp[2].VP[2], points[40].comp[2].VP[3], points[40].comp[2].VP[4], points[40].comp[2].VP[5], points[40].comp[2].VP[6]}, T[40])
 */
void Graph_eqFunction_2022(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2022};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[11758], (modelica_real)data->simulationInfo->realParameter[11759], (modelica_real)data->simulationInfo->realParameter[11760], (modelica_real)data->simulationInfo->realParameter[11761], (modelica_real)data->simulationInfo->realParameter[11762], (modelica_real)data->simulationInfo->realParameter[11763]);
  data->localData[0]->realVars[68] /* $cse160 variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->localData[0]->realVars[239] /* T[40] variable */);
  TRACE_POP
}
/*
 equation index: 2023
 type: SIMPLE_ASSIGN
 points[40]._K[2] = 0.0001 * points[40].gamma[2] * $cse160
 */
void Graph_eqFunction_2023(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2023};
  data->localData[0]->realVars[793] /* points[40]._K[2] variable */ = (0.0001) * ((data->localData[0]->realVars[953] /* points[40]._gamma[2] variable */) * (data->localData[0]->realVars[68] /* $cse160 variable */));
  TRACE_POP
}
/*
 equation index: 2024
 type: SIMPLE_ASSIGN
 points[40]._density[2] = Simulator.Files.ThermodynamicFunctions.Dens({points[40].comp[2].LiqDen[1], points[40].comp[2].LiqDen[2], points[40].comp[2].LiqDen[3], points[40].comp[2].LiqDen[4], points[40].comp[2].LiqDen[5], points[40].comp[2].LiqDen[6]}, points[40].comp[2].Tc, T[40], 10000.0)
 */
void Graph_eqFunction_2024(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2024};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[9358], (modelica_real)data->simulationInfo->realParameter[9359], (modelica_real)data->simulationInfo->realParameter[9360], (modelica_real)data->simulationInfo->realParameter[9361], (modelica_real)data->simulationInfo->realParameter[9362], (modelica_real)data->simulationInfo->realParameter[9363]);
  data->localData[0]->realVars[873] /* points[40]._density[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp1, data->simulationInfo->realParameter[11043], data->localData[0]->realVars[239] /* T[40] variable */, 10000.0);
  TRACE_POP
}
/*
 equation index: 2025
 type: SIMPLE_ASSIGN
 points[40]._density[1] = Simulator.Files.ThermodynamicFunctions.Dens({points[40].comp[1].LiqDen[1], points[40].comp[1].LiqDen[2], points[40].comp[1].LiqDen[3], points[40].comp[1].LiqDen[4], points[40].comp[1].LiqDen[5], points[40].comp[1].LiqDen[6]}, points[40].comp[1].Tc, T[40], 10000.0)
 */
void Graph_eqFunction_2025(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2025};
  real_array tmp2;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[9352], (modelica_real)data->simulationInfo->realParameter[9353], (modelica_real)data->simulationInfo->realParameter[9354], (modelica_real)data->simulationInfo->realParameter[9355], (modelica_real)data->simulationInfo->realParameter[9356], (modelica_real)data->simulationInfo->realParameter[9357]);
  data->localData[0]->realVars[872] /* points[40]._density[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, tmp2, data->simulationInfo->realParameter[11042], data->localData[0]->realVars[239] /* T[40] variable */, 10000.0);
  TRACE_POP
}


int Graph_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Graph_functionLocalKnownVars(data, threadData);
  Graph_eqFunction_995(data, threadData);

  Graph_eqFunction_1003(data, threadData);

  Graph_eqFunction_1004(data, threadData);

  Graph_eqFunction_1005(data, threadData);

  Graph_eqFunction_1006(data, threadData);

  Graph_eqFunction_1007(data, threadData);

  Graph_eqFunction_1008(data, threadData);

  Graph_eqFunction_1009(data, threadData);

  Graph_eqFunction_1010(data, threadData);

  Graph_eqFunction_1011(data, threadData);

  Graph_eqFunction_1012(data, threadData);

  Graph_eqFunction_1013(data, threadData);

  Graph_eqFunction_1014(data, threadData);

  Graph_eqFunction_1015(data, threadData);

  Graph_eqFunction_1016(data, threadData);

  Graph_eqFunction_1038(data, threadData);

  Graph_eqFunction_1039(data, threadData);

  Graph_eqFunction_1040(data, threadData);

  Graph_eqFunction_1041(data, threadData);

  Graph_eqFunction_1042(data, threadData);

  Graph_eqFunction_1064(data, threadData);

  Graph_eqFunction_1065(data, threadData);

  Graph_eqFunction_1066(data, threadData);

  Graph_eqFunction_1067(data, threadData);

  Graph_eqFunction_1068(data, threadData);

  Graph_eqFunction_1090(data, threadData);

  Graph_eqFunction_1091(data, threadData);

  Graph_eqFunction_1092(data, threadData);

  Graph_eqFunction_1093(data, threadData);

  Graph_eqFunction_1094(data, threadData);

  Graph_eqFunction_1116(data, threadData);

  Graph_eqFunction_1117(data, threadData);

  Graph_eqFunction_1118(data, threadData);

  Graph_eqFunction_1119(data, threadData);

  Graph_eqFunction_1120(data, threadData);

  Graph_eqFunction_1142(data, threadData);

  Graph_eqFunction_1143(data, threadData);

  Graph_eqFunction_1144(data, threadData);

  Graph_eqFunction_1145(data, threadData);

  Graph_eqFunction_1146(data, threadData);

  Graph_eqFunction_1168(data, threadData);

  Graph_eqFunction_1169(data, threadData);

  Graph_eqFunction_1170(data, threadData);

  Graph_eqFunction_1171(data, threadData);

  Graph_eqFunction_1172(data, threadData);

  Graph_eqFunction_1194(data, threadData);

  Graph_eqFunction_1195(data, threadData);

  Graph_eqFunction_1196(data, threadData);

  Graph_eqFunction_1197(data, threadData);

  Graph_eqFunction_1198(data, threadData);

  Graph_eqFunction_1220(data, threadData);

  Graph_eqFunction_1221(data, threadData);

  Graph_eqFunction_1222(data, threadData);

  Graph_eqFunction_1223(data, threadData);

  Graph_eqFunction_1224(data, threadData);

  Graph_eqFunction_1246(data, threadData);

  Graph_eqFunction_1247(data, threadData);

  Graph_eqFunction_1248(data, threadData);

  Graph_eqFunction_1249(data, threadData);

  Graph_eqFunction_1250(data, threadData);

  Graph_eqFunction_1272(data, threadData);

  Graph_eqFunction_1273(data, threadData);

  Graph_eqFunction_1274(data, threadData);

  Graph_eqFunction_1275(data, threadData);

  Graph_eqFunction_1276(data, threadData);

  Graph_eqFunction_1298(data, threadData);

  Graph_eqFunction_1299(data, threadData);

  Graph_eqFunction_1300(data, threadData);

  Graph_eqFunction_1301(data, threadData);

  Graph_eqFunction_1302(data, threadData);

  Graph_eqFunction_1324(data, threadData);

  Graph_eqFunction_1325(data, threadData);

  Graph_eqFunction_1326(data, threadData);

  Graph_eqFunction_1327(data, threadData);

  Graph_eqFunction_1328(data, threadData);

  Graph_eqFunction_1350(data, threadData);

  Graph_eqFunction_1351(data, threadData);

  Graph_eqFunction_1352(data, threadData);

  Graph_eqFunction_1353(data, threadData);

  Graph_eqFunction_1354(data, threadData);

  Graph_eqFunction_1376(data, threadData);

  Graph_eqFunction_1377(data, threadData);

  Graph_eqFunction_1378(data, threadData);

  Graph_eqFunction_1379(data, threadData);

  Graph_eqFunction_1380(data, threadData);

  Graph_eqFunction_1402(data, threadData);

  Graph_eqFunction_1403(data, threadData);

  Graph_eqFunction_1404(data, threadData);

  Graph_eqFunction_1405(data, threadData);

  Graph_eqFunction_1406(data, threadData);

  Graph_eqFunction_1428(data, threadData);

  Graph_eqFunction_1429(data, threadData);

  Graph_eqFunction_1430(data, threadData);

  Graph_eqFunction_1431(data, threadData);

  Graph_eqFunction_1432(data, threadData);

  Graph_eqFunction_1454(data, threadData);

  Graph_eqFunction_1455(data, threadData);

  Graph_eqFunction_1456(data, threadData);

  Graph_eqFunction_1457(data, threadData);

  Graph_eqFunction_1458(data, threadData);

  Graph_eqFunction_1480(data, threadData);

  Graph_eqFunction_1481(data, threadData);

  Graph_eqFunction_1482(data, threadData);

  Graph_eqFunction_1483(data, threadData);

  Graph_eqFunction_1484(data, threadData);

  Graph_eqFunction_1506(data, threadData);

  Graph_eqFunction_1507(data, threadData);

  Graph_eqFunction_1508(data, threadData);

  Graph_eqFunction_1509(data, threadData);

  Graph_eqFunction_1510(data, threadData);

  Graph_eqFunction_1532(data, threadData);

  Graph_eqFunction_1533(data, threadData);

  Graph_eqFunction_1534(data, threadData);

  Graph_eqFunction_1535(data, threadData);

  Graph_eqFunction_1536(data, threadData);

  Graph_eqFunction_1558(data, threadData);

  Graph_eqFunction_1559(data, threadData);

  Graph_eqFunction_1560(data, threadData);

  Graph_eqFunction_1561(data, threadData);

  Graph_eqFunction_1562(data, threadData);

  Graph_eqFunction_1584(data, threadData);

  Graph_eqFunction_1585(data, threadData);

  Graph_eqFunction_1586(data, threadData);

  Graph_eqFunction_1587(data, threadData);

  Graph_eqFunction_1588(data, threadData);

  Graph_eqFunction_1610(data, threadData);

  Graph_eqFunction_1611(data, threadData);

  Graph_eqFunction_1612(data, threadData);

  Graph_eqFunction_1613(data, threadData);

  Graph_eqFunction_1614(data, threadData);

  Graph_eqFunction_1636(data, threadData);

  Graph_eqFunction_1637(data, threadData);

  Graph_eqFunction_1638(data, threadData);

  Graph_eqFunction_1639(data, threadData);

  Graph_eqFunction_1640(data, threadData);

  Graph_eqFunction_1662(data, threadData);

  Graph_eqFunction_1663(data, threadData);

  Graph_eqFunction_1664(data, threadData);

  Graph_eqFunction_1665(data, threadData);

  Graph_eqFunction_1666(data, threadData);

  Graph_eqFunction_1688(data, threadData);

  Graph_eqFunction_1689(data, threadData);

  Graph_eqFunction_1690(data, threadData);

  Graph_eqFunction_1691(data, threadData);

  Graph_eqFunction_1692(data, threadData);

  Graph_eqFunction_1714(data, threadData);

  Graph_eqFunction_1715(data, threadData);

  Graph_eqFunction_1716(data, threadData);

  Graph_eqFunction_1717(data, threadData);

  Graph_eqFunction_1718(data, threadData);

  Graph_eqFunction_1740(data, threadData);

  Graph_eqFunction_1741(data, threadData);

  Graph_eqFunction_1742(data, threadData);

  Graph_eqFunction_1743(data, threadData);

  Graph_eqFunction_1744(data, threadData);

  Graph_eqFunction_1766(data, threadData);

  Graph_eqFunction_1767(data, threadData);

  Graph_eqFunction_1768(data, threadData);

  Graph_eqFunction_1769(data, threadData);

  Graph_eqFunction_1770(data, threadData);

  Graph_eqFunction_1792(data, threadData);

  Graph_eqFunction_1793(data, threadData);

  Graph_eqFunction_1794(data, threadData);

  Graph_eqFunction_1795(data, threadData);

  Graph_eqFunction_1796(data, threadData);

  Graph_eqFunction_1818(data, threadData);

  Graph_eqFunction_1819(data, threadData);

  Graph_eqFunction_1820(data, threadData);

  Graph_eqFunction_1821(data, threadData);

  Graph_eqFunction_1822(data, threadData);

  Graph_eqFunction_1844(data, threadData);

  Graph_eqFunction_1845(data, threadData);

  Graph_eqFunction_1846(data, threadData);

  Graph_eqFunction_1847(data, threadData);

  Graph_eqFunction_1848(data, threadData);

  Graph_eqFunction_1870(data, threadData);

  Graph_eqFunction_1871(data, threadData);

  Graph_eqFunction_1872(data, threadData);

  Graph_eqFunction_1873(data, threadData);

  Graph_eqFunction_1874(data, threadData);

  Graph_eqFunction_1896(data, threadData);

  Graph_eqFunction_1897(data, threadData);

  Graph_eqFunction_1898(data, threadData);

  Graph_eqFunction_1899(data, threadData);

  Graph_eqFunction_1900(data, threadData);

  Graph_eqFunction_1922(data, threadData);

  Graph_eqFunction_1923(data, threadData);

  Graph_eqFunction_1924(data, threadData);

  Graph_eqFunction_1925(data, threadData);

  Graph_eqFunction_1926(data, threadData);

  Graph_eqFunction_1948(data, threadData);

  Graph_eqFunction_1949(data, threadData);

  Graph_eqFunction_1950(data, threadData);

  Graph_eqFunction_1951(data, threadData);

  Graph_eqFunction_1952(data, threadData);

  Graph_eqFunction_1974(data, threadData);

  Graph_eqFunction_1975(data, threadData);

  Graph_eqFunction_1976(data, threadData);

  Graph_eqFunction_1977(data, threadData);

  Graph_eqFunction_1978(data, threadData);

  Graph_eqFunction_2000(data, threadData);

  Graph_eqFunction_2001(data, threadData);

  Graph_eqFunction_2002(data, threadData);

  Graph_eqFunction_2003(data, threadData);

  Graph_eqFunction_2004(data, threadData);

  Graph_eqFunction_2012(data, threadData);

  Graph_eqFunction_2013(data, threadData);

  Graph_eqFunction_2014(data, threadData);

  Graph_eqFunction_2015(data, threadData);

  Graph_eqFunction_2016(data, threadData);

  Graph_eqFunction_2017(data, threadData);

  Graph_eqFunction_2018(data, threadData);

  Graph_eqFunction_2019(data, threadData);

  Graph_eqFunction_2020(data, threadData);

  Graph_eqFunction_2021(data, threadData);

  Graph_eqFunction_2022(data, threadData);

  Graph_eqFunction_2023(data, threadData);

  Graph_eqFunction_2024(data, threadData);

  Graph_eqFunction_2025(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int Graph_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int Graph_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Graph_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Graph_12jac.h"
#include "Graph_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Graph_callback = {
   (int (*)(DATA *, threadData_t *, void *)) Graph_performSimulation,
   (int (*)(DATA *, threadData_t *, void *)) Graph_performQSSSimulation,
   Graph_updateContinuousSystem,
   Graph_callExternalObjectDestructors,
   Graph_initialNonLinearSystem,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   Graph_initializeStateSets,
   #else
   NULL,
   #endif
   Graph_initializeDAEmodeData,
   Graph_functionODE,
   Graph_functionAlgebraics,
   Graph_functionDAE,
   Graph_functionLocalKnownVars,
   Graph_input_function,
   Graph_input_function_init,
   Graph_input_function_updateStartValues,
   Graph_output_function,
   Graph_function_storeDelayed,
   Graph_updateBoundVariableAttributes,
   Graph_functionInitialEquations,
   0, /* useHomotopy - 0: no homotopy or local homotopy, 1: global homotopy, 2: new global homotopy approach */
   Graph_functionInitialEquations_lambda0,
   Graph_functionRemovedInitialEquations,
   Graph_updateBoundParameters,
   Graph_checkForAsserts,
   Graph_function_ZeroCrossingsEquations,
   Graph_function_ZeroCrossings,
   Graph_function_updateRelations,
   Graph_checkForDiscreteChanges,
   Graph_zeroCrossingDescription,
   Graph_relationDescription,
   Graph_function_initSample,
   Graph_INDEX_JAC_A,
   Graph_INDEX_JAC_B,
   Graph_INDEX_JAC_C,
   Graph_INDEX_JAC_D,
   Graph_initialAnalyticJacobianA,
   Graph_initialAnalyticJacobianB,
   Graph_initialAnalyticJacobianC,
   Graph_initialAnalyticJacobianD,
   Graph_functionJacA_column,
   Graph_functionJacB_column,
   Graph_functionJacC_column,
   Graph_functionJacD_column,
   Graph_linear_model_frame,
   Graph_linear_model_datarecovery_frame,
   Graph_mayer,
   Graph_lagrange,
   Graph_pickUpBoundsForInputsInOptimization,
   Graph_setInputData,
   Graph_getTimeGrid,
   Graph_symbolicInlineSystem,
   Graph_function_initSynchronous,
   Graph_function_updateSynchronous,
   Graph_function_equationsSynchronous,
   NULL,
   #ifdef FMU_EXPERIMENTAL
   Graph_functionODE_Partial,
   Graph_functionFMIJacobian,
   #endif
   Graph_inputNames
};

void Graph_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &Graph_callback;
  data->modelData->modelName = "Graph";
  data->modelData->modelFilePrefix = "Graph";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI-master/Simulator";
  data->modelData->modelGUID = "{75516925-6d31-4897-8614-3d3c70528439}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "Graph_init.c"
    ;
  static const char contents_info[] =
    #include "Graph_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "Graph_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "Graph_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 1114;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 13284;
  data->modelData->nParametersInteger = 246;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 328;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 1406;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "Graph_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 3;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 15843;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 80;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 4;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
}

#ifdef __cplusplus
}
#endif

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
int main(int argc, char**argv)
{
  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    Graph_setupDataStruc(&data, threadData);
    res = _main_SimulationRuntime(argc, argv, &data, threadData);
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  EXIT(res);
  return res;
}

