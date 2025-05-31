/*==============================================================================================
								  PROJECT BW 2016 Ver.1.0
								BW FLAME SENSOR LIBRARY
==============================================================================================*/

#include "bw_flame_sensor.h"

void FlameSensor_Init(void)
{
//	//Enable Port A Clock
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_IR_A, ENABLE);
//	GPIO_InitStructure.GPIO_Pin   = FLAME_LEFT |  //FRONT LEFT
//									FLAME_RIGHT; //FRONT RIGHT
//	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
//	GPIO_Init(IR_PORT_A, &GPIO_InitStructure);

	 GPIO_InitTypeDef      GPIO_InitStructure;

	 /*Enable GPIO clock*********************************************************/
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_FLAME, ENABLE);

	/* Configure ADC3 Channel7 pin as analog input ******************************/
	  GPIO_InitStructure.GPIO_Pin = FLAME_ANALOG_PIN;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	  //GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //gak perlu
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	  GPIO_Init(IR_PORT_FLAME, &GPIO_InitStructure);

	  ADC1_config();
}

void ADC1_config(void)
{
	  ADC_InitTypeDef       ADC_InitStructure;
	  ADC_CommonInitTypeDef ADC_CommonInitStructure;

	/*Enable ADC3 clock*********************************************************/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	/* ADC Common Init **********************************************************/
	  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
	  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	  ADC_CommonInit(&ADC_CommonInitStructure);

	  /* ADC3 Init ****************************************************************/
	  ADC_InitStructure.ADC_Resolution = ADC_Resolution_8b;
	  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
	  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	  ADC_InitStructure.ADC_NbrOfConversion = 1;

	  ADC_Init(ADC1, &ADC_InitStructure);

	  /* Enable ADC3 */
	  ADC_Cmd(ADC1, ENABLE);
	  ADC_ContinuousModeCmd(ADC1, ENABLE);
	  ADC_RegularChannelConfig(ADC1,ADC_Channel_11,1,ADC_SampleTime_3Cycles); //chanel 4 = IN4= datasheet PA.4(ADC123,IN4)
}


void GetFlame(void)
{
	ADC_SoftwareStartConv(ADC1); //harus masuk while(1)
	FLAME_SENSOR[FLM_ANALOG] = ADC_GetConversionValue(ADC1);

}


//void GetFlame(void)
//{
//	Get_IR();
//	FLAME_SENSOR[FLM_LEFT] = GETFLAME_LEFT;
//	FLAME_SENSOR[FLM_RIGHT] = GETFLAME_RIGHT;
//
//	if((FLAME_SENSOR[FLM_LEFT]==FLAME_DETECTED) &&  (INFRARED[IR_MID_LEFT]==IR_MID_DETECTED))
//	{
//		FLAME_SIDE=FLAME_LEFT_DETECTED;;
//	}
//	else if((FLAME_SENSOR[FLM_RIGHT]==FLAME_DETECTED) &&  (INFRARED[IR_MID_RIGHT]==IR_MID_DETECTED))
//	{
//		FLAME_SIDE=FLAME_RIGHT_DETECTED;
//	}
//
//}


/*
 * OUTPUT STORED IN:
 * unsigned int FLAME_SIDE '
 * 		* FLAME_NOT_DETECTED 	0
 * 		* FLAME_LEFT  			1
 * 		* FLAME_RIGHT 			2
 *
 */
void Display_Flame(void)
{
//	Get_IR();
//	GetFlame();
//	FlameSampling();

	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"FLAME MONITOR");lcd_putstr(lcd);

//	lcd_gotoxy(0,1);sprintf(lcd,"MID_L:%d",INFRARED[IR_MID_LEFT]);lcd_putstr(lcd);
//	lcd_gotoxy(8,1);sprintf(lcd,"MID_R:%d",INFRARED[IR_MID_RIGHT]);lcd_putstr(lcd);

//	lcd_gotoxy(0,2);sprintf(lcd,"FLM_L:%d",FLAME_SENSOR[FLM_LEFT]);lcd_putstr(lcd);
//	lcd_gotoxy(8,2);sprintf(lcd,"FLM_R:%d",FLAME_SENSOR[FLM_RIGHT]);lcd_putstr(lcd);

//	if(FLAME_SIDE==FLAME_RIGHT_DETECTED)
//	{
//		BW_Buzz(2);
//		lcd_gotoxy(0,3);sprintf(lcd,"FLAME RIGHT FOUND");lcd_putstr(lcd);
//	}
//
//	else if(FLAME_SIDE==FLAME_LEFT_DETECTED)
//	{
//		BW_Buzz(1);
//		lcd_gotoxy(0,3);sprintf(lcd,"FLAME LEFT FOUND");lcd_putstr(lcd);
//	}
//	else
//	{
//		lcd_gotoxy(0,3);sprintf(lcd,"FLAME NOT FOUND");lcd_putstr(lcd);
//	}
//	delay_ms(100);
}


/*
 * OUTPUT STORED IN:
 * unsigned int FLAME_SIDE
 * 		* FLAME_NOT_DETECTED 	0
 * 		* FLAME_LEFT  			1
 * 		* FLAME_RIGHT 			2
 *
 */
void Fwd_FlameSide(int distance, int SPEED)
{
	FLAME_SIDE=FLAME_NOT_DETECTED;

	GetFlame();

	Sendto_PC(USART1,"BW FORWARD FLAMESIDE \r");
	int limit= distance/5;
	int loop;
	generate_movement_data(0,5,9);
	delay_ms(50);
	for (loop=1;loop<=limit;loop++)
		{
			GetFlame();
			//1
			inv_kine(front_left,90,7,leg);
			inv_kine(front_right,90+beta[3],10,leg-3);
			inv_kine(middle_left,90+beta[1],10,leg-3);
			inv_kine(middle_right,90,7,leg);
			inv_kine(rear_left,90,7,leg);
			inv_kine(rear_right,90+beta[5],10,leg-3);
			delay_ms(SPEED);

			GetFlame();
			//2
			inv_kine(front_left,90+beta[0],7,leg);
			inv_kine(front_right,90-beta[3],10,leg-3);
			inv_kine(middle_left,90-beta[1],10,leg-3);
			inv_kine(middle_right,90+beta[4],7,leg);
			inv_kine(rear_left,90+beta[2],7,leg);
			inv_kine(rear_right,90-beta[5],10,leg-3);
			delay_ms(SPEED);

			GetFlame();
			//3
			inv_kine(front_left,90+beta[0],7,leg);
			inv_kine(front_right,90-beta[3],7,leg);
			inv_kine(middle_left,90-beta[1],7,leg);
			inv_kine(middle_right,90+beta[4],7,leg);
			inv_kine(rear_left,90+beta[2],7,leg);
			inv_kine(rear_right,90-beta[5],7,leg);
			delay_ms(SPEED);

			GetFlame();
			//4
			inv_kine(front_left,90+beta[0],10,leg-3);
			inv_kine(front_right,90,7,leg);
			inv_kine(middle_left,90,7,leg);
			inv_kine(middle_right,90+beta[4],10,leg-3);
			inv_kine(rear_left,90+beta[2],10,leg-3);
			inv_kine(rear_right,90,7,leg);
			delay_ms(SPEED);

			GetFlame();
			//5
			inv_kine(front_left,90-beta[0]-5,10,leg-3);
			inv_kine(front_right,90+beta[3],7,leg);
			inv_kine(middle_left,90+beta[1],7,leg);
			inv_kine(middle_right,90-beta[4],10,leg-3);
			inv_kine(rear_left,90-beta[2],10,leg-3);
			inv_kine(rear_right,90+beta[5],7,leg);
			delay_ms(SPEED);

			GetFlame();
			//6
			inv_kine(front_left,90-beta[0],7,leg);
			inv_kine(front_right,90+beta[3],7,leg);
			inv_kine(middle_left,90+beta[1],7,leg);
			inv_kine(middle_right,90-beta[4],7,leg);
			inv_kine(rear_left,90-beta[2],7,leg);
			inv_kine(rear_right,90+beta[5],7,leg);
			delay_ms(SPEED);
		}

//	lcd_display_clear();
//	if(FLAME_SIDE==FLAME_LEFT_DETECTED)
//	{
//		lcd_gotoxy(0,0);sprintf(lcd,"FLAME LEFT");lcd_putstr(lcd);
////		FIRE=1;
//	}
//	else if(FLAME_SIDE==FLAME_RIGHT_DETECTED)
//	{
//		lcd_gotoxy(0,0);sprintf(lcd,"FLAME RIGHT");lcd_putstr(lcd);
////		FIRE=1;
//	}
//	else
//	{
//		lcd_gotoxy(0,0);sprintf(lcd,"FLM SIDE NOT FOUND");lcd_putstr(lcd);
//	}

}
