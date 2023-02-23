/* Jacobians */
#include "Flowsheet_model.h"
#include "Flowsheet_12jac.h"

int Flowsheet_initialAnalyticJacobianNLSJac16(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac16;
  const int colPtrIndex[1+5] = {0,3,3,3,3,4};
  const int rowIndex[16] = {0,1,4,0,3,4,1,2,3,0,1,2,0,1,3,4};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 5;
  data->simulationInfo->analyticJacobians[index].sizeRows = 5;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 8;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(8,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(16*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 16;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 5;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 16*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[4] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 3;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 4;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 5;
  TRACE_POP
  return 0;
}

int Flowsheet_initialAnalyticJacobianNLSJac15(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac15;
  const int colPtrIndex[1+5] = {0,3,4,3,3,3};
  const int rowIndex[16] = {1,3,4,1,2,3,4,1,2,4,0,1,3,0,2,3};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 5;
  data->simulationInfo->analyticJacobians[index].sizeRows = 5;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 8;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(8,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(16*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 16;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 5;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 16*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[4] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 3;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 4;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 5;
  TRACE_POP
  return 0;
}

int Flowsheet_initialAnalyticJacobianNLSJac13(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac13;
  const int colPtrIndex[1+5] = {0,3,3,4,3,3};
  const int rowIndex[16] = {1,2,3,1,3,4,1,2,3,4,0,1,2,0,2,4};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 5;
  data->simulationInfo->analyticJacobians[index].sizeRows = 5;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 8;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(8,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(16*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 16;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 5;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 16*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[4] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 3;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 4;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 5;
  TRACE_POP
  return 0;
}

int Flowsheet_initialAnalyticJacobianNLSJac12(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac12;
  const int colPtrIndex[1+5] = {0,3,3,3,4,3};
  const int rowIndex[16] = {1,2,3,0,3,4,1,2,4,1,2,3,4,0,1,3};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 5;
  data->simulationInfo->analyticJacobians[index].sizeRows = 5;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 8;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(5,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(8,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((5+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(16*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 16;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(5*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 5;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (5+1)*sizeof(int));
  
  for(i=2;i<5+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 16*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[4] = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[3] = 2;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[2] = 3;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[1] = 4;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 5;
  TRACE_POP
  return 0;
}

int Flowsheet_initialAnalyticJacobianLSJac11(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac11;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 2;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(2,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int Flowsheet_initialAnalyticJacobianLSJac8(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac8;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 2;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(2,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int Flowsheet_initialAnalyticJacobianLSJac5(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac5;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 2;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(2,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}

int Flowsheet_initialAnalyticJacobianLSJac2(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac2;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 2;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(2,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}
int Flowsheet_initialAnalyticJacobianA(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Flowsheet_initialAnalyticJacobianB(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Flowsheet_initialAnalyticJacobianC(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Flowsheet_initialAnalyticJacobianD(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}


/*
 equation index: 760
 type: SIMPLE_ASSIGN
 MaterialStream2._xliq._$pDERNLSJac16._dummyVarNLSJac16 = -Mixer1_xvapin_s_2SeedNLSJac16
 */
void Flowsheet_eqFunction_760(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,760};
  $PMaterialStream2$Pxliq$P$pDERNLSJac16$PdummyVarNLSJac16 = (-$PMixer1_xvapin_s_2SeedNLSJac16);
  TRACE_POP
}

/*
 equation index: 761
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p._2._$pDERNLSJac16._dummyVarNLSJac16 = 100.0 * MaterialStream2.xliq.$pDERNLSJac16.dummyVarNLSJac16
 */
void Flowsheet_eqFunction_761(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,761};
  $PMaterialStream2$PF_p$P2$P$pDERNLSJac16$PdummyVarNLSJac16 = (100.0) * ($PMaterialStream2$Pxliq$P$pDERNLSJac16$PdummyVarNLSJac16);
  TRACE_POP
}

/*
 equation index: 762
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p._3._$pDERNLSJac16._dummyVarNLSJac16 = 100.0 * Mixer1_xvapin_s_2SeedNLSJac16
 */
void Flowsheet_eqFunction_762(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,762};
  $PMaterialStream2$PF_p$P3$P$pDERNLSJac16$PdummyVarNLSJac16 = (100.0) * ($PMixer1_xvapin_s_2SeedNLSJac16);
  TRACE_POP
}

/*
 equation index: 763
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac16._dummyVarNLSJac16 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2_x_pc_3_2SeedNLSJac16 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_2_1SeedNLSJac16 + DIVISION(MaterialStream2.x_pc[1,1] * Mixer1_xvapin_s_2SeedNLSJac16 * (-1.0 + MaterialStream2.K_c[1]), (1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[1])) ^ 2.0) else MaterialStream2_x_pc_2_2SeedNLSJac16
 */
void Flowsheet_eqFunction_763(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,763};
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  modelica_real tmp26;
  modelica_boolean tmp27;
  modelica_real tmp28;
  modelica_boolean tmp29;
  modelica_real tmp30;
  tmp24 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp29 = (modelica_boolean)tmp24;
  if(tmp29)
  {
    tmp30 = $PMaterialStream2_x_pc_3_2SeedNLSJac16;
  }
  else
  {
    tmp25 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp27 = (modelica_boolean)tmp25;
    if(tmp27)
    {
      tmp26 = 1.0 + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (-1.0 + data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */);
      tmp28 = $PMaterialStream2_x_pc_2_1SeedNLSJac16 + DIVISION_SIM((data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (($PMixer1_xvapin_s_2SeedNLSJac16) * (-1.0 + data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */)),(tmp26 * tmp26),"(1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[1])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp28 = $PMaterialStream2_x_pc_2_2SeedNLSJac16;
    }
    tmp30 = tmp28;
  }
  $P$res$P1$P$pDERNLSJac16$PdummyVarNLSJac16 = tmp30;
  TRACE_POP
}

/*
 equation index: 764
 type: SIMPLE_ASSIGN
 $res._2._$pDERNLSJac16._dummyVarNLSJac16 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2_x_pc_2_1SeedNLSJac16 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_2_2SeedNLSJac16 + DIVISION(MaterialStream2.x_pc[1,2] * Mixer1_xvapin_s_2SeedNLSJac16 * (-1.0 + MaterialStream2.K_c[2]), (1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[2])) ^ 2.0) else MaterialStream2_x_pc_3_1SeedNLSJac16
 */
void Flowsheet_eqFunction_764(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,764};
  modelica_boolean tmp31;
  modelica_boolean tmp32;
  modelica_real tmp33;
  modelica_boolean tmp34;
  modelica_real tmp35;
  modelica_boolean tmp36;
  modelica_real tmp37;
  tmp31 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp36 = (modelica_boolean)tmp31;
  if(tmp36)
  {
    tmp37 = $PMaterialStream2_x_pc_2_1SeedNLSJac16;
  }
  else
  {
    tmp32 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp34 = (modelica_boolean)tmp32;
    if(tmp34)
    {
      tmp33 = 1.0 + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (-1.0 + data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */);
      tmp35 = $PMaterialStream2_x_pc_2_2SeedNLSJac16 + DIVISION_SIM((data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (($PMixer1_xvapin_s_2SeedNLSJac16) * (-1.0 + data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */)),(tmp33 * tmp33),"(1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[2])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp35 = $PMaterialStream2_x_pc_3_1SeedNLSJac16;
    }
    tmp37 = tmp35;
  }
  $P$res$P2$P$pDERNLSJac16$PdummyVarNLSJac16 = tmp37;
  TRACE_POP
}

/*
 equation index: 765
 type: SIMPLE_ASSIGN
 $res._3._$pDERNLSJac16._dummyVarNLSJac16 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2_x_pc_3_1SeedNLSJac16 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_1SeedNLSJac16 - MaterialStream2.K_c[1] * MaterialStream2_x_pc_2_1SeedNLSJac16 else MaterialStream2_x_pc_2_1SeedNLSJac16
 */
void Flowsheet_eqFunction_765(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,765};
  modelica_boolean tmp38;
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  modelica_real tmp41;
  tmp38 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp40 = (modelica_boolean)tmp38;
  if(tmp40)
  {
    tmp41 = $PMaterialStream2_x_pc_3_1SeedNLSJac16;
  }
  else
  {
    tmp39 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp41 = (tmp39?$PMaterialStream2_x_pc_3_1SeedNLSJac16 - ((data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */) * ($PMaterialStream2_x_pc_2_1SeedNLSJac16)):$PMaterialStream2_x_pc_2_1SeedNLSJac16);
  }
  $P$res$P3$P$pDERNLSJac16$PdummyVarNLSJac16 = tmp41;
  TRACE_POP
}

/*
 equation index: 766
 type: SIMPLE_ASSIGN
 $res._4._$pDERNLSJac16._dummyVarNLSJac16 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2_x_pc_2_2SeedNLSJac16 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_1SeedNLSJac16 + MaterialStream2_x_pc_3_2SeedNLSJac16 else MaterialStream2_x_pc_3_2SeedNLSJac16
 */
void Flowsheet_eqFunction_766(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,766};
  modelica_boolean tmp42;
  modelica_boolean tmp43;
  modelica_boolean tmp44;
  modelica_real tmp45;
  tmp42 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp44 = (modelica_boolean)tmp42;
  if(tmp44)
  {
    tmp45 = $PMaterialStream2_x_pc_2_2SeedNLSJac16;
  }
  else
  {
    tmp43 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp45 = (tmp43?$PMaterialStream2_x_pc_3_1SeedNLSJac16 + $PMaterialStream2_x_pc_3_2SeedNLSJac16:$PMaterialStream2_x_pc_3_2SeedNLSJac16);
  }
  $P$res$P4$P$pDERNLSJac16$PdummyVarNLSJac16 = tmp45;
  TRACE_POP
}

/*
 equation index: 767
 type: SIMPLE_ASSIGN
 $res._5._$pDERNLSJac16._dummyVarNLSJac16 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2.F_p.3.$pDERNLSJac16.dummyVarNLSJac16 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_2SeedNLSJac16 - MaterialStream2.K_c[2] * MaterialStream2_x_pc_2_2SeedNLSJac16 else MaterialStream2.F_p.2.$pDERNLSJac16.dummyVarNLSJac16
 */
void Flowsheet_eqFunction_767(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,767};
  modelica_boolean tmp46;
  modelica_boolean tmp47;
  modelica_boolean tmp48;
  modelica_real tmp49;
  tmp46 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp48 = (modelica_boolean)tmp46;
  if(tmp48)
  {
    tmp49 = $PMaterialStream2$PF_p$P3$P$pDERNLSJac16$PdummyVarNLSJac16;
  }
  else
  {
    tmp47 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp49 = (tmp47?$PMaterialStream2_x_pc_3_2SeedNLSJac16 - ((data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */) * ($PMaterialStream2_x_pc_2_2SeedNLSJac16)):$PMaterialStream2$PF_p$P2$P$pDERNLSJac16$PdummyVarNLSJac16);
  }
  $P$res$P5$P$pDERNLSJac16$PdummyVarNLSJac16 = tmp49;
  TRACE_POP
}
int Flowsheet_functionJacNLSJac16_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac16;
  Flowsheet_eqFunction_760(data, threadData);

  Flowsheet_eqFunction_761(data, threadData);

  Flowsheet_eqFunction_762(data, threadData);

  Flowsheet_eqFunction_763(data, threadData);

  Flowsheet_eqFunction_764(data, threadData);

  Flowsheet_eqFunction_765(data, threadData);

  Flowsheet_eqFunction_766(data, threadData);

  Flowsheet_eqFunction_767(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 710
 type: SIMPLE_ASSIGN
 MaterialStream1._xliq._$pDERNLSJac15._dummyVarNLSJac15 = -Mixer1_xvapin_s_1SeedNLSJac15
 */
void Flowsheet_eqFunction_710(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,710};
  $PMaterialStream1$Pxliq$P$pDERNLSJac15$PdummyVarNLSJac15 = (-$PMixer1_xvapin_s_1SeedNLSJac15);
  TRACE_POP
}

/*
 equation index: 711
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p._2._$pDERNLSJac15._dummyVarNLSJac15 = 100.0 * MaterialStream1.xliq.$pDERNLSJac15.dummyVarNLSJac15
 */
void Flowsheet_eqFunction_711(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,711};
  $PMaterialStream1$PF_p$P2$P$pDERNLSJac15$PdummyVarNLSJac15 = (100.0) * ($PMaterialStream1$Pxliq$P$pDERNLSJac15$PdummyVarNLSJac15);
  TRACE_POP
}

/*
 equation index: 712
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p._3._$pDERNLSJac15._dummyVarNLSJac15 = 100.0 * Mixer1_xvapin_s_1SeedNLSJac15
 */
void Flowsheet_eqFunction_712(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,712};
  $PMaterialStream1$PF_p$P3$P$pDERNLSJac15$PdummyVarNLSJac15 = (100.0) * ($PMixer1_xvapin_s_1SeedNLSJac15);
  TRACE_POP
}

/*
 equation index: 713
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac15._dummyVarNLSJac15 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_3_1SeedNLSJac15 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_1SeedNLSJac15 - MaterialStream1.K_c[1] * MaterialStream1_x_pc_2_1SeedNLSJac15 else MaterialStream1_x_pc_2_1SeedNLSJac15
 */
void Flowsheet_eqFunction_713(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,713};
  modelica_boolean tmp50;
  modelica_boolean tmp51;
  modelica_boolean tmp52;
  modelica_real tmp53;
  tmp50 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp52 = (modelica_boolean)tmp50;
  if(tmp52)
  {
    tmp53 = $PMaterialStream1_x_pc_3_1SeedNLSJac15;
  }
  else
  {
    tmp51 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp53 = (tmp51?$PMaterialStream1_x_pc_3_1SeedNLSJac15 - ((data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */) * ($PMaterialStream1_x_pc_2_1SeedNLSJac15)):$PMaterialStream1_x_pc_2_1SeedNLSJac15);
  }
  $P$res$P1$P$pDERNLSJac15$PdummyVarNLSJac15 = tmp53;
  TRACE_POP
}

/*
 equation index: 714
 type: SIMPLE_ASSIGN
 $res._2._$pDERNLSJac15._dummyVarNLSJac15 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_3_2SeedNLSJac15 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_2_1SeedNLSJac15 + DIVISION(MaterialStream1.x_pc[1,1] * Mixer1_xvapin_s_1SeedNLSJac15 * (-1.0 + MaterialStream1.K_c[1]), (1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[1])) ^ 2.0) else MaterialStream1_x_pc_2_2SeedNLSJac15
 */
void Flowsheet_eqFunction_714(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,714};
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  modelica_real tmp56;
  modelica_boolean tmp57;
  modelica_real tmp58;
  modelica_boolean tmp59;
  modelica_real tmp60;
  tmp54 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp59 = (modelica_boolean)tmp54;
  if(tmp59)
  {
    tmp60 = $PMaterialStream1_x_pc_3_2SeedNLSJac15;
  }
  else
  {
    tmp55 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp57 = (modelica_boolean)tmp55;
    if(tmp57)
    {
      tmp56 = 1.0 + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (-1.0 + data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */);
      tmp58 = $PMaterialStream1_x_pc_2_1SeedNLSJac15 + DIVISION_SIM((data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (($PMixer1_xvapin_s_1SeedNLSJac15) * (-1.0 + data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */)),(tmp56 * tmp56),"(1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[1])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp58 = $PMaterialStream1_x_pc_2_2SeedNLSJac15;
    }
    tmp60 = tmp58;
  }
  $P$res$P2$P$pDERNLSJac15$PdummyVarNLSJac15 = tmp60;
  TRACE_POP
}

/*
 equation index: 715
 type: SIMPLE_ASSIGN
 $res._3._$pDERNLSJac15._dummyVarNLSJac15 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_2_2SeedNLSJac15 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_1SeedNLSJac15 + MaterialStream1_x_pc_3_2SeedNLSJac15 else MaterialStream1_x_pc_3_2SeedNLSJac15
 */
void Flowsheet_eqFunction_715(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,715};
  modelica_boolean tmp61;
  modelica_boolean tmp62;
  modelica_boolean tmp63;
  modelica_real tmp64;
  tmp61 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp63 = (modelica_boolean)tmp61;
  if(tmp63)
  {
    tmp64 = $PMaterialStream1_x_pc_2_2SeedNLSJac15;
  }
  else
  {
    tmp62 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp64 = (tmp62?$PMaterialStream1_x_pc_3_1SeedNLSJac15 + $PMaterialStream1_x_pc_3_2SeedNLSJac15:$PMaterialStream1_x_pc_3_2SeedNLSJac15);
  }
  $P$res$P3$P$pDERNLSJac15$PdummyVarNLSJac15 = tmp64;
  TRACE_POP
}

/*
 equation index: 716
 type: SIMPLE_ASSIGN
 $res._4._$pDERNLSJac15._dummyVarNLSJac15 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_2_1SeedNLSJac15 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_2_2SeedNLSJac15 + DIVISION(MaterialStream1.x_pc[1,2] * Mixer1_xvapin_s_1SeedNLSJac15 * (-1.0 + MaterialStream1.K_c[2]), (1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[2])) ^ 2.0) else MaterialStream1_x_pc_3_1SeedNLSJac15
 */
void Flowsheet_eqFunction_716(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,716};
  modelica_boolean tmp65;
  modelica_boolean tmp66;
  modelica_real tmp67;
  modelica_boolean tmp68;
  modelica_real tmp69;
  modelica_boolean tmp70;
  modelica_real tmp71;
  tmp65 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp70 = (modelica_boolean)tmp65;
  if(tmp70)
  {
    tmp71 = $PMaterialStream1_x_pc_2_1SeedNLSJac15;
  }
  else
  {
    tmp66 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp68 = (modelica_boolean)tmp66;
    if(tmp68)
    {
      tmp67 = 1.0 + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (-1.0 + data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */);
      tmp69 = $PMaterialStream1_x_pc_2_2SeedNLSJac15 + DIVISION_SIM((data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (($PMixer1_xvapin_s_1SeedNLSJac15) * (-1.0 + data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */)),(tmp67 * tmp67),"(1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[2])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp69 = $PMaterialStream1_x_pc_3_1SeedNLSJac15;
    }
    tmp71 = tmp69;
  }
  $P$res$P4$P$pDERNLSJac15$PdummyVarNLSJac15 = tmp71;
  TRACE_POP
}

/*
 equation index: 717
 type: SIMPLE_ASSIGN
 $res._5._$pDERNLSJac15._dummyVarNLSJac15 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1.F_p.3.$pDERNLSJac15.dummyVarNLSJac15 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_2SeedNLSJac15 - MaterialStream1.K_c[2] * MaterialStream1_x_pc_2_2SeedNLSJac15 else MaterialStream1.F_p.2.$pDERNLSJac15.dummyVarNLSJac15
 */
void Flowsheet_eqFunction_717(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,717};
  modelica_boolean tmp72;
  modelica_boolean tmp73;
  modelica_boolean tmp74;
  modelica_real tmp75;
  tmp72 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp74 = (modelica_boolean)tmp72;
  if(tmp74)
  {
    tmp75 = $PMaterialStream1$PF_p$P3$P$pDERNLSJac15$PdummyVarNLSJac15;
  }
  else
  {
    tmp73 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp75 = (tmp73?$PMaterialStream1_x_pc_3_2SeedNLSJac15 - ((data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */) * ($PMaterialStream1_x_pc_2_2SeedNLSJac15)):$PMaterialStream1$PF_p$P2$P$pDERNLSJac15$PdummyVarNLSJac15);
  }
  $P$res$P5$P$pDERNLSJac15$PdummyVarNLSJac15 = tmp75;
  TRACE_POP
}
int Flowsheet_functionJacNLSJac15_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac15;
  Flowsheet_eqFunction_710(data, threadData);

  Flowsheet_eqFunction_711(data, threadData);

  Flowsheet_eqFunction_712(data, threadData);

  Flowsheet_eqFunction_713(data, threadData);

  Flowsheet_eqFunction_714(data, threadData);

  Flowsheet_eqFunction_715(data, threadData);

  Flowsheet_eqFunction_716(data, threadData);

  Flowsheet_eqFunction_717(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 540
 type: SIMPLE_ASSIGN
 MaterialStream2._xliq._$pDERNLSJac13._dummyVarNLSJac13 = -Mixer1_xvapin_s_2SeedNLSJac13
 */
void Flowsheet_eqFunction_540(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,540};
  $PMaterialStream2$Pxliq$P$pDERNLSJac13$PdummyVarNLSJac13 = (-$PMixer1_xvapin_s_2SeedNLSJac13);
  TRACE_POP
}

/*
 equation index: 541
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p._2._$pDERNLSJac13._dummyVarNLSJac13 = 100.0 * MaterialStream2.xliq.$pDERNLSJac13.dummyVarNLSJac13
 */
void Flowsheet_eqFunction_541(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,541};
  $PMaterialStream2$PF_p$P2$P$pDERNLSJac13$PdummyVarNLSJac13 = (100.0) * ($PMaterialStream2$Pxliq$P$pDERNLSJac13$PdummyVarNLSJac13);
  TRACE_POP
}

/*
 equation index: 542
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p._3._$pDERNLSJac13._dummyVarNLSJac13 = 100.0 * Mixer1_xvapin_s_2SeedNLSJac13
 */
void Flowsheet_eqFunction_542(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,542};
  $PMaterialStream2$PF_p$P3$P$pDERNLSJac13$PdummyVarNLSJac13 = (100.0) * ($PMixer1_xvapin_s_2SeedNLSJac13);
  TRACE_POP
}

/*
 equation index: 543
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac13._dummyVarNLSJac13 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2_x_pc_3_1SeedNLSJac13 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_1SeedNLSJac13 - MaterialStream2.K_c[1] * MaterialStream2_x_pc_2_1SeedNLSJac13 else MaterialStream2_x_pc_2_1SeedNLSJac13
 */
void Flowsheet_eqFunction_543(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,543};
  modelica_boolean tmp76;
  modelica_boolean tmp77;
  modelica_boolean tmp78;
  modelica_real tmp79;
  tmp76 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp78 = (modelica_boolean)tmp76;
  if(tmp78)
  {
    tmp79 = $PMaterialStream2_x_pc_3_1SeedNLSJac13;
  }
  else
  {
    tmp77 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp79 = (tmp77?$PMaterialStream2_x_pc_3_1SeedNLSJac13 - ((data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */) * ($PMaterialStream2_x_pc_2_1SeedNLSJac13)):$PMaterialStream2_x_pc_2_1SeedNLSJac13);
  }
  $P$res$P1$P$pDERNLSJac13$PdummyVarNLSJac13 = tmp79;
  TRACE_POP
}

/*
 equation index: 544
 type: SIMPLE_ASSIGN
 $res._2._$pDERNLSJac13._dummyVarNLSJac13 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2_x_pc_3_2SeedNLSJac13 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_2_1SeedNLSJac13 + DIVISION(MaterialStream2.x_pc[1,1] * Mixer1_xvapin_s_2SeedNLSJac13 * (-1.0 + MaterialStream2.K_c[1]), (1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[1])) ^ 2.0) else MaterialStream2_x_pc_2_2SeedNLSJac13
 */
void Flowsheet_eqFunction_544(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,544};
  modelica_boolean tmp80;
  modelica_boolean tmp81;
  modelica_real tmp82;
  modelica_boolean tmp83;
  modelica_real tmp84;
  modelica_boolean tmp85;
  modelica_real tmp86;
  tmp80 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp85 = (modelica_boolean)tmp80;
  if(tmp85)
  {
    tmp86 = $PMaterialStream2_x_pc_3_2SeedNLSJac13;
  }
  else
  {
    tmp81 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp83 = (modelica_boolean)tmp81;
    if(tmp83)
    {
      tmp82 = 1.0 + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (-1.0 + data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */);
      tmp84 = $PMaterialStream2_x_pc_2_1SeedNLSJac13 + DIVISION_SIM((data->localData[0]->realVars[170] /* MaterialStream2._x_pc[1,1] variable */) * (($PMixer1_xvapin_s_2SeedNLSJac13) * (-1.0 + data->localData[0]->realVars[137] /* MaterialStream2._K_c[1] variable */)),(tmp82 * tmp82),"(1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[1])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp84 = $PMaterialStream2_x_pc_2_2SeedNLSJac13;
    }
    tmp86 = tmp84;
  }
  $P$res$P2$P$pDERNLSJac13$PdummyVarNLSJac13 = tmp86;
  TRACE_POP
}

/*
 equation index: 545
 type: SIMPLE_ASSIGN
 $res._3._$pDERNLSJac13._dummyVarNLSJac13 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2_x_pc_2_1SeedNLSJac13 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_2_2SeedNLSJac13 + DIVISION(MaterialStream2.x_pc[1,2] * Mixer1_xvapin_s_2SeedNLSJac13 * (-1.0 + MaterialStream2.K_c[2]), (1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[2])) ^ 2.0) else MaterialStream2_x_pc_3_1SeedNLSJac13
 */
void Flowsheet_eqFunction_545(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,545};
  modelica_boolean tmp87;
  modelica_boolean tmp88;
  modelica_real tmp89;
  modelica_boolean tmp90;
  modelica_real tmp91;
  modelica_boolean tmp92;
  modelica_real tmp93;
  tmp87 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp92 = (modelica_boolean)tmp87;
  if(tmp92)
  {
    tmp93 = $PMaterialStream2_x_pc_2_1SeedNLSJac13;
  }
  else
  {
    tmp88 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp90 = (modelica_boolean)tmp88;
    if(tmp90)
    {
      tmp89 = 1.0 + (data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */) * (-1.0 + data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */);
      tmp91 = $PMaterialStream2_x_pc_2_2SeedNLSJac13 + DIVISION_SIM((data->localData[0]->realVars[171] /* MaterialStream2._x_pc[1,2] variable */) * (($PMixer1_xvapin_s_2SeedNLSJac13) * (-1.0 + data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */)),(tmp89 * tmp89),"(1.0 + Mixer1.xvapin_s[2] * (-1.0 + MaterialStream2.K_c[2])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp91 = $PMaterialStream2_x_pc_3_1SeedNLSJac13;
    }
    tmp93 = tmp91;
  }
  $P$res$P3$P$pDERNLSJac13$PdummyVarNLSJac13 = tmp93;
  TRACE_POP
}

/*
 equation index: 546
 type: SIMPLE_ASSIGN
 $res._4._$pDERNLSJac13._dummyVarNLSJac13 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2.F_p.3.$pDERNLSJac13.dummyVarNLSJac13 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_2SeedNLSJac13 - MaterialStream2.K_c[2] * MaterialStream2_x_pc_2_2SeedNLSJac13 else MaterialStream2.F_p.2.$pDERNLSJac13.dummyVarNLSJac13
 */
void Flowsheet_eqFunction_546(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,546};
  modelica_boolean tmp94;
  modelica_boolean tmp95;
  modelica_boolean tmp96;
  modelica_real tmp97;
  tmp94 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp96 = (modelica_boolean)tmp94;
  if(tmp96)
  {
    tmp97 = $PMaterialStream2$PF_p$P3$P$pDERNLSJac13$PdummyVarNLSJac13;
  }
  else
  {
    tmp95 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp97 = (tmp95?$PMaterialStream2_x_pc_3_2SeedNLSJac13 - ((data->localData[0]->realVars[138] /* MaterialStream2._K_c[2] variable */) * ($PMaterialStream2_x_pc_2_2SeedNLSJac13)):$PMaterialStream2$PF_p$P2$P$pDERNLSJac13$PdummyVarNLSJac13);
  }
  $P$res$P4$P$pDERNLSJac13$PdummyVarNLSJac13 = tmp97;
  TRACE_POP
}

/*
 equation index: 547
 type: SIMPLE_ASSIGN
 $res._5._$pDERNLSJac13._dummyVarNLSJac13 = if 101325.0 >= MaterialStream2.Pbubl then MaterialStream2_x_pc_2_2SeedNLSJac13 else if 101325.0 >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_1SeedNLSJac13 + MaterialStream2_x_pc_3_2SeedNLSJac13 else MaterialStream2_x_pc_3_2SeedNLSJac13
 */
void Flowsheet_eqFunction_547(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,547};
  modelica_boolean tmp98;
  modelica_boolean tmp99;
  modelica_boolean tmp100;
  modelica_real tmp101;
  tmp98 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp100 = (modelica_boolean)tmp98;
  if(tmp100)
  {
    tmp101 = $PMaterialStream2_x_pc_2_2SeedNLSJac13;
  }
  else
  {
    tmp99 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp101 = (tmp99?$PMaterialStream2_x_pc_3_1SeedNLSJac13 + $PMaterialStream2_x_pc_3_2SeedNLSJac13:$PMaterialStream2_x_pc_3_2SeedNLSJac13);
  }
  $P$res$P5$P$pDERNLSJac13$PdummyVarNLSJac13 = tmp101;
  TRACE_POP
}
int Flowsheet_functionJacNLSJac13_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac13;
  Flowsheet_eqFunction_540(data, threadData);

  Flowsheet_eqFunction_541(data, threadData);

  Flowsheet_eqFunction_542(data, threadData);

  Flowsheet_eqFunction_543(data, threadData);

  Flowsheet_eqFunction_544(data, threadData);

  Flowsheet_eqFunction_545(data, threadData);

  Flowsheet_eqFunction_546(data, threadData);

  Flowsheet_eqFunction_547(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 475
 type: SIMPLE_ASSIGN
 MaterialStream1._xliq._$pDERNLSJac12._dummyVarNLSJac12 = -Mixer1_xvapin_s_1SeedNLSJac12
 */
void Flowsheet_eqFunction_475(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,475};
  $PMaterialStream1$Pxliq$P$pDERNLSJac12$PdummyVarNLSJac12 = (-$PMixer1_xvapin_s_1SeedNLSJac12);
  TRACE_POP
}

/*
 equation index: 476
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p._2._$pDERNLSJac12._dummyVarNLSJac12 = 100.0 * MaterialStream1.xliq.$pDERNLSJac12.dummyVarNLSJac12
 */
void Flowsheet_eqFunction_476(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,476};
  $PMaterialStream1$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12 = (100.0) * ($PMaterialStream1$Pxliq$P$pDERNLSJac12$PdummyVarNLSJac12);
  TRACE_POP
}

/*
 equation index: 477
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p._3._$pDERNLSJac12._dummyVarNLSJac12 = 100.0 * Mixer1_xvapin_s_1SeedNLSJac12
 */
void Flowsheet_eqFunction_477(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,477};
  $PMaterialStream1$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12 = (100.0) * ($PMixer1_xvapin_s_1SeedNLSJac12);
  TRACE_POP
}

/*
 equation index: 478
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac12._dummyVarNLSJac12 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_3_1SeedNLSJac12 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_1SeedNLSJac12 - MaterialStream1.K_c[1] * MaterialStream1_x_pc_2_1SeedNLSJac12 else MaterialStream1_x_pc_2_1SeedNLSJac12
 */
void Flowsheet_eqFunction_478(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,478};
  modelica_boolean tmp102;
  modelica_boolean tmp103;
  modelica_boolean tmp104;
  modelica_real tmp105;
  tmp102 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp104 = (modelica_boolean)tmp102;
  if(tmp104)
  {
    tmp105 = $PMaterialStream1_x_pc_3_1SeedNLSJac12;
  }
  else
  {
    tmp103 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp105 = (tmp103?$PMaterialStream1_x_pc_3_1SeedNLSJac12 - ((data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */) * ($PMaterialStream1_x_pc_2_1SeedNLSJac12)):$PMaterialStream1_x_pc_2_1SeedNLSJac12);
  }
  $P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp105;
  TRACE_POP
}

/*
 equation index: 479
 type: SIMPLE_ASSIGN
 $res._2._$pDERNLSJac12._dummyVarNLSJac12 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_3_2SeedNLSJac12 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_2_1SeedNLSJac12 + DIVISION(MaterialStream1.x_pc[1,1] * Mixer1_xvapin_s_1SeedNLSJac12 * (-1.0 + MaterialStream1.K_c[1]), (1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[1])) ^ 2.0) else MaterialStream1_x_pc_2_2SeedNLSJac12
 */
void Flowsheet_eqFunction_479(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,479};
  modelica_boolean tmp106;
  modelica_boolean tmp107;
  modelica_real tmp108;
  modelica_boolean tmp109;
  modelica_real tmp110;
  modelica_boolean tmp111;
  modelica_real tmp112;
  tmp106 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp111 = (modelica_boolean)tmp106;
  if(tmp111)
  {
    tmp112 = $PMaterialStream1_x_pc_3_2SeedNLSJac12;
  }
  else
  {
    tmp107 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp109 = (modelica_boolean)tmp107;
    if(tmp109)
    {
      tmp108 = 1.0 + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (-1.0 + data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */);
      tmp110 = $PMaterialStream1_x_pc_2_1SeedNLSJac12 + DIVISION_SIM((data->localData[0]->realVars[80] /* MaterialStream1._x_pc[1,1] variable */) * (($PMixer1_xvapin_s_1SeedNLSJac12) * (-1.0 + data->localData[0]->realVars[47] /* MaterialStream1._K_c[1] variable */)),(tmp108 * tmp108),"(1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[1])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp110 = $PMaterialStream1_x_pc_2_2SeedNLSJac12;
    }
    tmp112 = tmp110;
  }
  $P$res$P2$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp112;
  TRACE_POP
}

/*
 equation index: 480
 type: SIMPLE_ASSIGN
 $res._3._$pDERNLSJac12._dummyVarNLSJac12 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1.F_p.3.$pDERNLSJac12.dummyVarNLSJac12 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_2SeedNLSJac12 - MaterialStream1.K_c[2] * MaterialStream1_x_pc_2_2SeedNLSJac12 else MaterialStream1.F_p.2.$pDERNLSJac12.dummyVarNLSJac12
 */
void Flowsheet_eqFunction_480(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,480};
  modelica_boolean tmp113;
  modelica_boolean tmp114;
  modelica_boolean tmp115;
  modelica_real tmp116;
  tmp113 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp115 = (modelica_boolean)tmp113;
  if(tmp115)
  {
    tmp116 = $PMaterialStream1$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12;
  }
  else
  {
    tmp114 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp116 = (tmp114?$PMaterialStream1_x_pc_3_2SeedNLSJac12 - ((data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */) * ($PMaterialStream1_x_pc_2_2SeedNLSJac12)):$PMaterialStream1$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12);
  }
  $P$res$P3$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp116;
  TRACE_POP
}

/*
 equation index: 481
 type: SIMPLE_ASSIGN
 $res._4._$pDERNLSJac12._dummyVarNLSJac12 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_2_1SeedNLSJac12 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_2_2SeedNLSJac12 + DIVISION(MaterialStream1.x_pc[1,2] * Mixer1_xvapin_s_1SeedNLSJac12 * (-1.0 + MaterialStream1.K_c[2]), (1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[2])) ^ 2.0) else MaterialStream1_x_pc_3_1SeedNLSJac12
 */
void Flowsheet_eqFunction_481(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,481};
  modelica_boolean tmp117;
  modelica_boolean tmp118;
  modelica_real tmp119;
  modelica_boolean tmp120;
  modelica_real tmp121;
  modelica_boolean tmp122;
  modelica_real tmp123;
  tmp117 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp122 = (modelica_boolean)tmp117;
  if(tmp122)
  {
    tmp123 = $PMaterialStream1_x_pc_2_1SeedNLSJac12;
  }
  else
  {
    tmp118 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp120 = (modelica_boolean)tmp118;
    if(tmp120)
    {
      tmp119 = 1.0 + (data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */) * (-1.0 + data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */);
      tmp121 = $PMaterialStream1_x_pc_2_2SeedNLSJac12 + DIVISION_SIM((data->localData[0]->realVars[81] /* MaterialStream1._x_pc[1,2] variable */) * (($PMixer1_xvapin_s_1SeedNLSJac12) * (-1.0 + data->localData[0]->realVars[48] /* MaterialStream1._K_c[2] variable */)),(tmp119 * tmp119),"(1.0 + Mixer1.xvapin_s[1] * (-1.0 + MaterialStream1.K_c[2])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp121 = $PMaterialStream1_x_pc_3_1SeedNLSJac12;
    }
    tmp123 = tmp121;
  }
  $P$res$P4$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp123;
  TRACE_POP
}

/*
 equation index: 482
 type: SIMPLE_ASSIGN
 $res._5._$pDERNLSJac12._dummyVarNLSJac12 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_2_2SeedNLSJac12 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_1SeedNLSJac12 + MaterialStream1_x_pc_3_2SeedNLSJac12 else MaterialStream1_x_pc_3_2SeedNLSJac12
 */
void Flowsheet_eqFunction_482(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,482};
  modelica_boolean tmp124;
  modelica_boolean tmp125;
  modelica_boolean tmp126;
  modelica_real tmp127;
  tmp124 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp126 = (modelica_boolean)tmp124;
  if(tmp126)
  {
    tmp127 = $PMaterialStream1_x_pc_2_2SeedNLSJac12;
  }
  else
  {
    tmp125 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp127 = (tmp125?$PMaterialStream1_x_pc_3_1SeedNLSJac12 + $PMaterialStream1_x_pc_3_2SeedNLSJac12:$PMaterialStream1_x_pc_3_2SeedNLSJac12);
  }
  $P$res$P5$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp127;
  TRACE_POP
}
int Flowsheet_functionJacNLSJac12_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac12;
  Flowsheet_eqFunction_475(data, threadData);

  Flowsheet_eqFunction_476(data, threadData);

  Flowsheet_eqFunction_477(data, threadData);

  Flowsheet_eqFunction_478(data, threadData);

  Flowsheet_eqFunction_479(data, threadData);

  Flowsheet_eqFunction_480(data, threadData);

  Flowsheet_eqFunction_481(data, threadData);

  Flowsheet_eqFunction_482(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 406
 type: SIMPLE_ASSIGN
 $res._1._$pDERLSJac11._dummyVarLSJac11 = (MaterialStream1.yg[1] - MaterialStream1.xg[1]) * MaterialStream1_FvapgSeedLSJac11
 */
void Flowsheet_eqFunction_406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,406};
  $P$res$P1$P$pDERLSJac11$PdummyVarLSJac11 = (data->simulationInfo->realParameter[440] - data->simulationInfo->realParameter[432]) * ($PMaterialStream1_FvapgSeedLSJac11);
  TRACE_POP
}
int Flowsheet_functionJacLSJac11_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac11;
  Flowsheet_eqFunction_406(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 300
 type: SIMPLE_ASSIGN
 $res._1._$pDERLSJac8._dummyVarLSJac8 = (MaterialStream2.xg[1] - MaterialStream2.yg[1]) * MaterialStream2_FliqgSeedLSJac8
 */
void Flowsheet_eqFunction_300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,300};
  $P$res$P1$P$pDERLSJac8$PdummyVarLSJac8 = (data->simulationInfo->realParameter[639] - data->simulationInfo->realParameter[647]) * ($PMaterialStream2_FliqgSeedLSJac8);
  TRACE_POP
}
int Flowsheet_functionJacLSJac8_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac8;
  Flowsheet_eqFunction_300(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 208
 type: SIMPLE_ASSIGN
 $res._1._$pDERLSJac5._dummyVarLSJac5 = (Mixer1.yg[1] - Mixer1.xg[1]) * Mixer1_FvapgSeedLSJac5
 */
void Flowsheet_eqFunction_208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,208};
  $P$res$P1$P$pDERLSJac5$PdummyVarLSJac5 = (data->simulationInfo->realParameter[1061] - data->simulationInfo->realParameter[1053]) * ($PMixer1_FvapgSeedLSJac5);
  TRACE_POP
}
int Flowsheet_functionJacLSJac5_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac5;
  Flowsheet_eqFunction_208(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 105
 type: SIMPLE_ASSIGN
 $res._1._$pDERLSJac2._dummyVarLSJac2 = (MaterialStream3.yg[1] - MaterialStream3.xg[1]) * MaterialStream3_FvapgSeedLSJac2
 */
void Flowsheet_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,105};
  $P$res$P1$P$pDERLSJac2$PdummyVarLSJac2 = (data->simulationInfo->realParameter[854] - data->simulationInfo->realParameter[846]) * ($PMaterialStream3_FvapgSeedLSJac2);
  TRACE_POP
}
int Flowsheet_functionJacLSJac2_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac2;
  Flowsheet_eqFunction_105(data, threadData);
  
  TRACE_POP
  return 0;
}
int Flowsheet_functionJacA_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Flowsheet_functionJacB_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Flowsheet_functionJacC_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Flowsheet_functionJacD_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}


