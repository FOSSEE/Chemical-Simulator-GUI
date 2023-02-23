/* Linear Systems */
#include "Flowsheet_model.h"
#include "Flowsheet_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* initial linear systems */

/*
 equation index: 103
 type: SIMPLE_ASSIGN
 MaterialStream3._Fliqg = MaterialStream3.Fg - MaterialStream3.Fvapg
 */
void Flowsheet_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
  data->simulationInfo->realParameter[812] = data->simulationInfo->realParameter[811] - data->simulationInfo->realParameter[813];
  TRACE_POP
}

void residualFunc106(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,106};
  data->simulationInfo->realParameter[813] = xloc[0];
  /* local constraints */
  Flowsheet_eqFunction_103(data, threadData);
  res[0] = (data->simulationInfo->realParameter[854]) * (data->simulationInfo->realParameter[813]) + (data->simulationInfo->realParameter[846]) * (data->simulationInfo->realParameter[812]) - ((data->simulationInfo->realParameter[848]) * (data->simulationInfo->realParameter[811]));
  TRACE_POP
}
void initializeStaticLSData106(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream3.Fvapg */
  linearSystemData->nominal[i] = data->modelData->realParameterData[813].attribute /* MaterialStream3._Fvapg */.nominal;
  linearSystemData->min[i]     = data->modelData->realParameterData[813].attribute /* MaterialStream3._Fvapg */.min;
  linearSystemData->max[i++]   = data->modelData->realParameterData[813].attribute /* MaterialStream3._Fvapg */.max;
}


/*
 equation index: 206
 type: SIMPLE_ASSIGN
 Mixer1._Fliqg = Mixer1.Fg - Mixer1.Fvapg
 */
void Flowsheet_eqFunction_206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,206};
  data->simulationInfo->realParameter[1019] = data->simulationInfo->realParameter[1018] - data->simulationInfo->realParameter[1020];
  TRACE_POP
}

void residualFunc209(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,209};
  data->simulationInfo->realParameter[1020] = xloc[0];
  /* local constraints */
  Flowsheet_eqFunction_206(data, threadData);
  res[0] = (data->simulationInfo->realParameter[1061]) * (data->simulationInfo->realParameter[1020]) + (data->simulationInfo->realParameter[1053]) * (data->simulationInfo->realParameter[1019]) - ((data->simulationInfo->realParameter[1055]) * (data->simulationInfo->realParameter[1018]));
  TRACE_POP
}
void initializeStaticLSData209(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for Mixer1.Fvapg */
  linearSystemData->nominal[i] = data->modelData->realParameterData[1020].attribute /* Mixer1._Fvapg */.nominal;
  linearSystemData->min[i]     = data->modelData->realParameterData[1020].attribute /* Mixer1._Fvapg */.min;
  linearSystemData->max[i++]   = data->modelData->realParameterData[1020].attribute /* Mixer1._Fvapg */.max;
}


/*
 equation index: 298
 type: SIMPLE_ASSIGN
 MaterialStream2._Fvapg = MaterialStream2.Fg - MaterialStream2.Fliqg
 */
void Flowsheet_eqFunction_298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,298};
  data->simulationInfo->realParameter[606] = data->simulationInfo->realParameter[604] - data->simulationInfo->realParameter[605];
  TRACE_POP
}

void residualFunc301(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,301};
  data->simulationInfo->realParameter[605] = xloc[0];
  /* local constraints */
  Flowsheet_eqFunction_298(data, threadData);
  res[0] = (data->simulationInfo->realParameter[647]) * (data->simulationInfo->realParameter[606]) + (data->simulationInfo->realParameter[639]) * (data->simulationInfo->realParameter[605]) - ((data->simulationInfo->realParameter[641]) * (data->simulationInfo->realParameter[604]));
  TRACE_POP
}
void initializeStaticLSData301(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream2.Fliqg */
  linearSystemData->nominal[i] = data->modelData->realParameterData[605].attribute /* MaterialStream2._Fliqg */.nominal;
  linearSystemData->min[i]     = data->modelData->realParameterData[605].attribute /* MaterialStream2._Fliqg */.min;
  linearSystemData->max[i++]   = data->modelData->realParameterData[605].attribute /* MaterialStream2._Fliqg */.max;
}


/*
 equation index: 404
 type: SIMPLE_ASSIGN
 MaterialStream1._Fliqg = MaterialStream1.Fg - MaterialStream1.Fvapg
 */
void Flowsheet_eqFunction_404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,404};
  data->simulationInfo->realParameter[398] = data->simulationInfo->realParameter[397] - data->simulationInfo->realParameter[399];
  TRACE_POP
}

void residualFunc407(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,407};
  data->simulationInfo->realParameter[399] = xloc[0];
  /* local constraints */
  Flowsheet_eqFunction_404(data, threadData);
  res[0] = (data->simulationInfo->realParameter[440]) * (data->simulationInfo->realParameter[399]) + (data->simulationInfo->realParameter[432]) * (data->simulationInfo->realParameter[398]) - ((data->simulationInfo->realParameter[434]) * (data->simulationInfo->realParameter[397]));
  TRACE_POP
}
void initializeStaticLSData407(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream1.Fvapg */
  linearSystemData->nominal[i] = data->modelData->realParameterData[399].attribute /* MaterialStream1._Fvapg */.nominal;
  linearSystemData->min[i]     = data->modelData->realParameterData[399].attribute /* MaterialStream1._Fvapg */.min;
  linearSystemData->max[i++]   = data->modelData->realParameterData[399].attribute /* MaterialStream1._Fvapg */.max;
}

void setLinearMatrixA516(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,516};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  modelica_real tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  modelica_real tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_real tmp17;
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  modelica_boolean tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  modelica_boolean tmp29;
  modelica_real tmp30;
  modelica_boolean tmp31;
  modelica_boolean tmp32;
  modelica_boolean tmp33;
  modelica_boolean tmp34;
  modelica_real tmp35;
  modelica_boolean tmp36;
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  modelica_real tmp39;
  modelica_boolean tmp40;
  modelica_boolean tmp41;
  modelica_boolean tmp42;
  modelica_real tmp43;
  tmp0 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(0, 2, (-((tmp0?1.0:-0.0))), 0, linearSystemData, threadData);
  tmp1 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp3 = (modelica_boolean)tmp1;
  if(tmp3)
  {
    tmp4 = 0.0;
  }
  else
  {
    tmp2 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp4 = (tmp2?(-data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(0, 4, (-(tmp4)), 1, linearSystemData, threadData);
  tmp5 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp7 = (modelica_boolean)tmp5;
  if(tmp7)
  {
    tmp8 = 0.0;
  }
  else
  {
    tmp6 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp8 = (tmp6?-0.0:1.0);
  }
  linearSystemData->setAElement(1, 2, (-(tmp8)), 2, linearSystemData, threadData);
  tmp9 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp11 = (modelica_boolean)tmp9;
  if(tmp11)
  {
    tmp12 = 0.0;
  }
  else
  {
    tmp10 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp12 = (tmp10?(-data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(1, 3, (-(tmp12)), 3, linearSystemData, threadData);
  tmp13 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(1, 4, (-((tmp13?1.0:-0.0))), 4, linearSystemData, threadData);
  tmp14 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp16 = (modelica_boolean)tmp14;
  if(tmp16)
  {
    tmp17 = -1.0;
  }
  else
  {
    tmp15 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp17 = (tmp15?-0.0:-1.0);
  }
  linearSystemData->setAElement(2, 0, (-(tmp17)), 5, linearSystemData, threadData);
  tmp18 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp20 = (modelica_boolean)tmp18;
  if(tmp20)
  {
    tmp21 = 0.0;
  }
  else
  {
    tmp19 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp21 = (tmp19?-0.0:1.0);
  }
  linearSystemData->setAElement(2, 1, (-(tmp21)), 6, linearSystemData, threadData);
  tmp22 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp24 = (modelica_boolean)tmp22;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp23 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp25 = (tmp23?(-data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(2, 2, (-(tmp25)), 7, linearSystemData, threadData);
  tmp26 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(2, 3, (-((tmp26?1.0:-0.0))), 8, linearSystemData, threadData);
  tmp27 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp29 = (modelica_boolean)tmp27;
  if(tmp29)
  {
    tmp30 = 0.0;
  }
  else
  {
    tmp28 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp30 = (tmp28?(-data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(3, 0, (-(tmp30)), 9, linearSystemData, threadData);
  tmp31 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(3, 1, (-((tmp31?1.0:-0.0))), 10, linearSystemData, threadData);
  tmp32 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp34 = (modelica_boolean)tmp32;
  if(tmp34)
  {
    tmp35 = 0.0;
  }
  else
  {
    tmp33 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp35 = (tmp33?-0.0:1.0);
  }
  linearSystemData->setAElement(3, 3, (-(tmp35)), 11, linearSystemData, threadData);
  tmp36 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp38 = (modelica_boolean)tmp36;
  if(tmp38)
  {
    tmp39 = (-data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */);
  }
  else
  {
    tmp37 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp39 = (tmp37?-0.0:(-data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(4, 0, (-(tmp39)), 12, linearSystemData, threadData);
  tmp40 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp42 = (modelica_boolean)tmp40;
  if(tmp42)
  {
    tmp43 = -0.0;
  }
  else
  {
    tmp41 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp43 = (tmp41?(-data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(4, 1, (-(tmp43)), 13, linearSystemData, threadData);
}
void setLinearVectorb516(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,516};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp44;
  modelica_boolean tmp45;
  modelica_boolean tmp46;
  modelica_real tmp47;
  modelica_boolean tmp48;
  modelica_boolean tmp49;
  modelica_boolean tmp50;
  modelica_real tmp51;
  modelica_boolean tmp52;
  modelica_boolean tmp53;
  modelica_boolean tmp54;
  modelica_real tmp55;
  modelica_boolean tmp56;
  modelica_boolean tmp57;
  modelica_boolean tmp58;
  modelica_real tmp59;
  modelica_boolean tmp60;
  modelica_boolean tmp61;
  modelica_boolean tmp62;
  modelica_real tmp63;
  tmp44 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp46 = (modelica_boolean)tmp44;
  if(tmp46)
  {
    tmp47 = (-data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */);
  }
  else
  {
    tmp45 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp47 = (tmp45?data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(0, tmp47, linearSystemData, threadData);
  tmp48 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp50 = (modelica_boolean)tmp48;
  if(tmp50)
  {
    tmp51 = 0.0;
  }
  else
  {
    tmp49 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp51 = (tmp49?data->localData[0]->realVars[31] /* MaterialStream1._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(1, tmp51, linearSystemData, threadData);
  tmp52 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp54 = (modelica_boolean)tmp52;
  if(tmp54)
  {
    tmp55 = 0.0;
  }
  else
  {
    tmp53 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp55 = (tmp53?data->localData[0]->realVars[32] /* MaterialStream1._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(2, tmp55, linearSystemData, threadData);
  tmp56 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp58 = (modelica_boolean)tmp56;
  if(tmp58)
  {
    tmp59 = 0.0;
  }
  else
  {
    tmp57 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp59 = (tmp57?data->localData[0]->realVars[29] /* MaterialStream1._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(3, tmp59, linearSystemData, threadData);
  tmp60 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp62 = (modelica_boolean)tmp60;
  if(tmp62)
  {
    tmp63 = data->localData[0]->realVars[29] /* MaterialStream1._Fm_pc[1,1] variable */;
  }
  else
  {
    tmp61 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp63 = (tmp61?data->localData[0]->realVars[33] /* MaterialStream1._Fm_pc[3,1] variable */:data->localData[0]->realVars[29] /* MaterialStream1._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(4, tmp63, linearSystemData, threadData);
}
void initializeStaticLSData516(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream1.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[87].attribute /* MaterialStream1._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[87].attribute /* MaterialStream1._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[87].attribute /* MaterialStream1._xm_pc[1,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[91].attribute /* MaterialStream1._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[91].attribute /* MaterialStream1._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[91].attribute /* MaterialStream1._xm_pc[3,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[90].attribute /* MaterialStream1._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[90].attribute /* MaterialStream1._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[90].attribute /* MaterialStream1._xm_pc[2,2] */.max;
  /* static ls data for MaterialStream1.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[89].attribute /* MaterialStream1._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[89].attribute /* MaterialStream1._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[89].attribute /* MaterialStream1._xm_pc[2,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[3,2] */.max;
}

void setLinearMatrixA583(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,583};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp64;
  modelica_boolean tmp65;
  modelica_boolean tmp66;
  modelica_real tmp67;
  modelica_boolean tmp68;
  modelica_boolean tmp69;
  modelica_boolean tmp70;
  modelica_boolean tmp71;
  modelica_boolean tmp72;
  modelica_real tmp73;
  modelica_boolean tmp74;
  modelica_boolean tmp75;
  modelica_boolean tmp76;
  modelica_real tmp77;
  modelica_boolean tmp78;
  modelica_boolean tmp79;
  modelica_boolean tmp80;
  modelica_real tmp81;
  modelica_boolean tmp82;
  modelica_boolean tmp83;
  modelica_boolean tmp84;
  modelica_real tmp85;
  modelica_boolean tmp86;
  modelica_boolean tmp87;
  modelica_boolean tmp88;
  modelica_real tmp89;
  modelica_boolean tmp90;
  modelica_boolean tmp91;
  modelica_boolean tmp92;
  modelica_real tmp93;
  modelica_boolean tmp94;
  modelica_boolean tmp95;
  modelica_boolean tmp96;
  modelica_boolean tmp97;
  modelica_real tmp98;
  modelica_boolean tmp99;
  modelica_boolean tmp100;
  modelica_boolean tmp101;
  modelica_boolean tmp102;
  modelica_real tmp103;
  modelica_boolean tmp104;
  modelica_boolean tmp105;
  modelica_boolean tmp106;
  modelica_real tmp107;
  tmp64 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp66 = (modelica_boolean)tmp64;
  if(tmp66)
  {
    tmp67 = 0.0;
  }
  else
  {
    tmp65 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp67 = (tmp65?(-data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(0, 0, (-(tmp67)), 0, linearSystemData, threadData);
  tmp68 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(0, 4, (-((tmp68?1.0:-0.0))), 1, linearSystemData, threadData);
  tmp69 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(1, 1, (-((tmp69?1.0:-0.0))), 2, linearSystemData, threadData);
  tmp70 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp72 = (modelica_boolean)tmp70;
  if(tmp72)
  {
    tmp73 = 0.0;
  }
  else
  {
    tmp71 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp73 = (tmp71?-0.0:1.0);
  }
  linearSystemData->setAElement(1, 2, (-(tmp73)), 3, linearSystemData, threadData);
  tmp74 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp76 = (modelica_boolean)tmp74;
  if(tmp76)
  {
    tmp77 = -1.0;
  }
  else
  {
    tmp75 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp77 = (tmp75?-0.0:-1.0);
  }
  linearSystemData->setAElement(1, 3, (-(tmp77)), 4, linearSystemData, threadData);
  tmp78 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp80 = (modelica_boolean)tmp78;
  if(tmp80)
  {
    tmp81 = 0.0;
  }
  else
  {
    tmp79 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp81 = (tmp79?(-data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(1, 4, (-(tmp81)), 5, linearSystemData, threadData);
  tmp82 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp84 = (modelica_boolean)tmp82;
  if(tmp84)
  {
    tmp85 = -0.0;
  }
  else
  {
    tmp83 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp85 = (tmp83?(-data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(2, 2, (-(tmp85)), 6, linearSystemData, threadData);
  tmp86 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp88 = (modelica_boolean)tmp86;
  if(tmp88)
  {
    tmp89 = (-data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */);
  }
  else
  {
    tmp87 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp89 = (tmp87?-0.0:(-data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(2, 3, (-(tmp89)), 7, linearSystemData, threadData);
  tmp90 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp92 = (modelica_boolean)tmp90;
  if(tmp92)
  {
    tmp93 = 0.0;
  }
  else
  {
    tmp91 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp93 = (tmp91?-0.0:1.0);
  }
  linearSystemData->setAElement(3, 1, (-(tmp93)), 8, linearSystemData, threadData);
  tmp94 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(3, 2, (-((tmp94?1.0:-0.0))), 9, linearSystemData, threadData);
  tmp95 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp97 = (modelica_boolean)tmp95;
  if(tmp97)
  {
    tmp98 = 0.0;
  }
  else
  {
    tmp96 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp98 = (tmp96?(-data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(3, 3, (-(tmp98)), 10, linearSystemData, threadData);
  tmp99 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(4, 0, (-((tmp99?1.0:-0.0))), 11, linearSystemData, threadData);
  tmp100 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp102 = (modelica_boolean)tmp100;
  if(tmp102)
  {
    tmp103 = 0.0;
  }
  else
  {
    tmp101 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp103 = (tmp101?(-data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(4, 1, (-(tmp103)), 12, linearSystemData, threadData);
  tmp104 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp106 = (modelica_boolean)tmp104;
  if(tmp106)
  {
    tmp107 = 0.0;
  }
  else
  {
    tmp105 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp107 = (tmp105?-0.0:1.0);
  }
  linearSystemData->setAElement(4, 4, (-(tmp107)), 13, linearSystemData, threadData);
}
void setLinearVectorb583(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,583};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp108;
  modelica_boolean tmp109;
  modelica_boolean tmp110;
  modelica_real tmp111;
  modelica_boolean tmp112;
  modelica_boolean tmp113;
  modelica_boolean tmp114;
  modelica_real tmp115;
  modelica_boolean tmp116;
  modelica_boolean tmp117;
  modelica_boolean tmp118;
  modelica_real tmp119;
  modelica_boolean tmp120;
  modelica_boolean tmp121;
  modelica_boolean tmp122;
  modelica_real tmp123;
  modelica_boolean tmp124;
  modelica_boolean tmp125;
  modelica_boolean tmp126;
  modelica_real tmp127;
  tmp108 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp110 = (modelica_boolean)tmp108;
  if(tmp110)
  {
    tmp111 = (-data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */);
  }
  else
  {
    tmp109 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp111 = (tmp109?data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(0, tmp111, linearSystemData, threadData);
  tmp112 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp114 = (modelica_boolean)tmp112;
  if(tmp114)
  {
    tmp115 = 0.0;
  }
  else
  {
    tmp113 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp115 = (tmp113?data->localData[0]->realVars[122] /* MaterialStream2._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(1, tmp115, linearSystemData, threadData);
  tmp116 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp118 = (modelica_boolean)tmp116;
  if(tmp118)
  {
    tmp119 = data->localData[0]->realVars[119] /* MaterialStream2._Fm_pc[1,1] variable */;
  }
  else
  {
    tmp117 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp119 = (tmp117?data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[3,1] variable */:data->localData[0]->realVars[119] /* MaterialStream2._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(2, tmp119, linearSystemData, threadData);
  tmp120 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp122 = (modelica_boolean)tmp120;
  if(tmp122)
  {
    tmp123 = 0.0;
  }
  else
  {
    tmp121 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp123 = (tmp121?data->localData[0]->realVars[119] /* MaterialStream2._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(3, tmp123, linearSystemData, threadData);
  tmp124 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp126 = (modelica_boolean)tmp124;
  if(tmp126)
  {
    tmp127 = 0.0;
  }
  else
  {
    tmp125 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp127 = (tmp125?data->localData[0]->realVars[121] /* MaterialStream2._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(4, tmp127, linearSystemData, threadData);
}
void initializeStaticLSData583(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream2.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[3,2] */.max;
  /* static ls data for MaterialStream2.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[2,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[3,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[177].attribute /* MaterialStream2._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[177].attribute /* MaterialStream2._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[177].attribute /* MaterialStream2._xm_pc[1,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[2,2] */.max;
}

void setLinearMatrixA641(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,641};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp128;
  modelica_boolean tmp129;
  modelica_boolean tmp130;
  modelica_real tmp131;
  modelica_boolean tmp132;
  modelica_boolean tmp133;
  modelica_boolean tmp134;
  modelica_boolean tmp135;
  modelica_boolean tmp136;
  modelica_real tmp137;
  modelica_boolean tmp138;
  modelica_boolean tmp139;
  modelica_boolean tmp140;
  modelica_real tmp141;
  modelica_boolean tmp142;
  modelica_boolean tmp143;
  modelica_boolean tmp144;
  modelica_real tmp145;
  modelica_boolean tmp146;
  modelica_boolean tmp147;
  modelica_boolean tmp148;
  modelica_real tmp149;
  modelica_boolean tmp150;
  modelica_boolean tmp151;
  modelica_boolean tmp152;
  modelica_real tmp153;
  modelica_boolean tmp154;
  modelica_boolean tmp155;
  modelica_boolean tmp156;
  modelica_real tmp157;
  modelica_boolean tmp158;
  modelica_boolean tmp159;
  modelica_boolean tmp160;
  modelica_boolean tmp161;
  modelica_real tmp162;
  modelica_boolean tmp163;
  modelica_boolean tmp164;
  modelica_boolean tmp165;
  modelica_boolean tmp166;
  modelica_real tmp167;
  modelica_boolean tmp168;
  modelica_boolean tmp169;
  modelica_boolean tmp170;
  modelica_real tmp171;
  tmp128 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp130 = (modelica_boolean)tmp128;
  if(tmp130)
  {
    tmp131 = 0.0;
  }
  else
  {
    tmp129 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp131 = (tmp129?(-data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(0, 0, (-(tmp131)), 0, linearSystemData, threadData);
  tmp132 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  linearSystemData->setAElement(0, 4, (-((tmp132?1.0:-0.0))), 1, linearSystemData, threadData);
  tmp133 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  linearSystemData->setAElement(1, 1, (-((tmp133?1.0:-0.0))), 2, linearSystemData, threadData);
  tmp134 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp136 = (modelica_boolean)tmp134;
  if(tmp136)
  {
    tmp137 = 0.0;
  }
  else
  {
    tmp135 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp137 = (tmp135?-0.0:1.0);
  }
  linearSystemData->setAElement(1, 2, (-(tmp137)), 3, linearSystemData, threadData);
  tmp138 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp140 = (modelica_boolean)tmp138;
  if(tmp140)
  {
    tmp141 = -1.0;
  }
  else
  {
    tmp139 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp141 = (tmp139?-0.0:-1.0);
  }
  linearSystemData->setAElement(1, 3, (-(tmp141)), 4, linearSystemData, threadData);
  tmp142 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp144 = (modelica_boolean)tmp142;
  if(tmp144)
  {
    tmp145 = 0.0;
  }
  else
  {
    tmp143 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp145 = (tmp143?(-data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(1, 4, (-(tmp145)), 5, linearSystemData, threadData);
  tmp146 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp148 = (modelica_boolean)tmp146;
  if(tmp148)
  {
    tmp149 = -0.0;
  }
  else
  {
    tmp147 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp149 = (tmp147?(-data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(2, 2, (-(tmp149)), 6, linearSystemData, threadData);
  tmp150 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp152 = (modelica_boolean)tmp150;
  if(tmp152)
  {
    tmp153 = (-data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */);
  }
  else
  {
    tmp151 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp153 = (tmp151?-0.0:(-data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(2, 3, (-(tmp153)), 7, linearSystemData, threadData);
  tmp154 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp156 = (modelica_boolean)tmp154;
  if(tmp156)
  {
    tmp157 = 0.0;
  }
  else
  {
    tmp155 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp157 = (tmp155?-0.0:1.0);
  }
  linearSystemData->setAElement(3, 1, (-(tmp157)), 8, linearSystemData, threadData);
  tmp158 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  linearSystemData->setAElement(3, 2, (-((tmp158?1.0:-0.0))), 9, linearSystemData, threadData);
  tmp159 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp161 = (modelica_boolean)tmp159;
  if(tmp161)
  {
    tmp162 = 0.0;
  }
  else
  {
    tmp160 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp162 = (tmp160?(-data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(3, 3, (-(tmp162)), 10, linearSystemData, threadData);
  tmp163 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  linearSystemData->setAElement(4, 0, (-((tmp163?1.0:-0.0))), 11, linearSystemData, threadData);
  tmp164 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp166 = (modelica_boolean)tmp164;
  if(tmp166)
  {
    tmp167 = 0.0;
  }
  else
  {
    tmp165 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp167 = (tmp165?(-data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(4, 1, (-(tmp167)), 12, linearSystemData, threadData);
  tmp168 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp170 = (modelica_boolean)tmp168;
  if(tmp170)
  {
    tmp171 = 0.0;
  }
  else
  {
    tmp169 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp171 = (tmp169?-0.0:1.0);
  }
  linearSystemData->setAElement(4, 4, (-(tmp171)), 13, linearSystemData, threadData);
}
void setLinearVectorb641(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,641};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp172;
  modelica_boolean tmp173;
  modelica_boolean tmp174;
  modelica_real tmp175;
  modelica_boolean tmp176;
  modelica_boolean tmp177;
  modelica_boolean tmp178;
  modelica_real tmp179;
  modelica_boolean tmp180;
  modelica_boolean tmp181;
  modelica_boolean tmp182;
  modelica_real tmp183;
  modelica_boolean tmp184;
  modelica_boolean tmp185;
  modelica_boolean tmp186;
  modelica_real tmp187;
  modelica_boolean tmp188;
  modelica_boolean tmp189;
  modelica_boolean tmp190;
  modelica_real tmp191;
  tmp172 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp174 = (modelica_boolean)tmp172;
  if(tmp174)
  {
    tmp175 = (-data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */);
  }
  else
  {
    tmp173 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp175 = (tmp173?data->localData[0]->realVars[214] /* MaterialStream3._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(0, tmp175, linearSystemData, threadData);
  tmp176 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp178 = (modelica_boolean)tmp176;
  if(tmp178)
  {
    tmp179 = 0.0;
  }
  else
  {
    tmp177 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp179 = (tmp177?data->localData[0]->realVars[212] /* MaterialStream3._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(1, tmp179, linearSystemData, threadData);
  tmp180 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp182 = (modelica_boolean)tmp180;
  if(tmp182)
  {
    tmp183 = data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */;
  }
  else
  {
    tmp181 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp183 = (tmp181?data->localData[0]->realVars[213] /* MaterialStream3._Fm_pc[3,1] variable */:data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(2, tmp183, linearSystemData, threadData);
  tmp184 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp186 = (modelica_boolean)tmp184;
  if(tmp186)
  {
    tmp187 = 0.0;
  }
  else
  {
    tmp185 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp187 = (tmp185?data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(3, tmp187, linearSystemData, threadData);
  tmp188 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp190 = (modelica_boolean)tmp188;
  if(tmp190)
  {
    tmp191 = 0.0;
  }
  else
  {
    tmp189 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp191 = (tmp189?data->localData[0]->realVars[211] /* MaterialStream3._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(4, tmp191, linearSystemData, threadData);
}
void initializeStaticLSData641(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream3.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[272].attribute /* MaterialStream3._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[272].attribute /* MaterialStream3._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[272].attribute /* MaterialStream3._xm_pc[3,2] */.max;
  /* static ls data for MaterialStream3.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[269].attribute /* MaterialStream3._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[269].attribute /* MaterialStream3._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[269].attribute /* MaterialStream3._xm_pc[2,1] */.max;
  /* static ls data for MaterialStream3.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[271].attribute /* MaterialStream3._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[271].attribute /* MaterialStream3._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[271].attribute /* MaterialStream3._xm_pc[3,1] */.max;
  /* static ls data for MaterialStream3.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[267].attribute /* MaterialStream3._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[267].attribute /* MaterialStream3._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[267].attribute /* MaterialStream3._xm_pc[1,1] */.max;
  /* static ls data for MaterialStream3.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[270].attribute /* MaterialStream3._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[270].attribute /* MaterialStream3._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[270].attribute /* MaterialStream3._xm_pc[2,2] */.max;
}
/* initial_lambda0 linear systems */
/* parameter linear systems */
/* model linear systems */
void setLinearMatrixA741(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,741};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp192;
  modelica_boolean tmp193;
  modelica_boolean tmp194;
  modelica_real tmp195;
  modelica_boolean tmp196;
  modelica_boolean tmp197;
  modelica_boolean tmp198;
  modelica_real tmp199;
  modelica_boolean tmp200;
  modelica_boolean tmp201;
  modelica_boolean tmp202;
  modelica_boolean tmp203;
  modelica_real tmp204;
  modelica_boolean tmp205;
  modelica_boolean tmp206;
  modelica_boolean tmp207;
  modelica_real tmp208;
  modelica_boolean tmp209;
  modelica_boolean tmp210;
  modelica_boolean tmp211;
  modelica_boolean tmp212;
  modelica_real tmp213;
  modelica_boolean tmp214;
  modelica_boolean tmp215;
  modelica_boolean tmp216;
  modelica_boolean tmp217;
  modelica_real tmp218;
  modelica_boolean tmp219;
  modelica_boolean tmp220;
  modelica_boolean tmp221;
  modelica_boolean tmp222;
  modelica_real tmp223;
  modelica_boolean tmp224;
  modelica_boolean tmp225;
  modelica_boolean tmp226;
  modelica_real tmp227;
  modelica_boolean tmp228;
  modelica_boolean tmp229;
  modelica_boolean tmp230;
  modelica_real tmp231;
  modelica_boolean tmp232;
  modelica_boolean tmp233;
  modelica_boolean tmp234;
  modelica_real tmp235;
  tmp192 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp194 = (modelica_boolean)tmp192;
  if(tmp194)
  {
    tmp195 = 0.0;
  }
  else
  {
    tmp193 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp195 = (tmp193?-0.0:1.0);
  }
  linearSystemData->setAElement(0, 0, (-(tmp195)), 0, linearSystemData, threadData);
  tmp196 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp198 = (modelica_boolean)tmp196;
  if(tmp198)
  {
    tmp199 = -1.0;
  }
  else
  {
    tmp197 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp199 = (tmp197?-0.0:-1.0);
  }
  linearSystemData->setAElement(0, 1, (-(tmp199)), 1, linearSystemData, threadData);
  tmp200 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(0, 2, (-((tmp200?1.0:-0.0))), 2, linearSystemData, threadData);
  tmp201 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp203 = (modelica_boolean)tmp201;
  if(tmp203)
  {
    tmp204 = 0.0;
  }
  else
  {
    tmp202 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp204 = (tmp202?(-data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(0, 4, (-(tmp204)), 3, linearSystemData, threadData);
  tmp205 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp207 = (modelica_boolean)tmp205;
  if(tmp207)
  {
    tmp208 = 0.0;
  }
  else
  {
    tmp206 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp208 = (tmp206?(-data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(1, 3, (-(tmp208)), 4, linearSystemData, threadData);
  tmp209 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(1, 4, (-((tmp209?1.0:-0.0))), 5, linearSystemData, threadData);
  tmp210 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp212 = (modelica_boolean)tmp210;
  if(tmp212)
  {
    tmp213 = 0.0;
  }
  else
  {
    tmp211 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp213 = (tmp211?(-data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(2, 2, (-(tmp213)), 6, linearSystemData, threadData);
  tmp214 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(2, 3, (-((tmp214?1.0:-0.0))), 7, linearSystemData, threadData);
  tmp215 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp217 = (modelica_boolean)tmp215;
  if(tmp217)
  {
    tmp218 = 0.0;
  }
  else
  {
    tmp216 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp218 = (tmp216?-0.0:1.0);
  }
  linearSystemData->setAElement(2, 4, (-(tmp218)), 8, linearSystemData, threadData);
  tmp219 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(3, 0, (-((tmp219?1.0:-0.0))), 9, linearSystemData, threadData);
  tmp220 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp222 = (modelica_boolean)tmp220;
  if(tmp222)
  {
    tmp223 = 0.0;
  }
  else
  {
    tmp221 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp223 = (tmp221?(-data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(3, 1, (-(tmp223)), 10, linearSystemData, threadData);
  tmp224 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp226 = (modelica_boolean)tmp224;
  if(tmp226)
  {
    tmp227 = 0.0;
  }
  else
  {
    tmp225 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp227 = (tmp225?-0.0:1.0);
  }
  linearSystemData->setAElement(3, 2, (-(tmp227)), 11, linearSystemData, threadData);
  tmp228 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp230 = (modelica_boolean)tmp228;
  if(tmp230)
  {
    tmp231 = -0.0;
  }
  else
  {
    tmp229 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp231 = (tmp229?(-data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(4, 0, (-(tmp231)), 12, linearSystemData, threadData);
  tmp232 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp234 = (modelica_boolean)tmp232;
  if(tmp234)
  {
    tmp235 = (-data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */);
  }
  else
  {
    tmp233 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp235 = (tmp233?-0.0:(-data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(4, 1, (-(tmp235)), 13, linearSystemData, threadData);
}
void setLinearVectorb741(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,741};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp236;
  modelica_boolean tmp237;
  modelica_boolean tmp238;
  modelica_real tmp239;
  modelica_boolean tmp240;
  modelica_boolean tmp241;
  modelica_boolean tmp242;
  modelica_real tmp243;
  modelica_boolean tmp244;
  modelica_boolean tmp245;
  modelica_boolean tmp246;
  modelica_real tmp247;
  modelica_boolean tmp248;
  modelica_boolean tmp249;
  modelica_boolean tmp250;
  modelica_real tmp251;
  modelica_boolean tmp252;
  modelica_boolean tmp253;
  modelica_boolean tmp254;
  modelica_real tmp255;
  tmp236 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp238 = (modelica_boolean)tmp236;
  if(tmp238)
  {
    tmp239 = 0.0;
  }
  else
  {
    tmp237 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp239 = (tmp237?data->localData[0]->realVars[32] /* MaterialStream1._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(0, tmp239, linearSystemData, threadData);
  tmp240 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp242 = (modelica_boolean)tmp240;
  if(tmp242)
  {
    tmp243 = (-data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */);
  }
  else
  {
    tmp241 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp243 = (tmp241?data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(1, tmp243, linearSystemData, threadData);
  tmp244 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp246 = (modelica_boolean)tmp244;
  if(tmp246)
  {
    tmp247 = 0.0;
  }
  else
  {
    tmp245 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp247 = (tmp245?data->localData[0]->realVars[31] /* MaterialStream1._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(2, tmp247, linearSystemData, threadData);
  tmp248 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp250 = (modelica_boolean)tmp248;
  if(tmp250)
  {
    tmp251 = 0.0;
  }
  else
  {
    tmp249 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp251 = (tmp249?data->localData[0]->realVars[29] /* MaterialStream1._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(3, tmp251, linearSystemData, threadData);
  tmp252 = GreaterEq(101325.0,data->localData[0]->realVars[53] /* MaterialStream1._Pbubl variable */);
  tmp254 = (modelica_boolean)tmp252;
  if(tmp254)
  {
    tmp255 = data->localData[0]->realVars[29] /* MaterialStream1._Fm_pc[1,1] variable */;
  }
  else
  {
    tmp253 = GreaterEq(101325.0,data->localData[0]->realVars[54] /* MaterialStream1._Pdew variable */);
    tmp255 = (tmp253?data->localData[0]->realVars[33] /* MaterialStream1._Fm_pc[3,1] variable */:data->localData[0]->realVars[29] /* MaterialStream1._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(4, tmp255, linearSystemData, threadData);
}
void initializeStaticLSData741(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream1.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[91].attribute /* MaterialStream1._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[91].attribute /* MaterialStream1._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[91].attribute /* MaterialStream1._xm_pc[3,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[87].attribute /* MaterialStream1._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[87].attribute /* MaterialStream1._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[87].attribute /* MaterialStream1._xm_pc[1,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[89].attribute /* MaterialStream1._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[89].attribute /* MaterialStream1._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[89].attribute /* MaterialStream1._xm_pc[2,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[3,2] */.max;
  /* static ls data for MaterialStream1.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[90].attribute /* MaterialStream1._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[90].attribute /* MaterialStream1._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[90].attribute /* MaterialStream1._xm_pc[2,2] */.max;
}

void setLinearMatrixA791(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,791};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp256;
  modelica_boolean tmp257;
  modelica_boolean tmp258;
  modelica_real tmp259;
  modelica_boolean tmp260;
  modelica_boolean tmp261;
  modelica_boolean tmp262;
  modelica_real tmp263;
  modelica_boolean tmp264;
  modelica_boolean tmp265;
  modelica_boolean tmp266;
  modelica_boolean tmp267;
  modelica_real tmp268;
  modelica_boolean tmp269;
  modelica_boolean tmp270;
  modelica_boolean tmp271;
  modelica_real tmp272;
  modelica_boolean tmp273;
  modelica_boolean tmp274;
  modelica_boolean tmp275;
  modelica_boolean tmp276;
  modelica_real tmp277;
  modelica_boolean tmp278;
  modelica_boolean tmp279;
  modelica_boolean tmp280;
  modelica_boolean tmp281;
  modelica_real tmp282;
  modelica_boolean tmp283;
  modelica_boolean tmp284;
  modelica_boolean tmp285;
  modelica_real tmp286;
  modelica_boolean tmp287;
  modelica_boolean tmp288;
  modelica_boolean tmp289;
  modelica_boolean tmp290;
  modelica_real tmp291;
  modelica_boolean tmp292;
  modelica_boolean tmp293;
  modelica_boolean tmp294;
  modelica_real tmp295;
  modelica_boolean tmp296;
  modelica_boolean tmp297;
  modelica_boolean tmp298;
  modelica_real tmp299;
  tmp256 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp258 = (modelica_boolean)tmp256;
  if(tmp258)
  {
    tmp259 = -1.0;
  }
  else
  {
    tmp257 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp259 = (tmp257?-0.0:-1.0);
  }
  linearSystemData->setAElement(0, 0, (-(tmp259)), 0, linearSystemData, threadData);
  tmp260 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp262 = (modelica_boolean)tmp260;
  if(tmp262)
  {
    tmp263 = 0.0;
  }
  else
  {
    tmp261 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp263 = (tmp261?-0.0:1.0);
  }
  linearSystemData->setAElement(0, 1, (-(tmp263)), 1, linearSystemData, threadData);
  tmp264 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(0, 2, (-((tmp264?1.0:-0.0))), 2, linearSystemData, threadData);
  tmp265 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp267 = (modelica_boolean)tmp265;
  if(tmp267)
  {
    tmp268 = 0.0;
  }
  else
  {
    tmp266 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp268 = (tmp266?(-data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(0, 4, (-(tmp268)), 3, linearSystemData, threadData);
  tmp269 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp271 = (modelica_boolean)tmp269;
  if(tmp271)
  {
    tmp272 = 0.0;
  }
  else
  {
    tmp270 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp272 = (tmp270?(-data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(1, 3, (-(tmp272)), 4, linearSystemData, threadData);
  tmp273 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(1, 4, (-((tmp273?1.0:-0.0))), 5, linearSystemData, threadData);
  tmp274 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp276 = (modelica_boolean)tmp274;
  if(tmp276)
  {
    tmp277 = 0.0;
  }
  else
  {
    tmp275 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp277 = (tmp275?(-data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(2, 2, (-(tmp277)), 6, linearSystemData, threadData);
  tmp278 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(2, 3, (-((tmp278?1.0:-0.0))), 7, linearSystemData, threadData);
  tmp279 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp281 = (modelica_boolean)tmp279;
  if(tmp281)
  {
    tmp282 = 0.0;
  }
  else
  {
    tmp280 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp282 = (tmp280?-0.0:1.0);
  }
  linearSystemData->setAElement(2, 4, (-(tmp282)), 8, linearSystemData, threadData);
  tmp283 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp285 = (modelica_boolean)tmp283;
  if(tmp285)
  {
    tmp286 = 0.0;
  }
  else
  {
    tmp284 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp286 = (tmp284?(-data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(3, 0, (-(tmp286)), 9, linearSystemData, threadData);
  tmp287 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(3, 1, (-((tmp287?1.0:-0.0))), 10, linearSystemData, threadData);
  tmp288 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp290 = (modelica_boolean)tmp288;
  if(tmp290)
  {
    tmp291 = 0.0;
  }
  else
  {
    tmp289 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp291 = (tmp289?-0.0:1.0);
  }
  linearSystemData->setAElement(3, 2, (-(tmp291)), 11, linearSystemData, threadData);
  tmp292 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp294 = (modelica_boolean)tmp292;
  if(tmp294)
  {
    tmp295 = (-data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */);
  }
  else
  {
    tmp293 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp295 = (tmp293?-0.0:(-data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(4, 0, (-(tmp295)), 12, linearSystemData, threadData);
  tmp296 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp298 = (modelica_boolean)tmp296;
  if(tmp298)
  {
    tmp299 = -0.0;
  }
  else
  {
    tmp297 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp299 = (tmp297?(-data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(4, 1, (-(tmp299)), 13, linearSystemData, threadData);
}
void setLinearVectorb791(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,791};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp300;
  modelica_boolean tmp301;
  modelica_boolean tmp302;
  modelica_real tmp303;
  modelica_boolean tmp304;
  modelica_boolean tmp305;
  modelica_boolean tmp306;
  modelica_real tmp307;
  modelica_boolean tmp308;
  modelica_boolean tmp309;
  modelica_boolean tmp310;
  modelica_real tmp311;
  modelica_boolean tmp312;
  modelica_boolean tmp313;
  modelica_boolean tmp314;
  modelica_real tmp315;
  modelica_boolean tmp316;
  modelica_boolean tmp317;
  modelica_boolean tmp318;
  modelica_real tmp319;
  tmp300 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp302 = (modelica_boolean)tmp300;
  if(tmp302)
  {
    tmp303 = 0.0;
  }
  else
  {
    tmp301 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp303 = (tmp301?data->localData[0]->realVars[122] /* MaterialStream2._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(0, tmp303, linearSystemData, threadData);
  tmp304 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp306 = (modelica_boolean)tmp304;
  if(tmp306)
  {
    tmp307 = (-data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */);
  }
  else
  {
    tmp305 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp307 = (tmp305?data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(1, tmp307, linearSystemData, threadData);
  tmp308 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp310 = (modelica_boolean)tmp308;
  if(tmp310)
  {
    tmp311 = 0.0;
  }
  else
  {
    tmp309 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp311 = (tmp309?data->localData[0]->realVars[121] /* MaterialStream2._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(2, tmp311, linearSystemData, threadData);
  tmp312 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp314 = (modelica_boolean)tmp312;
  if(tmp314)
  {
    tmp315 = 0.0;
  }
  else
  {
    tmp313 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp315 = (tmp313?data->localData[0]->realVars[119] /* MaterialStream2._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(3, tmp315, linearSystemData, threadData);
  tmp316 = GreaterEq(101325.0,data->localData[0]->realVars[143] /* MaterialStream2._Pbubl variable */);
  tmp318 = (modelica_boolean)tmp316;
  if(tmp318)
  {
    tmp319 = data->localData[0]->realVars[119] /* MaterialStream2._Fm_pc[1,1] variable */;
  }
  else
  {
    tmp317 = GreaterEq(101325.0,data->localData[0]->realVars[144] /* MaterialStream2._Pdew variable */);
    tmp319 = (tmp317?data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[3,1] variable */:data->localData[0]->realVars[119] /* MaterialStream2._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(4, tmp319, linearSystemData, threadData);
}
void initializeStaticLSData791(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream2.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[177].attribute /* MaterialStream2._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[177].attribute /* MaterialStream2._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[177].attribute /* MaterialStream2._xm_pc[1,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[3,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[2,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[3,2] */.max;
  /* static ls data for MaterialStream2.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[180].attribute /* MaterialStream2._xm_pc[2,2] */.max;
}

void setLinearMatrixA847(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,847};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp320;
  modelica_boolean tmp321;
  modelica_boolean tmp322;
  modelica_real tmp323;
  modelica_boolean tmp324;
  modelica_boolean tmp325;
  modelica_boolean tmp326;
  modelica_real tmp327;
  modelica_boolean tmp328;
  modelica_boolean tmp329;
  modelica_boolean tmp330;
  modelica_real tmp331;
  modelica_boolean tmp332;
  modelica_boolean tmp333;
  modelica_boolean tmp334;
  modelica_boolean tmp335;
  modelica_real tmp336;
  modelica_boolean tmp337;
  modelica_boolean tmp338;
  modelica_boolean tmp339;
  modelica_boolean tmp340;
  modelica_real tmp341;
  modelica_boolean tmp342;
  modelica_boolean tmp343;
  modelica_boolean tmp344;
  modelica_real tmp345;
  modelica_boolean tmp346;
  modelica_boolean tmp347;
  modelica_boolean tmp348;
  modelica_real tmp349;
  modelica_boolean tmp350;
  modelica_boolean tmp351;
  modelica_boolean tmp352;
  modelica_real tmp353;
  modelica_boolean tmp354;
  modelica_boolean tmp355;
  modelica_boolean tmp356;
  modelica_boolean tmp357;
  modelica_real tmp358;
  modelica_boolean tmp359;
  modelica_boolean tmp360;
  modelica_boolean tmp361;
  modelica_boolean tmp362;
  modelica_real tmp363;
  tmp320 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp322 = (modelica_boolean)tmp320;
  if(tmp322)
  {
    tmp323 = -0.0;
  }
  else
  {
    tmp321 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp323 = (tmp321?(-data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(0, 3, (-(tmp323)), 0, linearSystemData, threadData);
  tmp324 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp326 = (modelica_boolean)tmp324;
  if(tmp326)
  {
    tmp327 = (-data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */);
  }
  else
  {
    tmp325 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp327 = (tmp325?-0.0:(-data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(0, 4, (-(tmp327)), 1, linearSystemData, threadData);
  tmp328 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp330 = (modelica_boolean)tmp328;
  if(tmp330)
  {
    tmp331 = 0.0;
  }
  else
  {
    tmp329 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp331 = (tmp329?-0.0:1.0);
  }
  linearSystemData->setAElement(1, 0, (-(tmp331)), 2, linearSystemData, threadData);
  tmp332 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  linearSystemData->setAElement(1, 3, (-((tmp332?1.0:-0.0))), 3, linearSystemData, threadData);
  tmp333 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp335 = (modelica_boolean)tmp333;
  if(tmp335)
  {
    tmp336 = 0.0;
  }
  else
  {
    tmp334 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp336 = (tmp334?(-data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(1, 4, (-(tmp336)), 4, linearSystemData, threadData);
  tmp337 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  linearSystemData->setAElement(2, 0, (-((tmp337?1.0:-0.0))), 5, linearSystemData, threadData);
  tmp338 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp340 = (modelica_boolean)tmp338;
  if(tmp340)
  {
    tmp341 = 0.0;
  }
  else
  {
    tmp339 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp341 = (tmp339?(-data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(2, 2, (-(tmp341)), 6, linearSystemData, threadData);
  tmp342 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp344 = (modelica_boolean)tmp342;
  if(tmp344)
  {
    tmp345 = 0.0;
  }
  else
  {
    tmp343 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp345 = (tmp343?-0.0:1.0);
  }
  linearSystemData->setAElement(2, 3, (-(tmp345)), 7, linearSystemData, threadData);
  tmp346 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp348 = (modelica_boolean)tmp346;
  if(tmp348)
  {
    tmp349 = -1.0;
  }
  else
  {
    tmp347 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp349 = (tmp347?-0.0:-1.0);
  }
  linearSystemData->setAElement(2, 4, (-(tmp349)), 8, linearSystemData, threadData);
  tmp350 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp352 = (modelica_boolean)tmp350;
  if(tmp352)
  {
    tmp353 = 0.0;
  }
  else
  {
    tmp351 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp353 = (tmp351?(-data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(3, 1, (-(tmp353)), 9, linearSystemData, threadData);
  tmp354 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  linearSystemData->setAElement(3, 2, (-((tmp354?1.0:-0.0))), 10, linearSystemData, threadData);
  tmp355 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp357 = (modelica_boolean)tmp355;
  if(tmp357)
  {
    tmp358 = 0.0;
  }
  else
  {
    tmp356 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp358 = (tmp356?(-data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(4, 0, (-(tmp358)), 11, linearSystemData, threadData);
  tmp359 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  linearSystemData->setAElement(4, 1, (-((tmp359?1.0:-0.0))), 12, linearSystemData, threadData);
  tmp360 = GreaterEq(101325.0,data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
  tmp362 = (modelica_boolean)tmp360;
  if(tmp362)
  {
    tmp363 = 0.0;
  }
  else
  {
    tmp361 = GreaterEq(101325.0,data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
    tmp363 = (tmp361?-0.0:1.0);
  }
  linearSystemData->setAElement(4, 2, (-(tmp363)), 13, linearSystemData, threadData);
}
void setLinearVectorb847(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,847};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp364;
  modelica_boolean tmp365;
  modelica_boolean tmp366;
  modelica_real tmp367;
  modelica_boolean tmp368;
  modelica_boolean tmp369;
  modelica_boolean tmp370;
  modelica_real tmp371;
  modelica_boolean tmp372;
  modelica_boolean tmp373;
  modelica_boolean tmp374;
  modelica_real tmp375;
  modelica_boolean tmp376;
  modelica_boolean tmp377;
  modelica_boolean tmp378;
  modelica_real tmp379;
  modelica_boolean tmp380;
  modelica_boolean tmp381;
  modelica_boolean tmp382;
  modelica_real tmp383;
  RELATIONHYSTERESIS(tmp364, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp366 = (modelica_boolean)tmp364;
  if(tmp366)
  {
    tmp367 = data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp365, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp367 = (tmp365?data->localData[0]->realVars[213] /* MaterialStream3._Fm_pc[3,1] variable */:data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(0, tmp367, linearSystemData, threadData);
  RELATIONHYSTERESIS(tmp368, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp370 = (modelica_boolean)tmp368;
  if(tmp370)
  {
    tmp371 = 0.0;
  }
  else
  {
    RELATIONHYSTERESIS(tmp369, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp371 = (tmp369?data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(1, tmp371, linearSystemData, threadData);
  RELATIONHYSTERESIS(tmp372, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp374 = (modelica_boolean)tmp372;
  if(tmp374)
  {
    tmp375 = 0.0;
  }
  else
  {
    RELATIONHYSTERESIS(tmp373, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp375 = (tmp373?data->localData[0]->realVars[212] /* MaterialStream3._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(2, tmp375, linearSystemData, threadData);
  RELATIONHYSTERESIS(tmp376, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp378 = (modelica_boolean)tmp376;
  if(tmp378)
  {
    tmp379 = (-data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */);
  }
  else
  {
    RELATIONHYSTERESIS(tmp377, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp379 = (tmp377?data->localData[0]->realVars[214] /* MaterialStream3._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(3, tmp379, linearSystemData, threadData);
  RELATIONHYSTERESIS(tmp380, 101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, 0, GreaterEq);
  tmp382 = (modelica_boolean)tmp380;
  if(tmp382)
  {
    tmp383 = 0.0;
  }
  else
  {
    RELATIONHYSTERESIS(tmp381, 101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, 1, GreaterEq);
    tmp383 = (tmp381?data->localData[0]->realVars[211] /* MaterialStream3._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(4, tmp383, linearSystemData, threadData);
}
void initializeStaticLSData847(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream3.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[269].attribute /* MaterialStream3._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[269].attribute /* MaterialStream3._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[269].attribute /* MaterialStream3._xm_pc[2,1] */.max;
  /* static ls data for MaterialStream3.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[272].attribute /* MaterialStream3._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[272].attribute /* MaterialStream3._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[272].attribute /* MaterialStream3._xm_pc[3,2] */.max;
  /* static ls data for MaterialStream3.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[270].attribute /* MaterialStream3._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[270].attribute /* MaterialStream3._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[270].attribute /* MaterialStream3._xm_pc[2,2] */.max;
  /* static ls data for MaterialStream3.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[271].attribute /* MaterialStream3._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[271].attribute /* MaterialStream3._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[271].attribute /* MaterialStream3._xm_pc[3,1] */.max;
  /* static ls data for MaterialStream3.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[267].attribute /* MaterialStream3._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[267].attribute /* MaterialStream3._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[267].attribute /* MaterialStream3._xm_pc[1,1] */.max;
}
/* inline linear systems */
/* jacobians linear systems */

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize linear systems */
void Flowsheet_initialLinearSystem(int nLinearSystems, LINEAR_SYSTEM_DATA* linearSystemData)
{
  /* initial linear systems */
  assertStreamPrint(NULL, nLinearSystems > 0, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[0].equationIndex = 106;
  linearSystemData[0].size = 1;
  linearSystemData[0].nnz = 0;
  linearSystemData[0].method = 1;
  linearSystemData[0].residualFunc = residualFunc106;
  linearSystemData[0].strictTearingFunctionCall = NULL;
  linearSystemData[0].analyticalJacobianColumn = Flowsheet_functionJacLSJac2_column;
  linearSystemData[0].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianLSJac2;
  linearSystemData[0].jacobianIndex = 0;
  linearSystemData[0].setA = NULL;//setLinearMatrixA106;
  linearSystemData[0].setb = NULL; //setLinearVectorb106;
  linearSystemData[0].initializeStaticLSData = initializeStaticLSData106;
  
  assertStreamPrint(NULL, nLinearSystems > 1, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[1].equationIndex = 209;
  linearSystemData[1].size = 1;
  linearSystemData[1].nnz = 0;
  linearSystemData[1].method = 1;
  linearSystemData[1].residualFunc = residualFunc209;
  linearSystemData[1].strictTearingFunctionCall = NULL;
  linearSystemData[1].analyticalJacobianColumn = Flowsheet_functionJacLSJac5_column;
  linearSystemData[1].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianLSJac5;
  linearSystemData[1].jacobianIndex = 1;
  linearSystemData[1].setA = NULL;//setLinearMatrixA209;
  linearSystemData[1].setb = NULL; //setLinearVectorb209;
  linearSystemData[1].initializeStaticLSData = initializeStaticLSData209;
  
  assertStreamPrint(NULL, nLinearSystems > 2, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[2].equationIndex = 301;
  linearSystemData[2].size = 1;
  linearSystemData[2].nnz = 0;
  linearSystemData[2].method = 1;
  linearSystemData[2].residualFunc = residualFunc301;
  linearSystemData[2].strictTearingFunctionCall = NULL;
  linearSystemData[2].analyticalJacobianColumn = Flowsheet_functionJacLSJac8_column;
  linearSystemData[2].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianLSJac8;
  linearSystemData[2].jacobianIndex = 2;
  linearSystemData[2].setA = NULL;//setLinearMatrixA301;
  linearSystemData[2].setb = NULL; //setLinearVectorb301;
  linearSystemData[2].initializeStaticLSData = initializeStaticLSData301;
  
  assertStreamPrint(NULL, nLinearSystems > 3, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[3].equationIndex = 407;
  linearSystemData[3].size = 1;
  linearSystemData[3].nnz = 0;
  linearSystemData[3].method = 1;
  linearSystemData[3].residualFunc = residualFunc407;
  linearSystemData[3].strictTearingFunctionCall = NULL;
  linearSystemData[3].analyticalJacobianColumn = Flowsheet_functionJacLSJac11_column;
  linearSystemData[3].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianLSJac11;
  linearSystemData[3].jacobianIndex = 3;
  linearSystemData[3].setA = NULL;//setLinearMatrixA407;
  linearSystemData[3].setb = NULL; //setLinearVectorb407;
  linearSystemData[3].initializeStaticLSData = initializeStaticLSData407;
  
  assertStreamPrint(NULL, nLinearSystems > 4, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[4].equationIndex = 516;
  linearSystemData[4].size = 5;
  linearSystemData[4].nnz = 14;
  linearSystemData[4].method = 0;
  linearSystemData[4].strictTearingFunctionCall = NULL;
  linearSystemData[4].setA = setLinearMatrixA516;
  linearSystemData[4].setb = setLinearVectorb516;
  linearSystemData[4].initializeStaticLSData = initializeStaticLSData516;
  
  assertStreamPrint(NULL, nLinearSystems > 5, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[5].equationIndex = 583;
  linearSystemData[5].size = 5;
  linearSystemData[5].nnz = 14;
  linearSystemData[5].method = 0;
  linearSystemData[5].strictTearingFunctionCall = NULL;
  linearSystemData[5].setA = setLinearMatrixA583;
  linearSystemData[5].setb = setLinearVectorb583;
  linearSystemData[5].initializeStaticLSData = initializeStaticLSData583;
  
  assertStreamPrint(NULL, nLinearSystems > 6, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[6].equationIndex = 641;
  linearSystemData[6].size = 5;
  linearSystemData[6].nnz = 14;
  linearSystemData[6].method = 0;
  linearSystemData[6].strictTearingFunctionCall = NULL;
  linearSystemData[6].setA = setLinearMatrixA641;
  linearSystemData[6].setb = setLinearVectorb641;
  linearSystemData[6].initializeStaticLSData = initializeStaticLSData641;
  /* initial_lambda0 linear systems */
  /* parameter linear systems */
  /* model linear systems */
  assertStreamPrint(NULL, nLinearSystems > 7, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[7].equationIndex = 741;
  linearSystemData[7].size = 5;
  linearSystemData[7].nnz = 14;
  linearSystemData[7].method = 0;
  linearSystemData[7].strictTearingFunctionCall = NULL;
  linearSystemData[7].setA = setLinearMatrixA741;
  linearSystemData[7].setb = setLinearVectorb741;
  linearSystemData[7].initializeStaticLSData = initializeStaticLSData741;
  
  assertStreamPrint(NULL, nLinearSystems > 8, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[8].equationIndex = 791;
  linearSystemData[8].size = 5;
  linearSystemData[8].nnz = 14;
  linearSystemData[8].method = 0;
  linearSystemData[8].strictTearingFunctionCall = NULL;
  linearSystemData[8].setA = setLinearMatrixA791;
  linearSystemData[8].setb = setLinearVectorb791;
  linearSystemData[8].initializeStaticLSData = initializeStaticLSData791;
  
  assertStreamPrint(NULL, nLinearSystems > 9, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[9].equationIndex = 847;
  linearSystemData[9].size = 5;
  linearSystemData[9].nnz = 14;
  linearSystemData[9].method = 0;
  linearSystemData[9].strictTearingFunctionCall = NULL;
  linearSystemData[9].setA = setLinearMatrixA847;
  linearSystemData[9].setb = setLinearVectorb847;
  linearSystemData[9].initializeStaticLSData = initializeStaticLSData847;
  /* inline linear systems */
  /* jacobians linear systems */
}

#if defined(__cplusplus)
}
#endif

