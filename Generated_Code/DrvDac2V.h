/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : DrvDac2V.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : DAC_LDD
**     Version     : Component 01.035, Driver 01.07, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-22, 19:12, # CodeGen: 21
**     Abstract    :
**         This component implements an internal D/A converter of the MCU.
**         It contains settings for converting various format of a values
**         to supported format of the D/A converter.
**
**     Settings    :
**          Component name                                 : DrvDac2V
**          D/A converter                                  : DAC0
**          Interrupt service/event                        : Disabled
**          Output pin                                     : yes
**            D/A channel (pin)                            : DAC0_OUT/ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1
**            D/A channel (pin) signal                     : 
**          Init value                                     : 2482
**          D/A resolution                                 : 12 bits
**          Data mode                                      : unsigned 16 bits, right justified
**          Low power mode                                 : Disabled
**          Voltage reference source                       : internal
**          Data buffer                                    : Disabled
**          DMA                                            : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnBufferEnd                                : Disabled
**              OnBufferStart                              : Disabled
**              OnComplete                                 : Disabled
**              OnError                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init     - LDD_TDeviceData* DrvDac2V_Init(LDD_TUserData *UserDataPtr);
**         Deinit   - void DrvDac2V_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetValue - LDD_TError DrvDac2V_SetValue(LDD_TDeviceData *DeviceDataPtr, LDD_DAC_TData...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __DrvDac2V_H
#define __DrvDac2V_H

/* MODULE DrvDac2V. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Cpu.h"

#include "DAC_PDD.h"
#include "PE_LDD.h"

/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define DrvDac2V_PRPH_BASE_ADDRESS  0x4003F000U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define DrvDac2V_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_DrvDac2V_ID))

/*  This constant contains mask of all events generated by Processor Expert */
#define DrvDac2V_AVAILABLE_EVENTS_MASK 0x00U
/* This constant contains minimal buffer size available on selected device. */
#define DrvDac2V_BUFFER_MIN_SIZE 0x01U
/* This constant contains maximal buffer size available on selected device. */
#define DrvDac2V_BUFFER_MAX_SIZE 0x02U

LDD_TDeviceData* DrvDac2V_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  DrvDac2V_Init (component DAC_LDD)
**
**     Description :
**         Initializes the device according to design-time
**         configuration properties. Allocates memory for the device
**         data structure. 
**         If the <Enable in init. code> is set to "yes" then the
**         device is also enabled (see the description of the Enable
**         method).
**         This method can be called only once. Before the second call
**         of Init the Deinit method must be called first. If DMA
**         service is enabled this method also initializes inherited
**         DMA Transfer component.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an events or callback parameter.
**     Returns     :
**         ---             - Device data structure pointer.
** ===================================================================
*/

void DrvDac2V_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DrvDac2V_Deinit (component DAC_LDD)
**
**     Description :
**         Disables the device and frees the device data structure
**         memory. If DMA service is enabled this method also
**         deinitializes inherited DMA Transfer component.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError DrvDac2V_SetValue(LDD_TDeviceData *DeviceDataPtr, LDD_DAC_TData Data);
/*
** ===================================================================
**     Method      :  DrvDac2V_SetValue (component DAC_LDD)
**
**     Description :
**         Sets DAC output voltage according to specified value.
**         Input data format is specified by <Data mode> property
**         settings. If selected formatting is not native for DAC
**         device which is used then any necessary transformations (e.g.
**         shifting) are done._/Note: This method is available only if
**         Data buffer is disabled./_
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure.
**         Data            - User data.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
** ===================================================================
*/

/* END DrvDac2V. */

#endif
/* ifndef __DrvDac2V_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/