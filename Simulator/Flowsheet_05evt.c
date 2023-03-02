/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "Flowsheet_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void Flowsheet_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *Flowsheet_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"Heater1.Pout >= MaterialStream2.Pbubl",
  "Heater1.Pout >= MaterialStream2.Pdew"};
  static const int occurEqs0[] = {1,-1};
  static const int occurEqs1[] = {1,-1};
  static const int *occurEqs[] = {occurEqs0,occurEqs1};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void Flowsheet_eqFunction_557(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_560(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_563(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_564(DATA* data, threadData_t *threadData);

int Flowsheet_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  Flowsheet_eqFunction_557(data, threadData);

  Flowsheet_eqFunction_560(data, threadData);

  Flowsheet_eqFunction_563(data, threadData);

  Flowsheet_eqFunction_564(data, threadData);
  
  TRACE_POP
  return 0;
}

int Flowsheet_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp351;
  modelica_boolean tmp352;
  
  data->simulationInfo->callStatistics.functionZeroCrossings++;
  
  tmp351 = GreaterEqZC(data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp351) ? 1 : -1;
  tmp352 = GreaterEqZC(data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp352) ? 1 : -1;
  
  TRACE_POP
  return 0;
}

const char *Flowsheet_relationDescription(int i)
{
  const char *res[] = {"Heater1.Pout >= MaterialStream2.Pbubl",
  "Heater1.Pout >= MaterialStream2.Pdew"};
  return res[i];
}

int Flowsheet_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp353;
  modelica_boolean tmp354;
  
  if(evalforZeroCross) {
    tmp353 = GreaterEqZC(data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp353;
    tmp354 = GreaterEqZC(data->localData[0]->realVars[4] /* Heater1._Pout variable */, data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp354;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->realVars[4] /* Heater1._Pout variable */ >= data->localData[0]->realVars[146] /* MaterialStream2._Pbubl variable */);
    data->simulationInfo->relations[1] = (data->localData[0]->realVars[4] /* Heater1._Pout variable */ >= data->localData[0]->realVars[147] /* MaterialStream2._Pdew variable */);
  }
  
  TRACE_POP
  return 0;
}

int Flowsheet_checkForDiscreteChanges(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int needToIterate = 0;

  infoStreamPrint(LOG_EVENTS_V, 1, "check for discrete changes at time=%.12g", data->localData[0]->timeValue);
  if (ACTIVE_STREAM(LOG_EVENTS_V)) messageClose(LOG_EVENTS_V);
  
  TRACE_POP
  return needToIterate;
}

#if defined(__cplusplus)
}
#endif

