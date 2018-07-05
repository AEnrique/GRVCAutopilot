//
// File: controlAerobi_types.h
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
#ifndef RTW_HEADER_controlAerobi_types_h_
#define RTW_HEADER_controlAerobi_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_shm_imu_
#define DEFINED_TYPEDEF_FOR_shm_imu_

typedef struct {
  real32_T _temperature;
  real32_T _ax;
  real32_T _ay;
  real32_T _az;
  real32_T _gx;
  real32_T _gy;
  real32_T _gz;
  real32_T _mx;
  real32_T _my;
  real32_T _mz;
} shm_imu;

#endif

#ifndef DEFINED_TYPEDEF_FOR_shm_RCin_
#define DEFINED_TYPEDEF_FOR_shm_RCin_

typedef struct {
  uint16_T _channel1;
  uint16_T _channel2;
  uint16_T _channel3;
  uint16_T _channel4;
  uint16_T _channel5;
  uint16_T _channel6;
  uint16_T _channel7;
  uint16_T _channel8;
  uint16_T _channel9;
  uint16_T _channel10;
  uint16_T _channel11;
  uint16_T _channel12;
  uint16_T _channel13;
  uint16_T _channel14;
} shm_RCin;

#endif

#ifndef DEFINED_TYPEDEF_FOR_shm_lightware_
#define DEFINED_TYPEDEF_FOR_shm_lightware_

typedef struct {
  real32_T _z;
} shm_lightware;

#endif

#ifndef DEFINED_TYPEDEF_FOR_shm_adc_
#define DEFINED_TYPEDEF_FOR_shm_adc_

typedef struct {
  real32_T _adc0;
  real32_T _adc1;
  real32_T _adc2;
  real32_T _adc3;
  real32_T _adc4;
  real32_T _adc5;
} shm_adc;

#endif

#ifndef DEFINED_TYPEDEF_FOR_shm_totalStation_
#define DEFINED_TYPEDEF_FOR_shm_totalStation_

typedef struct {
  real32_T _x;
  real32_T _y;
  real32_T _z;
  real_T _time;
} shm_totalStation;

#endif

#ifndef DEFINED_TYPEDEF_FOR_shm_px4flow_
#define DEFINED_TYPEDEF_FOR_shm_px4flow_

typedef struct {
  uint16_T _frame_count;
  int16_T _pixel_flow_x_sum;
  int16_T _pixel_flow_y_sum;
  int16_T _flow_comp_m_x;
  int16_T _flow_comp_m_y;
  int16_T _qual;
  int16_T _gyro_x_rate;
  int16_T _gyro_y_rate;
  int16_T _gyro_z_rate;
  uint8_T _gyro_range;
  uint8_T _sonar_timestamp;
  int16_T _ground_distance;
} shm_px4flow;

#endif

#ifndef DEFINED_TYPEDEF_FOR_shm_RCou_
#define DEFINED_TYPEDEF_FOR_shm_RCou_

typedef struct {
  real32_T _channel1;
  real32_T _channel2;
  real32_T _channel3;
  real32_T _channel4;
  real32_T _channel5;
  real32_T _channel6;
  real32_T _channel7;
  real32_T _channel8;
  real32_T _channel9;
  real32_T _channel10;
  real32_T _channel11;
  real32_T _channel12;
  real32_T _channel13;
  real32_T _channel14;
} shm_RCou;

#endif

// Parameters (auto storage)
typedef struct Parameters_controlAerobi_ Parameters_controlAerobi;

// Forward declaration for rtModel
typedef struct tag_RTM_controlAerobi RT_MODEL_controlAerobi;

#endif                                 // RTW_HEADER_controlAerobi_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
