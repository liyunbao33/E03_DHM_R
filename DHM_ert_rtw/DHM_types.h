/*
 * File: DHM_types.h
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

#ifndef RTW_HEADER_DHM_types_h_
#define RTW_HEADER_DHM_types_h_
#include "Rte_Type.h"
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_Learn_Sts_E_
#define DEFINED_TYPEDEF_FOR_Learn_Sts_E_

typedef uint8_T Learn_Sts_E;

/* enum Learn_Sts_E */
#define Learn_Invalid                  ((Learn_Sts_E)0U)         /* Default value */
#define Learn_Success                  ((Learn_Sts_E)1U)
#define Learn_Fail                     ((Learn_Sts_E)2U)
#define Learn_Reserved                 ((Learn_Sts_E)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_HndPos_Sts_E_
#define DEFINED_TYPEDEF_FOR_HndPos_Sts_E_

typedef uint8_T HndPos_Sts_E;

/* enum HndPos_Sts_E */
#define Hnd_Fold                       ((HndPos_Sts_E)0U)        /* Default value */
#define Hnd_Unfold                     ((HndPos_Sts_E)1U)
#define Hnd_Unknown                    ((HndPos_Sts_E)2U)
#define Hnd_Reserved                   ((HndPos_Sts_E)3U)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_DHM_T RT_MODEL_DHM_T;

#endif                                 /* RTW_HEADER_DHM_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
