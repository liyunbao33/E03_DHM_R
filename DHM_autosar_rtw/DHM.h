/*
 * File: DHM.h
 *
 * Code generated for Simulink model 'DHM'.
 *
 * Model version                  : 1.51
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Oct  7 08:48:48 2023
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

/* Block states (default storage) for system '<S8>/CtrlLogic' */
typedef struct {
  uint8 is_active_c1_DoorHndDriver;    /* '<S8>/CtrlLogic' */
  uint8 is_Ctrl;                       /* '<S8>/CtrlLogic' */
  uint8 is_Unfold;                     /* '<S8>/CtrlLogic' */
  uint8 is_Icebreak;                   /* '<S8>/CtrlLogic' */
  uint8 is_Fold;                       /* '<S8>/CtrlLogic' */
  uint8 temporalCounter_i1;            /* '<S8>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_prev;  /* '<S8>/CtrlLogic' */
  boolean SI_b_DoorHndUnfoldReq_start; /* '<S8>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_prev;    /* '<S8>/CtrlLogic' */
  boolean SI_b_DoorHndFoldReq_start;   /* '<S8>/CtrlLogic' */
} DW_CtrlLogic_DHM_T;

/* Block states (default storage) for system '<S8>/DoorHndPos' */
typedef struct {
  uint8 is_active_c5_DoorHndDriver;    /* '<S8>/DoorHndPos' */
} DW_DoorHndPos_DHM_T;

/* Block states (default storage) for system '<S8>/LearnLogic' */
typedef struct {
  uint8 is_active_c3_DoorHndDriver;    /* '<S8>/LearnLogic' */
  uint8 is_c3_DoorHndDriver;           /* '<S8>/LearnLogic' */
  uint8 is_LearnLogic;                 /* '<S8>/LearnLogic' */
  uint8 SI_e_AutoLearnCount;           /* '<S8>/LearnLogic' */
  uint8 temporalCounter_i1;            /* '<S8>/LearnLogic' */
  boolean SI_b_LearnReq_prev;          /* '<S8>/LearnLogic' */
  boolean SI_b_LearnReq_start;         /* '<S8>/LearnLogic' */
} DW_LearnLogic_DHM_T;

/* Block states (default storage) for system '<S8>/MotorLogic' */
typedef struct {
  uint8 is_active_c4_DoorHndDriver;    /* '<S8>/MotorLogic' */
} DW_MotorLogic_DHM_T;

/* Block states (default storage) for system '<S8>/Stall' */
typedef struct {
  sint16 SL_s_CurrentPos_Old;          /* '<S8>/Stall' */
  uint8 is_active_c2_DoorHndDriver;    /* '<S8>/Stall' */
  uint8 is_Stall_Handler;              /* '<S8>/Stall' */
  uint8 temporalCounter_i1;            /* '<S8>/Stall' */
} DW_Stall_DHM_T;

/* Block signals (default storage) */
typedef struct tag_B_DHM_T {
  SInt16 TmpSignalConversionAtVsINP_HWA_;
  SInt16 TmpSignalConversionAtVsINP_HW_n;
  sint16 SO_s_MaxPos;                  /* '<S9>/LearnLogic' */
  sint16 SO_s_MaxSoftPos;              /* '<S9>/DoorHndPos' */
  sint16 SO_s_MinSoftPos;              /* '<S9>/DoorHndPos' */
  sint16 SO_s_IceBrkPos;               /* '<S9>/DoorHndPos' */
  sint16 SO_s_MaxPos_g;                /* '<S8>/LearnLogic' */
  sint16 SO_s_MaxSoftPos_b;            /* '<S8>/DoorHndPos' */
  sint16 SO_s_MinSoftPos_i;            /* '<S8>/DoorHndPos' */
  sint16 SO_s_IceBrkPos_d;             /* '<S8>/DoorHndPos' */
  uint8 SO_e_MotorCmd;                 /* '<S9>/MotorLogic' */
  uint8 SO_e_MotorCmd_c;               /* '<S9>/LearnLogic' */
  uint8 SO_e_MotorPwm_m;               /* '<S9>/LearnLogic' */
  uint8 SO_e_MotorCmd_i;               /* '<S9>/CtrlLogic' */
  uint8 SO_e_MotorPwm_ml;              /* '<S9>/CtrlLogic' */
  uint8 SO_e_MotorCmd_l;               /* '<S8>/MotorLogic' */
  uint8 SO_e_MotorCmd_f;               /* '<S8>/LearnLogic' */
  uint8 SO_e_MotorPwm_d;               /* '<S8>/LearnLogic' */
  uint8 SO_e_MotorCmd_fa;              /* '<S8>/CtrlLogic' */
  uint8 SO_e_MotorPwm_h;               /* '<S8>/CtrlLogic' */
  boolean Compare;                     /* '<S4>/Compare' */
  boolean Compare_i;                   /* '<S5>/Compare' */
  boolean Compare_p;                   /* '<S6>/Compare' */
  boolean Compare_n;                   /* '<S7>/Compare' */
  boolean SO_b_HallStall;              /* '<S9>/Stall' */
  boolean SO_b_MotorA;                 /* '<S9>/MotorLogic' */
  boolean SO_b_MotorB;                 /* '<S9>/MotorLogic' */
  boolean SO_b_HallStall_m;            /* '<S8>/Stall' */
  boolean SO_b_MotorA_j;               /* '<S8>/MotorLogic' */
  boolean SO_b_MotorB_c;               /* '<S8>/MotorLogic' */
  Learn_Sts_E SO_m_LearnSts;           /* '<S9>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts_g;         /* '<S8>/LearnLogic' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_DHM_T {
  sint16 UnitDelay5_DSTATE;            /* '<S8>/Unit Delay5' */
  sint16 UnitDelay5_DSTATE_o;          /* '<S9>/Unit Delay5' */
  uint8 UnitDelay1_DSTATE;             /* '<S8>/Unit Delay1' */
  uint8 UnitDelay1_DSTATE_b;           /* '<S9>/Unit Delay1' */
  boolean UnitDelay4_DSTATE;           /* '<S8>/Unit Delay4' */
  boolean UnitDelay4_DSTATE_o;         /* '<S9>/Unit Delay4' */
  uint8 E03_DHM_R;                     /* '<S3>/Data Store Memory' */
  DW_Stall_DHM_T sf_Stall_k;           /* '<S9>/Stall' */
  DW_MotorLogic_DHM_T sf_MotorLogic_p; /* '<S9>/MotorLogic' */
  DW_LearnLogic_DHM_T sf_LearnLogic_m; /* '<S9>/LearnLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos_b; /* '<S9>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic_j;   /* '<S9>/CtrlLogic' */
  DW_Stall_DHM_T sf_Stall;             /* '<S8>/Stall' */
  DW_MotorLogic_DHM_T sf_MotorLogic;   /* '<S8>/MotorLogic' */
  DW_LearnLogic_DHM_T sf_LearnLogic;   /* '<S8>/LearnLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos;   /* '<S8>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic;     /* '<S8>/CtrlLogic' */
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
 * '<S8>'   : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver'
 * '<S9>'   : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver'
 * '<S10>'  : 'DHM/DHM_Step_sys/DHM/Recycle Bin'
 * '<S11>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/CtrlLogic'
 * '<S12>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/DoorHndPos'
 * '<S13>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/LearnLogic'
 * '<S14>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/MotorLogic'
 * '<S15>'  : 'DHM/DHM_Step_sys/DHM/FRDoorHndDriver/Stall'
 * '<S16>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/CtrlLogic'
 * '<S17>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/DoorHndPos'
 * '<S18>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/LearnLogic'
 * '<S19>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/MotorLogic'
 * '<S20>'  : 'DHM/DHM_Step_sys/DHM/RLDoorHndDriver/Stall'
 */
#endif                                 /* RTW_HEADER_DHM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
