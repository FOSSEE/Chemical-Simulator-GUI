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
  static const char *res[] = {"101325.0 >= MaterialStream3.Pbubl",
  "101325.0 >= MaterialStream3.Pdew"};
  static const int occurEqs0[] = {1,-1};
  static const int occurEqs1[] = {1,-1};
  static const int *occurEqs[] = {occurEqs0,occurEqs1};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void Flowsheet_eqFunction_718(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_721(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_723(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_746(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_768(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_770(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_775(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_796(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_799(DATA* data, threadData_t *threadData);
extern void Flowsheet_eqFunction_826(DATA* data, threadData_t *threadData);

int Flowsheet_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  Flowsheet_eqFunction_718(data, threadData);

  Flowsheet_eqFunction_721(data, threadData);

  Flowsheet_eqFunction_723(data, threadData);

  Flowsheet_eqFunction_746(data, threadData);

  Flowsheet_eqFunction_768(data, threadData);

  Flowsheet_eqFunction_770(data, threadData);

  Flowsheet_eqFunction_775(data, threadData);

  Flowsheet_eqFunction_796(data, threadData);

  Flowsheet_eqFunction_799(data, threadData);

  Flowsheet_eqFunction_826(data, threadData);
  
  TRACE_POP
  return 0;
}

int Flowsheet_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp438;
  modelica_boolean tmp439;
  
  data->simulationInfo->callStatistics.functionZeroCrossings++;
  
  tmp438 = GreaterEqZC(101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp438) ? 1 : -1;
  tmp439 = GreaterEqZC(101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp439) ? 1 : -1;
  
  TRACE_POP
  return 0;
}

const char *Flowsheet_relationDescription(int i)
{
  const char *res[] = {"101325.0 >= MaterialStream3.Pbubl",
  "101325.0 >= MaterialStream3.Pdew"};
  return res[i];
}

int Flowsheet_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp440;
  modelica_boolean tmp441;
  
  if(evalforZeroCross) {
    tmp440 = GreaterEqZC(101325.0, data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp440;
    tmp441 = GreaterEqZC(101325.0, data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp441;
  } else {
    data->simulationInfo->relations[0] = (101325.0 >= data->localData[0]->realVars[233] /* MaterialStream3._Pbubl variable */);
    data->simulationInfo->relations[1] = (101325.0 >= data->localData[0]->realVars[234] /* MaterialStream3._Pdew variable */);
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

