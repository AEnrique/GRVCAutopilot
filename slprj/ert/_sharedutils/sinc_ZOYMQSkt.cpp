//
// File: sinc_ZOYMQSkt.cpp
//
// Code generated for Simulink model 'controlAerobi'.
//
// Model version                  : 1.2412
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Wed Jul  4 13:33:52 2018
//
#include "rtwtypes.h"
#include <math.h>
#include "sinc_ZOYMQSkt.h"

// Function for MATLAB Function: '<S106>/TGIC_fcn'
void sinc_ZOYMQSkt(real_T *x)
{
  if (fabs(*x) < 1.0020841800044864E-292) {
    *x = 1.0;
  } else {
    *x *= 3.1415926535897931;
    *x = sin(*x) / *x;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
