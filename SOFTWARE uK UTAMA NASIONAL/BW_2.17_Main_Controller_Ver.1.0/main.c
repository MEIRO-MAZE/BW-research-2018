/*****************************************************
Project   : BW* Main Controller
Version   : 1.0
Year      : 2017
Date      : 20th 2017
Author    : BERTONI RAMADHAN PUTRA(2015)
University: University of Brawijaya
Department: Electrical Engineering Department, Engineering Faculty
Division  : Legged Fire-Fighting Division (KRPAI)
Comments  : *Dreams/aspirations, in Japanese language

What's New: Optimization from Ver.1.x , BW System using single STM32 and Rangefinder Controller
			New Pin Mapping for every actuator, sensor, and other peripheral

Board Type: STM32F4 Discovery Board
Chip  Type: STM32F407VG
*****************************************************/


#include "main.h"


int toggle=1;
void BW_Initialization(void);
int main(void)
{
	int BUTTON_ACT;
	int SOUND_ACT;

	BW_Initialization();

	delay_ms(500);

//	lcd_display_clear();
//	lcd_gotoxy(0,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//	lcd_gotoxy(0,1);sprintf(lcd,"MOV STATIC");lcd_putstr(lcd);

	Dynamx_Mov_Static(HEXSPD_ULTRASLOW,IKCALC_DISABLE);

//	while(1)
//	{
//		lcd_display_clear();
//		lcd_gotoxy(0,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
//		lcd_gotoxy(0,1);sprintf(lcd,"MOV SLIDE R");lcd_putstr(lcd);
//
//		Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//	}
//	kinematik_invers(FRONT_LEFT_DX,HEXSPD_SLOW,4,0,3);

//	static_syncwrite();
//	Dynamx_Mov_Static_Low(HEXSPD_ULTRASLOW);

//	while(1)
//	{
//		Dynamx_MovFwd4cm(4,HEXSPD_SLOW,IKCALC_DISABLE);
////		delay_ms(1000);
////		HexDemo();
//	}

			while( (BW_BUTTON_UNCLICKED) && (SOUND_INACTIVE) )
			{
				if(BW_BUTTON_CLICKED){BUTTON_ACT=1;break;}
				if(SOUND_ACTIVATED){SOUND_ACT=1;break;}
				RotSwitch_Sampling();
				Display_MODE();
				if(BW_BUTTON_CLICKED){BUTTON_ACT=1;break;}
				if(SOUND_ACTIVATED){SOUND_ACT=1;break;}
			}

		if(BW_BUTTON_CLICKED){BUTTON_ACT=1;}
		if(SOUND_ACTIVATED){SOUND_ACT=1;}

	if(BUTTON_ACT==1)
	{
		BW_Buzz(1);
		Sendto_PC(USART1,"BW BUTTON ACTIVATED! \r");
		lcd_display_clear();
		lcd_gotoxy(5,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"BUTTON ACTIVATED");lcd_putstr(lcd);
		delay_ms(100);

//		BW_Dimension_Check();
//		Dynamx_Mov_Static(HEXSPD_ULTRASLOW,IKCALC_ENABLE);

	}
	else if(SOUND_ACT==1)
	{
		BW_Buzz(2);
		Sendto_PC(USART1,"BW SOUND ACTIVATED! \r");
		lcd_display_clear();
		lcd_gotoxy(5,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
		lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
		lcd_gotoxy(0,2);sprintf(lcd,"FIREFIGHTER ROBO");lcd_putstr(lcd);
		lcd_gotoxy(0,3);sprintf(lcd,"SOUND ACTIVATED");lcd_putstr(lcd);
		delay_ms(100);

		SND_ACT_LED_ON;		//turn on sound led indicator
//		BW_LED_BLINK_ON;
	}

	switch(rot_switch_mode)
	{
//		//BW FAILED INITIALIZATION
		case BW_MODE_DEFAULT:
			{

			}break;

//		//BW TRIAL ALGORITHM MODE
		case BW_MODE_1:
			{
				BW_Initial_Setup(rot_switch_mode);

				while(1)
				{
					H_2017_Algorithm();
					while(1)
					{
						BW_Buzz(1);
						Dynamx_Mov_Static(HEXSPD_SLOW,IKCALC_DISABLE);
//						Dynamx_Mov_Static_Low(HEXSPD_SLOW);

					}

				}
			}break;

//		//BW TEST DRIVE MODE
		case BW_MODE_2:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();
				lcd_gotoxy(1,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(2,2);sprintf(lcd,"FOLLOW");lcd_putstr(lcd);
//				lcd_gotoxy(3,3);sprintf(lcd,":)");lcd_putstr(lcd);
//				lcd_display_clear();
//				int g;
//				int a,b,c,d,e,f;
//				int a;
//				ROOM1_FLAG=ROOM1FLAG_ACTIVE;

				CAT_FLAG_B=CAT_NOT_DETECTED;
				BW_LOCATION[0]=LOCATION_CORRIDOR;
				R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
				BW_PID_Init();

				BW_LOCATION[0]=LOCATION_ROOM;
//				FOLLOW_FLAG=KANAN;
				BW_PID_Init();

//				FIRESCAN_DIRECTION=SCAN_LEFT;
				while(1)
				{
					lcd_display_clear();
					lcd_gotoxy(1,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
					lcd_gotoxy(2,2);sprintf(lcd,"SLIDE RIGHT ");lcd_putstr(lcd);
					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);

//					delay_ms(50);
//					BW_FollowTracer_Right();
//					Nav_4B_To_1A();
					//test_IK();
//					Bumper_Follow();
//					BW_PID_Init_Room();
//					HexDemo();
//					Gerak(0);
//					Dynamx_Extinguish_High(HEXSPD_SLOW);
//					Set_Servo(0);
////				Dynamx_Rot_Left(HEXSPD_MED,HEXSTEP_MED,IKCALC_DISABLE);
//					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//					BW_FollowTracer_Right_Reverse();
				}
			}break;

//		//BW NAVIGATION MENU MODE
		case BW_MODE_3:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();
				lcd_gotoxy(1,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
				lcd_gotoxy(4,2);sprintf(lcd,"TEST DRIVE CAT 4A");lcd_putstr(lcd);
//				lcd_gotoxy(3,3);sprintf(lcd,"MOV FWD");lcd_putstr(lcd);
//				R4ATO3_SP_ROUTE==R4ATO3_SP_INACTIVE;
//				FOLLOW_FLAG=KIRI;
				CAT_FLAG_B=CAT_NOT_DETECTED;
				BW_LOCATION[0]=LOCATION_CORRIDOR;
				R4ATO3_SP_ROUTE=R4ATO3_SP_ACTIVE;
				BW_PID_Init();

				while(1)
				{
//					Dynamx_MovFwd4cm_slow(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

					Dynamx_MovFwd4cm(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);

//					lcd_display_clear();
//					lcd_gotoxy(1,0);sprintf(lcd,"BHATARA WIJAYA");lcd_putstr(lcd);
//					lcd_gotoxy(2,2);sprintf(lcd,"SLIDE LEFT");lcd_putstr(lcd);
//					Nav_Test_Menu();
//					Nav_4A_To_1A_VER2();
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);

				}

			}break;

//		//BW TCS3200Tracer MODE
		case BW_MODE_4:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();

//				BW_LOCATION[0]=LOCATION_ROOM;
//				FOLLOW_FLAG=KIRI;
				BW_PID_Init();
//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_CLOSE,IKCALC_DISABLE);
				while(1)
				{

//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_Slide_Right(HEXSTEP_MED,HEXSPD_MED);
//					BW_FollowTracer_Left_Reverse();
//					Dynamx_MovBwd(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//					Dynamx_MovFwd4cm_slow(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//					BW_FollowTracer_Left();
//					Dynamx_CurveRight_Reverse(HEXSPD_FAST, HEXSTEP_FAR, IKCALC_DISABLE);
					Hybrid_TCS3200Tracer_MainMenu();
//					Dynamx_CurveLeft(HEXSPD_MEDFAST, HEXSTEP_MED, IKCALC_DISABLE);
//					Dynamx_Rot_Left(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
				}
			}break;

//		//BW SENSOR MODE
		case BW_MODE_5:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();

//				Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_VERYCLOSE,IKCALC_DISABLE);
				//Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
				while(1)
				{
					Sensor_Menu();
				}
			}break;

//		//BW DEMO
		case BW_MODE_6:
			{
				BW_Initial_Setup(rot_switch_mode);
				lcd_display_clear();
				BW_PID_Flame_Init();
//				ROOM[2]=ROOM_2A;
				FIRESCAN_DIRECTION=SCAN_RIGHT;
				while(1)
				{
//					Dynamx_MovFwd4cm(4,HEXSPD_SLOW,IKCALC_DISABLE);
//					Dynamx_MovBwd(4,HEXSPD_FAST,IKCALC_DISABLE);
//					Dynamx_MovFwd4cm_slow(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
//					BW_FollowFlame();
//					BW_FlameFollowDemo();
//					BW_FireFight();
//					BW_FollowTracer_Right();
//					BWFollowCarpet_Left(COLOUR_GRAY,INVERSE);

					BW_FlameFollowDemo_Dynamixel();
//					Dynamx_CurveLeft_Reverse(HEXSPD_FAST, HEXSTEP_FAR, IKCALC_DISABLE);

//					Dynamx_MovFwd4cm_slow(4,HEXSPD_MED,IKCALC_DISABLE);
//					Dynamx_MovFwd4cm_slow(4,HEXSPD_MED,IKCALC_DISABLE);
//					Dynamx_MovFwd4cm_slow(4,HEXSPD_MED,IKCALC_DISABLE);
////				while(1)
////				{
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//
//					lcd_display_clear();
//					lcd_gotoxy(3,0);sprintf(lcd,"GRAY DETECTED");lcd_putstr(lcd);
//					}
//					Dynamx_Slide_Right(FAR, HEXSPD_MEDFAST);
//					Dynamx_Slide_Left(HEXSTEP_MED,HEXSPD_MED);
//					Dynamx_CurveRight(HEXSPD_MEDFAST, HEXSTEP_FAR, IKCALC_DISABLE);
//					Dynamx_Rot_Right(HEXSPD_FAST,HEXSTEP_FAR,IKCALC_DISABLE);
//					while(1)
//					{
//						mov_celebrate();
//					}

				}
			}break;
	}
	while(1)

	return 0;
}

void BW_Initialization(void)
{
	//CLOCK CONFIG
	SystemInit();

	//SYSTICK DELAY INIT
	SysTick_Init();

	//BW EXTINGUISHER INIT
	BW_Extinguisher_Init();

	//BW HEXAPOD SERVO INIT
//	BW_Servo_Initialization();

	//LCD INIT
	delay_ms(50);
	BW_LCD_Init();
	lcd_cursor_off_blink_off();
	lcd_display_clear();

	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"SYSTEM");lcd_putstr(lcd);
	lcd_gotoxy(1,2);sprintf(lcd,"INITIALIZATION");lcd_putstr(lcd);
	lcd_gotoxy(1,3);sprintf(lcd,"BRAWIJAYA 2017");lcd_putstr(lcd);
	delay_ms(500);

	//INERTIAL MEASUREMENT UNIT (IMU) SENSOR
	BW_CMPS11_Init();

	//BW USART COMMUNICATION PROTOCOLS
//	USART1_Init(9600);
//	USART2_Init(9600);
	USART3_Init(9600);
//	UART4_Init(115200);
	UART4_Init(9600);
	UART5_Init(9600);
	USART6_Init(9600);
	Dynamixel_USART2_Init(1000000);
//	Dynamixel_USART6_Init(1000000);

	//BW USER INTERFACE
	Button_Init();
	Buzzer_Init();
	FIRE_LED_Init();
	BW_LED_Interrupt_Init();
	RotSwitch_Init();
	RotSwitch_Sampling();

	SND_ACT_LED_Init();

	//INFRARED PROXIMITY SENSOR
	IR_Proximity_Init();

	//BW PID CONTROLLER INITIALIZATION
	BW_PID_Init();
	PID_Calculate_Rule_Interrupt_Init();

	//Cat_Avoider_Interrupt_Init();
	//BW CONTACT BUMPER
	Bumper_Init();

	//BW SENSOR STAT INTERRUPT
	FlameSensor_Init();

	//BW FLAME TRACKING PID
	FlameSense_PID_Init();

	//BW TPA81 INIT
	BW_TPA81_I2C_Init();

	//BW SOUND ACTIVATION INIT
	BW_Sound_Activation_Init();

	//BW TPA SERVO INIT
	PanServo_Init();

	//BW DYNAMIXEL INTERRUPT INIT
//	Dynamixel_Drive_Interrupt_Init();

	BW_Buzz_New(2);
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(5,1);sprintf(lcd,"SYSTEM");lcd_putstr(lcd);
	lcd_gotoxy(1,2);sprintf(lcd,"INITIALIZATION");lcd_putstr(lcd);
	lcd_gotoxy(3,3);sprintf(lcd,"COMPLETED");lcd_putstr(lcd);
	delay_ms(50);

	Sendto_PC(USART1,"PROJECT BW 2017 \r");
	Sendto_PC(USART1,"ELECTRICAL ENGINEERING - UNIVERSITY OF BRAWIJAYA \r");
	Sendto_PC(USART1,"SYSTEM INITIALIZATION");
	Sendto_PC(USART1,".");
	Sendto_PC(USART1,".");
	Sendto_PC(USART1,". \r");
	Sendto_PC(USART1,"INITIALIZATION COMPLETED \r");
}

