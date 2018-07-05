//
// File: norm_OKjrfDiG.cpp
//
// Code generated for Simulink model 'controlAerobi'.
//
// Model version                  : 1.2412
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Wed Jul  4 13:33:52 2018
//
#include "rtwtypes.h"
#include <math.h>
#include "norm_OKjrfDiG.h"

// Function for MATLAB Function: '<S147>/Embedded MATLAB Function1'
real_T norm_OKjrfDiG(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

//
// File trailer for generated code.
//
// [EOF]
//
