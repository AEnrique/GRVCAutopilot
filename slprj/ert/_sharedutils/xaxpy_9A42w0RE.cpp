//
// File: xaxpy_9A42w0RE.cpp
//
// Code generated for Simulink model 'controlAerobi'.
//
// Model version                  : 1.2412
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Wed Jul  4 13:33:52 2018
//
#include "rtwtypes.h"
#include "xaxpy_9A42w0RE.h"

// Function for MATLAB Function: '<S106>/TGIC_fcn'
void xaxpy_9A42w0RE(int32_T n, real_T a, const real_T x[100], int32_T ix0,
                    real_T y[10], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
