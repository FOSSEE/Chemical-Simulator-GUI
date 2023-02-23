#ifndef Graph__H
#define Graph__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif


DLLExport
real_array omc_Simulator_Files_ThermodynamicFunctions_BIPNRTL(threadData_t *threadData, modelica_integer _Nc, string_array _CAS);
DLLExport
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_BIPNRTL(threadData_t *threadData, modelica_metatype _Nc, modelica_metatype _CAS);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Simulator_Files_ThermodynamicFunctions_BIPNRTL,2,0) {(void*) boxptr_Simulator_Files_ThermodynamicFunctions_BIPNRTL,0}};
#define boxvar_Simulator_Files_ThermodynamicFunctions_BIPNRTL MMC_REFSTRUCTLIT(boxvar_lit_Simulator_Files_ThermodynamicFunctions_BIPNRTL)


DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_Dens(threadData_t *threadData, real_array _LiqDen, modelica_real _Tc, modelica_real _T, modelica_real _P);
DLLExport
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_Dens(threadData_t *threadData, modelica_metatype _LiqDen, modelica_metatype _Tc, modelica_metatype _T, modelica_metatype _P);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Simulator_Files_ThermodynamicFunctions_Dens,2,0) {(void*) boxptr_Simulator_Files_ThermodynamicFunctions_Dens,0}};
#define boxvar_Simulator_Files_ThermodynamicFunctions_Dens MMC_REFSTRUCTLIT(boxvar_lit_Simulator_Files_ThermodynamicFunctions_Dens)


DLLExport
modelica_real omc_Simulator_Files_ThermodynamicFunctions_Psat(threadData_t *threadData, real_array _VP, modelica_real _T);
DLLExport
modelica_metatype boxptr_Simulator_Files_ThermodynamicFunctions_Psat(threadData_t *threadData, modelica_metatype _VP, modelica_metatype _T);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Simulator_Files_ThermodynamicFunctions_Psat,2,0) {(void*) boxptr_Simulator_Files_ThermodynamicFunctions_Psat,0}};
#define boxvar_Simulator_Files_ThermodynamicFunctions_Psat MMC_REFSTRUCTLIT(boxvar_lit_Simulator_Files_ThermodynamicFunctions_Psat)
#include "Graph_model.h"


#ifdef __cplusplus
}
#endif
#endif

