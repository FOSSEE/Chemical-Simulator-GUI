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
 equation index: 698
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[1,2] = 200.0 * MaterialStream3.x_pc[1,2]
 */
void Flowsheet_eqFunction_698(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,698};
  data->localData[0]->realVars[201] /* MaterialStream3._F_pc[1,2] variable */ = (200.0) * (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */);
  TRACE_POP
}
/*
 equation index: 699
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[1,2] = MaterialStream3.F_pc[1,2] * MaterialStream3.C[2].MW
 */
void Flowsheet_eqFunction_699(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,699};
  data->localData[0]->realVars[210] /* MaterialStream3._Fm_pc[1,2] variable */ = (data->localData[0]->realVars[201] /* MaterialStream3._F_pc[1,2] variable */) * (data->simulationInfo->realParameter[738]);
  TRACE_POP
}
/*
 equation index: 700
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[1,1] = 200.0 * MaterialStream3.x_pc[1,1]
 */
void Flowsheet_eqFunction_700(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,700};
  data->localData[0]->realVars[200] /* MaterialStream3._F_pc[1,1] variable */ = (200.0) * (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */);
  TRACE_POP
}
/*
 equation index: 701
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[1,1] = MaterialStream3.F_pc[1,1] * MaterialStream3.C[1].MW
 */
void Flowsheet_eqFunction_701(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,701};
  data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */ = (data->localData[0]->realVars[200] /* MaterialStream3._F_pc[1,1] variable */) * (data->simulationInfo->realParameter[737]);
  TRACE_POP
}
void Flowsheet_eqFunction_702(DATA*,threadData_t*);
void Flowsheet_eqFunction_703(DATA*,threadData_t*);
void Flowsheet_eqFunction_704(DATA*,threadData_t*);
void Flowsheet_eqFunction_709(DATA*,threadData_t*);
void Flowsheet_eqFunction_708(DATA*,threadData_t*);
void Flowsheet_eqFunction_707(DATA*,threadData_t*);
void Flowsheet_eqFunction_706(DATA*,threadData_t*);
void Flowsheet_eqFunction_705(DATA*,threadData_t*);
/*
 equation index: 718
 indexNonlinear: 11
 type: NONLINEAR
 
 vars: {Mixer1._xvapin_s[1], MaterialStream1._x_pc[2,2], MaterialStream1._x_pc[3,2], MaterialStream1._x_pc[2,1], MaterialStream1._x_pc[3,1]}
 eqns: {702, 703, 704, 709, 708, 707, 706, 705}
 */
void Flowsheet_eqFunction_718(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,718};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 718 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[11].nlsxOld[0] = data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */;
  data->simulationInfo->nonlinearSystemData[11].nlsxOld[1] = data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */;
  data->simulationInfo->nonlinearSystemData[11].nlsxOld[2] = data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */;
  data->simulationInfo->nonlinearSystemData[11].nlsxOld[3] = data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[11].nlsxOld[4] = data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */;
  retValue = solve_nonlinear_system(data, threadData, 11);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,718};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 718 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */ = data->simulationInfo->nonlinearSystemData[11].nlsx[0];
  data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[11].nlsx[1];
  data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[11].nlsx[2];
  data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[11].nlsx[3];
  data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[11].nlsx[4];
  TRACE_POP
}
/*
 equation index: 719
 type: ALGORITHM
 
   (MaterialStream1.S_pc[2,1], MaterialStream1.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream1.C[1].VapCp[1], MaterialStream1.C[1].VapCp[2], MaterialStream1.C[1].VapCp[3], MaterialStream1.C[1].VapCp[4], MaterialStream1.C[1].VapCp[5], MaterialStream1.C[1].VapCp[6]}, {MaterialStream1.C[1].HOV[1], MaterialStream1.C[1].HOV[2], MaterialStream1.C[1].HOV[3], MaterialStream1.C[1].HOV[4], MaterialStream1.C[1].HOV[5], MaterialStream1.C[1].HOV[6]}, MaterialStream1.C[1].Tb, MaterialStream1.C[1].Tc, 250.0, 101325.0, MaterialStream1.x_pc[2,1], MaterialStream1.x_pc[3,1]);
 */
void Flowsheet_eqFunction_719(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,719};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[359], (modelica_real)data->simulationInfo->realParameter[360], (modelica_real)data->simulationInfo->realParameter[361], (modelica_real)data->simulationInfo->realParameter[362], (modelica_real)data->simulationInfo->realParameter[363], (modelica_real)data->simulationInfo->realParameter[364]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[259], (modelica_real)data->simulationInfo->realParameter[260], (modelica_real)data->simulationInfo->realParameter[261], (modelica_real)data->simulationInfo->realParameter[262], (modelica_real)data->simulationInfo->realParameter[263], (modelica_real)data->simulationInfo->realParameter[264]);
  data->localData[0]->realVars[62] /* MaterialStream1._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp0, tmp1, data->simulationInfo->realParameter[337], data->simulationInfo->realParameter[339], 250.0, 101325.0, data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */, data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ ,&data->localData[0]->realVars[64] /* MaterialStream1._S_pc[3,1] variable */);
  TRACE_POP
}
/*
 equation index: 720
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.Cp_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_720(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,720};
  data->localData[0]->realVars[7] /* MaterialStream1._Cp_p[3] variable */ = (data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[12] /* MaterialStream1._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[13] /* MaterialStream1._Cp_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 721
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.H_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.H_pc[3,2]
 */
void Flowsheet_eqFunction_721(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,721};
  data->localData[0]->realVars[37] /* MaterialStream1._H_p[3] variable */ = (data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[42] /* MaterialStream1._H_pc[3,1] variable */) + (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[43] /* MaterialStream1._H_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 722
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.Cp_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_722(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,722};
  data->localData[0]->realVars[6] /* MaterialStream1._Cp_p[2] variable */ = (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[10] /* MaterialStream1._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[11] /* MaterialStream1._Cp_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 723
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.H_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.H_pc[2,2]
 */
void Flowsheet_eqFunction_723(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,723};
  data->localData[0]->realVars[36] /* MaterialStream1._H_p[2] variable */ = (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[40] /* MaterialStream1._H_pc[2,1] variable */) + (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[41] /* MaterialStream1._H_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 724
 type: ALGORITHM
 
   MaterialStream1.MW_p[3] := $START.MaterialStream1.MW_p[3];
   MaterialStream1.MW_p[2] := $START.MaterialStream1.MW_p[2];
   MaterialStream1.MW_p[1] := $START.MaterialStream1.MW_p[1];
   for i in 1:2 loop
     MaterialStream1.MW_p[:] := {MaterialStream1.MW_p[1] + MaterialStream1.x_pc[1,i] * MaterialStream1.C[i].MW, MaterialStream1.MW_p[2] + MaterialStream1.x_pc[2,i] * MaterialStream1.C[i].MW, MaterialStream1.MW_p[3] + MaterialStream1.x_pc[3,i] * MaterialStream1.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_724(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,724};
  real_array tmp2;
  index_spec_t tmp3;
  real_array tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  data->localData[0]->realVars[51] /* MaterialStream1._MW_p[3] variable */ = data->modelData->realVarsData[51].attribute /* MaterialStream1._MW_p[3] variable */.start;

  data->localData[0]->realVars[50] /* MaterialStream1._MW_p[2] variable */ = data->modelData->realVarsData[50].attribute /* MaterialStream1._MW_p[2] variable */.start;

  data->localData[0]->realVars[49] /* MaterialStream1._MW_p[1] variable */ = data->modelData->realVarsData[49].attribute /* MaterialStream1._MW_p[1] variable */.start;

  tmp5 = ((modelica_integer) 1); tmp6 = 1; tmp7 = ((modelica_integer) 2);
  if(!tmp6)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert_withEquationIndexes(threadData, info, equationIndexes, "assertion range step != 0 failed");
  }
  else if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer $Pi;
    for($Pi = ((modelica_integer) 1); in_range_integer($Pi, tmp5, tmp7); $Pi += tmp6)
    {
      array_alloc_scalar_real_array(&tmp2, 3, (modelica_real)data->localData[0]->realVars[49] /* MaterialStream1._MW_p[1] variable */ + ((&data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[323])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[50] /* MaterialStream1._MW_p[2] variable */ + ((&data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[323])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[51] /* MaterialStream1._MW_p[3] variable */ + ((&data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[323])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp3, 1, (1), (int*)0, 'W');
      real_array_create(&tmp4, (modelica_real*)&data->localData[0]->realVars[49] /* MaterialStream1._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp2, &tmp4, &tmp3);
    }
  }
  TRACE_POP
}
/*
 equation index: 725
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[1] = 100.0 * MaterialStream1.MW_p[1]
 */
void Flowsheet_eqFunction_725(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,725};
  data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */ = (100.0) * (data->localData[0]->realVars[49] /* MaterialStream1._MW_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 726
 type: SIMPLE_ASSIGN
 MaterialStream1._xm_pc[1,2] = DIVISION(MaterialStream1.Fm_pc[1,2], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_726(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,726};
  data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[30] /* MaterialStream1._Fm_pc[1,2] variable */,data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 727
 type: ALGORITHM
 
   (MaterialStream1.S_pc[2,2], MaterialStream1.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream1.C[2].VapCp[1], MaterialStream1.C[2].VapCp[2], MaterialStream1.C[2].VapCp[3], MaterialStream1.C[2].VapCp[4], MaterialStream1.C[2].VapCp[5], MaterialStream1.C[2].VapCp[6]}, {MaterialStream1.C[2].HOV[1], MaterialStream1.C[2].HOV[2], MaterialStream1.C[2].HOV[3], MaterialStream1.C[2].HOV[4], MaterialStream1.C[2].HOV[5], MaterialStream1.C[2].HOV[6]}, MaterialStream1.C[2].Tb, MaterialStream1.C[2].Tc, 250.0, 101325.0, MaterialStream1.x_pc[2,2], MaterialStream1.x_pc[3,2]);
 */
void Flowsheet_eqFunction_727(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,727};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[365], (modelica_real)data->simulationInfo->realParameter[366], (modelica_real)data->simulationInfo->realParameter[367], (modelica_real)data->simulationInfo->realParameter[368], (modelica_real)data->simulationInfo->realParameter[369], (modelica_real)data->simulationInfo->realParameter[370]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[265], (modelica_real)data->simulationInfo->realParameter[266], (modelica_real)data->simulationInfo->realParameter[267], (modelica_real)data->simulationInfo->realParameter[268], (modelica_real)data->simulationInfo->realParameter[269], (modelica_real)data->simulationInfo->realParameter[270]);
  data->localData[0]->realVars[63] /* MaterialStream1._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp8, tmp9, data->simulationInfo->realParameter[338], data->simulationInfo->realParameter[340], 250.0, 101325.0, data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */, data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ ,&data->localData[0]->realVars[65] /* MaterialStream1._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 728
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[3] = MaterialStream1.x_pc[3,1] * MaterialStream1.S_pc[3,1] + MaterialStream1.x_pc[3,2] * MaterialStream1.S_pc[3,2]
 */
void Flowsheet_eqFunction_728(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,728};
  data->localData[0]->realVars[59] /* MaterialStream1._S_p[3] variable */ = (data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[64] /* MaterialStream1._S_pc[3,1] variable */) + (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[65] /* MaterialStream1._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 729
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[2] = MaterialStream1.x_pc[2,1] * MaterialStream1.S_pc[2,1] + MaterialStream1.x_pc[2,2] * MaterialStream1.S_pc[2,2]
 */
void Flowsheet_eqFunction_729(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,729};
  data->localData[0]->realVars[58] /* MaterialStream1._S_p[2] variable */ = (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[62] /* MaterialStream1._S_pc[2,1] variable */) + (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[63] /* MaterialStream1._S_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 730
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[3,1] = MaterialStream1.x_pc[3,1] * MaterialStream1.F_p[3]
 */
void Flowsheet_eqFunction_730(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,730};
  data->localData[0]->realVars[24] /* MaterialStream1._F_pc[3,1] variable */ = (data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */) * (data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 731
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[3,1] = MaterialStream1.F_pc[3,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_731(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,731};
  data->localData[0]->realVars[33] /* MaterialStream1._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[24] /* MaterialStream1._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[323]);
  TRACE_POP
}
/*
 equation index: 732
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[3,2] = MaterialStream1.x_pc[3,2] * MaterialStream1.F_p[3]
 */
void Flowsheet_eqFunction_732(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,732};
  data->localData[0]->realVars[25] /* MaterialStream1._F_pc[3,2] variable */ = (data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */) * (data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 733
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[3,2] = MaterialStream1.F_pc[3,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_733(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,733};
  data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[25] /* MaterialStream1._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[324]);
  TRACE_POP
}
/*
 equation index: 734
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[3] = MaterialStream1.F_p[3] * MaterialStream1.MW_p[3]
 */
void Flowsheet_eqFunction_734(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,734};
  data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */ = (data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */) * (data->localData[0]->realVars[51] /* MaterialStream1._MW_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 735
 type: SIMPLE_ASSIGN
 MaterialStream1._xmvap = DIVISION(MaterialStream1.Fm_p[3], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_735(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,735};
  data->localData[0]->realVars[94] /* MaterialStream1._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */,data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 736
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[2,1] = MaterialStream1.x_pc[2,1] * MaterialStream1.F_p[2]
 */
void Flowsheet_eqFunction_736(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,736};
  data->localData[0]->realVars[22] /* MaterialStream1._F_pc[2,1] variable */ = (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */) * (data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 737
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[2,1] = MaterialStream1.F_pc[2,1] * MaterialStream1.C[1].MW
 */
void Flowsheet_eqFunction_737(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,737};
  data->localData[0]->realVars[31] /* MaterialStream1._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[22] /* MaterialStream1._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[323]);
  TRACE_POP
}
/*
 equation index: 738
 type: SIMPLE_ASSIGN
 MaterialStream1._F_pc[2,2] = MaterialStream1.x_pc[2,2] * MaterialStream1.F_p[2]
 */
void Flowsheet_eqFunction_738(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,738};
  data->localData[0]->realVars[23] /* MaterialStream1._F_pc[2,2] variable */ = (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */) * (data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 739
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_pc[2,2] = MaterialStream1.F_pc[2,2] * MaterialStream1.C[2].MW
 */
void Flowsheet_eqFunction_739(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,739};
  data->localData[0]->realVars[32] /* MaterialStream1._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[23] /* MaterialStream1._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[324]);
  TRACE_POP
}
/*
 equation index: 740
 type: SIMPLE_ASSIGN
 MaterialStream1._Fm_p[2] = MaterialStream1.F_p[2] * MaterialStream1.MW_p[2]
 */
void Flowsheet_eqFunction_740(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,740};
  data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */ = (data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */) * (data->localData[0]->realVars[50] /* MaterialStream1._MW_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 741
 type: LINEAR
 
 <var>MaterialStream1._xm_pc[3,1]</var>
 <var>MaterialStream1._xm_pc[1,1]</var>
 <var>MaterialStream1._xm_pc[2,1]</var>
 <var>MaterialStream1._xm_pc[3,2]</var>
 <var>MaterialStream1._xm_pc[2,2]</var>
 <row>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[2,2] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then -MaterialStream1.xm_pc[1,2] else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[3,2] else -MaterialStream1.xm_pc[1,2]</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[2,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[1,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1.Fm_pc[1,1] else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1.Fm_pc[3,1] else MaterialStream1.Fm_pc[1,1]</cell>
 </row>
 <matrix>
   <cell row="0" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="0" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -1.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="0" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[2] else 0.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[3] else 1.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[2] else 0.0)</residual>
   </cell><cell row="2" col="3">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="2" col="4">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="3" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="3" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[1] else 0.0)</residual>
   </cell><cell row="3" col="2">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then 0.0 else if 101325.0 >= MaterialStream1.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -0.0 else if 101325.0 >= MaterialStream1.Pdew then -MaterialStream1.Fm_p[3] else -0.0)</residual>
   </cell><cell row="4" col="1">
     <residual>-(if 101325.0 >= MaterialStream1.Pbubl then -MaterialStream1.Fm_p[1] else if 101325.0 >= MaterialStream1.Pdew then -0.0 else -MaterialStream1.Fm_p[1])</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_741(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,741};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 741 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[7].x[0] = data->localData[1]->realVars[91] /* MaterialStream1._xm_pc[3,1] variable */;
  data->simulationInfo->linearSystemData[7].x[1] = data->localData[1]->realVars[87] /* MaterialStream1._xm_pc[1,1] variable */;
  data->simulationInfo->linearSystemData[7].x[2] = data->localData[1]->realVars[89] /* MaterialStream1._xm_pc[2,1] variable */;
  data->simulationInfo->linearSystemData[7].x[3] = data->localData[1]->realVars[92] /* MaterialStream1._xm_pc[3,2] variable */;
  data->simulationInfo->linearSystemData[7].x[4] = data->localData[1]->realVars[90] /* MaterialStream1._xm_pc[2,2] variable */;
  retValue = solve_linear_system(data, threadData, 7);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,741};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 741 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[91] /* MaterialStream1._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[7].x[0];
  data->localData[0]->realVars[87] /* MaterialStream1._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[7].x[1];
  data->localData[0]->realVars[89] /* MaterialStream1._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[7].x[2];
  data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[7].x[3];
  data->localData[0]->realVars[90] /* MaterialStream1._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[7].x[4];
  TRACE_POP
}
/*
 equation index: 742
 type: SIMPLE_ASSIGN
 MaterialStream1._xmliq = DIVISION(MaterialStream1.Fm_p[2], MaterialStream1.Fm_p[1])
 */
void Flowsheet_eqFunction_742(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,742};
  data->localData[0]->realVars[93] /* MaterialStream1._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */,data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */,"MaterialStream1.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 743
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_p[1] = MaterialStream1.xliq * MaterialStream1.Cp_p[2] + Mixer1.xvapin_s[1] * MaterialStream1.Cp_p[3]
 */
void Flowsheet_eqFunction_743(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,743};
  data->localData[0]->realVars[5] /* MaterialStream1._Cp_p[1] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[6] /* MaterialStream1._Cp_p[2] variable */) + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (data->localData[0]->realVars[7] /* MaterialStream1._Cp_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 744
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.Cp_p[1]
 */
void Flowsheet_eqFunction_744(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,744};
  data->localData[0]->realVars[8] /* MaterialStream1._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[5] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 745
 type: SIMPLE_ASSIGN
 MaterialStream1._Cp_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.Cp_p[1]
 */
void Flowsheet_eqFunction_745(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,745};
  data->localData[0]->realVars[9] /* MaterialStream1._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[5] /* MaterialStream1._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 746
 type: SIMPLE_ASSIGN
 MaterialStream1._H_p[1] = MaterialStream1.xliq * MaterialStream1.H_p[2] + Mixer1.xvapin_s[1] * MaterialStream1.H_p[3]
 */
void Flowsheet_eqFunction_746(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,746};
  data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[36] /* MaterialStream1._H_p[2] variable */) + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (data->localData[0]->realVars[37] /* MaterialStream1._H_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 747
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.H_p[1]
 */
void Flowsheet_eqFunction_747(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,747};
  data->localData[0]->realVars[38] /* MaterialStream1._H_pc[1,1] variable */ = (data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 748
 type: SIMPLE_ASSIGN
 MaterialStream1._H_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.H_p[1]
 */
void Flowsheet_eqFunction_748(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,748};
  data->localData[0]->realVars[39] /* MaterialStream1._H_pc[1,2] variable */ = (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 749
 type: SIMPLE_ASSIGN
 MaterialStream1._S_p[1] = MaterialStream1.xliq * MaterialStream1.S_p[2] + Mixer1.xvapin_s[1] * MaterialStream1.S_p[3]
 */
void Flowsheet_eqFunction_749(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,749};
  data->localData[0]->realVars[57] /* MaterialStream1._S_p[1] variable */ = (data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */) * (data->localData[0]->realVars[58] /* MaterialStream1._S_p[2] variable */) + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (data->localData[0]->realVars[59] /* MaterialStream1._S_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 750
 type: SIMPLE_ASSIGN
 MaterialStream1._S_pc[1,1] = MaterialStream1.x_pc[1,1] * MaterialStream1.S_p[1]
 */
void Flowsheet_eqFunction_750(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,750};
  data->localData[0]->realVars[60] /* MaterialStream1._S_pc[1,1] variable */ = (data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (data->localData[0]->realVars[57] /* MaterialStream1._S_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 751
 type: SIMPLE_ASSIGN
 MaterialStream1._S_pc[1,2] = MaterialStream1.x_pc[1,2] * MaterialStream1.S_p[1]
 */
void Flowsheet_eqFunction_751(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,751};
  data->localData[0]->realVars[61] /* MaterialStream1._S_pc[1,2] variable */ = (data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (data->localData[0]->realVars[57] /* MaterialStream1._S_p[1] variable */);
  TRACE_POP
}
void Flowsheet_eqFunction_752(DATA*,threadData_t*);
void Flowsheet_eqFunction_753(DATA*,threadData_t*);
void Flowsheet_eqFunction_754(DATA*,threadData_t*);
void Flowsheet_eqFunction_759(DATA*,threadData_t*);
void Flowsheet_eqFunction_758(DATA*,threadData_t*);
void Flowsheet_eqFunction_757(DATA*,threadData_t*);
void Flowsheet_eqFunction_756(DATA*,threadData_t*);
void Flowsheet_eqFunction_755(DATA*,threadData_t*);
/*
 equation index: 768
 indexNonlinear: 12
 type: NONLINEAR
 
 vars: {Mixer1._xvapin_s[2], MaterialStream2._x_pc[3,2], MaterialStream2._x_pc[3,1], MaterialStream2._x_pc[2,1], MaterialStream2._x_pc[2,2]}
 eqns: {752, 753, 754, 759, 758, 757, 756, 755}
 */
void Flowsheet_eqFunction_768(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,768};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 768 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[12].nlsxOld[0] = data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */;
  data->simulationInfo->nonlinearSystemData[12].nlsxOld[1] = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */;
  data->simulationInfo->nonlinearSystemData[12].nlsxOld[2] = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */;
  data->simulationInfo->nonlinearSystemData[12].nlsxOld[3] = data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */;
  data->simulationInfo->nonlinearSystemData[12].nlsxOld[4] = data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */;
  retValue = solve_nonlinear_system(data, threadData, 12);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,768};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 768 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */ = data->simulationInfo->nonlinearSystemData[12].nlsx[0];
  data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[12].nlsx[1];
  data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[12].nlsx[2];
  data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[12].nlsx[3];
  data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[12].nlsx[4];
  TRACE_POP
}
/*
 equation index: 769
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.Cp_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_769(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,769};
  data->localData[0]->realVars[96] /* MaterialStream2._Cp_p[2] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[100] /* MaterialStream2._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[101] /* MaterialStream2._Cp_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 770
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.H_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.H_pc[2,2]
 */
void Flowsheet_eqFunction_770(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,770};
  data->localData[0]->realVars[126] /* MaterialStream2._H_p[2] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[130] /* MaterialStream2._H_pc[2,1] variable */) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[131] /* MaterialStream2._H_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 771
 type: ALGORITHM
 
   (MaterialStream2.S_pc[2,1], MaterialStream2.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream2.C[1].VapCp[1], MaterialStream2.C[1].VapCp[2], MaterialStream2.C[1].VapCp[3], MaterialStream2.C[1].VapCp[4], MaterialStream2.C[1].VapCp[5], MaterialStream2.C[1].VapCp[6]}, {MaterialStream2.C[1].HOV[1], MaterialStream2.C[1].HOV[2], MaterialStream2.C[1].HOV[3], MaterialStream2.C[1].HOV[4], MaterialStream2.C[1].HOV[5], MaterialStream2.C[1].HOV[6]}, MaterialStream2.C[1].Tb, MaterialStream2.C[1].Tc, 300.0, 101325.0, MaterialStream2.x_pc[2,1], MaterialStream2.x_pc[3,1]);
 */
void Flowsheet_eqFunction_771(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,771};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567], (modelica_real)data->simulationInfo->realParameter[568], (modelica_real)data->simulationInfo->realParameter[569], (modelica_real)data->simulationInfo->realParameter[570], (modelica_real)data->simulationInfo->realParameter[571]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[466], (modelica_real)data->simulationInfo->realParameter[467], (modelica_real)data->simulationInfo->realParameter[468], (modelica_real)data->simulationInfo->realParameter[469], (modelica_real)data->simulationInfo->realParameter[470], (modelica_real)data->simulationInfo->realParameter[471]);
  data->localData[0]->realVars[152] /* MaterialStream2._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp0, tmp1, data->simulationInfo->realParameter[544], data->simulationInfo->realParameter[546], 300.0, 101325.0, data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */, data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ ,&data->localData[0]->realVars[154] /* MaterialStream2._S_pc[3,1] variable */);
  TRACE_POP
}
/*
 equation index: 772
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[3,1] = MaterialStream2.x_pc[3,1] * MaterialStream2.F_p[3]
 */
void Flowsheet_eqFunction_772(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,772};
  data->localData[0]->realVars[114] /* MaterialStream2._F_pc[3,1] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 773
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[3,1] = MaterialStream2.F_pc[3,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_773(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,773};
  data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[114] /* MaterialStream2._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[530]);
  TRACE_POP
}
/*
 equation index: 774
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.Cp_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_774(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,774};
  data->localData[0]->realVars[97] /* MaterialStream2._Cp_p[3] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[102] /* MaterialStream2._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[103] /* MaterialStream2._Cp_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 775
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.H_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.H_pc[3,2]
 */
void Flowsheet_eqFunction_775(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,775};
  data->localData[0]->realVars[127] /* MaterialStream2._H_p[3] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[132] /* MaterialStream2._H_pc[3,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[133] /* MaterialStream2._H_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 776
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[3,2] = MaterialStream2.x_pc[3,2] * MaterialStream2.F_p[3]
 */
void Flowsheet_eqFunction_776(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,776};
  data->localData[0]->realVars[115] /* MaterialStream2._F_pc[3,2] variable */ = (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 777
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[3,2] = MaterialStream2.F_pc[3,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_777(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,777};
  data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[115] /* MaterialStream2._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[531]);
  TRACE_POP
}
/*
 equation index: 778
 type: ALGORITHM
 
   MaterialStream2.MW_p[3] := $START.MaterialStream2.MW_p[3];
   MaterialStream2.MW_p[2] := $START.MaterialStream2.MW_p[2];
   MaterialStream2.MW_p[1] := $START.MaterialStream2.MW_p[1];
   for i in 1:2 loop
     MaterialStream2.MW_p[:] := {MaterialStream2.MW_p[1] + MaterialStream2.x_pc[1,i] * MaterialStream2.C[i].MW, MaterialStream2.MW_p[2] + MaterialStream2.x_pc[2,i] * MaterialStream2.C[i].MW, MaterialStream2.MW_p[3] + MaterialStream2.x_pc[3,i] * MaterialStream2.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_778(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,778};
  real_array tmp2;
  index_spec_t tmp3;
  real_array tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  data->localData[0]->realVars[141] /* MaterialStream2._MW_p[3] variable */ = data->modelData->realVarsData[141].attribute /* MaterialStream2._MW_p[3] variable */.start;

  data->localData[0]->realVars[140] /* MaterialStream2._MW_p[2] variable */ = data->modelData->realVarsData[140].attribute /* MaterialStream2._MW_p[2] variable */.start;

  data->localData[0]->realVars[139] /* MaterialStream2._MW_p[1] variable */ = data->modelData->realVarsData[139].attribute /* MaterialStream2._MW_p[1] variable */.start;

  tmp5 = ((modelica_integer) 1); tmp6 = 1; tmp7 = ((modelica_integer) 2);
  if(!tmp6)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert_withEquationIndexes(threadData, info, equationIndexes, "assertion range step != 0 failed");
  }
  else if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer $Pi;
    for($Pi = ((modelica_integer) 1); in_range_integer($Pi, tmp5, tmp7); $Pi += tmp6)
    {
      array_alloc_scalar_real_array(&tmp2, 3, (modelica_real)data->localData[0]->realVars[139] /* MaterialStream2._MW_p[1] variable */ + ((&data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[530])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[140] /* MaterialStream2._MW_p[2] variable */ + ((&data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[530])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[141] /* MaterialStream2._MW_p[3] variable */ + ((&data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[530])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp3, 1, (1), (int*)0, 'W');
      real_array_create(&tmp4, (modelica_real*)&data->localData[0]->realVars[139] /* MaterialStream2._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp2, &tmp4, &tmp3);
    }
  }
  TRACE_POP
}
/*
 equation index: 779
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[3] = MaterialStream2.F_p[3] * MaterialStream2.MW_p[3]
 */
void Flowsheet_eqFunction_779(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,779};
  data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */ = (data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */) * (data->localData[0]->realVars[141] /* MaterialStream2._MW_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 780
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[1] = 100.0 * MaterialStream2.MW_p[1]
 */
void Flowsheet_eqFunction_780(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,780};
  data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */ = (100.0) * (data->localData[0]->realVars[139] /* MaterialStream2._MW_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 781
 type: SIMPLE_ASSIGN
 MaterialStream2._xm_pc[1,2] = DIVISION(MaterialStream2.Fm_pc[1,2], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_781(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,781};
  data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[120] /* MaterialStream2._Fm_pc[1,2] variable */,data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 782
 type: SIMPLE_ASSIGN
 MaterialStream2._xmvap = DIVISION(MaterialStream2.Fm_p[3], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_782(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,782};
  data->localData[0]->realVars[184] /* MaterialStream2._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */,data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 783
 type: ALGORITHM
 
   (MaterialStream2.S_pc[2,2], MaterialStream2.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream2.C[2].VapCp[1], MaterialStream2.C[2].VapCp[2], MaterialStream2.C[2].VapCp[3], MaterialStream2.C[2].VapCp[4], MaterialStream2.C[2].VapCp[5], MaterialStream2.C[2].VapCp[6]}, {MaterialStream2.C[2].HOV[1], MaterialStream2.C[2].HOV[2], MaterialStream2.C[2].HOV[3], MaterialStream2.C[2].HOV[4], MaterialStream2.C[2].HOV[5], MaterialStream2.C[2].HOV[6]}, MaterialStream2.C[2].Tb, MaterialStream2.C[2].Tc, 300.0, 101325.0, MaterialStream2.x_pc[2,2], MaterialStream2.x_pc[3,2]);
 */
void Flowsheet_eqFunction_783(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,783};
  real_array tmp8;
  real_array tmp9;
  array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)data->simulationInfo->realParameter[572], (modelica_real)data->simulationInfo->realParameter[573], (modelica_real)data->simulationInfo->realParameter[574], (modelica_real)data->simulationInfo->realParameter[575], (modelica_real)data->simulationInfo->realParameter[576], (modelica_real)data->simulationInfo->realParameter[577]);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)data->simulationInfo->realParameter[472], (modelica_real)data->simulationInfo->realParameter[473], (modelica_real)data->simulationInfo->realParameter[474], (modelica_real)data->simulationInfo->realParameter[475], (modelica_real)data->simulationInfo->realParameter[476], (modelica_real)data->simulationInfo->realParameter[477]);
  data->localData[0]->realVars[153] /* MaterialStream2._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp8, tmp9, data->simulationInfo->realParameter[545], data->simulationInfo->realParameter[547], 300.0, 101325.0, data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */, data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ ,&data->localData[0]->realVars[155] /* MaterialStream2._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 784
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[2] = MaterialStream2.x_pc[2,1] * MaterialStream2.S_pc[2,1] + MaterialStream2.x_pc[2,2] * MaterialStream2.S_pc[2,2]
 */
void Flowsheet_eqFunction_784(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,784};
  data->localData[0]->realVars[148] /* MaterialStream2._S_p[2] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[152] /* MaterialStream2._S_pc[2,1] variable */) + (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[153] /* MaterialStream2._S_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 785
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[3] = MaterialStream2.x_pc[3,1] * MaterialStream2.S_pc[3,1] + MaterialStream2.x_pc[3,2] * MaterialStream2.S_pc[3,2]
 */
void Flowsheet_eqFunction_785(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,785};
  data->localData[0]->realVars[149] /* MaterialStream2._S_p[3] variable */ = (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */) * (data->localData[0]->realVars[154] /* MaterialStream2._S_pc[3,1] variable */) + (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */) * (data->localData[0]->realVars[155] /* MaterialStream2._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 786
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[2,2] = MaterialStream2.x_pc[2,2] * MaterialStream2.F_p[2]
 */
void Flowsheet_eqFunction_786(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,786};
  data->localData[0]->realVars[113] /* MaterialStream2._F_pc[2,2] variable */ = (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */) * (data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 787
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[2,2] = MaterialStream2.F_pc[2,2] * MaterialStream2.C[2].MW
 */
void Flowsheet_eqFunction_787(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,787};
  data->localData[0]->realVars[122] /* MaterialStream2._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[113] /* MaterialStream2._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[531]);
  TRACE_POP
}
/*
 equation index: 788
 type: SIMPLE_ASSIGN
 MaterialStream2._F_pc[2,1] = MaterialStream2.x_pc[2,1] * MaterialStream2.F_p[2]
 */
void Flowsheet_eqFunction_788(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,788};
  data->localData[0]->realVars[112] /* MaterialStream2._F_pc[2,1] variable */ = (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */) * (data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 789
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_pc[2,1] = MaterialStream2.F_pc[2,1] * MaterialStream2.C[1].MW
 */
void Flowsheet_eqFunction_789(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,789};
  data->localData[0]->realVars[121] /* MaterialStream2._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[112] /* MaterialStream2._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[530]);
  TRACE_POP
}
/*
 equation index: 790
 type: SIMPLE_ASSIGN
 MaterialStream2._Fm_p[2] = MaterialStream2.F_p[2] * MaterialStream2.MW_p[2]
 */
void Flowsheet_eqFunction_790(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,790};
  data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */ = (data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */) * (data->localData[0]->realVars[140] /* MaterialStream2._MW_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 791
 type: LINEAR
 
 <var>MaterialStream2._xm_pc[1,1]</var>
 <var>MaterialStream2._xm_pc[3,1]</var>
 <var>MaterialStream2._xm_pc[2,1]</var>
 <var>MaterialStream2._xm_pc[3,2]</var>
 <var>MaterialStream2._xm_pc[2,2]</var>
 <row>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[2,2] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then -MaterialStream2.xm_pc[1,2] else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[3,2] else -MaterialStream2.xm_pc[1,2]</cell>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[2,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[1,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2.Fm_pc[1,1] else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2.Fm_pc[3,1] else MaterialStream2.Fm_pc[1,1]</cell>
 </row>
 <matrix>
   <cell row="0" col="0">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then -1.0 else if 101325.0 >= MaterialStream2.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="0" col="1">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="0" col="2">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[2] else 0.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[3] else 1.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[2] else 0.0)</residual>
   </cell><cell row="2" col="3">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="2" col="4">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="3" col="0">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[1] else 0.0)</residual>
   </cell><cell row="3" col="1">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="3" col="2">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then 0.0 else if 101325.0 >= MaterialStream2.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then -MaterialStream2.Fm_p[1] else if 101325.0 >= MaterialStream2.Pdew then -0.0 else -MaterialStream2.Fm_p[1])</residual>
   </cell><cell row="4" col="1">
     <residual>-(if 101325.0 >= MaterialStream2.Pbubl then -0.0 else if 101325.0 >= MaterialStream2.Pdew then -MaterialStream2.Fm_p[3] else -0.0)</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_791(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,791};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 791 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[8].x[0] = data->localData[1]->realVars[177] /* MaterialStream2._xm_pc[1,1] variable */;
  data->simulationInfo->linearSystemData[8].x[1] = data->localData[1]->realVars[181] /* MaterialStream2._xm_pc[3,1] variable */;
  data->simulationInfo->linearSystemData[8].x[2] = data->localData[1]->realVars[179] /* MaterialStream2._xm_pc[2,1] variable */;
  data->simulationInfo->linearSystemData[8].x[3] = data->localData[1]->realVars[182] /* MaterialStream2._xm_pc[3,2] variable */;
  data->simulationInfo->linearSystemData[8].x[4] = data->localData[1]->realVars[180] /* MaterialStream2._xm_pc[2,2] variable */;
  retValue = solve_linear_system(data, threadData, 8);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,791};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 791 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[177] /* MaterialStream2._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[8].x[0];
  data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[8].x[1];
  data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[8].x[2];
  data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[8].x[3];
  data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[8].x[4];
  TRACE_POP
}
/*
 equation index: 792
 type: SIMPLE_ASSIGN
 MaterialStream2._xmliq = DIVISION(MaterialStream2.Fm_p[2], MaterialStream2.Fm_p[1])
 */
void Flowsheet_eqFunction_792(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,792};
  data->localData[0]->realVars[183] /* MaterialStream2._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */,data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */,"MaterialStream2.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 793
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_p[1] = MaterialStream2.xliq * MaterialStream2.Cp_p[2] + Mixer1.xvapin_s[2] * MaterialStream2.Cp_p[3]
 */
void Flowsheet_eqFunction_793(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,793};
  data->localData[0]->realVars[95] /* MaterialStream2._Cp_p[1] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[96] /* MaterialStream2._Cp_p[2] variable */) + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (data->localData[0]->realVars[97] /* MaterialStream2._Cp_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 794
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.Cp_p[1]
 */
void Flowsheet_eqFunction_794(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,794};
  data->localData[0]->realVars[98] /* MaterialStream2._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[95] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 795
 type: SIMPLE_ASSIGN
 MaterialStream2._Cp_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.Cp_p[1]
 */
void Flowsheet_eqFunction_795(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,795};
  data->localData[0]->realVars[99] /* MaterialStream2._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[95] /* MaterialStream2._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 796
 type: SIMPLE_ASSIGN
 MaterialStream2._H_p[1] = MaterialStream2.xliq * MaterialStream2.H_p[2] + Mixer1.xvapin_s[2] * MaterialStream2.H_p[3]
 */
void Flowsheet_eqFunction_796(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,796};
  data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[126] /* MaterialStream2._H_p[2] variable */) + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (data->localData[0]->realVars[127] /* MaterialStream2._H_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 797
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.H_p[1]
 */
void Flowsheet_eqFunction_797(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,797};
  data->localData[0]->realVars[128] /* MaterialStream2._H_pc[1,1] variable */ = (data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 798
 type: SIMPLE_ASSIGN
 MaterialStream2._H_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.H_p[1]
 */
void Flowsheet_eqFunction_798(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,798};
  data->localData[0]->realVars[129] /* MaterialStream2._H_pc[1,2] variable */ = (data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 799
 type: SIMPLE_ASSIGN
 MaterialStream3._H_p[1] = 0.5 * (MaterialStream1.H_p[1] + MaterialStream2.H_p[1])
 */
void Flowsheet_eqFunction_799(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,799};
  data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */ = (0.5) * (data->localData[0]->realVars[35] /* MaterialStream1._H_p[1] variable */ + data->localData[0]->realVars[125] /* MaterialStream2._H_p[1] variable */);
  TRACE_POP
}
void Flowsheet_eqFunction_800(DATA*,threadData_t*);
void Flowsheet_eqFunction_801(DATA*,threadData_t*);
void Flowsheet_eqFunction_802(DATA*,threadData_t*);
void Flowsheet_eqFunction_803(DATA*,threadData_t*);
void Flowsheet_eqFunction_804(DATA*,threadData_t*);
void Flowsheet_eqFunction_805(DATA*,threadData_t*);
void Flowsheet_eqFunction_806(DATA*,threadData_t*);
void Flowsheet_eqFunction_807(DATA*,threadData_t*);
void Flowsheet_eqFunction_808(DATA*,threadData_t*);
void Flowsheet_eqFunction_809(DATA*,threadData_t*);
void Flowsheet_eqFunction_810(DATA*,threadData_t*);
void Flowsheet_eqFunction_811(DATA*,threadData_t*);
void Flowsheet_eqFunction_812(DATA*,threadData_t*);
void Flowsheet_eqFunction_813(DATA*,threadData_t*);
void Flowsheet_eqFunction_814(DATA*,threadData_t*);
void Flowsheet_eqFunction_815(DATA*,threadData_t*);
void Flowsheet_eqFunction_816(DATA*,threadData_t*);
void Flowsheet_eqFunction_817(DATA*,threadData_t*);
void Flowsheet_eqFunction_818(DATA*,threadData_t*);
void Flowsheet_eqFunction_819(DATA*,threadData_t*);
void Flowsheet_eqFunction_825(DATA*,threadData_t*);
void Flowsheet_eqFunction_824(DATA*,threadData_t*);
void Flowsheet_eqFunction_823(DATA*,threadData_t*);
void Flowsheet_eqFunction_822(DATA*,threadData_t*);
void Flowsheet_eqFunction_821(DATA*,threadData_t*);
void Flowsheet_eqFunction_820(DATA*,threadData_t*);
/*
 equation index: 826
 indexNonlinear: 13
 type: NONLINEAR
 
 vars: {MaterialStream3._xvap, MaterialStream3._T, MaterialStream3._x_pc[2,2], MaterialStream3._x_pc[3,1], MaterialStream3._x_pc[3,2], MaterialStream3._x_pc[2,1]}
 eqns: {800, 801, 802, 803, 804, 805, 806, 807, 808, 809, 810, 811, 812, 813, 814, 815, 816, 817, 818, 819, 825, 824, 823, 822, 821, 820}
 */
void Flowsheet_eqFunction_826(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,826};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 826 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[13].nlsxOld[0] = data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */;
  data->simulationInfo->nonlinearSystemData[13].nlsxOld[1] = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  data->simulationInfo->nonlinearSystemData[13].nlsxOld[2] = data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */;
  data->simulationInfo->nonlinearSystemData[13].nlsxOld[3] = data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */;
  data->simulationInfo->nonlinearSystemData[13].nlsxOld[4] = data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */;
  data->simulationInfo->nonlinearSystemData[13].nlsxOld[5] = data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */;
  retValue = solve_nonlinear_system(data, threadData, 13);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,826};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 826 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */ = data->simulationInfo->nonlinearSystemData[13].nlsx[0];
  data->localData[0]->realVars[249] /* MaterialStream3._T variable */ = data->simulationInfo->nonlinearSystemData[13].nlsx[1];
  data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */ = data->simulationInfo->nonlinearSystemData[13].nlsx[2];
  data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ = data->simulationInfo->nonlinearSystemData[13].nlsx[3];
  data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ = data->simulationInfo->nonlinearSystemData[13].nlsx[4];
  data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */ = data->simulationInfo->nonlinearSystemData[13].nlsx[5];
  TRACE_POP
}
/*
 equation index: 827
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[2,1] = MaterialStream3.x_pc[2,1] * MaterialStream3.F_p[2]
 */
void Flowsheet_eqFunction_827(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,827};
  data->localData[0]->realVars[202] /* MaterialStream3._F_pc[2,1] variable */ = (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */) * (data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 828
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[2,1] = MaterialStream3.F_pc[2,1] * MaterialStream3.C[1].MW
 */
void Flowsheet_eqFunction_828(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,828};
  data->localData[0]->realVars[211] /* MaterialStream3._Fm_pc[2,1] variable */ = (data->localData[0]->realVars[202] /* MaterialStream3._F_pc[2,1] variable */) * (data->simulationInfo->realParameter[737]);
  TRACE_POP
}
/*
 equation index: 829
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[3,2] = MaterialStream3.x_pc[3,2] * MaterialStream3.F_p[3]
 */
void Flowsheet_eqFunction_829(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,829};
  data->localData[0]->realVars[205] /* MaterialStream3._F_pc[3,2] variable */ = (data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */) * (data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 830
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[3,2] = MaterialStream3.F_pc[3,2] * MaterialStream3.C[2].MW
 */
void Flowsheet_eqFunction_830(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,830};
  data->localData[0]->realVars[214] /* MaterialStream3._Fm_pc[3,2] variable */ = (data->localData[0]->realVars[205] /* MaterialStream3._F_pc[3,2] variable */) * (data->simulationInfo->realParameter[738]);
  TRACE_POP
}
/*
 equation index: 831
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[3,2] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_831(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,831};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  data->localData[0]->realVars[193] /* MaterialStream3._Cp_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp0, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 832
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[2,2] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream3.C[2].LiqCp[1], MaterialStream3.C[2].LiqCp[2], MaterialStream3.C[2].LiqCp[3], MaterialStream3.C[2].LiqCp[4], MaterialStream3.C[2].LiqCp[5], MaterialStream3.C[2].LiqCp[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_832(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,832};
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[695], (modelica_real)data->simulationInfo->realParameter[696], (modelica_real)data->simulationInfo->realParameter[697], (modelica_real)data->simulationInfo->realParameter[698], (modelica_real)data->simulationInfo->realParameter[699], (modelica_real)data->simulationInfo->realParameter[700]);
  data->localData[0]->realVars[191] /* MaterialStream3._Cp_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp1, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 833
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[3,1] = Simulator.Files.ThermodynamicFunctions.VapCpId({MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_833(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,833};
  real_array tmp2;
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  data->localData[0]->realVars[192] /* MaterialStream3._Cp_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp2, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 834
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[2,1] = Simulator.Files.ThermodynamicFunctions.LiqCpId({MaterialStream3.C[1].LiqCp[1], MaterialStream3.C[1].LiqCp[2], MaterialStream3.C[1].LiqCp[3], MaterialStream3.C[1].LiqCp[4], MaterialStream3.C[1].LiqCp[5], MaterialStream3.C[1].LiqCp[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_834(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,834};
  real_array tmp3;
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)data->simulationInfo->realParameter[689], (modelica_real)data->simulationInfo->realParameter[690], (modelica_real)data->simulationInfo->realParameter[691], (modelica_real)data->simulationInfo->realParameter[692], (modelica_real)data->simulationInfo->realParameter[693], (modelica_real)data->simulationInfo->realParameter[694]);
  data->localData[0]->realVars[190] /* MaterialStream3._Cp_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, tmp3, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 835
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[3,1] = MaterialStream3.x_pc[3,1] * MaterialStream3.F_p[3]
 */
void Flowsheet_eqFunction_835(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,835};
  data->localData[0]->realVars[204] /* MaterialStream3._F_pc[3,1] variable */ = (data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */) * (data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 836
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[3,1] = MaterialStream3.F_pc[3,1] * MaterialStream3.C[1].MW
 */
void Flowsheet_eqFunction_836(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,836};
  data->localData[0]->realVars[213] /* MaterialStream3._Fm_pc[3,1] variable */ = (data->localData[0]->realVars[204] /* MaterialStream3._F_pc[3,1] variable */) * (data->simulationInfo->realParameter[737]);
  TRACE_POP
}
/*
 equation index: 837
 type: ALGORITHM
 
   (MaterialStream3.S_pc[2,1], MaterialStream3.S_pc[3,1]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, {MaterialStream3.C[1].HOV[1], MaterialStream3.C[1].HOV[2], MaterialStream3.C[1].HOV[3], MaterialStream3.C[1].HOV[4], MaterialStream3.C[1].HOV[5], MaterialStream3.C[1].HOV[6]}, MaterialStream3.C[1].Tb, MaterialStream3.C[1].Tc, MaterialStream3.T, 101325.0, MaterialStream3.x_pc[2,1], MaterialStream3.x_pc[3,1]);
 */
void Flowsheet_eqFunction_837(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,837};
  real_array tmp4;
  real_array tmp5;
  array_alloc_scalar_real_array(&tmp4, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  array_alloc_scalar_real_array(&tmp5, 6, (modelica_real)data->simulationInfo->realParameter[673], (modelica_real)data->simulationInfo->realParameter[674], (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678]);
  data->localData[0]->realVars[242] /* MaterialStream3._S_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp4, tmp5, data->simulationInfo->realParameter[751], data->simulationInfo->realParameter[753], data->localData[0]->realVars[249] /* MaterialStream3._T variable */, 101325.0, data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */, data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ ,&data->localData[0]->realVars[244] /* MaterialStream3._S_pc[3,1] variable */);
  TRACE_POP
}
/*
 equation index: 838
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_p[3] = MaterialStream3.x_pc[3,1] * MaterialStream3.Cp_pc[3,1] + MaterialStream3.x_pc[3,2] * MaterialStream3.Cp_pc[3,2]
 */
void Flowsheet_eqFunction_838(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,838};
  data->localData[0]->realVars[187] /* MaterialStream3._Cp_p[3] variable */ = (data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */) * (data->localData[0]->realVars[192] /* MaterialStream3._Cp_pc[3,1] variable */) + (data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */) * (data->localData[0]->realVars[193] /* MaterialStream3._Cp_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 839
 type: SIMPLE_ASSIGN
 MaterialStream3._F_pc[2,2] = MaterialStream3.x_pc[2,2] * MaterialStream3.F_p[2]
 */
void Flowsheet_eqFunction_839(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,839};
  data->localData[0]->realVars[203] /* MaterialStream3._F_pc[2,2] variable */ = (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */) * (data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 840
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_pc[2,2] = MaterialStream3.F_pc[2,2] * MaterialStream3.C[2].MW
 */
void Flowsheet_eqFunction_840(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,840};
  data->localData[0]->realVars[212] /* MaterialStream3._Fm_pc[2,2] variable */ = (data->localData[0]->realVars[203] /* MaterialStream3._F_pc[2,2] variable */) * (data->simulationInfo->realParameter[738]);
  TRACE_POP
}
/*
 equation index: 841
 type: ALGORITHM
 
   MaterialStream3.MW_p[3] := $START.MaterialStream3.MW_p[3];
   MaterialStream3.MW_p[2] := $START.MaterialStream3.MW_p[2];
   MaterialStream3.MW_p[1] := $START.MaterialStream3.MW_p[1];
   for i in 1:2 loop
     MaterialStream3.MW_p[:] := {MaterialStream3.MW_p[1] + MaterialStream3.x_pc[1,i] * MaterialStream3.C[i].MW, MaterialStream3.MW_p[2] + MaterialStream3.x_pc[2,i] * MaterialStream3.C[i].MW, MaterialStream3.MW_p[3] + MaterialStream3.x_pc[3,i] * MaterialStream3.C[i].MW};
   end for;
 */
void Flowsheet_eqFunction_841(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,841};
  real_array tmp6;
  index_spec_t tmp7;
  real_array tmp8;
  modelica_integer tmp9;
  modelica_integer tmp10;
  modelica_integer tmp11;
  data->localData[0]->realVars[231] /* MaterialStream3._MW_p[3] variable */ = data->modelData->realVarsData[231].attribute /* MaterialStream3._MW_p[3] variable */.start;

  data->localData[0]->realVars[230] /* MaterialStream3._MW_p[2] variable */ = data->modelData->realVarsData[230].attribute /* MaterialStream3._MW_p[2] variable */.start;

  data->localData[0]->realVars[229] /* MaterialStream3._MW_p[1] variable */ = data->modelData->realVarsData[229].attribute /* MaterialStream3._MW_p[1] variable */.start;

  tmp9 = ((modelica_integer) 1); tmp10 = 1; tmp11 = ((modelica_integer) 2);
  if(!tmp10)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert_withEquationIndexes(threadData, info, equationIndexes, "assertion range step != 0 failed");
  }
  else if(!(((tmp10 > 0) && (tmp9 > tmp11)) || ((tmp10 < 0) && (tmp9 < tmp11))))
  {
    modelica_integer $Pi;
    for($Pi = ((modelica_integer) 1); in_range_integer($Pi, tmp9, tmp11); $Pi += tmp10)
    {
      array_alloc_scalar_real_array(&tmp6, 3, (modelica_real)data->localData[0]->realVars[229] /* MaterialStream3._MW_p[1] variable */ + ((&data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 1), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[737])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[230] /* MaterialStream3._MW_p[2] variable */ + ((&data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 2), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[737])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]), (modelica_real)data->localData[0]->realVars[231] /* MaterialStream3._MW_p[3] variable */ + ((&data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */)[calc_base_index_dims_subs(2, 3, 2, ((modelica_integer) 3), (modelica_integer)$Pi)]) * ((&data->simulationInfo->realParameter[737])[calc_base_index_dims_subs(1, 2, (modelica_integer)$Pi)]));
      create_index_spec(&tmp7, 1, (1), (int*)0, 'W');
      real_array_create(&tmp8, (modelica_real*)&data->localData[0]->realVars[229] /* MaterialStream3._MW_p[1] variable */, 1, 3);
      indexed_assign_real_array(tmp6, &tmp8, &tmp7);
    }
  }
  TRACE_POP
}
/*
 equation index: 842
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_p[2] = MaterialStream3.F_p[2] * MaterialStream3.MW_p[2]
 */
void Flowsheet_eqFunction_842(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,842};
  data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */ = (data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */) * (data->localData[0]->realVars[230] /* MaterialStream3._MW_p[2] variable */);
  TRACE_POP
}
/*
 equation index: 843
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_p[3] = MaterialStream3.F_p[3] * MaterialStream3.MW_p[3]
 */
void Flowsheet_eqFunction_843(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,843};
  data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */ = (data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */) * (data->localData[0]->realVars[231] /* MaterialStream3._MW_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 844
 type: SIMPLE_ASSIGN
 MaterialStream3._Fm_p[1] = 200.0 * MaterialStream3.MW_p[1]
 */
void Flowsheet_eqFunction_844(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,844};
  data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */ = (200.0) * (data->localData[0]->realVars[229] /* MaterialStream3._MW_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 845
 type: SIMPLE_ASSIGN
 MaterialStream3._xm_pc[1,2] = DIVISION(MaterialStream3.Fm_pc[1,2], MaterialStream3.Fm_p[1])
 */
void Flowsheet_eqFunction_845(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,845};
  data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */ = DIVISION_SIM(data->localData[0]->realVars[210] /* MaterialStream3._Fm_pc[1,2] variable */,data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */,"MaterialStream3.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 846
 type: SIMPLE_ASSIGN
 MaterialStream3._xmvap = DIVISION(MaterialStream3.Fm_p[3], MaterialStream3.Fm_p[1])
 */
void Flowsheet_eqFunction_846(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,846};
  data->localData[0]->realVars[274] /* MaterialStream3._xmvap variable */ = DIVISION_SIM(data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */,data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */,"MaterialStream3.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 847
 type: LINEAR
 
 <var>MaterialStream3._xm_pc[2,1]</var>
 <var>MaterialStream3._xm_pc[3,2]</var>
 <var>MaterialStream3._xm_pc[2,2]</var>
 <var>MaterialStream3._xm_pc[3,1]</var>
 <var>MaterialStream3._xm_pc[1,1]</var>
 <row>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then MaterialStream3.Fm_pc[1,1] else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[3,1] else MaterialStream3.Fm_pc[1,1]</cell>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[1,1] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[2,2] else 0.0</cell>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then -MaterialStream3.xm_pc[1,2] else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[3,2] else -MaterialStream3.xm_pc[1,2]</cell>
   <cell>if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then MaterialStream3.Fm_pc[2,1] else 0.0</cell>
 </row>
 <matrix>
   <cell row="0" col="3">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then -0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[3] else -0.0)</residual>
   </cell><cell row="0" col="4">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then -MaterialStream3.Fm_p[1] else if 101325.0 >= MaterialStream3.Pdew then -0.0 else -MaterialStream3.Fm_p[1])</residual>
   </cell><cell row="1" col="0">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="1" col="3">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="1" col="4">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[1] else 0.0)</residual>
   </cell><cell row="2" col="0">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="2" col="2">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[2] else 0.0)</residual>
   </cell><cell row="2" col="3">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -0.0 else 1.0)</residual>
   </cell><cell row="2" col="4">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then -1.0 else if 101325.0 >= MaterialStream3.Pdew then -0.0 else -1.0)</residual>
   </cell><cell row="3" col="1">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[3] else 1.0)</residual>
   </cell><cell row="3" col="2">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="4" col="0">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -MaterialStream3.Fm_p[2] else 0.0)</residual>
   </cell><cell row="4" col="1">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 1.0 else -0.0)</residual>
   </cell><cell row="4" col="2">
     <residual>-(if 101325.0 >= MaterialStream3.Pbubl then 0.0 else if 101325.0 >= MaterialStream3.Pdew then -0.0 else 1.0)</residual>
   </cell>
 </matrix>
 */
void Flowsheet_eqFunction_847(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,847};
  /* Linear equation system */
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving linear system 847 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  data->simulationInfo->linearSystemData[9].x[0] = data->localData[1]->realVars[269] /* MaterialStream3._xm_pc[2,1] variable */;
  data->simulationInfo->linearSystemData[9].x[1] = data->localData[1]->realVars[272] /* MaterialStream3._xm_pc[3,2] variable */;
  data->simulationInfo->linearSystemData[9].x[2] = data->localData[1]->realVars[270] /* MaterialStream3._xm_pc[2,2] variable */;
  data->simulationInfo->linearSystemData[9].x[3] = data->localData[1]->realVars[271] /* MaterialStream3._xm_pc[3,1] variable */;
  data->simulationInfo->linearSystemData[9].x[4] = data->localData[1]->realVars[267] /* MaterialStream3._xm_pc[1,1] variable */;
  retValue = solve_linear_system(data, threadData, 9);
  
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,847};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving linear system 847 failed at time=%.15g.\nFor more information please use -lv LOG_LS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[269] /* MaterialStream3._xm_pc[2,1] variable */ = data->simulationInfo->linearSystemData[9].x[0];
  data->localData[0]->realVars[272] /* MaterialStream3._xm_pc[3,2] variable */ = data->simulationInfo->linearSystemData[9].x[1];
  data->localData[0]->realVars[270] /* MaterialStream3._xm_pc[2,2] variable */ = data->simulationInfo->linearSystemData[9].x[2];
  data->localData[0]->realVars[271] /* MaterialStream3._xm_pc[3,1] variable */ = data->simulationInfo->linearSystemData[9].x[3];
  data->localData[0]->realVars[267] /* MaterialStream3._xm_pc[1,1] variable */ = data->simulationInfo->linearSystemData[9].x[4];
  TRACE_POP
}
/*
 equation index: 848
 type: SIMPLE_ASSIGN
 MaterialStream3._xmliq = DIVISION(MaterialStream3.Fm_p[2], MaterialStream3.Fm_p[1])
 */
void Flowsheet_eqFunction_848(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,848};
  data->localData[0]->realVars[273] /* MaterialStream3._xmliq variable */ = DIVISION_SIM(data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */,data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */,"MaterialStream3.Fm_p[1]",equationIndexes);
  TRACE_POP
}
/*
 equation index: 849
 type: ALGORITHM
 
   (MaterialStream3.S_pc[2,2], MaterialStream3.S_pc[3,2]) := Simulator.Files.ThermodynamicFunctions.SId({MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, {MaterialStream3.C[2].HOV[1], MaterialStream3.C[2].HOV[2], MaterialStream3.C[2].HOV[3], MaterialStream3.C[2].HOV[4], MaterialStream3.C[2].HOV[5], MaterialStream3.C[2].HOV[6]}, MaterialStream3.C[2].Tb, MaterialStream3.C[2].Tc, MaterialStream3.T, 101325.0, MaterialStream3.x_pc[2,2], MaterialStream3.x_pc[3,2]);
 */
void Flowsheet_eqFunction_849(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,849};
  real_array tmp12;
  real_array tmp13;
  array_alloc_scalar_real_array(&tmp12, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  array_alloc_scalar_real_array(&tmp13, 6, (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680], (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684]);
  data->localData[0]->realVars[243] /* MaterialStream3._S_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, tmp12, tmp13, data->simulationInfo->realParameter[752], data->simulationInfo->realParameter[754], data->localData[0]->realVars[249] /* MaterialStream3._T variable */, 101325.0, data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */, data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ ,&data->localData[0]->realVars[245] /* MaterialStream3._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 850
 type: SIMPLE_ASSIGN
 MaterialStream3._S_p[3] = MaterialStream3.x_pc[3,1] * MaterialStream3.S_pc[3,1] + MaterialStream3.x_pc[3,2] * MaterialStream3.S_pc[3,2]
 */
void Flowsheet_eqFunction_850(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,850};
  data->localData[0]->realVars[239] /* MaterialStream3._S_p[3] variable */ = (data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */) * (data->localData[0]->realVars[244] /* MaterialStream3._S_pc[3,1] variable */) + (data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */) * (data->localData[0]->realVars[245] /* MaterialStream3._S_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 851
 type: SIMPLE_ASSIGN
 MaterialStream3._S_p[2] = MaterialStream3.x_pc[2,1] * MaterialStream3.S_pc[2,1] + MaterialStream3.x_pc[2,2] * MaterialStream3.S_pc[2,2]
 */
void Flowsheet_eqFunction_851(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,851};
  data->localData[0]->realVars[238] /* MaterialStream3._S_p[2] variable */ = (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */) * (data->localData[0]->realVars[242] /* MaterialStream3._S_pc[2,1] variable */) + (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */) * (data->localData[0]->realVars[243] /* MaterialStream3._S_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 852
 type: SIMPLE_ASSIGN
 MaterialStream3._S_p[1] = MaterialStream3.xliq * MaterialStream3.S_p[2] + MaterialStream3.xvap * MaterialStream3.S_p[3]
 */
void Flowsheet_eqFunction_852(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,852};
  data->localData[0]->realVars[237] /* MaterialStream3._S_p[1] variable */ = (data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */) * (data->localData[0]->realVars[238] /* MaterialStream3._S_p[2] variable */) + (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (data->localData[0]->realVars[239] /* MaterialStream3._S_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 853
 type: SIMPLE_ASSIGN
 MaterialStream3._S_pc[1,1] = MaterialStream3.x_pc[1,1] * MaterialStream3.S_p[1]
 */
void Flowsheet_eqFunction_853(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,853};
  data->localData[0]->realVars[240] /* MaterialStream3._S_pc[1,1] variable */ = (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (data->localData[0]->realVars[237] /* MaterialStream3._S_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 854
 type: SIMPLE_ASSIGN
 MaterialStream3._S_pc[1,2] = MaterialStream3.x_pc[1,2] * MaterialStream3.S_p[1]
 */
void Flowsheet_eqFunction_854(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,854};
  data->localData[0]->realVars[241] /* MaterialStream3._S_pc[1,2] variable */ = (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (data->localData[0]->realVars[237] /* MaterialStream3._S_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 855
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_p[2] = MaterialStream3.x_pc[2,1] * MaterialStream3.Cp_pc[2,1] + MaterialStream3.x_pc[2,2] * MaterialStream3.Cp_pc[2,2]
 */
void Flowsheet_eqFunction_855(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,855};
  data->localData[0]->realVars[186] /* MaterialStream3._Cp_p[2] variable */ = (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */) * (data->localData[0]->realVars[190] /* MaterialStream3._Cp_pc[2,1] variable */) + (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */) * (data->localData[0]->realVars[191] /* MaterialStream3._Cp_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 856
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_p[1] = MaterialStream3.xliq * MaterialStream3.Cp_p[2] + MaterialStream3.xvap * MaterialStream3.Cp_p[3]
 */
void Flowsheet_eqFunction_856(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,856};
  data->localData[0]->realVars[185] /* MaterialStream3._Cp_p[1] variable */ = (data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */) * (data->localData[0]->realVars[186] /* MaterialStream3._Cp_p[2] variable */) + (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (data->localData[0]->realVars[187] /* MaterialStream3._Cp_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 857
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[1,1] = MaterialStream3.x_pc[1,1] * MaterialStream3.Cp_p[1]
 */
void Flowsheet_eqFunction_857(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,857};
  data->localData[0]->realVars[188] /* MaterialStream3._Cp_pc[1,1] variable */ = (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (data->localData[0]->realVars[185] /* MaterialStream3._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 858
 type: SIMPLE_ASSIGN
 MaterialStream3._Cp_pc[1,2] = MaterialStream3.x_pc[1,2] * MaterialStream3.Cp_p[1]
 */
void Flowsheet_eqFunction_858(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,858};
  data->localData[0]->realVars[189] /* MaterialStream3._Cp_pc[1,2] variable */ = (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (data->localData[0]->realVars[185] /* MaterialStream3._Cp_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 859
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[1,1] = MaterialStream3.x_pc[1,1] * MaterialStream3.H_p[1]
 */
void Flowsheet_eqFunction_859(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,859};
  data->localData[0]->realVars[218] /* MaterialStream3._H_pc[1,1] variable */ = (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 860
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[1,2] = MaterialStream3.x_pc[1,2] * MaterialStream3.H_p[1]
 */
void Flowsheet_eqFunction_860(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,860};
  data->localData[0]->realVars[219] /* MaterialStream3._H_pc[1,2] variable */ = (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 861
 type: SIMPLE_ASSIGN
 MaterialStream2._S_p[1] = MaterialStream2.xliq * MaterialStream2.S_p[2] + Mixer1.xvapin_s[2] * MaterialStream2.S_p[3]
 */
void Flowsheet_eqFunction_861(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,861};
  data->localData[0]->realVars[147] /* MaterialStream2._S_p[1] variable */ = (data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */) * (data->localData[0]->realVars[148] /* MaterialStream2._S_p[2] variable */) + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (data->localData[0]->realVars[149] /* MaterialStream2._S_p[3] variable */);
  TRACE_POP
}
/*
 equation index: 862
 type: SIMPLE_ASSIGN
 MaterialStream2._S_pc[1,1] = MaterialStream2.x_pc[1,1] * MaterialStream2.S_p[1]
 */
void Flowsheet_eqFunction_862(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,862};
  data->localData[0]->realVars[150] /* MaterialStream2._S_pc[1,1] variable */ = (data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (data->localData[0]->realVars[147] /* MaterialStream2._S_p[1] variable */);
  TRACE_POP
}
/*
 equation index: 863
 type: SIMPLE_ASSIGN
 MaterialStream2._S_pc[1,2] = MaterialStream2.x_pc[1,2] * MaterialStream2.S_p[1]
 */
void Flowsheet_eqFunction_863(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,863};
  data->localData[0]->realVars[151] /* MaterialStream2._S_pc[1,2] variable */ = (data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (data->localData[0]->realVars[147] /* MaterialStream2._S_p[1] variable */);
  TRACE_POP
}


int Flowsheet_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Flowsheet_functionLocalKnownVars(data, threadData);
  Flowsheet_eqFunction_698(data, threadData);

  Flowsheet_eqFunction_699(data, threadData);

  Flowsheet_eqFunction_700(data, threadData);

  Flowsheet_eqFunction_701(data, threadData);

  Flowsheet_eqFunction_718(data, threadData);

  Flowsheet_eqFunction_719(data, threadData);

  Flowsheet_eqFunction_720(data, threadData);

  Flowsheet_eqFunction_721(data, threadData);

  Flowsheet_eqFunction_722(data, threadData);

  Flowsheet_eqFunction_723(data, threadData);

  Flowsheet_eqFunction_724(data, threadData);

  Flowsheet_eqFunction_725(data, threadData);

  Flowsheet_eqFunction_726(data, threadData);

  Flowsheet_eqFunction_727(data, threadData);

  Flowsheet_eqFunction_728(data, threadData);

  Flowsheet_eqFunction_729(data, threadData);

  Flowsheet_eqFunction_730(data, threadData);

  Flowsheet_eqFunction_731(data, threadData);

  Flowsheet_eqFunction_732(data, threadData);

  Flowsheet_eqFunction_733(data, threadData);

  Flowsheet_eqFunction_734(data, threadData);

  Flowsheet_eqFunction_735(data, threadData);

  Flowsheet_eqFunction_736(data, threadData);

  Flowsheet_eqFunction_737(data, threadData);

  Flowsheet_eqFunction_738(data, threadData);

  Flowsheet_eqFunction_739(data, threadData);

  Flowsheet_eqFunction_740(data, threadData);

  Flowsheet_eqFunction_741(data, threadData);

  Flowsheet_eqFunction_742(data, threadData);

  Flowsheet_eqFunction_743(data, threadData);

  Flowsheet_eqFunction_744(data, threadData);

  Flowsheet_eqFunction_745(data, threadData);

  Flowsheet_eqFunction_746(data, threadData);

  Flowsheet_eqFunction_747(data, threadData);

  Flowsheet_eqFunction_748(data, threadData);

  Flowsheet_eqFunction_749(data, threadData);

  Flowsheet_eqFunction_750(data, threadData);

  Flowsheet_eqFunction_751(data, threadData);

  Flowsheet_eqFunction_768(data, threadData);

  Flowsheet_eqFunction_769(data, threadData);

  Flowsheet_eqFunction_770(data, threadData);

  Flowsheet_eqFunction_771(data, threadData);

  Flowsheet_eqFunction_772(data, threadData);

  Flowsheet_eqFunction_773(data, threadData);

  Flowsheet_eqFunction_774(data, threadData);

  Flowsheet_eqFunction_775(data, threadData);

  Flowsheet_eqFunction_776(data, threadData);

  Flowsheet_eqFunction_777(data, threadData);

  Flowsheet_eqFunction_778(data, threadData);

  Flowsheet_eqFunction_779(data, threadData);

  Flowsheet_eqFunction_780(data, threadData);

  Flowsheet_eqFunction_781(data, threadData);

  Flowsheet_eqFunction_782(data, threadData);

  Flowsheet_eqFunction_783(data, threadData);

  Flowsheet_eqFunction_784(data, threadData);

  Flowsheet_eqFunction_785(data, threadData);

  Flowsheet_eqFunction_786(data, threadData);

  Flowsheet_eqFunction_787(data, threadData);

  Flowsheet_eqFunction_788(data, threadData);

  Flowsheet_eqFunction_789(data, threadData);

  Flowsheet_eqFunction_790(data, threadData);

  Flowsheet_eqFunction_791(data, threadData);

  Flowsheet_eqFunction_792(data, threadData);

  Flowsheet_eqFunction_793(data, threadData);

  Flowsheet_eqFunction_794(data, threadData);

  Flowsheet_eqFunction_795(data, threadData);

  Flowsheet_eqFunction_796(data, threadData);

  Flowsheet_eqFunction_797(data, threadData);

  Flowsheet_eqFunction_798(data, threadData);

  Flowsheet_eqFunction_799(data, threadData);

  Flowsheet_eqFunction_826(data, threadData);

  Flowsheet_eqFunction_827(data, threadData);

  Flowsheet_eqFunction_828(data, threadData);

  Flowsheet_eqFunction_829(data, threadData);

  Flowsheet_eqFunction_830(data, threadData);

  Flowsheet_eqFunction_831(data, threadData);

  Flowsheet_eqFunction_832(data, threadData);

  Flowsheet_eqFunction_833(data, threadData);

  Flowsheet_eqFunction_834(data, threadData);

  Flowsheet_eqFunction_835(data, threadData);

  Flowsheet_eqFunction_836(data, threadData);

  Flowsheet_eqFunction_837(data, threadData);

  Flowsheet_eqFunction_838(data, threadData);

  Flowsheet_eqFunction_839(data, threadData);

  Flowsheet_eqFunction_840(data, threadData);

  Flowsheet_eqFunction_841(data, threadData);

  Flowsheet_eqFunction_842(data, threadData);

  Flowsheet_eqFunction_843(data, threadData);

  Flowsheet_eqFunction_844(data, threadData);

  Flowsheet_eqFunction_845(data, threadData);

  Flowsheet_eqFunction_846(data, threadData);

  Flowsheet_eqFunction_847(data, threadData);

  Flowsheet_eqFunction_848(data, threadData);

  Flowsheet_eqFunction_849(data, threadData);

  Flowsheet_eqFunction_850(data, threadData);

  Flowsheet_eqFunction_851(data, threadData);

  Flowsheet_eqFunction_852(data, threadData);

  Flowsheet_eqFunction_853(data, threadData);

  Flowsheet_eqFunction_854(data, threadData);

  Flowsheet_eqFunction_855(data, threadData);

  Flowsheet_eqFunction_856(data, threadData);

  Flowsheet_eqFunction_857(data, threadData);

  Flowsheet_eqFunction_858(data, threadData);

  Flowsheet_eqFunction_859(data, threadData);

  Flowsheet_eqFunction_860(data, threadData);

  Flowsheet_eqFunction_861(data, threadData);

  Flowsheet_eqFunction_862(data, threadData);

  Flowsheet_eqFunction_863(data, threadData);
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
  data->modelData->modelDir = "C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator";
  data->modelData->modelGUID = "{e7667160-3f08-4fef-b699-c58c7f5826df}";
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
  data->modelData->nVariablesReal = 278;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 1144;
  data->modelData->nParametersInteger = 27;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 25;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 132;
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
  data->modelData->modelDataXml.nEquations = 1943;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 10;
  data->modelData->nNonLinearSystems = 14;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 12;
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

