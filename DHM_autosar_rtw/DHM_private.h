/*
 * File: DHM_private.h
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

#ifndef RTW_HEADER_DHM_private_h_
#define RTW_HEADER_DHM_private_h_
#include "rtwtypes.h"
#include "DHM.h"
#include "DHM_types.h"

extern void DHM_CtrlLogic_Init(uint8 *rty_SO_e_MotorCmd, uint8
  *rty_SO_e_MotorPwm, boolean *rty_SO_b_Error);
extern void DHM_CtrlLogic(boolean rtu_SI_b_DoorHndFoldReq, boolean
  rtu_SI_b_DoorHndUnfoldReq, uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm,
  boolean *rty_SO_b_Error, DW_CtrlLogic_DHM_T *localDW);
extern void DHM_DoorHndPos_Init(HndPos_Sts_E *rty_SO_m_DoorHndPosSts, sint16
  *rty_SO_s_MaxSoftPos, sint16 *rty_SO_s_MinSoftPos, sint16 *rty_SO_s_IceBrkPos);
extern void DHM_DoorHndPos(HndPos_Sts_E *rty_SO_m_DoorHndPosSts,
  DW_DoorHndPos_DHM_T *localDW);
extern void DHM_LearnLogic_Init(uint8 *rty_SO_e_LearnMotorCmd, uint8
  *rty_SO_e_LearnMotorPwm, boolean *rty_SO_b_CorrectPosToZero, Learn_Sts_E
  *rty_SO_m_LearnSts, sint16 *rty_SO_s_MaxPos, boolean *rty_SO_b_Learning);
extern void DHM_MotorLogic_Init(uint8 *rty_SO_e_MotorCmd, uint8
  *rty_SO_e_MotorPwm);
extern void DHM_MotorLogic(uint8 rtu_SI_e_LearnMotorCmd, uint8
  rtu_SI_e_LearnMotorPwm, uint8 rtu_SI_e_CtrlMotorCmd, uint8
  rtu_SI_e_CtrlMotorPwm, uint8 *rty_SO_e_MotorCmd, uint8 *rty_SO_e_MotorPwm,
  DW_MotorLogic_DHM_T *localDW);
extern void DHM_Stall_Init(boolean *rty_SO_b_HallStall);

#endif                                 /* RTW_HEADER_DHM_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
