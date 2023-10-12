/*
 * File: DHM.c
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.69
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 12 20:08:56 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DHM.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "DHM_types.h"
#include "DHM_private.h"

/* Named constants for Chart: '<S8>/CtrlLogic' */
#define DHM_IN_Check                   ((uint8)1U)
#define DHM_IN_Fold                    ((uint8)1U)
#define DHM_IN_IceBrk                  ((uint8)2U)
#define DHM_IN_IceBrkSuccess           ((uint8)3U)
#define DHM_IN_Icebreak                ((uint8)1U)
#define DHM_IN_Idle                    ((uint8)2U)
#define DHM_IN_Interrupt1              ((uint8)3U)
#define DHM_IN_Interrupt2              ((uint8)4U)
#define DHM_IN_NO_ACTIVE_CHILD         ((uint8)0U)
#define DHM_IN_Start                   ((uint8)2U)
#define DHM_IN_Start_c                 ((uint8)1U)
#define DHM_IN_Step1                   ((uint8)3U)
#define DHM_IN_Step1_g                 ((uint8)2U)
#define DHM_IN_Step2                   ((uint8)4U)
#define DHM_IN_Step2_f                 ((uint8)3U)
#define DHM_IN_Step3                   ((uint8)5U)
#define DHM_IN_Step3_c                 ((uint8)4U)
#define DHM_IN_Stop                    ((uint8)6U)
#define DHM_IN_Stop_c                  ((uint8)5U)
#define DHM_IN_Unfold                  ((uint8)5U)

/* Named constants for Chart: '<S8>/LearnLogic' */
#define DHM_IN_Check_p                 ((uint8)1U)
#define DHM_IN_CorrectZeroPos          ((uint8)2U)
#define DHM_IN_Delay                   ((uint8)3U)
#define DHM_IN_Failed                  ((uint8)4U)
#define DHM_IN_Finished                ((uint8)5U)
#define DHM_IN_GotoMaxPos1             ((uint8)6U)
#define DHM_IN_GotoZeroPos             ((uint8)7U)
#define DHM_IN_Idle_f                  ((uint8)8U)
#define DHM_IN_LearnLogic              ((uint8)1U)
#define DHM_IN_PowerOn                 ((uint8)2U)

/* Named constants for Chart: '<S8>/Stall' */
#define DHM_IN_Checking                ((uint8)1U)
#define DHM_IN_Idle_fo                 ((uint8)2U)
#define DHM_IN_Stall                   ((uint8)3U)

/* Block signals (default storage) */
B_DHM_T DHM_B;

/* Block states (default storage) */
DW_DHM_T DHM_DW;

/* Forward declaration for local functions */
static void DHM_Unfold(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxSoftPos,
  sint16 rtu_SI_s_IceBrkPos, boolean rtu_SI_b_Learning, uint8 *rty_SO_e_MotorCmd,
  uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error, DW_CtrlLogic_DHM_T *localDW);

/* Forward declaration for local functions */
static float64 DHM_GetPosSts(float64 CurrentPos, float64 MinSoftPos, float64
  MaxSoftPos);
static uint8 DHM_safe_cast_to_HndPos_Sts_E(uint8 input);

/* Function for Chart: '<S8>/CtrlLogic' */
static void DHM_Unfold(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxSoftPos,
  sint16 rtu_SI_s_IceBrkPos, boolean rtu_SI_b_Learning, uint8 *rty_SO_e_MotorCmd,
  uint8 *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error, DW_CtrlLogic_DHM_T *localDW)
{
  if ((localDW->SI_b_DoorHndFoldReq_prev != localDW->SI_b_DoorHndFoldReq_start) &&
      localDW->SI_b_DoorHndFoldReq_start) {
    localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Ctrl = DHM_IN_Interrupt1;
    localDW->temporalCounter_i1 = 0U;

    /*  �۵����չ��  */
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  } else if (rtu_SI_b_Learning) {
    localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Ctrl = DHM_IN_Idle;
    *rty_SO_e_MotorCmd = 0U;
    *rty_SO_e_MotorPwm = 0U;
  } else {
    switch (localDW->is_Unfold) {
     case DHM_IN_Icebreak:
      {
        switch (localDW->is_Icebreak) {
         case DHM_IN_Check:
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
          if (rtu_SI_s_CurrentPos > rtu_SI_s_IceBrkPos) {
            localDW->is_Icebreak = DHM_IN_IceBrkSuccess;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_e_MotorPwm = 100U;
          } else if (localDW->SL_e_CycleCount >= 3) {
            *rty_SO_b_Error = true;

            /*  �Ʊ��ﵽָ������������  */
            localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Ctrl = DHM_IN_Idle;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
          } else if (localDW->temporalCounter_i1 >= 50) {
            localDW->is_Icebreak = DHM_IN_IceBrk;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_e_MotorPwm = 100U;
          }
          break;

         case DHM_IN_IceBrk:
          {
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_e_MotorPwm = 100U;
            if (localDW->temporalCounter_i1 >= 50) {
              sint32 tmp;
              localDW->is_Icebreak = DHM_IN_Check;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_e_MotorCmd = 0U;
              *rty_SO_e_MotorPwm = 0U;
              tmp = localDW->SL_e_CycleCount + 1;
              if (localDW->SL_e_CycleCount + 1 > 255) {
                tmp = 255;
              }

              localDW->SL_e_CycleCount = (uint8)tmp;
            }
          }
          break;

         default:
          /* case IN_IceBrkSuccess: */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 100U;
          if (localDW->temporalCounter_i1 >= 10) {
            localDW->SL_e_IceBrkCount = 0U;

            /*  �Ʊ����  */
            localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Unfold = DHM_IN_Step2;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 1U;
            *rty_SO_e_MotorPwm = 85U;
          }
          break;
        }
      }
      break;

     case DHM_IN_Start:
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 100U;
      if (localDW->temporalCounter_i1 >= 240) {
        localDW->is_Unfold = DHM_IN_Stop;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_b_Error = false;
      }
      break;

     case DHM_IN_Step1:
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 60U;
      if (localDW->temporalCounter_i1 >= 20) {
        localDW->is_Unfold = DHM_IN_Step2;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 85U;
      }
      break;

     case DHM_IN_Step2:
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 85U;
      if (rtu_SI_s_CurrentPos >= rtu_SI_s_MaxSoftPos) {
        localDW->is_Unfold = DHM_IN_Step3;
        localDW->temporalCounter_i1 = 0U;

        /*  ��ͣ  */
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 60U;
      } else if ((localDW->temporalCounter_i1 >= 130) &&
                 (localDW->SL_e_IceBrkCount <= 0) && (rtu_SI_s_CurrentPos <
                  rtu_SI_s_IceBrkPos)) {
        localDW->SL_e_IceBrkCount = 1U;
        localDW->is_Unfold = DHM_IN_Icebreak;
        localDW->SL_e_CycleCount = 0U;
        localDW->is_Icebreak = DHM_IN_IceBrk;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = 100U;
      } else if (localDW->temporalCounter_i1 >= 200) {
        /*  ��ʱ����  */
        localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Idle;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      }
      break;

     case DHM_IN_Step3:
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = 60U;
      if (localDW->temporalCounter_i1 >= 20) {
        localDW->is_Unfold = DHM_IN_Stop;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        *rty_SO_b_Error = false;
      }
      break;

     default:
      /* case IN_Stop: */
      localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
      localDW->is_Ctrl = DHM_IN_Idle;
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      break;
    }
  }
}

/*
 * System initialize for atomic system:
 *    '<S8>/CtrlLogic'
 *    '<S9>/CtrlLogic'
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
 *    '<S8>/CtrlLogic'
 *    '<S9>/CtrlLogic'
 */
void DHM_CtrlLogic(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxSoftPos,
                   sint16 rtu_SI_s_MinSoftPos, sint16 rtu_SI_s_IceBrkPos,
                   boolean rtu_SI_b_DoorHndFoldReq, boolean
                   rtu_SI_b_DoorHndUnfoldReq, Learn_Sts_E rtu_SI_m_LearnSts,
                   boolean rtu_SI_b_Learning, uint8 *rty_SO_e_MotorCmd, uint8
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

  /* Chart: '<S8>/CtrlLogic' */
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

        /*  չ������۵�  */
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      } else if (rtu_SI_b_Learning) {
        localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
        localDW->is_Ctrl = DHM_IN_Idle;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
      } else {
        switch (localDW->is_Fold) {
         case DHM_IN_Start_c:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 100U;
          if (localDW->temporalCounter_i1 >= 240) {
            localDW->is_Fold = DHM_IN_Stop_c;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
            *rty_SO_b_Error = false;
          }
          break;

         case DHM_IN_Step1_g:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
          if (localDW->temporalCounter_i1 >= 20) {
            localDW->is_Fold = DHM_IN_Step2_f;
            localDW->temporalCounter_i1 = 0U;
            *rty_SO_e_MotorCmd = 2U;
            *rty_SO_e_MotorPwm = 85U;
          }
          break;

         case DHM_IN_Step2_f:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 85U;
          if (rtu_SI_s_CurrentPos <= rtu_SI_s_MinSoftPos) {
            localDW->is_Fold = DHM_IN_Step3_c;
            localDW->temporalCounter_i1 = 0U;

            /*  ��ͣ  */
            *rty_SO_e_MotorCmd = 2U;
            *rty_SO_e_MotorPwm = 60U;
          } else if (localDW->temporalCounter_i1 >= 200) {
            /*  ��ʱ����  */
            localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
            localDW->is_Ctrl = DHM_IN_Idle;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
          }
          break;

         case DHM_IN_Step3_c:
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
          if (localDW->temporalCounter_i1 >= 20) {
            localDW->is_Fold = DHM_IN_Stop_c;
            *rty_SO_e_MotorCmd = 0U;
            *rty_SO_e_MotorPwm = 0U;
            *rty_SO_b_Error = false;
          }
          break;

         default:
          /* case IN_Stop: */
          localDW->is_Fold = DHM_IN_NO_ACTIVE_CHILD;
          localDW->is_Ctrl = DHM_IN_Idle;
          *rty_SO_e_MotorCmd = 0U;
          *rty_SO_e_MotorPwm = 0U;
          break;
        }
      }
      break;

     case DHM_IN_Idle:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if ((localDW->SI_b_DoorHndFoldReq_prev !=
           localDW->SI_b_DoorHndFoldReq_start) &&
          localDW->SI_b_DoorHndFoldReq_start) {
        localDW->is_Ctrl = DHM_IN_Fold;
        if (rtu_SI_m_LearnSts == Learn_Success) {
          /*  ��ѧϰ  */
          localDW->is_Fold = DHM_IN_Step1_g;
          localDW->temporalCounter_i1 = 0U;

          /*  ����  */
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  δѧϰ  */
          localDW->is_Fold = DHM_IN_Start_c;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 100U;
        }
      } else if ((localDW->SI_b_DoorHndUnfoldReq_prev !=
                  localDW->SI_b_DoorHndUnfoldReq_start) &&
                 localDW->SI_b_DoorHndUnfoldReq_start) {
        localDW->is_Ctrl = DHM_IN_Unfold;
        if (rtu_SI_m_LearnSts == Learn_Success) {
          /*  ��ѧϰ  */
          localDW->is_Unfold = DHM_IN_Step1;
          localDW->temporalCounter_i1 = 0U;

          /*  ����  */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  δѧϰ  */
          localDW->is_Unfold = DHM_IN_Start;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 100U;
        }
      }
      break;

     case DHM_IN_Interrupt1:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if (localDW->temporalCounter_i1 >= 20) {
        /*  delay   */
        localDW->is_Ctrl = DHM_IN_Fold;
        if (rtu_SI_m_LearnSts == Learn_Success) {
          /*  ��ѧϰ  */
          localDW->is_Fold = DHM_IN_Step1_g;
          localDW->temporalCounter_i1 = 0U;

          /*  ����  */
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  δѧϰ  */
          localDW->is_Fold = DHM_IN_Start_c;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 100U;
        }
      }
      break;

     case DHM_IN_Interrupt2:
      *rty_SO_e_MotorCmd = 0U;
      *rty_SO_e_MotorPwm = 0U;
      if (localDW->temporalCounter_i1 >= 20) {
        /*  delay   */
        localDW->is_Ctrl = DHM_IN_Unfold;
        if (rtu_SI_m_LearnSts == Learn_Success) {
          /*  ��ѧϰ  */
          localDW->is_Unfold = DHM_IN_Step1;
          localDW->temporalCounter_i1 = 0U;

          /*  ����  */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  δѧϰ  */
          localDW->is_Unfold = DHM_IN_Start;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 100U;
        }
      }
      break;

     default:
      /* case IN_Unfold: */
      DHM_Unfold(rtu_SI_s_CurrentPos, rtu_SI_s_MaxSoftPos, rtu_SI_s_IceBrkPos,
                 rtu_SI_b_Learning, rty_SO_e_MotorCmd, rty_SO_e_MotorPwm,
                 rty_SO_b_Error, localDW);
      break;
    }
  }

  /* End of Chart: '<S8>/CtrlLogic' */
}

/* Function for Chart: '<S8>/DoorHndPos' */
static float64 DHM_GetPosSts(float64 CurrentPos, float64 MinSoftPos, float64
  MaxSoftPos)
{
  float64 y;
  if (CurrentPos <= MinSoftPos) {
    y = 0.0;
  } else if (CurrentPos >= MaxSoftPos) {
    y = 1.0;
  } else {
    y = 2.0;
  }

  return y;
}

static uint8 DHM_safe_cast_to_HndPos_Sts_E(uint8 input)
{
  uint8 output;

  /* Initialize output value to default value for HndPos_Sts_E (Hnd_Fold) */
  output = 0U;
  if (input <= 3) {
    /* Set output value to input value if it is a member of HndPos_Sts_E */
    output = input;
  }

  return output;
}

/*
 * System initialize for atomic system:
 *    '<S8>/DoorHndPos'
 *    '<S9>/DoorHndPos'
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
 *    '<S8>/DoorHndPos'
 *    '<S9>/DoorHndPos'
 */
void DHM_DoorHndPos(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxPos,
                    Learn_Sts_E rtu_SI_m_LearnSts, HndPos_Sts_E
                    *rty_SO_m_DoorHndPosSts, sint16 *rty_SO_s_MaxSoftPos, sint16
                    *rty_SO_s_MinSoftPos, sint16 *rty_SO_s_IceBrkPos,
                    DW_DoorHndPos_DHM_T *localDW)
{
  /* Chart: '<S8>/DoorHndPos' */
  if (localDW->is_active_c5_DoorHndDriver == 0U) {
    localDW->is_active_c5_DoorHndDriver = 1U;
    if (rtu_SI_m_LearnSts == Learn_Success) {
      float64 tmp;
      *rty_SO_s_MaxSoftPos = (sint16)(rtu_SI_s_MaxPos * 95 / 100);
      *rty_SO_s_MinSoftPos = (sint16)(rtu_SI_s_MaxPos * 5 / 100);
      *rty_SO_s_IceBrkPos = (sint16)(rtu_SI_s_MaxPos * 20 / 100);
      tmp = DHM_GetPosSts((float64)rtu_SI_s_CurrentPos, (float64)*
                          rty_SO_s_MinSoftPos, (float64)*rty_SO_s_MaxSoftPos);
      if (tmp < 2.147483648E+9) {
        if (tmp >= -2.147483648E+9) {
          *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8)(sint32)
            tmp);
        } else {
          *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
        }
      } else {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
      }
    } else {
      *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
    }
  } else if (rtu_SI_m_LearnSts == Learn_Success) {
    float64 tmp;
    *rty_SO_s_MaxSoftPos = (sint16)(rtu_SI_s_MaxPos * 95 / 100);
    *rty_SO_s_MinSoftPos = (sint16)(rtu_SI_s_MaxPos * 5 / 100);
    *rty_SO_s_IceBrkPos = (sint16)(rtu_SI_s_MaxPos * 20 / 100);
    tmp = DHM_GetPosSts((float64)rtu_SI_s_CurrentPos, (float64)*
                        rty_SO_s_MinSoftPos, (float64)*rty_SO_s_MaxSoftPos);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8)(sint32)
          tmp);
      } else {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
      }
    } else {
      *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
    }
  } else {
    *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
  }

  /* End of Chart: '<S8>/DoorHndPos' */
}

/*
 * System initialize for atomic system:
 *    '<S8>/LearnLogic'
 *    '<S9>/LearnLogic'
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
 * Output and update for atomic system:
 *    '<S8>/LearnLogic'
 *    '<S9>/LearnLogic'
 */
void DHM_LearnLogic(boolean rtu_SI_b_HallStall, Boolean rtu_SI_b_LearnReq,
                    Learn_Sts_E rtu_SI_m_LearnStsFromEE, sint16
                    rtu_SI_s_MaxPosFromEE, SInt16 rtu_SI_s_CurrentPos, uint8
                    *rty_SO_e_LearnMotorCmd, uint8 *rty_SO_e_LearnMotorPwm,
                    boolean *rty_SO_b_CorrectPosToZero, Learn_Sts_E
                    *rty_SO_m_LearnSts, sint16 *rty_SO_s_MaxPos, boolean
                    *rty_SO_b_Learning, DW_LearnLogic_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 511U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_LearnReq_prev = localDW->SI_b_LearnReq_start;
  localDW->SI_b_LearnReq_start = rtu_SI_b_LearnReq;

  /* Chart: '<S8>/LearnLogic' */
  if (localDW->is_active_c3_DoorHndDriver == 0U) {
    localDW->SI_b_LearnReq_prev = rtu_SI_b_LearnReq;
    localDW->is_active_c3_DoorHndDriver = 1U;
    localDW->is_c3_DoorHndDriver = DHM_IN_PowerOn;
    localDW->temporalCounter_i1 = 0U;
    localDW->SL_e_AutoLearnCount = 2U;

    /* �ϵ��Զ�ѧϰ */
    *rty_SO_s_MaxPos = rtu_SI_s_MaxPosFromEE;
    *rty_SO_m_LearnSts = rtu_SI_m_LearnStsFromEE;
  } else if (localDW->is_c3_DoorHndDriver == DHM_IN_LearnLogic) {
    boolean guard1 = false;
    guard1 = false;
    switch (localDW->is_LearnLogic) {
     case DHM_IN_Check_p:
      /*   */
      if ((rtu_SI_s_CurrentPos == 0) && (*rty_SO_s_MaxPos > 400)) {
        localDW->is_LearnLogic = DHM_IN_Finished;
        localDW->temporalCounter_i1 = 0U;

        /*  ѧϰ�ɹ�  */
        *rty_SO_m_LearnSts = Learn_Success;
      } else {
        localDW->is_LearnLogic = DHM_IN_Failed;
        localDW->temporalCounter_i1 = 0U;

        /*  ѧϰʧ��  */
        *rty_SO_e_LearnMotorCmd = 0U;
        *rty_SO_e_LearnMotorPwm = 0U;
        *rty_SO_m_LearnSts = Learn_Fail;
      }
      break;

     case DHM_IN_CorrectZeroPos:
      if (localDW->temporalCounter_i1 >= 20) {
        localDW->is_LearnLogic = DHM_IN_Check_p;

        /*  ѧϰ����ж�  */
      }
      break;

     case DHM_IN_Delay:
      if (localDW->temporalCounter_i1 >= 200) {
        localDW->is_LearnLogic = DHM_IN_GotoZeroPos;
        localDW->temporalCounter_i1 = 0U;

        /*  �۵�  */
        *rty_SO_e_LearnMotorCmd = 2U;
        *rty_SO_e_LearnMotorPwm = 100U;
      }
      break;

     case DHM_IN_Failed:
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_LearnLogic = DHM_IN_Idle_f;
        *rty_SO_b_Learning = false;
        *rty_SO_e_LearnMotorCmd = 0U;
        *rty_SO_e_LearnMotorPwm = 0U;
        *rty_SO_b_CorrectPosToZero = false;
      }
      break;

     case DHM_IN_Finished:
      if (localDW->temporalCounter_i1 >= 3) {
        localDW->is_LearnLogic = DHM_IN_Idle_f;
        *rty_SO_b_Learning = false;
        *rty_SO_e_LearnMotorCmd = 0U;
        *rty_SO_e_LearnMotorPwm = 0U;
        *rty_SO_b_CorrectPosToZero = false;
      }
      break;

     case DHM_IN_GotoMaxPos1:
      {
        if (rtu_SI_b_HallStall) {
          sint16 tmp;
          tmp = rtu_SI_s_CurrentPos;
          if (rtu_SI_s_CurrentPos < 0) {
            tmp = 0;
          } else if (rtu_SI_s_CurrentPos > 255) {
            tmp = 255;
          }

          localDW->SL_e_tempPos = (uint8)tmp;
          localDW->is_LearnLogic = DHM_IN_Delay;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
        } else if (localDW->temporalCounter_i1 >= 400) {
          localDW->is_LearnLogic = DHM_IN_Failed;
          localDW->temporalCounter_i1 = 0U;

          /*  ѧϰʧ��  */
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
          *rty_SO_m_LearnSts = Learn_Fail;
        } else {
          /*  չ��  */
          *rty_SO_b_Learning = true;
          *rty_SO_e_LearnMotorCmd = 1U;
          *rty_SO_e_LearnMotorPwm = 100U;
        }
      }
      break;

     case DHM_IN_GotoZeroPos:
      {
        if (localDW->temporalCounter_i1 >= 400) {
          localDW->is_LearnLogic = DHM_IN_Failed;
          localDW->temporalCounter_i1 = 0U;

          /*  ѧϰʧ��  */
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
          *rty_SO_m_LearnSts = Learn_Fail;
        } else if (rtu_SI_b_HallStall) {
          sint32 tmp_0;
          tmp_0 = rtu_SI_s_CurrentPos - localDW->SL_e_tempPos;
          if (tmp_0 < -32768) {
            tmp_0 = -32768;
          }

          *rty_SO_s_MaxPos = (sint16)tmp_0;
          localDW->is_LearnLogic = DHM_IN_CorrectZeroPos;
          localDW->temporalCounter_i1 = 0U;

          /*  ���У׼  */
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
          *rty_SO_b_CorrectPosToZero = true;
        } else {
          /*  �۵�  */
          *rty_SO_e_LearnMotorCmd = 2U;
          *rty_SO_e_LearnMotorPwm = 100U;
        }
      }
      break;

     default:
      /* case IN_Idle: */
      if ((*rty_SO_m_LearnSts != Learn_Success) && (localDW->SL_e_AutoLearnCount
           > 0)) {
        localDW->SL_e_AutoLearnCount--;
        guard1 = true;
      } else if ((localDW->SI_b_LearnReq_prev != localDW->SI_b_LearnReq_start) &&
                 localDW->SI_b_LearnReq_start) {
        guard1 = true;
      }
      break;
    }

    if (guard1) {
      localDW->is_LearnLogic = DHM_IN_GotoMaxPos1;
      localDW->temporalCounter_i1 = 0U;

      /*  չ��  */
      *rty_SO_b_Learning = true;
      *rty_SO_e_LearnMotorCmd = 1U;
      *rty_SO_e_LearnMotorPwm = 100U;
    }

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 50) {
    /*  500ms�ڶ�ȡE2ѧϰ״̬�����hallλ��  */
    localDW->is_c3_DoorHndDriver = DHM_IN_LearnLogic;
    localDW->is_LearnLogic = DHM_IN_Idle_f;
    *rty_SO_b_Learning = false;
    *rty_SO_e_LearnMotorCmd = 0U;
    *rty_SO_e_LearnMotorPwm = 0U;
    *rty_SO_b_CorrectPosToZero = false;
  } else {
    localDW->SL_e_AutoLearnCount = 2U;

    /* �ϵ��Զ�ѧϰ */
    *rty_SO_s_MaxPos = rtu_SI_s_MaxPosFromEE;
    *rty_SO_m_LearnSts = rtu_SI_m_LearnStsFromEE;
  }

  /* End of Chart: '<S8>/LearnLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S8>/MotorLogic'
 *    '<S9>/MotorLogic'
 */
void DHM_MotorLogic_Init(uint8 *rty_SO_e_MotorCmd, boolean *rty_SO_b_MotorA,
  boolean *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorPwm)
{
  *rty_SO_e_MotorCmd = 0U;
  *rty_SO_b_MotorA = false;
  *rty_SO_b_MotorB = false;
  *rty_SO_e_MotorPwm = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S8>/MotorLogic'
 *    '<S9>/MotorLogic'
 */
void DHM_MotorLogic(uint8 rtu_SI_e_LearnMotorCmd, uint8 rtu_SI_e_LearnMotorPwm,
                    uint8 rtu_SI_e_CtrlMotorCmd, uint8 rtu_SI_e_CtrlMotorPwm,
                    uint8 *rty_SO_e_MotorCmd, boolean *rty_SO_b_MotorA, uint8
                    *rty_SO_e_MotorPwm, DW_MotorLogic_DHM_T *localDW)
{
  /* Chart: '<S8>/MotorLogic' */
  if (localDW->is_active_c4_DoorHndDriver == 0U) {
    localDW->is_active_c4_DoorHndDriver = 1U;
    switch (rtu_SI_e_LearnMotorCmd) {
     case 1:
      *rty_SO_b_MotorA = false;
      *rty_SO_e_MotorCmd = 1U;
      *rty_SO_e_MotorPwm = rtu_SI_e_LearnMotorPwm;
      break;

     case 2:
      *rty_SO_b_MotorA = true;
      *rty_SO_e_MotorCmd = 2U;
      *rty_SO_e_MotorPwm = rtu_SI_e_LearnMotorPwm;
      break;

     default:
      switch (rtu_SI_e_CtrlMotorCmd) {
       case 1:
        *rty_SO_b_MotorA = false;
        *rty_SO_e_MotorCmd = 1U;
        *rty_SO_e_MotorPwm = rtu_SI_e_CtrlMotorPwm;
        break;

       case 2:
        *rty_SO_b_MotorA = true;
        *rty_SO_e_MotorCmd = 2U;
        *rty_SO_e_MotorPwm = rtu_SI_e_CtrlMotorPwm;
        break;

       default:
        *rty_SO_b_MotorA = false;
        *rty_SO_e_MotorCmd = 0U;
        *rty_SO_e_MotorPwm = 0U;
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/MotorLogic' */
}

/*
 * System initialize for atomic system:
 *    '<S8>/Stall'
 *    '<S9>/Stall'
 */
void DHM_Stall_Init(boolean *rty_SO_b_HallStall)
{
  *rty_SO_b_HallStall = false;
}

/*
 * Output and update for atomic system:
 *    '<S8>/Stall'
 *    '<S9>/Stall'
 */
void DHM_Stall(SInt16 rtu_SI_s_CurrentPos, uint8 rtu_SI_e_MotorCmd, boolean
               *rty_SO_b_HallStall, DW_Stall_DHM_T *localDW)
{
  if (localDW->temporalCounter_i1 < 31U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S8>/Stall' */
  if (localDW->is_active_c2_DoorHndDriver == 0U) {
    localDW->is_active_c2_DoorHndDriver = 1U;
    localDW->is_Stall_Handler = DHM_IN_Idle_fo;
    *rty_SO_b_HallStall = false;
  } else {
    switch (localDW->is_Stall_Handler) {
     case DHM_IN_Checking:
      if (rtu_SI_e_MotorCmd == 0) {
        localDW->is_Stall_Handler = DHM_IN_Idle_fo;
        *rty_SO_b_HallStall = false;
      } else if ((rtu_SI_s_CurrentPos - localDW->SL_s_CurrentPos_Old > 5) ||
                 (localDW->SL_s_CurrentPos_Old - rtu_SI_s_CurrentPos > 5)) {
        localDW->is_Stall_Handler = DHM_IN_Checking;
        localDW->temporalCounter_i1 = 0U;
        localDW->SL_s_CurrentPos_Old = rtu_SI_s_CurrentPos;
      } else if (localDW->temporalCounter_i1 >= 30) {
        localDW->is_Stall_Handler = DHM_IN_Stall;
        localDW->temporalCounter_i1 = 0U;
        *rty_SO_b_HallStall = true;
      }
      break;

     case DHM_IN_Idle_fo:
      if (rtu_SI_e_MotorCmd != 0) {
        localDW->is_Stall_Handler = DHM_IN_Checking;
        localDW->temporalCounter_i1 = 0U;
        localDW->SL_s_CurrentPos_Old = rtu_SI_s_CurrentPos;
      }
      break;

     default:
      /* case IN_Stall: */
      if (localDW->temporalCounter_i1 >= 5) {
        localDW->is_Stall_Handler = DHM_IN_Idle_fo;
        *rty_SO_b_HallStall = false;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/Stall' */
}

/* Model step function for TID1 */
void DHM_Step(void)                    /* Explicit Task: DHM_Step */
{
  /* local block i/o variables */
  Boolean rtb_TmpSignalConversionAtVbINP_;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
  HndPos_Sts_E rtb_SO_m_DoorHndPosSts_f;
  UInt8 rtb_TmpSignalConversionAtVeINP_;
  UInt8 rtb_TmpSignalConversionAtVeIN_k;
  UInt8 tmpRead;
  uint8 SO_e_MotorPwm_e;
  boolean SO_b_CorrectPosToZero_m;

  /* Inport: '<Root>/VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig' */
  (void)
    Rte_Read_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig
    (&SO_e_MotorPwm_e);

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
  DHM_DW.E03_DHM_R = 0U;

  /* SignalConversion generated from: '<S2>/VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig_read' incorporates:
   *  Inport: '<Root>/VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig'
   */
  (void)Rte_Read_VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig
    (&rtb_TmpSignalConversionAtVeINP_);

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   */
  DHM_B.Compare = (rtb_TmpSignalConversionAtVeINP_ == 1);

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   */
  DHM_B.Compare_i = (rtb_TmpSignalConversionAtVeINP_ == 2);

  /* SignalConversion generated from: '<S2>/VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig_read' incorporates:
   *  Inport: '<Root>/VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig'
   */
  (void)Rte_Read_VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig
    (&rtb_TmpSignalConversionAtVeIN_k);

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  DHM_B.Compare_p = (rtb_TmpSignalConversionAtVeIN_k == 1);

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   */
  DHM_B.Compare_n = (rtb_TmpSignalConversionAtVeIN_k == 2);

  /* SignalConversion generated from: '<S2>/VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig_read' incorporates:
   *  Inport: '<Root>/VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig'
   */
  (void)Rte_Read_VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig
    (&DHM_B.TmpSignalConversionAtVsINP_HWA_);

  /* SignalConversion generated from: '<S2>/VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg_read' incorporates:
   *  Inport: '<Root>/VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg'
   */
  (void)Rte_Read_VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg
    (&rtb_TmpSignalConversionAtVbINP_);

  /* Chart: '<S8>/LearnLogic' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion8'
   *  UnitDelay: '<S8>/Unit Delay'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall_m, rtb_TmpSignalConversionAtVbINP_,
                 tmpRead, 0, DHM_B.TmpSignalConversionAtVsINP_HWA_,
                 &DHM_B.SO_e_LearnMotorCmd_o, &DHM_B.SO_e_LearnMotorPwm_f,
                 &SO_b_CorrectPosToZero_m, &DHM_B.SO_m_LearnSts_l,
                 &DHM_B.SO_s_MaxPos_b, &DHM_B.SO_b_Learning_f,
                 &DHM_DW.sf_LearnLogic);

  /* Chart: '<S8>/DoorHndPos' incorporates:
   *  UnitDelay: '<S8>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_B.TmpSignalConversionAtVsINP_HWA_, DHM_DW.UnitDelay5_DSTATE,
                 DHM_B.SO_m_LearnSts_l, &rtb_SO_m_DoorHndPosSts_f,
                 &DHM_B.SO_s_MaxSoftPos_b, &DHM_B.SO_s_MinSoftPos_i,
                 &DHM_B.SO_s_IceBrkPos_d, &DHM_DW.sf_DoorHndPos);

  /* SignalConversion generated from: '<S2>/VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig_read' incorporates:
   *  Inport: '<Root>/VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig'
   */
  (void)Rte_Read_VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig
    (&DHM_B.TmpSignalConversionAtVsINP_HW_n);

  /* Chart: '<S9>/LearnLogic' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion9'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall, rtb_TmpSignalConversionAtVbINP_,
                 SO_e_MotorPwm_e, 0, DHM_B.TmpSignalConversionAtVsINP_HW_n,
                 &DHM_B.SO_e_LearnMotorCmd, &DHM_B.SO_e_LearnMotorPwm,
                 &SO_b_CorrectPosToZero_m, &DHM_B.SO_m_LearnSts,
                 &DHM_B.SO_s_MaxPos, &DHM_B.SO_b_Learning,
                 &DHM_DW.sf_LearnLogic_m);

  /* Chart: '<S9>/DoorHndPos' incorporates:
   *  UnitDelay: '<S9>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_B.TmpSignalConversionAtVsINP_HW_n,
                 DHM_DW.UnitDelay5_DSTATE_o, DHM_B.SO_m_LearnSts,
                 &rtb_SO_m_DoorHndPosSts, &DHM_B.SO_s_MaxSoftPos,
                 &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos,
                 &DHM_DW.sf_DoorHndPos_b);

  /* Chart: '<S8>/CtrlLogic' */
  DHM_CtrlLogic(DHM_B.TmpSignalConversionAtVsINP_HWA_, DHM_B.SO_s_MaxSoftPos_b,
                DHM_B.SO_s_MinSoftPos_i, DHM_B.SO_s_IceBrkPos_d, DHM_B.Compare,
                DHM_B.Compare_i, DHM_B.SO_m_LearnSts_l, DHM_B.SO_b_Learning_f,
                &DHM_B.SO_e_MotorCmd_f, &DHM_B.SO_e_MotorPwm_h,
                &SO_b_CorrectPosToZero_m, &DHM_DW.sf_CtrlLogic);

  /* Chart: '<S8>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd_o, DHM_B.SO_e_LearnMotorPwm_f,
                 DHM_B.SO_e_MotorCmd_f, DHM_B.SO_e_MotorPwm_h,
                 &DHM_B.SO_e_MotorCmd_l, &DHM_B.SO_b_MotorA_j, &SO_e_MotorPwm_e,
                 &DHM_DW.sf_MotorLogic);

  /* Chart: '<S8>/Stall' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  DHM_Stall(DHM_B.TmpSignalConversionAtVsINP_HWA_, DHM_DW.UnitDelay1_DSTATE,
            &DHM_B.SO_b_HallStall_m, &DHM_DW.sf_Stall);

  /* Chart: '<S9>/CtrlLogic' */
  DHM_CtrlLogic(DHM_B.TmpSignalConversionAtVsINP_HW_n, DHM_B.SO_s_MaxSoftPos,
                DHM_B.SO_s_MinSoftPos, DHM_B.SO_s_IceBrkPos, DHM_B.Compare_n,
                DHM_B.Compare_p, DHM_B.SO_m_LearnSts, DHM_B.SO_b_Learning,
                &DHM_B.SO_e_MotorCmd_i, &DHM_B.SO_e_MotorPwm_m,
                &SO_b_CorrectPosToZero_m, &DHM_DW.sf_CtrlLogic_j);

  /* Chart: '<S9>/MotorLogic' */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd, DHM_B.SO_e_LearnMotorPwm,
                 DHM_B.SO_e_MotorCmd_i, DHM_B.SO_e_MotorPwm_m,
                 &DHM_B.SO_e_MotorCmd, &DHM_B.SO_b_MotorA, &SO_e_MotorPwm_e,
                 &DHM_DW.sf_MotorLogic_p);

  /* Chart: '<S9>/Stall' incorporates:
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  DHM_Stall(DHM_B.TmpSignalConversionAtVsINP_HW_n, DHM_DW.UnitDelay1_DSTATE_b,
            &DHM_B.SO_b_HallStall, &DHM_DW.sf_Stall_k);

  /* Update for UnitDelay: '<S8>/Unit Delay5' */
  DHM_DW.UnitDelay5_DSTATE = DHM_B.SO_s_MaxPos_b;

  /* Update for UnitDelay: '<S9>/Unit Delay5' */
  DHM_DW.UnitDelay5_DSTATE_o = DHM_B.SO_s_MaxPos;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE = DHM_B.SO_e_MotorCmd_l;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE_b = DHM_B.SO_e_MotorCmd;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  (void)Rte_Write_VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig
    (rtb_SO_m_DoorHndPosSts_f);

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  (void)Rte_Write_VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig
    (rtb_SO_m_DoorHndPosSts);

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

  /* Outport: '<Root>/VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg' */
  (void)Rte_Write_VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg
    (DHM_B.SO_b_MotorA_j);

  /* Outport: '<Root>/VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg' */
  (void)Rte_Write_VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg
    (DHM_B.SO_b_MotorB_c);

  /* Outport: '<Root>/VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg' */
  (void)Rte_Write_VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg
    (DHM_B.SO_b_MotorA);

  /* Outport: '<Root>/VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg' */
  (void)Rte_Write_VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg
    (DHM_B.SO_b_MotorB);

  /* Outport: '<Root>/VsINP_DHM_FRDoorHandleToEE_sig_VsINP_DHM_FRDoorHandleToEE_sig' */
  (void)Rte_Write_VsINP_DHM_FRDoorHandleToEE_sig_VsINP_DHM_FRDoorHandleToEE_sig
    (DHM_B.SO_s_MaxPos_b);

  /* Outport: '<Root>/VsINP_DHM_RRDoorHandleToEE_sig_VsINP_DHM_RRDoorHandleToEE_sig' */
  (void)Rte_Write_VsINP_DHM_RRDoorHandleToEE_sig_VsINP_DHM_RRDoorHandleToEE_sig
    (DHM_B.SO_s_MaxPos);

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Outport: '<Root>/VeINP_DHM_FRDoorHandleLrnSts_sig_VeINP_DHM_FRDoorHandleLrnSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion10'
   */
  (void)
    Rte_Write_VeINP_DHM_FRDoorHandleLrnSts_sig_VeINP_DHM_FRDoorHandleLrnSts_sig
    (DHM_B.SO_m_LearnSts_l);

  /* Outport: '<Root>/VeINP_DHM_RRDoorHandleLrnSts_sig_VeINP_DHM_RRDoorHandleLrnSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion11'
   */
  (void)
    Rte_Write_VeINP_DHM_RRDoorHandleLrnSts_sig_VeINP_DHM_RRDoorHandleLrnSts_sig
    (DHM_B.SO_m_LearnSts);

  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  (void)
    Rte_Write_VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig
    (DHM_B.SO_m_LearnSts_l);

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
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts;
    HndPos_Sts_E rtb_SO_m_DoorHndPosSts_f;
    uint8 SO_e_MotorPwm_e;
    boolean SO_b_Error_k;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
     *  SubSystem: '<Root>/DHM_Step_sys'
     */

    /* SystemInitialize for Chart: '<S8>/CtrlLogic' */
    DHM_CtrlLogic_Init(&DHM_B.SO_e_MotorCmd_f, &DHM_B.SO_e_MotorPwm_h,
                       &SO_b_Error_k);

    /* SystemInitialize for Chart: '<S8>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts_f, &DHM_B.SO_s_MaxSoftPos_b,
                        &DHM_B.SO_s_MinSoftPos_i, &DHM_B.SO_s_IceBrkPos_d);

    /* SystemInitialize for Chart: '<S8>/LearnLogic' */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd_o, &DHM_B.SO_e_LearnMotorPwm_f,
                        &SO_b_Error_k, &DHM_B.SO_m_LearnSts_l,
                        &DHM_B.SO_s_MaxPos_b, &DHM_B.SO_b_Learning_f);

    /* SystemInitialize for Chart: '<S8>/MotorLogic' */
    DHM_MotorLogic_Init(&DHM_B.SO_e_MotorCmd_l, &DHM_B.SO_b_MotorA_j,
                        &DHM_B.SO_b_MotorB_c, &SO_e_MotorPwm_e);

    /* SystemInitialize for Chart: '<S8>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall_m);

    /* SystemInitialize for Chart: '<S9>/CtrlLogic' */
    DHM_CtrlLogic_Init(&DHM_B.SO_e_MotorCmd_i, &DHM_B.SO_e_MotorPwm_m,
                       &SO_b_Error_k);

    /* SystemInitialize for Chart: '<S9>/DoorHndPos' */
    DHM_DoorHndPos_Init(&rtb_SO_m_DoorHndPosSts, &DHM_B.SO_s_MaxSoftPos,
                        &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos);

    /* SystemInitialize for Chart: '<S9>/LearnLogic' */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd, &DHM_B.SO_e_LearnMotorPwm,
                        &SO_b_Error_k, &DHM_B.SO_m_LearnSts, &DHM_B.SO_s_MaxPos,
                        &DHM_B.SO_b_Learning);

    /* SystemInitialize for Chart: '<S9>/MotorLogic' */
    DHM_MotorLogic_Init(&DHM_B.SO_e_MotorCmd, &DHM_B.SO_b_MotorA,
                        &DHM_B.SO_b_MotorB, &SO_e_MotorPwm_e);

    /* SystemInitialize for Chart: '<S9>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */

    /* SystemInitialize for Outport: '<Root>/VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg' */
    (void)Rte_Write_VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg
      (DHM_B.SO_b_MotorA_j);

    /* SystemInitialize for Outport: '<Root>/VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg' */
    (void)Rte_Write_VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg
      (DHM_B.SO_b_MotorB_c);

    /* SystemInitialize for Outport: '<Root>/VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg' */
    (void)Rte_Write_VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg
      (DHM_B.SO_b_MotorA);

    /* SystemInitialize for Outport: '<Root>/VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg' */
    (void)Rte_Write_VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg
      (DHM_B.SO_b_MotorB);

    /* SystemInitialize for Outport: '<Root>/VsINP_DHM_FRDoorHandleToEE_sig_VsINP_DHM_FRDoorHandleToEE_sig' */
    (void)
      Rte_Write_VsINP_DHM_FRDoorHandleToEE_sig_VsINP_DHM_FRDoorHandleToEE_sig
      (DHM_B.SO_s_MaxPos_b);

    /* SystemInitialize for Outport: '<Root>/VsINP_DHM_RRDoorHandleToEE_sig_VsINP_DHM_RRDoorHandleToEE_sig' */
    (void)
      Rte_Write_VsINP_DHM_RRDoorHandleToEE_sig_VsINP_DHM_RRDoorHandleToEE_sig
      (DHM_B.SO_s_MaxPos);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
