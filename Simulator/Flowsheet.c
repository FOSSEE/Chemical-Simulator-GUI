/* Main Simulation File */
#include "Flowsheet_model.h"

#define prefixedName_performSimulation Flowsheet_performSimulation
#define prefixedName_updateContinuousSystem Flowsheet_updateContinuousSystem
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation Flowsheet_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int Flowsheet_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Flowsheet_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Flowsheet_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Flowsheet_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Flowsheet_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
 equation index: 501
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[1,1] = MaterialStream1.F_pc[1,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_501(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,501};
  data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */ = (data->localData[0]->realVars[25] /* MaterialStream1._F_pc[1,1] variable */) * (data->simulationInfo->realParameter[532]);
  TRACE_POP
}
/*
 equation index: 502
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[1,2] = MaterialStream1.F_pc[1,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_502(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,502};
  data->localData[0]->realVars[35] /* MaterialStream1._Fm_pc[1,2] variable */ = (data->localData[0]->realVars[26] /* MaterialStream1._F_pc[1,2] variable */) * (data->simulationInfo->realParameter[533]);
  TRACE_POP
}
/*
 equation index: 503
 type: SIMPLE_ASSIGN
 MaterialStream1._K_c[1] = 9.869232667160129e-006 * MaterialStream1.Pvap_c[1]
 */
void Flowsheet_eqFunction_503(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,503};
  data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[60] /* MaterialStream1._Pvap_c[1] variable */);
  TRACE_POP
}
/*
 equation index: 504
 type: SIMPLE_ASSIGN
 MaterialStream1._K_c[2] = 9.869232667160129e-006 * MaterialStream1.Pvap_c[2]
 */
void Flowsheet_eqFunction_504(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,504};
  data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[61] /* MaterialStream1._Pvap_c[2] variable */);
  TRACE_POP
}
/*
 equation index: 505
 type: SIMPLE_ASSIGN
 MaterialStream2._K_c[1] = DIVISION(MaterialStream2.Pvap_c[1], Heater1.Pout)
 */
void Flowsheet_eqFunction_505(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,505};
  data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */ = DIVISION_SIM(data->localData[0]->realVars[148] /* MaterialStream2._Pvap_c[1] variable */,data->localData[0]->realVars[4] /* Heater1._Pout variable */,"Heater1.Pout",equationIndexes);
  TRACE_POP
}
/*
 equation index: 506
 type: SIMPLE_ASSIGN
 MaterialStream2._K_c[2] = DIVISION(MaterialStream2.Pvap_c[2], Heater1.Pout)
 */
void Flowsheet_eqFunction_506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,506};
  data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */ = DIVISION_SIM(data->localData[0]->realVars[149] /* MaterialStream2._Pvap_c[2] variable */,data->localData[0]->realVars[4] /* Heater1._Pout variable */,"Heater1.Pout",equationIndexes);
  TRACE_POP
}
void Flowsheet_eqFunction_507(DATA*,threadData_t*);
void Flowsheet_eqFunction_508(DATA*,threadData_t*);
void Flowsheet_eqFunction_509(DATA*,threadData_t*);
void Flowsheet_eqFunction_514(DATA*,threadData_t*);
void Flowsheet_eqFunction_513(DATA*,threadData_t*);
void Flowsheet_eqFunction_512(DATA*,threadData_t*);
void Flowsheet_eqFunction_511(DATA*,threadData_t*);
void Flowsheet_eqFunction_510(DATA*,threadData_t*);
/*
 equation index: 523
 indexNonlinear: 8
 type: NONLINEAR
 
 vars: {MaterialStream1._xliq, MaterialStream1._x_pc[2,1], MaterialStream1._x_pc[3,1], MaterialStream1._x_pc[3,2], MaterialStream1._x_pc[2,2]}
 eqns: {507, 508, 509, 514, 513, 512, 511, 510}
 */
void Flowsheet_eqFunction_523(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,523};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 523 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[0] = data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */;
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[1] = data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[2] = data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */;
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[3] = data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */;
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[4] = data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */;
  retValue = solve_nonlinear_system(data, threadData, 8);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,523};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 523 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[0];
  data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[1];
  data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[2];
  data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[3];
  data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[4];
  TRACE_POP
}
/*
 equation index: 524
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[2,2] = MaterialStream1.x_pc[2,2] * MaterialStream1.F_p[2]
 */
void Flowsheet_eqFunction_524(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,524};
  data->localData[0]->realVars[28] /* MaterialStream1._F_pc[2,2] variable */ = (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 525
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[2,2] = MaterialStream1.F_pc[2,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_525(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,525};
  data->localData[0]->realVars[37] /* MaterialStream1._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[28] /* MaterialStream1._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[533]);
  TRACE_POP
}
/*
 equation index: 526
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[3,2] = MaterialStream1.x_pc[3,2] * MaterialStream1.F_p[3]
 */
void Flowsheet_eqFunction_526(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,526};
  data->localData[0]->realVars[30] /* MaterialStream1._F_pc[3,2] variable */ = (data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 527
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[3,2] = MaterialStream1.F_pc[3,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_527(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,527};
  data->localData[0]->realVars[39] /* MaterialStream1._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[30] /* MaterialStream1._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[533]);
  TRACE_POP
}
/*
 equation index: 528
 type: ALGORITHM
 
   (MaterialStream1.S_pc[2,2], MaterialStream1.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tb, MaterialStream1.C[2].Tc, 350.0, 101325.0, MaterialStream1.x_pc[2,2], MaterialStream1.x_pc[3,2]);
 */
void Flowsheet_eqFunction_528(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,528};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577], (modelica_real)data->simulationInfo->realParameter[578], (modelica_real)data->simulationInfo->realParameter[579]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477], (modelica_real)data->simulationInfo->realParameter[478], (modelica_real)data->simulationInfo->realParameter[479]);
  data->localData[0]->realVars[68] /* MaterialStream1._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp0, tmp1, data->simulationInfo->realParameter[547], data->simulationInfo->realParameter[549], 350.0, 101325.0, data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */, data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ ,&data->localData[0]->realVars[70] /* MaterialStream1._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 529
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[3,1] = MaterialStream1.x_pc[3,1] * MaterialStream1.F_p[3]
 */
void Flowsheet_eqFunction_529(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,529};
  data->localData[0]->realVars[29] /* MaterialStream1._F_pc[3,1] variable */ = (data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 530
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[3,1] = MaterialStream1.F_pc[3,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_530(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,530};
  data->localData[0]->realVars[38] /* MaterialStream1._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[29] /* MaterialStream1._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[532]);
  TRACE_POP
}
/*
 equation index: 531
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.H_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.H_pc[3,2]
 */
void Flowsheet_eqFunction_531(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,531};
  data->localData[0]->realVars[42] /* MaterialStream1._H_p[3] variable */ = (data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[47] /* MaterialStream1._H_pc[3,1] variable */) + (data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[48] /* MaterialStream1._H_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 532
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.Cp_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_532(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,532};
  data->localData[0]->realVars[12] /* MaterialStream1._Cp_p[3] variable */ = (data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[17] /* MaterialStream1._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[18] /* MaterialStream1._Cp_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 533
 type: ALGORITHM
 
   (MaterialStream1.S_pc[2,1], MaterialStream1.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tb, MaterialStream1.C[1].Tc, 350.0, 101325.0, MaterialStream1.x_pc[2,1], MaterialStream1.x_pc[3,1]);
 */
void Flowsheet_eqFunction_533(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,533};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571], (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471], (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473]);
  data->localData[0]->realVars[67] /* MaterialStream1._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp2, tmp3, data->simulationInfo->realParameter[546], data->simulationInfo->realParameter[548], 350.0, 101325.0, data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */, data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ ,&data->localData[0]->realVars[69] /* MaterialStream1._S_pc[3,1] variable */);
  TRACE_POP
}
/*
 equation index: 534
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.S_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.S_pc[3,2]
 */
void Flowsheet_eqFunction_534(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,534};
  data->localData[0]->realVars[64] /* MaterialStream1._S_p[3] variable */ = (data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[69] /* MaterialStream1._S_pc[3,1] variable */) + (data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[70] /* MaterialStream1._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 535
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[2,1] = MaterialStream1.x_pc[2,1] * MaterialStream1.F_p[2]
 */
void Flowsheet_eqFunction_535(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,535};
  data->localData[0]->realVars[27] /* MaterialStream1._F_pc[2,1] variable */ = (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 536
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[2,1] = MaterialStream1.F_pc[2,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_536(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,536};
  data->localData[0]->realVars[36] /* MaterialStream1._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[27] /* MaterialStream1._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[532]);
  TRACE_POP
}
/*
 equation index: 537
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.H_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.H_pc[2,2]
 */
void Flowsheet_eqFunction_537(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,537};
  data->localData[0]->realVars[41] /* MaterialStream1._H_p[2] variable */ = (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[45] /* MaterialStream1._H_pc[2,1] variable */) + (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[46] /* MaterialStream1._H_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 538
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[1] = MaterialStream1.xliq * MaterialStream1.H_p[2] + Heater1.xvapin * MaterialStream1.H_p[3]
 */
void Flowsheet_eqFunction_538(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,538};
  data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */ = (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[41] /* MaterialStream1._H_p[2] variable */) + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (data->localData[0]->realVars[42] /* MaterialStream1._H_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 539
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.H_p[1]
 */
void Flowsheet_eqFunction_539(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,539};
  data->localData[0]->realVars[44] /* MaterialStream1._H_pc[1,2] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 540
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.H_p[1]
 */
void Flowsheet_eqFunction_540(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,540};
  data->localData[0]->realVars[43] /* MaterialStream1._H_pc[1,1] variable */ = (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 541
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.Cp_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_541(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,541};
  data->localData[0]->realVars[11] /* MaterialStream1._Cp_p[2] variable */ = (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[15] /* MaterialStream1._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[16] /* MaterialStream1._Cp_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 542
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[1] = MaterialStream1.xliq * MaterialStream1.Cp_p[2] + Heater1.xvapin * MaterialStream1.Cp_p[3]
 */
void Flowsheet_eqFunction_542(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,542};
  data->localData[0]->realVars[10] /* MaterialStream1._Cp_p[1] variable */ = (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[11] /* MaterialStream1._Cp_p[2] variable */) + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (data->localData[0]->realVars[12] /* MaterialStream1._Cp_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 543
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.Cp_p[1]
 */
void Flowsheet_eqFunction_543(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,543};
  data->localData[0]->realVars[14] /* MaterialStream1._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[10] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 544
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.Cp_p[1]
 */
void Flowsheet_eqFunction_544(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,544};
  data->localData[0]->realVars[13] /* MaterialStream1._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[10] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 545
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.S_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.S_pc[2,2]
 */
void Flowsheet_eqFunction_545(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,545};
  data->localData[0]->realVars[63] /* MaterialStream1._S_p[2] variable */ = (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[67] /* MaterialStream1._S_pc[2,1] variable */) + (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[68] /* MaterialStream1._S_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 546
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[1] = MaterialStream1.xliq * MaterialStream1.S_p[2] + Heater1.xvapin * MaterialStream1.S_p[3]
 */
void Flowsheet_eqFunction_546(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,546};
  data->localData[0]->realVars[62] /* MaterialStream1._S_p[1] variable */ = (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[63] /* MaterialStream1._S_p[2] variable */) + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (data->localData[0]->realVars[64] /* MaterialStream1._S_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 547
 type: SIMPLE_ASSIGN
 MaterialStream1._S_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.S_p[1]
 */
void Flowsheet_eqFunction_547(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,547};
  data->localData[0]->realVars[66] /* MaterialStream1._S_pc[1,2] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[62] /* MaterialStream1._S_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 548
 type: SIMPLE_ASSIGN
 MaterialStream1._S_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.S_p[1]
 */
void Flowsheet_eqFunction_548(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,548};
  data->localData[0]->realVars[65] /* MaterialStream1._S_pc[1,1] variable */ = (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[62] /* MaterialStream1._S_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 549
 type: ALGORITHM
 
   MaterialStream1.MW_p[3] := $START.MaterialStream1.MW_p[3];
   MaterialStream1.MW_p[2] := $START.MaterialStream1.MW_p[2];
   MaterialStream1.MW_p[1] := $START.MaterialStream1.MW_p[1];
   for i in 1:2 loop
     MaterialStream1.MW_p[:] := {MaterialStream1.MW_p[1] + MaterialStream1.x_pc[1,i] * MaterialStream1.C[i].MW, MaterialStream1.MW_p[2] + MaterialStream1.x_pc[2,i] * MaterialStream1.C[i].MW, MaterialStream1.MW_p[3] + MaterialStream1.x_pc[3,i] * MaterialStream1.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_549(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,549};
  real_array tmp4;
  index_spec_t tmp5;
  real_array tmp6;
  modelica_integer tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
  data->localData[0]->realVars[56] /* MaterialStream1._MW_p[3] variable */ = data->modelData->realVarsData[56].attribute /* MaterialStream1._MW_p[3] variable */.start;

  data->localData[0]->realVars[55] /* MaterialStream1._MW_p[2] variable */ = data->modelData->realVarsData[55].attribute /* MaterialStream1._MW_p[2] variable */.start;

  data->localData[0]->realVars[54] /* MaterialStream1._MW_p[1] variable */ = data->modelData->realVarsData[54].attribute /* MaterialStream1._MW_p[1] variable */.start;

  tmp7 = ((modelica_integer) 1); tmp8 = 1; tmp9 = ((modelica_integer) 2);
  if(!tmp8)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert_withEquationIndexes(threadData, info, equationIndexes, "assertion range step != 0 failed");
  }
  else if(!(((tmp8 > 0) && (tmp7 > tmp9)) || ((tmp8 < 0) && (tmp7 < tmp9))))
  {
    modelica_integer $Pi;
    for($Pi = ((modelica_integer) 1); in_range_integer($Pi, tmp7, tmp9); $Pi += tmp8)
    {
      array_alloc_scalar_real_array(&tmp4, 3, (modelica_real)data->localData[0]->realVars[54] /* MaterialStream1._MW_p[1] variable */ + ((&data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[532])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[55] /* MaterialStream1._MW_p[2] variable */ + ((&data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[532])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[56] /* MaterialStream1._MW_p[3] variable */ + ((&data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[532])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp5, 1, (1), (int*)0, 'W');
      real_array_create(&tmp6, (modelica_real*)&data->localData[0]->realVars[54] /* MaterialStream1._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp4, &tmp6, &tmp5);
    }
  }
  TRACE_POP
}
/*
 equation index: 550
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[3] = MaterialStream1.F_p[3] * MaterialStream1.MW_p[3]
 */
void Flowsheet_eqFunction_550(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,550};
  data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */ = (data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */) * (data->localData[0]->realVars[56] /* MaterialStream1._MW_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 551
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[2] = MaterialStream1.F_p[2] * MaterialStream1.MW_p[2]
 */
void Flowsheet_eqFunction_551(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,551};
  data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */ = (data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */) * (data->localData[0]->realVars[55] /* MaterialStream1._MW_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 552
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[1] = 100.0 * MaterialStream1.MW_p[1]
 */
void Flowsheet_eqFunction_552(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,552};
  data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */ = (100.0) * (data->localData[0]->realVars[54] /* MaterialStream1._MW_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 553
 type: SIMPLE_ASSIGN
 MaterialStream1._xm_pc[1,2] = DIVISION(MaterialStream1.Fm_pc[1,2], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_553(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,553};
  data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[35] /* MaterialStream1._Fm_pc[1,2] variable */,data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 554
 type: SIMPLE_ASSIGN
 MaterialStream1._xmliq = DIVISION(MaterialStream1.Fm_p[2], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_554(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,554};
  data->localData[0]->realVars[98] /* MaterialStream1._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */,data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 555
 type: SIMPLE_ASSIGN
 MaterialStream1._xmvap = DIVISION(MaterialStream1.Fm_p[3], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_555(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,555};
  data->localData[0]->realVars[99] /* MaterialStream1._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */,data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 556
 type: LINEAR
 
 <var>MaterialStream1._xm_pc[3,2]</var>
 <var>MaterialStream1._xm_pc[2,1]</var>
 <var>MaterialStream1._xm_pc[2,2]</var>
 <var>MaterialStream1._xm_pc[3,1]</var>
 <var>MaterialStream1._xm_pc[1,1]</var>
 <row>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1.Fm_pc[1,1] else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[3,1] else MaterialStream1.Fm_pc[1,1]</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[1,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[2,2] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[2,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then -MaterialStream1.xm_pc[1,2] else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[3,2] else -MaterialStream1.xm_pc[1,2]</cell>
 </row>
 <matrix>
   <cell row="0" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[3] else -0.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -MaterialStream1.Fm_p[1] else if 101325.0 >= MaterialStream1.Pdew then -0.0 else -MaterialStream1.Fm_p[1])</residual>
   </cell><cell row="1" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[1] else 0.0)</residual>
   </cell><cell row="2" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[2] else 0.0)</residual>
   </cell><cell row="2" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="2" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -1.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="3" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="3" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[2] else 0.0)</residual>
   </cell><cell row="3" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[3] else 1.0)</residual>
   </cell><cell row="4" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_556(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,556};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 556 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[5].x[0] = data->localData[1]->realVars[97] /* MaterialStream1._xm_pc[3,2] variable */;
  data->simulationInfo->linearSystemData[5].x[1] = data->localData[1]->realVars[94] /* MaterialStream1._xm_pc[2,1] variable */;
  data->simulationInfo->linearSystemData[5].x[2] = data->localData[1]->realVars[95] /* MaterialStream1._xm_pc[2,2] variable */;
  data->simulationInfo->linearSystemData[5].x[3] = data->localData[1]->realVars[96] /* MaterialStream1._xm_pc[3,1] variable */;
  data->simulationInfo->linearSystemData[5].x[4] = data->localData[1]->realVars[92] /* MaterialStream1._xm_pc[1,1] variable */;
  retValue = solve_linear_system(data, threadData, 5);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,556};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 556 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[97] /* MaterialStream1._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[5].x[0];
  data->localData[0]->realVars[94] /* MaterialStream1._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[5].x[1];
  data->localData[0]->realVars[95] /* MaterialStream1._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[5].x[2];
  data->localData[0]->realVars[96] /* MaterialStream1._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[5].x[3];
  data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[5].x[4];
  TRACE_POP
}
/*
 equation index: 557
 type: SIMPLE_ASSIGN
 MaterialStream2._x_pc[1,2] = MaterialStream1.x_pc[1,2]
 */
void Flowsheet_eqFunction_557(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,557};
  data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */ = data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */;
  TRACE_POP
}
/*
 equation index: 558
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[1,2] = 100.0 * MaterialStream2.x_pc[1,2]
 */
void Flowsheet_eqFunction_558(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,558};
  data->localData[0]->realVars[115] /* MaterialStream2._F_pc[1,2] variable */ = (100.0) * (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */);
  TRACE_POP
}
/*
 equation index: 559
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[1,2] = MaterialStream2.F_pc[1,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_559(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,559};
  data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[1,2] variable */ = (data->localData[0]->realVars[115] /* MaterialStream2._F_pc[1,2] variable */) * (data->simulationInfo->realParameter[740]);
  TRACE_POP
}
/*
 equation index: 560
 type: SIMPLE_ASSIGN
 MaterialStream2._x_pc[1,1] = MaterialStream1.x_pc[1,1]
 */
void Flowsheet_eqFunction_560(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,560};
  data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */ = data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */;
  TRACE_POP
}
/*
 equation index: 561
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[1,1] = 100.0 * MaterialStream2.x_pc[1,1]
 */
void Flowsheet_eqFunction_561(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,561};
  data->localData[0]->realVars[114] /* MaterialStream2._F_pc[1,1] variable */ = (100.0) * (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */);
  TRACE_POP
}
/*
 equation index: 562
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[1,1] = MaterialStream2.F_pc[1,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_562(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,562};
  data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */ = (data->localData[0]->realVars[114] /* MaterialStream2._F_pc[1,1] variable */) * (data->simulationInfo->realParameter[739]);
  TRACE_POP
}
/*
 equation index: 563
 type: SIMPLE_ASSIGN
 MaterialStream2._Pbubl = MaterialStream2.x_pc[1,1] * $cse3 + MaterialStream2.x_pc[1,2] * $cse4
 */
void Flowsheet_eqFunction_563(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,563};
  data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[2] /* $cse3 variable */) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[3] /* $cse4 variable */);
  TRACE_POP
}
/*
 equation index: 564
 type: SIMPLE_ASSIGN
 MaterialStream2._Pdew = DIVISION(1.0, MaterialStream2.x_pc[1,1] * $cse1 + MaterialStream2.x_pc[1,2] * $cse2)
 */
void Flowsheet_eqFunction_564(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,564};
  data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */ = DIVISION_SIM(1.0,(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[0] /* $cse1 variable */) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[1] /* $cse2 variable */),"MaterialStream2.x_pc[1,1] * $cse1 + MaterialStream2.x_pc[1,2] * $cse2",equationIndexes);
  TRACE_POP
}
void Flowsheet_eqFunction_565(DATA*,threadData_t*);
void Flowsheet_eqFunction_566(DATA*,threadData_t*);
void Flowsheet_eqFunction_567(DATA*,threadData_t*);
void Flowsheet_eqFunction_572(DATA*,threadData_t*);
void Flowsheet_eqFunction_571(DATA*,threadData_t*);
void Flowsheet_eqFunction_570(DATA*,threadData_t*);
void Flowsheet_eqFunction_569(DATA*,threadData_t*);
void Flowsheet_eqFunction_568(DATA*,threadData_t*);
/*
 equation index: 581
 indexNonlinear: 9
 type: NONLINEAR
 
 vars: {MaterialStream2._xliq, MaterialStream2._x_pc[3,2], MaterialStream2._x_pc[2,1], MaterialStream2._x_pc[3,1], MaterialStream2._x_pc[2,2]}
 eqns: {565, 566, 567, 572, 571, 570, 569, 568}
 */
void Flowsheet_eqFunction_581(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,581};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 581 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[0] = data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */;
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[1] = data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */;
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[2] = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[3] = data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */;
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[4] = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */;
  retValue = solve_nonlinear_system(data, threadData, 9);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,581};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 581 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[0];
  data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[1];
  data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[2];
  data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[3];
  data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[4];
  TRACE_POP
}
/*
 equation index: 582
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.H_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.H_pc[2,2]
 */
void Flowsheet_eqFunction_582(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,582};
  data->localData[0]->realVars[130] /* MaterialStream2._H_p[2] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[134] /* MaterialStream2._H_pc[2,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[135] /* MaterialStream2._H_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 583
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.Cp_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_583(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,583};
  data->localData[0]->realVars[101] /* MaterialStream2._Cp_p[2] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[105] /* MaterialStream2._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[106] /* MaterialStream2._Cp_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 584
 type: ALGORITHM
 
   (MaterialStream2.S_pc[2,1], MaterialStream2.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tb, MaterialStream2.C[1].Tc, 380.0, Heater1.Pout, MaterialStream2.x_pc[2,1], MaterialStream2.x_pc[3,1]);
 */
void Flowsheet_eqFunction_584(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,584};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778], (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678], (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680]);
  data->localData[0]->realVars[155] /* MaterialStream2._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp0, tmp1, data->simulationInfo->realParameter[753], data->simulationInfo->realParameter[755], 380.0, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */, data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ ,&data->localData[0]->realVars[157] /* MaterialStream2._S_pc[3,1] variable */);
  TRACE_POP
}
/*
 equation index: 585
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[2,1] = MaterialStream2.x_pc[2,1] * MaterialStream2.F_p[2]
 */
void Flowsheet_eqFunction_585(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,585};
  data->localData[0]->realVars[116] /* MaterialStream2._F_pc[2,1] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 586
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[2,1] = MaterialStream2.F_pc[2,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_586(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,586};
  data->localData[0]->realVars[125] /* MaterialStream2._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[116] /* MaterialStream2._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[739]);
  TRACE_POP
}
/*
 equation index: 587
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[2,2] = MaterialStream2.x_pc[2,2] * MaterialStream2.F_p[2]
 */
void Flowsheet_eqFunction_587(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,587};
  data->localData[0]->realVars[117] /* MaterialStream2._F_pc[2,2] variable */ = (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 588
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[2,2] = MaterialStream2.F_pc[2,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_588(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,588};
  data->localData[0]->realVars[126] /* MaterialStream2._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[117] /* MaterialStream2._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[740]);
  TRACE_POP
}
/*
 equation index: 589
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[3,1] = MaterialStream2.x_pc[3,1] * MaterialStream2.F_p[3]
 */
void Flowsheet_eqFunction_589(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,589};
  data->localData[0]->realVars[118] /* MaterialStream2._F_pc[3,1] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 590
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[3,1] = MaterialStream2.F_pc[3,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_590(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,590};
  data->localData[0]->realVars[127] /* MaterialStream2._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[118] /* MaterialStream2._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[739]);
  TRACE_POP
}
/*
 equation index: 591
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[3,2] = MaterialStream2.x_pc[3,2] * MaterialStream2.F_p[3]
 */
void Flowsheet_eqFunction_591(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,591};
  data->localData[0]->realVars[119] /* MaterialStream2._F_pc[3,2] variable */ = (data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 592
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[3,2] = MaterialStream2.F_pc[3,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_592(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,592};
  data->localData[0]->realVars[128] /* MaterialStream2._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[119] /* MaterialStream2._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[740]);
  TRACE_POP
}
/*
 equation index: 593
 type: ALGORITHM
 
   (MaterialStream2.S_pc[2,2], MaterialStream2.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tb, MaterialStream2.C[2].Tc, 380.0, Heater1.Pout, MaterialStream2.x_pc[2,2], MaterialStream2.x_pc[3,2]);
 */
void Flowsheet_eqFunction_593(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,593};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784], (modelica_real)data->simulationInfo->realParameter[785], (modelica_real)data->simulationInfo->realParameter[786]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684], (modelica_real)data->simulationInfo->realParameter[685], (modelica_real)data->simulationInfo->realParameter[686]);
  data->localData[0]->realVars[156] /* MaterialStream2._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp2, tmp3, data->simulationInfo->realParameter[754], data->simulationInfo->realParameter[756], 380.0, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */, data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ ,&data->localData[0]->realVars[158] /* MaterialStream2._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 594
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.S_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.S_pc[2,2]
 */
void Flowsheet_eqFunction_594(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,594};
  data->localData[0]->realVars[151] /* MaterialStream2._S_p[2] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[155] /* MaterialStream2._S_pc[2,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[156] /* MaterialStream2._S_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 595
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.H_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.H_pc[3,2]
 */
void Flowsheet_eqFunction_595(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,595};
  data->localData[0]->realVars[131] /* MaterialStream2._H_p[3] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[136] /* MaterialStream2._H_pc[3,1] variable */) + (data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[137] /* MaterialStream2._H_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 596
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[1] = MaterialStream2.xliq * MaterialStream2.H_p[2] + Heater1.xvapout * MaterialStream2.H_p[3]
 */
void Flowsheet_eqFunction_596(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,596};
  data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */ = (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[130] /* MaterialStream2._H_p[2] variable */) + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (data->localData[0]->realVars[131] /* MaterialStream2._H_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 597
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.H_p[1]
 */
void Flowsheet_eqFunction_597(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,597};
  data->localData[0]->realVars[133] /* MaterialStream2._H_pc[1,2] variable */ = (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 598
 type: SIMPLE_ASSIGN
 Heater1._Q = DIVISION(100.0 * (MaterialStream2.H_p[1] - MaterialStream1.H_p[1]), Heater1.Eff)
 */
void Flowsheet_eqFunction_598(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,598};
  data->localData[0]->realVars[5] /* Heater1._Q variable */ = DIVISION_SIM((100.0) * (data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */ - data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */),data->simulationInfo->realParameter[397],"Heater1.Eff",equationIndexes);
  TRACE_POP
}
/*
 equation index: 599
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.Cp_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_599(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,599};
  data->localData[0]->realVars[102] /* MaterialStream2._Cp_p[3] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[107] /* MaterialStream2._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[108] /* MaterialStream2._Cp_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 600
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[1] = MaterialStream2.xliq * MaterialStream2.Cp_p[2] + Heater1.xvapout * MaterialStream2.Cp_p[3]
 */
void Flowsheet_eqFunction_600(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,600};
  data->localData[0]->realVars[100] /* MaterialStream2._Cp_p[1] variable */ = (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[101] /* MaterialStream2._Cp_p[2] variable */) + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (data->localData[0]->realVars[102] /* MaterialStream2._Cp_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 601
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.Cp_p[1]
 */
void Flowsheet_eqFunction_601(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,601};
  data->localData[0]->realVars[104] /* MaterialStream2._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[100] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 602
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.S_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.S_pc[3,2]
 */
void Flowsheet_eqFunction_602(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,602};
  data->localData[0]->realVars[152] /* MaterialStream2._S_p[3] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[157] /* MaterialStream2._S_pc[3,1] variable */) + (data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[158] /* MaterialStream2._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 603
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[1] = MaterialStream2.xliq * MaterialStream2.S_p[2] + Heater1.xvapout * MaterialStream2.S_p[3]
 */
void Flowsheet_eqFunction_603(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,603};
  data->localData[0]->realVars[150] /* MaterialStream2._S_p[1] variable */ = (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[151] /* MaterialStream2._S_p[2] variable */) + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (data->localData[0]->realVars[152] /* MaterialStream2._S_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 604
 type: SIMPLE_ASSIGN
 MaterialStream2._S_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.S_p[1]
 */
void Flowsheet_eqFunction_604(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,604};
  data->localData[0]->realVars[154] /* MaterialStream2._S_pc[1,2] variable */ = (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[150] /* MaterialStream2._S_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 605
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.H_p[1]
 */
void Flowsheet_eqFunction_605(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,605};
  data->localData[0]->realVars[132] /* MaterialStream2._H_pc[1,1] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 606
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.Cp_p[1]
 */
void Flowsheet_eqFunction_606(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,606};
  data->localData[0]->realVars[103] /* MaterialStream2._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[100] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 607
 type: SIMPLE_ASSIGN
 MaterialStream2._S_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.S_p[1]
 */
void Flowsheet_eqFunction_607(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,607};
  data->localData[0]->realVars[153] /* MaterialStream2._S_pc[1,1] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[150] /* MaterialStream2._S_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 608
 type: ALGORITHM
 
   MaterialStream2.MW_p[3] := $START.MaterialStream2.MW_p[3];
   MaterialStream2.MW_p[2] := $START.MaterialStream2.MW_p[2];
   MaterialStream2.MW_p[1] := $START.MaterialStream2.MW_p[1];
   for i in 1:2 loop
     MaterialStream2.MW_p[:] := {MaterialStream2.MW_p[1] + MaterialStream2.x_pc[1,i] * MaterialStream2.C[i].MW, MaterialStream2.MW_p[2] + MaterialStream2.x_pc[2,i] * MaterialStream2.C[i].MW, MaterialStream2.MW_p[3] + MaterialStream2.x_pc[3,i] * MaterialStream2.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_608(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,608};
  real_array tmp4;
  index_spec_t tmp5;
  real_array tmp6;
  modelica_integer tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
  data->localData[0]->realVars[145] /* MaterialStream2._MW_p[3] variable */ = data->modelData->realVarsData[145].attribute /* MaterialStream2._MW_p[3] variable */.start;

  data->localData[0]->realVars[144] /* MaterialStream2._MW_p[2] variable */ = data->modelData->realVarsData[144].attribute /* MaterialStream2._MW_p[2] variable */.start;

  data->localData[0]->realVars[143] /* MaterialStream2._MW_p[1] variable */ = data->modelData->realVarsData[143].attribute /* MaterialStream2._MW_p[1] variable */.start;

  tmp7 = ((modelica_integer) 1); tmp8 = 1; tmp9 = ((modelica_integer) 2);
  if(!tmp8)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert_withEquationIndexes(threadData, info, equationIndexes, "assertion range step != 0 failed");
  }
  else if(!(((tmp8 > 0) && (tmp7 > tmp9)) || ((tmp8 < 0) && (tmp7 < tmp9))))
  {
    modelica_integer $Pi;
    for($Pi = ((modelica_integer) 1); in_range_integer($Pi, tmp7, tmp9); $Pi += tmp8)
    {
      array_alloc_scalar_real_array(&tmp4, 3, (modelica_real)data->localData[0]->realVars[143] /* MaterialStream2._MW_p[1] variable */ + ((&data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[739])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[144] /* MaterialStream2._MW_p[2] variable */ + ((&data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[739])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[145] /* MaterialStream2._MW_p[3] variable */ + ((&data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[739])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp5, 1, (1), (int*)0, 'W');
      real_array_create(&tmp6, (modelica_real*)&data->localData[0]->realVars[143] /* MaterialStream2._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp4, &tmp6, &tmp5);
    }
  }
  TRACE_POP
}
/*
 equation index: 609
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[3] = MaterialStream2.F_p[3] * MaterialStream2.MW_p[3]
 */
void Flowsheet_eqFunction_609(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,609};
  data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */ = (data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */) * (data->localData[0]->realVars[145] /* MaterialStream2._MW_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 610
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[1] = 100.0 * MaterialStream2.MW_p[1]
 */
void Flowsheet_eqFunction_610(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,610};
  data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */ = (100.0) * (data->localData[0]->realVars[143] /* MaterialStream2._MW_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 611
 type: SIMPLE_ASSIGN
 MaterialStream2._xmvap = DIVISION(MaterialStream2.Fm_p[3], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_611(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,611};
  data->localData[0]->realVars[186] /* MaterialStream2._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */,data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 612
 type: SIMPLE_ASSIGN
 MaterialStream2._xm_pc[1,2] = DIVISION(MaterialStream2.Fm_pc[1,2], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_612(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,612};
  data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[1,2] variable */,data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 613
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[2] = MaterialStream2.F_p[2] * MaterialStream2.MW_p[2]
 */
void Flowsheet_eqFunction_613(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,613};
  data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */ = (data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */) * (data->localData[0]->realVars[144] /* MaterialStream2._MW_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 614
 type: SIMPLE_ASSIGN
 MaterialStream2._xmliq = DIVISION(MaterialStream2.Fm_p[2], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_614(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,614};
  data->localData[0]->realVars[185] /* MaterialStream2._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */,data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 615
 type: LINEAR
 
 <var>MaterialStream2._xm_pc[1,1]</var>
 <var>MaterialStream2._xm_pc[3,2]</var>
 <var>MaterialStream2._xm_pc[2,2]</var>
 <var>MaterialStream2._xm_pc[2,1]</var>
 <var>MaterialStream2._xm_pc[3,1]</var>
 <row>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[2,2] else 0.0</cell>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[1,1] else 0.0</cell>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[2,1] else 0.0</cell>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then -MaterialStream2.xm_pc[1,2] else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[3,2] else -MaterialStream2.xm_pc[1,2]</cell>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2.Fm_pc[1,1] else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[3,1] else MaterialStream2.Fm_pc[1,1]</cell>
 </row>
 <matrix>
   <cell row="0" col="0">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then -1.0 else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="0" col="2">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[2] else 0.0)</residual>
   </cell><cell row="0" col="3">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="1" col="0">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[1] else 0.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="2" col="1">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="2" col="3">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[2] else 0.0)</residual>
   </cell><cell row="3" col="1">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[3] else 1.0)</residual>
   </cell><cell row="3" col="2">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then -MaterialStream2.Fm_p[1] else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else -MaterialStream2.Fm_p[1])</residual>
   </cell><cell row="4" col="4">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then -0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[3] else -0.0)</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_615(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,615};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 615 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[6].x[0] = data->localData[1]->realVars[179] /* MaterialStream2._xm_pc[1,1] variable */;
  data->simulationInfo->linearSystemData[6].x[1] = data->localData[1]->realVars[184] /* MaterialStream2._xm_pc[3,2] variable */;
  data->simulationInfo->linearSystemData[6].x[2] = data->localData[1]->realVars[182] /* MaterialStream2._xm_pc[2,2] variable */;
  data->simulationInfo->linearSystemData[6].x[3] = data->localData[1]->realVars[181] /* MaterialStream2._xm_pc[2,1] variable */;
  data->simulationInfo->linearSystemData[6].x[4] = data->localData[1]->realVars[183] /* MaterialStream2._xm_pc[3,1] variable */;
  retValue = solve_linear_system(data, threadData, 6);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,615};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 615 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[6].x[0];
  data->localData[0]->realVars[184] /* MaterialStream2._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[6].x[1];
  data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[6].x[2];
  data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[6].x[3];
  data->localData[0]->realVars[183] /* MaterialStream2._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[6].x[4];
  TRACE_POP
}


int Flowsheet_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Flowsheet_functionLocalKnownVars(data, threadData);
  Flowsheet_eqFunction_501(data, threadData);

  Flowsheet_eqFunction_502(data, threadData);

  Flowsheet_eqFunction_503(data, threadData);

  Flowsheet_eqFunction_504(data, threadData);

  Flowsheet_eqFunction_505(data, threadData);

  Flowsheet_eqFunction_506(data, threadData);

  Flowsheet_eqFunction_523(data, threadData);

  Flowsheet_eqFunction_524(data, threadData);

  Flowsheet_eqFunction_525(data, threadData);

  Flowsheet_eqFunction_526(data, threadData);

  Flowsheet_eqFunction_527(data, threadData);

  Flowsheet_eqFunction_528(data, threadData);

  Flowsheet_eqFunction_529(data, threadData);

  Flowsheet_eqFunction_530(data, threadData);

  Flowsheet_eqFunction_531(data, threadData);

  Flowsheet_eqFunction_532(data, threadData);

  Flowsheet_eqFunction_533(data, threadData);

  Flowsheet_eqFunction_534(data, threadData);

  Flowsheet_eqFunction_535(data, threadData);

  Flowsheet_eqFunction_536(data, threadData);

  Flowsheet_eqFunction_537(data, threadData);

  Flowsheet_eqFunction_538(data, threadData);

  Flowsheet_eqFunction_539(data, threadData);

  Flowsheet_eqFunction_540(data, threadData);

  Flowsheet_eqFunction_541(data, threadData);

  Flowsheet_eqFunction_542(data, threadData);

  Flowsheet_eqFunction_543(data, threadData);

  Flowsheet_eqFunction_544(data, threadData);

  Flowsheet_eqFunction_545(data, threadData);

  Flowsheet_eqFunction_546(data, threadData);

  Flowsheet_eqFunction_547(data, threadData);

  Flowsheet_eqFunction_548(data, threadData);

  Flowsheet_eqFunction_549(data, threadData);

  Flowsheet_eqFunction_550(data, threadData);

  Flowsheet_eqFunction_551(data, threadData);

  Flowsheet_eqFunction_552(data, threadData);

  Flowsheet_eqFunction_553(data, threadData);

  Flowsheet_eqFunction_554(data, threadData);

  Flowsheet_eqFunction_555(data, threadData);

  Flowsheet_eqFunction_556(data, threadData);

  Flowsheet_eqFunction_557(data, threadData);

  Flowsheet_eqFunction_558(data, threadData);

  Flowsheet_eqFunction_559(data, threadData);

  Flowsheet_eqFunction_560(data, threadData);

  Flowsheet_eqFunction_561(data, threadData);

  Flowsheet_eqFunction_562(data, threadData);

  Flowsheet_eqFunction_563(data, threadData);

  Flowsheet_eqFunction_564(data, threadData);

  Flowsheet_eqFunction_581(data, threadData);

  Flowsheet_eqFunction_582(data, threadData);

  Flowsheet_eqFunction_583(data, threadData);

  Flowsheet_eqFunction_584(data, threadData);

  Flowsheet_eqFunction_585(data, threadData);

  Flowsheet_eqFunction_586(data, threadData);

  Flowsheet_eqFunction_587(data, threadData);

  Flowsheet_eqFunction_588(data, threadData);

  Flowsheet_eqFunction_589(data, threadData);

  Flowsheet_eqFunction_590(data, threadData);

  Flowsheet_eqFunction_591(data, threadData);

  Flowsheet_eqFunction_592(data, threadData);

  Flowsheet_eqFunction_593(data, threadData);

  Flowsheet_eqFunction_594(data, threadData);

  Flowsheet_eqFunction_595(data, threadData);

  Flowsheet_eqFunction_596(data, threadData);

  Flowsheet_eqFunction_597(data, threadData);

  Flowsheet_eqFunction_598(data, threadData);

  Flowsheet_eqFunction_599(data, threadData);

  Flowsheet_eqFunction_600(data, threadData);

  Flowsheet_eqFunction_601(data, threadData);

  Flowsheet_eqFunction_602(data, threadData);

  Flowsheet_eqFunction_603(data, threadData);

  Flowsheet_eqFunction_604(data, threadData);

  Flowsheet_eqFunction_605(data, threadData);

  Flowsheet_eqFunction_606(data, threadData);

  Flowsheet_eqFunction_607(data, threadData);

  Flowsheet_eqFunction_608(data, threadData);

  Flowsheet_eqFunction_609(data, threadData);

  Flowsheet_eqFunction_610(data, threadData);

  Flowsheet_eqFunction_611(data, threadData);

  Flowsheet_eqFunction_612(data, threadData);

  Flowsheet_eqFunction_613(data, threadData);

  Flowsheet_eqFunction_614(data, threadData);

  Flowsheet_eqFunction_615(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int Flowsheet_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int Flowsheet_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Flowsheet_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Flowsheet_12jac.h"
#include "Flowsheet_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Flowsheet_callback = {
   (int (*)(DATA *, threadData_t *, void *)) Flowsheet_performSimulation,
   (int (*)(DATA *, threadData_t *, void *)) Flowsheet_performQSSSimulation,
   Flowsheet_updateContinuousSystem,
   Flowsheet_callExternalObjectDestructors,
   Flowsheet_initialNonLinearSystem,
   Flowsheet_initialLinearSystem,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   Flowsheet_initializeStateSets,
   #else
   NULL,
   #endif
   Flowsheet_initializeDAEmodeData,
   Flowsheet_functionODE,
   Flowsheet_functionAlgebraics,
   Flowsheet_functionDAE,
   Flowsheet_functionLocalKnownVars,
   Flowsheet_input_function,
   Flowsheet_input_function_init,
   Flowsheet_input_function_updateStartValues,
   Flowsheet_output_function,
   Flowsheet_function_storeDelayed,
   Flowsheet_updateBoundVariableAttributes,
   Flowsheet_functionInitialEquations,
   0, /* useHomotopy - 0: no homotopy or local homotopy, 1: global homotopy, 2: new global homotopy approach */
   Flowsheet_functionInitialEquations_lambda0,
   Flowsheet_functionRemovedInitialEquations,
   Flowsheet_updateBoundParameters,
   Flowsheet_checkForAsserts,
   Flowsheet_function_ZeroCrossingsEquations,
   Flowsheet_function_ZeroCrossings,
   Flowsheet_function_updateRelations,
   Flowsheet_checkForDiscreteChanges,
   Flowsheet_zeroCrossingDescription,
   Flowsheet_relationDescription,
   Flowsheet_function_initSample,
   Flowsheet_INDEX_JAC_A,
   Flowsheet_INDEX_JAC_B,
   Flowsheet_INDEX_JAC_C,
   Flowsheet_INDEX_JAC_D,
   Flowsheet_initialAnalyticJacobianA,
   Flowsheet_initialAnalyticJacobianB,
   Flowsheet_initialAnalyticJacobianC,
   Flowsheet_initialAnalyticJacobianD,
   Flowsheet_functionJacA_column,
   Flowsheet_functionJacB_column,
   Flowsheet_functionJacC_column,
   Flowsheet_functionJacD_column,
   Flowsheet_linear_model_frame,
   Flowsheet_linear_model_datarecovery_frame,
   Flowsheet_mayer,
   Flowsheet_lagrange,
   Flowsheet_pickUpBoundsForInputsInOptimization,
   Flowsheet_setInputData,
   Flowsheet_getTimeGrid,
   Flowsheet_symbolicInlineSystem,
   Flowsheet_function_initSynchronous,
   Flowsheet_function_updateSynchronous,
   Flowsheet_function_equationsSynchronous,
   NULL,
   #ifdef FMU_EXPERIMENTAL
   Flowsheet_functionODE_Partial,
   Flowsheet_functionFMIJacobian,
   #endif
   Flowsheet_inputNames
};

void Flowsheet_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &Flowsheet_callback;
  data->modelData->modelName = "Flowsheet";
  data->modelData->modelFilePrefix = "Flowsheet";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator";
  data->modelData->modelGUID = "{a2f04884-38bf-49ff-8adb-71488d59e5bf}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "Flowsheet_init.c"
    ;
  static const char contents_info[] =
    #include "Flowsheet_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "Flowsheet_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "Flowsheet_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 187;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 939;
  data->modelData->nParametersInteger = 20;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 20;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 86;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 2;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 2;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "Flowsheet_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 7;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 1458;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 7;
  data->modelData->nNonLinearSystems = 10;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 11;
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
  
    Flowsheet_setupDataStruc(&data, threadData);
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

