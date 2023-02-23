/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define Graph_INDEX_JAC_A 3
  int Graph_functionJacA_column(void* data, threadData_t *threadData);
  int Graph_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Graph_INDEX_JAC_B 2
  int Graph_functionJacB_column(void* data, threadData_t *threadData);
  int Graph_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Graph_INDEX_JAC_C 1
  int Graph_functionJacC_column(void* data, threadData_t *threadData);
  int Graph_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Graph_INDEX_JAC_D 0
  int Graph_functionJacD_column(void* data, threadData_t *threadData);
  int Graph_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */


