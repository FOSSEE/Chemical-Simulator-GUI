/* Asserts */
#include "Flowsheet_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
 equation index: 1390
 type: ALGORITHM
 
   assert(MaterialStream1.xliq >= 0.0 and MaterialStream1.xliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xliq <= 1.0, has value: " + String(MaterialStream1.xliq, "g"));
 */
void Flowsheet_eqFunction_1390(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1390};
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  static const MMC_DEFSTRINGLIT(tmp27,86,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xliq <= 1.0, has value: ");
  modelica_string tmp28;
  static int tmp29 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp29)
  {
    tmp25 = GreaterEq(data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */,0.0);
    tmp26 = LessEq(data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */,1.0);
    if(!(tmp25 && tmp26))
    {
      tmp28 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[91] /* MaterialStream1._xliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp27),tmp28);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",14,3,14,86,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xliq >= 0.0 and MaterialStream1.xliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp29 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1391
 type: ALGORITHM
 
   assert(MaterialStream1.xmliq >= 0.0 and MaterialStream1.xmliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xmliq <= 1.0, has value: " + String(MaterialStream1.xmliq, "g"));
 */
void Flowsheet_eqFunction_1391(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1391};
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,87,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xmliq <= 1.0, has value: ");
  modelica_string tmp33;
  static int tmp34 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp34)
  {
    tmp30 = GreaterEq(data->localData[0]->realVars[98] /* MaterialStream1._xmliq variable */,0.0);
    tmp31 = LessEq(data->localData[0]->realVars[98] /* MaterialStream1._xmliq variable */,1.0);
    if(!(tmp30 && tmp31))
    {
      tmp33 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[98] /* MaterialStream1._xmliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp32),tmp33);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",16,3,16,87,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xmliq >= 0.0 and MaterialStream1.xmliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp34 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1392
 type: ALGORITHM
 
   assert(MaterialStream1.xmvap >= 0.0 and MaterialStream1.xmvap <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xmvap <= 1.0, has value: " + String(MaterialStream1.xmvap, "g"));
 */
void Flowsheet_eqFunction_1392(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1392};
  modelica_boolean tmp35;
  modelica_boolean tmp36;
  static const MMC_DEFSTRINGLIT(tmp37,87,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xmvap <= 1.0, has value: ");
  modelica_string tmp38;
  static int tmp39 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp39)
  {
    tmp35 = GreaterEq(data->localData[0]->realVars[99] /* MaterialStream1._xmvap variable */,0.0);
    tmp36 = LessEq(data->localData[0]->realVars[99] /* MaterialStream1._xmvap variable */,1.0);
    if(!(tmp35 && tmp36))
    {
      tmp38 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[99] /* MaterialStream1._xmvap variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp37),tmp38);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",17,3,17,84,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xmvap >= 0.0 and MaterialStream1.xmvap <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp39 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1393
 type: ALGORITHM
 
   assert(MaterialStream1.F_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_p[2], has value: " + String(MaterialStream1.F_p[2], "g"));
 */
void Flowsheet_eqFunction_1393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1393};
  modelica_boolean tmp40;
  static const MMC_DEFSTRINGLIT(tmp41,77,"Variable violating min constraint: 0.0 <= MaterialStream1.F_p[2], has value: ");
  modelica_string tmp42;
  static int tmp43 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp43)
  {
    tmp40 = GreaterEq(data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */,0.0);
    if(!tmp40)
    {
      tmp42 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[23] /* MaterialStream1._F_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp41),tmp42);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp43 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1394
 type: ALGORITHM
 
   assert(MaterialStream1.F_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_p[3], has value: " + String(MaterialStream1.F_p[3], "g"));
 */
void Flowsheet_eqFunction_1394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1394};
  modelica_boolean tmp44;
  static const MMC_DEFSTRINGLIT(tmp45,77,"Variable violating min constraint: 0.0 <= MaterialStream1.F_p[3], has value: ");
  modelica_string tmp46;
  static int tmp47 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp47)
  {
    tmp44 = GreaterEq(data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */,0.0);
    if(!tmp44)
    {
      tmp46 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[24] /* MaterialStream1._F_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp45),tmp46);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp47 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1395
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[1], has value: " + String(MaterialStream1.Fm_p[1], "g"));
 */
void Flowsheet_eqFunction_1395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1395};
  modelica_boolean tmp48;
  static const MMC_DEFSTRINGLIT(tmp49,78,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[1], has value: ");
  modelica_string tmp50;
  static int tmp51 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp51)
  {
    tmp48 = GreaterEq(data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */,0.0);
    if(!tmp48)
    {
      tmp50 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[31] /* MaterialStream1._Fm_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp49),tmp50);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp51 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1396
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[2], has value: " + String(MaterialStream1.Fm_p[2], "g"));
 */
void Flowsheet_eqFunction_1396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1396};
  modelica_boolean tmp52;
  static const MMC_DEFSTRINGLIT(tmp53,78,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[2], has value: ");
  modelica_string tmp54;
  static int tmp55 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp55)
  {
    tmp52 = GreaterEq(data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */,0.0);
    if(!tmp52)
    {
      tmp54 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[32] /* MaterialStream1._Fm_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp53),tmp54);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp55 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1397
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[3], has value: " + String(MaterialStream1.Fm_p[3], "g"));
 */
void Flowsheet_eqFunction_1397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1397};
  modelica_boolean tmp56;
  static const MMC_DEFSTRINGLIT(tmp57,78,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[3], has value: ");
  modelica_string tmp58;
  static int tmp59 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp59)
  {
    tmp56 = GreaterEq(data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */,0.0);
    if(!tmp56)
    {
      tmp58 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[33] /* MaterialStream1._Fm_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp57),tmp58);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp59 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1398
 type: ALGORITHM
 
   assert(MaterialStream1.MW_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[1], has value: " + String(MaterialStream1.MW_p[1], "g"));
 */
void Flowsheet_eqFunction_1398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1398};
  modelica_boolean tmp60;
  static const MMC_DEFSTRINGLIT(tmp61,78,"Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[1], has value: ");
  modelica_string tmp62;
  static int tmp63 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp63)
  {
    tmp60 = GreaterEq(data->localData[0]->realVars[54] /* MaterialStream1._MW_p[1] variable */,0.0);
    if(!tmp60)
    {
      tmp62 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[54] /* MaterialStream1._MW_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp61),tmp62);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.MW_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp63 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1399
 type: ALGORITHM
 
   assert(MaterialStream1.MW_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[2], has value: " + String(MaterialStream1.MW_p[2], "g"));
 */
void Flowsheet_eqFunction_1399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1399};
  modelica_boolean tmp64;
  static const MMC_DEFSTRINGLIT(tmp65,78,"Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[2], has value: ");
  modelica_string tmp66;
  static int tmp67 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp67)
  {
    tmp64 = GreaterEq(data->localData[0]->realVars[55] /* MaterialStream1._MW_p[2] variable */,0.0);
    if(!tmp64)
    {
      tmp66 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[55] /* MaterialStream1._MW_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp65),tmp66);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.MW_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp67 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1400
 type: ALGORITHM
 
   assert(MaterialStream1.MW_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[3], has value: " + String(MaterialStream1.MW_p[3], "g"));
 */
void Flowsheet_eqFunction_1400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1400};
  modelica_boolean tmp68;
  static const MMC_DEFSTRINGLIT(tmp69,78,"Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[3], has value: ");
  modelica_string tmp70;
  static int tmp71 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp71)
  {
    tmp68 = GreaterEq(data->localData[0]->realVars[56] /* MaterialStream1._MW_p[3] variable */,0.0);
    if(!tmp68)
    {
      tmp70 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[56] /* MaterialStream1._MW_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp69),tmp70);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.MW_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp71 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1401
 type: ALGORITHM
 
   assert(MaterialStream1.x_pc[2,1] >= 0.0 and MaterialStream1.x_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[2,1] <= 1.0, has value: " + String(MaterialStream1.x_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1401};
  modelica_boolean tmp72;
  modelica_boolean tmp73;
  static const MMC_DEFSTRINGLIT(tmp74,91,"Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp75;
  static int tmp76 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp76)
  {
    tmp72 = GreaterEq(data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */,0.0);
    tmp73 = LessEq(data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */,1.0);
    if(!(tmp72 && tmp73))
    {
      tmp75 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[87] /* MaterialStream1._x_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp74),tmp75);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.x_pc[2,1] >= 0.0 and MaterialStream1.x_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp76 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1402
 type: ALGORITHM
 
   assert(MaterialStream1.x_pc[2,2] >= 0.0 and MaterialStream1.x_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[2,2] <= 1.0, has value: " + String(MaterialStream1.x_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1402};
  modelica_boolean tmp77;
  modelica_boolean tmp78;
  static const MMC_DEFSTRINGLIT(tmp79,91,"Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp80;
  static int tmp81 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp81)
  {
    tmp77 = GreaterEq(data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */,0.0);
    tmp78 = LessEq(data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */,1.0);
    if(!(tmp77 && tmp78))
    {
      tmp80 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[88] /* MaterialStream1._x_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp79),tmp80);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.x_pc[2,2] >= 0.0 and MaterialStream1.x_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp81 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1403
 type: ALGORITHM
 
   assert(MaterialStream1.x_pc[3,1] >= 0.0 and MaterialStream1.x_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[3,1] <= 1.0, has value: " + String(MaterialStream1.x_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1403(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1403};
  modelica_boolean tmp82;
  modelica_boolean tmp83;
  static const MMC_DEFSTRINGLIT(tmp84,91,"Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp85;
  static int tmp86 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp86)
  {
    tmp82 = GreaterEq(data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */,0.0);
    tmp83 = LessEq(data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */,1.0);
    if(!(tmp82 && tmp83))
    {
      tmp85 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[89] /* MaterialStream1._x_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp84),tmp85);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.x_pc[3,1] >= 0.0 and MaterialStream1.x_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp86 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1404
 type: ALGORITHM
 
   assert(MaterialStream1.x_pc[3,2] >= 0.0 and MaterialStream1.x_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[3,2] <= 1.0, has value: " + String(MaterialStream1.x_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1404};
  modelica_boolean tmp87;
  modelica_boolean tmp88;
  static const MMC_DEFSTRINGLIT(tmp89,91,"Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp90;
  static int tmp91 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp91)
  {
    tmp87 = GreaterEq(data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */,0.0);
    tmp88 = LessEq(data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */,1.0);
    if(!(tmp87 && tmp88))
    {
      tmp90 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[90] /* MaterialStream1._x_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp89),tmp90);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.x_pc[3,2] >= 0.0 and MaterialStream1.x_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp91 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1405
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[1,1] >= 0.0 and MaterialStream1.xm_pc[1,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[1,1] <= 1.0, has value: " + String(MaterialStream1.xm_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1405(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1405};
  modelica_boolean tmp92;
  modelica_boolean tmp93;
  static const MMC_DEFSTRINGLIT(tmp94,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[1,1] <= 1.0, has value: ");
  modelica_string tmp95;
  static int tmp96 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp96)
  {
    tmp92 = GreaterEq(data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[1,1] variable */,0.0);
    tmp93 = LessEq(data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[1,1] variable */,1.0);
    if(!(tmp92 && tmp93))
    {
      tmp95 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp94),tmp95);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[1,1] >= 0.0 and MaterialStream1.xm_pc[1,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp96 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1406
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[1,2] >= 0.0 and MaterialStream1.xm_pc[1,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[1,2] <= 1.0, has value: " + String(MaterialStream1.xm_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1406};
  modelica_boolean tmp97;
  modelica_boolean tmp98;
  static const MMC_DEFSTRINGLIT(tmp99,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[1,2] <= 1.0, has value: ");
  modelica_string tmp100;
  static int tmp101 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp101)
  {
    tmp97 = GreaterEq(data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */,0.0);
    tmp98 = LessEq(data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */,1.0);
    if(!(tmp97 && tmp98))
    {
      tmp100 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[93] /* MaterialStream1._xm_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp99),tmp100);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[1,2] >= 0.0 and MaterialStream1.xm_pc[1,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp101 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1407
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[2,1] >= 0.0 and MaterialStream1.xm_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[2,1] <= 1.0, has value: " + String(MaterialStream1.xm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1407(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1407};
  modelica_boolean tmp102;
  modelica_boolean tmp103;
  static const MMC_DEFSTRINGLIT(tmp104,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp105;
  static int tmp106 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp106)
  {
    tmp102 = GreaterEq(data->localData[0]->realVars[94] /* MaterialStream1._xm_pc[2,1] variable */,0.0);
    tmp103 = LessEq(data->localData[0]->realVars[94] /* MaterialStream1._xm_pc[2,1] variable */,1.0);
    if(!(tmp102 && tmp103))
    {
      tmp105 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[94] /* MaterialStream1._xm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp104),tmp105);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[2,1] >= 0.0 and MaterialStream1.xm_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp106 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1408
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[2,2] >= 0.0 and MaterialStream1.xm_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[2,2] <= 1.0, has value: " + String(MaterialStream1.xm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1408(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1408};
  modelica_boolean tmp107;
  modelica_boolean tmp108;
  static const MMC_DEFSTRINGLIT(tmp109,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp110;
  static int tmp111 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp111)
  {
    tmp107 = GreaterEq(data->localData[0]->realVars[95] /* MaterialStream1._xm_pc[2,2] variable */,0.0);
    tmp108 = LessEq(data->localData[0]->realVars[95] /* MaterialStream1._xm_pc[2,2] variable */,1.0);
    if(!(tmp107 && tmp108))
    {
      tmp110 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[95] /* MaterialStream1._xm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp109),tmp110);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[2,2] >= 0.0 and MaterialStream1.xm_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp111 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1409
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[3,1] >= 0.0 and MaterialStream1.xm_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[3,1] <= 1.0, has value: " + String(MaterialStream1.xm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1409(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1409};
  modelica_boolean tmp112;
  modelica_boolean tmp113;
  static const MMC_DEFSTRINGLIT(tmp114,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp115;
  static int tmp116 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp116)
  {
    tmp112 = GreaterEq(data->localData[0]->realVars[96] /* MaterialStream1._xm_pc[3,1] variable */,0.0);
    tmp113 = LessEq(data->localData[0]->realVars[96] /* MaterialStream1._xm_pc[3,1] variable */,1.0);
    if(!(tmp112 && tmp113))
    {
      tmp115 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[96] /* MaterialStream1._xm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp114),tmp115);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[3,1] >= 0.0 and MaterialStream1.xm_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp116 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1410
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[3,2] >= 0.0 and MaterialStream1.xm_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[3,2] <= 1.0, has value: " + String(MaterialStream1.xm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1410(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1410};
  modelica_boolean tmp117;
  modelica_boolean tmp118;
  static const MMC_DEFSTRINGLIT(tmp119,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp120;
  static int tmp121 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp121)
  {
    tmp117 = GreaterEq(data->localData[0]->realVars[97] /* MaterialStream1._xm_pc[3,2] variable */,0.0);
    tmp118 = LessEq(data->localData[0]->realVars[97] /* MaterialStream1._xm_pc[3,2] variable */,1.0);
    if(!(tmp117 && tmp118))
    {
      tmp120 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[97] /* MaterialStream1._xm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp119),tmp120);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[3,2] >= 0.0 and MaterialStream1.xm_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp121 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1411
 type: ALGORITHM
 
   assert(MaterialStream1.F_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[2,1], has value: " + String(MaterialStream1.F_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1411(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1411};
  modelica_boolean tmp122;
  static const MMC_DEFSTRINGLIT(tmp123,80,"Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[2,1], has value: ");
  modelica_string tmp124;
  static int tmp125 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp125)
  {
    tmp122 = GreaterEq(data->localData[0]->realVars[27] /* MaterialStream1._F_pc[2,1] variable */,0.0);
    if(!tmp122)
    {
      tmp124 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[27] /* MaterialStream1._F_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp123),tmp124);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp125 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1412
 type: ALGORITHM
 
   assert(MaterialStream1.F_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[2,2], has value: " + String(MaterialStream1.F_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1412(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1412};
  modelica_boolean tmp126;
  static const MMC_DEFSTRINGLIT(tmp127,80,"Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[2,2], has value: ");
  modelica_string tmp128;
  static int tmp129 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp129)
  {
    tmp126 = GreaterEq(data->localData[0]->realVars[28] /* MaterialStream1._F_pc[2,2] variable */,0.0);
    if(!tmp126)
    {
      tmp128 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[28] /* MaterialStream1._F_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp127),tmp128);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp129 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1413
 type: ALGORITHM
 
   assert(MaterialStream1.F_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[3,1], has value: " + String(MaterialStream1.F_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1413(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1413};
  modelica_boolean tmp130;
  static const MMC_DEFSTRINGLIT(tmp131,80,"Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[3,1], has value: ");
  modelica_string tmp132;
  static int tmp133 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp133)
  {
    tmp130 = GreaterEq(data->localData[0]->realVars[29] /* MaterialStream1._F_pc[3,1] variable */,0.0);
    if(!tmp130)
    {
      tmp132 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[29] /* MaterialStream1._F_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp131),tmp132);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp133 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1414
 type: ALGORITHM
 
   assert(MaterialStream1.F_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[3,2], has value: " + String(MaterialStream1.F_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1414(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1414};
  modelica_boolean tmp134;
  static const MMC_DEFSTRINGLIT(tmp135,80,"Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[3,2], has value: ");
  modelica_string tmp136;
  static int tmp137 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp137)
  {
    tmp134 = GreaterEq(data->localData[0]->realVars[30] /* MaterialStream1._F_pc[3,2] variable */,0.0);
    if(!tmp134)
    {
      tmp136 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[30] /* MaterialStream1._F_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp135),tmp136);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp137 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1415
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[2,1], has value: " + String(MaterialStream1.Fm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1415(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1415};
  modelica_boolean tmp138;
  static const MMC_DEFSTRINGLIT(tmp139,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[2,1], has value: ");
  modelica_string tmp140;
  static int tmp141 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp141)
  {
    tmp138 = GreaterEq(data->localData[0]->realVars[36] /* MaterialStream1._Fm_pc[2,1] variable */,0.0);
    if(!tmp138)
    {
      tmp140 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[36] /* MaterialStream1._Fm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp139),tmp140);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp141 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1416
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[2,2], has value: " + String(MaterialStream1.Fm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1416(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1416};
  modelica_boolean tmp142;
  static const MMC_DEFSTRINGLIT(tmp143,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[2,2], has value: ");
  modelica_string tmp144;
  static int tmp145 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp145)
  {
    tmp142 = GreaterEq(data->localData[0]->realVars[37] /* MaterialStream1._Fm_pc[2,2] variable */,0.0);
    if(!tmp142)
    {
      tmp144 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[37] /* MaterialStream1._Fm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp143),tmp144);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp145 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1417
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[3,1], has value: " + String(MaterialStream1.Fm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1417(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1417};
  modelica_boolean tmp146;
  static const MMC_DEFSTRINGLIT(tmp147,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[3,1], has value: ");
  modelica_string tmp148;
  static int tmp149 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp149)
  {
    tmp146 = GreaterEq(data->localData[0]->realVars[38] /* MaterialStream1._Fm_pc[3,1] variable */,0.0);
    if(!tmp146)
    {
      tmp148 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[38] /* MaterialStream1._Fm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp147),tmp148);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp149 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1418
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[3,2], has value: " + String(MaterialStream1.Fm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1418(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1418};
  modelica_boolean tmp150;
  static const MMC_DEFSTRINGLIT(tmp151,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[3,2], has value: ");
  modelica_string tmp152;
  static int tmp153 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp153)
  {
    tmp150 = GreaterEq(data->localData[0]->realVars[39] /* MaterialStream1._Fm_pc[3,2] variable */,0.0);
    if(!tmp150)
    {
      tmp152 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[39] /* MaterialStream1._Fm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp151),tmp152);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp153 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1419
 type: ALGORITHM
 
   assert(MaterialStream2.Pbubl >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Pbubl, has value: " + String(MaterialStream2.Pbubl, "g"));
 */
void Flowsheet_eqFunction_1419(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1419};
  modelica_boolean tmp154;
  static const MMC_DEFSTRINGLIT(tmp155,76,"Variable violating min constraint: 0.0 <= MaterialStream2.Pbubl, has value: ");
  modelica_string tmp156;
  static int tmp157 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp157)
  {
    tmp154 = GreaterEq(data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */,0.0);
    if(!tmp154)
    {
      tmp156 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp155),tmp156);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",12,3,12,73,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Pbubl >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp157 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1420
 type: ALGORITHM
 
   assert(MaterialStream2.Pdew >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Pdew, has value: " + String(MaterialStream2.Pdew, "g"));
 */
void Flowsheet_eqFunction_1420(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1420};
  modelica_boolean tmp158;
  static const MMC_DEFSTRINGLIT(tmp159,75,"Variable violating min constraint: 0.0 <= MaterialStream2.Pdew, has value: ");
  modelica_string tmp160;
  static int tmp161 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp161)
  {
    tmp158 = GreaterEq(data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */,0.0);
    if(!tmp158)
    {
      tmp160 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp159),tmp160);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",13,3,13,69,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Pdew >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp161 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1421
 type: ALGORITHM
 
   assert(MaterialStream2.xliq >= 0.0 and MaterialStream2.xliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xliq <= 1.0, has value: " + String(MaterialStream2.xliq, "g"));
 */
void Flowsheet_eqFunction_1421(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1421};
  modelica_boolean tmp162;
  modelica_boolean tmp163;
  static const MMC_DEFSTRINGLIT(tmp164,86,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xliq <= 1.0, has value: ");
  modelica_string tmp165;
  static int tmp166 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp166)
  {
    tmp162 = GreaterEq(data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */,0.0);
    tmp163 = LessEq(data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */,1.0);
    if(!(tmp162 && tmp163))
    {
      tmp165 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[178] /* MaterialStream2._xliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp164),tmp165);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",14,3,14,86,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xliq >= 0.0 and MaterialStream2.xliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp166 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1422
 type: ALGORITHM
 
   assert(MaterialStream2.xmliq >= 0.0 and MaterialStream2.xmliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xmliq <= 1.0, has value: " + String(MaterialStream2.xmliq, "g"));
 */
void Flowsheet_eqFunction_1422(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1422};
  modelica_boolean tmp167;
  modelica_boolean tmp168;
  static const MMC_DEFSTRINGLIT(tmp169,87,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xmliq <= 1.0, has value: ");
  modelica_string tmp170;
  static int tmp171 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp171)
  {
    tmp167 = GreaterEq(data->localData[0]->realVars[185] /* MaterialStream2._xmliq variable */,0.0);
    tmp168 = LessEq(data->localData[0]->realVars[185] /* MaterialStream2._xmliq variable */,1.0);
    if(!(tmp167 && tmp168))
    {
      tmp170 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[185] /* MaterialStream2._xmliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp169),tmp170);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",16,3,16,87,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xmliq >= 0.0 and MaterialStream2.xmliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp171 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1423
 type: ALGORITHM
 
   assert(MaterialStream2.xmvap >= 0.0 and MaterialStream2.xmvap <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xmvap <= 1.0, has value: " + String(MaterialStream2.xmvap, "g"));
 */
void Flowsheet_eqFunction_1423(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1423};
  modelica_boolean tmp172;
  modelica_boolean tmp173;
  static const MMC_DEFSTRINGLIT(tmp174,87,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xmvap <= 1.0, has value: ");
  modelica_string tmp175;
  static int tmp176 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp176)
  {
    tmp172 = GreaterEq(data->localData[0]->realVars[186] /* MaterialStream2._xmvap variable */,0.0);
    tmp173 = LessEq(data->localData[0]->realVars[186] /* MaterialStream2._xmvap variable */,1.0);
    if(!(tmp172 && tmp173))
    {
      tmp175 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[186] /* MaterialStream2._xmvap variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp174),tmp175);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",17,3,17,84,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xmvap >= 0.0 and MaterialStream2.xmvap <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp176 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1424
 type: ALGORITHM
 
   assert(MaterialStream2.F_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_p[2], has value: " + String(MaterialStream2.F_p[2], "g"));
 */
void Flowsheet_eqFunction_1424(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1424};
  modelica_boolean tmp177;
  static const MMC_DEFSTRINGLIT(tmp178,77,"Variable violating min constraint: 0.0 <= MaterialStream2.F_p[2], has value: ");
  modelica_string tmp179;
  static int tmp180 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp180)
  {
    tmp177 = GreaterEq(data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */,0.0);
    if(!tmp177)
    {
      tmp179 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[112] /* MaterialStream2._F_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp178),tmp179);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp180 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1425
 type: ALGORITHM
 
   assert(MaterialStream2.F_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_p[3], has value: " + String(MaterialStream2.F_p[3], "g"));
 */
void Flowsheet_eqFunction_1425(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1425};
  modelica_boolean tmp181;
  static const MMC_DEFSTRINGLIT(tmp182,77,"Variable violating min constraint: 0.0 <= MaterialStream2.F_p[3], has value: ");
  modelica_string tmp183;
  static int tmp184 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp184)
  {
    tmp181 = GreaterEq(data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */,0.0);
    if(!tmp181)
    {
      tmp183 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[113] /* MaterialStream2._F_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp182),tmp183);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp184 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1426
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[1], has value: " + String(MaterialStream2.Fm_p[1], "g"));
 */
void Flowsheet_eqFunction_1426(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1426};
  modelica_boolean tmp185;
  static const MMC_DEFSTRINGLIT(tmp186,78,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[1], has value: ");
  modelica_string tmp187;
  static int tmp188 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp188)
  {
    tmp185 = GreaterEq(data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */,0.0);
    if(!tmp185)
    {
      tmp187 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[120] /* MaterialStream2._Fm_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp186),tmp187);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp188 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1427
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[2], has value: " + String(MaterialStream2.Fm_p[2], "g"));
 */
void Flowsheet_eqFunction_1427(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1427};
  modelica_boolean tmp189;
  static const MMC_DEFSTRINGLIT(tmp190,78,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[2], has value: ");
  modelica_string tmp191;
  static int tmp192 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp192)
  {
    tmp189 = GreaterEq(data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */,0.0);
    if(!tmp189)
    {
      tmp191 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[121] /* MaterialStream2._Fm_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp190),tmp191);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp192 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1428
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[3], has value: " + String(MaterialStream2.Fm_p[3], "g"));
 */
void Flowsheet_eqFunction_1428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1428};
  modelica_boolean tmp193;
  static const MMC_DEFSTRINGLIT(tmp194,78,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[3], has value: ");
  modelica_string tmp195;
  static int tmp196 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp196)
  {
    tmp193 = GreaterEq(data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */,0.0);
    if(!tmp193)
    {
      tmp195 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[122] /* MaterialStream2._Fm_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp194),tmp195);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp196 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1429
 type: ALGORITHM
 
   assert(MaterialStream2.MW_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[1], has value: " + String(MaterialStream2.MW_p[1], "g"));
 */
void Flowsheet_eqFunction_1429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1429};
  modelica_boolean tmp197;
  static const MMC_DEFSTRINGLIT(tmp198,78,"Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[1], has value: ");
  modelica_string tmp199;
  static int tmp200 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp200)
  {
    tmp197 = GreaterEq(data->localData[0]->realVars[143] /* MaterialStream2._MW_p[1] variable */,0.0);
    if(!tmp197)
    {
      tmp199 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[143] /* MaterialStream2._MW_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp198),tmp199);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.MW_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp200 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1430
 type: ALGORITHM
 
   assert(MaterialStream2.MW_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[2], has value: " + String(MaterialStream2.MW_p[2], "g"));
 */
void Flowsheet_eqFunction_1430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1430};
  modelica_boolean tmp201;
  static const MMC_DEFSTRINGLIT(tmp202,78,"Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[2], has value: ");
  modelica_string tmp203;
  static int tmp204 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp204)
  {
    tmp201 = GreaterEq(data->localData[0]->realVars[144] /* MaterialStream2._MW_p[2] variable */,0.0);
    if(!tmp201)
    {
      tmp203 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[144] /* MaterialStream2._MW_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp202),tmp203);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.MW_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp204 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1431
 type: ALGORITHM
 
   assert(MaterialStream2.MW_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[3], has value: " + String(MaterialStream2.MW_p[3], "g"));
 */
void Flowsheet_eqFunction_1431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1431};
  modelica_boolean tmp205;
  static const MMC_DEFSTRINGLIT(tmp206,78,"Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[3], has value: ");
  modelica_string tmp207;
  static int tmp208 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp208)
  {
    tmp205 = GreaterEq(data->localData[0]->realVars[145] /* MaterialStream2._MW_p[3] variable */,0.0);
    if(!tmp205)
    {
      tmp207 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[145] /* MaterialStream2._MW_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp206),tmp207);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.MW_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp208 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1432
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[1,1] >= 0.0 and MaterialStream2.x_pc[1,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[1,1] <= 1.0, has value: " + String(MaterialStream2.x_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1432};
  modelica_boolean tmp209;
  modelica_boolean tmp210;
  static const MMC_DEFSTRINGLIT(tmp211,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[1,1] <= 1.0, has value: ");
  modelica_string tmp212;
  static int tmp213 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp213)
  {
    tmp209 = GreaterEq(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */,0.0);
    tmp210 = LessEq(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */,1.0);
    if(!(tmp209 && tmp210))
    {
      tmp212 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp211),tmp212);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[1,1] >= 0.0 and MaterialStream2.x_pc[1,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp213 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1433
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[1,2] >= 0.0 and MaterialStream2.x_pc[1,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[1,2] <= 1.0, has value: " + String(MaterialStream2.x_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1433};
  modelica_boolean tmp214;
  modelica_boolean tmp215;
  static const MMC_DEFSTRINGLIT(tmp216,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[1,2] <= 1.0, has value: ");
  modelica_string tmp217;
  static int tmp218 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp218)
  {
    tmp214 = GreaterEq(data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */,0.0);
    tmp215 = LessEq(data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */,1.0);
    if(!(tmp214 && tmp215))
    {
      tmp217 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[173] /* MaterialStream2._x_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp216),tmp217);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[1,2] >= 0.0 and MaterialStream2.x_pc[1,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp218 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1434
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[2,1] >= 0.0 and MaterialStream2.x_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[2,1] <= 1.0, has value: " + String(MaterialStream2.x_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1434};
  modelica_boolean tmp219;
  modelica_boolean tmp220;
  static const MMC_DEFSTRINGLIT(tmp221,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp222;
  static int tmp223 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp223)
  {
    tmp219 = GreaterEq(data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */,0.0);
    tmp220 = LessEq(data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */,1.0);
    if(!(tmp219 && tmp220))
    {
      tmp222 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[174] /* MaterialStream2._x_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp221),tmp222);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[2,1] >= 0.0 and MaterialStream2.x_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp223 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1435
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[2,2] >= 0.0 and MaterialStream2.x_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[2,2] <= 1.0, has value: " + String(MaterialStream2.x_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1435};
  modelica_boolean tmp224;
  modelica_boolean tmp225;
  static const MMC_DEFSTRINGLIT(tmp226,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp227;
  static int tmp228 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp228)
  {
    tmp224 = GreaterEq(data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */,0.0);
    tmp225 = LessEq(data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */,1.0);
    if(!(tmp224 && tmp225))
    {
      tmp227 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[175] /* MaterialStream2._x_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp226),tmp227);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[2,2] >= 0.0 and MaterialStream2.x_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp228 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1436
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[3,1] >= 0.0 and MaterialStream2.x_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[3,1] <= 1.0, has value: " + String(MaterialStream2.x_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1436(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1436};
  modelica_boolean tmp229;
  modelica_boolean tmp230;
  static const MMC_DEFSTRINGLIT(tmp231,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp232;
  static int tmp233 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp233)
  {
    tmp229 = GreaterEq(data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */,0.0);
    tmp230 = LessEq(data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */,1.0);
    if(!(tmp229 && tmp230))
    {
      tmp232 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[176] /* MaterialStream2._x_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp231),tmp232);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[3,1] >= 0.0 and MaterialStream2.x_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp233 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1437
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[3,2] >= 0.0 and MaterialStream2.x_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[3,2] <= 1.0, has value: " + String(MaterialStream2.x_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1437(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1437};
  modelica_boolean tmp234;
  modelica_boolean tmp235;
  static const MMC_DEFSTRINGLIT(tmp236,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp237;
  static int tmp238 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp238)
  {
    tmp234 = GreaterEq(data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */,0.0);
    tmp235 = LessEq(data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */,1.0);
    if(!(tmp234 && tmp235))
    {
      tmp237 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[177] /* MaterialStream2._x_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp236),tmp237);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[3,2] >= 0.0 and MaterialStream2.x_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp238 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1438
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[1,1] >= 0.0 and MaterialStream2.xm_pc[1,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[1,1] <= 1.0, has value: " + String(MaterialStream2.xm_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1438(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1438};
  modelica_boolean tmp239;
  modelica_boolean tmp240;
  static const MMC_DEFSTRINGLIT(tmp241,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[1,1] <= 1.0, has value: ");
  modelica_string tmp242;
  static int tmp243 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp243)
  {
    tmp239 = GreaterEq(data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[1,1] variable */,0.0);
    tmp240 = LessEq(data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[1,1] variable */,1.0);
    if(!(tmp239 && tmp240))
    {
      tmp242 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp241),tmp242);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[1,1] >= 0.0 and MaterialStream2.xm_pc[1,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp243 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1439
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[1,2] >= 0.0 and MaterialStream2.xm_pc[1,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[1,2] <= 1.0, has value: " + String(MaterialStream2.xm_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1439(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1439};
  modelica_boolean tmp244;
  modelica_boolean tmp245;
  static const MMC_DEFSTRINGLIT(tmp246,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[1,2] <= 1.0, has value: ");
  modelica_string tmp247;
  static int tmp248 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp248)
  {
    tmp244 = GreaterEq(data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */,0.0);
    tmp245 = LessEq(data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */,1.0);
    if(!(tmp244 && tmp245))
    {
      tmp247 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp246),tmp247);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[1,2] >= 0.0 and MaterialStream2.xm_pc[1,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp248 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1440
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[2,1] >= 0.0 and MaterialStream2.xm_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[2,1] <= 1.0, has value: " + String(MaterialStream2.xm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1440(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1440};
  modelica_boolean tmp249;
  modelica_boolean tmp250;
  static const MMC_DEFSTRINGLIT(tmp251,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp252;
  static int tmp253 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp253)
  {
    tmp249 = GreaterEq(data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[2,1] variable */,0.0);
    tmp250 = LessEq(data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[2,1] variable */,1.0);
    if(!(tmp249 && tmp250))
    {
      tmp252 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp251),tmp252);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[2,1] >= 0.0 and MaterialStream2.xm_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp253 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1441
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[2,2] >= 0.0 and MaterialStream2.xm_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[2,2] <= 1.0, has value: " + String(MaterialStream2.xm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1441(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1441};
  modelica_boolean tmp254;
  modelica_boolean tmp255;
  static const MMC_DEFSTRINGLIT(tmp256,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp257;
  static int tmp258 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp258)
  {
    tmp254 = GreaterEq(data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[2,2] variable */,0.0);
    tmp255 = LessEq(data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[2,2] variable */,1.0);
    if(!(tmp254 && tmp255))
    {
      tmp257 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp256),tmp257);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[2,2] >= 0.0 and MaterialStream2.xm_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp258 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1442
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[3,1] >= 0.0 and MaterialStream2.xm_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[3,1] <= 1.0, has value: " + String(MaterialStream2.xm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1442(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1442};
  modelica_boolean tmp259;
  modelica_boolean tmp260;
  static const MMC_DEFSTRINGLIT(tmp261,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp262;
  static int tmp263 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp263)
  {
    tmp259 = GreaterEq(data->localData[0]->realVars[183] /* MaterialStream2._xm_pc[3,1] variable */,0.0);
    tmp260 = LessEq(data->localData[0]->realVars[183] /* MaterialStream2._xm_pc[3,1] variable */,1.0);
    if(!(tmp259 && tmp260))
    {
      tmp262 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[183] /* MaterialStream2._xm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp261),tmp262);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[3,1] >= 0.0 and MaterialStream2.xm_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp263 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1443
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[3,2] >= 0.0 and MaterialStream2.xm_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[3,2] <= 1.0, has value: " + String(MaterialStream2.xm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1443(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1443};
  modelica_boolean tmp264;
  modelica_boolean tmp265;
  static const MMC_DEFSTRINGLIT(tmp266,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp267;
  static int tmp268 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp268)
  {
    tmp264 = GreaterEq(data->localData[0]->realVars[184] /* MaterialStream2._xm_pc[3,2] variable */,0.0);
    tmp265 = LessEq(data->localData[0]->realVars[184] /* MaterialStream2._xm_pc[3,2] variable */,1.0);
    if(!(tmp264 && tmp265))
    {
      tmp267 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[184] /* MaterialStream2._xm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp266),tmp267);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[3,2] >= 0.0 and MaterialStream2.xm_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp268 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1444
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[1,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[1,1], has value: " + String(MaterialStream2.F_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1444(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1444};
  modelica_boolean tmp269;
  static const MMC_DEFSTRINGLIT(tmp270,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[1,1], has value: ");
  modelica_string tmp271;
  static int tmp272 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp272)
  {
    tmp269 = GreaterEq(data->localData[0]->realVars[114] /* MaterialStream2._F_pc[1,1] variable */,0.0);
    if(!tmp269)
    {
      tmp271 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[114] /* MaterialStream2._F_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp270),tmp271);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[1,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp272 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1445
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[1,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[1,2], has value: " + String(MaterialStream2.F_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1445(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1445};
  modelica_boolean tmp273;
  static const MMC_DEFSTRINGLIT(tmp274,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[1,2], has value: ");
  modelica_string tmp275;
  static int tmp276 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp276)
  {
    tmp273 = GreaterEq(data->localData[0]->realVars[115] /* MaterialStream2._F_pc[1,2] variable */,0.0);
    if(!tmp273)
    {
      tmp275 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[115] /* MaterialStream2._F_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp274),tmp275);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[1,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp276 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1446
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[2,1], has value: " + String(MaterialStream2.F_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1446(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1446};
  modelica_boolean tmp277;
  static const MMC_DEFSTRINGLIT(tmp278,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[2,1], has value: ");
  modelica_string tmp279;
  static int tmp280 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp280)
  {
    tmp277 = GreaterEq(data->localData[0]->realVars[116] /* MaterialStream2._F_pc[2,1] variable */,0.0);
    if(!tmp277)
    {
      tmp279 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[116] /* MaterialStream2._F_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp278),tmp279);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp280 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1447
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[2,2], has value: " + String(MaterialStream2.F_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1447(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1447};
  modelica_boolean tmp281;
  static const MMC_DEFSTRINGLIT(tmp282,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[2,2], has value: ");
  modelica_string tmp283;
  static int tmp284 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp284)
  {
    tmp281 = GreaterEq(data->localData[0]->realVars[117] /* MaterialStream2._F_pc[2,2] variable */,0.0);
    if(!tmp281)
    {
      tmp283 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[117] /* MaterialStream2._F_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp282),tmp283);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp284 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1448
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[3,1], has value: " + String(MaterialStream2.F_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1448(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1448};
  modelica_boolean tmp285;
  static const MMC_DEFSTRINGLIT(tmp286,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[3,1], has value: ");
  modelica_string tmp287;
  static int tmp288 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp288)
  {
    tmp285 = GreaterEq(data->localData[0]->realVars[118] /* MaterialStream2._F_pc[3,1] variable */,0.0);
    if(!tmp285)
    {
      tmp287 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[118] /* MaterialStream2._F_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp286),tmp287);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp288 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1449
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[3,2], has value: " + String(MaterialStream2.F_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1449(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1449};
  modelica_boolean tmp289;
  static const MMC_DEFSTRINGLIT(tmp290,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[3,2], has value: ");
  modelica_string tmp291;
  static int tmp292 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp292)
  {
    tmp289 = GreaterEq(data->localData[0]->realVars[119] /* MaterialStream2._F_pc[3,2] variable */,0.0);
    if(!tmp289)
    {
      tmp291 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[119] /* MaterialStream2._F_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp290),tmp291);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp292 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1450
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[1,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[1,1], has value: " + String(MaterialStream2.Fm_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1450(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1450};
  modelica_boolean tmp293;
  static const MMC_DEFSTRINGLIT(tmp294,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[1,1], has value: ");
  modelica_string tmp295;
  static int tmp296 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp296)
  {
    tmp293 = GreaterEq(data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */,0.0);
    if(!tmp293)
    {
      tmp295 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp294),tmp295);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[1,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp296 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1451
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[1,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[1,2], has value: " + String(MaterialStream2.Fm_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1451(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1451};
  modelica_boolean tmp297;
  static const MMC_DEFSTRINGLIT(tmp298,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[1,2], has value: ");
  modelica_string tmp299;
  static int tmp300 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp300)
  {
    tmp297 = GreaterEq(data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[1,2] variable */,0.0);
    if(!tmp297)
    {
      tmp299 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp298),tmp299);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[1,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp300 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1452
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[2,1], has value: " + String(MaterialStream2.Fm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1452(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1452};
  modelica_boolean tmp301;
  static const MMC_DEFSTRINGLIT(tmp302,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[2,1], has value: ");
  modelica_string tmp303;
  static int tmp304 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp304)
  {
    tmp301 = GreaterEq(data->localData[0]->realVars[125] /* MaterialStream2._Fm_pc[2,1] variable */,0.0);
    if(!tmp301)
    {
      tmp303 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[125] /* MaterialStream2._Fm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp302),tmp303);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp304 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1453
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[2,2], has value: " + String(MaterialStream2.Fm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1453(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1453};
  modelica_boolean tmp305;
  static const MMC_DEFSTRINGLIT(tmp306,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[2,2], has value: ");
  modelica_string tmp307;
  static int tmp308 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp308)
  {
    tmp305 = GreaterEq(data->localData[0]->realVars[126] /* MaterialStream2._Fm_pc[2,2] variable */,0.0);
    if(!tmp305)
    {
      tmp307 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[126] /* MaterialStream2._Fm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp306),tmp307);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp308 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1454
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[3,1], has value: " + String(MaterialStream2.Fm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1454(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1454};
  modelica_boolean tmp309;
  static const MMC_DEFSTRINGLIT(tmp310,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[3,1], has value: ");
  modelica_string tmp311;
  static int tmp312 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp312)
  {
    tmp309 = GreaterEq(data->localData[0]->realVars[127] /* MaterialStream2._Fm_pc[3,1] variable */,0.0);
    if(!tmp309)
    {
      tmp311 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[127] /* MaterialStream2._Fm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp310),tmp311);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp312 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1455
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[3,2], has value: " + String(MaterialStream2.Fm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1455(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1455};
  modelica_boolean tmp313;
  static const MMC_DEFSTRINGLIT(tmp314,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[3,2], has value: ");
  modelica_string tmp315;
  static int tmp316 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp316)
  {
    tmp313 = GreaterEq(data->localData[0]->realVars[128] /* MaterialStream2._Fm_pc[3,2] variable */,0.0);
    if(!tmp313)
    {
      tmp315 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[128] /* MaterialStream2._Fm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp314),tmp315);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp316 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1456
 type: ALGORITHM
 
   assert(Heater1.xvapin >= 0.0 and Heater1.xvapin <= 1.0, "Variable violating min/max constraint: 0.0 <= Heater1.xvapin <= 1.0, has value: " + String(Heater1.xvapin, "g"));
 */
void Flowsheet_eqFunction_1456(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1456};
  modelica_boolean tmp317;
  modelica_boolean tmp318;
  static const MMC_DEFSTRINGLIT(tmp319,80,"Variable violating min/max constraint: 0.0 <= Heater1.xvapin <= 1.0, has value: ");
  modelica_string tmp320;
  static int tmp321 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp321)
  {
    tmp317 = GreaterEq(data->localData[0]->realVars[8] /* Heater1._xvapin variable */,0.0);
    tmp318 = LessEq(data->localData[0]->realVars[8] /* Heater1._xvapin variable */,1.0);
    if(!(tmp317 && tmp318))
    {
      tmp320 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[8] /* Heater1._xvapin variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp319),tmp320);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/UnitOperations/Heater.mo",13,3,13,100,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nHeater1.xvapin >= 0.0 and Heater1.xvapin <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp321 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1457
 type: ALGORITHM
 
   assert(Heater1.xvapout >= 0.0 and Heater1.xvapout <= 1.0, "Variable violating min/max constraint: 0.0 <= Heater1.xvapout <= 1.0, has value: " + String(Heater1.xvapout, "g"));
 */
void Flowsheet_eqFunction_1457(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1457};
  modelica_boolean tmp322;
  modelica_boolean tmp323;
  static const MMC_DEFSTRINGLIT(tmp324,81,"Variable violating min/max constraint: 0.0 <= Heater1.xvapout <= 1.0, has value: ");
  modelica_string tmp325;
  static int tmp326 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp326)
  {
    tmp322 = GreaterEq(data->localData[0]->realVars[9] /* Heater1._xvapout variable */,0.0);
    tmp323 = LessEq(data->localData[0]->realVars[9] /* Heater1._xvapout variable */,1.0);
    if(!(tmp322 && tmp323))
    {
      tmp325 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[9] /* Heater1._xvapout variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp324),tmp325);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/UnitOperations/Heater.mo",21,3,21,96,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nHeater1.xvapout >= 0.0 and Heater1.xvapout <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp326 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1389
 type: ALGORITHM
 
   assert(MaterialStream2.K_c[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.K_c[2], has value: " + String(MaterialStream2.K_c[2], "g"));
 */
void Flowsheet_eqFunction_1389(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1389};
  modelica_boolean tmp327;
  static const MMC_DEFSTRINGLIT(tmp328,77,"Variable violating min constraint: 0.0 <= MaterialStream2.K_c[2], has value: ");
  modelica_string tmp329;
  static int tmp330 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp330)
  {
    tmp327 = GreaterEq(data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */,0.0);
    if(!tmp327)
    {
      tmp329 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[142] /* MaterialStream2._K_c[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp328),tmp329);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Files/ThermodynamicPackages/RaoultsLaw.mo",5,5,5,65,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.K_c[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp330 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1388
 type: ALGORITHM
 
   assert(MaterialStream2.K_c[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.K_c[1], has value: " + String(MaterialStream2.K_c[1], "g"));
 */
void Flowsheet_eqFunction_1388(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1388};
  modelica_boolean tmp331;
  static const MMC_DEFSTRINGLIT(tmp332,77,"Variable violating min constraint: 0.0 <= MaterialStream2.K_c[1], has value: ");
  modelica_string tmp333;
  static int tmp334 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp334)
  {
    tmp331 = GreaterEq(data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */,0.0);
    if(!tmp331)
    {
      tmp333 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[141] /* MaterialStream2._K_c[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp332),tmp333);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Files/ThermodynamicPackages/RaoultsLaw.mo",5,5,5,65,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.K_c[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp334 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1387
 type: ALGORITHM
 
   assert(MaterialStream1.K_c[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.K_c[2], has value: " + String(MaterialStream1.K_c[2], "g"));
 */
void Flowsheet_eqFunction_1387(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1387};
  modelica_boolean tmp335;
  static const MMC_DEFSTRINGLIT(tmp336,77,"Variable violating min constraint: 0.0 <= MaterialStream1.K_c[2], has value: ");
  modelica_string tmp337;
  static int tmp338 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp338)
  {
    tmp335 = GreaterEq(data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */,0.0);
    if(!tmp335)
    {
      tmp337 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[53] /* MaterialStream1._K_c[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp336),tmp337);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Files/ThermodynamicPackages/RaoultsLaw.mo",5,5,5,65,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.K_c[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp338 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1386
 type: ALGORITHM
 
   assert(MaterialStream1.K_c[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.K_c[1], has value: " + String(MaterialStream1.K_c[1], "g"));
 */
void Flowsheet_eqFunction_1386(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1386};
  modelica_boolean tmp339;
  static const MMC_DEFSTRINGLIT(tmp340,77,"Variable violating min constraint: 0.0 <= MaterialStream1.K_c[1], has value: ");
  modelica_string tmp341;
  static int tmp342 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp342)
  {
    tmp339 = GreaterEq(data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */,0.0);
    if(!tmp339)
    {
      tmp341 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[52] /* MaterialStream1._K_c[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp340),tmp341);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Files/ThermodynamicPackages/RaoultsLaw.mo",5,5,5,65,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.K_c[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp342 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1385
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[1,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[1,2], has value: " + String(MaterialStream1.Fm_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1385(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1385};
  modelica_boolean tmp343;
  static const MMC_DEFSTRINGLIT(tmp344,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[1,2], has value: ");
  modelica_string tmp345;
  static int tmp346 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp346)
  {
    tmp343 = GreaterEq(data->localData[0]->realVars[35] /* MaterialStream1._Fm_pc[1,2] variable */,0.0);
    if(!tmp343)
    {
      tmp345 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[35] /* MaterialStream1._Fm_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp344),tmp345);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[1,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp346 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1384
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[1,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[1,1], has value: " + String(MaterialStream1.Fm_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1384};
  modelica_boolean tmp347;
  static const MMC_DEFSTRINGLIT(tmp348,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[1,1], has value: ");
  modelica_string tmp349;
  static int tmp350 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp350)
  {
    tmp347 = GreaterEq(data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */,0.0);
    if(!tmp347)
    {
      tmp349 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp348),tmp349);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/building/Chemical-Simulator-GUI/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[1,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp350 = 1;
    }
  }
  TRACE_POP
}
/* function to check assert after a step is done */
int Flowsheet_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  Flowsheet_eqFunction_1390(data, threadData);

  Flowsheet_eqFunction_1391(data, threadData);

  Flowsheet_eqFunction_1392(data, threadData);

  Flowsheet_eqFunction_1393(data, threadData);

  Flowsheet_eqFunction_1394(data, threadData);

  Flowsheet_eqFunction_1395(data, threadData);

  Flowsheet_eqFunction_1396(data, threadData);

  Flowsheet_eqFunction_1397(data, threadData);

  Flowsheet_eqFunction_1398(data, threadData);

  Flowsheet_eqFunction_1399(data, threadData);

  Flowsheet_eqFunction_1400(data, threadData);

  Flowsheet_eqFunction_1401(data, threadData);

  Flowsheet_eqFunction_1402(data, threadData);

  Flowsheet_eqFunction_1403(data, threadData);

  Flowsheet_eqFunction_1404(data, threadData);

  Flowsheet_eqFunction_1405(data, threadData);

  Flowsheet_eqFunction_1406(data, threadData);

  Flowsheet_eqFunction_1407(data, threadData);

  Flowsheet_eqFunction_1408(data, threadData);

  Flowsheet_eqFunction_1409(data, threadData);

  Flowsheet_eqFunction_1410(data, threadData);

  Flowsheet_eqFunction_1411(data, threadData);

  Flowsheet_eqFunction_1412(data, threadData);

  Flowsheet_eqFunction_1413(data, threadData);

  Flowsheet_eqFunction_1414(data, threadData);

  Flowsheet_eqFunction_1415(data, threadData);

  Flowsheet_eqFunction_1416(data, threadData);

  Flowsheet_eqFunction_1417(data, threadData);

  Flowsheet_eqFunction_1418(data, threadData);

  Flowsheet_eqFunction_1419(data, threadData);

  Flowsheet_eqFunction_1420(data, threadData);

  Flowsheet_eqFunction_1421(data, threadData);

  Flowsheet_eqFunction_1422(data, threadData);

  Flowsheet_eqFunction_1423(data, threadData);

  Flowsheet_eqFunction_1424(data, threadData);

  Flowsheet_eqFunction_1425(data, threadData);

  Flowsheet_eqFunction_1426(data, threadData);

  Flowsheet_eqFunction_1427(data, threadData);

  Flowsheet_eqFunction_1428(data, threadData);

  Flowsheet_eqFunction_1429(data, threadData);

  Flowsheet_eqFunction_1430(data, threadData);

  Flowsheet_eqFunction_1431(data, threadData);

  Flowsheet_eqFunction_1432(data, threadData);

  Flowsheet_eqFunction_1433(data, threadData);

  Flowsheet_eqFunction_1434(data, threadData);

  Flowsheet_eqFunction_1435(data, threadData);

  Flowsheet_eqFunction_1436(data, threadData);

  Flowsheet_eqFunction_1437(data, threadData);

  Flowsheet_eqFunction_1438(data, threadData);

  Flowsheet_eqFunction_1439(data, threadData);

  Flowsheet_eqFunction_1440(data, threadData);

  Flowsheet_eqFunction_1441(data, threadData);

  Flowsheet_eqFunction_1442(data, threadData);

  Flowsheet_eqFunction_1443(data, threadData);

  Flowsheet_eqFunction_1444(data, threadData);

  Flowsheet_eqFunction_1445(data, threadData);

  Flowsheet_eqFunction_1446(data, threadData);

  Flowsheet_eqFunction_1447(data, threadData);

  Flowsheet_eqFunction_1448(data, threadData);

  Flowsheet_eqFunction_1449(data, threadData);

  Flowsheet_eqFunction_1450(data, threadData);

  Flowsheet_eqFunction_1451(data, threadData);

  Flowsheet_eqFunction_1452(data, threadData);

  Flowsheet_eqFunction_1453(data, threadData);

  Flowsheet_eqFunction_1454(data, threadData);

  Flowsheet_eqFunction_1455(data, threadData);

  Flowsheet_eqFunction_1456(data, threadData);

  Flowsheet_eqFunction_1457(data, threadData);

  Flowsheet_eqFunction_1389(data, threadData);

  Flowsheet_eqFunction_1388(data, threadData);

  Flowsheet_eqFunction_1387(data, threadData);

  Flowsheet_eqFunction_1386(data, threadData);

  Flowsheet_eqFunction_1385(data, threadData);

  Flowsheet_eqFunction_1384(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

