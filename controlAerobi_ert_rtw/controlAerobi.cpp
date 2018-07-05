//
// File: controlAerobi.cpp
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
#include "controlAerobi.h"
#include "controlAerobi_private.h"
#include "controlAerobi_dt.h"
#include "diag_AmkIBh3P.h"
#include "diag_ZmyGsYYI.h"
#include "look1_binlx.h"
#include "norm_5ETDUxto.h"
#include "norm_OKjrfDiG.h"
#include "rt_atan2d_snf.h"
#include "rt_hypotd_snf.h"
#include "sinc_ZOYMQSkt.h"
#include "xaxpy_9A42w0RE.h"
#include "xaxpy_SEOAgeAY.h"
#include "xaxpy_kYK8fEIh.h"
#include "xdotc_30RDEAm5.h"
#include "xnrm2_36Ruq5vk.h"
#include "xnrm2_BcBwAYPM.h"

// Block signals (auto storage)
BlockIO_controlAerobi controlAerobi_B;

// Block states (auto storage)
D_Work_controlAerobi controlAerobi_DWork;

// External inputs (root inport signals with auto storage)
ExternalInputs_controlAerobi controlAerobi_U;

// External outputs (root outports fed by signals with auto storage)
ExternalOutputs_controlAerobi controlAerobi_Y;

// Real-time model
RT_MODEL_controlAerobi controlAerobi_M_;

// Const memory section
RT_MODEL_controlAerobi *const controlAerobi_M = &controlAerobi_M_;

// Forward declaration for local functions
static void controlAerobi_std(const real_T x[30], real_T y[3]);
static void controlAerobi_mrdivide_eK1qdBt4(real_T A[60], const real_T B[36]);
static void controlAerobi_rotation_SYBOT8wI(const real_T q_[4], real_T R[9]);
static real_T controlAerobi_xnrm2_N4q5JsKO(int32_T n, const real_T x[100],
  int32_T ix0);
static real_T controlAerobi_xnrm2_bVkOvwMp(int32_T n, const real_T x[10],
  int32_T ix0);
static void controlAerobi_xrotg_czoXf8gE(real_T *a, real_T *b, real_T *c, real_T
  *s);
static void controlAerobi_svd_NDGo5poy(const real_T A[100], real_T U[10]);
static real_T controlAerobi_norm_0KU7QpIQ(const real_T x[100]);
static void controlAerobi_mrdivide_oxNR4jke(real_T A[8], const real_T B[16]);
static void controlAerobi_mrdivide_TwA5PnsG(real_T A[30], const real_T B[25]);
static void controlAero_mrdivide_oxNR4jke_k(real_T A[8], const real_T B[16]);

//
// Output and update for atomic system:
//    '<S18>/Create dXY desired'
//    '<S58>/Create dXY desired'
//
void controlAerobi_CreatedXYdesired(real_T rtu_yaw, real_T rtu_chan2, real_T
  rtu_chan3, rtB_CreatedXYdesired_controlAer *localB)
{
  real_T dXY_d_tmp;
  real_T dXY_d_tmp_0;

  // MATLAB Function 'Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/Calculate_position_des/Create dXY desired': '<S23>:1' 
  // '<S23>:1:3'
  // '<S23>:1:5'
  localB->dXY_d[0] = 0.0;
  dXY_d_tmp_0 = cos(rtu_yaw);
  localB->dXY_d[0] += dXY_d_tmp_0 * rtu_chan2;
  dXY_d_tmp = sin(rtu_yaw);
  localB->dXY_d[0] += -dXY_d_tmp * rtu_chan3;
  localB->dXY_d[1] = 0.0;
  localB->dXY_d[1] += dXY_d_tmp * rtu_chan2;
  localB->dXY_d[1] += dXY_d_tmp_0 * rtu_chan3;
}

//
// System initialize for atomic system:
//    '<S109>/MATLAB Function'
//    '<S114>/MATLAB Function'
//
void controlAero_MATLABFunction_Init(rtDW_MATLABFunction_controlAero *localDW)
{
  localDW->offset_not_empty = false;
  localDW->num_not_empty = false;
  localDW->suma_not_empty = false;
}

//
// Output and update for atomic system:
//    '<S109>/MATLAB Function'
//    '<S114>/MATLAB Function'
//
void controlAerobi_MATLABFunction(const real_T rtu_g[3],
  rtB_MATLABFunction_controlAerob *localB, rtDW_MATLABFunction_controlAero
  *localDW)
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;

  // MATLAB Function 'Sensors/attitude/AttitudeEstimator/calib gyro lsm/MATLAB Function': '<S135>:1' 
  if ((!localDW->offset_not_empty) || (!localDW->num_not_empty) ||
      (!localDW->suma_not_empty)) {
    // '<S135>:1:4'
    // '<S135>:1:5'
    localDW->suma_not_empty = true;

    // '<S135>:1:6'
    localDW->suma[0] = 0.0;
    localDW->offset[0] = 0.0;
    localDW->suma[1] = 0.0;
    localDW->offset[1] = 0.0;
    localDW->suma[2] = 0.0;
    localDW->offset[2] = 0.0;
    localDW->offset_not_empty = true;

    // '<S135>:1:7'
    localDW->num = 0.0;
    localDW->num_not_empty = true;
  } else {
    scale = 3.3121686421112381E-170;
    absxk = fabs(rtu_g[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }

    absxk = fabs(rtu_g[1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    absxk = fabs(rtu_g[2]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    y = scale * sqrt(y);
    if (y < 0.2) {
      // '<S135>:1:9'
      // '<S135>:1:10'
      localDW->suma[0] += rtu_g[0];
      localDW->suma[1] += rtu_g[1];
      localDW->suma[2] += rtu_g[2];

      // '<S135>:1:11'
      localDW->num++;
    } else {
      // '<S135>:1:13'
      localDW->suma[0] = 0.0;
      localDW->suma[1] = 0.0;
      localDW->suma[2] = 0.0;

      // '<S135>:1:14'
      localDW->num = 0.0;
    }

    if (localDW->num == 200.0) {
      // '<S135>:1:17'
      // '<S135>:1:18'
      // '<S135>:1:19'
      localDW->offset[0] = localDW->suma[0] / localDW->num;
      localDW->suma[0] = 0.0;
      localDW->offset[1] = localDW->suma[1] / localDW->num;
      localDW->suma[1] = 0.0;
      localDW->offset[2] = localDW->suma[2] / localDW->num;
      localDW->suma[2] = 0.0;
      localDW->num = 0.0;

      // '<S135>:1:20'
    }
  }

  // '<S135>:1:23'
  localB->g_offset[0] = rtu_g[0] - localDW->offset[0];
  localB->g_offset[1] = rtu_g[1] - localDW->offset[1];
  localB->g_offset[2] = rtu_g[2] - localDW->offset[2];
}

// Function for MATLAB Function: '<S106>/TGIC_fcn'
static void controlAerobi_std(const real_T x[30], real_T y[3])
{
  int32_T j;
  int32_T k;
  real_T xbar;
  for (j = 0; j < 3; j++) {
    for (k = 0; k < 10; k++) {
      controlAerobi_B.xv[k] = x[k * 3 + j];
    }

    xbar = controlAerobi_B.xv[0];
    for (k = 0; k < 9; k++) {
      xbar += controlAerobi_B.xv[k + 1];
    }

    xbar /= 10.0;
    for (k = 0; k < 10; k++) {
      controlAerobi_B.absdiff[k] = fabs(controlAerobi_B.xv[k] - xbar);
    }

    y[j] = xnrm2_BcBwAYPM(controlAerobi_B.absdiff) / 3.0;
  }
}

// Function for MATLAB Function: '<S106>/TGIC_fcn'
static void controlAerobi_mrdivide_eK1qdBt4(real_T A[60], const real_T B[36])
{
  int8_T ipiv[6];
  int32_T j;
  int32_T ix;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kBcol;
  memcpy(&controlAerobi_B.b_A_c[0], &B[0], 36U * sizeof(real_T));
  for (d = 0; d < 6; d++) {
    ipiv[d] = (int8_T)(1 + d);
  }

  for (j = 0; j < 5; j++) {
    jBcol = j * 7;
    iy = 0;
    ix = jBcol;
    controlAerobi_B.smax = fabs(controlAerobi_B.b_A_c[jBcol]);
    for (kBcol = 2; kBcol <= 6 - j; kBcol++) {
      ix++;
      controlAerobi_B.s_o = fabs(controlAerobi_B.b_A_c[ix]);
      if (controlAerobi_B.s_o > controlAerobi_B.smax) {
        iy = kBcol - 1;
        controlAerobi_B.smax = controlAerobi_B.s_o;
      }
    }

    if (controlAerobi_B.b_A_c[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (kBcol = 0; kBcol < 6; kBcol++) {
          controlAerobi_B.smax = controlAerobi_B.b_A_c[ix];
          controlAerobi_B.b_A_c[ix] = controlAerobi_B.b_A_c[iy];
          controlAerobi_B.b_A_c[iy] = controlAerobi_B.smax;
          ix += 6;
          iy += 6;
        }
      }

      iy = (jBcol - j) + 6;
      for (ix = jBcol + 1; ix + 1 <= iy; ix++) {
        controlAerobi_B.b_A_c[ix] /= controlAerobi_B.b_A_c[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 6;
    for (kBcol = 1; kBcol <= 5 - j; kBcol++) {
      controlAerobi_B.smax = controlAerobi_B.b_A_c[ix];
      if (controlAerobi_B.b_A_c[ix] != 0.0) {
        c_ix = jBcol + 1;
        d = (iy - j) + 12;
        for (ijA = 7 + iy; ijA + 1 <= d; ijA++) {
          controlAerobi_B.b_A_c[ijA] += controlAerobi_B.b_A_c[c_ix] *
            -controlAerobi_B.smax;
          c_ix++;
        }
      }

      ix += 6;
      iy += 6;
    }
  }

  for (j = 0; j < 6; j++) {
    jBcol = 10 * j;
    iy = 6 * j;
    for (ix = 1; ix <= j; ix++) {
      kBcol = (ix - 1) * 10;
      if (controlAerobi_B.b_A_c[(ix + iy) - 1] != 0.0) {
        for (c_ix = 0; c_ix < 10; c_ix++) {
          d = c_ix + jBcol;
          A[d] -= controlAerobi_B.b_A_c[(ix + iy) - 1] * A[c_ix + kBcol];
        }
      }
    }

    controlAerobi_B.smax = 1.0 / controlAerobi_B.b_A_c[j + iy];
    for (iy = 0; iy < 10; iy++) {
      d = iy + jBcol;
      A[d] *= controlAerobi_B.smax;
    }
  }

  for (j = 5; j >= 0; j--) {
    jBcol = 10 * j;
    iy = 6 * j - 1;
    for (ix = j + 2; ix < 7; ix++) {
      kBcol = (ix - 1) * 10;
      if (controlAerobi_B.b_A_c[ix + iy] != 0.0) {
        for (c_ix = 0; c_ix < 10; c_ix++) {
          A[c_ix + jBcol] -= controlAerobi_B.b_A_c[ix + iy] * A[c_ix + kBcol];
        }
      }
    }
  }

  for (j = 4; j >= 0; j--) {
    if (j + 1 != ipiv[j]) {
      jBcol = ipiv[j] - 1;
      for (iy = 0; iy < 10; iy++) {
        controlAerobi_B.smax = A[10 * j + iy];
        A[iy + 10 * j] = A[10 * jBcol + iy];
        A[iy + 10 * jBcol] = controlAerobi_B.smax;
      }
    }
  }
}

// Function for MATLAB Function: '<S106>/TGIC_fcn'
static void controlAerobi_rotation_SYBOT8wI(const real_T q_[4], real_T R[9])
{
  real_T R_tmp;
  real_T R_tmp_0;
  real_T R_tmp_1;
  real_T R_tmp_2;
  real_T R_tmp_3;

  // '<S129>:1:139'
  controlAerobi_B.R_tmp_c = q_[0] * q_[0];
  R_tmp = q_[1] * q_[1];
  R_tmp_0 = q_[2] * q_[2];
  R_tmp_1 = q_[3] * q_[3];
  R[0] = ((controlAerobi_B.R_tmp_c + R_tmp) - R_tmp_0) - R_tmp_1;
  controlAerobi_B.R_tmp = q_[1] * q_[2];
  controlAerobi_B.R_tmp_m = q_[0] * q_[3];
  R[3] = (controlAerobi_B.R_tmp - controlAerobi_B.R_tmp_m) * 2.0;
  R_tmp_2 = q_[1] * q_[3];
  R_tmp_3 = q_[0] * q_[2];
  R[6] = (R_tmp_3 + R_tmp_2) * 2.0;
  R[1] = (controlAerobi_B.R_tmp + controlAerobi_B.R_tmp_m) * 2.0;
  controlAerobi_B.R_tmp_c -= R_tmp;
  R[4] = (controlAerobi_B.R_tmp_c + R_tmp_0) - R_tmp_1;
  R_tmp = q_[0] * q_[1];
  controlAerobi_B.R_tmp = q_[2] * q_[3];
  R[7] = (controlAerobi_B.R_tmp - R_tmp) * 2.0;
  R[2] = (R_tmp_2 - R_tmp_3) * 2.0;
  R[5] = (R_tmp + controlAerobi_B.R_tmp) * 2.0;
  R[8] = (controlAerobi_B.R_tmp_c - R_tmp_0) + R_tmp_1;
}

// Function for MATLAB Function: '<S106>/TGIC_fcn'
static real_T controlAerobi_xnrm2_N4q5JsKO(int32_T n, const real_T x[100],
  int32_T ix0)
{
  real_T y;
  int32_T kend;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      controlAerobi_B.scale_h = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        controlAerobi_B.absxk_c = fabs(x[k - 1]);
        if (controlAerobi_B.absxk_c > controlAerobi_B.scale_h) {
          controlAerobi_B.t_c = controlAerobi_B.scale_h /
            controlAerobi_B.absxk_c;
          y = y * controlAerobi_B.t_c * controlAerobi_B.t_c + 1.0;
          controlAerobi_B.scale_h = controlAerobi_B.absxk_c;
        } else {
          controlAerobi_B.t_c = controlAerobi_B.absxk_c /
            controlAerobi_B.scale_h;
          y += controlAerobi_B.t_c * controlAerobi_B.t_c;
        }
      }

      y = controlAerobi_B.scale_h * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S106>/TGIC_fcn'
static real_T controlAerobi_xnrm2_bVkOvwMp(int32_T n, const real_T x[10],
  int32_T ix0)
{
  real_T y;
  int32_T kend;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      controlAerobi_B.scale_m = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        controlAerobi_B.absxk_m = fabs(x[k - 1]);
        if (controlAerobi_B.absxk_m > controlAerobi_B.scale_m) {
          controlAerobi_B.t_j = controlAerobi_B.scale_m /
            controlAerobi_B.absxk_m;
          y = y * controlAerobi_B.t_j * controlAerobi_B.t_j + 1.0;
          controlAerobi_B.scale_m = controlAerobi_B.absxk_m;
        } else {
          controlAerobi_B.t_j = controlAerobi_B.absxk_m /
            controlAerobi_B.scale_m;
          y += controlAerobi_B.t_j * controlAerobi_B.t_j;
        }
      }

      y = controlAerobi_B.scale_m * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S106>/TGIC_fcn'
static void controlAerobi_xrotg_czoXf8gE(real_T *a, real_T *b, real_T *c, real_T
  *s)
{
  real_T bds;
  controlAerobi_B.roe = *b;
  controlAerobi_B.absa = fabs(*a);
  controlAerobi_B.absb = fabs(*b);
  if (controlAerobi_B.absa > controlAerobi_B.absb) {
    controlAerobi_B.roe = *a;
  }

  controlAerobi_B.scale = controlAerobi_B.absa + controlAerobi_B.absb;
  if (controlAerobi_B.scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    controlAerobi_B.absa = 0.0;
  } else {
    controlAerobi_B.ads = controlAerobi_B.absa / controlAerobi_B.scale;
    bds = controlAerobi_B.absb / controlAerobi_B.scale;
    controlAerobi_B.scale *= sqrt(controlAerobi_B.ads * controlAerobi_B.ads +
      bds * bds);
    if (controlAerobi_B.roe < 0.0) {
      controlAerobi_B.scale = -controlAerobi_B.scale;
    }

    *c = *a / controlAerobi_B.scale;
    *s = *b / controlAerobi_B.scale;
    if (controlAerobi_B.absa > controlAerobi_B.absb) {
      controlAerobi_B.absa = *s;
    } else if (*c != 0.0) {
      controlAerobi_B.absa = 1.0 / *c;
    } else {
      controlAerobi_B.absa = 1.0;
    }
  }

  *a = controlAerobi_B.scale;
  *b = controlAerobi_B.absa;
}

// Function for MATLAB Function: '<S106>/TGIC_fcn'
static void controlAerobi_svd_NDGo5poy(const real_T A[100], real_T U[10])
{
  int32_T q;
  int32_T qq;
  boolean_T apply_transform;
  int32_T qjj;
  int32_T kase;
  int32_T d_ii;
  int32_T i;
  int32_T exitg1;
  boolean_T exitg2;
  memcpy(&controlAerobi_B.b_A[0], &A[0], 100U * sizeof(real_T));
  for (i = 0; i < 10; i++) {
    controlAerobi_B.s[i] = 0.0;
    controlAerobi_B.e[i] = 0.0;
    controlAerobi_B.work[i] = 0.0;
  }

  for (i = 0; i < 9; i++) {
    qq = 10 * i + i;
    apply_transform = false;
    controlAerobi_B.nrm = controlAerobi_xnrm2_N4q5JsKO(10 - i,
      controlAerobi_B.b_A, qq + 1);
    if (controlAerobi_B.nrm > 0.0) {
      apply_transform = true;
      if (controlAerobi_B.b_A[qq] < 0.0) {
        controlAerobi_B.s[i] = -controlAerobi_B.nrm;
      } else {
        controlAerobi_B.s[i] = controlAerobi_B.nrm;
      }

      if (fabs(controlAerobi_B.s[i]) >= 1.0020841800044864E-292) {
        controlAerobi_B.nrm = 1.0 / controlAerobi_B.s[i];
        q = (qq - i) + 10;
        for (qjj = qq; qjj + 1 <= q; qjj++) {
          controlAerobi_B.b_A[qjj] *= controlAerobi_B.nrm;
        }
      } else {
        q = (qq - i) + 10;
        for (qjj = qq; qjj + 1 <= q; qjj++) {
          controlAerobi_B.b_A[qjj] /= controlAerobi_B.s[i];
        }
      }

      controlAerobi_B.b_A[qq]++;
      controlAerobi_B.s[i] = -controlAerobi_B.s[i];
    } else {
      controlAerobi_B.s[i] = 0.0;
    }

    for (q = i + 1; q + 1 < 11; q++) {
      qjj = 10 * q + i;
      if (apply_transform) {
        xaxpy_kYK8fEIh(10 - i, -(xdotc_30RDEAm5(10 - i, controlAerobi_B.b_A, qq
          + 1, controlAerobi_B.b_A, qjj + 1) / controlAerobi_B.b_A[i + 10 * i]),
                       qq + 1, controlAerobi_B.b_A, qjj + 1);
      }

      controlAerobi_B.e[q] = controlAerobi_B.b_A[qjj];
    }

    if (i + 1 <= 8) {
      controlAerobi_B.nrm = controlAerobi_xnrm2_bVkOvwMp(9 - i,
        controlAerobi_B.e, i + 2);
      if (controlAerobi_B.nrm == 0.0) {
        controlAerobi_B.e[i] = 0.0;
      } else {
        if (controlAerobi_B.e[i + 1] < 0.0) {
          controlAerobi_B.e[i] = -controlAerobi_B.nrm;
        } else {
          controlAerobi_B.e[i] = controlAerobi_B.nrm;
        }

        controlAerobi_B.nrm = controlAerobi_B.e[i];
        if (fabs(controlAerobi_B.e[i]) >= 1.0020841800044864E-292) {
          controlAerobi_B.nrm = 1.0 / controlAerobi_B.e[i];
          for (qq = i + 1; qq + 1 < 11; qq++) {
            controlAerobi_B.e[qq] *= controlAerobi_B.nrm;
          }
        } else {
          for (qq = i + 1; qq + 1 < 11; qq++) {
            controlAerobi_B.e[qq] /= controlAerobi_B.nrm;
          }
        }

        controlAerobi_B.e[i + 1]++;
        controlAerobi_B.e[i] = -controlAerobi_B.e[i];
        for (qq = i + 1; qq + 1 < 11; qq++) {
          controlAerobi_B.work[qq] = 0.0;
        }

        for (qq = i + 1; qq + 1 < 11; qq++) {
          xaxpy_9A42w0RE(9 - i, controlAerobi_B.e[qq], controlAerobi_B.b_A, (i +
            10 * qq) + 2, controlAerobi_B.work, i + 2);
        }

        for (qq = i + 1; qq + 1 < 11; qq++) {
          xaxpy_SEOAgeAY(9 - i, -controlAerobi_B.e[qq] / controlAerobi_B.e[i + 1],
                         controlAerobi_B.work, i + 2, controlAerobi_B.b_A, (i +
            10 * qq) + 2);
        }
      }
    }
  }

  i = 8;
  controlAerobi_B.s[9] = controlAerobi_B.b_A[99];
  controlAerobi_B.e[8] = controlAerobi_B.b_A[98];
  controlAerobi_B.e[9] = 0.0;
  for (qq = 0; qq < 10; qq++) {
    controlAerobi_B.ztest = controlAerobi_B.e[qq];
    if (controlAerobi_B.s[qq] != 0.0) {
      controlAerobi_B.rt = fabs(controlAerobi_B.s[qq]);
      controlAerobi_B.nrm = controlAerobi_B.s[qq] / controlAerobi_B.rt;
      controlAerobi_B.s[qq] = controlAerobi_B.rt;
      if (qq + 1 < 10) {
        controlAerobi_B.ztest = controlAerobi_B.e[qq] / controlAerobi_B.nrm;
      }
    }

    if ((qq + 1 < 10) && (controlAerobi_B.ztest != 0.0)) {
      controlAerobi_B.rt = fabs(controlAerobi_B.ztest);
      controlAerobi_B.nrm = controlAerobi_B.ztest;
      controlAerobi_B.ztest = controlAerobi_B.rt;
      controlAerobi_B.s[qq + 1] *= controlAerobi_B.rt / controlAerobi_B.nrm;
    }

    controlAerobi_B.e[qq] = controlAerobi_B.ztest;
  }

  qq = 0;
  controlAerobi_B.nrm = 0.0;
  for (q = 0; q < 10; q++) {
    controlAerobi_B.rt = fabs(controlAerobi_B.s[q]);
    controlAerobi_B.ztest = fabs(controlAerobi_B.e[q]);
    if ((controlAerobi_B.rt > controlAerobi_B.ztest) || rtIsNaN
        (controlAerobi_B.ztest)) {
      controlAerobi_B.ztest = controlAerobi_B.rt;
    }

    if (!((controlAerobi_B.nrm > controlAerobi_B.ztest) || rtIsNaN
          (controlAerobi_B.ztest))) {
      controlAerobi_B.nrm = controlAerobi_B.ztest;
    }
  }

  while ((i + 2 > 0) && (!(qq >= 75))) {
    kase = i + 1;
    do {
      exitg1 = 0;
      q = kase;
      if (kase == 0) {
        exitg1 = 1;
      } else {
        controlAerobi_B.rt = fabs(controlAerobi_B.e[kase - 1]);
        if ((controlAerobi_B.rt <= (fabs(controlAerobi_B.s[kase - 1]) + fabs
              (controlAerobi_B.s[kase])) * 2.2204460492503131E-16) ||
            ((controlAerobi_B.rt <= 1.0020841800044864E-292) || ((qq > 20) &&
              (controlAerobi_B.rt <= 2.2204460492503131E-16 *
               controlAerobi_B.nrm)))) {
          controlAerobi_B.e[kase - 1] = 0.0;
          exitg1 = 1;
        } else {
          kase--;
        }
      }
    } while (exitg1 == 0);

    if (i + 1 == kase) {
      kase = 4;
    } else {
      qjj = i + 2;
      d_ii = i + 2;
      exitg2 = false;
      while ((!exitg2) && (d_ii >= kase)) {
        qjj = d_ii;
        if (d_ii == kase) {
          exitg2 = true;
        } else {
          controlAerobi_B.rt = 0.0;
          if (d_ii < i + 2) {
            controlAerobi_B.rt = fabs(controlAerobi_B.e[d_ii - 1]);
          }

          if (d_ii > kase + 1) {
            controlAerobi_B.rt += fabs(controlAerobi_B.e[d_ii - 2]);
          }

          controlAerobi_B.ztest = fabs(controlAerobi_B.s[d_ii - 1]);
          if ((controlAerobi_B.ztest <= 2.2204460492503131E-16 *
               controlAerobi_B.rt) || (controlAerobi_B.ztest <=
               1.0020841800044864E-292)) {
            controlAerobi_B.s[d_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            d_ii--;
          }
        }
      }

      if (qjj == kase) {
        kase = 3;
      } else if (i + 2 == qjj) {
        kase = 1;
      } else {
        kase = 2;
        q = qjj;
      }
    }

    switch (kase) {
     case 1:
      controlAerobi_B.rt = controlAerobi_B.e[i];
      controlAerobi_B.e[i] = 0.0;
      for (qjj = i; qjj + 1 >= q + 1; qjj--) {
        controlAerobi_B.ztest = controlAerobi_B.s[qjj];
        controlAerobi_xrotg_czoXf8gE(&controlAerobi_B.ztest, &controlAerobi_B.rt,
          &controlAerobi_B.sqds, &controlAerobi_B.smm1);
        controlAerobi_B.s[qjj] = controlAerobi_B.ztest;
        if (qjj + 1 > q + 1) {
          controlAerobi_B.rt = controlAerobi_B.e[qjj - 1] *
            -controlAerobi_B.smm1;
          controlAerobi_B.e[qjj - 1] *= controlAerobi_B.sqds;
        }
      }
      break;

     case 2:
      controlAerobi_B.rt = controlAerobi_B.e[q - 1];
      controlAerobi_B.e[q - 1] = 0.0;
      while (q + 1 <= i + 2) {
        controlAerobi_B.ztest = controlAerobi_B.s[q];
        controlAerobi_xrotg_czoXf8gE(&controlAerobi_B.ztest, &controlAerobi_B.rt,
          &controlAerobi_B.sqds, &controlAerobi_B.smm1);
        controlAerobi_B.s[q] = controlAerobi_B.ztest;
        controlAerobi_B.rt = -controlAerobi_B.smm1 * controlAerobi_B.e[q];
        controlAerobi_B.e[q] *= controlAerobi_B.sqds;
        q++;
      }
      break;

     case 3:
      controlAerobi_B.varargin_1[0] = fabs(controlAerobi_B.s[i + 1]);
      controlAerobi_B.varargin_1[1] = fabs(controlAerobi_B.s[i]);
      controlAerobi_B.varargin_1[2] = fabs(controlAerobi_B.e[i]);
      controlAerobi_B.varargin_1[3] = fabs(controlAerobi_B.s[q]);
      controlAerobi_B.varargin_1[4] = fabs(controlAerobi_B.e[q]);
      qjj = 1;
      controlAerobi_B.ztest = controlAerobi_B.varargin_1[0];
      if (rtIsNaN(controlAerobi_B.varargin_1[0])) {
        kase = 2;
        exitg2 = false;
        while ((!exitg2) && (kase < 6)) {
          qjj = kase;
          if (!rtIsNaN(controlAerobi_B.varargin_1[kase - 1])) {
            controlAerobi_B.ztest = controlAerobi_B.varargin_1[kase - 1];
            exitg2 = true;
          } else {
            kase++;
          }
        }
      }

      if (qjj < 5) {
        while (qjj + 1 < 6) {
          if (controlAerobi_B.varargin_1[qjj] > controlAerobi_B.ztest) {
            controlAerobi_B.ztest = controlAerobi_B.varargin_1[qjj];
          }

          qjj++;
        }
      }

      controlAerobi_B.rt = controlAerobi_B.s[i + 1] / controlAerobi_B.ztest;
      controlAerobi_B.smm1 = controlAerobi_B.s[i] / controlAerobi_B.ztest;
      controlAerobi_B.emm1 = controlAerobi_B.e[i] / controlAerobi_B.ztest;
      controlAerobi_B.sqds = controlAerobi_B.s[q] / controlAerobi_B.ztest;
      controlAerobi_B.smm1 = ((controlAerobi_B.smm1 + controlAerobi_B.rt) *
        (controlAerobi_B.smm1 - controlAerobi_B.rt) + controlAerobi_B.emm1 *
        controlAerobi_B.emm1) / 2.0;
      controlAerobi_B.emm1 *= controlAerobi_B.rt;
      controlAerobi_B.emm1 *= controlAerobi_B.emm1;
      if ((controlAerobi_B.smm1 != 0.0) || (controlAerobi_B.emm1 != 0.0)) {
        controlAerobi_B.shift = sqrt(controlAerobi_B.smm1 * controlAerobi_B.smm1
          + controlAerobi_B.emm1);
        if (controlAerobi_B.smm1 < 0.0) {
          controlAerobi_B.shift = -controlAerobi_B.shift;
        }

        controlAerobi_B.shift = controlAerobi_B.emm1 / (controlAerobi_B.smm1 +
          controlAerobi_B.shift);
      } else {
        controlAerobi_B.shift = 0.0;
      }

      controlAerobi_B.rt = (controlAerobi_B.sqds + controlAerobi_B.rt) *
        (controlAerobi_B.sqds - controlAerobi_B.rt) + controlAerobi_B.shift;
      controlAerobi_B.ztest = controlAerobi_B.e[q] / controlAerobi_B.ztest *
        controlAerobi_B.sqds;
      for (qjj = q + 1; qjj <= i + 1; qjj++) {
        controlAerobi_xrotg_czoXf8gE(&controlAerobi_B.rt, &controlAerobi_B.ztest,
          &controlAerobi_B.sqds, &controlAerobi_B.smm1);
        if (qjj > q + 1) {
          controlAerobi_B.e[qjj - 2] = controlAerobi_B.rt;
        }

        controlAerobi_B.rt = controlAerobi_B.s[qjj - 1] * controlAerobi_B.sqds +
          controlAerobi_B.e[qjj - 1] * controlAerobi_B.smm1;
        controlAerobi_B.e[qjj - 1] = controlAerobi_B.e[qjj - 1] *
          controlAerobi_B.sqds - controlAerobi_B.s[qjj - 1] *
          controlAerobi_B.smm1;
        controlAerobi_B.ztest = controlAerobi_B.smm1 * controlAerobi_B.s[qjj];
        controlAerobi_B.s[qjj] *= controlAerobi_B.sqds;
        controlAerobi_xrotg_czoXf8gE(&controlAerobi_B.rt, &controlAerobi_B.ztest,
          &controlAerobi_B.sqds, &controlAerobi_B.smm1);
        controlAerobi_B.s[qjj - 1] = controlAerobi_B.rt;
        controlAerobi_B.rt = controlAerobi_B.e[qjj - 1] * controlAerobi_B.sqds +
          controlAerobi_B.smm1 * controlAerobi_B.s[qjj];
        controlAerobi_B.s[qjj] = controlAerobi_B.e[qjj - 1] *
          -controlAerobi_B.smm1 + controlAerobi_B.sqds * controlAerobi_B.s[qjj];
        controlAerobi_B.ztest = controlAerobi_B.smm1 * controlAerobi_B.e[qjj];
        controlAerobi_B.e[qjj] *= controlAerobi_B.sqds;
      }

      controlAerobi_B.e[i] = controlAerobi_B.rt;
      qq++;
      break;

     default:
      if (controlAerobi_B.s[q] < 0.0) {
        controlAerobi_B.s[q] = -controlAerobi_B.s[q];
      }

      qq = q + 1;
      while ((q + 1 < 10) && (controlAerobi_B.s[q] < controlAerobi_B.s[qq])) {
        controlAerobi_B.rt = controlAerobi_B.s[q];
        controlAerobi_B.s[q] = controlAerobi_B.s[qq];
        controlAerobi_B.s[qq] = controlAerobi_B.rt;
        q = qq;
        qq++;
      }

      qq = 0;
      i--;
      break;
    }
  }

  for (i = 0; i < 10; i++) {
    U[i] = controlAerobi_B.s[i];
  }
}

// Function for MATLAB Function: '<S106>/TGIC_fcn'
static real_T controlAerobi_norm_0KU7QpIQ(const real_T x[100])
{
  real_T y;
  int32_T k;
  boolean_T exitg1;
  y = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 100)) {
    controlAerobi_B.absx = fabs(x[k]);
    if (rtIsNaN(controlAerobi_B.absx)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (controlAerobi_B.absx > y) {
        y = controlAerobi_B.absx;
      }

      k++;
    }
  }

  if ((!rtIsInf(y)) && (!rtIsNaN(y))) {
    controlAerobi_svd_NDGo5poy(x, controlAerobi_B.dv1);
    y = controlAerobi_B.dv1[0];
  }

  return y;
}

// Function for MATLAB Function: '<S175>/Liner Fixed-gain Filter'
static void controlAerobi_mrdivide_oxNR4jke(real_T A[8], const real_T B[16])
{
  int8_T ipiv[4];
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kBcol;
  memcpy(&controlAerobi_B.b_A_m[0], &B[0], sizeof(real_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (j = 0; j < 3; j++) {
    jBcol = j * 5;
    iy = 0;
    ix = jBcol;
    controlAerobi_B.smax_nv = fabs(controlAerobi_B.b_A_m[jBcol]);
    for (kBcol = 2; kBcol <= 4 - j; kBcol++) {
      ix++;
      s = fabs(controlAerobi_B.b_A_m[ix]);
      if (s > controlAerobi_B.smax_nv) {
        iy = kBcol - 1;
        controlAerobi_B.smax_nv = s;
      }
    }

    if (controlAerobi_B.b_A_m[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        controlAerobi_B.smax_nv = controlAerobi_B.b_A_m[j];
        controlAerobi_B.b_A_m[j] = controlAerobi_B.b_A_m[iy];
        controlAerobi_B.b_A_m[iy] = controlAerobi_B.smax_nv;
        ix = j + 4;
        iy += 4;
        controlAerobi_B.smax_nv = controlAerobi_B.b_A_m[ix];
        controlAerobi_B.b_A_m[ix] = controlAerobi_B.b_A_m[iy];
        controlAerobi_B.b_A_m[iy] = controlAerobi_B.smax_nv;
        ix += 4;
        iy += 4;
        controlAerobi_B.smax_nv = controlAerobi_B.b_A_m[ix];
        controlAerobi_B.b_A_m[ix] = controlAerobi_B.b_A_m[iy];
        controlAerobi_B.b_A_m[iy] = controlAerobi_B.smax_nv;
        ix += 4;
        iy += 4;
        controlAerobi_B.smax_nv = controlAerobi_B.b_A_m[ix];
        controlAerobi_B.b_A_m[ix] = controlAerobi_B.b_A_m[iy];
        controlAerobi_B.b_A_m[iy] = controlAerobi_B.smax_nv;
      }

      iy = (jBcol - j) + 4;
      for (ix = jBcol + 1; ix + 1 <= iy; ix++) {
        controlAerobi_B.b_A_m[ix] /= controlAerobi_B.b_A_m[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 4;
    for (kBcol = 1; kBcol <= 3 - j; kBcol++) {
      controlAerobi_B.smax_nv = controlAerobi_B.b_A_m[ix];
      if (controlAerobi_B.b_A_m[ix] != 0.0) {
        c_ix = jBcol + 1;
        d = (iy - j) + 8;
        for (ijA = 5 + iy; ijA + 1 <= d; ijA++) {
          controlAerobi_B.b_A_m[ijA] += controlAerobi_B.b_A_m[c_ix] *
            -controlAerobi_B.smax_nv;
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  for (j = 0; j < 4; j++) {
    jBcol = j << 1;
    iy = j << 2;
    for (ix = 1; ix <= j; ix++) {
      kBcol = (ix - 1) << 1;
      if (controlAerobi_B.b_A_m[(ix + iy) - 1] != 0.0) {
        A[jBcol] -= controlAerobi_B.b_A_m[(ix + iy) - 1] * A[kBcol];
        A[1 + jBcol] -= controlAerobi_B.b_A_m[(ix + iy) - 1] * A[1 + kBcol];
      }
    }

    controlAerobi_B.smax_nv = 1.0 / controlAerobi_B.b_A_m[j + iy];
    A[jBcol] *= controlAerobi_B.smax_nv;
    A[1 + jBcol] *= controlAerobi_B.smax_nv;
  }

  for (j = 3; j >= 0; j--) {
    jBcol = j << 1;
    iy = (j << 2) - 1;
    for (ix = j + 2; ix < 5; ix++) {
      kBcol = (ix - 1) << 1;
      if (controlAerobi_B.b_A_m[ix + iy] != 0.0) {
        A[jBcol] -= controlAerobi_B.b_A_m[ix + iy] * A[kBcol];
        A[1 + jBcol] -= controlAerobi_B.b_A_m[ix + iy] * A[1 + kBcol];
      }
    }
  }

  for (j = 2; j >= 0; j--) {
    if (j + 1 != ipiv[j]) {
      jBcol = ipiv[j] - 1;
      controlAerobi_B.smax_nv = A[j << 1];
      A[j << 1] = A[jBcol << 1];
      A[jBcol << 1] = controlAerobi_B.smax_nv;
      controlAerobi_B.smax_nv = A[(j << 1) + 1];
      A[1 + (j << 1)] = A[(jBcol << 1) + 1];
      A[1 + (jBcol << 1)] = controlAerobi_B.smax_nv;
    }
  }
}

// Function for MATLAB Function: '<S175>/EKF2_XYZ'
static void controlAerobi_mrdivide_TwA5PnsG(real_T A[30], const real_T B[25])
{
  int8_T ipiv[5];
  int32_T j;
  int32_T ix;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kBcol;
  memcpy(&controlAerobi_B.b_A_cv[0], &B[0], 25U * sizeof(real_T));
  for (d = 0; d < 5; d++) {
    ipiv[d] = (int8_T)(1 + d);
  }

  for (j = 0; j < 4; j++) {
    jBcol = j * 6;
    iy = 0;
    ix = jBcol;
    controlAerobi_B.smax_n = fabs(controlAerobi_B.b_A_cv[jBcol]);
    for (kBcol = 2; kBcol <= 5 - j; kBcol++) {
      ix++;
      controlAerobi_B.s_i = fabs(controlAerobi_B.b_A_cv[ix]);
      if (controlAerobi_B.s_i > controlAerobi_B.smax_n) {
        iy = kBcol - 1;
        controlAerobi_B.smax_n = controlAerobi_B.s_i;
      }
    }

    if (controlAerobi_B.b_A_cv[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        ix = j;
        for (kBcol = 0; kBcol < 5; kBcol++) {
          controlAerobi_B.smax_n = controlAerobi_B.b_A_cv[ix];
          controlAerobi_B.b_A_cv[ix] = controlAerobi_B.b_A_cv[iy];
          controlAerobi_B.b_A_cv[iy] = controlAerobi_B.smax_n;
          ix += 5;
          iy += 5;
        }
      }

      iy = (jBcol - j) + 5;
      for (ix = jBcol + 1; ix + 1 <= iy; ix++) {
        controlAerobi_B.b_A_cv[ix] /= controlAerobi_B.b_A_cv[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 5;
    for (kBcol = 1; kBcol <= 4 - j; kBcol++) {
      controlAerobi_B.smax_n = controlAerobi_B.b_A_cv[ix];
      if (controlAerobi_B.b_A_cv[ix] != 0.0) {
        c_ix = jBcol + 1;
        d = (iy - j) + 10;
        for (ijA = 6 + iy; ijA + 1 <= d; ijA++) {
          controlAerobi_B.b_A_cv[ijA] += controlAerobi_B.b_A_cv[c_ix] *
            -controlAerobi_B.smax_n;
          c_ix++;
        }
      }

      ix += 5;
      iy += 5;
    }
  }

  for (j = 0; j < 5; j++) {
    jBcol = 6 * j;
    iy = 5 * j;
    for (ix = 1; ix <= j; ix++) {
      kBcol = (ix - 1) * 6;
      if (controlAerobi_B.b_A_cv[(ix + iy) - 1] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          d = c_ix + jBcol;
          A[d] -= controlAerobi_B.b_A_cv[(ix + iy) - 1] * A[c_ix + kBcol];
        }
      }
    }

    controlAerobi_B.smax_n = 1.0 / controlAerobi_B.b_A_cv[j + iy];
    for (iy = 0; iy < 6; iy++) {
      d = iy + jBcol;
      A[d] *= controlAerobi_B.smax_n;
    }
  }

  for (j = 4; j >= 0; j--) {
    jBcol = 6 * j;
    iy = 5 * j - 1;
    for (ix = j + 2; ix < 6; ix++) {
      kBcol = (ix - 1) * 6;
      if (controlAerobi_B.b_A_cv[ix + iy] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          A[c_ix + jBcol] -= controlAerobi_B.b_A_cv[ix + iy] * A[c_ix + kBcol];
        }
      }
    }
  }

  for (j = 3; j >= 0; j--) {
    if (j + 1 != ipiv[j]) {
      jBcol = ipiv[j] - 1;
      for (iy = 0; iy < 6; iy++) {
        controlAerobi_B.smax_n = A[6 * j + iy];
        A[iy + 6 * j] = A[6 * jBcol + iy];
        A[iy + 6 * jBcol] = controlAerobi_B.smax_n;
      }
    }
  }
}

// Function for MATLAB Function: '<S172>/Liner Fixed-gain Filter1'
static void controlAero_mrdivide_oxNR4jke_k(real_T A[8], const real_T B[16])
{
  int8_T ipiv[4];
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kBcol;
  memcpy(&controlAerobi_B.b_A_g[0], &B[0], sizeof(real_T) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (j = 0; j < 3; j++) {
    jBcol = j * 5;
    iy = 0;
    ix = jBcol;
    controlAerobi_B.smax_o = fabs(controlAerobi_B.b_A_g[jBcol]);
    for (kBcol = 2; kBcol <= 4 - j; kBcol++) {
      ix++;
      s = fabs(controlAerobi_B.b_A_g[ix]);
      if (s > controlAerobi_B.smax_o) {
        iy = kBcol - 1;
        controlAerobi_B.smax_o = s;
      }
    }

    if (controlAerobi_B.b_A_g[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        controlAerobi_B.smax_o = controlAerobi_B.b_A_g[j];
        controlAerobi_B.b_A_g[j] = controlAerobi_B.b_A_g[iy];
        controlAerobi_B.b_A_g[iy] = controlAerobi_B.smax_o;
        ix = j + 4;
        iy += 4;
        controlAerobi_B.smax_o = controlAerobi_B.b_A_g[ix];
        controlAerobi_B.b_A_g[ix] = controlAerobi_B.b_A_g[iy];
        controlAerobi_B.b_A_g[iy] = controlAerobi_B.smax_o;
        ix += 4;
        iy += 4;
        controlAerobi_B.smax_o = controlAerobi_B.b_A_g[ix];
        controlAerobi_B.b_A_g[ix] = controlAerobi_B.b_A_g[iy];
        controlAerobi_B.b_A_g[iy] = controlAerobi_B.smax_o;
        ix += 4;
        iy += 4;
        controlAerobi_B.smax_o = controlAerobi_B.b_A_g[ix];
        controlAerobi_B.b_A_g[ix] = controlAerobi_B.b_A_g[iy];
        controlAerobi_B.b_A_g[iy] = controlAerobi_B.smax_o;
      }

      iy = (jBcol - j) + 4;
      for (ix = jBcol + 1; ix + 1 <= iy; ix++) {
        controlAerobi_B.b_A_g[ix] /= controlAerobi_B.b_A_g[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 4;
    for (kBcol = 1; kBcol <= 3 - j; kBcol++) {
      controlAerobi_B.smax_o = controlAerobi_B.b_A_g[ix];
      if (controlAerobi_B.b_A_g[ix] != 0.0) {
        c_ix = jBcol + 1;
        d = (iy - j) + 8;
        for (ijA = 5 + iy; ijA + 1 <= d; ijA++) {
          controlAerobi_B.b_A_g[ijA] += controlAerobi_B.b_A_g[c_ix] *
            -controlAerobi_B.smax_o;
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  for (j = 0; j < 4; j++) {
    jBcol = j << 1;
    iy = j << 2;
    for (ix = 1; ix <= j; ix++) {
      kBcol = (ix - 1) << 1;
      if (controlAerobi_B.b_A_g[(ix + iy) - 1] != 0.0) {
        A[jBcol] -= controlAerobi_B.b_A_g[(ix + iy) - 1] * A[kBcol];
        A[1 + jBcol] -= controlAerobi_B.b_A_g[(ix + iy) - 1] * A[1 + kBcol];
      }
    }

    controlAerobi_B.smax_o = 1.0 / controlAerobi_B.b_A_g[j + iy];
    A[jBcol] *= controlAerobi_B.smax_o;
    A[1 + jBcol] *= controlAerobi_B.smax_o;
  }

  for (j = 3; j >= 0; j--) {
    jBcol = j << 1;
    iy = (j << 2) - 1;
    for (ix = j + 2; ix < 5; ix++) {
      kBcol = (ix - 1) << 1;
      if (controlAerobi_B.b_A_g[ix + iy] != 0.0) {
        A[jBcol] -= controlAerobi_B.b_A_g[ix + iy] * A[kBcol];
        A[1 + jBcol] -= controlAerobi_B.b_A_g[ix + iy] * A[1 + kBcol];
      }
    }
  }

  for (j = 2; j >= 0; j--) {
    if (j + 1 != ipiv[j]) {
      jBcol = ipiv[j] - 1;
      controlAerobi_B.smax_o = A[j << 1];
      A[j << 1] = A[jBcol << 1];
      A[jBcol << 1] = controlAerobi_B.smax_o;
      controlAerobi_B.smax_o = A[(j << 1) + 1];
      A[1 + (j << 1)] = A[(jBcol << 1) + 1];
      A[1 + (jBcol << 1)] = controlAerobi_B.smax_o;
    }
  }
}

// Model step function
void controlAerobi_step(void)
{
  char_T *sErr;
  static const real_T d_a[3] = { 0.00174321135381858, 0.00129129620273212,
    0.00183162832067774 };

  static const int8_T c_b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T e_b[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  static const int8_T c_b_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T d_b[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  int32_T distorsioned;
  static const int8_T e_a[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  int32_T o;
  static const int8_T b[10] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T b_b[100] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1 };

  static const int8_T c[30] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[30] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T e[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T b_a[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  int32_T r2;
  int32_T r3;
  static const int8_T b_0[6] = { 0, 1, 0, 0, 0, 0 };

  static const int8_T c_0[6] = { 0, 0, 0, 1, 0, 0 };

  static const int8_T d_0[6] = { 0, 0, 0, 0, 0, 1 };

  static const real_T e_0[6] = { 0.0, 0.05, 0.0, 0.05, 0.0, 0.05 };

  static const int8_T b_b_0[18] = { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0 };

  static const int8_T a[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  int8_T Q[4];
  static const real_T a_0[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0 };

  static const real_T b_a_0[18] = { 3.125E-6, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 3.125E-6, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.125E-6, 0.0025 };

  static const real_T b_1[36] = { 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const int8_T b_b_1[30] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 };

  static const int8_T c_a[30] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };

  static const real_T a_1[4] = { 0.348, 0.0, 0.0, 0.348 };

  static const real_T b_b_2[8] = { 0.348, 0.0, 0.0, 0.348, 1.0, 0.0, 0.0, 1.0 };

  static const real_T b_a_1[8] = { 0.348, 0.0, 1.0, 0.0, 0.0, 0.348, 0.0, 1.0 };

  static const real_T b_2[6] = { 0.0, 2.5E-5, 0.0, 2.5E-5, 0.0, 2.5E-5 };

  static const real_T a_2[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0 };

  static const int8_T b_b_3[18] = { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0 };

  static const real_T c_b_1[36] = { 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const int8_T b_a_2[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0 };

  static const real_T b_3[6] = { 0.0, 0.0025, 0.0, 0.0025, 0.0, 0.0025 };

  static const real_T a_3[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0 };

  static const int8_T b_b_4[18] = { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0 };

  static const real_T c_b_2[36] = { 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const int8_T b_a_3[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0 };

  static const int8_T b_4[3] = { 0, 0, 1 };

  static const real_T b_5[6] = { 0.0, 2.5E-5, 0.0, 2.5E-5, 0.0, 2.5E-5 };

  static const real_T a_4[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0 };

  static const int8_T b_b_5[18] = { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0 };

  static const real_T c_b_3[36] = { 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const int8_T b_a_4[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0 };

  static const real_T b_6[6] = { 0.0, 0.0025, 0.0, 0.0025, 0.0, 0.0025 };

  static const real_T a_5[36] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025, 1.0 };

  static const int8_T b_b_6[18] = { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0 };

  static const real_T c_b_4[36] = { 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0025, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  static const int8_T b_a_5[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0 };

  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator_e;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LowerRelop1_k[4];
  boolean_T rtb_EnableGeometricControl;
  int32_T i;
  real32_T rtb_DataTypeConversion_a_idx_0;
  real32_T rtb_DataTypeConversion_a_idx_1;
  real32_T rtb_DataTypeConversion_a_idx_2;
  boolean_T exitg1;

  // RelationalOperator: '<S159>/Compare' incorporates:
  //   Constant: '<S159>/Constant'
  //   DataTypeConversion: '<S155>/Data Type Conversion1'
  //   Inport: '<Root>/I_RCinput'

  controlAerobi_B.Compare = (controlAerobi_U.I_RCinput._channel8 >=
    controlAerobi_P.CompareToConstant1_const);

  // Switch: '<S90>/Switch' incorporates:
  //   Constant: '<S90>/Constant1'
  //   Constant: '<S90>/Constant2'

  if (controlAerobi_B.Compare) {
    controlAerobi_B.Switch_b5 = controlAerobi_P.Constant1_Value_f;
  } else {
    controlAerobi_B.Switch_b5 = controlAerobi_P.Constant2_Value;
  }

  // End of Switch: '<S90>/Switch'

  // S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  sErr = GetErrorBuffer(&controlAerobi_DWork.PX4receive_NetworkLib[0U]);
  o = 11;
  LibOutputs_Network(&controlAerobi_DWork.PX4receive_NetworkLib[0U],
                     &controlAerobi_B.PX4receive_o1[0U], &o);
  if (*sErr != 0) {
    rtmSetErrorStatus(controlAerobi_M, sErr);
    rtmSetStopRequested(controlAerobi_M, 1);
  }

  // S-Function (any2byte): '<S120>/Byte Pack'

  // Pack: <S120>/Byte Pack
  (void) memcpy(&controlAerobi_B.BytePack[0], &controlAerobi_B.PX4receive_o1[0],
                44);

  // S-Function (byte2any): '<S120>/Byte Unpack'

  // Unpack: <S120>/Byte Unpack
  (void) memcpy(&controlAerobi_B.ByteUnpack_o1[0], &controlAerobi_B.BytePack[0],
                40);
  (void) memcpy(&controlAerobi_B.ByteUnpack_o2, &controlAerobi_B.BytePack[40],
                4);

  // DataTypeConversion: '<S120>/single2double  '
  for (i = 0; i < 10; i++) {
    controlAerobi_B.DataTypeConversion_b[i] = controlAerobi_B.ByteUnpack_o1[i];
  }

  // End of DataTypeConversion: '<S120>/single2double  '

  // Switch: '<S119>/Switch' incorporates:
  //   Constant: '<S119>/Constant'
  //   Product: '<S121>/Product'
  //   Product: '<S121>/Product1'
  //   Product: '<S121>/Product2'
  //   Product: '<S121>/Product3'
  //   Sum: '<S121>/Sum'

  if (((controlAerobi_B.DataTypeConversion_b[3] *
        controlAerobi_B.DataTypeConversion_b[3] +
        controlAerobi_B.DataTypeConversion_b[4] *
        controlAerobi_B.DataTypeConversion_b[4]) +
       controlAerobi_B.DataTypeConversion_b[5] *
       controlAerobi_B.DataTypeConversion_b[5]) +
      controlAerobi_B.DataTypeConversion_b[6] *
      controlAerobi_B.DataTypeConversion_b[6] > controlAerobi_P.Switch_Threshold)
  {
    controlAerobi_B.Switch_ed[0] = controlAerobi_B.DataTypeConversion_b[3];
    controlAerobi_B.Switch_ed[1] = controlAerobi_B.DataTypeConversion_b[4];
    controlAerobi_B.Switch_ed[2] = controlAerobi_B.DataTypeConversion_b[5];
    controlAerobi_B.Switch_ed[3] = controlAerobi_B.DataTypeConversion_b[6];
  } else {
    controlAerobi_B.Switch_ed[0] = controlAerobi_P.Constant_Value_ab[0];
    controlAerobi_B.Switch_ed[1] = controlAerobi_P.Constant_Value_ab[1];
    controlAerobi_B.Switch_ed[2] = controlAerobi_P.Constant_Value_ab[2];
    controlAerobi_B.Switch_ed[3] = controlAerobi_P.Constant_Value_ab[3];
  }

  // End of Switch: '<S119>/Switch'

  // Sqrt: '<S125>/sqrt' incorporates:
  //   Product: '<S126>/Product'
  //   Product: '<S126>/Product1'
  //   Product: '<S126>/Product2'
  //   Product: '<S126>/Product3'
  //   Sum: '<S126>/Sum'

  controlAerobi_B.Product1_ew = sqrt(((controlAerobi_B.Switch_ed[0] *
    controlAerobi_B.Switch_ed[0] + controlAerobi_B.Switch_ed[1] *
    controlAerobi_B.Switch_ed[1]) + controlAerobi_B.Switch_ed[2] *
    controlAerobi_B.Switch_ed[2]) + controlAerobi_B.Switch_ed[3] *
    controlAerobi_B.Switch_ed[3]);

  // Product: '<S124>/Product'
  controlAerobi_B.Zgain_a = controlAerobi_B.Switch_ed[0] /
    controlAerobi_B.Product1_ew;

  // Product: '<S124>/Product1'
  controlAerobi_B.Abs_a = controlAerobi_B.Switch_ed[1] /
    controlAerobi_B.Product1_ew;

  // Product: '<S124>/Product2'
  controlAerobi_B.Product1_a1 = controlAerobi_B.Switch_ed[2] /
    controlAerobi_B.Product1_ew;

  // Product: '<S124>/Product3'
  controlAerobi_B.Product1_ew = controlAerobi_B.Switch_ed[3] /
    controlAerobi_B.Product1_ew;

  // Trigonometry: '<S123>/Trigonometric Function1' incorporates:
  //   Fcn: '<S122>/fcn1'
  //   Fcn: '<S122>/fcn2'

  controlAerobi_B.Gain_po[0] = rt_atan2d_snf((controlAerobi_B.Abs_a *
    controlAerobi_B.Product1_a1 + controlAerobi_B.Zgain_a *
    controlAerobi_B.Product1_ew) * 2.0, ((controlAerobi_B.Zgain_a *
    controlAerobi_B.Zgain_a + controlAerobi_B.Abs_a * controlAerobi_B.Abs_a) -
    controlAerobi_B.Product1_a1 * controlAerobi_B.Product1_a1) -
    controlAerobi_B.Product1_ew * controlAerobi_B.Product1_ew);

  // Fcn: '<S122>/fcn3'
  controlAerobi_B.absxk = (controlAerobi_B.Abs_a * controlAerobi_B.Product1_ew -
    controlAerobi_B.Zgain_a * controlAerobi_B.Product1_a1) * -2.0;

  // Trigonometry: '<S123>/trigFcn'
  if (controlAerobi_B.absxk > 1.0) {
    controlAerobi_B.absxk = 1.0;
  } else {
    if (controlAerobi_B.absxk < -1.0) {
      controlAerobi_B.absxk = -1.0;
    }
  }

  controlAerobi_B.Gain_po[1] = asin(controlAerobi_B.absxk);

  // End of Trigonometry: '<S123>/trigFcn'

  // Fcn: '<S122>/fcn4'
  controlAerobi_B.DiscreteTimeIntegrator_b = (controlAerobi_B.Product1_a1 *
    controlAerobi_B.Product1_ew + controlAerobi_B.Zgain_a *
    controlAerobi_B.Abs_a) * 2.0;

  // Fcn: '<S122>/fcn5'
  controlAerobi_B.Zgain_a = ((controlAerobi_B.Zgain_a * controlAerobi_B.Zgain_a
    - controlAerobi_B.Abs_a * controlAerobi_B.Abs_a) -
    controlAerobi_B.Product1_a1 * controlAerobi_B.Product1_a1) +
    controlAerobi_B.Product1_ew * controlAerobi_B.Product1_ew;

  // Trigonometry: '<S123>/Trigonometric Function3'
  controlAerobi_B.Gain_po[2] = rt_atan2d_snf
    (controlAerobi_B.DiscreteTimeIntegrator_b, controlAerobi_B.Zgain_a);

  // Gain: '<S119>/Rotation Angles  correction'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.RotationAnglescorrection[i] =
      controlAerobi_P.RotationAnglescorrection_Gain[i + 6] *
      controlAerobi_B.Gain_po[2] +
      (controlAerobi_P.RotationAnglescorrection_Gain[i + 3] *
       controlAerobi_B.Gain_po[1] +
       controlAerobi_P.RotationAnglescorrection_Gain[i] *
       controlAerobi_B.Gain_po[0]);
  }

  // End of Gain: '<S119>/Rotation Angles  correction'

  // S-Function (sdspunwrap2): '<S119>/Unwrap'
  if (controlAerobi_DWork.Unwrap_FirstStep) {
    controlAerobi_DWork.Unwrap_Prev = controlAerobi_B.RotationAnglescorrection[2];
    controlAerobi_DWork.Unwrap_FirstStep = false;
  }

  controlAerobi_B.Sum = controlAerobi_DWork.Unwrap_Cumsum;
  controlAerobi_B.Unwrap = controlAerobi_B.RotationAnglescorrection[2] -
    controlAerobi_DWork.Unwrap_Prev;
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_B.Unwrap - floor
    ((controlAerobi_B.Unwrap + 3.1415926535897931) / 6.2831853071795862) *
    6.2831853071795862;
  if ((controlAerobi_B.DiscreteTimeIntegrator_b == -3.1415926535897931) &&
      (controlAerobi_B.Unwrap > 0.0)) {
    controlAerobi_B.DiscreteTimeIntegrator_b = 3.1415926535897931;
  }

  controlAerobi_B.Unwrap = controlAerobi_B.DiscreteTimeIntegrator_b -
    controlAerobi_B.Unwrap;
  if (fabs(controlAerobi_B.Unwrap) > 3.1415926535897931) {
    controlAerobi_B.Sum = controlAerobi_DWork.Unwrap_Cumsum +
      controlAerobi_B.Unwrap;
  }

  controlAerobi_B.Unwrap = controlAerobi_B.RotationAnglescorrection[2] +
    controlAerobi_B.Sum;
  controlAerobi_DWork.Unwrap_Prev = controlAerobi_B.RotationAnglescorrection[2];
  controlAerobi_DWork.Unwrap_Cumsum = controlAerobi_B.Sum;

  // End of S-Function (sdspunwrap2): '<S119>/Unwrap'

  // DataTypeConversion: '<S101>/Data Type Conversion' incorporates:
  //   Inport: '<Root>/I_imu_mpu'

  controlAerobi_B.DataTypeConversion_b[0] =
    controlAerobi_U.I_imu_mpu._temperature;
  controlAerobi_B.DataTypeConversion_b[1] = controlAerobi_U.I_imu_mpu._ax;
  controlAerobi_B.DataTypeConversion_b[2] = controlAerobi_U.I_imu_mpu._ay;
  controlAerobi_B.DataTypeConversion_b[3] = controlAerobi_U.I_imu_mpu._az;
  controlAerobi_B.DataTypeConversion_b[4] = controlAerobi_U.I_imu_mpu._gx;
  controlAerobi_B.DataTypeConversion_b[5] = controlAerobi_U.I_imu_mpu._gy;
  controlAerobi_B.DataTypeConversion_b[6] = controlAerobi_U.I_imu_mpu._gz;
  controlAerobi_B.DataTypeConversion_b[7] = controlAerobi_U.I_imu_mpu._mx;
  controlAerobi_B.DataTypeConversion_b[8] = controlAerobi_U.I_imu_mpu._my;
  controlAerobi_B.DataTypeConversion_b[9] = controlAerobi_U.I_imu_mpu._mz;

  // Sum: '<S110>/Add' incorporates:
  //   Constant: '<S110>/Bias gyro'
  //   DataTypeConversion: '<S101>/Data Type Conversion'
  //   Inport: '<Root>/I_imu_mpu'

  controlAerobi_B.Add[0] = controlAerobi_U.I_imu_mpu._gx -
    controlAerobi_P.Biasgyro_Value[0];
  controlAerobi_B.Add[1] = controlAerobi_U.I_imu_mpu._gy -
    controlAerobi_P.Biasgyro_Value[1];
  controlAerobi_B.Add[2] = controlAerobi_U.I_imu_mpu._gz -
    controlAerobi_P.Biasgyro_Value[2];

  // MATLAB Function: '<S110>/MATLAB Function' incorporates:
  //   Constant: '<S110>/reset'

  // MATLAB Function 'Sensors/attitude/AttitudeEstimator/calib gyro mpu/MATLAB Function': '<S136>:1' 
  if ((!controlAerobi_DWork.offset_not_empty) ||
      (!controlAerobi_DWork.num_not_empty) ||
      (!controlAerobi_DWork.state_not_empty) ||
      (!controlAerobi_DWork.suma_not_empty)) {
    // '<S136>:1:4'
    // '<S136>:1:5'
    controlAerobi_DWork.suma_not_empty = true;

    // '<S136>:1:6'
    controlAerobi_DWork.suma[0] = 0.0;
    controlAerobi_DWork.offset[0] = 0.0;
    controlAerobi_DWork.suma[1] = 0.0;
    controlAerobi_DWork.offset[1] = 0.0;
    controlAerobi_DWork.suma[2] = 0.0;
    controlAerobi_DWork.offset[2] = 0.0;
    controlAerobi_DWork.offset_not_empty = true;

    // '<S136>:1:7'
    controlAerobi_DWork.num = 0.0;
    controlAerobi_DWork.num_not_empty = true;

    // '<S136>:1:8'
    controlAerobi_DWork.state = 0.0;
    controlAerobi_DWork.state_not_empty = true;
  } else if ((controlAerobi_P.reset_Value == 0.0) && (controlAerobi_DWork.state ==
              0.0)) {
    // '<S136>:1:10'
    // '<S136>:1:11'
    controlAerobi_DWork.suma[0] += controlAerobi_B.Add[0];
    controlAerobi_DWork.suma[1] += controlAerobi_B.Add[1];
    controlAerobi_DWork.suma[2] += controlAerobi_B.Add[2];

    // '<S136>:1:12'
    controlAerobi_DWork.num++;
  } else if ((controlAerobi_P.reset_Value == 1.0) && (controlAerobi_DWork.state ==
              0.0)) {
    // '<S136>:1:13'
    if (controlAerobi_DWork.num != 0.0) {
      // '<S136>:1:14'
      // '<S136>:1:15'
      controlAerobi_DWork.offset[0] = controlAerobi_DWork.suma[0] /
        controlAerobi_DWork.num;
      controlAerobi_DWork.offset[1] = controlAerobi_DWork.suma[1] /
        controlAerobi_DWork.num;
      controlAerobi_DWork.offset[2] = controlAerobi_DWork.suma[2] /
        controlAerobi_DWork.num;
    }

    // '<S136>:1:17'
    controlAerobi_DWork.state = 1.0;
  } else {
    if ((controlAerobi_P.reset_Value == 0.0) && (controlAerobi_DWork.state ==
         1.0)) {
      // '<S136>:1:18'
      // '<S136>:1:19'
      controlAerobi_DWork.state = 0.0;

      // '<S136>:1:20'
      controlAerobi_DWork.suma[0] = 0.0;
      controlAerobi_DWork.suma[1] = 0.0;
      controlAerobi_DWork.suma[2] = 0.0;

      // '<S136>:1:21'
      controlAerobi_DWork.num = 0.0;
    }
  }

  // Sum: '<S108>/Add' incorporates:
  //   Constant: '<S108>/Bias accel'
  //   DataTypeConversion: '<S101>/Data Type Conversion'
  //   Inport: '<Root>/I_imu_mpu'
  //   Product: '<S108>/Product'

  // '<S136>:1:24'
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_U.I_imu_mpu._ax -
    controlAerobi_P.Biasaccel_Value[0];
  controlAerobi_B.Sum = controlAerobi_U.I_imu_mpu._ay -
    controlAerobi_P.Biasaccel_Value[1];
  controlAerobi_B.b_exp_b = controlAerobi_U.I_imu_mpu._az -
    controlAerobi_P.Biasaccel_Value[2];
  for (i = 0; i < 3; i++) {
    // Sum: '<S112>/Add' incorporates:
    //   Constant: '<S112>/Bias magnet'
    //   Product: '<S112>/Product'

    controlAerobi_B.Add_j[i] = controlAerobi_B.DataTypeConversion_b[7 + i] -
      controlAerobi_P.Biasmagnet_Value[i];

    // Product: '<S108>/Product' incorporates:
    //   Constant: '<S108>/M accel'

    controlAerobi_B.Gain_po[i] = controlAerobi_P.Maccel_Value[i + 6] *
      controlAerobi_B.b_exp_b + (controlAerobi_P.Maccel_Value[i + 3] *
      controlAerobi_B.Sum + controlAerobi_P.Maccel_Value[i] *
      controlAerobi_B.DiscreteTimeIntegrator_b);
  }

  for (i = 0; i < 3; i++) {
    // Product: '<S112>/Product' incorporates:
    //   Constant: '<S112>/M magnet'

    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_P.Mmagnet_Value[i +
      6] * controlAerobi_B.Add_j[2] + (controlAerobi_P.Mmagnet_Value[i + 3] *
      controlAerobi_B.Add_j[1] + controlAerobi_P.Mmagnet_Value[i] *
      controlAerobi_B.Add_j[0]);

    // Switch: '<S148>/Switch' incorporates:
    //   Constant: '<S148>/Constant'
    //   RelationalOperator: '<S148>/Relational Operator'

    if (rtIsNaN(controlAerobi_B.DiscreteTimeIntegrator_b)) {
      controlAerobi_B.Switch[i] = controlAerobi_P.Constant_Value_p[i];
    } else {
      controlAerobi_B.Switch[i] = controlAerobi_B.DiscreteTimeIntegrator_b;
    }

    // End of Switch: '<S148>/Switch'
  }

  // MATLAB Function: '<S147>/Embedded MATLAB Function1' incorporates:
  //   Constant: '<S117>/limit'

  // MATLAB Function 'Sensors/attitude/AttitudeEstimator/mpu9250/Mahoney_estimator/Embedded MATLAB Function1': '<S149>:1' 
  // '<S149>:1:77'
  // '<S149>:1:33'
  // '<S149>:1:20'
  // '<S149>:1:29'
  // '<S149>:1:3'
  if ((!controlAerobi_DWork.b__not_empty) || (!controlAerobi_DWork.q__not_empty)
      || (!controlAerobi_DWork.mi_not_empty) ||
      (!controlAerobi_DWork.e3_not_empty)) {
    // '<S149>:1:6'
    // '<S149>:1:7'
    controlAerobi_DWork.q_[0] = cos(rt_atan2d_snf(-controlAerobi_B.Switch[1],
      controlAerobi_B.Switch[0]) / 2.0);
    controlAerobi_DWork.q_[1] = 0.0;
    controlAerobi_DWork.q_[2] = 0.0;
    controlAerobi_DWork.q_[3] = sin(rt_atan2d_snf(-controlAerobi_B.Switch[1],
      controlAerobi_B.Switch[0]) / 2.0);
    controlAerobi_DWork.q__not_empty = true;

    // '<S149>:1:8'
    controlAerobi_DWork.b__not_empty = true;

    // '<S149>:1:9'
    controlAerobi_DWork.mi_not_empty = true;

    // '<S149>:1:10'
    controlAerobi_DWork.b_[0] = 4.69268378119671E-6;
    controlAerobi_DWork.mi[0] = 0.5879;
    controlAerobi_DWork.e3[0] = 0.0;
    controlAerobi_DWork.b_[1] = 4.89432680601499E-6;
    controlAerobi_DWork.mi[1] = 0.0081;
    controlAerobi_DWork.e3[1] = 0.0;
    controlAerobi_DWork.b_[2] = 6.85616463287125E-6;
    controlAerobi_DWork.mi[2] = 0.8091;
    controlAerobi_DWork.e3[2] = 1.0;
    controlAerobi_DWork.e3_not_empty = true;
  }

  // '<S149>:1:14'
  controlAerobi_B.y_k_idx_1 = controlAerobi_DWork.q_[0] *
    controlAerobi_DWork.q_[0];
  controlAerobi_B.y_k_idx_0 = controlAerobi_DWork.q_[1] *
    controlAerobi_DWork.q_[1];
  controlAerobi_B.Product1_ew = controlAerobi_DWork.q_[2] *
    controlAerobi_DWork.q_[2];
  controlAerobi_B.Abs_a = controlAerobi_DWork.q_[3] * controlAerobi_DWork.q_[3];
  controlAerobi_B.R_[0] = ((controlAerobi_B.y_k_idx_1 +
    controlAerobi_B.y_k_idx_0) - controlAerobi_B.Product1_ew) -
    controlAerobi_B.Abs_a;
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.q_[1] *
    controlAerobi_DWork.q_[2];
  controlAerobi_B.Sum = controlAerobi_DWork.q_[0] * controlAerobi_DWork.q_[3];
  controlAerobi_B.R_[3] = (controlAerobi_B.DiscreteTimeIntegrator_b -
    controlAerobi_B.Sum) * 2.0;
  controlAerobi_B.b_exp_b = controlAerobi_DWork.q_[1] * controlAerobi_DWork.q_[3];
  controlAerobi_B.sinc = controlAerobi_DWork.q_[0] * controlAerobi_DWork.q_[2];
  controlAerobi_B.R_[6] = (controlAerobi_B.sinc + controlAerobi_B.b_exp_b) * 2.0;
  controlAerobi_B.R_[1] = (controlAerobi_B.DiscreteTimeIntegrator_b +
    controlAerobi_B.Sum) * 2.0;
  controlAerobi_B.y_k_idx_1 -= controlAerobi_B.y_k_idx_0;
  controlAerobi_B.R_[4] = (controlAerobi_B.y_k_idx_1 +
    controlAerobi_B.Product1_ew) - controlAerobi_B.Abs_a;
  controlAerobi_B.y_k_idx_0 = controlAerobi_DWork.q_[0] *
    controlAerobi_DWork.q_[1];
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.q_[2] *
    controlAerobi_DWork.q_[3];
  controlAerobi_B.R_[7] = (controlAerobi_B.DiscreteTimeIntegrator_b -
    controlAerobi_B.y_k_idx_0) * 2.0;
  controlAerobi_B.R_[2] = (controlAerobi_B.b_exp_b - controlAerobi_B.sinc) * 2.0;
  controlAerobi_B.R_[5] = (controlAerobi_B.y_k_idx_0 +
    controlAerobi_B.DiscreteTimeIntegrator_b) * 2.0;
  controlAerobi_B.R_[8] = (controlAerobi_B.y_k_idx_1 -
    controlAerobi_B.Product1_ew) + controlAerobi_B.Abs_a;

  // '<S149>:1:20'
  // '<S149>:1:25'
  controlAerobi_B.ub[0] = controlAerobi_B.Gain_po[0];
  controlAerobi_B.ub[1] = controlAerobi_B.Gain_po[1];
  controlAerobi_B.ub[2] = controlAerobi_B.Gain_po[2];

  // '<S149>:1:27'
  // '<S149>:1:29'
  controlAerobi_B.absxk = norm_OKjrfDiG(controlAerobi_B.ub);
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_B.absxk *
    controlAerobi_B.absxk;

  // '<S149>:1:30'
  controlAerobi_B.b_exp_b = norm_OKjrfDiG(controlAerobi_DWork.e3);
  controlAerobi_B.Sum = controlAerobi_B.b_exp_b * controlAerobi_B.b_exp_b;

  // '<S149>:1:33'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.b_exp_b = controlAerobi_B.Sum * (real_T)c_b[i] -
      controlAerobi_DWork.e3[i] * controlAerobi_DWork.e3[0];
    controlAerobi_B.P_ui[i] = controlAerobi_B.b_exp_b;
    controlAerobi_B.sinc = controlAerobi_B.b_exp_b * controlAerobi_DWork.mi[0];
    controlAerobi_B.b_exp_b = (real_T)c_b[i + 3] * controlAerobi_B.Sum -
      controlAerobi_DWork.e3[i] * controlAerobi_DWork.e3[1];
    controlAerobi_B.P_ui[i + 3] = controlAerobi_B.b_exp_b;
    controlAerobi_B.sinc += controlAerobi_B.b_exp_b * controlAerobi_DWork.mi[1];
    controlAerobi_B.b_exp_b = (real_T)c_b[i + 6] * controlAerobi_B.Sum -
      controlAerobi_DWork.e3[i] * controlAerobi_DWork.e3[2];
    controlAerobi_B.P_ui[i + 6] = controlAerobi_B.b_exp_b;
    controlAerobi_B.sinc += controlAerobi_B.b_exp_b * controlAerobi_DWork.mi[2];
    controlAerobi_B.P_ui_o[i] = controlAerobi_B.sinc;
  }

  controlAerobi_B.Sum = norm_OKjrfDiG(controlAerobi_B.P_ui_o);

  // '<S149>:1:35'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.P_ui_o[i] = controlAerobi_B.P_ui[i + 6] *
      controlAerobi_DWork.mi[2] + (controlAerobi_B.P_ui[i + 3] *
      controlAerobi_DWork.mi[1] + controlAerobi_B.P_ui[i] *
      controlAerobi_DWork.mi[0]);
  }

  controlAerobi_B.b_exp_b = norm_OKjrfDiG(controlAerobi_B.P_ui_o);

  // '<S149>:1:36'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.Gain_po[i] = ((((real_T)c_b[i + 3] *
      controlAerobi_B.DiscreteTimeIntegrator_b - controlAerobi_B.ub[i] *
      controlAerobi_B.ub[1]) * controlAerobi_B.Switch[1] +
      (controlAerobi_B.DiscreteTimeIntegrator_b * (real_T)c_b[i] -
       controlAerobi_B.ub[i] * controlAerobi_B.ub[0]) * controlAerobi_B.Switch[0])
      + ((real_T)c_b[i + 6] * controlAerobi_B.DiscreteTimeIntegrator_b -
         controlAerobi_B.ub[i] * controlAerobi_B.ub[2]) *
      controlAerobi_B.Switch[2]) / controlAerobi_B.b_exp_b;
    controlAerobi_B.ub_[i] = ((controlAerobi_B.R_[3 * i + 1] *
      controlAerobi_DWork.e3[1] + controlAerobi_B.R_[3 * i] *
      controlAerobi_DWork.e3[0]) + controlAerobi_B.R_[3 * i + 2] *
      controlAerobi_DWork.e3[2]) + d_a[i];
    controlAerobi_B.P_ui_o[i] = controlAerobi_B.P_ui[i + 6] *
      controlAerobi_DWork.mi[2] + (controlAerobi_B.P_ui[i + 3] *
      controlAerobi_DWork.mi[1] + controlAerobi_B.P_ui[i] *
      controlAerobi_DWork.mi[0]);
  }

  controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
    (controlAerobi_B.P_ui_o);

  // '<S149>:1:38'
  // '<S149>:1:39'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.R_d_m[i] = d_a[i] * controlAerobi_DWork.e3[0];
    controlAerobi_B.Re_R[i] = controlAerobi_DWork.e3[i] * 0.00174321135381858;
    controlAerobi_B.R_d_m[i + 3] = d_a[i] * controlAerobi_DWork.e3[1];
    controlAerobi_B.Re_R[i + 3] = controlAerobi_DWork.e3[i] *
      0.00129129620273212;
    controlAerobi_B.R_d_m[i + 6] = d_a[i] * controlAerobi_DWork.e3[2];
    controlAerobi_B.Re_R[i + 6] = controlAerobi_DWork.e3[i] *
      0.00183162832067774;
    controlAerobi_B.P_ui_o[i] = ((controlAerobi_B.P_ui[i + 3] *
      controlAerobi_DWork.mi[1] + controlAerobi_B.P_ui[i] *
      controlAerobi_DWork.mi[0]) + controlAerobi_B.P_ui[i + 6] *
      controlAerobi_DWork.mi[2]) / controlAerobi_B.DiscreteTimeIntegrator_b;
  }

  for (i = 0; i < 3; i++) {
    controlAerobi_B.d_a[3 * i] = controlAerobi_B.R_d_m[3 * i] +
      controlAerobi_B.Re_R[3 * i];
    distorsioned = 3 * i + 1;
    controlAerobi_B.d_a[1 + 3 * i] = controlAerobi_B.R_d_m[distorsioned] +
      controlAerobi_B.Re_R[distorsioned];
    distorsioned = 3 * i + 2;
    controlAerobi_B.d_a[2 + 3 * i] = controlAerobi_B.R_d_m[distorsioned] +
      controlAerobi_B.Re_R[distorsioned];
  }

  for (i = 0; i < 3; i++) {
    controlAerobi_B.Switch[i] = ((controlAerobi_B.R_[3 * i + 1] *
      controlAerobi_B.P_ui_o[1] + controlAerobi_B.R_[3 * i] *
      controlAerobi_B.P_ui_o[0]) + controlAerobi_B.R_[3 * i + 2] *
      controlAerobi_B.P_ui_o[2]) + -((controlAerobi_B.d_a[i + 6] *
      controlAerobi_DWork.mi[2] + (controlAerobi_B.d_a[i + 3] *
      controlAerobi_DWork.mi[1] + controlAerobi_B.d_a[i] *
      controlAerobi_DWork.mi[0])) + (controlAerobi_B.P_ui[i + 6] *
      0.0318810919418866 + (controlAerobi_B.P_ui[i + 3] * 0.00516051356214765 +
      controlAerobi_B.P_ui[i] * 0.00495318658314336))) / controlAerobi_B.Sum;
  }

  // '<S149>:1:42'
  controlAerobi_B.ubx_d[0] = controlAerobi_B.ub[1] * controlAerobi_B.ub_[2] -
    controlAerobi_B.ub[2] * controlAerobi_B.ub_[1];
  controlAerobi_B.ubx_d[1] = controlAerobi_B.ub[2] * controlAerobi_B.ub_[0] -
    controlAerobi_B.ub[0] * controlAerobi_B.ub_[2];
  controlAerobi_B.ubx_d[2] = controlAerobi_B.ub[0] * controlAerobi_B.ub_[1] -
    controlAerobi_B.ub[1] * controlAerobi_B.ub_[0];

  // '<S149>:1:43'
  controlAerobi_B.vbx[0] = controlAerobi_B.Gain_po[1] * controlAerobi_B.Switch[2]
    - controlAerobi_B.Gain_po[2] * controlAerobi_B.Switch[1];
  controlAerobi_B.vbx[1] = controlAerobi_B.Gain_po[2] * controlAerobi_B.Switch[0]
    - controlAerobi_B.Gain_po[0] * controlAerobi_B.Switch[2];
  controlAerobi_B.vbx[2] = controlAerobi_B.Gain_po[0] * controlAerobi_B.Switch[1]
    - controlAerobi_B.Gain_po[1] * controlAerobi_B.Switch[0];

  // '<S149>:1:45'
  // '<S149>:1:47'
  // '<S149>:1:50'
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_P.limit_Value /
    norm_OKjrfDiG(controlAerobi_DWork.b_);
  if ((1.0 < controlAerobi_B.DiscreteTimeIntegrator_b) || rtIsNaN
      (controlAerobi_B.DiscreteTimeIntegrator_b)) {
    controlAerobi_B.DiscreteTimeIntegrator_b = 1.0;
  }

  // '<S149>:1:52'
  // '<S149>:1:56'
  for (i = 0; i < 3; i++) {
    // MATLAB Function: '<S110>/MATLAB Function' incorporates:
    //   Product: '<S110>/Product'

    controlAerobi_B.P_ui_o[i] = controlAerobi_B.Add[i] -
      controlAerobi_DWork.offset[i];

    // MATLAB Function: '<S147>/Embedded MATLAB Function1'
    controlAerobi_B.R_d_m[i] = controlAerobi_B.ub_[i] * controlAerobi_B.ub_[0];
    controlAerobi_B.R_d_m[i + 3] = controlAerobi_B.ub_[i] * controlAerobi_B.ub_
      [1];
    controlAerobi_B.R_d_m[i + 6] = controlAerobi_B.ub_[i] * controlAerobi_B.ub_
      [2];
  }

  // MATLAB Function: '<S147>/Embedded MATLAB Function1' incorporates:
  //   Constant: '<S110>/M gyro'
  //   Constant: '<S117>/k1'
  //   Constant: '<S117>/k2'
  //   Product: '<S110>/Product'

  for (i = 0; i < 3; i++) {
    controlAerobi_B.Re_R[3 * i] = controlAerobi_B.R_d_m[3 * i] *
      controlAerobi_P.k2_Value;
    controlAerobi_B.Re_R[1 + 3 * i] = controlAerobi_B.R_d_m[3 * i + 1] *
      controlAerobi_P.k2_Value;
    controlAerobi_B.Re_R[2 + 3 * i] = controlAerobi_B.R_d_m[3 * i + 2] *
      controlAerobi_P.k2_Value;
    controlAerobi_B.rtb_Gain_po_l[i] = ((controlAerobi_P.Mgyro_Value[i + 3] *
      controlAerobi_B.P_ui_o[1] + controlAerobi_P.Mgyro_Value[i] *
      controlAerobi_B.P_ui_o[0]) + controlAerobi_P.Mgyro_Value[i + 6] *
      controlAerobi_B.P_ui_o[2]) - controlAerobi_DWork.b_[i];
  }

  for (i = 0; i < 3; i++) {
    controlAerobi_B.ub[i] = (((controlAerobi_B.Re_R[i + 3] *
      controlAerobi_B.vbx[1] + controlAerobi_B.Re_R[i] * controlAerobi_B.vbx[0])
      + controlAerobi_B.Re_R[i + 6] * controlAerobi_B.vbx[2]) +
      controlAerobi_P.k1_Value * controlAerobi_B.ubx_d[i]) +
      controlAerobi_B.rtb_Gain_po_l[i];
  }

  // '<S149>:1:59'
  // '<S149>:1:64'
  // '<S149>:1:67'
  controlAerobi_B.b_exp_b = 0.00125 * norm_OKjrfDiG(controlAerobi_B.ub);
  if (controlAerobi_B.b_exp_b == 0.0) {
    // '<S149>:1:70'
    // '<S149>:1:71'
    controlAerobi_B.sinc = 1.0;
  } else {
    // '<S149>:1:73'
    controlAerobi_B.sinc = sin(controlAerobi_B.b_exp_b) /
      controlAerobi_B.b_exp_b;
  }

  // '<S149>:1:77'
  controlAerobi_B.Sum = cos(controlAerobi_B.b_exp_b);
  controlAerobi_B.b_exp_b = 0.00125 * controlAerobi_B.sinc;
  controlAerobi_B.R_f[0] = controlAerobi_B.b_exp_b * 0.0;
  controlAerobi_B.sinc = controlAerobi_B.b_exp_b * -controlAerobi_B.ub[0];
  controlAerobi_B.R_f[4] = controlAerobi_B.sinc;
  controlAerobi_B.R_f[1] = controlAerobi_B.b_exp_b * controlAerobi_B.ub[0];
  controlAerobi_B.rtb_Switch_Pos_idx_1 = controlAerobi_B.b_exp_b *
    -controlAerobi_B.ub[1];
  controlAerobi_B.R_f[8] = controlAerobi_B.rtb_Switch_Pos_idx_1;
  controlAerobi_B.R_f[2] = controlAerobi_B.b_exp_b * controlAerobi_B.ub[1];
  controlAerobi_B.absxk = controlAerobi_B.b_exp_b * -controlAerobi_B.ub[2];
  controlAerobi_B.R_f[12] = controlAerobi_B.absxk;
  controlAerobi_B.R_f[3] = controlAerobi_B.b_exp_b * controlAerobi_B.ub[2];
  controlAerobi_B.R_f[5] = controlAerobi_B.b_exp_b * -0.0;
  controlAerobi_B.R_f[9] = controlAerobi_B.b_exp_b * -(-controlAerobi_B.ub[2]);
  controlAerobi_B.R_f[13] = controlAerobi_B.rtb_Switch_Pos_idx_1;
  controlAerobi_B.R_f[6] = controlAerobi_B.absxk;
  controlAerobi_B.R_f[10] = controlAerobi_B.b_exp_b * -0.0;
  controlAerobi_B.R_f[14] = controlAerobi_B.b_exp_b * -(-controlAerobi_B.ub[0]);
  controlAerobi_B.R_f[7] = controlAerobi_B.b_exp_b * -(-controlAerobi_B.ub[1]);
  controlAerobi_B.R_f[11] = controlAerobi_B.sinc;
  controlAerobi_B.R_f[15] = controlAerobi_B.b_exp_b * -0.0;
  for (i = 0; i < 4; i++) {
    controlAerobi_B.rtb_Sum_g2[i << 2] = (real_T)e_b[i << 2] *
      controlAerobi_B.Sum + controlAerobi_B.R_f[i << 2];
    controlAerobi_B.rtb_Sum_g2[1 + (i << 2)] = (real_T)e_b[(i << 2) + 1] *
      controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 1];
    controlAerobi_B.rtb_Sum_g2[2 + (i << 2)] = (real_T)e_b[(i << 2) + 2] *
      controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 2];
    controlAerobi_B.rtb_Sum_g2[3 + (i << 2)] = (real_T)e_b[(i << 2) + 3] *
      controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 3];
  }

  for (i = 0; i < 4; i++) {
    controlAerobi_B.rtb_Switch_ed_f = controlAerobi_B.rtb_Sum_g2[i + 12] *
      controlAerobi_DWork.q_[3] + (controlAerobi_B.rtb_Sum_g2[i + 8] *
      controlAerobi_DWork.q_[2] + (controlAerobi_B.rtb_Sum_g2[i + 4] *
      controlAerobi_DWork.q_[1] + controlAerobi_B.rtb_Sum_g2[i] *
      controlAerobi_DWork.q_[0]));
    rtb_LowerRelop1_k[i] = rtIsNaN(controlAerobi_B.rtb_Switch_ed_f);
    controlAerobi_B.Switch_ed[i] = controlAerobi_B.rtb_Switch_ed_f;
  }

  rtb_LogicalOperator = true;
  o = 0;
  exitg1 = false;
  while ((!exitg1) && (o + 1 < 5)) {
    if (!rtb_LowerRelop1_k[o]) {
      rtb_LogicalOperator = false;
      exitg1 = true;
    } else {
      o++;
    }
  }

  if (rtb_LogicalOperator) {
    // '<S149>:1:79'
    controlAerobi_B.Switch_ed[0] = 1.0;
    controlAerobi_B.Switch_ed[1] = 0.0;
    controlAerobi_B.Switch_ed[2] = 0.0;
    controlAerobi_B.Switch_ed[3] = 0.0;
  }

  // '<S149>:1:81'
  controlAerobi_DWork.q_[0] = controlAerobi_B.Switch_ed[0];
  controlAerobi_DWork.q_[1] = controlAerobi_B.Switch_ed[1];
  controlAerobi_DWork.q_[2] = controlAerobi_B.Switch_ed[2];
  controlAerobi_DWork.q_[3] = controlAerobi_B.Switch_ed[3];

  // DataTypeConversion: '<S101>/Data Type Conversion1' incorporates:
  //   Inport: '<Root>/I_imu_lsm'

  // '<S149>:1:82'
  controlAerobi_B.DataTypeConversion1_n[0] =
    controlAerobi_U.I_imu_lsm._temperature;
  controlAerobi_B.DataTypeConversion1_n[1] = controlAerobi_U.I_imu_lsm._ax;
  controlAerobi_B.DataTypeConversion1_n[2] = controlAerobi_U.I_imu_lsm._ay;
  controlAerobi_B.DataTypeConversion1_n[3] = controlAerobi_U.I_imu_lsm._az;
  controlAerobi_B.DataTypeConversion1_n[4] = controlAerobi_U.I_imu_lsm._gx;
  controlAerobi_B.DataTypeConversion1_n[5] = controlAerobi_U.I_imu_lsm._gy;
  controlAerobi_B.DataTypeConversion1_n[6] = controlAerobi_U.I_imu_lsm._gz;
  controlAerobi_B.DataTypeConversion1_n[7] = controlAerobi_U.I_imu_lsm._mx;
  controlAerobi_B.DataTypeConversion1_n[8] = controlAerobi_U.I_imu_lsm._my;
  controlAerobi_B.DataTypeConversion1_n[9] = controlAerobi_U.I_imu_lsm._mz;

  // MATLAB Function: '<S147>/Embedded MATLAB Function1' incorporates:
  //   Constant: '<S117>/k3'
  //   Constant: '<S117>/k4'
  //   Constant: '<S117>/kb'

  controlAerobi_DWork.b_[0] += ((controlAerobi_DWork.b_[0] *
    controlAerobi_B.DiscreteTimeIntegrator_b * controlAerobi_P.kb_Value +
    -controlAerobi_P.kb_Value * controlAerobi_DWork.b_[0]) +
    (-controlAerobi_P.k3_Value * controlAerobi_B.ubx_d[0] -
     controlAerobi_P.k4_Value * controlAerobi_B.vbx[0])) * 0.0025;

  // Sum: '<S109>/Add' incorporates:
  //   Constant: '<S109>/Bias gyro'
  //   DataTypeConversion: '<S101>/Data Type Conversion1'
  //   Inport: '<Root>/I_imu_lsm'

  controlAerobi_B.Add[0] = controlAerobi_U.I_imu_lsm._gx -
    controlAerobi_P.Biasgyro_Value_n[0];

  // MATLAB Function: '<S147>/Embedded MATLAB Function1' incorporates:
  //   Constant: '<S117>/k3'
  //   Constant: '<S117>/k4'
  //   Constant: '<S117>/kb'

  controlAerobi_DWork.b_[1] += ((controlAerobi_DWork.b_[1] *
    controlAerobi_B.DiscreteTimeIntegrator_b * controlAerobi_P.kb_Value +
    -controlAerobi_P.kb_Value * controlAerobi_DWork.b_[1]) +
    (-controlAerobi_P.k3_Value * controlAerobi_B.ubx_d[1] -
     controlAerobi_P.k4_Value * controlAerobi_B.vbx[1])) * 0.0025;

  // Sum: '<S109>/Add' incorporates:
  //   Constant: '<S109>/Bias gyro'
  //   DataTypeConversion: '<S101>/Data Type Conversion1'
  //   Inport: '<Root>/I_imu_lsm'

  controlAerobi_B.Add[1] = controlAerobi_U.I_imu_lsm._gy -
    controlAerobi_P.Biasgyro_Value_n[1];

  // MATLAB Function: '<S147>/Embedded MATLAB Function1' incorporates:
  //   Constant: '<S117>/k3'
  //   Constant: '<S117>/k4'
  //   Constant: '<S117>/kb'

  controlAerobi_DWork.b_[2] += ((controlAerobi_DWork.b_[2] *
    controlAerobi_B.DiscreteTimeIntegrator_b * controlAerobi_P.kb_Value +
    -controlAerobi_P.kb_Value * controlAerobi_DWork.b_[2]) +
    (-controlAerobi_P.k3_Value * controlAerobi_B.ubx_d[2] -
     controlAerobi_P.k4_Value * controlAerobi_B.vbx[2])) * 0.0025;

  // Sum: '<S109>/Add' incorporates:
  //   Constant: '<S109>/Bias gyro'
  //   DataTypeConversion: '<S101>/Data Type Conversion1'
  //   Inport: '<Root>/I_imu_lsm'

  controlAerobi_B.Add[2] = controlAerobi_U.I_imu_lsm._gz -
    controlAerobi_P.Biasgyro_Value_n[2];

  // MATLAB Function: '<S109>/MATLAB Function'
  controlAerobi_MATLABFunction(controlAerobi_B.Add,
    &controlAerobi_B.sf_MATLABFunction_a,
    &controlAerobi_DWork.sf_MATLABFunction_a);
  for (i = 0; i < 3; i++) {
    // Sum: '<S107>/Add' incorporates:
    //   Constant: '<S107>/Bias accel'
    //   Product: '<S107>/Product'

    controlAerobi_B.Gain_po[i] = controlAerobi_B.DataTypeConversion1_n[1 + i] -
      controlAerobi_P.Biasaccel_Value_e[i];

    // Product: '<S109>/Product' incorporates:
    //   Constant: '<S109>/M gyro'

    controlAerobi_B.Add[i] = controlAerobi_P.Mgyro_Value_f[i + 6] *
      controlAerobi_B.sf_MATLABFunction_a.g_offset[2] +
      (controlAerobi_P.Mgyro_Value_f[i + 3] *
       controlAerobi_B.sf_MATLABFunction_a.g_offset[1] +
       controlAerobi_P.Mgyro_Value_f[i] *
       controlAerobi_B.sf_MATLABFunction_a.g_offset[0]);
  }

  for (i = 0; i < 3; i++) {
    // Product: '<S107>/Product' incorporates:
    //   Constant: '<S107>/M accel'

    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_P.Maccel_Value_p[i
      + 6] * controlAerobi_B.Gain_po[2] + (controlAerobi_P.Maccel_Value_p[i + 3]
      * controlAerobi_B.Gain_po[1] + controlAerobi_P.Maccel_Value_p[i] *
      controlAerobi_B.Gain_po[0]);

    // RateLimiter: '<S107>/Rate Limiter1'
    controlAerobi_B.Sum = controlAerobi_B.DiscreteTimeIntegrator_b -
      controlAerobi_DWork.PrevY[i];
    if (controlAerobi_B.Sum > controlAerobi_P.RateLimiter1_RisingLim) {
      controlAerobi_B.Sum = controlAerobi_DWork.PrevY[i] +
        controlAerobi_P.RateLimiter1_RisingLim;
    } else if (controlAerobi_B.Sum < controlAerobi_P.RateLimiter1_FallingLim) {
      controlAerobi_B.Sum = controlAerobi_DWork.PrevY[i] +
        controlAerobi_P.RateLimiter1_FallingLim;
    } else {
      controlAerobi_B.Sum = controlAerobi_B.DiscreteTimeIntegrator_b;
    }

    controlAerobi_DWork.PrevY[i] = controlAerobi_B.Sum;

    // Sum: '<S111>/Add' incorporates:
    //   Constant: '<S111>/Bias magnet'
    //   Product: '<S111>/Product'

    controlAerobi_B.ub_[i] = controlAerobi_B.DataTypeConversion1_n[7 + i] -
      controlAerobi_P.Biasmagnet_Value_k[i];

    // RateLimiter: '<S107>/Rate Limiter1'
    controlAerobi_B.Switch[i] = controlAerobi_B.Sum;
  }

  for (i = 0; i < 3; i++) {
    // Product: '<S111>/Product' incorporates:
    //   Constant: '<S111>/M magnet'

    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_P.Mmagnet_Value_c[i
      + 6] * controlAerobi_B.ub_[2] + (controlAerobi_P.Mmagnet_Value_c[i + 3] *
      controlAerobi_B.ub_[1] + controlAerobi_P.Mmagnet_Value_c[i] *
      controlAerobi_B.ub_[0]);

    // RateLimiter: '<S111>/Rate Limiter1'
    controlAerobi_B.Sum = controlAerobi_B.DiscreteTimeIntegrator_b -
      controlAerobi_DWork.PrevY_i[i];
    if (controlAerobi_B.Sum > controlAerobi_P.RateLimiter1_RisingLim_p) {
      controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_i[i]
        + controlAerobi_P.RateLimiter1_RisingLim_p;
    } else {
      if (controlAerobi_B.Sum < controlAerobi_P.RateLimiter1_FallingLim_l) {
        controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_i[i]
          + controlAerobi_P.RateLimiter1_FallingLim_l;
      }
    }

    controlAerobi_DWork.PrevY_i[i] = controlAerobi_B.DiscreteTimeIntegrator_b;

    // End of RateLimiter: '<S111>/Rate Limiter1'

    // Switch: '<S137>/Switch' incorporates:
    //   Constant: '<S137>/Constant'
    //   RelationalOperator: '<S137>/Relational Operator'

    if (rtIsNaN(controlAerobi_B.DiscreteTimeIntegrator_b)) {
      controlAerobi_B.DiscreteTimeIntegrator_b =
        controlAerobi_P.Constant_Value_l[i];
    }

    // End of Switch: '<S137>/Switch'

    // Product: '<S111>/Product' incorporates:
    //   Constant: '<S111>/M magnet'

    controlAerobi_B.Gain_po[i] = controlAerobi_B.DiscreteTimeIntegrator_b;
  }

  // MATLAB Function: '<S140>/Embedded MATLAB Function1'
  // MATLAB Function 'Sensors/attitude/AttitudeEstimator/lsm9ds1/Mahoney_estimator/Embedded MATLAB Function1': '<S141>:1' 
  // '<S141>:1:102'
  // '<S141>:1:50'
  if ((!controlAerobi_DWork.b__not_empty_b) ||
      (!controlAerobi_DWork.q__not_empty_h) ||
      (!controlAerobi_DWork.mi_not_empty_n) ||
      (!controlAerobi_DWork.e3_not_empty_a) ||
      (!controlAerobi_DWork.mb_not_empty)) {
    // '<S141>:1:8'
    // '<S141>:1:10'
    controlAerobi_DWork.b__not_empty_b = true;

    // '<S141>:1:11'
    controlAerobi_DWork.mi_not_empty_n = true;

    // '<S141>:1:12'
    controlAerobi_DWork.b__h[0] = 0.0;
    controlAerobi_DWork.mi_g[0] = 0.5879;
    controlAerobi_DWork.e3_k[0] = 0.0;
    controlAerobi_DWork.b__h[1] = 0.0;
    controlAerobi_DWork.mi_g[1] = 0.0081;
    controlAerobi_DWork.e3_k[1] = 0.0;
    controlAerobi_DWork.b__h[2] = 0.0;
    controlAerobi_DWork.mi_g[2] = 0.8091;
    controlAerobi_DWork.e3_k[2] = 1.0;
    controlAerobi_DWork.e3_not_empty_a = true;

    // '<S141>:1:13'
    controlAerobi_B.Sum = norm_OKjrfDiG(controlAerobi_B.Gain_po);
    controlAerobi_B.vbx[0] = controlAerobi_B.Gain_po[0] / controlAerobi_B.Sum;
    controlAerobi_B.vbx[1] = controlAerobi_B.Gain_po[1] / controlAerobi_B.Sum;
    controlAerobi_DWork.mb_not_empty = true;

    // '<S141>:1:14'
    controlAerobi_DWork.q__c[0] = cos(rt_atan2d_snf(-controlAerobi_B.vbx[1],
      controlAerobi_B.vbx[0]) / 2.0);
    controlAerobi_DWork.q__c[1] = 0.0;
    controlAerobi_DWork.q__c[2] = 0.0;
    controlAerobi_DWork.q__c[3] = sin(rt_atan2d_snf(-controlAerobi_B.vbx[1],
      controlAerobi_B.vbx[0]) / 2.0);
    controlAerobi_DWork.q__not_empty_h = true;
  }

  // '<S141>:1:18'
  controlAerobi_B.b_exp_b = norm_OKjrfDiG(controlAerobi_B.Switch);
  controlAerobi_B.ub[0] = controlAerobi_B.Switch[0] / controlAerobi_B.b_exp_b;
  controlAerobi_B.ub[1] = controlAerobi_B.Switch[1] / controlAerobi_B.b_exp_b;
  controlAerobi_B.ub[2] = controlAerobi_B.Switch[2] / controlAerobi_B.b_exp_b;

  // '<S141>:1:19'
  controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
    (controlAerobi_B.Gain_po);
  controlAerobi_B.vbx[0] = controlAerobi_B.Gain_po[0] /
    controlAerobi_B.DiscreteTimeIntegrator_b;
  controlAerobi_B.vbx[1] = controlAerobi_B.Gain_po[1] /
    controlAerobi_B.DiscreteTimeIntegrator_b;
  controlAerobi_B.vbx[2] = controlAerobi_B.Gain_po[2] /
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // '<S141>:1:24'
  controlAerobi_B.Sum = 1.0 / sqrt(((controlAerobi_DWork.q__c[0] *
    controlAerobi_DWork.q__c[0] + controlAerobi_DWork.q__c[1] *
    controlAerobi_DWork.q__c[1]) + controlAerobi_DWork.q__c[2] *
    controlAerobi_DWork.q__c[2]) + controlAerobi_DWork.q__c[3] *
    controlAerobi_DWork.q__c[3]);
  controlAerobi_B.q_k_d[0] = controlAerobi_DWork.q__c[0] * controlAerobi_B.Sum;
  controlAerobi_B.q_k_d[1] = controlAerobi_DWork.q__c[1] * controlAerobi_B.Sum;
  controlAerobi_B.q_k_d[2] = controlAerobi_DWork.q__c[2] * controlAerobi_B.Sum;
  controlAerobi_B.q_k_d[3] = controlAerobi_DWork.q__c[3] * controlAerobi_B.Sum;

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 4;

  // MATLAB Function: '<S140>/Embedded MATLAB Function1' incorporates:
  //   Constant: '<S116>/k1'
  //   Constant: '<S116>/k2'
  //   Constant: '<S116>/k3'
  //   Constant: '<S116>/k4'
  //   Constant: '<S116>/kb'
  //   Constant: '<S116>/limit'
  //   Constant: '<S140>/Constant'

  controlAerobi_B.Sum = (controlAerobi_B.q_k_d[1] * controlAerobi_B.q_k_d[3] -
    controlAerobi_B.q_k_d[0] * controlAerobi_B.q_k_d[2]) * -2.0;
  if (controlAerobi_B.Sum > 1.0) {
    controlAerobi_B.Sum = 1.0;
  }

  if (controlAerobi_B.Sum < -1.0) {
    controlAerobi_B.Sum = -1.0;
  }

  controlAerobi_B.eulerZYX[0] = rt_atan2d_snf((controlAerobi_B.q_k_d[1] *
    controlAerobi_B.q_k_d[2] + controlAerobi_B.q_k_d[0] * controlAerobi_B.q_k_d
    [3]) * 2.0, ((controlAerobi_B.q_k_d[0] * controlAerobi_B.q_k_d[0] +
                  controlAerobi_B.q_k_d[1] * controlAerobi_B.q_k_d[1]) -
                 controlAerobi_B.q_k_d[2] * controlAerobi_B.q_k_d[2]) -
    controlAerobi_B.q_k_d[3] * controlAerobi_B.q_k_d[3]);
  controlAerobi_B.eulerZYX[1] = asin(controlAerobi_B.Sum);
  controlAerobi_B.eulerZYX[2] = rt_atan2d_snf((controlAerobi_B.q_k_d[2] *
    controlAerobi_B.q_k_d[3] + controlAerobi_B.q_k_d[0] * controlAerobi_B.q_k_d
    [1]) * 2.0, ((controlAerobi_B.q_k_d[0] * controlAerobi_B.q_k_d[0] -
                  controlAerobi_B.q_k_d[1] * controlAerobi_B.q_k_d[1]) -
                 controlAerobi_B.q_k_d[2] * controlAerobi_B.q_k_d[2]) +
    controlAerobi_B.q_k_d[3] * controlAerobi_B.q_k_d[3]);

  // '<S141>:1:25'
  // '<S141>:1:26'
  // '<S141>:1:27'
  // '<S141>:1:40'
  controlAerobi_B.y_k_idx_1 = cos(controlAerobi_B.eulerZYX[0]);
  controlAerobi_B.y_k_idx_0 = cos(controlAerobi_B.eulerZYX[1]);
  controlAerobi_B.R_[0] = controlAerobi_B.y_k_idx_0 * controlAerobi_B.y_k_idx_1;
  controlAerobi_B.Product1_ew = cos(controlAerobi_B.eulerZYX[2]);
  controlAerobi_B.Abs_a = sin(controlAerobi_B.eulerZYX[1]);
  controlAerobi_B.DiscreteTimeIntegrator_b = sin(controlAerobi_B.eulerZYX[2]);
  controlAerobi_B.Sum = sin(controlAerobi_B.eulerZYX[0]);
  controlAerobi_B.b_exp_b = controlAerobi_B.DiscreteTimeIntegrator_b *
    controlAerobi_B.Abs_a;
  controlAerobi_B.R_[3] = controlAerobi_B.b_exp_b * controlAerobi_B.y_k_idx_1 +
    -controlAerobi_B.Product1_ew * controlAerobi_B.Sum;
  controlAerobi_B.sinc = controlAerobi_B.Product1_ew * controlAerobi_B.Abs_a;
  controlAerobi_B.R_[6] = controlAerobi_B.sinc * controlAerobi_B.y_k_idx_1 +
    controlAerobi_B.DiscreteTimeIntegrator_b * controlAerobi_B.Sum;
  controlAerobi_B.R_[1] = controlAerobi_B.y_k_idx_0 * controlAerobi_B.Sum;
  controlAerobi_B.R_[4] = controlAerobi_B.b_exp_b * controlAerobi_B.Sum +
    controlAerobi_B.Product1_ew * controlAerobi_B.y_k_idx_1;
  controlAerobi_B.R_[7] = controlAerobi_B.sinc * controlAerobi_B.Sum +
    -controlAerobi_B.DiscreteTimeIntegrator_b * controlAerobi_B.y_k_idx_1;
  controlAerobi_B.R_[2] = -controlAerobi_B.Abs_a;
  controlAerobi_B.R_[5] = controlAerobi_B.DiscreteTimeIntegrator_b *
    controlAerobi_B.y_k_idx_0;
  controlAerobi_B.R_[8] = controlAerobi_B.Product1_ew *
    controlAerobi_B.y_k_idx_0;

  // '<S141>:1:50'
  controlAerobi_B.absxk = norm_OKjrfDiG(controlAerobi_B.ub);
  controlAerobi_B.Sum = controlAerobi_B.absxk * controlAerobi_B.absxk;

  // '<S141>:1:51'
  controlAerobi_B.b_exp_b = norm_OKjrfDiG(controlAerobi_DWork.e3_k);
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_B.b_exp_b *
    controlAerobi_B.b_exp_b;

  // '<S141>:1:53'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.b_exp_b = controlAerobi_B.DiscreteTimeIntegrator_b * (real_T)
      c_b_0[i] - controlAerobi_DWork.e3_k[i] * controlAerobi_DWork.e3_k[0];
    controlAerobi_B.P_ui[i] = controlAerobi_B.b_exp_b;
    controlAerobi_B.sinc = controlAerobi_B.b_exp_b * controlAerobi_DWork.mi_g[0];
    controlAerobi_B.b_exp_b = (real_T)c_b_0[i + 3] *
      controlAerobi_B.DiscreteTimeIntegrator_b - controlAerobi_DWork.e3_k[i] *
      controlAerobi_DWork.e3_k[1];
    controlAerobi_B.P_ui[i + 3] = controlAerobi_B.b_exp_b;
    controlAerobi_B.sinc += controlAerobi_B.b_exp_b * controlAerobi_DWork.mi_g[1];
    controlAerobi_B.b_exp_b = (real_T)c_b_0[i + 6] *
      controlAerobi_B.DiscreteTimeIntegrator_b - controlAerobi_DWork.e3_k[i] *
      controlAerobi_DWork.e3_k[2];
    controlAerobi_B.P_ui[i + 6] = controlAerobi_B.b_exp_b;
    controlAerobi_B.sinc += controlAerobi_B.b_exp_b * controlAerobi_DWork.mi_g[2];
    controlAerobi_B.P_ui_o[i] = controlAerobi_B.sinc;
    controlAerobi_B.ub_[i] = controlAerobi_B.R_[3 * i + 2] *
      controlAerobi_DWork.e3_k[2] + (controlAerobi_B.R_[3 * i + 1] *
      controlAerobi_DWork.e3_k[1] + controlAerobi_B.R_[3 * i] *
      controlAerobi_DWork.e3_k[0]);
  }

  controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
    (controlAerobi_B.P_ui_o);

  // '<S141>:1:54'
  // '<S141>:1:55'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.P_ui_o[i] = ((controlAerobi_B.P_ui[i + 3] *
      controlAerobi_DWork.mi_g[1] + controlAerobi_B.P_ui[i] *
      controlAerobi_DWork.mi_g[0]) + controlAerobi_B.P_ui[i + 6] *
      controlAerobi_DWork.mi_g[2]) / controlAerobi_B.DiscreteTimeIntegrator_b;
  }

  for (i = 0; i < 3; i++) {
    controlAerobi_B.eulerZYX[i] = controlAerobi_B.R_[3 * i + 2] *
      controlAerobi_B.P_ui_o[2] + (controlAerobi_B.R_[3 * i + 1] *
      controlAerobi_B.P_ui_o[1] + controlAerobi_B.R_[3 * i] *
      controlAerobi_B.P_ui_o[0]);
  }

  // '<S141>:1:56'
  // '<S141>:1:57'
  controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
    (controlAerobi_B.Gain_po);
  controlAerobi_B.rtb_Gain_po_l[0] = controlAerobi_B.Gain_po[0] /
    controlAerobi_B.DiscreteTimeIntegrator_b - controlAerobi_B.eulerZYX[0];
  controlAerobi_B.rtb_Gain_po_l[1] = controlAerobi_B.Gain_po[1] /
    controlAerobi_B.DiscreteTimeIntegrator_b - controlAerobi_B.eulerZYX[1];
  controlAerobi_B.rtb_Gain_po_l[2] = controlAerobi_B.Gain_po[2] /
    controlAerobi_B.DiscreteTimeIntegrator_b - controlAerobi_B.eulerZYX[2];
  if (norm_OKjrfDiG(controlAerobi_B.rtb_Gain_po_l) <
      controlAerobi_P.Constant_Value_g) {
    // '<S141>:1:58'
    // '<S141>:1:59'
    controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
      (controlAerobi_B.Gain_po);
    controlAerobi_B.vbx[0] = controlAerobi_B.Gain_po[0] /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.vbx[1] = controlAerobi_B.Gain_po[1] /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.vbx[2] = controlAerobi_B.Gain_po[2] /
      controlAerobi_B.DiscreteTimeIntegrator_b;
  }

  // '<S141>:1:65'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.P_ui_o[i] = controlAerobi_B.P_ui[i + 6] *
      controlAerobi_DWork.mi_g[2] + (controlAerobi_B.P_ui[i + 3] *
      controlAerobi_DWork.mi_g[1] + controlAerobi_B.P_ui[i] *
      controlAerobi_DWork.mi_g[0]);
  }

  controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
    (controlAerobi_B.P_ui_o);
  for (i = 0; i < 3; i++) {
    controlAerobi_B.Gain_po[i] = ((((real_T)c_b_0[i + 3] * controlAerobi_B.Sum -
      controlAerobi_B.ub[i] * controlAerobi_B.ub[1]) * controlAerobi_B.vbx[1] +
      (controlAerobi_B.Sum * (real_T)c_b_0[i] - controlAerobi_B.ub[i] *
       controlAerobi_B.ub[0]) * controlAerobi_B.vbx[0]) + ((real_T)c_b_0[i + 6] *
      controlAerobi_B.Sum - controlAerobi_B.ub[i] * controlAerobi_B.ub[2]) *
      controlAerobi_B.vbx[2]) / controlAerobi_B.DiscreteTimeIntegrator_b;
  }

  // '<S141>:1:67'
  controlAerobi_B.ubx_d[0] = controlAerobi_B.ub[1] * controlAerobi_B.ub_[2] -
    controlAerobi_B.ub[2] * controlAerobi_B.ub_[1];
  controlAerobi_B.ubx_d[1] = controlAerobi_B.ub[2] * controlAerobi_B.ub_[0] -
    controlAerobi_B.ub[0] * controlAerobi_B.ub_[2];
  controlAerobi_B.ubx_d[2] = controlAerobi_B.ub[0] * controlAerobi_B.ub_[1] -
    controlAerobi_B.ub[1] * controlAerobi_B.ub_[0];

  // '<S141>:1:68'
  controlAerobi_B.vbx[0] = controlAerobi_B.Gain_po[1] *
    controlAerobi_B.eulerZYX[2] - controlAerobi_B.Gain_po[2] *
    controlAerobi_B.eulerZYX[1];
  controlAerobi_B.vbx[1] = controlAerobi_B.Gain_po[2] *
    controlAerobi_B.eulerZYX[0] - controlAerobi_B.Gain_po[0] *
    controlAerobi_B.eulerZYX[2];
  controlAerobi_B.vbx[2] = controlAerobi_B.Gain_po[0] *
    controlAerobi_B.eulerZYX[1] - controlAerobi_B.Gain_po[1] *
    controlAerobi_B.eulerZYX[0];

  // '<S141>:1:70'
  // '<S141>:1:72'
  // '<S141>:1:74'
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_P.limit_Value_b /
    norm_OKjrfDiG(controlAerobi_DWork.b__h);
  if ((1.0 < controlAerobi_B.DiscreteTimeIntegrator_b) || rtIsNaN
      (controlAerobi_B.DiscreteTimeIntegrator_b)) {
    controlAerobi_B.DiscreteTimeIntegrator_b = 1.0;
  }

  // '<S141>:1:76'
  // '<S141>:1:81'
  for (i = 0; i < 3; i++) {
    controlAerobi_DWork.b__h[i] += ((controlAerobi_DWork.b__h[i] *
      controlAerobi_B.DiscreteTimeIntegrator_b * controlAerobi_P.kb_Value_o +
      -controlAerobi_P.kb_Value_o * controlAerobi_DWork.b__h[i]) +
      (-controlAerobi_P.k3_Value_j * controlAerobi_B.ubx_d[i] -
       controlAerobi_P.k4_Value_j * controlAerobi_B.vbx[i])) * 0.0025;
    controlAerobi_B.R_d_m[i] = controlAerobi_B.ub_[i] * controlAerobi_B.ub_[0];
    controlAerobi_B.R_d_m[i + 3] = controlAerobi_B.ub_[i] * controlAerobi_B.ub_
      [1];
    controlAerobi_B.R_d_m[i + 6] = controlAerobi_B.ub_[i] * controlAerobi_B.ub_
      [2];
  }

  for (i = 0; i < 3; i++) {
    controlAerobi_B.Re_R[3 * i] = controlAerobi_B.R_d_m[3 * i] *
      controlAerobi_P.k2_Value_a;
    controlAerobi_B.Re_R[1 + 3 * i] = controlAerobi_B.R_d_m[3 * i + 1] *
      controlAerobi_P.k2_Value_a;
    controlAerobi_B.Re_R[2 + 3 * i] = controlAerobi_B.R_d_m[3 * i + 2] *
      controlAerobi_P.k2_Value_a;
  }

  for (i = 0; i < 3; i++) {
    controlAerobi_B.eulerZYX[i] = (((controlAerobi_B.Re_R[i + 3] *
      controlAerobi_B.vbx[1] + controlAerobi_B.Re_R[i] * controlAerobi_B.vbx[0])
      + controlAerobi_B.Re_R[i + 6] * controlAerobi_B.vbx[2]) +
      controlAerobi_P.k1_Value_l * controlAerobi_B.ubx_d[i]) +
      (controlAerobi_B.Add[i] - controlAerobi_DWork.b__h[i]);
  }

  // '<S141>:1:84'
  // '<S141>:1:89'
  // '<S141>:1:92'
  controlAerobi_B.b_exp_b = 0.00125 * norm_OKjrfDiG(controlAerobi_B.eulerZYX);
  if (controlAerobi_B.b_exp_b == 0.0) {
    // '<S141>:1:95'
    // '<S141>:1:96'
    controlAerobi_B.sinc = 1.0;
  } else {
    // '<S141>:1:98'
    controlAerobi_B.sinc = sin(controlAerobi_B.b_exp_b) /
      controlAerobi_B.b_exp_b;
  }

  // '<S141>:1:102'
  controlAerobi_B.Sum = cos(controlAerobi_B.b_exp_b);
  controlAerobi_B.b_exp_b = 0.00125 * controlAerobi_B.sinc;
  controlAerobi_B.R_f[0] = controlAerobi_B.b_exp_b * 0.0;
  controlAerobi_B.sinc = controlAerobi_B.b_exp_b * -controlAerobi_B.eulerZYX[0];
  controlAerobi_B.R_f[4] = controlAerobi_B.sinc;
  controlAerobi_B.R_f[1] = controlAerobi_B.b_exp_b * controlAerobi_B.eulerZYX[0];
  controlAerobi_B.rtb_Switch_Pos_idx_1 = controlAerobi_B.b_exp_b *
    -controlAerobi_B.eulerZYX[1];
  controlAerobi_B.R_f[8] = controlAerobi_B.rtb_Switch_Pos_idx_1;
  controlAerobi_B.R_f[2] = controlAerobi_B.b_exp_b * controlAerobi_B.eulerZYX[1];
  controlAerobi_B.absxk = controlAerobi_B.b_exp_b * -controlAerobi_B.eulerZYX[2];
  controlAerobi_B.R_f[12] = controlAerobi_B.absxk;
  controlAerobi_B.R_f[3] = controlAerobi_B.b_exp_b * controlAerobi_B.eulerZYX[2];
  controlAerobi_B.R_f[5] = controlAerobi_B.b_exp_b * -0.0;
  controlAerobi_B.R_f[9] = controlAerobi_B.b_exp_b *
    -(-controlAerobi_B.eulerZYX[2]);
  controlAerobi_B.R_f[13] = controlAerobi_B.rtb_Switch_Pos_idx_1;
  controlAerobi_B.R_f[6] = controlAerobi_B.absxk;
  controlAerobi_B.R_f[10] = controlAerobi_B.b_exp_b * -0.0;
  controlAerobi_B.R_f[14] = controlAerobi_B.b_exp_b *
    -(-controlAerobi_B.eulerZYX[0]);
  controlAerobi_B.R_f[7] = controlAerobi_B.b_exp_b *
    -(-controlAerobi_B.eulerZYX[1]);
  controlAerobi_B.R_f[11] = controlAerobi_B.sinc;
  controlAerobi_B.R_f[15] = controlAerobi_B.b_exp_b * -0.0;
  for (i = 0; i < 4; i++) {
    controlAerobi_B.rtb_Sum_g2[i << 2] = (real_T)d_b[i << 2] *
      controlAerobi_B.Sum + controlAerobi_B.R_f[i << 2];
    controlAerobi_B.rtb_Sum_g2[1 + (i << 2)] = (real_T)d_b[(i << 2) + 1] *
      controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 1];
    controlAerobi_B.rtb_Sum_g2[2 + (i << 2)] = (real_T)d_b[(i << 2) + 2] *
      controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 2];
    controlAerobi_B.rtb_Sum_g2[3 + (i << 2)] = (real_T)d_b[(i << 2) + 3] *
      controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 3];
  }

  for (i = 0; i < 4; i++) {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_B.rtb_Sum_g2[i + 12]
      * controlAerobi_DWork.q__c[3] + (controlAerobi_B.rtb_Sum_g2[i + 8] *
      controlAerobi_DWork.q__c[2] + (controlAerobi_B.rtb_Sum_g2[i + 4] *
      controlAerobi_DWork.q__c[1] + controlAerobi_B.rtb_Sum_g2[i] *
      controlAerobi_DWork.q__c[0]));
    rtb_LowerRelop1_k[i] = rtIsNaN(controlAerobi_B.DiscreteTimeIntegrator_b);
    controlAerobi_B.q_k_d[i] = controlAerobi_B.DiscreteTimeIntegrator_b;
  }

  rtb_LogicalOperator = true;
  o = 0;
  exitg1 = false;
  while ((!exitg1) && (o + 1 < 5)) {
    if (!rtb_LowerRelop1_k[o]) {
      rtb_LogicalOperator = false;
      exitg1 = true;
    } else {
      o++;
    }
  }

  if (rtb_LogicalOperator) {
    // '<S141>:1:104'
    controlAerobi_B.q_k_d[0] = 1.0;
    controlAerobi_B.q_k_d[1] = 0.0;
    controlAerobi_B.q_k_d[2] = 0.0;
    controlAerobi_B.q_k_d[3] = 0.0;
  }

  // '<S141>:1:106'
  controlAerobi_DWork.q__c[0] = controlAerobi_B.q_k_d[0];
  controlAerobi_DWork.q__c[1] = controlAerobi_B.q_k_d[1];
  controlAerobi_DWork.q__c[2] = controlAerobi_B.q_k_d[2];
  controlAerobi_DWork.q__c[3] = controlAerobi_B.q_k_d[3];

  // Sqrt: '<S145>/sqrt' incorporates:
  //   Product: '<S146>/Product'
  //   Product: '<S146>/Product1'
  //   Product: '<S146>/Product2'
  //   Product: '<S146>/Product3'
  //   Sum: '<S146>/Sum'

  // '<S141>:1:107'
  controlAerobi_B.DiscreteTimeIntegrator_b = sqrt(((controlAerobi_B.q_k_d[0] *
    controlAerobi_B.q_k_d[0] + controlAerobi_B.q_k_d[1] * controlAerobi_B.q_k_d
    [1]) + controlAerobi_B.q_k_d[2] * controlAerobi_B.q_k_d[2]) +
    controlAerobi_B.q_k_d[3] * controlAerobi_B.q_k_d[3]);

  // Product: '<S144>/Product'
  controlAerobi_B.Product1_ew = controlAerobi_B.q_k_d[0] /
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Product: '<S144>/Product1'
  controlAerobi_B.Product1_a1 = controlAerobi_B.q_k_d[1] /
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Product: '<S144>/Product2'
  controlAerobi_B.Abs_a = controlAerobi_B.q_k_d[2] /
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Product: '<S144>/Product3'
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_B.q_k_d[3] /
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Trigonometry: '<S143>/Trigonometric Function1' incorporates:
  //   Fcn: '<S142>/fcn1'
  //   Fcn: '<S142>/fcn2'

  controlAerobi_B.Add_j[0] = rt_atan2d_snf((controlAerobi_B.Product1_a1 *
    controlAerobi_B.Abs_a - controlAerobi_B.Product1_ew *
    controlAerobi_B.DiscreteTimeIntegrator_b) * -2.0,
    ((controlAerobi_B.Product1_ew * controlAerobi_B.Product1_ew -
      controlAerobi_B.Product1_a1 * controlAerobi_B.Product1_a1) +
     controlAerobi_B.Abs_a * controlAerobi_B.Abs_a) -
    controlAerobi_B.DiscreteTimeIntegrator_b *
    controlAerobi_B.DiscreteTimeIntegrator_b);

  // Fcn: '<S142>/fcn3'
  controlAerobi_B.absxk = (controlAerobi_B.Abs_a *
    controlAerobi_B.DiscreteTimeIntegrator_b + controlAerobi_B.Product1_ew *
    controlAerobi_B.Product1_a1) * 2.0;

  // Fcn: '<S142>/fcn4'
  controlAerobi_B.Zgain_a = (controlAerobi_B.Product1_a1 *
    controlAerobi_B.DiscreteTimeIntegrator_b - controlAerobi_B.Product1_ew *
    controlAerobi_B.Abs_a) * -2.0;

  // Fcn: '<S142>/fcn5'
  controlAerobi_B.Product1_ew = ((controlAerobi_B.Product1_ew *
    controlAerobi_B.Product1_ew - controlAerobi_B.Product1_a1 *
    controlAerobi_B.Product1_a1) - controlAerobi_B.Abs_a * controlAerobi_B.Abs_a)
    + controlAerobi_B.DiscreteTimeIntegrator_b *
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Sum: '<S116>/Sum1' incorporates:
  //   Constant: '<S116>/offset'
  //   Gain: '<S116>/Gain'
  //   Trigonometry: '<S143>/Trigonometric Function3'

  controlAerobi_B.ub[0] = controlAerobi_P.Gain_Gain_i *
    controlAerobi_P.offset_Value_h[0] + rt_atan2d_snf(controlAerobi_B.Zgain_a,
    controlAerobi_B.Product1_ew);

  // Trigonometry: '<S143>/trigFcn'
  if (controlAerobi_B.absxk > 1.0) {
    controlAerobi_B.absxk = 1.0;
  } else {
    if (controlAerobi_B.absxk < -1.0) {
      controlAerobi_B.absxk = -1.0;
    }
  }

  // Sum: '<S116>/Sum1' incorporates:
  //   Constant: '<S116>/offset'
  //   Gain: '<S116>/Gain'
  //   Trigonometry: '<S143>/trigFcn'

  controlAerobi_B.ub[1] = controlAerobi_P.Gain_Gain_i *
    controlAerobi_P.offset_Value_h[1] + asin(controlAerobi_B.absxk);
  controlAerobi_B.ub[2] = controlAerobi_P.Gain_Gain_i *
    controlAerobi_P.offset_Value_h[2] + controlAerobi_B.Add_j[0];

  // RateLimiter: '<S113>/Rate Limiter' incorporates:
  //   DataTypeConversion: '<S101>/Data Type Conversion1'
  //   Inport: '<Root>/I_imu_lsm'

  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_U.I_imu_lsm._ax -
    controlAerobi_DWork.PrevY_m[0];
  if (controlAerobi_B.DiscreteTimeIntegrator_b >
      controlAerobi_P.RateLimiter_RisingLim) {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_m[0] +
      controlAerobi_P.RateLimiter_RisingLim;
  } else if (controlAerobi_B.DiscreteTimeIntegrator_b <
             controlAerobi_P.RateLimiter_FallingLim) {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_m[0] +
      controlAerobi_P.RateLimiter_FallingLim;
  } else {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_U.I_imu_lsm._ax;
  }

  controlAerobi_DWork.PrevY_m[0] = controlAerobi_B.DiscreteTimeIntegrator_b;

  // Sum: '<S113>/Add' incorporates:
  //   Constant: '<S113>/Bias_accel'

  controlAerobi_B.DiscreteTimeIntegrator_b -= controlAerobi_P.Bias_accel_Value[0];

  // RateLimiter: '<S113>/Rate Limiter' incorporates:
  //   DataTypeConversion: '<S101>/Data Type Conversion1'
  //   Inport: '<Root>/I_imu_lsm'

  controlAerobi_B.Add_j[0] = controlAerobi_B.DiscreteTimeIntegrator_b;
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_U.I_imu_lsm._ay -
    controlAerobi_DWork.PrevY_m[1];
  if (controlAerobi_B.DiscreteTimeIntegrator_b >
      controlAerobi_P.RateLimiter_RisingLim) {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_m[1] +
      controlAerobi_P.RateLimiter_RisingLim;
  } else if (controlAerobi_B.DiscreteTimeIntegrator_b <
             controlAerobi_P.RateLimiter_FallingLim) {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_m[1] +
      controlAerobi_P.RateLimiter_FallingLim;
  } else {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_U.I_imu_lsm._ay;
  }

  controlAerobi_DWork.PrevY_m[1] = controlAerobi_B.DiscreteTimeIntegrator_b;

  // Sum: '<S113>/Add' incorporates:
  //   Constant: '<S113>/Bias_accel'

  controlAerobi_B.DiscreteTimeIntegrator_b -= controlAerobi_P.Bias_accel_Value[1];

  // RateLimiter: '<S113>/Rate Limiter' incorporates:
  //   DataTypeConversion: '<S101>/Data Type Conversion1'
  //   Inport: '<Root>/I_imu_lsm'

  controlAerobi_B.Add_j[1] = controlAerobi_B.DiscreteTimeIntegrator_b;
  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_U.I_imu_lsm._az -
    controlAerobi_DWork.PrevY_m[2];
  if (controlAerobi_B.DiscreteTimeIntegrator_b >
      controlAerobi_P.RateLimiter_RisingLim) {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_m[2] +
      controlAerobi_P.RateLimiter_RisingLim;
  } else if (controlAerobi_B.DiscreteTimeIntegrator_b <
             controlAerobi_P.RateLimiter_FallingLim) {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_m[2] +
      controlAerobi_P.RateLimiter_FallingLim;
  } else {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_U.I_imu_lsm._az;
  }

  controlAerobi_DWork.PrevY_m[2] = controlAerobi_B.DiscreteTimeIntegrator_b;

  // Sum: '<S113>/Add' incorporates:
  //   Constant: '<S113>/Bias_accel'

  controlAerobi_B.DiscreteTimeIntegrator_b -= controlAerobi_P.Bias_accel_Value[2];

  // Product: '<S113>/Product' incorporates:
  //   Constant: '<S113>/M_accel'

  for (i = 0; i < 3; i++) {
    controlAerobi_B.Gain_po[i] = controlAerobi_P.M_accel_Value[i + 6] *
      controlAerobi_B.DiscreteTimeIntegrator_b +
      (controlAerobi_P.M_accel_Value[i + 3] * controlAerobi_B.Add_j[1] +
       controlAerobi_P.M_accel_Value[i] * controlAerobi_B.Add_j[0]);
  }

  // End of Product: '<S113>/Product'

  // Sum: '<S114>/Add' incorporates:
  //   Constant: '<S114>/Bias_gyro'
  //   DataTypeConversion: '<S101>/Data Type Conversion1'
  //   Inport: '<Root>/I_imu_lsm'

  controlAerobi_B.Add_j[0] = controlAerobi_U.I_imu_lsm._gx -
    controlAerobi_P.Bias_gyro_Value[0];
  controlAerobi_B.Add_j[1] = controlAerobi_U.I_imu_lsm._gy -
    controlAerobi_P.Bias_gyro_Value[1];
  controlAerobi_B.Add_j[2] = controlAerobi_U.I_imu_lsm._gz -
    controlAerobi_P.Bias_gyro_Value[2];

  // MATLAB Function: '<S114>/MATLAB Function'
  controlAerobi_MATLABFunction(controlAerobi_B.Add_j,
    &controlAerobi_B.sf_MATLABFunction_c,
    &controlAerobi_DWork.sf_MATLABFunction_c);
  for (i = 0; i < 3; i++) {
    // RateLimiter: '<S115>/Rate Limiter1'
    controlAerobi_B.DiscreteTimeIntegrator_b =
      controlAerobi_B.DataTypeConversion1_n[i + 7] -
      controlAerobi_DWork.PrevY_f[i];
    if (controlAerobi_B.DiscreteTimeIntegrator_b >
        controlAerobi_P.RateLimiter1_RisingLim_n) {
      controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_f[i]
        + controlAerobi_P.RateLimiter1_RisingLim_n;
    } else if (controlAerobi_B.DiscreteTimeIntegrator_b <
               controlAerobi_P.RateLimiter1_FallingLim_i) {
      controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_DWork.PrevY_f[i]
        + controlAerobi_P.RateLimiter1_FallingLim_i;
    } else {
      controlAerobi_B.DiscreteTimeIntegrator_b =
        controlAerobi_B.DataTypeConversion1_n[7 + i];
    }

    controlAerobi_DWork.PrevY_f[i] = controlAerobi_B.DiscreteTimeIntegrator_b;

    // End of RateLimiter: '<S115>/Rate Limiter1'

    // Switch: '<S139>/Switch' incorporates:
    //   Constant: '<S139>/Constant'
    //   RelationalOperator: '<S139>/Relational Operator'

    if (rtIsNaN(controlAerobi_B.DiscreteTimeIntegrator_b)) {
      controlAerobi_B.DiscreteTimeIntegrator_b =
        controlAerobi_P.Constant_Value_f[i];
    }

    // End of Switch: '<S139>/Switch'

    // Sum: '<S115>/Add' incorporates:
    //   Constant: '<S115>/Bias_magnet'
    //   Gain: '<S115>/Gain'
    //   Product: '<S115>/Product'

    controlAerobi_B.rtb_Gain_po_l[i] = controlAerobi_P.Gain_Gain_j *
      controlAerobi_B.DiscreteTimeIntegrator_b -
      controlAerobi_P.Bias_magnet_Value[i];

    // Product: '<S114>/Product' incorporates:
    //   Constant: '<S114>/M_gyro'

    controlAerobi_B.vbx[i] = controlAerobi_P.M_gyro_Value[i + 6] *
      controlAerobi_B.sf_MATLABFunction_c.g_offset[2] +
      (controlAerobi_P.M_gyro_Value[i + 3] *
       controlAerobi_B.sf_MATLABFunction_c.g_offset[1] +
       controlAerobi_P.M_gyro_Value[i] *
       controlAerobi_B.sf_MATLABFunction_c.g_offset[0]);
  }

  // Product: '<S115>/Product' incorporates:
  //   Constant: '<S115>/M_magnet'

  for (i = 0; i < 3; i++) {
    controlAerobi_B.ubx_d[i] = controlAerobi_P.M_magnet_Value[i + 6] *
      controlAerobi_B.rtb_Gain_po_l[2] + (controlAerobi_P.M_magnet_Value[i + 3] *
      controlAerobi_B.rtb_Gain_po_l[1] + controlAerobi_P.M_magnet_Value[i] *
      controlAerobi_B.rtb_Gain_po_l[0]);
  }

  // MATLAB Function: '<S127>/FCF_fcn' incorporates:
  //   Constant: '<S127>/distorsion_max'
  //   Constant: '<S127>/weight'
  //   Constant: '<S127>/ya'
  //   Constant: '<S127>/ym'

  // MATLAB Function 'Sensors/attitude/AttitudeEstimator/TGIC/FCF/FCF_fcn': '<S130>:1' 
  // '<S130>:1:64'
  // '<S130>:1:39'
  // '<S130>:1:3'
  // '<S130>:1:7'
  if (fabs(norm_OKjrfDiG(controlAerobi_B.ubx_d) - 44.0) >
      controlAerobi_P.distorsion_max_Value_g) {
    // '<S130>:1:8'
    // '<S130>:1:9'
    distorsioned = 1;
  } else {
    // '<S130>:1:11'
    distorsioned = 0;
  }

  if ((!controlAerobi_DWork.q_est_aw_hat_not_empty) ||
      (!controlAerobi_DWork.q_est_amw_hat_not_empty) ||
      (!controlAerobi_DWork.time_not_empty_l)) {
    // '<S130>:1:14'
    // '<S130>:1:15'
    controlAerobi_DWork.q_est_aw_hat_not_empty = true;

    // '<S130>:1:16'
    controlAerobi_DWork.q_est_aw_hat[0] = 1.0;
    controlAerobi_B.q_k_d[0] = 1.0;
    controlAerobi_DWork.q_est_aw_hat[1] = 0.0;
    controlAerobi_B.q_k_d[1] = 0.0;
    controlAerobi_DWork.q_est_aw_hat[2] = 0.0;
    controlAerobi_B.q_k_d[2] = 0.0;
    controlAerobi_DWork.q_est_aw_hat[3] = 0.0;
    controlAerobi_B.q_k_d[3] = 0.0;
    controlAerobi_DWork.q_est_amw_hat_not_empty = true;

    // '<S130>:1:17'
    controlAerobi_DWork.time_l = 0.0;
    controlAerobi_DWork.time_not_empty_l = true;
  } else {
    // '<S130>:1:20'
    controlAerobi_DWork.time_l += 0.0025;

    // '<S130>:1:21'
    controlAerobi_B.Sum = norm_OKjrfDiG(controlAerobi_B.Gain_po);

    // '<S130>:1:22'
    controlAerobi_B.b_exp_b = norm_OKjrfDiG(controlAerobi_B.ubx_d);
    controlAerobi_B.ub_[0] = controlAerobi_B.Gain_po[0] / controlAerobi_B.Sum;
    controlAerobi_B.Add_j[0] = controlAerobi_B.ubx_d[0] /
      controlAerobi_B.b_exp_b;
    controlAerobi_B.ub_[1] = controlAerobi_B.Gain_po[1] / controlAerobi_B.Sum;
    controlAerobi_B.Add_j[1] = controlAerobi_B.ubx_d[1] /
      controlAerobi_B.b_exp_b;
    controlAerobi_B.ub_[2] = controlAerobi_B.Gain_po[2] / controlAerobi_B.Sum;
    controlAerobi_B.Add_j[2] = controlAerobi_B.ubx_d[2] /
      controlAerobi_B.b_exp_b;

    // '<S130>:1:27'
    // '<S130>:1:31'
    controlAerobi_B.b_exp_b = 0.00125 * norm_OKjrfDiG(controlAerobi_B.vbx);
    if (controlAerobi_B.b_exp_b == 0.0) {
      // '<S130>:1:33'
      // '<S130>:1:34'
      controlAerobi_B.sinc = 1.0;
    } else {
      // '<S130>:1:36'
      controlAerobi_B.sinc = sin(controlAerobi_B.b_exp_b) /
        controlAerobi_B.b_exp_b;
    }

    // '<S130>:1:39'
    // '<S130>:1:40'
    // '<S130>:1:45'
    controlAerobi_B.Sum = cos(controlAerobi_B.b_exp_b);
    controlAerobi_B.absxk = (1.0 - controlAerobi_P.ya_Value) * 0.00125 *
      controlAerobi_B.sinc;
    controlAerobi_B.b_exp_b = 0.5 * controlAerobi_P.ya_Value;
    controlAerobi_B.R_f[0] = controlAerobi_B.absxk * 0.0;
    controlAerobi_B.r_x_idx_0 = controlAerobi_B.absxk * -controlAerobi_B.vbx[0];
    controlAerobi_B.R_f[4] = controlAerobi_B.r_x_idx_0;
    controlAerobi_B.r_x_idx_1 = controlAerobi_B.absxk * -controlAerobi_B.vbx[1];
    controlAerobi_B.R_f[8] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.r_x_idx_2 = controlAerobi_B.absxk * -controlAerobi_B.vbx[2];
    controlAerobi_B.R_f[12] = controlAerobi_B.r_x_idx_2;
    controlAerobi_B.Zgain_a = controlAerobi_B.absxk * controlAerobi_B.vbx[0];
    controlAerobi_B.R_f[1] = controlAerobi_B.Zgain_a;
    controlAerobi_B.R_f[5] = controlAerobi_B.absxk * 0.0;
    controlAerobi_B.b_x_idx_1 = controlAerobi_B.absxk * controlAerobi_B.vbx[2];
    controlAerobi_B.R_f[9] = controlAerobi_B.b_x_idx_1;
    controlAerobi_B.R_f[13] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.r_x_idx_1 = controlAerobi_B.absxk * controlAerobi_B.vbx[1];
    controlAerobi_B.R_f[2] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.R_f[6] = controlAerobi_B.r_x_idx_2;
    controlAerobi_B.R_f[10] = controlAerobi_B.absxk * 0.0;
    controlAerobi_B.R_f[14] = controlAerobi_B.Zgain_a;
    controlAerobi_B.R_f[3] = controlAerobi_B.b_x_idx_1;
    controlAerobi_B.R_f[7] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.R_f[11] = controlAerobi_B.r_x_idx_0;
    controlAerobi_B.R_f[15] = controlAerobi_B.absxk * 0.0;
    controlAerobi_B.rtb_Sum_g2[0] = controlAerobi_B.ub_[2];
    controlAerobi_B.rtb_Sum_g2[4] = controlAerobi_B.ub_[1];
    controlAerobi_B.rtb_Sum_g2[8] = -controlAerobi_B.ub_[0];
    controlAerobi_B.rtb_Sum_g2[12] = 0.0;
    controlAerobi_B.rtb_Sum_g2[1] = controlAerobi_B.ub_[1];
    controlAerobi_B.rtb_Sum_g2[5] = -controlAerobi_B.ub_[2];
    controlAerobi_B.rtb_Sum_g2[9] = 0.0;
    controlAerobi_B.rtb_Sum_g2[13] = controlAerobi_B.ub_[0];
    controlAerobi_B.rtb_Sum_g2[2] = -controlAerobi_B.ub_[0];
    controlAerobi_B.rtb_Sum_g2[6] = 0.0;
    controlAerobi_B.rtb_Sum_g2[10] = -controlAerobi_B.ub_[2];
    controlAerobi_B.rtb_Sum_g2[14] = controlAerobi_B.ub_[1];
    controlAerobi_B.rtb_Sum_g2[3] = 0.0;
    controlAerobi_B.rtb_Sum_g2[7] = controlAerobi_B.ub_[0];
    controlAerobi_B.rtb_Sum_g2[11] = controlAerobi_B.ub_[1];
    controlAerobi_B.rtb_Sum_g2[15] = controlAerobi_B.ub_[2];
    for (i = 0; i < 4; i++) {
      controlAerobi_B.e_a[i << 2] = ((real_T)e_a[i << 2] * controlAerobi_B.Sum +
        controlAerobi_B.R_f[i << 2]) + (controlAerobi_B.rtb_Sum_g2[i << 2] -
        (real_T)e_a[i << 2]) * controlAerobi_B.b_exp_b;
      controlAerobi_B.e_a[1 + (i << 2)] = ((real_T)e_a[(i << 2) + 1] *
        controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 1]) +
        (controlAerobi_B.rtb_Sum_g2[(i << 2) + 1] - (real_T)e_a[(i << 2) + 1]) *
        controlAerobi_B.b_exp_b;
      controlAerobi_B.e_a[2 + (i << 2)] = ((real_T)e_a[(i << 2) + 2] *
        controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 2]) +
        (controlAerobi_B.rtb_Sum_g2[(i << 2) + 2] - (real_T)e_a[(i << 2) + 2]) *
        controlAerobi_B.b_exp_b;
      controlAerobi_B.e_a[3 + (i << 2)] = ((real_T)e_a[(i << 2) + 3] *
        controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 3]) +
        (controlAerobi_B.rtb_Sum_g2[(i << 2) + 3] - (real_T)e_a[(i << 2) + 3]) *
        controlAerobi_B.b_exp_b;
    }

    for (i = 0; i < 4; i++) {
      controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_B.e_a[i + 12] *
        controlAerobi_DWork.q_est_aw_hat[3] + (controlAerobi_B.e_a[i + 8] *
        controlAerobi_DWork.q_est_aw_hat[2] + (controlAerobi_B.e_a[i + 4] *
        controlAerobi_DWork.q_est_aw_hat[1] + controlAerobi_B.e_a[i] *
        controlAerobi_DWork.q_est_aw_hat[0]));
      controlAerobi_B.q_k_d[i] = controlAerobi_B.DiscreteTimeIntegrator_b;
    }

    // '<S130>:1:47'
    controlAerobi_B.DiscreteTimeIntegrator_b = norm_5ETDUxto
      (controlAerobi_B.q_k_d);
    controlAerobi_DWork.q_est_aw_hat[0] = controlAerobi_B.q_k_d[0] /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_DWork.q_est_aw_hat[1] = controlAerobi_B.q_k_d[1] /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_DWork.q_est_aw_hat[2] = controlAerobi_B.q_k_d[2] /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_DWork.q_est_aw_hat[3] = controlAerobi_B.q_k_d[3] /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    if (controlAerobi_DWork.time_l > 6.0) {
      // '<S130>:1:51'
      // '<S130>:1:52'
      // '<S130>:1:56'
      // '<S130>:1:60'
      // '<S130>:1:64'
      controlAerobi_B.Re_R[0] = ((controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[0] + controlAerobi_DWork.q_est_aw_hat[1]
        * controlAerobi_DWork.q_est_aw_hat[1]) -
        controlAerobi_DWork.q_est_aw_hat[2] * controlAerobi_DWork.q_est_aw_hat[2])
        - controlAerobi_DWork.q_est_aw_hat[3] *
        controlAerobi_DWork.q_est_aw_hat[3];
      controlAerobi_B.Gain7 = 2.0 * controlAerobi_DWork.q_est_aw_hat[1] *
        controlAerobi_DWork.q_est_aw_hat[2];
      controlAerobi_B.Abs_a = 2.0 * controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[3];
      controlAerobi_B.Re_R[3] = controlAerobi_B.Gain7 - controlAerobi_B.Abs_a;
      controlAerobi_B.DiscreteTimeIntegrator_b = 2.0 *
        controlAerobi_DWork.q_est_aw_hat[1] * controlAerobi_DWork.q_est_aw_hat[3];
      controlAerobi_B.Re_R[6] = 2.0 * controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[2] +
        controlAerobi_B.DiscreteTimeIntegrator_b;
      controlAerobi_B.Re_R[1] = controlAerobi_B.Gain7 + controlAerobi_B.Abs_a;
      controlAerobi_B.Re_R[4] = ((controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[0] - controlAerobi_DWork.q_est_aw_hat[1]
        * controlAerobi_DWork.q_est_aw_hat[1]) +
        controlAerobi_DWork.q_est_aw_hat[2] * controlAerobi_DWork.q_est_aw_hat[2])
        - controlAerobi_DWork.q_est_aw_hat[3] *
        controlAerobi_DWork.q_est_aw_hat[3];
      controlAerobi_B.Gain7 = 2.0 * controlAerobi_DWork.q_est_aw_hat[2] *
        controlAerobi_DWork.q_est_aw_hat[3];
      controlAerobi_B.Re_R[7] = -2.0 * controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[1] + controlAerobi_B.Gain7;
      controlAerobi_B.Re_R[2] = -2.0 * controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[2] +
        controlAerobi_B.DiscreteTimeIntegrator_b;
      controlAerobi_B.Re_R[5] = controlAerobi_B.Gain7 + 2.0 *
        controlAerobi_DWork.q_est_aw_hat[0] * controlAerobi_DWork.q_est_aw_hat[1];
      controlAerobi_B.Re_R[8] = ((controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[0] - controlAerobi_DWork.q_est_aw_hat[1]
        * controlAerobi_DWork.q_est_aw_hat[1]) -
        controlAerobi_DWork.q_est_aw_hat[2] * controlAerobi_DWork.q_est_aw_hat[2])
        + controlAerobi_DWork.q_est_aw_hat[3] *
        controlAerobi_DWork.q_est_aw_hat[3];
      for (i = 0; i < 3; i++) {
        controlAerobi_B.eulerZYX[i] = controlAerobi_B.Re_R[i + 6] +
          (controlAerobi_B.Re_R[i + 3] * 0.0 + controlAerobi_B.Re_R[i] * 0.0);
      }
    } else {
      // '<S130>:1:66'
      controlAerobi_B.Sum = rt_atan2d_snf(-controlAerobi_B.Add_j[1],
        controlAerobi_B.Add_j[0]);

      // '<S130>:1:67'
      controlAerobi_DWork.q_est_aw_hat[0] = cos(controlAerobi_B.Sum / 2.0);
      controlAerobi_DWork.q_est_aw_hat[1] = 0.0;
      controlAerobi_DWork.q_est_aw_hat[2] = 0.0;
      controlAerobi_DWork.q_est_aw_hat[3] = sin(controlAerobi_B.Sum / 2.0);

      // '<S130>:1:68'
      // '<S130>:1:69'
      // '<S130>:1:125'
      controlAerobi_B.Gain7 = controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[0];
      controlAerobi_B.Abs_a = controlAerobi_DWork.q_est_aw_hat[1] *
        controlAerobi_DWork.q_est_aw_hat[1];
      controlAerobi_B.DiscreteTimeIntegrator_b =
        controlAerobi_DWork.q_est_aw_hat[2] * controlAerobi_DWork.q_est_aw_hat[2];
      controlAerobi_B.Sum = controlAerobi_DWork.q_est_aw_hat[3] *
        controlAerobi_DWork.q_est_aw_hat[3];
      controlAerobi_B.Re_R[0] = ((controlAerobi_B.Gain7 + controlAerobi_B.Abs_a)
        - controlAerobi_B.DiscreteTimeIntegrator_b) - controlAerobi_B.Sum;
      controlAerobi_B.b_exp_b = controlAerobi_DWork.q_est_aw_hat[1] *
        controlAerobi_DWork.q_est_aw_hat[2];
      controlAerobi_B.sinc = controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[3];
      controlAerobi_B.Re_R[1] = (controlAerobi_B.b_exp_b - controlAerobi_B.sinc)
        * 2.0;
      controlAerobi_B.r_x_idx_0 = controlAerobi_DWork.q_est_aw_hat[1] *
        controlAerobi_DWork.q_est_aw_hat[3];
      controlAerobi_B.r_x_idx_1 = controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[2];
      controlAerobi_B.Re_R[2] = (controlAerobi_B.r_x_idx_1 +
        controlAerobi_B.r_x_idx_0) * 2.0;
      controlAerobi_B.Re_R[3] = (controlAerobi_B.b_exp_b + controlAerobi_B.sinc)
        * 2.0;
      controlAerobi_B.Gain7 -= controlAerobi_B.Abs_a;
      controlAerobi_B.Re_R[4] = (controlAerobi_B.Gain7 +
        controlAerobi_B.DiscreteTimeIntegrator_b) - controlAerobi_B.Sum;
      controlAerobi_B.Abs_a = controlAerobi_DWork.q_est_aw_hat[0] *
        controlAerobi_DWork.q_est_aw_hat[1];
      controlAerobi_B.b_exp_b = controlAerobi_DWork.q_est_aw_hat[2] *
        controlAerobi_DWork.q_est_aw_hat[3];
      controlAerobi_B.Re_R[5] = (controlAerobi_B.b_exp_b - controlAerobi_B.Abs_a)
        * 2.0;
      controlAerobi_B.Re_R[6] = (controlAerobi_B.r_x_idx_0 -
        controlAerobi_B.r_x_idx_1) * 2.0;
      controlAerobi_B.Re_R[7] = (controlAerobi_B.Abs_a + controlAerobi_B.b_exp_b)
        * 2.0;
      controlAerobi_B.Re_R[8] = (controlAerobi_B.Gain7 -
        controlAerobi_B.DiscreteTimeIntegrator_b) + controlAerobi_B.Sum;
      for (i = 0; i < 3; i++) {
        controlAerobi_B.eulerZYX[i] = controlAerobi_B.Re_R[i + 6] +
          (controlAerobi_B.Re_R[i + 3] * 0.0 + controlAerobi_B.Re_R[i] * 0.0);
      }
    }

    // '<S130>:1:76'
    // '<S130>:1:77'
    // '<S130>:1:78'
    // '<S130>:1:80'
    // '<S130>:1:81'
    // '<S130>:1:82'
    // '<S130>:1:85'
    controlAerobi_B.Sum = (controlAerobi_B.eulerZYX[0] * controlAerobi_B.Add_j[0]
      + controlAerobi_B.eulerZYX[1] * controlAerobi_B.Add_j[1]) +
      controlAerobi_B.eulerZYX[2] * controlAerobi_B.Add_j[2];

    // '<S130>:1:86'
    // '<S130>:1:89'
    controlAerobi_B.r2[0] = controlAerobi_B.Sum;
    controlAerobi_B.r2[1] = 0.0;
    controlAerobi_B.r2[2] = sqrt(1.0 - controlAerobi_B.Sum * controlAerobi_B.Sum);

    // '<S130>:1:94'
    controlAerobi_B.rtb_Gain_po_l[0] = 0.0 * controlAerobi_B.r2[2];
    controlAerobi_B.Gain7 = controlAerobi_B.Sum - 0.0 * controlAerobi_B.r2[2];
    controlAerobi_B.rtb_Gain_po_l[1] = controlAerobi_B.Gain7;
    controlAerobi_B.Abs_a = 0.0 - 0.0 * controlAerobi_B.Sum;
    controlAerobi_B.rtb_Gain_po_l[2] = controlAerobi_B.Abs_a;
    controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
      (controlAerobi_B.rtb_Gain_po_l);
    controlAerobi_B.r_x_idx_0 = 0.0 * controlAerobi_B.r2[2] /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.r_x_idx_1 = controlAerobi_B.Gain7 /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.r_x_idx_2 = controlAerobi_B.Abs_a /
      controlAerobi_B.DiscreteTimeIntegrator_b;

    // '<S130>:1:95'
    controlAerobi_B.Zgain_a = controlAerobi_B.eulerZYX[1] *
      controlAerobi_B.Add_j[2] - controlAerobi_B.eulerZYX[2] *
      controlAerobi_B.Add_j[1];
    controlAerobi_B.rtb_Gain_po_l[0] = controlAerobi_B.Zgain_a;
    controlAerobi_B.sinc = controlAerobi_B.eulerZYX[2] * controlAerobi_B.Add_j[0]
      - controlAerobi_B.eulerZYX[0] * controlAerobi_B.Add_j[2];
    controlAerobi_B.rtb_Gain_po_l[1] = controlAerobi_B.sinc;
    controlAerobi_B.b_exp_b = controlAerobi_B.eulerZYX[0] *
      controlAerobi_B.Add_j[1] - controlAerobi_B.eulerZYX[1] *
      controlAerobi_B.Add_j[0];
    controlAerobi_B.rtb_Gain_po_l[2] = controlAerobi_B.b_exp_b;
    controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
      (controlAerobi_B.rtb_Gain_po_l);
    controlAerobi_B.Zgain_a /= controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.b_x_idx_1 = controlAerobi_B.sinc /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.b_x_idx_2 = controlAerobi_B.b_exp_b /
      controlAerobi_B.DiscreteTimeIntegrator_b;

    // '<S130>:1:99'
    controlAerobi_B.sinc = (controlAerobi_B.eulerZYX[1] -
      controlAerobi_B.eulerZYX[2] * 0.0) * controlAerobi_P.weight_Value +
      (controlAerobi_B.Add_j[1] * controlAerobi_B.r2[2] - controlAerobi_B.Add_j
       [2] * 0.0) * (1.0 - controlAerobi_P.weight_Value);
    controlAerobi_B.rtb_Switch_Pos_idx_1 = (controlAerobi_B.eulerZYX[2] * 0.0 -
      controlAerobi_B.eulerZYX[0]) * controlAerobi_P.weight_Value +
      (controlAerobi_B.Add_j[2] * controlAerobi_B.Sum - controlAerobi_B.Add_j[0]
       * controlAerobi_B.r2[2]) * (1.0 - controlAerobi_P.weight_Value);
    controlAerobi_B.absxk = (controlAerobi_B.eulerZYX[0] * 0.0 -
      controlAerobi_B.eulerZYX[1] * 0.0) * controlAerobi_P.weight_Value +
      (controlAerobi_B.Add_j[0] * 0.0 - controlAerobi_B.Add_j[1] *
       controlAerobi_B.Sum) * (1.0 - controlAerobi_P.weight_Value);
    controlAerobi_B.b_exp_b = ((controlAerobi_B.sinc *
      (controlAerobi_B.b_x_idx_1 * controlAerobi_B.r_x_idx_2 -
       controlAerobi_B.b_x_idx_2 * controlAerobi_B.r_x_idx_1) +
      controlAerobi_B.rtb_Switch_Pos_idx_1 * (controlAerobi_B.b_x_idx_2 *
      controlAerobi_B.r_x_idx_0 - controlAerobi_B.Zgain_a *
      controlAerobi_B.r_x_idx_2)) + controlAerobi_B.absxk *
      (controlAerobi_B.Zgain_a * controlAerobi_B.r_x_idx_1 -
       controlAerobi_B.b_x_idx_1 * controlAerobi_B.r_x_idx_0)) +
      (((controlAerobi_B.eulerZYX[0] * 0.0 + controlAerobi_B.eulerZYX[1] * 0.0)
        + controlAerobi_B.eulerZYX[2]) * controlAerobi_P.weight_Value +
       ((controlAerobi_B.Add_j[0] * controlAerobi_B.Sum + controlAerobi_B.Add_j
         [1] * 0.0) + controlAerobi_B.Add_j[2] * controlAerobi_B.r2[2]) * (1.0 -
        controlAerobi_P.weight_Value)) * (((controlAerobi_B.r_x_idx_0 *
      controlAerobi_B.Zgain_a + controlAerobi_B.r_x_idx_1 *
      controlAerobi_B.b_x_idx_1) + controlAerobi_B.r_x_idx_2 *
      controlAerobi_B.b_x_idx_2) + 1.0);

    // '<S130>:1:100'
    controlAerobi_B.Sum = (controlAerobi_B.sinc * (controlAerobi_B.Zgain_a +
      controlAerobi_B.r_x_idx_0) + controlAerobi_B.rtb_Switch_Pos_idx_1 *
      (controlAerobi_B.b_x_idx_1 + controlAerobi_B.r_x_idx_1)) +
      controlAerobi_B.absxk * (controlAerobi_B.b_x_idx_2 +
      controlAerobi_B.r_x_idx_2);

    // DiscreteFir: '<S104>/Hlp' incorporates:
    //   Constant: '<S127>/weight'
    //   Constant: '<S127>/ya'
    //   Lookup_n-D: '<S70>/1-D Lookup Table'
    //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
    //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

    o = 3;

    // '<S130>:1:101'
    controlAerobi_B.DiscreteTimeIntegrator_b = sqrt(controlAerobi_B.b_exp_b *
      controlAerobi_B.b_exp_b + controlAerobi_B.Sum * controlAerobi_B.Sum);
    if (controlAerobi_B.b_exp_b >= 0.0) {
      // '<S130>:1:103'
      // '<S130>:1:104'
      controlAerobi_B.sinc = controlAerobi_B.DiscreteTimeIntegrator_b +
        controlAerobi_B.b_exp_b;

      // DiscreteFir: '<S104>/Hlp' incorporates:
      //   Lookup_n-D: '<S70>/1-D Lookup Table'
      //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
      //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

      o = 3;
      controlAerobi_B.q_k_d[0] = (controlAerobi_B.b_x_idx_1 *
        controlAerobi_B.r_x_idx_2 - controlAerobi_B.b_x_idx_2 *
        controlAerobi_B.r_x_idx_1) * controlAerobi_B.sinc +
        (controlAerobi_B.Zgain_a + controlAerobi_B.r_x_idx_0) *
        controlAerobi_B.Sum;
      controlAerobi_B.q_k_d[1] = (controlAerobi_B.b_x_idx_2 *
        controlAerobi_B.r_x_idx_0 - controlAerobi_B.Zgain_a *
        controlAerobi_B.r_x_idx_2) * controlAerobi_B.sinc +
        (controlAerobi_B.b_x_idx_1 + controlAerobi_B.r_x_idx_1) *
        controlAerobi_B.Sum;
      controlAerobi_B.q_k_d[2] = (controlAerobi_B.Zgain_a *
        controlAerobi_B.r_x_idx_1 - controlAerobi_B.b_x_idx_1 *
        controlAerobi_B.r_x_idx_0) * controlAerobi_B.sinc +
        (controlAerobi_B.b_x_idx_2 + controlAerobi_B.r_x_idx_2) *
        controlAerobi_B.Sum;
      controlAerobi_B.q_k_d[3] = (((controlAerobi_B.Zgain_a *
        controlAerobi_B.r_x_idx_0 + controlAerobi_B.b_x_idx_1 *
        controlAerobi_B.r_x_idx_1) + controlAerobi_B.b_x_idx_2 *
        controlAerobi_B.r_x_idx_2) + 1.0) *
        (controlAerobi_B.DiscreteTimeIntegrator_b + controlAerobi_B.b_exp_b);
    } else {
      // '<S130>:1:107'
      controlAerobi_B.b_exp_b = controlAerobi_B.DiscreteTimeIntegrator_b -
        controlAerobi_B.b_exp_b;

      // DiscreteFir: '<S104>/Hlp' incorporates:
      //   Lookup_n-D: '<S70>/1-D Lookup Table'
      //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
      //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

      o = 3;
      controlAerobi_B.q_k_d[0] = (controlAerobi_B.b_x_idx_1 *
        controlAerobi_B.r_x_idx_2 - controlAerobi_B.b_x_idx_2 *
        controlAerobi_B.r_x_idx_1) * controlAerobi_B.Sum +
        (controlAerobi_B.Zgain_a + controlAerobi_B.r_x_idx_0) *
        controlAerobi_B.b_exp_b;
      controlAerobi_B.q_k_d[1] = (controlAerobi_B.b_x_idx_2 *
        controlAerobi_B.r_x_idx_0 - controlAerobi_B.Zgain_a *
        controlAerobi_B.r_x_idx_2) * controlAerobi_B.Sum +
        (controlAerobi_B.b_x_idx_1 + controlAerobi_B.r_x_idx_1) *
        controlAerobi_B.b_exp_b;
      controlAerobi_B.q_k_d[2] = (controlAerobi_B.Zgain_a *
        controlAerobi_B.r_x_idx_1 - controlAerobi_B.b_x_idx_1 *
        controlAerobi_B.r_x_idx_0) * controlAerobi_B.Sum +
        (controlAerobi_B.b_x_idx_2 + controlAerobi_B.r_x_idx_2) *
        controlAerobi_B.b_exp_b;
      controlAerobi_B.q_k_d[3] = (((controlAerobi_B.Zgain_a *
        controlAerobi_B.r_x_idx_0 + controlAerobi_B.b_x_idx_1 *
        controlAerobi_B.r_x_idx_1) + controlAerobi_B.b_x_idx_2 *
        controlAerobi_B.r_x_idx_2) + 1.0) * controlAerobi_B.Sum;
    }

    // '<S130>:1:111'
    controlAerobi_B.q_k_d[0] = (1.0 - controlAerobi_P.ym_Value) *
      controlAerobi_DWork.q_est_aw_hat[0] + controlAerobi_P.ym_Value *
      controlAerobi_B.q_k_d[0];
    controlAerobi_B.q_k_d[1] = (1.0 - controlAerobi_P.ym_Value) *
      controlAerobi_DWork.q_est_aw_hat[1] + controlAerobi_P.ym_Value *
      controlAerobi_B.q_k_d[1];
    controlAerobi_B.q_k_d[2] = (1.0 - controlAerobi_P.ym_Value) *
      controlAerobi_DWork.q_est_aw_hat[2] + controlAerobi_P.ym_Value *
      controlAerobi_B.q_k_d[2];
    controlAerobi_B.q_k_d[3] = (1.0 - controlAerobi_P.ym_Value) *
      controlAerobi_DWork.q_est_aw_hat[3] + controlAerobi_P.ym_Value *
      controlAerobi_B.q_k_d[3];

    // '<S130>:1:113'
    controlAerobi_B.DiscreteTimeIntegrator_b = norm_5ETDUxto
      (controlAerobi_B.q_k_d);
    controlAerobi_B.q_k_d[0] /= controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.q_k_d[1] /= controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.q_k_d[2] /= controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.q_k_d[3] /= controlAerobi_B.DiscreteTimeIntegrator_b;
  }

  if (distorsioned == 1) {
    // '<S130>:1:118'
    // '<S130>:1:119'
    controlAerobi_B.q_k_d[0] = controlAerobi_DWork.q_est_aw_hat[0];
    controlAerobi_B.q_k_d[1] = controlAerobi_DWork.q_est_aw_hat[1];
    controlAerobi_B.q_k_d[2] = controlAerobi_DWork.q_est_aw_hat[2];
    controlAerobi_B.q_k_d[3] = controlAerobi_DWork.q_est_aw_hat[3];
  } else {
    // '<S130>:1:121'
  }

  // End of MATLAB Function: '<S127>/FCF_fcn'

  // MATLAB Function: '<S106>/TGIC_fcn' incorporates:
  //   Constant: '<S106>/chi'
  //   Constant: '<S106>/er'
  //   Constant: '<S106>/mu'
  //   Constant: '<S106>/p0'
  //   Constant: '<S106>/qk'
  //   Constant: '<S106>/rk'

  // MATLAB Function 'Sensors/attitude/AttitudeEstimator/TGIC/TGIC_fcn': '<S129>:1' 
  // '<S129>:1:106'
  // '<S129>:1:87'
  // '<S129>:1:14'
  // '<S129>:1:3'
  // '<S129>:1:5'
  // '<S129>:1:6'
  rtb_LogicalOperator = !controlAerobi_DWork.P_k_not_empty_l;
  if ((!controlAerobi_DWork.S_a_not_empty) ||
      (!controlAerobi_DWork.S_m_not_empty) ||
      (!controlAerobi_DWork.S_g_not_empty) || (!controlAerobi_DWork.t_not_empty)
      || (!controlAerobi_DWork.X_k_not_empty) || rtb_LogicalOperator ||
      rtb_LogicalOperator || (!controlAerobi_DWork.S_P_not_empty) ||
      (!controlAerobi_DWork.time_not_empty_j)) {
    // '<S129>:1:10'
    // '<S129>:1:13'
    for (i = 0; i < 10; i++) {
      controlAerobi_DWork.X_k[i] = b[i];
    }

    controlAerobi_DWork.X_k_not_empty = true;

    // '<S129>:1:14'
    for (i = 0; i < 100; i++) {
      controlAerobi_DWork.P_k_hx[i] = controlAerobi_P.p0_Value * (real_T)b_b[i];
    }

    controlAerobi_DWork.P_k_not_empty_l = true;

    // '<S129>:1:15'
    memset(&controlAerobi_DWork.S_a[0], 0, 30U * sizeof(real_T));
    controlAerobi_DWork.S_a_not_empty = true;

    // '<S129>:1:16'
    controlAerobi_DWork.S_m_not_empty = true;

    // '<S129>:1:17'
    controlAerobi_DWork.S_g_not_empty = true;

    // '<S129>:1:18'
    memset(&controlAerobi_DWork.S_q[0], 0, 100U * sizeof(real_T));

    // '<S129>:1:19'
    memset(&controlAerobi_DWork.S_P[0], 0, 1000U * sizeof(real_T));
    controlAerobi_DWork.S_P_not_empty = true;

    // '<S129>:1:20'
    controlAerobi_DWork.t = 0.0;
    controlAerobi_DWork.t_not_empty = true;

    // '<S129>:1:21'
    controlAerobi_DWork.time_n = 0.0;
    controlAerobi_DWork.time_not_empty_j = true;
  } else {
    // '<S129>:1:23'
    controlAerobi_DWork.time_n++;
    if (controlAerobi_DWork.t < 10.0) {
      // '<S129>:1:26'
      // '<S129>:1:27'
      controlAerobi_DWork.t++;

      // '<S129>:1:28'
      i = 3 * ((int32_T)controlAerobi_DWork.t - 1);
      controlAerobi_DWork.S_a[i] = controlAerobi_B.Gain_po[0];
      controlAerobi_DWork.S_a[1 + i] = controlAerobi_B.Gain_po[1];
      controlAerobi_DWork.S_a[2 + i] = controlAerobi_B.Gain_po[2];

      // '<S129>:1:29'
      // '<S129>:1:30'
      // '<S129>:1:31'
      i = (int32_T)controlAerobi_DWork.t;

      // '<S129>:1:32'
      distorsioned = (int32_T)controlAerobi_DWork.t;
      for (r2 = 0; r2 < 10; r2++) {
        controlAerobi_DWork.S_q[r2 + 10 * (i - 1)] = controlAerobi_DWork.X_k[r2];
        for (o = 0; o < 10; o++) {
          controlAerobi_DWork.S_P[(o + 10 * r2) + 100 * (distorsioned - 1)] =
            controlAerobi_DWork.P_k_hx[10 * r2 + o];
        }
      }
    } else {
      // '<S129>:1:34'
      controlAerobi_DWork.t = 0.0;
    }

    // '<S129>:1:45'
    if (controlAerobi_DWork.t == 1.0) {
      // '<S129>:1:47'
      // '<S129>:1:48'
      controlAerobi_B.b_exp_b = controlAerobi_P.mu_Value * 0.0025;
      i = ((int32_T)controlAerobi_DWork.t - 1) * 3;
      controlAerobi_B.Gain_po[0] += (controlAerobi_B.Gain_po[0] -
        controlAerobi_DWork.S_a[i]) * controlAerobi_P.chi_Value /
        controlAerobi_B.b_exp_b;
      controlAerobi_B.Gain_po[1] += (controlAerobi_B.Gain_po[1] -
        controlAerobi_DWork.S_a[i + 1]) * controlAerobi_P.chi_Value /
        controlAerobi_B.b_exp_b;
      controlAerobi_B.Gain_po[2] += (controlAerobi_B.Gain_po[2] -
        controlAerobi_DWork.S_a[i + 2]) * controlAerobi_P.chi_Value /
        controlAerobi_B.b_exp_b;
    } else {
      // '<S129>:1:51'
      controlAerobi_B.Sum = controlAerobi_P.mu_Value * 0.0025;
      i = ((int32_T)(controlAerobi_DWork.t - 1.0) - 1) * 3;
      controlAerobi_B.Gain_po[0] += (controlAerobi_B.Gain_po[0] -
        controlAerobi_DWork.S_a[i]) * controlAerobi_P.chi_Value /
        controlAerobi_B.Sum;
      controlAerobi_B.Gain_po[1] += (controlAerobi_B.Gain_po[1] -
        controlAerobi_DWork.S_a[i + 1]) * controlAerobi_P.chi_Value /
        controlAerobi_B.Sum;
      controlAerobi_B.Gain_po[2] += (controlAerobi_B.Gain_po[2] -
        controlAerobi_DWork.S_a[i + 2]) * controlAerobi_P.chi_Value /
        controlAerobi_B.Sum;
    }

    // '<S129>:1:56'
    controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
      (controlAerobi_B.ubx_d);
    controlAerobi_B.ubx_d[0] /= controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.ubx_d[1] /= controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.sinc = controlAerobi_B.ubx_d[2] /
      controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_B.ubx_d[2] = controlAerobi_B.sinc;

    // '<S129>:1:57'
    controlAerobi_B.DiscreteTimeIntegrator_b = norm_OKjrfDiG
      (controlAerobi_B.Gain_po);

    // '<S129>:1:59'
    // '<S129>:1:66'
    controlAerobi_std(controlAerobi_DWork.S_a, controlAerobi_B.rtb_Gain_po_l);
    if (fabs(norm_OKjrfDiG(controlAerobi_B.rtb_Gain_po_l)) <=
        controlAerobi_P.er_Value) {
      // '<S129>:1:71'
      // '<S129>:1:72'
      o = 1;
    } else {
      // '<S129>:1:74'
      o = 0;
    }

    // '<S129>:1:82'
    // '<S129>:1:86'
    controlAerobi_B.b_exp_b = 0.00125 * norm_OKjrfDiG(controlAerobi_B.vbx);

    // '<S129>:1:87'
    controlAerobi_B.Sum = cos(controlAerobi_B.b_exp_b);
    sinc_ZOYMQSkt(&controlAerobi_B.b_exp_b);
    controlAerobi_B.absxk = 0.00125 * controlAerobi_B.b_exp_b;
    controlAerobi_B.R_f[0] = controlAerobi_B.absxk * 0.0;
    controlAerobi_B.r_x_idx_0 = controlAerobi_B.absxk * -controlAerobi_B.vbx[0];
    controlAerobi_B.R_f[4] = controlAerobi_B.r_x_idx_0;
    controlAerobi_B.r_x_idx_1 = controlAerobi_B.absxk * -controlAerobi_B.vbx[1];
    controlAerobi_B.R_f[8] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.r_x_idx_2 = controlAerobi_B.absxk * -controlAerobi_B.vbx[2];
    controlAerobi_B.R_f[12] = controlAerobi_B.r_x_idx_2;
    controlAerobi_B.Zgain_a = controlAerobi_B.absxk * controlAerobi_B.vbx[0];
    controlAerobi_B.R_f[1] = controlAerobi_B.Zgain_a;
    controlAerobi_B.R_f[5] = controlAerobi_B.absxk * 0.0;
    controlAerobi_B.b_x_idx_1 = controlAerobi_B.absxk * controlAerobi_B.vbx[2];
    controlAerobi_B.R_f[9] = controlAerobi_B.b_x_idx_1;
    controlAerobi_B.R_f[13] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.r_x_idx_1 = controlAerobi_B.absxk * controlAerobi_B.vbx[1];
    controlAerobi_B.R_f[2] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.R_f[6] = controlAerobi_B.r_x_idx_2;
    controlAerobi_B.R_f[10] = controlAerobi_B.absxk * 0.0;
    controlAerobi_B.R_f[14] = controlAerobi_B.Zgain_a;
    controlAerobi_B.R_f[3] = controlAerobi_B.b_x_idx_1;
    controlAerobi_B.R_f[7] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.R_f[11] = controlAerobi_B.r_x_idx_0;
    controlAerobi_B.R_f[15] = controlAerobi_B.absxk * 0.0;
    for (i = 0; i < 4; i++) {
      controlAerobi_B.F[10 * i] = (real_T)b_a[i << 2] * controlAerobi_B.Sum +
        controlAerobi_B.R_f[i << 2];
      controlAerobi_B.F[1 + 10 * i] = (real_T)b_a[(i << 2) + 1] *
        controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 1];
      controlAerobi_B.F[2 + 10 * i] = (real_T)b_a[(i << 2) + 2] *
        controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 2];
      controlAerobi_B.F[3 + 10 * i] = (real_T)b_a[(i << 2) + 3] *
        controlAerobi_B.Sum + controlAerobi_B.R_f[(i << 2) + 3];
    }

    for (i = 0; i < 6; i++) {
      r3 = 10 * (i + 4);
      controlAerobi_B.F[r3] = 0.0;
      controlAerobi_B.F[1 + r3] = 0.0;
      controlAerobi_B.F[2 + r3] = 0.0;
      controlAerobi_B.F[3 + r3] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      controlAerobi_B.F[4 + 10 * i] = c[3 * i];
      controlAerobi_B.F[7 + 10 * i] = d[3 * i];
      r3 = 3 * i + 1;
      controlAerobi_B.F[5 + 10 * i] = c[r3];
      controlAerobi_B.F[8 + 10 * i] = d[r3];
      r3 = 3 * i + 2;
      controlAerobi_B.F[6 + 10 * i] = c[r3];
      controlAerobi_B.F[9 + 10 * i] = d[r3];
    }

    // '<S129>:1:88'
    // '<S129>:1:89'
    diag_AmkIBh3P(controlAerobi_P.qk_Value, controlAerobi_B.dv0);
    for (i = 0; i < 10; i++) {
      for (distorsioned = 0; distorsioned < 10; distorsioned++) {
        r3 = i + 10 * distorsioned;
        controlAerobi_B.F_m[r3] = 0.0;
        for (r2 = 0; r2 < 10; r2++) {
          controlAerobi_B.F_m[r3] = controlAerobi_B.F[10 * r2 + i] *
            controlAerobi_DWork.P_k_hx[10 * distorsioned + r2] +
            controlAerobi_B.F_m[10 * distorsioned + i];
        }
      }

      for (distorsioned = 0; distorsioned < 10; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 10; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.F_m[10 * r2 + i] *
            controlAerobi_B.F[10 * r2 + distorsioned];
        }

        controlAerobi_B.P_k_[i + 10 * distorsioned] = controlAerobi_B.dv0[10 *
          distorsioned + i] + controlAerobi_B.Gain7;
      }
    }

    // '<S129>:1:92'
    // '<S129>:1:93'
    // '<S129>:1:96'
    controlAerobi_B.Add_j[0] = sqrt(controlAerobi_B.ubx_d[0] *
      controlAerobi_B.ubx_d[0] + controlAerobi_B.ubx_d[1] *
      controlAerobi_B.ubx_d[1]);

    // '<S129>:1:97'
    // '<S129>:1:98'
    // '<S129>:1:100'
    // '<S129>:1:103'
    // '<S129>:1:106'
    controlAerobi_B.Ak[0] = 19.62 * controlAerobi_DWork.X_k[2];
    controlAerobi_B.Ak[6] = -19.62 * controlAerobi_DWork.X_k[3];
    controlAerobi_B.Ak[12] = 19.62 * controlAerobi_DWork.X_k[0];
    controlAerobi_B.Ak[18] = -19.62 * controlAerobi_DWork.X_k[1];
    controlAerobi_B.Ak[1] = -19.62 * controlAerobi_DWork.X_k[1];
    controlAerobi_B.Ak[7] = -19.62 * controlAerobi_DWork.X_k[0];
    controlAerobi_B.Ak[13] = -19.62 * controlAerobi_DWork.X_k[3];
    controlAerobi_B.Ak[19] = -19.62 * controlAerobi_DWork.X_k[2];
    controlAerobi_B.Ak[2] = -39.24 * controlAerobi_DWork.X_k[0];
    controlAerobi_B.Ak[8] = 0.0;
    controlAerobi_B.Ak[14] = 0.0;
    controlAerobi_B.Ak[20] = 39.24 * controlAerobi_DWork.X_k[3];
    controlAerobi_B.Ak[3] = (4.0 * controlAerobi_B.Add_j[0] *
      controlAerobi_DWork.X_k[0] - 2.0 * controlAerobi_B.sinc *
      controlAerobi_DWork.X_k[2]) + 0.0 * controlAerobi_DWork.X_k[3];
    controlAerobi_B.Ak[9] = (4.0 * controlAerobi_B.Add_j[0] *
      controlAerobi_DWork.X_k[1] - 0.0 * controlAerobi_DWork.X_k[2]) + 2.0 *
      controlAerobi_B.sinc * controlAerobi_DWork.X_k[3];
    controlAerobi_B.Ak[15] = -2.0 * controlAerobi_B.sinc *
      controlAerobi_DWork.X_k[0] + 0.0 * controlAerobi_DWork.X_k[0];
    controlAerobi_B.Ak[21] = 2.0 * controlAerobi_B.sinc *
      controlAerobi_DWork.X_k[1] + 0.0 * controlAerobi_DWork.X_k[0];
    controlAerobi_B.Sum = 2.0 * controlAerobi_B.Add_j[0] *
      controlAerobi_DWork.X_k[3];
    controlAerobi_B.Ak[4] = (2.0 * controlAerobi_B.sinc *
      controlAerobi_DWork.X_k[1] + 0.0 * controlAerobi_DWork.X_k[0]) -
      controlAerobi_B.Sum;
    controlAerobi_B.b_exp_b = 2.0 * controlAerobi_B.Add_j[0] *
      controlAerobi_DWork.X_k[2];
    controlAerobi_B.Ak[10] = 2.0 * controlAerobi_B.sinc *
      controlAerobi_DWork.X_k[0] + controlAerobi_B.b_exp_b;
    controlAerobi_B.r_x_idx_0 = 2.0 * controlAerobi_B.Add_j[0] *
      controlAerobi_DWork.X_k[1] + 0.0 * controlAerobi_DWork.X_k[2];
    controlAerobi_B.Ak[16] = controlAerobi_B.r_x_idx_0 + 2.0 *
      controlAerobi_B.sinc * controlAerobi_DWork.X_k[3];
    controlAerobi_B.Ak[22] = -2.0 * controlAerobi_B.Add_j[0] *
      controlAerobi_DWork.X_k[0] + 2.0 * controlAerobi_B.sinc *
      controlAerobi_DWork.X_k[2];
    controlAerobi_B.Ak[5] = (4.0 * controlAerobi_B.sinc *
      controlAerobi_DWork.X_k[0] - 0.0 * controlAerobi_DWork.X_k[1]) +
      controlAerobi_B.b_exp_b;
    controlAerobi_B.Ak[11] = controlAerobi_B.Sum + -0.0 *
      controlAerobi_DWork.X_k[0];
    controlAerobi_B.Ak[17] = 2.0 * controlAerobi_B.Add_j[0] *
      controlAerobi_DWork.X_k[0] + 0.0 * controlAerobi_DWork.X_k[3];
    controlAerobi_B.Ak[23] = controlAerobi_B.r_x_idx_0 + 4.0 *
      controlAerobi_B.sinc * controlAerobi_DWork.X_k[3];
    for (i = 0; i < 3; i++) {
      r3 = 6 * (i + 4);
      controlAerobi_B.Ak[r3] = e[3 * i];
      distorsioned = 6 * (i + 7);
      controlAerobi_B.Ak[distorsioned] = 0.0;
      controlAerobi_B.Ak[3 + r3] = 0.0;
      controlAerobi_B.Ak[3 + distorsioned] = e[3 * i];
      controlAerobi_B.Ak[1 + r3] = e[3 * i + 1];
      controlAerobi_B.Ak[1 + distorsioned] = 0.0;
      controlAerobi_B.Ak[4 + r3] = 0.0;
      controlAerobi_B.Ak[4 + distorsioned] = e[3 * i + 1];
      controlAerobi_B.Ak[2 + r3] = e[3 * i + 2];
      controlAerobi_B.Ak[2 + distorsioned] = 0.0;
      controlAerobi_B.Ak[5 + r3] = 0.0;
      controlAerobi_B.Ak[5 + distorsioned] = e[3 * i + 2];
    }

    // '<S129>:1:109'
    for (i = 0; i < 10; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        r3 = i + 10 * distorsioned;
        controlAerobi_B.P_k__c[r3] = 0.0;
        for (r2 = 0; r2 < 10; r2++) {
          controlAerobi_B.P_k__c[r3] = controlAerobi_B.P_k_[10 * r2 + i] *
            controlAerobi_B.Ak[6 * r2 + distorsioned] + controlAerobi_B.P_k__c
            [10 * distorsioned + i];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 10; distorsioned++) {
        controlAerobi_B.K_k[distorsioned + 10 * i] = controlAerobi_B.P_k__c[10 *
          i + distorsioned] * (real_T)o;
      }
    }

    diag_ZmyGsYYI(controlAerobi_P.rk_Value, controlAerobi_B.dF_k);
    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 10; distorsioned++) {
        r3 = i + 6 * distorsioned;
        controlAerobi_B.P_k__c[r3] = 0.0;
        for (r2 = 0; r2 < 10; r2++) {
          controlAerobi_B.P_k__c[r3] = controlAerobi_B.Ak[6 * r2 + i] *
            controlAerobi_B.P_k_[10 * distorsioned + r2] +
            controlAerobi_B.P_k__c[6 * distorsioned + i];
        }
      }

      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 10; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.P_k__c[6 * r2 + i] *
            controlAerobi_B.Ak[6 * r2 + distorsioned];
        }

        controlAerobi_B.dQ[i + 6 * distorsioned] = controlAerobi_B.dF_k[6 *
          distorsioned + i] + controlAerobi_B.Gain7;
      }
    }

    controlAerobi_mrdivide_eK1qdBt4(controlAerobi_B.K_k, controlAerobi_B.dQ);

    // '<S129>:1:111'
    // '<S129>:1:114'
    controlAerobi_rotation_SYBOT8wI(&controlAerobi_DWork.X_k[0],
      controlAerobi_B.Re_R);
    controlAerobi_B.a[0] = (-2.0 * controlAerobi_DWork.X_k[0] *
      controlAerobi_DWork.X_k[2] + 2.0 * controlAerobi_DWork.X_k[1] *
      controlAerobi_DWork.X_k[3]) * -9.81;
    controlAerobi_B.a[1] = (2.0 * controlAerobi_DWork.X_k[0] *
      controlAerobi_DWork.X_k[1] + 2.0 * controlAerobi_DWork.X_k[2] *
      controlAerobi_DWork.X_k[3]) * -9.81;
    controlAerobi_B.a[2] = ((controlAerobi_DWork.X_k[0] *
      controlAerobi_DWork.X_k[0] * 2.0 + controlAerobi_DWork.X_k[3] *
      controlAerobi_DWork.X_k[3] * 2.0) - 1.0) * -9.81;
    for (i = 0; i < 3; i++) {
      controlAerobi_B.single2double[i] = controlAerobi_B.Gain_po[i] /
        controlAerobi_B.DiscreteTimeIntegrator_b;
      controlAerobi_B.single2double[i + 3] = controlAerobi_B.ubx_d[i];
      controlAerobi_B.a[i + 3] = controlAerobi_B.Re_R[3 * i + 2] *
        controlAerobi_B.sinc + (controlAerobi_B.Re_R[3 * i + 1] * 0.0 +
        controlAerobi_B.Re_R[3 * i] * controlAerobi_B.Add_j[0]);
    }

    for (i = 0; i < 6; i++) {
      controlAerobi_B.rtb_Gain_po_g[i] = controlAerobi_B.single2double[i] -
        controlAerobi_B.a[i];
    }

    for (i = 0; i < 10; i++) {
      controlAerobi_B.F_p[i] = 0.0;
      for (distorsioned = 0; distorsioned < 10; distorsioned++) {
        controlAerobi_B.F_p[i] += controlAerobi_B.F[10 * distorsioned + i] *
          controlAerobi_DWork.X_k[distorsioned];
      }
    }

    for (i = 0; i < 10; i++) {
      controlAerobi_B.o[i] = 0.0;
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_B.K_k[10 *
          distorsioned + i] * (real_T)o *
          controlAerobi_B.rtb_Gain_po_g[distorsioned] + controlAerobi_B.o[i];
        controlAerobi_B.o[i] = controlAerobi_B.DiscreteTimeIntegrator_b;
      }
    }

    // '<S129>:1:115'
    for (i = 0; i < 10; i++) {
      controlAerobi_DWork.X_k[i] = controlAerobi_B.F_p[i] + controlAerobi_B.o[i];
      for (distorsioned = 0; distorsioned < 10; distorsioned++) {
        o = i + 10 * distorsioned;
        controlAerobi_B.F[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.F[o] = controlAerobi_B.K_k[10 * r2 + i] *
            controlAerobi_B.Ak[6 * distorsioned + r2] + controlAerobi_B.F[10 *
            distorsioned + i];
        }
      }

      for (distorsioned = 0; distorsioned < 10; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 10; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.F[10 * r2 + i] *
            controlAerobi_B.P_k_[10 * distorsioned + r2];
        }

        controlAerobi_DWork.P_k_hx[i + 10 * distorsioned] =
          controlAerobi_B.P_k_[10 * distorsioned + i] - controlAerobi_B.Gain7;
      }
    }

    if ((!rtIsNaN(xnrm2_BcBwAYPM(controlAerobi_DWork.X_k))) && (!rtIsNaN
         (controlAerobi_norm_0KU7QpIQ(controlAerobi_DWork.P_k_hx)))) {
      // '<S129>:1:118'
      // '<S129>:1:119'
      // '<S129>:1:120'
    } else if (controlAerobi_DWork.t == 1.0) {
      // '<S129>:1:122'
      // '<S129>:1:123'
      // '<S129>:1:124'
      for (i = 0; i < 10; i++) {
        controlAerobi_DWork.X_k[i] = controlAerobi_DWork.S_q[90 + i];
        for (distorsioned = 0; distorsioned < 10; distorsioned++) {
          controlAerobi_DWork.P_k_hx[distorsioned + 10 * i] =
            controlAerobi_DWork.S_P[(10 * i + distorsioned) + 900];
        }
      }
    } else {
      // '<S129>:1:126'
      i = (int32_T)(controlAerobi_DWork.t - 1.0);

      // '<S129>:1:127'
      distorsioned = (int32_T)(controlAerobi_DWork.t - 1.0);
      for (r2 = 0; r2 < 10; r2++) {
        controlAerobi_DWork.X_k[r2] = controlAerobi_DWork.S_q[(i - 1) * 10 + r2];
        for (o = 0; o < 10; o++) {
          controlAerobi_DWork.P_k_hx[o + 10 * r2] = controlAerobi_DWork.S_P[(10 *
            r2 + o) + (distorsioned - 1) * 100];
        }
      }
    }
  }

  // Sqrt: '<S133>/sqrt' incorporates:
  //   MATLAB Function: '<S106>/TGIC_fcn'
  //   Product: '<S134>/Product'
  //   Product: '<S134>/Product1'
  //   Product: '<S134>/Product2'
  //   Product: '<S134>/Product3'
  //   Sum: '<S134>/Sum'

  // '<S129>:1:135'
  // '<S129>:1:136'
  controlAerobi_B.DiscreteTimeIntegrator_b = sqrt(((controlAerobi_B.q_k_d[0] *
    controlAerobi_B.q_k_d[0] + controlAerobi_B.q_k_d[1] * controlAerobi_B.q_k_d
    [1]) + controlAerobi_B.q_k_d[2] * controlAerobi_B.q_k_d[2]) +
    controlAerobi_B.q_k_d[3] * controlAerobi_B.q_k_d[3]);

  // Product: '<S132>/Product' incorporates:
  //   MATLAB Function: '<S106>/TGIC_fcn'

  controlAerobi_B.Product1_ew = controlAerobi_B.q_k_d[0] /
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Product: '<S132>/Product1' incorporates:
  //   MATLAB Function: '<S106>/TGIC_fcn'

  controlAerobi_B.Product1_a1 = controlAerobi_B.q_k_d[1] /
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Product: '<S132>/Product2' incorporates:
  //   MATLAB Function: '<S106>/TGIC_fcn'

  controlAerobi_B.Abs_a = controlAerobi_B.q_k_d[2] /
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Product: '<S132>/Product3' incorporates:
  //   MATLAB Function: '<S106>/TGIC_fcn'

  controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_B.q_k_d[3] /
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Trigonometry: '<S131>/Trigonometric Function1' incorporates:
  //   Fcn: '<S128>/fcn1'
  //   Fcn: '<S128>/fcn2'

  controlAerobi_B.Add_j[0] = rt_atan2d_snf((controlAerobi_B.Product1_a1 *
    controlAerobi_B.Abs_a - controlAerobi_B.Product1_ew *
    controlAerobi_B.DiscreteTimeIntegrator_b) * -2.0,
    ((controlAerobi_B.Product1_ew * controlAerobi_B.Product1_ew -
      controlAerobi_B.Product1_a1 * controlAerobi_B.Product1_a1) +
     controlAerobi_B.Abs_a * controlAerobi_B.Abs_a) -
    controlAerobi_B.DiscreteTimeIntegrator_b *
    controlAerobi_B.DiscreteTimeIntegrator_b);

  // Fcn: '<S128>/fcn3'
  controlAerobi_B.absxk = (controlAerobi_B.Abs_a *
    controlAerobi_B.DiscreteTimeIntegrator_b + controlAerobi_B.Product1_ew *
    controlAerobi_B.Product1_a1) * 2.0;

  // Trigonometry: '<S131>/trigFcn'
  if (controlAerobi_B.absxk > 1.0) {
    controlAerobi_B.absxk = 1.0;
  } else {
    if (controlAerobi_B.absxk < -1.0) {
      controlAerobi_B.absxk = -1.0;
    }
  }

  controlAerobi_B.Add_j[1] = asin(controlAerobi_B.absxk);

  // End of Trigonometry: '<S131>/trigFcn'

  // Fcn: '<S128>/fcn4'
  controlAerobi_B.Zgain_a = (controlAerobi_B.Product1_a1 *
    controlAerobi_B.DiscreteTimeIntegrator_b - controlAerobi_B.Product1_ew *
    controlAerobi_B.Abs_a) * -2.0;

  // Fcn: '<S128>/fcn5'
  controlAerobi_B.Product1_ew = ((controlAerobi_B.Product1_ew *
    controlAerobi_B.Product1_ew - controlAerobi_B.Product1_a1 *
    controlAerobi_B.Product1_a1) - controlAerobi_B.Abs_a * controlAerobi_B.Abs_a)
    + controlAerobi_B.DiscreteTimeIntegrator_b *
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Trigonometry: '<S131>/Trigonometric Function3'
  controlAerobi_B.Add_j[2] = rt_atan2d_snf(controlAerobi_B.Zgain_a,
    controlAerobi_B.Product1_ew);

  // MultiPortSwitch: '<S101>/Multiport Switch' incorporates:
  //   Constant: '<S101>/select'
  //   Constant: '<S117>/offset'
  //   Fcn: '<S150>/fcn1'
  //   Fcn: '<S150>/fcn2'
  //   Fcn: '<S150>/fcn4'
  //   Fcn: '<S150>/fcn5'
  //   Gain: '<S117>/Gain'
  //   Sum: '<S117>/Sum1'
  //   Trigonometry: '<S151>/Trigonometric Function1'
  //   Trigonometry: '<S151>/Trigonometric Function3'
  //   Trigonometry: '<S151>/trigFcn'

  switch ((int32_T)controlAerobi_P.select_Value) {
   case 1:
    controlAerobi_B.Gain_po[0] = controlAerobi_B.RotationAnglescorrection[0];
    controlAerobi_B.Gain_po[1] = controlAerobi_B.RotationAnglescorrection[1];
    controlAerobi_B.Gain_po[2] = controlAerobi_B.Unwrap;
    break;

   case 2:
    // Sqrt: '<S153>/sqrt' incorporates:
    //   Product: '<S154>/Product'
    //   Product: '<S154>/Product1'
    //   Product: '<S154>/Product2'
    //   Product: '<S154>/Product3'
    //   Sum: '<S154>/Sum'

    controlAerobi_B.sinc = sqrt(((controlAerobi_B.Switch_ed[0] *
      controlAerobi_B.Switch_ed[0] + controlAerobi_B.Switch_ed[1] *
      controlAerobi_B.Switch_ed[1]) + controlAerobi_B.Switch_ed[2] *
      controlAerobi_B.Switch_ed[2]) + controlAerobi_B.Switch_ed[3] *
      controlAerobi_B.Switch_ed[3]);

    // Product: '<S152>/Product3'
    controlAerobi_B.Sum = controlAerobi_B.Switch_ed[3] / controlAerobi_B.sinc;

    // Product: '<S152>/Product2'
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_B.Switch_ed[2] /
      controlAerobi_B.sinc;

    // Product: '<S152>/Product1'
    controlAerobi_B.b_exp_b = controlAerobi_B.Switch_ed[1] /
      controlAerobi_B.sinc;

    // Product: '<S152>/Product'
    controlAerobi_B.sinc = controlAerobi_B.Switch_ed[0] / controlAerobi_B.sinc;
    controlAerobi_B.Gain_po[0] = rt_atan2d_snf((controlAerobi_B.b_exp_b *
      controlAerobi_B.Sum - controlAerobi_B.sinc *
      controlAerobi_B.DiscreteTimeIntegrator_b) * -2.0, ((controlAerobi_B.sinc *
      controlAerobi_B.sinc - controlAerobi_B.b_exp_b * controlAerobi_B.b_exp_b)
      - controlAerobi_B.DiscreteTimeIntegrator_b *
      controlAerobi_B.DiscreteTimeIntegrator_b) + controlAerobi_B.Sum *
      controlAerobi_B.Sum) + controlAerobi_P.Gain_Gain_l *
      controlAerobi_P.offset_Value[0];

    // Fcn: '<S150>/fcn3' incorporates:
    //   Constant: '<S117>/offset'
    //   Fcn: '<S150>/fcn4'
    //   Fcn: '<S150>/fcn5'
    //   Gain: '<S117>/Gain'
    //   Sum: '<S117>/Sum1'
    //   Trigonometry: '<S151>/Trigonometric Function3'

    controlAerobi_B.absxk = (controlAerobi_B.DiscreteTimeIntegrator_b *
      controlAerobi_B.Sum + controlAerobi_B.sinc * controlAerobi_B.b_exp_b) *
      2.0;

    // Trigonometry: '<S151>/trigFcn'
    if (controlAerobi_B.absxk > 1.0) {
      controlAerobi_B.absxk = 1.0;
    } else {
      if (controlAerobi_B.absxk < -1.0) {
        controlAerobi_B.absxk = -1.0;
      }
    }

    controlAerobi_B.Gain_po[1] = controlAerobi_P.Gain_Gain_l *
      controlAerobi_P.offset_Value[1] + asin(controlAerobi_B.absxk);
    controlAerobi_B.Gain_po[2] = rt_atan2d_snf((controlAerobi_B.b_exp_b *
      controlAerobi_B.DiscreteTimeIntegrator_b - controlAerobi_B.sinc *
      controlAerobi_B.Sum) * -2.0, ((controlAerobi_B.sinc * controlAerobi_B.sinc
      - controlAerobi_B.b_exp_b * controlAerobi_B.b_exp_b) +
      controlAerobi_B.DiscreteTimeIntegrator_b *
      controlAerobi_B.DiscreteTimeIntegrator_b) - controlAerobi_B.Sum *
      controlAerobi_B.Sum) + controlAerobi_P.Gain_Gain_l *
      controlAerobi_P.offset_Value[2];
    break;

   case 3:
    controlAerobi_B.Gain_po[0] = controlAerobi_B.ub[0];
    controlAerobi_B.Gain_po[1] = controlAerobi_B.ub[1];
    controlAerobi_B.Gain_po[2] = controlAerobi_B.ub[2];
    break;

   default:
    controlAerobi_B.Gain_po[0] = controlAerobi_B.Add_j[2];
    controlAerobi_B.Gain_po[1] = controlAerobi_B.Add_j[1];
    controlAerobi_B.Gain_po[2] = controlAerobi_B.Add_j[0];
    break;
  }

  // End of MultiPortSwitch: '<S101>/Multiport Switch'

  // Switch: '<S173>/Switch' incorporates:
  //   Constant: '<S173>/select_xy_px4'
  //   Constant: '<S173>/selector_xy_ekf'
  //   Inport: '<Root>/I_totalStation'

  if (controlAerobi_U.I_totalStation._time != 0.0) {
    controlAerobi_B.Sum = controlAerobi_P.selector_xy_ekf_Value;
  } else {
    controlAerobi_B.Sum = controlAerobi_P.select_xy_px4_Value;
  }

  // End of Switch: '<S173>/Switch'

  // S-Function (sdspFromNetwork): '<S181>/Local position receive'
  sErr = GetErrorBuffer(&controlAerobi_DWork.Localpositionreceive_NetworkLib[0U]);
  o = 7;
  LibOutputs_Network(&controlAerobi_DWork.Localpositionreceive_NetworkLib[0U],
                     &controlAerobi_B.Localpositionreceive_o1[0U], &o);
  if (*sErr != 0) {
    rtmSetErrorStatus(controlAerobi_M, sErr);
    rtmSetStopRequested(controlAerobi_M, 1);
  }

  // S-Function (any2byte): '<S181>/Byte Pack'

  // Pack: <S181>/Byte Pack
  (void) memcpy(&controlAerobi_B.BytePack_j[0],
                &controlAerobi_B.Localpositionreceive_o1[0],
                28);

  // S-Function (byte2any): '<S181>/Byte Unpack'

  // Unpack: <S181>/Byte Unpack
  (void) memcpy(&controlAerobi_B.ByteUnpack_o1_o[0],
                &controlAerobi_B.BytePack_j[0],
                24);
  (void) memcpy(&controlAerobi_B.ByteUnpack_o2_f, &controlAerobi_B.BytePack_j[24],
                4);

  // DataTypeConversion: '<S181>/single2double'
  for (i = 0; i < 6; i++) {
    controlAerobi_B.single2double[i] = controlAerobi_B.ByteUnpack_o1_o[i];
  }

  // End of DataTypeConversion: '<S181>/single2double'

  // Switch: '<S174>/Switch' incorporates:
  //   Constant: '<S174>/NED//ENU'
  //   Gain: '<S174>/Gain2'
  //   Gain: '<S174>/Gain3'
  //   Inport: '<Root>/I_totalStation'
  //   Switch: '<S174>/Switch1'

  if (controlAerobi_P.NEDENU_Value != 0.0) {
    controlAerobi_B.b_exp_b = (real_T)controlAerobi_P.Gain3_Gain_o *
      controlAerobi_U.I_totalStation._y;
    controlAerobi_B.sinc = (real_T)controlAerobi_P.Gain2_Gain_o *
      controlAerobi_U.I_totalStation._x;
  } else {
    controlAerobi_B.b_exp_b = (real_T)controlAerobi_P.Gain2_Gain_o *
      controlAerobi_U.I_totalStation._x;
    controlAerobi_B.sinc = (real_T)controlAerobi_P.Gain3_Gain_o *
      controlAerobi_U.I_totalStation._y;
  }

  // End of Switch: '<S174>/Switch'

  // MATLAB Function: '<S175>/buffer' incorporates:
  //   DataTypeConversion: '<S170>/Data Type Conversion'
  //   Inport: '<Root>/I_sf11c'

  // MATLAB Function 'Sensors/position/EKF_total_Station_Lidar/filter/buffer': '<S180>:1' 
  // '<S180>:1:3'
  if ((!controlAerobi_DWork.buffer_not_empty) ||
      (!controlAerobi_DWork.time_not_empty) ||
      (!controlAerobi_DWork.index_not_empty) ||
      (!controlAerobi_DWork.counter_not_empty) ||
      (!controlAerobi_DWork.acc__not_empty)) {
    // '<S180>:1:5'
    // '<S180>:1:6'
    memset(&controlAerobi_DWork.buffer[0], 0, 60U * sizeof(real_T));
    controlAerobi_DWork.buffer_not_empty = true;

    // '<S180>:1:7'
    controlAerobi_DWork.time = 0.0;
    controlAerobi_DWork.time_not_empty = true;

    // '<S180>:1:8'
    controlAerobi_DWork.index = 1.0;
    controlAerobi_DWork.index_not_empty = true;

    // '<S180>:1:9'
    memset(&controlAerobi_DWork.counter[0], 0, 20U * sizeof(real_T));
    controlAerobi_DWork.counter_not_empty = true;

    // '<S180>:1:10'
    i = (int32_T)controlAerobi_DWork.index - 1;
    controlAerobi_DWork.buffer[3 * i] = controlAerobi_B.b_exp_b;
    controlAerobi_DWork.buffer[1 + 3 * i] = controlAerobi_B.sinc;
    controlAerobi_DWork.buffer[2 + 3 * i] = controlAerobi_U.I_sf11c._z;

    // '<S180>:1:11'
    controlAerobi_DWork.counter[0] = 1.0;

    // '<S180>:1:12'
    controlAerobi_DWork.acc_[0] = 0.0;
    controlAerobi_DWork.acc_[1] = 0.0;
    controlAerobi_DWork.acc_[2] = 1.0;
    controlAerobi_DWork.acc__not_empty = true;
  } else {
    // '<S180>:1:15'
    controlAerobi_B.r_x_idx_2 = 3.3121686421112381E-170;
    controlAerobi_B.r_x_idx_0 = fabs(controlAerobi_B.Switch[0]);
    if (controlAerobi_B.r_x_idx_0 > 3.3121686421112381E-170) {
      controlAerobi_B.Zgain_a = 1.0;
      controlAerobi_B.r_x_idx_2 = controlAerobi_B.r_x_idx_0;
    } else {
      controlAerobi_B.t = controlAerobi_B.r_x_idx_0 / 3.3121686421112381E-170;
      controlAerobi_B.Zgain_a = controlAerobi_B.t * controlAerobi_B.t;
    }

    controlAerobi_B.r_x_idx_0 = fabs(controlAerobi_B.Switch[1]);
    if (controlAerobi_B.r_x_idx_0 > controlAerobi_B.r_x_idx_2) {
      controlAerobi_B.t = controlAerobi_B.r_x_idx_2 / controlAerobi_B.r_x_idx_0;
      controlAerobi_B.Zgain_a = controlAerobi_B.Zgain_a * controlAerobi_B.t *
        controlAerobi_B.t + 1.0;
      controlAerobi_B.r_x_idx_2 = controlAerobi_B.r_x_idx_0;
    } else {
      controlAerobi_B.t = controlAerobi_B.r_x_idx_0 / controlAerobi_B.r_x_idx_2;
      controlAerobi_B.Zgain_a += controlAerobi_B.t * controlAerobi_B.t;
    }

    controlAerobi_B.r_x_idx_0 = fabs(controlAerobi_B.Switch[2]);
    if (controlAerobi_B.r_x_idx_0 > controlAerobi_B.r_x_idx_2) {
      controlAerobi_B.t = controlAerobi_B.r_x_idx_2 / controlAerobi_B.r_x_idx_0;
      controlAerobi_B.Zgain_a = controlAerobi_B.Zgain_a * controlAerobi_B.t *
        controlAerobi_B.t + 1.0;
      controlAerobi_B.r_x_idx_2 = controlAerobi_B.r_x_idx_0;
    } else {
      controlAerobi_B.t = controlAerobi_B.r_x_idx_0 / controlAerobi_B.r_x_idx_2;
      controlAerobi_B.Zgain_a += controlAerobi_B.t * controlAerobi_B.t;
    }

    // DiscreteFir: '<S104>/Hlp' incorporates:
    //   Lookup_n-D: '<S70>/1-D Lookup Table'
    //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
    //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

    o = 3;
    controlAerobi_B.Zgain_a = controlAerobi_B.r_x_idx_2 * sqrt
      (controlAerobi_B.Zgain_a);

    // '<S180>:1:16'
    controlAerobi_DWork.acc_[0] = controlAerobi_B.Switch[0] /
      controlAerobi_B.Zgain_a * 0.2 + controlAerobi_DWork.acc_[0] * 0.8;
    controlAerobi_DWork.acc_[1] = controlAerobi_B.Switch[1] /
      controlAerobi_B.Zgain_a * 0.2 + controlAerobi_DWork.acc_[1] * 0.8;
    controlAerobi_DWork.acc_[2] = controlAerobi_B.Switch[2] /
      controlAerobi_B.Zgain_a * 0.2 + controlAerobi_DWork.acc_[2] * 0.8;

    // '<S180>:1:17'
    controlAerobi_DWork.time += 0.0025;
    if (controlAerobi_DWork.time > 0.05) {
      // '<S180>:1:18'
      // '<S180>:1:19'
      controlAerobi_DWork.time = 0.0;
      i = (int32_T)controlAerobi_DWork.index - 1;
      distorsioned = i * 3;
      if ((controlAerobi_DWork.buffer[distorsioned] != controlAerobi_B.b_exp_b) ||
          (controlAerobi_DWork.buffer[distorsioned + 1] != controlAerobi_B.sinc))
      {
        // '<S180>:1:20'
        // '<S180>:1:21'
        controlAerobi_DWork.buffer[3 * i] = controlAerobi_B.b_exp_b;
        controlAerobi_DWork.buffer[1 + 3 * i] = controlAerobi_B.sinc;
        controlAerobi_DWork.buffer[2 + 3 * i] = controlAerobi_U.I_sf11c._z;

        // '<S180>:1:22'
        controlAerobi_DWork.counter[i] = 1.0;
      } else {
        // '<S180>:1:25'
        controlAerobi_DWork.buffer[3 * i] = controlAerobi_B.b_exp_b;
        controlAerobi_DWork.buffer[1 + 3 * i] = controlAerobi_B.sinc;
        controlAerobi_DWork.buffer[2 + 3 * i] = controlAerobi_U.I_sf11c._z;

        // '<S180>:1:26'
        controlAerobi_DWork.counter[i] = 0.0;
      }

      if (controlAerobi_DWork.index == 20.0) {
        // '<S180>:1:28'
        // '<S180>:1:29'
        controlAerobi_DWork.index = 1.0;
      } else {
        // '<S180>:1:31'
        controlAerobi_DWork.index++;
      }
    }
  }

  // '<S180>:1:37'
  controlAerobi_B.r_x_idx_2 = controlAerobi_DWork.counter[0];
  for (o = 0; o < 19; o++) {
    controlAerobi_B.r_x_idx_2 += controlAerobi_DWork.counter[o + 1];
  }

  if (controlAerobi_B.r_x_idx_2 > 20.0) {
    // '<S180>:1:38'
    // '<S180>:1:39'
    controlAerobi_B.r_x_idx_2 = 20.0;
  }

  if (rtIsNaN(controlAerobi_B.b_exp_b) || rtIsNaN(controlAerobi_B.sinc) ||
      rtIsInf(controlAerobi_B.b_exp_b) || rtIsInf(controlAerobi_B.sinc) || (fabs
       (controlAerobi_B.b_exp_b) > 50.0) || (fabs(controlAerobi_B.sinc) > 50.0))
  {
    // '<S180>:1:41'
    if (controlAerobi_DWork.index <= 1.0) {
      // '<S180>:1:42'
      // '<S180>:1:43'
      controlAerobi_B.b_exp_b = controlAerobi_DWork.buffer[57];

      // '<S180>:1:44'
      controlAerobi_B.sinc = controlAerobi_DWork.buffer[58];
    } else {
      // '<S180>:1:46'
      i = ((int32_T)(controlAerobi_DWork.index - 1.0) - 1) * 3;
      controlAerobi_B.b_exp_b = controlAerobi_DWork.buffer[i];

      // '<S180>:1:47'
      controlAerobi_B.sinc = controlAerobi_DWork.buffer[i + 1];
    }

    // '<S180>:1:49'
    controlAerobi_B.r_x_idx_1 = controlAerobi_U.I_sf11c._z;
  } else {
    if (controlAerobi_U.I_sf11c._z < 0.35) {
      // '<S180>:1:51'
      // '<S180>:1:52'
      controlAerobi_B.r_x_idx_1 = 0.35;
    } else {
      // '<S180>:1:54'
      controlAerobi_B.r_x_idx_1 = controlAerobi_U.I_sf11c._z;
    }

    // '<S180>:1:56'
    // '<S180>:1:57'
  }

  // Product: '<S157>/Divide2' incorporates:
  //   Constant: '<S157>/Constant4'
  //   Constant: '<S157>/Constant5'
  //   DataTypeConversion: '<S157>/Data Type Conversion'
  //   Gain: '<S157>/Gain2'
  //   Inport: '<Root>/I_RCinput'
  //   Sum: '<S157>/Add2'

  // '<S180>:1:59'
  controlAerobi_B.DiscreteTimeIntegrator_b = (controlAerobi_P.Gain2_Gain *
    (real_T)controlAerobi_U.I_RCinput._channel3 -
    controlAerobi_P.Constant4_Value) * controlAerobi_P.Constant5_Value;

  // MATLAB Function: '<S175>/EKF_dXYZ' incorporates:
  //   Inport: '<Root>/I_totalStation'
  //   MATLAB Function: '<S10>/trajectory_tracking'
  //   MATLAB Function: '<S172>/Liner Fixed-gain Filter1'
  //   MATLAB Function: '<S175>/EKF2_XYZ'
  //   MATLAB Function: '<S175>/Liner Fixed-gain Filter'
  //   MATLAB Function: '<S175>/buffer'
  //   MATLAB Function: '<S52>/Create RollPitchdesired'
  //   MATLAB Function: '<S9>/attitude_geometric_control'
  //   Product: '<S72>/Product'

  // MATLAB Function 'Sensors/position/EKF_total_Station_Lidar/filter/EKF_dXYZ': '<S178>:1' 
  // '<S178>:1:60'
  // '<S178>:1:37'
  // '<S178>:1:35'
  // '<S178>:1:33'
  // '<S178>:1:51'
  // '<S178>:1:50'
  // '<S178>:1:3'
  // '<S178>:1:6'
  controlAerobi_B.TSamp_hv = cos(controlAerobi_B.Gain_po[1]);
  controlAerobi_B.Sum_f = sin(controlAerobi_B.Gain_po[0]);
  controlAerobi_B.Abs_k = controlAerobi_B.Sum_f * controlAerobi_B.TSamp_hv;
  controlAerobi_B.b_x_idx_1 = -controlAerobi_DWork.acc_[0] -
    controlAerobi_B.Abs_k;
  controlAerobi_B.ubx_tmp = cos(controlAerobi_B.Gain_po[2]);
  controlAerobi_B.r_x_idx_0 = sin(controlAerobi_B.Gain_po[1]);
  controlAerobi_B.x_I_idx_1 = controlAerobi_DWork.acc_[1] -
    controlAerobi_B.r_x_idx_0;
  controlAerobi_B.ubx_tmp_a = sin(controlAerobi_B.Gain_po[2]);
  controlAerobi_B.b_x_idx_2 = controlAerobi_B.x_I_idx_1 *
    controlAerobi_B.ubx_tmp - controlAerobi_B.b_x_idx_1 *
    controlAerobi_B.ubx_tmp_a;
  controlAerobi_B.rtb_Switch_Pos_idx_1 = controlAerobi_B.b_x_idx_1 *
    controlAerobi_B.ubx_tmp + controlAerobi_B.x_I_idx_1 *
    controlAerobi_B.ubx_tmp_a;
  controlAerobi_B.TSamp_iz = cos(controlAerobi_B.Gain_po[0]);
  controlAerobi_B.ubx_tmp_j = controlAerobi_B.TSamp_iz *
    controlAerobi_B.TSamp_hv;
  controlAerobi_B.ubx_d[2] = controlAerobi_DWork.acc_[2] -
    controlAerobi_B.ubx_tmp_j;
  if ((!controlAerobi_DWork.dx_k_not_empty) ||
      (!controlAerobi_DWork.dP_k_not_empty) ||
      (!controlAerobi_DWork.time_not_empty_b) ||
      (!controlAerobi_DWork.timeTS0_not_empty) ||
      (!controlAerobi_DWork.queue_dx_not_empty) ||
      (!controlAerobi_DWork.queue_dP_not_empty) ||
      (!controlAerobi_DWork.index_not_empty_d) ||
      (!controlAerobi_DWork.timefreq_not_empty) ||
      (!controlAerobi_DWork.Ndata_not_empty)) {
    // '<S178>:1:11'
    // '<S178>:1:13'
    controlAerobi_DWork.dx_k[0] = 0.0;
    controlAerobi_DWork.dx_k[1] = 0.0;
    controlAerobi_DWork.dx_k[2] = 0.0;
    controlAerobi_DWork.dx_k[3] = 0.0;
    controlAerobi_DWork.dx_k[4] = controlAerobi_B.r_x_idx_1;
    controlAerobi_DWork.dx_k[5] = 0.0;
    controlAerobi_DWork.dx_k_not_empty = true;

    // '<S178>:1:14'
    memset(&controlAerobi_DWork.dP_k[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      i = o + 6 * o;
      controlAerobi_DWork.dP_k[i] = 1.0;
    }

    controlAerobi_DWork.dP_k_not_empty = true;

    // '<S178>:1:15'
    controlAerobi_DWork.queue_dx_not_empty = true;

    // '<S178>:1:16'
    controlAerobi_DWork.queue_dP_not_empty = true;

    // '<S178>:1:18'
    controlAerobi_DWork.time_a = 0.0;
    controlAerobi_DWork.time_not_empty_b = true;

    // '<S178>:1:19'
    controlAerobi_DWork.timeTS0 = controlAerobi_U.I_totalStation._time;
    controlAerobi_DWork.timeTS0_not_empty = true;

    // '<S178>:1:20'
    controlAerobi_DWork.index_j = 0.0;
    controlAerobi_DWork.index_not_empty_d = true;

    // '<S178>:1:21'
    controlAerobi_DWork.timefreq_not_empty = true;

    // '<S178>:1:22'
    controlAerobi_DWork.Ndata_not_empty = true;
  } else {
    if (controlAerobi_U.I_totalStation._time != 0.0) {
      // '<S178>:1:26'
      if (controlAerobi_DWork.timeTS0 != controlAerobi_U.I_totalStation._time) {
        // '<S178>:1:27'
        // '<S178>:1:28'
        controlAerobi_B.absxk = controlAerobi_DWork.time_a;

        // '<S178>:1:29'
        controlAerobi_DWork.time_a = 0.0;

        // '<S178>:1:30'
        controlAerobi_DWork.timeTS0 = controlAerobi_U.I_totalStation._time;

        // '<S178>:1:32'
        controlAerobi_B.dF[0] = 1.0;
        controlAerobi_B.dF[6] = controlAerobi_B.absxk;
        controlAerobi_B.dF[12] = 0.0;
        controlAerobi_B.dF[18] = 0.0;
        controlAerobi_B.dF[24] = 0.0;
        controlAerobi_B.dF[30] = 0.0;
        controlAerobi_B.dF[2] = 0.0;
        controlAerobi_B.dF[8] = 0.0;
        controlAerobi_B.dF[14] = 1.0;
        controlAerobi_B.dF[20] = controlAerobi_B.absxk;
        controlAerobi_B.dF[26] = 0.0;
        controlAerobi_B.dF[32] = 0.0;
        controlAerobi_B.dF[4] = 0.0;
        controlAerobi_B.dF[10] = 0.0;
        controlAerobi_B.dF[16] = 0.0;
        controlAerobi_B.dF[22] = 0.0;
        controlAerobi_B.dF[28] = 1.0;
        controlAerobi_B.dF[34] = controlAerobi_B.absxk;
        for (i = 0; i < 6; i++) {
          controlAerobi_B.dF[1 + 6 * i] = b_0[i];
          controlAerobi_B.dF[3 + 6 * i] = c_0[i];
          controlAerobi_B.dF[5 + 6 * i] = d_0[i];
        }

        // '<S178>:1:38'
        // '<S178>:1:44'
        // '<S178>:1:45'
        // '<S178>:1:46'
        controlAerobi_B.ub_[0] = controlAerobi_DWork.dx_k[0];
        controlAerobi_B.ub_[1] = controlAerobi_DWork.dx_k[2];
        controlAerobi_B.ub_[2] = controlAerobi_DWork.dx_k[4];

        // '<S178>:1:50'
        memset(&controlAerobi_B.dQ[0], 0, 36U * sizeof(real_T));
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dQ[r2 + 6 * r2] = e_0[r2];
        }

        // '<S178>:1:51'
        for (i = 0; i < 9; i++) {
          controlAerobi_B.R_[i] = 0.0;
        }

        controlAerobi_B.R_[0] = 0.001;
        controlAerobi_B.R_[4] = 0.001;
        controlAerobi_B.R_[8] = 0.001;

        // DiscreteFir: '<S104>/Hlp' incorporates:
        //   Lookup_n-D: '<S70>/1-D Lookup Table'
        //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
        //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

        o = 3;

        // '<S178>:1:55'
        controlAerobi_B.Gain7 = controlAerobi_B.absxk * controlAerobi_B.absxk *
          0.5;
        controlAerobi_B.dK_k[0] = controlAerobi_B.Gain7;
        controlAerobi_B.dK_k[6] = 0.0;
        controlAerobi_B.dK_k[12] = 0.0;
        controlAerobi_B.dK_k[1] = controlAerobi_B.absxk;
        controlAerobi_B.dK_k[7] = 0.0;
        controlAerobi_B.dK_k[13] = 0.0;
        controlAerobi_B.dK_k[2] = 0.0;
        controlAerobi_B.dK_k[8] = controlAerobi_B.Gain7;
        controlAerobi_B.dK_k[14] = 0.0;
        controlAerobi_B.dK_k[3] = 0.0;
        controlAerobi_B.dK_k[9] = controlAerobi_B.absxk;
        controlAerobi_B.dK_k[15] = 0.0;
        controlAerobi_B.dK_k[4] = 0.0;
        controlAerobi_B.dK_k[10] = 0.0;
        controlAerobi_B.dK_k[16] = controlAerobi_B.Gain7;
        controlAerobi_B.dK_k[5] = 0.0;
        controlAerobi_B.dK_k[11] = 0.0;
        controlAerobi_B.dK_k[17] = controlAerobi_B.absxk;
        for (i = 0; i < 6; i++) {
          controlAerobi_B.rtb_Gain_po_g[i] = 0.0;
          for (distorsioned = 0; distorsioned < 6; distorsioned++) {
            controlAerobi_B.rtb_Gain_po_g[i] += controlAerobi_B.dF[6 *
              distorsioned + i] * controlAerobi_DWork.dx_k[distorsioned];
          }

          controlAerobi_B.a[i] = controlAerobi_B.dK_k[i + 12] *
            controlAerobi_B.ubx_d[2] + (controlAerobi_B.dK_k[i + 6] *
            controlAerobi_B.rtb_Switch_Pos_idx_1 + controlAerobi_B.dK_k[i] *
            controlAerobi_B.b_x_idx_2);
        }

        // '<S178>:1:57'
        for (i = 0; i < 6; i++) {
          controlAerobi_DWork.dx_k[i] = controlAerobi_B.rtb_Gain_po_g[i] +
            controlAerobi_B.a[i];
          for (distorsioned = 0; distorsioned < 6; distorsioned++) {
            r3 = i + 6 * distorsioned;
            controlAerobi_B.dF_k[r3] = 0.0;
            for (r2 = 0; r2 < 6; r2++) {
              controlAerobi_B.dF_k[r3] = controlAerobi_B.dF[6 * r2 + i] *
                controlAerobi_DWork.dP_k[6 * distorsioned + r2] +
                controlAerobi_B.dF_k[6 * distorsioned + i];
            }
          }
        }

        // '<S178>:1:60'
        for (i = 0; i < 6; i++) {
          for (distorsioned = 0; distorsioned < 6; distorsioned++) {
            controlAerobi_B.Gain7 = 0.0;
            for (r2 = 0; r2 < 6; r2++) {
              controlAerobi_B.Gain7 += controlAerobi_B.dF_k[6 * r2 + i] *
                controlAerobi_B.dF[6 * r2 + distorsioned];
            }

            controlAerobi_DWork.dP_k[i + 6 * distorsioned] = controlAerobi_B.dQ
              [6 * distorsioned + i] + controlAerobi_B.Gain7;
          }

          for (distorsioned = 0; distorsioned < 3; distorsioned++) {
            o = i + 6 * distorsioned;
            controlAerobi_B.y[o] = 0.0;
            for (r2 = 0; r2 < 6; r2++) {
              controlAerobi_B.y[o] = controlAerobi_DWork.dP_k[6 * r2 + i] *
                (real_T)b_b_0[6 * distorsioned + r2] + controlAerobi_B.y[6 *
                distorsioned + i];
            }
          }
        }

        for (i = 0; i < 3; i++) {
          for (distorsioned = 0; distorsioned < 6; distorsioned++) {
            o = i + 3 * distorsioned;
            controlAerobi_B.dK_k[o] = 0.0;
            for (r2 = 0; r2 < 6; r2++) {
              controlAerobi_B.dK_k[o] = (real_T)a[3 * r2 + i] *
                controlAerobi_DWork.dP_k[6 * distorsioned + r2] +
                controlAerobi_B.dK_k[3 * distorsioned + i];
            }
          }

          for (distorsioned = 0; distorsioned < 3; distorsioned++) {
            controlAerobi_B.Gain7 = 0.0;
            for (r2 = 0; r2 < 6; r2++) {
              controlAerobi_B.Gain7 += controlAerobi_B.dK_k[3 * r2 + i] *
                (real_T)b_b_0[6 * distorsioned + r2];
            }

            controlAerobi_B.P_ui[i + 3 * distorsioned] = controlAerobi_B.R_[3 *
              distorsioned + i] + controlAerobi_B.Gain7;
          }
        }

        distorsioned = 0;
        r2 = 1;
        r3 = 2;
        controlAerobi_B.Product1_a1 = fabs(controlAerobi_B.P_ui[0]);
        controlAerobi_B.Product1_ew = fabs(controlAerobi_B.P_ui[1]);
        if (controlAerobi_B.Product1_ew > controlAerobi_B.Product1_a1) {
          controlAerobi_B.Product1_a1 = controlAerobi_B.Product1_ew;
          distorsioned = 1;
          r2 = 0;
        }

        if (fabs(controlAerobi_B.P_ui[2]) > controlAerobi_B.Product1_a1) {
          distorsioned = 2;
          r2 = 1;
          r3 = 0;
        }

        controlAerobi_B.P_ui[r2] /= controlAerobi_B.P_ui[distorsioned];
        controlAerobi_B.P_ui[r3] /= controlAerobi_B.P_ui[distorsioned];
        controlAerobi_B.P_ui[3 + r2] -= controlAerobi_B.P_ui[3 + distorsioned] *
          controlAerobi_B.P_ui[r2];
        controlAerobi_B.P_ui[3 + r3] -= controlAerobi_B.P_ui[3 + distorsioned] *
          controlAerobi_B.P_ui[r3];
        controlAerobi_B.P_ui[6 + r2] -= controlAerobi_B.P_ui[6 + distorsioned] *
          controlAerobi_B.P_ui[r2];
        controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[6 + distorsioned] *
          controlAerobi_B.P_ui[r3];
        if (fabs(controlAerobi_B.P_ui[3 + r3]) > fabs(controlAerobi_B.P_ui[3 +
             r2])) {
          o = r2 + 1;
          r2 = r3;
          r3 = o - 1;
        }

        controlAerobi_B.P_ui[3 + r3] /= controlAerobi_B.P_ui[3 + r2];
        controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[3 + r3] *
          controlAerobi_B.P_ui[6 + r2];
        for (o = 0; o < 6; o++) {
          i = o + 6 * distorsioned;
          controlAerobi_B.dK_k[i] = controlAerobi_B.y[o] /
            controlAerobi_B.P_ui[distorsioned];
          i = o + 6 * r2;
          controlAerobi_B.dK_k[i] = controlAerobi_B.y[6 + o] -
            controlAerobi_B.dK_k[6 * distorsioned + o] * controlAerobi_B.P_ui[3
            + distorsioned];
          i = o + 6 * r3;
          controlAerobi_B.dK_k[i] = controlAerobi_B.y[12 + o] -
            controlAerobi_B.dK_k[6 * distorsioned + o] * controlAerobi_B.P_ui[6
            + distorsioned];
          i = o + 6 * r2;
          controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] /
            controlAerobi_B.P_ui[3 + r2];
          i = o + 6 * r3;
          controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] -
            controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[6 + r2];
          i = o + 6 * r3;
          controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] /
            controlAerobi_B.P_ui[6 + r3];
          i = o + 6 * r2;
          controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] -
            controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[3 + r3];
          i = o + 6 * distorsioned;
          controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
            controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[r3];
          i = o + 6 * distorsioned;
          controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
            controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[r2];
        }

        // '<S178>:1:62'
        // '<S178>:1:64'
        controlAerobi_B.Zgain_a = controlAerobi_B.b_exp_b - controlAerobi_B.ub_
          [0];
        controlAerobi_B.absxk = controlAerobi_B.sinc - controlAerobi_B.ub_[1];
        controlAerobi_B.Abs_a = controlAerobi_B.r_x_idx_1 - controlAerobi_B.ub_
          [2];
        for (i = 0; i < 6; i++) {
          controlAerobi_DWork.dx_k[i] += (controlAerobi_B.dK_k[i + 6] *
            controlAerobi_B.absxk + controlAerobi_B.dK_k[i] *
            controlAerobi_B.Zgain_a) + controlAerobi_B.dK_k[i + 12] *
            controlAerobi_B.Abs_a;
        }

        // '<S178>:1:66'
        memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
        for (o = 0; o < 6; o++) {
          r3 = o + 6 * o;
          controlAerobi_B.dF[r3] = 1.0;
        }

        for (i = 0; i < 6; i++) {
          for (distorsioned = 0; distorsioned < 6; distorsioned++) {
            controlAerobi_B.dF_k[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
              distorsioned + i] - (((real_T)a[3 * distorsioned + 1] *
              controlAerobi_B.dK_k[i + 6] + (real_T)a[3 * distorsioned] *
              controlAerobi_B.dK_k[i]) + (real_T)a[3 * distorsioned + 2] *
              controlAerobi_B.dK_k[i + 12]);
          }

          for (distorsioned = 0; distorsioned < 6; distorsioned++) {
            r3 = i + 6 * distorsioned;
            controlAerobi_B.dQ[r3] = 0.0;
            for (r2 = 0; r2 < 6; r2++) {
              controlAerobi_B.dQ[r3] = controlAerobi_B.dF_k[6 * r2 + i] *
                controlAerobi_DWork.dP_k[6 * distorsioned + r2] +
                controlAerobi_B.dQ[6 * distorsioned + i];
            }
          }
        }

        for (i = 0; i < 6; i++) {
          for (distorsioned = 0; distorsioned < 6; distorsioned++) {
            controlAerobi_DWork.dP_k[distorsioned + 6 * i] = controlAerobi_B.dQ
              [6 * i + distorsioned];
          }
        }

        // '<S178>:1:68'
        controlAerobi_DWork.index_j++;
        if (controlAerobi_DWork.index_j > 10.0) {
          // '<S178>:1:70'
          // '<S178>:1:71'
          // '<S178>:1:72'
          // '<S178>:1:73'
          controlAerobi_DWork.index_j = 1.0;
        } else {
          // '<S178>:1:75'
          // '<S178>:1:76'
        }
      } else {
        // '<S178>:1:80'
        controlAerobi_DWork.time_a += 0.0025;
      }
    }
  }

  // RateLimiter: '<S175>/Rate Limiter' incorporates:
  //   MATLAB Function: '<S175>/EKF_dXYZ'

  // '<S178>:1:85'
  // '<S178>:1:86'
  controlAerobi_B.t = controlAerobi_DWork.dx_k[1] - controlAerobi_DWork.PrevY_o;
  if (controlAerobi_B.t > controlAerobi_P.RateLimiter_RisingLim_g) {
    controlAerobi_B.absxk = controlAerobi_DWork.PrevY_o +
      controlAerobi_P.RateLimiter_RisingLim_g;
  } else if (controlAerobi_B.t < controlAerobi_P.RateLimiter_FallingLim_k) {
    controlAerobi_B.absxk = controlAerobi_DWork.PrevY_o +
      controlAerobi_P.RateLimiter_FallingLim_k;
  } else {
    controlAerobi_B.absxk = controlAerobi_DWork.dx_k[1];
  }

  controlAerobi_DWork.PrevY_o = controlAerobi_B.absxk;

  // End of RateLimiter: '<S175>/Rate Limiter'

  // RateLimiter: '<S175>/Rate Limiter1' incorporates:
  //   MATLAB Function: '<S175>/EKF_dXYZ'

  controlAerobi_B.t = controlAerobi_DWork.dx_k[3] - controlAerobi_DWork.PrevY_p;
  if (controlAerobi_B.t > controlAerobi_P.RateLimiter1_RisingLim_i) {
    controlAerobi_B.t = controlAerobi_DWork.PrevY_p +
      controlAerobi_P.RateLimiter1_RisingLim_i;
  } else if (controlAerobi_B.t < controlAerobi_P.RateLimiter1_FallingLim_o) {
    controlAerobi_B.t = controlAerobi_DWork.PrevY_p +
      controlAerobi_P.RateLimiter1_FallingLim_o;
  } else {
    controlAerobi_B.t = controlAerobi_DWork.dx_k[3];
  }

  controlAerobi_DWork.PrevY_p = controlAerobi_B.t;

  // End of RateLimiter: '<S175>/Rate Limiter1'

  // MATLAB Function: '<S175>/Liner Fixed-gain Filter' incorporates:
  //   MATLAB Function: '<S175>/buffer'

  controlAerobi_B.Zgain_a = controlAerobi_B.DiscreteTimeIntegrator_b;

  // MATLAB Function 'Sensors/position/EKF_total_Station_Lidar/filter/Liner Fixed-gain Filter': '<S179>:1' 
  // '<S179>:1:34'
  // '<S179>:1:33'
  // '<S179>:1:40'
  // '<S179>:1:38'
  // '<S179>:1:36'
  // '<S179>:1:5'
  // '<S179>:1:6'
  if ((!controlAerobi_DWork.x_k_not_empty_m) ||
      (!controlAerobi_DWork.P_k_not_empty_d)) {
    // '<S179>:1:8'
    // '<S179>:1:9'
    controlAerobi_DWork.x_k_a[0] = 0.0;
    controlAerobi_DWork.x_k_a[1] = 0.0;
    controlAerobi_DWork.x_k_not_empty_m = true;

    // '<S179>:1:10'
    controlAerobi_DWork.P_k_n[0] = 1.0;
    controlAerobi_DWork.P_k_n[1] = 0.0;
    controlAerobi_DWork.P_k_n[2] = 0.0;
    controlAerobi_DWork.P_k_n[3] = 1.0;
    controlAerobi_DWork.P_k_not_empty_d = true;
  } else {
    if (controlAerobi_B.DiscreteTimeIntegrator_b < 40.0) {
      // '<S179>:1:13'
      // '<S179>:1:14'
      controlAerobi_B.Zgain_a = 40.0;
    } else {
      if (controlAerobi_B.DiscreteTimeIntegrator_b > 120.0) {
        // '<S179>:1:15'
        // '<S179>:1:16'
        controlAerobi_B.Zgain_a = 120.0;
      }
    }

    // '<S179>:1:18'
    controlAerobi_B.Zgain_a = 62.5 / controlAerobi_B.Zgain_a;

    // '<S179>:1:21'
    // '<S179>:1:26'
    // '<S179>:1:28'
    controlAerobi_B.Zgain_a = 0.87 * controlAerobi_B.Zgain_a / 2.5;
    controlAerobi_B.F_d[0] = controlAerobi_B.Zgain_a;
    controlAerobi_B.F_d[2] = 0.0;
    controlAerobi_B.F_d[1] = 0.0;
    controlAerobi_B.F_d[3] = controlAerobi_B.Zgain_a;

    // '<S179>:1:31'
    controlAerobi_B.H[0] = controlAerobi_B.Zgain_a;
    controlAerobi_B.H[4] = 0.0;
    controlAerobi_B.H[1] = 0.0;
    controlAerobi_B.H[5] = controlAerobi_B.Zgain_a;
    controlAerobi_B.H[2] = 0.0025;
    controlAerobi_B.H[3] = 0.0;
    controlAerobi_B.H[6] = 0.0;
    controlAerobi_B.H[7] = 0.0025;

    // '<S179>:1:36'
    Q[1] = 0;
    Q[2] = 0;
    Q[0] = 1;
    Q[3] = 1;
    if (controlAerobi_B.r_x_idx_2 >= 20.0) {
      // '<S179>:1:37'
      // '<S179>:1:38'
      memset(&controlAerobi_B.R_f[0], 0, sizeof(real_T) << 4U);
      controlAerobi_B.R_f[0] = 0.5;
      controlAerobi_B.R_f[5] = 0.5;
      controlAerobi_B.R_f[10] = 0.004;
      controlAerobi_B.R_f[15] = 0.004;

      // DiscreteFir: '<S104>/Hlp' incorporates:
      //   Lookup_n-D: '<S70>/1-D Lookup Table'
      //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
      //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

      o = 4;
    } else {
      // '<S179>:1:40'
      memset(&controlAerobi_B.R_f[0], 0, sizeof(real_T) << 4U);
      controlAerobi_B.R_f[0] = 0.01;
      controlAerobi_B.R_f[5] = 0.01;
      controlAerobi_B.R_f[10] = 100000.0;
      controlAerobi_B.R_f[15] = 100000.0;

      // DiscreteFir: '<S104>/Hlp' incorporates:
      //   Lookup_n-D: '<S70>/1-D Lookup Table'
      //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
      //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

      o = 4;
    }

    // '<S179>:1:43'
    // '<S179>:1:44'
    // '<S179>:1:47'
    controlAerobi_B.y_k_idx_0 = controlAerobi_DWork.x_k_a[0];
    controlAerobi_B.F_b[0] = controlAerobi_B.Zgain_a *
      controlAerobi_DWork.x_k_a[0] + 0.0 * controlAerobi_DWork.x_k_a[1];
    controlAerobi_B.y_k_idx_1 = controlAerobi_DWork.x_k_a[1];
    controlAerobi_B.F_b[1] = 0.0 * controlAerobi_DWork.x_k_a[0];
    controlAerobi_B.F_b[1] += controlAerobi_B.Zgain_a *
      controlAerobi_DWork.x_k_a[1];

    // '<S179>:1:49'
    for (i = 0; i < 2; i++) {
      controlAerobi_DWork.x_k_a[i] = controlAerobi_B.F_b[i];
      controlAerobi_B.q_k_d[i] = 0.0;
      controlAerobi_B.q_k_d[i] += controlAerobi_B.F_d[i] *
        controlAerobi_DWork.P_k_n[0];
      controlAerobi_B.q_k_d[i] += controlAerobi_B.F_d[i + 2] *
        controlAerobi_DWork.P_k_n[1];
      controlAerobi_B.q_k_d[i + 2] = 0.0;
      controlAerobi_B.q_k_d[i + 2] += controlAerobi_B.F_d[i] *
        controlAerobi_DWork.P_k_n[2];
      controlAerobi_B.q_k_d[i + 2] += controlAerobi_B.F_d[i + 2] *
        controlAerobi_DWork.P_k_n[3];
    }

    // '<S179>:1:52'
    for (i = 0; i < 2; i++) {
      controlAerobi_DWork.P_k_n[i] = (controlAerobi_B.q_k_d[i + 2] * 0.0 +
        controlAerobi_B.q_k_d[i] * controlAerobi_B.Zgain_a) + (real_T)Q[i];
      controlAerobi_DWork.P_k_n[i + 2] = (controlAerobi_B.q_k_d[i + 2] *
        controlAerobi_B.Zgain_a + controlAerobi_B.q_k_d[i] * 0.0) + (real_T)Q[i
        + 2];
      for (distorsioned = 0; distorsioned < 4; distorsioned++) {
        controlAerobi_B.K_k_j[i + (distorsioned << 1)] = 0.0;
        controlAerobi_B.K_k_j[i + (distorsioned << 1)] +=
          controlAerobi_DWork.P_k_n[i] * controlAerobi_B.H[distorsioned];
        controlAerobi_B.K_k_j[i + (distorsioned << 1)] +=
          controlAerobi_DWork.P_k_n[i + 2] * controlAerobi_B.H[distorsioned + 4];
      }
    }

    for (i = 0; i < 4; i++) {
      controlAerobi_B.H_d[i] = 0.0;
      controlAerobi_B.H_d[i] += controlAerobi_B.H[i] *
        controlAerobi_DWork.P_k_n[0];
      controlAerobi_B.H_d[i] += controlAerobi_B.H[i + 4] *
        controlAerobi_DWork.P_k_n[1];
      controlAerobi_B.H_d[i + 4] = 0.0;
      controlAerobi_B.H_d[i + 4] += controlAerobi_B.H[i] *
        controlAerobi_DWork.P_k_n[2];
      controlAerobi_B.H_d[i + 4] += controlAerobi_B.H[i + 4] *
        controlAerobi_DWork.P_k_n[3];
      for (distorsioned = 0; distorsioned < 4; distorsioned++) {
        controlAerobi_B.rtb_Sum_g2[i + (distorsioned << 2)] =
          (controlAerobi_B.H_d[i + 4] * controlAerobi_B.H[distorsioned + 4] +
           controlAerobi_B.H_d[i] * controlAerobi_B.H[distorsioned]) +
          controlAerobi_B.R_f[(distorsioned << 2) + i];
      }
    }

    controlAerobi_mrdivide_oxNR4jke(controlAerobi_B.K_k_j,
      controlAerobi_B.rtb_Sum_g2);

    // '<S179>:1:54'
    // '<S179>:1:56'
    controlAerobi_B.q_k_d[0] = controlAerobi_B.x_I_idx_1;
    controlAerobi_B.q_k_d[1] = controlAerobi_B.b_x_idx_1;
    controlAerobi_B.q_k_d[2] = controlAerobi_B.ubx_tmp * controlAerobi_B.absxk +
      -controlAerobi_B.ubx_tmp_a * controlAerobi_B.t;
    controlAerobi_B.q_k_d[3] = controlAerobi_B.ubx_tmp_a * controlAerobi_B.absxk
      + controlAerobi_B.ubx_tmp * controlAerobi_B.t;
    for (i = 0; i < 4; i++) {
      controlAerobi_B.ubx[i] = controlAerobi_B.q_k_d[i] - (controlAerobi_B.H[i +
        4] * controlAerobi_B.y_k_idx_1 + controlAerobi_B.H[i] *
        controlAerobi_B.y_k_idx_0);
    }

    for (i = 0; i < 2; i++) {
      controlAerobi_DWork.x_k_a[i] += ((controlAerobi_B.K_k_j[i + 2] *
        controlAerobi_B.ubx[1] + controlAerobi_B.K_k_j[i] * controlAerobi_B.ubx
        [0]) + controlAerobi_B.K_k_j[i + 4] * controlAerobi_B.ubx[2]) +
        controlAerobi_B.K_k_j[i + 6] * controlAerobi_B.ubx[3];
    }

    // '<S179>:1:58'
    controlAerobi_B.F_d[1] = 0.0;
    controlAerobi_B.F_d[2] = 0.0;
    controlAerobi_B.F_d[0] = 1.0;
    controlAerobi_B.F_d[3] = 1.0;

    // DiscreteFir: '<S104>/Hlp' incorporates:
    //   Lookup_n-D: '<S70>/1-D Lookup Table'
    //   MATLAB Function: '<S175>/buffer'
    //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
    //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

    o = 2;
    for (i = 0; i < 2; i++) {
      for (distorsioned = 0; distorsioned < 2; distorsioned++) {
        controlAerobi_B.q_k_d[i + (distorsioned << 1)] = controlAerobi_B.F_d
          [(distorsioned << 1) + i] - (((controlAerobi_B.H[(distorsioned << 2) +
          1] * controlAerobi_B.K_k_j[i + 2] + controlAerobi_B.H[distorsioned <<
          2] * controlAerobi_B.K_k_j[i]) + controlAerobi_B.H[(distorsioned << 2)
          + 2] * controlAerobi_B.K_k_j[i + 4]) + controlAerobi_B.H[(distorsioned
          << 2) + 3] * controlAerobi_B.K_k_j[i + 6]);
      }

      controlAerobi_B.ubx[i] = 0.0;
      controlAerobi_B.ubx[i] += controlAerobi_B.q_k_d[i] *
        controlAerobi_DWork.P_k_n[0];
      controlAerobi_B.ubx[i] += controlAerobi_B.q_k_d[i + 2] *
        controlAerobi_DWork.P_k_n[1];
      controlAerobi_B.ubx[i + 2] = 0.0;
      controlAerobi_B.ubx[i + 2] += controlAerobi_B.q_k_d[i] *
        controlAerobi_DWork.P_k_n[2];
      controlAerobi_B.ubx[i + 2] += controlAerobi_B.q_k_d[i + 2] *
        controlAerobi_DWork.P_k_n[3];
    }

    controlAerobi_DWork.P_k_n[0] = controlAerobi_B.ubx[0];
    controlAerobi_DWork.P_k_n[1] = controlAerobi_B.ubx[1];
    controlAerobi_DWork.P_k_n[2] = controlAerobi_B.ubx[2];
    controlAerobi_DWork.P_k_n[3] = controlAerobi_B.ubx[3];
  }

  // '<S179>:1:62'
  controlAerobi_B.b_x_idx_1 = controlAerobi_B.ubx_tmp *
    controlAerobi_DWork.x_k_a[0] + controlAerobi_B.ubx_tmp_a *
    controlAerobi_DWork.x_k_a[1];
  controlAerobi_B.Product1_a1 = -controlAerobi_B.ubx_tmp_a *
    controlAerobi_DWork.x_k_a[0] + controlAerobi_B.ubx_tmp *
    controlAerobi_DWork.x_k_a[1];

  // RateLimiter: '<S175>/Rate Limiter2' incorporates:
  //   MATLAB Function: '<S175>/Liner Fixed-gain Filter'

  // '<S179>:1:63'
  // '<S179>:1:64'
  controlAerobi_B.t = controlAerobi_B.b_x_idx_1 - controlAerobi_DWork.PrevY_d;
  if (controlAerobi_B.t > controlAerobi_P.RateLimiter2_RisingLim) {
    controlAerobi_B.Abs_a = controlAerobi_DWork.PrevY_d +
      controlAerobi_P.RateLimiter2_RisingLim;
  } else if (controlAerobi_B.t < controlAerobi_P.RateLimiter2_FallingLim) {
    controlAerobi_B.Abs_a = controlAerobi_DWork.PrevY_d +
      controlAerobi_P.RateLimiter2_FallingLim;
  } else {
    controlAerobi_B.Abs_a = controlAerobi_B.b_x_idx_1;
  }

  controlAerobi_DWork.PrevY_d = controlAerobi_B.Abs_a;

  // End of RateLimiter: '<S175>/Rate Limiter2'

  // RateLimiter: '<S175>/Rate Limiter3'
  controlAerobi_B.t = controlAerobi_B.Product1_a1 - controlAerobi_DWork.PrevY_n;
  if (controlAerobi_B.t > controlAerobi_P.RateLimiter3_RisingLim) {
    controlAerobi_B.Product1_a1 = controlAerobi_DWork.PrevY_n +
      controlAerobi_P.RateLimiter3_RisingLim;
  } else {
    if (controlAerobi_B.t < controlAerobi_P.RateLimiter3_FallingLim) {
      controlAerobi_B.Product1_a1 = controlAerobi_DWork.PrevY_n +
        controlAerobi_P.RateLimiter3_FallingLim;
    }
  }

  controlAerobi_DWork.PrevY_n = controlAerobi_B.Product1_a1;

  // End of RateLimiter: '<S175>/Rate Limiter3'

  // MATLAB Function: '<S175>/EKF2_XYZ'
  // MATLAB Function 'Sensors/position/EKF_total_Station_Lidar/filter/EKF2_XYZ': '<S177>:1' 
  // '<S177>:1:52'
  // '<S177>:1:49'
  // '<S177>:1:47'
  // '<S177>:1:4'
  controlAerobi_B.r_x_idx_2 = 3.3121686421112381E-170;
  controlAerobi_B.Gain7 = fabs(controlAerobi_B.Switch[0]);
  if (controlAerobi_B.Gain7 > 3.3121686421112381E-170) {
    controlAerobi_B.Zgain_a = 1.0;
    controlAerobi_B.r_x_idx_2 = controlAerobi_B.Gain7;
  } else {
    controlAerobi_B.t = controlAerobi_B.Gain7 / 3.3121686421112381E-170;
    controlAerobi_B.Zgain_a = controlAerobi_B.t * controlAerobi_B.t;
  }

  controlAerobi_B.Gain7 = fabs(controlAerobi_B.Switch[1]);
  if (controlAerobi_B.Gain7 > controlAerobi_B.r_x_idx_2) {
    controlAerobi_B.t = controlAerobi_B.r_x_idx_2 / controlAerobi_B.Gain7;
    controlAerobi_B.Zgain_a = controlAerobi_B.Zgain_a * controlAerobi_B.t *
      controlAerobi_B.t + 1.0;
    controlAerobi_B.r_x_idx_2 = controlAerobi_B.Gain7;
  } else {
    controlAerobi_B.t = controlAerobi_B.Gain7 / controlAerobi_B.r_x_idx_2;
    controlAerobi_B.Zgain_a += controlAerobi_B.t * controlAerobi_B.t;
  }

  controlAerobi_B.Gain7 = fabs(controlAerobi_B.Switch[2]);
  if (controlAerobi_B.Gain7 > controlAerobi_B.r_x_idx_2) {
    controlAerobi_B.t = controlAerobi_B.r_x_idx_2 / controlAerobi_B.Gain7;
    controlAerobi_B.Zgain_a = controlAerobi_B.Zgain_a * controlAerobi_B.t *
      controlAerobi_B.t + 1.0;
    controlAerobi_B.r_x_idx_2 = controlAerobi_B.Gain7;
  } else {
    controlAerobi_B.t = controlAerobi_B.Gain7 / controlAerobi_B.r_x_idx_2;
    controlAerobi_B.Zgain_a += controlAerobi_B.t * controlAerobi_B.t;
  }

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 3;

  // MATLAB Function: '<S175>/EKF2_XYZ' incorporates:
  //   Constant: '<S100>/KQ'
  //   Constant: '<S100>/KR'
  //   Constant: '<S100>/d_sf11'

  controlAerobi_B.Zgain_a = controlAerobi_B.r_x_idx_2 * sqrt
    (controlAerobi_B.Zgain_a);

  // '<S177>:1:5'
  controlAerobi_B.ubx_d[2] = controlAerobi_B.Switch[2] / controlAerobi_B.Zgain_a
    - controlAerobi_B.ubx_tmp_j;
  if ((!controlAerobi_DWork.x_k_not_empty_i) ||
      (!controlAerobi_DWork.P_k_not_empty_i) ||
      (!controlAerobi_DWork.x0_not_empty) || (!controlAerobi_DWork.y0_not_empty)
      || (!controlAerobi_DWork.z0_not_empty)) {
    // '<S177>:1:10'
    // '<S177>:1:11'
    controlAerobi_DWork.x_k_f[0] = 0.0;
    controlAerobi_DWork.x_k_f[1] = 0.0;
    controlAerobi_DWork.x_k_f[2] = 0.0;
    controlAerobi_DWork.x_k_f[3] = 0.0;
    controlAerobi_DWork.x_k_f[4] = controlAerobi_B.r_x_idx_1;
    controlAerobi_DWork.x_k_f[5] = 0.0;
    controlAerobi_DWork.x_k_not_empty_i = true;

    // '<S177>:1:12'
    memset(&controlAerobi_DWork.P_k_h[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      i = o + 6 * o;
      controlAerobi_DWork.P_k_h[i] = 1.0;
    }

    controlAerobi_DWork.P_k_not_empty_i = true;

    // '<S177>:1:13'
    controlAerobi_DWork.x0_not_empty = true;

    // '<S177>:1:14'
    controlAerobi_DWork.y0_not_empty = true;

    // '<S177>:1:15'
    controlAerobi_DWork.z0_not_empty = true;
  } else {
    // '<S177>:1:17'
    // '<S177>:1:19'
    // '<S177>:1:20'
    // '<S177>:1:21'
    // '<S177>:1:34'
    // '<S177>:1:35'
    // '<S177>:1:36'
    controlAerobi_B.y_k[0] = controlAerobi_DWork.x_k_f[0];
    controlAerobi_B.y_k[1] = controlAerobi_DWork.x_k_f[1];
    controlAerobi_B.y_k[2] = controlAerobi_DWork.x_k_f[2];
    controlAerobi_B.y_k[3] = controlAerobi_DWork.x_k_f[3];
    controlAerobi_B.y_k[4] = controlAerobi_DWork.x_k_f[4];

    // '<S177>:1:43'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (r2 = 0; r2 < 6; r2++) {
      controlAerobi_B.dF[r2 + 6 * r2] = controlAerobi_P.KQ_Value[r2];
    }

    // '<S177>:1:44'
    memset(&controlAerobi_B.R[0], 0, 25U * sizeof(real_T));
    for (o = 0; o < 5; o++) {
      controlAerobi_B.R[o + 5 * o] = controlAerobi_P.KR_Value[o];
    }

    // '<S177>:1:47'
    for (i = 0; i < 6; i++) {
      controlAerobi_B.a[i] = 0.0;
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.a[i] += a_0[6 * distorsioned + i] *
          controlAerobi_DWork.x_k_f[distorsioned];
      }

      controlAerobi_B.rtb_Gain_po_g[i] = b_a_0[i + 12] * controlAerobi_B.ubx_d[2]
        + (b_a_0[i + 6] * controlAerobi_B.rtb_Switch_Pos_idx_1 + b_a_0[i] *
           controlAerobi_B.b_x_idx_2);
    }

    // '<S177>:1:49'
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_f[i] = controlAerobi_B.a[i] +
        controlAerobi_B.rtb_Gain_po_g[i];
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.dF_k[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dF_k[o] = a_0[6 * r2 + i] * controlAerobi_DWork.P_k_h
            [6 * distorsioned + r2] + controlAerobi_B.dF_k[6 * distorsioned + i];
        }
      }
    }

    // '<S177>:1:52'
    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.dF_k[6 * r2 + i] * b_1[6 *
            distorsioned + r2];
        }

        controlAerobi_DWork.P_k_h[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] + controlAerobi_B.Gain7;
      }

      for (distorsioned = 0; distorsioned < 5; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.K_k_b[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.K_k_b[o] = controlAerobi_DWork.P_k_h[6 * r2 + i] *
            (real_T)b_b_1[6 * distorsioned + r2] + controlAerobi_B.K_k_b[6 *
            distorsioned + i];
        }
      }
    }

    for (i = 0; i < 5; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 5 * distorsioned;
        controlAerobi_B.c_a[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.c_a[o] = (real_T)c_a[5 * r2 + i] *
            controlAerobi_DWork.P_k_h[6 * distorsioned + r2] +
            controlAerobi_B.c_a[5 * distorsioned + i];
        }
      }

      for (distorsioned = 0; distorsioned < 5; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.c_a[5 * r2 + i] * (real_T)
            b_b_1[6 * distorsioned + r2];
        }

        controlAerobi_B.c_a_p[i + 5 * distorsioned] = controlAerobi_B.R[5 *
          distorsioned + i] + controlAerobi_B.Gain7;
      }
    }

    controlAerobi_mrdivide_TwA5PnsG(controlAerobi_B.K_k_b, controlAerobi_B.c_a_p);

    // '<S177>:1:54'
    // '<S177>:1:56'
    controlAerobi_B.b_exp[0] = controlAerobi_B.b_exp_b;
    controlAerobi_B.b_exp[1] = controlAerobi_B.Abs_a;
    controlAerobi_B.b_exp[2] = controlAerobi_B.sinc;
    controlAerobi_B.b_exp[3] = controlAerobi_B.Product1_a1;
    controlAerobi_B.b_exp[4] = (controlAerobi_B.r_x_idx_1 *
      controlAerobi_B.TSamp_iz + controlAerobi_P.d_sf11_Value *
      controlAerobi_B.Sum_f) * controlAerobi_B.TSamp_hv;
    for (i = 0; i < 5; i++) {
      controlAerobi_B.b_exp_l[i] = controlAerobi_B.b_exp[i] -
        controlAerobi_B.y_k[i];
    }

    for (i = 0; i < 6; i++) {
      controlAerobi_B.Gain7 = 0.0;
      for (distorsioned = 0; distorsioned < 5; distorsioned++) {
        controlAerobi_B.Gain7 += controlAerobi_B.K_k_b[6 * distorsioned + i] *
          controlAerobi_B.b_exp_l[distorsioned];
      }

      controlAerobi_DWork.x_k_f[i] += controlAerobi_B.Gain7;
    }

    // '<S177>:1:58'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      r3 = o + 6 * o;
      controlAerobi_B.dF[r3] = 1.0;
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 5; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.K_k_b[6 * r2 + i] * (real_T)
            c_a[5 * distorsioned + r2];
        }

        controlAerobi_B.dF_k[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] - controlAerobi_B.Gain7;
      }

      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        r3 = i + 6 * distorsioned;
        controlAerobi_B.dQ[r3] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dQ[r3] = controlAerobi_B.dF_k[6 * r2 + i] *
            controlAerobi_DWork.P_k_h[6 * distorsioned + r2] +
            controlAerobi_B.dQ[6 * distorsioned + i];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_DWork.P_k_h[distorsioned + 6 * i] = controlAerobi_B.dQ[6 *
          i + distorsioned];
      }
    }
  }

  // MultiPortSwitch: '<S173>/Switch_Pos' incorporates:
  //   MATLAB Function: '<S175>/EKF2_XYZ'

  // '<S177>:1:61'
  // '<S177>:1:62'
  // '<S177>:1:63'
  // '<S177>:1:64'
  // '<S177>:1:65'
  // '<S177>:1:66'
  if ((int32_T)controlAerobi_B.Sum == 1) {
    controlAerobi_B.b_x_idx_2 = controlAerobi_B.single2double[0];
    controlAerobi_B.rtb_Switch_Pos_idx_1 = controlAerobi_B.single2double[1];
  } else {
    controlAerobi_B.b_x_idx_2 = controlAerobi_DWork.x_k_f[0];
    controlAerobi_B.rtb_Switch_Pos_idx_1 = controlAerobi_DWork.x_k_f[2];
  }

  // End of MultiPortSwitch: '<S173>/Switch_Pos'

  // MultiPortSwitch: '<S173>/Switch_Z' incorporates:
  //   Constant: '<S173>/selector_z'
  //   Gain: '<S173>/Gain'
  //   MATLAB Function: '<S175>/EKF2_XYZ'

  if ((int32_T)controlAerobi_P.selector_z_Value == 1) {
    controlAerobi_B.b_exp_b = controlAerobi_P.Gain_Gain_b *
      controlAerobi_B.single2double[2];
  } else {
    controlAerobi_B.b_exp_b = controlAerobi_DWork.x_k_f[4];
  }

  // End of MultiPortSwitch: '<S173>/Switch_Z'

  // Gain: '<S172>/Gain2' incorporates:
  //   DataTypeConversion: '<S172>/Data Type Conversion2'
  //   Inport: '<Root>/I_px4flow'

  controlAerobi_B.sinc = controlAerobi_P.Gain2_Gain_k * (real_T)
    controlAerobi_U.I_px4flow._qual;

  // Gain: '<S172>/Gain4'
  controlAerobi_B.r_x_idx_1 = controlAerobi_P.Gain4_Gain *
    controlAerobi_B.Gain_po[2];

  // MATLAB Function: '<S172>/Liner Fixed-gain Filter1'
  // MATLAB Function 'Sensors/position/px4fow/Liner Fixed-gain Filter1': '<S182>:1' 
  // '<S182>:1:50'
  // '<S182>:1:45'
  // '<S182>:1:38'
  // '<S182>:1:36'
  // '<S182>:1:34'
  // '<S182>:1:6'
  // '<S182>:1:7'
  controlAerobi_B.r_x_idx_2 = 3.3121686421112381E-170;
  controlAerobi_B.Gain7 = fabs(controlAerobi_B.Switch[0]);
  if (controlAerobi_B.Gain7 > 3.3121686421112381E-170) {
    controlAerobi_B.Zgain_a = 1.0;
    controlAerobi_B.r_x_idx_2 = controlAerobi_B.Gain7;
  } else {
    controlAerobi_B.t = controlAerobi_B.Gain7 / 3.3121686421112381E-170;
    controlAerobi_B.Zgain_a = controlAerobi_B.t * controlAerobi_B.t;
  }

  controlAerobi_B.Gain7 = fabs(controlAerobi_B.Switch[1]);
  if (controlAerobi_B.Gain7 > controlAerobi_B.r_x_idx_2) {
    controlAerobi_B.t = controlAerobi_B.r_x_idx_2 / controlAerobi_B.Gain7;
    controlAerobi_B.Zgain_a = controlAerobi_B.Zgain_a * controlAerobi_B.t *
      controlAerobi_B.t + 1.0;
    controlAerobi_B.r_x_idx_2 = controlAerobi_B.Gain7;
  } else {
    controlAerobi_B.t = controlAerobi_B.Gain7 / controlAerobi_B.r_x_idx_2;
    controlAerobi_B.Zgain_a += controlAerobi_B.t * controlAerobi_B.t;
  }

  controlAerobi_B.Gain7 = fabs(controlAerobi_B.Switch[2]);
  if (controlAerobi_B.Gain7 > controlAerobi_B.r_x_idx_2) {
    controlAerobi_B.t = controlAerobi_B.r_x_idx_2 / controlAerobi_B.Gain7;
    controlAerobi_B.Zgain_a = controlAerobi_B.Zgain_a * controlAerobi_B.t *
      controlAerobi_B.t + 1.0;
    controlAerobi_B.r_x_idx_2 = controlAerobi_B.Gain7;
  } else {
    controlAerobi_B.t = controlAerobi_B.Gain7 / controlAerobi_B.r_x_idx_2;
    controlAerobi_B.Zgain_a += controlAerobi_B.t * controlAerobi_B.t;
  }

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 3;

  // MATLAB Function: '<S172>/Liner Fixed-gain Filter1' incorporates:
  //   DataTypeConversion: '<S172>/Data Type Conversion'
  //   DataTypeConversion: '<S172>/Data Type Conversion1'
  //   Gain: '<S172>/Gain'
  //   Gain: '<S172>/Gain1'
  //   Inport: '<Root>/I_px4flow'

  controlAerobi_B.Zgain_a = controlAerobi_B.r_x_idx_2 * sqrt
    (controlAerobi_B.Zgain_a);

  // '<S182>:1:8'
  controlAerobi_B.ubx_d[0] = controlAerobi_B.Switch[1] / controlAerobi_B.Zgain_a
    - controlAerobi_B.r_x_idx_0;
  controlAerobi_B.ubx_d[1] = -(controlAerobi_B.Switch[0] /
    controlAerobi_B.Zgain_a + controlAerobi_B.Abs_k);
  if ((!controlAerobi_DWork.x_k_not_empty) ||
      (!controlAerobi_DWork.P_k_not_empty)) {
    // '<S182>:1:12'
    // '<S182>:1:13'
    controlAerobi_DWork.x_k[0] = 0.0;
    controlAerobi_DWork.x_k[1] = 0.0;
    controlAerobi_DWork.x_k_not_empty = true;

    // '<S182>:1:14'
    controlAerobi_DWork.P_k[0] = 1.0;
    controlAerobi_DWork.P_k[1] = 0.0;
    controlAerobi_DWork.P_k[2] = 0.0;
    controlAerobi_DWork.P_k[3] = 1.0;
    controlAerobi_DWork.P_k_not_empty = true;
  } else {
    // '<S182>:1:24'
    // '<S182>:1:34'
    Q[1] = 0;
    Q[2] = 0;
    Q[0] = 1;
    Q[3] = 1;
    if (controlAerobi_B.sinc >= 100.0) {
      // '<S182>:1:35'
      // '<S182>:1:36'
      memset(&controlAerobi_B.R_f[0], 0, sizeof(real_T) << 4U);
      controlAerobi_B.R_f[0] = 0.5;
      controlAerobi_B.R_f[5] = 0.5;
      controlAerobi_B.R_f[10] = 0.1;
      controlAerobi_B.R_f[15] = 0.1;

      // DiscreteFir: '<S104>/Hlp' incorporates:
      //   Lookup_n-D: '<S70>/1-D Lookup Table'
      //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
      //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

      o = 4;
    } else {
      // '<S182>:1:38'
      memset(&controlAerobi_B.R_f[0], 0, sizeof(real_T) << 4U);
      controlAerobi_B.R_f[0] = 0.5;
      controlAerobi_B.R_f[5] = 0.5;
      controlAerobi_B.R_f[10] = 100000.0;
      controlAerobi_B.R_f[15] = 100000.0;

      // DiscreteFir: '<S104>/Hlp' incorporates:
      //   Lookup_n-D: '<S70>/1-D Lookup Table'
      //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
      //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

      o = 4;
    }

    // '<S182>:1:41'
    // '<S182>:1:42'
    // '<S182>:1:45'
    controlAerobi_B.y_k_idx_0 = controlAerobi_DWork.x_k[0];
    controlAerobi_B.F_b[0] = 0.348 * controlAerobi_DWork.x_k[0] + 0.0 *
      controlAerobi_DWork.x_k[1];
    controlAerobi_B.y_k_idx_1 = controlAerobi_DWork.x_k[1];
    controlAerobi_B.F_b[1] = 0.0 * controlAerobi_DWork.x_k[0];
    controlAerobi_B.F_b[1] += 0.348 * controlAerobi_DWork.x_k[1];

    // '<S182>:1:47'
    for (i = 0; i < 2; i++) {
      controlAerobi_DWork.x_k[i] = controlAerobi_B.F_b[i];
      controlAerobi_B.F_d[i] = 0.0;
      controlAerobi_B.F_d[i] += a_1[i] * controlAerobi_DWork.P_k[0];
      controlAerobi_B.F_d[i] += a_1[i + 2] * controlAerobi_DWork.P_k[1];
      controlAerobi_B.F_d[i + 2] = 0.0;
      controlAerobi_B.F_d[i + 2] += a_1[i] * controlAerobi_DWork.P_k[2];
      controlAerobi_B.F_d[i + 2] += a_1[i + 2] * controlAerobi_DWork.P_k[3];
    }

    // '<S182>:1:50'
    for (i = 0; i < 2; i++) {
      controlAerobi_DWork.P_k[i] = (controlAerobi_B.F_d[i + 2] * 0.0 +
        controlAerobi_B.F_d[i] * 0.348) + (real_T)Q[i];
      controlAerobi_DWork.P_k[i + 2] = (controlAerobi_B.F_d[i + 2] * 0.348 +
        controlAerobi_B.F_d[i] * 0.0) + (real_T)Q[i + 2];
      for (distorsioned = 0; distorsioned < 4; distorsioned++) {
        controlAerobi_B.K_k_j[i + (distorsioned << 1)] = 0.0;
        controlAerobi_B.K_k_j[i + (distorsioned << 1)] += b_b_2[distorsioned <<
          1] * controlAerobi_DWork.P_k[i];
        controlAerobi_B.K_k_j[i + (distorsioned << 1)] += b_b_2[(distorsioned <<
          1) + 1] * controlAerobi_DWork.P_k[i + 2];
      }
    }

    for (i = 0; i < 4; i++) {
      controlAerobi_B.H[i] = 0.0;
      controlAerobi_B.H[i] += b_a_1[i] * controlAerobi_DWork.P_k[0];
      controlAerobi_B.H[i] += b_a_1[i + 4] * controlAerobi_DWork.P_k[1];
      controlAerobi_B.H[i + 4] = 0.0;
      controlAerobi_B.H[i + 4] += b_a_1[i] * controlAerobi_DWork.P_k[2];
      controlAerobi_B.H[i + 4] += b_a_1[i + 4] * controlAerobi_DWork.P_k[3];
      for (distorsioned = 0; distorsioned < 4; distorsioned++) {
        controlAerobi_B.rtb_Sum_g2[i + (distorsioned << 2)] = (b_b_2
          [(distorsioned << 1) + 1] * controlAerobi_B.H[i + 4] +
          b_b_2[distorsioned << 1] * controlAerobi_B.H[i]) +
          controlAerobi_B.R_f[(distorsioned << 2) + i];
      }
    }

    controlAero_mrdivide_oxNR4jke_k(controlAerobi_B.K_k_j,
      controlAerobi_B.rtb_Sum_g2);

    // '<S182>:1:52'
    // '<S182>:1:54'
    controlAerobi_B.q_k_d[0] = controlAerobi_B.ubx_d[0];
    controlAerobi_B.q_k_d[1] = controlAerobi_B.ubx_d[1];
    controlAerobi_B.q_k_d[2] = controlAerobi_P.Gain1_Gain_a * (real_T)
      controlAerobi_U.I_px4flow._flow_comp_m_y;
    controlAerobi_B.q_k_d[3] = controlAerobi_P.Gain_Gain_p * (real_T)
      controlAerobi_U.I_px4flow._flow_comp_m_x;
    for (i = 0; i < 4; i++) {
      controlAerobi_B.ubx[i] = controlAerobi_B.q_k_d[i] - (b_a_1[i + 4] *
        controlAerobi_B.y_k_idx_1 + b_a_1[i] * controlAerobi_B.y_k_idx_0);
    }

    for (i = 0; i < 2; i++) {
      controlAerobi_DWork.x_k[i] += ((controlAerobi_B.K_k_j[i + 2] *
        controlAerobi_B.ubx[1] + controlAerobi_B.K_k_j[i] * controlAerobi_B.ubx
        [0]) + controlAerobi_B.K_k_j[i + 4] * controlAerobi_B.ubx[2]) +
        controlAerobi_B.K_k_j[i + 6] * controlAerobi_B.ubx[3];
    }

    // '<S182>:1:56'
    Q[1] = 0;
    Q[2] = 0;
    Q[0] = 1;
    Q[3] = 1;

    // DiscreteFir: '<S104>/Hlp' incorporates:
    //   DataTypeConversion: '<S172>/Data Type Conversion'
    //   DataTypeConversion: '<S172>/Data Type Conversion1'
    //   Gain: '<S172>/Gain'
    //   Gain: '<S172>/Gain1'
    //   Inport: '<Root>/I_px4flow'
    //   Lookup_n-D: '<S70>/1-D Lookup Table'
    //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
    //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

    o = 2;
    for (i = 0; i < 2; i++) {
      for (distorsioned = 0; distorsioned < 2; distorsioned++) {
        controlAerobi_B.F_d[i + (distorsioned << 1)] = (real_T)Q[(distorsioned <<
          1) + i] - (((b_a_1[(distorsioned << 2) + 1] * controlAerobi_B.K_k_j[i
                       + 2] + b_a_1[distorsioned << 2] * controlAerobi_B.K_k_j[i])
                      + b_a_1[(distorsioned << 2) + 2] * controlAerobi_B.K_k_j[i
                      + 4]) + b_a_1[(distorsioned << 2) + 3] *
                     controlAerobi_B.K_k_j[i + 6]);
      }

      controlAerobi_B.q_k_d[i] = 0.0;
      controlAerobi_B.q_k_d[i] += controlAerobi_B.F_d[i] *
        controlAerobi_DWork.P_k[0];
      controlAerobi_B.q_k_d[i] += controlAerobi_B.F_d[i + 2] *
        controlAerobi_DWork.P_k[1];
      controlAerobi_B.q_k_d[i + 2] = 0.0;
      controlAerobi_B.q_k_d[i + 2] += controlAerobi_B.F_d[i] *
        controlAerobi_DWork.P_k[2];
      controlAerobi_B.q_k_d[i + 2] += controlAerobi_B.F_d[i + 2] *
        controlAerobi_DWork.P_k[3];
    }

    controlAerobi_DWork.P_k[0] = controlAerobi_B.q_k_d[0];
    controlAerobi_DWork.P_k[1] = controlAerobi_B.q_k_d[1];
    controlAerobi_DWork.P_k[2] = controlAerobi_B.q_k_d[2];
    controlAerobi_DWork.P_k[3] = controlAerobi_B.q_k_d[3];
  }

  // '<S182>:1:60'
  // '<S182>:1:61'
  // '<S182>:1:62'
  // '<S182>:1:63'
  // '<S182>:1:64'
  controlAerobi_B.r_x_idx_2 = sin(controlAerobi_B.r_x_idx_1);
  controlAerobi_B.r_x_idx_1 = cos(controlAerobi_B.r_x_idx_1);
  controlAerobi_B.vx = controlAerobi_B.r_x_idx_1 * controlAerobi_DWork.x_k[0] +
    controlAerobi_B.r_x_idx_2 * controlAerobi_DWork.x_k[1];
  controlAerobi_B.vy = -controlAerobi_B.r_x_idx_2 * controlAerobi_DWork.x_k[0] +
    controlAerobi_B.r_x_idx_1 * controlAerobi_DWork.x_k[1];
  controlAerobi_B.ax = controlAerobi_B.ubx_d[0];
  controlAerobi_B.ay = controlAerobi_B.ubx_d[1];

  // MultiPortSwitch: '<S173>/Switch_Vel' incorporates:
  //   Constant: '<S173>/select_xy_px1'
  //   Constant: '<S173>/selector_z'
  //   MATLAB Function: '<S175>/EKF2_XYZ'
  //   Switch: '<S173>/Switch1'

  if ((int32_T)controlAerobi_P.selector_z_Value == 1) {
    controlAerobi_B.b_x_idx_1 = controlAerobi_B.single2double[3];
    controlAerobi_B.x_I_idx_1 = controlAerobi_B.single2double[4];

    // MultiPortSwitch: '<S173>/Switch_dZ' incorporates:
    //   Gain: '<S173>/Gain1'

    controlAerobi_B.r_x_idx_1 = controlAerobi_P.Gain1_Gain_p *
      controlAerobi_B.single2double[5];
  } else {
    if (controlAerobi_P.select_xy_px1_Value != 0.0) {
      // Switch: '<S173>/Switch1'
      controlAerobi_B.b_x_idx_1 = controlAerobi_B.vx;
      controlAerobi_B.x_I_idx_1 = controlAerobi_B.vy;
    } else {
      controlAerobi_B.b_x_idx_1 = controlAerobi_DWork.x_k_f[1];
      controlAerobi_B.x_I_idx_1 = controlAerobi_DWork.x_k_f[3];
    }

    // MultiPortSwitch: '<S173>/Switch_dZ' incorporates:
    //   MATLAB Function: '<S175>/EKF2_XYZ'

    controlAerobi_B.r_x_idx_1 = controlAerobi_DWork.x_k_f[5];
  }

  // End of MultiPortSwitch: '<S173>/Switch_Vel'

  // Logic: '<S155>/Logical Operator' incorporates:
  //   Constant: '<S155>/rollPitch_pos_rate'
  //   Constant: '<S160>/Constant'
  //   DataTypeConversion: '<S155>/Data Type Conversion2'
  //   Inport: '<Root>/I_RCinput'
  //   RelationalOperator: '<S160>/Compare'

  controlAerobi_B.ALTHOLD = (controlAerobi_B.Compare &&
    controlAerobi_P.rollPitch_pos_rate_Value &&
    (controlAerobi_U.I_RCinput._channel5 >=
     controlAerobi_P.CompareToConstant2_const));

  // MATLAB Function: '<S155>/enable pos' incorporates:
  //   Inport: '<Root>/I_totalStation'

  // MATLAB Function 'Sensors/control_modes/ModeBlock/enable pos': '<S163>:1'
  if (rtIsNaN(controlAerobi_U.I_totalStation._time) || rtIsInf
      (controlAerobi_U.I_totalStation._time) ||
      (controlAerobi_U.I_totalStation._time == 0.0)) {
    // '<S163>:1:3'
    // '<S163>:1:4'
    controlAerobi_B.r_x_idx_2 = 0.0;
  } else {
    // '<S163>:1:7'
    controlAerobi_B.r_x_idx_2 = 1.0;
  }

  // End of MATLAB Function: '<S155>/enable pos'

  // Logic: '<S155>/Logical Operator1' incorporates:
  //   Constant: '<S155>/position'
  //   Constant: '<S161>/Constant'
  //   DataTypeConversion: '<S155>/Data Type Conversion2'
  //   Inport: '<Root>/I_RCinput'
  //   Logic: '<S155>/Logical Operator4'
  //   RelationalOperator: '<S161>/Compare'

  controlAerobi_B.POS_HOLD = (controlAerobi_B.ALTHOLD &&
    (controlAerobi_U.I_RCinput._channel5 >=
     controlAerobi_P.CompareToConstant3_const) && ((controlAerobi_B.r_x_idx_2 !=
    0.0) || controlAerobi_P.position_Value));

  // Logic: '<S18>/Logical Operator'
  rtb_LogicalOperator = (controlAerobi_B.Compare && controlAerobi_B.POS_HOLD);

  // DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
  if (rtb_LogicalOperator &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevRese <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC;
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC;
  }

  // DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
  if (controlAerobi_B.ALTHOLD &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_k <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f =
      controlAerobi_P.DiscreteTimeIntegrator_IC_d;
  }

  // Saturate: '<S26>/Saturation'
  if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f >
      controlAerobi_P.Saturation_UpperSat_p) {
    controlAerobi_B.r_x_idx_2 = controlAerobi_P.Saturation_UpperSat_p;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f <
             controlAerobi_P.Saturation_LowerSat_k) {
    controlAerobi_B.r_x_idx_2 = controlAerobi_P.Saturation_LowerSat_k;
  } else {
    controlAerobi_B.r_x_idx_2 =
      controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f;
  }

  // End of Saturate: '<S26>/Saturation'

  // MATLAB Function: '<S20>/altitude_fcn'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_altitude_des/altitude_fcn': '<S24>:1' 
  if ((!controlAerobi_DWork.z0_not_empty_h) ||
      (!controlAerobi_DWork.althold0_not_empty_k) ||
      (!controlAerobi_DWork.thrust0_not_empty_h)) {
    // '<S24>:1:4'
    // '<S24>:1:5'
    controlAerobi_DWork.z0_g = controlAerobi_B.b_exp_b;
    controlAerobi_DWork.z0_not_empty_h = true;

    // '<S24>:1:6'
    controlAerobi_DWork.althold0_b = 0.0;
    controlAerobi_DWork.althold0_not_empty_k = true;

    // '<S24>:1:7'
    controlAerobi_DWork.thrust0_f = controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_DWork.thrust0_not_empty_h = true;
  } else {
    if ((controlAerobi_DWork.althold0_b == 0.0) && controlAerobi_B.ALTHOLD) {
      // '<S24>:1:10'
      // '<S24>:1:11'
      controlAerobi_DWork.z0_g = controlAerobi_B.b_exp_b;

      // '<S24>:1:12'
      controlAerobi_DWork.thrust0_f = controlAerobi_B.DiscreteTimeIntegrator_b;
    } else {
      if ((controlAerobi_DWork.althold0_b == 0.0) && (!controlAerobi_B.ALTHOLD))
      {
        // '<S24>:1:13'
        // '<S24>:1:14'
        controlAerobi_DWork.z0_g = controlAerobi_B.b_exp_b;
      }
    }

    // '<S24>:1:16'
    controlAerobi_DWork.althold0_b = controlAerobi_B.ALTHOLD;
  }

  // Switch: '<S16>/Switch2' incorporates:
  //   Constant: '<S155>/enable_PC'
  //   Constant: '<S156>/Xdes'
  //   Constant: '<S156>/Ydes'
  //   Constant: '<S156>/Zdes'
  //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator'

  // '<S24>:1:19'
  // '<S24>:1:20'
  if (controlAerobi_P.enable_PC_Value) {
    controlAerobi_B.ub_[0] = controlAerobi_P.Xdes_Value;
    controlAerobi_B.ub_[1] = controlAerobi_P.Ydes_Value;
    controlAerobi_B.ub_[2] = controlAerobi_P.Zdes_Value;
  } else {
    controlAerobi_B.ub_[0] = controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE[0];
    controlAerobi_B.ub_[1] = controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE[1];

    // Sum: '<S20>/Sum1' incorporates:
    //   DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
    //   MATLAB Function: '<S20>/altitude_fcn'

    controlAerobi_B.absxk = controlAerobi_B.r_x_idx_2 + controlAerobi_DWork.z0_g;

    // Saturate: '<S20>/Saturation'
    if (controlAerobi_B.absxk > controlAerobi_P.Saturation_UpperSat) {
      controlAerobi_B.ub_[2] = controlAerobi_P.Saturation_UpperSat;
    } else if (controlAerobi_B.absxk < controlAerobi_P.Saturation_LowerSat) {
      controlAerobi_B.ub_[2] = controlAerobi_P.Saturation_LowerSat;
    } else {
      controlAerobi_B.ub_[2] = controlAerobi_B.absxk;
    }

    // End of Saturate: '<S20>/Saturation'
  }

  // End of Switch: '<S16>/Switch2'

  // MATLAB Function: '<S16>/calculate_v_d'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_v_d': '<S22>:1' 
  // '<S22>:1:35'
  // '<S22>:1:32'
  // '<S22>:1:30'
  // '<S22>:1:27'
  // '<S22>:1:26'
  if ((!controlAerobi_DWork.x_k_not_empty_a) ||
      (!controlAerobi_DWork.P_k_not_empty_lk)) {
    // '<S22>:1:7'
    // '<S22>:1:8'
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_l[i] = 0.0;
    }

    controlAerobi_DWork.x_k_not_empty_a = true;

    // '<S22>:1:9'
    memset(&controlAerobi_DWork.P_k_d[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      i = o + 6 * o;
      controlAerobi_DWork.P_k_d[i] = 1.0;
    }

    controlAerobi_DWork.P_k_not_empty_lk = true;
  } else {
    // '<S22>:1:19'
    // '<S22>:1:20'
    controlAerobi_B.vbx[0] = controlAerobi_DWork.x_k_l[0];
    controlAerobi_B.vbx[1] = controlAerobi_DWork.x_k_l[2];
    controlAerobi_B.vbx[2] = controlAerobi_DWork.x_k_l[4];

    // '<S22>:1:26'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (r2 = 0; r2 < 6; r2++) {
      controlAerobi_B.dF[r2 + 6 * r2] = b_2[r2];
    }

    // '<S22>:1:27'
    for (i = 0; i < 9; i++) {
      controlAerobi_B.R_n[i] = 0;
    }

    controlAerobi_B.R_n[0] = 10;
    controlAerobi_B.R_n[4] = 10;
    controlAerobi_B.R_n[8] = 10;

    // DiscreteFir: '<S104>/Hlp' incorporates:
    //   Lookup_n-D: '<S70>/1-D Lookup Table'
    //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
    //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

    o = 3;

    // '<S22>:1:30'
    for (i = 0; i < 6; i++) {
      controlAerobi_B.a[i] = 0.0;
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.a[i] += a_2[6 * distorsioned + i] *
          controlAerobi_DWork.x_k_l[distorsioned];
      }
    }

    // '<S22>:1:32'
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_l[i] = controlAerobi_B.a[i];
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.dF_k[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dF_k[o] = a_2[6 * r2 + i] * controlAerobi_DWork.P_k_d
            [6 * distorsioned + r2] + controlAerobi_B.dF_k[6 * distorsioned + i];
        }
      }
    }

    // '<S22>:1:35'
    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.dF_k[6 * r2 + i] * c_b_1[6 *
            distorsioned + r2];
        }

        controlAerobi_DWork.P_k_d[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] + controlAerobi_B.Gain7;
      }

      for (distorsioned = 0; distorsioned < 3; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.y[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.y[o] = controlAerobi_DWork.P_k_d[6 * r2 + i] * (real_T)
            b_b_3[6 * distorsioned + r2] + controlAerobi_B.y[6 * distorsioned +
            i];
        }
      }
    }

    for (i = 0; i < 3; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 3 * distorsioned;
        controlAerobi_B.dK_k[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dK_k[o] = (real_T)b_a_2[3 * r2 + i] *
            controlAerobi_DWork.P_k_d[6 * distorsioned + r2] +
            controlAerobi_B.dK_k[3 * distorsioned + i];
        }
      }

      for (distorsioned = 0; distorsioned < 3; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.dK_k[3 * r2 + i] * (real_T)
            b_b_3[6 * distorsioned + r2];
        }

        controlAerobi_B.P_ui[i + 3 * distorsioned] = (real_T)
          controlAerobi_B.R_n[3 * distorsioned + i] + controlAerobi_B.Gain7;
      }
    }

    distorsioned = 0;
    r2 = 1;
    r3 = 2;
    controlAerobi_B.Product1_a1 = fabs(controlAerobi_B.P_ui[0]);
    controlAerobi_B.Product1_ew = fabs(controlAerobi_B.P_ui[1]);
    if (controlAerobi_B.Product1_ew > controlAerobi_B.Product1_a1) {
      controlAerobi_B.Product1_a1 = controlAerobi_B.Product1_ew;
      distorsioned = 1;
      r2 = 0;
    }

    if (fabs(controlAerobi_B.P_ui[2]) > controlAerobi_B.Product1_a1) {
      distorsioned = 2;
      r2 = 1;
      r3 = 0;
    }

    controlAerobi_B.P_ui[r2] /= controlAerobi_B.P_ui[distorsioned];
    controlAerobi_B.P_ui[r3] /= controlAerobi_B.P_ui[distorsioned];
    controlAerobi_B.P_ui[3 + r2] -= controlAerobi_B.P_ui[3 + distorsioned] *
      controlAerobi_B.P_ui[r2];
    controlAerobi_B.P_ui[3 + r3] -= controlAerobi_B.P_ui[3 + distorsioned] *
      controlAerobi_B.P_ui[r3];
    controlAerobi_B.P_ui[6 + r2] -= controlAerobi_B.P_ui[6 + distorsioned] *
      controlAerobi_B.P_ui[r2];
    controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[6 + distorsioned] *
      controlAerobi_B.P_ui[r3];
    if (fabs(controlAerobi_B.P_ui[3 + r3]) > fabs(controlAerobi_B.P_ui[3 + r2]))
    {
      o = r2 + 1;
      r2 = r3;
      r3 = o - 1;
    }

    controlAerobi_B.P_ui[3 + r3] /= controlAerobi_B.P_ui[3 + r2];
    controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[3 + r3] *
      controlAerobi_B.P_ui[6 + r2];
    for (o = 0; o < 6; o++) {
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[o] /
        controlAerobi_B.P_ui[distorsioned];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[6 + o] - controlAerobi_B.dK_k
        [6 * distorsioned + o] * controlAerobi_B.P_ui[3 + distorsioned];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[12 + o] -
        controlAerobi_B.dK_k[6 * distorsioned + o] * controlAerobi_B.P_ui[6 +
        distorsioned];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] /
        controlAerobi_B.P_ui[3 + r2];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] -
        controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[6 + r2];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] /
        controlAerobi_B.P_ui[6 + r3];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] -
        controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[3 + r3];
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
        controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[r3];
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
        controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[r2];
    }

    // '<S22>:1:37'
    // '<S22>:1:39'
    controlAerobi_B.Product1_ew = controlAerobi_B.ub_[0] - controlAerobi_B.vbx[0];
    controlAerobi_B.Product1_a1 = controlAerobi_B.ub_[1] - controlAerobi_B.vbx[1];
    controlAerobi_B.Sum_c = controlAerobi_B.ub_[2] - controlAerobi_B.vbx[2];
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_l[i] += (controlAerobi_B.dK_k[i + 6] *
        controlAerobi_B.Product1_a1 + controlAerobi_B.dK_k[i] *
        controlAerobi_B.Product1_ew) + controlAerobi_B.dK_k[i + 12] *
        controlAerobi_B.Sum_c;
    }

    // '<S22>:1:41'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      r3 = o + 6 * o;
      controlAerobi_B.dF[r3] = 1.0;
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.dF_k[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] - (((real_T)b_a_2[3 * distorsioned + 1] *
          controlAerobi_B.dK_k[i + 6] + (real_T)b_a_2[3 * distorsioned] *
          controlAerobi_B.dK_k[i]) + (real_T)b_a_2[3 * distorsioned + 2] *
          controlAerobi_B.dK_k[i + 12]);
      }

      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        r3 = i + 6 * distorsioned;
        controlAerobi_B.dQ[r3] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dQ[r3] = controlAerobi_B.dF_k[6 * r2 + i] *
            controlAerobi_DWork.P_k_d[6 * distorsioned + r2] +
            controlAerobi_B.dQ[6 * distorsioned + i];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_DWork.P_k_d[distorsioned + 6 * i] = controlAerobi_B.dQ[6 *
          i + distorsioned];
      }
    }
  }

  // MATLAB Function: '<S16>/calculate_ddx_d' incorporates:
  //   MATLAB Function: '<S16>/calculate_v_d'

  // '<S22>:1:44'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_ddx_d': '<S21>:1' 
  // '<S21>:1:35'
  // '<S21>:1:32'
  // '<S21>:1:30'
  // '<S21>:1:27'
  // '<S21>:1:26'
  if ((!controlAerobi_DWork.x_k_not_empty_d) ||
      (!controlAerobi_DWork.P_k_not_empty_o)) {
    // '<S21>:1:7'
    // '<S21>:1:8'
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_m[i] = 0.0;
    }

    controlAerobi_DWork.x_k_not_empty_d = true;

    // '<S21>:1:9'
    memset(&controlAerobi_DWork.P_k_k[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      i = o + 6 * o;
      controlAerobi_DWork.P_k_k[i] = 1.0;
    }

    controlAerobi_DWork.P_k_not_empty_o = true;
  } else {
    // '<S21>:1:20'
    controlAerobi_B.vbx[0] = controlAerobi_DWork.x_k_m[0];
    controlAerobi_B.vbx[1] = controlAerobi_DWork.x_k_m[2];
    controlAerobi_B.vbx[2] = controlAerobi_DWork.x_k_m[4];

    // '<S21>:1:26'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (r2 = 0; r2 < 6; r2++) {
      controlAerobi_B.dF[r2 + 6 * r2] = b_3[r2];
    }

    // '<S21>:1:27'
    for (i = 0; i < 9; i++) {
      controlAerobi_B.R_n[i] = 0;
    }

    controlAerobi_B.R_n[0] = 1;
    controlAerobi_B.R_n[4] = 1;
    controlAerobi_B.R_n[8] = 1;

    // DiscreteFir: '<S104>/Hlp' incorporates:
    //   Lookup_n-D: '<S70>/1-D Lookup Table'
    //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
    //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

    o = 3;

    // '<S21>:1:30'
    for (i = 0; i < 6; i++) {
      controlAerobi_B.a[i] = 0.0;
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.a[i] += a_3[6 * distorsioned + i] *
          controlAerobi_DWork.x_k_m[distorsioned];
      }
    }

    // '<S21>:1:32'
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_m[i] = controlAerobi_B.a[i];
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.dF_k[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dF_k[o] = a_3[6 * r2 + i] * controlAerobi_DWork.P_k_k
            [6 * distorsioned + r2] + controlAerobi_B.dF_k[6 * distorsioned + i];
        }
      }
    }

    // '<S21>:1:35'
    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.dF_k[6 * r2 + i] * c_b_2[6 *
            distorsioned + r2];
        }

        controlAerobi_DWork.P_k_k[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] + controlAerobi_B.Gain7;
      }

      for (distorsioned = 0; distorsioned < 3; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.y[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.y[o] = controlAerobi_DWork.P_k_k[6 * r2 + i] * (real_T)
            b_b_4[6 * distorsioned + r2] + controlAerobi_B.y[6 * distorsioned +
            i];
        }
      }
    }

    for (i = 0; i < 3; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 3 * distorsioned;
        controlAerobi_B.dK_k[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dK_k[o] = (real_T)b_a_3[3 * r2 + i] *
            controlAerobi_DWork.P_k_k[6 * distorsioned + r2] +
            controlAerobi_B.dK_k[3 * distorsioned + i];
        }
      }

      for (distorsioned = 0; distorsioned < 3; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.dK_k[3 * r2 + i] * (real_T)
            b_b_4[6 * distorsioned + r2];
        }

        controlAerobi_B.P_ui[i + 3 * distorsioned] = (real_T)
          controlAerobi_B.R_n[3 * distorsioned + i] + controlAerobi_B.Gain7;
      }
    }

    distorsioned = 0;
    r2 = 1;
    r3 = 2;
    controlAerobi_B.Product1_a1 = fabs(controlAerobi_B.P_ui[0]);
    controlAerobi_B.Product1_ew = fabs(controlAerobi_B.P_ui[1]);
    if (controlAerobi_B.Product1_ew > controlAerobi_B.Product1_a1) {
      controlAerobi_B.Product1_a1 = controlAerobi_B.Product1_ew;
      distorsioned = 1;
      r2 = 0;
    }

    if (fabs(controlAerobi_B.P_ui[2]) > controlAerobi_B.Product1_a1) {
      distorsioned = 2;
      r2 = 1;
      r3 = 0;
    }

    controlAerobi_B.P_ui[r2] /= controlAerobi_B.P_ui[distorsioned];
    controlAerobi_B.P_ui[r3] /= controlAerobi_B.P_ui[distorsioned];
    controlAerobi_B.P_ui[3 + r2] -= controlAerobi_B.P_ui[3 + distorsioned] *
      controlAerobi_B.P_ui[r2];
    controlAerobi_B.P_ui[3 + r3] -= controlAerobi_B.P_ui[3 + distorsioned] *
      controlAerobi_B.P_ui[r3];
    controlAerobi_B.P_ui[6 + r2] -= controlAerobi_B.P_ui[6 + distorsioned] *
      controlAerobi_B.P_ui[r2];
    controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[6 + distorsioned] *
      controlAerobi_B.P_ui[r3];
    if (fabs(controlAerobi_B.P_ui[3 + r3]) > fabs(controlAerobi_B.P_ui[3 + r2]))
    {
      o = r2 + 1;
      r2 = r3;
      r3 = o - 1;
    }

    controlAerobi_B.P_ui[3 + r3] /= controlAerobi_B.P_ui[3 + r2];
    controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[3 + r3] *
      controlAerobi_B.P_ui[6 + r2];
    for (o = 0; o < 6; o++) {
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[o] /
        controlAerobi_B.P_ui[distorsioned];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[6 + o] - controlAerobi_B.dK_k
        [6 * distorsioned + o] * controlAerobi_B.P_ui[3 + distorsioned];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[12 + o] -
        controlAerobi_B.dK_k[6 * distorsioned + o] * controlAerobi_B.P_ui[6 +
        distorsioned];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] /
        controlAerobi_B.P_ui[3 + r2];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] -
        controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[6 + r2];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] /
        controlAerobi_B.P_ui[6 + r3];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] -
        controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[3 + r3];
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
        controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[r3];
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
        controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[r2];
    }

    // '<S21>:1:37'
    // '<S21>:1:39'
    controlAerobi_B.Zgain_a = controlAerobi_DWork.x_k_l[1] -
      controlAerobi_B.vbx[0];
    controlAerobi_B.absxk = controlAerobi_DWork.x_k_l[3] - controlAerobi_B.vbx[1];
    controlAerobi_B.Abs_a = controlAerobi_DWork.x_k_l[5] - controlAerobi_B.vbx[2];
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_m[i] += (controlAerobi_B.dK_k[i + 6] *
        controlAerobi_B.absxk + controlAerobi_B.dK_k[i] *
        controlAerobi_B.Zgain_a) + controlAerobi_B.dK_k[i + 12] *
        controlAerobi_B.Abs_a;
    }

    // '<S21>:1:41'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      r3 = o + 6 * o;
      controlAerobi_B.dF[r3] = 1.0;
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.dF_k[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] - (((real_T)b_a_3[3 * distorsioned + 1] *
          controlAerobi_B.dK_k[i + 6] + (real_T)b_a_3[3 * distorsioned] *
          controlAerobi_B.dK_k[i]) + (real_T)b_a_3[3 * distorsioned + 2] *
          controlAerobi_B.dK_k[i + 12]);
      }

      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        r3 = i + 6 * distorsioned;
        controlAerobi_B.dQ[r3] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dQ[r3] = controlAerobi_B.dF_k[6 * r2 + i] *
            controlAerobi_DWork.P_k_k[6 * distorsioned + r2] +
            controlAerobi_B.dQ[6 * distorsioned + i];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_DWork.P_k_k[distorsioned + 6 * i] = controlAerobi_B.dQ[6 *
          i + distorsioned];
      }
    }
  }

  // MATLAB Function: '<S10>/trajectory_tracking' incorporates:
  //   Constant: '<S94>/c1'
  //   Constant: '<S94>/k_i'
  //   Constant: '<S94>/k_x'
  //   Constant: '<S94>/sat_P'
  //   Gain: '<S16>/Gain2'
  //   Logic: '<S16>/Logical Operator'
  //   MATLAB Function: '<S16>/calculate_v_d'
  //   MATLAB Function: '<S9>/attitude_geometric_control'

  // '<S21>:1:44'
  controlAerobi_B.eulerZYX[0] = controlAerobi_P.k_i_Value[0];
  controlAerobi_B.eulerZYX[1] = controlAerobi_P.k_i_Value[1];
  controlAerobi_B.eulerZYX[2] = controlAerobi_P.k_i_Value[2];

  // MATLAB Function 'Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/trajectory_tracking': '<S17>:1' 
  // '<S17>:1:34'
  // '<S17>:1:3'
  // '<S17>:1:4'
  controlAerobi_B.R_[0] = controlAerobi_B.TSamp_hv * controlAerobi_B.ubx_tmp;
  controlAerobi_B.y_k_idx_1 = controlAerobi_B.Sum_f * controlAerobi_B.r_x_idx_0;
  controlAerobi_B.R_[3] = controlAerobi_B.y_k_idx_1 * controlAerobi_B.ubx_tmp +
    -controlAerobi_B.TSamp_iz * controlAerobi_B.ubx_tmp_a;
  controlAerobi_B.y_k_idx_0 = controlAerobi_B.TSamp_iz *
    controlAerobi_B.r_x_idx_0;
  controlAerobi_B.R_[6] = controlAerobi_B.y_k_idx_0 * controlAerobi_B.ubx_tmp +
    controlAerobi_B.Sum_f * controlAerobi_B.ubx_tmp_a;
  controlAerobi_B.R_[1] = controlAerobi_B.TSamp_hv * controlAerobi_B.ubx_tmp_a;
  controlAerobi_B.R_[4] = controlAerobi_B.y_k_idx_1 * controlAerobi_B.ubx_tmp_a
    + controlAerobi_B.TSamp_iz * controlAerobi_B.ubx_tmp;
  controlAerobi_B.R_[7] = controlAerobi_B.y_k_idx_0 * controlAerobi_B.ubx_tmp_a
    + -controlAerobi_B.Sum_f * controlAerobi_B.ubx_tmp;
  controlAerobi_B.R_[2] = -controlAerobi_B.r_x_idx_0;
  controlAerobi_B.R_[5] = controlAerobi_B.Abs_k;
  controlAerobi_B.R_[8] = controlAerobi_B.ubx_tmp_j;
  if ((!controlAerobi_DWork.e_i_not_empty) || (!controlAerobi_DWork.M_not_empty))
  {
    // '<S17>:1:9'
    // '<S17>:1:10'
    controlAerobi_DWork.e_i_not_empty = true;

    // '<S17>:1:11'
    controlAerobi_DWork.e_i[0] = 0.0;
    controlAerobi_DWork.M[0] = 0.0;
    controlAerobi_DWork.e_i[1] = 0.0;
    controlAerobi_DWork.M[1] = 0.0;
    controlAerobi_DWork.e_i[2] = 0.0;
    controlAerobi_DWork.M[2] = 0.0;
    controlAerobi_DWork.M_not_empty = true;
  }

  // '<S17>:1:14'
  // '<S17>:1:15'
  controlAerobi_B.vbx[0] = controlAerobi_B.b_x_idx_2 - controlAerobi_B.ub_[0];
  controlAerobi_B.vbx[1] = controlAerobi_B.rtb_Switch_Pos_idx_1 -
    controlAerobi_B.ub_[1];
  controlAerobi_B.vbx[2] = controlAerobi_B.b_exp_b - controlAerobi_B.ub_[2];

  // '<S17>:1:17'
  // '<S17>:1:18'
  controlAerobi_B.ub_[0] = controlAerobi_B.b_x_idx_1 -
    controlAerobi_P.Gain2_Gain_i * controlAerobi_DWork.x_k_l[1];
  controlAerobi_B.ub_[1] = controlAerobi_B.x_I_idx_1 -
    controlAerobi_P.Gain2_Gain_i * controlAerobi_DWork.x_k_l[3];
  controlAerobi_B.ub_[2] = controlAerobi_B.r_x_idx_1 -
    controlAerobi_P.Gain2_Gain_i * controlAerobi_DWork.x_k_l[5];
  if (controlAerobi_B.Compare && controlAerobi_B.ALTHOLD) {
    // '<S17>:1:21'
    // '<S17>:1:22'
    for (i = 0; i < 9; i++) {
      controlAerobi_B.P_ui[i] = 0.0;
    }

    controlAerobi_B.P_ui[0] = controlAerobi_P.c1_Value[0];
    controlAerobi_B.P_ui[4] = controlAerobi_P.c1_Value[1];
    controlAerobi_B.P_ui[8] = controlAerobi_P.c1_Value[2];

    // '<S17>:1:23'
    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      controlAerobi_DWork.e_i[distorsioned] =
        (((controlAerobi_B.P_ui[distorsioned + 3] * controlAerobi_B.vbx[1] +
           controlAerobi_B.P_ui[distorsioned] * controlAerobi_B.vbx[0]) +
          controlAerobi_B.P_ui[distorsioned + 6] * controlAerobi_B.vbx[2]) +
         controlAerobi_B.ub_[distorsioned]) * 0.5 * 0.0025 -
        controlAerobi_DWork.e_i[distorsioned];

      // '<S17>:1:23'
      if ((controlAerobi_DWork.M[distorsioned] >
           controlAerobi_P.sat_P_Value[distorsioned]) ||
          (controlAerobi_DWork.M[distorsioned] <
           -controlAerobi_P.sat_P_Value[distorsioned])) {
        // '<S17>:1:24'
        // '<S17>:1:25'
        controlAerobi_B.eulerZYX[distorsioned] = 0.0;
      }
    }
  } else {
    // '<S17>:1:29'
    controlAerobi_DWork.e_i[0] = 0.0;
    controlAerobi_DWork.e_i[1] = 0.0;
    controlAerobi_DWork.e_i[2] = 0.0;
  }

  // '<S17>:1:34'
  for (i = 0; i < 9; i++) {
    controlAerobi_B.P_ui[i] = 0.0;
  }

  controlAerobi_B.P_ui[0] = controlAerobi_P.k_x_Value[0];
  controlAerobi_B.P_ui[4] = controlAerobi_P.k_x_Value[1];
  controlAerobi_B.P_ui[8] = controlAerobi_P.k_x_Value[2];

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 3;

  // MATLAB Function: '<S10>/trajectory_tracking' incorporates:
  //   Constant: '<S94>/k_v'

  for (i = 0; i < 9; i++) {
    controlAerobi_B.d_a[i] = 0.0;
  }

  controlAerobi_B.d_a[0] = controlAerobi_P.k_v_Value[0];
  controlAerobi_B.d_a[4] = controlAerobi_P.k_v_Value[1];
  controlAerobi_B.d_a[8] = controlAerobi_P.k_v_Value[2];

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 3;

  // MATLAB Function: '<S10>/trajectory_tracking'
  for (i = 0; i < 9; i++) {
    controlAerobi_B.R_d_m[i] = 0.0;
  }

  controlAerobi_B.R_d_m[0] = controlAerobi_B.eulerZYX[0];
  controlAerobi_B.R_d_m[4] = controlAerobi_B.eulerZYX[1];
  controlAerobi_B.R_d_m[8] = controlAerobi_B.eulerZYX[2];

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 3;

  // MATLAB Function: '<S10>/trajectory_tracking' incorporates:
  //   Constant: '<S94>/Mass'
  //   Gain: '<S16>/Gain1'
  //   MATLAB Function: '<S16>/calculate_ddx_d'

  controlAerobi_B.absxk = controlAerobi_P.Mass_Value * -9.81;
  for (i = 0; i < 3; i++) {
    controlAerobi_B.Re_R[3 * i] = -controlAerobi_B.P_ui[3 * i];
    controlAerobi_B.Re_R[1 + 3 * i] = -controlAerobi_B.P_ui[3 * i + 1];
    controlAerobi_B.Re_R[2 + 3 * i] = -controlAerobi_B.P_ui[3 * i + 2];
  }

  controlAerobi_B.rtb_Gain_po_l[0] = controlAerobi_P.Gain1_Gain_al *
    controlAerobi_DWork.x_k_m[1] * controlAerobi_P.Mass_Value;
  controlAerobi_B.rtb_Gain_po_l[1] = controlAerobi_P.Gain1_Gain_al *
    controlAerobi_DWork.x_k_m[3] * controlAerobi_P.Mass_Value;
  controlAerobi_B.rtb_Gain_po_l[2] = controlAerobi_P.Gain1_Gain_al *
    controlAerobi_DWork.x_k_m[5] * controlAerobi_P.Mass_Value;
  for (i = 0; i < 3; i++) {
    controlAerobi_B.ubx_d[i] = ((((controlAerobi_B.Re_R[i + 6] *
      controlAerobi_B.vbx[2] + (controlAerobi_B.Re_R[i + 3] *
      controlAerobi_B.vbx[1] + controlAerobi_B.Re_R[i] * controlAerobi_B.vbx[0]))
      - (controlAerobi_B.d_a[i + 6] * controlAerobi_B.ub_[2] +
         (controlAerobi_B.d_a[i + 3] * controlAerobi_B.ub_[1] +
          controlAerobi_B.d_a[i] * controlAerobi_B.ub_[0]))) -
      ((controlAerobi_B.R_d_m[i + 3] * controlAerobi_DWork.e_i[1] +
        controlAerobi_B.R_d_m[i] * controlAerobi_DWork.e_i[0]) +
       controlAerobi_B.R_d_m[i + 6] * controlAerobi_DWork.e_i[2])) -
      controlAerobi_B.absxk * (real_T)b_4[i]) + controlAerobi_B.rtb_Gain_po_l[i];
  }

  // '<S17>:1:35'
  // '<S17>:1:36'
  // '<S17>:1:37'
  // '<S17>:1:38'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.r_x_idx_0 = controlAerobi_B.R_[i + 6] +
      (controlAerobi_B.R_[i + 3] * 0.0 + controlAerobi_B.R_[i] * 0.0);
    controlAerobi_B.eulerZYX[i] = controlAerobi_B.r_x_idx_0;
    controlAerobi_B.ub_[i] = controlAerobi_B.R_[i + 6] + (controlAerobi_B.R_[i +
      3] * 0.0 + controlAerobi_B.R_[i] * 0.0);
    controlAerobi_B.vbx[i] = controlAerobi_B.r_x_idx_0;
  }

  controlAerobi_B.t = controlAerobi_B.ub_[0];
  controlAerobi_B.absxk = 0.0;
  controlAerobi_B.Zgain_a = xnrm2_36Ruq5vk(controlAerobi_B.vbx);
  if (controlAerobi_B.Zgain_a != 0.0) {
    controlAerobi_B.Zgain_a = rt_hypotd_snf(controlAerobi_B.ub_[0],
      controlAerobi_B.Zgain_a);
    if (controlAerobi_B.ub_[0] >= 0.0) {
      controlAerobi_B.Zgain_a = -controlAerobi_B.Zgain_a;
    }

    if (fabs(controlAerobi_B.Zgain_a) < 1.0020841800044864E-292) {
      distorsioned = 0;

      // DiscreteFir: '<S104>/Hlp' incorporates:
      //   Lookup_n-D: '<S70>/1-D Lookup Table'
      //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
      //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

      o = 2;
      do {
        distorsioned++;
        controlAerobi_B.eulerZYX[1] *= 9.9792015476736E+291;
        controlAerobi_B.eulerZYX[2] *= 9.9792015476736E+291;
        controlAerobi_B.Zgain_a *= 9.9792015476736E+291;
        controlAerobi_B.t *= 9.9792015476736E+291;
      } while (!(fabs(controlAerobi_B.Zgain_a) >= 1.0020841800044864E-292));

      controlAerobi_B.Zgain_a = rt_hypotd_snf(controlAerobi_B.t, xnrm2_36Ruq5vk
        (controlAerobi_B.eulerZYX));
      if (controlAerobi_B.t >= 0.0) {
        controlAerobi_B.Zgain_a = -controlAerobi_B.Zgain_a;
      }

      controlAerobi_B.absxk = (controlAerobi_B.Zgain_a - controlAerobi_B.t) /
        controlAerobi_B.Zgain_a;
      controlAerobi_B.t = 1.0 / (controlAerobi_B.t - controlAerobi_B.Zgain_a);
      controlAerobi_B.eulerZYX[1] *= controlAerobi_B.t;
      controlAerobi_B.eulerZYX[2] *= controlAerobi_B.t;
      for (o = 1; o <= distorsioned; o++) {
        controlAerobi_B.Zgain_a *= 1.0020841800044864E-292;
      }

      controlAerobi_B.t = controlAerobi_B.Zgain_a;
    } else {
      controlAerobi_B.absxk = (controlAerobi_B.Zgain_a - controlAerobi_B.vbx[0])
        / controlAerobi_B.Zgain_a;
      controlAerobi_B.t = 1.0 / (controlAerobi_B.vbx[0] -
        controlAerobi_B.Zgain_a);
      controlAerobi_B.eulerZYX[1] *= controlAerobi_B.t;
      controlAerobi_B.eulerZYX[2] *= controlAerobi_B.t;

      // DiscreteFir: '<S104>/Hlp' incorporates:
      //   Lookup_n-D: '<S70>/1-D Lookup Table'
      //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
      //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

      o = 2;
      controlAerobi_B.t = controlAerobi_B.Zgain_a;
    }
  }

  controlAerobi_B.eulerZYX[0] = controlAerobi_B.t;
  o = 0;
  controlAerobi_B.t = 3.0 * fabs(controlAerobi_B.t) * 2.2204460492503131E-16;
  while ((o < 1) && (!(fabs(controlAerobi_B.eulerZYX[0]) <= controlAerobi_B.t)))
  {
    o = 1;
  }

  controlAerobi_B.Zgain_a = 0.0;
  if (controlAerobi_B.absxk != 0.0) {
    controlAerobi_B.t = ((controlAerobi_B.eulerZYX[1] * controlAerobi_B.ubx_d[1]
                          + controlAerobi_B.ubx_d[0]) +
                         controlAerobi_B.eulerZYX[2] * controlAerobi_B.ubx_d[2])
      * controlAerobi_B.absxk;
    if (controlAerobi_B.t != 0.0) {
      controlAerobi_B.ubx_d[0] -= controlAerobi_B.t;
    }
  }

  distorsioned = 1;
  while (distorsioned <= o) {
    controlAerobi_B.Zgain_a = controlAerobi_B.ubx_d[0];
    distorsioned = 2;
  }

  while (o > 0) {
    controlAerobi_B.Zgain_a /= controlAerobi_B.eulerZYX[0];
    o = 0;
  }

  // Gain: '<S9>/Gain'
  controlAerobi_B.Abs_a = controlAerobi_P.Gain_Gain_b5 *
    controlAerobi_B.Gain_po[2];

  // DiscreteFir: '<S104>/Hlp'
  for (o = 0; o < 1; o++) {
    r3 = o * 10;

    // Consume delay line and beginning of input samples
    controlAerobi_B.absxk = 0.0;
    r2 = 0;
    while (r2 < 1) {
      controlAerobi_B.absxk += controlAerobi_B.Add[2] *
        controlAerobi_P.Hlp_Coefficients[0];
      r2 = 1;
    }

    for (r2 = 0; r2 < 10; r2++) {
      controlAerobi_B.absxk += controlAerobi_DWork.Hlp_states[r3 + r2] *
        controlAerobi_P.Hlp_Coefficients[1 + r2];
    }

    controlAerobi_B.dyaw = controlAerobi_B.absxk;

    // Update delay line for next frame
    for (distorsioned = r3 + 8; distorsioned >= r3; distorsioned--) {
      controlAerobi_DWork.Hlp_states[1 + distorsioned] =
        controlAerobi_DWork.Hlp_states[distorsioned];
    }

    controlAerobi_DWork.Hlp_states[r3] = controlAerobi_B.Add[2];
  }

  // Product: '<S157>/Divide' incorporates:
  //   Constant: '<S157>/Constant'
  //   Constant: '<S157>/Constant1'
  //   DataTypeConversion: '<S157>/Data Type Conversion'
  //   Gain: '<S157>/Gain'
  //   Inport: '<Root>/I_RCinput'
  //   Sum: '<S157>/Add'

  controlAerobi_B.Product1_ew = (controlAerobi_P.Gain_Gain_n * (real_T)
    controlAerobi_U.I_RCinput._channel1 - controlAerobi_P.Constant_Value_k1) *
    controlAerobi_P.Constant1_Value_e;

  // Switch: '<S165>/Switch' incorporates:
  //   Abs: '<S165>/Abs'
  //   Constant: '<S165>/Constant'
  //   Constant: '<S168>/Constant'
  //   RelationalOperator: '<S168>/Compare'

  if (fabs(controlAerobi_B.Product1_ew) <
      controlAerobi_P.CompareToConstant_const) {
    controlAerobi_B.Product1_ew = controlAerobi_P.Constant_Value_c;
  }

  // End of Switch: '<S165>/Switch'

  // Saturate: '<S157>/Saturation2'
  if (controlAerobi_B.Product1_ew > controlAerobi_P.Saturation2_UpperSat_l) {
    controlAerobi_B.absxk = controlAerobi_P.Saturation2_UpperSat_l;
  } else if (controlAerobi_B.Product1_ew <
             controlAerobi_P.Saturation2_LowerSat_h) {
    controlAerobi_B.absxk = controlAerobi_P.Saturation2_LowerSat_h;
  } else {
    controlAerobi_B.absxk = controlAerobi_B.Product1_ew;
  }

  // End of Saturate: '<S157>/Saturation2'

  // Gain: '<S11>/Gain4'
  controlAerobi_B.Product1_a1 = controlAerobi_P.Gain4_Gain_f *
    controlAerobi_B.absxk;

  // Product: '<S157>/Divide1' incorporates:
  //   Constant: '<S157>/Constant1'
  //   Constant: '<S157>/Constant2'
  //   DataTypeConversion: '<S157>/Data Type Conversion'
  //   Gain: '<S157>/Gain1'
  //   Gain: '<S157>/Gain4'
  //   Inport: '<Root>/I_RCinput'
  //   Sum: '<S157>/Add1'

  controlAerobi_B.Product1_ew = (controlAerobi_P.Gain1_Gain_f * (real_T)
    controlAerobi_U.I_RCinput._channel2 - controlAerobi_P.Constant2_Value_f) *
    (controlAerobi_P.Gain4_Gain_b * controlAerobi_P.Constant1_Value_e);

  // Switch: '<S164>/Switch' incorporates:
  //   Abs: '<S164>/Abs'
  //   Constant: '<S164>/Constant'
  //   Constant: '<S167>/Constant'
  //   RelationalOperator: '<S167>/Compare'

  if (fabs(controlAerobi_B.Product1_ew) <
      controlAerobi_P.CompareToConstant_const_c) {
    controlAerobi_B.Product1_ew = controlAerobi_P.Constant_Value_h;
  }

  // End of Switch: '<S164>/Switch'

  // Saturate: '<S157>/Saturation1'
  if (controlAerobi_B.Product1_ew > controlAerobi_P.Saturation1_UpperSat_n) {
    controlAerobi_B.t = controlAerobi_P.Saturation1_UpperSat_n;
  } else if (controlAerobi_B.Product1_ew <
             controlAerobi_P.Saturation1_LowerSat_b) {
    controlAerobi_B.t = controlAerobi_P.Saturation1_LowerSat_b;
  } else {
    controlAerobi_B.t = controlAerobi_B.Product1_ew;
  }

  // End of Saturate: '<S157>/Saturation1'

  // Gain: '<S11>/Gain3'
  controlAerobi_B.Gain3_l = controlAerobi_P.Gain3_Gain * controlAerobi_B.t;

  // Gain: '<S157>/Gain5' incorporates:
  //   Constant: '<S157>/Constant6'
  //   Constant: '<S157>/Constant7'
  //   DataTypeConversion: '<S157>/Data Type Conversion'
  //   Gain: '<S157>/Gain3'
  //   Inport: '<Root>/I_RCinput'
  //   Product: '<S157>/Divide3'
  //   Sum: '<S157>/Add3'

  controlAerobi_B.Product1_ew = (controlAerobi_P.Gain3_Gain_m * (real_T)
    controlAerobi_U.I_RCinput._channel4 - controlAerobi_P.Constant6_Value) *
    controlAerobi_P.Constant7_Value * controlAerobi_P.Gain5_Gain;

  // Switch: '<S166>/Switch' incorporates:
  //   Abs: '<S166>/Abs'
  //   Constant: '<S166>/Constant'
  //   Constant: '<S169>/Constant'
  //   RelationalOperator: '<S169>/Compare'

  if (fabs(controlAerobi_B.Product1_ew) <
      controlAerobi_P.CompareToConstant_const_d) {
    controlAerobi_B.r_x_idx_0 = controlAerobi_P.Constant_Value_m;
  } else {
    controlAerobi_B.r_x_idx_0 = controlAerobi_B.Product1_ew;
  }

  // End of Switch: '<S166>/Switch'

  // Gain: '<S11>/Gain1'
  controlAerobi_B.Product1_ew = controlAerobi_P.Gain1_Gain_l *
    controlAerobi_B.r_x_idx_0;

  // MATLAB Function: '<S11>/Calculate_rotation_matrix_des'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking/Generate_attitude_refereces/Calculate_rotation_matrix_des': '<S13>:1' 
  // '<S13>:1:3'
  controlAerobi_B.Sum_c = cos(controlAerobi_B.Product1_ew);
  controlAerobi_B.Abs_g = cos(controlAerobi_B.Gain3_l);
  controlAerobi_B.R_d_m[0] = controlAerobi_B.Abs_g * controlAerobi_B.Sum_c;
  controlAerobi_B.Gain7 = cos(controlAerobi_B.Product1_a1);
  controlAerobi_B.Gain3_l = sin(controlAerobi_B.Gain3_l);
  controlAerobi_B.Product1_a1 = sin(controlAerobi_B.Product1_a1);
  controlAerobi_B.Product1_ew = sin(controlAerobi_B.Product1_ew);
  controlAerobi_B.rtb_R_d_m_tmp = controlAerobi_B.Product1_a1 *
    controlAerobi_B.Gain3_l;
  controlAerobi_B.R_d_m[3] = controlAerobi_B.rtb_R_d_m_tmp *
    controlAerobi_B.Sum_c + -controlAerobi_B.Gain7 * controlAerobi_B.Product1_ew;
  controlAerobi_B.rtb_R_d_m_tmp_j = controlAerobi_B.Gain7 *
    controlAerobi_B.Gain3_l;
  controlAerobi_B.R_d_m[6] = controlAerobi_B.rtb_R_d_m_tmp_j *
    controlAerobi_B.Sum_c + controlAerobi_B.Product1_a1 *
    controlAerobi_B.Product1_ew;
  controlAerobi_B.R_d_m[1] = controlAerobi_B.Abs_g * controlAerobi_B.Product1_ew;
  controlAerobi_B.R_d_m[4] = controlAerobi_B.rtb_R_d_m_tmp *
    controlAerobi_B.Product1_ew + controlAerobi_B.Gain7 * controlAerobi_B.Sum_c;
  controlAerobi_B.R_d_m[7] = controlAerobi_B.rtb_R_d_m_tmp_j *
    controlAerobi_B.Product1_ew + -controlAerobi_B.Product1_a1 *
    controlAerobi_B.Sum_c;
  controlAerobi_B.R_d_m[2] = -controlAerobi_B.Gain3_l;
  controlAerobi_B.R_d_m[5] = controlAerobi_B.Product1_a1 * controlAerobi_B.Abs_g;
  controlAerobi_B.R_d_m[8] = controlAerobi_B.Gain7 * controlAerobi_B.Abs_g;

  // MATLAB Function: '<S11>/MATLAB Function'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking/Generate_attitude_refereces/MATLAB Function': '<S14>:1' 
  // '<S14>:1:35'
  // '<S14>:1:32'
  // '<S14>:1:30'
  // '<S14>:1:27'
  // '<S14>:1:26'
  if ((!controlAerobi_DWork.x_k_not_empty_my) ||
      (!controlAerobi_DWork.P_k_not_empty_ol)) {
    // '<S14>:1:7'
    // '<S14>:1:8'
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_fc[i] = 0.0;
    }

    controlAerobi_DWork.x_k_not_empty_my = true;

    // '<S14>:1:9'
    memset(&controlAerobi_DWork.P_k_a[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      i = o + 6 * o;
      controlAerobi_DWork.P_k_a[i] = 1.0;
    }

    controlAerobi_DWork.P_k_not_empty_ol = true;
  } else {
    // '<S14>:1:19'
    // '<S14>:1:20'
    controlAerobi_B.vbx[0] = controlAerobi_DWork.x_k_fc[0];
    controlAerobi_B.vbx[1] = controlAerobi_DWork.x_k_fc[2];
    controlAerobi_B.vbx[2] = controlAerobi_DWork.x_k_fc[4];

    // '<S14>:1:26'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (r2 = 0; r2 < 6; r2++) {
      controlAerobi_B.dF[r2 + 6 * r2] = b_5[r2];
    }

    // '<S14>:1:27'
    for (i = 0; i < 9; i++) {
      controlAerobi_B.R_n[i] = 0;
    }

    controlAerobi_B.R_n[0] = 10;
    controlAerobi_B.R_n[4] = 10;
    controlAerobi_B.R_n[8] = 10;

    // DiscreteFir: '<S104>/Hlp' incorporates:
    //   Lookup_n-D: '<S70>/1-D Lookup Table'
    //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
    //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

    o = 3;

    // '<S14>:1:30'
    for (i = 0; i < 6; i++) {
      controlAerobi_B.a[i] = 0.0;
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.a[i] += a_4[6 * distorsioned + i] *
          controlAerobi_DWork.x_k_fc[distorsioned];
      }
    }

    // '<S14>:1:32'
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_fc[i] = controlAerobi_B.a[i];
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.dF_k[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dF_k[o] = a_4[6 * r2 + i] * controlAerobi_DWork.P_k_a
            [6 * distorsioned + r2] + controlAerobi_B.dF_k[6 * distorsioned + i];
        }
      }
    }

    // '<S14>:1:35'
    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.dF_k[6 * r2 + i] * c_b_3[6 *
            distorsioned + r2];
        }

        controlAerobi_DWork.P_k_a[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] + controlAerobi_B.Gain7;
      }

      for (distorsioned = 0; distorsioned < 3; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.y[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.y[o] = controlAerobi_DWork.P_k_a[6 * r2 + i] * (real_T)
            b_b_5[6 * distorsioned + r2] + controlAerobi_B.y[6 * distorsioned +
            i];
        }
      }
    }

    for (i = 0; i < 3; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 3 * distorsioned;
        controlAerobi_B.dK_k[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dK_k[o] = (real_T)b_a_4[3 * r2 + i] *
            controlAerobi_DWork.P_k_a[6 * distorsioned + r2] +
            controlAerobi_B.dK_k[3 * distorsioned + i];
        }
      }

      for (distorsioned = 0; distorsioned < 3; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.dK_k[3 * r2 + i] * (real_T)
            b_b_5[6 * distorsioned + r2];
        }

        controlAerobi_B.P_ui[i + 3 * distorsioned] = (real_T)
          controlAerobi_B.R_n[3 * distorsioned + i] + controlAerobi_B.Gain7;
      }
    }

    distorsioned = 0;
    r2 = 1;
    r3 = 2;
    controlAerobi_B.Product1_a1 = fabs(controlAerobi_B.P_ui[0]);
    controlAerobi_B.Product1_ew = fabs(controlAerobi_B.P_ui[1]);
    if (controlAerobi_B.Product1_ew > controlAerobi_B.Product1_a1) {
      controlAerobi_B.Product1_a1 = controlAerobi_B.Product1_ew;
      distorsioned = 1;
      r2 = 0;
    }

    if (fabs(controlAerobi_B.P_ui[2]) > controlAerobi_B.Product1_a1) {
      distorsioned = 2;
      r2 = 1;
      r3 = 0;
    }

    controlAerobi_B.P_ui[r2] /= controlAerobi_B.P_ui[distorsioned];
    controlAerobi_B.P_ui[r3] /= controlAerobi_B.P_ui[distorsioned];
    controlAerobi_B.P_ui[3 + r2] -= controlAerobi_B.P_ui[3 + distorsioned] *
      controlAerobi_B.P_ui[r2];
    controlAerobi_B.P_ui[3 + r3] -= controlAerobi_B.P_ui[3 + distorsioned] *
      controlAerobi_B.P_ui[r3];
    controlAerobi_B.P_ui[6 + r2] -= controlAerobi_B.P_ui[6 + distorsioned] *
      controlAerobi_B.P_ui[r2];
    controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[6 + distorsioned] *
      controlAerobi_B.P_ui[r3];
    if (fabs(controlAerobi_B.P_ui[3 + r3]) > fabs(controlAerobi_B.P_ui[3 + r2]))
    {
      o = r2 + 1;
      r2 = r3;
      r3 = o - 1;
    }

    controlAerobi_B.P_ui[3 + r3] /= controlAerobi_B.P_ui[3 + r2];
    controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[3 + r3] *
      controlAerobi_B.P_ui[6 + r2];
    for (o = 0; o < 6; o++) {
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[o] /
        controlAerobi_B.P_ui[distorsioned];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[6 + o] - controlAerobi_B.dK_k
        [6 * distorsioned + o] * controlAerobi_B.P_ui[3 + distorsioned];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[12 + o] -
        controlAerobi_B.dK_k[6 * distorsioned + o] * controlAerobi_B.P_ui[6 +
        distorsioned];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] /
        controlAerobi_B.P_ui[3 + r2];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] -
        controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[6 + r2];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] /
        controlAerobi_B.P_ui[6 + r3];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] -
        controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[3 + r3];
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
        controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[r3];
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
        controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[r2];
    }

    // '<S14>:1:37'
    // '<S14>:1:39'
    controlAerobi_B.Product1_ew = controlAerobi_B.absxk - controlAerobi_B.vbx[0];
    controlAerobi_B.Product1_a1 = controlAerobi_B.t - controlAerobi_B.vbx[1];
    controlAerobi_B.Sum_c = controlAerobi_B.r_x_idx_0 - controlAerobi_B.vbx[2];
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_fc[i] += (controlAerobi_B.dK_k[i + 6] *
        controlAerobi_B.Product1_a1 + controlAerobi_B.dK_k[i] *
        controlAerobi_B.Product1_ew) + controlAerobi_B.dK_k[i + 12] *
        controlAerobi_B.Sum_c;
    }

    // '<S14>:1:41'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      r3 = o + 6 * o;
      controlAerobi_B.dF[r3] = 1.0;
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.dF_k[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] - (((real_T)b_a_4[3 * distorsioned + 1] *
          controlAerobi_B.dK_k[i + 6] + (real_T)b_a_4[3 * distorsioned] *
          controlAerobi_B.dK_k[i]) + (real_T)b_a_4[3 * distorsioned + 2] *
          controlAerobi_B.dK_k[i + 12]);
      }

      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        r3 = i + 6 * distorsioned;
        controlAerobi_B.dQ[r3] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dQ[r3] = controlAerobi_B.dF_k[6 * r2 + i] *
            controlAerobi_DWork.P_k_a[6 * distorsioned + r2] +
            controlAerobi_B.dQ[6 * distorsioned + i];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_DWork.P_k_a[distorsioned + 6 * i] = controlAerobi_B.dQ[6 *
          i + distorsioned];
      }
    }
  }

  // Gain: '<S11>/Gain2' incorporates:
  //   MATLAB Function: '<S11>/MATLAB Function'

  // '<S14>:1:44'
  // '<S14>:1:45'
  // '<S14>:1:46'
  // '<S14>:1:48'
  controlAerobi_B.ub_[0] = (-sin(controlAerobi_B.t) *
    controlAerobi_DWork.x_k_fc[5] + controlAerobi_DWork.x_k_fc[1]) *
    controlAerobi_P.Gain2_Gain_b;

  // MATLAB Function: '<S11>/MATLAB Function'
  controlAerobi_B.Product1_ew = cos(controlAerobi_B.t);
  controlAerobi_B.Product1_a1 = cos(controlAerobi_B.absxk);
  controlAerobi_B.Sum_c = sin(controlAerobi_B.absxk);

  // Gain: '<S11>/Gain2' incorporates:
  //   MATLAB Function: '<S11>/MATLAB Function'

  controlAerobi_B.ub_[1] = (controlAerobi_B.Product1_ew * controlAerobi_B.Sum_c *
    controlAerobi_DWork.x_k_fc[5] + controlAerobi_B.Product1_a1 *
    controlAerobi_DWork.x_k_fc[3]) * controlAerobi_P.Gain2_Gain_b;
  controlAerobi_B.ub_[2] = (controlAerobi_B.Product1_ew *
    controlAerobi_B.Product1_a1 * controlAerobi_DWork.x_k_fc[5] +
    -controlAerobi_B.Sum_c * controlAerobi_DWork.x_k_fc[3]) *
    controlAerobi_P.Gain2_Gain_b;

  // MATLAB Function: '<S11>/calculate_dOmega_d'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking/Generate_attitude_refereces/calculate_dOmega_d': '<S15>:1' 
  // '<S15>:1:35'
  // '<S15>:1:32'
  // '<S15>:1:30'
  // '<S15>:1:27'
  // '<S15>:1:26'
  if ((!controlAerobi_DWork.x_k_not_empty_mk) ||
      (!controlAerobi_DWork.P_k_not_empty_f)) {
    // '<S15>:1:7'
    // '<S15>:1:8'
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_a1[i] = 0.0;
    }

    controlAerobi_DWork.x_k_not_empty_mk = true;

    // '<S15>:1:9'
    memset(&controlAerobi_DWork.P_k_c[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      i = o + 6 * o;
      controlAerobi_DWork.P_k_c[i] = 1.0;
    }

    controlAerobi_DWork.P_k_not_empty_f = true;
  } else {
    // '<S15>:1:20'
    controlAerobi_B.vbx[0] = controlAerobi_DWork.x_k_a1[0];
    controlAerobi_B.vbx[1] = controlAerobi_DWork.x_k_a1[2];
    controlAerobi_B.vbx[2] = controlAerobi_DWork.x_k_a1[4];

    // '<S15>:1:26'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (r2 = 0; r2 < 6; r2++) {
      controlAerobi_B.dF[r2 + 6 * r2] = b_6[r2];
    }

    // '<S15>:1:27'
    for (i = 0; i < 9; i++) {
      controlAerobi_B.R_[i] = 0.0;
    }

    controlAerobi_B.R_[0] = 0.01;
    controlAerobi_B.R_[4] = 0.01;
    controlAerobi_B.R_[8] = 0.01;

    // DiscreteFir: '<S104>/Hlp' incorporates:
    //   Lookup_n-D: '<S70>/1-D Lookup Table'
    //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
    //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

    o = 3;

    // '<S15>:1:30'
    for (i = 0; i < 6; i++) {
      controlAerobi_B.a[i] = 0.0;
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.a[i] += a_5[6 * distorsioned + i] *
          controlAerobi_DWork.x_k_a1[distorsioned];
      }
    }

    // '<S15>:1:32'
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_a1[i] = controlAerobi_B.a[i];
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.dF_k[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dF_k[o] = a_5[6 * r2 + i] * controlAerobi_DWork.P_k_c
            [6 * distorsioned + r2] + controlAerobi_B.dF_k[6 * distorsioned + i];
        }
      }
    }

    // '<S15>:1:35'
    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.dF_k[6 * r2 + i] * c_b_4[6 *
            distorsioned + r2];
        }

        controlAerobi_DWork.P_k_c[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] + controlAerobi_B.Gain7;
      }

      for (distorsioned = 0; distorsioned < 3; distorsioned++) {
        o = i + 6 * distorsioned;
        controlAerobi_B.y[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.y[o] = controlAerobi_DWork.P_k_c[6 * r2 + i] * (real_T)
            b_b_6[6 * distorsioned + r2] + controlAerobi_B.y[6 * distorsioned +
            i];
        }
      }
    }

    for (i = 0; i < 3; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        o = i + 3 * distorsioned;
        controlAerobi_B.dK_k[o] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dK_k[o] = (real_T)b_a_5[3 * r2 + i] *
            controlAerobi_DWork.P_k_c[6 * distorsioned + r2] +
            controlAerobi_B.dK_k[3 * distorsioned + i];
        }
      }

      for (distorsioned = 0; distorsioned < 3; distorsioned++) {
        controlAerobi_B.Gain7 = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.Gain7 += controlAerobi_B.dK_k[3 * r2 + i] * (real_T)
            b_b_6[6 * distorsioned + r2];
        }

        controlAerobi_B.P_ui[i + 3 * distorsioned] = controlAerobi_B.R_[3 *
          distorsioned + i] + controlAerobi_B.Gain7;
      }
    }

    distorsioned = 0;
    r2 = 1;
    r3 = 2;
    controlAerobi_B.Product1_a1 = fabs(controlAerobi_B.P_ui[0]);
    controlAerobi_B.Product1_ew = fabs(controlAerobi_B.P_ui[1]);
    if (controlAerobi_B.Product1_ew > controlAerobi_B.Product1_a1) {
      controlAerobi_B.Product1_a1 = controlAerobi_B.Product1_ew;
      distorsioned = 1;
      r2 = 0;
    }

    if (fabs(controlAerobi_B.P_ui[2]) > controlAerobi_B.Product1_a1) {
      distorsioned = 2;
      r2 = 1;
      r3 = 0;
    }

    controlAerobi_B.P_ui[r2] /= controlAerobi_B.P_ui[distorsioned];
    controlAerobi_B.P_ui[r3] /= controlAerobi_B.P_ui[distorsioned];
    controlAerobi_B.P_ui[3 + r2] -= controlAerobi_B.P_ui[3 + distorsioned] *
      controlAerobi_B.P_ui[r2];
    controlAerobi_B.P_ui[3 + r3] -= controlAerobi_B.P_ui[3 + distorsioned] *
      controlAerobi_B.P_ui[r3];
    controlAerobi_B.P_ui[6 + r2] -= controlAerobi_B.P_ui[6 + distorsioned] *
      controlAerobi_B.P_ui[r2];
    controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[6 + distorsioned] *
      controlAerobi_B.P_ui[r3];
    if (fabs(controlAerobi_B.P_ui[3 + r3]) > fabs(controlAerobi_B.P_ui[3 + r2]))
    {
      o = r2 + 1;
      r2 = r3;
      r3 = o - 1;
    }

    controlAerobi_B.P_ui[3 + r3] /= controlAerobi_B.P_ui[3 + r2];
    controlAerobi_B.P_ui[6 + r3] -= controlAerobi_B.P_ui[3 + r3] *
      controlAerobi_B.P_ui[6 + r2];
    for (o = 0; o < 6; o++) {
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[o] /
        controlAerobi_B.P_ui[distorsioned];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[6 + o] - controlAerobi_B.dK_k
        [6 * distorsioned + o] * controlAerobi_B.P_ui[3 + distorsioned];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.y[12 + o] -
        controlAerobi_B.dK_k[6 * distorsioned + o] * controlAerobi_B.P_ui[6 +
        distorsioned];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] /
        controlAerobi_B.P_ui[3 + r2];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] -
        controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[6 + r2];
      i = o + 6 * r3;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r3 + o] /
        controlAerobi_B.P_ui[6 + r3];
      i = o + 6 * r2;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * r2 + o] -
        controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[3 + r3];
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
        controlAerobi_B.dK_k[6 * r3 + o] * controlAerobi_B.P_ui[r3];
      i = o + 6 * distorsioned;
      controlAerobi_B.dK_k[i] = controlAerobi_B.dK_k[6 * distorsioned + o] -
        controlAerobi_B.dK_k[6 * r2 + o] * controlAerobi_B.P_ui[r2];
    }

    // '<S15>:1:37'
    // '<S15>:1:39'
    controlAerobi_B.Product1_ew = controlAerobi_B.ub_[0] - controlAerobi_B.vbx[0];
    controlAerobi_B.Product1_a1 = controlAerobi_B.ub_[1] - controlAerobi_B.vbx[1];
    controlAerobi_B.Sum_c = controlAerobi_B.ub_[2] - controlAerobi_B.vbx[2];
    for (i = 0; i < 6; i++) {
      controlAerobi_DWork.x_k_a1[i] += (controlAerobi_B.dK_k[i + 6] *
        controlAerobi_B.Product1_a1 + controlAerobi_B.dK_k[i] *
        controlAerobi_B.Product1_ew) + controlAerobi_B.dK_k[i + 12] *
        controlAerobi_B.Sum_c;
    }

    // '<S15>:1:41'
    memset(&controlAerobi_B.dF[0], 0, 36U * sizeof(real_T));
    for (o = 0; o < 6; o++) {
      r3 = o + 6 * o;
      controlAerobi_B.dF[r3] = 1.0;
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_B.dF_k[i + 6 * distorsioned] = controlAerobi_B.dF[6 *
          distorsioned + i] - (((real_T)b_a_5[3 * distorsioned + 1] *
          controlAerobi_B.dK_k[i + 6] + (real_T)b_a_5[3 * distorsioned] *
          controlAerobi_B.dK_k[i]) + (real_T)b_a_5[3 * distorsioned + 2] *
          controlAerobi_B.dK_k[i + 12]);
      }

      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        r3 = i + 6 * distorsioned;
        controlAerobi_B.dQ[r3] = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          controlAerobi_B.dQ[r3] = controlAerobi_B.dF_k[6 * r2 + i] *
            controlAerobi_DWork.P_k_c[6 * distorsioned + r2] +
            controlAerobi_B.dQ[6 * distorsioned + i];
        }
      }
    }

    for (i = 0; i < 6; i++) {
      for (distorsioned = 0; distorsioned < 6; distorsioned++) {
        controlAerobi_DWork.P_k_c[distorsioned + 6 * i] = controlAerobi_B.dQ[6 *
          i + distorsioned];
      }
    }
  }

  // MATLAB Function: '<S9>/attitude_geometric_control' incorporates:
  //   Constant: '<S94>/c2'
  //   Constant: '<S94>/k_I'
  //   Constant: '<S94>/k_R'
  //   Constant: '<S94>/sat_R'

  // '<S15>:1:44'
  controlAerobi_B.ubx_d[0] = controlAerobi_P.k_I_Value[0];
  controlAerobi_B.ubx_d[1] = controlAerobi_P.k_I_Value[1];
  controlAerobi_B.ubx_d[2] = controlAerobi_P.k_I_Value[2];

  // MATLAB Function 'Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking/attitude_geometric_control': '<S12>:1' 
  if ((!controlAerobi_DWork.e_I_not_empty) ||
      (!controlAerobi_DWork.M_not_empty_f)) {
    // '<S12>:1:7'
    // '<S12>:1:8'
    controlAerobi_DWork.e_I_not_empty = true;

    // '<S12>:1:9'
    controlAerobi_DWork.e_I[0] = 0.0;
    controlAerobi_DWork.M_g[0] = 0.0;
    controlAerobi_DWork.e_I[1] = 0.0;
    controlAerobi_DWork.M_g[1] = 0.0;
    controlAerobi_DWork.e_I[2] = 0.0;
    controlAerobi_DWork.M_g[2] = 0.0;
    controlAerobi_DWork.M_not_empty_f = true;
  }

  // '<S12>:1:12'
  controlAerobi_B.Product1_ew = cos(controlAerobi_B.Abs_a);
  controlAerobi_B.R_[0] = controlAerobi_B.TSamp_hv * controlAerobi_B.Product1_ew;
  controlAerobi_B.Abs_a = sin(controlAerobi_B.Abs_a);
  controlAerobi_B.R_[3] = controlAerobi_B.y_k_idx_1 *
    controlAerobi_B.Product1_ew + -cos(controlAerobi_B.Gain_po[0]) *
    controlAerobi_B.Abs_a;
  controlAerobi_B.R_[6] = controlAerobi_B.y_k_idx_0 *
    controlAerobi_B.Product1_ew + controlAerobi_B.Sum_f * controlAerobi_B.Abs_a;
  controlAerobi_B.R_[1] = controlAerobi_B.TSamp_hv * controlAerobi_B.Abs_a;
  controlAerobi_B.R_[4] = controlAerobi_B.y_k_idx_1 * controlAerobi_B.Abs_a +
    controlAerobi_B.TSamp_iz * controlAerobi_B.Product1_ew;
  controlAerobi_B.R_[7] = controlAerobi_B.y_k_idx_0 * controlAerobi_B.Abs_a +
    -sin(controlAerobi_B.Gain_po[0]) * controlAerobi_B.Product1_ew;
  controlAerobi_B.R_[2] = -sin(controlAerobi_B.Gain_po[1]);
  controlAerobi_B.R_[5] = controlAerobi_B.Abs_k;
  controlAerobi_B.R_[8] = controlAerobi_B.ubx_tmp_j;

  // '<S12>:1:17'
  for (i = 0; i < 3; i++) {
    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      r2 = i + 3 * distorsioned;
      controlAerobi_B.P_ui[r2] = 0.0;
      controlAerobi_B.d_a[r2] = 0.0;
      o = 3 * distorsioned + i;
      controlAerobi_B.P_ui[r2] = controlAerobi_B.P_ui[o] +
        controlAerobi_B.R_d_m[3 * i] * controlAerobi_B.R_[3 * distorsioned];
      controlAerobi_B.d_a[r2] = controlAerobi_B.d_a[o] + controlAerobi_B.R_[3 *
        i] * controlAerobi_B.R_d_m[3 * distorsioned];
      o = 3 * i + 1;
      r3 = 3 * distorsioned + 1;
      controlAerobi_B.P_ui[r2] = controlAerobi_B.R_d_m[o] *
        controlAerobi_B.R_[r3] + controlAerobi_B.P_ui[3 * distorsioned + i];
      controlAerobi_B.d_a[r2] = controlAerobi_B.R_[o] * controlAerobi_B.R_d_m[r3]
        + controlAerobi_B.d_a[3 * distorsioned + i];
      o = 3 * i + 2;
      r3 = 3 * distorsioned + 2;
      controlAerobi_B.P_ui[r2] = controlAerobi_B.R_d_m[o] *
        controlAerobi_B.R_[r3] + controlAerobi_B.P_ui[3 * distorsioned + i];
      controlAerobi_B.d_a[r2] = controlAerobi_B.R_[o] * controlAerobi_B.R_d_m[r3]
        + controlAerobi_B.d_a[3 * distorsioned + i];
    }
  }

  for (i = 0; i < 3; i++) {
    controlAerobi_B.Re_R[3 * i] = (controlAerobi_B.P_ui[3 * i] -
      controlAerobi_B.d_a[3 * i]) * 0.5;
    distorsioned = 3 * i + 1;
    controlAerobi_B.Re_R[1 + 3 * i] = (controlAerobi_B.P_ui[distorsioned] -
      controlAerobi_B.d_a[distorsioned]) * 0.5;
    distorsioned = 3 * i + 2;
    controlAerobi_B.Re_R[2 + 3 * i] = (controlAerobi_B.P_ui[distorsioned] -
      controlAerobi_B.d_a[distorsioned]) * 0.5;
  }

  // '<S12>:1:18'
  controlAerobi_B.vbx[0] = controlAerobi_B.Re_R[5];
  controlAerobi_B.vbx[1] = controlAerobi_B.Re_R[6];
  controlAerobi_B.vbx[2] = controlAerobi_B.Re_R[1];

  // '<S12>:1:21'
  // '<S12>:1:22'
  controlAerobi_B.P_ui_o[0] = controlAerobi_B.Add[1];
  controlAerobi_B.P_ui_o[1] = controlAerobi_B.Add[0];
  controlAerobi_B.P_ui_o[2] = controlAerobi_B.dyaw;
  for (i = 0; i < 3; i++) {
    controlAerobi_B.rtb_Gain_po_l[i] = 0.0;
    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      r2 = i + 3 * distorsioned;
      controlAerobi_B.d_a[r2] = 0.0;
      controlAerobi_B.d_a[r2] = controlAerobi_B.d_a[3 * distorsioned + i] +
        controlAerobi_B.R_[3 * i] * controlAerobi_B.R_d_m[3 * distorsioned];
      controlAerobi_B.d_a[r2] = controlAerobi_B.R_[3 * i + 1] *
        controlAerobi_B.R_d_m[3 * distorsioned + 1] + controlAerobi_B.d_a[3 *
        distorsioned + i];
      controlAerobi_B.d_a[r2] = controlAerobi_B.R_[3 * i + 2] *
        controlAerobi_B.R_d_m[3 * distorsioned + 2] + controlAerobi_B.d_a[3 *
        distorsioned + i];
      controlAerobi_B.rtb_Gain_po_l[i] += controlAerobi_B.d_a[3 * distorsioned +
        i] * controlAerobi_B.ub_[distorsioned];
    }

    controlAerobi_B.eulerZYX[i] = controlAerobi_B.P_ui_o[i] -
      controlAerobi_B.rtb_Gain_po_l[i];
  }

  if (controlAerobi_B.Compare) {
    // '<S12>:1:25'
    // '<S12>:1:26'
    for (i = 0; i < 9; i++) {
      controlAerobi_B.Re_R[i] = 0.0;
    }

    controlAerobi_B.Re_R[0] = controlAerobi_P.c2_Value[0];
    controlAerobi_B.Re_R[4] = controlAerobi_P.c2_Value[1];
    controlAerobi_B.Re_R[8] = controlAerobi_P.c2_Value[2];

    // '<S12>:1:27'
    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      controlAerobi_DWork.e_I[distorsioned] =
        (((controlAerobi_B.Re_R[distorsioned + 3] * controlAerobi_B.vbx[1] +
           controlAerobi_B.Re_R[distorsioned] * controlAerobi_B.vbx[0]) +
          controlAerobi_B.Re_R[distorsioned + 6] * controlAerobi_B.vbx[2]) +
         controlAerobi_B.eulerZYX[distorsioned]) * 0.5 * 0.0025 -
        controlAerobi_DWork.e_I[distorsioned];

      // '<S12>:1:27'
      if ((controlAerobi_DWork.M_g[distorsioned] >
           controlAerobi_P.sat_R_Value[distorsioned]) ||
          (controlAerobi_DWork.M_g[distorsioned] <
           -controlAerobi_P.sat_R_Value[distorsioned])) {
        // '<S12>:1:28'
        // '<S12>:1:29'
        controlAerobi_B.ubx_d[distorsioned] = 0.0;
      }
    }
  } else {
    // '<S12>:1:33'
    controlAerobi_DWork.e_I[0] = 0.0;
    controlAerobi_DWork.e_I[1] = 0.0;
    controlAerobi_DWork.e_I[2] = 0.0;
  }

  // '<S12>:1:41'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.r2[i] = 0.0;
    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      r2 = i + 3 * distorsioned;
      controlAerobi_B.d_a[r2] = 0.0;
      controlAerobi_B.d_a[r2] = controlAerobi_B.d_a[3 * distorsioned + i] +
        controlAerobi_B.R_[3 * i] * controlAerobi_B.R_d_m[3 * distorsioned];
      controlAerobi_B.d_a[r2] = controlAerobi_B.R_[3 * i + 1] *
        controlAerobi_B.R_d_m[3 * distorsioned + 1] + controlAerobi_B.d_a[3 *
        distorsioned + i];
      controlAerobi_B.d_a[r2] = controlAerobi_B.R_[3 * i + 2] *
        controlAerobi_B.R_d_m[3 * distorsioned + 2] + controlAerobi_B.d_a[3 *
        distorsioned + i];
      controlAerobi_B.r2[i] += controlAerobi_B.d_a[3 * distorsioned + i] *
        controlAerobi_B.ub_[distorsioned];
    }
  }

  // '<S12>:1:42'
  // '<S12>:1:47'
  for (i = 0; i < 9; i++) {
    controlAerobi_B.Re_R[i] = 0.0;
  }

  controlAerobi_B.Re_R[0] = controlAerobi_P.k_R_Value[0];
  controlAerobi_B.Re_R[4] = controlAerobi_P.k_R_Value[1];
  controlAerobi_B.Re_R[8] = controlAerobi_P.k_R_Value[2];

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 3;

  // MATLAB Function: '<S9>/attitude_geometric_control' incorporates:
  //   Constant: '<S94>/k_Omega'

  for (i = 0; i < 9; i++) {
    controlAerobi_B.P_ui[i] = 0.0;
  }

  controlAerobi_B.P_ui[0] = controlAerobi_P.k_Omega_Value[0];
  controlAerobi_B.P_ui[4] = controlAerobi_P.k_Omega_Value[1];
  controlAerobi_B.P_ui[8] = controlAerobi_P.k_Omega_Value[2];

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 3;

  // MATLAB Function: '<S9>/attitude_geometric_control'
  for (i = 0; i < 9; i++) {
    controlAerobi_B.d_a[i] = 0.0;
  }

  controlAerobi_B.d_a[0] = controlAerobi_B.ubx_d[0];
  controlAerobi_B.d_a[4] = controlAerobi_B.ubx_d[1];
  controlAerobi_B.d_a[8] = controlAerobi_B.ubx_d[2];

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 3;

  // MATLAB Function: '<S9>/attitude_geometric_control'
  for (i = 0; i < 3; i++) {
    controlAerobi_B.Re_R_l[3 * i] = -controlAerobi_B.Re_R[3 * i];
    controlAerobi_B.Re_R_l[1 + 3 * i] = -controlAerobi_B.Re_R[3 * i + 1];
    controlAerobi_B.Re_R_l[2 + 3 * i] = -controlAerobi_B.Re_R[3 * i + 2];
  }

  controlAerobi_B.Re_R[0] = 0.0;
  controlAerobi_B.Re_R[3] = -controlAerobi_B.r2[2];
  controlAerobi_B.Re_R[6] = controlAerobi_B.r2[1];
  controlAerobi_B.Re_R[1] = controlAerobi_B.r2[2];
  controlAerobi_B.Re_R[4] = 0.0;
  controlAerobi_B.Re_R[7] = -controlAerobi_B.r2[0];
  controlAerobi_B.Re_R[2] = -controlAerobi_B.r2[1];
  controlAerobi_B.Re_R[5] = controlAerobi_B.r2[0];
  controlAerobi_B.Re_R[8] = 0.0;

  // Gain: '<S11>/Gain' incorporates:
  //   MATLAB Function: '<S11>/calculate_dOmega_d'

  controlAerobi_B.r2[0] = controlAerobi_P.Gain_Gain_n5 *
    controlAerobi_DWork.x_k_a1[1];
  controlAerobi_B.r2[1] = controlAerobi_P.Gain_Gain_n5 *
    controlAerobi_DWork.x_k_a1[3];
  controlAerobi_B.r2[2] = controlAerobi_P.Gain_Gain_n5 *
    controlAerobi_DWork.x_k_a1[5];

  // MATLAB Function: '<S9>/attitude_geometric_control' incorporates:
  //   Constant: '<S94>/J'
  //   Constant: '<S9>/drift'

  for (i = 0; i < 3; i++) {
    controlAerobi_B.ubx_d[i] = 0.0;
    controlAerobi_B.P_ui_o[i] = 0.0;
    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      r2 = i + 3 * distorsioned;
      controlAerobi_B.dv2[r2] = 0.0;
      o = 3 * distorsioned + i;
      controlAerobi_B.dv2[r2] = controlAerobi_B.dv2[o] +
        controlAerobi_P.J_Value[3 * distorsioned] * controlAerobi_B.Re_R[i];
      controlAerobi_B.dv2[r2] = controlAerobi_P.J_Value[3 * distorsioned + 1] *
        controlAerobi_B.Re_R[i + 3] + controlAerobi_B.dv2[3 * distorsioned + i];
      controlAerobi_B.dv2[r2] = controlAerobi_P.J_Value[3 * distorsioned + 2] *
        controlAerobi_B.Re_R[i + 6] + controlAerobi_B.dv2[3 * distorsioned + i];
      controlAerobi_B.ubx_d[i] += controlAerobi_B.Re_R_l[o] *
        controlAerobi_B.vbx[distorsioned];
      controlAerobi_B.P_ui_o[i] += controlAerobi_B.P_ui[o] *
        controlAerobi_B.eulerZYX[distorsioned];
    }

    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      r2 = i + 3 * distorsioned;
      controlAerobi_B.dv3[r2] = 0.0;
      controlAerobi_B.dv3[r2] = controlAerobi_B.dv3[3 * distorsioned + i] +
        controlAerobi_B.dv2[i] * controlAerobi_B.R_[distorsioned];
      controlAerobi_B.dv3[r2] = controlAerobi_B.dv3[3 * distorsioned + i] +
        controlAerobi_B.dv2[i + 3] * controlAerobi_B.R_[distorsioned + 3];
      controlAerobi_B.dv3[r2] = controlAerobi_B.dv3[3 * distorsioned + i] +
        controlAerobi_B.dv2[i + 6] * controlAerobi_B.R_[distorsioned + 6];
    }

    controlAerobi_B.Gain7 = 0.0;
    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      r2 = i + 3 * distorsioned;
      controlAerobi_B.dv4[r2] = 0.0;
      o = 3 * distorsioned + i;
      controlAerobi_B.dv4[r2] = controlAerobi_B.dv4[o] + controlAerobi_B.R_d_m[3
        * distorsioned] * controlAerobi_B.dv3[i];
      controlAerobi_B.dv4[r2] = controlAerobi_B.R_d_m[3 * distorsioned + 1] *
        controlAerobi_B.dv3[i + 3] + controlAerobi_B.dv4[3 * distorsioned + i];
      controlAerobi_B.dv4[r2] = controlAerobi_B.R_d_m[3 * distorsioned + 2] *
        controlAerobi_B.dv3[i + 6] + controlAerobi_B.dv4[3 * distorsioned + i];
      controlAerobi_B.Gain7 += controlAerobi_B.d_a[o] *
        controlAerobi_DWork.e_I[distorsioned];
    }

    controlAerobi_B.rtb_Gain_po_l[i] = 0.0;
    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      r2 = i + 3 * distorsioned;
      controlAerobi_B.dv5[r2] = 0.0;
      o = 3 * distorsioned + i;
      controlAerobi_B.dv5[r2] = controlAerobi_B.dv5[o] +
        controlAerobi_P.J_Value[i] * controlAerobi_B.R_[distorsioned];
      controlAerobi_B.dv5[r2] = controlAerobi_B.dv5[3 * distorsioned + i] +
        controlAerobi_P.J_Value[i + 3] * controlAerobi_B.R_[distorsioned + 3];
      controlAerobi_B.dv5[r2] = controlAerobi_B.dv5[3 * distorsioned + i] +
        controlAerobi_P.J_Value[i + 6] * controlAerobi_B.R_[distorsioned + 6];
      controlAerobi_B.rtb_Gain_po_l[i] += controlAerobi_B.dv4[o] *
        controlAerobi_B.ub_[distorsioned];
    }

    controlAerobi_B.Abs_a = 0.0;
    for (distorsioned = 0; distorsioned < 3; distorsioned++) {
      r2 = i + 3 * distorsioned;
      controlAerobi_B.dv6[r2] = 0.0;
      controlAerobi_B.dv6[r2] = controlAerobi_B.dv6[3 * distorsioned + i] +
        controlAerobi_B.R_d_m[3 * distorsioned] * controlAerobi_B.dv5[i];
      controlAerobi_B.dv6[r2] = controlAerobi_B.R_d_m[3 * distorsioned + 1] *
        controlAerobi_B.dv5[i + 3] + controlAerobi_B.dv6[3 * distorsioned + i];
      controlAerobi_B.dv6[r2] = controlAerobi_B.R_d_m[3 * distorsioned + 2] *
        controlAerobi_B.dv5[i + 6] + controlAerobi_B.dv6[3 * distorsioned + i];
      controlAerobi_B.Abs_a += controlAerobi_B.dv6[3 * distorsioned + i] *
        controlAerobi_B.r2[distorsioned];
    }

    controlAerobi_DWork.M_g[i] = ((((controlAerobi_B.ubx_d[i] -
      controlAerobi_B.P_ui_o[i]) - controlAerobi_B.Gain7) +
      controlAerobi_B.rtb_Gain_po_l[i]) + controlAerobi_B.Abs_a) +
      controlAerobi_P.drift_Value[i];
  }

  // Switch: '<S5>/Switch' incorporates:
  //   Constant: '<S5>/Reset'
  //   MATLAB Function: '<S9>/attitude_geometric_control'

  // '<S12>:1:50'
  // '<S12>:1:51'
  // '<S12>:1:52'
  if (controlAerobi_B.Compare) {
    // Switch: '<S5>/Switch1' incorporates:
    //   Gain: '<S16>/Gain'
    //   MATLAB Function: '<S10>/trajectory_tracking'
    //   MATLAB Function: '<S20>/altitude_fcn'

    if (controlAerobi_B.ALTHOLD) {
      controlAerobi_B.Switch_ed[0] = controlAerobi_P.Gain_Gain_c *
        controlAerobi_DWork.thrust0_f / controlAerobi_B.ubx_tmp_j +
        controlAerobi_B.Zgain_a;
    } else {
      controlAerobi_B.Switch_ed[0] = controlAerobi_B.DiscreteTimeIntegrator_b;
    }

    // End of Switch: '<S5>/Switch1'
    controlAerobi_B.Switch_ed[1] = controlAerobi_DWork.M_g[0];
    controlAerobi_B.Switch_ed[2] = controlAerobi_DWork.M_g[1];
  } else {
    controlAerobi_B.Switch_ed[0] = controlAerobi_P.Reset_Value[0];
    controlAerobi_B.Switch_ed[1] = controlAerobi_P.Reset_Value[1];
    controlAerobi_B.Switch_ed[2] = controlAerobi_P.Reset_Value[2];
  }

  // End of Switch: '<S5>/Switch'

  // Logic: '<S155>/Logical Operator3' incorporates:
  //   Constant: '<S155>/geometricControl'
  //   Constant: '<S162>/Constant'
  //   DataTypeConversion: '<S155>/Data Type Conversion3'
  //   Inport: '<Root>/I_RCinput'
  //   RelationalOperator: '<S162>/Compare'

  rtb_EnableGeometricControl = (controlAerobi_P.geometricControl_Value &&
    (controlAerobi_U.I_RCinput._channel10 <
     controlAerobi_P.CompareToConstant4_const));

  // MATLAB Function: '<S73>/altitude_fcn'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/calculate_altitude_des/altitude_fcn': '<S84>:1' 
  if ((!controlAerobi_DWork.z0_not_empty_c) ||
      (!controlAerobi_DWork.althold0_not_empty) ||
      (!controlAerobi_DWork.thrust0_not_empty)) {
    // '<S84>:1:4'
    // '<S84>:1:5'
    controlAerobi_DWork.z0 = controlAerobi_B.b_exp_b;
    controlAerobi_DWork.z0_not_empty_c = true;

    // '<S84>:1:6'
    controlAerobi_DWork.althold0 = 0.0;
    controlAerobi_DWork.althold0_not_empty = true;

    // '<S84>:1:7'
    controlAerobi_DWork.thrust0 = controlAerobi_B.DiscreteTimeIntegrator_b;
    controlAerobi_DWork.thrust0_not_empty = true;
  } else {
    if ((controlAerobi_DWork.althold0 == 0.0) && controlAerobi_B.ALTHOLD) {
      // '<S84>:1:10'
      // '<S84>:1:11'
      controlAerobi_DWork.z0 = controlAerobi_B.b_exp_b;

      // '<S84>:1:12'
      controlAerobi_DWork.thrust0 = controlAerobi_B.DiscreteTimeIntegrator_b;
    }

    // '<S84>:1:14'
    controlAerobi_DWork.althold0 = controlAerobi_B.ALTHOLD;
  }

  // DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
  // '<S84>:1:17'
  // '<S84>:1:18'
  if (controlAerobi_B.ALTHOLD &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_b <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n =
      controlAerobi_P.DiscreteTimeIntegrator_IC_l;
  }

  // Saturate: '<S86>/Saturation'
  if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n >
      controlAerobi_P.Saturation_UpperSat_n) {
    controlAerobi_B.Gain3_l = controlAerobi_P.Saturation_UpperSat_n;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n <
             controlAerobi_P.Saturation_LowerSat_e) {
    controlAerobi_B.Gain3_l = controlAerobi_P.Saturation_LowerSat_e;
  } else {
    controlAerobi_B.Gain3_l =
      controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n;
  }

  // End of Saturate: '<S86>/Saturation'

  // Switch: '<S73>/Switch' incorporates:
  //   Constant: '<S155>/Z_pos_vel'
  //   Constant: '<S155>/enable_PC'
  //   Constant: '<S156>/Zdes'
  //   Logic: '<S73>/and'

  if (controlAerobi_P.Z_pos_vel_Value && controlAerobi_P.enable_PC_Value) {
    controlAerobi_B.Switch_l0 = controlAerobi_P.Zdes_Value;
  } else {
    // Sum: '<S73>/Sum1' incorporates:
    //   MATLAB Function: '<S73>/altitude_fcn'

    controlAerobi_B.Switch_l0 = controlAerobi_B.Gain3_l + controlAerobi_DWork.z0;

    // Saturate: '<S73>/Saturation'
    if (controlAerobi_B.Switch_l0 > controlAerobi_P.Saturation_UpperSat_a) {
      controlAerobi_B.Switch_l0 = controlAerobi_P.Saturation_UpperSat_a;
    } else {
      if (controlAerobi_B.Switch_l0 < controlAerobi_P.Saturation_LowerSat_f) {
        controlAerobi_B.Switch_l0 = controlAerobi_P.Saturation_LowerSat_f;
      }
    }

    // End of Saturate: '<S73>/Saturation'
  }

  // End of Switch: '<S73>/Switch'

  // Switch: '<S74>/Switch4' incorporates:
  //   Constant: '<S74>/Constant'
  //   Sum: '<S72>/Sum1'

  if (controlAerobi_B.ALTHOLD) {
    controlAerobi_B.Product1_a1 = controlAerobi_B.Switch_l0 -
      controlAerobi_B.b_exp_b;
  } else {
    controlAerobi_B.Product1_a1 = controlAerobi_P.Constant_Value_oa;
  }

  // End of Switch: '<S74>/Switch4'

  // DiscreteIntegrator: '<S74>/Discrete-Time Integrator'
  if (controlAerobi_B.ALTHOLD &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_i <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_e =
      controlAerobi_P.DiscreteTimeIntegrator_IC_df;
  }

  // SampleTimeMath: '<S77>/TSamp' incorporates:
  //   Constant: '<S95>/D_Z_pos'
  //   Product: '<S74>/Product2'
  //
  //  About '<S77>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.TSamp = controlAerobi_P.D_Z_pos_Value *
    controlAerobi_B.Product1_a1 * controlAerobi_P.TSamp_WtEt;

  // Sum: '<S74>/Sum' incorporates:
  //   Constant: '<S95>/P_Z_pos'
  //   DiscreteIntegrator: '<S74>/Discrete-Time Integrator'
  //   Product: '<S74>/Product'
  //   Sum: '<S77>/Diff'
  //   UnitDelay: '<S77>/UD'

  controlAerobi_B.Sum_n = (controlAerobi_P.P_Z_pos_Value *
    controlAerobi_B.Product1_a1 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_e) +
    (controlAerobi_B.TSamp - controlAerobi_DWork.UD_DSTATE);

  // Switch: '<S78>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_Z_pos'
  //   Constant: '<S95>/SatPos_Z_pos'
  //   RelationalOperator: '<S78>/LowerRelop1'
  //   RelationalOperator: '<S78>/UpperRelop'
  //   Switch: '<S78>/Switch'

  if (controlAerobi_B.Sum_n > controlAerobi_P.SatPos_Z_pos_Value) {
    controlAerobi_B.Abs_a = controlAerobi_P.SatPos_Z_pos_Value;
  } else if (controlAerobi_B.Sum_n < controlAerobi_P.SatNeg_Z_pos_Value) {
    // Switch: '<S78>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_Z_pos'

    controlAerobi_B.Abs_a = controlAerobi_P.SatNeg_Z_pos_Value;
  } else {
    controlAerobi_B.Abs_a = controlAerobi_B.Sum_n;
  }

  // End of Switch: '<S78>/Switch2'

  // Gain: '<S85>/dZgain' incorporates:
  //   Constant: '<S73>/med_thrust'
  //   Gain: '<S85>/adapt_thrust'
  //   Lookup_n-D: '<S85>/1-D Lookup Table'
  //   Sum: '<S73>/Sum'

  controlAerobi_B.Zgain_a = look1_binlx
    ((controlAerobi_B.DiscreteTimeIntegrator_b -
      controlAerobi_P.med_thrust_Value) * controlAerobi_P.adapt_thrust_Gain,
     controlAerobi_P.uDLookupTable_bp01Data,
     controlAerobi_P.uDLookupTable_tableData, 600U) *
    controlAerobi_P.dZgain_Gain;

  // DeadZone: '<S85>/Dead Zone'
  if (controlAerobi_B.Zgain_a > controlAerobi_P.DeadZone_End) {
    controlAerobi_B.Zgain_a -= controlAerobi_P.DeadZone_End;
  } else if (controlAerobi_B.Zgain_a >= controlAerobi_P.DeadZone_Start) {
    controlAerobi_B.Zgain_a = 0.0;
  } else {
    controlAerobi_B.Zgain_a -= controlAerobi_P.DeadZone_Start;
  }

  // End of DeadZone: '<S85>/Dead Zone'

  // Saturate: '<S85>/Saturation'
  if (controlAerobi_B.Zgain_a > controlAerobi_P.Saturation_UpperSat_g) {
    controlAerobi_B.Zgain_a = controlAerobi_P.Saturation_UpperSat_g;
  } else {
    if (controlAerobi_B.Zgain_a < controlAerobi_P.Saturation_LowerSat_o) {
      controlAerobi_B.Zgain_a = controlAerobi_P.Saturation_LowerSat_o;
    }
  }

  // End of Saturate: '<S85>/Saturation'

  // Switch: '<S72>/Switch1' incorporates:
  //   Constant: '<S155>/Z_pos_vel'

  if (controlAerobi_P.Z_pos_vel_Value) {
    controlAerobi_B.dZ_des = controlAerobi_B.Abs_a;
  } else {
    controlAerobi_B.dZ_des = controlAerobi_B.Zgain_a;
  }

  // End of Switch: '<S72>/Switch1'

  // Switch: '<S75>/Switch4' incorporates:
  //   Constant: '<S75>/Constant'
  //   Sum: '<S72>/Sum5'

  if (controlAerobi_B.ALTHOLD) {
    controlAerobi_B.Product1_ew = controlAerobi_B.dZ_des -
      controlAerobi_B.r_x_idx_1;
  } else {
    controlAerobi_B.Product1_ew = controlAerobi_P.Constant_Value_b;
  }

  // End of Switch: '<S75>/Switch4'

  // DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
  if (controlAerobi_B.ALTHOLD &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_c <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n5 =
      controlAerobi_P.DiscreteTimeIntegrator_IC_p;
  }

  // SampleTimeMath: '<S81>/TSamp' incorporates:
  //   Constant: '<S95>/D_Z_rate'
  //   Product: '<S75>/Product2'
  //
  //  About '<S81>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.TSamp_h = controlAerobi_P.D_Z_rate_Value *
    controlAerobi_B.Product1_ew * controlAerobi_P.TSamp_WtEt_g;

  // Sum: '<S75>/Sum' incorporates:
  //   Constant: '<S95>/P_Z_rate'
  //   DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
  //   Product: '<S75>/Product'
  //   Sum: '<S81>/Diff'
  //   UnitDelay: '<S81>/UD'

  controlAerobi_B.Sum_b = (controlAerobi_P.P_Z_rate_Value *
    controlAerobi_B.Product1_ew +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n5) +
    (controlAerobi_B.TSamp_h - controlAerobi_DWork.UD_DSTATE_f);

  // Switch: '<S82>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_Z_rate'
  //   Constant: '<S95>/SatPos_Z_rate'
  //   RelationalOperator: '<S82>/LowerRelop1'
  //   RelationalOperator: '<S82>/UpperRelop'
  //   Switch: '<S82>/Switch'

  if (controlAerobi_B.Sum_b > controlAerobi_P.SatPos_Z_rate_Value) {
    controlAerobi_B.Abs = controlAerobi_P.SatPos_Z_rate_Value;
  } else if (controlAerobi_B.Sum_b < controlAerobi_P.SatNeg_Z_rate_Value) {
    // Switch: '<S82>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_Z_rate'

    controlAerobi_B.Abs = controlAerobi_P.SatNeg_Z_rate_Value;
  } else {
    controlAerobi_B.Abs = controlAerobi_B.Sum_b;
  }

  // End of Switch: '<S82>/Switch2'

  // Product: '<S72>/Divide' incorporates:
  //   MATLAB Function: '<S73>/altitude_fcn'
  //   Sum: '<S72>/Sum2'

  controlAerobi_B.Divide = (controlAerobi_DWork.thrust0 + controlAerobi_B.Abs) /
    controlAerobi_B.ubx_tmp_j;

  // Switch: '<S8>/Switch2' incorporates:
  //   Constant: '<S8>/Constant'
  //   Logic: '<S8>/Logical Operator'
  //   Switch: '<S53>/Switch1'

  if (rtb_EnableGeometricControl && controlAerobi_P.Constant_Value_gs) {
    controlAerobi_B.Switch2_n = controlAerobi_B.Switch_ed[0];
  } else if (controlAerobi_B.ALTHOLD) {
    // Switch: '<S53>/Switch1'
    controlAerobi_B.Switch2_n = controlAerobi_B.Divide;
  } else {
    controlAerobi_B.Switch2_n = controlAerobi_B.DiscreteTimeIntegrator_b;
  }

  // End of Switch: '<S8>/Switch2'

  // Switch: '<S93>/Switch2' incorporates:
  //   Constant: '<S91>/Constant1'
  //   Constant: '<S91>/Constant2'
  //   RelationalOperator: '<S93>/LowerRelop1'
  //   RelationalOperator: '<S93>/UpperRelop'
  //   Switch: '<S93>/Switch'

  if (controlAerobi_B.Switch2_n > controlAerobi_P.Constant1_Value_k) {
    controlAerobi_B.Switch2_n = controlAerobi_P.Constant1_Value_k;
  } else {
    if (controlAerobi_B.Switch2_n < controlAerobi_P.Constant2_Value_n) {
      // Switch: '<S93>/Switch' incorporates:
      //   Constant: '<S91>/Constant2'

      controlAerobi_B.Switch2_n = controlAerobi_P.Constant2_Value_n;
    }
  }

  // End of Switch: '<S93>/Switch2'

  // Sum: '<S91>/Sum1' incorporates:
  //   Constant: '<S91>/Constant8'
  //   Gain: '<S91>/Gain1'

  controlAerobi_B.Switch2_n = controlAerobi_P.Gain1_Gain_m *
    controlAerobi_B.Switch2_n + controlAerobi_P.Constant8_Value;

  // Logic: '<S58>/Logical Operator'
  rtb_LogicalOperator_e = (controlAerobi_B.Compare && controlAerobi_B.POS_HOLD);

  // DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  if (rtb_LogicalOperator_e &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_g <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_h;
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_h;
  }

  // Saturate: '<S68>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'

  if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0] >
      controlAerobi_P.Saturation_UpperSat_pm) {
    controlAerobi_B.y_k_idx_0 = controlAerobi_P.Saturation_UpperSat_pm;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0] <
             controlAerobi_P.Saturation_LowerSat_l) {
    controlAerobi_B.y_k_idx_0 = controlAerobi_P.Saturation_LowerSat_l;
  } else {
    controlAerobi_B.y_k_idx_0 =
      controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0];
  }

  if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1] >
      controlAerobi_P.Saturation_UpperSat_pm) {
    controlAerobi_B.y_k_idx_1 = controlAerobi_P.Saturation_UpperSat_pm;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1] <
             controlAerobi_P.Saturation_LowerSat_l) {
    controlAerobi_B.y_k_idx_1 = controlAerobi_P.Saturation_LowerSat_l;
  } else {
    controlAerobi_B.y_k_idx_1 =
      controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1];
  }

  // End of Saturate: '<S68>/Saturation'

  // DeadZone: '<S58>/Dead Zone'
  if (controlAerobi_B.t > controlAerobi_P.DeadZone_End_b) {
    controlAerobi_B.ubx_tmp_j = controlAerobi_B.t -
      controlAerobi_P.DeadZone_End_b;
  } else if (controlAerobi_B.t >= controlAerobi_P.DeadZone_Start_i) {
    controlAerobi_B.ubx_tmp_j = 0.0;
  } else {
    controlAerobi_B.ubx_tmp_j = controlAerobi_B.t -
      controlAerobi_P.DeadZone_Start_i;
  }

  // End of DeadZone: '<S58>/Dead Zone'

  // DeadZone: '<S58>/Dead Zone1'
  if (controlAerobi_B.absxk > controlAerobi_P.DeadZone1_End) {
    controlAerobi_B.TSamp_hv = controlAerobi_B.absxk -
      controlAerobi_P.DeadZone1_End;
  } else if (controlAerobi_B.absxk >= controlAerobi_P.DeadZone1_Start) {
    controlAerobi_B.TSamp_hv = 0.0;
  } else {
    controlAerobi_B.TSamp_hv = controlAerobi_B.absxk -
      controlAerobi_P.DeadZone1_Start;
  }

  // End of DeadZone: '<S58>/Dead Zone1'

  // MATLAB Function: '<S58>/Create dXY desired' incorporates:
  //   Gain: '<S58>/Gain'
  //   Gain: '<S58>/Gain1'

  controlAerobi_CreatedXYdesired(controlAerobi_B.Gain_po[2],
    controlAerobi_P.Gain_Gain_h * controlAerobi_B.ubx_tmp_j,
    controlAerobi_P.Gain1_Gain_k * controlAerobi_B.TSamp_hv,
    &controlAerobi_B.sf_CreatedXYdesired);

  // Saturate: '<S58>/Saturation1'
  if (controlAerobi_B.sf_CreatedXYdesired.dXY_d[0] >
      controlAerobi_P.Saturation1_UpperSat_m) {
    controlAerobi_B.rtb_Product1_a_idx_1 =
      controlAerobi_P.Saturation1_UpperSat_m;
  } else if (controlAerobi_B.sf_CreatedXYdesired.dXY_d[0] <
             controlAerobi_P.Saturation1_LowerSat_f) {
    controlAerobi_B.rtb_Product1_a_idx_1 =
      controlAerobi_P.Saturation1_LowerSat_f;
  } else {
    controlAerobi_B.rtb_Product1_a_idx_1 =
      controlAerobi_B.sf_CreatedXYdesired.dXY_d[0];
  }

  // Switch: '<S58>/Switch1' incorporates:
  //   Constant: '<S155>/XY_pos_vel'
  //   Constant: '<S58>/zero'

  if (controlAerobi_P.XY_pos_vel_Value) {
    controlAerobi_B.Gain7 = controlAerobi_B.rtb_Product1_a_idx_1;
  } else {
    controlAerobi_B.Gain7 = controlAerobi_P.zero_Value_n;
  }

  // Saturate: '<S58>/Saturation1'
  controlAerobi_B.rtb_Product1_a_idx_0 = controlAerobi_B.rtb_Product1_a_idx_1;
  if (controlAerobi_B.sf_CreatedXYdesired.dXY_d[1] >
      controlAerobi_P.Saturation1_UpperSat_m) {
    controlAerobi_B.rtb_Product1_a_idx_1 =
      controlAerobi_P.Saturation1_UpperSat_m;
  } else if (controlAerobi_B.sf_CreatedXYdesired.dXY_d[1] <
             controlAerobi_P.Saturation1_LowerSat_f) {
    controlAerobi_B.rtb_Product1_a_idx_1 =
      controlAerobi_P.Saturation1_LowerSat_f;
  } else {
    controlAerobi_B.rtb_Product1_a_idx_1 =
      controlAerobi_B.sf_CreatedXYdesired.dXY_d[1];
  }

  // DiscreteFir: '<S104>/Hlp' incorporates:
  //   Lookup_n-D: '<S70>/1-D Lookup Table'
  //   S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  //   S-Function (sdspFromNetwork): '<S181>/Local position receive'

  o = 2;

  // Gain: '<S70>/dZgain' incorporates:
  //   Gain: '<S70>/adapt_thrust'
  //   Lookup_n-D: '<S70>/1-D Lookup Table'

  controlAerobi_B.rtb_Saturation_g_idx_1 = controlAerobi_P.dZgain_Gain_l *
    look1_binlx(controlAerobi_P.adapt_thrust_Gain_l * controlAerobi_B.Gain7,
                controlAerobi_P.uDLookupTable_bp01Data_p,
                controlAerobi_P.uDLookupTable_tableData_l, 600U);

  // DeadZone: '<S70>/Dead Zone'
  if (controlAerobi_B.rtb_Saturation_g_idx_1 > controlAerobi_P.DeadZone_End_l) {
    controlAerobi_B.rtb_Saturation_g_idx_1 -= controlAerobi_P.DeadZone_End_l;
  } else if (controlAerobi_B.rtb_Saturation_g_idx_1 >=
             controlAerobi_P.DeadZone_Start_o) {
    controlAerobi_B.rtb_Saturation_g_idx_1 = 0.0;
  } else {
    controlAerobi_B.rtb_Saturation_g_idx_1 -= controlAerobi_P.DeadZone_Start_o;
  }

  // Saturate: '<S70>/Saturation'
  if (controlAerobi_B.rtb_Saturation_g_idx_1 >
      controlAerobi_P.Saturation_UpperSat_e) {
    controlAerobi_B.rtb_Saturation_g_idx_0 =
      controlAerobi_P.Saturation_UpperSat_e;
  } else if (controlAerobi_B.rtb_Saturation_g_idx_1 <
             controlAerobi_P.Saturation_LowerSat_h) {
    controlAerobi_B.rtb_Saturation_g_idx_0 =
      controlAerobi_P.Saturation_LowerSat_h;
  } else {
    controlAerobi_B.rtb_Saturation_g_idx_0 =
      controlAerobi_B.rtb_Saturation_g_idx_1;
  }

  // Switch: '<S58>/Switch1' incorporates:
  //   Constant: '<S155>/XY_pos_vel'
  //   Constant: '<S58>/zero'

  if (controlAerobi_P.XY_pos_vel_Value) {
    controlAerobi_B.Gain7 = controlAerobi_B.rtb_Product1_a_idx_1;
  } else {
    controlAerobi_B.Gain7 = controlAerobi_P.zero_Value_n;
  }

  // Gain: '<S70>/dZgain' incorporates:
  //   Gain: '<S70>/adapt_thrust'
  //   Lookup_n-D: '<S70>/1-D Lookup Table'

  controlAerobi_B.rtb_Saturation_g_idx_1 = look1_binlx
    (controlAerobi_P.adapt_thrust_Gain_l * controlAerobi_B.Gain7,
     controlAerobi_P.uDLookupTable_bp01Data_p,
     controlAerobi_P.uDLookupTable_tableData_l, 600U) *
    controlAerobi_P.dZgain_Gain_l;

  // DeadZone: '<S70>/Dead Zone'
  if (controlAerobi_B.rtb_Saturation_g_idx_1 > controlAerobi_P.DeadZone_End_l) {
    controlAerobi_B.rtb_Saturation_g_idx_1 -= controlAerobi_P.DeadZone_End_l;
  } else if (controlAerobi_B.rtb_Saturation_g_idx_1 >=
             controlAerobi_P.DeadZone_Start_o) {
    controlAerobi_B.rtb_Saturation_g_idx_1 = 0.0;
  } else {
    controlAerobi_B.rtb_Saturation_g_idx_1 -= controlAerobi_P.DeadZone_Start_o;
  }

  // Saturate: '<S70>/Saturation'
  if (controlAerobi_B.rtb_Saturation_g_idx_1 >
      controlAerobi_P.Saturation_UpperSat_e) {
    controlAerobi_B.rtb_Saturation_g_idx_1 =
      controlAerobi_P.Saturation_UpperSat_e;
  } else {
    if (controlAerobi_B.rtb_Saturation_g_idx_1 <
        controlAerobi_P.Saturation_LowerSat_h) {
      controlAerobi_B.rtb_Saturation_g_idx_1 =
        controlAerobi_P.Saturation_LowerSat_h;
    }
  }

  // Logic: '<S52>/Logical Operator1' incorporates:
  //   Constant: '<S155>/XY_pos_vel'

  rtb_LogicalOperator1 = (controlAerobi_P.XY_pos_vel_Value &&
    controlAerobi_B.POS_HOLD);

  // MATLAB Function: '<S52>/Create_Pos_Hold'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/Create_Pos_Hold': '<S55>:1' 
  if ((!controlAerobi_DWork.posHold_not_empty) ||
      (!controlAerobi_DWork.posState_not_empty) ||
      (!controlAerobi_DWork.stop_not_empty) ||
      (!controlAerobi_DWork.XY_ref0_not_empty) ||
      (!controlAerobi_DWork.solution0_not_empty)) {
    // '<S55>:1:4'
    // '<S55>:1:5'
    controlAerobi_DWork.posHold_not_empty = true;

    // '<S55>:1:6'
    controlAerobi_DWork.posState = 0.0;
    controlAerobi_DWork.posState_not_empty = true;

    // '<S55>:1:7'
    controlAerobi_DWork.stop_not_empty = true;

    // '<S55>:1:8'
    controlAerobi_DWork.posHold[0] = controlAerobi_B.b_x_idx_2;
    controlAerobi_DWork.stop[0] = 0.0;
    controlAerobi_DWork.XY_ref0[0] = 0.0;
    controlAerobi_DWork.posHold[1] = controlAerobi_B.rtb_Switch_Pos_idx_1;
    controlAerobi_DWork.stop[1] = 0.0;
    controlAerobi_DWork.XY_ref0[1] = 0.0;
    controlAerobi_DWork.XY_ref0_not_empty = true;

    // '<S55>:1:9'
    controlAerobi_DWork.solution0 = controlAerobi_B.Sum;
    controlAerobi_DWork.solution0_not_empty = true;
  } else {
    if ((!rtb_LogicalOperator1) && (controlAerobi_DWork.posState == 0.0)) {
      // '<S55>:1:11'
      // '<S55>:1:12'
      // '<S55>:1:13'
      controlAerobi_DWork.posHold[0] = controlAerobi_B.b_x_idx_2;
      controlAerobi_DWork.XY_ref0[0] = 0.0;
      controlAerobi_DWork.posHold[1] = controlAerobi_B.rtb_Switch_Pos_idx_1;
      controlAerobi_DWork.XY_ref0[1] = 0.0;
    } else if ((controlAerobi_DWork.posState == 0.0) && rtb_LogicalOperator1) {
      // '<S55>:1:14'
      // '<S55>:1:15'
      // '<S55>:1:16'
      controlAerobi_DWork.posHold[0] = controlAerobi_B.b_x_idx_2;
      controlAerobi_DWork.XY_ref0[0] = 0.0;
      controlAerobi_DWork.posHold[1] = controlAerobi_B.rtb_Switch_Pos_idx_1;
      controlAerobi_DWork.XY_ref0[1] = 0.0;
    } else {
      if (controlAerobi_DWork.posState == 1.0) {
        // '<S55>:1:17'
        if (controlAerobi_DWork.solution0 != controlAerobi_B.Sum) {
          // '<S55>:1:18'
          // '<S55>:1:19'
          // '<S55>:1:20'
          controlAerobi_DWork.posHold[0] = controlAerobi_B.b_x_idx_2;
          controlAerobi_DWork.XY_ref0[0] = controlAerobi_B.y_k_idx_0;
          controlAerobi_DWork.posHold[1] = controlAerobi_B.rtb_Switch_Pos_idx_1;
          controlAerobi_DWork.XY_ref0[1] = controlAerobi_B.y_k_idx_1;
        }

        // '<S55>:1:22'
        if ((controlAerobi_B.rtb_Saturation_g_idx_0 == 0.0) &&
            (controlAerobi_DWork.stop[0] == 0.0)) {
          // '<S55>:1:23'
          // '<S55>:1:24'
          controlAerobi_DWork.posHold[0] = controlAerobi_B.b_x_idx_2;

          // '<S55>:1:25'
          controlAerobi_DWork.stop[0] = 1.0;

          // '<S55>:1:26'
          controlAerobi_DWork.XY_ref0[0] = controlAerobi_B.y_k_idx_0;
        } else {
          if ((fabs(controlAerobi_B.rtb_Saturation_g_idx_0) > 0.0) &&
              (controlAerobi_DWork.stop[0] == 1.0)) {
            // '<S55>:1:27'
            // '<S55>:1:28'
            controlAerobi_DWork.stop[0] = 0.0;
          }
        }

        // '<S55>:1:22'
        if ((controlAerobi_B.rtb_Saturation_g_idx_1 == 0.0) &&
            (controlAerobi_DWork.stop[1] == 0.0)) {
          // '<S55>:1:23'
          // '<S55>:1:24'
          controlAerobi_DWork.posHold[1] = controlAerobi_B.rtb_Switch_Pos_idx_1;

          // '<S55>:1:25'
          controlAerobi_DWork.stop[1] = 1.0;

          // '<S55>:1:26'
          controlAerobi_DWork.XY_ref0[1] = controlAerobi_B.y_k_idx_1;
        } else {
          if ((fabs(controlAerobi_B.rtb_Saturation_g_idx_1) > 0.0) &&
              (controlAerobi_DWork.stop[1] == 1.0)) {
            // '<S55>:1:27'
            // '<S55>:1:28'
            controlAerobi_DWork.stop[1] = 0.0;
          }
        }
      }
    }

    // '<S55>:1:32'
    controlAerobi_DWork.posState = rtb_LogicalOperator1;
  }

  if (!rtb_LogicalOperator1) {
    // '<S55>:1:36'
    // '<S55>:1:37'
    controlAerobi_B.rtb_XYd_idx_0 = controlAerobi_DWork.posHold[0];
    controlAerobi_B.rtb_XYd_idx_1 = controlAerobi_DWork.posHold[1];
  } else {
    // '<S55>:1:39'
    controlAerobi_B.rtb_XYd_idx_0 = (controlAerobi_DWork.posHold[0] +
      controlAerobi_B.y_k_idx_0) - controlAerobi_DWork.XY_ref0[0];
    controlAerobi_B.rtb_XYd_idx_1 = (controlAerobi_DWork.posHold[1] +
      controlAerobi_B.y_k_idx_1) - controlAerobi_DWork.XY_ref0[1];
  }

  // End of MATLAB Function: '<S52>/Create_Pos_Hold'

  // Switch: '<S56>/Switch4' incorporates:
  //   Constant: '<S56>/Constant1'
  //   Sum: '<S52>/Sum4'

  if (rtb_LogicalOperator_e) {
    controlAerobi_B.rtb_Product1_na_idx_0 = controlAerobi_B.rtb_XYd_idx_0 -
      controlAerobi_B.b_x_idx_2;
    controlAerobi_B.rtb_Product1_na_idx_1 = controlAerobi_B.rtb_XYd_idx_1 -
      controlAerobi_B.rtb_Switch_Pos_idx_1;
  } else {
    controlAerobi_B.rtb_Product1_na_idx_0 = controlAerobi_P.Constant1_Value_m;
    controlAerobi_B.rtb_Product1_na_idx_1 = controlAerobi_P.Constant1_Value_m;
  }

  // End of Switch: '<S56>/Switch4'

  // DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
  if (rtb_LogicalOperator_e &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_l <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_m[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_c;
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_m[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_c;
  }

  // SampleTimeMath: '<S60>/TSamp' incorporates:
  //   Constant: '<S95>/D_XY_pos'
  //   Product: '<S56>/Product2'
  //
  //  About '<S60>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_TSamp_p_h = controlAerobi_P.D_XY_pos_Value *
    controlAerobi_B.rtb_Product1_na_idx_0 * controlAerobi_P.TSamp_WtEt_d;

  // Sum: '<S56>/Sum' incorporates:
  //   Constant: '<S95>/P_XY_pos'
  //   DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
  //   Product: '<S56>/Product'
  //   Sum: '<S60>/Diff'
  //   UnitDelay: '<S60>/UD'

  controlAerobi_B.rtb_Sum_l_b = (controlAerobi_P.P_XY_pos_Value *
    controlAerobi_B.rtb_Product1_na_idx_0 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_m[0]) +
    (controlAerobi_B.rtb_TSamp_p_h - controlAerobi_DWork.UD_DSTATE_d[0]);

  // Switch: '<S61>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_XY_pos'
  //   Constant: '<S95>/SatPos_XY_pos'
  //   RelationalOperator: '<S61>/LowerRelop1'
  //   RelationalOperator: '<S61>/UpperRelop'
  //   Switch: '<S61>/Switch'

  if (controlAerobi_B.rtb_Sum_l_b > controlAerobi_P.SatPos_XY_pos_Value) {
    controlAerobi_B.rtb_Abs_o_d = controlAerobi_P.SatPos_XY_pos_Value;
  } else if (controlAerobi_B.rtb_Sum_l_b < controlAerobi_P.SatNeg_XY_pos_Value)
  {
    // Switch: '<S61>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_XY_pos'

    controlAerobi_B.rtb_Abs_o_d = controlAerobi_P.SatNeg_XY_pos_Value;
  } else {
    controlAerobi_B.rtb_Abs_o_d = controlAerobi_B.rtb_Sum_l_b;
  }

  // Switch: '<S52>/Switch2' incorporates:
  //   Constant: '<S155>/XY_pos_vel'

  if (controlAerobi_P.XY_pos_vel_Value) {
    controlAerobi_B.rtb_Product1_a_idx_0 = controlAerobi_B.rtb_Abs_o_d;
  }

  // Saturate: '<S52>/Saturation'
  if (controlAerobi_B.rtb_Product1_a_idx_0 >
      controlAerobi_P.Saturation_UpperSat_m) {
    controlAerobi_B.rtb_Saturation_b_idx_0 =
      controlAerobi_P.Saturation_UpperSat_m;
  } else if (controlAerobi_B.rtb_Product1_a_idx_0 <
             controlAerobi_P.Saturation_LowerSat_p) {
    controlAerobi_B.rtb_Saturation_b_idx_0 =
      controlAerobi_P.Saturation_LowerSat_p;
  } else {
    controlAerobi_B.rtb_Saturation_b_idx_0 =
      controlAerobi_B.rtb_Product1_a_idx_0;
  }

  // SampleTimeMath: '<S60>/TSamp'
  //
  //  About '<S60>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_TSamp_p_idx_0 = controlAerobi_B.rtb_TSamp_p_h;

  // Sum: '<S56>/Sum'
  controlAerobi_B.rtb_Sum_l_idx_0 = controlAerobi_B.rtb_Sum_l_b;

  // Switch: '<S61>/Switch2'
  controlAerobi_B.rtb_Abs_o_idx_0 = controlAerobi_B.rtb_Abs_o_d;
  controlAerobi_B.rtb_Product1_a_idx_0 = controlAerobi_B.rtb_Product1_a_idx_1;

  // SampleTimeMath: '<S60>/TSamp' incorporates:
  //   Constant: '<S95>/D_XY_pos'
  //   Product: '<S56>/Product2'
  //
  //  About '<S60>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_TSamp_p_h = controlAerobi_P.D_XY_pos_Value *
    controlAerobi_B.rtb_Product1_na_idx_1 * controlAerobi_P.TSamp_WtEt_d;

  // Sum: '<S56>/Sum' incorporates:
  //   Constant: '<S95>/P_XY_pos'
  //   DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
  //   Product: '<S56>/Product'
  //   Sum: '<S60>/Diff'
  //   UnitDelay: '<S60>/UD'

  controlAerobi_B.rtb_Sum_l_b = (controlAerobi_P.P_XY_pos_Value *
    controlAerobi_B.rtb_Product1_na_idx_1 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_m[1]) +
    (controlAerobi_B.rtb_TSamp_p_h - controlAerobi_DWork.UD_DSTATE_d[1]);

  // Switch: '<S61>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_XY_pos'
  //   Constant: '<S95>/SatPos_XY_pos'
  //   RelationalOperator: '<S61>/LowerRelop1'
  //   RelationalOperator: '<S61>/UpperRelop'
  //   Switch: '<S61>/Switch'

  if (controlAerobi_B.rtb_Sum_l_b > controlAerobi_P.SatPos_XY_pos_Value) {
    controlAerobi_B.rtb_Abs_o_d = controlAerobi_P.SatPos_XY_pos_Value;
  } else if (controlAerobi_B.rtb_Sum_l_b < controlAerobi_P.SatNeg_XY_pos_Value)
  {
    // Switch: '<S61>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_XY_pos'

    controlAerobi_B.rtb_Abs_o_d = controlAerobi_P.SatNeg_XY_pos_Value;
  } else {
    controlAerobi_B.rtb_Abs_o_d = controlAerobi_B.rtb_Sum_l_b;
  }

  // Switch: '<S52>/Switch2' incorporates:
  //   Constant: '<S155>/XY_pos_vel'

  if (controlAerobi_P.XY_pos_vel_Value) {
    controlAerobi_B.rtb_Product1_a_idx_0 = controlAerobi_B.rtb_Abs_o_d;
  }

  // Saturate: '<S52>/Saturation'
  if (controlAerobi_B.rtb_Product1_a_idx_0 >
      controlAerobi_P.Saturation_UpperSat_m) {
    controlAerobi_B.rtb_Saturation_b_idx_1 =
      controlAerobi_P.Saturation_UpperSat_m;
  } else if (controlAerobi_B.rtb_Product1_a_idx_0 <
             controlAerobi_P.Saturation_LowerSat_p) {
    controlAerobi_B.rtb_Saturation_b_idx_1 =
      controlAerobi_P.Saturation_LowerSat_p;
  } else {
    controlAerobi_B.rtb_Saturation_b_idx_1 =
      controlAerobi_B.rtb_Product1_a_idx_0;
  }

  // Switch: '<S57>/Switch4' incorporates:
  //   Constant: '<S57>/Constant1'
  //   Sum: '<S52>/Sum'

  if (rtb_LogicalOperator_e) {
    controlAerobi_B.rtb_Product1_a_idx_0 =
      controlAerobi_B.rtb_Saturation_b_idx_0 - controlAerobi_B.b_x_idx_1;
    controlAerobi_B.rtb_Product1_a_idx_1 =
      controlAerobi_B.rtb_Saturation_b_idx_1 - controlAerobi_B.x_I_idx_1;
  } else {
    controlAerobi_B.rtb_Product1_a_idx_0 = controlAerobi_P.Constant1_Value_l;
    controlAerobi_B.rtb_Product1_a_idx_1 = controlAerobi_P.Constant1_Value_l;
  }

  // End of Switch: '<S57>/Switch4'

  // DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
  if (rtb_LogicalOperator_e &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_n <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_fo[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_hz;
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_fo[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_hz;
  }

  // SampleTimeMath: '<S64>/TSamp' incorporates:
  //   Constant: '<S95>/D_XY_rate'
  //   Product: '<S57>/Product2'
  //
  //  About '<S64>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_R_d_m_tmp = controlAerobi_P.D_XY_rate_Value *
    controlAerobi_B.rtb_Product1_a_idx_0 * controlAerobi_P.TSamp_WtEt_b;

  // Sum: '<S57>/Sum' incorporates:
  //   Constant: '<S95>/P_XY_rate'
  //   DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
  //   Product: '<S57>/Product'
  //   Sum: '<S64>/Diff'
  //   UnitDelay: '<S64>/UD'

  controlAerobi_B.rtb_R_d_m_tmp_j = (controlAerobi_P.P_XY_rate_Value *
    controlAerobi_B.rtb_Product1_a_idx_0 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_fo[0]) +
    (controlAerobi_B.rtb_R_d_m_tmp - controlAerobi_DWork.UD_DSTATE_o[0]);

  // Switch: '<S65>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_XY_rate'
  //   Constant: '<S95>/SatPos_XY_rate'
  //   RelationalOperator: '<S65>/LowerRelop1'
  //   RelationalOperator: '<S65>/UpperRelop'
  //   Switch: '<S65>/Switch'

  if (controlAerobi_B.rtb_R_d_m_tmp_j > controlAerobi_P.SatPos_XY_rate_Value) {
    controlAerobi_B.rtb_Abs_c_e = controlAerobi_P.SatPos_XY_rate_Value;
  } else if (controlAerobi_B.rtb_R_d_m_tmp_j <
             controlAerobi_P.SatNeg_XY_rate_Value) {
    // Switch: '<S65>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_XY_rate'

    controlAerobi_B.rtb_Abs_c_e = controlAerobi_P.SatNeg_XY_rate_Value;
  } else {
    controlAerobi_B.rtb_Abs_c_e = controlAerobi_B.rtb_R_d_m_tmp_j;
  }

  // Switch: '<S52>/Switch3' incorporates:
  //   Constant: '<S52>/pid//pid_cascade'

  if (controlAerobi_P.pidpid_cascade_Value != 0.0) {
    controlAerobi_B.rtb_Switch3_idx_0 = controlAerobi_B.rtb_Abs_o_idx_0;
  } else {
    controlAerobi_B.rtb_Switch3_idx_0 = controlAerobi_B.rtb_Abs_c_e;
  }

  // SampleTimeMath: '<S64>/TSamp'
  //
  //  About '<S64>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_TSamp_j_idx_0 = controlAerobi_B.rtb_R_d_m_tmp;

  // Sum: '<S57>/Sum'
  controlAerobi_B.rtb_Sum_oc_idx_0 = controlAerobi_B.rtb_R_d_m_tmp_j;

  // Switch: '<S65>/Switch2'
  controlAerobi_B.rtb_Abs_c_idx_0 = controlAerobi_B.rtb_Abs_c_e;

  // SampleTimeMath: '<S64>/TSamp' incorporates:
  //   Constant: '<S95>/D_XY_rate'
  //   Product: '<S57>/Product2'
  //
  //  About '<S64>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_R_d_m_tmp = controlAerobi_P.D_XY_rate_Value *
    controlAerobi_B.rtb_Product1_a_idx_1 * controlAerobi_P.TSamp_WtEt_b;

  // Sum: '<S57>/Sum' incorporates:
  //   Constant: '<S95>/P_XY_rate'
  //   DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
  //   Product: '<S57>/Product'
  //   Sum: '<S64>/Diff'
  //   UnitDelay: '<S64>/UD'

  controlAerobi_B.rtb_R_d_m_tmp_j = (controlAerobi_P.P_XY_rate_Value *
    controlAerobi_B.rtb_Product1_a_idx_1 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_fo[1]) +
    (controlAerobi_B.rtb_R_d_m_tmp - controlAerobi_DWork.UD_DSTATE_o[1]);

  // Switch: '<S65>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_XY_rate'
  //   Constant: '<S95>/SatPos_XY_rate'
  //   RelationalOperator: '<S65>/LowerRelop1'
  //   RelationalOperator: '<S65>/UpperRelop'
  //   Switch: '<S65>/Switch'

  if (controlAerobi_B.rtb_R_d_m_tmp_j > controlAerobi_P.SatPos_XY_rate_Value) {
    controlAerobi_B.rtb_Abs_c_e = controlAerobi_P.SatPos_XY_rate_Value;
  } else if (controlAerobi_B.rtb_R_d_m_tmp_j <
             controlAerobi_P.SatNeg_XY_rate_Value) {
    // Switch: '<S65>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_XY_rate'

    controlAerobi_B.rtb_Abs_c_e = controlAerobi_P.SatNeg_XY_rate_Value;
  } else {
    controlAerobi_B.rtb_Abs_c_e = controlAerobi_B.rtb_R_d_m_tmp_j;
  }

  // Switch: '<S52>/Switch3' incorporates:
  //   Constant: '<S52>/pid//pid_cascade'

  if (controlAerobi_P.pidpid_cascade_Value != 0.0) {
    controlAerobi_B.rtb_Switch3_idx_1 = controlAerobi_B.rtb_Abs_o_d;
  } else {
    controlAerobi_B.rtb_Switch3_idx_1 = controlAerobi_B.rtb_Abs_c_e;
  }

  // Switch: '<S29>/Switch2'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/Create RollPitchdesired': '<S54>:1' 
  // '<S54>:1:3'
  if (controlAerobi_B.POS_HOLD) {
    // MATLAB Function: '<S52>/Create RollPitchdesired' incorporates:
    //   Constant: '<S52>/p'
    //   Constant: '<S52>/r'

    controlAerobi_B.rtb_Switch2_o_idx_0 = (controlAerobi_P.r_Value *
      controlAerobi_B.rtb_Switch3_idx_0 * controlAerobi_B.ubx_tmp_a -
      controlAerobi_P.p_Value * controlAerobi_B.rtb_Switch3_idx_1 *
      controlAerobi_B.ubx_tmp) * 0.1019367991845056;

    // Saturate: '<S52>/Saturation2'
    if (controlAerobi_B.rtb_Switch2_o_idx_0 >
        controlAerobi_P.Saturation2_UpperSat) {
      controlAerobi_B.rtb_Switch2_o_idx_0 = controlAerobi_P.Saturation2_UpperSat;
    } else {
      if (controlAerobi_B.rtb_Switch2_o_idx_0 <
          controlAerobi_P.Saturation2_LowerSat) {
        controlAerobi_B.rtb_Switch2_o_idx_0 =
          controlAerobi_P.Saturation2_LowerSat;
      }
    }

    // MATLAB Function: '<S52>/Create RollPitchdesired' incorporates:
    //   Constant: '<S52>/r1'
    //   Constant: '<S52>/r2'
    //   Gain: '<S52>/Gain'

    controlAerobi_B.rtb_Switch2_o_idx_1 = 1.0 / (cos(controlAerobi_P.Gain_Gain_e
      * controlAerobi_B.Gain_po[0]) * 9.81) * (controlAerobi_P.r1_Value *
      controlAerobi_B.rtb_Switch3_idx_0 * controlAerobi_B.ubx_tmp +
      controlAerobi_P.r2_Value * controlAerobi_B.rtb_Switch3_idx_1 *
      controlAerobi_B.ubx_tmp_a);

    // Saturate: '<S52>/Saturation2'
    if (controlAerobi_B.rtb_Switch2_o_idx_1 >
        controlAerobi_P.Saturation2_UpperSat) {
      controlAerobi_B.rtb_Switch2_o_idx_1 = controlAerobi_P.Saturation2_UpperSat;
    } else {
      if (controlAerobi_B.rtb_Switch2_o_idx_1 <
          controlAerobi_P.Saturation2_LowerSat) {
        controlAerobi_B.rtb_Switch2_o_idx_1 =
          controlAerobi_P.Saturation2_LowerSat;
      }
    }
  } else {
    controlAerobi_B.rtb_Switch2_o_idx_0 = controlAerobi_B.absxk;
    controlAerobi_B.rtb_Switch2_o_idx_1 = controlAerobi_B.t;
  }

  // End of Switch: '<S29>/Switch2'

  // Logic: '<S29>/Logical Operator' incorporates:
  //   Logic: '<S29>/Logical Operator1'

  rtb_LogicalOperator1 = ((!rtb_EnableGeometricControl) &&
    controlAerobi_B.Compare);

  // Switch: '<S34>/Switch4' incorporates:
  //   Constant: '<S34>/Constant1'
  //   Sum: '<S29>/Sum6'

  if (rtb_LogicalOperator1) {
    controlAerobi_B.rtb_Switch3_idx_0 = controlAerobi_B.rtb_Switch2_o_idx_0 -
      controlAerobi_B.Gain_po[0];
    controlAerobi_B.rtb_Switch3_idx_1 = controlAerobi_B.rtb_Switch2_o_idx_1 -
      controlAerobi_B.Gain_po[1];
  } else {
    controlAerobi_B.rtb_Switch3_idx_0 = controlAerobi_P.Constant1_Value_h;
    controlAerobi_B.rtb_Switch3_idx_1 = controlAerobi_P.Constant1_Value_h;
  }

  // End of Switch: '<S34>/Switch4'

  // DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  if (rtb_LogicalOperator1 &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_p <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n2[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_f;
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n2[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_f;
  }

  // SampleTimeMath: '<S45>/TSamp' incorporates:
  //   Constant: '<S95>/D_RollPitch_pos'
  //   Product: '<S34>/Product2'
  //
  //  About '<S45>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_TSamp_i_b = controlAerobi_P.D_RollPitch_pos_Value *
    controlAerobi_B.rtb_Switch3_idx_0 * controlAerobi_P.TSamp_WtEt_n;

  // Sum: '<S34>/Sum' incorporates:
  //   Constant: '<S95>/P_RollPitch_pos'
  //   DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  //   Product: '<S34>/Product'
  //   Sum: '<S45>/Diff'
  //   UnitDelay: '<S45>/UD'

  controlAerobi_B.rtb_Sum_cw_j = (controlAerobi_P.P_RollPitch_pos_Value *
    controlAerobi_B.rtb_Switch3_idx_0 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n2[0]) +
    (controlAerobi_B.rtb_TSamp_i_b - controlAerobi_DWork.UD_DSTATE_oo[0]);

  // Switch: '<S46>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_RollPitch_pos'
  //   Constant: '<S95>/SatPos_RollPitch_pos'
  //   RelationalOperator: '<S46>/LowerRelop1'
  //   RelationalOperator: '<S46>/UpperRelop'
  //   Switch: '<S46>/Switch'

  if (controlAerobi_B.rtb_Sum_cw_j > controlAerobi_P.SatPos_RollPitch_pos_Value)
  {
    controlAerobi_B.rtb_Abs_l_idx_0 = controlAerobi_P.SatPos_RollPitch_pos_Value;
  } else if (controlAerobi_B.rtb_Sum_cw_j <
             controlAerobi_P.SatNeg_RollPitch_pos_Value) {
    // Switch: '<S46>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_RollPitch_pos'

    controlAerobi_B.rtb_Abs_l_idx_0 = controlAerobi_P.SatNeg_RollPitch_pos_Value;
  } else {
    controlAerobi_B.rtb_Abs_l_idx_0 = controlAerobi_B.rtb_Sum_cw_j;
  }

  // SampleTimeMath: '<S45>/TSamp'
  //
  //  About '<S45>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_TSamp_i_idx_0 = controlAerobi_B.rtb_TSamp_i_b;

  // Sum: '<S34>/Sum'
  controlAerobi_B.rtb_Sum_cw_idx_0 = controlAerobi_B.rtb_Sum_cw_j;

  // SampleTimeMath: '<S45>/TSamp' incorporates:
  //   Constant: '<S95>/D_RollPitch_pos'
  //   Product: '<S34>/Product2'
  //
  //  About '<S45>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_TSamp_i_b = controlAerobi_P.D_RollPitch_pos_Value *
    controlAerobi_B.rtb_Switch3_idx_1 * controlAerobi_P.TSamp_WtEt_n;

  // Sum: '<S34>/Sum' incorporates:
  //   Constant: '<S95>/P_RollPitch_pos'
  //   DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  //   Product: '<S34>/Product'
  //   Sum: '<S45>/Diff'
  //   UnitDelay: '<S45>/UD'

  controlAerobi_B.rtb_Sum_cw_j = (controlAerobi_P.P_RollPitch_pos_Value *
    controlAerobi_B.rtb_Switch3_idx_1 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n2[1]) +
    (controlAerobi_B.rtb_TSamp_i_b - controlAerobi_DWork.UD_DSTATE_oo[1]);

  // Switch: '<S46>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_RollPitch_pos'
  //   Constant: '<S95>/SatPos_RollPitch_pos'
  //   RelationalOperator: '<S46>/LowerRelop1'
  //   RelationalOperator: '<S46>/UpperRelop'
  //   Switch: '<S46>/Switch'

  if (controlAerobi_B.rtb_Sum_cw_j > controlAerobi_P.SatPos_RollPitch_pos_Value)
  {
    controlAerobi_B.rtb_Abs_l_idx_1 = controlAerobi_P.SatPos_RollPitch_pos_Value;
  } else if (controlAerobi_B.rtb_Sum_cw_j <
             controlAerobi_P.SatNeg_RollPitch_pos_Value) {
    // Switch: '<S46>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_RollPitch_pos'

    controlAerobi_B.rtb_Abs_l_idx_1 = controlAerobi_P.SatNeg_RollPitch_pos_Value;
  } else {
    controlAerobi_B.rtb_Abs_l_idx_1 = controlAerobi_B.rtb_Sum_cw_j;
  }

  // Switch: '<S29>/Switch' incorporates:
  //   Constant: '<S155>/rollPitch_pos_rate'
  //   Gain: '<S29>/Gain1'

  if (controlAerobi_P.rollPitch_pos_rate_Value) {
    controlAerobi_B.rtb_Switch_b_idx_0 = controlAerobi_B.rtb_Abs_l_idx_0;
    controlAerobi_B.rtb_Switch_b_idx_1 = controlAerobi_B.rtb_Abs_l_idx_1;
  } else {
    controlAerobi_B.rtb_Switch_b_idx_0 = controlAerobi_P.Gain1_Gain *
      controlAerobi_B.rtb_Switch2_o_idx_0;
    controlAerobi_B.rtb_Switch_b_idx_1 = controlAerobi_P.Gain1_Gain *
      controlAerobi_B.rtb_Switch2_o_idx_1;
  }

  // End of Switch: '<S29>/Switch'

  // Switch: '<S32>/Switch4' incorporates:
  //   Constant: '<S32>/Constant1'
  //   Sum: '<S29>/Sum2'

  if (rtb_LogicalOperator1) {
    controlAerobi_B.rtb_Product1_kp_idx_0 = controlAerobi_B.rtb_Switch_b_idx_0 -
      controlAerobi_B.Add[1];
    controlAerobi_B.rtb_Product1_kp_idx_1 = controlAerobi_B.rtb_Switch_b_idx_1 -
      controlAerobi_B.Add[0];
  } else {
    controlAerobi_B.rtb_Product1_kp_idx_0 = controlAerobi_P.Constant1_Value;
    controlAerobi_B.rtb_Product1_kp_idx_1 = controlAerobi_P.Constant1_Value;
  }

  // End of Switch: '<S32>/Switch4'

  // DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
  if (rtb_LogicalOperator1 &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_gz <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_h[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_ly;
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_h[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_ly;
  }

  // SampleTimeMath: '<S37>/TSamp' incorporates:
  //   Constant: '<S95>/D_RollPitch_rate'
  //   Product: '<S32>/Product2'
  //
  //  About '<S37>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.ubx_tmp = controlAerobi_P.D_RollPitch_rate_Value *
    controlAerobi_B.rtb_Product1_kp_idx_0 * controlAerobi_P.TSamp_WtEt_e;

  // Sum: '<S32>/Sum' incorporates:
  //   Constant: '<S95>/P_RollPitch_rate'
  //   DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
  //   Product: '<S32>/Product'
  //   Sum: '<S37>/Diff'
  //   UnitDelay: '<S37>/UD'

  controlAerobi_B.ubx_tmp_a = (controlAerobi_P.P_RollPitch_rate_Value *
    controlAerobi_B.rtb_Product1_kp_idx_0 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_h[0]) +
    (controlAerobi_B.ubx_tmp - controlAerobi_DWork.UD_DSTATE_i[0]);

  // Switch: '<S38>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_RollPitch_rate'
  //   Constant: '<S95>/SatPos_RollPitch_rate'
  //   RelationalOperator: '<S38>/LowerRelop1'
  //   RelationalOperator: '<S38>/UpperRelop'
  //   Switch: '<S38>/Switch'

  if (controlAerobi_B.ubx_tmp_a > controlAerobi_P.SatPos_RollPitch_rate_Value) {
    controlAerobi_B.ubx_tmp_j = controlAerobi_P.SatPos_RollPitch_rate_Value;
  } else if (controlAerobi_B.ubx_tmp_a <
             controlAerobi_P.SatNeg_RollPitch_rate_Value) {
    // Switch: '<S38>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_RollPitch_rate'

    controlAerobi_B.ubx_tmp_j = controlAerobi_P.SatNeg_RollPitch_rate_Value;
  } else {
    controlAerobi_B.ubx_tmp_j = controlAerobi_B.ubx_tmp_a;
  }

  // Sum: '<S29>/Sum3' incorporates:
  //   Constant: '<S29>/Constant'

  controlAerobi_B.rtb_Zgain_idx_0 = controlAerobi_B.ubx_tmp_j +
    controlAerobi_P.Constant_Value_j[0];

  // SampleTimeMath: '<S37>/TSamp'
  //
  //  About '<S37>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.rtb_TSamp_n_idx_0 = controlAerobi_B.ubx_tmp;

  // Sum: '<S32>/Sum'
  controlAerobi_B.rtb_Sum_m_idx_0 = controlAerobi_B.ubx_tmp_a;

  // Switch: '<S38>/Switch2'
  controlAerobi_B.rtb_Abs_f_idx_0 = controlAerobi_B.ubx_tmp_j;

  // SampleTimeMath: '<S37>/TSamp' incorporates:
  //   Constant: '<S95>/D_RollPitch_rate'
  //   Product: '<S32>/Product2'
  //
  //  About '<S37>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.ubx_tmp = controlAerobi_P.D_RollPitch_rate_Value *
    controlAerobi_B.rtb_Product1_kp_idx_1 * controlAerobi_P.TSamp_WtEt_e;

  // Sum: '<S32>/Sum' incorporates:
  //   Constant: '<S95>/P_RollPitch_rate'
  //   DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
  //   Product: '<S32>/Product'
  //   Sum: '<S37>/Diff'
  //   UnitDelay: '<S37>/UD'

  controlAerobi_B.ubx_tmp_a = (controlAerobi_P.P_RollPitch_rate_Value *
    controlAerobi_B.rtb_Product1_kp_idx_1 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_h[1]) +
    (controlAerobi_B.ubx_tmp - controlAerobi_DWork.UD_DSTATE_i[1]);

  // Switch: '<S38>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_RollPitch_rate'
  //   Constant: '<S95>/SatPos_RollPitch_rate'
  //   RelationalOperator: '<S38>/LowerRelop1'
  //   RelationalOperator: '<S38>/UpperRelop'
  //   Switch: '<S38>/Switch'

  if (controlAerobi_B.ubx_tmp_a > controlAerobi_P.SatPos_RollPitch_rate_Value) {
    controlAerobi_B.ubx_tmp_j = controlAerobi_P.SatPos_RollPitch_rate_Value;
  } else if (controlAerobi_B.ubx_tmp_a <
             controlAerobi_P.SatNeg_RollPitch_rate_Value) {
    // Switch: '<S38>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_RollPitch_rate'

    controlAerobi_B.ubx_tmp_j = controlAerobi_P.SatNeg_RollPitch_rate_Value;
  } else {
    controlAerobi_B.ubx_tmp_j = controlAerobi_B.ubx_tmp_a;
  }

  // Switch: '<S8>/Switch' incorporates:
  //   Constant: '<S29>/Constant'
  //   Sum: '<S29>/Sum3'
  //   Switch: '<S8>/Switch1'

  if (rtb_EnableGeometricControl) {
    controlAerobi_B.rtb_Zgain_idx_0 = controlAerobi_B.Switch_ed[1];
    controlAerobi_B.TSamp_hv = controlAerobi_B.Switch_ed[2];
  } else {
    controlAerobi_B.TSamp_hv = controlAerobi_B.ubx_tmp_j +
      controlAerobi_P.Constant_Value_j[1];
  }

  // End of Switch: '<S8>/Switch'

  // Gain: '<S91>/Gain3'
  controlAerobi_B.rtb_Zgain_idx_0 *= controlAerobi_P.Gain3_Gain_l;

  // Gain: '<S91>/Gain5'
  controlAerobi_B.Gain5 = controlAerobi_P.Gain5_Gain_m *
    controlAerobi_B.TSamp_hv;

  // DeadZone: '<S29>/Dead Zone1'
  if (controlAerobi_B.r_x_idx_0 > controlAerobi_P.DeadZone1_End_a) {
    controlAerobi_B.DeadZone1 = controlAerobi_B.r_x_idx_0 -
      controlAerobi_P.DeadZone1_End_a;
  } else if (controlAerobi_B.r_x_idx_0 >= controlAerobi_P.DeadZone1_Start_c) {
    controlAerobi_B.DeadZone1 = 0.0;
  } else {
    controlAerobi_B.DeadZone1 = controlAerobi_B.r_x_idx_0 -
      controlAerobi_P.DeadZone1_Start_c;
  }

  // End of DeadZone: '<S29>/Dead Zone1'

  // MATLAB Function: '<S29>/Continuous Yaw Generator'
  // MATLAB Function 'Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/Continuous Yaw Generator': '<S31>:1' 
  if ((!controlAerobi_DWork.yaw_references_not_empty) ||
      (!controlAerobi_DWork.yaw_position_old_not_empty) ||
      (!controlAerobi_DWork.n_not_empty)) {
    // '<S31>:1:5'
    // '<S31>:1:6'
    controlAerobi_DWork.yaw_references = 0.0;
    controlAerobi_DWork.yaw_references_not_empty = true;

    // '<S31>:1:7'
    controlAerobi_DWork.yaw_position_old = controlAerobi_B.Gain_po[2];
    controlAerobi_DWork.yaw_position_old_not_empty = true;

    // '<S31>:1:8'
    controlAerobi_DWork.n = 0.0;
    controlAerobi_DWork.n_not_empty = true;
  } else if (!controlAerobi_B.Compare) {
    // '<S31>:1:10'
    // '<S31>:1:11'
    controlAerobi_DWork.yaw_references = controlAerobi_DWork.n * 2.0 *
      3.1415926535897931 + controlAerobi_B.Gain_po[2];
  } else {
    controlAerobi_B.Gain7 = controlAerobi_B.Gain_po[2] -
      controlAerobi_DWork.yaw_position_old;
    if (controlAerobi_B.Gain7 < -3.1415926535897931) {
      // '<S31>:1:14'
      // '<S31>:1:15'
      controlAerobi_DWork.n++;
    } else {
      if (controlAerobi_B.Gain7 > 3.1415926535897931) {
        // '<S31>:1:16'
        // '<S31>:1:17'
        controlAerobi_DWork.n--;
      }
    }

    // '<S31>:1:19'
    controlAerobi_DWork.yaw_position_old = controlAerobi_B.Gain_po[2];

    // '<S31>:1:20'
    controlAerobi_DWork.yaw_references += controlAerobi_B.DeadZone1 * 0.015;
  }

  // Switch: '<S35>/Switch4' incorporates:
  //   Constant: '<S35>/Constant1'
  //   MATLAB Function: '<S29>/Continuous Yaw Generator'
  //   Sum: '<S29>/Sum1'

  // '<S31>:1:23'
  // '<S31>:1:24'
  if (controlAerobi_B.Compare) {
    controlAerobi_B.r_x_idx_0 = controlAerobi_DWork.yaw_references -
      (controlAerobi_DWork.n * 2.0 * 3.1415926535897931 +
       controlAerobi_B.Gain_po[2]);
  } else {
    controlAerobi_B.r_x_idx_0 = controlAerobi_P.Constant1_Value_j;
  }

  // End of Switch: '<S35>/Switch4'

  // DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
  if (controlAerobi_B.Compare &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_l3 <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_l =
      controlAerobi_P.DiscreteTimeIntegrator_IC_cx;
  }

  // SampleTimeMath: '<S49>/TSamp' incorporates:
  //   Constant: '<S95>/D_Yaw_pos'
  //   Product: '<S35>/Product2'
  //
  //  About '<S49>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.TSamp_hv = controlAerobi_P.D_Yaw_pos_Value *
    controlAerobi_B.r_x_idx_0 * controlAerobi_P.TSamp_WtEt_o;

  // Sum: '<S35>/Sum' incorporates:
  //   Constant: '<S95>/P_Yaw_pos'
  //   DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
  //   Product: '<S35>/Product'
  //   Sum: '<S49>/Diff'
  //   UnitDelay: '<S49>/UD'

  controlAerobi_B.Sum_f = (controlAerobi_P.P_Yaw_pos_Value *
    controlAerobi_B.r_x_idx_0 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_l) +
    (controlAerobi_B.TSamp_hv - controlAerobi_DWork.UD_DSTATE_j);

  // Switch: '<S50>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_Yaw_pos'
  //   Constant: '<S95>/SatPos_Yaw_pos'
  //   RelationalOperator: '<S50>/LowerRelop1'
  //   RelationalOperator: '<S50>/UpperRelop'
  //   Switch: '<S50>/Switch'

  if (controlAerobi_B.Sum_f > controlAerobi_P.SatPos_Yaw_pos_Value) {
    controlAerobi_B.Abs_k = controlAerobi_P.SatPos_Yaw_pos_Value;
  } else if (controlAerobi_B.Sum_f < controlAerobi_P.SatNeg_Yaw_pos_Value) {
    // Switch: '<S50>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_Yaw_pos'

    controlAerobi_B.Abs_k = controlAerobi_P.SatNeg_Yaw_pos_Value;
  } else {
    controlAerobi_B.Abs_k = controlAerobi_B.Sum_f;
  }

  // End of Switch: '<S50>/Switch2'

  // Switch: '<S29>/Switch1' incorporates:
  //   Constant: '<S155>/yaw_pos_rate'
  //   Gain: '<S29>/Gain'

  if (controlAerobi_P.yaw_pos_rate_Value) {
    controlAerobi_B.DeadZone1 = controlAerobi_B.Abs_k;
  } else {
    controlAerobi_B.DeadZone1 *= controlAerobi_P.Gain_Gain;
  }

  // End of Switch: '<S29>/Switch1'

  // Switch: '<S33>/Switch4' incorporates:
  //   Constant: '<S33>/Constant1'
  //   Sum: '<S29>/Sum5'

  if (controlAerobi_B.Compare) {
    controlAerobi_B.Switch4 = controlAerobi_B.DeadZone1 - controlAerobi_B.dyaw;
  } else {
    controlAerobi_B.Switch4 = controlAerobi_P.Constant1_Value_o;
  }

  // End of Switch: '<S33>/Switch4'

  // DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
  if (controlAerobi_B.Compare &&
      (controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_cu <= 0)) {
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_o =
      controlAerobi_P.DiscreteTimeIntegrator_IC_a;
  }

  // SampleTimeMath: '<S41>/TSamp' incorporates:
  //   Constant: '<S95>/D_Yaw_rate'
  //   Product: '<S33>/Product2'
  //
  //  About '<S41>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  controlAerobi_B.TSamp_iz = controlAerobi_P.D_Yaw_rate_Value *
    controlAerobi_B.Switch4 * controlAerobi_P.TSamp_WtEt_p;

  // Sum: '<S33>/Sum' incorporates:
  //   Constant: '<S95>/P_Yaw_rate'
  //   DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
  //   Product: '<S33>/Product'
  //   Sum: '<S41>/Diff'
  //   UnitDelay: '<S41>/UD'

  controlAerobi_B.Sum_c = (controlAerobi_P.P_Yaw_rate_Value *
    controlAerobi_B.Switch4 +
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_o) +
    (controlAerobi_B.TSamp_iz - controlAerobi_DWork.UD_DSTATE_j5);

  // Switch: '<S42>/Switch2' incorporates:
  //   Constant: '<S95>/SatNeg_Yaw_rate'
  //   Constant: '<S95>/SatPos_Yaw_rate'
  //   RelationalOperator: '<S42>/LowerRelop1'
  //   RelationalOperator: '<S42>/UpperRelop'
  //   Switch: '<S42>/Switch'

  if (controlAerobi_B.Sum_c > controlAerobi_P.SatPos_Yaw_rate_Value) {
    controlAerobi_B.Abs_g = controlAerobi_P.SatPos_Yaw_rate_Value;
  } else if (controlAerobi_B.Sum_c < controlAerobi_P.SatNeg_Yaw_rate_Value) {
    // Switch: '<S42>/Switch' incorporates:
    //   Constant: '<S95>/SatNeg_Yaw_rate'

    controlAerobi_B.Abs_g = controlAerobi_P.SatNeg_Yaw_rate_Value;
  } else {
    controlAerobi_B.Abs_g = controlAerobi_B.Sum_c;
  }

  // End of Switch: '<S42>/Switch2'

  // Gain: '<S91>/Gain7'
  controlAerobi_B.Gain7 = controlAerobi_P.Gain7_Gain * controlAerobi_B.Abs_g;

  // Sum: '<S7>/Sum' incorporates:
  //   Sum: '<S7>/Sum3'

  controlAerobi_B.rtb_Switch_ed_f = controlAerobi_B.Switch2_n -
    controlAerobi_B.rtb_Zgain_idx_0;

  // Sum: '<S7>/Sum1' incorporates:
  //   Sum: '<S7>/Sum2'

  controlAerobi_B.rtb_Gain1_k_idx_0 = controlAerobi_B.Switch2_n +
    controlAerobi_B.rtb_Zgain_idx_0;

  // Product: '<S90>/Product' incorporates:
  //   Gain: '<S7>/scale2ticks'
  //   Sum: '<S7>/Sum'
  //   Sum: '<S7>/Sum1'
  //   Sum: '<S7>/Sum2'
  //   Sum: '<S7>/Sum3'

  controlAerobi_B.Switch2_n = controlAerobi_P.scale2ticks_Gain *
    ((controlAerobi_B.rtb_Switch_ed_f + controlAerobi_B.Gain5) +
     controlAerobi_B.Gain7) * controlAerobi_B.Switch_b5;
  controlAerobi_B.rtb_Zgain_idx_0 = controlAerobi_P.scale2ticks_Gain *
    ((controlAerobi_B.rtb_Gain1_k_idx_0 - controlAerobi_B.Gain5) +
     controlAerobi_B.Gain7) * controlAerobi_B.Switch_b5;
  controlAerobi_B.rtb_Gain1_k_idx_0 = controlAerobi_P.scale2ticks_Gain *
    ((controlAerobi_B.rtb_Gain1_k_idx_0 + controlAerobi_B.Gain5) -
     controlAerobi_B.Gain7) * controlAerobi_B.Switch_b5;
  controlAerobi_B.Switch_b5 *= controlAerobi_P.scale2ticks_Gain *
    ((controlAerobi_B.rtb_Switch_ed_f - controlAerobi_B.Gain5) -
     controlAerobi_B.Gain7);
  controlAerobi_B.rtb_Switch_ed_f = controlAerobi_B.Switch2_n;

  // Switch: '<S92>/Switch' incorporates:
  //   Constant: '<S7>/Constant3'
  //   Product: '<S90>/Product'
  //   RelationalOperator: '<S92>/UpperRelop'

  if (controlAerobi_B.Switch2_n < controlAerobi_P.Constant3_Value) {
    controlAerobi_B.rtb_Switch_ed_f = controlAerobi_P.Constant3_Value;
  }

  // Switch: '<S92>/Switch2' incorporates:
  //   Constant: '<S7>/Constant'
  //   Product: '<S90>/Product'
  //   RelationalOperator: '<S92>/LowerRelop1'

  if (controlAerobi_B.Switch2_n > controlAerobi_P.Constant_Value_o) {
    controlAerobi_B.rtb_Switch_ed_f = controlAerobi_P.Constant_Value_o;
  }

  // DataTypeConversion: '<S89>/Data Type Conversion'
  rtb_DataTypeConversion_a_idx_0 = (real32_T)controlAerobi_B.rtb_Switch_ed_f;

  // Switch: '<S92>/Switch' incorporates:
  //   RelationalOperator: '<S92>/UpperRelop'

  controlAerobi_B.Switch_ed[0] = controlAerobi_B.rtb_Switch_ed_f;
  controlAerobi_B.rtb_Switch_ed_f = controlAerobi_B.rtb_Zgain_idx_0;

  // Switch: '<S92>/Switch' incorporates:
  //   Constant: '<S7>/Constant3'
  //   Product: '<S90>/Product'
  //   RelationalOperator: '<S92>/UpperRelop'

  if (controlAerobi_B.rtb_Zgain_idx_0 < controlAerobi_P.Constant3_Value) {
    controlAerobi_B.rtb_Switch_ed_f = controlAerobi_P.Constant3_Value;
  }

  // Switch: '<S92>/Switch2' incorporates:
  //   Constant: '<S7>/Constant'
  //   Product: '<S90>/Product'
  //   RelationalOperator: '<S92>/LowerRelop1'

  if (controlAerobi_B.rtb_Zgain_idx_0 > controlAerobi_P.Constant_Value_o) {
    controlAerobi_B.rtb_Switch_ed_f = controlAerobi_P.Constant_Value_o;
  }

  // DataTypeConversion: '<S89>/Data Type Conversion'
  rtb_DataTypeConversion_a_idx_1 = (real32_T)controlAerobi_B.rtb_Switch_ed_f;

  // Switch: '<S92>/Switch' incorporates:
  //   RelationalOperator: '<S92>/UpperRelop'

  controlAerobi_B.Switch_ed[1] = controlAerobi_B.rtb_Switch_ed_f;
  controlAerobi_B.rtb_Switch_ed_f = controlAerobi_B.rtb_Gain1_k_idx_0;

  // Switch: '<S92>/Switch' incorporates:
  //   Constant: '<S7>/Constant3'
  //   Product: '<S90>/Product'
  //   RelationalOperator: '<S92>/UpperRelop'

  if (controlAerobi_B.rtb_Gain1_k_idx_0 < controlAerobi_P.Constant3_Value) {
    controlAerobi_B.rtb_Switch_ed_f = controlAerobi_P.Constant3_Value;
  }

  // Switch: '<S92>/Switch2' incorporates:
  //   Constant: '<S7>/Constant'
  //   Product: '<S90>/Product'
  //   RelationalOperator: '<S92>/LowerRelop1'

  if (controlAerobi_B.rtb_Gain1_k_idx_0 > controlAerobi_P.Constant_Value_o) {
    controlAerobi_B.rtb_Switch_ed_f = controlAerobi_P.Constant_Value_o;
  }

  // DataTypeConversion: '<S89>/Data Type Conversion'
  rtb_DataTypeConversion_a_idx_2 = (real32_T)controlAerobi_B.rtb_Switch_ed_f;

  // Switch: '<S92>/Switch' incorporates:
  //   RelationalOperator: '<S92>/UpperRelop'

  controlAerobi_B.Switch_ed[2] = controlAerobi_B.rtb_Switch_ed_f;
  controlAerobi_B.rtb_Switch_ed_f = controlAerobi_B.Switch_b5;

  // Switch: '<S92>/Switch' incorporates:
  //   Constant: '<S7>/Constant3'
  //   Product: '<S90>/Product'
  //   RelationalOperator: '<S92>/UpperRelop'

  if (controlAerobi_B.Switch_b5 < controlAerobi_P.Constant3_Value) {
    controlAerobi_B.rtb_Switch_ed_f = controlAerobi_P.Constant3_Value;
  }

  // Switch: '<S92>/Switch2' incorporates:
  //   Constant: '<S7>/Constant'
  //   Product: '<S90>/Product'
  //   RelationalOperator: '<S92>/LowerRelop1'

  if (controlAerobi_B.Switch_b5 > controlAerobi_P.Constant_Value_o) {
    controlAerobi_B.rtb_Switch_ed_f = controlAerobi_P.Constant_Value_o;
  }

  // ManualSwitch: '<S89>/Manual Switch2'
  if (controlAerobi_P.ManualSwitch2_CurrentSetting == 1) {
    // Outport: '<Root>/O_servoOut' incorporates:
    //   Constant: '<S89>/Constant4'

    controlAerobi_Y.O_servoOut._channel1 = controlAerobi_P.Constant4_Value_k;
  } else {
    // Outport: '<Root>/O_servoOut'
    controlAerobi_Y.O_servoOut._channel1 = rtb_DataTypeConversion_a_idx_0;
  }

  // End of ManualSwitch: '<S89>/Manual Switch2'

  // ManualSwitch: '<S89>/Manual Switch13'
  if (controlAerobi_P.ManualSwitch13_CurrentSetting == 1) {
    // Outport: '<Root>/O_servoOut' incorporates:
    //   Constant: '<S89>/Constant15'

    controlAerobi_Y.O_servoOut._channel2 = controlAerobi_P.Constant15_Value;
  } else {
    // Outport: '<Root>/O_servoOut'
    controlAerobi_Y.O_servoOut._channel2 = rtb_DataTypeConversion_a_idx_1;
  }

  // End of ManualSwitch: '<S89>/Manual Switch13'

  // ManualSwitch: '<S89>/Manual Switch14'
  if (controlAerobi_P.ManualSwitch14_CurrentSetting == 1) {
    // Outport: '<Root>/O_servoOut' incorporates:
    //   Constant: '<S89>/Constant16'

    controlAerobi_Y.O_servoOut._channel3 = controlAerobi_P.Constant16_Value;
  } else {
    // Outport: '<Root>/O_servoOut'
    controlAerobi_Y.O_servoOut._channel3 = rtb_DataTypeConversion_a_idx_2;
  }

  // End of ManualSwitch: '<S89>/Manual Switch14'

  // ManualSwitch: '<S89>/Manual Switch15'
  if (controlAerobi_P.ManualSwitch15_CurrentSetting == 1) {
    // Outport: '<Root>/O_servoOut' incorporates:
    //   Constant: '<S89>/Constant17'

    controlAerobi_Y.O_servoOut._channel4 = controlAerobi_P.Constant17_Value;
  } else {
    // Outport: '<Root>/O_servoOut' incorporates:
    //   DataTypeConversion: '<S89>/Data Type Conversion'

    controlAerobi_Y.O_servoOut._channel4 = (real32_T)
      controlAerobi_B.rtb_Switch_ed_f;
  }

  // End of ManualSwitch: '<S89>/Manual Switch15'

  // Outport: '<Root>/O_servoOut' incorporates:
  //   Constant: '<S89>/Constant10'
  //   Constant: '<S89>/Constant11'
  //   Constant: '<S89>/Constant12'
  //   Constant: '<S89>/Constant14'
  //   Constant: '<S89>/Constant18'
  //   Constant: '<S89>/Constant5'
  //   Constant: '<S89>/Constant6'
  //   Constant: '<S89>/Constant7'
  //   Constant: '<S89>/Constant8'
  //   Constant: '<S89>/Constant9'

  controlAerobi_Y.O_servoOut._channel5 = controlAerobi_P.Constant5_Value_p;
  controlAerobi_Y.O_servoOut._channel6 = controlAerobi_P.Constant6_Value_i;
  controlAerobi_Y.O_servoOut._channel7 = controlAerobi_P.Constant7_Value_c;
  controlAerobi_Y.O_servoOut._channel8 = controlAerobi_P.Constant8_Value_d;
  controlAerobi_Y.O_servoOut._channel9 = controlAerobi_P.Constant9_Value;
  controlAerobi_Y.O_servoOut._channel10 = controlAerobi_P.Constant18_Value;
  controlAerobi_Y.O_servoOut._channel11 = controlAerobi_P.Constant10_Value;
  controlAerobi_Y.O_servoOut._channel12 = controlAerobi_P.Constant11_Value;
  controlAerobi_Y.O_servoOut._channel13 = controlAerobi_P.Constant12_Value;
  controlAerobi_Y.O_servoOut._channel14 = controlAerobi_P.Constant14_Value;

  // Outport: '<Root>/StateMode'
  controlAerobi_Y.StateMode[0] = controlAerobi_B.Compare;
  controlAerobi_Y.StateMode[1] = controlAerobi_B.ALTHOLD;
  controlAerobi_Y.StateMode[2] = controlAerobi_B.POS_HOLD;

  // Gain: '<S3>/Gain'
  controlAerobi_B.rtb_Zgain_idx_0 = controlAerobi_P.Gain_Gain_i2 *
    controlAerobi_B.Gain_po[0];
  controlAerobi_B.Switch2_n = controlAerobi_P.Gain_Gain_i2 *
    controlAerobi_B.rtb_Switch2_o_idx_0;

  // Gain: '<S3>/Gain1'
  controlAerobi_B.rtb_Gain1_k_idx_0 = controlAerobi_P.Gain1_Gain_mz *
    controlAerobi_B.Gain_po[1];
  controlAerobi_B.Gain5 = controlAerobi_P.Gain1_Gain_mz *
    controlAerobi_B.rtb_Switch2_o_idx_1;

  // Gain: '<S3>/Gain2' incorporates:
  //   MATLAB Function: '<S29>/Continuous Yaw Generator'

  controlAerobi_B.Switch_b5 = controlAerobi_P.Gain2_Gain_n *
    controlAerobi_B.Gain_po[2];
  controlAerobi_B.Gain7 = controlAerobi_P.Gain2_Gain_n *
    controlAerobi_DWork.yaw_references;

  // MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
  //   Constant: '<S3>/SelectPlot1'

  switch ((int32_T)controlAerobi_P.logs_SelectPlot1) {
   case 1:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.rtb_Zgain_idx_0;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.Switch2_n;
    break;

   case 2:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.rtb_Gain1_k_idx_0;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.Gain5;
    break;

   case 3:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.Switch_b5;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.Gain7;
    break;

   case 4:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.Add[1];
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.rtb_Switch_b_idx_0;
    break;

   case 5:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.Add[0];
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.rtb_Switch_b_idx_1;
    break;

   case 6:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.dyaw;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.DeadZone1;
    break;

   case 7:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.b_x_idx_2;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.rtb_XYd_idx_0;
    break;

   case 8:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.rtb_Switch_Pos_idx_1;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.rtb_XYd_idx_1;
    break;

   case 9:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.b_exp_b;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.Switch_l0;
    break;

   case 10:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.b_x_idx_1;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.rtb_Saturation_b_idx_0;
    break;

   case 11:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.x_I_idx_1;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.rtb_Saturation_b_idx_1;
    break;

   case 12:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.dZ_des;
    break;

   case 13:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.Switch_ed[0];
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.Switch_ed[1];
    break;

   default:
    controlAerobi_B.MultiportSwitch[0] = controlAerobi_B.Switch_ed[2];
    controlAerobi_B.MultiportSwitch[1] = controlAerobi_B.rtb_Switch_ed_f;
    break;
  }

  // End of MultiPortSwitch: '<S3>/Multiport Switch'

  // MultiPortSwitch: '<S3>/Multiport Switch1' incorporates:
  //   Constant: '<S3>/SelectPlot2'

  switch ((int32_T)controlAerobi_P.logs_SelectPlot2) {
   case 1:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.rtb_Zgain_idx_0;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.Switch2_n;
    break;

   case 2:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.rtb_Gain1_k_idx_0;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.Gain5;
    break;

   case 3:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.Switch_b5;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.Gain7;
    break;

   case 4:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.Add[1];
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.rtb_Switch_b_idx_0;
    break;

   case 5:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.Add[0];
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.rtb_Switch_b_idx_1;
    break;

   case 6:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.dyaw;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.DeadZone1;
    break;

   case 7:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.b_x_idx_2;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.rtb_XYd_idx_0;
    break;

   case 8:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.rtb_Switch_Pos_idx_1;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.rtb_XYd_idx_1;
    break;

   case 9:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.b_exp_b;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.Switch_l0;
    break;

   case 10:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.b_x_idx_1;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.rtb_Saturation_b_idx_0;
    break;

   case 11:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.x_I_idx_1;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.rtb_Saturation_b_idx_1;
    break;

   case 12:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.dZ_des;
    break;

   case 13:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.Switch_ed[0];
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.Switch_ed[1];
    break;

   default:
    controlAerobi_B.MultiportSwitch1[0] = controlAerobi_B.Switch_ed[2];
    controlAerobi_B.MultiportSwitch1[1] = controlAerobi_B.rtb_Switch_ed_f;
    break;
  }

  // End of MultiPortSwitch: '<S3>/Multiport Switch1'

  // MultiPortSwitch: '<S3>/Multiport Switch2' incorporates:
  //   Constant: '<S3>/SelectPlot3'

  switch ((int32_T)controlAerobi_P.logs_SelectPlot3) {
   case 1:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.rtb_Zgain_idx_0;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.Switch2_n;
    break;

   case 2:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.rtb_Gain1_k_idx_0;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.Gain5;
    break;

   case 3:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.Switch_b5;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.Gain7;
    break;

   case 4:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.Add[1];
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.rtb_Switch_b_idx_0;
    break;

   case 5:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.Add[0];
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.rtb_Switch_b_idx_1;
    break;

   case 6:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.dyaw;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.DeadZone1;
    break;

   case 7:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.b_x_idx_2;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.rtb_XYd_idx_0;
    break;

   case 8:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.rtb_Switch_Pos_idx_1;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.rtb_XYd_idx_1;
    break;

   case 9:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.b_exp_b;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.Switch_l0;
    break;

   case 10:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.b_x_idx_1;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.rtb_Saturation_b_idx_0;
    break;

   case 11:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.x_I_idx_1;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.rtb_Saturation_b_idx_1;
    break;

   case 12:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.dZ_des;
    break;

   case 13:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.Switch_ed[0];
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.Switch_ed[1];
    break;

   default:
    controlAerobi_B.MultiportSwitch2[0] = controlAerobi_B.Switch_ed[2];
    controlAerobi_B.MultiportSwitch2[1] = controlAerobi_B.rtb_Switch_ed_f;
    break;
  }

  // End of MultiPortSwitch: '<S3>/Multiport Switch2'

  // MultiPortSwitch: '<S3>/Multiport Switch3' incorporates:
  //   Constant: '<S3>/SelectPlot4'

  switch ((int32_T)controlAerobi_P.logs_SelectPlot4) {
   case 1:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.rtb_Zgain_idx_0;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.Switch2_n;
    break;

   case 2:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.rtb_Gain1_k_idx_0;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.Gain5;
    break;

   case 3:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.Switch_b5;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.Gain7;
    break;

   case 4:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.Add[1];
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.rtb_Switch_b_idx_0;
    break;

   case 5:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.Add[0];
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.rtb_Switch_b_idx_1;
    break;

   case 6:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.dyaw;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.DeadZone1;
    break;

   case 7:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.b_x_idx_2;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.rtb_XYd_idx_0;
    break;

   case 8:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.rtb_Switch_Pos_idx_1;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.rtb_XYd_idx_1;
    break;

   case 9:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.b_exp_b;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.Switch_l0;
    break;

   case 10:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.b_x_idx_1;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.rtb_Saturation_b_idx_0;
    break;

   case 11:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.x_I_idx_1;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.rtb_Saturation_b_idx_1;
    break;

   case 12:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.r_x_idx_1;
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.dZ_des;
    break;

   case 13:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.Switch_ed[0];
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.Switch_ed[1];
    break;

   default:
    controlAerobi_B.MultiportSwitch3[0] = controlAerobi_B.Switch_ed[2];
    controlAerobi_B.MultiportSwitch3[1] = controlAerobi_B.rtb_Switch_ed_f;
    break;
  }

  // End of MultiPortSwitch: '<S3>/Multiport Switch3'
  // SignalConversion: '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' incorporates:
  //   Inport: '<Root>/I_adc'

  controlAerobi_B._adc0 = controlAerobi_U.I_adc._adc0;

  // SignalConversion: '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' incorporates:
  //   Inport: '<Root>/I_adc'

  controlAerobi_B._adc1 = controlAerobi_U.I_adc._adc1;

  // SignalConversion: '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' incorporates:
  //   Inport: '<Root>/I_adc'

  controlAerobi_B._adc2 = controlAerobi_U.I_adc._adc2;

  // SignalConversion: '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' incorporates:
  //   Inport: '<Root>/I_adc'

  controlAerobi_B._adc3 = controlAerobi_U.I_adc._adc3;

  // SignalConversion: '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' incorporates:
  //   Inport: '<Root>/I_adc'

  controlAerobi_B._adc4 = controlAerobi_U.I_adc._adc4;

  // SignalConversion: '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' incorporates:
  //   Inport: '<Root>/I_adc'

  controlAerobi_B._adc5 = controlAerobi_U.I_adc._adc5;

  // DeadZone: '<S18>/Dead Zone'
  if (controlAerobi_B.t > controlAerobi_P.DeadZone_End_c) {
    controlAerobi_B.t -= controlAerobi_P.DeadZone_End_c;
  } else if (controlAerobi_B.t >= controlAerobi_P.DeadZone_Start_j) {
    controlAerobi_B.t = 0.0;
  } else {
    controlAerobi_B.t -= controlAerobi_P.DeadZone_Start_j;
  }

  // End of DeadZone: '<S18>/Dead Zone'

  // DeadZone: '<S18>/Dead Zone1'
  if (controlAerobi_B.absxk > controlAerobi_P.DeadZone1_End_n) {
    controlAerobi_B.absxk -= controlAerobi_P.DeadZone1_End_n;
  } else if (controlAerobi_B.absxk >= controlAerobi_P.DeadZone1_Start_o) {
    controlAerobi_B.absxk = 0.0;
  } else {
    controlAerobi_B.absxk -= controlAerobi_P.DeadZone1_Start_o;
  }

  // End of DeadZone: '<S18>/Dead Zone1'

  // MATLAB Function: '<S18>/Create dXY desired' incorporates:
  //   Gain: '<S18>/Gain'
  //   Gain: '<S18>/Gain1'

  controlAerobi_CreatedXYdesired(controlAerobi_B.Gain_po[2],
    controlAerobi_P.Gain_Gain_o * controlAerobi_B.t,
    controlAerobi_P.Gain1_Gain_au * controlAerobi_B.absxk,
    &controlAerobi_B.sf_CreatedXYdesired_o);

  // Switch: '<S18>/Switch1' incorporates:
  //   Constant: '<S18>/zero'

  if (rtb_LogicalOperator) {
    // Saturate: '<S18>/Saturation1'
    if (controlAerobi_B.sf_CreatedXYdesired_o.dXY_d[0] >
        controlAerobi_P.Saturation1_UpperSat) {
      controlAerobi_B.rtb_Gain1_k_idx_0 = controlAerobi_P.Saturation1_UpperSat;
    } else if (controlAerobi_B.sf_CreatedXYdesired_o.dXY_d[0] <
               controlAerobi_P.Saturation1_LowerSat) {
      controlAerobi_B.rtb_Gain1_k_idx_0 = controlAerobi_P.Saturation1_LowerSat;
    } else {
      controlAerobi_B.rtb_Gain1_k_idx_0 =
        controlAerobi_B.sf_CreatedXYdesired_o.dXY_d[0];
    }

    if (controlAerobi_B.sf_CreatedXYdesired_o.dXY_d[1] >
        controlAerobi_P.Saturation1_UpperSat) {
      controlAerobi_B.Gain5 = controlAerobi_P.Saturation1_UpperSat;
    } else if (controlAerobi_B.sf_CreatedXYdesired_o.dXY_d[1] <
               controlAerobi_P.Saturation1_LowerSat) {
      controlAerobi_B.Gain5 = controlAerobi_P.Saturation1_LowerSat;
    } else {
      controlAerobi_B.Gain5 = controlAerobi_B.sf_CreatedXYdesired_o.dXY_d[1];
    }

    // End of Saturate: '<S18>/Saturation1'
  } else {
    controlAerobi_B.rtb_Gain1_k_idx_0 = controlAerobi_P.zero_Value;
    controlAerobi_B.Gain5 = controlAerobi_P.zero_Value;
  }

  // End of Switch: '<S18>/Switch1'

  // Gain: '<S25>/dZgain' incorporates:
  //   Constant: '<S20>/med_thrust'
  //   Gain: '<S25>/adapt_thrust'
  //   Lookup_n-D: '<S25>/1-D Lookup Table'
  //   Sum: '<S20>/Sum'

  controlAerobi_B.absxk = look1_binlx((controlAerobi_B.DiscreteTimeIntegrator_b
    - controlAerobi_P.med_thrust_Value_n) * controlAerobi_P.adapt_thrust_Gain_o,
    controlAerobi_P.uDLookupTable_bp01Data_l,
    controlAerobi_P.uDLookupTable_tableData_j, 600U) *
    controlAerobi_P.dZgain_Gain_p;

  // DeadZone: '<S25>/Dead Zone'
  if (controlAerobi_B.absxk > controlAerobi_P.DeadZone_End_l5) {
    controlAerobi_B.absxk -= controlAerobi_P.DeadZone_End_l5;
  } else if (controlAerobi_B.absxk >= controlAerobi_P.DeadZone_Start_k) {
    controlAerobi_B.absxk = 0.0;
  } else {
    controlAerobi_B.absxk -= controlAerobi_P.DeadZone_Start_k;
  }

  // End of DeadZone: '<S25>/Dead Zone'

  // Saturate: '<S25>/Saturation'
  if (controlAerobi_B.absxk > controlAerobi_P.Saturation_UpperSat_i) {
    controlAerobi_B.absxk = controlAerobi_P.Saturation_UpperSat_i;
  } else {
    if (controlAerobi_B.absxk < controlAerobi_P.Saturation_LowerSat_g) {
      controlAerobi_B.absxk = controlAerobi_P.Saturation_LowerSat_g;
    }
  }

  // End of Saturate: '<S25>/Saturation'

  // Gain: '<S26>/Zgain'
  controlAerobi_B.absxk *= controlAerobi_P.Zgain_Gain;

  // Signum: '<S27>/SignPreSat'
  if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f < 0.0) {
    controlAerobi_B.Gain7 = -1.0;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f > 0.0) {
    controlAerobi_B.Gain7 = 1.0;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f == 0.0) {
    controlAerobi_B.Gain7 = 0.0;
  } else {
    controlAerobi_B.Gain7 = controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f;
  }

  // End of Signum: '<S27>/SignPreSat'

  // Signum: '<S27>/SignPreIntegrator'
  if (controlAerobi_B.absxk < 0.0) {
    controlAerobi_B.Switch_b5 = -1.0;
  } else if (controlAerobi_B.absxk > 0.0) {
    controlAerobi_B.Switch_b5 = 1.0;
  } else if (controlAerobi_B.absxk == 0.0) {
    controlAerobi_B.Switch_b5 = 0.0;
  } else {
    controlAerobi_B.Switch_b5 = (rtNaN);
  }

  // End of Signum: '<S27>/SignPreIntegrator'

  // Switch: '<S26>/Switch1' incorporates:
  //   Abs: '<S27>/Abs'
  //   Constant: '<S26>/Constant'
  //   Constant: '<S28>/Constant'
  //   DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
  //   Logic: '<S27>/AND'
  //   RelationalOperator: '<S27>/Equal'
  //   RelationalOperator: '<S28>/Compare'
  //   Sum: '<S27>/Add'

  if ((fabs(controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f -
            controlAerobi_B.r_x_idx_2) >=
       controlAerobi_P.CompareToConstant_const_h) && (controlAerobi_B.Gain7 ==
       controlAerobi_B.Switch_b5)) {
    controlAerobi_B.Switch_b5 = controlAerobi_P.Constant_Value;
  } else {
    controlAerobi_B.Switch_b5 = controlAerobi_B.absxk;
  }

  // End of Switch: '<S26>/Switch1'

  // Sum: '<S36>/Add' incorporates:
  //   Abs: '<S36>/Abs'

  controlAerobi_B.rtb_Abs_f_idx_0 = fabs(controlAerobi_B.rtb_Sum_m_idx_0 -
    controlAerobi_B.rtb_Abs_f_idx_0);

  // Product: '<S32>/Product1' incorporates:
  //   Constant: '<S95>/I_RollPitch_rate'

  controlAerobi_B.rtb_Product1_kp_idx_0 *=
    controlAerobi_P.I_RollPitch_rate_Value;
  controlAerobi_B.r_x_idx_2 = controlAerobi_P.I_RollPitch_rate_Value *
    controlAerobi_B.rtb_Product1_kp_idx_1;

  // Sum: '<S40>/Add'
  controlAerobi_B.Abs_g = controlAerobi_B.Sum_c - controlAerobi_B.Abs_g;

  // Abs: '<S40>/Abs'
  controlAerobi_B.Abs_g = fabs(controlAerobi_B.Abs_g);

  // Switch: '<S33>/Switch1' incorporates:
  //   Constant: '<S33>/Constant'
  //   Constant: '<S33>/Constant2'
  //   Constant: '<S95>/I_Yaw_rate'
  //   Product: '<S33>/Product1'
  //   RelationalOperator: '<S33>/Relational Operator'

  if (controlAerobi_B.DiscreteTimeIntegrator_b <=
      controlAerobi_P.Constant2_Value_p) {
    controlAerobi_B.absxk = controlAerobi_P.Constant_Value_n;
  } else {
    controlAerobi_B.absxk = controlAerobi_P.I_Yaw_rate_Value *
      controlAerobi_B.Switch4;
  }

  // End of Switch: '<S33>/Switch1'

  // Sum: '<S48>/Add'
  controlAerobi_B.Abs_k = controlAerobi_B.Sum_f - controlAerobi_B.Abs_k;

  // Abs: '<S48>/Abs'
  controlAerobi_B.Abs_k = fabs(controlAerobi_B.Abs_k);

  // Product: '<S35>/Product1' incorporates:
  //   Constant: '<S95>/I_Yaw_pos'

  controlAerobi_B.r_x_idx_0 *= controlAerobi_P.I_Yaw_pos_Value;

  // Gain: '<S68>/Zgain'
  controlAerobi_B.rtb_Zgain_idx_0 = controlAerobi_P.Zgain_Gain_e *
    controlAerobi_B.rtb_Saturation_g_idx_0;

  // Sum: '<S44>/Add' incorporates:
  //   Abs: '<S44>/Abs'

  controlAerobi_B.rtb_Abs_l_idx_0 = fabs(controlAerobi_B.rtb_Sum_cw_idx_0 -
    controlAerobi_B.rtb_Abs_l_idx_0);

  // Product: '<S34>/Product1' incorporates:
  //   Constant: '<S95>/I_RollPitch_pos'

  controlAerobi_B.rtb_Switch3_idx_0 *= controlAerobi_P.I_RollPitch_pos_Value;

  // Sum: '<S59>/Add' incorporates:
  //   Abs: '<S59>/Abs'

  controlAerobi_B.rtb_Abs_o_idx_0 = fabs(controlAerobi_B.rtb_Sum_l_idx_0 -
    controlAerobi_B.rtb_Abs_o_idx_0);

  // Product: '<S56>/Product1' incorporates:
  //   Constant: '<S95>/I_XY_pos'

  controlAerobi_B.rtb_Product1_na_idx_0 *= controlAerobi_P.I_XY_pos_Value;

  // Sum: '<S63>/Add' incorporates:
  //   Abs: '<S63>/Abs'

  controlAerobi_B.rtb_Abs_c_idx_0 = fabs(controlAerobi_B.rtb_Sum_oc_idx_0 -
    controlAerobi_B.rtb_Abs_c_idx_0);

  // Product: '<S57>/Product1' incorporates:
  //   Constant: '<S95>/I_XY_rate'

  controlAerobi_B.rtb_Product1_a_idx_0 *= controlAerobi_P.I_XY_rate_Value;

  // Product: '<S34>/Product1' incorporates:
  //   Constant: '<S95>/I_RollPitch_pos'

  controlAerobi_B.DiscreteTimeIntegrator_b =
    controlAerobi_P.I_RollPitch_pos_Value * controlAerobi_B.rtb_Switch3_idx_1;

  // Product: '<S56>/Product1' incorporates:
  //   Constant: '<S95>/I_XY_pos'

  controlAerobi_B.t = controlAerobi_P.I_XY_pos_Value *
    controlAerobi_B.rtb_Product1_na_idx_1;

  // Product: '<S57>/Product1' incorporates:
  //   Constant: '<S95>/I_XY_rate'

  controlAerobi_B.rtb_Product1_a_idx_1 *= controlAerobi_P.I_XY_rate_Value;

  // Gain: '<S68>/Zgain'
  controlAerobi_B.Switch2_n = controlAerobi_P.Zgain_Gain_e *
    controlAerobi_B.rtb_Saturation_g_idx_1;

  // Sum: '<S76>/Add'
  controlAerobi_B.Abs_a = controlAerobi_B.Sum_n - controlAerobi_B.Abs_a;

  // Abs: '<S76>/Abs'
  controlAerobi_B.Abs_a = fabs(controlAerobi_B.Abs_a);

  // Product: '<S74>/Product1' incorporates:
  //   Constant: '<S95>/I_Z_pos'

  controlAerobi_B.Product1_a1 *= controlAerobi_P.I_Z_pos_Value;

  // Sum: '<S80>/Add'
  controlAerobi_B.Abs = controlAerobi_B.Sum_b - controlAerobi_B.Abs;

  // Abs: '<S80>/Abs'
  controlAerobi_B.Abs = fabs(controlAerobi_B.Abs);

  // Product: '<S75>/Product1' incorporates:
  //   Constant: '<S95>/I_Z_rate'

  controlAerobi_B.Product1_ew *= controlAerobi_P.I_Z_rate_Value;

  // Gain: '<S86>/Zgain'
  controlAerobi_B.Zgain_a *= controlAerobi_P.Zgain_Gain_d;

  // Gain: '<S102>/Gain'
  controlAerobi_B.Gain[0] = controlAerobi_P.Gain_Gain_f * controlAerobi_B.Add_j
    [2];
  controlAerobi_B.Gain[1] = controlAerobi_P.Gain_Gain_f * controlAerobi_B.ub[0];
  controlAerobi_B.Gain[2] = controlAerobi_P.Gain_Gain_f *
    controlAerobi_B.RotationAnglescorrection[0];

  // Gain: '<S102>/Gain1'
  controlAerobi_B.Gain1[0] = controlAerobi_P.Gain1_Gain_i *
    controlAerobi_B.Add_j[1];
  controlAerobi_B.Gain1[1] = controlAerobi_P.Gain1_Gain_i * controlAerobi_B.ub[1];
  controlAerobi_B.Gain1[2] = controlAerobi_P.Gain1_Gain_i *
    controlAerobi_B.RotationAnglescorrection[1];

  // Gain: '<S102>/Gain2'
  controlAerobi_B.Gain2[0] = controlAerobi_P.Gain2_Gain_m *
    controlAerobi_B.Add_j[0];
  controlAerobi_B.Gain2[1] = controlAerobi_P.Gain2_Gain_m * controlAerobi_B.ub[2];
  controlAerobi_B.Gain2[2] = controlAerobi_P.Gain2_Gain_m *
    controlAerobi_B.Unwrap;

  // Gain: '<S172>/Gain3'
  controlAerobi_B.Gain3 = controlAerobi_P.Gain3_Gain_n * controlAerobi_B.sinc;

  // DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
  //   DataTypeConversion: '<S170>/Data Type Conversion'
  //   DataTypeConversion: '<S176>/Data1'
  //   DataTypeConversion: '<S176>/Data2'
  //   DataTypeConversion: '<S176>/Data3'
  //   Inport: '<Root>/I_sf11c'
  //   Inport: '<Root>/I_totalStation'

  // MATLAB Function 'Sensors/position/px4fow/MATLAB Function1': '<S184>:1'
  // '<S184>:1:39'
  // '<S184>:1:40'
  // '<S184>:1:41'
  // '<S184>:1:42'
  // '<S184>:1:44'
  // '<S184>:1:45'
  // '<S184>:1:46'
  // '<S184>:1:47'
  // '<S184>:1:48'
  // '<S184>:1:60'
  // '<S184>:1:68'
  // '<S184>:1:69'
  // '<S184>:1:70'
  // '<S184>:1:71'
  // '<S184>:1:72'
  // '<S184>:1:74'
  // '<S184>:1:75'
  // '<S184>:1:76'
  // '<S184>:1:77'
  // '<S184>:1:78'
  // '<S184>:1:80'
  // '<S184>:1:81'
  // '<S184>:1:82'
  // '<S184>:1:84'
  controlAerobi_B.DataTypeConversion2[3] = (real32_T)controlAerobi_B.Add[1];
  controlAerobi_B.DataTypeConversion2[4] = (real32_T)controlAerobi_B.Add[0];
  controlAerobi_B.DataTypeConversion2[5] = (real32_T)controlAerobi_B.dyaw;
  controlAerobi_B.DataTypeConversion2[0] = (real32_T)controlAerobi_B.Gain_po[0];
  controlAerobi_B.DataTypeConversion2[6] = (real32_T)controlAerobi_B.Switch[0];
  controlAerobi_B.DataTypeConversion2[9] = (real32_T)
    controlAerobi_B.DataTypeConversion_b[4];
  controlAerobi_B.DataTypeConversion2[12] = (real32_T)
    controlAerobi_B.DataTypeConversion_b[1];
  controlAerobi_B.DataTypeConversion2[15] = (real32_T)
    controlAerobi_B.DataTypeConversion_b[7];
  controlAerobi_B.DataTypeConversion2[18] = (real32_T)
    controlAerobi_B.DataTypeConversion1_n[4];
  controlAerobi_B.DataTypeConversion2[21] = (real32_T)
    controlAerobi_B.DataTypeConversion1_n[1];
  controlAerobi_B.DataTypeConversion2[24] = (real32_T)
    controlAerobi_B.DataTypeConversion1_n[7];
  controlAerobi_B.DataTypeConversion2[1] = (real32_T)controlAerobi_B.Gain_po[1];
  controlAerobi_B.DataTypeConversion2[7] = (real32_T)controlAerobi_B.Switch[1];
  controlAerobi_B.DataTypeConversion2[10] = (real32_T)
    controlAerobi_B.DataTypeConversion_b[5];
  controlAerobi_B.DataTypeConversion2[13] = (real32_T)
    controlAerobi_B.DataTypeConversion_b[2];
  controlAerobi_B.DataTypeConversion2[16] = (real32_T)
    controlAerobi_B.DataTypeConversion_b[8];
  controlAerobi_B.DataTypeConversion2[19] = (real32_T)
    controlAerobi_B.DataTypeConversion1_n[5];
  controlAerobi_B.DataTypeConversion2[22] = (real32_T)
    controlAerobi_B.DataTypeConversion1_n[2];
  controlAerobi_B.DataTypeConversion2[25] = (real32_T)
    controlAerobi_B.DataTypeConversion1_n[8];
  controlAerobi_B.DataTypeConversion2[2] = (real32_T)controlAerobi_B.Gain_po[2];
  controlAerobi_B.DataTypeConversion2[8] = (real32_T)controlAerobi_B.Switch[2];
  controlAerobi_B.DataTypeConversion2[11] = (real32_T)
    controlAerobi_B.DataTypeConversion_b[6];
  controlAerobi_B.DataTypeConversion2[14] = (real32_T)
    controlAerobi_B.DataTypeConversion_b[3];
  controlAerobi_B.DataTypeConversion2[17] = (real32_T)
    controlAerobi_B.DataTypeConversion_b[9];
  controlAerobi_B.DataTypeConversion2[20] = (real32_T)
    controlAerobi_B.DataTypeConversion1_n[6];
  controlAerobi_B.DataTypeConversion2[23] = (real32_T)
    controlAerobi_B.DataTypeConversion1_n[3];
  controlAerobi_B.DataTypeConversion2[26] = (real32_T)
    controlAerobi_B.DataTypeConversion1_n[9];
  controlAerobi_B.DataTypeConversion2[27] = (real32_T)controlAerobi_B.Sum;
  controlAerobi_B.DataTypeConversion2[30] = (real32_T)controlAerobi_B.b_exp_b;
  controlAerobi_B.DataTypeConversion2[33] = (real32_T)controlAerobi_B.r_x_idx_1;
  controlAerobi_B.DataTypeConversion2[34] = controlAerobi_U.I_sf11c._z;
  controlAerobi_B.DataTypeConversion2[35] = controlAerobi_U.I_totalStation._x;
  controlAerobi_B.DataTypeConversion2[36] = controlAerobi_U.I_totalStation._y;
  controlAerobi_B.DataTypeConversion2[37] = controlAerobi_U.I_totalStation._z;
  controlAerobi_B.DataTypeConversion2[38] = (real32_T)
    controlAerobi_U.I_totalStation._time;

  // DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
  //   MATLAB Function: '<S29>/Continuous Yaw Generator'

  controlAerobi_B.DataTypeConversion[4] = (real32_T)controlAerobi_B.Divide;
  controlAerobi_B.DataTypeConversion[5] = (real32_T)controlAerobi_B.Switch_l0;
  controlAerobi_B.DataTypeConversion[6] = (real32_T)controlAerobi_B.dZ_des;
  controlAerobi_B.DataTypeConversion[9] = (real32_T)
    controlAerobi_DWork.yaw_references;

  // DataTypeConversion: '<S3>/Data Type Conversion2'
  controlAerobi_B.DataTypeConversion2[28] = (real32_T)controlAerobi_B.b_x_idx_2;
  controlAerobi_B.DataTypeConversion2[31] = (real32_T)controlAerobi_B.b_x_idx_1;

  // DataTypeConversion: '<S3>/Data Type Conversion'
  controlAerobi_B.DataTypeConversion[0] = (real32_T)
    controlAerobi_B.rtb_XYd_idx_0;
  controlAerobi_B.DataTypeConversion[2] = (real32_T)
    controlAerobi_B.rtb_Saturation_b_idx_0;
  controlAerobi_B.DataTypeConversion[7] = (real32_T)
    controlAerobi_B.rtb_Switch2_o_idx_0;
  controlAerobi_B.DataTypeConversion[10] = (real32_T)
    controlAerobi_B.rtb_Switch_b_idx_0;

  // DataTypeConversion: '<S3>/Data Type Conversion2'
  controlAerobi_B.DataTypeConversion2[29] = (real32_T)
    controlAerobi_B.rtb_Switch_Pos_idx_1;
  controlAerobi_B.DataTypeConversion2[32] = (real32_T)controlAerobi_B.x_I_idx_1;

  // DataTypeConversion: '<S3>/Data Type Conversion'
  controlAerobi_B.DataTypeConversion[1] = (real32_T)
    controlAerobi_B.rtb_XYd_idx_1;
  controlAerobi_B.DataTypeConversion[3] = (real32_T)
    controlAerobi_B.rtb_Saturation_b_idx_1;
  controlAerobi_B.DataTypeConversion[8] = (real32_T)
    controlAerobi_B.rtb_Switch2_o_idx_1;
  controlAerobi_B.DataTypeConversion[11] = (real32_T)
    controlAerobi_B.rtb_Switch_b_idx_1;
  controlAerobi_B.DataTypeConversion[12] = (real32_T)controlAerobi_B.DeadZone1;
  controlAerobi_B.DataTypeConversion[13] = (real32_T)controlAerobi_B.Switch_ed[0];
  controlAerobi_B.DataTypeConversion[14] = (real32_T)controlAerobi_B.Switch_ed[1];
  controlAerobi_B.DataTypeConversion[15] = (real32_T)controlAerobi_B.Switch_ed[2];
  controlAerobi_B.DataTypeConversion[16] = (real32_T)
    controlAerobi_B.rtb_Switch_ed_f;

  // DataTypeConversion: '<S3>/Data Type Conversion1' incorporates:
  //   Inport: '<Root>/I_RCinput'

  controlAerobi_B.DataTypeConversion1[0] = controlAerobi_U.I_RCinput._channel1;
  controlAerobi_B.DataTypeConversion1[1] = controlAerobi_U.I_RCinput._channel2;
  controlAerobi_B.DataTypeConversion1[2] = controlAerobi_U.I_RCinput._channel3;
  controlAerobi_B.DataTypeConversion1[3] = controlAerobi_U.I_RCinput._channel4;
  controlAerobi_B.DataTypeConversion1[4] = controlAerobi_U.I_RCinput._channel5;
  controlAerobi_B.DataTypeConversion1[5] = controlAerobi_U.I_RCinput._channel6;
  controlAerobi_B.DataTypeConversion1[6] = controlAerobi_U.I_RCinput._channel7;
  controlAerobi_B.DataTypeConversion1[7] = controlAerobi_U.I_RCinput._channel8;
  controlAerobi_B.DataTypeConversion1[8] = controlAerobi_U.I_RCinput._channel9;
  controlAerobi_B.DataTypeConversion1[9] = controlAerobi_U.I_RCinput._channel10;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevRese = (int8_T)
    rtb_LogicalOperator;

  // Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_i * controlAerobi_B.Switch_b5;
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_k = (int8_T)
    controlAerobi_B.ALTHOLD;

  // Signum: '<S87>/SignPreSat'
  if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n < 0.0) {
    controlAerobi_B.Gain7 = -1.0;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n > 0.0) {
    controlAerobi_B.Gain7 = 1.0;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n == 0.0) {
    controlAerobi_B.Gain7 = 0.0;
  } else {
    controlAerobi_B.Gain7 = controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n;
  }

  // End of Signum: '<S87>/SignPreSat'

  // Signum: '<S87>/SignPreIntegrator'
  if (controlAerobi_B.Zgain_a < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.Zgain_a > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.Zgain_a == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // End of Signum: '<S87>/SignPreIntegrator'

  // Switch: '<S86>/Switch1' incorporates:
  //   Abs: '<S87>/Abs'
  //   Constant: '<S86>/Constant'
  //   Constant: '<S88>/Constant'
  //   DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
  //   Logic: '<S87>/AND'
  //   RelationalOperator: '<S87>/Equal'
  //   RelationalOperator: '<S88>/Compare'
  //   Sum: '<S87>/Add'

  if ((fabs(controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n -
            controlAerobi_B.Gain3_l) >=
       controlAerobi_P.CompareToConstant_const_bo) && (controlAerobi_B.Gain7 ==
       controlAerobi_B.Unwrap)) {
    controlAerobi_B.Zgain_a = controlAerobi_P.Constant_Value_a;
  }

  // End of Switch: '<S86>/Switch1'

  // Update for DiscreteIntegrator: '<S86>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_a * controlAerobi_B.Zgain_a;
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_b = (int8_T)
    controlAerobi_B.ALTHOLD;

  // Signum: '<S76>/SignPreSat'
  if (controlAerobi_B.Sum_n < 0.0) {
    controlAerobi_B.Sum_n = -1.0;
  } else if (controlAerobi_B.Sum_n > 0.0) {
    controlAerobi_B.Sum_n = 1.0;
  } else if (controlAerobi_B.Sum_n == 0.0) {
    controlAerobi_B.Sum_n = 0.0;
  } else {
    controlAerobi_B.Sum_n = (rtNaN);
  }

  // End of Signum: '<S76>/SignPreSat'

  // Signum: '<S76>/SignPreIntegrator'
  if (controlAerobi_B.Product1_a1 < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.Product1_a1 > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.Product1_a1 == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // End of Signum: '<S76>/SignPreIntegrator'

  // Switch: '<S74>/Switch' incorporates:
  //   Constant: '<S74>/Constant'
  //   Constant: '<S79>/Constant'
  //   Logic: '<S76>/AND'
  //   RelationalOperator: '<S76>/Equal'
  //   RelationalOperator: '<S79>/Compare'

  if ((controlAerobi_B.Abs_a >= controlAerobi_P.CompareToConstant_const_hw) &&
      (controlAerobi_B.Sum_n == controlAerobi_B.Unwrap)) {
    controlAerobi_B.Product1_a1 = controlAerobi_P.Constant_Value_oa;
  }

  // End of Switch: '<S74>/Switch'

  // Update for DiscreteIntegrator: '<S74>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_e +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_e *
    controlAerobi_B.Product1_a1;
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_i = (int8_T)
    controlAerobi_B.ALTHOLD;

  // Update for UnitDelay: '<S77>/UD'
  controlAerobi_DWork.UD_DSTATE = controlAerobi_B.TSamp;

  // Signum: '<S80>/SignPreSat'
  if (controlAerobi_B.Sum_b < 0.0) {
    controlAerobi_B.Sum_b = -1.0;
  } else if (controlAerobi_B.Sum_b > 0.0) {
    controlAerobi_B.Sum_b = 1.0;
  } else if (controlAerobi_B.Sum_b == 0.0) {
    controlAerobi_B.Sum_b = 0.0;
  } else {
    controlAerobi_B.Sum_b = (rtNaN);
  }

  // End of Signum: '<S80>/SignPreSat'

  // Signum: '<S80>/SignPreIntegrator'
  if (controlAerobi_B.Product1_ew < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.Product1_ew > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.Product1_ew == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // End of Signum: '<S80>/SignPreIntegrator'

  // Switch: '<S75>/Switch' incorporates:
  //   Constant: '<S75>/Constant'
  //   Constant: '<S83>/Constant'
  //   Logic: '<S80>/AND'
  //   RelationalOperator: '<S80>/Equal'
  //   RelationalOperator: '<S83>/Compare'

  if ((controlAerobi_B.Abs >= controlAerobi_P.CompareToConstant_const_g) &&
      (controlAerobi_B.Sum_b == controlAerobi_B.Unwrap)) {
    controlAerobi_B.Product1_ew = controlAerobi_P.Constant_Value_b;
  }

  // End of Switch: '<S75>/Switch'

  // Update for DiscreteIntegrator: '<S75>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n5 +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_m *
    controlAerobi_B.Product1_ew;
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_c = (int8_T)
    controlAerobi_B.ALTHOLD;

  // Update for UnitDelay: '<S81>/UD'
  controlAerobi_DWork.UD_DSTATE_f = controlAerobi_B.TSamp_h;

  // Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    rtb_LogicalOperator_e;

  // Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_l = (int8_T)
    rtb_LogicalOperator_e;

  // Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_n = (int8_T)
    rtb_LogicalOperator_e;

  // Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
    rtb_LogicalOperator1;

  // Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_gz = (int8_T)
    rtb_LogicalOperator1;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE[0] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainval *
    controlAerobi_B.rtb_Gain1_k_idx_0;

  // Signum: '<S69>/SignPreSat' incorporates:
  //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'

  if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0] < 0.0) {
    controlAerobi_B.Gain7 = -1.0;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0] > 0.0) {
    controlAerobi_B.Gain7 = 1.0;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0] == 0.0) {
    controlAerobi_B.Gain7 = 0.0;
  } else {
    controlAerobi_B.Gain7 = (rtNaN);
  }

  // Signum: '<S69>/SignPreIntegrator'
  if (controlAerobi_B.rtb_Zgain_idx_0 < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.rtb_Zgain_idx_0 > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.rtb_Zgain_idx_0 == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Switch: '<S68>/Switch1' incorporates:
  //   Abs: '<S69>/Abs'
  //   Constant: '<S68>/Constant'
  //   Constant: '<S71>/Constant'
  //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  //   Logic: '<S69>/AND'
  //   RelationalOperator: '<S69>/Equal'
  //   RelationalOperator: '<S71>/Compare'
  //   Sum: '<S69>/Add'

  if ((fabs(controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0] -
            controlAerobi_B.y_k_idx_0) >=
       controlAerobi_P.CompareToConstant_const_i) && (controlAerobi_B.Gain7 ==
       controlAerobi_B.Unwrap)) {
    controlAerobi_B.rtb_Zgain_idx_0 = controlAerobi_P.Constant_Value_gv;
  }

  // Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainv_mu *
    controlAerobi_B.rtb_Zgain_idx_0;

  // Signum: '<S59>/SignPreSat'
  if (controlAerobi_B.rtb_Sum_l_idx_0 < 0.0) {
    controlAerobi_B.rtb_Sum_l_idx_0 = -1.0;
  } else if (controlAerobi_B.rtb_Sum_l_idx_0 > 0.0) {
    controlAerobi_B.rtb_Sum_l_idx_0 = 1.0;
  } else if (controlAerobi_B.rtb_Sum_l_idx_0 == 0.0) {
    controlAerobi_B.rtb_Sum_l_idx_0 = 0.0;
  } else {
    controlAerobi_B.rtb_Sum_l_idx_0 = (rtNaN);
  }

  // Signum: '<S59>/SignPreIntegrator'
  if (controlAerobi_B.rtb_Product1_na_idx_0 < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.rtb_Product1_na_idx_0 > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.rtb_Product1_na_idx_0 == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Switch: '<S56>/Switch' incorporates:
  //   Constant: '<S56>/Constant'
  //   Constant: '<S62>/Constant'
  //   Logic: '<S59>/AND'
  //   RelationalOperator: '<S59>/Equal'
  //   RelationalOperator: '<S62>/Compare'

  if ((controlAerobi_B.rtb_Abs_o_idx_0 >=
       controlAerobi_P.CompareToConstant_const_m) &&
      (controlAerobi_B.rtb_Sum_l_idx_0 == controlAerobi_B.Unwrap)) {
    controlAerobi_B.rtb_Product1_na_idx_0 = controlAerobi_P.Constant_Value_jp;
  }

  // Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_m[0] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_d *
    controlAerobi_B.rtb_Product1_na_idx_0;

  // Update for UnitDelay: '<S60>/UD'
  controlAerobi_DWork.UD_DSTATE_d[0] = controlAerobi_B.rtb_TSamp_p_idx_0;

  // Signum: '<S63>/SignPreSat'
  if (controlAerobi_B.rtb_Sum_oc_idx_0 < 0.0) {
    controlAerobi_B.rtb_Sum_oc_idx_0 = -1.0;
  } else if (controlAerobi_B.rtb_Sum_oc_idx_0 > 0.0) {
    controlAerobi_B.rtb_Sum_oc_idx_0 = 1.0;
  } else if (controlAerobi_B.rtb_Sum_oc_idx_0 == 0.0) {
    controlAerobi_B.rtb_Sum_oc_idx_0 = 0.0;
  } else {
    controlAerobi_B.rtb_Sum_oc_idx_0 = (rtNaN);
  }

  // Signum: '<S63>/SignPreIntegrator'
  if (controlAerobi_B.rtb_Product1_a_idx_0 < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.rtb_Product1_a_idx_0 > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.rtb_Product1_a_idx_0 == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Switch: '<S57>/Switch' incorporates:
  //   Constant: '<S57>/Constant'
  //   Constant: '<S66>/Constant'
  //   Logic: '<S63>/AND'
  //   RelationalOperator: '<S63>/Equal'
  //   RelationalOperator: '<S66>/Compare'

  if ((controlAerobi_B.rtb_Abs_c_idx_0 >=
       controlAerobi_P.CompareToConstant_const_e) &&
      (controlAerobi_B.rtb_Sum_oc_idx_0 == controlAerobi_B.Unwrap)) {
    controlAerobi_B.rtb_Product1_a_idx_0 = controlAerobi_P.Constant_Value_g3;
  }

  // Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_fo[0] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainv_mv *
    controlAerobi_B.rtb_Product1_a_idx_0;

  // Update for UnitDelay: '<S64>/UD'
  controlAerobi_DWork.UD_DSTATE_o[0] = controlAerobi_B.rtb_TSamp_j_idx_0;

  // Signum: '<S44>/SignPreSat'
  if (controlAerobi_B.rtb_Sum_cw_idx_0 < 0.0) {
    controlAerobi_B.rtb_Sum_cw_idx_0 = -1.0;
  } else if (controlAerobi_B.rtb_Sum_cw_idx_0 > 0.0) {
    controlAerobi_B.rtb_Sum_cw_idx_0 = 1.0;
  } else if (controlAerobi_B.rtb_Sum_cw_idx_0 == 0.0) {
    controlAerobi_B.rtb_Sum_cw_idx_0 = 0.0;
  } else {
    controlAerobi_B.rtb_Sum_cw_idx_0 = (rtNaN);
  }

  // Signum: '<S44>/SignPreIntegrator'
  if (controlAerobi_B.rtb_Switch3_idx_0 < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.rtb_Switch3_idx_0 > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.rtb_Switch3_idx_0 == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Switch: '<S34>/Switch' incorporates:
  //   Constant: '<S34>/Constant'
  //   Constant: '<S47>/Constant'
  //   Logic: '<S44>/AND'
  //   RelationalOperator: '<S44>/Equal'
  //   RelationalOperator: '<S47>/Compare'

  if ((controlAerobi_B.rtb_Abs_l_idx_0 >=
       controlAerobi_P.CompareToConstant_const_l) &&
      (controlAerobi_B.rtb_Sum_cw_idx_0 == controlAerobi_B.Unwrap)) {
    controlAerobi_B.rtb_Switch3_idx_0 = controlAerobi_P.Constant_Value_lb;
  }

  // Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n2[0] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_b *
    controlAerobi_B.rtb_Switch3_idx_0;

  // Update for UnitDelay: '<S45>/UD'
  controlAerobi_DWork.UD_DSTATE_oo[0] = controlAerobi_B.rtb_TSamp_i_idx_0;

  // Signum: '<S36>/SignPreSat'
  if (controlAerobi_B.rtb_Sum_m_idx_0 < 0.0) {
    controlAerobi_B.rtb_Sum_m_idx_0 = -1.0;
  } else if (controlAerobi_B.rtb_Sum_m_idx_0 > 0.0) {
    controlAerobi_B.rtb_Sum_m_idx_0 = 1.0;
  } else if (controlAerobi_B.rtb_Sum_m_idx_0 == 0.0) {
    controlAerobi_B.rtb_Sum_m_idx_0 = 0.0;
  } else {
    controlAerobi_B.rtb_Sum_m_idx_0 = (rtNaN);
  }

  // Signum: '<S36>/SignPreIntegrator'
  if (controlAerobi_B.rtb_Product1_kp_idx_0 < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.rtb_Product1_kp_idx_0 > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.rtb_Product1_kp_idx_0 == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Switch: '<S32>/Switch' incorporates:
  //   Constant: '<S32>/Constant'
  //   Constant: '<S39>/Constant'
  //   Logic: '<S36>/AND'
  //   RelationalOperator: '<S36>/Equal'
  //   RelationalOperator: '<S39>/Compare'

  if ((controlAerobi_B.rtb_Abs_f_idx_0 >=
       controlAerobi_P.CompareToConstant_const_h5) &&
      (controlAerobi_B.rtb_Sum_m_idx_0 == controlAerobi_B.Unwrap)) {
    controlAerobi_B.rtb_Product1_kp_idx_0 = controlAerobi_P.Constant_Value_gt;
  }

  // Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_h[0] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_k *
    controlAerobi_B.rtb_Product1_kp_idx_0;

  // Update for UnitDelay: '<S37>/UD'
  controlAerobi_DWork.UD_DSTATE_i[0] = controlAerobi_B.rtb_TSamp_n_idx_0;

  // Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE[1] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainval * controlAerobi_B.Gain5;

  // Signum: '<S69>/SignPreSat' incorporates:
  //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'

  if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1] < 0.0) {
    controlAerobi_B.Gain7 = -1.0;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1] > 0.0) {
    controlAerobi_B.Gain7 = 1.0;
  } else if (controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1] == 0.0) {
    controlAerobi_B.Gain7 = 0.0;
  } else {
    controlAerobi_B.Gain7 = (rtNaN);
  }

  // Signum: '<S69>/SignPreIntegrator'
  if (controlAerobi_B.Switch2_n < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.Switch2_n > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.Switch2_n == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Switch: '<S68>/Switch1' incorporates:
  //   Abs: '<S69>/Abs'
  //   Constant: '<S68>/Constant'
  //   Constant: '<S71>/Constant'
  //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  //   DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  //   Logic: '<S69>/AND'
  //   RelationalOperator: '<S69>/Equal'
  //   RelationalOperator: '<S71>/Compare'
  //   Sum: '<S69>/Add'

  if ((fabs(controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1] -
            controlAerobi_B.y_k_idx_1) >=
       controlAerobi_P.CompareToConstant_const_i) && (controlAerobi_B.Gain7 ==
       controlAerobi_B.Unwrap)) {
    controlAerobi_B.Switch2_n = controlAerobi_P.Constant_Value_gv;
  }

  // Update for DiscreteIntegrator: '<S68>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainv_mu * controlAerobi_B.Switch2_n;

  // Signum: '<S59>/SignPreSat'
  if (controlAerobi_B.rtb_Sum_l_b < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.rtb_Sum_l_b > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.rtb_Sum_l_b == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Signum: '<S59>/SignPreIntegrator'
  if (controlAerobi_B.t < 0.0) {
    controlAerobi_B.dyaw = -1.0;
  } else if (controlAerobi_B.t > 0.0) {
    controlAerobi_B.dyaw = 1.0;
  } else if (controlAerobi_B.t == 0.0) {
    controlAerobi_B.dyaw = 0.0;
  } else {
    controlAerobi_B.dyaw = (rtNaN);
  }

  // Switch: '<S56>/Switch' incorporates:
  //   Abs: '<S59>/Abs'
  //   Constant: '<S56>/Constant'
  //   Constant: '<S62>/Constant'
  //   Logic: '<S59>/AND'
  //   RelationalOperator: '<S59>/Equal'
  //   RelationalOperator: '<S62>/Compare'
  //   Sum: '<S59>/Add'

  if ((fabs(controlAerobi_B.rtb_Sum_l_b - controlAerobi_B.rtb_Abs_o_d) >=
       controlAerobi_P.CompareToConstant_const_m) && (controlAerobi_B.Unwrap ==
       controlAerobi_B.dyaw)) {
    controlAerobi_B.t = controlAerobi_P.Constant_Value_jp;
  }

  // Update for DiscreteIntegrator: '<S56>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_m[1] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_d * controlAerobi_B.t;

  // Update for UnitDelay: '<S60>/UD'
  controlAerobi_DWork.UD_DSTATE_d[1] = controlAerobi_B.rtb_TSamp_p_h;

  // Signum: '<S63>/SignPreSat'
  if (controlAerobi_B.rtb_R_d_m_tmp_j < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.rtb_R_d_m_tmp_j > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.rtb_R_d_m_tmp_j == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Signum: '<S63>/SignPreIntegrator'
  if (controlAerobi_B.rtb_Product1_a_idx_1 < 0.0) {
    controlAerobi_B.dyaw = -1.0;
  } else if (controlAerobi_B.rtb_Product1_a_idx_1 > 0.0) {
    controlAerobi_B.dyaw = 1.0;
  } else if (controlAerobi_B.rtb_Product1_a_idx_1 == 0.0) {
    controlAerobi_B.dyaw = 0.0;
  } else {
    controlAerobi_B.dyaw = (rtNaN);
  }

  // Switch: '<S57>/Switch' incorporates:
  //   Abs: '<S63>/Abs'
  //   Constant: '<S57>/Constant'
  //   Constant: '<S66>/Constant'
  //   Logic: '<S63>/AND'
  //   RelationalOperator: '<S63>/Equal'
  //   RelationalOperator: '<S66>/Compare'
  //   Sum: '<S63>/Add'

  if ((fabs(controlAerobi_B.rtb_R_d_m_tmp_j - controlAerobi_B.rtb_Abs_c_e) >=
       controlAerobi_P.CompareToConstant_const_e) && (controlAerobi_B.Unwrap ==
       controlAerobi_B.dyaw)) {
    controlAerobi_B.rtb_Product1_a_idx_1 = controlAerobi_P.Constant_Value_g3;
  }

  // Update for DiscreteIntegrator: '<S57>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_fo[1] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainv_mv *
    controlAerobi_B.rtb_Product1_a_idx_1;

  // Update for UnitDelay: '<S64>/UD'
  controlAerobi_DWork.UD_DSTATE_o[1] = controlAerobi_B.rtb_R_d_m_tmp;

  // Signum: '<S44>/SignPreSat'
  if (controlAerobi_B.rtb_Sum_cw_j < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.rtb_Sum_cw_j > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.rtb_Sum_cw_j == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Signum: '<S44>/SignPreIntegrator'
  if (controlAerobi_B.DiscreteTimeIntegrator_b < 0.0) {
    controlAerobi_B.dyaw = -1.0;
  } else if (controlAerobi_B.DiscreteTimeIntegrator_b > 0.0) {
    controlAerobi_B.dyaw = 1.0;
  } else if (controlAerobi_B.DiscreteTimeIntegrator_b == 0.0) {
    controlAerobi_B.dyaw = 0.0;
  } else {
    controlAerobi_B.dyaw = (rtNaN);
  }

  // Switch: '<S34>/Switch' incorporates:
  //   Abs: '<S44>/Abs'
  //   Constant: '<S34>/Constant'
  //   Constant: '<S47>/Constant'
  //   Logic: '<S44>/AND'
  //   RelationalOperator: '<S44>/Equal'
  //   RelationalOperator: '<S47>/Compare'
  //   Sum: '<S44>/Add'

  if ((fabs(controlAerobi_B.rtb_Sum_cw_j - controlAerobi_B.rtb_Abs_l_idx_1) >=
       controlAerobi_P.CompareToConstant_const_l) && (controlAerobi_B.Unwrap ==
       controlAerobi_B.dyaw)) {
    controlAerobi_B.DiscreteTimeIntegrator_b = controlAerobi_P.Constant_Value_lb;
  }

  // Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n2[1] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_b *
    controlAerobi_B.DiscreteTimeIntegrator_b;

  // Update for UnitDelay: '<S45>/UD'
  controlAerobi_DWork.UD_DSTATE_oo[1] = controlAerobi_B.rtb_TSamp_i_b;

  // Signum: '<S36>/SignPreSat'
  if (controlAerobi_B.ubx_tmp_a < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.ubx_tmp_a > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.ubx_tmp_a == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // Signum: '<S36>/SignPreIntegrator'
  if (controlAerobi_B.r_x_idx_2 < 0.0) {
    controlAerobi_B.dyaw = -1.0;
  } else if (controlAerobi_B.r_x_idx_2 > 0.0) {
    controlAerobi_B.dyaw = 1.0;
  } else if (controlAerobi_B.r_x_idx_2 == 0.0) {
    controlAerobi_B.dyaw = 0.0;
  } else {
    controlAerobi_B.dyaw = (rtNaN);
  }

  // Switch: '<S32>/Switch' incorporates:
  //   Abs: '<S36>/Abs'
  //   Constant: '<S32>/Constant'
  //   Constant: '<S39>/Constant'
  //   Logic: '<S36>/AND'
  //   RelationalOperator: '<S36>/Equal'
  //   RelationalOperator: '<S39>/Compare'
  //   Sum: '<S36>/Add'

  if ((fabs(controlAerobi_B.ubx_tmp_a - controlAerobi_B.ubx_tmp_j) >=
       controlAerobi_P.CompareToConstant_const_h5) && (controlAerobi_B.Unwrap ==
       controlAerobi_B.dyaw)) {
    controlAerobi_B.r_x_idx_2 = controlAerobi_P.Constant_Value_gt;
  }

  // Update for DiscreteIntegrator: '<S32>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_h[1] +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_k * controlAerobi_B.r_x_idx_2;

  // Update for UnitDelay: '<S37>/UD'
  controlAerobi_DWork.UD_DSTATE_i[1] = controlAerobi_B.ubx_tmp;

  // Signum: '<S48>/SignPreSat'
  if (controlAerobi_B.Sum_f < 0.0) {
    controlAerobi_B.Sum_f = -1.0;
  } else if (controlAerobi_B.Sum_f > 0.0) {
    controlAerobi_B.Sum_f = 1.0;
  } else if (controlAerobi_B.Sum_f == 0.0) {
    controlAerobi_B.Sum_f = 0.0;
  } else {
    controlAerobi_B.Sum_f = (rtNaN);
  }

  // End of Signum: '<S48>/SignPreSat'

  // Signum: '<S48>/SignPreIntegrator'
  if (controlAerobi_B.r_x_idx_0 < 0.0) {
    controlAerobi_B.Unwrap = -1.0;
  } else if (controlAerobi_B.r_x_idx_0 > 0.0) {
    controlAerobi_B.Unwrap = 1.0;
  } else if (controlAerobi_B.r_x_idx_0 == 0.0) {
    controlAerobi_B.Unwrap = 0.0;
  } else {
    controlAerobi_B.Unwrap = (rtNaN);
  }

  // End of Signum: '<S48>/SignPreIntegrator'

  // Switch: '<S35>/Switch' incorporates:
  //   Constant: '<S35>/Constant'
  //   Constant: '<S51>/Constant'
  //   Logic: '<S48>/AND'
  //   RelationalOperator: '<S48>/Equal'
  //   RelationalOperator: '<S51>/Compare'

  if ((controlAerobi_B.Abs_k >= controlAerobi_P.CompareToConstant_const_b) &&
      (controlAerobi_B.Sum_f == controlAerobi_B.Unwrap)) {
    controlAerobi_B.r_x_idx_0 = controlAerobi_P.Constant_Value_k;
  }

  // End of Switch: '<S35>/Switch'

  // Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_l +=
    controlAerobi_P.DiscreteTimeIntegrator_gainva_o * controlAerobi_B.r_x_idx_0;
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_l3 = (int8_T)
    controlAerobi_B.Compare;

  // Update for UnitDelay: '<S49>/UD'
  controlAerobi_DWork.UD_DSTATE_j = controlAerobi_B.TSamp_hv;

  // Signum: '<S40>/SignPreSat'
  if (controlAerobi_B.Sum_c < 0.0) {
    controlAerobi_B.Sum_c = -1.0;
  } else if (controlAerobi_B.Sum_c > 0.0) {
    controlAerobi_B.Sum_c = 1.0;
  } else if (controlAerobi_B.Sum_c == 0.0) {
    controlAerobi_B.Sum_c = 0.0;
  } else {
    controlAerobi_B.Sum_c = (rtNaN);
  }

  // End of Signum: '<S40>/SignPreSat'

  // Signum: '<S40>/SignPreIntegrator'
  if (controlAerobi_B.absxk < 0.0) {
    controlAerobi_B.Switch_b5 = -1.0;
  } else if (controlAerobi_B.absxk > 0.0) {
    controlAerobi_B.Switch_b5 = 1.0;
  } else if (controlAerobi_B.absxk == 0.0) {
    controlAerobi_B.Switch_b5 = 0.0;
  } else {
    controlAerobi_B.Switch_b5 = (rtNaN);
  }

  // End of Signum: '<S40>/SignPreIntegrator'

  // Switch: '<S33>/Switch' incorporates:
  //   Constant: '<S33>/Constant'
  //   Constant: '<S43>/Constant'
  //   Logic: '<S40>/AND'
  //   RelationalOperator: '<S40>/Equal'
  //   RelationalOperator: '<S43>/Compare'

  if ((controlAerobi_B.Abs_g >= controlAerobi_P.CompareToConstant_const_p) &&
      (controlAerobi_B.Sum_c == controlAerobi_B.Switch_b5)) {
    controlAerobi_B.absxk = controlAerobi_P.Constant_Value_n;
  }

  // End of Switch: '<S33>/Switch'

  // Update for DiscreteIntegrator: '<S33>/Discrete-Time Integrator'
  controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_o +=
    controlAerobi_P.DiscreteTimeIntegrator_gainv_iz * controlAerobi_B.absxk;
  controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_cu = (int8_T)
    controlAerobi_B.Compare;

  // Update for UnitDelay: '<S41>/UD'
  controlAerobi_DWork.UD_DSTATE_j5 = controlAerobi_B.TSamp_iz;

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [0.0025s, 0.0s]
    rtExtModeUpload(0, controlAerobi_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.0025s, 0.0s]
    if ((rtmGetTFinal(controlAerobi_M)!=-1) &&
        !((rtmGetTFinal(controlAerobi_M)-controlAerobi_M->Timing.taskTime0) >
          controlAerobi_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(controlAerobi_M, "Simulation finished");
    }

    if (rtmGetStopRequested(controlAerobi_M)) {
      rtmSetErrorStatus(controlAerobi_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  controlAerobi_M->Timing.taskTime0 =
    (++controlAerobi_M->Timing.clockTick0) * controlAerobi_M->Timing.stepSize0;
}

// Model initialize function
void controlAerobi_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  controlAerobi_P.Saturation_UpperSat = rtInf;
  controlAerobi_P.SatNeg_Yaw_rate_Value = rtMinusInf;
  controlAerobi_P.SatNeg_Yaw_pos_Value = rtMinusInf;
  controlAerobi_P.SatNeg_Z_rate_Value = rtMinusInf;
  controlAerobi_P.Saturation_UpperSat_a = rtInf;
  controlAerobi_P.Constant1_Value_k = rtInf;
  controlAerobi_P.Saturation_UpperSat_p = rtInf;
  controlAerobi_P.Saturation_LowerSat_k = rtMinusInf;
  controlAerobi_P.sat_P_Value[0] = rtInf;
  controlAerobi_P.sat_P_Value[1] = rtInf;
  controlAerobi_P.sat_P_Value[2] = rtInf;
  controlAerobi_P.sat_R_Value[0] = rtInf;
  controlAerobi_P.sat_R_Value[1] = rtInf;
  controlAerobi_P.sat_R_Value[2] = rtInf;
  controlAerobi_P.SatPos_Z_rate_Value = rtInf;
  controlAerobi_P.Saturation_UpperSat_n = rtInf;
  controlAerobi_P.Saturation_LowerSat_e = rtMinusInf;
  controlAerobi_P.SatPos_RollPitch_rate_Value = rtInf;
  controlAerobi_P.SatPos_XY_pos_Value = rtInf;
  controlAerobi_P.Saturation_UpperSat_pm = rtInf;
  controlAerobi_P.Saturation_LowerSat_l = rtMinusInf;
  controlAerobi_P.Saturation_UpperSat_e = rtInf;
  controlAerobi_P.Saturation_LowerSat_h = rtMinusInf;
  controlAerobi_P.SatNeg_XY_pos_Value = rtMinusInf;
  controlAerobi_P.SatPos_XY_rate_Value = rtInf;
  controlAerobi_P.Saturation_UpperSat_m = rtInf;
  controlAerobi_P.Saturation_LowerSat_p = rtMinusInf;
  controlAerobi_P.SatNeg_XY_rate_Value = rtMinusInf;
  controlAerobi_P.SatNeg_RollPitch_rate_Value = rtMinusInf;
  controlAerobi_P.SatPos_Yaw_rate_Value = rtInf;
  controlAerobi_P.SatPos_Yaw_pos_Value = rtInf;

  // initialize real-time model
  (void) memset((void *)controlAerobi_M, 0,
                sizeof(RT_MODEL_controlAerobi));
  rtmSetTFinal(controlAerobi_M, -1);
  controlAerobi_M->Timing.stepSize0 = 0.0025;

  // External mode info
  controlAerobi_M->Sizes.checksums[0] = (569576501U);
  controlAerobi_M->Sizes.checksums[1] = (3272881783U);
  controlAerobi_M->Sizes.checksums[2] = (1823612586U);
  controlAerobi_M->Sizes.checksums[3] = (1467950775U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[80];
    controlAerobi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = &rtAlwaysEnabled;
    systemRan[48] = &rtAlwaysEnabled;
    systemRan[49] = &rtAlwaysEnabled;
    systemRan[50] = &rtAlwaysEnabled;
    systemRan[51] = &rtAlwaysEnabled;
    systemRan[52] = &rtAlwaysEnabled;
    systemRan[53] = &rtAlwaysEnabled;
    systemRan[54] = &rtAlwaysEnabled;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = &rtAlwaysEnabled;
    systemRan[57] = &rtAlwaysEnabled;
    systemRan[58] = &rtAlwaysEnabled;
    systemRan[59] = &rtAlwaysEnabled;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = &rtAlwaysEnabled;
    systemRan[62] = &rtAlwaysEnabled;
    systemRan[63] = &rtAlwaysEnabled;
    systemRan[64] = &rtAlwaysEnabled;
    systemRan[65] = &rtAlwaysEnabled;
    systemRan[66] = &rtAlwaysEnabled;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = &rtAlwaysEnabled;
    systemRan[69] = &rtAlwaysEnabled;
    systemRan[70] = &rtAlwaysEnabled;
    systemRan[71] = &rtAlwaysEnabled;
    systemRan[72] = &rtAlwaysEnabled;
    systemRan[73] = &rtAlwaysEnabled;
    systemRan[74] = &rtAlwaysEnabled;
    systemRan[75] = &rtAlwaysEnabled;
    systemRan[76] = &rtAlwaysEnabled;
    systemRan[77] = &rtAlwaysEnabled;
    systemRan[78] = &rtAlwaysEnabled;
    systemRan[79] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controlAerobi_M->extModeInfo,
      &controlAerobi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controlAerobi_M->extModeInfo,
                        controlAerobi_M->Sizes.checksums);
    rteiSetTPtr(controlAerobi_M->extModeInfo, rtmGetTPtr(controlAerobi_M));
  }

  // block I/O
  (void) memset(((void *) &controlAerobi_B), 0,
                sizeof(BlockIO_controlAerobi));

  // states (dwork)
  (void) memset((void *)&controlAerobi_DWork, 0,
                sizeof(D_Work_controlAerobi));

  // external inputs
  (void)memset((void *)&controlAerobi_U, 0, sizeof(ExternalInputs_controlAerobi));

  // external outputs
  (void) memset((void *)&controlAerobi_Y, 0,
                sizeof(ExternalOutputs_controlAerobi));

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    controlAerobi_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    char_T *sErr;
    int32_T i;

    // Start for S-Function (sdspFromNetwork): '<S120>/PX4 receive'
    sErr = GetErrorBuffer(&controlAerobi_DWork.PX4receive_NetworkLib[0U]);
    CreateUDPInterface(&controlAerobi_DWork.PX4receive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&controlAerobi_DWork.PX4receive_NetworkLib[0U], 0,
                        "0.0.0.0", controlAerobi_P.PX4receive_localPort,
                        "127.0.0.1", -1, 1, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&controlAerobi_DWork.PX4receive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&controlAerobi_DWork.PX4receive_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(controlAerobi_M, sErr);
        rtmSetStopRequested(controlAerobi_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S120>/PX4 receive'

    // Start for S-Function (sdspFromNetwork): '<S181>/Local position receive'
    sErr = GetErrorBuffer(&controlAerobi_DWork.Localpositionreceive_NetworkLib
                          [0U]);
    CreateUDPInterface(&controlAerobi_DWork.Localpositionreceive_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&controlAerobi_DWork.Localpositionreceive_NetworkLib[0U],
                        0, "0.0.0.0",
                        controlAerobi_P.Localpositionreceive_localPort,
                        "127.0.0.1", -1, 1, 4, 0);
    }

    if (*sErr == 0) {
      LibStart(&controlAerobi_DWork.Localpositionreceive_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&controlAerobi_DWork.Localpositionreceive_NetworkLib
                          [0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(controlAerobi_M, sErr);
        rtmSetStopRequested(controlAerobi_M, 1);
      }
    }

    // End of Start for S-Function (sdspFromNetwork): '<S181>/Local position receive' 

    // InitializeConditions for S-Function (sdspunwrap2): '<S119>/Unwrap'
    controlAerobi_DWork.Unwrap_FirstStep = true;
    controlAerobi_DWork.Unwrap_Cumsum = 0.0;

    // InitializeConditions for RateLimiter: '<S107>/Rate Limiter1'
    controlAerobi_DWork.PrevY[0] = controlAerobi_P.RateLimiter1_IC;

    // InitializeConditions for RateLimiter: '<S111>/Rate Limiter1'
    controlAerobi_DWork.PrevY_i[0] = controlAerobi_P.RateLimiter1_IC_i;

    // InitializeConditions for RateLimiter: '<S113>/Rate Limiter'
    controlAerobi_DWork.PrevY_m[0] = controlAerobi_P.RateLimiter_IC;

    // InitializeConditions for RateLimiter: '<S115>/Rate Limiter1'
    controlAerobi_DWork.PrevY_f[0] = controlAerobi_P.RateLimiter1_IC_iz;

    // InitializeConditions for RateLimiter: '<S107>/Rate Limiter1'
    controlAerobi_DWork.PrevY[1] = controlAerobi_P.RateLimiter1_IC;

    // InitializeConditions for RateLimiter: '<S111>/Rate Limiter1'
    controlAerobi_DWork.PrevY_i[1] = controlAerobi_P.RateLimiter1_IC_i;

    // InitializeConditions for RateLimiter: '<S113>/Rate Limiter'
    controlAerobi_DWork.PrevY_m[1] = controlAerobi_P.RateLimiter_IC;

    // InitializeConditions for RateLimiter: '<S115>/Rate Limiter1'
    controlAerobi_DWork.PrevY_f[1] = controlAerobi_P.RateLimiter1_IC_iz;

    // InitializeConditions for RateLimiter: '<S107>/Rate Limiter1'
    controlAerobi_DWork.PrevY[2] = controlAerobi_P.RateLimiter1_IC;

    // InitializeConditions for RateLimiter: '<S111>/Rate Limiter1'
    controlAerobi_DWork.PrevY_i[2] = controlAerobi_P.RateLimiter1_IC_i;

    // InitializeConditions for RateLimiter: '<S113>/Rate Limiter'
    controlAerobi_DWork.PrevY_m[2] = controlAerobi_P.RateLimiter_IC;

    // InitializeConditions for RateLimiter: '<S115>/Rate Limiter1'
    controlAerobi_DWork.PrevY_f[2] = controlAerobi_P.RateLimiter1_IC_iz;

    // InitializeConditions for RateLimiter: '<S175>/Rate Limiter'
    controlAerobi_DWork.PrevY_o = controlAerobi_P.RateLimiter_IC_a;

    // InitializeConditions for RateLimiter: '<S175>/Rate Limiter1'
    controlAerobi_DWork.PrevY_p = controlAerobi_P.RateLimiter1_IC_b;

    // InitializeConditions for RateLimiter: '<S175>/Rate Limiter2'
    controlAerobi_DWork.PrevY_d = controlAerobi_P.RateLimiter2_IC;

    // InitializeConditions for RateLimiter: '<S175>/Rate Limiter3'
    controlAerobi_DWork.PrevY_n = controlAerobi_P.RateLimiter3_IC;

    // InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC;
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC;
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevRese = 2;

    // InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_f =
      controlAerobi_P.DiscreteTimeIntegrator_IC_d;
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_k = 2;

    // InitializeConditions for DiscreteFir: '<S104>/Hlp'
    for (i = 0; i < 10; i++) {
      controlAerobi_DWork.Hlp_states[i] = controlAerobi_P.Hlp_InitialStates;
    }

    // End of InitializeConditions for DiscreteFir: '<S104>/Hlp'

    // InitializeConditions for DiscreteIntegrator: '<S86>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_n =
      controlAerobi_P.DiscreteTimeIntegrator_IC_l;
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_b = 2;

    // InitializeConditions for DiscreteIntegrator: '<S74>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_e =
      controlAerobi_P.DiscreteTimeIntegrator_IC_df;
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_i = 2;

    // InitializeConditions for UnitDelay: '<S77>/UD'
    controlAerobi_DWork.UD_DSTATE =
      controlAerobi_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for DiscreteIntegrator: '<S75>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n5 =
      controlAerobi_P.DiscreteTimeIntegrator_IC_p;
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_c = 2;

    // InitializeConditions for UnitDelay: '<S81>/UD'
    controlAerobi_DWork.UD_DSTATE_f =
      controlAerobi_P.DiscreteDerivative_ICPrevScal_m;

    // InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_g = 2;

    // InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_l = 2;

    // InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_n = 2;

    // InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevRe_p = 2;

    // InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_gz = 2;

    // InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_h;

    // InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_m[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_c;

    // InitializeConditions for UnitDelay: '<S60>/UD'
    controlAerobi_DWork.UD_DSTATE_d[0] =
      controlAerobi_P.DiscreteDerivative_ICPrevScal_k;

    // InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_fo[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_hz;

    // InitializeConditions for UnitDelay: '<S64>/UD'
    controlAerobi_DWork.UD_DSTATE_o[0] =
      controlAerobi_P.DiscreteDerivative_ICPrevScal_e;

    // InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n2[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_f;

    // InitializeConditions for UnitDelay: '<S45>/UD'
    controlAerobi_DWork.UD_DSTATE_oo[0] =
      controlAerobi_P.DiscreteDerivative_ICPrevScal_d;

    // InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_h[0] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_ly;

    // InitializeConditions for UnitDelay: '<S37>/UD'
    controlAerobi_DWork.UD_DSTATE_i[0] =
      controlAerobi_P.DiscreteDerivative_ICPrevSca_da;

    // InitializeConditions for DiscreteIntegrator: '<S68>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_p[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_h;

    // InitializeConditions for DiscreteIntegrator: '<S56>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_m[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_c;

    // InitializeConditions for UnitDelay: '<S60>/UD'
    controlAerobi_DWork.UD_DSTATE_d[1] =
      controlAerobi_P.DiscreteDerivative_ICPrevScal_k;

    // InitializeConditions for DiscreteIntegrator: '<S57>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_fo[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_hz;

    // InitializeConditions for UnitDelay: '<S64>/UD'
    controlAerobi_DWork.UD_DSTATE_o[1] =
      controlAerobi_P.DiscreteDerivative_ICPrevScal_e;

    // InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTAT_n2[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_f;

    // InitializeConditions for UnitDelay: '<S45>/UD'
    controlAerobi_DWork.UD_DSTATE_oo[1] =
      controlAerobi_P.DiscreteDerivative_ICPrevScal_d;

    // InitializeConditions for DiscreteIntegrator: '<S32>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_h[1] =
      controlAerobi_P.DiscreteTimeIntegrator_IC_ly;

    // InitializeConditions for UnitDelay: '<S37>/UD'
    controlAerobi_DWork.UD_DSTATE_i[1] =
      controlAerobi_P.DiscreteDerivative_ICPrevSca_da;

    // InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_l =
      controlAerobi_P.DiscreteTimeIntegrator_IC_cx;
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_l3 = 2;

    // InitializeConditions for UnitDelay: '<S49>/UD'
    controlAerobi_DWork.UD_DSTATE_j =
      controlAerobi_P.DiscreteDerivative_ICPrevScal_a;

    // InitializeConditions for DiscreteIntegrator: '<S33>/Discrete-Time Integrator' 
    controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE_o =
      controlAerobi_P.DiscreteTimeIntegrator_IC_a;
    controlAerobi_DWork.DiscreteTimeIntegrator_PrevR_cu = 2;

    // InitializeConditions for UnitDelay: '<S41>/UD'
    controlAerobi_DWork.UD_DSTATE_j5 =
      controlAerobi_P.DiscreteDerivative_ICPrevSca_kf;

    // SystemInitialize for MATLAB Function: '<S110>/MATLAB Function'
    controlAerobi_DWork.offset_not_empty = false;
    controlAerobi_DWork.num_not_empty = false;
    controlAerobi_DWork.state_not_empty = false;
    controlAerobi_DWork.suma_not_empty = false;

    // SystemInitialize for MATLAB Function: '<S147>/Embedded MATLAB Function1'
    controlAerobi_DWork.q__not_empty = false;
    controlAerobi_DWork.b__not_empty = false;
    controlAerobi_DWork.mi_not_empty = false;
    controlAerobi_DWork.e3_not_empty = false;

    // SystemInitialize for MATLAB Function: '<S109>/MATLAB Function'
    controlAero_MATLABFunction_Init(&controlAerobi_DWork.sf_MATLABFunction_a);

    // SystemInitialize for MATLAB Function: '<S140>/Embedded MATLAB Function1'
    controlAerobi_DWork.q__not_empty_h = false;
    controlAerobi_DWork.b__not_empty_b = false;
    controlAerobi_DWork.mi_not_empty_n = false;
    controlAerobi_DWork.e3_not_empty_a = false;
    controlAerobi_DWork.mb_not_empty = false;

    // SystemInitialize for MATLAB Function: '<S114>/MATLAB Function'
    controlAero_MATLABFunction_Init(&controlAerobi_DWork.sf_MATLABFunction_c);

    // SystemInitialize for MATLAB Function: '<S127>/FCF_fcn'
    controlAerobi_DWork.q_est_aw_hat_not_empty = false;
    controlAerobi_DWork.q_est_amw_hat_not_empty = false;
    controlAerobi_DWork.time_not_empty_l = false;

    // SystemInitialize for MATLAB Function: '<S106>/TGIC_fcn'
    controlAerobi_DWork.X_k_not_empty = false;
    controlAerobi_DWork.P_k_not_empty_l = false;
    controlAerobi_DWork.t_not_empty = false;
    controlAerobi_DWork.S_a_not_empty = false;
    controlAerobi_DWork.S_m_not_empty = false;
    controlAerobi_DWork.S_g_not_empty = false;
    controlAerobi_DWork.S_P_not_empty = false;
    controlAerobi_DWork.time_not_empty_j = false;

    // SystemInitialize for MATLAB Function: '<S175>/buffer'
    controlAerobi_DWork.buffer_not_empty = false;
    controlAerobi_DWork.time_not_empty = false;
    controlAerobi_DWork.index_not_empty = false;
    controlAerobi_DWork.counter_not_empty = false;
    controlAerobi_DWork.acc__not_empty = false;

    // SystemInitialize for MATLAB Function: '<S175>/EKF_dXYZ'
    controlAerobi_DWork.time_not_empty_b = false;
    controlAerobi_DWork.timeTS0_not_empty = false;
    controlAerobi_DWork.dx_k_not_empty = false;
    controlAerobi_DWork.dP_k_not_empty = false;
    controlAerobi_DWork.queue_dx_not_empty = false;
    controlAerobi_DWork.queue_dP_not_empty = false;
    controlAerobi_DWork.index_not_empty_d = false;
    controlAerobi_DWork.Ndata_not_empty = false;
    controlAerobi_DWork.timefreq_not_empty = false;

    // SystemInitialize for MATLAB Function: '<S175>/Liner Fixed-gain Filter'
    controlAerobi_DWork.x_k_not_empty_m = false;
    controlAerobi_DWork.P_k_not_empty_d = false;

    // SystemInitialize for MATLAB Function: '<S175>/EKF2_XYZ'
    controlAerobi_DWork.x_k_not_empty_i = false;
    controlAerobi_DWork.P_k_not_empty_i = false;
    controlAerobi_DWork.x0_not_empty = false;
    controlAerobi_DWork.y0_not_empty = false;
    controlAerobi_DWork.z0_not_empty = false;

    // SystemInitialize for MATLAB Function: '<S172>/Liner Fixed-gain Filter1'
    controlAerobi_DWork.x_k_not_empty = false;
    controlAerobi_DWork.P_k_not_empty = false;

    // SystemInitialize for MATLAB Function: '<S20>/altitude_fcn'
    controlAerobi_DWork.z0_not_empty_h = false;
    controlAerobi_DWork.althold0_not_empty_k = false;
    controlAerobi_DWork.thrust0_not_empty_h = false;

    // SystemInitialize for MATLAB Function: '<S16>/calculate_v_d'
    controlAerobi_DWork.x_k_not_empty_a = false;
    controlAerobi_DWork.P_k_not_empty_lk = false;

    // SystemInitialize for MATLAB Function: '<S16>/calculate_ddx_d'
    controlAerobi_DWork.x_k_not_empty_d = false;
    controlAerobi_DWork.P_k_not_empty_o = false;

    // SystemInitialize for MATLAB Function: '<S10>/trajectory_tracking'
    controlAerobi_DWork.e_i_not_empty = false;
    controlAerobi_DWork.M_not_empty = false;

    // SystemInitialize for MATLAB Function: '<S11>/MATLAB Function'
    controlAerobi_DWork.x_k_not_empty_my = false;
    controlAerobi_DWork.P_k_not_empty_ol = false;

    // SystemInitialize for MATLAB Function: '<S11>/calculate_dOmega_d'
    controlAerobi_DWork.x_k_not_empty_mk = false;
    controlAerobi_DWork.P_k_not_empty_f = false;

    // SystemInitialize for MATLAB Function: '<S9>/attitude_geometric_control'
    controlAerobi_DWork.e_I_not_empty = false;
    controlAerobi_DWork.M_not_empty_f = false;

    // SystemInitialize for MATLAB Function: '<S73>/altitude_fcn'
    controlAerobi_DWork.z0_not_empty_c = false;
    controlAerobi_DWork.althold0_not_empty = false;
    controlAerobi_DWork.thrust0_not_empty = false;

    // SystemInitialize for MATLAB Function: '<S52>/Create_Pos_Hold'
    controlAerobi_DWork.posHold_not_empty = false;
    controlAerobi_DWork.posState_not_empty = false;
    controlAerobi_DWork.stop_not_empty = false;
    controlAerobi_DWork.XY_ref0_not_empty = false;
    controlAerobi_DWork.solution0_not_empty = false;

    // SystemInitialize for MATLAB Function: '<S29>/Continuous Yaw Generator'
    controlAerobi_DWork.yaw_references_not_empty = false;
    controlAerobi_DWork.yaw_position_old_not_empty = false;
    controlAerobi_DWork.n_not_empty = false;
  }
}

// Model terminate function
void controlAerobi_terminate(void)
{
  char_T *sErr;

  // Terminate for S-Function (sdspFromNetwork): '<S120>/PX4 receive'
  sErr = GetErrorBuffer(&controlAerobi_DWork.PX4receive_NetworkLib[0U]);
  LibTerminate(&controlAerobi_DWork.PX4receive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(controlAerobi_M, sErr);
    rtmSetStopRequested(controlAerobi_M, 1);
  }

  LibDestroy(&controlAerobi_DWork.PX4receive_NetworkLib[0U], 0);
  DestroyUDPInterface(&controlAerobi_DWork.PX4receive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S120>/PX4 receive'

  // Terminate for S-Function (sdspFromNetwork): '<S181>/Local position receive' 
  sErr = GetErrorBuffer(&controlAerobi_DWork.Localpositionreceive_NetworkLib[0U]);
  LibTerminate(&controlAerobi_DWork.Localpositionreceive_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(controlAerobi_M, sErr);
    rtmSetStopRequested(controlAerobi_M, 1);
  }

  LibDestroy(&controlAerobi_DWork.Localpositionreceive_NetworkLib[0U], 0);
  DestroyUDPInterface(&controlAerobi_DWork.Localpositionreceive_NetworkLib[0U]);

  // End of Terminate for S-Function (sdspFromNetwork): '<S181>/Local position receive' 
}

//
// File trailer for generated code.
//
// [EOF]
//
