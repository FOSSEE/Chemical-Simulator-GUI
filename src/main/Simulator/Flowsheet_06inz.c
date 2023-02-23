/* Initialization */
#include "Flowsheet_model.h"
#include "Flowsheet_11mix.h"
#include "Flowsheet_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Flowsheet_functionInitialEquations_0(DATA *data, threadData_t *threadData);


/*
 equation index: 1
 type: SIMPLE_ASSIGN
 MaterialStream1._gma_c[1] = 1.0
 */
void Flowsheet_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[70] /* MaterialStream1._gma_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 2
 type: SIMPLE_ASSIGN
 MaterialStream1._gma_c[2] = 1.0
 */
void Flowsheet_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[71] /* MaterialStream1._gma_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 3
 type: SIMPLE_ASSIGN
 MaterialStream1._Cpres_p[1] = 0.0
 */
void Flowsheet_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[14] /* MaterialStream1._Cpres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 4
 type: SIMPLE_ASSIGN
 MaterialStream1._Hres_p[1] = 0.0
 */
void Flowsheet_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  data->localData[0]->realVars[44] /* MaterialStream1._Hres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 5
 type: SIMPLE_ASSIGN
 MaterialStream1._Sres_p[1] = 0.0
 */
void Flowsheet_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  data->localData[0]->realVars[66] /* MaterialStream1._Sres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 6
 type: SIMPLE_ASSIGN
 MaterialStream2._gma_c[1] = 1.0
 */
void Flowsheet_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  data->localData[0]->realVars[160] /* MaterialStream2._gma_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 7
 type: SIMPLE_ASSIGN
 MaterialStream2._gma_c[2] = 1.0
 */
void Flowsheet_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  data->localData[0]->realVars[161] /* MaterialStream2._gma_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 8
 type: SIMPLE_ASSIGN
 MaterialStream2._Cpres_p[1] = 0.0
 */
void Flowsheet_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->realVars[104] /* MaterialStream2._Cpres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 9
 type: SIMPLE_ASSIGN
 MaterialStream2._Hres_p[1] = 0.0
 */
void Flowsheet_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  data->localData[0]->realVars[134] /* MaterialStream2._Hres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 10
 type: SIMPLE_ASSIGN
 MaterialStream2._Sres_p[1] = 0.0
 */
void Flowsheet_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  data->localData[0]->realVars[156] /* MaterialStream2._Sres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 11
 type: SIMPLE_ASSIGN
 MaterialStream3._gma_c[1] = 1.0
 */
void Flowsheet_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  data->localData[0]->realVars[250] /* MaterialStream3._gma_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 12
 type: SIMPLE_ASSIGN
 MaterialStream3._gma_c[2] = 1.0
 */
void Flowsheet_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[251] /* MaterialStream3._gma_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 13
 type: SIMPLE_ASSIGN
 MaterialStream3._Cpres_p[1] = 0.0
 */
void Flowsheet_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  data->localData[0]->realVars[194] /* MaterialStream3._Cpres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 14
 type: SIMPLE_ASSIGN
 MaterialStream3._Hres_p[1] = 0.0
 */
void Flowsheet_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  data->localData[0]->realVars[224] /* MaterialStream3._Hres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 15
 type: SIMPLE_ASSIGN
 MaterialStream3._Sres_p[1] = 0.0
 */
void Flowsheet_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  data->localData[0]->realVars[246] /* MaterialStream3._Sres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 16
 type: SIMPLE_ASSIGN
 MaterialStream2._Pvap_c[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[2].VP[1], MaterialStream2.C[2].VP[2], MaterialStream2.C[2].VP[3], MaterialStream2.C[2].VP[4], MaterialStream2.C[2].VP[5], MaterialStream2.C[2].VP[6]}, 300.0)
 */
void Flowsheet_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[560], (modelica_real)data->simulationInfo->realParameter[561], (modelica_real)data->simulationInfo->realParameter[562], (modelica_real)data->simulationInfo->realParameter[563], (modelica_real)data->simulationInfo->realParameter[564], (modelica_real)data->simulationInfo->realParameter[565]);
  data->localData[0]->realVars[146] /* MaterialStream2._Pvap_c[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, 300.0);
  TRACE_POP
}

/*
 equation index: 17
 type: SIMPLE_ASSIGN
 MaterialStream2._K_c[2] = 9.869232667160129e-006 * MaterialStream2.Pvap_c[2]
 */
void Flowsheet_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[146] /* MaterialStream2._Pvap_c[2] variable */);
  TRACE_POP
}

/*
 equation index: 18
 type: SIMPLE_ASSIGN
 MaterialStream2._Pvap_c[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[1].VP[1], MaterialStream2.C[1].VP[2], MaterialStream2.C[1].VP[3], MaterialStream2.C[1].VP[4], MaterialStream2.C[1].VP[5], MaterialStream2.C[1].VP[6]}, 300.0)
 */
void Flowsheet_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[554], (modelica_real)data->simulationInfo->realParameter[555], (modelica_real)data->simulationInfo->realParameter[556], (modelica_real)data->simulationInfo->realParameter[557], (modelica_real)data->simulationInfo->realParameter[558], (modelica_real)data->simulationInfo->realParameter[559]);
  data->localData[0]->realVars[145] /* MaterialStream2._Pvap_c[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp1, 300.0);
  TRACE_POP
}

/*
 equation index: 19
 type: SIMPLE_ASSIGN
 MaterialStream2._K_c[1] = 9.869232667160129e-006 * MaterialStream2.Pvap_c[1]
 */
void Flowsheet_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[145] /* MaterialStream2._Pvap_c[1] variable */);
  TRACE_POP
}

/*
 equation index: 20
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[3,2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream2.C[2].SH, {MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tc, 300.0)
 */
void Flowsheet_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573], (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473], (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477]);
  data->localData[0]->realVars[133] /* MaterialStream2._H_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[537], tmp2, tmp3, data->simulationInfo->realParameter[547], 300.0);
  TRACE_POP
}

/*
 equation index: 21
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[2,2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream2.C[2].SH, {MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tc, 300.0)
 */
void Flowsheet_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573], (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473], (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477]);
  data->localData[0]->realVars[131] /* MaterialStream2._H_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[537], tmp4, tmp5, data->simulationInfo->realParameter[547], 300.0);
  TRACE_POP
}

/*
 equation index: 22
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[3,2] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, 300.0)
 */
void Flowsheet_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  real_array tmp6;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573], (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577]);
  data->localData[0]->realVars[103] /* MaterialStream2._Cp_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp6, 300.0);
  TRACE_POP
}

/*
 equation index: 23
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[2,2] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream2.C[2].LiqCp[1], MaterialStream2.C[2].LiqCp[2], MaterialStream2.C[2].LiqCp[3], MaterialStream2.C[2].LiqCp[4], MaterialStream2.C[2].LiqCp[5], MaterialStream2.C[2].LiqCp[6]}, 300.0)
 */
void Flowsheet_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[488], (modelica_real)data->simulationInfo->realParameter[489], (modelica_real)data->simulationInfo->realParameter[490], (modelica_real)data->simulationInfo->realParameter[491], (modelica_real)data->simulationInfo->realParameter[492], (modelica_real)data->simulationInfo->realParameter[493]);
  data->localData[0]->realVars[101] /* MaterialStream2._Cp_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp7, 300.0);
  TRACE_POP
}

/*
 equation index: 24
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[3,1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream2.C[1].SH, {MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tc, 300.0)
 */
void Flowsheet_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567], (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[466], (modelica_real)data->simulationInfo->realParameter[467], (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471]);
  data->localData[0]->realVars[132] /* MaterialStream2._H_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[536], tmp8, tmp9, data->simulationInfo->realParameter[546], 300.0);
  TRACE_POP
}

/*
 equation index: 25
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[2,1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream2.C[1].SH, {MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tc, 300.0)
 */
void Flowsheet_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  real_array tmp10;
  real_array tmp11;
  array_alloc_scalar_real_array(&tmp10, 6, (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567], (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571]);
  array_alloc_scalar_real_array(&tmp11, 6, (modelica_real)data->simulationInfo->realParameter[466], (modelica_real)data->simulationInfo->realParameter[467], (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471]);
  data->localData[0]->realVars[130] /* MaterialStream2._H_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[536], tmp10, tmp11, data->simulationInfo->realParameter[546], 300.0);
  TRACE_POP
}

/*
 equation index: 26
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[3,1] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, 300.0)
 */
void Flowsheet_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  real_array tmp12;
  array_alloc_scalar_real_array(&tmp12, 6, (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567], (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571]);
  data->localData[0]->realVars[102] /* MaterialStream2._Cp_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp12, 300.0);
  TRACE_POP
}

/*
 equation index: 27
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[2,1] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream2.C[1].LiqCp[1], MaterialStream2.C[1].LiqCp[2], MaterialStream2.C[1].LiqCp[3], MaterialStream2.C[1].LiqCp[4], MaterialStream2.C[1].LiqCp[5], MaterialStream2.C[1].LiqCp[6]}, 300.0)
 */
void Flowsheet_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  real_array tmp13;
  array_alloc_scalar_real_array(&tmp13, 6, (modelica_real)data->simulationInfo->realParameter[482], (modelica_real)data->simulationInfo->realParameter[483], (modelica_real)data->simulationInfo->realParameter[484], (modelica_real)data->simulationInfo->realParameter[485], (modelica_real)data->simulationInfo->realParameter[486], (modelica_real)data->simulationInfo->realParameter[487]);
  data->localData[0]->realVars[100] /* MaterialStream2._Cp_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp13, 300.0);
  TRACE_POP
}

/*
 equation index: 28
 type: SIMPLE_ASSIGN
 MaterialStream1._Pvap_c[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[2].VP[1], MaterialStream1.C[2].VP[2], MaterialStream1.C[2].VP[3], MaterialStream1.C[2].VP[4], MaterialStream1.C[2].VP[5], MaterialStream1.C[2].VP[6]}, 250.0)
 */
void Flowsheet_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  real_array tmp14;
  array_alloc_scalar_real_array(&tmp14, 6, (modelica_real)data->simulationInfo->realParameter[353], (modelica_real)data->simulationInfo->realParameter[354], (modelica_real)data->simulationInfo->realParameter[355], (modelica_real)data->simulationInfo->realParameter[356], (modelica_real)data->simulationInfo->realParameter[357], (modelica_real)data->simulationInfo->realParameter[358]);
  data->localData[0]->realVars[56] /* MaterialStream1._Pvap_c[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp14, 250.0);
  TRACE_POP
}

/*
 equation index: 29
 type: SIMPLE_ASSIGN
 MaterialStream1._K_c[2] = 9.869232667160129e-006 * MaterialStream1.Pvap_c[2]
 */
void Flowsheet_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[56] /* MaterialStream1._Pvap_c[2] variable */);
  TRACE_POP
}

/*
 equation index: 30
 type: SIMPLE_ASSIGN
 MaterialStream1._Pvap_c[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[1].VP[1], MaterialStream1.C[1].VP[2], MaterialStream1.C[1].VP[3], MaterialStream1.C[1].VP[4], MaterialStream1.C[1].VP[5], MaterialStream1.C[1].VP[6]}, 250.0)
 */
void Flowsheet_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  real_array tmp15;
  array_alloc_scalar_real_array(&tmp15, 6, (modelica_real)data->simulationInfo->realParameter[347], (modelica_real)data->simulationInfo->realParameter[348], (modelica_real)data->simulationInfo->realParameter[349], (modelica_real)data->simulationInfo->realParameter[350], (modelica_real)data->simulationInfo->realParameter[351], (modelica_real)data->simulationInfo->realParameter[352]);
  data->localData[0]->realVars[55] /* MaterialStream1._Pvap_c[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp15, 250.0);
  TRACE_POP
}

/*
 equation index: 31
 type: SIMPLE_ASSIGN
 MaterialStream1._K_c[1] = 9.869232667160129e-006 * MaterialStream1.Pvap_c[1]
 */
void Flowsheet_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[55] /* MaterialStream1._Pvap_c[1] variable */);
  TRACE_POP
}

/*
 equation index: 32
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[3,2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream1.C[2].SH, {MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tc, 250.0)
 */
void Flowsheet_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  real_array tmp16;
  real_array tmp17;
  array_alloc_scalar_real_array(&tmp16, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  array_alloc_scalar_real_array(&tmp17, 6, (modelica_real)data->simulationInfo->realParameter[265], (modelica_real)data->simulationInfo->realParameter[266], (modelica_real)data->simulationInfo->realParameter[267], (modelica_real)data->simulationInfo->realParameter[268], (modelica_real)data->simulationInfo->realParameter[269], (modelica_real)data->simulationInfo->realParameter[270]);
  data->localData[0]->realVars[43] /* MaterialStream1._H_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[330], tmp16, tmp17, data->simulationInfo->realParameter[340], 250.0);
  TRACE_POP
}

/*
 equation index: 33
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[2,2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream1.C[2].SH, {MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tc, 250.0)
 */
void Flowsheet_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  real_array tmp18;
  real_array tmp19;
  array_alloc_scalar_real_array(&tmp18, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  array_alloc_scalar_real_array(&tmp19, 6, (modelica_real)data->simulationInfo->realParameter[265], (modelica_real)data->simulationInfo->realParameter[266], (modelica_real)data->simulationInfo->realParameter[267], (modelica_real)data->simulationInfo->realParameter[268], (modelica_real)data->simulationInfo->realParameter[269], (modelica_real)data->simulationInfo->realParameter[270]);
  data->localData[0]->realVars[41] /* MaterialStream1._H_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[330], tmp18, tmp19, data->simulationInfo->realParameter[340], 250.0);
  TRACE_POP
}

/*
 equation index: 34
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[3,2] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, 250.0)
 */
void Flowsheet_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  real_array tmp20;
  array_alloc_scalar_real_array(&tmp20, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  data->localData[0]->realVars[13] /* MaterialStream1._Cp_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp20, 250.0);
  TRACE_POP
}

/*
 equation index: 35
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[2,2] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream1.C[2].LiqCp[1], MaterialStream1.C[2].LiqCp[2], MaterialStream1.C[2].LiqCp[3], MaterialStream1.C[2].LiqCp[4], MaterialStream1.C[2].LiqCp[5], MaterialStream1.C[2].LiqCp[6]}, 250.0)
 */
void Flowsheet_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  real_array tmp21;
  array_alloc_scalar_real_array(&tmp21, 6, (modelica_real)data->simulationInfo->realParameter[281], (modelica_real)data->simulationInfo->realParameter[282], (modelica_real)data->simulationInfo->realParameter[283], (modelica_real)data->simulationInfo->realParameter[284], (modelica_real)data->simulationInfo->realParameter[285], (modelica_real)data->simulationInfo->realParameter[286]);
  data->localData[0]->realVars[11] /* MaterialStream1._Cp_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp21, 250.0);
  TRACE_POP
}

/*
 equation index: 36
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[3,1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream1.C[1].SH, {MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tc, 250.0)
 */
void Flowsheet_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  real_array tmp22;
  real_array tmp23;
  array_alloc_scalar_real_array(&tmp22, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  array_alloc_scalar_real_array(&tmp23, 6, (modelica_real)data->simulationInfo->realParameter[259], (modelica_real)data->simulationInfo->realParameter[260], (modelica_real)data->simulationInfo->realParameter[261], (modelica_real)data->simulationInfo->realParameter[262], (modelica_real)data->simulationInfo->realParameter[263], (modelica_real)data->simulationInfo->realParameter[264]);
  data->localData[0]->realVars[42] /* MaterialStream1._H_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[329], tmp22, tmp23, data->simulationInfo->realParameter[339], 250.0);
  TRACE_POP
}

/*
 equation index: 37
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[2,1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream1.C[1].SH, {MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tc, 250.0)
 */
void Flowsheet_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  real_array tmp24;
  real_array tmp25;
  array_alloc_scalar_real_array(&tmp24, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  array_alloc_scalar_real_array(&tmp25, 6, (modelica_real)data->simulationInfo->realParameter[259], (modelica_real)data->simulationInfo->realParameter[260], (modelica_real)data->simulationInfo->realParameter[261], (modelica_real)data->simulationInfo->realParameter[262], (modelica_real)data->simulationInfo->realParameter[263], (modelica_real)data->simulationInfo->realParameter[264]);
  data->localData[0]->realVars[40] /* MaterialStream1._H_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[329], tmp24, tmp25, data->simulationInfo->realParameter[339], 250.0);
  TRACE_POP
}

/*
 equation index: 38
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[3,1] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, 250.0)
 */
void Flowsheet_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  real_array tmp26;
  array_alloc_scalar_real_array(&tmp26, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  data->localData[0]->realVars[12] /* MaterialStream1._Cp_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp26, 250.0);
  TRACE_POP
}

/*
 equation index: 39
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[2,1] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream1.C[1].LiqCp[1], MaterialStream1.C[1].LiqCp[2], MaterialStream1.C[1].LiqCp[3], MaterialStream1.C[1].LiqCp[4], MaterialStream1.C[1].LiqCp[5], MaterialStream1.C[1].LiqCp[6]}, 250.0)
 */
void Flowsheet_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  real_array tmp27;
  array_alloc_scalar_real_array(&tmp27, 6, (modelica_real)data->simulationInfo->realParameter[275], (modelica_real)data->simulationInfo->realParameter[276], (modelica_real)data->simulationInfo->realParameter[277], (modelica_real)data->simulationInfo->realParameter[278], (modelica_real)data->simulationInfo->realParameter[279], (modelica_real)data->simulationInfo->realParameter[280]);
  data->localData[0]->realVars[10] /* MaterialStream1._Cp_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp27, 250.0);
  TRACE_POP
}

/*
 equation index: 40
 type: SIMPLE_ASSIGN
 MaterialStream3._xguess[2] = 0.5
 */
void Flowsheet_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  data->simulationInfo->realParameter[849] = 0.5;
  TRACE_POP
}

/*
 equation index: 41
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xm_pc[1,2] = MaterialStream3.xguess[2]
 */
void Flowsheet_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  data->modelData->realVarsData[268].attribute /* MaterialStream3._xm_pc[1,2] variable */.start = data->simulationInfo->realParameter[849];
    data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */ = data->modelData->realVarsData[268].attribute /* MaterialStream3._xm_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[268].info /* MaterialStream3._xm_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 42
 type: SIMPLE_ASSIGN
 MaterialStream3._xguess[1] = 0.5
 */
void Flowsheet_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  data->simulationInfo->realParameter[848] = 0.5;
  TRACE_POP
}

void Flowsheet_eqFunction_43(DATA*,threadData_t*);
void Flowsheet_eqFunction_44(DATA*,threadData_t*);
void Flowsheet_eqFunction_45(DATA*,threadData_t*);
/*
 equation index: 46
 indexNonlinear: 0
 type: NONLINEAR
 
 vars: {MaterialStream3._Tdg}
 eqns: {43, 44, 45}
 */
void Flowsheet_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 46 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = data->simulationInfo->realParameter[843];
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,46};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 46 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[843] = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  TRACE_POP
}

void Flowsheet_eqFunction_47(DATA*,threadData_t*);
void Flowsheet_eqFunction_48(DATA*,threadData_t*);
void Flowsheet_eqFunction_49(DATA*,threadData_t*);
/*
 equation index: 50
 indexNonlinear: 1
 type: NONLINEAR
 
 vars: {MaterialStream3._Tbg}
 eqns: {47, 48, 49}
 */
void Flowsheet_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 50 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = data->simulationInfo->realParameter[840];
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,50};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 50 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[840] = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  TRACE_POP
}

/*
 equation index: 51
 type: SIMPLE_ASSIGN
 MaterialStream3._Temp = 0.5 * (MaterialStream3.Tbg + MaterialStream3.Tdg)
 */
void Flowsheet_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  data->simulationInfo->realParameter[844] = (0.5) * (data->simulationInfo->realParameter[840] + data->simulationInfo->realParameter[843]);
  TRACE_POP
}

/*
 equation index: 52
 type: SIMPLE_ASSIGN
 MaterialStream3._Psatt[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[1].VP[1], MaterialStream3.C[1].VP[2], MaterialStream3.C[1].VP[3], MaterialStream3.C[1].VP[4], MaterialStream3.C[1].VP[5], MaterialStream3.C[1].VP[6]}, MaterialStream3.Temp)
 */
void Flowsheet_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[761], (modelica_real)data->simulationInfo->realParameter[762], (modelica_real)data->simulationInfo->realParameter[763], (modelica_real)data->simulationInfo->realParameter[764], (modelica_real)data->simulationInfo->realParameter[765], (modelica_real)data->simulationInfo->realParameter[766]);
  data->simulationInfo->realParameter[833] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[844]);
  TRACE_POP
}

/*
 equation index: 53
 type: SIMPLE_ASSIGN
 MaterialStream3._K_guess[1] = DIVISION(MaterialStream3.Psatt[1], MaterialStream3.Pg)
 */
void Flowsheet_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
  data->simulationInfo->realParameter[824] = DIVISION_SIM(data->simulationInfo->realParameter[833],data->simulationInfo->realParameter[826],"MaterialStream3.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 54
 type: SIMPLE_ASSIGN
 MaterialStream3._Psatt[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[2].VP[1], MaterialStream3.C[2].VP[2], MaterialStream3.C[2].VP[3], MaterialStream3.C[2].VP[4], MaterialStream3.C[2].VP[5], MaterialStream3.C[2].VP[6]}, MaterialStream3.Temp)
 */
void Flowsheet_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[767], (modelica_real)data->simulationInfo->realParameter[768], (modelica_real)data->simulationInfo->realParameter[769], (modelica_real)data->simulationInfo->realParameter[770], (modelica_real)data->simulationInfo->realParameter[771], (modelica_real)data->simulationInfo->realParameter[772]);
  data->simulationInfo->realParameter[834] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp1, data->simulationInfo->realParameter[844]);
  TRACE_POP
}

/*
 equation index: 55
 type: SIMPLE_ASSIGN
 MaterialStream3._K_guess[2] = DIVISION(MaterialStream3.Psatt[2], MaterialStream3.Pg)
 */
void Flowsheet_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
  data->simulationInfo->realParameter[825] = DIVISION_SIM(data->simulationInfo->realParameter[834],data->simulationInfo->realParameter[826],"MaterialStream3.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 56
 type: SIMPLE_ASSIGN
 MaterialStream3._Pxc[2] = DIVISION(MaterialStream3.xguess[2], MaterialStream3.Psatt[2])
 */
void Flowsheet_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
  data->simulationInfo->realParameter[837] = DIVISION_SIM(data->simulationInfo->realParameter[849],data->simulationInfo->realParameter[834],"MaterialStream3.Psatt[2]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 57
 type: SIMPLE_ASSIGN
 MaterialStream3._Pxm[2] = MaterialStream3.xguess[2] * MaterialStream3.Psatt[2]
 */
void Flowsheet_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  data->simulationInfo->realParameter[839] = (data->simulationInfo->realParameter[849]) * (data->simulationInfo->realParameter[834]);
  TRACE_POP
}

/*
 equation index: 58
 type: SIMPLE_ASSIGN
 MaterialStream3._Tg = MaterialStream3.Temp
 */
void Flowsheet_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  data->simulationInfo->realParameter[845] = data->simulationInfo->realParameter[844];
  TRACE_POP
}

/*
 equation index: 59
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._T = MaterialStream3.Tg
 */
void Flowsheet_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  data->modelData->realVarsData[249].attribute /* MaterialStream3._T variable */.start = data->simulationInfo->realParameter[845];
    data->localData[0]->realVars[249] /* MaterialStream3._T variable */ = data->modelData->realVarsData[249].attribute /* MaterialStream3._T variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[249].info /* MaterialStream3._T */.name, (modelica_real) data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}

/*
 equation index: 60
 type: SIMPLE_ASSIGN
 MaterialStream3._Hcomplg[1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream3.C[1].SH, {MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, {MaterialStream3.C[1].HOV[1], MaterialStream3.C[1].HOV[2], MaterialStream3.C[1].HOV[3], MaterialStream3.C[1].HOV[4], MaterialStream3.C[1].HOV[5], MaterialStream3.C[1].HOV[6]}, MaterialStream3.C[1].Tc, MaterialStream3.Temp)
 */
void Flowsheet_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[673], (modelica_real)data->simulationInfo->realParameter[674], (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678]);
  data->simulationInfo->realParameter[816] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[743], tmp2, tmp3, data->simulationInfo->realParameter[753], data->simulationInfo->realParameter[844]);
  TRACE_POP
}

/*
 equation index: 61
 type: SIMPLE_ASSIGN
 MaterialStream3._Hcompvg[1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream3.C[1].SH, {MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, {MaterialStream3.C[1].HOV[1], MaterialStream3.C[1].HOV[2], MaterialStream3.C[1].HOV[3], MaterialStream3.C[1].HOV[4], MaterialStream3.C[1].HOV[5], MaterialStream3.C[1].HOV[6]}, MaterialStream3.C[1].Tc, MaterialStream3.Temp)
 */
void Flowsheet_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[673], (modelica_real)data->simulationInfo->realParameter[674], (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678]);
  data->simulationInfo->realParameter[818] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[743], tmp4, tmp5, data->simulationInfo->realParameter[753], data->simulationInfo->realParameter[844]);
  TRACE_POP
}

/*
 equation index: 62
 type: SIMPLE_ASSIGN
 MaterialStream3._Hcomplg[2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream3.C[2].SH, {MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, {MaterialStream3.C[2].HOV[1], MaterialStream3.C[2].HOV[2], MaterialStream3.C[2].HOV[3], MaterialStream3.C[2].HOV[4], MaterialStream3.C[2].HOV[5], MaterialStream3.C[2].HOV[6]}, MaterialStream3.C[2].Tc, MaterialStream3.Temp)
 */
void Flowsheet_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680], (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684]);
  data->simulationInfo->realParameter[817] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[744], tmp6, tmp7, data->simulationInfo->realParameter[754], data->simulationInfo->realParameter[844]);
  TRACE_POP
}

/*
 equation index: 63
 type: SIMPLE_ASSIGN
 MaterialStream3._Hcompvg[2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream3.C[2].SH, {MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, {MaterialStream3.C[2].HOV[1], MaterialStream3.C[2].HOV[2], MaterialStream3.C[2].HOV[3], MaterialStream3.C[2].HOV[4], MaterialStream3.C[2].HOV[5], MaterialStream3.C[2].HOV[6]}, MaterialStream3.C[2].Tc, MaterialStream3.Temp)
 */
void Flowsheet_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680], (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684]);
  data->simulationInfo->realParameter[819] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[744], tmp8, tmp9, data->simulationInfo->realParameter[754], data->simulationInfo->realParameter[844]);
  TRACE_POP
}

/*
 equation index: 64
 type: SIMPLE_ASSIGN
 MaterialStream3._Pxc[1] = DIVISION(MaterialStream3.xguess[1], MaterialStream3.Psatt[1])
 */
void Flowsheet_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  data->simulationInfo->realParameter[836] = DIVISION_SIM(data->simulationInfo->realParameter[848],data->simulationInfo->realParameter[833],"MaterialStream3.Psatt[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 65
 type: SIMPLE_ASSIGN
 MaterialStream3._Px = MaterialStream3.Pxc[1] + MaterialStream3.Pxc[2]
 */
void Flowsheet_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  data->simulationInfo->realParameter[835] = data->simulationInfo->realParameter[836] + data->simulationInfo->realParameter[837];
  TRACE_POP
}

/*
 equation index: 66
 type: SIMPLE_ASSIGN
 MaterialStream3._Pmin = DIVISION(1.0, MaterialStream3.Px)
 */
void Flowsheet_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  data->simulationInfo->realParameter[828] = DIVISION_SIM(1.0,data->simulationInfo->realParameter[835],"MaterialStream3.Px",equationIndexes);
  TRACE_POP
}

/*
 equation index: 67
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._Pbubl = MaterialStream3.Pmin
 */
void Flowsheet_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
  data->modelData->realVarsData[233].attribute /* MaterialStream3._Pbubl variable */.start = data->simulationInfo->realParameter[828];
    data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */ = data->modelData->realVarsData[233].attribute /* MaterialStream3._Pbubl variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[233].info /* MaterialStream3._Pbubl */.name, (modelica_real) data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  TRACE_POP
}

/*
 equation index: 68
 type: SIMPLE_ASSIGN
 MaterialStream3._Pxm[1] = MaterialStream3.xguess[1] * MaterialStream3.Psatt[1]
 */
void Flowsheet_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  data->simulationInfo->realParameter[838] = (data->simulationInfo->realParameter[848]) * (data->simulationInfo->realParameter[833]);
  TRACE_POP
}

/*
 equation index: 69
 type: SIMPLE_ASSIGN
 MaterialStream3._Pmax = MaterialStream3.Pxm[1] + MaterialStream3.Pxm[2]
 */
void Flowsheet_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  data->simulationInfo->realParameter[827] = data->simulationInfo->realParameter[838] + data->simulationInfo->realParameter[839];
  TRACE_POP
}


/*
 equation index: 70
 type: SIMPLE_ASSIGN
 MaterialStream3._xvapg = 0.0
 */
void Flowsheet_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
  data->simulationInfo->realParameter[853] = 0.0;
  TRACE_POP
}
/*
 equation index: 71
 type: SIMPLE_ASSIGN
 MaterialStream3._xvapg = (MaterialStream3.Pg - MaterialStream3.Pmin) / (MaterialStream3.Pmax - MaterialStream3.Pmin)
 */
void Flowsheet_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  modelica_real tmp12;
  tmp12 = data->simulationInfo->realParameter[827] - data->simulationInfo->realParameter[828];
  if (tmp12 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(MaterialStream3.Pg - MaterialStream3.Pmin) / (MaterialStream3.Pmax - MaterialStream3.Pmin)");}
  data->simulationInfo->realParameter[853] = (data->simulationInfo->realParameter[826] - data->simulationInfo->realParameter[828]) / tmp12;
  TRACE_POP
}
/*
 equation index: 72
 type: SIMPLE_ASSIGN
 MaterialStream3._xvapg = 1.0
 */
void Flowsheet_eqFunction_72(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,72};
  data->simulationInfo->realParameter[853] = 1.0;
  TRACE_POP
}
/*
 equation index: 73
 type: IFEQUATION
 
 equation index: 70
 type: SIMPLE_ASSIGN
 MaterialStream3._xvapg = 0.0equation index: 71
 type: SIMPLE_ASSIGN
 MaterialStream3._xvapg = (MaterialStream3.Pg - MaterialStream3.Pmin) / (MaterialStream3.Pmax - MaterialStream3.Pmin)
 equation index: 72
 type: SIMPLE_ASSIGN
 MaterialStream3._xvapg = 1.0
 */
void Flowsheet_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  tmp10 = GreaterEq(data->simulationInfo->realParameter[826],data->simulationInfo->realParameter[827]);
  tmp11 = GreaterEq(data->simulationInfo->realParameter[826],data->simulationInfo->realParameter[828]);
  if(tmp10)
  {
    Flowsheet_eqFunction_70(data, threadData);
  }
  else if(tmp11)
  {
    Flowsheet_eqFunction_71(data, threadData);
  }else
  {
    Flowsheet_eqFunction_72(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 74
 type: SIMPLE_ASSIGN
 MaterialStream3._xliqg = 1.0 - MaterialStream3.xvapg
 */
void Flowsheet_eqFunction_74(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,74};
  data->simulationInfo->realParameter[850] = 1.0 - data->simulationInfo->realParameter[853];
  TRACE_POP
}

/*
 equation index: 75
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xmliq = MaterialStream3.xliqg
 */
void Flowsheet_eqFunction_75(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  data->modelData->realVarsData[273].attribute /* MaterialStream3._xmliq variable */.start = data->simulationInfo->realParameter[850];
    data->localData[0]->realVars[273] /* MaterialStream3._xmliq variable */ = data->modelData->realVarsData[273].attribute /* MaterialStream3._xmliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[273].info /* MaterialStream3._xmliq */.name, (modelica_real) data->localData[0]->realVars[273] /* MaterialStream3._xmliq variable */);
  TRACE_POP
}

/*
 equation index: 76
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xliq = MaterialStream3.xliqg
 */
void Flowsheet_eqFunction_76(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
  data->modelData->realVarsData[266].attribute /* MaterialStream3._xliq variable */.start = data->simulationInfo->realParameter[850];
    data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */ = data->modelData->realVarsData[266].attribute /* MaterialStream3._xliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[266].info /* MaterialStream3._xliq */.name, (modelica_real) data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */);
  TRACE_POP
}


/*
 equation index: 77
 type: SIMPLE_ASSIGN
 MaterialStream3._Beta = 1.0
 */
void Flowsheet_eqFunction_77(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
  data->simulationInfo->realParameter[652] = 1.0;
  TRACE_POP
}
/*
 equation index: 78
 type: SIMPLE_ASSIGN
 MaterialStream3._Beta = 0.0
 */
void Flowsheet_eqFunction_78(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  data->simulationInfo->realParameter[652] = 0.0;
  TRACE_POP
}
/*
 equation index: 79
 type: SIMPLE_ASSIGN
 MaterialStream3._Beta = MaterialStream3.xvapg
 */
void Flowsheet_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  data->simulationInfo->realParameter[652] = data->simulationInfo->realParameter[853];
  TRACE_POP
}
/*
 equation index: 80
 type: IFEQUATION
 
 equation index: 77
 type: SIMPLE_ASSIGN
 MaterialStream3._Beta = 1.0equation index: 78
 type: SIMPLE_ASSIGN
 MaterialStream3._Beta = 0.0
 equation index: 79
 type: SIMPLE_ASSIGN
 MaterialStream3._Beta = MaterialStream3.xvapg
 */
void Flowsheet_eqFunction_80(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  tmp13 = Greater(data->simulationInfo->realParameter[853],1.0);
  tmp14 = Less(data->simulationInfo->realParameter[853],0.0);
  if(tmp13)
  {
    Flowsheet_eqFunction_77(data, threadData);
  }
  else if(tmp14)
  {
    Flowsheet_eqFunction_78(data, threadData);
  }else
  {
    Flowsheet_eqFunction_79(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 81
 type: SIMPLE_ASSIGN
 MaterialStream3._Alpha = 1.0 - MaterialStream3.Beta
 */
void Flowsheet_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  data->simulationInfo->realParameter[651] = 1.0 - data->simulationInfo->realParameter[652];
  TRACE_POP
}



/*
 equation index: 82
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = MaterialStream3.xguess[1] * MaterialStream3.K_guess[1] / (1.0 + (-1.0 + MaterialStream3.K_guess[1]) * MaterialStream3.xvapg)
 */
void Flowsheet_eqFunction_82(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
  modelica_real tmp18;
  tmp18 = 1.0 + (-1.0 + data->simulationInfo->realParameter[824]) * (data->simulationInfo->realParameter[853]);
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream3.K_guess[1] / (1.0 + (-1.0 + MaterialStream3.K_guess[1]) * MaterialStream3.xvapg)");}
  data->simulationInfo->realParameter[856] = (data->simulationInfo->realParameter[848]) * ((data->simulationInfo->realParameter[824]) / tmp18);
  TRACE_POP
}
/*
 equation index: 83
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = MaterialStream3.xguess[1]
 */
void Flowsheet_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  data->simulationInfo->realParameter[856] = data->simulationInfo->realParameter[848];
  TRACE_POP
}
/*
 equation index: 84
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  data->simulationInfo->realParameter[856] = 0.0;
  TRACE_POP
}
/*
 equation index: 85
 type: IFEQUATION
 
 equation index: 82
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = MaterialStream3.xguess[1] * MaterialStream3.K_guess[1] / (1.0 + (-1.0 + MaterialStream3.K_guess[1]) * MaterialStream3.xvapg)equation index: 83
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = MaterialStream3.xguess[1]
 equation index: 84
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_85(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
  modelica_boolean tmp16;
  tmp16 = Greater(data->simulationInfo->realParameter[652],0.0);
  if((tmp16 && (data->simulationInfo->realParameter[652] != 1.0)))
  {
    Flowsheet_eqFunction_82(data, threadData);
  }
  else if((data->simulationInfo->realParameter[652] == 1.0))
  {
    Flowsheet_eqFunction_83(data, threadData);
  }else
  {
    Flowsheet_eqFunction_84(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 86
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = MaterialStream3.ymol[1] / MaterialStream3.K_guess[1]
 */
void Flowsheet_eqFunction_86(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,86};
  modelica_real tmp22;
  tmp22 = data->simulationInfo->realParameter[824];
  if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream3.ymol[1] / MaterialStream3.K_guess[1]");}
  data->simulationInfo->realParameter[851] = (data->simulationInfo->realParameter[856]) / tmp22;
  TRACE_POP
}
/*
 equation index: 87
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = MaterialStream3.xguess[1]
 */
void Flowsheet_eqFunction_87(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
  data->simulationInfo->realParameter[851] = data->simulationInfo->realParameter[848];
  TRACE_POP
}
/*
 equation index: 88
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  data->simulationInfo->realParameter[851] = 0.0;
  TRACE_POP
}
/*
 equation index: 89
 type: IFEQUATION
 
 equation index: 86
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = MaterialStream3.ymol[1] / MaterialStream3.K_guess[1]equation index: 87
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = MaterialStream3.xguess[1]
 equation index: 88
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  tmp20 = Greater(data->simulationInfo->realParameter[652],0.0);
  tmp21 = Less(data->simulationInfo->realParameter[652],1.0);
  if((tmp20 && tmp21))
  {
    Flowsheet_eqFunction_86(data, threadData);
  }
  else if((data->simulationInfo->realParameter[652] == 0.0))
  {
    Flowsheet_eqFunction_87(data, threadData);
  }else
  {
    Flowsheet_eqFunction_88(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 90
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  data->simulationInfo->realParameter[851] = 0.0;
  TRACE_POP
}

/*
 equation index: 91
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_91(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
  data->simulationInfo->realParameter[856] = 0.0;
  TRACE_POP
}
/*
 equation index: 92
 type: IFEQUATION
 
 equation index: 85
 type: IFEQUATION
 
 equation index: 82
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = MaterialStream3.xguess[1] * MaterialStream3.K_guess[1] / (1.0 + (-1.0 + MaterialStream3.K_guess[1]) * MaterialStream3.xvapg)equation index: 83
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = MaterialStream3.xguess[1]
 equation index: 84
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = 0.0equation index: 89
 type: IFEQUATION
 
 equation index: 86
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = MaterialStream3.ymol[1] / MaterialStream3.K_guess[1]equation index: 87
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = MaterialStream3.xguess[1]
 equation index: 88
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = 0.0
 equation index: 90
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[1] = 0.0equation index: 91
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  if((data->simulationInfo->realParameter[848] != 0.0))
  {
    Flowsheet_eqFunction_85(data, threadData);

    Flowsheet_eqFunction_89(data, threadData);
  }else
  {
    Flowsheet_eqFunction_90(data, threadData);
    Flowsheet_eqFunction_91(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 93
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[1] = 0.0
 */
void Flowsheet_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
  data->simulationInfo->realParameter[846] = 0.0;
  TRACE_POP
}
/*
 equation index: 94
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[1] = 1.0
 */
void Flowsheet_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
  data->simulationInfo->realParameter[846] = 1.0;
  TRACE_POP
}
/*
 equation index: 95
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[1] = MaterialStream3.xmol[1]
 */
void Flowsheet_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,95};
  data->simulationInfo->realParameter[846] = data->simulationInfo->realParameter[851];
  TRACE_POP
}
/*
 equation index: 96
 type: IFEQUATION
 
 equation index: 93
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[1] = 0.0equation index: 94
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[1] = 1.0
 equation index: 95
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[1] = MaterialStream3.xmol[1]
 */
void Flowsheet_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  tmp24 = Less(data->simulationInfo->realParameter[851],0.0);
  tmp25 = Greater(data->simulationInfo->realParameter[846],1.0);
  if(tmp24)
  {
    Flowsheet_eqFunction_93(data, threadData);
  }
  else if(tmp25)
  {
    Flowsheet_eqFunction_94(data, threadData);
  }else
  {
    Flowsheet_eqFunction_95(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 97
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xm_pc[2,1] = MaterialStream3.xg[1]
 */
void Flowsheet_eqFunction_97(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,97};
  data->modelData->realVarsData[269].attribute /* MaterialStream3._xm_pc[2,1] variable */.start = data->simulationInfo->realParameter[846];
    data->localData[0]->realVars[269] /* MaterialStream3._xm_pc[2,1] variable */ = data->modelData->realVarsData[269].attribute /* MaterialStream3._xm_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[269].info /* MaterialStream3._xm_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[269] /* MaterialStream3._xm_pc[2,1] variable */);
  TRACE_POP
}

/*
 equation index: 98
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._x_pc[2,1] = MaterialStream3.xg[1]
 */
void Flowsheet_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
  data->modelData->realVarsData[262].attribute /* MaterialStream3._x_pc[2,1] variable */.start = data->simulationInfo->realParameter[846];
    data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */ = data->modelData->realVarsData[262].attribute /* MaterialStream3._x_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[262].info /* MaterialStream3._x_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */);
  TRACE_POP
}


/*
 equation index: 99
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[1] = 0.0
 */
void Flowsheet_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
  data->simulationInfo->realParameter[854] = 0.0;
  TRACE_POP
}
/*
 equation index: 100
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[1] = 1.0
 */
void Flowsheet_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  data->simulationInfo->realParameter[854] = 1.0;
  TRACE_POP
}
/*
 equation index: 101
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[1] = MaterialStream3.ymol[1]
 */
void Flowsheet_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  data->simulationInfo->realParameter[854] = data->simulationInfo->realParameter[856];
  TRACE_POP
}
/*
 equation index: 102
 type: IFEQUATION
 
 equation index: 99
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[1] = 0.0equation index: 100
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[1] = 1.0
 equation index: 101
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[1] = MaterialStream3.ymol[1]
 */
void Flowsheet_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  tmp26 = Less(data->simulationInfo->realParameter[856],0.0);
  tmp27 = Greater(data->simulationInfo->realParameter[856],1.0);
  if(tmp26)
  {
    Flowsheet_eqFunction_99(data, threadData);
  }
  else if(tmp27)
  {
    Flowsheet_eqFunction_100(data, threadData);
  }else
  {
    Flowsheet_eqFunction_101(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 106
 type: LINEAR
 
 <var>MaterialStream3._Fvapg</var>
 <row>

 </row>
 <matrix>
 </matrix>
 */
void Flowsheet_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 106 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[0].x[0] = data->simulationInfo->realParameter[813];
  retValue = solve_linear_system(data, threadData, 0);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,106};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 106 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[813] = data->simulationInfo->linearSystemData[0].x[0];
  TRACE_POP
}

/*
 equation index: 107
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._F_p[2] = MaterialStream3.Fliqg
 */
void Flowsheet_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
  data->modelData->realVarsData[198].attribute /* MaterialStream3._F_p[2] variable */.start = data->simulationInfo->realParameter[812];
    data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */ = data->modelData->realVarsData[198].attribute /* MaterialStream3._F_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[198].info /* MaterialStream3._F_p[2] */.name, (modelica_real) data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 108
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._F_p[3] = MaterialStream3.Fvapg
 */
void Flowsheet_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
  data->modelData->realVarsData[199].attribute /* MaterialStream3._F_p[3] variable */.start = data->simulationInfo->realParameter[813];
    data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */ = data->modelData->realVarsData[199].attribute /* MaterialStream3._F_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[199].info /* MaterialStream3._F_p[3] */.name, (modelica_real) data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 109
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xm_pc[3,1] = MaterialStream3.yg[1]
 */
void Flowsheet_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
  data->modelData->realVarsData[271].attribute /* MaterialStream3._xm_pc[3,1] variable */.start = data->simulationInfo->realParameter[854];
    data->localData[0]->realVars[271] /* MaterialStream3._xm_pc[3,1] variable */ = data->modelData->realVarsData[271].attribute /* MaterialStream3._xm_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[271].info /* MaterialStream3._xm_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[271] /* MaterialStream3._xm_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 110
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._x_pc[3,1] = MaterialStream3.yg[1]
 */
void Flowsheet_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
  data->modelData->realVarsData[264].attribute /* MaterialStream3._x_pc[3,1] variable */.start = data->simulationInfo->realParameter[854];
    data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ = data->modelData->realVarsData[264].attribute /* MaterialStream3._x_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[264].info /* MaterialStream3._x_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */);
  TRACE_POP
}



/*
 equation index: 111
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = MaterialStream3.xguess[2] * MaterialStream3.K_guess[2] / (1.0 + (-1.0 + MaterialStream3.K_guess[2]) * MaterialStream3.xvapg)
 */
void Flowsheet_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  modelica_real tmp31;
  tmp31 = 1.0 + (-1.0 + data->simulationInfo->realParameter[825]) * (data->simulationInfo->realParameter[853]);
  if (tmp31 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream3.K_guess[2] / (1.0 + (-1.0 + MaterialStream3.K_guess[2]) * MaterialStream3.xvapg)");}
  data->simulationInfo->realParameter[857] = (data->simulationInfo->realParameter[849]) * ((data->simulationInfo->realParameter[825]) / tmp31);
  TRACE_POP
}
/*
 equation index: 112
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = MaterialStream3.xguess[2]
 */
void Flowsheet_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
  data->simulationInfo->realParameter[857] = data->simulationInfo->realParameter[849];
  TRACE_POP
}
/*
 equation index: 113
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
  data->simulationInfo->realParameter[857] = 0.0;
  TRACE_POP
}
/*
 equation index: 114
 type: IFEQUATION
 
 equation index: 111
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = MaterialStream3.xguess[2] * MaterialStream3.K_guess[2] / (1.0 + (-1.0 + MaterialStream3.K_guess[2]) * MaterialStream3.xvapg)equation index: 112
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = MaterialStream3.xguess[2]
 equation index: 113
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
  modelica_boolean tmp29;
  tmp29 = Greater(data->simulationInfo->realParameter[652],0.0);
  if((tmp29 && (data->simulationInfo->realParameter[652] != 1.0)))
  {
    Flowsheet_eqFunction_111(data, threadData);
  }
  else if((data->simulationInfo->realParameter[652] == 1.0))
  {
    Flowsheet_eqFunction_112(data, threadData);
  }else
  {
    Flowsheet_eqFunction_113(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 115
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = MaterialStream3.ymol[2] / MaterialStream3.K_guess[2]
 */
void Flowsheet_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  modelica_real tmp35;
  tmp35 = data->simulationInfo->realParameter[825];
  if (tmp35 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream3.ymol[2] / MaterialStream3.K_guess[2]");}
  data->simulationInfo->realParameter[852] = (data->simulationInfo->realParameter[857]) / tmp35;
  TRACE_POP
}
/*
 equation index: 116
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = MaterialStream3.xguess[2]
 */
void Flowsheet_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
  data->simulationInfo->realParameter[852] = data->simulationInfo->realParameter[849];
  TRACE_POP
}
/*
 equation index: 117
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
  data->simulationInfo->realParameter[852] = 0.0;
  TRACE_POP
}
/*
 equation index: 118
 type: IFEQUATION
 
 equation index: 115
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = MaterialStream3.ymol[2] / MaterialStream3.K_guess[2]equation index: 116
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = MaterialStream3.xguess[2]
 equation index: 117
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  tmp33 = Greater(data->simulationInfo->realParameter[652],0.0);
  tmp34 = Less(data->simulationInfo->realParameter[652],1.0);
  if((tmp33 && tmp34))
  {
    Flowsheet_eqFunction_115(data, threadData);
  }
  else if((data->simulationInfo->realParameter[652] == 0.0))
  {
    Flowsheet_eqFunction_116(data, threadData);
  }else
  {
    Flowsheet_eqFunction_117(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 119
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
  data->simulationInfo->realParameter[852] = 0.0;
  TRACE_POP
}

/*
 equation index: 120
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  data->simulationInfo->realParameter[857] = 0.0;
  TRACE_POP
}
/*
 equation index: 121
 type: IFEQUATION
 
 equation index: 114
 type: IFEQUATION
 
 equation index: 111
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = MaterialStream3.xguess[2] * MaterialStream3.K_guess[2] / (1.0 + (-1.0 + MaterialStream3.K_guess[2]) * MaterialStream3.xvapg)equation index: 112
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = MaterialStream3.xguess[2]
 equation index: 113
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = 0.0equation index: 118
 type: IFEQUATION
 
 equation index: 115
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = MaterialStream3.ymol[2] / MaterialStream3.K_guess[2]equation index: 116
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = MaterialStream3.xguess[2]
 equation index: 117
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = 0.0
 equation index: 119
 type: SIMPLE_ASSIGN
 MaterialStream3._xmol[2] = 0.0equation index: 120
 type: SIMPLE_ASSIGN
 MaterialStream3._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
  if((data->simulationInfo->realParameter[849] != 0.0))
  {
    Flowsheet_eqFunction_114(data, threadData);

    Flowsheet_eqFunction_118(data, threadData);
  }else
  {
    Flowsheet_eqFunction_119(data, threadData);
    Flowsheet_eqFunction_120(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 122
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[2] = 0.0
 */
void Flowsheet_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  data->simulationInfo->realParameter[847] = 0.0;
  TRACE_POP
}
/*
 equation index: 123
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[2] = 1.0
 */
void Flowsheet_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  data->simulationInfo->realParameter[847] = 1.0;
  TRACE_POP
}
/*
 equation index: 124
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[2] = MaterialStream3.xmol[2]
 */
void Flowsheet_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  data->simulationInfo->realParameter[847] = data->simulationInfo->realParameter[852];
  TRACE_POP
}
/*
 equation index: 125
 type: IFEQUATION
 
 equation index: 122
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[2] = 0.0equation index: 123
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[2] = 1.0
 equation index: 124
 type: SIMPLE_ASSIGN
 MaterialStream3._xg[2] = MaterialStream3.xmol[2]
 */
void Flowsheet_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  tmp37 = Less(data->simulationInfo->realParameter[852],0.0);
  tmp38 = Greater(data->simulationInfo->realParameter[847],1.0);
  if(tmp37)
  {
    Flowsheet_eqFunction_122(data, threadData);
  }
  else if(tmp38)
  {
    Flowsheet_eqFunction_123(data, threadData);
  }else
  {
    Flowsheet_eqFunction_124(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 126
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xm_pc[2,2] = MaterialStream3.xg[2]
 */
void Flowsheet_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
  data->modelData->realVarsData[270].attribute /* MaterialStream3._xm_pc[2,2] variable */.start = data->simulationInfo->realParameter[847];
    data->localData[0]->realVars[270] /* MaterialStream3._xm_pc[2,2] variable */ = data->modelData->realVarsData[270].attribute /* MaterialStream3._xm_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[270].info /* MaterialStream3._xm_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[270] /* MaterialStream3._xm_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 127
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._x_pc[2,2] = MaterialStream3.xg[2]
 */
void Flowsheet_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
  data->modelData->realVarsData[263].attribute /* MaterialStream3._x_pc[2,2] variable */.start = data->simulationInfo->realParameter[847];
    data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */ = data->modelData->realVarsData[263].attribute /* MaterialStream3._x_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[263].info /* MaterialStream3._x_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */);
  TRACE_POP
}


/*
 equation index: 128
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[2] = 0.0
 */
void Flowsheet_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
  data->simulationInfo->realParameter[855] = 0.0;
  TRACE_POP
}
/*
 equation index: 129
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[2] = 1.0
 */
void Flowsheet_eqFunction_129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,129};
  data->simulationInfo->realParameter[855] = 1.0;
  TRACE_POP
}
/*
 equation index: 130
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[2] = MaterialStream3.ymol[2]
 */
void Flowsheet_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
  data->simulationInfo->realParameter[855] = data->simulationInfo->realParameter[857];
  TRACE_POP
}
/*
 equation index: 131
 type: IFEQUATION
 
 equation index: 128
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[2] = 0.0equation index: 129
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[2] = 1.0
 equation index: 130
 type: SIMPLE_ASSIGN
 MaterialStream3._yg[2] = MaterialStream3.ymol[2]
 */
void Flowsheet_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  tmp39 = Less(data->simulationInfo->realParameter[857],0.0);
  tmp40 = Greater(data->simulationInfo->realParameter[857],1.0);
  if(tmp39)
  {
    Flowsheet_eqFunction_128(data, threadData);
  }
  else if(tmp40)
  {
    Flowsheet_eqFunction_129(data, threadData);
  }else
  {
    Flowsheet_eqFunction_130(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 132
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xm_pc[3,2] = MaterialStream3.yg[2]
 */
void Flowsheet_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
  data->modelData->realVarsData[272].attribute /* MaterialStream3._xm_pc[3,2] variable */.start = data->simulationInfo->realParameter[855];
    data->localData[0]->realVars[272] /* MaterialStream3._xm_pc[3,2] variable */ = data->modelData->realVarsData[272].attribute /* MaterialStream3._xm_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[272].info /* MaterialStream3._xm_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[272] /* MaterialStream3._xm_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 133
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._x_pc[3,2] = MaterialStream3.yg[2]
 */
void Flowsheet_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,133};
  data->modelData->realVarsData[265].attribute /* MaterialStream3._x_pc[3,2] variable */.start = data->simulationInfo->realParameter[855];
    data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ = data->modelData->realVarsData[265].attribute /* MaterialStream3._x_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[265].info /* MaterialStream3._x_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 134
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xmvap = MaterialStream3.xvapg
 */
void Flowsheet_eqFunction_134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,134};
  data->modelData->realVarsData[274].attribute /* MaterialStream3._xmvap variable */.start = data->simulationInfo->realParameter[853];
    data->localData[0]->realVars[274] /* MaterialStream3._xmvap variable */ = data->modelData->realVarsData[274].attribute /* MaterialStream3._xmvap variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[274].info /* MaterialStream3._xmvap */.name, (modelica_real) data->localData[0]->realVars[274] /* MaterialStream3._xmvap variable */);
  TRACE_POP
}

/*
 equation index: 135
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xvap = MaterialStream3.xvapg
 */
void Flowsheet_eqFunction_135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,135};
  data->modelData->realVarsData[275].attribute /* MaterialStream3._xvap variable */.start = data->simulationInfo->realParameter[853];
    data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */ = data->modelData->realVarsData[275].attribute /* MaterialStream3._xvap variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[275].info /* MaterialStream3._xvap */.name, (modelica_real) data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */);
  TRACE_POP
}

/*
 equation index: 136
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._Pdew = MaterialStream3.Pmax
 */
void Flowsheet_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
  data->modelData->realVarsData[234].attribute /* MaterialStream3._Pdew variable */.start = data->simulationInfo->realParameter[827];
    data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */ = data->modelData->realVarsData[234].attribute /* MaterialStream3._Pdew variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[234].info /* MaterialStream3._Pdew */.name, (modelica_real) data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
  TRACE_POP
}

/*
 equation index: 137
 type: SIMPLE_ASSIGN
 MaterialStream3._Hliqg = MaterialStream3.xguess[1] * MaterialStream3.Hcomplg[1] + MaterialStream3.xguess[2] * MaterialStream3.Hcomplg[2]
 */
void Flowsheet_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
  data->simulationInfo->realParameter[820] = (data->simulationInfo->realParameter[848]) * (data->simulationInfo->realParameter[816]) + (data->simulationInfo->realParameter[849]) * (data->simulationInfo->realParameter[817]);
  TRACE_POP
}

/*
 equation index: 138
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._H_p[2] = MaterialStream3.Hliqg
 */
void Flowsheet_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
  data->modelData->realVarsData[216].attribute /* MaterialStream3._H_p[2] variable */.start = data->simulationInfo->realParameter[820];
    data->localData[0]->realVars[216] /* MaterialStream3._H_p[2] variable */ = data->modelData->realVarsData[216].attribute /* MaterialStream3._H_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[216].info /* MaterialStream3._H_p[2] */.name, (modelica_real) data->localData[0]->realVars[216] /* MaterialStream3._H_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 139
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._Cp_p[2] = MaterialStream3.Hliqg
 */
void Flowsheet_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
  data->modelData->realVarsData[186].attribute /* MaterialStream3._Cp_p[2] variable */.start = data->simulationInfo->realParameter[820];
    data->localData[0]->realVars[186] /* MaterialStream3._Cp_p[2] variable */ = data->modelData->realVarsData[186].attribute /* MaterialStream3._Cp_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[186].info /* MaterialStream3._Cp_p[2] */.name, (modelica_real) data->localData[0]->realVars[186] /* MaterialStream3._Cp_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 140
 type: SIMPLE_ASSIGN
 MaterialStream3._Hvapg = MaterialStream3.xguess[1] * MaterialStream3.Hcompvg[1] + MaterialStream3.xguess[2] * MaterialStream3.Hcompvg[2]
 */
void Flowsheet_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  data->simulationInfo->realParameter[823] = (data->simulationInfo->realParameter[848]) * (data->simulationInfo->realParameter[818]) + (data->simulationInfo->realParameter[849]) * (data->simulationInfo->realParameter[819]);
  TRACE_POP
}

/*
 equation index: 141
 type: SIMPLE_ASSIGN
 MaterialStream3._Htotg = MaterialStream3.Hliqg + MaterialStream3.Hvapg
 */
void Flowsheet_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
  data->simulationInfo->realParameter[822] = data->simulationInfo->realParameter[820] + data->simulationInfo->realParameter[823];
  TRACE_POP
}

/*
 equation index: 142
 type: SIMPLE_ASSIGN
 MaterialStream3._Hmixg = MaterialStream3.Htotg
 */
void Flowsheet_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
  data->simulationInfo->realParameter[821] = data->simulationInfo->realParameter[822];
  TRACE_POP
}

/*
 equation index: 143
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._H_p[1] = MaterialStream3.Hmixg
 */
void Flowsheet_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
  data->modelData->realVarsData[215].attribute /* MaterialStream3._H_p[1] variable */.start = data->simulationInfo->realParameter[821];
    data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */ = data->modelData->realVarsData[215].attribute /* MaterialStream3._H_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[215].info /* MaterialStream3._H_p[1] */.name, (modelica_real) data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 144
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._Cp_p[1] = MaterialStream3.Hmixg
 */
void Flowsheet_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
  data->modelData->realVarsData[185].attribute /* MaterialStream3._Cp_p[1] variable */.start = data->simulationInfo->realParameter[821];
    data->localData[0]->realVars[185] /* MaterialStream3._Cp_p[1] variable */ = data->modelData->realVarsData[185].attribute /* MaterialStream3._Cp_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[185].info /* MaterialStream3._Cp_p[1] */.name, (modelica_real) data->localData[0]->realVars[185] /* MaterialStream3._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 145
 type: SIMPLE_ASSIGN
 MaterialStream3._Hcompg[1] = MaterialStream3.xguess[1] * MaterialStream3.Htotg
 */
void Flowsheet_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
  data->simulationInfo->realParameter[814] = (data->simulationInfo->realParameter[848]) * (data->simulationInfo->realParameter[822]);
  TRACE_POP
}

/*
 equation index: 146
 type: SIMPLE_ASSIGN
 MaterialStream3._Hcompg[2] = MaterialStream3.xguess[2] * MaterialStream3.Htotg
 */
void Flowsheet_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
  data->simulationInfo->realParameter[815] = (data->simulationInfo->realParameter[849]) * (data->simulationInfo->realParameter[822]);
  TRACE_POP
}

/*
 equation index: 147
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._H_p[3] = MaterialStream3.Hvapg
 */
void Flowsheet_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
  data->modelData->realVarsData[217].attribute /* MaterialStream3._H_p[3] variable */.start = data->simulationInfo->realParameter[823];
    data->localData[0]->realVars[217] /* MaterialStream3._H_p[3] variable */ = data->modelData->realVarsData[217].attribute /* MaterialStream3._H_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[217].info /* MaterialStream3._H_p[3] */.name, (modelica_real) data->localData[0]->realVars[217] /* MaterialStream3._H_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 148
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._Cp_p[3] = MaterialStream3.Hvapg
 */
void Flowsheet_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,148};
  data->modelData->realVarsData[187].attribute /* MaterialStream3._Cp_p[3] variable */.start = data->simulationInfo->realParameter[823];
    data->localData[0]->realVars[187] /* MaterialStream3._Cp_p[3] variable */ = data->modelData->realVarsData[187].attribute /* MaterialStream3._Cp_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[187].info /* MaterialStream3._Cp_p[3] */.name, (modelica_real) data->localData[0]->realVars[187] /* MaterialStream3._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 149
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._xm_pc[1,1] = MaterialStream3.xguess[1]
 */
void Flowsheet_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
  data->modelData->realVarsData[267].attribute /* MaterialStream3._xm_pc[1,1] variable */.start = data->simulationInfo->realParameter[848];
    data->localData[0]->realVars[267] /* MaterialStream3._xm_pc[1,1] variable */ = data->modelData->realVarsData[267].attribute /* MaterialStream3._xm_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[267].info /* MaterialStream3._xm_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[267] /* MaterialStream3._xm_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 150
 type: SIMPLE_ASSIGN
 Mixer1._xguess[2] = 0.5
 */
void Flowsheet_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
  data->simulationInfo->realParameter[1056] = 0.5;
  TRACE_POP
}

/*
 equation index: 151
 type: SIMPLE_ASSIGN
 Mixer1._xguess[1] = 0.5
 */
void Flowsheet_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
  data->simulationInfo->realParameter[1055] = 0.5;
  TRACE_POP
}

void Flowsheet_eqFunction_152(DATA*,threadData_t*);
void Flowsheet_eqFunction_153(DATA*,threadData_t*);
void Flowsheet_eqFunction_154(DATA*,threadData_t*);
/*
 equation index: 155
 indexNonlinear: 2
 type: NONLINEAR
 
 vars: {Mixer1._Tdg}
 eqns: {152, 153, 154}
 */
void Flowsheet_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 155 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[0] = data->simulationInfo->realParameter[1050];
  retValue = solve_nonlinear_system(data, threadData, 2);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,155};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 155 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[1050] = data->simulationInfo->nonlinearSystemData[2].nlsx[0];
  TRACE_POP
}

void Flowsheet_eqFunction_156(DATA*,threadData_t*);
void Flowsheet_eqFunction_157(DATA*,threadData_t*);
void Flowsheet_eqFunction_158(DATA*,threadData_t*);
/*
 equation index: 159
 indexNonlinear: 3
 type: NONLINEAR
 
 vars: {Mixer1._Tbg}
 eqns: {156, 157, 158}
 */
void Flowsheet_eqFunction_159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,159};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 159 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[0] = data->simulationInfo->realParameter[1047];
  retValue = solve_nonlinear_system(data, threadData, 3);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,159};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 159 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[1047] = data->simulationInfo->nonlinearSystemData[3].nlsx[0];
  TRACE_POP
}

/*
 equation index: 160
 type: SIMPLE_ASSIGN
 Mixer1._Temp = 0.5 * (Mixer1.Tbg + Mixer1.Tdg)
 */
void Flowsheet_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
  data->simulationInfo->realParameter[1051] = (0.5) * (data->simulationInfo->realParameter[1047] + data->simulationInfo->realParameter[1050]);
  TRACE_POP
}

/*
 equation index: 161
 type: SIMPLE_ASSIGN
 Mixer1._Psatt[1] = Simulator.Files.ThermodynamicFunctions.Psat({Mixer1.C[1].VP[1], Mixer1.C[1].VP[2], Mixer1.C[1].VP[3], Mixer1.C[1].VP[4], Mixer1.C[1].VP[5], Mixer1.C[1].VP[6]}, Mixer1.Temp)
 */
void Flowsheet_eqFunction_161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,161};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[968], (modelica_real)data->simulationInfo->realParameter[969], (modelica_real)data->simulationInfo->realParameter[970], (modelica_real)data->simulationInfo->realParameter[971], (modelica_real)data->simulationInfo->realParameter[972], (modelica_real)data->simulationInfo->realParameter[973]);
  data->simulationInfo->realParameter[1040] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[1051]);
  TRACE_POP
}

/*
 equation index: 162
 type: SIMPLE_ASSIGN
 Mixer1._K_guess[1] = DIVISION(Mixer1.Psatt[1], Mixer1.Pg)
 */
void Flowsheet_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
  data->simulationInfo->realParameter[1031] = DIVISION_SIM(data->simulationInfo->realParameter[1040],data->simulationInfo->realParameter[1033],"Mixer1.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 163
 type: SIMPLE_ASSIGN
 Mixer1._Psatt[2] = Simulator.Files.ThermodynamicFunctions.Psat({Mixer1.C[2].VP[1], Mixer1.C[2].VP[2], Mixer1.C[2].VP[3], Mixer1.C[2].VP[4], Mixer1.C[2].VP[5], Mixer1.C[2].VP[6]}, Mixer1.Temp)
 */
void Flowsheet_eqFunction_163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,163};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[974], (modelica_real)data->simulationInfo->realParameter[975], (modelica_real)data->simulationInfo->realParameter[976], (modelica_real)data->simulationInfo->realParameter[977], (modelica_real)data->simulationInfo->realParameter[978], (modelica_real)data->simulationInfo->realParameter[979]);
  data->simulationInfo->realParameter[1041] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp1, data->simulationInfo->realParameter[1051]);
  TRACE_POP
}

/*
 equation index: 164
 type: SIMPLE_ASSIGN
 Mixer1._K_guess[2] = DIVISION(Mixer1.Psatt[2], Mixer1.Pg)
 */
void Flowsheet_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
  data->simulationInfo->realParameter[1032] = DIVISION_SIM(data->simulationInfo->realParameter[1041],data->simulationInfo->realParameter[1033],"Mixer1.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 165
 type: SIMPLE_ASSIGN
 Mixer1._Pxc[2] = DIVISION(Mixer1.xguess[2], Mixer1.Psatt[2])
 */
void Flowsheet_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
  data->simulationInfo->realParameter[1044] = DIVISION_SIM(data->simulationInfo->realParameter[1056],data->simulationInfo->realParameter[1041],"Mixer1.Psatt[2]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 166
 type: SIMPLE_ASSIGN
 Mixer1._Pxm[2] = Mixer1.xguess[2] * Mixer1.Psatt[2]
 */
void Flowsheet_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
  data->simulationInfo->realParameter[1046] = (data->simulationInfo->realParameter[1056]) * (data->simulationInfo->realParameter[1041]);
  TRACE_POP
}

/*
 equation index: 167
 type: SIMPLE_ASSIGN
 Mixer1._Tg = Mixer1.Temp
 */
void Flowsheet_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
  data->simulationInfo->realParameter[1052] = data->simulationInfo->realParameter[1051];
  TRACE_POP
}

/*
 equation index: 168
 type: SIMPLE_ASSIGN
 Mixer1._Hcomplg[1] = Simulator.Files.ThermodynamicFunctions.HLiqId(Mixer1.C[1].SH, {Mixer1.C[1].VapCp[1], Mixer1.C[1].VapCp[2], Mixer1.C[1].VapCp[3], Mixer1.C[1].VapCp[4], Mixer1.C[1].VapCp[5], Mixer1.C[1].VapCp[6]}, {Mixer1.C[1].HOV[1], Mixer1.C[1].HOV[2], Mixer1.C[1].HOV[3], Mixer1.C[1].HOV[4], Mixer1.C[1].HOV[5], Mixer1.C[1].HOV[6]}, Mixer1.C[1].Tc, Mixer1.Temp)
 */
void Flowsheet_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[980], (modelica_real)data->simulationInfo->realParameter[981], (modelica_real)data->simulationInfo->realParameter[982], (modelica_real)data->simulationInfo->realParameter[983], (modelica_real)data->simulationInfo->realParameter[984], (modelica_real)data->simulationInfo->realParameter[985]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[880], (modelica_real)data->simulationInfo->realParameter[881], (modelica_real)data->simulationInfo->realParameter[882], (modelica_real)data->simulationInfo->realParameter[883], (modelica_real)data->simulationInfo->realParameter[884], (modelica_real)data->simulationInfo->realParameter[885]);
  data->simulationInfo->realParameter[1023] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[950], tmp2, tmp3, data->simulationInfo->realParameter[960], data->simulationInfo->realParameter[1051]);
  TRACE_POP
}

/*
 equation index: 169
 type: SIMPLE_ASSIGN
 Mixer1._Hcompvg[1] = Simulator.Files.ThermodynamicFunctions.HVapId(Mixer1.C[1].SH, {Mixer1.C[1].VapCp[1], Mixer1.C[1].VapCp[2], Mixer1.C[1].VapCp[3], Mixer1.C[1].VapCp[4], Mixer1.C[1].VapCp[5], Mixer1.C[1].VapCp[6]}, {Mixer1.C[1].HOV[1], Mixer1.C[1].HOV[2], Mixer1.C[1].HOV[3], Mixer1.C[1].HOV[4], Mixer1.C[1].HOV[5], Mixer1.C[1].HOV[6]}, Mixer1.C[1].Tc, Mixer1.Temp)
 */
void Flowsheet_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[980], (modelica_real)data->simulationInfo->realParameter[981], (modelica_real)data->simulationInfo->realParameter[982], (modelica_real)data->simulationInfo->realParameter[983], (modelica_real)data->simulationInfo->realParameter[984], (modelica_real)data->simulationInfo->realParameter[985]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[880], (modelica_real)data->simulationInfo->realParameter[881], (modelica_real)data->simulationInfo->realParameter[882], (modelica_real)data->simulationInfo->realParameter[883], (modelica_real)data->simulationInfo->realParameter[884], (modelica_real)data->simulationInfo->realParameter[885]);
  data->simulationInfo->realParameter[1025] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[950], tmp4, tmp5, data->simulationInfo->realParameter[960], data->simulationInfo->realParameter[1051]);
  TRACE_POP
}

/*
 equation index: 170
 type: SIMPLE_ASSIGN
 Mixer1._Hcomplg[2] = Simulator.Files.ThermodynamicFunctions.HLiqId(Mixer1.C[2].SH, {Mixer1.C[2].VapCp[1], Mixer1.C[2].VapCp[2], Mixer1.C[2].VapCp[3], Mixer1.C[2].VapCp[4], Mixer1.C[2].VapCp[5], Mixer1.C[2].VapCp[6]}, {Mixer1.C[2].HOV[1], Mixer1.C[2].HOV[2], Mixer1.C[2].HOV[3], Mixer1.C[2].HOV[4], Mixer1.C[2].HOV[5], Mixer1.C[2].HOV[6]}, Mixer1.C[2].Tc, Mixer1.Temp)
 */
void Flowsheet_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[986], (modelica_real)data->simulationInfo->realParameter[987], (modelica_real)data->simulationInfo->realParameter[988], (modelica_real)data->simulationInfo->realParameter[989], (modelica_real)data->simulationInfo->realParameter[990], (modelica_real)data->simulationInfo->realParameter[991]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[886], (modelica_real)data->simulationInfo->realParameter[887], (modelica_real)data->simulationInfo->realParameter[888], (modelica_real)data->simulationInfo->realParameter[889], (modelica_real)data->simulationInfo->realParameter[890], (modelica_real)data->simulationInfo->realParameter[891]);
  data->simulationInfo->realParameter[1024] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[951], tmp6, tmp7, data->simulationInfo->realParameter[961], data->simulationInfo->realParameter[1051]);
  TRACE_POP
}

/*
 equation index: 171
 type: SIMPLE_ASSIGN
 Mixer1._Hcompvg[2] = Simulator.Files.ThermodynamicFunctions.HVapId(Mixer1.C[2].SH, {Mixer1.C[2].VapCp[1], Mixer1.C[2].VapCp[2], Mixer1.C[2].VapCp[3], Mixer1.C[2].VapCp[4], Mixer1.C[2].VapCp[5], Mixer1.C[2].VapCp[6]}, {Mixer1.C[2].HOV[1], Mixer1.C[2].HOV[2], Mixer1.C[2].HOV[3], Mixer1.C[2].HOV[4], Mixer1.C[2].HOV[5], Mixer1.C[2].HOV[6]}, Mixer1.C[2].Tc, Mixer1.Temp)
 */
void Flowsheet_eqFunction_171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,171};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[986], (modelica_real)data->simulationInfo->realParameter[987], (modelica_real)data->simulationInfo->realParameter[988], (modelica_real)data->simulationInfo->realParameter[989], (modelica_real)data->simulationInfo->realParameter[990], (modelica_real)data->simulationInfo->realParameter[991]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[886], (modelica_real)data->simulationInfo->realParameter[887], (modelica_real)data->simulationInfo->realParameter[888], (modelica_real)data->simulationInfo->realParameter[889], (modelica_real)data->simulationInfo->realParameter[890], (modelica_real)data->simulationInfo->realParameter[891]);
  data->simulationInfo->realParameter[1026] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[951], tmp8, tmp9, data->simulationInfo->realParameter[961], data->simulationInfo->realParameter[1051]);
  TRACE_POP
}

/*
 equation index: 172
 type: SIMPLE_ASSIGN
 Mixer1._Pxc[1] = DIVISION(Mixer1.xguess[1], Mixer1.Psatt[1])
 */
void Flowsheet_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
  data->simulationInfo->realParameter[1043] = DIVISION_SIM(data->simulationInfo->realParameter[1055],data->simulationInfo->realParameter[1040],"Mixer1.Psatt[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 173
 type: SIMPLE_ASSIGN
 Mixer1._Px = Mixer1.Pxc[1] + Mixer1.Pxc[2]
 */
void Flowsheet_eqFunction_173(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,173};
  data->simulationInfo->realParameter[1042] = data->simulationInfo->realParameter[1043] + data->simulationInfo->realParameter[1044];
  TRACE_POP
}

/*
 equation index: 174
 type: SIMPLE_ASSIGN
 Mixer1._Pmin = DIVISION(1.0, Mixer1.Px)
 */
void Flowsheet_eqFunction_174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,174};
  data->simulationInfo->realParameter[1035] = DIVISION_SIM(1.0,data->simulationInfo->realParameter[1042],"Mixer1.Px",equationIndexes);
  TRACE_POP
}

/*
 equation index: 175
 type: SIMPLE_ASSIGN
 Mixer1._Pxm[1] = Mixer1.xguess[1] * Mixer1.Psatt[1]
 */
void Flowsheet_eqFunction_175(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,175};
  data->simulationInfo->realParameter[1045] = (data->simulationInfo->realParameter[1055]) * (data->simulationInfo->realParameter[1040]);
  TRACE_POP
}

/*
 equation index: 176
 type: SIMPLE_ASSIGN
 Mixer1._Pmax = Mixer1.Pxm[1] + Mixer1.Pxm[2]
 */
void Flowsheet_eqFunction_176(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,176};
  data->simulationInfo->realParameter[1034] = data->simulationInfo->realParameter[1045] + data->simulationInfo->realParameter[1046];
  TRACE_POP
}


/*
 equation index: 177
 type: SIMPLE_ASSIGN
 Mixer1._xvapg = 0.0
 */
void Flowsheet_eqFunction_177(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,177};
  data->simulationInfo->realParameter[1060] = 0.0;
  TRACE_POP
}
/*
 equation index: 178
 type: SIMPLE_ASSIGN
 Mixer1._xvapg = (Mixer1.Pg - Mixer1.Pmin) / (Mixer1.Pmax - Mixer1.Pmin)
 */
void Flowsheet_eqFunction_178(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,178};
  modelica_real tmp12;
  tmp12 = data->simulationInfo->realParameter[1034] - data->simulationInfo->realParameter[1035];
  if (tmp12 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(Mixer1.Pg - Mixer1.Pmin) / (Mixer1.Pmax - Mixer1.Pmin)");}
  data->simulationInfo->realParameter[1060] = (data->simulationInfo->realParameter[1033] - data->simulationInfo->realParameter[1035]) / tmp12;
  TRACE_POP
}
/*
 equation index: 179
 type: SIMPLE_ASSIGN
 Mixer1._xvapg = 1.0
 */
void Flowsheet_eqFunction_179(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,179};
  data->simulationInfo->realParameter[1060] = 1.0;
  TRACE_POP
}
/*
 equation index: 180
 type: IFEQUATION
 
 equation index: 177
 type: SIMPLE_ASSIGN
 Mixer1._xvapg = 0.0equation index: 178
 type: SIMPLE_ASSIGN
 Mixer1._xvapg = (Mixer1.Pg - Mixer1.Pmin) / (Mixer1.Pmax - Mixer1.Pmin)
 equation index: 179
 type: SIMPLE_ASSIGN
 Mixer1._xvapg = 1.0
 */
void Flowsheet_eqFunction_180(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,180};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  tmp10 = GreaterEq(data->simulationInfo->realParameter[1033],data->simulationInfo->realParameter[1034]);
  tmp11 = GreaterEq(data->simulationInfo->realParameter[1033],data->simulationInfo->realParameter[1035]);
  if(tmp10)
  {
    Flowsheet_eqFunction_177(data, threadData);
  }
  else if(tmp11)
  {
    Flowsheet_eqFunction_178(data, threadData);
  }else
  {
    Flowsheet_eqFunction_179(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 181
 type: SIMPLE_ASSIGN
 Mixer1._xliqg = 1.0 - Mixer1.xvapg
 */
void Flowsheet_eqFunction_181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,181};
  data->simulationInfo->realParameter[1057] = 1.0 - data->simulationInfo->realParameter[1060];
  TRACE_POP
}


/*
 equation index: 182
 type: SIMPLE_ASSIGN
 Mixer1._Beta = 1.0
 */
void Flowsheet_eqFunction_182(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,182};
  data->simulationInfo->realParameter[859] = 1.0;
  TRACE_POP
}
/*
 equation index: 183
 type: SIMPLE_ASSIGN
 Mixer1._Beta = 0.0
 */
void Flowsheet_eqFunction_183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,183};
  data->simulationInfo->realParameter[859] = 0.0;
  TRACE_POP
}
/*
 equation index: 184
 type: SIMPLE_ASSIGN
 Mixer1._Beta = Mixer1.xvapg
 */
void Flowsheet_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
  data->simulationInfo->realParameter[859] = data->simulationInfo->realParameter[1060];
  TRACE_POP
}
/*
 equation index: 185
 type: IFEQUATION
 
 equation index: 182
 type: SIMPLE_ASSIGN
 Mixer1._Beta = 1.0equation index: 183
 type: SIMPLE_ASSIGN
 Mixer1._Beta = 0.0
 equation index: 184
 type: SIMPLE_ASSIGN
 Mixer1._Beta = Mixer1.xvapg
 */
void Flowsheet_eqFunction_185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,185};
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  tmp13 = Greater(data->simulationInfo->realParameter[1060],1.0);
  tmp14 = Less(data->simulationInfo->realParameter[1060],0.0);
  if(tmp13)
  {
    Flowsheet_eqFunction_182(data, threadData);
  }
  else if(tmp14)
  {
    Flowsheet_eqFunction_183(data, threadData);
  }else
  {
    Flowsheet_eqFunction_184(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 186
 type: SIMPLE_ASSIGN
 Mixer1._Alpha = 1.0 - Mixer1.Beta
 */
void Flowsheet_eqFunction_186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,186};
  data->simulationInfo->realParameter[858] = 1.0 - data->simulationInfo->realParameter[859];
  TRACE_POP
}



/*
 equation index: 187
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = Mixer1.xguess[1] * Mixer1.K_guess[1] / (1.0 + (-1.0 + Mixer1.K_guess[1]) * Mixer1.xvapg)
 */
void Flowsheet_eqFunction_187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,187};
  modelica_real tmp18;
  tmp18 = 1.0 + (-1.0 + data->simulationInfo->realParameter[1031]) * (data->simulationInfo->realParameter[1060]);
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Mixer1.K_guess[1] / (1.0 + (-1.0 + Mixer1.K_guess[1]) * Mixer1.xvapg)");}
  data->simulationInfo->realParameter[1063] = (data->simulationInfo->realParameter[1055]) * ((data->simulationInfo->realParameter[1031]) / tmp18);
  TRACE_POP
}
/*
 equation index: 188
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = Mixer1.xguess[1]
 */
void Flowsheet_eqFunction_188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,188};
  data->simulationInfo->realParameter[1063] = data->simulationInfo->realParameter[1055];
  TRACE_POP
}
/*
 equation index: 189
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,189};
  data->simulationInfo->realParameter[1063] = 0.0;
  TRACE_POP
}
/*
 equation index: 190
 type: IFEQUATION
 
 equation index: 187
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = Mixer1.xguess[1] * Mixer1.K_guess[1] / (1.0 + (-1.0 + Mixer1.K_guess[1]) * Mixer1.xvapg)equation index: 188
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = Mixer1.xguess[1]
 equation index: 189
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,190};
  modelica_boolean tmp16;
  tmp16 = Greater(data->simulationInfo->realParameter[859],0.0);
  if((tmp16 && (data->simulationInfo->realParameter[859] != 1.0)))
  {
    Flowsheet_eqFunction_187(data, threadData);
  }
  else if((data->simulationInfo->realParameter[859] == 1.0))
  {
    Flowsheet_eqFunction_188(data, threadData);
  }else
  {
    Flowsheet_eqFunction_189(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 191
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = Mixer1.ymol[1] / Mixer1.K_guess[1]
 */
void Flowsheet_eqFunction_191(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,191};
  modelica_real tmp22;
  tmp22 = data->simulationInfo->realParameter[1031];
  if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Mixer1.ymol[1] / Mixer1.K_guess[1]");}
  data->simulationInfo->realParameter[1058] = (data->simulationInfo->realParameter[1063]) / tmp22;
  TRACE_POP
}
/*
 equation index: 192
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = Mixer1.xguess[1]
 */
void Flowsheet_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
  data->simulationInfo->realParameter[1058] = data->simulationInfo->realParameter[1055];
  TRACE_POP
}
/*
 equation index: 193
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,193};
  data->simulationInfo->realParameter[1058] = 0.0;
  TRACE_POP
}
/*
 equation index: 194
 type: IFEQUATION
 
 equation index: 191
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = Mixer1.ymol[1] / Mixer1.K_guess[1]equation index: 192
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = Mixer1.xguess[1]
 equation index: 193
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,194};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  tmp20 = Greater(data->simulationInfo->realParameter[859],0.0);
  tmp21 = Less(data->simulationInfo->realParameter[859],1.0);
  if((tmp20 && tmp21))
  {
    Flowsheet_eqFunction_191(data, threadData);
  }
  else if((data->simulationInfo->realParameter[859] == 0.0))
  {
    Flowsheet_eqFunction_192(data, threadData);
  }else
  {
    Flowsheet_eqFunction_193(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 195
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_195(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,195};
  data->simulationInfo->realParameter[1058] = 0.0;
  TRACE_POP
}

/*
 equation index: 196
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,196};
  data->simulationInfo->realParameter[1063] = 0.0;
  TRACE_POP
}
/*
 equation index: 197
 type: IFEQUATION
 
 equation index: 190
 type: IFEQUATION
 
 equation index: 187
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = Mixer1.xguess[1] * Mixer1.K_guess[1] / (1.0 + (-1.0 + Mixer1.K_guess[1]) * Mixer1.xvapg)equation index: 188
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = Mixer1.xguess[1]
 equation index: 189
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = 0.0equation index: 194
 type: IFEQUATION
 
 equation index: 191
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = Mixer1.ymol[1] / Mixer1.K_guess[1]equation index: 192
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = Mixer1.xguess[1]
 equation index: 193
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = 0.0
 equation index: 195
 type: SIMPLE_ASSIGN
 Mixer1._xmol[1] = 0.0equation index: 196
 type: SIMPLE_ASSIGN
 Mixer1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,197};
  if((data->simulationInfo->realParameter[1055] != 0.0))
  {
    Flowsheet_eqFunction_190(data, threadData);

    Flowsheet_eqFunction_194(data, threadData);
  }else
  {
    Flowsheet_eqFunction_195(data, threadData);
    Flowsheet_eqFunction_196(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 198
 type: SIMPLE_ASSIGN
 Mixer1._xg[1] = 0.0
 */
void Flowsheet_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
  data->simulationInfo->realParameter[1053] = 0.0;
  TRACE_POP
}
/*
 equation index: 199
 type: SIMPLE_ASSIGN
 Mixer1._xg[1] = 1.0
 */
void Flowsheet_eqFunction_199(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,199};
  data->simulationInfo->realParameter[1053] = 1.0;
  TRACE_POP
}
/*
 equation index: 200
 type: SIMPLE_ASSIGN
 Mixer1._xg[1] = Mixer1.xmol[1]
 */
void Flowsheet_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
  data->simulationInfo->realParameter[1053] = data->simulationInfo->realParameter[1058];
  TRACE_POP
}
/*
 equation index: 201
 type: IFEQUATION
 
 equation index: 198
 type: SIMPLE_ASSIGN
 Mixer1._xg[1] = 0.0equation index: 199
 type: SIMPLE_ASSIGN
 Mixer1._xg[1] = 1.0
 equation index: 200
 type: SIMPLE_ASSIGN
 Mixer1._xg[1] = Mixer1.xmol[1]
 */
void Flowsheet_eqFunction_201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,201};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  tmp24 = Less(data->simulationInfo->realParameter[1058],0.0);
  tmp25 = Greater(data->simulationInfo->realParameter[1053],1.0);
  if(tmp24)
  {
    Flowsheet_eqFunction_198(data, threadData);
  }
  else if(tmp25)
  {
    Flowsheet_eqFunction_199(data, threadData);
  }else
  {
    Flowsheet_eqFunction_200(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 202
 type: SIMPLE_ASSIGN
 Mixer1._yg[1] = 0.0
 */
void Flowsheet_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
  data->simulationInfo->realParameter[1061] = 0.0;
  TRACE_POP
}
/*
 equation index: 203
 type: SIMPLE_ASSIGN
 Mixer1._yg[1] = 1.0
 */
void Flowsheet_eqFunction_203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,203};
  data->simulationInfo->realParameter[1061] = 1.0;
  TRACE_POP
}
/*
 equation index: 204
 type: SIMPLE_ASSIGN
 Mixer1._yg[1] = Mixer1.ymol[1]
 */
void Flowsheet_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
  data->simulationInfo->realParameter[1061] = data->simulationInfo->realParameter[1063];
  TRACE_POP
}
/*
 equation index: 205
 type: IFEQUATION
 
 equation index: 202
 type: SIMPLE_ASSIGN
 Mixer1._yg[1] = 0.0equation index: 203
 type: SIMPLE_ASSIGN
 Mixer1._yg[1] = 1.0
 equation index: 204
 type: SIMPLE_ASSIGN
 Mixer1._yg[1] = Mixer1.ymol[1]
 */
void Flowsheet_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  tmp26 = Less(data->simulationInfo->realParameter[1063],0.0);
  tmp27 = Greater(data->simulationInfo->realParameter[1063],1.0);
  if(tmp26)
  {
    Flowsheet_eqFunction_202(data, threadData);
  }
  else if(tmp27)
  {
    Flowsheet_eqFunction_203(data, threadData);
  }else
  {
    Flowsheet_eqFunction_204(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 209
 type: LINEAR
 
 <var>Mixer1._Fvapg</var>
 <row>

 </row>
 <matrix>
 </matrix>
 */
void Flowsheet_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 209 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[1].x[0] = data->simulationInfo->realParameter[1020];
  retValue = solve_linear_system(data, threadData, 1);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,209};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 209 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[1020] = data->simulationInfo->linearSystemData[1].x[0];
  TRACE_POP
}



/*
 equation index: 210
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = Mixer1.xguess[2] * Mixer1.K_guess[2] / (1.0 + (-1.0 + Mixer1.K_guess[2]) * Mixer1.xvapg)
 */
void Flowsheet_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
  modelica_real tmp31;
  tmp31 = 1.0 + (-1.0 + data->simulationInfo->realParameter[1032]) * (data->simulationInfo->realParameter[1060]);
  if (tmp31 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Mixer1.K_guess[2] / (1.0 + (-1.0 + Mixer1.K_guess[2]) * Mixer1.xvapg)");}
  data->simulationInfo->realParameter[1064] = (data->simulationInfo->realParameter[1056]) * ((data->simulationInfo->realParameter[1032]) / tmp31);
  TRACE_POP
}
/*
 equation index: 211
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = Mixer1.xguess[2]
 */
void Flowsheet_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
  data->simulationInfo->realParameter[1064] = data->simulationInfo->realParameter[1056];
  TRACE_POP
}
/*
 equation index: 212
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
  data->simulationInfo->realParameter[1064] = 0.0;
  TRACE_POP
}
/*
 equation index: 213
 type: IFEQUATION
 
 equation index: 210
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = Mixer1.xguess[2] * Mixer1.K_guess[2] / (1.0 + (-1.0 + Mixer1.K_guess[2]) * Mixer1.xvapg)equation index: 211
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = Mixer1.xguess[2]
 equation index: 212
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  modelica_boolean tmp29;
  tmp29 = Greater(data->simulationInfo->realParameter[859],0.0);
  if((tmp29 && (data->simulationInfo->realParameter[859] != 1.0)))
  {
    Flowsheet_eqFunction_210(data, threadData);
  }
  else if((data->simulationInfo->realParameter[859] == 1.0))
  {
    Flowsheet_eqFunction_211(data, threadData);
  }else
  {
    Flowsheet_eqFunction_212(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 214
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = Mixer1.ymol[2] / Mixer1.K_guess[2]
 */
void Flowsheet_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  modelica_real tmp35;
  tmp35 = data->simulationInfo->realParameter[1032];
  if (tmp35 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Mixer1.ymol[2] / Mixer1.K_guess[2]");}
  data->simulationInfo->realParameter[1059] = (data->simulationInfo->realParameter[1064]) / tmp35;
  TRACE_POP
}
/*
 equation index: 215
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = Mixer1.xguess[2]
 */
void Flowsheet_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
  data->simulationInfo->realParameter[1059] = data->simulationInfo->realParameter[1056];
  TRACE_POP
}
/*
 equation index: 216
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  data->simulationInfo->realParameter[1059] = 0.0;
  TRACE_POP
}
/*
 equation index: 217
 type: IFEQUATION
 
 equation index: 214
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = Mixer1.ymol[2] / Mixer1.K_guess[2]equation index: 215
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = Mixer1.xguess[2]
 equation index: 216
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  tmp33 = Greater(data->simulationInfo->realParameter[859],0.0);
  tmp34 = Less(data->simulationInfo->realParameter[859],1.0);
  if((tmp33 && tmp34))
  {
    Flowsheet_eqFunction_214(data, threadData);
  }
  else if((data->simulationInfo->realParameter[859] == 0.0))
  {
    Flowsheet_eqFunction_215(data, threadData);
  }else
  {
    Flowsheet_eqFunction_216(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 218
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
  data->simulationInfo->realParameter[1059] = 0.0;
  TRACE_POP
}

/*
 equation index: 219
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
  data->simulationInfo->realParameter[1064] = 0.0;
  TRACE_POP
}
/*
 equation index: 220
 type: IFEQUATION
 
 equation index: 213
 type: IFEQUATION
 
 equation index: 210
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = Mixer1.xguess[2] * Mixer1.K_guess[2] / (1.0 + (-1.0 + Mixer1.K_guess[2]) * Mixer1.xvapg)equation index: 211
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = Mixer1.xguess[2]
 equation index: 212
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = 0.0equation index: 217
 type: IFEQUATION
 
 equation index: 214
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = Mixer1.ymol[2] / Mixer1.K_guess[2]equation index: 215
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = Mixer1.xguess[2]
 equation index: 216
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = 0.0
 equation index: 218
 type: SIMPLE_ASSIGN
 Mixer1._xmol[2] = 0.0equation index: 219
 type: SIMPLE_ASSIGN
 Mixer1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  if((data->simulationInfo->realParameter[1056] != 0.0))
  {
    Flowsheet_eqFunction_213(data, threadData);

    Flowsheet_eqFunction_217(data, threadData);
  }else
  {
    Flowsheet_eqFunction_218(data, threadData);
    Flowsheet_eqFunction_219(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 221
 type: SIMPLE_ASSIGN
 Mixer1._yg[2] = 0.0
 */
void Flowsheet_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  data->simulationInfo->realParameter[1062] = 0.0;
  TRACE_POP
}
/*
 equation index: 222
 type: SIMPLE_ASSIGN
 Mixer1._yg[2] = 1.0
 */
void Flowsheet_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  data->simulationInfo->realParameter[1062] = 1.0;
  TRACE_POP
}
/*
 equation index: 223
 type: SIMPLE_ASSIGN
 Mixer1._yg[2] = Mixer1.ymol[2]
 */
void Flowsheet_eqFunction_223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,223};
  data->simulationInfo->realParameter[1062] = data->simulationInfo->realParameter[1064];
  TRACE_POP
}
/*
 equation index: 224
 type: IFEQUATION
 
 equation index: 221
 type: SIMPLE_ASSIGN
 Mixer1._yg[2] = 0.0equation index: 222
 type: SIMPLE_ASSIGN
 Mixer1._yg[2] = 1.0
 equation index: 223
 type: SIMPLE_ASSIGN
 Mixer1._yg[2] = Mixer1.ymol[2]
 */
void Flowsheet_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  tmp37 = Less(data->simulationInfo->realParameter[1064],0.0);
  tmp38 = Greater(data->simulationInfo->realParameter[1064],1.0);
  if(tmp37)
  {
    Flowsheet_eqFunction_221(data, threadData);
  }
  else if(tmp38)
  {
    Flowsheet_eqFunction_222(data, threadData);
  }else
  {
    Flowsheet_eqFunction_223(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 225
 type: SIMPLE_ASSIGN
 Mixer1._xg[2] = 0.0
 */
void Flowsheet_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
  data->simulationInfo->realParameter[1054] = 0.0;
  TRACE_POP
}
/*
 equation index: 226
 type: SIMPLE_ASSIGN
 Mixer1._xg[2] = 1.0
 */
void Flowsheet_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  data->simulationInfo->realParameter[1054] = 1.0;
  TRACE_POP
}
/*
 equation index: 227
 type: SIMPLE_ASSIGN
 Mixer1._xg[2] = Mixer1.xmol[2]
 */
void Flowsheet_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  data->simulationInfo->realParameter[1054] = data->simulationInfo->realParameter[1059];
  TRACE_POP
}
/*
 equation index: 228
 type: IFEQUATION
 
 equation index: 225
 type: SIMPLE_ASSIGN
 Mixer1._xg[2] = 0.0equation index: 226
 type: SIMPLE_ASSIGN
 Mixer1._xg[2] = 1.0
 equation index: 227
 type: SIMPLE_ASSIGN
 Mixer1._xg[2] = Mixer1.xmol[2]
 */
void Flowsheet_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  tmp39 = Less(data->simulationInfo->realParameter[1059],0.0);
  tmp40 = Greater(data->simulationInfo->realParameter[1054],1.0);
  if(tmp39)
  {
    Flowsheet_eqFunction_225(data, threadData);
  }
  else if(tmp40)
  {
    Flowsheet_eqFunction_226(data, threadData);
  }else
  {
    Flowsheet_eqFunction_227(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 229
 type: SIMPLE_ASSIGN
 $START._Mixer1._xvapin_s[2] = Mixer1.xvapg
 */
void Flowsheet_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  data->modelData->realVarsData[277].attribute /* Mixer1._xvapin_s[2] variable */.start = data->simulationInfo->realParameter[1060];
    data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */ = data->modelData->realVarsData[277].attribute /* Mixer1._xvapin_s[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[277].info /* Mixer1._xvapin_s[2] */.name, (modelica_real) data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */);
  TRACE_POP
}

/*
 equation index: 230
 type: SIMPLE_ASSIGN
 $START._Mixer1._xvapin_s[1] = Mixer1.xvapg
 */
void Flowsheet_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  data->modelData->realVarsData[276].attribute /* Mixer1._xvapin_s[1] variable */.start = data->simulationInfo->realParameter[1060];
    data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */ = data->modelData->realVarsData[276].attribute /* Mixer1._xvapin_s[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[276].info /* Mixer1._xvapin_s[1] */.name, (modelica_real) data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */);
  TRACE_POP
}

/*
 equation index: 231
 type: SIMPLE_ASSIGN
 Mixer1._Hliqg = Mixer1.xguess[1] * Mixer1.Hcomplg[1] + Mixer1.xguess[2] * Mixer1.Hcomplg[2]
 */
void Flowsheet_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  data->simulationInfo->realParameter[1027] = (data->simulationInfo->realParameter[1055]) * (data->simulationInfo->realParameter[1023]) + (data->simulationInfo->realParameter[1056]) * (data->simulationInfo->realParameter[1024]);
  TRACE_POP
}

/*
 equation index: 232
 type: SIMPLE_ASSIGN
 Mixer1._Hvapg = Mixer1.xguess[1] * Mixer1.Hcompvg[1] + Mixer1.xguess[2] * Mixer1.Hcompvg[2]
 */
void Flowsheet_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  data->simulationInfo->realParameter[1030] = (data->simulationInfo->realParameter[1055]) * (data->simulationInfo->realParameter[1025]) + (data->simulationInfo->realParameter[1056]) * (data->simulationInfo->realParameter[1026]);
  TRACE_POP
}

/*
 equation index: 233
 type: SIMPLE_ASSIGN
 Mixer1._Htotg = Mixer1.Hliqg + Mixer1.Hvapg
 */
void Flowsheet_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  data->simulationInfo->realParameter[1029] = data->simulationInfo->realParameter[1027] + data->simulationInfo->realParameter[1030];
  TRACE_POP
}

/*
 equation index: 234
 type: SIMPLE_ASSIGN
 Mixer1._Hmixg = Mixer1.Htotg
 */
void Flowsheet_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  data->simulationInfo->realParameter[1028] = data->simulationInfo->realParameter[1029];
  TRACE_POP
}

/*
 equation index: 235
 type: SIMPLE_ASSIGN
 Mixer1._Hcompg[1] = Mixer1.xguess[1] * Mixer1.Htotg
 */
void Flowsheet_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  data->simulationInfo->realParameter[1021] = (data->simulationInfo->realParameter[1055]) * (data->simulationInfo->realParameter[1029]);
  TRACE_POP
}

/*
 equation index: 236
 type: SIMPLE_ASSIGN
 Mixer1._Hcompg[2] = Mixer1.xguess[2] * Mixer1.Htotg
 */
void Flowsheet_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
  data->simulationInfo->realParameter[1022] = (data->simulationInfo->realParameter[1056]) * (data->simulationInfo->realParameter[1029]);
  TRACE_POP
}

/*
 equation index: 237
 type: SIMPLE_ASSIGN
 MaterialStream2._xguess[2] = 0.5
 */
void Flowsheet_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  data->simulationInfo->realParameter[642] = 0.5;
  TRACE_POP
}

/*
 equation index: 238
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[1,2] = MaterialStream2.xguess[2]
 */
void Flowsheet_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  data->modelData->realVarsData[178].attribute /* MaterialStream2._xm_pc[1,2] variable */.start = data->simulationInfo->realParameter[642];
    data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */ = data->modelData->realVarsData[178].attribute /* MaterialStream2._xm_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[178].info /* MaterialStream2._xm_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 239
 type: SIMPLE_ASSIGN
 MaterialStream2._xguess[1] = 0.5
 */
void Flowsheet_eqFunction_239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,239};
  data->simulationInfo->realParameter[641] = 0.5;
  TRACE_POP
}

void Flowsheet_eqFunction_240(DATA*,threadData_t*);
void Flowsheet_eqFunction_241(DATA*,threadData_t*);
void Flowsheet_eqFunction_242(DATA*,threadData_t*);
/*
 equation index: 243
 indexNonlinear: 4
 type: NONLINEAR
 
 vars: {MaterialStream2._Tdg}
 eqns: {240, 241, 242}
 */
void Flowsheet_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 243 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[4].nlsxOld[0] = data->simulationInfo->realParameter[636];
  retValue = solve_nonlinear_system(data, threadData, 4);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,243};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 243 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[636] = data->simulationInfo->nonlinearSystemData[4].nlsx[0];
  TRACE_POP
}

void Flowsheet_eqFunction_244(DATA*,threadData_t*);
void Flowsheet_eqFunction_245(DATA*,threadData_t*);
void Flowsheet_eqFunction_246(DATA*,threadData_t*);
/*
 equation index: 247
 indexNonlinear: 5
 type: NONLINEAR
 
 vars: {MaterialStream2._Tbg}
 eqns: {244, 245, 246}
 */
void Flowsheet_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 247 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[5].nlsxOld[0] = data->simulationInfo->realParameter[633];
  retValue = solve_nonlinear_system(data, threadData, 5);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,247};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 247 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[633] = data->simulationInfo->nonlinearSystemData[5].nlsx[0];
  TRACE_POP
}

/*
 equation index: 248
 type: SIMPLE_ASSIGN
 MaterialStream2._Temp = 0.5 * (MaterialStream2.Tbg + MaterialStream2.Tdg)
 */
void Flowsheet_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
  data->simulationInfo->realParameter[637] = (0.5) * (data->simulationInfo->realParameter[633] + data->simulationInfo->realParameter[636]);
  TRACE_POP
}

/*
 equation index: 249
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatt[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[1].VP[1], MaterialStream2.C[1].VP[2], MaterialStream2.C[1].VP[3], MaterialStream2.C[1].VP[4], MaterialStream2.C[1].VP[5], MaterialStream2.C[1].VP[6]}, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[554], (modelica_real)data->simulationInfo->realParameter[555], (modelica_real)data->simulationInfo->realParameter[556], (modelica_real)data->simulationInfo->realParameter[557], (modelica_real)data->simulationInfo->realParameter[558], (modelica_real)data->simulationInfo->realParameter[559]);
  data->simulationInfo->realParameter[626] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[637]);
  TRACE_POP
}

/*
 equation index: 250
 type: SIMPLE_ASSIGN
 MaterialStream2._K_guess[1] = DIVISION(MaterialStream2.Psatt[1], MaterialStream2.Pg)
 */
void Flowsheet_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
  data->simulationInfo->realParameter[617] = DIVISION_SIM(data->simulationInfo->realParameter[626],data->simulationInfo->realParameter[619],"MaterialStream2.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 251
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatt[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[2].VP[1], MaterialStream2.C[2].VP[2], MaterialStream2.C[2].VP[3], MaterialStream2.C[2].VP[4], MaterialStream2.C[2].VP[5], MaterialStream2.C[2].VP[6]}, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[560], (modelica_real)data->simulationInfo->realParameter[561], (modelica_real)data->simulationInfo->realParameter[562], (modelica_real)data->simulationInfo->realParameter[563], (modelica_real)data->simulationInfo->realParameter[564], (modelica_real)data->simulationInfo->realParameter[565]);
  data->simulationInfo->realParameter[627] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp1, data->simulationInfo->realParameter[637]);
  TRACE_POP
}

/*
 equation index: 252
 type: SIMPLE_ASSIGN
 MaterialStream2._K_guess[2] = DIVISION(MaterialStream2.Psatt[2], MaterialStream2.Pg)
 */
void Flowsheet_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  data->simulationInfo->realParameter[618] = DIVISION_SIM(data->simulationInfo->realParameter[627],data->simulationInfo->realParameter[619],"MaterialStream2.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 253
 type: SIMPLE_ASSIGN
 MaterialStream2._Pxc[2] = DIVISION(MaterialStream2.xguess[2], MaterialStream2.Psatt[2])
 */
void Flowsheet_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
  data->simulationInfo->realParameter[630] = DIVISION_SIM(data->simulationInfo->realParameter[642],data->simulationInfo->realParameter[627],"MaterialStream2.Psatt[2]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 254
 type: SIMPLE_ASSIGN
 MaterialStream2._Pxm[2] = MaterialStream2.xguess[2] * MaterialStream2.Psatt[2]
 */
void Flowsheet_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  data->simulationInfo->realParameter[632] = (data->simulationInfo->realParameter[642]) * (data->simulationInfo->realParameter[627]);
  TRACE_POP
}

/*
 equation index: 255
 type: SIMPLE_ASSIGN
 MaterialStream2._Tg = MaterialStream2.Temp
 */
void Flowsheet_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  data->simulationInfo->realParameter[638] = data->simulationInfo->realParameter[637];
  TRACE_POP
}

/*
 equation index: 256
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcomplg[1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream2.C[1].SH, {MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tc, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567], (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[466], (modelica_real)data->simulationInfo->realParameter[467], (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471]);
  data->simulationInfo->realParameter[609] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[536], tmp2, tmp3, data->simulationInfo->realParameter[546], data->simulationInfo->realParameter[637]);
  TRACE_POP
}

/*
 equation index: 257
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcompvg[1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream2.C[1].SH, {MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tc, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567], (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[466], (modelica_real)data->simulationInfo->realParameter[467], (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471]);
  data->simulationInfo->realParameter[611] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[536], tmp4, tmp5, data->simulationInfo->realParameter[546], data->simulationInfo->realParameter[637]);
  TRACE_POP
}

/*
 equation index: 258
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcomplg[2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream2.C[2].SH, {MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tc, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573], (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473], (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477]);
  data->simulationInfo->realParameter[610] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[537], tmp6, tmp7, data->simulationInfo->realParameter[547], data->simulationInfo->realParameter[637]);
  TRACE_POP
}

/*
 equation index: 259
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcompvg[2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream2.C[2].SH, {MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tc, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573], (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473], (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477]);
  data->simulationInfo->realParameter[612] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[537], tmp8, tmp9, data->simulationInfo->realParameter[547], data->simulationInfo->realParameter[637]);
  TRACE_POP
}

/*
 equation index: 260
 type: SIMPLE_ASSIGN
 MaterialStream2._Pxc[1] = DIVISION(MaterialStream2.xguess[1], MaterialStream2.Psatt[1])
 */
void Flowsheet_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  data->simulationInfo->realParameter[629] = DIVISION_SIM(data->simulationInfo->realParameter[641],data->simulationInfo->realParameter[626],"MaterialStream2.Psatt[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 261
 type: SIMPLE_ASSIGN
 MaterialStream2._Px = MaterialStream2.Pxc[1] + MaterialStream2.Pxc[2]
 */
void Flowsheet_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
  data->simulationInfo->realParameter[628] = data->simulationInfo->realParameter[629] + data->simulationInfo->realParameter[630];
  TRACE_POP
}

/*
 equation index: 262
 type: SIMPLE_ASSIGN
 MaterialStream2._Pmin = DIVISION(1.0, MaterialStream2.Px)
 */
void Flowsheet_eqFunction_262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,262};
  data->simulationInfo->realParameter[621] = DIVISION_SIM(1.0,data->simulationInfo->realParameter[628],"MaterialStream2.Px",equationIndexes);
  TRACE_POP
}

/*
 equation index: 263
 type: SIMPLE_ASSIGN
 MaterialStream2._Pxm[1] = MaterialStream2.xguess[1] * MaterialStream2.Psatt[1]
 */
void Flowsheet_eqFunction_263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,263};
  data->simulationInfo->realParameter[631] = (data->simulationInfo->realParameter[641]) * (data->simulationInfo->realParameter[626]);
  TRACE_POP
}

/*
 equation index: 264
 type: SIMPLE_ASSIGN
 MaterialStream2._Pmax = MaterialStream2.Pxm[1] + MaterialStream2.Pxm[2]
 */
void Flowsheet_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,264};
  data->simulationInfo->realParameter[620] = data->simulationInfo->realParameter[631] + data->simulationInfo->realParameter[632];
  TRACE_POP
}


/*
 equation index: 265
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = 0.0
 */
void Flowsheet_eqFunction_265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,265};
  data->simulationInfo->realParameter[646] = 0.0;
  TRACE_POP
}
/*
 equation index: 266
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = (MaterialStream2.Pg - MaterialStream2.Pmin) / (MaterialStream2.Pmax - MaterialStream2.Pmin)
 */
void Flowsheet_eqFunction_266(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,266};
  modelica_real tmp12;
  tmp12 = data->simulationInfo->realParameter[620] - data->simulationInfo->realParameter[621];
  if (tmp12 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(MaterialStream2.Pg - MaterialStream2.Pmin) / (MaterialStream2.Pmax - MaterialStream2.Pmin)");}
  data->simulationInfo->realParameter[646] = (data->simulationInfo->realParameter[619] - data->simulationInfo->realParameter[621]) / tmp12;
  TRACE_POP
}
/*
 equation index: 267
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = 1.0
 */
void Flowsheet_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
  data->simulationInfo->realParameter[646] = 1.0;
  TRACE_POP
}
/*
 equation index: 268
 type: IFEQUATION
 
 equation index: 265
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = 0.0equation index: 266
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = (MaterialStream2.Pg - MaterialStream2.Pmin) / (MaterialStream2.Pmax - MaterialStream2.Pmin)
 equation index: 267
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = 1.0
 */
void Flowsheet_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  tmp10 = GreaterEq(data->simulationInfo->realParameter[619],data->simulationInfo->realParameter[620]);
  tmp11 = GreaterEq(data->simulationInfo->realParameter[619],data->simulationInfo->realParameter[621]);
  if(tmp10)
  {
    Flowsheet_eqFunction_265(data, threadData);
  }
  else if(tmp11)
  {
    Flowsheet_eqFunction_266(data, threadData);
  }else
  {
    Flowsheet_eqFunction_267(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 269
 type: SIMPLE_ASSIGN
 MaterialStream2._xliqg = 1.0 - MaterialStream2.xvapg
 */
void Flowsheet_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  data->simulationInfo->realParameter[643] = 1.0 - data->simulationInfo->realParameter[646];
  TRACE_POP
}

/*
 equation index: 270
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xmliq = MaterialStream2.xliqg
 */
void Flowsheet_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  data->modelData->realVarsData[183].attribute /* MaterialStream2._xmliq variable */.start = data->simulationInfo->realParameter[643];
    data->localData[0]->realVars[183] /* MaterialStream2._xmliq variable */ = data->modelData->realVarsData[183].attribute /* MaterialStream2._xmliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[183].info /* MaterialStream2._xmliq */.name, (modelica_real) data->localData[0]->realVars[183] /* MaterialStream2._xmliq variable */);
  TRACE_POP
}

/*
 equation index: 271
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xliq = MaterialStream2.xliqg
 */
void Flowsheet_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
  data->modelData->realVarsData[176].attribute /* MaterialStream2._xliq variable */.start = data->simulationInfo->realParameter[643];
    data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */ = data->modelData->realVarsData[176].attribute /* MaterialStream2._xliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[176].info /* MaterialStream2._xliq */.name, (modelica_real) data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */);
  TRACE_POP
}


/*
 equation index: 272
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = 1.0
 */
void Flowsheet_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
  data->simulationInfo->realParameter[445] = 1.0;
  TRACE_POP
}
/*
 equation index: 273
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = 0.0
 */
void Flowsheet_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
  data->simulationInfo->realParameter[445] = 0.0;
  TRACE_POP
}
/*
 equation index: 274
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = MaterialStream2.xvapg
 */
void Flowsheet_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
  data->simulationInfo->realParameter[445] = data->simulationInfo->realParameter[646];
  TRACE_POP
}
/*
 equation index: 275
 type: IFEQUATION
 
 equation index: 272
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = 1.0equation index: 273
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = 0.0
 equation index: 274
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = MaterialStream2.xvapg
 */
void Flowsheet_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  tmp13 = Greater(data->simulationInfo->realParameter[646],1.0);
  tmp14 = Less(data->simulationInfo->realParameter[646],0.0);
  if(tmp13)
  {
    Flowsheet_eqFunction_272(data, threadData);
  }
  else if(tmp14)
  {
    Flowsheet_eqFunction_273(data, threadData);
  }else
  {
    Flowsheet_eqFunction_274(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 276
 type: SIMPLE_ASSIGN
 MaterialStream2._Alpha = 1.0 - MaterialStream2.Beta
 */
void Flowsheet_eqFunction_276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,276};
  data->simulationInfo->realParameter[444] = 1.0 - data->simulationInfo->realParameter[445];
  TRACE_POP
}



/*
 equation index: 277
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1] * MaterialStream2.K_guess[1] / (1.0 + (-1.0 + MaterialStream2.K_guess[1]) * MaterialStream2.xvapg)
 */
void Flowsheet_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,277};
  modelica_real tmp18;
  tmp18 = 1.0 + (-1.0 + data->simulationInfo->realParameter[617]) * (data->simulationInfo->realParameter[646]);
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.K_guess[1] / (1.0 + (-1.0 + MaterialStream2.K_guess[1]) * MaterialStream2.xvapg)");}
  data->simulationInfo->realParameter[649] = (data->simulationInfo->realParameter[641]) * ((data->simulationInfo->realParameter[617]) / tmp18);
  TRACE_POP
}
/*
 equation index: 278
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1]
 */
void Flowsheet_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
  data->simulationInfo->realParameter[649] = data->simulationInfo->realParameter[641];
  TRACE_POP
}
/*
 equation index: 279
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,279};
  data->simulationInfo->realParameter[649] = 0.0;
  TRACE_POP
}
/*
 equation index: 280
 type: IFEQUATION
 
 equation index: 277
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1] * MaterialStream2.K_guess[1] / (1.0 + (-1.0 + MaterialStream2.K_guess[1]) * MaterialStream2.xvapg)equation index: 278
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1]
 equation index: 279
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  modelica_boolean tmp16;
  tmp16 = Greater(data->simulationInfo->realParameter[445],0.0);
  if((tmp16 && (data->simulationInfo->realParameter[445] != 1.0)))
  {
    Flowsheet_eqFunction_277(data, threadData);
  }
  else if((data->simulationInfo->realParameter[445] == 1.0))
  {
    Flowsheet_eqFunction_278(data, threadData);
  }else
  {
    Flowsheet_eqFunction_279(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 281
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.ymol[1] / MaterialStream2.K_guess[1]
 */
void Flowsheet_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
  modelica_real tmp22;
  tmp22 = data->simulationInfo->realParameter[617];
  if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.ymol[1] / MaterialStream2.K_guess[1]");}
  data->simulationInfo->realParameter[644] = (data->simulationInfo->realParameter[649]) / tmp22;
  TRACE_POP
}
/*
 equation index: 282
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.xguess[1]
 */
void Flowsheet_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
  data->simulationInfo->realParameter[644] = data->simulationInfo->realParameter[641];
  TRACE_POP
}
/*
 equation index: 283
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  data->simulationInfo->realParameter[644] = 0.0;
  TRACE_POP
}
/*
 equation index: 284
 type: IFEQUATION
 
 equation index: 281
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.ymol[1] / MaterialStream2.K_guess[1]equation index: 282
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.xguess[1]
 equation index: 283
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  tmp20 = Greater(data->simulationInfo->realParameter[445],0.0);
  tmp21 = Less(data->simulationInfo->realParameter[445],1.0);
  if((tmp20 && tmp21))
  {
    Flowsheet_eqFunction_281(data, threadData);
  }
  else if((data->simulationInfo->realParameter[445] == 0.0))
  {
    Flowsheet_eqFunction_282(data, threadData);
  }else
  {
    Flowsheet_eqFunction_283(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 285
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  data->simulationInfo->realParameter[644] = 0.0;
  TRACE_POP
}

/*
 equation index: 286
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  data->simulationInfo->realParameter[649] = 0.0;
  TRACE_POP
}
/*
 equation index: 287
 type: IFEQUATION
 
 equation index: 280
 type: IFEQUATION
 
 equation index: 277
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1] * MaterialStream2.K_guess[1] / (1.0 + (-1.0 + MaterialStream2.K_guess[1]) * MaterialStream2.xvapg)equation index: 278
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1]
 equation index: 279
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0equation index: 284
 type: IFEQUATION
 
 equation index: 281
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.ymol[1] / MaterialStream2.K_guess[1]equation index: 282
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.xguess[1]
 equation index: 283
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0
 equation index: 285
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0equation index: 286
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  if((data->simulationInfo->realParameter[641] != 0.0))
  {
    Flowsheet_eqFunction_280(data, threadData);

    Flowsheet_eqFunction_284(data, threadData);
  }else
  {
    Flowsheet_eqFunction_285(data, threadData);
    Flowsheet_eqFunction_286(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 288
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = 0.0
 */
void Flowsheet_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  data->simulationInfo->realParameter[639] = 0.0;
  TRACE_POP
}
/*
 equation index: 289
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = 1.0
 */
void Flowsheet_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  data->simulationInfo->realParameter[639] = 1.0;
  TRACE_POP
}
/*
 equation index: 290
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = MaterialStream2.xmol[1]
 */
void Flowsheet_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  data->simulationInfo->realParameter[639] = data->simulationInfo->realParameter[644];
  TRACE_POP
}
/*
 equation index: 291
 type: IFEQUATION
 
 equation index: 288
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = 0.0equation index: 289
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = 1.0
 equation index: 290
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = MaterialStream2.xmol[1]
 */
void Flowsheet_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  tmp24 = Less(data->simulationInfo->realParameter[644],0.0);
  tmp25 = Greater(data->simulationInfo->realParameter[639],1.0);
  if(tmp24)
  {
    Flowsheet_eqFunction_288(data, threadData);
  }
  else if(tmp25)
  {
    Flowsheet_eqFunction_289(data, threadData);
  }else
  {
    Flowsheet_eqFunction_290(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 292
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[2,1] = MaterialStream2.xg[1]
 */
void Flowsheet_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
  data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[2,1] variable */.start = data->simulationInfo->realParameter[639];
    data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[2,1] variable */ = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[179].info /* MaterialStream2._xm_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[2,1] variable */);
  TRACE_POP
}

/*
 equation index: 293
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[2,1] = MaterialStream2.xg[1]
 */
void Flowsheet_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
  data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[2,1] variable */.start = data->simulationInfo->realParameter[639];
    data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */ = data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[172].info /* MaterialStream2._x_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */);
  TRACE_POP
}


/*
 equation index: 294
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = 0.0
 */
void Flowsheet_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
  data->simulationInfo->realParameter[647] = 0.0;
  TRACE_POP
}
/*
 equation index: 295
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = 1.0
 */
void Flowsheet_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
  data->simulationInfo->realParameter[647] = 1.0;
  TRACE_POP
}
/*
 equation index: 296
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = MaterialStream2.ymol[1]
 */
void Flowsheet_eqFunction_296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,296};
  data->simulationInfo->realParameter[647] = data->simulationInfo->realParameter[649];
  TRACE_POP
}
/*
 equation index: 297
 type: IFEQUATION
 
 equation index: 294
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = 0.0equation index: 295
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = 1.0
 equation index: 296
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = MaterialStream2.ymol[1]
 */
void Flowsheet_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,297};
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  tmp26 = Less(data->simulationInfo->realParameter[649],0.0);
  tmp27 = Greater(data->simulationInfo->realParameter[649],1.0);
  if(tmp26)
  {
    Flowsheet_eqFunction_294(data, threadData);
  }
  else if(tmp27)
  {
    Flowsheet_eqFunction_295(data, threadData);
  }else
  {
    Flowsheet_eqFunction_296(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 301
 type: LINEAR
 
 <var>MaterialStream2._Fliqg</var>
 <row>

 </row>
 <matrix>
 </matrix>
 */
void Flowsheet_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 301 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[2].x[0] = data->simulationInfo->realParameter[605];
  retValue = solve_linear_system(data, threadData, 2);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,301};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 301 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[605] = data->simulationInfo->linearSystemData[2].x[0];
  TRACE_POP
}

/*
 equation index: 302
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._F_p[3] = MaterialStream2.Fvapg
 */
void Flowsheet_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  data->modelData->realVarsData[109].attribute /* MaterialStream2._F_p[3] variable */.start = data->simulationInfo->realParameter[606];
    data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */ = data->modelData->realVarsData[109].attribute /* MaterialStream2._F_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[109].info /* MaterialStream2._F_p[3] */.name, (modelica_real) data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 303
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._F_p[2] = MaterialStream2.Fliqg
 */
void Flowsheet_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  data->modelData->realVarsData[108].attribute /* MaterialStream2._F_p[2] variable */.start = data->simulationInfo->realParameter[605];
    data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */ = data->modelData->realVarsData[108].attribute /* MaterialStream2._F_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[108].info /* MaterialStream2._F_p[2] */.name, (modelica_real) data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 304
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[3,1] = MaterialStream2.yg[1]
 */
void Flowsheet_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[3,1] variable */.start = data->simulationInfo->realParameter[647];
    data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[3,1] variable */ = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[181].info /* MaterialStream2._xm_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 305
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[3,1] = MaterialStream2.yg[1]
 */
void Flowsheet_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
  data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[3,1] variable */.start = data->simulationInfo->realParameter[647];
    data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[174].info /* MaterialStream2._x_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */);
  TRACE_POP
}



/*
 equation index: 306
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2] * MaterialStream2.K_guess[2] / (1.0 + (-1.0 + MaterialStream2.K_guess[2]) * MaterialStream2.xvapg)
 */
void Flowsheet_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
  modelica_real tmp31;
  tmp31 = 1.0 + (-1.0 + data->simulationInfo->realParameter[618]) * (data->simulationInfo->realParameter[646]);
  if (tmp31 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.K_guess[2] / (1.0 + (-1.0 + MaterialStream2.K_guess[2]) * MaterialStream2.xvapg)");}
  data->simulationInfo->realParameter[650] = (data->simulationInfo->realParameter[642]) * ((data->simulationInfo->realParameter[618]) / tmp31);
  TRACE_POP
}
/*
 equation index: 307
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2]
 */
void Flowsheet_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,307};
  data->simulationInfo->realParameter[650] = data->simulationInfo->realParameter[642];
  TRACE_POP
}
/*
 equation index: 308
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,308};
  data->simulationInfo->realParameter[650] = 0.0;
  TRACE_POP
}
/*
 equation index: 309
 type: IFEQUATION
 
 equation index: 306
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2] * MaterialStream2.K_guess[2] / (1.0 + (-1.0 + MaterialStream2.K_guess[2]) * MaterialStream2.xvapg)equation index: 307
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2]
 equation index: 308
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
  modelica_boolean tmp29;
  tmp29 = Greater(data->simulationInfo->realParameter[445],0.0);
  if((tmp29 && (data->simulationInfo->realParameter[445] != 1.0)))
  {
    Flowsheet_eqFunction_306(data, threadData);
  }
  else if((data->simulationInfo->realParameter[445] == 1.0))
  {
    Flowsheet_eqFunction_307(data, threadData);
  }else
  {
    Flowsheet_eqFunction_308(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 310
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.ymol[2] / MaterialStream2.K_guess[2]
 */
void Flowsheet_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
  modelica_real tmp35;
  tmp35 = data->simulationInfo->realParameter[618];
  if (tmp35 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.ymol[2] / MaterialStream2.K_guess[2]");}
  data->simulationInfo->realParameter[645] = (data->simulationInfo->realParameter[650]) / tmp35;
  TRACE_POP
}
/*
 equation index: 311
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.xguess[2]
 */
void Flowsheet_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
  data->simulationInfo->realParameter[645] = data->simulationInfo->realParameter[642];
  TRACE_POP
}
/*
 equation index: 312
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,312};
  data->simulationInfo->realParameter[645] = 0.0;
  TRACE_POP
}
/*
 equation index: 313
 type: IFEQUATION
 
 equation index: 310
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.ymol[2] / MaterialStream2.K_guess[2]equation index: 311
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.xguess[2]
 equation index: 312
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,313};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  tmp33 = Greater(data->simulationInfo->realParameter[445],0.0);
  tmp34 = Less(data->simulationInfo->realParameter[445],1.0);
  if((tmp33 && tmp34))
  {
    Flowsheet_eqFunction_310(data, threadData);
  }
  else if((data->simulationInfo->realParameter[445] == 0.0))
  {
    Flowsheet_eqFunction_311(data, threadData);
  }else
  {
    Flowsheet_eqFunction_312(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 314
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
  data->simulationInfo->realParameter[645] = 0.0;
  TRACE_POP
}

/*
 equation index: 315
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,315};
  data->simulationInfo->realParameter[650] = 0.0;
  TRACE_POP
}
/*
 equation index: 316
 type: IFEQUATION
 
 equation index: 309
 type: IFEQUATION
 
 equation index: 306
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2] * MaterialStream2.K_guess[2] / (1.0 + (-1.0 + MaterialStream2.K_guess[2]) * MaterialStream2.xvapg)equation index: 307
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2]
 equation index: 308
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0equation index: 313
 type: IFEQUATION
 
 equation index: 310
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.ymol[2] / MaterialStream2.K_guess[2]equation index: 311
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.xguess[2]
 equation index: 312
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0
 equation index: 314
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0equation index: 315
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  if((data->simulationInfo->realParameter[642] != 0.0))
  {
    Flowsheet_eqFunction_309(data, threadData);

    Flowsheet_eqFunction_313(data, threadData);
  }else
  {
    Flowsheet_eqFunction_314(data, threadData);
    Flowsheet_eqFunction_315(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 317
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = 0.0
 */
void Flowsheet_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
  data->simulationInfo->realParameter[640] = 0.0;
  TRACE_POP
}
/*
 equation index: 318
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = 1.0
 */
void Flowsheet_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  data->simulationInfo->realParameter[640] = 1.0;
  TRACE_POP
}
/*
 equation index: 319
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = MaterialStream2.xmol[2]
 */
void Flowsheet_eqFunction_319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,319};
  data->simulationInfo->realParameter[640] = data->simulationInfo->realParameter[645];
  TRACE_POP
}
/*
 equation index: 320
 type: IFEQUATION
 
 equation index: 317
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = 0.0equation index: 318
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = 1.0
 equation index: 319
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = MaterialStream2.xmol[2]
 */
void Flowsheet_eqFunction_320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,320};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  tmp37 = Less(data->simulationInfo->realParameter[645],0.0);
  tmp38 = Greater(data->simulationInfo->realParameter[640],1.0);
  if(tmp37)
  {
    Flowsheet_eqFunction_317(data, threadData);
  }
  else if(tmp38)
  {
    Flowsheet_eqFunction_318(data, threadData);
  }else
  {
    Flowsheet_eqFunction_319(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 321
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[2,2] = MaterialStream2.xg[2]
 */
void Flowsheet_eqFunction_321(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,321};
  data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[2,2] variable */.start = data->simulationInfo->realParameter[640];
    data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[2,2] variable */ = data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[180].info /* MaterialStream2._xm_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 322
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[2,2] = MaterialStream2.xg[2]
 */
void Flowsheet_eqFunction_322(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,322};
  data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[2,2] variable */.start = data->simulationInfo->realParameter[640];
    data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */ = data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[173].info /* MaterialStream2._x_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */);
  TRACE_POP
}


/*
 equation index: 323
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = 0.0
 */
void Flowsheet_eqFunction_323(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,323};
  data->simulationInfo->realParameter[648] = 0.0;
  TRACE_POP
}
/*
 equation index: 324
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = 1.0
 */
void Flowsheet_eqFunction_324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,324};
  data->simulationInfo->realParameter[648] = 1.0;
  TRACE_POP
}
/*
 equation index: 325
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = MaterialStream2.ymol[2]
 */
void Flowsheet_eqFunction_325(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,325};
  data->simulationInfo->realParameter[648] = data->simulationInfo->realParameter[650];
  TRACE_POP
}
/*
 equation index: 326
 type: IFEQUATION
 
 equation index: 323
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = 0.0equation index: 324
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = 1.0
 equation index: 325
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = MaterialStream2.ymol[2]
 */
void Flowsheet_eqFunction_326(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,326};
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  tmp39 = Less(data->simulationInfo->realParameter[650],0.0);
  tmp40 = Greater(data->simulationInfo->realParameter[650],1.0);
  if(tmp39)
  {
    Flowsheet_eqFunction_323(data, threadData);
  }
  else if(tmp40)
  {
    Flowsheet_eqFunction_324(data, threadData);
  }else
  {
    Flowsheet_eqFunction_325(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 327
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[3,2] = MaterialStream2.yg[2]
 */
void Flowsheet_eqFunction_327(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,327};
  data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[3,2] variable */.start = data->simulationInfo->realParameter[648];
    data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[3,2] variable */ = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[182].info /* MaterialStream2._xm_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 328
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[3,2] = MaterialStream2.yg[2]
 */
void Flowsheet_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,328};
  data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[3,2] variable */.start = data->simulationInfo->realParameter[648];
    data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[175].info /* MaterialStream2._x_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 329
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xmvap = MaterialStream2.xvapg
 */
void Flowsheet_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,329};
  data->modelData->realVarsData[184].attribute /* MaterialStream2._xmvap variable */.start = data->simulationInfo->realParameter[646];
    data->localData[0]->realVars[184] /* MaterialStream2._xmvap variable */ = data->modelData->realVarsData[184].attribute /* MaterialStream2._xmvap variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[184].info /* MaterialStream2._xmvap */.name, (modelica_real) data->localData[0]->realVars[184] /* MaterialStream2._xmvap variable */);
  TRACE_POP
}

/*
 equation index: 330
 type: SIMPLE_ASSIGN
 MaterialStream2._Hliqg = MaterialStream2.xguess[1] * MaterialStream2.Hcomplg[1] + MaterialStream2.xguess[2] * MaterialStream2.Hcomplg[2]
 */
void Flowsheet_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,330};
  data->simulationInfo->realParameter[613] = (data->simulationInfo->realParameter[641]) * (data->simulationInfo->realParameter[609]) + (data->simulationInfo->realParameter[642]) * (data->simulationInfo->realParameter[610]);
  TRACE_POP
}

/*
 equation index: 331
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._H_p[2] = MaterialStream2.Hliqg
 */
void Flowsheet_eqFunction_331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,331};
  data->modelData->realVarsData[126].attribute /* MaterialStream2._H_p[2] variable */.start = data->simulationInfo->realParameter[613];
    data->localData[0]->realVars[126] /* MaterialStream2._H_p[2] variable */ = data->modelData->realVarsData[126].attribute /* MaterialStream2._H_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[126].info /* MaterialStream2._H_p[2] */.name, (modelica_real) data->localData[0]->realVars[126] /* MaterialStream2._H_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 332
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Cp_p[2] = MaterialStream2.Hliqg
 */
void Flowsheet_eqFunction_332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,332};
  data->modelData->realVarsData[96].attribute /* MaterialStream2._Cp_p[2] variable */.start = data->simulationInfo->realParameter[613];
    data->localData[0]->realVars[96] /* MaterialStream2._Cp_p[2] variable */ = data->modelData->realVarsData[96].attribute /* MaterialStream2._Cp_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[96].info /* MaterialStream2._Cp_p[2] */.name, (modelica_real) data->localData[0]->realVars[96] /* MaterialStream2._Cp_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 333
 type: SIMPLE_ASSIGN
 MaterialStream2._Hvapg = MaterialStream2.xguess[1] * MaterialStream2.Hcompvg[1] + MaterialStream2.xguess[2] * MaterialStream2.Hcompvg[2]
 */
void Flowsheet_eqFunction_333(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,333};
  data->simulationInfo->realParameter[616] = (data->simulationInfo->realParameter[641]) * (data->simulationInfo->realParameter[611]) + (data->simulationInfo->realParameter[642]) * (data->simulationInfo->realParameter[612]);
  TRACE_POP
}

/*
 equation index: 334
 type: SIMPLE_ASSIGN
 MaterialStream2._Htotg = MaterialStream2.Hliqg + MaterialStream2.Hvapg
 */
void Flowsheet_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  data->simulationInfo->realParameter[615] = data->simulationInfo->realParameter[613] + data->simulationInfo->realParameter[616];
  TRACE_POP
}

/*
 equation index: 335
 type: SIMPLE_ASSIGN
 MaterialStream2._Hmixg = MaterialStream2.Htotg
 */
void Flowsheet_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  data->simulationInfo->realParameter[614] = data->simulationInfo->realParameter[615];
  TRACE_POP
}

/*
 equation index: 336
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._H_p[1] = MaterialStream2.Hmixg
 */
void Flowsheet_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  data->modelData->realVarsData[125].attribute /* MaterialStream2._H_p[1] variable */.start = data->simulationInfo->realParameter[614];
    data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */ = data->modelData->realVarsData[125].attribute /* MaterialStream2._H_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[125].info /* MaterialStream2._H_p[1] */.name, (modelica_real) data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 337
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Cp_p[1] = MaterialStream2.Hmixg
 */
void Flowsheet_eqFunction_337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,337};
  data->modelData->realVarsData[95].attribute /* MaterialStream2._Cp_p[1] variable */.start = data->simulationInfo->realParameter[614];
    data->localData[0]->realVars[95] /* MaterialStream2._Cp_p[1] variable */ = data->modelData->realVarsData[95].attribute /* MaterialStream2._Cp_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[95].info /* MaterialStream2._Cp_p[1] */.name, (modelica_real) data->localData[0]->realVars[95] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 338
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcompg[1] = MaterialStream2.xguess[1] * MaterialStream2.Htotg
 */
void Flowsheet_eqFunction_338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,338};
  data->simulationInfo->realParameter[607] = (data->simulationInfo->realParameter[641]) * (data->simulationInfo->realParameter[615]);
  TRACE_POP
}

/*
 equation index: 339
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcompg[2] = MaterialStream2.xguess[2] * MaterialStream2.Htotg
 */
void Flowsheet_eqFunction_339(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,339};
  data->simulationInfo->realParameter[608] = (data->simulationInfo->realParameter[642]) * (data->simulationInfo->realParameter[615]);
  TRACE_POP
}

/*
 equation index: 340
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._H_p[3] = MaterialStream2.Hvapg
 */
void Flowsheet_eqFunction_340(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,340};
  data->modelData->realVarsData[127].attribute /* MaterialStream2._H_p[3] variable */.start = data->simulationInfo->realParameter[616];
    data->localData[0]->realVars[127] /* MaterialStream2._H_p[3] variable */ = data->modelData->realVarsData[127].attribute /* MaterialStream2._H_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[127].info /* MaterialStream2._H_p[3] */.name, (modelica_real) data->localData[0]->realVars[127] /* MaterialStream2._H_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 341
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Cp_p[3] = MaterialStream2.Hvapg
 */
void Flowsheet_eqFunction_341(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,341};
  data->modelData->realVarsData[97].attribute /* MaterialStream2._Cp_p[3] variable */.start = data->simulationInfo->realParameter[616];
    data->localData[0]->realVars[97] /* MaterialStream2._Cp_p[3] variable */ = data->modelData->realVarsData[97].attribute /* MaterialStream2._Cp_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[97].info /* MaterialStream2._Cp_p[3] */.name, (modelica_real) data->localData[0]->realVars[97] /* MaterialStream2._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 342
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[1,1] = MaterialStream2.xguess[1]
 */
void Flowsheet_eqFunction_342(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,342};
  data->modelData->realVarsData[177].attribute /* MaterialStream2._xm_pc[1,1] variable */.start = data->simulationInfo->realParameter[641];
    data->localData[0]->realVars[177] /* MaterialStream2._xm_pc[1,1] variable */ = data->modelData->realVarsData[177].attribute /* MaterialStream2._xm_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[177].info /* MaterialStream2._xm_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[177] /* MaterialStream2._xm_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 343
 type: SIMPLE_ASSIGN
 MaterialStream1._xguess[2] = 0.5
 */
void Flowsheet_eqFunction_343(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,343};
  data->simulationInfo->realParameter[435] = 0.5;
  TRACE_POP
}

/*
 equation index: 344
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[1,2] = MaterialStream1.xguess[2]
 */
void Flowsheet_eqFunction_344(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,344};
  data->modelData->realVarsData[88].attribute /* MaterialStream1._xm_pc[1,2] variable */.start = data->simulationInfo->realParameter[435];
    data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */ = data->modelData->realVarsData[88].attribute /* MaterialStream1._xm_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[88].info /* MaterialStream1._xm_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 345
 type: SIMPLE_ASSIGN
 MaterialStream1._xguess[1] = 0.5
 */
void Flowsheet_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,345};
  data->simulationInfo->realParameter[434] = 0.5;
  TRACE_POP
}

void Flowsheet_eqFunction_346(DATA*,threadData_t*);
void Flowsheet_eqFunction_347(DATA*,threadData_t*);
void Flowsheet_eqFunction_348(DATA*,threadData_t*);
/*
 equation index: 349
 indexNonlinear: 6
 type: NONLINEAR
 
 vars: {MaterialStream1._Tdg}
 eqns: {346, 347, 348}
 */
void Flowsheet_eqFunction_349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,349};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 349 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[6].nlsxOld[0] = data->simulationInfo->realParameter[429];
  retValue = solve_nonlinear_system(data, threadData, 6);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,349};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 349 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[429] = data->simulationInfo->nonlinearSystemData[6].nlsx[0];
  TRACE_POP
}

void Flowsheet_eqFunction_350(DATA*,threadData_t*);
void Flowsheet_eqFunction_351(DATA*,threadData_t*);
void Flowsheet_eqFunction_352(DATA*,threadData_t*);
/*
 equation index: 353
 indexNonlinear: 7
 type: NONLINEAR
 
 vars: {MaterialStream1._Tbg}
 eqns: {350, 351, 352}
 */
void Flowsheet_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 353 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[7].nlsxOld[0] = data->simulationInfo->realParameter[426];
  retValue = solve_nonlinear_system(data, threadData, 7);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,353};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 353 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[426] = data->simulationInfo->nonlinearSystemData[7].nlsx[0];
  TRACE_POP
}

/*
 equation index: 354
 type: SIMPLE_ASSIGN
 MaterialStream1._Temp = 0.5 * (MaterialStream1.Tbg + MaterialStream1.Tdg)
 */
void Flowsheet_eqFunction_354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,354};
  data->simulationInfo->realParameter[430] = (0.5) * (data->simulationInfo->realParameter[426] + data->simulationInfo->realParameter[429]);
  TRACE_POP
}

/*
 equation index: 355
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatt[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[1].VP[1], MaterialStream1.C[1].VP[2], MaterialStream1.C[1].VP[3], MaterialStream1.C[1].VP[4], MaterialStream1.C[1].VP[5], MaterialStream1.C[1].VP[6]}, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_355(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,355};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[347], (modelica_real)data->simulationInfo->realParameter[348], (modelica_real)data->simulationInfo->realParameter[349], (modelica_real)data->simulationInfo->realParameter[350], (modelica_real)data->simulationInfo->realParameter[351], (modelica_real)data->simulationInfo->realParameter[352]);
  data->simulationInfo->realParameter[419] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[430]);
  TRACE_POP
}

/*
 equation index: 356
 type: SIMPLE_ASSIGN
 MaterialStream1._K_guess[1] = DIVISION(MaterialStream1.Psatt[1], MaterialStream1.Pg)
 */
void Flowsheet_eqFunction_356(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,356};
  data->simulationInfo->realParameter[410] = DIVISION_SIM(data->simulationInfo->realParameter[419],data->simulationInfo->realParameter[412],"MaterialStream1.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 357
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatt[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[2].VP[1], MaterialStream1.C[2].VP[2], MaterialStream1.C[2].VP[3], MaterialStream1.C[2].VP[4], MaterialStream1.C[2].VP[5], MaterialStream1.C[2].VP[6]}, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_357(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,357};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[353], (modelica_real)data->simulationInfo->realParameter[354], (modelica_real)data->simulationInfo->realParameter[355], (modelica_real)data->simulationInfo->realParameter[356], (modelica_real)data->simulationInfo->realParameter[357], (modelica_real)data->simulationInfo->realParameter[358]);
  data->simulationInfo->realParameter[420] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp1, data->simulationInfo->realParameter[430]);
  TRACE_POP
}

/*
 equation index: 358
 type: SIMPLE_ASSIGN
 MaterialStream1._K_guess[2] = DIVISION(MaterialStream1.Psatt[2], MaterialStream1.Pg)
 */
void Flowsheet_eqFunction_358(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,358};
  data->simulationInfo->realParameter[411] = DIVISION_SIM(data->simulationInfo->realParameter[420],data->simulationInfo->realParameter[412],"MaterialStream1.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 359
 type: SIMPLE_ASSIGN
 MaterialStream1._Pxc[2] = DIVISION(MaterialStream1.xguess[2], MaterialStream1.Psatt[2])
 */
void Flowsheet_eqFunction_359(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,359};
  data->simulationInfo->realParameter[423] = DIVISION_SIM(data->simulationInfo->realParameter[435],data->simulationInfo->realParameter[420],"MaterialStream1.Psatt[2]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 360
 type: SIMPLE_ASSIGN
 MaterialStream1._Pxm[2] = MaterialStream1.xguess[2] * MaterialStream1.Psatt[2]
 */
void Flowsheet_eqFunction_360(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,360};
  data->simulationInfo->realParameter[425] = (data->simulationInfo->realParameter[435]) * (data->simulationInfo->realParameter[420]);
  TRACE_POP
}

/*
 equation index: 361
 type: SIMPLE_ASSIGN
 MaterialStream1._Tg = MaterialStream1.Temp
 */
void Flowsheet_eqFunction_361(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,361};
  data->simulationInfo->realParameter[431] = data->simulationInfo->realParameter[430];
  TRACE_POP
}

/*
 equation index: 362
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcomplg[1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream1.C[1].SH, {MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tc, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_362(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,362};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[259], (modelica_real)data->simulationInfo->realParameter[260], (modelica_real)data->simulationInfo->realParameter[261], (modelica_real)data->simulationInfo->realParameter[262], (modelica_real)data->simulationInfo->realParameter[263], (modelica_real)data->simulationInfo->realParameter[264]);
  data->simulationInfo->realParameter[402] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[329], tmp2, tmp3, data->simulationInfo->realParameter[339], data->simulationInfo->realParameter[430]);
  TRACE_POP
}

/*
 equation index: 363
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcompvg[1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream1.C[1].SH, {MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tc, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_363(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,363};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[259], (modelica_real)data->simulationInfo->realParameter[260], (modelica_real)data->simulationInfo->realParameter[261], (modelica_real)data->simulationInfo->realParameter[262], (modelica_real)data->simulationInfo->realParameter[263], (modelica_real)data->simulationInfo->realParameter[264]);
  data->simulationInfo->realParameter[404] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[329], tmp4, tmp5, data->simulationInfo->realParameter[339], data->simulationInfo->realParameter[430]);
  TRACE_POP
}

/*
 equation index: 364
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcomplg[2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream1.C[2].SH, {MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tc, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_364(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,364};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[265], (modelica_real)data->simulationInfo->realParameter[266], (modelica_real)data->simulationInfo->realParameter[267], (modelica_real)data->simulationInfo->realParameter[268], (modelica_real)data->simulationInfo->realParameter[269], (modelica_real)data->simulationInfo->realParameter[270]);
  data->simulationInfo->realParameter[403] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[330], tmp6, tmp7, data->simulationInfo->realParameter[340], data->simulationInfo->realParameter[430]);
  TRACE_POP
}

/*
 equation index: 365
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcompvg[2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream1.C[2].SH, {MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tc, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_365(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,365};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[265], (modelica_real)data->simulationInfo->realParameter[266], (modelica_real)data->simulationInfo->realParameter[267], (modelica_real)data->simulationInfo->realParameter[268], (modelica_real)data->simulationInfo->realParameter[269], (modelica_real)data->simulationInfo->realParameter[270]);
  data->simulationInfo->realParameter[405] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[330], tmp8, tmp9, data->simulationInfo->realParameter[340], data->simulationInfo->realParameter[430]);
  TRACE_POP
}

/*
 equation index: 366
 type: SIMPLE_ASSIGN
 MaterialStream1._Pxc[1] = DIVISION(MaterialStream1.xguess[1], MaterialStream1.Psatt[1])
 */
void Flowsheet_eqFunction_366(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,366};
  data->simulationInfo->realParameter[422] = DIVISION_SIM(data->simulationInfo->realParameter[434],data->simulationInfo->realParameter[419],"MaterialStream1.Psatt[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 367
 type: SIMPLE_ASSIGN
 MaterialStream1._Px = MaterialStream1.Pxc[1] + MaterialStream1.Pxc[2]
 */
void Flowsheet_eqFunction_367(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,367};
  data->simulationInfo->realParameter[421] = data->simulationInfo->realParameter[422] + data->simulationInfo->realParameter[423];
  TRACE_POP
}

/*
 equation index: 368
 type: SIMPLE_ASSIGN
 MaterialStream1._Pmin = DIVISION(1.0, MaterialStream1.Px)
 */
void Flowsheet_eqFunction_368(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,368};
  data->simulationInfo->realParameter[414] = DIVISION_SIM(1.0,data->simulationInfo->realParameter[421],"MaterialStream1.Px",equationIndexes);
  TRACE_POP
}

/*
 equation index: 369
 type: SIMPLE_ASSIGN
 MaterialStream1._Pxm[1] = MaterialStream1.xguess[1] * MaterialStream1.Psatt[1]
 */
void Flowsheet_eqFunction_369(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,369};
  data->simulationInfo->realParameter[424] = (data->simulationInfo->realParameter[434]) * (data->simulationInfo->realParameter[419]);
  TRACE_POP
}

/*
 equation index: 370
 type: SIMPLE_ASSIGN
 MaterialStream1._Pmax = MaterialStream1.Pxm[1] + MaterialStream1.Pxm[2]
 */
void Flowsheet_eqFunction_370(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,370};
  data->simulationInfo->realParameter[413] = data->simulationInfo->realParameter[424] + data->simulationInfo->realParameter[425];
  TRACE_POP
}


/*
 equation index: 371
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = 0.0
 */
void Flowsheet_eqFunction_371(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,371};
  data->simulationInfo->realParameter[439] = 0.0;
  TRACE_POP
}
/*
 equation index: 372
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = (MaterialStream1.Pg - MaterialStream1.Pmin) / (MaterialStream1.Pmax - MaterialStream1.Pmin)
 */
void Flowsheet_eqFunction_372(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,372};
  modelica_real tmp12;
  tmp12 = data->simulationInfo->realParameter[413] - data->simulationInfo->realParameter[414];
  if (tmp12 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(MaterialStream1.Pg - MaterialStream1.Pmin) / (MaterialStream1.Pmax - MaterialStream1.Pmin)");}
  data->simulationInfo->realParameter[439] = (data->simulationInfo->realParameter[412] - data->simulationInfo->realParameter[414]) / tmp12;
  TRACE_POP
}
/*
 equation index: 373
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = 1.0
 */
void Flowsheet_eqFunction_373(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,373};
  data->simulationInfo->realParameter[439] = 1.0;
  TRACE_POP
}
/*
 equation index: 374
 type: IFEQUATION
 
 equation index: 371
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = 0.0equation index: 372
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = (MaterialStream1.Pg - MaterialStream1.Pmin) / (MaterialStream1.Pmax - MaterialStream1.Pmin)
 equation index: 373
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = 1.0
 */
void Flowsheet_eqFunction_374(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,374};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  tmp10 = GreaterEq(data->simulationInfo->realParameter[412],data->simulationInfo->realParameter[413]);
  tmp11 = GreaterEq(data->simulationInfo->realParameter[412],data->simulationInfo->realParameter[414]);
  if(tmp10)
  {
    Flowsheet_eqFunction_371(data, threadData);
  }
  else if(tmp11)
  {
    Flowsheet_eqFunction_372(data, threadData);
  }else
  {
    Flowsheet_eqFunction_373(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 375
 type: SIMPLE_ASSIGN
 MaterialStream1._xliqg = 1.0 - MaterialStream1.xvapg
 */
void Flowsheet_eqFunction_375(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,375};
  data->simulationInfo->realParameter[436] = 1.0 - data->simulationInfo->realParameter[439];
  TRACE_POP
}

/*
 equation index: 376
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xmliq = MaterialStream1.xliqg
 */
void Flowsheet_eqFunction_376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,376};
  data->modelData->realVarsData[93].attribute /* MaterialStream1._xmliq variable */.start = data->simulationInfo->realParameter[436];
    data->localData[0]->realVars[93] /* MaterialStream1._xmliq variable */ = data->modelData->realVarsData[93].attribute /* MaterialStream1._xmliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[93].info /* MaterialStream1._xmliq */.name, (modelica_real) data->localData[0]->realVars[93] /* MaterialStream1._xmliq variable */);
  TRACE_POP
}

/*
 equation index: 377
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xliq = MaterialStream1.xliqg
 */
void Flowsheet_eqFunction_377(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,377};
  data->modelData->realVarsData[86].attribute /* MaterialStream1._xliq variable */.start = data->simulationInfo->realParameter[436];
    data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */ = data->modelData->realVarsData[86].attribute /* MaterialStream1._xliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[86].info /* MaterialStream1._xliq */.name, (modelica_real) data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */);
  TRACE_POP
}


/*
 equation index: 378
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = 1.0
 */
void Flowsheet_eqFunction_378(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,378};
  data->simulationInfo->realParameter[238] = 1.0;
  TRACE_POP
}
/*
 equation index: 379
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = 0.0
 */
void Flowsheet_eqFunction_379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,379};
  data->simulationInfo->realParameter[238] = 0.0;
  TRACE_POP
}
/*
 equation index: 380
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = MaterialStream1.xvapg
 */
void Flowsheet_eqFunction_380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,380};
  data->simulationInfo->realParameter[238] = data->simulationInfo->realParameter[439];
  TRACE_POP
}
/*
 equation index: 381
 type: IFEQUATION
 
 equation index: 378
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = 1.0equation index: 379
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = 0.0
 equation index: 380
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = MaterialStream1.xvapg
 */
void Flowsheet_eqFunction_381(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,381};
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  tmp13 = Greater(data->simulationInfo->realParameter[439],1.0);
  tmp14 = Less(data->simulationInfo->realParameter[439],0.0);
  if(tmp13)
  {
    Flowsheet_eqFunction_378(data, threadData);
  }
  else if(tmp14)
  {
    Flowsheet_eqFunction_379(data, threadData);
  }else
  {
    Flowsheet_eqFunction_380(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 382
 type: SIMPLE_ASSIGN
 MaterialStream1._Alpha = 1.0 - MaterialStream1.Beta
 */
void Flowsheet_eqFunction_382(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,382};
  data->simulationInfo->realParameter[237] = 1.0 - data->simulationInfo->realParameter[238];
  TRACE_POP
}



/*
 equation index: 383
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1] * MaterialStream1.K_guess[1] / (1.0 + (-1.0 + MaterialStream1.K_guess[1]) * MaterialStream1.xvapg)
 */
void Flowsheet_eqFunction_383(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,383};
  modelica_real tmp18;
  tmp18 = 1.0 + (-1.0 + data->simulationInfo->realParameter[410]) * (data->simulationInfo->realParameter[439]);
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.K_guess[1] / (1.0 + (-1.0 + MaterialStream1.K_guess[1]) * MaterialStream1.xvapg)");}
  data->simulationInfo->realParameter[442] = (data->simulationInfo->realParameter[434]) * ((data->simulationInfo->realParameter[410]) / tmp18);
  TRACE_POP
}
/*
 equation index: 384
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1]
 */
void Flowsheet_eqFunction_384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,384};
  data->simulationInfo->realParameter[442] = data->simulationInfo->realParameter[434];
  TRACE_POP
}
/*
 equation index: 385
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_385(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,385};
  data->simulationInfo->realParameter[442] = 0.0;
  TRACE_POP
}
/*
 equation index: 386
 type: IFEQUATION
 
 equation index: 383
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1] * MaterialStream1.K_guess[1] / (1.0 + (-1.0 + MaterialStream1.K_guess[1]) * MaterialStream1.xvapg)equation index: 384
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1]
 equation index: 385
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_386(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,386};
  modelica_boolean tmp16;
  tmp16 = Greater(data->simulationInfo->realParameter[238],0.0);
  if((tmp16 && (data->simulationInfo->realParameter[238] != 1.0)))
  {
    Flowsheet_eqFunction_383(data, threadData);
  }
  else if((data->simulationInfo->realParameter[238] == 1.0))
  {
    Flowsheet_eqFunction_384(data, threadData);
  }else
  {
    Flowsheet_eqFunction_385(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 387
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.ymol[1] / MaterialStream1.K_guess[1]
 */
void Flowsheet_eqFunction_387(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,387};
  modelica_real tmp22;
  tmp22 = data->simulationInfo->realParameter[410];
  if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.ymol[1] / MaterialStream1.K_guess[1]");}
  data->simulationInfo->realParameter[437] = (data->simulationInfo->realParameter[442]) / tmp22;
  TRACE_POP
}
/*
 equation index: 388
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.xguess[1]
 */
void Flowsheet_eqFunction_388(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,388};
  data->simulationInfo->realParameter[437] = data->simulationInfo->realParameter[434];
  TRACE_POP
}
/*
 equation index: 389
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_389(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,389};
  data->simulationInfo->realParameter[437] = 0.0;
  TRACE_POP
}
/*
 equation index: 390
 type: IFEQUATION
 
 equation index: 387
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.ymol[1] / MaterialStream1.K_guess[1]equation index: 388
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.xguess[1]
 equation index: 389
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_390(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,390};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  tmp20 = Greater(data->simulationInfo->realParameter[238],0.0);
  tmp21 = Less(data->simulationInfo->realParameter[238],1.0);
  if((tmp20 && tmp21))
  {
    Flowsheet_eqFunction_387(data, threadData);
  }
  else if((data->simulationInfo->realParameter[238] == 0.0))
  {
    Flowsheet_eqFunction_388(data, threadData);
  }else
  {
    Flowsheet_eqFunction_389(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 391
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_391(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,391};
  data->simulationInfo->realParameter[437] = 0.0;
  TRACE_POP
}

/*
 equation index: 392
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_392(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,392};
  data->simulationInfo->realParameter[442] = 0.0;
  TRACE_POP
}
/*
 equation index: 393
 type: IFEQUATION
 
 equation index: 386
 type: IFEQUATION
 
 equation index: 383
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1] * MaterialStream1.K_guess[1] / (1.0 + (-1.0 + MaterialStream1.K_guess[1]) * MaterialStream1.xvapg)equation index: 384
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1]
 equation index: 385
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0equation index: 390
 type: IFEQUATION
 
 equation index: 387
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.ymol[1] / MaterialStream1.K_guess[1]equation index: 388
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.xguess[1]
 equation index: 389
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0
 equation index: 391
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0equation index: 392
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,393};
  if((data->simulationInfo->realParameter[434] != 0.0))
  {
    Flowsheet_eqFunction_386(data, threadData);

    Flowsheet_eqFunction_390(data, threadData);
  }else
  {
    Flowsheet_eqFunction_391(data, threadData);
    Flowsheet_eqFunction_392(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 394
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = 0.0
 */
void Flowsheet_eqFunction_394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,394};
  data->simulationInfo->realParameter[440] = 0.0;
  TRACE_POP
}
/*
 equation index: 395
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = 1.0
 */
void Flowsheet_eqFunction_395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,395};
  data->simulationInfo->realParameter[440] = 1.0;
  TRACE_POP
}
/*
 equation index: 396
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = MaterialStream1.ymol[1]
 */
void Flowsheet_eqFunction_396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,396};
  data->simulationInfo->realParameter[440] = data->simulationInfo->realParameter[442];
  TRACE_POP
}
/*
 equation index: 397
 type: IFEQUATION
 
 equation index: 394
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = 0.0equation index: 395
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = 1.0
 equation index: 396
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = MaterialStream1.ymol[1]
 */
void Flowsheet_eqFunction_397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,397};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  tmp24 = Less(data->simulationInfo->realParameter[442],0.0);
  tmp25 = Greater(data->simulationInfo->realParameter[442],1.0);
  if(tmp24)
  {
    Flowsheet_eqFunction_394(data, threadData);
  }
  else if(tmp25)
  {
    Flowsheet_eqFunction_395(data, threadData);
  }else
  {
    Flowsheet_eqFunction_396(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 398
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[3,1] = MaterialStream1.yg[1]
 */
void Flowsheet_eqFunction_398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,398};
  data->modelData->realVarsData[91].attribute /* MaterialStream1._xm_pc[3,1] variable */.start = data->simulationInfo->realParameter[440];
    data->localData[0]->realVars[91] /* MaterialStream1._xm_pc[3,1] variable */ = data->modelData->realVarsData[91].attribute /* MaterialStream1._xm_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[91].info /* MaterialStream1._xm_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[91] /* MaterialStream1._xm_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 399
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[3,1] = MaterialStream1.yg[1]
 */
void Flowsheet_eqFunction_399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,399};
  data->modelData->realVarsData[84].attribute /* MaterialStream1._x_pc[3,1] variable */.start = data->simulationInfo->realParameter[440];
    data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ = data->modelData->realVarsData[84].attribute /* MaterialStream1._x_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[84].info /* MaterialStream1._x_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */);
  TRACE_POP
}


/*
 equation index: 400
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = 0.0
 */
void Flowsheet_eqFunction_400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,400};
  data->simulationInfo->realParameter[432] = 0.0;
  TRACE_POP
}
/*
 equation index: 401
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = 1.0
 */
void Flowsheet_eqFunction_401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,401};
  data->simulationInfo->realParameter[432] = 1.0;
  TRACE_POP
}
/*
 equation index: 402
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = MaterialStream1.xmol[1]
 */
void Flowsheet_eqFunction_402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,402};
  data->simulationInfo->realParameter[432] = data->simulationInfo->realParameter[437];
  TRACE_POP
}
/*
 equation index: 403
 type: IFEQUATION
 
 equation index: 400
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = 0.0equation index: 401
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = 1.0
 equation index: 402
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = MaterialStream1.xmol[1]
 */
void Flowsheet_eqFunction_403(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,403};
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  tmp26 = Less(data->simulationInfo->realParameter[437],0.0);
  tmp27 = Greater(data->simulationInfo->realParameter[432],1.0);
  if(tmp26)
  {
    Flowsheet_eqFunction_400(data, threadData);
  }
  else if(tmp27)
  {
    Flowsheet_eqFunction_401(data, threadData);
  }else
  {
    Flowsheet_eqFunction_402(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 407
 type: LINEAR
 
 <var>MaterialStream1._Fvapg</var>
 <row>

 </row>
 <matrix>
 </matrix>
 */
void Flowsheet_eqFunction_407(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,407};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 407 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[3].x[0] = data->simulationInfo->realParameter[399];
  retValue = solve_linear_system(data, threadData, 3);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,407};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 407 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[399] = data->simulationInfo->linearSystemData[3].x[0];
  TRACE_POP
}

/*
 equation index: 408
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._F_p[2] = MaterialStream1.Fliqg
 */
void Flowsheet_eqFunction_408(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,408};
  data->modelData->realVarsData[18].attribute /* MaterialStream1._F_p[2] variable */.start = data->simulationInfo->realParameter[398];
    data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */ = data->modelData->realVarsData[18].attribute /* MaterialStream1._F_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[18].info /* MaterialStream1._F_p[2] */.name, (modelica_real) data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 409
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._F_p[3] = MaterialStream1.Fvapg
 */
void Flowsheet_eqFunction_409(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,409};
  data->modelData->realVarsData[19].attribute /* MaterialStream1._F_p[3] variable */.start = data->simulationInfo->realParameter[399];
    data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */ = data->modelData->realVarsData[19].attribute /* MaterialStream1._F_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[19].info /* MaterialStream1._F_p[3] */.name, (modelica_real) data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 410
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[2,1] = MaterialStream1.xg[1]
 */
void Flowsheet_eqFunction_410(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,410};
  data->modelData->realVarsData[89].attribute /* MaterialStream1._xm_pc[2,1] variable */.start = data->simulationInfo->realParameter[432];
    data->localData[0]->realVars[89] /* MaterialStream1._xm_pc[2,1] variable */ = data->modelData->realVarsData[89].attribute /* MaterialStream1._xm_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[89].info /* MaterialStream1._xm_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[89] /* MaterialStream1._xm_pc[2,1] variable */);
  TRACE_POP
}

/*
 equation index: 411
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[2,1] = MaterialStream1.xg[1]
 */
void Flowsheet_eqFunction_411(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,411};
  data->modelData->realVarsData[82].attribute /* MaterialStream1._x_pc[2,1] variable */.start = data->simulationInfo->realParameter[432];
    data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */ = data->modelData->realVarsData[82].attribute /* MaterialStream1._x_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[82].info /* MaterialStream1._x_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */);
  TRACE_POP
}



/*
 equation index: 412
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2] * MaterialStream1.K_guess[2] / (1.0 + (-1.0 + MaterialStream1.K_guess[2]) * MaterialStream1.xvapg)
 */
void Flowsheet_eqFunction_412(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,412};
  modelica_real tmp31;
  tmp31 = 1.0 + (-1.0 + data->simulationInfo->realParameter[411]) * (data->simulationInfo->realParameter[439]);
  if (tmp31 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.K_guess[2] / (1.0 + (-1.0 + MaterialStream1.K_guess[2]) * MaterialStream1.xvapg)");}
  data->simulationInfo->realParameter[443] = (data->simulationInfo->realParameter[435]) * ((data->simulationInfo->realParameter[411]) / tmp31);
  TRACE_POP
}
/*
 equation index: 413
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2]
 */
void Flowsheet_eqFunction_413(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,413};
  data->simulationInfo->realParameter[443] = data->simulationInfo->realParameter[435];
  TRACE_POP
}
/*
 equation index: 414
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_414(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,414};
  data->simulationInfo->realParameter[443] = 0.0;
  TRACE_POP
}
/*
 equation index: 415
 type: IFEQUATION
 
 equation index: 412
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2] * MaterialStream1.K_guess[2] / (1.0 + (-1.0 + MaterialStream1.K_guess[2]) * MaterialStream1.xvapg)equation index: 413
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2]
 equation index: 414
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_415(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,415};
  modelica_boolean tmp29;
  tmp29 = Greater(data->simulationInfo->realParameter[238],0.0);
  if((tmp29 && (data->simulationInfo->realParameter[238] != 1.0)))
  {
    Flowsheet_eqFunction_412(data, threadData);
  }
  else if((data->simulationInfo->realParameter[238] == 1.0))
  {
    Flowsheet_eqFunction_413(data, threadData);
  }else
  {
    Flowsheet_eqFunction_414(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 416
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.ymol[2] / MaterialStream1.K_guess[2]
 */
void Flowsheet_eqFunction_416(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,416};
  modelica_real tmp35;
  tmp35 = data->simulationInfo->realParameter[411];
  if (tmp35 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.ymol[2] / MaterialStream1.K_guess[2]");}
  data->simulationInfo->realParameter[438] = (data->simulationInfo->realParameter[443]) / tmp35;
  TRACE_POP
}
/*
 equation index: 417
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.xguess[2]
 */
void Flowsheet_eqFunction_417(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,417};
  data->simulationInfo->realParameter[438] = data->simulationInfo->realParameter[435];
  TRACE_POP
}
/*
 equation index: 418
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_418(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,418};
  data->simulationInfo->realParameter[438] = 0.0;
  TRACE_POP
}
/*
 equation index: 419
 type: IFEQUATION
 
 equation index: 416
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.ymol[2] / MaterialStream1.K_guess[2]equation index: 417
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.xguess[2]
 equation index: 418
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_419(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,419};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  tmp33 = Greater(data->simulationInfo->realParameter[238],0.0);
  tmp34 = Less(data->simulationInfo->realParameter[238],1.0);
  if((tmp33 && tmp34))
  {
    Flowsheet_eqFunction_416(data, threadData);
  }
  else if((data->simulationInfo->realParameter[238] == 0.0))
  {
    Flowsheet_eqFunction_417(data, threadData);
  }else
  {
    Flowsheet_eqFunction_418(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 420
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_420(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,420};
  data->simulationInfo->realParameter[438] = 0.0;
  TRACE_POP
}

/*
 equation index: 421
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_421(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,421};
  data->simulationInfo->realParameter[443] = 0.0;
  TRACE_POP
}
/*
 equation index: 422
 type: IFEQUATION
 
 equation index: 415
 type: IFEQUATION
 
 equation index: 412
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2] * MaterialStream1.K_guess[2] / (1.0 + (-1.0 + MaterialStream1.K_guess[2]) * MaterialStream1.xvapg)equation index: 413
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2]
 equation index: 414
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0equation index: 419
 type: IFEQUATION
 
 equation index: 416
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.ymol[2] / MaterialStream1.K_guess[2]equation index: 417
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.xguess[2]
 equation index: 418
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0
 equation index: 420
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0equation index: 421
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_422(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,422};
  if((data->simulationInfo->realParameter[435] != 0.0))
  {
    Flowsheet_eqFunction_415(data, threadData);

    Flowsheet_eqFunction_419(data, threadData);
  }else
  {
    Flowsheet_eqFunction_420(data, threadData);
    Flowsheet_eqFunction_421(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 423
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = 0.0
 */
void Flowsheet_eqFunction_423(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,423};
  data->simulationInfo->realParameter[441] = 0.0;
  TRACE_POP
}
/*
 equation index: 424
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = 1.0
 */
void Flowsheet_eqFunction_424(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,424};
  data->simulationInfo->realParameter[441] = 1.0;
  TRACE_POP
}
/*
 equation index: 425
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = MaterialStream1.ymol[2]
 */
void Flowsheet_eqFunction_425(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,425};
  data->simulationInfo->realParameter[441] = data->simulationInfo->realParameter[443];
  TRACE_POP
}
/*
 equation index: 426
 type: IFEQUATION
 
 equation index: 423
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = 0.0equation index: 424
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = 1.0
 equation index: 425
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = MaterialStream1.ymol[2]
 */
void Flowsheet_eqFunction_426(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,426};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  tmp37 = Less(data->simulationInfo->realParameter[443],0.0);
  tmp38 = Greater(data->simulationInfo->realParameter[443],1.0);
  if(tmp37)
  {
    Flowsheet_eqFunction_423(data, threadData);
  }
  else if(tmp38)
  {
    Flowsheet_eqFunction_424(data, threadData);
  }else
  {
    Flowsheet_eqFunction_425(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 427
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[3,2] = MaterialStream1.yg[2]
 */
void Flowsheet_eqFunction_427(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,427};
  data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[3,2] variable */.start = data->simulationInfo->realParameter[441];
    data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[3,2] variable */ = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[92].info /* MaterialStream1._xm_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 428
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[3,2] = MaterialStream1.yg[2]
 */
void Flowsheet_eqFunction_428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,428};
  data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[3,2] variable */.start = data->simulationInfo->realParameter[441];
    data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ = data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[85].info /* MaterialStream1._x_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */);
  TRACE_POP
}


/*
 equation index: 429
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = 0.0
 */
void Flowsheet_eqFunction_429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,429};
  data->simulationInfo->realParameter[433] = 0.0;
  TRACE_POP
}
/*
 equation index: 430
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = 1.0
 */
void Flowsheet_eqFunction_430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,430};
  data->simulationInfo->realParameter[433] = 1.0;
  TRACE_POP
}
/*
 equation index: 431
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = MaterialStream1.xmol[2]
 */
void Flowsheet_eqFunction_431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,431};
  data->simulationInfo->realParameter[433] = data->simulationInfo->realParameter[438];
  TRACE_POP
}
/*
 equation index: 432
 type: IFEQUATION
 
 equation index: 429
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = 0.0equation index: 430
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = 1.0
 equation index: 431
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = MaterialStream1.xmol[2]
 */
void Flowsheet_eqFunction_432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,432};
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  tmp39 = Less(data->simulationInfo->realParameter[438],0.0);
  tmp40 = Greater(data->simulationInfo->realParameter[433],1.0);
  if(tmp39)
  {
    Flowsheet_eqFunction_429(data, threadData);
  }
  else if(tmp40)
  {
    Flowsheet_eqFunction_430(data, threadData);
  }else
  {
    Flowsheet_eqFunction_431(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 433
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[2,2] = MaterialStream1.xg[2]
 */
void Flowsheet_eqFunction_433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,433};
  data->modelData->realVarsData[90].attribute /* MaterialStream1._xm_pc[2,2] variable */.start = data->simulationInfo->realParameter[433];
    data->localData[0]->realVars[90] /* MaterialStream1._xm_pc[2,2] variable */ = data->modelData->realVarsData[90].attribute /* MaterialStream1._xm_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[90].info /* MaterialStream1._xm_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[90] /* MaterialStream1._xm_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 434
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[2,2] = MaterialStream1.xg[2]
 */
void Flowsheet_eqFunction_434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,434};
  data->modelData->realVarsData[83].attribute /* MaterialStream1._x_pc[2,2] variable */.start = data->simulationInfo->realParameter[433];
    data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */ = data->modelData->realVarsData[83].attribute /* MaterialStream1._x_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[83].info /* MaterialStream1._x_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 435
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xmvap = MaterialStream1.xvapg
 */
void Flowsheet_eqFunction_435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,435};
  data->modelData->realVarsData[94].attribute /* MaterialStream1._xmvap variable */.start = data->simulationInfo->realParameter[439];
    data->localData[0]->realVars[94] /* MaterialStream1._xmvap variable */ = data->modelData->realVarsData[94].attribute /* MaterialStream1._xmvap variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[94].info /* MaterialStream1._xmvap */.name, (modelica_real) data->localData[0]->realVars[94] /* MaterialStream1._xmvap variable */);
  TRACE_POP
}

/*
 equation index: 436
 type: SIMPLE_ASSIGN
 MaterialStream1._Hliqg = MaterialStream1.xguess[1] * MaterialStream1.Hcomplg[1] + MaterialStream1.xguess[2] * MaterialStream1.Hcomplg[2]
 */
void Flowsheet_eqFunction_436(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,436};
  data->simulationInfo->realParameter[406] = (data->simulationInfo->realParameter[434]) * (data->simulationInfo->realParameter[402]) + (data->simulationInfo->realParameter[435]) * (data->simulationInfo->realParameter[403]);
  TRACE_POP
}

/*
 equation index: 437
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._H_p[2] = MaterialStream1.Hliqg
 */
void Flowsheet_eqFunction_437(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,437};
  data->modelData->realVarsData[36].attribute /* MaterialStream1._H_p[2] variable */.start = data->simulationInfo->realParameter[406];
    data->localData[0]->realVars[36] /* MaterialStream1._H_p[2] variable */ = data->modelData->realVarsData[36].attribute /* MaterialStream1._H_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[36].info /* MaterialStream1._H_p[2] */.name, (modelica_real) data->localData[0]->realVars[36] /* MaterialStream1._H_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 438
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Cp_p[2] = MaterialStream1.Hliqg
 */
void Flowsheet_eqFunction_438(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,438};
  data->modelData->realVarsData[6].attribute /* MaterialStream1._Cp_p[2] variable */.start = data->simulationInfo->realParameter[406];
    data->localData[0]->realVars[6] /* MaterialStream1._Cp_p[2] variable */ = data->modelData->realVarsData[6].attribute /* MaterialStream1._Cp_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[6].info /* MaterialStream1._Cp_p[2] */.name, (modelica_real) data->localData[0]->realVars[6] /* MaterialStream1._Cp_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 439
 type: SIMPLE_ASSIGN
 MaterialStream1._Hvapg = MaterialStream1.xguess[1] * MaterialStream1.Hcompvg[1] + MaterialStream1.xguess[2] * MaterialStream1.Hcompvg[2]
 */
void Flowsheet_eqFunction_439(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,439};
  data->simulationInfo->realParameter[409] = (data->simulationInfo->realParameter[434]) * (data->simulationInfo->realParameter[404]) + (data->simulationInfo->realParameter[435]) * (data->simulationInfo->realParameter[405]);
  TRACE_POP
}

/*
 equation index: 440
 type: SIMPLE_ASSIGN
 MaterialStream1._Htotg = MaterialStream1.Hliqg + MaterialStream1.Hvapg
 */
void Flowsheet_eqFunction_440(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,440};
  data->simulationInfo->realParameter[408] = data->simulationInfo->realParameter[406] + data->simulationInfo->realParameter[409];
  TRACE_POP
}

/*
 equation index: 441
 type: SIMPLE_ASSIGN
 MaterialStream1._Hmixg = MaterialStream1.Htotg
 */
void Flowsheet_eqFunction_441(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,441};
  data->simulationInfo->realParameter[407] = data->simulationInfo->realParameter[408];
  TRACE_POP
}

/*
 equation index: 442
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._H_p[1] = MaterialStream1.Hmixg
 */
void Flowsheet_eqFunction_442(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,442};
  data->modelData->realVarsData[35].attribute /* MaterialStream1._H_p[1] variable */.start = data->simulationInfo->realParameter[407];
    data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */ = data->modelData->realVarsData[35].attribute /* MaterialStream1._H_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[35].info /* MaterialStream1._H_p[1] */.name, (modelica_real) data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 443
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Cp_p[1] = MaterialStream1.Hmixg
 */
void Flowsheet_eqFunction_443(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,443};
  data->modelData->realVarsData[5].attribute /* MaterialStream1._Cp_p[1] variable */.start = data->simulationInfo->realParameter[407];
    data->localData[0]->realVars[5] /* MaterialStream1._Cp_p[1] variable */ = data->modelData->realVarsData[5].attribute /* MaterialStream1._Cp_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[5].info /* MaterialStream1._Cp_p[1] */.name, (modelica_real) data->localData[0]->realVars[5] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 444
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcompg[1] = MaterialStream1.xguess[1] * MaterialStream1.Htotg
 */
void Flowsheet_eqFunction_444(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,444};
  data->simulationInfo->realParameter[400] = (data->simulationInfo->realParameter[434]) * (data->simulationInfo->realParameter[408]);
  TRACE_POP
}

/*
 equation index: 445
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcompg[2] = MaterialStream1.xguess[2] * MaterialStream1.Htotg
 */
void Flowsheet_eqFunction_445(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,445};
  data->simulationInfo->realParameter[401] = (data->simulationInfo->realParameter[435]) * (data->simulationInfo->realParameter[408]);
  TRACE_POP
}

/*
 equation index: 446
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._H_p[3] = MaterialStream1.Hvapg
 */
void Flowsheet_eqFunction_446(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,446};
  data->modelData->realVarsData[37].attribute /* MaterialStream1._H_p[3] variable */.start = data->simulationInfo->realParameter[409];
    data->localData[0]->realVars[37] /* MaterialStream1._H_p[3] variable */ = data->modelData->realVarsData[37].attribute /* MaterialStream1._H_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[37].info /* MaterialStream1._H_p[3] */.name, (modelica_real) data->localData[0]->realVars[37] /* MaterialStream1._H_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 447
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Cp_p[3] = MaterialStream1.Hvapg
 */
void Flowsheet_eqFunction_447(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,447};
  data->modelData->realVarsData[7].attribute /* MaterialStream1._Cp_p[3] variable */.start = data->simulationInfo->realParameter[409];
    data->localData[0]->realVars[7] /* MaterialStream1._Cp_p[3] variable */ = data->modelData->realVarsData[7].attribute /* MaterialStream1._Cp_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[7].info /* MaterialStream1._Cp_p[3] */.name, (modelica_real) data->localData[0]->realVars[7] /* MaterialStream1._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 448
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[1,1] = MaterialStream1.xguess[1]
 */
void Flowsheet_eqFunction_448(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,448};
  data->modelData->realVarsData[87].attribute /* MaterialStream1._xm_pc[1,1] variable */.start = data->simulationInfo->realParameter[434];
    data->localData[0]->realVars[87] /* MaterialStream1._xm_pc[1,1] variable */ = data->modelData->realVarsData[87].attribute /* MaterialStream1._xm_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[87].info /* MaterialStream1._xm_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[87] /* MaterialStream1._xm_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 449
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._x_pc[1,1] = MaterialStream3.xguess[1]
 */
void Flowsheet_eqFunction_449(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,449};
  data->modelData->realVarsData[260].attribute /* MaterialStream3._x_pc[1,1] variable */.start = data->simulationInfo->realParameter[848];
    data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */ = data->modelData->realVarsData[260].attribute /* MaterialStream3._x_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[260].info /* MaterialStream3._x_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 450
 type: SIMPLE_ASSIGN
 $START._MaterialStream3._x_pc[1,2] = MaterialStream3.xguess[2]
 */
void Flowsheet_eqFunction_450(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,450};
  data->modelData->realVarsData[261].attribute /* MaterialStream3._x_pc[1,2] variable */.start = data->simulationInfo->realParameter[849];
    data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */ = data->modelData->realVarsData[261].attribute /* MaterialStream3._x_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[261].info /* MaterialStream3._x_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 451
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Pdew = MaterialStream2.Pmax
 */
void Flowsheet_eqFunction_451(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,451};
  data->modelData->realVarsData[144].attribute /* MaterialStream2._Pdew variable */.start = data->simulationInfo->realParameter[620];
    data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */ = data->modelData->realVarsData[144].attribute /* MaterialStream2._Pdew variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[144].info /* MaterialStream2._Pdew */.name, (modelica_real) data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
  TRACE_POP
}

/*
 equation index: 452
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Pbubl = MaterialStream2.Pmin
 */
void Flowsheet_eqFunction_452(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,452};
  data->modelData->realVarsData[143].attribute /* MaterialStream2._Pbubl variable */.start = data->simulationInfo->realParameter[621];
    data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */ = data->modelData->realVarsData[143].attribute /* MaterialStream2._Pbubl variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[143].info /* MaterialStream2._Pbubl */.name, (modelica_real) data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  TRACE_POP
}

/*
 equation index: 453
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Pdew = MaterialStream1.Pmax
 */
void Flowsheet_eqFunction_453(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,453};
  data->modelData->realVarsData[54].attribute /* MaterialStream1._Pdew variable */.start = data->simulationInfo->realParameter[413];
    data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */ = data->modelData->realVarsData[54].attribute /* MaterialStream1._Pdew variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[54].info /* MaterialStream1._Pdew */.name, (modelica_real) data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
  TRACE_POP
}

/*
 equation index: 454
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Pbubl = MaterialStream1.Pmin
 */
void Flowsheet_eqFunction_454(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,454};
  data->modelData->realVarsData[53].attribute /* MaterialStream1._Pbubl variable */.start = data->simulationInfo->realParameter[414];
    data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */ = data->modelData->realVarsData[53].attribute /* MaterialStream1._Pbubl variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[53].info /* MaterialStream1._Pbubl */.name, (modelica_real) data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  TRACE_POP
}

/*
 equation index: 455
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._T = MaterialStream1.Tg
 */
void Flowsheet_eqFunction_455(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,455};
  data->modelData->realVarsData[69].attribute /* MaterialStream1._T variable */.start = data->simulationInfo->realParameter[431];
    data->localData[0]->realVars[69] /* MaterialStream1._T variable */ = data->modelData->realVarsData[69].attribute /* MaterialStream1._T variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[69].info /* MaterialStream1._T */.name, (modelica_real) data->localData[0]->realVars[69] /* MaterialStream1._T variable */);
  TRACE_POP
}

/*
 equation index: 456
 type: SIMPLE_ASSIGN
 MaterialStream1._T = 250.0
 */
void Flowsheet_eqFunction_456(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,456};
  data->localData[0]->realVars[69] /* MaterialStream1._T variable */ = 250.0;
  TRACE_POP
}

/*
 equation index: 457
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[1,1] = MaterialStream1.xguess[1]
 */
void Flowsheet_eqFunction_457(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,457};
  data->modelData->realVarsData[80].attribute /* MaterialStream1._x_pc[1,1] variable */.start = data->simulationInfo->realParameter[434];
    data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */ = data->modelData->realVarsData[80].attribute /* MaterialStream1._x_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[80].info /* MaterialStream1._x_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 458
 type: SIMPLE_ASSIGN
 MaterialStream1._x_pc[1,1] = 0.7
 */
void Flowsheet_eqFunction_458(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,458};
  data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */ = 0.7;
  TRACE_POP
}

/*
 equation index: 459
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[1,1] = 100.0 * MaterialStream1.x_pc[1,1]
 */
void Flowsheet_eqFunction_459(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,459};
  data->localData[0]->realVars[20] /* MaterialStream1._F_pc[1,1] variable */ = (100.0) * (data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 460
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[1,1] = MaterialStream1.F_pc[1,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_460(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,460};
  data->localData[0]->realVars[29] /* MaterialStream1._Fm_pc[1,1] variable */ = (data->localData[0]->realVars[20] /* MaterialStream1._F_pc[1,1] variable */) * (data->simulationInfo->realParameter[323]);
  TRACE_POP
}

/*
 equation index: 461
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[1,2] = MaterialStream1.xguess[2]
 */
void Flowsheet_eqFunction_461(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,461};
  data->modelData->realVarsData[81].attribute /* MaterialStream1._x_pc[1,2] variable */.start = data->simulationInfo->realParameter[435];
    data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */ = data->modelData->realVarsData[81].attribute /* MaterialStream1._x_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[81].info /* MaterialStream1._x_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 462
 type: SIMPLE_ASSIGN
 MaterialStream1._x_pc[1,2] = 0.3
 */
void Flowsheet_eqFunction_462(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,462};
  data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */ = 0.3;
  TRACE_POP
}

/*
 equation index: 463
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[1,2] = 100.0 * MaterialStream1.x_pc[1,2]
 */
void Flowsheet_eqFunction_463(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,463};
  data->localData[0]->realVars[21] /* MaterialStream1._F_pc[1,2] variable */ = (100.0) * (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 464
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[1,2] = MaterialStream1.F_pc[1,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_464(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,464};
  data->localData[0]->realVars[30] /* MaterialStream1._Fm_pc[1,2] variable */ = (data->localData[0]->realVars[21] /* MaterialStream1._F_pc[1,2] variable */) * (data->simulationInfo->realParameter[324]);
  TRACE_POP
}

/*
 equation index: 465
 type: SIMPLE_ASSIGN
 MaterialStream1._Pbubl = MaterialStream1.x_pc[1,1] * exp(MaterialStream1.C[1].VP[2] + 0.004 * MaterialStream1.C[1].VP[3] + MaterialStream1.C[1].VP[4] * 5.521460917862246 + MaterialStream1.C[1].VP[5] * 250.0 ^ MaterialStream1.C[1].VP[6]) + MaterialStream1.x_pc[1,2] * exp(MaterialStream1.C[2].VP[2] + 0.004 * MaterialStream1.C[2].VP[3] + MaterialStream1.C[2].VP[4] * 5.521460917862246 + MaterialStream1.C[2].VP[5] * 250.0 ^ MaterialStream1.C[2].VP[6])
 */
void Flowsheet_eqFunction_465(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,465};
  modelica_real tmp41;
  modelica_real tmp42;
  modelica_real tmp43;
  modelica_real tmp44;
  modelica_real tmp45;
  modelica_real tmp46;
  modelica_real tmp47;
  modelica_real tmp48;
  modelica_real tmp49;
  modelica_real tmp50;
  modelica_real tmp51;
  modelica_real tmp52;
  modelica_real tmp53;
  modelica_real tmp54;
  tmp41 = 250.0;
  tmp42 = data->simulationInfo->realParameter[352];
  if(tmp41 < 0.0 && tmp42 != 0.0)
  {
    tmp44 = modf(tmp42, &tmp45);
    
    if(tmp44 > 0.5)
    {
      tmp44 -= 1.0;
      tmp45 += 1.0;
    }
    else if(tmp44 < -0.5)
    {
      tmp44 += 1.0;
      tmp45 -= 1.0;
    }
    
    if(fabs(tmp44) < 1e-10)
      tmp43 = pow(tmp41, tmp45);
    else
    {
      tmp47 = modf(1.0/tmp42, &tmp46);
      if(tmp47 > 0.5)
      {
        tmp47 -= 1.0;
        tmp46 += 1.0;
      }
      else if(tmp47 < -0.5)
      {
        tmp47 += 1.0;
        tmp46 -= 1.0;
      }
      if(fabs(tmp47) < 1e-10 && ((unsigned long)tmp46 & 1))
      {
        tmp43 = -pow(-tmp41, tmp44)*pow(tmp41, tmp45);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp41, tmp42);
      }
    }
  }
  else
  {
    tmp43 = pow(tmp41, tmp42);
  }
  if(isnan(tmp43) || isinf(tmp43))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp41, tmp42);
  }tmp48 = 250.0;
  tmp49 = data->simulationInfo->realParameter[358];
  if(tmp48 < 0.0 && tmp49 != 0.0)
  {
    tmp51 = modf(tmp49, &tmp52);
    
    if(tmp51 > 0.5)
    {
      tmp51 -= 1.0;
      tmp52 += 1.0;
    }
    else if(tmp51 < -0.5)
    {
      tmp51 += 1.0;
      tmp52 -= 1.0;
    }
    
    if(fabs(tmp51) < 1e-10)
      tmp50 = pow(tmp48, tmp52);
    else
    {
      tmp54 = modf(1.0/tmp49, &tmp53);
      if(tmp54 > 0.5)
      {
        tmp54 -= 1.0;
        tmp53 += 1.0;
      }
      else if(tmp54 < -0.5)
      {
        tmp54 += 1.0;
        tmp53 -= 1.0;
      }
      if(fabs(tmp54) < 1e-10 && ((unsigned long)tmp53 & 1))
      {
        tmp50 = -pow(-tmp48, tmp51)*pow(tmp48, tmp52);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp48, tmp49);
      }
    }
  }
  else
  {
    tmp50 = pow(tmp48, tmp49);
  }
  if(isnan(tmp50) || isinf(tmp50))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp48, tmp49);
  }
  data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */ = (data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (exp(data->simulationInfo->realParameter[348] + (0.004) * (data->simulationInfo->realParameter[349]) + (data->simulationInfo->realParameter[350]) * (5.521460917862246) + (data->simulationInfo->realParameter[351]) * (tmp43))) + (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (exp(data->simulationInfo->realParameter[354] + (0.004) * (data->simulationInfo->realParameter[355]) + (data->simulationInfo->realParameter[356]) * (5.521460917862246) + (data->simulationInfo->realParameter[357]) * (tmp50)));
  TRACE_POP
}

/*
 equation index: 466
 type: SIMPLE_ASSIGN
 MaterialStream1._Pdew = DIVISION(1.0, MaterialStream1.x_pc[1,1] * exp((-MaterialStream1.C[1].VP[2]) - 0.004 * MaterialStream1.C[1].VP[3] - MaterialStream1.C[1].VP[4] * 5.521460917862246 - MaterialStream1.C[1].VP[5] * 250.0 ^ MaterialStream1.C[1].VP[6]) + MaterialStream1.x_pc[1,2] * exp((-MaterialStream1.C[2].VP[2]) - 0.004 * MaterialStream1.C[2].VP[3] - MaterialStream1.C[2].VP[4] * 5.521460917862246 - MaterialStream1.C[2].VP[5] * 250.0 ^ MaterialStream1.C[2].VP[6]))
 */
void Flowsheet_eqFunction_466(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,466};
  modelica_real tmp55;
  modelica_real tmp56;
  modelica_real tmp57;
  modelica_real tmp58;
  modelica_real tmp59;
  modelica_real tmp60;
  modelica_real tmp61;
  modelica_real tmp62;
  modelica_real tmp63;
  modelica_real tmp64;
  modelica_real tmp65;
  modelica_real tmp66;
  modelica_real tmp67;
  modelica_real tmp68;
  tmp55 = 250.0;
  tmp56 = data->simulationInfo->realParameter[352];
  if(tmp55 < 0.0 && tmp56 != 0.0)
  {
    tmp58 = modf(tmp56, &tmp59);
    
    if(tmp58 > 0.5)
    {
      tmp58 -= 1.0;
      tmp59 += 1.0;
    }
    else if(tmp58 < -0.5)
    {
      tmp58 += 1.0;
      tmp59 -= 1.0;
    }
    
    if(fabs(tmp58) < 1e-10)
      tmp57 = pow(tmp55, tmp59);
    else
    {
      tmp61 = modf(1.0/tmp56, &tmp60);
      if(tmp61 > 0.5)
      {
        tmp61 -= 1.0;
        tmp60 += 1.0;
      }
      else if(tmp61 < -0.5)
      {
        tmp61 += 1.0;
        tmp60 -= 1.0;
      }
      if(fabs(tmp61) < 1e-10 && ((unsigned long)tmp60 & 1))
      {
        tmp57 = -pow(-tmp55, tmp58)*pow(tmp55, tmp59);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp55, tmp56);
      }
    }
  }
  else
  {
    tmp57 = pow(tmp55, tmp56);
  }
  if(isnan(tmp57) || isinf(tmp57))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp55, tmp56);
  }tmp62 = 250.0;
  tmp63 = data->simulationInfo->realParameter[358];
  if(tmp62 < 0.0 && tmp63 != 0.0)
  {
    tmp65 = modf(tmp63, &tmp66);
    
    if(tmp65 > 0.5)
    {
      tmp65 -= 1.0;
      tmp66 += 1.0;
    }
    else if(tmp65 < -0.5)
    {
      tmp65 += 1.0;
      tmp66 -= 1.0;
    }
    
    if(fabs(tmp65) < 1e-10)
      tmp64 = pow(tmp62, tmp66);
    else
    {
      tmp68 = modf(1.0/tmp63, &tmp67);
      if(tmp68 > 0.5)
      {
        tmp68 -= 1.0;
        tmp67 += 1.0;
      }
      else if(tmp68 < -0.5)
      {
        tmp68 += 1.0;
        tmp67 -= 1.0;
      }
      if(fabs(tmp68) < 1e-10 && ((unsigned long)tmp67 & 1))
      {
        tmp64 = -pow(-tmp62, tmp65)*pow(tmp62, tmp66);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp62, tmp63);
      }
    }
  }
  else
  {
    tmp64 = pow(tmp62, tmp63);
  }
  if(isnan(tmp64) || isinf(tmp64))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp62, tmp63);
  }
  data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */ = DIVISION_SIM(1.0,(data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (exp((-data->simulationInfo->realParameter[348]) - ((0.004) * (data->simulationInfo->realParameter[349])) - ((data->simulationInfo->realParameter[350]) * (5.521460917862246)) - ((data->simulationInfo->realParameter[351]) * (tmp57)))) + (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (exp((-data->simulationInfo->realParameter[354]) - ((0.004) * (data->simulationInfo->realParameter[355])) - ((data->simulationInfo->realParameter[356]) * (5.521460917862246)) - ((data->simulationInfo->realParameter[357]) * (tmp64)))),"MaterialStream1.x_pc[1,1] * exp((-MaterialStream1.C[1].VP[2]) - 0.004 * MaterialStream1.C[1].VP[3] - MaterialStream1.C[1].VP[4] * 5.521460917862246 - MaterialStream1.C[1].VP[5] * 250.0 ^ MaterialStream1.C[1].VP[6]) + MaterialStream1.x_pc[1,2] * exp((-MaterialStream1.C[2].VP[2]) - 0.004 * MaterialStream1.C[2].VP[3] - MaterialStream1.C[2].VP[4] * 5.521460917862246 - MaterialStream1.C[2].VP[5] * 250.0 ^ MaterialStream1.C[2].VP[6])",equationIndexes);
  TRACE_POP
}

void Flowsheet_eqFunction_467(DATA*,threadData_t*);
void Flowsheet_eqFunction_468(DATA*,threadData_t*);
void Flowsheet_eqFunction_469(DATA*,threadData_t*);
void Flowsheet_eqFunction_474(DATA*,threadData_t*);
void Flowsheet_eqFunction_473(DATA*,threadData_t*);
void Flowsheet_eqFunction_472(DATA*,threadData_t*);
void Flowsheet_eqFunction_471(DATA*,threadData_t*);
void Flowsheet_eqFunction_470(DATA*,threadData_t*);
/*
 equation index: 483
 indexNonlinear: 8
 type: NONLINEAR
 
 vars: {Mixer1._xvapin_s[1], MaterialStream1._x_pc[3,1], MaterialStream1._x_pc[3,2], MaterialStream1._x_pc[2,2], MaterialStream1._x_pc[2,1]}
 eqns: {467, 468, 469, 474, 473, 472, 471, 470}
 */
void Flowsheet_eqFunction_483(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,483};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 483 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[0] = data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */;
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[1] = data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */;
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[2] = data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */;
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[3] = data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */;
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[4] = data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */;
  retValue = solve_nonlinear_system(data, threadData, 8);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,483};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 483 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[0];
  data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[1];
  data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[2];
  data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[3];
  data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[8].nlsx[4];
  TRACE_POP
}

/*
 equation index: 484
 type: ALGORITHM
 
   for i in 1:2 loop
     MaterialStream1.MW_p[:] := {MaterialStream1.MW_p[1] + MaterialStream1.x_pc[1,i] * MaterialStream1.C[i].MW, MaterialStream1.MW_p[2] + MaterialStream1.x_pc[2,i] * MaterialStream1.C[i].MW, MaterialStream1.MW_p[3] + MaterialStream1.x_pc[3,i] * MaterialStream1.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_484(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,484};
  real_array tmp0;
  index_spec_t tmp1;
  real_array tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  tmp3 = ((modelica_integer) 1); tmp4 = 1; tmp5 = ((modelica_integer) 2);
  if(!tmp4)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert_withEquationIndexes(threadData, info, equationIndexes, "assertion range step != 0 failed");
  }
  else if(!(((tmp4 > 0) && (tmp3 > tmp5)) || ((tmp4 < 0) && (tmp3 < tmp5))))
  {
    modelica_integer $Pi;
    for($Pi = ((modelica_integer) 1); in_range_integer($Pi, tmp3, tmp5); $Pi += tmp4)
    {
      array_alloc_scalar_real_array(&tmp0, 3, (modelica_real)data->localData[0]->realVars[49] /* MaterialStream1._MW_p[1] variable */ + ((&data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[323])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[50] /* MaterialStream1._MW_p[2] variable */ + ((&data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[323])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[51] /* MaterialStream1._MW_p[3] variable */ + ((&data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[323])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp1, 1, (1), (int*)0, 'W');
      real_array_create(&tmp2, (modelica_real*)&data->localData[0]->realVars[49] /* MaterialStream1._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp0, &tmp2, &tmp1);
    }
  }
  TRACE_POP
}

/*
 equation index: 485
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[1] = 100.0 * MaterialStream1.MW_p[1]
 */
void Flowsheet_eqFunction_485(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,485};
  data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */ = (100.0) * (data->localData[0]->realVars[49] /* MaterialStream1._MW_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 486
 type: SIMPLE_ASSIGN
 MaterialStream1._xm_pc[1,2] = DIVISION(MaterialStream1.Fm_pc[1,2], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_486(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,486};
  data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[30] /* MaterialStream1._Fm_pc[1,2] variable */,data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 487
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[3] = MaterialStream1.F_p[3] * MaterialStream1.MW_p[3]
 */
void Flowsheet_eqFunction_487(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,487};
  data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */ = (data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */) * (data->localData[0]->realVars[51] /* MaterialStream1._MW_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 488
 type: SIMPLE_ASSIGN
 MaterialStream1._xmvap = DIVISION(MaterialStream1.Fm_p[3], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_488(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,488};
  data->localData[0]->realVars[94] /* MaterialStream1._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */,data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 489
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.H_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.H_pc[2,2]
 */
void Flowsheet_eqFunction_489(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,489};
  data->localData[0]->realVars[36] /* MaterialStream1._H_p[2] variable */ = (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[40] /* MaterialStream1._H_pc[2,1] variable */) + (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[41] /* MaterialStream1._H_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 490
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.Cp_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_490(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,490};
  data->localData[0]->realVars[6] /* MaterialStream1._Cp_p[2] variable */ = (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[10] /* MaterialStream1._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[11] /* MaterialStream1._Cp_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 491
 type: ALGORITHM
 
   (MaterialStream1.S_pc[2,2], MaterialStream1.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tb, MaterialStream1.C[2].Tc, 250.0, 101325.0, MaterialStream1.x_pc[2,2], MaterialStream1.x_pc[3,2]);
 */
void Flowsheet_eqFunction_491(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,491};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[265], (modelica_real)data->simulationInfo->realParameter[266], (modelica_real)data->simulationInfo->realParameter[267], (modelica_real)data->simulationInfo->realParameter[268], (modelica_real)data->simulationInfo->realParameter[269], (modelica_real)data->simulationInfo->realParameter[270]);
  data->localData[0]->realVars[63] /* MaterialStream1._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp6, tmp7, data->simulationInfo->realParameter[338], data->simulationInfo->realParameter[340], 250.0, 101325.0, data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */, data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ ,&data->localData[0]->realVars[65] /* MaterialStream1._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 492
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[3,2] = MaterialStream1.x_pc[3,2] * MaterialStream1.F_p[3]
 */
void Flowsheet_eqFunction_492(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,492};
  data->localData[0]->realVars[25] /* MaterialStream1._F_pc[3,2] variable */ = (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 493
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[3,2] = MaterialStream1.F_pc[3,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_493(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,493};
  data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[25] /* MaterialStream1._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[324]);
  TRACE_POP
}

/*
 equation index: 494
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[2] = MaterialStream1.F_p[2] * MaterialStream1.MW_p[2]
 */
void Flowsheet_eqFunction_494(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,494};
  data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */ = (data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */) * (data->localData[0]->realVars[50] /* MaterialStream1._MW_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 495
 type: SIMPLE_ASSIGN
 MaterialStream1._xmliq = DIVISION(MaterialStream1.Fm_p[2], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_495(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,495};
  data->localData[0]->realVars[93] /* MaterialStream1._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */,data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 496
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[2,2] = MaterialStream1.x_pc[2,2] * MaterialStream1.F_p[2]
 */
void Flowsheet_eqFunction_496(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,496};
  data->localData[0]->realVars[23] /* MaterialStream1._F_pc[2,2] variable */ = (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 497
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[2,2] = MaterialStream1.F_pc[2,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_497(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,497};
  data->localData[0]->realVars[32] /* MaterialStream1._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[23] /* MaterialStream1._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[324]);
  TRACE_POP
}

/*
 equation index: 498
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[2,1] = MaterialStream1.x_pc[2,1] * MaterialStream1.F_p[2]
 */
void Flowsheet_eqFunction_498(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,498};
  data->localData[0]->realVars[22] /* MaterialStream1._F_pc[2,1] variable */ = (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 499
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[2,1] = MaterialStream1.F_pc[2,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_499(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,499};
  data->localData[0]->realVars[31] /* MaterialStream1._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[22] /* MaterialStream1._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[323]);
  TRACE_POP
}

/*
 equation index: 500
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.H_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.H_pc[3,2]
 */
void Flowsheet_eqFunction_500(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,500};
  data->localData[0]->realVars[37] /* MaterialStream1._H_p[3] variable */ = (data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[42] /* MaterialStream1._H_pc[3,1] variable */) + (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[43] /* MaterialStream1._H_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 501
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[1] = MaterialStream1.xliq * MaterialStream1.H_p[2] + Mixer1.xvapin_s[1] * MaterialStream1.H_p[3]
 */
void Flowsheet_eqFunction_501(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,501};
  data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[36] /* MaterialStream1._H_p[2] variable */) + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (data->localData[0]->realVars[37] /* MaterialStream1._H_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 502
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.H_p[1]
 */
void Flowsheet_eqFunction_502(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,502};
  data->localData[0]->realVars[39] /* MaterialStream1._H_pc[1,2] variable */ = (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 503
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.H_p[1]
 */
void Flowsheet_eqFunction_503(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,503};
  data->localData[0]->realVars[38] /* MaterialStream1._H_pc[1,1] variable */ = (data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 504
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.Cp_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_504(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,504};
  data->localData[0]->realVars[7] /* MaterialStream1._Cp_p[3] variable */ = (data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[12] /* MaterialStream1._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[13] /* MaterialStream1._Cp_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 505
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[1] = MaterialStream1.xliq * MaterialStream1.Cp_p[2] + Mixer1.xvapin_s[1] * MaterialStream1.Cp_p[3]
 */
void Flowsheet_eqFunction_505(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,505};
  data->localData[0]->realVars[5] /* MaterialStream1._Cp_p[1] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[6] /* MaterialStream1._Cp_p[2] variable */) + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (data->localData[0]->realVars[7] /* MaterialStream1._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 506
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.Cp_p[1]
 */
void Flowsheet_eqFunction_506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,506};
  data->localData[0]->realVars[9] /* MaterialStream1._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[5] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 507
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.Cp_p[1]
 */
void Flowsheet_eqFunction_507(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,507};
  data->localData[0]->realVars[8] /* MaterialStream1._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[5] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 508
 type: ALGORITHM
 
   (MaterialStream1.S_pc[2,1], MaterialStream1.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tb, MaterialStream1.C[1].Tc, 250.0, 101325.0, MaterialStream1.x_pc[2,1], MaterialStream1.x_pc[3,1]);
 */
void Flowsheet_eqFunction_508(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,508};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[259], (modelica_real)data->simulationInfo->realParameter[260], (modelica_real)data->simulationInfo->realParameter[261], (modelica_real)data->simulationInfo->realParameter[262], (modelica_real)data->simulationInfo->realParameter[263], (modelica_real)data->simulationInfo->realParameter[264]);
  data->localData[0]->realVars[62] /* MaterialStream1._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp8, tmp9, data->simulationInfo->realParameter[337], data->simulationInfo->realParameter[339], 250.0, 101325.0, data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */, data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ ,&data->localData[0]->realVars[64] /* MaterialStream1._S_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 509
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.S_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.S_pc[3,2]
 */
void Flowsheet_eqFunction_509(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,509};
  data->localData[0]->realVars[59] /* MaterialStream1._S_p[3] variable */ = (data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[64] /* MaterialStream1._S_pc[3,1] variable */) + (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[65] /* MaterialStream1._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 510
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.S_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.S_pc[2,2]
 */
void Flowsheet_eqFunction_510(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,510};
  data->localData[0]->realVars[58] /* MaterialStream1._S_p[2] variable */ = (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[62] /* MaterialStream1._S_pc[2,1] variable */) + (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[63] /* MaterialStream1._S_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 511
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[1] = MaterialStream1.xliq * MaterialStream1.S_p[2] + Mixer1.xvapin_s[1] * MaterialStream1.S_p[3]
 */
void Flowsheet_eqFunction_511(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,511};
  data->localData[0]->realVars[57] /* MaterialStream1._S_p[1] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[58] /* MaterialStream1._S_p[2] variable */) + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (data->localData[0]->realVars[59] /* MaterialStream1._S_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 512
 type: SIMPLE_ASSIGN
 MaterialStream1._S_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.S_p[1]
 */
void Flowsheet_eqFunction_512(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,512};
  data->localData[0]->realVars[61] /* MaterialStream1._S_pc[1,2] variable */ = (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[57] /* MaterialStream1._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 513
 type: SIMPLE_ASSIGN
 MaterialStream1._S_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.S_p[1]
 */
void Flowsheet_eqFunction_513(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,513};
  data->localData[0]->realVars[60] /* MaterialStream1._S_pc[1,1] variable */ = (data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[57] /* MaterialStream1._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 514
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[3,1] = MaterialStream1.x_pc[3,1] * MaterialStream1.F_p[3]
 */
void Flowsheet_eqFunction_514(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,514};
  data->localData[0]->realVars[24] /* MaterialStream1._F_pc[3,1] variable */ = (data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 515
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[3,1] = MaterialStream1.F_pc[3,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_515(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,515};
  data->localData[0]->realVars[33] /* MaterialStream1._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[24] /* MaterialStream1._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[323]);
  TRACE_POP
}

/*
 equation index: 516
 type: LINEAR
 
 <var>MaterialStream1._xm_pc[1,1]</var>
 <var>MaterialStream1._xm_pc[3,1]</var>
 <var>MaterialStream1._xm_pc[2,2]</var>
 <var>MaterialStream1._xm_pc[2,1]</var>
 <var>MaterialStream1._xm_pc[3,2]</var>
 <row>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then -MaterialStream1.xm_pc[1,2] else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[3,2] else -MaterialStream1.xm_pc[1,2]</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[2,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[2,2] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[1,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1.Fm_pc[1,1] else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[3,1] else MaterialStream1.Fm_pc[1,1]</cell>
 </row>
 <matrix>
   <cell row="0" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[3] else 1.0)</residual>
   </cell><cell row="1" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[2] else 0.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="2" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -1.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="2" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[2] else 0.0)</residual>
   </cell><cell row="2" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="3" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[1] else 0.0)</residual>
   </cell><cell row="3" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="3" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -MaterialStream1.Fm_p[1] else if 101325.0 >= MaterialStream1.Pdew then -0.0 else -MaterialStream1.Fm_p[1])</residual>
   </cell><cell row="4" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[3] else -0.0)</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_516(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,516};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 516 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[4].x[0] = data->localData[1]->realVars[87] /* MaterialStream1._xm_pc[1,1] variable */;
  data->simulationInfo->linearSystemData[4].x[1] = data->localData[1]->realVars[91] /* MaterialStream1._xm_pc[3,1] variable */;
  data->simulationInfo->linearSystemData[4].x[2] = data->localData[1]->realVars[90] /* MaterialStream1._xm_pc[2,2] variable */;
  data->simulationInfo->linearSystemData[4].x[3] = data->localData[1]->realVars[89] /* MaterialStream1._xm_pc[2,1] variable */;
  data->simulationInfo->linearSystemData[4].x[4] = data->localData[1]->realVars[92] /* MaterialStream1._xm_pc[3,2] variable */;
  retValue = solve_linear_system(data, threadData, 4);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,516};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 516 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[87] /* MaterialStream1._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[4].x[0];
  data->localData[0]->realVars[91] /* MaterialStream1._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[4].x[1];
  data->localData[0]->realVars[90] /* MaterialStream1._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[4].x[2];
  data->localData[0]->realVars[89] /* MaterialStream1._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[4].x[3];
  data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[4].x[4];
  TRACE_POP
}

/*
 equation index: 517
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._T = MaterialStream2.Tg
 */
void Flowsheet_eqFunction_517(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,517};
  data->modelData->realVarsData[159].attribute /* MaterialStream2._T variable */.start = data->simulationInfo->realParameter[638];
    data->localData[0]->realVars[159] /* MaterialStream2._T variable */ = data->modelData->realVarsData[159].attribute /* MaterialStream2._T variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[159].info /* MaterialStream2._T */.name, (modelica_real) data->localData[0]->realVars[159] /* MaterialStream2._T variable */);
  TRACE_POP
}

/*
 equation index: 518
 type: SIMPLE_ASSIGN
 MaterialStream2._T = 300.0
 */
void Flowsheet_eqFunction_518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,518};
  data->localData[0]->realVars[159] /* MaterialStream2._T variable */ = 300.0;
  TRACE_POP
}

/*
 equation index: 519
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[1,1] = MaterialStream2.xguess[1]
 */
void Flowsheet_eqFunction_519(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,519};
  data->modelData->realVarsData[170].attribute /* MaterialStream2._x_pc[1,1] variable */.start = data->simulationInfo->realParameter[641];
    data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */ = data->modelData->realVarsData[170].attribute /* MaterialStream2._x_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[170].info /* MaterialStream2._x_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 520
 type: SIMPLE_ASSIGN
 MaterialStream2._x_pc[1,1] = 0.5
 */
void Flowsheet_eqFunction_520(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,520};
  data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */ = 0.5;
  TRACE_POP
}

/*
 equation index: 521
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[1,1] = 100.0 * MaterialStream2.x_pc[1,1]
 */
void Flowsheet_eqFunction_521(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,521};
  data->localData[0]->realVars[110] /* MaterialStream2._F_pc[1,1] variable */ = (100.0) * (data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 522
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[1,1] = MaterialStream2.F_pc[1,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_522(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,522};
  data->localData[0]->realVars[119] /* MaterialStream2._Fm_pc[1,1] variable */ = (data->localData[0]->realVars[110] /* MaterialStream2._F_pc[1,1] variable */) * (data->simulationInfo->realParameter[530]);
  TRACE_POP
}

/*
 equation index: 523
 type: SIMPLE_ASSIGN
 MaterialStream3._x_pc[1,1] = 0.5 * (MaterialStream1.x_pc[1,1] + MaterialStream2.x_pc[1,1])
 */
void Flowsheet_eqFunction_523(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,523};
  data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */ = (0.5) * (data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */ + data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 524
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[1,1] = 200.0 * MaterialStream3.x_pc[1,1]
 */
void Flowsheet_eqFunction_524(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,524};
  data->localData[0]->realVars[200] /* MaterialStream3._F_pc[1,1] variable */ = (200.0) * (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 525
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[1,1] = MaterialStream3.F_pc[1,1] * MaterialStream3.C[1].MW
 */
void Flowsheet_eqFunction_525(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,525};
  data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */ = (data->localData[0]->realVars[200] /* MaterialStream3._F_pc[1,1] variable */) * (data->simulationInfo->realParameter[737]);
  TRACE_POP
}

/*
 equation index: 526
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[1,2] = MaterialStream2.xguess[2]
 */
void Flowsheet_eqFunction_526(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,526};
  data->modelData->realVarsData[171].attribute /* MaterialStream2._x_pc[1,2] variable */.start = data->simulationInfo->realParameter[642];
    data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */ = data->modelData->realVarsData[171].attribute /* MaterialStream2._x_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[171].info /* MaterialStream2._x_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 527
 type: SIMPLE_ASSIGN
 MaterialStream2._x_pc[1,2] = 0.5
 */
void Flowsheet_eqFunction_527(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,527};
  data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */ = 0.5;
  TRACE_POP
}

/*
 equation index: 528
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[1,2] = 100.0 * MaterialStream2.x_pc[1,2]
 */
void Flowsheet_eqFunction_528(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,528};
  data->localData[0]->realVars[111] /* MaterialStream2._F_pc[1,2] variable */ = (100.0) * (data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 529
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[1,2] = MaterialStream2.F_pc[1,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_529(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,529};
  data->localData[0]->realVars[120] /* MaterialStream2._Fm_pc[1,2] variable */ = (data->localData[0]->realVars[111] /* MaterialStream2._F_pc[1,2] variable */) * (data->simulationInfo->realParameter[531]);
  TRACE_POP
}

/*
 equation index: 530
 type: SIMPLE_ASSIGN
 MaterialStream2._Pbubl = MaterialStream2.x_pc[1,1] * exp(MaterialStream2.C[1].VP[2] + MaterialStream2.C[1].VP[3] / 300.0 + MaterialStream2.C[1].VP[4] * 5.703782474656201 + MaterialStream2.C[1].VP[5] * 300.0 ^ MaterialStream2.C[1].VP[6]) + MaterialStream2.x_pc[1,2] * exp(MaterialStream2.C[2].VP[2] + MaterialStream2.C[2].VP[3] / 300.0 + MaterialStream2.C[2].VP[4] * 5.703782474656201 + MaterialStream2.C[2].VP[5] * 300.0 ^ MaterialStream2.C[2].VP[6])
 */
void Flowsheet_eqFunction_530(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,530};
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  tmp10 = 300.0;
  if (tmp10 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.C[1].VP[3] / 300.0");}
  tmp11 = 300.0;
  tmp12 = data->simulationInfo->realParameter[559];
  if(tmp11 < 0.0 && tmp12 != 0.0)
  {
    tmp14 = modf(tmp12, &tmp15);
    
    if(tmp14 > 0.5)
    {
      tmp14 -= 1.0;
      tmp15 += 1.0;
    }
    else if(tmp14 < -0.5)
    {
      tmp14 += 1.0;
      tmp15 -= 1.0;
    }
    
    if(fabs(tmp14) < 1e-10)
      tmp13 = pow(tmp11, tmp15);
    else
    {
      tmp17 = modf(1.0/tmp12, &tmp16);
      if(tmp17 > 0.5)
      {
        tmp17 -= 1.0;
        tmp16 += 1.0;
      }
      else if(tmp17 < -0.5)
      {
        tmp17 += 1.0;
        tmp16 -= 1.0;
      }
      if(fabs(tmp17) < 1e-10 && ((unsigned long)tmp16 & 1))
      {
        tmp13 = -pow(-tmp11, tmp14)*pow(tmp11, tmp15);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp11, tmp12);
      }
    }
  }
  else
  {
    tmp13 = pow(tmp11, tmp12);
  }
  if(isnan(tmp13) || isinf(tmp13))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp11, tmp12);
  }tmp18 = 300.0;
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.C[2].VP[3] / 300.0");}
  tmp19 = 300.0;
  tmp20 = data->simulationInfo->realParameter[565];
  if(tmp19 < 0.0 && tmp20 != 0.0)
  {
    tmp22 = modf(tmp20, &tmp23);
    
    if(tmp22 > 0.5)
    {
      tmp22 -= 1.0;
      tmp23 += 1.0;
    }
    else if(tmp22 < -0.5)
    {
      tmp22 += 1.0;
      tmp23 -= 1.0;
    }
    
    if(fabs(tmp22) < 1e-10)
      tmp21 = pow(tmp19, tmp23);
    else
    {
      tmp25 = modf(1.0/tmp20, &tmp24);
      if(tmp25 > 0.5)
      {
        tmp25 -= 1.0;
        tmp24 += 1.0;
      }
      else if(tmp25 < -0.5)
      {
        tmp25 += 1.0;
        tmp24 -= 1.0;
      }
      if(fabs(tmp25) < 1e-10 && ((unsigned long)tmp24 & 1))
      {
        tmp21 = -pow(-tmp19, tmp22)*pow(tmp19, tmp23);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp19, tmp20);
      }
    }
  }
  else
  {
    tmp21 = pow(tmp19, tmp20);
  }
  if(isnan(tmp21) || isinf(tmp21))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp19, tmp20);
  }
  data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */ = (data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (exp(data->simulationInfo->realParameter[555] + (data->simulationInfo->realParameter[556]) / tmp10 + (data->simulationInfo->realParameter[557]) * (5.703782474656201) + (data->simulationInfo->realParameter[558]) * (tmp13))) + (data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (exp(data->simulationInfo->realParameter[561] + (data->simulationInfo->realParameter[562]) / tmp18 + (data->simulationInfo->realParameter[563]) * (5.703782474656201) + (data->simulationInfo->realParameter[564]) * (tmp21)));
  TRACE_POP
}

/*
 equation index: 531
 type: SIMPLE_ASSIGN
 MaterialStream2._Pdew = DIVISION(1.0, MaterialStream2.x_pc[1,1] * exp((-MaterialStream2.C[1].VP[2]) - MaterialStream2.C[1].VP[3] / 300.0 - MaterialStream2.C[1].VP[4] * 5.703782474656201 - MaterialStream2.C[1].VP[5] * 300.0 ^ MaterialStream2.C[1].VP[6]) + MaterialStream2.x_pc[1,2] * exp((-MaterialStream2.C[2].VP[2]) - MaterialStream2.C[2].VP[3] / 300.0 - MaterialStream2.C[2].VP[4] * 5.703782474656201 - MaterialStream2.C[2].VP[5] * 300.0 ^ MaterialStream2.C[2].VP[6]))
 */
void Flowsheet_eqFunction_531(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,531};
  modelica_real tmp26;
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_real tmp33;
  modelica_real tmp34;
  modelica_real tmp35;
  modelica_real tmp36;
  modelica_real tmp37;
  modelica_real tmp38;
  modelica_real tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  tmp26 = 300.0;
  if (tmp26 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.C[1].VP[3] / 300.0");}
  tmp27 = 300.0;
  tmp28 = data->simulationInfo->realParameter[559];
  if(tmp27 < 0.0 && tmp28 != 0.0)
  {
    tmp30 = modf(tmp28, &tmp31);
    
    if(tmp30 > 0.5)
    {
      tmp30 -= 1.0;
      tmp31 += 1.0;
    }
    else if(tmp30 < -0.5)
    {
      tmp30 += 1.0;
      tmp31 -= 1.0;
    }
    
    if(fabs(tmp30) < 1e-10)
      tmp29 = pow(tmp27, tmp31);
    else
    {
      tmp33 = modf(1.0/tmp28, &tmp32);
      if(tmp33 > 0.5)
      {
        tmp33 -= 1.0;
        tmp32 += 1.0;
      }
      else if(tmp33 < -0.5)
      {
        tmp33 += 1.0;
        tmp32 -= 1.0;
      }
      if(fabs(tmp33) < 1e-10 && ((unsigned long)tmp32 & 1))
      {
        tmp29 = -pow(-tmp27, tmp30)*pow(tmp27, tmp31);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp27, tmp28);
      }
    }
  }
  else
  {
    tmp29 = pow(tmp27, tmp28);
  }
  if(isnan(tmp29) || isinf(tmp29))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp27, tmp28);
  }tmp34 = 300.0;
  if (tmp34 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.C[2].VP[3] / 300.0");}
  tmp35 = 300.0;
  tmp36 = data->simulationInfo->realParameter[565];
  if(tmp35 < 0.0 && tmp36 != 0.0)
  {
    tmp38 = modf(tmp36, &tmp39);
    
    if(tmp38 > 0.5)
    {
      tmp38 -= 1.0;
      tmp39 += 1.0;
    }
    else if(tmp38 < -0.5)
    {
      tmp38 += 1.0;
      tmp39 -= 1.0;
    }
    
    if(fabs(tmp38) < 1e-10)
      tmp37 = pow(tmp35, tmp39);
    else
    {
      tmp41 = modf(1.0/tmp36, &tmp40);
      if(tmp41 > 0.5)
      {
        tmp41 -= 1.0;
        tmp40 += 1.0;
      }
      else if(tmp41 < -0.5)
      {
        tmp41 += 1.0;
        tmp40 -= 1.0;
      }
      if(fabs(tmp41) < 1e-10 && ((unsigned long)tmp40 & 1))
      {
        tmp37 = -pow(-tmp35, tmp38)*pow(tmp35, tmp39);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp35, tmp36);
      }
    }
  }
  else
  {
    tmp37 = pow(tmp35, tmp36);
  }
  if(isnan(tmp37) || isinf(tmp37))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp35, tmp36);
  }
  data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */ = DIVISION_SIM(1.0,(data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (exp((-data->simulationInfo->realParameter[555]) - ((data->simulationInfo->realParameter[556]) / tmp26) - ((data->simulationInfo->realParameter[557]) * (5.703782474656201)) - ((data->simulationInfo->realParameter[558]) * (tmp29)))) + (data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (exp((-data->simulationInfo->realParameter[561]) - ((data->simulationInfo->realParameter[562]) / tmp34) - ((data->simulationInfo->realParameter[563]) * (5.703782474656201)) - ((data->simulationInfo->realParameter[564]) * (tmp37)))),"MaterialStream2.x_pc[1,1] * exp((-MaterialStream2.C[1].VP[2]) - MaterialStream2.C[1].VP[3] / 300.0 - MaterialStream2.C[1].VP[4] * 5.703782474656201 - MaterialStream2.C[1].VP[5] * 300.0 ^ MaterialStream2.C[1].VP[6]) + MaterialStream2.x_pc[1,2] * exp((-MaterialStream2.C[2].VP[2]) - MaterialStream2.C[2].VP[3] / 300.0 - MaterialStream2.C[2].VP[4] * 5.703782474656201 - MaterialStream2.C[2].VP[5] * 300.0 ^ MaterialStream2.C[2].VP[6])",equationIndexes);
  TRACE_POP
}

void Flowsheet_eqFunction_532(DATA*,threadData_t*);
void Flowsheet_eqFunction_533(DATA*,threadData_t*);
void Flowsheet_eqFunction_534(DATA*,threadData_t*);
void Flowsheet_eqFunction_539(DATA*,threadData_t*);
void Flowsheet_eqFunction_538(DATA*,threadData_t*);
void Flowsheet_eqFunction_537(DATA*,threadData_t*);
void Flowsheet_eqFunction_536(DATA*,threadData_t*);
void Flowsheet_eqFunction_535(DATA*,threadData_t*);
/*
 equation index: 548
 indexNonlinear: 9
 type: NONLINEAR
 
 vars: {Mixer1._xvapin_s[2], MaterialStream2._x_pc[3,2], MaterialStream2._x_pc[2,2], MaterialStream2._x_pc[2,1], MaterialStream2._x_pc[3,1]}
 eqns: {532, 533, 534, 539, 538, 537, 536, 535}
 */
void Flowsheet_eqFunction_548(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,548};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 548 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[0] = data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */;
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[1] = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */;
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[2] = data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */;
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[3] = data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[4] = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */;
  retValue = solve_nonlinear_system(data, threadData, 9);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,548};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 548 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[0];
  data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[1];
  data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[2];
  data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[3];
  data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[9].nlsx[4];
  TRACE_POP
}

/*
 equation index: 549
 type: ALGORITHM
 
   for i in 1:2 loop
     MaterialStream2.MW_p[:] := {MaterialStream2.MW_p[1] + MaterialStream2.x_pc[1,i] * MaterialStream2.C[i].MW, MaterialStream2.MW_p[2] + MaterialStream2.x_pc[2,i] * MaterialStream2.C[i].MW, MaterialStream2.MW_p[3] + MaterialStream2.x_pc[3,i] * MaterialStream2.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_549(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,549};
  real_array tmp0;
  index_spec_t tmp1;
  real_array tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  tmp3 = ((modelica_integer) 1); tmp4 = 1; tmp5 = ((modelica_integer) 2);
  if(!tmp4)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert_withEquationIndexes(threadData, info, equationIndexes, "assertion range step != 0 failed");
  }
  else if(!(((tmp4 > 0) && (tmp3 > tmp5)) || ((tmp4 < 0) && (tmp3 < tmp5))))
  {
    modelica_integer $Pi;
    for($Pi = ((modelica_integer) 1); in_range_integer($Pi, tmp3, tmp5); $Pi += tmp4)
    {
      array_alloc_scalar_real_array(&tmp0, 3, (modelica_real)data->localData[0]->realVars[139] /* MaterialStream2._MW_p[1] variable */ + ((&data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[530])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[140] /* MaterialStream2._MW_p[2] variable */ + ((&data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[530])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[141] /* MaterialStream2._MW_p[3] variable */ + ((&data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[530])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp1, 1, (1), (int*)0, 'W');
      real_array_create(&tmp2, (modelica_real*)&data->localData[0]->realVars[139] /* MaterialStream2._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp0, &tmp2, &tmp1);
    }
  }
  TRACE_POP
}

/*
 equation index: 550
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[1] = 100.0 * MaterialStream2.MW_p[1]
 */
void Flowsheet_eqFunction_550(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,550};
  data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */ = (100.0) * (data->localData[0]->realVars[139] /* MaterialStream2._MW_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 551
 type: SIMPLE_ASSIGN
 MaterialStream2._xm_pc[1,2] = DIVISION(MaterialStream2.Fm_pc[1,2], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_551(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,551};
  data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[120] /* MaterialStream2._Fm_pc[1,2] variable */,data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 552
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[2] = MaterialStream2.F_p[2] * MaterialStream2.MW_p[2]
 */
void Flowsheet_eqFunction_552(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,552};
  data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */ = (data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */) * (data->localData[0]->realVars[140] /* MaterialStream2._MW_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 553
 type: SIMPLE_ASSIGN
 MaterialStream2._xmliq = DIVISION(MaterialStream2.Fm_p[2], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_553(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,553};
  data->localData[0]->realVars[183] /* MaterialStream2._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */,data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 554
 type: ALGORITHM
 
   (MaterialStream2.S_pc[2,1], MaterialStream2.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tb, MaterialStream2.C[1].Tc, 300.0, 101325.0, MaterialStream2.x_pc[2,1], MaterialStream2.x_pc[3,1]);
 */
void Flowsheet_eqFunction_554(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,554};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567], (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[466], (modelica_real)data->simulationInfo->realParameter[467], (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471]);
  data->localData[0]->realVars[152] /* MaterialStream2._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp6, tmp7, data->simulationInfo->realParameter[544], data->simulationInfo->realParameter[546], 300.0, 101325.0, data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */, data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ ,&data->localData[0]->realVars[154] /* MaterialStream2._S_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 555
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.H_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.H_pc[2,2]
 */
void Flowsheet_eqFunction_555(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,555};
  data->localData[0]->realVars[126] /* MaterialStream2._H_p[2] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[130] /* MaterialStream2._H_pc[2,1] variable */) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[131] /* MaterialStream2._H_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 556
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.Cp_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_556(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,556};
  data->localData[0]->realVars[96] /* MaterialStream2._Cp_p[2] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[100] /* MaterialStream2._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[101] /* MaterialStream2._Cp_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 557
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[3] = MaterialStream2.F_p[3] * MaterialStream2.MW_p[3]
 */
void Flowsheet_eqFunction_557(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,557};
  data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */ = (data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */) * (data->localData[0]->realVars[141] /* MaterialStream2._MW_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 558
 type: SIMPLE_ASSIGN
 MaterialStream2._xmvap = DIVISION(MaterialStream2.Fm_p[3], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_558(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,558};
  data->localData[0]->realVars[184] /* MaterialStream2._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */,data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 559
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[3,1] = MaterialStream2.x_pc[3,1] * MaterialStream2.F_p[3]
 */
void Flowsheet_eqFunction_559(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,559};
  data->localData[0]->realVars[114] /* MaterialStream2._F_pc[3,1] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 560
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[3,1] = MaterialStream2.F_pc[3,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_560(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,560};
  data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[114] /* MaterialStream2._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[530]);
  TRACE_POP
}

/*
 equation index: 561
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[2,2] = MaterialStream2.x_pc[2,2] * MaterialStream2.F_p[2]
 */
void Flowsheet_eqFunction_561(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,561};
  data->localData[0]->realVars[113] /* MaterialStream2._F_pc[2,2] variable */ = (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 562
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[2,2] = MaterialStream2.F_pc[2,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_562(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,562};
  data->localData[0]->realVars[122] /* MaterialStream2._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[113] /* MaterialStream2._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[531]);
  TRACE_POP
}

/*
 equation index: 563
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[2,1] = MaterialStream2.x_pc[2,1] * MaterialStream2.F_p[2]
 */
void Flowsheet_eqFunction_563(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,563};
  data->localData[0]->realVars[112] /* MaterialStream2._F_pc[2,1] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 564
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[2,1] = MaterialStream2.F_pc[2,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_564(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,564};
  data->localData[0]->realVars[121] /* MaterialStream2._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[112] /* MaterialStream2._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[530]);
  TRACE_POP
}

/*
 equation index: 565
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.H_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.H_pc[3,2]
 */
void Flowsheet_eqFunction_565(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,565};
  data->localData[0]->realVars[127] /* MaterialStream2._H_p[3] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[132] /* MaterialStream2._H_pc[3,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[133] /* MaterialStream2._H_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 566
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[1] = MaterialStream2.xliq * MaterialStream2.H_p[2] + Mixer1.xvapin_s[2] * MaterialStream2.H_p[3]
 */
void Flowsheet_eqFunction_566(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,566};
  data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[126] /* MaterialStream2._H_p[2] variable */) + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (data->localData[0]->realVars[127] /* MaterialStream2._H_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 567
 type: SIMPLE_ASSIGN
 MaterialStream3._H_p[1] = 0.5 * (MaterialStream1.H_p[1] + MaterialStream2.H_p[1])
 */
void Flowsheet_eqFunction_567(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,567};
  data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */ = (0.5) * (data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */ + data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 568
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[1,1] = MaterialStream3.x_pc[1,1] * MaterialStream3.H_p[1]
 */
void Flowsheet_eqFunction_568(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,568};
  data->localData[0]->realVars[218] /* MaterialStream3._H_pc[1,1] variable */ = (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 569
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.H_p[1]
 */
void Flowsheet_eqFunction_569(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,569};
  data->localData[0]->realVars[129] /* MaterialStream2._H_pc[1,2] variable */ = (data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 570
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.H_p[1]
 */
void Flowsheet_eqFunction_570(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,570};
  data->localData[0]->realVars[128] /* MaterialStream2._H_pc[1,1] variable */ = (data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 571
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.Cp_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_571(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,571};
  data->localData[0]->realVars[97] /* MaterialStream2._Cp_p[3] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[102] /* MaterialStream2._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[103] /* MaterialStream2._Cp_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 572
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[1] = MaterialStream2.xliq * MaterialStream2.Cp_p[2] + Mixer1.xvapin_s[2] * MaterialStream2.Cp_p[3]
 */
void Flowsheet_eqFunction_572(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,572};
  data->localData[0]->realVars[95] /* MaterialStream2._Cp_p[1] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[96] /* MaterialStream2._Cp_p[2] variable */) + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (data->localData[0]->realVars[97] /* MaterialStream2._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 573
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.Cp_p[1]
 */
void Flowsheet_eqFunction_573(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,573};
  data->localData[0]->realVars[99] /* MaterialStream2._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[95] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 574
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.Cp_p[1]
 */
void Flowsheet_eqFunction_574(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,574};
  data->localData[0]->realVars[98] /* MaterialStream2._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[95] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 575
 type: ALGORITHM
 
   (MaterialStream2.S_pc[2,2], MaterialStream2.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tb, MaterialStream2.C[2].Tc, 300.0, 101325.0, MaterialStream2.x_pc[2,2], MaterialStream2.x_pc[3,2]);
 */
void Flowsheet_eqFunction_575(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,575};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573], (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473], (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477]);
  data->localData[0]->realVars[153] /* MaterialStream2._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp8, tmp9, data->simulationInfo->realParameter[545], data->simulationInfo->realParameter[547], 300.0, 101325.0, data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */, data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ ,&data->localData[0]->realVars[155] /* MaterialStream2._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 576
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.S_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.S_pc[3,2]
 */
void Flowsheet_eqFunction_576(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,576};
  data->localData[0]->realVars[149] /* MaterialStream2._S_p[3] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[154] /* MaterialStream2._S_pc[3,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[155] /* MaterialStream2._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 577
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.S_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.S_pc[2,2]
 */
void Flowsheet_eqFunction_577(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,577};
  data->localData[0]->realVars[148] /* MaterialStream2._S_p[2] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[152] /* MaterialStream2._S_pc[2,1] variable */) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[153] /* MaterialStream2._S_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 578
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[1] = MaterialStream2.xliq * MaterialStream2.S_p[2] + Mixer1.xvapin_s[2] * MaterialStream2.S_p[3]
 */
void Flowsheet_eqFunction_578(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,578};
  data->localData[0]->realVars[147] /* MaterialStream2._S_p[1] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[148] /* MaterialStream2._S_p[2] variable */) + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (data->localData[0]->realVars[149] /* MaterialStream2._S_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 579
 type: SIMPLE_ASSIGN
 MaterialStream2._S_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.S_p[1]
 */
void Flowsheet_eqFunction_579(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,579};
  data->localData[0]->realVars[151] /* MaterialStream2._S_pc[1,2] variable */ = (data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[147] /* MaterialStream2._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 580
 type: SIMPLE_ASSIGN
 MaterialStream2._S_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.S_p[1]
 */
void Flowsheet_eqFunction_580(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,580};
  data->localData[0]->realVars[150] /* MaterialStream2._S_pc[1,1] variable */ = (data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[147] /* MaterialStream2._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 581
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[3,2] = MaterialStream2.x_pc[3,2] * MaterialStream2.F_p[3]
 */
void Flowsheet_eqFunction_581(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,581};
  data->localData[0]->realVars[115] /* MaterialStream2._F_pc[3,2] variable */ = (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 582
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[3,2] = MaterialStream2.F_pc[3,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_582(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,582};
  data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[115] /* MaterialStream2._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[531]);
  TRACE_POP
}

/*
 equation index: 583
 type: LINEAR
 
 <var>MaterialStream2._xm_pc[3,2]</var>
 <var>MaterialStream2._xm_pc[2,1]</var>
 <var>MaterialStream2._xm_pc[3,1]</var>
 <var>MaterialStream2._xm_pc[1,1]</var>
 <var>MaterialStream2._xm_pc[2,2]</var>
 <row>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then -MaterialStream2.xm_pc[1,2] else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[3,2] else -MaterialStream2.xm_pc[1,2]</cell>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[2,2] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2.Fm_pc[1,1] else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[3,1] else MaterialStream2.Fm_pc[1,1]</cell>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[1,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[2,1] else 0.0</cell>
 </row>
 <matrix>
   <cell row="0" col="0">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[3] else 1.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="1" col="1">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="1" col="2">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then -1.0 else if 101325.0 >= MaterialStream2.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[2] else 0.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then -0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[3] else -0.0)</residual>
   </cell><cell row="2" col="3">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then -MaterialStream2.Fm_p[1] else if 101325.0 >= MaterialStream2.Pdew then -0.0 else -MaterialStream2.Fm_p[1])</residual>
   </cell><cell row="3" col="1">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="3" col="2">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="3" col="3">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[1] else 0.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="4" col="1">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[2] else 0.0)</residual>
   </cell><cell row="4" col="4">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_583(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,583};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 583 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[5].x[0] = data->localData[1]->realVars[182] /* MaterialStream2._xm_pc[3,2] variable */;
  data->simulationInfo->linearSystemData[5].x[1] = data->localData[1]->realVars[179] /* MaterialStream2._xm_pc[2,1] variable */;
  data->simulationInfo->linearSystemData[5].x[2] = data->localData[1]->realVars[181] /* MaterialStream2._xm_pc[3,1] variable */;
  data->simulationInfo->linearSystemData[5].x[3] = data->localData[1]->realVars[177] /* MaterialStream2._xm_pc[1,1] variable */;
  data->simulationInfo->linearSystemData[5].x[4] = data->localData[1]->realVars[180] /* MaterialStream2._xm_pc[2,2] variable */;
  retValue = solve_linear_system(data, threadData, 5);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,583};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 583 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[5].x[0];
  data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[5].x[1];
  data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[5].x[2];
  data->localData[0]->realVars[177] /* MaterialStream2._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[5].x[3];
  data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[5].x[4];
  TRACE_POP
}

/*
 equation index: 584
 type: SIMPLE_ASSIGN
 MaterialStream3._x_pc[1,2] = 0.5 * (MaterialStream1.x_pc[1,2] + MaterialStream2.x_pc[1,2])
 */
void Flowsheet_eqFunction_584(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,584};
  data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */ = (0.5) * (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */ + data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */);
  TRACE_POP
}

void Flowsheet_eqFunction_585(DATA*,threadData_t*);
void Flowsheet_eqFunction_586(DATA*,threadData_t*);
void Flowsheet_eqFunction_587(DATA*,threadData_t*);
void Flowsheet_eqFunction_588(DATA*,threadData_t*);
void Flowsheet_eqFunction_589(DATA*,threadData_t*);
void Flowsheet_eqFunction_590(DATA*,threadData_t*);
void Flowsheet_eqFunction_591(DATA*,threadData_t*);
void Flowsheet_eqFunction_592(DATA*,threadData_t*);
void Flowsheet_eqFunction_593(DATA*,threadData_t*);
void Flowsheet_eqFunction_594(DATA*,threadData_t*);
void Flowsheet_eqFunction_595(DATA*,threadData_t*);
void Flowsheet_eqFunction_596(DATA*,threadData_t*);
void Flowsheet_eqFunction_597(DATA*,threadData_t*);
void Flowsheet_eqFunction_598(DATA*,threadData_t*);
void Flowsheet_eqFunction_599(DATA*,threadData_t*);
void Flowsheet_eqFunction_605(DATA*,threadData_t*);
void Flowsheet_eqFunction_604(DATA*,threadData_t*);
void Flowsheet_eqFunction_603(DATA*,threadData_t*);
void Flowsheet_eqFunction_602(DATA*,threadData_t*);
void Flowsheet_eqFunction_601(DATA*,threadData_t*);
void Flowsheet_eqFunction_600(DATA*,threadData_t*);
/*
 equation index: 606
 indexNonlinear: 10
 type: NONLINEAR
 
 vars: {MaterialStream3._xvap, MaterialStream3._x_pc[3,1], MaterialStream3._x_pc[2,2], MaterialStream3._x_pc[2,1], MaterialStream3._x_pc[3,2], MaterialStream3._T}
 eqns: {585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 605, 604, 603, 602, 601, 600}
 */
void Flowsheet_eqFunction_606(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,606};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 606 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[10].nlsxOld[0] = data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */;
  data->simulationInfo->nonlinearSystemData[10].nlsxOld[1] = data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */;
  data->simulationInfo->nonlinearSystemData[10].nlsxOld[2] = data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */;
  data->simulationInfo->nonlinearSystemData[10].nlsxOld[3] = data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[10].nlsxOld[4] = data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */;
  data->simulationInfo->nonlinearSystemData[10].nlsxOld[5] = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  retValue = solve_nonlinear_system(data, threadData, 10);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,606};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 606 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */ = data->simulationInfo->nonlinearSystemData[10].nlsx[0];
  data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[10].nlsx[1];
  data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[10].nlsx[2];
  data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[10].nlsx[3];
  data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[10].nlsx[4];
  data->localData[0]->realVars[249] /* MaterialStream3._T variable */ = data->simulationInfo->nonlinearSystemData[10].nlsx[5];
  TRACE_POP
}

/*
 equation index: 607
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[3,2] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_607(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,607};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  data->localData[0]->realVars[193] /* MaterialStream3._Cp_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp0, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}

/*
 equation index: 608
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[2,2] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream3.C[2].LiqCp[1], MaterialStream3.C[2].LiqCp[2], MaterialStream3.C[2].LiqCp[3], MaterialStream3.C[2].LiqCp[4], MaterialStream3.C[2].LiqCp[5], MaterialStream3.C[2].LiqCp[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_608(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,608};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[695], (modelica_real)data->simulationInfo->realParameter[696], (modelica_real)data->simulationInfo->realParameter[697], (modelica_real)data->simulationInfo->realParameter[698], (modelica_real)data->simulationInfo->realParameter[699], (modelica_real)data->simulationInfo->realParameter[700]);
  data->localData[0]->realVars[191] /* MaterialStream3._Cp_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp1, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}

/*
 equation index: 609
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[3,1] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_609(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,609};
  real_array tmp2;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  data->localData[0]->realVars[192] /* MaterialStream3._Cp_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp2, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}

/*
 equation index: 610
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[2,1] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream3.C[1].LiqCp[1], MaterialStream3.C[1].LiqCp[2], MaterialStream3.C[1].LiqCp[3], MaterialStream3.C[1].LiqCp[4], MaterialStream3.C[1].LiqCp[5], MaterialStream3.C[1].LiqCp[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_610(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,610};
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[689], (modelica_real)data->simulationInfo->realParameter[690], (modelica_real)data->simulationInfo->realParameter[691], (modelica_real)data->simulationInfo->realParameter[692], (modelica_real)data->simulationInfo->realParameter[693], (modelica_real)data->simulationInfo->realParameter[694]);
  data->localData[0]->realVars[190] /* MaterialStream3._Cp_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp3, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}

/*
 equation index: 611
 type: ALGORITHM
 
   for i in 1:2 loop
     MaterialStream3.MW_p[:] := {MaterialStream3.MW_p[1] + MaterialStream3.x_pc[1,i] * MaterialStream3.C[i].MW, MaterialStream3.MW_p[2] + MaterialStream3.x_pc[2,i] * MaterialStream3.C[i].MW, MaterialStream3.MW_p[3] + MaterialStream3.x_pc[3,i] * MaterialStream3.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_611(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,611};
  real_array tmp4;
  index_spec_t tmp5;
  real_array tmp6;
  modelica_integer tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
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
      array_alloc_scalar_real_array(&tmp4, 3, (modelica_real)data->localData[0]->realVars[229] /* MaterialStream3._MW_p[1] variable */ + ((&data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[737])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[230] /* MaterialStream3._MW_p[2] variable */ + ((&data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[737])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[231] /* MaterialStream3._MW_p[3] variable */ + ((&data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[737])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp5, 1, (1), (int*)0, 'W');
      real_array_create(&tmp6, (modelica_real*)&data->localData[0]->realVars[229] /* MaterialStream3._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp4, &tmp6, &tmp5);
    }
  }
  TRACE_POP
}

/*
 equation index: 612
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_p[1] = 200.0 * MaterialStream3.MW_p[1]
 */
void Flowsheet_eqFunction_612(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,612};
  data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */ = (200.0) * (data->localData[0]->realVars[229] /* MaterialStream3._MW_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 613
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_p[2] = MaterialStream3.F_p[2] * MaterialStream3.MW_p[2]
 */
void Flowsheet_eqFunction_613(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,613};
  data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */ = (data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */) * (data->localData[0]->realVars[230] /* MaterialStream3._MW_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 614
 type: SIMPLE_ASSIGN
 MaterialStream3._xmliq = DIVISION(MaterialStream3.Fm_p[2], MaterialStream3.Fm_p[1])
 */
void Flowsheet_eqFunction_614(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,614};
  data->localData[0]->realVars[273] /* MaterialStream3._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */,data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */,"MaterialStream3.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 615
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[2,1] = MaterialStream3.x_pc[2,1] * MaterialStream3.F_p[2]
 */
void Flowsheet_eqFunction_615(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,615};
  data->localData[0]->realVars[202] /* MaterialStream3._F_pc[2,1] variable */ = (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */) * (data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 616
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[2,1] = MaterialStream3.F_pc[2,1] * MaterialStream3.C[1].MW
 */
void Flowsheet_eqFunction_616(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,616};
  data->localData[0]->realVars[211] /* MaterialStream3._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[202] /* MaterialStream3._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[737]);
  TRACE_POP
}

/*
 equation index: 617
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_p[2] = MaterialStream3.x_pc[2,1] * MaterialStream3.Cp_pc[2,1] + MaterialStream3.x_pc[2,2] * MaterialStream3.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_617(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,617};
  data->localData[0]->realVars[186] /* MaterialStream3._Cp_p[2] variable */ = (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */) * (data->localData[0]->realVars[190] /* MaterialStream3._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */) * (data->localData[0]->realVars[191] /* MaterialStream3._Cp_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 618
 type: ALGORITHM
 
   (MaterialStream3.S_pc[2,2], MaterialStream3.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, {MaterialStream3.C[2].HOV[1], MaterialStream3.C[2].HOV[2], MaterialStream3.C[2].HOV[3], MaterialStream3.C[2].HOV[4], MaterialStream3.C[2].HOV[5], MaterialStream3.C[2].HOV[6]}, MaterialStream3.C[2].Tb, MaterialStream3.C[2].Tc, MaterialStream3.T, 101325.0, MaterialStream3.x_pc[2,2], MaterialStream3.x_pc[3,2]);
 */
void Flowsheet_eqFunction_618(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,618};
  real_array tmp10;
  real_array tmp11;
  array_alloc_scalar_real_array(&tmp10, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  array_alloc_scalar_real_array(&tmp11, 6, (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680], (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684]);
  data->localData[0]->realVars[243] /* MaterialStream3._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp10, tmp11, data->simulationInfo->realParameter[752], data->simulationInfo->realParameter[754], data->localData[0]->realVars[249] /* MaterialStream3._T variable */, 101325.0, data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */, data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ ,&data->localData[0]->realVars[245] /* MaterialStream3._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 619
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[2,2] = MaterialStream3.x_pc[2,2] * MaterialStream3.F_p[2]
 */
void Flowsheet_eqFunction_619(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,619};
  data->localData[0]->realVars[203] /* MaterialStream3._F_pc[2,2] variable */ = (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */) * (data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 620
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[2,2] = MaterialStream3.F_pc[2,2] * MaterialStream3.C[2].MW
 */
void Flowsheet_eqFunction_620(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,620};
  data->localData[0]->realVars[212] /* MaterialStream3._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[203] /* MaterialStream3._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[738]);
  TRACE_POP
}

/*
 equation index: 621
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_p[3] = MaterialStream3.F_p[3] * MaterialStream3.MW_p[3]
 */
void Flowsheet_eqFunction_621(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,621};
  data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */ = (data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */) * (data->localData[0]->realVars[231] /* MaterialStream3._MW_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 622
 type: SIMPLE_ASSIGN
 MaterialStream3._xmvap = DIVISION(MaterialStream3.Fm_p[3], MaterialStream3.Fm_p[1])
 */
void Flowsheet_eqFunction_622(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,622};
  data->localData[0]->realVars[274] /* MaterialStream3._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */,data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */,"MaterialStream3.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 623
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[3,2] = MaterialStream3.x_pc[3,2] * MaterialStream3.F_p[3]
 */
void Flowsheet_eqFunction_623(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,623};
  data->localData[0]->realVars[205] /* MaterialStream3._F_pc[3,2] variable */ = (data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */) * (data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 624
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[3,2] = MaterialStream3.F_pc[3,2] * MaterialStream3.C[2].MW
 */
void Flowsheet_eqFunction_624(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,624};
  data->localData[0]->realVars[214] /* MaterialStream3._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[205] /* MaterialStream3._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[738]);
  TRACE_POP
}

/*
 equation index: 625
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_p[3] = MaterialStream3.x_pc[3,1] * MaterialStream3.Cp_pc[3,1] + MaterialStream3.x_pc[3,2] * MaterialStream3.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_625(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,625};
  data->localData[0]->realVars[187] /* MaterialStream3._Cp_p[3] variable */ = (data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */) * (data->localData[0]->realVars[192] /* MaterialStream3._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */) * (data->localData[0]->realVars[193] /* MaterialStream3._Cp_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 626
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_p[1] = MaterialStream3.xliq * MaterialStream3.Cp_p[2] + MaterialStream3.xvap * MaterialStream3.Cp_p[3]
 */
void Flowsheet_eqFunction_626(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,626};
  data->localData[0]->realVars[185] /* MaterialStream3._Cp_p[1] variable */ = (data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */) * (data->localData[0]->realVars[186] /* MaterialStream3._Cp_p[2] variable */) + (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (data->localData[0]->realVars[187] /* MaterialStream3._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 627
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[1,1] = MaterialStream3.x_pc[1,1] * MaterialStream3.Cp_p[1]
 */
void Flowsheet_eqFunction_627(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,627};
  data->localData[0]->realVars[188] /* MaterialStream3._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (data->localData[0]->realVars[185] /* MaterialStream3._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 628
 type: ALGORITHM
 
   (MaterialStream3.S_pc[2,1], MaterialStream3.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, {MaterialStream3.C[1].HOV[1], MaterialStream3.C[1].HOV[2], MaterialStream3.C[1].HOV[3], MaterialStream3.C[1].HOV[4], MaterialStream3.C[1].HOV[5], MaterialStream3.C[1].HOV[6]}, MaterialStream3.C[1].Tb, MaterialStream3.C[1].Tc, MaterialStream3.T, 101325.0, MaterialStream3.x_pc[2,1], MaterialStream3.x_pc[3,1]);
 */
void Flowsheet_eqFunction_628(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,628};
  real_array tmp12;
  real_array tmp13;
  array_alloc_scalar_real_array(&tmp12, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  array_alloc_scalar_real_array(&tmp13, 6, (modelica_real)data->simulationInfo->realParameter[673], (modelica_real)data->simulationInfo->realParameter[674], (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678]);
  data->localData[0]->realVars[242] /* MaterialStream3._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp12, tmp13, data->simulationInfo->realParameter[751], data->simulationInfo->realParameter[753], data->localData[0]->realVars[249] /* MaterialStream3._T variable */, 101325.0, data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */, data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ ,&data->localData[0]->realVars[244] /* MaterialStream3._S_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 629
 type: SIMPLE_ASSIGN
 MaterialStream3._S_p[2] = MaterialStream3.x_pc[2,1] * MaterialStream3.S_pc[2,1] + MaterialStream3.x_pc[2,2] * MaterialStream3.S_pc[2,2]
 */
void Flowsheet_eqFunction_629(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,629};
  data->localData[0]->realVars[238] /* MaterialStream3._S_p[2] variable */ = (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */) * (data->localData[0]->realVars[242] /* MaterialStream3._S_pc[2,1] variable */) + (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */) * (data->localData[0]->realVars[243] /* MaterialStream3._S_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 630
 type: SIMPLE_ASSIGN
 MaterialStream3._S_p[3] = MaterialStream3.x_pc[3,1] * MaterialStream3.S_pc[3,1] + MaterialStream3.x_pc[3,2] * MaterialStream3.S_pc[3,2]
 */
void Flowsheet_eqFunction_630(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,630};
  data->localData[0]->realVars[239] /* MaterialStream3._S_p[3] variable */ = (data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */) * (data->localData[0]->realVars[244] /* MaterialStream3._S_pc[3,1] variable */) + (data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */) * (data->localData[0]->realVars[245] /* MaterialStream3._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 631
 type: SIMPLE_ASSIGN
 MaterialStream3._S_p[1] = MaterialStream3.xliq * MaterialStream3.S_p[2] + MaterialStream3.xvap * MaterialStream3.S_p[3]
 */
void Flowsheet_eqFunction_631(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,631};
  data->localData[0]->realVars[237] /* MaterialStream3._S_p[1] variable */ = (data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */) * (data->localData[0]->realVars[238] /* MaterialStream3._S_p[2] variable */) + (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (data->localData[0]->realVars[239] /* MaterialStream3._S_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 632
 type: SIMPLE_ASSIGN
 MaterialStream3._S_pc[1,1] = MaterialStream3.x_pc[1,1] * MaterialStream3.S_p[1]
 */
void Flowsheet_eqFunction_632(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,632};
  data->localData[0]->realVars[240] /* MaterialStream3._S_pc[1,1] variable */ = (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (data->localData[0]->realVars[237] /* MaterialStream3._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 633
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[3,1] = MaterialStream3.x_pc[3,1] * MaterialStream3.F_p[3]
 */
void Flowsheet_eqFunction_633(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,633};
  data->localData[0]->realVars[204] /* MaterialStream3._F_pc[3,1] variable */ = (data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */) * (data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 634
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[3,1] = MaterialStream3.F_pc[3,1] * MaterialStream3.C[1].MW
 */
void Flowsheet_eqFunction_634(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,634};
  data->localData[0]->realVars[213] /* MaterialStream3._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[204] /* MaterialStream3._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[737]);
  TRACE_POP
}

/*
 equation index: 635
 type: SIMPLE_ASSIGN
 MaterialStream3._S_pc[1,2] = MaterialStream3.x_pc[1,2] * MaterialStream3.S_p[1]
 */
void Flowsheet_eqFunction_635(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,635};
  data->localData[0]->realVars[241] /* MaterialStream3._S_pc[1,2] variable */ = (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (data->localData[0]->realVars[237] /* MaterialStream3._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 636
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[1,2] = MaterialStream3.x_pc[1,2] * MaterialStream3.H_p[1]
 */
void Flowsheet_eqFunction_636(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,636};
  data->localData[0]->realVars[219] /* MaterialStream3._H_pc[1,2] variable */ = (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 637
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[1,2] = MaterialStream3.x_pc[1,2] * MaterialStream3.Cp_p[1]
 */
void Flowsheet_eqFunction_637(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,637};
  data->localData[0]->realVars[189] /* MaterialStream3._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (data->localData[0]->realVars[185] /* MaterialStream3._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 638
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[1,2] = 200.0 * MaterialStream3.x_pc[1,2]
 */
void Flowsheet_eqFunction_638(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,638};
  data->localData[0]->realVars[201] /* MaterialStream3._F_pc[1,2] variable */ = (200.0) * (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 639
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[1,2] = MaterialStream3.F_pc[1,2] * MaterialStream3.C[2].MW
 */
void Flowsheet_eqFunction_639(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,639};
  data->localData[0]->realVars[210] /* MaterialStream3._Fm_pc[1,2] variable */ = (data->localData[0]->realVars[201] /* MaterialStream3._F_pc[1,2] variable */) * (data->simulationInfo->realParameter[738]);
  TRACE_POP
}

/*
 equation index: 640
 type: SIMPLE_ASSIGN
 MaterialStream3._xm_pc[1,2] = DIVISION(MaterialStream3.Fm_pc[1,2], MaterialStream3.Fm_p[1])
 */
void Flowsheet_eqFunction_640(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,640};
  data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[210] /* MaterialStream3._Fm_pc[1,2] variable */,data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */,"MaterialStream3.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 641
 type: LINEAR
 
 <var>MaterialStream3._xm_pc[3,2]</var>
 <var>MaterialStream3._xm_pc[2,1]</var>
 <var>MaterialStream3._xm_pc[3,1]</var>
 <var>MaterialStream3._xm_pc[1,1]</var>
 <var>MaterialStream3._xm_pc[2,2]</var>
 <row>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then -MaterialStream3.xm_pc[1,2] else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[3,2] else -MaterialStream3.xm_pc[1,2]</cell>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[2,2] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then MaterialStream3.Fm_pc[1,1] else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[3,1] else MaterialStream3.Fm_pc[1,1]</cell>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[1,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[2,1] else 0.0</cell>
 </row>
 <matrix>
   <cell row="0" col="0">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[3] else 1.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="1" col="1">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="1" col="2">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then -1.0 else if 101325.0 >= MaterialStream3.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[2] else 0.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then -0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[3] else -0.0)</residual>
   </cell><cell row="2" col="3">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then -MaterialStream3.Fm_p[1] else if 101325.0 >= MaterialStream3.Pdew then -0.0 else -MaterialStream3.Fm_p[1])</residual>
   </cell><cell row="3" col="1">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="3" col="2">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="3" col="3">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[1] else 0.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="4" col="1">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[2] else 0.0)</residual>
   </cell><cell row="4" col="4">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -0.0 else 1.0)</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_641(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,641};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 641 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[6].x[0] = data->localData[1]->realVars[272] /* MaterialStream3._xm_pc[3,2] variable */;
  data->simulationInfo->linearSystemData[6].x[1] = data->localData[1]->realVars[269] /* MaterialStream3._xm_pc[2,1] variable */;
  data->simulationInfo->linearSystemData[6].x[2] = data->localData[1]->realVars[271] /* MaterialStream3._xm_pc[3,1] variable */;
  data->simulationInfo->linearSystemData[6].x[3] = data->localData[1]->realVars[267] /* MaterialStream3._xm_pc[1,1] variable */;
  data->simulationInfo->linearSystemData[6].x[4] = data->localData[1]->realVars[270] /* MaterialStream3._xm_pc[2,2] variable */;
  retValue = solve_linear_system(data, threadData, 6);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,641};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 641 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[272] /* MaterialStream3._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[6].x[0];
  data->localData[0]->realVars[269] /* MaterialStream3._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[6].x[1];
  data->localData[0]->realVars[271] /* MaterialStream3._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[6].x[2];
  data->localData[0]->realVars[267] /* MaterialStream3._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[6].x[3];
  data->localData[0]->realVars[270] /* MaterialStream3._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[6].x[4];
  TRACE_POP
}

/*
 equation index: 642
 type: SIMPLE_ASSIGN
 MaterialStream3._F_p[1] = 200.0
 */
void Flowsheet_eqFunction_642(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,642};
  data->localData[0]->realVars[197] /* MaterialStream3._F_p[1] variable */ = 200.0;
  TRACE_POP
}

/*
 equation index: 643
 type: SIMPLE_ASSIGN
 MaterialStream3._P = 101325.0
 */
void Flowsheet_eqFunction_643(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,643};
  data->localData[0]->realVars[232] /* MaterialStream3._P variable */ = 101325.0;
  TRACE_POP
}

/*
 equation index: 644
 type: SIMPLE_ASSIGN
 MaterialStream1._gmabubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_644(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,644};
  data->localData[0]->realVars[72] /* MaterialStream1._gmabubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 645
 type: SIMPLE_ASSIGN
 MaterialStream1._gmadew_c[1] = 1.0
 */
void Flowsheet_eqFunction_645(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,645};
  data->localData[0]->realVars[74] /* MaterialStream1._gmadew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 646
 type: SIMPLE_ASSIGN
 MaterialStream1._philiqbubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_646(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,646};
  data->localData[0]->realVars[76] /* MaterialStream1._philiqbubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 647
 type: SIMPLE_ASSIGN
 MaterialStream1._phivapdew_c[1] = 1.0
 */
void Flowsheet_eqFunction_647(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,647};
  data->localData[0]->realVars[78] /* MaterialStream1._phivapdew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 648
 type: SIMPLE_ASSIGN
 MaterialStream1._gmabubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_648(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,648};
  data->localData[0]->realVars[73] /* MaterialStream1._gmabubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 649
 type: SIMPLE_ASSIGN
 MaterialStream1._gmadew_c[2] = 1.0
 */
void Flowsheet_eqFunction_649(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,649};
  data->localData[0]->realVars[75] /* MaterialStream1._gmadew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 650
 type: SIMPLE_ASSIGN
 MaterialStream1._philiqbubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_650(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,650};
  data->localData[0]->realVars[77] /* MaterialStream1._philiqbubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 651
 type: SIMPLE_ASSIGN
 MaterialStream1._phivapdew_c[2] = 1.0
 */
void Flowsheet_eqFunction_651(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,651};
  data->localData[0]->realVars[79] /* MaterialStream1._phivapdew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 652
 type: SIMPLE_ASSIGN
 MaterialStream1._Cpres_p[2] = 0.0
 */
void Flowsheet_eqFunction_652(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,652};
  data->localData[0]->realVars[15] /* MaterialStream1._Cpres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 653
 type: SIMPLE_ASSIGN
 MaterialStream1._Cpres_p[3] = 0.0
 */
void Flowsheet_eqFunction_653(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,653};
  data->localData[0]->realVars[16] /* MaterialStream1._Cpres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 654
 type: SIMPLE_ASSIGN
 MaterialStream1._Hres_p[2] = 0.0
 */
void Flowsheet_eqFunction_654(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,654};
  data->localData[0]->realVars[45] /* MaterialStream1._Hres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 655
 type: SIMPLE_ASSIGN
 MaterialStream1._Hres_p[3] = 0.0
 */
void Flowsheet_eqFunction_655(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,655};
  data->localData[0]->realVars[46] /* MaterialStream1._Hres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 656
 type: SIMPLE_ASSIGN
 MaterialStream1._Sres_p[2] = 0.0
 */
void Flowsheet_eqFunction_656(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,656};
  data->localData[0]->realVars[67] /* MaterialStream1._Sres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 657
 type: SIMPLE_ASSIGN
 MaterialStream1._Sres_p[3] = 0.0
 */
void Flowsheet_eqFunction_657(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,657};
  data->localData[0]->realVars[68] /* MaterialStream1._Sres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 658
 type: SIMPLE_ASSIGN
 MaterialStream2._gmabubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_658(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,658};
  data->localData[0]->realVars[162] /* MaterialStream2._gmabubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 659
 type: SIMPLE_ASSIGN
 MaterialStream2._gmadew_c[1] = 1.0
 */
void Flowsheet_eqFunction_659(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,659};
  data->localData[0]->realVars[164] /* MaterialStream2._gmadew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 660
 type: SIMPLE_ASSIGN
 MaterialStream2._philiqbubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_660(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,660};
  data->localData[0]->realVars[166] /* MaterialStream2._philiqbubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 661
 type: SIMPLE_ASSIGN
 MaterialStream2._phivapdew_c[1] = 1.0
 */
void Flowsheet_eqFunction_661(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,661};
  data->localData[0]->realVars[168] /* MaterialStream2._phivapdew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 662
 type: SIMPLE_ASSIGN
 MaterialStream2._gmabubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_662(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,662};
  data->localData[0]->realVars[163] /* MaterialStream2._gmabubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 663
 type: SIMPLE_ASSIGN
 MaterialStream2._gmadew_c[2] = 1.0
 */
void Flowsheet_eqFunction_663(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,663};
  data->localData[0]->realVars[165] /* MaterialStream2._gmadew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 664
 type: SIMPLE_ASSIGN
 MaterialStream2._philiqbubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_664(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,664};
  data->localData[0]->realVars[167] /* MaterialStream2._philiqbubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 665
 type: SIMPLE_ASSIGN
 MaterialStream2._phivapdew_c[2] = 1.0
 */
void Flowsheet_eqFunction_665(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,665};
  data->localData[0]->realVars[169] /* MaterialStream2._phivapdew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 666
 type: SIMPLE_ASSIGN
 MaterialStream2._Cpres_p[2] = 0.0
 */
void Flowsheet_eqFunction_666(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,666};
  data->localData[0]->realVars[105] /* MaterialStream2._Cpres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 667
 type: SIMPLE_ASSIGN
 MaterialStream2._Cpres_p[3] = 0.0
 */
void Flowsheet_eqFunction_667(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,667};
  data->localData[0]->realVars[106] /* MaterialStream2._Cpres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 668
 type: SIMPLE_ASSIGN
 MaterialStream2._Hres_p[2] = 0.0
 */
void Flowsheet_eqFunction_668(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,668};
  data->localData[0]->realVars[135] /* MaterialStream2._Hres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 669
 type: SIMPLE_ASSIGN
 MaterialStream2._Hres_p[3] = 0.0
 */
void Flowsheet_eqFunction_669(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,669};
  data->localData[0]->realVars[136] /* MaterialStream2._Hres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 670
 type: SIMPLE_ASSIGN
 MaterialStream2._Sres_p[2] = 0.0
 */
void Flowsheet_eqFunction_670(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,670};
  data->localData[0]->realVars[157] /* MaterialStream2._Sres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 671
 type: SIMPLE_ASSIGN
 MaterialStream2._Sres_p[3] = 0.0
 */
void Flowsheet_eqFunction_671(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,671};
  data->localData[0]->realVars[158] /* MaterialStream2._Sres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 672
 type: SIMPLE_ASSIGN
 MaterialStream3._gmabubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_672(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,672};
  data->localData[0]->realVars[252] /* MaterialStream3._gmabubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 673
 type: SIMPLE_ASSIGN
 MaterialStream3._gmadew_c[1] = 1.0
 */
void Flowsheet_eqFunction_673(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,673};
  data->localData[0]->realVars[254] /* MaterialStream3._gmadew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 674
 type: SIMPLE_ASSIGN
 MaterialStream3._philiqbubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_674(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,674};
  data->localData[0]->realVars[256] /* MaterialStream3._philiqbubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 675
 type: SIMPLE_ASSIGN
 MaterialStream3._phivapdew_c[1] = 1.0
 */
void Flowsheet_eqFunction_675(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,675};
  data->localData[0]->realVars[258] /* MaterialStream3._phivapdew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 676
 type: SIMPLE_ASSIGN
 MaterialStream3._gmabubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_676(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,676};
  data->localData[0]->realVars[253] /* MaterialStream3._gmabubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 677
 type: SIMPLE_ASSIGN
 MaterialStream3._gmadew_c[2] = 1.0
 */
void Flowsheet_eqFunction_677(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,677};
  data->localData[0]->realVars[255] /* MaterialStream3._gmadew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 678
 type: SIMPLE_ASSIGN
 MaterialStream3._philiqbubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_678(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,678};
  data->localData[0]->realVars[257] /* MaterialStream3._philiqbubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 679
 type: SIMPLE_ASSIGN
 MaterialStream3._phivapdew_c[2] = 1.0
 */
void Flowsheet_eqFunction_679(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,679};
  data->localData[0]->realVars[259] /* MaterialStream3._phivapdew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 680
 type: SIMPLE_ASSIGN
 MaterialStream3._Cpres_p[2] = 0.0
 */
void Flowsheet_eqFunction_680(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,680};
  data->localData[0]->realVars[195] /* MaterialStream3._Cpres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 681
 type: SIMPLE_ASSIGN
 MaterialStream3._Cpres_p[3] = 0.0
 */
void Flowsheet_eqFunction_681(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,681};
  data->localData[0]->realVars[196] /* MaterialStream3._Cpres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 682
 type: SIMPLE_ASSIGN
 MaterialStream3._Hres_p[2] = 0.0
 */
void Flowsheet_eqFunction_682(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,682};
  data->localData[0]->realVars[225] /* MaterialStream3._Hres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 683
 type: SIMPLE_ASSIGN
 MaterialStream3._Hres_p[3] = 0.0
 */
void Flowsheet_eqFunction_683(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,683};
  data->localData[0]->realVars[226] /* MaterialStream3._Hres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 684
 type: SIMPLE_ASSIGN
 MaterialStream3._Sres_p[2] = 0.0
 */
void Flowsheet_eqFunction_684(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,684};
  data->localData[0]->realVars[247] /* MaterialStream3._Sres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 685
 type: SIMPLE_ASSIGN
 MaterialStream3._Sres_p[3] = 0.0
 */
void Flowsheet_eqFunction_685(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,685};
  data->localData[0]->realVars[248] /* MaterialStream3._Sres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 686
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[1] = 100.0
 */
void Flowsheet_eqFunction_686(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,686};
  data->localData[0]->realVars[17] /* MaterialStream1._F_p[1] variable */ = 100.0;
  TRACE_POP
}

/*
 equation index: 687
 type: SIMPLE_ASSIGN
 MaterialStream1._P = 101325.0
 */
void Flowsheet_eqFunction_687(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,687};
  data->localData[0]->realVars[52] /* MaterialStream1._P variable */ = 101325.0;
  TRACE_POP
}

/*
 equation index: 688
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p[1] = 100.0
 */
void Flowsheet_eqFunction_688(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,688};
  data->localData[0]->realVars[107] /* MaterialStream2._F_p[1] variable */ = 100.0;
  TRACE_POP
}

/*
 equation index: 689
 type: SIMPLE_ASSIGN
 MaterialStream2._P = 101325.0
 */
void Flowsheet_eqFunction_689(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,689};
  data->localData[0]->realVars[142] /* MaterialStream2._P variable */ = 101325.0;
  TRACE_POP
}

/*
 equation index: 690
 type: SIMPLE_ASSIGN
 MaterialStream3._Tc[2] = MaterialStream3.C[2].Tc
 */
void Flowsheet_eqFunction_690(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,690};
  data->simulationInfo->realParameter[842] = data->simulationInfo->realParameter[754];
  TRACE_POP
}

/*
 equation index: 691
 type: SIMPLE_ASSIGN
 MaterialStream3._Tc[1] = MaterialStream3.C[1].Tc
 */
void Flowsheet_eqFunction_691(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,691};
  data->simulationInfo->realParameter[841] = data->simulationInfo->realParameter[753];
  TRACE_POP
}

/*
 equation index: 692
 type: SIMPLE_ASSIGN
 Mixer1._Tc[2] = Mixer1.C[2].Tc
 */
void Flowsheet_eqFunction_692(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,692};
  data->simulationInfo->realParameter[1049] = data->simulationInfo->realParameter[961];
  TRACE_POP
}

/*
 equation index: 693
 type: SIMPLE_ASSIGN
 Mixer1._Tc[1] = Mixer1.C[1].Tc
 */
void Flowsheet_eqFunction_693(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,693};
  data->simulationInfo->realParameter[1048] = data->simulationInfo->realParameter[960];
  TRACE_POP
}

/*
 equation index: 694
 type: SIMPLE_ASSIGN
 MaterialStream2._Tc[2] = MaterialStream2.C[2].Tc
 */
void Flowsheet_eqFunction_694(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,694};
  data->simulationInfo->realParameter[635] = data->simulationInfo->realParameter[547];
  TRACE_POP
}

/*
 equation index: 695
 type: SIMPLE_ASSIGN
 MaterialStream2._Tc[1] = MaterialStream2.C[1].Tc
 */
void Flowsheet_eqFunction_695(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,695};
  data->simulationInfo->realParameter[634] = data->simulationInfo->realParameter[546];
  TRACE_POP
}

/*
 equation index: 696
 type: SIMPLE_ASSIGN
 MaterialStream1._Tc[2] = MaterialStream1.C[2].Tc
 */
void Flowsheet_eqFunction_696(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,696};
  data->simulationInfo->realParameter[428] = data->simulationInfo->realParameter[340];
  TRACE_POP
}

/*
 equation index: 697
 type: SIMPLE_ASSIGN
 MaterialStream1._Tc[1] = MaterialStream1.C[1].Tc
 */
void Flowsheet_eqFunction_697(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,697};
  data->simulationInfo->realParameter[427] = data->simulationInfo->realParameter[339];
  TRACE_POP
}
void Flowsheet_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Flowsheet_eqFunction_1(data, threadData);
  Flowsheet_eqFunction_2(data, threadData);
  Flowsheet_eqFunction_3(data, threadData);
  Flowsheet_eqFunction_4(data, threadData);
  Flowsheet_eqFunction_5(data, threadData);
  Flowsheet_eqFunction_6(data, threadData);
  Flowsheet_eqFunction_7(data, threadData);
  Flowsheet_eqFunction_8(data, threadData);
  Flowsheet_eqFunction_9(data, threadData);
  Flowsheet_eqFunction_10(data, threadData);
  Flowsheet_eqFunction_11(data, threadData);
  Flowsheet_eqFunction_12(data, threadData);
  Flowsheet_eqFunction_13(data, threadData);
  Flowsheet_eqFunction_14(data, threadData);
  Flowsheet_eqFunction_15(data, threadData);
  Flowsheet_eqFunction_16(data, threadData);
  Flowsheet_eqFunction_17(data, threadData);
  Flowsheet_eqFunction_18(data, threadData);
  Flowsheet_eqFunction_19(data, threadData);
  Flowsheet_eqFunction_20(data, threadData);
  Flowsheet_eqFunction_21(data, threadData);
  Flowsheet_eqFunction_22(data, threadData);
  Flowsheet_eqFunction_23(data, threadData);
  Flowsheet_eqFunction_24(data, threadData);
  Flowsheet_eqFunction_25(data, threadData);
  Flowsheet_eqFunction_26(data, threadData);
  Flowsheet_eqFunction_27(data, threadData);
  Flowsheet_eqFunction_28(data, threadData);
  Flowsheet_eqFunction_29(data, threadData);
  Flowsheet_eqFunction_30(data, threadData);
  Flowsheet_eqFunction_31(data, threadData);
  Flowsheet_eqFunction_32(data, threadData);
  Flowsheet_eqFunction_33(data, threadData);
  Flowsheet_eqFunction_34(data, threadData);
  Flowsheet_eqFunction_35(data, threadData);
  Flowsheet_eqFunction_36(data, threadData);
  Flowsheet_eqFunction_37(data, threadData);
  Flowsheet_eqFunction_38(data, threadData);
  Flowsheet_eqFunction_39(data, threadData);
  Flowsheet_eqFunction_40(data, threadData);
  Flowsheet_eqFunction_41(data, threadData);
  Flowsheet_eqFunction_42(data, threadData);
  Flowsheet_eqFunction_46(data, threadData);
  Flowsheet_eqFunction_50(data, threadData);
  Flowsheet_eqFunction_51(data, threadData);
  Flowsheet_eqFunction_52(data, threadData);
  Flowsheet_eqFunction_53(data, threadData);
  Flowsheet_eqFunction_54(data, threadData);
  Flowsheet_eqFunction_55(data, threadData);
  Flowsheet_eqFunction_56(data, threadData);
  Flowsheet_eqFunction_57(data, threadData);
  Flowsheet_eqFunction_58(data, threadData);
  Flowsheet_eqFunction_59(data, threadData);
  Flowsheet_eqFunction_60(data, threadData);
  Flowsheet_eqFunction_61(data, threadData);
  Flowsheet_eqFunction_62(data, threadData);
  Flowsheet_eqFunction_63(data, threadData);
  Flowsheet_eqFunction_64(data, threadData);
  Flowsheet_eqFunction_65(data, threadData);
  Flowsheet_eqFunction_66(data, threadData);
  Flowsheet_eqFunction_67(data, threadData);
  Flowsheet_eqFunction_68(data, threadData);
  Flowsheet_eqFunction_69(data, threadData);
  Flowsheet_eqFunction_73(data, threadData);
  Flowsheet_eqFunction_74(data, threadData);
  Flowsheet_eqFunction_75(data, threadData);
  Flowsheet_eqFunction_76(data, threadData);
  Flowsheet_eqFunction_80(data, threadData);
  Flowsheet_eqFunction_81(data, threadData);
  Flowsheet_eqFunction_92(data, threadData);
  Flowsheet_eqFunction_96(data, threadData);
  Flowsheet_eqFunction_97(data, threadData);
  Flowsheet_eqFunction_98(data, threadData);
  Flowsheet_eqFunction_102(data, threadData);
  Flowsheet_eqFunction_106(data, threadData);
  Flowsheet_eqFunction_107(data, threadData);
  Flowsheet_eqFunction_108(data, threadData);
  Flowsheet_eqFunction_109(data, threadData);
  Flowsheet_eqFunction_110(data, threadData);
  Flowsheet_eqFunction_121(data, threadData);
  Flowsheet_eqFunction_125(data, threadData);
  Flowsheet_eqFunction_126(data, threadData);
  Flowsheet_eqFunction_127(data, threadData);
  Flowsheet_eqFunction_131(data, threadData);
  Flowsheet_eqFunction_132(data, threadData);
  Flowsheet_eqFunction_133(data, threadData);
  Flowsheet_eqFunction_134(data, threadData);
  Flowsheet_eqFunction_135(data, threadData);
  Flowsheet_eqFunction_136(data, threadData);
  Flowsheet_eqFunction_137(data, threadData);
  Flowsheet_eqFunction_138(data, threadData);
  Flowsheet_eqFunction_139(data, threadData);
  Flowsheet_eqFunction_140(data, threadData);
  Flowsheet_eqFunction_141(data, threadData);
  Flowsheet_eqFunction_142(data, threadData);
  Flowsheet_eqFunction_143(data, threadData);
  Flowsheet_eqFunction_144(data, threadData);
  Flowsheet_eqFunction_145(data, threadData);
  Flowsheet_eqFunction_146(data, threadData);
  Flowsheet_eqFunction_147(data, threadData);
  Flowsheet_eqFunction_148(data, threadData);
  Flowsheet_eqFunction_149(data, threadData);
  Flowsheet_eqFunction_150(data, threadData);
  Flowsheet_eqFunction_151(data, threadData);
  Flowsheet_eqFunction_155(data, threadData);
  Flowsheet_eqFunction_159(data, threadData);
  Flowsheet_eqFunction_160(data, threadData);
  Flowsheet_eqFunction_161(data, threadData);
  Flowsheet_eqFunction_162(data, threadData);
  Flowsheet_eqFunction_163(data, threadData);
  Flowsheet_eqFunction_164(data, threadData);
  Flowsheet_eqFunction_165(data, threadData);
  Flowsheet_eqFunction_166(data, threadData);
  Flowsheet_eqFunction_167(data, threadData);
  Flowsheet_eqFunction_168(data, threadData);
  Flowsheet_eqFunction_169(data, threadData);
  Flowsheet_eqFunction_170(data, threadData);
  Flowsheet_eqFunction_171(data, threadData);
  Flowsheet_eqFunction_172(data, threadData);
  Flowsheet_eqFunction_173(data, threadData);
  Flowsheet_eqFunction_174(data, threadData);
  Flowsheet_eqFunction_175(data, threadData);
  Flowsheet_eqFunction_176(data, threadData);
  Flowsheet_eqFunction_180(data, threadData);
  Flowsheet_eqFunction_181(data, threadData);
  Flowsheet_eqFunction_185(data, threadData);
  Flowsheet_eqFunction_186(data, threadData);
  Flowsheet_eqFunction_197(data, threadData);
  Flowsheet_eqFunction_201(data, threadData);
  Flowsheet_eqFunction_205(data, threadData);
  Flowsheet_eqFunction_209(data, threadData);
  Flowsheet_eqFunction_220(data, threadData);
  Flowsheet_eqFunction_224(data, threadData);
  Flowsheet_eqFunction_228(data, threadData);
  Flowsheet_eqFunction_229(data, threadData);
  Flowsheet_eqFunction_230(data, threadData);
  Flowsheet_eqFunction_231(data, threadData);
  Flowsheet_eqFunction_232(data, threadData);
  Flowsheet_eqFunction_233(data, threadData);
  Flowsheet_eqFunction_234(data, threadData);
  Flowsheet_eqFunction_235(data, threadData);
  Flowsheet_eqFunction_236(data, threadData);
  Flowsheet_eqFunction_237(data, threadData);
  Flowsheet_eqFunction_238(data, threadData);
  Flowsheet_eqFunction_239(data, threadData);
  Flowsheet_eqFunction_243(data, threadData);
  Flowsheet_eqFunction_247(data, threadData);
  Flowsheet_eqFunction_248(data, threadData);
  Flowsheet_eqFunction_249(data, threadData);
  Flowsheet_eqFunction_250(data, threadData);
  Flowsheet_eqFunction_251(data, threadData);
  Flowsheet_eqFunction_252(data, threadData);
  Flowsheet_eqFunction_253(data, threadData);
  Flowsheet_eqFunction_254(data, threadData);
  Flowsheet_eqFunction_255(data, threadData);
  Flowsheet_eqFunction_256(data, threadData);
  Flowsheet_eqFunction_257(data, threadData);
  Flowsheet_eqFunction_258(data, threadData);
  Flowsheet_eqFunction_259(data, threadData);
  Flowsheet_eqFunction_260(data, threadData);
  Flowsheet_eqFunction_261(data, threadData);
  Flowsheet_eqFunction_262(data, threadData);
  Flowsheet_eqFunction_263(data, threadData);
  Flowsheet_eqFunction_264(data, threadData);
  Flowsheet_eqFunction_268(data, threadData);
  Flowsheet_eqFunction_269(data, threadData);
  Flowsheet_eqFunction_270(data, threadData);
  Flowsheet_eqFunction_271(data, threadData);
  Flowsheet_eqFunction_275(data, threadData);
  Flowsheet_eqFunction_276(data, threadData);
  Flowsheet_eqFunction_287(data, threadData);
  Flowsheet_eqFunction_291(data, threadData);
  Flowsheet_eqFunction_292(data, threadData);
  Flowsheet_eqFunction_293(data, threadData);
  Flowsheet_eqFunction_297(data, threadData);
  Flowsheet_eqFunction_301(data, threadData);
  Flowsheet_eqFunction_302(data, threadData);
  Flowsheet_eqFunction_303(data, threadData);
  Flowsheet_eqFunction_304(data, threadData);
  Flowsheet_eqFunction_305(data, threadData);
  Flowsheet_eqFunction_316(data, threadData);
  Flowsheet_eqFunction_320(data, threadData);
  Flowsheet_eqFunction_321(data, threadData);
  Flowsheet_eqFunction_322(data, threadData);
  Flowsheet_eqFunction_326(data, threadData);
  Flowsheet_eqFunction_327(data, threadData);
  Flowsheet_eqFunction_328(data, threadData);
  Flowsheet_eqFunction_329(data, threadData);
  Flowsheet_eqFunction_330(data, threadData);
  Flowsheet_eqFunction_331(data, threadData);
  Flowsheet_eqFunction_332(data, threadData);
  Flowsheet_eqFunction_333(data, threadData);
  Flowsheet_eqFunction_334(data, threadData);
  Flowsheet_eqFunction_335(data, threadData);
  Flowsheet_eqFunction_336(data, threadData);
  Flowsheet_eqFunction_337(data, threadData);
  Flowsheet_eqFunction_338(data, threadData);
  Flowsheet_eqFunction_339(data, threadData);
  Flowsheet_eqFunction_340(data, threadData);
  Flowsheet_eqFunction_341(data, threadData);
  Flowsheet_eqFunction_342(data, threadData);
  Flowsheet_eqFunction_343(data, threadData);
  Flowsheet_eqFunction_344(data, threadData);
  Flowsheet_eqFunction_345(data, threadData);
  Flowsheet_eqFunction_349(data, threadData);
  Flowsheet_eqFunction_353(data, threadData);
  Flowsheet_eqFunction_354(data, threadData);
  Flowsheet_eqFunction_355(data, threadData);
  Flowsheet_eqFunction_356(data, threadData);
  Flowsheet_eqFunction_357(data, threadData);
  Flowsheet_eqFunction_358(data, threadData);
  Flowsheet_eqFunction_359(data, threadData);
  Flowsheet_eqFunction_360(data, threadData);
  Flowsheet_eqFunction_361(data, threadData);
  Flowsheet_eqFunction_362(data, threadData);
  Flowsheet_eqFunction_363(data, threadData);
  Flowsheet_eqFunction_364(data, threadData);
  Flowsheet_eqFunction_365(data, threadData);
  Flowsheet_eqFunction_366(data, threadData);
  Flowsheet_eqFunction_367(data, threadData);
  Flowsheet_eqFunction_368(data, threadData);
  Flowsheet_eqFunction_369(data, threadData);
  Flowsheet_eqFunction_370(data, threadData);
  Flowsheet_eqFunction_374(data, threadData);
  Flowsheet_eqFunction_375(data, threadData);
  Flowsheet_eqFunction_376(data, threadData);
  Flowsheet_eqFunction_377(data, threadData);
  Flowsheet_eqFunction_381(data, threadData);
  Flowsheet_eqFunction_382(data, threadData);
  Flowsheet_eqFunction_393(data, threadData);
  Flowsheet_eqFunction_397(data, threadData);
  Flowsheet_eqFunction_398(data, threadData);
  Flowsheet_eqFunction_399(data, threadData);
  Flowsheet_eqFunction_403(data, threadData);
  Flowsheet_eqFunction_407(data, threadData);
  Flowsheet_eqFunction_408(data, threadData);
  Flowsheet_eqFunction_409(data, threadData);
  Flowsheet_eqFunction_410(data, threadData);
  Flowsheet_eqFunction_411(data, threadData);
  Flowsheet_eqFunction_422(data, threadData);
  Flowsheet_eqFunction_426(data, threadData);
  Flowsheet_eqFunction_427(data, threadData);
  Flowsheet_eqFunction_428(data, threadData);
  Flowsheet_eqFunction_432(data, threadData);
  Flowsheet_eqFunction_433(data, threadData);
  Flowsheet_eqFunction_434(data, threadData);
  Flowsheet_eqFunction_435(data, threadData);
  Flowsheet_eqFunction_436(data, threadData);
  Flowsheet_eqFunction_437(data, threadData);
  Flowsheet_eqFunction_438(data, threadData);
  Flowsheet_eqFunction_439(data, threadData);
  Flowsheet_eqFunction_440(data, threadData);
  Flowsheet_eqFunction_441(data, threadData);
  Flowsheet_eqFunction_442(data, threadData);
  Flowsheet_eqFunction_443(data, threadData);
  Flowsheet_eqFunction_444(data, threadData);
  Flowsheet_eqFunction_445(data, threadData);
  Flowsheet_eqFunction_446(data, threadData);
  Flowsheet_eqFunction_447(data, threadData);
  Flowsheet_eqFunction_448(data, threadData);
  Flowsheet_eqFunction_449(data, threadData);
  Flowsheet_eqFunction_450(data, threadData);
  Flowsheet_eqFunction_451(data, threadData);
  Flowsheet_eqFunction_452(data, threadData);
  Flowsheet_eqFunction_453(data, threadData);
  Flowsheet_eqFunction_454(data, threadData);
  Flowsheet_eqFunction_455(data, threadData);
  Flowsheet_eqFunction_456(data, threadData);
  Flowsheet_eqFunction_457(data, threadData);
  Flowsheet_eqFunction_458(data, threadData);
  Flowsheet_eqFunction_459(data, threadData);
  Flowsheet_eqFunction_460(data, threadData);
  Flowsheet_eqFunction_461(data, threadData);
  Flowsheet_eqFunction_462(data, threadData);
  Flowsheet_eqFunction_463(data, threadData);
  Flowsheet_eqFunction_464(data, threadData);
  Flowsheet_eqFunction_465(data, threadData);
  Flowsheet_eqFunction_466(data, threadData);
  Flowsheet_eqFunction_483(data, threadData);
  Flowsheet_eqFunction_484(data, threadData);
  Flowsheet_eqFunction_485(data, threadData);
  Flowsheet_eqFunction_486(data, threadData);
  Flowsheet_eqFunction_487(data, threadData);
  Flowsheet_eqFunction_488(data, threadData);
  Flowsheet_eqFunction_489(data, threadData);
  Flowsheet_eqFunction_490(data, threadData);
  Flowsheet_eqFunction_491(data, threadData);
  Flowsheet_eqFunction_492(data, threadData);
  Flowsheet_eqFunction_493(data, threadData);
  Flowsheet_eqFunction_494(data, threadData);
  Flowsheet_eqFunction_495(data, threadData);
  Flowsheet_eqFunction_496(data, threadData);
  Flowsheet_eqFunction_497(data, threadData);
  Flowsheet_eqFunction_498(data, threadData);
  Flowsheet_eqFunction_499(data, threadData);
  Flowsheet_eqFunction_500(data, threadData);
  Flowsheet_eqFunction_501(data, threadData);
  Flowsheet_eqFunction_502(data, threadData);
  Flowsheet_eqFunction_503(data, threadData);
  Flowsheet_eqFunction_504(data, threadData);
  Flowsheet_eqFunction_505(data, threadData);
  Flowsheet_eqFunction_506(data, threadData);
  Flowsheet_eqFunction_507(data, threadData);
  Flowsheet_eqFunction_508(data, threadData);
  Flowsheet_eqFunction_509(data, threadData);
  Flowsheet_eqFunction_510(data, threadData);
  Flowsheet_eqFunction_511(data, threadData);
  Flowsheet_eqFunction_512(data, threadData);
  Flowsheet_eqFunction_513(data, threadData);
  Flowsheet_eqFunction_514(data, threadData);
  Flowsheet_eqFunction_515(data, threadData);
  Flowsheet_eqFunction_516(data, threadData);
  Flowsheet_eqFunction_517(data, threadData);
  Flowsheet_eqFunction_518(data, threadData);
  Flowsheet_eqFunction_519(data, threadData);
  Flowsheet_eqFunction_520(data, threadData);
  Flowsheet_eqFunction_521(data, threadData);
  Flowsheet_eqFunction_522(data, threadData);
  Flowsheet_eqFunction_523(data, threadData);
  Flowsheet_eqFunction_524(data, threadData);
  Flowsheet_eqFunction_525(data, threadData);
  Flowsheet_eqFunction_526(data, threadData);
  Flowsheet_eqFunction_527(data, threadData);
  Flowsheet_eqFunction_528(data, threadData);
  Flowsheet_eqFunction_529(data, threadData);
  Flowsheet_eqFunction_530(data, threadData);
  Flowsheet_eqFunction_531(data, threadData);
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
  Flowsheet_eqFunction_565(data, threadData);
  Flowsheet_eqFunction_566(data, threadData);
  Flowsheet_eqFunction_567(data, threadData);
  Flowsheet_eqFunction_568(data, threadData);
  Flowsheet_eqFunction_569(data, threadData);
  Flowsheet_eqFunction_570(data, threadData);
  Flowsheet_eqFunction_571(data, threadData);
  Flowsheet_eqFunction_572(data, threadData);
  Flowsheet_eqFunction_573(data, threadData);
  Flowsheet_eqFunction_574(data, threadData);
  Flowsheet_eqFunction_575(data, threadData);
  Flowsheet_eqFunction_576(data, threadData);
  Flowsheet_eqFunction_577(data, threadData);
  Flowsheet_eqFunction_578(data, threadData);
  Flowsheet_eqFunction_579(data, threadData);
  Flowsheet_eqFunction_580(data, threadData);
  Flowsheet_eqFunction_581(data, threadData);
  Flowsheet_eqFunction_582(data, threadData);
  Flowsheet_eqFunction_583(data, threadData);
  Flowsheet_eqFunction_584(data, threadData);
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
  Flowsheet_eqFunction_616(data, threadData);
  Flowsheet_eqFunction_617(data, threadData);
  Flowsheet_eqFunction_618(data, threadData);
  Flowsheet_eqFunction_619(data, threadData);
  Flowsheet_eqFunction_620(data, threadData);
  Flowsheet_eqFunction_621(data, threadData);
  Flowsheet_eqFunction_622(data, threadData);
  Flowsheet_eqFunction_623(data, threadData);
  Flowsheet_eqFunction_624(data, threadData);
  Flowsheet_eqFunction_625(data, threadData);
  Flowsheet_eqFunction_626(data, threadData);
  Flowsheet_eqFunction_627(data, threadData);
  Flowsheet_eqFunction_628(data, threadData);
  Flowsheet_eqFunction_629(data, threadData);
  Flowsheet_eqFunction_630(data, threadData);
  Flowsheet_eqFunction_631(data, threadData);
  Flowsheet_eqFunction_632(data, threadData);
  Flowsheet_eqFunction_633(data, threadData);
  Flowsheet_eqFunction_634(data, threadData);
  Flowsheet_eqFunction_635(data, threadData);
  Flowsheet_eqFunction_636(data, threadData);
  Flowsheet_eqFunction_637(data, threadData);
  Flowsheet_eqFunction_638(data, threadData);
  Flowsheet_eqFunction_639(data, threadData);
  Flowsheet_eqFunction_640(data, threadData);
  Flowsheet_eqFunction_641(data, threadData);
  Flowsheet_eqFunction_642(data, threadData);
  Flowsheet_eqFunction_643(data, threadData);
  Flowsheet_eqFunction_644(data, threadData);
  Flowsheet_eqFunction_645(data, threadData);
  Flowsheet_eqFunction_646(data, threadData);
  Flowsheet_eqFunction_647(data, threadData);
  Flowsheet_eqFunction_648(data, threadData);
  Flowsheet_eqFunction_649(data, threadData);
  Flowsheet_eqFunction_650(data, threadData);
  Flowsheet_eqFunction_651(data, threadData);
  Flowsheet_eqFunction_652(data, threadData);
  Flowsheet_eqFunction_653(data, threadData);
  Flowsheet_eqFunction_654(data, threadData);
  Flowsheet_eqFunction_655(data, threadData);
  Flowsheet_eqFunction_656(data, threadData);
  Flowsheet_eqFunction_657(data, threadData);
  Flowsheet_eqFunction_658(data, threadData);
  Flowsheet_eqFunction_659(data, threadData);
  Flowsheet_eqFunction_660(data, threadData);
  Flowsheet_eqFunction_661(data, threadData);
  Flowsheet_eqFunction_662(data, threadData);
  Flowsheet_eqFunction_663(data, threadData);
  Flowsheet_eqFunction_664(data, threadData);
  Flowsheet_eqFunction_665(data, threadData);
  Flowsheet_eqFunction_666(data, threadData);
  Flowsheet_eqFunction_667(data, threadData);
  Flowsheet_eqFunction_668(data, threadData);
  Flowsheet_eqFunction_669(data, threadData);
  Flowsheet_eqFunction_670(data, threadData);
  Flowsheet_eqFunction_671(data, threadData);
  Flowsheet_eqFunction_672(data, threadData);
  Flowsheet_eqFunction_673(data, threadData);
  Flowsheet_eqFunction_674(data, threadData);
  Flowsheet_eqFunction_675(data, threadData);
  Flowsheet_eqFunction_676(data, threadData);
  Flowsheet_eqFunction_677(data, threadData);
  Flowsheet_eqFunction_678(data, threadData);
  Flowsheet_eqFunction_679(data, threadData);
  Flowsheet_eqFunction_680(data, threadData);
  Flowsheet_eqFunction_681(data, threadData);
  Flowsheet_eqFunction_682(data, threadData);
  Flowsheet_eqFunction_683(data, threadData);
  Flowsheet_eqFunction_684(data, threadData);
  Flowsheet_eqFunction_685(data, threadData);
  Flowsheet_eqFunction_686(data, threadData);
  Flowsheet_eqFunction_687(data, threadData);
  Flowsheet_eqFunction_688(data, threadData);
  Flowsheet_eqFunction_689(data, threadData);
  Flowsheet_eqFunction_690(data, threadData);
  Flowsheet_eqFunction_691(data, threadData);
  Flowsheet_eqFunction_692(data, threadData);
  Flowsheet_eqFunction_693(data, threadData);
  Flowsheet_eqFunction_694(data, threadData);
  Flowsheet_eqFunction_695(data, threadData);
  Flowsheet_eqFunction_696(data, threadData);
  Flowsheet_eqFunction_697(data, threadData);
  TRACE_POP
}


int Flowsheet_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Flowsheet_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int Flowsheet_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int Flowsheet_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

