#include "Flowsheet_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "Flowsheet_includes.h"


DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData_t *threadData, modelica_real _SH, real_array _VapCp, real_array _HOV, modelica_real _Tc, modelica_real _T)
{
  modelica_real _Hliq;
  real_array tmp1;
  real_array tmp2;
  real_array tmp3;
  _tailrecursive: OMC_LABEL_UNUSED
  array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6))));
  array_alloc_scalar_real_array(&tmp2, 6, (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 6))));
  array_alloc_scalar_real_array(&tmp3, 6, (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 6))));
  _Hliq = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, _SH, tmp1, tmp2, _Tc, _T) - omc_Simulator_Files_ThermodynamicFunctions_HV(threadData, tmp3, _Tc, _T);
  _return: OMC_LABEL_UNUSED
  return _Hliq;
}
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData_t *threadData, modelica_metatype _SH, modelica_metatype _VapCp, modelica_metatype _HOV, modelica_metatype _Tc, modelica_metatype _T)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _Hliq;
  modelica_metatype out_Hliq;
  tmp1 = mmc_unbox_real(_SH);
  tmp2 = mmc_unbox_real(_Tc);
  tmp3 = mmc_unbox_real(_T);
  _Hliq = omc_Simulator_Files_ThermodynamicFunctions_HLiqId(threadData, tmp1, *((base_array_t*)_VapCp), *((base_array_t*)_HOV), tmp2, tmp3);
  out_Hliq = mmc_mk_rcon(_Hliq);
  return out_Hliq;
}

DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_HV(threadData_t *threadData, real_array _HOV, modelica_real _Tc, modelica_real _T)
{
  modelica_real _Hvap;
  modelica_real _Tr;
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
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = _Tc;
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "T / Tc");}
  _Tr = (_T) / tmp1;
  if((_T < _Tc))
  {
    tmp2 = _Tr;
    tmp3 = _Tr;
    tmp4 = 1.0 - _Tr;
    tmp5 = (*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 3))) + ((*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 4)))) * (_Tr) + ((*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 5)))) * ((tmp2 * tmp2)) + ((*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 6)))) * ((tmp3 * tmp3 * tmp3));
    if(tmp4 < 0.0 && tmp5 != 0.0)
    {
      tmp7 = modf(tmp5, &tmp8);
      
      if(tmp7 > 0.5)
      {
        tmp7 -= 1.0;
        tmp8 += 1.0;
      }
      else if(tmp7 < -0.5)
      {
        tmp7 += 1.0;
        tmp8 -= 1.0;
      }
      
      if(fabs(tmp7) < 1e-10)
        tmp6 = pow(tmp4, tmp8);
      else
      {
        tmp10 = modf(1.0/tmp5, &tmp9);
        if(tmp10 > 0.5)
        {
          tmp10 -= 1.0;
          tmp9 += 1.0;
        }
        else if(tmp10 < -0.5)
        {
          tmp10 += 1.0;
          tmp9 -= 1.0;
        }
        if(fabs(tmp10) < 1e-10 && ((unsigned long)tmp9 & 1))
        {
          tmp6 = -pow(-tmp4, tmp7)*pow(tmp4, tmp8);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp4, tmp5);
        }
      }
    }
    else
    {
      tmp6 = pow(tmp4, tmp5);
    }
    if(isnan(tmp6) || isinf(tmp6))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp4, tmp5);
    }
    _Hvap = (0.001) * (((*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 2)))) * (tmp6));
  }
  else
  {
    _Hvap = 0.0;
  }
  _return: OMC_LABEL_UNUSED
  return _Hvap;
}
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_HV(threadData_t *threadData, modelica_metatype _HOV, modelica_metatype _Tc, modelica_metatype _T)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real _Hvap;
  modelica_metatype out_Hvap;
  tmp1 = mmc_unbox_real(_Tc);
  tmp2 = mmc_unbox_real(_T);
  _Hvap = omc_Simulator_Files_ThermodynamicFunctions_HV(threadData, *((base_array_t*)_HOV), tmp1, tmp2);
  out_Hvap = mmc_mk_rcon(_Hvap);
  return out_Hvap;
}

DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData_t *threadData, modelica_real _SH, real_array _VapCp, real_array _HOV, modelica_real _Tc, modelica_real _T)
{
  modelica_real _Hvap;
  modelica_integer _n;
  real_array _Cp;
  real_array tmp1;
  modelica_real tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  real_array tmp6;
  real_array tmp7;
  index_spec_t tmp8;
  real_array tmp9;
  modelica_real tmp10;
  _tailrecursive: OMC_LABEL_UNUSED
  _n = ((modelica_integer) 100);
  alloc_real_array(&_Cp, 1, ((modelica_integer) -1) + (modelica_integer)_n);
  tmp3 = ((modelica_integer) 1); tmp4 = 1; tmp5 = ((modelica_integer) -1) + (modelica_integer)_n;
  if(!tmp4)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert(threadData, info, "assertion range step != 0 failed");
  }
  else if(!(((tmp4 > 0) && (tmp3 > tmp5)) || ((tmp4 < 0) && (tmp3 < tmp5))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp3, tmp5); _i += tmp4)
    {
      array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6))));
      tmp2 = ((modelica_real)((modelica_integer)_n));
      if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(-298.15 + T) / /*Real*/(n)");}
      (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ (modelica_integer)_i)) = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp1, 298.15 + (((modelica_real)((modelica_integer)_i))) * ((-298.15 + _T) / tmp2));
    }
  }

  array_alloc_scalar_real_array(&tmp6, 6, (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6))));
  create_index_spec(&tmp8, 1, (1), (int*)0, 'W');
  index_alloc_real_array(&_Cp, &tmp8, &tmp7);
  array_alloc_scalar_real_array(&tmp9, 6, (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6))));
  tmp10 = ((modelica_real)((modelica_integer)_n));
  if (tmp10 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(0.5 * Simulator.Files.ThermodynamicFunctions.VapCpId({VapCp[1], VapCp[2], VapCp[3], VapCp[4], VapCp[5], VapCp[6]}, T) + sum(Cp[:]) + 0.5 * Simulator.Files.ThermodynamicFunctions.VapCpId({VapCp[1], VapCp[2], VapCp[3], VapCp[4], VapCp[5], VapCp[6]}, 298.15)) / /*Real*/(n)");}
  _Hvap = (-298.15 + _T) * (((0.5) * (omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp6, _T)) + sum_real_array(tmp7) + (0.5) * (omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp9, 298.15))) / tmp10);
  _return: OMC_LABEL_UNUSED
  return _Hvap;
}
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_HVapId(threadData_t *threadData, modelica_metatype _SH, modelica_metatype _VapCp, modelica_metatype _HOV, modelica_metatype _Tc, modelica_metatype _T)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _Hvap;
  modelica_metatype out_Hvap;
  tmp1 = mmc_unbox_real(_SH);
  tmp2 = mmc_unbox_real(_Tc);
  tmp3 = mmc_unbox_real(_T);
  _Hvap = omc_Simulator_Files_ThermodynamicFunctions_HVapId(threadData, tmp1, *((base_array_t*)_VapCp), *((base_array_t*)_HOV), tmp2, tmp3);
  out_Hvap = mmc_mk_rcon(_Hvap);
  return out_Hvap;
}

DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData_t *threadData, real_array _LiqCp, modelica_real _T)
{
  modelica_real _Cpliq;
  modelica_real tmp1;
  modelica_real tmp2;
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = _T;
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "LiqCp[3] / T");}
  tmp2 = _T;
  _Cpliq = (0.001) * ((*real_array_element_addr1(&_LiqCp, 1, /* modelica_integer */ ((modelica_integer) 2))) + exp(((*real_array_element_addr1(&_LiqCp, 1, /* modelica_integer */ ((modelica_integer) 3)))) / tmp1 + (*real_array_element_addr1(&_LiqCp, 1, /* modelica_integer */ ((modelica_integer) 4))) + ((*real_array_element_addr1(&_LiqCp, 1, /* modelica_integer */ ((modelica_integer) 5)))) * (_T) + ((*real_array_element_addr1(&_LiqCp, 1, /* modelica_integer */ ((modelica_integer) 6)))) * ((tmp2 * tmp2))));
  _return: OMC_LABEL_UNUSED
  return _Cpliq;
}
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData_t *threadData, modelica_metatype _LiqCp, modelica_metatype _T)
{
  modelica_real tmp1;
  modelica_real _Cpliq;
  modelica_metatype out_Cpliq;
  tmp1 = mmc_unbox_real(_T);
  _Cpliq = omc_Simulator_Files_ThermodynamicFunctions_LiqCpId(threadData, *((base_array_t*)_LiqCp), tmp1);
  out_Cpliq = mmc_mk_rcon(_Cpliq);
  return out_Cpliq;
}

DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData_t *threadData, real_array _VP, modelica_real _T)
{
  modelica_real _Pvap;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = _T;
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "VP[3] / T");}
  tmp2 = _T;
  if(!(tmp2 > 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of log(T) was %g should be > 0", tmp2);
  }tmp3 = _T;
  tmp4 = (*real_array_element_addr1(&_VP, 1, /* modelica_integer */ ((modelica_integer) 6)));
  if(tmp3 < 0.0 && tmp4 != 0.0)
  {
    tmp6 = modf(tmp4, &tmp7);
    
    if(tmp6 > 0.5)
    {
      tmp6 -= 1.0;
      tmp7 += 1.0;
    }
    else if(tmp6 < -0.5)
    {
      tmp6 += 1.0;
      tmp7 -= 1.0;
    }
    
    if(fabs(tmp6) < 1e-10)
      tmp5 = pow(tmp3, tmp7);
    else
    {
      tmp9 = modf(1.0/tmp4, &tmp8);
      if(tmp9 > 0.5)
      {
        tmp9 -= 1.0;
        tmp8 += 1.0;
      }
      else if(tmp9 < -0.5)
      {
        tmp9 += 1.0;
        tmp8 -= 1.0;
      }
      if(fabs(tmp9) < 1e-10 && ((unsigned long)tmp8 & 1))
      {
        tmp5 = -pow(-tmp3, tmp6)*pow(tmp3, tmp7);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp3, tmp4);
      }
    }
  }
  else
  {
    tmp5 = pow(tmp3, tmp4);
  }
  if(isnan(tmp5) || isinf(tmp5))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp3, tmp4);
  }
  _Pvap = exp((*real_array_element_addr1(&_VP, 1, /* modelica_integer */ ((modelica_integer) 2))) + ((*real_array_element_addr1(&_VP, 1, /* modelica_integer */ ((modelica_integer) 3)))) / tmp1 + ((*real_array_element_addr1(&_VP, 1, /* modelica_integer */ ((modelica_integer) 4)))) * (log(tmp2)) + ((*real_array_element_addr1(&_VP, 1, /* modelica_integer */ ((modelica_integer) 5)))) * (tmp5));
  _return: OMC_LABEL_UNUSED
  return _Pvap;
}
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_Psat(threadData_t *threadData, modelica_metatype _VP, modelica_metatype _T)
{
  modelica_real tmp1;
  modelica_real _Pvap;
  modelica_metatype out_Pvap;
  tmp1 = mmc_unbox_real(_T);
  _Pvap = omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData, *((base_array_t*)_VP), tmp1);
  out_Pvap = mmc_mk_rcon(_Pvap);
  return out_Pvap;
}

DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_SId(threadData_t *threadData, real_array _VapCp, real_array _HOV, modelica_real _Tb, modelica_real _Tc, modelica_real _T, modelica_real _P, modelica_real _xliq, modelica_real _xvap, modelica_real *out_Svap)
{
  modelica_real _Sliq;
  modelica_real _Svap;
  modelica_real _Tref;
  modelica_real _Pref;
  modelica_real _S;
  modelica_integer _n;
  real_array _Cp;
  real_array tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  real_array tmp8;
  modelica_real tmp9;
  real_array tmp10;
  modelica_real tmp11;
  real_array tmp12;
  modelica_real tmp13;
  real_array tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  real_array tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  real_array tmp30;
  modelica_real tmp31;
  _tailrecursive: OMC_LABEL_UNUSED
  _Tref = 298.15;
  _Pref = 101325.0;
  _n = ((modelica_integer) 10);
  alloc_real_array(&_Cp, 1, ((modelica_integer) 9));
  _S = 0.0;

  tmp5 = ((modelica_integer) 1); tmp6 = 1; tmp7 = ((modelica_integer) -1) + (modelica_integer)_n;
  if(!tmp6)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert(threadData, info, "assertion range step != 0 failed");
  }
  else if(!(((tmp6 > 0) && (tmp5 > tmp7)) || ((tmp6 < 0) && (tmp5 < tmp7))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp5, tmp7); _i += tmp6)
    {
      array_alloc_scalar_real_array(&tmp1, 6, (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6))));
      tmp2 = ((modelica_real)((modelica_integer)_n));
      if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(-298.15 + T) / /*Real*/(n)");}
      tmp3 = ((modelica_real)((modelica_integer)_n));
      if (tmp3 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(-298.15 + T) / /*Real*/(n)");}
      tmp4 = 298.15 + (((modelica_real)((modelica_integer)_i))) * ((-298.15 + _T) / tmp3);
      if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Simulator.Files.ThermodynamicFunctions.VapCpId({VapCp[1], VapCp[2], VapCp[3], VapCp[4], VapCp[5], VapCp[6]}, 298.15 + /*Real*/(i) * (-298.15 + T) / /*Real*/(n)) / (298.15 + /*Real*/(i) * (-298.15 + T) / /*Real*/(n))");}
      (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ (modelica_integer)_i)) = (omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp1, 298.15 + (((modelica_real)((modelica_integer)_i))) * ((-298.15 + _T) / tmp2))) / tmp4;
    }
  }

  if((_T >= _Tref))
  {
    array_alloc_scalar_real_array(&tmp8, 6, (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6))));
    tmp9 = _T;
    if (tmp9 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Simulator.Files.ThermodynamicFunctions.VapCpId({VapCp[1], VapCp[2], VapCp[3], VapCp[4], VapCp[5], VapCp[6]}, T) / T");}
    array_alloc_scalar_real_array(&tmp10, 6, (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6))));
    tmp11 = ((modelica_real)((modelica_integer)_n));
    if (tmp11 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(0.5 * Simulator.Files.ThermodynamicFunctions.VapCpId({VapCp[1], VapCp[2], VapCp[3], VapCp[4], VapCp[5], VapCp[6]}, T) / T + Cp[1] + Cp[2] + Cp[3] + Cp[4] + Cp[5] + Cp[6] + Cp[7] + Cp[8] + Cp[9] + 0.001677008217340265 * Simulator.Files.ThermodynamicFunctions.VapCpId({VapCp[1], VapCp[2], VapCp[3], VapCp[4], VapCp[5], VapCp[6]}, 298.15)) / /*Real*/(n)");}
    _S = (-298.15 + _T) * (((0.5) * ((omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp8, _T)) / tmp9) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 1))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 2))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 3))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 4))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 5))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 6))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 7))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 8))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 9))) + (0.001677008217340265) * (omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp10, 298.15))) / tmp11);
  }
  else
  {
    array_alloc_scalar_real_array(&tmp12, 6, (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6))));
    tmp13 = _T;
    if (tmp13 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Simulator.Files.ThermodynamicFunctions.VapCpId({VapCp[1], VapCp[2], VapCp[3], VapCp[4], VapCp[5], VapCp[6]}, T) / T");}
    array_alloc_scalar_real_array(&tmp14, 6, (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6))));
    tmp15 = ((modelica_real)((modelica_integer)_n));
    if (tmp15 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(0.5 * Simulator.Files.ThermodynamicFunctions.VapCpId({VapCp[1], VapCp[2], VapCp[3], VapCp[4], VapCp[5], VapCp[6]}, T) / T + Cp[1] + Cp[2] + Cp[3] + Cp[4] + Cp[5] + Cp[6] + Cp[7] + Cp[8] + Cp[9] + 0.001677008217340265 * Simulator.Files.ThermodynamicFunctions.VapCpId({VapCp[1], VapCp[2], VapCp[3], VapCp[4], VapCp[5], VapCp[6]}, 298.15)) / /*Real*/(n)");}
    _S = (298.15 - _T) * (((0.5) * ((omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp12, _T)) / tmp13) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 1))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 2))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 3))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 4))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 5))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 6))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 7))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 8))) + (*real_array_element_addr1(&_Cp, 1, /* modelica_integer */ ((modelica_integer) 9))) + (0.001677008217340265) * (omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, tmp14, 298.15))) / tmp15);
  }

  if(((_xliq > 0.0) && (_xvap > 0.0)))
  {
    tmp16 = _Pref;
    if (tmp16 == 0) {throwStreamPrint(threadData, "Division by zero %s", "P / Pref");}
    tmp17 = (_P) / tmp16;
    if(!(tmp17 > 0.0))
    {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert(threadData, info, "Model error: Argument of log(P / Pref) was %g should be > 0", tmp17);
    }tmp18 = _xliq;
    if(!(tmp18 > 0.0))
    {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert(threadData, info, "Model error: Argument of log(xliq) was %g should be > 0", tmp18);
    }array_alloc_scalar_real_array(&tmp19, 6, (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 6))));
    tmp20 = _T;
    if (tmp20 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Simulator.Files.ThermodynamicFunctions.HV({HOV[1], HOV[2], HOV[3], HOV[4], HOV[5], HOV[6]}, Tc, T) / T");}
    _Sliq = _S + (-8.3144598) * (log(tmp17) + log(tmp18)) - ((omc_Simulator_Files_ThermodynamicFunctions_HV(threadData, tmp19, _Tc, _T)) / tmp20);

    tmp21 = _Pref;
    if (tmp21 == 0) {throwStreamPrint(threadData, "Division by zero %s", "P / Pref");}
    tmp22 = (_P) / tmp21;
    if(!(tmp22 > 0.0))
    {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert(threadData, info, "Model error: Argument of log(P / Pref) was %g should be > 0", tmp22);
    }tmp23 = _xvap;
    if(!(tmp23 > 0.0))
    {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert(threadData, info, "Model error: Argument of log(xvap) was %g should be > 0", tmp23);
    }
    _Svap = _S + (-8.3144598) * (log(tmp22) + log(tmp23));
  }
  else
  {
    if(((_xliq <= 0.0) && (_xvap <= 0.0)))
    {
      _Sliq = 0.0;

      _Svap = 0.0;
    }
    else
    {
      if((_xliq == 0.0))
      {
        _Sliq = 0.0;

        tmp24 = _Pref;
        if (tmp24 == 0) {throwStreamPrint(threadData, "Division by zero %s", "P / Pref");}
        tmp25 = (_P) / tmp24;
        if(!(tmp25 > 0.0))
        {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert(threadData, info, "Model error: Argument of log(P / Pref) was %g should be > 0", tmp25);
        }tmp26 = _xvap;
        if(!(tmp26 > 0.0))
        {
          FILE_INFO info = {"",0,0,0,0,0};
          omc_assert(threadData, info, "Model error: Argument of log(xvap) was %g should be > 0", tmp26);
        }
        _Svap = _S + (-8.3144598) * (log(tmp25) + log(tmp26));
      }
      else
      {
        if((_xvap == 0.0))
        {
          tmp27 = _Pref;
          if (tmp27 == 0) {throwStreamPrint(threadData, "Division by zero %s", "P / Pref");}
          tmp28 = (_P) / tmp27;
          if(!(tmp28 > 0.0))
          {
            FILE_INFO info = {"",0,0,0,0,0};
            omc_assert(threadData, info, "Model error: Argument of log(P / Pref) was %g should be > 0", tmp28);
          }tmp29 = _xliq;
          if(!(tmp29 > 0.0))
          {
            FILE_INFO info = {"",0,0,0,0,0};
            omc_assert(threadData, info, "Model error: Argument of log(xliq) was %g should be > 0", tmp29);
          }array_alloc_scalar_real_array(&tmp30, 6, (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 1))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 2))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 3))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 4))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 5))), (modelica_real)(*real_array_element_addr1(&_HOV, 1, /* modelica_integer */ ((modelica_integer) 6))));
          tmp31 = _T;
          if (tmp31 == 0) {throwStreamPrint(threadData, "Division by zero %s", "Simulator.Files.ThermodynamicFunctions.HV({HOV[1], HOV[2], HOV[3], HOV[4], HOV[5], HOV[6]}, Tc, T) / T");}
          _Sliq = _S + (-8.3144598) * (log(tmp28) + log(tmp29)) - ((omc_Simulator_Files_ThermodynamicFunctions_HV(threadData, tmp30, _Tc, _T)) / tmp31);

          _Svap = 0.0;
        }
        else
        {
          _Sliq = 0.0;

          _Svap = 0.0;
        }
      }
    }
  }
  _return: OMC_LABEL_UNUSED
  if (out_Svap) { *out_Svap = _Svap; }
  return _Sliq;
}
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_SId(threadData_t *threadData, modelica_metatype _VapCp, modelica_metatype _HOV, modelica_metatype _Tb, modelica_metatype _Tc, modelica_metatype _T, modelica_metatype _P, modelica_metatype _xliq, modelica_metatype _xvap, modelica_metatype *out_Svap)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real _Svap;
  modelica_real _Sliq;
  modelica_metatype out_Sliq;
  tmp1 = mmc_unbox_real(_Tb);
  tmp2 = mmc_unbox_real(_Tc);
  tmp3 = mmc_unbox_real(_T);
  tmp4 = mmc_unbox_real(_P);
  tmp5 = mmc_unbox_real(_xliq);
  tmp6 = mmc_unbox_real(_xvap);
  _Sliq = omc_Simulator_Files_ThermodynamicFunctions_SId(threadData, *((base_array_t*)_VapCp), *((base_array_t*)_HOV), tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, &_Svap);
  out_Sliq = mmc_mk_rcon(_Sliq);
  if (out_Svap) { *out_Svap = mmc_mk_rcon(_Svap); }
  return out_Sliq;
}

DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData_t *threadData, real_array _VapCp, modelica_real _T)
{
  modelica_real _Cpvap;
  modelica_real tmp1;
  modelica_real tmp2;
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = _T;
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "VapCp[3] / T");}
  tmp2 = _T;
  _Cpvap = (0.001) * ((*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 2))) + exp(((*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 3)))) / tmp1 + (*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 4))) + ((*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 5)))) * (_T) + ((*real_array_element_addr1(&_VapCp, 1, /* modelica_integer */ ((modelica_integer) 6)))) * ((tmp2 * tmp2))));
  _return: OMC_LABEL_UNUSED
  return _Cpvap;
}
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData_t *threadData, modelica_metatype _VapCp, modelica_metatype _T)
{
  modelica_real tmp1;
  modelica_real _Cpvap;
  modelica_metatype out_Cpvap;
  tmp1 = mmc_unbox_real(_T);
  _Cpvap = omc_Simulator_Files_ThermodynamicFunctions_VapCpId(threadData, *((base_array_t*)_VapCp), tmp1);
  out_Cpvap = mmc_mk_rcon(_Cpvap);
  return out_Cpvap;
}

#ifdef __cplusplus
}
#endif
