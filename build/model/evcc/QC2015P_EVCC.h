//
// File: QC2015P_EVCC.h
//
// Code generated for Simulink model 'QC2015P_EVCC'.
//
// Model version                  : 1.547
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sun Sep 27 17:49:46 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_QC2015P_EVCC_h_
#define RTW_HEADER_QC2015P_EVCC_h_
#include <math.h>
#include "rtwtypes.h"
#include "can_fd_message.h"
#include "QC2015P_EVCC_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <cstring>

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rtGetInf.h"

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
  real_T BCL_Cycle_Va;                 // Referenced by: '<S37>/BCL_Cycle_Va'
  real_T BEM_Cycle_Va;                 // Referenced by: '<S37>/BEM_Cycle_Va'
  real_T BHM_Cycle_Va;                 // Referenced by: '<S37>/BHM_Cycle_Va'
  real_T BMS_Vlotage;                  // Referenced by:
                                          //  '<S5>/BMS_Vlotage1'
                                          //  '<S6>/BMS_Vlotage'
                                          //  '<S6>/BMS_Vlotage1'

  real_T BRO_Cycle_Va;                 // Referenced by: '<S37>/BRO_Cycle_Va'
  real_T BSD_Cycle_Va;                 // Referenced by: '<S37>/BSD_Cycle_Va'
  real_T BSM_Cycle_Va;                 // Referenced by: '<S37>/BSM_Cycle_Va'
  real_T BST_Cycle_Va;                 // Referenced by: '<S37>/BST_Cycle_Va'
  real_T CONTROL_EVCC_Cycle_Va;// Referenced by: '<S108>/CONTROL_EVCC_Cycle_Va'
  real_T Charge_Current;               // Referenced by:
                                          //  '<S5>/Charge_Current'
                                          //  '<S6>/Charge_Current'

  real_T LM_EVCC_Cycle_Va;          // Referenced by: '<S108>/LM_EVCC_Cycle_Va'
  real_T PGI22_Capacity;               // Referenced by: '<S6>/PGI22_Capacity'
  real_T PGI22_Current;                // Referenced by: '<S6>/PGI22_Current'
  real_T PGI22_SOC;                    // Referenced by: '<S6>/PGI22_SOC'
  real_T PGI22_Voltage;                // Referenced by: '<S6>/PGI22_Voltage'
  real_T PGI22_Voltage2;               // Referenced by: '<S6>/PGI22_Voltage2'
  real_T PGI72_EVCC_V_Exe_Va;      // Referenced by: '<S6>/PGI72_EVCC_V_Exe_Va'
  real_T PGI73_A_Va;                   // Referenced by: '<S6>/PGI73_A_Va'
  real_T PGI73_V_Va;                   // Referenced by: '<S6>/PGI73_V_Va'
  real_T PGI74_SOC_Va;                 // Referenced by: '<S6>/PGI74_SOC_Va'
  real_T PGI74_TimeRemain_Va;      // Referenced by: '<S6>/PGI74_TimeRemain_Va'
  real_T PGI77_SingleBattV_Max;  // Referenced by: '<S6>/PGI77_SingleBattV_Max'
  real_T PGI77_SingleBattV_Min;  // Referenced by: '<S6>/PGI77_SingleBattV_Min'
  real_T PGI94_SOC_Va;                 // Referenced by: '<S6>/PGI94_SOC_Va'
  real_T SM_RM_EVCC_Cycle_Va;    // Referenced by: '<S108>/SM_RM_EVCC_Cycle_Va'
  real_T SM_URM_EVCC_Cycle_Va;  // Referenced by: '<S108>/SM_URM_EVCC_Cycle_Va'
  real_T SOC_Set;                      // Referenced by:
                                          //  '<S5>/SOC_Set'
                                          //  '<S6>/SOC_Set'

  real_T SPN2565_BRM_ProtocolVer_Va;
                            // Referenced by: '<S5>/SPN2565_BRM_ProtocolVer_Va'
  real_T SPN2566_BRM_BatteryType_Va;
                            // Referenced by: '<S5>/SPN2566_BRM_BatteryType_Va'
  real_T SPN2567_BRM_BatteryCapacity_Va;
                        // Referenced by: '<S5>/SPN2567_BRM_BatteryCapacity_Va'
  real_T SPN2568_BRM_BatteryVoltage_Va;
                         // Referenced by: '<S5>/SPN2568_BRM_BatteryVoltage_Va'
  real_T SPN2569_BRM_BatteryProducer_Va;
                        // Referenced by: '<S5>/SPN2569_BRM_BatteryProducer_Va'
  real_T SPN2570_BRM_BatterySN_Va;
                              // Referenced by: '<S5>/SPN2570_BRM_BatterySN_Va'
  real_T SPN2571_BRM_ManufactureDate_Va;
                        // Referenced by: '<S5>/SPN2571_BRM_ManufactureDate_Va'
  real_T SPN2571_BRM_ManufactureMonth_Va;
                       // Referenced by: '<S5>/SPN2571_BRM_ManufactureMonth_Va'
  real_T SPN2571_BRM_ManufactureYear_Va;
                        // Referenced by: '<S5>/SPN2571_BRM_ManufactureYear_Va'
  real_T SPN2572_BRM_BatteryChargedTimes_Va;
                    // Referenced by: '<S5>/SPN2572_BRM_BatteryChargedTimes_Va'
  real_T SPN2573_BRM_Ownership_Va;
                              // Referenced by: '<S5>/SPN2573_BRM_Ownership_Va'
  real_T SPN2574_BRM_BRMReserved_Va;
                            // Referenced by: '<S5>/SPN2574_BRM_BRMReserved_Va'
  real_T SPN2575_BRM_VINPart1_Va;
                               // Referenced by: '<S5>/SPN2575_BRM_VINPart1_Va'
  real_T SPN2575_BRM_VINPart2_Va;
                               // Referenced by: '<S5>/SPN2575_BRM_VINPart2_Va'
  real_T SPN2575_BRM_VINPart3_Va;
                               // Referenced by: '<S5>/SPN2575_BRM_VINPart3_Va'
  real_T SPN2575_BRM_VINPart4_Va;
                              // Referenced by: '<S5>/SPN2575_BRM_VINPart2_Va1'
  real_T SPN2575_BRM_VINPart5_Va;
                              // Referenced by: '<S5>/SPN2575_BRM_VINPart3_Va1'
  real_T SPN2576_BRM_BMSSoftVer_Reserved_Va;
                    // Referenced by: '<S5>/SPN2576_BRM_BMSSoftVer_Reserved_Va'
  real_T SPN2576_BRM_BMSSoftwareVer_Date_Va;
                    // Referenced by: '<S5>/SPN2576_BRM_BMSSoftwareVer_Date_Va'
  real_T SPN2576_BRM_BMSSoftwareVer_Num_Va;
                     // Referenced by: '<S5>/SPN2576_BRM_BMSSoftwareVer_Num_Va'
  real_T SPN2601_BHM_ChargeTotalVolt_MAX_Va;
                    // Referenced by: '<S5>/SPN2601_BHM_ChargeTotalVolt_MAX_Va'
  real_T SPN2816_BCP_CellChargeVolt_MAX_Va;
                     // Referenced by: '<S5>/SPN2816_BCP_CellChargeVolt_MAX_Va'
  real_T SPN2817_BCP_ChargeCurrent_MAX_Va;
                      // Referenced by: '<S5>/SPN2817_BCP_ChargeCurrent_MAX_Va'
  real_T SPN2818_BCP_NominalCapacity_Va;
                        // Referenced by: '<S5>/SPN2818_BCP_NominalCapacity_Va'
  real_T SPN2819_BCP_ChargeTotalVolt_MAX_Va;
                    // Referenced by: '<S5>/SPN2819_BCP_ChargeTotalVolt_MAX_Va'
  real_T SPN2820_BCP_Temperature_MAX_Va;
                        // Referenced by: '<S5>/SPN2820_BCP_Temperature_MAX_Va'
  real_T SPN2821_BCP_SOC_Va;        // Referenced by: '<S5>/SPN2821_BCP_SOC_Va'
  real_T SPN2822_BCP_BatteryTotalVoltage_Va;
                    // Referenced by: '<S5>/SPN2822_BCP_BatteryTotalVoltage_Va'
  real_T SPN2829_BRO_BMSReadyOrNot_Va;
                          // Referenced by: '<S5>/SPN2829_BRO_BMSReadyOrNot_Va'
  real_T SPN3072_BCL_VoltageRequirement_Va;
                     // Referenced by: '<S5>/SPN3072_BCL_VoltageRequirement_Va'
  real_T SPN3073_BCL_CurrentRequirement_Va;
                     // Referenced by: '<S5>/SPN3073_BCL_CurrentRequirement_Va'
  real_T SPN3074_BCL_ChargingModel_Va;
                          // Referenced by: '<S5>/SPN3074_BCL_ChargingModel_Va'
  real_T SPN3075_BCS_ChargEVoltMeasure_Va;
                      // Referenced by: '<S5>/SPN3075_BCS_ChargEVoltMeasure_Va'
  real_T SPN3076_BCS_ChargeCurrentMeasure_Va;
                   // Referenced by: '<S5>/SPN3076_BCS_ChargeCurrentMeasure_Va'
  real_T SPN3077_BCS_Max_CellVoltage_Num_Va;
                    // Referenced by: '<S5>/SPN3077_BCS_Max_CellVoltage_Num_Va'
  real_T SPN3077_BCS_Max_CellVoltage_Va;
                        // Referenced by: '<S5>/SPN3077_BCS_Max_CellVoltage_Va'
  real_T SPN3078_BCS_SOC_Va;        // Referenced by: '<S5>/SPN3078_BCS_SOC_Va'
  real_T SPN3079_BCS_ChargeTimeRest_Va;
                         // Referenced by: '<S5>/SPN3079_BCS_ChargeTimeRest_Va'
  real_T SPN3085_BSM_NumberHighestVB_Va;
                        // Referenced by: '<S5>/SPN3085_BSM_NumberHighestVB_Va'
  real_T SPN3086_BSM_BatteryHighsestTemp_Va;
                    // Referenced by: '<S5>/SPN3086_BSM_BatteryHighsestTemp_Va'
  real_T SPN3087_BSM_NumHTemTestingPoint_Va;
                    // Referenced by: '<S5>/SPN3087_BSM_NumHTemTestingPoint_Va'
  real_T SPN3088_BSM_BatteryLowestTemp_Va;
                      // Referenced by: '<S5>/SPN3088_BSM_BatteryLowestTemp_Va'
  real_T SPN3089_BSM_NumLTemTestingPoint_Va;
                    // Referenced by: '<S5>/SPN3089_BSM_NumLTemTestingPoint_Va'
  real_T SPN3090_BSM_CellVoltageState_Va;
                       // Referenced by: '<S5>/SPN3090_BSM_CellVoltageState_Va'
  real_T SPN3091_BSM_VehicleBatterySOC_Va;
                      // Referenced by: '<S5>/SPN3091_BSM_VehicleBatterySOC_Va'
  real_T SPN3092_BSM_ChargingOverCurrent_Va;
                    // Referenced by: '<S5>/SPN3092_BSM_ChargingOverCurrent_Va'
  real_T SPN3093_BSM_BatteryTemState_Va;
                        // Referenced by: '<S5>/SPN3093_BSM_BatteryTemState_Va'
  real_T SPN3094_BSM_BatInsulationState_Va;
                     // Referenced by: '<S5>/SPN3094_BSM_BatInsulationState_Va'
  real_T SPN3095_BSM_BatOutputConState_Va;
                      // Referenced by: '<S5>/SPN3095_BSM_BatOutputConState_Va'
  real_T SPN3096_BSM_ChargingPermit_Va;
                         // Referenced by: '<S5>/SPN3096_BSM_ChargingPermit_Va'
  real_T SPN3511_BST_PauseChrgRes_Active_Va;
                    // Referenced by: '<S5>/SPN3511_BST_PauseChrgRes_Active_Va'
  real_T SPN3511_BST_PauseChrgRes_CeVol_Va;
                     // Referenced by: '<S5>/SPN3511_BST_PauseChrgRes_CeVol_Va'
  real_T SPN3511_BST_PauseChrgRes_SOC_Va;
                       // Referenced by: '<S5>/SPN3511_BST_PauseChrgRes_SOC_Va'
  real_T SPN3511_BST_PauseChrgRes_ToVol_Va;
                     // Referenced by: '<S5>/SPN3511_BST_PauseChrgRes_ToVol_Va'
  real_T SPN3512_BST_PauseChrgflt_BMS_Va;
                       // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_BMS_Va'
  real_T SPN3512_BST_PauseChrgflt_Con_Va;
                       // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_Con_Va'
  real_T SPN3512_BST_PauseChrgflt_HVRelay_Va;
                   // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_HVRelay_Va'
  real_T SPN3512_BST_PauseChrgflt_Ins_Va;
                       // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_Ins_Va'
  real_T SPN3512_BST_PauseChrgflt_Oth_Va;
                       // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_Oth_Va'
  real_T SPN3512_BST_PauseChrgflt_OutCon_Va;
                    // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_OutCon_Va'
  real_T SPN3512_BST_PauseChrgflt_OverT_Va;
                     // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_OverT_Va'
  real_T SPN3512_BST_PauseChrgflt_TPoint2_Va;
                   // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_TPoint2_Va'
  real_T SPN3513_BST_PauseChrgErr_Cur_Va;
                       // Referenced by: '<S5>/SPN3513_BST_PauseChrgErr_Cur_Va'
  real_T SPN3513_BST_PauseChrgErr_Vol_Va;
                       // Referenced by: '<S5>/SPN3513_BST_PauseChrgErr_Vol_Va'
  real_T SPN3601_BSD_SOC_end_Va;// Referenced by: '<S5>/SPN3601_BSD_SOC_end_Va'
  real_T SPN3602_BSD_MinCellU_Va;
                               // Referenced by: '<S5>/SPN3602_BSD_MinCellU_Va'
  real_T SPN3603_BSD_MaxCellU_Va;
                               // Referenced by: '<S5>/SPN3603_BSD_MaxCellU_Va'
  real_T SPN3604_BSD_MinBatT_Va;// Referenced by: '<S5>/SPN3604_BSD_MinBatT_Va'
  real_T SPN3605_BSD_MaxBatT_Va;// Referenced by: '<S5>/SPN3605_BSD_MaxBatT_Va'
  real_T TP_DT_Cycle_Va;               // Referenced by: '<S37>/TP_DT_Cycle_Va'
  real_T TP_RTS_Cycle_Va;             // Referenced by: '<S37>/TP_RTS_Cycle_Va'
  real_T VC_EVCC_Cycle_Va;          // Referenced by: '<S108>/VC_EVCC_Cycle_Va'
  boolean_T BCL_Data_SW;               // Referenced by: '<S37>/BCL_Data_SW'
  boolean_T BCL_Enable_SW;             // Referenced by: '<S37>/BCL_Enable_SW'
  boolean_T BCL_Enable_Va;             // Referenced by: '<S37>/BCL_Enable_Va'
  boolean_T BEM_Data_SW;               // Referenced by: '<S37>/BEM_Data_SW'
  boolean_T BEM_Enable_SW;             // Referenced by: '<S37>/BEM_Enable_SW'
  boolean_T BEM_Enable_Va;             // Referenced by: '<S37>/BEM_Enable_Va'
  boolean_T BHM_Data_SW;               // Referenced by: '<S37>/BHM_Data_SW'
  boolean_T BHM_Enable_SW;             // Referenced by: '<S37>/BHM_Enable_SW'
  boolean_T BHM_Enable_Va;             // Referenced by: '<S37>/BHM_Enable_Va'
  boolean_T BRO_Data_SW;               // Referenced by: '<S37>/BRO_Data_SW'
  boolean_T BRO_Enable_SW;             // Referenced by: '<S37>/BRO_Enable_SW'
  boolean_T BRO_Enable_Va;             // Referenced by: '<S37>/BRO_Enable_Va'
  boolean_T BSD_Data_SW;               // Referenced by: '<S37>/BSD_Data_SW'
  boolean_T BSD_Enable_SW;             // Referenced by: '<S37>/BSD_Enable_SW'
  boolean_T BSD_Enable_Va;             // Referenced by: '<S37>/BSD_Enable_Va'
  boolean_T BSM_Data_SW;               // Referenced by: '<S37>/BSM_Data_SW'
  boolean_T BSM_Enable_SW;             // Referenced by: '<S37>/BSM_Enable_SW'
  boolean_T BSM_Enable_Va;             // Referenced by: '<S37>/BSM_Enable_Va'
  boolean_T BST_Data_SW;               // Referenced by: '<S37>/BST_Data_SW'
  boolean_T BST_Enable_SW;             // Referenced by: '<S37>/BST_Enable_SW'
  boolean_T BST_Enable_Va;             // Referenced by: '<S37>/BST_Enable_Va'
  boolean_T CONTROL_EVCC_Data_SW;
                                // Referenced by: '<S108>/CONTROL_EVCC_Data_SW'
  boolean_T CONTROL_EVCC_Enable_SW;
                              // Referenced by: '<S108>/CONTROL_EVCC_Enable_SW'
  boolean_T CONTROL_EVCC_Enable_Va;
                              // Referenced by: '<S108>/CONTROL_EVCC_Enable_Va'
  boolean_T EVCC_2015P_Enable;     // Referenced by: '<Root>/EVCC_2015P_Enable'
  boolean_T EVCC_ChargeSta;           // Referenced by: '<Root>/EVCC_ChargeSta'
  boolean_T EVCC_DefineMsg_Enable;
                               // Referenced by: '<S108>/EVCC_DefineMsg_Enable'
  boolean_T EVCC_DiagSW;               // Referenced by: '<S6>/EVCC_DiagSW'
  boolean_T EVCC_LM_ManualSTOP;     // Referenced by: '<S6>/EVCC_LM_ManualSTOP'
  boolean_T EVCC_ManualSTOP;           // Referenced by: '<S6>/EVCC_ManualSTOP'
  boolean_T EVCC_Pause;                // Referenced by:
                                          //  '<S5>/Constant38'
                                          //  '<S5>/Constant39'
                                          //  '<S5>/Constant53'
                                          //  '<S6>/Constant53'

  boolean_T EVCC_ProtocolVersion_SW;
                               // Referenced by: '<S6>/EVCC_ProtocolVersion_SW'
  boolean_T EVCC_Reboot;               // Referenced by: '<S6>/EVCC_Reboot'
  boolean_T EVCC_Relink;               // Referenced by: '<S6>/EVCC_Relink'
  boolean_T EVCC_VersionResult_SW;
                                 // Referenced by: '<S6>/EVCC_VersionResult_SW'
  boolean_T LM_EVCC_Data_SW;         // Referenced by: '<S108>/LM_EVCC_Data_SW'
  boolean_T LM_EVCC_Enable_SW;     // Referenced by: '<S108>/LM_EVCC_Enable_SW'
  boolean_T LM_EVCC_Enable_Va;     // Referenced by: '<S108>/LM_EVCC_Enable_Va'
  boolean_T PGI02_check_SW;            // Referenced by: '<S6>/PGI02_check_SW'
  boolean_T PGI06_K5_SW;               // Referenced by: '<S6>/PGI06_K5_SW'
  boolean_T PGI06_K6_SW;               // Referenced by: '<S6>/PGI06_K6_SW'
  boolean_T PGI09_wakeup_SW;           // Referenced by: '<S6>/PGI09_wakeup_SW'
  boolean_T PGI12_Authentic_SW;     // Referenced by: '<S6>/PGI12_Authentic_SW'
  boolean_T PGI22_SOC_SW;              // Referenced by: '<S6>/PGI22_SOC_SW'
  boolean_T PGI32_VAuthenStatus;   // Referenced by: '<S6>/PGI32_VAuthenStatus'
  boolean_T PGI52_CheckState_SW;   // Referenced by: '<S6>/PGI52_CheckState_SW'
  boolean_T PGI72_EVCCReady_SW;     // Referenced by: '<S6>/PGI72_EVCCReady_SW'
  boolean_T PGI72_EVCC_V_Exe_SW;   // Referenced by: '<S6>/PGI72_EVCC_V_Exe_SW'
  boolean_T PGI73_A_SW;                // Referenced by: '<S6>/PGI73_A_SW'
  boolean_T PGI73_PowerMode_SW;     // Referenced by: '<S6>/PGI73_PowerMode_SW'
  boolean_T PGI73_V_SW;                // Referenced by: '<S6>/PGI73_V_SW'
  boolean_T PGI74_SOC_SW;              // Referenced by: '<S6>/PGI74_SOC_SW'
  boolean_T PGI74_TimeRemain_SW;   // Referenced by: '<S6>/PGI74_TimeRemain_SW'
  boolean_T PGI79_Pause_SW;            // Referenced by: '<S6>/PGI79_Pause_SW'
  boolean_T PGI91_EVCCDetectSta_SW;
                                // Referenced by: '<S6>/PGI91_EVCCDetectSta_SW'
  boolean_T PGI94_SOC_SW;              // Referenced by: '<S6>/PGI94_SOC_SW'
  boolean_T SM_RM_EVCC_Data_SW;   // Referenced by: '<S108>/SM_RM_EVCC_Data_SW'
  boolean_T SM_RM_EVCC_Enable_SW;
                                // Referenced by: '<S108>/SM_RM_EVCC_Enable_SW'
  boolean_T SM_RM_EVCC_Enable_Va;
                                // Referenced by: '<S108>/SM_RM_EVCC_Enable_Va'
  boolean_T SM_URM_EVCC_Data_SW; // Referenced by: '<S108>/SM_URM_EVCC_Data_SW'
  boolean_T SM_URM_EVCC_Enable_SW;
                               // Referenced by: '<S108>/SM_URM_EVCC_Enable_SW'
  boolean_T SM_URM_EVCC_Enable_Va;
                               // Referenced by: '<S108>/SM_URM_EVCC_Enable_Va'
  boolean_T SPN2565_BRM_ProtocolVer_SW;
                            // Referenced by: '<S5>/SPN2565_BRM_ProtocolVer_SW'
  boolean_T SPN2566_BRM_BatteryType_SW;
                            // Referenced by: '<S5>/SPN2566_BRM_BatteryType_SW'
  boolean_T SPN2567_BRM_BatteryCapacity_SW;
                        // Referenced by: '<S5>/SPN2567_BRM_BatteryCapacity_SW'
  boolean_T SPN2568_BRM_BatteryVoltage_SW;
                         // Referenced by: '<S5>/SPN2568_BRM_BatteryVoltage_SW'
  boolean_T SPN2569_BRM_BatteryProducer_SW;
                        // Referenced by: '<S5>/SPN2569_BRM_BatteryProducer_SW'
  boolean_T SPN2570_BRM_BatterySN_SW;
                              // Referenced by: '<S5>/SPN2570_BRM_BatterySN_SW'
  boolean_T SPN2571_BRM_ManufactureDate_SW;
                        // Referenced by: '<S5>/SPN2571_BRM_ManufactureDate_SW'
  boolean_T SPN2571_BRM_ManufactureMonth_SW;
                       // Referenced by: '<S5>/SPN2571_BRM_ManufactureMonth_SW'
  boolean_T SPN2571_BRM_ManufactureYear_SW;
                        // Referenced by: '<S5>/SPN2571_BRM_ManufactureYear_SW'
  boolean_T SPN2572_BRM_BatteryChargedTimes_SW;
                    // Referenced by: '<S5>/SPN2572_BRM_BatteryChargedTimes_SW'
  boolean_T SPN2573_BRM_Ownership_SW;
                              // Referenced by: '<S5>/SPN2573_BRM_Ownership_SW'
  boolean_T SPN2574_BRM_BRMReserved_SW;
                            // Referenced by: '<S5>/SPN2574_BRM_BRMReserved_SW'
  boolean_T SPN2575_BRM_VINPart1_SW;
                               // Referenced by: '<S5>/SPN2575_BRM_VINPart1_SW'
  boolean_T SPN2575_BRM_VINPart2_SW;
                               // Referenced by: '<S5>/SPN2575_BRM_VINPart2_SW'
  boolean_T SPN2575_BRM_VINPart3_SW;
                               // Referenced by: '<S5>/SPN2575_BRM_VINPart3_SW'
  boolean_T SPN2575_BRM_VINPart4_SW;
                              // Referenced by: '<S5>/SPN2575_BRM_VINPart2_SW1'
  boolean_T SPN2575_BRM_VINPart5_SW;
                              // Referenced by: '<S5>/SPN2575_BRM_VINPart3_SW1'
  boolean_T SPN2576_BRM_BMSSoftVer_Reserved_SW;
                    // Referenced by: '<S5>/SPN2576_BRM_BMSSoftVer_Reserved_SW'
  boolean_T SPN2576_BRM_BMSSoftwareVer_Date_SW;
                    // Referenced by: '<S5>/SPN2576_BRM_BMSSoftwareVer_Date_SW'
  boolean_T SPN2576_BRM_BMSSoftwareVer_Num_SW;
                     // Referenced by: '<S5>/SPN2576_BRM_BMSSoftwareVer_Num_SW'
  boolean_T SPN2601_BHM_ChargeTotalVolt_MAX_SW;
                    // Referenced by: '<S5>/SPN2601_BHM_ChargeTotalVolt_MAX_SW'
  boolean_T SPN2816_BCP_CellChargeVolt_MAX_SW;
                     // Referenced by: '<S5>/SPN2816_BCP_CellChargeVolt_MAX_SW'
  boolean_T SPN2817_BCP_ChargeCurrent_MAX_SW;
                      // Referenced by: '<S5>/SPN2817_BCP_ChargeCurrent_MAX_SW'
  boolean_T SPN2818_BCP_NominalCapacity_SW;
                        // Referenced by: '<S5>/SPN2818_BCP_NominalCapacity_SW'
  boolean_T SPN2819_BCP_ChargeTotalVolt_MAX_SW;
                    // Referenced by: '<S5>/SPN2819_BCP_ChargeTotalVolt_MAX_SW'
  boolean_T SPN2820_BCP_Temperature_MAX_SW;
                        // Referenced by: '<S5>/SPN2820_BCP_Temperature_MAX_SW'
  boolean_T SPN2821_BCP_SOC_SW;     // Referenced by: '<S5>/SPN2821_BCP_SOC_SW'
  boolean_T SPN2822_BCP_BatteryTotalVoltage_SW;
                    // Referenced by: '<S5>/SPN2822_BCP_BatteryTotalVoltage_SW'
  boolean_T SPN2829_BRO_BMSReadyOrNot_SW;
                          // Referenced by: '<S5>/SPN2829_BRO_BMSReadyOrNot_SW'
  boolean_T SPN3072_BCL_VoltageRequirement_SW;
                     // Referenced by: '<S5>/SPN3072_BCL_VoltageRequirement_SW'
  boolean_T SPN3073_BCL_CurrentRequirement_SW;
                     // Referenced by: '<S5>/SPN3073_BCL_CurrentRequirement_SW'
  boolean_T SPN3074_BCL_ChargingModel_SW;
                          // Referenced by: '<S5>/SPN3074_BCL_ChargingModel_SW'
  boolean_T SPN3075_BCS_ChargEVoltMeasure_SW;
                      // Referenced by: '<S5>/SPN3075_BCS_ChargEVoltMeasure_SW'
  boolean_T SPN3076_BCS_ChargeCurrentMeasure_SW;
                   // Referenced by: '<S5>/SPN3076_BCS_ChargeCurrentMeasure_SW'
  boolean_T SPN3077_BCS_Max_CellVoltage_Num_SW;
                    // Referenced by: '<S5>/SPN3077_BCS_Max_CellVoltage_Num_SW'
  boolean_T SPN3077_BCS_Max_CellVoltage_SW;
                        // Referenced by: '<S5>/SPN3077_BCS_Max_CellVoltage_SW'
  boolean_T SPN3078_BCS_SOC_SW;     // Referenced by: '<S5>/SPN3078_BCS_SOC_SW'
  boolean_T SPN3079_BCS_ChargeTimeRest_SW;
                         // Referenced by: '<S5>/SPN3079_BCS_ChargeTimeRest_SW'
  boolean_T SPN3085_BSM_NumberHighestVB_SW;
                        // Referenced by: '<S5>/SPN3085_BSM_NumberHighestVB_SW'
  boolean_T SPN3086_BSM_BatteryHighsestTemp_SW;
                    // Referenced by: '<S5>/SPN3086_BSM_BatteryHighsestTemp_SW'
  boolean_T SPN3087_BSM_NumHTemTestingPoint_SW;
                    // Referenced by: '<S5>/SPN3087_BSM_NumHTemTestingPoint_SW'
  boolean_T SPN3088_BSM_BatteryLowestTemp_SW;
                      // Referenced by: '<S5>/SPN3088_BSM_BatteryLowestTemp_SW'
  boolean_T SPN3089_BSM_NumLTemTestingPoint_SW;
                    // Referenced by: '<S5>/SPN3089_BSM_NumLTemTestingPoint_SW'
  boolean_T SPN3090_BSM_CellVoltageState_SW;
                       // Referenced by: '<S5>/SPN3090_BSM_CellVoltageState_SW'
  boolean_T SPN3091_BSM_VehicleBatterySOC_SW;
                      // Referenced by: '<S5>/SPN3091_BSM_VehicleBatterySOC_SW'
  boolean_T SPN3092_BSM_ChargingOverCurrent_SW;
                    // Referenced by: '<S5>/SPN3092_BSM_ChargingOverCurrent_SW'
  boolean_T SPN3093_BSM_BatteryTemState_SW;
                        // Referenced by: '<S5>/SPN3093_BSM_BatteryTemState_SW'
  boolean_T SPN3094_BSM_BatInsulationState_SW;
                     // Referenced by: '<S5>/SPN3094_BSM_BatInsulationState_SW'
  boolean_T SPN3095_BSM_BatOutputConState_SW;
                      // Referenced by: '<S5>/SPN3095_BSM_BatOutputConState_SW'
  boolean_T SPN3096_BSM_ChargingPermit_SW;
                         // Referenced by: '<S5>/SPN3096_BSM_ChargingPermit_SW'
  boolean_T SPN3511_BST_PauseChrgRes_Active_SW;
                    // Referenced by: '<S5>/SPN3511_BST_PauseChrgRes_Active_SW'
  boolean_T SPN3511_BST_PauseChrgRes_CeVol_SW;
                     // Referenced by: '<S5>/SPN3511_BST_PauseChrgRes_CeVol_SW'
  boolean_T SPN3511_BST_PauseChrgRes_SOC_SW;
                       // Referenced by: '<S5>/SPN3511_BST_PauseChrgRes_SOC_SW'
  boolean_T SPN3511_BST_PauseChrgRes_ToVol_SW;
                     // Referenced by: '<S5>/SPN3511_BST_PauseChrgRes_ToVol_SW'
  boolean_T SPN3512_BST_PauseChrgflt_BMS_SW;
                       // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_BMS_SW'
  boolean_T SPN3512_BST_PauseChrgflt_Con_SW;
                       // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_Con_SW'
  boolean_T SPN3512_BST_PauseChrgflt_HVRelay_SW;
                   // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_HVRelay_SW'
  boolean_T SPN3512_BST_PauseChrgflt_Ins_SW;
                       // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_Ins_SW'
  boolean_T SPN3512_BST_PauseChrgflt_Oth_SW;
                       // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_Oth_SW'
  boolean_T SPN3512_BST_PauseChrgflt_OutCon_SW;
                    // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_OutCon_SW'
  boolean_T SPN3512_BST_PauseChrgflt_OverT_SW;
                     // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_OverT_SW'
  boolean_T SPN3512_BST_PauseChrgflt_TPoint2_SW;
                   // Referenced by: '<S5>/SPN3512_BST_PauseChrgflt_TPoint2_SW'
  boolean_T SPN3513_BST_PauseChrgErr_Cur_SW;
                       // Referenced by: '<S5>/SPN3513_BST_PauseChrgErr_Cur_SW'
  boolean_T SPN3513_BST_PauseChrgErr_Vol_SW;
                       // Referenced by: '<S5>/SPN3513_BST_PauseChrgErr_Vol_SW'
  boolean_T SPN3601_BSD_SOC_end_SW;
                                // Referenced by: '<S5>/SPN3601_BSD_SOC_end_SW'
  boolean_T SPN3602_BSD_MinCellU_SW;
                               // Referenced by: '<S5>/SPN3602_BSD_MinCellU_SW'
  boolean_T SPN3603_BSD_MaxCellU_SW;
                               // Referenced by: '<S5>/SPN3603_BSD_MaxCellU_SW'
  boolean_T SPN3604_BSD_MinBatT_SW;
                                // Referenced by: '<S5>/SPN3604_BSD_MinBatT_SW'
  boolean_T SPN3605_BSD_MaxBatT_SW;
                                // Referenced by: '<S5>/SPN3605_BSD_MaxBatT_SW'
  boolean_T TP_DT_Data_SW;             // Referenced by: '<S37>/TP_DT_Data_SW'
  boolean_T TP_DT_Enable_SW;          // Referenced by: '<S37>/TP_DT_Enable_SW'
  boolean_T TP_DT_Enable_Va;          // Referenced by: '<S37>/TP_DT_Enable_Va'
  boolean_T TP_RTS_Data_SW;            // Referenced by: '<S37>/TP_RTS_Data_SW'
  boolean_T TP_RTS_Enable_SW;        // Referenced by: '<S37>/TP_RTS_Enable_SW'
  boolean_T TP_RTS_Enable_Va;        // Referenced by: '<S37>/TP_RTS_Enable_Va'
  boolean_T VC_EVCC_Data_SW;         // Referenced by: '<S108>/VC_EVCC_Data_SW'
  boolean_T VC_EVCC_Enable_SW;     // Referenced by: '<S108>/VC_EVCC_Enable_SW'
  boolean_T VC_EVCC_Enable_Va;     // Referenced by: '<S108>/VC_EVCC_Enable_Va'
  int16_T PGI22_Temp;                  // Referenced by: '<S6>/PGI22_Temp'
  int16_T PGI77_SingleBattTemp_Max;
                              // Referenced by: '<S6>/PGI77_SingleBattTemp_Max'
  int16_T PGI77_SingleBattTemp_Min;
                              // Referenced by: '<S6>/PGI77_SingleBattTemp_Min'
  uint32_T EVCC_CVList[4];             // Referenced by: '<S6>/CvList'
  uint32_T EVCC_DefineMsg_Cycle;// Referenced by: '<S108>/EVCC_DefineMsg_Cycle'
  uint32_T EVCC_DefineMsg_ID;      // Referenced by: '<S108>/EVCC_DefineMsg_ID'
  uint32_T EVCC_ProtocolVersion_Va;
                               // Referenced by: '<S6>/EVCC_ProtocolVersion_Va'
  uint8_T BCL_Data_Va[8];              // Referenced by: '<S37>/BCL_Data_Va'
  uint8_T BEM_Data_Va[8];              // Referenced by: '<S37>/BEM_Data_Va'
  uint8_T BHM_Data_Va[8];              // Referenced by: '<S37>/BHM_Data_Va'
  uint8_T BRO_Data_Va[8];              // Referenced by: '<S37>/BRO_Data_Va'
  uint8_T BSD_Data_Va[8];              // Referenced by: '<S37>/BSD_Data_Va'
  uint8_T BSM_Data_Va[8];              // Referenced by: '<S37>/BSM_Data_Va'
  uint8_T BST_Data_Va[8];              // Referenced by: '<S37>/BST_Data_Va'
  uint8_T CONTROL_EVCC_Data_Va[8];
                                // Referenced by: '<S108>/CONTROL_EVCC_Data_Va'
  uint8_T EVCC_CANType;                // Referenced by: '<S6>/EVCC_CANType'
  uint8_T EVCC_CPVersion;              // Referenced by: '<S6>/EVCC_CPVersion'
  uint8_T EVCC_DefineMsg_Data[8];// Referenced by: '<S108>/EVCC_DefineMsg_Data'
  uint8_T EVCC_DefineMsg_Extended;
                             // Referenced by: '<S108>/EVCC_DefineMsg_Extended'
  uint8_T EVCC_DefineMsg_Length;
                               // Referenced by: '<S108>/EVCC_DefineMsg_Length'
  uint8_T EVCC_K_Limit;                // Referenced by: '<S6>/EVCC_K_Limit'
  uint8_T EVCC_Reserved_VN;           // Referenced by: '<S6>/EVCC_Reserved_VN'
  uint8_T EVCC_TLVersion;              // Referenced by: '<S6>/EVCC_TLVersion'
  uint8_T EVCC_VersionResult_Va; // Referenced by: '<S6>/EVCC_VersionResult_Va'
  uint8_T LM_EVCC_Data_Va[8];        // Referenced by: '<S108>/LM_EVCC_Data_Va'
  uint8_T PGI02;                       // Referenced by: '<S6>/PGI02'
  uint8_T PGI02_check_Va;              // Referenced by: '<S6>/PGI02_check_Va'
  uint8_T PGI04_Data[8];               // Referenced by: '<S6>/PGI04_Data'
  uint8_T PGI06;                       // Referenced by: '<S6>/PGI06'
  uint8_T PGI06_K5_Va;                 // Referenced by: '<S6>/PGI06_K5_Va'
  uint8_T PGI06_K6_Va;                 // Referenced by: '<S6>/PGI06_K6_Va'
  uint8_T PGI09;                       // Referenced by: '<S6>/PGI09'
  uint8_T PGI09_wakeup_Va;             // Referenced by: '<S6>/PGI09_wakeup_Va'
  uint8_T PGI12;                       // Referenced by: '<S6>/PGI12'
  uint8_T PGI12_Authentic_Va;       // Referenced by: '<S6>/PGI12_Authentic_Va'
  uint8_T PGI12_EndOfCharge;         // Referenced by: '<S6>/PGI12_EndOfCharge'
  uint8_T PGI12_OutLoopDete;         // Referenced by: '<S6>/PGI12_OutLoopDete'
  uint8_T PGI12_ParmCfg;               // Referenced by: '<S6>/PGI12_ParmCfg'
  uint8_T PGI12_PowerMode;             // Referenced by: '<S6>/PGI12_PowerMode'
  uint8_T PGI12_PreChgEnTrans;     // Referenced by: '<S6>/PGI12_PreChgEnTrans'
  uint8_T PGI12_Scheduled;             // Referenced by: '<S6>/PGI12_Scheduled'
  uint8_T PGI22;                       // Referenced by: '<S6>/PGI22'
  uint8_T PGI22_BatteryType;         // Referenced by: '<S6>/PGI22_BatteryType'
  uint8_T PGI22_RestartNum;           // Referenced by: '<S6>/PGI22_RestartNum'
  uint8_T PGI32;                       // Referenced by: '<S6>/PGI32'
  uint8_T PGI52;                       // Referenced by: '<S6>/PGI52'
  uint8_T PGI52_CheckState_Va;     // Referenced by: '<S6>/PGI52_CheckState_Va'
  uint8_T PGI72;                       // Referenced by: '<S6>/PGI72'
  uint8_T PGI72_EVCCReady_Va;       // Referenced by: '<S6>/PGI72_EVCCReady_Va'
  uint8_T PGI73;                       // Referenced by: '<S6>/PGI73'
  uint8_T PGI73_PowerMode_Va;       // Referenced by: '<S6>/PGI73_PowerMode_Va'
  uint8_T PGI74;                       // Referenced by: '<S6>/PGI4'
  uint8_T PGI77;                       // Referenced by: '<S6>/PGI77'
  uint8_T PGI79;                       // Referenced by: '<S6>/PGI79'
  uint8_T PGI79_Pause_Va;              // Referenced by: '<S6>/PGI79_Pause_Va'
  uint8_T PGI91;                       // Referenced by: '<S6>/PGI91'
  uint8_T PGI91_EVCCDetectSta_Va;
                                // Referenced by: '<S6>/PGI91_EVCCDetectSta_Va'
  uint8_T PGI94;                       // Referenced by: '<S6>/PGI94'
  uint8_T SM_RM_EVCC_Data_Va[8];  // Referenced by: '<S108>/SM_RM_EVCC_Data_Va'
  uint8_T SM_URM_EVCC_Data_Va[8];// Referenced by: '<S108>/SM_URM_EVCC_Data_Va'
  uint8_T TP_DT_Data_Va[8];            // Referenced by: '<S37>/TP_DT_Data_Va'
  uint8_T TP_RTS_Data_Va[8];           // Referenced by: '<S37>/TP_RTS_Data_Va'
  uint8_T VC_EVCC_Data_Va[8];        // Referenced by: '<S108>/VC_EVCC_Data_Va'
};

extern CAN_DATATYPE CAN_DATATYPE_GROUND;

// External data declarations for dependent source files
extern const CAN_MESSAGE_BUS QC2015P_EVCC_rtZCAN_MESSAGE_BUS;// CAN_MESSAGE_BUS ground 

// Exported data declaration

// Declaration for custom storage class: Struct
extern rt_Simulink_Struct_type rt_Simulink_Struct;

// Class declaration for model QC2015P_EVCC
class QC2015P_EVCC final
{
  // public data and function members
 public:
  // Block signals for system '<S5>/MAIN_CNT'
  struct B_MAIN_CNT_QC2015P_EVCC_T {
    real_T m50_1;                      // '<S5>/MAIN_CNT'
    real_T m50_11;                     // '<S5>/MAIN_CNT'
    real_T m50_21;                     // '<S5>/MAIN_CNT'
    real_T m50_31;                     // '<S5>/MAIN_CNT'
    real_T m50_41;                     // '<S5>/MAIN_CNT'
    real_T m50_2;                      // '<S5>/MAIN_CNT'
    real_T m50_12;                     // '<S5>/MAIN_CNT'
    real_T m10_3;                      // '<S5>/MAIN_CNT'
    real_T m10_4;                      // '<S5>/MAIN_CNT'
    real_T m10_5;                      // '<S5>/MAIN_CNT'
    real_T m10_6;                      // '<S5>/MAIN_CNT'
  };

  // Block states (default storage) for system '<S5>/MAIN_CNT'
  struct DW_MAIN_CNT_QC2015P_EVCC_T {
    real_T timer;                      // '<S5>/MAIN_CNT'
    uint8_T is_active_c41_QC2015P_EVCC;// '<S5>/MAIN_CNT'
    uint8_T is_c41_QC2015P_EVCC;       // '<S5>/MAIN_CNT'
  };

  // Block states (default storage) for system '<S37>/sendCyclic10'
  struct DW_sendCyclic10_QC2015P_EVCC_T {
    real_T cnt;                        // '<S37>/sendCyclic10'
    uint8_T is_active_c29_QC2015P_EVCC;// '<S37>/sendCyclic10'
    uint8_T is_c29_QC2015P_EVCC;       // '<S37>/sendCyclic10'
  };

  // Block states (default storage) for system '<S5>/normal250'
  struct DW_normal250_QC2015P_EVCC_T {
    real_T cnt;                        // '<S5>/normal250'
    uint8_T is_active_c44_QC2015P_EVCC;// '<S5>/normal250'
    uint8_T is_c44_QC2015P_EVCC;       // '<S5>/normal250'
  };

  // Block states (default storage) for system '<S6>/keep50ms1'
  struct DW_keep50ms1_QC2015P_EVCC_T {
    uint8_T is_active_c21_QC2015P_EVCC;// '<S6>/keep50ms1'
    uint8_T is_c21_QC2015P_EVCC;       // '<S6>/keep50ms1'
    uint8_T temporalCounter_i1;        // '<S6>/keep50ms1'
  };

  // Block states (default storage) for system '<S6>/normal1000'
  struct DW_normal1000_QC2015P_EVCC_T {
    real_T cnt;                        // '<S6>/normal1000'
    uint8_T is_active_c20_QC2015P_EVCC;// '<S6>/normal1000'
    uint8_T is_c20_QC2015P_EVCC;       // '<S6>/normal1000'
  };

  // Block states (default storage) for system '<S6>/normal1000_50for3'
  struct DW_normal1000_50for3_QC2015P__T {
    real_T times;                      // '<S6>/normal1000_50for3'
    real_T cnt;                        // '<S6>/normal1000_50for3'
    uint8_T is_active_c19_QC2015P_EVCC;// '<S6>/normal1000_50for3'
    uint8_T is_c19_QC2015P_EVCC;       // '<S6>/normal1000_50for3'
  };

  // Block signals (default storage)
  struct B_QC2015P_EVCC_T {
    CAN_FD_MESSAGE_BUS CANFDPacK5;     // '<S6>/CAN FD PacK5'
    CAN_FD_MESSAGE_BUS CANFDPack;      // '<S6>/CAN FD Pack'
    CAN_FD_MESSAGE_BUS CANFDPack_o;    // '<S5>/CAN FD Pack'
    CAN_FD_MESSAGE_BUS CANFDPack1;     // '<S5>/CAN FD Pack1'
    CAN_FD_MESSAGE_BUS CANFDPack2;     // '<S5>/CAN FD Pack2'
    CAN_MSG_BUS Switch4;               // '<S8>/Switch4'
    CAN_MSG_BUS Switch4_c;             // '<S15>/Switch4'
    CAN_MSG_BUS Switch4_m;             // '<S14>/Switch4'
    CAN_MSG_BUS Switch4_g;             // '<S16>/Switch4'
    CAN_MSG_BUS Switch4_k;             // '<S9>/Switch4'
    CAN_MSG_BUS Switch4_b;             // '<S13>/Switch4'
    CAN_MSG_BUS Switch4_gn;            // '<S19>/Switch4'
    CAN_MSG_BUS Switch4_mw;            // '<S12>/Switch4'
    CAN_MSG_BUS Switch4_m3;            // '<S11>/Switch4'
    CAN_MSG_BUS Switch4_j;             // '<S20>/Switch4'
    CAN_MSG_BUS Switch4_cp;            // '<S17>/Switch4'
    CAN_MSG_BUS Switch4_cn;            // '<S21>/Switch4'
    CAN_MSG_BUS Switch4_gl;            // '<S10>/Switch4'
    CAN_MESSAGE_BUS CANPack5;          // '<S108>/CAN Pack5'
    CAN_MESSAGE_BUS CANPack;           // '<S108>/CAN Pack'
    CAN_MESSAGE_BUS CANPack1;          // '<S108>/CAN Pack1'
    CAN_MESSAGE_BUS CANPack2;          // '<S108>/CAN Pack2'
    CAN_MESSAGE_BUS CANPack3;          // '<S108>/CAN Pack3'
    CAN_MESSAGE_BUS CANPack4;          // '<S108>/CAN Pack4'
    CAN_MESSAGE_BUS VectorConcatenate[6];// '<S108>/Vector Concatenate'
    CAN_MESSAGE_BUS CANPack18;         // '<S5>/CAN Pack18'
    CAN_MESSAGE_BUS CANPack20;         // '<S5>/CAN Pack20'
    CAN_MESSAGE_BUS CANPack21;         // '<S5>/CAN Pack21'
    CAN_MESSAGE_BUS CANPack25;         // '<S5>/CAN Pack25'
    CAN_MESSAGE_BUS CANPack28;         // '<S5>/CAN Pack28'
    CAN_MESSAGE_BUS CANPack31;         // '<S5>/CAN Pack31'
    CAN_MESSAGE_BUS CANPack10;         // '<S37>/CAN Pack10'
    CAN_MESSAGE_BUS CANPack11;         // '<S37>/CAN Pack11'
    CAN_MESSAGE_BUS CANPack12;         // '<S37>/CAN Pack12'
    CAN_MESSAGE_BUS CANPack13;         // '<S37>/CAN Pack13'
    CAN_MESSAGE_BUS CANPack14;         // '<S37>/CAN Pack14'
    CAN_MESSAGE_BUS CANPack15;         // '<S37>/CAN Pack15'
    CAN_MESSAGE_BUS CANPack16;         // '<S37>/CAN Pack16'
    CAN_MESSAGE_BUS CANPack17;         // '<S37>/CAN Pack17'
    CAN_MESSAGE_BUS CANPack9;          // '<S37>/CAN Pack9'
    CAN_MESSAGE_BUS VectorConcatenate_j[9];// '<S37>/Vector Concatenate'
    real_T PGI01_FC;                   // '<S4>/CAN Unpack5'
    real_T PGI01_FDC;                  // '<S4>/CAN Unpack5'
    real_T PGI03_STOP_reason0;         // '<S4>/CAN Unpack5'
    real_T PGI03_STOP_reason1;         // '<S4>/CAN Unpack5'
    real_T PGI03_STOP_type;            // '<S4>/CAN Unpack5'
    real_T PGI03_reLink;               // '<S4>/CAN Unpack5'
    real_T PGI08_wakeup;               // '<S4>/CAN Unpack5'
    real_T PGI33_AuthenResult;         // '<S4>/CAN Unpack5'
    real_T PGI33_SAuthenFDC;           // '<S4>/CAN Unpack5'
    real_T PGI35_AuthenResult;         // '<S4>/CAN Unpack5'
    real_T PGI35_SAuthenFDC;           // '<S4>/CAN Unpack5'
    real_T PGI39_AuthenResult;         // '<S4>/CAN Unpack5'
    real_T PGI39_SAuthenFDC;           // '<S4>/CAN Unpack5'
    real_T PGI78_Pause;                // '<S4>/CAN Unpack5'
    real_T PGI93_ChargePower;          // '<S4>/CAN Unpack5'
    real_T PGI93_DishargePower;        // '<S4>/CAN Unpack5'
    real_T S_SECC_PGI;                 // '<S4>/CAN Unpack5'
    real_T SECC_CANType;               // '<S4>/CAN Unpack2'
    real_T SECC_CPVersoin;             // '<S4>/CAN Unpack2'
    real_T SECC_ProtocolVersion0;      // '<S4>/CAN Unpack2'
    real_T SECC_ProtocolVersion1;      // '<S4>/CAN Unpack2'
    real_T SECC_ProtocolVersion2;      // '<S4>/CAN Unpack2'
    real_T SECC_Reserved;              // '<S4>/CAN Unpack2'
    real_T SECC_TLVersion;             // '<S4>/CAN Unpack2'
    real_T SECC_VersionResult;         // '<S4>/CAN Unpack2'
    real_T Ctrl_SECC_Byte0;            // '<S4>/CAN Unpack8'
    real_T confirmPGI;                 // '<S4>/CAN Unpack8'
    real_T recvedByteTotal;            // '<S4>/CAN Unpack8'
    real_T recvedNumTotal;             // '<S4>/CAN Unpack8'
    real_T waitRecvNumStart;           // '<S4>/CAN Unpack8'
    real_T waitRecvNumTotal;           // '<S4>/CAN Unpack8'
    real_T PGI05_K1;                   // '<S4>/CAN Unpack6'
    real_T PGI05_K2;                   // '<S4>/CAN Unpack6'
    real_T PGI07_ELock;                // '<S4>/CAN Unpack6'
    real_T PGI31_CAuthenStatus;        // '<S4>/CAN Unpack6'
    real_T PGI31_MTime2;               // '<S4>/CAN Unpack6'
    real_T PGI51_DetectTest;           // '<S4>/CAN Unpack6'
    real_T PGI51_Discharge;            // '<S4>/CAN Unpack6'
    real_T PGI51_Insulation;           // '<S4>/CAN Unpack6'
    real_T PGI51_ShortCircuit;         // '<S4>/CAN Unpack6'
    real_T PGI71_ChargerReady;         // '<S4>/CAN Unpack6'
    real_T PGI75_MaxOutput_A;          // '<S4>/CAN Unpack6'
    real_T PGI75_OutputChangeReason;   // '<S4>/CAN Unpack6'
    real_T PGI76_A_Exe;                // '<S4>/CAN Unpack6'
    real_T PGI76_V_Exe;                // '<S4>/CAN Unpack6'
    real_T PGI92_AllowDetectCheck;     // '<S4>/CAN Unpack6'
    real_T SU_SECC_PGI;                // '<S4>/CAN Unpack6'
    real_T SPN2600_CHM_ProtocolVer;    // '<S4>/CAN Unpack7'
    real_T SPN2560_CRM_BMSIdentify;    // '<S4>/CAN Unpack11'
    real_T SPN2561_CRM_ChargerIndex;   // '<S4>/CAN Unpack11'
    real_T SPN2562_CRM_ChargerLocationCode;// '<S4>/CAN Unpack11'
    real_T SPN2830_CRO_ChargerReadyOrNot;// '<S4>/CAN Unpack10'
    real_T SPN2824_CML_OutputVoltage_MAX;// '<S4>/CAN Unpack4'
    real_T SPN2825_CML_OutputVoltage_MIN;// '<S4>/CAN Unpack4'
    real_T SPN2826_CML_OutputCurrent_MAX;// '<S4>/CAN Unpack4'
    real_T SPN2827_CML_OutputCurrent_MIN;// '<S4>/CAN Unpack4'
    real_T SPN3081_CCS_VoltageOutputValue;// '<S4>/CAN Unpack1'
    real_T SPN3082_CCS_ChargingCurrentValu;// '<S4>/CAN Unpack1'
    real_T SPN3083_CCS_CumulativeChargeTim;// '<S4>/CAN Unpack1'
    real_T SPN3929_CCS_ChargingAllow;  // '<S4>/CAN Unpack1'
    real_T SPN3521_CST_PauseChrgRes_Active;// '<S4>/CAN Unpack13'
    real_T SPN3521_CST_PauseChrgRes_Cond;// '<S4>/CAN Unpack13'
    real_T SPN3521_CST_PauseChrgRes_Flt;// '<S4>/CAN Unpack13'
    real_T SPN3521_CST_PauseChrgRes_Man;// '<S4>/CAN Unpack13'
    real_T SPN3522_CST_PauseChrgflt_Con;// '<S4>/CAN Unpack13'
    real_T SPN3522_CST_PauseChrgflt_IntTem;// '<S4>/CAN Unpack13'
    real_T SPN3522_CST_PauseChrgflt_Oth;// '<S4>/CAN Unpack13'
    real_T SPN3522_CST_PauseChrgflt_Qua;// '<S4>/CAN Unpack13'
    real_T SPN3522_CST_PauseChrgflt_Sud;// '<S4>/CAN Unpack13'
    real_T SPN3522_CST_PauseChrgflt_Tem;// '<S4>/CAN Unpack13'
    real_T SPN3523_CST_PauseChrgErr_Cur;// '<S4>/CAN Unpack13'
    real_T SPN3523_CST_PauseChrgErr_Vol;// '<S4>/CAN Unpack13'
    real_T SPN3611_CSD_ChrgTime;       // '<S4>/CAN Unpack12'
    real_T SPN3612_CSD_Energy_OutPower;// '<S4>/CAN Unpack12'
    real_T SPN3613_CSD_ChrgNum;        // '<S4>/CAN Unpack12'
    real_T CANFDUnpack_o1;             // '<S6>/CAN FD Unpack'
    real_T CANFDUnpack_o2;             // '<S6>/CAN FD Unpack'
    real_T CANFDUnpack_o3;             // '<S6>/CAN FD Unpack'
    real_T CANFDUnpack_o4;             // '<S6>/CAN FD Unpack'
    real_T CANFDUnpack_o5;             // '<S6>/CAN FD Unpack'
    real_T CANFDUnpack_o6;             // '<S6>/CAN FD Unpack'
    real_T DataTypeConversion37[8];    // '<S6>/Data Type Conversion37'
    real_T Switch3;                    // '<S6>/Switch3'
    real_T enable_e;                   // '<S6>/normal250_3'
    real_T enable_d;                   // '<S6>/normal1000_50for3_'
    real_T enable_o;                   // '<S6>/normal1000_50for3'
    real_T enable_g;                   // '<S6>/normal1000_1'
    real_T enable_a;                   // '<S6>/normal1000'
    real_T outPGI;                     // '<S6>/keep1_for10ms'
    real_T outNextStep;                // '<S6>/VN'
    real_T VersionResult;              // '<S6>/VN'
    real_T VN_Enable;                  // '<S6>/VN'
    real_T DetectAllow;                // '<S6>/QC2015P_STOP'
    real_T RelinkAllow;                // '<S6>/QC2015P_STOP'
    real_T RebootAllow;                // '<S6>/QC2015P_STOP'
    real_T SEQ;                        // '<S6>/QC2015P_MAIN'
    real_T ReStart;                    // '<S6>/QC2015P_MAIN'
    real_T PGI73_V;                    // '<S6>/QC2015P_MAIN'
    real_T PGI73_A;                    // '<S6>/QC2015P_MAIN'
    real_T enable_k;                   // '<S108>/sendCyclic5'
    real_T enable_af;                  // '<S108>/sendCyclic4'
    real_T enable_f;                   // '<S108>/sendCyclic3'
    real_T enable_m;                   // '<S108>/sendCyclic2'
    real_T enable_a4;                  // '<S108>/sendCyclic1'
    real_T enable_h;                   // '<S108>/sendCyclic'
    real_T LM_NACK;                    // '<S6>/LM_Send'
    real_T sendFlg;                    // '<S6>/LM_Send'
    real_T n_num;                      // '<S6>/LM_Send'
    real_T sendFlg_i;                  // '<S6>/LM_Recv'
    real_T n_num_p;                    // '<S6>/LM_Recv'
    real_T k_num;                      // '<S6>/LM_Recv'
    real_T recv_tfra;                  // '<S6>/LM_Recv'
    real_T totalBytes;                 // '<S6>/LM_Recv'
    real_T Sw19;                       // '<S5>/Sw19'
    real_T Sw18;                       // '<S5>/Sw18'
    real_T Sw17;                       // '<S5>/Sw17'
    real_T Sw16;                       // '<S5>/Sw16'
    real_T Sw15;                       // '<S5>/Sw15'
    real_T Sw14;                       // '<S5>/Sw14'
    real_T Sw13;                       // '<S5>/Sw13'
    real_T RandomNumber;               // '<S5>/Random Number'
    real_T Sw72;                       // '<S5>/Sw72'
    real_T RandomNumber1;              // '<S5>/Random Number1'
    real_T Sw73;                       // '<S5>/Sw73'
    real_T Sw37;                       // '<S5>/Sw37'
    real_T Sw36;                       // '<S5>/Sw36'
    real_T Sw35;                       // '<S5>/Sw35'
    real_T Sw34;                       // '<S5>/Sw34'
    real_T Sw33;                       // '<S5>/Sw33'
    real_T Sw32;                       // '<S5>/Sw32'
    real_T Sw29;                       // '<S5>/Sw29'
    real_T Sw30;                       // '<S5>/Sw30'
    real_T Sw31;                       // '<S5>/Sw31'
    real_T Sw28;                       // '<S5>/Sw28'
    real_T Sw27;                       // '<S5>/Sw27'
    real_T Sw26;                       // '<S5>/Sw26'
    real_T Sw25;                       // '<S5>/Sw25'
    real_T Sw24;                       // '<S5>/Sw24'
    real_T Sw23;                       // '<S5>/Sw23'
    real_T Sw3;                        // '<S5>/Sw3'
    real_T Sw2;                        // '<S5>/Sw2'
    real_T Sw22;                       // '<S5>/Sw22'
    real_T Sw21;                       // '<S5>/Sw21'
    real_T Sw20;                       // '<S5>/Sw20'
    real_T Sw71;                       // '<S5>/Sw71'
    real_T Sw70;                       // '<S5>/Sw70'
    real_T Sw69;                       // '<S5>/Sw69'
    real_T Sw68;                       // '<S5>/Sw68'
    real_T Sw1;                        // '<S5>/Sw1'
    real_T Sw75;                       // '<S5>/Sw75'
    real_T Sw74;                       // '<S5>/Sw74'
    real_T Sw76;                       // '<S5>/Sw76'
    real_T Sw101;                      // '<S5>/Sw101'
    real_T Sw102;                      // '<S5>/Sw102'
    real_T Sw100;                      // '<S5>/Sw100'
    real_T Sw99;                       // '<S5>/Sw99'
    real_T Sw93;                       // '<S5>/Sw93'
    real_T Sw97;                       // '<S5>/Sw97'
    real_T Sw95;                       // '<S5>/Sw95'
    real_T Sw96;                       // '<S5>/Sw96'
    real_T Sw89;                       // '<S5>/Sw89'
    real_T Sw94;                       // '<S5>/Sw94'
    real_T Sw98;                       // '<S5>/Sw98'
    real_T Sw92;                       // '<S5>/Sw92'
    real_T Sw91;                       // '<S5>/Sw91'
    real_T Sw90;                       // '<S5>/Sw90'
    real_T Sw126;                      // '<S5>/Sw126'
    real_T Sw125;                      // '<S5>/Sw125'
    real_T Sw124;                      // '<S5>/Sw124'
    real_T Sw122;                      // '<S5>/Sw122'
    real_T Sw123;                      // '<S5>/Sw123'
    real_T Sw64;                       // '<S5>/Sw64'
    real_T Sw63;                       // '<S5>/Sw63'
    real_T Sw62;                       // '<S5>/Sw62'
    real_T Sw61;                       // '<S5>/Sw61'
    real_T Sw60;                       // '<S5>/Sw60'
    real_T Sw59;                       // '<S5>/Sw59'
    real_T Sw58;                       // '<S5>/Sw58'
    real_T Sw57;                       // '<S5>/Sw57'
    real_T Sw56;                       // '<S5>/Sw56'
    real_T Sw55;                       // '<S5>/Sw55'
    real_T Sw54;                       // '<S5>/Sw54'
    real_T Sw53;                       // '<S5>/Sw53'
    real_T Sw52;                       // '<S5>/Sw52'
    real_T DataTypeConversion8[8];     // '<S5>/Data Type Conversion8'
    real_T enable_oa;                  // '<S5>/normal500'
    real_T enable_o3;                  // '<S5>/normal250_4'
    real_T enable_l;                   // '<S5>/normal250_3'
    real_T enable_i;                   // '<S5>/normal250_2'
    real_T enable_b;                   // '<S5>/normal250_1'
    real_T enable_n;                   // '<S5>/normal250'
    real_T enable_p;                   // '<S37>/sendCyclic9'
    real_T enable_e0;                  // '<S37>/sendCyclic17'
    real_T enable_bk;                  // '<S37>/sendCyclic16'
    real_T enable_kj;                  // '<S37>/sendCyclic15'
    real_T enable_j;                   // '<S37>/sendCyclic14'
    real_T enable_d5;                  // '<S37>/sendCyclic13'
    real_T enable_g2;                  // '<S37>/sendCyclic12'
    real_T enable_lc;                  // '<S37>/sendCyclic11'
    real_T enable_nz;                  // '<S37>/sendCyclic10'
    real_T SEQ_m;                      // '<S5>/MAIN'
    real_T RTS_Enable;                 // '<S5>/J1939_TP.CM_Send'
    real_T TP_Enable;                  // '<S5>/J1939_TP.CM_Send'
    uint32_T LocalVersion;             // '<S6>/VN'
    uint8_T RX_Status;                 // '<S4>/CAN Unpack5'
    uint8_T RX_Status_m;               // '<S4>/CAN Unpack2'
    uint8_T Data[8];                   // '<S4>/CAN Unpack9'
    uint8_T RX_Status_l;               // '<S4>/CAN Unpack9'
    uint8_T RX_Status_mu;              // '<S4>/CAN Unpack8'
    uint8_T RX_Status_n;               // '<S4>/CAN Unpack6'
    uint8_T Data_k[8];                 // '<S4>/CAN Unpack14'
    uint8_T RX_Status_lo;              // '<S4>/CAN Unpack14'
    uint8_T RX_Status_k;               // '<S4>/CAN Unpack7'
    uint8_T RX_Status_a;               // '<S4>/CAN Unpack11'
    uint8_T RX_Status_d;               // '<S4>/CAN Unpack10'
    uint8_T RX_Status_p;               // '<S4>/CAN Unpack4'
    uint8_T RX_Status_c;               // '<S4>/CAN Unpack1'
    uint8_T RX_Status_i;               // '<S4>/CAN Unpack13'
    uint8_T RX_Status_k1;              // '<S4>/CAN Unpack12'
    uint8_T Switch44[12];              // '<S6>/Switch44'
    uint8_T Switch5[8];                // '<S108>/Switch5'
    uint8_T Switch10[8];               // '<S108>/Switch10'
    uint8_T Switch12[8];               // '<S108>/Switch12'
    uint8_T Switch8[8];                // '<S108>/Switch8'
    uint8_T Switch14[8];               // '<S108>/Switch14'
    uint8_T PGI_Enable[255];           // '<S6>/QC2015P_MAIN'
    uint8_T Data_PGI04[8];             // '<S6>/QC2015P_MAIN'
    uint8_T K5;                        // '<S6>/QC2015P_MAIN'
    uint8_T K6;                        // '<S6>/QC2015P_MAIN'
    uint8_T PGI02_check;               // '<S6>/QC2015P_MAIN'
    uint8_T PGI72_EVCCReady;           // '<S6>/QC2015P_MAIN'
    uint8_T PGI91_EVCCDetectSta;       // '<S6>/QC2015P_MAIN'
    uint8_T PGI09_wakeup;              // '<S6>/QC2015P_MAIN'
    uint8_T PGI52_CheckState;          // '<S6>/QC2015P_MAIN'
    uint8_T Switch28[8];               // '<S37>/Switch28'
    uint8_T Switch52_n[8];             // '<S37>/Switch52'
    uint8_T Switch49[8];               // '<S37>/Switch49'
    uint8_T Switch46[8];               // '<S37>/Switch46'
    uint8_T Switch43[8];               // '<S37>/Switch43'
    uint8_T Switch40[8];               // '<S37>/Switch40'
    uint8_T Switch37[8];               // '<S37>/Switch37'
    uint8_T Switch34[8];               // '<S37>/Switch34'
    uint8_T Switch31[8];               // '<S37>/Switch31'
    uint8_T PGN_Enable[255];           // '<S5>/MAIN'
    uint8_T Data_BEM[8];               // '<S5>/MAIN'
    uint8_T SPN2829;                   // '<S5>/MAIN'
    uint8_T ERROR_Type;                // '<S5>/MAIN'
    uint8_T Data_BST[8];               // '<S5>/MAIN'
    uint8_T RTS_Data[8];               // '<S5>/J1939_TP.CM_Send'
    uint8_T TP_Num;                    // '<S5>/J1939_TP.CM_Send'
    B_MAIN_CNT_QC2015P_EVCC_T sf_MAIN_CNT_e;// '<S6>/MAIN_CNT'
    B_MAIN_CNT_QC2015P_EVCC_T sf_MAIN_CNT;// '<S5>/MAIN_CNT'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_QC2015P_EVCC_T {
    real_T Delay1_DSTATE[2];           // '<Root>/Delay1'
    real_T Delay_DSTATE[2];            // '<Root>/Delay'
    real_T UnitDelay1_DSTATE;          // '<S6>/Unit Delay1'
    real_T UnitDelay16_DSTATE;         // '<S6>/Unit Delay16'
    real_T UnitDelay17_DSTATE;         // '<S6>/Unit Delay17'
    real_T UnitDelay12_DSTATE;         // '<S6>/Unit Delay12'
    real_T UnitDelay13_DSTATE;         // '<S6>/Unit Delay13'
    real_T UnitDelay11_DSTATE;         // '<S6>/Unit Delay11'
    real_T UnitDelay15_DSTATE;         // '<S6>/Unit Delay15'
    real_T UnitDelay_DSTATE;           // '<S113>/Unit Delay'
    real_T DiscreteTimeIntegrator1_DSTATE;// '<S113>/Discrete-Time Integrator1'
    real_T UnitDelay6_DSTATE;          // '<S6>/Unit Delay6'
    real_T UnitDelay10_DSTATE;         // '<S6>/Unit Delay10'
    real_T UnitDelay8_DSTATE;          // '<S6>/Unit Delay8'
    real_T UnitDelay15_DSTATE_p;       // '<S5>/Unit Delay15'
    real_T UnitDelay1_DSTATE_l;        // '<S5>/Unit Delay1'
    real_T UnitDelay2_DSTATE;          // '<S5>/Unit Delay2'
    real_T UnitDelay3_DSTATE;          // '<S5>/Unit Delay3'
    real_T UnitDelay5_DSTATE;          // '<S5>/Unit Delay5'
    real_T UnitDelay6_DSTATE_l;        // '<S5>/Unit Delay6'
    real_T UnitDelay7_DSTATE;          // '<S5>/Unit Delay7'
    real_T UnitDelay_DSTATE_j;         // '<S36>/Unit Delay'
    real_T DiscreteTimeIntegrator1_DSTAT_h;// '<S36>/Discrete-Time Integrator1'
    real_T cnt;                        // '<S6>/normal250_3'
    real_T Ns;                         // '<S6>/VN'
    real_T Tout0;                      // '<S6>/VN'
    real_T NextStep;                   // '<S6>/VN'
    real_T timeOut;                    // '<S6>/QC2015P_MAIN'
    real_T timer;                      // '<S6>/QC2015P_MAIN'
    real_T PauseCNT;                   // '<S6>/QC2015P_MAIN'
    real_T T1;                         // '<S6>/QC2015P_MAIN'
    real_T T2;                         // '<S6>/QC2015P_MAIN'
    real_T PGI33_Flg;                  // '<S6>/QC2015P_MAIN'
    real_T cnt_l;                      // '<S108>/sendCyclic5'
    real_T err_cnt;                    // '<S6>/LM_Send'
    real_T LMS_T1;                     // '<S6>/LM_Send'
    real_T local_n;                    // '<S6>/LM_Send'
    real_T LMS_T3;                     // '<S6>/LM_Send'
    real_T LMS_T2;                     // '<S6>/LM_Send'
    real_T local_k;                    // '<S6>/LM_Send'
    real_T send_cnt;                   // '<S6>/LM_Send'
    real_T recv_no;                    // '<S6>/LM_Recv'
    real_T LMS_T2_i;                   // '<S6>/LM_Recv'
    real_T err_cnt_h;                  // '<S6>/LM_Recv'
    real_T LMS_T3_k;                   // '<S6>/LM_Recv'
    real_T lm_tfra;                    // '<S6>/LM_Recv'
    real_T recv_num;                   // '<S6>/LM_Recv'
    real_T totalBytes;                 // '<S6>/AnalysisLM'
    real_T lm_tfra_o;                  // '<S6>/AnalysisLM'
    real_T tmpLists[64];               // '<S6>/AnalysisLM'
    real_T tmpCnt;                     // '<S6>/AnalysisLM'
    real_T NextOutput;                 // '<S5>/Random Number'
    real_T NextOutput_o;               // '<S5>/Random Number1'
    real_T cnt_n;                      // '<S5>/normal500'
    real_T CRO_OverTime;               // '<S5>/MAIN'
    real_T RelinkTimes;                // '<S5>/MAIN'
    real_T CML_OverTime;               // '<S5>/MAIN'
    real_T CCS_OverTime;               // '<S5>/MAIN'
    real_T CRM_NotReady_OverTime;      // '<S5>/MAIN'
    real_T CRM_Ready_OverTime;         // '<S5>/MAIN'
    real_T CST_OverTime;               // '<S5>/MAIN'
    real_T CSD_OverTime;               // '<S5>/MAIN'
    real_T CCS_timer;                  // '<S5>/MAIN'
    real_T CNT;                        // '<S5>/J1939_TP.CM_Send'
    uint32_T RandSeed;                 // '<S5>/Random Number'
    uint32_T RandSeed_m;               // '<S5>/Random Number1'
    int_T CANUnpack5_ModeSignalID;     // '<S4>/CAN Unpack5'
    int_T CANUnpack5_StatusPortID;     // '<S4>/CAN Unpack5'
    int_T CANUnpack2_ModeSignalID;     // '<S4>/CAN Unpack2'
    int_T CANUnpack2_StatusPortID;     // '<S4>/CAN Unpack2'
    int_T CANUnpack9_ModeSignalID;     // '<S4>/CAN Unpack9'
    int_T CANUnpack9_StatusPortID;     // '<S4>/CAN Unpack9'
    int_T CANUnpack8_ModeSignalID;     // '<S4>/CAN Unpack8'
    int_T CANUnpack8_StatusPortID;     // '<S4>/CAN Unpack8'
    int_T CANUnpack6_ModeSignalID;     // '<S4>/CAN Unpack6'
    int_T CANUnpack6_StatusPortID;     // '<S4>/CAN Unpack6'
    int_T CANUnpack14_ModeSignalID;    // '<S4>/CAN Unpack14'
    int_T CANUnpack14_StatusPortID;    // '<S4>/CAN Unpack14'
    int_T CANUnpack7_ModeSignalID;     // '<S4>/CAN Unpack7'
    int_T CANUnpack7_StatusPortID;     // '<S4>/CAN Unpack7'
    int_T CANUnpack11_ModeSignalID;    // '<S4>/CAN Unpack11'
    int_T CANUnpack11_StatusPortID;    // '<S4>/CAN Unpack11'
    int_T CANUnpack10_ModeSignalID;    // '<S4>/CAN Unpack10'
    int_T CANUnpack10_StatusPortID;    // '<S4>/CAN Unpack10'
    int_T CANUnpack4_ModeSignalID;     // '<S4>/CAN Unpack4'
    int_T CANUnpack4_StatusPortID;     // '<S4>/CAN Unpack4'
    int_T CANUnpack1_ModeSignalID;     // '<S4>/CAN Unpack1'
    int_T CANUnpack1_StatusPortID;     // '<S4>/CAN Unpack1'
    int_T CANUnpack13_ModeSignalID;    // '<S4>/CAN Unpack13'
    int_T CANUnpack13_StatusPortID;    // '<S4>/CAN Unpack13'
    int_T CANUnpack12_ModeSignalID;    // '<S4>/CAN Unpack12'
    int_T CANUnpack12_StatusPortID;    // '<S4>/CAN Unpack12'
    int_T CANFDUnpack_ModeSignalID;    // '<S6>/CAN FD Unpack'
    int_T CANFDUnpack_StatusPortID;    // '<S6>/CAN FD Unpack'
    int_T CANFDPack_ModeSignalID;      // '<S6>/CAN FD Pack'
    int_T CANFDPack_ModeSignalID_p;    // '<S5>/CAN FD Pack'
    int_T CANFDPack1_ModeSignalID;     // '<S5>/CAN FD Pack1'
    int_T CANFDPack2_ModeSignalID;     // '<S5>/CAN FD Pack2'
    int_T CANPack18_ModeSignalID;      // '<S5>/CAN Pack18'
    int_T CANPack20_ModeSignalID;      // '<S5>/CAN Pack20'
    int_T CANPack21_ModeSignalID;      // '<S5>/CAN Pack21'
    int_T CANPack25_ModeSignalID;      // '<S5>/CAN Pack25'
    int_T CANPack28_ModeSignalID;      // '<S5>/CAN Pack28'
    int_T CANPack31_ModeSignalID;      // '<S5>/CAN Pack31'
    uint16_T temporalCounter_i1;       // '<S6>/keep1_for10000ms3'
    uint16_T temporalCounter_i1_k;     // '<S6>/QC2015P_MAIN'
    uint16_T temporalCounter_i2;       // '<S6>/QC2015P_MAIN'
    uint16_T temporalCounter_i3;       // '<S6>/QC2015P_MAIN'
    uint16_T temporalCounter_i1_j;     // '<S5>/MAIN'
    uint16_T temporalCounter_i2_d;     // '<S5>/MAIN'
    uint16_T temporalCounter_i3_g;     // '<S5>/J1939_TP.CM_Send'
    uint8_T UnitDelay9_DSTATE[255];    // '<S6>/Unit Delay9'
    uint8_T UnitDelay7_DSTATE_f;       // '<S6>/Unit Delay7'
    uint8_T UnitDelay3_DSTATE_f[8];    // '<S6>/Unit Delay3'
    uint8_T UnitDelay2_DSTATE_p[8];    // '<S6>/Unit Delay2'
    boolean_T UnitDelay_DSTATE_m;      // '<S6>/Unit Delay'
    boolean_T UnitDelay5_DSTATE_c;     // '<S6>/Unit Delay5'
    boolean_T UnitDelay19_DSTATE;      // '<S6>/Unit Delay19'
    int8_T DiscreteTimeIntegrator1_PrevRes;// '<S113>/Discrete-Time Integrator1' 
    int8_T DiscreteTimeIntegrator1_PrevR_a;// '<S36>/Discrete-Time Integrator1'
    uint8_T is_active_c2_QC2015P_EVCC; // '<S6>/normal250_3'
    uint8_T is_c2_QC2015P_EVCC;        // '<S6>/normal250_3'
    uint8_T is_active_c28_QC2015P_EVCC;// '<S6>/keep1_for50ms'
    uint8_T is_c28_QC2015P_EVCC;       // '<S6>/keep1_for50ms'
    uint8_T temporalCounter_i1_m;      // '<S6>/keep1_for50ms'
    uint8_T is_active_c26_QC2015P_EVCC;// '<S6>/keep1_for10ms1'
    uint8_T is_c26_QC2015P_EVCC;       // '<S6>/keep1_for10ms1'
    uint8_T temporalCounter_i1_kr;     // '<S6>/keep1_for10ms1'
    uint8_T is_active_c25_QC2015P_EVCC;// '<S6>/keep1_for10ms'
    uint8_T is_c25_QC2015P_EVCC;       // '<S6>/keep1_for10ms'
    uint8_T temporalCounter_i1_i;      // '<S6>/keep1_for10ms'
    uint8_T is_active_c30_QC2015P_EVCC;// '<S6>/keep1_for10000ms3'
    uint8_T is_c30_QC2015P_EVCC;       // '<S6>/keep1_for10000ms3'
    uint8_T is_active_c9_QC2015P_EVCC; // '<S6>/VN'
    uint8_T is_c9_QC2015P_EVCC;        // '<S6>/VN'
    uint8_T temporalCounter_i1_n;      // '<S6>/VN'
    uint8_T is_active_c10_QC2015P_EVCC;// '<S6>/QC2015P_STOP'
    uint8_T is_c10_QC2015P_EVCC;       // '<S6>/QC2015P_STOP'
    uint8_T is_active_c18_QC2015P_EVCC;// '<S6>/QC2015P_MAIN'
    uint8_T is_c18_QC2015P_EVCC;       // '<S6>/QC2015P_MAIN'
    uint8_T is_QC2015P;                // '<S6>/QC2015P_MAIN'
    uint8_T is_End;                    // '<S6>/QC2015P_MAIN'
    uint8_T is_Checking;               // '<S6>/QC2015P_MAIN'
    uint8_T is_S4;                     // '<S6>/QC2015P_MAIN'
    uint8_T is_Send_PGI91;             // '<S6>/QC2015P_MAIN'
    uint8_T is_FC_Start;               // '<S6>/QC2015P_MAIN'
    uint8_T is_QC2015P_BeforeEnd;      // '<S6>/QC2015P_MAIN'
    uint8_T is_Authentic;              // '<S6>/QC2015P_MAIN'
    uint8_T is_FC_Start_d;             // '<S6>/QC2015P_MAIN'
    uint8_T is_Wait_PGI31_Send_PGI32;  // '<S6>/QC2015P_MAIN'
    uint8_T is_FN;                     // '<S6>/QC2015P_MAIN'
    uint8_T is_FC_Start_f;             // '<S6>/QC2015P_MAIN'
    uint8_T is_OutLoopDete;            // '<S6>/QC2015P_MAIN'
    uint8_T is_FC_Start_p;             // '<S6>/QC2015P_MAIN'
    uint8_T is_ParmCfg;                // '<S6>/QC2015P_MAIN'
    uint8_T is_FC_Start_a;             // '<S6>/QC2015P_MAIN'
    uint8_T is_PreChgEnTrans;          // '<S6>/QC2015P_MAIN'
    uint8_T is_EnTrans;                // '<S6>/QC2015P_MAIN'
    uint8_T is_PreChg;                 // '<S6>/QC2015P_MAIN'
    uint8_T is_ReLink_Reboot;          // '<S6>/QC2015P_MAIN'
    uint8_T is_Rebooting;              // '<S6>/QC2015P_MAIN'
    uint8_T is_active_c23_QC2015P_EVCC;// '<S108>/sendCyclic5'
    uint8_T is_c23_QC2015P_EVCC;       // '<S108>/sendCyclic5'
    uint8_T is_active_c15_QC2015P_EVCC;// '<S6>/LM_Send'
    uint8_T is_c15_QC2015P_EVCC;       // '<S6>/LM_Send'
    uint8_T is_S1_S4;                  // '<S6>/LM_Send'
    uint8_T temporalCounter_i1_m5;     // '<S6>/LM_Send'
    uint8_T is_active_c11_QC2015P_EVCC;// '<S6>/LM_Recv'
    uint8_T is_c11_QC2015P_EVCC;       // '<S6>/LM_Recv'
    uint8_T is_S1;                     // '<S6>/LM_Recv'
    uint8_T temporalCounter_i1_b;      // '<S6>/LM_Recv'
    uint8_T is_active_c42_QC2015P_EVCC;// '<S5>/normal500'
    uint8_T is_c42_QC2015P_EVCC;       // '<S5>/normal500'
    uint8_T is_active_c40_QC2015P_EVCC;// '<S5>/MAIN'
    uint8_T is_c40_QC2015P_EVCC;       // '<S5>/MAIN'
    uint8_T is_Chage_Step;             // '<S5>/MAIN'
    uint8_T is_Send_BCL_BCS_BSM;       // '<S5>/MAIN'
    uint8_T is_Send_BCP;               // '<S5>/MAIN'
    uint8_T is_Send_BRO;               // '<S5>/MAIN'
    uint8_T is_Send_BRO_AA;            // '<S5>/MAIN'
    uint8_T is_Send_BSD;               // '<S5>/MAIN'
    uint8_T is_Send_BST;               // '<S5>/MAIN'
    uint8_T MsgCanBeSend;              // '<S5>/J1939_TP.CM_Send'
    uint8_T is_active_c39_QC2015P_EVCC;// '<S5>/J1939_TP.CM_Send'
    uint8_T is_c39_QC2015P_EVCC;       // '<S5>/J1939_TP.CM_Send'
    uint8_T is_Send;                   // '<S5>/J1939_TP.CM_Send'
    uint8_T is_Send_RTS;               // '<S5>/J1939_TP.CM_Send'
    uint8_T is_Send_TP;                // '<S5>/J1939_TP.CM_Send'
    uint8_T temporalCounter_i1_c;      // '<S5>/J1939_TP.CM_Send'
    uint8_T temporalCounter_i2_b;      // '<S5>/J1939_TP.CM_Send'
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3_;// '<S6>/normal1000_50for3_' 
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3;// '<S6>/normal1000_50for3' 
    DW_normal1000_QC2015P_EVCC_T sf_normal1000_1;// '<S6>/normal1000_1'
    DW_normal1000_QC2015P_EVCC_T sf_normal1000;// '<S6>/normal1000'
    DW_keep50ms1_QC2015P_EVCC_T sf_keep50ms2;// '<S6>/keep50ms2'
    DW_keep50ms1_QC2015P_EVCC_T sf_keep50ms1;// '<S6>/keep50ms1'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic4;// '<S108>/sendCyclic4'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic3;// '<S108>/sendCyclic3'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic2;// '<S108>/sendCyclic2'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic1;// '<S108>/sendCyclic1'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic;// '<S108>/sendCyclic'
    DW_MAIN_CNT_QC2015P_EVCC_T sf_MAIN_CNT_e;// '<S6>/MAIN_CNT'
    DW_normal250_QC2015P_EVCC_T sf_normal250_4;// '<S5>/normal250_4'
    DW_normal250_QC2015P_EVCC_T sf_normal250_3;// '<S5>/normal250_3'
    DW_normal250_QC2015P_EVCC_T sf_normal250_2;// '<S5>/normal250_2'
    DW_normal250_QC2015P_EVCC_T sf_normal250_1;// '<S5>/normal250_1'
    DW_normal250_QC2015P_EVCC_T sf_normal250;// '<S5>/normal250'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic9;// '<S37>/sendCyclic9'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic17;// '<S37>/sendCyclic17'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic16;// '<S37>/sendCyclic16'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic15;// '<S37>/sendCyclic15'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic14;// '<S37>/sendCyclic14'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic13;// '<S37>/sendCyclic13'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic12;// '<S37>/sendCyclic12'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic11;// '<S37>/sendCyclic11'
    DW_sendCyclic10_QC2015P_EVCC_T sf_sendCyclic10;// '<S37>/sendCyclic10'
    DW_MAIN_CNT_QC2015P_EVCC_T sf_MAIN_CNT;// '<S5>/MAIN_CNT'
  };

  // Invariant block signals (default storage)
  struct ConstB_QC2015P_EVCC_T {
    real_T DataTypeConversion;         // '<S5>/Data Type Conversion'
  };

  // Constant parameters (default storage)
  struct ConstP_QC2015P_EVCC_T {
    // Expression: [2, 255, 255, 255, 255, 255, 255, 255]
    //  Referenced by: '<S6>/LM_NACK'

    real_T LM_NACK_Value[8];

    // Expression: [0,1,3,0xFF,0xFF,0xFF,0xFF,0xFF]
    //  Referenced by: '<S6>/Constant50'

    uint8_T Constant50_Value_f[8];

    // Expression: [4,1,3,2,0xFF,0xFF,0xFF,0xFF]
    //  Referenced by: '<S6>/Constant64'

    uint8_T Constant64_Value[8];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_QC2015P_EVCC_T {
    CAN_MSG_Array MsgInput;            // '<Root>/MsgInput'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_QC2015P_EVCC_T {
    CAN_MESSAGE_BUS Msg_Send[15];      // '<Root>/Msg_Send'
    UserMonitor_EVCC UserMonitor_EVCC_h;// '<Root>/UserMonitor_EVCC'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_QC2015P_EVCC_T {
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
  QC2015P_EVCC(QC2015P_EVCC const&) = delete;

  // Assignment Operator
  QC2015P_EVCC& operator= (QC2015P_EVCC const&) & = delete;

  // Move Constructor
  QC2015P_EVCC(QC2015P_EVCC &&) = delete;

  // Move Assignment Operator
  QC2015P_EVCC& operator= (QC2015P_EVCC &&) = delete;

  // Real-Time Model get method
  QC2015P_EVCC::RT_MODEL_QC2015P_EVCC_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_QC2015P_EVCC_T *pExtU_QC2015P_EVCC_T)
  {
    QC2015P_EVCC_U = *pExtU_QC2015P_EVCC_T;
  }

  // Root outports get method
  const ExtY_QC2015P_EVCC_T &getExternalOutputs() const
  {
    return QC2015P_EVCC_Y;
  }

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  QC2015P_EVCC();

  // Destructor
  ~QC2015P_EVCC();

  // private data and function members
 private:
  // External inputs
  ExtU_QC2015P_EVCC_T QC2015P_EVCC_U;

  // External outputs
  ExtY_QC2015P_EVCC_T QC2015P_EVCC_Y;

  // Block signals
  B_QC2015P_EVCC_T QC2015P_EVCC_B;

  // Block states
  DW_QC2015P_EVCC_T QC2015P_EVCC_DW;

  // private member function(s) for subsystem '<S5>/MAIN_CNT'
  void QC2015P_EVCC_MAIN_CNT(boolean_T rtu_startFlg, B_MAIN_CNT_QC2015P_EVCC_T
    *localB, DW_MAIN_CNT_QC2015P_EVCC_T *localDW);
  void QC2015P_EVCC_enter_atomic_init(B_MAIN_CNT_QC2015P_EVCC_T *localB,
    DW_MAIN_CNT_QC2015P_EVCC_T *localDW);
  real_T QC2015P_EVCC_mod(real_T x);
  real_T QC2015P_EVCC_mod_l(real_T x);

  // private member function(s) for subsystem '<S37>/sendCyclic10'
  static void QC2015P_EVCC_sendCyclic10_Init(real_T *rty_enable);
  static void QC2015P_EVCC_sendCyclic10(boolean_T rtu_startFlg, real_T
    rtu_cycleTime, real_T *rty_enable, DW_sendCyclic10_QC2015P_EVCC_T *localDW);

  // private member function(s) for subsystem '<S5>/normal250'
  static void QC2015P_EVCC_normal250_Init(real_T *rty_enable);
  static void QC2015P_EVCC_normal250(boolean_T rtu_rawCycle, real_T *rty_enable,
    DW_normal250_QC2015P_EVCC_T *localDW);

  // private member function(s) for subsystem '<S6>/Bit Shift10'
  static void QC2015P_EVCC_BitShift10(uint16_T rtu_u, uint16_T *rty_y);

  // private member function(s) for subsystem '<S6>/keep50ms1'
  static void QC2015P_EVCC_keep50ms1_Init(real_T *rty_out);
  static void QC2015P_EVCC_keep50ms1(boolean_T rtu_rawIn, real_T *rty_out,
    DW_keep50ms1_QC2015P_EVCC_T *localDW);

  // private member function(s) for subsystem '<S6>/normal1000'
  static void QC2015P_EVCC_normal1000_Init(real_T *rty_enable);
  static void QC2015P_EVCC_normal1000(boolean_T rtu_rawCycle, real_T *rty_enable,
    DW_normal1000_QC2015P_EVCC_T *localDW);

  // private member function(s) for subsystem '<S6>/normal1000_50for3'
  static void QC2015P__normal1000_50for3_Init(real_T *rty_enable);
  static void QC2015P_EVCC_normal1000_50for3(boolean_T rtu_rawCycle, boolean_T
    rtu_startFlg, real_T *rty_enable, DW_normal1000_50for3_QC2015P__T *localDW);

  // private member function(s) for subsystem '<Root>'
  void QC2015P_EVCC_Checking(const boolean_T *LogicalOperator34);
  void QC2015P_EVCC_exit_internal_End(void);
  void QC2015P_EVCC_Authentic(const boolean_T *LogicalOperator34, const uint8_T *
    Switch11);
  void QC2015P_EVCC_OutLoopDete(const boolean_T *LogicalOperator34, const real_T
    *Switch45);
  void QC2015P_EVCC_ParmCfg(const boolean_T *LogicalOperator34, const real_T
    *Switch7);
  void QC2015P_EVCC_PreChgEnTrans(const boolean_T *LogicalOperator34);
  void exit_internal_QC2015P_BeforeEnd(void);
  void QC2015P_EVCC_QC2015P_BeforeEnd(const boolean_T *LogicalOperator34, const
    real_T *Switch52, const real_T *Switch7, const uint8_T *Switch11, const
    real_T *Switch45, const uint8_T Transpose1[8]);
  void QC2015P_EVCC_ReLink_Reboot(const boolean_T *LogicalOperator34, const
    real_T *out);
  void QC2015P_E_exit_internal_QC2015P(void);
  void QC2015P_EVC_enter_atomic_init_a(void);
  void enter_atomic_S0_init_or_S2_fini(void);
  void QC2015P_EVCC_S1(const real_T DataTypeConversion5[8], const boolean_T
                       *LogicalOperator4, const real_T *DataTypeConversion40);
  void QC2015P_EV_enter_atomic_init_S0(void);
  void QC2015_exit_internal_Chage_Step(void);
  void QC2015P_E_enter_atomic_Send_BEM(void);
  void QC2015P_EVCC_Chage_Step(void);
  void QC2015P_EVCC_Send_BEM(void);
  void QC2015P_EVC_enter_atomic_init_k(void);
  void QC2015P_enter_internal_Send_RTS(const real_T *Switch1, const real_T
    *Switch, const uint8_T *Switch3_d);

  // Real-Time Model
  RT_MODEL_QC2015P_EVCC_T QC2015P_EVCC_M;
};

extern const QC2015P_EVCC::ConstB_QC2015P_EVCC_T QC2015P_EVCC_ConstB;// constant block i/o 

// Constant parameters (default storage)
extern const QC2015P_EVCC::ConstP_QC2015P_EVCC_T QC2015P_EVCC_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S4>/CAN Unpack3' : Unused code path elimination
//  Block '<S4>/Constant6' : Unused code path elimination
//  Block '<S18>/Equal1' : Unused code path elimination
//  Block '<S18>/Equal2' : Unused code path elimination
//  Block '<S18>/Equal3' : Unused code path elimination
//  Block '<S18>/Equal4' : Unused code path elimination
//  Block '<S18>/Switch1' : Unused code path elimination
//  Block '<S18>/Switch2' : Unused code path elimination
//  Block '<S18>/Switch3' : Unused code path elimination
//  Block '<S18>/Switch4' : Unused code path elimination
//  Block '<S6>/Constant26' : Unused code path elimination
//  Block '<S6>/Constant28' : Unused code path elimination
//  Block '<S6>/Constant29' : Unused code path elimination
//  Block '<S6>/Constant32' : Unused code path elimination
//  Block '<S6>/Constant33' : Unused code path elimination
//  Block '<S6>/Constant36' : Unused code path elimination
//  Block '<S6>/Constant37' : Unused code path elimination
//  Block '<S6>/Constant63' : Unused code path elimination
//  Block '<S6>/Min of Elements3' : Unused code path elimination
//  Block '<S6>/Selector14' : Unused code path elimination
//  Block '<S6>/Selector20' : Unused code path elimination
//  Block '<S6>/Selector21' : Unused code path elimination
//  Block '<S6>/Selector23' : Unused code path elimination
//  Block '<S6>/Selector25' : Unused code path elimination
//  Block '<S6>/Selector26' : Unused code path elimination
//  Block '<S6>/Selector27' : Unused code path elimination
//  Block '<S6>/Switch51' : Unused code path elimination
//  Block '<S6>/Unit Delay14' : Unused code path elimination
//  Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<Root>/Data Type Conversion4' : Eliminate redundant data type conversion
//  Block '<S5>/Data Type Conversion5' : Eliminate redundant data type conversion
//  Block '<S6>/Data Type Conversion7' : Eliminate redundant data type conversion


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
//  '<Root>' : 'QC2015P_EVCC'
//  '<S1>'   : 'QC2015P_EVCC/Compare To Constant1'
//  '<S2>'   : 'QC2015P_EVCC/Compare To Constant10'
//  '<S3>'   : 'QC2015P_EVCC/Compare To Constant24'
//  '<S4>'   : 'QC2015P_EVCC/Msg_Recv'
//  '<S5>'   : 'QC2015P_EVCC/QC2015'
//  '<S6>'   : 'QC2015P_EVCC/QC2015P'
//  '<S7>'   : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag'
//  '<S8>'   : 'QC2015P_EVCC/Msg_Recv/MsgSelect'
//  '<S9>'   : 'QC2015P_EVCC/Msg_Recv/MsgSelect1'
//  '<S10>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect10'
//  '<S11>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect11'
//  '<S12>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect12'
//  '<S13>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect13'
//  '<S14>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect2'
//  '<S15>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect3'
//  '<S16>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect4'
//  '<S17>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect5'
//  '<S18>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect6'
//  '<S19>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect7'
//  '<S20>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect8'
//  '<S21>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect9'
//  '<S22>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant'
//  '<S23>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant1'
//  '<S24>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant2'
//  '<S25>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant3'
//  '<S26>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant4'
//  '<S27>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant5'
//  '<S28>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant6'
//  '<S29>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant7'
//  '<S30>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant8'
//  '<S31>'  : 'QC2015P_EVCC/Msg_Recv/CHM_CRM_Flag/Compare To Constant9'
//  '<S32>'  : 'QC2015P_EVCC/QC2015/J1939_TP.CM_PACK'
//  '<S33>'  : 'QC2015P_EVCC/QC2015/J1939_TP.CM_Send'
//  '<S34>'  : 'QC2015P_EVCC/QC2015/MAIN'
//  '<S35>'  : 'QC2015P_EVCC/QC2015/MAIN_CNT'
//  '<S36>'  : 'QC2015P_EVCC/QC2015/SOC1'
//  '<S37>'  : 'QC2015P_EVCC/QC2015/Subsystem'
//  '<S38>'  : 'QC2015P_EVCC/QC2015/normal250'
//  '<S39>'  : 'QC2015P_EVCC/QC2015/normal250_1'
//  '<S40>'  : 'QC2015P_EVCC/QC2015/normal250_2'
//  '<S41>'  : 'QC2015P_EVCC/QC2015/normal250_3'
//  '<S42>'  : 'QC2015P_EVCC/QC2015/normal250_4'
//  '<S43>'  : 'QC2015P_EVCC/QC2015/normal500'
//  '<S44>'  : 'QC2015P_EVCC/QC2015/Subsystem/sendCyclic10'
//  '<S45>'  : 'QC2015P_EVCC/QC2015/Subsystem/sendCyclic11'
//  '<S46>'  : 'QC2015P_EVCC/QC2015/Subsystem/sendCyclic12'
//  '<S47>'  : 'QC2015P_EVCC/QC2015/Subsystem/sendCyclic13'
//  '<S48>'  : 'QC2015P_EVCC/QC2015/Subsystem/sendCyclic14'
//  '<S49>'  : 'QC2015P_EVCC/QC2015/Subsystem/sendCyclic15'
//  '<S50>'  : 'QC2015P_EVCC/QC2015/Subsystem/sendCyclic16'
//  '<S51>'  : 'QC2015P_EVCC/QC2015/Subsystem/sendCyclic17'
//  '<S52>'  : 'QC2015P_EVCC/QC2015/Subsystem/sendCyclic9'
//  '<S53>'  : 'QC2015P_EVCC/QC2015P/AnalysisLM'
//  '<S54>'  : 'QC2015P_EVCC/QC2015P/Bit Shift'
//  '<S55>'  : 'QC2015P_EVCC/QC2015P/Bit Shift1'
//  '<S56>'  : 'QC2015P_EVCC/QC2015P/Bit Shift10'
//  '<S57>'  : 'QC2015P_EVCC/QC2015P/Bit Shift11'
//  '<S58>'  : 'QC2015P_EVCC/QC2015P/Bit Shift2'
//  '<S59>'  : 'QC2015P_EVCC/QC2015P/Bit Shift3'
//  '<S60>'  : 'QC2015P_EVCC/QC2015P/Bit Shift4'
//  '<S61>'  : 'QC2015P_EVCC/QC2015P/Bit Shift5'
//  '<S62>'  : 'QC2015P_EVCC/QC2015P/Bit Shift6'
//  '<S63>'  : 'QC2015P_EVCC/QC2015P/Bit Shift7'
//  '<S64>'  : 'QC2015P_EVCC/QC2015P/Bit Shift8'
//  '<S65>'  : 'QC2015P_EVCC/QC2015P/Bit Shift9'
//  '<S66>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant'
//  '<S67>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant1'
//  '<S68>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant11'
//  '<S69>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant12'
//  '<S70>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant13'
//  '<S71>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant14'
//  '<S72>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant15'
//  '<S73>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant16'
//  '<S74>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant17'
//  '<S75>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant18'
//  '<S76>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant19'
//  '<S77>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant2'
//  '<S78>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant20'
//  '<S79>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant21'
//  '<S80>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant22'
//  '<S81>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant23'
//  '<S82>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant27'
//  '<S83>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant28'
//  '<S84>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant29'
//  '<S85>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant3'
//  '<S86>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant30'
//  '<S87>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant31'
//  '<S88>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant32'
//  '<S89>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant33'
//  '<S90>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant34'
//  '<S91>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant35'
//  '<S92>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant36'
//  '<S93>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant37'
//  '<S94>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant38'
//  '<S95>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant39'
//  '<S96>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant4'
//  '<S97>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant41'
//  '<S98>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant5'
//  '<S99>'  : 'QC2015P_EVCC/QC2015P/Compare To Constant6'
//  '<S100>' : 'QC2015P_EVCC/QC2015P/Compare To Constant7'
//  '<S101>' : 'QC2015P_EVCC/QC2015P/Compare To Constant8'
//  '<S102>' : 'QC2015P_EVCC/QC2015P/Compare To Constant9'
//  '<S103>' : 'QC2015P_EVCC/QC2015P/LM_Recv'
//  '<S104>' : 'QC2015P_EVCC/QC2015P/LM_Send'
//  '<S105>' : 'QC2015P_EVCC/QC2015P/MAIN_CNT'
//  '<S106>' : 'QC2015P_EVCC/QC2015P/MATLAB Function'
//  '<S107>' : 'QC2015P_EVCC/QC2015P/MATLAB Function1'
//  '<S108>' : 'QC2015P_EVCC/QC2015P/MsgSend'
//  '<S109>' : 'QC2015P_EVCC/QC2015P/PACK_LM'
//  '<S110>' : 'QC2015P_EVCC/QC2015P/Pack_LM_ACK'
//  '<S111>' : 'QC2015P_EVCC/QC2015P/QC2015P_MAIN'
//  '<S112>' : 'QC2015P_EVCC/QC2015P/QC2015P_STOP'
//  '<S113>' : 'QC2015P_EVCC/QC2015P/SOC'
//  '<S114>' : 'QC2015P_EVCC/QC2015P/VN'
//  '<S115>' : 'QC2015P_EVCC/QC2015P/get_lm_tfra'
//  '<S116>' : 'QC2015P_EVCC/QC2015P/keep1_for10000ms3'
//  '<S117>' : 'QC2015P_EVCC/QC2015P/keep1_for10ms'
//  '<S118>' : 'QC2015P_EVCC/QC2015P/keep1_for10ms1'
//  '<S119>' : 'QC2015P_EVCC/QC2015P/keep1_for50ms'
//  '<S120>' : 'QC2015P_EVCC/QC2015P/keep50ms1'
//  '<S121>' : 'QC2015P_EVCC/QC2015P/keep50ms2'
//  '<S122>' : 'QC2015P_EVCC/QC2015P/normal1000'
//  '<S123>' : 'QC2015P_EVCC/QC2015P/normal1000_1'
//  '<S124>' : 'QC2015P_EVCC/QC2015P/normal1000_50for3'
//  '<S125>' : 'QC2015P_EVCC/QC2015P/normal1000_50for3_'
//  '<S126>' : 'QC2015P_EVCC/QC2015P/normal250_3'
//  '<S127>' : 'QC2015P_EVCC/QC2015P/Bit Shift/bit_shift'
//  '<S128>' : 'QC2015P_EVCC/QC2015P/Bit Shift1/bit_shift'
//  '<S129>' : 'QC2015P_EVCC/QC2015P/Bit Shift10/bit_shift'
//  '<S130>' : 'QC2015P_EVCC/QC2015P/Bit Shift11/bit_shift'
//  '<S131>' : 'QC2015P_EVCC/QC2015P/Bit Shift2/bit_shift'
//  '<S132>' : 'QC2015P_EVCC/QC2015P/Bit Shift3/bit_shift'
//  '<S133>' : 'QC2015P_EVCC/QC2015P/Bit Shift4/bit_shift'
//  '<S134>' : 'QC2015P_EVCC/QC2015P/Bit Shift5/bit_shift'
//  '<S135>' : 'QC2015P_EVCC/QC2015P/Bit Shift6/bit_shift'
//  '<S136>' : 'QC2015P_EVCC/QC2015P/Bit Shift7/bit_shift'
//  '<S137>' : 'QC2015P_EVCC/QC2015P/Bit Shift8/bit_shift'
//  '<S138>' : 'QC2015P_EVCC/QC2015P/Bit Shift9/bit_shift'
//  '<S139>' : 'QC2015P_EVCC/QC2015P/MsgSend/sendCyclic'
//  '<S140>' : 'QC2015P_EVCC/QC2015P/MsgSend/sendCyclic1'
//  '<S141>' : 'QC2015P_EVCC/QC2015P/MsgSend/sendCyclic2'
//  '<S142>' : 'QC2015P_EVCC/QC2015P/MsgSend/sendCyclic3'
//  '<S143>' : 'QC2015P_EVCC/QC2015P/MsgSend/sendCyclic4'
//  '<S144>' : 'QC2015P_EVCC/QC2015P/MsgSend/sendCyclic5'

#endif                                 // RTW_HEADER_QC2015P_EVCC_h_

//
// File trailer for generated code.
//
// [EOF]
//
