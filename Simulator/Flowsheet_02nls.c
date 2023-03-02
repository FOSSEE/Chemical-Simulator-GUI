/* Non Linear Systems */
#include "Flowsheet_model.h"
#include "Flowsheet_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
 equation index: 39
 type: SIMPLE_ASSIGN
 Heater1._Psatdg[2] = Simulator.Files.ThermodynamicFunctions.Psat({Heater1.C[2].VP[1], Heater1.C[2].VP[2], Heater1.C[2].VP[3], Heater1.C[2].VP[4], Heater1.C[2].VP[5], Heater1.C[2].VP[6]}, Heater1.Tdg)
 */
void Flowsheet_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[353], (modelica_real)data->simulationInfo->realParameter[354], (modelica_real)data->simulationInfo->realParameter[355], (modelica_real)data->simulationInfo->realParameter[356], (modelica_real)data->simulationInfo->realParameter[357], (modelica_real)data->simulationInfo->realParameter[358]);
  data->simulationInfo->realParameter[420] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[431]);
  TRACE_POP
}
/*
 equation index: 40
 type: SIMPLE_ASSIGN
 Heater1._Psatdg[1] = Simulator.Files.ThermodynamicFunctions.Psat({Heater1.C[1].VP[1], Heater1.C[1].VP[2], Heater1.C[1].VP[3], Heater1.C[1].VP[4], Heater1.C[1].VP[5], Heater1.C[1].VP[6]}, Heater1.Tdg)
 */
void Flowsheet_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[347], (modelica_real)data->simulationInfo->realParameter[348], (modelica_real)data->simulationInfo->realParameter[349], (modelica_real)data->simulationInfo->realParameter[350], (modelica_real)data->simulationInfo->realParameter[351], (modelica_real)data->simulationInfo->realParameter[352]);
  data->simulationInfo->realParameter[419] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[431]);
  TRACE_POP
}

void residualFunc42(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,42};
  /* iteration variables */
  data->simulationInfo->realParameter[431] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_39(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_40(data, threadData);
  /* body */
  res[0] = 1.0 - ((data->simulationInfo->realParameter[414]) * (DIVISION_SIM(data->simulationInfo->realParameter[436],data->simulationInfo->realParameter[419],"Heater1.Psatdg[1]",equationIndexes) + DIVISION_SIM(data->simulationInfo->realParameter[437],data->simulationInfo->realParameter[420],"Heater1.Psatdg[2]",equationIndexes)));
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS42(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS42(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for Heater1.Tdg */
  sysData->nominal[i] = data->modelData->realParameterData[431].attribute /* Heater1._Tdg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[431].attribute /* Heater1._Tdg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[431].attribute /* Heater1._Tdg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS42(sysData);
}

void getIterationVarsNLS42(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[431];
}


/* inner equations */

/*
 equation index: 43
 type: SIMPLE_ASSIGN
 Heater1._Psatbg[1] = Simulator.Files.ThermodynamicFunctions.Psat({Heater1.C[1].VP[1], Heater1.C[1].VP[2], Heater1.C[1].VP[3], Heater1.C[1].VP[4], Heater1.C[1].VP[5], Heater1.C[1].VP[6]}, Heater1.Tbg)
 */
void Flowsheet_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[347], (modelica_real)data->simulationInfo->realParameter[348], (modelica_real)data->simulationInfo->realParameter[349], (modelica_real)data->simulationInfo->realParameter[350], (modelica_real)data->simulationInfo->realParameter[351], (modelica_real)data->simulationInfo->realParameter[352]);
  data->simulationInfo->realParameter[417] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[428]);
  TRACE_POP
}
/*
 equation index: 44
 type: SIMPLE_ASSIGN
 Heater1._Psatbg[2] = Simulator.Files.ThermodynamicFunctions.Psat({Heater1.C[2].VP[1], Heater1.C[2].VP[2], Heater1.C[2].VP[3], Heater1.C[2].VP[4], Heater1.C[2].VP[5], Heater1.C[2].VP[6]}, Heater1.Tbg)
 */
void Flowsheet_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[353], (modelica_real)data->simulationInfo->realParameter[354], (modelica_real)data->simulationInfo->realParameter[355], (modelica_real)data->simulationInfo->realParameter[356], (modelica_real)data->simulationInfo->realParameter[357], (modelica_real)data->simulationInfo->realParameter[358]);
  data->simulationInfo->realParameter[418] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[428]);
  TRACE_POP
}

void residualFunc46(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,46};
  /* iteration variables */
  data->simulationInfo->realParameter[428] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_43(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_44(data, threadData);
  /* body */
  res[0] = (data->simulationInfo->realParameter[437]) * (data->simulationInfo->realParameter[418]) + (data->simulationInfo->realParameter[436]) * (data->simulationInfo->realParameter[417]) - data->simulationInfo->realParameter[414];
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
  /* static nls data for Heater1.Tbg */
  sysData->nominal[i] = data->modelData->realParameterData[428].attribute /* Heater1._Tbg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[428].attribute /* Heater1._Tbg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[428].attribute /* Heater1._Tbg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS46(sysData);
}

void getIterationVarsNLS46(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[428];
}


/* inner equations */

/*
 equation index: 128
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatdg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[2].VP[1], MaterialStream2.C[2].VP[2], MaterialStream2.C[2].VP[3], MaterialStream2.C[2].VP[4], MaterialStream2.C[2].VP[5], MaterialStream2.C[2].VP[6]}, MaterialStream2.Tdg)
 */
void Flowsheet_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[769], (modelica_real)data->simulationInfo->realParameter[770], (modelica_real)data->simulationInfo->realParameter[771], (modelica_real)data->simulationInfo->realParameter[772], (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774]);
  data->simulationInfo->realParameter[834] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[845]);
  TRACE_POP
}
/*
 equation index: 129
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatdg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[1].VP[1], MaterialStream2.C[1].VP[2], MaterialStream2.C[1].VP[3], MaterialStream2.C[1].VP[4], MaterialStream2.C[1].VP[5], MaterialStream2.C[1].VP[6]}, MaterialStream2.Tdg)
 */
void Flowsheet_eqFunction_129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,129};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[763], (modelica_real)data->simulationInfo->realParameter[764], (modelica_real)data->simulationInfo->realParameter[765], (modelica_real)data->simulationInfo->realParameter[766], (modelica_real)data->simulationInfo->realParameter[767], (modelica_real)data->simulationInfo->realParameter[768]);
  data->simulationInfo->realParameter[833] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[845]);
  TRACE_POP
}

void residualFunc131(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,131};
  /* iteration variables */
  data->simulationInfo->realParameter[845] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_128(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_129(data, threadData);
  /* body */
  res[0] = 1.0 - ((data->simulationInfo->realParameter[828]) * (DIVISION_SIM(data->simulationInfo->realParameter[850],data->simulationInfo->realParameter[833],"MaterialStream2.Psatdg[1]",equationIndexes) + DIVISION_SIM(data->simulationInfo->realParameter[851],data->simulationInfo->realParameter[834],"MaterialStream2.Psatdg[2]",equationIndexes)));
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS131(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS131(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream2.Tdg */
  sysData->nominal[i] = data->modelData->realParameterData[845].attribute /* MaterialStream2._Tdg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[845].attribute /* MaterialStream2._Tdg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[845].attribute /* MaterialStream2._Tdg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS131(sysData);
}

void getIterationVarsNLS131(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[845];
}


/* inner equations */

/*
 equation index: 132
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatbg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[2].VP[1], MaterialStream2.C[2].VP[2], MaterialStream2.C[2].VP[3], MaterialStream2.C[2].VP[4], MaterialStream2.C[2].VP[5], MaterialStream2.C[2].VP[6]}, MaterialStream2.Tbg)
 */
void Flowsheet_eqFunction_132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,132};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[769], (modelica_real)data->simulationInfo->realParameter[770], (modelica_real)data->simulationInfo->realParameter[771], (modelica_real)data->simulationInfo->realParameter[772], (modelica_real)data->simulationInfo->realParameter[773], (modelica_real)data->simulationInfo->realParameter[774]);
  data->simulationInfo->realParameter[832] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[842]);
  TRACE_POP
}
/*
 equation index: 133
 type: SIMPLE_ASSIGN
 MaterialStream2._Psatbg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream2.C[1].VP[1], MaterialStream2.C[1].VP[2], MaterialStream2.C[1].VP[3], MaterialStream2.C[1].VP[4], MaterialStream2.C[1].VP[5], MaterialStream2.C[1].VP[6]}, MaterialStream2.Tbg)
 */
void Flowsheet_eqFunction_133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,133};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[763], (modelica_real)data->simulationInfo->realParameter[764], (modelica_real)data->simulationInfo->realParameter[765], (modelica_real)data->simulationInfo->realParameter[766], (modelica_real)data->simulationInfo->realParameter[767], (modelica_real)data->simulationInfo->realParameter[768]);
  data->simulationInfo->realParameter[831] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[842]);
  TRACE_POP
}

void residualFunc135(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,135};
  /* iteration variables */
  data->simulationInfo->realParameter[842] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_132(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_133(data, threadData);
  /* body */
  res[0] = (data->simulationInfo->realParameter[851]) * (data->simulationInfo->realParameter[832]) + (data->simulationInfo->realParameter[850]) * (data->simulationInfo->realParameter[831]) - data->simulationInfo->realParameter[828];
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS135(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS135(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream2.Tbg */
  sysData->nominal[i] = data->modelData->realParameterData[842].attribute /* MaterialStream2._Tbg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[842].attribute /* MaterialStream2._Tbg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[842].attribute /* MaterialStream2._Tbg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS135(sysData);
}

void getIterationVarsNLS135(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[842];
}


/* inner equations */

/*
 equation index: 237
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatdg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[2].VP[1], MaterialStream1.C[2].VP[2], MaterialStream1.C[2].VP[3], MaterialStream1.C[2].VP[4], MaterialStream1.C[2].VP[5], MaterialStream1.C[2].VP[6]}, MaterialStream1.Tdg)
 */
void Flowsheet_eqFunction_237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,237};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[562], (modelica_real)data->simulationInfo->realParameter[563], (modelica_real)data->simulationInfo->realParameter[564], (modelica_real)data->simulationInfo->realParameter[565], (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567]);
  data->simulationInfo->realParameter[627] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[638]);
  TRACE_POP
}
/*
 equation index: 238
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatdg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[1].VP[1], MaterialStream1.C[1].VP[2], MaterialStream1.C[1].VP[3], MaterialStream1.C[1].VP[4], MaterialStream1.C[1].VP[5], MaterialStream1.C[1].VP[6]}, MaterialStream1.Tdg)
 */
void Flowsheet_eqFunction_238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,238};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[556], (modelica_real)data->simulationInfo->realParameter[557], (modelica_real)data->simulationInfo->realParameter[558], (modelica_real)data->simulationInfo->realParameter[559], (modelica_real)data->simulationInfo->realParameter[560], (modelica_real)data->simulationInfo->realParameter[561]);
  data->simulationInfo->realParameter[626] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[638]);
  TRACE_POP
}

void residualFunc240(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,240};
  /* iteration variables */
  data->simulationInfo->realParameter[638] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_237(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_238(data, threadData);
  /* body */
  res[0] = 1.0 - ((data->simulationInfo->realParameter[621]) * (DIVISION_SIM(data->simulationInfo->realParameter[643],data->simulationInfo->realParameter[626],"MaterialStream1.Psatdg[1]",equationIndexes) + DIVISION_SIM(data->simulationInfo->realParameter[644],data->simulationInfo->realParameter[627],"MaterialStream1.Psatdg[2]",equationIndexes)));
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS240(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS240(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream1.Tdg */
  sysData->nominal[i] = data->modelData->realParameterData[638].attribute /* MaterialStream1._Tdg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[638].attribute /* MaterialStream1._Tdg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[638].attribute /* MaterialStream1._Tdg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS240(sysData);
}

void getIterationVarsNLS240(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[638];
}


/* inner equations */

/*
 equation index: 241
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatbg[2] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[2].VP[1], MaterialStream1.C[2].VP[2], MaterialStream1.C[2].VP[3], MaterialStream1.C[2].VP[4], MaterialStream1.C[2].VP[5], MaterialStream1.C[2].VP[6]}, MaterialStream1.Tbg)
 */
void Flowsheet_eqFunction_241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,241};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[562], (modelica_real)data->simulationInfo->realParameter[563], (modelica_real)data->simulationInfo->realParameter[564], (modelica_real)data->simulationInfo->realParameter[565], (modelica_real)data->simulationInfo->realParameter[566], (modelica_real)data->simulationInfo->realParameter[567]);
  data->simulationInfo->realParameter[625] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[635]);
  TRACE_POP
}
/*
 equation index: 242
 type: SIMPLE_ASSIGN
 MaterialStream1._Psatbg[1] = Simulator.Files.ThermodynamicFunctions.Psat({MaterialStream1.C[1].VP[1], MaterialStream1.C[1].VP[2], MaterialStream1.C[1].VP[3], MaterialStream1.C[1].VP[4], MaterialStream1.C[1].VP[5], MaterialStream1.C[1].VP[6]}, MaterialStream1.Tbg)
 */
void Flowsheet_eqFunction_242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,242};
  real_array tmp0;
  array_alloc_scalar_real_array(&tmp0, 6, (modelica_real)data->simulationInfo->realParameter[556], (modelica_real)data->simulationInfo->realParameter[557], (modelica_real)data->simulationInfo->realParameter[558], (modelica_real)data->simulationInfo->realParameter[559], (modelica_real)data->simulationInfo->realParameter[560], (modelica_real)data->simulationInfo->realParameter[561]);
  data->simulationInfo->realParameter[624] = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, tmp0, data->simulationInfo->realParameter[635]);
  TRACE_POP
}

void residualFunc244(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,244};
  /* iteration variables */
  data->simulationInfo->realParameter[635] = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_241(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_242(data, threadData);
  /* body */
  res[0] = (data->simulationInfo->realParameter[644]) * (data->simulationInfo->realParameter[625]) + (data->simulationInfo->realParameter[643]) * (data->simulationInfo->realParameter[624]) - data->simulationInfo->realParameter[621];
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS244(NONLINEAR_SYSTEM_DATA* inSysData)
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
void initializeStaticDataNLS244(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream1.Tbg */
  sysData->nominal[i] = data->modelData->realParameterData[635].attribute /* MaterialStream1._Tbg */.nominal;
  sysData->min[i]     = data->modelData->realParameterData[635].attribute /* MaterialStream1._Tbg */.min;
  sysData->max[i++]   = data->modelData->realParameterData[635].attribute /* MaterialStream1._Tbg */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS244(sysData);
}

void getIterationVarsNLS244(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->simulationInfo->realParameter[635];
}


/* inner equations */

/*
 equation index: 360
 type: SIMPLE_ASSIGN
 Heater1._xvapout = (-MaterialStream2.xliq) - -1.0
 */
void Flowsheet_eqFunction_360(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,360};
  data->localData[0]->realVars[9] /* Heater1._xvapout variable */ = (-data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */) - (-1.0);
  TRACE_POP
}
/*
 equation index: 361
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p[3] = 100.0 - 100.0 * MaterialStream2.xliq
 */
void Flowsheet_eqFunction_361(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,361};
  data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */ = 100.0 - ((100.0) * (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */));
  TRACE_POP
}
/*
 equation index: 362
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p[2] = 100.0 * MaterialStream2.xliq
 */
void Flowsheet_eqFunction_362(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,362};
  data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */ = (100.0) * (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */);
  TRACE_POP
}

void residualFunc376(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,376};
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
  data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */ = xloc[0];
  data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */ = xloc[1];
  data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */ = xloc[2];
  data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ = xloc[3];
  data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ = xloc[4];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_360(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_361(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_362(data, threadData);
  /* body */
  tmp0 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */;
  }
  else
  {
    tmp1 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp3 = (tmp1?data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ - ((data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */) * (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */)):data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */);
  }
  res[0] = tmp3;

  tmp4 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */ - data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */;
  }
  else
  {
    tmp5 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp7 = (tmp5?data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ + data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ - data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */);
  }
  res[1] = tmp7;

  tmp8 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */;
  }
  else
  {
    tmp9 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp11 = (tmp9?data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ - ((data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */) * (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */)):data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */);
  }
  res[2] = tmp11;

  tmp12 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */;
  }
  else
  {
    tmp13 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp15 = (tmp13?data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (-1.0 + data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */),"1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[1])",equationIndexes):data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */);
  }
  res[3] = tmp15;

  tmp16 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */ - data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */;
  }
  else
  {
    tmp17 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp19 = (tmp17?data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (-1.0 + data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */),"1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[2])",equationIndexes):data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ - data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */);
  }
  res[4] = tmp19;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS376(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+5] = {0,3,4,3,3,3};
  const int rowIndex[16] = {0,3,4,0,1,3,4,2,3,4,1,2,4,0,1,3};
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
void initializeStaticDataNLS376(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream2.xliq */
  sysData->nominal[i] = data->modelData->realVarsData[178].attribute /* MaterialStream2._xliq */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[178].attribute /* MaterialStream2._xliq */.min;
  sysData->max[i++]   = data->modelData->realVarsData[178].attribute /* MaterialStream2._xliq */.max;
  /* static nls data for MaterialStream2.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[2,2] */.max;
  /* static nls data for MaterialStream2.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[2,1] */.max;
  /* static nls data for MaterialStream2.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[176].attribute /* MaterialStream2._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[176].attribute /* MaterialStream2._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[176].attribute /* MaterialStream2._x_pc[3,1] */.max;
  /* static nls data for MaterialStream2.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[177].attribute /* MaterialStream2._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[177].attribute /* MaterialStream2._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[177].attribute /* MaterialStream2._x_pc[3,2] */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS376(sysData);
}

void getIterationVarsNLS376(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */;
  array[1] = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */;
  array[2] = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */;
  array[3] = data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */;
  array[4] = data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */;
}


/* inner equations */

/*
 equation index: 414
 type: SIMPLE_ASSIGN
 Heater1._xvapin = (-MaterialStream1.xliq) - -1.0
 */
void Flowsheet_eqFunction_414(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,414};
  data->localData[0]->realVars[8] /* Heater1._xvapin variable */ = (-data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */) - (-1.0);
  TRACE_POP
}
/*
 equation index: 415
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[3] = 100.0 - 100.0 * MaterialStream1.xliq
 */
void Flowsheet_eqFunction_415(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,415};
  data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */ = 100.0 - ((100.0) * (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */));
  TRACE_POP
}
/*
 equation index: 416
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[2] = 100.0 * MaterialStream1.xliq
 */
void Flowsheet_eqFunction_416(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,416};
  data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */ = (100.0) * (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */);
  TRACE_POP
}

void residualFunc430(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,430};
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
  data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */ = xloc[0];
  data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */ = xloc[1];
  data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ = xloc[2];
  data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */ = xloc[3];
  data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ = xloc[4];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_414(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_415(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_416(data, threadData);
  /* body */
  tmp0 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */ - data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */;
  }
  else
  {
    tmp1 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp3 = (tmp1?data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ + data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ - data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */);
  }
  res[0] = tmp3;

  tmp4 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */ - data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */;
  }
  else
  {
    tmp5 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp7 = (tmp5?data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (-1.0 + data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */),"1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[2])",equationIndexes):data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ - data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */);
  }
  res[1] = tmp7;

  tmp8 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */;
  }
  else
  {
    tmp9 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp11 = (tmp9?data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ - ((data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */) * (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */)):data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */);
  }
  res[2] = tmp11;

  tmp12 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */;
  }
  else
  {
    tmp13 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp15 = (tmp13?data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (-1.0 + data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */),"1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[1])",equationIndexes):data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */);
  }
  res[3] = tmp15;

  tmp16 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */;
  }
  else
  {
    tmp17 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp19 = (tmp17?data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ - ((data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */) * (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */)):data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */);
  }
  res[4] = tmp19;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS430(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+5] = {0,3,3,3,4,3};
  const int rowIndex[16] = {1,2,3,1,3,4,0,2,3,0,1,2,3,0,1,4};
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
void initializeStaticDataNLS430(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream1.xliq */
  sysData->nominal[i] = data->modelData->realVarsData[91].attribute /* MaterialStream1._xliq */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[91].attribute /* MaterialStream1._xliq */.min;
  sysData->max[i++]   = data->modelData->realVarsData[91].attribute /* MaterialStream1._xliq */.max;
  /* static nls data for MaterialStream1.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[87].attribute /* MaterialStream1._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[87].attribute /* MaterialStream1._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[87].attribute /* MaterialStream1._x_pc[2,1] */.max;
  /* static nls data for MaterialStream1.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[90].attribute /* MaterialStream1._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[90].attribute /* MaterialStream1._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[90].attribute /* MaterialStream1._x_pc[3,2] */.max;
  /* static nls data for MaterialStream1.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[88].attribute /* MaterialStream1._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[88].attribute /* MaterialStream1._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[88].attribute /* MaterialStream1._x_pc[2,2] */.max;
  /* static nls data for MaterialStream1.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[89].attribute /* MaterialStream1._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[89].attribute /* MaterialStream1._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[89].attribute /* MaterialStream1._x_pc[3,1] */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS430(sysData);
}

void getIterationVarsNLS430(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */;
  array[1] = data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */;
  array[2] = data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */;
  array[3] = data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */;
  array[4] = data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */;
}

/* inner equations */

/*
 equation index: 507
 type: SIMPLE_ASSIGN
 Heater1._xvapin = (-MaterialStream1.xliq) - -1.0
 */
void Flowsheet_eqFunction_507(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,507};
  data->localData[0]->realVars[8] /* Heater1._xvapin variable */ = (-data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */) - (-1.0);
  TRACE_POP
}
/*
 equation index: 508
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[3] = 100.0 - 100.0 * MaterialStream1.xliq
 */
void Flowsheet_eqFunction_508(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,508};
  data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */ = 100.0 - ((100.0) * (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */));
  TRACE_POP
}
/*
 equation index: 509
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p[2] = 100.0 * MaterialStream1.xliq
 */
void Flowsheet_eqFunction_509(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,509};
  data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */ = (100.0) * (data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */);
  TRACE_POP
}

void residualFunc523(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,523};
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
  data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */ = xloc[0];
  data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */ = xloc[1];
  data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ = xloc[2];
  data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ = xloc[3];
  data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */ = xloc[4];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_507(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_508(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_509(data, threadData);
  /* body */
  tmp0 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */;
  }
  else
  {
    tmp1 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp3 = (tmp1?data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ - ((data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */) * (data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */)):data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */);
  }
  res[0] = tmp3;

  tmp4 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */;
  }
  else
  {
    tmp5 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp7 = (tmp5?data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (-1.0 + data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */),"1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[1])",equationIndexes):data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */);
  }
  res[1] = tmp7;

  tmp8 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */ - data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */;
  }
  else
  {
    tmp9 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp11 = (tmp9?data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ + data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */ - data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */);
  }
  res[2] = tmp11;

  tmp12 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */;
  }
  else
  {
    tmp13 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp15 = (tmp13?data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ - ((data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */) * (data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */)):data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */);
  }
  res[3] = tmp15;

  tmp16 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */ - data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */;
  }
  else
  {
    tmp17 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp19 = (tmp17?data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (-1.0 + data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */),"1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[2])",equationIndexes):data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */ - data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */);
  }
  res[4] = tmp19;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS523(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+5] = {0,3,3,3,3,4};
  const int rowIndex[16] = {0,1,4,1,3,4,2,3,4,0,1,2,0,1,2,4};
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
void initializeStaticDataNLS523(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream1.xliq */
  sysData->nominal[i] = data->modelData->realVarsData[91].attribute /* MaterialStream1._xliq */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[91].attribute /* MaterialStream1._xliq */.min;
  sysData->max[i++]   = data->modelData->realVarsData[91].attribute /* MaterialStream1._xliq */.max;
  /* static nls data for MaterialStream1.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[87].attribute /* MaterialStream1._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[87].attribute /* MaterialStream1._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[87].attribute /* MaterialStream1._x_pc[2,1] */.max;
  /* static nls data for MaterialStream1.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[89].attribute /* MaterialStream1._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[89].attribute /* MaterialStream1._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[89].attribute /* MaterialStream1._x_pc[3,1] */.max;
  /* static nls data for MaterialStream1.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[90].attribute /* MaterialStream1._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[90].attribute /* MaterialStream1._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[90].attribute /* MaterialStream1._x_pc[3,2] */.max;
  /* static nls data for MaterialStream1.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[88].attribute /* MaterialStream1._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[88].attribute /* MaterialStream1._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[88].attribute /* MaterialStream1._x_pc[2,2] */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS523(sysData);
}

void getIterationVarsNLS523(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */;
  array[1] = data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */;
  array[2] = data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */;
  array[3] = data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */;
  array[4] = data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */;
}


/* inner equations */

/*
 equation index: 565
 type: SIMPLE_ASSIGN
 Heater1._xvapout = (-MaterialStream2.xliq) - -1.0
 */
void Flowsheet_eqFunction_565(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,565};
  data->localData[0]->realVars[9] /* Heater1._xvapout variable */ = (-data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */) - (-1.0);
  TRACE_POP
}
/*
 equation index: 566
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p[3] = 100.0 - 100.0 * MaterialStream2.xliq
 */
void Flowsheet_eqFunction_566(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,566};
  data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */ = 100.0 - ((100.0) * (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */));
  TRACE_POP
}
/*
 equation index: 567
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p[2] = 100.0 * MaterialStream2.xliq
 */
void Flowsheet_eqFunction_567(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,567};
  data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */ = (100.0) * (data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */);
  TRACE_POP
}

void residualFunc581(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,581};
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
  data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */ = xloc[0];
  data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ = xloc[1];
  data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */ = xloc[2];
  data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ = xloc[3];
  data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */ = xloc[4];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Flowsheet_eqFunction_565(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_566(data, threadData);

  /* local constraints */
  Flowsheet_eqFunction_567(data, threadData);
  /* body */
  RELATIONHYSTERESIS(tmp0, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */ - data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp1, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp3 = (tmp1?data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ + data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ - 1.0:data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ - data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */);
  }
  res[0] = tmp3;

  RELATIONHYSTERESIS(tmp4, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp5, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp7 = (tmp5?data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ - ((data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */) * (data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */)):data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */);
  }
  res[1] = tmp7;

  RELATIONHYSTERESIS(tmp8, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp11 = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */ - data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp9, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp11 = (tmp9?data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */ - DIVISION_SIM(data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */,1.0 + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (-1.0 + data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */),"1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[2])",equationIndexes):data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */ - data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */);
  }
  res[2] = tmp11;

  RELATIONHYSTERESIS(tmp12, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp14 = (modelica_boolean)tmp12;
  if(tmp14)
  {
    tmp15 = data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp13, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp15 = (tmp13?data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */ - ((data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */) * (data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */)):data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */);
  }
  res[3] = tmp15;

  RELATIONHYSTERESIS(tmp16, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp18 = (modelica_boolean)tmp16;
  if(tmp18)
  {
    tmp19 = data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp17, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp19 = (tmp17?data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */ - DIVISION_SIM(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */,1.0 + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (-1.0 + data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */),"1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[1])",equationIndexes):data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */);
  }
  res[4] = tmp19;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS581(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+5] = {0,3,3,3,3,4};
  const int rowIndex[16] = {2,3,4,0,3,4,1,2,4,0,1,2,0,2,3,4};
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
void initializeStaticDataNLS581(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for MaterialStream2.xliq */
  sysData->nominal[i] = data->modelData->realVarsData[178].attribute /* MaterialStream2._xliq */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[178].attribute /* MaterialStream2._xliq */.min;
  sysData->max[i++]   = data->modelData->realVarsData[178].attribute /* MaterialStream2._xliq */.max;
  /* static nls data for MaterialStream2.x_pc[3,2] */
  sysData->nominal[i] = data->modelData->realVarsData[177].attribute /* MaterialStream2._x_pc[3,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[177].attribute /* MaterialStream2._x_pc[3,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[177].attribute /* MaterialStream2._x_pc[3,2] */.max;
  /* static nls data for MaterialStream2.x_pc[2,1] */
  sysData->nominal[i] = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[2,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[2,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[174].attribute /* MaterialStream2._x_pc[2,1] */.max;
  /* static nls data for MaterialStream2.x_pc[3,1] */
  sysData->nominal[i] = data->modelData->realVarsData[176].attribute /* MaterialStream2._x_pc[3,1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[176].attribute /* MaterialStream2._x_pc[3,1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[176].attribute /* MaterialStream2._x_pc[3,1] */.max;
  /* static nls data for MaterialStream2.x_pc[2,2] */
  sysData->nominal[i] = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[2,2] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[2,2] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[175].attribute /* MaterialStream2._x_pc[2,2] */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS581(sysData);
}

void getIterationVarsNLS581(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */;
  array[1] = data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */;
  array[2] = data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */;
  array[3] = data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */;
  array[4] = data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void Flowsheet_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[0].equationIndex = 42;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0;
  nonLinearSystemData[0].mixedSystem = 0;
  nonLinearSystemData[0].residualFunc = residualFunc42;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = NULL;
  nonLinearSystemData[0].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[0].jacobianIndex = -1;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS42;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS42;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  
  nonLinearSystemData[1].equationIndex = 46;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0;
  nonLinearSystemData[1].mixedSystem = 0;
  nonLinearSystemData[1].residualFunc = residualFunc46;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = NULL;
  nonLinearSystemData[1].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[1].jacobianIndex = -1;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS46;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS46;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  
  nonLinearSystemData[2].equationIndex = 131;
  nonLinearSystemData[2].size = 1;
  nonLinearSystemData[2].homotopySupport = 0;
  nonLinearSystemData[2].mixedSystem = 0;
  nonLinearSystemData[2].residualFunc = residualFunc131;
  nonLinearSystemData[2].strictTearingFunctionCall = NULL;
  nonLinearSystemData[2].analyticalJacobianColumn = NULL;
  nonLinearSystemData[2].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[2].jacobianIndex = -1;
  nonLinearSystemData[2].initializeStaticNLSData = initializeStaticDataNLS131;
  nonLinearSystemData[2].getIterationVars = getIterationVarsNLS131;
  nonLinearSystemData[2].checkConstraints = NULL;
  
  
  nonLinearSystemData[3].equationIndex = 135;
  nonLinearSystemData[3].size = 1;
  nonLinearSystemData[3].homotopySupport = 0;
  nonLinearSystemData[3].mixedSystem = 0;
  nonLinearSystemData[3].residualFunc = residualFunc135;
  nonLinearSystemData[3].strictTearingFunctionCall = NULL;
  nonLinearSystemData[3].analyticalJacobianColumn = NULL;
  nonLinearSystemData[3].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[3].jacobianIndex = -1;
  nonLinearSystemData[3].initializeStaticNLSData = initializeStaticDataNLS135;
  nonLinearSystemData[3].getIterationVars = getIterationVarsNLS135;
  nonLinearSystemData[3].checkConstraints = NULL;
  
  
  nonLinearSystemData[4].equationIndex = 240;
  nonLinearSystemData[4].size = 1;
  nonLinearSystemData[4].homotopySupport = 0;
  nonLinearSystemData[4].mixedSystem = 0;
  nonLinearSystemData[4].residualFunc = residualFunc240;
  nonLinearSystemData[4].strictTearingFunctionCall = NULL;
  nonLinearSystemData[4].analyticalJacobianColumn = NULL;
  nonLinearSystemData[4].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[4].jacobianIndex = -1;
  nonLinearSystemData[4].initializeStaticNLSData = initializeStaticDataNLS240;
  nonLinearSystemData[4].getIterationVars = getIterationVarsNLS240;
  nonLinearSystemData[4].checkConstraints = NULL;
  
  
  nonLinearSystemData[5].equationIndex = 244;
  nonLinearSystemData[5].size = 1;
  nonLinearSystemData[5].homotopySupport = 0;
  nonLinearSystemData[5].mixedSystem = 0;
  nonLinearSystemData[5].residualFunc = residualFunc244;
  nonLinearSystemData[5].strictTearingFunctionCall = NULL;
  nonLinearSystemData[5].analyticalJacobianColumn = NULL;
  nonLinearSystemData[5].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[5].jacobianIndex = -1;
  nonLinearSystemData[5].initializeStaticNLSData = initializeStaticDataNLS244;
  nonLinearSystemData[5].getIterationVars = getIterationVarsNLS244;
  nonLinearSystemData[5].checkConstraints = NULL;
  
  
  nonLinearSystemData[6].equationIndex = 376;
  nonLinearSystemData[6].size = 5;
  nonLinearSystemData[6].homotopySupport = 0;
  nonLinearSystemData[6].mixedSystem = 0;
  nonLinearSystemData[6].residualFunc = residualFunc376;
  nonLinearSystemData[6].strictTearingFunctionCall = NULL;
  nonLinearSystemData[6].analyticalJacobianColumn = Flowsheet_functionJacNLSJac9_column;
  nonLinearSystemData[6].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianNLSJac9;
  nonLinearSystemData[6].jacobianIndex = 3;
  nonLinearSystemData[6].initializeStaticNLSData = initializeStaticDataNLS376;
  nonLinearSystemData[6].getIterationVars = getIterationVarsNLS376;
  nonLinearSystemData[6].checkConstraints = NULL;
  
  
  nonLinearSystemData[7].equationIndex = 430;
  nonLinearSystemData[7].size = 5;
  nonLinearSystemData[7].homotopySupport = 0;
  nonLinearSystemData[7].mixedSystem = 0;
  nonLinearSystemData[7].residualFunc = residualFunc430;
  nonLinearSystemData[7].strictTearingFunctionCall = NULL;
  nonLinearSystemData[7].analyticalJacobianColumn = Flowsheet_functionJacNLSJac10_column;
  nonLinearSystemData[7].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianNLSJac10;
  nonLinearSystemData[7].jacobianIndex = 4;
  nonLinearSystemData[7].initializeStaticNLSData = initializeStaticDataNLS430;
  nonLinearSystemData[7].getIterationVars = getIterationVarsNLS430;
  nonLinearSystemData[7].checkConstraints = NULL;
  
  nonLinearSystemData[8].equationIndex = 523;
  nonLinearSystemData[8].size = 5;
  nonLinearSystemData[8].homotopySupport = 0;
  nonLinearSystemData[8].mixedSystem = 0;
  nonLinearSystemData[8].residualFunc = residualFunc523;
  nonLinearSystemData[8].strictTearingFunctionCall = NULL;
  nonLinearSystemData[8].analyticalJacobianColumn = Flowsheet_functionJacNLSJac11_column;
  nonLinearSystemData[8].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianNLSJac11;
  nonLinearSystemData[8].jacobianIndex = 5;
  nonLinearSystemData[8].initializeStaticNLSData = initializeStaticDataNLS523;
  nonLinearSystemData[8].getIterationVars = getIterationVarsNLS523;
  nonLinearSystemData[8].checkConstraints = NULL;
  
  
  nonLinearSystemData[9].equationIndex = 581;
  nonLinearSystemData[9].size = 5;
  nonLinearSystemData[9].homotopySupport = 0;
  nonLinearSystemData[9].mixedSystem = 0;
  nonLinearSystemData[9].residualFunc = residualFunc581;
  nonLinearSystemData[9].strictTearingFunctionCall = NULL;
  nonLinearSystemData[9].analyticalJacobianColumn = Flowsheet_functionJacNLSJac12_column;
  nonLinearSystemData[9].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianNLSJac12;
  nonLinearSystemData[9].jacobianIndex = 6;
  nonLinearSystemData[9].initializeStaticNLSData = initializeStaticDataNLS581;
  nonLinearSystemData[9].getIterationVars = getIterationVarsNLS581;
  nonLinearSystemData[9].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif

