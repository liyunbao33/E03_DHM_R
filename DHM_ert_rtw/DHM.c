/*
 * File: DHM.c
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 24 17:35:14 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DHM.h"
#include "rtwtypes.h"
#include "DHM_types.h"
#include "DHM_private.h"

/* Named constants for Chart: '<S12>/CtrlLogic' */
#define DHM_IN_Fold                    ((uint8_T)1U)
#define DHM_IN_Idle                    ((uint8_T)2U)
#define DHM_IN_Interrupt1              ((uint8_T)3U)
#define DHM_IN_Interrupt2              ((uint8_T)4U)
#define DHM_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define DHM_IN_Start                   ((uint8_T)1U)
#define DHM_IN_Stop                    ((uint8_T)2U)
#define DHM_IN_Unfold                  ((uint8_T)5U)

/* Block signals (default storage) */
B_DHM_T DHM_B;

/* Block states (default storage) */
DW_DHM_T DHM_DW;

/* External inputs (root inport signals with default storage) */
ExtU_DHM_T DHM_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_DHM_T DHM_Y;

/* Real-time model */
static RT_MODEL_DHM_T DHM_M_;
RT_MODEL_DHM_T *const DHM_M = &DHM_M_;

/*
 * System initialize for atomic system:
 *    '<S12>/CtrlLogic'
 *    '<S13>/CtrlLogic'
 */
void DHM_CtrlLogic_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm,
  boolean_T *rty_SO_b_Error)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
  *rty_SO_b_Error = false;
}

/*
 * Output and update for atomic system:
 *    '<S12>/CtrlLogic'
 *    '<S13>/CtrlLogic'
 */
void DHM_CtrlLogic(boolean_T rtu_SI_b_DoorHndFoldReq, boolean_T
                   rtu_SI_b_DoorHndUnfoldReq, uint8_T *rty_SO_e_MotorCmd,
                   uint8_T *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error,
                   DW_CtrlLogic_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_DoorHndUnfoldReq_prev = localDW->SI_b_DoorHndUnfoldReq_start;
  localDW->SI_b_DoorHndUnfoldReq_start = rtu_SI_b_DoorHndUnfoldReq;
  localDW->SI_b_DoorHndFoldReq_prev = localDW->SI_b_DoorHndFoldReq_start;
  localDW->SI_b_DoorHndFoldReq_start = rtu_SI_b_DoorHndFoldReq;

  /* Chart: '<S12>/CtrlLogic' */
  if (localDW->is_active_c1_DoorHndDriver == 0U) {
    localDW->SI_b_DoorHndUnfoldReq_prev = rtu_SI_b_DoorHndUnfoldReq;
    localDW->SI_b_DoorHndFoldReq_prev = rtu_SI_b_DoorHndFoldReq;
    localDW->is_active_c1_DoorHndDriver = 1U;
    localDW->is_Ctrl = DHM_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  } else {
    switch (localDW->is_Ctrl) {
     case DHM_IN_Fold:
      if ((localDW->SI_b_DoorHndUnfoldReq_prev !=
           localDW->SI_b_DoorHndUnfoldReq_start) &&
          localDW->SI_b_DoorHndUnfoldReq_start) {
        localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Interrupt2;
        localDW->temporalCounter_i1 = 0U;

        /*  展开打断折叠  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      } else if (localDW->is_Fold == DHM_IN_Start) {
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = 100U;
        if (localDW->temporalCounter_i1 >= 240) {
          localDW->is_Fold = DHM_IN_Stop;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
          *rty_SO_b_Error = false;
        }
      } else {
        /* case IN_Stop: */
        localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Idle;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     case DHM_IN_Idle:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if ((localDW->SI_b_DoorHndFoldReq_prev !=
           localDW->SI_b_DoorHndFoldReq_start) &&
          localDW->SI_b_DoorHndFoldReq_start) {
        localDW->is_Ctrl = DHM_IN_Fold;

        /*  未学习  */
        localDW->is_Fold = DHM_IN_Start;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = 100U;
      } else if ((localDW->SI_b_DoorHndUnfoldReq_prev !=
                  localDW->SI_b_DoorHndUnfoldReq_start) &&
                 localDW->SI_b_DoorHndUnfoldReq_start) {
        localDW->is_Ctrl = DHM_IN_Unfold;

        /*  未学习  */
        localDW->is_Unfold = DHM_IN_Start;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;

     case DHM_IN_Interrupt1:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if (localDW->temporalCounter_i1 >= 20) {
        /*  delay   */
        localDW->is_Ctrl = DHM_IN_Fold;

        /*  未学习  */
        localDW->is_Fold = DHM_IN_Start;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;

     case DHM_IN_Interrupt2:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if (localDW->temporalCounter_i1 >= 20) {
        /*  delay   */
        localDW->is_Ctrl = DHM_IN_Unfold;

        /*  未学习  */
        localDW->is_Unfold = DHM_IN_Start;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
      }
      break;

     default:
      /* case IN_Unfold: */
      if ((localDW->SI_b_DoorHndFoldReq_prev !=
           localDW->SI_b_DoorHndFoldReq_start) &&
          localDW->SI_b_DoorHndFoldReq_start) {
        localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Interrupt1;
        localDW->temporalCounter_i1 = 0U;

        /*  折叠打断展开  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      } else if (localDW->is_Unfold == DHM_IN_Start) {
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
        if (localDW->temporalCounter_i1 >= 240) {
          localDW->is_Unfold = DHM_IN_Stop;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
          *rty_SO_b_Error = false;
        }
      } else {
        /* case IN_Stop: */
        localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Idle;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S12>/CtrlLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S12>/DoorHndPos'
 *    '<S13>/DoorHndPos'
 */
void DHM_DoorHndPos_Init(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, int16_T
  *rty_SO_s_MaxSoftPos, int16_T *rty_SO_s_MinSoftPos, int16_T
  *rty_SO_s_IceBrkPos)
{
  *rty_SO_m_DoorHndPosSts = Hnd_Fold;
  *rty_SO_s_MaxSoftPos = 0;
  *rty_SO_s_MinSoftPos = 0;
  *rty_SO_s_IceBrkPos = 0;
}

/*
 * Output and update for atomic system:
 *    '<S12>/DoorHndPos'
 *    '<S13>/DoorHndPos'
 */
void DHM_DoorHndPos(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, DW_DoorHndPos_DHM_T
                    *localDW)
{
  /* Chart: '<S12>/DoorHndPos' */
  if (localDW->is_active_c5_DoorHndDriver == 0U) {
    localDW->is_active_c5_DoorHndDriver = 1U;
    *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
  } else {
    *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
  }

  /* End of Chart: '<S12>/DoorHndPos' */
}

/*
 * System initialize for atomic system:
 *    '<S12>/LearnLogic'
 *    '<S13>/LearnLogic'
 */
void DHM_LearnLogic_Init(uint8_T *rty_SO_e_LearnMotorCmd, uint8_T
  *rty_SO_e_LearnMotorPwm, boolean_T *rty_SO_b_CorrectPosToZero, Learn_Sts_E
  *rty_SO_m_LearnSts, int16_T *rty_SO_s_MaxPos, boolean_T *rty_SO_b_Learning)
{
  *rty_SO_e_LearnMotorCmd = 0U;
  *rty_SO_e_LearnMotorPwm = 0U;
  *rty_SO_b_CorrectPosToZero = false;
  *rty_SO_m_LearnSts = Learn_Invalid;
  *rty_SO_s_MaxPos = 0;
  *rty_SO_b_Learning = false;
}

/*
 * System initialize for atomic system:
 *    '<S12>/MotorLogic'
 *    '<S13>/MotorLogic'
 */
void DHM_MotorLogic_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S12>/MotorLogic'
 *    '<S13>/MotorLogic'
 */
void DHM_MotorLogic(uint8_T rtu_SI_e_LearnMotorCmd, uint8_T
                    rtu_SI_e_LearnMotorPwm, uint8_T rtu_SI_e_CtrlMotorCmd,
                    uint8_T rtu_SI_e_CtrlMotorPwm, uint8_T *rty_SO_e_MotorCmd,
                    uint8_T *rty_SO_e_MotorPwm, DW_MotorLogic_DHM_T *localDW)
{
  /* Chart: '<S12>/MotorLogic' */
  if (localDW->is_active_c4_DoorHndDriver == 0U) {
    localDW->is_active_c4_DoorHndDriver = 1U;
    if (rtu_SI_e_LearnMotorCmd != 0) {
      *rty_SO_e_MotorCmd = rtu_SI_e_LearnMotorCmd;
      *rty_SO_e_MotorPwm = rtu_SI_e_LearnMotorPwm;
    } else if (rtu_SI_e_CtrlMotorCmd != 0) {
      *rty_SO_e_MotorCmd = rtu_SI_e_CtrlMotorCmd;
      *rty_SO_e_MotorPwm = rtu_SI_e_CtrlMotorPwm;
    } else {
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
    }
  } else if (rtu_SI_e_LearnMotorCmd != 0) {
    *rty_SO_e_MotorCmd = rtu_SI_e_LearnMotorCmd;
    *rty_SO_e_MotorPwm = rtu_SI_e_LearnMotorPwm;
  } else if (rtu_SI_e_CtrlMotorCmd != 0) {
    *rty_SO_e_MotorCmd = rtu_SI_e_CtrlMotorCmd;
    *rty_SO_e_MotorPwm = rtu_SI_e_CtrlMotorPwm;
  } else {
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  }

  /* End of Chart: '<S12>/MotorLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S12>/Stall'
 *    '<S13>/Stall'
 */
void DHM_Stall_Init(boolean_T *rty_SO_b_HallStall)
{
  *rty_SO_b_HallStall = false;
}

/* Model step function for TID1 */
void DHM_Step(void)                    /* Explicit Task: DHM_Step */
{
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts_a;
  uint8_T rtb_SO_e_MotorCmd_h;
  uint8_T rtb_SO_e_MotorCmd_ns;
  uint8_T rtb_SO_e_MotorPwm_e;
  uint8_T rtb_SO_e_MotorPwm_n;
  boolean_T SO_b_Error_h;

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Chart: '<S12>/DoorHndPos' */
  DHM_DoorHndPos(&rtb_SO_m_DoorHndPosSts_a, &DHM_DW.sf_DoorHndPos);

  /* Chart: '<S12>/CtrlLogic' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Inport: '<Root>/VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   */
  DHM_CtrlLogic(DHM_U.VeINP_CAN_RDoorHandleReq_sig_Ve == 1,
                DHM_U.VeINP_CAN_RDoorHandleReq_sig_Ve == 2,
                &rtb_SO_e_MotorCmd_ns, &rtb_SO_e_MotorPwm_e, &SO_b_Error_h,
                &DHM_DW.sf_CtrlLogic);

  /* Chart: '<S12>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd_p, DHM_B.SO_e_LearnMotorPwm_f,
                 rtb_SO_e_MotorCmd_ns, rtb_SO_e_MotorPwm_e, &rtb_SO_e_MotorCmd_h,
                 &rtb_SO_e_MotorPwm_n, &DHM_DW.sf_MotorLogic);

  /* Outport: '<Root>/VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   */
  DHM_Y.VbOUT_DHM_FRHadUnfold_flg_VbOUT = (rtb_SO_e_MotorCmd_h == 1);

  /* Outport: '<Root>/VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg' incorporates:
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   */
  DHM_Y.VbOUT_DHM_FRHadFold_flg_VbOUT_D = (rtb_SO_e_MotorCmd_h == 2);

  /* Chart: '<S13>/DoorHndPos' */
  DHM_DoorHndPos(&rtb_SO_m_DoorHndPosSts, &DHM_DW.sf_DoorHndPos_g);

  /* Chart: '<S13>/CtrlLogic' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   */
  DHM_CtrlLogic(DHM_U.VeINP_CAN_RRDoorHandleReq_sig_V == 1,
                DHM_U.VeINP_CAN_RRDoorHandleReq_sig_V == 2,
                &rtb_SO_e_MotorCmd_ns, &rtb_SO_e_MotorPwm_e, &SO_b_Error_h,
                &DHM_DW.sf_CtrlLogic_g);

  /* Chart: '<S13>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd, DHM_B.SO_e_LearnMotorPwm,
                 rtb_SO_e_MotorCmd_ns, rtb_SO_e_MotorPwm_e, &rtb_SO_e_MotorCmd_h,
                 &rtb_SO_e_MotorPwm_n, &DHM_DW.sf_MotorLogic_j);

  /* Outport: '<Root>/VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg' incorporates:
   *  Constant: '<S10>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   */
  DHM_Y.VbOUT_DHM_RRHandleUnfold_flg_Vb = (rtb_SO_e_MotorCmd_h == 1);

  /* Outport: '<Root>/VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg' incorporates:
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S11>/Compare'
   */
  DHM_Y.VbOUT_DHM_RRHandleFold_flg_VbOU = (rtb_SO_e_MotorCmd_h == 2);

  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  DHM_Y.VeOUT_DHM_FRDoorHandleSts_sig_V = rtb_SO_m_DoorHndPosSts_a;

  /* DataTypeConversion: '<S3>/Data Type Conversion10' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  DHM_Y.VeOUT_DHM_FRDoorHandleLrnSts_si = DHM_B.SO_m_LearnSts_n;

  /* DataTypeConversion: '<S3>/Data Type Conversion11' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  DHM_Y.VeOUT_DHM_RRDoorHandleLrnSts_si = DHM_B.SO_m_LearnSts;

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  DHM_Y.VeOUT_DHM_RRDoorHandleSts_sig_V = rtb_SO_m_DoorHndPosSts;

  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  DHM_Y.VeOUT_DHM_FRDoorHandleLrnStsEE_ = DHM_Y.VeOUT_DHM_FRDoorHandleLrnSts_si;

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  DHM_Y.VeOUT_DHM_RRDoorHandleLrnStsEE_ = DHM_Y.VeOUT_DHM_RRDoorHandleLrnSts_si;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */
}

/* Model initialize function */
void DHM_initialize(void)
{
  {
    int16_T SO_s_IceBrkPos_f;
    int16_T SO_s_MaxSoftPos_j;
    int16_T SO_s_MinSoftPos_d;
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
    uint8_T rtb_SO_e_MotorCmd_l;
    uint8_T rtb_SO_e_MotorPwm_k;
    boolean_T SO_b_Error_h;
    boolean_T SO_b_Learning_n;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
     *  SubSystem: '<Root>/DHM_Step_sys'
     */

    /* SystemInitialize for Chart: '<S12>/CtrlLogic' */
    DHM_CtrlLogic_Init(&rtb_SO_e_MotorCmd_l, &rtb_SO_e_MotorPwm_k, &SO_b_Error_h);

    /* SystemInitialize for Chart: '<S12>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts, &SO_s_MaxSoftPos_j,
                        &SO_s_MinSoftPos_d, &SO_s_IceBrkPos_f);

    /* SystemInitialize for Chart: '<S12>/LearnLogic' incorporates:
     *  Outport: '<Root>/VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig'
     */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd_p, &DHM_B.SO_e_LearnMotorPwm_f,
                        &SO_b_Error_h, &DHM_B.SO_m_LearnSts_n,
                        &DHM_Y.VsOUT_DHM_FRDoorHandleToEE_sig_, &SO_b_Learning_n);

    /* SystemInitialize for Chart: '<S12>/MotorLogic' */
    DHM_MotorLogic_Init(&rtb_SO_e_MotorCmd_l, &rtb_SO_e_MotorPwm_k);

    /* SystemInitialize for Chart: '<S12>/Stall' */
    DHM_Stall_Init(&SO_b_Error_h);

    /* SystemInitialize for Chart: '<S13>/CtrlLogic' */
    DHM_CtrlLogic_Init(&rtb_SO_e_MotorCmd_l, &rtb_SO_e_MotorPwm_k, &SO_b_Error_h);

    /* SystemInitialize for Chart: '<S13>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts, &SO_s_MaxSoftPos_j,
                        &SO_s_MinSoftPos_d, &SO_s_IceBrkPos_f);

    /* SystemInitialize for Chart: '<S13>/LearnLogic' incorporates:
     *  Outport: '<Root>/VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig'
     */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd, &DHM_B.SO_e_LearnMotorPwm,
                        &SO_b_Error_h, &DHM_B.SO_m_LearnSts,
                        &DHM_Y.VsOUT_DHM_RRDoorHandleToEE_sig_, &SO_b_Learning_n);

    /* SystemInitialize for Chart: '<S13>/MotorLogic' */
    DHM_MotorLogic_Init(&rtb_SO_e_MotorCmd_l, &rtb_SO_e_MotorPwm_k);

    /* SystemInitialize for Chart: '<S13>/Stall' */
    DHM_Stall_Init(&SO_b_Error_h);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */
  }
}

/* Model terminate function */
void DHM_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
