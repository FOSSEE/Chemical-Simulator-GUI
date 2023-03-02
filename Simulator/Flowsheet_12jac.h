/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_NLSJac12 6
  int Flowsheet_functionJacNLSJac12_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianNLSJac12(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac12 */
#define $PMaterialStream2_xliqSeedNLSJac12 data->simulationInfo->analyticJacobians[6].seedVars[0]
#define $PMaterialStream2_x_pc_3_2SeedNLSJac12 data->simulationInfo->analyticJacobians[6].seedVars[1]
#define $PMaterialStream2_x_pc_2_1SeedNLSJac12 data->simulationInfo->analyticJacobians[6].seedVars[2]
#define $PMaterialStream2_x_pc_3_1SeedNLSJac12 data->simulationInfo->analyticJacobians[6].seedVars[3]
#define $PMaterialStream2_x_pc_2_2SeedNLSJac12 data->simulationInfo->analyticJacobians[6].seedVars[4]
#define _$PMaterialStream2$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[6].tmpVars[0]
#define $PMaterialStream2$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12 _$PMaterialStream2$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$PMaterialStream2$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[6].tmpVars[1]
#define $PMaterialStream2$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12 _$PMaterialStream2$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$PHeater1$Pxvapout$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[6].tmpVars[2]
#define $PHeater1$Pxvapout$P$pDERNLSJac12$PdummyVarNLSJac12 _$PHeater1$Pxvapout$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P5$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[6].resultVars[4]
#define $P$res$P5$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P5$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P4$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[6].resultVars[3]
#define $P$res$P4$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P4$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P3$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[6].resultVars[2]
#define $P$res$P3$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P3$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P2$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[6].resultVars[1]
#define $P$res$P2$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P2$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[6].resultVars[0]
#define $P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_NLSJac11 5
  int Flowsheet_functionJacNLSJac11_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianNLSJac11(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac11 */
#define $PMaterialStream1_xliqSeedNLSJac11 data->simulationInfo->analyticJacobians[5].seedVars[0]
#define $PMaterialStream1_x_pc_2_1SeedNLSJac11 data->simulationInfo->analyticJacobians[5].seedVars[1]
#define $PMaterialStream1_x_pc_3_1SeedNLSJac11 data->simulationInfo->analyticJacobians[5].seedVars[2]
#define $PMaterialStream1_x_pc_3_2SeedNLSJac11 data->simulationInfo->analyticJacobians[5].seedVars[3]
#define $PMaterialStream1_x_pc_2_2SeedNLSJac11 data->simulationInfo->analyticJacobians[5].seedVars[4]
#define _$PMaterialStream1$PF_p$P2$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[5].tmpVars[0]
#define $PMaterialStream1$PF_p$P2$P$pDERNLSJac11$PdummyVarNLSJac11 _$PMaterialStream1$PF_p$P2$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$PMaterialStream1$PF_p$P3$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[5].tmpVars[1]
#define $PMaterialStream1$PF_p$P3$P$pDERNLSJac11$PdummyVarNLSJac11 _$PMaterialStream1$PF_p$P3$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$PHeater1$Pxvapin$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[5].tmpVars[2]
#define $PHeater1$Pxvapin$P$pDERNLSJac11$PdummyVarNLSJac11 _$PHeater1$Pxvapin$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$P$res$P5$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[5].resultVars[4]
#define $P$res$P5$P$pDERNLSJac11$PdummyVarNLSJac11 _$P$res$P5$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$P$res$P4$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[5].resultVars[3]
#define $P$res$P4$P$pDERNLSJac11$PdummyVarNLSJac11 _$P$res$P4$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$P$res$P3$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[5].resultVars[2]
#define $P$res$P3$P$pDERNLSJac11$PdummyVarNLSJac11 _$P$res$P3$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$P$res$P2$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[5].resultVars[1]
#define $P$res$P2$P$pDERNLSJac11$PdummyVarNLSJac11 _$P$res$P2$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#define _$P$res$P1$P$pDERNLSJac11$PdummyVarNLSJac11(i) data->simulationInfo->analyticJacobians[5].resultVars[0]
#define $P$res$P1$P$pDERNLSJac11$PdummyVarNLSJac11 _$P$res$P1$P$pDERNLSJac11$PdummyVarNLSJac11(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_NLSJac10 4
  int Flowsheet_functionJacNLSJac10_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianNLSJac10(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac10 */
#define $PMaterialStream1_xliqSeedNLSJac10 data->simulationInfo->analyticJacobians[4].seedVars[0]
#define $PMaterialStream1_x_pc_2_1SeedNLSJac10 data->simulationInfo->analyticJacobians[4].seedVars[1]
#define $PMaterialStream1_x_pc_3_2SeedNLSJac10 data->simulationInfo->analyticJacobians[4].seedVars[2]
#define $PMaterialStream1_x_pc_2_2SeedNLSJac10 data->simulationInfo->analyticJacobians[4].seedVars[3]
#define $PMaterialStream1_x_pc_3_1SeedNLSJac10 data->simulationInfo->analyticJacobians[4].seedVars[4]
#define _$PMaterialStream1$PF_p$P2$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[4].tmpVars[0]
#define $PMaterialStream1$PF_p$P2$P$pDERNLSJac10$PdummyVarNLSJac10 _$PMaterialStream1$PF_p$P2$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$PMaterialStream1$PF_p$P3$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[4].tmpVars[1]
#define $PMaterialStream1$PF_p$P3$P$pDERNLSJac10$PdummyVarNLSJac10 _$PMaterialStream1$PF_p$P3$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$PHeater1$Pxvapin$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[4].tmpVars[2]
#define $PHeater1$Pxvapin$P$pDERNLSJac10$PdummyVarNLSJac10 _$PHeater1$Pxvapin$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$P$res$P5$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[4].resultVars[4]
#define $P$res$P5$P$pDERNLSJac10$PdummyVarNLSJac10 _$P$res$P5$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$P$res$P4$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[4].resultVars[3]
#define $P$res$P4$P$pDERNLSJac10$PdummyVarNLSJac10 _$P$res$P4$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$P$res$P3$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[4].resultVars[2]
#define $P$res$P3$P$pDERNLSJac10$PdummyVarNLSJac10 _$P$res$P3$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$P$res$P2$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[4].resultVars[1]
#define $P$res$P2$P$pDERNLSJac10$PdummyVarNLSJac10 _$P$res$P2$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#define _$P$res$P1$P$pDERNLSJac10$PdummyVarNLSJac10(i) data->simulationInfo->analyticJacobians[4].resultVars[0]
#define $P$res$P1$P$pDERNLSJac10$PdummyVarNLSJac10 _$P$res$P1$P$pDERNLSJac10$PdummyVarNLSJac10(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_NLSJac9 3
  int Flowsheet_functionJacNLSJac9_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianNLSJac9(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac9 */
#define $PMaterialStream2_xliqSeedNLSJac9 data->simulationInfo->analyticJacobians[3].seedVars[0]
#define $PMaterialStream2_x_pc_2_2SeedNLSJac9 data->simulationInfo->analyticJacobians[3].seedVars[1]
#define $PMaterialStream2_x_pc_2_1SeedNLSJac9 data->simulationInfo->analyticJacobians[3].seedVars[2]
#define $PMaterialStream2_x_pc_3_1SeedNLSJac9 data->simulationInfo->analyticJacobians[3].seedVars[3]
#define $PMaterialStream2_x_pc_3_2SeedNLSJac9 data->simulationInfo->analyticJacobians[3].seedVars[4]
#define _$PMaterialStream2$PF_p$P2$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[3].tmpVars[0]
#define $PMaterialStream2$PF_p$P2$P$pDERNLSJac9$PdummyVarNLSJac9 _$PMaterialStream2$PF_p$P2$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$PMaterialStream2$PF_p$P3$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[3].tmpVars[1]
#define $PMaterialStream2$PF_p$P3$P$pDERNLSJac9$PdummyVarNLSJac9 _$PMaterialStream2$PF_p$P3$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$PHeater1$Pxvapout$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[3].tmpVars[2]
#define $PHeater1$Pxvapout$P$pDERNLSJac9$PdummyVarNLSJac9 _$PHeater1$Pxvapout$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$P$res$P5$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[3].resultVars[4]
#define $P$res$P5$P$pDERNLSJac9$PdummyVarNLSJac9 _$P$res$P5$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$P$res$P4$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[3].resultVars[3]
#define $P$res$P4$P$pDERNLSJac9$PdummyVarNLSJac9 _$P$res$P4$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$P$res$P3$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[3].resultVars[2]
#define $P$res$P3$P$pDERNLSJac9$PdummyVarNLSJac9 _$P$res$P3$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$P$res$P2$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[3].resultVars[1]
#define $P$res$P2$P$pDERNLSJac9$PdummyVarNLSJac9 _$P$res$P2$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#define _$P$res$P1$P$pDERNLSJac9$PdummyVarNLSJac9(i) data->simulationInfo->analyticJacobians[3].resultVars[0]
#define $P$res$P1$P$pDERNLSJac9$PdummyVarNLSJac9 _$P$res$P1$P$pDERNLSJac9$PdummyVarNLSJac9(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_LSJac8 2
  int Flowsheet_functionJacLSJac8_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianLSJac8(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* LSJac8 */
#define $PMaterialStream1_FvapgSeedLSJac8 data->simulationInfo->analyticJacobians[2].seedVars[0]
#define _$PMaterialStream1$PFliqg$P$pDERLSJac8$PdummyVarLSJac8(i) data->simulationInfo->analyticJacobians[2].tmpVars[0]
#define $PMaterialStream1$PFliqg$P$pDERLSJac8$PdummyVarLSJac8 _$PMaterialStream1$PFliqg$P$pDERLSJac8$PdummyVarLSJac8(0)

#define _$P$res$P1$P$pDERLSJac8$PdummyVarLSJac8(i) data->simulationInfo->analyticJacobians[2].resultVars[0]
#define $P$res$P1$P$pDERLSJac8$PdummyVarLSJac8 _$P$res$P1$P$pDERLSJac8$PdummyVarLSJac8(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_LSJac5 1
  int Flowsheet_functionJacLSJac5_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianLSJac5(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* LSJac5 */
#define $PMaterialStream2_FvapgSeedLSJac5 data->simulationInfo->analyticJacobians[1].seedVars[0]
#define _$PMaterialStream2$PFliqg$P$pDERLSJac5$PdummyVarLSJac5(i) data->simulationInfo->analyticJacobians[1].tmpVars[0]
#define $PMaterialStream2$PFliqg$P$pDERLSJac5$PdummyVarLSJac5 _$PMaterialStream2$PFliqg$P$pDERLSJac5$PdummyVarLSJac5(0)

#define _$P$res$P1$P$pDERLSJac5$PdummyVarLSJac5(i) data->simulationInfo->analyticJacobians[1].resultVars[0]
#define $P$res$P1$P$pDERLSJac5$PdummyVarLSJac5 _$P$res$P1$P$pDERLSJac5$PdummyVarLSJac5(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_LSJac2 0
  int Flowsheet_functionJacLSJac2_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianLSJac2(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* LSJac2 */
#define $PHeater1_FvapgSeedLSJac2 data->simulationInfo->analyticJacobians[0].seedVars[0]
#define _$PHeater1$PFliqg$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].tmpVars[0]
#define $PHeater1$PFliqg$P$pDERLSJac2$PdummyVarLSJac2 _$PHeater1$PFliqg$P$pDERLSJac2$PdummyVarLSJac2(0)

#define _$P$res$P1$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].resultVars[0]
#define $P$res$P1$P$pDERLSJac2$PdummyVarLSJac2 _$P$res$P1$P$pDERLSJac2$PdummyVarLSJac2(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_A 10
  int Flowsheet_functionJacA_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_B 9
  int Flowsheet_functionJacB_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_C 8
  int Flowsheet_functionJacC_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_D 7
  int Flowsheet_functionJacD_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */


