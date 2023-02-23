#include "Graph_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "Graph_includes.h"


DLLExport
real_array omc_Simulator_Files_ThermodynamicFunctions_BIPNRTL(threadData_t *threadData, modelica_integer _Nc, string_array _CAS)
{
  real_array _BIP;
  modelica_string _Us = NULL;
  string_array _CAS_CAS;
  real_array _BIPdb;
  string_array _c_cc;
  string_array _d_cc;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  modelica_integer tmp8;
  modelica_integer tmp9;
  modelica_integer tmp10;
  modelica_integer tmp11;
  modelica_integer tmp12;
  modelica_integer tmp13;
  modelica_integer tmp14;
  modelica_integer tmp15;
  modelica_integer tmp16;
  modelica_integer tmp17;
  modelica_integer tmp18;
  modelica_metatype tmpMeta[2] __attribute__((unused)) = {0};
  _tailrecursive: OMC_LABEL_UNUSED
  alloc_real_array(&_BIP, 3, (modelica_integer)_Nc, (modelica_integer)_Nc, ((modelica_integer) 2));
  _Us = _OMC_LIT1;
  _CAS_CAS = _OMC_LIT339;
  _BIPdb = _OMC_LIT340;
  alloc_string_array(&_c_cc, 2, (modelica_integer)_Nc, (modelica_integer)_Nc);
  alloc_string_array(&_d_cc, 2, (modelica_integer)_Nc, (modelica_integer)_Nc);
  tmp7 = ((modelica_integer) 1); tmp8 = 1; tmp9 = (modelica_integer)_Nc;
  if(!tmp8)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert(threadData, info, "assertion range step != 0 failed");
  }
  else if(!(((tmp8 > 0) && (tmp7 > tmp9)) || ((tmp8 < 0) && (tmp7 < tmp9))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp7, tmp9); _i += tmp8)
    {
      tmp4 = ((modelica_integer) 1); tmp5 = 1; tmp6 = (modelica_integer)_Nc;
      if(!tmp5)
      {
        FILE_INFO info = omc_dummyFileInfo;
        omc_assert(threadData, info, "assertion range step != 0 failed");
      }
      else if(!(((tmp5 > 0) && (tmp4 > tmp6)) || ((tmp5 < 0) && (tmp4 < tmp6))))
      {
        modelica_integer _j;
        for(_j = ((modelica_integer) 1); in_range_integer(_j, tmp4, tmp6); _j += tmp5)
        {
          tmp1 = ((modelica_integer) 1); tmp2 = 1; tmp3 = ((modelica_integer) 2);
          if(!tmp2)
          {
            FILE_INFO info = omc_dummyFileInfo;
            omc_assert(threadData, info, "assertion range step != 0 failed");
          }
          else if(!(((tmp2 > 0) && (tmp1 > tmp3)) || ((tmp2 < 0) && (tmp1 < tmp3))))
          {
            modelica_integer _k;
            for(_k = ((modelica_integer) 1); in_range_integer(_k, tmp1, tmp3); _k += tmp2)
            {
              (*real_array_element_addr(&_BIP, 3, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_j, /* modelica_integer */ (modelica_integer)_k)) = 0.0;
            }
          }
        }
      }
    }
  }

  tmp16 = ((modelica_integer) 1); tmp17 = 1; tmp18 = (modelica_integer)_Nc;
  if(!tmp17)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert(threadData, info, "assertion range step != 0 failed");
  }
  else if(!(((tmp17 > 0) && (tmp16 > tmp18)) || ((tmp17 < 0) && (tmp16 < tmp18))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp16, tmp18); _i += tmp17)
    {
      tmp13 = ((modelica_integer) 1); tmp14 = 1; tmp15 = (modelica_integer)_Nc;
      if(!tmp14)
      {
        FILE_INFO info = omc_dummyFileInfo;
        omc_assert(threadData, info, "assertion range step != 0 failed");
      }
      else if(!(((tmp14 > 0) && (tmp13 > tmp15)) || ((tmp14 < 0) && (tmp13 < tmp15))))
      {
        modelica_integer _j;
        for(_j = ((modelica_integer) 1); in_range_integer(_j, tmp13, tmp15); _j += tmp14)
        {
          tmpMeta[0] = stringAppend((*string_array_element_addr1(&_CAS, 1, /* modelica_integer */ (modelica_integer)_i)),_OMC_LIT1);
          tmpMeta[1] = stringAppend(tmpMeta[0],(*string_array_element_addr1(&_CAS, 1, /* modelica_integer */ (modelica_integer)_j)));
          (*string_array_element_addr2(&_c_cc, 2, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_j)) = tmpMeta[1];

          tmpMeta[0] = stringAppend((*string_array_element_addr1(&_CAS, 1, /* modelica_integer */ (modelica_integer)_j)),_OMC_LIT1);
          tmpMeta[1] = stringAppend(tmpMeta[0],(*string_array_element_addr1(&_CAS, 1, /* modelica_integer */ (modelica_integer)_i)));
          (*string_array_element_addr2(&_d_cc, 2, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_j)) = tmpMeta[1];

          tmp10 = ((modelica_integer) 1); tmp11 = 1; tmp12 = ((modelica_integer) 352);
          if(!tmp11)
          {
            FILE_INFO info = omc_dummyFileInfo;
            omc_assert(threadData, info, "assertion range step != 0 failed");
          }
          else if(!(((tmp11 > 0) && (tmp10 > tmp12)) || ((tmp11 < 0) && (tmp10 < tmp12))))
          {
            modelica_integer _k;
            for(_k = ((modelica_integer) 1); in_range_integer(_k, tmp10, tmp12); _k += tmp11)
            {
              if((stringEqual((*string_array_element_addr2(&_c_cc, 2, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_j)), string_get(_OMC_LIT339, ((modelica_integer)_k)-1))))
              {
                (*real_array_element_addr(&_BIP, 3, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_j, /* modelica_integer */ ((modelica_integer) 1))) = real_get_2D(_OMC_LIT340, ((modelica_integer)_k)-1, 0);

                (*real_array_element_addr(&_BIP, 3, /* modelica_integer */ (modelica_integer)_j, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ ((modelica_integer) 1))) = real_get_2D(_OMC_LIT340, ((modelica_integer)_k)-1, 1);

                (*real_array_element_addr(&_BIP, 3, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_j, /* modelica_integer */ ((modelica_integer) 2))) = real_get_2D(_OMC_LIT340, ((modelica_integer)_k)-1, 2);

                (*real_array_element_addr(&_BIP, 3, /* modelica_integer */ (modelica_integer)_j, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ ((modelica_integer) 2))) = real_get_2D(_OMC_LIT340, ((modelica_integer)_k)-1, 2);
              }

              if((stringEqual((*string_array_element_addr2(&_d_cc, 2, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_j)), string_get(_OMC_LIT339, ((modelica_integer)_k)-1))))
              {
                (*real_array_element_addr(&_BIP, 3, /* modelica_integer */ (modelica_integer)_j, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ ((modelica_integer) 1))) = real_get_2D(_OMC_LIT340, ((modelica_integer)_k)-1, 0);

                (*real_array_element_addr(&_BIP, 3, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_j, /* modelica_integer */ ((modelica_integer) 1))) = real_get_2D(_OMC_LIT340, ((modelica_integer)_k)-1, 1);

                (*real_array_element_addr(&_BIP, 3, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_j, /* modelica_integer */ ((modelica_integer) 2))) = real_get_2D(_OMC_LIT340, ((modelica_integer)_k)-1, 2);

                (*real_array_element_addr(&_BIP, 3, /* modelica_integer */ (modelica_integer)_j, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ ((modelica_integer) 2))) = real_get_2D(_OMC_LIT340, ((modelica_integer)_k)-1, 2);
              }
            }
          }
        }
      }
    }
  }
  _return: OMC_LABEL_UNUSED
  return _BIP;
}
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_BIPNRTL(threadData_t *threadData, modelica_metatype _Nc, modelica_metatype _CAS)
{
  modelica_integer tmp1;
  real_array _BIP;
  modelica_metatype out_BIP;
  tmp1 = mmc_unbox_integer(_Nc);
  _BIP = omc_Simulator_Files_ThermodynamicFunctions_BIPNRTL(threadData, tmp1, *((base_array_t*)_CAS));
  out_BIP = mmc_mk_modelica_array(_BIP);
  return out_BIP;
}

DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData_t *threadData, real_array _LiqDen, modelica_real _Tc, modelica_real _T, modelica_real _P)
{
  modelica_real _rho;
  modelica_real _Tr;
  modelica_real _R;
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
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  _tailrecursive: OMC_LABEL_UNUSED
  _R = 8.314;
  tmp1 = _Tc;
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "T / Tc");}
  _Tr = (_T) / tmp1;

  if((_T < _Tc))
  {
    if(((*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 1))) == 105.0))
    {
      tmp2 = (*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 4)));
      if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "T / LiqDen[4]");}
      tmp3 = 1.0 - ((_T) / tmp2);
      tmp4 = (*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 5)));
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
      }tmp10 = (*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 3)));
      tmp11 = -1.0 - (tmp5);
      if(tmp10 < 0.0 && tmp11 != 0.0)
      {
        tmp13 = modf(tmp11, &tmp14);
        
        if(tmp13 > 0.5)
        {
          tmp13 -= 1.0;
          tmp14 += 1.0;
        }
        else if(tmp13 < -0.5)
        {
          tmp13 += 1.0;
          tmp14 -= 1.0;
        }
        
        if(fabs(tmp13) < 1e-10)
          tmp12 = pow(tmp10, tmp14);
        else
        {
          tmp16 = modf(1.0/tmp11, &tmp15);
          if(tmp16 > 0.5)
          {
            tmp16 -= 1.0;
            tmp15 += 1.0;
          }
          else if(tmp16 < -0.5)
          {
            tmp16 += 1.0;
            tmp15 -= 1.0;
          }
          if(fabs(tmp16) < 1e-10 && ((unsigned long)tmp15 & 1))
          {
            tmp12 = -pow(-tmp10, tmp13)*pow(tmp10, tmp14);
          }
          else
          {
            throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp10, tmp11);
          }
        }
      }
      else
      {
        tmp12 = pow(tmp10, tmp11);
      }
      if(isnan(tmp12) || isinf(tmp12))
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp10, tmp11);
      }
      _rho = (1000.0) * (((*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 2)))) * (tmp12));
    }
    else
    {
      if(((*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 1))) == 106.0))
      {
        tmp17 = _Tr;
        tmp18 = _Tr;
        tmp19 = 1.0 - _Tr;
        tmp20 = (*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 3))) + ((*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 4)))) * (_Tr) + ((*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 5)))) * ((tmp17 * tmp17)) + ((*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 6)))) * ((tmp18 * tmp18 * tmp18));
        if(tmp19 < 0.0 && tmp20 != 0.0)
        {
          tmp22 = modf(tmp20, &tmp23);
          
          if(tmp22 > 0.5)
          {
            tmp22 -= 1.0;
            tmp23 += 1.0;
          }
          else if(tmp22 < -0.5)
          {
            tmp22 += 1.0;
            tmp23 -= 1.0;
          }
          
          if(fabs(tmp22) < 1e-10)
            tmp21 = pow(tmp19, tmp23);
          else
          {
            tmp25 = modf(1.0/tmp20, &tmp24);
            if(tmp25 > 0.5)
            {
              tmp25 -= 1.0;
              tmp24 += 1.0;
            }
            else if(tmp25 < -0.5)
            {
              tmp25 += 1.0;
              tmp24 -= 1.0;
            }
            if(fabs(tmp25) < 1e-10 && ((unsigned long)tmp24 & 1))
            {
              tmp21 = -pow(-tmp19, tmp22)*pow(tmp19, tmp23);
            }
            else
            {
              throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp19, tmp20);
            }
          }
        }
        else
        {
          tmp21 = pow(tmp19, tmp20);
        }
        if(isnan(tmp21) || isinf(tmp21))
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp19, tmp20);
        }
        _rho = (1000.0) * (((*real_array_element_addr1(&_LiqDen, 1, /* modelica_integer */ ((modelica_integer) 2)))) * (tmp21));
      }
    }
  }
  else
  {
    tmp26 = (_T) * (_R);
    if (tmp26 == 0) {throwStreamPrint(threadData, "Division by zero %s", "P / (T * R)");}
    _rho = (0.001) * ((_P) / tmp26);
  }
  _return: OMC_LABEL_UNUSED
  return _rho;
}
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_Dens(threadData_t *threadData, modelica_metatype _LiqDen, modelica_metatype _Tc, modelica_metatype _T, modelica_metatype _P)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _rho;
  modelica_metatype out_rho;
  tmp1 = mmc_unbox_real(_Tc);
  tmp2 = mmc_unbox_real(_T);
  tmp3 = mmc_unbox_real(_P);
  _rho = omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData, *((base_array_t*)_LiqDen), tmp1, tmp2, tmp3);
  out_rho = mmc_mk_rcon(_rho);
  return out_rho;
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

#ifdef __cplusplus
}
#endif
