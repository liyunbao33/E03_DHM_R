/*
 * File: DHM.c
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Oct 24 17:38:54 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DHM.h"
#include "rtwtypes.h"
#include "DHM_types.h"
#include "DHM_private.h"
#include "Rte_Type.h"

/* Named constants for Chart: '<S12>/CtrlLogic' */
#define DHM_IN_Fold                    ((uint8)1U)
#define DHM_IN_Idle                    ((uint8)2U)
#define DHM_IN_Interrupt1              ((uint8)3U)
#define DHM_IN_Interrupt2              ((uint8)4U)
#define DHM_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define DHM_IN_Start                   ((uint8)1U)
#define DHM_IN_Stop                    ((uint8)2U)
#define DHM_IN_Unfold                  ((uint8)5U)

/* Block signals (default storage) */
B_DHM_T DHM_B;

/* Block states (default storage) */
DW_DHM_T DHM_DW;

/*
 * System initialize for atomic system:
 *    '<S12>/CtrlLogic'
 *    '<S13>/CtrlLogic'
 */
void DHM_CtrlLogic_Init(uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm,
  boolean *rty_SO_b_Error)
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
void DHM_CtrlLogic(boolean rtu_SI_b_DoorHndFoldReq, boolean
                   rtu_SI_b_DoorHndUnfoldReq, uint8 *rty_SO_e_MotorCmd, uint8
                   *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error,
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
void DHM_DoorHndPos_Init(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, sint16
  *rty_SO_s_MaxSoftPos, sint16 *rty_SO_s_MinSoftPos, sint16 *rty_SO_s_IceBrkPos)
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
void DHM_LearnLogic_Init(uint8 *rty_SO_e_LearnMotorCmd, uint8
  *rty_SO_e_LearnMotorPwm, boolean *rty_SO_b_CorrectPosToZero, Learn_Sts_E
  *rty_SO_m_LearnSts, sint16 *rty_SO_s_MaxPos, boolean *rty_SO_b_Learning)
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
void DHM_MotorLogic_Init(uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_e_MotorPwm = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S12>/MotorLogic'
 *    '<S13>/MotorLogic'
 */
void DHM_MotorLogic(uint8 rtu_SI_e_LearnMotorCmd, uint8 rtu_SI_e_LearnMotorPwm,
                    uint8 rtu_SI_e_CtrlMotorCmd, uint8 rtu_SI_e_CtrlMotorPwm,
                    uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm,
                    DW_MotorLogic_DHM_T *localDW)
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
void DHM_Stall_Init(boolean *rty_SO_b_HallStall)
{
  *rty_SO_b_HallStall = false;
}

/* Model step function for TID1 */
void DHM_Step(void)                    /* Explicit Task: DHM_Step */
{
  /* local block i/o variables */
  SInt16 rtb_TmpSignalConversionAtVsINP_;
  SInt16 rtb_TmpSignalConversionAtVsIN_n;
  uint8 rtb_SO_e_MotorCmd;
  uint8 rtb_SO_e_MotorPwm;
  uint8 rtb_SO_e_MotorCmd_b;
  uint8 rtb_SO_e_MotorPwm_h;
  uint8 rtb_SO_e_MotorCmd_h;
  uint8 rtb_SO_e_MotorPwm_o;
  uint8 rtb_SO_e_MotorCmd_i;
  uint8 rtb_SO_e_MotorPwm_i;
  Boolean rtb_TmpSignalConversionAtVbINP_;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts_i;
  UInt8 rtb_TmpSignalConversionAtVeINP_;
  UInt8 rtb_TmpSignalConversionAtVeIN_k;
  UInt8 tmpRead;
  UInt8 tmpRead_0;
  boolean SO_b_Error_h;

  /* Inport: '<Root>/VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig' */
  (void)
    Rte_Read_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig
    (&tmpRead_0);

  /* Inport: '<Root>/VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig' */
  (void)
    Rte_Read_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig
    (&tmpRead);

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* DataStoreWrite: '<S3>/Data Store Write' incorporates:
   *  Constant: '<S3>/Constant'
   */
  DHM_DW.E03_DHM_R = 1U;

  /* SignalConversion generated from: '<S2>/VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig_read' incorporates:
   *  Inport: '<Root>/VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig'
   */
  (void)Rte_Read_VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig
    (&rtb_TmpSignalConversionAtVeINP_);

  /* SignalConversion generated from: '<S2>/VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig_read' incorporates:
   *  Inport: '<Root>/VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig'
   */
  (void)Rte_Read_VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig
    (&rtb_TmpSignalConversionAtVeIN_k);

  /* SignalConversion generated from: '<S2>/VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg'
   */
  (void)Rte_Read_VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg
    (&rtb_TmpSignalConversionAtVbINP_);

  /* SignalConversion generated from: '<S2>/VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig_read' incorporates:
   *  Inport: '<Root>/VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig'
   */
  (void)Rte_Read_VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig
    (&rtb_TmpSignalConversionAtVsINP_);

  /* Chart: '<S12>/DoorHndPos' */
  DHM_DoorHndPos(&rtb_SO_m_DoorHndPosSts_i, &DHM_DW.sf_DoorHndPos);

  /* Chart: '<S12>/CtrlLogic' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   */
  DHM_CtrlLogic(rtb_TmpSignalConversionAtVeINP_ == 1,
                rtb_TmpSignalConversionAtVeINP_ == 2, &rtb_SO_e_MotorCmd_i,
                &rtb_SO_e_MotorPwm_i, &SO_b_Error_h, &DHM_DW.sf_CtrlLogic);

  /* Chart: '<S12>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd_p, DHM_B.SO_e_LearnMotorPwm_f,
                 rtb_SO_e_MotorCmd_i, rtb_SO_e_MotorPwm_i, &rtb_SO_e_MotorCmd_h,
                 &rtb_SO_e_MotorPwm_o, &DHM_DW.sf_MotorLogic);

  /* SignalConversion generated from: '<S2>/VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig_read' incorporates:
   *  Inport: '<Root>/VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig'
   */
  (void)Rte_Read_VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig
    (&rtb_TmpSignalConversionAtVsIN_n);

  /* Chart: '<S13>/DoorHndPos' */
  DHM_DoorHndPos(&rtb_SO_m_DoorHndPosSts, &DHM_DW.sf_DoorHndPos_g);

  /* Chart: '<S13>/CtrlLogic' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   */
  DHM_CtrlLogic(rtb_TmpSignalConversionAtVeIN_k == 1,
                rtb_TmpSignalConversionAtVeIN_k == 2, &rtb_SO_e_MotorCmd_b,
                &rtb_SO_e_MotorPwm_h, &SO_b_Error_h, &DHM_DW.sf_CtrlLogic_g);

  /* Chart: '<S13>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd, DHM_B.SO_e_LearnMotorPwm,
                 rtb_SO_e_MotorCmd_b, rtb_SO_e_MotorPwm_h, &rtb_SO_e_MotorCmd,
                 &rtb_SO_e_MotorPwm, &DHM_DW.sf_MotorLogic_j);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  (void)Rte_Write_VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig
    (rtb_SO_m_DoorHndPosSts_i);

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  (void)Rte_Write_VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig
    (rtb_SO_m_DoorHndPosSts);

  /* Outport: '<Root>/VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   */
  (void)Rte_Write_VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg
    (rtb_SO_e_MotorCmd_h == 1);

  /* Outport: '<Root>/VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg' incorporates:
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   */
  (void)Rte_Write_VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg
    (rtb_SO_e_MotorCmd_h == 2);

  /* Outport: '<Root>/VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg' incorporates:
   *  Constant: '<S10>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   */
  (void)Rte_Write_VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg
    (rtb_SO_e_MotorCmd == 1);

  /* Outport: '<Root>/VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg' incorporates:
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S11>/Compare'
   */
  (void)Rte_Write_VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg
    (rtb_SO_e_MotorCmd == 2);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* Outport: '<Root>/VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig' */
  (void)Rte_Write_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig
    (DHM_B.SO_s_MaxPos_l);

  /* Outport: '<Root>/VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig' */
  (void)Rte_Write_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig
    (DHM_B.SO_s_MaxPos);

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleLrnSts_sig_VeOUT_DHM_FRDoorHandleLrnSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   */
  (void)
    Rte_Write_VeOUT_DHM_FRDoorHandleLrnSts_sig_VeOUT_DHM_FRDoorHandleLrnSts_sig
    (DHM_B.SO_m_LearnSts_n);

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleLrnSts_sig_VeOUT_DHM_RRDoorHandleLrnSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion11'
   */
  (void)
    Rte_Write_VeOUT_DHM_RRDoorHandleLrnSts_sig_VeOUT_DHM_RRDoorHandleLrnSts_sig
    (DHM_B.SO_m_LearnSts);

  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  (void)
    Rte_Write_VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig
    (DHM_B.SO_m_LearnSts_n);

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  (void)
    Rte_Write_VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig
    (DHM_B.SO_m_LearnSts);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */
}

/* Model initialize function */
void DHM_Init(void)
{
  {
    /* local block i/o variables */
    uint8 rtb_SO_e_MotorCmd;
    uint8 rtb_SO_e_MotorPwm;
    uint8 rtb_SO_e_MotorCmd_b;
    uint8 rtb_SO_e_MotorPwm_h;
    uint8 rtb_SO_e_MotorCmd_h;
    uint8 rtb_SO_e_MotorPwm_o;
    uint8 rtb_SO_e_MotorCmd_i;
    uint8 rtb_SO_e_MotorPwm_i;
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts_i;
    boolean SO_b_Error_h;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
     *  SubSystem: '<Root>/DHM_Step_sys'
     */

    /* SystemInitialize for Chart: '<S12>/CtrlLogic' */
    DHM_CtrlLogic_Init(&rtb_SO_e_MotorCmd_i, &rtb_SO_e_MotorPwm_i, &SO_b_Error_h);

    /* SystemInitialize for Chart: '<S12>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts_i, &DHM_B.SO_s_MaxSoftPos_j,
                        &DHM_B.SO_s_MinSoftPos_d, &DHM_B.SO_s_IceBrkPos_f);

    /* SystemInitialize for Chart: '<S12>/LearnLogic' */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd_p, &DHM_B.SO_e_LearnMotorPwm_f,
                        &SO_b_Error_h, &DHM_B.SO_m_LearnSts_n,
                        &DHM_B.SO_s_MaxPos_l, &DHM_B.SO_b_Learning_n);

    /* SystemInitialize for Chart: '<S12>/MotorLogic' */
    DHM_MotorLogic_Init(&rtb_SO_e_MotorCmd_h, &rtb_SO_e_MotorPwm_o);

    /* SystemInitialize for Chart: '<S12>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall_g);

    /* SystemInitialize for Chart: '<S13>/CtrlLogic' */
    DHM_CtrlLogic_Init(&rtb_SO_e_MotorCmd_b, &rtb_SO_e_MotorPwm_h, &SO_b_Error_h);

    /* SystemInitialize for Chart: '<S13>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts, &DHM_B.SO_s_MaxSoftPos,
                        &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos);

    /* SystemInitialize for Chart: '<S13>/LearnLogic' */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd, &DHM_B.SO_e_LearnMotorPwm,
                        &SO_b_Error_h, &DHM_B.SO_m_LearnSts, &DHM_B.SO_s_MaxPos,
                        &DHM_B.SO_b_Learning);

    /* SystemInitialize for Chart: '<S13>/MotorLogic' */
    DHM_MotorLogic_Init(&rtb_SO_e_MotorCmd, &rtb_SO_e_MotorPwm);

    /* SystemInitialize for Chart: '<S13>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

    /* SystemInitialize for Outport: '<Root>/VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig' */
    (void)
      Rte_Write_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig
      (DHM_B.SO_s_MaxPos_l);

    /* SystemInitialize for Outport: '<Root>/VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig' */
    (void)
      Rte_Write_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig
      (DHM_B.SO_s_MaxPos);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
