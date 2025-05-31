/*==============================================================================================
								  PROJECT YUME 3.17 Ver.1.0
								  YUME DYNAMIXEL AX-12A
==============================================================================================*/

#include "bw_dynamixel_ax_12a.h"

void Dynamixel_USART2_Init(uint32_t DYNAMIXEL_BAUDRATE)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;  // Pins 2 (TX) and 3 (RX) are used
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOA, &GPIO_InitStructure);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); //
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

	USART_InitStructure.USART_BaudRate = DYNAMIXEL_BAUDRATE;				// the baudrate is set to the value we passed into this init function
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStructure.USART_StopBits = USART_StopBits_2;		// we want 1 stop bit (standard)
	USART_InitStructure.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART2, &USART_InitStructure);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting

	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt

	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;		 // we want to configure the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART3 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART3 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff

	// finally this enables the complete USART2 peripheral
	USART_Cmd(USART2, ENABLE);

}

int16_t USART_TimeOut(int16_t VALUE)
{
	int16_t RetVal= VALUE;

// USART De-Init
	USART_DeInit(USART6);

//	USART Re-Init
	Dynamixel_USART2_Init(1000000);

	return(RetVal);
}

// Send USART
void Dynamx_Send(USART_TypeDef* USARTx, int DATA)
{
  uint32_t TimeOut= USART_TIMEOUT;
  USART_ClearFlag(USARTx,USART_FLAG_TXE);

  TimeOut = USART_TIMEOUT;
  while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET)
  {
    if(TimeOut!=0) TimeOut--;
    else return (USART_TimeOut(-1));;
  }// Wait empty
  USART_SendData(USARTx, DATA); // Send char
}

void Dynamixel_Pin_Config(void)
{
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin 	= GPIO_Pin_1 ;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;       	// Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd 	= GPIO_PuPd_NOPULL; 	// pin tidak diberikan pull up
	GPIO_Init(GPIOC, &GPIO_InitStructure); 	// inisialisasi periperal GPIO sesuai parameter typdef diatas
}
//*******************************Dynamixel*************************************//
int Dynamixel_moveSpeed(unsigned char ID, int Position, unsigned int Speed, unsigned int TX_DELAY_TIME)
{
    char Position_H,Position_L,Speed_H,Speed_L;
    Position_H = Position >> 8;
    Position_L = Position;                // 16 bits - 2 x 8 bits variables
    Speed_H = Speed >> 8;
    Speed_L = Speed;                      // 16 bits - 2 x 8 bits variables
    Checksum = (~(ID + AX_GOAL_SP_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H))&0xFF;


    GPIO_SetBits(GPIOC, GPIO_Pin_1);
//	lcd_display_clear();
//	lcd_gotoxy(0,3);sprintf(lcd,"C1 SETBITS");lcd_putstr(lcd);

    Dynamx_Send(USART6,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART6,AX_HEADER);
    Dynamx_Send(USART6,ID);
    Dynamx_Send(USART6,AX_GOAL_SP_LENGTH);
    Dynamx_Send(USART6,AX_WRITE_DATA);
    Dynamx_Send(USART6,AX_GOAL_POSITION_L);
    Dynamx_Send(USART6,Position_L);
    Dynamx_Send(USART6,Position_H);
    Dynamx_Send(USART6,Speed_L);
    Dynamx_Send(USART6,Speed_H);
    Dynamx_Send(USART6,Checksum);

    delay_ms(TX_DELAY_TIME);

    GPIO_ResetBits(GPIOC, GPIO_Pin_1);

    return -1 ;
}

int Dyna_Actuate(unsigned char Dyna_ID, unsigned int Angle, unsigned int Speed, unsigned int TX_DELAY_TIME)
{
	int Position;
    char Position_H,Position_L,Speed_H,Speed_L;

    //Convert Angle to position value
    Position= Angle*1024;
    Position= Position/300;
    if(Position!=0) {Position-=1;}

//    Position = Angle;

    //Break 16 Bit value to two variables of 8 bit each
    Position_H = Position >> 8;
    Position_L = Position;

    //Break 16 Bit value to two variables of 8 bit each
    Speed_H = Speed >> 8;
    Speed_L = Speed;

    Checksum = (~(Dyna_ID + AX_GOAL_SP_LENGTH + AX_WRITE_DATA + AX_GOAL_POSITION_L + Position_L + Position_H + Speed_L + Speed_H))&0xFF;

//	lcd_gotoxy(0,3);sprintf(lcd,"BW SETBITS PINC1");lcd_putstr(lcd);

    GPIO_SetBits(GPIOC, GPIO_Pin_1);

    Dynamx_Send(USART2,AX_HEADER); // Send Instructions over Serial
    Dynamx_Send(USART2,AX_HEADER);
    Dynamx_Send(USART2,Dyna_ID);
    Dynamx_Send(USART2,AX_GOAL_SP_LENGTH);
    Dynamx_Send(USART2,AX_WRITE_DATA);
    Dynamx_Send(USART2,AX_GOAL_POSITION_L);
    Dynamx_Send(USART2,Position_L);
    Dynamx_Send(USART2,Position_H);
    Dynamx_Send(USART2,Speed_L);
    Dynamx_Send(USART2,Speed_H);
    Dynamx_Send(USART2,Checksum);

    delay_us(TX_DELAY_TIME);

//	lcd_gotoxy(0,3);sprintf(lcd,"BW RESETBITS PINC1");lcd_putstr(lcd);

    GPIO_ResetBits(GPIOC, GPIO_Pin_1);

    return -1;
}

//void DynamixelDrive (unsigned int Speed)
//{
//    int length = 4 + (18 * 5);   // 5 = id + pos(2byte) + speed(2 bytes)
//    int checksum = 254 + length + AX_SYNC_WRITE + 4 + AX_GOAL_POSITION_L; //255
//
////    GPIO_SetBits(GPIOC, GPIO_Pin_1);
//
//    Dynamx_Send(USART6,AX_HEADER);
//    Dynamx_Send(USART6,AX_HEADER);
//    Dynamx_Send(USART6,BROADCAST_ID);
//    Dynamx_Send(USART6,length);
//    Dynamx_Send(USART6,AX_SYNC_WRITE);
//    Dynamx_Send(USART6,AX_GOAL_POSITION_L);
//    Dynamx_Send(USART6,4);    // number of bytes per servo (plus the ID...)
//
//    int i;
//    for (i = 0; i < 18; i++) {
//
//      unsigned char id = (*((char *)&Dynamixel_Pin[i]));
//      checksum += id + (DynamixelPos[i] & 255) + (DynamixelPos[i] >> 8) + (Speed >> 8) + (Speed & 255);
//      Dynamx_Send(USART6,id);
//      Dynamx_Send(USART6,DynamixelPos[i] & 255);
//      Dynamx_Send(USART6,DynamixelPos[i] >> 8);
//      Dynamx_Send(USART6,Speed & 255);
//      Dynamx_Send(USART6,Speed >> 8);
//
//    }
//    Dynamx_Send(USART6,255 - (checksum % 256)); //254
//
////    delay_us(1000);
////    GPIO_ResetBits(GPIOC, GPIO_Pin_1);
//
////    return -1;
//}

void DynamixelDrive (unsigned int speed)
{
	unsigned char position_H = 0;
	unsigned char position_L = 0;
	unsigned char speed_H = 0;
	unsigned char speed_L = 0;
	unsigned char id;
	unsigned char panjangData = 4;
	unsigned char jumlahServo = 6 * 3;
	unsigned char LENGTH = (panjangData + 1) * jumlahServo + 4;//19; // (panjang data +1) x jumlah servo + 4 ===>>> lighat manual rx 28 halaman 37
	// tentukanKecepatanServo(speed);
	speed_H = speed>>8; //high adresses
	speed_L = speed&0xff; //low addresses karena pengiriman data harus 16bit tetapi dipecah menjadi 2 yaitu masing2 8bit
	Checksum =0xFE + LENGTH + 0X83 + AX_GOAL_POSITION_L + panjangData;
	//############# HEADER ############//
	bufferDataTx[0]=0xFF;
	bufferDataTx[1]=0xFF;
	//######## BROADCAST INTRUCTION ############//
	bufferDataTx[2]=0xFE;
	//######## LENGTH ############//
	bufferDataTx[3]=LENGTH;
	//######## SYNC WRITE ############//
	bufferDataTx[4]=0x83;
	//######## FISRT ADDRESS ############//
	bufferDataTx[5]=AX_GOAL_POSITION_L;
	//######## LENGTH OF DATA ############//
	bufferDataTx[6]=panjangData;
	//######## SERVO 00 ##################//
	position_H = outServo[0]>>8;
	position_L = outServo[0]&0xff;

	id =1;

	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[7] = id;
	bufferDataTx[8] = position_L;
	bufferDataTx[9] = position_H;
	bufferDataTx[10] = speed_L;
	bufferDataTx[11] = speed_H;
	//######## SERVO 01 ##################//
	position_H = outServo[1]>>8;
	position_L = outServo[1]&0xff;

	id =2;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[12] = id;
	bufferDataTx[13] = position_L;
	bufferDataTx[14] = position_H;
	bufferDataTx[15] = speed_L;
	bufferDataTx[16] = speed_H;
	//######## SERVO 02 ##################//
	position_H = outServo[2]>>8;
	position_L = outServo[2]&0xff;

	id =3;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[17] = id;
	bufferDataTx[18] = position_L;
	bufferDataTx[19] = position_H;
	bufferDataTx[20] = speed_L;
	bufferDataTx[21] = speed_H;
	//######## SERVO 10 ##################//
	position_H = outServo[3]>>8;
	position_L = outServo[3]&0xff;

	id =4;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[22] = id;
	bufferDataTx[23] = position_L;
	bufferDataTx[24] = position_H;
	bufferDataTx[25] = speed_L;
	bufferDataTx[26] = speed_H;
	//######## SERVO 11 ##################//
	position_H = outServo[4]>>8;
	position_L = outServo[4]&0xff;

	id =5;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[27] = id;
	bufferDataTx[28] = position_L;
	bufferDataTx[29] = position_H;
	bufferDataTx[30] = speed_L;
	bufferDataTx[31] = speed_H;
	//######## SERVO 12 ##################//
	position_H = outServo[5]>>8;
	position_L = outServo[5]&0xff;

	id =6;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[32] = id;
	bufferDataTx[33] = position_L;
	bufferDataTx[34] = position_H;
	bufferDataTx[35] = speed_L;
	bufferDataTx[36] = speed_H;
	//######## SERVO 20 ##################//
	position_H = outServo[6]>>8;
	position_L = outServo[6]&0xff;

	id =7;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[37] = id;
	bufferDataTx[38] = position_L;
	bufferDataTx[39] = position_H;
	bufferDataTx[40] = speed_L;
	bufferDataTx[41] = speed_H;
	//######## SERVO 21 ##################//
	position_H = outServo[7]>>8;
	position_L = outServo[7]&0xff;

	id =8;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[42] = id;
	bufferDataTx[43] = position_L;
	bufferDataTx[44] = position_H;
	bufferDataTx[45] = speed_L;
	bufferDataTx[46] = speed_H;
	//######## SERVO 22 ##################//
	position_H = outServo[8]>>8;
	position_L = outServo[8]&0xff;

	id =9;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[47] = id;
	bufferDataTx[48] = position_L;
	bufferDataTx[49] = position_H;
	bufferDataTx[50] = speed_L;
	bufferDataTx[51] = speed_H;
	//######## SERVO 30 ##################//

	position_H = outServo[9]>>8;
	position_L = outServo[9]&0xff;

	id =10;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[52] = id;
	bufferDataTx[53] = position_L;
	bufferDataTx[54] = position_H;
	bufferDataTx[55] = speed_L;
	bufferDataTx[56] = speed_H;
	//######## SERVO 31 ##################//
	position_H = outServo[10]>>8;
	position_L = outServo[10]&0xff;

	id =11;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[57] = id;
	bufferDataTx[58] = position_L;
	bufferDataTx[59] = position_H;
	bufferDataTx[60] = speed_L;
	bufferDataTx[61] = speed_H;
	//######## SERVO 32 ##################//
	position_H = outServo[11]>>8;
	position_L = outServo[11]&0xff;

	id =12;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[62] = id;
	bufferDataTx[63] = position_L;
	bufferDataTx[64] = position_H;
	bufferDataTx[65] = speed_L;
	bufferDataTx[66] = speed_H;

	position_H = outServo[12]>>8;
	position_L = outServo[12]&0xff;

	id =13;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[67] = id;
	bufferDataTx[68] = position_L;
	bufferDataTx[69] = position_H;
	bufferDataTx[70] = speed_L;
	bufferDataTx[71] = speed_H;

	position_H = outServo[13]>>8;
	position_L = outServo[13]&0xff;

	id =14;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[72] = id;
	bufferDataTx[73] = position_L;
	bufferDataTx[74] = position_H;
	bufferDataTx[75] = speed_L;
	bufferDataTx[76] = speed_H;

	position_H = outServo[14]>>8;
	position_L = outServo[14]&0xff;

	id =15;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[77] = id;
	bufferDataTx[78] = position_L;
	bufferDataTx[79] = position_H;
	bufferDataTx[80] = speed_L;
	bufferDataTx[81] = speed_H;

	position_H = outServo[15]>>8;
	position_L = outServo[15]&0xff;

	id =16;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[82] = id;
	bufferDataTx[83] = position_L;
	bufferDataTx[84] = position_H;
	bufferDataTx[85] = speed_L;
	bufferDataTx[86] = speed_H;

	position_H = outServo[16]>>8;
	position_L = outServo[16]&0xff;

	id =17;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[87] = id;
	bufferDataTx[88] = position_L;
	bufferDataTx[89] = position_H;
	bufferDataTx[90] = speed_L;
	bufferDataTx[91] = speed_H;

	position_H = outServo[17]>>8;
	position_L = outServo[17]&0xff;

	id =18;
	Checksum += position_L +position_H +speed_L +speed_H + id;
	bufferDataTx[92] = id;
	bufferDataTx[93] = position_L;
	bufferDataTx[94] = position_H;
	bufferDataTx[95] = speed_L;
	bufferDataTx[96] = speed_H;

	//############# checksum ##############//
	Checksum =(~Checksum) & 0xFF; //only use lower bytes hal.49
	bufferDataTx[97] = Checksum;

	kirimData(97);
}
void kirimData(char jmlhData)
{
	if(jumlahData == 0)
	{
		jumlahData = jmlhData;
		USART_ITConfig(USART2, USART_IT_TXE, ENABLE);
	}
}
void USART2_IRQHandler(void)
{
	GPIO_SetBits(GPIOC, GPIO_Pin_1);
	static int dataKe;
	if (USART_GetITStatus(USART2, USART_IT_TXE) != RESET)
	{
		USART_SendData(USART2,bufferDataTx[dataKe]);
		dataKe++;
		if(dataKe == jumlahData + 1)
		{
			jumlahData = 0;
			dataKe = 0;
			USART_ITConfig(USART2, USART_IT_TXE, DISABLE);
		}
	}
	GPIO_ResetBits(GPIOC, GPIO_Pin_1);
}

void Dynamixel_Drive_Interrupt_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	TIM_TimeBaseStructure.TIM_Prescaler = 83; //f per count= 84.000.000/(83+1)=1000000Hz = 10us (0,000001 s)
	//335;  //f per count= 84000000/(335+1)=250000Hz = 0.004ms
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 39999;
	// 0,00001 s x 50 = 0.0005 s -> 1 Hz
//	TIM_TimeBaseStructure.TIM_Period = 500;// 0,1 ms x 500 = 50 ms -> 0,5 s -> 2 Hz
			//200; //0,1 X 200 = 20 ms -> 0,2 s -> 5 Hz
	//10000; //0,1ms x 10000 = 1 s
	//0.004*125000=500ms jadi sampling adc setiap 500ms //MAX 65535
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM6, ENABLE); //default di off dulu
//	TIM_ITConfig(TIM5, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);

    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = TIM6_DAC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}


void TIM6_DAC_IRQHandler()
{
	if(GERAK==0)
	{
		static_syncwrite();

		outServo[0]=((150-90+move[0])*1024)/300;
		outServo[1]=((150+move[1])*1024)/300;		//FRONT LEFT
		outServo[2]=((150+move[2])*1024)/300;

		outServo[12]=((150+90-move[12])*1024)/300;
		outServo[13]=((150-move[13])*1024)/300;		//MIDDLE RIGHT
		outServo[14]=((150-move[14])*1024)/300;

		outServo[6]=((150-90+move[6])*1024)/300;
		outServo[7]=((150+move[7])*1024)/300;		//REAR LEFT
		outServo[8]=((150+move[8])*1024)/300;

		outServo[9]=((150+90-move[9])*1024)/300;
		outServo[10]=((150-move[10])*1024)/300; 	//FRONT RIGHT
		outServo[11]=((150-move[11])*1024)/300;

		outServo[3]=((150-90+move[3])*1024)/300;
		outServo[4]=((150+move[4])*1024)/300;		//MIDDLE LEFT
		outServo[5]=((150+move[5])*1024)/300;

		outServo[15]=((150+90-move[15])*1024)/300;
		outServo[16]=((150-move[16])*1024)/300;		//REAR RIGHT
		outServo[17]=((150-move[17])*1024)/300;

	}
	else
	{
		syncwrite();
	}
//	gerak(unsigned int leg_position, unsigned int ThetaCoxa, int ThetaFemur, int ThetaTibia);

	DynamixelDrive(0);

TIM_ClearFlag(TIM6,TIM_FLAG_Update);
}

void MOV_LEG(
			 	 int FL_COXA,int FL_FEMUR,int FL_TIBIA,
			 	 int MR_COXA,int MR_FEMUR,int MR_TIBIA,
			 	 int RL_COXA,int RL_FEMUR,int RL_TIBIA,

			 	 int FR_COXA,int FR_FEMUR,int FR_TIBIA,
			 	 int ML_COXA,int ML_FEMUR,int ML_TIBIA,
			 	 int RR_COXA,int RR_FEMUR,int RR_TIBIA
			 )
{
	move[0]=FL_COXA;
	move[1]=FL_FEMUR;	//FRONT LEFT
	move[2]=FL_TIBIA;

	move[12]=MR_COXA;
	move[13]=MR_FEMUR;	//MIDDLE RIGHT
	move[14]=MR_TIBIA;

	move[6]=RL_COXA;
	move[7]=RL_FEMUR;	//REAR LEFT
	move[8]=RL_TIBIA;

	move[9]=FR_COXA;
	move[10]=FR_FEMUR;	//FRONT RIGHT
	move[11]=FR_TIBIA;

	move[3]=ML_COXA;
	move[4]=ML_FEMUR;	//MIDDLE LEFT
	move[5]=ML_TIBIA;

	move[15]=RR_COXA;
	move[16]=RR_FEMUR;	//REAR RIGHT
	move[17]=RR_TIBIA;

	GERAK=1;
	syncwrite();
}

void syncwrite(void)
{
	outServo[0]=((150-90+move[0])*1024)/300;
	outServo[1]=((150+move[1])*1024)/300;		//FRONT LEFT
	outServo[2]=((150+move[2])*1024)/300;

	outServo[12]=((150+90-move[12])*1024)/300;
	outServo[13]=((150-move[13])*1024)/300;		//MIDDLE RIGHT
	outServo[14]=((150-move[14])*1024)/300;

	outServo[6]=((150-90+move[6])*1024)/300;
	outServo[7]=((150+move[7])*1024)/300;		//REAR LEFT
	outServo[8]=((150+move[8])*1024)/300;

	outServo[9]=((150+90-move[9])*1024)/300;
	outServo[10]=((150-move[10])*1024)/300; 	//FRONT RIGHT
	outServo[11]=((150-move[11])*1024)/300;

	outServo[3]=((150-90+move[3])*1024)/300;
	outServo[4]=((150+move[4])*1024)/300;		//MIDDLE LEFT
	outServo[5]=((150+move[5])*1024)/300;

	outServo[15]=((150+90-move[15])*1024)/300;
	outServo[16]=((150-move[16])*1024)/300;		//REAR RIGHT
	outServo[17]=((150-move[17])*1024)/300;

}

void static_syncwrite(void)
{
	move[0]=SUDUT_STATIC[9];
	move[1]=SUDUT_STATIC[10];	//FRONT LEFT
	move[2]=SUDUT_STATIC[11];

	move[12]=SUDUT_STATIC[12];
	move[13]=SUDUT_STATIC[13];	//MIDDLE RIGHT
	move[14]=SUDUT_STATIC[14];

	move[6]=SUDUT_STATIC[15];
	move[7]=SUDUT_STATIC[16];	//REAR LEFT
	move[8]=SUDUT_STATIC[17];

	move[9]=SUDUT_STATIC[0];
	move[10]=SUDUT_STATIC[1];	//FRONT RIGHT
	move[11]=SUDUT_STATIC[2];

	move[3]=SUDUT_STATIC[3];
	move[4]=SUDUT_STATIC[4];	//MIDDLE LEFT
	move[5]=SUDUT_STATIC[5];

	move[15]=SUDUT_STATIC[6];
	move[16]=SUDUT_STATIC[7];	//REAR RIGHT
	move[17]=SUDUT_STATIC[8];

}

void Gerak(int delay)
{
	//STEP 2
						MOV_LEG(
									 SUDUT_STATIC[9],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT,
									 SUDUT_STATIC[12],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT,
									 SUDUT_STATIC[15],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT,

									 SUDUT_STATIC[0],SUDUT_STATIC[1],SUDUT_STATIC[2],
									 SUDUT_STATIC[3],SUDUT_STATIC[4],SUDUT_STATIC[5],
									 SUDUT_STATIC[6],SUDUT_STATIC[7],SUDUT_STATIC[8]
							   );
	//STEP 3
						delay_ms(delay);
						MOV_LEG(
									SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2],
									SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1],
									SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0],

									SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R3[0],
									SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1],
									SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R3[2]
							   );
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2],
									SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1],
									SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0],

									SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R2[0],
									SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1],
									SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7],SUDUT_STATIC[8]-IKFWD_TIBIA_R2[2]
							   );
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2],
									SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1],
									SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0],

									SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1],SUDUT_STATIC[2]+IKFWD_TIBIA_R1[0],
									SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1],
									SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]-7,SUDUT_STATIC[8]-IKFWD_TIBIA_R1[2]
							   );
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2],
									SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1],
									SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0],

									SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]+IKFWD_TIBIA_R[0],
									SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]-7,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1],
									SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]-10,SUDUT_STATIC[8]-IKFWD_TIBIA_R[2]
							   );
						delay_ms(delay);
	//STEP 4
						MOV_LEG(
									SUDUT_STATIC[9]+IKFWD_COXA_L[0],SUDUT_STATIC[10]-10,SUDUT_STATIC[11]-IKFWD_TIBIA_L[2],
									SUDUT_STATIC[12]+IKFWD_COXA_R[1],SUDUT_STATIC[13]-7,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1],
									SUDUT_STATIC[15]+IKFWD_COXA_L[2],SUDUT_STATIC[16]-7,SUDUT_STATIC[17]+IKFWD_TIBIA_L[0],

									SUDUT_STATIC[0]-IKFWD_COXA_R[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT,
									SUDUT_STATIC[3]-IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT,
									SUDUT_STATIC[6]-IKFWD_COXA_R[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT
							   );
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]+IKFWD_COXA_L1[0],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]-IKFWD_TIBIA_L1[2],
									SUDUT_STATIC[12]+IKFWD_COXA_R1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1],
									SUDUT_STATIC[15]+IKFWD_COXA_L1[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L1[0],

									SUDUT_STATIC[0]-IKFWD_COXA_R1[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT,
									SUDUT_STATIC[3]-IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT,
									SUDUT_STATIC[6]-IKFWD_COXA_R1[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT
							   );
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]+IKFWD_COXA_L2[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L2[2],
									SUDUT_STATIC[12]+IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1],
									SUDUT_STATIC[15]+IKFWD_COXA_L2[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L2[0],

									SUDUT_STATIC[0]-IKFWD_COXA_R2[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT,
									SUDUT_STATIC[3]-IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT,
									SUDUT_STATIC[6]-IKFWD_COXA_R2[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT
							   );
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]+IKFWD_COXA_L3[0],SUDUT_STATIC[10],SUDUT_STATIC[11]-IKFWD_TIBIA_L3[2],
									SUDUT_STATIC[12]+IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1],
									SUDUT_STATIC[15]+IKFWD_COXA_L3[2],SUDUT_STATIC[16],SUDUT_STATIC[17]+IKFWD_TIBIA_L3[0],

									SUDUT_STATIC[0]-IKFWD_COXA_R3[2],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT,
									SUDUT_STATIC[3]-IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT,
									SUDUT_STATIC[6]-IKFWD_COXA_R3[0],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT
							   );
						delay_ms(delay);
	//STEP 5
						MOV_LEG(
									SUDUT_STATIC[9],SUDUT_STATIC[10],SUDUT_STATIC[11],
									SUDUT_STATIC[12],SUDUT_STATIC[13],SUDUT_STATIC[14],
									SUDUT_STATIC[15],SUDUT_STATIC[16],SUDUT_STATIC[17],

									SUDUT_STATIC[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]+SUDUT_ANGKAT,
									SUDUT_STATIC[3],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]+SUDUT_ANGKAT,
									SUDUT_STATIC[6],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+SUDUT_ANGKAT
							   );
						delay_ms(delay);
	//STEP 6
						MOV_LEG(
									SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L3[0],
									SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R3[1],
									SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L3[2],

									SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2],
									SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1],
									SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]
							   );
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L2[0],
									SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13],SUDUT_STATIC[14]-IKFWD_TIBIA_R2[1],
									SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16],SUDUT_STATIC[17]-IKFWD_TIBIA_L2[2],

									SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2],
									SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1],
									SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]
							   );
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10],SUDUT_STATIC[11]+IKFWD_TIBIA_L1[0],
									SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]-3,SUDUT_STATIC[14]-IKFWD_TIBIA_R1[1],
									SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]-7,SUDUT_STATIC[17]-IKFWD_TIBIA_L1[2],

									SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2],
									SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1],
									SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]
							   );
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]-7,SUDUT_STATIC[11]+IKFWD_TIBIA_L[0],
									SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]-7,SUDUT_STATIC[14]-IKFWD_TIBIA_R[1],
									SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]-10,SUDUT_STATIC[17]-IKFWD_TIBIA_L[2],

									SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]+SUDUT_ANGKAT,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2],
									SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]+SUDUT_ANGKAT,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1],
									SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]+SUDUT_ANGKAT,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]
							   );
						delay_ms(delay);

	//STEP 1
						MOV_LEG(
									SUDUT_STATIC[9]-IKFWD_COXA_L[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT,
									SUDUT_STATIC[12]-IKFWD_COXA_R[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT,
									SUDUT_STATIC[15]-IKFWD_COXA_L[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT,

									SUDUT_STATIC[0]+IKFWD_COXA_R[0],SUDUT_STATIC[1]-10,SUDUT_STATIC[2]-IKFWD_TIBIA_R[2],
									SUDUT_STATIC[3]+IKFWD_COXA_L[1],SUDUT_STATIC[4]-7,SUDUT_STATIC[5]-IKFWD_TIBIA_L[1],
									SUDUT_STATIC[6]+IKFWD_COXA_R[2],SUDUT_STATIC[7]-7,SUDUT_STATIC[8]+IKFWD_TIBIA_R[0]
								);
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]-IKFWD_COXA_L1[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT,
									SUDUT_STATIC[12]-IKFWD_COXA_R1[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT,
									SUDUT_STATIC[15]-IKFWD_COXA_L1[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT,

									SUDUT_STATIC[0]+IKFWD_COXA_R1[0],SUDUT_STATIC[1]-7,SUDUT_STATIC[2]-IKFWD_TIBIA_R1[2],
									SUDUT_STATIC[3]+IKFWD_COXA_L1[1],SUDUT_STATIC[4]-3,SUDUT_STATIC[5]-IKFWD_TIBIA_L1[1],
									SUDUT_STATIC[6]+IKFWD_COXA_R1[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R1[0]
								);
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]-IKFWD_COXA_L2[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT,
									SUDUT_STATIC[12]-IKFWD_COXA_R2[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT,
									SUDUT_STATIC[15]-IKFWD_COXA_L2[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT,

									SUDUT_STATIC[0]+IKFWD_COXA_R2[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R2[2],
									SUDUT_STATIC[3]+IKFWD_COXA_L2[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L2[1],
									SUDUT_STATIC[6]+IKFWD_COXA_R2[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R2[0]
								);
						delay_ms(delay);

						MOV_LEG(
									SUDUT_STATIC[9]-IKFWD_COXA_L3[2],SUDUT_STATIC[10]+SUDUT_ANGKAT,SUDUT_STATIC[11]+SUDUT_ANGKAT,
									SUDUT_STATIC[12]-IKFWD_COXA_R3[1],SUDUT_STATIC[13]+SUDUT_ANGKAT,SUDUT_STATIC[14]+SUDUT_ANGKAT,
									SUDUT_STATIC[15]-IKFWD_COXA_L3[0],SUDUT_STATIC[16]+SUDUT_ANGKAT,SUDUT_STATIC[17]+SUDUT_ANGKAT,

									SUDUT_STATIC[0]+IKFWD_COXA_R3[0],SUDUT_STATIC[1],SUDUT_STATIC[2]-IKFWD_TIBIA_R3[2],
									SUDUT_STATIC[3]+IKFWD_COXA_L3[1],SUDUT_STATIC[4],SUDUT_STATIC[5]-IKFWD_TIBIA_L3[1],
									SUDUT_STATIC[6]+IKFWD_COXA_R3[2],SUDUT_STATIC[7],SUDUT_STATIC[8]+IKFWD_TIBIA_R3[0]
								);
						delay_ms(delay);

}

/*
 * Comparison between 3DOF leg vs 2DOF leg
 */
void Dynamx_Demo(void)
{
//		//DEPAN ANGKAT
//		Dyna_Actuate(FRONT_RIGHT_DX_COXA,150,500,2600);
//		Dyna_Actuate(FRONT_RIGHT_DX_FEMUR,150,500,2600);
//		Dyna_Actuate(FRONT_RIGHT_DX_TIBIA,150,500,2600);
//
//		Dyna_Actuate(FRONT_LEFT_DX_COXA,150,500,2600);
//		Dyna_Actuate(FRONT_LEFT_DX_FEMUR,150,500,2600);
//		Dyna_Actuate(FRONT_LEFT_DX_TIBIA,150,500,2600);
//
//		Dyna_Actuate(MIDDLE_RIGHT_DX_COXA,150,500,2600);
//		Dyna_Actuate(MIDDLE_RIGHT_DX_FEMUR,150,500,2600);
//		Dyna_Actuate(MIDDLE_RIGHT_DX_TIBIA,150,500,2600);
//
//		Dyna_Actuate(MIDDLE_LEFT_DX_COXA,150,500,2600);
//		Dyna_Actuate(MIDDLE_LEFT_DX_FEMUR,150,500,2600);
//		Dyna_Actuate(MIDDLE_LEFT_DX_TIBIA,150,500,2600);
//
//		Dyna_Actuate(REAR_RIGHT_DX_COXA,150,500,2600);
//		Dyna_Actuate(REAR_RIGHT_DX_FEMUR,150,500,2600);
//		Dyna_Actuate(REAR_RIGHT_DX_TIBIA,150,500,2600);
//
//		Dyna_Actuate(REAR_LEFT_DX_COXA,150,500,2600);
//		Dyna_Actuate(REAR_LEFT_DX_FEMUR,150,500,2600);
//		Dyna_Actuate(REAR_LEFT_DX_TIBIA,150,500,2600);
//		Dyna_Actuate(FRONT_LEFT_COXA,175,500);
//		Dyna_Actuate(FRONT_LEFT_FEMUR,120,500);
//
//		//DEPAN MENAPAK
//		Dyna_Actuate(FRONT_RIGHT_DX_COXA,175,500,2600);
//		Dyna_Actuate(FRONT_RIGHT_DX_FEMUR,175,500,2600);
//		Dyna_Actuate(FRONT_RIGHT_DX_TIBIA,175,500,2600);
//
//		Dyna_Actuate(FRONT_LEFT_COXA,175,500);
//		Dyna_Actuate(FRONT_LEFT_FEMUR,140,500);
//
//		//BELAKANG MENAPAK
//		Dyna_Actuate(FRONT_RIGHT_DX_COXA,125,500,2600);
//		Dyna_Actuate(FRONT_RIGHT_DX_FEMUR,125,500,2600);
//		Dyna_Actuate(FRONT_RIGHT_DX_TIBIA,175,500,2600);
//
//		Dyna_Actuate(FRONT_LEFT_COXA,125,500);
//		Dyna_Actuate(FRONT_LEFT_FEMUR,140,500);
//
//		//DEPAN ANGKAT
//		Dyna_Actuate(FRONT_RIGHT_COXA,125,500);
//		Dyna_Actuate(FRONT_RIGHT_FEMUR,200,500);
//		Dyna_Actuate(FRONT_RIGHT_TIBIA,190,500);
	
	
	//DEFAULT
	//		Dyna_Actuate(FRONT_LEFT_COXA,125,500);
	//		Dyna_Actuate(FRONT_LEFT_FEMUR,120,500);
}
