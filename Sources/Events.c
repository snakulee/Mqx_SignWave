/** ###################################################################
**     Filename    : Events.c
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
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  DrvI2c0_OnMasterBlockSent (module Events)
**
**     Component   :  DrvI2c0 [I2C_LDD]
**     Description :
**         This event is called when I2C in master mode finishes the
**         transmission of the data successfully. This event is not
**         available for the SLAVE mode and if MasterSendBlock is
**         disabled. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void DrvI2c0_OnMasterBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	TDataState *I2c0_DataState = (TDataState*)UserDataPtr;
	I2c0_DataState->Sent = TRUE;
}

/*
** ===================================================================
**     Event       :  DrvI2c0_OnMasterBlockReceived (module Events)
**
**     Component   :  DrvI2c0 [I2C_LDD]
**     Description :
**         This event is called when I2C is in master mode and finishes
**         the reception of the data successfully. This event is not
**         available for the SLAVE mode and if MasterReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void DrvI2c0_OnMasterBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	TDataState *I2c0_DataState = (TDataState*)UserDataPtr;
	I2c0_DataState->Received = TRUE;
}

/*
** ===================================================================
**     Event       :  DrvI2c0_OnError (module Events)
**
**     Component   :  DrvI2c0 [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void DrvI2c0_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  DrvPwmTimerRG_OnCounterRestart (module Events)
**
**     Component   :  DrvPwmTimerRG [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void DrvPwmTimerRG_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  DrvPwmTimerRG_OnChannel0 (module Events)
**
**     Component   :  DrvPwmTimerRG [TimerUnit_LDD]
**     Description :
**         Called if compare register match the counter registers or
**         capture register has a new content. OnChannel0 event and
**         Timer unit must be enabled. See <SetEventMask> and
**         <GetEventMask> methods. This event is available only if a
**         <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void DrvPwmTimerRG_OnChannel0(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  DrvI2c1_OnMasterBlockSent (module Events)
**
**     Component   :  DrvI2c1 [I2C_LDD]
**     Description :
**         This event is called when I2C in master mode finishes the
**         transmission of the data successfully. This event is not
**         available for the SLAVE mode and if MasterSendBlock is
**         disabled. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void DrvI2c1_OnMasterBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
  	TDataState *I2c1_DataState = (TDataState*)UserDataPtr;
	I2c1_DataState->Sent = TRUE;

}

/*
** ===================================================================
**     Event       :  DrvI2c1_OnMasterBlockReceived (module Events)
**
**     Component   :  DrvI2c1 [I2C_LDD]
**     Description :
**         This event is called when I2C is in master mode and finishes
**         the reception of the data successfully. This event is not
**         available for the SLAVE mode and if MasterReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void DrvI2c1_OnMasterBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	TDataState *I2c1_DataState = (TDataState*)UserDataPtr;
	I2c1_DataState->Received = TRUE;

}

/*
** ===================================================================
**     Event       :  DrvI2c1_OnError (module Events)
**
**     Component   :  DrvI2c1 [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void DrvI2c1_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
