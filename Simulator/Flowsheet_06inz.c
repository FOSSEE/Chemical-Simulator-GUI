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
  data->localData[0]->realVars[75] /* MaterialStream1._gma_c[1] variable */ = 1.0;
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
  data->localData[0]->realVars[76] /* MaterialStream1._gma_c[2] variable */ = 1.0;
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
  data->localData[0]->realVars[19] /* MaterialStream1._Cpres_p[1] variable */ = 0.0;
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
  data->localData[0]->realVars[49] /* MaterialStream1._Hres_p[1] variable */ = 0.0;
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
  data->localData[0]->realVars[71] /* MaterialStream1._Sres_p[1] variable */ = 0.0;
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
  data->localData[0]->realVars[162] /* MaterialStream2._gma_c[1] variable */ = 1.0;
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
  data->localData[0]->realVars[163] /* MaterialStream2._gma_c[2] variable */ = 1.0;
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
  data->localData[0]->realVars[109] /* MaterialStream2._Cpres_p[1] variable */ = 0.0;
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
  data->localData[0]->realVars[138] /* MaterialStream2._Hres_p[1] variable */ = 0.0;
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
  data->localData[0]->realVars[159] /* MaterialStream2._Sres_p[1] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 11
 type: SIMPLE_ASSIGN
 Heater1._Tdel = 30.0
 */
void Flowsheet_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  data->localData[0]->realVars[6] /* Heater1._Tdel variable */ = 30.0;
  TRACE_POP
}

/*
 equation index: 12
 type: SIMPLE_ASSIGN
 Heater1._Pout = 101325.0 - Heater1.Pdel
 */
void Flowsheet_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[4] /* Heater1._Pout variable */ = 101325.0 - data->simulationInfo->realParameter[413];
  TRACE_POP
}

/*
 equation index: 13
 type: SIMPLE_ASSIGN
 MaterialStream2._Pvap_c[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[2].VP[1], MaterialStream2.C[2].VP[2], MaterialStream2.C[2].VP[3], MaterialStream2.C[2].VP[4], MaterialStream2.C[2].VP[5], MaterialStream2.C[2].VP[6]}, 380.0)
 */
void Flowsheet_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[769], (modelica_real)data->simulationInfo->realParameter[770], (modelica_real)data->simulationInfo->realParameter[771], (modelica_real)data->simulationInfo->realParameter[772], (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774]);
  data->localData[0]->realVars[149] /* MaterialStream2._Pvap_c[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, 380.0);
  TRACE_POP
}

/*
 equation index: 14
 type: SIMPLE_ASSIGN
 MaterialStream2._Pvap_c[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[1].VP[1], MaterialStream2.C[1].VP[2], MaterialStream2.C[1].VP[3], MaterialStream2.C[1].VP[4], MaterialStream2.C[1].VP[5], MaterialStream2.C[1].VP[6]}, 380.0)
 */
void Flowsheet_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[763], (modelica_real)data->simulationInfo->realParameter[764], (modelica_real)data->simulationInfo->realParameter[765], (modelica_real)data->simulationInfo->realParameter[766], (modelica_real)data->simulationInfo->realParameter[767], (modelica_real)data->simulationInfo->realParameter[768]);
  data->localData[0]->realVars[148] /* MaterialStream2._Pvap_c[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp1, 380.0);
  TRACE_POP
}

/*
 equation index: 15
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[3,2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream2.C[2].SH, {MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tc, 380.0)
 */
void Flowsheet_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784], (modelica_real)data->simulationInfo->realParameter[785], (modelica_real)data->simulationInfo->realParameter[786]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684], (modelica_real)data->simulationInfo->realParameter[685], (modelica_real)data->simulationInfo->realParameter[686]);
  data->localData[0]->realVars[137] /* MaterialStream2._H_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[746], tmp2, tmp3, data->simulationInfo->realParameter[756], 380.0);
  TRACE_POP
}

/*
 equation index: 16
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[2,2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream2.C[2].SH, {MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tc, 380.0)
 */
void Flowsheet_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784], (modelica_real)data->simulationInfo->realParameter[785], (modelica_real)data->simulationInfo->realParameter[786]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684], (modelica_real)data->simulationInfo->realParameter[685], (modelica_real)data->simulationInfo->realParameter[686]);
  data->localData[0]->realVars[135] /* MaterialStream2._H_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[746], tmp4, tmp5, data->simulationInfo->realParameter[756], 380.0);
  TRACE_POP
}

/*
 equation index: 17
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[3,2] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, 380.0)
 */
void Flowsheet_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  real_array tmp6;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784], (modelica_real)data->simulationInfo->realParameter[785], (modelica_real)data->simulationInfo->realParameter[786]);
  data->localData[0]->realVars[108] /* MaterialStream2._Cp_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp6, 380.0);
  TRACE_POP
}

/*
 equation index: 18
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[2,2] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream2.C[2].LiqCp[1], MaterialStream2.C[2].LiqCp[2], MaterialStream2.C[2].LiqCp[3], MaterialStream2.C[2].LiqCp[4], MaterialStream2.C[2].LiqCp[5], MaterialStream2.C[2].LiqCp[6]}, 380.0)
 */
void Flowsheet_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[697], (modelica_real)data->simulationInfo->realParameter[698], (modelica_real)data->simulationInfo->realParameter[699], (modelica_real)data->simulationInfo->realParameter[700], (modelica_real)data->simulationInfo->realParameter[701], (modelica_real)data->simulationInfo->realParameter[702]);
  data->localData[0]->realVars[106] /* MaterialStream2._Cp_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp7, 380.0);
  TRACE_POP
}

/*
 equation index: 19
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[3,1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream2.C[1].SH, {MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tc, 380.0)
 */
void Flowsheet_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778], (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678], (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680]);
  data->localData[0]->realVars[136] /* MaterialStream2._H_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[745], tmp8, tmp9, data->simulationInfo->realParameter[755], 380.0);
  TRACE_POP
}

/*
 equation index: 20
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[2,1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream2.C[1].SH, {MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tc, 380.0)
 */
void Flowsheet_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  real_array tmp10;
  real_array tmp11;
  array_alloc_scalar_real_array(&tmp10, 6, (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778], (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780]);
  array_alloc_scalar_real_array(&tmp11, 6, (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678], (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680]);
  data->localData[0]->realVars[134] /* MaterialStream2._H_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[745], tmp10, tmp11, data->simulationInfo->realParameter[755], 380.0);
  TRACE_POP
}

/*
 equation index: 21
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[3,1] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, 380.0)
 */
void Flowsheet_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  real_array tmp12;
  array_alloc_scalar_real_array(&tmp12, 6, (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778], (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780]);
  data->localData[0]->realVars[107] /* MaterialStream2._Cp_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp12, 380.0);
  TRACE_POP
}

/*
 equation index: 22
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[2,1] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream2.C[1].LiqCp[1], MaterialStream2.C[1].LiqCp[2], MaterialStream2.C[1].LiqCp[3], MaterialStream2.C[1].LiqCp[4], MaterialStream2.C[1].LiqCp[5], MaterialStream2.C[1].LiqCp[6]}, 380.0)
 */
void Flowsheet_eqFunction_22(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,22};
  real_array tmp13;
  array_alloc_scalar_real_array(&tmp13, 6, (modelica_real)data->simulationInfo->realParameter[691], (modelica_real)data->simulationInfo->realParameter[692], (modelica_real)data->simulationInfo->realParameter[693], (modelica_real)data->simulationInfo->realParameter[694], (modelica_real)data->simulationInfo->realParameter[695], (modelica_real)data->simulationInfo->realParameter[696]);
  data->localData[0]->realVars[105] /* MaterialStream2._Cp_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp13, 380.0);
  TRACE_POP
}

/*
 equation index: 23
 type: SIMPLE_ASSIGN
 MaterialStream1._Pvap_c[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[2].VP[1], MaterialStream1.C[2].VP[2], MaterialStream1.C[2].VP[3], MaterialStream1.C[2].VP[4], MaterialStream1.C[2].VP[5], MaterialStream1.C[2].VP[6]}, 350.0)
 */
void Flowsheet_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,23};
  real_array tmp14;
  array_alloc_scalar_real_array(&tmp14, 6, (modelica_real)data->simulationInfo->realParameter[562], (modelica_real)data->simulationInfo->realParameter[563], (modelica_real)data->simulationInfo->realParameter[564], (modelica_real)data->simulationInfo->realParameter[565], (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567]);
  data->localData[0]->realVars[61] /* MaterialStream1._Pvap_c[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp14, 350.0);
  TRACE_POP
}

/*
 equation index: 24
 type: SIMPLE_ASSIGN
 MaterialStream1._Pvap_c[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[1].VP[1], MaterialStream1.C[1].VP[2], MaterialStream1.C[1].VP[3], MaterialStream1.C[1].VP[4], MaterialStream1.C[1].VP[5], MaterialStream1.C[1].VP[6]}, 350.0)
 */
void Flowsheet_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,24};
  real_array tmp15;
  array_alloc_scalar_real_array(&tmp15, 6, (modelica_real)data->simulationInfo->realParameter[556], (modelica_real)data->simulationInfo->realParameter[557], (modelica_real)data->simulationInfo->realParameter[558], (modelica_real)data->simulationInfo->realParameter[559], (modelica_real)data->simulationInfo->realParameter[560], (modelica_real)data->simulationInfo->realParameter[561]);
  data->localData[0]->realVars[60] /* MaterialStream1._Pvap_c[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp15, 350.0);
  TRACE_POP
}

/*
 equation index: 25
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[3,2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream1.C[2].SH, {MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tc, 350.0)
 */
void Flowsheet_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,25};
  real_array tmp16;
  real_array tmp17;
  array_alloc_scalar_real_array(&tmp16, 6, (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577], (modelica_real)data->simulationInfo->realParameter[578], (modelica_real)data->simulationInfo->realParameter[579]);
  array_alloc_scalar_real_array(&tmp17, 6, (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477], (modelica_real)data->simulationInfo->realParameter[478], (modelica_real)data->simulationInfo->realParameter[479]);
  data->localData[0]->realVars[48] /* MaterialStream1._H_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[539], tmp16, tmp17, data->simulationInfo->realParameter[549], 350.0);
  TRACE_POP
}

/*
 equation index: 26
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[2,2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream1.C[2].SH, {MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tc, 350.0)
 */
void Flowsheet_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  real_array tmp18;
  real_array tmp19;
  array_alloc_scalar_real_array(&tmp18, 6, (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577], (modelica_real)data->simulationInfo->realParameter[578], (modelica_real)data->simulationInfo->realParameter[579]);
  array_alloc_scalar_real_array(&tmp19, 6, (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477], (modelica_real)data->simulationInfo->realParameter[478], (modelica_real)data->simulationInfo->realParameter[479]);
  data->localData[0]->realVars[46] /* MaterialStream1._H_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[539], tmp18, tmp19, data->simulationInfo->realParameter[549], 350.0);
  TRACE_POP
}

/*
 equation index: 27
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[3,2] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, 350.0)
 */
void Flowsheet_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  real_array tmp20;
  array_alloc_scalar_real_array(&tmp20, 6, (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577], (modelica_real)data->simulationInfo->realParameter[578], (modelica_real)data->simulationInfo->realParameter[579]);
  data->localData[0]->realVars[18] /* MaterialStream1._Cp_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp20, 350.0);
  TRACE_POP
}

/*
 equation index: 28
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[2,2] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream1.C[2].LiqCp[1], MaterialStream1.C[2].LiqCp[2], MaterialStream1.C[2].LiqCp[3], MaterialStream1.C[2].LiqCp[4], MaterialStream1.C[2].LiqCp[5], MaterialStream1.C[2].LiqCp[6]}, 350.0)
 */
void Flowsheet_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  real_array tmp21;
  array_alloc_scalar_real_array(&tmp21, 6, (modelica_real)data->simulationInfo->realParameter[490], (modelica_real)data->simulationInfo->realParameter[491], (modelica_real)data->simulationInfo->realParameter[492], (modelica_real)data->simulationInfo->realParameter[493], (modelica_real)data->simulationInfo->realParameter[494], (modelica_real)data->simulationInfo->realParameter[495]);
  data->localData[0]->realVars[16] /* MaterialStream1._Cp_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp21, 350.0);
  TRACE_POP
}

/*
 equation index: 29
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[3,1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream1.C[1].SH, {MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tc, 350.0)
 */
void Flowsheet_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  real_array tmp22;
  real_array tmp23;
  array_alloc_scalar_real_array(&tmp22, 6, (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571], (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573]);
  array_alloc_scalar_real_array(&tmp23, 6, (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471], (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473]);
  data->localData[0]->realVars[47] /* MaterialStream1._H_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[538], tmp22, tmp23, data->simulationInfo->realParameter[548], 350.0);
  TRACE_POP
}

/*
 equation index: 30
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[2,1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream1.C[1].SH, {MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tc, 350.0)
 */
void Flowsheet_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  real_array tmp24;
  real_array tmp25;
  array_alloc_scalar_real_array(&tmp24, 6, (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571], (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573]);
  array_alloc_scalar_real_array(&tmp25, 6, (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471], (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473]);
  data->localData[0]->realVars[45] /* MaterialStream1._H_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[538], tmp24, tmp25, data->simulationInfo->realParameter[548], 350.0);
  TRACE_POP
}

/*
 equation index: 31
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[3,1] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, 350.0)
 */
void Flowsheet_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  real_array tmp26;
  array_alloc_scalar_real_array(&tmp26, 6, (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571], (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573]);
  data->localData[0]->realVars[17] /* MaterialStream1._Cp_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp26, 350.0);
  TRACE_POP
}

/*
 equation index: 32
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[2,1] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream1.C[1].LiqCp[1], MaterialStream1.C[1].LiqCp[2], MaterialStream1.C[1].LiqCp[3], MaterialStream1.C[1].LiqCp[4], MaterialStream1.C[1].LiqCp[5], MaterialStream1.C[1].LiqCp[6]}, 350.0)
 */
void Flowsheet_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  real_array tmp27;
  array_alloc_scalar_real_array(&tmp27, 6, (modelica_real)data->simulationInfo->realParameter[484], (modelica_real)data->simulationInfo->realParameter[485], (modelica_real)data->simulationInfo->realParameter[486], (modelica_real)data->simulationInfo->realParameter[487], (modelica_real)data->simulationInfo->realParameter[488], (modelica_real)data->simulationInfo->realParameter[489]);
  data->localData[0]->realVars[15] /* MaterialStream1._Cp_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp27, 350.0);
  TRACE_POP
}

/*
 equation index: 33
 type: SIMPLE_ASSIGN
 MaterialStream2._K_c[2] = DIVISION(MaterialStream2.Pvap_c[2], Heater1.Pout)
 */
void Flowsheet_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */ = DIVISION_SIM(data->localData[0]->realVars[149] /* MaterialStream2._Pvap_c[2] variable */,data->localData[0]->realVars[4] /* Heater1._Pout variable */,"Heater1.Pout",equationIndexes);
  TRACE_POP
}

/*
 equation index: 34
 type: SIMPLE_ASSIGN
 MaterialStream2._K_c[1] = DIVISION(MaterialStream2.Pvap_c[1], Heater1.Pout)
 */
void Flowsheet_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */ = DIVISION_SIM(data->localData[0]->realVars[148] /* MaterialStream2._Pvap_c[1] variable */,data->localData[0]->realVars[4] /* Heater1._Pout variable */,"Heater1.Pout",equationIndexes);
  TRACE_POP
}

/*
 equation index: 35
 type: SIMPLE_ASSIGN
 MaterialStream1._K_c[2] = 9.869232667160129e-006 * MaterialStream1.Pvap_c[2]
 */
void Flowsheet_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[61] /* MaterialStream1._Pvap_c[2] variable */);
  TRACE_POP
}

/*
 equation index: 36
 type: SIMPLE_ASSIGN
 MaterialStream1._K_c[1] = 9.869232667160129e-006 * MaterialStream1.Pvap_c[1]
 */
void Flowsheet_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[60] /* MaterialStream1._Pvap_c[1] variable */);
  TRACE_POP
}

/*
 equation index: 37
 type: SIMPLE_ASSIGN
 Heater1._xguess[2] = 0.5
 */
void Flowsheet_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  data->simulationInfo->realParameter[437] = 0.5;
  TRACE_POP
}

/*
 equation index: 38
 type: SIMPLE_ASSIGN
 Heater1._xguess[1] = 0.5
 */
void Flowsheet_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  data->simulationInfo->realParameter[436] = 0.5;
  TRACE_POP
}

void Flowsheet_eqFunction_39(DATA*,threadData_t*);
void Flowsheet_eqFunction_40(DATA*,threadData_t*);
void Flowsheet_eqFunction_41(DATA*,threadData_t*);
/*
 equation index: 42
 indexNonlinear: 0
 type: NONLINEAR
 
 vars: {Heater1._Tdg}
 eqns: {39, 40, 41}
 */
void Flowsheet_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 42 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = data->simulationInfo->realParameter[431];
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,42};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 42 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[431] = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  TRACE_POP
}

void Flowsheet_eqFunction_43(DATA*,threadData_t*);
void Flowsheet_eqFunction_44(DATA*,threadData_t*);
void Flowsheet_eqFunction_45(DATA*,threadData_t*);
/*
 equation index: 46
 indexNonlinear: 1
 type: NONLINEAR
 
 vars: {Heater1._Tbg}
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
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = data->simulationInfo->realParameter[428];
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,46};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 46 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[428] = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  TRACE_POP
}

/*
 equation index: 47
 type: SIMPLE_ASSIGN
 Heater1._Temp = 0.5 * (Heater1.Tbg + Heater1.Tdg)
 */
void Flowsheet_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  data->simulationInfo->realParameter[432] = (0.5) * (data->simulationInfo->realParameter[428] + data->simulationInfo->realParameter[431]);
  TRACE_POP
}

/*
 equation index: 48
 type: SIMPLE_ASSIGN
 Heater1._Psatt[1] = Simulator.Files.ThermodynamicFunctions.Psat({Heater1.C[1].VP[1], Heater1.C[1].VP[2], Heater1.C[1].VP[3], Heater1.C[1].VP[4], Heater1.C[1].VP[5], Heater1.C[1].VP[6]}, Heater1.Temp)
 */
void Flowsheet_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[347], (modelica_real)data->simulationInfo->realParameter[348], (modelica_real)data->simulationInfo->realParameter[349], (modelica_real)data->simulationInfo->realParameter[350], (modelica_real)data->simulationInfo->realParameter[351], (modelica_real)data->simulationInfo->realParameter[352]);
  data->simulationInfo->realParameter[421] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[432]);
  TRACE_POP
}

/*
 equation index: 49
 type: SIMPLE_ASSIGN
 Heater1._K_guess[1] = DIVISION(Heater1.Psatt[1], Heater1.Pg)
 */
void Flowsheet_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  data->simulationInfo->realParameter[411] = DIVISION_SIM(data->simulationInfo->realParameter[421],data->simulationInfo->realParameter[414],"Heater1.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 50
 type: SIMPLE_ASSIGN
 Heater1._Psatt[2] = Simulator.Files.ThermodynamicFunctions.Psat({Heater1.C[2].VP[1], Heater1.C[2].VP[2], Heater1.C[2].VP[3], Heater1.C[2].VP[4], Heater1.C[2].VP[5], Heater1.C[2].VP[6]}, Heater1.Temp)
 */
void Flowsheet_eqFunction_50(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,50};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[353], (modelica_real)data->simulationInfo->realParameter[354], (modelica_real)data->simulationInfo->realParameter[355], (modelica_real)data->simulationInfo->realParameter[356], (modelica_real)data->simulationInfo->realParameter[357], (modelica_real)data->simulationInfo->realParameter[358]);
  data->simulationInfo->realParameter[422] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp1, data->simulationInfo->realParameter[432]);
  TRACE_POP
}

/*
 equation index: 51
 type: SIMPLE_ASSIGN
 Heater1._K_guess[2] = DIVISION(Heater1.Psatt[2], Heater1.Pg)
 */
void Flowsheet_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  data->simulationInfo->realParameter[412] = DIVISION_SIM(data->simulationInfo->realParameter[422],data->simulationInfo->realParameter[414],"Heater1.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 52
 type: SIMPLE_ASSIGN
 Heater1._Pxc[2] = DIVISION(Heater1.xguess[2], Heater1.Psatt[2])
 */
void Flowsheet_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  data->simulationInfo->realParameter[425] = DIVISION_SIM(data->simulationInfo->realParameter[437],data->simulationInfo->realParameter[422],"Heater1.Psatt[2]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 53
 type: SIMPLE_ASSIGN
 Heater1._Pxm[2] = Heater1.xguess[2] * Heater1.Psatt[2]
 */
void Flowsheet_eqFunction_53(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,53};
  data->simulationInfo->realParameter[427] = (data->simulationInfo->realParameter[437]) * (data->simulationInfo->realParameter[422]);
  TRACE_POP
}

/*
 equation index: 54
 type: SIMPLE_ASSIGN
 Heater1._Tg = Heater1.Temp
 */
void Flowsheet_eqFunction_54(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,54};
  data->simulationInfo->realParameter[433] = data->simulationInfo->realParameter[432];
  TRACE_POP
}

/*
 equation index: 55
 type: SIMPLE_ASSIGN
 Heater1._Hcomplg[1] = Simulator.Files.ThermodynamicFunctions.HLiqId(Heater1.C[1].SH, {Heater1.C[1].VapCp[1], Heater1.C[1].VapCp[2], Heater1.C[1].VapCp[3], Heater1.C[1].VapCp[4], Heater1.C[1].VapCp[5], Heater1.C[1].VapCp[6]}, {Heater1.C[1].HOV[1], Heater1.C[1].HOV[2], Heater1.C[1].HOV[3], Heater1.C[1].HOV[4], Heater1.C[1].HOV[5], Heater1.C[1].HOV[6]}, Heater1.C[1].Tc, Heater1.Temp)
 */
void Flowsheet_eqFunction_55(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,55};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[259], (modelica_real)data->simulationInfo->realParameter[260], (modelica_real)data->simulationInfo->realParameter[261], (modelica_real)data->simulationInfo->realParameter[262], (modelica_real)data->simulationInfo->realParameter[263], (modelica_real)data->simulationInfo->realParameter[264]);
  data->simulationInfo->realParameter[403] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[329], tmp2, tmp3, data->simulationInfo->realParameter[339], data->simulationInfo->realParameter[432]);
  TRACE_POP
}

/*
 equation index: 56
 type: SIMPLE_ASSIGN
 Heater1._Hcompvg[1] = Simulator.Files.ThermodynamicFunctions.HVapId(Heater1.C[1].SH, {Heater1.C[1].VapCp[1], Heater1.C[1].VapCp[2], Heater1.C[1].VapCp[3], Heater1.C[1].VapCp[4], Heater1.C[1].VapCp[5], Heater1.C[1].VapCp[6]}, {Heater1.C[1].HOV[1], Heater1.C[1].HOV[2], Heater1.C[1].HOV[3], Heater1.C[1].HOV[4], Heater1.C[1].HOV[5], Heater1.C[1].HOV[6]}, Heater1.C[1].Tc, Heater1.Temp)
 */
void Flowsheet_eqFunction_56(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,56};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[259], (modelica_real)data->simulationInfo->realParameter[260], (modelica_real)data->simulationInfo->realParameter[261], (modelica_real)data->simulationInfo->realParameter[262], (modelica_real)data->simulationInfo->realParameter[263], (modelica_real)data->simulationInfo->realParameter[264]);
  data->simulationInfo->realParameter[405] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[329], tmp4, tmp5, data->simulationInfo->realParameter[339], data->simulationInfo->realParameter[432]);
  TRACE_POP
}

/*
 equation index: 57
 type: SIMPLE_ASSIGN
 Heater1._Hcomplg[2] = Simulator.Files.ThermodynamicFunctions.HLiqId(Heater1.C[2].SH, {Heater1.C[2].VapCp[1], Heater1.C[2].VapCp[2], Heater1.C[2].VapCp[3], Heater1.C[2].VapCp[4], Heater1.C[2].VapCp[5], Heater1.C[2].VapCp[6]}, {Heater1.C[2].HOV[1], Heater1.C[2].HOV[2], Heater1.C[2].HOV[3], Heater1.C[2].HOV[4], Heater1.C[2].HOV[5], Heater1.C[2].HOV[6]}, Heater1.C[2].Tc, Heater1.Temp)
 */
void Flowsheet_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[265], (modelica_real)data->simulationInfo->realParameter[266], (modelica_real)data->simulationInfo->realParameter[267], (modelica_real)data->simulationInfo->realParameter[268], (modelica_real)data->simulationInfo->realParameter[269], (modelica_real)data->simulationInfo->realParameter[270]);
  data->simulationInfo->realParameter[404] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[330], tmp6, tmp7, data->simulationInfo->realParameter[340], data->simulationInfo->realParameter[432]);
  TRACE_POP
}

/*
 equation index: 58
 type: SIMPLE_ASSIGN
 Heater1._Hcompvg[2] = Simulator.Files.ThermodynamicFunctions.HVapId(Heater1.C[2].SH, {Heater1.C[2].VapCp[1], Heater1.C[2].VapCp[2], Heater1.C[2].VapCp[3], Heater1.C[2].VapCp[4], Heater1.C[2].VapCp[5], Heater1.C[2].VapCp[6]}, {Heater1.C[2].HOV[1], Heater1.C[2].HOV[2], Heater1.C[2].HOV[3], Heater1.C[2].HOV[4], Heater1.C[2].HOV[5], Heater1.C[2].HOV[6]}, Heater1.C[2].Tc, Heater1.Temp)
 */
void Flowsheet_eqFunction_58(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,58};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[265], (modelica_real)data->simulationInfo->realParameter[266], (modelica_real)data->simulationInfo->realParameter[267], (modelica_real)data->simulationInfo->realParameter[268], (modelica_real)data->simulationInfo->realParameter[269], (modelica_real)data->simulationInfo->realParameter[270]);
  data->simulationInfo->realParameter[406] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[330], tmp8, tmp9, data->simulationInfo->realParameter[340], data->simulationInfo->realParameter[432]);
  TRACE_POP
}

/*
 equation index: 59
 type: SIMPLE_ASSIGN
 Heater1._Pxc[1] = DIVISION(Heater1.xguess[1], Heater1.Psatt[1])
 */
void Flowsheet_eqFunction_59(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,59};
  data->simulationInfo->realParameter[424] = DIVISION_SIM(data->simulationInfo->realParameter[436],data->simulationInfo->realParameter[421],"Heater1.Psatt[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 60
 type: SIMPLE_ASSIGN
 Heater1._Px = Heater1.Pxc[1] + Heater1.Pxc[2]
 */
void Flowsheet_eqFunction_60(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,60};
  data->simulationInfo->realParameter[423] = data->simulationInfo->realParameter[424] + data->simulationInfo->realParameter[425];
  TRACE_POP
}

/*
 equation index: 61
 type: SIMPLE_ASSIGN
 Heater1._Pmin = DIVISION(1.0, Heater1.Px)
 */
void Flowsheet_eqFunction_61(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,61};
  data->simulationInfo->realParameter[416] = DIVISION_SIM(1.0,data->simulationInfo->realParameter[423],"Heater1.Px",equationIndexes);
  TRACE_POP
}

/*
 equation index: 62
 type: SIMPLE_ASSIGN
 Heater1._Pxm[1] = Heater1.xguess[1] * Heater1.Psatt[1]
 */
void Flowsheet_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  data->simulationInfo->realParameter[426] = (data->simulationInfo->realParameter[436]) * (data->simulationInfo->realParameter[421]);
  TRACE_POP
}

/*
 equation index: 63
 type: SIMPLE_ASSIGN
 Heater1._Pmax = Heater1.Pxm[1] + Heater1.Pxm[2]
 */
void Flowsheet_eqFunction_63(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,63};
  data->simulationInfo->realParameter[415] = data->simulationInfo->realParameter[426] + data->simulationInfo->realParameter[427];
  TRACE_POP
}


/*
 equation index: 64
 type: SIMPLE_ASSIGN
 Heater1._xvapg = 0.0
 */
void Flowsheet_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  data->simulationInfo->realParameter[441] = 0.0;
  TRACE_POP
}
/*
 equation index: 65
 type: SIMPLE_ASSIGN
 Heater1._xvapg = (Heater1.Pg - Heater1.Pmin) / (Heater1.Pmax - Heater1.Pmin)
 */
void Flowsheet_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  modelica_real tmp12;
  tmp12 = data->simulationInfo->realParameter[415] - data->simulationInfo->realParameter[416];
  if (tmp12 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(Heater1.Pg - Heater1.Pmin) / (Heater1.Pmax - Heater1.Pmin)");}
  data->simulationInfo->realParameter[441] = (data->simulationInfo->realParameter[414] - data->simulationInfo->realParameter[416]) / tmp12;
  TRACE_POP
}
/*
 equation index: 66
 type: SIMPLE_ASSIGN
 Heater1._xvapg = 1.0
 */
void Flowsheet_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  data->simulationInfo->realParameter[441] = 1.0;
  TRACE_POP
}
/*
 equation index: 67
 type: IFEQUATION
 
 equation index: 64
 type: SIMPLE_ASSIGN
 Heater1._xvapg = 0.0equation index: 65
 type: SIMPLE_ASSIGN
 Heater1._xvapg = (Heater1.Pg - Heater1.Pmin) / (Heater1.Pmax - Heater1.Pmin)
 equation index: 66
 type: SIMPLE_ASSIGN
 Heater1._xvapg = 1.0
 */
void Flowsheet_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  tmp10 = GreaterEq(data->simulationInfo->realParameter[414],data->simulationInfo->realParameter[415]);
  tmp11 = GreaterEq(data->simulationInfo->realParameter[414],data->simulationInfo->realParameter[416]);
  if(tmp10)
  {
    Flowsheet_eqFunction_64(data, threadData);
  }
  else if(tmp11)
  {
    Flowsheet_eqFunction_65(data, threadData);
  }else
  {
    Flowsheet_eqFunction_66(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 68
 type: SIMPLE_ASSIGN
 Heater1._xliqg = 1.0 - Heater1.xvapg
 */
void Flowsheet_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  data->simulationInfo->realParameter[438] = 1.0 - data->simulationInfo->realParameter[441];
  TRACE_POP
}


/*
 equation index: 69
 type: SIMPLE_ASSIGN
 Heater1._Beta = 1.0
 */
void Flowsheet_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  data->simulationInfo->realParameter[238] = 1.0;
  TRACE_POP
}
/*
 equation index: 70
 type: SIMPLE_ASSIGN
 Heater1._Beta = 0.0
 */
void Flowsheet_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
  data->simulationInfo->realParameter[238] = 0.0;
  TRACE_POP
}
/*
 equation index: 71
 type: SIMPLE_ASSIGN
 Heater1._Beta = Heater1.xvapg
 */
void Flowsheet_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  data->simulationInfo->realParameter[238] = data->simulationInfo->realParameter[441];
  TRACE_POP
}
/*
 equation index: 72
 type: IFEQUATION
 
 equation index: 69
 type: SIMPLE_ASSIGN
 Heater1._Beta = 1.0equation index: 70
 type: SIMPLE_ASSIGN
 Heater1._Beta = 0.0
 equation index: 71
 type: SIMPLE_ASSIGN
 Heater1._Beta = Heater1.xvapg
 */
void Flowsheet_eqFunction_72(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,72};
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  tmp13 = Greater(data->simulationInfo->realParameter[441],1.0);
  tmp14 = Less(data->simulationInfo->realParameter[441],0.0);
  if(tmp13)
  {
    Flowsheet_eqFunction_69(data, threadData);
  }
  else if(tmp14)
  {
    Flowsheet_eqFunction_70(data, threadData);
  }else
  {
    Flowsheet_eqFunction_71(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 73
 type: SIMPLE_ASSIGN
 Heater1._Alpha = 1.0 - Heater1.Beta
 */
void Flowsheet_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  data->simulationInfo->realParameter[237] = 1.0 - data->simulationInfo->realParameter[238];
  TRACE_POP
}



/*
 equation index: 74
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = Heater1.xguess[1] * Heater1.K_guess[1] / (1.0 + (-1.0 + Heater1.K_guess[1]) * Heater1.xvapg)
 */
void Flowsheet_eqFunction_74(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,74};
  modelica_real tmp18;
  tmp18 = 1.0 + (-1.0 + data->simulationInfo->realParameter[411]) * (data->simulationInfo->realParameter[441]);
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Heater1.K_guess[1] / (1.0 + (-1.0 + Heater1.K_guess[1]) * Heater1.xvapg)");}
  data->simulationInfo->realParameter[444] = (data->simulationInfo->realParameter[436]) * ((data->simulationInfo->realParameter[411]) / tmp18);
  TRACE_POP
}
/*
 equation index: 75
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = Heater1.xguess[1]
 */
void Flowsheet_eqFunction_75(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  data->simulationInfo->realParameter[444] = data->simulationInfo->realParameter[436];
  TRACE_POP
}
/*
 equation index: 76
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_76(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
  data->simulationInfo->realParameter[444] = 0.0;
  TRACE_POP
}
/*
 equation index: 77
 type: IFEQUATION
 
 equation index: 74
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = Heater1.xguess[1] * Heater1.K_guess[1] / (1.0 + (-1.0 + Heater1.K_guess[1]) * Heater1.xvapg)equation index: 75
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = Heater1.xguess[1]
 equation index: 76
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_77(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,77};
  modelica_boolean tmp16;
  tmp16 = Greater(data->simulationInfo->realParameter[238],0.0);
  if((tmp16 && (data->simulationInfo->realParameter[238] != 1.0)))
  {
    Flowsheet_eqFunction_74(data, threadData);
  }
  else if((data->simulationInfo->realParameter[238] == 1.0))
  {
    Flowsheet_eqFunction_75(data, threadData);
  }else
  {
    Flowsheet_eqFunction_76(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 78
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = Heater1.ymol[1] / Heater1.K_guess[1]
 */
void Flowsheet_eqFunction_78(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,78};
  modelica_real tmp22;
  tmp22 = data->simulationInfo->realParameter[411];
  if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Heater1.ymol[1] / Heater1.K_guess[1]");}
  data->simulationInfo->realParameter[439] = (data->simulationInfo->realParameter[444]) / tmp22;
  TRACE_POP
}
/*
 equation index: 79
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = Heater1.xguess[1]
 */
void Flowsheet_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  data->simulationInfo->realParameter[439] = data->simulationInfo->realParameter[436];
  TRACE_POP
}
/*
 equation index: 80
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_80(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  data->simulationInfo->realParameter[439] = 0.0;
  TRACE_POP
}
/*
 equation index: 81
 type: IFEQUATION
 
 equation index: 78
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = Heater1.ymol[1] / Heater1.K_guess[1]equation index: 79
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = Heater1.xguess[1]
 equation index: 80
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  tmp20 = Greater(data->simulationInfo->realParameter[238],0.0);
  tmp21 = Less(data->simulationInfo->realParameter[238],1.0);
  if((tmp20 && tmp21))
  {
    Flowsheet_eqFunction_78(data, threadData);
  }
  else if((data->simulationInfo->realParameter[238] == 0.0))
  {
    Flowsheet_eqFunction_79(data, threadData);
  }else
  {
    Flowsheet_eqFunction_80(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 82
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_82(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
  data->simulationInfo->realParameter[439] = 0.0;
  TRACE_POP
}

/*
 equation index: 83
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  data->simulationInfo->realParameter[444] = 0.0;
  TRACE_POP
}
/*
 equation index: 84
 type: IFEQUATION
 
 equation index: 77
 type: IFEQUATION
 
 equation index: 74
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = Heater1.xguess[1] * Heater1.K_guess[1] / (1.0 + (-1.0 + Heater1.K_guess[1]) * Heater1.xvapg)equation index: 75
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = Heater1.xguess[1]
 equation index: 76
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = 0.0equation index: 81
 type: IFEQUATION
 
 equation index: 78
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = Heater1.ymol[1] / Heater1.K_guess[1]equation index: 79
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = Heater1.xguess[1]
 equation index: 80
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = 0.0
 equation index: 82
 type: SIMPLE_ASSIGN
 Heater1._xmol[1] = 0.0equation index: 83
 type: SIMPLE_ASSIGN
 Heater1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  if((data->simulationInfo->realParameter[436] != 0.0))
  {
    Flowsheet_eqFunction_77(data, threadData);

    Flowsheet_eqFunction_81(data, threadData);
  }else
  {
    Flowsheet_eqFunction_82(data, threadData);
    Flowsheet_eqFunction_83(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 85
 type: SIMPLE_ASSIGN
 Heater1._xg[1] = 0.0
 */
void Flowsheet_eqFunction_85(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,85};
  data->simulationInfo->realParameter[434] = 0.0;
  TRACE_POP
}
/*
 equation index: 86
 type: SIMPLE_ASSIGN
 Heater1._xg[1] = 1.0
 */
void Flowsheet_eqFunction_86(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,86};
  data->simulationInfo->realParameter[434] = 1.0;
  TRACE_POP
}
/*
 equation index: 87
 type: SIMPLE_ASSIGN
 Heater1._xg[1] = Heater1.xmol[1]
 */
void Flowsheet_eqFunction_87(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,87};
  data->simulationInfo->realParameter[434] = data->simulationInfo->realParameter[439];
  TRACE_POP
}
/*
 equation index: 88
 type: IFEQUATION
 
 equation index: 85
 type: SIMPLE_ASSIGN
 Heater1._xg[1] = 0.0equation index: 86
 type: SIMPLE_ASSIGN
 Heater1._xg[1] = 1.0
 equation index: 87
 type: SIMPLE_ASSIGN
 Heater1._xg[1] = Heater1.xmol[1]
 */
void Flowsheet_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  tmp24 = Less(data->simulationInfo->realParameter[439],0.0);
  tmp25 = Greater(data->simulationInfo->realParameter[434],1.0);
  if(tmp24)
  {
    Flowsheet_eqFunction_85(data, threadData);
  }
  else if(tmp25)
  {
    Flowsheet_eqFunction_86(data, threadData);
  }else
  {
    Flowsheet_eqFunction_87(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 89
 type: SIMPLE_ASSIGN
 Heater1._yg[1] = 0.0
 */
void Flowsheet_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  data->simulationInfo->realParameter[442] = 0.0;
  TRACE_POP
}
/*
 equation index: 90
 type: SIMPLE_ASSIGN
 Heater1._yg[1] = 1.0
 */
void Flowsheet_eqFunction_90(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,90};
  data->simulationInfo->realParameter[442] = 1.0;
  TRACE_POP
}
/*
 equation index: 91
 type: SIMPLE_ASSIGN
 Heater1._yg[1] = Heater1.ymol[1]
 */
void Flowsheet_eqFunction_91(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,91};
  data->simulationInfo->realParameter[442] = data->simulationInfo->realParameter[444];
  TRACE_POP
}
/*
 equation index: 92
 type: IFEQUATION
 
 equation index: 89
 type: SIMPLE_ASSIGN
 Heater1._yg[1] = 0.0equation index: 90
 type: SIMPLE_ASSIGN
 Heater1._yg[1] = 1.0
 equation index: 91
 type: SIMPLE_ASSIGN
 Heater1._yg[1] = Heater1.ymol[1]
 */
void Flowsheet_eqFunction_92(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,92};
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  tmp26 = Less(data->simulationInfo->realParameter[444],0.0);
  tmp27 = Greater(data->simulationInfo->realParameter[444],1.0);
  if(tmp26)
  {
    Flowsheet_eqFunction_89(data, threadData);
  }
  else if(tmp27)
  {
    Flowsheet_eqFunction_90(data, threadData);
  }else
  {
    Flowsheet_eqFunction_91(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 96
 type: LINEAR
 
 <var>Heater1._Fvapg</var>
 <row>

 </row>
 <matrix>
 </matrix>
 */
void Flowsheet_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 96 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[0].x[0] = data->simulationInfo->realParameter[400];
  retValue = solve_linear_system(data, threadData, 0);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,96};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 96 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[400] = data->simulationInfo->linearSystemData[0].x[0];
  TRACE_POP
}



/*
 equation index: 97
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = Heater1.xguess[2] * Heater1.K_guess[2] / (1.0 + (-1.0 + Heater1.K_guess[2]) * Heater1.xvapg)
 */
void Flowsheet_eqFunction_97(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,97};
  modelica_real tmp31;
  tmp31 = 1.0 + (-1.0 + data->simulationInfo->realParameter[412]) * (data->simulationInfo->realParameter[441]);
  if (tmp31 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Heater1.K_guess[2] / (1.0 + (-1.0 + Heater1.K_guess[2]) * Heater1.xvapg)");}
  data->simulationInfo->realParameter[445] = (data->simulationInfo->realParameter[437]) * ((data->simulationInfo->realParameter[412]) / tmp31);
  TRACE_POP
}
/*
 equation index: 98
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = Heater1.xguess[2]
 */
void Flowsheet_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
  data->simulationInfo->realParameter[445] = data->simulationInfo->realParameter[437];
  TRACE_POP
}
/*
 equation index: 99
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
  data->simulationInfo->realParameter[445] = 0.0;
  TRACE_POP
}
/*
 equation index: 100
 type: IFEQUATION
 
 equation index: 97
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = Heater1.xguess[2] * Heater1.K_guess[2] / (1.0 + (-1.0 + Heater1.K_guess[2]) * Heater1.xvapg)equation index: 98
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = Heater1.xguess[2]
 equation index: 99
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,100};
  modelica_boolean tmp29;
  tmp29 = Greater(data->simulationInfo->realParameter[238],0.0);
  if((tmp29 && (data->simulationInfo->realParameter[238] != 1.0)))
  {
    Flowsheet_eqFunction_97(data, threadData);
  }
  else if((data->simulationInfo->realParameter[238] == 1.0))
  {
    Flowsheet_eqFunction_98(data, threadData);
  }else
  {
    Flowsheet_eqFunction_99(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 101
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = Heater1.ymol[2] / Heater1.K_guess[2]
 */
void Flowsheet_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  modelica_real tmp35;
  tmp35 = data->simulationInfo->realParameter[412];
  if (tmp35 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Heater1.ymol[2] / Heater1.K_guess[2]");}
  data->simulationInfo->realParameter[440] = (data->simulationInfo->realParameter[445]) / tmp35;
  TRACE_POP
}
/*
 equation index: 102
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = Heater1.xguess[2]
 */
void Flowsheet_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  data->simulationInfo->realParameter[440] = data->simulationInfo->realParameter[437];
  TRACE_POP
}
/*
 equation index: 103
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
  data->simulationInfo->realParameter[440] = 0.0;
  TRACE_POP
}
/*
 equation index: 104
 type: IFEQUATION
 
 equation index: 101
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = Heater1.ymol[2] / Heater1.K_guess[2]equation index: 102
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = Heater1.xguess[2]
 equation index: 103
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,104};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  tmp33 = Greater(data->simulationInfo->realParameter[238],0.0);
  tmp34 = Less(data->simulationInfo->realParameter[238],1.0);
  if((tmp33 && tmp34))
  {
    Flowsheet_eqFunction_101(data, threadData);
  }
  else if((data->simulationInfo->realParameter[238] == 0.0))
  {
    Flowsheet_eqFunction_102(data, threadData);
  }else
  {
    Flowsheet_eqFunction_103(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 105
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
  data->simulationInfo->realParameter[440] = 0.0;
  TRACE_POP
}

/*
 equation index: 106
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,106};
  data->simulationInfo->realParameter[445] = 0.0;
  TRACE_POP
}
/*
 equation index: 107
 type: IFEQUATION
 
 equation index: 100
 type: IFEQUATION
 
 equation index: 97
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = Heater1.xguess[2] * Heater1.K_guess[2] / (1.0 + (-1.0 + Heater1.K_guess[2]) * Heater1.xvapg)equation index: 98
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = Heater1.xguess[2]
 equation index: 99
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = 0.0equation index: 104
 type: IFEQUATION
 
 equation index: 101
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = Heater1.ymol[2] / Heater1.K_guess[2]equation index: 102
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = Heater1.xguess[2]
 equation index: 103
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = 0.0
 equation index: 105
 type: SIMPLE_ASSIGN
 Heater1._xmol[2] = 0.0equation index: 106
 type: SIMPLE_ASSIGN
 Heater1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,107};
  if((data->simulationInfo->realParameter[437] != 0.0))
  {
    Flowsheet_eqFunction_100(data, threadData);

    Flowsheet_eqFunction_104(data, threadData);
  }else
  {
    Flowsheet_eqFunction_105(data, threadData);
    Flowsheet_eqFunction_106(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 108
 type: SIMPLE_ASSIGN
 Heater1._yg[2] = 0.0
 */
void Flowsheet_eqFunction_108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,108};
  data->simulationInfo->realParameter[443] = 0.0;
  TRACE_POP
}
/*
 equation index: 109
 type: SIMPLE_ASSIGN
 Heater1._yg[2] = 1.0
 */
void Flowsheet_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
  data->simulationInfo->realParameter[443] = 1.0;
  TRACE_POP
}
/*
 equation index: 110
 type: SIMPLE_ASSIGN
 Heater1._yg[2] = Heater1.ymol[2]
 */
void Flowsheet_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
  data->simulationInfo->realParameter[443] = data->simulationInfo->realParameter[445];
  TRACE_POP
}
/*
 equation index: 111
 type: IFEQUATION
 
 equation index: 108
 type: SIMPLE_ASSIGN
 Heater1._yg[2] = 0.0equation index: 109
 type: SIMPLE_ASSIGN
 Heater1._yg[2] = 1.0
 equation index: 110
 type: SIMPLE_ASSIGN
 Heater1._yg[2] = Heater1.ymol[2]
 */
void Flowsheet_eqFunction_111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,111};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  tmp37 = Less(data->simulationInfo->realParameter[445],0.0);
  tmp38 = Greater(data->simulationInfo->realParameter[445],1.0);
  if(tmp37)
  {
    Flowsheet_eqFunction_108(data, threadData);
  }
  else if(tmp38)
  {
    Flowsheet_eqFunction_109(data, threadData);
  }else
  {
    Flowsheet_eqFunction_110(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 112
 type: SIMPLE_ASSIGN
 Heater1._xg[2] = 0.0
 */
void Flowsheet_eqFunction_112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,112};
  data->simulationInfo->realParameter[435] = 0.0;
  TRACE_POP
}
/*
 equation index: 113
 type: SIMPLE_ASSIGN
 Heater1._xg[2] = 1.0
 */
void Flowsheet_eqFunction_113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,113};
  data->simulationInfo->realParameter[435] = 1.0;
  TRACE_POP
}
/*
 equation index: 114
 type: SIMPLE_ASSIGN
 Heater1._xg[2] = Heater1.xmol[2]
 */
void Flowsheet_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
  data->simulationInfo->realParameter[435] = data->simulationInfo->realParameter[440];
  TRACE_POP
}
/*
 equation index: 115
 type: IFEQUATION
 
 equation index: 112
 type: SIMPLE_ASSIGN
 Heater1._xg[2] = 0.0equation index: 113
 type: SIMPLE_ASSIGN
 Heater1._xg[2] = 1.0
 equation index: 114
 type: SIMPLE_ASSIGN
 Heater1._xg[2] = Heater1.xmol[2]
 */
void Flowsheet_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  tmp39 = Less(data->simulationInfo->realParameter[440],0.0);
  tmp40 = Greater(data->simulationInfo->realParameter[435],1.0);
  if(tmp39)
  {
    Flowsheet_eqFunction_112(data, threadData);
  }
  else if(tmp40)
  {
    Flowsheet_eqFunction_113(data, threadData);
  }else
  {
    Flowsheet_eqFunction_114(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 116
 type: SIMPLE_ASSIGN
 $START._Heater1._xvapout = Heater1.xvapg
 */
void Flowsheet_eqFunction_116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,116};
  data->modelData->realVarsData[9].attribute /* Heater1._xvapout variable */.start = data->simulationInfo->realParameter[441];
    data->localData[0]->realVars[9] /* Heater1._xvapout variable */ = data->modelData->realVarsData[9].attribute /* Heater1._xvapout variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[9].info /* Heater1._xvapout */.name, (modelica_real) data->localData[0]->realVars[9] /* Heater1._xvapout variable */);
  TRACE_POP
}

/*
 equation index: 117
 type: SIMPLE_ASSIGN
 $START._Heater1._xvapin = Heater1.xvapg
 */
void Flowsheet_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
  data->modelData->realVarsData[8].attribute /* Heater1._xvapin variable */.start = data->simulationInfo->realParameter[441];
    data->localData[0]->realVars[8] /* Heater1._xvapin variable */ = data->modelData->realVarsData[8].attribute /* Heater1._xvapin variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[8].info /* Heater1._xvapin */.name, (modelica_real) data->localData[0]->realVars[8] /* Heater1._xvapin variable */);
  TRACE_POP
}

/*
 equation index: 118
 type: SIMPLE_ASSIGN
 Heater1._Hliqg = Heater1.xguess[1] * Heater1.Hcomplg[1] + Heater1.xguess[2] * Heater1.Hcomplg[2]
 */
void Flowsheet_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
  data->simulationInfo->realParameter[407] = (data->simulationInfo->realParameter[436]) * (data->simulationInfo->realParameter[403]) + (data->simulationInfo->realParameter[437]) * (data->simulationInfo->realParameter[404]);
  TRACE_POP
}

/*
 equation index: 119
 type: SIMPLE_ASSIGN
 Heater1._Hvapg = Heater1.xguess[1] * Heater1.Hcompvg[1] + Heater1.xguess[2] * Heater1.Hcompvg[2]
 */
void Flowsheet_eqFunction_119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,119};
  data->simulationInfo->realParameter[410] = (data->simulationInfo->realParameter[436]) * (data->simulationInfo->realParameter[405]) + (data->simulationInfo->realParameter[437]) * (data->simulationInfo->realParameter[406]);
  TRACE_POP
}

/*
 equation index: 120
 type: SIMPLE_ASSIGN
 Heater1._Htotg = Heater1.Hliqg + Heater1.Hvapg
 */
void Flowsheet_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  data->simulationInfo->realParameter[409] = data->simulationInfo->realParameter[407] + data->simulationInfo->realParameter[410];
  TRACE_POP
}

/*
 equation index: 121
 type: SIMPLE_ASSIGN
 Heater1._Hmixg = Heater1.Htotg
 */
void Flowsheet_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
  data->simulationInfo->realParameter[408] = data->simulationInfo->realParameter[409];
  TRACE_POP
}

/*
 equation index: 122
 type: SIMPLE_ASSIGN
 Heater1._Hcompg[1] = Heater1.xguess[1] * Heater1.Htotg
 */
void Flowsheet_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  data->simulationInfo->realParameter[401] = (data->simulationInfo->realParameter[436]) * (data->simulationInfo->realParameter[409]);
  TRACE_POP
}

/*
 equation index: 123
 type: SIMPLE_ASSIGN
 Heater1._Hcompg[2] = Heater1.xguess[2] * Heater1.Htotg
 */
void Flowsheet_eqFunction_123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,123};
  data->simulationInfo->realParameter[402] = (data->simulationInfo->realParameter[437]) * (data->simulationInfo->realParameter[409]);
  TRACE_POP
}

/*
 equation index: 124
 type: SIMPLE_ASSIGN
 MaterialStream2._xguess[2] = 0.5
 */
void Flowsheet_eqFunction_124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,124};
  data->simulationInfo->realParameter[851] = 0.5;
  TRACE_POP
}

/*
 equation index: 125
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[1,2] = MaterialStream2.xguess[2]
 */
void Flowsheet_eqFunction_125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,125};
  data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[1,2] variable */.start = data->simulationInfo->realParameter[851];
    data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */ = data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[180].info /* MaterialStream2._xm_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 126
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[1,2] = MaterialStream2.xguess[2]
 */
void Flowsheet_eqFunction_126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,126};
  data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[1,2] variable */.start = data->simulationInfo->realParameter[851];
    data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */ = data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[173].info /* MaterialStream2._x_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 127
 type: SIMPLE_ASSIGN
 MaterialStream2._xguess[1] = 0.5
 */
void Flowsheet_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
  data->simulationInfo->realParameter[850] = 0.5;
  TRACE_POP
}

void Flowsheet_eqFunction_128(DATA*,threadData_t*);
void Flowsheet_eqFunction_129(DATA*,threadData_t*);
void Flowsheet_eqFunction_130(DATA*,threadData_t*);
/*
 equation index: 131
 indexNonlinear: 2
 type: NONLINEAR
 
 vars: {MaterialStream2._Tdg}
 eqns: {128, 129, 130}
 */
void Flowsheet_eqFunction_131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,131};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 131 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[0] = data->simulationInfo->realParameter[845];
  retValue = solve_nonlinear_system(data, threadData, 2);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,131};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 131 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[845] = data->simulationInfo->nonlinearSystemData[2].nlsx[0];
  TRACE_POP
}

void Flowsheet_eqFunction_132(DATA*,threadData_t*);
void Flowsheet_eqFunction_133(DATA*,threadData_t*);
void Flowsheet_eqFunction_134(DATA*,threadData_t*);
/*
 equation index: 135
 indexNonlinear: 3
 type: NONLINEAR
 
 vars: {MaterialStream2._Tbg}
 eqns: {132, 133, 134}
 */
void Flowsheet_eqFunction_135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,135};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 135 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[3].nlsxOld[0] = data->simulationInfo->realParameter[842];
  retValue = solve_nonlinear_system(data, threadData, 3);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,135};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 135 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[842] = data->simulationInfo->nonlinearSystemData[3].nlsx[0];
  TRACE_POP
}

/*
 equation index: 136
 type: SIMPLE_ASSIGN
 MaterialStream2._Temp = 0.5 * (MaterialStream2.Tbg + MaterialStream2.Tdg)
 */
void Flowsheet_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
  data->simulationInfo->realParameter[846] = (0.5) * (data->simulationInfo->realParameter[842] + data->simulationInfo->realParameter[845]);
  TRACE_POP
}

/*
 equation index: 137
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatt[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[1].VP[1], MaterialStream2.C[1].VP[2], MaterialStream2.C[1].VP[3], MaterialStream2.C[1].VP[4], MaterialStream2.C[1].VP[5], MaterialStream2.C[1].VP[6]}, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[763], (modelica_real)data->simulationInfo->realParameter[764], (modelica_real)data->simulationInfo->realParameter[765], (modelica_real)data->simulationInfo->realParameter[766], (modelica_real)data->simulationInfo->realParameter[767], (modelica_real)data->simulationInfo->realParameter[768]);
  data->simulationInfo->realParameter[835] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[846]);
  TRACE_POP
}

/*
 equation index: 138
 type: SIMPLE_ASSIGN
 MaterialStream2._K_guess[1] = DIVISION(MaterialStream2.Psatt[1], MaterialStream2.Pg)
 */
void Flowsheet_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
  data->simulationInfo->realParameter[826] = DIVISION_SIM(data->simulationInfo->realParameter[835],data->simulationInfo->realParameter[828],"MaterialStream2.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 139
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatt[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[2].VP[1], MaterialStream2.C[2].VP[2], MaterialStream2.C[2].VP[3], MaterialStream2.C[2].VP[4], MaterialStream2.C[2].VP[5], MaterialStream2.C[2].VP[6]}, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[769], (modelica_real)data->simulationInfo->realParameter[770], (modelica_real)data->simulationInfo->realParameter[771], (modelica_real)data->simulationInfo->realParameter[772], (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774]);
  data->simulationInfo->realParameter[836] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp1, data->simulationInfo->realParameter[846]);
  TRACE_POP
}

/*
 equation index: 140
 type: SIMPLE_ASSIGN
 MaterialStream2._K_guess[2] = DIVISION(MaterialStream2.Psatt[2], MaterialStream2.Pg)
 */
void Flowsheet_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  data->simulationInfo->realParameter[827] = DIVISION_SIM(data->simulationInfo->realParameter[836],data->simulationInfo->realParameter[828],"MaterialStream2.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 141
 type: SIMPLE_ASSIGN
 MaterialStream2._Pxc[2] = DIVISION(MaterialStream2.xguess[2], MaterialStream2.Psatt[2])
 */
void Flowsheet_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
  data->simulationInfo->realParameter[839] = DIVISION_SIM(data->simulationInfo->realParameter[851],data->simulationInfo->realParameter[836],"MaterialStream2.Psatt[2]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 142
 type: SIMPLE_ASSIGN
 MaterialStream2._Pxm[2] = MaterialStream2.xguess[2] * MaterialStream2.Psatt[2]
 */
void Flowsheet_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
  data->simulationInfo->realParameter[841] = (data->simulationInfo->realParameter[851]) * (data->simulationInfo->realParameter[836]);
  TRACE_POP
}

/*
 equation index: 143
 type: SIMPLE_ASSIGN
 MaterialStream2._Tg = MaterialStream2.Temp
 */
void Flowsheet_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
  data->simulationInfo->realParameter[847] = data->simulationInfo->realParameter[846];
  TRACE_POP
}

/*
 equation index: 144
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcomplg[1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream2.C[1].SH, {MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tc, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778], (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678], (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680]);
  data->simulationInfo->realParameter[818] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[745], tmp2, tmp3, data->simulationInfo->realParameter[755], data->simulationInfo->realParameter[846]);
  TRACE_POP
}

/*
 equation index: 145
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcompvg[1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream2.C[1].SH, {MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tc, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778], (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678], (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680]);
  data->simulationInfo->realParameter[820] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[745], tmp4, tmp5, data->simulationInfo->realParameter[755], data->simulationInfo->realParameter[846]);
  TRACE_POP
}

/*
 equation index: 146
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcomplg[2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream2.C[2].SH, {MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tc, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784], (modelica_real)data->simulationInfo->realParameter[785], (modelica_real)data->simulationInfo->realParameter[786]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684], (modelica_real)data->simulationInfo->realParameter[685], (modelica_real)data->simulationInfo->realParameter[686]);
  data->simulationInfo->realParameter[819] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[746], tmp6, tmp7, data->simulationInfo->realParameter[756], data->simulationInfo->realParameter[846]);
  TRACE_POP
}

/*
 equation index: 147
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcompvg[2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream2.C[2].SH, {MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tc, MaterialStream2.Temp)
 */
void Flowsheet_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784], (modelica_real)data->simulationInfo->realParameter[785], (modelica_real)data->simulationInfo->realParameter[786]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684], (modelica_real)data->simulationInfo->realParameter[685], (modelica_real)data->simulationInfo->realParameter[686]);
  data->simulationInfo->realParameter[821] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[746], tmp8, tmp9, data->simulationInfo->realParameter[756], data->simulationInfo->realParameter[846]);
  TRACE_POP
}

/*
 equation index: 148
 type: SIMPLE_ASSIGN
 MaterialStream2._Pxc[1] = DIVISION(MaterialStream2.xguess[1], MaterialStream2.Psatt[1])
 */
void Flowsheet_eqFunction_148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,148};
  data->simulationInfo->realParameter[838] = DIVISION_SIM(data->simulationInfo->realParameter[850],data->simulationInfo->realParameter[835],"MaterialStream2.Psatt[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 149
 type: SIMPLE_ASSIGN
 MaterialStream2._Px = MaterialStream2.Pxc[1] + MaterialStream2.Pxc[2]
 */
void Flowsheet_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
  data->simulationInfo->realParameter[837] = data->simulationInfo->realParameter[838] + data->simulationInfo->realParameter[839];
  TRACE_POP
}

/*
 equation index: 150
 type: SIMPLE_ASSIGN
 MaterialStream2._Pmin = DIVISION(1.0, MaterialStream2.Px)
 */
void Flowsheet_eqFunction_150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,150};
  data->simulationInfo->realParameter[830] = DIVISION_SIM(1.0,data->simulationInfo->realParameter[837],"MaterialStream2.Px",equationIndexes);
  TRACE_POP
}

/*
 equation index: 151
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Pbubl = MaterialStream2.Pmin
 */
void Flowsheet_eqFunction_151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,151};
  data->modelData->realVarsData[146].attribute /* MaterialStream2._Pbubl variable */.start = data->simulationInfo->realParameter[830];
    data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */ = data->modelData->realVarsData[146].attribute /* MaterialStream2._Pbubl variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[146].info /* MaterialStream2._Pbubl */.name, (modelica_real) data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  TRACE_POP
}

/*
 equation index: 152
 type: SIMPLE_ASSIGN
 MaterialStream2._Pxm[1] = MaterialStream2.xguess[1] * MaterialStream2.Psatt[1]
 */
void Flowsheet_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
  data->simulationInfo->realParameter[840] = (data->simulationInfo->realParameter[850]) * (data->simulationInfo->realParameter[835]);
  TRACE_POP
}

/*
 equation index: 153
 type: SIMPLE_ASSIGN
 MaterialStream2._Pmax = MaterialStream2.Pxm[1] + MaterialStream2.Pxm[2]
 */
void Flowsheet_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
  data->simulationInfo->realParameter[829] = data->simulationInfo->realParameter[840] + data->simulationInfo->realParameter[841];
  TRACE_POP
}


/*
 equation index: 154
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = 0.0
 */
void Flowsheet_eqFunction_154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,154};
  data->simulationInfo->realParameter[855] = 0.0;
  TRACE_POP
}
/*
 equation index: 155
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = (MaterialStream2.Pg - MaterialStream2.Pmin) / (MaterialStream2.Pmax - MaterialStream2.Pmin)
 */
void Flowsheet_eqFunction_155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,155};
  modelica_real tmp12;
  tmp12 = data->simulationInfo->realParameter[829] - data->simulationInfo->realParameter[830];
  if (tmp12 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(MaterialStream2.Pg - MaterialStream2.Pmin) / (MaterialStream2.Pmax - MaterialStream2.Pmin)");}
  data->simulationInfo->realParameter[855] = (data->simulationInfo->realParameter[828] - data->simulationInfo->realParameter[830]) / tmp12;
  TRACE_POP
}
/*
 equation index: 156
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = 1.0
 */
void Flowsheet_eqFunction_156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,156};
  data->simulationInfo->realParameter[855] = 1.0;
  TRACE_POP
}
/*
 equation index: 157
 type: IFEQUATION
 
 equation index: 154
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = 0.0equation index: 155
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = (MaterialStream2.Pg - MaterialStream2.Pmin) / (MaterialStream2.Pmax - MaterialStream2.Pmin)
 equation index: 156
 type: SIMPLE_ASSIGN
 MaterialStream2._xvapg = 1.0
 */
void Flowsheet_eqFunction_157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,157};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  tmp10 = GreaterEq(data->simulationInfo->realParameter[828],data->simulationInfo->realParameter[829]);
  tmp11 = GreaterEq(data->simulationInfo->realParameter[828],data->simulationInfo->realParameter[830]);
  if(tmp10)
  {
    Flowsheet_eqFunction_154(data, threadData);
  }
  else if(tmp11)
  {
    Flowsheet_eqFunction_155(data, threadData);
  }else
  {
    Flowsheet_eqFunction_156(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 158
 type: SIMPLE_ASSIGN
 MaterialStream2._xliqg = 1.0 - MaterialStream2.xvapg
 */
void Flowsheet_eqFunction_158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,158};
  data->simulationInfo->realParameter[852] = 1.0 - data->simulationInfo->realParameter[855];
  TRACE_POP
}

/*
 equation index: 159
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xmliq = MaterialStream2.xliqg
 */
void Flowsheet_eqFunction_159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,159};
  data->modelData->realVarsData[185].attribute /* MaterialStream2._xmliq variable */.start = data->simulationInfo->realParameter[852];
    data->localData[0]->realVars[185] /* MaterialStream2._xmliq variable */ = data->modelData->realVarsData[185].attribute /* MaterialStream2._xmliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[185].info /* MaterialStream2._xmliq */.name, (modelica_real) data->localData[0]->realVars[185] /* MaterialStream2._xmliq variable */);
  TRACE_POP
}

/*
 equation index: 160
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xliq = MaterialStream2.xliqg
 */
void Flowsheet_eqFunction_160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,160};
  data->modelData->realVarsData[178].attribute /* MaterialStream2._xliq variable */.start = data->simulationInfo->realParameter[852];
    data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */ = data->modelData->realVarsData[178].attribute /* MaterialStream2._xliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[178].info /* MaterialStream2._xliq */.name, (modelica_real) data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */);
  TRACE_POP
}


/*
 equation index: 161
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = 1.0
 */
void Flowsheet_eqFunction_161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,161};
  data->simulationInfo->realParameter[654] = 1.0;
  TRACE_POP
}
/*
 equation index: 162
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = 0.0
 */
void Flowsheet_eqFunction_162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,162};
  data->simulationInfo->realParameter[654] = 0.0;
  TRACE_POP
}
/*
 equation index: 163
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = MaterialStream2.xvapg
 */
void Flowsheet_eqFunction_163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,163};
  data->simulationInfo->realParameter[654] = data->simulationInfo->realParameter[855];
  TRACE_POP
}
/*
 equation index: 164
 type: IFEQUATION
 
 equation index: 161
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = 1.0equation index: 162
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = 0.0
 equation index: 163
 type: SIMPLE_ASSIGN
 MaterialStream2._Beta = MaterialStream2.xvapg
 */
void Flowsheet_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  tmp13 = Greater(data->simulationInfo->realParameter[855],1.0);
  tmp14 = Less(data->simulationInfo->realParameter[855],0.0);
  if(tmp13)
  {
    Flowsheet_eqFunction_161(data, threadData);
  }
  else if(tmp14)
  {
    Flowsheet_eqFunction_162(data, threadData);
  }else
  {
    Flowsheet_eqFunction_163(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 165
 type: SIMPLE_ASSIGN
 MaterialStream2._Alpha = 1.0 - MaterialStream2.Beta
 */
void Flowsheet_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
  data->simulationInfo->realParameter[653] = 1.0 - data->simulationInfo->realParameter[654];
  TRACE_POP
}



/*
 equation index: 166
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1] * MaterialStream2.K_guess[1] / (1.0 + (-1.0 + MaterialStream2.K_guess[1]) * MaterialStream2.xvapg)
 */
void Flowsheet_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
  modelica_real tmp18;
  tmp18 = 1.0 + (-1.0 + data->simulationInfo->realParameter[826]) * (data->simulationInfo->realParameter[855]);
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.K_guess[1] / (1.0 + (-1.0 + MaterialStream2.K_guess[1]) * MaterialStream2.xvapg)");}
  data->simulationInfo->realParameter[858] = (data->simulationInfo->realParameter[850]) * ((data->simulationInfo->realParameter[826]) / tmp18);
  TRACE_POP
}
/*
 equation index: 167
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1]
 */
void Flowsheet_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
  data->simulationInfo->realParameter[858] = data->simulationInfo->realParameter[850];
  TRACE_POP
}
/*
 equation index: 168
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
  data->simulationInfo->realParameter[858] = 0.0;
  TRACE_POP
}
/*
 equation index: 169
 type: IFEQUATION
 
 equation index: 166
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1] * MaterialStream2.K_guess[1] / (1.0 + (-1.0 + MaterialStream2.K_guess[1]) * MaterialStream2.xvapg)equation index: 167
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1]
 equation index: 168
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,169};
  modelica_boolean tmp16;
  tmp16 = Greater(data->simulationInfo->realParameter[654],0.0);
  if((tmp16 && (data->simulationInfo->realParameter[654] != 1.0)))
  {
    Flowsheet_eqFunction_166(data, threadData);
  }
  else if((data->simulationInfo->realParameter[654] == 1.0))
  {
    Flowsheet_eqFunction_167(data, threadData);
  }else
  {
    Flowsheet_eqFunction_168(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 170
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.ymol[1] / MaterialStream2.K_guess[1]
 */
void Flowsheet_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
  modelica_real tmp22;
  tmp22 = data->simulationInfo->realParameter[826];
  if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.ymol[1] / MaterialStream2.K_guess[1]");}
  data->simulationInfo->realParameter[853] = (data->simulationInfo->realParameter[858]) / tmp22;
  TRACE_POP
}
/*
 equation index: 171
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.xguess[1]
 */
void Flowsheet_eqFunction_171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,171};
  data->simulationInfo->realParameter[853] = data->simulationInfo->realParameter[850];
  TRACE_POP
}
/*
 equation index: 172
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
  data->simulationInfo->realParameter[853] = 0.0;
  TRACE_POP
}
/*
 equation index: 173
 type: IFEQUATION
 
 equation index: 170
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.ymol[1] / MaterialStream2.K_guess[1]equation index: 171
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.xguess[1]
 equation index: 172
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_173(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,173};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  tmp20 = Greater(data->simulationInfo->realParameter[654],0.0);
  tmp21 = Less(data->simulationInfo->realParameter[654],1.0);
  if((tmp20 && tmp21))
  {
    Flowsheet_eqFunction_170(data, threadData);
  }
  else if((data->simulationInfo->realParameter[654] == 0.0))
  {
    Flowsheet_eqFunction_171(data, threadData);
  }else
  {
    Flowsheet_eqFunction_172(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 174
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,174};
  data->simulationInfo->realParameter[853] = 0.0;
  TRACE_POP
}

/*
 equation index: 175
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_175(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,175};
  data->simulationInfo->realParameter[858] = 0.0;
  TRACE_POP
}
/*
 equation index: 176
 type: IFEQUATION
 
 equation index: 169
 type: IFEQUATION
 
 equation index: 166
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1] * MaterialStream2.K_guess[1] / (1.0 + (-1.0 + MaterialStream2.K_guess[1]) * MaterialStream2.xvapg)equation index: 167
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = MaterialStream2.xguess[1]
 equation index: 168
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0equation index: 173
 type: IFEQUATION
 
 equation index: 170
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.ymol[1] / MaterialStream2.K_guess[1]equation index: 171
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = MaterialStream2.xguess[1]
 equation index: 172
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0
 equation index: 174
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[1] = 0.0equation index: 175
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_176(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,176};
  if((data->simulationInfo->realParameter[850] != 0.0))
  {
    Flowsheet_eqFunction_169(data, threadData);

    Flowsheet_eqFunction_173(data, threadData);
  }else
  {
    Flowsheet_eqFunction_174(data, threadData);
    Flowsheet_eqFunction_175(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 177
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = 0.0
 */
void Flowsheet_eqFunction_177(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,177};
  data->simulationInfo->realParameter[856] = 0.0;
  TRACE_POP
}
/*
 equation index: 178
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = 1.0
 */
void Flowsheet_eqFunction_178(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,178};
  data->simulationInfo->realParameter[856] = 1.0;
  TRACE_POP
}
/*
 equation index: 179
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = MaterialStream2.ymol[1]
 */
void Flowsheet_eqFunction_179(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,179};
  data->simulationInfo->realParameter[856] = data->simulationInfo->realParameter[858];
  TRACE_POP
}
/*
 equation index: 180
 type: IFEQUATION
 
 equation index: 177
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = 0.0equation index: 178
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = 1.0
 equation index: 179
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[1] = MaterialStream2.ymol[1]
 */
void Flowsheet_eqFunction_180(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,180};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  tmp24 = Less(data->simulationInfo->realParameter[858],0.0);
  tmp25 = Greater(data->simulationInfo->realParameter[858],1.0);
  if(tmp24)
  {
    Flowsheet_eqFunction_177(data, threadData);
  }
  else if(tmp25)
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
 $START._MaterialStream2._xm_pc[3,1] = MaterialStream2.yg[1]
 */
void Flowsheet_eqFunction_181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,181};
  data->modelData->realVarsData[183].attribute /* MaterialStream2._xm_pc[3,1] variable */.start = data->simulationInfo->realParameter[856];
    data->localData[0]->realVars[183] /* MaterialStream2._xm_pc[3,1] variable */ = data->modelData->realVarsData[183].attribute /* MaterialStream2._xm_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[183].info /* MaterialStream2._xm_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[183] /* MaterialStream2._xm_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 182
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[3,1] = MaterialStream2.yg[1]
 */
void Flowsheet_eqFunction_182(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,182};
  data->modelData->realVarsData[176].attribute /* MaterialStream2._x_pc[3,1] variable */.start = data->simulationInfo->realParameter[856];
    data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ = data->modelData->realVarsData[176].attribute /* MaterialStream2._x_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[176].info /* MaterialStream2._x_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */);
  TRACE_POP
}


/*
 equation index: 183
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = 0.0
 */
void Flowsheet_eqFunction_183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,183};
  data->simulationInfo->realParameter[848] = 0.0;
  TRACE_POP
}
/*
 equation index: 184
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = 1.0
 */
void Flowsheet_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
  data->simulationInfo->realParameter[848] = 1.0;
  TRACE_POP
}
/*
 equation index: 185
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = MaterialStream2.xmol[1]
 */
void Flowsheet_eqFunction_185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,185};
  data->simulationInfo->realParameter[848] = data->simulationInfo->realParameter[853];
  TRACE_POP
}
/*
 equation index: 186
 type: IFEQUATION
 
 equation index: 183
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = 0.0equation index: 184
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = 1.0
 equation index: 185
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[1] = MaterialStream2.xmol[1]
 */
void Flowsheet_eqFunction_186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,186};
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  tmp26 = Less(data->simulationInfo->realParameter[853],0.0);
  tmp27 = Greater(data->simulationInfo->realParameter[848],1.0);
  if(tmp26)
  {
    Flowsheet_eqFunction_183(data, threadData);
  }
  else if(tmp27)
  {
    Flowsheet_eqFunction_184(data, threadData);
  }else
  {
    Flowsheet_eqFunction_185(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 190
 type: LINEAR
 
 <var>MaterialStream2._Fvapg</var>
 <row>

 </row>
 <matrix>
 </matrix>
 */
void Flowsheet_eqFunction_190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,190};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 190 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[1].x[0] = data->simulationInfo->realParameter[815];
  retValue = solve_linear_system(data, threadData, 1);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,190};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 190 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[815] = data->simulationInfo->linearSystemData[1].x[0];
  TRACE_POP
}

/*
 equation index: 191
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._F_p[2] = MaterialStream2.Fliqg
 */
void Flowsheet_eqFunction_191(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,191};
  data->modelData->realVarsData[112].attribute /* MaterialStream2._F_p[2] variable */.start = data->simulationInfo->realParameter[814];
    data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */ = data->modelData->realVarsData[112].attribute /* MaterialStream2._F_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[112].info /* MaterialStream2._F_p[2] */.name, (modelica_real) data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 192
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._F_p[3] = MaterialStream2.Fvapg
 */
void Flowsheet_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
  data->modelData->realVarsData[113].attribute /* MaterialStream2._F_p[3] variable */.start = data->simulationInfo->realParameter[815];
    data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */ = data->modelData->realVarsData[113].attribute /* MaterialStream2._F_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[113].info /* MaterialStream2._F_p[3] */.name, (modelica_real) data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 193
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[2,1] = MaterialStream2.xg[1]
 */
void Flowsheet_eqFunction_193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,193};
  data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[2,1] variable */.start = data->simulationInfo->realParameter[848];
    data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[2,1] variable */ = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[181].info /* MaterialStream2._xm_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[2,1] variable */);
  TRACE_POP
}

/*
 equation index: 194
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[2,1] = MaterialStream2.xg[1]
 */
void Flowsheet_eqFunction_194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,194};
  data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[2,1] variable */.start = data->simulationInfo->realParameter[848];
    data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */ = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[174].info /* MaterialStream2._x_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */);
  TRACE_POP
}



/*
 equation index: 195
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2] * MaterialStream2.K_guess[2] / (1.0 + (-1.0 + MaterialStream2.K_guess[2]) * MaterialStream2.xvapg)
 */
void Flowsheet_eqFunction_195(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,195};
  modelica_real tmp31;
  tmp31 = 1.0 + (-1.0 + data->simulationInfo->realParameter[827]) * (data->simulationInfo->realParameter[855]);
  if (tmp31 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.K_guess[2] / (1.0 + (-1.0 + MaterialStream2.K_guess[2]) * MaterialStream2.xvapg)");}
  data->simulationInfo->realParameter[859] = (data->simulationInfo->realParameter[851]) * ((data->simulationInfo->realParameter[827]) / tmp31);
  TRACE_POP
}
/*
 equation index: 196
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2]
 */
void Flowsheet_eqFunction_196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,196};
  data->simulationInfo->realParameter[859] = data->simulationInfo->realParameter[851];
  TRACE_POP
}
/*
 equation index: 197
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,197};
  data->simulationInfo->realParameter[859] = 0.0;
  TRACE_POP
}
/*
 equation index: 198
 type: IFEQUATION
 
 equation index: 195
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2] * MaterialStream2.K_guess[2] / (1.0 + (-1.0 + MaterialStream2.K_guess[2]) * MaterialStream2.xvapg)equation index: 196
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2]
 equation index: 197
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
  modelica_boolean tmp29;
  tmp29 = Greater(data->simulationInfo->realParameter[654],0.0);
  if((tmp29 && (data->simulationInfo->realParameter[654] != 1.0)))
  {
    Flowsheet_eqFunction_195(data, threadData);
  }
  else if((data->simulationInfo->realParameter[654] == 1.0))
  {
    Flowsheet_eqFunction_196(data, threadData);
  }else
  {
    Flowsheet_eqFunction_197(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 199
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.ymol[2] / MaterialStream2.K_guess[2]
 */
void Flowsheet_eqFunction_199(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,199};
  modelica_real tmp35;
  tmp35 = data->simulationInfo->realParameter[827];
  if (tmp35 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.ymol[2] / MaterialStream2.K_guess[2]");}
  data->simulationInfo->realParameter[854] = (data->simulationInfo->realParameter[859]) / tmp35;
  TRACE_POP
}
/*
 equation index: 200
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.xguess[2]
 */
void Flowsheet_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
  data->simulationInfo->realParameter[854] = data->simulationInfo->realParameter[851];
  TRACE_POP
}
/*
 equation index: 201
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,201};
  data->simulationInfo->realParameter[854] = 0.0;
  TRACE_POP
}
/*
 equation index: 202
 type: IFEQUATION
 
 equation index: 199
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.ymol[2] / MaterialStream2.K_guess[2]equation index: 200
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.xguess[2]
 equation index: 201
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,202};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  tmp33 = Greater(data->simulationInfo->realParameter[654],0.0);
  tmp34 = Less(data->simulationInfo->realParameter[654],1.0);
  if((tmp33 && tmp34))
  {
    Flowsheet_eqFunction_199(data, threadData);
  }
  else if((data->simulationInfo->realParameter[654] == 0.0))
  {
    Flowsheet_eqFunction_200(data, threadData);
  }else
  {
    Flowsheet_eqFunction_201(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 203
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,203};
  data->simulationInfo->realParameter[854] = 0.0;
  TRACE_POP
}

/*
 equation index: 204
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
  data->simulationInfo->realParameter[859] = 0.0;
  TRACE_POP
}
/*
 equation index: 205
 type: IFEQUATION
 
 equation index: 198
 type: IFEQUATION
 
 equation index: 195
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2] * MaterialStream2.K_guess[2] / (1.0 + (-1.0 + MaterialStream2.K_guess[2]) * MaterialStream2.xvapg)equation index: 196
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = MaterialStream2.xguess[2]
 equation index: 197
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0equation index: 202
 type: IFEQUATION
 
 equation index: 199
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.ymol[2] / MaterialStream2.K_guess[2]equation index: 200
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = MaterialStream2.xguess[2]
 equation index: 201
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0
 equation index: 203
 type: SIMPLE_ASSIGN
 MaterialStream2._xmol[2] = 0.0equation index: 204
 type: SIMPLE_ASSIGN
 MaterialStream2._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
  if((data->simulationInfo->realParameter[851] != 0.0))
  {
    Flowsheet_eqFunction_198(data, threadData);

    Flowsheet_eqFunction_202(data, threadData);
  }else
  {
    Flowsheet_eqFunction_203(data, threadData);
    Flowsheet_eqFunction_204(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 206
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = 0.0
 */
void Flowsheet_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
  data->simulationInfo->realParameter[849] = 0.0;
  TRACE_POP
}
/*
 equation index: 207
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = 1.0
 */
void Flowsheet_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  data->simulationInfo->realParameter[849] = 1.0;
  TRACE_POP
}
/*
 equation index: 208
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = MaterialStream2.xmol[2]
 */
void Flowsheet_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,208};
  data->simulationInfo->realParameter[849] = data->simulationInfo->realParameter[854];
  TRACE_POP
}
/*
 equation index: 209
 type: IFEQUATION
 
 equation index: 206
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = 0.0equation index: 207
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = 1.0
 equation index: 208
 type: SIMPLE_ASSIGN
 MaterialStream2._xg[2] = MaterialStream2.xmol[2]
 */
void Flowsheet_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  tmp37 = Less(data->simulationInfo->realParameter[854],0.0);
  tmp38 = Greater(data->simulationInfo->realParameter[849],1.0);
  if(tmp37)
  {
    Flowsheet_eqFunction_206(data, threadData);
  }
  else if(tmp38)
  {
    Flowsheet_eqFunction_207(data, threadData);
  }else
  {
    Flowsheet_eqFunction_208(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 210
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[2,2] = MaterialStream2.xg[2]
 */
void Flowsheet_eqFunction_210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,210};
  data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[2,2] variable */.start = data->simulationInfo->realParameter[849];
    data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[2,2] variable */ = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[182].info /* MaterialStream2._xm_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 211
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[2,2] = MaterialStream2.xg[2]
 */
void Flowsheet_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
  data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[2,2] variable */.start = data->simulationInfo->realParameter[849];
    data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */ = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[175].info /* MaterialStream2._x_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */);
  TRACE_POP
}


/*
 equation index: 212
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = 0.0
 */
void Flowsheet_eqFunction_212(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,212};
  data->simulationInfo->realParameter[857] = 0.0;
  TRACE_POP
}
/*
 equation index: 213
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = 1.0
 */
void Flowsheet_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  data->simulationInfo->realParameter[857] = 1.0;
  TRACE_POP
}
/*
 equation index: 214
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = MaterialStream2.ymol[2]
 */
void Flowsheet_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  data->simulationInfo->realParameter[857] = data->simulationInfo->realParameter[859];
  TRACE_POP
}
/*
 equation index: 215
 type: IFEQUATION
 
 equation index: 212
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = 0.0equation index: 213
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = 1.0
 equation index: 214
 type: SIMPLE_ASSIGN
 MaterialStream2._yg[2] = MaterialStream2.ymol[2]
 */
void Flowsheet_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  tmp39 = Less(data->simulationInfo->realParameter[859],0.0);
  tmp40 = Greater(data->simulationInfo->realParameter[859],1.0);
  if(tmp39)
  {
    Flowsheet_eqFunction_212(data, threadData);
  }
  else if(tmp40)
  {
    Flowsheet_eqFunction_213(data, threadData);
  }else
  {
    Flowsheet_eqFunction_214(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 216
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[3,2] = MaterialStream2.yg[2]
 */
void Flowsheet_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  data->modelData->realVarsData[184].attribute /* MaterialStream2._xm_pc[3,2] variable */.start = data->simulationInfo->realParameter[857];
    data->localData[0]->realVars[184] /* MaterialStream2._xm_pc[3,2] variable */ = data->modelData->realVarsData[184].attribute /* MaterialStream2._xm_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[184].info /* MaterialStream2._xm_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[184] /* MaterialStream2._xm_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 217
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[3,2] = MaterialStream2.yg[2]
 */
void Flowsheet_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
  data->modelData->realVarsData[177].attribute /* MaterialStream2._x_pc[3,2] variable */.start = data->simulationInfo->realParameter[857];
    data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ = data->modelData->realVarsData[177].attribute /* MaterialStream2._x_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[177].info /* MaterialStream2._x_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 218
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xmvap = MaterialStream2.xvapg
 */
void Flowsheet_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
  data->modelData->realVarsData[186].attribute /* MaterialStream2._xmvap variable */.start = data->simulationInfo->realParameter[855];
    data->localData[0]->realVars[186] /* MaterialStream2._xmvap variable */ = data->modelData->realVarsData[186].attribute /* MaterialStream2._xmvap variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[186].info /* MaterialStream2._xmvap */.name, (modelica_real) data->localData[0]->realVars[186] /* MaterialStream2._xmvap variable */);
  TRACE_POP
}

/*
 equation index: 219
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Pdew = MaterialStream2.Pmax
 */
void Flowsheet_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
  data->modelData->realVarsData[147].attribute /* MaterialStream2._Pdew variable */.start = data->simulationInfo->realParameter[829];
    data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */ = data->modelData->realVarsData[147].attribute /* MaterialStream2._Pdew variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[147].info /* MaterialStream2._Pdew */.name, (modelica_real) data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
  TRACE_POP
}

/*
 equation index: 220
 type: SIMPLE_ASSIGN
 MaterialStream2._Hliqg = MaterialStream2.xguess[1] * MaterialStream2.Hcomplg[1] + MaterialStream2.xguess[2] * MaterialStream2.Hcomplg[2]
 */
void Flowsheet_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  data->simulationInfo->realParameter[822] = (data->simulationInfo->realParameter[850]) * (data->simulationInfo->realParameter[818]) + (data->simulationInfo->realParameter[851]) * (data->simulationInfo->realParameter[819]);
  TRACE_POP
}

/*
 equation index: 221
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._H_p[2] = MaterialStream2.Hliqg
 */
void Flowsheet_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  data->modelData->realVarsData[130].attribute /* MaterialStream2._H_p[2] variable */.start = data->simulationInfo->realParameter[822];
    data->localData[0]->realVars[130] /* MaterialStream2._H_p[2] variable */ = data->modelData->realVarsData[130].attribute /* MaterialStream2._H_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[130].info /* MaterialStream2._H_p[2] */.name, (modelica_real) data->localData[0]->realVars[130] /* MaterialStream2._H_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 222
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Cp_p[2] = MaterialStream2.Hliqg
 */
void Flowsheet_eqFunction_222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,222};
  data->modelData->realVarsData[101].attribute /* MaterialStream2._Cp_p[2] variable */.start = data->simulationInfo->realParameter[822];
    data->localData[0]->realVars[101] /* MaterialStream2._Cp_p[2] variable */ = data->modelData->realVarsData[101].attribute /* MaterialStream2._Cp_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[101].info /* MaterialStream2._Cp_p[2] */.name, (modelica_real) data->localData[0]->realVars[101] /* MaterialStream2._Cp_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 223
 type: SIMPLE_ASSIGN
 MaterialStream2._Hvapg = MaterialStream2.xguess[1] * MaterialStream2.Hcompvg[1] + MaterialStream2.xguess[2] * MaterialStream2.Hcompvg[2]
 */
void Flowsheet_eqFunction_223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,223};
  data->simulationInfo->realParameter[825] = (data->simulationInfo->realParameter[850]) * (data->simulationInfo->realParameter[820]) + (data->simulationInfo->realParameter[851]) * (data->simulationInfo->realParameter[821]);
  TRACE_POP
}

/*
 equation index: 224
 type: SIMPLE_ASSIGN
 MaterialStream2._Htotg = MaterialStream2.Hliqg + MaterialStream2.Hvapg
 */
void Flowsheet_eqFunction_224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,224};
  data->simulationInfo->realParameter[824] = data->simulationInfo->realParameter[822] + data->simulationInfo->realParameter[825];
  TRACE_POP
}

/*
 equation index: 225
 type: SIMPLE_ASSIGN
 MaterialStream2._Hmixg = MaterialStream2.Htotg
 */
void Flowsheet_eqFunction_225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,225};
  data->simulationInfo->realParameter[823] = data->simulationInfo->realParameter[824];
  TRACE_POP
}

/*
 equation index: 226
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._H_p[1] = MaterialStream2.Hmixg
 */
void Flowsheet_eqFunction_226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,226};
  data->modelData->realVarsData[129].attribute /* MaterialStream2._H_p[1] variable */.start = data->simulationInfo->realParameter[823];
    data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */ = data->modelData->realVarsData[129].attribute /* MaterialStream2._H_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[129].info /* MaterialStream2._H_p[1] */.name, (modelica_real) data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 227
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Cp_p[1] = MaterialStream2.Hmixg
 */
void Flowsheet_eqFunction_227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,227};
  data->modelData->realVarsData[100].attribute /* MaterialStream2._Cp_p[1] variable */.start = data->simulationInfo->realParameter[823];
    data->localData[0]->realVars[100] /* MaterialStream2._Cp_p[1] variable */ = data->modelData->realVarsData[100].attribute /* MaterialStream2._Cp_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[100].info /* MaterialStream2._Cp_p[1] */.name, (modelica_real) data->localData[0]->realVars[100] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 228
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcompg[1] = MaterialStream2.xguess[1] * MaterialStream2.Htotg
 */
void Flowsheet_eqFunction_228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,228};
  data->simulationInfo->realParameter[816] = (data->simulationInfo->realParameter[850]) * (data->simulationInfo->realParameter[824]);
  TRACE_POP
}

/*
 equation index: 229
 type: SIMPLE_ASSIGN
 MaterialStream2._Hcompg[2] = MaterialStream2.xguess[2] * MaterialStream2.Htotg
 */
void Flowsheet_eqFunction_229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,229};
  data->simulationInfo->realParameter[817] = (data->simulationInfo->realParameter[851]) * (data->simulationInfo->realParameter[824]);
  TRACE_POP
}

/*
 equation index: 230
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._H_p[3] = MaterialStream2.Hvapg
 */
void Flowsheet_eqFunction_230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,230};
  data->modelData->realVarsData[131].attribute /* MaterialStream2._H_p[3] variable */.start = data->simulationInfo->realParameter[825];
    data->localData[0]->realVars[131] /* MaterialStream2._H_p[3] variable */ = data->modelData->realVarsData[131].attribute /* MaterialStream2._H_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[131].info /* MaterialStream2._H_p[3] */.name, (modelica_real) data->localData[0]->realVars[131] /* MaterialStream2._H_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 231
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._Cp_p[3] = MaterialStream2.Hvapg
 */
void Flowsheet_eqFunction_231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,231};
  data->modelData->realVarsData[102].attribute /* MaterialStream2._Cp_p[3] variable */.start = data->simulationInfo->realParameter[825];
    data->localData[0]->realVars[102] /* MaterialStream2._Cp_p[3] variable */ = data->modelData->realVarsData[102].attribute /* MaterialStream2._Cp_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[102].info /* MaterialStream2._Cp_p[3] */.name, (modelica_real) data->localData[0]->realVars[102] /* MaterialStream2._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 232
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._xm_pc[1,1] = MaterialStream2.xguess[1]
 */
void Flowsheet_eqFunction_232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,232};
  data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[1,1] variable */.start = data->simulationInfo->realParameter[850];
    data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[1,1] variable */ = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[179].info /* MaterialStream2._xm_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 233
 type: SIMPLE_ASSIGN
 $START._MaterialStream2._x_pc[1,1] = MaterialStream2.xguess[1]
 */
void Flowsheet_eqFunction_233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,233};
  data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[1,1] variable */.start = data->simulationInfo->realParameter[850];
    data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */ = data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[172].info /* MaterialStream2._x_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 234
 type: SIMPLE_ASSIGN
 MaterialStream1._xguess[2] = 0.5
 */
void Flowsheet_eqFunction_234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,234};
  data->simulationInfo->realParameter[644] = 0.5;
  TRACE_POP
}

/*
 equation index: 235
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[1,2] = MaterialStream1.xguess[2]
 */
void Flowsheet_eqFunction_235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,235};
  data->modelData->realVarsData[93].attribute /* MaterialStream1._xm_pc[1,2] variable */.start = data->simulationInfo->realParameter[644];
    data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */ = data->modelData->realVarsData[93].attribute /* MaterialStream1._xm_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[93].info /* MaterialStream1._xm_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 236
 type: SIMPLE_ASSIGN
 MaterialStream1._xguess[1] = 0.5
 */
void Flowsheet_eqFunction_236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,236};
  data->simulationInfo->realParameter[643] = 0.5;
  TRACE_POP
}

void Flowsheet_eqFunction_237(DATA*,threadData_t*);
void Flowsheet_eqFunction_238(DATA*,threadData_t*);
void Flowsheet_eqFunction_239(DATA*,threadData_t*);
/*
 equation index: 240
 indexNonlinear: 4
 type: NONLINEAR
 
 vars: {MaterialStream1._Tdg}
 eqns: {237, 238, 239}
 */
void Flowsheet_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 240 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[4].nlsxOld[0] = data->simulationInfo->realParameter[638];
  retValue = solve_nonlinear_system(data, threadData, 4);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,240};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 240 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[638] = data->simulationInfo->nonlinearSystemData[4].nlsx[0];
  TRACE_POP
}

void Flowsheet_eqFunction_241(DATA*,threadData_t*);
void Flowsheet_eqFunction_242(DATA*,threadData_t*);
void Flowsheet_eqFunction_243(DATA*,threadData_t*);
/*
 equation index: 244
 indexNonlinear: 5
 type: NONLINEAR
 
 vars: {MaterialStream1._Tbg}
 eqns: {241, 242, 243}
 */
void Flowsheet_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 244 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[5].nlsxOld[0] = data->simulationInfo->realParameter[635];
  retValue = solve_nonlinear_system(data, threadData, 5);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,244};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 244 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[635] = data->simulationInfo->nonlinearSystemData[5].nlsx[0];
  TRACE_POP
}

/*
 equation index: 245
 type: SIMPLE_ASSIGN
 MaterialStream1._Temp = 0.5 * (MaterialStream1.Tbg + MaterialStream1.Tdg)
 */
void Flowsheet_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  data->simulationInfo->realParameter[639] = (0.5) * (data->simulationInfo->realParameter[635] + data->simulationInfo->realParameter[638]);
  TRACE_POP
}

/*
 equation index: 246
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatt[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[1].VP[1], MaterialStream1.C[1].VP[2], MaterialStream1.C[1].VP[3], MaterialStream1.C[1].VP[4], MaterialStream1.C[1].VP[5], MaterialStream1.C[1].VP[6]}, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[556], (modelica_real)data->simulationInfo->realParameter[557], (modelica_real)data->simulationInfo->realParameter[558], (modelica_real)data->simulationInfo->realParameter[559], (modelica_real)data->simulationInfo->realParameter[560], (modelica_real)data->simulationInfo->realParameter[561]);
  data->simulationInfo->realParameter[628] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[639]);
  TRACE_POP
}

/*
 equation index: 247
 type: SIMPLE_ASSIGN
 MaterialStream1._K_guess[1] = DIVISION(MaterialStream1.Psatt[1], MaterialStream1.Pg)
 */
void Flowsheet_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  data->simulationInfo->realParameter[619] = DIVISION_SIM(data->simulationInfo->realParameter[628],data->simulationInfo->realParameter[621],"MaterialStream1.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 248
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatt[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[2].VP[1], MaterialStream1.C[2].VP[2], MaterialStream1.C[2].VP[3], MaterialStream1.C[2].VP[4], MaterialStream1.C[2].VP[5], MaterialStream1.C[2].VP[6]}, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[562], (modelica_real)data->simulationInfo->realParameter[563], (modelica_real)data->simulationInfo->realParameter[564], (modelica_real)data->simulationInfo->realParameter[565], (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567]);
  data->simulationInfo->realParameter[629] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp1, data->simulationInfo->realParameter[639]);
  TRACE_POP
}

/*
 equation index: 249
 type: SIMPLE_ASSIGN
 MaterialStream1._K_guess[2] = DIVISION(MaterialStream1.Psatt[2], MaterialStream1.Pg)
 */
void Flowsheet_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
  data->simulationInfo->realParameter[620] = DIVISION_SIM(data->simulationInfo->realParameter[629],data->simulationInfo->realParameter[621],"MaterialStream1.Pg",equationIndexes);
  TRACE_POP
}

/*
 equation index: 250
 type: SIMPLE_ASSIGN
 MaterialStream1._Pxc[2] = DIVISION(MaterialStream1.xguess[2], MaterialStream1.Psatt[2])
 */
void Flowsheet_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
  data->simulationInfo->realParameter[632] = DIVISION_SIM(data->simulationInfo->realParameter[644],data->simulationInfo->realParameter[629],"MaterialStream1.Psatt[2]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 251
 type: SIMPLE_ASSIGN
 MaterialStream1._Pxm[2] = MaterialStream1.xguess[2] * MaterialStream1.Psatt[2]
 */
void Flowsheet_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  data->simulationInfo->realParameter[634] = (data->simulationInfo->realParameter[644]) * (data->simulationInfo->realParameter[629]);
  TRACE_POP
}

/*
 equation index: 252
 type: SIMPLE_ASSIGN
 MaterialStream1._Tg = MaterialStream1.Temp
 */
void Flowsheet_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  data->simulationInfo->realParameter[640] = data->simulationInfo->realParameter[639];
  TRACE_POP
}

/*
 equation index: 253
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcomplg[1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream1.C[1].SH, {MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tc, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571], (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471], (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473]);
  data->simulationInfo->realParameter[611] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[538], tmp2, tmp3, data->simulationInfo->realParameter[548], data->simulationInfo->realParameter[639]);
  TRACE_POP
}

/*
 equation index: 254
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcompvg[1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream1.C[1].SH, {MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tc, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571], (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471], (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473]);
  data->simulationInfo->realParameter[613] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[538], tmp4, tmp5, data->simulationInfo->realParameter[548], data->simulationInfo->realParameter[639]);
  TRACE_POP
}

/*
 equation index: 255
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcomplg[2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream1.C[2].SH, {MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tc, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  real_array tmp6;
  real_array tmp7;
  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577], (modelica_real)data->simulationInfo->realParameter[578], (modelica_real)data->simulationInfo->realParameter[579]);
  array_alloc_scalar_real_array(&tmp7, 6, (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477], (modelica_real)data->simulationInfo->realParameter[478], (modelica_real)data->simulationInfo->realParameter[479]);
  data->simulationInfo->realParameter[612] = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[539], tmp6, tmp7, data->simulationInfo->realParameter[549], data->simulationInfo->realParameter[639]);
  TRACE_POP
}

/*
 equation index: 256
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcompvg[2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream1.C[2].SH, {MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tc, MaterialStream1.Temp)
 */
void Flowsheet_eqFunction_256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,256};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577], (modelica_real)data->simulationInfo->realParameter[578], (modelica_real)data->simulationInfo->realParameter[579]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477], (modelica_real)data->simulationInfo->realParameter[478], (modelica_real)data->simulationInfo->realParameter[479]);
  data->simulationInfo->realParameter[614] = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[539], tmp8, tmp9, data->simulationInfo->realParameter[549], data->simulationInfo->realParameter[639]);
  TRACE_POP
}

/*
 equation index: 257
 type: SIMPLE_ASSIGN
 MaterialStream1._Pxc[1] = DIVISION(MaterialStream1.xguess[1], MaterialStream1.Psatt[1])
 */
void Flowsheet_eqFunction_257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,257};
  data->simulationInfo->realParameter[631] = DIVISION_SIM(data->simulationInfo->realParameter[643],data->simulationInfo->realParameter[628],"MaterialStream1.Psatt[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 258
 type: SIMPLE_ASSIGN
 MaterialStream1._Px = MaterialStream1.Pxc[1] + MaterialStream1.Pxc[2]
 */
void Flowsheet_eqFunction_258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,258};
  data->simulationInfo->realParameter[630] = data->simulationInfo->realParameter[631] + data->simulationInfo->realParameter[632];
  TRACE_POP
}

/*
 equation index: 259
 type: SIMPLE_ASSIGN
 MaterialStream1._Pmin = DIVISION(1.0, MaterialStream1.Px)
 */
void Flowsheet_eqFunction_259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,259};
  data->simulationInfo->realParameter[623] = DIVISION_SIM(1.0,data->simulationInfo->realParameter[630],"MaterialStream1.Px",equationIndexes);
  TRACE_POP
}

/*
 equation index: 260
 type: SIMPLE_ASSIGN
 MaterialStream1._Pxm[1] = MaterialStream1.xguess[1] * MaterialStream1.Psatt[1]
 */
void Flowsheet_eqFunction_260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,260};
  data->simulationInfo->realParameter[633] = (data->simulationInfo->realParameter[643]) * (data->simulationInfo->realParameter[628]);
  TRACE_POP
}

/*
 equation index: 261
 type: SIMPLE_ASSIGN
 MaterialStream1._Pmax = MaterialStream1.Pxm[1] + MaterialStream1.Pxm[2]
 */
void Flowsheet_eqFunction_261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,261};
  data->simulationInfo->realParameter[622] = data->simulationInfo->realParameter[633] + data->simulationInfo->realParameter[634];
  TRACE_POP
}


/*
 equation index: 262
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = 0.0
 */
void Flowsheet_eqFunction_262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,262};
  data->simulationInfo->realParameter[648] = 0.0;
  TRACE_POP
}
/*
 equation index: 263
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = (MaterialStream1.Pg - MaterialStream1.Pmin) / (MaterialStream1.Pmax - MaterialStream1.Pmin)
 */
void Flowsheet_eqFunction_263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,263};
  modelica_real tmp12;
  tmp12 = data->simulationInfo->realParameter[622] - data->simulationInfo->realParameter[623];
  if (tmp12 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(MaterialStream1.Pg - MaterialStream1.Pmin) / (MaterialStream1.Pmax - MaterialStream1.Pmin)");}
  data->simulationInfo->realParameter[648] = (data->simulationInfo->realParameter[621] - data->simulationInfo->realParameter[623]) / tmp12;
  TRACE_POP
}
/*
 equation index: 264
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = 1.0
 */
void Flowsheet_eqFunction_264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,264};
  data->simulationInfo->realParameter[648] = 1.0;
  TRACE_POP
}
/*
 equation index: 265
 type: IFEQUATION
 
 equation index: 262
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = 0.0equation index: 263
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = (MaterialStream1.Pg - MaterialStream1.Pmin) / (MaterialStream1.Pmax - MaterialStream1.Pmin)
 equation index: 264
 type: SIMPLE_ASSIGN
 MaterialStream1._xvapg = 1.0
 */
void Flowsheet_eqFunction_265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,265};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  tmp10 = GreaterEq(data->simulationInfo->realParameter[621],data->simulationInfo->realParameter[622]);
  tmp11 = GreaterEq(data->simulationInfo->realParameter[621],data->simulationInfo->realParameter[623]);
  if(tmp10)
  {
    Flowsheet_eqFunction_262(data, threadData);
  }
  else if(tmp11)
  {
    Flowsheet_eqFunction_263(data, threadData);
  }else
  {
    Flowsheet_eqFunction_264(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 266
 type: SIMPLE_ASSIGN
 MaterialStream1._xliqg = 1.0 - MaterialStream1.xvapg
 */
void Flowsheet_eqFunction_266(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,266};
  data->simulationInfo->realParameter[645] = 1.0 - data->simulationInfo->realParameter[648];
  TRACE_POP
}

/*
 equation index: 267
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xmliq = MaterialStream1.xliqg
 */
void Flowsheet_eqFunction_267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,267};
  data->modelData->realVarsData[98].attribute /* MaterialStream1._xmliq variable */.start = data->simulationInfo->realParameter[645];
    data->localData[0]->realVars[98] /* MaterialStream1._xmliq variable */ = data->modelData->realVarsData[98].attribute /* MaterialStream1._xmliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[98].info /* MaterialStream1._xmliq */.name, (modelica_real) data->localData[0]->realVars[98] /* MaterialStream1._xmliq variable */);
  TRACE_POP
}

/*
 equation index: 268
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xliq = MaterialStream1.xliqg
 */
void Flowsheet_eqFunction_268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,268};
  data->modelData->realVarsData[91].attribute /* MaterialStream1._xliq variable */.start = data->simulationInfo->realParameter[645];
    data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */ = data->modelData->realVarsData[91].attribute /* MaterialStream1._xliq variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[91].info /* MaterialStream1._xliq */.name, (modelica_real) data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */);
  TRACE_POP
}


/*
 equation index: 269
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = 1.0
 */
void Flowsheet_eqFunction_269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,269};
  data->simulationInfo->realParameter[447] = 1.0;
  TRACE_POP
}
/*
 equation index: 270
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = 0.0
 */
void Flowsheet_eqFunction_270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,270};
  data->simulationInfo->realParameter[447] = 0.0;
  TRACE_POP
}
/*
 equation index: 271
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = MaterialStream1.xvapg
 */
void Flowsheet_eqFunction_271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,271};
  data->simulationInfo->realParameter[447] = data->simulationInfo->realParameter[648];
  TRACE_POP
}
/*
 equation index: 272
 type: IFEQUATION
 
 equation index: 269
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = 1.0equation index: 270
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = 0.0
 equation index: 271
 type: SIMPLE_ASSIGN
 MaterialStream1._Beta = MaterialStream1.xvapg
 */
void Flowsheet_eqFunction_272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,272};
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  tmp13 = Greater(data->simulationInfo->realParameter[648],1.0);
  tmp14 = Less(data->simulationInfo->realParameter[648],0.0);
  if(tmp13)
  {
    Flowsheet_eqFunction_269(data, threadData);
  }
  else if(tmp14)
  {
    Flowsheet_eqFunction_270(data, threadData);
  }else
  {
    Flowsheet_eqFunction_271(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 273
 type: SIMPLE_ASSIGN
 MaterialStream1._Alpha = 1.0 - MaterialStream1.Beta
 */
void Flowsheet_eqFunction_273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,273};
  data->simulationInfo->realParameter[446] = 1.0 - data->simulationInfo->realParameter[447];
  TRACE_POP
}



/*
 equation index: 274
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1] * MaterialStream1.K_guess[1] / (1.0 + (-1.0 + MaterialStream1.K_guess[1]) * MaterialStream1.xvapg)
 */
void Flowsheet_eqFunction_274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,274};
  modelica_real tmp18;
  tmp18 = 1.0 + (-1.0 + data->simulationInfo->realParameter[619]) * (data->simulationInfo->realParameter[648]);
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.K_guess[1] / (1.0 + (-1.0 + MaterialStream1.K_guess[1]) * MaterialStream1.xvapg)");}
  data->simulationInfo->realParameter[651] = (data->simulationInfo->realParameter[643]) * ((data->simulationInfo->realParameter[619]) / tmp18);
  TRACE_POP
}
/*
 equation index: 275
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1]
 */
void Flowsheet_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
  data->simulationInfo->realParameter[651] = data->simulationInfo->realParameter[643];
  TRACE_POP
}
/*
 equation index: 276
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,276};
  data->simulationInfo->realParameter[651] = 0.0;
  TRACE_POP
}
/*
 equation index: 277
 type: IFEQUATION
 
 equation index: 274
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1] * MaterialStream1.K_guess[1] / (1.0 + (-1.0 + MaterialStream1.K_guess[1]) * MaterialStream1.xvapg)equation index: 275
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1]
 equation index: 276
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,277};
  modelica_boolean tmp16;
  tmp16 = Greater(data->simulationInfo->realParameter[447],0.0);
  if((tmp16 && (data->simulationInfo->realParameter[447] != 1.0)))
  {
    Flowsheet_eqFunction_274(data, threadData);
  }
  else if((data->simulationInfo->realParameter[447] == 1.0))
  {
    Flowsheet_eqFunction_275(data, threadData);
  }else
  {
    Flowsheet_eqFunction_276(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 278
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.ymol[1] / MaterialStream1.K_guess[1]
 */
void Flowsheet_eqFunction_278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,278};
  modelica_real tmp22;
  tmp22 = data->simulationInfo->realParameter[619];
  if (tmp22 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.ymol[1] / MaterialStream1.K_guess[1]");}
  data->simulationInfo->realParameter[646] = (data->simulationInfo->realParameter[651]) / tmp22;
  TRACE_POP
}
/*
 equation index: 279
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.xguess[1]
 */
void Flowsheet_eqFunction_279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,279};
  data->simulationInfo->realParameter[646] = data->simulationInfo->realParameter[643];
  TRACE_POP
}
/*
 equation index: 280
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,280};
  data->simulationInfo->realParameter[646] = 0.0;
  TRACE_POP
}
/*
 equation index: 281
 type: IFEQUATION
 
 equation index: 278
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.ymol[1] / MaterialStream1.K_guess[1]equation index: 279
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.xguess[1]
 equation index: 280
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,281};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  tmp20 = Greater(data->simulationInfo->realParameter[447],0.0);
  tmp21 = Less(data->simulationInfo->realParameter[447],1.0);
  if((tmp20 && tmp21))
  {
    Flowsheet_eqFunction_278(data, threadData);
  }
  else if((data->simulationInfo->realParameter[447] == 0.0))
  {
    Flowsheet_eqFunction_279(data, threadData);
  }else
  {
    Flowsheet_eqFunction_280(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 282
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0
 */
void Flowsheet_eqFunction_282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,282};
  data->simulationInfo->realParameter[646] = 0.0;
  TRACE_POP
}

/*
 equation index: 283
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,283};
  data->simulationInfo->realParameter[651] = 0.0;
  TRACE_POP
}
/*
 equation index: 284
 type: IFEQUATION
 
 equation index: 277
 type: IFEQUATION
 
 equation index: 274
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1] * MaterialStream1.K_guess[1] / (1.0 + (-1.0 + MaterialStream1.K_guess[1]) * MaterialStream1.xvapg)equation index: 275
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = MaterialStream1.xguess[1]
 equation index: 276
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0equation index: 281
 type: IFEQUATION
 
 equation index: 278
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.ymol[1] / MaterialStream1.K_guess[1]equation index: 279
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = MaterialStream1.xguess[1]
 equation index: 280
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0
 equation index: 282
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[1] = 0.0equation index: 283
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[1] = 0.0
 */
void Flowsheet_eqFunction_284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,284};
  if((data->simulationInfo->realParameter[643] != 0.0))
  {
    Flowsheet_eqFunction_277(data, threadData);

    Flowsheet_eqFunction_281(data, threadData);
  }else
  {
    Flowsheet_eqFunction_282(data, threadData);
    Flowsheet_eqFunction_283(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 285
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = 0.0
 */
void Flowsheet_eqFunction_285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,285};
  data->simulationInfo->realParameter[649] = 0.0;
  TRACE_POP
}
/*
 equation index: 286
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = 1.0
 */
void Flowsheet_eqFunction_286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,286};
  data->simulationInfo->realParameter[649] = 1.0;
  TRACE_POP
}
/*
 equation index: 287
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = MaterialStream1.ymol[1]
 */
void Flowsheet_eqFunction_287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,287};
  data->simulationInfo->realParameter[649] = data->simulationInfo->realParameter[651];
  TRACE_POP
}
/*
 equation index: 288
 type: IFEQUATION
 
 equation index: 285
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = 0.0equation index: 286
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = 1.0
 equation index: 287
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[1] = MaterialStream1.ymol[1]
 */
void Flowsheet_eqFunction_288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,288};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  tmp24 = Less(data->simulationInfo->realParameter[651],0.0);
  tmp25 = Greater(data->simulationInfo->realParameter[651],1.0);
  if(tmp24)
  {
    Flowsheet_eqFunction_285(data, threadData);
  }
  else if(tmp25)
  {
    Flowsheet_eqFunction_286(data, threadData);
  }else
  {
    Flowsheet_eqFunction_287(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 289
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[3,1] = MaterialStream1.yg[1]
 */
void Flowsheet_eqFunction_289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,289};
  data->modelData->realVarsData[96].attribute /* MaterialStream1._xm_pc[3,1] variable */.start = data->simulationInfo->realParameter[649];
    data->localData[0]->realVars[96] /* MaterialStream1._xm_pc[3,1] variable */ = data->modelData->realVarsData[96].attribute /* MaterialStream1._xm_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[96].info /* MaterialStream1._xm_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[96] /* MaterialStream1._xm_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 290
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[3,1] = MaterialStream1.yg[1]
 */
void Flowsheet_eqFunction_290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,290};
  data->modelData->realVarsData[89].attribute /* MaterialStream1._x_pc[3,1] variable */.start = data->simulationInfo->realParameter[649];
    data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ = data->modelData->realVarsData[89].attribute /* MaterialStream1._x_pc[3,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[89].info /* MaterialStream1._x_pc[3,1] */.name, (modelica_real) data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */);
  TRACE_POP
}


/*
 equation index: 291
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = 0.0
 */
void Flowsheet_eqFunction_291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,291};
  data->simulationInfo->realParameter[641] = 0.0;
  TRACE_POP
}
/*
 equation index: 292
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = 1.0
 */
void Flowsheet_eqFunction_292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,292};
  data->simulationInfo->realParameter[641] = 1.0;
  TRACE_POP
}
/*
 equation index: 293
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = MaterialStream1.xmol[1]
 */
void Flowsheet_eqFunction_293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,293};
  data->simulationInfo->realParameter[641] = data->simulationInfo->realParameter[646];
  TRACE_POP
}
/*
 equation index: 294
 type: IFEQUATION
 
 equation index: 291
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = 0.0equation index: 292
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = 1.0
 equation index: 293
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[1] = MaterialStream1.xmol[1]
 */
void Flowsheet_eqFunction_294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,294};
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  tmp26 = Less(data->simulationInfo->realParameter[646],0.0);
  tmp27 = Greater(data->simulationInfo->realParameter[641],1.0);
  if(tmp26)
  {
    Flowsheet_eqFunction_291(data, threadData);
  }
  else if(tmp27)
  {
    Flowsheet_eqFunction_292(data, threadData);
  }else
  {
    Flowsheet_eqFunction_293(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 298
 type: LINEAR
 
 <var>MaterialStream1._Fvapg</var>
 <row>

 </row>
 <matrix>
 </matrix>
 */
void Flowsheet_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 298 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[2].x[0] = data->simulationInfo->realParameter[608];
  retValue = solve_linear_system(data, threadData, 2);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,298};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 298 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->simulationInfo->realParameter[608] = data->simulationInfo->linearSystemData[2].x[0];
  TRACE_POP
}

/*
 equation index: 299
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._F_p[2] = MaterialStream1.Fliqg
 */
void Flowsheet_eqFunction_299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,299};
  data->modelData->realVarsData[23].attribute /* MaterialStream1._F_p[2] variable */.start = data->simulationInfo->realParameter[607];
    data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */ = data->modelData->realVarsData[23].attribute /* MaterialStream1._F_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[23].info /* MaterialStream1._F_p[2] */.name, (modelica_real) data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 300
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._F_p[3] = MaterialStream1.Fvapg
 */
void Flowsheet_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,300};
  data->modelData->realVarsData[24].attribute /* MaterialStream1._F_p[3] variable */.start = data->simulationInfo->realParameter[608];
    data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */ = data->modelData->realVarsData[24].attribute /* MaterialStream1._F_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[24].info /* MaterialStream1._F_p[3] */.name, (modelica_real) data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 301
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[2,1] = MaterialStream1.xg[1]
 */
void Flowsheet_eqFunction_301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,301};
  data->modelData->realVarsData[94].attribute /* MaterialStream1._xm_pc[2,1] variable */.start = data->simulationInfo->realParameter[641];
    data->localData[0]->realVars[94] /* MaterialStream1._xm_pc[2,1] variable */ = data->modelData->realVarsData[94].attribute /* MaterialStream1._xm_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[94].info /* MaterialStream1._xm_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[94] /* MaterialStream1._xm_pc[2,1] variable */);
  TRACE_POP
}

/*
 equation index: 302
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[2,1] = MaterialStream1.xg[1]
 */
void Flowsheet_eqFunction_302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,302};
  data->modelData->realVarsData[87].attribute /* MaterialStream1._x_pc[2,1] variable */.start = data->simulationInfo->realParameter[641];
    data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */ = data->modelData->realVarsData[87].attribute /* MaterialStream1._x_pc[2,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[87].info /* MaterialStream1._x_pc[2,1] */.name, (modelica_real) data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */);
  TRACE_POP
}



/*
 equation index: 303
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2] * MaterialStream1.K_guess[2] / (1.0 + (-1.0 + MaterialStream1.K_guess[2]) * MaterialStream1.xvapg)
 */
void Flowsheet_eqFunction_303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,303};
  modelica_real tmp31;
  tmp31 = 1.0 + (-1.0 + data->simulationInfo->realParameter[620]) * (data->simulationInfo->realParameter[648]);
  if (tmp31 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.K_guess[2] / (1.0 + (-1.0 + MaterialStream1.K_guess[2]) * MaterialStream1.xvapg)");}
  data->simulationInfo->realParameter[652] = (data->simulationInfo->realParameter[644]) * ((data->simulationInfo->realParameter[620]) / tmp31);
  TRACE_POP
}
/*
 equation index: 304
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2]
 */
void Flowsheet_eqFunction_304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,304};
  data->simulationInfo->realParameter[652] = data->simulationInfo->realParameter[644];
  TRACE_POP
}
/*
 equation index: 305
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,305};
  data->simulationInfo->realParameter[652] = 0.0;
  TRACE_POP
}
/*
 equation index: 306
 type: IFEQUATION
 
 equation index: 303
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2] * MaterialStream1.K_guess[2] / (1.0 + (-1.0 + MaterialStream1.K_guess[2]) * MaterialStream1.xvapg)equation index: 304
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2]
 equation index: 305
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,306};
  modelica_boolean tmp29;
  tmp29 = Greater(data->simulationInfo->realParameter[447],0.0);
  if((tmp29 && (data->simulationInfo->realParameter[447] != 1.0)))
  {
    Flowsheet_eqFunction_303(data, threadData);
  }
  else if((data->simulationInfo->realParameter[447] == 1.0))
  {
    Flowsheet_eqFunction_304(data, threadData);
  }else
  {
    Flowsheet_eqFunction_305(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 307
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.ymol[2] / MaterialStream1.K_guess[2]
 */
void Flowsheet_eqFunction_307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,307};
  modelica_real tmp35;
  tmp35 = data->simulationInfo->realParameter[620];
  if (tmp35 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.ymol[2] / MaterialStream1.K_guess[2]");}
  data->simulationInfo->realParameter[647] = (data->simulationInfo->realParameter[652]) / tmp35;
  TRACE_POP
}
/*
 equation index: 308
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.xguess[2]
 */
void Flowsheet_eqFunction_308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,308};
  data->simulationInfo->realParameter[647] = data->simulationInfo->realParameter[644];
  TRACE_POP
}
/*
 equation index: 309
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,309};
  data->simulationInfo->realParameter[647] = 0.0;
  TRACE_POP
}
/*
 equation index: 310
 type: IFEQUATION
 
 equation index: 307
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.ymol[2] / MaterialStream1.K_guess[2]equation index: 308
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.xguess[2]
 equation index: 309
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,310};
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  tmp33 = Greater(data->simulationInfo->realParameter[447],0.0);
  tmp34 = Less(data->simulationInfo->realParameter[447],1.0);
  if((tmp33 && tmp34))
  {
    Flowsheet_eqFunction_307(data, threadData);
  }
  else if((data->simulationInfo->realParameter[447] == 0.0))
  {
    Flowsheet_eqFunction_308(data, threadData);
  }else
  {
    Flowsheet_eqFunction_309(data, threadData);
  }
  TRACE_POP
}
/*
 equation index: 311
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0
 */
void Flowsheet_eqFunction_311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,311};
  data->simulationInfo->realParameter[647] = 0.0;
  TRACE_POP
}

/*
 equation index: 312
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,312};
  data->simulationInfo->realParameter[652] = 0.0;
  TRACE_POP
}
/*
 equation index: 313
 type: IFEQUATION
 
 equation index: 306
 type: IFEQUATION
 
 equation index: 303
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2] * MaterialStream1.K_guess[2] / (1.0 + (-1.0 + MaterialStream1.K_guess[2]) * MaterialStream1.xvapg)equation index: 304
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = MaterialStream1.xguess[2]
 equation index: 305
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0equation index: 310
 type: IFEQUATION
 
 equation index: 307
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.ymol[2] / MaterialStream1.K_guess[2]equation index: 308
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = MaterialStream1.xguess[2]
 equation index: 309
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0
 equation index: 311
 type: SIMPLE_ASSIGN
 MaterialStream1._xmol[2] = 0.0equation index: 312
 type: SIMPLE_ASSIGN
 MaterialStream1._ymol[2] = 0.0
 */
void Flowsheet_eqFunction_313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,313};
  if((data->simulationInfo->realParameter[644] != 0.0))
  {
    Flowsheet_eqFunction_306(data, threadData);

    Flowsheet_eqFunction_310(data, threadData);
  }else
  {
    Flowsheet_eqFunction_311(data, threadData);
    Flowsheet_eqFunction_312(data, threadData);
  }
  TRACE_POP
}


/*
 equation index: 314
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = 0.0
 */
void Flowsheet_eqFunction_314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,314};
  data->simulationInfo->realParameter[650] = 0.0;
  TRACE_POP
}
/*
 equation index: 315
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = 1.0
 */
void Flowsheet_eqFunction_315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,315};
  data->simulationInfo->realParameter[650] = 1.0;
  TRACE_POP
}
/*
 equation index: 316
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = MaterialStream1.ymol[2]
 */
void Flowsheet_eqFunction_316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,316};
  data->simulationInfo->realParameter[650] = data->simulationInfo->realParameter[652];
  TRACE_POP
}
/*
 equation index: 317
 type: IFEQUATION
 
 equation index: 314
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = 0.0equation index: 315
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = 1.0
 equation index: 316
 type: SIMPLE_ASSIGN
 MaterialStream1._yg[2] = MaterialStream1.ymol[2]
 */
void Flowsheet_eqFunction_317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,317};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  tmp37 = Less(data->simulationInfo->realParameter[652],0.0);
  tmp38 = Greater(data->simulationInfo->realParameter[652],1.0);
  if(tmp37)
  {
    Flowsheet_eqFunction_314(data, threadData);
  }
  else if(tmp38)
  {
    Flowsheet_eqFunction_315(data, threadData);
  }else
  {
    Flowsheet_eqFunction_316(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 318
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[3,2] = MaterialStream1.yg[2]
 */
void Flowsheet_eqFunction_318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,318};
  data->modelData->realVarsData[97].attribute /* MaterialStream1._xm_pc[3,2] variable */.start = data->simulationInfo->realParameter[650];
    data->localData[0]->realVars[97] /* MaterialStream1._xm_pc[3,2] variable */ = data->modelData->realVarsData[97].attribute /* MaterialStream1._xm_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[97].info /* MaterialStream1._xm_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[97] /* MaterialStream1._xm_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 319
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[3,2] = MaterialStream1.yg[2]
 */
void Flowsheet_eqFunction_319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,319};
  data->modelData->realVarsData[90].attribute /* MaterialStream1._x_pc[3,2] variable */.start = data->simulationInfo->realParameter[650];
    data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ = data->modelData->realVarsData[90].attribute /* MaterialStream1._x_pc[3,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[90].info /* MaterialStream1._x_pc[3,2] */.name, (modelica_real) data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */);
  TRACE_POP
}


/*
 equation index: 320
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = 0.0
 */
void Flowsheet_eqFunction_320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,320};
  data->simulationInfo->realParameter[642] = 0.0;
  TRACE_POP
}
/*
 equation index: 321
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = 1.0
 */
void Flowsheet_eqFunction_321(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,321};
  data->simulationInfo->realParameter[642] = 1.0;
  TRACE_POP
}
/*
 equation index: 322
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = MaterialStream1.xmol[2]
 */
void Flowsheet_eqFunction_322(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,322};
  data->simulationInfo->realParameter[642] = data->simulationInfo->realParameter[647];
  TRACE_POP
}
/*
 equation index: 323
 type: IFEQUATION
 
 equation index: 320
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = 0.0equation index: 321
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = 1.0
 equation index: 322
 type: SIMPLE_ASSIGN
 MaterialStream1._xg[2] = MaterialStream1.xmol[2]
 */
void Flowsheet_eqFunction_323(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,323};
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  tmp39 = Less(data->simulationInfo->realParameter[647],0.0);
  tmp40 = Greater(data->simulationInfo->realParameter[642],1.0);
  if(tmp39)
  {
    Flowsheet_eqFunction_320(data, threadData);
  }
  else if(tmp40)
  {
    Flowsheet_eqFunction_321(data, threadData);
  }else
  {
    Flowsheet_eqFunction_322(data, threadData);
  }
  TRACE_POP
}

/*
 equation index: 324
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[2,2] = MaterialStream1.xg[2]
 */
void Flowsheet_eqFunction_324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,324};
  data->modelData->realVarsData[95].attribute /* MaterialStream1._xm_pc[2,2] variable */.start = data->simulationInfo->realParameter[642];
    data->localData[0]->realVars[95] /* MaterialStream1._xm_pc[2,2] variable */ = data->modelData->realVarsData[95].attribute /* MaterialStream1._xm_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[95].info /* MaterialStream1._xm_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[95] /* MaterialStream1._xm_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 325
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[2,2] = MaterialStream1.xg[2]
 */
void Flowsheet_eqFunction_325(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,325};
  data->modelData->realVarsData[88].attribute /* MaterialStream1._x_pc[2,2] variable */.start = data->simulationInfo->realParameter[642];
    data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */ = data->modelData->realVarsData[88].attribute /* MaterialStream1._x_pc[2,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[88].info /* MaterialStream1._x_pc[2,2] */.name, (modelica_real) data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 326
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xmvap = MaterialStream1.xvapg
 */
void Flowsheet_eqFunction_326(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,326};
  data->modelData->realVarsData[99].attribute /* MaterialStream1._xmvap variable */.start = data->simulationInfo->realParameter[648];
    data->localData[0]->realVars[99] /* MaterialStream1._xmvap variable */ = data->modelData->realVarsData[99].attribute /* MaterialStream1._xmvap variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[99].info /* MaterialStream1._xmvap */.name, (modelica_real) data->localData[0]->realVars[99] /* MaterialStream1._xmvap variable */);
  TRACE_POP
}

/*
 equation index: 327
 type: SIMPLE_ASSIGN
 MaterialStream1._Hliqg = MaterialStream1.xguess[1] * MaterialStream1.Hcomplg[1] + MaterialStream1.xguess[2] * MaterialStream1.Hcomplg[2]
 */
void Flowsheet_eqFunction_327(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,327};
  data->simulationInfo->realParameter[615] = (data->simulationInfo->realParameter[643]) * (data->simulationInfo->realParameter[611]) + (data->simulationInfo->realParameter[644]) * (data->simulationInfo->realParameter[612]);
  TRACE_POP
}

/*
 equation index: 328
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._H_p[2] = MaterialStream1.Hliqg
 */
void Flowsheet_eqFunction_328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,328};
  data->modelData->realVarsData[41].attribute /* MaterialStream1._H_p[2] variable */.start = data->simulationInfo->realParameter[615];
    data->localData[0]->realVars[41] /* MaterialStream1._H_p[2] variable */ = data->modelData->realVarsData[41].attribute /* MaterialStream1._H_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[41].info /* MaterialStream1._H_p[2] */.name, (modelica_real) data->localData[0]->realVars[41] /* MaterialStream1._H_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 329
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Cp_p[2] = MaterialStream1.Hliqg
 */
void Flowsheet_eqFunction_329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,329};
  data->modelData->realVarsData[11].attribute /* MaterialStream1._Cp_p[2] variable */.start = data->simulationInfo->realParameter[615];
    data->localData[0]->realVars[11] /* MaterialStream1._Cp_p[2] variable */ = data->modelData->realVarsData[11].attribute /* MaterialStream1._Cp_p[2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[11].info /* MaterialStream1._Cp_p[2] */.name, (modelica_real) data->localData[0]->realVars[11] /* MaterialStream1._Cp_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 330
 type: SIMPLE_ASSIGN
 MaterialStream1._Hvapg = MaterialStream1.xguess[1] * MaterialStream1.Hcompvg[1] + MaterialStream1.xguess[2] * MaterialStream1.Hcompvg[2]
 */
void Flowsheet_eqFunction_330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,330};
  data->simulationInfo->realParameter[618] = (data->simulationInfo->realParameter[643]) * (data->simulationInfo->realParameter[613]) + (data->simulationInfo->realParameter[644]) * (data->simulationInfo->realParameter[614]);
  TRACE_POP
}

/*
 equation index: 331
 type: SIMPLE_ASSIGN
 MaterialStream1._Htotg = MaterialStream1.Hliqg + MaterialStream1.Hvapg
 */
void Flowsheet_eqFunction_331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,331};
  data->simulationInfo->realParameter[617] = data->simulationInfo->realParameter[615] + data->simulationInfo->realParameter[618];
  TRACE_POP
}

/*
 equation index: 332
 type: SIMPLE_ASSIGN
 MaterialStream1._Hmixg = MaterialStream1.Htotg
 */
void Flowsheet_eqFunction_332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,332};
  data->simulationInfo->realParameter[616] = data->simulationInfo->realParameter[617];
  TRACE_POP
}

/*
 equation index: 333
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._H_p[1] = MaterialStream1.Hmixg
 */
void Flowsheet_eqFunction_333(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,333};
  data->modelData->realVarsData[40].attribute /* MaterialStream1._H_p[1] variable */.start = data->simulationInfo->realParameter[616];
    data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */ = data->modelData->realVarsData[40].attribute /* MaterialStream1._H_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[40].info /* MaterialStream1._H_p[1] */.name, (modelica_real) data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 334
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Cp_p[1] = MaterialStream1.Hmixg
 */
void Flowsheet_eqFunction_334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,334};
  data->modelData->realVarsData[10].attribute /* MaterialStream1._Cp_p[1] variable */.start = data->simulationInfo->realParameter[616];
    data->localData[0]->realVars[10] /* MaterialStream1._Cp_p[1] variable */ = data->modelData->realVarsData[10].attribute /* MaterialStream1._Cp_p[1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[10].info /* MaterialStream1._Cp_p[1] */.name, (modelica_real) data->localData[0]->realVars[10] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 335
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcompg[1] = MaterialStream1.xguess[1] * MaterialStream1.Htotg
 */
void Flowsheet_eqFunction_335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,335};
  data->simulationInfo->realParameter[609] = (data->simulationInfo->realParameter[643]) * (data->simulationInfo->realParameter[617]);
  TRACE_POP
}

/*
 equation index: 336
 type: SIMPLE_ASSIGN
 MaterialStream1._Hcompg[2] = MaterialStream1.xguess[2] * MaterialStream1.Htotg
 */
void Flowsheet_eqFunction_336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,336};
  data->simulationInfo->realParameter[610] = (data->simulationInfo->realParameter[644]) * (data->simulationInfo->realParameter[617]);
  TRACE_POP
}

/*
 equation index: 337
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._H_p[3] = MaterialStream1.Hvapg
 */
void Flowsheet_eqFunction_337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,337};
  data->modelData->realVarsData[42].attribute /* MaterialStream1._H_p[3] variable */.start = data->simulationInfo->realParameter[618];
    data->localData[0]->realVars[42] /* MaterialStream1._H_p[3] variable */ = data->modelData->realVarsData[42].attribute /* MaterialStream1._H_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[42].info /* MaterialStream1._H_p[3] */.name, (modelica_real) data->localData[0]->realVars[42] /* MaterialStream1._H_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 338
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Cp_p[3] = MaterialStream1.Hvapg
 */
void Flowsheet_eqFunction_338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,338};
  data->modelData->realVarsData[12].attribute /* MaterialStream1._Cp_p[3] variable */.start = data->simulationInfo->realParameter[618];
    data->localData[0]->realVars[12] /* MaterialStream1._Cp_p[3] variable */ = data->modelData->realVarsData[12].attribute /* MaterialStream1._Cp_p[3] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[12].info /* MaterialStream1._Cp_p[3] */.name, (modelica_real) data->localData[0]->realVars[12] /* MaterialStream1._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 339
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._xm_pc[1,1] = MaterialStream1.xguess[1]
 */
void Flowsheet_eqFunction_339(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,339};
  data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[1,1] variable */.start = data->simulationInfo->realParameter[643];
    data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[1,1] variable */ = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[92].info /* MaterialStream1._xm_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 340
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Pdew = MaterialStream1.Pmax
 */
void Flowsheet_eqFunction_340(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,340};
  data->modelData->realVarsData[59].attribute /* MaterialStream1._Pdew variable */.start = data->simulationInfo->realParameter[622];
    data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */ = data->modelData->realVarsData[59].attribute /* MaterialStream1._Pdew variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[59].info /* MaterialStream1._Pdew */.name, (modelica_real) data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
  TRACE_POP
}

/*
 equation index: 341
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._Pbubl = MaterialStream1.Pmin
 */
void Flowsheet_eqFunction_341(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,341};
  data->modelData->realVarsData[58].attribute /* MaterialStream1._Pbubl variable */.start = data->simulationInfo->realParameter[623];
    data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */ = data->modelData->realVarsData[58].attribute /* MaterialStream1._Pbubl variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[58].info /* MaterialStream1._Pbubl */.name, (modelica_real) data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  TRACE_POP
}

/*
 equation index: 342
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._T = MaterialStream1.Tg
 */
void Flowsheet_eqFunction_342(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,342};
  data->modelData->realVarsData[74].attribute /* MaterialStream1._T variable */.start = data->simulationInfo->realParameter[640];
    data->localData[0]->realVars[74] /* MaterialStream1._T variable */ = data->modelData->realVarsData[74].attribute /* MaterialStream1._T variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[74].info /* MaterialStream1._T */.name, (modelica_real) data->localData[0]->realVars[74] /* MaterialStream1._T variable */);
  TRACE_POP
}

/*
 equation index: 343
 type: SIMPLE_ASSIGN
 MaterialStream1._T = 350.0
 */
void Flowsheet_eqFunction_343(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,343};
  data->localData[0]->realVars[74] /* MaterialStream1._T variable */ = 350.0;
  TRACE_POP
}

/*
 equation index: 344
 type: SIMPLE_ASSIGN
 $START._Heater1._Tout = Heater1.Tg
 */
void Flowsheet_eqFunction_344(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,344};
  data->modelData->realVarsData[7].attribute /* Heater1._Tout variable */.start = data->simulationInfo->realParameter[433];
    data->localData[0]->realVars[7] /* Heater1._Tout variable */ = data->modelData->realVarsData[7].attribute /* Heater1._Tout variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[7].info /* Heater1._Tout */.name, (modelica_real) data->localData[0]->realVars[7] /* Heater1._Tout variable */);
  TRACE_POP
}

/*
 equation index: 345
 type: SIMPLE_ASSIGN
 Heater1._Tout = 380.0
 */
void Flowsheet_eqFunction_345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,345};
  data->localData[0]->realVars[7] /* Heater1._Tout variable */ = 380.0;
  TRACE_POP
}

/*
 equation index: 346
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[1,1] = MaterialStream1.xguess[1]
 */
void Flowsheet_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,346};
  data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[1,1] variable */.start = data->simulationInfo->realParameter[643];
    data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */ = data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[1,1] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[85].info /* MaterialStream1._x_pc[1,1] */.name, (modelica_real) data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 347
 type: SIMPLE_ASSIGN
 MaterialStream1._x_pc[1,1] = 0.5
 */
void Flowsheet_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,347};
  data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */ = 0.5;
  TRACE_POP
}

/*
 equation index: 348
 type: SIMPLE_ASSIGN
 MaterialStream2._x_pc[1,1] = MaterialStream1.x_pc[1,1]
 */
void Flowsheet_eqFunction_348(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,348};
  data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */ = data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */;
  TRACE_POP
}

/*
 equation index: 349
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[1,1] = 100.0 * MaterialStream2.x_pc[1,1]
 */
void Flowsheet_eqFunction_349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,349};
  data->localData[0]->realVars[114] /* MaterialStream2._F_pc[1,1] variable */ = (100.0) * (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 350
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[1,1] = MaterialStream2.F_pc[1,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,350};
  data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */ = (data->localData[0]->realVars[114] /* MaterialStream2._F_pc[1,1] variable */) * (data->simulationInfo->realParameter[739]);
  TRACE_POP
}

/*
 equation index: 351
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[1,1] = 100.0 * MaterialStream1.x_pc[1,1]
 */
void Flowsheet_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
  data->localData[0]->realVars[25] /* MaterialStream1._F_pc[1,1] variable */ = (100.0) * (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */);
  TRACE_POP
}

/*
 equation index: 352
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[1,1] = MaterialStream1.F_pc[1,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,352};
  data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */ = (data->localData[0]->realVars[25] /* MaterialStream1._F_pc[1,1] variable */) * (data->simulationInfo->realParameter[532]);
  TRACE_POP
}

/*
 equation index: 353
 type: SIMPLE_ASSIGN
 $START._MaterialStream1._x_pc[1,2] = MaterialStream1.xguess[2]
 */
void Flowsheet_eqFunction_353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,353};
  data->modelData->realVarsData[86].attribute /* MaterialStream1._x_pc[1,2] variable */.start = data->simulationInfo->realParameter[644];
    data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */ = data->modelData->realVarsData[86].attribute /* MaterialStream1._x_pc[1,2] variable */.start;
    infoStreamPrint(LOG_INIT, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[86].info /* MaterialStream1._x_pc[1,2] */.name, (modelica_real) data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 354
 type: SIMPLE_ASSIGN
 MaterialStream1._x_pc[1,2] = 0.5
 */
void Flowsheet_eqFunction_354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,354};
  data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */ = 0.5;
  TRACE_POP
}

/*
 equation index: 355
 type: SIMPLE_ASSIGN
 MaterialStream2._x_pc[1,2] = MaterialStream1.x_pc[1,2]
 */
void Flowsheet_eqFunction_355(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,355};
  data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */ = data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */;
  TRACE_POP
}

/*
 equation index: 356
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[1,2] = 100.0 * MaterialStream2.x_pc[1,2]
 */
void Flowsheet_eqFunction_356(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,356};
  data->localData[0]->realVars[115] /* MaterialStream2._F_pc[1,2] variable */ = (100.0) * (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 357
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[1,2] = MaterialStream2.F_pc[1,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_357(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,357};
  data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[1,2] variable */ = (data->localData[0]->realVars[115] /* MaterialStream2._F_pc[1,2] variable */) * (data->simulationInfo->realParameter[740]);
  TRACE_POP
}

/*
 equation index: 358
 type: SIMPLE_ASSIGN
 MaterialStream2._Pbubl = MaterialStream2.x_pc[1,1] * exp(MaterialStream2.C[1].VP[2] + MaterialStream2.C[1].VP[3] / 380.0 + MaterialStream2.C[1].VP[4] * 5.940171252720432 + MaterialStream2.C[1].VP[5] * 380.0 ^ MaterialStream2.C[1].VP[6]) + MaterialStream2.x_pc[1,2] * exp(MaterialStream2.C[2].VP[2] + MaterialStream2.C[2].VP[3] / 380.0 + MaterialStream2.C[2].VP[4] * 5.940171252720432 + MaterialStream2.C[2].VP[5] * 380.0 ^ MaterialStream2.C[2].VP[6])
 */
void Flowsheet_eqFunction_358(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,358};
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
  modelica_real tmp55;
  modelica_real tmp56;
  tmp41 = 380.0;
  if (tmp41 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.C[1].VP[3] / 380.0");}
  tmp42 = 380.0;
  tmp43 = data->simulationInfo->realParameter[768];
  if(tmp42 < 0.0 && tmp43 != 0.0)
  {
    tmp45 = modf(tmp43, &tmp46);
    
    if(tmp45 > 0.5)
    {
      tmp45 -= 1.0;
      tmp46 += 1.0;
    }
    else if(tmp45 < -0.5)
    {
      tmp45 += 1.0;
      tmp46 -= 1.0;
    }
    
    if(fabs(tmp45) < 1e-10)
      tmp44 = pow(tmp42, tmp46);
    else
    {
      tmp48 = modf(1.0/tmp43, &tmp47);
      if(tmp48 > 0.5)
      {
        tmp48 -= 1.0;
        tmp47 += 1.0;
      }
      else if(tmp48 < -0.5)
      {
        tmp48 += 1.0;
        tmp47 -= 1.0;
      }
      if(fabs(tmp48) < 1e-10 && ((unsigned long)tmp47 & 1))
      {
        tmp44 = -pow(-tmp42, tmp45)*pow(tmp42, tmp46);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp42, tmp43);
      }
    }
  }
  else
  {
    tmp44 = pow(tmp42, tmp43);
  }
  if(isnan(tmp44) || isinf(tmp44))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp42, tmp43);
  }tmp49 = 380.0;
  if (tmp49 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.C[2].VP[3] / 380.0");}
  tmp50 = 380.0;
  tmp51 = data->simulationInfo->realParameter[774];
  if(tmp50 < 0.0 && tmp51 != 0.0)
  {
    tmp53 = modf(tmp51, &tmp54);
    
    if(tmp53 > 0.5)
    {
      tmp53 -= 1.0;
      tmp54 += 1.0;
    }
    else if(tmp53 < -0.5)
    {
      tmp53 += 1.0;
      tmp54 -= 1.0;
    }
    
    if(fabs(tmp53) < 1e-10)
      tmp52 = pow(tmp50, tmp54);
    else
    {
      tmp56 = modf(1.0/tmp51, &tmp55);
      if(tmp56 > 0.5)
      {
        tmp56 -= 1.0;
        tmp55 += 1.0;
      }
      else if(tmp56 < -0.5)
      {
        tmp56 += 1.0;
        tmp55 -= 1.0;
      }
      if(fabs(tmp56) < 1e-10 && ((unsigned long)tmp55 & 1))
      {
        tmp52 = -pow(-tmp50, tmp53)*pow(tmp50, tmp54);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp50, tmp51);
      }
    }
  }
  else
  {
    tmp52 = pow(tmp50, tmp51);
  }
  if(isnan(tmp52) || isinf(tmp52))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp50, tmp51);
  }
  data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (exp(data->simulationInfo->realParameter[764] + (data->simulationInfo->realParameter[765]) / tmp41 + (data->simulationInfo->realParameter[766]) * (5.940171252720432) + (data->simulationInfo->realParameter[767]) * (tmp44))) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (exp(data->simulationInfo->realParameter[770] + (data->simulationInfo->realParameter[771]) / tmp49 + (data->simulationInfo->realParameter[772]) * (5.940171252720432) + (data->simulationInfo->realParameter[773]) * (tmp52)));
  TRACE_POP
}

/*
 equation index: 359
 type: SIMPLE_ASSIGN
 MaterialStream2._Pdew = DIVISION(1.0, MaterialStream2.x_pc[1,1] * exp((-MaterialStream2.C[1].VP[2]) - MaterialStream2.C[1].VP[3] / 380.0 - MaterialStream2.C[1].VP[4] * 5.940171252720432 - MaterialStream2.C[1].VP[5] * 380.0 ^ MaterialStream2.C[1].VP[6]) + MaterialStream2.x_pc[1,2] * exp((-MaterialStream2.C[2].VP[2]) - MaterialStream2.C[2].VP[3] / 380.0 - MaterialStream2.C[2].VP[4] * 5.940171252720432 - MaterialStream2.C[2].VP[5] * 380.0 ^ MaterialStream2.C[2].VP[6]))
 */
void Flowsheet_eqFunction_359(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,359};
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
  modelica_real tmp69;
  modelica_real tmp70;
  modelica_real tmp71;
  modelica_real tmp72;
  tmp57 = 380.0;
  if (tmp57 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.C[1].VP[3] / 380.0");}
  tmp58 = 380.0;
  tmp59 = data->simulationInfo->realParameter[768];
  if(tmp58 < 0.0 && tmp59 != 0.0)
  {
    tmp61 = modf(tmp59, &tmp62);
    
    if(tmp61 > 0.5)
    {
      tmp61 -= 1.0;
      tmp62 += 1.0;
    }
    else if(tmp61 < -0.5)
    {
      tmp61 += 1.0;
      tmp62 -= 1.0;
    }
    
    if(fabs(tmp61) < 1e-10)
      tmp60 = pow(tmp58, tmp62);
    else
    {
      tmp64 = modf(1.0/tmp59, &tmp63);
      if(tmp64 > 0.5)
      {
        tmp64 -= 1.0;
        tmp63 += 1.0;
      }
      else if(tmp64 < -0.5)
      {
        tmp64 += 1.0;
        tmp63 -= 1.0;
      }
      if(fabs(tmp64) < 1e-10 && ((unsigned long)tmp63 & 1))
      {
        tmp60 = -pow(-tmp58, tmp61)*pow(tmp58, tmp62);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp58, tmp59);
      }
    }
  }
  else
  {
    tmp60 = pow(tmp58, tmp59);
  }
  if(isnan(tmp60) || isinf(tmp60))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp58, tmp59);
  }tmp65 = 380.0;
  if (tmp65 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream2.C[2].VP[3] / 380.0");}
  tmp66 = 380.0;
  tmp67 = data->simulationInfo->realParameter[774];
  if(tmp66 < 0.0 && tmp67 != 0.0)
  {
    tmp69 = modf(tmp67, &tmp70);
    
    if(tmp69 > 0.5)
    {
      tmp69 -= 1.0;
      tmp70 += 1.0;
    }
    else if(tmp69 < -0.5)
    {
      tmp69 += 1.0;
      tmp70 -= 1.0;
    }
    
    if(fabs(tmp69) < 1e-10)
      tmp68 = pow(tmp66, tmp70);
    else
    {
      tmp72 = modf(1.0/tmp67, &tmp71);
      if(tmp72 > 0.5)
      {
        tmp72 -= 1.0;
        tmp71 += 1.0;
      }
      else if(tmp72 < -0.5)
      {
        tmp72 += 1.0;
        tmp71 -= 1.0;
      }
      if(fabs(tmp72) < 1e-10 && ((unsigned long)tmp71 & 1))
      {
        tmp68 = -pow(-tmp66, tmp69)*pow(tmp66, tmp70);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp66, tmp67);
      }
    }
  }
  else
  {
    tmp68 = pow(tmp66, tmp67);
  }
  if(isnan(tmp68) || isinf(tmp68))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp66, tmp67);
  }
  data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */ = DIVISION_SIM(1.0,(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (exp((-data->simulationInfo->realParameter[764]) - ((data->simulationInfo->realParameter[765]) / tmp57) - ((data->simulationInfo->realParameter[766]) * (5.940171252720432)) - ((data->simulationInfo->realParameter[767]) * (tmp60)))) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (exp((-data->simulationInfo->realParameter[770]) - ((data->simulationInfo->realParameter[771]) / tmp65) - ((data->simulationInfo->realParameter[772]) * (5.940171252720432)) - ((data->simulationInfo->realParameter[773]) * (tmp68)))),"MaterialStream2.x_pc[1,1] * exp((-MaterialStream2.C[1].VP[2]) - MaterialStream2.C[1].VP[3] / 380.0 - MaterialStream2.C[1].VP[4] * 5.940171252720432 - MaterialStream2.C[1].VP[5] * 380.0 ^ MaterialStream2.C[1].VP[6]) + MaterialStream2.x_pc[1,2] * exp((-MaterialStream2.C[2].VP[2]) - MaterialStream2.C[2].VP[3] / 380.0 - MaterialStream2.C[2].VP[4] * 5.940171252720432 - MaterialStream2.C[2].VP[5] * 380.0 ^ MaterialStream2.C[2].VP[6])",equationIndexes);
  TRACE_POP
}

void Flowsheet_eqFunction_360(DATA*,threadData_t*);
void Flowsheet_eqFunction_361(DATA*,threadData_t*);
void Flowsheet_eqFunction_362(DATA*,threadData_t*);
void Flowsheet_eqFunction_367(DATA*,threadData_t*);
void Flowsheet_eqFunction_366(DATA*,threadData_t*);
void Flowsheet_eqFunction_365(DATA*,threadData_t*);
void Flowsheet_eqFunction_364(DATA*,threadData_t*);
void Flowsheet_eqFunction_363(DATA*,threadData_t*);
/*
 equation index: 376
 indexNonlinear: 6
 type: NONLINEAR
 
 vars: {MaterialStream2._xliq, MaterialStream2._x_pc[2,2], MaterialStream2._x_pc[2,1], MaterialStream2._x_pc[3,1], MaterialStream2._x_pc[3,2]}
 eqns: {360, 361, 362, 367, 366, 365, 364, 363}
 */
void Flowsheet_eqFunction_376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,376};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 376 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[6].nlsxOld[0] = data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */;
  data->simulationInfo->nonlinearSystemData[6].nlsxOld[1] = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */;
  data->simulationInfo->nonlinearSystemData[6].nlsxOld[2] = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[6].nlsxOld[3] = data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */;
  data->simulationInfo->nonlinearSystemData[6].nlsxOld[4] = data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */;
  retValue = solve_nonlinear_system(data, threadData, 6);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,376};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 376 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */ = data->simulationInfo->nonlinearSystemData[6].nlsx[0];
  data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[6].nlsx[1];
  data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[6].nlsx[2];
  data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[6].nlsx[3];
  data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[6].nlsx[4];
  TRACE_POP
}

/*
 equation index: 377
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.Cp_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_377(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,377};
  data->localData[0]->realVars[101] /* MaterialStream2._Cp_p[2] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[105] /* MaterialStream2._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[106] /* MaterialStream2._Cp_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 378
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.H_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.H_pc[2,2]
 */
void Flowsheet_eqFunction_378(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,378};
  data->localData[0]->realVars[130] /* MaterialStream2._H_p[2] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[134] /* MaterialStream2._H_pc[2,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[135] /* MaterialStream2._H_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 379
 type: ALGORITHM
 
   (MaterialStream2.S_pc[2,1], MaterialStream2.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tb, MaterialStream2.C[1].Tc, 380.0, Heater1.Pout, MaterialStream2.x_pc[2,1], MaterialStream2.x_pc[3,1]);
 */
void Flowsheet_eqFunction_379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,379};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778], (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678], (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680]);
  data->localData[0]->realVars[155] /* MaterialStream2._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp0, tmp1, data->simulationInfo->realParameter[753], data->simulationInfo->realParameter[755], 380.0, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */, data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ ,&data->localData[0]->realVars[157] /* MaterialStream2._S_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 380
 type: ALGORITHM
 
   (MaterialStream2.S_pc[2,2], MaterialStream2.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tb, MaterialStream2.C[2].Tc, 380.0, Heater1.Pout, MaterialStream2.x_pc[2,2], MaterialStream2.x_pc[3,2]);
 */
void Flowsheet_eqFunction_380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,380};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784], (modelica_real)data->simulationInfo->realParameter[785], (modelica_real)data->simulationInfo->realParameter[786]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684], (modelica_real)data->simulationInfo->realParameter[685], (modelica_real)data->simulationInfo->realParameter[686]);
  data->localData[0]->realVars[156] /* MaterialStream2._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp2, tmp3, data->simulationInfo->realParameter[754], data->simulationInfo->realParameter[756], 380.0, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */, data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ ,&data->localData[0]->realVars[158] /* MaterialStream2._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 381
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.S_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.S_pc[2,2]
 */
void Flowsheet_eqFunction_381(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,381};
  data->localData[0]->realVars[151] /* MaterialStream2._S_p[2] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[155] /* MaterialStream2._S_pc[2,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[156] /* MaterialStream2._S_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 382
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.Cp_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_382(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,382};
  data->localData[0]->realVars[102] /* MaterialStream2._Cp_p[3] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[107] /* MaterialStream2._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[108] /* MaterialStream2._Cp_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 383
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.H_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.H_pc[3,2]
 */
void Flowsheet_eqFunction_383(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,383};
  data->localData[0]->realVars[131] /* MaterialStream2._H_p[3] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[136] /* MaterialStream2._H_pc[3,1] variable */) + (data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[137] /* MaterialStream2._H_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 384
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.S_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.S_pc[3,2]
 */
void Flowsheet_eqFunction_384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,384};
  data->localData[0]->realVars[152] /* MaterialStream2._S_p[3] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[157] /* MaterialStream2._S_pc[3,1] variable */) + (data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[158] /* MaterialStream2._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 385
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[2,1] = MaterialStream2.x_pc[2,1] * MaterialStream2.F_p[2]
 */
void Flowsheet_eqFunction_385(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,385};
  data->localData[0]->realVars[116] /* MaterialStream2._F_pc[2,1] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 386
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[2,1] = MaterialStream2.F_pc[2,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_386(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,386};
  data->localData[0]->realVars[125] /* MaterialStream2._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[116] /* MaterialStream2._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[739]);
  TRACE_POP
}

/*
 equation index: 387
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[2,2] = MaterialStream2.x_pc[2,2] * MaterialStream2.F_p[2]
 */
void Flowsheet_eqFunction_387(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,387};
  data->localData[0]->realVars[117] /* MaterialStream2._F_pc[2,2] variable */ = (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 388
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[2,2] = MaterialStream2.F_pc[2,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_388(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,388};
  data->localData[0]->realVars[126] /* MaterialStream2._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[117] /* MaterialStream2._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[740]);
  TRACE_POP
}

/*
 equation index: 389
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[3,1] = MaterialStream2.x_pc[3,1] * MaterialStream2.F_p[3]
 */
void Flowsheet_eqFunction_389(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,389};
  data->localData[0]->realVars[118] /* MaterialStream2._F_pc[3,1] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 390
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[3,1] = MaterialStream2.F_pc[3,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_390(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,390};
  data->localData[0]->realVars[127] /* MaterialStream2._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[118] /* MaterialStream2._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[739]);
  TRACE_POP
}

/*
 equation index: 391
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[3,2] = MaterialStream2.x_pc[3,2] * MaterialStream2.F_p[3]
 */
void Flowsheet_eqFunction_391(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,391};
  data->localData[0]->realVars[119] /* MaterialStream2._F_pc[3,2] variable */ = (data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 392
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[3,2] = MaterialStream2.F_pc[3,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_392(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,392};
  data->localData[0]->realVars[128] /* MaterialStream2._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[119] /* MaterialStream2._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[740]);
  TRACE_POP
}

/*
 equation index: 393
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[1] = MaterialStream2.xliq * MaterialStream2.Cp_p[2] + Heater1.xvapout * MaterialStream2.Cp_p[3]
 */
void Flowsheet_eqFunction_393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,393};
  data->localData[0]->realVars[100] /* MaterialStream2._Cp_p[1] variable */ = (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[101] /* MaterialStream2._Cp_p[2] variable */) + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (data->localData[0]->realVars[102] /* MaterialStream2._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 394
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.Cp_p[1]
 */
void Flowsheet_eqFunction_394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,394};
  data->localData[0]->realVars[103] /* MaterialStream2._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[100] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 395
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.Cp_p[1]
 */
void Flowsheet_eqFunction_395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,395};
  data->localData[0]->realVars[104] /* MaterialStream2._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[100] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 396
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[1] = MaterialStream2.xliq * MaterialStream2.H_p[2] + Heater1.xvapout * MaterialStream2.H_p[3]
 */
void Flowsheet_eqFunction_396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,396};
  data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */ = (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[130] /* MaterialStream2._H_p[2] variable */) + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (data->localData[0]->realVars[131] /* MaterialStream2._H_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 397
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.H_p[1]
 */
void Flowsheet_eqFunction_397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,397};
  data->localData[0]->realVars[132] /* MaterialStream2._H_pc[1,1] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 398
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.H_p[1]
 */
void Flowsheet_eqFunction_398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,398};
  data->localData[0]->realVars[133] /* MaterialStream2._H_pc[1,2] variable */ = (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 399
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[1] = MaterialStream2.xliq * MaterialStream2.S_p[2] + Heater1.xvapout * MaterialStream2.S_p[3]
 */
void Flowsheet_eqFunction_399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,399};
  data->localData[0]->realVars[150] /* MaterialStream2._S_p[1] variable */ = (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[151] /* MaterialStream2._S_p[2] variable */) + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (data->localData[0]->realVars[152] /* MaterialStream2._S_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 400
 type: SIMPLE_ASSIGN
 MaterialStream2._S_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.S_p[1]
 */
void Flowsheet_eqFunction_400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,400};
  data->localData[0]->realVars[153] /* MaterialStream2._S_pc[1,1] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[150] /* MaterialStream2._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 401
 type: SIMPLE_ASSIGN
 MaterialStream2._S_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.S_p[1]
 */
void Flowsheet_eqFunction_401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,401};
  data->localData[0]->realVars[154] /* MaterialStream2._S_pc[1,2] variable */ = (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[150] /* MaterialStream2._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 402
 type: ALGORITHM
 
   for i in 1:2 loop
     MaterialStream2.MW_p[:] := {MaterialStream2.MW_p[1] + MaterialStream2.x_pc[1,i] * MaterialStream2.C[i].MW, MaterialStream2.MW_p[2] + MaterialStream2.x_pc[2,i] * MaterialStream2.C[i].MW, MaterialStream2.MW_p[3] + MaterialStream2.x_pc[3,i] * MaterialStream2.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,402};
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
      array_alloc_scalar_real_array(&tmp4, 3, (modelica_real)data->localData[0]->realVars[143] /* MaterialStream2._MW_p[1] variable */ + ((&data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[739])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[144] /* MaterialStream2._MW_p[2] variable */ + ((&data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[739])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[145] /* MaterialStream2._MW_p[3] variable */ + ((&data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[739])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp5, 1, (1), (int*)0, 'W');
      real_array_create(&tmp6, (modelica_real*)&data->localData[0]->realVars[143] /* MaterialStream2._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp4, &tmp6, &tmp5);
    }
  }
  TRACE_POP
}

/*
 equation index: 403
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[3] = MaterialStream2.F_p[3] * MaterialStream2.MW_p[3]
 */
void Flowsheet_eqFunction_403(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,403};
  data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */ = (data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */) * (data->localData[0]->realVars[145] /* MaterialStream2._MW_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 404
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[1] = 100.0 * MaterialStream2.MW_p[1]
 */
void Flowsheet_eqFunction_404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,404};
  data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */ = (100.0) * (data->localData[0]->realVars[143] /* MaterialStream2._MW_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 405
 type: SIMPLE_ASSIGN
 MaterialStream2._xm_pc[1,2] = DIVISION(MaterialStream2.Fm_pc[1,2], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_405(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,405};
  data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[1,2] variable */,data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 406
 type: SIMPLE_ASSIGN
 MaterialStream2._xmvap = DIVISION(MaterialStream2.Fm_p[3], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,406};
  data->localData[0]->realVars[186] /* MaterialStream2._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */,data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 407
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[2] = MaterialStream2.F_p[2] * MaterialStream2.MW_p[2]
 */
void Flowsheet_eqFunction_407(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,407};
  data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */ = (data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */) * (data->localData[0]->realVars[144] /* MaterialStream2._MW_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 408
 type: LINEAR
 
 <var>MaterialStream2._xm_pc[3,2]</var>
 <var>MaterialStream2._xm_pc[2,2]</var>
 <var>MaterialStream2._xm_pc[1,1]</var>
 <var>MaterialStream2._xm_pc[3,1]</var>
 <var>MaterialStream2._xm_pc[2,1]</var>
 <row>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[2,1] else 0.0</cell>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[1,1] else 0.0</cell>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2.Fm_pc[1,1] else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[3,1] else MaterialStream2.Fm_pc[1,1]</cell>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[2,2] else 0.0</cell>
   <cell>if Heater1.Pout >= MaterialStream2.Pbubl then -MaterialStream2.xm_pc[1,2] else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[3,2] else -MaterialStream2.xm_pc[1,2]</cell>
 </row>
 <matrix>
   <cell row="0" col="0">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="0" col="1">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[2] else 0.0)</residual>
   </cell><cell row="1" col="2">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[1] else 0.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then -MaterialStream2.Fm_p[1] else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else -MaterialStream2.Fm_p[1])</residual>
   </cell><cell row="2" col="3">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then -0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[3] else -0.0)</residual>
   </cell><cell row="3" col="1">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[2] else 0.0)</residual>
   </cell><cell row="3" col="2">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then -1.0 else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="3" col="3">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="3" col="4">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 0.0 else if Heater1.Pout >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[3] else 1.0)</residual>
   </cell><cell row="4" col="1">
     <residual>-(if Heater1.Pout >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_408(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,408};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 408 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[3].x[0] = data->localData[1]->realVars[184] /* MaterialStream2._xm_pc[3,2] variable */;
  data->simulationInfo->linearSystemData[3].x[1] = data->localData[1]->realVars[182] /* MaterialStream2._xm_pc[2,2] variable */;
  data->simulationInfo->linearSystemData[3].x[2] = data->localData[1]->realVars[179] /* MaterialStream2._xm_pc[1,1] variable */;
  data->simulationInfo->linearSystemData[3].x[3] = data->localData[1]->realVars[183] /* MaterialStream2._xm_pc[3,1] variable */;
  data->simulationInfo->linearSystemData[3].x[4] = data->localData[1]->realVars[181] /* MaterialStream2._xm_pc[2,1] variable */;
  retValue = solve_linear_system(data, threadData, 3);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,408};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 408 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[184] /* MaterialStream2._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[3].x[0];
  data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[3].x[1];
  data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[3].x[2];
  data->localData[0]->realVars[183] /* MaterialStream2._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[3].x[3];
  data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[3].x[4];
  TRACE_POP
}

/*
 equation index: 409
 type: SIMPLE_ASSIGN
 MaterialStream2._xmliq = DIVISION(MaterialStream2.Fm_p[2], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_409(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,409};
  data->localData[0]->realVars[185] /* MaterialStream2._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */,data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 410
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[1,2] = 100.0 * MaterialStream1.x_pc[1,2]
 */
void Flowsheet_eqFunction_410(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,410};
  data->localData[0]->realVars[26] /* MaterialStream1._F_pc[1,2] variable */ = (100.0) * (data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */);
  TRACE_POP
}

/*
 equation index: 411
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[1,2] = MaterialStream1.F_pc[1,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_411(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,411};
  data->localData[0]->realVars[35] /* MaterialStream1._Fm_pc[1,2] variable */ = (data->localData[0]->realVars[26] /* MaterialStream1._F_pc[1,2] variable */) * (data->simulationInfo->realParameter[533]);
  TRACE_POP
}

/*
 equation index: 412
 type: SIMPLE_ASSIGN
 MaterialStream1._Pbubl = MaterialStream1.x_pc[1,1] * exp(MaterialStream1.C[1].VP[2] + MaterialStream1.C[1].VP[3] / 350.0 + MaterialStream1.C[1].VP[4] * 5.857933154483459 + MaterialStream1.C[1].VP[5] * 350.0 ^ MaterialStream1.C[1].VP[6]) + MaterialStream1.x_pc[1,2] * exp(MaterialStream1.C[2].VP[2] + MaterialStream1.C[2].VP[3] / 350.0 + MaterialStream1.C[2].VP[4] * 5.857933154483459 + MaterialStream1.C[2].VP[5] * 350.0 ^ MaterialStream1.C[2].VP[6])
 */
void Flowsheet_eqFunction_412(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,412};
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
  tmp10 = 350.0;
  if (tmp10 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.C[1].VP[3] / 350.0");}
  tmp11 = 350.0;
  tmp12 = data->simulationInfo->realParameter[561];
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
  }tmp18 = 350.0;
  if (tmp18 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.C[2].VP[3] / 350.0");}
  tmp19 = 350.0;
  tmp20 = data->simulationInfo->realParameter[567];
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
  data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */ = (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (exp(data->simulationInfo->realParameter[557] + (data->simulationInfo->realParameter[558]) / tmp10 + (data->simulationInfo->realParameter[559]) * (5.857933154483459) + (data->simulationInfo->realParameter[560]) * (tmp13))) + (data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (exp(data->simulationInfo->realParameter[563] + (data->simulationInfo->realParameter[564]) / tmp18 + (data->simulationInfo->realParameter[565]) * (5.857933154483459) + (data->simulationInfo->realParameter[566]) * (tmp21)));
  TRACE_POP
}

/*
 equation index: 413
 type: SIMPLE_ASSIGN
 MaterialStream1._Pdew = DIVISION(1.0, MaterialStream1.x_pc[1,1] * exp((-MaterialStream1.C[1].VP[2]) - MaterialStream1.C[1].VP[3] / 350.0 - MaterialStream1.C[1].VP[4] * 5.857933154483459 - MaterialStream1.C[1].VP[5] * 350.0 ^ MaterialStream1.C[1].VP[6]) + MaterialStream1.x_pc[1,2] * exp((-MaterialStream1.C[2].VP[2]) - MaterialStream1.C[2].VP[3] / 350.0 - MaterialStream1.C[2].VP[4] * 5.857933154483459 - MaterialStream1.C[2].VP[5] * 350.0 ^ MaterialStream1.C[2].VP[6]))
 */
void Flowsheet_eqFunction_413(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,413};
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
  tmp26 = 350.0;
  if (tmp26 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.C[1].VP[3] / 350.0");}
  tmp27 = 350.0;
  tmp28 = data->simulationInfo->realParameter[561];
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
  }tmp34 = 350.0;
  if (tmp34 == 0) {throwStreamPrint(threadData, "Division by zero %s", "MaterialStream1.C[2].VP[3] / 350.0");}
  tmp35 = 350.0;
  tmp36 = data->simulationInfo->realParameter[567];
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
  data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */ = DIVISION_SIM(1.0,(data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (exp((-data->simulationInfo->realParameter[557]) - ((data->simulationInfo->realParameter[558]) / tmp26) - ((data->simulationInfo->realParameter[559]) * (5.857933154483459)) - ((data->simulationInfo->realParameter[560]) * (tmp29)))) + (data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (exp((-data->simulationInfo->realParameter[563]) - ((data->simulationInfo->realParameter[564]) / tmp34) - ((data->simulationInfo->realParameter[565]) * (5.857933154483459)) - ((data->simulationInfo->realParameter[566]) * (tmp37)))),"MaterialStream1.x_pc[1,1] * exp((-MaterialStream1.C[1].VP[2]) - MaterialStream1.C[1].VP[3] / 350.0 - MaterialStream1.C[1].VP[4] * 5.857933154483459 - MaterialStream1.C[1].VP[5] * 350.0 ^ MaterialStream1.C[1].VP[6]) + MaterialStream1.x_pc[1,2] * exp((-MaterialStream1.C[2].VP[2]) - MaterialStream1.C[2].VP[3] / 350.0 - MaterialStream1.C[2].VP[4] * 5.857933154483459 - MaterialStream1.C[2].VP[5] * 350.0 ^ MaterialStream1.C[2].VP[6])",equationIndexes);
  TRACE_POP
}

void Flowsheet_eqFunction_414(DATA*,threadData_t*);
void Flowsheet_eqFunction_415(DATA*,threadData_t*);
void Flowsheet_eqFunction_416(DATA*,threadData_t*);
void Flowsheet_eqFunction_421(DATA*,threadData_t*);
void Flowsheet_eqFunction_420(DATA*,threadData_t*);
void Flowsheet_eqFunction_419(DATA*,threadData_t*);
void Flowsheet_eqFunction_418(DATA*,threadData_t*);
void Flowsheet_eqFunction_417(DATA*,threadData_t*);
/*
 equation index: 430
 indexNonlinear: 7
 type: NONLINEAR
 
 vars: {MaterialStream1._xliq, MaterialStream1._x_pc[2,1], MaterialStream1._x_pc[3,2], MaterialStream1._x_pc[2,2], MaterialStream1._x_pc[3,1]}
 eqns: {414, 415, 416, 421, 420, 419, 418, 417}
 */
void Flowsheet_eqFunction_430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,430};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 430 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[7].nlsxOld[0] = data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */;
  data->simulationInfo->nonlinearSystemData[7].nlsxOld[1] = data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[7].nlsxOld[2] = data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */;
  data->simulationInfo->nonlinearSystemData[7].nlsxOld[3] = data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */;
  data->simulationInfo->nonlinearSystemData[7].nlsxOld[4] = data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */;
  retValue = solve_nonlinear_system(data, threadData, 7);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,430};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 430 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */ = data->simulationInfo->nonlinearSystemData[7].nlsx[0];
  data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[7].nlsx[1];
  data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[7].nlsx[2];
  data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[7].nlsx[3];
  data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[7].nlsx[4];
  TRACE_POP
}

/*
 equation index: 431
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[2,1] = MaterialStream1.x_pc[2,1] * MaterialStream1.F_p[2]
 */
void Flowsheet_eqFunction_431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,431};
  data->localData[0]->realVars[27] /* MaterialStream1._F_pc[2,1] variable */ = (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 432
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[2,1] = MaterialStream1.F_pc[2,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,432};
  data->localData[0]->realVars[36] /* MaterialStream1._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[27] /* MaterialStream1._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[532]);
  TRACE_POP
}

/*
 equation index: 433
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[3,2] = MaterialStream1.x_pc[3,2] * MaterialStream1.F_p[3]
 */
void Flowsheet_eqFunction_433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,433};
  data->localData[0]->realVars[30] /* MaterialStream1._F_pc[3,2] variable */ = (data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 434
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[3,2] = MaterialStream1.F_pc[3,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,434};
  data->localData[0]->realVars[39] /* MaterialStream1._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[30] /* MaterialStream1._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[533]);
  TRACE_POP
}

/*
 equation index: 435
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[2,2] = MaterialStream1.x_pc[2,2] * MaterialStream1.F_p[2]
 */
void Flowsheet_eqFunction_435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,435};
  data->localData[0]->realVars[28] /* MaterialStream1._F_pc[2,2] variable */ = (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 436
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[2,2] = MaterialStream1.F_pc[2,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_436(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,436};
  data->localData[0]->realVars[37] /* MaterialStream1._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[28] /* MaterialStream1._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[533]);
  TRACE_POP
}

/*
 equation index: 437
 type: ALGORITHM
 
   (MaterialStream1.S_pc[2,2], MaterialStream1.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tb, MaterialStream1.C[2].Tc, 350.0, 101325.0, MaterialStream1.x_pc[2,2], MaterialStream1.x_pc[3,2]);
 */
void Flowsheet_eqFunction_437(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,437};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577], (modelica_real)data->simulationInfo->realParameter[578], (modelica_real)data->simulationInfo->realParameter[579]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477], (modelica_real)data->simulationInfo->realParameter[478], (modelica_real)data->simulationInfo->realParameter[479]);
  data->localData[0]->realVars[68] /* MaterialStream1._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp0, tmp1, data->simulationInfo->realParameter[547], data->simulationInfo->realParameter[549], 350.0, 101325.0, data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */, data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ ,&data->localData[0]->realVars[70] /* MaterialStream1._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 438
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.Cp_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_438(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,438};
  data->localData[0]->realVars[11] /* MaterialStream1._Cp_p[2] variable */ = (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[15] /* MaterialStream1._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[16] /* MaterialStream1._Cp_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 439
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.H_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.H_pc[2,2]
 */
void Flowsheet_eqFunction_439(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,439};
  data->localData[0]->realVars[41] /* MaterialStream1._H_p[2] variable */ = (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[45] /* MaterialStream1._H_pc[2,1] variable */) + (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[46] /* MaterialStream1._H_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 440
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[3,1] = MaterialStream1.x_pc[3,1] * MaterialStream1.F_p[3]
 */
void Flowsheet_eqFunction_440(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,440};
  data->localData[0]->realVars[29] /* MaterialStream1._F_pc[3,1] variable */ = (data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 441
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[3,1] = MaterialStream1.F_pc[3,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_441(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,441};
  data->localData[0]->realVars[38] /* MaterialStream1._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[29] /* MaterialStream1._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[532]);
  TRACE_POP
}

/*
 equation index: 442
 type: ALGORITHM
 
   (MaterialStream1.S_pc[2,1], MaterialStream1.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tb, MaterialStream1.C[1].Tc, 350.0, 101325.0, MaterialStream1.x_pc[2,1], MaterialStream1.x_pc[3,1]);
 */
void Flowsheet_eqFunction_442(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,442};
  real_array tmp2;
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571], (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573]);
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471], (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473]);
  data->localData[0]->realVars[67] /* MaterialStream1._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp2, tmp3, data->simulationInfo->realParameter[546], data->simulationInfo->realParameter[548], 350.0, 101325.0, data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */, data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ ,&data->localData[0]->realVars[69] /* MaterialStream1._S_pc[3,1] variable */);
  TRACE_POP
}

/*
 equation index: 443
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.S_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.S_pc[2,2]
 */
void Flowsheet_eqFunction_443(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,443};
  data->localData[0]->realVars[63] /* MaterialStream1._S_p[2] variable */ = (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[67] /* MaterialStream1._S_pc[2,1] variable */) + (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[68] /* MaterialStream1._S_pc[2,2] variable */);
  TRACE_POP
}

/*
 equation index: 444
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.Cp_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_444(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,444};
  data->localData[0]->realVars[12] /* MaterialStream1._Cp_p[3] variable */ = (data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[17] /* MaterialStream1._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[18] /* MaterialStream1._Cp_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 445
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.H_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.H_pc[3,2]
 */
void Flowsheet_eqFunction_445(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,445};
  data->localData[0]->realVars[42] /* MaterialStream1._H_p[3] variable */ = (data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[47] /* MaterialStream1._H_pc[3,1] variable */) + (data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[48] /* MaterialStream1._H_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 446
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.S_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.S_pc[3,2]
 */
void Flowsheet_eqFunction_446(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,446};
  data->localData[0]->realVars[64] /* MaterialStream1._S_p[3] variable */ = (data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[69] /* MaterialStream1._S_pc[3,1] variable */) + (data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[70] /* MaterialStream1._S_pc[3,2] variable */);
  TRACE_POP
}

/*
 equation index: 447
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[1] = MaterialStream1.xliq * MaterialStream1.Cp_p[2] + Heater1.xvapin * MaterialStream1.Cp_p[3]
 */
void Flowsheet_eqFunction_447(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,447};
  data->localData[0]->realVars[10] /* MaterialStream1._Cp_p[1] variable */ = (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[11] /* MaterialStream1._Cp_p[2] variable */) + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (data->localData[0]->realVars[12] /* MaterialStream1._Cp_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 448
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.Cp_p[1]
 */
void Flowsheet_eqFunction_448(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,448};
  data->localData[0]->realVars[13] /* MaterialStream1._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[10] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 449
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.Cp_p[1]
 */
void Flowsheet_eqFunction_449(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,449};
  data->localData[0]->realVars[14] /* MaterialStream1._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[10] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 450
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[1] = MaterialStream1.xliq * MaterialStream1.H_p[2] + Heater1.xvapin * MaterialStream1.H_p[3]
 */
void Flowsheet_eqFunction_450(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,450};
  data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */ = (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[41] /* MaterialStream1._H_p[2] variable */) + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (data->localData[0]->realVars[42] /* MaterialStream1._H_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 451
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.H_p[1]
 */
void Flowsheet_eqFunction_451(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,451};
  data->localData[0]->realVars[43] /* MaterialStream1._H_pc[1,1] variable */ = (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 452
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.H_p[1]
 */
void Flowsheet_eqFunction_452(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,452};
  data->localData[0]->realVars[44] /* MaterialStream1._H_pc[1,2] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 453
 type: SIMPLE_ASSIGN
 Heater1._Q = DIVISION(100.0 * (MaterialStream2.H_p[1] - MaterialStream1.H_p[1]), Heater1.Eff)
 */
void Flowsheet_eqFunction_453(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,453};
  data->localData[0]->realVars[5] /* Heater1._Q variable */ = DIVISION_SIM((100.0) * (data->localData[0]->realVars[129] /* MaterialStream2._H_p[1] variable */ - data->localData[0]->realVars[40] /* MaterialStream1._H_p[1] variable */),data->simulationInfo->realParameter[397],"Heater1.Eff",equationIndexes);
  TRACE_POP
}

/*
 equation index: 454
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[1] = MaterialStream1.xliq * MaterialStream1.S_p[2] + Heater1.xvapin * MaterialStream1.S_p[3]
 */
void Flowsheet_eqFunction_454(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,454};
  data->localData[0]->realVars[62] /* MaterialStream1._S_p[1] variable */ = (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[63] /* MaterialStream1._S_p[2] variable */) + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (data->localData[0]->realVars[64] /* MaterialStream1._S_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 455
 type: SIMPLE_ASSIGN
 MaterialStream1._S_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.S_p[1]
 */
void Flowsheet_eqFunction_455(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,455};
  data->localData[0]->realVars[65] /* MaterialStream1._S_pc[1,1] variable */ = (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[62] /* MaterialStream1._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 456
 type: SIMPLE_ASSIGN
 MaterialStream1._S_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.S_p[1]
 */
void Flowsheet_eqFunction_456(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,456};
  data->localData[0]->realVars[66] /* MaterialStream1._S_pc[1,2] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[62] /* MaterialStream1._S_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 457
 type: ALGORITHM
 
   for i in 1:2 loop
     MaterialStream1.MW_p[:] := {MaterialStream1.MW_p[1] + MaterialStream1.x_pc[1,i] * MaterialStream1.C[i].MW, MaterialStream1.MW_p[2] + MaterialStream1.x_pc[2,i] * MaterialStream1.C[i].MW, MaterialStream1.MW_p[3] + MaterialStream1.x_pc[3,i] * MaterialStream1.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_457(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,457};
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
      array_alloc_scalar_real_array(&tmp4, 3, (modelica_real)data->localData[0]->realVars[54] /* MaterialStream1._MW_p[1] variable */ + ((&data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[532])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[55] /* MaterialStream1._MW_p[2] variable */ + ((&data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[532])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[56] /* MaterialStream1._MW_p[3] variable */ + ((&data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[532])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp5, 1, (1), (int*)0, 'W');
      real_array_create(&tmp6, (modelica_real*)&data->localData[0]->realVars[54] /* MaterialStream1._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp4, &tmp6, &tmp5);
    }
  }
  TRACE_POP
}

/*
 equation index: 458
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[3] = MaterialStream1.F_p[3] * MaterialStream1.MW_p[3]
 */
void Flowsheet_eqFunction_458(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,458};
  data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */ = (data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */) * (data->localData[0]->realVars[56] /* MaterialStream1._MW_p[3] variable */);
  TRACE_POP
}

/*
 equation index: 459
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[1] = 100.0 * MaterialStream1.MW_p[1]
 */
void Flowsheet_eqFunction_459(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,459};
  data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */ = (100.0) * (data->localData[0]->realVars[54] /* MaterialStream1._MW_p[1] variable */);
  TRACE_POP
}

/*
 equation index: 460
 type: SIMPLE_ASSIGN
 MaterialStream1._xm_pc[1,2] = DIVISION(MaterialStream1.Fm_pc[1,2], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_460(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,460};
  data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[35] /* MaterialStream1._Fm_pc[1,2] variable */,data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 461
 type: SIMPLE_ASSIGN
 MaterialStream1._xmvap = DIVISION(MaterialStream1.Fm_p[3], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_461(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,461};
  data->localData[0]->realVars[99] /* MaterialStream1._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */,data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 462
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[2] = MaterialStream1.F_p[2] * MaterialStream1.MW_p[2]
 */
void Flowsheet_eqFunction_462(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,462};
  data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */ = (data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */) * (data->localData[0]->realVars[55] /* MaterialStream1._MW_p[2] variable */);
  TRACE_POP
}

/*
 equation index: 463
 type: LINEAR
 
 <var>MaterialStream1._xm_pc[3,2]</var>
 <var>MaterialStream1._xm_pc[2,2]</var>
 <var>MaterialStream1._xm_pc[1,1]</var>
 <var>MaterialStream1._xm_pc[3,1]</var>
 <var>MaterialStream1._xm_pc[2,1]</var>
 <row>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[2,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[1,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1.Fm_pc[1,1] else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[3,1] else MaterialStream1.Fm_pc[1,1]</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[2,2] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then -MaterialStream1.xm_pc[1,2] else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[3,2] else -MaterialStream1.xm_pc[1,2]</cell>
 </row>
 <matrix>
   <cell row="0" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="0" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[2] else 0.0)</residual>
   </cell><cell row="1" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[1] else 0.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -MaterialStream1.Fm_p[1] else if 101325.0 >= MaterialStream1.Pdew then -0.0 else -MaterialStream1.Fm_p[1])</residual>
   </cell><cell row="2" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[3] else -0.0)</residual>
   </cell><cell row="3" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[2] else 0.0)</residual>
   </cell><cell row="3" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -1.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="3" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="3" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[3] else 1.0)</residual>
   </cell><cell row="4" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_463(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,463};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 463 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[4].x[0] = data->localData[1]->realVars[97] /* MaterialStream1._xm_pc[3,2] variable */;
  data->simulationInfo->linearSystemData[4].x[1] = data->localData[1]->realVars[95] /* MaterialStream1._xm_pc[2,2] variable */;
  data->simulationInfo->linearSystemData[4].x[2] = data->localData[1]->realVars[92] /* MaterialStream1._xm_pc[1,1] variable */;
  data->simulationInfo->linearSystemData[4].x[3] = data->localData[1]->realVars[96] /* MaterialStream1._xm_pc[3,1] variable */;
  data->simulationInfo->linearSystemData[4].x[4] = data->localData[1]->realVars[94] /* MaterialStream1._xm_pc[2,1] variable */;
  retValue = solve_linear_system(data, threadData, 4);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,463};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 463 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[97] /* MaterialStream1._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[4].x[0];
  data->localData[0]->realVars[95] /* MaterialStream1._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[4].x[1];
  data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[4].x[2];
  data->localData[0]->realVars[96] /* MaterialStream1._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[4].x[3];
  data->localData[0]->realVars[94] /* MaterialStream1._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[4].x[4];
  TRACE_POP
}

/*
 equation index: 464
 type: SIMPLE_ASSIGN
 MaterialStream1._xmliq = DIVISION(MaterialStream1.Fm_p[2], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_464(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,464};
  data->localData[0]->realVars[98] /* MaterialStream1._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */,data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}

/*
 equation index: 465
 type: SIMPLE_ASSIGN
 MaterialStream1._gmabubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_465(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,465};
  data->localData[0]->realVars[77] /* MaterialStream1._gmabubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 466
 type: SIMPLE_ASSIGN
 MaterialStream1._gmadew_c[1] = 1.0
 */
void Flowsheet_eqFunction_466(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,466};
  data->localData[0]->realVars[79] /* MaterialStream1._gmadew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 467
 type: SIMPLE_ASSIGN
 MaterialStream1._philiqbubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_467(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,467};
  data->localData[0]->realVars[81] /* MaterialStream1._philiqbubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 468
 type: SIMPLE_ASSIGN
 MaterialStream1._phivapdew_c[1] = 1.0
 */
void Flowsheet_eqFunction_468(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,468};
  data->localData[0]->realVars[83] /* MaterialStream1._phivapdew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 469
 type: SIMPLE_ASSIGN
 MaterialStream1._gmabubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_469(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,469};
  data->localData[0]->realVars[78] /* MaterialStream1._gmabubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 470
 type: SIMPLE_ASSIGN
 MaterialStream1._gmadew_c[2] = 1.0
 */
void Flowsheet_eqFunction_470(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,470};
  data->localData[0]->realVars[80] /* MaterialStream1._gmadew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 471
 type: SIMPLE_ASSIGN
 MaterialStream1._philiqbubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_471(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,471};
  data->localData[0]->realVars[82] /* MaterialStream1._philiqbubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 472
 type: SIMPLE_ASSIGN
 MaterialStream1._phivapdew_c[2] = 1.0
 */
void Flowsheet_eqFunction_472(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,472};
  data->localData[0]->realVars[84] /* MaterialStream1._phivapdew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 473
 type: SIMPLE_ASSIGN
 MaterialStream1._Cpres_p[2] = 0.0
 */
void Flowsheet_eqFunction_473(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,473};
  data->localData[0]->realVars[20] /* MaterialStream1._Cpres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 474
 type: SIMPLE_ASSIGN
 MaterialStream1._Cpres_p[3] = 0.0
 */
void Flowsheet_eqFunction_474(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,474};
  data->localData[0]->realVars[21] /* MaterialStream1._Cpres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 475
 type: SIMPLE_ASSIGN
 MaterialStream1._Hres_p[2] = 0.0
 */
void Flowsheet_eqFunction_475(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,475};
  data->localData[0]->realVars[50] /* MaterialStream1._Hres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 476
 type: SIMPLE_ASSIGN
 MaterialStream1._Hres_p[3] = 0.0
 */
void Flowsheet_eqFunction_476(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,476};
  data->localData[0]->realVars[51] /* MaterialStream1._Hres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 477
 type: SIMPLE_ASSIGN
 MaterialStream1._Sres_p[2] = 0.0
 */
void Flowsheet_eqFunction_477(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,477};
  data->localData[0]->realVars[72] /* MaterialStream1._Sres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 478
 type: SIMPLE_ASSIGN
 MaterialStream1._Sres_p[3] = 0.0
 */
void Flowsheet_eqFunction_478(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,478};
  data->localData[0]->realVars[73] /* MaterialStream1._Sres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 479
 type: SIMPLE_ASSIGN
 MaterialStream2._gmabubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_479(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,479};
  data->localData[0]->realVars[164] /* MaterialStream2._gmabubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 480
 type: SIMPLE_ASSIGN
 MaterialStream2._gmadew_c[1] = 1.0
 */
void Flowsheet_eqFunction_480(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,480};
  data->localData[0]->realVars[166] /* MaterialStream2._gmadew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 481
 type: SIMPLE_ASSIGN
 MaterialStream2._philiqbubl_c[1] = 1.0
 */
void Flowsheet_eqFunction_481(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,481};
  data->localData[0]->realVars[168] /* MaterialStream2._philiqbubl_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 482
 type: SIMPLE_ASSIGN
 MaterialStream2._phivapdew_c[1] = 1.0
 */
void Flowsheet_eqFunction_482(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,482};
  data->localData[0]->realVars[170] /* MaterialStream2._phivapdew_c[1] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 483
 type: SIMPLE_ASSIGN
 MaterialStream2._gmabubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_483(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,483};
  data->localData[0]->realVars[165] /* MaterialStream2._gmabubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 484
 type: SIMPLE_ASSIGN
 MaterialStream2._gmadew_c[2] = 1.0
 */
void Flowsheet_eqFunction_484(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,484};
  data->localData[0]->realVars[167] /* MaterialStream2._gmadew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 485
 type: SIMPLE_ASSIGN
 MaterialStream2._philiqbubl_c[2] = 1.0
 */
void Flowsheet_eqFunction_485(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,485};
  data->localData[0]->realVars[169] /* MaterialStream2._philiqbubl_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 486
 type: SIMPLE_ASSIGN
 MaterialStream2._phivapdew_c[2] = 1.0
 */
void Flowsheet_eqFunction_486(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,486};
  data->localData[0]->realVars[171] /* MaterialStream2._phivapdew_c[2] variable */ = 1.0;
  TRACE_POP
}

/*
 equation index: 487
 type: SIMPLE_ASSIGN
 MaterialStream2._Cpres_p[2] = 0.0
 */
void Flowsheet_eqFunction_487(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,487};
  data->localData[0]->realVars[110] /* MaterialStream2._Cpres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 488
 type: SIMPLE_ASSIGN
 MaterialStream2._Cpres_p[3] = 0.0
 */
void Flowsheet_eqFunction_488(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,488};
  data->localData[0]->realVars[111] /* MaterialStream2._Cpres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 489
 type: SIMPLE_ASSIGN
 MaterialStream2._Hres_p[2] = 0.0
 */
void Flowsheet_eqFunction_489(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,489};
  data->localData[0]->realVars[139] /* MaterialStream2._Hres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 490
 type: SIMPLE_ASSIGN
 MaterialStream2._Hres_p[3] = 0.0
 */
void Flowsheet_eqFunction_490(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,490};
  data->localData[0]->realVars[140] /* MaterialStream2._Hres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 491
 type: SIMPLE_ASSIGN
 MaterialStream2._Sres_p[2] = 0.0
 */
void Flowsheet_eqFunction_491(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,491};
  data->localData[0]->realVars[160] /* MaterialStream2._Sres_p[2] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 492
 type: SIMPLE_ASSIGN
 MaterialStream2._Sres_p[3] = 0.0
 */
void Flowsheet_eqFunction_492(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,492};
  data->localData[0]->realVars[161] /* MaterialStream2._Sres_p[3] variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 493
 type: SIMPLE_ASSIGN
 MaterialStream1._P = 101325.0
 */
void Flowsheet_eqFunction_493(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,493};
  data->localData[0]->realVars[57] /* MaterialStream1._P variable */ = 101325.0;
  TRACE_POP
}

/*
 equation index: 494
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[1] = 100.0
 */
void Flowsheet_eqFunction_494(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,494};
  data->localData[0]->realVars[22] /* MaterialStream1._F_p[1] variable */ = 100.0;
  TRACE_POP
}

/*
 equation index: 495
 type: SIMPLE_ASSIGN
 Heater1._Tc[2] = Heater1.C[2].Tc
 */
void Flowsheet_eqFunction_495(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,495};
  data->simulationInfo->realParameter[430] = data->simulationInfo->realParameter[340];
  TRACE_POP
}

/*
 equation index: 496
 type: SIMPLE_ASSIGN
 Heater1._Tc[1] = Heater1.C[1].Tc
 */
void Flowsheet_eqFunction_496(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,496};
  data->simulationInfo->realParameter[429] = data->simulationInfo->realParameter[339];
  TRACE_POP
}

/*
 equation index: 497
 type: SIMPLE_ASSIGN
 MaterialStream2._Tc[2] = MaterialStream2.C[2].Tc
 */
void Flowsheet_eqFunction_497(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,497};
  data->simulationInfo->realParameter[844] = data->simulationInfo->realParameter[756];
  TRACE_POP
}

/*
 equation index: 498
 type: SIMPLE_ASSIGN
 MaterialStream2._Tc[1] = MaterialStream2.C[1].Tc
 */
void Flowsheet_eqFunction_498(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,498};
  data->simulationInfo->realParameter[843] = data->simulationInfo->realParameter[755];
  TRACE_POP
}

/*
 equation index: 499
 type: SIMPLE_ASSIGN
 MaterialStream1._Tc[2] = MaterialStream1.C[2].Tc
 */
void Flowsheet_eqFunction_499(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,499};
  data->simulationInfo->realParameter[637] = data->simulationInfo->realParameter[549];
  TRACE_POP
}

/*
 equation index: 500
 type: SIMPLE_ASSIGN
 MaterialStream1._Tc[1] = MaterialStream1.C[1].Tc
 */
void Flowsheet_eqFunction_500(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,500};
  data->simulationInfo->realParameter[636] = data->simulationInfo->realParameter[548];
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
  Flowsheet_eqFunction_42(data, threadData);
  Flowsheet_eqFunction_46(data, threadData);
  Flowsheet_eqFunction_47(data, threadData);
  Flowsheet_eqFunction_48(data, threadData);
  Flowsheet_eqFunction_49(data, threadData);
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
  Flowsheet_eqFunction_67(data, threadData);
  Flowsheet_eqFunction_68(data, threadData);
  Flowsheet_eqFunction_72(data, threadData);
  Flowsheet_eqFunction_73(data, threadData);
  Flowsheet_eqFunction_84(data, threadData);
  Flowsheet_eqFunction_88(data, threadData);
  Flowsheet_eqFunction_92(data, threadData);
  Flowsheet_eqFunction_96(data, threadData);
  Flowsheet_eqFunction_107(data, threadData);
  Flowsheet_eqFunction_111(data, threadData);
  Flowsheet_eqFunction_115(data, threadData);
  Flowsheet_eqFunction_116(data, threadData);
  Flowsheet_eqFunction_117(data, threadData);
  Flowsheet_eqFunction_118(data, threadData);
  Flowsheet_eqFunction_119(data, threadData);
  Flowsheet_eqFunction_120(data, threadData);
  Flowsheet_eqFunction_121(data, threadData);
  Flowsheet_eqFunction_122(data, threadData);
  Flowsheet_eqFunction_123(data, threadData);
  Flowsheet_eqFunction_124(data, threadData);
  Flowsheet_eqFunction_125(data, threadData);
  Flowsheet_eqFunction_126(data, threadData);
  Flowsheet_eqFunction_127(data, threadData);
  Flowsheet_eqFunction_131(data, threadData);
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
  Flowsheet_eqFunction_152(data, threadData);
  Flowsheet_eqFunction_153(data, threadData);
  Flowsheet_eqFunction_157(data, threadData);
  Flowsheet_eqFunction_158(data, threadData);
  Flowsheet_eqFunction_159(data, threadData);
  Flowsheet_eqFunction_160(data, threadData);
  Flowsheet_eqFunction_164(data, threadData);
  Flowsheet_eqFunction_165(data, threadData);
  Flowsheet_eqFunction_176(data, threadData);
  Flowsheet_eqFunction_180(data, threadData);
  Flowsheet_eqFunction_181(data, threadData);
  Flowsheet_eqFunction_182(data, threadData);
  Flowsheet_eqFunction_186(data, threadData);
  Flowsheet_eqFunction_190(data, threadData);
  Flowsheet_eqFunction_191(data, threadData);
  Flowsheet_eqFunction_192(data, threadData);
  Flowsheet_eqFunction_193(data, threadData);
  Flowsheet_eqFunction_194(data, threadData);
  Flowsheet_eqFunction_205(data, threadData);
  Flowsheet_eqFunction_209(data, threadData);
  Flowsheet_eqFunction_210(data, threadData);
  Flowsheet_eqFunction_211(data, threadData);
  Flowsheet_eqFunction_215(data, threadData);
  Flowsheet_eqFunction_216(data, threadData);
  Flowsheet_eqFunction_217(data, threadData);
  Flowsheet_eqFunction_218(data, threadData);
  Flowsheet_eqFunction_219(data, threadData);
  Flowsheet_eqFunction_220(data, threadData);
  Flowsheet_eqFunction_221(data, threadData);
  Flowsheet_eqFunction_222(data, threadData);
  Flowsheet_eqFunction_223(data, threadData);
  Flowsheet_eqFunction_224(data, threadData);
  Flowsheet_eqFunction_225(data, threadData);
  Flowsheet_eqFunction_226(data, threadData);
  Flowsheet_eqFunction_227(data, threadData);
  Flowsheet_eqFunction_228(data, threadData);
  Flowsheet_eqFunction_229(data, threadData);
  Flowsheet_eqFunction_230(data, threadData);
  Flowsheet_eqFunction_231(data, threadData);
  Flowsheet_eqFunction_232(data, threadData);
  Flowsheet_eqFunction_233(data, threadData);
  Flowsheet_eqFunction_234(data, threadData);
  Flowsheet_eqFunction_235(data, threadData);
  Flowsheet_eqFunction_236(data, threadData);
  Flowsheet_eqFunction_240(data, threadData);
  Flowsheet_eqFunction_244(data, threadData);
  Flowsheet_eqFunction_245(data, threadData);
  Flowsheet_eqFunction_246(data, threadData);
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
  Flowsheet_eqFunction_265(data, threadData);
  Flowsheet_eqFunction_266(data, threadData);
  Flowsheet_eqFunction_267(data, threadData);
  Flowsheet_eqFunction_268(data, threadData);
  Flowsheet_eqFunction_272(data, threadData);
  Flowsheet_eqFunction_273(data, threadData);
  Flowsheet_eqFunction_284(data, threadData);
  Flowsheet_eqFunction_288(data, threadData);
  Flowsheet_eqFunction_289(data, threadData);
  Flowsheet_eqFunction_290(data, threadData);
  Flowsheet_eqFunction_294(data, threadData);
  Flowsheet_eqFunction_298(data, threadData);
  Flowsheet_eqFunction_299(data, threadData);
  Flowsheet_eqFunction_300(data, threadData);
  Flowsheet_eqFunction_301(data, threadData);
  Flowsheet_eqFunction_302(data, threadData);
  Flowsheet_eqFunction_313(data, threadData);
  Flowsheet_eqFunction_317(data, threadData);
  Flowsheet_eqFunction_318(data, threadData);
  Flowsheet_eqFunction_319(data, threadData);
  Flowsheet_eqFunction_323(data, threadData);
  Flowsheet_eqFunction_324(data, threadData);
  Flowsheet_eqFunction_325(data, threadData);
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
  Flowsheet_eqFunction_346(data, threadData);
  Flowsheet_eqFunction_347(data, threadData);
  Flowsheet_eqFunction_348(data, threadData);
  Flowsheet_eqFunction_349(data, threadData);
  Flowsheet_eqFunction_350(data, threadData);
  Flowsheet_eqFunction_351(data, threadData);
  Flowsheet_eqFunction_352(data, threadData);
  Flowsheet_eqFunction_353(data, threadData);
  Flowsheet_eqFunction_354(data, threadData);
  Flowsheet_eqFunction_355(data, threadData);
  Flowsheet_eqFunction_356(data, threadData);
  Flowsheet_eqFunction_357(data, threadData);
  Flowsheet_eqFunction_358(data, threadData);
  Flowsheet_eqFunction_359(data, threadData);
  Flowsheet_eqFunction_376(data, threadData);
  Flowsheet_eqFunction_377(data, threadData);
  Flowsheet_eqFunction_378(data, threadData);
  Flowsheet_eqFunction_379(data, threadData);
  Flowsheet_eqFunction_380(data, threadData);
  Flowsheet_eqFunction_381(data, threadData);
  Flowsheet_eqFunction_382(data, threadData);
  Flowsheet_eqFunction_383(data, threadData);
  Flowsheet_eqFunction_384(data, threadData);
  Flowsheet_eqFunction_385(data, threadData);
  Flowsheet_eqFunction_386(data, threadData);
  Flowsheet_eqFunction_387(data, threadData);
  Flowsheet_eqFunction_388(data, threadData);
  Flowsheet_eqFunction_389(data, threadData);
  Flowsheet_eqFunction_390(data, threadData);
  Flowsheet_eqFunction_391(data, threadData);
  Flowsheet_eqFunction_392(data, threadData);
  Flowsheet_eqFunction_393(data, threadData);
  Flowsheet_eqFunction_394(data, threadData);
  Flowsheet_eqFunction_395(data, threadData);
  Flowsheet_eqFunction_396(data, threadData);
  Flowsheet_eqFunction_397(data, threadData);
  Flowsheet_eqFunction_398(data, threadData);
  Flowsheet_eqFunction_399(data, threadData);
  Flowsheet_eqFunction_400(data, threadData);
  Flowsheet_eqFunction_401(data, threadData);
  Flowsheet_eqFunction_402(data, threadData);
  Flowsheet_eqFunction_403(data, threadData);
  Flowsheet_eqFunction_404(data, threadData);
  Flowsheet_eqFunction_405(data, threadData);
  Flowsheet_eqFunction_406(data, threadData);
  Flowsheet_eqFunction_407(data, threadData);
  Flowsheet_eqFunction_408(data, threadData);
  Flowsheet_eqFunction_409(data, threadData);
  Flowsheet_eqFunction_410(data, threadData);
  Flowsheet_eqFunction_411(data, threadData);
  Flowsheet_eqFunction_412(data, threadData);
  Flowsheet_eqFunction_413(data, threadData);
  Flowsheet_eqFunction_430(data, threadData);
  Flowsheet_eqFunction_431(data, threadData);
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
  Flowsheet_eqFunction_467(data, threadData);
  Flowsheet_eqFunction_468(data, threadData);
  Flowsheet_eqFunction_469(data, threadData);
  Flowsheet_eqFunction_470(data, threadData);
  Flowsheet_eqFunction_471(data, threadData);
  Flowsheet_eqFunction_472(data, threadData);
  Flowsheet_eqFunction_473(data, threadData);
  Flowsheet_eqFunction_474(data, threadData);
  Flowsheet_eqFunction_475(data, threadData);
  Flowsheet_eqFunction_476(data, threadData);
  Flowsheet_eqFunction_477(data, threadData);
  Flowsheet_eqFunction_478(data, threadData);
  Flowsheet_eqFunction_479(data, threadData);
  Flowsheet_eqFunction_480(data, threadData);
  Flowsheet_eqFunction_481(data, threadData);
  Flowsheet_eqFunction_482(data, threadData);
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

