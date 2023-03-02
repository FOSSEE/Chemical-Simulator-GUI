/* Linear Systems */
#include "Flowsheet_model.h"
#include "Flowsheet_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* initial linear systems */

/*
 equation index: 93
 type: SIMPLE_ASSIGN
 Heater1._Fliqg = Heater1.Fg - Heater1.Fvapg
 */
void Flowsheet_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
  data->simulationInfo->realParameter[399] = data->simulationInfo->realParameter[398] - data->simulationInfo->realParameter[400];
  TRACE_POP
}

void residualFunc96(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,96};
  data->simulationInfo->realParameter[400] = xloc[0];
  /* local constraints */
  Flowsheet_eqFunction_93(data, threadData);
  res[0] = (data->simulationInfo->realParameter[442]) * (data->simulationInfo->realParameter[400]) + (data->simulationInfo->realParameter[434]) * (data->simulationInfo->realParameter[399]) - ((data->simulationInfo->realParameter[436]) * (data->simulationInfo->realParameter[398]));
  TRACE_POP
}
void initializeStaticLSData96(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for Heater1.Fvapg */
  linearSystemData->nominal[i] = data->modelData->realParameterData[400].attribute /* Heater1._Fvapg */.nominal;
  linearSystemData->min[i]     = data->modelData->realParameterData[400].attribute /* Heater1._Fvapg */.min;
  linearSystemData->max[i++]   = data->modelData->realParameterData[400].attribute /* Heater1._Fvapg */.max;
}


/*
 equation index: 187
 type: SIMPLE_ASSIGN
 MaterialStream2._Fliqg = MaterialStream2.Fg - MaterialStream2.Fvapg
 */
void Flowsheet_eqFunction_187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,187};
  data->simulationInfo->realParameter[814] = data->simulationInfo->realParameter[813] - data->simulationInfo->realParameter[815];
  TRACE_POP
}

void residualFunc190(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,190};
  data->simulationInfo->realParameter[815] = xloc[0];
  /* local constraints */
  Flowsheet_eqFunction_187(data, threadData);
  res[0] = (data->simulationInfo->realParameter[856]) * (data->simulationInfo->realParameter[815]) + (data->simulationInfo->realParameter[848]) * (data->simulationInfo->realParameter[814]) - ((data->simulationInfo->realParameter[850]) * (data->simulationInfo->realParameter[813]));
  TRACE_POP
}
void initializeStaticLSData190(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream2.Fvapg */
  linearSystemData->nominal[i] = data->modelData->realParameterData[815].attribute /* MaterialStream2._Fvapg */.nominal;
  linearSystemData->min[i]     = data->modelData->realParameterData[815].attribute /* MaterialStream2._Fvapg */.min;
  linearSystemData->max[i++]   = data->modelData->realParameterData[815].attribute /* MaterialStream2._Fvapg */.max;
}


/*
 equation index: 295
 type: SIMPLE_ASSIGN
 MaterialStream1._Fliqg = MaterialStream1.Fg - MaterialStream1.Fvapg
 */
void Flowsheet_eqFunction_295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,295};
  data->simulationInfo->realParameter[607] = data->simulationInfo->realParameter[606] - data->simulationInfo->realParameter[608];
  TRACE_POP
}

void residualFunc298(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,298};
  data->simulationInfo->realParameter[608] = xloc[0];
  /* local constraints */
  Flowsheet_eqFunction_295(data, threadData);
  res[0] = (data->simulationInfo->realParameter[649]) * (data->simulationInfo->realParameter[608]) + (data->simulationInfo->realParameter[641]) * (data->simulationInfo->realParameter[607]) - ((data->simulationInfo->realParameter[643]) * (data->simulationInfo->realParameter[606]));
  TRACE_POP
}
void initializeStaticLSData298(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream1.Fvapg */
  linearSystemData->nominal[i] = data->modelData->realParameterData[608].attribute /* MaterialStream1._Fvapg */.nominal;
  linearSystemData->min[i]     = data->modelData->realParameterData[608].attribute /* MaterialStream1._Fvapg */.min;
  linearSystemData->max[i++]   = data->modelData->realParameterData[608].attribute /* MaterialStream1._Fvapg */.max;
}

void setLinearMatrixA408(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,408};
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
  modelica_real tmp29;
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  modelica_boolean tmp32;
  modelica_real tmp33;
  modelica_boolean tmp34;
  modelica_boolean tmp35;
  modelica_boolean tmp36;
  modelica_real tmp37;
  modelica_boolean tmp38;
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  modelica_boolean tmp41;
  modelica_real tmp42;
  modelica_boolean tmp43;
  tmp0 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(0, 0, (-((tmp0?1.0:-0.0))), 0, linearSystemData, threadData);
  tmp1 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp3 = (modelica_boolean)tmp1;
  if(tmp3)
  {
    tmp4 = 0.0;
  }
  else
  {
    tmp2 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp4 = (tmp2?-0.0:1.0);
  }
  linearSystemData->setAElement(0, 1, (-(tmp4)), 1, linearSystemData, threadData);
  tmp5 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp7 = (modelica_boolean)tmp5;
  if(tmp7)
  {
    tmp8 = 0.0;
  }
  else
  {
    tmp6 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp8 = (tmp6?(-data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(0, 4, (-(tmp8)), 2, linearSystemData, threadData);
  tmp9 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp11 = (modelica_boolean)tmp9;
  if(tmp11)
  {
    tmp12 = 0.0;
  }
  else
  {
    tmp10 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp12 = (tmp10?(-data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(1, 2, (-(tmp12)), 3, linearSystemData, threadData);
  tmp13 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(1, 3, (-((tmp13?1.0:-0.0))), 4, linearSystemData, threadData);
  tmp14 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp16 = (modelica_boolean)tmp14;
  if(tmp16)
  {
    tmp17 = 0.0;
  }
  else
  {
    tmp15 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp17 = (tmp15?-0.0:1.0);
  }
  linearSystemData->setAElement(1, 4, (-(tmp17)), 5, linearSystemData, threadData);
  tmp18 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp20 = (modelica_boolean)tmp18;
  if(tmp20)
  {
    tmp21 = (-data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */);
  }
  else
  {
    tmp19 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp21 = (tmp19?-0.0:(-data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(2, 2, (-(tmp21)), 6, linearSystemData, threadData);
  tmp22 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp24 = (modelica_boolean)tmp22;
  if(tmp24)
  {
    tmp25 = -0.0;
  }
  else
  {
    tmp23 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp25 = (tmp23?(-data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(2, 3, (-(tmp25)), 7, linearSystemData, threadData);
  tmp26 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp28 = (modelica_boolean)tmp26;
  if(tmp28)
  {
    tmp29 = 0.0;
  }
  else
  {
    tmp27 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp29 = (tmp27?(-data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(3, 1, (-(tmp29)), 8, linearSystemData, threadData);
  tmp30 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp32 = (modelica_boolean)tmp30;
  if(tmp32)
  {
    tmp33 = -1.0;
  }
  else
  {
    tmp31 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp33 = (tmp31?-0.0:-1.0);
  }
  linearSystemData->setAElement(3, 2, (-(tmp33)), 9, linearSystemData, threadData);
  tmp34 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp36 = (modelica_boolean)tmp34;
  if(tmp36)
  {
    tmp37 = 0.0;
  }
  else
  {
    tmp35 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp37 = (tmp35?-0.0:1.0);
  }
  linearSystemData->setAElement(3, 3, (-(tmp37)), 10, linearSystemData, threadData);
  tmp38 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(3, 4, (-((tmp38?1.0:-0.0))), 11, linearSystemData, threadData);
  tmp39 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp41 = (modelica_boolean)tmp39;
  if(tmp41)
  {
    tmp42 = 0.0;
  }
  else
  {
    tmp40 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp42 = (tmp40?(-data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(4, 0, (-(tmp42)), 12, linearSystemData, threadData);
  tmp43 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(4, 1, (-((tmp43?1.0:-0.0))), 13, linearSystemData, threadData);
}
void setLinearVectorb408(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,408};
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
  tmp44 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp46 = (modelica_boolean)tmp44;
  if(tmp46)
  {
    tmp47 = 0.0;
  }
  else
  {
    tmp45 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp47 = (tmp45?data->localData[0]->realVars[125] /* MaterialStream2._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(0, tmp47, linearSystemData, threadData);
  tmp48 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp50 = (modelica_boolean)tmp48;
  if(tmp50)
  {
    tmp51 = 0.0;
  }
  else
  {
    tmp49 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp51 = (tmp49?data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(1, tmp51, linearSystemData, threadData);
  tmp52 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp54 = (modelica_boolean)tmp52;
  if(tmp54)
  {
    tmp55 = data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */;
  }
  else
  {
    tmp53 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp55 = (tmp53?data->localData[0]->realVars[127] /* MaterialStream2._Fm_pc[3,1] variable */:data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(2, tmp55, linearSystemData, threadData);
  tmp56 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp58 = (modelica_boolean)tmp56;
  if(tmp58)
  {
    tmp59 = 0.0;
  }
  else
  {
    tmp57 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp59 = (tmp57?data->localData[0]->realVars[126] /* MaterialStream2._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(3, tmp59, linearSystemData, threadData);
  tmp60 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp62 = (modelica_boolean)tmp60;
  if(tmp62)
  {
    tmp63 = (-data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */);
  }
  else
  {
    tmp61 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp63 = (tmp61?data->localData[0]->realVars[128] /* MaterialStream2._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(4, tmp63, linearSystemData, threadData);
}
void initializeStaticLSData408(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream2.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[184].attribute /* MaterialStream2._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[184].attribute /* MaterialStream2._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[184].attribute /* MaterialStream2._xm_pc[3,2] */.max;
  /* static ls data for MaterialStream2.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[2,2] */.max;
  /* static ls data for MaterialStream2.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[1,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[183].attribute /* MaterialStream2._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[183].attribute /* MaterialStream2._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[183].attribute /* MaterialStream2._xm_pc[3,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[2,1] */.max;
}

void setLinearMatrixA463(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,463};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp64;
  modelica_boolean tmp65;
  modelica_boolean tmp66;
  modelica_boolean tmp67;
  modelica_real tmp68;
  modelica_boolean tmp69;
  modelica_boolean tmp70;
  modelica_boolean tmp71;
  modelica_real tmp72;
  modelica_boolean tmp73;
  modelica_boolean tmp74;
  modelica_boolean tmp75;
  modelica_real tmp76;
  modelica_boolean tmp77;
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
  modelica_real tmp97;
  modelica_boolean tmp98;
  modelica_boolean tmp99;
  modelica_boolean tmp100;
  modelica_real tmp101;
  modelica_boolean tmp102;
  modelica_boolean tmp103;
  modelica_boolean tmp104;
  modelica_boolean tmp105;
  modelica_real tmp106;
  modelica_boolean tmp107;
  tmp64 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(0, 0, (-((tmp64?1.0:-0.0))), 0, linearSystemData, threadData);
  tmp65 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp67 = (modelica_boolean)tmp65;
  if(tmp67)
  {
    tmp68 = 0.0;
  }
  else
  {
    tmp66 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp68 = (tmp66?-0.0:1.0);
  }
  linearSystemData->setAElement(0, 1, (-(tmp68)), 1, linearSystemData, threadData);
  tmp69 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp71 = (modelica_boolean)tmp69;
  if(tmp71)
  {
    tmp72 = 0.0;
  }
  else
  {
    tmp70 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp72 = (tmp70?(-data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(0, 4, (-(tmp72)), 2, linearSystemData, threadData);
  tmp73 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp75 = (modelica_boolean)tmp73;
  if(tmp75)
  {
    tmp76 = 0.0;
  }
  else
  {
    tmp74 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp76 = (tmp74?(-data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(1, 2, (-(tmp76)), 3, linearSystemData, threadData);
  tmp77 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(1, 3, (-((tmp77?1.0:-0.0))), 4, linearSystemData, threadData);
  tmp78 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp80 = (modelica_boolean)tmp78;
  if(tmp80)
  {
    tmp81 = 0.0;
  }
  else
  {
    tmp79 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp81 = (tmp79?-0.0:1.0);
  }
  linearSystemData->setAElement(1, 4, (-(tmp81)), 5, linearSystemData, threadData);
  tmp82 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp84 = (modelica_boolean)tmp82;
  if(tmp84)
  {
    tmp85 = (-data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */);
  }
  else
  {
    tmp83 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp85 = (tmp83?-0.0:(-data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(2, 2, (-(tmp85)), 6, linearSystemData, threadData);
  tmp86 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp88 = (modelica_boolean)tmp86;
  if(tmp88)
  {
    tmp89 = -0.0;
  }
  else
  {
    tmp87 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp89 = (tmp87?(-data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(2, 3, (-(tmp89)), 7, linearSystemData, threadData);
  tmp90 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp92 = (modelica_boolean)tmp90;
  if(tmp92)
  {
    tmp93 = 0.0;
  }
  else
  {
    tmp91 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp93 = (tmp91?(-data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(3, 1, (-(tmp93)), 8, linearSystemData, threadData);
  tmp94 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp96 = (modelica_boolean)tmp94;
  if(tmp96)
  {
    tmp97 = -1.0;
  }
  else
  {
    tmp95 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp97 = (tmp95?-0.0:-1.0);
  }
  linearSystemData->setAElement(3, 2, (-(tmp97)), 9, linearSystemData, threadData);
  tmp98 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp100 = (modelica_boolean)tmp98;
  if(tmp100)
  {
    tmp101 = 0.0;
  }
  else
  {
    tmp99 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp101 = (tmp99?-0.0:1.0);
  }
  linearSystemData->setAElement(3, 3, (-(tmp101)), 10, linearSystemData, threadData);
  tmp102 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(3, 4, (-((tmp102?1.0:-0.0))), 11, linearSystemData, threadData);
  tmp103 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp105 = (modelica_boolean)tmp103;
  if(tmp105)
  {
    tmp106 = 0.0;
  }
  else
  {
    tmp104 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp106 = (tmp104?(-data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(4, 0, (-(tmp106)), 12, linearSystemData, threadData);
  tmp107 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(4, 1, (-((tmp107?1.0:-0.0))), 13, linearSystemData, threadData);
}
void setLinearVectorb463(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,463};
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
  tmp108 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp110 = (modelica_boolean)tmp108;
  if(tmp110)
  {
    tmp111 = 0.0;
  }
  else
  {
    tmp109 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp111 = (tmp109?data->localData[0]->realVars[36] /* MaterialStream1._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(0, tmp111, linearSystemData, threadData);
  tmp112 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp114 = (modelica_boolean)tmp112;
  if(tmp114)
  {
    tmp115 = 0.0;
  }
  else
  {
    tmp113 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp115 = (tmp113?data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(1, tmp115, linearSystemData, threadData);
  tmp116 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp118 = (modelica_boolean)tmp116;
  if(tmp118)
  {
    tmp119 = data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */;
  }
  else
  {
    tmp117 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp119 = (tmp117?data->localData[0]->realVars[38] /* MaterialStream1._Fm_pc[3,1] variable */:data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(2, tmp119, linearSystemData, threadData);
  tmp120 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp122 = (modelica_boolean)tmp120;
  if(tmp122)
  {
    tmp123 = 0.0;
  }
  else
  {
    tmp121 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp123 = (tmp121?data->localData[0]->realVars[37] /* MaterialStream1._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(3, tmp123, linearSystemData, threadData);
  tmp124 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp126 = (modelica_boolean)tmp124;
  if(tmp126)
  {
    tmp127 = (-data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */);
  }
  else
  {
    tmp125 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp127 = (tmp125?data->localData[0]->realVars[39] /* MaterialStream1._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(4, tmp127, linearSystemData, threadData);
}
void initializeStaticLSData463(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream1.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[97].attribute /* MaterialStream1._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[97].attribute /* MaterialStream1._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[97].attribute /* MaterialStream1._xm_pc[3,2] */.max;
  /* static ls data for MaterialStream1.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[95].attribute /* MaterialStream1._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[95].attribute /* MaterialStream1._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[95].attribute /* MaterialStream1._xm_pc[2,2] */.max;
  /* static ls data for MaterialStream1.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[1,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[96].attribute /* MaterialStream1._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[96].attribute /* MaterialStream1._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[96].attribute /* MaterialStream1._xm_pc[3,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[94].attribute /* MaterialStream1._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[94].attribute /* MaterialStream1._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[94].attribute /* MaterialStream1._xm_pc[2,1] */.max;
}
/* initial_lambda0 linear systems */
/* parameter linear systems */
/* model linear systems */
void setLinearMatrixA556(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,556};
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  modelica_boolean tmp128;
  modelica_boolean tmp129;
  modelica_boolean tmp130;
  modelica_real tmp131;
  modelica_boolean tmp132;
  modelica_boolean tmp133;
  modelica_boolean tmp134;
  modelica_real tmp135;
  modelica_boolean tmp136;
  modelica_boolean tmp137;
  modelica_boolean tmp138;
  modelica_real tmp139;
  modelica_boolean tmp140;
  modelica_boolean tmp141;
  modelica_boolean tmp142;
  modelica_boolean tmp143;
  modelica_real tmp144;
  modelica_boolean tmp145;
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
  modelica_real tmp166;
  modelica_boolean tmp167;
  modelica_boolean tmp168;
  modelica_boolean tmp169;
  modelica_real tmp170;
  modelica_boolean tmp171;
  tmp128 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp130 = (modelica_boolean)tmp128;
  if(tmp130)
  {
    tmp131 = -0.0;
  }
  else
  {
    tmp129 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp131 = (tmp129?(-data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(0, 3, (-(tmp131)), 0, linearSystemData, threadData);
  tmp132 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp134 = (modelica_boolean)tmp132;
  if(tmp134)
  {
    tmp135 = (-data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */);
  }
  else
  {
    tmp133 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp135 = (tmp133?-0.0:(-data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(0, 4, (-(tmp135)), 1, linearSystemData, threadData);
  tmp136 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp138 = (modelica_boolean)tmp136;
  if(tmp138)
  {
    tmp139 = 0.0;
  }
  else
  {
    tmp137 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp139 = (tmp137?-0.0:1.0);
  }
  linearSystemData->setAElement(1, 1, (-(tmp139)), 2, linearSystemData, threadData);
  tmp140 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(1, 3, (-((tmp140?1.0:-0.0))), 3, linearSystemData, threadData);
  tmp141 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp143 = (modelica_boolean)tmp141;
  if(tmp143)
  {
    tmp144 = 0.0;
  }
  else
  {
    tmp142 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp144 = (tmp142?(-data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(1, 4, (-(tmp144)), 4, linearSystemData, threadData);
  tmp145 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(2, 1, (-((tmp145?1.0:-0.0))), 5, linearSystemData, threadData);
  tmp146 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp148 = (modelica_boolean)tmp146;
  if(tmp148)
  {
    tmp149 = 0.0;
  }
  else
  {
    tmp147 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp149 = (tmp147?(-data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(2, 2, (-(tmp149)), 6, linearSystemData, threadData);
  tmp150 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp152 = (modelica_boolean)tmp150;
  if(tmp152)
  {
    tmp153 = 0.0;
  }
  else
  {
    tmp151 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp153 = (tmp151?-0.0:1.0);
  }
  linearSystemData->setAElement(2, 3, (-(tmp153)), 7, linearSystemData, threadData);
  tmp154 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp156 = (modelica_boolean)tmp154;
  if(tmp156)
  {
    tmp157 = -1.0;
  }
  else
  {
    tmp155 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp157 = (tmp155?-0.0:-1.0);
  }
  linearSystemData->setAElement(2, 4, (-(tmp157)), 8, linearSystemData, threadData);
  tmp158 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(3, 0, (-((tmp158?1.0:-0.0))), 9, linearSystemData, threadData);
  tmp159 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp161 = (modelica_boolean)tmp159;
  if(tmp161)
  {
    tmp162 = 0.0;
  }
  else
  {
    tmp160 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp162 = (tmp160?(-data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(3, 1, (-(tmp162)), 10, linearSystemData, threadData);
  tmp163 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp165 = (modelica_boolean)tmp163;
  if(tmp165)
  {
    tmp166 = 0.0;
  }
  else
  {
    tmp164 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp166 = (tmp164?-0.0:1.0);
  }
  linearSystemData->setAElement(3, 2, (-(tmp166)), 11, linearSystemData, threadData);
  tmp167 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp169 = (modelica_boolean)tmp167;
  if(tmp169)
  {
    tmp170 = 0.0;
  }
  else
  {
    tmp168 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp170 = (tmp168?(-data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(4, 0, (-(tmp170)), 12, linearSystemData, threadData);
  tmp171 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  linearSystemData->setAElement(4, 2, (-((tmp171?1.0:-0.0))), 13, linearSystemData, threadData);
}
void setLinearVectorb556(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,556};
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
  tmp172 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp174 = (modelica_boolean)tmp172;
  if(tmp174)
  {
    tmp175 = data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */;
  }
  else
  {
    tmp173 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp175 = (tmp173?data->localData[0]->realVars[38] /* MaterialStream1._Fm_pc[3,1] variable */:data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(0, tmp175, linearSystemData, threadData);
  tmp176 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp178 = (modelica_boolean)tmp176;
  if(tmp178)
  {
    tmp179 = 0.0;
  }
  else
  {
    tmp177 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp179 = (tmp177?data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(1, tmp179, linearSystemData, threadData);
  tmp180 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp182 = (modelica_boolean)tmp180;
  if(tmp182)
  {
    tmp183 = 0.0;
  }
  else
  {
    tmp181 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp183 = (tmp181?data->localData[0]->realVars[37] /* MaterialStream1._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(2, tmp183, linearSystemData, threadData);
  tmp184 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp186 = (modelica_boolean)tmp184;
  if(tmp186)
  {
    tmp187 = 0.0;
  }
  else
  {
    tmp185 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp187 = (tmp185?data->localData[0]->realVars[36] /* MaterialStream1._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(3, tmp187, linearSystemData, threadData);
  tmp188 = GreaterEq(101325.0,data->localData[0]->realVars[58] /* MaterialStream1._Pbubl variable */);
  tmp190 = (modelica_boolean)tmp188;
  if(tmp190)
  {
    tmp191 = (-data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */);
  }
  else
  {
    tmp189 = GreaterEq(101325.0,data->localData[0]->realVars[59] /* MaterialStream1._Pdew variable */);
    tmp191 = (tmp189?data->localData[0]->realVars[39] /* MaterialStream1._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(4, tmp191, linearSystemData, threadData);
}
void initializeStaticLSData556(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream1.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[97].attribute /* MaterialStream1._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[97].attribute /* MaterialStream1._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[97].attribute /* MaterialStream1._xm_pc[3,2] */.max;
  /* static ls data for MaterialStream1.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[94].attribute /* MaterialStream1._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[94].attribute /* MaterialStream1._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[94].attribute /* MaterialStream1._xm_pc[2,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[95].attribute /* MaterialStream1._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[95].attribute /* MaterialStream1._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[95].attribute /* MaterialStream1._xm_pc[2,2] */.max;
  /* static ls data for MaterialStream1.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[96].attribute /* MaterialStream1._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[96].attribute /* MaterialStream1._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[96].attribute /* MaterialStream1._xm_pc[3,1] */.max;
  /* static ls data for MaterialStream1.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[92].attribute /* MaterialStream1._xm_pc[1,1] */.max;
}

void setLinearMatrixA615(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,615};
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
  modelica_real tmp212;
  modelica_boolean tmp213;
  modelica_boolean tmp214;
  modelica_boolean tmp215;
  modelica_boolean tmp216;
  modelica_boolean tmp217;
  modelica_real tmp218;
  modelica_boolean tmp219;
  modelica_boolean tmp220;
  modelica_boolean tmp221;
  modelica_real tmp222;
  modelica_boolean tmp223;
  modelica_boolean tmp224;
  modelica_boolean tmp225;
  modelica_real tmp226;
  modelica_boolean tmp227;
  modelica_boolean tmp228;
  modelica_boolean tmp229;
  modelica_boolean tmp230;
  modelica_real tmp231;
  modelica_boolean tmp232;
  modelica_boolean tmp233;
  modelica_boolean tmp234;
  modelica_real tmp235;
  tmp192 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp194 = (modelica_boolean)tmp192;
  if(tmp194)
  {
    tmp195 = -1.0;
  }
  else
  {
    tmp193 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp195 = (tmp193?-0.0:-1.0);
  }
  linearSystemData->setAElement(0, 0, (-(tmp195)), 0, linearSystemData, threadData);
  tmp196 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp198 = (modelica_boolean)tmp196;
  if(tmp198)
  {
    tmp199 = 0.0;
  }
  else
  {
    tmp197 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp199 = (tmp197?(-data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(0, 2, (-(tmp199)), 1, linearSystemData, threadData);
  tmp200 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(0, 3, (-((tmp200?1.0:-0.0))), 2, linearSystemData, threadData);
  tmp201 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp203 = (modelica_boolean)tmp201;
  if(tmp203)
  {
    tmp204 = 0.0;
  }
  else
  {
    tmp202 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp204 = (tmp202?-0.0:1.0);
  }
  linearSystemData->setAElement(0, 4, (-(tmp204)), 3, linearSystemData, threadData);
  tmp205 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp207 = (modelica_boolean)tmp205;
  if(tmp207)
  {
    tmp208 = 0.0;
  }
  else
  {
    tmp206 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp208 = (tmp206?(-data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */):0.0);
  }
  linearSystemData->setAElement(1, 0, (-(tmp208)), 4, linearSystemData, threadData);
  tmp209 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp211 = (modelica_boolean)tmp209;
  if(tmp211)
  {
    tmp212 = 0.0;
  }
  else
  {
    tmp210 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp212 = (tmp210?-0.0:1.0);
  }
  linearSystemData->setAElement(1, 3, (-(tmp212)), 5, linearSystemData, threadData);
  tmp213 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(1, 4, (-((tmp213?1.0:-0.0))), 6, linearSystemData, threadData);
  tmp214 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(2, 1, (-((tmp214?1.0:-0.0))), 7, linearSystemData, threadData);
  tmp215 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp217 = (modelica_boolean)tmp215;
  if(tmp217)
  {
    tmp218 = 0.0;
  }
  else
  {
    tmp216 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp218 = (tmp216?-0.0:1.0);
  }
  linearSystemData->setAElement(2, 2, (-(tmp218)), 8, linearSystemData, threadData);
  tmp219 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp221 = (modelica_boolean)tmp219;
  if(tmp221)
  {
    tmp222 = 0.0;
  }
  else
  {
    tmp220 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp222 = (tmp220?(-data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */):0.0);
  }
  linearSystemData->setAElement(2, 3, (-(tmp222)), 9, linearSystemData, threadData);
  tmp223 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp225 = (modelica_boolean)tmp223;
  if(tmp225)
  {
    tmp226 = 0.0;
  }
  else
  {
    tmp224 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp226 = (tmp224?(-data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */):1.0);
  }
  linearSystemData->setAElement(3, 1, (-(tmp226)), 10, linearSystemData, threadData);
  tmp227 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  linearSystemData->setAElement(3, 2, (-((tmp227?1.0:-0.0))), 11, linearSystemData, threadData);
  tmp228 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp230 = (modelica_boolean)tmp228;
  if(tmp230)
  {
    tmp231 = (-data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */);
  }
  else
  {
    tmp229 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp231 = (tmp229?-0.0:(-data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */));
  }
  linearSystemData->setAElement(4, 0, (-(tmp231)), 12, linearSystemData, threadData);
  tmp232 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
  tmp234 = (modelica_boolean)tmp232;
  if(tmp234)
  {
    tmp235 = -0.0;
  }
  else
  {
    tmp233 = GreaterEq(data->localData[0]->realVars[4] /* Heater1._Pout variable */,data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
    tmp235 = (tmp233?(-data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */):-0.0);
  }
  linearSystemData->setAElement(4, 4, (-(tmp235)), 13, linearSystemData, threadData);
}
void setLinearVectorb615(void *inData, threadData_t *threadData, void *systemData)
{
  const int equationIndexes[2] = {1,615};
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
  RELATIONHYSTERESIS(tmp236, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp238 = (modelica_boolean)tmp236;
  if(tmp238)
  {
    tmp239 = 0.0;
  }
  else
  {
    RELATIONHYSTERESIS(tmp237, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp239 = (tmp237?data->localData[0]->realVars[126] /* MaterialStream2._Fm_pc[2,2] variable */:0.0);
  }
  linearSystemData->setBElement(0, tmp239, linearSystemData, threadData);
  RELATIONHYSTERESIS(tmp240, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp242 = (modelica_boolean)tmp240;
  if(tmp242)
  {
    tmp243 = 0.0;
  }
  else
  {
    RELATIONHYSTERESIS(tmp241, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp243 = (tmp241?data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */:0.0);
  }
  linearSystemData->setBElement(1, tmp243, linearSystemData, threadData);
  RELATIONHYSTERESIS(tmp244, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp246 = (modelica_boolean)tmp244;
  if(tmp246)
  {
    tmp247 = 0.0;
  }
  else
  {
    RELATIONHYSTERESIS(tmp245, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp247 = (tmp245?data->localData[0]->realVars[125] /* MaterialStream2._Fm_pc[2,1] variable */:0.0);
  }
  linearSystemData->setBElement(2, tmp247, linearSystemData, threadData);
  RELATIONHYSTERESIS(tmp248, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp250 = (modelica_boolean)tmp248;
  if(tmp250)
  {
    tmp251 = (-data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */);
  }
  else
  {
    RELATIONHYSTERESIS(tmp249, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp251 = (tmp249?data->localData[0]->realVars[128] /* MaterialStream2._Fm_pc[3,2] variable */:(-data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */));
  }
  linearSystemData->setBElement(3, tmp251, linearSystemData, threadData);
  RELATIONHYSTERESIS(tmp252, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, 0, GreaterEq);
  tmp254 = (modelica_boolean)tmp252;
  if(tmp254)
  {
    tmp255 = data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */;
  }
  else
  {
    RELATIONHYSTERESIS(tmp253, data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, 1, GreaterEq);
    tmp255 = (tmp253?data->localData[0]->realVars[127] /* MaterialStream2._Fm_pc[3,1] variable */:data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */);
  }
  linearSystemData->setBElement(4, tmp255, linearSystemData, threadData);
}
void initializeStaticLSData615(void *inData, threadData_t *threadData, void *systemData)
{
  DATA* data = (DATA*) inData;
  LINEAR_SYSTEM_DATA* linearSystemData = (LINEAR_SYSTEM_DATA*) systemData;
  int i=0;
  /* static ls data for MaterialStream2.xm_pc[1,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[1,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[1,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[179].attribute /* MaterialStream2._xm_pc[1,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[3,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[184].attribute /* MaterialStream2._xm_pc[3,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[184].attribute /* MaterialStream2._xm_pc[3,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[184].attribute /* MaterialStream2._xm_pc[3,2] */.max;
  /* static ls data for MaterialStream2.xm_pc[2,2] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[2,2] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[2,2] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[182].attribute /* MaterialStream2._xm_pc[2,2] */.max;
  /* static ls data for MaterialStream2.xm_pc[2,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[2,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[2,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[181].attribute /* MaterialStream2._xm_pc[2,1] */.max;
  /* static ls data for MaterialStream2.xm_pc[3,1] */
  linearSystemData->nominal[i] = data->modelData->realVarsData[183].attribute /* MaterialStream2._xm_pc[3,1] */.nominal;
  linearSystemData->min[i]     = data->modelData->realVarsData[183].attribute /* MaterialStream2._xm_pc[3,1] */.min;
  linearSystemData->max[i++]   = data->modelData->realVarsData[183].attribute /* MaterialStream2._xm_pc[3,1] */.max;
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
  linearSystemData[0].equationIndex = 96;
  linearSystemData[0].size = 1;
  linearSystemData[0].nnz = 0;
  linearSystemData[0].method = 1;
  linearSystemData[0].residualFunc = residualFunc96;
  linearSystemData[0].strictTearingFunctionCall = NULL;
  linearSystemData[0].analyticalJacobianColumn = Flowsheet_functionJacLSJac2_column;
  linearSystemData[0].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianLSJac2;
  linearSystemData[0].jacobianIndex = 0;
  linearSystemData[0].setA = NULL;//setLinearMatrixA96;
  linearSystemData[0].setb = NULL; //setLinearVectorb96;
  linearSystemData[0].initializeStaticLSData = initializeStaticLSData96;
  
  assertStreamPrint(NULL, nLinearSystems > 1, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[1].equationIndex = 190;
  linearSystemData[1].size = 1;
  linearSystemData[1].nnz = 0;
  linearSystemData[1].method = 1;
  linearSystemData[1].residualFunc = residualFunc190;
  linearSystemData[1].strictTearingFunctionCall = NULL;
  linearSystemData[1].analyticalJacobianColumn = Flowsheet_functionJacLSJac5_column;
  linearSystemData[1].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianLSJac5;
  linearSystemData[1].jacobianIndex = 1;
  linearSystemData[1].setA = NULL;//setLinearMatrixA190;
  linearSystemData[1].setb = NULL; //setLinearVectorb190;
  linearSystemData[1].initializeStaticLSData = initializeStaticLSData190;
  
  assertStreamPrint(NULL, nLinearSystems > 2, "Internal Error: indexlinearSystem mismatch!");
  linearSystemData[2].equationIndex = 298;
  linearSystemData[2].size = 1;
  linearSystemData[2].nnz = 0;
  linearSystemData[2].method = 1;
  linearSystemData[2].residualFunc = residualFunc298;
  linearSystemData[2].strictTearingFunctionCall = NULL;
  linearSystemData[2].analyticalJacobianColumn = Flowsheet_functionJacLSJac8_column;
  linearSystemData[2].initialAnalyticalJacobian = Flowsheet_initialAnalyticJacobianLSJac8;
  linearSystemData[2].jacobianIndex = 2;
  linearSystemData[2].setA = NULL;//setLinearMatrixA298;
  linearSystemData[2].setb = NULL; //setLinearVectorb298;
  linearSystemData[2].initializeStaticLSData = initializeStaticLSData298;
  
  assertStreamPrint(NULL, nLinearSystems > 3, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[3].equationIndex = 408;
  linearSystemData[3].size = 5;
  linearSystemData[3].nnz = 14;
  linearSystemData[3].method = 0;
  linearSystemData[3].strictTearingFunctionCall = NULL;
  linearSystemData[3].setA = setLinearMatrixA408;
  linearSystemData[3].setb = setLinearVectorb408;
  linearSystemData[3].initializeStaticLSData = initializeStaticLSData408;
  
  assertStreamPrint(NULL, nLinearSystems > 4, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[4].equationIndex = 463;
  linearSystemData[4].size = 5;
  linearSystemData[4].nnz = 14;
  linearSystemData[4].method = 0;
  linearSystemData[4].strictTearingFunctionCall = NULL;
  linearSystemData[4].setA = setLinearMatrixA463;
  linearSystemData[4].setb = setLinearVectorb463;
  linearSystemData[4].initializeStaticLSData = initializeStaticLSData463;
  /* initial_lambda0 linear systems */
  /* parameter linear systems */
  /* model linear systems */
  assertStreamPrint(NULL, nLinearSystems > 5, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[5].equationIndex = 556;
  linearSystemData[5].size = 5;
  linearSystemData[5].nnz = 14;
  linearSystemData[5].method = 0;
  linearSystemData[5].strictTearingFunctionCall = NULL;
  linearSystemData[5].setA = setLinearMatrixA556;
  linearSystemData[5].setb = setLinearVectorb556;
  linearSystemData[5].initializeStaticLSData = initializeStaticLSData556;
  
  assertStreamPrint(NULL, nLinearSystems > 6, "Internal Error: nLinearSystems mismatch!");
  linearSystemData[6].equationIndex = 615;
  linearSystemData[6].size = 5;
  linearSystemData[6].nnz = 14;
  linearSystemData[6].method = 0;
  linearSystemData[6].strictTearingFunctionCall = NULL;
  linearSystemData[6].setA = setLinearMatrixA615;
  linearSystemData[6].setb = setLinearVectorb615;
  linearSystemData[6].initializeStaticLSData = initializeStaticLSData615;
  /* inline linear systems */
  /* jacobians linear systems */
}

#if defined(__cplusplus)
}
#endif

