/*==============================================================================================
								 	 PROJECT BW Ver.1.0
					    BW DEVANTECH CMPS-11 MAGNETIC COMPASS LIBRARY
==============================================================================================*/


#include "bw_cmps11.h"

void BW_CMPS11_Init (void)
{
	void BW_CMPS11_I2C_Init ();
}

/*
 * ACCESSING CMPS-11 THROUGH THE I2C/TWI COMMUNICATION PROTOCOL
 */

/* func      : 	void BW_CMPS11_I2C_Init (void)
 * brief     : 	CMPS-11 I2C BUS Initialization
 * param     :	N/A
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Friday, January 29th 2016)
 * Revised By: N/A
 *
 */
void BW_CMPS11_I2C_Init (void)
{
    //GY-85 I2C INIT
	/*  GPIO Setup  */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /*  I2C Setup  */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_ClockSpeed = 400000; //400kHz
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_OwnAddress1 = 0x00;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

    I2C_Cmd(I2C2, ENABLE);
    I2C_Init(I2C2, &I2C_InitStructure);

    /* Connect PXx to I2C_SCL*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_I2C2);

    /* Connect PXx to I2C_SDA*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_I2C2);
}


/* func      : int16_t I2C2_TimeOut(int16_t VALUE)
 * brief     : STOP, RESET, and RE-INIT the I2C2 Communication Interface
 * param     :	int16_t VALUE : TIMEOUT CODE
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C2_ReadMultiByte SUCCESS!
 * 				RetVal < 0 -> I2C2_ReadMultiByte ERROR!
 * Ver       : 1
 * written By: Ryan (Friday, January 29th 2016)
 * Revised By: N/A
 *
 */
int16_t I2C2_TimeOut(int16_t VALUE)
{
	int16_t RetVal= VALUE;

//	Stop and reset
	I2C_GenerateSTOP(I2C2,ENABLE);
	I2C_SoftwareResetCmd(I2C2,ENABLE);
	I2C_SoftwareResetCmd(I2C1, DISABLE);

	// I2C De-Init
	I2C_DeInit(I2C2);

//	I2C Re-Init
	BW_CMPS11_I2C_Init();

    return(RetVal);
}
/*
 * I2C READ OLD ALGORITHM WITH DEVICE ADDRESS FIX
 */
void RyanRead_I2C2(int Address, int Register)
{
	if((MPU_ACTIVE_MODE&&1)==1)
	{
		while (I2C_GetFlagStatus(I2C2, I2C_FLAG_BUSY))
		{
			;
		}

		I2C_GenerateSTART(I2C2, ENABLE);
		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
		{
			;
		}

		I2C_Send7bitAddress(I2C2, Address,I2C_Direction_Transmitter);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		{
			;
		}

		I2C_Cmd(I2C2, ENABLE);

		I2C_SendData(I2C2,Register);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		{
			;
		}

		I2C_GenerateSTART(I2C2, ENABLE);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_MODE_SELECT))
		{
			;
		}

		I2C_Send7bitAddress(I2C2,Address,I2C_Direction_Receiver);
		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
		{
			;
		}

		I2C_AcknowledgeConfig(I2C2, DISABLE);
		I2C_GenerateSTOP(I2C2, ENABLE);

		while (!I2C_CheckEvent(I2C2, I2C_EVENT_MASTER_BYTE_RECEIVED))
		{
			;
		}

		DATA=I2C_ReceiveData(I2C2);
		I2C_AcknowledgeConfig(I2C2, ENABLE);
	}
}

/* func      : int16_t I2C2_ReadByte(uint8_t ADDRESS, uint8_t REGISTER)
 * brief     : Read single byte variables from I2C Bus
 * param     :
 * 				uint8_t ADDRESS : I2C Slave Device Address
 * 				uint8_t REGISTER: Register Address
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C2_ReadByte SUCCESS!
 * 				RetVal < 0 -> I2C2_ReadByte ERROR!
 * 				Data stored int I2C2_DATA[0]
 * Ver       : 1
 * written By: Ryan (Saturday, January 30th 2016)
 * Revised By: N/A
 *
 */
int16_t I2C2_ReadByte(uint8_t ADDRESS, uint8_t REGISTER)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C2_TIMEOUT;
//	  uint8_t Value,counter;

	  //Start Sequences
	  I2C_GenerateSTART(I2C2, ENABLE);

	  TimeOut= I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2,I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-1));
	  }

	  // ACK disable
	  I2C_AcknowledgeConfig(I2C2, DISABLE);

	  // Slave Address Send (write)
	  I2C_Send7bitAddress(I2C2, ADDRESS, I2C_Direction_Transmitter);

	  TimeOut= I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C2->SR2;

	  TimeOut=I2C2_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-3));
	  }

	  // SEND REGISTER ADDRESS
	  I2C_SendData(I2C2, REGISTER);

	  TimeOut=I2C2_TIMEOUT;
	  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-4));
	  }

	  // Start Sequence
	  I2C_GenerateSTART(I2C2, ENABLE);

	  TimeOut=I2C2_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-5));
	  }

	  // Slave Address Send (read
	  I2C_Send7bitAddress(I2C2, ADDRESS, I2C_Direction_Receiver);

	  TimeOut=I2C2_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-6));
	  }

	  // Clear ADDR Flag
	  I2C2->SR2;

	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_RXNE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-7));
	  }

	  // Stop Sequences
	  I2C_GenerateSTOP(I2C2, ENABLE);

	  // Read data
	  I2C2_DATA[0]=I2C_ReceiveData(I2C2);

	  // ACK enable
	  I2C_AcknowledgeConfig(I2C2, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return(RetVal);
}


//int16_t UB_I2C1_ReadMultiByte(uint8_t slave_adr, uint8_t adr, uint8_t cnt);
/* func      : int16_t I2C2_ReadMultiByte_I2C2(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE)
 * brief     : Read multibyte variables from I2C Bus
 * param     :
 * 				uint8_t ADDRESS : I2C Slave Device Address
 * 				uint8_t REGISTER: Start Register Address
 * 				uint8_t BYTE	: Number of Requested Byte
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C2_ReadMultiByte SUCCESS!
 * 				RetVal < 0 -> I2C2_ReadMultiByte ERROR!
 * 				Data stored int I2C2_DATA[0]-I2C2_DATA[9]
 * Ver       : 1
 * written By: Ryan (Friday, January 29th 2016)
 * Revised By: N/A
 *
 */
int16_t I2C2_ReadMultiByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C2_TIMEOUT;
	  uint8_t Value,counter;

	  if(BYTE==0) return (-8);
	  if(BYTE>I2C2_MULTIBYTE_MAX) return(-9);

//	  Start Sequences
	  I2C_GenerateSTART(I2C2, ENABLE);

	  TimeOut= I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2,I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-1));
	  }

	  if(BYTE==1)
	  {
//		  ACK Disable
		  I2C_AcknowledgeConfig(I2C2, DISABLE);
	  }

	  else
	  {
		// ACK enable
		I2C_AcknowledgeConfig(I2C2, ENABLE);
	  }

	  // Slave-Adress send (write)
	  I2C_Send7bitAddress(I2C2, ADDRESS, I2C_Direction_Transmitter);

	  TimeOut=I2C2_TIMEOUT;

	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C2->SR2;

	  TimeOut=I2C2_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-3));
	  }

	  // Send REGISTER ADDRESS
	  I2C_SendData(I2C2, REGISTER);

	  TimeOut=I2C2_TIMEOUT;
	  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-4));
	  }

	  // Start Sequence
	  I2C_GenerateSTART(I2C2, ENABLE);

	  TimeOut=I2C2_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-5));
	  }

	  // Slave Address Send (read
	  I2C_Send7bitAddress(I2C2, ADDRESS, I2C_Direction_Receiver);

	  TimeOut=I2C2_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-6));
	  }

	  // Clear ADDR Flag
	  I2C2->SR2;

//	  Read ALL DATA
	  for(counter=0;counter<BYTE;counter++)
	  {
		  if( (counter+1)>=BYTE)
		  {
			  // Disable ACK
			  I2C_AcknowledgeConfig(I2C2, DISABLE);

			  // Stop Sequences
			  I2C_GenerateSTOP(I2C2, ENABLE);
		  }

		  TimeOut=I2C2_TIMEOUT;

		  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_RXNE))
		  {
			  if(TimeOut!=0) TimeOut--;
			  else return (I2C2_TimeOut(-7));
		  }

		  // Read data
		  Value=I2C_ReceiveData(I2C2);

		  // Store received data in array
		  I2C2_DATA[counter]=Value;
	  }

	  // ACK enable
	  I2C_AcknowledgeConfig(I2C2, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return(RetVal);
}

/* func      : int16_t I2C2_WriteByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t VALUE)
 * brief     : Write single byte variables through the I2C2 Communication Protocol
 * param     :
 * 				uint8_t ADDRESS : I2C Slave Device Address
 * 				uint8_t REGISTER: Start Register Address
 * 				uint8_t VALUE	: Value that should be sent to the I2C Slave Devices
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C2_WriteByte SUCCESS!
 * 				RetVal < 0 -> I2C2_WriteByte ERROR!
 *
 * Ver       : 1
 * written By: Ryan (Saturday, January 30th 2016)
 * Revised By: N/A
 *
 */
int16_t I2C2_WriteByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t VALUE)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C2_TIMEOUT;

	  //Start Sequences
	  I2C_GenerateSTART(I2C2, ENABLE);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-1));
	  }

	  // Slave Address Send (write)
	  I2C_Send7bitAddress(I2C2,ADDRESS,I2C_Direction_Transmitter);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C2->SR2;

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-3));
	  }

	  // Address Send
	  I2C_SendData(I2C2, ADDRESS);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-4));
	  }

	  //Send Data
	  I2C_SendData(I2C2, VALUE);

	  TimeOut=I2C2_TIMEOUT;

	  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-5));
	  }

	  // Stop Sequences
	  I2C_GenerateSTOP(I2C2, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return (RetVal);
}



/* func      : int16_t I2C2_WriteMultiByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE)
 * brief     : Write multibyte variables to the I2C Bus
 * param     :
 * 				Hold the value you want to send on the buffer I2C2_DATA[0] ~ I2C2_DATA[9]
 * 				uint8_t ADDRESS : I2C Slave Device Address
 * 				uint8_t REGISTER: Start Register Address
 * 				uint8_t BYTE	: Number of Requested Byte
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C2_WriteMultiByte SUCCESS!
 * 				RetVal < 0 -> I2C2_WriteMultiByte ERROR!
 *
 * Ver       : 1
 * written By: Ryan (Friday, January 29th 2016)
 * Revised By: N/A
 *
 */
int16_t I2C2_WriteMultiByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C2_TIMEOUT;
	  unsigned int Value=0,counter=0;

	  if(counter==0) return(-6);
	  if(counter>I2C2_MULTIBYTE_MAX) return(-7);

//	  Start Sequences
	  I2C_GenerateSTART(I2C2, ENABLE);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-1));
	  }

	  // Slave Address Send (write)
	  I2C_Send7bitAddress(I2C2,ADDRESS,I2C_Direction_Transmitter);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C2->SR2;

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-3));
	  }

	  // Address Send
	  I2C_SendData(I2C2, ADDRESS);

	  TimeOut=I2C2_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C2_TimeOut(-4));
	  }

	  // Send all data
	  for(counter=0;counter<BYTE;counter++)
	  {
		  //Read data from array
		  Value=I2C2_DATA[counter];

		  //Send Data
		  I2C_SendData(I2C2, Value);

		  TimeOut=I2C2_TIMEOUT;

		  while ((!I2C_GetFlagStatus(I2C2, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C2, I2C_FLAG_BTF)))
		  {
			  if(TimeOut!=0) TimeOut--;
			  else return (I2C2_TimeOut(-5));
		  }
	  }

	  // Stop Sequences
	  I2C_GenerateSTOP(I2C2, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return (RetVal);
}

/* func      : void CMPS11_I2C_Calibration (void)
 * brief     : CMPS-11 Magnetometer, Accelerometer, and Gyroscope Calibration using I2C Communication Protocol
 * param     :	N/A
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Saturday, January 30th 2016)
 * Revised By: N/A
 *
 */
void CMPS11_I2C_Calibration (void)
{
	int BW_BUTTON=0;

	I2C2_WriteByte(CMPS11_ADDRESS, CMPS11_CMD_REGISTER, CALIBRATE_BYTE_1);
	delay_ms(200);
	I2C2_WriteByte(CMPS11_ADDRESS, CMPS11_CMD_REGISTER, CALIBRATE_BYTE_2);
	delay_ms(200);
	I2C2_WriteByte(CMPS11_ADDRESS, CMPS11_CMD_REGISTER, CALIBRATE_BYTE_3_FULL);
	delay_ms(200);

	BW_Buzz(2);

	while(BW_BUTTON==0)
	{
		BW_BUTTON=BW_BUTTON_INPUT;
		mov_rot_right(MED,FAR);
	}

	I2C2_WriteByte(CMPS11_ADDRESS, CMPS11_CMD_REGISTER, CALIBRATE_EXIT);

	BW_Buzz(4);
}



/* func      : void GetCMPS11_Pitch(int KF_STATUS)
 * brief     : Read CMPS11 Pitch Angle with or without Kalman Filter
 * param     : int KF_STATUS
 * 			   KF_ACTIVE   -> Read Pitch Angle with Kalman Filter
 * 			   KF_INACTIVE -> Read Pitch Angle without Kalman Filter
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 1st 2016)
 * Revised By: N/A
 * Programmer's Note: Compass Data stored in:
 * 						BW_CMPS11.PitchKF   -> Pitch Angle Kalman Filtered
 * 						BW_CMPS11.PitchNoKF -> Pitch Angle without Kalman Filter
 */
void GetCMPS11_Pitch(int KF_STATUS)
{
	int16_t ERROR_CODE=0;

	switch (KF_STATUS)
	{
		// KF ENABLED
		case 0:
				{
					ERROR_CODE= I2C2_ReadByte(CMPS11_ADDRESS, CMPS11_PITCH_KF);
					BW_CMPS11.PitchKF=I2C2_DATA[0];
					Sendto_PC(USART1,"Pitch Angle Kalman Filtered: %d \t\t",BW_CMPS11.PitchKF);

				}break;
		// KF DISABLED
		case 1:
				{
					ERROR_CODE= I2C2_ReadByte(CMPS11_ADDRESS, CMPS11_PITCH_NO_KF);
					BW_CMPS11.PitchNoKF=I2C2_DATA[0];
					Sendto_PC(USART1,"Pitch Angle without Kalman Filter: %d \t\t",BW_CMPS11.PitchNoKF);
				}break;
	}

	Sendto_PC(USART1,"ERROR_CODE: %d \r",ERROR_CODE);
}

/* func      : void GetCMPS11_Roll(int KF_STATUS)
 * brief     : Read CMPS11 Roll Angle with or without Kalman Filter
 * param     : int KF_STATUS
 * 			   KF_ACTIVE   -> Read Roll Angle with Kalman Filter
 * 			   KF_INACTIVE -> Read Roll Angle without Kalman Filter
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 1st 2016)
 * Revised By: N/A
 * Programmer's Note: Compass Data stored in:
 * 						BW_CMPS11.RollKF   -> Roll Angle Kalman Filtered
 * 						BW_CMPS11.RollNoKF -> Roll Angle without Kalman Filter
 */
void GetCMPS11_Roll(int KF_STATUS)
{
	int16_t ERROR_CODE=0;

	switch (KF_STATUS)
	{
		// KF ENABLED
		case 0:
				{
					ERROR_CODE= I2C2_ReadByte(CMPS11_ADDRESS, CMPS11_ROLL_KF);
					BW_CMPS11.RollKF=I2C2_DATA[0];
					Sendto_PC(USART1,"Roll Angle Kalman Filtered: %d \t\t",BW_CMPS11.RollKF);

				}break;

		// KF DISABLED
		case 1:
				{
					ERROR_CODE= I2C2_ReadByte(CMPS11_ADDRESS, CMPS11_ROLL_NO_KF);
					BW_CMPS11.RollNoKF=I2C2_DATA[0];
					Sendto_PC(USART1,"Roll Angle without Kalman Filter: %d \t\t",BW_CMPS11.RollNoKF);
				}break;
	}

	Sendto_PC(USART1,"ERROR_CODE: %d \r",ERROR_CODE);
}

/* func      : void GetCMPS11_Angle8Bit(void)
 * brief     : Read CMPS11 Compass Bearing in 8 Bit Resolution
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Saturday, January 30th 2016)
 * Revised By: Ryan (Monday, February 1st 2016)
 * Programmer's Note: Compass Data stored in BW_CMPS11.Compass8Bit
 */
void GetCMPS11_Angle8Bit(void)
{
	int16_t ERROR_CODE=0;
	ERROR_CODE= I2C2_ReadByte(CMPS11_ADDRESS, CMPS11_BEARING_8BIT);

	BW_CMPS11.Compass8Bit=I2C2_DATA[0];
	BW_CMPS11.Compass8Bit*=1.411;
	Sendto_PC(USART1,"ANGLE_8BIT: %d \t\t",BW_CMPS11.Compass8Bit);

//	BW_CMPS11.Compass8Bit= BW_CMPS11.Compass8Bit/255;
//	BW_CMPS11.Compass8Bit= BW_CMPS11.Compass8Bit*360;

	Sendto_PC(USART1,"Converted Angle: %d \t\t",BW_CMPS11.Compass8Bit);
	Sendto_PC(USART1,"ERROR_CODE: %d \r",ERROR_CODE);

//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"ANGLE: %d",BW_CMPS11.Compass8Bit);lcd_putstr(lcd);
//	delay_ms(100);

	if(ERROR_CODE!=0)
	{
		ERROR_CODE= I2C2_ReadByte(CMPS11_ADDRESS, CMPS11_BEARING_8BIT);
		BW_CMPS11.Compass8Bit=I2C2_DATA[0];
		BW_CMPS11.Compass8Bit*=1.411;
		Sendto_PC(USART1,"ANGLE_8BIT: %d \t\t",BW_CMPS11.Compass8Bit);

	//	BW_CMPS11.Compass8Bit= BW_CMPS11.Compass8Bit/255;
	//	BW_CMPS11.Compass8Bit= BW_CMPS11.Compass8Bit*360;

		Sendto_PC(USART1,"Converted Angle: %d \t\t",BW_CMPS11.Compass8Bit);
		Sendto_PC(USART1,"ERROR_CODE: %d \r",ERROR_CODE);

//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"ANGLE: %d",BW_CMPS11.Compass8Bit);lcd_putstr(lcd);
//		delay_ms(100);
	}

	CMPS11_Angle=BW_CMPS11.Compass8Bit;

}

void HOME_START_POSITION(int angle)
{
	GetCMPS11_Angle8Bit();
	if(CMPS11_Angle <= angle)
	{
		Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
	}
	else
	{
		Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
	}
}
/* func      : void GetCMPS11_Angle16Bit(void)
 * brief     : Read CMPS11 Compass Bearing in 16 Bit Resolution
 * param     : N/A
 * retval    : N/A
 * Ver       : 2
 * written By: Ryan (Saturday, January 30th 2016)
 * Revised By: Ryan (Monday, February 1st 2016)
 * Programmer's Note: Compass Data stored in:
 * 					  BW_CMPS11.Compass16Bit[HIGH]   -> HIGH Byte
 * 					  BW_CMPS11.Compass16Bit[LOW]    -> LOW  Byte
 * 					  BW_CMPS11.Compass16Bit[MERGED] -> MERGED Byte
 */
void GetCMPS11_Angle16Bit(void)
{
//	int CMPS_H,CMPS_L;
	unsigned int ERROR_CODE=0;

	/*
	 * 	Read Single Byte Version
	 */
//	Sendto_PC(USART1,"==== READ SINGLE BYTE==== \r");

//	RyanRead_I2C2(CMPS11_ADDRESS, CMPS11_BEARING_16BIT_H);
//	CMPS_H=DATA;
	ERROR_CODE= I2C2_ReadByte(CMPS11_ADDRESS, CMPS11_BEARING_16BIT_H);
	BW_CMPS11.Compass16Bit[HIGH]= I2C2_DATA[0];

//	RyanRead_I2C2(CMPS11_ADDRESS, CMPS11_BEARING_16BIT_L);
//	CMPS_L=DATA;
	ERROR_CODE= I2C2_ReadByte(CMPS11_ADDRESS, CMPS11_BEARING_16BIT_L);
	BW_CMPS11.Compass16Bit[LOW]= I2C2_DATA[0];

	Sendto_PC(USART1,"ANGLE_H: %d \t\t",BW_CMPS11.Compass16Bit[HIGH]);
	Sendto_PC(USART1,"ANGLE_L: %d \t\t",BW_CMPS11.Compass16Bit[LOW]);

	BW_CMPS11.Compass16Bit[MERGED] = BW_CMPS11.Compass16Bit[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.Compass16Bit[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.Compass16Bit[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.Compass16Bit[MERGED] |= BW_CMPS11.Compass16Bit[LOW];

	//Convert 0 ~ 3599 Value to 0 ~ 359.9 Degrees
	BW_CMPS11.Compass16Bit[MERGED]/=10;

	Sendto_PC(USART1,"MERGED ANGLE_16BIT: %d \r",(int) BW_CMPS11.Compass16Bit[MERGED]);

	/*
	 * Read MultiByte Version
	 */
//	Sendto_PC(USART1,"==== READ MULTI BYTE==== \r");
//
//	ERROR_CODE= I2C2_ReadMultiByte(CMPS11_ADDRESS, CMPS11_BEARING_16BIT_H, 2);
//	BW_CMPS11.Compass16Bit[HIGH]= I2C2_DATA[0];
//	BW_CMPS11.Compass16Bit[LOW]= I2C2_DATA[1];
//
//	Sendto_PC(USART1,"ANGLE_H: %d \t\t",BW_CMPS11.Compass16Bit[HIGH]);
//	Sendto_PC(USART1,"ANGLE_L: %d \t\t",BW_CMPS11.Compass16Bit[LOW]);
//
//	BW_CMPS11.Compass16Bit[MERGED] = BW_CMPS11.Compass16Bit[HIGH];
//
//	//Shift to the HIGH BYTE Value
//	BW_CMPS11.Compass16Bit[MERGED] <<= 8;
//	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",(int)BW_CMPS11.Compass16Bit[MERGED]);
//
//	//Merge the HIGH BYTE and LOW BYTE Value
//	BW_CMPS11.Compass16Bit[MERGED] |= BW_CMPS11.Compass16Bit[LOW];
//
//	//Convert 0 ~ 3599 Value to 0 ~ 359.9 Degrees
//	BW_CMPS11.Compass16Bit[MERGED]/=10;
//
//	Sendto_PC(USART1,"MERGED ANGLE_16BIT: %d \r",(int)BW_CMPS11.Compass16Bit[MERGED]);
//
//	Sendto_PC(USART1,"ERROR_CODE: %d \r",ERROR_CODE);

//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"ANGLE: %d",(int)BW_CMPS11.Compass16Bit[MERGED]);lcd_putstr(lcd);
//	delay_ms(100);

}

/* func      : void GetCMPS11_MagRaw (void)
 * brief     : Read CMPS11 Magnetometer Raw Data
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 1st 2016)
 * Revised By: N/A
 * Programmer's Note: Compass Data stored in:
 * 					  BW_CMPS11.MagX[MERGED]
 * 					  BW_CMPS11.MagY[MERGED]
 * 					  BW_CMPS11.MagZ[MERGED]
 */
void GetCMPS11_MagRaw (void)
{
	int16_t ERROR_CODE=0;

	/*
	 * Read MultiByte Version
	 */
	Sendto_PC(USART1,"==== READ MULTI BYTE==== \r");

	ERROR_CODE= I2C2_ReadMultiByte(CMPS11_ADDRESS, CMPS11_MAG_XH, 6);

	/*
	 * Get X Axis Data
	 */
	//Assign X Axis Data
	BW_CMPS11.MagX[HIGH]= I2C2_DATA[0];
	BW_CMPS11.MagX[LOW] = I2C2_DATA[1];

	BW_CMPS11.MagX[MERGED] = BW_CMPS11.MagX[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.MagX[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.MagX[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.MagX[MERGED] |= BW_CMPS11.MagX[LOW];

	Sendto_PC(USART1,"MagX[MERGED]: %d \t\t",BW_CMPS11.MagX[MERGED]);


	/*
	 * Get Y Axis Data
	 */
	//Assign Y Axis Data
	BW_CMPS11.MagY[HIGH]= I2C2_DATA[2];
	BW_CMPS11.MagY[LOW] = I2C2_DATA[3];

	BW_CMPS11.MagY[MERGED] = BW_CMPS11.MagY[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.MagY[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.MagY[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.MagY[MERGED] |= BW_CMPS11.MagY[LOW];

	Sendto_PC(USART1,"MagY[MERGED]: %d \t\t",BW_CMPS11.MagY[MERGED]);

	/*
	 * Get Z Axis Data
	 */
	//Assign Z Axis Data
	BW_CMPS11.MagZ[HIGH]= I2C2_DATA[4];
	BW_CMPS11.MagZ[LOW]= I2C2_DATA[5];

	BW_CMPS11.MagZ[MERGED] = BW_CMPS11.MagZ[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.MagZ[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.MagZ[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.MagZ[MERGED] |= BW_CMPS11.MagZ[LOW];

	Sendto_PC(USART1,"MagZ[MERGED]: %d \t\t",BW_CMPS11.MagZ[MERGED]);

	Sendto_PC(USART1,"ERROR_CODE: %d \r",ERROR_CODE);
}

/* func      : void GetCMPS11_AccRaw (void)
 * brief     : Read CMPS11 Accelerometer Raw Data
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 1st 2016)
 * Revised By: N/A
 * Programmer's Note: Compass Data stored in:
 * 					  BW_CMPS11.AccX[MERGED]
 * 					  BW_CMPS11.AccY[MERGED]
 * 					  BW_CMPS11.AccZ[MERGED]
 */
void GetCMPS11_AccRaw (void)
{
	int16_t ERROR_CODE=0;

	/*
	 * Read MultiByte Version
	 */
	Sendto_PC(USART1,"==== READ MULTI BYTE==== \r");

	ERROR_CODE= I2C2_ReadMultiByte(CMPS11_ADDRESS, CMPS11_ACC_XH, 6);

	/*
	 * Get X Axis Data
	 */
	//Assign X Axis Data
	BW_CMPS11.AccX[HIGH]= I2C2_DATA[0];
	BW_CMPS11.AccX[LOW] = I2C2_DATA[1];

	BW_CMPS11.AccX[MERGED] = BW_CMPS11.AccX[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.AccX[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.AccX[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.AccX[MERGED] |= BW_CMPS11.AccX[LOW];

	Sendto_PC(USART1,"AccX[MERGED]: %d \t\t",BW_CMPS11.AccX[MERGED]);


	/*
	 * Get Y Axis Data
	 */
	//Assign Y Axis Data
	BW_CMPS11.AccY[HIGH]= I2C2_DATA[2];
	BW_CMPS11.AccY[LOW] = I2C2_DATA[3];

	BW_CMPS11.AccY[MERGED] = BW_CMPS11.AccY[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.AccY[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.AccY[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.AccY[MERGED] |= BW_CMPS11.AccY[LOW];

	Sendto_PC(USART1,"AccY[MERGED]: %d \t\t",BW_CMPS11.AccY[MERGED]);

	/*
	 * Get Z Axis Data
	 */
	//Assign Z Axis Data
	BW_CMPS11.AccZ[HIGH]= I2C2_DATA[4];
	BW_CMPS11.AccZ[LOW]= I2C2_DATA[5];

	BW_CMPS11.AccZ[MERGED] = BW_CMPS11.AccZ[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.AccZ[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.AccZ[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.AccZ[MERGED] |= BW_CMPS11.AccZ[LOW];

	Sendto_PC(USART1,"AccZ[MERGED]: %d \t\t",BW_CMPS11.AccZ[MERGED]);

	Sendto_PC(USART1,"ERROR_CODE: %d \r",ERROR_CODE);
}

/* func      : GetCMPS11_GyroRaw (void)
 * brief     : Read CMPS11 Gyroscope Raw Data
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 1st 2016)
 * Revised By: N/A
 * Programmer's Note: Compass Data stored in:
 * 					  BW_CMPS11.GyroX[MERGED]
 * 					  BW_CMPS11.GyroY[MERGED]
 * 					  BW_CMPS11.GyroZ[MERGED]
 */
void GetCMPS11_GyroRaw (void)
{
	int16_t ERROR_CODE=0;

	/*
	 * Read MultiByte Version
	 */
	Sendto_PC(USART1,"==== READ MULTI BYTE==== \r");

	ERROR_CODE= I2C2_ReadMultiByte(CMPS11_ADDRESS, CMPS11_GYRO_XH, 6);

	/*
	 * Get X Axis Data
	 */
	//Assign X Axis Data
	BW_CMPS11.GyroX[HIGH]= I2C2_DATA[0];
	BW_CMPS11.GyroX[LOW] = I2C2_DATA[1];

	BW_CMPS11.GyroX[MERGED] = BW_CMPS11.GyroX[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.GyroX[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.GyroX[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.GyroX[MERGED] |= BW_CMPS11.GyroX[LOW];

	Sendto_PC(USART1,"GyroX[MERGED]: %d \t\t",BW_CMPS11.GyroX[MERGED]);


	/*
	 * Get Y Axis Data
	 */
	//Assign Y Axis Data
	BW_CMPS11.GyroY[HIGH]= I2C2_DATA[2];
	BW_CMPS11.GyroY[LOW] = I2C2_DATA[3];

	BW_CMPS11.GyroY[MERGED] = BW_CMPS11.GyroY[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.GyroY[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.GyroY[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.GyroY[MERGED] |= BW_CMPS11.GyroY[LOW];

	Sendto_PC(USART1,"GyroY[MERGED]: %d \t\t",BW_CMPS11.GyroY[MERGED]);

	/*
	 * Get Z Axis Data
	 */
	//Assign Z Axis Data
	BW_CMPS11.GyroZ[HIGH]= I2C2_DATA[4];
	BW_CMPS11.GyroZ[LOW]= I2C2_DATA[5];

	BW_CMPS11.GyroZ[MERGED] = BW_CMPS11.GyroZ[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.GyroZ[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.GyroZ[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.GyroZ[MERGED] |= BW_CMPS11.GyroZ[LOW];

	Sendto_PC(USART1,"GyroZ[MERGED]: %d \t\t",BW_CMPS11.GyroZ[MERGED]);

	Sendto_PC(USART1,"ERROR_CODE: %d \r",ERROR_CODE);
}

/* func      : void GetCMPS11_Temperature (void)
 * brief     : Read CMPS11 Temperature Data
 * param     : N/A
 * retval    : N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 1st 2016)
 * Revised By: N/A
 * Programmer's Note: Compass Data stored in:
 * 					  BW_CMPS11.Temperature[HIGH]
 * 					  BW_CMPS11.Temperature[LOW]
 * 					  BW_CMPS11.Temperature[MERGED]
 */
void GetCMPS11_Temperature (void)
{
	int16_t ERROR_CODE;

	/*
	 * Read MultiByte Version
	 */
	Sendto_PC(USART1,"==== READ MULTI BYTE==== \r");

	ERROR_CODE= I2C2_ReadMultiByte(CMPS11_ADDRESS, CMPS11_TEMP_H, 2);

	/*
	 * Get X Axis Data
	 */
	//Assign X Axis Data
	BW_CMPS11.Temperature[HIGH]= I2C2_DATA[0];
	BW_CMPS11.Temperature[LOW] = I2C2_DATA[1];

	BW_CMPS11.Temperature[MERGED] = BW_CMPS11.Temperature[HIGH];

	//Shift to the HIGH BYTE Value
	BW_CMPS11.Temperature[MERGED] <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",BW_CMPS11.Temperature[MERGED]);

	//Merge the HIGH BYTE and LOW BYTE Value
	BW_CMPS11.Temperature[MERGED] |= BW_CMPS11.Temperature[LOW];

	Sendto_PC(USART1,"Temperature[MERGED]: %d \t\t",(int)BW_CMPS11.Temperature[MERGED]);

}

/*
 * Complementary Filter
 */
void CMPS11_GetComplementaryFilter(void)
{
	float CMPS11AccAngle_X=0;
	float CMPS11AccAngle_Y=0;
	float CMPS11AccAngle_Z=0;
	float CMPS11_LPF_AccX=0;
	float CMPS11_LPF_AccY=0;
	float CMPS11_LPF_AccZ=0;

	GetCMPS11_AccRaw();
	GetCMPS11_GyroRaw();

	CMPS11AccAngle_X= (float) 57.295 * atan((float)BW_CMPS11.AccY[MERGED] / sqrt (pow((float)BW_CMPS11.AccZ[MERGED],2) + pow((float)BW_CMPS11.AccX[MERGED],2)));

	CMPS11AccAngle_Y= (float) 57.295 * atan((float)-BW_CMPS11.AccX[MERGED] / sqrt(pow((float)BW_CMPS11.AccZ[MERGED],2) + pow((float)BW_CMPS11.AccY[MERGED],2)));

	CMPS11AccAngle_Z= (float) 57.295 * atan(sqrt (pow((float)BW_CMPS11.AccX[MERGED],2) + pow((float)BW_CMPS11.AccY[MERGED],2) / (float)BW_CMPS11.AccZ[MERGED]));

	CMPS11_LPF_AccX= (float) ( BW_CMPS11.AccX[MERGED] * ALPHA + (CMPS11_LPF_AccX * (1.0 - ALPHA)) );
	CMPS11_LPF_AccY= (float) ( BW_CMPS11.AccY[MERGED] * ALPHA + (CMPS11_LPF_AccY * (1.0 - ALPHA)) );
	CMPS11_LPF_AccZ= (float) ( BW_CMPS11.AccZ[MERGED] * ALPHA + (CMPS11_LPF_AccZ * (1.0 - ALPHA)) );

	BW_CMPS11.RollComp= (float) (atan2(-CMPS11_LPF_AccY,CMPS11_LPF_AccZ)*180.0)/M_PI;
	BW_CMPS11.PitchComp= (float) (atan2(-CMPS11_LPF_AccX, sqrt( (CMPS11_LPF_AccY*CMPS11_LPF_AccY)+(CMPS11_LPF_AccZ*CMPS11_LPF_AccZ)))*180)/M_PI;

	Sendto_PC(USART1,"BW_CMPS11.RollComp: %d \t\t",(int)BW_CMPS11.RollComp);
	Sendto_PC(USART1,"BW_CMPS11.PitchComp: %d \t\t\r",(int)BW_CMPS11.PitchComp);

	BW_CMPS11.RollComp2  = 0.93 * (BW_CMPS11.RollComp2  + BW_CMPS11.RollComp)  + (0.07 * CMPS11AccAngle_X);
	BW_CMPS11.PitchComp2 = 0.93 * (BW_CMPS11.PitchComp2 + BW_CMPS11.PitchComp) + (0.07 * CMPS11AccAngle_Y);

	Sendto_PC(USART1,"BW_CMPS11.RollComp2: %d \t\t",(int)BW_CMPS11.RollComp2);
	Sendto_PC(USART1,"BW_CMPS11.PitchComp2: %d \t\t\r",(int)BW_CMPS11.PitchComp2);

}


/*
 * ACCESSING CMPS-11 THROUGH THE UART/USART COMMUNICATION PROTOCOL
 */
// Send USART

/* func      : void CMPS11_Transmit(USART_TypeDef* USARTx, int DATA)
 * brief     : Send data to CMPS-11 Device through USART/UART Communication Protocol
 * param     :	N/A
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Saturday, January 30th 2016)
 * Revised By: N/A
 *
 */
void CMPS11_Transmit(USART_TypeDef* USARTx, int DATA)
{
  while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); // Wait empty
  USART_SendData(USARTx, DATA); // Send char
}

/* func      : void CMPS11_I2C_Calibration (void)
 * brief     : CMPS-11 Magnetometer, Accelerometer, and Gyroscope Calibration using UART/USART Communication Protocol
 * param     :	N/A
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Friday, January 30th 2016)
 * Revised By: N/A
 *
 */
void CMPS11_Calibration(void)
{
	int BW_BUTTON=0;

	CMPS11_Transmit(UART4,CALIBRATE_BYTE_1);
	Sendto_PC(USART1,"CALIBRATE_1 %d \r",USART2_DATA);
	CMPS11_Transmit(UART4,CALIBRATE_BYTE_2);
	Sendto_PC(USART1,"CALIBRATE_2 %d \r",USART2_DATA);
	CMPS11_Transmit(UART4,CALIBRATE_BYTE_3_FULL);
	Sendto_PC(USART1,"CALIBRATE_3 %d \r",USART2_DATA);

	BW_Buzz(4);
	while(BW_BUTTON==0)
	{
		BW_BUTTON=BW_BUTTON_INPUT;
	}

	CMPS11_Transmit(UART4,CALIBRATE_EXIT);
	Sendto_PC(USART1,"CALIBRATE_EXIT %d \r",USART2_DATA[0]);



}

void CMPS11_GetPitch(void)
{
	CMPS11_Transmit(USART2,GET_PITCH);
	delay_ms(200);
	Sendto_PC(USART1,"PITCH: %d \r",USART2_DATA[0]);
}

void CMPS11_GetRoll(void)
{
	CMPS11_Transmit(USART2,GET_ROLL);
	delay_ms(200);
	Sendto_PC(USART1,"ROLL: %d \r",USART2_DATA[0]);
}

void CMPS11_GetAngle16Bit(void)
{
	int ANGLE_16BIT;

	CMPS11_Transmit(USART2,GET_ANGLE_16_BIT);
	delay_ms(200);

	Sendto_PC(USART1,"ANGLE_H: %d \t\t",USART2_DATA[0]);
	Sendto_PC(USART1,"ANGLE_L: %d \t\t",USART2_DATA[1]);

	ANGLE_16BIT=USART2_DATA[0];
	ANGLE_16BIT <<= 8;
	Sendto_PC(USART1,"LEFT SHIFTED: %d \t\t",ANGLE_16BIT);

	ANGLE_16BIT |= USART2_DATA[1];

	//ANGLE_16BIT/=10;

	Sendto_PC(USART1,"MERGED ANGLE_16BIT: %d \r",ANGLE_16BIT);
}

void CMPS11_GetAngle8Bit(void)
{
	CMPS11_Transmit(USART2,GET_ANGLE_8_BIT);
	delay_ms(200);
	Sendto_PC(USART1,"ANGLE_8BIT: %d \r",USART2_DATA[0]);
}




/*
 *  I2C3 COMMUNICATION
 */

/* func      : 	void I2C3_Init (void)
 * brief     : 	I2C3 BUS Initialization
 * param     :	N/A
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Tuesday, February 24th 2016)
 * Revised By: N/A
 * Programmer's Note: Specifically on I2C3, maximum frequency = 250 kHz (with occasional TimeOut)
 * 					Use 200kHz max for optimum performance
 * 					400kHz bus frequency cannot be used, TimeOut occurs on code (-5)
 *
 */
void I2C3_Init (void)
{
	/*  GPIO Setup  */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /*  I2C Setup  */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C3, ENABLE);
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
//    I2C_InitStructure.I2C_ClockSpeed = 400000; //400kHz
    I2C_InitStructure.I2C_ClockSpeed = 200000; //200kHz (optimum performance, without TimeOut)
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_OwnAddress1 = 0x00;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

    I2C_Cmd(I2C3, ENABLE);
    I2C_Init(I2C3, &I2C_InitStructure);

    /* Connect PXx to I2C_SCL*/
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_I2C3);

    /* Connect PXx to I2C_SDA*/
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_I2C3);
}






/* func      : int16_t I2C3_TimeOut(int16_t VALUE)
 * brief     : STOP, RESET, and RE-INIT the I2C2 Communication Interface
 * param     :	int16_t VALUE : TIMEOUT CODE
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C3_ReadMultiByte SUCCESS!
 * 				RetVal < 0 -> I2C3_ReadMultiByte ERROR!
 * Ver       : 1
 * written By: Ryan (Tuesday, February 24th 2016)
 * Revised By: N/A
 *
 */
int16_t I2C3_TimeOut(int16_t VALUE)
{
	int16_t RetVal= VALUE;

//	Stop and reset
	I2C_GenerateSTOP(I2C3,ENABLE);
	I2C_SoftwareResetCmd(I2C3,ENABLE);
	I2C_SoftwareResetCmd(I2C1, DISABLE);
	I2C_SoftwareResetCmd(I2C2, DISABLE);

	// I2C De-Init
	I2C_DeInit(I2C3);

//	I2C Re-Init
	I2C3_Init();

    return(RetVal);
}


/* func      : int16_t I2C3_ReadByte(uint8_t ADDRESS, uint8_t REGISTER)
 * brief     : Read single byte variables from I2C3 Bus
 * param     :
 * 				uint8_t ADDRESS : I2C Slave Device Address
 * 				uint8_t REGISTER: Register Address
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C3_ReadByte SUCCESS!
 * 				RetVal < 0 -> I2C3_ReadByte ERROR!
 * 				Data stored int I2C3_DATA[0]
 * Ver       : 1
 * written By: Ryan (Tuesday, February 24th 2016)
 * Revised By: N/A
 *
 */
int16_t I2C3_ReadByte(uint8_t ADDRESS, uint8_t REGISTER)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C3_TIMEOUT;
//	  uint8_t Value,counter;

	  //Start Sequences
	  I2C_GenerateSTART(I2C3, ENABLE);

	  TimeOut= I2C3_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C3,I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C3_TimeOut(-1));
	  }

	  // ACK disable
	  I2C_AcknowledgeConfig(I2C3, DISABLE);

	  // Slave Address Send (write)
	  I2C_Send7bitAddress(I2C3, ADDRESS, I2C_Direction_Transmitter);

	  TimeOut= I2C3_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C3, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C3_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C3->SR2;

	  TimeOut=I2C3_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C3, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C3_TimeOut(-3));
	  }

	  // SEND REGISTER ADDRESS
	  I2C_SendData(I2C3, REGISTER);

	  TimeOut=I2C3_TIMEOUT;
	  while ((!I2C_GetFlagStatus(I2C3, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C3, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C3_TimeOut(-4));
	  }

	  // Start Sequence
	  I2C_GenerateSTART(I2C3, ENABLE);

	  TimeOut=I2C3_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C3, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C3_TimeOut(-5));
	  }

	  // Slave Address Send (read(CMPS11_ADDRESS, CMPS11_BEARING_8BIT);
	  I2C_Send7bitAddress(I2C3, ADDRESS, I2C_Direction_Receiver);

	  TimeOut=I2C3_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C3, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C3_TimeOut(-6));
	  }

	  // Clear ADDR Flag
	  I2C3->SR2;

	  while (!I2C_GetFlagStatus(I2C3, I2C_FLAG_RXNE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C3_TimeOut(-7));
	  }

	  // Stop Sequences
	  I2C_GenerateSTOP(I2C3, ENABLE);

	  // Read data
	  I2C3_DATA[0]=I2C_ReceiveData(I2C3);

	  // ACK enable
	  I2C_AcknowledgeConfig(I2C3, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return(RetVal);
}

void I2C3_Test(void)
{
	int16_t ERROR_CODE=0;
	ERROR_CODE= I2C3_ReadByte(CMPS11_ADDRESS, CMPS11_BEARING_8BIT);
	BW_CMPS11.Compass8Bit=I2C3_DATA[0];

	Sendto_PC(USART1,"ANGLE_8BIT: %d \t\t",BW_CMPS11.Compass8Bit);

	BW_CMPS11.Compass8Bit= BW_CMPS11.Compass8Bit/255*360;

	Sendto_PC(USART1,"Converted Angle: %d \t\t",BW_CMPS11.Compass8Bit);
	Sendto_PC(USART1,"ERROR_CODE: %d \r",ERROR_CODE);
}

void Get_East_Status(void)
{
	GetCMPS11_Angle8Bit();
//	if((CMPS11_Angle<NORTH_THRESHOLD_LOWER) || (CMPS11_Angle>NORTH_THRESHOLD_UPPER))
	if((CMPS11_Angle<WEST_THRESHOLD_LOWER) || (CMPS11_Angle>WEST_THRESHOLD_UPPER))
//	if((CMPS11_Angle<SOUTH_THRESHOLD_LOWER) || (CMPS11_Angle>SOUTH_THRESHOLD_UPPER))
//	if((CMPS11_Angle<EAST_THRESHOLD_LOWER) || (CMPS11_Angle>EAST_THRESHOLD_UPPER))
	{
		ARENA_FLAG=CMPS_INACTIVE;
	}
	else
	{
		ARENA_FLAG=CMPS_ACTIVE;
	}
}

void Get_North_Status(void)
{
	GetCMPS11_Angle8Bit();
//	if((CMPS11_Angle<(R4B_THRESHOLD_LOWER-30)) || (CMPS11_Angle>(R4B_THRESHOLD_UPPER+20)))
////	if((CMPS11_Angle<NORTH_THRESHOLD_LOWER) || (CMPS11_Angle>NORTH_THRESHOLD_UPPER))
////	if((CMPS11_Angle<WEST_THRESHOLD_LOWER) || (CMPS11_Angle>WEST_THRESHOLD_UPPER))
////	if((CMPS11_Angle<SOUTH_THRESHOLD_LOWER) || (CMPS11_Angle>SOUTH_THRESHOLD_UPPER))
////	if((CMPS11_Angle<EAST_THRESHOLD_LOWER) || (CMPS11_Angle>EAST_THRESHOLD_UPPER))
//	{
//		ARENA_FLAG=CMPS_INACTIVE;
//	}
//	else
//	{
//		ARENA_FLAG=CMPS_ACTIVE;
//	}
}


void Get_Data_Status(void)
{
	GetCMPS11_Angle8Bit();
	if((CMPS11_Angle>NORTH_THRESHOLD_LOWER) && (CMPS11_Angle<NORTH_THRESHOLD_UPPER))
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"DIRECTION :");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"NORTH / %d",CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(100);
	}
	else if((CMPS11_Angle>WEST_THRESHOLD_LOWER) && (CMPS11_Angle<WEST_THRESHOLD_UPPER))
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"DIRECTION :");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"WEST / %d",CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(100);
	}
	else if((CMPS11_Angle>SOUTH_THRESHOLD_LOWER) && (CMPS11_Angle<SOUTH_THRESHOLD_UPPER))
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"DIRECTION :");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"SOUTH / %d",CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(100);
	}
	else if((CMPS11_Angle>EAST_THRESHOLD_LOWER) && (CMPS11_Angle<EAST_THRESHOLD_UPPER))
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"DIRECTION :");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"EAST / %d",CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(100);
	}
	else
	{
		lcd_display_clear();
		lcd_gotoxy(0,0);sprintf(lcd,"BW 2016");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"DIRECTION :");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"----- / %d",CMPS11_Angle);lcd_putstr(lcd);
		delay_ms(100);
	}

}

void Display_Yaw_Angle(void)
{
//	GetCMPS11_Angle8Bit();
	Get_East_Status();

	lcd_display_clear();
	lcd_gotoxy(1,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(0,1);sprintf(lcd,"COMPASS  MONITOR");lcd_putstr(lcd);
	lcd_gotoxy(0,2);sprintf(lcd,"YAW ANGLE: %d",CMPS11_Angle);lcd_putstr(lcd);

	if(ARENA_FLAG==CMPS_ACTIVE)
	{
		lcd_gotoxy(0,3);sprintf(lcd,"EASTFLG ACTIVE");lcd_putstr(lcd);
	}
	else
	{
		lcd_gotoxy(0,3);sprintf(lcd,"EASTFLG INACTIVE");lcd_putstr(lcd);
	}
	delay_ms(100);

}
