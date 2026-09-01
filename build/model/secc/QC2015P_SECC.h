//
// File: QC2015P_SECC.h
//
// Code generated for Simulink model 'QC2015P_SECC'.
//
// Model version                  : 1.406
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Aug 29 16:43:03 2026
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
  real_T CONTROL_SECC_Cycle_Va; // Referenced by: '<S52>/CONTROL_SECC_Cycle_Va'
  real_T LM_SECC_Cycle_Va;           // Referenced by: '<S52>/LM_SECC_Cycle_Va'
  real_T PGI21_A_Max;                  // Referenced by: '<Root>/PGI21_A_Max'
  real_T PGI21_A_Min;                  // Referenced by: '<Root>/PGI21_A_Min'
  real_T PGI21_V_Max;                  // Referenced by: '<Root>/PGI21_V_Max'
  real_T PGI21_V_Min;                  // Referenced by: '<Root>/PGI21_V_Min'
  real_T PGI75_MaxOutput_A_Va;  // Referenced by: '<Root>/PGI75_MaxOutput_A_Va'
  real_T PGI76_A_Exe_Va;              // Referenced by: '<Root>/PGI76_A_Exe_Va'
  real_T PGI76_V_Exe_Va;              // Referenced by: '<Root>/PGI76_V_Exe_Va'
  real_T PGI93_ChargeCapacity_Va;
                             // Referenced by: '<Root>/PGI93_ChargeCapacity_Va'
  real_T PGI93_DishargeCapacity_Va;
                           // Referenced by: '<Root>/PGI93_DishargeCapacity_Va'
  real_T SM_RM_SECC_Cycle_Va;     // Referenced by: '<S52>/SM_RM_SECC_Cycle_Va'
  real_T SM_URM_SECC_Cycle_Va;   // Referenced by: '<S52>/SM_URM_SECC_Cycle_Va'
  real_T VC_SECC_Cycle_Va;           // Referenced by: '<S52>/VC_SECC_Cycle_Va'
  boolean_T Authen_Pass;               // Referenced by: '<Root>/Authen_Pass'
  boolean_T CONTROL_SECC_Data_SW;// Referenced by: '<S52>/CONTROL_SECC_Data_SW'
  boolean_T CONTROL_SECC_Enable_SW;
                               // Referenced by: '<S52>/CONTROL_SECC_Enable_SW'
  boolean_T CONTROL_SECC_Enable_Va;
                               // Referenced by: '<S52>/CONTROL_SECC_Enable_Va'
  boolean_T Card;                      // Referenced by: '<Root>/Card'
  boolean_T EVCC_LM_ManualSTOP;   // Referenced by: '<Root>/EVCC_LM_ManualSTOP'
  boolean_T LM_SECC_Data_SW;          // Referenced by: '<S52>/LM_SECC_Data_SW'
  boolean_T LM_SECC_Enable_SW;      // Referenced by: '<S52>/LM_SECC_Enable_SW'
  boolean_T LM_SECC_Enable_Va;      // Referenced by: '<S52>/LM_SECC_Enable_Va'
  boolean_T PGI05_K1_SW;               // Referenced by: '<Root>/PGI05_K1_SW'
  boolean_T PGI05_K2_SW;               // Referenced by: '<Root>/PGI05_K2_SW'
  boolean_T PGI07_ELock_SW;           // Referenced by: '<Root>/PGI07_ELock_SW'
  boolean_T PGI08_wakeup_SW;         // Referenced by: '<Root>/PGI08_wakeup_SW'
  boolean_T PGI31_CAuthenStatus_SW;
                              // Referenced by: '<Root>/PGI31_CAuthenStatus_SW'
  boolean_T PGI33_AuthenResult_SW;
                               // Referenced by: '<Root>/PGI33_AuthenResult_SW'
  boolean_T PGI33_SAuthenFDC_SW; // Referenced by: '<Root>/PGI33_SAuthenFDC_SW'
  boolean_T PGI51_Data_SW;             // Referenced by: '<Root>/PGI51_Data_SW'
  boolean_T PGI71_ChargerReady_SW;
                               // Referenced by: '<Root>/PGI71_ChargerReady_SW'
  boolean_T PGI75_MaxOutput_A_SW;
                                // Referenced by: '<Root>/PGI75_MaxOutput_A_SW'
  boolean_T PGI75_OutputChangeReason_SW;
                         // Referenced by: '<Root>/PGI75_OutputChangeReason_SW'
  boolean_T PGI76_A_Exe_SW;           // Referenced by: '<Root>/PGI76_A_Exe_SW'
  boolean_T PGI76_V_Exe_SW;           // Referenced by: '<Root>/PGI76_V_Exe_SW'
  boolean_T PGI78_Pause_SW;           // Referenced by: '<Root>/PGI78_Pause_SW'
  boolean_T PGI92_AllowDetectCheck_SW;
                           // Referenced by: '<Root>/PGI92_AllowDetectCheck_SW'
  boolean_T PGI93_ChargeCapacity_SW;
                             // Referenced by: '<Root>/PGI93_ChargeCapacity_SW'
  boolean_T PGI93_DishargeCapacity_SW;
                           // Referenced by: '<Root>/PGI93_DishargeCapacity_SW'
  boolean_T SECC_ChargeSta;           // Referenced by: '<Root>/SECC_ChargeSta'
  boolean_T SECC_DiagSW;               // Referenced by: '<Root>/SECC_DiagSW'
  boolean_T SECC_ManualSTOP;         // Referenced by: '<Root>/SECC_ManualSTOP'
  boolean_T SECC_Pause;                // Referenced by: '<Root>/Constant53'
  boolean_T SECC_ProtocolVersion_SW;
                             // Referenced by: '<Root>/SECC_ProtocolVersion_SW'
  boolean_T SECC_Reboot;               // Referenced by: '<Root>/SECC_Reboot'
  boolean_T SECC_Relink;               // Referenced by: '<Root>/SECC_Relink'
  boolean_T SECC_VersionResult_SW;
                               // Referenced by: '<Root>/SECC_VersionResult_SW'
  boolean_T SM_RM_SECC_Data_SW;    // Referenced by: '<S52>/SM_RM_SECC_Data_SW'
  boolean_T SM_RM_SECC_Enable_SW;// Referenced by: '<S52>/SM_RM_SECC_Enable_SW'
  boolean_T SM_RM_SECC_Enable_Va;// Referenced by: '<S52>/SM_RM_SECC_Enable_Va'
  boolean_T SM_URM_SECC_Data_SW;  // Referenced by: '<S52>/SM_URM_SECC_Data_SW'
  boolean_T SM_URM_SECC_Enable_SW;
                                // Referenced by: '<S52>/SM_URM_SECC_Enable_SW'
  boolean_T SM_URM_SECC_Enable_Va;
                                // Referenced by: '<S52>/SM_URM_SECC_Enable_Va'
  boolean_T VC_SECC_Data_SW;          // Referenced by: '<S52>/VC_SECC_Data_SW'
  boolean_T VC_SECC_Enable_SW;      // Referenced by: '<S52>/VC_SECC_Enable_SW'
  boolean_T VC_SECC_Enable_Va;      // Referenced by: '<S52>/VC_SECC_Enable_Va'
  uint16_T PGI01_FCFDC_20;            // Referenced by: '<Root>/PGI01_FCFDC_20'
  uint16_T PGI01_FCFDC_30;            // Referenced by: '<Root>/PGI01_FCFDC_30'
  uint16_T PGI01_FCFDC_40;            // Referenced by: '<Root>/PGI01_FCFDC_40'
  uint16_T PGI01_FCFDC_50;            // Referenced by: '<Root>/PGI01_FCFDC_50'
  uint16_T PGI01_FCFDC_60;            // Referenced by: '<Root>/PGI01_FCFDC_60'
  uint16_T PGI01_FCFDC_70;            // Referenced by: '<Root>/PGI01_FCFDC_70'
  uint16_T PGI01_FCFDC_80;            // Referenced by: '<Root>/PGI01_FCFDC_80'
  uint32_T SECC_CVList[4];             // Referenced by: '<Root>/CvList'
  uint32_T SECC_ProtocolVersion_Va;
                             // Referenced by: '<Root>/SECC_ProtocolVersion_Va'
  uint8_T CONTROL_SECC_Data_Va[8];
                                 // Referenced by: '<S52>/CONTROL_SECC_Data_Va'
  uint8_T LM_SECC_Data_Va[8];         // Referenced by: '<S52>/LM_SECC_Data_Va'
  uint8_T PGI01;                       // Referenced by: '<Root>/PGI01'
  uint8_T PGI03_Data[8];               // Referenced by: '<Root>/PGI03_Data'
  uint8_T PGI05;                       // Referenced by: '<Root>/PGI05'
  uint8_T PGI05_K1_Va;                 // Referenced by: '<Root>/PGI05_K1_Va'
  uint8_T PGI05_K2_Va;                 // Referenced by: '<Root>/PGI05_K2_Va'
  uint8_T PGI07;                       // Referenced by: '<Root>/PGI07'
  uint8_T PGI07_ELock_Va;             // Referenced by: '<Root>/PGI07_ELock_Va'
  uint8_T PGI08;                       // Referenced by: '<Root>/PGI08'
  uint8_T PGI08_wakeup_Va;           // Referenced by: '<Root>/PGI08_wakeup_Va'
  uint8_T PGI11;                       // Referenced by: '<Root>/PGI11'
  uint8_T PGI11_Authentic[8];        // Referenced by: '<Root>/PGI11_Authentic'
  uint8_T PGI11_EndOfCharge[8];    // Referenced by: '<Root>/PGI11_EndOfCharge'
  uint8_T PGI11_OutLoopDete[8];    // Referenced by: '<Root>/PGI11_OutLoopDete'
  uint8_T PGI11_ParmCfg[8];            // Referenced by: '<Root>/PGI11_ParmCfg'
  uint8_T PGI11_PowerMode[8];        // Referenced by: '<Root>/PGI11_PowerMode'
  uint8_T PGI11_PreChgEnTrans[8];// Referenced by: '<Root>/PGI11_PreChgEnTrans'
  uint8_T PGI11_Scheduled[8];        // Referenced by: '<Root>/PGI11_Scheduled'
  uint8_T PGI21;                       // Referenced by: '<Root>/PGI21'
  uint8_T PGI21_RebotTimes;         // Referenced by: '<Root>/PGI21_RebotTimes'
  uint8_T PGI31;                       // Referenced by: '<Root>/PGI31'
  uint8_T PGI31_CAuthenStatus_Va;
                              // Referenced by: '<Root>/PGI31_CAuthenStatus_Va'
  uint8_T PGI31_MTime2;                // Referenced by: '<Root>/PGI31_MTime2'
  uint8_T PGI33;                       // Referenced by: '<Root>/PGI33'
  uint8_T PGI33_AuthenResult_Va;
                               // Referenced by: '<Root>/PGI33_AuthenResult_Va'
  uint8_T PGI33_SAuthenFDC_Va;   // Referenced by: '<Root>/PGI33_SAuthenFDC_Va'
  uint8_T PGI51_Data_Va[8];            // Referenced by: '<Root>/PGI51_Data_Va'
  uint8_T PGI71;                       // Referenced by: '<Root>/PGI71'
  uint8_T PGI71_ChargerReady_Va;
                               // Referenced by: '<Root>/PGI71_ChargerReady_Va'
  uint8_T PGI75;                       // Referenced by: '<Root>/PGI75'
  uint8_T PGI75_OutputChangeReason_Va;
                         // Referenced by: '<Root>/PGI75_OutputChangeReason_Va'
  uint8_T PGI76;                       // Referenced by: '<Root>/PGI76'
  uint8_T PGI78;                       // Referenced by: '<Root>/PGI78'
  uint8_T PGI78_Pause_Va;             // Referenced by: '<Root>/PGI78_Pause_Va'
  uint8_T PGI92;                       // Referenced by: '<Root>/PGI922'
  uint8_T PGI92_AllowDetectCheck_Va;
                           // Referenced by: '<Root>/PGI92_AllowDetectCheck_Va'
  uint8_T PGI93;                       // Referenced by: '<Root>/PGI93'
  uint8_T SECC_CANType;                // Referenced by: '<Root>/SECC_CANType'
  uint8_T SECC_CPVersion;             // Referenced by: '<Root>/SECC_CPVersion'
  uint8_T SECC_K_Limit;                // Referenced by: '<Root>/SECC_K_Limit'
  uint8_T SECC_Reserved_VN;         // Referenced by: '<Root>/SECC_Reserved_VN'
  uint8_T SECC_TLVersion;             // Referenced by: '<Root>/SECC_TLVersion'
  uint8_T SECC_VersionResult_Va;
                               // Referenced by: '<Root>/SECC_VersionResult_Va'
  uint8_T SM_RM_SECC_Data_Va[8];   // Referenced by: '<S52>/SM_RM_SECC_Data_Va'
  uint8_T SM_URM_SECC_Data_Va[8]; // Referenced by: '<S52>/SM_URM_SECC_Data_Va'
  uint8_T VC_SECC_Data_Va[8];         // Referenced by: '<S52>/VC_SECC_Data_Va'
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
  // Block states (default storage) for system '<S52>/sendCyclic'
  struct DW_sendCyclic_QC2015P_SECC_T {
    real_T cnt;                        // '<S52>/sendCyclic'
    uint8_T is_active_c4_QC2015P_SECC; // '<S52>/sendCyclic'
    uint8_T is_c4_QC2015P_SECC;        // '<S52>/sendCyclic'
  };

  // Block states (default storage) for system '<Root>/normal1000_50for3'
  struct DW_normal1000_50for3_QC2015P__T {
    real_T times;                      // '<Root>/normal1000_50for3'
    real_T cnt;                        // '<Root>/normal1000_50for3'
    uint8_T is_active_c1_QC2015P_SECC; // '<Root>/normal1000_50for3'
    uint8_T is_c1_QC2015P_SECC;        // '<Root>/normal1000_50for3'
  };

  // Block states (default storage) for system '<Root>/normal250_'
  struct DW_normal250__QC2015P_SECC_T {
    real_T cnt;                        // '<Root>/normal250_'
    uint8_T is_active_c2_QC2015P_SECC; // '<Root>/normal250_'
    uint8_T is_c2_QC2015P_SECC;        // '<Root>/normal250_'
  };

  // Block signals (default storage)
  struct B_QC2015P_SECC_T {
    CAN_FD_MESSAGE_BUS CANFDPack1;     // '<Root>/CAN FD Pack1'
    CAN_FD_MESSAGE_BUS CANFDPack;      // '<Root>/CAN FD Pack'
    CAN_MSG_BUS Switch;                // '<S77>/Switch'
    CAN_MSG_BUS Switch_l;              // '<S81>/Switch'
    CAN_MSG_BUS Switch_lw;             // '<S80>/Switch'
    CAN_MSG_BUS Switch_b;              // '<S78>/Switch'
    CAN_MSG_BUS Switch_p;              // '<S79>/Switch'
    CAN_MESSAGE_BUS CANPack;           // '<S52>/CAN Pack'
    CAN_MESSAGE_BUS CANPack1;          // '<S52>/CAN Pack1'
    CAN_MESSAGE_BUS CANPack2;          // '<S52>/CAN Pack2'
    CAN_MESSAGE_BUS CANPack3;          // '<S52>/CAN Pack3'
    CAN_MESSAGE_BUS CANPack4;          // '<S52>/CAN Pack4'
    real_T PGI02_check;                // '<S47>/CAN Unpack'
    real_T PGI04_STOP_reason0;         // '<S47>/CAN Unpack'
    real_T PGI04_STOP_reason1;         // '<S47>/CAN Unpack'
    real_T PGI04_STOP_type;            // '<S47>/CAN Unpack'
    real_T PGI04_reLink;               // '<S47>/CAN Unpack'
    real_T PGI09_wakeup;               // '<S47>/CAN Unpack'
    real_T PGI12_Authentic;            // '<S47>/CAN Unpack'
    real_T PGI12_EndOfCharge;          // '<S47>/CAN Unpack'
    real_T PGI12_OutLoopDete;          // '<S47>/CAN Unpack'
    real_T PGI12_ParmCfg;              // '<S47>/CAN Unpack'
    real_T PGI12_PowerMode;            // '<S47>/CAN Unpack'
    real_T PGI12_PreChgEnTrans;        // '<S47>/CAN Unpack'
    real_T PGI12_Scheduled;            // '<S47>/CAN Unpack'
    real_T PGI36_FDCType;              // '<S47>/CAN Unpack'
    real_T PGI3A_FDCType;              // '<S47>/CAN Unpack'
    real_T PGI52_CheckState;           // '<S47>/CAN Unpack'
    real_T PGI79_Pause;                // '<S47>/CAN Unpack'
    real_T PGI94_SOC;                  // '<S47>/CAN Unpack'
    real_T S_EVCC_PGI;                 // '<S47>/CAN Unpack'
    real_T EVCC_CANType;               // '<S47>/CAN Unpack7'
    real_T EVCC_CPVersoin;             // '<S47>/CAN Unpack7'
    real_T EVCC_ProtocolVersion0;      // '<S47>/CAN Unpack7'
    real_T EVCC_ProtocolVersion1;      // '<S47>/CAN Unpack7'
    real_T EVCC_ProtocolVersion2;      // '<S47>/CAN Unpack7'
    real_T EVCC_Reserved;              // '<S47>/CAN Unpack7'
    real_T EVCC_TLVersion;             // '<S47>/CAN Unpack7'
    real_T EVCC_VersionResult;         // '<S47>/CAN Unpack7'
    real_T Ctrl_EVCC_Byte0;            // '<S47>/CAN Unpack3'
    real_T confirmPGI;                 // '<S47>/CAN Unpack3'
    real_T recvedByteTotal;            // '<S47>/CAN Unpack3'
    real_T recvedNumTotal;             // '<S47>/CAN Unpack3'
    real_T waitRecvNumStart;           // '<S47>/CAN Unpack3'
    real_T waitRecvNumTotal;           // '<S47>/CAN Unpack3'
    real_T PGI06_K5;                   // '<S47>/CAN Unpack1'
    real_T PGI06_K6;                   // '<S47>/CAN Unpack1'
    real_T PGI32_VAuthenStatus;        // '<S47>/CAN Unpack1'
    real_T PGI72_EVCCReady;            // '<S47>/CAN Unpack1'
    real_T PGI72_EVCC_V_Exe;           // '<S47>/CAN Unpack1'
    real_T PGI73_A;                    // '<S47>/CAN Unpack1'
    real_T PGI73_PowerMode;            // '<S47>/CAN Unpack1'
    real_T PGI73_V;                    // '<S47>/CAN Unpack1'
    real_T PGI74_SOC;                  // '<S47>/CAN Unpack1'
    real_T PGI74_TimeRemain;           // '<S47>/CAN Unpack1'
    real_T PGI77_SingleBattTemp_Max;   // '<S47>/CAN Unpack1'
    real_T PGI77_SingleBattTemp_Min;   // '<S47>/CAN Unpack1'
    real_T PGI77_SingleBattV_Max;      // '<S47>/CAN Unpack1'
    real_T PGI77_SingleBattV_Min;      // '<S47>/CAN Unpack1'
    real_T PGI91_EVCCDetectSta;        // '<S47>/CAN Unpack1'
    real_T SU_EVCC_PGI;                // '<S47>/CAN Unpack1'
    real_T CANFDUnpack_o1;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o2;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o3;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o4;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o5;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o6;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o7;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o8;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o9;             // '<Root>/CAN FD Unpack'
    real_T Switch6;                    // '<Root>/Switch6'
    real_T DataTypeConversion26;       // '<Root>/Data Type Conversion26'
    real_T enable_m;                   // '<Root>/normal250_3'
    real_T enable_g;                   // '<Root>/normal250_2'
    real_T enable_i;                   // '<Root>/normal250_1'
    real_T enable_o;                   // '<Root>/normal250_'
    real_T enable_gd;                  // '<Root>/normal1000_50for3_1'
    real_T enable_c;                   // '<Root>/normal1000_50for3_'
    real_T enable_ol;                  // '<Root>/normal1000_50for3'
    real_T enable_mj;                  // '<Root>/normal1000'
    real_T outPGI;                     // '<Root>/keep1_for10ms'
    real_T outNextStep;                // '<Root>/VN'
    real_T VersionResult;              // '<Root>/VN'
    real_T VN_Enable;                  // '<Root>/VN'
    real_T enable_a;                   // '<S52>/sendCyclic4'
    real_T enable_f;                   // '<S52>/sendCyclic3'
    real_T enable_mg;                  // '<S52>/sendCyclic2'
    real_T enable_a4;                  // '<S52>/sendCyclic1'
    real_T enable_h;                   // '<S52>/sendCyclic'
    real_T DetectAllow;                // '<Root>/QC2015P_STOP'
    real_T RelinkAllow;                // '<Root>/QC2015P_STOP'
    real_T RebootAllow;                // '<Root>/QC2015P_STOP'
    real_T SEQ;                        // '<Root>/QC2015P_MAIN'
    real_T ReStart;                    // '<Root>/QC2015P_MAIN'
    real_T m50_1;                      // '<Root>/MAIN_CNT'
    real_T m50_11;                     // '<Root>/MAIN_CNT'
    real_T m50_21;                     // '<Root>/MAIN_CNT'
    real_T m50_31;                     // '<Root>/MAIN_CNT'
    real_T m50_41;                     // '<Root>/MAIN_CNT'
    real_T m50_2;                      // '<Root>/MAIN_CNT'
    real_T m50_12;                     // '<Root>/MAIN_CNT'
    real_T m10_3;                      // '<Root>/MAIN_CNT'
    real_T m10_4;                      // '<Root>/MAIN_CNT'
    real_T m10_5;                      // '<Root>/MAIN_CNT'
    real_T m10_6;                      // '<Root>/MAIN_CNT'
    real_T LM_NACK;                    // '<Root>/LM_Send'
    real_T sendFlg;                    // '<Root>/LM_Send'
    real_T n_num;                      // '<Root>/LM_Send'
    real_T sendFlg_l;                  // '<Root>/LM_Recv'
    real_T n_num_l;                    // '<Root>/LM_Recv'
    real_T k_num;                      // '<Root>/LM_Recv'
    real_T recv_tfra;                  // '<Root>/LM_Recv'
    real_T totalBytes;                 // '<Root>/LM_Recv'
    uint32_T LocalVersion;             // '<Root>/VN'
    uint8_T RX_Status;                 // '<S47>/CAN Unpack'
    uint8_T RX_Status_c;               // '<S47>/CAN Unpack7'
    uint8_T RX_Status_j;               // '<S47>/CAN Unpack3'
    uint8_T RX_Status_jq;              // '<S47>/CAN Unpack1'
    uint8_T Data[8];                   // '<S47>/CAN Unpack4'
    uint8_T RX_Status_f;               // '<S47>/CAN Unpack4'
    uint8_T Switch45[16];              // '<Root>/Switch45'
    uint8_T Transpose[8];              // '<Root>/Transpose'
    uint8_T Switch5[8];                // '<S52>/Switch5'
    uint8_T Switch8[8];                // '<S52>/Switch8'
    uint8_T Switch12[8];               // '<S52>/Switch12'
    uint8_T Switch10[8];               // '<S52>/Switch10'
    uint8_T Switch14[8];               // '<S52>/Switch14'
    uint8_T PGI_Enable[255];           // '<Root>/QC2015P_MAIN'
    uint8_T Data_PGI03[8];             // '<Root>/QC2015P_MAIN'
    uint8_T K1;                        // '<Root>/QC2015P_MAIN'
    uint8_T K2;                        // '<Root>/QC2015P_MAIN'
    uint8_T Elock;                     // '<Root>/QC2015P_MAIN'
    uint8_T PGI71_ChargerReady;        // '<Root>/QC2015P_MAIN'
    uint8_T PGI51_Data[8];             // '<Root>/QC2015P_MAIN'
    uint8_T PGI08_wakeup;              // '<Root>/QC2015P_MAIN'
    boolean_T LogicalOperator28;       // '<Root>/Logical Operator28'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_QC2015P_SECC_T {
    real_T UnitDelay1_DSTATE;          // '<Root>/Unit Delay1'
    real_T UnitDelay16_DSTATE;         // '<Root>/Unit Delay16'
    real_T UnitDelay17_DSTATE;         // '<Root>/Unit Delay17'
    real_T UnitDelay12_DSTATE;         // '<Root>/Unit Delay12'
    real_T UnitDelay13_DSTATE;         // '<Root>/Unit Delay13'
    real_T DiscreteTimeIntegrator_DSTATE;// '<Root>/Discrete-Time Integrator'
    real_T UnitDelay9_DSTATE;          // '<Root>/Unit Delay9'
    real_T UnitDelay8_DSTATE;          // '<Root>/Unit Delay8'
    real_T UnitDelay10_DSTATE;         // '<Root>/Unit Delay10'
    real_T cnt;                        // '<Root>/normal1000'
    real_T Ns;                         // '<Root>/VN'
    real_T Tout0;                      // '<Root>/VN'
    real_T NextStep;                   // '<Root>/VN'
    real_T timeOut;                    // '<Root>/QC2015P_MAIN'
    real_T timer;                      // '<Root>/QC2015P_MAIN'
    real_T PauseCNT;                   // '<Root>/QC2015P_MAIN'
    real_T T1;                         // '<Root>/QC2015P_MAIN'
    real_T T2;                         // '<Root>/QC2015P_MAIN'
    real_T STOP_reason;                // '<Root>/QC2015P_MAIN'
    real_T STOP_type;                  // '<Root>/QC2015P_MAIN'
    real_T PGI32_Flg;                  // '<Root>/QC2015P_MAIN'
    real_T timer_d;                    // '<Root>/MAIN_CNT'
    real_T err_cnt;                    // '<Root>/LM_Send'
    real_T LMS_T1;                     // '<Root>/LM_Send'
    real_T local_n;                    // '<Root>/LM_Send'
    real_T LMS_T3;                     // '<Root>/LM_Send'
    real_T LMS_T2;                     // '<Root>/LM_Send'
    real_T local_k;                    // '<Root>/LM_Send'
    real_T send_cnt;                   // '<Root>/LM_Send'
    real_T recv_no;                    // '<Root>/LM_Recv'
    real_T LMS_T2_b;                   // '<Root>/LM_Recv'
    real_T err_cnt_k;                  // '<Root>/LM_Recv'
    real_T LMS_T3_n;                   // '<Root>/LM_Recv'
    real_T lm_tfra;                    // '<Root>/LM_Recv'
    real_T recv_num;                   // '<Root>/LM_Recv'
    real_T totalBytes;                 // '<Root>/AnalysisLM'
    real_T lm_tfra_p;                  // '<Root>/AnalysisLM'
    real_T tmpLists[1785];             // '<Root>/AnalysisLM'
    real_T sliceFlag[255];             // '<Root>/AnalysisLM'
    int_T CANUnpack_ModeSignalID;      // '<S47>/CAN Unpack'
    int_T CANUnpack_StatusPortID;      // '<S47>/CAN Unpack'
    int_T CANUnpack7_ModeSignalID;     // '<S47>/CAN Unpack7'
    int_T CANUnpack7_StatusPortID;     // '<S47>/CAN Unpack7'
    int_T CANUnpack3_ModeSignalID;     // '<S47>/CAN Unpack3'
    int_T CANUnpack3_StatusPortID;     // '<S47>/CAN Unpack3'
    int_T CANUnpack1_ModeSignalID;     // '<S47>/CAN Unpack1'
    int_T CANUnpack1_StatusPortID;     // '<S47>/CAN Unpack1'
    int_T CANUnpack4_ModeSignalID;     // '<S47>/CAN Unpack4'
    int_T CANUnpack4_StatusPortID;     // '<S47>/CAN Unpack4'
    int_T CANFDUnpack_ModeSignalID;    // '<Root>/CAN FD Unpack'
    int_T CANFDUnpack_StatusPortID;    // '<Root>/CAN FD Unpack'
    int_T CANFDPack_ModeSignalID;      // '<Root>/CAN FD Pack'
    uint16_T temporalCounter_i1;       // '<Root>/keep1_for10000ms1'
    uint16_T temporalCounter_i1_b;     // '<Root>/QC2015P_MAIN'
    uint16_T temporalCounter_i2;       // '<Root>/QC2015P_MAIN'
    uint8_T UnitDelay11_DSTATE[255];   // '<Root>/Unit Delay11'
    uint8_T UnitDelay5_DSTATE;         // '<Root>/Unit Delay5'
    uint8_T UnitDelay7_DSTATE;         // '<Root>/Unit Delay7'
    uint8_T UnitDelay3_DSTATE[8];      // '<Root>/Unit Delay3'
    uint8_T UnitDelay2_DSTATE[8];      // '<Root>/Unit Delay2'
    uint8_T UnitDelay_DSTATE[8];       // '<Root>/Unit Delay'
    boolean_T UnitDelay4_DSTATE;       // '<Root>/Unit Delay4'
    boolean_T UnitDelay6_DSTATE;       // '<Root>/Unit Delay6'
    boolean_T UnitDelay19_DSTATE;      // '<Root>/Unit Delay19'
    int8_T DiscreteTimeIntegrator_PrevRese;// '<Root>/Discrete-Time Integrator'
    uint8_T is_active_c18_QC2015P_SECC;// '<Root>/normal1000'
    uint8_T is_c18_QC2015P_SECC;       // '<Root>/normal1000'
    uint8_T is_active_c25_QC2015P_SECC;// '<Root>/keep1_for50ms'
    uint8_T is_c25_QC2015P_SECC;       // '<Root>/keep1_for50ms'
    uint8_T temporalCounter_i1_o;      // '<Root>/keep1_for50ms'
    uint8_T is_active_c20_QC2015P_SECC;// '<Root>/keep1_for10ms1'
    uint8_T is_c20_QC2015P_SECC;       // '<Root>/keep1_for10ms1'
    uint8_T temporalCounter_i1_g;      // '<Root>/keep1_for10ms1'
    uint8_T is_active_c19_QC2015P_SECC;// '<Root>/keep1_for10ms'
    uint8_T is_c19_QC2015P_SECC;       // '<Root>/keep1_for10ms'
    uint8_T temporalCounter_i1_l;      // '<Root>/keep1_for10ms'
    uint8_T is_active_c30_QC2015P_SECC;// '<Root>/keep1_for10000ms1'
    uint8_T is_c30_QC2015P_SECC;       // '<Root>/keep1_for10000ms1'
    uint8_T is_active_c9_QC2015P_SECC; // '<Root>/VN'
    uint8_T is_c9_QC2015P_SECC;        // '<Root>/VN'
    uint8_T temporalCounter_i1_a;      // '<Root>/VN'
    uint8_T is_active_c26_QC2015P_SECC;// '<Root>/QC2015P_STOP'
    uint8_T is_c26_QC2015P_SECC;       // '<Root>/QC2015P_STOP'
    uint8_T is_active_c10_QC2015P_SECC;// '<Root>/QC2015P_MAIN'
    uint8_T is_c10_QC2015P_SECC;       // '<Root>/QC2015P_MAIN'
    uint8_T is_QC2015P;                // '<Root>/QC2015P_MAIN'
    uint8_T is_End;                    // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start;               // '<Root>/QC2015P_MAIN'
    uint8_T is_QC2015P_BeforeEnd;      // '<Root>/QC2015P_MAIN'
    uint8_T is_Authentic;              // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start_n;             // '<Root>/QC2015P_MAIN'
    uint8_T is_Send_PGI31;             // '<Root>/QC2015P_MAIN'
    uint8_T is_FN;                     // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start_p;             // '<Root>/QC2015P_MAIN'
    uint8_T is_OutLoopDete;            // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start_np;            // '<Root>/QC2015P_MAIN'
    uint8_T is_Send_PGI51;             // '<Root>/QC2015P_MAIN'
    uint8_T is_Detecting;              // '<Root>/QC2015P_MAIN'
    uint8_T is_ManualSet;              // '<Root>/QC2015P_MAIN'
    uint8_T is_ParmCfg;                // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start_k;             // '<Root>/QC2015P_MAIN'
    uint8_T is_PreChgEnTrans;          // '<Root>/QC2015P_MAIN'
    uint8_T is_EnTrans;                // '<Root>/QC2015P_MAIN'
    uint8_T is_PreChg;                 // '<Root>/QC2015P_MAIN'
    uint8_T is_S2;                     // '<Root>/QC2015P_MAIN'
    uint8_T is_ReLink_Reboot;          // '<Root>/QC2015P_MAIN'
    uint8_T is_Rebooting;              // '<Root>/QC2015P_MAIN'
    uint8_T is_active_c3_QC2015P_SECC; // '<Root>/MAIN_CNT'
    uint8_T is_c3_QC2015P_SECC;        // '<Root>/MAIN_CNT'
    uint8_T is_active_c15_QC2015P_SECC;// '<Root>/LM_Send'
    uint8_T is_c15_QC2015P_SECC;       // '<Root>/LM_Send'
    uint8_T is_S1_S4;                  // '<Root>/LM_Send'
    uint8_T temporalCounter_i1_c;      // '<Root>/LM_Send'
    uint8_T is_active_c11_QC2015P_SECC;// '<Root>/LM_Recv'
    uint8_T is_c11_QC2015P_SECC;       // '<Root>/LM_Recv'
    uint8_T is_S1;                     // '<Root>/LM_Recv'
    uint8_T temporalCounter_i1_aw;     // '<Root>/LM_Recv'
    DW_normal250__QC2015P_SECC_T sf_normal250_3;// '<Root>/normal250_3'
    DW_normal250__QC2015P_SECC_T sf_normal250_2;// '<Root>/normal250_2'
    DW_normal250__QC2015P_SECC_T sf_normal250_1;// '<Root>/normal250_1'
    DW_normal250__QC2015P_SECC_T sf_normal250_;// '<Root>/normal250_'
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3_1;// '<Root>/normal1000_50for3_1' 
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3_;// '<Root>/normal1000_50for3_' 
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3;// '<Root>/normal1000_50for3' 
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic4;// '<S52>/sendCyclic4'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic3;// '<S52>/sendCyclic3'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic2;// '<S52>/sendCyclic2'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic1;// '<S52>/sendCyclic1'
    DW_sendCyclic_QC2015P_SECC_T sf_sendCyclic;// '<S52>/sendCyclic'
  };

  // Constant parameters (default storage)
  struct ConstP_QC2015P_SECC_T {
    // Expression: [2, 255, 255, 255, 255, 255, 255, 255]
    //  Referenced by: '<Root>/LM_NACK'

    real_T LM_NACK_Value[8];

    // Expression: [0,1,4,0xFF,0xFF,0xFF,0xFF,0xFF]
    //  Referenced by: '<Root>/Constant37'

    uint8_T Constant37_Value[8];

    // Expression: [3,1,3,2,0xFF,0xFF,0xFF,0xFF]
    //  Referenced by: '<Root>/Constant56'

    uint8_T Constant56_Value[8];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_QC2015P_SECC_T {
    CAN_MSG_Array MsgInput;            // '<Root>/MsgInput'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_QC2015P_SECC_T {
    CAN_MESSAGE_BUS Msg_Send[5];       // '<Root>/Msg_Send'
    UserMonitor_SECC UserMonitor_SECC_n;// '<Root>/UserMonitor_SECC'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_QC2015P_SECC_T {
    const char_T * volatile errorStatus;
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

  // private member function(s) for subsystem '<Root>/Bit Shift10'
  static void QC2015P_SECC_BitShift10(uint16_T rtu_u, uint16_T *rty_y);

  // private member function(s) for subsystem '<S52>/sendCyclic'
  static void QC2015P_SECC_sendCyclic_Init(real_T *rty_enable);
  static void QC2015P_SECC_sendCyclic(boolean_T rtu_startFlg, real_T
    rtu_cycleTime, real_T *rty_enable, DW_sendCyclic_QC2015P_SECC_T *localDW);

  // private member function(s) for subsystem '<Root>/normal1000_50for3'
  static void QC2015P__normal1000_50for3_Init(real_T *rty_enable);
  static void QC2015P_SECC_normal1000_50for3(boolean_T rtu_rawCycle, boolean_T
    rtu_startFlg, real_T *rty_enable, DW_normal1000_50for3_QC2015P__T *localDW);

  // private member function(s) for subsystem '<Root>/normal250_'
  static void QC2015P_SECC_normal250__Init(real_T *rty_enable);
  static void QC2015P_SECC_normal250_(boolean_T rtu_rawCycle, real_T *rty_enable,
    DW_normal250__QC2015P_SECC_T *localDW);

  // private member function(s) for subsystem '<Root>'
  real_T QC2015P_SECC_mod(real_T x);
  real_T QC2015P_SECC_mod_b(real_T x);
  void QC2015P_SECC_enter_atomic_init(void);
  void QC2015P_SECC_exit_internal_End(void);
  void QC2015P_SECC_End(void);
  void QC2015P_SECC_Authentic(void);
  void QC2015P_SECC_OutLoopDete(void);
  void QC2015P_SECC_ParmCfg(void);
  void QC2015P_SECC_PreChgEnTrans(void);
  void exit_internal_QC2015P_BeforeEnd(void);
  void QC2015P_SECC_QC2015P_BeforeEnd(const real_T *Switch53, const uint8_T
    Transpose1[8]);
  void QC2015P_S_exit_internal_QC2015P(void);
  void QC2015P_SEC_enter_atomic_init_g(void);
  void QC2015P_SECC_QC2015P(const real_T *Switch53, const real_T *out, const
    uint8_T Transpose1[8]);
  void QC2015P_SE_enter_atomic_init_S0(void);
  void enter_atomic_S0_init_or_S2_fini(void);
  void QC2015P_SECC_S1(const real_T DataTypeConversion6[8], const boolean_T
                       *LogicalOperator4);

  // Real-Time Model
  RT_MODEL_QC2015P_SECC_T QC2015P_SECC_M;
};

// Constant parameters (default storage)
extern const QC2015P_SECC::ConstP_QC2015P_SECC_T QC2015P_SECC_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Constant10' : Unused code path elimination
//  Block '<Root>/Constant25' : Unused code path elimination
//  Block '<Root>/Constant59' : Unused code path elimination
//  Block '<Root>/Constant9' : Unused code path elimination
//  Block '<Root>/Min of Elements3' : Unused code path elimination
//  Block '<Root>/Selector15' : Unused code path elimination
//  Block '<Root>/Selector16' : Unused code path elimination
//  Block '<Root>/Selector19' : Unused code path elimination
//  Block '<Root>/Switch55' : Unused code path elimination
//  Block '<Root>/Unit Delay14' : Unused code path elimination


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
//  '<S1>'   : 'QC2015P_SECC/AnalysisLM'
//  '<S2>'   : 'QC2015P_SECC/Bit Shift'
//  '<S3>'   : 'QC2015P_SECC/Bit Shift1'
//  '<S4>'   : 'QC2015P_SECC/Bit Shift10'
//  '<S5>'   : 'QC2015P_SECC/Bit Shift2'
//  '<S6>'   : 'QC2015P_SECC/Bit Shift3'
//  '<S7>'   : 'QC2015P_SECC/Bit Shift4'
//  '<S8>'   : 'QC2015P_SECC/Bit Shift5'
//  '<S9>'   : 'QC2015P_SECC/Bit Shift6'
//  '<S10>'  : 'QC2015P_SECC/Bit Shift7'
//  '<S11>'  : 'QC2015P_SECC/Bit Shift8'
//  '<S12>'  : 'QC2015P_SECC/Compare To Constant'
//  '<S13>'  : 'QC2015P_SECC/Compare To Constant1'
//  '<S14>'  : 'QC2015P_SECC/Compare To Constant10'
//  '<S15>'  : 'QC2015P_SECC/Compare To Constant11'
//  '<S16>'  : 'QC2015P_SECC/Compare To Constant12'
//  '<S17>'  : 'QC2015P_SECC/Compare To Constant13'
//  '<S18>'  : 'QC2015P_SECC/Compare To Constant14'
//  '<S19>'  : 'QC2015P_SECC/Compare To Constant15'
//  '<S20>'  : 'QC2015P_SECC/Compare To Constant16'
//  '<S21>'  : 'QC2015P_SECC/Compare To Constant17'
//  '<S22>'  : 'QC2015P_SECC/Compare To Constant18'
//  '<S23>'  : 'QC2015P_SECC/Compare To Constant19'
//  '<S24>'  : 'QC2015P_SECC/Compare To Constant2'
//  '<S25>'  : 'QC2015P_SECC/Compare To Constant20'
//  '<S26>'  : 'QC2015P_SECC/Compare To Constant21'
//  '<S27>'  : 'QC2015P_SECC/Compare To Constant22'
//  '<S28>'  : 'QC2015P_SECC/Compare To Constant23'
//  '<S29>'  : 'QC2015P_SECC/Compare To Constant27'
//  '<S30>'  : 'QC2015P_SECC/Compare To Constant28'
//  '<S31>'  : 'QC2015P_SECC/Compare To Constant29'
//  '<S32>'  : 'QC2015P_SECC/Compare To Constant3'
//  '<S33>'  : 'QC2015P_SECC/Compare To Constant30'
//  '<S34>'  : 'QC2015P_SECC/Compare To Constant36'
//  '<S35>'  : 'QC2015P_SECC/Compare To Constant37'
//  '<S36>'  : 'QC2015P_SECC/Compare To Constant4'
//  '<S37>'  : 'QC2015P_SECC/Compare To Constant41'
//  '<S38>'  : 'QC2015P_SECC/Compare To Constant5'
//  '<S39>'  : 'QC2015P_SECC/Compare To Constant6'
//  '<S40>'  : 'QC2015P_SECC/Compare To Constant7'
//  '<S41>'  : 'QC2015P_SECC/Compare To Constant8'
//  '<S42>'  : 'QC2015P_SECC/Compare To Constant9'
//  '<S43>'  : 'QC2015P_SECC/LM_Recv'
//  '<S44>'  : 'QC2015P_SECC/LM_Send'
//  '<S45>'  : 'QC2015P_SECC/MAIN_CNT'
//  '<S46>'  : 'QC2015P_SECC/MATLAB Function1'
//  '<S47>'  : 'QC2015P_SECC/Msg_Recv'
//  '<S48>'  : 'QC2015P_SECC/PACK_LM'
//  '<S49>'  : 'QC2015P_SECC/Pack_LM_ACK'
//  '<S50>'  : 'QC2015P_SECC/QC2015P_MAIN'
//  '<S51>'  : 'QC2015P_SECC/QC2015P_STOP'
//  '<S52>'  : 'QC2015P_SECC/Subsystem'
//  '<S53>'  : 'QC2015P_SECC/VN'
//  '<S54>'  : 'QC2015P_SECC/get_lm_tfra'
//  '<S55>'  : 'QC2015P_SECC/keep1_for10000ms1'
//  '<S56>'  : 'QC2015P_SECC/keep1_for10ms'
//  '<S57>'  : 'QC2015P_SECC/keep1_for10ms1'
//  '<S58>'  : 'QC2015P_SECC/keep1_for50ms'
//  '<S59>'  : 'QC2015P_SECC/normal1000'
//  '<S60>'  : 'QC2015P_SECC/normal1000_50for3'
//  '<S61>'  : 'QC2015P_SECC/normal1000_50for3_'
//  '<S62>'  : 'QC2015P_SECC/normal1000_50for3_1'
//  '<S63>'  : 'QC2015P_SECC/normal250_'
//  '<S64>'  : 'QC2015P_SECC/normal250_1'
//  '<S65>'  : 'QC2015P_SECC/normal250_2'
//  '<S66>'  : 'QC2015P_SECC/normal250_3'
//  '<S67>'  : 'QC2015P_SECC/Bit Shift/bit_shift'
//  '<S68>'  : 'QC2015P_SECC/Bit Shift1/bit_shift'
//  '<S69>'  : 'QC2015P_SECC/Bit Shift10/bit_shift'
//  '<S70>'  : 'QC2015P_SECC/Bit Shift2/bit_shift'
//  '<S71>'  : 'QC2015P_SECC/Bit Shift3/bit_shift'
//  '<S72>'  : 'QC2015P_SECC/Bit Shift4/bit_shift'
//  '<S73>'  : 'QC2015P_SECC/Bit Shift5/bit_shift'
//  '<S74>'  : 'QC2015P_SECC/Bit Shift6/bit_shift'
//  '<S75>'  : 'QC2015P_SECC/Bit Shift7/bit_shift'
//  '<S76>'  : 'QC2015P_SECC/Bit Shift8/bit_shift'
//  '<S77>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect'
//  '<S78>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect1'
//  '<S79>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect2'
//  '<S80>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect3'
//  '<S81>'  : 'QC2015P_SECC/Msg_Recv/MsgSelect4'
//  '<S82>'  : 'QC2015P_SECC/Subsystem/sendCyclic'
//  '<S83>'  : 'QC2015P_SECC/Subsystem/sendCyclic1'
//  '<S84>'  : 'QC2015P_SECC/Subsystem/sendCyclic2'
//  '<S85>'  : 'QC2015P_SECC/Subsystem/sendCyclic3'
//  '<S86>'  : 'QC2015P_SECC/Subsystem/sendCyclic4'

#endif                                 // RTW_HEADER_QC2015P_SECC_h_

//
// File trailer for generated code.
//
// [EOF]
//
