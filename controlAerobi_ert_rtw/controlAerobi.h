//
// File: controlAerobi.h
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
#ifndef RTW_HEADER_controlAerobi_h_
#define RTW_HEADER_controlAerobi_h_
#include <string.h>
#include <math.h>
#include <float.h>
#include <stddef.h>
#ifndef controlAerobi_COMMON_INCLUDES_
# define controlAerobi_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "DAHostLib_Network.h"
#endif                                 // controlAerobi_COMMON_INCLUDES_

#include "controlAerobi_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

// user code (top of header file)
#include <shm_util.h>
#include <shm_channels.h>

// Block signals for system '<S18>/Create dXY desired'
typedef struct {
  real_T dXY_d[2];                     // '<S18>/Create dXY desired'
} rtB_CreatedXYdesired_controlAer;

// Block signals for system '<S109>/MATLAB Function'
typedef struct {
  real_T g_offset[3];                  // '<S109>/MATLAB Function'
} rtB_MATLABFunction_controlAerob;

// Block states (auto storage) for system '<S109>/MATLAB Function'
typedef struct {
  real_T offset[3];                    // '<S109>/MATLAB Function'
  real_T num;                          // '<S109>/MATLAB Function'
  real_T suma[3];                      // '<S109>/MATLAB Function'
  boolean_T offset_not_empty;          // '<S109>/MATLAB Function'
  boolean_T num_not_empty;             // '<S109>/MATLAB Function'
  boolean_T suma_not_empty;            // '<S109>/MATLAB Function'
} rtDW_MATLABFunction_controlAero;

// Block signals (auto storage)
typedef struct {
  real_T F[100];
  real_T P_k_[100];
  real_T dv0[100];
  real_T F_m[100];
  real_T b_A[100];
  real_T Ak[60];
  real_T K_k[60];
  real_T P_k__c[60];
  real_T dF[36];
  real_T dQ[36];
  real_T dF_k[36];
  real_T b_A_c[36];
  real_T K_k_b[30];
  real_T c_a[30];
  real_T R[25];
  real_T c_a_p[25];
  real_T b_A_cv[25];
  real_T dK_k[18];
  real_T y[18];
  real_T R_f[16];
  real_T rtb_Sum_g2[16];
  real_T e_a[16];
  real_T b_A_g[16];
  real_T b_A_m[16];
  real_T DataTypeConversion1_n[10];    // '<S101>/Data Type Conversion1'
  real_T DataTypeConversion_b[10];     // '<S101>/Data Type Conversion'
  real_T F_p[10];
  real_T o[10];
  real_T dv1[10];
  real_T s[10];
  real_T e[10];
  real_T work[10];
  real_T xv[10];
  real_T absdiff[10];
  real_T R_[9];
  real_T P_ui[9];
  real_T Re_R[9];
  real_T R_d_m[9];                     // '<S11>/Calculate_rotation_matrix_des'
  real_T d_a[9];
  real_T Re_R_l[9];
  real_T dv2[9];
  real_T dv3[9];
  real_T dv4[9];
  real_T dv5[9];
  real_T dv6[9];
  real_T H[8];
  real_T K_k_j[8];
  real_T H_d[8];
  real_T single2double[6];             // '<S181>/single2double'
  real_T rtb_Gain_po_g[6];
  real_T a[6];
  real_T y_k[5];
  real_T b_exp[5];
  real_T b_exp_l[5];
  real_T varargin_1[5];
  real_T F_d[4];
  real_T q_k_d[4];                     // '<S140>/Embedded MATLAB Function1'
  real_T Switch_ed[4];                 // '<S92>/Switch'
  real_T ubx[4];
  real32_T Localpositionreceive_o1[7]; // '<S181>/Local position receive'
  real32_T ByteUnpack_o1_o[6];         // '<S181>/Byte Unpack'
  real_T ub[3];
  real_T ub_[3];
  real_T ubx_d[3];
  real_T vbx[3];
  real_T eulerZYX[3];
  real_T r2[3];
  real_T Add_j[3];                     // '<S115>/Add'
  real_T Gain_po[3];                   // '<S116>/Gain'
  real_T RotationAnglescorrection[3];  // '<S119>/Rotation Angles  correction'
  real_T Add[3];                       // '<S110>/Add'
  real_T Switch[3];                    // '<S148>/Switch'
  real_T rtb_Gain_po_l[3];
  real_T P_ui_o[3];
  real_T MultiportSwitch[2];           // '<S3>/Multiport Switch'
  real_T MultiportSwitch1[2];          // '<S3>/Multiport Switch1'
  real_T MultiportSwitch2[2];          // '<S3>/Multiport Switch2'
  real_T MultiportSwitch3[2];          // '<S3>/Multiport Switch3'
  real_T Gain[3];                      // '<S102>/Gain'
  real_T Gain1[3];                     // '<S102>/Gain1'
  real_T Gain2[3];                     // '<S102>/Gain2'
  real_T F_b[2];
  int8_T R_n[9];
  real_T Gain3;                        // '<S172>/Gain3'
  real_T vx;                           // '<S172>/Liner Fixed-gain Filter1'
  real_T vy;                           // '<S172>/Liner Fixed-gain Filter1'
  real_T ax;                           // '<S172>/Liner Fixed-gain Filter1'
  real_T ay;                           // '<S172>/Liner Fixed-gain Filter1'
  real32_T PX4receive_o1[11];          // '<S120>/PX4 receive'
  real32_T ByteUnpack_o1[10];          // '<S120>/Byte Unpack'
  real_T b_exp_b;
  real_T sinc;
  real_T absxk;
  real_T t;
  real_T dZ_des;                       // '<S72>/Switch1'
  real_T Switch_l0;                    // '<S73>/Switch'
  real_T Divide;                       // '<S72>/Divide'
  real_T Unwrap;                       // '<S119>/Unwrap'
  real_T DiscreteTimeIntegrator_b;     // '<S26>/Discrete-Time Integrator'
  real_T Abs_a;                        // '<S76>/Abs'
  real_T Product1_a1;                  // '<S74>/Product1'
  real_T Product1_ew;                  // '<S75>/Product1'
  real_T Zgain_a;                      // '<S86>/Zgain'
  real_T Abs;                          // '<S80>/Abs'
  real_T Abs_k;                        // '<S48>/Abs'
  real_T Abs_g;                        // '<S40>/Abs'
  real_T Sum_c;                        // '<S33>/Sum'
  real_T Sum_f;                        // '<S35>/Sum'
  real_T Sum_b;                        // '<S75>/Sum'
  real_T Sum_n;                        // '<S74>/Sum'
  real_T Sum;                          // '<S121>/Sum'
  real_T Switch2_n;                    // '<S8>/Switch2'
  real_T Switch4;                      // '<S33>/Switch4'
  real_T DeadZone1;                    // '<S29>/Dead Zone1'
  real_T TSamp_iz;                     // '<S41>/TSamp'
  real_T TSamp_hv;                     // '<S49>/TSamp'
  real_T TSamp_h;                      // '<S81>/TSamp'
  real_T TSamp;                        // '<S77>/TSamp'
  real_T Gain3_l;                      // '<S11>/Gain3'
  real_T Gain5;                        // '<S91>/Gain5'
  real_T Switch_b5;                    // '<S90>/Switch'
  real_T Gain7;                        // '<S91>/Gain7'
  real_T dyaw;
  real_T rtb_TSamp_p_h;
  real_T rtb_Sum_l_b;
  real_T rtb_Abs_o_d;
  real_T rtb_Abs_c_e;
  real_T rtb_TSamp_i_b;
  real_T rtb_Sum_cw_j;
  real_T x_I_idx_1;
  real_T rtb_Switch2_o_idx_0;
  real_T rtb_Switch2_o_idx_1;
  real_T r_x_idx_0;
  real_T r_x_idx_1;
  real_T r_x_idx_2;
  real_T b_x_idx_1;
  real_T b_x_idx_2;
  real_T rtb_Switch_Pos_idx_1;
  real_T rtb_Switch3_idx_0;
  real_T rtb_Switch3_idx_1;
  real_T rtb_Switch_b_idx_0;
  real_T rtb_Product1_kp_idx_0;
  real_T rtb_Switch_b_idx_1;
  real_T rtb_Product1_kp_idx_1;
  real_T rtb_Zgain_idx_0;
  real_T rtb_Gain1_k_idx_0;
  real_T rtb_XYd_idx_0;
  real_T rtb_XYd_idx_1;
  real_T rtb_Saturation_b_idx_0;
  real_T rtb_Saturation_b_idx_1;
  real_T y_k_idx_0;
  real_T y_k_idx_1;
  real_T rtb_Product1_na_idx_0;
  real_T rtb_Product1_a_idx_0;
  real_T rtb_Product1_na_idx_1;
  real_T rtb_Product1_a_idx_1;
  real_T rtb_Saturation_g_idx_0;
  real_T rtb_Saturation_g_idx_1;
  real_T rtb_TSamp_p_idx_0;
  real_T rtb_Sum_l_idx_0;
  real_T rtb_Abs_o_idx_0;
  real_T rtb_TSamp_j_idx_0;
  real_T rtb_Sum_oc_idx_0;
  real_T rtb_Abs_c_idx_0;
  real_T rtb_Abs_l_idx_0;
  real_T rtb_TSamp_i_idx_0;
  real_T rtb_Sum_cw_idx_0;
  real_T rtb_Abs_l_idx_1;
  real_T rtb_TSamp_n_idx_0;
  real_T rtb_Sum_m_idx_0;
  real_T rtb_Abs_f_idx_0;
  real_T rtb_Switch_ed_f;
  real_T ubx_tmp;
  real_T ubx_tmp_a;
  real_T ubx_tmp_j;
  real_T rtb_R_d_m_tmp;
  real_T rtb_R_d_m_tmp_j;
  real_T absx;
  real_T nrm;
  real_T rt;
  real_T ztest;
  real_T smm1;
  real_T emm1;
  real_T sqds;
  real_T shift;
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale;
  real_T ads;
  real_T smax;
  real_T s_o;
  real_T smax_n;
  real_T s_i;
  real_T smax_o;
  real_T smax_nv;
  real_T R_tmp;
  real_T R_tmp_m;
  real_T R_tmp_c;
  real_T scale_m;
  real_T absxk_m;
  real_T t_j;
  real_T scale_h;
  real_T absxk_c;
  real_T t_c;
  real32_T _adc0;                      // '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' 
  real32_T _adc1;                      // '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' 
  real32_T _adc2;                      // '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' 
  real32_T _adc3;                      // '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' 
  real32_T _adc4;                      // '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' 
  real32_T _adc5;                      // '<Root>/BusConversion_InsertedFor_I_adc_at_outport_0' 
  real32_T DataTypeConversion2[39];    // '<S3>/Data Type Conversion2'
  real32_T DataTypeConversion[17];     // '<S3>/Data Type Conversion'
  real32_T DataTypeConversion1[10];    // '<S3>/Data Type Conversion1'
  uint32_T ByteUnpack_o2;              // '<S120>/Byte Unpack'
  uint32_T ByteUnpack_o2_f;            // '<S181>/Byte Unpack'
  uint8_T BytePack[44];                // '<S120>/Byte Pack'
  uint8_T BytePack_j[28];              // '<S181>/Byte Pack'
  boolean_T Compare;                   // '<S159>/Compare'
  boolean_T ALTHOLD;                   // '<S155>/Logical Operator'
  boolean_T POS_HOLD;                  // '<S155>/Logical Operator1'
  rtB_MATLABFunction_controlAerob sf_MATLABFunction_c;// '<S114>/MATLAB Function' 
  rtB_MATLABFunction_controlAerob sf_MATLABFunction_a;// '<S109>/MATLAB Function' 
  rtB_CreatedXYdesired_controlAer sf_CreatedXYdesired;// '<S58>/Create dXY desired' 
  rtB_CreatedXYdesired_controlAer sf_CreatedXYdesired_o;// '<S18>/Create dXY desired' 
} BlockIO_controlAerobi;

// Block states (auto storage) for system '<Root>'
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[2];// '<S18>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_f;// '<S26>/Discrete-Time Integrator'
  real_T Hlp_states[10];               // '<S104>/Hlp'
  real_T DiscreteTimeIntegrator_DSTATE_n;// '<S86>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_e;// '<S74>/Discrete-Time Integrator'
  real_T UD_DSTATE;                    // '<S77>/UD'
  real_T DiscreteTimeIntegrator_DSTAT_n5;// '<S75>/Discrete-Time Integrator'
  real_T UD_DSTATE_f;                  // '<S81>/UD'
  real_T DiscreteTimeIntegrator_DSTATE_p[2];// '<S68>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_m[2];// '<S56>/Discrete-Time Integrator'
  real_T UD_DSTATE_d[2];               // '<S60>/UD'
  real_T DiscreteTimeIntegrator_DSTAT_fo[2];// '<S57>/Discrete-Time Integrator'
  real_T UD_DSTATE_o[2];               // '<S64>/UD'
  real_T DiscreteTimeIntegrator_DSTAT_n2[2];// '<S34>/Discrete-Time Integrator'
  real_T UD_DSTATE_oo[2];              // '<S45>/UD'
  real_T DiscreteTimeIntegrator_DSTATE_h[2];// '<S32>/Discrete-Time Integrator'
  real_T UD_DSTATE_i[2];               // '<S37>/UD'
  real_T DiscreteTimeIntegrator_DSTATE_l;// '<S35>/Discrete-Time Integrator'
  real_T UD_DSTATE_j;                  // '<S49>/UD'
  real_T DiscreteTimeIntegrator_DSTATE_o;// '<S33>/Discrete-Time Integrator'
  real_T UD_DSTATE_j5;                 // '<S41>/UD'
  real_T PX4receive_NetworkLib[137];   // '<S120>/PX4 receive'
  real_T Unwrap_Prev;                  // '<S119>/Unwrap'
  real_T Unwrap_Cumsum;                // '<S119>/Unwrap'
  real_T PrevY[3];                     // '<S107>/Rate Limiter1'
  real_T PrevY_i[3];                   // '<S111>/Rate Limiter1'
  real_T PrevY_m[3];                   // '<S113>/Rate Limiter'
  real_T PrevY_f[3];                   // '<S115>/Rate Limiter1'
  real_T Localpositionreceive_NetworkLib[137];// '<S181>/Local position receive' 
  real_T PrevY_o;                      // '<S175>/Rate Limiter'
  real_T PrevY_p;                      // '<S175>/Rate Limiter1'
  real_T PrevY_d;                      // '<S175>/Rate Limiter2'
  real_T PrevY_n;                      // '<S175>/Rate Limiter3'
  real_T x_k[2];                       // '<S172>/Liner Fixed-gain Filter1'
  real_T P_k[4];                       // '<S172>/Liner Fixed-gain Filter1'
  real_T buffer[60];                   // '<S175>/buffer'
  real_T time;                         // '<S175>/buffer'
  real_T index;                        // '<S175>/buffer'
  real_T counter[20];                  // '<S175>/buffer'
  real_T acc_[3];                      // '<S175>/buffer'
  real_T x_k_a[2];                     // '<S175>/Liner Fixed-gain Filter'
  real_T P_k_n[4];                     // '<S175>/Liner Fixed-gain Filter'
  real_T time_a;                       // '<S175>/EKF_dXYZ'
  real_T timeTS0;                      // '<S175>/EKF_dXYZ'
  real_T dx_k[6];                      // '<S175>/EKF_dXYZ'
  real_T dP_k[36];                     // '<S175>/EKF_dXYZ'
  real_T index_j;                      // '<S175>/EKF_dXYZ'
  real_T x_k_f[6];                     // '<S175>/EKF2_XYZ'
  real_T P_k_h[36];                    // '<S175>/EKF2_XYZ'
  real_T q_[4];                        // '<S147>/Embedded MATLAB Function1'
  real_T b_[3];                        // '<S147>/Embedded MATLAB Function1'
  real_T mi[3];                        // '<S147>/Embedded MATLAB Function1'
  real_T e3[3];                        // '<S147>/Embedded MATLAB Function1'
  real_T q__c[4];                      // '<S140>/Embedded MATLAB Function1'
  real_T b__h[3];                      // '<S140>/Embedded MATLAB Function1'
  real_T mi_g[3];                      // '<S140>/Embedded MATLAB Function1'
  real_T e3_k[3];                      // '<S140>/Embedded MATLAB Function1'
  real_T offset[3];                    // '<S110>/MATLAB Function'
  real_T num;                          // '<S110>/MATLAB Function'
  real_T state;                        // '<S110>/MATLAB Function'
  real_T suma[3];                      // '<S110>/MATLAB Function'
  real_T X_k[10];                      // '<S106>/TGIC_fcn'
  real_T P_k_hx[100];                  // '<S106>/TGIC_fcn'
  real_T t;                            // '<S106>/TGIC_fcn'
  real_T S_a[30];                      // '<S106>/TGIC_fcn'
  real_T S_q[100];                     // '<S106>/TGIC_fcn'
  real_T S_P[1000];                    // '<S106>/TGIC_fcn'
  real_T time_n;                       // '<S106>/TGIC_fcn'
  real_T q_est_aw_hat[4];              // '<S127>/FCF_fcn'
  real_T time_l;                       // '<S127>/FCF_fcn'
  real_T z0;                           // '<S73>/altitude_fcn'
  real_T althold0;                     // '<S73>/altitude_fcn'
  real_T thrust0;                      // '<S73>/altitude_fcn'
  real_T posHold[2];                   // '<S52>/Create_Pos_Hold'
  real_T posState;                     // '<S52>/Create_Pos_Hold'
  real_T stop[2];                      // '<S52>/Create_Pos_Hold'
  real_T XY_ref0[2];                   // '<S52>/Create_Pos_Hold'
  real_T solution0;                    // '<S52>/Create_Pos_Hold'
  real_T yaw_references;               // '<S29>/Continuous Yaw Generator'
  real_T yaw_position_old;             // '<S29>/Continuous Yaw Generator'
  real_T n;                            // '<S29>/Continuous Yaw Generator'
  real_T e_i[3];                       // '<S10>/trajectory_tracking'
  real_T M[3];                         // '<S10>/trajectory_tracking'
  real_T x_k_l[6];                     // '<S16>/calculate_v_d'
  real_T P_k_d[36];                    // '<S16>/calculate_v_d'
  real_T x_k_m[6];                     // '<S16>/calculate_ddx_d'
  real_T P_k_k[36];                    // '<S16>/calculate_ddx_d'
  real_T z0_g;                         // '<S20>/altitude_fcn'
  real_T althold0_b;                   // '<S20>/altitude_fcn'
  real_T thrust0_f;                    // '<S20>/altitude_fcn'
  real_T e_I[3];                       // '<S9>/attitude_geometric_control'
  real_T M_g[3];                       // '<S9>/attitude_geometric_control'
  real_T x_k_a1[6];                    // '<S11>/calculate_dOmega_d'
  real_T P_k_c[36];                    // '<S11>/calculate_dOmega_d'
  real_T x_k_fc[6];                    // '<S11>/MATLAB Function'
  real_T P_k_a[36];                    // '<S11>/MATLAB Function'
  struct {
    void *LoggedData[4];
  } PLOT_PWORK;                        // '<Root>/PLOT'

  struct {
    void *LoggedData[3];
  } imu_PWORK;                         // '<S98>/imu'

  struct {
    void *LoggedData;
  } PX4_PWORK;                         // '<S100>/PX4'

  struct {
    void *LoggedData;
  } datalog_PWORK;                     // '<S3>/datalog'

  int8_T DiscreteTimeIntegrator_PrevRese;// '<S18>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_k;// '<S26>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_b;// '<S86>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_i;// '<S74>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_c;// '<S75>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_g;// '<S68>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_l;// '<S56>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_n;// '<S57>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_p;// '<S34>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_gz;// '<S32>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_l3;// '<S35>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_cu;// '<S33>/Discrete-Time Integrator'
  boolean_T Unwrap_FirstStep;          // '<S119>/Unwrap'
  boolean_T x_k_not_empty;             // '<S172>/Liner Fixed-gain Filter1'
  boolean_T P_k_not_empty;             // '<S172>/Liner Fixed-gain Filter1'
  boolean_T buffer_not_empty;          // '<S175>/buffer'
  boolean_T time_not_empty;            // '<S175>/buffer'
  boolean_T index_not_empty;           // '<S175>/buffer'
  boolean_T counter_not_empty;         // '<S175>/buffer'
  boolean_T acc__not_empty;            // '<S175>/buffer'
  boolean_T x_k_not_empty_m;           // '<S175>/Liner Fixed-gain Filter'
  boolean_T P_k_not_empty_d;           // '<S175>/Liner Fixed-gain Filter'
  boolean_T time_not_empty_b;          // '<S175>/EKF_dXYZ'
  boolean_T timeTS0_not_empty;         // '<S175>/EKF_dXYZ'
  boolean_T dx_k_not_empty;            // '<S175>/EKF_dXYZ'
  boolean_T dP_k_not_empty;            // '<S175>/EKF_dXYZ'
  boolean_T queue_dx_not_empty;        // '<S175>/EKF_dXYZ'
  boolean_T queue_dP_not_empty;        // '<S175>/EKF_dXYZ'
  boolean_T index_not_empty_d;         // '<S175>/EKF_dXYZ'
  boolean_T Ndata_not_empty;           // '<S175>/EKF_dXYZ'
  boolean_T timefreq_not_empty;        // '<S175>/EKF_dXYZ'
  boolean_T x_k_not_empty_i;           // '<S175>/EKF2_XYZ'
  boolean_T P_k_not_empty_i;           // '<S175>/EKF2_XYZ'
  boolean_T x0_not_empty;              // '<S175>/EKF2_XYZ'
  boolean_T y0_not_empty;              // '<S175>/EKF2_XYZ'
  boolean_T z0_not_empty;              // '<S175>/EKF2_XYZ'
  boolean_T q__not_empty;              // '<S147>/Embedded MATLAB Function1'
  boolean_T b__not_empty;              // '<S147>/Embedded MATLAB Function1'
  boolean_T mi_not_empty;              // '<S147>/Embedded MATLAB Function1'
  boolean_T e3_not_empty;              // '<S147>/Embedded MATLAB Function1'
  boolean_T q__not_empty_h;            // '<S140>/Embedded MATLAB Function1'
  boolean_T b__not_empty_b;            // '<S140>/Embedded MATLAB Function1'
  boolean_T mi_not_empty_n;            // '<S140>/Embedded MATLAB Function1'
  boolean_T e3_not_empty_a;            // '<S140>/Embedded MATLAB Function1'
  boolean_T mb_not_empty;              // '<S140>/Embedded MATLAB Function1'
  boolean_T offset_not_empty;          // '<S110>/MATLAB Function'
  boolean_T num_not_empty;             // '<S110>/MATLAB Function'
  boolean_T state_not_empty;           // '<S110>/MATLAB Function'
  boolean_T suma_not_empty;            // '<S110>/MATLAB Function'
  boolean_T X_k_not_empty;             // '<S106>/TGIC_fcn'
  boolean_T P_k_not_empty_l;           // '<S106>/TGIC_fcn'
  boolean_T t_not_empty;               // '<S106>/TGIC_fcn'
  boolean_T S_a_not_empty;             // '<S106>/TGIC_fcn'
  boolean_T S_m_not_empty;             // '<S106>/TGIC_fcn'
  boolean_T S_g_not_empty;             // '<S106>/TGIC_fcn'
  boolean_T S_P_not_empty;             // '<S106>/TGIC_fcn'
  boolean_T time_not_empty_j;          // '<S106>/TGIC_fcn'
  boolean_T q_est_aw_hat_not_empty;    // '<S127>/FCF_fcn'
  boolean_T q_est_amw_hat_not_empty;   // '<S127>/FCF_fcn'
  boolean_T time_not_empty_l;          // '<S127>/FCF_fcn'
  boolean_T z0_not_empty_c;            // '<S73>/altitude_fcn'
  boolean_T althold0_not_empty;        // '<S73>/altitude_fcn'
  boolean_T thrust0_not_empty;         // '<S73>/altitude_fcn'
  boolean_T posHold_not_empty;         // '<S52>/Create_Pos_Hold'
  boolean_T posState_not_empty;        // '<S52>/Create_Pos_Hold'
  boolean_T stop_not_empty;            // '<S52>/Create_Pos_Hold'
  boolean_T XY_ref0_not_empty;         // '<S52>/Create_Pos_Hold'
  boolean_T solution0_not_empty;       // '<S52>/Create_Pos_Hold'
  boolean_T yaw_references_not_empty;  // '<S29>/Continuous Yaw Generator'
  boolean_T yaw_position_old_not_empty;// '<S29>/Continuous Yaw Generator'
  boolean_T n_not_empty;               // '<S29>/Continuous Yaw Generator'
  boolean_T e_i_not_empty;             // '<S10>/trajectory_tracking'
  boolean_T M_not_empty;               // '<S10>/trajectory_tracking'
  boolean_T x_k_not_empty_a;           // '<S16>/calculate_v_d'
  boolean_T P_k_not_empty_lk;          // '<S16>/calculate_v_d'
  boolean_T x_k_not_empty_d;           // '<S16>/calculate_ddx_d'
  boolean_T P_k_not_empty_o;           // '<S16>/calculate_ddx_d'
  boolean_T z0_not_empty_h;            // '<S20>/altitude_fcn'
  boolean_T althold0_not_empty_k;      // '<S20>/altitude_fcn'
  boolean_T thrust0_not_empty_h;       // '<S20>/altitude_fcn'
  boolean_T e_I_not_empty;             // '<S9>/attitude_geometric_control'
  boolean_T M_not_empty_f;             // '<S9>/attitude_geometric_control'
  boolean_T x_k_not_empty_mk;          // '<S11>/calculate_dOmega_d'
  boolean_T P_k_not_empty_f;           // '<S11>/calculate_dOmega_d'
  boolean_T x_k_not_empty_my;          // '<S11>/MATLAB Function'
  boolean_T P_k_not_empty_ol;          // '<S11>/MATLAB Function'
  rtDW_MATLABFunction_controlAero sf_MATLABFunction_c;// '<S114>/MATLAB Function' 
  rtDW_MATLABFunction_controlAero sf_MATLABFunction_a;// '<S109>/MATLAB Function' 
} D_Work_controlAerobi;

// External inputs (root inport signals with auto storage)
typedef struct {
  shm_imu I_imu_mpu;                   // '<Root>/I_imu_mpu'
  shm_RCin I_RCinput;                  // '<Root>/I_RCinput'
  shm_lightware I_sf11c;               // '<Root>/I_sf11c'
  shm_adc I_adc;                       // '<Root>/I_adc'
  shm_totalStation I_totalStation;     // '<Root>/I_totalStation'
  shm_imu I_imu_lsm;                   // '<Root>/I_imu_lsm'
  shm_px4flow I_px4flow;               // '<Root>/I_px4flow'
} ExternalInputs_controlAerobi;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  shm_RCou O_servoOut;                 // '<Root>/O_servoOut'
  boolean_T StateMode[3];              // '<Root>/StateMode'
} ExternalOutputs_controlAerobi;

// Parameters (auto storage)
struct Parameters_controlAerobi_ {
  real_T DiscreteDerivative_ICPrevScaled;// Mask Parameter: DiscreteDerivative_ICPrevScaled
                                         //  Referenced by: '<S77>/UD'

  real_T DiscreteDerivative_ICPrevScal_m;// Mask Parameter: DiscreteDerivative_ICPrevScal_m
                                         //  Referenced by: '<S81>/UD'

  real_T DiscreteDerivative_ICPrevScal_k;// Mask Parameter: DiscreteDerivative_ICPrevScal_k
                                         //  Referenced by: '<S60>/UD'

  real_T DiscreteDerivative_ICPrevScal_e;// Mask Parameter: DiscreteDerivative_ICPrevScal_e
                                         //  Referenced by: '<S64>/UD'

  real_T DiscreteDerivative_ICPrevScal_d;// Mask Parameter: DiscreteDerivative_ICPrevScal_d
                                         //  Referenced by: '<S45>/UD'

  real_T DiscreteDerivative_ICPrevSca_da;// Mask Parameter: DiscreteDerivative_ICPrevSca_da
                                         //  Referenced by: '<S37>/UD'

  real_T DiscreteDerivative_ICPrevScal_a;// Mask Parameter: DiscreteDerivative_ICPrevScal_a
                                         //  Referenced by: '<S49>/UD'

  real_T DiscreteDerivative_ICPrevSca_kf;// Mask Parameter: DiscreteDerivative_ICPrevSca_kf
                                         //  Referenced by: '<S41>/UD'

  real_T logs_SelectPlot1;             // Mask Parameter: logs_SelectPlot1
                                       //  Referenced by: '<S3>/SelectPlot1'

  real_T logs_SelectPlot2;             // Mask Parameter: logs_SelectPlot2
                                       //  Referenced by: '<S3>/SelectPlot2'

  real_T logs_SelectPlot3;             // Mask Parameter: logs_SelectPlot3
                                       //  Referenced by: '<S3>/SelectPlot3'

  real_T logs_SelectPlot4;             // Mask Parameter: logs_SelectPlot4
                                       //  Referenced by: '<S3>/SelectPlot4'

  real_T CompareToConstant1_const;     // Mask Parameter: CompareToConstant1_const
                                       //  Referenced by: '<S159>/Constant'

  real_T CompareToConstant2_const;     // Mask Parameter: CompareToConstant2_const
                                       //  Referenced by: '<S160>/Constant'

  real_T CompareToConstant3_const;     // Mask Parameter: CompareToConstant3_const
                                       //  Referenced by: '<S161>/Constant'

  real_T CompareToConstant_const;      // Mask Parameter: CompareToConstant_const
                                       //  Referenced by: '<S168>/Constant'

  real_T CompareToConstant_const_c;    // Mask Parameter: CompareToConstant_const_c
                                       //  Referenced by: '<S167>/Constant'

  real_T CompareToConstant_const_d;    // Mask Parameter: CompareToConstant_const_d
                                       //  Referenced by: '<S169>/Constant'

  real_T CompareToConstant4_const;     // Mask Parameter: CompareToConstant4_const
                                       //  Referenced by: '<S162>/Constant'

  real_T CompareToConstant_const_h;    // Mask Parameter: CompareToConstant_const_h
                                       //  Referenced by: '<S28>/Constant'

  real_T CompareToConstant_const_h5;   // Mask Parameter: CompareToConstant_const_h5
                                       //  Referenced by: '<S39>/Constant'

  real_T CompareToConstant_const_p;    // Mask Parameter: CompareToConstant_const_p
                                       //  Referenced by: '<S43>/Constant'

  real_T CompareToConstant_const_l;    // Mask Parameter: CompareToConstant_const_l
                                       //  Referenced by: '<S47>/Constant'

  real_T CompareToConstant_const_b;    // Mask Parameter: CompareToConstant_const_b
                                       //  Referenced by: '<S51>/Constant'

  real_T CompareToConstant_const_m;    // Mask Parameter: CompareToConstant_const_m
                                       //  Referenced by: '<S62>/Constant'

  real_T CompareToConstant_const_e;    // Mask Parameter: CompareToConstant_const_e
                                       //  Referenced by: '<S66>/Constant'

  real_T CompareToConstant_const_i;    // Mask Parameter: CompareToConstant_const_i
                                       //  Referenced by: '<S71>/Constant'

  real_T CompareToConstant_const_hw;   // Mask Parameter: CompareToConstant_const_hw
                                       //  Referenced by: '<S79>/Constant'

  real_T CompareToConstant_const_g;    // Mask Parameter: CompareToConstant_const_g
                                       //  Referenced by: '<S83>/Constant'

  real_T CompareToConstant_const_bo;   // Mask Parameter: CompareToConstant_const_bo
                                       //  Referenced by: '<S88>/Constant'

  int32_T PX4receive_localPort;        // Mask Parameter: PX4receive_localPort
                                       //  Referenced by: '<S120>/PX4 receive'

  int32_T Localpositionreceive_localPort;// Mask Parameter: Localpositionreceive_localPort
                                         //  Referenced by: '<S181>/Local position receive'

  real_T Reset_Value[4];               // Expression: [0;0;0;0]
                                       //  Referenced by: '<S5>/Reset'

  real_T Saturation_UpperSat;          // Expression: inf
                                       //  Referenced by: '<S20>/Saturation'

  real_T Saturation_LowerSat;          // Expression: 0
                                       //  Referenced by: '<S20>/Saturation'

  real_T Xdes_Value;                   // Expression: 0
                                       //  Referenced by: '<S156>/Xdes'

  real_T Ydes_Value;                   // Expression: 0
                                       //  Referenced by: '<S156>/Ydes'

  real_T zero_Value;                   // Expression: 0
                                       //  Referenced by: '<S18>/zero'

  real_T Saturation1_UpperSat;         // Expression: 3
                                       //  Referenced by: '<S18>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -3
                                       //  Referenced by: '<S18>/Saturation1'

  real_T Constant_Value;               // Expression: 0
                                       //  Referenced by: '<S26>/Constant'

  real_T Saturation2_UpperSat;         // Expression: 0.20
                                       //  Referenced by: '<S52>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -0.20
                                       //  Referenced by: '<S52>/Saturation2'

  real_T Gain_Gain;                    // Expression: 12
                                       //  Referenced by: '<S29>/Gain'

  real_T Gain1_Gain;                   // Expression: 7
                                       //  Referenced by: '<S29>/Gain1'

  real_T Constant1_Value;              // Expression: 0
                                       //  Referenced by: '<S32>/Constant1'

  real_T Constant1_Value_o;            // Expression: 0
                                       //  Referenced by: '<S33>/Constant1'

  real_T I_Yaw_rate_Value;             // Expression: 20
                                       //  Referenced by: '<S95>/I_Yaw_rate'

  real_T SatNeg_Yaw_rate_Value;        // Expression: -Inf
                                       //  Referenced by: '<S95>/SatNeg_Yaw_rate'

  real_T Constant1_Value_h;            // Expression: 0
                                       //  Referenced by: '<S34>/Constant1'

  real_T Constant1_Value_j;            // Expression: 0
                                       //  Referenced by: '<S35>/Constant1'

  real_T Constant_Value_k;             // Expression: 0
                                       //  Referenced by: '<S35>/Constant'

  real_T SatNeg_Yaw_pos_Value;         // Expression: -Inf
                                       //  Referenced by: '<S95>/SatNeg_Yaw_pos'

  real_T Constant1_Value_m;            // Expression: 0
                                       //  Referenced by: '<S56>/Constant1'

  real_T Constant1_Value_l;            // Expression: 0
                                       //  Referenced by: '<S57>/Constant1'

  real_T zero_Value_n;                 // Expression: 0
                                       //  Referenced by: '<S58>/zero'

  real_T SatNeg_Z_pos_Value;           // Expression: -2
                                       //  Referenced by: '<S95>/SatNeg_Z_pos'

  real_T SatNeg_Z_rate_Value;          // Expression: -Inf
                                       //  Referenced by: '<S95>/SatNeg_Z_rate'

  real_T Saturation_UpperSat_a;        // Expression: inf
                                       //  Referenced by: '<S73>/Saturation'

  real_T Saturation_LowerSat_f;        // Expression: 0
                                       //  Referenced by: '<S73>/Saturation'

  real_T Constant_Value_a;             // Expression: 0
                                       //  Referenced by: '<S86>/Constant'

  real_T Constant2_Value;              // Expression: 0
                                       //  Referenced by: '<S90>/Constant2'

  real_T Constant1_Value_f;            // Expression: 1
                                       //  Referenced by: '<S90>/Constant1'

  real_T Constant2_Value_n;            // Expression: 0
                                       //  Referenced by: '<S91>/Constant2'

  real_T offset_Value[3];              // Expression: [0;0;0]
                                       //  Referenced by: '<S117>/offset'

  real_T Gain_Gain_l;                  // Expression: pi/180
                                       //  Referenced by: '<S117>/Gain'

  real_T Constant_Value_ab[4];         // Expression: [0 0 0 1]
                                       //  Referenced by: '<S119>/Constant'

  real_T Constant_Value_h;             // Expression: 0
                                       //  Referenced by: '<S164>/Constant'

  real_T Constant_Value_c;             // Expression: 0
                                       //  Referenced by: '<S165>/Constant'

  real_T Constant_Value_m;             // Expression: 0
                                       //  Referenced by: '<S166>/Constant'

  real_T Gain1_Gain_p;                 // Expression: 1
                                       //  Referenced by: '<S173>/Gain1'

  real_T Gain_Gain_b;                  // Expression: 1
                                       //  Referenced by: '<S173>/Gain'

  real_T select_xy_px1_Value;          // Expression: 0
                                       //  Referenced by: '<S173>/select_xy_px1'

  real_T select_xy_px4_Value;          // Expression: 2
                                       //  Referenced by: '<S173>/select_xy_px4'

  real_T selector_xy_ekf_Value;        // Expression: 2
                                       //  Referenced by: '<S173>/selector_xy_ekf'

  real_T Constant_Value_o;             // Expression: 2000
                                       //  Referenced by: '<S7>/Constant'

  real_T Constant1_Value_k;            // Expression: inf
                                       //  Referenced by: '<S91>/Constant1'

  real_T select_Value;                 // Expression: 1
                                       //  Referenced by: '<S101>/select'

  real_T Switch_Threshold;             // Expression: 0
                                       //  Referenced by: '<S119>/Switch'

  real_T RotationAnglescorrection_Gain[9];// Expression: [0 0 1;0 1 0;1 0 0]
                                          //  Referenced by: '<S119>/Rotation Angles  correction'

  real_T Mgyro_Value[9];               // Expression: [1 0 0;0 1 0;0 0 -1]
                                       //  Referenced by: '<S110>/M gyro'

  real_T Biasgyro_Value[3];            // Expression:  [-0.039 0.0047 0.00025]
                                       //  Referenced by: '<S110>/Bias gyro'

  real_T reset_Value;                  // Expression: 1
                                       //  Referenced by: '<S110>/reset'

  real_T Maccel_Value[9];              // Expression: [0.102062997425644 -0.000360608360630755 0.000399354774698161;0 0.101817729774635 0.000576698824955731;0 0 0.100789866244925]
                                       //  Referenced by: '<S108>/M accel'

  real_T Biasaccel_Value[3];           // Expression: [-0.0492144423708621;0.144627115284475;-0.758694194437572]
                                       //  Referenced by: '<S108>/Bias accel'

  real_T Constant_Value_p[3];          // Expression: [0.5879;0.0081;0.8091]
                                       //  Referenced by: '<S148>/Constant'

  real_T Mmagnet_Value[9];             // Expression: [0.0253755958616719 -0.000792704952881109 -0.00238411920606669;0 0.0239968575813526 0.000823311977129874;0 0 0.0238779704051099]
                                       //  Referenced by: '<S112>/M magnet'

  real_T Biasmagnet_Value[3];          // Expression: [-9.15447404913273;21.2106327279048;-2.87719515232140]
                                       //  Referenced by: '<S112>/Bias magnet'

  real_T kb_Value;                     // Expression: 50
                                       //  Referenced by: '<S117>/kb'

  real_T k1_Value;                     // Expression: 1
                                       //  Referenced by: '<S117>/k1'

  real_T k2_Value;                     // Expression: 0.8
                                       //  Referenced by: '<S117>/k2'

  real_T k3_Value;                     // Expression: 0.25
                                       //  Referenced by: '<S117>/k3'

  real_T k4_Value;                     // Expression: 0.05
                                       //  Referenced by: '<S117>/k4'

  real_T limit_Value;                  // Expression: 0.03
                                       //  Referenced by: '<S117>/limit'

  real_T Mgyro_Value_f[9];             // Expression: [1 0 0;0 1 0;0 0 -1]
                                       //  Referenced by: '<S109>/M gyro'

  real_T Biasgyro_Value_n[3];          // Expression: [0 0 0]
                                       //  Referenced by: '<S109>/Bias gyro'

  real_T Maccel_Value_p[9];            // Expression: [0.102461992116242 -0.000598491957672618 0.000398970370700955;0 0.102027597979423 7.50526054392845e-05;0 0 0.101558166766067]
                                       //  Referenced by: '<S107>/M accel'

  real_T Biasaccel_Value_e[3];         // Expression: [0.0758571454418519;0.0424696823519786;-0.321384803687075]
                                       //  Referenced by: '<S107>/Bias accel'

  real_T RateLimiter1_RisingLim;       // Computed Parameter: RateLimiter1_RisingLim
                                       //  Referenced by: '<S107>/Rate Limiter1'

  real_T RateLimiter1_FallingLim;      // Computed Parameter: RateLimiter1_FallingLim
                                       //  Referenced by: '<S107>/Rate Limiter1'

  real_T RateLimiter1_IC;              // Expression: 0
                                       //  Referenced by: '<S107>/Rate Limiter1'

  real_T Constant_Value_l[3];          // Expression: [0.5879;0.0081;0.8091]
                                       //  Referenced by: '<S137>/Constant'

  real_T Mmagnet_Value_c[9];           // Expression: [0.0245576523410537 -0.00273259684033348 -0.00278802564696040;0 0.0254002563813822 -0.00118636240410959;0 0 -0.0239663665345273]
                                       //  Referenced by: '<S111>/M magnet'

  real_T Biasmagnet_Value_k[3];        // Expression: [17.0874271396470;17.12515209882385;38.7277179953262]
                                       //  Referenced by: '<S111>/Bias magnet'

  real_T RateLimiter1_RisingLim_p;     // Computed Parameter: RateLimiter1_RisingLim_p
                                       //  Referenced by: '<S111>/Rate Limiter1'

  real_T RateLimiter1_FallingLim_l;    // Computed Parameter: RateLimiter1_FallingLim_l
                                       //  Referenced by: '<S111>/Rate Limiter1'

  real_T RateLimiter1_IC_i;            // Expression: 0
                                       //  Referenced by: '<S111>/Rate Limiter1'

  real_T kb_Value_o;                   // Expression: 16
                                       //  Referenced by: '<S116>/kb'

  real_T k1_Value_l;                   // Expression: 1
                                       //  Referenced by: '<S116>/k1'

  real_T k2_Value_a;                   // Expression: 0.8
                                       //  Referenced by: '<S116>/k2'

  real_T k3_Value_j;                   // Expression: 0.25
                                       //  Referenced by: '<S116>/k3'

  real_T k4_Value_j;                   // Expression: 0.05
                                       //  Referenced by: '<S116>/k4'

  real_T limit_Value_b;                // Expression: 0.03
                                       //  Referenced by: '<S116>/limit'

  real_T Constant_Value_g;             // Expression: 100
                                       //  Referenced by: '<S140>/Constant'

  real_T offset_Value_h[3];            // Expression: [0;0;0]
                                       //  Referenced by: '<S116>/offset'

  real_T Gain_Gain_i;                  // Expression: pi/180
                                       //  Referenced by: '<S116>/Gain'

  real_T M_accel_Value[9];             // Expression: [1.001169204711914062,0,0;0,1.003445267677307129,0;0,0,1.001209974288940430]
                                       //  Referenced by: '<S113>/M_accel'

  real_T RateLimiter_RisingLim;        // Computed Parameter: RateLimiter_RisingLim
                                       //  Referenced by: '<S113>/Rate Limiter'

  real_T RateLimiter_FallingLim;       // Computed Parameter: RateLimiter_FallingLim
                                       //  Referenced by: '<S113>/Rate Limiter'

  real_T RateLimiter_IC;               // Expression: 0
                                       //  Referenced by: '<S113>/Rate Limiter'

  real_T Bias_accel_Value[3];          // Expression: [-0.008039474487304688;-0.078669071197509766;0.213560581207275391]
                                       //  Referenced by: '<S113>/Bias_accel'

  real_T M_gyro_Value[9];              // Expression: [1.000000000000000000,0,0;0,1.000000000000000000,0;0,0,-1.000000000000000000]
                                       //  Referenced by: '<S114>/M_gyro'

  real_T Bias_gyro_Value[3];           // Expression: [-0.113444186747074127;-0.091068968176841736;-0.060674510896205902]
                                       //  Referenced by: '<S114>/Bias_gyro'

  real_T M_magnet_Value[9];            // Expression: [0.962506949901580811,0,0;0,0.992451548576354980,0;0,0,1.044171094894409180]
                                       //  Referenced by: '<S115>/M_magnet'

  real_T Constant_Value_f[3];          // Expression: [0.5879;0.0081;0.8091]
                                       //  Referenced by: '<S139>/Constant'

  real_T RateLimiter1_RisingLim_n;     // Computed Parameter: RateLimiter1_RisingLim_n
                                       //  Referenced by: '<S115>/Rate Limiter1'

  real_T RateLimiter1_FallingLim_i;    // Computed Parameter: RateLimiter1_FallingLim_i
                                       //  Referenced by: '<S115>/Rate Limiter1'

  real_T RateLimiter1_IC_iz;           // Expression: 0
                                       //  Referenced by: '<S115>/Rate Limiter1'

  real_T Gain_Gain_j;                  // Expression: 1/100
                                       //  Referenced by: '<S115>/Gain'

  real_T Bias_magnet_Value[3];         // Expression: [0.211622878909111023;0.140778407454490662;0.142240136861801147]
                                       //  Referenced by: '<S115>/Bias_magnet'

  real_T mu_a_Value;                   // Expression: 0.9
                                       //  Referenced by: '<S106>/mu_a'

  real_T mu_m_Value;                   // Expression: 0.9
                                       //  Referenced by: '<S106>/mu_m'

  real_T rk_Value[6];                  // Expression: [0.4;0.4;0.4;0.1;0.1;0.1]
                                       //  Referenced by: '<S106>/rk'

  real_T qk_Value[10];                 // Expression: [0.25*(0.0025^2)*0.5;0.25*(0.0025^2)*0.5;0.25*(0.0025^2)*0.5;0.25*(0.0025^2)*0.5;0.025;0.025;0.025;0.0025;0.0025;0.0025]
                                       //  Referenced by: '<S106>/qk'

  real_T mu_Value;                     // Expression: 1.2
                                       //  Referenced by: '<S106>/mu'

  real_T chi_Value;                    // Expression: 0
                                       //  Referenced by: '<S106>/chi'

  real_T p0_Value;                     // Expression: 0.0001
                                       //  Referenced by: '<S106>/p0'

  real_T distorsion_max_Value;         // Expression: 100
                                       //  Referenced by: '<S106>/distorsion_max'

  real_T ym_Value;                     // Expression: 0.005
                                       //  Referenced by: '<S127>/ym'

  real_T ya_Value;                     // Expression: 0.005
                                       //  Referenced by: '<S127>/ya'

  real_T weight_Value;                 // Expression: 0.9
                                       //  Referenced by: '<S127>/weight'

  real_T distorsion_max_Value_g;       // Expression: 10
                                       //  Referenced by: '<S127>/distorsion_max'

  real_T er_Value;                     // Expression: 100
                                       //  Referenced by: '<S106>/er'

  real_T NEDENU_Value;                 // Expression: 1
                                       //  Referenced by: '<S174>/NED//ENU'

  real_T Gain2_Gain;                   // Expression: 1/1927
                                       //  Referenced by: '<S157>/Gain2'

  real_T Constant4_Value;              // Expression: 1
                                       //  Referenced by: '<S157>/Constant4'

  real_T Constant5_Value;              // Expression: -275
                                       //  Referenced by: '<S157>/Constant5'

  real_T RateLimiter_RisingLim_g;      // Computed Parameter: RateLimiter_RisingLim_g
                                       //  Referenced by: '<S175>/Rate Limiter'

  real_T RateLimiter_FallingLim_k;     // Computed Parameter: RateLimiter_FallingLim_k
                                       //  Referenced by: '<S175>/Rate Limiter'

  real_T RateLimiter_IC_a;             // Expression: 0
                                       //  Referenced by: '<S175>/Rate Limiter'

  real_T RateLimiter1_RisingLim_i;     // Computed Parameter: RateLimiter1_RisingLim_i
                                       //  Referenced by: '<S175>/Rate Limiter1'

  real_T RateLimiter1_FallingLim_o;    // Computed Parameter: RateLimiter1_FallingLim_o
                                       //  Referenced by: '<S175>/Rate Limiter1'

  real_T RateLimiter1_IC_b;            // Expression: 0
                                       //  Referenced by: '<S175>/Rate Limiter1'

  real_T RateLimiter2_RisingLim;       // Computed Parameter: RateLimiter2_RisingLim
                                       //  Referenced by: '<S175>/Rate Limiter2'

  real_T RateLimiter2_FallingLim;      // Computed Parameter: RateLimiter2_FallingLim
                                       //  Referenced by: '<S175>/Rate Limiter2'

  real_T RateLimiter2_IC;              // Expression: 0
                                       //  Referenced by: '<S175>/Rate Limiter2'

  real_T RateLimiter3_RisingLim;       // Computed Parameter: RateLimiter3_RisingLim
                                       //  Referenced by: '<S175>/Rate Limiter3'

  real_T RateLimiter3_FallingLim;      // Computed Parameter: RateLimiter3_FallingLim
                                       //  Referenced by: '<S175>/Rate Limiter3'

  real_T RateLimiter3_IC;              // Expression: 0
                                       //  Referenced by: '<S175>/Rate Limiter3'

  real_T d_sf11_Value;                 // Expression: 0.048
                                       //  Referenced by: '<S100>/d_sf11'

  real_T KQ_Value[6];                  // Expression: [ 0 0.005  0 0.005  0 0.0025]
                                       //  Referenced by: '<S100>/KQ'

  real_T KR_Value[5];                  // Expression: [0.01 0.1 0.01 0.1 0.05]
                                       //  Referenced by: '<S100>/KR'

  real_T selector_z_Value;             // Expression: 2
                                       //  Referenced by: '<S173>/selector_z'

  real_T Gain1_Gain_a;                 // Expression: 0.001
                                       //  Referenced by: '<S172>/Gain1'

  real_T Gain_Gain_p;                  // Expression: 0.001
                                       //  Referenced by: '<S172>/Gain'

  real_T Gain2_Gain_k;                 // Expression: 1
                                       //  Referenced by: '<S172>/Gain2'

  real_T Gain4_Gain;                   // Expression: 0
                                       //  Referenced by: '<S172>/Gain4'

  real_T Zdes_Value;                   // Expression: 1
                                       //  Referenced by: '<S156>/Zdes'

  real_T DiscreteTimeIntegrator_gainval;// Computed Parameter: DiscreteTimeIntegrator_gainval
                                        //  Referenced by: '<S18>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                       //  Referenced by: '<S18>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_gainva_i;// Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                         //  Referenced by: '<S26>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_d;  // Expression: 0
                                       //  Referenced by: '<S26>/Discrete-Time Integrator'

  real_T Saturation_UpperSat_p;        // Expression: inf
                                       //  Referenced by: '<S26>/Saturation'

  real_T Saturation_LowerSat_k;        // Expression: -inf
                                       //  Referenced by: '<S26>/Saturation'

  real_T Gain2_Gain_i;                 // Expression: 1
                                       //  Referenced by: '<S16>/Gain2'

  real_T Gain1_Gain_al;                // Expression: 1
                                       //  Referenced by: '<S16>/Gain1'

  real_T b1_Value[3];                  // Expression: [1;0;0]
                                       //  Referenced by: '<S16>/b1'

  real_T Gain_Gain_c;                  // Expression: 0.6
                                       //  Referenced by: '<S16>/Gain'

  real_T k_x_Value[3];                 // Expression: [10; 10; 10]
                                       //  Referenced by: '<S94>/k_x'

  real_T k_v_Value[3];                 // Expression: [10; 10; 10]
                                       //  Referenced by: '<S94>/k_v'

  real_T k_i_Value[3];                 // Expression: [0; 0; 0]
                                       //  Referenced by: '<S94>/k_i'

  real_T c1_Value[3];                  // Expression: [0.8; 0.8; 0.8]
                                       //  Referenced by: '<S94>/c1'

  real_T sat_P_Value[3];               // Expression: [inf; inf; inf]
                                       //  Referenced by: '<S94>/sat_P'

  real_T Mass_Value;                   // Expression: 1.97
                                       //  Referenced by: '<S94>/Mass'

  real_T Gain_Gain_b5;                 // Expression: 0
                                       //  Referenced by: '<S9>/Gain'

  real_T Hlp_InitialStates;            // Expression: 0
                                       //  Referenced by: '<S104>/Hlp'

  real_T Hlp_Coefficients[11];         // Expression: [-0.018169813976955839 0.0058137717737195456 0.058455939914966247 0.13944761285026877 0.2150131411793364 0.24597811695967281 0.2150131411793364 0.13944761285026877 0.058455939914966247 0.0058137717737195456 -0.018169813976955839]
                                       //  Referenced by: '<S104>/Hlp'

  real_T Gain_Gain_n;                  // Expression: 1/1514
                                       //  Referenced by: '<S157>/Gain'

  real_T Constant_Value_k1;            // Expression: 1
                                       //  Referenced by: '<S157>/Constant'

  real_T Constant1_Value_e;            // Expression: 1
                                       //  Referenced by: '<S157>/Constant1'

  real_T Saturation2_UpperSat_l;       // Expression: 0.5
                                       //  Referenced by: '<S157>/Saturation2'

  real_T Saturation2_LowerSat_h;       // Expression: -0.5
                                       //  Referenced by: '<S157>/Saturation2'

  real_T Gain4_Gain_f;                 // Expression: 1.5
                                       //  Referenced by: '<S11>/Gain4'

  real_T Gain1_Gain_f;                 // Expression: 1/1518
                                       //  Referenced by: '<S157>/Gain1'

  real_T Constant2_Value_f;            // Expression: 1
                                       //  Referenced by: '<S157>/Constant2'

  real_T Gain4_Gain_b;                 // Expression: 1
                                       //  Referenced by: '<S157>/Gain4'

  real_T Saturation1_UpperSat_n;       // Expression: 0.5
                                       //  Referenced by: '<S157>/Saturation1'

  real_T Saturation1_LowerSat_b;       // Expression: -0.5
                                       //  Referenced by: '<S157>/Saturation1'

  real_T Gain3_Gain;                   // Expression: 1.5
                                       //  Referenced by: '<S11>/Gain3'

  real_T Gain3_Gain_m;                 // Expression: 1/1515
                                       //  Referenced by: '<S157>/Gain3'

  real_T Constant6_Value;              // Expression: 1
                                       //  Referenced by: '<S157>/Constant6'

  real_T Constant7_Value;              // Expression: 1
                                       //  Referenced by: '<S157>/Constant7'

  real_T Gain5_Gain;                   // Expression: 1
                                       //  Referenced by: '<S157>/Gain5'

  real_T Gain1_Gain_l;                 // Expression: 0
                                       //  Referenced by: '<S11>/Gain1'

  real_T Gain2_Gain_b;                 // Expression: 1
                                       //  Referenced by: '<S11>/Gain2'

  real_T Gain_Gain_n5;                 // Expression: 1
                                       //  Referenced by: '<S11>/Gain'

  real_T J_Value[9];                   // Expression: [0.08 0 0; 0 0.08 0; 0 0 0.14]
                                       //  Referenced by: '<S94>/J'

  real_T k_R_Value[3];                 // Expression: [60; 60; 60]
                                       //  Referenced by: '<S94>/k_R'

  real_T k_Omega_Value[3];             // Expression: [8; 8; 8]
                                       //  Referenced by: '<S94>/k_Omega'

  real_T k_I_Value[3];                 // Expression: [55; 55; 55]
                                       //  Referenced by: '<S94>/k_I'

  real_T c2_Value[3];                  // Expression: [3; 3; 3]
                                       //  Referenced by: '<S94>/c2'

  real_T sat_R_Value[3];               // Expression: [inf; inf; inf]
                                       //  Referenced by: '<S94>/sat_R'

  real_T drift_Value[3];               // Expression: [0;0;0]
                                       //  Referenced by: '<S9>/drift'

  real_T SatPos_Z_rate_Value;          // Expression: Inf
                                       //  Referenced by: '<S95>/SatPos_Z_rate'

  real_T P_Z_rate_Value;               // Expression: 9
                                       //  Referenced by: '<S95>/P_Z_rate'

  real_T SatPos_Z_pos_Value;           // Expression: 2
                                       //  Referenced by: '<S95>/SatPos_Z_pos'

  real_T P_Z_pos_Value;                // Expression: 1
                                       //  Referenced by: '<S95>/P_Z_pos'

  real_T DiscreteTimeIntegrator_gainva_a;// Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                         //  Referenced by: '<S86>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_l;  // Expression: 0
                                       //  Referenced by: '<S86>/Discrete-Time Integrator'

  real_T Saturation_UpperSat_n;        // Expression: inf
                                       //  Referenced by: '<S86>/Saturation'

  real_T Saturation_LowerSat_e;        // Expression: -inf
                                       //  Referenced by: '<S86>/Saturation'

  real_T Constant_Value_oa;            // Expression: 0
                                       //  Referenced by: '<S74>/Constant'

  real_T DiscreteTimeIntegrator_gainva_e;// Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                         //  Referenced by: '<S74>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_df; // Expression: 0
                                       //  Referenced by: '<S74>/Discrete-Time Integrator'

  real_T D_Z_pos_Value;                // Expression: 0.02
                                       //  Referenced by: '<S95>/D_Z_pos'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                       //  Referenced by: '<S77>/TSamp'

  real_T med_thrust_Value;             // Expression: 52.23
                                       //  Referenced by: '<S73>/med_thrust'

  real_T adapt_thrust_Gain;            // Expression: 0.01
                                       //  Referenced by: '<S85>/adapt_thrust'

  real_T uDLookupTable_tableData[601]; // Expression: [-3:0.01:3]
                                       //  Referenced by: '<S85>/1-D Lookup Table'

  real_T uDLookupTable_bp01Data[601];  // Expression: [-3:0.01:3]
                                       //  Referenced by: '<S85>/1-D Lookup Table'

  real_T dZgain_Gain;                  // Expression: 6
                                       //  Referenced by: '<S85>/dZgain'

  real_T DeadZone_Start;               // Expression: -0.8
                                       //  Referenced by: '<S85>/Dead Zone'

  real_T DeadZone_End;                 // Expression: 0.5
                                       //  Referenced by: '<S85>/Dead Zone'

  real_T Saturation_UpperSat_g;        // Expression: 2
                                       //  Referenced by: '<S85>/Saturation'

  real_T Saturation_LowerSat_o;        // Expression: -2
                                       //  Referenced by: '<S85>/Saturation'

  real_T Constant_Value_b;             // Expression: 0
                                       //  Referenced by: '<S75>/Constant'

  real_T DiscreteTimeIntegrator_gainva_m;// Computed Parameter: DiscreteTimeIntegrator_gainva_m
                                         //  Referenced by: '<S75>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_p;  // Expression: 0
                                       //  Referenced by: '<S75>/Discrete-Time Integrator'

  real_T D_Z_rate_Value;               // Expression: 0.2
                                       //  Referenced by: '<S95>/D_Z_rate'

  real_T TSamp_WtEt_g;                 // Computed Parameter: TSamp_WtEt_g
                                       //  Referenced by: '<S81>/TSamp'

  real_T Gain1_Gain_m;                 // Expression: 6.5
                                       //  Referenced by: '<S91>/Gain1'

  real_T Constant8_Value;              // Expression: 1227
                                       //  Referenced by: '<S91>/Constant8'

  real_T SatPos_RollPitch_rate_Value;  // Expression: Inf
                                       //  Referenced by: '<S95>/SatPos_RollPitch_rate'

  real_T P_RollPitch_rate_Value;       // Expression: 6
                                       //  Referenced by: '<S95>/P_RollPitch_rate'

  real_T SatPos_RollPitch_pos_Value;   // Expression: 4
                                       //  Referenced by: '<S95>/SatPos_RollPitch_pos'

  real_T P_RollPitch_pos_Value;        // Expression: 8.5
                                       //  Referenced by: '<S95>/P_RollPitch_pos'

  real_T Gain_Gain_e;                  // Expression: 0
                                       //  Referenced by: '<S52>/Gain'

  real_T SatPos_XY_pos_Value;          // Expression: Inf
                                       //  Referenced by: '<S95>/SatPos_XY_pos'

  real_T P_XY_pos_Value;               // Expression: 3
                                       //  Referenced by: '<S95>/P_XY_pos'

  real_T DiscreteTimeIntegrator_gainv_mu;// Computed Parameter: DiscreteTimeIntegrator_gainv_mu
                                         //  Referenced by: '<S68>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_h;  // Expression: 0
                                       //  Referenced by: '<S68>/Discrete-Time Integrator'

  real_T Saturation_UpperSat_pm;       // Expression: inf
                                       //  Referenced by: '<S68>/Saturation'

  real_T Saturation_LowerSat_l;        // Expression: -inf
                                       //  Referenced by: '<S68>/Saturation'

  real_T DeadZone_Start_i;             // Expression: -0.05
                                       //  Referenced by: '<S58>/Dead Zone'

  real_T DeadZone_End_b;               // Expression: 0.05
                                       //  Referenced by: '<S58>/Dead Zone'

  real_T Gain_Gain_h;                  // Expression: -3
                                       //  Referenced by: '<S58>/Gain'

  real_T DeadZone1_Start;              // Expression: -0.05
                                       //  Referenced by: '<S58>/Dead Zone1'

  real_T DeadZone1_End;                // Expression: 0.05
                                       //  Referenced by: '<S58>/Dead Zone1'

  real_T Gain1_Gain_k;                 // Expression: 3
                                       //  Referenced by: '<S58>/Gain1'

  real_T Saturation1_UpperSat_m;       // Expression: 3
                                       //  Referenced by: '<S58>/Saturation1'

  real_T Saturation1_LowerSat_f;       // Expression: -3
                                       //  Referenced by: '<S58>/Saturation1'

  real_T adapt_thrust_Gain_l;          // Expression: 1
                                       //  Referenced by: '<S70>/adapt_thrust'

  real_T uDLookupTable_tableData_l[601];// Expression: [-3:0.01:3]
                                        //  Referenced by: '<S70>/1-D Lookup Table'

  real_T uDLookupTable_bp01Data_p[601];// Expression: [-3:0.01:3]
                                       //  Referenced by: '<S70>/1-D Lookup Table'

  real_T dZgain_Gain_l;                // Expression: 10
                                       //  Referenced by: '<S70>/dZgain'

  real_T DeadZone_Start_o;             // Expression: -0.2
                                       //  Referenced by: '<S70>/Dead Zone'

  real_T DeadZone_End_l;               // Expression: 0.2
                                       //  Referenced by: '<S70>/Dead Zone'

  real_T Saturation_UpperSat_e;        // Expression: inf
                                       //  Referenced by: '<S70>/Saturation'

  real_T Saturation_LowerSat_h;        // Expression: -inf
                                       //  Referenced by: '<S70>/Saturation'

  real_T DiscreteTimeIntegrator_gainva_d;// Computed Parameter: DiscreteTimeIntegrator_gainva_d
                                         //  Referenced by: '<S56>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_c;  // Expression: 0
                                       //  Referenced by: '<S56>/Discrete-Time Integrator'

  real_T D_XY_pos_Value;               // Expression: 0
                                       //  Referenced by: '<S95>/D_XY_pos'

  real_T TSamp_WtEt_d;                 // Computed Parameter: TSamp_WtEt_d
                                       //  Referenced by: '<S60>/TSamp'

  real_T SatNeg_XY_pos_Value;          // Expression: -Inf
                                       //  Referenced by: '<S95>/SatNeg_XY_pos'

  real_T pidpid_cascade_Value;         // Expression: 1
                                       //  Referenced by: '<S52>/pid//pid_cascade'

  real_T SatPos_XY_rate_Value;         // Expression: Inf
                                       //  Referenced by: '<S95>/SatPos_XY_rate'

  real_T P_XY_rate_Value;              // Expression: 5
                                       //  Referenced by: '<S95>/P_XY_rate'

  real_T Saturation_UpperSat_m;        // Expression: inf
                                       //  Referenced by: '<S52>/Saturation'

  real_T Saturation_LowerSat_p;        // Expression: -inf
                                       //  Referenced by: '<S52>/Saturation'

  real_T DiscreteTimeIntegrator_gainv_mv;// Computed Parameter: DiscreteTimeIntegrator_gainv_mv
                                         //  Referenced by: '<S57>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_hz; // Expression: 0
                                       //  Referenced by: '<S57>/Discrete-Time Integrator'

  real_T D_XY_rate_Value;              // Expression: 0
                                       //  Referenced by: '<S95>/D_XY_rate'

  real_T TSamp_WtEt_b;                 // Computed Parameter: TSamp_WtEt_b
                                       //  Referenced by: '<S64>/TSamp'

  real_T SatNeg_XY_rate_Value;         // Expression: -Inf
                                       //  Referenced by: '<S95>/SatNeg_XY_rate'

  real_T r_Value;                      // Expression: -1
                                       //  Referenced by: '<S52>/r'

  real_T p_Value;                      // Expression: -1
                                       //  Referenced by: '<S52>/p'

  real_T r1_Value;                     // Expression: -1
                                       //  Referenced by: '<S52>/r1'

  real_T r2_Value;                     // Expression: -1
                                       //  Referenced by: '<S52>/r2'

  real_T DiscreteTimeIntegrator_gainva_b;// Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                         //  Referenced by: '<S34>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_f;  // Expression: 0
                                       //  Referenced by: '<S34>/Discrete-Time Integrator'

  real_T D_RollPitch_pos_Value;        // Expression: 0
                                       //  Referenced by: '<S95>/D_RollPitch_pos'

  real_T TSamp_WtEt_n;                 // Computed Parameter: TSamp_WtEt_n
                                       //  Referenced by: '<S45>/TSamp'

  real_T SatNeg_RollPitch_pos_Value;   // Expression: -4
                                       //  Referenced by: '<S95>/SatNeg_RollPitch_pos'

  real_T DiscreteTimeIntegrator_gainva_k;// Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                         //  Referenced by: '<S32>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_ly; // Expression: 0
                                       //  Referenced by: '<S32>/Discrete-Time Integrator'

  real_T D_RollPitch_rate_Value;       // Expression: 0
                                       //  Referenced by: '<S95>/D_RollPitch_rate'

  real_T TSamp_WtEt_e;                 // Computed Parameter: TSamp_WtEt_e
                                       //  Referenced by: '<S37>/TSamp'

  real_T SatNeg_RollPitch_rate_Value;  // Expression: -Inf
                                       //  Referenced by: '<S95>/SatNeg_RollPitch_rate'

  real_T Constant_Value_j[2];          // Expression: [0;0]
                                       //  Referenced by: '<S29>/Constant'

  real_T Gain3_Gain_l;                 // Expression: 6.5
                                       //  Referenced by: '<S91>/Gain3'

  real_T Gain5_Gain_m;                 // Expression: 6.5
                                       //  Referenced by: '<S91>/Gain5'

  real_T SatPos_Yaw_rate_Value;        // Expression: Inf
                                       //  Referenced by: '<S95>/SatPos_Yaw_rate'

  real_T P_Yaw_rate_Value;             // Expression: 75
                                       //  Referenced by: '<S95>/P_Yaw_rate'

  real_T SatPos_Yaw_pos_Value;         // Expression: Inf
                                       //  Referenced by: '<S95>/SatPos_Yaw_pos'

  real_T P_Yaw_pos_Value;              // Expression: 10
                                       //  Referenced by: '<S95>/P_Yaw_pos'

  real_T DeadZone1_Start_c;            // Expression: -0.025
                                       //  Referenced by: '<S29>/Dead Zone1'

  real_T DeadZone1_End_a;              // Expression: 0.025
                                       //  Referenced by: '<S29>/Dead Zone1'

  real_T DiscreteTimeIntegrator_gainva_o;// Computed Parameter: DiscreteTimeIntegrator_gainva_o
                                         //  Referenced by: '<S35>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_cx; // Expression: 0
                                       //  Referenced by: '<S35>/Discrete-Time Integrator'

  real_T D_Yaw_pos_Value;              // Expression: 0
                                       //  Referenced by: '<S95>/D_Yaw_pos'

  real_T TSamp_WtEt_o;                 // Computed Parameter: TSamp_WtEt_o
                                       //  Referenced by: '<S49>/TSamp'

  real_T DiscreteTimeIntegrator_gainv_iz;// Computed Parameter: DiscreteTimeIntegrator_gainv_iz
                                         //  Referenced by: '<S33>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC_a;  // Expression: 0
                                       //  Referenced by: '<S33>/Discrete-Time Integrator'

  real_T D_Yaw_rate_Value;             // Expression: 0
                                       //  Referenced by: '<S95>/D_Yaw_rate'

  real_T TSamp_WtEt_p;                 // Computed Parameter: TSamp_WtEt_p
                                       //  Referenced by: '<S41>/TSamp'

  real_T Gain7_Gain;                   // Expression: 6.5
                                       //  Referenced by: '<S91>/Gain7'

  real_T scale2ticks_Gain;             // Expression: 1
                                       //  Referenced by: '<S7>/scale2ticks'

  real_T Constant3_Value;              // Expression: 1100
                                       //  Referenced by: '<S7>/Constant3'

  real_T Gain_Gain_i2;                 // Expression: 180/pi
                                       //  Referenced by: '<S3>/Gain'

  real_T Gain1_Gain_mz;                // Expression: 180/pi
                                       //  Referenced by: '<S3>/Gain1'

  real_T Gain2_Gain_n;                 // Expression: 180/pi
                                       //  Referenced by: '<S3>/Gain2'

  real_T DeadZone_Start_j;             // Expression: -0.05
                                       //  Referenced by: '<S18>/Dead Zone'

  real_T DeadZone_End_c;               // Expression: 0.05
                                       //  Referenced by: '<S18>/Dead Zone'

  real_T Gain_Gain_o;                  // Expression: -3
                                       //  Referenced by: '<S18>/Gain'

  real_T DeadZone1_Start_o;            // Expression: -0.05
                                       //  Referenced by: '<S18>/Dead Zone1'

  real_T DeadZone1_End_n;              // Expression: 0.05
                                       //  Referenced by: '<S18>/Dead Zone1'

  real_T Gain1_Gain_au;                // Expression: 3
                                       //  Referenced by: '<S18>/Gain1'

  real_T med_thrust_Value_n;           // Expression: 52.23
                                       //  Referenced by: '<S20>/med_thrust'

  real_T adapt_thrust_Gain_o;          // Expression: 0.01
                                       //  Referenced by: '<S25>/adapt_thrust'

  real_T uDLookupTable_tableData_j[601];// Expression: [-3:0.01:3]
                                        //  Referenced by: '<S25>/1-D Lookup Table'

  real_T uDLookupTable_bp01Data_l[601];// Expression: [-3:0.01:3]
                                       //  Referenced by: '<S25>/1-D Lookup Table'

  real_T dZgain_Gain_p;                // Expression: 6
                                       //  Referenced by: '<S25>/dZgain'

  real_T DeadZone_Start_k;             // Expression: -0.8
                                       //  Referenced by: '<S25>/Dead Zone'

  real_T DeadZone_End_l5;              // Expression: 0.5
                                       //  Referenced by: '<S25>/Dead Zone'

  real_T Saturation_UpperSat_i;        // Expression: 2
                                       //  Referenced by: '<S25>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: -2
                                       //  Referenced by: '<S25>/Saturation'

  real_T Zgain_Gain;                   // Expression: 0.5
                                       //  Referenced by: '<S26>/Zgain'

  real_T I_RollPitch_rate_Value;       // Expression: 0
                                       //  Referenced by: '<S95>/I_RollPitch_rate'

  real_T Constant_Value_gt;            // Expression: 0
                                       //  Referenced by: '<S32>/Constant'

  real_T Constant_Value_n;             // Expression: 0
                                       //  Referenced by: '<S33>/Constant'

  real_T Constant2_Value_p;            // Expression: 10
                                       //  Referenced by: '<S33>/Constant2'

  real_T I_RollPitch_pos_Value;        // Expression: 4.2
                                       //  Referenced by: '<S95>/I_RollPitch_pos'

  real_T Constant_Value_lb;            // Expression: 0
                                       //  Referenced by: '<S34>/Constant'

  real_T I_Yaw_pos_Value;              // Expression: 0.1
                                       //  Referenced by: '<S95>/I_Yaw_pos'

  real_T I_XY_pos_Value;               // Expression: 0
                                       //  Referenced by: '<S95>/I_XY_pos'

  real_T Constant_Value_jp;            // Expression: 0
                                       //  Referenced by: '<S56>/Constant'

  real_T I_XY_rate_Value;              // Expression: 0.5
                                       //  Referenced by: '<S95>/I_XY_rate'

  real_T Constant_Value_g3;            // Expression: 0
                                       //  Referenced by: '<S57>/Constant'

  real_T Zgain_Gain_e;                 // Expression: 0.5
                                       //  Referenced by: '<S68>/Zgain'

  real_T Constant_Value_gv;            // Expression: 0
                                       //  Referenced by: '<S68>/Constant'

  real_T I_Z_pos_Value;                // Expression: 0.1
                                       //  Referenced by: '<S95>/I_Z_pos'

  real_T I_Z_rate_Value;               // Expression: 0.2
                                       //  Referenced by: '<S95>/I_Z_rate'

  real_T Zgain_Gain_d;                 // Expression: 0.5
                                       //  Referenced by: '<S86>/Zgain'

  real_T Gain_Gain_f;                  // Expression: 180/pi
                                       //  Referenced by: '<S102>/Gain'

  real_T Gain1_Gain_i;                 // Expression: 180/pi
                                       //  Referenced by: '<S102>/Gain1'

  real_T Gain2_Gain_m;                 // Expression: 180/pi
                                       //  Referenced by: '<S102>/Gain2'

  real_T Gain3_Gain_n;                 // Expression: 1/255
                                       //  Referenced by: '<S172>/Gain3'

  real_T q_Value[4];                   // Expression: [0;0;0;1]
                                       //  Referenced by: '<S172>/q '

  real32_T Gain3_Gain_o;               // Computed Parameter: Gain3_Gain_o
                                       //  Referenced by: '<S174>/Gain3'

  real32_T Gain2_Gain_o;               // Computed Parameter: Gain2_Gain_o
                                       //  Referenced by: '<S174>/Gain2'

  real32_T Constant5_Value_p;          // Computed Parameter: Constant5_Value_p
                                       //  Referenced by: '<S89>/Constant5'

  real32_T Constant6_Value_i;          // Computed Parameter: Constant6_Value_i
                                       //  Referenced by: '<S89>/Constant6'

  real32_T Constant7_Value_c;          // Computed Parameter: Constant7_Value_c
                                       //  Referenced by: '<S89>/Constant7'

  real32_T Constant8_Value_d;          // Computed Parameter: Constant8_Value_d
                                       //  Referenced by: '<S89>/Constant8'

  real32_T Constant9_Value;            // Computed Parameter: Constant9_Value
                                       //  Referenced by: '<S89>/Constant9'

  real32_T Constant18_Value;           // Computed Parameter: Constant18_Value
                                       //  Referenced by: '<S89>/Constant18'

  real32_T Constant10_Value;           // Computed Parameter: Constant10_Value
                                       //  Referenced by: '<S89>/Constant10'

  real32_T Constant11_Value;           // Computed Parameter: Constant11_Value
                                       //  Referenced by: '<S89>/Constant11'

  real32_T Constant12_Value;           // Computed Parameter: Constant12_Value
                                       //  Referenced by: '<S89>/Constant12'

  real32_T Constant14_Value;           // Computed Parameter: Constant14_Value
                                       //  Referenced by: '<S89>/Constant14'

  uint16_T Constant4_Value_k;          // Computed Parameter: Constant4_Value_k
                                       //  Referenced by: '<S89>/Constant4'

  uint16_T Constant17_Value;           // Computed Parameter: Constant17_Value
                                       //  Referenced by: '<S89>/Constant17'

  uint16_T Constant16_Value;           // Computed Parameter: Constant16_Value
                                       //  Referenced by: '<S89>/Constant16'

  uint16_T Constant15_Value;           // Computed Parameter: Constant15_Value
                                       //  Referenced by: '<S89>/Constant15'

  uint8_T ManualSwitch2_CurrentSetting;// Computed Parameter: ManualSwitch2_CurrentSetting
                                       //  Referenced by: '<S89>/Manual Switch2'

  uint8_T ManualSwitch13_CurrentSetting;// Computed Parameter: ManualSwitch13_CurrentSetting
                                        //  Referenced by: '<S89>/Manual Switch13'

  uint8_T ManualSwitch14_CurrentSetting;// Computed Parameter: ManualSwitch14_CurrentSetting
                                        //  Referenced by: '<S89>/Manual Switch14'

  uint8_T ManualSwitch15_CurrentSetting;// Computed Parameter: ManualSwitch15_CurrentSetting
                                        //  Referenced by: '<S89>/Manual Switch15'

  boolean_T enable_PC_Value;           // Computed Parameter: enable_PC_Value
                                       //  Referenced by: '<S155>/enable_PC'

  boolean_T rollPitch_pos_rate_Value;  // Computed Parameter: rollPitch_pos_rate_Value
                                       //  Referenced by: '<S155>/rollPitch_pos_rate'

  boolean_T position_Value;            // Computed Parameter: position_Value
                                       //  Referenced by: '<S155>/position'

  boolean_T geometricControl_Value;    // Computed Parameter: geometricControl_Value
                                       //  Referenced by: '<S155>/geometricControl'

  boolean_T Constant_Value_gs;         // Computed Parameter: Constant_Value_gs
                                       //  Referenced by: '<S8>/Constant'

  boolean_T Z_pos_vel_Value;           // Computed Parameter: Z_pos_vel_Value
                                       //  Referenced by: '<S155>/Z_pos_vel'

  boolean_T XY_pos_vel_Value;          // Computed Parameter: XY_pos_vel_Value
                                       //  Referenced by: '<S155>/XY_pos_vel'

  boolean_T yaw_pos_rate_Value;        // Computed Parameter: yaw_pos_rate_Value
                                       //  Referenced by: '<S155>/yaw_pos_rate'

};

// Real-time Model Data Structure
struct tag_RTM_controlAerobi {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern Parameters_controlAerobi controlAerobi_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern BlockIO_controlAerobi controlAerobi_B;

// Block states (auto storage)
extern D_Work_controlAerobi controlAerobi_DWork;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with auto storage)
  extern ExternalInputs_controlAerobi controlAerobi_U;

  // External outputs (root outports fed by signals with auto storage)
  extern ExternalOutputs_controlAerobi controlAerobi_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void controlAerobi_initialize(void);
  extern void controlAerobi_step(void);
  extern void controlAerobi_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  // Const memory section
  extern RT_MODEL_controlAerobi *const controlAerobi_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S37>/Data Type Duplicate' : Unused code path elimination
//  Block '<S38>/Data Type Duplicate' : Unused code path elimination
//  Block '<S38>/Data Type Propagation' : Unused code path elimination
//  Block '<S41>/Data Type Duplicate' : Unused code path elimination
//  Block '<S42>/Data Type Duplicate' : Unused code path elimination
//  Block '<S42>/Data Type Propagation' : Unused code path elimination
//  Block '<S45>/Data Type Duplicate' : Unused code path elimination
//  Block '<S46>/Data Type Duplicate' : Unused code path elimination
//  Block '<S46>/Data Type Propagation' : Unused code path elimination
//  Block '<S49>/Data Type Duplicate' : Unused code path elimination
//  Block '<S50>/Data Type Duplicate' : Unused code path elimination
//  Block '<S50>/Data Type Propagation' : Unused code path elimination
//  Block '<S60>/Data Type Duplicate' : Unused code path elimination
//  Block '<S61>/Data Type Duplicate' : Unused code path elimination
//  Block '<S61>/Data Type Propagation' : Unused code path elimination
//  Block '<S64>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/Data Type Propagation' : Unused code path elimination
//  Block '<S77>/Data Type Duplicate' : Unused code path elimination
//  Block '<S78>/Data Type Duplicate' : Unused code path elimination
//  Block '<S78>/Data Type Propagation' : Unused code path elimination
//  Block '<S81>/Data Type Duplicate' : Unused code path elimination
//  Block '<S82>/Data Type Duplicate' : Unused code path elimination
//  Block '<S82>/Data Type Propagation' : Unused code path elimination
//  Block '<S93>/Data Type Duplicate' : Unused code path elimination
//  Block '<S93>/Data Type Propagation' : Unused code path elimination
//  Block '<S92>/Data Type Duplicate' : Unused code path elimination
//  Block '<S92>/Data Type Propagation' : Unused code path elimination
//  Block '<S94>/CTf' : Unused code path elimination
//  Block '<S94>/d' : Unused code path elimination
//  Block '<S158>/Constant' : Unused code path elimination
//  Block '<S158>/Constant1' : Unused code path elimination
//  Block '<S158>/Data Type Conversion4' : Unused code path elimination
//  Block '<S158>/Divide' : Unused code path elimination
//  Block '<S158>/Saturation' : Unused code path elimination
//  Block '<S158>/Sum' : Unused code path elimination
//  Block '<S155>/Logical Operator2' : Unused code path elimination
//  Block '<S155>/TAKEOFF' : Unused code path elimination
//  Block '<S156>/YAWdes' : Unused code path elimination
//  Block '<S100>/d_prism' : Unused code path elimination
//  Block '<S172>/Data Type Conversion5' : Unused code path elimination
//  Block '<S172>/Gain5' : Unused code path elimination
//  Block '<S105>/Zero-Order Hold1' : Eliminated since input and output rates are identical
//  Block '<S176>/Data4' : Eliminate redundant data type conversion
//  Block '<S171>/Zero-Order Hold2' : Eliminated since input and output rates are identical
//  Block '<S171>/Zero-Order Hold4' : Eliminated since input and output rates are identical


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'controlAerobi'
//  '<S1>'   : 'controlAerobi/Controllers'
//  '<S2>'   : 'controlAerobi/Sensors'
//  '<S3>'   : 'controlAerobi/logs'
//  '<S4>'   : 'controlAerobi/Controllers/Quadrotor_Controllers'
//  '<S5>'   : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller'
//  '<S6>'   : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers'
//  '<S7>'   : 'controlAerobi/Controllers/Quadrotor_Controllers/mixer'
//  '<S8>'   : 'controlAerobi/Controllers/Quadrotor_Controllers/switch_controllers'
//  '<S9>'   : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking'
//  '<S10>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking'
//  '<S11>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking/Generate_attitude_refereces'
//  '<S12>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking/attitude_geometric_control'
//  '<S13>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking/Generate_attitude_refereces/Calculate_rotation_matrix_des'
//  '<S14>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking/Generate_attitude_refereces/MATLAB Function'
//  '<S15>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/attitude_tracking/Generate_attitude_refereces/calculate_dOmega_d'
//  '<S16>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces'
//  '<S17>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/trajectory_tracking'
//  '<S18>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/Calculate_position_des'
//  '<S19>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/Position _desired_from_PC'
//  '<S20>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_altitude_des'
//  '<S21>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_ddx_d'
//  '<S22>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_v_d'
//  '<S23>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/Calculate_position_des/Create dXY desired'
//  '<S24>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_altitude_des/altitude_fcn'
//  '<S25>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_altitude_des/antiwind_up_dzdes'
//  '<S26>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_altitude_des/antiwind_up_zdes'
//  '<S27>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_altitude_des/antiwind_up_zdes/Clamping circuit1'
//  '<S28>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/Geometric_controller/trajectory_tracking/Generate_tracking_referecnces/calculate_altitude_des/antiwind_up_zdes/Clamping circuit1/Compare To Constant'
//  '<S29>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER'
//  '<S30>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER'
//  '<S31>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/Continuous Yaw Generator'
//  '<S32>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_drolldPitch'
//  '<S33>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_dyaw'
//  '<S34>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_rollPitch'
//  '<S35>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_yaw'
//  '<S36>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_drolldPitch/Clamping circuit1'
//  '<S37>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_drolldPitch/Discrete Derivative'
//  '<S38>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_drolldPitch/Saturation Dynamic'
//  '<S39>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_drolldPitch/Clamping circuit1/Compare To Constant'
//  '<S40>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_dyaw/Clamping circuit1'
//  '<S41>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_dyaw/Discrete Derivative'
//  '<S42>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_dyaw/Saturation Dynamic'
//  '<S43>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_dyaw/Clamping circuit1/Compare To Constant'
//  '<S44>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_rollPitch/Clamping circuit1'
//  '<S45>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_rollPitch/Discrete Derivative'
//  '<S46>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_rollPitch/Saturation Dynamic'
//  '<S47>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_rollPitch/Clamping circuit1/Compare To Constant'
//  '<S48>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_yaw/Clamping circuit1'
//  '<S49>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_yaw/Discrete Derivative'
//  '<S50>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_yaw/Saturation Dynamic'
//  '<S51>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_ATTITUDE_CONTROLLER/PID_yaw/Clamping circuit1/Compare To Constant'
//  '<S52>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller'
//  '<S53>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller'
//  '<S54>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/Create RollPitchdesired'
//  '<S55>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/Create_Pos_Hold'
//  '<S56>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_XY'
//  '<S57>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_dXY'
//  '<S58>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/create_references'
//  '<S59>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_XY/Clamping circuit1'
//  '<S60>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_XY/Discrete Derivative'
//  '<S61>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_XY/Saturation Dynamic'
//  '<S62>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_XY/Clamping circuit1/Compare To Constant'
//  '<S63>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_dXY/Clamping circuit1'
//  '<S64>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_dXY/Discrete Derivative'
//  '<S65>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_dXY/Saturation Dynamic'
//  '<S66>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/PID_dXY/Clamping circuit1/Compare To Constant'
//  '<S67>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/create_references/Create dXY desired'
//  '<S68>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/create_references/antiwind_up_xydes'
//  '<S69>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/create_references/antiwind_up_xydes/Clamping circuit1'
//  '<S70>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/create_references/antiwind_up_xydes/antiwind_up_dzdes'
//  '<S71>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/XY_controller/create_references/antiwind_up_xydes/Clamping circuit1/Compare To Constant'
//  '<S72>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs'
//  '<S73>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/calculate_altitude_des'
//  '<S74>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_Z'
//  '<S75>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_dZ'
//  '<S76>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_Z/Clamping circuit1'
//  '<S77>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_Z/Discrete Derivative'
//  '<S78>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_Z/Saturation Dynamic'
//  '<S79>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_Z/Clamping circuit1/Compare To Constant'
//  '<S80>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_dZ/Clamping circuit1'
//  '<S81>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_dZ/Discrete Derivative'
//  '<S82>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_dZ/Saturation Dynamic'
//  '<S83>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/Altitude_PIDs/PID_dZ/Clamping circuit1/Compare To Constant'
//  '<S84>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/calculate_altitude_des/altitude_fcn'
//  '<S85>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/calculate_altitude_des/antiwind_up_dzdes'
//  '<S86>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/calculate_altitude_des/antiwind_up_zdes'
//  '<S87>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/calculate_altitude_des/antiwind_up_zdes/Clamping circuit1'
//  '<S88>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/PID_cascade_controllers/PID_POSITION_CONTROLLER/Z_controller/calculate_altitude_des/antiwind_up_zdes/Clamping circuit1/Compare To Constant'
//  '<S89>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/mixer/Mux Rotor'
//  '<S90>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/mixer/Subsystem'
//  '<S91>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/mixer/saturation & Adapater signals'
//  '<S92>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/mixer/ticks_Saturation Should Never saturate'
//  '<S93>'  : 'controlAerobi/Controllers/Quadrotor_Controllers/mixer/saturation & Adapater signals/ticks_Saturation Should Never saturate1'
//  '<S94>'  : 'controlAerobi/Sensors/Geometric_Control_gains'
//  '<S95>'  : 'controlAerobi/Sensors/PID_cascade_gains'
//  '<S96>'  : 'controlAerobi/Sensors/RadioChannels'
//  '<S97>'  : 'controlAerobi/Sensors/ViewFlightMode'
//  '<S98>'  : 'controlAerobi/Sensors/attitude'
//  '<S99>'  : 'controlAerobi/Sensors/control_modes'
//  '<S100>' : 'controlAerobi/Sensors/position'
//  '<S101>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator'
//  '<S102>' : 'controlAerobi/Sensors/attitude/routing'
//  '<S103>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/Acceleration'
//  '<S104>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/AngularRates'
//  '<S105>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/DATA  ACQUISITION'
//  '<S106>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/TGIC'
//  '<S107>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib accel lsm'
//  '<S108>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib accel mpu'
//  '<S109>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib gyro lsm'
//  '<S110>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib gyro mpu'
//  '<S111>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib magnet lsm'
//  '<S112>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib magnet mpu'
//  '<S113>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib_accel_lsm'
//  '<S114>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib_gyro_lsm'
//  '<S115>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib_magnet_lsm'
//  '<S116>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/lsm9ds1'
//  '<S117>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/mpu9250'
//  '<S118>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/routing'
//  '<S119>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/DATA  ACQUISITION/Demux UAV_att, UAV_att_rate'
//  '<S120>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/DATA  ACQUISITION/PX4 + attitude '
//  '<S121>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/DATA  ACQUISITION/Demux UAV_att, UAV_att_rate/Quaternion Norm'
//  '<S122>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/DATA  ACQUISITION/Demux UAV_att, UAV_att_rate/Quaternions to  Rotation Angles'
//  '<S123>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/DATA  ACQUISITION/Demux UAV_att, UAV_att_rate/Quaternions to  Rotation Angles/Angle Calculation'
//  '<S124>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/DATA  ACQUISITION/Demux UAV_att, UAV_att_rate/Quaternions to  Rotation Angles/Quaternion Normalize'
//  '<S125>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/DATA  ACQUISITION/Demux UAV_att, UAV_att_rate/Quaternions to  Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S126>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/DATA  ACQUISITION/Demux UAV_att, UAV_att_rate/Quaternions to  Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S127>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/TGIC/FCF'
//  '<S128>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/TGIC/Quaternions to Rotation Angles1'
//  '<S129>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/TGIC/TGIC_fcn'
//  '<S130>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/TGIC/FCF/FCF_fcn'
//  '<S131>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/TGIC/Quaternions to Rotation Angles1/Angle Calculation'
//  '<S132>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/TGIC/Quaternions to Rotation Angles1/Quaternion Normalize'
//  '<S133>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/TGIC/Quaternions to Rotation Angles1/Quaternion Normalize/Quaternion Modulus'
//  '<S134>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/TGIC/Quaternions to Rotation Angles1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S135>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib gyro lsm/MATLAB Function'
//  '<S136>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib gyro mpu/MATLAB Function'
//  '<S137>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib magnet lsm/Security IsNaN2'
//  '<S138>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib_gyro_lsm/MATLAB Function'
//  '<S139>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/calib_magnet_lsm/Security IsNaN2'
//  '<S140>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/lsm9ds1/Mahoney_estimator'
//  '<S141>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/lsm9ds1/Mahoney_estimator/Embedded MATLAB Function1'
//  '<S142>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/lsm9ds1/Mahoney_estimator/Quaternions to Rotation Angles'
//  '<S143>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/lsm9ds1/Mahoney_estimator/Quaternions to Rotation Angles/Angle Calculation'
//  '<S144>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/lsm9ds1/Mahoney_estimator/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S145>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/lsm9ds1/Mahoney_estimator/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S146>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/lsm9ds1/Mahoney_estimator/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S147>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/mpu9250/Mahoney_estimator'
//  '<S148>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/mpu9250/Security IsNaN2'
//  '<S149>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/mpu9250/Mahoney_estimator/Embedded MATLAB Function1'
//  '<S150>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/mpu9250/Mahoney_estimator/Quaternions to Rotation Angles'
//  '<S151>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/mpu9250/Mahoney_estimator/Quaternions to Rotation Angles/Angle Calculation'
//  '<S152>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/mpu9250/Mahoney_estimator/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S153>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/mpu9250/Mahoney_estimator/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S154>' : 'controlAerobi/Sensors/attitude/AttitudeEstimator/mpu9250/Mahoney_estimator/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S155>' : 'controlAerobi/Sensors/control_modes/ModeBlock'
//  '<S156>' : 'controlAerobi/Sensors/control_modes/PositionDesired'
//  '<S157>' : 'controlAerobi/Sensors/control_modes/Signals_to_references'
//  '<S158>' : 'controlAerobi/Sensors/control_modes/ModeBlock/AdjustControlGain'
//  '<S159>' : 'controlAerobi/Sensors/control_modes/ModeBlock/Compare To Constant1'
//  '<S160>' : 'controlAerobi/Sensors/control_modes/ModeBlock/Compare To Constant2'
//  '<S161>' : 'controlAerobi/Sensors/control_modes/ModeBlock/Compare To Constant3'
//  '<S162>' : 'controlAerobi/Sensors/control_modes/ModeBlock/Compare To Constant4'
//  '<S163>' : 'controlAerobi/Sensors/control_modes/ModeBlock/enable pos'
//  '<S164>' : 'controlAerobi/Sensors/control_modes/Signals_to_references/Dead band_pitch'
//  '<S165>' : 'controlAerobi/Sensors/control_modes/Signals_to_references/Dead band_roll'
//  '<S166>' : 'controlAerobi/Sensors/control_modes/Signals_to_references/Dead band_yaw'
//  '<S167>' : 'controlAerobi/Sensors/control_modes/Signals_to_references/Dead band_pitch/Compare To Constant'
//  '<S168>' : 'controlAerobi/Sensors/control_modes/Signals_to_references/Dead band_roll/Compare To Constant'
//  '<S169>' : 'controlAerobi/Sensors/control_modes/Signals_to_references/Dead band_yaw/Compare To Constant'
//  '<S170>' : 'controlAerobi/Sensors/position/EKF_total_Station_Lidar'
//  '<S171>' : 'controlAerobi/Sensors/position/GPS_px4'
//  '<S172>' : 'controlAerobi/Sensors/position/px4fow'
//  '<S173>' : 'controlAerobi/Sensors/position/selector'
//  '<S174>' : 'controlAerobi/Sensors/position/EKF_total_Station_Lidar/enu//ned'
//  '<S175>' : 'controlAerobi/Sensors/position/EKF_total_Station_Lidar/filter'
//  '<S176>' : 'controlAerobi/Sensors/position/EKF_total_Station_Lidar/routingData'
//  '<S177>' : 'controlAerobi/Sensors/position/EKF_total_Station_Lidar/filter/EKF2_XYZ'
//  '<S178>' : 'controlAerobi/Sensors/position/EKF_total_Station_Lidar/filter/EKF_dXYZ'
//  '<S179>' : 'controlAerobi/Sensors/position/EKF_total_Station_Lidar/filter/Liner Fixed-gain Filter'
//  '<S180>' : 'controlAerobi/Sensors/position/EKF_total_Station_Lidar/filter/buffer'
//  '<S181>' : 'controlAerobi/Sensors/position/GPS_px4/NED estimation'
//  '<S182>' : 'controlAerobi/Sensors/position/px4fow/Liner Fixed-gain Filter1'
//  '<S183>' : 'controlAerobi/Sensors/position/px4fow/MATLAB Function'
//  '<S184>' : 'controlAerobi/Sensors/position/px4fow/MATLAB Function1'

#endif                                 // RTW_HEADER_controlAerobi_h_

//
// File trailer for generated code.
//
// [EOF]
//
