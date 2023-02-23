/* Asserts */
#include "Flowsheet_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
 equation index: 1848
 type: ALGORITHM
 
   assert(MaterialStream1.xliq >= 0.0 and MaterialStream1.xliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xliq <= 1.0, has value: " + String(MaterialStream1.xliq, "g"));
 */
void Flowsheet_eqFunction_1848(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1848};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  static const MMC_DEFSTRINGLIT(tmp2,86,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xliq <= 1.0, has value: ");
  modelica_string tmp3;
  static int tmp4 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp4)
  {
    tmp0 = GreaterEq(data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */,0.0);
    tmp1 = LessEq(data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */,1.0);
    if(!(tmp0 && tmp1))
    {
      tmp3 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[86] /* MaterialStream1._xliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp2),tmp3);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",14,3,14,86,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xliq >= 0.0 and MaterialStream1.xliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp4 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1849
 type: ALGORITHM
 
   assert(MaterialStream1.xmliq >= 0.0 and MaterialStream1.xmliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xmliq <= 1.0, has value: " + String(MaterialStream1.xmliq, "g"));
 */
void Flowsheet_eqFunction_1849(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1849};
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  static const MMC_DEFSTRINGLIT(tmp7,87,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xmliq <= 1.0, has value: ");
  modelica_string tmp8;
  static int tmp9 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp9)
  {
    tmp5 = GreaterEq(data->localData[0]->realVars[93] /* MaterialStream1._xmliq variable */,0.0);
    tmp6 = LessEq(data->localData[0]->realVars[93] /* MaterialStream1._xmliq variable */,1.0);
    if(!(tmp5 && tmp6))
    {
      tmp8 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[93] /* MaterialStream1._xmliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp7),tmp8);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",16,3,16,87,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xmliq >= 0.0 and MaterialStream1.xmliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp9 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1850
 type: ALGORITHM
 
   assert(MaterialStream1.xmvap >= 0.0 and MaterialStream1.xmvap <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xmvap <= 1.0, has value: " + String(MaterialStream1.xmvap, "g"));
 */
void Flowsheet_eqFunction_1850(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1850};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  static const MMC_DEFSTRINGLIT(tmp12,87,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xmvap <= 1.0, has value: ");
  modelica_string tmp13;
  static int tmp14 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp14)
  {
    tmp10 = GreaterEq(data->localData[0]->realVars[94] /* MaterialStream1._xmvap variable */,0.0);
    tmp11 = LessEq(data->localData[0]->realVars[94] /* MaterialStream1._xmvap variable */,1.0);
    if(!(tmp10 && tmp11))
    {
      tmp13 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[94] /* MaterialStream1._xmvap variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp12),tmp13);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",17,3,17,84,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xmvap >= 0.0 and MaterialStream1.xmvap <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp14 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1851
 type: ALGORITHM
 
   assert(MaterialStream1.F_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_p[2], has value: " + String(MaterialStream1.F_p[2], "g"));
 */
void Flowsheet_eqFunction_1851(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1851};
  modelica_boolean tmp15;
  static const MMC_DEFSTRINGLIT(tmp16,77,"Variable violating min constraint: 0.0 <= MaterialStream1.F_p[2], has value: ");
  modelica_string tmp17;
  static int tmp18 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp18)
  {
    tmp15 = GreaterEq(data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */,0.0);
    if(!tmp15)
    {
      tmp17 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[18] /* MaterialStream1._F_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp16),tmp17);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp18 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1852
 type: ALGORITHM
 
   assert(MaterialStream1.F_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_p[3], has value: " + String(MaterialStream1.F_p[3], "g"));
 */
void Flowsheet_eqFunction_1852(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1852};
  modelica_boolean tmp19;
  static const MMC_DEFSTRINGLIT(tmp20,77,"Variable violating min constraint: 0.0 <= MaterialStream1.F_p[3], has value: ");
  modelica_string tmp21;
  static int tmp22 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp22)
  {
    tmp19 = GreaterEq(data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */,0.0);
    if(!tmp19)
    {
      tmp21 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[19] /* MaterialStream1._F_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp20),tmp21);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp22 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1853
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[1], has value: " + String(MaterialStream1.Fm_p[1], "g"));
 */
void Flowsheet_eqFunction_1853(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1853};
  modelica_boolean tmp23;
  static const MMC_DEFSTRINGLIT(tmp24,78,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[1], has value: ");
  modelica_string tmp25;
  static int tmp26 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp26)
  {
    tmp23 = GreaterEq(data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */,0.0);
    if(!tmp23)
    {
      tmp25 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[26] /* MaterialStream1._Fm_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp24),tmp25);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp26 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1854
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[2], has value: " + String(MaterialStream1.Fm_p[2], "g"));
 */
void Flowsheet_eqFunction_1854(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1854};
  modelica_boolean tmp27;
  static const MMC_DEFSTRINGLIT(tmp28,78,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[2], has value: ");
  modelica_string tmp29;
  static int tmp30 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp30)
  {
    tmp27 = GreaterEq(data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */,0.0);
    if(!tmp27)
    {
      tmp29 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[27] /* MaterialStream1._Fm_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp28),tmp29);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp30 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1855
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[3], has value: " + String(MaterialStream1.Fm_p[3], "g"));
 */
void Flowsheet_eqFunction_1855(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1855};
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,78,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_p[3], has value: ");
  modelica_string tmp33;
  static int tmp34 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp34)
  {
    tmp31 = GreaterEq(data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */,0.0);
    if(!tmp31)
    {
      tmp33 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[28] /* MaterialStream1._Fm_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp32),tmp33);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp34 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1856
 type: ALGORITHM
 
   assert(MaterialStream1.MW_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[1], has value: " + String(MaterialStream1.MW_p[1], "g"));
 */
void Flowsheet_eqFunction_1856(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1856};
  modelica_boolean tmp35;
  static const MMC_DEFSTRINGLIT(tmp36,78,"Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[1], has value: ");
  modelica_string tmp37;
  static int tmp38 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp38)
  {
    tmp35 = GreaterEq(data->localData[0]->realVars[49] /* MaterialStream1._MW_p[1] variable */,0.0);
    if(!tmp35)
    {
      tmp37 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[49] /* MaterialStream1._MW_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp36),tmp37);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.MW_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp38 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1857
 type: ALGORITHM
 
   assert(MaterialStream1.MW_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[2], has value: " + String(MaterialStream1.MW_p[2], "g"));
 */
void Flowsheet_eqFunction_1857(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1857};
  modelica_boolean tmp39;
  static const MMC_DEFSTRINGLIT(tmp40,78,"Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[2], has value: ");
  modelica_string tmp41;
  static int tmp42 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp42)
  {
    tmp39 = GreaterEq(data->localData[0]->realVars[50] /* MaterialStream1._MW_p[2] variable */,0.0);
    if(!tmp39)
    {
      tmp41 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[50] /* MaterialStream1._MW_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp40),tmp41);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.MW_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp42 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1858
 type: ALGORITHM
 
   assert(MaterialStream1.MW_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[3], has value: " + String(MaterialStream1.MW_p[3], "g"));
 */
void Flowsheet_eqFunction_1858(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1858};
  modelica_boolean tmp43;
  static const MMC_DEFSTRINGLIT(tmp44,78,"Variable violating min constraint: 0.0 <= MaterialStream1.MW_p[3], has value: ");
  modelica_string tmp45;
  static int tmp46 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp46)
  {
    tmp43 = GreaterEq(data->localData[0]->realVars[51] /* MaterialStream1._MW_p[3] variable */,0.0);
    if(!tmp43)
    {
      tmp45 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[51] /* MaterialStream1._MW_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp44),tmp45);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.MW_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp46 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1859
 type: ALGORITHM
 
   assert(MaterialStream1.x_pc[2,1] >= 0.0 and MaterialStream1.x_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[2,1] <= 1.0, has value: " + String(MaterialStream1.x_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1859(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1859};
  modelica_boolean tmp47;
  modelica_boolean tmp48;
  static const MMC_DEFSTRINGLIT(tmp49,91,"Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp50;
  static int tmp51 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp51)
  {
    tmp47 = GreaterEq(data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */,0.0);
    tmp48 = LessEq(data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */,1.0);
    if(!(tmp47 && tmp48))
    {
      tmp50 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[82] /* MaterialStream1._x_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp49),tmp50);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.x_pc[2,1] >= 0.0 and MaterialStream1.x_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp51 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1860
 type: ALGORITHM
 
   assert(MaterialStream1.x_pc[2,2] >= 0.0 and MaterialStream1.x_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[2,2] <= 1.0, has value: " + String(MaterialStream1.x_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1860(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1860};
  modelica_boolean tmp52;
  modelica_boolean tmp53;
  static const MMC_DEFSTRINGLIT(tmp54,91,"Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp55;
  static int tmp56 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp56)
  {
    tmp52 = GreaterEq(data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */,0.0);
    tmp53 = LessEq(data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */,1.0);
    if(!(tmp52 && tmp53))
    {
      tmp55 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[83] /* MaterialStream1._x_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp54),tmp55);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.x_pc[2,2] >= 0.0 and MaterialStream1.x_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp56 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1861
 type: ALGORITHM
 
   assert(MaterialStream1.x_pc[3,1] >= 0.0 and MaterialStream1.x_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[3,1] <= 1.0, has value: " + String(MaterialStream1.x_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1861(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1861};
  modelica_boolean tmp57;
  modelica_boolean tmp58;
  static const MMC_DEFSTRINGLIT(tmp59,91,"Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp60;
  static int tmp61 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp61)
  {
    tmp57 = GreaterEq(data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */,0.0);
    tmp58 = LessEq(data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */,1.0);
    if(!(tmp57 && tmp58))
    {
      tmp60 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[84] /* MaterialStream1._x_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp59),tmp60);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.x_pc[3,1] >= 0.0 and MaterialStream1.x_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp61 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1862
 type: ALGORITHM
 
   assert(MaterialStream1.x_pc[3,2] >= 0.0 and MaterialStream1.x_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[3,2] <= 1.0, has value: " + String(MaterialStream1.x_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1862(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1862};
  modelica_boolean tmp62;
  modelica_boolean tmp63;
  static const MMC_DEFSTRINGLIT(tmp64,91,"Variable violating min/max constraint: 0.0 <= MaterialStream1.x_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp65;
  static int tmp66 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp66)
  {
    tmp62 = GreaterEq(data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */,0.0);
    tmp63 = LessEq(data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */,1.0);
    if(!(tmp62 && tmp63))
    {
      tmp65 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[85] /* MaterialStream1._x_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp64),tmp65);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.x_pc[3,2] >= 0.0 and MaterialStream1.x_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp66 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1863
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[1,1] >= 0.0 and MaterialStream1.xm_pc[1,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[1,1] <= 1.0, has value: " + String(MaterialStream1.xm_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1863(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1863};
  modelica_boolean tmp67;
  modelica_boolean tmp68;
  static const MMC_DEFSTRINGLIT(tmp69,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[1,1] <= 1.0, has value: ");
  modelica_string tmp70;
  static int tmp71 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp71)
  {
    tmp67 = GreaterEq(data->localData[0]->realVars[87] /* MaterialStream1._xm_pc[1,1] variable */,0.0);
    tmp68 = LessEq(data->localData[0]->realVars[87] /* MaterialStream1._xm_pc[1,1] variable */,1.0);
    if(!(tmp67 && tmp68))
    {
      tmp70 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[87] /* MaterialStream1._xm_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp69),tmp70);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[1,1] >= 0.0 and MaterialStream1.xm_pc[1,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp71 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1864
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[1,2] >= 0.0 and MaterialStream1.xm_pc[1,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[1,2] <= 1.0, has value: " + String(MaterialStream1.xm_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1864(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1864};
  modelica_boolean tmp72;
  modelica_boolean tmp73;
  static const MMC_DEFSTRINGLIT(tmp74,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[1,2] <= 1.0, has value: ");
  modelica_string tmp75;
  static int tmp76 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp76)
  {
    tmp72 = GreaterEq(data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */,0.0);
    tmp73 = LessEq(data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */,1.0);
    if(!(tmp72 && tmp73))
    {
      tmp75 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[88] /* MaterialStream1._xm_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp74),tmp75);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[1,2] >= 0.0 and MaterialStream1.xm_pc[1,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp76 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1865
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[2,1] >= 0.0 and MaterialStream1.xm_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[2,1] <= 1.0, has value: " + String(MaterialStream1.xm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1865(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1865};
  modelica_boolean tmp77;
  modelica_boolean tmp78;
  static const MMC_DEFSTRINGLIT(tmp79,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp80;
  static int tmp81 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp81)
  {
    tmp77 = GreaterEq(data->localData[0]->realVars[89] /* MaterialStream1._xm_pc[2,1] variable */,0.0);
    tmp78 = LessEq(data->localData[0]->realVars[89] /* MaterialStream1._xm_pc[2,1] variable */,1.0);
    if(!(tmp77 && tmp78))
    {
      tmp80 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[89] /* MaterialStream1._xm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp79),tmp80);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[2,1] >= 0.0 and MaterialStream1.xm_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp81 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1866
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[2,2] >= 0.0 and MaterialStream1.xm_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[2,2] <= 1.0, has value: " + String(MaterialStream1.xm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1866(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1866};
  modelica_boolean tmp82;
  modelica_boolean tmp83;
  static const MMC_DEFSTRINGLIT(tmp84,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp85;
  static int tmp86 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp86)
  {
    tmp82 = GreaterEq(data->localData[0]->realVars[90] /* MaterialStream1._xm_pc[2,2] variable */,0.0);
    tmp83 = LessEq(data->localData[0]->realVars[90] /* MaterialStream1._xm_pc[2,2] variable */,1.0);
    if(!(tmp82 && tmp83))
    {
      tmp85 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[90] /* MaterialStream1._xm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp84),tmp85);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[2,2] >= 0.0 and MaterialStream1.xm_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp86 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1867
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[3,1] >= 0.0 and MaterialStream1.xm_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[3,1] <= 1.0, has value: " + String(MaterialStream1.xm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1867(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1867};
  modelica_boolean tmp87;
  modelica_boolean tmp88;
  static const MMC_DEFSTRINGLIT(tmp89,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp90;
  static int tmp91 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp91)
  {
    tmp87 = GreaterEq(data->localData[0]->realVars[91] /* MaterialStream1._xm_pc[3,1] variable */,0.0);
    tmp88 = LessEq(data->localData[0]->realVars[91] /* MaterialStream1._xm_pc[3,1] variable */,1.0);
    if(!(tmp87 && tmp88))
    {
      tmp90 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[91] /* MaterialStream1._xm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp89),tmp90);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[3,1] >= 0.0 and MaterialStream1.xm_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp91 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1868
 type: ALGORITHM
 
   assert(MaterialStream1.xm_pc[3,2] >= 0.0 and MaterialStream1.xm_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[3,2] <= 1.0, has value: " + String(MaterialStream1.xm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1868(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1868};
  modelica_boolean tmp92;
  modelica_boolean tmp93;
  static const MMC_DEFSTRINGLIT(tmp94,92,"Variable violating min/max constraint: 0.0 <= MaterialStream1.xm_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp95;
  static int tmp96 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp96)
  {
    tmp92 = GreaterEq(data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[3,2] variable */,0.0);
    tmp93 = LessEq(data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[3,2] variable */,1.0);
    if(!(tmp92 && tmp93))
    {
      tmp95 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[92] /* MaterialStream1._xm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp94),tmp95);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.xm_pc[3,2] >= 0.0 and MaterialStream1.xm_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp96 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1869
 type: ALGORITHM
 
   assert(MaterialStream1.F_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[2,1], has value: " + String(MaterialStream1.F_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1869(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1869};
  modelica_boolean tmp97;
  static const MMC_DEFSTRINGLIT(tmp98,80,"Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[2,1], has value: ");
  modelica_string tmp99;
  static int tmp100 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp100)
  {
    tmp97 = GreaterEq(data->localData[0]->realVars[22] /* MaterialStream1._F_pc[2,1] variable */,0.0);
    if(!tmp97)
    {
      tmp99 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[22] /* MaterialStream1._F_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp98),tmp99);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp100 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1870
 type: ALGORITHM
 
   assert(MaterialStream1.F_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[2,2], has value: " + String(MaterialStream1.F_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1870(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1870};
  modelica_boolean tmp101;
  static const MMC_DEFSTRINGLIT(tmp102,80,"Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[2,2], has value: ");
  modelica_string tmp103;
  static int tmp104 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp104)
  {
    tmp101 = GreaterEq(data->localData[0]->realVars[23] /* MaterialStream1._F_pc[2,2] variable */,0.0);
    if(!tmp101)
    {
      tmp103 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[23] /* MaterialStream1._F_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp102),tmp103);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp104 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1871
 type: ALGORITHM
 
   assert(MaterialStream1.F_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[3,1], has value: " + String(MaterialStream1.F_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1871(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1871};
  modelica_boolean tmp105;
  static const MMC_DEFSTRINGLIT(tmp106,80,"Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[3,1], has value: ");
  modelica_string tmp107;
  static int tmp108 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp108)
  {
    tmp105 = GreaterEq(data->localData[0]->realVars[24] /* MaterialStream1._F_pc[3,1] variable */,0.0);
    if(!tmp105)
    {
      tmp107 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[24] /* MaterialStream1._F_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp106),tmp107);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp108 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1872
 type: ALGORITHM
 
   assert(MaterialStream1.F_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[3,2], has value: " + String(MaterialStream1.F_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1872(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1872};
  modelica_boolean tmp109;
  static const MMC_DEFSTRINGLIT(tmp110,80,"Variable violating min constraint: 0.0 <= MaterialStream1.F_pc[3,2], has value: ");
  modelica_string tmp111;
  static int tmp112 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp112)
  {
    tmp109 = GreaterEq(data->localData[0]->realVars[25] /* MaterialStream1._F_pc[3,2] variable */,0.0);
    if(!tmp109)
    {
      tmp111 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[25] /* MaterialStream1._F_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp110),tmp111);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.F_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp112 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1873
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[2,1], has value: " + String(MaterialStream1.Fm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1873(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1873};
  modelica_boolean tmp113;
  static const MMC_DEFSTRINGLIT(tmp114,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[2,1], has value: ");
  modelica_string tmp115;
  static int tmp116 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp116)
  {
    tmp113 = GreaterEq(data->localData[0]->realVars[31] /* MaterialStream1._Fm_pc[2,1] variable */,0.0);
    if(!tmp113)
    {
      tmp115 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[31] /* MaterialStream1._Fm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp114),tmp115);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp116 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1874
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[2,2], has value: " + String(MaterialStream1.Fm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1874(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1874};
  modelica_boolean tmp117;
  static const MMC_DEFSTRINGLIT(tmp118,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[2,2], has value: ");
  modelica_string tmp119;
  static int tmp120 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp120)
  {
    tmp117 = GreaterEq(data->localData[0]->realVars[32] /* MaterialStream1._Fm_pc[2,2] variable */,0.0);
    if(!tmp117)
    {
      tmp119 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[32] /* MaterialStream1._Fm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp118),tmp119);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp120 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1875
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[3,1], has value: " + String(MaterialStream1.Fm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1875(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1875};
  modelica_boolean tmp121;
  static const MMC_DEFSTRINGLIT(tmp122,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[3,1], has value: ");
  modelica_string tmp123;
  static int tmp124 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp124)
  {
    tmp121 = GreaterEq(data->localData[0]->realVars[33] /* MaterialStream1._Fm_pc[3,1] variable */,0.0);
    if(!tmp121)
    {
      tmp123 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[33] /* MaterialStream1._Fm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp122),tmp123);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp124 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1876
 type: ALGORITHM
 
   assert(MaterialStream1.Fm_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[3,2], has value: " + String(MaterialStream1.Fm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1876(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1876};
  modelica_boolean tmp125;
  static const MMC_DEFSTRINGLIT(tmp126,81,"Variable violating min constraint: 0.0 <= MaterialStream1.Fm_pc[3,2], has value: ");
  modelica_string tmp127;
  static int tmp128 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp128)
  {
    tmp125 = GreaterEq(data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[3,2] variable */,0.0);
    if(!tmp125)
    {
      tmp127 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[34] /* MaterialStream1._Fm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp126),tmp127);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream1.Fm_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp128 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1877
 type: ALGORITHM
 
   assert(MaterialStream2.xliq >= 0.0 and MaterialStream2.xliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xliq <= 1.0, has value: " + String(MaterialStream2.xliq, "g"));
 */
void Flowsheet_eqFunction_1877(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1877};
  modelica_boolean tmp129;
  modelica_boolean tmp130;
  static const MMC_DEFSTRINGLIT(tmp131,86,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xliq <= 1.0, has value: ");
  modelica_string tmp132;
  static int tmp133 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp133)
  {
    tmp129 = GreaterEq(data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */,0.0);
    tmp130 = LessEq(data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */,1.0);
    if(!(tmp129 && tmp130))
    {
      tmp132 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[176] /* MaterialStream2._xliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp131),tmp132);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",14,3,14,86,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xliq >= 0.0 and MaterialStream2.xliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp133 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1878
 type: ALGORITHM
 
   assert(MaterialStream2.xmliq >= 0.0 and MaterialStream2.xmliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xmliq <= 1.0, has value: " + String(MaterialStream2.xmliq, "g"));
 */
void Flowsheet_eqFunction_1878(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1878};
  modelica_boolean tmp134;
  modelica_boolean tmp135;
  static const MMC_DEFSTRINGLIT(tmp136,87,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xmliq <= 1.0, has value: ");
  modelica_string tmp137;
  static int tmp138 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp138)
  {
    tmp134 = GreaterEq(data->localData[0]->realVars[183] /* MaterialStream2._xmliq variable */,0.0);
    tmp135 = LessEq(data->localData[0]->realVars[183] /* MaterialStream2._xmliq variable */,1.0);
    if(!(tmp134 && tmp135))
    {
      tmp137 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[183] /* MaterialStream2._xmliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp136),tmp137);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",16,3,16,87,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xmliq >= 0.0 and MaterialStream2.xmliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp138 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1879
 type: ALGORITHM
 
   assert(MaterialStream2.xmvap >= 0.0 and MaterialStream2.xmvap <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xmvap <= 1.0, has value: " + String(MaterialStream2.xmvap, "g"));
 */
void Flowsheet_eqFunction_1879(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1879};
  modelica_boolean tmp139;
  modelica_boolean tmp140;
  static const MMC_DEFSTRINGLIT(tmp141,87,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xmvap <= 1.0, has value: ");
  modelica_string tmp142;
  static int tmp143 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp143)
  {
    tmp139 = GreaterEq(data->localData[0]->realVars[184] /* MaterialStream2._xmvap variable */,0.0);
    tmp140 = LessEq(data->localData[0]->realVars[184] /* MaterialStream2._xmvap variable */,1.0);
    if(!(tmp139 && tmp140))
    {
      tmp142 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[184] /* MaterialStream2._xmvap variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp141),tmp142);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",17,3,17,84,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xmvap >= 0.0 and MaterialStream2.xmvap <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp143 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1880
 type: ALGORITHM
 
   assert(MaterialStream2.F_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_p[2], has value: " + String(MaterialStream2.F_p[2], "g"));
 */
void Flowsheet_eqFunction_1880(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1880};
  modelica_boolean tmp144;
  static const MMC_DEFSTRINGLIT(tmp145,77,"Variable violating min constraint: 0.0 <= MaterialStream2.F_p[2], has value: ");
  modelica_string tmp146;
  static int tmp147 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp147)
  {
    tmp144 = GreaterEq(data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */,0.0);
    if(!tmp144)
    {
      tmp146 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[108] /* MaterialStream2._F_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp145),tmp146);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp147 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1881
 type: ALGORITHM
 
   assert(MaterialStream2.F_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_p[3], has value: " + String(MaterialStream2.F_p[3], "g"));
 */
void Flowsheet_eqFunction_1881(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1881};
  modelica_boolean tmp148;
  static const MMC_DEFSTRINGLIT(tmp149,77,"Variable violating min constraint: 0.0 <= MaterialStream2.F_p[3], has value: ");
  modelica_string tmp150;
  static int tmp151 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp151)
  {
    tmp148 = GreaterEq(data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */,0.0);
    if(!tmp148)
    {
      tmp150 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[109] /* MaterialStream2._F_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp149),tmp150);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp151 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1882
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[1], has value: " + String(MaterialStream2.Fm_p[1], "g"));
 */
void Flowsheet_eqFunction_1882(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1882};
  modelica_boolean tmp152;
  static const MMC_DEFSTRINGLIT(tmp153,78,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[1], has value: ");
  modelica_string tmp154;
  static int tmp155 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp155)
  {
    tmp152 = GreaterEq(data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */,0.0);
    if(!tmp152)
    {
      tmp154 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[116] /* MaterialStream2._Fm_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp153),tmp154);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp155 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1883
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[2], has value: " + String(MaterialStream2.Fm_p[2], "g"));
 */
void Flowsheet_eqFunction_1883(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1883};
  modelica_boolean tmp156;
  static const MMC_DEFSTRINGLIT(tmp157,78,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[2], has value: ");
  modelica_string tmp158;
  static int tmp159 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp159)
  {
    tmp156 = GreaterEq(data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */,0.0);
    if(!tmp156)
    {
      tmp158 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[117] /* MaterialStream2._Fm_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp157),tmp158);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp159 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1884
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[3], has value: " + String(MaterialStream2.Fm_p[3], "g"));
 */
void Flowsheet_eqFunction_1884(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1884};
  modelica_boolean tmp160;
  static const MMC_DEFSTRINGLIT(tmp161,78,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_p[3], has value: ");
  modelica_string tmp162;
  static int tmp163 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp163)
  {
    tmp160 = GreaterEq(data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */,0.0);
    if(!tmp160)
    {
      tmp162 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[118] /* MaterialStream2._Fm_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp161),tmp162);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp163 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1885
 type: ALGORITHM
 
   assert(MaterialStream2.MW_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[1], has value: " + String(MaterialStream2.MW_p[1], "g"));
 */
void Flowsheet_eqFunction_1885(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1885};
  modelica_boolean tmp164;
  static const MMC_DEFSTRINGLIT(tmp165,78,"Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[1], has value: ");
  modelica_string tmp166;
  static int tmp167 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp167)
  {
    tmp164 = GreaterEq(data->localData[0]->realVars[139] /* MaterialStream2._MW_p[1] variable */,0.0);
    if(!tmp164)
    {
      tmp166 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[139] /* MaterialStream2._MW_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp165),tmp166);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.MW_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp167 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1886
 type: ALGORITHM
 
   assert(MaterialStream2.MW_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[2], has value: " + String(MaterialStream2.MW_p[2], "g"));
 */
void Flowsheet_eqFunction_1886(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1886};
  modelica_boolean tmp168;
  static const MMC_DEFSTRINGLIT(tmp169,78,"Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[2], has value: ");
  modelica_string tmp170;
  static int tmp171 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp171)
  {
    tmp168 = GreaterEq(data->localData[0]->realVars[140] /* MaterialStream2._MW_p[2] variable */,0.0);
    if(!tmp168)
    {
      tmp170 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[140] /* MaterialStream2._MW_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp169),tmp170);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.MW_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp171 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1887
 type: ALGORITHM
 
   assert(MaterialStream2.MW_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[3], has value: " + String(MaterialStream2.MW_p[3], "g"));
 */
void Flowsheet_eqFunction_1887(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1887};
  modelica_boolean tmp172;
  static const MMC_DEFSTRINGLIT(tmp173,78,"Variable violating min constraint: 0.0 <= MaterialStream2.MW_p[3], has value: ");
  modelica_string tmp174;
  static int tmp175 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp175)
  {
    tmp172 = GreaterEq(data->localData[0]->realVars[141] /* MaterialStream2._MW_p[3] variable */,0.0);
    if(!tmp172)
    {
      tmp174 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[141] /* MaterialStream2._MW_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp173),tmp174);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.MW_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp175 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1888
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[2,1] >= 0.0 and MaterialStream2.x_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[2,1] <= 1.0, has value: " + String(MaterialStream2.x_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1888(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1888};
  modelica_boolean tmp176;
  modelica_boolean tmp177;
  static const MMC_DEFSTRINGLIT(tmp178,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp179;
  static int tmp180 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp180)
  {
    tmp176 = GreaterEq(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */,0.0);
    tmp177 = LessEq(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */,1.0);
    if(!(tmp176 && tmp177))
    {
      tmp179 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[172] /* MaterialStream2._x_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp178),tmp179);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[2,1] >= 0.0 and MaterialStream2.x_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp180 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1889
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[2,2] >= 0.0 and MaterialStream2.x_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[2,2] <= 1.0, has value: " + String(MaterialStream2.x_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1889(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1889};
  modelica_boolean tmp181;
  modelica_boolean tmp182;
  static const MMC_DEFSTRINGLIT(tmp183,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp184;
  static int tmp185 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp185)
  {
    tmp181 = GreaterEq(data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */,0.0);
    tmp182 = LessEq(data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */,1.0);
    if(!(tmp181 && tmp182))
    {
      tmp184 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[173] /* MaterialStream2._x_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp183),tmp184);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[2,2] >= 0.0 and MaterialStream2.x_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp185 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1890
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[3,1] >= 0.0 and MaterialStream2.x_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[3,1] <= 1.0, has value: " + String(MaterialStream2.x_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1890(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1890};
  modelica_boolean tmp186;
  modelica_boolean tmp187;
  static const MMC_DEFSTRINGLIT(tmp188,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp189;
  static int tmp190 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp190)
  {
    tmp186 = GreaterEq(data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */,0.0);
    tmp187 = LessEq(data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */,1.0);
    if(!(tmp186 && tmp187))
    {
      tmp189 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[174] /* MaterialStream2._x_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp188),tmp189);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[3,1] >= 0.0 and MaterialStream2.x_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp190 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1891
 type: ALGORITHM
 
   assert(MaterialStream2.x_pc[3,2] >= 0.0 and MaterialStream2.x_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[3,2] <= 1.0, has value: " + String(MaterialStream2.x_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1891(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1891};
  modelica_boolean tmp191;
  modelica_boolean tmp192;
  static const MMC_DEFSTRINGLIT(tmp193,91,"Variable violating min/max constraint: 0.0 <= MaterialStream2.x_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp194;
  static int tmp195 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp195)
  {
    tmp191 = GreaterEq(data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */,0.0);
    tmp192 = LessEq(data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */,1.0);
    if(!(tmp191 && tmp192))
    {
      tmp194 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[175] /* MaterialStream2._x_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp193),tmp194);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.x_pc[3,2] >= 0.0 and MaterialStream2.x_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp195 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1892
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[1,1] >= 0.0 and MaterialStream2.xm_pc[1,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[1,1] <= 1.0, has value: " + String(MaterialStream2.xm_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1892(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1892};
  modelica_boolean tmp196;
  modelica_boolean tmp197;
  static const MMC_DEFSTRINGLIT(tmp198,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[1,1] <= 1.0, has value: ");
  modelica_string tmp199;
  static int tmp200 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp200)
  {
    tmp196 = GreaterEq(data->localData[0]->realVars[177] /* MaterialStream2._xm_pc[1,1] variable */,0.0);
    tmp197 = LessEq(data->localData[0]->realVars[177] /* MaterialStream2._xm_pc[1,1] variable */,1.0);
    if(!(tmp196 && tmp197))
    {
      tmp199 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[177] /* MaterialStream2._xm_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp198),tmp199);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[1,1] >= 0.0 and MaterialStream2.xm_pc[1,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp200 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1893
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[1,2] >= 0.0 and MaterialStream2.xm_pc[1,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[1,2] <= 1.0, has value: " + String(MaterialStream2.xm_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1893(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1893};
  modelica_boolean tmp201;
  modelica_boolean tmp202;
  static const MMC_DEFSTRINGLIT(tmp203,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[1,2] <= 1.0, has value: ");
  modelica_string tmp204;
  static int tmp205 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp205)
  {
    tmp201 = GreaterEq(data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */,0.0);
    tmp202 = LessEq(data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */,1.0);
    if(!(tmp201 && tmp202))
    {
      tmp204 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[178] /* MaterialStream2._xm_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp203),tmp204);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[1,2] >= 0.0 and MaterialStream2.xm_pc[1,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp205 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1894
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[2,1] >= 0.0 and MaterialStream2.xm_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[2,1] <= 1.0, has value: " + String(MaterialStream2.xm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1894(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1894};
  modelica_boolean tmp206;
  modelica_boolean tmp207;
  static const MMC_DEFSTRINGLIT(tmp208,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp209;
  static int tmp210 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp210)
  {
    tmp206 = GreaterEq(data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[2,1] variable */,0.0);
    tmp207 = LessEq(data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[2,1] variable */,1.0);
    if(!(tmp206 && tmp207))
    {
      tmp209 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[179] /* MaterialStream2._xm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp208),tmp209);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[2,1] >= 0.0 and MaterialStream2.xm_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp210 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1895
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[2,2] >= 0.0 and MaterialStream2.xm_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[2,2] <= 1.0, has value: " + String(MaterialStream2.xm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1895(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1895};
  modelica_boolean tmp211;
  modelica_boolean tmp212;
  static const MMC_DEFSTRINGLIT(tmp213,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp214;
  static int tmp215 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp215)
  {
    tmp211 = GreaterEq(data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[2,2] variable */,0.0);
    tmp212 = LessEq(data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[2,2] variable */,1.0);
    if(!(tmp211 && tmp212))
    {
      tmp214 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[180] /* MaterialStream2._xm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp213),tmp214);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[2,2] >= 0.0 and MaterialStream2.xm_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp215 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1896
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[3,1] >= 0.0 and MaterialStream2.xm_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[3,1] <= 1.0, has value: " + String(MaterialStream2.xm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1896(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1896};
  modelica_boolean tmp216;
  modelica_boolean tmp217;
  static const MMC_DEFSTRINGLIT(tmp218,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp219;
  static int tmp220 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp220)
  {
    tmp216 = GreaterEq(data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[3,1] variable */,0.0);
    tmp217 = LessEq(data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[3,1] variable */,1.0);
    if(!(tmp216 && tmp217))
    {
      tmp219 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[181] /* MaterialStream2._xm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp218),tmp219);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[3,1] >= 0.0 and MaterialStream2.xm_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp220 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1897
 type: ALGORITHM
 
   assert(MaterialStream2.xm_pc[3,2] >= 0.0 and MaterialStream2.xm_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[3,2] <= 1.0, has value: " + String(MaterialStream2.xm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1897(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1897};
  modelica_boolean tmp221;
  modelica_boolean tmp222;
  static const MMC_DEFSTRINGLIT(tmp223,92,"Variable violating min/max constraint: 0.0 <= MaterialStream2.xm_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp224;
  static int tmp225 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp225)
  {
    tmp221 = GreaterEq(data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[3,2] variable */,0.0);
    tmp222 = LessEq(data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[3,2] variable */,1.0);
    if(!(tmp221 && tmp222))
    {
      tmp224 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[182] /* MaterialStream2._xm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp223),tmp224);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.xm_pc[3,2] >= 0.0 and MaterialStream2.xm_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp225 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1898
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[2,1], has value: " + String(MaterialStream2.F_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1898(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1898};
  modelica_boolean tmp226;
  static const MMC_DEFSTRINGLIT(tmp227,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[2,1], has value: ");
  modelica_string tmp228;
  static int tmp229 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp229)
  {
    tmp226 = GreaterEq(data->localData[0]->realVars[112] /* MaterialStream2._F_pc[2,1] variable */,0.0);
    if(!tmp226)
    {
      tmp228 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[112] /* MaterialStream2._F_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp227),tmp228);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp229 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1899
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[2,2], has value: " + String(MaterialStream2.F_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1899(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1899};
  modelica_boolean tmp230;
  static const MMC_DEFSTRINGLIT(tmp231,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[2,2], has value: ");
  modelica_string tmp232;
  static int tmp233 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp233)
  {
    tmp230 = GreaterEq(data->localData[0]->realVars[113] /* MaterialStream2._F_pc[2,2] variable */,0.0);
    if(!tmp230)
    {
      tmp232 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[113] /* MaterialStream2._F_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp231),tmp232);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp233 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1900
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[3,1], has value: " + String(MaterialStream2.F_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1900(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1900};
  modelica_boolean tmp234;
  static const MMC_DEFSTRINGLIT(tmp235,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[3,1], has value: ");
  modelica_string tmp236;
  static int tmp237 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp237)
  {
    tmp234 = GreaterEq(data->localData[0]->realVars[114] /* MaterialStream2._F_pc[3,1] variable */,0.0);
    if(!tmp234)
    {
      tmp236 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[114] /* MaterialStream2._F_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp235),tmp236);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp237 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1901
 type: ALGORITHM
 
   assert(MaterialStream2.F_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[3,2], has value: " + String(MaterialStream2.F_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1901(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1901};
  modelica_boolean tmp238;
  static const MMC_DEFSTRINGLIT(tmp239,80,"Variable violating min constraint: 0.0 <= MaterialStream2.F_pc[3,2], has value: ");
  modelica_string tmp240;
  static int tmp241 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp241)
  {
    tmp238 = GreaterEq(data->localData[0]->realVars[115] /* MaterialStream2._F_pc[3,2] variable */,0.0);
    if(!tmp238)
    {
      tmp240 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[115] /* MaterialStream2._F_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp239),tmp240);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.F_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp241 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1902
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[2,1], has value: " + String(MaterialStream2.Fm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1902(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1902};
  modelica_boolean tmp242;
  static const MMC_DEFSTRINGLIT(tmp243,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[2,1], has value: ");
  modelica_string tmp244;
  static int tmp245 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp245)
  {
    tmp242 = GreaterEq(data->localData[0]->realVars[121] /* MaterialStream2._Fm_pc[2,1] variable */,0.0);
    if(!tmp242)
    {
      tmp244 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[121] /* MaterialStream2._Fm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp243),tmp244);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp245 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1903
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[2,2], has value: " + String(MaterialStream2.Fm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1903(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1903};
  modelica_boolean tmp246;
  static const MMC_DEFSTRINGLIT(tmp247,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[2,2], has value: ");
  modelica_string tmp248;
  static int tmp249 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp249)
  {
    tmp246 = GreaterEq(data->localData[0]->realVars[122] /* MaterialStream2._Fm_pc[2,2] variable */,0.0);
    if(!tmp246)
    {
      tmp248 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[122] /* MaterialStream2._Fm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp247),tmp248);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp249 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1904
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[3,1], has value: " + String(MaterialStream2.Fm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1904(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1904};
  modelica_boolean tmp250;
  static const MMC_DEFSTRINGLIT(tmp251,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[3,1], has value: ");
  modelica_string tmp252;
  static int tmp253 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp253)
  {
    tmp250 = GreaterEq(data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[3,1] variable */,0.0);
    if(!tmp250)
    {
      tmp252 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[123] /* MaterialStream2._Fm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp251),tmp252);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp253 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1905
 type: ALGORITHM
 
   assert(MaterialStream2.Fm_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[3,2], has value: " + String(MaterialStream2.Fm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1905(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1905};
  modelica_boolean tmp254;
  static const MMC_DEFSTRINGLIT(tmp255,81,"Variable violating min constraint: 0.0 <= MaterialStream2.Fm_pc[3,2], has value: ");
  modelica_string tmp256;
  static int tmp257 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp257)
  {
    tmp254 = GreaterEq(data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[3,2] variable */,0.0);
    if(!tmp254)
    {
      tmp256 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[124] /* MaterialStream2._Fm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp255),tmp256);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream2.Fm_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp257 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1906
 type: ALGORITHM
 
   assert(Mixer1.xvapin_s[1] >= 0.0 and Mixer1.xvapin_s[1] <= 1.0, "Variable violating min/max constraint: 0.0 <= Mixer1.xvapin_s[1] <= 1.0, has value: " + String(Mixer1.xvapin_s[1], "g"));
 */
void Flowsheet_eqFunction_1906(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1906};
  modelica_boolean tmp258;
  modelica_boolean tmp259;
  static const MMC_DEFSTRINGLIT(tmp260,84,"Variable violating min/max constraint: 0.0 <= Mixer1.xvapin_s[1] <= 1.0, has value: ");
  modelica_string tmp261;
  static int tmp262 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp262)
  {
    tmp258 = GreaterEq(data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */,0.0);
    tmp259 = LessEq(data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */,1.0);
    if(!(tmp258 && tmp259))
    {
      tmp261 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[276] /* Mixer1._xvapin_s[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp260),tmp261);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/UnitOperations/Mixer.mo",16,3,16,125,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMixer1.xvapin_s[1] >= 0.0 and Mixer1.xvapin_s[1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp262 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1907
 type: ALGORITHM
 
   assert(Mixer1.xvapin_s[2] >= 0.0 and Mixer1.xvapin_s[2] <= 1.0, "Variable violating min/max constraint: 0.0 <= Mixer1.xvapin_s[2] <= 1.0, has value: " + String(Mixer1.xvapin_s[2], "g"));
 */
void Flowsheet_eqFunction_1907(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1907};
  modelica_boolean tmp263;
  modelica_boolean tmp264;
  static const MMC_DEFSTRINGLIT(tmp265,84,"Variable violating min/max constraint: 0.0 <= Mixer1.xvapin_s[2] <= 1.0, has value: ");
  modelica_string tmp266;
  static int tmp267 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp267)
  {
    tmp263 = GreaterEq(data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */,0.0);
    tmp264 = LessEq(data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */,1.0);
    if(!(tmp263 && tmp264))
    {
      tmp266 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[277] /* Mixer1._xvapin_s[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp265),tmp266);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/UnitOperations/Mixer.mo",16,3,16,125,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMixer1.xvapin_s[2] >= 0.0 and Mixer1.xvapin_s[2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp267 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1908
 type: ALGORITHM
 
   assert(MaterialStream3.T >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.T, has value: " + String(MaterialStream3.T, "g"));
 */
void Flowsheet_eqFunction_1908(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1908};
  modelica_boolean tmp268;
  static const MMC_DEFSTRINGLIT(tmp269,72,"Variable violating min constraint: 0.0 <= MaterialStream3.T, has value: ");
  modelica_string tmp270;
  static int tmp271 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp271)
  {
    tmp268 = GreaterEq(data->localData[0]->realVars[249] /* MaterialStream3._T variable */,0.0);
    if(!tmp268)
    {
      tmp270 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[249] /* MaterialStream3._T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp269),tmp270);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",11,3,11,47,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp271 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1909
 type: ALGORITHM
 
   assert(MaterialStream3.Pbubl >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Pbubl, has value: " + String(MaterialStream3.Pbubl, "g"));
 */
void Flowsheet_eqFunction_1909(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1909};
  modelica_boolean tmp272;
  static const MMC_DEFSTRINGLIT(tmp273,76,"Variable violating min constraint: 0.0 <= MaterialStream3.Pbubl, has value: ");
  modelica_string tmp274;
  static int tmp275 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp275)
  {
    tmp272 = GreaterEq(data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */,0.0);
    if(!tmp272)
    {
      tmp274 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp273),tmp274);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",12,3,12,73,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Pbubl >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp275 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1910
 type: ALGORITHM
 
   assert(MaterialStream3.Pdew >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Pdew, has value: " + String(MaterialStream3.Pdew, "g"));
 */
void Flowsheet_eqFunction_1910(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1910};
  modelica_boolean tmp276;
  static const MMC_DEFSTRINGLIT(tmp277,75,"Variable violating min constraint: 0.0 <= MaterialStream3.Pdew, has value: ");
  modelica_string tmp278;
  static int tmp279 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp279)
  {
    tmp276 = GreaterEq(data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */,0.0);
    if(!tmp276)
    {
      tmp278 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp277),tmp278);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",13,3,13,69,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Pdew >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp279 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1911
 type: ALGORITHM
 
   assert(MaterialStream3.xliq >= 0.0 and MaterialStream3.xliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xliq <= 1.0, has value: " + String(MaterialStream3.xliq, "g"));
 */
void Flowsheet_eqFunction_1911(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1911};
  modelica_boolean tmp280;
  modelica_boolean tmp281;
  static const MMC_DEFSTRINGLIT(tmp282,86,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xliq <= 1.0, has value: ");
  modelica_string tmp283;
  static int tmp284 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp284)
  {
    tmp280 = GreaterEq(data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */,0.0);
    tmp281 = LessEq(data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */,1.0);
    if(!(tmp280 && tmp281))
    {
      tmp283 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[266] /* MaterialStream3._xliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp282),tmp283);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",14,3,14,86,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xliq >= 0.0 and MaterialStream3.xliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp284 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1912
 type: ALGORITHM
 
   assert(MaterialStream3.xvap >= 0.0 and MaterialStream3.xvap <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xvap <= 1.0, has value: " + String(MaterialStream3.xvap, "g"));
 */
void Flowsheet_eqFunction_1912(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1912};
  modelica_boolean tmp285;
  modelica_boolean tmp286;
  static const MMC_DEFSTRINGLIT(tmp287,86,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xvap <= 1.0, has value: ");
  modelica_string tmp288;
  static int tmp289 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp289)
  {
    tmp285 = GreaterEq(data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */,0.0);
    tmp286 = LessEq(data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */,1.0);
    if(!(tmp285 && tmp286))
    {
      tmp288 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[275] /* MaterialStream3._xvap variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp287),tmp288);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",15,3,15,85,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xvap >= 0.0 and MaterialStream3.xvap <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp289 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1913
 type: ALGORITHM
 
   assert(MaterialStream3.xmliq >= 0.0 and MaterialStream3.xmliq <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xmliq <= 1.0, has value: " + String(MaterialStream3.xmliq, "g"));
 */
void Flowsheet_eqFunction_1913(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1913};
  modelica_boolean tmp290;
  modelica_boolean tmp291;
  static const MMC_DEFSTRINGLIT(tmp292,87,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xmliq <= 1.0, has value: ");
  modelica_string tmp293;
  static int tmp294 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp294)
  {
    tmp290 = GreaterEq(data->localData[0]->realVars[273] /* MaterialStream3._xmliq variable */,0.0);
    tmp291 = LessEq(data->localData[0]->realVars[273] /* MaterialStream3._xmliq variable */,1.0);
    if(!(tmp290 && tmp291))
    {
      tmp293 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[273] /* MaterialStream3._xmliq variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp292),tmp293);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",16,3,16,87,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xmliq >= 0.0 and MaterialStream3.xmliq <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp294 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1914
 type: ALGORITHM
 
   assert(MaterialStream3.xmvap >= 0.0 and MaterialStream3.xmvap <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xmvap <= 1.0, has value: " + String(MaterialStream3.xmvap, "g"));
 */
void Flowsheet_eqFunction_1914(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1914};
  modelica_boolean tmp295;
  modelica_boolean tmp296;
  static const MMC_DEFSTRINGLIT(tmp297,87,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xmvap <= 1.0, has value: ");
  modelica_string tmp298;
  static int tmp299 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp299)
  {
    tmp295 = GreaterEq(data->localData[0]->realVars[274] /* MaterialStream3._xmvap variable */,0.0);
    tmp296 = LessEq(data->localData[0]->realVars[274] /* MaterialStream3._xmvap variable */,1.0);
    if(!(tmp295 && tmp296))
    {
      tmp298 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[274] /* MaterialStream3._xmvap variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp297),tmp298);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",17,3,17,84,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xmvap >= 0.0 and MaterialStream3.xmvap <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp299 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1915
 type: ALGORITHM
 
   assert(MaterialStream3.F_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.F_p[2], has value: " + String(MaterialStream3.F_p[2], "g"));
 */
void Flowsheet_eqFunction_1915(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1915};
  modelica_boolean tmp300;
  static const MMC_DEFSTRINGLIT(tmp301,77,"Variable violating min constraint: 0.0 <= MaterialStream3.F_p[2], has value: ");
  modelica_string tmp302;
  static int tmp303 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp303)
  {
    tmp300 = GreaterEq(data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */,0.0);
    if(!tmp300)
    {
      tmp302 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[198] /* MaterialStream3._F_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp301),tmp302);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.F_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp303 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1916
 type: ALGORITHM
 
   assert(MaterialStream3.F_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.F_p[3], has value: " + String(MaterialStream3.F_p[3], "g"));
 */
void Flowsheet_eqFunction_1916(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1916};
  modelica_boolean tmp304;
  static const MMC_DEFSTRINGLIT(tmp305,77,"Variable violating min constraint: 0.0 <= MaterialStream3.F_p[3], has value: ");
  modelica_string tmp306;
  static int tmp307 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp307)
  {
    tmp304 = GreaterEq(data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */,0.0);
    if(!tmp304)
    {
      tmp306 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[199] /* MaterialStream3._F_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp305),tmp306);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",18,3,18,101,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.F_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp307 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1917
 type: ALGORITHM
 
   assert(MaterialStream3.Fm_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Fm_p[1], has value: " + String(MaterialStream3.Fm_p[1], "g"));
 */
void Flowsheet_eqFunction_1917(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1917};
  modelica_boolean tmp308;
  static const MMC_DEFSTRINGLIT(tmp309,78,"Variable violating min constraint: 0.0 <= MaterialStream3.Fm_p[1], has value: ");
  modelica_string tmp310;
  static int tmp311 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp311)
  {
    tmp308 = GreaterEq(data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */,0.0);
    if(!tmp308)
    {
      tmp310 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[206] /* MaterialStream3._Fm_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp309),tmp310);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Fm_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp311 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1918
 type: ALGORITHM
 
   assert(MaterialStream3.Fm_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Fm_p[2], has value: " + String(MaterialStream3.Fm_p[2], "g"));
 */
void Flowsheet_eqFunction_1918(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1918};
  modelica_boolean tmp312;
  static const MMC_DEFSTRINGLIT(tmp313,78,"Variable violating min constraint: 0.0 <= MaterialStream3.Fm_p[2], has value: ");
  modelica_string tmp314;
  static int tmp315 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp315)
  {
    tmp312 = GreaterEq(data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */,0.0);
    if(!tmp312)
    {
      tmp314 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[207] /* MaterialStream3._Fm_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp313),tmp314);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Fm_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp315 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1919
 type: ALGORITHM
 
   assert(MaterialStream3.Fm_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Fm_p[3], has value: " + String(MaterialStream3.Fm_p[3], "g"));
 */
void Flowsheet_eqFunction_1919(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1919};
  modelica_boolean tmp316;
  static const MMC_DEFSTRINGLIT(tmp317,78,"Variable violating min constraint: 0.0 <= MaterialStream3.Fm_p[3], has value: ");
  modelica_string tmp318;
  static int tmp319 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp319)
  {
    tmp316 = GreaterEq(data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */,0.0);
    if(!tmp316)
    {
      tmp318 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[208] /* MaterialStream3._Fm_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp317),tmp318);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",19,3,19,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Fm_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp319 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1920
 type: ALGORITHM
 
   assert(MaterialStream3.MW_p[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.MW_p[1], has value: " + String(MaterialStream3.MW_p[1], "g"));
 */
void Flowsheet_eqFunction_1920(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1920};
  modelica_boolean tmp320;
  static const MMC_DEFSTRINGLIT(tmp321,78,"Variable violating min constraint: 0.0 <= MaterialStream3.MW_p[1], has value: ");
  modelica_string tmp322;
  static int tmp323 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp323)
  {
    tmp320 = GreaterEq(data->localData[0]->realVars[229] /* MaterialStream3._MW_p[1] variable */,0.0);
    if(!tmp320)
    {
      tmp322 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[229] /* MaterialStream3._MW_p[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp321),tmp322);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.MW_p[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp323 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1921
 type: ALGORITHM
 
   assert(MaterialStream3.MW_p[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.MW_p[2], has value: " + String(MaterialStream3.MW_p[2], "g"));
 */
void Flowsheet_eqFunction_1921(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1921};
  modelica_boolean tmp324;
  static const MMC_DEFSTRINGLIT(tmp325,78,"Variable violating min constraint: 0.0 <= MaterialStream3.MW_p[2], has value: ");
  modelica_string tmp326;
  static int tmp327 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp327)
  {
    tmp324 = GreaterEq(data->localData[0]->realVars[230] /* MaterialStream3._MW_p[2] variable */,0.0);
    if(!tmp324)
    {
      tmp326 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[230] /* MaterialStream3._MW_p[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp325),tmp326);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.MW_p[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp327 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1922
 type: ALGORITHM
 
   assert(MaterialStream3.MW_p[3] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.MW_p[3], has value: " + String(MaterialStream3.MW_p[3], "g"));
 */
void Flowsheet_eqFunction_1922(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1922};
  modelica_boolean tmp328;
  static const MMC_DEFSTRINGLIT(tmp329,78,"Variable violating min constraint: 0.0 <= MaterialStream3.MW_p[3], has value: ");
  modelica_string tmp330;
  static int tmp331 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp331)
  {
    tmp328 = GreaterEq(data->localData[0]->realVars[231] /* MaterialStream3._MW_p[3] variable */,0.0);
    if(!tmp328)
    {
      tmp330 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[231] /* MaterialStream3._MW_p[3] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp329),tmp330);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",20,3,20,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.MW_p[3] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp331 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1923
 type: ALGORITHM
 
   assert(MaterialStream3.x_pc[2,1] >= 0.0 and MaterialStream3.x_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.x_pc[2,1] <= 1.0, has value: " + String(MaterialStream3.x_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1923(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1923};
  modelica_boolean tmp332;
  modelica_boolean tmp333;
  static const MMC_DEFSTRINGLIT(tmp334,91,"Variable violating min/max constraint: 0.0 <= MaterialStream3.x_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp335;
  static int tmp336 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp336)
  {
    tmp332 = GreaterEq(data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */,0.0);
    tmp333 = LessEq(data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */,1.0);
    if(!(tmp332 && tmp333))
    {
      tmp335 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[262] /* MaterialStream3._x_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp334),tmp335);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.x_pc[2,1] >= 0.0 and MaterialStream3.x_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp336 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1924
 type: ALGORITHM
 
   assert(MaterialStream3.x_pc[2,2] >= 0.0 and MaterialStream3.x_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.x_pc[2,2] <= 1.0, has value: " + String(MaterialStream3.x_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1924(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1924};
  modelica_boolean tmp337;
  modelica_boolean tmp338;
  static const MMC_DEFSTRINGLIT(tmp339,91,"Variable violating min/max constraint: 0.0 <= MaterialStream3.x_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp340;
  static int tmp341 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp341)
  {
    tmp337 = GreaterEq(data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */,0.0);
    tmp338 = LessEq(data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */,1.0);
    if(!(tmp337 && tmp338))
    {
      tmp340 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[263] /* MaterialStream3._x_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp339),tmp340);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.x_pc[2,2] >= 0.0 and MaterialStream3.x_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp341 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1925
 type: ALGORITHM
 
   assert(MaterialStream3.x_pc[3,1] >= 0.0 and MaterialStream3.x_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.x_pc[3,1] <= 1.0, has value: " + String(MaterialStream3.x_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1925(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1925};
  modelica_boolean tmp342;
  modelica_boolean tmp343;
  static const MMC_DEFSTRINGLIT(tmp344,91,"Variable violating min/max constraint: 0.0 <= MaterialStream3.x_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp345;
  static int tmp346 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp346)
  {
    tmp342 = GreaterEq(data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */,0.0);
    tmp343 = LessEq(data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */,1.0);
    if(!(tmp342 && tmp343))
    {
      tmp345 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[264] /* MaterialStream3._x_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp344),tmp345);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.x_pc[3,1] >= 0.0 and MaterialStream3.x_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp346 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1926
 type: ALGORITHM
 
   assert(MaterialStream3.x_pc[3,2] >= 0.0 and MaterialStream3.x_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.x_pc[3,2] <= 1.0, has value: " + String(MaterialStream3.x_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1926(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1926};
  modelica_boolean tmp347;
  modelica_boolean tmp348;
  static const MMC_DEFSTRINGLIT(tmp349,91,"Variable violating min/max constraint: 0.0 <= MaterialStream3.x_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp350;
  static int tmp351 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp351)
  {
    tmp347 = GreaterEq(data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */,0.0);
    tmp348 = LessEq(data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */,1.0);
    if(!(tmp347 && tmp348))
    {
      tmp350 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[265] /* MaterialStream3._x_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp349),tmp350);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",21,3,21,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.x_pc[3,2] >= 0.0 and MaterialStream3.x_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp351 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1927
 type: ALGORITHM
 
   assert(MaterialStream3.xm_pc[1,1] >= 0.0 and MaterialStream3.xm_pc[1,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[1,1] <= 1.0, has value: " + String(MaterialStream3.xm_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1927(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1927};
  modelica_boolean tmp352;
  modelica_boolean tmp353;
  static const MMC_DEFSTRINGLIT(tmp354,92,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[1,1] <= 1.0, has value: ");
  modelica_string tmp355;
  static int tmp356 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp356)
  {
    tmp352 = GreaterEq(data->localData[0]->realVars[267] /* MaterialStream3._xm_pc[1,1] variable */,0.0);
    tmp353 = LessEq(data->localData[0]->realVars[267] /* MaterialStream3._xm_pc[1,1] variable */,1.0);
    if(!(tmp352 && tmp353))
    {
      tmp355 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[267] /* MaterialStream3._xm_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp354),tmp355);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xm_pc[1,1] >= 0.0 and MaterialStream3.xm_pc[1,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp356 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1928
 type: ALGORITHM
 
   assert(MaterialStream3.xm_pc[1,2] >= 0.0 and MaterialStream3.xm_pc[1,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[1,2] <= 1.0, has value: " + String(MaterialStream3.xm_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1928(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1928};
  modelica_boolean tmp357;
  modelica_boolean tmp358;
  static const MMC_DEFSTRINGLIT(tmp359,92,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[1,2] <= 1.0, has value: ");
  modelica_string tmp360;
  static int tmp361 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp361)
  {
    tmp357 = GreaterEq(data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */,0.0);
    tmp358 = LessEq(data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */,1.0);
    if(!(tmp357 && tmp358))
    {
      tmp360 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[268] /* MaterialStream3._xm_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp359),tmp360);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xm_pc[1,2] >= 0.0 and MaterialStream3.xm_pc[1,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp361 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1929
 type: ALGORITHM
 
   assert(MaterialStream3.xm_pc[2,1] >= 0.0 and MaterialStream3.xm_pc[2,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[2,1] <= 1.0, has value: " + String(MaterialStream3.xm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1929(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1929};
  modelica_boolean tmp362;
  modelica_boolean tmp363;
  static const MMC_DEFSTRINGLIT(tmp364,92,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[2,1] <= 1.0, has value: ");
  modelica_string tmp365;
  static int tmp366 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp366)
  {
    tmp362 = GreaterEq(data->localData[0]->realVars[269] /* MaterialStream3._xm_pc[2,1] variable */,0.0);
    tmp363 = LessEq(data->localData[0]->realVars[269] /* MaterialStream3._xm_pc[2,1] variable */,1.0);
    if(!(tmp362 && tmp363))
    {
      tmp365 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[269] /* MaterialStream3._xm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp364),tmp365);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xm_pc[2,1] >= 0.0 and MaterialStream3.xm_pc[2,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp366 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1930
 type: ALGORITHM
 
   assert(MaterialStream3.xm_pc[2,2] >= 0.0 and MaterialStream3.xm_pc[2,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[2,2] <= 1.0, has value: " + String(MaterialStream3.xm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1930(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1930};
  modelica_boolean tmp367;
  modelica_boolean tmp368;
  static const MMC_DEFSTRINGLIT(tmp369,92,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[2,2] <= 1.0, has value: ");
  modelica_string tmp370;
  static int tmp371 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp371)
  {
    tmp367 = GreaterEq(data->localData[0]->realVars[270] /* MaterialStream3._xm_pc[2,2] variable */,0.0);
    tmp368 = LessEq(data->localData[0]->realVars[270] /* MaterialStream3._xm_pc[2,2] variable */,1.0);
    if(!(tmp367 && tmp368))
    {
      tmp370 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[270] /* MaterialStream3._xm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp369),tmp370);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xm_pc[2,2] >= 0.0 and MaterialStream3.xm_pc[2,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp371 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1931
 type: ALGORITHM
 
   assert(MaterialStream3.xm_pc[3,1] >= 0.0 and MaterialStream3.xm_pc[3,1] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[3,1] <= 1.0, has value: " + String(MaterialStream3.xm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1931(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1931};
  modelica_boolean tmp372;
  modelica_boolean tmp373;
  static const MMC_DEFSTRINGLIT(tmp374,92,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[3,1] <= 1.0, has value: ");
  modelica_string tmp375;
  static int tmp376 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp376)
  {
    tmp372 = GreaterEq(data->localData[0]->realVars[271] /* MaterialStream3._xm_pc[3,1] variable */,0.0);
    tmp373 = LessEq(data->localData[0]->realVars[271] /* MaterialStream3._xm_pc[3,1] variable */,1.0);
    if(!(tmp372 && tmp373))
    {
      tmp375 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[271] /* MaterialStream3._xm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp374),tmp375);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xm_pc[3,1] >= 0.0 and MaterialStream3.xm_pc[3,1] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp376 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1932
 type: ALGORITHM
 
   assert(MaterialStream3.xm_pc[3,2] >= 0.0 and MaterialStream3.xm_pc[3,2] <= 1.0, "Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[3,2] <= 1.0, has value: " + String(MaterialStream3.xm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1932(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1932};
  modelica_boolean tmp377;
  modelica_boolean tmp378;
  static const MMC_DEFSTRINGLIT(tmp379,92,"Variable violating min/max constraint: 0.0 <= MaterialStream3.xm_pc[3,2] <= 1.0, has value: ");
  modelica_string tmp380;
  static int tmp381 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp381)
  {
    tmp377 = GreaterEq(data->localData[0]->realVars[272] /* MaterialStream3._xm_pc[3,2] variable */,0.0);
    tmp378 = LessEq(data->localData[0]->realVars[272] /* MaterialStream3._xm_pc[3,2] variable */,1.0);
    if(!(tmp377 && tmp378))
    {
      tmp380 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[272] /* MaterialStream3._xm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp379),tmp380);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",22,3,22,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.xm_pc[3,2] >= 0.0 and MaterialStream3.xm_pc[3,2] <= 1.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp381 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1933
 type: ALGORITHM
 
   assert(MaterialStream3.F_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[2,1], has value: " + String(MaterialStream3.F_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1933(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1933};
  modelica_boolean tmp382;
  static const MMC_DEFSTRINGLIT(tmp383,80,"Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[2,1], has value: ");
  modelica_string tmp384;
  static int tmp385 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp385)
  {
    tmp382 = GreaterEq(data->localData[0]->realVars[202] /* MaterialStream3._F_pc[2,1] variable */,0.0);
    if(!tmp382)
    {
      tmp384 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[202] /* MaterialStream3._F_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp383),tmp384);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.F_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp385 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1934
 type: ALGORITHM
 
   assert(MaterialStream3.F_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[2,2], has value: " + String(MaterialStream3.F_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1934(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1934};
  modelica_boolean tmp386;
  static const MMC_DEFSTRINGLIT(tmp387,80,"Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[2,2], has value: ");
  modelica_string tmp388;
  static int tmp389 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp389)
  {
    tmp386 = GreaterEq(data->localData[0]->realVars[203] /* MaterialStream3._F_pc[2,2] variable */,0.0);
    if(!tmp386)
    {
      tmp388 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[203] /* MaterialStream3._F_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp387),tmp388);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.F_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp389 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1935
 type: ALGORITHM
 
   assert(MaterialStream3.F_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[3,1], has value: " + String(MaterialStream3.F_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1935(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1935};
  modelica_boolean tmp390;
  static const MMC_DEFSTRINGLIT(tmp391,80,"Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[3,1], has value: ");
  modelica_string tmp392;
  static int tmp393 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp393)
  {
    tmp390 = GreaterEq(data->localData[0]->realVars[204] /* MaterialStream3._F_pc[3,1] variable */,0.0);
    if(!tmp390)
    {
      tmp392 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[204] /* MaterialStream3._F_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp391),tmp392);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.F_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp393 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1936
 type: ALGORITHM
 
   assert(MaterialStream3.F_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[3,2], has value: " + String(MaterialStream3.F_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1936(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1936};
  modelica_boolean tmp394;
  static const MMC_DEFSTRINGLIT(tmp395,80,"Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[3,2], has value: ");
  modelica_string tmp396;
  static int tmp397 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp397)
  {
    tmp394 = GreaterEq(data->localData[0]->realVars[205] /* MaterialStream3._F_pc[3,2] variable */,0.0);
    if(!tmp394)
    {
      tmp396 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[205] /* MaterialStream3._F_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp395),tmp396);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.F_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp397 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1937
 type: ALGORITHM
 
   assert(MaterialStream3.Fm_pc[2,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[2,1], has value: " + String(MaterialStream3.Fm_pc[2,1], "g"));
 */
void Flowsheet_eqFunction_1937(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1937};
  modelica_boolean tmp398;
  static const MMC_DEFSTRINGLIT(tmp399,81,"Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[2,1], has value: ");
  modelica_string tmp400;
  static int tmp401 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp401)
  {
    tmp398 = GreaterEq(data->localData[0]->realVars[211] /* MaterialStream3._Fm_pc[2,1] variable */,0.0);
    if(!tmp398)
    {
      tmp400 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[211] /* MaterialStream3._Fm_pc[2,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp399),tmp400);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Fm_pc[2,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp401 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1938
 type: ALGORITHM
 
   assert(MaterialStream3.Fm_pc[2,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[2,2], has value: " + String(MaterialStream3.Fm_pc[2,2], "g"));
 */
void Flowsheet_eqFunction_1938(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1938};
  modelica_boolean tmp402;
  static const MMC_DEFSTRINGLIT(tmp403,81,"Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[2,2], has value: ");
  modelica_string tmp404;
  static int tmp405 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp405)
  {
    tmp402 = GreaterEq(data->localData[0]->realVars[212] /* MaterialStream3._Fm_pc[2,2] variable */,0.0);
    if(!tmp402)
    {
      tmp404 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[212] /* MaterialStream3._Fm_pc[2,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp403),tmp404);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Fm_pc[2,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp405 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1939
 type: ALGORITHM
 
   assert(MaterialStream3.Fm_pc[3,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[3,1], has value: " + String(MaterialStream3.Fm_pc[3,1], "g"));
 */
void Flowsheet_eqFunction_1939(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1939};
  modelica_boolean tmp406;
  static const MMC_DEFSTRINGLIT(tmp407,81,"Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[3,1], has value: ");
  modelica_string tmp408;
  static int tmp409 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp409)
  {
    tmp406 = GreaterEq(data->localData[0]->realVars[213] /* MaterialStream3._Fm_pc[3,1] variable */,0.0);
    if(!tmp406)
    {
      tmp408 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[213] /* MaterialStream3._Fm_pc[3,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp407),tmp408);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Fm_pc[3,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp409 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1940
 type: ALGORITHM
 
   assert(MaterialStream3.Fm_pc[3,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[3,2], has value: " + String(MaterialStream3.Fm_pc[3,2], "g"));
 */
void Flowsheet_eqFunction_1940(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1940};
  modelica_boolean tmp410;
  static const MMC_DEFSTRINGLIT(tmp411,81,"Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[3,2], has value: ");
  modelica_string tmp412;
  static int tmp413 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp413)
  {
    tmp410 = GreaterEq(data->localData[0]->realVars[214] /* MaterialStream3._Fm_pc[3,2] variable */,0.0);
    if(!tmp410)
    {
      tmp412 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[214] /* MaterialStream3._Fm_pc[3,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp411),tmp412);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Fm_pc[3,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp413 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1941
 type: ALGORITHM
 
   assert(MaterialStream3.K_c[1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.K_c[1], has value: " + String(MaterialStream3.K_c[1], "g"));
 */
void Flowsheet_eqFunction_1941(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1941};
  modelica_boolean tmp414;
  static const MMC_DEFSTRINGLIT(tmp415,77,"Variable violating min constraint: 0.0 <= MaterialStream3.K_c[1], has value: ");
  modelica_string tmp416;
  static int tmp417 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp417)
  {
    tmp414 = GreaterEq(data->localData[0]->realVars[227] /* MaterialStream3._K_c[1] variable */,0.0);
    if(!tmp414)
    {
      tmp416 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[227] /* MaterialStream3._K_c[1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp415),tmp416);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Files/ThermodynamicPackages/RaoultsLaw.mo",5,5,5,65,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.K_c[1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp417 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1942
 type: ALGORITHM
 
   assert(MaterialStream3.K_c[2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.K_c[2], has value: " + String(MaterialStream3.K_c[2], "g"));
 */
void Flowsheet_eqFunction_1942(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1942};
  modelica_boolean tmp418;
  static const MMC_DEFSTRINGLIT(tmp419,77,"Variable violating min constraint: 0.0 <= MaterialStream3.K_c[2], has value: ");
  modelica_string tmp420;
  static int tmp421 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp421)
  {
    tmp418 = GreaterEq(data->localData[0]->realVars[228] /* MaterialStream3._K_c[2] variable */,0.0);
    if(!tmp418)
    {
      tmp420 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[228] /* MaterialStream3._K_c[2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp419),tmp420);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Files/ThermodynamicPackages/RaoultsLaw.mo",5,5,5,65,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.K_c[2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp421 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1847
 type: ALGORITHM
 
   assert(MaterialStream3.Fm_pc[1,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[1,1], has value: " + String(MaterialStream3.Fm_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1847(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1847};
  modelica_boolean tmp422;
  static const MMC_DEFSTRINGLIT(tmp423,81,"Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[1,1], has value: ");
  modelica_string tmp424;
  static int tmp425 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp425)
  {
    tmp422 = GreaterEq(data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */,0.0);
    if(!tmp422)
    {
      tmp424 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[209] /* MaterialStream3._Fm_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp423),tmp424);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Fm_pc[1,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp425 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1846
 type: ALGORITHM
 
   assert(MaterialStream3.F_pc[1,1] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[1,1], has value: " + String(MaterialStream3.F_pc[1,1], "g"));
 */
void Flowsheet_eqFunction_1846(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1846};
  modelica_boolean tmp426;
  static const MMC_DEFSTRINGLIT(tmp427,80,"Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[1,1], has value: ");
  modelica_string tmp428;
  static int tmp429 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp429)
  {
    tmp426 = GreaterEq(data->localData[0]->realVars[200] /* MaterialStream3._F_pc[1,1] variable */,0.0);
    if(!tmp426)
    {
      tmp428 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[200] /* MaterialStream3._F_pc[1,1] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp427),tmp428);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.F_pc[1,1] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp429 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1845
 type: ALGORITHM
 
   assert(MaterialStream3.Fm_pc[1,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[1,2], has value: " + String(MaterialStream3.Fm_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1845(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1845};
  modelica_boolean tmp430;
  static const MMC_DEFSTRINGLIT(tmp431,81,"Variable violating min constraint: 0.0 <= MaterialStream3.Fm_pc[1,2], has value: ");
  modelica_string tmp432;
  static int tmp433 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp433)
  {
    tmp430 = GreaterEq(data->localData[0]->realVars[210] /* MaterialStream3._Fm_pc[1,2] variable */,0.0);
    if(!tmp430)
    {
      tmp432 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[210] /* MaterialStream3._Fm_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp431),tmp432);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",24,3,24,102,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.Fm_pc[1,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp433 = 1;
    }
  }
  TRACE_POP
}

/*
 equation index: 1844
 type: ALGORITHM
 
   assert(MaterialStream3.F_pc[1,2] >= 0.0, "Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[1,2], has value: " + String(MaterialStream3.F_pc[1,2], "g"));
 */
void Flowsheet_eqFunction_1844(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1844};
  modelica_boolean tmp434;
  static const MMC_DEFSTRINGLIT(tmp435,80,"Variable violating min constraint: 0.0 <= MaterialStream3.F_pc[1,2], has value: ");
  modelica_string tmp436;
  static int tmp437 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp437)
  {
    tmp434 = GreaterEq(data->localData[0]->realVars[201] /* MaterialStream3._F_pc[1,2] variable */,0.0);
    if(!tmp434)
    {
      tmp436 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[201] /* MaterialStream3._F_pc[1,2] variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp435),tmp436);
      {
        FILE_INFO info = {"C:/Users/thant/OneDrive/Desktop/IITB Capstone/Main Project/Chemical-Simulator-GUI/src/main/Simulator/Simulator/Streams/MaterialStream.mo",23,3,23,103,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nMaterialStream3.F_pc[1,2] >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp437 = 1;
    }
  }
  TRACE_POP
}
/* function to check assert after a step is done */
int Flowsheet_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  Flowsheet_eqFunction_1848(data, threadData);

  Flowsheet_eqFunction_1849(data, threadData);

  Flowsheet_eqFunction_1850(data, threadData);

  Flowsheet_eqFunction_1851(data, threadData);

  Flowsheet_eqFunction_1852(data, threadData);

  Flowsheet_eqFunction_1853(data, threadData);

  Flowsheet_eqFunction_1854(data, threadData);

  Flowsheet_eqFunction_1855(data, threadData);

  Flowsheet_eqFunction_1856(data, threadData);

  Flowsheet_eqFunction_1857(data, threadData);

  Flowsheet_eqFunction_1858(data, threadData);

  Flowsheet_eqFunction_1859(data, threadData);

  Flowsheet_eqFunction_1860(data, threadData);

  Flowsheet_eqFunction_1861(data, threadData);

  Flowsheet_eqFunction_1862(data, threadData);

  Flowsheet_eqFunction_1863(data, threadData);

  Flowsheet_eqFunction_1864(data, threadData);

  Flowsheet_eqFunction_1865(data, threadData);

  Flowsheet_eqFunction_1866(data, threadData);

  Flowsheet_eqFunction_1867(data, threadData);

  Flowsheet_eqFunction_1868(data, threadData);

  Flowsheet_eqFunction_1869(data, threadData);

  Flowsheet_eqFunction_1870(data, threadData);

  Flowsheet_eqFunction_1871(data, threadData);

  Flowsheet_eqFunction_1872(data, threadData);

  Flowsheet_eqFunction_1873(data, threadData);

  Flowsheet_eqFunction_1874(data, threadData);

  Flowsheet_eqFunction_1875(data, threadData);

  Flowsheet_eqFunction_1876(data, threadData);

  Flowsheet_eqFunction_1877(data, threadData);

  Flowsheet_eqFunction_1878(data, threadData);

  Flowsheet_eqFunction_1879(data, threadData);

  Flowsheet_eqFunction_1880(data, threadData);

  Flowsheet_eqFunction_1881(data, threadData);

  Flowsheet_eqFunction_1882(data, threadData);

  Flowsheet_eqFunction_1883(data, threadData);

  Flowsheet_eqFunction_1884(data, threadData);

  Flowsheet_eqFunction_1885(data, threadData);

  Flowsheet_eqFunction_1886(data, threadData);

  Flowsheet_eqFunction_1887(data, threadData);

  Flowsheet_eqFunction_1888(data, threadData);

  Flowsheet_eqFunction_1889(data, threadData);

  Flowsheet_eqFunction_1890(data, threadData);

  Flowsheet_eqFunction_1891(data, threadData);

  Flowsheet_eqFunction_1892(data, threadData);

  Flowsheet_eqFunction_1893(data, threadData);

  Flowsheet_eqFunction_1894(data, threadData);

  Flowsheet_eqFunction_1895(data, threadData);

  Flowsheet_eqFunction_1896(data, threadData);

  Flowsheet_eqFunction_1897(data, threadData);

  Flowsheet_eqFunction_1898(data, threadData);

  Flowsheet_eqFunction_1899(data, threadData);

  Flowsheet_eqFunction_1900(data, threadData);

  Flowsheet_eqFunction_1901(data, threadData);

  Flowsheet_eqFunction_1902(data, threadData);

  Flowsheet_eqFunction_1903(data, threadData);

  Flowsheet_eqFunction_1904(data, threadData);

  Flowsheet_eqFunction_1905(data, threadData);

  Flowsheet_eqFunction_1906(data, threadData);

  Flowsheet_eqFunction_1907(data, threadData);

  Flowsheet_eqFunction_1908(data, threadData);

  Flowsheet_eqFunction_1909(data, threadData);

  Flowsheet_eqFunction_1910(data, threadData);

  Flowsheet_eqFunction_1911(data, threadData);

  Flowsheet_eqFunction_1912(data, threadData);

  Flowsheet_eqFunction_1913(data, threadData);

  Flowsheet_eqFunction_1914(data, threadData);

  Flowsheet_eqFunction_1915(data, threadData);

  Flowsheet_eqFunction_1916(data, threadData);

  Flowsheet_eqFunction_1917(data, threadData);

  Flowsheet_eqFunction_1918(data, threadData);

  Flowsheet_eqFunction_1919(data, threadData);

  Flowsheet_eqFunction_1920(data, threadData);

  Flowsheet_eqFunction_1921(data, threadData);

  Flowsheet_eqFunction_1922(data, threadData);

  Flowsheet_eqFunction_1923(data, threadData);

  Flowsheet_eqFunction_1924(data, threadData);

  Flowsheet_eqFunction_1925(data, threadData);

  Flowsheet_eqFunction_1926(data, threadData);

  Flowsheet_eqFunction_1927(data, threadData);

  Flowsheet_eqFunction_1928(data, threadData);

  Flowsheet_eqFunction_1929(data, threadData);

  Flowsheet_eqFunction_1930(data, threadData);

  Flowsheet_eqFunction_1931(data, threadData);

  Flowsheet_eqFunction_1932(data, threadData);

  Flowsheet_eqFunction_1933(data, threadData);

  Flowsheet_eqFunction_1934(data, threadData);

  Flowsheet_eqFunction_1935(data, threadData);

  Flowsheet_eqFunction_1936(data, threadData);

  Flowsheet_eqFunction_1937(data, threadData);

  Flowsheet_eqFunction_1938(data, threadData);

  Flowsheet_eqFunction_1939(data, threadData);

  Flowsheet_eqFunction_1940(data, threadData);

  Flowsheet_eqFunction_1941(data, threadData);

  Flowsheet_eqFunction_1942(data, threadData);

  Flowsheet_eqFunction_1847(data, threadData);

  Flowsheet_eqFunction_1846(data, threadData);

  Flowsheet_eqFunction_1845(data, threadData);

  Flowsheet_eqFunction_1844(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

