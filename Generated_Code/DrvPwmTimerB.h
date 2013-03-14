/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : DrvPwmTimerB.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : TimerUnit_LDD
**     Version     : Component 01.139, Driver 01.09, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-21, 14:56, # CodeGen: 9
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : DrvPwmTimerB
**          Module name                                    : TPM0
**          Counter                                        : TPM0_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : Optimal
**          Input clock source                             : Internal
**            Counter frequency                            : 24 MHz
**          Counter restart                                : On-overrun
**            Overrun period                               : 2.730667 ms
**            Interrupt                                    : Disabled
**          Channel list                                   : 1
**            Channel 0                                    : 
**              Mode                                       : Compare
**                Compare                                  : TPM0_C1V
**                Offset                                   : 43690 timer-ticks
**                Output on compare                        : Set
**                  Output on overrun                      : Clear
**                  Initial state                          : Low
**                  Output pin                             : ADC0_SE5b/PTD1/SPI0_SCK/TPM0_CH1
**                  Output pin signal                      : 
**                Interrupt                                : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Disabled
**              OnChannel0                                 : Disabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
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
**         Init            - LDD_TDeviceData* DrvPwmTimerB_Init(LDD_TUserData *UserDataPtr);
**         Deinit          - void DrvPwmTimerB_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable          - LDD_TError DrvPwmTimerB_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable         - LDD_TError DrvPwmTimerB_Disable(LDD_TDeviceData *DeviceDataPtr);
**         GetCounterValue - DrvPwmTimerB_TValueType DrvPwmTimerB_GetCounterValue(LDD_TDeviceData...
**         SetOffsetTicks  - LDD_TError DrvPwmTimerB_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr,...
**         GetOffsetTicks  - LDD_TError DrvPwmTimerB_GetOffsetTicks(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __DrvPwmTimerB_H
#define __DrvPwmTimerB_H

/* MODULE DrvPwmTimerB. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "PE_LDD.h"
#include "TPM_PDD.h"
#include "Cpu.h"


#ifndef __BWUserType_DrvPwmTimerB_TValueType
#define __BWUserType_DrvPwmTimerB_TValueType
  typedef uint32_t DrvPwmTimerB_TValueType ; /* Type for data parameters of methods */
#endif
#define DrvPwmTimerB_CNT_INP_FREQ_U_0 0x016E3600UL /* Counter input frequency in Hz */
#define DrvPwmTimerB_CNT_INP_FREQ_R_0 23999808.00153599F /* Counter input frequency in Hz */
#define DrvPwmTimerB_CNT_INP_FREQ_COUNT 0U /* Count of predefined counter input frequencies */
#define DrvPwmTimerB_PERIOD_TICKS 0x00010000UL /* Initialization value of period in 'counter ticks' */
#define DrvPwmTimerB_NUMBER_OF_CHANNELS 0x01U /* Count of predefined channels */
#define DrvPwmTimerB_COUNTER_WIDTH 0x10U /* Counter width in bits  */
#define DrvPwmTimerB_COUNTER_DIR DIR_UP /* Direction of counting */
#define DrvPwmTimerB_OFFSET_0_TICKS 0xAAAAul /* Initialization value of offset as 'counter ticks' for channel 0 */
/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define DrvPwmTimerB_PRPH_BASE_ADDRESS  0x40038000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define DrvPwmTimerB_Init_METHOD_ENABLED
#define DrvPwmTimerB_Deinit_METHOD_ENABLED
#define DrvPwmTimerB_Enable_METHOD_ENABLED
#define DrvPwmTimerB_Disable_METHOD_ENABLED
#define DrvPwmTimerB_GetCounterValue_METHOD_ENABLED
#define DrvPwmTimerB_SetOffsetTicks_METHOD_ENABLED
#define DrvPwmTimerB_GetOffsetTicks_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */



LDD_TDeviceData* DrvPwmTimerB_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  DrvPwmTimerB_Init (component TimerUnit_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property <"Enable in init. code"> is set to "yes" value then
**         the device is also enabled (see the description of the
**         <Enable> method). In this case the <Enable> method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the <Deinit>
**         must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/

void DrvPwmTimerB_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DrvPwmTimerB_Deinit (component TimerUnit_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError DrvPwmTimerB_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DrvPwmTimerB_Enable (component TimerUnit_LDD)
**
**     Description :
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask). The method is
**         not available if the counter can't be disabled/enabled by HW.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError DrvPwmTimerB_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DrvPwmTimerB_Disable (component TimerUnit_LDD)
**
**     Description :
**         Disables the component - it stops signal generation and
**         events calling. The method is not available if the counter
**         can't be disabled/enabled by HW.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

DrvPwmTimerB_TValueType DrvPwmTimerB_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DrvPwmTimerB_GetCounterValue (component TimerUnit_LDD)
**
**     Description :
**         Returns the content of counter register. This method can be
**         used both if counter is enabled and if counter is disabled.
**         The method is not available if HW doesn't allow reading of
**         the counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Counter value (number of counted ticks).
** ===================================================================
*/

LDD_TError DrvPwmTimerB_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, DrvPwmTimerB_TValueType Ticks);
/*
** ===================================================================
**     Method      :  DrvPwmTimerB_SetOffsetTicks (component TimerUnit_LDD)
**
**     Description :
**         Sets the new offset value to channel specified by the
**         parameter ChannelIdx. It is user responsibility to use value
**         below selected period. This method is available when at
**         least one channel is configured.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         ChannelIdx      - Index of the component
**                           channel.
**         Ticks           - Number of counter ticks to compare
**                           match.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range.
**                           ERR_NOTAVAIL -  The compare mode is not
**                           selected for selected channel
**                           ERR_PARAM_TICKS - Ticks parameter is out of
**                           possible range.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

LDD_TError DrvPwmTimerB_GetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, DrvPwmTimerB_TValueType *TicksPtr);
/*
** ===================================================================
**     Method      :  DrvPwmTimerB_GetOffsetTicks (component TimerUnit_LDD)
**
**     Description :
**         Returns the number of counter ticks to compare match channel
**         specified by the parameter ChannelIdx. See also method
**         <SetOffsetTicks>. This method is available when at least one
**         channel is configured.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         ChannelIdx      - Index of the component
**                           channel.
**       * TicksPtr        - Pointer to return value of the
**                           number of counter ticks to compare match.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range.
**                           ERR_NOTAVAIL -  The compare mode is not
**                           selected for selected channel.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/

/* END DrvPwmTimerB. */

#endif
/* ifndef __DrvPwmTimerB_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
