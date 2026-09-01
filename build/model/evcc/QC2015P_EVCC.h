//
// File: QC2015P_EVCC.h
//
// Code generated for Simulink model 'QC2015P_EVCC'.
//
// Model version                  : 1.401
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Sep  1 20:27:09 2026
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
  real_T BMS_Vlotage;                  // Referenced by:
                                          //  '<Root>/BMS_Vlotage'
                                          //  '<Root>/BMS_Vlotage1'

  real_T CONTROL_EVCC_Cycle_Va; // Referenced by: '<S62>/CONTROL_EVCC_Cycle_Va'
  real_T Charge_Current;              // Referenced by: '<Root>/Charge_Current'
  real_T LM_EVCC_Cycle_Va;           // Referenced by: '<S62>/LM_EVCC_Cycle_Va'
  real_T PGI22_Capacity;              // Referenced by: '<Root>/PGI22_Capacity'
  real_T PGI22_Current;                // Referenced by: '<Root>/PGI22_Current'
  real_T PGI22_SOC;                    // Referenced by: '<Root>/PGI22_SOC'
  real_T PGI22_Voltage;                // Referenced by: '<Root>/PGI22_Voltage'
  real_T PGI22_Voltage2;              // Referenced by: '<Root>/PGI22_Voltage2'
  real_T PGI72_EVCC_V_Exe_Va;    // Referenced by: '<Root>/PGI72_EVCC_V_Exe_Va'
  real_T PGI73_A_Va;                   // Referenced by: '<Root>/PGI73_A_Va'
  real_T PGI73_V_Va;                   // Referenced by: '<Root>/PGI73_V_Va'
  real_T PGI74_SOC_Va;                 // Referenced by: '<Root>/PGI74_SOC_Va'
  real_T PGI74_TimeRemain_Va;    // Referenced by: '<Root>/PGI74_TimeRemain_Va'
  real_T PGI77_SingleBattV_Max;// Referenced by: '<Root>/PGI77_SingleBattV_Max'
  real_T PGI77_SingleBattV_Min;// Referenced by: '<Root>/PGI77_SingleBattV_Min'
  real_T PGI94_SOC_Va;                 // Referenced by: '<Root>/PGI94_SOC_Va'
  real_T SM_RM_EVCC_Cycle_Va;     // Referenced by: '<S62>/SM_RM_EVCC_Cycle_Va'
  real_T SM_URM_EVCC_Cycle_Va;   // Referenced by: '<S62>/SM_URM_EVCC_Cycle_Va'
  real_T SOC_Set;                      // Referenced by: '<Root>/SOC_Set'
  real_T VC_EVCC_Cycle_Va;           // Referenced by: '<S62>/VC_EVCC_Cycle_Va'
  boolean_T CONTROL_EVCC_Data_SW;// Referenced by: '<S62>/CONTROL_EVCC_Data_SW'
  boolean_T CONTROL_EVCC_Enable_SW;
                               // Referenced by: '<S62>/CONTROL_EVCC_Enable_SW'
  boolean_T CONTROL_EVCC_Enable_Va;
                               // Referenced by: '<S62>/CONTROL_EVCC_Enable_Va'
  boolean_T EVCC_ChargeSta;           // Referenced by: '<Root>/EVCC_ChargeSta'
  boolean_T EVCC_DiagSW;               // Referenced by: '<Root>/EVCC_DiagSW'
  boolean_T EVCC_LM_ManualSTOP;   // Referenced by: '<Root>/EVCC_LM_ManualSTOP'
  boolean_T EVCC_ManualSTOP;         // Referenced by: '<Root>/EVCC_ManualSTOP'
  boolean_T EVCC_Pause;                // Referenced by: '<Root>/Constant53'
  boolean_T EVCC_ProtocolVersion_SW;
                             // Referenced by: '<Root>/EVCC_ProtocolVersion_SW'
  boolean_T EVCC_Reboot;               // Referenced by: '<Root>/EVCC_Reboot'
  boolean_T EVCC_Relink;               // Referenced by: '<Root>/EVCC_Relink'
  boolean_T EVCC_VersionResult_SW;
                               // Referenced by: '<Root>/EVCC_VersionResult_SW'
  boolean_T LM_EVCC_Data_SW;          // Referenced by: '<S62>/LM_EVCC_Data_SW'
  boolean_T LM_EVCC_Enable_SW;      // Referenced by: '<S62>/LM_EVCC_Enable_SW'
  boolean_T LM_EVCC_Enable_Va;      // Referenced by: '<S62>/LM_EVCC_Enable_Va'
  boolean_T PGI02_check_SW;           // Referenced by: '<Root>/PGI02_check_SW'
  boolean_T PGI06_K5_SW;               // Referenced by: '<Root>/PGI06_K5_SW'
  boolean_T PGI06_K6_SW;               // Referenced by: '<Root>/PGI06_K6_SW'
  boolean_T PGI09_wakeup_SW;         // Referenced by: '<Root>/PGI09_wakeup_SW'
  boolean_T PGI12_Authentic_SW;   // Referenced by: '<Root>/PGI12_Authentic_SW'
  boolean_T PGI22_SOC_SW;              // Referenced by: '<Root>/PGI22_SOC_SW'
  boolean_T PGI32_VAuthenStatus; // Referenced by: '<Root>/PGI32_VAuthenStatus'
  boolean_T PGI52_CheckState_SW; // Referenced by: '<Root>/PGI52_CheckState_SW'
  boolean_T PGI72_EVCCReady_SW;   // Referenced by: '<Root>/PGI72_EVCCReady_SW'
  boolean_T PGI72_EVCC_V_Exe_SW; // Referenced by: '<Root>/PGI72_EVCC_V_Exe_SW'
  boolean_T PGI73_A_SW;                // Referenced by: '<Root>/PGI73_A_SW'
  boolean_T PGI73_PowerMode_SW;   // Referenced by: '<Root>/PGI73_PowerMode_SW'
  boolean_T PGI73_V_SW;                // Referenced by: '<Root>/PGI73_V_SW'
  boolean_T PGI74_SOC_SW;              // Referenced by: '<Root>/PGI74_SOC_SW'
  boolean_T PGI74_TimeRemain_SW; // Referenced by: '<Root>/PGI74_TimeRemain_SW'
  boolean_T PGI79_Pause_SW;           // Referenced by: '<Root>/PGI79_Pause_SW'
  boolean_T PGI91_EVCCDetectSta_SW;
                              // Referenced by: '<Root>/PGI91_EVCCDetectSta_SW'
  boolean_T PGI94_SOC_SW;              // Referenced by: '<Root>/PGI94_SOC_SW'
  boolean_T SM_RM_EVCC_Data_SW;    // Referenced by: '<S62>/SM_RM_EVCC_Data_SW'
  boolean_T SM_RM_EVCC_Enable_SW;// Referenced by: '<S62>/SM_RM_EVCC_Enable_SW'
  boolean_T SM_RM_EVCC_Enable_Va;// Referenced by: '<S62>/SM_RM_EVCC_Enable_Va'
  boolean_T SM_URM_EVCC_Data_SW;  // Referenced by: '<S62>/SM_URM_EVCC_Data_SW'
  boolean_T SM_URM_EVCC_Enable_SW;
                                // Referenced by: '<S62>/SM_URM_EVCC_Enable_SW'
  boolean_T SM_URM_EVCC_Enable_Va;
                                // Referenced by: '<S62>/SM_URM_EVCC_Enable_Va'
  boolean_T VC_EVCC_Data_SW;          // Referenced by: '<S62>/VC_EVCC_Data_SW'
  boolean_T VC_EVCC_Enable_SW;      // Referenced by: '<S62>/VC_EVCC_Enable_SW'
  boolean_T VC_EVCC_Enable_Va;      // Referenced by: '<S62>/VC_EVCC_Enable_Va'
  int16_T PGI22_Temp;                  // Referenced by: '<Root>/PGI22_Temp'
  int16_T PGI77_SingleBattTemp_Max;
                            // Referenced by: '<Root>/PGI77_SingleBattTemp_Max'
  int16_T PGI77_SingleBattTemp_Min;
                            // Referenced by: '<Root>/PGI77_SingleBattTemp_Min'
  uint32_T EVCC_CVList[4];             // Referenced by: '<Root>/CvList'
  uint32_T EVCC_ProtocolVersion_Va;
                             // Referenced by: '<Root>/EVCC_ProtocolVersion_Va'
  uint8_T CONTROL_EVCC_Data_Va[8];
                                 // Referenced by: '<S62>/CONTROL_EVCC_Data_Va'
  uint8_T EVCC_CANType;                // Referenced by: '<Root>/EVCC_CANType'
  uint8_T EVCC_CPVersion;             // Referenced by: '<Root>/EVCC_CPVersion'
  uint8_T EVCC_K_Limit;                // Referenced by: '<Root>/EVCC_K_Limit'
  uint8_T EVCC_Reserved_VN;         // Referenced by: '<Root>/EVCC_Reserved_VN'
  uint8_T EVCC_TLVersion;             // Referenced by: '<Root>/EVCC_TLVersion'
  uint8_T EVCC_VersionResult_Va;
                               // Referenced by: '<Root>/EVCC_VersionResult_Va'
  uint8_T LM_EVCC_Data_Va[8];         // Referenced by: '<S62>/LM_EVCC_Data_Va'
  uint8_T PGI02;                       // Referenced by: '<Root>/PGI02'
  uint8_T PGI02_check_Va;             // Referenced by: '<Root>/PGI02_check_Va'
  uint8_T PGI04_Data[8];               // Referenced by: '<Root>/PGI04_Data'
  uint8_T PGI06;                       // Referenced by: '<Root>/PGI06'
  uint8_T PGI06_K5_Va;                 // Referenced by: '<Root>/PGI06_K5_Va'
  uint8_T PGI06_K6_Va;                 // Referenced by: '<Root>/PGI06_K6_Va'
  uint8_T PGI09;                       // Referenced by: '<Root>/PGI09'
  uint8_T PGI09_wakeup_Va;           // Referenced by: '<Root>/PGI09_wakeup_Va'
  uint8_T PGI12;                       // Referenced by: '<Root>/PGI12'
  uint8_T PGI12_Authentic_Va;     // Referenced by: '<Root>/PGI12_Authentic_Va'
  uint8_T PGI12_EndOfCharge;       // Referenced by: '<Root>/PGI12_EndOfCharge'
  uint8_T PGI12_OutLoopDete;       // Referenced by: '<Root>/PGI12_OutLoopDete'
  uint8_T PGI12_ParmCfg;               // Referenced by: '<Root>/PGI12_ParmCfg'
  uint8_T PGI12_PowerMode;           // Referenced by: '<Root>/PGI12_PowerMode'
  uint8_T PGI12_PreChgEnTrans;   // Referenced by: '<Root>/PGI12_PreChgEnTrans'
  uint8_T PGI12_Scheduled;           // Referenced by: '<Root>/PGI12_Scheduled'
  uint8_T PGI22;                       // Referenced by: '<Root>/PGI22'
  uint8_T PGI22_BatteryType;       // Referenced by: '<Root>/PGI22_BatteryType'
  uint8_T PGI22_RestartNum;         // Referenced by: '<Root>/PGI22_RestartNum'
  uint8_T PGI32;                       // Referenced by: '<Root>/PGI32'
  uint8_T PGI52;                       // Referenced by: '<Root>/PGI52'
  uint8_T PGI52_CheckState_Va;   // Referenced by: '<Root>/PGI52_CheckState_Va'
  uint8_T PGI72;                       // Referenced by: '<Root>/PGI72'
  uint8_T PGI72_EVCCReady_Va;     // Referenced by: '<Root>/PGI72_EVCCReady_Va'
  uint8_T PGI73;                       // Referenced by: '<Root>/PGI73'
  uint8_T PGI73_PowerMode_Va;     // Referenced by: '<Root>/PGI73_PowerMode_Va'
  uint8_T PGI74;                       // Referenced by: '<Root>/PGI4'
  uint8_T PGI77;                       // Referenced by: '<Root>/PGI77'
  uint8_T PGI79;                       // Referenced by: '<Root>/PGI79'
  uint8_T PGI79_Pause_Va;             // Referenced by: '<Root>/PGI79_Pause_Va'
  uint8_T PGI91;                       // Referenced by: '<Root>/PGI91'
  uint8_T PGI91_EVCCDetectSta_Va;
                              // Referenced by: '<Root>/PGI91_EVCCDetectSta_Va'
  uint8_T PGI94;                       // Referenced by: '<Root>/PGI94'
  uint8_T SM_RM_EVCC_Data_Va[8];   // Referenced by: '<S62>/SM_RM_EVCC_Data_Va'
  uint8_T SM_URM_EVCC_Data_Va[8]; // Referenced by: '<S62>/SM_URM_EVCC_Data_Va'
  uint8_T VC_EVCC_Data_Va[8];         // Referenced by: '<S62>/VC_EVCC_Data_Va'
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
  // Block states (default storage) for system '<S62>/sendCyclic'
  struct DW_sendCyclic_QC2015P_EVCC_T {
    real_T cnt;                        // '<S62>/sendCyclic'
    uint8_T is_active_c4_QC2015P_EVCC; // '<S62>/sendCyclic'
    uint8_T is_c4_QC2015P_EVCC;        // '<S62>/sendCyclic'
  };

  // Block states (default storage) for system '<Root>/keep50ms1'
  struct DW_keep50ms1_QC2015P_EVCC_T {
    uint8_T is_active_c21_QC2015P_EVCC;// '<Root>/keep50ms1'
    uint8_T is_c21_QC2015P_EVCC;       // '<Root>/keep50ms1'
    uint8_T temporalCounter_i1;        // '<Root>/keep50ms1'
  };

  // Block states (default storage) for system '<Root>/normal1'
  struct DW_normal1_QC2015P_EVCC_T {
    real_T cnt;                        // '<Root>/normal1'
    uint8_T is_active_c24_QC2015P_EVCC;// '<Root>/normal1'
    uint8_T is_c24_QC2015P_EVCC;       // '<Root>/normal1'
  };

  // Block states (default storage) for system '<Root>/normal1000_50for3'
  struct DW_normal1000_50for3_QC2015P__T {
    real_T times;                      // '<Root>/normal1000_50for3'
    real_T cnt;                        // '<Root>/normal1000_50for3'
    uint8_T is_active_c19_QC2015P_EVCC;// '<Root>/normal1000_50for3'
    uint8_T is_c19_QC2015P_EVCC;       // '<Root>/normal1000_50for3'
  };

  // Block signals (default storage)
  struct B_QC2015P_EVCC_T {
    CAN_FD_MESSAGE_BUS CANFDPacK5;     // '<Root>/CAN FD PacK5'
    CAN_FD_MESSAGE_BUS CANFDPack;      // '<Root>/CAN FD Pack'
    CAN_MSG_BUS Switch;                // '<S88>/Switch'
    CAN_MSG_BUS Switch_l;              // '<S92>/Switch'
    CAN_MSG_BUS Switch_p;              // '<S90>/Switch'
    CAN_MSG_BUS Switch_lw;             // '<S91>/Switch'
    CAN_MSG_BUS Switch_b;              // '<S89>/Switch'
    CAN_MESSAGE_BUS CANPack;           // '<S62>/CAN Pack'
    CAN_MESSAGE_BUS CANPack1;          // '<S62>/CAN Pack1'
    CAN_MESSAGE_BUS CANPack2;          // '<S62>/CAN Pack2'
    CAN_MESSAGE_BUS CANPack3;          // '<S62>/CAN Pack3'
    CAN_MESSAGE_BUS CANPack4;          // '<S62>/CAN Pack4'
    real_T PGI01_FC;                   // '<S56>/CAN Unpack5'
    real_T PGI01_FDC;                  // '<S56>/CAN Unpack5'
    real_T PGI03_STOP_reason0;         // '<S56>/CAN Unpack5'
    real_T PGI03_STOP_reason1;         // '<S56>/CAN Unpack5'
    real_T PGI03_STOP_type;            // '<S56>/CAN Unpack5'
    real_T PGI03_reLink;               // '<S56>/CAN Unpack5'
    real_T PGI08_wakeup;               // '<S56>/CAN Unpack5'
    real_T PGI33_AuthenResult;         // '<S56>/CAN Unpack5'
    real_T PGI33_SAuthenFDC;           // '<S56>/CAN Unpack5'
    real_T PGI35_AuthenResult;         // '<S56>/CAN Unpack5'
    real_T PGI35_SAuthenFDC;           // '<S56>/CAN Unpack5'
    real_T PGI39_AuthenResult;         // '<S56>/CAN Unpack5'
    real_T PGI39_SAuthenFDC;           // '<S56>/CAN Unpack5'
    real_T PGI78_Pause;                // '<S56>/CAN Unpack5'
    real_T PGI93_ChargePower;          // '<S56>/CAN Unpack5'
    real_T PGI93_DishargePower;        // '<S56>/CAN Unpack5'
    real_T S_SECC_PGI;                 // '<S56>/CAN Unpack5'
    real_T SECC_CANType;               // '<S56>/CAN Unpack2'
    real_T SECC_CPVersoin;             // '<S56>/CAN Unpack2'
    real_T SECC_ProtocolVersion0;      // '<S56>/CAN Unpack2'
    real_T SECC_ProtocolVersion1;      // '<S56>/CAN Unpack2'
    real_T SECC_ProtocolVersion2;      // '<S56>/CAN Unpack2'
    real_T SECC_Reserved;              // '<S56>/CAN Unpack2'
    real_T SECC_TLVersion;             // '<S56>/CAN Unpack2'
    real_T SECC_VersionResult;         // '<S56>/CAN Unpack2'
    real_T Ctrl_SECC_Byte0;            // '<S56>/CAN Unpack8'
    real_T confirmPGI;                 // '<S56>/CAN Unpack8'
    real_T recvedByteTotal;            // '<S56>/CAN Unpack8'
    real_T recvedNumTotal;             // '<S56>/CAN Unpack8'
    real_T waitRecvNumStart;           // '<S56>/CAN Unpack8'
    real_T waitRecvNumTotal;           // '<S56>/CAN Unpack8'
    real_T PGI05_K1;                   // '<S56>/CAN Unpack6'
    real_T PGI05_K2;                   // '<S56>/CAN Unpack6'
    real_T PGI07_ELock;                // '<S56>/CAN Unpack6'
    real_T PGI31_CAuthenStatus;        // '<S56>/CAN Unpack6'
    real_T PGI31_MTime2;               // '<S56>/CAN Unpack6'
    real_T PGI51_DetectTest;           // '<S56>/CAN Unpack6'
    real_T PGI51_Discharge;            // '<S56>/CAN Unpack6'
    real_T PGI51_Insulation;           // '<S56>/CAN Unpack6'
    real_T PGI51_ShortCircuit;         // '<S56>/CAN Unpack6'
    real_T PGI71_ChargerReady;         // '<S56>/CAN Unpack6'
    real_T PGI75_MaxOutput_A;          // '<S56>/CAN Unpack6'
    real_T PGI75_OutputChangeReason;   // '<S56>/CAN Unpack6'
    real_T PGI76_A_Exe;                // '<S56>/CAN Unpack6'
    real_T PGI76_V_Exe;                // '<S56>/CAN Unpack6'
    real_T PGI92_AllowDetectCheck;     // '<S56>/CAN Unpack6'
    real_T SU_SECC_PGI;                // '<S56>/CAN Unpack6'
    real_T CANFDUnpack_o1;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o2;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o3;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o4;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o5;             // '<Root>/CAN FD Unpack'
    real_T CANFDUnpack_o6;             // '<Root>/CAN FD Unpack'
    real_T Switch3;                    // '<Root>/Switch3'
    real_T enable_e;                   // '<Root>/normal250_3'
    real_T enable_d;                   // '<Root>/normal1000_50for3_'
    real_T enable_o;                   // '<Root>/normal1000_50for3'
    real_T enable_a;                   // '<Root>/normal1000'
    real_T enable_g;                   // '<Root>/normal1'
    real_T outPGI;                     // '<Root>/keep1_for10ms'
    real_T outNextStep;                // '<Root>/VN'
    real_T VersionResult;              // '<Root>/VN'
    real_T VN_Enable;                  // '<Root>/VN'
    real_T enable_af;                  // '<S62>/sendCyclic4'
    real_T enable_f;                   // '<S62>/sendCyclic3'
    real_T enable_m;                   // '<S62>/sendCyclic2'
    real_T enable_a4;                  // '<S62>/sendCyclic1'
    real_T enable_h;                   // '<S62>/sendCyclic'
    real_T DetectAllow;                // '<Root>/QC2015P_STOP'
    real_T RelinkAllow;                // '<Root>/QC2015P_STOP'
    real_T RebootAllow;                // '<Root>/QC2015P_STOP'
    real_T SEQ;                        // '<Root>/QC2015P_MAIN'
    real_T ReStart;                    // '<Root>/QC2015P_MAIN'
    real_T PGI73_V;                    // '<Root>/QC2015P_MAIN'
    real_T PGI73_A;                    // '<Root>/QC2015P_MAIN'
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
    real_T sendFlg_h;                  // '<Root>/LM_Recv'
    real_T n_num_i;                    // '<Root>/LM_Recv'
    real_T k_num;                      // '<Root>/LM_Recv'
    real_T recv_tfra;                  // '<Root>/LM_Recv'
    real_T totalBytes;                 // '<Root>/LM_Recv'
    uint32_T LocalVersion;             // '<Root>/VN'
    uint8_T RX_Status;                 // '<S56>/CAN Unpack5'
    uint8_T RX_Status_m;               // '<S56>/CAN Unpack2'
    uint8_T Data[8];                   // '<S56>/CAN Unpack9'
    uint8_T RX_Status_l;               // '<S56>/CAN Unpack9'
    uint8_T RX_Status_mu;              // '<S56>/CAN Unpack8'
    uint8_T RX_Status_n;               // '<S56>/CAN Unpack6'
    uint8_T Switch44[12];              // '<Root>/Switch44'
    uint8_T Switch5[8];                // '<S62>/Switch5'
    uint8_T Switch8[8];                // '<S62>/Switch8'
    uint8_T Switch10[8];               // '<S62>/Switch10'
    uint8_T Switch12[8];               // '<S62>/Switch12'
    uint8_T Switch14[8];               // '<S62>/Switch14'
    uint8_T PGI_Enable[255];           // '<Root>/QC2015P_MAIN'
    uint8_T Data_PGI04[8];             // '<Root>/QC2015P_MAIN'
    uint8_T K5;                        // '<Root>/QC2015P_MAIN'
    uint8_T K6;                        // '<Root>/QC2015P_MAIN'
    uint8_T PGI02_check;               // '<Root>/QC2015P_MAIN'
    uint8_T PGI72_EVCCReady;           // '<Root>/QC2015P_MAIN'
    uint8_T PGI91_EVCCDetectSta;       // '<Root>/QC2015P_MAIN'
    uint8_T PGI09_wakeup;              // '<Root>/QC2015P_MAIN'
    uint8_T PGI52_CheckState;          // '<Root>/QC2015P_MAIN'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_QC2015P_EVCC_T {
    real_T UnitDelay1_DSTATE;          // '<Root>/Unit Delay1'
    real_T UnitDelay16_DSTATE;         // '<Root>/Unit Delay16'
    real_T UnitDelay17_DSTATE;         // '<Root>/Unit Delay17'
    real_T UnitDelay12_DSTATE;         // '<Root>/Unit Delay12'
    real_T UnitDelay13_DSTATE;         // '<Root>/Unit Delay13'
    real_T UnitDelay11_DSTATE;         // '<Root>/Unit Delay11'
    real_T UnitDelay15_DSTATE;         // '<Root>/Unit Delay15'
    real_T UnitDelay_DSTATE;           // '<S61>/Unit Delay'
    real_T DiscreteTimeIntegrator1_DSTATE;// '<S61>/Discrete-Time Integrator1'
    real_T UnitDelay6_DSTATE;          // '<Root>/Unit Delay6'
    real_T UnitDelay10_DSTATE;         // '<Root>/Unit Delay10'
    real_T UnitDelay8_DSTATE;          // '<Root>/Unit Delay8'
    real_T cnt;                        // '<Root>/normal250_3'
    real_T Ns;                         // '<Root>/VN'
    real_T Tout0;                      // '<Root>/VN'
    real_T NextStep;                   // '<Root>/VN'
    real_T timeOut;                    // '<Root>/QC2015P_MAIN'
    real_T timer;                      // '<Root>/QC2015P_MAIN'
    real_T PauseCNT;                   // '<Root>/QC2015P_MAIN'
    real_T T1;                         // '<Root>/QC2015P_MAIN'
    real_T T2;                         // '<Root>/QC2015P_MAIN'
    real_T PGI33_Flg;                  // '<Root>/QC2015P_MAIN'
    real_T timer_d;                    // '<Root>/MAIN_CNT'
    real_T err_cnt;                    // '<Root>/LM_Send'
    real_T LMS_T1;                     // '<Root>/LM_Send'
    real_T local_n;                    // '<Root>/LM_Send'
    real_T LMS_T3;                     // '<Root>/LM_Send'
    real_T LMS_T2;                     // '<Root>/LM_Send'
    real_T local_k;                    // '<Root>/LM_Send'
    real_T send_cnt;                   // '<Root>/LM_Send'
    real_T recv_no;                    // '<Root>/LM_Recv'
    real_T LMS_T2_i;                   // '<Root>/LM_Recv'
    real_T err_cnt_b;                  // '<Root>/LM_Recv'
    real_T LMS_T3_f;                   // '<Root>/LM_Recv'
    real_T lm_tfra;                    // '<Root>/LM_Recv'
    real_T recv_num;                   // '<Root>/LM_Recv'
    real_T totalBytes;                 // '<Root>/AnalysisLM'
    real_T lm_tfra_o;                  // '<Root>/AnalysisLM'
    real_T tmpLists[64];               // '<Root>/AnalysisLM'
    real_T tmpCnt;                     // '<Root>/AnalysisLM'
    int_T CANUnpack5_ModeSignalID;     // '<S56>/CAN Unpack5'
    int_T CANUnpack5_StatusPortID;     // '<S56>/CAN Unpack5'
    int_T CANUnpack2_ModeSignalID;     // '<S56>/CAN Unpack2'
    int_T CANUnpack2_StatusPortID;     // '<S56>/CAN Unpack2'
    int_T CANUnpack9_ModeSignalID;     // '<S56>/CAN Unpack9'
    int_T CANUnpack9_StatusPortID;     // '<S56>/CAN Unpack9'
    int_T CANUnpack8_ModeSignalID;     // '<S56>/CAN Unpack8'
    int_T CANUnpack8_StatusPortID;     // '<S56>/CAN Unpack8'
    int_T CANUnpack6_ModeSignalID;     // '<S56>/CAN Unpack6'
    int_T CANUnpack6_StatusPortID;     // '<S56>/CAN Unpack6'
    int_T CANFDUnpack_ModeSignalID;    // '<Root>/CAN FD Unpack'
    int_T CANFDUnpack_StatusPortID;    // '<Root>/CAN FD Unpack'
    int_T CANFDPack_ModeSignalID;      // '<Root>/CAN FD Pack'
    uint16_T temporalCounter_i1;       // '<Root>/keep1_for10000ms3'
    uint16_T temporalCounter_i1_k;     // '<Root>/QC2015P_MAIN'
    uint16_T temporalCounter_i2;       // '<Root>/QC2015P_MAIN'
    uint16_T temporalCounter_i3;       // '<Root>/QC2015P_MAIN'
    uint8_T UnitDelay9_DSTATE[255];    // '<Root>/Unit Delay9'
    uint8_T UnitDelay7_DSTATE;         // '<Root>/Unit Delay7'
    uint8_T UnitDelay3_DSTATE[8];      // '<Root>/Unit Delay3'
    uint8_T UnitDelay2_DSTATE[8];      // '<Root>/Unit Delay2'
    boolean_T UnitDelay_DSTATE_m;      // '<Root>/Unit Delay'
    boolean_T UnitDelay5_DSTATE;       // '<Root>/Unit Delay5'
    boolean_T UnitDelay19_DSTATE;      // '<Root>/Unit Delay19'
    int8_T DiscreteTimeIntegrator1_PrevRes;// '<S61>/Discrete-Time Integrator1'
    uint8_T is_active_c2_QC2015P_EVCC; // '<Root>/normal250_3'
    uint8_T is_c2_QC2015P_EVCC;        // '<Root>/normal250_3'
    uint8_T is_active_c28_QC2015P_EVCC;// '<Root>/keep1_for50ms'
    uint8_T is_c28_QC2015P_EVCC;       // '<Root>/keep1_for50ms'
    uint8_T temporalCounter_i1_m;      // '<Root>/keep1_for50ms'
    uint8_T is_active_c26_QC2015P_EVCC;// '<Root>/keep1_for10ms1'
    uint8_T is_c26_QC2015P_EVCC;       // '<Root>/keep1_for10ms1'
    uint8_T temporalCounter_i1_kr;     // '<Root>/keep1_for10ms1'
    uint8_T is_active_c25_QC2015P_EVCC;// '<Root>/keep1_for10ms'
    uint8_T is_c25_QC2015P_EVCC;       // '<Root>/keep1_for10ms'
    uint8_T temporalCounter_i1_i;      // '<Root>/keep1_for10ms'
    uint8_T is_active_c30_QC2015P_EVCC;// '<Root>/keep1_for10000ms3'
    uint8_T is_c30_QC2015P_EVCC;       // '<Root>/keep1_for10000ms3'
    uint8_T is_active_c9_QC2015P_EVCC; // '<Root>/VN'
    uint8_T is_c9_QC2015P_EVCC;        // '<Root>/VN'
    uint8_T temporalCounter_i1_n;      // '<Root>/VN'
    uint8_T is_active_c10_QC2015P_EVCC;// '<Root>/QC2015P_STOP'
    uint8_T is_c10_QC2015P_EVCC;       // '<Root>/QC2015P_STOP'
    uint8_T is_active_c18_QC2015P_EVCC;// '<Root>/QC2015P_MAIN'
    uint8_T is_c18_QC2015P_EVCC;       // '<Root>/QC2015P_MAIN'
    uint8_T is_QC2015P;                // '<Root>/QC2015P_MAIN'
    uint8_T is_End;                    // '<Root>/QC2015P_MAIN'
    uint8_T is_Checking;               // '<Root>/QC2015P_MAIN'
    uint8_T is_S4;                     // '<Root>/QC2015P_MAIN'
    uint8_T is_Send_PGI91;             // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start;               // '<Root>/QC2015P_MAIN'
    uint8_T is_QC2015P_BeforeEnd;      // '<Root>/QC2015P_MAIN'
    uint8_T is_Authentic;              // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start_d;             // '<Root>/QC2015P_MAIN'
    uint8_T is_Wait_PGI31_Send_PGI32;  // '<Root>/QC2015P_MAIN'
    uint8_T is_FN;                     // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start_f;             // '<Root>/QC2015P_MAIN'
    uint8_T is_OutLoopDete;            // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start_p;             // '<Root>/QC2015P_MAIN'
    uint8_T is_ParmCfg;                // '<Root>/QC2015P_MAIN'
    uint8_T is_FC_Start_a;             // '<Root>/QC2015P_MAIN'
    uint8_T is_PreChgEnTrans;          // '<Root>/QC2015P_MAIN'
    uint8_T is_EnTrans;                // '<Root>/QC2015P_MAIN'
    uint8_T is_PreChg;                 // '<Root>/QC2015P_MAIN'
    uint8_T is_ReLink_Reboot;          // '<Root>/QC2015P_MAIN'
    uint8_T is_Rebooting;              // '<Root>/QC2015P_MAIN'
    uint8_T is_active_c3_QC2015P_EVCC; // '<Root>/MAIN_CNT'
    uint8_T is_c3_QC2015P_EVCC;        // '<Root>/MAIN_CNT'
    uint8_T is_active_c15_QC2015P_EVCC;// '<Root>/LM_Send'
    uint8_T is_c15_QC2015P_EVCC;       // '<Root>/LM_Send'
    uint8_T is_S1_S4;                  // '<Root>/LM_Send'
    uint8_T temporalCounter_i1_m5;     // '<Root>/LM_Send'
    uint8_T is_active_c11_QC2015P_EVCC;// '<Root>/LM_Recv'
    uint8_T is_c11_QC2015P_EVCC;       // '<Root>/LM_Recv'
    uint8_T is_S1;                     // '<Root>/LM_Recv'
    uint8_T temporalCounter_i1_o;      // '<Root>/LM_Recv'
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3_;// '<Root>/normal1000_50for3_' 
    DW_normal1000_50for3_QC2015P__T sf_normal1000_50for3;// '<Root>/normal1000_50for3' 
    DW_normal1_QC2015P_EVCC_T sf_normal1000;// '<Root>/normal1000'
    DW_normal1_QC2015P_EVCC_T sf_normal1;// '<Root>/normal1'
    DW_keep50ms1_QC2015P_EVCC_T sf_keep50ms2;// '<Root>/keep50ms2'
    DW_keep50ms1_QC2015P_EVCC_T sf_keep50ms1;// '<Root>/keep50ms1'
    DW_sendCyclic_QC2015P_EVCC_T sf_sendCyclic4;// '<S62>/sendCyclic4'
    DW_sendCyclic_QC2015P_EVCC_T sf_sendCyclic3;// '<S62>/sendCyclic3'
    DW_sendCyclic_QC2015P_EVCC_T sf_sendCyclic2;// '<S62>/sendCyclic2'
    DW_sendCyclic_QC2015P_EVCC_T sf_sendCyclic1;// '<S62>/sendCyclic1'
    DW_sendCyclic_QC2015P_EVCC_T sf_sendCyclic;// '<S62>/sendCyclic'
  };

  // Constant parameters (default storage)
  struct ConstP_QC2015P_EVCC_T {
    // Expression: [2, 255, 255, 255, 255, 255, 255, 255]
    //  Referenced by: '<Root>/LM_NACK'

    real_T LM_NACK_Value[8];

    // Expression: [0,1,3,0xFF,0xFF,0xFF,0xFF,0xFF]
    //  Referenced by: '<Root>/Constant50'

    uint8_T Constant50_Value[8];

    // Expression: [4,1,3,2,0xFF,0xFF,0xFF,0xFF]
    //  Referenced by: '<Root>/Constant64'

    uint8_T Constant64_Value[8];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_QC2015P_EVCC_T {
    CAN_MSG_Array MsgInput;            // '<Root>/MsgInput'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_QC2015P_EVCC_T {
    CAN_MESSAGE_BUS Msg_Send[5];       // '<Root>/Msg_Send'
    UserMonitor_EVCC UserMonitor_EVCC_h;// '<Root>/UserMonitor_EVCC'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_QC2015P_EVCC_T {
    const char_T * volatile errorStatus;
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

  // private member function(s) for subsystem '<Root>/Bit Shift10'
  static void QC2015P_EVCC_BitShift10(uint16_T rtu_u, uint16_T *rty_y);

  // private member function(s) for subsystem '<S62>/sendCyclic'
  static void QC2015P_EVCC_sendCyclic_Init(real_T *rty_enable);
  static void QC2015P_EVCC_sendCyclic(boolean_T rtu_startFlg, real_T
    rtu_cycleTime, real_T *rty_enable, DW_sendCyclic_QC2015P_EVCC_T *localDW);

  // private member function(s) for subsystem '<Root>/keep50ms1'
  static void QC2015P_EVCC_keep50ms1_Init(real_T *rty_out);
  static void QC2015P_EVCC_keep50ms1(boolean_T rtu_rawIn, real_T *rty_out,
    DW_keep50ms1_QC2015P_EVCC_T *localDW);

  // private member function(s) for subsystem '<Root>/normal1'
  static void QC2015P_EVCC_normal1_Init(real_T *rty_enable);
  static void QC2015P_EVCC_normal1(boolean_T rtu_rawCycle, real_T *rty_enable,
    DW_normal1_QC2015P_EVCC_T *localDW);

  // private member function(s) for subsystem '<Root>/normal1000_50for3'
  static void QC2015P__normal1000_50for3_Init(real_T *rty_enable);
  static void QC2015P_EVCC_normal1000_50for3(boolean_T rtu_rawCycle, boolean_T
    rtu_startFlg, real_T *rty_enable, DW_normal1000_50for3_QC2015P__T *localDW);

  // private member function(s) for subsystem '<Root>'
  real_T QC2015P_EVCC_mod(real_T x);
  real_T QC2015P_EVCC_mod_b(real_T x);
  void QC2015P_EVCC_enter_atomic_init(void);
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
  void QC2015P_EV_enter_atomic_init_S0(void);
  void enter_atomic_S0_init_or_S2_fini(void);
  void QC2015P_EVCC_S1(const real_T DataTypeConversion5[8], const boolean_T
                       *LogicalOperator4);

  // Real-Time Model
  RT_MODEL_QC2015P_EVCC_T QC2015P_EVCC_M;
};

// Constant parameters (default storage)
extern const QC2015P_EVCC::ConstP_QC2015P_EVCC_T QC2015P_EVCC_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Constant26' : Unused code path elimination
//  Block '<Root>/Constant28' : Unused code path elimination
//  Block '<Root>/Constant29' : Unused code path elimination
//  Block '<Root>/Constant32' : Unused code path elimination
//  Block '<Root>/Constant33' : Unused code path elimination
//  Block '<Root>/Constant36' : Unused code path elimination
//  Block '<Root>/Constant37' : Unused code path elimination
//  Block '<Root>/Constant63' : Unused code path elimination
//  Block '<Root>/Min of Elements3' : Unused code path elimination
//  Block '<Root>/Selector14' : Unused code path elimination
//  Block '<Root>/Selector20' : Unused code path elimination
//  Block '<Root>/Selector21' : Unused code path elimination
//  Block '<Root>/Selector23' : Unused code path elimination
//  Block '<Root>/Selector25' : Unused code path elimination
//  Block '<Root>/Selector26' : Unused code path elimination
//  Block '<Root>/Selector27' : Unused code path elimination
//  Block '<Root>/Switch51' : Unused code path elimination
//  Block '<Root>/Unit Delay14' : Unused code path elimination
//  Block '<Root>/Data Type Conversion7' : Eliminate redundant data type conversion


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
//  '<S1>'   : 'QC2015P_EVCC/AnalysisLM'
//  '<S2>'   : 'QC2015P_EVCC/Bit Shift'
//  '<S3>'   : 'QC2015P_EVCC/Bit Shift1'
//  '<S4>'   : 'QC2015P_EVCC/Bit Shift10'
//  '<S5>'   : 'QC2015P_EVCC/Bit Shift11'
//  '<S6>'   : 'QC2015P_EVCC/Bit Shift2'
//  '<S7>'   : 'QC2015P_EVCC/Bit Shift3'
//  '<S8>'   : 'QC2015P_EVCC/Bit Shift4'
//  '<S9>'   : 'QC2015P_EVCC/Bit Shift5'
//  '<S10>'  : 'QC2015P_EVCC/Bit Shift6'
//  '<S11>'  : 'QC2015P_EVCC/Bit Shift7'
//  '<S12>'  : 'QC2015P_EVCC/Bit Shift8'
//  '<S13>'  : 'QC2015P_EVCC/Bit Shift9'
//  '<S14>'  : 'QC2015P_EVCC/Compare To Constant'
//  '<S15>'  : 'QC2015P_EVCC/Compare To Constant1'
//  '<S16>'  : 'QC2015P_EVCC/Compare To Constant11'
//  '<S17>'  : 'QC2015P_EVCC/Compare To Constant12'
//  '<S18>'  : 'QC2015P_EVCC/Compare To Constant13'
//  '<S19>'  : 'QC2015P_EVCC/Compare To Constant14'
//  '<S20>'  : 'QC2015P_EVCC/Compare To Constant15'
//  '<S21>'  : 'QC2015P_EVCC/Compare To Constant16'
//  '<S22>'  : 'QC2015P_EVCC/Compare To Constant17'
//  '<S23>'  : 'QC2015P_EVCC/Compare To Constant18'
//  '<S24>'  : 'QC2015P_EVCC/Compare To Constant19'
//  '<S25>'  : 'QC2015P_EVCC/Compare To Constant2'
//  '<S26>'  : 'QC2015P_EVCC/Compare To Constant20'
//  '<S27>'  : 'QC2015P_EVCC/Compare To Constant21'
//  '<S28>'  : 'QC2015P_EVCC/Compare To Constant22'
//  '<S29>'  : 'QC2015P_EVCC/Compare To Constant23'
//  '<S30>'  : 'QC2015P_EVCC/Compare To Constant27'
//  '<S31>'  : 'QC2015P_EVCC/Compare To Constant28'
//  '<S32>'  : 'QC2015P_EVCC/Compare To Constant29'
//  '<S33>'  : 'QC2015P_EVCC/Compare To Constant3'
//  '<S34>'  : 'QC2015P_EVCC/Compare To Constant30'
//  '<S35>'  : 'QC2015P_EVCC/Compare To Constant31'
//  '<S36>'  : 'QC2015P_EVCC/Compare To Constant32'
//  '<S37>'  : 'QC2015P_EVCC/Compare To Constant33'
//  '<S38>'  : 'QC2015P_EVCC/Compare To Constant34'
//  '<S39>'  : 'QC2015P_EVCC/Compare To Constant35'
//  '<S40>'  : 'QC2015P_EVCC/Compare To Constant36'
//  '<S41>'  : 'QC2015P_EVCC/Compare To Constant37'
//  '<S42>'  : 'QC2015P_EVCC/Compare To Constant38'
//  '<S43>'  : 'QC2015P_EVCC/Compare To Constant39'
//  '<S44>'  : 'QC2015P_EVCC/Compare To Constant4'
//  '<S45>'  : 'QC2015P_EVCC/Compare To Constant41'
//  '<S46>'  : 'QC2015P_EVCC/Compare To Constant5'
//  '<S47>'  : 'QC2015P_EVCC/Compare To Constant6'
//  '<S48>'  : 'QC2015P_EVCC/Compare To Constant7'
//  '<S49>'  : 'QC2015P_EVCC/Compare To Constant8'
//  '<S50>'  : 'QC2015P_EVCC/Compare To Constant9'
//  '<S51>'  : 'QC2015P_EVCC/LM_Recv'
//  '<S52>'  : 'QC2015P_EVCC/LM_Send'
//  '<S53>'  : 'QC2015P_EVCC/MAIN_CNT'
//  '<S54>'  : 'QC2015P_EVCC/MATLAB Function'
//  '<S55>'  : 'QC2015P_EVCC/MATLAB Function1'
//  '<S56>'  : 'QC2015P_EVCC/Msg_Recv'
//  '<S57>'  : 'QC2015P_EVCC/PACK_LM'
//  '<S58>'  : 'QC2015P_EVCC/Pack_LM_ACK'
//  '<S59>'  : 'QC2015P_EVCC/QC2015P_MAIN'
//  '<S60>'  : 'QC2015P_EVCC/QC2015P_STOP'
//  '<S61>'  : 'QC2015P_EVCC/SOC'
//  '<S62>'  : 'QC2015P_EVCC/Subsystem'
//  '<S63>'  : 'QC2015P_EVCC/VN'
//  '<S64>'  : 'QC2015P_EVCC/get_lm_tfra'
//  '<S65>'  : 'QC2015P_EVCC/keep1_for10000ms3'
//  '<S66>'  : 'QC2015P_EVCC/keep1_for10ms'
//  '<S67>'  : 'QC2015P_EVCC/keep1_for10ms1'
//  '<S68>'  : 'QC2015P_EVCC/keep1_for50ms'
//  '<S69>'  : 'QC2015P_EVCC/keep50ms1'
//  '<S70>'  : 'QC2015P_EVCC/keep50ms2'
//  '<S71>'  : 'QC2015P_EVCC/normal1'
//  '<S72>'  : 'QC2015P_EVCC/normal1000'
//  '<S73>'  : 'QC2015P_EVCC/normal1000_50for3'
//  '<S74>'  : 'QC2015P_EVCC/normal1000_50for3_'
//  '<S75>'  : 'QC2015P_EVCC/normal250_3'
//  '<S76>'  : 'QC2015P_EVCC/Bit Shift/bit_shift'
//  '<S77>'  : 'QC2015P_EVCC/Bit Shift1/bit_shift'
//  '<S78>'  : 'QC2015P_EVCC/Bit Shift10/bit_shift'
//  '<S79>'  : 'QC2015P_EVCC/Bit Shift11/bit_shift'
//  '<S80>'  : 'QC2015P_EVCC/Bit Shift2/bit_shift'
//  '<S81>'  : 'QC2015P_EVCC/Bit Shift3/bit_shift'
//  '<S82>'  : 'QC2015P_EVCC/Bit Shift4/bit_shift'
//  '<S83>'  : 'QC2015P_EVCC/Bit Shift5/bit_shift'
//  '<S84>'  : 'QC2015P_EVCC/Bit Shift6/bit_shift'
//  '<S85>'  : 'QC2015P_EVCC/Bit Shift7/bit_shift'
//  '<S86>'  : 'QC2015P_EVCC/Bit Shift8/bit_shift'
//  '<S87>'  : 'QC2015P_EVCC/Bit Shift9/bit_shift'
//  '<S88>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect'
//  '<S89>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect1'
//  '<S90>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect2'
//  '<S91>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect3'
//  '<S92>'  : 'QC2015P_EVCC/Msg_Recv/MsgSelect4'
//  '<S93>'  : 'QC2015P_EVCC/Subsystem/sendCyclic'
//  '<S94>'  : 'QC2015P_EVCC/Subsystem/sendCyclic1'
//  '<S95>'  : 'QC2015P_EVCC/Subsystem/sendCyclic2'
//  '<S96>'  : 'QC2015P_EVCC/Subsystem/sendCyclic3'
//  '<S97>'  : 'QC2015P_EVCC/Subsystem/sendCyclic4'

#endif                                 // RTW_HEADER_QC2015P_EVCC_h_

//
// File trailer for generated code.
//
// [EOF]
//
