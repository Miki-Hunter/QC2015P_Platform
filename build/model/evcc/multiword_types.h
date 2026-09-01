//
// File: multiword_types.h
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

#ifndef MULTIWORD_TYPES_H
#define MULTIWORD_TYPES_H
#include "rtwtypes.h"

//
//  MultiWord supporting definitions
typedef long int long_T;

//
//  MultiWord types
typedef struct {
  uint32_T chunks[2];
} int64m_T;

typedef struct {
  int64m_T re;
  int64m_T im;
} cint64m_T;

typedef struct {
  uint32_T chunks[2];
} uint64m_T;

typedef struct {
  uint64m_T re;
  uint64m_T im;
} cuint64m_T;

#endif                                 // MULTIWORD_TYPES_H

//
// File trailer for generated code.
//
// [EOF]
//
