#include "bw_usart_comm.h"

/*
 * HC-05 BLUETOOTH MODULE
 */

void USART1_Init(uint32_t baudrate)
{ //TO SERVO CONTROLLER
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;  // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOB, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1); //
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);

	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART1, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff

	// finally this enables the complete USART1 peripheral
	USART_Cmd(USART1, ENABLE);
}

/*
 *  func : void USART1_IRQHandler(void)
 *  brief: USART1 RX Interupt handler from Main Controller to Servo Controller
 *  param: command_code[0] -> gait_mode code selection
 *  	   command_code[1] -> speed paameter for each gait_mode function
 */

void USART1_IRQHandler(void)
{
	//comment
	if( USART_GetITStatus(USART1, USART_IT_RXNE) )
	{
		char t = USART1->DR; // the character from the USART3 data register is saved in t
		char static last_data;


		switch(USART_Bluetooth_Count)
		{
			//case  0 : USART_Bluetooth_Count+=1; break;
			case  1 : command_code[0] =USART1->DR; USART_Bluetooth_Count+=1; break;
			case  2 : command_code[1] =USART1->DR; USART_Bluetooth_Count+=1; break;
			case  3 : command_code[2] =USART1->DR; USART_Bluetooth_Count+=1; break;
			case  4 : command_code[3] =USART1->DR; USART_Bluetooth_Count+=1; break;
			case  5 : command_code[4] =USART1->DR; USART_Bluetooth_Count=811; break;
			default : break;
		}

		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USART_Bluetooth_Count=1; //  TERMINATING COMMAND <>
		last_data=t;
	}
}


/*
 * DYNAMIXEL
 */
//void USART2_Init(uint32_t baudrate)
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
//
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
//
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;  // Pins 2 (TX) and 3 (RX) are used
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
//	GPIO_Init(GPIOA, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
//
//	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); //
//	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
//
//	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
//	USART_InitStructure.USART_StopBits = USART_StopBits_2;		// we want 1 stop bit (standard)
//	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
//	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
//	USART_Init(USART2, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting
//
//	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt
//
//	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;		 // we want to configure the USART3 interrupts
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		 // this sets the subpriority inside the group
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
//	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff
//
//	// finally this enables the complete USART2 peripheral
//	USART_Cmd(USART2, ENABLE);
//}

//void USART2_IRQHandler(void)
//{
//	if( USART_GetITStatus(USART2, USART_IT_RXNE) )
//	{
//		char t = USART2->DR; // the character from the USART3 data register is saved in t
//		char static last_data;
//
//		switch(USARTFlame_Counter)
//		{
//			case  1 : FlameSense[0]= USART2->DR; USARTFlame_Counter+=1; break;
//		}
//		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USARTFlame_Counter=1;
//		last_data=t;
//	}
//
//}








/*
 * CMUCAM5 VISION SENSOR+ENCODER MASTER-SLAVE COMMUNICATION
 * STM32 TX -> CMUCAM5 RX
 * CMUCAM5 TX -> ENCODER mCU RX
 * ENCODER mCU TX -> STM32 RX
 */
void UART4_Init(uint32_t baudrate)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;  // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOC, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_UART4);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_UART4);

	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(UART4, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff

	// finally this enables the complete USART6 peripheral
	USART_Cmd(UART4, ENABLE);
}
//
void UART4_IRQHandler(void)
{
	if( USART_GetITStatus(UART4, USART_IT_RXNE) )
	{
		char t = UART4->DR; // the character from the USART3 data register is saved in t
		char static last_data;

		switch(USARTFlameDigi_Counter)
		{
			case  1 : FlameSenseDigi[0]= UART4->DR; USARTFlameDigi_Counter+=1; break;
			case  2 : FlameFrontDigi[0]= UART4->DR; USARTFlameDigi_Counter+=13; break;
		}
		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USARTFlameDigi_Counter=1;
		last_data=t;
	}
}

/*
 * TCS3200 SLAVE mCU
 */
void UART5_Init(uint32_t baudrate)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5,ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;  // Pins 12 (TX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOC, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;  // Pins 2 (RX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOD, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers


	GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_UART5);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource2, GPIO_AF_UART5);

	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(UART5, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(UART5, USART_IT_RXNE, ENABLE); // enable the USART5 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff

	// finally this enables the complete USART5 peripheral
	USART_Cmd(UART5, ENABLE);
}

void UART5_IRQHandler(void)
{
	//TRIAL MODE
//	if( USART_GetITStatus(UART5, USART_IT_RXNE) )
//	{
//		char t = UART5->DR; // the character from the USART3 data register is saved in t
//		char static last_data;
//
//		switch(TCS3200_SLV_CNT)
//		{
//			case  1 : TCS3200_SLV_STAT[0]= UART5->DR; TCS3200_SLV_CNT+=1; break;
//			case  2 : TCS3200_SLV_STAT[1]= UART5->DR; TCS3200_SLV_CNT+=1; break;
//			case  3 : TCS3200_SLV_STAT[2]= UART5->DR; TCS3200_SLV_CNT+=1; break;
//			case  4 : TCS3200_SLV_STAT[3]= UART5->DR; TCS3200_SLV_CNT+=63; break;
//		}
//		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) TCS3200_SLV_CNT=1;
//		last_data=t;
//	}

	//CALIBRATION MODE
	if( USART_GetITStatus(UART5, USART_IT_RXNE) )
	{
		char t = UART5->DR; // the character from the USART3 data register is saved in t
		char static last_data;

		switch(TCS3200_SLV_CNT)
		{
			case  1 : TCS3200_SLV_DATA[0]= UART5->DR; TCS3200_SLV_CNT+=1; break; //RAW_VAL)FLAG

			//MULTIPLY_COUNTER MID_Pulse_R
			case  2 : TCS3200_SLV_DATA[1]= UART5->DR; TCS3200_SLV_CNT+=1; break;

			//MODULO VALUE OF MID_Pulse_R
			case  3 : TCS3200_SLV_DATA[2]= UART5->DR; TCS3200_SLV_CNT+=1; break;

			case  4 : 	{
							//TCS3200 PROCESSOR SENDING RAW VALUE
							if(TCS3200_SLV_DATA[0]==RAW_VAL_FLAG)
							{
								//MULTIPLY_COUNTER MID_Pulse_G
								TCS3200_SLV_DATA[3]= UART5->DR; TCS3200_SLV_CNT+=1; break;
							}
							//TCS3200 PROCESSOR SENDING PROCESSED VALUE
							//ENDING THE INSTRUCTION FETCHING FLOW
							else
							{
								TCS3200_SLV_DATA[3]= UART5->DR; TCS3200_SLV_CNT+=63; break;
							}
						}

			//MODULO VALUE OF MID_Pulse_G
			case  5 : TCS3200_SLV_DATA[4]= UART5->DR; TCS3200_SLV_CNT+=1; break;

			//MULTIPLY_COUNTER MID_Pulse_B
			case  6 : TCS3200_SLV_DATA[5]= UART5->DR; TCS3200_SLV_CNT+=1; break;
			 //MODULO VALUE OF MID_Pulse_B
			case  7 : TCS3200_SLV_DATA[6]= UART5->DR; TCS3200_SLV_CNT+=1; break;

			//MULTIPLY_COUNTER MID_Pulse_W
			case  8 : TCS3200_SLV_DATA[7]= UART5->DR; TCS3200_SLV_CNT+=1; break;
			 //MODULO VALUE OF MID_Pulse_W
			case  9 : TCS3200_SLV_DATA[8]= UART5->DR; TCS3200_SLV_CNT+=1; break;

			//MULTIPLY_COUNTER MID_Pulse_Sum
			case  10 : TCS3200_SLV_DATA[9]= UART5->DR; TCS3200_SLV_CNT+=1; break;
			 //MODULO VALUE OF MID_Pulse_Sum
			case  11 : TCS3200_SLV_DATA[10]= UART5->DR; TCS3200_SLV_CNT+=63; break;

		}
		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) TCS3200_SLV_CNT=1;
		last_data=t;

//		if	(
//				( (TCS3200_SLV_DATA[0]==COLOUR_WHITE) ) &&
//				(FOLLOWTRACER_FLAG==FOLLOWTRACER_ENABLE)
//			)
//		{
//			 TRACER_STAT=TRACER_WHITE;
//		}

		if	(
				( (TCS3200_SLV_DATA[1]==TRACER_WHITE) && (TCS3200_SLV_DATA[0]!=COLOUR_WHITE) ) &&
				(FOLLOWTRACER_FLAG==FOLLOWTRACER_ENABLE)
			)
		{
			TRACER_STAT=TRACER_WHITE;
		}

	}

//	//CALIBRATION MODE
//	if( USART_GetITStatus(UART5, USART_IT_RXNE) )
//	{
//		char t = UART5->DR; // the character from the USART3 data register is saved in t
//		char static last_data;
//
//		switch(TCS3200_SLV_CNT)
//		{
//			case  1 : TCS3200_CMD_CODE[0]= UART5->DR; TCS3200_SLV_CNT+=99; break;
//		}
//		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) TCS3200_SLV_CNT=1;
//		last_data=t;
//	}
}

/*
 *
 */
void USART6_Init(uint32_t baudrate)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6,ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;  // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOC, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);

	USART_InitStructure.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART6, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff

	// finally this enables the complete USART6 peripheral
	USART_Cmd(USART6, ENABLE);
}

void USART6_IRQHandler(void)
{
	if( USART_GetITStatus(USART6, USART_IT_RXNE) )
	{
//		char t = USART6->DR; // the character from the USART3 data register is saved in t
//		char static last_data;
//
//		switch(USARTFlameDigi_Counter)
//		{
//			case  1 : FlameSenseDigi[0]= USART6->DR; USARTFlameDigi_Counter+=1; break;
//			case  2 : FlameFrontDigi[0]= USART6->DR; USARTFlameDigi_Counter+=13; break;
//		}
//		if(t==COMMAND_FLAG_B && last_data==COMMAND_FLAG_A) USARTFlameDigi_Counter=1;
//		last_data=t;
	}
}

/*
 * USART/UART TRANSMIT ROUTINES
 */
//fungsi yang dimatikan biar stabil
void Sendto_PC(USART_TypeDef* USARTx, const char *pFormat, ... )
{
//	    va_list ap;
//	    char pStr[100];
//
//	    va_start(ap, pFormat);
//	    vsprintf(pStr, pFormat, ap);
//	    va_end(ap);
//
//	    int i=0;
//	    int n = strlen(pStr);
//	    for(i=0;i<n;i++)
//	    {
//	        USART_SendData(USARTx, (uint8_t)pStr[i]);
//	        while (USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
//	    }
}


void Command_Gait(USART_TypeDef* USARTx, volatile char *s)
{
	while(*s)
	{
		// wait until data register is empty
		while( !(USARTx->SR & 0x00000040) );
		USART_SendData(USARTx,(int)*s);
		*s++;
	}
}

void TCS3200_CMD(USART_TypeDef* USARTx, volatile char *s)
{
	while(*s)
	{
		// wait until data register is empty
		while( !(USARTx->SR & 0x00000040) );
		USART_SendData(USARTx,(int)*s);
		*s++;
	}
}

void TCS3200_Transmit(USART_TypeDef* USARTx, int DATA)
{
  while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET); // Wait empty
  USART_SendData(USARTx, DATA); // Send char
}

void Send_FlameSense(void)
{
	if(FlameSense[0]>5){Sendto_PC(USART1,"ERROR \r");FlameSense[0]=0;}
	else {
			Sendto_PC(USART1, "FlameSense[1]: %d \t",FlameSense[1]);
			Sendto_PC(USART1, "FlameSense[0]: %d \r",FlameSense[0]);
		 }
}

void Display_FlameSense(void)
{
	Get_UV();
	GetFlame();

	if( (FlameSense[0]!=0) || (UV_state==0))
	{
		FIRE_LED_BLINK_ON;

		if(FlameSense[0]==0)
		{
			lcd_display_clear();
//			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//			lcd_gotoxy(1,0);sprintf(lcd,"FLAME  MONITOR");lcd_putstr(lcd);
			lcd_gotoxy(1,0);sprintf(lcd,"FLM: %d %d ",FlameSenseDigi[0],FlameFrontDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"UV_state: %d",UV_state);lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FLM MALFUNC");lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"FLM_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
			delay_ms(100);
		}
		if(UV_state==1)
		{
			lcd_display_clear();
//			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//			lcd_gotoxy(1,0);sprintf(lcd,"FLAME  MONITOR");lcd_putstr(lcd);
			lcd_gotoxy(1,0);sprintf(lcd,"FLM: %d %d ",FlameSenseDigi[0],FlameFrontDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"UV MALFUNC");lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FlameSense[0]: %d",FlameSense[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"FLM_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
			delay_ms(100);
		}
		else
		{
			BW_Buzz(1);
			lcd_display_clear();
//			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//			lcd_gotoxy(1,0);sprintf(lcd,"FLAME  MONITOR");lcd_putstr(lcd);
			lcd_gotoxy(1,0);sprintf(lcd,"FLM: %d %d ",FlameSenseDigi[0],FlameFrontDigi[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"UV_state: %d",UV_state);lcd_putstr(lcd);
			lcd_gotoxy(0,2);sprintf(lcd,"FlameSense[0]: %d",FlameSense[0]);lcd_putstr(lcd);
			lcd_gotoxy(0,3);sprintf(lcd,"FLM_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);
			delay_ms(100);

		}

//		while(FlameSense[0]!=0){};
	}

	else if(FlameSense[0]==0)
	{
		lcd_display_clear();
//		lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//		lcd_gotoxy(1,0);sprintf(lcd,"FLAME  MONITOR");lcd_putstr(lcd);
		lcd_gotoxy(1,0);sprintf(lcd,"FLM: %d %d ",FlameSenseDigi[0],FlameFrontDigi[0]);lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"UV_state: %d",UV_state);lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FlameSense[0]: %d",FlameSense[0]);lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"FLM_AN: %d",FLAME_SENSOR[FLM_ANALOG]);lcd_putstr(lcd);

		delay_ms(100);

		FIRE_LED_OFF;
		FIRE_LED_BLINK_OFF;
		FIRE_LED_OFF;
//		while(FlameSense[0]==0){};
	}
	FIRE_LED_OFF;
	FIRE_LED_BLINK_OFF;
	FIRE_LED_OFF;
}


