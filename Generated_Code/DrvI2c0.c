/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : DrvI2c0.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : I2C_LDD
**     Version     : Component 01.011, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-02-22, 13:57, # CodeGen: 14
**     Abstract    :
**          This component encapsulates the internal I2C communication
**          interface. The implementation of the interface is based
**          on the Philips I2C-bus specification version 2.0.
**          Interface features:
**          MASTER mode
**            - Multi master communication
**            - The combined format of communication possible
**              (see SendStop parameter in MasterSend/ReceiveBlock method)
**            - 7-bit slave addressing (10-bit addressing can be made as well)
**            - Acknowledge polling provided
**            - No wait state initiated when a slave device holds the SCL line low
**            - Holding of the SCL line low by slave device recognized as 'not available bus'
**            - Invalid start/stop condition detection provided
**          SLAVE mode
**            - 7-bit slave addressing
**            - General call address detection provided
**     Settings    :
**          Component name                                 : DrvI2c0
**          I2C channel                                    : I2C0
**          Interrupt service                              : Enabled
**            Interrupt                                    : INT_I2C0
**            Interrupt priority                           : medium priority
**          Settings                                       : 
**            Mode selection                               : MASTER
**            MASTER mode                                  : Enabled
**              Initialization                             : 
**                Address mode                             : 7-bit addressing
**                Target slave address init                : 1D
**            SLAVE mode                                   : Disabled
**            Pins                                         : 
**              SDA pin                                    : 
**                SDA pin                                  : PTE25/TPM0_CH1/I2C0_SDA
**                SDA pin signal                           : 
**              SCL pin                                    : 
**                SCL pin                                  : PTE24/TPM0_CH0/I2C0_SCL
**                SCL pin signal                           : 
**              High drive select                          : Disabled
**              Input Glitch filter                        : 0
**            Internal frequency (multiplier factor)       : 24 MHz
**            Bits 0-2 of Frequency divider register       : 101
**            Bits 3-5 of Frequency divider register       : 100
**            SCL frequency                                : 75 kHz
**            SDA Hold                                     : 2.042 us
**            SCL start Hold                               : 6.583 us
**            SCL stop Hold                                : 6.708 us
**            Control acknowledge bit                      : Disabled
**            Low timeout                                  : Disabled
**          Initialization                                 : 
**            Enabled in init code                         : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnMasterBlockSent                          : Enabled
**              OnMasterBlockReceived                      : Enabled
**              OnMasterByteReceived                       : Disabled
**              OnSlaveBlockSent                           : Disabled
**              OnSlaveBlockReceived                       : Disabled
**              OnSlaveByteReceived                        : Disabled
**              OnSlaveRxRequest                           : Disabled
**              OnSlaveTxRequest                           : Disabled
**              OnSlaveGeneralCallAddr                     : Disabled
**              OnSlaveSmBusCallAddr                       : Disabled
**              OnSlaveSmBusAlertResponse                  : Disabled
**              OnError                                    : Enabled
**              OnBusStopDetected                          : Disabled
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
**         Init               - LDD_TDeviceData* DrvI2c0_Init(LDD_TUserData *UserDataPtr);
**         Deinit             - void DrvI2c0_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         MasterSendBlock    - LDD_TError DrvI2c0_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         MasterReceiveBlock - LDD_TError DrvI2c0_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr,...
**         CheckBus           - LDD_TError DrvI2c0_CheckBus(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TBusState...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE DrvI2c0. */

#include "Events.h"
#include "DrvI2c0.h"
#include "PORT_PDD.h"
#include "I2C_PDD.h"
/* MQX Lite include files */
#include "mqxlite.h"
#include "mqxlite_prv.h"
#include "IO_Map.h"


/* SerFlag bits */
#define MASTER_IN_PROGRES       0x01U  /* Communication is in progress (Master) */

typedef struct {
  uint8_t SerFlag;                     /* Flags for serial communication */
                                       /* Bits: 0 - Running int from TX */
  LDD_I2C_TSendStop SendStop;          /* Enable/Disable generate send stop condition after transmission */
  LDD_I2C_TSize InpLenM;               /* The counter of input bufer's content */
  uint8_t *InpPtrM;                    /* Pointer to input buffer for Master mode */
  LDD_I2C_TSize OutLenM;               /* The counter of output bufer's content */
  uint8_t *OutPtrM;                    /* Pointer to output buffer for Master mode */
  LDD_RTOS_TISRVectorSettings SavedISRSettings; /* {MQXLite RTOS Adapter} Saved settings of allocated interrupt vector */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} DrvI2c0_TDeviceData;

typedef DrvI2c0_TDeviceData *DrvI2c0_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {MQXLite RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static DrvI2c0_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

#define AVAILABLE_EVENTS_MASK (LDD_I2C_ON_MASTER_BLOCK_SENT | LDD_I2C_ON_MASTER_BLOCK_RECEIVED | LDD_I2C_ON_ERROR)

/*
** ===================================================================
**     Method      :  DrvI2c0_Interrupt (component I2C_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void DrvI2c0_Interrupt(LDD_RTOS_TISRParameter _isrParameter)
{
  /* {MQXLite RTOS Adapter} ISR parameter is passed as parameter from RTOS interrupt dispatcher */
  DrvI2c0_TDeviceDataPtr DeviceDataPrv = (DrvI2c0_TDeviceDataPtr)_isrParameter;
  LDD_I2C_TErrorMask ErrorMask = 0x00U; /* Temporary variable for error mask */
  register uint8_t Status;             /* Temporary variable for status register */

  Status = I2C_PDD_ReadStatusReg(I2C0_BASE_PTR); /* Safe status register */
  I2C_PDD_ClearInterruptFlags(I2C0_BASE_PTR, (Status)); /* Clear interrupt flag */
  if (I2C_PDD_GetMasterMode(I2C0_BASE_PTR) == I2C_PDD_MASTER_MODE) { /* Is device in master mode? */
    if (I2C_PDD_GetTransmitMode(I2C0_BASE_PTR) == I2C_PDD_TX_DIRECTION) { /* Is device in Tx mode? */
      if ((Status & I2C_PDD_RX_ACKNOWLEDGE) != 0x00U){ /* NACK received? */
        I2C_PDD_SetMasterMode(I2C0_BASE_PTR, I2C_PDD_SLAVE_MODE); /* Switch device to slave mode (stop signal sent) */
        I2C_PDD_SetTransmitMode(I2C0_BASE_PTR, I2C_PDD_RX_DIRECTION); /* Switch to Rx mode */
        DeviceDataPrv->OutLenM = 0x00U; /* No character for sending */
        DeviceDataPrv->InpLenM = 0x00U; /* No character for reception */
        DeviceDataPrv->SerFlag &= (uint8_t)~(MASTER_IN_PROGRES); /* No character for sending or reception */
        ErrorMask |= LDD_I2C_MASTER_NACK; /* Set the Master Nack error mask */
      } else {
        if (DeviceDataPrv->OutLenM != 0x00U) { /* Is any char. for transmitting? */
          DeviceDataPrv->OutLenM--;    /* Decrease number of chars for the transmit */
          I2C_PDD_WriteDataReg(I2C0_BASE_PTR, *(DeviceDataPrv->OutPtrM)++); /* Send character */
        }
        else {
          if (DeviceDataPrv->InpLenM != 0x00U) { /* Is any char. for reception? */
            if (DeviceDataPrv->InpLenM == 0x01U) { /* If only one char to receive */
              I2C_PDD_EnableTransmitAcknowledge(I2C0_BASE_PTR, PDD_DISABLE); /* then transmit ACK disable */
            } else {
              I2C_PDD_EnableTransmitAcknowledge(I2C0_BASE_PTR, PDD_ENABLE); /* else transmit ACK enable */
            }
            I2C_PDD_SetTransmitMode(I2C0_BASE_PTR, I2C_PDD_RX_DIRECTION); /* Switch to Rx mode */
            (void)I2C_PDD_ReadDataReg(I2C0_BASE_PTR); /* Dummy read character */
          }
          else {
            DeviceDataPrv->SerFlag &= (uint8_t)~(MASTER_IN_PROGRES); /* Clear flag "busy" */
            if (DeviceDataPrv->SendStop == LDD_I2C_SEND_STOP) {
              I2C_PDD_SetMasterMode(I2C0_BASE_PTR, I2C_PDD_SLAVE_MODE); /* Switch device to slave mode (stop signal sent) */
              I2C_PDD_SetTransmitMode(I2C0_BASE_PTR, I2C_PDD_RX_DIRECTION); /* Switch to Rx mode */
            }
            DrvI2c0_OnMasterBlockSent(DeviceDataPrv->UserData); /* Invoke OnMasterBlockSent event */
          }
        }
      }
    }
    else {
      DeviceDataPrv->InpLenM--;        /* Decrease number of chars for the receive */
      if (DeviceDataPrv->InpLenM != 0x00U) { /* Is any char. for reception? */
        if (DeviceDataPrv->InpLenM == 0x01U) {
          I2C_PDD_EnableTransmitAcknowledge(I2C0_BASE_PTR, PDD_DISABLE); /* Transmit NACK */
        }
      } else {
        DeviceDataPrv->SerFlag &= (uint8_t)~(MASTER_IN_PROGRES); /* Clear flag "busy" */
        I2C_PDD_SetMasterMode(I2C0_BASE_PTR, I2C_PDD_SLAVE_MODE); /* If no, switch device to slave mode (stop signal sent) */
        I2C_PDD_EnableTransmitAcknowledge(I2C0_BASE_PTR, PDD_ENABLE); /* Transmit ACK */
      }
      *(DeviceDataPrv->InpPtrM)++ = I2C_PDD_ReadDataReg(I2C0_BASE_PTR); /* Receive character */
      if (DeviceDataPrv->InpLenM == 0x00U) { /* Is any char. for reception? */
        DrvI2c0_OnMasterBlockReceived(DeviceDataPrv->UserData); /* Invoke OnMasterBlockReceived event */
      }
    }
  } else {
    if ((Status & I2C_PDD_ARBIT_LOST) != 0x00U) { /* Arbitration lost? */
      DeviceDataPrv->OutLenM = 0x00U;  /* Any character is not for sent */
      DeviceDataPrv->InpLenM = 0x00U;  /* Any character is not for reception */
      DeviceDataPrv->SendStop = LDD_I2C_SEND_STOP; /* Set variable for sending stop condition (for master mode) */
      DeviceDataPrv->SerFlag &= (uint8_t)~(MASTER_IN_PROGRES); /* Any character is not for sent or reception*/
      I2C_PDD_SetTransmitMode(I2C0_BASE_PTR, I2C_PDD_RX_DIRECTION); /* Switch to Rx mode */
      ErrorMask |= LDD_I2C_ARBIT_LOST; /* Set the ArbitLost error mask */
    }
  }
  if (ErrorMask != 0x00U) {            /* Is any error mask set? */
    DrvI2c0_OnError(DeviceDataPrv->UserData); /* If yes then invoke user event */
  }
}

/*
** ===================================================================
**     Method      :  DrvI2c0_Init (component I2C_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the device data structure. 
** ===================================================================
*/
LDD_TDeviceData* DrvI2c0_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate HAL device structure */
  DrvI2c0_TDeviceData *DeviceDataPrv;
  /* {MQXLite RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;

  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */

  /* Allocate interrupt vector */
  /* {MQXLite RTOS Adapter} Save old and set new interrupt vector (function handler and ISR parameter) */
  /* Note: Exception handler for interrupt is not saved, because it is not modified */
  DeviceDataPrv->SavedISRSettings.isrData = _int_get_isr_data(LDD_ivIndex_INT_I2C0);
  DeviceDataPrv->SavedISRSettings.isrFunction = _int_install_isr(LDD_ivIndex_INT_I2C0, DrvI2c0_Interrupt, DeviceDataPrv);
  DeviceDataPrv->SerFlag = 0x00U;      /* Reset all flags */
  DeviceDataPrv->SendStop = LDD_I2C_SEND_STOP; /* Set variable for sending stop condition (for master mode) */
  DeviceDataPrv->InpLenM = 0x00U;      /* Set zero counter of data of reception */
  DeviceDataPrv->OutLenM = 0x00U;      /* Set zero counter of data of transmission */
  /* SIM_SCGC4: I2C0=1 */
  SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;                                                   
  /* I2C0_C1: IICEN=0,IICIE=0,MST=0,TX=0,TXAK=0,RSTA=0,WUEN=0,DMAEN=0 */
  I2C0_C1 = 0x00U;                     /* Clear control register */
  /* I2C0_FLT: SHEN=0,STOPF=1,STOPIE=0,FLT=0 */
  I2C0_FLT = I2C_FLT_STOPF_MASK;       /* Clear bus status interrupt flags */
  /* I2C0_S: TCF=0,IAAS=0,BUSY=0,ARBL=0,RAM=0,SRW=0,IICIF=1,RXAK=0 */
  I2C0_S = I2C_S_IICIF_MASK;           /* Clear interrupt flag */
  /* PORTE_PCR25: ISF=0,MUX=5 */
  PORTE_PCR25 = (uint32_t)((PORTE_PCR25 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x02)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x05)
                ));                                                  
  /* PORTE_PCR24: ISF=0,MUX=5 */
  PORTE_PCR24 = (uint32_t)((PORTE_PCR24 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x02)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x05)
                ));                                                  
  /* NVIC_IPR2: PRI_8=0x80 */
  NVIC_IPR2 = (uint32_t)((NVIC_IPR2 & (uint32_t)~(uint32_t)(
               NVIC_IP_PRI_8(0x7F)
              )) | (uint32_t)(
               NVIC_IP_PRI_8(0x80)
              ));                                                  
  /* NVIC_ISER: SETENA|=0x0100 */
  NVIC_ISER |= NVIC_ISER_SETENA(0x0100);                                                   
  /* I2C0_C2: GCAEN=0,ADEXT=0,HDRS=0,SBRC=0,RMEN=0,AD=0 */
  I2C0_C2 = 0x00U;                                                   
  /* I2C0_FLT: SHEN=0,STOPF=0,STOPIE=0,FLT=0 */
  I2C0_FLT = 0x00U;                    /* Set glitch filter register */
  /* I2C0_SMB: FACK=0,ALERTEN=0,SIICAEN=0,TCKSEL=0,SLTF=1,SHTF1=0,SHTF2=0,SHTF2IE=0 */
  I2C0_SMB = I2C_SMB_SLTF_MASK;                                                   
  /* I2C0_F: MULT=0,ICR=0x25 */
  I2C0_F = I2C_F_ICR(0x25);            /* Set prescaler bits */
  I2C_PDD_EnableDevice(I2C0_BASE_PTR, PDD_ENABLE); /* Enable device */
  I2C_PDD_EnableInterrupt(I2C0_BASE_PTR); /* Enable interrupt */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_DrvI2c0_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the data data structure */
}

/*
** ===================================================================
**     Method      :  DrvI2c0_Deinit (component I2C_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/
void DrvI2c0_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  /* I2C0_C1: IICEN=0,IICIE=0,MST=0,TX=0,TXAK=0,RSTA=0,WUEN=0,DMAEN=0 */
  I2C0_C1 = 0x00U;                     /* Reset I2C Control register */
  /* Restoring the interrupt vector */
  /* {MQXLite RTOS Adapter} Restore interrupt vector (function handler and ISR parameter) */
  /* Note: Exception handler for interrupt is not restored, because it was not modified */
  (void)_int_install_isr(LDD_ivIndex_INT_I2C0, ((DrvI2c0_TDeviceDataPtr)DeviceDataPtr)->SavedISRSettings.isrFunction, ((DrvI2c0_TDeviceDataPtr)DeviceDataPtr)->SavedISRSettings.isrData);
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_DrvI2c0_ID);
  /* Deallocation of the device structure */
  /* {MQXLite RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
  /* SIM_SCGC4: I2C0=0 */
  SIM_SCGC4 &= (uint32_t)~(uint32_t)(SIM_SCGC4_I2C0_MASK);                                                   
}

/*
** ===================================================================
**     Method      :  DrvI2c0_MasterSendBlock (component I2C_LDD)
**
**     Description :
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 0 to
**         the I2C bus and then writes the block of characters to the
**         bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that transmission was
**         successful. The state of transmission is detectable by means
**         of events (OnMasterSendComplete or OnError). Data to be sent
**         are not copied to an internal buffer and remains in the
**         original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockSent"can be used to detect the end of
**         the transmission. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to the block of data
**                           to send.
**         Size            - Size of the data block.
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The I2C device is now running
** ===================================================================
*/
LDD_TError DrvI2c0_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop)
{
  DrvI2c0_TDeviceData *DeviceDataPrv = (DrvI2c0_TDeviceData *)DeviceDataPtr;

  if (Size == 0x00U) {                 /* Test variable Size on zero */
    return ERR_OK;                     /* If zero then OK */
  }
  if (DeviceDataPrv->SendStop == LDD_I2C_SEND_STOP) {
    if ((I2C_PDD_GetBusStatus(I2C0_BASE_PTR) == I2C_PDD_BUS_BUSY) || /* Is the bus busy? */  \
       ((DeviceDataPrv->SerFlag & MASTER_IN_PROGRES) != 0x00U) || \
       (DeviceDataPrv->OutLenM != 0x00U))  {
      return ERR_BUSY;                 /* If yes then error */
    }
  } else {
    if (((DeviceDataPrv->SerFlag & MASTER_IN_PROGRES) != 0x00U) || /* Is the bus busy? */  \
      (DeviceDataPrv->OutLenM != 0x00U))  {
      return ERR_BUSY;                 /* If yes then error */
    }
  }
  /* {MQXLite RTOS Adapter} Critical section begin (RTOS function call is defined by MQXLite RTOS Adapter property) */
  _int_disable();
  DeviceDataPrv->SerFlag |= MASTER_IN_PROGRES; /* Set flag "busy" */
  DeviceDataPrv->OutPtrM = (uint8_t *)BufferPtr; /* Save pointer to data for transmitting */
  DeviceDataPrv->OutLenM = Size;       /* Set the counter of output bufer's content */
  DeviceDataPrv->SendStop = SendStop;  /* Set generating stop condition */
  I2C_PDD_SetTransmitMode(I2C0_BASE_PTR, I2C_PDD_TX_DIRECTION); /* Set TX mode */
  if (I2C_PDD_GetMasterMode(I2C0_BASE_PTR) == I2C_PDD_MASTER_MODE) { /* Is device in master mode? */
    I2C_PDD_RepeatStart(I2C0_BASE_PTR); /* If yes then repeat start cycle generated */
  } else {
    I2C_PDD_SetMasterMode(I2C0_BASE_PTR, I2C_PDD_MASTER_MODE); /* If no then start signal generated */
  }
  I2C_PDD_WriteDataReg(I2C0_BASE_PTR, 0x3AU); /* Send slave address */
  /* {MQXLite RTOS Adapter} Critical section ends (RTOS function call is defined by MQXLite RTOS Adapter property) */
  _int_enable();
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  DrvI2c0_MasterReceiveBlock (component I2C_LDD)
**
**     Description :
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 1 to
**         the I2C bus and then receives the block of characters from
**         the bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that reception was
**         successful. The state of reception is detectable by means of
**         events (OnMasterSendComplete  or OnError). Data to be
**         received are not copied to an internal buffer and remains in
**         the original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockReceived"can be used to detect the end
**         of the reception. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to a buffer where
**                           received characters will be stored.
**         Size            - The size of the block.
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The master device is busy
**                           ERR_NOTAVAIL - It is not possible to
**                           receive data if general call address is set.
**                           ERR_PARAM_MODE -  Stop condition isn't
**                           possible generated on end transmission.
** ===================================================================
*/
LDD_TError DrvI2c0_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop)
{
  DrvI2c0_TDeviceData *DeviceDataPrv = (DrvI2c0_TDeviceData *)DeviceDataPtr;

  if (Size == 0x00U) {                 /* Test variable Size on zero */
    return ERR_OK;                     /* If zero then OK */
  }
  if (SendStop == LDD_I2C_NO_SEND_STOP) { /* Test variable SendStop on supported value */
    return ERR_PARAM_MODE;             /* If not supported value then error */
  }
  if (DeviceDataPrv->SendStop == LDD_I2C_SEND_STOP) {
    if ((I2C_PDD_GetBusStatus(I2C0_BASE_PTR) == I2C_PDD_BUS_BUSY) || /* Is the bus busy? */  \
      ((DeviceDataPrv->SerFlag & MASTER_IN_PROGRES) != 0x00U) || \
      (DeviceDataPrv->InpLenM != 0x00U)) {
      return ERR_BUSY;                 /* If yes then error */
    }
  } else {
    if(((DeviceDataPrv->SerFlag & MASTER_IN_PROGRES) != 0x00U) || /* Is the bus busy? */  \
      (DeviceDataPrv->InpLenM != 0x00U)) {
      return ERR_BUSY;               /* If yes then error */
    }
  }
  /* {MQXLite RTOS Adapter} Critical section begin (RTOS function call is defined by MQXLite RTOS Adapter property) */
  _int_disable();
  DeviceDataPrv->SerFlag |= MASTER_IN_PROGRES; /* Set flag "busy" */
  DeviceDataPrv->InpPtrM = (uint8_t *)BufferPtr; /* Save pointer to data for reception */
  DeviceDataPrv->InpLenM = Size;       /* Set the counter of input bufer's content */
  DeviceDataPrv->SendStop = SendStop;  /* Set generating stop condition */
  I2C_PDD_SetTransmitMode(I2C0_BASE_PTR, I2C_PDD_TX_DIRECTION); /* Set TX mode */
  if (I2C_PDD_GetMasterMode(I2C0_BASE_PTR) == I2C_PDD_MASTER_MODE) { /* Is device in master mode? */
    I2C_PDD_RepeatStart(I2C0_BASE_PTR); /* If yes then repeat start cycle generated */
  } else {
    I2C_PDD_SetMasterMode(I2C0_BASE_PTR, I2C_PDD_MASTER_MODE); /* If no then start signal generated */
  }
  I2C_PDD_WriteDataReg(I2C0_BASE_PTR, 0x3BU); /* Send slave address */
  /* {MQXLite RTOS Adapter} Critical section ends (RTOS function call is defined by MQXLite RTOS Adapter property) */
  _int_enable();
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  DrvI2c0_CheckBus (component I2C_LDD)
**
**     Description :
**         This method returns the status of the bus. If the START
**         condition has been detected, the method returns LDD_I2C_BUSY.
**         If the STOP condition has been detected, the method returns
**         LDD_I2C_IDLE.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BusStatePtr     - Pointer to a variable,
**                           where value of status is stored.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
** ===================================================================
*/
LDD_TError DrvI2c0_CheckBus(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TBusState *BusStatePtr)
{
  DrvI2c0_TDeviceData *DeviceDataPrv = (DrvI2c0_TDeviceData *)DeviceDataPtr;

  (void)DeviceDataPrv;                 /* Suppress unused variable warning if needed */
  *BusStatePtr = (LDD_I2C_TBusState)((I2C_PDD_GetBusStatus(I2C0_BASE_PTR) == I2C_PDD_BUS_BUSY)?LDD_I2C_BUSY:LDD_I2C_IDLE); /* Return value of Busy bit in status register */
  return ERR_OK;
}

/* END DrvI2c0. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
