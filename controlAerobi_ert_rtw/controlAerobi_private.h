//
// File: controlAerobi_private.h
//
// Code generated for Simulink model 'controlAerobi'.
//
// Model version                  : 1.2418
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Thu Jul  5 16:05:22 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives:
//    1. Execution efficiency
//    2. ROM efficiency
//    3. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_controlAerobi_private_h_
#define RTW_HEADER_controlAerobi_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "controlAerobi.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void controlAerobi_CreatedXYdesired(real_T rtu_yaw, real_T rtu_chan2,
  real_T rtu_chan3, rtB_CreatedXYdesired_controlAer *localB);
extern void controlAero_MATLABFunction_Init(rtDW_MATLABFunction_controlAero
  *localDW);
extern void controlAerobi_MATLABFunction(const real_T rtu_g[3],
  rtB_MATLABFunction_controlAerob *localB, rtDW_MATLABFunction_controlAero
  *localDW);

#endif                                 // RTW_HEADER_controlAerobi_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
