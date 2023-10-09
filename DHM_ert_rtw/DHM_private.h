/*
 * File: DHM_private.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Oct  9 09:16:57 2023
 *
 * Target selection: ert.tlc
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

extern void DHM_CtrlLogic_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T
  *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error);
extern void DHM_CtrlLogic(boolean_T rtu_SI_b_HallStall, SInt16
  rtu_SI_s_CurrentPos, int16_T rtu_SI_s_MaxSoftPos, int16_T rtu_SI_s_MinSoftPos,
  int16_T rtu_SI_s_IceBrkPos, boolean_T rtu_SI_b_DoorHndFoldReq, boolean_T
  rtu_SI_b_DoorHndUnfoldReq, Learn_Sts_E rtu_SI_m_LearnSts, uint8_T
  *rty_SO_e_MotorCmd, uint8_T *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_Error,
  DW_CtrlLogic_DHM_T *localDW);
extern void DHM_DoorHndPos_Init(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, int16_T
  *rty_SO_s_MaxSoftPos, int16_T *rty_SO_s_MinSoftPos, int16_T
  *rty_SO_s_IceBrkPos);
extern void DHM_DoorHndPos(SInt16 rtu_SI_s_CurrentPos, int16_T rtu_SI_s_MaxPos,
  Learn_Sts_E rtu_SI_m_LearnSts, HndPos_Sts_E *rty_SO_m_DoorHndPosSts, int16_T
  *rty_SO_s_MaxSoftPos, int16_T *rty_SO_s_MinSoftPos, int16_T
  *rty_SO_s_IceBrkPos, DW_DoorHndPos_DHM_T *localDW);
extern void DHM_LearnLogic_Init(uint8_T *rty_SO_e_MotorCmd, uint8_T
  *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_CorrectPosToZero, boolean_T
  *rty_SO_b_CorrectPosToMax, Learn_Sts_E *rty_SO_m_LearnSts, int16_T
  *rty_SO_s_MaxPos);
extern void DHM_LearnLogic(boolean_T rtu_SI_b_HallStall, Boolean
  rtu_SI_b_LearnReq, Learn_Sts_E rtu_SI_m_LearnStsFromEE, int16_T
  rtu_SI_s_MaxPosFromEE, SInt16 rtu_SI_s_CurrentPos, uint8_T *rty_SO_e_MotorCmd,
  uint8_T *rty_SO_e_MotorPwm, boolean_T *rty_SO_b_CorrectPosToZero, boolean_T
  *rty_SO_b_CorrectPosToMax, Learn_Sts_E *rty_SO_m_LearnSts, int16_T
  *rty_SO_s_MaxPos, DW_LearnLogic_DHM_T *localDW);
extern void DHM_MotorLogic_Init(uint8_T *rty_SO_e_MotorCmd, boolean_T
  *rty_SO_b_MotorA, boolean_T *rty_SO_b_MotorB, uint8_T *rty_SO_e_MotorPwm);
extern void DHM_MotorLogic(uint8_T rtu_SI_e_LearnMotorCmd, uint8_T
  rtu_SI_e_LearnMotorPwm, uint8_T rtu_SI_e_CtrlMotorCmd, uint8_T
  rtu_SI_e_CtrlMotorPwm, uint8_T *rty_SO_e_MotorCmd, boolean_T *rty_SO_b_MotorA,
  uint8_T *rty_SO_e_MotorPwm, DW_MotorLogic_DHM_T *localDW);
extern void DHM_Stall_Init(boolean_T *rty_SO_b_HallStall);
extern void DHM_Stall(SInt16 rtu_SI_s_CurrentPos, uint8_T rtu_SI_e_MotorCmd,
                      boolean_T *rty_SO_b_HallStall, DW_Stall_DHM_T *localDW);

#endif                                 /* RTW_HEADER_DHM_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
