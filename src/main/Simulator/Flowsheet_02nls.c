/* Non Linear Systems */
#include "Flowsheet_model.h"
#include "Flowsheet_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
 equation index: 43
 type: SIMPLE_ASSIGN
 MaterialStream3._Psatdg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[2].VP[1], MaterialStream3.C[2].VP[2], MaterialStream3.C[2].VP[3], MaterialStream3.C[2].VP[4], MaterialStream3.C[2].VP[5], MaterialStream3.C[2].VP[6]}, MaterialStream3.Tdg)
 */
void Flowsheet_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[767], (modelica_real)data->simulationInfo->realParameter[768], (modelica_real)data->simulationInfo->realParameter[769], (modelica_real)data->simulationInfo->realParameter[770], (modelica_real)data->simulationInfo->realParameter[771], (modelica_real)data->simulationInfo->realParameter[772]);
  data->simulationInfo->realParameter[832] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[843]);
  TRACE_POP
}
/*
 equation index: 44
 type: SIMPLE_ASSIGN
 MaterialStream3._Psatdg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[1].VP[1], MaterialStream3.C[1].VP[2], MaterialStream3.C[1].VP[3], MaterialStream3.C[1].VP[4], MaterialStream3.C[1].VP[5], MaterialStream3.C[1].VP[6]}, MaterialStream3.Tdg)
 */
void Flowsheet_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[761], (modelica_real)data->simulationInfo->realParameter[762], (modelica_real)data->simulationInfo->realParameter[763], (modelica_real)data->simulationInfo->realParameter[764], (modelica_real)data->simulationInfo->realParameter[765], (modelica_real)data->simulationInfo->realParameter[766]);
  data->simulationInfo->realParameter[831] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[843]);
  TRACE_POP
}

void residualFunc46(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,46};
  /* iteration variables */
  data->simulationInfo->realParameter[843] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_43(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_44(data, threadData);
  /* body */
  res[0] = 1.0 - ((data->simulationInfo->realParameter[826]) * (DIVISION_SIM(data->simulationInfo->realParameter[848],data->simulationInfo->realParameter[831],"MaterialStream3.Psatdg[1]",equationIndexes) + DIVISION_SIM(data->simulationInfo->realParameter[849],data->simulationInfo->realParameter[832],"MaterialStream3.Psatdg[2]",equationIndexes)));
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS46(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS46(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream3.Tdg */
  sysData->nominal[i] = data->modelData->realParameterData[843].attribute /* MaterialStream3._Tdg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[843].attribute /* MaterialStream3._Tdg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[843].attribute /* MaterialStream3._Tdg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS46(sysData);
}

void getIterationVarsNLS46(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[843];
}


/* inner equations */

/*
 equation index: 47
 type: SIMPLE_ASSIGN
 MaterialStream3._Psatbg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[2].VP[1], MaterialStream3.C[2].VP[2], MaterialStream3.C[2].VP[3], MaterialStream3.C[2].VP[4], MaterialStream3.C[2].VP[5], MaterialStream3.C[2].VP[6]}, MaterialStream3.Tbg)
 */
void Flowsheet_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[767], (modelica_real)data->simulationInfo->realParameter[768], (modelica_real)data->simulationInfo->realParameter[769], (modelica_real)data->simulationInfo->realParameter[770], (modelica_real)data->simulationInfo->realParameter[771], (modelica_real)data->simulationInfo->realParameter[772]);
  data->simulationInfo->realParameter[830] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[840]);
  TRACE_POP
}
/*
 equation index: 48
 type: SIMPLE_ASSIGN
 MaterialStream3._Psatbg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[1].VP[1], MaterialStream3.C[1].VP[2], MaterialStream3.C[1].VP[3], MaterialStream3.C[1].VP[4], MaterialStream3.C[1].VP[5], MaterialStream3.C[1].VP[6]}, MaterialStream3.Tbg)
 */
void Flowsheet_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[761], (modelica_real)data->simulationInfo->realParameter[762], (modelica_real)data->simulationInfo->realParameter[763], (modelica_real)data->simulationInfo->realParameter[764], (modelica_real)data->simulationInfo->realParameter[765], (modelica_real)data->simulationInfo->realParameter[766]);
  data->simulationInfo->realParameter[829] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[840]);
  TRACE_POP
}

void residualFunc50(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,50};
  /* iteration variables */
  data->simulationInfo->realParameter[840] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_47(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_48(data, threadData);
  /* body */
  res[0] = (data->simulationInfo->realParameter[849]) * (data->simulationInfo->realParameter[830]) + (data->simulationInfo->realParameter[848]) * (data->simulationInfo->realParameter[829]) - data->simulationInfo->realParameter[826];
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS50(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS50(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream3.Tbg */
  sysData->nominal[i] = data->modelData->realParameterData[840].attribute /* MaterialStream3._Tbg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[840].attribute /* MaterialStream3._Tbg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[840].attribute /* MaterialStream3._Tbg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS50(sysData);
}

void getIterationVarsNLS50(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[840];
}


/* inner equations */

/*
 equation index: 152
 type: SIMPLE_ASSIGN
 Mixer1._Psatdg[1] = Simulator.Files.ThermodynamicFunctions.Psat({Mixer1.C[1].VP[1], Mixer1.C[1].VP[2], Mixer1.C[1].VP[3], Mixer1.C[1].VP[4], Mixer1.C[1].VP[5], Mixer1.C[1].VP[6]}, Mixer1.Tdg)
 */
void Flowsheet_eqFunction_152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,152};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[968], (modelica_real)data->simulationInfo->realParameter[969], (modelica_real)data->simulationInfo->realParameter[970], (modelica_real)data->simulationInfo->realParameter[971], (modelica_real)data->simulationInfo->realParameter[972], (modelica_real)data->simulationInfo->realParameter[973]);
  data->simulationInfo->realParameter[1038] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[1050]);
  TRACE_POP
}
/*
 equation index: 153
 type: SIMPLE_ASSIGN
 Mixer1._Psatdg[2] = Simulator.Files.ThermodynamicFunctions.Psat({Mixer1.C[2].VP[1], Mixer1.C[2].VP[2], Mixer1.C[2].VP[3], Mixer1.C[2].VP[4], Mixer1.C[2].VP[5], Mixer1.C[2].VP[6]}, Mixer1.Tdg)
 */
void Flowsheet_eqFunction_153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,153};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[974], (modelica_real)data->simulationInfo->realParameter[975], (modelica_real)data->simulationInfo->realParameter[976], (modelica_real)data->simulationInfo->realParameter[977], (modelica_real)data->simulationInfo->realParameter[978], (modelica_real)data->simulationInfo->realParameter[979]);
  data->simulationInfo->realParameter[1039] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[1050]);
  TRACE_POP
}

void residualFunc155(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,155};
  /* iteration variables */
  data->simulationInfo->realParameter[1050] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_152(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_153(data, threadData);
  /* body */
  res[0] = 1.0 - ((data->simulationInfo->realParameter[1033]) * (DIVISION_SIM(data->simulationInfo->realParameter[1055],data->simulationInfo->realParameter[1038],"Mixer1.Psatdg[1]",equationIndexes) + DIVISION_SIM(data->simulationInfo->realParameter[1056],data->simulationInfo->realParameter[1039],"Mixer1.Psatdg[2]",equationIndexes)));
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS155(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS155(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Mixer1.Tdg */
  sysData->nominal[i] = data->modelData->realParameterData[1050].attribute /* Mixer1._Tdg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[1050].attribute /* Mixer1._Tdg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[1050].attribute /* Mixer1._Tdg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS155(sysData);
}

void getIterationVarsNLS155(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[1050];
}


/* inner equations */

/*
 equation index: 156
 type: SIMPLE_ASSIGN
 Mixer1._Psatbg[2] = Simulator.Files.ThermodynamicFunctions.Psat({Mixer1.C[2].VP[1], Mixer1.C[2].VP[2], Mixer1.C[2].VP[3], Mixer1.C[2].VP[4], Mixer1.C[2].VP[5], Mixer1.C[2].VP[6]}, Mixer1.Tbg)
 */
void Flowsheet_eqFunction_156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,156};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[974], (modelica_real)data->simulationInfo->realParameter[975], (modelica_real)data->simulationInfo->realParameter[976], (modelica_real)data->simulationInfo->realParameter[977], (modelica_real)data->simulationInfo->realParameter[978], (modelica_real)data->simulationInfo->realParameter[979]);
  data->simulationInfo->realParameter[1037] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[1047]);
  TRACE_POP
}
/*
 equation index: 157
 type: SIMPLE_ASSIGN
 Mixer1._Psatbg[1] = Simulator.Files.ThermodynamicFunctions.Psat({Mixer1.C[1].VP[1], Mixer1.C[1].VP[2], Mixer1.C[1].VP[3], Mixer1.C[1].VP[4], Mixer1.C[1].VP[5], Mixer1.C[1].VP[6]}, Mixer1.Tbg)
 */
void Flowsheet_eqFunction_157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,157};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[968], (modelica_real)data->simulationInfo->realParameter[969], (modelica_real)data->simulationInfo->realParameter[970], (modelica_real)data->simulationInfo->realParameter[971], (modelica_real)data->simulationInfo->realParameter[972], (modelica_real)data->simulationInfo->realParameter[973]);
  data->simulationInfo->realParameter[1036] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[1047]);
  TRACE_POP
}

void residualFunc159(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,159};
  /* iteration variables */
  data->simulationInfo->realParameter[1047] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_156(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_157(data, threadData);
  /* body */
  res[0] = (data->simulationInfo->realParameter[1056]) * (data->simulationInfo->realParameter[1037]) + (data->simulationInfo->realParameter[1055]) * (data->simulationInfo->realParameter[1036]) - data->simulationInfo->realParameter[1033];
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS159(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS159(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Mixer1.Tbg */
  sysData->nominal[i] = data->modelData->realParameterData[1047].attribute /* Mixer1._Tbg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[1047].attribute /* Mixer1._Tbg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[1047].attribute /* Mixer1._Tbg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS159(sysData);
}

void getIterationVarsNLS159(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[1047];
}


/* inner equations */

/*
 equation index: 240
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatdg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[2].VP[1], MaterialStream2.C[2].VP[2], MaterialStream2.C[2].VP[3], MaterialStream2.C[2].VP[4], MaterialStream2.C[2].VP[5], MaterialStream2.C[2].VP[6]}, MaterialStream2.Tdg)
 */
void Flowsheet_eqFunction_240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,240};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[560], (modelica_real)data->simulationInfo->realParameter[561], (modelica_real)data->simulationInfo->realParameter[562], (modelica_real)data->simulationInfo->realParameter[563], (modelica_real)data->simulationInfo->realParameter[564], (modelica_real)data->simulationInfo->realParameter[565]);
  data->simulationInfo->realParameter[625] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[636]);
  TRACE_POP
}
/*
 equation index: 241
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatdg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[1].VP[1], MaterialStream2.C[1].VP[2], MaterialStream2.C[1].VP[3], MaterialStream2.C[1].VP[4], MaterialStream2.C[1].VP[5], MaterialStream2.C[1].VP[6]}, MaterialStream2.Tdg)
 */
void Flowsheet_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[554], (modelica_real)data->simulationInfo->realParameter[555], (modelica_real)data->simulationInfo->realParameter[556], (modelica_real)data->simulationInfo->realParameter[557], (modelica_real)data->simulationInfo->realParameter[558], (modelica_real)data->simulationInfo->realParameter[559]);
  data->simulationInfo->realParameter[624] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[636]);
  TRACE_POP
}

void residualFunc243(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,243};
  /* iteration variables */
  data->simulationInfo->realParameter[636] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_240(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_241(data, threadData);
  /* body */
  res[0] = 1.0 - ((data->simulationInfo->realParameter[619]) * (DIVISION_SIM(data->simulationInfo->realParameter[641],data->simulationInfo->realParameter[624],"MaterialStream2.Psatdg[1]",equationIndexes) + DIVISION_SIM(data->simulationInfo->realParameter[642],data->simulationInfo->realParameter[625],"MaterialStream2.Psatdg[2]",equationIndexes)));
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS243(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS243(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream2.Tdg */
  sysData->nominal[i] = data->modelData->realParameterData[636].attribute /* MaterialStream2._Tdg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[636].attribute /* MaterialStream2._Tdg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[636].attribute /* MaterialStream2._Tdg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS243(sysData);
}

void getIterationVarsNLS243(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[636];
}


/* inner equations */

/*
 equation index: 244
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatbg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[2].VP[1], MaterialStream2.C[2].VP[2], MaterialStream2.C[2].VP[3], MaterialStream2.C[2].VP[4], MaterialStream2.C[2].VP[5], MaterialStream2.C[2].VP[6]}, MaterialStream2.Tbg)
 */
void Flowsheet_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[560], (modelica_real)data->simulationInfo->realParameter[561], (modelica_real)data->simulationInfo->realParameter[562], (modelica_real)data->simulationInfo->realParameter[563], (modelica_real)data->simulationInfo->realParameter[564], (modelica_real)data->simulationInfo->realParameter[565]);
  data->simulationInfo->realParameter[623] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[633]);
  TRACE_POP
}
/*
 equation index: 245
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatbg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[1].VP[1], MaterialStream2.C[1].VP[2], MaterialStream2.C[1].VP[3], MaterialStream2.C[1].VP[4], MaterialStream2.C[1].VP[5], MaterialStream2.C[1].VP[6]}, MaterialStream2.Tbg)
 */
void Flowsheet_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[554], (modelica_real)data->simulationInfo->realParameter[555], (modelica_real)data->simulationInfo->realParameter[556], (modelica_real)data->simulationInfo->realParameter[557], (modelica_real)data->simulationInfo->realParameter[558], (modelica_real)data->simulationInfo->realParameter[559]);
  data->simulationInfo->realParameter[622] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[633]);
  TRACE_POP
}

void residualFunc247(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,247};
  /* iteration variables */
  data->simulationInfo->realParameter[633] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_244(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_245(data, threadData);
  /* body */
  res[0] = (data->simulationInfo->realParameter[642]) * (data->simulationInfo->realParameter[623]) + (data->simulationInfo->realParameter[641]) * (data->simulationInfo->realParameter[622]) - data->simulationInfo->realParameter[619];
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS247(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS247(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream2.Tbg */
  sysData->nominal[i] = data->modelData->realParameterData[633].attribute /* MaterialStream2._Tbg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[633].attribute /* MaterialStream2._Tbg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[633].attribute /* MaterialStream2._Tbg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS247(sysData);
}

void getIterationVarsNLS247(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[633];
}


/* inner equations */

/*
 equation index: 346
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatdg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[2].VP[1], MaterialStream1.C[2].VP[2], MaterialStream1.C[2].VP[3], MaterialStream1.C[2].VP[4], MaterialStream1.C[2].VP[5], MaterialStream1.C[2].VP[6]}, MaterialStream1.Tdg)
 */
void Flowsheet_eqFunction_346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,346};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[353], (modelica_real)data->simulationInfo->realParameter[354], (modelica_real)data->simulationInfo->realParameter[355], (modelica_real)data->simulationInfo->realParameter[356], (modelica_real)data->simulationInfo->realParameter[357], (modelica_real)data->simulationInfo->realParameter[358]);
  data->simulationInfo->realParameter[418] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[429]);
  TRACE_POP
}
/*
 equation index: 347
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatdg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[1].VP[1], MaterialStream1.C[1].VP[2], MaterialStream1.C[1].VP[3], MaterialStream1.C[1].VP[4], MaterialStream1.C[1].VP[5], MaterialStream1.C[1].VP[6]}, MaterialStream1.Tdg)
 */
void Flowsheet_eqFunction_347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,347};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[347], (modelica_real)data->simulationInfo->realParameter[348], (modelica_real)data->simulationInfo->realParameter[349], (modelica_real)data->simulationInfo->realParameter[350], (modelica_real)data->simulationInfo->realParameter[351], (modelica_real)data->simulationInfo->realParameter[352]);
  data->simulationInfo->realParameter[417] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[429]);
  TRACE_POP
}

void residualFunc349(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,349};
  /* iteration variables */
  data->simulationInfo->realParameter[429] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_346(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_347(data, threadData);
  /* body */
  res[0] = 1.0 - ((data->simulationInfo->realParameter[412]) * (DIVISION_SIM(data->simulationInfo->realParameter[434],data->simulationInfo->realParameter[417],"MaterialStream1.Psatdg[1]",equationIndexes) + DIVISION_SIM(data->simulationInfo->realParameter[435],data->simulationInfo->realParameter[418],"MaterialStream1.Psatdg[2]",equationIndexes)));
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS349(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS349(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream1.Tdg */
  sysData->nominal[i] = data->modelData->realParameterData[429].attribute /* MaterialStream1._Tdg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[429].attribute /* MaterialStream1._Tdg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[429].attribute /* MaterialStream1._Tdg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS349(sysData);
}

void getIterationVarsNLS349(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[429];
}


/* inner equations */

/*
 equation index: 350
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatbg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[2].VP[1], MaterialStream1.C[2].VP[2], MaterialStream1.C[2].VP[3], MaterialStream1.C[2].VP[4], MaterialStream1.C[2].VP[5], MaterialStream1.C[2].VP[6]}, MaterialStream1.Tbg)
 */
void Flowsheet_eqFunction_350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,350};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[353], (modelica_real)data->simulationInfo->realParameter[354], (modelica_real)data->simulationInfo->realParameter[355], (modelica_real)data->simulationInfo->realParameter[356], (modelica_real)data->simulationInfo->realParameter[357], (modelica_real)data->simulationInfo->realParameter[358]);
  data->simulationInfo->realParameter[416] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[426]);
  TRACE_POP
}
/*
 equation index: 351
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatbg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[1].VP[1], MaterialStream1.C[1].VP[2], MaterialStream1.C[1].VP[3], MaterialStream1.C[1].VP[4], MaterialStream1.C[1].VP[5], MaterialStream1.C[1].VP[6]}, MaterialStream1.Tbg)
 */
void Flowsheet_eqFunction_351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,351};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[347], (modelica_real)data->simulationInfo->realParameter[348], (modelica_real)data->simulationInfo->realParameter[349], (modelica_real)data->simulationInfo->realParameter[350], (modelica_real)data->simulationInfo->realParameter[351], (modelica_real)data->simulationInfo->realParameter[352]);
  data->simulationInfo->realParameter[415] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[426]);
  TRACE_POP
}

void residualFunc353(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,353};
  /* iteration variables */
  data->simulationInfo->realParameter[426] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_350(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_351(data, threadData);
  /* body */
  res[0] = (data->simulationInfo->realParameter[435]) * (data->simulationInfo->realParameter[416]) + (data->simulationInfo->realParameter[434]) * (data->simulationInfo->realParameter[415]) - data->simulationInfo->realParameter[412];
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS353(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS353(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream1.Tbg */
  sysData->nominal[i] = data->modelData->realParameterData[426].attribute /* MaterialStream1._Tbg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[426].attribute /* MaterialStream1._Tbg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[426].attribute /* MaterialStream1._Tbg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS353(sysData);
}

void getIterationVarsNLS353(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[426];
}


/* inner equations */

/*
 equation index: 467
 type: SIMPLE_ASSIGN
 MaterialStream1._xliq = 1.0 - Mixer1.xvapin_s[1]
 */
void Flowsheet_eqFunction_467(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,467};
  data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */ = 1.0 - data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */;
  TRACE_POP
}
/*
 equation index: 468
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[2] = 100.0 * MaterialStream1.xliq
 */
void Flowsheet_eqFunction_468(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,468};
  data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */ = (100.0) * (data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */);
  TRACE_POP
}
/*
 equation index: 469
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[3] = 100.0 * Mixer1.xvapin_s[1]
 */
void Flowsheet_eqFunction_469(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,469};
  data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */ = (100.0) * (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */);
  TRACE_POP
}

void residualFunc483(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,483};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  /* iteration variables */
  data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */ = xloc[0];
  data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ = xloc[1];
  data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ = xloc[2];
  data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */ = xloc[3];
  data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */ = xloc[4];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_467(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_468(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_469(data, threadData);
  /* body */
  tmp0 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */;
  }
  else
  {
    tmp1 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp3 = (tmp1?data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ - ((data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */) * (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */)):data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */);
  }
  res[0] = tmp3;

  tmp4 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */;
  }
  else
  {
    tmp5 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp7 = (tmp5?data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (-1.0 + data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */),"1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[1])",equationIndexes):data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */);
  }
  res[1] = tmp7;

  tmp8 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */;
  }
  else
  {
    tmp9 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp11 = (tmp9?data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ - ((data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */) * (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */)):data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */);
  }
  res[2] = tmp11;

  tmp12 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */ - data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */;
  }
  else
  {
    tmp13 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp15 = (tmp13?data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (-1.0 + data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */),"1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[2])",equationIndexes):data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ - data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */);
  }
  res[3] = tmp15;

  tmp16 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */ - data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */;
  }
  else
  {
    tmp17 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp19 = (tmp17?data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ + data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ - data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */);
  }
  res[4] = tmp19;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS483(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+5] = {0,3,3,3,4,3};
  const int rowIndex[16] = {1,2,3,0,3,4,1,2,4,1,2,3,4,0,1,3};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(16*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 16;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  inSysData->sparsePattern.maxColors = 5;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 16*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[4] = 1;
  inSysData->sparsePattern.colorCols[3] = 2;
  inSysData->sparsePattern.colorCols[2] = 3;
  inSysData->sparsePattern.colorCols[1] = 4;
  inSysData->sparsePattern.colorCols[0] = 5;
}
void initializeStaticDataNLS483(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Mixer1.xvapin_s[1] */
  sysData->nominal[i] = data->modelData->realVarsData[276].attribute /* Mixer1._xvapin_s[1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[276].attribute /* Mixer1._xvapin_s[1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[276].attribute /* Mixer1._xvapin_s[1] */.max;
  /* static nls data for MaterialStream1.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[84].attribute /* MaterialStream1._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[84].attribute /* MaterialStream1._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[84].attribute /* MaterialStream1._x_pc[3,1] */.max;
  /* static nls data for MaterialStream1.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[3,2] */.max;
  /* static nls data for MaterialStream1.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[83].attribute /* MaterialStream1._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[83].attribute /* MaterialStream1._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[83].attribute /* MaterialStream1._x_pc[2,2] */.max;
  /* static nls data for MaterialStream1.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[82].attribute /* MaterialStream1._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[82].attribute /* MaterialStream1._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[82].attribute /* MaterialStream1._x_pc[2,1] */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS483(sysData);
}

void getIterationVarsNLS483(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */;
  array[1] = data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */;
  array[2] = data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */;
  array[3] = data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */;
  array[4] = data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */;
}


/* inner equations */

/*
 equation index: 532
 type: SIMPLE_ASSIGN
 MaterialStream2._xliq = 1.0 - Mixer1.xvapin_s[2]
 */
void Flowsheet_eqFunction_532(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,532};
  data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */ = 1.0 - data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */;
  TRACE_POP
}
/*
 equation index: 533
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p[2] = 100.0 * MaterialStream2.xliq
 */
void Flowsheet_eqFunction_533(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,533};
  data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */ = (100.0) * (data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */);
  TRACE_POP
}
/*
 equation index: 534
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p[3] = 100.0 * Mixer1.xvapin_s[2]
 */
void Flowsheet_eqFunction_534(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,534};
  data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */ = (100.0) * (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */);
  TRACE_POP
}

void residualFunc548(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,548};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  /* iteration variables */
  data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */ = xloc[0];
  data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ = xloc[1];
  data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */ = xloc[2];
  data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */ = xloc[3];
  data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ = xloc[4];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_532(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_533(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_534(data, threadData);
  /* body */
  tmp0 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */;
  }
  else
  {
    tmp1 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp3 = (tmp1?data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ - ((data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */) * (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */)):data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */);
  }
  res[0] = tmp3;

  tmp4 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */;
  }
  else
  {
    tmp5 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp7 = (tmp5?data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (-1.0 + data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */),"1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[1])",equationIndexes):data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */);
  }
  res[1] = tmp7;

  tmp8 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */ - data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */;
  }
  else
  {
    tmp9 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp11 = (tmp9?data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (-1.0 + data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */),"1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[2])",equationIndexes):data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ - data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */);
  }
  res[2] = tmp11;

  tmp12 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */;
  }
  else
  {
    tmp13 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp15 = (tmp13?data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ - ((data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */) * (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */)):data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */);
  }
  res[3] = tmp15;

  tmp16 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */ - data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */;
  }
  else
  {
    tmp17 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp19 = (tmp17?data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ + data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ - data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */);
  }
  res[4] = tmp19;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS548(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+5] = {0,3,3,4,3,3};
  const int rowIndex[16] = {1,2,3,1,3,4,1,2,3,4,0,1,2,0,2,4};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(16*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 16;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  inSysData->sparsePattern.maxColors = 5;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 16*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[4] = 1;
  inSysData->sparsePattern.colorCols[3] = 2;
  inSysData->sparsePattern.colorCols[2] = 3;
  inSysData->sparsePattern.colorCols[1] = 4;
  inSysData->sparsePattern.colorCols[0] = 5;
}
void initializeStaticDataNLS548(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Mixer1.xvapin_s[2] */
  sysData->nominal[i] = data->modelData->realVarsData[277].attribute /* Mixer1._xvapin_s[2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[277].attribute /* Mixer1._xvapin_s[2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[277].attribute /* Mixer1._xvapin_s[2] */.max;
  /* static nls data for MaterialStream2.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[3,2] */.max;
  /* static nls data for MaterialStream2.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[2,2] */.max;
  /* static nls data for MaterialStream2.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[2,1] */.max;
  /* static nls data for MaterialStream2.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[3,1] */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS548(sysData);
}

void getIterationVarsNLS548(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */;
  array[1] = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */;
  array[2] = data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */;
  array[3] = data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */;
  array[4] = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */;
}


/* inner equations */

/*
 equation index: 585
 type: SIMPLE_ASSIGN
 MaterialStream3._Pvap_c[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[1].VP[1], MaterialStream3.C[1].VP[2], MaterialStream3.C[1].VP[3], MaterialStream3.C[1].VP[4], MaterialStream3.C[1].VP[5], MaterialStream3.C[1].VP[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_585(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,585};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[761], (modelica_real)data->simulationInfo->realParameter[762], (modelica_real)data->simulationInfo->realParameter[763], (modelica_real)data->simulationInfo->realParameter[764], (modelica_real)data->simulationInfo->realParameter[765], (modelica_real)data->simulationInfo->realParameter[766]);
  data->localData[0]->realVars[235] /* MaterialStream3._Pvap_c[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 586
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[2,1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream3.C[1].SH, {MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, {MaterialStream3.C[1].HOV[1], MaterialStream3.C[1].HOV[2], MaterialStream3.C[1].HOV[3], MaterialStream3.C[1].HOV[4], MaterialStream3.C[1].HOV[5], MaterialStream3.C[1].HOV[6]}, MaterialStream3.C[1].Tc, MaterialStream3.T)
 */
void Flowsheet_eqFunction_586(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,586};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[673], (modelica_real)data->simulationInfo->realParameter[674], (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678]);
  data->localData[0]->realVars[220] /* MaterialStream3._H_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[743], tmp0, tmp1, data->simulationInfo->realParameter[753], data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 587
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[3,1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream3.C[1].SH, {MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, {MaterialStream3.C[1].HOV[1], MaterialStream3.C[1].HOV[2], MaterialStream3.C[1].HOV[3], MaterialStream3.C[1].HOV[4], MaterialStream3.C[1].HOV[5], MaterialStream3.C[1].HOV[6]}, MaterialStream3.C[1].Tc, MaterialStream3.T)
 */
void Flowsheet_eqFunction_587(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,587};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[673], (modelica_real)data->simulationInfo->realParameter[674], (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678]);
  data->localData[0]->realVars[222] /* MaterialStream3._H_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[743], tmp0, tmp1, data->simulationInfo->realParameter[753], data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 588
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[2,2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream3.C[2].SH, {MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, {MaterialStream3.C[2].HOV[1], MaterialStream3.C[2].HOV[2], MaterialStream3.C[2].HOV[3], MaterialStream3.C[2].HOV[4], MaterialStream3.C[2].HOV[5], MaterialStream3.C[2].HOV[6]}, MaterialStream3.C[2].Tc, MaterialStream3.T)
 */
void Flowsheet_eqFunction_588(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,588};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680], (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684]);
  data->localData[0]->realVars[221] /* MaterialStream3._H_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[744], tmp0, tmp1, data->simulationInfo->realParameter[754], data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 589
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[3,2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream3.C[2].SH, {MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, {MaterialStream3.C[2].HOV[1], MaterialStream3.C[2].HOV[2], MaterialStream3.C[2].HOV[3], MaterialStream3.C[2].HOV[4], MaterialStream3.C[2].HOV[5], MaterialStream3.C[2].HOV[6]}, MaterialStream3.C[2].Tc, MaterialStream3.T)
 */
void Flowsheet_eqFunction_589(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,589};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680], (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684]);
  data->localData[0]->realVars[223] /* MaterialStream3._H_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[744], tmp0, tmp1, data->simulationInfo->realParameter[754], data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 590
 type: SIMPLE_ASSIGN
 MaterialStream3._Pvap_c[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[2].VP[1], MaterialStream3.C[2].VP[2], MaterialStream3.C[2].VP[3], MaterialStream3.C[2].VP[4], MaterialStream3.C[2].VP[5], MaterialStream3.C[2].VP[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_590(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,590};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[767], (modelica_real)data->simulationInfo->realParameter[768], (modelica_real)data->simulationInfo->realParameter[769], (modelica_real)data->simulationInfo->realParameter[770], (modelica_real)data->simulationInfo->realParameter[771], (modelica_real)data->simulationInfo->realParameter[772]);
  data->localData[0]->realVars[236] /* MaterialStream3._Pvap_c[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 591
 type: SIMPLE_ASSIGN
 MaterialStream3._H_p[3] = MaterialStream3.x_pc[3,1] * MaterialStream3.H_pc[3,1] + MaterialStream3.x_pc[3,2] * MaterialStream3.H_pc[3,2]
 */
void Flowsheet_eqFunction_591(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,591};
  data->localData[0]->realVars[217] /* MaterialStream3._H_p[3] variable */ = (data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */) * (data->localData[0]->realVars[222] /* MaterialStream3._H_pc[3,1] variable */) + (data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */) * (data->localData[0]->realVars[223] /* MaterialStream3._H_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 592
 type: SIMPLE_ASSIGN
 MaterialStream3._H_p[2] = MaterialStream3.x_pc[2,1] * MaterialStream3.H_pc[2,1] + MaterialStream3.x_pc[2,2] * MaterialStream3.H_pc[2,2]
 */
void Flowsheet_eqFunction_592(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,592};
  data->localData[0]->realVars[216] /* MaterialStream3._H_p[2] variable */ = (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */) * (data->localData[0]->realVars[220] /* MaterialStream3._H_pc[2,1] variable */) + (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */) * (data->localData[0]->realVars[221] /* MaterialStream3._H_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 593
 type: SIMPLE_ASSIGN
 MaterialStream3._Pbubl = MaterialStream3.x_pc[1,1] * exp(MaterialStream3.C[1].VP[2] + DIVISION(MaterialStream3.C[1].VP[3], MaterialStream3.T) + MaterialStream3.C[1].VP[4] * log(MaterialStream3.T) + MaterialStream3.C[1].VP[5] * MaterialStream3.T ^ MaterialStream3.C[1].VP[6]) + MaterialStream3.x_pc[1,2] * exp(MaterialStream3.C[2].VP[2] + DIVISION(MaterialStream3.C[2].VP[3], MaterialStream3.T) + MaterialStream3.C[2].VP[4] * log(MaterialStream3.T) + MaterialStream3.C[2].VP[5] * MaterialStream3.T ^ MaterialStream3.C[2].VP[6])
 */
void Flowsheet_eqFunction_593(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,593};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  tmp0 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  if(!(tmp0 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of log(MaterialStream3.T) was %g should be > 0", tmp0);
  }tmp1 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  tmp2 = data->simulationInfo->realParameter[766];
  if(tmp1 < 0.0 && tmp2 != 0.0)
  {
    tmp4 = modf(tmp2, &tmp5);
    
    if(tmp4 > 0.5)
    {
      tmp4 -= 1.0;
      tmp5 += 1.0;
    }
    else if(tmp4 < -0.5)
    {
      tmp4 += 1.0;
      tmp5 -= 1.0;
    }
    
    if(fabs(tmp4) < 1e-10)
      tmp3 = pow(tmp1, tmp5);
    else
    {
      tmp7 = modf(1.0/tmp2, &tmp6);
      if(tmp7 > 0.5)
      {
        tmp7 -= 1.0;
        tmp6 += 1.0;
      }
      else if(tmp7 < -0.5)
      {
        tmp7 += 1.0;
        tmp6 -= 1.0;
      }
      if(fabs(tmp7) < 1e-10 && ((unsigned long)tmp6 & 1))
      {
        tmp3 = -pow(-tmp1, tmp4)*pow(tmp1, tmp5);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
      }
    }
  }
  else
  {
    tmp3 = pow(tmp1, tmp2);
  }
  if(isnan(tmp3) || isinf(tmp3))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
  }tmp8 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  if(!(tmp8 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of log(MaterialStream3.T) was %g should be > 0", tmp8);
  }tmp9 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  tmp10 = data->simulationInfo->realParameter[772];
  if(tmp9 < 0.0 && tmp10 != 0.0)
  {
    tmp12 = modf(tmp10, &tmp13);
    
    if(tmp12 > 0.5)
    {
      tmp12 -= 1.0;
      tmp13 += 1.0;
    }
    else if(tmp12 < -0.5)
    {
      tmp12 += 1.0;
      tmp13 -= 1.0;
    }
    
    if(fabs(tmp12) < 1e-10)
      tmp11 = pow(tmp9, tmp13);
    else
    {
      tmp15 = modf(1.0/tmp10, &tmp14);
      if(tmp15 > 0.5)
      {
        tmp15 -= 1.0;
        tmp14 += 1.0;
      }
      else if(tmp15 < -0.5)
      {
        tmp15 += 1.0;
        tmp14 -= 1.0;
      }
      if(fabs(tmp15) < 1e-10 && ((unsigned long)tmp14 & 1))
      {
        tmp11 = -pow(-tmp9, tmp12)*pow(tmp9, tmp13);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp9, tmp10);
      }
    }
  }
  else
  {
    tmp11 = pow(tmp9, tmp10);
  }
  if(isnan(tmp11) || isinf(tmp11))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp9, tmp10);
  }
  data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */ = (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (exp(data->simulationInfo->realParameter[762] + DIVISION_SIM(data->simulationInfo->realParameter[763],data->localData[0]->realVars[249] /* MaterialStream3._T variable */,"MaterialStream3.T",equationIndexes) + (data->simulationInfo->realParameter[764]) * (log(tmp0)) + (data->simulationInfo->realParameter[765]) * (tmp3))) + (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (exp(data->simulationInfo->realParameter[768] + DIVISION_SIM(data->simulationInfo->realParameter[769],data->localData[0]->realVars[249] /* MaterialStream3._T variable */,"MaterialStream3.T",equationIndexes) + (data->simulationInfo->realParameter[770]) * (log(tmp8)) + (data->simulationInfo->realParameter[771]) * (tmp11)));
  TRACE_POP
}
/*
 equation index: 594
 type: SIMPLE_ASSIGN
 MaterialStream3._Pdew = DIVISION(1.0, MaterialStream3.x_pc[1,1] * exp((-MaterialStream3.C[1].VP[2]) - DIVISION(MaterialStream3.C[1].VP[3], MaterialStream3.T) - MaterialStream3.C[1].VP[4] * log(MaterialStream3.T) - MaterialStream3.C[1].VP[5] * MaterialStream3.T ^ MaterialStream3.C[1].VP[6]) + MaterialStream3.x_pc[1,2] * exp((-MaterialStream3.C[2].VP[2]) - DIVISION(MaterialStream3.C[2].VP[3], MaterialStream3.T) - MaterialStream3.C[2].VP[4] * log(MaterialStream3.T) - MaterialStream3.C[2].VP[5] * MaterialStream3.T ^ MaterialStream3.C[2].VP[6]))
 */
void Flowsheet_eqFunction_594(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,594};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  tmp0 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  if(!(tmp0 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of log(MaterialStream3.T) was %g should be > 0", tmp0);
  }tmp1 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  tmp2 = data->simulationInfo->realParameter[766];
  if(tmp1 < 0.0 && tmp2 != 0.0)
  {
    tmp4 = modf(tmp2, &tmp5);
    
    if(tmp4 > 0.5)
    {
      tmp4 -= 1.0;
      tmp5 += 1.0;
    }
    else if(tmp4 < -0.5)
    {
      tmp4 += 1.0;
      tmp5 -= 1.0;
    }
    
    if(fabs(tmp4) < 1e-10)
      tmp3 = pow(tmp1, tmp5);
    else
    {
      tmp7 = modf(1.0/tmp2, &tmp6);
      if(tmp7 > 0.5)
      {
        tmp7 -= 1.0;
        tmp6 += 1.0;
      }
      else if(tmp7 < -0.5)
      {
        tmp7 += 1.0;
        tmp6 -= 1.0;
      }
      if(fabs(tmp7) < 1e-10 && ((unsigned long)tmp6 & 1))
      {
        tmp3 = -pow(-tmp1, tmp4)*pow(tmp1, tmp5);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
      }
    }
  }
  else
  {
    tmp3 = pow(tmp1, tmp2);
  }
  if(isnan(tmp3) || isinf(tmp3))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
  }tmp8 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  if(!(tmp8 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of log(MaterialStream3.T) was %g should be > 0", tmp8);
  }tmp9 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  tmp10 = data->simulationInfo->realParameter[772];
  if(tmp9 < 0.0 && tmp10 != 0.0)
  {
    tmp12 = modf(tmp10, &tmp13);
    
    if(tmp12 > 0.5)
    {
      tmp12 -= 1.0;
      tmp13 += 1.0;
    }
    else if(tmp12 < -0.5)
    {
      tmp12 += 1.0;
      tmp13 -= 1.0;
    }
    
    if(fabs(tmp12) < 1e-10)
      tmp11 = pow(tmp9, tmp13);
    else
    {
      tmp15 = modf(1.0/tmp10, &tmp14);
      if(tmp15 > 0.5)
      {
        tmp15 -= 1.0;
        tmp14 += 1.0;
      }
      else if(tmp15 < -0.5)
      {
        tmp15 += 1.0;
        tmp14 -= 1.0;
      }
      if(fabs(tmp15) < 1e-10 && ((unsigned long)tmp14 & 1))
      {
        tmp11 = -pow(-tmp9, tmp12)*pow(tmp9, tmp13);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp9, tmp10);
      }
    }
  }
  else
  {
    tmp11 = pow(tmp9, tmp10);
  }
  if(isnan(tmp11) || isinf(tmp11))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp9, tmp10);
  }
  data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */ = DIVISION_SIM(1.0,(data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (exp((-data->simulationInfo->realParameter[762]) - DIVISION_SIM(data->simulationInfo->realParameter[763],data->localData[0]->realVars[249] /* MaterialStream3._T variable */,"MaterialStream3.T",equationIndexes) - ((data->simulationInfo->realParameter[764]) * (log(tmp0))) - ((data->simulationInfo->realParameter[765]) * (tmp3)))) + (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (exp((-data->simulationInfo->realParameter[768]) - DIVISION_SIM(data->simulationInfo->realParameter[769],data->localData[0]->realVars[249] /* MaterialStream3._T variable */,"MaterialStream3.T",equationIndexes) - ((data->simulationInfo->realParameter[770]) * (log(tmp8))) - ((data->simulationInfo->realParameter[771]) * (tmp11)))),"MaterialStream3.x_pc[1,1] * exp((-MaterialStream3.C[1].VP[2]) - DIVISION(MaterialStream3.C[1].VP[3], MaterialStream3.T) - MaterialStream3.C[1].VP[4] * log(MaterialStream3.T) - MaterialStream3.C[1].VP[5] * MaterialStream3.T ^ MaterialStream3.C[1].VP[6]) + MaterialStream3.x_pc[1,2] * exp((-MaterialStream3.C[2].VP[2]) - DIVISION(MaterialStream3.C[2].VP[3], MaterialStream3.T) - MaterialStream3.C[2].VP[4] * log(MaterialStream3.T) - MaterialStream3.C[2].VP[5] * MaterialStream3.T ^ MaterialStream3.C[2].VP[6])",equationIndexes);
  TRACE_POP
}
/*
 equation index: 595
 type: SIMPLE_ASSIGN
 MaterialStream3._K_c[1] = 9.869232667160129e-006 * MaterialStream3.Pvap_c[1]
 */
void Flowsheet_eqFunction_595(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,595};
  data->localData[0]->realVars[227] /* MaterialStream3._K_c[1] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[235] /* MaterialStream3._Pvap_c[1] variable */);
  TRACE_POP
}
/*
 equation index: 596
 type: SIMPLE_ASSIGN
 MaterialStream3._K_c[2] = 9.869232667160129e-006 * MaterialStream3.Pvap_c[2]
 */
void Flowsheet_eqFunction_596(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,596};
  data->localData[0]->realVars[228] /* MaterialStream3._K_c[2] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[236] /* MaterialStream3._Pvap_c[2] variable */);
  TRACE_POP
}
/*
 equation index: 597
 type: SIMPLE_ASSIGN
 MaterialStream3._xliq = 1.0 - MaterialStream3.xvap
 */
void Flowsheet_eqFunction_597(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,597};
  data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */ = 1.0 - data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */;
  TRACE_POP
}
/*
 equation index: 598
 type: SIMPLE_ASSIGN
 MaterialStream3._F_p[3] = 200.0 * MaterialStream3.xvap
 */
void Flowsheet_eqFunction_598(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,598};
  data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */ = (200.0) * (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */);
  TRACE_POP
}
/*
 equation index: 599
 type: SIMPLE_ASSIGN
 MaterialStream3._F_p[2] = 200.0 * MaterialStream3.xliq
 */
void Flowsheet_eqFunction_599(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,599};
  data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */ = (200.0) * (data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */);
  TRACE_POP
}

void residualFunc606(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,606};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  /* iteration variables */
  data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */ = xloc[0];
  data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ = xloc[1];
  data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */ = xloc[2];
  data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */ = xloc[3];
  data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ = xloc[4];
  data->localData[0]->realVars[249] /* MaterialStream3._T variable */ = xloc[5];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_585(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_586(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_587(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_588(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_589(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_590(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_591(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_592(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_593(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_594(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_595(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_596(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_597(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_598(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_599(data, threadData);
  /* body */
  tmp0 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */;
  }
  else
  {
    tmp1 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp3 = (tmp1?data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ - ((data->localData[0]->realVars[227] /* MaterialStream3._K_c[1] variable */) * (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */)):data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */);
  }
  res[0] = tmp3;

  tmp4 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */;
  }
  else
  {
    tmp5 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp7 = (tmp5?data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (-1.0 + data->localData[0]->realVars[227] /* MaterialStream3._K_c[1] variable */),"1.0 + MaterialStream3.xvap * (-1.0 + MaterialStream3.K_c[1])",equationIndexes):data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */);
  }
  res[1] = tmp7;

  tmp8 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */ - data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */;
  }
  else
  {
    tmp9 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp11 = (tmp9?data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (-1.0 + data->localData[0]->realVars[228] /* MaterialStream3._K_c[2] variable */),"1.0 + MaterialStream3.xvap * (-1.0 + MaterialStream3.K_c[2])",equationIndexes):data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ - data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */);
  }
  res[2] = tmp11;

  tmp12 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */;
  }
  else
  {
    tmp13 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp15 = (tmp13?data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ - ((data->localData[0]->realVars[228] /* MaterialStream3._K_c[2] variable */) * (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */)):data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */);
  }
  res[3] = tmp15;

  res[4] = (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (data->localData[0]->realVars[217] /* MaterialStream3._H_p[3] variable */) + (data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */) * (data->localData[0]->realVars[216] /* MaterialStream3._H_p[2] variable */) - data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */;

  tmp16 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */ - data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */;
  }
  else
  {
    tmp17 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp19 = (tmp17?data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ + data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ - data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */);
  }
  res[5] = tmp19;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS606(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+6] = {0,4,4,5,4,4,6};
  const int rowIndex[27] = {1,2,3,4,0,2,4,5,1,2,3,4,5,0,1,2,4,1,3,4,5,0,1,2,3,4,5};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((6+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(27*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 27;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(6*sizeof(int));
  inSysData->sparsePattern.maxColors = 6;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (6+1)*sizeof(int));
  
  for(i=2;i<6+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 27*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[5] = 1;
  inSysData->sparsePattern.colorCols[4] = 2;
  inSysData->sparsePattern.colorCols[3] = 3;
  inSysData->sparsePattern.colorCols[2] = 4;
  inSysData->sparsePattern.colorCols[1] = 5;
  inSysData->sparsePattern.colorCols[0] = 6;
}
void initializeStaticDataNLS606(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream3.xvap */
  sysData->nominal[i] = data->modelData->realVarsData[275].attribute /* MaterialStream3._xvap */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[275].attribute /* MaterialStream3._xvap */.min;
  sysData->max[i++]   = data->modelData->realVarsData[275].attribute /* MaterialStream3._xvap */.max;
  /* static nls data for MaterialStream3.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[264].attribute /* MaterialStream3._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[264].attribute /* MaterialStream3._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[264].attribute /* MaterialStream3._x_pc[3,1] */.max;
  /* static nls data for MaterialStream3.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[263].attribute /* MaterialStream3._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[263].attribute /* MaterialStream3._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[263].attribute /* MaterialStream3._x_pc[2,2] */.max;
  /* static nls data for MaterialStream3.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[262].attribute /* MaterialStream3._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[262].attribute /* MaterialStream3._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[262].attribute /* MaterialStream3._x_pc[2,1] */.max;
  /* static nls data for MaterialStream3.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[265].attribute /* MaterialStream3._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[265].attribute /* MaterialStream3._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[265].attribute /* MaterialStream3._x_pc[3,2] */.max;
  /* static nls data for MaterialStream3.T */
  sysData->nominal[i] = data->modelData->realVarsData[249].attribute /* MaterialStream3._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[249].attribute /* MaterialStream3._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[249].attribute /* MaterialStream3._T */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS606(sysData);
}

void getIterationVarsNLS606(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */;
  array[1] = data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */;
  array[2] = data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */;
  array[3] = data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */;
  array[4] = data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */;
  array[5] = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
}

/* inner equations */

/*
 equation index: 702
 type: SIMPLE_ASSIGN
 MaterialStream1._xliq = 1.0 - Mixer1.xvapin_s[1]
 */
void Flowsheet_eqFunction_702(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,702};
  data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */ = 1.0 - data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */;
  TRACE_POP
}
/*
 equation index: 703
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[2] = 100.0 * MaterialStream1.xliq
 */
void Flowsheet_eqFunction_703(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,703};
  data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */ = (100.0) * (data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */);
  TRACE_POP
}
/*
 equation index: 704
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[3] = 100.0 * Mixer1.xvapin_s[1]
 */
void Flowsheet_eqFunction_704(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,704};
  data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */ = (100.0) * (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */);
  TRACE_POP
}

void residualFunc718(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,718};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  /* iteration variables */
  data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */ = xloc[0];
  data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */ = xloc[1];
  data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ = xloc[2];
  data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */ = xloc[3];
  data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ = xloc[4];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_702(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_703(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_704(data, threadData);
  /* body */
  tmp0 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */;
  }
  else
  {
    tmp1 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp3 = (tmp1?data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ - ((data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */) * (data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */)):data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */);
  }
  res[0] = tmp3;

  tmp4 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */;
  }
  else
  {
    tmp5 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp7 = (tmp5?data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (-1.0 + data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */),"1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[1])",equationIndexes):data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */);
  }
  res[1] = tmp7;

  tmp8 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */ - data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */;
  }
  else
  {
    tmp9 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp11 = (tmp9?data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ + data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ - data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */);
  }
  res[2] = tmp11;

  tmp12 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */ - data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */;
  }
  else
  {
    tmp13 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp15 = (tmp13?data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (-1.0 + data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */),"1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[2])",equationIndexes):data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */ - data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */);
  }
  res[3] = tmp15;

  tmp16 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */;
  }
  else
  {
    tmp17 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp19 = (tmp17?data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */ - ((data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */) * (data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */)):data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */);
  }
  res[4] = tmp19;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS718(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+5] = {0,3,4,3,3,3};
  const int rowIndex[16] = {1,3,4,1,2,3,4,1,2,4,0,1,3,0,2,3};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(16*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 16;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  inSysData->sparsePattern.maxColors = 5;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 16*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[4] = 1;
  inSysData->sparsePattern.colorCols[3] = 2;
  inSysData->sparsePattern.colorCols[2] = 3;
  inSysData->sparsePattern.colorCols[1] = 4;
  inSysData->sparsePattern.colorCols[0] = 5;
}
void initializeStaticDataNLS718(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Mixer1.xvapin_s[1] */
  sysData->nominal[i] = data->modelData->realVarsData[276].attribute /* Mixer1._xvapin_s[1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[276].attribute /* Mixer1._xvapin_s[1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[276].attribute /* Mixer1._xvapin_s[1] */.max;
  /* static nls data for MaterialStream1.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[83].attribute /* MaterialStream1._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[83].attribute /* MaterialStream1._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[83].attribute /* MaterialStream1._x_pc[2,2] */.max;
  /* static nls data for MaterialStream1.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[85].attribute /* MaterialStream1._x_pc[3,2] */.max;
  /* static nls data for MaterialStream1.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[82].attribute /* MaterialStream1._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[82].attribute /* MaterialStream1._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[82].attribute /* MaterialStream1._x_pc[2,1] */.max;
  /* static nls data for MaterialStream1.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[84].attribute /* MaterialStream1._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[84].attribute /* MaterialStream1._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[84].attribute /* MaterialStream1._x_pc[3,1] */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS718(sysData);
}

void getIterationVarsNLS718(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */;
  array[1] = data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */;
  array[2] = data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */;
  array[3] = data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */;
  array[4] = data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */;
}


/* inner equations */

/*
 equation index: 752
 type: SIMPLE_ASSIGN
 MaterialStream2._xliq = 1.0 - Mixer1.xvapin_s[2]
 */
void Flowsheet_eqFunction_752(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,752};
  data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */ = 1.0 - data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */;
  TRACE_POP
}
/*
 equation index: 753
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p[2] = 100.0 * MaterialStream2.xliq
 */
void Flowsheet_eqFunction_753(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,753};
  data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */ = (100.0) * (data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */);
  TRACE_POP
}
/*
 equation index: 754
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p[3] = 100.0 * Mixer1.xvapin_s[2]
 */
void Flowsheet_eqFunction_754(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,754};
  data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */ = (100.0) * (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */);
  TRACE_POP
}

void residualFunc768(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,768};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  /* iteration variables */
  data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */ = xloc[0];
  data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ = xloc[1];
  data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ = xloc[2];
  data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */ = xloc[3];
  data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */ = xloc[4];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_752(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_753(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_754(data, threadData);
  /* body */
  tmp0 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */;
  }
  else
  {
    tmp1 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp3 = (tmp1?data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (-1.0 + data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */),"1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[1])",equationIndexes):data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */);
  }
  res[0] = tmp3;

  tmp4 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */ - data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */;
  }
  else
  {
    tmp5 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp7 = (tmp5?data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (-1.0 + data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */),"1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[2])",equationIndexes):data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ - data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */);
  }
  res[1] = tmp7;

  tmp8 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */;
  }
  else
  {
    tmp9 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp11 = (tmp9?data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ - ((data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */) * (data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */)):data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */);
  }
  res[2] = tmp11;

  tmp12 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */ - data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */;
  }
  else
  {
    tmp13 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp15 = (tmp13?data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */ + data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ - data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */);
  }
  res[3] = tmp15;

  tmp16 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */;
  }
  else
  {
    tmp17 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp19 = (tmp17?data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */ - ((data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */) * (data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */)):data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */);
  }
  res[4] = tmp19;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS768(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+5] = {0,3,3,3,3,4};
  const int rowIndex[16] = {0,1,4,0,3,4,1,2,3,0,1,2,0,1,3,4};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(16*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 16;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  inSysData->sparsePattern.maxColors = 5;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 16*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[4] = 1;
  inSysData->sparsePattern.colorCols[3] = 2;
  inSysData->sparsePattern.colorCols[2] = 3;
  inSysData->sparsePattern.colorCols[1] = 4;
  inSysData->sparsePattern.colorCols[0] = 5;
}
void initializeStaticDataNLS768(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Mixer1.xvapin_s[2] */
  sysData->nominal[i] = data->modelData->realVarsData[277].attribute /* Mixer1._xvapin_s[2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[277].attribute /* Mixer1._xvapin_s[2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[277].attribute /* Mixer1._xvapin_s[2] */.max;
  /* static nls data for MaterialStream2.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[3,2] */.max;
  /* static nls data for MaterialStream2.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[3,1] */.max;
  /* static nls data for MaterialStream2.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[172].attribute /* MaterialStream2._x_pc[2,1] */.max;
  /* static nls data for MaterialStream2.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[173].attribute /* MaterialStream2._x_pc[2,2] */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS768(sysData);
}

void getIterationVarsNLS768(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */;
  array[1] = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */;
  array[2] = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */;
  array[3] = data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */;
  array[4] = data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */;
}


/* inner equations */

/*
 equation index: 800
 type: SIMPLE_ASSIGN
 MaterialStream3._Pvap_c[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[2].VP[1], MaterialStream3.C[2].VP[2], MaterialStream3.C[2].VP[3], MaterialStream3.C[2].VP[4], MaterialStream3.C[2].VP[5], MaterialStream3.C[2].VP[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_800(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,800};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[767], (modelica_real)data->simulationInfo->realParameter[768], (modelica_real)data->simulationInfo->realParameter[769], (modelica_real)data->simulationInfo->realParameter[770], (modelica_real)data->simulationInfo->realParameter[771], (modelica_real)data->simulationInfo->realParameter[772]);
  data->localData[0]->realVars[236] /* MaterialStream3._Pvap_c[2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 801
 type: SIMPLE_ASSIGN
 MaterialStream3._Pvap_c[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream3.C[1].VP[1], MaterialStream3.C[1].VP[2], MaterialStream3.C[1].VP[3], MaterialStream3.C[1].VP[4], MaterialStream3.C[1].VP[5], MaterialStream3.C[1].VP[6]}, MaterialStream3.T)
 */
void Flowsheet_eqFunction_801(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,801};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[761], (modelica_real)data->simulationInfo->realParameter[762], (modelica_real)data->simulationInfo->realParameter[763], (modelica_real)data->simulationInfo->realParameter[764], (modelica_real)data->simulationInfo->realParameter[765], (modelica_real)data->simulationInfo->realParameter[766]);
  data->localData[0]->realVars[235] /* MaterialStream3._Pvap_c[1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 802
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[2,2] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream3.C[2].SH, {MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, {MaterialStream3.C[2].HOV[1], MaterialStream3.C[2].HOV[2], MaterialStream3.C[2].HOV[3], MaterialStream3.C[2].HOV[4], MaterialStream3.C[2].HOV[5], MaterialStream3.C[2].HOV[6]}, MaterialStream3.C[2].Tc, MaterialStream3.T)
 */
void Flowsheet_eqFunction_802(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,802};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680], (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684]);
  data->localData[0]->realVars[221] /* MaterialStream3._H_pc[2,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[744], tmp0, tmp1, data->simulationInfo->realParameter[754], data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 803
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[3,1] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream3.C[1].SH, {MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, {MaterialStream3.C[1].HOV[1], MaterialStream3.C[1].HOV[2], MaterialStream3.C[1].HOV[3], MaterialStream3.C[1].HOV[4], MaterialStream3.C[1].HOV[5], MaterialStream3.C[1].HOV[6]}, MaterialStream3.C[1].Tc, MaterialStream3.T)
 */
void Flowsheet_eqFunction_803(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,803};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[673], (modelica_real)data->simulationInfo->realParameter[674], (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678]);
  data->localData[0]->realVars[222] /* MaterialStream3._H_pc[3,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[743], tmp0, tmp1, data->simulationInfo->realParameter[753], data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 804
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[2,1] = Simulator.Files.ThermodynamicFunctions.HLiqId(MaterialStream3.C[1].SH, {MaterialStream3.C[1].VapCp[1], MaterialStream3.C[1].VapCp[2], MaterialStream3.C[1].VapCp[3], MaterialStream3.C[1].VapCp[4], MaterialStream3.C[1].VapCp[5], MaterialStream3.C[1].VapCp[6]}, {MaterialStream3.C[1].HOV[1], MaterialStream3.C[1].HOV[2], MaterialStream3.C[1].HOV[3], MaterialStream3.C[1].HOV[4], MaterialStream3.C[1].HOV[5], MaterialStream3.C[1].HOV[6]}, MaterialStream3.C[1].Tc, MaterialStream3.T)
 */
void Flowsheet_eqFunction_804(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,804};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774], (modelica_real)data->simulationInfo->realParameter[775], (modelica_real)data->simulationInfo->realParameter[776], (modelica_real)data->simulationInfo->realParameter[777], (modelica_real)data->simulationInfo->realParameter[778]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[673], (modelica_real)data->simulationInfo->realParameter[674], (modelica_real)data->simulationInfo->realParameter[675], (modelica_real)data->simulationInfo->realParameter[676], (modelica_real)data->simulationInfo->realParameter[677], (modelica_real)data->simulationInfo->realParameter[678]);
  data->localData[0]->realVars[220] /* MaterialStream3._H_pc[2,1] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, data->simulationInfo->realParameter[743], tmp0, tmp1, data->simulationInfo->realParameter[753], data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 805
 type: SIMPLE_ASSIGN
 MaterialStream3._H_pc[3,2] = Simulator.Files.ThermodynamicFunctions.HVapId(MaterialStream3.C[2].SH, {MaterialStream3.C[2].VapCp[1], MaterialStream3.C[2].VapCp[2], MaterialStream3.C[2].VapCp[3], MaterialStream3.C[2].VapCp[4], MaterialStream3.C[2].VapCp[5], MaterialStream3.C[2].VapCp[6]}, {MaterialStream3.C[2].HOV[1], MaterialStream3.C[2].HOV[2], MaterialStream3.C[2].HOV[3], MaterialStream3.C[2].HOV[4], MaterialStream3.C[2].HOV[5], MaterialStream3.C[2].HOV[6]}, MaterialStream3.C[2].Tc, MaterialStream3.T)
 */
void Flowsheet_eqFunction_805(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,805};
  real_array tmp0;
  real_array tmp1;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[779], (modelica_real)data->simulationInfo->realParameter[780], (modelica_real)data->simulationInfo->realParameter[781], (modelica_real)data->simulationInfo->realParameter[782], (modelica_real)data->simulationInfo->realParameter[783], (modelica_real)data->simulationInfo->realParameter[784]);
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)data->simulationInfo->realParameter[679], (modelica_real)data->simulationInfo->realParameter[680], (modelica_real)data->simulationInfo->realParameter[681], (modelica_real)data->simulationInfo->realParameter[682], (modelica_real)data->simulationInfo->realParameter[683], (modelica_real)data->simulationInfo->realParameter[684]);
  data->localData[0]->realVars[223] /* MaterialStream3._H_pc[3,2] variable */ = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, data->simulationInfo->realParameter[744], tmp0, tmp1, data->simulationInfo->realParameter[754], data->localData[0]->realVars[249] /* MaterialStream3._T variable */);
  TRACE_POP
}
/*
 equation index: 806
 type: SIMPLE_ASSIGN
 MaterialStream3._H_p[2] = MaterialStream3.x_pc[2,1] * MaterialStream3.H_pc[2,1] + MaterialStream3.x_pc[2,2] * MaterialStream3.H_pc[2,2]
 */
void Flowsheet_eqFunction_806(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,806};
  data->localData[0]->realVars[216] /* MaterialStream3._H_p[2] variable */ = (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */) * (data->localData[0]->realVars[220] /* MaterialStream3._H_pc[2,1] variable */) + (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */) * (data->localData[0]->realVars[221] /* MaterialStream3._H_pc[2,2] variable */);
  TRACE_POP
}
/*
 equation index: 807
 type: SIMPLE_ASSIGN
 MaterialStream3._H_p[3] = MaterialStream3.x_pc[3,1] * MaterialStream3.H_pc[3,1] + MaterialStream3.x_pc[3,2] * MaterialStream3.H_pc[3,2]
 */
void Flowsheet_eqFunction_807(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,807};
  data->localData[0]->realVars[217] /* MaterialStream3._H_p[3] variable */ = (data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */) * (data->localData[0]->realVars[222] /* MaterialStream3._H_pc[3,1] variable */) + (data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */) * (data->localData[0]->realVars[223] /* MaterialStream3._H_pc[3,2] variable */);
  TRACE_POP
}
/*
 equation index: 808
 type: SIMPLE_ASSIGN
 MaterialStream3._K_c[2] = 9.869232667160129e-006 * MaterialStream3.Pvap_c[2]
 */
void Flowsheet_eqFunction_808(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,808};
  data->localData[0]->realVars[228] /* MaterialStream3._K_c[2] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[236] /* MaterialStream3._Pvap_c[2] variable */);
  TRACE_POP
}
/*
 equation index: 809
 type: SIMPLE_ASSIGN
 MaterialStream3._K_c[1] = 9.869232667160129e-006 * MaterialStream3.Pvap_c[1]
 */
void Flowsheet_eqFunction_809(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,809};
  data->localData[0]->realVars[227] /* MaterialStream3._K_c[1] variable */ = (9.869232667160129e-006) * (data->localData[0]->realVars[235] /* MaterialStream3._Pvap_c[1] variable */);
  TRACE_POP
}
/*
 equation index: 810
 type: SIMPLE_ASSIGN
 $cse2 = log(MaterialStream3.T)
 */
void Flowsheet_eqFunction_810(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,810};
  modelica_real tmp0;
  tmp0 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  if(!(tmp0 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of log(MaterialStream3.T) was %g should be > 0", tmp0);
  }
  data->localData[0]->realVars[1] /* $cse2 variable */ = log(tmp0);
  TRACE_POP
}
/*
 equation index: 811
 type: SIMPLE_ASSIGN
 $cse5 = exp((-MaterialStream3.C[2].VP[2]) - DIVISION(MaterialStream3.C[2].VP[3], MaterialStream3.T) - MaterialStream3.C[2].VP[4] * $cse2 - MaterialStream3.C[2].VP[5] * MaterialStream3.T ^ MaterialStream3.C[2].VP[6])
 */
void Flowsheet_eqFunction_811(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,811};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp0 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  tmp1 = data->simulationInfo->realParameter[772];
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }
  data->localData[0]->realVars[4] /* $cse5 variable */ = exp((-data->simulationInfo->realParameter[768]) - DIVISION_SIM(data->simulationInfo->realParameter[769],data->localData[0]->realVars[249] /* MaterialStream3._T variable */,"MaterialStream3.T",equationIndexes) - ((data->simulationInfo->realParameter[770]) * (data->localData[0]->realVars[1] /* $cse2 variable */)) - ((data->simulationInfo->realParameter[771]) * (tmp2)));
  TRACE_POP
}
/*
 equation index: 812
 type: SIMPLE_ASSIGN
 $cse4 = exp((-MaterialStream3.C[1].VP[2]) - DIVISION(MaterialStream3.C[1].VP[3], MaterialStream3.T) - MaterialStream3.C[1].VP[4] * $cse2 - MaterialStream3.C[1].VP[5] * MaterialStream3.T ^ MaterialStream3.C[1].VP[6])
 */
void Flowsheet_eqFunction_812(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,812};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp0 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  tmp1 = data->simulationInfo->realParameter[766];
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }
  data->localData[0]->realVars[3] /* $cse4 variable */ = exp((-data->simulationInfo->realParameter[762]) - DIVISION_SIM(data->simulationInfo->realParameter[763],data->localData[0]->realVars[249] /* MaterialStream3._T variable */,"MaterialStream3.T",equationIndexes) - ((data->simulationInfo->realParameter[764]) * (data->localData[0]->realVars[1] /* $cse2 variable */)) - ((data->simulationInfo->realParameter[765]) * (tmp2)));
  TRACE_POP
}
/*
 equation index: 813
 type: SIMPLE_ASSIGN
 MaterialStream3._Pdew = DIVISION(1.0, MaterialStream3.x_pc[1,1] * $cse4 + MaterialStream3.x_pc[1,2] * $cse5)
 */
void Flowsheet_eqFunction_813(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,813};
  data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */ = DIVISION_SIM(1.0,(data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (data->localData[0]->realVars[3] /* $cse4 variable */) + (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (data->localData[0]->realVars[4] /* $cse5 variable */),"MaterialStream3.x_pc[1,1] * $cse4 + MaterialStream3.x_pc[1,2] * $cse5",equationIndexes);
  TRACE_POP
}
/*
 equation index: 814
 type: SIMPLE_ASSIGN
 $cse3 = exp(MaterialStream3.C[2].VP[2] + DIVISION(MaterialStream3.C[2].VP[3], MaterialStream3.T) + MaterialStream3.C[2].VP[4] * $cse2 + MaterialStream3.C[2].VP[5] * MaterialStream3.T ^ MaterialStream3.C[2].VP[6])
 */
void Flowsheet_eqFunction_814(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,814};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp0 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  tmp1 = data->simulationInfo->realParameter[772];
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }
  data->localData[0]->realVars[2] /* $cse3 variable */ = exp(data->simulationInfo->realParameter[768] + DIVISION_SIM(data->simulationInfo->realParameter[769],data->localData[0]->realVars[249] /* MaterialStream3._T variable */,"MaterialStream3.T",equationIndexes) + (data->simulationInfo->realParameter[770]) * (data->localData[0]->realVars[1] /* $cse2 variable */) + (data->simulationInfo->realParameter[771]) * (tmp2));
  TRACE_POP
}
/*
 equation index: 815
 type: SIMPLE_ASSIGN
 $cse1 = exp(MaterialStream3.C[1].VP[2] + DIVISION(MaterialStream3.C[1].VP[3], MaterialStream3.T) + MaterialStream3.C[1].VP[4] * $cse2 + MaterialStream3.C[1].VP[5] * MaterialStream3.T ^ MaterialStream3.C[1].VP[6])
 */
void Flowsheet_eqFunction_815(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,815};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp0 = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  tmp1 = data->simulationInfo->realParameter[766];
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }
  data->localData[0]->realVars[0] /* $cse1 variable */ = exp(data->simulationInfo->realParameter[762] + DIVISION_SIM(data->simulationInfo->realParameter[763],data->localData[0]->realVars[249] /* MaterialStream3._T variable */,"MaterialStream3.T",equationIndexes) + (data->simulationInfo->realParameter[764]) * (data->localData[0]->realVars[1] /* $cse2 variable */) + (data->simulationInfo->realParameter[765]) * (tmp2));
  TRACE_POP
}
/*
 equation index: 816
 type: SIMPLE_ASSIGN
 MaterialStream3._Pbubl = MaterialStream3.x_pc[1,1] * $cse1 + MaterialStream3.x_pc[1,2] * $cse3
 */
void Flowsheet_eqFunction_816(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,816};
  data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */ = (data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */) * (data->localData[0]->realVars[0] /* $cse1 variable */) + (data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */) * (data->localData[0]->realVars[2] /* $cse3 variable */);
  TRACE_POP
}
/*
 equation index: 817
 type: SIMPLE_ASSIGN
 MaterialStream3._xliq = 1.0 - MaterialStream3.xvap
 */
void Flowsheet_eqFunction_817(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,817};
  data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */ = 1.0 - data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */;
  TRACE_POP
}
/*
 equation index: 818
 type: SIMPLE_ASSIGN
 MaterialStream3._F_p[3] = 200.0 * MaterialStream3.xvap
 */
void Flowsheet_eqFunction_818(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,818};
  data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */ = (200.0) * (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */);
  TRACE_POP
}
/*
 equation index: 819
 type: SIMPLE_ASSIGN
 MaterialStream3._F_p[2] = 200.0 * MaterialStream3.xliq
 */
void Flowsheet_eqFunction_819(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,819};
  data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */ = (200.0) * (data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */);
  TRACE_POP
}

void residualFunc826(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,826};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_real tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_real tmp19;
  /* iteration variables */
  data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */ = xloc[0];
  data->localData[0]->realVars[249] /* MaterialStream3._T variable */ = xloc[1];
  data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */ = xloc[2];
  data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ = xloc[3];
  data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ = xloc[4];
  data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */ = xloc[5];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_800(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_801(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_802(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_803(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_804(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_805(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_806(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_807(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_808(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_809(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_810(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_811(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_812(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_813(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_814(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_815(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_816(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_817(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_818(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_819(data, threadData);
  /* body */
  RELATIONHYSTERESIS(tmp0, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp1, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp3 = (tmp1?data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ - ((data->localData[0]->realVars[227] /* MaterialStream3._K_c[1] variable */) * (data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */)):data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */);
  }
  res[0] = tmp3;

  RELATIONHYSTERESIS(tmp4, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp5, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp7 = (tmp5?data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ - ((data->localData[0]->realVars[228] /* MaterialStream3._K_c[2] variable */) * (data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */)):data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */);
  }
  res[1] = tmp7;

  RELATIONHYSTERESIS(tmp8, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp9, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp11 = (tmp9?data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (-1.0 + data->localData[0]->realVars[227] /* MaterialStream3._K_c[1] variable */),"1.0 + MaterialStream3.xvap * (-1.0 + MaterialStream3.K_c[1])",equationIndexes):data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */);
  }
  res[2] = tmp11;

  RELATIONHYSTERESIS(tmp12, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */ - data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp13, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp15 = (tmp13?data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (-1.0 + data->localData[0]->realVars[228] /* MaterialStream3._K_c[2] variable */),"1.0 + MaterialStream3.xvap * (-1.0 + MaterialStream3.K_c[2])",equationIndexes):data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ - data->localData[0]->realVars[260] /* MaterialStream3._x_pc[1,1] variable */);
  }
  res[3] = tmp15;

  RELATIONHYSTERESIS(tmp16, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */ - data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp17, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp19 = (tmp17?data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */ + data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */ - data->localData[0]->realVars[261] /* MaterialStream3._x_pc[1,2] variable */);
  }
  res[4] = tmp19;

  res[5] = (data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */) * (data->localData[0]->realVars[217] /* MaterialStream3._H_p[3] variable */) + (data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */) * (data->localData[0]->realVars[216] /* MaterialStream3._H_p[2] variable */) - data->localData[0]->realVars[215] /* MaterialStream3._H_p[1] variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS826(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+6] = {0,4,6,5,4,4,4};
  const int rowIndex[27] = {1,2,3,5,0,1,2,3,4,5,1,2,3,4,5,0,3,4,5,1,2,4,5,0,2,3,5};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((6+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(27*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 27;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(6*sizeof(int));
  inSysData->sparsePattern.maxColors = 6;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (6+1)*sizeof(int));
  
  for(i=2;i<6+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 27*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[5] = 1;
  inSysData->sparsePattern.colorCols[4] = 2;
  inSysData->sparsePattern.colorCols[3] = 3;
  inSysData->sparsePattern.colorCols[2] = 4;
  inSysData->sparsePattern.colorCols[1] = 5;
  inSysData->sparsePattern.colorCols[0] = 6;
}
void initializeStaticDataNLS826(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream3.xvap */
  sysData->nominal[i] = data->modelData->realVarsData[275].attribute /* MaterialStream3._xvap */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[275].attribute /* MaterialStream3._xvap */.min;
  sysData->max[i++]   = data->modelData->realVarsData[275].attribute /* MaterialStream3._xvap */.max;
  /* static nls data for MaterialStream3.T */
  sysData->nominal[i] = data->modelData->realVarsData[249].attribute /* MaterialStream3._T */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[249].attribute /* MaterialStream3._T */.min;
  sysData->max[i++]   = data->modelData->realVarsData[249].attribute /* MaterialStream3._T */.max;
  /* static nls data for MaterialStream3.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[263].attribute /* MaterialStream3._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[263].attribute /* MaterialStream3._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[263].attribute /* MaterialStream3._x_pc[2,2] */.max;
  /* static nls data for MaterialStream3.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[264].attribute /* MaterialStream3._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[264].attribute /* MaterialStream3._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[264].attribute /* MaterialStream3._x_pc[3,1] */.max;
  /* static nls data for MaterialStream3.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[265].attribute /* MaterialStream3._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[265].attribute /* MaterialStream3._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[265].attribute /* MaterialStream3._x_pc[3,2] */.max;
  /* static nls data for MaterialStream3.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[262].attribute /* MaterialStream3._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[262].attribute /* MaterialStream3._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[262].attribute /* MaterialStream3._x_pc[2,1] */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS826(sysData);
}

void getIterationVarsNLS826(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */;
  array[1] = data->localData[0]->realVars[249] /* MaterialStream3._T variable */;
  array[2] = data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */;
  array[3] = data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */;
  array[4] = data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */;
  array[5] = data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void Flowsheet_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[0].equationIndex = 46;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0;
  nonLinearSystemData[0].mixedSystem = 0;
  nonLinearSystemData[0].residualFunc = residualFunc46;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = NULL;
  nonLinearSystemData[0].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[0].jacobianIndex = -1;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS46;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS46;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  
  nonLinearSystemData[1].equationIndex = 50;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0;
  nonLinearSystemData[1].mixedSystem = 0;
  nonLinearSystemData[1].residualFunc = residualFunc50;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = NULL;
  nonLinearSystemData[1].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[1].jacobianIndex = -1;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS50;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS50;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  
  nonLinearSystemData[2].equationIndex = 155;
  nonLinearSystemData[2].size = 1;
  nonLinearSystemData[2].homotopySupport = 0;
  nonLinearSystemData[2].mixedSystem = 0;
  nonLinearSystemData[2].residualFunc = residualFunc155;
  nonLinearSystemData[2].strictTearingFunctionCall = NULL;
  nonLinearSystemData[2].analyticalJacobianColumn = NULL;
  nonLinearSystemData[2].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[2].jacobianIndex = -1;
  nonLinearSystemData[2].initializeStaticNLSData = initializeStaticDataNLS155;
  nonLinearSystemData[2].getIterationVars = getIterationVarsNLS155;
  nonLinearSystemData[2].checkConstraints = NULL;
  
  
  nonLinearSystemData[3].equationIndex = 159;
  nonLinearSystemData[3].size = 1;
  nonLinearSystemData[3].homotopySupport = 0;
  nonLinearSystemData[3].mixedSystem = 0;
  nonLinearSystemData[3].residualFunc = residualFunc159;
  nonLinearSystemData[3].strictTearingFunctionCall = NULL;
  nonLinearSystemData[3].analyticalJacobianColumn = NULL;
  nonLinearSystemData[3].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[3].jacobianIndex = -1;
  nonLinearSystemData[3].initializeStaticNLSData = initializeStaticDataNLS159;
  nonLinearSystemData[3].getIterationVars = getIterationVarsNLS159;
  nonLinearSystemData[3].checkConstraints = NULL;
  
  
  nonLinearSystemData[4].equationIndex = 243;
  nonLinearSystemData[4].size = 1;
  nonLinearSystemData[4].homotopySupport = 0;
  nonLinearSystemData[4].mixedSystem = 0;
  nonLinearSystemData[4].residualFunc = residualFunc243;
  nonLinearSystemData[4].strictTearingFunctionCall = NULL;
  nonLinearSystemData[4].analyticalJacobianColumn = NULL;
  nonLinearSystemData[4].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[4].jacobianIndex = -1;
  nonLinearSystemData[4].initializeStaticNLSData = initializeStaticDataNLS243;
  nonLinearSystemData[4].getIterationVars = getIterationVarsNLS243;
  nonLinearSystemData[4].checkConstraints = NULL;
  
  
  nonLinearSystemData[5].equationIndex = 247;
  nonLinearSystemData[5].size = 1;
  nonLinearSystemData[5].homotopySupport = 0;
  nonLinearSystemData[5].mixedSystem = 0;
  nonLinearSystemData[5].residualFunc = residualFunc247;
  nonLinearSystemData[5].strictTearingFunctionCall = NULL;
  nonLinearSystemData[5].analyticalJacobianColumn = NULL;
  nonLinearSystemData[5].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[5].jacobianIndex = -1;
  nonLinearSystemData[5].initializeStaticNLSData = initializeStaticDataNLS247;
  nonLinearSystemData[5].getIterationVars = getIterationVarsNLS247;
  nonLinearSystemData[5].checkConstraints = NULL;
  
  
  nonLinearSystemData[6].equationIndex = 349;
  nonLinearSystemData[6].size = 1;
  nonLinearSystemData[6].homotopySupport = 0;
  nonLinearSystemData[6].mixedSystem = 0;
  nonLinearSystemData[6].residualFunc = residualFunc349;
  nonLinearSystemData[6].strictTearingFunctionCall = NULL;
  nonLinearSystemData[6].analyticalJacobianColumn = NULL;
  nonLinearSystemData[6].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[6].jacobianIndex = -1;
  nonLinearSystemData[6].initializeStaticNLSData = initializeStaticDataNLS349;
  nonLinearSystemData[6].getIterationVars = getIterationVarsNLS349;
  nonLinearSystemData[6].checkConstraints = NULL;
  
  
  nonLinearSystemData[7].equationIndex = 353;
  nonLinearSystemData[7].size = 1;
  nonLinearSystemData[7].homotopySupport = 0;
  nonLinearSystemData[7].mixedSystem = 0;
  nonLinearSystemData[7].residualFunc = residualFunc353;
  nonLinearSystemData[7].strictTearingFunctionCall = NULL;
  nonLinearSystemData[7].analyticalJacobianColumn = NULL;
  nonLinearSystemData[7].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[7].jacobianIndex = -1;
  nonLinearSystemData[7].initializeStaticNLSData = initializeStaticDataNLS353;
  nonLinearSystemData[7].getIterationVars = getIterationVarsNLS353;
  nonLinearSystemData[7].checkConstraints = NULL;
  
  
  nonLinearSystemData[8].equationIndex = 483;
  nonLinearSystemData[8].size = 5;
  nonLinearSystemData[8].homotopySupport = 0;
  nonLinearSystemData[8].mixedSystem = 0;
  nonLinearSystemData[8].residualFunc = residualFunc483;
  nonLinearSystemData[8].strictTearingFunctionCall = NULL;
  nonLinearSystemData[8].analyticalJacobianColumn = Flowsheet_functionJacNLSJac12_column;
  nonLinearSystemData[8].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianNLSJac12;
  nonLinearSystemData[8].jacobianIndex = 4;
  nonLinearSystemData[8].initializeStaticNLSData = initializeStaticDataNLS483;
  nonLinearSystemData[8].getIterationVars = getIterationVarsNLS483;
  nonLinearSystemData[8].checkConstraints = NULL;
  
  
  nonLinearSystemData[9].equationIndex = 548;
  nonLinearSystemData[9].size = 5;
  nonLinearSystemData[9].homotopySupport = 0;
  nonLinearSystemData[9].mixedSystem = 0;
  nonLinearSystemData[9].residualFunc = residualFunc548;
  nonLinearSystemData[9].strictTearingFunctionCall = NULL;
  nonLinearSystemData[9].analyticalJacobianColumn = Flowsheet_functionJacNLSJac13_column;
  nonLinearSystemData[9].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianNLSJac13;
  nonLinearSystemData[9].jacobianIndex = 5;
  nonLinearSystemData[9].initializeStaticNLSData = initializeStaticDataNLS548;
  nonLinearSystemData[9].getIterationVars = getIterationVarsNLS548;
  nonLinearSystemData[9].checkConstraints = NULL;
  
  
  nonLinearSystemData[10].equationIndex = 606;
  nonLinearSystemData[10].size = 6;
  nonLinearSystemData[10].homotopySupport = 0;
  nonLinearSystemData[10].mixedSystem = 1;
  nonLinearSystemData[10].residualFunc = residualFunc606;
  nonLinearSystemData[10].strictTearingFunctionCall = NULL;
  nonLinearSystemData[10].analyticalJacobianColumn = NULL;
  nonLinearSystemData[10].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[10].jacobianIndex = -1;
  nonLinearSystemData[10].initializeStaticNLSData = initializeStaticDataNLS606;
  nonLinearSystemData[10].getIterationVars = getIterationVarsNLS606;
  nonLinearSystemData[10].checkConstraints = NULL;
  
  nonLinearSystemData[11].equationIndex = 718;
  nonLinearSystemData[11].size = 5;
  nonLinearSystemData[11].homotopySupport = 0;
  nonLinearSystemData[11].mixedSystem = 0;
  nonLinearSystemData[11].residualFunc = residualFunc718;
  nonLinearSystemData[11].strictTearingFunctionCall = NULL;
  nonLinearSystemData[11].analyticalJacobianColumn = Flowsheet_functionJacNLSJac15_column;
  nonLinearSystemData[11].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianNLSJac15;
  nonLinearSystemData[11].jacobianIndex = 6;
  nonLinearSystemData[11].initializeStaticNLSData = initializeStaticDataNLS718;
  nonLinearSystemData[11].getIterationVars = getIterationVarsNLS718;
  nonLinearSystemData[11].checkConstraints = NULL;
  
  
  nonLinearSystemData[12].equationIndex = 768;
  nonLinearSystemData[12].size = 5;
  nonLinearSystemData[12].homotopySupport = 0;
  nonLinearSystemData[12].mixedSystem = 0;
  nonLinearSystemData[12].residualFunc = residualFunc768;
  nonLinearSystemData[12].strictTearingFunctionCall = NULL;
  nonLinearSystemData[12].analyticalJacobianColumn = Flowsheet_functionJacNLSJac16_column;
  nonLinearSystemData[12].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianNLSJac16;
  nonLinearSystemData[12].jacobianIndex = 7;
  nonLinearSystemData[12].initializeStaticNLSData = initializeStaticDataNLS768;
  nonLinearSystemData[12].getIterationVars = getIterationVarsNLS768;
  nonLinearSystemData[12].checkConstraints = NULL;
  
  
  nonLinearSystemData[13].equationIndex = 826;
  nonLinearSystemData[13].size = 6;
  nonLinearSystemData[13].homotopySupport = 0;
  nonLinearSystemData[13].mixedSystem = 1;
  nonLinearSystemData[13].residualFunc = residualFunc826;
  nonLinearSystemData[13].strictTearingFunctionCall = NULL;
  nonLinearSystemData[13].analyticalJacobianColumn = NULL;
  nonLinearSystemData[13].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[13].jacobianIndex = -1;
  nonLinearSystemData[13].initializeStaticNLSData = initializeStaticDataNLS826;
  nonLinearSystemData[13].getIterationVars = getIterationVarsNLS826;
  nonLinearSystemData[13].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif

