//
// File: QC2015P_SECC_types.h
//
// Code generated for Simulink model 'QC2015P_SECC'.
//
// Model version                  : 1.567
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sun Sep 27 17:22:00 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_QC2015P_SECC_types_h_
#define RTW_HEADER_QC2015P_SECC_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MESSAGE_BUS_

struct CAN_MESSAGE_BUS
{
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_CAN_FD_MESSAGE_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_FD_MESSAGE_BUS_

struct CAN_FD_MESSAGE_BUS
{
  uint8_T ProtocolMode;
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint8_T BRS;
  uint8_T ESI;
  uint8_T DLC;
  uint32_T ID;
  uint32_T Reserved;
  real_T Timestamp;
  uint8_T Data[64];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_CAN_MSG_BUS_
#define DEFINED_TYPEDEF_FOR_CAN_MSG_BUS_

struct CAN_MSG_BUS
{
  uint8_T Extended;
  uint8_T Length;
  uint8_T Remote;
  uint8_T Error;
  uint32_T ID;
  real_T Timestamp;
  uint8_T Data[8];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_CAN_MSG_Array_
#define DEFINED_TYPEDEF_FOR_CAN_MSG_Array_

// Array of 5 CAN_MSG_BUS elements
struct CAN_MSG_Array
{
  CAN_MSG_BUS CAN_MSG_1;
  CAN_MSG_BUS CAN_MSG_2;
  CAN_MSG_BUS CAN_MSG_3;
  CAN_MSG_BUS CAN_MSG_4;
  CAN_MSG_BUS CAN_MSG_5;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_UserMonitor_SECC_
#define DEFINED_TYPEDEF_FOR_UserMonitor_SECC_

// Bus for UserMonitor
struct UserMonitor_SECC
{
  real_T MAIN_SEQ;
  real_T ChargeCapacity;
  boolean_T RelinkAllow;
  boolean_T RebootAllow;
  boolean_T DetectAllow;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_WCv6ubosP3YfKvVoToJBJ_
#define DEFINED_TYPEDEF_FOR_struct_WCv6ubosP3YfKvVoToJBJ_

struct struct_WCv6ubosP3YfKvVoToJBJ
{
  real_T SEQ;
  real_T ChargeCapacity;
  real_T signal3;
  real_T signal4;
  real_T signal5;
};

#endif
#endif                                 // RTW_HEADER_QC2015P_SECC_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
