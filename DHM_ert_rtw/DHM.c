/*
 * File: DHM.c
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Oct 15 23:31:30 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DHM.h"
#include "rtwtypes.h"
#include "DHM_types.h"
#include "Rte_Type.h"
#include "DHM_private.h"

/* Named constants for Chart: '<S8>/CtrlLogic' */
#define DHM_IN_Check                   ((uint8_T)1U)
#define DHM_IN_Fold                    ((uint8_T)1U)
#define DHM_IN_IceBrk                  ((uint8_T)2U)
#define DHM_IN_IceBrkSuccess           ((uint8_T)3U)
#define DHM_IN_Icebreak                ((uint8_T)1U)
#define DHM_IN_Idle                    ((uint8_T)2U)
#define DHM_IN_Interrupt1              ((uint8_T)3U)
#define DHM_IN_Interrupt2              ((uint8_T)4U)
#define DHM_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define DHM_IN_Start                   ((uint8_T)2U)
#define DHM_IN_Start_c                 ((uint8_T)1U)
#define DHM_IN_Step1                   ((uint8_T)3U)
#define DHM_IN_Step1_g                 ((uint8_T)2U)
#define DHM_IN_Step2                   ((uint8_T)4U)
#define DHM_IN_Step2_f                 ((uint8_T)3U)
#define DHM_IN_Step3                   ((uint8_T)5U)
#define DHM_IN_Step3_c                 ((uint8_T)4U)
#define DHM_IN_Stop                    ((uint8_T)6U)
#define DHM_IN_Stop_c                  ((uint8_T)5U)
#define DHM_IN_Unfold                  ((uint8_T)5U)

/* Named constants for Chart: '<S8>/DoorHndPos' */
#define DHM_IN_GetSoftPos              ((uint8_T)1U)
#define DHM_IN_PowerOn                 ((uint8_T)2U)

/* Named constants for Chart: '<S8>/LearnLogic' */
#define DHM_IN_Check_p                 ((uint8_T)1U)
#define DHM_IN_CorrectZeroPos          ((uint8_T)2U)
#define DHM_IN_Delay                   ((uint8_T)3U)
#define DHM_IN_Failed                  ((uint8_T)4U)
#define DHM_IN_Finished                ((uint8_T)5U)
#define DHM_IN_GotoMaxPos1             ((uint8_T)6U)
#define DHM_IN_GotoZeroPos             ((uint8_T)7U)
#define DHM_IN_Idle_f                  ((uint8_T)8U)
#define DHM_IN_LearnLogic              ((uint8_T)1U)
#define DHM_IN_PowerOn_g               ((uint8_T)2U)

/* Named constants for Chart: '<S8>/Stall' */
#define DHM_IN_Checking                ((uint8_T)1U)
#define DHM_IN_Idle_fo                 ((uint8_T)2U)
#define DHM_IN_Stall                   ((uint8_T)3U)

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

/* Forward declaration for local functions */
static void DHM_Unfold(int16_T rtu_SI_s_CurrentPos, int16_T rtu_SI_s_MaxSoftPos,
  int16_T rtu_SI_s_IceBrkPos, boolean_T rtu_SI_b_Learning, uint8_T
  *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error,
  DW_CtrlLogic_DHM_T *localDW);

/* Forward declaration for local functions */
static void DHM_GetCurrenPos(real_T *CurrentPos, SInt16 rtu_SI_s_HallCount,
  DW_DoorHndPos_DHM_T *localDW);
static real_T DHM_GetPosSts(real_T CurrentPos, real_T MinSoftPos, real_T
  MaxSoftPos);
static uint8_T DHM_safe_cast_to_HndPos_Sts_E(uint8_T input);

/* Function for Chart: '<S8>/CtrlLogic' */
static void DHM_Unfold(int16_T rtu_SI_s_CurrentPos, int16_T rtu_SI_s_MaxSoftPos,
  int16_T rtu_SI_s_IceBrkPos, boolean_T rtu_SI_b_Learning, uint8_T
  *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error,
  DW_CtrlLogic_DHM_T *localDW)
{
  if ((localDW->SI_b_DoorHndFoldReq_prev != localDW->SI_b_DoorHndFoldReq_start) &&
      localDW->SI_b_DoorHndFoldReq_start) {
    localDW->is_Icebreak = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Unfold = DHM_IN_NO_ACTIVE_CHILD;
    localDW->is_Ctrl = DHM_IN_Interrupt1;
    localDW->temporalCounter_i1 = 0U;

    /*  折叠打断展开  */
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

            /*  破冰达到指定次数，报错  */
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
              int32_T tmp;
              localDW->is_Icebreak = DHM_IN_Check;
              localDW->temporalCounter_i1 = 0U;
              *rty_SO_e_MotorCmd = 0U;
              *rty_SO_e_MotorPwm = 0U;
              tmp = localDW->SL_e_CycleCount + 1;
              if (localDW->SL_e_CycleCount + 1 > 255) {
                tmp = 255;
              }

              localDW->SL_e_CycleCount = (uint8_T)tmp;
            }
          }
          break;

         default:
          /* case IN_IceBrkSuccess: */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 100U;
          if (localDW->temporalCounter_i1 >= 10) {
            localDW->SL_e_IceBrkCount = 0U;

            /*  破冰完成  */
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

        /*  缓停  */
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
        /*  超时报错  */
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
void DHM_CtrlLogic_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm,
  boolean_T *rty_SO_b_Error)
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
void DHM_CtrlLogic(int16_T rtu_SI_s_CurrentPos, int16_T rtu_SI_s_MaxSoftPos,
                   int16_T rtu_SI_s_MinSoftPos, int16_T rtu_SI_s_IceBrkPos,
                   boolean_T rtu_SI_b_DoorHndFoldReq, boolean_T
                   rtu_SI_b_DoorHndUnfoldReq, Learn_Sts_E rtu_SI_m_LearnSts,
                   boolean_T rtu_SI_b_Learning, uint8_T *rty_SO_e_MotorCmd,
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

        /*  展开打断折叠  */
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

            /*  缓停  */
            *rty_SO_e_MotorCmd = 2U;
            *rty_SO_e_MotorPwm = 60U;
          } else if (localDW->temporalCounter_i1 >= 200) {
            /*  超时报错  */
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
          /*  已学习  */
          localDW->is_Fold = DHM_IN_Step1_g;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
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
          /*  已学习  */
          localDW->is_Unfold = DHM_IN_Step1;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
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
          /*  已学习  */
          localDW->is_Fold = DHM_IN_Step1_g;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 2U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
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
          /*  已学习  */
          localDW->is_Unfold = DHM_IN_Step1;
          localDW->temporalCounter_i1 = 0U;

          /*  缓启  */
          *rty_SO_e_MotorCmd = 1U;
          *rty_SO_e_MotorPwm = 60U;
        } else {
          /*  未学习  */
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
static void DHM_GetCurrenPos(real_T *CurrentPos, SInt16 rtu_SI_s_HallCount,
  DW_DoorHndPos_DHM_T *localDW)
{
  int32_T tmp;
  tmp = rtu_SI_s_HallCount - localDW->SL_s_TempHallCount;
  if (tmp > 32767) {
    tmp = 32767;
  } else if (tmp < -32768) {
    tmp = -32768;
  }

  localDW->SL_s_TempHallCount = rtu_SI_s_HallCount;
  if ((localDW->SI_b_CorrectPosToZero_prev !=
       localDW->SI_b_CorrectPosToZero_start) &&
      localDW->SI_b_CorrectPosToZero_start) {
    *CurrentPos = 0.0;
  }

  *CurrentPos += (real_T)(int16_T)tmp;
}

/* Function for Chart: '<S8>/DoorHndPos' */
static real_T DHM_GetPosSts(real_T CurrentPos, real_T MinSoftPos, real_T
  MaxSoftPos)
{
  real_T HndSts;
  if (CurrentPos <= MinSoftPos) {
    HndSts = 0.0;
  } else if (CurrentPos >= MaxSoftPos) {
    HndSts = 1.0;
  } else {
    HndSts = 2.0;
  }

  return HndSts;
}

static uint8_T DHM_safe_cast_to_HndPos_Sts_E(uint8_T input)
{
  uint8_T output;

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
void DHM_DoorHndPos_Init(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, int16_T
  *rty_SO_s_MaxSoftPos, int16_T *rty_SO_s_MinSoftPos, int16_T
  *rty_SO_s_IceBrkPos, int16_T *rty_SO_s_CurrentPos)
{
  *rty_SO_m_DoorHndPosSts = Hnd_Fold;
  *rty_SO_s_MaxSoftPos = 0;
  *rty_SO_s_MinSoftPos = 0;
  *rty_SO_s_IceBrkPos = 0;
  *rty_SO_s_CurrentPos = 0;
}

/*
 * Output and update for atomic system:
 *    '<S8>/DoorHndPos'
 *    '<S9>/DoorHndPos'
 */
void DHM_DoorHndPos(SInt16 rtu_SI_s_HallCount, int16_T rtu_SI_s_CurrentPosFromEE,
                    int16_T rtu_SI_s_MaxPos, boolean_T rtu_SI_b_CorrectPosToZero,
                    Learn_Sts_E rtu_SI_m_LearnSts, HndPos_Sts_E
                    *rty_SO_m_DoorHndPosSts, int16_T *rty_SO_s_MaxSoftPos,
                    int16_T *rty_SO_s_MinSoftPos, int16_T *rty_SO_s_IceBrkPos,
                    int16_T *rty_SO_s_CurrentPos, DW_DoorHndPos_DHM_T *localDW)
{
  real_T c;
  if (localDW->temporalCounter_i1 < 63U) {
    localDW->temporalCounter_i1++;
  }

  localDW->SI_b_CorrectPosToZero_prev = localDW->SI_b_CorrectPosToZero_start;
  localDW->SI_b_CorrectPosToZero_start = rtu_SI_b_CorrectPosToZero;

  /* Chart: '<S8>/DoorHndPos' */
  if (localDW->is_active_c5_DoorHndDriver == 0U) {
    localDW->SI_b_CorrectPosToZero_prev = rtu_SI_b_CorrectPosToZero;
    localDW->is_active_c5_DoorHndDriver = 1U;
    localDW->is_c5_DoorHndDriver = DHM_IN_PowerOn;
    localDW->temporalCounter_i1 = 0U;
    *rty_SO_s_CurrentPos = rtu_SI_s_CurrentPosFromEE;
  } else if (localDW->is_c5_DoorHndDriver == DHM_IN_GetSoftPos) {
    if (rtu_SI_m_LearnSts == Learn_Success) {
      *rty_SO_s_MaxSoftPos = (int16_T)(rtu_SI_s_MaxPos * 95 / 100);
      *rty_SO_s_MinSoftPos = (int16_T)(rtu_SI_s_MaxPos * 5 / 100);
      *rty_SO_s_IceBrkPos = (int16_T)(rtu_SI_s_MaxPos * 20 / 100);
      c = DHM_GetPosSts((real_T)*rty_SO_s_CurrentPos, (real_T)
                        *rty_SO_s_MinSoftPos, (real_T)*rty_SO_s_MaxSoftPos);
      if (c < 2.147483648E+9) {
        if (c >= -2.147483648E+9) {
          *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)
            (int32_T)c);
        } else {
          *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
        }
      } else {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
      }
    } else {
      *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
    }

    c = *rty_SO_s_CurrentPos;
    DHM_GetCurrenPos(&c, rtu_SI_s_HallCount, localDW);
    if (c < 32768.0) {
      if (c >= -32768.0) {
        *rty_SO_s_CurrentPos = (int16_T)c;
      } else {
        *rty_SO_s_CurrentPos = MIN_int16_T;
      }
    } else {
      *rty_SO_s_CurrentPos = MAX_int16_T;
    }

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 50) {
    /*  500ms内读取E2当前位置  */
    localDW->is_c5_DoorHndDriver = DHM_IN_GetSoftPos;
    if (rtu_SI_m_LearnSts == Learn_Success) {
      *rty_SO_s_MaxSoftPos = (int16_T)(rtu_SI_s_MaxPos * 95 / 100);
      *rty_SO_s_MinSoftPos = (int16_T)(rtu_SI_s_MaxPos * 5 / 100);
      *rty_SO_s_IceBrkPos = (int16_T)(rtu_SI_s_MaxPos * 20 / 100);
      c = DHM_GetPosSts((real_T)*rty_SO_s_CurrentPos, (real_T)
                        *rty_SO_s_MinSoftPos, (real_T)*rty_SO_s_MaxSoftPos);
      if (c < 2.147483648E+9) {
        if (c >= -2.147483648E+9) {
          *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E((uint8_T)
            (int32_T)c);
        } else {
          *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(0);
        }
      } else {
        *rty_SO_m_DoorHndPosSts = DHM_safe_cast_to_HndPos_Sts_E(MAX_uint8_T);
      }
    } else {
      *rty_SO_m_DoorHndPosSts = Hnd_Unknown;
    }

    c = *rty_SO_s_CurrentPos;
    DHM_GetCurrenPos(&c, rtu_SI_s_HallCount, localDW);
    if (c < 32768.0) {
      if (c >= -32768.0) {
        *rty_SO_s_CurrentPos = (int16_T)c;
      } else {
        *rty_SO_s_CurrentPos = MIN_int16_T;
      }
    } else {
      *rty_SO_s_CurrentPos = MAX_int16_T;
    }
  } else {
    *rty_SO_s_CurrentPos = rtu_SI_s_CurrentPosFromEE;
  }

  /* End of Chart: '<S8>/DoorHndPos' */
}

/*
 * System initialize for atomic system:
 *    '<S8>/LearnLogic'
 *    '<S9>/LearnLogic'
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
 * Output and update for atomic system:
 *    '<S8>/LearnLogic'
 *    '<S9>/LearnLogic'
 */
void DHM_LearnLogic(boolean_T rtu_SI_b_HallStall, Boolean rtu_SI_b_LearnReq,
                    Learn_Sts_E rtu_SI_m_LearnStsFromEE, SInt16
                    rtu_SI_s_MaxPosFromEE, int16_T rtu_SI_s_CurrentPos, uint8_T *
                    rty_SO_e_LearnMotorCmd, uint8_T *rty_SO_e_LearnMotorPwm,
                    boolean_T *rty_SO_b_CorrectPosToZero, Learn_Sts_E
                    *rty_SO_m_LearnSts, int16_T *rty_SO_s_MaxPos, boolean_T
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
    localDW->is_c3_DoorHndDriver = DHM_IN_PowerOn_g;
    localDW->temporalCounter_i1 = 0U;
    localDW->SL_e_AutoLearnCount = 2U;

    /* 上电自动学习 */
    *rty_SO_s_MaxPos = rtu_SI_s_MaxPosFromEE;
    *rty_SO_m_LearnSts = rtu_SI_m_LearnStsFromEE;
  } else if (localDW->is_c3_DoorHndDriver == DHM_IN_LearnLogic) {
    boolean_T guard1 = false;
    guard1 = false;
    switch (localDW->is_LearnLogic) {
     case DHM_IN_Check_p:
      if (*rty_SO_s_MaxPos > 400) {
        localDW->is_LearnLogic = DHM_IN_Finished;
        localDW->temporalCounter_i1 = 0U;

        /*  学习成功  */
        *rty_SO_m_LearnSts = Learn_Success;
      } else {
        localDW->is_LearnLogic = DHM_IN_Failed;
        localDW->temporalCounter_i1 = 0U;

        /*  学习失败  */
        *rty_SO_e_LearnMotorCmd = 0U;
        *rty_SO_e_LearnMotorPwm = 0U;
        *rty_SO_m_LearnSts = Learn_Fail;
      }
      break;

     case DHM_IN_CorrectZeroPos:
      if (localDW->temporalCounter_i1 >= 20) {
        localDW->is_LearnLogic = DHM_IN_Check_p;

        /*  学习结果判断  */
      }
      break;

     case DHM_IN_Delay:
      if (localDW->temporalCounter_i1 >= 200) {
        localDW->is_LearnLogic = DHM_IN_GotoZeroPos;
        localDW->temporalCounter_i1 = 0U;

        /*  折叠  */
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
          int16_T tmp;
          tmp = rtu_SI_s_CurrentPos;
          if (rtu_SI_s_CurrentPos < 0) {
            tmp = 0;
          } else if (rtu_SI_s_CurrentPos > 255) {
            tmp = 255;
          }

          localDW->SL_e_tempPos = (uint8_T)tmp;
          localDW->is_LearnLogic = DHM_IN_Delay;
          localDW->temporalCounter_i1 = 0U;
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
        } else if (localDW->temporalCounter_i1 >= 400) {
          localDW->is_LearnLogic = DHM_IN_Failed;
          localDW->temporalCounter_i1 = 0U;

          /*  学习失败  */
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
          *rty_SO_m_LearnSts = Learn_Fail;
        } else {
          /*  展开  */
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

          /*  学习失败  */
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
          *rty_SO_m_LearnSts = Learn_Fail;
        } else if (rtu_SI_b_HallStall) {
          int32_T tmp_0;
          tmp_0 = rtu_SI_s_CurrentPos - localDW->SL_e_tempPos;
          if (tmp_0 < -32768) {
            tmp_0 = -32768;
          }

          *rty_SO_s_MaxPos = (int16_T)tmp_0;
          localDW->is_LearnLogic = DHM_IN_CorrectZeroPos;
          localDW->temporalCounter_i1 = 0U;

          /*  零点校准  */
          *rty_SO_e_LearnMotorCmd = 0U;
          *rty_SO_e_LearnMotorPwm = 0U;
          *rty_SO_b_CorrectPosToZero = true;
        } else {
          /*  折叠  */
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

      /*  展开  */
      *rty_SO_b_Learning = true;
      *rty_SO_e_LearnMotorCmd = 1U;
      *rty_SO_e_LearnMotorPwm = 100U;
    }

    /* case IN_PowerOn: */
  } else if (localDW->temporalCounter_i1 >= 50) {
    /*  500ms内读取E2学习状态和最大hall位置  */
    localDW->is_c3_DoorHndDriver = DHM_IN_LearnLogic;
    localDW->is_LearnLogic = DHM_IN_Idle_f;
    *rty_SO_b_Learning = false;
    *rty_SO_e_LearnMotorCmd = 0U;
    *rty_SO_e_LearnMotorPwm = 0U;
    *rty_SO_b_CorrectPosToZero = false;
  } else {
    localDW->SL_e_AutoLearnCount = 2U;

    /* 上电自动学习 */
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
void DHM_MotorLogic_Init(uint8_T *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_MotorA,
  boolean_T *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorPwm)
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
void DHM_MotorLogic(uint8_T rtu_SI_e_LearnMotorCmd, uint8_T
                    rtu_SI_e_LearnMotorPwm, uint8_T rtu_SI_e_CtrlMotorCmd,
                    uint8_T rtu_SI_e_CtrlMotorPwm, uint8_T *rty_SO_e_MotorCmd,
                    boolean_T *rty_SO_b_MotorA, uint8_T *rty_SO_e_MotorPwm,
                    DW_MotorLogic_DHM_T *localDW)
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
void DHM_Stall_Init(boolean_T *rty_SO_b_HallStall)
{
  *rty_SO_b_HallStall = false;
}

/*
 * Output and update for atomic system:
 *    '<S8>/Stall'
 *    '<S9>/Stall'
 */
void DHM_Stall(int16_T rtu_SI_s_CurrentPos, uint8_T rtu_SI_e_MotorCmd, boolean_T
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
  uint8_T SO_e_MotorCmd_f;
  uint8_T SO_e_MotorPwm_e;
  uint8_T SO_e_MotorPwm_h;
  boolean_T SO_b_Error_k;

  /* RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
   *  SubSystem: '<Root>/DHM_Step_sys'
   */
  /* Chart: '<S8>/LearnLogic' incorporates:
   *  Inport: '<Root>/VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg'
   *  Inport: '<Root>/VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig'
   *  Inport: '<Root>/VsINP_EPRM_FRDoorHandleFromEE_sig_VsINP_EPRM_FRDoorHandleFromEE_sig'
   *  Outport: '<Root>/VsINP_DHM_FRDoorHandleToEE_sig_VsINP_DHM_FRDoorHandleToEE_sig'
   *  UnitDelay: '<S8>/Unit Delay'
   *  UnitDelay: '<S8>/Unit Delay3'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall_m, DHM_U.VbINP_CAN_DoorHandleLrnReq_flg_,
                 DHM_U.VeINP_EPRM_FRDoorHandleLrnStsFr,
                 DHM_U.VsINP_EPRM_FRDoorHandleFromEE_s, DHM_B.SO_s_CurrentPos_o,
                 &DHM_B.SO_e_LearnMotorCmd_o, &DHM_B.SO_e_LearnMotorPwm_f,
                 &DHM_B.SO_b_CorrectPosToZero_m, &DHM_B.SO_m_LearnSts_l,
                 &DHM_Y.VsINP_DHM_FRDoorHandleToEE_sig_, &DHM_B.SO_b_Learning_f,
                 &DHM_DW.sf_LearnLogic);

  /* Chart: '<S8>/DoorHndPos' incorporates:
   *  Inport: '<Root>/VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig'
   *  UnitDelay: '<S8>/Unit Delay2'
   *  UnitDelay: '<S8>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_U.VsINP_HWA_PassHandleHall_sig_Vs, 0,
                 DHM_DW.UnitDelay5_DSTATE, DHM_DW.UnitDelay2_DSTATE,
                 DHM_B.SO_m_LearnSts_l, &DHM_B.SO_m_DoorHndPosSts_f,
                 &DHM_B.SO_s_MaxSoftPos_b, &DHM_B.SO_s_MinSoftPos_i,
                 &DHM_B.SO_s_IceBrkPos_d, &DHM_B.SO_s_CurrentPos_o,
                 &DHM_DW.sf_DoorHndPos);

  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  DHM_Y.VeOUT_DHM_FRDoorHandleSts_sig_V = DHM_B.SO_m_DoorHndPosSts_f;

  /* DataTypeConversion: '<S3>/Data Type Conversion10' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  DHM_Y.VeINP_DHM_FRDoorHandleLrnSts_si = DHM_B.SO_m_LearnSts_l;

  /* Chart: '<S9>/LearnLogic' incorporates:
   *  Inport: '<Root>/VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg'
   *  Inport: '<Root>/VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig'
   *  Inport: '<Root>/VsINP_EPRM_RRDoorHandleFromEE_sig_VsINP_EPRM_RRDoorHandleFromEE_sig'
   *  Outport: '<Root>/VsINP_DHM_RRDoorHandleToEE_sig_VsINP_DHM_RRDoorHandleToEE_sig'
   *  UnitDelay: '<S9>/Unit Delay'
   *  UnitDelay: '<S9>/Unit Delay3'
   */
  DHM_LearnLogic(DHM_B.SO_b_HallStall, DHM_U.VbINP_CAN_DoorHandleLrnReq_flg_,
                 DHM_U.VeINP_EPRM_RRDoorHandleLrnStsFr,
                 DHM_U.VsINP_EPRM_RRDoorHandleFromEE_s, DHM_B.SO_s_CurrentPos,
                 &DHM_B.SO_e_LearnMotorCmd, &DHM_B.SO_e_LearnMotorPwm,
                 &DHM_B.SO_b_CorrectPosToZero, &DHM_B.SO_m_LearnSts,
                 &DHM_Y.VsINP_DHM_RRDoorHandleToEE_sig_, &DHM_B.SO_b_Learning,
                 &DHM_DW.sf_LearnLogic_m);

  /* DataTypeConversion: '<S3>/Data Type Conversion11' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  DHM_Y.VeINP_DHM_RRDoorHandleLrnSts_si = DHM_B.SO_m_LearnSts;

  /* Chart: '<S9>/DoorHndPos' incorporates:
   *  Inport: '<Root>/VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig'
   *  UnitDelay: '<S9>/Unit Delay2'
   *  UnitDelay: '<S9>/Unit Delay5'
   */
  DHM_DoorHndPos(DHM_U.VsINP_HWA_RRHandleHall_sig_VsIN, 0,
                 DHM_DW.UnitDelay5_DSTATE_o, DHM_DW.UnitDelay2_DSTATE_e,
                 DHM_B.SO_m_LearnSts, &DHM_B.SO_m_DoorHndPosSts,
                 &DHM_B.SO_s_MaxSoftPos, &DHM_B.SO_s_MinSoftPos,
                 &DHM_B.SO_s_IceBrkPos, &DHM_B.SO_s_CurrentPos,
                 &DHM_DW.sf_DoorHndPos_b);

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  DHM_Y.VeOUT_DHM_RRDoorHandleSts_sig_V = DHM_B.SO_m_DoorHndPosSts;

  /* Outport: '<Root>/VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion3'
   */
  DHM_Y.VeOUT_DHM_FRDoorHandleLrnStsEE_ = DHM_Y.VeINP_DHM_FRDoorHandleLrnSts_si;

  /* Outport: '<Root>/VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion4'
   */
  DHM_Y.VeOUT_DHM_RRDoorHandleLrnStsEE_ = DHM_Y.VeINP_DHM_RRDoorHandleLrnSts_si;

  /* Chart: '<S8>/CtrlLogic' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S5>/Constant'
   *  Inport: '<Root>/VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S5>/Compare'
   */
  DHM_CtrlLogic(DHM_B.SO_s_CurrentPos_o, DHM_B.SO_s_MaxSoftPos_b,
                DHM_B.SO_s_MinSoftPos_i, DHM_B.SO_s_IceBrkPos_d,
                DHM_U.VeINP_CAN_RDoorHandleReq_sig_Ve == 1,
                DHM_U.VeINP_CAN_RDoorHandleReq_sig_Ve == 2,
                DHM_B.SO_m_LearnSts_l, DHM_B.SO_b_Learning_f, &SO_e_MotorCmd_f,
                &SO_e_MotorPwm_h, &SO_b_Error_k, &DHM_DW.sf_CtrlLogic);

  /* Chart: '<S8>/MotorLogic' incorporates:
   *  Outport: '<Root>/VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg'
   */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd_o, DHM_B.SO_e_LearnMotorPwm_f,
                 SO_e_MotorCmd_f, SO_e_MotorPwm_h, &DHM_B.SO_e_MotorCmd_l,
                 &DHM_Y.VbOUT_DHM_FRHadUnfold_flg_VbOUT, &SO_e_MotorPwm_e,
                 &DHM_DW.sf_MotorLogic);

  /* Chart: '<S8>/Stall' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  DHM_Stall(DHM_B.SO_s_CurrentPos_o, DHM_DW.UnitDelay1_DSTATE,
            &DHM_B.SO_b_HallStall_m, &DHM_DW.sf_Stall);

  /* Chart: '<S9>/CtrlLogic' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   */
  DHM_CtrlLogic(DHM_B.SO_s_CurrentPos, DHM_B.SO_s_MaxSoftPos,
                DHM_B.SO_s_MinSoftPos, DHM_B.SO_s_IceBrkPos,
                DHM_U.VeINP_CAN_RRDoorHandleReq_sig_V == 2,
                DHM_U.VeINP_CAN_RRDoorHandleReq_sig_V == 1, DHM_B.SO_m_LearnSts,
                DHM_B.SO_b_Learning, &SO_e_MotorCmd_f, &SO_e_MotorPwm_h,
                &SO_b_Error_k, &DHM_DW.sf_CtrlLogic_j);

  /* Chart: '<S9>/MotorLogic' incorporates:
   *  Outport: '<Root>/VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg'
   */
  DHM_MotorLogic(DHM_B.SO_e_LearnMotorCmd, DHM_B.SO_e_LearnMotorPwm,
                 SO_e_MotorCmd_f, SO_e_MotorPwm_h, &DHM_B.SO_e_MotorCmd,
                 &DHM_Y.VbOUT_DHM_RRHandleUnfold_flg_Vb, &SO_e_MotorPwm_e,
                 &DHM_DW.sf_MotorLogic_p);

  /* Chart: '<S9>/Stall' incorporates:
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  DHM_Stall(DHM_B.SO_s_CurrentPos, DHM_DW.UnitDelay1_DSTATE_b,
            &DHM_B.SO_b_HallStall, &DHM_DW.sf_Stall_k);

  /* Update for UnitDelay: '<S8>/Unit Delay5' incorporates:
   *  Outport: '<Root>/VsINP_DHM_FRDoorHandleToEE_sig_VsINP_DHM_FRDoorHandleToEE_sig'
   */
  DHM_DW.UnitDelay5_DSTATE = DHM_Y.VsINP_DHM_FRDoorHandleToEE_sig_;

  /* Update for UnitDelay: '<S8>/Unit Delay2' */
  DHM_DW.UnitDelay2_DSTATE = DHM_B.SO_b_CorrectPosToZero_m;

  /* Update for UnitDelay: '<S9>/Unit Delay5' incorporates:
   *  Outport: '<Root>/VsINP_DHM_RRDoorHandleToEE_sig_VsINP_DHM_RRDoorHandleToEE_sig'
   */
  DHM_DW.UnitDelay5_DSTATE_o = DHM_Y.VsINP_DHM_RRDoorHandleToEE_sig_;

  /* Update for UnitDelay: '<S9>/Unit Delay2' */
  DHM_DW.UnitDelay2_DSTATE_e = DHM_B.SO_b_CorrectPosToZero;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE = DHM_B.SO_e_MotorCmd_l;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  DHM_DW.UnitDelay1_DSTATE_b = DHM_B.SO_e_MotorCmd;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' */
}

/* Model initialize function */
void DHM_initialize(void)
{
  {
    uint8_T SO_e_MotorCmd_f;
    uint8_T SO_e_MotorPwm_h;
    boolean_T SO_b_Error_k;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/DHM_Step' incorporates:
     *  SubSystem: '<Root>/DHM_Step_sys'
     */

    /* SystemInitialize for Chart: '<S8>/CtrlLogic' */
    DHM_CtrlLogic_Init(&SO_e_MotorCmd_f, &SO_e_MotorPwm_h, &SO_b_Error_k);

    /* SystemInitialize for Chart: '<S8>/DoorHndPos' */
    DHM_DoorHndPos_Init(&DHM_B.SO_m_DoorHndPosSts_f, &DHM_B.SO_s_MaxSoftPos_b,
                        &DHM_B.SO_s_MinSoftPos_i, &DHM_B.SO_s_IceBrkPos_d,
                        &DHM_B.SO_s_CurrentPos_o);

    /* SystemInitialize for Chart: '<S8>/LearnLogic' incorporates:
     *  Outport: '<Root>/VsINP_DHM_FRDoorHandleToEE_sig_VsINP_DHM_FRDoorHandleToEE_sig'
     */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd_o, &DHM_B.SO_e_LearnMotorPwm_f,
                        &DHM_B.SO_b_CorrectPosToZero_m, &DHM_B.SO_m_LearnSts_l,
                        &DHM_Y.VsINP_DHM_FRDoorHandleToEE_sig_,
                        &DHM_B.SO_b_Learning_f);

    /* SystemInitialize for Chart: '<S8>/MotorLogic' incorporates:
     *  Outport: '<Root>/VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg'
     *  Outport: '<Root>/VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg'
     */
    DHM_MotorLogic_Init(&DHM_B.SO_e_MotorCmd_l,
                        &DHM_Y.VbOUT_DHM_FRHadUnfold_flg_VbOUT,
                        &DHM_Y.VbOUT_DHM_FRHadFold_flg_VbOUT_D, &SO_e_MotorCmd_f);

    /* SystemInitialize for Chart: '<S8>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall_m);

    /* SystemInitialize for Chart: '<S9>/CtrlLogic' */
    DHM_CtrlLogic_Init(&SO_e_MotorCmd_f, &SO_e_MotorPwm_h, &SO_b_Error_k);

    /* SystemInitialize for Chart: '<S9>/DoorHndPos' */
    DHM_DoorHndPos_Init(&DHM_B.SO_m_DoorHndPosSts, &DHM_B.SO_s_MaxSoftPos,
                        &DHM_B.SO_s_MinSoftPos, &DHM_B.SO_s_IceBrkPos,
                        &DHM_B.SO_s_CurrentPos);

    /* SystemInitialize for Chart: '<S9>/LearnLogic' incorporates:
     *  Outport: '<Root>/VsINP_DHM_RRDoorHandleToEE_sig_VsINP_DHM_RRDoorHandleToEE_sig'
     */
    DHM_LearnLogic_Init(&DHM_B.SO_e_LearnMotorCmd, &DHM_B.SO_e_LearnMotorPwm,
                        &DHM_B.SO_b_CorrectPosToZero, &DHM_B.SO_m_LearnSts,
                        &DHM_Y.VsINP_DHM_RRDoorHandleToEE_sig_,
                        &DHM_B.SO_b_Learning);

    /* SystemInitialize for Chart: '<S9>/MotorLogic' incorporates:
     *  Outport: '<Root>/VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg'
     *  Outport: '<Root>/VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg'
     */
    DHM_MotorLogic_Init(&DHM_B.SO_e_MotorCmd,
                        &DHM_Y.VbOUT_DHM_RRHandleUnfold_flg_Vb,
                        &DHM_Y.VbOUT_DHM_RRHandleFold_flg_VbOU, &SO_e_MotorCmd_f);

    /* SystemInitialize for Chart: '<S9>/Stall' */
    DHM_Stall_Init(&DHM_B.SO_b_HallStall);

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
