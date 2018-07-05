//
// File: diag_ZmyGsYYI.cpp
//
// Code generated for Simulink model 'controlAerobi'.
//
// Model version                  : 1.2412
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Wed Jul  4 13:33:52 2018
//
#include "rtwtypes.h"
#include <string.h>
#include "diag_ZmyGsYYI.h"

// Function for MATLAB Function: '<S106>/TGIC_fcn'
void diag_ZmyGsYYI(const real_T v[6], real_T d[36])
{
  int32_T j;
  memset(&d[0], 0, 36U * sizeof(real_T));
  for (j = 0; j < 6; j++) {
    d[j + 6 * j] = v[j];
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
