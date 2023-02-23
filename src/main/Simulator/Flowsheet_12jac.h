/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_NLSJac16 7
  int Flowsheet_functionJacNLSJac16_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianNLSJac16(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac16 */
#define $PMixer1_xvapin_s_2SeedNLSJac16 data->simulationInfo->analyticJacobians[7].seedVars[0]
#define $PMaterialStream2_x_pc_3_2SeedNLSJac16 data->simulationInfo->analyticJacobians[7].seedVars[1]
#define $PMaterialStream2_x_pc_3_1SeedNLSJac16 data->simulationInfo->analyticJacobians[7].seedVars[2]
#define $PMaterialStream2_x_pc_2_1SeedNLSJac16 data->simulationInfo->analyticJacobians[7].seedVars[3]
#define $PMaterialStream2_x_pc_2_2SeedNLSJac16 data->simulationInfo->analyticJacobians[7].seedVars[4]
#define _$PMaterialStream2$PF_p$P3$P$pDERNLSJac16$PdummyVarNLSJac16(i) data->simulationInfo->analyticJacobians[7].tmpVars[0]
#define $PMaterialStream2$PF_p$P3$P$pDERNLSJac16$PdummyVarNLSJac16 _$PMaterialStream2$PF_p$P3$P$pDERNLSJac16$PdummyVarNLSJac16(0)

#define _$PMaterialStream2$PF_p$P2$P$pDERNLSJac16$PdummyVarNLSJac16(i) data->simulationInfo->analyticJacobians[7].tmpVars[1]
#define $PMaterialStream2$PF_p$P2$P$pDERNLSJac16$PdummyVarNLSJac16 _$PMaterialStream2$PF_p$P2$P$pDERNLSJac16$PdummyVarNLSJac16(0)

#define _$PMaterialStream2$Pxliq$P$pDERNLSJac16$PdummyVarNLSJac16(i) data->simulationInfo->analyticJacobians[7].tmpVars[2]
#define $PMaterialStream2$Pxliq$P$pDERNLSJac16$PdummyVarNLSJac16 _$PMaterialStream2$Pxliq$P$pDERNLSJac16$PdummyVarNLSJac16(0)

#define _$P$res$P5$P$pDERNLSJac16$PdummyVarNLSJac16(i) data->simulationInfo->analyticJacobians[7].resultVars[4]
#define $P$res$P5$P$pDERNLSJac16$PdummyVarNLSJac16 _$P$res$P5$P$pDERNLSJac16$PdummyVarNLSJac16(0)

#define _$P$res$P4$P$pDERNLSJac16$PdummyVarNLSJac16(i) data->simulationInfo->analyticJacobians[7].resultVars[3]
#define $P$res$P4$P$pDERNLSJac16$PdummyVarNLSJac16 _$P$res$P4$P$pDERNLSJac16$PdummyVarNLSJac16(0)

#define _$P$res$P3$P$pDERNLSJac16$PdummyVarNLSJac16(i) data->simulationInfo->analyticJacobians[7].resultVars[2]
#define $P$res$P3$P$pDERNLSJac16$PdummyVarNLSJac16 _$P$res$P3$P$pDERNLSJac16$PdummyVarNLSJac16(0)

#define _$P$res$P2$P$pDERNLSJac16$PdummyVarNLSJac16(i) data->simulationInfo->analyticJacobians[7].resultVars[1]
#define $P$res$P2$P$pDERNLSJac16$PdummyVarNLSJac16 _$P$res$P2$P$pDERNLSJac16$PdummyVarNLSJac16(0)

#define _$P$res$P1$P$pDERNLSJac16$PdummyVarNLSJac16(i) data->simulationInfo->analyticJacobians[7].resultVars[0]
#define $P$res$P1$P$pDERNLSJac16$PdummyVarNLSJac16 _$P$res$P1$P$pDERNLSJac16$PdummyVarNLSJac16(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_NLSJac15 6
  int Flowsheet_functionJacNLSJac15_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianNLSJac15(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac15 */
#define $PMixer1_xvapin_s_1SeedNLSJac15 data->simulationInfo->analyticJacobians[6].seedVars[0]
#define $PMaterialStream1_x_pc_2_2SeedNLSJac15 data->simulationInfo->analyticJacobians[6].seedVars[1]
#define $PMaterialStream1_x_pc_3_2SeedNLSJac15 data->simulationInfo->analyticJacobians[6].seedVars[2]
#define $PMaterialStream1_x_pc_2_1SeedNLSJac15 data->simulationInfo->analyticJacobians[6].seedVars[3]
#define $PMaterialStream1_x_pc_3_1SeedNLSJac15 data->simulationInfo->analyticJacobians[6].seedVars[4]
#define _$PMaterialStream1$PF_p$P3$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[6].tmpVars[0]
#define $PMaterialStream1$PF_p$P3$P$pDERNLSJac15$PdummyVarNLSJac15 _$PMaterialStream1$PF_p$P3$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$PMaterialStream1$PF_p$P2$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[6].tmpVars[1]
#define $PMaterialStream1$PF_p$P2$P$pDERNLSJac15$PdummyVarNLSJac15 _$PMaterialStream1$PF_p$P2$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$PMaterialStream1$Pxliq$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[6].tmpVars[2]
#define $PMaterialStream1$Pxliq$P$pDERNLSJac15$PdummyVarNLSJac15 _$PMaterialStream1$Pxliq$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$P$res$P5$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[6].resultVars[4]
#define $P$res$P5$P$pDERNLSJac15$PdummyVarNLSJac15 _$P$res$P5$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$P$res$P4$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[6].resultVars[3]
#define $P$res$P4$P$pDERNLSJac15$PdummyVarNLSJac15 _$P$res$P4$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$P$res$P3$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[6].resultVars[2]
#define $P$res$P3$P$pDERNLSJac15$PdummyVarNLSJac15 _$P$res$P3$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$P$res$P2$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[6].resultVars[1]
#define $P$res$P2$P$pDERNLSJac15$PdummyVarNLSJac15 _$P$res$P2$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#define _$P$res$P1$P$pDERNLSJac15$PdummyVarNLSJac15(i) data->simulationInfo->analyticJacobians[6].resultVars[0]
#define $P$res$P1$P$pDERNLSJac15$PdummyVarNLSJac15 _$P$res$P1$P$pDERNLSJac15$PdummyVarNLSJac15(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_NLSJac13 5
  int Flowsheet_functionJacNLSJac13_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianNLSJac13(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac13 */
#define $PMixer1_xvapin_s_2SeedNLSJac13 data->simulationInfo->analyticJacobians[5].seedVars[0]
#define $PMaterialStream2_x_pc_3_2SeedNLSJac13 data->simulationInfo->analyticJacobians[5].seedVars[1]
#define $PMaterialStream2_x_pc_2_2SeedNLSJac13 data->simulationInfo->analyticJacobians[5].seedVars[2]
#define $PMaterialStream2_x_pc_2_1SeedNLSJac13 data->simulationInfo->analyticJacobians[5].seedVars[3]
#define $PMaterialStream2_x_pc_3_1SeedNLSJac13 data->simulationInfo->analyticJacobians[5].seedVars[4]
#define _$PMaterialStream2$PF_p$P3$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[5].tmpVars[0]
#define $PMaterialStream2$PF_p$P3$P$pDERNLSJac13$PdummyVarNLSJac13 _$PMaterialStream2$PF_p$P3$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$PMaterialStream2$PF_p$P2$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[5].tmpVars[1]
#define $PMaterialStream2$PF_p$P2$P$pDERNLSJac13$PdummyVarNLSJac13 _$PMaterialStream2$PF_p$P2$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$PMaterialStream2$Pxliq$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[5].tmpVars[2]
#define $PMaterialStream2$Pxliq$P$pDERNLSJac13$PdummyVarNLSJac13 _$PMaterialStream2$Pxliq$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$P$res$P5$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[5].resultVars[4]
#define $P$res$P5$P$pDERNLSJac13$PdummyVarNLSJac13 _$P$res$P5$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$P$res$P4$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[5].resultVars[3]
#define $P$res$P4$P$pDERNLSJac13$PdummyVarNLSJac13 _$P$res$P4$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$P$res$P3$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[5].resultVars[2]
#define $P$res$P3$P$pDERNLSJac13$PdummyVarNLSJac13 _$P$res$P3$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$P$res$P2$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[5].resultVars[1]
#define $P$res$P2$P$pDERNLSJac13$PdummyVarNLSJac13 _$P$res$P2$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#define _$P$res$P1$P$pDERNLSJac13$PdummyVarNLSJac13(i) data->simulationInfo->analyticJacobians[5].resultVars[0]
#define $P$res$P1$P$pDERNLSJac13$PdummyVarNLSJac13 _$P$res$P1$P$pDERNLSJac13$PdummyVarNLSJac13(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_NLSJac12 4
  int Flowsheet_functionJacNLSJac12_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianNLSJac12(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac12 */
#define $PMixer1_xvapin_s_1SeedNLSJac12 data->simulationInfo->analyticJacobians[4].seedVars[0]
#define $PMaterialStream1_x_pc_3_1SeedNLSJac12 data->simulationInfo->analyticJacobians[4].seedVars[1]
#define $PMaterialStream1_x_pc_3_2SeedNLSJac12 data->simulationInfo->analyticJacobians[4].seedVars[2]
#define $PMaterialStream1_x_pc_2_2SeedNLSJac12 data->simulationInfo->analyticJacobians[4].seedVars[3]
#define $PMaterialStream1_x_pc_2_1SeedNLSJac12 data->simulationInfo->analyticJacobians[4].seedVars[4]
#define _$PMaterialStream1$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[4].tmpVars[0]
#define $PMaterialStream1$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12 _$PMaterialStream1$PF_p$P3$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$PMaterialStream1$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[4].tmpVars[1]
#define $PMaterialStream1$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12 _$PMaterialStream1$PF_p$P2$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$PMaterialStream1$Pxliq$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[4].tmpVars[2]
#define $PMaterialStream1$Pxliq$P$pDERNLSJac12$PdummyVarNLSJac12 _$PMaterialStream1$Pxliq$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P5$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[4].resultVars[4]
#define $P$res$P5$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P5$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P4$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[4].resultVars[3]
#define $P$res$P4$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P4$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P3$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[4].resultVars[2]
#define $P$res$P3$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P3$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P2$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[4].resultVars[1]
#define $P$res$P2$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P2$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#define _$P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12(i) data->simulationInfo->analyticJacobians[4].resultVars[0]
#define $P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12 _$P$res$P1$P$pDERNLSJac12$PdummyVarNLSJac12(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_LSJac11 3
  int Flowsheet_functionJacLSJac11_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianLSJac11(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* LSJac11 */
#define $PMaterialStream1_FvapgSeedLSJac11 data->simulationInfo->analyticJacobians[3].seedVars[0]
#define _$PMaterialStream1$PFliqg$P$pDERLSJac11$PdummyVarLSJac11(i) data->simulationInfo->analyticJacobians[3].tmpVars[0]
#define $PMaterialStream1$PFliqg$P$pDERLSJac11$PdummyVarLSJac11 _$PMaterialStream1$PFliqg$P$pDERLSJac11$PdummyVarLSJac11(0)

#define _$P$res$P1$P$pDERLSJac11$PdummyVarLSJac11(i) data->simulationInfo->analyticJacobians[3].resultVars[0]
#define $P$res$P1$P$pDERLSJac11$PdummyVarLSJac11 _$P$res$P1$P$pDERLSJac11$PdummyVarLSJac11(0)

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
#define $PMaterialStream2_FliqgSeedLSJac8 data->simulationInfo->analyticJacobians[2].seedVars[0]
#define _$PMaterialStream2$PFvapg$P$pDERLSJac8$PdummyVarLSJac8(i) data->simulationInfo->analyticJacobians[2].tmpVars[0]
#define $PMaterialStream2$PFvapg$P$pDERLSJac8$PdummyVarLSJac8 _$PMaterialStream2$PFvapg$P$pDERLSJac8$PdummyVarLSJac8(0)

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
#define $PMixer1_FvapgSeedLSJac5 data->simulationInfo->analyticJacobians[1].seedVars[0]
#define _$PMixer1$PFliqg$P$pDERLSJac5$PdummyVarLSJac5(i) data->simulationInfo->analyticJacobians[1].tmpVars[0]
#define $PMixer1$PFliqg$P$pDERLSJac5$PdummyVarLSJac5 _$PMixer1$PFliqg$P$pDERLSJac5$PdummyVarLSJac5(0)

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
#define $PMaterialStream3_FvapgSeedLSJac2 data->simulationInfo->analyticJacobians[0].seedVars[0]
#define _$PMaterialStream3$PFliqg$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].tmpVars[0]
#define $PMaterialStream3$PFliqg$P$pDERLSJac2$PdummyVarLSJac2 _$PMaterialStream3$PFliqg$P$pDERLSJac2$PdummyVarLSJac2(0)

#define _$P$res$P1$P$pDERLSJac2$PdummyVarLSJac2(i) data->simulationInfo->analyticJacobians[0].resultVars[0]
#define $P$res$P1$P$pDERLSJac2$PdummyVarLSJac2 _$P$res$P1$P$pDERLSJac2$PdummyVarLSJac2(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_A 11
  int Flowsheet_functionJacA_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_B 10
  int Flowsheet_functionJacB_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_C 9
  int Flowsheet_functionJacC_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Flowsheet_INDEX_JAC_D 8
  int Flowsheet_functionJacD_column(void* data, threadData_t *threadData);
  int Flowsheet_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */


