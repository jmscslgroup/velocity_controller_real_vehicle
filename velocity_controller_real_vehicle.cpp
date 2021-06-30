//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: velocity_controller_real_vehicle.cpp
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

// Block signals (default storage)
B_velocity_controller_real_ve_T velocity_controller_real_vehi_B;

// Continuous states
X_velocity_controller_real_ve_T velocity_controller_real_vehi_X;

// Block states (default storage)
DW_velocity_controller_real_v_T velocity_controller_real_veh_DW;

// Real-time model
RT_MODEL_velocity_controller__T velocity_controller_real_veh_M_ =
  RT_MODEL_velocity_controller__T();
RT_MODEL_velocity_controller__T *const velocity_controller_real_veh_M =
  &velocity_controller_real_veh_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  velocity_controller_real_vehicle_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  velocity_controller_real_vehicle_step();
  velocity_controller_real_vehicle_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  velocity_controller_real_vehicle_step();
  velocity_controller_real_vehicle_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void velocity_controller_real_vehicle_step(void)
{
  SL_Bus_velocity_controller_real_vehicle_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_IntegralGain;
  real_T rtb_SignPreSat;
  real_T rtb_ZeroGain;
  real_T tmp;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(velocity_controller_real_veh_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&velocity_controller_real_veh_M->solverInfo,
                          ((velocity_controller_real_veh_M->Timing.clockTick0+1)*
      velocity_controller_real_veh_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(velocity_controller_real_veh_M)) {
    velocity_controller_real_veh_M->Timing.t[0] = rtsiGetT
      (&velocity_controller_real_veh_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(velocity_controller_real_veh_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   Inport: '<S56>/In1'

    b_varargout_1 = Sub_velocity_controller_real_vehicle_10.getLatestMessage
      (&velocity_controller_real_vehi_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S56>/Enable'

    if (b_varargout_1) {
      velocity_controller_real_vehi_B.In1_d =
        velocity_controller_real_vehi_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Outputs for Atomic SubSystem: '<Root>/relative velocity'
    // MATLABSystem: '<S5>/SourceBlock' incorporates:
    //   Inport: '<S57>/In1'

    b_varargout_1 = Sub_velocity_controller_real_vehicle_34.getLatestMessage
      (&velocity_controller_real_vehi_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S57>/Enable'

    if (b_varargout_1) {
      velocity_controller_real_vehi_B.In1 =
        velocity_controller_real_vehi_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/relative velocity'

    // Sum: '<Root>/Sum' incorporates:
    //   Sum: '<Root>/Sum1'

    rtb_IntegralGain = (velocity_controller_real_vehi_B.In1_d.Linear.X -
                        velocity_controller_real_vehi_B.In1.Linear.Z) -
      velocity_controller_real_vehi_B.In1_d.Linear.X;

    // Gain: '<S44>/Proportional Gain'
    velocity_controller_real_vehi_B.ProportionalGain =
      velocity_controller_real_vehi_P.PIDController1_P * rtb_IntegralGain;

    // Gain: '<S33>/Derivative Gain'
    velocity_controller_real_vehi_B.DerivativeGain =
      velocity_controller_real_vehi_P.PIDController1_D * rtb_IntegralGain;
  }

  // Gain: '<S42>/Filter Coefficient' incorporates:
  //   Integrator: '<S34>/Filter'
  //   Sum: '<S34>/SumD'

  velocity_controller_real_vehi_B.FilterCoefficient =
    (velocity_controller_real_vehi_B.DerivativeGain -
     velocity_controller_real_vehi_X.Filter_CSTATE) *
    velocity_controller_real_vehi_P.PIDController1_N;

  // Sum: '<S48>/Sum' incorporates:
  //   Integrator: '<S39>/Integrator'

  rtb_SignPreSat = (velocity_controller_real_vehi_B.ProportionalGain +
                    velocity_controller_real_vehi_X.Integrator_CSTATE) +
    velocity_controller_real_vehi_B.FilterCoefficient;

  // Saturate: '<S46>/Saturation'
  if (rtb_SignPreSat >
      velocity_controller_real_vehi_P.PIDController1_UpperSaturationL) {
    rtb_ZeroGain =
      velocity_controller_real_vehi_P.PIDController1_UpperSaturationL;
  } else if (rtb_SignPreSat <
             velocity_controller_real_vehi_P.PIDController1_LowerSaturationL) {
    rtb_ZeroGain =
      velocity_controller_real_vehi_P.PIDController1_LowerSaturationL;
  } else {
    rtb_ZeroGain = rtb_SignPreSat;
  }

  // End of Saturate: '<S46>/Saturation'

  // Saturate: '<Root>/Saturation'
  if (rtb_ZeroGain > velocity_controller_real_vehi_P.Saturation_UpperSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = velocity_controller_real_vehi_P.Saturation_UpperSat;
  } else if (rtb_ZeroGain < velocity_controller_real_vehi_P.Saturation_LowerSat)
  {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = velocity_controller_real_vehi_P.Saturation_LowerSat;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = rtb_ZeroGain;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_velocity_controller_real_vehicle_3.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // Gain: '<S30>/ZeroGain'
  rtb_ZeroGain = velocity_controller_real_vehi_P.ZeroGain_Gain * rtb_SignPreSat;

  // DeadZone: '<S32>/DeadZone'
  if (rtb_SignPreSat >
      velocity_controller_real_vehi_P.PIDController1_UpperSaturationL) {
    rtb_SignPreSat -=
      velocity_controller_real_vehi_P.PIDController1_UpperSaturationL;
  } else if (rtb_SignPreSat >=
             velocity_controller_real_vehi_P.PIDController1_LowerSaturationL) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat -=
      velocity_controller_real_vehi_P.PIDController1_LowerSaturationL;
  }

  // End of DeadZone: '<S32>/DeadZone'
  if (rtmIsMajorTimeStep(velocity_controller_real_veh_M)) {
    // Gain: '<S36>/Integral Gain'
    rtb_IntegralGain *= velocity_controller_real_vehi_P.PIDController1_I;

    // Signum: '<S30>/SignPreIntegrator'
    if (rtb_IntegralGain < 0.0) {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      tmp = -1.0;
    } else if (rtb_IntegralGain > 0.0) {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      tmp = 1.0;
    } else if (rtb_IntegralGain == 0.0) {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      tmp = 0.0;
    } else {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      tmp = (rtNaN);
    }

    // End of Signum: '<S30>/SignPreIntegrator'

    // DataTypeConversion: '<S30>/DataTypeConv2'
    if (rtIsNaN(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    // DataTypeConversion: '<S30>/DataTypeConv2'
    velocity_controller_real_vehi_B.DataTypeConv2 = static_cast<int8_T>(tmp <
      0.0 ? static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(
      static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(static_cast<int8_T>(
      static_cast<uint8_T>(tmp))));
  }

  // Signum: '<S30>/SignPreSat'
  if (rtb_SignPreSat < 0.0) {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    tmp = -1.0;
  } else if (rtb_SignPreSat > 0.0) {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    tmp = 1.0;
  } else if (rtb_SignPreSat == 0.0) {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    tmp = (rtNaN);
  }

  // End of Signum: '<S30>/SignPreSat'

  // DataTypeConversion: '<S30>/DataTypeConv1'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // Logic: '<S30>/AND3' incorporates:
  //   DataTypeConversion: '<S30>/DataTypeConv1'
  //   RelationalOperator: '<S30>/Equal1'
  //   RelationalOperator: '<S30>/NotEqual'

  velocity_controller_real_vehi_B.AND3 = ((rtb_ZeroGain != rtb_SignPreSat) &&
    ((tmp < 0.0 ? static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(
    static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp)))) ==
     velocity_controller_real_vehi_B.DataTypeConv2));
  if (rtmIsMajorTimeStep(velocity_controller_real_veh_M)) {
    // Switch: '<S30>/Switch' incorporates:
    //   Memory: '<S30>/Memory'

    if (velocity_controller_real_veh_DW.Memory_PreviousInput) {
      // Switch: '<S30>/Switch' incorporates:
      //   Constant: '<S30>/Constant1'

      velocity_controller_real_vehi_B.Switch =
        velocity_controller_real_vehi_P.Constant1_Value;
    } else {
      // Switch: '<S30>/Switch'
      velocity_controller_real_vehi_B.Switch = rtb_IntegralGain;
    }

    // End of Switch: '<S30>/Switch'
  }

  if (rtmIsMajorTimeStep(velocity_controller_real_veh_M)) {
    if (rtmIsMajorTimeStep(velocity_controller_real_veh_M)) {
      // Update for Memory: '<S30>/Memory'
      velocity_controller_real_veh_DW.Memory_PreviousInput =
        velocity_controller_real_vehi_B.AND3;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(velocity_controller_real_veh_M)) {
    rt_ertODEUpdateContinuousStates(&velocity_controller_real_veh_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++velocity_controller_real_veh_M->Timing.clockTick0;
    velocity_controller_real_veh_M->Timing.t[0] = rtsiGetSolverStopTime
      (&velocity_controller_real_veh_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.02s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.02, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      velocity_controller_real_veh_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void velocity_controller_real_vehicle_derivatives(void)
{
  XDot_velocity_controller_real_T *_rtXdot;
  _rtXdot = ((XDot_velocity_controller_real_T *)
             velocity_controller_real_veh_M->derivs);

  // Derivatives for Integrator: '<S39>/Integrator'
  _rtXdot->Integrator_CSTATE = velocity_controller_real_vehi_B.Switch;

  // Derivatives for Integrator: '<S34>/Filter'
  _rtXdot->Filter_CSTATE = velocity_controller_real_vehi_B.FilterCoefficient;
}

// Model initialize function
void velocity_controller_real_vehicle_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&velocity_controller_real_veh_M->solverInfo,
                          &velocity_controller_real_veh_M->Timing.simTimeStep);
    rtsiSetTPtr(&velocity_controller_real_veh_M->solverInfo, &rtmGetTPtr
                (velocity_controller_real_veh_M));
    rtsiSetStepSizePtr(&velocity_controller_real_veh_M->solverInfo,
                       &velocity_controller_real_veh_M->Timing.stepSize0);
    rtsiSetdXPtr(&velocity_controller_real_veh_M->solverInfo,
                 &velocity_controller_real_veh_M->derivs);
    rtsiSetContStatesPtr(&velocity_controller_real_veh_M->solverInfo, (real_T **)
                         &velocity_controller_real_veh_M->contStates);
    rtsiSetNumContStatesPtr(&velocity_controller_real_veh_M->solverInfo,
      &velocity_controller_real_veh_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&velocity_controller_real_veh_M->solverInfo,
      &velocity_controller_real_veh_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&velocity_controller_real_veh_M->solverInfo,
       &velocity_controller_real_veh_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&velocity_controller_real_veh_M->solverInfo,
       &velocity_controller_real_veh_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&velocity_controller_real_veh_M->solverInfo,
                          (&rtmGetErrorStatus(velocity_controller_real_veh_M)));
    rtsiSetRTModelPtr(&velocity_controller_real_veh_M->solverInfo,
                      velocity_controller_real_veh_M);
  }

  rtsiSetSimTimeStep(&velocity_controller_real_veh_M->solverInfo,
                     MAJOR_TIME_STEP);
  velocity_controller_real_veh_M->intgData.y =
    velocity_controller_real_veh_M->odeY;
  velocity_controller_real_veh_M->intgData.f[0] =
    velocity_controller_real_veh_M->odeF[0];
  velocity_controller_real_veh_M->intgData.f[1] =
    velocity_controller_real_veh_M->odeF[1];
  velocity_controller_real_veh_M->intgData.f[2] =
    velocity_controller_real_veh_M->odeF[2];
  velocity_controller_real_veh_M->contStates = ((X_velocity_controller_real_ve_T
    *) &velocity_controller_real_vehi_X);
  rtsiSetSolverData(&velocity_controller_real_veh_M->solverInfo, static_cast<
                    void *>(&velocity_controller_real_veh_M->intgData));
  rtsiSetSolverName(&velocity_controller_real_veh_M->solverInfo,"ode3");
  rtmSetTPtr(velocity_controller_real_veh_M,
             &velocity_controller_real_veh_M->Timing.tArray[0]);
  velocity_controller_real_veh_M->Timing.stepSize0 = 0.02;

  {
    int32_T i;
    char_T b_zeroDelimTopic_1[10];
    char_T b_zeroDelimTopic_0[9];
    char_T b_zeroDelimTopic[5];
    static const char_T tmp[8] = { '/', 'r', 'e', 'l', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[9] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l'
    };

    // InitializeConditions for Integrator: '<S39>/Integrator'
    velocity_controller_real_vehi_X.Integrator_CSTATE =
      velocity_controller_real_vehi_P.PIDController1_InitialConditi_h;

    // InitializeConditions for Integrator: '<S34>/Filter'
    velocity_controller_real_vehi_X.Filter_CSTATE =
      velocity_controller_real_vehi_P.PIDController1_InitialCondition;

    // InitializeConditions for Memory: '<S30>/Memory'
    velocity_controller_real_veh_DW.Memory_PreviousInput =
      velocity_controller_real_vehi_P.Memory_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S56>/Out1' incorporates:
    //   Inport: '<S56>/In1'

    velocity_controller_real_vehi_B.In1_d =
      velocity_controller_real_vehi_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    velocity_controller_real_veh_DW.obj_nq.matlabCodegenIsDeleted = false;
    velocity_controller_real_veh_DW.obj_nq.isInitialized = 1;
    b_zeroDelimTopic[0] = '/';
    b_zeroDelimTopic[1] = 'v';
    b_zeroDelimTopic[2] = 'e';
    b_zeroDelimTopic[3] = 'l';
    b_zeroDelimTopic[4] = '\x00';
    Sub_velocity_controller_real_vehicle_10.createSubscriber(&b_zeroDelimTopic[0],
      1);
    velocity_controller_real_veh_DW.obj_nq.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/relative velocity'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S57>/Out1' incorporates:
    //   Inport: '<S57>/In1'

    velocity_controller_real_vehi_B.In1 =
      velocity_controller_real_vehi_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    velocity_controller_real_veh_DW.obj_n.matlabCodegenIsDeleted = false;
    velocity_controller_real_veh_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic_0[i] = tmp[i];
    }

    b_zeroDelimTopic_0[8] = '\x00';
    Sub_velocity_controller_real_vehicle_34.createSubscriber
      (&b_zeroDelimTopic_0[0], 1);
    velocity_controller_real_veh_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/relative velocity'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    velocity_controller_real_veh_DW.obj.matlabCodegenIsDeleted = false;
    velocity_controller_real_veh_DW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = tmp_0[i];
    }

    b_zeroDelimTopic_1[9] = '\x00';
    Pub_velocity_controller_real_vehicle_3.createPublisher(&b_zeroDelimTopic_1[0],
      1);
    velocity_controller_real_veh_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void velocity_controller_real_vehicle_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!velocity_controller_real_veh_DW.obj_nq.matlabCodegenIsDeleted) {
    velocity_controller_real_veh_DW.obj_nq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/relative velocity'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!velocity_controller_real_veh_DW.obj_n.matlabCodegenIsDeleted) {
    velocity_controller_real_veh_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/relative velocity'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!velocity_controller_real_veh_DW.obj.matlabCodegenIsDeleted) {
    velocity_controller_real_veh_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
