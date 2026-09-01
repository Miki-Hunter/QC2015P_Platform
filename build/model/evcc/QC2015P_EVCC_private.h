//
// File: QC2015P_EVCC_private.h
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
#ifndef RTW_HEADER_QC2015P_EVCC_private_h_
#define RTW_HEADER_QC2015P_EVCC_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "QC2015P_EVCC_types.h"
#include "QC2015P_EVCC.h"

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern void MultiWordIor(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
  int32_T n);
extern void Double2MultiWord(real_T u1, uint32_T y[], int32_T n);
extern void uMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);

#endif                                 // RTW_HEADER_QC2015P_EVCC_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
