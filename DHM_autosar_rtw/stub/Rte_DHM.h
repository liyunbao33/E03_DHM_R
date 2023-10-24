/* This file contains stub implementations of the AUTOSAR RTE functions.
   The stub implementations can be used for testing the generated code in
   Simulink, for example, in SIL/PIL simulations of the component under
   test. Note that this file should be replaced with an appropriate RTE
   file when deploying the generated code outside of Simulink.

   This file is generated for:
   Atomic software component:  "DHM"
   ARXML schema: "4.3"
   File generated on: "24-Oct-2023 17:38:58"  */

#ifndef Rte_DHM_h
#define Rte_DHM_h
#include "Rte_Type.h"
#include "Compiler.h"

/* Data access functions */
#define Rte_Write_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig Rte_Write_DHM_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig

Std_ReturnType
  Rte_Write_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig(SInt16
  u);

#define Rte_Invalidate_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig Rte_Invalidate_DHM_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig

Std_ReturnType
  Rte_Invalidate_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig
  (void);

#define Rte_Write_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig Rte_Write_DHM_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig

Std_ReturnType
  Rte_Write_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig(SInt16
  u);

#define Rte_Invalidate_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig Rte_Invalidate_DHM_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig

Std_ReturnType
  Rte_Invalidate_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig
  (void);

#define Rte_Read_VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg Rte_Read_DHM_VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg

Std_ReturnType
  Rte_Read_VbINP_CAN_DoorHandleLrnReq_flg_VbINP_CAN_DoorHandleLrnReq_flg(Boolean*
  u);

#define Rte_Read_VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig Rte_Read_DHM_VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig

Std_ReturnType
  Rte_Read_VeINP_CAN_RDoorHandleReq_sig_VeINP_CAN_RDoorHandleReq_sig(UInt8* u);

#define Rte_Read_VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig Rte_Read_DHM_VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig

Std_ReturnType
  Rte_Read_VeINP_CAN_RRDoorHandleReq_sig_VeINP_CAN_RRDoorHandleReq_sig(UInt8* u);

#define Rte_Read_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig Rte_Read_DHM_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig

Std_ReturnType
  Rte_Read_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_FRDoorHandleLrnStsFromEE_sig
  (UInt8* u);

#define Rte_Read_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig Rte_Read_DHM_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig

Std_ReturnType
  Rte_Read_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig_VeINP_EPRM_RRDoorHandleLrnStsFromEE_sig
  (UInt8* u);

#define Rte_Read_VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig Rte_Read_DHM_VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig

Std_ReturnType
  Rte_Read_VsINP_HWA_PassHandleHall_sig_VsINP_HWA_PassHandleHall_sig(SInt16* u);

#define Rte_Read_VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig Rte_Read_DHM_VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig

Std_ReturnType Rte_Read_VsINP_HWA_RRHandleHall_sig_VsINP_HWA_RRHandleHall_sig
  (SInt16* u);

#define Rte_Write_VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig Rte_Write_DHM_VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig(UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig Rte_Invalidate_DHM_VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_FRDoorHandleSts_sig_VeOUT_DHM_FRDoorHandleSts_sig
  (void);

#define Rte_Write_VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig Rte_Write_DHM_VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig(UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig Rte_Invalidate_DHM_VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_RRDoorHandleSts_sig_VeOUT_DHM_RRDoorHandleSts_sig
  (void);

#define Rte_Write_VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg Rte_Write_DHM_VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg

Std_ReturnType Rte_Write_VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg Rte_Invalidate_DHM_VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_DHM_FRHadUnfold_flg_VbOUT_DHM_FRHadUnfold_flg(void);

#define Rte_Write_VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg Rte_Write_DHM_VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg

Std_ReturnType Rte_Write_VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg(Boolean
  u);

#define Rte_Invalidate_VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg Rte_Invalidate_DHM_VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg

Std_ReturnType Rte_Invalidate_VbOUT_DHM_FRHadFold_flg_VbOUT_DHM_FRHadFold_flg
  (void);

#define Rte_Write_VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg Rte_Write_DHM_VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg

Std_ReturnType
  Rte_Write_VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg(Boolean u);

#define Rte_Invalidate_VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg Rte_Invalidate_DHM_VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_DHM_RRHandleUnfold_flg_VbOUT_DHM_RRHandleUnfold_flg(void);

#define Rte_Write_VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg Rte_Write_DHM_VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg

Std_ReturnType Rte_Write_VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg
  (Boolean u);

#define Rte_Invalidate_VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg Rte_Invalidate_DHM_VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg

Std_ReturnType
  Rte_Invalidate_VbOUT_DHM_RRHandleFold_flg_VbOUT_DHM_RRHandleFold_flg(void);

#define Rte_Write_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig Rte_Write_DHM_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig

Std_ReturnType
  Rte_Write_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig(SInt16
  u);

#define Rte_Invalidate_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig Rte_Invalidate_DHM_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig

Std_ReturnType
  Rte_Invalidate_VsOUT_DHM_FRDoorHandleToEE_sig_VsOUT_DHM_FRDoorHandleToEE_sig
  (void);

#define Rte_Write_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig Rte_Write_DHM_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig

Std_ReturnType
  Rte_Write_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig(SInt16
  u);

#define Rte_Invalidate_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig Rte_Invalidate_DHM_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig

Std_ReturnType
  Rte_Invalidate_VsOUT_DHM_RRDoorHandleToEE_sig_VsOUT_DHM_RRDoorHandleToEE_sig
  (void);

#define Rte_Write_VeOUT_DHM_FRDoorHandleLrnSts_sig_VeOUT_DHM_FRDoorHandleLrnSts_sig Rte_Write_DHM_VeOUT_DHM_FRDoorHandleLrnSts_sig_VeOUT_DHM_FRDoorHandleLrnSts_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_FRDoorHandleLrnSts_sig_VeOUT_DHM_FRDoorHandleLrnSts_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_FRDoorHandleLrnSts_sig_VeOUT_DHM_FRDoorHandleLrnSts_sig Rte_Invalidate_DHM_VeOUT_DHM_FRDoorHandleLrnSts_sig_VeOUT_DHM_FRDoorHandleLrnSts_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_FRDoorHandleLrnSts_sig_VeOUT_DHM_FRDoorHandleLrnSts_sig
  (void);

#define Rte_Write_VeOUT_DHM_RRDoorHandleLrnSts_sig_VeOUT_DHM_RRDoorHandleLrnSts_sig Rte_Write_DHM_VeOUT_DHM_RRDoorHandleLrnSts_sig_VeOUT_DHM_RRDoorHandleLrnSts_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_RRDoorHandleLrnSts_sig_VeOUT_DHM_RRDoorHandleLrnSts_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_RRDoorHandleLrnSts_sig_VeOUT_DHM_RRDoorHandleLrnSts_sig Rte_Invalidate_DHM_VeOUT_DHM_RRDoorHandleLrnSts_sig_VeOUT_DHM_RRDoorHandleLrnSts_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_RRDoorHandleLrnSts_sig_VeOUT_DHM_RRDoorHandleLrnSts_sig
  (void);

#define Rte_Write_VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig Rte_Write_DHM_VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig Rte_Invalidate_DHM_VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_FRDoorHandleLrnStsEE_sig_VeOUT_DHM_FRDoorHandleLrnStsEE_sig
  (void);

#define Rte_Write_VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig Rte_Write_DHM_VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Write_VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig
  (UInt8 u);

#define Rte_Invalidate_VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig Rte_Invalidate_DHM_VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig

Std_ReturnType
  Rte_Invalidate_VeOUT_DHM_RRDoorHandleLrnStsEE_sig_VeOUT_DHM_RRDoorHandleLrnStsEE_sig
  (void);

/* Entry point functions */
extern FUNC(void, DHM_CODE) DHM_Init(void);
extern FUNC(void, DHM_CODE) DHM_Step(void);

#endif
