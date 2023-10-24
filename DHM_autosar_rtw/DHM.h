/*
 * File: DHM.h
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

#ifndef RTW_HEADER_DHM_h_
#define RTW_HEADER_DHM_h_
#ifndef DHM_COMMON_INCLUDES_
#define DHM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_DHM.h"
#endif                                 /* DHM_COMMON_INCLUDES_ */

#include "DHM_types.h"
#include "Rte_Type.h"

/* Block states (default storage) for system '<S12>/CtrlLogic' */
typedef struct {
  uint8 is_active_c1_DoorHndDriver;    /* '<S12>/CtrlLogic' */
  uint8 is_Ctrl;                       /* '<S12>/CtrlLogic' */
  uint8 is_Unfold;                     /* '<S12>/CtrlLogic' */
  uint8 is_Fold;                       /* '<S12>/CtrlLogic' */
  uint8 temporalCounter_i1;            /* '<S12>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_prev;  /* '<S12>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_start; /* '<S12>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_prev;    /* '<S12>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_start;   /* '<S12>/CtrlLogic' */
} DW_CtrlLogic_DHM_T;

/* Block states (default storage) for system '<S12>/DoorHndPos' */
typedef struct {
  uint8 is_active_c5_DoorHndDriver;    /* '<S12>/DoorHndPos' */
} DW_DoorHndPos_DHM_T;

/* Block states (default storage) for system '<S12>/MotorLogic' */
typedef struct {
  uint8 is_active_c4_DoorHndDriver;    /* '<S12>/MotorLogic' */
} DW_MotorLogic_DHM_T;

/* Block signals (default storage) */
typedef struct tag_B_DHM_T {
  sint16 SO_s_MaxPos;                  /* '<S13>/LearnLogic' */
  sint16 SO_s_MaxSoftPos;              /* '<S13>/DoorHndPos' */
  sint16 SO_s_MinSoftPos;              /* '<S13>/DoorHndPos' */
  sint16 SO_s_IceBrkPos;               /* '<S13>/DoorHndPos' */
  sint16 SO_s_MaxPos_l;                /* '<S12>/LearnLogic' */
  sint16 SO_s_MaxSoftPos_j;            /* '<S12>/DoorHndPos' */
  sint16 SO_s_MinSoftPos_d;            /* '<S12>/DoorHndPos' */
  sint16 SO_s_IceBrkPos_f;             /* '<S12>/DoorHndPos' */
  uint8 SO_e_LearnMotorCmd;            /* '<S13>/LearnLogic' */
  uint8 SO_e_LearnMotorPwm;            /* '<S13>/LearnLogic' */
  uint8 SO_e_LearnMotorCmd_p;          /* '<S12>/LearnLogic' */
  uint8 SO_e_LearnMotorPwm_f;          /* '<S12>/LearnLogic' */
  boolean SO_b_HallStall;              /* '<S13>/Stall' */
  boolean SO_b_Learning;               /* '<S13>/LearnLogic' */
  boolean SO_b_HallStall_g;            /* '<S12>/Stall' */
  boolean SO_b_Learning_n;             /* '<S12>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts;           /* '<S13>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts_n;         /* '<S12>/LearnLogic' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_DHM_T {
  uint8 E03_DHM_R;                     /* '<S3>/Data Store Memory' */
  DW_MotorLogic_DHM_T sf_MotorLogic_j; /* '<S13>/MotorLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos_g; /* '<S13>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic_g;   /* '<S13>/CtrlLogic' */
  DW_MotorLogic_DHM_T sf_MotorLogic;   /* '<S12>/MotorLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos;   /* '<S12>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic;     /* '<S12>/CtrlLogic' */
} DW_DHM_T;

/* Block signals (default storage) */
extern B_DHM_T DHM_B;

/* Block states (default storage) */
extern DW_DHM_T DHM_DW;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DHM'
 * '<S1>'   : 'DHM/DHM_Init'
 * '<S2>'   : 'DHM/DHM_Step_sys'
 * '<S3>'   : 'DHM/DHM_Step_sys/DHM'
 * '<S4>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant'
 * '<S5>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant1'
 * '<S6>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant2'
 * '<S7>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant3'
 * '<S8>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant4'
 * '<S9>'   : 'DHM/DHM_Step_sys/DHM/Compare To Constant5'
 * '<S10>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant6'
 * '<S11>'  : 'DHM/DHM_Step_sys/DHM/Compare To Constant7'
 * '<S12>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver'
 * '<S13>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver'
 * '<S14>'  : 'DHM/DHM_Step_sys/DHM/Recycle Bin'
 * '<S15>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/CtrlLogic'
 * '<S16>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/DoorHndPos'
 * '<S17>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/LearnLogic'
 * '<S18>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/MotorLogic'
 * '<S19>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/Stall'
 * '<S20>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/CtrlLogic'
 * '<S21>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/DoorHndPos'
 * '<S22>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/LearnLogic'
 * '<S23>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/MotorLogic'
 * '<S24>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/Stall'
 */
#endif                                 /* RTW_HEADER_DHM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
