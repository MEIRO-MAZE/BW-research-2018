/*==============================================================================================
								  PROJECT BW Ver.1.0
							BW HEXAPOD COMMAND LIBRARY
==============================================================================================*/

//USER DEFINED LIBRARIES
#include "bw_hexapod_cmd.h"

/*****************************************************
Project   : BW* Servo Controller / Hexapod Gait Generator
Version   : 2.0
Year      : 2015
Date      :
Author    : Ryan
University: University of Brawijaya
Department: Electrical Engineering Department, Engineering Faculty
Division  : Legged Fire-Fighting Division (KRPAI)
Comments  : *Dreams/aspirations, in Japanese language

Board Type: STM32F4 Discovery Board
Chip      : STM32F407VG
*****************************************************/

#include "main.h"

//HEXAPOD GAIT MODE PARAMETER
const int STATIC_LOW_CLEARANCE  = 0;
const int STATIC_MED_CLEARANCE  = 1;
const int STATIC_HIGH_CLEARANCE = 2;
const int SEARCH_FIRE           = 3;
const int FORWARD 				= 4;
const int BACKWARD 				= 5;
const int ROTATE_RIGHT 			= 6;
const int ROTATE_LEFT 			= 7;
const int CURVE_RIGHT 			= 8;
const int CURVE_LEFT 			= 9;
const int ASKEW_RIGHT 			= 10;
const int ASKEW_LEFT 			= 11;
const int FWD_RIPPLE			= 12;
const int FWD_WAVE				= 13;

uint32_t CCR1_Val;
uint32_t CCR2_Val;
uint32_t CCR3_Val;


void BW_Servo_Initialization(void)
{
	Servo_GPIO_Init();
	Servo_Interrupt_Init();
	Servo_TIM_Init();				//TIM3
	Servo_Interrupt_Init2();
	Servo_TIM_Init2();				//TIM2
}

void Servo_TIM_Init(void)
{
	 //PrescalerValue = (uint32_t) ((SystemCoreClock / 2) / 9830250) - 1;

	 /* Time base configuration */
	 TIM_TimeBaseStructure.TIM_Period = 65535;//10000;//65535; /*nilai mak utk timer=16bit*/
	 TIM_TimeBaseStructure.TIM_Prescaler = 21;
	 TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	 TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	 /* Prescaler configuration */
	 //TIM_PrescalerConfig(TIM3, PrescalerValue, TIM_PSCReloadMode_Immediate);
}

void Servo_TIM_Init2(void)
{
	 //PrescalerValue = (uint32_t) ((SystemCoreClock / 2) / 9830250) - 1;

	 /* Time base configuration */
	 TIM_TimeBaseStructure.TIM_Period = 65535;//10000;//65535; /*nilai mak utk timer=16bit*/
	 TIM_TimeBaseStructure.TIM_Prescaler = 21;
	 TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	 TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	 /* Prescaler configuration */
	 //TIM_PrescalerConfig(TIM3, PrescalerValue, TIM_PSCReloadMode_Immediate);
}

void Servo_Interrupt_Init(void)
{
//	 NVIC_InitTypeDef NVIC_InitStructure;
//
//	 /* TIM3 clock enable */
//	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
//	 /* Enable the TIM3 gloabal Interrupt */
//	 NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
//	 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	 NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	 NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	 NVIC_Init(&NVIC_InitStructure);
//
//	 /* Output Compare Timing Mode configuration: Channel1 */
//	 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
//	 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	 TIM_OCInitStructure.TIM_Pulse = TIM3 -> CCR1;
//	 TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//	 TIM_OC1Init(TIM3, &TIM_OCInitStructure);
//
//	 TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Disable);
//
//	 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	 TIM_OCInitStructure.TIM_Pulse = TIM3 -> CCR2;
//	 TIM_OC2Init(TIM3, &TIM_OCInitStructure);
//
//	 TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Disable);
//
//	 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	 TIM_OCInitStructure.TIM_Pulse = TIM3 -> CCR3;
//	 TIM_OC3Init(TIM3, &TIM_OCInitStructure);
//
//	 TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Disable);
//
//	 //TIM_ClearOC1Ref(TIM3, TIM_OCClear_Enable);
//	 //TIM_ClearOC2Ref(TIM3, TIM_OCClear_Enable);
//	 //TIM_ForcedOC1Config(TIM3, TIM_ForcedAction_Active);
//	 /* TIM Interrupts enable */
//	 TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
//	 TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
//	 TIM_ITConfig(TIM3, TIM_IT_CC2, ENABLE);
//	 TIM_ITConfig(TIM3, TIM_IT_CC3, ENABLE);
//
//	 /* TIM3 enable counter */
//	 TIM_Cmd(TIM3, ENABLE);
}

void Servo_Interrupt_Init2(void)
{
//	 NVIC_InitTypeDef NVIC_InitStructure;
//
//	 /* TIM3 clock enable */
//	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//	 /* Enable the TIM3 gloabal Interrupt */
//	 NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
//	 NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//	 NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//	 NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	 NVIC_Init(&NVIC_InitStructure);
//
//	 /* Output Compare Timing Mode configuration: Channel1 */
//	 TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Timing;
//	 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	 TIM_OCInitStructure.TIM_Pulse = TIM2 -> CCR1;
//	 TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//	 TIM_OC1Init(TIM2, &TIM_OCInitStructure);
//
//	 TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Disable);
//
//	 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	 TIM_OCInitStructure.TIM_Pulse = TIM2 -> CCR2;
//	 TIM_OC2Init(TIM2, &TIM_OCInitStructure);
//
//	 TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Disable);
//
//	 TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	 TIM_OCInitStructure.TIM_Pulse = TIM2 -> CCR3;
//	 TIM_OC3Init(TIM2, &TIM_OCInitStructure);
//
//	 TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Disable);
//
//	 //TIM_ClearOC1Ref(TIM3, TIM_OCClear_Enable);
//	 //TIM_ClearOC2Ref(TIM3, TIM_OCClear_Enable);
//	 //TIM_ForcedOC1Config(TIM3, TIM_ForcedAction_Active);
//	 /* TIM Interrupts enable */
//	 TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
//	 TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE);
//	 TIM_ITConfig(TIM2, TIM_IT_CC2, ENABLE);
//	 TIM_ITConfig(TIM2, TIM_IT_CC3, ENABLE);
//
//	 /* TIM3 enable counter */
//	 TIM_Cmd(TIM2, ENABLE);
}

/* func      : 	void Servo_GPIO_Init(void)
 * brief     : 	BW Hexapod Servo Initialization
 * param     :	N/A
 * retval    : 	N/A
 * Ver       : 2.0
 * written By: Ryan (Monday, January 29th 2016)
 * Revised By: Ver.2.0 By Ryan (Monday, February 22nd 2016)
 */
void Servo_GPIO_Init(void)
{
	/*
	 * YUME 2.16 NEW SERVO CONFIGURATION
	 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_3| //Front Left
								  GPIO_Pin_7; //Middle Left
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4| //Middle Left
								  GPIO_Pin_14|GPIO_Pin_13|GPIO_Pin_12| //Front Right
								  GPIO_Pin_2|GPIO_Pin_1|GPIO_Pin_0; //Rear Right
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4|GPIO_Pin_6|  //Rear Left
								  GPIO_Pin_9|GPIO_Pin_8|GPIO_Pin_7; //Middle Right
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

}
/*
void TIM3_IRQHandler(void)
{

	 if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
	  {
		 if(++index_servo>=8) {index_servo=0;}

		 TIM_ClearITPendingBit(TIM3, TIM_IT_Update);

		 switch (index_servo)
		 {

		 	 	 case 0:
		 		        GPIO_SetBits(ch_0);
		 		 	    GPIO_SetBits(ch_6);
		 		 	    GPIO_SetBits(ch_12);
		 		 	    break;
		 		 case 1:
		 	 	    	GPIO_SetBits(ch_1);
		 	 	    	GPIO_SetBits(ch_7);
		 	 	    	GPIO_SetBits(ch_13);
		 	 	    	break;
		 		 case 2:
		 	 	    	GPIO_SetBits(ch_2);
		 	 	    	GPIO_SetBits(ch_8);
		 	 	    	GPIO_SetBits(ch_14);
		 	 	    	break;
		 		 case 3:
		 	 	    	GPIO_SetBits(ch_3);
		 	 	    	GPIO_SetBits(ch_9);
		 	 	    	GPIO_SetBits(ch_15);
		 	 	    	break;
		 		 case 4:
		 	 	    	GPIO_SetBits(ch_4);
		 	 	    	GPIO_SetBits(ch_10);
		 	 	    	GPIO_SetBits(ch_16);
		 	 	    	break;
		 		 case 5:
		 	    		GPIO_SetBits(ch_5);
		 	    		GPIO_SetBits(ch_11);
		 	    		GPIO_SetBits(ch_17);
		 	    		break;
		 }
		 if(index_servo>5) {index_bantu=0;}
		 else if(index_servo<=5) {index_bantu=index_servo;}
		 TIM3 -> CCR1=sudut[index_bantu];
		 TIM3 -> CCR2=sudut[index_bantu+6];
		 TIM3 -> CCR3=sudut[index_bantu+12];

		 //index_servo++;
		 //if(index_servo>=5) {index_servo=0;}
	  }
	 else if (TIM_GetITStatus(TIM3, TIM_IT_CC1) == SET)
							{  TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);
		 	 	 	 	 	 	 switch (index_servo)
		 	 	 	 	 	 	 {
		 	 	 	 	 	 case 0: GPIO_ResetBits(ch_0);break;
		 	 	 	 	 	 case 1: GPIO_ResetBits(ch_1);break;
		 	 	 	 	 	 case 2: GPIO_ResetBits(ch_2);break;
		 	 	 	 	 	 case 3: GPIO_ResetBits(ch_3);break;
		 	 	 	 	 	 case 4: GPIO_ResetBits(ch_4);break;
		 	 	 	 	 	 case 5: GPIO_ResetBits(ch_5);break;
		 	 	 	 	 	 	 }
							}
	 else if (TIM_GetITStatus(TIM3, TIM_IT_CC2) == SET)
							{  TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);
			 	 	 	 	 	 switch (index_servo)
			 	 	 	 	 	 {
			 	 	 	 	 case 0: GPIO_ResetBits(ch_6);break;
			 	 	 	 	 case 1: GPIO_ResetBits(ch_7);break;
			 	 	 	 	 case 2: GPIO_ResetBits(ch_8);break;
			 	 	 	 	 case 3: GPIO_ResetBits(ch_9);break;
			 	 	 	 	 case 4: GPIO_ResetBits(ch_10);break;
			 	 	 	 	 case 5: GPIO_ResetBits(ch_11);break;
			 	 	 	 	 	 }
							}
	 else if (TIM_GetITStatus(TIM3, TIM_IT_CC3) == SET)
	 						{  TIM_ClearITPendingBit(TIM3, TIM_IT_CC3);
	 			 	 	 	 	 switch (index_servo)
	 			 	 	 	 	 {
	 			 	 	 	 case 0:  GPIO_ResetBits(ch_12);break;
	 			 	 	 	 case 1:  GPIO_ResetBits(ch_13);break;
	 			 	 	 	 case 2:  GPIO_ResetBits(ch_14);break;
	 			 	 	 	 case 3:  GPIO_ResetBits(ch_15);break;
	 			 	 	 	 case 4:  GPIO_ResetBits(ch_16);break;
	 			 	 	 	 case 5:  GPIO_ResetBits(ch_17);break;
	 			 	 	 	 	 }
	 						}
}
*/

//void TIM3_IRQHandler(void)
//{
//	static int temp;
//	 if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
//	  {
//		 if(++index_servo3>=3) {index_servo3=0;}
//
//		 TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
//
//		 switch (index_servo3)
//		 {
//		 	 	 case 0:
//		 		        GPIO_SetBits(ch_0);
//		 		 	    GPIO_SetBits(ch_6);
//		 		 	    GPIO_SetBits(ch_12);
//		 		 	    break;
//		 		 case 1:
//		 	 	    	GPIO_SetBits(ch_1);
//		 	 	    	GPIO_SetBits(ch_7);
//		 	 	    	GPIO_SetBits(ch_13);
//		 	 	    	break;
//		 		 case 2:
//		 	 	    	GPIO_SetBits(ch_2);
//		 	 	    	GPIO_SetBits(ch_8);
//		 	 	    	GPIO_SetBits(ch_14);
//		 	 	    	break;
//
//		 }
//		 if(index_servo3>2) {temp=0;}
//		 else if(index_servo3<=2) {temp=index_servo3;}
//		 TIM3 -> CCR1=sudut[temp];
//		 TIM3 -> CCR2=sudut[temp+6];
//		 TIM3 -> CCR3=sudut[temp+12];
//
////		 index_servo3++;
//		 //if(index_servo>=5) {index_servo=0;}
//	  }
//	 else if (TIM_GetITStatus(TIM3, TIM_IT_CC1) == SET)
//							{  TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);
//		 	 	 	 	 	 	 switch (index_servo3)
//		 	 	 	 	 	 	 {
//		 	 	 	 	 	 case 0: GPIO_ResetBits(ch_0);break;
//		 	 	 	 	 	 case 1: GPIO_ResetBits(ch_1);break;
//		 	 	 	 	 	 case 2: GPIO_ResetBits(ch_2);break;
//		 	 	 	 	 	 	 }
//							}
//	 else if (TIM_GetITStatus(TIM3, TIM_IT_CC2) == SET)
//							{  TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);
//			 	 	 	 	 	 switch (index_servo3)
//			 	 	 	 	 	 {
//			 	 	 	 	 case 0: GPIO_ResetBits(ch_6);break;
//			 	 	 	 	 case 1: GPIO_ResetBits(ch_7);break;
//			 	 	 	 	 case 2: GPIO_ResetBits(ch_8);break;
//			 	 	 	 	 	 }
//							}
//	 else if (TIM_GetITStatus(TIM3, TIM_IT_CC3) == SET)
//	 						{  TIM_ClearITPendingBit(TIM3, TIM_IT_CC3);
//	 			 	 	 	 	 switch (index_servo3)
//	 			 	 	 	 	 {
//	 			 	 	 	 case 0:  GPIO_ResetBits(ch_12);break;
//	 			 	 	 	 case 1:  GPIO_ResetBits(ch_13);break;
//	 			 	 	 	 case 2:  GPIO_ResetBits(ch_14);break;
//	 			 	 	 	 	 }
//	 						}
//}
//
//void TIM2_IRQHandler(void)
//{
//	static int temp2;
//	 if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
//	  {
//		 if(++index_servo2>=3) {index_servo2=0;}
//
//		 TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//
//		 switch (index_servo2)
//		 {
//		 		case 0:
//		 				GPIO_SetBits(ch_3);
//		 				GPIO_SetBits(ch_9);
//		 				GPIO_SetBits(ch_15);
//		 				break;
//		 		case 1:
//		 				GPIO_SetBits(ch_4);
//		 				GPIO_SetBits(ch_10);
//		 				GPIO_SetBits(ch_16);
//		 				break;
//		 		case 2:
//		 				GPIO_SetBits(ch_5);
//		 				GPIO_SetBits(ch_11);
//		 				GPIO_SetBits(ch_17);
//		 				break;
//		 }
//		 if(index_servo2>2) {temp2=3;}
//		 else if(index_servo2<=2) {temp2=index_servo2+3;}
//		 TIM2 -> CCR1=sudut[temp2];
//		 TIM2 -> CCR2=sudut[temp2+6];
//		 TIM2 -> CCR3=sudut[temp2+12];
//
////		 index_servo2++;
//		 //if(index_servo>=5) {index_servo=0;}
//	  }
//	 else if (TIM_GetITStatus(TIM2, TIM_IT_CC1) == SET)
//							{  TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);
//		 	 	 	 	 	 	 switch (index_servo2)
//		 	 	 	 	 	 	 {
//		 	 	 	 	 	 case 0: GPIO_ResetBits(ch_3);break;
//		 	 	 	 	 	 case 1: GPIO_ResetBits(ch_4);break;
//		 	 	 	 	 	 case 2: GPIO_ResetBits(ch_5);break;
//		 	 	 	 	 	 	 }
//							}
//	 else if (TIM_GetITStatus(TIM2, TIM_IT_CC2) == SET)
//							{  TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
//			 	 	 	 	 	 switch (index_servo2)
//			 	 	 	 	 	 {
//			 	 	 	 	 case 0: GPIO_ResetBits(ch_9);break;
//			 	 	 	 	 case 1: GPIO_ResetBits(ch_10);break;
//			 	 	 	 	 case 2: GPIO_ResetBits(ch_11);break;
//			 	 	 	 	 	 }
//							}
//	 else if (TIM_GetITStatus(TIM2, TIM_IT_CC3) == SET)
//	 						{  TIM_ClearITPendingBit(TIM2, TIM_IT_CC3);
//	 			 	 	 	 	 switch (index_servo2)
//	 			 	 	 	 	 {
//	 			 	 	 	 case 0:  GPIO_ResetBits(ch_15);break;
//	 			 	 	 	 case 1:  GPIO_ResetBits(ch_16);break;
//	 			 	 	 	 case 2:  GPIO_ResetBits(ch_17);break;
//	 			 	 	 	 	 }
//	 						}
//}

void generate_movement_data(int deflection_angle, int translation, float clearance)
{
	leg=clearance;
//	translation -=1;
    A_body = (float) translation;
    for(i=0;i<6;i++)
	{
	  ww[i] = (int)(alpha[i] - deflection_angle);			//hitung gamma = alpha - psi
	  //printf("%d \n",param->gamma);
	  // hitung beta tiap kaki
	  temp_var  = (float) (A_body * cos(ww[i] / rad2deg));	//temp_var = Ab*cos(gamma)
	  temp_var  = (float) (leg_norm[i] - temp_var);				//temp_var = L2 - temp_var
	  temp_var2 = (float) (A_body * sin(ww[i] / rad2deg));	//temp_var2 = Ab*sin(gamma)
	  temp_var  = (float) (temp_var2 / temp_var);				//var = temp_var2 / temp_var
	  temp_var  = (float) atan(temp_var);						//temp_var = arctan (temp_var)
	  beta[i] = (temp_var*rad2deg);							//beta[i] = temp_var
	  // hitung panjang kaki (L2')
	  temp_var  = (float) sin(ww[i] / rad2deg);				//temp_var = sin(gamma);
	  temp_var  = (float) (A_body * temp_var);					//temp_var = Ab * temp_var;
	  temp_var2 = (float) sin(beta[i] / rad2deg);				//temp_var2 = sin(alpha);
	  temp_var  = (float) (temp_var / temp_var2);				//temp_var  = temp_var/temp_var2
//	  leg_next[i] = temp_var-7;									// leg_next[i] = temp_var
	  leg_next[i] = temp_var;
//	  leg_next[i] = temp_var-7;

	}
    leg_next[0]+=2; //5
    leg_next[3]+=2; //5
    leg_next[1]-=3; //10

    leg_next[4]-=3; //10
    leg_next[2]-=7; //14
    leg_next[5]-=7; //14

}

void inv_kine(char leg_pos,float x,float w, float z)
{
	temp_angle.teta1  = x;

	Lsem = w;//(cos(temp_angle.teta1));
	Lsem -= lj;
	c1 = (la*la) + (lb*lb);
	c2 = 2*la*lb;
	temp_angle.teta3 = acos(((((Lsem*Lsem)+(z*z))-c1)/c2));

	c3=la+(lb*cos(temp_angle.teta3));
	c4=lb*sin(temp_angle.teta3);
	temp_angle.teta2 = atan((((z*c3)-(Lsem*c4))/((Lsem*c3)+(z*c4))));

	temp_angle.teta3 *= rad2deg;
	temp_angle.teta2 *= rad2deg;

	switch(leg_pos)
	{
		case front_left      :   servo_lin_func(0, temp_angle.teta1);
                            	 servo_lin_func(1, temp_angle.teta2);
                            	 servo_lin_func(2, temp_angle.teta3);

                            	 break;
		case front_right     :   servo_lin_func(9,temp_angle.teta1);
                            	 servo_lin_func(10,temp_angle.teta2);
                            	 servo_lin_func(11,temp_angle.teta3);
                            	 break;
		case middle_left     :   servo_lin_func(3,temp_angle.teta1);
                            	 servo_lin_func(4,temp_angle.teta2);
                            	 servo_lin_func(5,temp_angle.teta3);
                            	 break;
		case middle_right    :   servo_lin_func(12,temp_angle.teta1);
								 servo_lin_func(13,temp_angle.teta2);
								 servo_lin_func(14,temp_angle.teta3);
								 break;
		case rear_left       :   servo_lin_func(6,temp_angle.teta1);
                            	 servo_lin_func(7,temp_angle.teta2);
                            	 servo_lin_func(8,temp_angle.teta3);
                            	 break;
		case rear_right      :   servo_lin_func(15,temp_angle.teta1);
                            	 servo_lin_func(16,temp_angle.teta2);
                            	 servo_lin_func(17,temp_angle.teta3);
                            	 break;
	}
}


// A -> konstanta sudut
// B ->
//perhitungan berdasarkan perhitungan 90 derajat == 3000
// patokan awal 90 derajat (sudut nol)
//merubah perhitungan inverse kinematic menjadi pulsa PWM servo
void servo_lin_func(int ch_num,float value)
{
	sudut[ch_num] =(long int)((A_const[ch_num]*(value+correct[ch_num]))+ B_const[ch_num]);
}


/* func : void gait_mode(int menu, int *SPEED)
 * brief: toggle the hexapod gait's mode
 * param: int menu (desc. below),
 * int *SPEED (SLOW=250, MED_SLOW=200, MED=150, FAST=130, ULTRA_FAST=50}
 * HEXAPOD LOCOMOTION'S MODE
 * gait_mode(0/STATIC_LOW_CLEARANCE)    = Static Gait, LOW Clearance /UNUSED
 * gait_mode(1/STATIC_MED_CLEARANCE)    = Static Gait, MED Clearance /UNUSED
 * gait_mode(2/STATIC_HIGH_CLEARANCE)   = Static Gait, HIGH Clearance
 * gait_mode(3/SEARCH_FIRE)             = Search Fire
 * gait_mode(4/FORWARD)                 = Forward Kinematics, Tripod Gait
 * gait_mode(5/BACKWARD) 			    = Backward Kinematics, Tripod Gait
 * gait_mode(6)/ROTATE_RIGHT            = Rotate Right Kinematics
 * gait_mode(7)/ROTATE_LEFT             = Rotate Left Kinemtics
 * gait_mode(8)/TURN_RIGHT				= Turn Right Kinematics
 * gai_mode(9)/TURN_LEFT				= Turn Left Kinematics
 *
 */


void mov_static(void)
{
//	Sendto_PC(USART1,"BW Hexapod Static Gait \r");

    generate_movement_data(0,0,9);
    delay_ms(50);
//    delay_ms(5000); jika delay di tambah jadi kacau
    inv_kine(front_left,90,7,leg);
    inv_kine(front_right,90,7,leg);
    inv_kine(middle_left,90,7,leg);
    inv_kine(middle_right,90,7,leg);
    inv_kine(rear_left,90,7,leg);
    inv_kine(rear_right,90,7,leg);
    delay_ms(100);

}

/*
 * func  : void mov_fwd_5cm (int distance, int SPEED)
 * brief : convert (int) distance into forward locomotion
 * param : (int) distance is prescaled by 5
 * Ver   : 4
 * 		   Configured for the new BW's mechanical
 *		   Last Revised By: Ryan (Thursday, August 28, 2015
 * programmer's note  : theoretically, robot should move 5 cm in each iteration,
 * 					    but in the actual case, it just move for about 4.75 cm
 * 					    (case: mov_fwd_5cm(20,FAST) -> BW moves forward only 18 cm
 *
 */
void mov_fwd_5cm (int distance, int SPEED)
{
	Sendto_PC(USART1,"BW Forward Movement 5 cm \r");
	int limit= distance/5;
	int loop;

	generate_movement_data(0,5,9);
	delay_ms(50);
	for (loop=1;loop<=limit;loop++)
		{
			//gait_mode(FORWARD, &SPEED);
			//1
			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			inv_kine(front_left,90,7,leg); //static
			inv_kine(front_right,90+beta[3],10,leg-3); //ke belakang angkat
			inv_kine(middle_left,90+beta[1],10,leg-3);
			inv_kine(middle_right,90,7,leg);
			inv_kine(rear_left,90,7,leg);
			inv_kine(rear_right,90+beta[5],10,leg-3);
			delay_ms(SPEED);

			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;

			//BW_Tracer_Check();
			//2
			inv_kine(front_left,90+beta[0],7,leg); //ke belakang
			inv_kine(front_right,90-beta[3],10,leg-3); //ke depan angkat
			inv_kine(middle_left,90-beta[1],10,leg-3);
			inv_kine(middle_right,90+beta[4],7,leg);
			inv_kine(rear_left,90+beta[2],7,leg);
			inv_kine(rear_right,90-beta[5],10,leg-3);
			delay_ms(SPEED);

			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			//3
			inv_kine(front_left,90+beta[0],7,leg); //ke belakang
			inv_kine(front_right,90-beta[3],7,leg); //ke depan turun
			inv_kine(middle_left,90-beta[1],7,leg);
			inv_kine(middle_right,90+beta[4],7,leg);
			inv_kine(rear_left,90+beta[2],7,leg);
			inv_kine(rear_right,90-beta[5],7,leg);
			delay_ms(SPEED);

			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			//4
			inv_kine(front_left,90+beta[0],10,leg-3); //angkat
			inv_kine(front_right,90,7,leg); //static
			inv_kine(middle_left,90,7,leg);
			inv_kine(middle_right,90+beta[4],10,leg-3);
			inv_kine(rear_left,90+beta[2],10,leg-3);
			inv_kine(rear_right,90,7,leg);
			delay_ms(SPEED);

			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			//5
			inv_kine(front_left,90-beta[0],10,leg-3); //ke depan
			inv_kine(front_right,90+beta[3],7,leg); // ke belakang
			inv_kine(middle_left,90+beta[1],7,leg);
			inv_kine(middle_right,90-beta[4],10,leg-3);
			inv_kine(rear_left,90-beta[2],10,leg-3);
			inv_kine(rear_right,90+beta[5],7,leg);
			delay_ms(SPEED);

			//BW_Tracer_Check();
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			TCS3200_Transmit(UART5, TCS_CMD_SEND_CONCLUSION);
			if(TCS3200_SLV_DATA[2]==TRACER_WHITE) TRACER_STAT= TRACER_WHITE;
			//6
			inv_kine(front_left,90-beta[0],7,leg); //turun
			inv_kine(front_right,90+beta[3],7,leg); //ke belakang
			inv_kine(middle_left,90+beta[1],7,leg);
			inv_kine(middle_right,90-beta[4],7,leg);
			inv_kine(rear_left,90-beta[2],7,leg);
			inv_kine(rear_right,90+beta[5],7,leg);
			delay_ms(SPEED);
		}
}

void mov_fwd_3cm (int distance, int SPEED)
{
	Sendto_PC(USART1,"BW Forward Movement 3 cm \r");
	int limit= distance/3;
	int loop;
	generate_movement_data(0,3,9);

	delay_ms(50);
	for (loop=1;loop<=limit;loop++)
		{
			//1
			inv_kine(front_left,90,7,leg);
			inv_kine(front_right,90+beta[3],10,leg-3);
			inv_kine(middle_left,90+beta[1],10,leg-3);
			inv_kine(middle_right,90,7,leg);
			inv_kine(rear_left,90,7,leg);
			inv_kine(rear_right,90+beta[5],10,leg-3);
			delay_ms(SPEED);

			//2
			inv_kine(front_left,90+beta[0],7,leg);
			inv_kine(front_right,90-beta[3],10,leg-3);
			inv_kine(middle_left,90-beta[1],10,leg-3);
			inv_kine(middle_right,90+beta[4],7,leg);
			inv_kine(rear_left,90+beta[2],7,leg);
			inv_kine(rear_right,90-beta[5],10,leg-3);
			delay_ms(SPEED);

			//3
			inv_kine(front_left,90+beta[0],7,leg);
			inv_kine(front_right,90-beta[3],7,leg);
			inv_kine(middle_left,90-beta[1],7,leg);
			inv_kine(middle_right,90+beta[4],7,leg);
			inv_kine(rear_left,90+beta[2],7,leg);
			inv_kine(rear_right,90-beta[5],7,leg);
			delay_ms(SPEED);

			//4
			inv_kine(front_left,90+beta[0],10,leg-3);
			inv_kine(front_right,90,7,leg);
			inv_kine(middle_left,90,7,leg);
			inv_kine(middle_right,90+beta[4],10,leg-3);
			inv_kine(rear_left,90+beta[2],10,leg-3);
			inv_kine(rear_right,90,7,leg);
			delay_ms(SPEED);

			//5
			inv_kine(front_left,90-beta[0],10,leg-3);
			inv_kine(front_right,90+beta[3],7,leg);
			inv_kine(middle_left,90+beta[1],7,leg);
			inv_kine(middle_right,90-beta[4],10,leg-3);
			inv_kine(rear_left,90-beta[2],10,leg-3);
			inv_kine(rear_right,90+beta[5],7,leg);
			delay_ms(SPEED);

			//6
			inv_kine(front_left,90-beta[0],7,leg);
			inv_kine(front_right,90+beta[3],7,leg);
			inv_kine(middle_left,90+beta[1],7,leg);
			inv_kine(middle_right,90-beta[4],7,leg);
			inv_kine(rear_left,90-beta[2],7,leg);
			inv_kine(rear_right,90+beta[5],7,leg);
			delay_ms(SPEED);
		}
	//mov_static();
	//delay_ms(150);
}

void mov_fwd_2cm (int distance, int SPEED)
{
	Sendto_PC(USART1,"BW Forward Movement 2 cm \r");
	int limit= distance/2;
	int loop;
	generate_movement_data(0,2,9);

	delay_ms(50);
	for (loop=1;loop<=limit;loop++)
		{
			//1
			inv_kine(front_left,90,7,leg);
			inv_kine(front_right,90+beta[3],10,leg-3);
			inv_kine(middle_left,90+beta[1],10,leg-3);
			inv_kine(middle_right,90,7,leg);
			inv_kine(rear_left,90,7,leg);
			inv_kine(rear_right,90+beta[5],10,leg-3);
			delay_ms(SPEED);

			//2
			inv_kine(front_left,90+beta[0],7,leg);
			inv_kine(front_right,90-beta[3],10,leg-3);
			inv_kine(middle_left,90-beta[1],10,leg-3);
			inv_kine(middle_right,90+beta[4],7,leg);
			inv_kine(rear_left,90+beta[2],7,leg);
			inv_kine(rear_right,90-beta[5],10,leg-3);
			delay_ms(SPEED);

			//3
			inv_kine(front_left,90+beta[0],7,leg);
			inv_kine(front_right,90-beta[3],7,leg);
			inv_kine(middle_left,90-beta[1],7,leg);
			inv_kine(middle_right,90+beta[4],7,leg);
			inv_kine(rear_left,90+beta[2],7,leg);
			inv_kine(rear_right,90-beta[5],7,leg);
			delay_ms(SPEED);

			//4
			inv_kine(front_left,90+beta[0],10,leg-3);
			inv_kine(front_right,90,7,leg);
			inv_kine(middle_left,90,7,leg);
			inv_kine(middle_right,90+beta[4],10,leg-3);
			inv_kine(rear_left,90+beta[2],10,leg-3);
			inv_kine(rear_right,90,7,leg);
			delay_ms(SPEED);

			//5
			inv_kine(front_left,90-beta[0],10,leg-3);
			inv_kine(front_right,90+beta[3],7,leg);
			inv_kine(middle_left,90+beta[1],7,leg);
			inv_kine(middle_right,90-beta[4],10,leg-3);
			inv_kine(rear_left,90-beta[2],10,leg-3);
			inv_kine(rear_right,90+beta[5],7,leg);
			delay_ms(SPEED);

			//6
			inv_kine(front_left,90-beta[0],7,leg);
			inv_kine(front_right,90+beta[3],7,leg);
			inv_kine(middle_left,90+beta[1],7,leg);
			inv_kine(middle_right,90-beta[4],7,leg);
			inv_kine(rear_left,90-beta[2],7,leg);
			inv_kine(rear_right,90+beta[5],7,leg);
			delay_ms(SPEED);
		}
	//mov_static();
	//delay_ms(150);
}

/*
 * func  : void mov_bwd (int distance)
 * brief : convert (int) distance into backward locomotion
 * param : (int) distance is prescaled by 5
 * Ver   : 2
 * 		   Configured for the new BW's mechanical
 *		   Last Revised By: Ryan (Friday, April 3rd, 2015)
 * programmer's note  :
 *
 */
void mov_bwd(int distance, int SPEED)
{
	Sendto_PC(USART1,"BW Bacward Movement \r");
	int limit= distance/5;
	int loop;
	generate_movement_data(0,-5,9);
	delay_ms(50);
	for (loop=1;loop<=limit;loop++)
		{
			//1
			inv_kine(front_left,90,7,leg);
			inv_kine(front_right,90+beta[3],10,leg-3); //MAJU
			inv_kine(middle_left,90+beta[4]+13,10,leg-3); //MAJU
			inv_kine(middle_right,90,7,leg);
			inv_kine(rear_left,90,7,leg);
			inv_kine(rear_right,90+beta[5],10,leg-3); //MAJU
			delay_ms(SPEED);

			//2
			inv_kine(front_left,90+beta[0]+13,7,leg); //MAJU
			inv_kine(front_right,90-beta[3],10,leg-3); //MUNDUR
			inv_kine(middle_left,90-beta[1],10,leg-3); //MAJU
			inv_kine(middle_right,90+beta[4],7,leg); //MUNDUR
			inv_kine(rear_left,90+beta[2]+13,7,leg); //MAJU
			inv_kine(rear_right,90-beta[5],10,leg-3); //MUNDUR
			delay_ms(SPEED);

			//3
			inv_kine(front_left,90+beta[0]+10,7,leg); //MAJU
			inv_kine(front_right,90-beta[3],7,leg); //MUNDUR
			inv_kine(middle_left,90-beta[1],7,leg); //MUNDUR
			inv_kine(middle_right,90+beta[4],7,leg); //MAJU
			inv_kine(rear_left,90+beta[2]+13,7,leg); //MAJU
			inv_kine(rear_right,90-beta[5],7,leg); //MUNDUR
			delay_ms(SPEED);

			//4
			inv_kine(front_left,90+beta[0]+13,10,leg-3); //MAJU
			inv_kine(front_right,90,7,leg);
			inv_kine(middle_left,90,7,leg);
			inv_kine(middle_right,90+beta[4],10.5,leg-3); //MAJU
			inv_kine(rear_left,90+beta[2]+13,10,leg-3); //MAJU
			inv_kine(rear_right,90,7,leg);
			delay_ms(SPEED);

			//5
			inv_kine(front_left,90-beta[0],10,leg-3); //MUNDUR
			inv_kine(front_right,90+beta[3],7,leg); //MAJU
			inv_kine(middle_left,90+beta[1]+13,7,leg); //MAJU
			inv_kine(middle_right,90-beta[4],10.5,leg-3); //MUNDUR
			inv_kine(rear_left,90-beta[2],10,leg-3); //MUNDUR
			inv_kine(rear_right,90+beta[5],7,leg); //MAJU
			delay_ms(SPEED);

			//6
			inv_kine(front_left,90-beta[0],7,leg); //MUNDUR
			inv_kine(front_right,90+beta[3],7,leg); //MAJU
			inv_kine(middle_left,90+beta[1]+13,7,leg); //MAJU
			inv_kine(middle_right,90-beta[4],7,leg); //MUNDUR
			inv_kine(rear_left,90-beta[2],7,leg); //MUNDUR
			inv_kine(rear_right,90+beta[5],7,leg); //MAJU
			delay_ms(SPEED);
		}
}

void mov_bwd_5cm(int distance, int SPEED)
{
	Sendto_PC(USART1,"BW Bacward Movement \r");
	int limit= distance/5;
	int loop;
	generate_movement_data(0,-5,9);
	delay_ms(50);
	for (loop=1;loop<=limit;loop++)
		{
				//1
				inv_kine(front_left,90+beta[5],10,leg-3); //static
				inv_kine(front_right,90,7,leg); //ke belakang angkat
				inv_kine(middle_left,90,7,leg);
				inv_kine(middle_right,90+beta[1],10,leg-3);
				inv_kine(rear_left,90+beta[3],10,leg-3);
				inv_kine(rear_right,90,7,leg);
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90-beta[5],10,leg-3); //ke belakang
				inv_kine(front_right,90+beta[2],7,leg); //ke depan angkat
				inv_kine(middle_left,90+beta[4],7,leg);
				inv_kine(middle_right,90-beta[1],10,leg-3);
				inv_kine(rear_left,90-beta[3],10,leg-3);
				inv_kine(rear_right,90+beta[0],7,leg);
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90-beta[5],7,leg); //ke belakang
				inv_kine(front_right,90+beta[2],7,leg); //ke depan turun
				inv_kine(middle_left,90+beta[4],7,leg);
				inv_kine(middle_right,90-beta[1],7,leg);
				inv_kine(rear_left,90-beta[3],7,leg);
				inv_kine(rear_right,90+beta[0],7,leg);
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90,7,leg); //angkat
				inv_kine(front_right,90+beta[2],10,leg-3); //static
				inv_kine(middle_left,90+beta[4],10,leg-3);
				inv_kine(middle_right,90,7,leg);
				inv_kine(rear_left,90,7,leg);
				inv_kine(rear_right,90+beta[0],10,leg-3);
				delay_ms(SPEED);

				//5
				inv_kine(front_left,90+beta[5],7,leg); //ke depan
				inv_kine(front_right,90-beta[2],10,leg-3); // ke belakang
				inv_kine(middle_left,90-beta[4],10,leg-3);
				inv_kine(middle_right,90+beta[1],7,leg);
				inv_kine(rear_left,90+beta[3],7,leg);
				inv_kine(rear_right,90-beta[0],10,leg-3);
				delay_ms(SPEED);

				//6
				inv_kine(front_left,90+beta[5],7,leg); //turun
				inv_kine(front_right,90-beta[2],7,leg); //ke belakang
				inv_kine(middle_left,90-beta[4],7,leg);
				inv_kine(middle_right,90+beta[1],7,leg);
				inv_kine(rear_left,90+beta[3],7,leg);
				inv_kine(rear_right,90-beta[0],7,leg);
				delay_ms(SPEED);
		}
}

void mov_bwd_3cm(int distance, int SPEED)
{
	Sendto_PC(USART1,"BW Bacward Movement \r");
	int limit= distance/3;
	int loop;
	generate_movement_data(0,-3,9);
	delay_ms(50);
	for (loop=1;loop<=limit;loop++)
		{
				//1
				inv_kine(front_left,90+beta[5],10,leg-3); //static
				inv_kine(front_right,90,7,leg); //ke belakang angkat
				inv_kine(middle_left,90,7,leg);
				inv_kine(middle_right,90+beta[1],10,leg-3);
				inv_kine(rear_left,90+beta[3],10,leg-3);
				inv_kine(rear_right,90,7,leg);
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90-beta[5],10,leg-3); //ke belakang
				inv_kine(front_right,90+beta[2],7,leg); //ke depan angkat
				inv_kine(middle_left,90+beta[4],7,leg);
				inv_kine(middle_right,90-beta[1],10,leg-3);
				inv_kine(rear_left,90-beta[3],10,leg-3);
				inv_kine(rear_right,90+beta[0],7,leg);
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90-beta[5],7,leg); //ke belakang
				inv_kine(front_right,90+beta[2],7,leg); //ke depan turun
				inv_kine(middle_left,90+beta[4],7,leg);
				inv_kine(middle_right,90-beta[1],7,leg);
				inv_kine(rear_left,90-beta[3],7,leg);
				inv_kine(rear_right,90+beta[0],7,leg);
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90,7,leg); //angkat
				inv_kine(front_right,90+beta[2],10,leg-3); //static
				inv_kine(middle_left,90+beta[4],10,leg-3);
				inv_kine(middle_right,90,7,leg);
				inv_kine(rear_left,90,7,leg);
				inv_kine(rear_right,90+beta[0],10,leg-3);
				delay_ms(SPEED);

				//5
				inv_kine(front_left,90+beta[5],7,leg); //ke depan
				inv_kine(front_right,90-beta[2],10,leg-3); // ke belakang
				inv_kine(middle_left,90-beta[4],10,leg-3);
				inv_kine(middle_right,90+beta[1],7,leg);
				inv_kine(rear_left,90+beta[3],7,leg);
				inv_kine(rear_right,90-beta[0],10,leg-3);
				delay_ms(SPEED);

				//6
				inv_kine(front_left,90+beta[5],7,leg); //turun
				inv_kine(front_right,90-beta[2],7,leg); //ke belakang
				inv_kine(middle_left,90-beta[4],7,leg);
				inv_kine(middle_right,90+beta[1],7,leg);
				inv_kine(rear_left,90+beta[3],7,leg);
				inv_kine(rear_right,90-beta[0],7,leg);
				delay_ms(SPEED);
		}
}

/*
 *  Func  : void mov_rot_right(int SPEED, int STEP)
 *  Brief : rotate hexapod body clockwise per parameter with desired speed and step length
 *  Param : SPEED -> default= MED_SLOW(200), MED(150), FAST(130), ULTRA_FAST(50);
 *  		STEP  -> default= FAR(5), CLOSE (2);
 *  ver	  : 1
 *  Last revised by: Ryan (MON, August 3rd 2015)
 *     	             Configured for the new BW's mechanical
 * programmer's note  :
 */
void mov_rot_right(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Rotate Right Movement \r");
	switch(STEP)
	{
		case CLOSE:
			{
				generate_movement_data(0,STEP,9);
				delay_ms(50);

				//gait_mode(ROTATE_RIGHT,SPEED);
				//1
				inv_kine(front_left,90+beta[0],7,leg); //mundur
				inv_kine(front_right,90+beta[3],10,leg-3); //mundur
				inv_kine(middle_left,90-beta[1],10,leg-3); //maju
				inv_kine(middle_right,90-beta[4],7,leg); //maju
				inv_kine(rear_left,90+beta[2],7,leg); //mundur
				inv_kine(rear_right,90+beta[5],10,leg-3); //mundur
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90+beta[0],7,leg); //mundur
				inv_kine(front_right,90+beta[3],7,leg); //mundur
				inv_kine(middle_left,90-beta[1],7,leg); //maju
				inv_kine(middle_right,90-beta[4],7,leg); //maju
				inv_kine(rear_left,90+beta[2],7,leg); //mundur
				inv_kine(rear_right,90+beta[5],7,leg); //mundur
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90-beta[0],10,leg-3); //maju
				inv_kine(front_right,90-beta[3],7,leg); //maju
				inv_kine(middle_left,90+beta[1],7,leg); //mundur
				inv_kine(middle_right,90+beta[4],10.5,leg-3); //mundur
				inv_kine(rear_left,90-beta[2],10,leg-3); //maju
				inv_kine(rear_right,90-beta[5],7,leg); //maju
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90-beta[0],7,leg); //maju
				inv_kine(front_right,90-beta[3],7,leg); //maju
				inv_kine(middle_left,90+beta[1],7,leg); //mundur
				inv_kine(middle_right,90+beta[4],7,leg); //mundur
				inv_kine(rear_left,90-beta[2],7,leg); //maju
				inv_kine(rear_right,90-beta[5],7,leg); //maju
				delay_ms(SPEED);

			}break;

		case FAR:
			{
				generate_movement_data(0,STEP,9);
				delay_ms(50);

				//gait_mode(ROTATE_RIGHT,SPEED);
				//1
				inv_kine(front_left,90+beta[0],7,leg); //mundur
				inv_kine(front_right,90+beta[3],10,leg-3); //mundur
				inv_kine(middle_left,90-beta[1],10,leg-3); //maju
				inv_kine(middle_right,90-beta[4],7,leg); //maju
				inv_kine(rear_left,90+beta[2],7,leg); //mundur
				inv_kine(rear_right,90+beta[5],10,leg-3); //mundur
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90+beta[0],7,leg); //mundur
				inv_kine(front_right,90+beta[3],7,leg); //mundur
				inv_kine(middle_left,90-beta[1],7,leg); //maju
				inv_kine(middle_right,90-beta[4],7,leg); //maju
				inv_kine(rear_left,90+beta[2],7,leg); //mundur
				inv_kine(rear_right,90+beta[5],7,leg); //mundur
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90-beta[0],10,leg-3); //maju
				inv_kine(front_right,90-beta[3],7,leg); //maju
				inv_kine(middle_left,90+beta[1],7,leg); //mundur
				inv_kine(middle_right,90+beta[4],10.5,leg-3); //mundur
				inv_kine(rear_left,90-beta[2],10,leg-3); //maju
				inv_kine(rear_right,90-beta[5],7,leg); //maju
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90-beta[0],7,leg); //maju
				inv_kine(front_right,90-beta[3],7,leg); //maju
				inv_kine(middle_left,90+beta[1],7,leg); //mundur
				inv_kine(middle_right,90+beta[4],7,leg); //mundur
				inv_kine(rear_left,90-beta[2],7,leg); //maju
				inv_kine(rear_right,90-beta[5],7,leg); //maju
				delay_ms(SPEED);

			}break;
		default: break;
	}
}

void mov_rot_right_reverse(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Rotate Right Movement \r");
	switch(STEP)
	{
		case CLOSE:
			{
				generate_movement_data(0,-STEP,9);
				delay_ms(50);

				//gait_mode(ROTATE_RIGHT,SPEED);
				//1
				inv_kine(front_left,90+beta[5],10,leg-3); //mundur
				inv_kine(front_right,90+beta[2],7,leg); //mundur
				inv_kine(middle_left,90-beta[4],7,leg); //maju
				inv_kine(middle_right,90-beta[1],10,leg-3); //maju
				inv_kine(rear_left,90+beta[3],10,leg-3); //mundur
				inv_kine(rear_right,90+beta[0],7,leg); //mundur
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90+beta[5],7,leg); //mundur
				inv_kine(front_right,90+beta[2],7,leg); //mundur
				inv_kine(middle_left,90-beta[4],7,leg); //maju
				inv_kine(middle_right,90-beta[1],7,leg); //maju
				inv_kine(rear_left,90+beta[3],7,leg); //mundur
				inv_kine(rear_right,90+beta[0],7,leg); //mundur
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90-beta[5],7,leg); //maju
				inv_kine(front_right,90-beta[2],10,leg-3); //maju
				inv_kine(middle_left,90+beta[4],10.5,leg-3); //mundur
				inv_kine(middle_right,90+beta[1],7,leg); //mundur
				inv_kine(rear_left,90-beta[3],7,leg); //maju
				inv_kine(rear_right,90-beta[0],10,leg-3); //maju
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90-beta[5],7,leg); //maju
				inv_kine(front_right,90-beta[2],7,leg); //maju
				inv_kine(middle_left,90+beta[4],7,leg); //mundur
				inv_kine(middle_right,90+beta[1],7,leg); //mundur
				inv_kine(rear_left,90-beta[3],7,leg); //maju
				inv_kine(rear_right,90-beta[0],7,leg); //maju
				delay_ms(SPEED);

			}break;

		case FAR:
			{
				generate_movement_data(0,-STEP,9);
				delay_ms(50);

				//gait_mode(ROTATE_RIGHT,SPEED);
				//1
				inv_kine(front_left,90+beta[5],10,leg-3); //mundur
				inv_kine(front_right,90+beta[2],7,leg); //mundur
				inv_kine(middle_left,90-beta[4],7,leg); //maju
				inv_kine(middle_right,90-beta[1],10,leg-3); //maju
				inv_kine(rear_left,90+beta[3],10,leg-3); //mundur
				inv_kine(rear_right,90+beta[0],7,leg); //mundur
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90+beta[5],7,leg); //mundur
				inv_kine(front_right,90+beta[2],7,leg); //mundur
				inv_kine(middle_left,90-beta[4],7,leg); //maju
				inv_kine(middle_right,90-beta[1],7,leg); //maju
				inv_kine(rear_left,90+beta[3],7,leg); //mundur
				inv_kine(rear_right,90+beta[0],7,leg); //mundur
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90-beta[5],7,leg); //maju
				inv_kine(front_right,90-beta[2],10,leg-3); //maju
				inv_kine(middle_left,90+beta[4],10.5,leg-3); //mundur
				inv_kine(middle_right,90+beta[1],7,leg); //mundur
				inv_kine(rear_left,90-beta[3],7,leg); //maju
				inv_kine(rear_right,90-beta[0],10,leg-3); //maju
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90-beta[5],7,leg); //maju
				inv_kine(front_right,90-beta[2],7,leg); //maju
				inv_kine(middle_left,90+beta[4],7,leg); //mundur
				inv_kine(middle_right,90+beta[1],7,leg); //mundur
				inv_kine(rear_left,90-beta[3],7,leg); //maju
				inv_kine(rear_right,90-beta[0],7,leg); //maju
				delay_ms(SPEED);

			}break;
		default: break;
	}
}

/*
 *  Func  : void mov_rot_left(int SPEED, int STEP)
 *  Brief : rotate hexapod body clockwise per parameter with desired speed and step length
 *  Param : SPEED -> default= MED_SLOW(200), MED(150), FAST(130), ULTRA_FAST(50);
 *  		STEP  -> default= FAR(5), CLOSE (2);
 *  ver	  : 1
 *  Last revised by: Ryan (MON, August 3rd 2015)
 *     	             Configured for the new BW's mechanical
 * programmer's note  :
 */
void mov_rot_left(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Rotate Left Movement \r");
	switch(STEP)
	{
		case CLOSE:
			{
				generate_movement_data(0,STEP,9);
				delay_ms(50);

				//gait_mode(ROTATE_LEFT, SPEED);
				//1
				inv_kine(front_left,90-beta[0],7,leg); //maju /
				inv_kine(front_right,90-beta[3],10,leg-3); //maju
				inv_kine(middle_left,90+beta[1],10,leg-3); //mundur /
				inv_kine(middle_right,90+beta[4],7,leg); //mundur /
				inv_kine(rear_left,90-beta[2],7,leg); //maju /
				inv_kine(rear_right,90-beta[5],10,leg-3); //maju /
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90-beta[0],7,leg); //maju /
				inv_kine(front_right,90-beta[3],7,leg); //maju /
				inv_kine(middle_left,90+beta[1],7,leg); //mundur /
				inv_kine(middle_right,90+beta[4],7,leg); //mundur /
				inv_kine(rear_left,90-beta[2],7,leg); //maju /
				inv_kine(rear_right,90-beta[5],7,leg); //maju /
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90+beta[0],10,leg-3); //mundur /
				inv_kine(front_right,90+beta[3],7,leg); //mundur /
				inv_kine(middle_left,90-beta[1],7,leg); //maju /
				inv_kine(middle_right,90-beta[4],10.5,leg-3); //maju /
				inv_kine(rear_left,90+beta[2],10,leg-3); //mundur /
				inv_kine(rear_right,90+beta[5],7,leg); //mundur /
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90+beta[0],7,leg); //mundur /
				inv_kine(front_right,90+beta[3],7,leg); //mundur /
				inv_kine(middle_left,90-beta[1],7,leg); //maju /
				inv_kine(middle_right,90-beta[4],7,leg); //maju /
				inv_kine(rear_left,90+beta[2],7,leg); //mundur /
				inv_kine(rear_right,90+beta[5],7,leg); //mundur /
				delay_ms(SPEED);

			}break;

		case FAR:
			{
				generate_movement_data(0,STEP,9);
				delay_ms(50);

				//gait_mode(ROTATE_LEFT, SPEED);
				//1
				inv_kine(front_left,90-beta[0],7,leg); //maju /
				inv_kine(front_right,90-beta[3],10,leg-3); //maju
				inv_kine(middle_left,90+beta[1],10,leg-3); //mundur /
				inv_kine(middle_right,90+beta[4],7,leg); //mundur /
				inv_kine(rear_left,90-beta[2],7,leg); //maju /
				inv_kine(rear_right,90-beta[5],10,leg-3); //maju /
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90-beta[0],7,leg); //maju /
				inv_kine(front_right,90-beta[3],7,leg); //maju /
				inv_kine(middle_left,90+beta[1],7,leg); //mundur /
				inv_kine(middle_right,90+beta[4],7,leg); //mundur /
				inv_kine(rear_left,90-beta[2],7,leg); //maju /
				inv_kine(rear_right,90-beta[5],7,leg); //maju /
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90+beta[0],10,leg-3); //mundur /
				inv_kine(front_right,90+beta[3],7,leg); //mundur /
				inv_kine(middle_left,90-beta[1],7,leg); //maju /
				inv_kine(middle_right,90-beta[4],10.5,leg-3); //maju /
				inv_kine(rear_left,90+beta[2],10,leg-3); //mundur /
				inv_kine(rear_right,90+beta[5],7,leg); //mundur /
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90+beta[0],7,leg); //mundur /
				inv_kine(front_right,90+beta[3],7,leg); //mundur /
				inv_kine(middle_left,90-beta[1],7,leg); //maju /
				inv_kine(middle_right,90-beta[4],7,leg); //maju /
				inv_kine(rear_left,90+beta[2],7,leg); //mundur /
				inv_kine(rear_right,90+beta[5],7,leg); //mundur /
				delay_ms(SPEED);

			}break;
		default: break;
	}
}

void mov_rot_left_reverse(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Rotate Left Movement \r");
	switch(STEP)
	{
		case CLOSE:
			{
				generate_movement_data(0,-STEP,9);
				delay_ms(50);

				//gait_mode(ROTATE_LEFT, SPEED);
				//1
				inv_kine(front_left,90-beta[5],10,leg-3); //maju /
				inv_kine(front_right,90-beta[2],7,leg); //maju
				inv_kine(middle_left,90+beta[4],7,leg); //mundur /
				inv_kine(middle_right,90+beta[1],10,leg-3); //mundur /
				inv_kine(rear_left,90-beta[3],10,leg-3); //maju /
				inv_kine(rear_right,90-beta[0],7,leg); //maju /
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90-beta[5],7,leg); //maju /
				inv_kine(front_right,90-beta[2],7,leg); //maju /
				inv_kine(middle_left,90+beta[4],7,leg); //mundur /
				inv_kine(middle_right,90+beta[1],7,leg); //mundur /
				inv_kine(rear_left,90-beta[3],7,leg); //maju /
				inv_kine(rear_right,90-beta[0],7,leg); //maju /
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90+beta[5],7,leg); //mundur /
				inv_kine(front_right,90+beta[2],10,leg-3); //mundur /
				inv_kine(middle_left,90-beta[4],10.5,leg-3); //maju /
				inv_kine(middle_right,90-beta[1],7,leg); //maju /
				inv_kine(rear_left,90+beta[3],7,leg); //mundur /
				inv_kine(rear_right,90+beta[0],10,leg-3); //mundur /
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90+beta[5],7,leg); //mundur /
				inv_kine(front_right,90+beta[2],7,leg); //mundur /
				inv_kine(middle_left,90-beta[4],7,leg); //maju /
				inv_kine(middle_right,90-beta[1],7,leg); //maju /
				inv_kine(rear_left,90+beta[3],7,leg); //mundur /
				inv_kine(rear_right,90+beta[0],7,leg); //mundur /
				delay_ms(SPEED);

			}break;

		case FAR:
			{
				generate_movement_data(0,-STEP,9);
				delay_ms(50);

				//gait_mode(ROTATE_LEFT, SPEED);
				//1
				inv_kine(front_left,90-beta[5],10,leg-3); //maju /
				inv_kine(front_right,90-beta[2],7,leg); //maju
				inv_kine(middle_left,90+beta[4],7,leg); //mundur /
				inv_kine(middle_right,90+beta[1],10,leg-3); //mundur /
				inv_kine(rear_left,90-beta[3],10,leg-3); //maju /
				inv_kine(rear_right,90-beta[0],7,leg); //maju /
				delay_ms(SPEED);

				//2
				inv_kine(front_left,90-beta[5],7,leg); //maju /
				inv_kine(front_right,90-beta[2],7,leg); //maju /
				inv_kine(middle_left,90+beta[4],7,leg); //mundur /
				inv_kine(middle_right,90+beta[1],7,leg); //mundur /
				inv_kine(rear_left,90-beta[3],7,leg); //maju /
				inv_kine(rear_right,90-beta[0],7,leg); //maju /
				delay_ms(SPEED);

				//3
				inv_kine(front_left,90+beta[5],7,leg); //mundur /
				inv_kine(front_right,90+beta[2],10,leg-3); //mundur /
				inv_kine(middle_left,90-beta[4],10.5,leg-3); //maju /
				inv_kine(middle_right,90-beta[1],7,leg); //maju /
				inv_kine(rear_left,90+beta[3],7,leg); //mundur /
				inv_kine(rear_right,90+beta[0],10,leg-3); //mundur /
				delay_ms(SPEED);

				//4
				inv_kine(front_left,90+beta[5],7,leg); //mundur /
				inv_kine(front_right,90+beta[2],7,leg); //mundur /
				inv_kine(middle_left,90-beta[4],7,leg); //maju /
				inv_kine(middle_right,90-beta[1],7,leg); //maju /
				inv_kine(rear_left,90+beta[3],7,leg); //mundur /
				inv_kine(rear_right,90+beta[0],7,leg); //mundur /
				delay_ms(SPEED);

			}break;
		default: break;
	}
}

/*
 * Func : void mov_curve_right(int SPEED, int STEP)
 * brief: Robot's forward curve right locomotion, useful for wall following and solving the crossroad
 * Written By: Ryan (MON, MARCH 9th, 2015)
 * Ver  : 2 (Last Revised By: Ryan (MON, August 19th, 2015)
 *   	     sudut belok dikurangi (yang lama sering bermasalah untuk follow)
 * programmer's note  :
 */
void mov_curve_right(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Curve Right Movement \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	//gait_mode(CURVE_RIGHT, SPEED);
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3],10,leg-3);
	inv_kine(middle_left,90+beta[1],10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],10,leg-3);
	delay_ms(SPEED);

	//2
	inv_kine(front_left,90+beta[0]+15,7,leg);
	inv_kine(front_right,90-beta[3]+10,10,leg-3);
	inv_kine(middle_left,90-beta[1]-15,10,leg-3);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+15,7,leg);
	inv_kine(rear_right,90-beta[5]+10,10,leg-3);
	delay_ms(SPEED);

	//3
	inv_kine(front_left,90+beta[0]+15,7,leg);
	inv_kine(front_right,90-beta[3]+10,7,leg);
	inv_kine(middle_left,90-beta[1]-15,7,leg);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+15,7,leg);
	inv_kine(rear_right,90-beta[5]+10,7,leg);
	delay_ms(SPEED);

	//4
	inv_kine(front_left,90+beta[0]+15,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4],10.5,leg-3);
	inv_kine(rear_left,90+beta[2]+15,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	//5
	inv_kine(front_left,90-beta[0]-15,10,leg-3);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+15,7,leg);
	inv_kine(middle_right,90-beta[4]+10,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]-15,10,leg-3);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	//6
	inv_kine(front_left,90-beta[0]-15,7,leg);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+15,7,leg);
	inv_kine(middle_right,90-beta[4]+10,7,leg);
	inv_kine(rear_left,90-beta[2]-15,7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);
}

void mov_curve_right_reverse(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Curve Right Movement \r");
	generate_movement_data(0,-STEP,9);
	delay_ms(50);

	//gait_mode(CURVE_RIGHT, SPEED);
	//1
	inv_kine(front_left,90+beta[5],10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[1],10,leg-3);
	inv_kine(rear_left,90+beta[3],10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	//2
	inv_kine(front_left,90-beta[5]+10,10,leg-3);
	inv_kine(front_right,90+beta[2]+15,7,leg);
	inv_kine(middle_left,90+beta[4],7,leg);
	inv_kine(middle_right,90-beta[1]-15,10,leg-3);
	inv_kine(rear_left,90-beta[3]+10,10,leg-3);
	inv_kine(rear_right,90+beta[0]+15,7,leg);
	delay_ms(SPEED);

	//3
	inv_kine(front_left,90-beta[5]+10,7,leg);
	inv_kine(front_right,90+beta[2]+15,7,leg);
	inv_kine(middle_left,90+beta[4],7,leg);
	inv_kine(middle_right,90-beta[1]-15,7,leg);
	inv_kine(rear_left,90-beta[3]+10,7,leg);
	inv_kine(rear_right,90+beta[0]+15,7,leg);
	delay_ms(SPEED);

	//4
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[2]+15,10,leg-3);
	inv_kine(middle_left,90+beta[4],10.5,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[0]+15,10,leg-3);
	delay_ms(SPEED);

	//5
	inv_kine(front_left,90+beta[5],7,leg);
	inv_kine(front_right,90-beta[2]-15,10,leg-3);
	inv_kine(middle_left,90-beta[4]+10,10.5,leg-3);
	inv_kine(middle_right,90+beta[1]+15,7,leg);
	inv_kine(rear_left,90+beta[3],7,leg);
	inv_kine(rear_right,90-beta[0]-15,10,leg-3);
	delay_ms(SPEED);

	//6
	inv_kine(front_left,90+beta[5],7,leg);
	inv_kine(front_right,90-beta[2]-15,7,leg);
	inv_kine(middle_left,90-beta[4]+10,7,leg);
	inv_kine(middle_right,90+beta[1]+15,7,leg);
	inv_kine(rear_left,90+beta[3],7,leg);
	inv_kine(rear_right,90-beta[0]-15,7,leg);
	delay_ms(SPEED);
}

/*
 * Func : void mov_curve_left(int SPEED, int STEP)
 * brief: Robot's forward curve right locomotion, useful for wall following and solving the crossroad
 * Written By: Ryan (MON, MARCH 9th, 2015)
 * Ver  : 2 (Last Revised By: Ryan (MON, August 19th, 2015)
 *   	     sudut belok dikurangi (yang lama sering bermasalah untuk follow)
 * programmer's note  :
 */
void mov_curve_left(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Curve Left Movement \r");
	generate_movement_data(0,STEP,9);
	delay_ms(50);

	//gait_mode(CURVE_LEFT, SPEED);
	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3]+15,10,leg-3);
	inv_kine(middle_left,90+beta[1]-10,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5]+15,10,leg-3);
	delay_ms(SPEED);

	//2
	inv_kine(front_left,90+beta[0]-10,7,leg);
	inv_kine(front_right,90-beta[3]-15,10,leg-3);
	inv_kine(middle_left,90-beta[1]+10,10,leg-3);
	inv_kine(middle_right,90+beta[4]+15,7,leg);
	inv_kine(rear_left,90+beta[2]-10,7,leg);
	inv_kine(rear_right,90-beta[5]-15,10,leg-3);
	delay_ms(SPEED);

	//3
	inv_kine(front_left,90+beta[0]-10,7,leg);
	inv_kine(front_right,90-beta[3]-15,7,leg);
	inv_kine(middle_left,90-beta[1]+10,7,leg);
	inv_kine(middle_right,90+beta[4]+15,7,leg);
	inv_kine(rear_left,90+beta[2]-10,7,leg);
	inv_kine(rear_right,90-beta[5]-15,7,leg);
	delay_ms(SPEED);

	//4
	inv_kine(front_left,90+beta[0]-10,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4]+15,10.5,leg-3);
	inv_kine(rear_left,90+beta[2]-10,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	//5
	inv_kine(front_left,90-beta[0]+10,10,leg-3);
	inv_kine(front_right,90+beta[3]+15,7,leg);
	inv_kine(middle_left,90+beta[1]-10,7,leg);
	inv_kine(middle_right,90-beta[4]-15,10.5,leg-3);
	inv_kine(rear_left,90-beta[2]+10,10,leg-3);
	inv_kine(rear_right,90+beta[5]+15,7,leg);
	delay_ms(SPEED);

	//6
	inv_kine(front_left,90-beta[0]+10,7,leg);
	inv_kine(front_right,90+beta[3]+15,7,leg);
	inv_kine(middle_left,90+beta[1]-10,7,leg);
	inv_kine(middle_right,90-beta[4]-15,7,leg);
	inv_kine(rear_left,90-beta[2]+10,7,leg);
	inv_kine(rear_right,90+beta[5]+15,7,leg);
	delay_ms(SPEED);
}

void mov_curve_left_reverse(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Curve Left Movement \r");
	generate_movement_data(0,-STEP,9);
	delay_ms(50);

	//gait_mode(CURVE_LEFT, SPEED);
	//1
	inv_kine(front_left,90+beta[5]+15,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[1]-10,10,leg-3);
	inv_kine(rear_left,90+beta[3]+15,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	//2
	inv_kine(front_left,90-beta[5]-15,10,leg-3);
	inv_kine(front_right,90+beta[2]-10,7,leg);
	inv_kine(middle_left,90+beta[4]+15,7,leg);
	inv_kine(middle_right,90-beta[1]+10,10,leg-3);
	inv_kine(rear_left,90-beta[3]-15,10,leg-3);
	inv_kine(rear_right,90+beta[0]-10,7,leg);
	delay_ms(SPEED);

	//3
	inv_kine(front_left,90-beta[5]-15,7,leg);
	inv_kine(front_right,90+beta[2]-10,7,leg);
	inv_kine(middle_left,90+beta[4]+15,7,leg);
	inv_kine(middle_right,90-beta[1]+10,7,leg);
	inv_kine(rear_left,90-beta[3]-15,7,leg);
	inv_kine(rear_right,90+beta[0]-10,7,leg);
	delay_ms(SPEED);

	//4
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[2]-10,10,leg-3);
	inv_kine(middle_left,90+beta[4]+15,10.5,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[0]-10,10,leg-3);
	delay_ms(SPEED);

	//5
	inv_kine(front_left,90+beta[5]+15,7,leg);
	inv_kine(front_right,90-beta[2]+10,10,leg-3);
	inv_kine(middle_left,90-beta[4]-15,10.5,leg-3);
	inv_kine(middle_right,90+beta[1]-10,7,leg);
	inv_kine(rear_left,90+beta[3]+15,7,leg);
	inv_kine(rear_right,90-beta[0]+10,10,leg-3);
	delay_ms(SPEED);

	//6
	inv_kine(front_left,90+beta[5]+15,7,leg);
	inv_kine(front_right,90-beta[2]+10,7,leg);
	inv_kine(middle_left,90-beta[4]-15,7,leg);
	inv_kine(middle_right,90+beta[1]-10,7,leg);
	inv_kine(rear_left,90+beta[3]+15,7,leg);
	inv_kine(rear_right,90-beta[0]+10,7,leg);
	delay_ms(SPEED);
}

/*
 * Func : void mov_askew_right_transition(void)
 * Brief: Transition gait as preparatory stage for askew right locomotion
 * 		  transition using quadrupedal gait
 * Param: N/A
 * Written By: Ryan (Thursday, August 6th, 2015
 * Ver  : 1
 * Programmer's Note: This function MUST be called in mov_askew_right function
 */
void mov_askew_right_transition(void)
{
	Sendto_PC(USART1,"BW Askew Right Transition \r");
	mov_static();
	delay_ms(100);

	/*
	 * pengurangan/penambahan 20: tiap sequence satu langkah defleksi 0.5 cm
	 * pengurangan/penambahan 40: terlalu extreme, body tengah justru yang berubah arah, mengganggu sensor ultrasonic
	 * transitions dengan tripod gait tidak stabil
	 * transition dengan tetrapo gait right handed, robot stabil
	 *
	 */

	//TRANSITION FROM STATIC GAIT HIGH CLEARANCE
	//USED GAIT: TETRAPOD/RIPPLE GAIT RIGHT HANDED
	generate_movement_data(0,0,9);
	delay_ms(150);

	//1
	inv_kine(front_left,60,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,120,10,leg-3);
	delay_ms(150);

	//2
	inv_kine(front_left,60,7,leg);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,120,7,leg);
	delay_ms(150);

	//3
	inv_kine(front_left,60,7,leg);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,120,10,leg-3);
	inv_kine(rear_left,60,10,leg-3);
	inv_kine(rear_right,120,7,leg);
	delay_ms(150);

	//4
	inv_kine(front_left,60,7,leg);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,120,7,leg);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,120,7,leg);
	delay_ms(150);

	//5
	inv_kine(front_left,60,7,leg);
	inv_kine(front_right,120,10,leg-3);
	inv_kine(middle_left,60,10,leg-3);
	inv_kine(middle_right,120,7,leg);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,120,7,leg);
	delay_ms(150);

	//FINAL FORM
	inv_kine(front_left,60,7,leg);
	inv_kine(front_right,120,7,leg);
	inv_kine(middle_left,60,7,leg);
	inv_kine(middle_right,120,7,leg);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,120,7,leg);
	delay_ms(150);


}

void mov_askew_right_transition_reverse(void)
{
	Sendto_PC(USART1,"BW Askew Right Transition \r");
	mov_static();
	delay_ms(100);

	/*
	 * pengurangan/penambahan 20: tiap sequence satu langkah defleksi 0.5 cm
	 * pengurangan/penambahan 40: terlalu extreme, body tengah justru yang berubah arah, mengganggu sensor ultrasonic
	 * transitions dengan tripod gait tidak stabil
	 * transition dengan tetrapo gait right handed, robot stabil
	 *
	 */

	//TRANSITION FROM STATIC GAIT HIGH CLEARANCE
	//USED GAIT: TETRAPOD/RIPPLE GAIT RIGHT HANDED
	generate_movement_data(0,0,9);
	delay_ms(150);

	//1
	inv_kine(front_left,120,10,leg-3);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,60,10,leg-3);
	delay_ms(150);

	//2
	inv_kine(front_left,120,7,leg);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,60,7,leg);
	delay_ms(150);

	//3
	inv_kine(front_left,120,7,leg);
	inv_kine(front_right,60,10,leg-3);
	inv_kine(middle_left,120,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,60,7,leg);
	delay_ms(150);

	//4
	inv_kine(front_left,120,7,leg);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,120,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,60,7,leg);
	delay_ms(150);

	//5
	inv_kine(front_left,120,7,leg);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,120,7,leg);
	inv_kine(middle_right,60,10,leg-3);
	inv_kine(rear_left,120,10,leg-3);
	inv_kine(rear_right,60,7,leg);
	delay_ms(150);

	//FINAL FORM
	inv_kine(front_left,120,7,leg);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,120,7,leg);
	inv_kine(middle_right,60,7,leg);
	inv_kine(rear_left,120,7,leg);
	inv_kine(rear_right,60,7,leg);
	delay_ms(150);


}

/*
 * Func : void mov_askew_right(int SPEED, int STEP)
 * brief: move robot's body in askew motion to the right
 * 		  Every 10 cm translation to x coordinates, robot moves 1 cm to the right (y positive)
 * Written By: Ryan (MON, August 3rd, 2015)
 * Ver  : 2
 * Revised By: Ryan (Thursday, August 7th, 2015)
 * programmer's note  :
 */
void mov_askew_right(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Askew Right Movement \r");

	generate_movement_data(0,5,9);
	delay_ms(150);
	//gait_mode(ASKEW_RIGHT, SPEED);
	//1
	inv_kine(front_left,60,7,leg);
	inv_kine(front_right,120+beta[3],10,leg-3);
	inv_kine(middle_left,60+beta[1],10,leg-3);
	inv_kine(middle_right,120,7,leg);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,120+beta[5],10,leg-3);
	delay_ms(SPEED);

	//2
	inv_kine(front_left,60+beta[0],7,leg);
	inv_kine(front_right,120-beta[3],10,leg-3);
	inv_kine(middle_left,60-beta[1],10,leg-3);
	inv_kine(middle_right,120+beta[4],7,leg);
	inv_kine(rear_left,60+beta[2],7,leg);
	inv_kine(rear_right,120-beta[5],10,leg-3);
	delay_ms(SPEED);

	//3
	inv_kine(front_left,60+beta[0],7,leg);
	inv_kine(front_right,120-beta[3],7,leg);
	inv_kine(middle_left,60-beta[1],7,leg);
	inv_kine(middle_right,120+beta[4],7,leg);
	inv_kine(rear_left,60+beta[2],7,leg);
	inv_kine(rear_right,120-beta[5],7,leg);
	delay_ms(SPEED);

	//4
	inv_kine(front_left,60+beta[0],10,leg-3);
	inv_kine(front_right,120,7,leg);
	inv_kine(middle_left,60,7,leg);
	inv_kine(middle_right,120+beta[4],10,leg-3);
	inv_kine(rear_left,60+beta[2],10,leg-3);
	inv_kine(rear_right,120,7,leg);
	delay_ms(SPEED);

	//5
	inv_kine(front_left,60-beta[0],10,leg-3);
	inv_kine(front_right,120+beta[3],7,leg);
	inv_kine(middle_left,60+beta[1],7,leg);
	inv_kine(middle_right,120-beta[4],10,leg-3);
	inv_kine(rear_left,60-beta[2],10,leg-3);
	inv_kine(rear_right,120+beta[5],7,leg);
	delay_ms(SPEED);

	//6
	inv_kine(front_left,60-beta[0],7,leg);
	inv_kine(front_right,120+beta[3],7,leg);
	inv_kine(middle_left,60+beta[1],7,leg);
	inv_kine(middle_right,120-beta[4],7,leg);
	inv_kine(rear_left,60-beta[2],7,leg);
	inv_kine(rear_right,120+beta[5],7,leg);
	delay_ms(SPEED);

}

void mov_askew_right_reverse(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Askew Right Movement \r");

	generate_movement_data(0,-5,9);
	delay_ms(150);
	//gait_mode(ASKEW_RIGHT, SPEED);
	//1
	inv_kine(front_left,120+beta[5],10,leg-3);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,120,7,leg);
	inv_kine(middle_right,60+beta[1],10,leg-3);
	inv_kine(rear_left,120+beta[3],10,leg-3);
	inv_kine(rear_right,60,7,leg);
	delay_ms(SPEED);

	//2
	inv_kine(front_left,120-beta[5],10,leg-3);
	inv_kine(front_right,60+beta[2],7,leg);
	inv_kine(middle_left,120+beta[4],7,leg);
	inv_kine(middle_right,60-beta[1],10,leg-3);
	inv_kine(rear_left,120-beta[3],10,leg-3);
	inv_kine(rear_right,60+beta[0],7,leg);
	delay_ms(SPEED);

	//3
	inv_kine(front_left,120-beta[5],7,leg);
	inv_kine(front_right,60+beta[2],7,leg);
	inv_kine(middle_left,120+beta[4],7,leg);
	inv_kine(middle_right,60-beta[1],7,leg);
	inv_kine(rear_left,120-beta[3],7,leg);
	inv_kine(rear_right,60+beta[0],7,leg);
	delay_ms(SPEED);

	//4
	inv_kine(front_left,120,7,leg);
	inv_kine(front_right,60+beta[2],10,leg-3);
	inv_kine(middle_left,120+beta[4],10,leg-3);
	inv_kine(middle_right,60,7,leg);
	inv_kine(rear_left,120,7,leg);
	inv_kine(rear_right,60+beta[0],10,leg-3);
	delay_ms(SPEED);

	//5
	inv_kine(front_left,120+beta[5],7,leg);
	inv_kine(front_right,60-beta[2],10,leg-3);
	inv_kine(middle_left,120-beta[4],10,leg-3);
	inv_kine(middle_right,60+beta[1],7,leg);
	inv_kine(rear_left,120+beta[3],7,leg);
	inv_kine(rear_right,60-beta[0],10,leg-3);
	delay_ms(SPEED);

	//6
	inv_kine(front_left,120+beta[5],7,leg);
	inv_kine(front_right,60-beta[2],7,leg);
	inv_kine(middle_left,120-beta[4],7,leg);
	inv_kine(middle_right,60+beta[1],7,leg);
	inv_kine(rear_left,120+beta[3],7,leg);
	inv_kine(rear_right,60-beta[0],7,leg);
	delay_ms(SPEED);

}

/*
 * Func : void mov_askew_left_transition(void)
 * Brief: Transition gait as preparatory stage for askew left locomotion
 * 		  transition using quadrupedal gait
 * Param: N/A
 * Written By: Ryan (Thursday, August 6th, 2015
 * Ver  : 1
 * Programmer's Note: This function MUST be called in mov_askew_left function
 */
void mov_askew_left_transition(void)
{
	Sendto_PC(USART1,"BW Askew Left transition \r");
	mov_static();
	delay_ms(100);

	/*
	 * pengurangan/penambahan 20: tiap sequence satu langkah defleksi 0.5 cm
	 * pengurangan/penambahan 40: terlalu extreme, body tengah justru yang berubah arah, mengganggu sensor ultrasonic
	 * transitions dengan tripod gait tidak stabil
	 * transition dengan tetrapo gait right handed, robot stabil
	 *
	 */
	//TRANSITION FROM STATIC GAIT HIGH CLEARANCE
	//USED GAIT: TETRAPOD/RIPPLE GAIT LEFT HANDED
	generate_movement_data(0,0,9);
	delay_ms(150);

	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90,7,leg);
	delay_ms(150);

	//PHASE 1 STARTED
	//2
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,60,10,leg-3);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,120,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(150);

	//PHASE 1 COMPLETED
	//3
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,120,7,leg);
	inv_kine(rear_right,90,7,leg);
	delay_ms(150);

	//PHASE 2 STARTED
	//4
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,120,10,leg-3);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,120,7,leg);
	inv_kine(rear_right,60,10,leg-3);
	delay_ms(150);

	//PHASE 2 COMPLETED
	//5
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,120,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,120,7,leg);
	inv_kine(rear_right,60,10,leg);
	delay_ms(150);

	//PHASE 3 STARTED
	//5
	inv_kine(front_left,120,10,leg-3);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,120,7,leg);
	inv_kine(middle_right,60,10,leg-3);
	inv_kine(rear_left,120,7,leg);
	inv_kine(rear_right,60,7,leg);
	delay_ms(150);

	//FINAL FORM
	inv_kine(front_left,120,7,leg);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,120,7,leg);
	inv_kine(middle_right,60,7,leg);
	inv_kine(rear_left,120,7,leg);
	inv_kine(rear_right,60,7,leg);
	delay_ms(150);
}

void mov_askew_left_transition_reverse(void)
{
	Sendto_PC(USART1,"BW Askew Left transition \r");
	mov_static();
	delay_ms(100);

	/*
	 * pengurangan/penambahan 20: tiap sequence satu langkah defleksi 0.5 cm
	 * pengurangan/penambahan 40: terlalu extreme, body tengah justru yang berubah arah, mengganggu sensor ultrasonic
	 * transitions dengan tripod gait tidak stabil
	 * transition dengan tetrapo gait right handed, robot stabil
	 *
	 */
	//TRANSITION FROM STATIC GAIT HIGH CLEARANCE
	//USED GAIT: TETRAPOD/RIPPLE GAIT LEFT HANDED
	generate_movement_data(0,0,9);
	delay_ms(150);

	//1
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90,7,leg);
	delay_ms(150);

	//PHASE 1 STARTED
	//2
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,120,10,leg-3);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,60,10,leg-3);
	inv_kine(rear_right,90,7,leg);
	delay_ms(150);

	//PHASE 1 COMPLETED
	//3
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,120,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,90,7,leg);
	delay_ms(150);

	//PHASE 2 STARTED
	//4
	inv_kine(front_left,60,10,leg-3);
	inv_kine(front_right,120,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,120,10,leg-3);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,90,7,leg);
	delay_ms(150);

	//PHASE 2 COMPLETED
	//5
	inv_kine(front_left,60,10,leg);
	inv_kine(front_right,120,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,120,7,leg);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,90,7,leg);
	delay_ms(150);

	//PHASE 3 STARTED
	//5
	inv_kine(front_left,60,7,leg);
	inv_kine(front_right,120,7,leg);
	inv_kine(middle_left,60,10,leg-3);
	inv_kine(middle_right,120,7,leg);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,120,10,leg-3);
	delay_ms(150);

	//FINAL FORM
	inv_kine(front_left,60,7,leg);
	inv_kine(front_right,120,7,leg);
	inv_kine(middle_left,60,7,leg);
	inv_kine(middle_right,120,7,leg);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,120,7,leg);
	delay_ms(150);
}

/*
 * Func: void mov_askew_left(int SPEED, int STEP)
 * brief: move robot's body in askew motion to the left
 * Every 10 cm translation to x coordinates, robot moves 1 cm to the left (y negative)
 * Written By: Ryan (MON, MARCH 9th, 2015)
 * Ver  : 2
 * Revised By: Ryan (Thursday, August 6th, 2015)
 * programmer's note  :
 */
void mov_askew_left(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Askew Left Movement \r");
	generate_movement_data(0,5,9);
	delay_ms(150);

	//gait_mode(ASKEW_LEFT, &SPEED);
	//1
	inv_kine(front_left,120,7,leg);
	inv_kine(front_right,60+beta[3],10,leg-3);
	inv_kine(middle_left,120+beta[1],10,leg-3);
	inv_kine(middle_right,60,7,leg);
	inv_kine(rear_left,120,7,leg);
	inv_kine(rear_right,60+beta[5],10,leg-3);
	delay_ms(SPEED);

	//2
	inv_kine(front_left,120+beta[0],7,leg);
	inv_kine(front_right,60-beta[3],10,leg-3);
	inv_kine(middle_left,120-beta[1],10,leg-3);
	inv_kine(middle_right,60+beta[4],7,leg);
	inv_kine(rear_left,120+beta[2],7,leg);
	inv_kine(rear_right,60-beta[5],10,leg-3);
	delay_ms(SPEED);

	//3
	inv_kine(front_left,120+beta[0],7,leg);
	inv_kine(front_right,60-beta[3],7,leg);
	inv_kine(middle_left,120-beta[1],7,leg);
	inv_kine(middle_right,60+beta[4],7,leg);
	inv_kine(rear_left,120+beta[2],7,leg);
	inv_kine(rear_right,60-beta[5],7,leg);
	delay_ms(SPEED);

	//4
	inv_kine(front_left,120+beta[0],10,leg-3);
	inv_kine(front_right,60,7,leg);
	inv_kine(middle_left,120,7,leg);
	inv_kine(middle_right,60+beta[4],10,leg-3);
	inv_kine(rear_left,120+beta[2],10,leg-3);
	inv_kine(rear_right,60,7,leg);
	delay_ms(SPEED);

	//5
	inv_kine(front_left,120-beta[0],10,leg-3);
	inv_kine(front_right,60+beta[3],7,leg);
	inv_kine(middle_left,120+beta[1],7,leg);
	inv_kine(middle_right,60-beta[4],10,leg-3);
	inv_kine(rear_left,120-beta[2],10,leg-3);
	inv_kine(rear_right,60+beta[5],7,leg);
	delay_ms(SPEED);

	//6
	inv_kine(front_left,120-beta[0],7,leg);
	inv_kine(front_right,60+beta[3],7,leg);
	inv_kine(middle_left,120+beta[1],7,leg);
	inv_kine(middle_right,60-beta[4],7,leg);
	inv_kine(rear_left,120-beta[2],7,leg);
	inv_kine(rear_right,60+beta[5],7,leg);
	delay_ms(SPEED);
}

void mov_askew_left_reverse(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Askew Left Movement \r");
	generate_movement_data(0,-5,9);
	delay_ms(150);

	//gait_mode(ASKEW_LEFT, &SPEED);
	//1
	inv_kine(front_left,60+beta[5],10,leg-3);
	inv_kine(front_right,120,7,leg);
	inv_kine(middle_left,60,7,leg);
	inv_kine(middle_right,120+beta[1],10,leg-3);
	inv_kine(rear_left,60+beta[3],10,leg-3);
	inv_kine(rear_right,120,7,leg);
	delay_ms(SPEED);

	//2
	inv_kine(front_left,60-beta[5],10,leg-3);
	inv_kine(front_right,120+beta[2],7,leg);
	inv_kine(middle_left,60+beta[4],7,leg);
	inv_kine(middle_right,120-beta[1],10,leg-3);
	inv_kine(rear_left,60-beta[3],10,leg-3);
	inv_kine(rear_right,120+beta[0],7,leg);
	delay_ms(SPEED);

	//3
	inv_kine(front_left,60-beta[5],7,leg);
	inv_kine(front_right,120+beta[2],7,leg);
	inv_kine(middle_left,60+beta[4],7,leg);
	inv_kine(middle_right,120-beta[1],7,leg);
	inv_kine(rear_left,60-beta[3],7,leg);
	inv_kine(rear_right,120+beta[0],7,leg);
	delay_ms(SPEED);

	//4
	inv_kine(front_left,60,7,leg);
	inv_kine(front_right,120+beta[2],10,leg-3);
	inv_kine(middle_left,60+beta[4],10,leg-3);
	inv_kine(middle_right,120,7,leg);
	inv_kine(rear_left,60,7,leg);
	inv_kine(rear_right,120+beta[0],10,leg-3);
	delay_ms(SPEED);

	//5
	inv_kine(front_left,60+beta[5],7,leg);
	inv_kine(front_right,120-beta[2],10,leg-3);
	inv_kine(middle_left,60-beta[4],10,leg-3);
	inv_kine(middle_right,120+beta[1],7,leg);
	inv_kine(rear_left,60+beta[3],7,leg);
	inv_kine(rear_right,120-beta[0],10,leg-3);
	delay_ms(SPEED);

	//6
	inv_kine(front_left,60+beta[5],7,leg);
	inv_kine(front_right,120-beta[2],7,leg);
	inv_kine(middle_left,60-beta[4],7,leg);
	inv_kine(middle_right,120+beta[1],7,leg);
	inv_kine(rear_left,60+beta[3],7,leg);
	inv_kine(rear_right,120-beta[0],7,leg);
	delay_ms(SPEED);
}

/*
 * Func: void mov_fwd_ripple_gait(int distance, int SPEED)
 * brief: hexapod forward locomotion using ripple gait/tetrapod gait
 * Written By: Ryan (TUE, MARCH 10th, 2015)
 * Revised By: Ryan (Tuesday, AUgust 4th, 2015)
 *
 */
void mov_fwd_ripple_gait(int SPEED)
{
	Sendto_PC(USART1,"BW Forward Ripple Gait \r");
	generate_movement_data(0,5,9);
	delay_ms(50);

	//gait_mode(FWD_RIPPLE, &SPEED);
	//PHASE 1 STARTED
	inv_kine(front_left,90-beta[0],10,leg-3); //MAJU ANGKAT
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4],7,leg); //REAR
	inv_kine(rear_left,90+beta[2],7,leg); //REAR
	inv_kine(rear_right,90-beta[5],10,leg-3); //MAJU ANGKAT
	delay_ms(SPEED);

	//PHASE 1
	inv_kine(front_left,90-beta[0],7,leg); //MAJU MENAPAK
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90+beta[4],7,leg); //REAR
	inv_kine(rear_left,90+beta[2],7,leg); //REAR
	inv_kine(rear_right,90-beta[5],7,leg); //MAJU MENAPAK
	delay_ms(SPEED);

	//PHASE 2 STARTED
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3],7,leg);//REAR
	inv_kine(middle_left,90+beta[1],7,leg);//REAR
	inv_kine(middle_right,90-beta[4],10,leg-3); //MAJU ANGKAT
	inv_kine(rear_left,90-beta[2],10,leg-3); //MAJU ANGKAT
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	//PHASE 2
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90+beta[3],7,leg);//REAR
	inv_kine(middle_left,90+beta[1],7,leg);//REAR
	inv_kine(middle_right,90-beta[4],7,leg); //MAJU MENAPAK
	inv_kine(rear_left,90-beta[2],7,leg); //MAJU MENAPAK
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	//PHASE 3 STARTED
	inv_kine(front_left,90+beta[0],8,leg);//REAR
	inv_kine(front_right,90-beta[3],10,leg-3); //MAJU ANGKAT
	inv_kine(middle_left,90-beta[1],10,leg-3); //MAJU ANGKAT
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],7,leg); //REAR
	delay_ms(SPEED);

	//PHASE 3 STARTED
	inv_kine(front_left,90+beta[0],7,leg);//REAR
	inv_kine(front_right,90-beta[3],7,leg); //MAJU MENAPAK
	inv_kine(middle_left,90-beta[1],7,leg); //MAJU MENAPAK
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],7,leg); //REAR
	delay_ms(SPEED);

}

void mov_fwd_ripple_gait_reverse(int SPEED)
{
	Sendto_PC(USART1,"BW Forward Ripple Gait \r");
	generate_movement_data(0,-5,9);
	delay_ms(50);

	//gait_mode(FWD_RIPPLE, &SPEED);
	//PHASE 1 STARTED
	inv_kine(front_left,90-beta[5],10,leg-3); //MAJU ANGKAT
	inv_kine(front_right,90+beta[2],7,leg); //REAR
	inv_kine(middle_left,90+beta[4],7,leg); //REAR
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90-beta[0],10,leg-3); //MAJU ANGKAT
	delay_ms(SPEED);

	//PHASE 1
	inv_kine(front_left,90-beta[5],7,leg); //MAJU MENAPAK
	inv_kine(front_right,90+beta[2],7,leg); //REAR
	inv_kine(middle_left,90+beta[4],7,leg); //REAR
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90-beta[0],7,leg); //MAJU MENAPAK
	delay_ms(SPEED);

	//PHASE 2 STARTED
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90-beta[2],10,leg-3); //MAJU ANGKAT
	inv_kine(middle_left,90-beta[4],10,leg-3); //MAJU ANGKAT
	inv_kine(middle_right,90+beta[1],7,leg);//REAR
	inv_kine(rear_left,90+beta[3],7,leg);//REAR
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	//PHASE 2
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90-beta[2],7,leg); //MAJU MENAPAK
	inv_kine(middle_left,90-beta[4],7,leg); //MAJU MENAPAK
	inv_kine(middle_right,90+beta[1],7,leg);//REAR
	inv_kine(rear_left,90+beta[3],7,leg);//REAR
	inv_kine(rear_right,90,7,leg);
	delay_ms(SPEED);

	//PHASE 3 STARTED
	inv_kine(front_left,90+beta[5],7,leg); //REAR
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90-beta[1],10,leg-3); //MAJU ANGKAT
	inv_kine(rear_left,90-beta[3],10,leg-3); //MAJU ANGKAT
	inv_kine(rear_right,90+beta[0],8,leg);//REAR
	delay_ms(SPEED);

	//PHASE 3 STARTED
	inv_kine(front_left,90+beta[5],7,leg); //REAR
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90-beta[1],7,leg); //MAJU MENAPAK
	inv_kine(rear_left,90-beta[3],7,leg); //MAJU MENAPAK
	inv_kine(rear_right,90+beta[0],7,leg);//REAR
	delay_ms(SPEED);

}

/*
 * Func: void mov_bwd_ripple_gait(int SPEED)
 * brief: hexapod forward locomotion using ripple gait/tetrapod gait
 * Written By: Ryan (TUE, MARCH 10th, 2015)
 * Revised By: Ryan (Tuesday, AUgust 4th, 2015)
 *
 */
void mov_bwd_ripple_gait(int SPEED)
{
	Sendto_PC(USART1,"BW Backward Ripple Gait \r");

	generate_movement_data(0,5,9);
	delay_ms(50);

	//PHASE 1
	inv_kine(front_left,90+beta[0]+5,7.5,leg); //MAJU MENAPAK
	inv_kine(front_right,90-beta[3]-5,7,leg); //REAR
	inv_kine(middle_left,90-beta[1]-5,8,leg); //REAR
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],7,leg); //MAJU MENAPAK
	delay_ms(250);

	//PHASE 2 STARTED
	inv_kine(front_left,90,7.5,leg);
	inv_kine(front_right,90+beta[3],7,leg-3); //MAJU-ANGKAT
	inv_kine(middle_left,90-beta[1]-5,8,leg); //REAR
	inv_kine(middle_right,90-beta[4],7,leg); //REAR
	inv_kine(rear_left,90-beta[2]-10,7,leg); //REAR
	inv_kine(rear_right,90,7,leg);
	delay_ms(250);

	//PHASE 2 MID
	inv_kine(front_left,90,7.5,leg);
	inv_kine(front_right,90+beta[3],7,leg); //MAJU-MENAPAK
	inv_kine(middle_left,90+beta[1]+5,8,leg-3); //MAJU-ANGKAT
	inv_kine(middle_right,90-beta[4],7,leg); //REAR
	inv_kine(rear_left,90-beta[2]-10,7,leg); //REAR
	inv_kine(rear_right,90,7,leg);
	delay_ms(250);

	//PHASE 2 END
	inv_kine(front_left,90,7.5,leg);
	inv_kine(front_right,90+beta[3],7,leg); //MAJU-MENAPAK
	inv_kine(middle_left,90+beta[1]+5,8,leg); //MAJU-MENAPAK
	inv_kine(middle_right,90-beta[4],7,leg); //REAR
	inv_kine(rear_left,90-beta[2]-10,7,leg); //REAR
	inv_kine(rear_right,90,7,leg);
	delay_ms(250);

	//PHASE 3 STARTED
	inv_kine(front_left,90-beta[0],7.5,leg); //REAR
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,8,leg);
	inv_kine(middle_right,90+beta[4],7,leg-3); //MAJU-ANGKAT
	inv_kine(rear_left,90-beta[2]-10,7,leg); //REAR
	inv_kine(rear_right,90-beta[5]-5,7.5,leg); //REAR
	delay_ms(250);

	//PHASE 3 MID
	inv_kine(front_left,90-beta[0],7.5,leg); //REAR
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,8,leg);
	inv_kine(middle_right,90+beta[4],7,leg); //MAJU-MENAPAK
	inv_kine(rear_left,90+beta[2]+10,7,leg-3); //MAJU-ANGKAT
	inv_kine(rear_right,90-beta[5]-5,7.5,leg); //REAR
	delay_ms(250);

	//PHASE 3 END
	inv_kine(front_left,90-beta[0],7.5,leg); //REAR
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,8,leg);
	inv_kine(middle_right,90+beta[4],7,leg); //MAJU-MENAPAK
	inv_kine(rear_left,90+beta[2]+10,7,leg); //MAJU-MENAPAK
	inv_kine(rear_right,90-beta[5]-5,7.5,leg); //REAR
	delay_ms(250);

	//PHASE 1 STARTED
	inv_kine(front_left,90-beta[0],7.5,leg); //REAR
	inv_kine(front_right,90-beta[3]-5,7,leg); //REAR
	inv_kine(middle_left,90-beta[1]-5,8,leg); //REAR
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],10,leg-3); //MAJU ANGKAT
	delay_ms(250);

	//PHASE 1 MID
	inv_kine(front_left,90+beta[0]+5,7.5,leg-3); //MAJU ANGKAT
	inv_kine(front_right,90-beta[3]-5,7,leg); //REAR
	inv_kine(middle_left,90-beta[1]-5,8,leg); //REAR
	inv_kine(middle_right,90,7,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90+beta[5],10,leg); //MAJU-MENAPAK
	delay_ms(250);

}

void mov_bwd_ripple_gait_reverse(int SPEED)
{
	Sendto_PC(USART1,"BW Backward Ripple Gait \r");

	generate_movement_data(0,-5,9);
	delay_ms(50);

	//PHASE 1
	inv_kine(front_left,90+beta[5],7,leg); //MAJU MENAPAK
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90-beta[1]-5,8,leg); //REAR
	inv_kine(rear_left,90-beta[3]-5,7,leg); //REAR
	inv_kine(rear_right,90+beta[0]+5,7.5,leg); //MAJU MENAPAK
	delay_ms(250);

	//PHASE 2 STARTED
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90-beta[2]-10,7,leg); //REAR
	inv_kine(middle_left,90-beta[4],7,leg); //REAR
	inv_kine(middle_right,90-beta[1]-5,8,leg); //REAR
	inv_kine(rear_left,90+beta[3],7,leg-3); //MAJU-ANGKAT
	inv_kine(rear_right,90,7.5,leg);
	delay_ms(250);

	//PHASE 2 MID
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90-beta[2]-10,7,leg); //REAR
	inv_kine(middle_left,90-beta[4],7,leg); //REAR
	inv_kine(middle_right,90+beta[1]+5,8,leg-3); //MAJU-ANGKAT
	inv_kine(rear_left,90+beta[3],7,leg); //MAJU-MENAPAK
	inv_kine(rear_right,90,7.5,leg);
	delay_ms(250);

	//PHASE 2 END
	inv_kine(front_left,90,7,leg);
	inv_kine(front_right,90-beta[2]-10,7,leg); //REAR
	inv_kine(middle_left,90-beta[4],7,leg); //REAR
	inv_kine(middle_right,90+beta[1]+5,8,leg); //MAJU-MENAPAK
	inv_kine(rear_left,90+beta[3],7,leg); //MAJU-MENAPAK
	inv_kine(rear_right,90,7.5,leg);
	delay_ms(250);

	//PHASE 3 STARTED
	inv_kine(front_left,90-beta[5]-5,7.5,leg); //REAR
	inv_kine(front_right,90-beta[2]-10,7,leg); //REAR
	inv_kine(middle_left,90+beta[4],7,leg-3); //MAJU-ANGKAT
	inv_kine(middle_right,90,8,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90-beta[0],7.5,leg); //REAR
	delay_ms(250);

	//PHASE 3 MID
	inv_kine(front_left,90-beta[5]-5,7.5,leg); //REAR
	inv_kine(front_right,90+beta[2]+10,7,leg-3); //MAJU-ANGKAT
	inv_kine(middle_left,90+beta[4],7,leg); //MAJU-MENAPAK
	inv_kine(middle_right,90,8,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90-beta[0],7.5,leg); //REAR
	delay_ms(250);

	//PHASE 3 END
	inv_kine(front_left,90-beta[5]-5,7.5,leg); //REAR
	inv_kine(front_right,90+beta[2]+10,7,leg); //MAJU-MENAPAK
	inv_kine(middle_left,90+beta[4],7,leg); //MAJU-MENAPAK
	inv_kine(middle_right,90,8,leg);
	inv_kine(rear_left,90,7,leg);
	inv_kine(rear_right,90-beta[0],7.5,leg); //REAR
	delay_ms(250);

	//PHASE 1 STARTED
	inv_kine(front_left,90+beta[5],10,leg-3); //MAJU ANGKAT
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90-beta[1]-5,8,leg); //REAR
	inv_kine(rear_left,90-beta[3]-5,7,leg); //REAR
	inv_kine(rear_right,90-beta[0],7.5,leg); //REAR
	delay_ms(250);

	//PHASE 1 MID
	inv_kine(front_left,90+beta[5],10,leg); //MAJU-MENAPAK
	inv_kine(front_right,90,7,leg);
	inv_kine(middle_left,90,7,leg);
	inv_kine(middle_right,90-beta[1]-5,8,leg); //REAR
	inv_kine(rear_left,90-beta[3]-5,7,leg); //REAR
	inv_kine(rear_right,90+beta[0]+5,7.5,leg-3); //MAJU ANGKAT
	delay_ms(250);

}

/*
 * Func: void mov_fwd_wave_gait(int SPEED)
 * brief: hexapod forward locomotion using wave gait (one leg at a time)
 * Written By: Ryan (TUE, August 4th, 2015)
 */
void mov_fwd_wave_gait(int SPEED)
{
	Sendto_PC(USART1,"BW Forward Wave Gait \r");
	generate_movement_data(0,10,9);
	delay_ms(50);

	//gait_mode(FWD_WAVE, &SPEED);
	//PHASE 1 STARTED
	inv_kine(front_left,90+beta[0],7,leg);
	inv_kine(front_right,90+beta[3],7,leg);
	inv_kine(middle_left,90+beta[1],7,leg);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 1
	inv_kine(front_left,90+beta[0],7,leg);
	inv_kine(front_right,90-beta[3],10,leg-3);
	inv_kine(middle_left,90+beta[1],7,leg);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 1
	inv_kine(front_left,90+beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90+beta[1]+5,7,leg);
	inv_kine(middle_right,90+beta[4],7,leg);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 2 STARTED
	inv_kine(front_left,90+beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90+beta[1],7,leg);
	inv_kine(middle_right,90-beta[4],10,leg-3);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 2
	inv_kine(front_left,90+beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90+beta[1],7,leg);
	inv_kine(middle_right,90-beta[4],7,leg);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90+beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 3 STARTED
	inv_kine(front_left,90+beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90+beta[1],7,leg);
	inv_kine(middle_right,90-beta[4],7,leg);
	inv_kine(rear_left,90+beta[2]+5,7,leg);
	inv_kine(rear_right,90-beta[5],10,leg-3);
	delay_ms(SPEED);

	//PHASE 3
	inv_kine(front_left,90+beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90+beta[1],7,leg);
	inv_kine(middle_right,90-beta[4],7,leg);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90-beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 4 STARTED
	inv_kine(front_left,90-beta[0],10,leg-3);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90+beta[1],7,leg);
	inv_kine(middle_right,90-beta[4],7,leg);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90-beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 4
	inv_kine(front_left,90-beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90+beta[1],7,leg);
	inv_kine(middle_right,90-beta[4],7,leg);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90-beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 5 STARTED
	inv_kine(front_left,90-beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90-beta[1],10,leg-3);
	inv_kine(middle_right,90-beta[4],7,leg);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90-beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 5
	inv_kine(front_left,90-beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90-beta[1],7,leg);
	inv_kine(middle_right,90-beta[4],7,leg);
	inv_kine(rear_left,90+beta[2],7,leg);
	inv_kine(rear_right,90-beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 6 STARTED
	inv_kine(front_left,90-beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90-beta[1],7,leg);
	inv_kine(middle_right,90-beta[4],7,leg);
	inv_kine(rear_left,90-beta[2],10,leg-3);
	inv_kine(rear_right,90-beta[5],7,leg);
	delay_ms(SPEED);

	//PHASE 6 STARTED
	inv_kine(front_left,90-beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg);
	inv_kine(middle_left,90-beta[1],7,leg);
	inv_kine(middle_right,90-beta[4],7,leg);
	inv_kine(rear_left,90-beta[2],7,leg);
	inv_kine(rear_right,90-beta[5],7,leg);
	delay_ms(SPEED);

}

void mov_fwd_wave_gait_reverse(int SPEED)
{
	Sendto_PC(USART1,"BW Forward Wave Gait \r");
	generate_movement_data(0,-10,9);
	delay_ms(50);

	//gait_mode(FWD_WAVE, &SPEED);
	//PHASE 1 STARTED
	inv_kine(front_left,90+beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90+beta[4],7,leg);
	inv_kine(middle_right,90+beta[1],7,leg);
	inv_kine(rear_left,90+beta[3],7,leg);
	inv_kine(rear_right,90+beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 1
	inv_kine(front_left,90+beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90+beta[4],7,leg);
	inv_kine(middle_right,90+beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],10,leg-3);
	inv_kine(rear_right,90+beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 1
	inv_kine(front_left,90+beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90+beta[4],7,leg);
	inv_kine(middle_right,90+beta[1]+5,7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90+beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 2 STARTED
	inv_kine(front_left,90+beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90-beta[4],10,leg-3);
	inv_kine(middle_right,90+beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90+beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 2
	inv_kine(front_left,90+beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90-beta[4],7,leg);
	inv_kine(middle_right,90+beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90+beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 3 STARTED
	inv_kine(front_left,90-beta[5],10,leg-3);
	inv_kine(front_right,90+beta[2]+5,7,leg);
	inv_kine(middle_left,90-beta[4],7,leg);
	inv_kine(middle_right,90+beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90+beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 3
	inv_kine(front_left,90-beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90-beta[4],7,leg);
	inv_kine(middle_right,90+beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90+beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 4 STARTED
	inv_kine(front_left,90-beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90-beta[4],7,leg);
	inv_kine(middle_right,90+beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90-beta[0],10,leg-3);
	delay_ms(SPEED);

	//PHASE 4
	inv_kine(front_left,90-beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90-beta[4],7,leg);
	inv_kine(middle_right,90+beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90-beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 5 STARTED
	inv_kine(front_left,90-beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90-beta[4],7,leg);
	inv_kine(middle_right,90-beta[1],10,leg-3);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90-beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 5
	inv_kine(front_left,90-beta[5],7,leg);
	inv_kine(front_right,90+beta[2],7,leg);
	inv_kine(middle_left,90-beta[4],7,leg);
	inv_kine(middle_right,90-beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90-beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 6 STARTED
	inv_kine(front_left,90-beta[5],7,leg);
	inv_kine(front_right,90-beta[2],10,leg-3);
	inv_kine(middle_left,90-beta[4],7,leg);
	inv_kine(middle_right,90-beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90-beta[0],7,leg);
	delay_ms(SPEED);

	//PHASE 6 STARTED
	inv_kine(front_left,90-beta[5],7,leg);
	inv_kine(front_right,90-beta[2],7,leg);
	inv_kine(middle_left,90-beta[4],7,leg);
	inv_kine(middle_right,90-beta[1],7,leg);
	inv_kine(rear_left,90-beta[3],7,leg);
	inv_kine(rear_right,90-beta[0],7,leg);
	delay_ms(SPEED);

}

void mov_celebrate(void)
{
	Sendto_PC(USART1,"BW Celebrate Movement \r");

	mov_static();
	delay_ms(1000);
	int counter=0;

	Sendto_PC(USART1,"BW Celebrate Movement \r");

	mov_static();
	delay_ms(1000);
	BW_Buzz(3);

	while(counter<=8)
	{
		counter++;

		BW_Buzz(1);

		mov_static();
		delay_ms(200);

		if(counter==1)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"FIREFIGHTING");lcd_putstr(lcd);
			lcd_gotoxy(4,2);sprintf(lcd,"SUCCESS!!!");lcd_putstr(lcd);
			lcd_gotoxy(3,3);sprintf(lcd,"BRAWIJAYA!!!");lcd_putstr(lcd);
			delay_ms(100);
		}
		else if(counter==2)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"KITA!");lcd_putstr(lcd);
			delay_ms(100);
		}
		else if(counter==3)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"KITA!");lcd_putstr(lcd);
			lcd_gotoxy(4,2);sprintf(lcd,"SATU!");lcd_putstr(lcd);
			delay_ms(100);
		}
		else if(counter==4)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"KITA!");lcd_putstr(lcd);
			lcd_gotoxy(4,2);sprintf(lcd,"SATU!");lcd_putstr(lcd);
			lcd_gotoxy(5,3);sprintf(lcd,"BRAWIJAYA!!!");lcd_putstr(lcd);
			delay_ms(50);
		}
		else if(counter==5)
		{
			lcd_display_clear();
			delay_ms(50);
		}
		else if(counter==6)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"KITA!");lcd_putstr(lcd);
			lcd_gotoxy(4,2);sprintf(lcd,"SATU!");lcd_putstr(lcd);
			lcd_gotoxy(5,3);sprintf(lcd,"BRAWIJAYA!!!");lcd_putstr(lcd);
			delay_ms(50);
		}
		else if(counter==7)
		{
			lcd_display_clear();
			delay_ms(50);
		}
		else if(counter==8)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
			lcd_gotoxy(0,1);sprintf(lcd,"KITA!");lcd_putstr(lcd);
			lcd_gotoxy(4,2);sprintf(lcd,"SATU!");lcd_putstr(lcd);
			lcd_gotoxy(5,3);sprintf(lcd,"BRAWIJAYA!!!");lcd_putstr(lcd);
			delay_ms(50);
		}
	}

	while(1)
	{
		mov_static();
		BW_Buzz(1);
	}

}

void mov_toggle_clearance(void)
{
    generate_movement_data(0,0,13);
    delay_ms(50);
    inv_kine(front_left,90,7,leg);
    inv_kine(front_right,90,7,leg);
    inv_kine(middle_left,90,7,leg);
    inv_kine(middle_right,90,7,leg);
    inv_kine(rear_left,90,7,leg);
    inv_kine(rear_right,90,7,leg);
    delay_ms(300);

}

/*
 * Func : void mov_deflect_right(int SPEED, int STEP)
 * Brief: Deflect to the right hexapod gait, moving 5 cm every step
 * Param: int SPEED (speed parameter), STEP (step parameter)
 * Written By: Ryan (Wednesday, August 26th, 2015
 * Ver  : 1
 * Programmer's Note:
 */
void mov_deflect_right(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Deflect Right Movement \r");
    generate_movement_data(0,5,9);
    delay_ms(50);

	inv_kine(front_left,90+beta[0],7,leg);
	inv_kine(front_right,90+beta[3],10,leg-3); //maju angkat
	inv_kine(middle_left,90,8,leg-1);
	inv_kine(middle_right,90,7,leg-1);
	inv_kine(rear_left,90+beta[2]+5,10,leg-3); //maju angkat
	inv_kine(rear_right,90+beta[5]+5,7,leg);
	delay_ms(SPEED);
//	delay_ms(500);

	inv_kine(front_left,90-beta[0],10,leg-3);
	inv_kine(front_right,90+beta[3],7,leg); //maju menapak
	inv_kine(middle_left,90,8,leg-1);
	inv_kine(middle_right,90,7,leg-1);
	inv_kine(rear_left,90+beta[2]+5,7,leg); //maju angkat
	inv_kine(rear_right,90-beta[5]-5,10,leg-3);
	delay_ms(SPEED);
//	delay_ms(500);

	inv_kine(front_left,90-beta[0],7,leg);
	inv_kine(front_right,90-beta[3],7,leg); //mundur
	inv_kine(middle_left,90,8,leg-1);
	inv_kine(middle_right,90,7,leg-1);
	inv_kine(rear_left,90-beta[2]-5,7,leg); //mundur
	inv_kine(rear_right,90-beta[5]-5,7,leg);
	delay_ms(SPEED);

}

void mov_deflect_right_reverse(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Deflect Right Movement \r");
    generate_movement_data(0,-5,9);
    delay_ms(50);

	inv_kine(front_left,90+beta[5]+5,7,leg);
	inv_kine(front_right,90+beta[2]+5,10,leg-3); //maju angkat
	inv_kine(middle_left,90,7,leg-1);
	inv_kine(middle_right,90,8,leg-1);
	inv_kine(rear_left,90+beta[3],10,leg-3); //maju angkat
	inv_kine(rear_right,90+beta[0],7,leg);
	delay_ms(SPEED);
//	delay_ms(500);

	inv_kine(front_left,90-beta[5]-5,10,leg-3);
	inv_kine(front_right,90+beta[2]+5,7,leg); //maju angkat
	inv_kine(middle_left,90,7,leg-1);
	inv_kine(middle_right,90,8,leg-1);
	inv_kine(rear_left,90+beta[3],7,leg); //maju menapak
	inv_kine(rear_right,90-beta[0],10,leg-3);
	delay_ms(SPEED);
//	delay_ms(500);

	inv_kine(front_left,90-beta[5]-5,7,leg);
	inv_kine(front_right,90-beta[2]-5,7,leg); //mundur
	inv_kine(middle_left,90,7,leg-1);
	inv_kine(middle_right,90,8,leg-1);
	inv_kine(rear_left,90-beta[3],7,leg); //mundur
	inv_kine(rear_right,90-beta[0],7,leg);
	delay_ms(SPEED);

}

/*
 * Func : void mov_deflect_left(int SPEED, int STEP)
 * Brief: Deflect to the left hexapod gait, moving 5 cm every step
 * Param: int SPEED (speed parameter), STEP (step parameter)
 * Written By: Ryan (Wednesday, August 26th, 2015
 * Ver  : 1
 * Programmer's Note:
 */
void mov_deflect_left(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Deflect Left Movement \r");
    generate_movement_data(0,5,9);
    delay_ms(50);

	inv_kine(front_left,90-beta[0],7,leg);
	inv_kine(front_right,90-beta[3],10,leg-3); //maju angkat
	inv_kine(middle_left,90,8,leg-1);
	inv_kine(middle_right,90,7,leg-1);
	inv_kine(rear_left,90-beta[2]-5,10,leg-3); //maju angkat
	inv_kine(rear_right,90-beta[5]-5,7,leg);
	delay_ms(SPEED);
//	delay_ms(500);

	inv_kine(front_left,90+beta[0],10,leg-3);
	inv_kine(front_right,90-beta[3],7,leg); //maju menapak
	inv_kine(middle_left,90,8,leg-1);
	inv_kine(middle_right,90,7,leg-1);
	inv_kine(rear_left,90-beta[2]-5,7,leg); //maju angkat
	inv_kine(rear_right,90+beta[5]+5,10,leg-3);
	delay_ms(SPEED);
//	delay_ms(500);

	inv_kine(front_left,90+beta[0],7,leg);
	inv_kine(front_right,90+beta[3],7,leg); //mundur
	inv_kine(middle_left,90,8,leg-1);
	inv_kine(middle_right,90,7,leg-1);
	inv_kine(rear_left,90+beta[2]+5,7,leg); //mundur
	inv_kine(rear_right,90+beta[5]+5,7,leg);
	delay_ms(SPEED);
//	delay_ms(500);

}

void mov_deflect_left_reverse(int SPEED, int STEP)
{
	Sendto_PC(USART1,"BW Deflect Left Movement \r");
    generate_movement_data(0,-5,9);
    delay_ms(50);

	inv_kine(front_left,90-beta[5]-5,7,leg);
	inv_kine(front_right,90-beta[2]-5,10,leg-3); //maju angkat
	inv_kine(middle_left,90,7,leg-1);
	inv_kine(middle_right,90,8,leg-1);
	inv_kine(rear_left,90-beta[3],10,leg-3); //maju angkat
	inv_kine(rear_right,90-beta[0],7,leg);
	delay_ms(SPEED);
//	delay_ms(500);

	inv_kine(front_left,90+beta[5]+5,10,leg-3);
	inv_kine(front_right,90-beta[2]-5,7,leg); //maju angkat
	inv_kine(middle_left,90,7,leg-1);
	inv_kine(middle_right,90,8,leg-1);
	inv_kine(rear_left,90-beta[3],7,leg); //maju menapak
	inv_kine(rear_right,90+beta[0],10,leg-3);
	delay_ms(SPEED);
//	delay_ms(500);

	inv_kine(front_left,90+beta[5]+5,7,leg);
	inv_kine(front_right,90+beta[2]+5,7,leg); //mundur
	inv_kine(middle_left,90,7,leg-1);
	inv_kine(middle_right,90,8,leg-1);
	inv_kine(rear_left,90+beta[3],7,leg); //mundur
	inv_kine(rear_right,90+beta[0],7,leg);
	delay_ms(SPEED);
//	delay_ms(500);

}

void PID_curve_right(int SPEED, int STEP, float *COMMAND_LOOP)
{
	int counter;
	//int limit= *COMMAND_LOOP;

	for(counter=1;counter<=*COMMAND_LOOP;counter++)
	{
		mov_curve_right(MED,FAR);
	}

}

void PID_curve_right_reverse(int SPEED, int STEP, float *COMMAND_LOOP)
{
	int counter;
	//int limit= *COMMAND_LOOP;

	for(counter=1;counter<=*COMMAND_LOOP;counter++)
	{
		mov_curve_right_reverse(MED,FAR);
	}

}

void PID_curve_left(int SPEED, int STEP, float *COMMAND_LOOP)
{
	int counter;
	//int limit= *COMMAND_LOOP;

	for(counter=1;counter<=*COMMAND_LOOP;counter++)
	{
		mov_curve_left(MED,FAR);
	}

}

void PID_curve_left_reverse(int SPEED, int STEP, float *COMMAND_LOOP)
{
	int counter;
	//int limit= *COMMAND_LOOP;

	for(counter=1;counter<=*COMMAND_LOOP;counter++)
	{
		mov_curve_left_reverse(MED,FAR);
	}

}

int BW_Calibration(void)
{

//	while(cmd_srv_fdbck==0){while(cmd_srv_fdbck==0){}};
	//while((cmd_srv_fdbck=!COMMAND_COMPLETED)){};
//	if ((cmd_srv_fdbck==COMMAND_COMPLETED)||(cmd_srv_fdbck==COMMAND_NOT_RECEIVED))
//	{
	    //cmd_srv_fdbck=0;
	    //Command_Gait(USART2,&COMMAND_FLAG_A); //<
	    //Command_Gait(USART2,&COMMAND_FLAG_B); //>
	    //Command_Gait(USART2,&); //
//	}
////	delay_ms(duration);
//		Sendto_PC(USART1,"Entering Calibration Mode \r");
//		Sendto_PC(USART1,"command_code[0]: %c \r",(char) command_code[0]);
//		Sendto_PC(USART1,"command_code[1]: %c \r",(char) command_code[1]);
//		Sendto_PC(USART1,"command_code[2]: %c \r",(char) command_code[2]);
//		Sendto_PC(USART1,"command_code[3]: %c \r",(char) command_code[3]);
//		Sendto_PC(USART1,"command_code[4]: %c \r",(char) command_code[4]);
    	switch(command_code[0])
    	{

    		case CMD_RUNTIME_CALIBRATION:
    			{
    				switch(command_code[1])
    				{

    					//FRONT LEFT LEG RUNTIME CALIBRATION
    					case FRONT_LEFT:
    					{

    						switch(command_code[2])
    						{

    							//FRONT LEFT COXA
    							case COXA:
    							{
    								switch(command_code[3])
    								{
    									case CAL_INCREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[0]+=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[0]+=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[0]+=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[0]+=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[0]+=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;

    									case CAL_DECREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[0]-=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[0]-=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[0]-=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[0]-=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[0]-=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;
    								}break;
    							}break;


    							//FRONT LEFT FEMUR
    							case FEMUR:
    							{
    								switch(command_code[3])
    								{
    									case CAL_INCREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[1]+=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[1]+=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[1]+=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[1]+=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[1]+=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;

    									case CAL_DECREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[1]-=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[1]-=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[1]-=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[1]-=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[1]-=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;
    								}break;
    							}break;


    							//FRONT LEFT TIBIA
    							case TIBIA:
    							{
    								switch(command_code[3])
    								{
    									case CAL_INCREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[2]+=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[2]+=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[2]+=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[2]+=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[2]+=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;

    									case CAL_DECREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[2]-=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[2]-=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[2]-=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[2]-=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[2]-=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;
    								}break;
    							}break;
    						} //end of switch
    					}break;



    					//MIDDLE LEFT LEG RUNTIME CALIBRATION
    					case MIDDLE_LEFT:
    					{

    						switch(command_code[2])
    						{

    							//MIDDLE LEFT COXA
    							case COXA:
    							{
    								switch(command_code[3])
    								{
    									case CAL_INCREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[3]+=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[3]+=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[3]+=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[3]+=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[3]+=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;

    									case CAL_DECREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[3]-=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[3]-=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[3]-=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[3]-=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[3]-=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;
    								}break;
    							}break;


    							//MIDDLE LEFT FEMUR
    							case FEMUR:
    							{
    								switch(command_code[3])
    								{
    									case CAL_INCREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[4]+=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[4]+=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[4]+=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[4]+=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[4]+=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;

    									case CAL_DECREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[4]-=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[4]-=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[4]-=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[4]-=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[4]-=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;
    								}break;
    							}break;


    							//MIDDLE LEFT TIBIA
    							case TIBIA:
    							{
    								switch(command_code[3])
    								{
    									case CAL_INCREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[5]+=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[5]+=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[5]+=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[5]+=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[5]+=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;

    									case CAL_DECREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[5]-=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[5]-=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[5]-=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[5]-=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[5]-=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;
    								}break;
    							}break;
    						} //end of switch
    					}break;




    					//REAR LEFT LEG RUNTIME CALIBRATION
    					case REAR_LEFT:
    					{

    						switch(command_code[2])
    						{

    							//REAR LEFT COXA
    							case COXA:
    							{
    								switch(command_code[3])
    								{
    									case CAL_INCREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[6]+=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[6]+=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[6]+=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[6]+=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[6]+=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;

    									case CAL_DECREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[6]-=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[6]-=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[6]-=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[6]-=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[6]-=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;
    								}break;
    							}break;


    							//REAR LEFT FEMUR
    							case FEMUR:
    							{
    								switch(command_code[3])
    								{
    									case CAL_INCREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[7]+=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[7]+=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[7]+=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[7]+=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[7]+=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;

    									case CAL_DECREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[7]-=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[7]-=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[7]-=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[7]-=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[7]-=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;
    								}break;
    							}break;


    							//REAR LEFT TIBIA
    							case TIBIA:
    							{
    								switch(command_code[3])
    								{
    									case CAL_INCREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[8]+=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[8]+=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[8]+=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[8]+=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[8]+=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;

    									case CAL_DECREMENT:
    										{
    											switch(command_code[4])
    											{
    												case ONE  : {correct[8]-=1; CMD_RESET;delay_ms(50);break;}
    												case TWO  : {correct[8]-=2; CMD_RESET;delay_ms(50);break;}
    												case THREE: {correct[8]-=3; CMD_RESET;delay_ms(50);break;}
    												case FOUR : {correct[8]-=4; CMD_RESET;delay_ms(50);break;}
    												case FIVE : {correct[8]-=5; CMD_RESET;delay_ms(50);break;}
    											}
    										}break;
    								}break;
    							}break;
    						}//end of switch
    					}break;


    	    					//FRONT RIGHT LEG RUNTIME CALIBRATION
    	    					case FRONT_RIGHT:
    	    					{

    	    						switch(command_code[2])
    	    						{

    	    							//FRONT RIGHT COXA
    	    							case COXA:
    	    							{
    	    								switch(command_code[3])
    	    								{
    	    									case CAL_INCREMENT:
    	    										{
    	    											switch(command_code[4])
    	    											{
    	    												case ONE  : {correct[9]+=1; CMD_RESET;delay_ms(50);break;}
    	    												case TWO  : {correct[9]+=2; CMD_RESET;delay_ms(50);break;}
    	    												case THREE: {correct[9]+=3; CMD_RESET;delay_ms(50);break;}
    	    												case FOUR : {correct[9]+=4; CMD_RESET;delay_ms(50);break;}
    	    												case FIVE : {correct[9]+=5; CMD_RESET;delay_ms(50);break;}
    	    											}
    	    										}break;

    	    									case CAL_DECREMENT:
    	    										{
    	    											switch(command_code[4])
    	    											{
    	    												case ONE  : {correct[9]-=1; CMD_RESET;delay_ms(50);break;}
    	    												case TWO  : {correct[9]-=2; CMD_RESET;delay_ms(50);break;}
    	    												case THREE: {correct[9]-=3; CMD_RESET;delay_ms(50);break;}
    	    												case FOUR : {correct[9]-=4; CMD_RESET;delay_ms(50);break;}
    	    												case FIVE : {correct[9]-=5; CMD_RESET;delay_ms(50);break;}
    	    											}
    	    										}break;
    	    								}break;
    	    							}break;


    	    							//FRONT RIGHT FEMUR
    	    							case FEMUR:
    	    							{
    	    								switch(command_code[3])
    	    								{
    	    									case CAL_INCREMENT:
    	    										{
    	    											switch(command_code[4])
    	    											{
    	    												case ONE  : {correct[10]+=1; CMD_RESET;delay_ms(50);break;}
    	    												case TWO  : {correct[10]+=2; CMD_RESET;delay_ms(50);break;}
    	    												case THREE: {correct[10]+=3; CMD_RESET;delay_ms(50);break;}
    	    												case FOUR : {correct[10]+=4; CMD_RESET;delay_ms(50);break;}
    	    												case FIVE : {correct[10]+=5; CMD_RESET;delay_ms(50);break;}
    	    											}
    	    										}break;

    	    									case CAL_DECREMENT:
    	    										{
    	    											switch(command_code[4])
    	    											{
    	    												case ONE  : {correct[10]-=1; CMD_RESET;delay_ms(50);break;}
    	    												case TWO  : {correct[10]-=2; CMD_RESET;delay_ms(50);break;}
    	    												case THREE: {correct[10]-=3; CMD_RESET;delay_ms(50);break;}
    	    												case FOUR : {correct[10]-=4; CMD_RESET;delay_ms(50);break;}
    	    												case FIVE : {correct[10]-=5; CMD_RESET;;delay_ms(50);break;}
    	    											}
    	    										}break;
    	    								}break;
    	    							}break;


    	    							//FRONT RIGHT TIBIA
    	    							case TIBIA:
    	    							{
    	    								switch(command_code[3])
    	    								{
    	    									case CAL_INCREMENT:
    	    										{
    	    											switch(command_code[4])
    	    											{
    	    												case ONE  : {correct[11]+=1; CMD_RESET;delay_ms(50);break;}
    	    												case TWO  : {correct[11]+=2; CMD_RESET;delay_ms(50);break;}
    	    												case THREE: {correct[11]+=3; CMD_RESET;delay_ms(50);break;}
    	    												case FOUR : {correct[11]+=4; CMD_RESET;delay_ms(50);break;}
    	    												case FIVE : {correct[11]+=5; CMD_RESET;delay_ms(50);break;}
    	    											}
    	    										}break;

    	    									case CAL_DECREMENT:
    	    										{
    	    											switch(command_code[4])
    	    											{
    	    												case ONE  : {correct[11]-=1; CMD_RESET;delay_ms(50);break;}
    	    												case TWO  : {correct[11]-=2; CMD_RESET;delay_ms(50);break;}
    	    												case THREE: {correct[11]-=3; CMD_RESET;delay_ms(50);break;}
    	    												case FOUR : {correct[11]-=4; CMD_RESET;delay_ms(50);break;}
    	    												case FIVE : {correct[11]-=5; CMD_RESET;delay_ms(50);break;}
    	    											}
    	    										}break;
    	    								}break;
    	    							}break;
    	    						}//end of switch
    	    					}break;



    	    	    					//MIDDLE RIGHT LEG RUNTIME CALIBRATION
    	    	    					case MIDDLE_RIGHT:
    	    	    					{

    	    	    						switch(command_code[2])
    	    	    						{

    	    	    							//MIDDLE RIGHT COXA
    	    	    							case COXA:
    	    	    							{
    	    	    								switch(command_code[3])
    	    	    								{
    	    	    									case CAL_INCREMENT:
    	    	    										{
    	    	    											switch(command_code[4])
    	    	    											{
    	    	    												case ONE  : {correct[12]+=1; CMD_RESET;delay_ms(50);break;}
    	    	    												case TWO  : {correct[12]+=2; CMD_RESET;delay_ms(50);break;}
    	    	    												case THREE: {correct[12]+=3; CMD_RESET;delay_ms(50);break;}
    	    	    												case FOUR : {correct[12]+=4; CMD_RESET;delay_ms(50);break;}
    	    	    												case FIVE : {correct[12]+=5; CMD_RESET;delay_ms(50);break;}
    	    	    											}
    	    	    										}break;

    	    	    									case CAL_DECREMENT:
    	    	    										{
    	    	    											switch(command_code[4])
    	    	    											{
    	    	    												case ONE  : {correct[12]-=1; CMD_RESET;delay_ms(50);break;}
    	    	    												case TWO  : {correct[12]-=2; CMD_RESET;delay_ms(50);break;}
    	    	    												case THREE: {correct[12]-=3; CMD_RESET;delay_ms(50);break;}
    	    	    												case FOUR : {correct[12]-=4; CMD_RESET;delay_ms(50);break;}
    	    	    												case FIVE : {correct[12]-=5; CMD_RESET;delay_ms(50);break;}
    	    	    											}
    	    	    										}break;
    	    	    								}break;
    	    	    							}break;


    	    	    							//MIDDLE RIGHT FEMUR
    	    	    							case FEMUR:
    	    	    							{
    	    	    								switch(command_code[3])
    	    	    								{
    	    	    									case CAL_INCREMENT:
    	    	    										{
    	    	    											switch(command_code[4])
    	    	    											{
    	    	    												case ONE  : {correct[13]+=1; CMD_RESET;delay_ms(50);break;}
    	    	    												case TWO  : {correct[13]+=2; CMD_RESET;delay_ms(50);break;}
    	    	    												case THREE: {correct[13]+=3; CMD_RESET;delay_ms(50);break;}
    	    	    												case FOUR : {correct[13]+=4; CMD_RESET;delay_ms(50);break;}
    	    	    												case FIVE : {correct[13]+=5; CMD_RESET;delay_ms(50);break;}
    	    	    											}
    	    	    										}break;

    	    	    									case CAL_DECREMENT:
    	    	    										{
    	    	    											switch(command_code[4])
    	    	    											{
    	    	    												case ONE  : {correct[13]-=1; CMD_RESET;delay_ms(50);break;}
    	    	    												case TWO  : {correct[13]-=2; CMD_RESET;delay_ms(50);break;}
    	    	    												case THREE: {correct[13]-=3; CMD_RESET;delay_ms(50);break;}
    	    	    												case FOUR : {correct[13]-=4; CMD_RESET;delay_ms(50);break;}
    	    	    												case FIVE : {correct[13]-=5; CMD_RESET;delay_ms(50);break;}
    	    	    											}
    	    	    										}break;
    	    	    								}break;
    	    	    							}break;


    	    	    							//MIDDLE RIGHT TIBIA
    	    	    							case TIBIA:
    	    	    							{
    	    	    								switch(command_code[3])
    	    	    								{
    	    	    									case CAL_INCREMENT:
    	    	    										{
    	    	    											switch(command_code[4])
    	    	    											{
    	    	    												case ONE  : {correct[14]+=1; CMD_RESET;delay_ms(50);break;}
    	    	    												case TWO  : {correct[14]+=2; CMD_RESET;delay_ms(50);break;}
    	    	    												case THREE: {correct[14]+=3; CMD_RESET;delay_ms(50);break;}
    	    	    												case FOUR : {correct[14]+=4; CMD_RESET;delay_ms(50);break;}
    	    	    												case FIVE : {correct[14]+=5; CMD_RESET;delay_ms(50);break;}
    	    	    											}
    	    	    										}break;

    	    	    									case CAL_DECREMENT:
    	    	    										{
    	    	    											switch(command_code[4])
    	    	    											{
    	    	    												case ONE  : {correct[14]-=1; CMD_RESET;delay_ms(50);break;}
    	    	    												case TWO  : {correct[14]-=2; CMD_RESET;delay_ms(50);break;}
    	    	    												case THREE: {correct[14]-=3; CMD_RESET;delay_ms(50);break;}
    	    	    												case FOUR : {correct[14]-=4; CMD_RESET;delay_ms(50);break;}
    	    	    												case FIVE : {correct[14]-=5; CMD_RESET;delay_ms(50);break;}
    	    	    											}
    	    	    										}break;
    	    	    								}break;
    	    	    							}break;
    	    	    						}//end of switch
    	    	    					}break;




    	    	    	    					//REAR RIGHT LEG RUNTIME CALIBRATION
    	    	    	    					case REAR_RIGHT:
    	    	    	    					{

    	    	    	    						switch(command_code[2])
    	    	    	    						{

    	    	    	    							//REAR RIGHT COXA
    	    	    	    							case COXA:
    	    	    	    							{
    	    	    	    								switch(command_code[3])
    	    	    	    								{
    	    	    	    									case CAL_INCREMENT:
    	    	    	    										{
    	    	    	    											switch(command_code[4])
    	    	    	    											{
    	    	    	    												case ONE  : {correct[15]+=1; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case TWO  : {correct[15]+=2; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case THREE: {correct[15]+=3; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FOUR : {correct[15]+=4; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FIVE : {correct[15]+=5; CMD_RESET;delay_ms(50);break;}
    	    	    	    											}
    	    	    	    										}break;

    	    	    	    									case CAL_DECREMENT:
    	    	    	    										{
    	    	    	    											switch(command_code[4])
    	    	    	    											{
    	    	    	    												case ONE  : {correct[15]-=1; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case TWO  : {correct[15]-=2; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case THREE: {correct[15]-=3; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FOUR : {correct[15]-=4; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FIVE : {correct[15]-=5; CMD_RESET;delay_ms(50);break;}
    	    	    	    											}
    	    	    	    										}break;
    	    	    	    								}break;
    	    	    	    							}break;


    	    	    	    							//REAR RIGHT FEMUR
    	    	    	    							case FEMUR:
    	    	    	    							{
    	    	    	    								switch(command_code[3])
    	    	    	    								{
    	    	    	    									case CAL_INCREMENT:
    	    	    	    										{
    	    	    	    											switch(command_code[4])
    	    	    	    											{
    	    	    	    												case ONE  : {correct[16]+=1; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case TWO  : {correct[16]+=2; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case THREE: {correct[16]+=3; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FOUR : {correct[16]+=4; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FIVE : {correct[16]+=5; CMD_RESET;delay_ms(50);break;}
    	    	    	    											}
    	    	    	    										}break;

    	    	    	    									case CAL_DECREMENT:
    	    	    	    										{
    	    	    	    											switch(command_code[4])
    	    	    	    											{
    	    	    	    												case ONE  : {correct[16]-=1; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case TWO  : {correct[16]-=2; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case THREE: {correct[16]-=3; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FOUR : {correct[16]-=4; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FIVE : {correct[16]-=5; CMD_RESET;delay_ms(50);break;}
    	    	    	    											}
    	    	    	    										}break;
    	    	    	    								}break;
    	    	    	    							}break;


    	    	    	    							//REAR RIGHT TIBIA
    	    	    	    							case TIBIA:
    	    	    	    							{
    	    	    	    								switch(command_code[3])
    	    	    	    								{
    	    	    	    									case CAL_INCREMENT:
    	    	    	    										{
    	    	    	    											switch(command_code[4])
    	    	    	    											{
    	    	    	    												case ONE  : {correct[17]+=1; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case TWO  : {correct[17]+=2; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case THREE: {correct[17]+=3; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FOUR : {correct[17]+=4; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FIVE : {correct[17]+=5; CMD_RESET;delay_ms(50);break;}
    	    	    	    											}
    	    	    	    										}break;

    	    	    	    									case CAL_DECREMENT:
    	    	    	    										{
    	    	    	    											switch(command_code[4])
    	    	    	    											{
    	    	    	    												case ONE  : {correct[17]-=1; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case TWO  : {correct[17]-=2; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case THREE: {correct[17]-=3; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FOUR : {correct[17]-=4; CMD_RESET;delay_ms(50);break;}
    	    	    	    												case FIVE : {correct[17]-=5; CMD_RESET;delay_ms(50);break;}
    	    	    	    											}
    	    	    	    										}break;
    	    	    	    								}break;
    	    	    	    							}break;
    	    	    	    						}//end of switch
    	    	    	    					}break;

    						} //end of switch statement command_code[1]
    					}break;

    					case CMD_SHOW_CALIBRATION:
    					{
    			    		Sendto_PC(USART1,"FRONT LEFT COXA: %d ",(int) correct[0]);
    			    		Sendto_PC(USART1,"FRONT LEFT FEMUR: %d ",(int)correct[1]);
    			    		Sendto_PC(USART1,"FRONT LEFT TIBIA: %d \r\r",(int)correct[2]);

    			    		Sendto_PC(USART1,"MIDDLE LEFT COXA: %d ",(int)correct[3]);
    			    		Sendto_PC(USART1,"MIDDLE LEFT FEMUR: %d ",(int)correct[4]);
    			    		Sendto_PC(USART1,"MIDDLE LEFT TIBIA: %d \r\r",(int)correct[5]);

    			    		Sendto_PC(USART1,"REAR LEFT COXA: %d ",(int)correct[6]);
    			    		Sendto_PC(USART1,"REAR LEFT FEMUR: %d ",(int)correct[7]);
    			    		Sendto_PC(USART1,"REAR LEFT TIBIA: %d \r\r",(int)correct[8]);

    			    		Sendto_PC(USART1,"FRONT RIGHT COXA: %d ",(int)correct[9]);
    			    		Sendto_PC(USART1,"FRONT RIGHT FEMUR: %d ",(int)correct[10]);
    			    		Sendto_PC(USART1,"FRONT RIGHT TIBIA: %d \r\r",(int)correct[11]);

    			    		Sendto_PC(USART1,"MIDDLE RIGHT COXA: %d ",(int)correct[12]);
    			    		Sendto_PC(USART1,"MIDDLE RIGHT FEMUR: %d ",(int)correct[13]);
    			    		Sendto_PC(USART1,"MIDDLE RIGHT TIBIA: %d \r\r",(int)correct[14]);

    			    		Sendto_PC(USART1,"REAR RIGHT COXA: %d ",(int)correct[15]);
    			    		Sendto_PC(USART1,"REAR RIGHT FEMUR: %d ",(int)correct[16]);
    			    		Sendto_PC(USART1,"REAR RIGHT TIBIA: %d \r\r",(int)correct[17]);
    						CMD_RESET;
    					}break;

    					case CMD_SIDE_CALIBRATION:
    					{
    						Sendto_PC(USART1,"CMD_SIDE_CALIBRATION");
    						correct[0]=122;
    						correct[3]=10;
    						correct[6]=-82;
    						correct[9]=131;
    						correct[12]=-15;
    						correct[15]=-82;
    						mov_static();
    						delay_ms(100);
    						CMD_RESET;
    					}break;

    					case CMD_REAR_CALIBRATION:
    					{
    						Sendto_PC(USART1,"CMD_FRONT_CALIBRATION");
    						correct[0]=-24;
    						correct[9]=-48;
    						mov_static();
    						delay_ms(100);
    						CMD_RESET;
    					}break;

    					case CMD_NORMAL_CALIBRATION:
    					{
    						Sendto_PC(USART1,"CMD_NORMAL_CALIBRATION");
    						correct[0]=48;
    						correct[3]=17;
    						correct[6]=-34;
    						correct[9]=31;
    						correct[12]=-15;
    						correct[15]=-1;
    						mov_static();
    						delay_ms(100);
    						CMD_RESET;
    					}break;

    					case CMD_DRIVETEST_STATIC:
    					{
    						Sendto_PC(USART1,"CMD_DRIVETEST_STATIC \r");
    						Sendto_PC(USART1,"CALIBRATION_STAT: %d \r",CALIBRATION_STAT);
    						CMD_RESET;
    						CALIBRATION_STAT= 1;
    					}break;

    					case CMD_DRIVETEST_FWD:
    					{
    						Sendto_PC(USART1,"CMD_DRIVETEST_FWD \r");
    						Sendto_PC(USART1,"CALIBRATION_STAT: %d \r",CALIBRATION_STAT);
    						CMD_RESET;
    						CALIBRATION_STAT= 2;
    					}break;

    					case CMD_DRIVETEST_BWD:
    					{
    						Sendto_PC(USART1,"CMD_DRIVETEST_BWD \r");
    						Sendto_PC(USART1,"CALIBRATION_STAT: %d \r",CALIBRATION_STAT);
    						CMD_RESET;
    						CALIBRATION_STAT= 3;
    					}break;
    			} //end of switch statement command_code[0]
    return 1;
} //end of BW_Calibration function


void CMD_ACTUATE(void)
{
	switch(CALIBRATION_STAT)
	{
		case 1:
		{
			mov_static();
			delay_ms(100);
		}break;

		case 2:
		{
			mov_fwd_5cm(10,FAST_LEVEL_3);
			delay_ms(100);
		}break;

		case 3:
		{
			mov_bwd(10,MED);
			delay_ms(100);
		}break;

		default: break;
	}
}


void INV_KINE_TEST(void)
{
//    generate_movement_data(0,0,10);
//    delay_ms(50);

//    inv_kine(rear_right,90,7,10);
//    delay_ms(2000);

//    generate_movement_data(0,5,10);
//    Sendto_PC(USART1,"beta[5]: %d \r",(int) beta[5]);
//    Sendto_PC(USART1,"leg_next[5]: %d \r",(int) leg_next[5]);



//
//	inv_kine(rear_right,90+beta[5],10,leg-3);
//	delay_ms(200);
//
//	inv_kine(rear_right,90-beta[5],10,leg-3);
//	delay_ms(200);
//
//	inv_kine(rear_right,90-beta[5],7,leg);
//	delay_ms(200);
//
//	inv_kine(rear_right,90,7,leg);
//	delay_ms(200);
//
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(200);
//
//	inv_kine(rear_right,90+beta[5],7,leg);
//	delay_ms(200);

//    //belakang angkat
//	inv_kine(rear_right,90+beta[5],leg_next[5],9);
//	delay_ms(200);
//
//	//maju angkat
//	inv_kine(rear_right,90-beta[5],leg_next[5],9);
//	delay_ms(200);
//
//	//maju menapak
//	inv_kine(rear_right,90-beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	//tengah menapak
//	inv_kine(rear_right,90,leg_next[5],10);
//	delay_ms(200);
//
//	//belakang menapak
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);

	//belakang menapak
//	inv_kine(rear_right,90+beta[5],leg_next[5],8);
//	delay_ms(500);
//
//	inv_kine(rear_right,90+beta[5],leg_next[5],9);
//	delay_ms(500);

//    generate_movement_data(0,5,10);
//	inv_kine(rear_right,90+beta[5],leg_next[5]-2,11);
//	delay_ms(500);
    float CLR;

    for (CLR=8;CLR<=10;CLR+=0.1)
    {
        generate_movement_data(0,0,CLR);
//        inv_kine(front_left,90,leg_next[0],CLR);
//        inv_kine(front_right,90,leg_next[3],CLR);
//        inv_kine(middle_left,90,leg_next[1],CLR);
//        inv_kine(middle_right,90,leg_next[4],CLR);
//        inv_kine(rear_left,90,leg_next[2],CLR);
//    	inv_kine(rear_right,90+beta[5],leg_next[5],CLR);
        inv_kine(front_left,90,7,CLR);
        inv_kine(front_right,90,7,CLR);
        inv_kine(middle_left,90,7,CLR);
        inv_kine(middle_right,90,7,CLR);
        inv_kine(rear_left,90,7,CLR);
    	inv_kine(rear_right,90,7,CLR);
    	delay_ms(30);
    }

//    for (CLR=10;CLR>=8;CLR-=0.1)
//    {
//        generate_movement_data(0,0,CLR);
////        inv_kine(front_left,90,leg_next[0],CLR);
////        inv_kine(front_right,90,leg_next[3],CLR);
////        inv_kine(middle_left,90,leg_next[1],CLR);
////        inv_kine(middle_right,90,leg_next[4],CLR);
////        inv_kine(rear_left,90,leg_next[2],CLR);
////    	inv_kine(rear_right,90,leg_next[5],CLR);
//        inv_kine(front_left,90,7-CLR,CLR);
//        inv_kine(front_right,90,7-CLR,CLR);
//        inv_kine(middle_left,90,7-CLR,CLR);
//        inv_kine(middle_right,90,7-CLR,CLR);
//        inv_kine(rear_left,90,7-CLR,CLR);
//    	inv_kine(rear_right,90,7-CLR,CLR);
//    	delay_ms(30);
//    }

//    generate_movement_data(0,5,10);
//    Sendto_PC(USART1,"leg_next[0]: %d \r",(int) leg_next[0]);
//    Sendto_PC(USART1,"leg_next[3]: %d \r",(int) leg_next[3]);
//    Sendto_PC(USART1,"leg_next[1]: %d \r",(int) leg_next[1]);
//    Sendto_PC(USART1,"leg_next[4]: %d \r",(int) leg_next[4]);
//    Sendto_PC(USART1,"leg_next[2]: %d \r",(int) leg_next[2]);
//    Sendto_PC(USART1,"leg_next[5]: %d \r",(int) leg_next[5]);

//    inv_kine(front_left,90,leg_next[0],10);
//    inv_kine(front_right,90,leg_next[3],10);
//    inv_kine(middle_left,90,leg_next[1],10);
//    inv_kine(middle_right,90,leg_next[4],10);
//    inv_kine(rear_left,90,leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);

    /*
     * HALF BAD
     */
//	inv_kine(front_left,90,7,10);
//	inv_kine(front_right,90+beta[3],leg_next[3]+3,7);
//	inv_kine(middle_left,90+beta[1],leg_next[1]+3,7);
//	inv_kine(middle_right,90,7,10);
//	inv_kine(rear_left,90,7,10);
//	inv_kine(rear_right,90+beta[5],leg_next[5]+3,7);
//	delay_ms(150);
//
//	//BW_Tracer_Check();
//	//2
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90-beta[3],leg_next[3]+3,7);
//	inv_kine(middle_left,90-beta[1],leg_next[1]+3,7);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90-beta[5],leg_next[5]+3,7);
//	delay_ms(150);
//
//	//BW_Tracer_Check();
//	//3
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90-beta[3],7,10);
//	inv_kine(middle_left,90-beta[1],7,10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90-beta[5],7,10);
//	delay_ms(150);
//
//	//BW_Tracer_Check();
//	//4
//	inv_kine(front_left,90+beta[0],leg_next[0]+3,7);
//	inv_kine(front_right,90,7,10);
//	inv_kine(middle_left,90,7,10);
//	inv_kine(middle_right,90+beta[4],leg_next[4]+3,7);
//	inv_kine(rear_left,90+beta[2],leg_next[2]+3,7);
//	inv_kine(rear_right,90,7,10);
//	delay_ms(150);
//
//	//BW_Tracer_Check();
//	//5
//	inv_kine(front_left,90-beta[0],leg_next[0]+3,7);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90-beta[4],leg_next[4]+3,7);
//	inv_kine(rear_left,90-beta[2],leg_next[2]+3,7);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(150);
//
//	//BW_Tracer_Check();
//	//6
//	inv_kine(front_left,90-beta[0],7,10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90-beta[4],7,10);
//	inv_kine(rear_left,90-beta[2],7,10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(150);
//
//	/*
//	 *
//	 */
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90,7,9);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	//belakang kiri
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90,7,10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90,7,9);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	//menapak
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90,7,10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	//depan kanan
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90,7,9);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	//tengah kiri
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90,7,10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90,7,9);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	//menapak
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90,7,10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	//belakang kanan
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90,7,9);
//	delay_ms(200);
//
//	//depan kiri
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90,7,10);
//	delay_ms(200);
//
//	inv_kine(front_left,90,7,9);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	//menapak
//	inv_kine(front_left,90,7,10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//
//	//tengah kanan
//	inv_kine(front_left,90+beta[0],leg_next[0],10);
//	inv_kine(front_right,90+beta[3],leg_next[3],10);
//	inv_kine(middle_left,90+beta[1],leg_next[1],10);
//	inv_kine(middle_right,90+beta[4],leg_next[4],10);
//	inv_kine(rear_left,90+beta[2],leg_next[2],10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);
//	delay_ms(100);
//    mov_static();
	//    generate_movement_data(0,5,12);
//    inv_kine(middle_left,90,leg_next[1]+1,11);
//    inv_kine(front_left,90,leg_next[0]+5,10);
//    inv_kine(front_right,90,leg_next[3]+1,11);
//    inv_kine(middle_left,90,leg_next[1]+1,11);
//    inv_kine(middle_right,90,leg_next[4]+1,11);
//    inv_kine(rear_left,90,leg_next[2]+1,11);
//    inv_kine(rear_right,90,leg_next[5]+1,11);
//    delay_ms(500);

//    inv_kine(middle_left,90,leg_next[1]+2,11);
//    delay_ms(500);
//    inv_kine(middle_left,90,leg_next[1]-2,12);
//    delay_ms(500);

//    generate_movement_data(0,5,8);
//    inv_kine(front_left,90,7,9);


//    generate_movement_data(0,5,8);
//	inv_kine(rear_right,90+beta[5],leg_next[5],8);
//	delay_ms(500);
//
//    generate_movement_data(0,5,9);
//	inv_kine(rear_right,90+beta[5],leg_next[5],9);
//	delay_ms(500);
//
//
//    generate_movement_data(0,5,10);
//	inv_kine(rear_right,90+beta[5],leg_next[5],10);
//	delay_ms(200);

}


void BW_Celebrate_Ver2(void)
{
	Sendto_PC(USART1,"BW Celebrate Movement \r");

	mov_static();
	delay_ms(1000);
	int counter=0;
	int adder;
	//STATIC

	inv_kine(front_left,30,11,leg-5);
	inv_kine(front_right,30,11,leg-5);
	inv_kine(middle_left,60,7,leg);
	inv_kine(middle_right,60,7,leg);
	inv_kine(rear_left,120,9,leg-2);
	inv_kine(rear_right,120,10,leg-3);
	delay_ms(100);
	BW_Buzz(3);

	for(counter=0;counter<=8;counter++)
	{
		inv_kine(front_left,30,11,leg-5);
		inv_kine(front_right,30,7,leg);
		inv_kine(middle_left,60,7,leg);
		inv_kine(middle_right,60,7,leg);
		inv_kine(rear_left,120,9,leg-2);
		inv_kine(rear_right,120,10,leg-3);
		delay_ms(50);
		BW_Buzz(3);

		inv_kine(front_left,30,7,leg);
		inv_kine(front_right,30,11,leg-5);
		inv_kine(middle_left,60,7,leg);
		inv_kine(middle_right,60,7,leg);
		inv_kine(rear_left,120,9,leg-2);
		inv_kine(rear_right,120,10,leg-3);
		delay_ms(50);
		BW_Buzz(3);
	}




	for(adder=30;adder<=150;adder+=5)
	{
		inv_kine(front_left,adder,11,leg-5);
		inv_kine(front_right,adder,11,leg-5);
		inv_kine(middle_left,60,7,leg);
		inv_kine(middle_right,60,7,leg);
		inv_kine(rear_left,120,9,leg-2);
		inv_kine(rear_right,120,10,leg-3);
		delay_ms(10);
	}
	BW_Buzz(3);
	delay_ms(100);

//	BW_BLDC_ON;
//	delay_ms(2000);
//	BW_BLDC_OFF;


	for(adder=150;adder>=30;adder-=5)
	{
		inv_kine(front_left,adder,11,leg-5);
		inv_kine(front_right,adder,11,leg-5);
		inv_kine(middle_left,60,7,leg);
		inv_kine(middle_right,60,7,leg);
		inv_kine(rear_left,120,9,leg-2);
		inv_kine(rear_right,120,10,leg-3);
		delay_ms(10);
	}
	delay_ms(100);
	BW_Buzz(3);


}
