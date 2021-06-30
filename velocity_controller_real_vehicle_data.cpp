//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: velocity_controller_real_vehicle_data.cpp
//
// Code generated for Simulink model 'velocity_controller_real_vehicle'.
//
// Model version                  : 1.38
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Jun 29 17:29:20 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "velocity_controller_real_vehicle.h"
#include "velocity_controller_real_vehicle_private.h"

// Block parameters (default storage)
P_velocity_controller_real_ve_T velocity_controller_real_vehi_P = {
  // Mask Parameter: PIDController1_D
  //  Referenced by: '<S33>/Derivative Gain'

  1.14032900506104,

  // Mask Parameter: PIDController1_I
  //  Referenced by: '<S36>/Integral Gain'

  0.134074922947779,

  // Mask Parameter: PIDController1_InitialCondition
  //  Referenced by: '<S34>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_h
  //  Referenced by: '<S39>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_LowerSaturationL
  //  Referenced by:
  //    '<S46>/Saturation'
  //    '<S32>/DeadZone'

  -3.0,

  // Mask Parameter: PIDController1_N
  //  Referenced by: '<S42>/Filter Coefficient'

  2.31488315878784,

  // Mask Parameter: PIDController1_P
  //  Referenced by: '<S44>/Proportional Gain'

  1.0467641274631,

  // Mask Parameter: PIDController1_UpperSaturationL
  //  Referenced by:
  //    '<S46>/Saturation'
  //    '<S32>/DeadZone'

  1.5,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S56>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S4>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S57>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S5>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 0
  //  Referenced by: '<S30>/Constant1'

  0.0,

  // Expression: 1.5
  //  Referenced by: '<Root>/Saturation'

  1.5,

  // Expression: -3
  //  Referenced by: '<Root>/Saturation'

  -3.0,

  // Expression: 0
  //  Referenced by: '<S30>/ZeroGain'

  0.0,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S30>/Memory'

  0
};

//
// File trailer for generated code.
//
// [EOF]
//
