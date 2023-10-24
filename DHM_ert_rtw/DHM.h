/*
 * File: DHM.h
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

#ifndef RTW_HEADER_DHM_h_
#define RTW_HEADER_DHM_h_
#ifndef DHM_COMMON_INCLUDES_
#define DHM_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DHM_COMMON_INCLUDES_ */

#include "DHM_types.h"
#include "Rte_Type.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S12>/CtrlLogic' */
typedef struct {
  uint8_T is_active_c1_DoorHndDriver;  /* '<S12>/CtrlLogic' */
  uint8_T is_Ctrl;                     /* '<S12>/CtrlLogic' */
  uint8_T is_Unfold;                   /* '<S12>/CtrlLogic' */
  uint8_T is_Fold;                     /* '<S12>/CtrlLogic' */
  uint8_T temporalCounter_i1;          /* '<S12>/CtrlLogic' */
  boolean_T SI_b_DoorHndUnfoldReq_prev;/* '<S12>/CtrlLogic' */
  boolean_T SI_b_DoorHndUnfoldReq_start;/* '<S12>/CtrlLogic' */
  boolean_T SI_b_DoorHndFoldReq_prev;  /* '<S12>/CtrlLogic' */
  boolean_T SI_b_DoorHndFoldReq_start; /* '<S12>/CtrlLogic' */
} DW_CtrlLogic_DHM_T;

/* Block states (default storage) for system '<S12>/DoorHndPos' */
typedef struct {
  uint8_T is_active_c5_DoorHndDriver;  /* '<S12>/DoorHndPos' */
} DW_DoorHndPos_DHM_T;

/* Block states (default storage) for system '<S12>/MotorLogic' */
typedef struct {
  uint8_T is_active_c4_DoorHndDriver;  /* '<S12>/MotorLogic' */
} DW_MotorLogic_DHM_T;

/* Block signals (default storage) */
typedef struct {
  uint8_T SO_e_LearnMotorCmd;          /* '<S13>/LearnLogic' */
  uint8_T SO_e_LearnMotorPwm;          /* '<S13>/LearnLogic' */
  uint8_T SO_e_LearnMotorCmd_p;        /* '<S12>/LearnLogic' */
  uint8_T SO_e_LearnMotorPwm_f;        /* '<S12>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts;           /* '<S13>/LearnLogic' */
  Learn_Sts_E SO_m_LearnSts_n;         /* '<S12>/LearnLogic' */
} B_DHM_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_MotorLogic_DHM_T sf_MotorLogic_j; /* '<S13>/MotorLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos_g; /* '<S13>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic_g;   /* '<S13>/CtrlLogic' */
  DW_MotorLogic_DHM_T sf_MotorLogic;   /* '<S12>/MotorLogic' */
  DW_DoorHndPos_DHM_T sf_DoorHndPos;   /* '<S12>/DoorHndPos' */
  DW_CtrlLogic_DHM_T sf_CtrlLogic;     /* '<S12>/CtrlLogic' */
} DW_DHM_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  SInt16 VsINP_HWA_PassHandleHall_sig_Vs;
        /* '<Root>/VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig' */
  SInt16 VsINP_HWA_RRHandleHall_sig_VsIN;
            /* '<Root>/VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig' */
  UInt8 VeINP_CAN_RDoorHandleReq_sig_Ve;
        /* '<Root>/VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig' */
  UInt8 VeINP_CAN_RRDoorHandleReq_sig_V;
      /* '<Root>/VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig' */
  SInt16 VsINP_EPRM_FRDoorHandleFromEE_s;
  /* '<Root>/VsINP_EPRM_FRDoorHandleFromEE_sig_VsINP_EPRM_FRDoorHandleFromEE_sig' */
  SInt16 VsINP_EPRM_RRDoorHandleFromEE_s;
  /* '<Root>/VsINP_EPRM_RRDoorHandleFromEE_sig_VsINP_EPRM_RRDoorHandleFromEE_sig' */
  Boolean VbINP_CAN_DoorHandleLrnReq_flg_;
    /* '<Root>/VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg' */
  UInt8 VeINP_EPRM_FRDoorHandleLrnStsFr;
  /* '<Root>/VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig' */
  UInt8 VeINP_EPRM_RRDoorHandleLrnStsFr;
  /* '<Root>/VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig' */
} ExtU_DHM_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  UInt8 VeOUT_DHM_FRDoorHandleSts_sig_V;
      /* '<Root>/VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig' */
  UInt8 VeOUT_DHM_RRDoorHandleSts_sig_V;
      /* '<Root>/VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig' */
  Boolean VbOUT_DHM_FRHadUnfold_flg_VbOUT;
              /* '<Root>/VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg' */
  Boolean VbOUT_DHM_FRHadFold_flg_VbOUT_D;
                  /* '<Root>/VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg' */
  Boolean VbOUT_DHM_RRHandleUnfold_flg_Vb;
        /* '<Root>/VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg' */
  Boolean VbOUT_DHM_RRHandleFold_flg_VbOU;
            /* '<Root>/VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg' */
  SInt16 VsOUT_DHM_FRDoorHandleToEE_sig_;
    /* '<Root>/VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig' */
  SInt16 VsOUT_DHM_RRDoorHandleToEE_sig_;
    /* '<Root>/VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig' */
  UInt8 VeOUT_DHM_FRDoorHandleLrnSts_si;
  /* '<Root>/VeOUT_DHM_FRDoorHandleLrnSts_sig_VeOUT_DHM_FRDoorHandleLrnSts_sig' */
  UInt8 VeOUT_DHM_RRDoorHandleLrnSts_si;
  /* '<Root>/VeOUT_DHM_RRDoorHandleLrnSts_sig_VeOUT_DHM_RRDoorHandleLrnSts_sig' */
  UInt8 VeOUT_DHM_FRDoorHandleLrnStsEE_;
  /* '<Root>/VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig' */
  UInt8 VeOUT_DHM_RRDoorHandleLrnStsEE_;
  /* '<Root>/VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig' */
} ExtY_DHM_T;

/* Real-time Model Data Structure */
struct tag_RTM_DHM_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_DHM_T DHM_B;

/* Block states (default storage) */
extern DW_DHM_T DHM_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_DHM_T DHM_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_DHM_T DHM_Y;

/* Model entry point functions */
extern void DHM_initialize(void);
extern void DHM_terminate(void);

/* Exported entry point function */
extern void DHM_Step(void);

/* Real-time Model object */
extern RT_MODEL_DHM_T *const DHM_M;

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
