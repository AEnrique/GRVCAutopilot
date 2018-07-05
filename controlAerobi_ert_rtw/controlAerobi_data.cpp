//
// File: controlAerobi_data.cpp
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

// Block parameters (auto storage)
Parameters_controlAerobi controlAerobi_P = {
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S77>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_m
  //  Referenced by: '<S81>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_k
  //  Referenced by: '<S60>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_e
  //  Referenced by: '<S64>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_d
  //  Referenced by: '<S45>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevSca_da
  //  Referenced by: '<S37>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_a
  //  Referenced by: '<S49>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevSca_kf
  //  Referenced by: '<S41>/UD'

  0.0,

  // Mask Parameter: logs_SelectPlot1
  //  Referenced by: '<S3>/SelectPlot1'

  2.0,

  // Mask Parameter: logs_SelectPlot2
  //  Referenced by: '<S3>/SelectPlot2'

  7.0,

  // Mask Parameter: logs_SelectPlot3
  //  Referenced by: '<S3>/SelectPlot3'

  1.0,

  // Mask Parameter: logs_SelectPlot4
  //  Referenced by: '<S3>/SelectPlot4'

  8.0,

  // Mask Parameter: CompareToConstant1_const
  //  Referenced by: '<S159>/Constant'

  1200.0,

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: '<S160>/Constant'

  1200.0,

  // Mask Parameter: CompareToConstant3_const
  //  Referenced by: '<S161>/Constant'

  1800.0,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S168>/Constant'

  0.01,

  // Mask Parameter: CompareToConstant_const_c
  //  Referenced by: '<S167>/Constant'

  0.01,

  // Mask Parameter: CompareToConstant_const_d
  //  Referenced by: '<S169>/Constant'

  0.01,

  // Mask Parameter: CompareToConstant4_const
  //  Referenced by: '<S162>/Constant'

  1200.0,

  // Mask Parameter: CompareToConstant_const_h
  //  Referenced by: '<S28>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_h5
  //  Referenced by: '<S39>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_p
  //  Referenced by: '<S43>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_l
  //  Referenced by: '<S47>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_b
  //  Referenced by: '<S51>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_m
  //  Referenced by: '<S62>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_e
  //  Referenced by: '<S66>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_i
  //  Referenced by: '<S71>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_hw
  //  Referenced by: '<S79>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_g
  //  Referenced by: '<S83>/Constant'

  1.0E-10,

  // Mask Parameter: CompareToConstant_const_bo
  //  Referenced by: '<S88>/Constant'

  1.0E-10,

  // Mask Parameter: PX4receive_localPort
  //  Referenced by: '<S120>/PX4 receive'

  8082,

  // Mask Parameter: Localpositionreceive_localPort
  //  Referenced by: '<S181>/Local position receive'

  8083,

  // Expression: [0;0;0;0]
  //  Referenced by: '<S5>/Reset'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: inf
  //  Referenced by: '<S20>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S20>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S156>/Xdes'

  0.0,

  // Expression: 0
  //  Referenced by: '<S156>/Ydes'

  0.0,

  // Expression: 0
  //  Referenced by: '<S18>/zero'

  0.0,

  // Expression: 3
  //  Referenced by: '<S18>/Saturation1'

  3.0,

  // Expression: -3
  //  Referenced by: '<S18>/Saturation1'

  -3.0,

  // Expression: 0
  //  Referenced by: '<S26>/Constant'

  0.0,

  // Expression: 0.20
  //  Referenced by: '<S52>/Saturation2'

  0.2,

  // Expression: -0.20
  //  Referenced by: '<S52>/Saturation2'

  -0.2,

  // Expression: 12
  //  Referenced by: '<S29>/Gain'

  12.0,

  // Expression: 7
  //  Referenced by: '<S29>/Gain1'

  7.0,

  // Expression: 0
  //  Referenced by: '<S32>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant1'

  0.0,

  // Expression: 20
  //  Referenced by: '<S95>/I_Yaw_rate'

  20.0,

  // Expression: -Inf
  //  Referenced by: '<S95>/SatNeg_Yaw_rate'

  0.0,

  // Expression: 0
  //  Referenced by: '<S34>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S35>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S35>/Constant'

  0.0,

  // Expression: -Inf
  //  Referenced by: '<S95>/SatNeg_Yaw_pos'

  0.0,

  // Expression: 0
  //  Referenced by: '<S56>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S57>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S58>/zero'

  0.0,

  // Expression: -2
  //  Referenced by: '<S95>/SatNeg_Z_pos'

  -2.0,

  // Expression: -Inf
  //  Referenced by: '<S95>/SatNeg_Z_rate'

  0.0,

  // Expression: inf
  //  Referenced by: '<S73>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S73>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S86>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S90>/Constant2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S90>/Constant1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S91>/Constant2'

  0.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S117>/offset'

  { 0.0, 0.0, 0.0 },

  // Expression: pi/180
  //  Referenced by: '<S117>/Gain'

  0.017453292519943295,

  // Expression: [0 0 0 1]
  //  Referenced by: '<S119>/Constant'

  { 0.0, 0.0, 0.0, 1.0 },

  // Expression: 0
  //  Referenced by: '<S164>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S165>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S166>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<S173>/Gain1'

  1.0,

  // Expression: 1
  //  Referenced by: '<S173>/Gain'

  1.0,

  // Expression: 0
  //  Referenced by: '<S173>/select_xy_px1'

  0.0,

  // Expression: 2
  //  Referenced by: '<S173>/select_xy_px4'

  2.0,

  // Expression: 2
  //  Referenced by: '<S173>/selector_xy_ekf'

  2.0,

  // Expression: 2000
  //  Referenced by: '<S7>/Constant'

  2000.0,

  // Expression: inf
  //  Referenced by: '<S91>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S101>/select'

  1.0,

  // Expression: 0
  //  Referenced by: '<S119>/Switch'

  0.0,

  // Expression: [0 0 1;0 1 0;1 0 0]
  //  Referenced by: '<S119>/Rotation Angles  correction'

  { 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  // Expression: [1 0 0;0 1 0;0 0 -1]
  //  Referenced by: '<S110>/M gyro'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, -1.0 },

  // Expression:  [-0.039 0.0047 0.00025]
  //  Referenced by: '<S110>/Bias gyro'

  { -0.039, 0.0047, 0.00025 },

  // Expression: 1
  //  Referenced by: '<S110>/reset'

  1.0,

  // Expression: [0.102062997425644 -0.000360608360630755 0.000399354774698161;0 0.101817729774635 0.000576698824955731;0 0 0.100789866244925]
  //  Referenced by: '<S108>/M accel'

  { 0.102062997425644, 0.0, 0.0, -0.000360608360630755, 0.101817729774635, 0.0,
    0.000399354774698161, 0.000576698824955731, 0.100789866244925 },

  // Expression: [-0.0492144423708621;0.144627115284475;-0.758694194437572]
  //  Referenced by: '<S108>/Bias accel'

  { -0.0492144423708621, 0.144627115284475, -0.758694194437572 },

  // Expression: [0.5879;0.0081;0.8091]
  //  Referenced by: '<S148>/Constant'

  { 0.5879, 0.0081, 0.8091 },

  // Expression: [0.0253755958616719 -0.000792704952881109 -0.00238411920606669;0 0.0239968575813526 0.000823311977129874;0 0 0.0238779704051099]
  //  Referenced by: '<S112>/M magnet'

  { 0.0253755958616719, 0.0, 0.0, -0.000792704952881109, 0.0239968575813526, 0.0,
    -0.00238411920606669, 0.000823311977129874, 0.0238779704051099 },

  // Expression: [-9.15447404913273;21.2106327279048;-2.87719515232140]
  //  Referenced by: '<S112>/Bias magnet'

  { -9.15447404913273, 21.2106327279048, -2.8771951523214 },

  // Expression: 50
  //  Referenced by: '<S117>/kb'

  50.0,

  // Expression: 1
  //  Referenced by: '<S117>/k1'

  1.0,

  // Expression: 0.8
  //  Referenced by: '<S117>/k2'

  0.8,

  // Expression: 0.25
  //  Referenced by: '<S117>/k3'

  0.25,

  // Expression: 0.05
  //  Referenced by: '<S117>/k4'

  0.05,

  // Expression: 0.03
  //  Referenced by: '<S117>/limit'

  0.03,

  // Expression: [1 0 0;0 1 0;0 0 -1]
  //  Referenced by: '<S109>/M gyro'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, -1.0 },

  // Expression: [0 0 0]
  //  Referenced by: '<S109>/Bias gyro'

  { 0.0, 0.0, 0.0 },

  // Expression: [0.102461992116242 -0.000598491957672618 0.000398970370700955;0 0.102027597979423 7.50526054392845e-05;0 0 0.101558166766067]
  //  Referenced by: '<S107>/M accel'

  { 0.102461992116242, 0.0, 0.0, -0.000598491957672618, 0.102027597979423, 0.0,
    0.000398970370700955, 7.50526054392845E-5, 0.101558166766067 },

  // Expression: [0.0758571454418519;0.0424696823519786;-0.321384803687075]
  //  Referenced by: '<S107>/Bias accel'

  { 0.0758571454418519, 0.0424696823519786, -0.321384803687075 },

  // Computed Parameter: RateLimiter1_RisingLim
  //  Referenced by: '<S107>/Rate Limiter1'

  0.025,

  // Computed Parameter: RateLimiter1_FallingLim
  //  Referenced by: '<S107>/Rate Limiter1'

  -0.025,

  // Expression: 0
  //  Referenced by: '<S107>/Rate Limiter1'

  0.0,

  // Expression: [0.5879;0.0081;0.8091]
  //  Referenced by: '<S137>/Constant'

  { 0.5879, 0.0081, 0.8091 },

  // Expression: [0.0245576523410537 -0.00273259684033348 -0.00278802564696040;0 0.0254002563813822 -0.00118636240410959;0 0 -0.0239663665345273]
  //  Referenced by: '<S111>/M magnet'

  { 0.0245576523410537, 0.0, 0.0, -0.00273259684033348, 0.0254002563813822, 0.0,
    -0.0027880256469604, -0.00118636240410959, -0.0239663665345273 },

  // Expression: [17.0874271396470;17.12515209882385;38.7277179953262]
  //  Referenced by: '<S111>/Bias magnet'

  { 17.087427139647, 17.12515209882385, 38.7277179953262 },

  // Computed Parameter: RateLimiter1_RisingLim_p
  //  Referenced by: '<S111>/Rate Limiter1'

  0.025,

  // Computed Parameter: RateLimiter1_FallingLim_l
  //  Referenced by: '<S111>/Rate Limiter1'

  -0.025,

  // Expression: 0
  //  Referenced by: '<S111>/Rate Limiter1'

  0.0,

  // Expression: 16
  //  Referenced by: '<S116>/kb'

  16.0,

  // Expression: 1
  //  Referenced by: '<S116>/k1'

  1.0,

  // Expression: 0.8
  //  Referenced by: '<S116>/k2'

  0.8,

  // Expression: 0.25
  //  Referenced by: '<S116>/k3'

  0.25,

  // Expression: 0.05
  //  Referenced by: '<S116>/k4'

  0.05,

  // Expression: 0.03
  //  Referenced by: '<S116>/limit'

  0.03,

  // Expression: 100
  //  Referenced by: '<S140>/Constant'

  100.0,

  // Expression: [0;0;0]
  //  Referenced by: '<S116>/offset'

  { 0.0, 0.0, 0.0 },

  // Expression: pi/180
  //  Referenced by: '<S116>/Gain'

  0.017453292519943295,

  // Expression: [1.001169204711914062,0,0;0,1.003445267677307129,0;0,0,1.001209974288940430]
  //  Referenced by: '<S113>/M_accel'

  { 1.0011692047119141, 0.0, 0.0, 0.0, 1.0034452676773071, 0.0, 0.0, 0.0,
    1.0012099742889404 },

  // Computed Parameter: RateLimiter_RisingLim
  //  Referenced by: '<S113>/Rate Limiter'

  0.025,

  // Computed Parameter: RateLimiter_FallingLim
  //  Referenced by: '<S113>/Rate Limiter'

  -0.025,

  // Expression: 0
  //  Referenced by: '<S113>/Rate Limiter'

  0.0,

  // Expression: [-0.008039474487304688;-0.078669071197509766;0.213560581207275391]
  //  Referenced by: '<S113>/Bias_accel'

  { -0.0080394744873046875, -0.078669071197509766, 0.21356058120727539 },

  // Expression: [1.000000000000000000,0,0;0,1.000000000000000000,0;0,0,-1.000000000000000000]
  //  Referenced by: '<S114>/M_gyro'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, -1.0 },

  // Expression: [-0.113444186747074127;-0.091068968176841736;-0.060674510896205902]
  //  Referenced by: '<S114>/Bias_gyro'

  { -0.11344418674707413, -0.091068968176841736, -0.0606745108962059 },

  // Expression: [0.962506949901580811,0,0;0,0.992451548576354980,0;0,0,1.044171094894409180]
  //  Referenced by: '<S115>/M_magnet'

  { 0.96250694990158081, 0.0, 0.0, 0.0, 0.992451548576355, 0.0, 0.0, 0.0,
    1.0441710948944092 },

  // Expression: [0.5879;0.0081;0.8091]
  //  Referenced by: '<S139>/Constant'

  { 0.5879, 0.0081, 0.8091 },

  // Computed Parameter: RateLimiter1_RisingLim_n
  //  Referenced by: '<S115>/Rate Limiter1'

  0.025,

  // Computed Parameter: RateLimiter1_FallingLim_i
  //  Referenced by: '<S115>/Rate Limiter1'

  -0.025,

  // Expression: 0
  //  Referenced by: '<S115>/Rate Limiter1'

  0.0,

  // Expression: 1/100
  //  Referenced by: '<S115>/Gain'

  0.01,

  // Expression: [0.211622878909111023;0.140778407454490662;0.142240136861801147]
  //  Referenced by: '<S115>/Bias_magnet'

  { 0.21162287890911102, 0.14077840745449066, 0.14224013686180115 },

  // Expression: 0.9
  //  Referenced by: '<S106>/mu_a'

  0.9,

  // Expression: 0.9
  //  Referenced by: '<S106>/mu_m'

  0.9,

  // Expression: [0.4;0.4;0.4;0.1;0.1;0.1]
  //  Referenced by: '<S106>/rk'

  { 0.4, 0.4, 0.4, 0.1, 0.1, 0.1 },

  // Expression: [0.25*(0.0025^2)*0.5;0.25*(0.0025^2)*0.5;0.25*(0.0025^2)*0.5;0.25*(0.0025^2)*0.5;0.025;0.025;0.025;0.0025;0.0025;0.0025]
  //  Referenced by: '<S106>/qk'

  { 7.8125E-7, 7.8125E-7, 7.8125E-7, 7.8125E-7, 0.025, 0.025, 0.025, 0.0025,
    0.0025, 0.0025 },

  // Expression: 1.2
  //  Referenced by: '<S106>/mu'

  1.2,

  // Expression: 0
  //  Referenced by: '<S106>/chi'

  0.0,

  // Expression: 0.0001
  //  Referenced by: '<S106>/p0'

  0.0001,

  // Expression: 100
  //  Referenced by: '<S106>/distorsion_max'

  100.0,

  // Expression: 0.005
  //  Referenced by: '<S127>/ym'

  0.005,

  // Expression: 0.005
  //  Referenced by: '<S127>/ya'

  0.005,

  // Expression: 0.9
  //  Referenced by: '<S127>/weight'

  0.9,

  // Expression: 10
  //  Referenced by: '<S127>/distorsion_max'

  10.0,

  // Expression: 100
  //  Referenced by: '<S106>/er'

  100.0,

  // Expression: 1
  //  Referenced by: '<S174>/NED//ENU'

  1.0,

  // Expression: 1/1927
  //  Referenced by: '<S157>/Gain2'

  0.0005189413596263622,

  // Expression: 1
  //  Referenced by: '<S157>/Constant4'

  1.0,

  // Expression: -275
  //  Referenced by: '<S157>/Constant5'

  -275.0,

  // Computed Parameter: RateLimiter_RisingLim_g
  //  Referenced by: '<S175>/Rate Limiter'

  0.0125,

  // Computed Parameter: RateLimiter_FallingLim_k
  //  Referenced by: '<S175>/Rate Limiter'

  -0.0125,

  // Expression: 0
  //  Referenced by: '<S175>/Rate Limiter'

  0.0,

  // Computed Parameter: RateLimiter1_RisingLim_i
  //  Referenced by: '<S175>/Rate Limiter1'

  0.0125,

  // Computed Parameter: RateLimiter1_FallingLim_o
  //  Referenced by: '<S175>/Rate Limiter1'

  -0.0125,

  // Expression: 0
  //  Referenced by: '<S175>/Rate Limiter1'

  0.0,

  // Computed Parameter: RateLimiter2_RisingLim
  //  Referenced by: '<S175>/Rate Limiter2'

  0.0125,

  // Computed Parameter: RateLimiter2_FallingLim
  //  Referenced by: '<S175>/Rate Limiter2'

  -0.0125,

  // Expression: 0
  //  Referenced by: '<S175>/Rate Limiter2'

  0.0,

  // Computed Parameter: RateLimiter3_RisingLim
  //  Referenced by: '<S175>/Rate Limiter3'

  0.0125,

  // Computed Parameter: RateLimiter3_FallingLim
  //  Referenced by: '<S175>/Rate Limiter3'

  -0.0125,

  // Expression: 0
  //  Referenced by: '<S175>/Rate Limiter3'

  0.0,

  // Expression: 0.048
  //  Referenced by: '<S100>/d_sf11'

  0.048,

  // Expression: [ 0 0.005  0 0.005  0 0.0025]
  //  Referenced by: '<S100>/KQ'

  { 0.0, 0.005, 0.0, 0.005, 0.0, 0.0025 },

  // Expression: [0.01 0.1 0.01 0.1 0.05]
  //  Referenced by: '<S100>/KR'

  { 0.01, 0.1, 0.01, 0.1, 0.05 },

  // Expression: 2
  //  Referenced by: '<S173>/selector_z'

  2.0,

  // Expression: 0.001
  //  Referenced by: '<S172>/Gain1'

  0.001,

  // Expression: 0.001
  //  Referenced by: '<S172>/Gain'

  0.001,

  // Expression: 1
  //  Referenced by: '<S172>/Gain2'

  1.0,

  // Expression: 0
  //  Referenced by: '<S172>/Gain4'

  0.0,

  // Expression: 1
  //  Referenced by: '<S156>/Zdes'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S18>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S18>/Discrete-Time Integrator'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_i
  //  Referenced by: '<S26>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S26>/Discrete-Time Integrator'

  0.0,

  // Expression: inf
  //  Referenced by: '<S26>/Saturation'

  0.0,

  // Expression: -inf
  //  Referenced by: '<S26>/Saturation'

  0.0,

  // Expression: 1
  //  Referenced by: '<S16>/Gain2'

  1.0,

  // Expression: 1
  //  Referenced by: '<S16>/Gain1'

  1.0,

  // Expression: [1;0;0]
  //  Referenced by: '<S16>/b1'

  { 1.0, 0.0, 0.0 },

  // Expression: 0.6
  //  Referenced by: '<S16>/Gain'

  0.6,

  // Expression: [10; 10; 10]
  //  Referenced by: '<S94>/k_x'

  { 10.0, 10.0, 10.0 },

  // Expression: [10; 10; 10]
  //  Referenced by: '<S94>/k_v'

  { 10.0, 10.0, 10.0 },

  // Expression: [0; 0; 0]
  //  Referenced by: '<S94>/k_i'

  { 0.0, 0.0, 0.0 },

  // Expression: [0.8; 0.8; 0.8]
  //  Referenced by: '<S94>/c1'

  { 0.8, 0.8, 0.8 },

  // Expression: [inf; inf; inf]
  //  Referenced by: '<S94>/sat_P'

  { 0.0, 0.0, 0.0 },

  // Expression: 1.97
  //  Referenced by: '<S94>/Mass'

  1.97,

  // Expression: 0
  //  Referenced by: '<S9>/Gain'

  0.0,

  // Expression: 0
  //  Referenced by: '<S104>/Hlp'

  0.0,

  // Expression: [-0.018169813976955839 0.0058137717737195456 0.058455939914966247 0.13944761285026877 0.2150131411793364 0.24597811695967281 0.2150131411793364 0.13944761285026877 0.058455939914966247 0.0058137717737195456 -0.018169813976955839]
  //  Referenced by: '<S104>/Hlp'

  { -0.018169813976955839, 0.0058137717737195456, 0.058455939914966247,
    0.13944761285026877, 0.2150131411793364, 0.24597811695967281,
    0.2150131411793364, 0.13944761285026877, 0.058455939914966247,
    0.0058137717737195456, -0.018169813976955839 },

  // Expression: 1/1514
  //  Referenced by: '<S157>/Gain'

  0.00066050198150594452,

  // Expression: 1
  //  Referenced by: '<S157>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S157>/Constant1'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<S157>/Saturation2'

  0.5,

  // Expression: -0.5
  //  Referenced by: '<S157>/Saturation2'

  -0.5,

  // Expression: 1.5
  //  Referenced by: '<S11>/Gain4'

  1.5,

  // Expression: 1/1518
  //  Referenced by: '<S157>/Gain1'

  0.00065876152832674575,

  // Expression: 1
  //  Referenced by: '<S157>/Constant2'

  1.0,

  // Expression: 1
  //  Referenced by: '<S157>/Gain4'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<S157>/Saturation1'

  0.5,

  // Expression: -0.5
  //  Referenced by: '<S157>/Saturation1'

  -0.5,

  // Expression: 1.5
  //  Referenced by: '<S11>/Gain3'

  1.5,

  // Expression: 1/1515
  //  Referenced by: '<S157>/Gain3'

  0.00066006600660066007,

  // Expression: 1
  //  Referenced by: '<S157>/Constant6'

  1.0,

  // Expression: 1
  //  Referenced by: '<S157>/Constant7'

  1.0,

  // Expression: 1
  //  Referenced by: '<S157>/Gain5'

  1.0,

  // Expression: 0
  //  Referenced by: '<S11>/Gain1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S11>/Gain2'

  1.0,

  // Expression: 1
  //  Referenced by: '<S11>/Gain'

  1.0,

  // Expression: [0.08 0 0; 0 0.08 0; 0 0 0.14]
  //  Referenced by: '<S94>/J'

  { 0.08, 0.0, 0.0, 0.0, 0.08, 0.0, 0.0, 0.0, 0.14 },

  // Expression: [60; 60; 60]
  //  Referenced by: '<S94>/k_R'

  { 60.0, 60.0, 60.0 },

  // Expression: [8; 8; 8]
  //  Referenced by: '<S94>/k_Omega'

  { 8.0, 8.0, 8.0 },

  // Expression: [55; 55; 55]
  //  Referenced by: '<S94>/k_I'

  { 55.0, 55.0, 55.0 },

  // Expression: [3; 3; 3]
  //  Referenced by: '<S94>/c2'

  { 3.0, 3.0, 3.0 },

  // Expression: [inf; inf; inf]
  //  Referenced by: '<S94>/sat_R'

  { 0.0, 0.0, 0.0 },

  // Expression: [0;0;0]
  //  Referenced by: '<S9>/drift'

  { 0.0, 0.0, 0.0 },

  // Expression: Inf
  //  Referenced by: '<S95>/SatPos_Z_rate'

  0.0,

  // Expression: 9
  //  Referenced by: '<S95>/P_Z_rate'

  9.0,

  // Expression: 2
  //  Referenced by: '<S95>/SatPos_Z_pos'

  2.0,

  // Expression: 1
  //  Referenced by: '<S95>/P_Z_pos'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_a
  //  Referenced by: '<S86>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S86>/Discrete-Time Integrator'

  0.0,

  // Expression: inf
  //  Referenced by: '<S86>/Saturation'

  0.0,

  // Expression: -inf
  //  Referenced by: '<S86>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S74>/Constant'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_e
  //  Referenced by: '<S74>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S74>/Discrete-Time Integrator'

  0.0,

  // Expression: 0.02
  //  Referenced by: '<S95>/D_Z_pos'

  0.02,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S77>/TSamp'

  400.0,

  // Expression: 52.23
  //  Referenced by: '<S73>/med_thrust'

  52.23,

  // Expression: 0.01
  //  Referenced by: '<S85>/adapt_thrust'

  0.01,

  // Expression: [-3:0.01:3]
  //  Referenced by: '<S85>/1-D Lookup Table'

  { -3.0, -2.99, -2.98, -2.97, -2.96, -2.95, -2.94, -2.93, -2.92, -2.91, -2.9,
    -2.89, -2.88, -2.87, -2.86, -2.85, -2.84, -2.83, -2.82, -2.81, -2.8, -2.79,
    -2.78, -2.77, -2.76, -2.75, -2.74, -2.73, -2.7199999999999998, -2.71, -2.7,
    -2.69, -2.68, -2.67, -2.66, -2.65, -2.64, -2.63, -2.62, -2.61, -2.6, -2.59,
    -2.58, -2.57, -2.56, -2.55, -2.54, -2.53, -2.52, -2.51, -2.5, -2.49, -2.48,
    -2.4699999999999998, -2.46, -2.45, -2.44, -2.4299999999999997, -2.42, -2.41,
    -2.4, -2.39, -2.38, -2.37, -2.36, -2.35, -2.34, -2.33, -2.32, -2.31, -2.3,
    -2.29, -2.2800000000000002, -2.27, -2.26, -2.25, -2.24, -2.23,
    -2.2199999999999998, -2.21, -2.2, -2.19, -2.1799999999999997, -2.17, -2.16,
    -2.15, -2.14, -2.13, -2.12, -2.11, -2.1, -2.09, -2.08, -2.07, -2.06, -2.05,
    -2.04, -2.0300000000000002, -2.02, -2.01, -2.0, -1.99, -1.98, -1.97, -1.96,
    -1.95, -1.94, -1.93, -1.92, -1.91, -1.9, -1.89, -1.88, -1.8699999999999999,
    -1.8599999999999999, -1.8499999999999999, -1.84, -1.83, -1.82, -1.81, -1.8,
    -1.79, -1.78, -1.77, -1.76, -1.75, -1.74, -1.73, -1.72, -1.71, -1.7, -1.69,
    -1.68, -1.67, -1.66, -1.65, -1.64, -1.63, -1.6199999999999999,
    -1.6099999999999999, -1.5999999999999999, -1.59, -1.58, -1.57, -1.56, -1.55,
    -1.54, -1.53, -1.52, -1.51, -1.5, -1.49, -1.48, -1.47, -1.46, -1.45, -1.44,
    -1.43, -1.42, -1.41, -1.4, -1.39, -1.38, -1.3699999999999999,
    -1.3599999999999999, -1.3499999999999999, -1.3399999999999999, -1.33, -1.32,
    -1.31, -1.3, -1.29, -1.28, -1.27, -1.26, -1.25, -1.24, -1.23, -1.22, -1.21,
    -1.2, -1.19, -1.18, -1.17, -1.16, -1.15, -1.14, -1.13, -1.1199999999999999,
    -1.1099999999999999, -1.0999999999999999, -1.0899999999999999, -1.08, -1.07,
    -1.06, -1.05, -1.04, -1.03, -1.02, -1.01, -1.0, -0.98999999999999977, -0.98,
    -0.96999999999999975, -0.96, -0.95000000000000018, -0.94,
    -0.93000000000000016, -0.91999999999999993, -0.91000000000000014,
    -0.89999999999999991, -0.89000000000000012, -0.87999999999999989,
    -0.87000000000000011, -0.85999999999999988, -0.85000000000000009,
    -0.83999999999999986, -0.83000000000000007, -0.81999999999999984, -0.81,
    -0.79999999999999982, -0.79, -0.7799999999999998, -0.77,
    -0.75999999999999979, -0.75, -0.73999999999999977, -0.73,
    -0.71999999999999975, -0.71, -0.69999999999999973, -0.69,
    -0.68000000000000016, -0.66999999999999993, -0.66000000000000014,
    -0.64999999999999991, -0.64000000000000012, -0.62999999999999989,
    -0.62000000000000011, -0.60999999999999988, -0.60000000000000009,
    -0.58999999999999986, -0.58000000000000007, -0.56999999999999984, -0.56,
    -0.54999999999999982, -0.54, -0.5299999999999998, -0.52,
    -0.50999999999999979, -0.5, -0.48999999999999977, -0.48,
    -0.46999999999999975, -0.45999999999999996, -0.44999999999999973,
    -0.43999999999999995, -0.43000000000000016, -0.41999999999999993,
    -0.41000000000000014, -0.39999999999999991, -0.39000000000000012,
    -0.37999999999999989, -0.37000000000000011, -0.35999999999999988,
    -0.35000000000000009, -0.33999999999999986, -0.33000000000000007,
    -0.31999999999999984, -0.31000000000000005, -0.29999999999999982,
    -0.29000000000000004, -0.2799999999999998, -0.27, -0.25999999999999979,
    -0.25, -0.23999999999999977, -0.22999999999999998, -0.21999999999999975,
    -0.20999999999999996, -0.19999999999999973, -0.18999999999999995,
    -0.18000000000000016, -0.16999999999999993, -0.16000000000000014,
    -0.14999999999999991, -0.14000000000000012, -0.12999999999999989,
    -0.12000000000000011, -0.10999999999999988, -0.10000000000000009,
    -0.089999999999999858, -0.080000000000000071, -0.06999999999999984,
    -0.060000000000000053, -0.049999999999999822, -0.040000000000000036,
    -0.029999999999999805, -0.020000000000000018, -0.0099999999999997868, 0.0,
    0.0099999999999997868, 0.020000000000000018, 0.029999999999999805,
    0.040000000000000036, 0.049999999999999822, 0.060000000000000053,
    0.06999999999999984, 0.080000000000000071, 0.089999999999999858,
    0.10000000000000009, 0.10999999999999988, 0.12000000000000011,
    0.12999999999999989, 0.14000000000000012, 0.14999999999999991,
    0.16000000000000014, 0.16999999999999993, 0.18000000000000016,
    0.18999999999999995, 0.19999999999999973, 0.20999999999999996,
    0.21999999999999975, 0.22999999999999998, 0.23999999999999977, 0.25,
    0.25999999999999979, 0.27, 0.2799999999999998, 0.29000000000000004,
    0.29999999999999982, 0.31000000000000005, 0.31999999999999984,
    0.33000000000000007, 0.33999999999999986, 0.35000000000000009,
    0.35999999999999988, 0.37000000000000011, 0.37999999999999989,
    0.39000000000000012, 0.39999999999999991, 0.41000000000000014,
    0.41999999999999993, 0.43000000000000016, 0.43999999999999995,
    0.44999999999999973, 0.45999999999999996, 0.46999999999999975, 0.48,
    0.48999999999999977, 0.5, 0.50999999999999979, 0.52, 0.5299999999999998,
    0.54, 0.54999999999999982, 0.56, 0.56999999999999984, 0.58000000000000007,
    0.58999999999999986, 0.60000000000000009, 0.60999999999999988,
    0.62000000000000011, 0.62999999999999989, 0.64000000000000012,
    0.64999999999999991, 0.66000000000000014, 0.66999999999999993,
    0.68000000000000016, 0.69, 0.69999999999999973, 0.71, 0.71999999999999975,
    0.73, 0.73999999999999977, 0.75, 0.75999999999999979, 0.77,
    0.7799999999999998, 0.79, 0.79999999999999982, 0.81, 0.81999999999999984,
    0.83000000000000007, 0.83999999999999986, 0.85000000000000009,
    0.85999999999999988, 0.87000000000000011, 0.87999999999999989,
    0.89000000000000012, 0.89999999999999991, 0.91000000000000014,
    0.91999999999999993, 0.93000000000000016, 0.94, 0.95000000000000018, 0.96,
    0.96999999999999975, 0.98, 0.98999999999999977, 1.0, 1.01, 1.02, 1.03, 1.04,
    1.05, 1.06, 1.07, 1.08, 1.0899999999999999, 1.0999999999999999,
    1.1099999999999999, 1.1199999999999999, 1.13, 1.14, 1.15, 1.16, 1.17, 1.18,
    1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3, 1.31,
    1.32, 1.33, 1.3399999999999999, 1.3499999999999999, 1.3599999999999999,
    1.3699999999999999, 1.38, 1.39, 1.4, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
    1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58, 1.59,
    1.5999999999999999, 1.6099999999999999, 1.6199999999999999, 1.63, 1.64, 1.65,
    1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77, 1.78,
    1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.8499999999999999, 1.8599999999999999,
    1.8699999999999999, 1.88, 1.89, 1.9, 1.91, 1.92, 1.93, 1.94, 1.95, 1.96,
    1.97, 1.98, 1.99, 2.0, 2.01, 2.02, 2.0300000000000002, 2.04, 2.05, 2.06,
    2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17,
    2.1799999999999997, 2.19, 2.2, 2.21, 2.2199999999999998, 2.23, 2.24, 2.25,
    2.26, 2.27, 2.2800000000000002, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35,
    2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.4299999999999997, 2.44, 2.45,
    2.46, 2.4699999999999998, 2.48, 2.49, 2.5, 2.51, 2.52, 2.53, 2.54, 2.55,
    2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 2.66, 2.67, 2.68,
    2.69, 2.7, 2.71, 2.7199999999999998, 2.73, 2.74, 2.75, 2.76, 2.77, 2.78,
    2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87, 2.88, 2.89, 2.9, 2.91,
    2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0 },

  // Expression: [-3:0.01:3]
  //  Referenced by: '<S85>/1-D Lookup Table'

  { -3.0, -2.99, -2.98, -2.97, -2.96, -2.95, -2.94, -2.93, -2.92, -2.91, -2.9,
    -2.89, -2.88, -2.87, -2.86, -2.85, -2.84, -2.83, -2.82, -2.81, -2.8, -2.79,
    -2.78, -2.77, -2.76, -2.75, -2.74, -2.73, -2.7199999999999998, -2.71, -2.7,
    -2.69, -2.68, -2.67, -2.66, -2.65, -2.64, -2.63, -2.62, -2.61, -2.6, -2.59,
    -2.58, -2.57, -2.56, -2.55, -2.54, -2.53, -2.52, -2.51, -2.5, -2.49, -2.48,
    -2.4699999999999998, -2.46, -2.45, -2.44, -2.4299999999999997, -2.42, -2.41,
    -2.4, -2.39, -2.38, -2.37, -2.36, -2.35, -2.34, -2.33, -2.32, -2.31, -2.3,
    -2.29, -2.2800000000000002, -2.27, -2.26, -2.25, -2.24, -2.23,
    -2.2199999999999998, -2.21, -2.2, -2.19, -2.1799999999999997, -2.17, -2.16,
    -2.15, -2.14, -2.13, -2.12, -2.11, -2.1, -2.09, -2.08, -2.07, -2.06, -2.05,
    -2.04, -2.0300000000000002, -2.02, -2.01, -2.0, -1.99, -1.98, -1.97, -1.96,
    -1.95, -1.94, -1.93, -1.92, -1.91, -1.9, -1.89, -1.88, -1.8699999999999999,
    -1.8599999999999999, -1.8499999999999999, -1.84, -1.83, -1.82, -1.81, -1.8,
    -1.79, -1.78, -1.77, -1.76, -1.75, -1.74, -1.73, -1.72, -1.71, -1.7, -1.69,
    -1.68, -1.67, -1.66, -1.65, -1.64, -1.63, -1.6199999999999999,
    -1.6099999999999999, -1.5999999999999999, -1.59, -1.58, -1.57, -1.56, -1.55,
    -1.54, -1.53, -1.52, -1.51, -1.5, -1.49, -1.48, -1.47, -1.46, -1.45, -1.44,
    -1.43, -1.42, -1.41, -1.4, -1.39, -1.38, -1.3699999999999999,
    -1.3599999999999999, -1.3499999999999999, -1.3399999999999999, -1.33, -1.32,
    -1.31, -1.3, -1.29, -1.28, -1.27, -1.26, -1.25, -1.24, -1.23, -1.22, -1.21,
    -1.2, -1.19, -1.18, -1.17, -1.16, -1.15, -1.14, -1.13, -1.1199999999999999,
    -1.1099999999999999, -1.0999999999999999, -1.0899999999999999, -1.08, -1.07,
    -1.06, -1.05, -1.04, -1.03, -1.02, -1.01, -1.0, -0.98999999999999977, -0.98,
    -0.96999999999999975, -0.96, -0.95000000000000018, -0.94,
    -0.93000000000000016, -0.91999999999999993, -0.91000000000000014,
    -0.89999999999999991, -0.89000000000000012, -0.87999999999999989,
    -0.87000000000000011, -0.85999999999999988, -0.85000000000000009,
    -0.83999999999999986, -0.83000000000000007, -0.81999999999999984, -0.81,
    -0.79999999999999982, -0.79, -0.7799999999999998, -0.77,
    -0.75999999999999979, -0.75, -0.73999999999999977, -0.73,
    -0.71999999999999975, -0.71, -0.69999999999999973, -0.69,
    -0.68000000000000016, -0.66999999999999993, -0.66000000000000014,
    -0.64999999999999991, -0.64000000000000012, -0.62999999999999989,
    -0.62000000000000011, -0.60999999999999988, -0.60000000000000009,
    -0.58999999999999986, -0.58000000000000007, -0.56999999999999984, -0.56,
    -0.54999999999999982, -0.54, -0.5299999999999998, -0.52,
    -0.50999999999999979, -0.5, -0.48999999999999977, -0.48,
    -0.46999999999999975, -0.45999999999999996, -0.44999999999999973,
    -0.43999999999999995, -0.43000000000000016, -0.41999999999999993,
    -0.41000000000000014, -0.39999999999999991, -0.39000000000000012,
    -0.37999999999999989, -0.37000000000000011, -0.35999999999999988,
    -0.35000000000000009, -0.33999999999999986, -0.33000000000000007,
    -0.31999999999999984, -0.31000000000000005, -0.29999999999999982,
    -0.29000000000000004, -0.2799999999999998, -0.27, -0.25999999999999979,
    -0.25, -0.23999999999999977, -0.22999999999999998, -0.21999999999999975,
    -0.20999999999999996, -0.19999999999999973, -0.18999999999999995,
    -0.18000000000000016, -0.16999999999999993, -0.16000000000000014,
    -0.14999999999999991, -0.14000000000000012, -0.12999999999999989,
    -0.12000000000000011, -0.10999999999999988, -0.10000000000000009,
    -0.089999999999999858, -0.080000000000000071, -0.06999999999999984,
    -0.060000000000000053, -0.049999999999999822, -0.040000000000000036,
    -0.029999999999999805, -0.020000000000000018, -0.0099999999999997868, 0.0,
    0.0099999999999997868, 0.020000000000000018, 0.029999999999999805,
    0.040000000000000036, 0.049999999999999822, 0.060000000000000053,
    0.06999999999999984, 0.080000000000000071, 0.089999999999999858,
    0.10000000000000009, 0.10999999999999988, 0.12000000000000011,
    0.12999999999999989, 0.14000000000000012, 0.14999999999999991,
    0.16000000000000014, 0.16999999999999993, 0.18000000000000016,
    0.18999999999999995, 0.19999999999999973, 0.20999999999999996,
    0.21999999999999975, 0.22999999999999998, 0.23999999999999977, 0.25,
    0.25999999999999979, 0.27, 0.2799999999999998, 0.29000000000000004,
    0.29999999999999982, 0.31000000000000005, 0.31999999999999984,
    0.33000000000000007, 0.33999999999999986, 0.35000000000000009,
    0.35999999999999988, 0.37000000000000011, 0.37999999999999989,
    0.39000000000000012, 0.39999999999999991, 0.41000000000000014,
    0.41999999999999993, 0.43000000000000016, 0.43999999999999995,
    0.44999999999999973, 0.45999999999999996, 0.46999999999999975, 0.48,
    0.48999999999999977, 0.5, 0.50999999999999979, 0.52, 0.5299999999999998,
    0.54, 0.54999999999999982, 0.56, 0.56999999999999984, 0.58000000000000007,
    0.58999999999999986, 0.60000000000000009, 0.60999999999999988,
    0.62000000000000011, 0.62999999999999989, 0.64000000000000012,
    0.64999999999999991, 0.66000000000000014, 0.66999999999999993,
    0.68000000000000016, 0.69, 0.69999999999999973, 0.71, 0.71999999999999975,
    0.73, 0.73999999999999977, 0.75, 0.75999999999999979, 0.77,
    0.7799999999999998, 0.79, 0.79999999999999982, 0.81, 0.81999999999999984,
    0.83000000000000007, 0.83999999999999986, 0.85000000000000009,
    0.85999999999999988, 0.87000000000000011, 0.87999999999999989,
    0.89000000000000012, 0.89999999999999991, 0.91000000000000014,
    0.91999999999999993, 0.93000000000000016, 0.94, 0.95000000000000018, 0.96,
    0.96999999999999975, 0.98, 0.98999999999999977, 1.0, 1.01, 1.02, 1.03, 1.04,
    1.05, 1.06, 1.07, 1.08, 1.0899999999999999, 1.0999999999999999,
    1.1099999999999999, 1.1199999999999999, 1.13, 1.14, 1.15, 1.16, 1.17, 1.18,
    1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3, 1.31,
    1.32, 1.33, 1.3399999999999999, 1.3499999999999999, 1.3599999999999999,
    1.3699999999999999, 1.38, 1.39, 1.4, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
    1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58, 1.59,
    1.5999999999999999, 1.6099999999999999, 1.6199999999999999, 1.63, 1.64, 1.65,
    1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77, 1.78,
    1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.8499999999999999, 1.8599999999999999,
    1.8699999999999999, 1.88, 1.89, 1.9, 1.91, 1.92, 1.93, 1.94, 1.95, 1.96,
    1.97, 1.98, 1.99, 2.0, 2.01, 2.02, 2.0300000000000002, 2.04, 2.05, 2.06,
    2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17,
    2.1799999999999997, 2.19, 2.2, 2.21, 2.2199999999999998, 2.23, 2.24, 2.25,
    2.26, 2.27, 2.2800000000000002, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35,
    2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.4299999999999997, 2.44, 2.45,
    2.46, 2.4699999999999998, 2.48, 2.49, 2.5, 2.51, 2.52, 2.53, 2.54, 2.55,
    2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 2.66, 2.67, 2.68,
    2.69, 2.7, 2.71, 2.7199999999999998, 2.73, 2.74, 2.75, 2.76, 2.77, 2.78,
    2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87, 2.88, 2.89, 2.9, 2.91,
    2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0 },

  // Expression: 6
  //  Referenced by: '<S85>/dZgain'

  6.0,

  // Expression: -0.8
  //  Referenced by: '<S85>/Dead Zone'

  -0.8,

  // Expression: 0.5
  //  Referenced by: '<S85>/Dead Zone'

  0.5,

  // Expression: 2
  //  Referenced by: '<S85>/Saturation'

  2.0,

  // Expression: -2
  //  Referenced by: '<S85>/Saturation'

  -2.0,

  // Expression: 0
  //  Referenced by: '<S75>/Constant'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_m
  //  Referenced by: '<S75>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S75>/Discrete-Time Integrator'

  0.0,

  // Expression: 0.2
  //  Referenced by: '<S95>/D_Z_rate'

  0.2,

  // Computed Parameter: TSamp_WtEt_g
  //  Referenced by: '<S81>/TSamp'

  400.0,

  // Expression: 6.5
  //  Referenced by: '<S91>/Gain1'

  6.5,

  // Expression: 1227
  //  Referenced by: '<S91>/Constant8'

  1227.0,

  // Expression: Inf
  //  Referenced by: '<S95>/SatPos_RollPitch_rate'

  0.0,

  // Expression: 6
  //  Referenced by: '<S95>/P_RollPitch_rate'

  6.0,

  // Expression: 4
  //  Referenced by: '<S95>/SatPos_RollPitch_pos'

  4.0,

  // Expression: 8.5
  //  Referenced by: '<S95>/P_RollPitch_pos'

  8.5,

  // Expression: 0
  //  Referenced by: '<S52>/Gain'

  0.0,

  // Expression: Inf
  //  Referenced by: '<S95>/SatPos_XY_pos'

  0.0,

  // Expression: 3
  //  Referenced by: '<S95>/P_XY_pos'

  3.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainv_mu
  //  Referenced by: '<S68>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S68>/Discrete-Time Integrator'

  0.0,

  // Expression: inf
  //  Referenced by: '<S68>/Saturation'

  0.0,

  // Expression: -inf
  //  Referenced by: '<S68>/Saturation'

  0.0,

  // Expression: -0.05
  //  Referenced by: '<S58>/Dead Zone'

  -0.05,

  // Expression: 0.05
  //  Referenced by: '<S58>/Dead Zone'

  0.05,

  // Expression: -3
  //  Referenced by: '<S58>/Gain'

  -3.0,

  // Expression: -0.05
  //  Referenced by: '<S58>/Dead Zone1'

  -0.05,

  // Expression: 0.05
  //  Referenced by: '<S58>/Dead Zone1'

  0.05,

  // Expression: 3
  //  Referenced by: '<S58>/Gain1'

  3.0,

  // Expression: 3
  //  Referenced by: '<S58>/Saturation1'

  3.0,

  // Expression: -3
  //  Referenced by: '<S58>/Saturation1'

  -3.0,

  // Expression: 1
  //  Referenced by: '<S70>/adapt_thrust'

  1.0,

  // Expression: [-3:0.01:3]
  //  Referenced by: '<S70>/1-D Lookup Table'

  { -3.0, -2.99, -2.98, -2.97, -2.96, -2.95, -2.94, -2.93, -2.92, -2.91, -2.9,
    -2.89, -2.88, -2.87, -2.86, -2.85, -2.84, -2.83, -2.82, -2.81, -2.8, -2.79,
    -2.78, -2.77, -2.76, -2.75, -2.74, -2.73, -2.7199999999999998, -2.71, -2.7,
    -2.69, -2.68, -2.67, -2.66, -2.65, -2.64, -2.63, -2.62, -2.61, -2.6, -2.59,
    -2.58, -2.57, -2.56, -2.55, -2.54, -2.53, -2.52, -2.51, -2.5, -2.49, -2.48,
    -2.4699999999999998, -2.46, -2.45, -2.44, -2.4299999999999997, -2.42, -2.41,
    -2.4, -2.39, -2.38, -2.37, -2.36, -2.35, -2.34, -2.33, -2.32, -2.31, -2.3,
    -2.29, -2.2800000000000002, -2.27, -2.26, -2.25, -2.24, -2.23,
    -2.2199999999999998, -2.21, -2.2, -2.19, -2.1799999999999997, -2.17, -2.16,
    -2.15, -2.14, -2.13, -2.12, -2.11, -2.1, -2.09, -2.08, -2.07, -2.06, -2.05,
    -2.04, -2.0300000000000002, -2.02, -2.01, -2.0, -1.99, -1.98, -1.97, -1.96,
    -1.95, -1.94, -1.93, -1.92, -1.91, -1.9, -1.89, -1.88, -1.8699999999999999,
    -1.8599999999999999, -1.8499999999999999, -1.84, -1.83, -1.82, -1.81, -1.8,
    -1.79, -1.78, -1.77, -1.76, -1.75, -1.74, -1.73, -1.72, -1.71, -1.7, -1.69,
    -1.68, -1.67, -1.66, -1.65, -1.64, -1.63, -1.6199999999999999,
    -1.6099999999999999, -1.5999999999999999, -1.59, -1.58, -1.57, -1.56, -1.55,
    -1.54, -1.53, -1.52, -1.51, -1.5, -1.49, -1.48, -1.47, -1.46, -1.45, -1.44,
    -1.43, -1.42, -1.41, -1.4, -1.39, -1.38, -1.3699999999999999,
    -1.3599999999999999, -1.3499999999999999, -1.3399999999999999, -1.33, -1.32,
    -1.31, -1.3, -1.29, -1.28, -1.27, -1.26, -1.25, -1.24, -1.23, -1.22, -1.21,
    -1.2, -1.19, -1.18, -1.17, -1.16, -1.15, -1.14, -1.13, -1.1199999999999999,
    -1.1099999999999999, -1.0999999999999999, -1.0899999999999999, -1.08, -1.07,
    -1.06, -1.05, -1.04, -1.03, -1.02, -1.01, -1.0, -0.98999999999999977, -0.98,
    -0.96999999999999975, -0.96, -0.95000000000000018, -0.94,
    -0.93000000000000016, -0.91999999999999993, -0.91000000000000014,
    -0.89999999999999991, -0.89000000000000012, -0.87999999999999989,
    -0.87000000000000011, -0.85999999999999988, -0.85000000000000009,
    -0.83999999999999986, -0.83000000000000007, -0.81999999999999984, -0.81,
    -0.79999999999999982, -0.79, -0.7799999999999998, -0.77,
    -0.75999999999999979, -0.75, -0.73999999999999977, -0.73,
    -0.71999999999999975, -0.71, -0.69999999999999973, -0.69,
    -0.68000000000000016, -0.66999999999999993, -0.66000000000000014,
    -0.64999999999999991, -0.64000000000000012, -0.62999999999999989,
    -0.62000000000000011, -0.60999999999999988, -0.60000000000000009,
    -0.58999999999999986, -0.58000000000000007, -0.56999999999999984, -0.56,
    -0.54999999999999982, -0.54, -0.5299999999999998, -0.52,
    -0.50999999999999979, -0.5, -0.48999999999999977, -0.48,
    -0.46999999999999975, -0.45999999999999996, -0.44999999999999973,
    -0.43999999999999995, -0.43000000000000016, -0.41999999999999993,
    -0.41000000000000014, -0.39999999999999991, -0.39000000000000012,
    -0.37999999999999989, -0.37000000000000011, -0.35999999999999988,
    -0.35000000000000009, -0.33999999999999986, -0.33000000000000007,
    -0.31999999999999984, -0.31000000000000005, -0.29999999999999982,
    -0.29000000000000004, -0.2799999999999998, -0.27, -0.25999999999999979,
    -0.25, -0.23999999999999977, -0.22999999999999998, -0.21999999999999975,
    -0.20999999999999996, -0.19999999999999973, -0.18999999999999995,
    -0.18000000000000016, -0.16999999999999993, -0.16000000000000014,
    -0.14999999999999991, -0.14000000000000012, -0.12999999999999989,
    -0.12000000000000011, -0.10999999999999988, -0.10000000000000009,
    -0.089999999999999858, -0.080000000000000071, -0.06999999999999984,
    -0.060000000000000053, -0.049999999999999822, -0.040000000000000036,
    -0.029999999999999805, -0.020000000000000018, -0.0099999999999997868, 0.0,
    0.0099999999999997868, 0.020000000000000018, 0.029999999999999805,
    0.040000000000000036, 0.049999999999999822, 0.060000000000000053,
    0.06999999999999984, 0.080000000000000071, 0.089999999999999858,
    0.10000000000000009, 0.10999999999999988, 0.12000000000000011,
    0.12999999999999989, 0.14000000000000012, 0.14999999999999991,
    0.16000000000000014, 0.16999999999999993, 0.18000000000000016,
    0.18999999999999995, 0.19999999999999973, 0.20999999999999996,
    0.21999999999999975, 0.22999999999999998, 0.23999999999999977, 0.25,
    0.25999999999999979, 0.27, 0.2799999999999998, 0.29000000000000004,
    0.29999999999999982, 0.31000000000000005, 0.31999999999999984,
    0.33000000000000007, 0.33999999999999986, 0.35000000000000009,
    0.35999999999999988, 0.37000000000000011, 0.37999999999999989,
    0.39000000000000012, 0.39999999999999991, 0.41000000000000014,
    0.41999999999999993, 0.43000000000000016, 0.43999999999999995,
    0.44999999999999973, 0.45999999999999996, 0.46999999999999975, 0.48,
    0.48999999999999977, 0.5, 0.50999999999999979, 0.52, 0.5299999999999998,
    0.54, 0.54999999999999982, 0.56, 0.56999999999999984, 0.58000000000000007,
    0.58999999999999986, 0.60000000000000009, 0.60999999999999988,
    0.62000000000000011, 0.62999999999999989, 0.64000000000000012,
    0.64999999999999991, 0.66000000000000014, 0.66999999999999993,
    0.68000000000000016, 0.69, 0.69999999999999973, 0.71, 0.71999999999999975,
    0.73, 0.73999999999999977, 0.75, 0.75999999999999979, 0.77,
    0.7799999999999998, 0.79, 0.79999999999999982, 0.81, 0.81999999999999984,
    0.83000000000000007, 0.83999999999999986, 0.85000000000000009,
    0.85999999999999988, 0.87000000000000011, 0.87999999999999989,
    0.89000000000000012, 0.89999999999999991, 0.91000000000000014,
    0.91999999999999993, 0.93000000000000016, 0.94, 0.95000000000000018, 0.96,
    0.96999999999999975, 0.98, 0.98999999999999977, 1.0, 1.01, 1.02, 1.03, 1.04,
    1.05, 1.06, 1.07, 1.08, 1.0899999999999999, 1.0999999999999999,
    1.1099999999999999, 1.1199999999999999, 1.13, 1.14, 1.15, 1.16, 1.17, 1.18,
    1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3, 1.31,
    1.32, 1.33, 1.3399999999999999, 1.3499999999999999, 1.3599999999999999,
    1.3699999999999999, 1.38, 1.39, 1.4, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
    1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58, 1.59,
    1.5999999999999999, 1.6099999999999999, 1.6199999999999999, 1.63, 1.64, 1.65,
    1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77, 1.78,
    1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.8499999999999999, 1.8599999999999999,
    1.8699999999999999, 1.88, 1.89, 1.9, 1.91, 1.92, 1.93, 1.94, 1.95, 1.96,
    1.97, 1.98, 1.99, 2.0, 2.01, 2.02, 2.0300000000000002, 2.04, 2.05, 2.06,
    2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17,
    2.1799999999999997, 2.19, 2.2, 2.21, 2.2199999999999998, 2.23, 2.24, 2.25,
    2.26, 2.27, 2.2800000000000002, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35,
    2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.4299999999999997, 2.44, 2.45,
    2.46, 2.4699999999999998, 2.48, 2.49, 2.5, 2.51, 2.52, 2.53, 2.54, 2.55,
    2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 2.66, 2.67, 2.68,
    2.69, 2.7, 2.71, 2.7199999999999998, 2.73, 2.74, 2.75, 2.76, 2.77, 2.78,
    2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87, 2.88, 2.89, 2.9, 2.91,
    2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0 },

  // Expression: [-3:0.01:3]
  //  Referenced by: '<S70>/1-D Lookup Table'

  { -3.0, -2.99, -2.98, -2.97, -2.96, -2.95, -2.94, -2.93, -2.92, -2.91, -2.9,
    -2.89, -2.88, -2.87, -2.86, -2.85, -2.84, -2.83, -2.82, -2.81, -2.8, -2.79,
    -2.78, -2.77, -2.76, -2.75, -2.74, -2.73, -2.7199999999999998, -2.71, -2.7,
    -2.69, -2.68, -2.67, -2.66, -2.65, -2.64, -2.63, -2.62, -2.61, -2.6, -2.59,
    -2.58, -2.57, -2.56, -2.55, -2.54, -2.53, -2.52, -2.51, -2.5, -2.49, -2.48,
    -2.4699999999999998, -2.46, -2.45, -2.44, -2.4299999999999997, -2.42, -2.41,
    -2.4, -2.39, -2.38, -2.37, -2.36, -2.35, -2.34, -2.33, -2.32, -2.31, -2.3,
    -2.29, -2.2800000000000002, -2.27, -2.26, -2.25, -2.24, -2.23,
    -2.2199999999999998, -2.21, -2.2, -2.19, -2.1799999999999997, -2.17, -2.16,
    -2.15, -2.14, -2.13, -2.12, -2.11, -2.1, -2.09, -2.08, -2.07, -2.06, -2.05,
    -2.04, -2.0300000000000002, -2.02, -2.01, -2.0, -1.99, -1.98, -1.97, -1.96,
    -1.95, -1.94, -1.93, -1.92, -1.91, -1.9, -1.89, -1.88, -1.8699999999999999,
    -1.8599999999999999, -1.8499999999999999, -1.84, -1.83, -1.82, -1.81, -1.8,
    -1.79, -1.78, -1.77, -1.76, -1.75, -1.74, -1.73, -1.72, -1.71, -1.7, -1.69,
    -1.68, -1.67, -1.66, -1.65, -1.64, -1.63, -1.6199999999999999,
    -1.6099999999999999, -1.5999999999999999, -1.59, -1.58, -1.57, -1.56, -1.55,
    -1.54, -1.53, -1.52, -1.51, -1.5, -1.49, -1.48, -1.47, -1.46, -1.45, -1.44,
    -1.43, -1.42, -1.41, -1.4, -1.39, -1.38, -1.3699999999999999,
    -1.3599999999999999, -1.3499999999999999, -1.3399999999999999, -1.33, -1.32,
    -1.31, -1.3, -1.29, -1.28, -1.27, -1.26, -1.25, -1.24, -1.23, -1.22, -1.21,
    -1.2, -1.19, -1.18, -1.17, -1.16, -1.15, -1.14, -1.13, -1.1199999999999999,
    -1.1099999999999999, -1.0999999999999999, -1.0899999999999999, -1.08, -1.07,
    -1.06, -1.05, -1.04, -1.03, -1.02, -1.01, -1.0, -0.98999999999999977, -0.98,
    -0.96999999999999975, -0.96, -0.95000000000000018, -0.94,
    -0.93000000000000016, -0.91999999999999993, -0.91000000000000014,
    -0.89999999999999991, -0.89000000000000012, -0.87999999999999989,
    -0.87000000000000011, -0.85999999999999988, -0.85000000000000009,
    -0.83999999999999986, -0.83000000000000007, -0.81999999999999984, -0.81,
    -0.79999999999999982, -0.79, -0.7799999999999998, -0.77,
    -0.75999999999999979, -0.75, -0.73999999999999977, -0.73,
    -0.71999999999999975, -0.71, -0.69999999999999973, -0.69,
    -0.68000000000000016, -0.66999999999999993, -0.66000000000000014,
    -0.64999999999999991, -0.64000000000000012, -0.62999999999999989,
    -0.62000000000000011, -0.60999999999999988, -0.60000000000000009,
    -0.58999999999999986, -0.58000000000000007, -0.56999999999999984, -0.56,
    -0.54999999999999982, -0.54, -0.5299999999999998, -0.52,
    -0.50999999999999979, -0.5, -0.48999999999999977, -0.48,
    -0.46999999999999975, -0.45999999999999996, -0.44999999999999973,
    -0.43999999999999995, -0.43000000000000016, -0.41999999999999993,
    -0.41000000000000014, -0.39999999999999991, -0.39000000000000012,
    -0.37999999999999989, -0.37000000000000011, -0.35999999999999988,
    -0.35000000000000009, -0.33999999999999986, -0.33000000000000007,
    -0.31999999999999984, -0.31000000000000005, -0.29999999999999982,
    -0.29000000000000004, -0.2799999999999998, -0.27, -0.25999999999999979,
    -0.25, -0.23999999999999977, -0.22999999999999998, -0.21999999999999975,
    -0.20999999999999996, -0.19999999999999973, -0.18999999999999995,
    -0.18000000000000016, -0.16999999999999993, -0.16000000000000014,
    -0.14999999999999991, -0.14000000000000012, -0.12999999999999989,
    -0.12000000000000011, -0.10999999999999988, -0.10000000000000009,
    -0.089999999999999858, -0.080000000000000071, -0.06999999999999984,
    -0.060000000000000053, -0.049999999999999822, -0.040000000000000036,
    -0.029999999999999805, -0.020000000000000018, -0.0099999999999997868, 0.0,
    0.0099999999999997868, 0.020000000000000018, 0.029999999999999805,
    0.040000000000000036, 0.049999999999999822, 0.060000000000000053,
    0.06999999999999984, 0.080000000000000071, 0.089999999999999858,
    0.10000000000000009, 0.10999999999999988, 0.12000000000000011,
    0.12999999999999989, 0.14000000000000012, 0.14999999999999991,
    0.16000000000000014, 0.16999999999999993, 0.18000000000000016,
    0.18999999999999995, 0.19999999999999973, 0.20999999999999996,
    0.21999999999999975, 0.22999999999999998, 0.23999999999999977, 0.25,
    0.25999999999999979, 0.27, 0.2799999999999998, 0.29000000000000004,
    0.29999999999999982, 0.31000000000000005, 0.31999999999999984,
    0.33000000000000007, 0.33999999999999986, 0.35000000000000009,
    0.35999999999999988, 0.37000000000000011, 0.37999999999999989,
    0.39000000000000012, 0.39999999999999991, 0.41000000000000014,
    0.41999999999999993, 0.43000000000000016, 0.43999999999999995,
    0.44999999999999973, 0.45999999999999996, 0.46999999999999975, 0.48,
    0.48999999999999977, 0.5, 0.50999999999999979, 0.52, 0.5299999999999998,
    0.54, 0.54999999999999982, 0.56, 0.56999999999999984, 0.58000000000000007,
    0.58999999999999986, 0.60000000000000009, 0.60999999999999988,
    0.62000000000000011, 0.62999999999999989, 0.64000000000000012,
    0.64999999999999991, 0.66000000000000014, 0.66999999999999993,
    0.68000000000000016, 0.69, 0.69999999999999973, 0.71, 0.71999999999999975,
    0.73, 0.73999999999999977, 0.75, 0.75999999999999979, 0.77,
    0.7799999999999998, 0.79, 0.79999999999999982, 0.81, 0.81999999999999984,
    0.83000000000000007, 0.83999999999999986, 0.85000000000000009,
    0.85999999999999988, 0.87000000000000011, 0.87999999999999989,
    0.89000000000000012, 0.89999999999999991, 0.91000000000000014,
    0.91999999999999993, 0.93000000000000016, 0.94, 0.95000000000000018, 0.96,
    0.96999999999999975, 0.98, 0.98999999999999977, 1.0, 1.01, 1.02, 1.03, 1.04,
    1.05, 1.06, 1.07, 1.08, 1.0899999999999999, 1.0999999999999999,
    1.1099999999999999, 1.1199999999999999, 1.13, 1.14, 1.15, 1.16, 1.17, 1.18,
    1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3, 1.31,
    1.32, 1.33, 1.3399999999999999, 1.3499999999999999, 1.3599999999999999,
    1.3699999999999999, 1.38, 1.39, 1.4, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
    1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58, 1.59,
    1.5999999999999999, 1.6099999999999999, 1.6199999999999999, 1.63, 1.64, 1.65,
    1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77, 1.78,
    1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.8499999999999999, 1.8599999999999999,
    1.8699999999999999, 1.88, 1.89, 1.9, 1.91, 1.92, 1.93, 1.94, 1.95, 1.96,
    1.97, 1.98, 1.99, 2.0, 2.01, 2.02, 2.0300000000000002, 2.04, 2.05, 2.06,
    2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17,
    2.1799999999999997, 2.19, 2.2, 2.21, 2.2199999999999998, 2.23, 2.24, 2.25,
    2.26, 2.27, 2.2800000000000002, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35,
    2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.4299999999999997, 2.44, 2.45,
    2.46, 2.4699999999999998, 2.48, 2.49, 2.5, 2.51, 2.52, 2.53, 2.54, 2.55,
    2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 2.66, 2.67, 2.68,
    2.69, 2.7, 2.71, 2.7199999999999998, 2.73, 2.74, 2.75, 2.76, 2.77, 2.78,
    2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87, 2.88, 2.89, 2.9, 2.91,
    2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0 },

  // Expression: 10
  //  Referenced by: '<S70>/dZgain'

  10.0,

  // Expression: -0.2
  //  Referenced by: '<S70>/Dead Zone'

  -0.2,

  // Expression: 0.2
  //  Referenced by: '<S70>/Dead Zone'

  0.2,

  // Expression: inf
  //  Referenced by: '<S70>/Saturation'

  0.0,

  // Expression: -inf
  //  Referenced by: '<S70>/Saturation'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_d
  //  Referenced by: '<S56>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S56>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S95>/D_XY_pos'

  0.0,

  // Computed Parameter: TSamp_WtEt_d
  //  Referenced by: '<S60>/TSamp'

  400.0,

  // Expression: -Inf
  //  Referenced by: '<S95>/SatNeg_XY_pos'

  0.0,

  // Expression: 1
  //  Referenced by: '<S52>/pid//pid_cascade'

  1.0,

  // Expression: Inf
  //  Referenced by: '<S95>/SatPos_XY_rate'

  0.0,

  // Expression: 5
  //  Referenced by: '<S95>/P_XY_rate'

  5.0,

  // Expression: inf
  //  Referenced by: '<S52>/Saturation'

  0.0,

  // Expression: -inf
  //  Referenced by: '<S52>/Saturation'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainv_mv
  //  Referenced by: '<S57>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S57>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S95>/D_XY_rate'

  0.0,

  // Computed Parameter: TSamp_WtEt_b
  //  Referenced by: '<S64>/TSamp'

  400.0,

  // Expression: -Inf
  //  Referenced by: '<S95>/SatNeg_XY_rate'

  0.0,

  // Expression: -1
  //  Referenced by: '<S52>/r'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S52>/p'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S52>/r1'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S52>/r2'

  -1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_b
  //  Referenced by: '<S34>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S34>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S95>/D_RollPitch_pos'

  0.0,

  // Computed Parameter: TSamp_WtEt_n
  //  Referenced by: '<S45>/TSamp'

  400.0,

  // Expression: -4
  //  Referenced by: '<S95>/SatNeg_RollPitch_pos'

  -4.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_k
  //  Referenced by: '<S32>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S32>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S95>/D_RollPitch_rate'

  0.0,

  // Computed Parameter: TSamp_WtEt_e
  //  Referenced by: '<S37>/TSamp'

  400.0,

  // Expression: -Inf
  //  Referenced by: '<S95>/SatNeg_RollPitch_rate'

  0.0,

  // Expression: [0;0]
  //  Referenced by: '<S29>/Constant'

  { 0.0, 0.0 },

  // Expression: 6.5
  //  Referenced by: '<S91>/Gain3'

  6.5,

  // Expression: 6.5
  //  Referenced by: '<S91>/Gain5'

  6.5,

  // Expression: Inf
  //  Referenced by: '<S95>/SatPos_Yaw_rate'

  0.0,

  // Expression: 75
  //  Referenced by: '<S95>/P_Yaw_rate'

  75.0,

  // Expression: Inf
  //  Referenced by: '<S95>/SatPos_Yaw_pos'

  0.0,

  // Expression: 10
  //  Referenced by: '<S95>/P_Yaw_pos'

  10.0,

  // Expression: -0.025
  //  Referenced by: '<S29>/Dead Zone1'

  -0.025,

  // Expression: 0.025
  //  Referenced by: '<S29>/Dead Zone1'

  0.025,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_o
  //  Referenced by: '<S35>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S35>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S95>/D_Yaw_pos'

  0.0,

  // Computed Parameter: TSamp_WtEt_o
  //  Referenced by: '<S49>/TSamp'

  400.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainv_iz
  //  Referenced by: '<S33>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S33>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S95>/D_Yaw_rate'

  0.0,

  // Computed Parameter: TSamp_WtEt_p
  //  Referenced by: '<S41>/TSamp'

  400.0,

  // Expression: 6.5
  //  Referenced by: '<S91>/Gain7'

  6.5,

  // Expression: 1
  //  Referenced by: '<S7>/scale2ticks'

  1.0,

  // Expression: 1100
  //  Referenced by: '<S7>/Constant3'

  1100.0,

  // Expression: 180/pi
  //  Referenced by: '<S3>/Gain'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S3>/Gain1'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S3>/Gain2'

  57.295779513082323,

  // Expression: -0.05
  //  Referenced by: '<S18>/Dead Zone'

  -0.05,

  // Expression: 0.05
  //  Referenced by: '<S18>/Dead Zone'

  0.05,

  // Expression: -3
  //  Referenced by: '<S18>/Gain'

  -3.0,

  // Expression: -0.05
  //  Referenced by: '<S18>/Dead Zone1'

  -0.05,

  // Expression: 0.05
  //  Referenced by: '<S18>/Dead Zone1'

  0.05,

  // Expression: 3
  //  Referenced by: '<S18>/Gain1'

  3.0,

  // Expression: 52.23
  //  Referenced by: '<S20>/med_thrust'

  52.23,

  // Expression: 0.01
  //  Referenced by: '<S25>/adapt_thrust'

  0.01,

  // Expression: [-3:0.01:3]
  //  Referenced by: '<S25>/1-D Lookup Table'

  { -3.0, -2.99, -2.98, -2.97, -2.96, -2.95, -2.94, -2.93, -2.92, -2.91, -2.9,
    -2.89, -2.88, -2.87, -2.86, -2.85, -2.84, -2.83, -2.82, -2.81, -2.8, -2.79,
    -2.78, -2.77, -2.76, -2.75, -2.74, -2.73, -2.7199999999999998, -2.71, -2.7,
    -2.69, -2.68, -2.67, -2.66, -2.65, -2.64, -2.63, -2.62, -2.61, -2.6, -2.59,
    -2.58, -2.57, -2.56, -2.55, -2.54, -2.53, -2.52, -2.51, -2.5, -2.49, -2.48,
    -2.4699999999999998, -2.46, -2.45, -2.44, -2.4299999999999997, -2.42, -2.41,
    -2.4, -2.39, -2.38, -2.37, -2.36, -2.35, -2.34, -2.33, -2.32, -2.31, -2.3,
    -2.29, -2.2800000000000002, -2.27, -2.26, -2.25, -2.24, -2.23,
    -2.2199999999999998, -2.21, -2.2, -2.19, -2.1799999999999997, -2.17, -2.16,
    -2.15, -2.14, -2.13, -2.12, -2.11, -2.1, -2.09, -2.08, -2.07, -2.06, -2.05,
    -2.04, -2.0300000000000002, -2.02, -2.01, -2.0, -1.99, -1.98, -1.97, -1.96,
    -1.95, -1.94, -1.93, -1.92, -1.91, -1.9, -1.89, -1.88, -1.8699999999999999,
    -1.8599999999999999, -1.8499999999999999, -1.84, -1.83, -1.82, -1.81, -1.8,
    -1.79, -1.78, -1.77, -1.76, -1.75, -1.74, -1.73, -1.72, -1.71, -1.7, -1.69,
    -1.68, -1.67, -1.66, -1.65, -1.64, -1.63, -1.6199999999999999,
    -1.6099999999999999, -1.5999999999999999, -1.59, -1.58, -1.57, -1.56, -1.55,
    -1.54, -1.53, -1.52, -1.51, -1.5, -1.49, -1.48, -1.47, -1.46, -1.45, -1.44,
    -1.43, -1.42, -1.41, -1.4, -1.39, -1.38, -1.3699999999999999,
    -1.3599999999999999, -1.3499999999999999, -1.3399999999999999, -1.33, -1.32,
    -1.31, -1.3, -1.29, -1.28, -1.27, -1.26, -1.25, -1.24, -1.23, -1.22, -1.21,
    -1.2, -1.19, -1.18, -1.17, -1.16, -1.15, -1.14, -1.13, -1.1199999999999999,
    -1.1099999999999999, -1.0999999999999999, -1.0899999999999999, -1.08, -1.07,
    -1.06, -1.05, -1.04, -1.03, -1.02, -1.01, -1.0, -0.98999999999999977, -0.98,
    -0.96999999999999975, -0.96, -0.95000000000000018, -0.94,
    -0.93000000000000016, -0.91999999999999993, -0.91000000000000014,
    -0.89999999999999991, -0.89000000000000012, -0.87999999999999989,
    -0.87000000000000011, -0.85999999999999988, -0.85000000000000009,
    -0.83999999999999986, -0.83000000000000007, -0.81999999999999984, -0.81,
    -0.79999999999999982, -0.79, -0.7799999999999998, -0.77,
    -0.75999999999999979, -0.75, -0.73999999999999977, -0.73,
    -0.71999999999999975, -0.71, -0.69999999999999973, -0.69,
    -0.68000000000000016, -0.66999999999999993, -0.66000000000000014,
    -0.64999999999999991, -0.64000000000000012, -0.62999999999999989,
    -0.62000000000000011, -0.60999999999999988, -0.60000000000000009,
    -0.58999999999999986, -0.58000000000000007, -0.56999999999999984, -0.56,
    -0.54999999999999982, -0.54, -0.5299999999999998, -0.52,
    -0.50999999999999979, -0.5, -0.48999999999999977, -0.48,
    -0.46999999999999975, -0.45999999999999996, -0.44999999999999973,
    -0.43999999999999995, -0.43000000000000016, -0.41999999999999993,
    -0.41000000000000014, -0.39999999999999991, -0.39000000000000012,
    -0.37999999999999989, -0.37000000000000011, -0.35999999999999988,
    -0.35000000000000009, -0.33999999999999986, -0.33000000000000007,
    -0.31999999999999984, -0.31000000000000005, -0.29999999999999982,
    -0.29000000000000004, -0.2799999999999998, -0.27, -0.25999999999999979,
    -0.25, -0.23999999999999977, -0.22999999999999998, -0.21999999999999975,
    -0.20999999999999996, -0.19999999999999973, -0.18999999999999995,
    -0.18000000000000016, -0.16999999999999993, -0.16000000000000014,
    -0.14999999999999991, -0.14000000000000012, -0.12999999999999989,
    -0.12000000000000011, -0.10999999999999988, -0.10000000000000009,
    -0.089999999999999858, -0.080000000000000071, -0.06999999999999984,
    -0.060000000000000053, -0.049999999999999822, -0.040000000000000036,
    -0.029999999999999805, -0.020000000000000018, -0.0099999999999997868, 0.0,
    0.0099999999999997868, 0.020000000000000018, 0.029999999999999805,
    0.040000000000000036, 0.049999999999999822, 0.060000000000000053,
    0.06999999999999984, 0.080000000000000071, 0.089999999999999858,
    0.10000000000000009, 0.10999999999999988, 0.12000000000000011,
    0.12999999999999989, 0.14000000000000012, 0.14999999999999991,
    0.16000000000000014, 0.16999999999999993, 0.18000000000000016,
    0.18999999999999995, 0.19999999999999973, 0.20999999999999996,
    0.21999999999999975, 0.22999999999999998, 0.23999999999999977, 0.25,
    0.25999999999999979, 0.27, 0.2799999999999998, 0.29000000000000004,
    0.29999999999999982, 0.31000000000000005, 0.31999999999999984,
    0.33000000000000007, 0.33999999999999986, 0.35000000000000009,
    0.35999999999999988, 0.37000000000000011, 0.37999999999999989,
    0.39000000000000012, 0.39999999999999991, 0.41000000000000014,
    0.41999999999999993, 0.43000000000000016, 0.43999999999999995,
    0.44999999999999973, 0.45999999999999996, 0.46999999999999975, 0.48,
    0.48999999999999977, 0.5, 0.50999999999999979, 0.52, 0.5299999999999998,
    0.54, 0.54999999999999982, 0.56, 0.56999999999999984, 0.58000000000000007,
    0.58999999999999986, 0.60000000000000009, 0.60999999999999988,
    0.62000000000000011, 0.62999999999999989, 0.64000000000000012,
    0.64999999999999991, 0.66000000000000014, 0.66999999999999993,
    0.68000000000000016, 0.69, 0.69999999999999973, 0.71, 0.71999999999999975,
    0.73, 0.73999999999999977, 0.75, 0.75999999999999979, 0.77,
    0.7799999999999998, 0.79, 0.79999999999999982, 0.81, 0.81999999999999984,
    0.83000000000000007, 0.83999999999999986, 0.85000000000000009,
    0.85999999999999988, 0.87000000000000011, 0.87999999999999989,
    0.89000000000000012, 0.89999999999999991, 0.91000000000000014,
    0.91999999999999993, 0.93000000000000016, 0.94, 0.95000000000000018, 0.96,
    0.96999999999999975, 0.98, 0.98999999999999977, 1.0, 1.01, 1.02, 1.03, 1.04,
    1.05, 1.06, 1.07, 1.08, 1.0899999999999999, 1.0999999999999999,
    1.1099999999999999, 1.1199999999999999, 1.13, 1.14, 1.15, 1.16, 1.17, 1.18,
    1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3, 1.31,
    1.32, 1.33, 1.3399999999999999, 1.3499999999999999, 1.3599999999999999,
    1.3699999999999999, 1.38, 1.39, 1.4, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
    1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58, 1.59,
    1.5999999999999999, 1.6099999999999999, 1.6199999999999999, 1.63, 1.64, 1.65,
    1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77, 1.78,
    1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.8499999999999999, 1.8599999999999999,
    1.8699999999999999, 1.88, 1.89, 1.9, 1.91, 1.92, 1.93, 1.94, 1.95, 1.96,
    1.97, 1.98, 1.99, 2.0, 2.01, 2.02, 2.0300000000000002, 2.04, 2.05, 2.06,
    2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17,
    2.1799999999999997, 2.19, 2.2, 2.21, 2.2199999999999998, 2.23, 2.24, 2.25,
    2.26, 2.27, 2.2800000000000002, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35,
    2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.4299999999999997, 2.44, 2.45,
    2.46, 2.4699999999999998, 2.48, 2.49, 2.5, 2.51, 2.52, 2.53, 2.54, 2.55,
    2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 2.66, 2.67, 2.68,
    2.69, 2.7, 2.71, 2.7199999999999998, 2.73, 2.74, 2.75, 2.76, 2.77, 2.78,
    2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87, 2.88, 2.89, 2.9, 2.91,
    2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0 },

  // Expression: [-3:0.01:3]
  //  Referenced by: '<S25>/1-D Lookup Table'

  { -3.0, -2.99, -2.98, -2.97, -2.96, -2.95, -2.94, -2.93, -2.92, -2.91, -2.9,
    -2.89, -2.88, -2.87, -2.86, -2.85, -2.84, -2.83, -2.82, -2.81, -2.8, -2.79,
    -2.78, -2.77, -2.76, -2.75, -2.74, -2.73, -2.7199999999999998, -2.71, -2.7,
    -2.69, -2.68, -2.67, -2.66, -2.65, -2.64, -2.63, -2.62, -2.61, -2.6, -2.59,
    -2.58, -2.57, -2.56, -2.55, -2.54, -2.53, -2.52, -2.51, -2.5, -2.49, -2.48,
    -2.4699999999999998, -2.46, -2.45, -2.44, -2.4299999999999997, -2.42, -2.41,
    -2.4, -2.39, -2.38, -2.37, -2.36, -2.35, -2.34, -2.33, -2.32, -2.31, -2.3,
    -2.29, -2.2800000000000002, -2.27, -2.26, -2.25, -2.24, -2.23,
    -2.2199999999999998, -2.21, -2.2, -2.19, -2.1799999999999997, -2.17, -2.16,
    -2.15, -2.14, -2.13, -2.12, -2.11, -2.1, -2.09, -2.08, -2.07, -2.06, -2.05,
    -2.04, -2.0300000000000002, -2.02, -2.01, -2.0, -1.99, -1.98, -1.97, -1.96,
    -1.95, -1.94, -1.93, -1.92, -1.91, -1.9, -1.89, -1.88, -1.8699999999999999,
    -1.8599999999999999, -1.8499999999999999, -1.84, -1.83, -1.82, -1.81, -1.8,
    -1.79, -1.78, -1.77, -1.76, -1.75, -1.74, -1.73, -1.72, -1.71, -1.7, -1.69,
    -1.68, -1.67, -1.66, -1.65, -1.64, -1.63, -1.6199999999999999,
    -1.6099999999999999, -1.5999999999999999, -1.59, -1.58, -1.57, -1.56, -1.55,
    -1.54, -1.53, -1.52, -1.51, -1.5, -1.49, -1.48, -1.47, -1.46, -1.45, -1.44,
    -1.43, -1.42, -1.41, -1.4, -1.39, -1.38, -1.3699999999999999,
    -1.3599999999999999, -1.3499999999999999, -1.3399999999999999, -1.33, -1.32,
    -1.31, -1.3, -1.29, -1.28, -1.27, -1.26, -1.25, -1.24, -1.23, -1.22, -1.21,
    -1.2, -1.19, -1.18, -1.17, -1.16, -1.15, -1.14, -1.13, -1.1199999999999999,
    -1.1099999999999999, -1.0999999999999999, -1.0899999999999999, -1.08, -1.07,
    -1.06, -1.05, -1.04, -1.03, -1.02, -1.01, -1.0, -0.98999999999999977, -0.98,
    -0.96999999999999975, -0.96, -0.95000000000000018, -0.94,
    -0.93000000000000016, -0.91999999999999993, -0.91000000000000014,
    -0.89999999999999991, -0.89000000000000012, -0.87999999999999989,
    -0.87000000000000011, -0.85999999999999988, -0.85000000000000009,
    -0.83999999999999986, -0.83000000000000007, -0.81999999999999984, -0.81,
    -0.79999999999999982, -0.79, -0.7799999999999998, -0.77,
    -0.75999999999999979, -0.75, -0.73999999999999977, -0.73,
    -0.71999999999999975, -0.71, -0.69999999999999973, -0.69,
    -0.68000000000000016, -0.66999999999999993, -0.66000000000000014,
    -0.64999999999999991, -0.64000000000000012, -0.62999999999999989,
    -0.62000000000000011, -0.60999999999999988, -0.60000000000000009,
    -0.58999999999999986, -0.58000000000000007, -0.56999999999999984, -0.56,
    -0.54999999999999982, -0.54, -0.5299999999999998, -0.52,
    -0.50999999999999979, -0.5, -0.48999999999999977, -0.48,
    -0.46999999999999975, -0.45999999999999996, -0.44999999999999973,
    -0.43999999999999995, -0.43000000000000016, -0.41999999999999993,
    -0.41000000000000014, -0.39999999999999991, -0.39000000000000012,
    -0.37999999999999989, -0.37000000000000011, -0.35999999999999988,
    -0.35000000000000009, -0.33999999999999986, -0.33000000000000007,
    -0.31999999999999984, -0.31000000000000005, -0.29999999999999982,
    -0.29000000000000004, -0.2799999999999998, -0.27, -0.25999999999999979,
    -0.25, -0.23999999999999977, -0.22999999999999998, -0.21999999999999975,
    -0.20999999999999996, -0.19999999999999973, -0.18999999999999995,
    -0.18000000000000016, -0.16999999999999993, -0.16000000000000014,
    -0.14999999999999991, -0.14000000000000012, -0.12999999999999989,
    -0.12000000000000011, -0.10999999999999988, -0.10000000000000009,
    -0.089999999999999858, -0.080000000000000071, -0.06999999999999984,
    -0.060000000000000053, -0.049999999999999822, -0.040000000000000036,
    -0.029999999999999805, -0.020000000000000018, -0.0099999999999997868, 0.0,
    0.0099999999999997868, 0.020000000000000018, 0.029999999999999805,
    0.040000000000000036, 0.049999999999999822, 0.060000000000000053,
    0.06999999999999984, 0.080000000000000071, 0.089999999999999858,
    0.10000000000000009, 0.10999999999999988, 0.12000000000000011,
    0.12999999999999989, 0.14000000000000012, 0.14999999999999991,
    0.16000000000000014, 0.16999999999999993, 0.18000000000000016,
    0.18999999999999995, 0.19999999999999973, 0.20999999999999996,
    0.21999999999999975, 0.22999999999999998, 0.23999999999999977, 0.25,
    0.25999999999999979, 0.27, 0.2799999999999998, 0.29000000000000004,
    0.29999999999999982, 0.31000000000000005, 0.31999999999999984,
    0.33000000000000007, 0.33999999999999986, 0.35000000000000009,
    0.35999999999999988, 0.37000000000000011, 0.37999999999999989,
    0.39000000000000012, 0.39999999999999991, 0.41000000000000014,
    0.41999999999999993, 0.43000000000000016, 0.43999999999999995,
    0.44999999999999973, 0.45999999999999996, 0.46999999999999975, 0.48,
    0.48999999999999977, 0.5, 0.50999999999999979, 0.52, 0.5299999999999998,
    0.54, 0.54999999999999982, 0.56, 0.56999999999999984, 0.58000000000000007,
    0.58999999999999986, 0.60000000000000009, 0.60999999999999988,
    0.62000000000000011, 0.62999999999999989, 0.64000000000000012,
    0.64999999999999991, 0.66000000000000014, 0.66999999999999993,
    0.68000000000000016, 0.69, 0.69999999999999973, 0.71, 0.71999999999999975,
    0.73, 0.73999999999999977, 0.75, 0.75999999999999979, 0.77,
    0.7799999999999998, 0.79, 0.79999999999999982, 0.81, 0.81999999999999984,
    0.83000000000000007, 0.83999999999999986, 0.85000000000000009,
    0.85999999999999988, 0.87000000000000011, 0.87999999999999989,
    0.89000000000000012, 0.89999999999999991, 0.91000000000000014,
    0.91999999999999993, 0.93000000000000016, 0.94, 0.95000000000000018, 0.96,
    0.96999999999999975, 0.98, 0.98999999999999977, 1.0, 1.01, 1.02, 1.03, 1.04,
    1.05, 1.06, 1.07, 1.08, 1.0899999999999999, 1.0999999999999999,
    1.1099999999999999, 1.1199999999999999, 1.13, 1.14, 1.15, 1.16, 1.17, 1.18,
    1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3, 1.31,
    1.32, 1.33, 1.3399999999999999, 1.3499999999999999, 1.3599999999999999,
    1.3699999999999999, 1.38, 1.39, 1.4, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
    1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58, 1.59,
    1.5999999999999999, 1.6099999999999999, 1.6199999999999999, 1.63, 1.64, 1.65,
    1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77, 1.78,
    1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.8499999999999999, 1.8599999999999999,
    1.8699999999999999, 1.88, 1.89, 1.9, 1.91, 1.92, 1.93, 1.94, 1.95, 1.96,
    1.97, 1.98, 1.99, 2.0, 2.01, 2.02, 2.0300000000000002, 2.04, 2.05, 2.06,
    2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15, 2.16, 2.17,
    2.1799999999999997, 2.19, 2.2, 2.21, 2.2199999999999998, 2.23, 2.24, 2.25,
    2.26, 2.27, 2.2800000000000002, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35,
    2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.4299999999999997, 2.44, 2.45,
    2.46, 2.4699999999999998, 2.48, 2.49, 2.5, 2.51, 2.52, 2.53, 2.54, 2.55,
    2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65, 2.66, 2.67, 2.68,
    2.69, 2.7, 2.71, 2.7199999999999998, 2.73, 2.74, 2.75, 2.76, 2.77, 2.78,
    2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87, 2.88, 2.89, 2.9, 2.91,
    2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0 },

  // Expression: 6
  //  Referenced by: '<S25>/dZgain'

  6.0,

  // Expression: -0.8
  //  Referenced by: '<S25>/Dead Zone'

  -0.8,

  // Expression: 0.5
  //  Referenced by: '<S25>/Dead Zone'

  0.5,

  // Expression: 2
  //  Referenced by: '<S25>/Saturation'

  2.0,

  // Expression: -2
  //  Referenced by: '<S25>/Saturation'

  -2.0,

  // Expression: 0.5
  //  Referenced by: '<S26>/Zgain'

  0.5,

  // Expression: 0
  //  Referenced by: '<S95>/I_RollPitch_rate'

  0.0,

  // Expression: 0
  //  Referenced by: '<S32>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S33>/Constant'

  0.0,

  // Expression: 10
  //  Referenced by: '<S33>/Constant2'

  10.0,

  // Expression: 4.2
  //  Referenced by: '<S95>/I_RollPitch_pos'

  4.2,

  // Expression: 0
  //  Referenced by: '<S34>/Constant'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S95>/I_Yaw_pos'

  0.1,

  // Expression: 0
  //  Referenced by: '<S95>/I_XY_pos'

  0.0,

  // Expression: 0
  //  Referenced by: '<S56>/Constant'

  0.0,

  // Expression: 0.5
  //  Referenced by: '<S95>/I_XY_rate'

  0.5,

  // Expression: 0
  //  Referenced by: '<S57>/Constant'

  0.0,

  // Expression: 0.5
  //  Referenced by: '<S68>/Zgain'

  0.5,

  // Expression: 0
  //  Referenced by: '<S68>/Constant'

  0.0,

  // Expression: 0.1
  //  Referenced by: '<S95>/I_Z_pos'

  0.1,

  // Expression: 0.2
  //  Referenced by: '<S95>/I_Z_rate'

  0.2,

  // Expression: 0.5
  //  Referenced by: '<S86>/Zgain'

  0.5,

  // Expression: 180/pi
  //  Referenced by: '<S102>/Gain'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S102>/Gain1'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S102>/Gain2'

  57.295779513082323,

  // Expression: 1/255
  //  Referenced by: '<S172>/Gain3'

  0.00392156862745098,

  // Expression: [0;0;0;1]
  //  Referenced by: '<S172>/q '

  { 0.0, 0.0, 0.0, 1.0 },

  // Computed Parameter: Gain3_Gain_o
  //  Referenced by: '<S174>/Gain3'

  1.0F,

  // Computed Parameter: Gain2_Gain_o
  //  Referenced by: '<S174>/Gain2'

  1.0F,

  // Computed Parameter: Constant5_Value_p
  //  Referenced by: '<S89>/Constant5'

  0.0F,

  // Computed Parameter: Constant6_Value_i
  //  Referenced by: '<S89>/Constant6'

  0.0F,

  // Computed Parameter: Constant7_Value_c
  //  Referenced by: '<S89>/Constant7'

  0.0F,

  // Computed Parameter: Constant8_Value_d
  //  Referenced by: '<S89>/Constant8'

  0.0F,

  // Computed Parameter: Constant9_Value
  //  Referenced by: '<S89>/Constant9'

  0.0F,

  // Computed Parameter: Constant18_Value
  //  Referenced by: '<S89>/Constant18'

  0.0F,

  // Computed Parameter: Constant10_Value
  //  Referenced by: '<S89>/Constant10'

  0.0F,

  // Computed Parameter: Constant11_Value
  //  Referenced by: '<S89>/Constant11'

  0.0F,

  // Computed Parameter: Constant12_Value
  //  Referenced by: '<S89>/Constant12'

  0.0F,

  // Computed Parameter: Constant14_Value
  //  Referenced by: '<S89>/Constant14'

  0.0F,

  // Computed Parameter: Constant4_Value_k
  //  Referenced by: '<S89>/Constant4'

  1100U,

  // Computed Parameter: Constant17_Value
  //  Referenced by: '<S89>/Constant17'

  1100U,

  // Computed Parameter: Constant16_Value
  //  Referenced by: '<S89>/Constant16'

  1100U,

  // Computed Parameter: Constant15_Value
  //  Referenced by: '<S89>/Constant15'

  1100U,

  // Computed Parameter: ManualSwitch2_CurrentSetting
  //  Referenced by: '<S89>/Manual Switch2'

  0U,

  // Computed Parameter: ManualSwitch13_CurrentSetting
  //  Referenced by: '<S89>/Manual Switch13'

  0U,

  // Computed Parameter: ManualSwitch14_CurrentSetting
  //  Referenced by: '<S89>/Manual Switch14'

  0U,

  // Computed Parameter: ManualSwitch15_CurrentSetting
  //  Referenced by: '<S89>/Manual Switch15'

  0U,

  // Computed Parameter: enable_PC_Value
  //  Referenced by: '<S155>/enable_PC'

  0,

  // Computed Parameter: rollPitch_pos_rate_Value
  //  Referenced by: '<S155>/rollPitch_pos_rate'

  1,

  // Computed Parameter: position_Value
  //  Referenced by: '<S155>/position'

  1,

  // Computed Parameter: geometricControl_Value
  //  Referenced by: '<S155>/geometricControl'

  1,

  // Computed Parameter: Constant_Value_gs
  //  Referenced by: '<S8>/Constant'

  0,

  // Computed Parameter: Z_pos_vel_Value
  //  Referenced by: '<S155>/Z_pos_vel'

  1,

  // Computed Parameter: XY_pos_vel_Value
  //  Referenced by: '<S155>/XY_pos_vel'

  1,

  // Computed Parameter: yaw_pos_rate_Value
  //  Referenced by: '<S155>/yaw_pos_rate'

  1
};

//
// File trailer for generated code.
//
// [EOF]
//
