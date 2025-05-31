/*========================================================================================
								   PROJECT BW 2.16 Ver.1.0
								  BW Hydro Extinguisher Library
==============================================================================================*/

#include "bw_extinguisher.h"

void BW_Extinguisher_Init(void)
{
//	EXTINGUISHER_OFF;
	Pump_GPIOInit();
	EXTINGUISHER_OFF;
}

void Pump_GPIOInit(void)
{

	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_EXTINGUISHER, ENABLE); // Clocking GPIOC (AHB1/APB1 = 42MHz)
	GPIO_InitStructure.GPIO_Pin = EXTINGUISHER_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       // Pin ini memiliki Mode Ouput
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD; 		// Pin bersifat Push Pull (Pull-up, down or no Pull)
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; 	// kecepatan clock(2, 25, 50 or 100 MHz)
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; 	// pin tidak diberikan pull up
	GPIO_Init(EXTINGUISHER_PORT, &GPIO_InitStructure); 		// inisialisasi peripheral GPIO sesuai parameter typdef diatas

}

void BW_HydroPump (void)
{
	EXTINGUISHER_ON;
	delay_ms(1500);
	EXTINGUISHER_OFF;
}

void BW_HydroPump_2 (void)
{
//	BW_Buzz(4);
//
////	unsigned int SPEED=HEXSPD_SLOW;
//	int i=0;
//	int CNT=0;
//	int g;
//
//	BW_Buzz(4);
////	EXTINGUISHER_ON;
////	delay_ms(2000);
//
//		Get_UV();
//		while(UV_state==0)
//		{
//			Dynamx_Mov_Extinguish(HEXSPD_MED);
////			while(i>=1)
////			{
//				lcd_display_clear();
//				lcd_gotoxy(2,0);sprintf(lcd,"EXT FUNCTION");lcd_putstr(lcd);
//				CNT++;
//				lcd_gotoxy(0,3);sprintf(lcd,"CNT = %d",CNT);lcd_putstr(lcd);
//
////				Dynamx_Mov_Extinguish(HEXSPD_MED);
//				Get_UV();
//				if(UV_state==1){EXTINGUISHER_OFF;break;}

	BW_Buzz(4);

//	unsigned int SPEED=HEXSPD_SLOW;
	int i=0;
	int CNT=0;
	int g;

	BW_Buzz(4);
	EXTINGUISHER_ON;
//	delay_ms(1000);

		Get_UV();
		while(UV_state==0)
		{
			lcd_display_clear();
			lcd_gotoxy(2,0);sprintf(lcd,"EXT FUNCTION");lcd_putstr(lcd);
			Dynamx_Mov_Extinguish(HEXSPD_SLOW);
			while(i>0)//&& ((Ping[PING_FRONT]>20) || (SHARP[SHARP_FRONT_R]>20) || (SHARP[SHARP_FRONT_L]>20)))
			{
				UVLock_Refresh();
				Get_UV();
				if(UV_state==1){EXTINGUISHER_OFF;break;}

				lcd_display_clear();
				lcd_gotoxy(2,0);sprintf(lcd,"EXT FUNCTION PLUS");lcd_putstr(lcd);
				CNT++;
				lcd_gotoxy(0,3);sprintf(lcd,"CNT = %d",CNT);lcd_putstr(lcd);

				Dynamx_Mov_Extinguish(HEXSPD_SLOW);
				UVLock_Refresh();
				if(UV_state==1){EXTINGUISHER_OFF;break;}

				if((FlameFrontDigi[0]==4) && UV_state==0 &&(Ping[PING_FRONT]>30) && ((SHARP[SHARP_FRONT_R]>25) || (SHARP[SHARP_FRONT_L]>25)))
				{
					EXTINGUISHER_OFF;
					lcd_display_clear();
					lcd_gotoxy(2,0);sprintf(lcd,"FORWARD CORRECTION");lcd_putstr(lcd);
//					while (Ping[PING_FRONT]>30)
//					{
//						Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//						Furniture_Avoider();
//						Bumper_Follow();
//					}
					Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
					Furniture_Avoider();
					Bumper_Follow();

					UVLock_Refresh();
					if(UV_state==1){EXTINGUISHER_OFF;break;}

					FlameTracking_Center();

					if((SHARP[SHARP_FRONT_R]<15) || (SHARP[SHARP_FRONT_L]<15))
					{
						Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					}

					EXTINGUISHER_ON;

				}
			if(CNT==2)
			{
				// UNTUK LILIN TENGAH
				UVLock_Refresh();
				if(UV_state==1){EXTINGUISHER_OFF;break;}

				if((SP_FIRE_1B==SP_FIRE_ACTIVE) && ((Ping[PING_FRONT]>40) || ((SHARP[SHARP_FRONT_R]<10) || (SHARP[SHARP_FRONT_L]<10))))
				{
					lcd_display_clear();
					lcd_gotoxy(2,0);sprintf(lcd,"LILIN TENGAH !!!");lcd_putstr(lcd);
					Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					SP_FIRE_1B=SP_FIRE_INACTIVE;
//					FIREROOM_R1A_FLAG==FIREROOM_R1A_INACTIVE;
				}
				else if((FIRESCAN_DIRECTION==SCAN_RIGHT ||(FOLLOW_FLAG==KIRI)) && UV_Lock==UVLOCK_ACTIVE)
				{
					lcd_display_clear();
					lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CORRECTION LEFT");lcd_putstr(lcd);
					EXTINGUISHER_OFF;
					BW_PID_Init_Room();
					for(g=0;g<=10;g++)
					{
						UVLock_Refresh();
						if(UV_state==1){EXTINGUISHER_OFF;break;}

						BW_FollowCounter_Left(1);
						if(g>1)
						{

							TRACER_STAT=TRACER_BLACK;
							TCSlave_Check();
							if (TRACER_STAT==TRACER_WHITE)
							{
								lcd_display_clear();
								lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
								lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
								delay_ms(50);
								Dynamx_MovBwd(8,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
								Nav_TurnAround(TURN_RIGHT);
								Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//								break;
							}
							if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==5))break;
//							if((FlameSenseDigi[0]==3) || (FlameSenseDigi[0]==2))Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);break;
							if(FlameFrontDigi[0]==4)break;
						}
					}

					UVLock_Refresh();
					if(UV_state==1){EXTINGUISHER_OFF;break;}
					for(x=0;x<=3;x++)
					{
						UVLock_Refresh();
						if(UV_state==1){EXTINGUISHER_OFF;break;}
						FlameTracking_Center();
						while(SHARP[SHARP_FRONT_R]>25 && (SHARP[SHARP_FRONT_L]>25))
						{
							Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

							Furniture_Avoider();
							Bumper_Follow();

							if(FlameFrontDigi[0]!=4)break;
						}

						Bumper_Follow();

						UVLock_Refresh();
						if(UV_state==1){EXTINGUISHER_OFF;break;}

						FlameTracking_Center();
						while(SHARP[SHARP_FRONT_R]>25 && (SHARP[SHARP_FRONT_L]>25))
						{
							Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

							Furniture_Avoider();
							Bumper_Follow();

							if(FlameFrontDigi[0]!=4)break;
						}

						Bumper_Follow();
					}
					if((SHARP[SHARP_FRONT_R]<15) || (SHARP[SHARP_FRONT_L]<15))
					{
						Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					}

				EXTINGUISHER_ON;
				}

				else if((FIREROOM_R1A_FLAG==FIREROOM_R1A_ACTIVE || FIRESCAN_DIRECTION==SCAN_LEFT ||(FOLLOW_FLAG==KANAN)) && UV_Lock==UVLOCK_ACTIVE)
				{
					EXTINGUISHER_OFF;
					lcd_display_clear();
					lcd_gotoxy(2,0);sprintf(lcd,"FOLLOW CORRECTION RIGHT");lcd_putstr(lcd);
					BW_PID_Init_Room();
						for(g=0;g<=10;g++)
						{
							UVLock_Refresh();
							if(UV_state==1){EXTINGUISHER_OFF;break;}

							BW_FollowCounter_Right(1);

							if(g>1)
							{
								TRACER_STAT=TRACER_BLACK;
								TCSlave_Check();
								if (TRACER_STAT==TRACER_WHITE)
									{
										lcd_display_clear();
										lcd_gotoxy(0,0);sprintf(lcd,"TRACER STATS");lcd_putstr(lcd);
										lcd_gotoxy(0,1);sprintf(lcd,"WHITE");lcd_putstr(lcd);
										delay_ms(50);

										Dynamx_MovBwd(8,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
										Nav_TurnAround(TURN_RIGHT);
										Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);
//										break;
									}
								if((FlameSenseDigi[0]==4) || (FlameSenseDigi[0]==3))break;
							}
							if(FlameFrontDigi[0]==4)break;
						}

					UVLock_Refresh();
					if(UV_state==1){EXTINGUISHER_OFF;break;}
					FlameTracking_Center();

					for(x=0;x<=3;x++)
					{
						UVLock_Refresh();
						if(UV_state==1){EXTINGUISHER_OFF;break;}

						FlameTracking_Center();
						while(SHARP[SHARP_FRONT_R]>25 && (SHARP[SHARP_FRONT_L]>25))
						{
							Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

							Furniture_Avoider();
							Bumper_Follow();

							if(FlameFrontDigi[0]!=4)break;
						}

						Bumper_Follow();

						UVLock_Refresh();
						if(UV_state==1){EXTINGUISHER_OFF;break;}

						FlameTracking_Center();
						while(SHARP[SHARP_FRONT_R]>25 && (SHARP[SHARP_FRONT_L]>25))
						{
							Dynamx_MovFwd4cm(4,HEXSPD_MEDFAST,IKCALC_DISABLE);

							Furniture_Avoider();
							Bumper_Follow();

							if(FlameFrontDigi[0]!=4)break;
						}

						Bumper_Follow();
					}
					if(SHARP[SHARP_FRONT_R]<15 || (SHARP[SHARP_FRONT_L]<15))
					{
						Dynamx_MovBwd(4,HEXSPD_ULTRAFAST,IKCALC_DISABLE);
					}

				EXTINGUISHER_ON;
					}
				}
			}
			i++;
			UVLock_Refresh();
			if(UV_state==1){lcd_display_clear();lcd_gotoxy(2,0);sprintf(lcd,"UV INACTIVE");lcd_putstr(lcd);EXTINGUISHER_OFF;break;}
		}

	EXTINGUISHER_OFF;
}

void PushTo_Burst (void)
{
	lcd_display_clear();
	lcd_gotoxy(2,0);sprintf(lcd,"PROJECT BW");lcd_putstr(lcd);
	lcd_gotoxy(4,1);sprintf(lcd,"BRAWIJAYA");lcd_putstr(lcd);
	lcd_gotoxy(2,2);sprintf(lcd,"PUSH TO BURST");lcd_putstr(lcd);
	lcd_gotoxy(2,3);sprintf(lcd,"JTE FT-UB 63");lcd_putstr(lcd);
	delay_ms(100);

//	mov_static();
//	delay_ms(100);

	EXTINGUISHER_OFF;

	BW_START=BW_BUTTON_INPUT;
	if(BW_START==1)
	{
		BW_Buzz(2);
		BW_HydroPump();
//		BW_BLDC_Fight();
	}
	else EXTINGUISHER_OFF;
}
