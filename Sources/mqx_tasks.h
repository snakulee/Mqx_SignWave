/** ###################################################################
**     Filename    : mqx_tasks.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-15, 14:02, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Task_Default - void Task_Default(void* task_init_data);
**
** ###################################################################*/

#ifndef __mqx_tasks_H
#define __mqx_tasks_H
/* MODULE mqx_tasks */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "MQX1.h"
#include "SystemTimer1.h"
#include "Console.h"
#include "IO1.h"
#include "DrvPwmTimerRG.h"
#include "DrvPwmTimerB.h"
#include "DrvI2c0.h"
#include "DrvI2c1.h"
#include "DrvDac2V.h"
#include "PE_LDD.h"


typedef struct
{
	volatile bool Sent;
	volatile bool Received;
}TDataState;

typedef struct
{
	volatile uint32_t u32_dac_val;
}TDacUsrData;

void Task_Default(uint32_t task_init_data);
/*
** ===================================================================
**     Event       :  Task_Default (module mqx_tasks)
**
**     Component   :  Task1 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/




void Task_Led(uint32_t task_init_data);
/*
** ===================================================================
**     Event       :  Task_Led (module mqx_tasks)
**
**     Component   :  Task2 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/



void Task_Dac(uint32_t task_init_data);
/*
** ===================================================================
**     Event       :  Task_Dac (module mqx_tasks)
**
**     Component   :  Task2 [MQXLite_task]
**     Description :
**         MQX task routine. The routine is generated into mqx_tasks.c
**         file.
**     Parameters  :
**         NAME            - DESCRIPTION
**         task_init_data  - 
**     Returns     : Nothing
** ===================================================================
*/

/* END mqx_tasks */
#endif /* __mqx_tasks_H*/

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
