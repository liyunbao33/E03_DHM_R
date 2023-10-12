/*
 * File: DHM_private.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Oct 12 19:52:01 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DHM_private_h_
#define RTW_HEADER_DHM_private_h_
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "DHM_types.h"
#include "DHM.h"

extern void DHM_CtrlLogic_Init(uint8 *rty_SO_e_MotorCmd, uint8
  *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error);
extern void DHM_CtrlLogic(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxSoftPos,
  sint16 rtu_SI_s_MinSoftPos, sint16 rtu_SI_s_IceBrkPos, boolean
  rtu_SI_b_DoorHndFoldReq, boolean rtu_SI_b_DoorHndUnfoldReq, Learn_Sts_E
  rtu_SI_m_LearnSts, boolean rtu_SI_b_Learning, uint8 *rty_SO_e_MotorCmd, uint8 *
  rty_SO_e_MotorPwm, boolean *rty_SO_b_Error, DW_CtrlLogic_DHM_T *localDW);
extern void DHM_DoorHndPos_Init(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, sint16
  *rty_SO_s_MaxSoftPos, sint16 *rty_SO_s_MinSoftPos, sint16 *rty_SO_s_IceBrkPos);
extern void DHM_DoorHndPos(SInt16 rtu_SI_s_CurrentPos, sint16 rtu_SI_s_MaxPos,
  Learn_Sts_E rtu_SI_m_LearnSts, HndPos_Sts_E *rty_SO_m_DoorHndPosSts, sint16
  *rty_SO_s_MaxSoftPos, sint16 *rty_SO_s_MinSoftPos, sint16 *rty_SO_s_IceBrkPos,
  DW_DoorHndPos_DHM_T *localDW);
extern void DHM_LearnLogic_Init(uint8 *rty_SO_e_LearnMotorCmd, uint8
  *rty_SO_e_LearnMotorPwm, boolean *rty_SO_b_CorrectPosToZero, Learn_Sts_E
  *rty_SO_m_LearnSts, sint16 *rty_SO_s_MaxPos, boolean *rty_SO_b_Learning);
extern void DHM_LearnLogic(boolean rtu_SI_b_HallStall, Boolean rtu_SI_b_LearnReq,
  Learn_Sts_E rtu_SI_m_LearnStsFromEE, sint16 rtu_SI_s_MaxPosFromEE, SInt16
  rtu_SI_s_CurrentPos, uint8 *rty_SO_e_LearnMotorCmd, uint8
  *rty_SO_e_LearnMotorPwm, boolean *rty_SO_b_CorrectPosToZero, Learn_Sts_E
  *rty_SO_m_LearnSts, sint16 *rty_SO_s_MaxPos, boolean *rty_SO_b_Learning,
  DW_LearnLogic_DHM_T *localDW);
extern void DHM_MotorLogic_Init(uint8 *rty_SO_e_MotorCmd, boolean
  *rty_SO_b_MotorA, boolean *rty_SO_b_MotorB, uint8 *rty_SO_e_MotorPwm);
extern void DHM_MotorLogic(uint8 rtu_SI_e_LearnMotorCmd, uint8
  rtu_SI_e_LearnMotorPwm, uint8 rtu_SI_e_CtrlMotorCmd, uint8
  rtu_SI_e_CtrlMotorPwm, uint8 *rty_SO_e_MotorCmd, boolean *rty_SO_b_MotorA,
  uint8 *rty_SO_e_MotorPwm, DW_MotorLogic_DHM_T *localDW);
extern void DHM_Stall_Init(boolean *rty_SO_b_HallStall);
extern void DHM_Stall(SInt16 rtu_SI_s_CurrentPos, uint8 rtu_SI_e_MotorCmd,
                      boolean *rty_SO_b_HallStall, DW_Stall_DHM_T *localDW);

#endif                                 /* RTW_HEADER_DHM_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
