/*
 * File: ert_main.c
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

#include <stdio.h>
#include "DHM.h"                       /* Model header file */

/* Example use case for call to exported function: DHM_Step */
extern void sample_usage_DHM_Step(void);
void sample_usage_DHM_Step(void)
{
  /* Set task inputs here */

  /* Call to exported function */
  DHM_Step();

  /* Read function outputs here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching exported functions to a real-time clock is target specific.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  DHM_initialize();
  while (rtmGetErrorStatus(DHM_M) == (NULL)) {
    /*  Perform application tasks here. */
  }

  /* Terminate model */
  DHM_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
