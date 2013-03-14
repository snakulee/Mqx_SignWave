/** ###################################################################
**     Filename    : mqx_tasks.c
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
/* MODULE mqx_tasks */

#include "Cpu.h"
#include "Events.h"
#include "mqx_tasks.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

#include <stdlib.h>
#include <string.h>
#include <math.h>

/* MMA8451Q IOMap */
/* External 3-axis accelerometer data register addresses */
#define OUT_X_MSB 0x01
#define OUT_X_LSB 0x02
#define OUT_Y_MSB 0x03
#define OUT_Y_LSB 0x04
#define OUT_Z_MSB 0x05
#define OUT_Z_LSB 0x06
/* External 3-axis accelerometer control register addresses */
#define CTRL_REG_1 0x2A
/* External 3-axis accelerometer control register bit masks */
#define ACTIVE_BIT_MASK 0x01
#define F_READ_BIT_MASK 0x02
#define ACC_REG_SIZE 1U
#define READ_COUNT 5U


#define ADS1015_CONV_REG		0x00U
#define ADS1015_CONV_REG_LEN	0x02U


#define ADS1015_CTRL_REG		0x01U
#define ADS1015_THRE_LO_REG		0x02U
#define ADS1015_THRE_HI_REG		0x03U
#define ADS1015_CTRL_REG_LEN	0x02U

#define PI 3.14159265F
#define DAC_2V	2482UL
#define DAC_3V	3724UL
#define DAC_1V	1241UL


LDD_TDeviceData *I2c0_DeviceData = NULL;
TDataState I2c0_DataState;

LDD_TDeviceData *I2c1_DeviceData = NULL;
TDataState I2c1_DataState;


LDD_TDeviceData *Dac0_DeviceData = NULL;
TDacUsrData Dac0_Data;



LDD_TDeviceData *PWMTimerRG_DeviceData = NULL;
LDD_TDeviceData *PWMTimerB_DeviceData = NULL;


bool I2c0_ReadAccRegs(LDD_TDeviceData *I2CPtr, TDataState *I2c0_DataState, uint8_t Address, uint8_t RegCount, uint8_t *Buffer)
{
	LDD_I2C_TBusState BusState;
	I2c0_DataState->Sent = FALSE;
	uint32_t u32_retry = 0UL;
	
	DrvI2c0_MasterSendBlock(I2CPtr, &Address, sizeof(Address), LDD_I2C_NO_SEND_STOP);

	while ((!I2c0_DataState->Sent) && (u32_retry < 100000))
	{
		u32_retry++;
	}

	if (!I2c0_DataState->Sent)
	{
		return FALSE;
	}
	
	I2c0_DataState->Received = FALSE;
	DrvI2c0_MasterReceiveBlock(I2CPtr, Buffer, RegCount, LDD_I2C_SEND_STOP);

	u32_retry = 0UL;
	while ((!I2c0_DataState->Received) && (u32_retry < 100000))
	{
		u32_retry++;
	}
	
	do
	{
		DrvI2c0_CheckBus(I2CPtr, &BusState);
	}while (BusState != LDD_I2C_IDLE);

	if (!I2c0_DataState->Received)
	{
		return FALSE;
	}

	return TRUE;
}


bool I2c0_WriteAccRegs(LDD_TDeviceData *I2CPtr, TDataState *I2c0_DataState, uint8_t Address, uint8_t RegCount, uint8_t *Data)
{
	LDD_I2C_TBusState BusState;
	const uint8_t MAX_REG_COUNT = 16;
	uint8_t SendBuffer[MAX_REG_COUNT];
	uint32_t u32_retry = 0UL;
	
	SendBuffer[0] = Address;
	
	memcpy(&SendBuffer[1], Data, RegCount);
	I2c0_DataState->Sent = FALSE;
	
	DrvI2c0_MasterSendBlock(I2CPtr, &SendBuffer, RegCount + 1, LDD_I2C_SEND_STOP);

	while ((!I2c0_DataState->Sent)&& (u32_retry < 100000))
	{
		u32_retry++;
	}

	do
	{
		DrvI2c0_CheckBus(I2CPtr, &BusState);
	}while(BusState != LDD_I2C_IDLE); 

	if (!I2c0_DataState->Sent)
	{
		return FALSE;
	}
	
	return TRUE;
}

bool I2c1_ReadAccRegs(LDD_TDeviceData *I2CPtr, TDataState *I2c1_DataState, uint8_t Address, uint8_t RegCount, uint8_t *Buffer)
{
	LDD_I2C_TBusState BusState;
	I2c1_DataState->Sent = FALSE;
	uint32_t u32_retry = 0UL;
	
	DrvI2c1_MasterSendBlock(I2CPtr, &Address, sizeof(Address), LDD_I2C_NO_SEND_STOP);

	while ((!I2c1_DataState->Sent) && (u32_retry < 100000))
	{
		u32_retry++;
	}

	if (!I2c1_DataState->Sent)
	{
		return FALSE;
	}
	
	I2c1_DataState->Received = FALSE;
	DrvI2c1_MasterReceiveBlock(I2CPtr, Buffer, RegCount, LDD_I2C_SEND_STOP);

	u32_retry = 0UL;
	
	while ((!I2c1_DataState->Received) && (u32_retry < 100000))
	{
		u32_retry++;
	}
	
	do
	{
		DrvI2c1_CheckBus(I2CPtr, &BusState);
	}while (BusState != LDD_I2C_IDLE);

	if (!I2c1_DataState->Received)
	{
		return FALSE;
	}

	return TRUE;
}


bool I2c1_WriteAccRegs(LDD_TDeviceData *I2CPtr, TDataState *I2c1_DataState, uint8_t Address, uint8_t RegCount, uint8_t *Data)
{
	LDD_I2C_TBusState BusState;
	const uint8_t MAX_REG_COUNT = 16;
	uint8_t SendBuffer[MAX_REG_COUNT];
	uint32_t u32_retry = 0UL;

	
	SendBuffer[0] = Address;
	memcpy(&SendBuffer[1], Data, RegCount);
	I2c1_DataState->Sent = FALSE;
	
	DrvI2c1_MasterSendBlock(I2CPtr, &SendBuffer, RegCount + 1, LDD_I2C_SEND_STOP);

	while ((!I2c1_DataState->Sent)&& (u32_retry < 100000))
	{
		u32_retry++;
	}

	do
	{
		DrvI2c1_CheckBus(I2CPtr, &BusState);
	}while(BusState != LDD_I2C_IDLE); 

	if (!I2c1_DataState->Sent)
	{
		return FALSE;
	}
	
	return TRUE;
}



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
void Task_Default(uint32_t task_init_data)
{
  int counter = 0;

	byte Data;
	LDD_TError Error = 0;
	signed char Color[3] = {0,127,127}; // initialize to turqoise

	pointer td_ptr;
	_task_id tid;

	#if 0
	uint32_t u32_size, u32_usage;
	_mqx_uint u_ret;
	#endif
	
	printf("Project description:\n");
	printf("I2C example of communication with external accelerometer.\n");
	printf("PWM is used for dimming the RGB LED in dependence on tilt of the board.\n");
	printf("\n");


	tid = _task_get_id();
	printf("Default Task ID = %ld\n", tid);
	
	// Initialize Accelerometer
	I2c0_DeviceData = DrvI2c0_Init(&I2c0_DataState);
	
	Error = !I2c0_ReadAccRegs(I2c0_DeviceData, &I2c0_DataState, CTRL_REG_1, ACC_REG_SIZE, &Data);
	if (!Error)
	{
		Data = (ACTIVE_BIT_MASK | F_READ_BIT_MASK); /* Set active mode bit and fast read mode bit */
		Error = !I2c0_WriteAccRegs(I2c0_DeviceData, &I2c0_DataState, CTRL_REG_1, ACC_REG_SIZE, &Data);
	}

	if (!Error)
	{
		Data = 0;
		Error = !I2c0_ReadAccRegs(I2c0_DeviceData, &I2c0_DataState, CTRL_REG_1, ACC_REG_SIZE, &Data);

		if (!Error)
		{
			if (Data != (ACTIVE_BIT_MASK | F_READ_BIT_MASK))
			{
				Error = TRUE;
			}
		}
	}
	
	/* Initialization passed? */
	if (!Error)
	{
		printf("Init Inertial sensor (I2C addr = 0x1D) PASSED.\n");
	}
	else
	{
		printf("FAILED.\n");
	}

	if (!Error)
	{
		printf("Tilt your Freedom Board to change the RGB LED colors.\n");
	}

	
	PWMTimerRG_DeviceData = DrvPwmTimerRG_Init(NULL);
	PWMTimerB_DeviceData = DrvPwmTimerB_Init(NULL);


	#if 1
	
	#else
	printf("Task_Dac ID");
	_time_delay_ticks(10);
	
	tid = _task_get_id_from_name("task_dac");
	if(tid != MQX_NULL_TASK_ID)
	{
		printf(" = %ld.\n", tid);

		_time_delay_ticks(10);
		
		td_ptr = _task_get_td(tid);
		if(td_ptr != NULL)
		{
			printf("Start DAC task ID=%ld.\n", tid);

			_time_delay_ticks(10);
			
			_task_ready((pointer)td_ptr);
		}
		else
		{
			printf("!! Get task TD Fail.\n");
		}
	}
	else
	{
		printf("!! Get task ID Fail.\n");
	}
	#endif

	#if 0
	u_ret = _klog_get_task_stack_usage(
				_task_get_id(), 
				&u32_size, 
				&u32_usage);
	if(u_ret == MQX_OK)
	{
		printf("Default task stack size=%ld, usage=%ld\n", u32_size, u32_usage);
	}
	else
	{
		printf("GET Default task stack size FAIL\n");
	}
	#endif

	while(1)
	{
		counter++;

    	/* Write your code here ... */
		Error = !I2c0_ReadAccRegs(I2c0_DeviceData, &I2c0_DataState, OUT_X_MSB, 3 * ACC_REG_SIZE, (uint8_t*)Color); // Read x,y,z acceleration data.
		if (!Error)
		{
			DrvPwmTimerRG_Enable(PWMTimerRG_DeviceData);
			DrvPwmTimerB_Enable(PWMTimerB_DeviceData);
			DrvPwmTimerRG_SetOffsetTicks(PWMTimerRG_DeviceData, 0,1000*(1<<(abs(Color[0]/10)))); //x axis - red LED 
			DrvPwmTimerRG_SetOffsetTicks(PWMTimerRG_DeviceData, 1, 1000*(1<<(abs(Color[1]/10)))); // y axis - green LED 
			DrvPwmTimerB_SetOffsetTicks(PWMTimerB_DeviceData, 0, 1000*(1<<(abs(Color[2]/10)))); // z axis - blue LED
		}
		_time_delay_ticks(100);
	}
}


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
void Task_Dac(uint32_t task_init_data)
{	
	uint8_t i2c1_buffer[4] = {0};
	LDD_TError Error = 0;

	#if 0	/* draw sign wave */
	float f_sin = 0.0, f_val;
	uint32 u32_tmp, u32_delay=86UL;
	uint32 u32_sin[91];
	uint32_t u32_val;
	uint8 u8_i, u8_j;
	#endif
	

	int16_t s16_AdcData = 0;


	// TI ADS1015 ADC chip
	
	I2c1_DeviceData = DrvI2c1_Init(&I2c1_DataState);

	Dac0_DeviceData = DrvDac2V_Init(&Dac0_Data);


	#if 1

	i2c1_buffer[0] = ADS1015_CTRL_REG;
	Error = !I2c1_ReadAccRegs(I2c1_DeviceData, &I2c1_DataState, ADS1015_CTRL_REG, ADS1015_CTRL_REG_LEN, i2c1_buffer);
	if (!Error)
	{
		printf("READ TI ADS1015 control register PASS, MSB=0x%02X, LSB=0x%02X.\n", i2c1_buffer[0], i2c1_buffer[1]);
	}
	else
	{
		printf("READ TI ADS1015 control register FAILED.\n");
	}

	i2c1_buffer[0] &= ~0x01;

	Error = !I2c0_WriteAccRegs(I2c1_DeviceData, &I2c1_DataState, ADS1015_CTRL_REG, ADS1015_CTRL_REG_LEN, i2c1_buffer);
	if (!Error)
	{
		printf("WRITE TI ADS1015 control register PASS, MSB=0x%02X, LSB=0x%02X.\n", i2c1_buffer[0], i2c1_buffer[1]);
	}
	else
	{
		printf("WRITE TI ADS1015 control register FAILED.\n");
	}

	#endif


	#if 0		/* draw sign wave */
	for(u8_i=0U; u8_i<90; u8_i++)
	{
		u32_sin[u8_i] = 4096UL*(sin((PI*u8_i)/180));
	}
	u32_sin[90] = 4095UL;
	u8_i = 0U;
	#endif

	DrvDac2V_SetValue(Dac0_DeviceData, DAC_2V);	// output 2 V

  	while(1)
	{

		/* Write your code here ... */

		Error = !I2c1_ReadAccRegs(I2c1_DeviceData, &I2c1_DataState, ADS1015_CONV_REG, ADS1015_CONV_REG_LEN, i2c1_buffer);
		if (!Error)
		{
			s16_AdcData = (int16_t*)i2c1_buffer;
			s16_AdcData >>= 4;
			printf("READ TI ADS1015 convert register PASS, MSB=0x%02X, LSB=0x%02X, DAC=%d.\n", i2c1_buffer[0], i2c1_buffer[1], s16_AdcData);
		}
		else
		{
			printf("READ TI ADS1015 convert register FAILED.\n");
		}

		#if 0		/* draw sign wave */
		for(u8_j=0; u8_j<180; u8_j++)
		{
			u32_tmp = 0UL;
			u8_i = abs(90U-u8_j);
			DrvDac2V_SetValue(Dac0_DeviceData, u32_sin[u8_i]);

			while(u32_tmp < u32_delay)
			{
				u32_tmp++;
			}
			
		}
		#endif
	}
}

/* END mqx_tasks */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
