/*==============================================================================================
								  PROJECT BW Ver.1.0
							THERMOPHILE ARRAY AND SERVO LIBRARY
==============================================================================================*/



//USER DEFINED LIBRARIES
#include "bw_tpa_servo.h"
#include "bw_hexapod_cmd.h"

//MIN    -> 1850
//CENTER -> 3000
//MAX    -> 4250

const int SERVO_MIN    = 1850;
const int SERVO_CENTER = 3000;
const int SERVO_MAX    = 4250;

void PanServo_Init(void)
{
	TIM12_PWM_Configuration();
//	TIM4_PWM_Configuration();
	PWM_servo = 3100; //centeraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

}


void TIM12_PWM_Configuration(void)
{
	  // Clock enable
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);       // Clocking GPIOC (AHB1/APB1 = 42MHz)
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM12, ENABLE);        // Clocking TIM12  (APB1 = 42x2PLL=84MHz)

	  // GPIO__TIM_init
	  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;                           // PWM is an alternative function
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                      // GPIO_HIGH_Speed
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                          // Push-pull
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOB, &GPIO_InitStructure);                                  // Initializing GPIOC structure
	  GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_TIM12);     // Routing TIM3 output to PC6

	  // Timer init
	  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 // => 0 = Not dividing
	  TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;           // Upcounting configuration
	  TIM_TimeBaseStructure.TIM_Period        = 39999;            			 // 39999=TCNT ==>pwm_freq=2000000/39999+1=50Hz
	  TIM_TimeBaseStructure.TIM_Prescaler     = 41;            				 // Tim_tick => 84000000Hz/41+1=2000000Hz
	  TIM_TimeBaseInit(TIM12, &TIM_TimeBaseStructure);                         // Initializing Time Base structure

	  // Channel 1, Ch.1 (PC6)
	  TIM_OCInitStructure.TIM_OCMode      = TIM_OCMode_PWM2;                  // PWM mode 1 = Set on compare match, PWM mode 2 = Clear on compare match pasangan OCPolarity_LOW
	  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;           // Enabling the Output Compare state
	  TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_Low;                // Regular polarity (low will inverse it)
	  TIM_OCInitStructure.TIM_Pulse       = PWM_servo;                      // Output Compare 1 reg value
	  TIM_OC2Init(TIM12, &TIM_OCInitStructure);                                // Initializing Output Compare 1 structure
	  TIM_OC2PreloadConfig(TIM12, TIM_OCPreload_Enable);                       // Enable Ch.1 Output Compare preload

	  // Timer enable
	  TIM_Cmd(TIM12, ENABLE);												// Ready, Set, Go!

}

void Set_Servo(int sudut)
{
	int PWM=0;
	int cnt=0;
	int cnt_extinguish=0;
	PWM_FIRE = 0;

	if(((SHARP[SHARP_FRONT_R]<10)) || (SHARP[SHARP_FRONT_L]<10) && ROOM[2]!=ROOM_4A && ROOM[2]!=ROOM_4B)
	{
		Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
	}

	Get_UV();
	Get_TPA81();
	if(FIRE==0)
	{
		lcd_display_clear();
		lcd_gotoxy(5,0);sprintf(lcd,"TPA");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"CHECK 1");lcd_putstr(lcd);

		for(PWM=0;PWM<600;PWM+=25)
		{
			Get_TPA81();
			if(FIRE==1)break;
//			PWM_servo = 2500+PWM;
			PWM_servo = 2800+PWM;
			delay_ms(50);
		}
	}

	Get_UV();
	Get_TPA81();
	if(FIRE==0)
	{
		lcd_display_clear();
		lcd_gotoxy(5,0);sprintf(lcd,"TPA");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"CHECK 2");lcd_putstr(lcd);

		for(PWM=600;PWM>0;PWM-=25)
		{
			Get_TPA81();
			if(FIRE==1)break;
//			PWM_servo = 2500+PWM;
			PWM_servo = 2800+PWM;
			delay_ms(50);
		}
	}

// Special condition: JIKA TPA terhalang furniture tapi flame tidak
	Get_UV();
	Get_TPA81();
	if(FIRE==0 && UV_state==0)
	{
		lcd_display_clear();
		lcd_gotoxy(5,0);sprintf(lcd,"TPA");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"CHECK 3");lcd_putstr(lcd);

		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MEDFAST);

		for(x=0;x<=3;x++)
		{
				FlameTracking_Center();

				while(SHARP[SHARP_FRONT_R]>25 && SHARP[SHARP_FRONT_L]>25)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					Furniture_Avoider();
					Bumper_Follow();

					if(FlameFrontDigi[0]!=4)break;
				}

				FlameTracking_Center();

				Bumper_Follow();

				while(SHARP[SHARP_FRONT_R]>25 && SHARP[SHARP_FRONT_L]>25)
				{
					lcd_display_clear();
					lcd_gotoxy(0,0);sprintf(lcd,"MAJU KE API");lcd_putstr(lcd);

					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					Furniture_Avoider();
					Bumper_Follow();

					if(FlameFrontDigi[0]!=4)break;
				}

				Bumper_Follow();
		}

		Get_TPA81();
		if(FIRE==0)
		{
			for(PWM=0;PWM<600;PWM+=25)
			{
				Get_TPA81();
				if(FIRE==1)break;
//				PWM_servo = 2500+PWM;
				PWM_servo = 2800+PWM;
				delay_ms(50);
			}
		}
		Get_TPA81();
		if(FIRE==0)
		{
			for(PWM=600;PWM>0;PWM-=25)
			{
				Get_TPA81();
				if(FIRE==1)break;
//				PWM_servo = 2500+PWM;
				PWM_servo = 2800+PWM;
				delay_ms(50);
			}
		}

	}

	Get_UV();
	Get_TPA81();
	while(UV_state==0)
	{
		Get_TPA81();
		while(FIRE==1)
		{
			EXTINGUISHER_ON;
			while(cnt_extinguish<2)
			{
				cnt_extinguish++;
				PWM_FIRE=PWM_servo;
				Dynamx_Extinguish_High(HEXSPD_SLOW);

				Get_UV();
				if(UV_state==1)EXTINGUISHER_OFF;break;
			}
			Get_UV();
			if(UV_state==1)EXTINGUISHER_OFF;break;

//			else
//			{
//				Dynamx_MovFwd4cm(4,HEXSPD_MED,IKCALC_DISABLE);
//			}
//			Get_UV();
//			if(UV_state==1)EXTINGUISHER_OFF;break;
//			if(FlameFrontDigi[0]!=4)
//			{
//				EXTINGUISHER_OFF;
//				FlameTracking_Center();
//				//EXTINGUISHER_ON;
//			}
//			Get_UV();
//			if(UV_state==1)EXTINGUISHER_OFF;break;
//			Get_TPA81();
		}

		cnt_extinguish=0;

		lcd_display_clear();
		lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW FIRE");lcd_putstr(lcd);
		lcd_gotoxy(0,1);sprintf(lcd,"CNT= %d",cnt);lcd_putstr(lcd);
		if(cnt==1)break;
		cnt++;
		Get_UV();
		if(UV_state==1){break;}
	}
	PWM_servo = 3100; //center
	EXTINGUISHER_OFF;
}

void TIM4_PWM_Configuration(void)
{
	  // Clock enable
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);       // Clocking GPIOC (AHB1/APB1 = 42MHz)
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);        // Clocking TIM12  (APB1 = 42x2PLL=84MHz)

	  // GPIO__TIM_init
	  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_12;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;                           // PWM is an alternative function
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                      // GPIO_HIGH_Speed
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                          // Push-pull
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOD, &GPIO_InitStructure);                                  // Initializing GPIOC structure
	  GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);     // Routing TIM3 output to PC6

	  // Timer init
	  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 // => 0 = Not dividing
	  TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;           // Upcounting configuration
	  TIM_TimeBaseStructure.TIM_Period        = 39999;            			 // 39999=TCNT ==>pwm_freq=2000000/39999+1=50Hz
	  TIM_TimeBaseStructure.TIM_Prescaler     = 41;            				 // Tim_tick => 84000000Hz/41+1=2000000Hz
	  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);                         // Initializing Time Base structure

	  // Channel 1, Ch.1 (PC6)
	  TIM_OCInitStructure.TIM_OCMode      = TIM_OCMode_PWM2;                  // PWM mode 1 = Set on compare match, PWM mode 2 = Clear on compare match pasangan OCPolarity_LOW
	  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;           // Enabling the Output Compare state
	  TIM_OCInitStructure.TIM_OCPolarity  = TIM_OCPolarity_Low;                // Regular polarity (low will inverse it)
	  TIM_OCInitStructure.TIM_Pulse       = PWM4_Servo;                      // Output Compare 1 reg value
	  TIM_OC2Init(TIM4, &TIM_OCInitStructure);                                // Initializing Output Compare 1 structure
	  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);                       // Enable Ch.1 Output Compare preload

	  // Timer enable
	  TIM_Cmd(TIM4, ENABLE);                                      // Ready, Set, Go!

}

void Set_Servo2(void)
{
	  PWM4_Servo = 1850;
	  delay_ms(1000);
	  PWM4_Servo = 4250;
	  delay_ms(1000);
}


void BW_Thermopile_Init(void)
{
	//TIM12_PWM_Configuration();
	Setup_I2C();
}


void Setup_I2C()
{
//    //TPA 81
//	/*  GPIO Setup  */
//    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//
//    //I2C_DeInit(I2C1);
//    /*  I2C Setup  */
//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
//    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
//    I2C_InitStructure.I2C_ClockSpeed = 100000; //100kHz
////    I2C_InitStructure.I2C_ClockSpeed = 400000; //400kHz
//    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
//    I2C_InitStructure.I2C_OwnAddress1 = 0x00;
//    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
//    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
//
//    I2C_Cmd(I2C1, ENABLE);
//    I2C_Init(I2C1, &I2C_InitStructure);
//
//    /* Connect PXx to I2C_SCL*/
//    GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_I2C1);
//
//    /* Connect PXx to I2C_SDA*/
//    GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1);
////
////    //==========================================================
////    //COMPASS
////    /*  GPIO Setup  */
////    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
////    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
////    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
////    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
////    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
////    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
////    GPIO_Init(GPIOB, &GPIO_InitStructure);
////
////    //I2C_DeInit(I2C1);
////    /*  I2C Setup  */
////    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
////    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
////    I2C_InitStructure.I2C_ClockSpeed = 100000; //100kHz
////    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
////    I2C_InitStructure.I2C_OwnAddress1 = 0x00;
////    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
////    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
////
////    I2C_Cmd(I2C2, ENABLE);
////    I2C_Init(I2C2, &I2C_InitStructure);
////
////    /* Connect PXx to I2C_SCL*/
////    GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_I2C2);
////
////    /* Connect PXx to I2C_SDA*/
////    GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_I2C2);
}

void Write_I2C(int Address, int Register, int Data)
{
	if((MPU_ACTIVE_MODE&&1)==1)
	{
		while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY))
		{
			;
		}

		I2C_GenerateSTART(I2C1, ENABLE);

		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
		{
			;
		}
		I2C_Send7bitAddress(I2C1,Address<<1,I2C_Direction_Transmitter);

		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		{
			;
		}

		I2C_SendData(I2C1,Register);

		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		{
			;
		}

		I2C_SendData(I2C1,Data);
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		{
			;
		}

		I2C_GenerateSTOP(I2C1, ENABLE);
	}
}



void Read_I2C(int Address, int Register)
{
	if((MPU_ACTIVE_MODE&&1)==1)
	{
		while (I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY))
		{
			;
		}

		I2C_GenerateSTART(I2C1, ENABLE);
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
		{
			;
		}

		I2C_Send7bitAddress(I2C1, Address<<1,I2C_Direction_Transmitter);

		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		{
			;
		}

		I2C_Cmd(I2C1, ENABLE);

		I2C_SendData(I2C1,Register);

		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		{
			;
		}

		I2C_GenerateSTART(I2C1, ENABLE);

		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT))
		{
			;
		}

		I2C_Send7bitAddress(I2C1,Address<<1,I2C_Direction_Receiver);
		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
		{
			;
		}

		I2C_AcknowledgeConfig(I2C1, DISABLE);
		I2C_GenerateSTOP(I2C1, ENABLE);

		while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_RECEIVED))
		{
			;
		}

		DATA=I2C_ReceiveData(I2C1);
		I2C_AcknowledgeConfig(I2C1, ENABLE);
	}
}




//==============
//TPA
unsigned char BW_TPA_Check(char val_or_flag)
{
	//unsigned char tpa_fight=0;
	i=0, temp=0,suhu_ruang=0;
	regs=0x00;

	//int shifted_address = 0xD0>>1;


	for (i=0;i<=9;i++)
	{
		//Read_I2C(shifted_address,regs);
		Read_I2C(0x68, regs); //Aslinya 0xD0, tapi hasilnya digeser satu bit ke kanan
		regs=regs+1; // register=0x02,0x03,...,0x09
		pixel[i]=DATA;

		/*
		 * NEW ALGORITHM
		 */
//		I2C1_ReadByte(TPA81_ADDRESS,regs);
//		regs=regs+1; // register=0x02,0x03,...,0x09
//		pixel[i]= I2C1_DATA[0]
	}

	/*
	 *  NEW ALGORITHM
	 */
//	I2C1_ReadMultiByte(TPA81_ADDRESS,TPA81_TEMPERATURE,TPA81_REQUESTED_BYTE);
//	suhu_ruang 		= I2C1_DATA[0];
//	suhu_pixel[0] 	= I2C1_DATA[2];
//	suhu_pixel[1] 	= I2C1_DATA[3];
//	suhu_pixel[2] 	= I2C1_DATA[4];
//	suhu_pixel[3] 	= I2C1_DATA[5];
//	suhu_pixel[4] 	= I2C1_DATA[6];
//	suhu_pixel[5] 	= I2C1_DATA[7];
//	suhu_pixel[6] 	= I2C1_DATA[1];
//	suhu_pixel[7] 	= I2C1_DATA[8];


	suhu_ruang = pixel[1];
	suhu_pixel[0] = pixel[3];
	suhu_pixel[1] = pixel[4];
	suhu_pixel[2] = pixel[5];
	suhu_pixel[3] = pixel[6];
	suhu_pixel[4] = pixel[7];
	suhu_pixel[5] = pixel[8];
	suhu_pixel[6] = pixel[2];
	suhu_pixel[7] = pixel[9];

	temp = fmax(temp,suhu_pixel[0]);
	temp = fmax(temp,suhu_pixel[1]);
	temp = fmax(temp,suhu_pixel[2]);
	temp = fmax(temp,suhu_pixel[3]);
	temp = fmax(temp,suhu_pixel[4]);
	temp = fmax(temp,suhu_pixel[5]);
	temp = fmax(temp,suhu_pixel[6]);
	temp = fmax(temp,suhu_pixel[7]);

	if(!val_or_flag)
	{return (unsigned char)temp;}

	temp -= suhu_ruang;


	if(temp>14 && val_or_flag) {/*tpa_fight=1;*/ return 1;}   //dulu pakai tresh hold 15 kurang respon jika di ruang 3

	else {return 0;}


//    if(((pixel[2]+pixel[3]+pixel[4]+pixel[5]+pixel[6]+pixel[7]+pixel[8]+pixel[9])/8) >= 55) //pixel[0]&&pixel[1] tidak dipakai karena nilai sensornya tetap/tdk berubah
//    //if(pixel[2]&&pixel[3]&&pixel[4]&&pixel[5]&&pixel[6]&&pixel[7]&&pixel[8]&&pixel[9] >= 54) //pake and sering salah baca
//    {return 1;}
//    else
//    {return 0;}
}


////==============
////TPA SERVO
int tpa_servo()
{
	panas=0;
    int sudut_sv=-90;
    Set_Servo(-90);
    delay_ms(1000);

    while(panas==0 && sudut_sv<=90)
    {
        //Set_Servo((signed char)sudut_sv);
        Set_Servo(sudut_sv);
        delay_ms(20);
        panas = BW_TPA_Check(1);
        sudut_sv += 2;
    }
//    buzz(4);
    if(panas==0) //penting kalo if ini dihilangkan servo gak mau berhenti/ langsung reset ke -90
    {
//    	buzz(1);
        //PWM_servo = center_ser;    //mempercepat reset ke titik awal
        sudut_sv = 120; //angka gw bole suka"
    }
    else if(panas==1) //ada api
    {
//    	buzz(2);
    	sudut_sv = (sudut_sv-2);
    }
    delay_ms(1000);
    return sudut_sv;
}

//unsigned int BW_Search_Fire(void)
//{
//	panas=0;
//	static int counter=1;
//
//	//mov_search_fire(SRC_FR_A);
//
//	while (panas==0)
//	{
//		panas = BW_TPA_Check(1);
//		switch(counter)
//		{
//			case 1:  {mov_search_fire(SRC_FR_A); counter++;delay_ms(100);}break;
//			case 2:  {mov_search_fire(SRC_FR_B); counter++;delay_ms(100);}break;
//			case 3:  {mov_search_fire(SRC_FR_C); counter++;delay_ms(100);}break;
//			case 4:  {mov_search_fire(SRC_FR_D); counter++;delay_ms(100);}break;
//			case 5:  {mov_search_fire(SRC_FR_E); counter++;delay_ms(100);}break;
//			case 6:  {mov_search_fire(SRC_FR_F); counter++;delay_ms(100);}break;
//			case 7:  {mov_search_fire(SRC_FR_G); counter++;delay_ms(100);}break;
//			case 8:  {mov_search_fire(SRC_FR_H); counter++;delay_ms(100);}break;
//			case 9:  {mov_search_fire(SRC_FR_I); counter++;delay_ms(100);}break;
//			case 10:  {mov_search_fire(SRC_FR_J); counter++;delay_ms(100);}break;
//			case 11:  {mov_search_fire(SRC_FR_K); counter++;delay_ms(100);}break;
//			case 12:  {mov_search_fire(SRC_FR_L); counter++;delay_ms(100);}break;
//			case 13:  {mov_search_fire(SRC_FR_M); counter++;delay_ms(100);}break;
//			case 14:  {mov_search_fire(SRC_FR_L); counter++;delay_ms(100);}break;
//			case 15:  {mov_search_fire(SRC_FR_K); counter++;delay_ms(100);}break;
//			case 16:  {mov_search_fire(SRC_FR_J); counter++;delay_ms(100);}break;
//			case 17:  {mov_search_fire(SRC_FR_I); counter++;delay_ms(100);}break;
//			case 18:  {mov_search_fire(SRC_FR_H); counter++;delay_ms(100);}break;
//			case 19:  {mov_search_fire(SRC_FR_G); counter++;delay_ms(100);}break;
//			case 20:  {mov_search_fire(SRC_FR_F); counter++;delay_ms(100);}break;
//			case 21:  {mov_search_fire(SRC_FR_E); counter++;delay_ms(100);}break;
//			case 22:  {mov_search_fire(SRC_FR_D); counter++;delay_ms(100);}break;
//			case 23:  {mov_search_fire(SRC_FR_C); counter++;delay_ms(100);}break;
//			case 24:  {mov_search_fire(SRC_FR_B); counter++;delay_ms(100);}break;
//			default: counter=1;break;
//		}
//	}
//
//	if (panas==1)
//	{
//		//panas=0;		Mov_fwd_5cm(5,MED);
//
//		//mov_search_fire(SEARCH_FIRE_RESET);
//	}
//	return 1;
//}

void Get_TPA81(void)
{
	FIRE= BW_TPA_Check(1);
//	Sendto_PC(USART1,"FIRE: %d",FIRE);
	lcd_display_clear();
	lcd_gotoxy(0,0);sprintf(lcd,"FIRE: %d",FIRE);lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"suhu_ruang: %d",suhu_ruang);lcd_putstr(lcd);
//	lcd_gotoxy(0,2);sprintf(lcd,"%d  %d  %d  %d",suhu_pixel[0],suhu_pixel[1],suhu_pixel[2],suhu_pixel[3]);lcd_putstr(lcd);
//	lcd_gotoxy(0,3);sprintf(lcd,"%d  %d  %d  %d",suhu_pixel[4],suhu_pixel[5],suhu_pixel[6],suhu_pixel[7]);lcd_putstr(lcd);
//	delay_ms(100);


}


/* func      : 	void BW_TPA81_I2C_Init (void)
 * brief     : 	TPA81 I2C1 BUS Initialization
 * param     :	N/A
 * retval    : 	N/A
 * Ver       : 1
 * written By: Ryan (Monday, February 22nd 2016)
 * Revised By: N/A
 *
 */
void BW_TPA81_I2C_Init (void)
{
    //TPA 81
	/*  GPIO Setup  */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    //I2C_DeInit(I2C1);
    /*  I2C Setup  */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    I2C_InitStructure.I2C_ClockSpeed = 100000; //100kHz
//    I2C_InitStructure.I2C_ClockSpeed = 400000; //400kHz
    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitStructure.I2C_OwnAddress1 = 0x00;
    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;

    I2C_Cmd(I2C1, ENABLE);
    I2C_Init(I2C1, &I2C_InitStructure);

    /* Connect PXx to I2C_SCL*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_I2C1);

    /* Connect PXx to I2C_SDA*/
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_I2C1);
}


/* func      : int16_t I2C1_TimeOut(int16_t VALUE)
 * brief     : STOP, RESET, and RE-INIT the I2C1 Communication Interface
 * param     :	int16_t VALUE : TIMEOUT CODE
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C1_ReadMultiByte SUCCESS!
 * 				RetVal < 0 -> I2C1_ReadMultiByte ERROR!
 * Ver       : 1
 * written By: Ryan (Monday, February 22nd 2016)
 * Revised By: N/A
 *
 */
int16_t I2C1_TimeOut(int16_t VALUE)
{
	int16_t RetVal= VALUE;

//	Stop and reset
	I2C_GenerateSTOP(I2C1,ENABLE);
	I2C_SoftwareResetCmd(I2C1,ENABLE);
	I2C_SoftwareResetCmd(I2C2, DISABLE);

	// I2C De-Init
	I2C_DeInit(I2C1);

//	I2C Re-Init
	BW_TPA81_I2C_Init();

    return(RetVal);
}

/* func      : int16_t I2C1_ReadByte(uint8_t ADDRESS, uint8_t REGISTER)
 * brief     : Read single byte variables from I2C Bus
 * param     :
 * 				uint8_t ADDRESS : I2C Slave Device Address
 * 				uint8_t REGISTER: Register Address
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C1_ReadByte SUCCESS!
 * 				RetVal < 0 -> I2C1_ReadByte ERROR!
 * 				Data stored int I2C1_DATA[0]
 * Ver       : 1
 * written By: Ryan (Monday, February 22nd 2016)
 * Revised By: N/A
 *
 */
int16_t I2C1_ReadByte(uint8_t ADDRESS, uint8_t REGISTER)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C1_TIMEOUT;
//	  uint8_t Value,counter;

	  //Start Sequences
	  I2C_GenerateSTART(I2C1, ENABLE);

	  TimeOut= I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1,I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-1));
	  }

	  // ACK disable
	  I2C_AcknowledgeConfig(I2C1, DISABLE);

	  // Slave Address Send (write)
	  I2C_Send7bitAddress(I2C1, ADDRESS, I2C_Direction_Transmitter);

	  TimeOut= I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C1->SR2;

	  TimeOut=I2C1_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-3));
	  }

	  // SEND REGISTER ADDRESS
	  I2C_SendData(I2C1, REGISTER);

	  TimeOut=I2C1_TIMEOUT;
	  while ((!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C1, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-4));
	  }

	  // Start Sequence
	  I2C_GenerateSTART(I2C1, ENABLE);

	  TimeOut=I2C1_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-5));
	  }

	  // Slave Address Send (read
	  I2C_Send7bitAddress(I2C1, ADDRESS, I2C_Direction_Receiver);

	  TimeOut=I2C1_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-6));
	  }

	  // Clear ADDR Flag
	  I2C1->SR2;

	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_RXNE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-7));
	  }

	  // Stop Sequences
	  I2C_GenerateSTOP(I2C1, ENABLE);

	  // Read data
	  I2C1_DATA[0]=I2C_ReceiveData(I2C1);

	  // ACK enable
	  I2C_AcknowledgeConfig(I2C1, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return(RetVal);
}


//int16_t UB_I2C1_ReadMultiByte(uint8_t slave_adr, uint8_t adr, uint8_t cnt);
/* func      : int16_t I2C1_ReadMultiByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE)
 * brief     : Read multibyte variables from I2C Bus
 * param     :
 * 				uint8_t ADDRESS : I2C Slave Device Address
 * 				uint8_t REGISTER: Start Register Address
 * 				uint8_t BYTE	: Number of Requested Byte
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C1_ReadMultiByte SUCCESS!
 * 				RetVal < 0 -> I2C1_ReadMultiByte ERROR!
 * 				Data stored int I2C2_DATA[0]-I2C2_DATA[9]
 * Ver       : 1
 * written By: Ryan (Monday, February 22nd 2016)
 * Revised By: N/A
 *
 */
int16_t I2C1_ReadMultiByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C1_TIMEOUT;
	  uint8_t Value,counter;

	  if(BYTE==0) return (-8);
	  if(BYTE>I2C1_MULTIBYTE_MAX) return(-9);

//	  Start Sequences
	  I2C_GenerateSTART(I2C1, ENABLE);

	  TimeOut= I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1,I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-1));
	  }

	  if(BYTE==1)
	  {
//		  ACK Disable
		  I2C_AcknowledgeConfig(I2C1, DISABLE);
	  }

	  else
	  {
		// ACK enable
		I2C_AcknowledgeConfig(I2C1, ENABLE);
	  }

	  // Slave-Adress send (write)
	  I2C_Send7bitAddress(I2C1, ADDRESS, I2C_Direction_Transmitter);

	  TimeOut=I2C1_TIMEOUT;

	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C1->SR2;

	  TimeOut=I2C1_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-3));
	  }

	  // Send REGISTER ADDRESS
	  I2C_SendData(I2C1, REGISTER);

	  TimeOut=I2C1_TIMEOUT;
	  while ((!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C1, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-4));
	  }

	  // Start Sequence
	  I2C_GenerateSTART(I2C1, ENABLE);

	  TimeOut=I2C1_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-5));
	  }

	  // Slave Address Send (read
	  I2C_Send7bitAddress(I2C1, ADDRESS, I2C_Direction_Receiver);

	  TimeOut=I2C1_TIMEOUT;
	  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-6));
	  }

	  // Clear ADDR Flag
	  I2C1->SR2;

//	  Read ALL DATA
	  for(counter=0;counter<BYTE;counter++)
	  {
		  if( (counter+1)>=BYTE)
		  {
			  // Disable ACK
			  I2C_AcknowledgeConfig(I2C1, DISABLE);

			  // Stop Sequences
			  I2C_GenerateSTOP(I2C1, ENABLE);
		  }

		  TimeOut=I2C1_TIMEOUT;

		  while (!I2C_GetFlagStatus(I2C1, I2C_FLAG_RXNE))
		  {
			  if(TimeOut!=0) TimeOut--;
			  else return (I2C1_TimeOut(-7));
		  }

		  // Read data
		  Value=I2C_ReceiveData(I2C1);

		  // Store received data in array
		  I2C2_DATA[counter]=Value;
	  }

	  // ACK enable
	  I2C_AcknowledgeConfig(I2C1, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return(RetVal);
}


/* func      : int16_t I2C1_WriteByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t VALUE)
 * brief     : Write single byte variables through the I2C1 Communication Protocol
 * param     :
 * 				uint8_t ADDRESS : I2C Slave Device Address
 * 				uint8_t REGISTER: Start Register Address
 * 				uint8_t VALUE	: Value that should be sent to the I2C Slave Devices
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C1_WriteByte SUCCESS!
 * 				RetVal < 0 -> I2C1_WriteByte ERROR!
 *
 * Ver       : 1
 * written By: Ryan (Monday, February 22nd 2016)
 * Revised By: N/A
 *
 */
int16_t I2C1_WriteByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t VALUE)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C1_TIMEOUT;

	  //Start Sequences
	  I2C_GenerateSTART(I2C1, ENABLE);

	  TimeOut=I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-1));
	  }

	  // Slave Address Send (write)
	  I2C_Send7bitAddress(I2C1,ADDRESS,I2C_Direction_Transmitter);

	  TimeOut=I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C1->SR2;

	  TimeOut=I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-3));
	  }

	  // Address Send
	  I2C_SendData(I2C1, ADDRESS);

	  TimeOut=I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-4));
	  }

	  //Send Data
	  I2C_SendData(I2C1, VALUE);

	  TimeOut=I2C1_TIMEOUT;

	  while ((!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C1, I2C_FLAG_BTF)))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-5));
	  }

	  // Stop Sequences
	  I2C_GenerateSTOP(I2C1, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return (RetVal);
}



/* func      : int16_t I2C1_WriteMultiByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE)
 * brief     : Write multibyte variables to the I2C Bus
 * param     :
 * 				Hold the value you want to send on the buffer I2C2_DATA[0] ~ I2C2_DATA[9]
 * 				uint8_t ADDRESS : I2C Slave Device Address
 * 				uint8_t REGISTER: Start Register Address
 * 				uint8_t BYTE	: Number of Requested Byte
 * retval    : 	int16_t RetVal (ERROR CODE indicator)
 * 				RetVal = 0 -> I2C1_WriteMultiByte SUCCESS!
 * 				RetVal < 0 -> I2C1_WriteMultiByte ERROR!
 *
 * Ver       : 1
 * written By: Ryan (Monday, February 22nd 2016)
 * Revised By: N/A
 *
 */
int16_t I2C1_WriteMultiByte(uint8_t ADDRESS, uint8_t REGISTER, uint8_t BYTE)
{
	  int16_t RetVal=0;
	  uint32_t TimeOut=I2C1_TIMEOUT;
	  uint8_t Value;
	  unsigned int counter;

	  if(counter==0) return(-6);
	  if(counter>I2C1_MULTIBYTE_MAX) return(-7);

//	  Start Sequences
	  I2C_GenerateSTART(I2C1, ENABLE);

	  TimeOut=I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_SB))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-1));
	  }

	  // Slave Address Send (write)
	  I2C_Send7bitAddress(I2C1,ADDRESS,I2C_Direction_Transmitter);

	  TimeOut=I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_ADDR))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-2));
	  }

	  // Clear ADDR Flag
	  I2C1->SR2;

	  TimeOut=I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-3));
	  }

	  // Address Send
	  I2C_SendData(I2C1, ADDRESS);

	  TimeOut=I2C1_TIMEOUT;
	  while(!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE))
	  {
		  if(TimeOut!=0) TimeOut--;
		  else return (I2C1_TimeOut(-4));
	  }

	  // Send all data
	  for(counter=0;counter<BYTE;counter++)
	  {
		  //Read data from array
		  Value=I2C1_DATA[counter];

		  //Send Data
		  I2C_SendData(I2C1, Value);

		  TimeOut=I2C1_TIMEOUT;

		  while ((!I2C_GetFlagStatus(I2C1, I2C_FLAG_TXE)) || (!I2C_GetFlagStatus(I2C1, I2C_FLAG_BTF)))
		  {
			  if(TimeOut!=0) TimeOut--;
			  else return (I2C1_TimeOut(-5));
		  }
	  }

	  // Stop Sequences
	  I2C_GenerateSTOP(I2C1, ENABLE);

	  // Everything's... Alright~ ;) *I hope
	  RetVal=0;

	  return (RetVal);
}

