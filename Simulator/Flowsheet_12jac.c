/* Jacobians */
#include "Flowsheet_model.h"
#include "Flowsheet_12jac.h"

int Flowsheet_initialAnalyticJacobianNLSJac12(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac12;
  const int colPtrIndex[1+5] = {0,3,3,3,3,4};
  const int rowIndex[16] = {2,3,4,0,3,4,1,2,4,0,1,2,0,2,3,4};
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

int Flowsheet_initialAnalyticJacobianNLSJac11(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac11;
  const int colPtrIndex[1+5] = {0,3,3,3,3,4};
  const int rowIndex[16] = {0,1,4,1,3,4,2,3,4,0,1,2,0,1,2,4};
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

int Flowsheet_initialAnalyticJacobianNLSJac10(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac10;
  const int colPtrIndex[1+5] = {0,3,3,3,4,3};
  const int rowIndex[16] = {1,2,3,1,3,4,0,2,3,0,1,2,3,0,1,4};
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

int Flowsheet_initialAnalyticJacobianNLSJac9(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac9;
  const int colPtrIndex[1+5] = {0,3,4,3,3,3};
  const int rowIndex[16] = {0,3,4,0,1,3,4,2,3,4,1,2,4,0,1,3};
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
 equation index: 573
 type: SIMPLE_ASSIGN
 Heater1._xvapout._$pDERNLSJac12._dummyVarNLSJac12 = -MaterialStream2_xliqSeedNLSJac12
 */
void Flowsheet_eqFunction_573(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,573};
  $PHeater1$Pxvapout$P$pDERNLSJac12$PdummyVarNLSJac12 = (-$PMaterialStream2_xliqSeedNLSJac12);
  TRACE_POP
}

/*
 equation index: 574
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p._3._$pDERNLSJac12._dummyVarNLSJac12 = -100.0 * MaterialStream2_xliqSeedNLSJac12
 */
void Flowsheet_eqFunction_574(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,574};
  $PMaterialStream2$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12 = (-100.0) * ($PMaterialStream2_xliqSeedNLSJac12);
  TRACE_POP
}

/*
 equation index: 575
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p._2._$pDERNLSJac12._dummyVarNLSJac12 = 100.0 * MaterialStream2_xliqSeedNLSJac12
 */
void Flowsheet_eqFunction_575(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,575};
  $PMaterialStream2$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12 = (100.0) * ($PMaterialStream2_xliqSeedNLSJac12);
  TRACE_POP
}

/*
 equation index: 576
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac12._dummyVarNLSJac12 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2_x_pc_2_2SeedNLSJac12 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_1SeedNLSJac12 + MaterialStream2_x_pc_3_2SeedNLSJac12 else MaterialStream2_x_pc_3_2SeedNLSJac12
 */
void Flowsheet_eqFunction_576(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,576};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = $PMaterialStream2_x_pc_2_2SeedNLSJac12;
  }
  else
  {
    tmp1 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp3 = (tmp1?$PMaterialStream2_x_pc_3_1SeedNLSJac12 + $PMaterialStream2_x_pc_3_2SeedNLSJac12:$PMaterialStream2_x_pc_3_2SeedNLSJac12);
  }
  $P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp3;
  TRACE_POP
}

/*
 equation index: 577
 type: SIMPLE_ASSIGN
 $res._2._$pDERNLSJac12._dummyVarNLSJac12 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2_x_pc_3_1SeedNLSJac12 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_1SeedNLSJac12 - MaterialStream2.K_c[1] * MaterialStream2_x_pc_2_1SeedNLSJac12 else MaterialStream2_x_pc_2_1SeedNLSJac12
 */
void Flowsheet_eqFunction_577(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,577};
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  tmp4 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp7 = $PMaterialStream2_x_pc_3_1SeedNLSJac12;
  }
  else
  {
    tmp5 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp7 = (tmp5?$PMaterialStream2_x_pc_3_1SeedNLSJac12 - ((data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */) * ($PMaterialStream2_x_pc_2_1SeedNLSJac12)):$PMaterialStream2_x_pc_2_1SeedNLSJac12);
  }
  $P$res$P2$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp7;
  TRACE_POP
}

/*
 equation index: 578
 type: SIMPLE_ASSIGN
 $res._3._$pDERNLSJac12._dummyVarNLSJac12 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2_x_pc_2_1SeedNLSJac12 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_2_2SeedNLSJac12 + DIVISION(MaterialStream2.x_pc[1,2] * Heater1.xvapout.$pDERNLSJac12.dummyVarNLSJac12 * (-1.0 + MaterialStream2.K_c[2]), (1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[2])) ^ 2.0) else MaterialStream2_x_pc_3_1SeedNLSJac12
 */
void Flowsheet_eqFunction_578(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,578};
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_boolean tmp11;
  modelica_real tmp12;
  modelica_boolean tmp13;
  modelica_real tmp14;
  tmp8 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp13 = (modelica_boolean)tmp8;
  if(tmp13)
  {
    tmp14 = $PMaterialStream2_x_pc_2_1SeedNLSJac12;
  }
  else
  {
    tmp9 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp11 = (modelica_boolean)tmp9;
    if(tmp11)
    {
      tmp10 = 1.0 + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (-1.0 + data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */);
      tmp12 = $PMaterialStream2_x_pc_2_2SeedNLSJac12 + DIVISION_SIM((data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (($PHeater1$Pxvapout$P$pDERNLSJac12$PdummyVarNLSJac12) * (-1.0 + data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */)),(tmp10 * tmp10),"(1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[2])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp12 = $PMaterialStream2_x_pc_3_1SeedNLSJac12;
    }
    tmp14 = tmp12;
  }
  $P$res$P3$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp14;
  TRACE_POP
}

/*
 equation index: 579
 type: SIMPLE_ASSIGN
 $res._4._$pDERNLSJac12._dummyVarNLSJac12 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2.F_p.3.$pDERNLSJac12.dummyVarNLSJac12 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_2SeedNLSJac12 - MaterialStream2.K_c[2] * MaterialStream2_x_pc_2_2SeedNLSJac12 else MaterialStream2.F_p.2.$pDERNLSJac12.dummyVarNLSJac12
 */
void Flowsheet_eqFunction_579(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,579};
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_real tmp18;
  tmp15 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp17 = (modelica_boolean)tmp15;
  if(tmp17)
  {
    tmp18 = $PMaterialStream2$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12;
  }
  else
  {
    tmp16 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp18 = (tmp16?$PMaterialStream2_x_pc_3_2SeedNLSJac12 - ((data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */) * ($PMaterialStream2_x_pc_2_2SeedNLSJac12)):$PMaterialStream2$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12);
  }
  $P$res$P4$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp18;
  TRACE_POP
}

/*
 equation index: 580
 type: SIMPLE_ASSIGN
 $res._5._$pDERNLSJac12._dummyVarNLSJac12 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2_x_pc_3_2SeedNLSJac12 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_2_1SeedNLSJac12 + DIVISION(MaterialStream2.x_pc[1,1] * Heater1.xvapout.$pDERNLSJac12.dummyVarNLSJac12 * (-1.0 + MaterialStream2.K_c[1]), (1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[1])) ^ 2.0) else MaterialStream2_x_pc_2_2SeedNLSJac12
 */
void Flowsheet_eqFunction_580(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,580};
  modelica_boolean tmp19;
  modelica_boolean tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp19 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp24 = (modelica_boolean)tmp19;
  if(tmp24)
  {
    tmp25 = $PMaterialStream2_x_pc_3_2SeedNLSJac12;
  }
  else
  {
    tmp20 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp22 = (modelica_boolean)tmp20;
    if(tmp22)
    {
      tmp21 = 1.0 + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (-1.0 + data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */);
      tmp23 = $PMaterialStream2_x_pc_2_1SeedNLSJac12 + DIVISION_SIM((data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (($PHeater1$Pxvapout$P$pDERNLSJac12$PdummyVarNLSJac12) * (-1.0 + data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */)),(tmp21 * tmp21),"(1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[1])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp23 = $PMaterialStream2_x_pc_2_2SeedNLSJac12;
    }
    tmp25 = tmp23;
  }
  $P$res$P5$P$pDERNLSJac12$PdummyVarNLSJac12 = tmp25;
  TRACE_POP
}
int Flowsheet_functionJacNLSJac12_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac12;
  Flowsheet_eqFunction_573(data, threadData);

  Flowsheet_eqFunction_574(data, threadData);

  Flowsheet_eqFunction_575(data, threadData);

  Flowsheet_eqFunction_576(data, threadData);

  Flowsheet_eqFunction_577(data, threadData);

  Flowsheet_eqFunction_578(data, threadData);

  Flowsheet_eqFunction_579(data, threadData);

  Flowsheet_eqFunction_580(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 515
 type: SIMPLE_ASSIGN
 Heater1._xvapin._$pDERNLSJac11._dummyVarNLSJac11 = -MaterialStream1_xliqSeedNLSJac11
 */
void Flowsheet_eqFunction_515(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,515};
  $PHeater1$Pxvapin$P$pDERNLSJac11$PdummyVarNLSJac11 = (-$PMaterialStream1_xliqSeedNLSJac11);
  TRACE_POP
}

/*
 equation index: 516
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p._3._$pDERNLSJac11._dummyVarNLSJac11 = -100.0 * MaterialStream1_xliqSeedNLSJac11
 */
void Flowsheet_eqFunction_516(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,516};
  $PMaterialStream1$PF_p$P3$P$pDERNLSJac11$PdummyVarNLSJac11 = (-100.0) * ($PMaterialStream1_xliqSeedNLSJac11);
  TRACE_POP
}

/*
 equation index: 517
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p._2._$pDERNLSJac11._dummyVarNLSJac11 = 100.0 * MaterialStream1_xliqSeedNLSJac11
 */
void Flowsheet_eqFunction_517(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,517};
  $PMaterialStream1$PF_p$P2$P$pDERNLSJac11$PdummyVarNLSJac11 = (100.0) * ($PMaterialStream1_xliqSeedNLSJac11);
  TRACE_POP
}

/*
 equation index: 518
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac11._dummyVarNLSJac11 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1.F_p.3.$pDERNLSJac11.dummyVarNLSJac11 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_2SeedNLSJac11 - MaterialStream1.K_c[2] * MaterialStream1_x_pc_2_2SeedNLSJac11 else MaterialStream1.F_p.2.$pDERNLSJac11.dummyVarNLSJac11
 */
void Flowsheet_eqFunction_518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,518};
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  modelica_real tmp29;
  tmp26 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp28 = (modelica_boolean)tmp26;
  if(tmp28)
  {
    tmp29 = $PMaterialStream1$PF_p$P3$P$pDERNLSJac11$PdummyVarNLSJac11;
  }
  else
  {
    tmp27 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp29 = (tmp27?$PMaterialStream1_x_pc_3_2SeedNLSJac11 - ((data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */) * ($PMaterialStream1_x_pc_2_2SeedNLSJac11)):$PMaterialStream1$PF_p$P2$P$pDERNLSJac11$PdummyVarNLSJac11);
  }
  $P$res$P1$P$pDERNLSJac11$PdummyVarNLSJac11 = tmp29;
  TRACE_POP
}

/*
 equation index: 519
 type: SIMPLE_ASSIGN
 $res._2._$pDERNLSJac11._dummyVarNLSJac11 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_3_2SeedNLSJac11 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_2_1SeedNLSJac11 + DIVISION(MaterialStream1.x_pc[1,1] * Heater1.xvapin.$pDERNLSJac11.dummyVarNLSJac11 * (-1.0 + MaterialStream1.K_c[1]), (1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[1])) ^ 2.0) else MaterialStream1_x_pc_2_2SeedNLSJac11
 */
void Flowsheet_eqFunction_519(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,519};
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  modelica_real tmp32;
  modelica_boolean tmp33;
  modelica_real tmp34;
  modelica_boolean tmp35;
  modelica_real tmp36;
  tmp30 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp35 = (modelica_boolean)tmp30;
  if(tmp35)
  {
    tmp36 = $PMaterialStream1_x_pc_3_2SeedNLSJac11;
  }
  else
  {
    tmp31 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp33 = (modelica_boolean)tmp31;
    if(tmp33)
    {
      tmp32 = 1.0 + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (-1.0 + data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */);
      tmp34 = $PMaterialStream1_x_pc_2_1SeedNLSJac11 + DIVISION_SIM((data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (($PHeater1$Pxvapin$P$pDERNLSJac11$PdummyVarNLSJac11) * (-1.0 + data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */)),(tmp32 * tmp32),"(1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[1])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp34 = $PMaterialStream1_x_pc_2_2SeedNLSJac11;
    }
    tmp36 = tmp34;
  }
  $P$res$P2$P$pDERNLSJac11$PdummyVarNLSJac11 = tmp36;
  TRACE_POP
}

/*
 equation index: 520
 type: SIMPLE_ASSIGN
 $res._3._$pDERNLSJac11._dummyVarNLSJac11 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_2_2SeedNLSJac11 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_1SeedNLSJac11 + MaterialStream1_x_pc_3_2SeedNLSJac11 else MaterialStream1_x_pc_3_2SeedNLSJac11
 */
void Flowsheet_eqFunction_520(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,520};
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  modelica_boolean tmp39;
  modelica_real tmp40;
  tmp37 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp39 = (modelica_boolean)tmp37;
  if(tmp39)
  {
    tmp40 = $PMaterialStream1_x_pc_2_2SeedNLSJac11;
  }
  else
  {
    tmp38 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp40 = (tmp38?$PMaterialStream1_x_pc_3_1SeedNLSJac11 + $PMaterialStream1_x_pc_3_2SeedNLSJac11:$PMaterialStream1_x_pc_3_2SeedNLSJac11);
  }
  $P$res$P3$P$pDERNLSJac11$PdummyVarNLSJac11 = tmp40;
  TRACE_POP
}

/*
 equation index: 521
 type: SIMPLE_ASSIGN
 $res._4._$pDERNLSJac11._dummyVarNLSJac11 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_3_1SeedNLSJac11 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_1SeedNLSJac11 - MaterialStream1.K_c[1] * MaterialStream1_x_pc_2_1SeedNLSJac11 else MaterialStream1_x_pc_2_1SeedNLSJac11
 */
void Flowsheet_eqFunction_521(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,521};
  modelica_boolean tmp41;
  modelica_boolean tmp42;
  modelica_boolean tmp43;
  modelica_real tmp44;
  tmp41 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp43 = (modelica_boolean)tmp41;
  if(tmp43)
  {
    tmp44 = $PMaterialStream1_x_pc_3_1SeedNLSJac11;
  }
  else
  {
    tmp42 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp44 = (tmp42?$PMaterialStream1_x_pc_3_1SeedNLSJac11 - ((data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */) * ($PMaterialStream1_x_pc_2_1SeedNLSJac11)):$PMaterialStream1_x_pc_2_1SeedNLSJac11);
  }
  $P$res$P4$P$pDERNLSJac11$PdummyVarNLSJac11 = tmp44;
  TRACE_POP
}

/*
 equation index: 522
 type: SIMPLE_ASSIGN
 $res._5._$pDERNLSJac11._dummyVarNLSJac11 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_2_1SeedNLSJac11 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_2_2SeedNLSJac11 + DIVISION(MaterialStream1.x_pc[1,2] * Heater1.xvapin.$pDERNLSJac11.dummyVarNLSJac11 * (-1.0 + MaterialStream1.K_c[2]), (1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[2])) ^ 2.0) else MaterialStream1_x_pc_3_1SeedNLSJac11
 */
void Flowsheet_eqFunction_522(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,522};
  modelica_boolean tmp45;
  modelica_boolean tmp46;
  modelica_real tmp47;
  modelica_boolean tmp48;
  modelica_real tmp49;
  modelica_boolean tmp50;
  modelica_real tmp51;
  tmp45 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp50 = (modelica_boolean)tmp45;
  if(tmp50)
  {
    tmp51 = $PMaterialStream1_x_pc_2_1SeedNLSJac11;
  }
  else
  {
    tmp46 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp48 = (modelica_boolean)tmp46;
    if(tmp48)
    {
      tmp47 = 1.0 + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (-1.0 + data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */);
      tmp49 = $PMaterialStream1_x_pc_2_2SeedNLSJac11 + DIVISION_SIM((data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (($PHeater1$Pxvapin$P$pDERNLSJac11$PdummyVarNLSJac11) * (-1.0 + data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */)),(tmp47 * tmp47),"(1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[2])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp49 = $PMaterialStream1_x_pc_3_1SeedNLSJac11;
    }
    tmp51 = tmp49;
  }
  $P$res$P5$P$pDERNLSJac11$PdummyVarNLSJac11 = tmp51;
  TRACE_POP
}
int Flowsheet_functionJacNLSJac11_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac11;
  Flowsheet_eqFunction_515(data, threadData);

  Flowsheet_eqFunction_516(data, threadData);

  Flowsheet_eqFunction_517(data, threadData);

  Flowsheet_eqFunction_518(data, threadData);

  Flowsheet_eqFunction_519(data, threadData);

  Flowsheet_eqFunction_520(data, threadData);

  Flowsheet_eqFunction_521(data, threadData);

  Flowsheet_eqFunction_522(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 422
 type: SIMPLE_ASSIGN
 Heater1._xvapin._$pDERNLSJac10._dummyVarNLSJac10 = -MaterialStream1_xliqSeedNLSJac10
 */
void Flowsheet_eqFunction_422(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,422};
  $PHeater1$Pxvapin$P$pDERNLSJac10$PdummyVarNLSJac10 = (-$PMaterialStream1_xliqSeedNLSJac10);
  TRACE_POP
}

/*
 equation index: 423
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p._3._$pDERNLSJac10._dummyVarNLSJac10 = -100.0 * MaterialStream1_xliqSeedNLSJac10
 */
void Flowsheet_eqFunction_423(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,423};
  $PMaterialStream1$PF_p$P3$P$pDERNLSJac10$PdummyVarNLSJac10 = (-100.0) * ($PMaterialStream1_xliqSeedNLSJac10);
  TRACE_POP
}

/*
 equation index: 424
 type: SIMPLE_ASSIGN
 MaterialStream1._F_p._2._$pDERNLSJac10._dummyVarNLSJac10 = 100.0 * MaterialStream1_xliqSeedNLSJac10
 */
void Flowsheet_eqFunction_424(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,424};
  $PMaterialStream1$PF_p$P2$P$pDERNLSJac10$PdummyVarNLSJac10 = (100.0) * ($PMaterialStream1_xliqSeedNLSJac10);
  TRACE_POP
}

/*
 equation index: 425
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac10._dummyVarNLSJac10 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_2_2SeedNLSJac10 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_1SeedNLSJac10 + MaterialStream1_x_pc_3_2SeedNLSJac10 else MaterialStream1_x_pc_3_2SeedNLSJac10
 */
void Flowsheet_eqFunction_425(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,425};
  modelica_boolean tmp52;
  modelica_boolean tmp53;
  modelica_boolean tmp54;
  modelica_real tmp55;
  tmp52 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp54 = (modelica_boolean)tmp52;
  if(tmp54)
  {
    tmp55 = $PMaterialStream1_x_pc_2_2SeedNLSJac10;
  }
  else
  {
    tmp53 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp55 = (tmp53?$PMaterialStream1_x_pc_3_1SeedNLSJac10 + $PMaterialStream1_x_pc_3_2SeedNLSJac10:$PMaterialStream1_x_pc_3_2SeedNLSJac10);
  }
  $P$res$P1$P$pDERNLSJac10$PdummyVarNLSJac10 = tmp55;
  TRACE_POP
}

/*
 equation index: 426
 type: SIMPLE_ASSIGN
 $res._2._$pDERNLSJac10._dummyVarNLSJac10 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_2_1SeedNLSJac10 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_2_2SeedNLSJac10 + DIVISION(MaterialStream1.x_pc[1,2] * Heater1.xvapin.$pDERNLSJac10.dummyVarNLSJac10 * (-1.0 + MaterialStream1.K_c[2]), (1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[2])) ^ 2.0) else MaterialStream1_x_pc_3_1SeedNLSJac10
 */
void Flowsheet_eqFunction_426(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,426};
  modelica_boolean tmp56;
  modelica_boolean tmp57;
  modelica_real tmp58;
  modelica_boolean tmp59;
  modelica_real tmp60;
  modelica_boolean tmp61;
  modelica_real tmp62;
  tmp56 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp61 = (modelica_boolean)tmp56;
  if(tmp61)
  {
    tmp62 = $PMaterialStream1_x_pc_2_1SeedNLSJac10;
  }
  else
  {
    tmp57 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp59 = (modelica_boolean)tmp57;
    if(tmp59)
    {
      tmp58 = 1.0 + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (-1.0 + data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */);
      tmp60 = $PMaterialStream1_x_pc_2_2SeedNLSJac10 + DIVISION_SIM((data->localData[0]->realVars[86] /* MaterialStream1._x_pc[1,2] variable */) * (($PHeater1$Pxvapin$P$pDERNLSJac10$PdummyVarNLSJac10) * (-1.0 + data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */)),(tmp58 * tmp58),"(1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[2])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp60 = $PMaterialStream1_x_pc_3_1SeedNLSJac10;
    }
    tmp62 = tmp60;
  }
  $P$res$P2$P$pDERNLSJac10$PdummyVarNLSJac10 = tmp62;
  TRACE_POP
}

/*
 equation index: 427
 type: SIMPLE_ASSIGN
 $res._3._$pDERNLSJac10._dummyVarNLSJac10 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1.F_p.3.$pDERNLSJac10.dummyVarNLSJac10 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_2SeedNLSJac10 - MaterialStream1.K_c[2] * MaterialStream1_x_pc_2_2SeedNLSJac10 else MaterialStream1.F_p.2.$pDERNLSJac10.dummyVarNLSJac10
 */
void Flowsheet_eqFunction_427(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,427};
  modelica_boolean tmp63;
  modelica_boolean tmp64;
  modelica_boolean tmp65;
  modelica_real tmp66;
  tmp63 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp65 = (modelica_boolean)tmp63;
  if(tmp65)
  {
    tmp66 = $PMaterialStream1$PF_p$P3$P$pDERNLSJac10$PdummyVarNLSJac10;
  }
  else
  {
    tmp64 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp66 = (tmp64?$PMaterialStream1_x_pc_3_2SeedNLSJac10 - ((data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */) * ($PMaterialStream1_x_pc_2_2SeedNLSJac10)):$PMaterialStream1$PF_p$P2$P$pDERNLSJac10$PdummyVarNLSJac10);
  }
  $P$res$P3$P$pDERNLSJac10$PdummyVarNLSJac10 = tmp66;
  TRACE_POP
}

/*
 equation index: 428
 type: SIMPLE_ASSIGN
 $res._4._$pDERNLSJac10._dummyVarNLSJac10 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_3_2SeedNLSJac10 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_2_1SeedNLSJac10 + DIVISION(MaterialStream1.x_pc[1,1] * Heater1.xvapin.$pDERNLSJac10.dummyVarNLSJac10 * (-1.0 + MaterialStream1.K_c[1]), (1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[1])) ^ 2.0) else MaterialStream1_x_pc_2_2SeedNLSJac10
 */
void Flowsheet_eqFunction_428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,428};
  modelica_boolean tmp67;
  modelica_boolean tmp68;
  modelica_real tmp69;
  modelica_boolean tmp70;
  modelica_real tmp71;
  modelica_boolean tmp72;
  modelica_real tmp73;
  tmp67 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp72 = (modelica_boolean)tmp67;
  if(tmp72)
  {
    tmp73 = $PMaterialStream1_x_pc_3_2SeedNLSJac10;
  }
  else
  {
    tmp68 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp70 = (modelica_boolean)tmp68;
    if(tmp70)
    {
      tmp69 = 1.0 + (data->localData[0]->realVars[8] /* Heater1._xvapin variable */) * (-1.0 + data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */);
      tmp71 = $PMaterialStream1_x_pc_2_1SeedNLSJac10 + DIVISION_SIM((data->localData[0]->realVars[85] /* MaterialStream1._x_pc[1,1] variable */) * (($PHeater1$Pxvapin$P$pDERNLSJac10$PdummyVarNLSJac10) * (-1.0 + data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */)),(tmp69 * tmp69),"(1.0 + Heater1.xvapin * (-1.0 + MaterialStream1.K_c[1])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp71 = $PMaterialStream1_x_pc_2_2SeedNLSJac10;
    }
    tmp73 = tmp71;
  }
  $P$res$P4$P$pDERNLSJac10$PdummyVarNLSJac10 = tmp73;
  TRACE_POP
}

/*
 equation index: 429
 type: SIMPLE_ASSIGN
 $res._5._$pDERNLSJac10._dummyVarNLSJac10 = if 101325.0 >= MaterialStream1.Pbubl then MaterialStream1_x_pc_3_1SeedNLSJac10 else if 101325.0 >= MaterialStream1.Pdew then MaterialStream1_x_pc_3_1SeedNLSJac10 - MaterialStream1.K_c[1] * MaterialStream1_x_pc_2_1SeedNLSJac10 else MaterialStream1_x_pc_2_1SeedNLSJac10
 */
void Flowsheet_eqFunction_429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,429};
  modelica_boolean tmp74;
  modelica_boolean tmp75;
  modelica_boolean tmp76;
  modelica_real tmp77;
  tmp74 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp76 = (modelica_boolean)tmp74;
  if(tmp76)
  {
    tmp77 = $PMaterialStream1_x_pc_3_1SeedNLSJac10;
  }
  else
  {
    tmp75 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp77 = (tmp75?$PMaterialStream1_x_pc_3_1SeedNLSJac10 - ((data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */) * ($PMaterialStream1_x_pc_2_1SeedNLSJac10)):$PMaterialStream1_x_pc_2_1SeedNLSJac10);
  }
  $P$res$P5$P$pDERNLSJac10$PdummyVarNLSJac10 = tmp77;
  TRACE_POP
}
int Flowsheet_functionJacNLSJac10_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac10;
  Flowsheet_eqFunction_422(data, threadData);

  Flowsheet_eqFunction_423(data, threadData);

  Flowsheet_eqFunction_424(data, threadData);

  Flowsheet_eqFunction_425(data, threadData);

  Flowsheet_eqFunction_426(data, threadData);

  Flowsheet_eqFunction_427(data, threadData);

  Flowsheet_eqFunction_428(data, threadData);

  Flowsheet_eqFunction_429(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 368
 type: SIMPLE_ASSIGN
 Heater1._xvapout._$pDERNLSJac9._dummyVarNLSJac9 = -MaterialStream2_xliqSeedNLSJac9
 */
void Flowsheet_eqFunction_368(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,368};
  $PHeater1$Pxvapout$P$pDERNLSJac9$PdummyVarNLSJac9 = (-$PMaterialStream2_xliqSeedNLSJac9);
  TRACE_POP
}

/*
 equation index: 369
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p._3._$pDERNLSJac9._dummyVarNLSJac9 = -100.0 * MaterialStream2_xliqSeedNLSJac9
 */
void Flowsheet_eqFunction_369(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,369};
  $PMaterialStream2$PF_p$P3$P$pDERNLSJac9$PdummyVarNLSJac9 = (-100.0) * ($PMaterialStream2_xliqSeedNLSJac9);
  TRACE_POP
}

/*
 equation index: 370
 type: SIMPLE_ASSIGN
 MaterialStream2._F_p._2._$pDERNLSJac9._dummyVarNLSJac9 = 100.0 * MaterialStream2_xliqSeedNLSJac9
 */
void Flowsheet_eqFunction_370(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,370};
  $PMaterialStream2$PF_p$P2$P$pDERNLSJac9$PdummyVarNLSJac9 = (100.0) * ($PMaterialStream2_xliqSeedNLSJac9);
  TRACE_POP
}

/*
 equation index: 371
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac9._dummyVarNLSJac9 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2.F_p.3.$pDERNLSJac9.dummyVarNLSJac9 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_2SeedNLSJac9 - MaterialStream2.K_c[2] * MaterialStream2_x_pc_2_2SeedNLSJac9 else MaterialStream2.F_p.2.$pDERNLSJac9.dummyVarNLSJac9
 */
void Flowsheet_eqFunction_371(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,371};
  modelica_boolean tmp78;
  modelica_boolean tmp79;
  modelica_boolean tmp80;
  modelica_real tmp81;
  tmp78 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp80 = (modelica_boolean)tmp78;
  if(tmp80)
  {
    tmp81 = $PMaterialStream2$PF_p$P3$P$pDERNLSJac9$PdummyVarNLSJac9;
  }
  else
  {
    tmp79 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp81 = (tmp79?$PMaterialStream2_x_pc_3_2SeedNLSJac9 - ((data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */) * ($PMaterialStream2_x_pc_2_2SeedNLSJac9)):$PMaterialStream2$PF_p$P2$P$pDERNLSJac9$PdummyVarNLSJac9);
  }
  $P$res$P1$P$pDERNLSJac9$PdummyVarNLSJac9 = tmp81;
  TRACE_POP
}

/*
 equation index: 372
 type: SIMPLE_ASSIGN
 $res._2._$pDERNLSJac9._dummyVarNLSJac9 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2_x_pc_2_2SeedNLSJac9 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_1SeedNLSJac9 + MaterialStream2_x_pc_3_2SeedNLSJac9 else MaterialStream2_x_pc_3_2SeedNLSJac9
 */
void Flowsheet_eqFunction_372(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,372};
  modelica_boolean tmp82;
  modelica_boolean tmp83;
  modelica_boolean tmp84;
  modelica_real tmp85;
  tmp82 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp84 = (modelica_boolean)tmp82;
  if(tmp84)
  {
    tmp85 = $PMaterialStream2_x_pc_2_2SeedNLSJac9;
  }
  else
  {
    tmp83 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp85 = (tmp83?$PMaterialStream2_x_pc_3_1SeedNLSJac9 + $PMaterialStream2_x_pc_3_2SeedNLSJac9:$PMaterialStream2_x_pc_3_2SeedNLSJac9);
  }
  $P$res$P2$P$pDERNLSJac9$PdummyVarNLSJac9 = tmp85;
  TRACE_POP
}

/*
 equation index: 373
 type: SIMPLE_ASSIGN
 $res._3._$pDERNLSJac9._dummyVarNLSJac9 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2_x_pc_3_1SeedNLSJac9 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_3_1SeedNLSJac9 - MaterialStream2.K_c[1] * MaterialStream2_x_pc_2_1SeedNLSJac9 else MaterialStream2_x_pc_2_1SeedNLSJac9
 */
void Flowsheet_eqFunction_373(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,373};
  modelica_boolean tmp86;
  modelica_boolean tmp87;
  modelica_boolean tmp88;
  modelica_real tmp89;
  tmp86 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp88 = (modelica_boolean)tmp86;
  if(tmp88)
  {
    tmp89 = $PMaterialStream2_x_pc_3_1SeedNLSJac9;
  }
  else
  {
    tmp87 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp89 = (tmp87?$PMaterialStream2_x_pc_3_1SeedNLSJac9 - ((data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */) * ($PMaterialStream2_x_pc_2_1SeedNLSJac9)):$PMaterialStream2_x_pc_2_1SeedNLSJac9);
  }
  $P$res$P3$P$pDERNLSJac9$PdummyVarNLSJac9 = tmp89;
  TRACE_POP
}

/*
 equation index: 374
 type: SIMPLE_ASSIGN
 $res._4._$pDERNLSJac9._dummyVarNLSJac9 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2_x_pc_3_2SeedNLSJac9 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_2_1SeedNLSJac9 + DIVISION(MaterialStream2.x_pc[1,1] * Heater1.xvapout.$pDERNLSJac9.dummyVarNLSJac9 * (-1.0 + MaterialStream2.K_c[1]), (1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[1])) ^ 2.0) else MaterialStream2_x_pc_2_2SeedNLSJac9
 */
void Flowsheet_eqFunction_374(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,374};
  modelica_boolean tmp90;
  modelica_boolean tmp91;
  modelica_real tmp92;
  modelica_boolean tmp93;
  modelica_real tmp94;
  modelica_boolean tmp95;
  modelica_real tmp96;
  tmp90 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp95 = (modelica_boolean)tmp90;
  if(tmp95)
  {
    tmp96 = $PMaterialStream2_x_pc_3_2SeedNLSJac9;
  }
  else
  {
    tmp91 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp93 = (modelica_boolean)tmp91;
    if(tmp93)
    {
      tmp92 = 1.0 + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (-1.0 + data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */);
      tmp94 = $PMaterialStream2_x_pc_2_1SeedNLSJac9 + DIVISION_SIM((data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */) * (($PHeater1$Pxvapout$P$pDERNLSJac9$PdummyVarNLSJac9) * (-1.0 + data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */)),(tmp92 * tmp92),"(1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[1])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp94 = $PMaterialStream2_x_pc_2_2SeedNLSJac9;
    }
    tmp96 = tmp94;
  }
  $P$res$P4$P$pDERNLSJac9$PdummyVarNLSJac9 = tmp96;
  TRACE_POP
}

/*
 equation index: 375
 type: SIMPLE_ASSIGN
 $res._5._$pDERNLSJac9._dummyVarNLSJac9 = if Heater1.Pout >= MaterialStream2.Pbubl then MaterialStream2_x_pc_2_1SeedNLSJac9 else if Heater1.Pout >= MaterialStream2.Pdew then MaterialStream2_x_pc_2_2SeedNLSJac9 + DIVISION(MaterialStream2.x_pc[1,2] * Heater1.xvapout.$pDERNLSJac9.dummyVarNLSJac9 * (-1.0 + MaterialStream2.K_c[2]), (1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[2])) ^ 2.0) else MaterialStream2_x_pc_3_1SeedNLSJac9
 */
void Flowsheet_eqFunction_375(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,375};
  modelica_boolean tmp97;
  modelica_boolean tmp98;
  modelica_real tmp99;
  modelica_boolean tmp100;
  modelica_real tmp101;
  modelica_boolean tmp102;
  modelica_real tmp103;
  tmp97 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp102 = (modelica_boolean)tmp97;
  if(tmp102)
  {
    tmp103 = $PMaterialStream2_x_pc_2_1SeedNLSJac9;
  }
  else
  {
    tmp98 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp100 = (modelica_boolean)tmp98;
    if(tmp100)
    {
      tmp99 = 1.0 + (data->localData[0]->realVars[9] /* Heater1._xvapout variable */) * (-1.0 + data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */);
      tmp101 = $PMaterialStream2_x_pc_2_2SeedNLSJac9 + DIVISION_SIM((data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */) * (($PHeater1$Pxvapout$P$pDERNLSJac9$PdummyVarNLSJac9) * (-1.0 + data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */)),(tmp99 * tmp99),"(1.0 + Heater1.xvapout * (-1.0 + MaterialStream2.K_c[2])) ^ 2.0",equationIndexes);
    }
    else
    {
      tmp101 = $PMaterialStream2_x_pc_3_1SeedNLSJac9;
    }
    tmp103 = tmp101;
  }
  $P$res$P5$P$pDERNLSJac9$PdummyVarNLSJac9 = tmp103;
  TRACE_POP
}
int Flowsheet_functionJacNLSJac9_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_NLSJac9;
  Flowsheet_eqFunction_368(data, threadData);

  Flowsheet_eqFunction_369(data, threadData);

  Flowsheet_eqFunction_370(data, threadData);

  Flowsheet_eqFunction_371(data, threadData);

  Flowsheet_eqFunction_372(data, threadData);

  Flowsheet_eqFunction_373(data, threadData);

  Flowsheet_eqFunction_374(data, threadData);

  Flowsheet_eqFunction_375(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 297
 type: SIMPLE_ASSIGN
 $res._1._$pDERLSJac8._dummyVarLSJac8 = (MaterialStream1.yg[1] - MaterialStream1.xg[1]) * MaterialStream1_FvapgSeedLSJac8
 */
void Flowsheet_eqFunction_297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,297};
  $P$res$P1$P$pDERLSJac8$PdummyVarLSJac8 = (data->simulationInfo->realParameter[649] - data->simulationInfo->realParameter[641]) * ($PMaterialStream1_FvapgSeedLSJac8);
  TRACE_POP
}
int Flowsheet_functionJacLSJac8_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac8;
  Flowsheet_eqFunction_297(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 189
 type: SIMPLE_ASSIGN
 $res._1._$pDERLSJac5._dummyVarLSJac5 = (MaterialStream2.yg[1] - MaterialStream2.xg[1]) * MaterialStream2_FvapgSeedLSJac5
 */
void Flowsheet_eqFunction_189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,189};
  $P$res$P1$P$pDERLSJac5$PdummyVarLSJac5 = (data->simulationInfo->realParameter[856] - data->simulationInfo->realParameter[848]) * ($PMaterialStream2_FvapgSeedLSJac5);
  TRACE_POP
}
int Flowsheet_functionJacLSJac5_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac5;
  Flowsheet_eqFunction_189(data, threadData);
  
  TRACE_POP
  return 0;
}

/*
 equation index: 95
 type: SIMPLE_ASSIGN
 $res._1._$pDERLSJac2._dummyVarLSJac2 = (Heater1.yg[1] - Heater1.xg[1]) * Heater1_FvapgSeedLSJac2
 */
void Flowsheet_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,95};
  $P$res$P1$P$pDERLSJac2$PdummyVarLSJac2 = (data->simulationInfo->realParameter[442] - data->simulationInfo->realParameter[434]) * ($PHeater1_FvapgSeedLSJac2);
  TRACE_POP
}
int Flowsheet_functionJacLSJac2_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Flowsheet_INDEX_JAC_LSJac2;
  Flowsheet_eqFunction_95(data, threadData);
  
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


