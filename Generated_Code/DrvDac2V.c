/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : DrvDac2V.c
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

/* MODULE DrvDac2V. */

/* MQX Lite include files */
#include "mqxlite.h"
#include "mqxlite_prv.h"
#include "DrvDac2V.h"

typedef struct {
  LDD_TDeviceData *DmaTransferDeviceDataPtr; /* DMATransfer device data structure */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} DrvDac2V_TDeviceData;                /* Device data structure type */

/* {MQXLite RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static DrvDac2V_TDeviceData DeviceDataPtr__DEFAULT_RTOS_ALLOC;

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
LDD_TDeviceData* DrvDac2V_Init(LDD_TUserData *UserDataPtr)
{
  DrvDac2V_TDeviceData *DeviceDataPtr; /* LDD device structure */

  /* Allocate HAL device structure */
  /* {MQXLite RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPtr = &DeviceDataPtr__DEFAULT_RTOS_ALLOC;
  DeviceDataPtr->DmaTransferDeviceDataPtr = NULL; /* DMA is not used */
  DeviceDataPtr->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* Enable device clock gate */
  /* SIM_SCGC6: DAC0=1 */
  SIM_SCGC6 |= SIM_SCGC6_DAC0_MASK;                                                   
  DAC_PDD_EnableDevice(DAC0_BASE_PTR,PDD_DISABLE); /* Disable device */
  /* PORTE_PCR30: ISF=0,MUX=0 */
  PORTE_PCR30 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));                                                   
  /* DAC0_DAT0H: ??=0,??=0,??=0,??=0,DATA1=9 */
  DAC0_DAT0H = DAC_DATH_DATA1(0x09);                                                   
  /* DAC0_DAT0L: DATA0=0xB2 */
  DAC0_DAT0L = DAC_DATL_DATA0(0xB2);                                                   
  /* DAC0_C2: ??=0,??=0,??=0,DACBFRP=0,??=1,??=1,??=1,DACBFUP=1 */
  DAC0_C2 = (DAC_C2_DACBFUP_MASK | 0x0EU);                                                   
  /* DAC0_C1: DMAEN=0,??=0,??=0,??=0,??=0,DACBFMD=0,??=0,DACBFEN=0 */
  DAC0_C1 = 0x00U;                                                   
  /* DAC0_SR: ??=0,??=0,??=0,??=0,??=0,??=0,DACBFRPTF=0,DACBFRPBF=0 */
  DAC0_SR = 0x00U;                                                   
  /* DAC0_C0: DACEN=1,DACRFS=0,DACTRGSEL=0,DACSWTRG=0,LPEN=0,??=0,DACBTIEN=0,DACBBIEN=0 */
  DAC0_C0 = DAC_C0_DACEN_MASK;                                                   
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_DrvDac2V_ID,DeviceDataPtr);
  return ((LDD_TDeviceData*)DeviceDataPtr); /* Return pointer to the data data structure */
}

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
void DrvDac2V_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter not used, suppress not used argument warning */
  DAC_PDD_EnableDevice(DAC0_BASE_PTR,PDD_DISABLE); /* Disable device */
  /* Deallocation of the device structure */
  /* {MQXLite RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
  /* Disable device clock gate */
  /* SIM_SCGC6: DAC0=0 */
  SIM_SCGC6 &= (uint32_t)~(uint32_t)(SIM_SCGC6_DAC0_MASK);                                                   
}

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
LDD_TError DrvDac2V_SetValue(LDD_TDeviceData *DeviceDataPtr, LDD_DAC_TData Data)
{
  (void)DeviceDataPtr;                 /* Parameter not used, suppress not used argument warning */
  DAC_PDD_SetData(DAC0_BASE_PTR,(uint16_t)Data,0U);
  return ERR_OK;
}



/* END DrvDac2V. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/