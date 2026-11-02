//
// File: QC2015P_SECC.h
//
// Code generated for Simulink model 'QC2015P_SECC'.
//
// Model version                  : 1.607
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Mon Nov  2 19:23:22 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_QC2015P_SECC_h_
#define RTW_HEADER_QC2015P_SECC_h_
#include <math.h>
#include "rtwtypes.h"
#include "can_fd_message.h"
#include "QC2015P_SECC_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <cstring>

extern "C"
{

#include "rtGetNaN.h"

}

#include <cmath>
#include "can_message.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Type definition for custom storage class: Struct
struct rt_Simulink_Struct_type {
  real_T CCS_Cycle_Va;                 // Referenced by: '<S31>/CCS_Cycle_Va'
  real_T CEM_Cycle_Va;                 // Referenced by: '<S31>/CEM_Cycle_Va'
  real_T CHM_Cycle_Va;                 // Referenced by: '<S31>/CHM_Cycle_Va'
  real_T CML_Cycle_Va;                 // Referenced by: '<S31>/CML_Cycle_Va'
  real_T CONTROL_SECC_Cycle_Va; // Referenced by: '<S95>/CONTROL_SECC_Cycle_Va'
  real_T CRM_Cycle_Va;                 // Referenced by: '<S31>/CRM_Cycle_Va'
  real_T CRO_Cycle_Va;                 // Referenced by: '<S31>/CRO_Cycle_Va'
  real_T CSD_Cycle_Va;                 // Referenced by: '<S31>/CSD_Cycle_Va'
  real_T CST_Cycle_Va;                 // Referenced by: '<S31>/CST_Cycle_Va'
  real_T LM_SECC_Cycle_Va;           // Referenced by: '<S95>/LM_SECC_Cycle_Va'
  real_T PGI21_A_Max;                  // Referenced by: '<S5>/PGI21_A_Max'
  real_T PGI21_A_Min;                  // Referenced by: '<S5>/PGI21_A_Min'
  real_T PGI21_V_Max;                  // Referenced by: '<S5>/PGI21_V_Max'
  real_T PGI21_V_Min;                  // Referenced by: '<S5>/PGI21_V_Min'
  real_T PGI75_MaxOutput_A_Va;    // Referenced by: '<S5>/PGI75_MaxOutput_A_Va'
  real_T PGI76_A_Exe_Va;               // Referenced by: '<S5>/PGI76_A_Exe_Va'
  real_T PGI76_V_Exe_Va;               // Referenced by: '<S5>/PGI76_V_Exe_Va'
  real_T PGI93_ChargeCapacity_Va;
                               // Referenced by: '<S5>/PGI93_ChargeCapacity_Va'
  real_T PGI93_DishargeCapacity_Va;
                             // Referenced by: '<S5>/PGI93_DishargeCapacity_Va'
  real_T SM_RM_SECC_Cycle_Va;     // Referenced by: '<S95>/SM_RM_SECC_Cycle_Va'
  real_T SM_URM_SECC_Cycle_Va;   // Referenced by: '<S95>/SM_URM_SECC_Cycle_Va'
  real_T SPN2560_CRM_BMSIdentify_Va;
                            // Referenced by: '<S4>/SPN2560_CRM_BMSIdentify_Va'
  real_T SPN2561_CRM_ChargerIndex_Va;
                           // Referenced by: '<S4>/SPN2561_CRM_ChargerIndex_Va'
  real_T SPN2562_CRM_ChargerLocationCode_Va;
                    // Referenced by: '<S4>/SPN2562_CRM_ChargerLocationCode_Va'
  real_T SPN2600_CHM_ProtocolVer_Va;
                            // Referenced by: '<S4>/SPN2600_CHM_ProtocolVer_Va'
  real_T SPN2824_CML_OutputVoltage_MAX_Va;
                      // Referenced by: '<S4>/SPN2824_CML_OutputVoltage_MAX_Va'
  real_T SPN2825_CML_OutputVoltage_MIN_Va;
                      // Referenced by: '<S4>/SPN2825_CML_OutputVoltage_MIN_Va'
  real_T SPN2826_CML_OutputCurrent_MAX_Va;
                      // Referenced by: '<S4>/SPN2826_CML_OutputCurrent_MAX_Va'
  real_T SPN2827_CML_OutputCurrent_MIN_Va;
                      // Referenced by: '<S4>/SPN2827_CML_OutputCurrent_MIN_Va'
  real_T SPN2830_CRO_ChargerReadyOrNot_Va;
                     // Referenced by: '<S4>/SPN2830_CRO_ChargerReadyOrNot_Va1'
  real_T SPN3081_CCS_VoltageOutputValue_Va;
                     // Referenced by: '<S4>/SPN3081_CCS_VoltageOutputValue_Va'
  real_T SPN3082_CCS_ChargingCurrentValue_Va;
                   // Referenced by: '<S4>/SPN3082_CCS_ChargingCurrentValue_Va'
  real_T SPN3083_CCS_ChargingAllow_Va;
                          // Referenced by: '<S4>/SPN3083_CCS_ChargingAllow_Va'
  real_T SPN3083_CCS_CumulativeChargeTime_Va;
                   // Referenced by: '<S4>/SPN3083_CCS_CumulativeChargeTime_Va'
  real_T SPN3521_CST_PauseChrgRes_Active_Va;
                    // Referenced by: '<S4>/SPN3521_CST_PauseChrgRes_Active_Va'
  real_T SPN3521_CST_PauseChrgRes_Cond_Va;
                      // Referenced by: '<S4>/SPN3521_CST_PauseChrgRes_Cond_Va'
  real_T SPN3521_CST_PauseChrgRes_Flt_Va;
                       // Referenced by: '<S4>/SPN3521_CST_PauseChrgRes_Flt_Va'
  real_T SPN3521_CST_PauseChrgRes_Man_Va;
                       // Referenced by: '<S4>/SPN3521_CST_PauseChrgRes_Man_Va'
  real_T SPN3522_CST_PauseChrgflt_Con_Va;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Con_Va'
  real_T SPN3522_CST_PauseChrgflt_IntTem_Va;
                    // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_IntTem_Va'
  real_T SPN3522_CST_PauseChrgflt_Oth_Va;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Oth_Va'
  real_T SPN3522_CST_PauseChrgflt_Qua_Va;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Qua_Va'
  real_T SPN3522_CST_PauseChrgflt_Sud_Va;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Sud_Va'
  real_T SPN3522_CST_PauseChrgflt_Tem_Va;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Tem_Va'
  real_T SPN3523_CST_PauseChrgErr_Cur_Va;
                       // Referenced by: '<S4>/SPN3523_CST_PauseChrgErr_Cur_Va'
  real_T SPN3523_CST_PauseChrgErr_Vol_Va;
                       // Referenced by: '<S4>/SPN3523_CST_PauseChrgErr_Vol_Va'
  real_T SPN3611_CSD_ChrgTime_Va;
                               // Referenced by: '<S4>/SPN3611_CSD_ChrgTime_Va'
  real_T SPN3612_CSD_Energy_OutPower_Va;
                        // Referenced by: '<S4>/SPN3612_CSD_Energy_OutPower_Va'
  real_T SPN3613_CSD_ChrgNum_Va;// Referenced by: '<S4>/SPN3613_CSD_ChrgNum_Va'
  real_T TP_CTS_Cycle_Va;             // Referenced by: '<S31>/TP_CTS_Cycle_Va'
  real_T VC_SECC_Cycle_Va;           // Referenced by: '<S95>/VC_SECC_Cycle_Va'
  boolean_T Authen_Pass;               // Referenced by: '<S5>/Authen_Pass'
  boolean_T CCS_Data_SW;               // Referenced by: '<S31>/CCS_Data_SW'
  boolean_T CCS_Enable_SW;             // Referenced by: '<S31>/CCS_Enable_SW'
  boolean_T CCS_Enable_Va;             // Referenced by: '<S31>/CCS_Enable_Va'
  boolean_T CEM_Data_SW;               // Referenced by: '<S31>/CEM_Data_SW'
  boolean_T CEM_Enable_SW;             // Referenced by: '<S31>/CEM_Enable_SW'
  boolean_T CEM_Enable_Va;             // Referenced by: '<S31>/CEM_Enable_Va'
  boolean_T CHM_Data_SW;               // Referenced by: '<S31>/CHM_Data_SW'
  boolean_T CHM_Enable_SW;             // Referenced by: '<S31>/CHM_Enable_SW'
  boolean_T CHM_Enable_Va;             // Referenced by: '<S31>/CHM_Enable_Va'
  boolean_T CML_Data_SW;               // Referenced by: '<S31>/CML_Data_SW'
  boolean_T CML_Enable_SW;             // Referenced by: '<S31>/CML_Enable_SW'
  boolean_T CML_Enable_Va;             // Referenced by: '<S31>/CML_Enable_Va'
  boolean_T CONTROL_SECC_Data_SW;// Referenced by: '<S95>/CONTROL_SECC_Data_SW'
  boolean_T CONTROL_SECC_Enable_SW;
                               // Referenced by: '<S95>/CONTROL_SECC_Enable_SW'
  boolean_T CONTROL_SECC_Enable_Va;
                               // Referenced by: '<S95>/CONTROL_SECC_Enable_Va'
  boolean_T CRM_Data_SW;               // Referenced by: '<S31>/CRM_Data_SW'
  boolean_T CRM_Enable_SW;             // Referenced by: '<S31>/CRM_Enable_SW'
  boolean_T CRM_Enable_Va;             // Referenced by: '<S31>/CRM_Enable_Va'
  boolean_T CRO_Data_SW;               // Referenced by: '<S31>/CRO_Data_SW'
  boolean_T CRO_Enable_SW;             // Referenced by: '<S31>/CRO_Enable_SW'
  boolean_T CRO_Enable_Va;             // Referenced by: '<S31>/CRO_Enable_Va'
  boolean_T CSD_Data_SW;               // Referenced by: '<S31>/CSD_Data_SW'
  boolean_T CSD_Enable_SW;             // Referenced by: '<S31>/CSD_Enable_SW'
  boolean_T CSD_Enable_Va;             // Referenced by: '<S31>/CSD_Enable_Va'
  boolean_T CST_Data_SW;               // Referenced by: '<S31>/CST_Data_SW'
  boolean_T CST_Enable_SW;             // Referenced by: '<S31>/CST_Enable_SW'
  boolean_T CST_Enable_Va;             // Referenced by: '<S31>/CST_Enable_Va'
  boolean_T Card;                      // Referenced by: '<Root>/Card'
  boolean_T LM_SECC_Data_SW;          // Referenced by: '<S95>/LM_SECC_Data_SW'
  boolean_T LM_SECC_Enable_SW;      // Referenced by: '<S95>/LM_SECC_Enable_SW'
  boolean_T LM_SECC_Enable_Va;      // Referenced by: '<S95>/LM_SECC_Enable_Va'
  boolean_T PGI01_Enable;              // Referenced by: '<S5>/PGI01_Enable'
  boolean_T PGI03_Enable;              // Referenced by: '<S5>/PGI03_Enable'
  boolean_T PGI05_Enable;              // Referenced by: '<S5>/PGI05_Enable'
  boolean_T PGI05_K1_SW;               // Referenced by: '<S5>/PGI05_K1_SW'
  boolean_T PGI05_K2_SW;               // Referenced by: '<S5>/PGI05_K2_SW'
  boolean_T PGI07_ELock_SW;            // Referenced by: '<S5>/PGI07_ELock_SW'
  boolean_T PGI07_Enable;              // Referenced by: '<S5>/PGI07_Enable'
  boolean_T PGI08_Enable;              // Referenced by: '<S5>/PGI08_Enable'
  boolean_T PGI08_wakeup_SW;           // Referenced by: '<S5>/PGI08_wakeup_SW'
  boolean_T PGI11_Enable;              // Referenced by: '<S5>/PGI11_Enable'
  boolean_T PGI21_Enable;              // Referenced by: '<S5>/PGI21_Enable'
  boolean_T PGI31_CAuthenStatus_SW;
                                // Referenced by: '<S5>/PGI31_CAuthenStatus_SW'
  boolean_T PGI31_Enable;              // Referenced by: '<S5>/PGI31_Enable'
  boolean_T PGI33_AuthenResult_SW;
                                 // Referenced by: '<S5>/PGI33_AuthenResult_SW'
  boolean_T PGI33_Enable;              // Referenced by: '<S5>/PGI33_Enable'
  boolean_T PGI33_SAuthenFDC_SW;   // Referenced by: '<S5>/PGI33_SAuthenFDC_SW'
  boolean_T PGI51_Data_SW;             // Referenced by: '<S5>/PGI51_Data_SW'
  boolean_T PGI51_Enable;              // Referenced by: '<S5>/PGI51_Enable'
  boolean_T PGI71_ChargerReady_SW;
                                 // Referenced by: '<S5>/PGI71_ChargerReady_SW'
  boolean_T PGI71_Enable;              // Referenced by: '<S5>/PGI71_Enable'
  boolean_T PGI75_Enable;              // Referenced by: '<S5>/PGI75_Enable'
  boolean_T PGI75_MaxOutput_A_SW; // Referenced by: '<S5>/PGI75_MaxOutput_A_SW'
  boolean_T PGI75_OutputChangeReason_SW;
                           // Referenced by: '<S5>/PGI75_OutputChangeReason_SW'
  boolean_T PGI76_A_Exe_SW;            // Referenced by: '<S5>/PGI76_A_Exe_SW'
  boolean_T PGI76_Enable;              // Referenced by: '<S5>/PGI76_Enable'
  boolean_T PGI76_V_Exe_SW;            // Referenced by: '<S5>/PGI76_V_Exe_SW'
  boolean_T PGI78_Enable;              // Referenced by: '<S5>/PGI78_Enable'
  boolean_T PGI78_Pause_SW;            // Referenced by: '<S5>/PGI78_Pause_SW'
  boolean_T PGI92_AllowDetectCheck_SW;
                             // Referenced by: '<S5>/PGI92_AllowDetectCheck_SW'
  boolean_T PGI92_Enable;              // Referenced by: '<S5>/PGI92_Enable'
  boolean_T PGI93_ChargeCapacity_SW;
                               // Referenced by: '<S5>/PGI93_ChargeCapacity_SW'
  boolean_T PGI93_DishargeCapacity_SW;
                             // Referenced by: '<S5>/PGI93_DishargeCapacity_SW'
  boolean_T PGI93_Enable;              // Referenced by: '<S5>/PGI93_Enable'
  boolean_T SECC_2015P_Enable;     // Referenced by: '<Root>/SECC_2015P_Enable'
  boolean_T SECC_ChargeSta;           // Referenced by: '<Root>/SECC_ChargeSta'
  boolean_T SECC_DefineMsg_Enable;
                                // Referenced by: '<S95>/SECC_DefineMsg_Enable'
  boolean_T SECC_DiagSW;               // Referenced by: '<S5>/SECC_DiagSW'
  boolean_T SECC_LM_Pause;             // Referenced by: '<S5>/SECC_LM_Pause'
  boolean_T SECC_LM_STOPRecv;         // Referenced by: '<S5>/SECC_LM_STOPRecv'
  boolean_T SECC_LM_STOPSend;         // Referenced by: '<S5>/SECC_LM_STOPSend'
  boolean_T SECC_ManualSTOP;           // Referenced by: '<S5>/SECC_ManualSTOP'
  boolean_T SECC_Pause;                // Referenced by:
                                          //  '<S4>/Constant10'
                                          //  '<S4>/Constant9'
                                          //  '<S5>/Constant53'

  boolean_T SECC_ProtocolVersion_SW;
                               // Referenced by: '<S5>/SECC_ProtocolVersion_SW'
  boolean_T SECC_Reboot;               // Referenced by: '<S5>/SECC_Reboot'
  boolean_T SECC_Relink;               // Referenced by: '<S5>/SECC_Relink'
  boolean_T SECC_VNMan_SW;             // Referenced by: '<S5>/SECC_VNMan_SW'
  boolean_T SECC_VersionResult_SW;
                                 // Referenced by: '<S5>/SECC_VersionResult_SW'
  boolean_T SM_RM_SECC_Data_SW;    // Referenced by: '<S95>/SM_RM_SECC_Data_SW'
  boolean_T SM_RM_SECC_Enable_SW;// Referenced by: '<S95>/SM_RM_SECC_Enable_SW'
  boolean_T SM_RM_SECC_Enable_Va;// Referenced by: '<S95>/SM_RM_SECC_Enable_Va'
  boolean_T SM_URM_SECC_Data_SW;  // Referenced by: '<S95>/SM_URM_SECC_Data_SW'
  boolean_T SM_URM_SECC_Enable_SW;
                                // Referenced by: '<S95>/SM_URM_SECC_Enable_SW'
  boolean_T SM_URM_SECC_Enable_Va;
                                // Referenced by: '<S95>/SM_URM_SECC_Enable_Va'
  boolean_T SPN2560_CRM_BMSIdentify_SW;
                            // Referenced by: '<S4>/SPN2560_CRM_BMSIdentify_SW'
  boolean_T SPN2561_CRM_ChargerIndex_SW;
                           // Referenced by: '<S4>/SPN2561_CRM_ChargerIndex_SW'
  boolean_T SPN2562_CRM_ChargerLocationCode_SW;
                    // Referenced by: '<S4>/SPN2562_CRM_ChargerLocationCode_SW'
  boolean_T SPN2600_CHM_ProtocolVer_SW;
                            // Referenced by: '<S4>/SPN2600_CHM_ProtocolVer_SW'
  boolean_T SPN2824_CML_OutputVoltage_MAX_SW;
                      // Referenced by: '<S4>/SPN2824_CML_OutputVoltage_MAX_SW'
  boolean_T SPN2825_CML_OutputVoltage_MIN_SW;
                      // Referenced by: '<S4>/SPN2825_CML_OutputVoltage_MIN_SW'
  boolean_T SPN2826_CML_OutputCurrent_MAX_SW;
                      // Referenced by: '<S4>/SPN2826_CML_OutputCurrent_MAX_SW'
  boolean_T SPN2827_CML_OutputCurrent_MIN_SW;
                      // Referenced by: '<S4>/SPN2827_CML_OutputCurrent_MIN_SW'
  boolean_T SPN2830_CRO_ChargerReadyOrNot_SW;
                     // Referenced by: '<S4>/SPN2830_CRO_ChargerReadyOrNot_SW1'
  boolean_T SPN3081_CCS_VoltageOutputValue_SW;
                     // Referenced by: '<S4>/SPN3081_CCS_VoltageOutputValue_SW'
  boolean_T SPN3082_CCS_ChargingCurrentValue_SW;
                   // Referenced by: '<S4>/SPN3082_CCS_ChargingCurrentValue_SW'
  boolean_T SPN3083_CCS_ChargingAllow_SW;
                          // Referenced by: '<S4>/SPN3083_CCS_ChargingAllow_SW'
  boolean_T SPN3083_CCS_CumulativeChargeTime_SW;
                   // Referenced by: '<S4>/SPN3083_CCS_CumulativeChargeTime_SW'
  boolean_T SPN3521_CST_PauseChrgRes_Active_SW;
                    // Referenced by: '<S4>/SPN3521_CST_PauseChrgRes_Active_SW'
  boolean_T SPN3521_CST_PauseChrgRes_Cond_SW;
                      // Referenced by: '<S4>/SPN3521_CST_PauseChrgRes_Cond_SW'
  boolean_T SPN3521_CST_PauseChrgRes_Flt_SW;
                       // Referenced by: '<S4>/SPN3521_CST_PauseChrgRes_Flt_SW'
  boolean_T SPN3521_CST_PauseChrgRes_Man_SW;
                       // Referenced by: '<S4>/SPN3521_CST_PauseChrgRes_Man_SW'
  boolean_T SPN3522_CST_PauseChrgflt_Con_SW;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Con_SW'
  boolean_T SPN3522_CST_PauseChrgflt_IntTem_SW;
                    // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_IntTem_SW'
  boolean_T SPN3522_CST_PauseChrgflt_Oth_SW;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Oth_SW'
  boolean_T SPN3522_CST_PauseChrgflt_Qua_SW;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Qua_SW'
  boolean_T SPN3522_CST_PauseChrgflt_Sud_SW;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Sud_SW'
  boolean_T SPN3522_CST_PauseChrgflt_Tem_SW;
                       // Referenced by: '<S4>/SPN3522_CST_PauseChrgflt_Tem_SW'
  boolean_T SPN3523_CST_PauseChrgErr_Cur_SW;
                       // Referenced by: '<S4>/SPN3523_CST_PauseChrgErr_Cur_SW'
  boolean_T SPN3523_CST_PauseChrgErr_Vol_SW;
                       // Referenced by: '<S4>/SPN3523_CST_PauseChrgErr_Vol_SW'
  boolean_T SPN3611_CSD_ChrgTime_SW;
                               // Referenced by: '<S4>/SPN3611_CSD_ChrgTime_SW'
  boolean_T SPN3612_CSD_Energy_OutPower_SW;
                        // Referenced by: '<S4>/SPN3612_CSD_Energy_OutPower_SW'
  boolean_T SPN3613_CSD_ChrgNum_SW;
                                // Referenced by: '<S4>/SPN3613_CSD_ChrgNum_SW'
  boolean_T TP_CTS_Data_SW;            // Referenced by: '<S31>/TP_CTS_Data_SW'
  boolean_T TP_CTS_Enable_SW;        // Referenced by: '<S31>/TP_CTS_Enable_SW'
  boolean_T TP_CTS_Enable_Va;        // Referenced by: '<S31>/TP_CTS_Enable_Va'
  boolean_T VC_SECC_Data_SW;          // Referenced by: '<S95>/VC_SECC_Data_SW'
  boolean_T VC_SECC_Enable_SW;      // Referenced by: '<S95>/VC_SECC_Enable_SW'
  boolean_T VC_SECC_Enable_Va;      // Referenced by: '<S95>/VC_SECC_Enable_Va'
  uint16_T PGI01_FCFDC_20;             // Referenced by: '<S5>/PGI01_FCFDC_20'
  uint16_T PGI01_FCFDC_30;             // Referenced by: '<S5>/PGI01_FCFDC_30'
  uint16_T PGI01_FCFDC_40;             // Referenced by: '<S5>/PGI01_FCFDC_40'
  uint16_T PGI01_FCFDC_50;             // Referenced by: '<S5>/PGI01_FCFDC_50'
  uint16_T PGI01_FCFDC_60;             // Referenced by: '<S5>/PGI01_FCFDC_60'
  uint16_T PGI01_FCFDC_70;             // Referenced by: '<S5>/PGI01_FCFDC_70'
  uint16_T PGI01_FCFDC_80;             // Referenced by: '<S5>/PGI01_FCFDC_80'
  uint32_T SECC_CVList[4];             // Referenced by: '<S5>/CvList'
  uint32_T SECC_DefineMsg_Cycle; // Referenced by: '<S95>/SECC_DefineMsg_Cycle'
  uint32_T SECC_DefineMsg_ID;       // Referenced by: '<S95>/SECC_DefineMsg_ID'
  uint32_T SECC_ProtocolVersion_Va;
                               // Referenced by: '<S5>/SECC_ProtocolVersion_Va'
  uint8_T CCS_Data_Va[8];              // Referenced by: '<S31>/CCS_Data_Va'
  uint8_T CEM_Data_Va[8];              // Referenced by: '<S31>/CEM_Data_Va'
  uint8_T CHM_Data_Va[8];              // Referenced by: '<S31>/CHM_Data_Va'
  uint8_T CML_Data_Va[8];              // Referenced by: '<S31>/CML_Data_Va'
  uint8_T CONTROL_SECC_Data_Va[8];
                                 // Referenced by: '<S95>/CONTROL_SECC_Data_Va'
  uint8_T CRM_Data_Va[8];              // Referenced by: '<S31>/CRM_Data_Va'
  uint8_T CRO_Data_Va[8];              // Referenced by: '<S31>/CRO_Data_Va'
  uint8_T CSD_Data_Va[8];              // Referenced by: '<S31>/CSD_Data_Va'
  uint8_T CST_Data_Va[8];              // Referenced by: '<S31>/CST_Data_Va'
  uint8_T LM_SECC_Data_Va[8];         // Referenced by: '<S95>/LM_SECC_Data_Va'
  uint8_T PGI01;                       // Referenced by: '<S5>/PGI01'
  uint8_T PGI03_Data[8];               // Referenced by: '<S5>/PGI03_Data'
  uint8_T PGI05;                       // Referenced by: '<S5>/PGI05'
  uint8_T PGI05_K1_Va;                 // Referenced by: '<S5>/PGI05_K1_Va'
  uint8_T PGI05_K2_Va;                 // Referenced by: '<S5>/PGI05_K2_Va'
  uint8_T PGI07;                       // Referenced by: '<S5>/PGI07'
  uint8_T PGI07_ELock_Va;              // Referenced by: '<S5>/PGI07_ELock_Va'
  uint8_T PGI08;                       // Referenced by: '<S5>/PGI08'
  uint8_T PGI08_wakeup_Va;             // Referenced by: '<S5>/PGI08_wakeup_Va'
  uint8_T PGI11;                       // Referenced by: '<S5>/PGI11'
  uint8_T PGI11_Authentic[8];          // Referenced by: '<S5>/PGI11_Authentic'
  uint8_T PGI11_EndOfCharge[8];      // Referenced by: '<S5>/PGI11_EndOfCharge'
  uint8_T PGI11_OutLoopDete[8];      // Referenced by: '<S5>/PGI11_OutLoopDete'
  uint8_T PGI11_ParmCfg[8];            // Referenced by: '<S5>/PGI11_ParmCfg'
  uint8_T PGI11_PowerMode[8];          // Referenced by: '<S5>/PGI11_PowerMode'
  uint8_T PGI11_PreChgEnTrans[8];  // Referenced by: '<S5>/PGI11_PreChgEnTrans'
  uint8_T PGI11_Scheduled[8];          // Referenced by: '<S5>/PGI11_Scheduled'
  uint8_T PGI21;                       // Referenced by: '<S5>/PGI21'
  uint8_T PGI21_RebotTimes;           // Referenced by: '<S5>/PGI21_RebotTimes'
  uint8_T PGI31;                       // Referenced by: '<S5>/PGI31'
  uint8_T PGI31_CAuthenStatus_Va;
                                // Referenced by: '<S5>/PGI31_CAuthenStatus_Va'
  uint8_T PGI31_MTime2;                // Referenced by: '<S5>/PGI31_MTime2'
  uint8_T PGI33;                       // Referenced by: '<S5>/PGI33'
  uint8_T PGI33_AuthenResult_Va; // Referenced by: '<S5>/PGI33_AuthenResult_Va'
  uint8_T PGI33_SAuthenFDC_Va;     // Referenced by: '<S5>/PGI33_SAuthenFDC_Va'
  uint8_T PGI51_Data_Va[8];            // Referenced by: '<S5>/PGI51_Data_Va'
  uint8_T PGI71;                       // Referenced by: '<S5>/PGI71'
  uint8_T PGI71_ChargerReady_Va; // Referenced by: '<S5>/PGI71_ChargerReady_Va'
  uint8_T PGI75;                       // Referenced by: '<S5>/PGI75'
  uint8_T PGI75_OutputChangeReason_Va;
                           // Referenced by: '<S5>/PGI75_OutputChangeReason_Va'
  uint8_T PGI76;                       // Referenced by: '<S5>/PGI76'
  uint8_T PGI78;                       // Referenced by: '<S5>/PGI78'
  uint8_T PGI78_Pause_Va;              // Referenced by: '<S5>/PGI78_Pause_Va'
  uint8_T PGI92;                       // Referenced by: '<S5>/PGI922'
  uint8_T PGI92_AllowDetectCheck_Va;
                             // Referenced by: '<S5>/PGI92_AllowDetectCheck_Va'
  uint8_T PGI93;                       // Referenced by: '<S5>/PGI93'
  uint8_T SECC_CANType;                // Referenced by: '<S5>/SECC_CANType'
  uint8_T SECC_CPVersion;              // Referenced by: '<S5>/SECC_CPVersion'
  uint8_T SECC_DefineMsg_Data[8]; // Referenced by: '<S95>/SECC_DefineMsg_Data'
  uint8_T SECC_DefineMsg_Extended;
                              // Referenced by: '<S95>/SECC_DefineMsg_Extended'
  uint8_T SECC_DefineMsg_Length;// Referenced by: '<S95>/SECC_DefineMsg_Length'
  uint8_T SECC_K_Limit;                // Referenced by: '<S5>/SECC_K_Limit'
  uint8_T SECC_Reserved_VN;           // Referenced by: '<S5>/SECC_Reserved_VN'
  uint8_T SECC_TLVersion;              // Referenced by: '<S5>/SECC_TLVersion'
  uint8_T SECC_VersionResult_Va; // Referenced by: '<S5>/SECC_VersionResult_Va'
  uint8_T SM_RM_SECC_Data_Va[8];   // Referenced by: '<S95>/SM_RM_SECC_Data_Va'
  uint8_T SM_URM_SECC_Data_Va[8]; // Referenced by: '<S95>/SM_URM_SECC_Data_Va'
  uint8_T TP_CTS_Data_Va[8];           // Referenced by: '<S31>/TP_CTS_Data_Va'
  uint8_T VC_SECC_Data_Va[8];         // Referenced by: '<S95>/VC_SECC_Data_Va'
};

extern CAN_DATATYPE CAN_DATATYPE_GROUND;

// External data declarations for dependent source files
extern const CAN_MESSAGE_BUS QC2015P_SECC_rtZCAN_MESSAGE_BUS;// CAN_MESSAGE_BUS ground 

// Exported data declaration

// Declaration for custom storage class: Struct
extern rt_Simulink_Struct_type rt_Simulink_Struct;

// Class declaration for model QC2015P_SECC
class QC2015P_SECC final
{
  // public data and function members
 public:
  // Block signals for system '<S4>/MAIN_CNT'
  struct B_MAIN_CNT_QC2015P_SECC_T {
    real_T m50_1;                      // '<S4>/MAIN_CNT'
    real_T m50_11;                     // '<S4>/MAIN_CNT'
    real_T m50_21;                     // '<S4>/MAIN_CNT'
    real_T m50_31;                     // '<S4>/MAIN_CNT'
    real_T m50_41;                     // '<S4>/MAIN_CNT'
    real_T m50_2;                      // '<S4>/MAIN_CNT'
    real_T m50_12;                     // '<S4>/MAIN_CNT'
    real_T m10_3;                      // '<S4>/MAIN_CNT'
    real_T m10_4;                      // '<S4>/MAIN_CNT'
    real_T m10_5;                      // '<S4>/MAIN_CNT'
    real_T m10_6;                      // '<S4>/MAIN_CNT'
  };

  // Block states (default storage) for system '<S4>/MAIN_CNT'
  struct DW_MAIN_CNT_QC2015P_SECC_T {
    real_T timer;                      // '<S4>/MAIN_CNT'
    uint8_T is_active_c32_QC2015P_SECC;// '<S4>/MAIN_CNT'
    uint8_T is_c32_QC2015P_SECC;       // '<S4>/MAIN_CNT'
  };

  // Block states (default storage) for system '<S31>/sendCyclic'
  struct DW_sendCyclic_QC2015P_SECC_T {
    real_T cnt;                        // '<S31>/sendCyclic'
    uint8_T is_active_c33_QC2015P_SECC;// '<S31>/sendCyclic'
    uint8_T is_c33_QC2015P_SECC;       // '<S31>/sendCyclic'
  };

  // Block states (default storage) for system '<S4>/keep1_for10ms'
  struct DW_keep1_for10ms_QC2015P_SECC_T {
    uint8_T is_active_c42_QC2015P_SECC;// '<S4>/keep1_for10ms'
    uint8_T is_c42_QC2015P_SECC;       // '<S4>/keep1_for10ms'
    uint8_T temporalCounter_i1;        // '<S4>/keep1_for10ms'
  };

  // Block states (default storage) for system '<S4>/normal250'
  struct DW_normal250_QC2015P_SECC_T {
    real_T cnt;                        // '<S4>/normal250'
    uint8_T is_active_c44_QC2015P_SECC;// '<S4>/normal250'
    uint8_T is_c44_QC2015P_SECC;       // '<S4>/normal250'
  };

  // Block states (default storage) for system '<S5>/normal1000_50for3'
  struct DW_normal1000_50for3_QC2015P__T {
    real_T times;                      // '<S5>/normal1000_50for3'
    real_T cnt;                        // '<S5>/normal1000_50for3'
    uint8_T is_active_c1_QC2015P_SECC; // '<S5>/normal1000_50for3'
    uint8_T is_c1_QC2015P_SECC;        // '<S5>/normal1000_50for3'
  };

  // Block states (default storage) for system '<S5>/normal250_'
  struct DW_normal250__QC2015P_SECC_T {
    real_T cnt;                        // '<S5>/normal250_'
    uint8_T is_active_c2_QC2015P_SECC; // '<S5>/normal250_'
    uint8_T is_c2_QC2015P_SECC;        // '<S5>/normal250_'
  };

  // Block signals (default storage)
  struct B_QC2015P_SECC_T {
    CAN_FD_MESSAGE_BUS CANFDPack1;     // '<S5>/CAN FD Pack1'
    CAN_FD_MESSAGE_BUS CANFDPack;      // '<S5>/CAN FD Pack'
    CAN_MSG_BUS Switch4;               // '<S6>/Switch4'
    CAN_MSG_BUS Switch4_b;             // '<S13>/Switch4'
    CAN_MSG_BUS Switch4_n;             // '<S7>/Switch4'
    CAN_MSG_BUS Switch4_l;             // '<S14>/Switch4'
    CAN_MSG_BUS Switch4_nu;            // '<S12>/Switch4'
    CAN_MSG_BUS Switch4_a;             // '<S17>/Switch4'
    CAN_MSG_BUS Switch4_d;             // '<S8>/Switch4'
    CAN_MSG_BUS Switch4_c;             // '<S15>/Switch4'
    CAN_MSG_BUS Switch4_i;             // '<S9>/Switch4'
    CAN_MSG_BUS Switch4_p;             // '<S18>/Switch4'
    CAN_MSG_BUS Switch4_m;             // '<S16>/Switch4'
    CAN_MSG_BUS Switch4_h;             // '<S19>/Switch4'
    CAN_MSG_BUS Switch4_cs;            // '<S10>/Switch4'
    CAN_MSG_BUS Switch4_mu;            // '<S11>/Switch4'
    CAN_MESSAGE_BUS CANPack6;          // '<S95>/CAN Pack6'
    CAN_MESSAGE_BUS CANPack;           // '<S95>/CAN Pack'
    CAN_MESSAGE_BUS CANPack1;          // '<S95>/CAN Pack1'
    CAN_MESSAGE_BUS CANPack2;          // '<S95>/CAN Pack2'
    CAN_MESSAGE_BUS CANPack3;          // '<S95>/CAN Pack3'
    CAN_MESSAGE_BUS CANPack4;          // '<S95>/CAN Pack4'
    CAN_MESSAGE_BUS VectorConcatenate[6];// '<S95>/Vector Concatenate'
    CAN_MESSAGE_BUS CANPack1_l;        // '<S4>/CAN Pack1'
    CAN_MESSAGE_BUS CANPack19;         // '<S4>/CAN Pack19'
    CAN_MESSAGE_BUS CANPack22;         // '<S4>/CAN Pack22'
    CAN_MESSAGE_BUS CANPack26;         // '<S4>/CAN Pack26'
    CAN_MESSAGE_BUS CANPack27;         // '<S4>/CAN Pack27'
    CAN_MESSAGE_BUS CANPack29;         // '<S4>/CAN Pack29'
    CAN_MESSAGE_BUS CANPack32;         // '<S4>/CAN Pack32'
    CAN_MESSAGE_BUS CANPack_c;         // '<S31>/CAN Pack'
    CAN_MESSAGE_BUS CANPack1_ly;       // '<S31>/CAN Pack1'
    CAN_MESSAGE_BUS CANPack2_d;        // '<S31>/CAN Pack2'
    CAN_MESSAGE_BUS CANPack3_i;        // '<S31>/CAN Pack3'
    CAN_MESSAGE_BUS CANPack4_j;        // '<S31>/CAN Pack4'
    CAN_MESSAGE_BUS CANPack5;          // '<S31>/CAN Pack5'
    CAN_MESSAGE_BUS CANPack6_n;        // '<S31>/CAN Pack6'
    CAN_MESSAGE_BUS CANPack7;          // '<S31>/CAN Pack7'
    CAN_MESSAGE_BUS CANPack8;          // '<S31>/CAN Pack8'
    CAN_MESSAGE_BUS VectorConcatenate_d[9];// '<S31>/Vector Concatenate'
    real_T PGI02_check;                // '<S3>/CAN Unpack'
    real_T PGI04_STOP_reason0;         // '<S3>/CAN Unpack'
    real_T PGI04_STOP_reason1;         // '<S3>/CAN Unpack'
    real_T PGI04_STOP_type;            // '<S3>/CAN Unpack'
    real_T PGI04_reLink;               // '<S3>/CAN Unpack'
    real_T PGI09_wakeup;               // '<S3>/CAN Unpack'
    real_T PGI12_Authentic;            // '<S3>/CAN Unpack'
    real_T PGI12_EndOfCharge;          // '<S3>/CAN Unpack'
    real_T PGI12_OutLoopDete;          // '<S3>/CAN Unpack'
    real_T PGI12_ParmCfg;              // '<S3>/CAN Unpack'
    real_T PGI12_PowerMode;            // '<S3>/CAN Unpack'
    real_T PGI12_PreChgEnTrans;        // '<S3>/CAN Unpack'
    real_T PGI12_Scheduled;            // '<S3>/CAN Unpack'
    real_T PGI36_FDCType;              // '<S3>/CAN Unpack'
    real_T PGI3A_FDCType;              // '<S3>/CAN Unpack'
    real_T PGI52_CheckState;           // '<S3>/CAN Unpack'
    real_T PGI79_Pause;                // '<S3>/CAN Unpack'
    real_T PGI94_SOC;                  // '<S3>/CAN Unpack'
    real_T S_EVCC_PGI;                 // '<S3>/CAN Unpack'
    real_T EVCC_CANType;               // '<S3>/CAN Unpack7'
    real_T EVCC_CPVersoin;             // '<S3>/CAN Unpack7'
    real_T EVCC_ProtocolVersion0;      // '<S3>/CAN Unpack7'
    real_T EVCC_ProtocolVersion1;      // '<S3>/CAN Unpack7'
    real_T EVCC_ProtocolVersion2;      // '<S3>/CAN Unpack7'
    real_T EVCC_Reserved;              // '<S3>/CAN Unpack7'
    real_T EVCC_TLVersion;             // '<S3>/CAN Unpack7'
    real_T EVCC_VersionResult;         // '<S3>/CAN Unpack7'
    real_T PGI06_K5;                   // '<S3>/CAN Unpack1'
    real_T PGI06_K6;                   // '<S3>/CAN Unpack1'
    real_T PGI32_VAuthenStatus;        // '<S3>/CAN Unpack1'
    real_T PGI72_EVCCReady;            // '<S3>/CAN Unpack1'
    real_T PGI72_EVCC_V_Exe;           // '<S3>/CAN Unpack1'
    real_T PGI73_A;                    // '<S3>/CAN Unpack1'
    real_T PGI73_PowerMode;            // '<S3>/CAN Unpack1'
    real_T PGI73_V;                    // '<S3>/CAN Unpack1'
    real_T PGI74_SOC;                  // '<S3>/CAN Unpack1'
    real_T PGI74_TimeRemain;           // '<S3>/CAN Unpack1'
    real_T PGI77_SingleBattTemp_Max;   // '<S3>/CAN Unpack1'
    real_T PGI77_SingleBattTemp_Min;   // '<S3>/CAN Unpack1'
    real_T PGI77_SingleBattV_Max;      // '<S3>/CAN Unpack1'
    real_T PGI77_SingleBattV_Min;      // '<S3>/CAN Unpack1'
    real_T PGI91_EVCCDetectSta;        // '<S3>/CAN Unpack1'
    real_T SU_EVCC_PGI;                // '<S3>/CAN Unpack1'
    real_T Ctrl_EVCC_Byte0;            // '<S3>/CAN Unpack3'
    real_T confirmPGI;                 // '<S3>/CAN Unpack3'
    real_T recvedByteTotal;            // '<S3>/CAN Unpack3'
    real_T recvedNumTotal;             // '<S3>/CAN Unpack3'
    real_T waitRecvNumStart;           // '<S3>/CAN Unpack3'
    real_T waitRecvNumTotal;           // '<S3>/CAN Unpack3'
    real_T SPN3085_BSM_NumberHighestVB;// '<S3>/CAN Unpack9'
    real_T SPN3086_BSM_BatteryHighsestTemp;// '<S3>/CAN Unpack9'
    real_T SPN3087_BSM_NumHTemTestingPoint;// '<S3>/CAN Unpack9'
    real_T SPN3088_BSM_BatteryLowestTemp;// '<S3>/CAN Unpack9'
    real_T SPN3089_BSM_NumLTemTestingPoint;// '<S3>/CAN Unpack9'
    real_T SPN3090_BSM_CellVoltageState;// '<S3>/CAN Unpack9'
    real_T SPN3091_BSM_VehicleBatterySOC;// '<S3>/CAN Unpack9'
    real_T SPN3092_BSM_ChargingOverCurrent;// '<S3>/CAN Unpack9'
    real_T SPN3093_BSM_BatteryTemState;// '<S3>/CAN Unpack9'
    real_T SPN3094_BSM_BatInsulationState;// '<S3>/CAN Unpack9'
    real_T SPN3095_BSM_BatOutputConState;// '<S3>/CAN Unpack9'
    real_T SPN3096_BSM_ChargingPermit; // '<S3>/CAN Unpack9'
    real_T SPN2829_BRO_BMSReadyOrNot;  // '<S3>/CAN Unpack11'
    real_T SPN3072_BCL_VoltageRequirement;// '<S3>/CAN Unpack2'
    real_T SPN3073_BCL_CurrentRequirement;// '<S3>/CAN Unpack2'
    real_T SPN3074_BCL_ChargingModel;  // '<S3>/CAN Unpack2'
    real_T SPN3511_BST_PauseChrgRes_Active;// '<S3>/CAN Unpack14'
    real_T SPN3511_BST_PauseChrgRes_CeVol;// '<S3>/CAN Unpack14'
    real_T SPN3511_BST_PauseChrgRes_SOC;// '<S3>/CAN Unpack14'
    real_T SPN3511_BST_PauseChrgRes_ToVol;// '<S3>/CAN Unpack14'
    real_T SPN3512_BST_PauseChrgflt_BMS;// '<S3>/CAN Unpack14'
    real_T SPN3512_BST_PauseChrgflt_Con;// '<S3>/CAN Unpack14'
    real_T SPN3512_BST_PauseChrgflt_HVRela;// '<S3>/CAN Unpack14'
    real_T SPN3512_BST_PauseChrgflt_Ins;// '<S3>/CAN Unpack14'
    real_T SPN3512_BST_PauseChrgflt_Oth;// '<S3>/CAN Unpack14'
    real_T SPN3512_BST_PauseChrgflt_OutCon;// '<S3>/CAN Unpack14'
    real_T SPN3512_BST_PauseChrgflt_OverT;// '<S3>/CAN Unpack14'
    real_T SPN3512_BST_PauseChrgflt_TPoint;// '<S3>/CAN Unpack14'
    real_T SPN3513_BST_PauseChrgErr_Cur;// '<S3>/CAN Unpack14'
    real_T SPN3513_BST_PauseChrgErr_Vol;// '<S3>/CAN Unpack14'
    real_T NOSPN_BEM_Other;            // '<S3>/CAN Unpack5'
    real_T SPN3901_BEM_RSPN256000_OverTim;// '<S3>/CAN Unpack5'
    real_T SPN3902_BEM_RSPN2560AA_OverTim;// '<S3>/CAN Unpack5'
    real_T SPN3903_BEM_CTSCML_OverTim; // '<S3>/CAN Unpack5'
    real_T SPN3904_BEM_CRO_OverTim;    // '<S3>/CAN Unpack5'
    real_T SPN3905_BEM_CCS_OverTim;    // '<S3>/CAN Unpack5'
    real_T SPN3906_BEM_CST_OverTim;    // '<S3>/CAN Unpack5'
    real_T SPN3907_BEM_CSD_OverTim;    // '<S3>/CAN Unpack5'
    real_T SPN2601_BHM_ChargeTotalVolt_MAX;// '<S3>/CAN Unpack6'
    real_T SPN3601_BSD_SOC_end;        // '<S3>/CAN Unpack8'
    real_T SPN3602_BSD_MinCellU;       // '<S3>/CAN Unpack8'
    real_T SPN3603_BSD_MaxCellU;       // '<S3>/CAN Unpack8'
    real_T SPN3604_BSD_MinBatT;        // '<S3>/CAN Unpack8'
    real_T SPN3605_BSD_MaxBatT;        // '<S3>/CAN Unpack8'
    real_T CANFDUnpack_o1;             // '<S5>/CAN FD Unpack'
    real_T CANFDUnpack_o2;             // '<S5>/CAN FD Unpack'
    real_T CANFDUnpack_o3;             // '<S5>/CAN FD Unpack'
    real_T CANFDUnpack_o4;             // '<S5>/CAN FD Unpack'
    real_T CANFDUnpack_o5;             // '<S5>/CAN FD Unpack'
    real_T CANFDUnpack_o6;             // '<S5>/CAN FD Unpack'
    real_T CANFDUnpack_o7;             // '<S5>/CAN FD Unpack'
    real_T CANFDUnpack_o8;             // '<S5>/CAN FD Unpack'
    real_T CANFDUnpack_o9;             // '<S5>/CAN FD Unpack'
    real_T Switch6;                    // '<S5>/Switch6'
    real_T DataTypeConversion26;       // '<S5>/Data Type Conversion26'
    real_T RandomNumber;               // '<S5>/Random Number'
    real_T RandomNumber1;              // '<S5>/Random Number1'
    real_T DataTypeConversion10[5];    // '<S5>/Data Type Conversion10'
    real_T enable_m;                   // '<S5>/normal250_3'
    real_T enable_g;                   // '<S5>/normal250_2'
    real_T enable_i;                   // '<S5>/normal250_1'
    real_T enable_o;                   // '<S5>/normal250_'
    real_T enable_gd;                  // '<S5>/normal1000_50for3_1'
    real_T enable_c;                   // '<S5>/normal1000_50for3_'
    real_T enable_ol;                  // '<S5>/normal1000_50for3'
    real_T enable_mj;                  // '<S5>/normal1000'
    real_T outPGI;                     // '<S5>/keep1_for10ms'
    real_T outNextStep;                // '<S5>/VN'
    real_T VersionResult;              // '<S5>/VN'
    real_T VN_Enable;                  // '<S5>/VN'
    real_T DetectAllow;                // '<S5>/QC2015P_STOP'
    real_T RelinkAllow;                // '<S5>/QC2015P_STOP'
    real_T RebootAllow;                // '<S5>/QC2015P_STOP'
    real_T SEQ;                        // '<S5>/QC2015P_MAIN'
    real_T ReStart;                    // '<S5>/QC2015P_MAIN'
    real_T enable_l;                   // '<S95>/sendCyclic5'
    real_T enable_a;                   // '<S95>/sendCyclic4'
    real_T enable_f;                   // '<S95>/sendCyclic3'
    real_T enable_mg;                  // '<S95>/sendCyclic2'
    real_T enable_a4;                  // '<S95>/sendCyclic1'
    real_T enable_h;                   // '<S95>/sendCyclic'
    real_T LM_NACK;                    // '<S5>/LM_Send'
    real_T sendFlg;                    // '<S5>/LM_Send'
    real_T n_num;                      // '<S5>/LM_Send'
    real_T sendFlg_o;                  // '<S5>/LM_Recv'
    real_T n_num_k;                    // '<S5>/LM_Recv'
    real_T k_num;                      // '<S5>/LM_Recv'
    real_T recv_tfra;                  // '<S5>/LM_Recv'
    real_T totalBytes;                 // '<S5>/LM_Recv'
    real_T Sw1;                        // '<S4>/Sw1'
    real_T Sw7;                        // '<S4>/Sw7'
    real_T Sw6;                        // '<S4>/Sw6'
    real_T Sw5;                        // '<S4>/Sw5'
    real_T Sw4;                        // '<S4>/Sw4'
    real_T RandomNumber_i;             // '<S4>/Random Number'
    real_T Sw65;                       // '<S4>/Sw65'
    real_T RandomNumber1_l;            // '<S4>/Random Number1'
    real_T Sw66;                       // '<S4>/Sw66'
    real_T Sw85;                       // '<S4>/Sw85'
    real_T Sw88;                       // '<S4>/Sw88'
    real_T Sw87;                       // '<S4>/Sw87'
    real_T Sw86;                       // '<S4>/Sw86'
    real_T Sw84;                       // '<S4>/Sw84'
    real_T Sw83;                       // '<S4>/Sw83'
    real_T Sw82;                       // '<S4>/Sw82'
    real_T Sw81;                       // '<S4>/Sw81'
    real_T Sw80;                       // '<S4>/Sw80'
    real_T Sw79;                       // '<S4>/Sw79'
    real_T Sw78;                       // '<S4>/Sw78'
    real_T Sw77;                       // '<S4>/Sw77'
    real_T Sw113;                      // '<S4>/Sw113'
    real_T Sw111;                      // '<S4>/Sw111'
    real_T Sw112;                      // '<S4>/Sw112'
    real_T Sw67;                       // '<S4>/Sw67'
    real_T Sw8;                        // '<S4>/Sw8'
    real_T Sw50;                       // '<S4>/Sw50'
    real_T Sw49;                       // '<S4>/Sw49'
    real_T Sw48;                       // '<S4>/Sw48'
    real_T Sw9;                        // '<S4>/Sw9'
    real_T ChargeCapacity;             // '<S4>/Data Type Conversion12'
    real_T SEQ_g;                      // '<S4>/Data Type Conversion11'
    real_T TmpBufferAtTmpGroundAtBusCreato;
    real_T TmpBufferAtTmpGroundAtBusCrea_p;
    real_T TmpBufferAtTmpGroundAtBusCrea_m;
    real_T enable_p;                   // '<S4>/normal250_5'
    real_T enable_lc;                  // '<S4>/normal250_4'
    real_T enable_n;                   // '<S4>/normal250_3'
    real_T enable_e;                   // '<S4>/normal250_2'
    real_T enable_ic;                  // '<S4>/normal250_1'
    real_T enable_at;                  // '<S4>/normal250'
    real_T enable_k;                   // '<S31>/sendCyclic8'
    real_T enable_j;                   // '<S31>/sendCyclic7'
    real_T enable_d;                   // '<S31>/sendCyclic6'
    real_T enable_ll;                  // '<S31>/sendCyclic5'
    real_T enable_ch;                  // '<S31>/sendCyclic4'
    real_T enable_eu;                  // '<S31>/sendCyclic3'
    real_T enable_ey;                  // '<S31>/sendCyclic2'
    real_T enable_b;                   // '<S31>/sendCyclic1'
    real_T enable_be;                  // '<S31>/sendCyclic'
    real_T CTS_Enable;                 // '<S4>/J1939_TP.CM_Recv'
    real_T counter;                    // '<S4>/Chart'
    uint32_T LocalVersion;             // '<S5>/VN'
    uint8_T RX_Status;                 // '<S3>/CAN Unpack'
    uint8_T RX_Status_e;               // '<S3>/CAN Unpack7'
    uint8_T RX_Status_p;               // '<S3>/CAN Unpack1'
    uint8_T RX_Status_m;               // '<S3>/CAN Unpack3'
    uint8_T Data[8];                   // '<S3>/CAN Unpack4'
    uint8_T RX_Status_j;               // '<S3>/CAN Unpack4'
    uint8_T RX_Status_c;               // '<S3>/CAN Unpack9'
    uint8_T RX_Status_a;               // '<S3>/CAN Unpack11'
    uint8_T RX_Status_n;               // '<S3>/CAN Unpack2'
    uint8_T RX_Status_me;              // '<S3>/CAN Unpack14'
    uint8_T RX_Status_ao;              // '<S3>/CAN Unpack5'
    uint8_T RX_Status_f;               // '<S3>/CAN Unpack6'
    uint8_T RX_Status_jw;              // '<S3>/CAN Unpack8'
    uint8_T Data_o[8];                 // '<S3>/CAN Unpack10'
    uint8_T RX_Status_pc;              // '<S3>/CAN Unpack10'
    uint8_T Data_b[8];                 // '<S3>/CAN Unpack12'
    uint8_T RX_Status_pa;              // '<S3>/CAN Unpack12'
    uint8_T Switch45[16];              // '<S5>/Switch45'
    uint8_T Transpose[8];              // '<S5>/Transpose'
    uint8_T Switch8[8];                // '<S95>/Switch8'
    uint8_T Switch12[8];               // '<S95>/Switch12'
    uint8_T Switch10[8];               // '<S95>/Switch10'
    uint8_T Switch5[8];                // '<S95>/Switch5'
    uint8_T Switch14[8];               // '<S95>/Switch14'
    uint8_T PGI_Enable[255];           // '<S5>/QC2015P_MAIN'
    uint8_T Data_PGI03[8];             // '<S5>/QC2015P_MAIN'
    uint8_T K1;                        // '<S5>/QC2015P_MAIN'
    uint8_T K2;                        // '<S5>/QC2015P_MAIN'
    uint8_T Elock;                     // '<S5>/QC2015P_MAIN'
    uint8_T PGI71_ChargerReady;        // '<S5>/QC2015P_MAIN'
    uint8_T PGI51_Data[8];             // '<S5>/QC2015P_MAIN'
    uint8_T PGI08_wakeup;              // '<S5>/QC2015P_MAIN'
    uint8_T Switch10_h[8];             // '<S31>/Switch10'
    uint8_T Switch6_f[8];              // '<S31>/Switch6'
    uint8_T Switch2[8];                // '<S31>/Switch2'
    uint8_T Switch5_b[8];              // '<S31>/Switch5'
    uint8_T Switch13[8];               // '<S31>/Switch13'
    uint8_T Switch16[8];               // '<S31>/Switch16'
    uint8_T Switch19[8];               // '<S31>/Switch19'
    uint8_T Switch22[8];               // '<S31>/Switch22'
    uint8_T Switch25[8];               // '<S31>/Switch25'
    uint8_T SEQ_e;                     // '<S4>/MAIN'
    uint8_T PGN_Enable[255];           // '<S4>/MAIN'
    uint8_T Data_CEM[8];               // '<S4>/MAIN'
    uint8_T SPN2560;                   // '<S4>/MAIN'
    uint8_T SPN2830;                   // '<S4>/MAIN'
    uint8_T ERROR_Type;                // '<S4>/MAIN'
    uint8_T Data_CST[8];               // '<S4>/MAIN'
    uint8_T CTS_Data[8];               // '<S4>/J1939_TP.CM_Recv'
    uint8_T SPN;                       // '<S4>/J1939_TP.CM_Recv'
    boolean_T Delay;                   // '<S5>/Delay'
    B_MAIN_CNT_QC2015P_SECC_T sf_MAIN_CNT_e;// '<S5>/MAIN_CNT'
    B_MAIN_CNT_QC2015P_SECC_T sf_MAIN_CNT;// '<S4>/MAIN_CNT'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_QC2015P_SECC_T {
    real_T Delay2_DSTATE[2];           // '<Root>/Delay2'
    real_T UnitDelay1_DSTATE;          // '<S5>/Unit Delay1'
    real_T UnitDelay16_DSTATE;         // '<S5>/Unit Delay16'
    real_T UnitDelay17_DSTATE;         // '<S5>/Unit Delay17'
    real_T UnitDelay12_DSTATE;         // '<S5>/Unit Delay12'
    real_T UnitDelay13_DSTATE;         // '<S5>/Unit Delay13'
    real_T DiscreteTimeIntegrator_DSTATE;// '<S5>/Discrete-Time Integrator'
    real_T UnitDelay9_DSTATE;          // '<S5>/Unit Delay9'
    real_T UnitDelay8_DSTATE;          // '<S5>/Unit Delay8'
    real_T UnitDelay10_DSTATE;         // '<S5>/Unit Delay10'
    real_T DiscreteTimeIntegrator_DSTATE_i;// '<S4>/Discrete-Time Integrator'
    real_T NextOutput;                 // '<S5>/Random Number'
    real_T NextOutput_a;               // '<S5>/Random Number1'
    real_T cnt;                        // '<S5>/normal1000'
    real_T Ns;                         // '<S5>/VN'
    real_T Tout0;                      // '<S5>/VN'
    real_T NextStep;                   // '<S5>/VN'
    real_T timeOut;                    // '<S5>/QC2015P_MAIN'
    real_T timer;                      // '<S5>/QC2015P_MAIN'
    real_T PauseCNT;                   // '<S5>/QC2015P_MAIN'
    real_T T1;                         // '<S5>/QC2015P_MAIN'
    real_T T2;                         // '<S5>/QC2015P_MAIN'
    real_T STOP_reason;                // '<S5>/QC2015P_MAIN'
    real_T STOP_type;                  // '<S5>/QC2015P_MAIN'
    real_T Temp_PGI03_Enable;          // '<S5>/QC2015P_MAIN'
    real_T cnt_j;                      // '<S95>/sendCyclic5'
    real_T err_cnt;                    // '<S5>/LM_Send'
    real_T LMS_T1;                     // '<S5>/LM_Send'
    real_T local_n;                    // '<S5>/LM_Send'
    real_T LMS_T3;                     // '<S5>/LM_Send'
    real_T LMS_T2;                     // '<S5>/LM_Send'
    real_T local_k;                    // '<S5>/LM_Send'
    real_T send_cnt;                   // '<S5>/LM_Send'
    real_T recv_no;                    // '<S5>/LM_Recv'
    real_T LMS_T2_a;                   // '<S5>/LM_Recv'
    real_T err_cnt_l;                  // '<S5>/LM_Recv'
    real_T LMS_T3_f;                   // '<S5>/LM_Recv'
    real_T lm_tfra;                    // '<S5>/LM_Recv'
    real_T recv_num;                   // '<S5>/LM_Recv'
    real_T totalBytes;                 // '<S5>/AnalysisLM'
    real_T lm_tfra_p;                  // '<S5>/AnalysisLM'
    real_T tmpLists[1785];             // '<S5>/AnalysisLM'
    real_T sliceFlag[255];             // '<S5>/AnalysisLM'
    real_T NextOutput_k;               // '<S4>/Random Number'
    real_T NextOutput_e;               // '<S4>/Random Number1'
    real_T RelinkTimes;                // '<S4>/MAIN'
    real_T BSM_Start;                  // '<S4>/MAIN'
    real_T BSM_timer;                  // '<S4>/MAIN'
    real_T BCL_timer;                  // '<S4>/MAIN'
    real_T BCS_timer;                  // '<S4>/MAIN'
    real_T BRO_OverTime;               // '<S4>/MAIN'
    real_T BSM_OverTime;               // '<S4>/MAIN'
    real_T BCP_OverTime;               // '<S4>/MAIN'
    real_T BSD_OverTime;               // '<S4>/MAIN'
    real_T BCS_OverTime;               // '<S4>/MAIN'
    real_T BCL_OverTime;               // '<S4>/MAIN'
    real_T BST_OverTime;               // '<S4>/MAIN'
    real_T BRM_OverTime;               // '<S4>/MAIN'
    real_T CNT;                        // '<S4>/J1939_TP.CM_Recv'
    uint32_T RandSeed;                 // '<S5>/Random Number'
    uint32_T RandSeed_p;               // '<S5>/Random Number1'
    uint32_T RandSeed_e;               // '<S4>/Random Number'
    uint32_T RandSeed_k;               // '<S4>/Random Number1'
    int_T CANUnpack_ModeSignalID;      // '<S3>/CAN Unpack'
    int_T CANUnpack_StatusPortID;      // '<S3>/CAN Unpack'
    int_T CANUnpack7_ModeSignalID;     // '<S3>/CAN Unpack7'
    int_T CANUnpack7_StatusPortID;     // '<S3>/CAN Unpack7'
    int_T CANUnpack1_ModeSignalID;     // '<S3>/CAN Unpack1'
    int_T CANUnpack1_StatusPortID;     // '<S3>/CAN Unpack1'
    int_T CANUnpack3_ModeSignalID;     // '<S3>/CAN Unpack3'
    int_T CANUnpack3_StatusPortID;     // '<S3>/CAN Unpack3'
    int_T CANUnpack4_ModeSignalID;     // '<S3>/CAN Unpack4'
    int_T CANUnpack4_StatusPortID;     // '<S3>/CAN Unpack4'
    int_T CANUnpack9_ModeSignalID;     // '<S3>/CAN Unpack9'
    int_T CANUnpack9_StatusPortID;     // '<S3>/CAN Unpack9'
    int_T CANUnpack11_ModeSignalID;    // '<S3>/CAN Unpack11'
    int_T CANUnpack11_StatusPortID;    // '<S3>/CAN Unpack11'
    int_T CANUnpack2_ModeSignalID;     // '<S3>/CAN Unpack2'
    int_T CANUnpack2_StatusPortID;     // '<S3>/CAN Unpack2'
    int_T CANUnpack14_ModeSignalID;    // '<S3>/CAN Unpack14'
    int_T CANUnpack14_StatusPortID;    // '<S3>/CAN Unpack14'
    int_T CANUnpack5_ModeSignalID;     // '<S3>/CAN Unpack5'
    int_T CANUnpack5_StatusPortID;     // '<S3>/CAN Unpack5'
    int_T CANUnpack6_ModeSignalID;     // '<S3>/CAN Unpack6'
    int_T CANUnpack6_StatusPortID;     // '<S3>/CAN Unpack6'
    int_T CANUnpack8_ModeSignalID;     // '<S3>/CAN Unpack8'
    int_T CANUnpack8_StatusPortID;     // '<S3>/CAN Unpack8'
    int_T CANUnpack10_ModeSignalID;    // '<S3>/CAN Unpack10'
    int_T CANUnpack10_StatusPortID;    // '<S3>/CAN Unpack10'
    int_T CANUnpack12_ModeSignalID;    // '<S3>/CAN Unpack12'
    int_T CANUnpack12_StatusPortID;    // '<S3>/CAN Unpack12'
    int_T CANFDUnpack_ModeSignalID;    // '<S5>/CAN FD Unpack'
    int_T CANFDUnpack_StatusPortID;    // '<S5>/CAN FD Unpack'
    int_T CANFDPack_ModeSignalID;      // '<S5>/CAN FD Pack'
    int_T CANPack1_ModeSignalID;       // '<S4>/CAN Pack1'
    int_T CANPack19_ModeSignalID;      // '<S4>/CAN Pack19'
    int_T CANPack22_ModeSignalID;      // '<S4>/CAN Pack22'
    int_T CANPack26_ModeSignalID;      // '<S4>/CAN Pack26'
    int_T CANPack27_ModeSignalID;      // '<S4>/CAN Pack27'
    int_T CANPack29_ModeSignalID;      // '<S4>/CAN Pack29'
    int_T CANPack32_ModeSignalID;      // '<S4>/CAN Pack32'
    uint16_T temporalCounter_i1;       // '<S5>/keep1_for10000ms'
    uint16_T temporalCounter_i1_m;     // '<S5>/QC2015P_MAIN'
    uint16_T temporalCounter_i2;       // '<S5>/QC2015P_MAIN'
    uint16_T temporalCounter_i1_a;     // '<S4>/MAIN'
    uint16_T temporalCounter_i2_i;     // '<S4>/MAIN'
    uint16_T temporalCounter_i3;       // '<S4>/J1939_TP.CM_Recv'
    uint16_T temporalCounter_i1_b;     // '<S4>/Chart'
    uint8_T UnitDelay11_DSTATE[255];   // '<S5>/Unit Delay11'
    uint8_T UnitDelay5_DSTATE;         // '<S5>/Unit Delay5'
    uint8_T UnitDelay7_DSTATE;         // '<S5>/Unit Delay7'
    uint8_T UnitDelay3_DSTATE[8];      // '<S5>/Unit Delay3'
    uint8_T UnitDelay2_DSTATE[8];      // '<S5>/Unit Delay2'
    uint8_T UnitDelay_DSTATE[8];       // '<S5>/Unit Delay'
    uint8_T UnitDelay_DSTATE_l[255];   // '<S4>/Unit Delay'
    boolean_T Delay_DSTATE[10];        // '<S5>/Delay'
    boolean_T UnitDelay4_DSTATE;       // '<S5>/Unit Delay4'
    boolean_T UnitDelay6_DSTATE;       // '<S5>/Unit Delay6'
    boolean_T UnitDelay19_DSTATE;      // '<S5>/Unit Delay19'
    int8_T DiscreteTimeIntegrator_PrevRese;// '<S5>/Discrete-Time Integrator'
    int8_T DiscreteTimeIntegrator_PrevRe_b;// '<S4>/Discrete-Time Integrator'
    uint8_T is_active_c18_QC2015P_SECC;// '<S5>/normal1000'
    uint8_T is_c18_QC2015P_SECC;       // '<S5>/normal1000'
    uint8_T is_active_c25_QC2015P_SECC;// '<S5>/keep1_for50ms'
    uint8_T is_c25_QC2015P_SECC;       // '<S5>/keep1_for50ms'
    uint8_T temporalCounter_i1_o;      // '<S5>/keep1_for50ms'
    uint8_T is_active_c19_QC2015P_SECC;// '<S5>/keep1_for10ms'
    uint8_T is_c19_QC2015P_SECC;       // '<S5>/keep1_for10ms'
    uint8_T temporalCounter_i1_l;      // '<S5>/keep1_for10ms'
    uint8_T is_active_c30_QC2015P_SECC;// '<S5>/keep1_for10000ms'
    uint8_T is_c30_QC2015P_SECC;       // '<S5>/keep1_for10000ms'
    uint8_T is_active_c9_QC2015P_SECC; // '<S5>/VN'
    uint8_T is_c9_QC2015P_SECC;        // '<S5>/VN'
    uint8_T temporalCounter_i1_ax;     // '<S5>/VN'
    uint8_T is_active_c26_QC2015P_SECC;// '<S5>/QC2015P_STOP'
    uint8_T is_c26_QC2015P_SECC;       // '<S5>/QC2015P_STOP'
    uint8_T is_active_c10_QC2015P_SECC;// '<S5>/QC2015P_MAIN'
    uint8_T is_c10_QC2015P_SECC;       // '<S5>/QC2015P_MAIN'
    uint8_T is_QC2015P;                // '<S5>/QC2015P_MAIN'
    uint8_T is_End;                    // '<S5>/QC2015P_MAIN'
    uint8_T is_FC_Start;               // '<S5>/QC2015P_MAIN'
    uint8_T is_QC2015P_BeforeEnd;      // '<S5>/QC2015P_MAIN'
    uint8_T is_Authentic;              // '<S5>/QC2015P_MAIN'
    uint8_T is_Authentic_Main;         // '<S5>/QC2015P_MAIN'
    uint8_T is_Send_PGI31;             // '<S5>/QC2015P_MAIN'
    uint8_T is_FC_Start_b;             // '<S5>/QC2015P_MAIN'
    uint8_T is_FN;                     // '<S5>/QC2015P_MAIN'
    uint8_T is_FC_Start_h;             // '<S5>/QC2015P_MAIN'
    uint8_T is_OutLoopDete;            // '<S5>/QC2015P_MAIN'
    uint8_T is_FC_Start_i;             // '<S5>/QC2015P_MAIN'
    uint8_T is_Send_PGI51;             // '<S5>/QC2015P_MAIN'
    uint8_T is_Detecting;              // '<S5>/QC2015P_MAIN'
    uint8_T is_ManualSet;              // '<S5>/QC2015P_MAIN'
    uint8_T is_ParmCfg;                // '<S5>/QC2015P_MAIN'
    uint8_T is_FC_Start_f;             // '<S5>/QC2015P_MAIN'
    uint8_T is_PreChgEnTrans;          // '<S5>/QC2015P_MAIN'
    uint8_T is_EnTrans;                // '<S5>/QC2015P_MAIN'
    uint8_T is_PreChg;                 // '<S5>/QC2015P_MAIN'
    uint8_T is_S2;                     // '<S5>/QC2015P_MAIN'
    uint8_T is_ReLink_Reboot;          // '<S5>/QC2015P_MAIN'
    uint8_T is_Rebooting;              // '<S5>/QC2015P_MAIN'
    uint8_T is_active_c28_QC2015P_SECC;// '<S95>/sendCyclic5'
    uint8_T is_c28_QC2015P_SECC;       // '<S95>/sendCyclic5'
    uint8_T is_active_c15_QC2015P_SECC;// '<S5>/LM_Send'
    uint8_T is_c15_QC2015P_SECC;       // '<S5>/LM_Send'
    uint8_T is_S1_S4;                  // '<S5>/LM_Send'
    uint8_T temporalCounter_i1_c;      // '<S5>/LM_Send'
    uint8_T is_active_c11_QC2015P_SECC;// '<S5>/LM_Recv'
    uint8_T is_c11_QC2015P_SECC;       // '<S5>/LM_Recv'
    uint8_T is_S1;                     // '<S5>/LM_Recv'
    uint8_T temporalCounter_i1_g;      // '<S5>/LM_Recv'
    uint8_T is_active_c29_QC2015P_SECC;// '<S4>/MAIN'
    uint8_T is_c29_QC2015P_SECC;       // '<S4>/MAIN'
    uint8_T is_Chage_Step;             // '<S4>/MAIN'
    uint8_T is_Send_CCS;               // '<S4>/MAIN'
    uint8_T is_Send_CML;               // '<S4>/MAIN'
    uint8_T is_Send_CRM;               // '<S4>/MAIN'
    uint8_T is_Send_CRO;               // '<S4>/MAIN'
    uint8_T is_Send_CSD;               // '<S4>/MAIN'
    uint8_T is_Send_CST;               // '<S4>/MAIN'
    uint8_T ByteNum;                   // '<S4>/J1939_TP.CM_Recv'
    uint8_T MsgNum;                    // '<S4>/J1939_TP.CM_Recv'
    uint8_T Temp_SPN;                  // '<S4>/J1939_TP.CM_Recv'
    uint8_T is_active_c31_QC2015P_SECC;// '<S4>/J1939_TP.CM_Recv'
    uint8_T is_c31_QC2015P_SECC;       // '<S4>/J1939_TP.CM_Recv'
    uint8_T is_RECV;                   // '<S4>/J1939_TP.CM_Recv'
    uint8_T is_Reply_RTS;              // '<S4>/J1939_TP.CM_Recv'
    uint8_T is_Reply_TP;               // '<S4>/J1939_TP.CM_Recv'
    uint8_T temporalCounter_i1_p;      // '<S4>/J1939_TP.CM_Recv'
    uint8_T temporalCounter_i2_k;      // '<S4>/J1939_TP.CM_Recv'
    uint8_T is_active_c51_QC2015P_SECC;// '<S4>/Chart'
    uint8_T is_c51_QC2015P_SECC;       // '<S4>/Chart'
    DW_normal250__QC2015P_SECC_T sf_normal250_3_a;// '<S5>/normal250_3'
    DW_normal250__QC2015P_SECC_T sf_normal250_2_e;// '<S5>/normal250_2'
    DW_normal250__QC2015P_SECC_T sf_normal250_1_e;// '<S5>/normal250_1'
    DW_normal250__QC2015P_SECC_T sf_normal250_;// '<S5>/normal250_'
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3_1;// '<S5>/normal1000_50for3_1' 
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3_;// '<S5>/normal1000_50for3_' 
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3;// '<S5>/normal1000_50for3' 
    DW_keep1_for10ms_QC2015P_SECC_T sf_keep1_for10ms1;// '<S5>/keep1_for10ms1'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic4_f;// '<S95>/sendCyclic4'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic3_d;// '<S95>/sendCyclic3'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic2_n;// '<S95>/sendCyclic2'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic1_m;// '<S95>/sendCyclic1'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic_e;// '<S95>/sendCyclic'
    DW_MAIN_CNT_QC2015P_SECC_T sf_MAIN_CNT_e;// '<S5>/MAIN_CNT'
    DW_normal250_QC2015P_SECC_T sf_normal250_5;// '<S4>/normal250_5'
    DW_normal250_QC2015P_SECC_T sf_normal250_4;// '<S4>/normal250_4'
    DW_normal250_QC2015P_SECC_T sf_normal250_3;// '<S4>/normal250_3'
    DW_normal250_QC2015P_SECC_T sf_normal250_2;// '<S4>/normal250_2'
    DW_normal250_QC2015P_SECC_T sf_normal250_1;// '<S4>/normal250_1'
    DW_normal250_QC2015P_SECC_T sf_normal250;// '<S4>/normal250'
    DW_keep1_for10ms_QC2015P_SECC_T sf_keep1_for10ms;// '<S4>/keep1_for10ms'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic8;// '<S31>/sendCyclic8'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic7;// '<S31>/sendCyclic7'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic6;// '<S31>/sendCyclic6'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic5;// '<S31>/sendCyclic5'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic4;// '<S31>/sendCyclic4'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic3;// '<S31>/sendCyclic3'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic2;// '<S31>/sendCyclic2'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic1;// '<S31>/sendCyclic1'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic;// '<S31>/sendCyclic'
    DW_MAIN_CNT_QC2015P_SECC_T sf_MAIN_CNT;// '<S4>/MAIN_CNT'
  };

  // Invariant block signals (default storage)
  struct ConstB_QC2015P_SECC_T {
    real_T DataTypeConversion;         // '<S4>/Data Type Conversion'
  };

  // Constant parameters (default storage)
  struct ConstP_QC2015P_SECC_T {
    // Expression: [2, 255, 255, 255, 255, 255, 255, 255]
    //  Referenced by: '<S5>/LM_NACK'

    real_T LM_NACK_Value[8];

    // Expression: [0,1,4,0xFF,0xFF,0xFF,0xFF,0xFF]
    //  Referenced by: '<S5>/Constant37'

    uint8_T Constant37_Value[8];

    // Expression: [3,1,3,2,0xFF,0xFF,0xFF,0xFF]
    //  Referenced by: '<S5>/Constant56'

    uint8_T Constant56_Value[8];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_QC2015P_SECC_T {
    CAN_MSG_Array MsgInput;            // '<Root>/MsgInput'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_QC2015P_SECC_T {
    CAN_MESSAGE_BUS Msg_Send[15];      // '<Root>/Msg_Send'
    UserMonitor_SECC UserMonitor_SECC_n;// '<Root>/UserMonitor_SECC'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_QC2015P_SECC_T {
    const char_T * volatile errorStatus;

    //
    //  Timing:
    //  The following substructure contains information regarding
    //  the timing information for the model.

    struct {
      struct {
        uint8_T TID[2];
      } TaskCounters;
    } Timing;
  };

  // Copy Constructor
  QC2015P_SECC(QC2015P_SECC const&) = delete;

  // Assignment Operator
  QC2015P_SECC& operator= (QC2015P_SECC const&) & = delete;

  // Move Constructor
  QC2015P_SECC(QC2015P_SECC &&) = delete;

  // Move Assignment Operator
  QC2015P_SECC& operator= (QC2015P_SECC &&) = delete;

  // Real-Time Model get method
  QC2015P_SECC::RT_MODEL_QC2015P_SECC_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_QC2015P_SECC_T *pExtU_QC2015P_SECC_T)
  {
    QC2015P_SECC_U = *pExtU_QC2015P_SECC_T;
  }

  // Root outports get method
  const ExtY_QC2015P_SECC_T &getExternalOutputs() const
  {
    return QC2015P_SECC_Y;
  }

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  QC2015P_SECC();

  // Destructor
  ~QC2015P_SECC();

  // private data and function members
 private:
  // External inputs
  ExtU_QC2015P_SECC_T QC2015P_SECC_U;

  // External outputs
  ExtY_QC2015P_SECC_T QC2015P_SECC_Y;

  // Block signals
  B_QC2015P_SECC_T QC2015P_SECC_B;

  // Block states
  DW_QC2015P_SECC_T QC2015P_SECC_DW;

  // private member function(s) for subsystem '<S4>/MAIN_CNT'
  void QC2015P_SECC_MAIN_CNT(boolean_T rtu_startFlg, B_MAIN_CNT_QC2015P_SECC_T
    *localB, DW_MAIN_CNT_QC2015P_SECC_T *localDW);
  void QC2015P_SECC_enter_atomic_init(B_MAIN_CNT_QC2015P_SECC_T *localB,
    DW_MAIN_CNT_QC2015P_SECC_T *localDW);
  real_T QC2015P_SECC_mod(real_T x);
  real_T QC2015P_SECC_mod_i(real_T x);

  // private member function(s) for subsystem '<S31>/sendCyclic'
  static void QC2015P_SECC_sendCyclic_Init(real_T *rty_enable);
  static void QC2015P_SECC_sendCyclic(boolean_T rtu_startFlg, real_T
    rtu_cycleTime, real_T *rty_enable, DW_sendCyclic_QC2015P_SECC_T *localDW);

  // private member function(s) for subsystem '<S4>/keep1_for10ms'
  static void QC2015P_SECC_keep1_for10ms_Init(real_T *rty_out);
  static void QC2015P_SECC_keep1_for10ms(boolean_T rtu_startFlg, real_T *rty_out,
    DW_keep1_for10ms_QC2015P_SECC_T *localDW);

  // private member function(s) for subsystem '<S4>/normal250'
  static void QC2015P_SECC_normal250_Init(real_T *rty_enable);
  static void QC2015P_SECC_normal250(boolean_T rtu_rawCycle, real_T *rty_enable,
    DW_normal250_QC2015P_SECC_T *localDW);

  // private member function(s) for subsystem '<S5>/Bit Shift10'
  static void QC2015P_SECC_BitShift10(uint16_T rtu_u, uint16_T *rty_y);

  // private member function(s) for subsystem '<S5>/normal1000_50for3'
  static void QC2015P__normal1000_50for3_Init(real_T *rty_enable);
  static void QC2015P_SECC_normal1000_50for3(boolean_T rtu_rawCycle, boolean_T
    rtu_startFlg, real_T *rty_enable, DW_normal1000_50for3_QC2015P__T *localDW);

  // private member function(s) for subsystem '<S5>/normal250_'
  static void QC2015P_SECC_normal250__Init(real_T *rty_enable);
  static void QC2015P_SECC_normal250_(boolean_T rtu_rawCycle, real_T *rty_enable,
    DW_normal250__QC2015P_SECC_T *localDW);

  // private member function(s) for subsystem '<Root>'
  void QC2015P_SECC_exit_internal_End(void);
  void QC2015P_SECC_End(void);
  void QC2015P_SECC_Authentic(void);
  void QC2015P_SECC_OutLoopDete(void);
  void QC2015P_SECC_ParmCfg(void);
  void QC2015P_SECC_EnTrans(void);
  void exit_internal_QC2015P_BeforeEnd(void);
  void QC2015P_SECC_QC2015P_BeforeEnd(const boolean_T *LogicalOperator38, const
    real_T *Switch53, const uint8_T Transpose1[8]);
  void QC2015P_S_exit_internal_QC2015P(void);
  void QC2015P_SE_enter_atomic_init_gp(void);
  void QC2015P_SECC_QC2015P(const boolean_T *LogicalOperator38, const real_T
    *Switch53, const real_T *out, const uint8_T Transpose1[8]);
  void QC2015P_SE_enter_atomic_init_S0(void);
  void enter_atomic_S0_init_or_S2_fini(void);
  void QC2015P_SECC_S1(const real_T DataTypeConversion6[8], const real_T
                       *DataTypeConversion40, const boolean_T *LogicalOperator4);
  void QC2015_enter_internal_Reply_RTS(void);
  void QC2015P_SECC_Send_CRO(void);
  void QC2015_exit_internal_Chage_Step(void);
  void QC2015P_S_enter_atomic_Send_CEM(void);
  void QC2015P_SECC_Chage_Step(const boolean_T *Compare, const boolean_T
    *Compare_h, const boolean_T *Compare_n);
  void QC2015P_SECC_Send_CEM(void);
  void QC2015P_SEC_enter_atomic_init_g(void);

  // Real-Time Model
  RT_MODEL_QC2015P_SECC_T QC2015P_SECC_M;
};

extern const QC2015P_SECC::ConstB_QC2015P_SECC_T QC2015P_SECC_ConstB;// constant block i/o 

// Constant parameters (default storage)
extern const QC2015P_SECC::ConstP_QC2015P_SECC_T QC2015P_SECC_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S4>/CAN FD PacK1' : Unused code path elimination
//  Block '<S4>/CAN FD PacK2' : Unused code path elimination
//  Block '<S4>/CAN FD PacK5' : Unused code path elimination
//  Block '<S4>/CAN FD Unpack' : Unused code path elimination
//  Block '<S4>/CAN FD Unpack1' : Unused code path elimination
//  Block '<S4>/CAN FD Unpack2' : Unused code path elimination
//  Block '<S4>/CAN Pack30' : Unused code path elimination
//  Block '<S24>/Compare' : Unused code path elimination
//  Block '<S24>/Constant' : Unused code path elimination
//  Block '<S26>/Compare' : Unused code path elimination
//  Block '<S26>/Constant' : Unused code path elimination
//  Block '<S27>/Compare' : Unused code path elimination
//  Block '<S27>/Constant' : Unused code path elimination
//  Block '<S4>/Data Type Conversion13' : Unused code path elimination
//  Block '<S4>/Data Type Conversion4' : Unused code path elimination
//  Block '<S4>/Data Type Conversion5' : Unused code path elimination
//  Block '<S4>/Data Type Conversion6' : Unused code path elimination
//  Block '<S4>/Logical Operator10' : Unused code path elimination
//  Block '<S4>/Logical Operator11' : Unused code path elimination
//  Block '<S4>/Logical Operator12' : Unused code path elimination
//  Block '<S4>/SPN2830_CRO_ChargerReadyOrNot_SW' : Unused code path elimination
//  Block '<S4>/SPN2830_CRO_ChargerReadyOrNot_Va' : Unused code path elimination
//  Block '<S4>/Sw51' : Unused code path elimination
//  Block '<S4>/Switch1' : Unused code path elimination
//  Block '<S4>/Switch2' : Unused code path elimination
//  Block '<S4>/Switch44' : Unused code path elimination
//  Block '<S5>/Constant59' : Unused code path elimination
//  Block '<S5>/Min of Elements3' : Unused code path elimination
//  Block '<S5>/Switch55' : Unused code path elimination
//  Block '<S5>/Unit Delay14' : Unused code path elimination
//  Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S4>/Data Type Conversion9' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'QC2015P_SECC'
//  '<S1>'   : 'QC2015P_SECC/Compare To Constant10'
//  '<S2>'   : 'QC2015P_SECC/Compare To Constant2'
//  '<S3>'   : 'QC2015P_SECC/Msg_Recv'
//  '<S4>'   : 'QC2015P_SECC/QC2015'
//  '<S5>'   : 'QC2015P_SECC/QC2015P'
//  '<S6>'   : 'QC2015P_SECC/Msg_Recv/MsgSelect'
//  '<S7>'   : 'QC2015P_SECC/Msg_Recv/MsgSelect1'
//  '<S8>'   : 'QC2015P_SECC/Msg_Recv/MsgSelect10'
//  '<S9>'   : 'QC2015P_SECC/Msg_Recv/MsgSelect11'
//  '<S10>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect12'
//  '<S11>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect13'
//  '<S12>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect2'
//  '<S13>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect3'
//  '<S14>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect4'
//  '<S15>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect5'
//  '<S16>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect6'
//  '<S17>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect7'
//  '<S18>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect8'
//  '<S19>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect9'
//  '<S20>'  : 'QC2015P_SECC/QC2015/AnalysisLM'
//  '<S21>'  : 'QC2015P_SECC/QC2015/Chart'
//  '<S22>'  : 'QC2015P_SECC/QC2015/Compare To Constant'
//  '<S23>'  : 'QC2015P_SECC/QC2015/Compare To Constant1'
//  '<S24>'  : 'QC2015P_SECC/QC2015/Compare To Constant19'
//  '<S25>'  : 'QC2015P_SECC/QC2015/Compare To Constant2'
//  '<S26>'  : 'QC2015P_SECC/QC2015/Compare To Constant5'
//  '<S27>'  : 'QC2015P_SECC/QC2015/Compare To Constant6'
//  '<S28>'  : 'QC2015P_SECC/QC2015/J1939_TP.CM_Recv'
//  '<S29>'  : 'QC2015P_SECC/QC2015/MAIN'
//  '<S30>'  : 'QC2015P_SECC/QC2015/MAIN_CNT'
//  '<S31>'  : 'QC2015P_SECC/QC2015/MsgSend'
//  '<S32>'  : 'QC2015P_SECC/QC2015/keep1_for10ms'
//  '<S33>'  : 'QC2015P_SECC/QC2015/normal250'
//  '<S34>'  : 'QC2015P_SECC/QC2015/normal250_1'
//  '<S35>'  : 'QC2015P_SECC/QC2015/normal250_2'
//  '<S36>'  : 'QC2015P_SECC/QC2015/normal250_3'
//  '<S37>'  : 'QC2015P_SECC/QC2015/normal250_4'
//  '<S38>'  : 'QC2015P_SECC/QC2015/normal250_5'
//  '<S39>'  : 'QC2015P_SECC/QC2015/MsgSend/sendCyclic'
//  '<S40>'  : 'QC2015P_SECC/QC2015/MsgSend/sendCyclic1'
//  '<S41>'  : 'QC2015P_SECC/QC2015/MsgSend/sendCyclic2'
//  '<S42>'  : 'QC2015P_SECC/QC2015/MsgSend/sendCyclic3'
//  '<S43>'  : 'QC2015P_SECC/QC2015/MsgSend/sendCyclic4'
//  '<S44>'  : 'QC2015P_SECC/QC2015/MsgSend/sendCyclic5'
//  '<S45>'  : 'QC2015P_SECC/QC2015/MsgSend/sendCyclic6'
//  '<S46>'  : 'QC2015P_SECC/QC2015/MsgSend/sendCyclic7'
//  '<S47>'  : 'QC2015P_SECC/QC2015/MsgSend/sendCyclic8'
//  '<S48>'  : 'QC2015P_SECC/QC2015P/AnalysisLM'
//  '<S49>'  : 'QC2015P_SECC/QC2015P/Bit Shift'
//  '<S50>'  : 'QC2015P_SECC/QC2015P/Bit Shift1'
//  '<S51>'  : 'QC2015P_SECC/QC2015P/Bit Shift10'
//  '<S52>'  : 'QC2015P_SECC/QC2015P/Bit Shift2'
//  '<S53>'  : 'QC2015P_SECC/QC2015P/Bit Shift3'
//  '<S54>'  : 'QC2015P_SECC/QC2015P/Bit Shift4'
//  '<S55>'  : 'QC2015P_SECC/QC2015P/Bit Shift5'
//  '<S56>'  : 'QC2015P_SECC/QC2015P/Bit Shift6'
//  '<S57>'  : 'QC2015P_SECC/QC2015P/Bit Shift7'
//  '<S58>'  : 'QC2015P_SECC/QC2015P/Bit Shift8'
//  '<S59>'  : 'QC2015P_SECC/QC2015P/Compare To Constant'
//  '<S60>'  : 'QC2015P_SECC/QC2015P/Compare To Constant1'
//  '<S61>'  : 'QC2015P_SECC/QC2015P/Compare To Constant10'
//  '<S62>'  : 'QC2015P_SECC/QC2015P/Compare To Constant11'
//  '<S63>'  : 'QC2015P_SECC/QC2015P/Compare To Constant12'
//  '<S64>'  : 'QC2015P_SECC/QC2015P/Compare To Constant13'
//  '<S65>'  : 'QC2015P_SECC/QC2015P/Compare To Constant14'
//  '<S66>'  : 'QC2015P_SECC/QC2015P/Compare To Constant15'
//  '<S67>'  : 'QC2015P_SECC/QC2015P/Compare To Constant16'
//  '<S68>'  : 'QC2015P_SECC/QC2015P/Compare To Constant17'
//  '<S69>'  : 'QC2015P_SECC/QC2015P/Compare To Constant18'
//  '<S70>'  : 'QC2015P_SECC/QC2015P/Compare To Constant19'
//  '<S71>'  : 'QC2015P_SECC/QC2015P/Compare To Constant2'
//  '<S72>'  : 'QC2015P_SECC/QC2015P/Compare To Constant20'
//  '<S73>'  : 'QC2015P_SECC/QC2015P/Compare To Constant21'
//  '<S74>'  : 'QC2015P_SECC/QC2015P/Compare To Constant22'
//  '<S75>'  : 'QC2015P_SECC/QC2015P/Compare To Constant23'
//  '<S76>'  : 'QC2015P_SECC/QC2015P/Compare To Constant24'
//  '<S77>'  : 'QC2015P_SECC/QC2015P/Compare To Constant27'
//  '<S78>'  : 'QC2015P_SECC/QC2015P/Compare To Constant28'
//  '<S79>'  : 'QC2015P_SECC/QC2015P/Compare To Constant29'
//  '<S80>'  : 'QC2015P_SECC/QC2015P/Compare To Constant3'
//  '<S81>'  : 'QC2015P_SECC/QC2015P/Compare To Constant30'
//  '<S82>'  : 'QC2015P_SECC/QC2015P/Compare To Constant36'
//  '<S83>'  : 'QC2015P_SECC/QC2015P/Compare To Constant37'
//  '<S84>'  : 'QC2015P_SECC/QC2015P/Compare To Constant4'
//  '<S85>'  : 'QC2015P_SECC/QC2015P/Compare To Constant41'
//  '<S86>'  : 'QC2015P_SECC/QC2015P/Compare To Constant5'
//  '<S87>'  : 'QC2015P_SECC/QC2015P/Compare To Constant6'
//  '<S88>'  : 'QC2015P_SECC/QC2015P/Compare To Constant7'
//  '<S89>'  : 'QC2015P_SECC/QC2015P/Compare To Constant8'
//  '<S90>'  : 'QC2015P_SECC/QC2015P/Compare To Constant9'
//  '<S91>'  : 'QC2015P_SECC/QC2015P/LM_Recv'
//  '<S92>'  : 'QC2015P_SECC/QC2015P/LM_Send'
//  '<S93>'  : 'QC2015P_SECC/QC2015P/MAIN_CNT'
//  '<S94>'  : 'QC2015P_SECC/QC2015P/MATLAB Function1'
//  '<S95>'  : 'QC2015P_SECC/QC2015P/MsgSend'
//  '<S96>'  : 'QC2015P_SECC/QC2015P/PACK_LM'
//  '<S97>'  : 'QC2015P_SECC/QC2015P/Pack_LM_ACK'
//  '<S98>'  : 'QC2015P_SECC/QC2015P/QC2015P_MAIN'
//  '<S99>'  : 'QC2015P_SECC/QC2015P/QC2015P_STOP'
//  '<S100>' : 'QC2015P_SECC/QC2015P/VN'
//  '<S101>' : 'QC2015P_SECC/QC2015P/get_lm_tfra'
//  '<S102>' : 'QC2015P_SECC/QC2015P/keep1_for10000ms'
//  '<S103>' : 'QC2015P_SECC/QC2015P/keep1_for10ms'
//  '<S104>' : 'QC2015P_SECC/QC2015P/keep1_for10ms1'
//  '<S105>' : 'QC2015P_SECC/QC2015P/keep1_for50ms'
//  '<S106>' : 'QC2015P_SECC/QC2015P/normal1000'
//  '<S107>' : 'QC2015P_SECC/QC2015P/normal1000_50for3'
//  '<S108>' : 'QC2015P_SECC/QC2015P/normal1000_50for3_'
//  '<S109>' : 'QC2015P_SECC/QC2015P/normal1000_50for3_1'
//  '<S110>' : 'QC2015P_SECC/QC2015P/normal250_'
//  '<S111>' : 'QC2015P_SECC/QC2015P/normal250_1'
//  '<S112>' : 'QC2015P_SECC/QC2015P/normal250_2'
//  '<S113>' : 'QC2015P_SECC/QC2015P/normal250_3'
//  '<S114>' : 'QC2015P_SECC/QC2015P/Bit Shift/bit_shift'
//  '<S115>' : 'QC2015P_SECC/QC2015P/Bit Shift1/bit_shift'
//  '<S116>' : 'QC2015P_SECC/QC2015P/Bit Shift10/bit_shift'
//  '<S117>' : 'QC2015P_SECC/QC2015P/Bit Shift2/bit_shift'
//  '<S118>' : 'QC2015P_SECC/QC2015P/Bit Shift3/bit_shift'
//  '<S119>' : 'QC2015P_SECC/QC2015P/Bit Shift4/bit_shift'
//  '<S120>' : 'QC2015P_SECC/QC2015P/Bit Shift5/bit_shift'
//  '<S121>' : 'QC2015P_SECC/QC2015P/Bit Shift6/bit_shift'
//  '<S122>' : 'QC2015P_SECC/QC2015P/Bit Shift7/bit_shift'
//  '<S123>' : 'QC2015P_SECC/QC2015P/Bit Shift8/bit_shift'
//  '<S124>' : 'QC2015P_SECC/QC2015P/MsgSend/sendCyclic'
//  '<S125>' : 'QC2015P_SECC/QC2015P/MsgSend/sendCyclic1'
//  '<S126>' : 'QC2015P_SECC/QC2015P/MsgSend/sendCyclic2'
//  '<S127>' : 'QC2015P_SECC/QC2015P/MsgSend/sendCyclic3'
//  '<S128>' : 'QC2015P_SECC/QC2015P/MsgSend/sendCyclic4'
//  '<S129>' : 'QC2015P_SECC/QC2015P/MsgSend/sendCyclic5'

#endif                                 // RTW_HEADER_QC2015P_SECC_h_

//
// File trailer for generated code.
//
// [EOF]
//
