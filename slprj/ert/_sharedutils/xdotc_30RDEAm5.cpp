//
// File: xdotc_30RDEAm5.cpp
//
// Code generated for Simulink model 'controlAerobi'.
//
// Model version                  : 1.2412
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Wed Jul  4 13:33:52 2018
//
#include "rtwtypes.h"
#include "xdotc_30RDEAm5.h"

// Function for MATLAB Function: '<S106>/TGIC_fcn'
real_T xdotc_30RDEAm5(int32_T n, const real_T x[100], int32_T ix0, const real_T
                      y[100], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (!(n < 1)) {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

//
// File trailer for generated code.
//
// [EOF]
//
