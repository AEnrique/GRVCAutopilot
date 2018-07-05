//
//  controlAerobi_dt.h
//
//  Code generation for model "controlAerobi".
//
//  Model version              : 1.2418
//  Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
//  C++ source code generated on : Thu Jul  5 16:05:22 2018
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex
//  Code generation objectives:
//     1. Execution efficiency
//     2. ROM efficiency
//     3. RAM efficiency
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(shm_imu),
  sizeof(shm_RCin),
  sizeof(shm_lightware),
  sizeof(shm_adc),
  sizeof(shm_totalStation),
  sizeof(shm_px4flow),
  sizeof(shm_RCou)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "shm_imu",
  "shm_RCin",
  "shm_lightware",
  "shm_adc",
  "shm_totalStation",
  "shm_px4flow",
  "shm_RCou"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&controlAerobi_B.Localpositionreceive_o1[0]), 1, 0, 13 },

  { (char_T *)(&controlAerobi_B.MultiportSwitch[0]), 0, 0, 17 },

  { (char_T *)(&controlAerobi_B.Gain3), 0, 0, 5 },

  { (char_T *)(&controlAerobi_B.PX4receive_o1[0]), 1, 0, 21 },

  { (char_T *)(&controlAerobi_B._adc0), 1, 0, 72 },

  { (char_T *)(&controlAerobi_B.ByteUnpack_o2), 7, 0, 2 },

  { (char_T *)(&controlAerobi_B.BytePack[0]), 3, 0, 72 },

  { (char_T *)(&controlAerobi_B.Compare), 8, 0, 3 },

  { (char_T *)(&controlAerobi_B.sf_MATLABFunction_c.g_offset[0]), 0, 0, 3 },

  { (char_T *)(&controlAerobi_B.sf_MATLABFunction_a.g_offset[0]), 0, 0, 3 },

  { (char_T *)(&controlAerobi_B.sf_CreatedXYdesired.dXY_d[0]), 0, 0, 2 },

  { (char_T *)(&controlAerobi_B.sf_CreatedXYdesired_o.dXY_d[0]), 0, 0, 2 }
  ,

  { (char_T *)(&controlAerobi_DWork.DiscreteTimeIntegrator_DSTATE[0]), 0, 0,
    1994 },

  { (char_T *)(&controlAerobi_DWork.PLOT_PWORK.LoggedData[0]), 11, 0, 9 },

  { (char_T *)(&controlAerobi_DWork.DiscreteTimeIntegrator_PrevRese), 2, 0, 12 },

  { (char_T *)(&controlAerobi_DWork.Unwrap_FirstStep), 8, 0, 74 },

  { (char_T *)(&controlAerobi_DWork.sf_MATLABFunction_c.offset[0]), 0, 0, 7 },

  { (char_T *)(&controlAerobi_DWork.sf_MATLABFunction_c.offset_not_empty), 8, 0,
    3 },

  { (char_T *)(&controlAerobi_DWork.sf_MATLABFunction_a.offset[0]), 0, 0, 7 },

  { (char_T *)(&controlAerobi_DWork.sf_MATLABFunction_a.offset_not_empty), 8, 0,
    3 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  20U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&controlAerobi_P.DiscreteDerivative_ICPrevScaled), 0, 0, 30 },

  { (char_T *)(&controlAerobi_P.PX4receive_localPort), 6, 0, 2 },

  { (char_T *)(&controlAerobi_P.Reset_Value[0]), 0, 0, 4109 },

  { (char_T *)(&controlAerobi_P.Gain3_Gain_o), 1, 0, 12 },

  { (char_T *)(&controlAerobi_P.Constant4_Value_k), 5, 0, 4 },

  { (char_T *)(&controlAerobi_P.ManualSwitch2_CurrentSetting), 3, 0, 4 },

  { (char_T *)(&controlAerobi_P.enable_PC_Value), 8, 0, 8 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

// [EOF] controlAerobi_dt.h
